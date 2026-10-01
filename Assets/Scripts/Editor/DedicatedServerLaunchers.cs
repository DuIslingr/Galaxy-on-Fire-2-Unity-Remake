// DedicatedServerLaunchers.cs
// After a Windows or Linux player build: a launcher for the dedicated server (DedicatedServer) next to the game, so a
// server starts with a double click (Windows) or one command (Linux) instead of typing the command line. The name,
// password and player limit are at the top of the file to edit; it starts the game headless (-batchmode -nographics),
// online through Unity Relay and listed in the server browser. Windows: the server opens its own console window (the
// log and the commands); Linux: the terminal it runs in.

using System.IO;
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
                File.WriteAllText(Path.Combine(folder, "Start Dedicated Server.bat"), WindowsLauncher(name).Replace("\n", "\r\n"));
            else
                File.WriteAllText(Path.Combine(folder, "start-server.sh"), LinuxLauncher(name));
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
            "rem Add -unlisted to keep it out of the server browser (players then join with the join code from the console).\n" +
            // Only a set password goes on the command line (Unity drops an empty "" argument).
            "set PASSWORDARG=\n" +
            "if defined PASSWORD set PASSWORDARG=-password \"%PASSWORD%\"\n" +
            $"start \"\" \"%~dp0{exe}\" -batchmode -nographics -server -relay -name \"%NAME%\" %PASSWORDARG% -maxplayers %MAXPLAYERS%\n";

        static string LinuxLauncher(string exe) =>
            "#!/bin/sh\n" +
            "# Galaxy on Fire 2 Unity Remake: a dedicated multiplayer server, headless. The terminal shows who joins and the\n" +
            "# chat, and takes commands (help, list, say, kick, stop). Run: sh start-server.sh\n" +
            "# It hosts online through Unity Relay and is listed in the server browser. Edit these:\n" +
            "NAME=\"Galaxy on Fire 2 server\"\n" +
            "PASSWORD=\"\"        # empty = none\n" +
            "MAXPLAYERS=16      # at most 100\n" +
            "# Add -unlisted to keep it out of the server browser (players then join with the join code shown here).\n" +
            "cd \"$(dirname \"$0\")\"\n" +
            $"chmod +x ./{exe} 2>/dev/null\n" +
            "if [ -n \"$PASSWORD\" ]; then set -- -password \"$PASSWORD\"; else set --; fi\n" +
            $"exec ./{exe} -batchmode -nographics -server -relay -name \"$NAME\" \"$@\" -maxplayers \"$MAXPLAYERS\" -logFile -\n";
    }
}
