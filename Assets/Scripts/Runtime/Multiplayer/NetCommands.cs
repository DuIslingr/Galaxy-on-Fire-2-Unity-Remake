// NetCommands.cs
// Chat commands: a line typed in the chat that starts with "/" runs here on this game instead of being sent (NetChat.Send).
// Each command says who may use it (`available`); /help lists the ones this player can run. Their answers are chat
// notices only this player sees.
//   /help       the commands this player can use
//   /netstats   shows / hides the network stats over the HUD (NetStats)

using System;
using GoF2Remake.Data;

namespace GoF2Remake.Multiplayer
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class NetCommands
    {
        sealed class Command
        {
            public string name;
            public Func<string> description;
            public Func<bool> available;
            public Action<string> run;
        }

        static readonly Command[] Commands =
        {
            new Command
            {
                name = "help", available = () => true, run = _ => Help(),
                description = () => X("mpCmdHelp", "lists the commands you can use"),
            },
            new Command
            {
                name = "netstats", available = () => true, run = _ => ToggleStats(),
                description = () => X("mpCmdNetstats", "shows or hides the network stats (ping, packet loss, data in / out)"),
            },
        };

        static string X(string key, string english) => Localization.Extra(key, english);

        /// <summary>A chat line starting with "/": runs it (true = it was a command, nothing is sent).</summary>
        public static bool TryRun(string line)
        {
            if (string.IsNullOrEmpty(line) || line[0] != '/') return false;
            string body = line.Substring(1).Trim();
            int space = body.IndexOf(' ');
            string name = (space < 0 ? body : body.Substring(0, space)).ToLowerInvariant();
            string args = space < 0 ? "" : body.Substring(space + 1).Trim();
            var command = Array.Find(Commands, c => c.name == name && c.available());
            if (command == null)
                NetChat.Notice(string.Format(X("mpCmdUnknown", "Unknown command /{0}. Type /help for the commands you can use."), name));
            else command.run(args);
            return true;
        }

        static void Help()
        {
            NetChat.Notice(X("mpCmdList", "Commands:"));
            foreach (var c in Commands)
                if (c.available()) NetChat.Notice($"/{c.name}: {c.description()}");
        }

        static void ToggleStats()
        {
            NetStats.Shown = !NetStats.Shown;
            NetChat.Notice(NetStats.Shown ? X("mpStatsOn", "Network stats on (/netstats hides them).") : X("mpStatsOff", "Network stats off."));
        }
    }
}
