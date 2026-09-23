// GoF2OrbitBuilder.cs
// Turns a GoF2OrbitLayout into scene objects. Shared by the flight level (GoF2SpaceLevel) and the main menu
// background (GoF2MenuBackground), like the original, whose menu backdrop is a normal orbit level (Level type 2 in
// Level::createScene 0xc2910: createPlayer + an empty mission) built by the same Level::init code.
//   Level::createSpace      sky (GoF2/SpaceSky), station at the origin, jumpgate, sun/planets (GoF2Backdrop)
//   StarSystem::initLight   LIGHT0 toward the sun, LIGHT1 from the orbit planet (Unity +Z), skybox ambient, fog
//   Level::createAsteroids  asteroids around the seeded centre (per-visit placement with UnityEngine.Random)
//   initParticleSystems     space dust + fog sprites around the camera

using System;
using GoF2Remake.Data;
using GoF2Remake.Visuals;
using UnityEngine;
using UnityEngine.Rendering;
using Object = UnityEngine.Object;
using Random = UnityEngine.Random;

namespace GoF2Remake.World
{
    public static class GoF2OrbitBuilder
    {
        const float M = GoF2OrbitLayout.MetersPerUnit;

        // ---- sky, light, fog ---------------------------------------------------------------------------------

        public static void SetupSky(GoF2OrbitLayout layout, float ambientIntensity = 1f)
        {
            var template = Resources.Load<Material>("GoF2Sky/SpaceSky");
            if (template == null) { Debug.LogWarning("GoF2OrbitBuilder: run GoF2 > Bake Space Skies"); return; }
            var sky = new Material(template) { name = "SpaceSky (runtime)" };
            int stars = layout.systemIndex >= 0 ? layout.systemIndex % 3 : 2;   // alien/void: stars_002
            sky.SetTexture("_Stars", Resources.Load<Cubemap>($"GoF2Sky/stars_{stars:000}"));
            sky.SetTexture("_Nebula", Resources.Load<Cubemap>($"GoF2Sky/nebula_{layout.systemTexture:000}"));
            // The shader maps world directions into the baked cube: the inverse of the sky's Unity rotation.
            sky.SetMatrix("_SkyRotation", Matrix4x4.Rotate(Quaternion.Inverse(SkyRotation(layout))));
            RenderSettings.skybox = sky;
            RenderSettings.ambientMode = AmbientMode.Skybox;
            RenderSettings.ambientIntensity = ambientIntensity;
            RenderSettings.defaultReflectionMode = DefaultReflectionMode.Skybox;
            DynamicGI.UpdateEnvironment();

            RenderSettings.fog = layout.fog;
            if (layout.fog)
            {
                RenderSettings.fogMode = FogMode.Linear;
                RenderSettings.fogStartDistance = 0f;
                RenderSettings.fogEndDistance = layout.fogEnd * M;
                RenderSettings.fogColor = layout.fogColor;
            }
        }

        /// <summary>R_sky in Unity (the baked cubemaps are the sky meshes at identity, after the import's 180 deg yaw).</summary>
        public static Quaternion SkyRotation(GoF2OrbitLayout layout)
        {
            if (!layout.skySunAligned) return GoF2OrbitLayout.RotationToUnity(layout.skyEuler);
            // System 27: X = a x b, Y = a (toward the sun), Z = b with b = normalize((1,0,0) x a). Mirrored to Unity
            // (S * R * S) the Z column flips sign: Y' = S a, Z' = -S b.
            var a = GoF2OrbitLayout.DirToUnity(layout.lightDirection).normalized;
            var b = GoF2OrbitLayout.DirToUnity(Vector3.Cross(Vector3.right, layout.lightDirection)).normalized;
            return Quaternion.LookRotation(-b, a) * Quaternion.Euler(0f, 180f, 0f);
        }

        /// <param name="sunIntensityAt2">URP intensity for the original's LIGHT0 diffuse of 2.0 (tuned, not recovered).</param>
        public static void SetupLights(GoF2OrbitLayout layout, Light sun, Light planet, float sunIntensityAt2 = 1.6f, float planetIntensity = 1f)
        {
            if (sun != null)
            {
                var toSun = GoF2OrbitLayout.DirToUnity(layout.lightDirection).normalized;
                sun.transform.rotation = Quaternion.LookRotation(-toSun);
                var c = layout.SunLightColor;   // 0..2 per channel, 2 for most systems
                float max = Mathf.Max(c.r, Mathf.Max(c.g, c.b), 1e-3f);
                sun.color = c / max;
                sun.intensity = sunIntensityAt2 * max / 2f;
            }
            if (planet != null)
            {
                // LIGHT1 direction (0, 0, -1) game = toward the orbit planet (Unity +Z); light travels toward -Z.
                planet.transform.rotation = Quaternion.LookRotation(Vector3.back);
                planet.color = layout.planetLightColor;
                planet.intensity = planetIntensity;
            }
        }

        // ---- objects -----------------------------------------------------------------------------------------

        static GameObject Spawn(GoF2Database db, string assembly, Vector3 gamePos, Quaternion rot, string label, Transform parent)
        {
            var prefab = GoF2AssembledObject.LoadPrefab(db.AssemblyByName(assembly));
            if (prefab == null) return null;
            var go = Object.Instantiate(prefab, GoF2OrbitLayout.ToUnity(gamePos), rot, parent);
            go.name = label;
            return go;
        }

        /// <summary>Assembly name of a station (PlayerStation::PlayerStation, assemblies_stations_notes.md), null if none.</summary>
        public static string StationAssembly(GoF2Database db, GoF2OrbitLayout layout)
        {
            // Special cases, as they are before the campaign changes them.
            switch (layout.stationIndex)
            {
                case 100: return "v_station_deep_science";
                case 101: return "v_station_battlestation_anim";
                case 108: return "station_kaamo_club";
                case 109: case 110: return "sn_station_midorian_wrecked";
                case 111: return "sn_burning_station_luur";
            }
            string prefix = $"station_{layout.stationIndex:000}_";
            var entry = db.Assemblies.Find(a => a.category == "stations" && (a.name.StartsWith(prefix)
                                                  || a.name.StartsWith("v_" + prefix) || a.name.StartsWith("sn_" + prefix)));
            return entry != null ? entry.name : layout.raceId == 1 ? "station_vossk" : null;   // Vossk: no collision entry
        }

        /// <summary>Level::createSpace / PlayerStation: at the origin, rotation (0, pi, 0) (= identity in Unity).</summary>
        public static GameObject SpawnStation(GoF2Database db, GoF2OrbitLayout layout, Transform parent = null)
        {
            if (!layout.hasStation && layout.stationIndex != 110) return null;   // 110 keeps its wreck in the empty orbit
            string name = StationAssembly(db, layout);
            if (name == null) { Debug.LogWarning($"GoF2OrbitBuilder: no station assembly for {layout.stationIndex}"); return null; }
            return Spawn(db, name, Vector3.zero, GoF2OrbitLayout.RotationToUnity(new Vector3(0f, Mathf.PI, 0f)), "Station", parent);
        }

        public static GameObject SpawnJumpgate(GoF2Database db, GoF2OrbitLayout layout, Transform parent = null)
        {
            if (!layout.hasJumpgate) return null;
            return Spawn(db, layout.JumpgateAssembly, layout.jumpgate, GoF2OrbitLayout.RotationToUnity(new Vector3(0f, Mathf.PI, 0f)), "Jumpgate", parent);
        }

        /// <summary>
        /// Level::createAsteroids / PlayerAsteroid. The first 2..9 are big (cube +-30000, scale 1.2..2.19, no spin), the
        /// rest small (cube +-50000, scale 0.3..0.99, 0.1 rad/s on random axes). 'reject' (Unity position) re-rolls a
        /// spot, e.g. to keep the menu camera's orbit clear.
        /// </summary>
        public static Transform SpawnAsteroids(GoF2Database db, GoF2OrbitLayout layout, Transform parent = null, Func<Vector3, bool> reject = null)
        {
            var prefab = GoF2AssembledObject.LoadPrefab(db.AssemblyByName(layout.AsteroidAssembly));
            var explosion = GoF2AssembledObject.LoadPrefab(db.AssemblyByName(layout.AsteroidAssembly + "_explosion_anim"));
            var destroyedSound = GoF2Remake.Flight.GoF2CombatAudio.Load()?.asteroidDestroyed;
            var root = new GameObject("Asteroids").transform;
            root.SetParent(parent, false);
            if (prefab == null) return root;
            int big = Random.Range(2, 10);
            var bigPositions = new Vector3[big];
            for (int i = 0; i < layout.asteroidCount; i++)
            {
                bool isBig = i < big;
                float side = isBig ? 60000f : 100000f;
                Vector3 pos;
                int tries = 0;
                bool bad;
                do
                {
                    pos = layout.asteroidCentre + new Vector3(Random.Range(-0.5f, 0.5f), Random.Range(-0.5f, 0.5f), Random.Range(-0.5f, 0.5f)) * side;
                    bad = (isBig && TooClose(pos, bigPositions, i))   // intended rule: big ones 8000 apart
                          || (reject != null && reject(GoF2OrbitLayout.ToUnity(pos)));
                } while (bad && ++tries < 40);
                if (bad && reject != null) continue;   // no valid spot: leave it out rather than block the view
                if (isBig) bigPositions[i] = pos;

                float scale = isBig ? Random.Range(120, 220) * 0.01f : Random.Range(30, 100) * 0.01f;
                var euler = new Vector3(Random.Range(0, 100), Random.Range(0, 100), Random.Range(0, 100)) * 0.01f * 2f * Mathf.PI;
                var go = Object.Instantiate(prefab, GoF2OrbitLayout.ToUnity(pos), GoF2OrbitLayout.RotationToUnity(euler), root);
                go.name = $"Asteroid {i}";
                go.transform.localScale = prefab.transform.localScale * scale;
                // PlayerAsteroid: hit radius = meshRadius * scale * 0.7, HP = scale * 100 + 30.
                var target = go.AddComponent<GoF2Remake.Flight.GoF2Target>();
                target.isAsteroid = true;
                target.radius = layout.AsteroidMeshRadius * scale * 0.7f * M;
                target.maxHp = target.hp = scale * 100f + 30f;
                target.explosionPrefab = explosion;
                target.explosionScale = scale;
                target.destroyedSound = destroyedSound;
                float spin = 1f - Mathf.Clamp(scale, 0.9f, 1f);   // 0.1 rad/s for small, none for big
                if (spin > 0f)
                {
                    var axes = new Vector3(Random.Range(-1, 2), Random.Range(-1, 2), Random.Range(-1, 2));
                    go.AddComponent<GoF2Spin>().degreesPerSecond = new Vector3(-axes.x, -axes.y, axes.z) * spin * Mathf.Rad2Deg;
                }
            }
            return root;
        }

        static bool TooClose(Vector3 p, Vector3[] others, int count)
        {
            for (int j = 0; j < count; j++) if ((others[j] - p).sqrMagnitude < 8000f * 8000f) return true;
            return false;
        }

        /// <summary>SET_STARS + SET_FOG around the camera (Level::initParticleSystems 0xcc990).</summary>
        public static void SpawnDust(GoF2OrbitLayout layout, Transform parent = null)
        {
            var stars = new GameObject("SpaceDust").AddComponent<GoF2SpaceDust>();
            stars.transform.SetParent(parent, false);
            stars.Build(Resources.Load<Material>($"{GoF2Backdrop.MaterialFolder}/space_particle"), 500, 20f, 60f, Color.white, 10000f, 5000f, 2000f);
            var fog = new GameObject("SpaceFog").AddComponent<GoF2SpaceDust>();
            fog.transform.SetParent(parent, false);
            string fogTex = layout.systemTexture == 12 ? "v_fog_ice" : "fog";
            fog.Build(Resources.Load<Material>($"{GoF2Backdrop.MaterialFolder}/{fogTex}"), 15, 10000f, 10000f, layout.dustFogTint, 10000f, 5000f, 1000f);
        }

        public static GoF2Backdrop SpawnBackdrop(GoF2OrbitLayout layout, Camera camera, Transform parent = null)
        {
            var backdrop = new GameObject("Backdrop").AddComponent<GoF2Backdrop>();
            backdrop.transform.SetParent(parent, false);
            backdrop.Build(layout, camera);
            return backdrop;
        }
    }
}
