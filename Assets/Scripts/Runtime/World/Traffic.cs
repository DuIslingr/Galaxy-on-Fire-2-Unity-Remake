// Traffic.cs
// The orbit's NPC ships (Reference/research/npc_traffic_ai.md 2, 4, 7, 8), created by SpaceLevel:
//   Level::createMission / createShip   spawns TrafficPlan's ships (NpcShip)
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
    public class Traffic : MonoBehaviour
    {
        const float M = 0.05f;

        public readonly List<NpcShip> Ships = new List<NpcShip>();
        public Target Player { get; private set; }
        public int SystemRace { get; private set; }
        public int AttackRace { get; private set; }
        public int Security { get; private set; }
        public int StationIndex { get; private set; }
        public Vector3 StationPosition { get; private set; }
        /// <summary>Radar+0x1b8: hostile living ships (0 without a scanner).</summary>
        public int HostileCount { get; private set; }
        public event Action<string> Message;

        Database db;
        bool hasScanner, radioTurned, radioAlarm, blackMarket;
        float respawnMs, jumperMs;
        int raiderWaves, raidersRespawned;
        AudioSource music;
        int musicCategory = -1, pendingCategory = -1;
        float fade = 1f;
        CombatAssets assets;

        /// <summary>'storyOrbit': the orbit is built around a campaign mission (Level::init calls createCampaignMission
        /// instead of createMission), so no normal traffic; the campaign level spawns its ships with SpawnShip.</summary>
        public void Setup(Database database, OrbitLayout layout, Target player, GameObject station, bool storyOrbit = false, Wormhole wormhole = null)
        {
            db = database;
            Wormhole = wormhole;
            // Level::update: updateAlienAttackers in the alien orbit and at the station the Void attack; their music.
            VoidAttack = layout.alienOrbit || (!Session.FreePlay && Session.CampaignMission < 45 && layout.stationIndex == Session.VoidInvasionStation);
            Player = player;
            assets = CombatAssets.Load();
            StationIndex = layout.stationIndex;
            var sys = db.Systems.Find(s => s.index == layout.systemIndex);
            SystemRace = Mathf.Clamp(sys?.raceId ?? 0, 0, 3);
            AttackRace = Standing.EnemyRaceOf(SystemRace);
            Security = sys?.securityLevel ?? 0;
            blackMarket = layout.systemIndex == 25;
            hasScanner = Shop.FirstMounted(db, 17) != null;
            if (station != null) StationPosition = station.transform.position;

            fxRoot = new GameObject("NPC weapon fx").transform;
            fxRoot.SetParent(transform, false);
            IsStoryOrbit = storyOrbit;
            if (!storyOrbit)
                foreach (var spec in TrafficPlan.Build(db, StationIndex, sys, player != null ? new Vector3(player.transform.position.x, player.transform.position.y, -player.transform.position.z) / 0.05f : Vector3.zero,
                                                       wormhole != null && wormhole.Visible ? wormhole.GamePosition : (Vector3?)null)) Create(spec);
            AddCampaignStatics(layout);
            ConnectPlayers();
            wantedShip = Ships.Find(s => s.Spec.wantedIndex >= 0);
            convoyFreighter = Ships.Find(s => s.Spec.convoyRole == SpawnSpec.ConvoyFreighter);
            if (convoyFreighter != null)
            {
                ConvoyRoute = new Route(false);
                ConvoyRoute.points.Add(convoyFreighter.Spec.position);
            }
            Debug.Log($"Traffic: {Ships.Count} ships ({CountGroup(NpcGroup.Local)} local, {CountGroup(NpcGroup.Jumper)} jumpers, " +
                      $"{CountGroup(NpcGroup.Freighter)} freighters, {CountGroup(NpcGroup.Raider)} raiders)");

            music = gameObject.AddComponent<AudioSource>();
            music.loop = true;
            music.playOnAwake = false;
            music.spatialBlend = 0f;

            // MGame::OnUpdate hints 0x23 / 0x24 (npc_combat_specials.md 3.5): the first Nivelian system visit, then a later one.
            if (!storyOrbit && SystemRace == 2)
            {
                if (Session.Hints.Add(0x23)) Radio(443, 443, 2);
                else if (Session.Hints.Add(0x24)) Radio(444, 444, 2);
            }
            // Level::initParticleSystems: the red static fog around a pirate base's outpost.
            foreach (var s in Ships) if (s.Spec.group == NpcGroup.Outpost) SpawnRedFog(s.transform.position);

            // Level+0x18a: back at a station whose race the player attacked.
            if (Session.AttackedStations.Contains(StationIndex))
            {
                AlarmAllFriends(SystemRace, false);
                Radio(445, 447, SystemRace);
            }
        }

        int CountGroup(NpcGroup g) => Ships.FindAll(s => s.Spec.group == g).Count;

        Transform fxRoot;
        public bool IsStoryOrbit { get; private set; }
        /// <summary>The orbit's wormhole (landmark 3), null = none.</summary>
        public Wormhole Wormhole { get; private set; }
        /// <summary>The alien orbit or a station under Void attack: dead Void ships come back, Void music.</summary>
        public bool VoidAttack { get; private set; }
        float alienMs;

        NpcShip Create(SpawnSpec spec)
        {
            var prefab = spec.turretAssembly != null ? AssembledObject.LoadPrefab(db.AssemblyByName(spec.turretAssembly))
                       : spec.ship == 14 ? AssembledObject.LoadPrefab(db.AssemblyByName("battleship_terran"))
                       : spec.fixedObject != null ? AssembledObject.LoadPrefab(db.AssemblyByName(spec.fixedObject))
                       : spec.freighter ? AssembledObject.LoadPrefab(db.AssemblyByName(NpcTables.FreighterAssembly(spec.race)))
                                        : AssembledObject.LoadPrefab(ShipAssembly(spec.ship, spec.race));
            var go = new GameObject($"NPC {spec.group} {spec.race}/{spec.ship}");
            go.transform.SetParent(transform, false);
            var ship = go.AddComponent<NpcShip>();
            Ships.Add(ship);
            ship.Setup(this, db, spec, prefab, fxRoot);
            return ship;
        }

        /// <summary>Level::createWingmen 0xcb338: the hired wingmen next to the player (after every other ship). The model
        /// comes from a generator seeded with 5 x the name's length, so each wingman flies the same ship everywhere; 600
        /// hull at least; unarmed in a Challenge. Not at campaign 158.</summary>
        public void SpawnWingmen(Transform player, bool unarmed)
        {
            var names = Session.Wingmen;
            if (names == null || names.Count == 0 || player == null || Session.CampaignMission == 158) return;
            // Level::createWingmen: not in the supernova system (27) either, before campaign 0x9e.
            if (!Session.FreePlay && Session.CampaignMission < 0x9e && (db.Stations.Find(s => s.index == StationIndex)?.system ?? -1) == 27) return;
            int race = Session.WingmanRace;
            float[] right = { -1000f, 2000f, 0f };
            for (int i = 0; i < Mathf.Min(3, names.Count); i++)
            {
                var state = UnityEngine.Random.state;
                UnityEngine.Random.InitState(5 * names[i].Length);
                int ship = NpcTables.RandomFighter(race <= 3 ? race : Standing.Pirate);   // races 4-7: the pirate pool
                UnityEngine.Random.state = state;
                var pos = player.position + (player.right * right[i] - player.forward * 2000f + Vector3.up * (i == 2 ? 1000f : 0f)) * 0.05f;
                var spec = new SpawnSpec
                {
                    group = NpcGroup.Wingman, race = race, ship = ship, alwaysFriend = true, noLoot = true, name = names[i],
                    position = new Vector3(pos.x, pos.y, -pos.z) / 0.05f, hitpoints = Mathf.Max(600, NpcTables.Hull(0, ship)),
                };
                var s = Create(spec);
                s.transform.rotation = player.rotation;
                s.MakeWingman(i, !unarmed);
            }
            ConnectPlayers();
        }

        public List<NpcShip> LivingWingmen => Ships.FindAll(s => s.IsWingman && !s.Gone && s.Current == NpcShip.State.Fly);

        /// <summary>The wingman menu's command for every living wingman (MGame::OnTouchEnd, menu 2).</summary>
        public void CommandWingmen(int command, Target locked, Route playerRoute)
        {
            if (command == 0) Session.WingmanShowEmp = !Session.WingmanShowEmp;   // Status+0xf8
            foreach (var w in LivingWingmen) w.WingmanCommand(command, locked, playerRoute);
        }

        /// <summary>Level::createShip for a campaign level: one ship; call ConnectPlayers once all are spawned.</summary>
        public NpcShip SpawnShip(SpawnSpec spec) => Create(spec);

        /// <summary>Level::connectPlayers: each ship's enemy list is the player first, then every ship of another race.
        /// 'playerExempt': ships of these races leave the player out (campaign 16 / 24 / 28: the Void attack the others).</summary>
        public void ConnectPlayers(int playerExemptRace = -99)
        {
            foreach (var s in Ships)
            {
                s.enemies.Clear();
                if (Player != null && s.Race != playerExemptRace) s.enemies.Add(Player);
                foreach (var o in Ships) if (o != s && o.Race != s.Race) s.enemies.Add(o.Target);
            }
        }

        AssemblyData ShipAssembly(int ship, int race)
        {
            string raceName = race switch { 0 => "terran", 1 => "vossk", 2 => "nivelian", 3 => "midorian", 9 => "void", _ => "pirate" };
            return db.ShipAssembly(ship, raceName);
        }

        // ---- generic radio chatter (Level::createRadioMessage(kind, race) 0xd5568; combat_equipment.md 6) ------------

        /// <summary>One generic radio line: a random face of the race (ImageFactory::createChar) or the Pirate Boss (speaker 9).</summary>
        public class Chatter
        {
            public string text, speaker;
            public int[] portrait;      // a generic face, or null with speakerId
            public int speakerId = -1;  // a story speaker (9 Pirate Boss)
            public string voice;        // Globals::getDialogueSoundId (the story's radio calls)
        }

        /// <summary>A story speaker's line in the radio box (Level::createRadioMessage 0x13 / 0x1b), with its voice.</summary>
        public void QueueLine(int text, int speakerId, string voice = null)
        {
            chatterQueue.Enqueue(new Chatter { text = Localization.Get(text), speaker = StoryTable.SpeakerName(speakerId), speakerId = speakerId, voice = voice });
        }

        readonly Queue<Chatter> chatterQueue = new Queue<Chatter>();
        Chatter chatter;
        float chatterMs, chatterDurationMs;

        /// <summary>The generic line on screen (after the 2000 ms delay), null = none.</summary>
        public Chatter ChatterVisible => chatter != null && chatterMs >= 2000f ? chatter : null;

        /// <summary>Speaker image by race: 0 -> 64, 2 -> 65, 3 -> 21, 8 -> 9 (Pirate Boss), else 63; the name 1597 + image.</summary>
        void Radio(int firstText, int lastText, int race)
        {
            int image = race == 0 ? 64 : race == 2 ? 65 : race == 3 ? 21 : race == 8 ? 9 : 63;
            var c = new Chatter { text = Localization.Get(UnityEngine.Random.Range(firstText, lastText + 1)), speaker = Localization.Get(1597 + image) };
            if (image == 9) c.speakerId = 9;
            else c.portrait = AgentGenerator.CreatePortrait(UnityEngine.Random.value < 0.8f, race == 0 || race == 2 || race == 3 ? race : 1);
            chatterQueue.Enqueue(c);
        }

        /// <summary>Radio::update: hidden 2000 ms, then lines * 2000 + 1500 ms (world time).</summary>
        void UpdateChatter(float dtMs)
        {
            if (chatter != null)
            {
                chatterMs += dtMs;
                if (chatterMs >= 2000f + chatterDurationMs) chatter = null;
                return;
            }
            if (chatterQueue.Count == 0) return;
            chatter = chatterQueue.Dequeue();
            chatterMs = 0f;
            chatterDurationMs = Mathf.Max(1, Mathf.CeilToInt(chatter.text.Length / 55f)) * 2000f + 1500f;
        }

        bool baseWakeRadio, baseDestroyedRadio;
        int emergencyKills;

        /// <summary>A HUD message (Hud::hudEvent), e.g. "Signature invalid".</summary>
        public void Warn(string text) => Message?.Invoke(text);

        /// <summary>Level::pirateStationAction 0xd6338: a guard woke (radio 435-437, once per level) or the outpost died
        /// (the base destroyed, the reward pending, radio 438-440, once).</summary>
        public void PirateStationAction(bool guardWoke)
        {
            if (guardWoke)
            {
                if (baseWakeRadio) return;
                baseWakeRadio = true;
                Radio(435, 437, Standing.Pirate);
                return;
            }
            if (baseDestroyedRadio || PirateBases.IndexOf(StationIndex) < 0) return;
            baseDestroyedRadio = true;
            PirateBases.Destroyed(StationIndex);
            Radio(438, 440, Standing.Pirate);
        }

        /// <summary>SET_FOG_STATIC (space_props.md 4): 30 sprites of 32768 units within +-40000 of the outpost, colour
        /// 0xE2282880, forever, not tied to the camera.</summary>
        void SpawnRedFog(Vector3 at)
        {
            var go = new GameObject("Pirate base fog");
            go.transform.SetParent(transform, false);
            go.transform.position = at;
            var ps = go.AddComponent<ParticleSystem>();
            ps.Stop(true, ParticleSystemStopBehavior.StopEmittingAndClear);
            var main = ps.main;
            main.loop = false;
            main.playOnAwake = false;
            main.maxParticles = 30;
            main.startLifetime = float.PositiveInfinity;
            main.startSpeed = 0f;
            main.startSize = 32768f * 0.05f;
            main.startColor = new Color(0xE2 / 255f, 0x28 / 255f, 0x28 / 255f, 0x80 / 255f);
            main.simulationSpace = ParticleSystemSimulationSpace.World;
            main.cullingMode = ParticleSystemCullingMode.AlwaysSimulate;
            var emission = ps.emission;
            emission.enabled = false;
            var shape = ps.shape;
            shape.enabled = false;
            var r = go.GetComponent<ParticleSystemRenderer>();
            r.renderMode = ParticleSystemRenderMode.Billboard;
            r.maxParticleSize = 10f;
            r.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
            if (assets != null && assets.smokeMaterial != null) r.sharedMaterial = assets.smokeMaterial;
            var p = new ParticleSystem.EmitParams { applyShapeToPosition = false };
            for (int i = 0; i < 30; i++)
            {
                p.position = at + new Vector3(UnityEngine.Random.Range(-40000f, 40000f), UnityEngine.Random.Range(-40000f, 40000f), UnityEngine.Random.Range(-40000f, 40000f)) * 0.05f;
                p.rotation = UnityEngine.Random.Range(0f, 360f);
                ps.Emit(p, 1);
            }
        }

        /// <summary>The Terran battleship died: its turrets go with it.</summary>
        public void DestroyTurrets()
        {
            foreach (var s in Ships.ToArray()) s.DestroyAsTurret();
        }

        /// <summary>Level::friendTurnedEnemy: radio 0 once per level.</summary>
        public void FriendTurnedEnemy(int race)
        {
            if (radioTurned) return;
            radioTurned = true;
            Radio(426, 428, race);
        }

        /// <summary>Level::alarmAllFriends: every ship of 'race' turns hostile; radio 1 once; the station remembers it.</summary>
        public void AlarmAllFriends(int race, bool radio)
        {
            foreach (var s in Ships) if (s.Race == race) s.alwaysEnemy = true;
            if (radio && !radioAlarm)
            {
                radioAlarm = true;
                Radio(429, 431, race);
                if (race == SystemRace) Session.AttackedStations.Add(StationIndex);
            }
        }

        /// <summary>Level::enemyDied / friendDied bookkeeping and Standing::applyKill.</summary>
        /// <summary>Level::enemyDied / friendDied: a ship died, killed by the player or not (the campaign's kill counters).</summary>
        public event Action<NpcShip, bool> ShipDied;
        /// <summary>Level::stealFriendCargo (Level+0x13c): cargo was stolen from a friendly ship (Objective 0x13).</summary>
        public bool FriendCargoStolen { get; set; }

        public void OnShipDied(NpcShip ship, bool byPlayer)
        {
            ShipDied?.Invoke(ship, byPlayer);
            // Informer mission (PlayerFighter::update ~0xf1cb0): the spy dead -> Status+0xf0; the player shooting another
            // ship in its orbit -> Status+0xf1 (failed on the next docking).
            var fm = Session.FreelanceMission;
            if (fm != null && fm.type == MissionType.Informer && fm.target == StationIndex)
            {
                if (ship.Spec.nameText == 1663) Session.InformerKilled = true;
                else if (byPlayer && !Session.InformerKilled) Session.InformerFailed = true;
            }
            // PlayerFighter::update's death: a Most Wanted criminal pays its bounty whoever killed it; no standing hit.
            if (ship.Spec.wantedIndex >= 0) { WantedKilled(ship); if (byPlayer && ship.Target.hostileToPlayer) Session.Kills++; return; }
            if (!byPlayer || blackMarket) return;
            // Player::damage: the convoy freighter ("Arms delivery") destroyed by the Liberator (0xb3) -> step 59's bonus.
            if (ship.Spec.convoyRole == SpawnSpec.ConvoyFreighter && ship.Target.lastPlayerWeapon == 179 && Session.StoryMission != null)
                Session.StoryMission.value++;
            Standing.ApplyKill(ship.Race, SystemRace);
            if (ship.Target.hostileToPlayer)
            {
                if (PlayerHealth.EmergencyActive) Session.GraveRiserKills = Mathf.Max(Session.GraveRiserKills, ++emergencyKills);
                else emergencyKills = 0;
                Session.Kills++;
                if (ship.Race == Standing.Pirate) Session.PirateKills++;
            }
        }

        void Update()
        {
            float dtMs = Time.deltaTime * 1000f;
            UpdateOrbit(dtMs);
            UpdateAlienAttackers(dtMs);
            UpdateChatter(dtMs);
            UpdateConvoy();
            UpdateWanted();
            int hostiles = 0;
            if (hasScanner)
                foreach (var s in Ships)
                    // Radar::draw 0x156xxx: only active ships (Player::isActive) count, so a ship held back by its level
                    // script doesn't start the battle music or block fast-forward before it shows up.
                    if (!s.Gone && !s.Inactive && s.Current != NpcShip.State.Dying && s.Current != NpcShip.State.Dead && s.Target.Alive && s.Target.hostileToPlayer && !s.IsFreighter)
                        hostiles++;
            HostileCount = hostiles;
            UpdateMusic(Time.unscaledDeltaTime);
        }

        // ---- Level::createStaticObjects 0xcadb0 (campaign_levels_c.md 4, space_props.md 3) ------------------------------

        /// <summary>The Supernova's orbit objects in every level: the Mining Plant at Coromesk (103) for campaign > 0x54 (not
        /// at 0x87, whose level has its own), and at Var Lupra (112) for 0x80..0x91 the plasma array at (-50000, 0, 50000)
        /// facing the sun in its build stage (stage 5 with its glow at 0x91). Friendly, unkillable, never moving.</summary>
        void AddCampaignStatics(OrbitLayout layout)
        {
            if (Session.FreePlay || layout.alienOrbit) return;
            int cm = Session.CampaignMission;
            if (layout.stationIndex == 103 && cm > 0x54 && cm != 0x87) Create(MiningPlant());
            if (layout.stationIndex == 112 && cm >= 0x80 && cm <= 0x91) Create(PlasmaArray(layout, cm));
        }

        /// <summary>Level::createStaticObject 0x4a88: the Mining Plant (3210), docking type 1 (the titanium goes in here);
        /// getBoundingVolume 2000.</summary>
        public static SpawnSpec MiningPlant() => new SpawnSpec
        {
            group = NpcGroup.Special, race = 3, ship = -1, position = Vector3.zero, fixedObject = "sn_station_mining_plant", stationary = true,
            alwaysFriend = true, hitpoints = 9999999, noLoot = true, nameText = 3210, dockingType = ObjectDocking.DropOff, spacePoints = 1, hitRadius = 8000f,
            collisionId = 2000,
        };

        /// <summary>The plasma array (3207) in the build stage of campaign 'cm' (stages 1-5: from 0x80, 0x83, 0x87, 0x8a, 0x8e);
        /// getBoundingVolume 2001 for every stage (Level::createStaticObject 0x493e + 3k).</summary>
        public static SpawnSpec PlasmaArray(OrbitLayout layout, int cm)
        {
            int stage = cm < 0x83 ? 1 : cm < 0x87 ? 2 : cm < 0x8a ? 3 : cm < 0x8e ? 4 : 5;
            var sun = layout.lightDirection;
            float yaw = Mathf.Atan2(sun.x, sun.z);
            return new SpawnSpec
            {
                group = NpcGroup.Special, race = 3, ship = -1, position = new Vector3(-50000, 0, 50000), rotation = new Vector3(0, yaw, 0),
                fixedObject = $"sn_plasma_array_midorian_stage_00{stage}", stationary = true, alwaysFriend = true, hitpoints = 9999999, noLoot = true,
                nameText = 3207, hitRadius = 8000f, collisionId = 2001,
            };
        }

        /// <summary>PlayerEgo::update's hacking won at a hidden-blueprint wreck: Status::unlockBluePrint, the wreck's flag and
        /// loot cleared, docking type 0, Level::createRadioMessage(k + 0x15) (3156 + k, BLUEPRINT_RECOVERED_k), found for good.</summary>
        public void OnHackWon(NpcShip ship)
        {
            int k = ship != null ? ship.Spec.hiddenBlueprint : -1;
            if (k < 0 || k >= TrafficPlan.HiddenBlueprints.Length || (Session.HiddenBlueprintsFound & (1 << k)) != 0) return;
            Session.HiddenBlueprintsFound |= 1 << k;
            Blueprints.Unlock(TrafficPlan.HiddenBlueprints[k].blueprint);
            ship.DockingType = 0;
            QueueLine(3156 + k, 0, $"BLUEPRINT_RECOVERED_{k}");
        }

        // ---- the Most Wanted criminal (wingmen_wanted.md 2.6-2.7) -----------------------------------------------------

        NpcShip wantedShip;
        bool wantedUncovered, wantedAttacked, wantedSurrendered;
        int damageAfterSurrender;
        /// <summary>The player's radar ship lock (CombatRadar.Locked), set by the level: locking the criminal uncovers it.</summary>
        public Func<Target> LockedTarget;
        /// <summary>A bounty was paid (the reward message: 3206 + credits, sound 36).</summary>
        public event Action<int> BountyCollected;
        /// <summary>An uncovered criminal is alive (Radar::draw: music 151).</summary>
        public bool WantedUncovered => wantedShip != null && wantedShip.Target.Alive && wantedShip.alwaysEnemy;

        WantedData WantedOf(NpcShip s) => s != null && s.Spec.wantedIndex >= 0 && s.Spec.wantedIndex < db.Wanted.Count ? db.Wanted[s.Spec.wantedIndex] : null;

        void UpdateWanted()
        {
            if (wantedShip == null || !wantedShip.Target.Alive) return;
            // PlayerFighter::update ~0xf0f00: the radar lock on it uncovers it (a scanner is needed to lock ships).
            if (!wantedUncovered && !wantedShip.alwaysEnemy && !wantedSurrendered && LockedTarget != null && LockedTarget() == wantedShip.Target)
                UncoverWanted();
            // Player::damage -> Level::almostKillWanted: the storyline criminals give up at a third of their hull.
            var w = WantedOf(wantedShip);
            if (w != null && WantedBoard.IsStoryline(w.index) && !wantedSurrendered && wantedShip.Hp.hull < wantedShip.Hp.maxHull / 3)
            {
                wantedSurrendered = true;
                wantedShip.alwaysEnemy = false;
                wantedShip.turnedEnemy = false;
                wantedShip.alwaysFriend = true;
                wantedShip.shootingEnabled = false;
                damageAfterSurrender = 0;
                WantedBoard.OnSurrender(db, w.index, StationIndex);
            }
        }

        /// <summary>Level::uncoverWanted 0xd63ac: it and its escort turn on the player; the uncover line (or the storyline talk).</summary>
        void UncoverWanted()
        {
            wantedUncovered = true;
            TurnWantedHostile();
            var w = WantedOf(wantedShip);
            if (w == null) return;
            if (w.index == 0) { WantedLine(3134, -1, w); WantedLine(3135, w.index, w); }
            else if (w.index == 1) { WantedLine(3139, -1, w); WantedLine(3140, w.index, w); }
            else WantedLine(3141 + UnityEngine.Random.Range(0, 5), -1, w);
        }

        /// <summary>Level::attackWanted 0xd642c: the player's first hit (instead of the friendly-fire rules).</summary>
        public void AttackWanted(NpcShip s, int dmg)
        {
            if (s != wantedShip) return;
            if (wantedSurrendered)
            {
                // A surrendered criminal fights again when the player keeps shooting (above 5 % of its hull).
                damageAfterSurrender += dmg;
                if (damageAfterSurrender > s.Hp.maxHull / 20) { s.alwaysFriend = false; s.alwaysEnemy = true; s.shootingEnabled = true; }
                return;
            }
            if (wantedAttacked) return;
            wantedAttacked = true;
            TurnWantedHostile();
            var w = WantedOf(s);
            if (w == null) return;
            if (w.index == 0) { WantedLine(3132, w.index, w); WantedLine(3133, -1, w); }
            else if (w.index == 1) { WantedLine(3136, w.index, w); WantedLine(3137, -1, w); WantedLine(3138, w.index, w); }
            else if ((w.index | 4) == 6) WantedLine(3146 + UnityEngine.Random.Range(0, 5), w.index, w);   // only wanted 2 and 6 taunt
        }

        void TurnWantedHostile()
        {
            wantedShip.alwaysEnemy = true;
            foreach (var s in Ships)
                if (s.Spec.wantedEscortOf == wantedShip.Spec.wantedIndex && s.Target.Alive) { s.alwaysEnemy = true; s.turnedEnemy = true; }
        }

        void WantedKilled(NpcShip ship)
        {
            var w = WantedOf(ship);
            if (w == null) return;
            int reward = WantedBoard.OnKilled(db, w.index);
            if (reward > 0) BountyCollected?.Invoke(reward);
            WantedLine(3151 + UnityEngine.Random.Range(0, 5), -1, w);   // Level::killWanted: "a job well done"
        }

        /// <summary>Level::createRadioMessage(0x10 / 0x11 / 0x12): Keith (speaker 0) or the criminal (image 10000 + i: its face).</summary>
        void WantedLine(int text, int wantedSpeaker, WantedData w)
        {
            var c = new Chatter { text = Localization.Get(text) };
            if (wantedSpeaker < 0) { c.speakerId = 0; c.speaker = Localization.Get(1597); }
            else { c.portrait = w.portraitParts; c.speaker = w.name; }
            chatterQueue.Enqueue(c);
        }

        // ---- step 59's arms convoy (LevelScript::process, LevelScript+0xa9) ------------------------------------------

        NpcShip convoyFreighter;
        int convoyStep;
        /// <summary>The convoy point as the player's route (Level+0x108), null = none / done.</summary>
        public Route ConvoyRoute { get; private set; }
        /// <summary>The convoy freighter died: the player's route and autopilot are cleared.</summary>
        public event Action ConvoyDone;

        /// <summary>Step 0: the player within 50 000 of the freighter -> the freighter, its escorts and turrets always-enemy,
        /// radio 0xe. Then the freighter dead -> its turrets destroyed, this station done in Status+0x90 (-1), radio 0xf.</summary>
        void UpdateConvoy()
        {
            if (convoyFreighter == null || convoyStep >= 2 || Player == null) return;
            if (convoyStep == 0 && (convoyFreighter.transform.position - Player.transform.position).magnitude < 50000f * 0.05f)
            {
                foreach (var s in Ships) if (s.Spec.convoyRole > 0) s.alwaysEnemy = true;
                ConvoyRadio(0x88f, false);
                convoyStep = 1;
            }
            if (convoyFreighter.Target.Alive) return;
            foreach (var s in Ships) if (s.Spec.convoyRole == SpawnSpec.ConvoyTurret) s.DestroyAsTurret();
            for (int i = 0; i < Session.StoryTargets.Count; i++) if (Session.StoryTargets[i] == StationIndex) Session.StoryTargets[i] = -1;
            ConvoyRadio(0x88e, true);
            ConvoyRoute = null;
            ConvoyDone?.Invoke();
            convoyStep = 2;
        }

        /// <summary>Level::createRadioMessage(0xe / 0xf, system race): text 'baseText' - 2 per target station still to do
        /// (0xe: 2185 / 2187 / 2189 "too close" lines; 0xf: 2186 / 2188, none after the last one).</summary>
        void ConvoyRadio(int baseText, bool afterKill)
        {
            int text = baseText;
            foreach (int t in Session.StoryTargets) if (t >= 0) text -= 2;
            if (afterKill && (text < 0x889 || text > 0x88d)) return;
            Radio(text, text, SystemRace);
        }

        /// <summary>Level::updateOrbit: relaunches and raider waves (not in a campaign orbit).</summary>
        void UpdateOrbit(float dtMs)
        {
            if (IsStoryOrbit) return;
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
            var raiders = Ships.FindAll(s => s.Spec.group == NpcGroup.Raider);
            int deadRaiders = raiders.FindAll(s => s.Gone).Count;
            bool anyBack = false;
            foreach (var s in Ships)
            {
                if (!s.Gone) continue;
                if (s.Spec.group == NpcGroup.Local && s.Spec.wantedIndex < 0) { s.Revive(StationPosition); continue; }   // not the criminal
                if (s.Spec.group == NpcGroup.Raider && deadRaiders > 1 && raiderWaves < 2 && Player != null
                    && (s.Race == Standing.Void || Security == 0 || (Security == 1 && raidersRespawned <= 2)))
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

        /// <summary>Level::updateAlienAttackers 0xd5ce0: every 45 000 ms (10 000 at index 41) the dead Void ships come back, at
        /// the wormhole +-10 000 while it is open, else around the player (+-40 000, +-30 000, 40 000 ahead: the fixed z offset
        /// is assumed).</summary>
        void UpdateAlienAttackers(float dtMs)
        {
            if (!VoidAttack) return;
            alienMs += dtMs;
            if (alienMs < (Session.CampaignMission == 41 ? 10000f : 45000f)) return;
            alienMs = 0f;
            foreach (var s in Ships)
            {
                if (!s.Gone || s.Race != Standing.Void || s.IsWingman) continue;
                Vector3 at;
                float R(float r) => UnityEngine.Random.Range(-r, r);
                if (Wormhole != null && Wormhole.Visible) at = Wormhole.transform.position + new Vector3(R(10000f), R(10000f), R(10000f)) * M;
                else if (Player != null) at = Player.transform.position + new Vector3(R(40000f), R(30000f), -40000f) * M;
                else continue;
                s.Revive(at);
            }
        }

        /// <summary>A cutscene plays its own music (the prologue / rescue): the traffic music stays silent.</summary>
        public bool MusicMuted { get; set; }
        /// <summary>Radar::draw: no battle music (campaign index 16, the first Void contact).</summary>
        public bool NoBattleMusic { get; set; }

        /// <summary>Radar::draw music choice: switch (with a short fade) only when the category changes.</summary>
        /// <summary>Any active hostile Specter (race 10) in the orbit.</summary>
        bool SpectersHostile => Ships.Exists(s => s.Race == Standing.Specter && !s.Gone && !s.Inactive && s.Target.Alive && s.Target.hostileToPlayer);
        /// <summary>The supernova system (27) before campaign 0x9e: its own calm music (148).</summary>
        bool SupernovaCalm => !Session.FreePlay && Session.CampaignMission < 0x9e && (db.Stations.Find(s => s.index == StationIndex)?.system ?? -1) == 27;

        void UpdateMusic(float dt)
        {
            if (assets == null || music == null) return;
            if (MusicMuted) { if (music.isPlaying) music.Stop(); musicCategory = pendingCategory = -1; return; }
            int cat = HostileCount <= 0 || NoBattleMusic ? 0 : HostileCount <= 2 ? 1 : HostileCount <= 4 ? 2 : 3;
            // Radar::draw: an uncovered Most Wanted criminal -> 151; hostile Specters (race 10) -> 149 / 150.
            if (cat > 0 && WantedUncovered) cat = 4;
            else if (cat > 0 && SpectersHostile) cat = cat >= 3 ? 6 : 5;
            if (cat != musicCategory && cat != pendingCategory) pendingCategory = cat;
            if (pendingCategory >= 0)
            {
                fade = musicCategory < 0 ? 0f : Mathf.Max(0f, fade - dt / 1.5f);
                if (fade <= 0f)
                {
                    musicCategory = pendingCategory;
                    pendingCategory = -1;
                    // Globals::playMusicAndFadeOutCurrent: 146 HomeBase_NoCombat in the Kaamo Club's orbit.
                    var sn = SupernovaAssets.Load();
                    var clip = musicCategory == 0 ? (StationIndex == KaamoClub.Station && assets.homeBaseMusic != null ? assets.homeBaseMusic
                                                     : SupernovaCalm && sn != null && sn.gammaRayMusic != null ? sn.gammaRayMusic   // 148 the supernova
                                                     : assets.spaceMusic != null && assets.spaceMusic.Length == 4 ? assets.spaceMusic[SystemRace] : null)
                                 : musicCategory == 4 ? sn?.wantedMusic
                                 : musicCategory == 5 ? sn?.stealthMusic1
                                 : musicCategory == 6 ? sn?.stealthMusic2
                                 : (assets.battleMusic != null && assets.battleMusic.Length == 3 ? assets.battleMusic[musicCategory - 1] : null);
                    // Radar::draw: 145 Space_NoCombat_Void in the alien orbit, 136 Space_Combat_Void there and at an attacked station.
                    var story = StoryAssets.Load();
                    if (story != null && musicCategory == 0 && StationIndex == Session.VoidOrbit && story.voidMusic != null) clip = story.voidMusic;
                    if (story != null && musicCategory > 0 && VoidAttack && story.voidBattle != null) clip = story.voidBattle;
                    music.clip = clip;
                    if (clip != null) music.Play();
                }
            }
            else fade = Mathf.Min(1f, fade + dt / 1.5f);
            music.volume = fade * Settings.MusicVolume;
        }
    }
}
