#include "pch.h"

#include "MultiplayerSystemInterop.h"
#include "../MultiplayerSystem/MultiplayerSystem.h"

namespace MultiplayerSystemInterop {

    int Class1::Add(int a, int b)
    {
        // Call the native C++ static function
        return ::MathCore::Add(a, b);
    }
}