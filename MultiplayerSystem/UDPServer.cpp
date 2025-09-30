#include "pch.h"
#include "UDPServer.h"
#include <iostream>
#include <stdexcept>

#pragma comment(lib, "Ws2_32.lib")

namespace MultiplayerSystem {

    UDPServer::UDPServer(int port) : port(port), futureObj(exitSignal.get_future()) {}

    UDPServer::~UDPServer() {
        Stop();
    }

    void UDPServer::Start() {
        try {
            InitializeWinsock();
            struct addrinfo* result = SetupAddressInfo();
            sock = CreateSocket(result);
            BindSocket(sock, result);
            freeaddrinfo(result);

            listener = std::thread(&UDPServer::ListenForPackets, this, std::move(futureObj));
            std::cout << "UDP Server started on port " << port << ". Waiting for messages...\n";
        }
        catch (const std::exception& ex) {
            std::cerr << "Server error: " << ex.what() << "\n";
        }
    }

    void UDPServer::Stop() {
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

    void UDPServer::InitializeWinsock() {
        WSADATA wsaData{};
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
            throw std::runtime_error("WSAStartup failed.");
        }
    }

    struct addrinfo* UDPServer::SetupAddressInfo() {
        struct addrinfo hints {}, * result = nullptr;
        ZeroMemory(&hints, sizeof(hints));
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_DGRAM;
        hints.ai_protocol = IPPROTO_UDP;
        hints.ai_flags = AI_PASSIVE;

        char portStr[6];
        sprintf_s(portStr, "%d", port);

        if (getaddrinfo(NULL, portStr, &hints, &result) != 0) {
            WSACleanup();
            throw std::runtime_error("getaddrinfo failed.");
        }
        return result;
    }

    SOCKET UDPServer::CreateSocket(struct addrinfo* result) {
        SOCKET sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
        if (sock == INVALID_SOCKET) {
            WSACleanup();
            throw std::runtime_error("socket creation failed.");
        }
        return sock;
    }

    void UDPServer::BindSocket(SOCKET sock, struct addrinfo* result) {
        if (bind(sock, result->ai_addr, (int)result->ai_addrlen) == SOCKET_ERROR) {
            closesocket(sock);
            WSACleanup();
            throw std::runtime_error("bind failed with error: " + std::to_string(WSAGetLastError()));
        }
    }

    void UDPServer::ListenForPackets(std::future<void> stopSignal) {
        while (stopSignal.wait_for(std::chrono::milliseconds(100)) == std::future_status::timeout)
        {
            char recvbuf[1024];

            int bytesReceived = recvfrom(sock, recvbuf, sizeof(recvbuf) - 1, 0, nullptr, nullptr);
            if (bytesReceived == SOCKET_ERROR) {
                int err = WSAGetLastError();
                if (err == WSAEINTR || err == WSAENOTSOCK) {
                    break; // socket closed during shutdown
                }
                std::cerr << "recvfrom failed: " << err << "\n";
                break;
            }

            recvbuf[bytesReceived] = '\0';
            std::cout << "Received: " << recvbuf << "\n";
        }

        std::cout << "Server thread stopping...\n";
    }

    void UDPServer::Cleanup(SOCKET sock) {
        closesocket(sock);
        WSACleanup();
    }

}
