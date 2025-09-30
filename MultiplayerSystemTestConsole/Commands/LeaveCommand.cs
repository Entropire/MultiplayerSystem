using SimpleCommands;

namespace MultiplayerSystemTestConsole.Commands
{
  [CommandName("Leave")]
  internal class LeaveCommand : Command
  {
    public override void Execute(string CommandName, string[] args)
    {
      Program.UDPClient.Stop();
    }
  }
}
