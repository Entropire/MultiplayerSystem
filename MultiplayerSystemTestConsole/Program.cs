using MultiplayerSystemTestConsole.Commands;
using SimpleCommands;

class Program
{
  private CommandHandler handler = new CommandHandler();

  static void Main() => new Program().Start();

  private void Start()
  {
    string input = "";
    string[] args = [];
    while (true)
    {
      input = Console.ReadLine();

      if (input == null)
      {
        continue;
      }

      if (!input.StartsWith("/"))
      {
        continue;
      }

      input = input.Replace("/", "").ToLower();
      args = input.Split(" ");
      handler.Execute(args[0], args.Skip(1).ToArray());
    }
  }

  private void InitCommands()
  {
    handler.Register(new HostCommand());
    handler.Register(new JoinCommand());
    handler.Register(new LeaveCommand());
    handler.Register(new StopCommand());
  }
}