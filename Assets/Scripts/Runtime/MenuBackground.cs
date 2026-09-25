// MenuBackground.cs
// The main menu backdrop. The original's menu background is a normal orbit level (ModMainMenu::OnInitialize picks
// Galaxy::getStation(rnd.nextInt(100)); Level type 2 in Level::createScene), so this builds the chosen station's orbit
// with the same OrbitBuilder as the flight level: its sky and rotation, sun and planets, lights, fog, jumpgate,
// asteroids and dust. The choice is from a curated set of stations that frame well behind the menu. Menu-only:
// the station keeps full detail at every distance, asteroids stay out of the camera's orbit, and the traffic is a
// readable version of the orbit's ambient mission (Level::createMission 0xbda70): fighters of the system's race in
// pairs, a freighter (30% Nivelian, like the original), the battleship in Terran space, crossing the view on lanes.

using System;
using GoF2Remake.Data;
using GoF2Remake.World;
using UnityEngine;

namespace GoF2Remake.Visuals
{
    public class MenuBackground : MonoBehaviour
    {
        [Serializable]
        public class Setup
        {
            public string label;
            [Tooltip("Station index (stations.json); the orbit is built like a flight level.")]
            public int station;
            [Tooltip("Where the camera orbit starts (degrees around the station); negative = automatic (lit side, planet behind).")]
            public float cameraStartAngle = -1f;
        }

        public Setup[] setups;
        public MenuCamera menuCamera;
        public Light sunLight;
        public Light planetLight;

        [Tooltip("-1 = random from the setups.")]
        public int forceSetup = -1;

        [Tooltip("Asteroids are kept this many camera-orbit radii away from the station centre.")]
        public float asteroidKeepOut = 1.35f;

        [Header("Traffic")]
        public int fighterPairs = 2;
        [Tooltip("Speeds in m/s; faster than the original's 100 m/s so they cross the view at menu distances.")]
        public float fighterSpeed = 140f, freighterSpeed = 60f, battleshipSpeed = 35f;

        static readonly string[] RaceSuffix = { "terran", "vossk", "nivelian", "midorian" };

        public GameObject Station { get; private set; }
        public OrbitLayout Layout { get; private set; }

        void Awake()
        {
            if (setups == null || setups.Length == 0) return;
            int i = forceSetup >= 0 && forceSetup < setups.Length ? forceSetup : UnityEngine.Random.Range(0, setups.Length);
            var s = setups[i];
            var db = Database.Load();
            Layout = OrbitLayout.Build(db, s.station);

            OrbitBuilder.SetupSky(Layout);
            OrbitBuilder.SetupLights(Layout, sunLight, planetLight);

            float orbit = 4000f;
            var centre = Vector3.zero;
            Station = OrbitBuilder.SpawnStation(db, Layout, transform);
            if (Station != null)
            {
                // The menu shows the full-detail station at every distance, like this build of the game.
                foreach (var lg in Station.GetComponentsInChildren<LODGroup>()) lg.enabled = false;
                var b = Bounds(Station);
                centre = b.center;
                if (menuCamera != null)
                {
                    menuCamera.target = Station.transform;
                    menuCamera.lookOffset = Station.transform.InverseTransformPoint(b.center);
                    menuCamera.distance = b.extents.magnitude * 2.6f;
                    menuCamera.height = b.extents.y * 0.35f;
                    menuCamera.bobAmplitude = b.extents.y * 0.12f;
                    menuCamera.startAngle = s.cameraStartAngle >= 0f ? s.cameraStartAngle : AutoStartAngle(Layout);
                    menuCamera.ResetOrbit();
                    orbit = menuCamera.distance;
                }
            }
            OrbitBuilder.SpawnJumpgate(db, Layout, transform);
            SpawnStatics();
            float keepOut = orbit * asteroidKeepOut;
            OrbitBuilder.SpawnAsteroids(db, Layout, transform, p => (p - centre).sqrMagnitude < keepOut * keepOut);
            SpawnTraffic(db, centre);
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

        void SpawnTraffic(Database db, Vector3 centre)
        {
            var root = new GameObject("Traffic").transform;
            root.SetParent(transform, false);
            string race = RaceSuffix[Layout.raceId >= 0 && Layout.raceId < RaceSuffix.Length ? Layout.raceId : 0];
            var fighters = db.Assemblies.FindAll(a => a.category == "ships" && a.pack == "main" && a.name.StartsWith("ship_") && a.name.EndsWith("_" + race));
            var freighter = db.Assemblies.Find(a => a.category == "ships" && a.name.StartsWith("cargo_")
                                                     && a.name.EndsWith("_" + (UnityEngine.Random.value < 0.3f ? "nivelian" : race)));
            var cam = menuCamera != null ? menuCamera.transform : Camera.main.transform;

            for (int i = 0; i < fighterPairs && fighters.Count > 0; i++)
            {
                var entry = fighters[UnityEngine.Random.Range(0, fighters.Count)];
                // The first pair is already crossing the view when the menu appears, the others fly in.
                bool inView = i == 0;
                float delay = inView ? 0f : UnityEngine.Random.Range(2f, 6f) + (i - 1) * 8f;
                float progress = inView ? UnityEngine.Random.Range(0.25f, 0.5f) : 0f;
                var lead = SpawnFlyby(entry, root, fighterSpeed, 10f, delay, progress);
                var wing = SpawnFlyby(entry, root, fighterSpeed, 10f, delay, progress);
                if (lead == null || wing == null) continue;
                // One lane per pass for the pair, whichever of the two asks first (both ask once per pass).
                int calls = 0;
                (Vector3 start, Quaternion rot, float length) shared = default;
                (Vector3, Quaternion, float) PairLane()
                {
                    if (calls++ % 2 == 0) shared = Lane(cam, centre, UnityEngine.Random.Range(0.12f, 0.35f));
                    return shared;
                }
                lead.nextLane = PairLane;
                // Wingman: beside, above and behind the leader.
                wing.nextLane = () =>
                {
                    var (start, rot, length) = PairLane();
                    float d = (start - cam.position).magnitude * 0.03f;
                    return (start + rot * new Vector3(d * 1.5f, d * 0.5f, -d * 2f), rot, length);
                };
            }
            if (freighter != null)
            {
                var f = SpawnFlyby(freighter, root, freighterSpeed, 20f, 0f, UnityEngine.Random.Range(0.3f, 0.6f));
                if (f != null) f.nextLane = () => Lane(cam, centre, UnityEngine.Random.Range(0.5f, 0.85f));
            }
            if (race == "terran")
            {
                var b = SpawnFlyby(db.AssemblyByName("battleship_terran"), root, battleshipSpeed, 40f, 0f, UnityEngine.Random.Range(0.3f, 0.5f));
                if (b != null) b.nextLane = () => Lane(cam, centre, UnityEngine.Random.Range(0.9f, 1.3f));
            }
        }

        /// <summary>
        /// A lane across the current view: it crosses the line from the camera to the station at 'depth' (fraction of
        /// that distance), sideways, and is long enough to enter and leave the screen.
        /// </summary>
        static (Vector3 start, Quaternion rotation, float length) Lane(Transform cam, Vector3 centre, float depth)
        {
            var toStation = centre - cam.position;
            float dist = toStation.magnitude;
            var fwd = toStation / Mathf.Max(dist, 1f);
            var side = Vector3.Cross(Vector3.up, fwd).normalized;
            var closest = cam.position + fwd * dist * depth
                          + side * dist * depth * UnityEngine.Random.Range(-0.15f, 0.15f)
                          + Vector3.up * dist * depth * UnityEngine.Random.Range(-0.25f, 0.25f);
            var heading = (UnityEngine.Random.value < 0.5f ? side : -side);
            heading = Quaternion.AngleAxis(UnityEngine.Random.Range(-25f, 25f), Vector3.up) * heading;
            heading = Quaternion.AngleAxis(UnityEngine.Random.Range(-6f, 6f), side) * heading;
            float length = dist * depth * 2f;   // starts and ends just outside the view (visible width ~1.65 x depth)
            return (closest - heading * length * 0.5f, Quaternion.LookRotation(heading), length);
        }

        static Flyby SpawnFlyby(AssemblyData entry, Transform parent, float speed, float pause, float delay, float progress = 0f)
        {
            var prefab = AssembledObject.LoadPrefab(entry);
            if (prefab == null) return null;
            var go = Instantiate(prefab, parent);
            go.GetComponent<AssembledObject>()?.SetPlayerVariant(false);   // NPC engines
            var fly = go.AddComponent<Flyby>();
            fly.speed = speed;
            fly.pause = pause;
            fly.startDelay = delay;
            fly.startProgress = progress;
            return fly;
        }

        /// <summary>
        /// Camera start angle between the sun's side (the station is lit) and the side opposite the orbit planet
        /// (the planet, at Unity +Z, is behind the station). MenuCamera puts the camera at Euler(0, a, 0) * -Z.
        /// </summary>
        static float AutoStartAngle(OrbitLayout layout)
        {
            var toSun = OrbitLayout.DirToUnity(layout.lightDirection);
            toSun.y = 0f;
            var d = (toSun.sqrMagnitude > 1e-4f ? toSun.normalized : Vector3.zero) + Vector3.back;
            if (d.sqrMagnitude < 1e-4f) d = Vector3.left;   // sun straight behind the planet: look from the side
            return Mathf.Atan2(-d.x, -d.z) * Mathf.Rad2Deg;
        }

        static Bounds Bounds(GameObject go)
        {
            var rs = go.GetComponentsInChildren<Renderer>();
            if (rs.Length == 0) return new Bounds(go.transform.position, Vector3.one * 100f);
            var b = rs[0].bounds;
            foreach (var r in rs) b.Encapsulate(r.bounds);
            return b;
        }
    }
}
