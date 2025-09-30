using SimpleCommands;

namespace MultiplayerSystemTestConsole.Commands
{
  [CommandName("Stop")]
  internal class StopCommand : Command
  {
    public override void Execute(string CommandName, string[] args)
    {
      Program.UDPServer.Stop();
    }
  }
}
