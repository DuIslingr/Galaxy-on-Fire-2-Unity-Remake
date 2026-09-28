// NetGame.cs
// Remake-only multiplayer (Netcode for GameObjects over Unity Transport, direct IP, port 7777): one shared game world.
// The main menu's Multiplayer panel hosts or joins; every player starts a fresh free-play game docked at Var Hastra (78) and then
// plays it like single player: their own scenes (Space for their orbit, Station for their hangar), economy, jumps and
// docking. No scene synchronisation: the network objects live in DontDestroyOnLoad and each player shows only what is
// where they are.
//   NetState      the world (spawned by the host): the world seed (every orbit's asteroid field), destroyed asteroids per
//                 station, the spawn / despawn requests of the players who run an orbit.
//   NetPlayer     one per player: where they are (station; in space, in the hangar, taking off), their ship, pose, name,
//                 hull; in space the others there see the ship, in a hangar the others docked there see it land, park
//                 and take off (NetHangar, HangarTraffic's guests).
//   NetOrbit      a player's own Space level: the first player in an orbit runs its NPC traffic and crates (the orbit
//                 authority) and shows them to the others there as NetProxy / NetCrate objects it owns; the others' levels
//                 build no traffic. Asteroids: the same field for everyone, destruction shared.
//   Shots, hits on proxies and crate claims go between the players in the same orbit (NetShotSender / NetShotMirror,
//   NetProxy, NetCrate). Not yet: handing an orbit's NPCs over when its authority leaves (they go with it),
//   player-versus-player damage, NPCs attacking other players than the authority. The players can't die (game over
//   would load a save), nothing is saved (SaveGame), and the game never pauses (Time.timeScale stays 1).
// Network prefabs: Resources/GoF2Net (GoF2 > Build Network Prefabs).

using System;
using System.Collections.Generic;
using System.Net;
using System.Net.NetworkInformation;
using System.Net.Sockets;
using GoF2Remake.Data;
using Unity.Netcode;
using Unity.Netcode.Transports.UTP;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace GoF2Remake.Multiplayer
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class NetGame
    {
        public const ushort Port = 7777;
        public const int Station = 78;
        public const string PrefabFolder = "GoF2Net";
        public static readonly string[] PrefabNames = { "NetPlayer", "NetProxy", "NetState", "NetCrate" };
        const string StationScene = "Station", MenuScene = "MainMenu";

        static NetworkManager manager;
        static readonly HashSet<ulong> playersSpawned = new HashSet<ulong>();
        static bool worldEntered, transportConnected, sessionGame;

        /// <summary>A session runs (hosting, or a client connecting / connected); not while the host is closing it.</summary>
        public static bool Active => manager != null && manager.IsListening && !closing;

        /// <summary>The game in memory is a session's (from PrepareSession until the main menu opens after it), even once the
        /// connection is gone: SaveGame never saves it, and a level loaded after the session ended goes to the menu.</summary>
        public static bool SessionGame => sessionGame || Active;

        /// <summary>The session is gone but its game is still loaded (SpaceLevel / StationLevel then go to the main menu).</summary>
        public static bool SessionLost => sessionGame && !Active;

        /// <summary>The main menu opened: a session that has ended leaves nothing behind.</summary>
        public static void OnMainMenu()
        {
            if (!Active) sessionGame = false;
        }

        // Play mode without a domain reload keeps statics: a fresh start (also builds, where it changes nothing).
        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics()
        {
            manager = null;
            closing = quitAfter = worldEntered = transportConnected = sessionGame = lostHandled = false;
            hostEndReason = null;
            playersSpawned.Clear();
        }
        public static bool IsServer => Active && manager.IsServer;
        public static ulong LocalId => Active ? manager.LocalClientId : 0;
        /// <summary>Connected to the host (or hosting).</summary>
        public static bool Connected => Active && (manager.IsServer || manager.IsConnectedClient);
        static Database db;
        /// <summary>The game data, loaded once for the multiplayer code's look-ups (turrets, models).</summary>
        internal static Database Db => db ??= Database.Load();

        /// <summary>The world's seed (the host picks it, NetState carries it to the clients).</summary>
        public static int Seed { get; private set; }

        /// <summary>An orbit's asteroid seed: the same field for every player there, a different one per station.</summary>
        public static int OrbitSeed(int station) => unchecked(Seed * 31 + (station + 1000) * 7919);
        public const int MaxNameLength = 20;

        /// <summary>The player's name, shown to the others (lock plate, NetPlayer); the menu's name field, PlayerPrefs
        /// "mp_name". Empty = "Player N".</summary>
        public static string PlayerName
        {
            get => NameOverride ?? PlayerPrefs.GetString("mp_name", "");
            set => PlayerPrefs.SetString("mp_name", Clean(value));
        }

        /// <summary>A name for this process only (not saved), null = PlayerName's own: -mpname on the command line.</summary>
        public static string NameOverride = CommandLineValue("-mpname");

        /// <summary>-mpjoin &lt;address&gt; on the command line (testing): the main menu skips its intro and joins, null = none.</summary>
        public static readonly string AutoJoinAddress = CommandLineValue("-mpjoin");

        /// <summary>Testing, development builds only: -mpdock docks this player once, a few seconds into their first flight;
        /// -mpaccept accepts squad invitations while docked (NetPlayer), so the real squad flow runs without a hand on it.</summary>
        public static readonly bool TestDock = TestFlag("-mpdock"), TestAccept = TestFlag("-mpaccept");

        static bool TestFlag(string flag) =>
            Debug.isDebugBuild && Array.Exists(Environment.GetCommandLineArgs(), a => string.Equals(a, flag, StringComparison.OrdinalIgnoreCase));

        static string CommandLineValue(string flag)
        {
            var args = Environment.GetCommandLineArgs();
            for (int i = 0; i < args.Length - 1; i++)
                if (string.Equals(args[i], flag, StringComparison.OrdinalIgnoreCase)) return args[i + 1];
            return null;
        }

        /// <summary>Trimmed, at most MaxNameLength characters, no rich-text tags (the lock plate is a rich-text Label).</summary>
        public static string Clean(string name)
        {
            name = (name ?? "").Replace("<", "").Replace(">", "").Trim();
            return name.Length > MaxNameLength ? name.Substring(0, MaxNameLength) : name;
        }

        /// <summary>A session ended while playing: the main menu opens the Multiplayer panel with a popup of Status.</summary>
        public static bool PopupPending { get; private set; }

        /// <summary>The main menu: the pending popup's text, once.</summary>
        public static bool TakePopup(out string text)
        {
            text = Status;
            bool pending = PopupPending;
            PopupPending = false;
            return pending && !string.IsNullOrEmpty(text);
        }

        /// <summary>Why the last session ended or failed ("" = none), shown by the menu.</summary>
        public static string Status { get; private set; } = "";

        public static bool StartHost()
        {
            PrepareSession();
            Seed = Environment.TickCount & 0x7fffffff;
            var m = EnsureManager();
            Transport.SetConnectionData("127.0.0.1", Port, "0.0.0.0");
            if (!m.StartHost())
            {
                Status = Localization.Extra("mpHostFailed", "Could not start hosting (is port 7777 in use?).");
                Shutdown();
                return false;
            }
            var state = UnityEngine.Object.Instantiate(Resources.Load<GameObject>($"{PrefabFolder}/NetState"));
            state.GetComponent<NetState>().SetSeed(Seed);
            state.GetComponent<NetworkObject>().Spawn(false);
            SpawnPlayer(NetworkManager.ServerClientId);
            EnterWorld();
            return true;
        }

        public static bool StartClient(string address)
        {
            PrepareSession();
            hostEndReason = null;
            var m = EnsureManager();
            Transport.SetConnectionData(address.Trim(), Port);
            if (!m.StartClient())
            {
                Status = Localization.Extra("mpJoinFailed", "Could not connect.");
                Shutdown();
                return false;
            }
            return true;   // NetState reaching this client (EnterWorld) starts the game
        }

        /// <summary>The world's state is here (the host at once, a client when NetState spawns): the seed, then the game
        /// starts docked at Var Hastra (no fly-in: the others see the ship appear on a pad), a new free-play game.</summary>
        internal static void EnterWorld(int seed = -1)
        {
            if (worldEntered) return;
            worldEntered = true;
            if (seed >= 0) Seed = seed;
            Session.DockedFromSpace = false;
            SceneManager.LoadScene(StationScene);
        }

        static bool closing, quitAfter, lostHandled;
        static string hostEndReason;

        /// <summary>Ends the session (leaving to the main menu, a failed connection). The host with players connected tells
        /// them why first and closes a moment later (NetDelayedShutdown), so the reason reaches them.</summary>
        public static void Shutdown()
        {
            NetChat.Clear();
            NetSquad.Clear();
            worldEntered = false;
            if (manager == null || closing) return;
            if (manager.IsServer && manager.IsListening && manager.ConnectedClientsIds.Count > 1 && NetState.Instance != null && NetState.Instance.IsSpawned)
            {
                closing = true;
                NetState.Instance.SessionEndingRpc(Localization.Extra("mpHostLeft", "The host ended the session."));
                manager.gameObject.AddComponent<NetDelayedShutdown>().Run(0.35f, quitAfter);
                return;
            }
            ShutdownNow();
        }

        /// <summary>Closing the game while hosting others: the quit waits for their goodbye (Shutdown), then goes on.</summary>
        static bool WantsToQuit()
        {
            if (manager == null || closing || !manager.IsServer || !manager.IsListening || manager.ConnectedClientsIds.Count <= 1) return true;
            quitAfter = true;
            Shutdown();
            return !closing;
        }

        /// <summary>NetState: the host announced the end (the next disconnect's reason).</summary>
        internal static void OnHostEnding(string reason) => hostEndReason = reason;

        /// <summary>Closes the session at once (Shutdown, NetDelayedShutdown).</summary>
        public static void ShutdownNow()
        {
            closing = false;
            quitAfter = false;
            playersSpawned.Clear();
            if (manager == null) return;
            manager.OnClientConnectedCallback -= OnClientConnected;
            manager.OnClientDisconnectCallback -= OnClientDisconnect;
            manager.OnClientStopped -= OnStopped;
            if (manager.IsListening) manager.Shutdown();
            // A moment later: Netcode finishes its shutdown at the end of the frame (destroyed at once, its OnDestroy shut the
            // transport down a second time: "DisconnectRemoteClient should only be called on a listening server!").
            UnityEngine.Object.Destroy(manager.gameObject, 0.25f);
            manager = null;
            if (SceneManager.GetActiveScene().name == MenuScene) sessionGame = false;   // already back in the menu
            // The session's objects live in DontDestroyOnLoad: gone with it (after Netcode's own shutdown, like the manager).
            foreach (var n in UnityEngine.Object.FindObjectsByType<NetworkObject>(FindObjectsInactive.Include))
                if (n != null) UnityEngine.Object.Destroy(n.gameObject, 0.3f);
        }

        /// <summary>This device's LAN address, for the host to tell the others.</summary>
        public static string LocalAddress()
        {
            try
            {
                foreach (var nic in NetworkInterface.GetAllNetworkInterfaces())
                {
                    if (nic.OperationalStatus != OperationalStatus.Up || nic.NetworkInterfaceType == NetworkInterfaceType.Loopback) continue;
                    foreach (var a in nic.GetIPProperties().UnicastAddresses)
                        if (a.Address.AddressFamily == AddressFamily.InterNetwork && !IPAddress.IsLoopback(a.Address)) return a.Address.ToString();
                }
            }
            catch (Exception) { }
            try
            {
                foreach (var a in Dns.GetHostEntry(Dns.GetHostName()).AddressList)
                    if (a.AddressFamily == AddressFamily.InterNetwork && !IPAddress.IsLoopback(a)) return a.ToString();
            }
            catch (Exception) { }
            return "127.0.0.1";
        }

        static UnityTransport Transport => (UnityTransport)manager.NetworkConfig.NetworkTransport;

        /// <summary>Status::resetGame as free play (no story), at Var Hastra, with the launch camera.</summary>
        static void PrepareSession()
        {
            Status = "";
            playersSpawned.Clear();   // statics outlive a session (and, with domain reload off, Play mode)
            worldEntered = transportConnected = lostHandled = false;
            closing = quitAfter = false;
            sessionGame = true;
            NetStock.Reset();
            Session.ResetNewGame();
            Session.Difficulty = Session.DifficultyNormal;   // every session plays on Normal (the shared stock, NPCs, rewards)
            Session.FreePlay = true;
            Session.CampaignMission = Session.FreePlayMission;
            Session.StationIndex = Station;
            Session.LaunchedFromStation = false;   // the session starts docked (EnterWorld)
        }

        static NetworkManager EnsureManager()
        {
            if (manager != null) return manager;
            var go = new GameObject("NetworkManager");
            UnityEngine.Object.DontDestroyOnLoad(go);
            var transport = go.AddComponent<UnityTransport>();
            transport.ConnectTimeoutMS = 1000;
            transport.MaxConnectAttempts = 10;   // a wrong address gives up after about 10 s
            transport.DisconnectTimeoutMS = 5000;   // a player whose game closed without leaving is gone after 5 s (default 30)
            manager = go.AddComponent<NetworkManager>();
            // No scene management: every player loads their own scenes (the shared world, see the header).
            manager.NetworkConfig = new NetworkConfig { NetworkTransport = transport, EnableSceneManagement = false, ConnectionApproval = false };
            foreach (var name in PrefabNames)
            {
                var prefab = Resources.Load<GameObject>($"{PrefabFolder}/{name}");
                if (prefab != null) manager.AddNetworkPrefab(prefab);
                else Debug.LogError($"NetGame: missing network prefab Resources/{PrefabFolder}/{name} (GoF2 > Build Network Prefabs)");
            }
            manager.OnClientConnectedCallback += OnClientConnected;
            manager.OnClientDisconnectCallback += OnClientDisconnect;
            manager.OnClientStopped += OnStopped;   // Netcode ending the session by itself (a transport failure)
            Application.quitting -= Shutdown;
            Application.quitting += Shutdown;   // closing the game leaves the session (the others see it at once)
            Application.wantsToQuit -= WantsToQuit;
            Application.wantsToQuit += WantsToQuit;   // hosting: the others hear why first
            return manager;
        }

        static void OnClientConnected(ulong clientId)
        {
            if (manager == null) return;
            if (!manager.IsServer) { if (clientId == manager.LocalClientId) transportConnected = true; return; }
            // The host is closing (its goodbye is out): a player connecting now is turned away with the reason.
            if (closing) { if (clientId != NetworkManager.ServerClientId) manager.DisconnectClient(clientId, Localization.Extra("mpHostLeft", "The host ended the session.")); return; }
            SpawnPlayer(clientId);
        }

        /// <summary>Netcode stopped this session by itself (not ShutdownNow, which unsubscribes first): like a lost host.</summary>
        static void OnStopped(bool wasHost)
        {
            if (manager == null) return;
            if (wasHost) { SessionEnded(Localization.Extra("mpStopped", "The session stopped (network error).")); return; }
            OnClientDisconnect(manager.LocalClientId);
        }

        /// <summary>The session is over while playing: out of it, back to the Multiplayer panel with the reason.</summary>
        static void SessionEnded(string reason)
        {
            if (lostHandled) return;
            lostHandled = true;
            Status = reason;
            Shutdown();
            PopupPending = true;
            UI.MainMenu.OpenPanelOnStart = "multiplayerPanel";
            SceneManager.LoadScene(MenuScene);
        }

        static void SpawnPlayer(ulong clientId)
        {
            if (!playersSpawned.Add(clientId)) return;
            var player = UnityEngine.Object.Instantiate(Resources.Load<GameObject>($"{PrefabFolder}/NetPlayer"));
            player.GetComponent<NetworkObject>().SpawnAsPlayerObject(clientId, false);
        }

        static void OnClientDisconnect(ulong clientId)
        {
            if (manager == null) return;
            if (manager.IsServer)
            {
                // That player's ship goes at once (NGO removes a player object with its owner; this also covers a late one),
                // and so does what they showed of their orbit (NGO destroys the objects a leaving client owns).
                playersSpawned.Remove(clientId);
                // (Netcode has usually despawned the player object already: its mission cargo is handed over in
                // NetPlayer.OnNetworkDespawn.)
                foreach (var p in UnityEngine.Object.FindObjectsByType<NetPlayer>())
                    if (p.OwnerClientId == clientId && p.IsSpawned) p.NetworkObject.Despawn();
                return;
            }
            // This client lost the host (or never reached it): the host's own reason, else a plain one (not Netcode's
            // "[Disconnect Event] ... ProtocolTimeout" text).
            if (lostHandled) return;
            string reason = hostEndReason ?? manager.DisconnectReason;
            hostEndReason = null;
            bool wasConnected = worldEntered;
            if (string.IsNullOrEmpty(reason) || reason.StartsWith("[")) reason = null;
            // A host that answered but ended the session before this player was in: not "no host".
            Status = reason ?? (wasConnected ? Localization.Extra("mpLost", "The connection to the host was lost.")
                                : transportConnected ? Localization.Extra("mpHostLeft", "The host ended the session.")
                                : Localization.Extra("mpNoHost", "No host found at that address."));
            if (!wasConnected && SceneManager.GetActiveScene().name == MenuScene)
            {
                // A failed join: the panel shows it.
                lostHandled = true;
                Shutdown();
                sessionGame = false;
                return;
            }
            SessionEnded(Status);
        }
    }
}
