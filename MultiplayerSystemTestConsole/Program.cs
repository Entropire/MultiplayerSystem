using MultiplayerSystemTestConsole.Commands;
using SimpleCommands;
using MultiplayerSystem.CLI;

class Program
{
  private CommandHandler handler = new CommandHandler();
  public static UDPServer UDPServer = new UDPServer(8080);
  public static UDPClient UDPClient = new UDPClient("192.168.137.1", 8080);

  static void Main() => new Program().Start();

  private void Start()
  {
    handler.Register(new HostCommand());
    handler.Register(new JoinCommand());
    handler.Register(new LeaveCommand());
    handler.Register(new StopCommand());

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
        UDPClient.SendPacket(input);
        continue;
      }

      input = input.Replace("/", "").ToLower();
      args = input.Split(" ");
      handler.Execute(args[0], args);
    }
  }
}