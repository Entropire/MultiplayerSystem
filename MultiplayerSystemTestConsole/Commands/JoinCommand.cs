using MultiplayerSystem.CLI;
using SimpleCommands;

namespace MultiplayerSystemTestConsole.Commands
{
  [CommandName("Join")]
  internal class JoinCommand : Command
  {
    public override void Execute(string CommandName, string[] args)
    {
      Program.UDPClient.Start();
    }
  }
}
