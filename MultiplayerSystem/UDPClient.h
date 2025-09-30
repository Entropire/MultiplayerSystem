    #pragma once
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #include <string>
    #include <thread>
    #include <future>

    namespace MultiplayerSystem {

        class UDPClient {
        private:
            sockaddr_in serverAddr{};
		    SOCKET sock{ INVALID_SOCKET }; 
		    std::thread listener;

            std::promise<void> exitSignal;
            std::future<void> futureObj;

            void InitializeWinsock();
            void SetupServerAddress(int port, const std::string& ip);
            SOCKET CreateSocket();
            void ListenForPackets(std::future<void> stopSignal);

        public:
            UDPClient(int port, const std::string& ip);
            ~UDPClient();
            void Start();
            void Stop();
            void SendPacket(const std::string& message);
        };

    }
