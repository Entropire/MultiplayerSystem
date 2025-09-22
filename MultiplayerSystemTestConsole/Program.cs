using System;
using MultiplayerSystemInterop; // namespace of the C++/CLI wrapper

class Program
{
  static void Main()
  {
    int result = Class1.Add(5, 7);
    Console.WriteLine($"5 + 7 = {result}");
  }
}