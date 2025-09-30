#include "pch.h"
#include "ServerCLI.h"

namespace MultiplayerSystem {
    namespace CLI {

        UDPServer::UDPServer(int port) {
            nativeServer = new MultiplayerSystem::UDPServer(port);
        }

        UDPServer::~UDPServer() {
            this->!UDPServer();
        }

        UDPServer::!UDPServer() {
            if (nativeServer != nullptr) {
                nativeServer->Stop();
                delete nativeServer;
                nativeServer = nullptr;
            }
        }

        void UDPServer::Start() {
            nativeServer->Start();
        }

        void UDPServer::Stop() {
            nativeServer->Stop();
        }
    }
}
