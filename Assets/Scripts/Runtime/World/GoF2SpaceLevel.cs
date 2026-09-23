// GoF2SpaceLevel.cs
// Builds the flight level for the current station orbit at startup, like Level::init 0xbb49c (two passes) and
// MGame::reset 0x1a793c: one level = one station orbit; the other stations of the system only appear as planets.
// The world itself (sky, lights, station, jumpgate, asteroids, dust, sun/planets) comes from GoF2OrbitBuilder,
// which the main menu background uses too. This adds the flight parts:
//   createPlayer:  player ship at (10, 10, 10000) facing away from the station (+-8.8 deg), speed 2 u/ms
//   MGame::reset:  camera fov 1.22 rad, near 20, far 300000 units; chase offsets (0, 600, -1338) / (0, 600, -650)
// Not yet: traffic (Level::createMission), missions, docking, travel, HUD, lens flare, wormhole.

using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.Visuals;
using UnityEngine;

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

            GoF2OrbitBuilder.SetupSky(Layout, ambientIntensity);
            GoF2OrbitBuilder.SetupLights(Layout, sunLight, planetLight, sunIntensityAt2, planetLightIntensity);
            SetupCamera();
            GoF2OrbitBuilder.SpawnStation(db, Layout);
            GoF2OrbitBuilder.SpawnJumpgate(db, Layout);
            GoF2OrbitBuilder.SpawnAsteroids(db, Layout);
            SpawnPlayer();
            GoF2OrbitBuilder.SpawnDust(Layout);
            GoF2OrbitBuilder.SpawnBackdrop(Layout, mainCamera);
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
    }
}
