// NetOrbit.cs
// Multiplayer: the local player's Space level in the shared world (SpaceLevel adds it while a session runs).
//   Asteroids: the field is built from the orbit's seed (SpaceLevel.SpawnNetworkAsteroids), the same for every player
//     there; on arrival the ones already destroyed this session are removed (NetState's list), and a destruction here
//     (shot, mined, rammed) or elsewhere in this orbit reaches everyone (by index in the field).
//   The orbit authority (the first player in an empty orbit, SpaceLevel.NetAuthority: only then is new traffic built) runs
//   the orbit's NPC traffic and shows it to the
//     others: one NetProxy per living ship (by its index in Traffic.Ships) and one NetCrate per crate, spawned for it by
//     the host and owned by this player; despawned when the ship is gone or the crate taken / expired. Leaving the orbit
//     takes them away: the player still there with the lowest client id takes the orbit over, rebuilding each flying ship
//     where it was (Traffic.Adopt, same model, race and hull); NetState keeps the old proxies a few seconds for that.

using System.Collections.Generic;
using GoF2Remake.Flight;
using GoF2Remake.World;
using UnityEngine;

namespace GoF2Remake.Multiplayer
{
    public sealed class NetOrbit : MonoBehaviour
    {
        const float ScanSeconds = 0.25f;

        /// <summary>The local player's orbit, null outside a multiplayer Space level.</summary>
        public static NetOrbit Current { get; private set; }

        SpaceLevel level;
        readonly List<Target> asteroids = new List<Target>();
        readonly HashSet<int> requestedShips = new HashSet<int>();
        readonly Dictionary<NpcShip, NetProxy> proxies = new Dictionary<NpcShip, NetProxy>();
        readonly Dictionary<int, Crate> crates = new Dictionary<int, Crate>();
        readonly Dictionary<Crate, NetCrate> netCrates = new Dictionary<Crate, NetCrate>();
        readonly Dictionary<Crate, int> crateIds = new Dictionary<Crate, int>();
        int nextCrateId;
        bool applyingRemote, requestedList;
        float scanTimer;

        public int Station => level != null && level.Layout != null ? level.Layout.stationIndex : -1;
        /// <summary>The orbit's system race (a remote kill's standing, Standing.ApplyKill).</summary>
        public int SystemRace => level != null && level.Traffic != null ? level.Traffic.SystemRace : -1;
        bool Authority => level != null && level.NetAuthority;

        public void Setup(SpaceLevel spaceLevel)
        {
            level = spaceLevel;
            Current = this;
            if (level.Asteroids == null) return;
            foreach (Transform t in level.Asteroids)
            {
                var target = t.GetComponent<Target>();
                int index = asteroids.Count;
                asteroids.Add(target);
                if (target != null) target.Died += _ => OnLocalAsteroidDied(index);
            }
        }

        void OnDestroy()
        {
            if (Current == this) Current = null;
            ClearNpcHooks();
        }

        // ---- the NPCs and the other players (the authority's NpcShip hooks) --------------------------------------

        readonly List<Target> remotePlayers = new List<Target>();

        void UpdateNpcHooks()
        {
            remotePlayers.Clear();
            foreach (var p in NetPlayer.All)
                if (p != null && p.SharesOrbit && p.LocalTarget != null && p.LocalTarget.Alive) remotePlayers.Add(p.LocalTarget);
            NpcShip.RemotePlayers = remotePlayers;
            NpcShip.HostileToRemote = HostileToRemote;
            NpcShip.HostileToLocalBySquad = HostileToLocalBySquad;
        }

        static void ClearNpcHooks()
        {
            NpcShip.RemotePlayers = null;
            NpcShip.HostileToRemote = null;
            NpcShip.HostileToLocalBySquad = null;
        }

        /// <summary>An always-hostile race (pirates, the Void, Specters), a race their own standing makes an enemy, a ship their
        /// squad turned on, or one hostile to the local player (this orbit's authority) while they are in its squad.</summary>
        static bool HostileToRemote(NpcShip ship, Target t)
        {
            var p = t != null ? t.GetComponent<NetPlayer>() : null;
            if (p == null) return false;
            int r = ship.Race;
            if (r == Standing.Pirate || r == Standing.Void || r == Standing.Specter) return true;
            if (Standing.IsEnemyWith(r, p.Standing0, p.Standing1, p.Signature)) return true;   // their own standing toward the race
            foreach (var id in ship.aggressors) if (NetSquad.SameClient(id, p)) return true;
            return ship.Target != null && ship.Target.hostileToPlayer && NetSquad.Same(p, NetPlayer.Local);
        }

        /// <summary>Another member of the local player's squad shot it.</summary>
        static bool HostileToLocalBySquad(NpcShip ship)
        {
            var me = NetPlayer.Local;
            if (me == null || me.SquadId == 0) return false;
            foreach (var id in ship.aggressors) if (id != me.OwnerClientId && NetSquad.SameClient(id, me)) return true;
            return false;
        }

        // ---- asteroids --------------------------------------------------------------------------------------

        void OnLocalAsteroidDied(int index)
        {
            if (applyingRemote || NetState.Instance == null || !NetState.Instance.IsSpawned) return;
            NetState.Instance.AsteroidDestroyedRpc(Station, index);
        }

        /// <summary>An asteroid of 'station' was destroyed by someone: gone here too (with its explosion).</summary>
        public void OnAsteroidGone(int station, int index)
        {
            if (station != Station || index < 0 || index >= asteroids.Count) return;
            var t = asteroids[index];
            if (t == null || !t.Alive || !t.isActiveAndEnabled) return;
            applyingRemote = true;
            t.Explode();
            applyingRemote = false;
        }

        /// <summary>Arriving: the asteroids destroyed here before, removed without a trace.</summary>
        public void OnDestroyedList(int station, int[] indices)
        {
            if (station != Station || indices == null) return;
            foreach (int i in indices)
                if (i >= 0 && i < asteroids.Count && asteroids[i] != null) asteroids[i].gameObject.SetActive(false);
        }

        // ---- the authority's ships and crates ---------------------------------------------------------------

        /// <summary>Ship 'localId' (its index in the traffic), null = none.</summary>
        public NpcShip Ship(int localId)
        {
            var ships = level != null && level.Traffic != null ? level.Traffic.Ships : null;
            return ships != null && localId >= 0 && localId < ships.Count ? ships[localId] : null;
        }

        public Crate Crate(int localId) => crates.TryGetValue(localId, out var c) ? c : null;

        public void Register(NetProxy proxy, NpcShip ship) => proxies[ship] = proxy;
        public void Register(NetCrate net, Crate crate) => netCrates[crate] = net;

        /// <summary>The proxy showing 'ship' to the others (for shot targets), null = none.</summary>
        public NetProxy ProxyOf(NpcShip ship) => ship != null && proxies.TryGetValue(ship, out var p) ? p : null;

        void Update()
        {
            var state = NetState.Instance;
            if (state == null || !state.IsSpawned) return;
            if (!requestedList) { requestedList = true; state.RequestDestroyedRpc(Station); }
            if (!Authority) { ClearNpcHooks(); TryTakeOver(); return; }
            UpdateNpcHooks();
            if ((scanTimer -= Time.unscaledDeltaTime) > 0f) return;
            scanTimer = ScanSeconds;
            ScanShips(state);
            ScanCrates(state);
        }

        /// <summary>Nobody runs this orbit any more (its authority left): the player here with the lowest id takes over
        /// the old authority's flying ships.</summary>
        void TryTakeOver()
        {
            var me = NetPlayer.Local;
            if (me == null || !me.InSpace || me.Station != Station || !NetState.IsOrbitAuthority(Station)) return;
            foreach (var p in NetPlayer.All)
                if (p != null && p != me && p.IsSpawned && p.InSpace && p.Station == Station && p.OwnerClientId < me.OwnerClientId) return;
            var proxies = FindObjectsByType<NetProxy>(FindObjectsSortMode.None);
            bool any = false;
            foreach (var proxy in proxies)
                if (proxy.IsSpawned && (!proxy.IsOwner || proxy.Orphan) && proxy.Station == Station) { any = true; break; }
            if (!any && level.Traffic != null && level.Traffic.Ships.Count == 0 && Time.timeSinceLevelLoad < 3f) return;   // wait for them to arrive
            level.TakeOverNetAuthority();
            if (level.Traffic == null) return;
            foreach (var proxy in proxies)
            {
                if (!proxy.IsSpawned || proxy.Station != Station || !proxy.Adoptable) continue;
                var u = proxy.WorldPosition;
                var ship = level.Traffic.Adopt(proxy.AdoptSpec(new Vector3(u.x, u.y, -u.z) / OrbitLayout.MetersPerUnit), proxy.WorldRotation, proxy.HullFraction);
                foreach (var id in proxy.Aggressors) ship.aggressors.Add(id);   // still hostile to whom it was
                proxy.MarkAdopted();
            }
        }

        void ScanShips(NetState state)
        {
            var ships = level.Traffic != null ? level.Traffic.Ships : null;
            if (ships == null) return;
            for (int i = 0; i < ships.Count; i++)
            {
                var ship = ships[i];
                bool alive = ship != null && !ship.Gone && !string.IsNullOrEmpty(ship.ModelPath);
                if (alive && requestedShips.Add(i)) state.SpawnProxyRpc(Station, i);
                if (alive || !requestedShips.Contains(i)) continue;
                // Gone (dead after its explosion, jumped out): its proxy goes; a relaunch asks for a new one.
                if (ship != null && proxies.TryGetValue(ship, out var proxy))
                {
                    if (proxy != null && proxy.IsSpawned) state.DespawnRpc(proxy.NetworkObjectId);
                    proxies.Remove(ship);
                    requestedShips.Remove(i);
                }
            }
        }

        void ScanCrates(NetState state)
        {
            foreach (var crate in FindObjectsByType<Crate>(FindObjectsInactive.Exclude))
            {
                if (crate.remote || crateIds.ContainsKey(crate)) continue;
                int id = nextCrateId++;
                crateIds[crate] = id;
                crates[id] = crate;
                state.SpawnCrateRpc(Station, id);
            }
            List<Crate> gone = null;
            foreach (var pair in crateIds) if (pair.Key == null) (gone ??= new List<Crate>()).Add(pair.Key);
            if (gone == null) return;
            foreach (var crate in gone)
            {
                crates.Remove(crateIds[crate]);
                crateIds.Remove(crate);
                if (netCrates.TryGetValue(crate, out var net))
                {
                    if (net != null && net.IsSpawned) state.DespawnRpc(net.NetworkObjectId);
                    netCrates.Remove(crate);
                }
            }
        }
    }
}
