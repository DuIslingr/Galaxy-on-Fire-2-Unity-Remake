// NetPlayer.cs
// One per player in a multiplayer session (NetGame spawns it as that player's player object when they connect; it lives
// in DontDestroyOnLoad, through all their scene changes). The owner writes where they are (the station, and in space /
// in the hangar / taking off from it, from the scene they are in) and, in space, their ship's pose and hull fraction
// (owner-written, sent at the tick rate), their ship, name and whether they run their orbit's NPCs (NetOrbit).
// Every other player in the same orbit sees the ship model there (player variant), smoothed (NetSmoothing), as:
//   a Target in Target.NetShips: lockable, the player's name (NetGame.PlayerName, else "Player N") on the lock plate; a
//     yellow (neutral) marker whose hits (guns, missiles, blasts) go to the owner's game, which applies them to its own ship
//     (players can destroy each other: a notice for everyone, the destroyed player respawns docked); a squadmate is a
//     green marker that the local player's weapons don't affect (Target.playerProof; NetSquad);
//   an Obstacle: a sphere around the model that the local ship slides along (PlayerCollision, camera shake, no damage),
//     sized to cover both ships (the local ship is tested as a point). Each player's own device pushes their own ship,
//     so two players bump off each other;
//   a shot mirror: the owner's shots (every gun and the turret, missiles homing on its lock, blasts) drawn here
//     (NetShotSender -> NetShotMirror); the hits stay the owner's (on NPC proxies through NetProxy).
// The ship looks and sounds like the owner's: its engine glow and exhaust (ShipExhaust) while their engine shows, bigger
// with their boost, the engine loop (3D), their cloak (NpcCloak's look, off the radar from 25 %, NPCs don't fire at it),
// and an EMP's lightning. EMP on a player (the remake's pick: players have no EMP pool) drains that much shield and
// shows the lightning for 1.5 s. The owner also shares their standings (Standing.*With), so the NPCs of an orbit another
// player runs treat them by their own standing.
// Elsewhere (another orbit, docked) all of it is hidden; the players docked at the same station see them in their hangar
// instead (NetHangar).

using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.Visuals;
using GoF2Remake.World;
using Unity.Collections;
using Unity.Netcode;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace GoF2Remake.Multiplayer
{
    public sealed class NetPlayer : NetworkBehaviour
    {
        public enum Place : byte { None = 0, Space = 1, Hangar = 2, Departing = 3 }

        /// <summary>The collision sphere per unit of the model's bounding radius (about both ships' size).</summary>
        const float CollisionScale = 1.6f;

        static readonly NetworkVariableReadPermission Read = NetworkVariableReadPermission.Everyone;
        static readonly NetworkVariableWritePermission Write = NetworkVariableWritePermission.Owner;

        readonly NetworkVariable<Vector3> position = new NetworkVariable<Vector3>(default, Read, Write);
        readonly NetworkVariable<Quaternion> rotation = new NetworkVariable<Quaternion>(Quaternion.identity, Read, Write);
        readonly NetworkVariable<int> ship = new NetworkVariable<int>(-1, Read, Write);
        readonly NetworkVariable<float> hull = new NetworkVariable<float>(1f, Read, Write);
        readonly NetworkVariable<float> shield = new NetworkVariable<float>(-1f, Read, Write);   // fractions, -1 = no such pool
        readonly NetworkVariable<float> armor = new NetworkVariable<float>(-1f, Read, Write);
        readonly NetworkVariable<FixedString128Bytes> pilot = new NetworkVariable<FixedString128Bytes>(default, Read, Write);
        readonly NetworkVariable<int> station = new NetworkVariable<int>(-1, Read, Write);
        readonly NetworkVariable<byte> place = new NetworkVariable<byte>((byte)Place.None, Read, Write);
        readonly NetworkVariable<bool> authority = new NetworkVariable<bool>(false, Read, Write);
        readonly NetworkVariable<int> squad = new NetworkVariable<int>(0);   // the host's (NetSquad), 0 = none
        readonly NetworkVariable<bool> engine = new NetworkVariable<bool>(true, Read, Write);   // the engine glow shows
        readonly NetworkVariable<float> boost = new NetworkVariable<float>(0f, Read, Write);    // 0..1 (FlightModel.BoostVisualPercent)
        readonly NetworkVariable<float> cloak = new NetworkVariable<float>(0f, Read, Write);    // 0..100
        readonly NetworkVariable<bool> empShock = new NetworkVariable<bool>(false, Read, Write);
        readonly NetworkVariable<int> standing0 = new NetworkVariable<int>(0, Read, Write);    // Session.Standing, the signature
        readonly NetworkVariable<int> standing1 = new NetworkVariable<int>(0, Read, Write);
        readonly NetworkVariable<int> signature = new NetworkVariable<int>(-1, Read, Write);

        /// <summary>Every player in the session, the local one included.</summary>
        public static readonly List<NetPlayer> All = new List<NetPlayer>();
        /// <summary>The local player's, null outside a session.</summary>
        public static NetPlayer Local { get; private set; }

        public int Station => station.Value;
        public Place Where => (Place)place.Value;
        public bool InSpace => Where == Place.Space;
        /// <summary>Docked (taking off included).</summary>
        public bool InHangar => Where == Place.Hangar || Where == Place.Departing;
        public bool OrbitAuthority => authority.Value;
        public int ShipIndex => ship.Value;
        public int SquadId => squad.Value;
        /// <summary>This player's standing axes and signature (their Session): Standing.IsEnemyWith / IsFriendWith.</summary>
        public int Standing0 => standing0.Value;
        public int Standing1 => standing1.Value;
        public int Signature => signature.Value;
        public float CloakPercent => cloak.Value;
        public float Hull => hull.Value;
        /// <summary>Shield / armor fractions, -1 = the ship has none.</summary>
        public float Shield => shield.Value;
        public float Armor => armor.Value;
        /// <summary>Host: into squad 'id' (0 = none).</summary>
        public void SetSquad(int id) { if (IsServer && squad.Value != id) squad.Value = id; }
        public string DisplayName
        {
            get
            {
                string n = NetGame.Clean(pilot.Value.ToString());
                return n.Length > 0 ? n : string.Format(Localization.Extra("mpPlayerName", "Player {0}"), OwnerClientId + 1);
            }
        }
        /// <summary>A remote player in the local player's orbit: their ship is shown here.</summary>
        public bool SharesOrbit => !IsOwner && Local != null && Local.InSpace && InSpace && Station == Local.Station;

        readonly NetSmoothing smoothing = new NetSmoothing();
        SpaceLevel level;
        StationLevel dock;
        Transform localShip;
        GameObject model;
        Target target;
        Obstacle obstacle;
        NetShotSender sender;
        NetShotMirror mirror;
        bool shown, joinNoticePending;
        ShipExhaust exhaust;
        World.NpcCloak cloakLook;
        AudioSource engineLoop;
        float engineVolume, empShockMs;
        EmpSparks sparks, ownSparks;
        AssembledObject asm;
        float spawnedAt;

        /// <summary>This player's ship as a Target here: the local player's own where it is theirs, else the proxy Target.</summary>
        public Target LocalTarget => IsOwner ? (level != null && level.Health != null ? level.Health.Target : null) : target;

        public override void OnNetworkSpawn()
        {
            DontDestroyOnLoad(gameObject);
            All.Add(this);
            name = $"NetPlayer {OwnerClientId}";
            if (IsOwner)
            {
                Local = this;
                spawnedAt = Time.unscaledTime;
                ship.Value = Session.ShipIndex;
                pilot.Value = NetGame.Clean(NetGame.PlayerName);
                sender = new NetShotSender(ShotRpc, BlastRpc, () => level != null && level.Weapons != null ? level.Weapons.LockTarget : null);
                SceneManager.sceneLoaded += OnSceneLoaded;
                FindLevel();
                return;
            }
            position.OnValueChanged += (_, p) => smoothing.Push(p);
            ship.OnValueChanged += (_, s) => BuildModel(s);
            smoothing.Push(position.Value);

            target = gameObject.AddComponent<Target>();
            target.isShip = true;
            target.customDeath = true;
            target.maxHp = 100f;
            target.RemoteDamage = (amount, hitVector, byNpc) => HitRpc(amount, hitVector, byNpc);
            target.RemoteEmp = emp => EmpRpc(emp);
            ApplyName();
            pilot.OnValueChanged += (_, _) => ApplyName();
            Target.NetShips.Add(target);
            obstacle = gameObject.AddComponent<Obstacle>();
            obstacle.projectFromVolume = false;
            mirror = new NetShotMirror(transform, () => target, ThroughSquad);
            BuildModel(ship.Value);
            SetShown(false);
            // The join notice: once their name is here, and not for the players already in the session when this one joined.
            joinNoticePending = Local != null && Time.unscaledTime - Local.spawnedAt > 3f;
            spawnedAt = Time.unscaledTime;
        }

        public override void OnNetworkDespawn()
        {
            All.Remove(this);
            if (Local == this) Local = null;
            else if (!IsOwner && NetGame.Active) NetChat.Notice(NetChat.LeftText(DisplayName));
            SceneManager.sceneLoaded -= OnSceneLoaded;
            if (target != null) Target.NetShips.Remove(target);
            sender?.Unhook();
            mirror?.Clear();
            cloakLook?.Dispose();
            sparks?.Clear();
            ownSparks?.Clear();
        }

        /// <summary>This player's shots pass through their squadmates (the local player's ship included).</summary>
        bool ThroughSquad(Target t)
        {
            if (SquadId == 0 || t == null) return false;
            var p = t.isPlayer ? Local : t.GetComponent<NetPlayer>();
            return p != null && p != this && NetSquad.Same(this, p);
        }

        void ApplyName()
        {
            target.displayName = DisplayName;
            name = $"NetPlayer {OwnerClientId} ({target.displayName})";
        }

        /// <summary>Another game's hit on this player's ship (a player's weapon, or an NPC that orbit's authority runs): this
        /// player's own ship takes it; destroyed by a player = a notice for everyone.</summary>
        [Rpc(SendTo.Owner)]
        void HitRpc(float amount, Vector3 hitVector, bool byNpc, RpcParams rpc = default)
        {
            var own = level != null && level.Health != null ? level.Health.Target : null;
            if (own == null) return;
            bool alive = own.Alive;
            own.Damage(amount, byNpc, hitVector);
            if (alive && !own.Alive && !byNpc && NetState.Instance != null) NetState.Instance.DestroyedByRpc(rpc.Receive.SenderClientId);
        }

        [Rpc(SendTo.NotOwner, Delivery = RpcDelivery.Unreliable)]
        void ShotRpc(int item, Vector3 position, Vector3 velocity, Vector3 up, float lifetimeMs, float homingDelayMs, ulong targetId)
        {
            if (shown) mirror?.Shot(item, position, velocity, up, lifetimeMs, homingDelayMs, NetShots.Resolve(targetId));
        }

        [Rpc(SendTo.NotOwner)]
        void BlastRpc(int item, Vector3 point)
        {
            if (shown) mirror?.Blast(item, point);
        }

        void BuildModel(int index)
        {
            if (model != null) Destroy(model);
            if (index < 0) return;
            var prefab = AssembledObject.LoadPrefab(Database.Load().ShipAssembly(index));
            if (prefab == null) return;
            model = Instantiate(prefab, transform, false);
            model.GetComponent<AssembledObject>()?.SetPlayerVariant(true);
            // The hit cube and the collision sphere from the model's size (its renderers' bounds, at the origin pose).
            var bounds = new Bounds(transform.position, Vector3.zero);
            foreach (var r in model.GetComponentsInChildren<Renderer>()) bounds.Encapsulate(r.bounds);
            float size = Mathf.Max(5f, bounds.extents.magnitude);
            if (target != null) target.radius = size * 0.7f;
            if (obstacle != null)
            {
                obstacle.volumes.Clear();
                obstacle.volumes.Add(CollisionVolume.Sphere(Vector3.zero, size * CollisionScale));
            }
            model.SetActive(shown);
            // Its look and sound: the exhaust, the cloak, the engine loop (3D, at space distances).
            asm = model.GetComponent<AssembledObject>();
            if (exhaust != null) Destroy(exhaust);
            exhaust = ShipExhaust.AttachRemote(gameObject, Database.Load(), model.transform, index, () => shown && engine.Value && cloak.Value < 25f,
                                               () => boost.Value, () => cloak.Value);
            cloakLook?.Dispose();
            cloakLook = new World.NpcCloak(model.transform);
            if (engineLoop != null) Destroy(engineLoop);
            engineLoop = World.HangarFlight.AddEngine(model, true, Database.Load(), index, out engineVolume);
            if (engineLoop != null) { engineLoop.minDistance = 100f; engineLoop.maxDistance = 4000f; }
        }

        /// <summary>Remote: the ship, its marker, lock and collision only in the local player's orbit.</summary>
        void SetShown(bool on)
        {
            shown = on;
            if (model != null) model.SetActive(on);
            if (target != null) { target.enabled = on; target.untargetable = !on; }
            if (obstacle != null) obstacle.enabled = on;
            if (!on) { mirror?.Clear(); sparks?.SetEmitting(false); if (engineLoop != null) engineLoop.Stop(); }
            else smoothing.Snap();
        }

        /// <summary>Remote, shown: the glow, the engine loop, the cloak and the EMP lightning from the owner's state.</summary>
        void ApplyLook(float dtMs)
        {
            bool cloaked = cloak.Value > 0f, hidden = cloak.Value >= 25f;
            asm?.SetExhaust(engine.Value && !hidden, true);
            cloakLook?.Show(cloak.Value, dtMs);
            if (target != null)
            {
                target.cloaked = cloaked;          // NPCs keep chasing but hold their fire (Target.cloaked)
                target.untargetable = hidden;      // off the radar and the lock from 25 %
            }
            if (engineLoop != null)
            {
                bool run = engine.Value && !hidden;
                engineLoop.volume = engineVolume;
                engineLoop.pitch = 1f + 0.12f * boost.Value;
                if (run && !engineLoop.isPlaying) engineLoop.Play();
                else if (!run && engineLoop.isPlaying) engineLoop.Stop();
            }
            if (empShock.Value && sparks == null) sparks = new EmpSparks(transform);
            sparks?.SetEmitting(empShock.Value);
        }

        /// <summary>Another game's EMP on this player's ship: players have no EMP pool, so it drains that much shield and
        /// shows the lightning for 1.5 s (a remake pick).</summary>
        [Rpc(SendTo.Owner)]
        void EmpRpc(int emp)
        {
            var hp = level != null && level.Health != null && level.Health.Target != null ? level.Health.Target.hitpoints : null;
            if (hp == null || !hp.Alive) return;
            hp.shield = Mathf.Max(0f, hp.shield - emp);
            empShockMs = 1500f;
        }

        void OnSceneLoaded(Scene scene, LoadSceneMode mode) => FindLevel();

        void WritePools(float s, float a)
        {
            if (Mathf.Abs(shield.Value - s) > 0.004f) shield.Value = s;
            if (Mathf.Abs(armor.Value - a) > 0.004f) armor.Value = a;
        }

        void FindLevel()
        {
            level = FindAnyObjectByType<SpaceLevel>();
            dock = level == null ? FindAnyObjectByType<StationLevel>() : null;
            localShip = null;
            ownSparks = null;   // went with the last level's ship
            sender?.Unhook();   // the last level's guns
        }

        void Update()
        {
            if (!IsSpawned) return;
            if (!IsOwner)
            {
                if (joinNoticePending && (pilot.Value.Length > 0 || Time.unscaledTime - spawnedAt > 2f))
                {
                    joinNoticePending = false;
                    NetChat.Notice(NetChat.JoinedText(DisplayName));
                }
                bool show = SharesOrbit;
                if (show != shown) SetShown(show);
                if (!shown) return;
                smoothing.Apply(transform, rotation.Value);
                ApplyLook(Time.deltaTime * 1000f);
                if (target != null)
                {
                    target.hp = hull.Value * target.maxHp;   // 0 = destroyed: no marker, no lock, no NPC after it
                    bool mate = NetSquad.Same(this, Local);   // squadmates: green, out of each other's line of fire
                    target.friendToPlayer = mate;
                    target.playerProof = mate;
                }
                mirror?.Update(Time.deltaTime * 1000f);
                return;
            }
            if (ship.Value != Session.ShipIndex) ship.Value = Session.ShipIndex;   // bought another
            if (standing0.Value != Session.Standing[0]) standing0.Value = Session.Standing[0];
            if (standing1.Value != Session.Standing[1]) standing1.Value = Session.Standing[1];
            int sig = Standing.SignatureRace;
            if (signature.Value != sig) signature.Value = sig;
            if (empShockMs > 0f) empShockMs -= Time.deltaTime * 1000f;
            bool shock = empShockMs > 0f;
            if (empShock.Value != shock) empShock.Value = shock;
            // Where the local player is: the scene they are in.
            Place now = level != null ? Place.Space : dock != null ? (dock.PlayerDeparting ? Place.Departing : Place.Hangar) : Place.None;
            int at = level != null && level.Layout != null ? level.Layout.stationIndex : dock != null && dock.Layout != null ? dock.Layout.stationIndex : -1;
            if (place.Value != (byte)now) place.Value = (byte)now;
            if (station.Value != at) station.Value = at;
            bool runs = level != null && level.NetAuthority;
            if (authority.Value != runs) authority.Value = runs;
            if (level == null)
            {
                // Docked: repaired (the pools' presence stays as last seen in space).
                if (dock != null) { if (hull.Value != 1f) hull.Value = 1f; WritePools(shield.Value < 0f ? -1f : 1f, armor.Value < 0f ? -1f : 1f); }
                return;
            }
            if (localShip == null)
            {
                if (level.Player == null) return;
                localShip = level.Player.transform;
            }
            if (level.Weapons != null) sender?.Hook(level.Weapons.Guns);
            if (level.Turret != null && level.Turret.Gun != null) sender?.Hook(new[] { level.Turret.Gun });
            transform.SetPositionAndRotation(localShip.position, localShip.rotation);
            if ((position.Value - localShip.position).sqrMagnitude > 0.0001f) position.Value = localShip.position;
            if (Quaternion.Angle(rotation.Value, localShip.rotation) > 0.05f) rotation.Value = localShip.rotation;
            var hp = level.Health != null && level.Health.Target != null ? level.Health.Target.hitpoints : null;
            float h = level.Health != null && level.Health.Target != null ? level.Health.Target.HullFraction : 1f;
            if (Mathf.Abs(hull.Value - h) > 0.004f) hull.Value = h;
            // The look the others see: the engine glow (off while mining, docking at an object, cloaked, dead), boost, cloak.
            var ownAsm = level.Player.visualModel != null ? level.Player.visualModel.GetComponent<AssembledObject>() : null;
            var glowPart = ownAsm != null && ownAsm.playerVariantParts != null && ownAsm.playerVariantParts.Length > 0 ? ownAsm.playerVariantParts[0] : null;
            bool glowOn = (glowPart == null || glowPart.activeInHierarchy) && (level.Health == null || !level.Health.Dead);
            if (engine.Value != glowOn) engine.Value = glowOn;
            float b = level.Player.Model != null ? level.Player.Model.BoostVisualPercent : 0f;
            if (Mathf.Abs(boost.Value - b) > 0.02f) boost.Value = b;
            float c = level.Cloak != null && level.Cloak.Rules != null ? level.Cloak.Rules.Percentage : 0f;
            if (Mathf.Abs(cloak.Value - c) > 0.5f || (c == 0f && cloak.Value != 0f)) cloak.Value = c;
            // The EMP lightning on the own ship too.
            if (shock && ownSparks == null) ownSparks = new EmpSparks(localShip);
            ownSparks?.SetEmitting(shock);
            WritePools(hp != null && hp.maxShield > 0 ? hp.shield / hp.maxShield : -1f, hp != null && hp.maxArmor > 0 ? (float)hp.armor / hp.maxArmor : -1f);
        }
    }
}
