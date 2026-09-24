// SpaceLevel.cs
// Builds the flight level for the current station orbit at startup, like Level::init 0xbb49c (two passes) and
// MGame::reset 0x1a793c: one level = one station orbit; the other stations of the system only appear as planets.
// The world itself (sky, lights, station, jumpgate, asteroids, dust, sun/planets) comes from OrbitBuilder,
// which the main menu background uses too. This adds the flight parts:
//   createPlayer:  player ship at (10, 10, 10000) facing away from the station (+-8.8 deg), speed 2 u/ms
//   MGame::reset:  camera fov 1.22 rad, near 20, far 300000 units; chase offsets (0, 600, -1338) / (0, 600, -650)
//   MGame::dockEvent 0x1afebc: docking switches straight to the station module (no animation). The original needs the
//                  autopilot aimed at the station plus a collision or |pos| < 16000; here the HUD offers "Dock" inside
//                  16000 units once the player has flown out of that range after spawning (no autopilot yet).
//   LevelScript 0x15e650 / process 0x160d50: after launching from the station a fixed camera 9000 units ahead of the
//                  ship (+-500..2499 sideways and up) watches it fly past for 7 s, then the chase camera takes over.
//   Level::init arrival by travel (planet jump, Navigation): 4x the previous station's planet billboard (about 80000
//                  units out) or the hidden jumpgate in the gate orbit, facing the station, with the travel launch camera.
//   Navigation: station / jumpgate / planet locks, autopilot (docks at the station), planet jump, fast-forward.
//   SystemJump: the jumpgate (star map, jump scene) and the Khador Drive. Arrival from another system: the hidden gate
//                  in the gate orbit, else (0, 0, 100000); the arrival camera then shows the orbit information.
//   LevelScript::process 0x160d50: at the end of the launch / arrival camera the autopilot continues to a programmed
//                  station (Navigation.ContinueToProgrammedStation), unless the Khador Drive is about to charge.
//   Level::createMission etc.: the NPC traffic (Traffic) and ship combat: the player's pools and death
//                  (PlayerHealth), ship / salvage locks (CombatRadar); invulnerable during the launch / arrival
//                  camera and the jump scenes.
//   PlayerEgo::calcCollision: the ship slides along the station, the visible jumpgate and freighters (Obstacle,
//                  PlayerCollision), touching an asteroid destroys it; off during the launch / arrival camera and the
//                  jump scenes. MGame::dockEvent: the autopilot to the station also docks on touching the station.
//   Story (StorySpace, CampaignLevel): an orbit built around a campaign mission (Story.IsLevelMission) gets
//                  the campaign level instead of normal traffic; briefings, success / failure, the add-on entry calls. On a
//                  story mission the station refuses docking and the planet jumps / Khador Drive are blocked (525).
//   Wormhole (landmark 3): exists until the game is won, visible when coming out of the Void, at the station the Void
//                  attack or in the alien orbit (Session.VoidOrbit, the Void's home: its station, sky 010, Void asteroids);
//                  arriving from the Void it closes behind the player (LevelScript::LevelScript: player - dir * 10000,
//                  reset(true)). MGame::OnUpdate, the player inside it: an active campaign mission advances first (index
//                  < 41, not 29 / 40; 40 only once Errkt's freighter went through, carrying its hull into 41), entering too
//                  early at 29 / 40 / 41 kills the player, 42 in the alien orbit is the level script's; then the ride:
//                  into the alien orbit (remembering this station, Status+0x84) or back out to that station.

using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.Visuals;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.Controls;
using UnityEngine.SceneManagement;

namespace GoF2Remake.World
{
    [DefaultExecutionOrder(-100)]
    public class SpaceLevel : MonoBehaviour
    {
        const float M = OrbitLayout.MetersPerUnit;

        [Header("Scene")]
        public Camera mainCamera;
        public Light sunLight;
        public Light planetLight;

        [Header("Orbit (-1 = Session)")]
        public int stationOverride = -1;
        public string stationScene = "Station";

        [Header("Tuning (not recovered constants)")]
        [Tooltip("URP intensity for the original's LIGHT0 diffuse of 2.0 (clamp(15 * sunColour, 0, 2)).")]
        public float sunIntensityAt2 = 1.6f;
        public float planetLightIntensity = 1f;
        public float ambientIntensity = 1f;

        public OrbitLayout Layout { get; private set; }
        public ShipController Player { get; private set; }
        public WeaponSystem Weapons { get; private set; }
        public Mining Mining { get; private set; }
        public Navigation Navigation { get; private set; }
        public SystemJump SystemJump { get; private set; }
        public PlayerHealth Health { get; private set; }
        public Traffic Traffic { get; private set; }
        public CombatRadar Radar { get; private set; }
        public PlayerCollision Collision { get; private set; }
        public StorySpace StorySpace { get; private set; }
        /// <summary>The campaign level of a story orbit, null in a normal orbit.</summary>
        public CampaignLevel Campaign { get; private set; }
        /// <summary>The freelance mission's orbit (FreelanceOrbit), null = none.</summary>
        public FreelanceOrbit FreelanceOrbit { get; private set; }
        /// <summary>The Kaamo Club's pirate siege (station 108 before it's freed), null elsewhere.</summary>
        public KaamoSiege Siege { get; private set; }
        /// <summary>The player's turret (null without a turret item / mount).</summary>
        public PlayerTurret Turret { get; private set; }
        public PlayerCloak Cloak { get; private set; }
        public TimeExtender Extender { get; private set; }
        /// <summary>MGame::dockEvent: 525 while a mission holds the player here (the story's blocks, the Kaamo siege).</summary>
        public bool DockingBlocked => Story.BlocksDocking(Layout.stationIndex) || (Siege != null && Siege.Active);
        /// <summary>A story conversation is open (the game is paused).</summary>
        public bool Dialogue => StorySpace != null && StorySpace.DialogueOpen;
        /// <summary>LevelScript startSequenceOver: the launch / arrival camera has ended (in the prologue / rescue the
        /// cutscene script decides).</summary>
        public bool StartSequenceOver => launchCameraMs <= 0f && (Campaign == null || Campaign.StartSequenceOver);
        public bool LaunchCameraOver => launchCameraMs <= 0f;
        /// <summary>A LevelScript cutscene owns the camera (MGame+0x5f): no HUD, no player control.</summary>
        public bool Cutscene => Campaign != null && Campaign.Cutscene;
        public Transform Asteroids { get; private set; }
        public Backdrop Backdrop { get; private set; }
        public GameObject Station { get; private set; }
        public GameObject Jumpgate { get; private set; }
        /// <summary>Landmark 3 (PlayerWormHole), null once the game is won.</summary>
        public Wormhole Wormhole { get; private set; }
        /// <summary>Hud::drawOrbitInformation: during the arrival camera after a gate / Khador jump.</summary>
        public bool OrbitInfoVisible => orbitInfo && launchCameraMs > 0f;
        /// <summary>This orbit's station (name, tech level) and its system's jumpgate station (-1 = none).</summary>
        public StationData StationInfo { get; private set; }
        public int SystemJumpgateStation { get; private set; } = -1;

        /// <summary>PlayerEgo::collidesWithStation / calcCollision 0xab550: |pos| &lt; 16000 units.</summary>
        public const float DockRange = 16000f;
        const float LaunchCameraMs = 7000f;

        /// <summary>The HUD's "Dock" prompt: an orbit with a station, player inside the dock range, not during the launch
        /// camera, and only after having left the range once (the undock spawn at 10000 units is inside it).</summary>
        public bool CanDock => Layout.hasStation && Player != null && launchCameraMs <= 0f && leftDockRange && InDockRange && (Health == null || !Health.Dead)
                               && !DockingBlocked
                               && (Mining == null || Mining.State == Mining.Phase.Idle);
        bool InDockRange => Player.transform.position.sqrMagnitude < DockRange * M * DockRange * M;

        Database db;
        public Database Database => db;
        ChaseCamera chase;
        float launchCameraMs;
        bool leftDockRange, orbitInfo;

        void OnEnable() => Settings.Changed += ApplyOptions;
        void OnDisable() => Settings.Changed -= ApplyOptions;

        /// <summary>Options changed in flight (the pause menu) reach the ship and the chase camera at once.</summary>
        void ApplyOptions()
        {
            if (Player != null) { Player.sensitivity = Settings.Sensitivity; Player.invertPitch = Settings.InvertPitch; }
            if (chase != null) chase.baseFov = Settings.FieldOfView;
        }

        void Awake()
        {
            db = Database.Load();
            int station = stationOverride >= 0 ? stationOverride : Session.StationIndex;
            ComingFromVoid = Session.ComingFromVoid;
            // Status::departStation: the Void-invasion re-roll counter (index 32-44).
            Story.OnDepart(db, station);
            Layout = OrbitLayout.Build(db, station);
            var st = db.Stations.Find(s => s.index == station);
            StationInfo = st;
            SystemJumpgateStation = db.Systems.Find(s => s.index == Layout.systemIndex)?.jumpgateStation ?? -1;
            Debug.Log($"SpaceLevel: station {station} {st?.name} (system {Layout.systemIndex} {st?.systemName}), " +
                      $"gate {Layout.hasJumpgate}, {Layout.asteroidCount} asteroids");

            OrbitBuilder.SetupSky(Layout, ambientIntensity);
            OrbitBuilder.SetupLights(Layout, sunLight, planetLight, sunIntensityAt2, planetLightIntensity);
            SetupCamera();
            // Status::inEmptyOrbit: Var Hastra (78) has no station while the index is 0 or 1 (the prologue and the rescue);
            // Level::init: the prologue's asteroid belt is centred on the origin, under its own sky (Level::createSpace).
            bool prologue = station == 78 && !Session.FreePlay && Story.Index <= 1;
            if (prologue) Layout.hasStation = false;
            if (prologue && Story.Index == 0) Layout.asteroidCentre = Vector3.zero;
            Station = OrbitBuilder.SpawnStation(db, Layout);
            Jumpgate = OrbitBuilder.SpawnJumpgate(db, Layout);
            SpawnWormhole();
            AddObstacles();
            Asteroids = OrbitBuilder.SpawnAsteroids(db, Layout);
            if (prologue && Story.Index == 0)
            {
                var story = StoryAssets.Load();
                if (story != null && story.introSky != null) { RenderSettings.skybox = story.introSky; DynamicGI.UpdateEnvironment(); }
            }
            orbitInfo = Session.ArrivedBySystemJump;
            Session.ArrivedBySystemJump = false;
            SpawnPlayer();
            PlaceArrivalWormhole();
            OrbitBuilder.SpawnDust(Layout);
            var backdrop = OrbitBuilder.SpawnBackdrop(Layout, mainCamera);
            SkyLayers.Spawn(Layout, mainCamera);   // ring sky, storms, supernova flares, asteroid belt
            Backdrop = backdrop;

            // Locks on the station, the jumpgate and the other stations' planets; autopilot, planet jump, fast-forward.
            Navigation = Player.gameObject.AddComponent<Navigation>();
            Navigation.Setup(db, Layout, backdrop, Player, Mining, chase, Weapons);
            Mining.navigation = Navigation;
            SystemJump = Player.gameObject.AddComponent<SystemJump>();
            SystemJump.Setup(db, Navigation, Player, Weapons, chase, Jumpgate);

            // Ship combat: the player's Player object, the orbit's NPC traffic, the ship / salvage locks.
            Health = Player.gameObject.AddComponent<PlayerHealth>();
            Health.Setup(db, Player, chase, Weapons);
            Collision = Player.gameObject.AddComponent<PlayerCollision>();
            Collision.Setup(Health, chase, Mining);
            Collision.wormhole = Wormhole;
            bool storyOrbit = !Session.FreePlay && Story.IsLevelMission(station);
            // Status::departStation: the freelance mission's target orbit is built around it (not over a story orbit).
            bool freelanceOrbit = !storyOrbit && Freelance.IsMissionOrbit(station);
            // Level::createMission: the Kaamo Club under siege (kaamo_club.md 3).
            bool siege = !storyOrbit && !freelanceOrbit && KaamoClub.SiegeAt(station);
            Traffic = new GameObject("Traffic").AddComponent<Traffic>();
            Traffic.Setup(db, Layout, Health.Target, Station, storyOrbit || freelanceOrbit || siege, Wormhole);
            if (storyOrbit)
            {
                Campaign = new GameObject("Campaign").AddComponent<CampaignLevel>();
                Campaign.Setup(this, Traffic);
                Navigation.SetRoute(Campaign.PlayerRoute);
            }
            else if (freelanceOrbit)
            {
                FreelanceOrbit = new GameObject("FreelanceOrbit mission").AddComponent<FreelanceOrbit>();
                FreelanceOrbit.Setup(this, Traffic);
                Navigation.SetRoute(FreelanceOrbit.PlayerRoute);
            }
            else if (siege)
            {
                Siege = new GameObject("Kaamo siege").AddComponent<KaamoSiege>();
                Siege.Setup(this, Traffic);
            }
            // Step 59's arms convoy: its point is the player's route until the freighter is gone.
            if (Traffic.ConvoyRoute != null)
            {
                Navigation.SetRoute(Traffic.ConvoyRoute);
                Traffic.ConvoyDone += () => { Navigation.SetAutopilot(null); Navigation.SetRoute(null); };
            }
            // Level::createWingmen: after the mission's ships (Challenge: unarmed).
            Traffic.SpawnWingmen(Player.transform, FreelanceOrbit != null && FreelanceOrbit.Type == MissionType.Challenge);
            Navigation.HasWingmen = () => Traffic != null && Traffic.LivingWingmen.Count > 0;
            StorySpace = gameObject.AddComponent<StorySpace>();
            StorySpace.Setup(this, Campaign);
            Navigation.JumpsBlocked = () => !Story.PlanetJumpsAllowed || Story.BlocksJumps(Layout.stationIndex) || (Siege != null && Siege.Active)
                                            || (!Session.FreePlay && Story.Index == 65 && Layout.stationIndex == 100)   // escorting Khador (MGame::UseKhadorDrive)
                                            // remake: no Khador Drive out of the Void in the main story (its wormhole is the way back)
                                            || (Layout.alienOrbit && !Story.GameWon && Story.ForcedKhadorTarget(Layout.stationIndex) == null);
            Navigation.SetWormhole(Wormhole);
            Navigation.PlanetJumpRefused = st => StorySpace != null && StorySpace.RefusePlanetJump(st);
            SystemJump.GateBlocked = () => Siege != null && Siege.Active;
            Radar = Player.gameObject.AddComponent<CombatRadar>();
            Radar.Setup(db, Player, Navigation, Mining, Weapons, Health, Traffic);
            // Equipment (combat_equipment.md): the cloak (autopilot menu entry), the time extender, the repair / transfusion beams.
            Cloak = PlayerCloak.Attach(Player.gameObject, db, Session.ShipIndex, Health.Target, Player.visualModel);
            Navigation.Cloak = Cloak;
            Navigation.Extender = Extender;
            if (Extender != null) Extender.Blocked = () => ExtenderBlocked;
            RepairBeam.AttachAll(Player.gameObject, db, Health.Target, Traffic);
            Session.ComingFromVoid = false;   // Level::init / LevelScript have used it (the Void raid, the closing wormhole)
        }

        /// <summary>Level::comingFromAlienWorld for this level (the session flag is cleared once the level is built).</summary>
        public bool ComingFromVoid { get; private set; }

        /// <summary>A cinematic, a jump, the launch camera or the player's death stops the time extender (MGame::OnUpdate 0x1af162).</summary>
        bool ExtenderBlocked => launchCameraMs > 0f || Navigation.Jumping || (SystemJump != null && SystemJump.Cinematic) || Cutscene
                                || Health == null || Health.Dead;

        void Update()
        {
            // MGame::OnUpdate: the wingmen's contract runs down while flying (fast-forward included, not while paused).
            if (Session.Wingmen.Count > 0 && Session.WingmanContractMs > 0f) Session.WingmanContractMs = Mathf.Max(0f, Session.WingmanContractMs - Time.deltaTime * 1000f);
            if (Health == null) return;
            Health.invulnerable = launchCameraMs > 0f || Navigation.Jumping || (SystemJump != null && SystemJump.Cinematic)
                                  || (Campaign != null && Campaign.PlayerInvulnerable);
            Collision.off = launchCameraMs > 0f || Navigation.Jumping || (SystemJump != null && SystemJump.Cinematic)
                            || (Campaign != null && Campaign.CollisionOff);   // PlayerEgo+0x144
            Collision.ignoreGate = Navigation.GoingToGate;
            // Hostiles, or a radio line on screen, block fast-forward (MGame::OnUpdate).
            Navigation.HostilesPresent = (Traffic != null && (Traffic.HostileCount > 0 || Traffic.ChatterVisible != null)) || (Campaign != null && Campaign.Radio != null && Campaign.Radio.Busy);
            if (Extender != null && ExtenderBlocked) Extender.Cancel();
            UpdateWormholeRide();
        }

        // ---- the wormhole (landmark 3) -----------------------------------------------------------------------

        /// <summary>Level::createSpace: landmark 3 while the game isn't won, at a random spot (time-seeded).</summary>
        void SpawnWormhole()
        {
            if (Session.FreePlay || Story.GameWon) return;
            bool attacked = Layout.stationIndex == Session.VoidInvasionStation;
            bool visible = (ComingFromVoid || attacked || Layout.alienOrbit) && Story.Index < 43;
            var pos = new Vector3(Random.Range(0, 80000) - 40000, Random.Range(0, 40000) - 20000, Random.Range(0, 40000) + 40000);
            Wormhole = Wormhole.Spawn(StoryAssets.Load(), pos, visible);
            Wormhole.alienOrbit = Layout.alienOrbit;
            Wormhole.attackedStation = attacked;
        }

        /// <summary>LevelScript::LevelScript 0x16056c: coming out of the Void (or in the alien orbit) the wormhole sits
        /// 10000 units behind the player and closes after a second (reset(true)).</summary>
        void PlaceArrivalWormhole()
        {
            if (Wormhole == null) return;
            Wormhole.player = Player.transform;
            if (!(ComingFromVoid || Layout.alienOrbit) || Story.Index >= 43) return;
            var p = Player.transform.position - Player.transform.forward * 10000f * M;
            Wormhole.ResetTimer(true);
            Wormhole.transform.position = p;
            Wormhole.SetVisible(true);
        }

        bool riding, rode;
        /// <summary>The level is being left (wormhole ride, docking): the story checks stop.</summary>
        public bool Leaving { get; private set; }

        /// <summary>MGame::OnUpdate, PlayerEgo::isInWormhole (see the header).</summary>
        void UpdateWormholeRide()
        {
            if (riding || Collision == null || !Collision.InWormhole || Health == null || Health.Dead) return;
            int index = Story.Index;
            bool active = !Session.FreePlay && Campaign != null && Story.IsLevelMission(Layout.stationIndex);
            if (index == 42)
            {
                if (Layout.alienOrbit) return;   // the mother ship's explosion: the level script rides out itself
                RideWormhole();
                return;
            }
            if (active)
            {
                if (index == 29 || index == 41 || (index == 40 && Campaign.Event <= 3)) { riding = true; Health.Kill(); return; }
                if (index == 40) Session.LastFreighterHull = Campaign.FreighterHull;
                if (index < 41) Story.Advance(db);
            }
            RideWormhole();
        }

        /// <summary>The ride: into the alien orbit (remembering this station as Status+0x84), or out of it back there; the
        /// hull etc. are kept (Status), a stream-out arrival with the wormhole behind the player.</summary>
        public void RideWormhole()
        {
            if (rode) return;
            rode = riding = true;
            Leaving = true;
            Weapons?.StoreAmmo();
            int from = Layout.stationIndex;
            if (Layout.alienOrbit) Session.StationIndex = Session.VoidReturnStation;
            else { Session.VoidReturnStation = from; Session.StationIndex = Session.VoidOrbit; }
            Session.PreviousStationIndex = from;
            Session.ArrivedByTravel = true;
            Session.LaunchedFromStation = false;
            Session.ComingFromVoid = true;
            Session.ProgrammedStation = -1;
            SceneManager.LoadScene(SceneManager.GetActiveScene().name);
        }

        /// <summary>A level script's jump to another orbit (MGame::OnTouchEnd after index 64's / 80's success conversation:
        /// switch_to_target_setting, departStation, initStreamOutPosition): hull, shield and armor kept, a stream-out arrival.</summary>
        public void TravelTo(int station)
        {
            if (Leaving) return;
            Leaving = true;
            Weapons?.StoreAmmo();
            if (station == Session.VoidOrbit) Session.VoidReturnStation = Layout.stationIndex;
            Session.PreviousStationIndex = Layout.stationIndex;
            Session.StationIndex = station;
            Session.ArrivedByTravel = true;
            Session.LaunchedFromStation = false;
            Session.ProgrammedStation = -1;
            SceneManager.LoadScene(SceneManager.GetActiveScene().name);
        }

        /// <summary>The station's volumes (collision.json) and the visible jumpgate's sphere (see Obstacle).</summary>
        void AddObstacles()
        {
            if (Station != null)
            {
                var o = Station.AddComponent<Obstacle>();
                o.landmark = o.isStation = true;
                o.volumes = CollisionVolume.ForStation(Layout.stationIndex, Layout.systemIndex < 0);
                // PlayerStation+0x150: the transform's bounding radius + 5000 units.
                var b = new Bounds(Station.transform.position, Vector3.zero);
                foreach (var r in Station.GetComponentsInChildren<Renderer>()) b.Encapsulate(r.bounds);
                o.cubeHalf = Mathf.Max(b.extents.x, b.extents.y, b.extents.z) + 5000f * M;
            }
            if (Jumpgate != null)
            {
                var o = Jumpgate.AddComponent<Obstacle>();
                o.landmark = o.cubeIsContact = true;
                o.cubeHalf = Layout.JumpgateRadius * M;
                o.volumes.Add(CollisionVolume.Sphere(Vector3.zero, Layout.JumpgateRadius * M));
            }
        }

        void SetupCamera()
        {
            if (mainCamera == null) mainCamera = Camera.main;
            mainCamera.nearClipPlane = 20f * M;
            mainCamera.farClipPlane = 300000f * M;
            mainCamera.clearFlags = CameraClearFlags.Skybox;
        }

        // Level::createPlayer + the undock branch of Level::init.
        void SpawnPlayer()
        {
            var ship = db.Ships.Find(s => s.index == Session.ShipIndex);
            var root = new GameObject($"Player ({ship?.name})");
            if (Session.ArrivedByTravel)
            {
                var arrival = ArrivalPosition();
                root.transform.SetPositionAndRotation(arrival, Quaternion.LookRotation(-arrival.normalized, Vector3.up));
            }
            else
                root.transform.SetPositionAndRotation(
                    OrbitLayout.ToUnity(OrbitLayout.UndockPosition),
                    OrbitLayout.RotationToUnity(new Vector3(0f, (Random.value < 0.5f ? 1 : -1) * OrbitLayout.UndockYaw / 65536f * 2f * Mathf.PI, 0f)));
            var ctrl = root.AddComponent<ShipController>();
            var equipment = new System.Collections.Generic.List<ItemData>();
            foreach (var e in Session.Equipment) { var it = db.Item(e.item); if (it != null) equipment.Add(it); }
            if (ship != null) ctrl.stats = Database.BuildFlightStats(ship, equipment, Session.HasMod(3) ? 1 : 0);   // mod 3: handling +0.2
            ctrl.sensitivity = Settings.Sensitivity;
            ctrl.invertPitch = Settings.InvertPitch;
            ctrl.ApplyStats();

            var entry = db.ShipAssembly(Session.ShipIndex);
            var prefab = AssembledObject.LoadPrefab(entry);
            if (prefab != null)
            {
                var model = Instantiate(prefab, root.transform, false);
                model.GetComponent<AssembledObject>()?.SetPlayerVariant(true);
                ctrl.visualModel = model.transform;
            }
            Player = ctrl;

            // Level::createPlayer: one gun per equipped weapon on the ship's mounts (weapons_hd.json).
            Weapons = root.AddComponent<WeaponSystem>();
            Weapons.Setup(db, Session.ShipIndex, Session.Equipment);

            chase = mainCamera.GetComponent<ChaseCamera>();
            if (chase == null) chase = mainCamera.gameObject.AddComponent<ChaseCamera>();
            chase.target = ctrl;
            // TargetFollowCamera offsets (game local) -> Unity local (-x, y, z) * 0.05.
            chase.offset = new Vector3(0f, 600f, -1338f) * M;
            chase.lookOffset = new Vector3(0f, 600f, -650f) * M;
            // CameraSetPerspective(1.22 rad) is the vertical FOV: with the level look offset the ship then sits in the
            // lower middle of the screen like in the original. Used as the 16:9 value (Hor+ on wider screens). Remake: the
            // field of view option (Settings.OriginalFov by default).
            chase.baseFov = Settings.FieldOfView;
            chase.Snap();
            // PlayerEgo::checkForTurret: the turret-slot item on the ship's turret mount.
            Turret = PlayerTurret.Attach(root, db, Session.ShipIndex, Session.Equipment, chase);
            Extender = TimeExtender.Attach(root, db);

            // Asteroid mining (lock, autopilot approach, minigame): needs a drill (category 19) to lock.
            Mining = root.AddComponent<Mining>();
            Mining.Setup(db, ctrl, Weapons, chase);

            if (Session.LaunchedFromStation || Session.ArrivedByTravel) StartLaunchCamera();
        }

        /// <summary>Level::init with initStreamOutPosition (space_level_setup.md 4): into the gate orbit at the hidden gate
        /// (landmark 2); else 4 x the planet billboard (-20000 * dir) of the station the player came from, or (0, 0, 100000)
        /// when that station isn't in this system.</summary>
        Vector3 ArrivalPosition()
        {
            if (Layout.hasJumpgate || Layout.alienOrbit) return OrbitLayout.ToUnity(Layout.hiddenJumpgate);
            var from = Layout.planets.Find(p => p.station == Session.PreviousStationIndex);
            if (from == null) return OrbitLayout.ToUnity(new Vector3(0f, 0f, 100000f));
            return OrbitLayout.ToUnity(-4f * OrbitLayout.BackdropDistance * OrbitLayout.Direction(from.pitch, from.yaw));
        }

        /// <summary>Level::createCampaignMission / LevelScript: the level puts the player somewhere else (Unity pose); the launch /
        /// arrival camera is placed again around the new pose.</summary>
        public void MovePlayer(Vector3 position, Quaternion rotation)
        {
            Player.transform.SetPositionAndRotation(position, rotation);
            chase.Snap();
            if (launchCameraMs <= 0f) return;
            bool travel = launchTravel;
            float Side() => (Random.value < 0.5f ? -1f : 1f) * (travel ? Random.Range(500, 1000) : Random.Range(500, 2500));
            var local = new Vector3(-Side(), Side(), travel ? 7000f : 9000f) * M;
            mainCamera.transform.position = Player.transform.TransformPoint(local);
            mainCamera.transform.rotation = Quaternion.LookRotation(Player.transform.position - mainCamera.transform.position, Player.transform.up);
            PlaceArrivalWormhole();
        }
        bool launchTravel;
        /// <summary>Level::initStreamOutPosition: this level began with an arrival by travel (planet jump, gate, wormhole).</summary>
        public bool StreamOutArrival => launchTravel;

        // LevelScript::LevelScript: TargetFollowCamera in look-at mode at playerPos + playerRotation * (+-(500..2499),
        // +-(500..2499), 9000) (arrival by travel: +-(500..999), 7000); the chase camera takes over after 7000 ms.
        void StartLaunchCamera()
        {
            Session.LaunchedFromStation = false;
            bool travel = Session.ArrivedByTravel;
            launchTravel = travel;
            Session.ArrivedByTravel = false;
            float Side() => (Random.value < 0.5f ? -1f : 1f) * (travel ? Random.Range(500, 1000) : Random.Range(500, 2500));
            var local = new Vector3(-Side(), Side(), travel ? 7000f : 9000f) * M;   // ship-local game -> Unity (-x, y, z)
            mainCamera.transform.position = Player.transform.TransformPoint(local);
            mainCamera.transform.rotation = Quaternion.LookRotation(Player.transform.position - mainCamera.transform.position, Player.transform.up);
            mainCamera.fieldOfView = Aspect.VerticalFov(chase.baseFov, mainCamera.aspect);
            chase.enabled = false;
            launchCameraMs = LaunchCameraMs;
            Player.inputLocked = true;
            if (Weapons != null) Weapons.Blocked = true;
        }

        /// <summary>The end of the start sequence (LevelScript +0x24 > 7000): the chase camera and the controls come back, then
        /// the autopilot to a programmed station. 'skipped' (LevelScript::skipSequence, any input): the camera snaps
        /// behind the ship instead of easing there.</summary>
        void EndLaunchCamera(bool skipped)
        {
            launchCameraMs = 0f;
            Player.inputLocked = false;
            if (Weapons != null) Weapons.Blocked = false;
            chase.enabled = true;   // eases from here to the chase position
            if (skipped) chase.Snap();
            if (Session.ProgrammedStation >= 0 && !Session.InstantJump) Navigation?.ContinueToProgrammedStation();
        }

        /// <summary>A level that opens on its own cutscene (LevelScript ctor, index 78 / 81): no launch / arrival camera.</summary>
        public void EndStartSequence()
        {
            if (launchCameraMs > 0f) EndLaunchCamera(true);
        }

        /// <summary>MGame::OnTouchEnd -> LevelScript::skipSequence: the player tried to fly (steer, throttle, boost, fire, a
        /// tap, any key or button except the pause and autopilot-menu ones) during the start sequence.</summary>
        static bool PlayerTriedToFly()
        {
            var kb = Keyboard.current;
            if (kb != null && kb.anyKey.wasPressedThisFrame && !kb.escapeKey.wasPressedThisFrame && !kb.tabKey.wasPressedThisFrame) return true;
            var mouse = Mouse.current;
            if (mouse != null && (mouse.leftButton.wasPressedThisFrame || mouse.rightButton.wasPressedThisFrame)) return true;
            var touch = Touchscreen.current;
            if (touch != null && touch.primaryTouch.press.wasPressedThisFrame) return true;
            var pad = Gamepad.current;
            if (pad != null)
            {
                if (pad.leftStick.ReadValue().sqrMagnitude > 0.25f || pad.rightStick.ReadValue().sqrMagnitude > 0.25f) return true;
                if (pad.rightTrigger.wasPressedThisFrame || pad.leftTrigger.wasPressedThisFrame) return true;
                foreach (var c in pad.allControls)
                    if (c is ButtonControl b && b.wasPressedThisFrame && b != pad.startButton && b != pad.selectButton) return true;
            }
            return false;
        }

        void LateUpdate()
        {
            if (Player == null || (Health != null && Health.Dead)) return;
            if (!InDockRange) leftDockRange = true;
            // MGame::dockEvent: the autopilot to the station docks within 16000 units or on touching the station (collision
            // is off during the launch).
            if (Navigation != null && Navigation.GoingToStation && (InDockRange || Collision.TouchingStation) && launchCameraMs <= 0f && Layout.hasStation)
            {
                if (DockingBlocked) { Navigation.Refuse(); return; }   // 525 "Not possible on a mission."
                Dock();
                return;
            }
            if (launchCameraMs <= 0f) return;
            // Remake option: no launch / arrival camera = skipped at once.
            if (!Settings.LaunchCamera || Time.timeScale > 0f && PlayerTriedToFly()) { EndLaunchCamera(true); return; }
            launchCameraMs -= Time.deltaTime * 1000f;
            var cam = mainCamera.transform;
            cam.rotation = Quaternion.LookRotation(Player.transform.position - cam.position, Player.transform.up);
            if (launchCameraMs <= 0f) EndLaunchCamera(false);
        }

        /// <summary>The last save (auto-save slot) after a failed mission, or the main menu without one.</summary>
        public void LoadLastSave()
        {
            if (Session.LoadAutosave() && Application.CanStreamedLevelBeLoaded(stationScene)) SceneManager.LoadScene(stationScene);
            else SceneManager.LoadScene(0);
        }

        /// <summary>MGame::dockEvent: straight to the station module (SetCurrentApplicationModule(5)).</summary>
        public void Dock()
        {
            Leaving = true;
            Session.LaunchedFromStation = false;
            Weapons?.StoreAmmo();   // MGame::dockEvent saves the ship state to Status
            if (Application.CanStreamedLevelBeLoaded(stationScene)) SceneManager.LoadScene(stationScene);
        }
    }
}
