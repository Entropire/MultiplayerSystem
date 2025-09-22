#pragma once

using namespace System;

namespace MultiplayerSystemInterop {
	public ref class Class1
	{
	public:
		// Static .NET method wrapping native Add
		static int Add(int a, int b);
	};
}
