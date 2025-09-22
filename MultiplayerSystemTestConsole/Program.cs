using MultiplayerSystemTestConsole.Commands;

class Program
{
  static void Main() => new Program().Start();

  private void Start()
  {
    CommandHandler.InitializeCommands();

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
      CommandHandler.executeCommand(args[0], args);
    }
  }
}