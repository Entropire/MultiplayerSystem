using MultiplayerSystem.CLI;
using SimpleCommands;


namespace MultiplayerSystemTestConsole.Commands
{
    [CommandName("Host")]
    internal class HostCommand : Command
    {
        public override void Execute(string CommandName, string[] args)
        {
      Program.UDPServer.Start();
        }
    }
}
