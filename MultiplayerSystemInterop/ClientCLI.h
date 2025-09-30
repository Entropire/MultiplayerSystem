#pragma once
#include "UDPClient.h"

namespace MultiplayerSystem {
    namespace CLI {
        public ref class UDPClient {
        private:
            MultiplayerSystem::UDPClient* nativeServer;

        public:
            UDPClient(System::String^ ip, int port);
            ~UDPClient();
            !UDPClient();

            void Start();
            void Stop();
			void SendPacket(System::String^ message);
        };
    }
}