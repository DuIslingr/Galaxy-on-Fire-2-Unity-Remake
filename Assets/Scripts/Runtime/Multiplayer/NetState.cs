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
//   squads (NetSquad): invitations, joining and leaving, a squad of one dissolved; the players' kill notices.

using System.Collections.Generic;
using GoF2Remake.Data;
using Unity.Netcode;
using UnityEngine;

namespace GoF2Remake.Multiplayer
{
    public sealed class NetState : NetworkBehaviour
    {
        const float SweepSeconds = 0.5f;

        readonly NetworkVariable<int> seed = new NetworkVariable<int>();
        readonly Dictionary<int, HashSet<int>> destroyed = new Dictionary<int, HashSet<int>>();
        GameObject proxyPrefab, cratePrefab;
        int pendingSeed;
        float sweepTimer;
        readonly Dictionary<ulong, float> staleSince = new Dictionary<ulong, float>();

        /// <summary>The session's world, null outside one.</summary>
        public static NetState Instance { get; private set; }

        /// <summary>Host, before spawning (written in OnNetworkSpawn, so it is in the clients' spawn data).</summary>
        public void SetSeed(int value) => pendingSeed = value;

        public override void OnNetworkSpawn()
        {
            name = "NetState";
            DontDestroyOnLoad(gameObject);
            Instance = this;
            if (IsServer)
            {
                seed.Value = pendingSeed;
                proxyPrefab = Resources.Load<GameObject>($"{NetGame.PrefabFolder}/NetProxy");
                cratePrefab = Resources.Load<GameObject>($"{NetGame.PrefabFolder}/NetCrate");
            }
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
        public void AsteroidDestroyedRpc(int station, int index)
        {
            if (!destroyed.TryGetValue(station, out var set)) destroyed[station] = set = new HashSet<int>();
            if (set.Add(index)) AsteroidGoneRpc(station, index);
        }

        [Rpc(SendTo.Everyone)]
        void AsteroidGoneRpc(int station, int index) => NetOrbit.Current?.OnAsteroidGone(station, index);

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
            NetPlayer sender = null;
            foreach (var p in NetPlayer.All) if (p != null && p.OwnerClientId == rpc.Receive.SenderClientId) { sender = p; break; }
            if (sender == null) return;
            ChatRpc(sender.OwnerClientId, sender.DisplayName, text, global, sender.Station, sender.InSpace, sender.InHangar);
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
            if (leader == null || joiner == null || leader == joiner) return;
            if (leader.SquadId == 0) leader.SetSquad(nextSquad++);
            joiner.SetSquad(leader.SquadId);
            DissolveSingles();
            SquadNoticeRpc(leader.SquadId, string.Format(Localization.Extra("mpSquadJoined", "{0} joined the squad."), joiner.DisplayName));
        }

        [Rpc(SendTo.Server)]
        public void LeaveSquadRpc(RpcParams rpc = default)
        {
            var p = NetSquad.Find(rpc.Receive.SenderClientId);
            if (p == null || p.SquadId == 0) return;
            int id = p.SquadId;
            p.SetSquad(0);
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
            NoticeRpc(string.Format(Localization.Extra("mpDestroyedBy", "{0} was destroyed by {1}."), victim.DisplayName, by.DisplayName));
        }

        [Rpc(SendTo.Everyone)]
        void NoticeRpc(string text) => NetChat.Notice(text);

        /// <summary>The host is closing the session: its reason, before the connection goes (NetGame.Shutdown).</summary>
        [Rpc(SendTo.NotServer)]
        public void SessionEndingRpc(string reason) => NetGame.OnHostEnding(reason);

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
            if (!IsServer || !IsSpawned) return;
            if ((sweepTimer -= Time.unscaledDeltaTime) > 0f) return;
            sweepTimer = SweepSeconds;
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
