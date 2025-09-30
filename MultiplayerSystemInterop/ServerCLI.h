#pragma once
#include <string>
#include "UDPServer.h"

namespace MultiplayerSystem {
    namespace CLI {

        public ref class UDPServer {
        private:
            MultiplayerSystem::UDPServer* nativeServer;

        public:
            UDPServer(int port);
            ~UDPServer();           
            !UDPServer();           

            void Start();
            void Stop();
        };

    }
}
