namespace MultiplayerSystemTestConsole.Commands.ConsoleCommands
{
  [CommandName("Stop")]
  internal class StopCommand : Command
  {
    public override void Execute(string[] args)
    {
      Console.WriteLine(args[0] + " Command");
    }
  }
}
