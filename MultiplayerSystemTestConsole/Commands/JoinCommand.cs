using SimpleCommands;

namespace MultiplayerSystemTestConsole.Commands
{
    [CommandName("Join")]
    internal class JoinCommand : Command
    {
        public override void Execute(string[] args)
        {
            Console.WriteLine(args[0] + " Command");
        }
    }
}
