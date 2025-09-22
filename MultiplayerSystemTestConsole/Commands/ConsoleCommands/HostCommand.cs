namespace MultiplayerSystemTestConsole.Commands.ConsoleCommands
{
  [CommandName("Host")]
  internal class HostCommand : Command
  {
    public override void Execute(string[] args)
    {
      Console.WriteLine(args[0] + " Command");
    }
  }
}
