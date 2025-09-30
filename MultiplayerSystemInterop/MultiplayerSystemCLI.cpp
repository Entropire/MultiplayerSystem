#include "pch.h"

#include "MultiplayerSystemCLI.h"
#include "MultiplayerSystem.h"

namespace MultiplayerSystem {
	namespace CLI {
        int MathCore::Add(int a, int b)
        {
            return MultiplayerSystem::MathCore::Add(a, b);
        }
	}
}