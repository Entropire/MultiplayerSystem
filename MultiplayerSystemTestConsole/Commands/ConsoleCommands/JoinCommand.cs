namespace MultiplayerSystemTestConsole.Commands.ConsoleCommands
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
