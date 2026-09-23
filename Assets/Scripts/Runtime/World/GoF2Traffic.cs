// GoF2Traffic.cs
// The orbit's NPC ships (Reference/research/npc_traffic_ai.md 2, 4, 7, 8), created by GoF2SpaceLevel:
//   Level::createMission / createShip   spawns GoF2TrafficPlan's ships (GoF2NpcShip)
//   Level::connectPlayers 0xcc330       each NPC's enemy list: the player first, then every ship of another race (same-race
//                                       ships never target or hit each other)
//   Level::updateOrbit 0xd50b0          every 10 s one gone jumper relaunches from the station; every 45 s gone local
//                                       fighters relaunch from the station and a destroyed raider group comes back 60-120 km
//                                       from the player (at most 2 waves; security 0, or 3 ships in security 1)
//   Level::friendTurnedEnemy / alarmAllFriends   radio 0 "Hold your fire!" (426-428) once, radio 1 (429-431) once and
//                                       every ship of that race turns hostile; the station remembers it (next visit: at
//                                       least 7 local fighters, all hostile at once, radio 2 "He's back!" 445-447)
//   Level::enemyDied / Standing::applyKill   a player kill: kills +1 (hostile ships), pirate kills, standing -5 with the
//                                       race (a pirate: +1 toward the system race); not in the black-market system
//   Radar::draw hostile counter         hostile living ships (only with a scanner): blocks fast-forward and picks the music:
//                                       0 the system's space track, 1-2 / 3-4 / 5+ Space_Battle_Low / Medium / Full
// Radio messages are shown as HUD messages (the original's radio window with portraits isn't built yet).

using System;
using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.Visuals;
using UnityEngine;

namespace GoF2Remake.World
{
    public class GoF2Traffic : MonoBehaviour
    {
        const float M = 0.05f;

        public readonly List<GoF2NpcShip> Ships = new List<GoF2NpcShip>();
        public GoF2Target Player { get; private set; }
        public int SystemRace { get; private set; }
        public int AttackRace { get; private set; }
        public int Security { get; private set; }
        public int StationIndex { get; private set; }
        public Vector3 StationPosition { get; private set; }
        /// <summary>Radar+0x1b8: hostile living ships (0 without a scanner).</summary>
        public int HostileCount { get; private set; }
        public event Action<string> Message;

        GoF2Database db;
        bool hasScanner, radioTurned, radioAlarm, blackMarket;
        float respawnMs, jumperMs;
        int raiderWaves, raidersRespawned;
        AudioSource music;
        int musicCategory = -1, pendingCategory = -1;
        float fade = 1f;
        GoF2CombatAssets assets;

        public void Setup(GoF2Database database, GoF2OrbitLayout layout, GoF2Target player, GameObject station)
        {
            db = database;
            Player = player;
            assets = GoF2CombatAssets.Load();
            StationIndex = layout.stationIndex;
            var sys = db.Systems.Find(s => s.index == layout.systemIndex);
            SystemRace = Mathf.Clamp(sys?.raceId ?? 0, 0, 3);
            AttackRace = GoF2Standing.EnemyRaceOf(SystemRace);
            Security = sys?.securityLevel ?? 0;
            blackMarket = layout.systemIndex == 25;
            hasScanner = GoF2Shop.FirstMounted(db, 17) != null;
            if (station != null) StationPosition = station.transform.position;

            var fxRoot = new GameObject("NPC weapon fx").transform;
            fxRoot.SetParent(transform, false);
            foreach (var spec in GoF2TrafficPlan.Build(db, StationIndex, sys))
            {
                var prefab = spec.freighter ? GoF2AssembledObject.LoadPrefab(db.AssemblyByName(GoF2NpcTables.FreighterAssembly(spec.race)))
                                            : GoF2AssembledObject.LoadPrefab(ShipAssembly(spec.ship, spec.race));
                var go = new GameObject($"NPC {spec.group} {spec.race}/{spec.ship}");
                go.transform.SetParent(transform, false);
                var ship = go.AddComponent<GoF2NpcShip>();
                Ships.Add(ship);
                ship.Setup(this, db, spec, prefab, fxRoot);
            }
            // Level::connectPlayers.
            foreach (var s in Ships)
            {
                s.enemies.Clear();
                if (Player != null) s.enemies.Add(Player);
                foreach (var o in Ships) if (o != s && o.Race != s.Race) s.enemies.Add(o.Target);
            }
            Debug.Log($"GoF2Traffic: {Ships.Count} ships ({CountGroup(GoF2NpcGroup.Local)} local, {CountGroup(GoF2NpcGroup.Jumper)} jumpers, " +
                      $"{CountGroup(GoF2NpcGroup.Freighter)} freighters, {CountGroup(GoF2NpcGroup.Raider)} raiders)");

            music = gameObject.AddComponent<AudioSource>();
            music.loop = true;
            music.playOnAwake = false;
            music.spatialBlend = 0f;

            // Level+0x18a: back at a station whose race the player attacked.
            if (GoF2Session.AttackedStations.Contains(StationIndex))
            {
                AlarmAllFriends(SystemRace, false);
                Radio(445, 447);
            }
        }

        int CountGroup(GoF2NpcGroup g) => Ships.FindAll(s => s.Spec.group == g).Count;

        AssemblyData ShipAssembly(int ship, int race)
        {
            string prefix = $"ship_{ship:000}_";
            string raceName = race switch { 0 => "terran", 1 => "vossk", 2 => "nivelian", 3 => "midorian", 9 => "void", _ => "pirate" };
            return db.Assemblies.Find(a => a.category == "ships" && a.name.StartsWith(prefix) && a.name.EndsWith(raceName))
                   ?? db.Assemblies.Find(a => a.category == "ships" && a.name.StartsWith(prefix));
        }

        void Radio(int firstText, int lastText) => Message?.Invoke(GoF2Localization.Get(UnityEngine.Random.Range(firstText, lastText + 1)));

        /// <summary>Level::friendTurnedEnemy: radio 0 once per level.</summary>
        public void FriendTurnedEnemy(int race)
        {
            if (radioTurned) return;
            radioTurned = true;
            Radio(426, 428);
        }

        /// <summary>Level::alarmAllFriends: every ship of 'race' turns hostile; radio 1 once; the station remembers it.</summary>
        public void AlarmAllFriends(int race, bool radio)
        {
            foreach (var s in Ships) if (s.Race == race) s.alwaysEnemy = true;
            if (radio && !radioAlarm)
            {
                radioAlarm = true;
                Radio(429, 431);
                if (race == SystemRace) GoF2Session.AttackedStations.Add(StationIndex);
            }
        }

        /// <summary>Level::enemyDied / friendDied bookkeeping and Standing::applyKill.</summary>
        public void OnShipDied(GoF2NpcShip ship, bool byPlayer)
        {
            if (!byPlayer || blackMarket) return;
            GoF2Standing.ApplyKill(ship.Race, SystemRace);
            if (ship.Target.hostileToPlayer)
            {
                GoF2Session.Kills++;
                if (ship.Race == GoF2Standing.Pirate) GoF2Session.PirateKills++;
            }
        }

        void Update()
        {
            float dtMs = Time.deltaTime * 1000f;
            UpdateOrbit(dtMs);
            int hostiles = 0;
            if (hasScanner)
                foreach (var s in Ships)
                    if (!s.Gone && s.Current != GoF2NpcShip.State.Dying && s.Current != GoF2NpcShip.State.Dead && s.Target.Alive && s.Target.hostileToPlayer && !s.IsFreighter)
                        hostiles++;
            HostileCount = hostiles;
            UpdateMusic(Time.unscaledDeltaTime);
        }

        /// <summary>Level::updateOrbit: relaunches and raider waves.</summary>
        void UpdateOrbit(float dtMs)
        {
            jumperMs += dtMs;
            respawnMs += dtMs;
            if (jumperMs > 10000f)
            {
                jumperMs = 0f;
                var j = Ships.Find(s => s.IsJumper && s.Gone);
                if (j != null) j.Revive(StationPosition);
            }
            if (respawnMs < 45001f) return;
            respawnMs = 0f;
            var raiders = Ships.FindAll(s => s.Spec.group == GoF2NpcGroup.Raider);
            int deadRaiders = raiders.FindAll(s => s.Gone).Count;
            bool anyBack = false;
            foreach (var s in Ships)
            {
                if (!s.Gone) continue;
                if (s.Spec.group == GoF2NpcGroup.Local) { s.Revive(StationPosition); continue; }
                if (s.Spec.group == GoF2NpcGroup.Raider && deadRaiders > 1 && raiderWaves < 2 && Player != null
                    && (s.Race == GoF2Standing.Void || Security == 0 || (Security == 1 && raidersRespawned <= 2)))
                {
                    raidersRespawned++;
                    float Sign() => UnityEngine.Random.value < 0.5f ? -1f : 1f;
                    var off = new Vector3(Sign() * (60000 + UnityEngine.Random.Range(0, 60000)), Sign() * (5000 + UnityEngine.Random.Range(0, 5000)),
                                          Sign() * (60000 + UnityEngine.Random.Range(0, 60000))) * M;
                    s.Revive(Player.transform.position + off);
                    anyBack = true;
                }
            }
            if (anyBack) raiderWaves++;
        }

        /// <summary>Radar::draw music choice: switch (with a short fade) only when the category changes.</summary>
        void UpdateMusic(float dt)
        {
            if (assets == null || music == null) return;
            int cat = HostileCount <= 0 ? 0 : HostileCount <= 2 ? 1 : HostileCount <= 4 ? 2 : 3;
            if (cat != musicCategory && cat != pendingCategory) pendingCategory = cat;
            if (pendingCategory >= 0)
            {
                fade = musicCategory < 0 ? 0f : Mathf.Max(0f, fade - dt / 1.5f);
                if (fade <= 0f)
                {
                    musicCategory = pendingCategory;
                    pendingCategory = -1;
                    var clip = musicCategory == 0 ? (assets.spaceMusic != null && assets.spaceMusic.Length == 4 ? assets.spaceMusic[SystemRace] : null)
                                                  : (assets.battleMusic != null && assets.battleMusic.Length == 3 ? assets.battleMusic[musicCategory - 1] : null);
                    music.clip = clip;
                    if (clip != null) music.Play();
                }
            }
            else fade = Mathf.Min(1f, fade + dt / 1.5f);
            music.volume = fade * GoF2Settings.MusicVolume;
        }
    }
}
