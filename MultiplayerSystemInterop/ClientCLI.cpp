#include "pch.h"
#include "CLientCLI.h"
#include <msclr/marshal_cppstd.h>

namespace MultiplayerSystem {
    namespace CLI {
        UDPClient::UDPClient(System::String^ ip, int port) {
            std::string nativeIp = msclr::interop::marshal_as<std::string>(ip);
            nativeServer = new MultiplayerSystem::UDPClient(port, nativeIp);
        }

        UDPClient::~UDPClient() {
            this->!UDPClient();
        }

        UDPClient::!UDPClient() {
            if (nativeServer != nullptr) {
                nativeServer->Stop();
                delete nativeServer;
                nativeServer = nullptr;
            }
        }

        void UDPClient::Start() {
            nativeServer->Start();
        }

        void UDPClient::Stop() {
            nativeServer->Stop();
        }

		void UDPClient::SendPacket(System::String^ message) {
            std::string nativeMessage = msclr::interop::marshal_as<std::string>(message);
			nativeServer->SendPacket(nativeMessage);
		}
    }
}
