#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include <thread>
#include <future>

namespace MultiplayerSystem {

    class UDPServer {
    private:
        int port;
        SOCKET sock{ INVALID_SOCKET };
        std::thread listener;

        std::promise<void> exitSignal;
        std::future<void> futureObj;

        void InitializeWinsock();
        struct addrinfo* SetupAddressInfo();
        SOCKET CreateSocket(struct addrinfo* result);
        void BindSocket(SOCKET sock, struct addrinfo* result);
        void Cleanup(SOCKET sock);
        void ListenForPackets(std::future<void> stopSignal);

    public:
        UDPServer(int port);
        ~UDPServer();
        void Start();
        void Stop();
    };

}
