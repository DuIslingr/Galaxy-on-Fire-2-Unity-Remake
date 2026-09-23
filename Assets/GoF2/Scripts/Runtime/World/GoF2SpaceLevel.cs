// GoF2SpaceLevel.cs
// Builds the flight level for the current station orbit at startup, like Level::init 0xbb49c (two passes) and
// MGame::reset 0x1a793c: one level = one station orbit; the other stations of the system only appear as planets.
//   createSpace:   sky (GoF2/SpaceSky, stars + nebula rotated by R_sky), station at the origin, visible jumpgate in
//                  the system's gate orbit, sun/planets (GoF2Backdrop)
//   initLight:     LIGHT0 toward the sun, LIGHT1 from the orbit planet (Unity +Z), skybox ambient, linear fog
//   createPlayer:  player ship at (10, 10, 10000) facing away from the station (+-8.8 deg), speed 2 u/ms
//   createAsteroids: 40..79 asteroids around a seeded centre (the individual rocks are random per visit)
//   initParticleSystems: space dust + fog sprites around the camera
//   MGame::reset:  camera fov 1.22 rad, near 20, far 300000 units; chase offsets (0, 600, -1338) / (0, 600, -650)
// Not yet: traffic (Level::createMission), missions, docking, travel, HUD, lens flare, wormhole.

using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.Visuals;
using UnityEngine;
using UnityEngine.Rendering;

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

        [Header("Tuning (not recovered constants)")]
        [Tooltip("URP intensity for the original's LIGHT0 diffuse of 2.0 (clamp(15 * sunColour, 0, 2)).")]
        public float sunIntensityAt2 = 1.6f;
        public float planetLightIntensity = 1f;
        public float ambientIntensity = 1f;

        public GoF2OrbitLayout Layout { get; private set; }
        public GoF2ShipController Player { get; private set; }

        GoF2Database db;

        void Awake()
        {
            db = GoF2Database.Load();
            int station = stationOverride >= 0 ? stationOverride : GoF2Session.StationIndex;
            Layout = GoF2OrbitLayout.Build(db, station);
            var st = db.Stations.Find(s => s.index == station);
            Debug.Log($"GoF2SpaceLevel: station {station} {st?.name} (system {Layout.systemIndex} {st?.systemName}), " +
                      $"gate {Layout.hasJumpgate}, {Layout.asteroidCount} asteroids");

            SetupSky();
            SetupLights();
            SetupCamera();
            SpawnStation();
            SpawnJumpgate();
            SpawnAsteroids();
            SpawnPlayer();
            SpawnDust();
            new GameObject("Backdrop").AddComponent<GoF2Backdrop>().Build(Layout, mainCamera);
        }

        // ---- sky, light, fog ---------------------------------------------------------------------------------

        void SetupSky()
        {
            var template = Resources.Load<Material>("GoF2Sky/SpaceSky");
            if (template == null) { Debug.LogWarning("GoF2SpaceLevel: run GoF2 > Bake Space Skies"); return; }
            var sky = new Material(template) { name = "SpaceSky (runtime)" };
            int stars = Layout.systemIndex >= 0 ? Layout.systemIndex % 3 : 2;   // alien/void: stars_002
            sky.SetTexture("_Stars", Resources.Load<Cubemap>($"GoF2Sky/stars_{stars:000}"));
            sky.SetTexture("_Nebula", Resources.Load<Cubemap>($"GoF2Sky/nebula_{Layout.systemTexture:000}"));
            // The shader maps world directions into the baked cube: the inverse of the sky's Unity rotation.
            sky.SetMatrix("_SkyRotation", Matrix4x4.Rotate(Quaternion.Inverse(SkyRotation())));
            RenderSettings.skybox = sky;
            RenderSettings.ambientMode = AmbientMode.Skybox;
            RenderSettings.ambientIntensity = ambientIntensity;
            RenderSettings.defaultReflectionMode = DefaultReflectionMode.Skybox;
            DynamicGI.UpdateEnvironment();

            RenderSettings.fog = Layout.fog;
            if (Layout.fog)
            {
                RenderSettings.fogMode = FogMode.Linear;
                RenderSettings.fogStartDistance = 0f;
                RenderSettings.fogEndDistance = Layout.fogEnd * M;
                RenderSettings.fogColor = Layout.fogColor;
            }
        }

        /// <summary>R_sky in Unity (the baked cubemaps are the sky meshes at identity, after the import's 180 deg yaw).</summary>
        Quaternion SkyRotation()
        {
            if (!Layout.skySunAligned) return GoF2OrbitLayout.RotationToUnity(Layout.skyEuler);
            // System 27: X = a x b, Y = a (toward the sun), Z = b with b = normalize((1,0,0) x a). Mirrored to Unity
            // (S * R * S) the Z column flips sign: Y' = S a, Z' = -S b.
            var a = GoF2OrbitLayout.DirToUnity(Layout.lightDirection).normalized;
            var b = GoF2OrbitLayout.DirToUnity(Vector3.Cross(Vector3.right, Layout.lightDirection)).normalized;
            return Quaternion.LookRotation(-b, a) * Quaternion.Euler(0f, 180f, 0f);
        }

        void SetupLights()
        {
            var toSun = GoF2OrbitLayout.DirToUnity(Layout.lightDirection).normalized;
            if (sunLight != null)
            {
                sunLight.transform.rotation = Quaternion.LookRotation(-toSun);
                var c = Layout.SunLightColor;   // 0..2 per channel, 2 for most systems
                float max = Mathf.Max(c.r, Mathf.Max(c.g, c.b), 1e-3f);
                sunLight.color = c / max;
                sunLight.intensity = sunIntensityAt2 * max / 2f;
            }
            if (planetLight != null)
            {
                // LIGHT1 direction (0, 0, -1) game = toward the orbit planet (Unity +Z); light travels toward -Z.
                planetLight.transform.rotation = Quaternion.LookRotation(Vector3.back);
                planetLight.color = Layout.planetLightColor;
                planetLight.intensity = planetLightIntensity;
            }
        }

        void SetupCamera()
        {
            if (mainCamera == null) mainCamera = Camera.main;
            mainCamera.nearClipPlane = 20f * M;
            mainCamera.farClipPlane = 300000f * M;
            mainCamera.clearFlags = CameraClearFlags.Skybox;
        }

        // ---- objects -----------------------------------------------------------------------------------------

        GameObject Spawn(string assembly, Vector3 gamePos, Quaternion rot, string label)
        {
            var prefab = GoF2AssembledObject.LoadPrefab(db.AssemblyByName(assembly));
            if (prefab == null) return null;
            var go = Instantiate(prefab, GoF2OrbitLayout.ToUnity(gamePos), rot);
            go.name = label;
            return go;
        }

        // Level::createSpace / PlayerStation: at the origin, rotation (0, pi, 0) (= identity in Unity).
        void SpawnStation()
        {
            if (!Layout.hasStation && Layout.stationIndex != 110) return;   // 110 keeps its wreck in the empty orbit
            // PlayerStation::PlayerStation special cases (assemblies_stations_notes.md), before the campaign changes them.
            string name = Layout.stationIndex switch
            {
                100 => "v_station_deep_science",
                101 => "v_station_battlestation_anim",
                108 => "station_kaamo_club",
                109 or 110 => "sn_station_midorian_wrecked",
                111 => "sn_burning_station_luur",
                _ => null,
            };
            if (name == null)
            {
                string prefix = $"station_{Layout.stationIndex:000}_";
                var entry = db.Assemblies.Find(a => a.category == "stations" && (a.name.StartsWith(prefix)
                                                      || a.name.StartsWith("v_" + prefix) || a.name.StartsWith("sn_" + prefix)));
                name = entry != null ? entry.name : Layout.raceId == 1 ? "station_vossk" : null;   // Vossk: no collision entry
            }
            if (name == null) { Debug.LogWarning($"GoF2SpaceLevel: no station assembly for {Layout.stationIndex}"); return; }
            Spawn(name, Vector3.zero, GoF2OrbitLayout.RotationToUnity(new Vector3(0f, Mathf.PI, 0f)), "Station");
        }

        void SpawnJumpgate()
        {
            if (!Layout.hasJumpgate) return;
            Spawn(Layout.JumpgateAssembly, Layout.jumpgate, GoF2OrbitLayout.RotationToUnity(new Vector3(0f, Mathf.PI, 0f)), "Jumpgate");
        }

        // Level::createAsteroids / PlayerAsteroid (placement per visit with Unity's Random, like the original's
        // time-seeded part). The first 2..9 are big (cube +-30000, scale 1.2..2.19, no spin), the rest small
        // (cube +-50000, scale 0.3..0.99, 0.1 rad/s on random axes).
        void SpawnAsteroids()
        {
            var prefab = GoF2AssembledObject.LoadPrefab(db.AssemblyByName(Layout.AsteroidAssembly));
            if (prefab == null) return;
            var parent = new GameObject("Asteroids").transform;
            int big = Random.Range(2, 10);
            var bigPositions = new Vector3[big];
            for (int i = 0; i < Layout.asteroidCount; i++)
            {
                bool isBig = i < big;
                float side = isBig ? 60000f : 100000f;
                Vector3 pos;
                int tries = 0;
                do pos = Layout.asteroidCentre + new Vector3(Random.Range(-0.5f, 0.5f), Random.Range(-0.5f, 0.5f), Random.Range(-0.5f, 0.5f)) * side;
                while (isBig && ++tries < 30 && TooClose(pos, bigPositions, i));   // intended rule: big ones 8000 apart
                if (isBig) bigPositions[i] = pos;

                float scale = isBig ? Random.Range(120, 220) * 0.01f : Random.Range(30, 100) * 0.01f;
                var euler = new Vector3(Random.Range(0, 100), Random.Range(0, 100), Random.Range(0, 100)) * 0.01f * 2f * Mathf.PI;
                var go = Instantiate(prefab, GoF2OrbitLayout.ToUnity(pos), GoF2OrbitLayout.RotationToUnity(euler), parent);
                go.name = $"Asteroid {i}";
                go.transform.localScale = prefab.transform.localScale * scale;
                float spin = 1f - Mathf.Clamp(scale, 0.9f, 1f);   // 0.1 rad/s for small, none for big
                if (spin > 0f)
                {
                    var axes = new Vector3(Random.Range(-1, 2), Random.Range(-1, 2), Random.Range(-1, 2));
                    go.AddComponent<GoF2Spin>().degreesPerSecond = new Vector3(-axes.x, -axes.y, axes.z) * spin * Mathf.Rad2Deg;
                }
            }
        }

        static bool TooClose(Vector3 p, Vector3[] others, int count)
        {
            for (int j = 0; j < count; j++) if ((others[j] - p).sqrMagnitude < 8000f * 8000f) return true;
            return false;
        }

        // Level::createPlayer + the undock branch of Level::init.
        void SpawnPlayer()
        {
            var ship = db.Ships.Find(s => s.index == GoF2Session.ShipIndex);
            var root = new GameObject($"Player ({ship?.name})");
            root.transform.SetPositionAndRotation(
                GoF2OrbitLayout.ToUnity(GoF2OrbitLayout.UndockPosition),
                GoF2OrbitLayout.RotationToUnity(new Vector3(0f, (Random.value < 0.5f ? 1 : -1) * GoF2OrbitLayout.UndockYaw / 65536f * 2f * Mathf.PI, 0f)));
            var ctrl = root.AddComponent<GoF2ShipController>();
            var equipment = new System.Collections.Generic.List<ItemData>();
            foreach (int i in GoF2Session.Equipment) { var it = db.Items.Find(x => x.index == i); if (it != null) equipment.Add(it); }
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

            var chase = mainCamera.GetComponent<GoF2ChaseCamera>();
            if (chase == null) chase = mainCamera.gameObject.AddComponent<GoF2ChaseCamera>();
            chase.target = ctrl;
            // TargetFollowCamera offsets (game local) -> Unity local (-x, y, z) * 0.05.
            chase.offset = new Vector3(0f, 600f, -1338f) * M;
            chase.lookOffset = new Vector3(0f, 600f, -650f) * M;
            // CameraSetPerspective(1.22 rad) is the vertical FOV: with the level look offset the ship then sits in the
            // lower middle of the screen like in the original. Used as the 16:9 value (Hor+ on wider screens).
            chase.baseFov = 1.22f * Mathf.Rad2Deg;
            chase.Snap();
        }

        void SpawnDust()
        {
            var stars = new GameObject("SpaceDust").AddComponent<GoF2SpaceDust>();
            stars.Build(Resources.Load<Material>($"{GoF2Backdrop.MaterialFolder}/space_particle"), 500, 20f, 60f, Color.white, 10000f, 5000f, 2000f);
            var fog = new GameObject("SpaceFog").AddComponent<GoF2SpaceDust>();
            string fogTex = Layout.systemTexture == 12 ? "v_fog_ice" : "fog";
            fog.Build(Resources.Load<Material>($"{GoF2Backdrop.MaterialFolder}/{fogTex}"), 15, 10000f, 10000f, Layout.dustFogTint, 10000f, 5000f, 1000f);
        }
    }
}
