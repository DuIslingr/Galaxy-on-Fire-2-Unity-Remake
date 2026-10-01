// DedicatedServer.cs
// Remake-only: the normal Windows / Linux player as a dedicated multiplayer server, so a session runs without anyone
// playing on the hosting machine. Started with -server on the command line (Unity's -batchmode -nographics recommended:
// no window, no rendering), or the GOF2_SERVER environment variable (the Editor's Play mode, for testing). Options:
//   -relay           online through Unity Relay: the console shows the join code, no port forwarding (else players join
//                    on this machine's address); listed in the server browser (NetLobby) unless -unlisted
//   -name "..."      the server browser's name for it
//   -password X      players need it to join (NetGame's connection approval)
//   -maxplayers N    Relay's player limit (default 16, at most 100)
//   -port N          the local port (default 7777); -fps N the server's frame rate (default 60)
// Bootstrap calls Boot before the first scene wakes and swaps in an empty scene. The main menu scene never runs: in the
// Editor its objects are already loaded and are switched off at once; in a player the scene is still loading then, so
// MainMenu / MenuBackground call ShutOff as they wake (the scene's objects off before the rest wake: no menu, music or
// live orbit backdrop), and the scene is unloaded once loaded. The process is muted (AudioListener volume 0, paused).
// Then NetGame.StartServer runs the session's world (NetState: the seed, the shared stock, squads, missions, crate
// claims, the chat relay) without a player of its own; every player's game runs its orbits as with a host (the first
// player in an orbit runs its NPCs).
// The console: the log (joins and leaves with the client ids, where each player is, chat, errors) and commands (help,
// status, list, say, kick, stop). Windows players are GUI programs: the server opens its own console window (WinConsole)
// unless its output is redirected to a file or pipe (or -noconsole); the log is mirrored into that window (Unity prints
// its log only to a standard output it starts with). Linux uses the terminal's stdin / stdout (-logFile - prints the log
// there). Ctrl+C or closing the window stops the server like "stop": the players hear why first (NetGame.StopServer).

using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Threading;
using GoF2Remake.Data;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace GoF2Remake.Multiplayer
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public sealed class DedicatedServer : MonoBehaviour
    {
        public const string EnvironmentSwitch = "GOF2_SERVER";
        const string ServerName = "Server";
        const float TrackSeconds = 1f;

        /// <summary>This process runs as a dedicated server (-server, or GOF2_SERVER set).</summary>
        public static bool Enabled { get; private set; } = Detect();

        static readonly ConcurrentQueue<string> commands = new ConcurrentQueue<string>();
        static TextWriter console;
        static bool consoleLog;
        static DedicatedServer instance;
        static ushort port;
        static int maxPlayers;
        static bool relay;
        static float startedAt;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics()
        {
            Enabled = Detect();
            while (commands.TryDequeue(out _)) { }
            instance = null;
        }

        static bool Detect() =>
            HasFlag("-server") || !string.IsNullOrEmpty(Environment.GetEnvironmentVariable(EnvironmentSwitch));

        static bool HasFlag(string flag) =>
            Array.Exists(Environment.GetCommandLineArgs(), a => string.Equals(a, flag, StringComparison.OrdinalIgnoreCase));

        static string Value(string flag) => NetGame.CommandLineValue(flag);

        /// <summary>Bootstrap (BeforeSceneLoad): the first scene's objects are loaded but not awake yet. They are switched off
        /// and replaced by an empty scene, and the server starts.</summary>
        public static void Boot()
        {
            if (instance != null) return;
            int fps = int.TryParse(Value("-fps"), out int f) ? Mathf.Clamp(f, 10, 240) : 60;
            port = ushort.TryParse(Value("-port"), out ushort p) && p >= 1024 ? p : NetGame.DefaultPort;
            maxPlayers = int.TryParse(Value("-maxplayers"), out int mp) ? Mathf.Clamp(mp, 1, 100) : NetGame.MaxOnlinePlayers;
            NetGame.HostPassword = NetGame.CleanPassword(Value("-password"));
            relay = HasFlag("-relay") || Environment.GetEnvironmentVariable(EnvironmentSwitch) == "relay";
            Application.runInBackground = true;
#if UNITY_EDITOR
            int editorVSync = QualitySettings.vSyncCount;
            Application.quitting += () => QualitySettings.vSyncCount = editorVSync;   // QualitySettings.asset keeps its own
#endif
            QualitySettings.vSyncCount = 0;   // batch mode has no display to sync to: the cap keeps the CPU idle
            Application.targetFrameRate = fps;
            AudioListener.volume = 0f;   // a server makes no sound, with or without -nographics
            AudioListener.pause = true;

            var first = SceneManager.GetActiveScene();
            serverScene = SceneManager.CreateScene("DedicatedServer");
            SceneManager.SetActiveScene(serverScene);
            // The Editor: the first scene is loaded already, its objects not awake: off and gone now. A player loads it
            // after this (ShutOff as it wakes, OnSceneLoaded unloads it).
            if (first.IsValid() && first.isLoaded && first != serverScene)
            {
                foreach (var root in first.GetRootGameObjects()) root.SetActive(false);
                SceneManager.UnloadSceneAsync(first);
            }
            SceneManager.sceneLoaded -= OnSceneLoaded;
            SceneManager.sceneLoaded += OnSceneLoaded;

            var go = new GameObject("DedicatedServer");
            DontDestroyOnLoad(go);
            instance = go.AddComponent<DedicatedServer>();
        }

        static Scene serverScene;

        /// <summary>MainMenu / MenuBackground as they wake: on a dedicated server their scene is switched off at once (true =
        /// do nothing more); OnSceneLoaded unloads it.</summary>
        public static bool ShutOff(Scene scene)
        {
            if (!Enabled) return false;
            foreach (var root in scene.GetRootGameObjects()) if (root.activeSelf) root.SetActive(false);
            return true;
        }

        /// <summary>Any other scene that loads on a server (the first scene in a player): off and unloaded.</summary>
        static void OnSceneLoaded(Scene scene, LoadSceneMode mode)
        {
            if (!Enabled || scene == serverScene || !scene.IsValid()) return;
            foreach (var root in scene.GetRootGameObjects()) if (root.activeSelf) root.SetActive(false);
            if (serverScene.IsValid() && serverScene.isLoaded) SceneManager.SetActiveScene(serverScene);
            SceneManager.UnloadSceneAsync(scene);
        }

        readonly Dictionary<ulong, (string name, string where, float since)> known = new Dictionary<ulong, (string, string, float)>();
        float trackTimer;

        async void Start()
        {
            OpenConsole();
            startedAt = Time.unscaledTime;
            Log($"Galaxy on Fire 2 Unity Remake dedicated server, version {Application.version}");
            if (relay)
            {
                Log("Reserving an online session (Unity Relay)...");
                string listed = HasFlag("-unlisted") ? null : (Value("-name") ?? "Galaxy on Fire 2 server");
                if (!await NetGame.PrepareOnlineHost(maxPlayers, listed)) { Fail(); return; }
            }
            if (!NetGame.StartServer(port)) { Fail(); return; }
            if (NetGame.JoinCode != null)
                Log($"Online through Unity Relay, up to {maxPlayers} players. Join code: {NetGame.JoinCode}");
            else
            {
                Log($"Listening on port {port} (UDP, every network adapter). Players join on this machine's address{(port != NetGame.DefaultPort ? ":" + port : "")}.");
                foreach (var (name, address) in NetGame.LocalAddresses()) Log($"  {name}: {address}");
            }
            if (NetGame.HasPassword) Log("Players need the password (-password) to join.");
            Log("Type \"help\" for the commands.");
        }

        static void Fail()
        {
            Debug.LogError("Server: " + NetGame.Status);
            Application.Quit(1);
        }

        void Update()
        {
            while (commands.TryDequeue(out string line))
            {
                string answer = Run(line);
                if (!string.IsNullOrEmpty(answer)) Answer(answer);
            }
            if ((trackTimer -= Time.unscaledDeltaTime) <= 0f)
            {
                trackTimer = TrackSeconds;
                TrackPlayers();
            }
        }

        void OnDestroy()
        {
            if (instance == this) instance = null;
            if (consoleLog) Application.logMessageReceivedThreaded -= Mirror;
            SceneManager.sceneLoaded -= OnSceneLoaded;
        }

        // ---- players ----------------------------------------------------------------------------------------

        /// <summary>Joins, leaves and moves of the players, logged once their name and place are known.</summary>
        void TrackPlayers()
        {
            var seen = new HashSet<ulong>();
            foreach (var p in NetPlayer.All)
            {
                if (p == null || !p.IsSpawned) continue;
                ulong id = p.OwnerClientId;
                seen.Add(id);
                string where = Where(p);
                if (!known.TryGetValue(id, out var k))
                {
                    if (p.Where == NetPlayer.Place.None) continue;   // still loading: their name and place come with their scene
                    known[id] = (p.DisplayName, where, Time.unscaledTime);
                    Log($"{p.DisplayName} (client {id}) joined, {where}. {Count()}");
                }
                else if (k.where != where || k.name != p.DisplayName)
                {
                    if (k.name != p.DisplayName) Log($"{k.name} (client {id}) is now called {p.DisplayName}.");
                    if (k.where != where) Log($"{p.DisplayName}: {where}");
                    known[id] = (p.DisplayName, where, k.since);
                }
            }
            var gone = new List<ulong>();
            foreach (var pair in known) if (!seen.Contains(pair.Key)) gone.Add(pair.Key);
            foreach (ulong id in gone)
            {
                var k = known[id];
                known.Remove(id);
                Log($"{k.name} (client {id}) left after {Duration(Time.unscaledTime - k.since)}. {Count()}");
            }
        }

        string Count()
        {
            int n = NetGame.ClientIds.Count;
            return n == 1 ? "1 player online." : $"{n} players online.";
        }

        static string Where(NetPlayer p)
        {
            string station = StationName(p.Station);
            switch (p.Where)
            {
                case NetPlayer.Place.Space: return $"in space at {station}";
                case NetPlayer.Place.Hangar: return $"docked at {station}";
                case NetPlayer.Place.Departing: return $"taking off from {station}";
                default: return "loading";
            }
        }

        static string StationName(int index)
        {
            if (index == Session.VoidOrbit) return "the Void";
            var s = NetGame.Db.Stations.Find(x => x.index == index);
            return s != null && !string.IsNullOrEmpty(s.name) ? s.name : $"station {index}";
        }

        static string Duration(float seconds)
        {
            var t = TimeSpan.FromSeconds(Mathf.Max(0f, seconds));
            return t.TotalHours >= 1 ? $"{(int)t.TotalHours}h {t.Minutes:00}m" : t.TotalMinutes >= 1 ? $"{t.Minutes}m {t.Seconds:00}s" : $"{t.Seconds}s";
        }

        // ---- commands ---------------------------------------------------------------------------------------

        /// <summary>Runs one console command and returns its answer (also for the Editor: DedicatedServer.Run("list")).</summary>
        public static string Run(string line)
        {
            line = (line ?? "").Trim();
            if (line.Length == 0) return "";
            int space = line.IndexOf(' ');
            string cmd = (space < 0 ? line : line.Substring(0, space)).ToLowerInvariant();
            string rest = space < 0 ? "" : line.Substring(space + 1).Trim();
            switch (cmd)
            {
                case "help": case "?":
                    return "Commands:\n" +
                           "  status              join code / port, uptime, players\n" +
                           "  list                the players: client id, name, where, ship, squad\n" +
                           "  say <text>          a chat line to everyone, from \"Server\"\n" +
                           "  kick <id|name> [reason]  drops a player\n" +
                           "  stop                tells the players and shuts the server down (also quit, exit, Ctrl+C)";
                case "status":
                    return $"{(NetGame.Active ? "Running" : "Not running")} {(NetGame.JoinCode != null ? $"online, join code {NetGame.JoinCode}" : $"on port {port}")}, up {Duration(Time.unscaledTime - startedAt)}, " +
                           $"{NetGame.ClientIds.Count} player(s), world seed {NetGame.Seed}, {Application.targetFrameRate} fps.";
                case "list": case "players": case "who":
                    return List();
                case "say":
                    if (rest.Length == 0) return "say <text>";
                    if (NetState.Instance == null || !NetState.Instance.IsSpawned) return "The server isn't running.";
                    NetState.Instance.ServerChat(ServerName, rest);
                    return "";   // the chat line itself is logged
                case "kick":
                    return Kick(rest);
                case "stop": case "quit": case "exit": case "shutdown":
                    Log("Stopping the server...");
                    NetGame.StopServer();
                    return "";
                default:
                    return $"Unknown command \"{cmd}\". Type \"help\".";
            }
        }

        static string List()
        {
            var sb = new StringBuilder();
            int n = 0;
            foreach (var p in NetPlayer.All)
            {
                if (p == null || !p.IsSpawned) continue;
                n++;
                sb.Append($"\n  {p.OwnerClientId,3}  {p.DisplayName,-20}  {Where(p)}, {UI.ItemInfo.ShipName(p.ShipIndex)}");
                if (p.SquadId != 0) sb.Append($", squad {p.SquadId}");
            }
            return n == 0 ? "No players online." : $"{n} player(s):" + sb;
        }

        static string Kick(string args)
        {
            if (args.Length == 0) return "kick <id|name> [reason]";
            int space = args.IndexOf(' ');
            string who = space < 0 ? args : args.Substring(0, space);
            string reason = space < 0 ? "" : args.Substring(space + 1).Trim();
            NetPlayer target = null;
            foreach (var p in NetPlayer.All)
            {
                if (p == null || !p.IsSpawned) continue;
                if ((ulong.TryParse(who, out ulong id) && p.OwnerClientId == id) || string.Equals(p.DisplayName, who, StringComparison.OrdinalIgnoreCase))
                { target = p; break; }
            }
            if (target == null) return $"No player \"{who}\" (see \"list\").";
            string name = target.DisplayName;
            if (reason.Length == 0) reason = Localization.Extra("mpKicked", "The server removed you from the session.");
            return NetGame.Kick(target.OwnerClientId, reason) ? $"Kicked {name}." : $"Could not kick {name}.";
        }

        // ---- console ----------------------------------------------------------------------------------------

        /// <summary>A server line: the log (Player.log) and the console.</summary>
        static void Log(string text) => Debug.LogFormat(LogType.Log, LogOption.NoStacktrace, null, "Server: {0}", text);

        /// <summary>A command's answer: only the console (the log needn't keep lists).</summary>
        static void Answer(string text)
        {
            if (console != null) Write(text);
            else Debug.LogFormat(LogType.Log, LogOption.NoStacktrace, null, "{0}", text);
        }

        static void Write(string text)
        {
            try { lock (console) console.WriteLine(text); } catch (Exception) { }
        }

        /// <summary>Every log message on the console, with its time (errors and exceptions with their first trace line).</summary>
        static void Mirror(string message, string stackTrace, LogType type)
        {
            string line = $"[{DateTime.Now:HH:mm:ss}] " + (type == LogType.Log ? "" : type == LogType.Warning ? "Warning: " : "Error: ") + message;
            if ((type == LogType.Exception || type == LogType.Error) && !string.IsNullOrEmpty(stackTrace))
            {
                int nl = stackTrace.IndexOf('\n');
                line += "\n    " + (nl < 0 ? stackTrace : stackTrace.Substring(0, nl)).Trim();
            }
            Write(line);
        }

        void OpenConsole()
        {
            if (Application.isEditor || HasFlag("-noconsole")) return;   // the Editor: the Console window and Run()
            // Unity prints its log to a standard output it was started with (redirected, a terminal, -logFile -): only a
            // console window opened here gets the log mirrored; elsewhere the console adds only the command answers.
            bool mirror = false;
            Stream input = null, output = null;
            try
            {
#if UNITY_STANDALONE_WIN
                // A GUI program: without redirected output, a console window of its own (a parent's console would share its
                // input with the shell that started it).
                // Its own window unless the output goes to a file or pipe (with -logFile, Unity's stdout is that log file:
                // the window then still opens).
                if (Value("-logFile") != null || !WinConsole.HasOutput())
                {
                    mirror = true;
                    WinConsole.Open($"{Application.productName} server (port {port})");
                    WinConsole.OnClose(() =>
                    {
                        commands.Enqueue("stop");
                        Thread.Sleep(1500);   // closing the window: the goodbye goes out before Windows ends the process
                    });
                }
                input = WinConsole.Input();
                output = WinConsole.Output();
#else
                input = Console.OpenStandardInput();
                output = Console.OpenStandardOutput();
                Console.CancelKeyPress += (_, e) => { e.Cancel = true; commands.Enqueue("stop"); };
#endif
            }
            catch (Exception e)
            {
                Debug.LogWarning("Server: no console (" + e.Message + "); the log only.");
            }
            if (output != null)
            {
                console = TextWriter.Synchronized(new StreamWriter(output, new UTF8Encoding(false)) { AutoFlush = true });
                if (mirror)
                {
                    consoleLog = true;
                    Application.logMessageReceivedThreaded += Mirror;
                }
            }
            if (input != null)
            {
                var reader = new StreamReader(input, Encoding.UTF8);
                var thread = new Thread(() =>
                {
                    try
                    {
                        string line;
                        while ((line = reader.ReadLine()) != null) commands.Enqueue(line);
                    }
                    catch (Exception) { }
                }) { IsBackground = true, Name = "Server console" };
                thread.Start();
            }
        }
    }
}
