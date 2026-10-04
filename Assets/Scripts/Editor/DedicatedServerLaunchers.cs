// DedicatedServerLaunchers.cs
// After a Windows or Linux player build: a launcher for the dedicated server (DedicatedServer) next to the game, so a
// server starts with a double click (Windows) or one command (Linux) instead of typing the command line. The name,
// password, player limit, whether the Debug menu is allowed and the web admin (WebAdmin) are at the top of the file to edit (a rebuild keeps the values already there); it starts
// the game headless (-batchmode -nographics), online through Unity Relay and listed in the server browser. Windows: the server opens its own console window (the
// log and the commands); Linux: the terminal it runs in.

using System.IO;
using System.Text.RegularExpressions;
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;

namespace GoF2Remake.EditorTools
{
    public class DedicatedServerLaunchers : IPostprocessBuildWithReport
    {
        public int callbackOrder => 0;

        public void OnPostprocessBuild(BuildReport report)
        {
            var target = report.summary.platform;
            if (target != BuildTarget.StandaloneWindows64 && target != BuildTarget.StandaloneLinux64) return;
            if (report.summary.result == BuildResult.Failed || report.summary.result == BuildResult.Cancelled) return;
            string exe = report.summary.outputPath;
            string folder = Path.GetDirectoryName(exe);
            if (string.IsNullOrEmpty(folder) || !Directory.Exists(folder)) return;
            string name = Path.GetFileName(exe);
            if (target == BuildTarget.StandaloneWindows64)
            {
                string path = Path.Combine(folder, "Start Dedicated Server.bat");
                File.WriteAllText(path, KeepSettings(path, WindowsLauncher(name), true).Replace("\n", "\r\n"));
            }
            else
            {
                string path = Path.Combine(folder, "start-server.sh");
                File.WriteAllText(path, KeepSettings(path, LinuxLauncher(name), false));
            }
        }

        static readonly string[] Settings = { "NAME", "PASSWORD", "MAXPLAYERS", "ALLOWDEBUG", "WEBPORT", "WEBBIND" };

        /// <summary>A launcher already there keeps its edited settings (the name, password, player limit, Debug menu) in the new
        /// one; a setting it doesn't have yet (an older launcher) gets the default.</summary>
        static string KeepSettings(string path, string text, bool windows)
        {
            if (!File.Exists(path)) return text;
            string old = File.ReadAllText(path).Replace("\r\n", "\n");
            foreach (string key in Settings)
            {
                // Windows "set KEY=value" (the rest of the line); Linux "KEY=value  # comment" (a word or a quoted string).
                string pattern = windows ? $"(?m)^(set {key}=)(.*)$" : $"(?m)^({key}=)(\"[^\"]*\"|\\S*)";
                var had = Regex.Match(old, pattern);
                if (had.Success) text = Regex.Replace(text, pattern, m => m.Groups[1].Value + had.Groups[2].Value);
            }
            return text;
        }

        static string WindowsLauncher(string exe) =>
            "@echo off\n" +
            "rem Galaxy on Fire 2 Unity Remake: a dedicated multiplayer server. It runs without the game's window; its console\n" +
            "rem window shows who joins and the chat, and takes commands (help, list, say, kick, stop).\n" +
            "rem It hosts online through Unity Relay and is listed in the server browser. Edit these:\n" +
            "set NAME=Galaxy on Fire 2 server\n" +
            "rem Leave PASSWORD empty for none.\n" +
            "set PASSWORD=\n" +
            "rem At most 100.\n" +
            "set MAXPLAYERS=16\n" +
            "rem 1 = the players may use the Debug menu (cheats, items, spawns); 0 = off.\n" +
            "set ALLOWDEBUG=0\n" +
            "rem The web admin (a browser page: players, bans, settings, console, log): a port such as 8080, empty = off.\n" +
            "rem Log in with the admin token from the console, or a code from /web in the game.\n" +
            "set WEBPORT=\n" +
            "rem 127.0.0.1 = this PC only; 0.0.0.0 = the network too (plain HTTP: not on the open internet).\n" +
            "set WEBBIND=127.0.0.1\n" +
            "rem Add -unlisted to keep it out of the server browser (players then join with the join code from the console).\n" +
            // Only a set password goes on the command line (Unity drops an empty "" argument).
            "set PASSWORDARG=\n" +
            "if defined PASSWORD set PASSWORDARG=-password \"%PASSWORD%\"\n" +
            "set DEBUGARG=\n" +
            "if \"%ALLOWDEBUG%\"==\"1\" set DEBUGARG=-allowdebug\n" +
            "set WEBARG=\n" +
            "if defined WEBPORT set WEBARG=-webport %WEBPORT% -webbind %WEBBIND%\n" +
            $"start \"\" \"%~dp0{exe}\" -batchmode -nographics -server -relay -name \"%NAME%\" %PASSWORDARG% -maxplayers %MAXPLAYERS% %DEBUGARG% %WEBARG%\n";

        static string LinuxLauncher(string exe) =>
            "#!/bin/sh\n" +
            "# Galaxy on Fire 2 Unity Remake: a dedicated multiplayer server, headless. The terminal shows who joins and the\n" +
            "# chat, and takes commands (help, list, say, kick, stop). Run: sh start-server.sh\n" +
            "# It hosts online through Unity Relay and is listed in the server browser. Edit these:\n" +
            "NAME=\"Galaxy on Fire 2 server\"\n" +
            "PASSWORD=\"\"        # empty = none\n" +
            "MAXPLAYERS=16      # at most 100\n" +
            "ALLOWDEBUG=0       # 1 = the players may use the Debug menu (cheats, items, spawns)\n" +
            "WEBPORT=           # the web admin's port (e.g. 8080), empty = off; log in with the admin token or /web's code\n" +
            "WEBBIND=127.0.0.1  # 127.0.0.1 = this machine only; 0.0.0.0 = the network (plain HTTP: put a TLS proxy in front)\n" +
            "# Add -unlisted to keep it out of the server browser (players then join with the join code shown here).\n" +
            "cd \"$(dirname \"$0\")\"\n" +
            $"chmod +x \"./{exe}\" 2>/dev/null\n" +   // quoted: the product name has spaces ("Galaxy on Fire 2.x86_64")
            "if [ -n \"$PASSWORD\" ]; then set -- -password \"$PASSWORD\"; else set --; fi\n" +
            "if [ \"$ALLOWDEBUG\" = \"1\" ]; then set -- \"$@\" -allowdebug; fi\n" +
            "if [ -n \"$WEBPORT\" ]; then set -- \"$@\" -webport \"$WEBPORT\" -webbind \"$WEBBIND\"; fi\n" +
            $"exec \"./{exe}\" -batchmode -nographics -server -relay -name \"$NAME\" \"$@\" -maxplayers \"$MAXPLAYERS\" -logFile -\n";
    }
}
