#pragma once

using namespace System;

namespace MultiplayerSystem {
	namespace CLI {
		public ref class MathCore
		{
		public:
			// Static .NET method wrapping native Add
			static int Add(int a, int b);
		};
	}
}
