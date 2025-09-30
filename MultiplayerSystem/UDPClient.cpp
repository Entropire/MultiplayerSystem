#include "pch.h"
#include "UDPClient.h"
#include <iostream>
#include <stdexcept>

#pragma comment(lib, "Ws2_32.lib")

namespace MultiplayerSystem {

    UDPClient::UDPClient(int port, const std::string& ip) : futureObj(exitSignal.get_future()) {
        SetupServerAddress(port, ip);
    }

	UDPClient::~UDPClient() {
		Stop();
	}

    void UDPClient::Start() {
        try {
            InitializeWinsock();
            sock = CreateSocket();
            std::cout << "UDP Client started. Type messages to send (type 'quit' to exit):\n";
            listener = std::thread(&UDPClient::ListenForPackets, this, std::move(futureObj));
        }
        catch (const std::exception& ex) {
            std::cerr << "Client error: " << ex.what() << "\n";
        }
    }

	void UDPClient::Stop() {
		exitSignal.set_value();
        if (sock != INVALID_SOCKET) {
            closesocket(sock);
            sock = INVALID_SOCKET;
        }
        if (listener.joinable()) {
            listener.join();
        }
        WSACleanup();
	}

    void UDPClient::InitializeWinsock() {
        WSADATA wsaData{};
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
            throw std::runtime_error("WSAStartup failed.");
        }
    }

    void UDPClient::SetupServerAddress(int port, const std::string& ip) {
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(port);
        if (inet_pton(AF_INET, ip.c_str(), &serverAddr.sin_addr) != 1) {
            throw std::runtime_error("Invalid IP address: " + ip);
        }
    }

    SOCKET UDPClient::CreateSocket() {
        SOCKET sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if (sock == INVALID_SOCKET) {
            WSACleanup();
            throw std::runtime_error("Socket creation failed.");
        }
        return sock;
    }

    void UDPClient::ListenForPackets(std::future<void> stopSignal) {
        while (stopSignal.wait_for(std::chrono::milliseconds(100)) == std::future_status::timeout)
        {
            char recvbuf[1024];
            int serverAddrSize = sizeof(serverAddr);

            int bytesReceived = recvfrom(sock, recvbuf, sizeof(recvbuf) - 1, 0, nullptr, nullptr);
            if (bytesReceived == SOCKET_ERROR) {
                std::cerr << "recvfrom failed: " << WSAGetLastError() << "\n";
                break;
            }

            recvbuf[bytesReceived] = '\0';
            std::cout << "Server replied: " << recvbuf << "\n";
        }
    }

    void UDPClient::SendPacket(const std::string& message) {
        int serverAddrSize = sizeof(serverAddr);

        int bytesSent = sendto(sock, message.c_str(), (int)message.size(), 0, (sockaddr*)&serverAddr, serverAddrSize);
        if (bytesSent == SOCKET_ERROR) {
            std::cerr << "sendto failed: " << WSAGetLastError() << "\n";

        }
    }
}