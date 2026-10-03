// NetState.cs
// The multiplayer world (NetGame: the host spawns one; it lives in DontDestroyOnLoad for the whole session):
//   the world seed: reaching a client it starts that player's game (NetGame.EnterWorld); every orbit's asteroid field is
//     built from it (NetGame.OrbitSeed), so the players in one orbit share it;
//   destroyed asteroids per station, kept for the session: a player arriving in an orbit gets its list (the asteroids stay
//     gone), and a destruction reaches everyone (each applies it to its own orbit);
//   the spawn / despawn requests of an orbit's authority (NetOrbit): the NetProxy and NetCrate objects it shows the others
//     there are spawned by the host and owned by that player; the host also removes them once their owner is no longer in
//     that orbit (docked, jumped, gone);
//   the chat relay (NetChat): a player's line reaches everyone with the sender's name and location;
//   squads (NetSquad): invitations, joining and leaving, a squad of one dissolved; the players' kill notices;
//   squad missions (NetMissions): the shared missions, their progress and results, a disconnecting carrier's cargo;
//   the shared shop stock (NetStock): the host's list per station, the players' trades, the reset;
//   whether the session allows the Debug menu (NetGame.HostAllowsDebug, Cheats.Allowed);
//   a dedicated server's player profiles (NetProfiles / NetProfileClient): signing in, the profile to the player, their
//     uploads, handing control between a profile's devices, the chat's /link /control /profile commands;
//   moderation (NetAdmin): /kick /tempban /ban /unban /bans /op /deop /staff;
//   crews (NetCrews): the chat's /crew and /c commands, the claims (Claims), bank deposits and payouts;
//   arena matches (NetArena / NetArenaClient): the chat's /duel /accept /decline /ffa /leave /arena /top, a match's
//     start, state, end and kills; whether players may fight outside them (FreePvp, -freepvp).

using System.Collections.Generic;
using GoF2Remake.Data;
using Unity.Collections;
using Unity.Netcode;
using UnityEngine;

namespace GoF2Remake.Multiplayer
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public sealed class NetState : NetworkBehaviour
    {
        const float SweepSeconds = 0.5f;

        readonly NetworkVariable<int> seed = new NetworkVariable<int>();
        readonly NetworkVariable<bool> dedicated = new NetworkVariable<bool>();
        readonly NetworkVariable<bool> debugAllowed = new NetworkVariable<bool>();   // the host's / server's choice, fixed for the session
        readonly NetworkVariable<bool> profilesOn = new NetworkVariable<bool>();     // the server keeps player profiles (NetProfiles)
        readonly NetworkVariable<bool> freePvp = new NetworkVariable<bool>();        // players may fight anywhere (else only in arenas)
        readonly NetworkVariable<FixedString4096Bytes> claims = new NetworkVariable<FixedString4096Bytes>();   // NetCrews' territory
        readonly NetworkVariable<FixedString4096Bytes> sieges = new NetworkVariable<FixedString4096Bytes>();   // NetCrews' sieges
        readonly NetworkVariable<int> toll = new NetworkVariable<int>();   // NetCrews.Toll
        readonly NetworkVariable<FixedString64Bytes> serverId = new NetworkVariable<FixedString64Bytes>();   // their key on the client
        readonly Dictionary<int, HashSet<int>> destroyed = new Dictionary<int, HashSet<int>>();
        GameObject proxyPrefab, cratePrefab;
        int pendingSeed;
        bool pendingDedicated;
        float sweepTimer;
        readonly Dictionary<ulong, float> staleSince = new Dictionary<ulong, float>();

        /// <summary>The session's world, null outside one.</summary>
        public static NetState Instance { get; private set; }

        /// <summary>Host, before spawning (written in OnNetworkSpawn, so it is in the clients' spawn data); 'server' = a
        /// dedicated server, no player of its own.</summary>
        public void SetSeed(int value, bool server = false) { pendingSeed = value; pendingDedicated = server; }

        /// <summary>The session runs on a dedicated server: the players' client ids start at 1.</summary>
        public bool Dedicated => dedicated.Value;

        /// <summary>The session allows the Debug menu (NetGame.HostAllowsDebug when it started; off by default).</summary>
        public bool DebugAllowed => debugAllowed.Value;

        /// <summary>The server keeps player profiles: a joining game signs in and waits for its profile (NetProfileClient).</summary>
        public bool ProfilesOn => profilesOn.Value;

        /// <summary>Players may shoot each other anywhere (NetGame.FreePvp, -freepvp); else only in an arena match.</summary>
        public bool FreePvp => freePvp.Value;

        /// <summary>The crews' claimed stations, "station|TAG|Name" per line (NetCrews, NetCrewsClient).</summary>
        public string Claims => claims.Value.ToString();

        /// <summary>Server: the claims (cut at a whole line to fit the network variable's 4 KB).</summary>
        internal void SetClaims(string text)
        {
            if (!IsServer) return;
            text = Fit(text);
            if (claims.Value.ToString() != text) claims.Value = text;
        }

        /// <summary>The sieges, "station|attacker|defender|started|seconds left|control" per line (NetCrews).</summary>
        public string Sieges => sieges.Value.ToString();

        internal void SetSieges(string text)
        {
            if (!IsServer) return;
            text = Fit(text);
            if (sieges.Value.ToString() != text) sieges.Value = text;
        }

        /// <summary>The toll a pilot of another crew pays at a held station (NetCrews.Toll; 0 = none).</summary>
        public int Toll => toll.Value;

        internal void SetToll(int value) { if (IsServer && toll.Value != value) toll.Value = value; }

        static string Fit(string text)
        {
            text ??= "";
            while (System.Text.Encoding.UTF8.GetByteCount(text) > 4000)
            {
                int cut = text.LastIndexOf('\n', text.Length - 2);
                text = cut < 0 ? "" : text.Substring(0, cut + 1);
            }
            return text;
        }
        public override void OnNetworkSpawn()
        {
            name = "NetState";
            DontDestroyOnLoad(gameObject);
            Instance = this;
            if (IsServer)
            {
                seed.Value = pendingSeed;
                dedicated.Value = pendingDedicated;
                debugAllowed.Value = NetGame.HostAllowsDebug;
                profilesOn.Value = NetProfiles.Enabled;
                serverId.Value = NetProfiles.ServerId;
                freePvp.Value = NetGame.FreePvp;
                NetCrews.OnStateSpawned();   // the claims, now that this object exists
                proxyPrefab = Resources.Load<GameObject>($"{NetGame.PrefabFolder}/NetProxy");
                cratePrefab = Resources.Load<GameObject>($"{NetGame.PrefabFolder}/NetCrate");
            }
            // A server with profiles: the world waits for this player's profile (NetProfileClient.Begin -> EnterWorld).
            else if (profilesOn.Value) NetProfileClient.Begin(serverId.Value.ToString(), seed.Value);
            else NetGame.EnterWorld(seed.Value);
        }

        public override void OnNetworkDespawn()
        {
            if (Instance == this) Instance = null;
        }

        /// <summary>No other player is in this orbit: the arriving player builds its traffic (only then: the players already
        /// there never see ships appear out of nowhere).</summary>
        public static bool OrbitEmpty(int station)
        {
            foreach (var p in NetPlayer.All)
                if (p != null && !p.IsOwner && p.IsSpawned && p.InSpace && p.Station == station) return false;
            return true;
        }

        /// <summary>Nobody else runs this orbit's NPCs: a player there may take the old authority's ships over (NetOrbit).</summary>
        public static bool IsOrbitAuthority(int station)
        {
            foreach (var p in NetPlayer.All)
                if (p != null && !p.IsOwner && p.IsSpawned && p.InSpace && p.Station == station && p.OrbitAuthority) return false;
            return true;
        }

        // ---- asteroids --------------------------------------------------------------------------------------

        /// <summary>A player destroyed asteroid 'index' of 'station' (shot, mined, rammed).</summary>
        [Rpc(SendTo.Server)]
        public void AsteroidDestroyedRpc(int station, int index, bool mined, RpcParams rpc = default)
        {
            if (!destroyed.TryGetValue(station, out var set)) destroyed[station] = set = new HashSet<int>();
            var by = NetSquad.Find(rpc.Receive.SenderClientId);
            if (set.Add(index)) AsteroidGoneRpc(station, index, by != null ? by.DisplayName : "", mined);
        }

        /// <summary>'by': the pilot who destroyed it, 'mined': drilled out (else shot / rammed): a miner's message (Mining).</summary>
        [Rpc(SendTo.Everyone)]
        void AsteroidGoneRpc(int station, int index, string by, bool mined) => NetOrbit.Current?.OnAsteroidGone(station, index, by, mined);

        /// <summary>A player arrived in 'station': the asteroids already gone there.</summary>
        [Rpc(SendTo.Server)]
        public void RequestDestroyedRpc(int station, RpcParams rpc = default)
        {
            var list = destroyed.TryGetValue(station, out var set) ? new List<int>(set).ToArray() : new int[0];
            DestroyedListRpc(station, list, RpcTarget.Single(rpc.Receive.SenderClientId, RpcTargetUse.Temp));
        }

        [Rpc(SendTo.SpecifiedInParams)]
        void DestroyedListRpc(int station, int[] indices, RpcParams rpc = default) => NetOrbit.Current?.OnDestroyedList(station, indices);

        // ---- chat (NetChat) ---------------------------------------------------------------------------------

        /// <summary>A player's chat line: the host adds who and where, then everyone gets it (NetChat keeps what is theirs).</summary>
        [Rpc(SendTo.Server)]
        public void SendChatRpc(string text, bool global, RpcParams rpc = default)
        {
            text = NetChat.Clean(text);
            if (text.Length == 0) return;
            // Commands (the arena's /duel /ffa ..., the profiles' /link /control /profile): answered to the sender only,
            // never shown to the others.
            if (text[0] == '/')
            {
                ulong from = rpc.Receive.SenderClientId;
                string answer = NetArena.Command(from, text)
                                ?? (NetProfiles.Enabled ? NetAdmin.Command(from, text) ?? NetCrews.Command(from, text) ?? NetProfiles.Command(from, text)
                                    : Localization.Extra("mpArenaCommands", "Commands: /duel <name>, /accept, /decline, /ffa, /leave, /arena."));
                if (!string.IsNullOrEmpty(answer)) Notify(from, answer);
                return;
            }
            NetPlayer sender = null;
            foreach (var p in NetPlayer.All) if (p != null && p.OwnerClientId == rpc.Receive.SenderClientId) { sender = p; break; }
            if (sender == null) return;
            ChatRpc(sender.OwnerClientId, sender.TaggedName, text, global, sender.Station, sender.InSpace, sender.InHangar);
        }

        /// <summary>Server: a global chat line from the server itself (the dedicated server's say command).</summary>
        public void ServerChat(string from, string text)
        {
            text = NetChat.Clean(text);
            if (IsServer && text.Length > 0) ChatRpc(NetworkManager.ServerClientId, from, text, true, -1, false, false);
        }

        [Rpc(SendTo.Everyone)]
        void ChatRpc(ulong sender, string from, string text, bool global, int station, bool inSpace, bool inHangar)
            => NetChat.Receive(sender, from, text, global, station, inSpace, inHangar);

        // ---- squads (NetSquad) ------------------------------------------------------------------------------

        int nextSquad = 1;

        [Rpc(SendTo.Server)]
        public void InviteRpc(ulong target, RpcParams rpc = default)
        {
            var from = NetSquad.Find(rpc.Receive.SenderClientId);
            var to = NetSquad.Find(target);
            if (from == null || to == null || NetSquad.Same(from, to)) return;
            InvitedRpc(from.OwnerClientId, from.DisplayName, RpcTarget.Single(target, RpcTargetUse.Temp));
        }

        [Rpc(SendTo.SpecifiedInParams)]
        void InvitedRpc(ulong from, string name, RpcParams rpc = default) => NetSquad.OnInvited(from, name);

        /// <summary>The invited player said yes: into the inviter's squad (a new one if the inviter had none).</summary>
        [Rpc(SendTo.Server)]
        public void AcceptInviteRpc(ulong inviter, RpcParams rpc = default)
        {
            var leader = NetSquad.Find(inviter);
            var joiner = NetSquad.Find(rpc.Receive.SenderClientId);
            if (leader == null || joiner == null || leader == joiner || NetSquad.Same(leader, joiner)) return;   // squadmates already
            // Squads form only in a hangar: both docked at the same station.
            if (!leader.InHangar || !joiner.InHangar || leader.Station != joiner.Station)
            {
                NoticeToRpc(Localization.Extra("mpSquadHangarOnly", "Squads can only be formed while docked in the same hangar."),
                            RpcTarget.Single(joiner.OwnerClientId, RpcTargetUse.Temp));
                return;
            }
            JoinSquad(leader, joiner);
            NetProfiles.SquadJoined(leader.OwnerClientId, joiner.OwnerClientId);   // both profiles remember it
        }

        /// <summary>'joiner' into 'leader''s squad (a new one if the leader has none).</summary>
        void JoinSquad(NetPlayer leader, NetPlayer joiner)
        {
            if (leader.SquadId == 0) leader.SetSquad(nextSquad++);
            joiner.SetSquad(leader.SquadId);
            DissolveSingles();
            // The joiner's own mission goes; the squad's active one (the inviter's first) comes to them.
            JoinedSquadRpc(RpcTarget.Single(joiner.OwnerClientId, RpcTargetUse.Temp));
            NetPlayer holder = leader.MissionHeld != 0 ? leader : null;
            if (holder == null)
                foreach (var p in NetPlayer.All)
                    if (p != null && p != joiner && p.IsSpawned && p.SquadId == leader.SquadId && p.MissionHeld != 0) { holder = p; break; }
            if (holder != null) SendMissionToRpc(joiner.OwnerClientId, RpcTarget.Single(holder.OwnerClientId, RpcTargetUse.Temp));
            SquadNoticeRpc(leader.SquadId, string.Format(Localization.Extra("mpSquadJoined", "{0} joined the squad."), joiner.DisplayName));
        }

        /// <summary>NetProfiles: a player signing in goes back into the squad their profile remembers ('mate' is online and
        /// in it). Unlike an invitation this works anywhere, docked or not.</summary>
        internal void RestoreSquad(NetPlayer mate, NetPlayer joiner)
        {
            if (!IsServer || mate == null || joiner == null || mate == joiner || NetSquad.Same(mate, joiner)) return;
            JoinSquad(mate, joiner);
        }

        [Rpc(SendTo.Server)]
        public void LeaveSquadRpc(RpcParams rpc = default)
        {
            var p = NetSquad.Find(rpc.Receive.SenderClientId);
            if (p == null || p.SquadId == 0) return;
            int id = p.SquadId;
            p.SetSquad(0);
            NetProfiles.SquadLeft(p.OwnerClientId);
            LeftSquadRpc(RpcTarget.Single(p.OwnerClientId, RpcTargetUse.Temp));   // the squad's mission leaves with them
            SquadNoticeRpc(id, string.Format(Localization.Extra("mpSquadLeft", "{0} left the squad."), p.DisplayName));
            DissolveSingles();
        }

        [Rpc(SendTo.Everyone)]
        void SquadNoticeRpc(int squad, string text)
        {
            if (NetSquad.LocalSquad == squad || (NetPlayer.Local != null && text.Contains(NetPlayer.Local.DisplayName))) NetChat.Notice(text);
        }

        /// <summary>A squad of one is no squad (the others left or disconnected).</summary>
        void DissolveSingles()
        {
            var count = new Dictionary<int, int>();
            foreach (var p in NetPlayer.All)
                if (p != null && p.IsSpawned && p.SquadId != 0) count[p.SquadId] = count.TryGetValue(p.SquadId, out int c) ? c + 1 : 1;
            foreach (var p in NetPlayer.All)
                if (p != null && p.IsSpawned && p.SquadId != 0 && count[p.SquadId] < 2) p.SetSquad(0);
        }

        /// <summary>A player's ship was destroyed by another player: everyone hears of it.</summary>
        [Rpc(SendTo.Server)]
        public void DestroyedByRpc(ulong killer, RpcParams rpc = default)
        {
            var victim = NetSquad.Find(rpc.Receive.SenderClientId);
            var by = NetSquad.Find(killer);
            if (victim == null || by == null) return;
            NetArena.OnKill(victim.OwnerClientId, by.OwnerClientId);   // an arena match's score
            NoticeRpc(string.Format(Localization.Extra("mpDestroyedBy", "{0} was destroyed by {1}."), victim.DisplayName, by.DisplayName));
        }

        [Rpc(SendTo.Everyone)]
        void NoticeRpc(string text) => NetChat.Notice(text);

        [Rpc(SendTo.SpecifiedInParams)]
        void NoticeToRpc(string text, RpcParams rpc = default) => NetChat.Notice(text);

        /// <summary>Server: a notice in one player's chat.</summary>
        internal void Notify(ulong client, string text)
        {
            if (IsServer && !string.IsNullOrEmpty(text)) NoticeToRpc(text, RpcTarget.Single(client, RpcTargetUse.Temp));
        }

        // ---- player profiles (NetProfiles / NetProfileClient) ----------------------------------------------

        int profileSeq;

        /// <summary>A joining game on a server with profiles: its token for this server ("" = none) and device label.</summary>
        [Rpc(SendTo.Server)]
        public void LoginRpc(string token, string device, string name, RpcParams rpc = default)
            => NetProfiles.OnLogin(rpc.Receive.SenderClientId, token, device, name);

        /// <summary>Server: a profile to one player: the header (its new token, if any; its role), then the gzipped chunks
        /// (none = a fresh start). Reliable RPCs to one client arrive in order.</summary>
        internal void SendProfile(ulong client, string token, bool controller, bool guest, string json, int home)
        {
            if (!IsServer) return;
            var parts = NetProfiles.Pack(json);
            int seq = ++profileSeq;
            ProfileHeaderRpc(seq, parts.Count, token ?? "", controller, guest, home, RpcTarget.Single(client, RpcTargetUse.Temp));
            for (int i = 0; i < parts.Count; i++) ProfileChunkRpc(seq, i, parts[i], RpcTarget.Single(client, RpcTargetUse.Temp));
        }

        [Rpc(SendTo.SpecifiedInParams)]
        void ProfileHeaderRpc(int seq, int count, string token, bool controller, bool guest, int home, RpcParams rpc = default)
            => NetProfileClient.OnProfileHeader(seq, count, token, controller, guest, home);

        [Rpc(SendTo.SpecifiedInParams)]
        void ProfileChunkRpc(int seq, int part, byte[] data, RpcParams rpc = default) => NetProfileClient.OnProfileChunk(seq, part, data);

        /// <summary>A player's profile, a chunk at a time (NetProfileClient.Upload).</summary>
        [Rpc(SendTo.Server)]
        public void UploadChunkRpc(int seq, int part, int count, byte[] data, RpcParams rpc = default)
            => NetProfiles.OnUploadChunk(rpc.Receive.SenderClientId, seq, part, count, data);

        /// <summary>Server: this player's device controls its profile now, or watches.</summary>
        internal void SendRole(ulong client, bool controller)
        {
            if (IsServer) RoleRpc(controller, RpcTarget.Single(client, RpcTargetUse.Temp));
        }

        [Rpc(SendTo.SpecifiedInParams)]
        void RoleRpc(bool controller, RpcParams rpc = default) => NetProfileClient.OnRole(controller);

        /// <summary>Server: the old controller sends its profile once more before another device takes over (/control).</summary>
        internal void RequestUpload(ulong client)
        {
            if (IsServer) RequestUploadRpc(RpcTarget.Single(client, RpcTargetUse.Temp));
        }

        [Rpc(SendTo.SpecifiedInParams)]
        void RequestUploadRpc(RpcParams rpc = default) => NetProfileClient.Upload(true);

        // ---- crews (NetCrews / NetCrewsClient) -------------------------------------------------------------

        /// <summary>Server: the player's game is asked to pay a crew deposit ('token' answers it).</summary>
        internal void Charge(ulong client, int token, int amount)
        {
            if (IsServer) ChargeRpc(token, amount, RpcTarget.Single(client, RpcTargetUse.Temp));
        }

        [Rpc(SendTo.SpecifiedInParams)]
        void ChargeRpc(int token, int amount, RpcParams rpc = default) => NetCrewsClient.OnCharge(token, amount);

        /// <summary>The player's game paid the deposit 'token' (or had too few credits).</summary>
        [Rpc(SendTo.Server)]
        public void ChargedRpc(int token, bool paid, RpcParams rpc = default) => NetCrews.OnCharged(rpc.Receive.SenderClientId, token, paid);

        /// <summary>Server: credits from the crew bank to the player's game.</summary>
        internal void Grant(ulong client, int amount)
        {
            if (IsServer) GrantRpc(amount, RpcTarget.Single(client, RpcTargetUse.Temp));
        }

        [Rpc(SendTo.SpecifiedInParams)]
        void GrantRpc(int amount, RpcParams rpc = default) => NetCrewsClient.OnGrant(amount);

        /// <summary>A pilot of another crew paid the toll at 'station' (their game took the credits).</summary>
        [Rpc(SendTo.Server)]
        public void TollPaidRpc(int station, RpcParams rpc = default) => NetCrews.OnTollPaid(rpc.Receive.SenderClientId, station);

        /// <summary>Server: a notice for everyone (a claim).</summary>
        internal void Announce(string text)
        {
            if (IsServer && !string.IsNullOrEmpty(text)) NoticeRpc(text);
        }

        // ---- the station's Crew / Arena / Profile window (NetPanel) ----------------------------------------

        /// <summary>The window asks for its snapshot.</summary>
        [Rpc(SendTo.Server)]
        public void PanelRequestRpc(RpcParams rpc = default) => NetPanel.Send(rpc.Receive.SenderClientId);

        /// <summary>Server: a chunk of the snapshot to one player.</summary>
        internal void PanelChunk(ulong client, int seq, int part, int count, byte[] data)
        {
            if (IsServer) PanelChunkRpc(seq, part, count, data, RpcTarget.Single(client, RpcTargetUse.Temp));
        }

        [Rpc(SendTo.SpecifiedInParams)]
        void PanelChunkRpc(int seq, int part, int count, byte[] data, RpcParams rpc = default) => NetPanel.OnChunk(seq, part, count, data);

        // ---- arena matches (NetArena / NetArenaClient) -----------------------------------------------------

        /// <summary>Server: the player goes into match 'id' (their game loads the arena).</summary>
        internal void ArenaStart(ulong client, int id, byte kind, int orbitId, int template, bool voids, int slot, int killLimit, float seconds)
        {
            if (IsServer) ArenaStartRpc(id, kind, orbitId, template, voids, slot, killLimit, seconds, RpcTarget.Single(client, RpcTargetUse.Temp));
        }

        [Rpc(SendTo.SpecifiedInParams)]
        void ArenaStartRpc(int id, byte kind, int orbitId, int template, bool voids, int slot, int killLimit, float seconds, RpcParams rpc = default)
            => NetArenaClient.OnStart(id, kind, orbitId, template, voids, slot, killLimit, seconds);

        /// <summary>A player's game has the arena loaded.</summary>
        [Rpc(SendTo.Server)]
        public void ArenaReadyRpc(int id, RpcParams rpc = default) => NetArena.OnReady(rpc.Receive.SenderClientId, id);

        /// <summary>Server: the match's phase, seconds left, scores and a kill-feed line ("" = none) to one player.</summary>
        internal void ArenaState(ulong client, int id, byte phase, float left, ulong[] players, int[] kills, string feed)
        {
            if (IsServer) ArenaStateRpc(id, phase, left, players, kills, feed, RpcTarget.Single(client, RpcTargetUse.Temp));
        }

        [Rpc(SendTo.SpecifiedInParams)]
        void ArenaStateRpc(int id, byte phase, float left, ulong[] players, int[] kills, string feed, RpcParams rpc = default)
            => NetArenaClient.OnState(id, phase, left, players, kills, feed);

        /// <summary>Server: the match is over (the result's text); the player's game goes home after showing it.</summary>
        internal void ArenaEnd(ulong client, int id, string text)
        {
            if (IsServer) ArenaEndRpc(id, text, RpcTarget.Single(client, RpcTargetUse.Temp));
        }

        [Rpc(SendTo.SpecifiedInParams)]
        void ArenaEndRpc(int id, string text, RpcParams rpc = default) => NetArenaClient.OnEnd(id, text);

        /// <summary>Server: the player left their match (/leave): home at once.</summary>
        internal void ArenaLeave(ulong client)
        {
            if (IsServer) ArenaLeaveRpc(RpcTarget.Single(client, RpcTargetUse.Temp));
        }

        [Rpc(SendTo.SpecifiedInParams)]
        void ArenaLeaveRpc(RpcParams rpc = default) => NetArenaClient.OnLeave();

        [Rpc(SendTo.SpecifiedInParams)]
        void JoinedSquadRpc(RpcParams rpc = default) => NetMissions.OnJoinedSquad();

        [Rpc(SendTo.SpecifiedInParams)]
        void LeftSquadRpc(RpcParams rpc = default) => NetMissions.OnLeftSquad();

        [Rpc(SendTo.SpecifiedInParams)]
        void SendMissionToRpc(ulong client, RpcParams rpc = default) => NetMissions.SendTo(client);

        /// <summary>A squad member's mission for one player (the squad's new member).</summary>
        [Rpc(SendTo.Server)]
        public void ShareMissionToRpc(string json, ulong client, RpcParams rpc = default)
        {
            var from = NetSquad.Find(rpc.Receive.SenderClientId);
            var to = NetSquad.Find(client);
            if (from == null || to == null || from.SquadId == 0 || to.SquadId != from.SquadId) return;
            ReceiveMissionRpc(json, from.DisplayName, true, RpcTarget.Single(client, RpcTargetUse.Temp));
        }

        /// <summary>The host is closing the session: its reason, before the connection goes (NetGame.Shutdown).</summary>
        [Rpc(SendTo.NotServer)]
        public void SessionEndingRpc(string reason) => NetGame.OnHostEnding(reason);

        // ---- squad missions (NetMissions) -------------------------------------------------------------------

        /// <summary>A player's mission for their squadmates (a new one or an update).</summary>
        [Rpc(SendTo.Server)]
        public void ShareMissionRpc(string json, bool isNew, RpcParams rpc = default)
        {
            var from = NetSquad.Find(rpc.Receive.SenderClientId);
            if (from == null || from.SquadId == 0) return;
            if (isNew)
            {
                // The host checks the acceptance too: the whole squad docked at the sender's station, and no other member's
                // new mission a moment ago (two accepting at once would swap missions): else the sender's is refused.
                long netId = 0;
                try { netId = JsonUtility.FromJson<FreelanceMission>(json).netId; } catch (System.Exception) { }
                string refusal = null;
                foreach (var p in NetPlayer.All)
                    if (p != null && p != from && p.IsSpawned && p.SquadId == from.SquadId && (p.Where != NetPlayer.Place.Hangar || p.Station != from.Station))
                        refusal = Localization.Extra("mpMissionSquadHere", "The whole squad must be docked at this station to accept a mission.");
                if (squadAccepts.TryGetValue(from.SquadId, out var last) && last.netId != netId && Time.unscaledTime - last.time < 3f)
                    refusal = string.Format(Localization.Extra("mpMissionAtOnce", "{0} accepted a squad mission at the same moment."), last.who);
                if (refusal != null) { MissionRefusedRpc(netId, refusal, RpcTarget.Single(from.OwnerClientId, RpcTargetUse.Temp)); return; }
                squadAccepts[from.SquadId] = (netId, Time.unscaledTime, from.DisplayName);
            }
            foreach (var p in NetPlayer.All)
                if (p != null && p != from && p.IsSpawned && p.SquadId == from.SquadId)
                    ReceiveMissionRpc(json, from.DisplayName, isNew, RpcTarget.Single(p.OwnerClientId, RpcTargetUse.Temp));
        }

        [Rpc(SendTo.SpecifiedInParams)]
        void ReceiveMissionRpc(string json, string from, bool isNew, RpcParams rpc = default) => NetMissions.Receive(json, from, isNew);

        /// <summary>Host: each squad's last new mission (ShareMissionRpc's check).</summary>
        readonly Dictionary<int, (long netId, float time, string who)> squadAccepts = new Dictionary<int, (long, float, string)>();
        /// <summary>Host: the missions already ended (a second result, e.g. two members delivering at once, is dropped).</summary>
        readonly HashSet<long> endedMissions = new HashSet<long>();

        [Rpc(SendTo.SpecifiedInParams)]
        void MissionRefusedRpc(long netId, string reason, RpcParams rpc = default) => NetMissions.OnRefused(netId, reason);

        /// <summary>The squad's mission (the sender's squad, and whoever holds that mission) other than the sender.</summary>
        List<NetPlayer> MissionTeam(NetPlayer from, long netId)
        {
            var list = new List<NetPlayer>();
            foreach (var p in NetPlayer.All)
                if (p != null && p != from && p.IsSpawned && ((from.SquadId != 0 && p.SquadId == from.SquadId) || p.MissionHeld == netId))
                    list.Add(p);
            return list;
        }

        /// <summary>A squad mission's end (NetMissions.Result: success with each member's share, failure, abandoned) for the
        /// rest of the squad.</summary>
        [Rpc(SendTo.Server)]
        public void MissionResultRpc(long netId, int result, int share, RpcParams rpc = default)
        {
            var from = NetSquad.Find(rpc.Receive.SenderClientId);
            if (from == null || netId == 0 || !endedMissions.Add(netId)) return;   // once per mission
            foreach (var p in MissionTeam(from, netId))
                MissionResultToRpc(netId, result, share, from.DisplayName, RpcTarget.Single(p.OwnerClientId, RpcTargetUse.Temp));
        }

        [Rpc(SendTo.SpecifiedInParams)]
        void MissionResultToRpc(long netId, int result, int share, string from, RpcParams rpc = default)
            => NetMissions.OnResult(netId, result, share, from);

        /// <summary>The squad mission's shared progress ('status' + delta: delivered ore, the captured container).</summary>
        [Rpc(SendTo.Server)]
        public void MissionStatusRpc(long netId, int delta, RpcParams rpc = default)
        {
            var from = NetSquad.Find(rpc.Receive.SenderClientId);
            if (from == null || netId == 0 || endedMissions.Contains(netId)) return;
            foreach (var p in MissionTeam(from, netId))
                MissionStatusToRpc(netId, delta, RpcTarget.Single(p.OwnerClientId, RpcTargetUse.Temp));
        }

        [Rpc(SendTo.SpecifiedInParams)]
        void MissionStatusToRpc(long netId, int delta, RpcParams rpc = default) => NetMissions.OnStatus(netId, delta);

        /// <summary>Host: 'gone' disconnects; what they carried for the mission (containers, passengers) goes to a member still
        /// holding it (their squad first), so the squad keeps a mission it can finish.</summary>
        public void HandOverMission(NetPlayer gone)
        {
            if (!IsServer || gone == null || gone.MissionHeld == 0 || gone.MissionCargo == 0) return;
            NetPlayer to = null;
            foreach (var p in NetPlayer.All)
                if (p != null && p != gone && p.IsSpawned && p.MissionHeld == gone.MissionHeld
                    && (to == null || (p.SquadId == gone.SquadId && to.SquadId != gone.SquadId))) to = p;
            if (to != null) TakeMissionCargoRpc(gone.MissionHeld, gone.MissionCargo, gone.DisplayName, RpcTarget.Single(to.OwnerClientId, RpcTargetUse.Temp));
        }

        [Rpc(SendTo.SpecifiedInParams)]
        void TakeMissionCargoRpc(long netId, int cargo, string from, RpcParams rpc = default) => NetMissions.TakeCargo(netId, cargo, from);

        // ---- the shared shop stock (NetStock) ------------------------------------------------------------------

        /// <summary>A player docked at 'station': the host's stock there (made now if it has none).</summary>
        [Rpc(SendTo.Server)]
        public void StockRequestRpc(int station, RpcParams rpc = default)
            => StockRpc(station, NetStock.HostGet(station), RpcTarget.Single(rpc.Receive.SenderClientId, RpcTargetUse.Temp));

        /// <summary>A player bought (-1, for 'price') or sold (+1) an item at 'station'; a unit no longer there goes back.</summary>
        [Rpc(SendTo.Server)]
        public void StockItemRpc(int station, int item, int delta, int price, RpcParams rpc = default)
        {
            if (!NetStock.HostItem(station, item, delta))
                ItemRefusedRpc(station, item, price, RpcTarget.Single(rpc.Receive.SenderClientId, RpcTargetUse.Temp));
            else if (delta < 0 && NetProfiles.Enabled) NetCrews.OnPurchase(rpc.Receive.SenderClientId, station, price);   // a crew station's tax
            BroadcastStock(station);
        }

        [Rpc(SendTo.SpecifiedInParams)]
        void ItemRefusedRpc(int station, int item, int price, RpcParams rpc = default) => NetStock.ItemRefused(station, item, price);

        /// <summary>A player wants the dealer's ship 'ship' at 'station': theirs if it is still there (then off the list).</summary>
        [Rpc(SendTo.Server)]
        public void ReserveShipRpc(int station, int ship, RpcParams rpc = default)
        {
            bool ok = NetStock.HostReserveShip(station, ship);
            ReserveResultRpc(station, ship, ok, RpcTarget.Single(rpc.Receive.SenderClientId, RpcTargetUse.Temp));
            if (ok) BroadcastStock(station);
        }

        [Rpc(SendTo.SpecifiedInParams)]
        void ReserveResultRpc(int station, int ship, bool ok, RpcParams rpc = default) => NetStock.ReserveResult(station, ship, ok);

        /// <summary>A player's ship trade at 'station': the dealer's row 'removed' became 'added' (-1 = none).</summary>
        [Rpc(SendTo.Server)]
        public void StockShipRpc(int station, int removed, int added)
        {
            if (NetStock.HostShip(station, removed, added)) BroadcastStock(station);
        }

        /// <summary>Host: the stock of 'station' for every player docked there.</summary>
        internal void BroadcastStock(int station)
        {
            string text = NetStock.HostGet(station);
            foreach (var p in NetPlayer.All)
                if (p != null && p.IsSpawned && p.InHangar && p.Station == station)
                    StockRpc(station, text, RpcTarget.Single(p.OwnerClientId, RpcTargetUse.Temp));
        }

        [Rpc(SendTo.SpecifiedInParams)]
        void StockRpc(int station, string text, RpcParams rpc = default) => NetStock.Apply(station, text);

        // ---- the orbit authority's objects ------------------------------------------------------------------

        /// <summary>An orbit authority shows its ship 'localId' (NetOrbit's list) of 'station' to the others.</summary>
        [Rpc(SendTo.Server)]
        public void SpawnProxyRpc(int station, int localId, RpcParams rpc = default)
        {
            if (proxyPrefab == null) return;
            var go = Instantiate(proxyPrefab);
            go.GetComponent<NetProxy>().Init(station, localId);
            var obj = go.GetComponent<NetworkObject>();
            obj.DontDestroyWithOwner = true;   // an owner who disconnects leaves it to the host: the others can take it over
            obj.SpawnWithOwnership(rpc.Receive.SenderClientId, false);
        }

        /// <summary>An orbit authority shows its crate 'localId' of 'station' to the others.</summary>
        [Rpc(SendTo.Server)]
        public void SpawnCrateRpc(int station, int localId, RpcParams rpc = default)
        {
            if (cratePrefab == null) return;
            var go = Instantiate(cratePrefab);
            go.GetComponent<NetCrate>().Init(station, localId);
            go.GetComponent<NetworkObject>().SpawnWithOwnership(rpc.Receive.SenderClientId, false);
        }

        /// <summary>A player took a ship / junk / crate of another game over (NetOrbit, FreelanceOrbit.Promote): its old copy
        /// goes for everyone, and when its creator is still in that orbit their own ship goes too (TakenOverRpc).</summary>
        [Rpc(SendTo.Server)]
        public void AdoptedRpc(ulong objectId, RpcParams rpc = default)
        {
            if (!NetworkManager.SpawnManager.SpawnedObjects.TryGetValue(objectId, out var obj) || obj == null || !obj.IsSpawned) return;
            var proxy = obj.GetComponent<NetProxy>();
            var crate = obj.GetComponent<NetCrate>();
            int station = proxy != null ? proxy.Station : crate != null ? crate.Station : -1;
            ulong creator = proxy != null ? proxy.Creator : obj.OwnerClientId;
            if (creator == rpc.Receive.SenderClientId) return;
            if (NetOrbit.InOrbit(creator, station) && obj.OwnerClientId == creator)
            {
                if (proxy != null) proxy.TakenOverRpc();
                else crate.TakenOverRpc();
                return;   // the creator's game drops its own (NetOrbit's scan despawns it)
            }
            obj.Despawn();
        }

        // ---- a hangar's NPC ships (NetHangar) -------------------------------------------------------------------

        /// <summary>The game running 'station's hangar: an NPC ship lands (key, ship, yaw) or takes off (key): the others docked
        /// there do the same.</summary>
        [Rpc(SendTo.Server)]
        public void HangarNpcRpc(int station, bool landing, int key, int ship, float yaw, RpcParams rpc = default)
        {
            foreach (var p in NetPlayer.All)
                if (p != null && p.IsSpawned && p.OwnerClientId != rpc.Receive.SenderClientId && p.InHangar && p.Station == station)
                    HangarNpcToRpc(landing, key, ship, yaw, RpcTarget.Single(p.OwnerClientId, RpcTargetUse.Temp));
        }

        [Rpc(SendTo.SpecifiedInParams)]
        void HangarNpcToRpc(bool landing, int key, int ship, float yaw, RpcParams rpc = default) => NetHangar.Current?.OnRemoteNpc(landing, key, ship, yaw);

        /// <summary>A player docked at 'station' wants its NPC ships as they are: the running game sends them.</summary>
        [Rpc(SendTo.Server)]
        public void HangarSnapshotRequestRpc(int station, RpcParams rpc = default)
        {
            NetPlayer runner = null;
            foreach (var p in NetPlayer.All)
                if (p != null && p.IsSpawned && p.OwnerClientId != rpc.Receive.SenderClientId && p.InHangar && p.Station == station && p.HangarRun
                    && (runner == null || p.OwnerClientId < runner.OwnerClientId)) runner = p;
            if (runner != null) HangarSnapshotAskRpc(rpc.Receive.SenderClientId, RpcTarget.Single(runner.OwnerClientId, RpcTargetUse.Temp));
        }

        [Rpc(SendTo.SpecifiedInParams)]
        void HangarSnapshotAskRpc(ulong requester, RpcParams rpc = default) => NetHangar.Current?.SendSnapshot(requester);

        [Rpc(SendTo.Server)]
        public void HangarSnapshotRpc(ulong requester, string data) => HangarSnapshotToRpc(data, RpcTarget.Single(requester, RpcTargetUse.Temp));

        [Rpc(SendTo.SpecifiedInParams)]
        void HangarSnapshotToRpc(string data, RpcParams rpc = default) => NetHangar.Current?.OnSnapshot(data);

        /// <summary>The Kaamo siege won in a player's game: the others in that orbit (their siege view) win it too.</summary>
        [Rpc(SendTo.Server)]
        public void SiegeWonRpc(int station, RpcParams rpc = default)
        {
            foreach (var p in NetPlayer.All)
                if (p != null && p.IsSpawned && p.OwnerClientId != rpc.Receive.SenderClientId && p.InSpace && p.Station == station)
                    SiegeWonToRpc(RpcTarget.Single(p.OwnerClientId, RpcTargetUse.Temp));
        }

        [Rpc(SendTo.SpecifiedInParams)]
        void SiegeWonToRpc(RpcParams rpc = default) => World.KaamoSiege.Current?.OnRemoteWin();

        /// <summary>Its owner is done with a NetProxy / NetCrate (the ship left or died for good, the crate was taken).</summary>
        [Rpc(SendTo.Server)]
        public void DespawnRpc(ulong objectId, RpcParams rpc = default)
        {
            if (NetworkManager.SpawnManager.SpawnedObjects.TryGetValue(objectId, out var obj) && obj != null
                && obj.OwnerClientId == rpc.Receive.SenderClientId && obj.IsSpawned)
                obj.Despawn();
        }

        void Update()
        {
            NetStock.Flush();   // the shared stock that arrived, applied between frames (every player)
            if (!IsServer || !IsSpawned) return;
            NetProfiles.Tick();   // link codes and handovers that ran out
            NetArena.Tick();      // queues, countdowns, time limits
            if (NetProfiles.Enabled) NetCrews.Tick();   // claims kept by docking members, lapses, stale deposits
            if ((sweepTimer -= Time.unscaledDeltaTime) > 0f) return;
            sweepTimer = SweepSeconds;
            NetStock.HostTick(this);   // the stock resets
            DissolveSingles();   // a squadmate who disconnected
            // An orbit's objects go once their owner isn't in that orbit any more.
            var owners = new Dictionary<ulong, NetPlayer>();
            foreach (var p in NetPlayer.All) if (p != null && p.IsSpawned) owners[p.OwnerClientId] = p;
            var stale = new List<NetworkObject>();
            foreach (var obj in NetworkManager.SpawnManager.SpawnedObjectsList)
            {
                int station;
                var proxy = obj.GetComponent<NetProxy>();
                var crate = proxy == null ? obj.GetComponent<NetCrate>() : null;
                if (proxy != null) station = proxy.Station;
                else if (crate != null) station = crate.Station;
                else continue;
                // A new one waits for its owner's position (sent at the tick, maybe after the spawn request).
                if (Time.unscaledTime - (proxy != null ? proxy.SpawnedAt : crate.SpawnedAt) < 3f) continue;
                bool orphan = proxy != null && proxy.Orphan;   // its owner left the session: the host holds it without a ship
                if (!orphan && owners.TryGetValue(obj.OwnerClientId, out var owner) && owner.InSpace && owner.Station == station) { staleSince.Remove(obj.NetworkObjectId); continue; }
                // Players still in that orbit take its ships over (NetOrbit): they keep the old proxies a few seconds.
                bool watched = false;
                foreach (var p in owners.Values) if (p.InSpace && p.Station == station) { watched = true; break; }
                if (!staleSince.TryGetValue(obj.NetworkObjectId, out float since)) staleSince[obj.NetworkObjectId] = since = Time.unscaledTime;
                if (!watched || Time.unscaledTime - since > 5f) stale.Add(obj);
            }
            foreach (var obj in stale) { staleSince.Remove(obj.NetworkObjectId); if (obj.IsSpawned) obj.Despawn(); }
        }
    }
}
