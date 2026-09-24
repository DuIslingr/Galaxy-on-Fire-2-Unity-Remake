// GoF2SpaceLevel.cs
// Builds the flight level for the current station orbit at startup, like Level::init 0xbb49c (two passes) and
// MGame::reset 0x1a793c: one level = one station orbit; the other stations of the system only appear as planets.
// The world itself (sky, lights, station, jumpgate, asteroids, dust, sun/planets) comes from GoF2OrbitBuilder,
// which the main menu background uses too. This adds the flight parts:
//   createPlayer:  player ship at (10, 10, 10000) facing away from the station (+-8.8 deg), speed 2 u/ms
//   MGame::reset:  camera fov 1.22 rad, near 20, far 300000 units; chase offsets (0, 600, -1338) / (0, 600, -650)
//   MGame::dockEvent 0x1afebc: docking switches straight to the station module (no animation). The original needs the
//                  autopilot aimed at the station plus a collision or |pos| < 16000; here the HUD offers "Dock" inside
//                  16000 units once the player has flown out of that range after spawning (no autopilot yet).
//   LevelScript 0x15e650 / process 0x160d50: after launching from the station a fixed camera 9000 units ahead of the
//                  ship (+-500..2499 sideways and up) watches it fly past for 7 s, then the chase camera takes over.
//   Level::init arrival by travel (planet jump, GoF2Navigation): 4x the previous station's planet billboard (about 80000
//                  units out) or the hidden jumpgate in the gate orbit, facing the station, with the travel launch camera.
//   GoF2Navigation: station / jumpgate / planet locks, autopilot (docks at the station), planet jump, fast-forward.
//   GoF2SystemJump: the jumpgate (star map, jump scene) and the Khador Drive. Arrival from another system: the hidden gate
//                  in the gate orbit, else (0, 0, 100000); the arrival camera then shows the orbit information.
//   LevelScript::process 0x160d50: at the end of the launch / arrival camera the autopilot continues to a programmed
//                  station (GoF2Navigation.ContinueToProgrammedStation), unless the Khador Drive is about to charge.
//   Level::createMission etc.: the NPC traffic (GoF2Traffic) and ship combat: the player's pools and death
//                  (GoF2PlayerHealth), ship / salvage locks (GoF2CombatRadar); invulnerable during the launch / arrival
//                  camera and the jump scenes.
//   PlayerEgo::calcCollision: the ship slides along the station, the visible jumpgate and freighters (GoF2Obstacle,
//                  GoF2PlayerCollision), touching an asteroid destroys it; off during the launch / arrival camera and the
//                  jump scenes. MGame::dockEvent: the autopilot to the station also docks on touching the station.
//   Story (GoF2StorySpace, GoF2CampaignLevel): an orbit built around a campaign mission (GoF2Story.IsLevelMission) gets
//                  the campaign level instead of normal traffic; briefings, success / failure, the add-on entry calls. On a
//                  story mission the station refuses docking and the planet jumps / Khador Drive are blocked (525).
// Not yet: lens flare, wormhole.

using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.Visuals;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace GoF2Remake.World
{
    [DefaultExecutionOrder(-100)]
    public class GoF2SpaceLevel : MonoBehaviour
    {
        const float M = GoF2OrbitLayout.MetersPerUnit;

        [Header("Scene")]
        public Camera mainCamera;
        public Light sunLight;
        public Light planetLight;

        [Header("Orbit (-1 = GoF2Session)")]
        public int stationOverride = -1;
        public string stationScene = "Station";

        [Header("Tuning (not recovered constants)")]
        [Tooltip("URP intensity for the original's LIGHT0 diffuse of 2.0 (clamp(15 * sunColour, 0, 2)).")]
        public float sunIntensityAt2 = 1.6f;
        public float planetLightIntensity = 1f;
        public float ambientIntensity = 1f;

        public GoF2OrbitLayout Layout { get; private set; }
        public GoF2ShipController Player { get; private set; }
        public GoF2WeaponSystem Weapons { get; private set; }
        public GoF2Mining Mining { get; private set; }
        public GoF2Navigation Navigation { get; private set; }
        public GoF2SystemJump SystemJump { get; private set; }
        public GoF2PlayerHealth Health { get; private set; }
        public GoF2Traffic Traffic { get; private set; }
        public GoF2CombatRadar Radar { get; private set; }
        public GoF2PlayerCollision Collision { get; private set; }
        public GoF2StorySpace Story { get; private set; }
        /// <summary>The campaign level of a story orbit, null in a normal orbit.</summary>
        public GoF2CampaignLevel Campaign { get; private set; }
        /// <summary>The freelance mission's orbit (GoF2FreelanceOrbit), null = none.</summary>
        public GoF2FreelanceOrbit Freelance { get; private set; }
        /// <summary>A story conversation is open (the game is paused).</summary>
        public bool Dialogue => Story != null && Story.DialogueOpen;
        /// <summary>LevelScript startSequenceOver: the launch / arrival camera has ended (in the prologue / rescue the
        /// cutscene script decides).</summary>
        public bool StartSequenceOver => launchCameraMs <= 0f && (Campaign == null || Campaign.StartSequenceOver);
        public bool LaunchCameraOver => launchCameraMs <= 0f;
        /// <summary>A LevelScript cutscene owns the camera (MGame+0x5f): no HUD, no player control.</summary>
        public bool Cutscene => Campaign != null && Campaign.Cutscene;
        public Transform Asteroids { get; private set; }
        public GoF2Backdrop Backdrop { get; private set; }
        public GameObject Station { get; private set; }
        public GameObject Jumpgate { get; private set; }
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
                               && !GoF2Story.BlocksDocking(Layout.stationIndex)
                               && (Mining == null || Mining.State == GoF2Mining.Phase.Idle);
        bool InDockRange => Player.transform.position.sqrMagnitude < DockRange * M * DockRange * M;

        GoF2Database db;
        public GoF2Database Database => db;
        GoF2ChaseCamera chase;
        float launchCameraMs;
        bool leftDockRange, orbitInfo;

        void Awake()
        {
            db = GoF2Database.Load();
            int station = stationOverride >= 0 ? stationOverride : GoF2Session.StationIndex;
            Layout = GoF2OrbitLayout.Build(db, station);
            var st = db.Stations.Find(s => s.index == station);
            StationInfo = st;
            SystemJumpgateStation = db.Systems.Find(s => s.index == Layout.systemIndex)?.jumpgateStation ?? -1;
            Debug.Log($"GoF2SpaceLevel: station {station} {st?.name} (system {Layout.systemIndex} {st?.systemName}), " +
                      $"gate {Layout.hasJumpgate}, {Layout.asteroidCount} asteroids");

            GoF2OrbitBuilder.SetupSky(Layout, ambientIntensity);
            GoF2OrbitBuilder.SetupLights(Layout, sunLight, planetLight, sunIntensityAt2, planetLightIntensity);
            SetupCamera();
            // Status::inEmptyOrbit: Var Hastra (78) has no station while the index is 0 or 1 (the prologue and the rescue);
            // Level::init: the prologue's asteroid belt is centred on the origin, under its own sky (Level::createSpace).
            bool prologue = station == 78 && !GoF2Session.FreePlay && GoF2Story.Index <= 1;
            if (prologue) Layout.hasStation = false;
            if (prologue && GoF2Story.Index == 0) Layout.asteroidCentre = Vector3.zero;
            Station = GoF2OrbitBuilder.SpawnStation(db, Layout);
            Jumpgate = GoF2OrbitBuilder.SpawnJumpgate(db, Layout);
            AddObstacles();
            Asteroids = GoF2OrbitBuilder.SpawnAsteroids(db, Layout);
            if (prologue && GoF2Story.Index == 0)
            {
                var story = GoF2StoryAssets.Load();
                if (story != null && story.introSky != null) { RenderSettings.skybox = story.introSky; DynamicGI.UpdateEnvironment(); }
            }
            orbitInfo = GoF2Session.ArrivedBySystemJump;
            GoF2Session.ArrivedBySystemJump = false;
            SpawnPlayer();
            GoF2OrbitBuilder.SpawnDust(Layout);
            var backdrop = GoF2OrbitBuilder.SpawnBackdrop(Layout, mainCamera);
            Backdrop = backdrop;

            // Locks on the station, the jumpgate and the other stations' planets; autopilot, planet jump, fast-forward.
            Navigation = Player.gameObject.AddComponent<GoF2Navigation>();
            Navigation.Setup(db, Layout, backdrop, Player, Mining, chase, Weapons);
            Mining.navigation = Navigation;
            SystemJump = Player.gameObject.AddComponent<GoF2SystemJump>();
            SystemJump.Setup(db, Navigation, Player, Weapons, chase, Jumpgate);

            // Ship combat: the player's Player object, the orbit's NPC traffic, the ship / salvage locks.
            Health = Player.gameObject.AddComponent<GoF2PlayerHealth>();
            Health.Setup(db, Player, chase, Weapons);
            Collision = Player.gameObject.AddComponent<GoF2PlayerCollision>();
            Collision.Setup(Health, chase, Mining);
            bool storyOrbit = !GoF2Session.FreePlay && GoF2Story.IsLevelMission(station);
            // Status::departStation: the freelance mission's target orbit is built around it (not over a story orbit).
            bool freelanceOrbit = !storyOrbit && GoF2Freelance.IsMissionOrbit(station);
            Traffic = new GameObject("Traffic").AddComponent<GoF2Traffic>();
            Traffic.Setup(db, Layout, Health.Target, Station, storyOrbit || freelanceOrbit);
            if (storyOrbit)
            {
                Campaign = new GameObject("Campaign").AddComponent<GoF2CampaignLevel>();
                Campaign.Setup(this, Traffic);
                Navigation.SetRoute(Campaign.PlayerRoute);
            }
            else if (freelanceOrbit)
            {
                Freelance = new GameObject("Freelance mission").AddComponent<GoF2FreelanceOrbit>();
                Freelance.Setup(this, Traffic);
                Navigation.SetRoute(Freelance.PlayerRoute);
            }
            // Level::createWingmen: after the mission's ships (Challenge: unarmed).
            Traffic.SpawnWingmen(Player.transform, Freelance != null && Freelance.Type == GoF2MissionType.Challenge);
            Navigation.HasWingmen = () => Traffic != null && Traffic.LivingWingmen.Count > 0;
            Story = gameObject.AddComponent<GoF2StorySpace>();
            Story.Setup(this, Campaign);
            Navigation.JumpsBlocked = () => !GoF2Story.PlanetJumpsAllowed || GoF2Story.BlocksJumps(Layout.stationIndex);
            Radar = Player.gameObject.AddComponent<GoF2CombatRadar>();
            Radar.Setup(db, Player, Navigation, Mining, Weapons, Health, Traffic);
        }

        void Update()
        {
            // MGame::OnUpdate: the wingmen's contract runs down while flying (fast-forward included, not while paused).
            if (GoF2Session.Wingmen.Count > 0 && GoF2Session.WingmanContractMs > 0f) GoF2Session.WingmanContractMs = Mathf.Max(0f, GoF2Session.WingmanContractMs - Time.deltaTime * 1000f);
            if (Health == null) return;
            Health.invulnerable = launchCameraMs > 0f || Navigation.Jumping || (SystemJump != null && SystemJump.Cinematic)
                                  || (Campaign != null && Campaign.PlayerInvulnerable);
            Collision.off = launchCameraMs > 0f || Navigation.Jumping || (SystemJump != null && SystemJump.Cinematic)
                            || (Campaign != null && Campaign.CollisionOff);   // PlayerEgo+0x144
            Collision.ignoreGate = Navigation.GoingToGate;
            // Hostiles, or a radio line on screen, block fast-forward (MGame::OnUpdate).
            Navigation.HostilesPresent = (Traffic != null && Traffic.HostileCount > 0) || (Campaign != null && Campaign.Radio != null && Campaign.Radio.Busy);
        }

        /// <summary>The station's volumes (collision.json) and the visible jumpgate's sphere (see GoF2Obstacle).</summary>
        void AddObstacles()
        {
            if (Station != null)
            {
                var o = Station.AddComponent<GoF2Obstacle>();
                o.landmark = o.isStation = true;
                o.volumes = GoF2CollisionVolume.ForStation(Layout.stationIndex, Layout.systemIndex < 0);
                // PlayerStation+0x150: the transform's bounding radius + 5000 units.
                var b = new Bounds(Station.transform.position, Vector3.zero);
                foreach (var r in Station.GetComponentsInChildren<Renderer>()) b.Encapsulate(r.bounds);
                o.cubeHalf = Mathf.Max(b.extents.x, b.extents.y, b.extents.z) + 5000f * M;
            }
            if (Jumpgate != null)
            {
                var o = Jumpgate.AddComponent<GoF2Obstacle>();
                o.landmark = o.cubeIsContact = true;
                o.cubeHalf = Layout.JumpgateRadius * M;
                o.volumes.Add(GoF2CollisionVolume.Sphere(Vector3.zero, Layout.JumpgateRadius * M));
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
            var ship = db.Ships.Find(s => s.index == GoF2Session.ShipIndex);
            var root = new GameObject($"Player ({ship?.name})");
            if (GoF2Session.ArrivedByTravel)
            {
                var arrival = ArrivalPosition();
                root.transform.SetPositionAndRotation(arrival, Quaternion.LookRotation(-arrival.normalized, Vector3.up));
            }
            else
                root.transform.SetPositionAndRotation(
                    GoF2OrbitLayout.ToUnity(GoF2OrbitLayout.UndockPosition),
                    GoF2OrbitLayout.RotationToUnity(new Vector3(0f, (Random.value < 0.5f ? 1 : -1) * GoF2OrbitLayout.UndockYaw / 65536f * 2f * Mathf.PI, 0f)));
            var ctrl = root.AddComponent<GoF2ShipController>();
            var equipment = new System.Collections.Generic.List<ItemData>();
            foreach (var e in GoF2Session.Equipment) { var it = db.Item(e.item); if (it != null) equipment.Add(it); }
            if (ship != null) ctrl.stats = GoF2Database.BuildFlightStats(ship, equipment);
            ctrl.sensitivity = GoF2Settings.Sensitivity;
            ctrl.invertPitch = GoF2Settings.InvertPitch;
            ctrl.ApplyStats();

            string prefix = $"ship_{GoF2Session.ShipIndex:000}_";
            var entry = db.Assemblies.Find(a => a.category == "ships" && a.name.StartsWith(prefix));
            var prefab = GoF2AssembledObject.LoadPrefab(entry);
            if (prefab != null)
            {
                var model = Instantiate(prefab, root.transform, false);
                model.GetComponent<GoF2AssembledObject>()?.SetPlayerVariant(true);
                ctrl.visualModel = model.transform;
            }
            Player = ctrl;

            // Level::createPlayer: one gun per equipped weapon on the ship's mounts (weapons_hd.json).
            Weapons = root.AddComponent<GoF2WeaponSystem>();
            Weapons.Setup(db, GoF2Session.ShipIndex, GoF2Session.Equipment);

            chase = mainCamera.GetComponent<GoF2ChaseCamera>();
            if (chase == null) chase = mainCamera.gameObject.AddComponent<GoF2ChaseCamera>();
            chase.target = ctrl;
            // TargetFollowCamera offsets (game local) -> Unity local (-x, y, z) * 0.05.
            chase.offset = new Vector3(0f, 600f, -1338f) * M;
            chase.lookOffset = new Vector3(0f, 600f, -650f) * M;
            // CameraSetPerspective(1.22 rad) is the vertical FOV: with the level look offset the ship then sits in the
            // lower middle of the screen like in the original. Used as the 16:9 value (Hor+ on wider screens).
            chase.baseFov = 1.22f * Mathf.Rad2Deg;
            chase.Snap();

            // Asteroid mining (lock, autopilot approach, minigame): needs a drill (category 19) to lock.
            Mining = root.AddComponent<GoF2Mining>();
            Mining.Setup(db, ctrl, Weapons, chase);

            if (GoF2Session.LaunchedFromStation || GoF2Session.ArrivedByTravel) StartLaunchCamera();
        }

        /// <summary>Level::init with initStreamOutPosition (space_level_setup.md 4): into the gate orbit at the hidden gate
        /// (landmark 2); else 4 x the planet billboard (-20000 * dir) of the station the player came from, or (0, 0, 100000)
        /// when that station isn't in this system.</summary>
        Vector3 ArrivalPosition()
        {
            if (Layout.hasJumpgate) return GoF2OrbitLayout.ToUnity(Layout.hiddenJumpgate);
            var from = Layout.planets.Find(p => p.station == GoF2Session.PreviousStationIndex);
            if (from == null) return GoF2OrbitLayout.ToUnity(new Vector3(0f, 0f, 100000f));
            return GoF2OrbitLayout.ToUnity(-4f * GoF2OrbitLayout.BackdropDistance * GoF2OrbitLayout.Direction(from.pitch, from.yaw));
        }

        // LevelScript::LevelScript: TargetFollowCamera in look-at mode at playerPos + playerRotation * (+-(500..2499),
        // +-(500..2499), 9000) (arrival by travel: +-(500..999), 7000); the chase camera takes over after 7000 ms.
        void StartLaunchCamera()
        {
            GoF2Session.LaunchedFromStation = false;
            bool travel = GoF2Session.ArrivedByTravel;
            GoF2Session.ArrivedByTravel = false;
            float Side() => (Random.value < 0.5f ? -1f : 1f) * (travel ? Random.Range(500, 1000) : Random.Range(500, 2500));
            var local = new Vector3(-Side(), Side(), travel ? 7000f : 9000f) * M;   // ship-local game -> Unity (-x, y, z)
            mainCamera.transform.position = Player.transform.TransformPoint(local);
            mainCamera.transform.rotation = Quaternion.LookRotation(Player.transform.position - mainCamera.transform.position, Player.transform.up);
            mainCamera.fieldOfView = GoF2Aspect.VerticalFov(chase.baseFov, mainCamera.aspect);
            chase.enabled = false;
            launchCameraMs = LaunchCameraMs;
        }

        void LateUpdate()
        {
            if (Player == null || (Health != null && Health.Dead)) return;
            if (!InDockRange) leftDockRange = true;
            // MGame::dockEvent: the autopilot to the station docks within 16000 units or on touching the station (collision
            // is off during the launch).
            if (Navigation != null && Navigation.GoingToStation && (InDockRange || Collision.TouchingStation) && launchCameraMs <= 0f && Layout.hasStation)
            {
                if (GoF2Story.BlocksDocking(Layout.stationIndex)) { Navigation.Refuse(); return; }   // 525 "Not possible on a mission."
                Dock();
                return;
            }
            if (launchCameraMs <= 0f) return;
            launchCameraMs -= Time.deltaTime * 1000f;
            var cam = mainCamera.transform;
            cam.rotation = Quaternion.LookRotation(Player.transform.position - cam.position, Player.transform.up);
            if (launchCameraMs <= 0f)
            {
                chase.enabled = true;   // eases from here to the chase position
                if (GoF2Session.ProgrammedStation >= 0 && !GoF2Session.InstantJump) Navigation?.ContinueToProgrammedStation();
            }
        }

        /// <summary>The last save (auto-save slot) after a failed mission, or the main menu without one.</summary>
        public void LoadLastSave()
        {
            if (GoF2Session.LoadAutosave() && Application.CanStreamedLevelBeLoaded(stationScene)) SceneManager.LoadScene(stationScene);
            else SceneManager.LoadScene(0);
        }

        /// <summary>MGame::dockEvent: straight to the station module (SetCurrentApplicationModule(5)).</summary>
        public void Dock()
        {
            GoF2Session.LaunchedFromStation = false;
            Weapons?.StoreAmmo();   // MGame::dockEvent saves the ship state to Status
            if (Application.CanStreamedLevelBeLoaded(stationScene)) SceneManager.LoadScene(stationScene);
        }
    }
}
