// MenuBackground.cs
// The main menu backdrop, like the original (Reference/research/mainmenu_notes.md; ModMainMenu::OnInitialize 0x1a46dc,
// CutScene(2), Level(2)):
//   ModMainMenu::OnInitialize   Status::resetGame, AERandom::reset, Status::setStation(Galaxy::getStation(nextInt(100))):
//                               a random main-game station 0..99 on every menu entry (the ending's backdrop keeps the
//                               station and the game: Session.EndingPending)
//   Level::init (type 2)        a normal orbit (OrbitBuilder: sky, sun / planets, lights, fog, station, jumpgate,
//                               asteroids, dust) with the ordinary free-flight traffic (Level::createMission 0xbda70 on
//                               the empty mission: Traffic / TrafficPlan / NpcShip): patrolling local fighters, raiders
//                               fighting them, freighters crossing 1-4 km beside the station, the static Terran
//                               battleship, jumpers and respawns (Level::updateOrbit); the fighters turn away from the
//                               station's volumes (PlayerFighter::update, Obstacle) like in flight
//   the player                  exists but inactive (Player::setActive(false)) at the origin: the NPCs never target it
//   CutScene::process mode 2    the camera: a fixed spot, a slow yaw pan (MenuCamera)
// Remake-only: the station keeps full detail at every distance (this build of the game always draws LOD 0 anyway), no
// asteroid right at the camera, and the traffic's own music stays off under the menu theme.

using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.World;
using UnityEngine;

namespace GoF2Remake.Visuals
{
    public class MenuBackground : MonoBehaviour
    {
        /// <summary>Unused (the old curated backdrops); kept so the menu scene's serialized data stays valid.</summary>
        [System.Serializable]
        public class Setup
        {
            public string label;
            public int station;
            public float cameraStartAngle = -1f;
        }

        [HideInInspector] public Setup[] setups;
        public MenuCamera menuCamera;
        public Light sunLight;
        public Light planetLight;

        [Tooltip("-1 = a random station 0..99 like the original (Galaxy::getStation(nextInt(100))).")]
        public int forceStation = -1;

        [Tooltip("Asteroids are kept this far (metres) from the camera (remake: nothing fills the whole view).")]
        public float cameraKeepOut = 150f;

        public GameObject Station { get; private set; }
        public OrbitLayout Layout { get; private set; }
        public Traffic Traffic { get; private set; }

        void Awake()
        {
            var db = Database.Load();
            bool ending = Session.EndingPending;
            if (!ending) Session.ResetNewGame();   // Status::resetGame
            int station = forceStation >= 0 ? forceStation : ending ? Session.StationIndex : Random.Range(0, 100);
            Layout = OrbitLayout.Build(db, station);
            Debug.Log($"MenuBackground: station {station} ({db.Stations.Find(s => s.index == station)?.name}), system {Layout.systemIndex}");

            OrbitBuilder.SetupSky(Layout);
            OrbitBuilder.SetupLights(Layout, sunLight, planetLight);

            Station = OrbitBuilder.SpawnStation(db, Layout, transform);
            if (Station != null) foreach (var lg in Station.GetComponentsInChildren<LODGroup>()) lg.enabled = false;
            var gate = OrbitBuilder.SpawnJumpgate(db, Layout, transform);
            OrbitBuilder.AddObstacles(Layout, Station, gate);
            SpawnStatics();

            // CutScene::initialize mode 2: (rnd(20000) - 20000, 0, rnd(60000) + 40000).
            var camGame = new Vector3(Random.Range(0, 20000) - 20000f, 0f, Random.Range(0, 60000) + 40000f);
            if (menuCamera != null) menuCamera.Place(camGame);
            var camPos = OrbitLayout.ToUnity(camGame);
            OrbitBuilder.SpawnAsteroids(db, Layout, transform, p => (p - camPos).sqrMagnitude < cameraKeepOut * cameraKeepOut);

            SpawnTraffic(db);
            OrbitBuilder.SpawnDust(Layout, transform);
            var cam = menuCamera != null ? menuCamera.GetComponent<Camera>() : Camera.main;
            OrbitBuilder.SpawnBackdrop(Layout, cam, transform);
            SkyLayers.Spawn(Layout, cam, transform);
        }

        /// <summary>Level::createScene mode 2 at campaign mission 0x2b (the ending's backdrop): two PlayerStatics at the
        /// origin, meshes 0x37d0 (beer) and 0x37d1 (bra), unturned (game identity = Unity yaw 180), i.e. inside the station.</summary>
        void SpawnStatics()
        {
            if (Session.CampaignMission != 0x2b || Session.FreePlay) return;
            var story = StoryAssets.Load();
            if (story == null || story.menuStatics == null) return;
            foreach (var prefab in story.menuStatics)
                if (prefab != null) Instantiate(prefab, Vector3.zero, OrbitLayout.RotationToUnity(Vector3.zero), transform).name = prefab.name;
        }

        /// <summary>Level::createMission on the empty mission, as in flight (TrafficPlan), with the inactive player at the
        /// origin (Level::createPlayer, Player::setActive(false)): alive for nothing, so no NPC ever targets it.</summary>
        void SpawnTraffic(Database db)
        {
            NpcTables.InCampaignLevel = false;   // per-level flags the flight level sets
            NpcTables.LevelFreelanceType = -1;
            var player = new GameObject("Player (inactive)");
            player.transform.SetParent(transform, false);
            var target = player.AddComponent<Target>();
            target.isPlayer = true;
            target.untargetable = true;
            target.hp = 0f;
            Traffic = new GameObject("Traffic").AddComponent<Traffic>();
            Traffic.transform.SetParent(transform, false);
            Traffic.MenuBackdrop = true;
            Traffic.Setup(db, Layout, target, Station);
        }
    }
}
