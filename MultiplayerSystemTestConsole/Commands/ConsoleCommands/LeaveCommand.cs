namespace MultiplayerSystemTestConsole.Commands.ConsoleCommands
{
  [CommandName("Leave")]
  internal class LeaveCommand : Command
  {
    public override void Execute(string[] args)
    {
      Console.WriteLine(args[0] + " Command");
    }
  }
}
