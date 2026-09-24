// Backdrop.cs
// Sun, planets, planet rings and the sun streak of the current orbit (StarSystem::render 0x15db84,
// renderSunStreak). They are quads on the original's `plane` (65000 units wide) kept 20000 units (1000 m) from the
// camera every frame, so they stay at infinity; the GoF2/Backdrop shader draws them behind all geometry.
//   Sun: additive, faces the camera with the camera's up, swells by e = max((I - 10) / 64, 0) where I is the lens
//        flare intensity 64 * (1 - d / (H / 2)) (d = sun distance from the screen centre in pixels).
//   Streak: the sun texture stretched horizontally by e (invisible when the sun is off-centre).
//   Planets: fixed orientation (not billboards), alpha blended, mirrored so the lit rim faces the sun; the orbit
//        planet (straight ahead, Unity +Z) grows up to +0.2 scale as the camera flies toward it.
//   Rings: the planet's quad x4 with sn_planet_ring.
// Materials come from Resources/GoF2Backdrop/<texture> (made by GoF2 > Create Space Scene), so only the current
// orbit's textures are loaded.

using System.Collections.Generic;
using UnityEngine;

namespace GoF2Remake.World
{
    public class Backdrop : MonoBehaviour
    {
        public const string MaterialFolder = "GoF2Backdrop";
        const float Distance = OrbitLayout.BackdropDistance * OrbitLayout.MetersPerUnit;   // 1000 m
        const float QuadMeters = OrbitLayout.PlaneSize * OrbitLayout.MetersPerUnit;        // 3250 m at scale 1

        [Tooltip("HDR multiplier on the sun so it blooms.")]
        public float sunGlow = 1.6f;

        class Body
        {
            public Transform t;
            public Vector3 dir;          // Unity direction from the camera
            public Quaternion rot;       // fixed orientation (planets)
            public float scale;
            public bool orbitPlanet;
        }

        Camera cam;
        OrbitLayout layout;
        Body sun, streak;
        readonly List<Body> planets = new List<Body>();

        /// <summary>StarSystem::getPlanetTargets: one per planet billboard with its station (the orbit planet = the current
        /// station's own, never lockable). The transforms follow the camera, 1000 m out.</summary>
        public readonly List<(int station, Transform transform, bool orbitPlanet)> PlanetTargets = new List<(int, Transform, bool)>();
        readonly List<Body> rings = new List<Body>();
        float flareIntensity;
        static Mesh quad;

        public void Build(OrbitLayout orbit, Camera camera)
        {
            layout = orbit;
            cam = camera;
            var sunDir = OrbitLayout.DirToUnity(orbit.lightDirection).normalized;
            var sunMat = Load(orbit.sunTexture);
            sun = Make("Sun", sunMat, 2900, sunDir, Quaternion.identity, orbit.sunScale);
            streak = Make("SunStreak", sunMat, 2903, sunDir, Quaternion.identity, 0f);
            foreach (var r in new[] { sun.t, streak.t })
            {
                var block = new MaterialPropertyBlock();
                block.SetColor("_Color", Color.white * sunGlow);
                r.GetComponent<MeshRenderer>().SetPropertyBlock(block);
            }

            Color tint = orbit.fog ? (orbit.systemTexture == 15 ? orbit.fogColor : orbit.fogColor * 0.7f) : Color.clear;
            var ringMat = orbit.planets.Exists(p => p.ring) ? Load("sn_planet_ring") : null;
            foreach (var p in orbit.planets)
            {
                // StarSystem: rotation (pitch, yaw, 0) then moveForward(-20000), a quad facing the origin.
                var gameDir = OrbitLayout.Direction(p.pitch, p.yaw);
                var dir = OrbitLayout.DirToUnity(-gameDir).normalized;
                var up = OrbitLayout.DirToUnity(new Vector3(0f, Mathf.Cos(p.pitch), Mathf.Sin(p.pitch)));
                var rot = Quaternion.LookRotation(dir, up);
                // The planet PNGs have their lit rim on the right: mirror when the sun is on the left as seen.
                bool mirror = Vector3.Dot(sunDir, rot * Vector3.right) < 0f;
                var body = Make(p.texture, Load(p.texture), 2901, dir, rot, p.scale);
                body.orbitPlanet = p.isOrbitPlanet;
                SetProps(body.t, mirror, tint);
                planets.Add(body);
                PlanetTargets.Add((p.station, body.t, p.isOrbitPlanet));
                if (p.ring && ringMat != null)
                {
                    var ring = Make(p.texture + "_ring", ringMat, 2902, dir, rot, p.scale * 4f);
                    SetProps(ring.t, mirror, Color.clear);
                    rings.Add(ring);
                }
            }
        }

        /// <summary>StarSystem::switchPlanetForIntro 0x15d820 (the prologue's time jump): the orbit planet gets planet_000_big
        /// and twice its size.</summary>
        public void SwitchOrbitPlanetForIntro()
        {
            var mat = Load("planet_000_big");
            foreach (var p in planets)
            {
                if (!p.orbitPlanet) continue;
                if (mat != null) p.t.GetComponent<MeshRenderer>().sharedMaterial = mat;
                p.scale *= 2f;
            }
        }

        static void SetProps(Transform t, bool mirror, Color tint)
        {
            var block = new MaterialPropertyBlock();
            block.SetFloat("_Mirror", mirror ? 1f : 0f);
            block.SetColor("_Tint", tint);
            t.GetComponent<MeshRenderer>().SetPropertyBlock(block);
        }

        static Material Load(string texture)
        {
            var m = Resources.Load<Material>($"{MaterialFolder}/{texture}");
            if (m == null) Debug.LogWarning($"Backdrop: missing material Resources/{MaterialFolder}/{texture}");
            return m;
        }

        Body Make(string name, Material mat, int queue, Vector3 dir, Quaternion rot, float scale)
        {
            var go = new GameObject(name);
            go.transform.SetParent(transform, false);
            go.AddComponent<MeshFilter>().sharedMesh = Quad;
            var r = go.AddComponent<MeshRenderer>();
            r.sharedMaterial = mat;
            r.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
            r.receiveShadows = false;
            r.lightProbeUsage = UnityEngine.Rendering.LightProbeUsage.Off;
            r.reflectionProbeUsage = UnityEngine.Rendering.ReflectionProbeUsage.Off;
            if (mat != null && mat.renderQueue != queue) r.material.renderQueue = queue;   // painter's order
            return new Body { t = go.transform, dir = dir, rot = rot, scale = scale };
        }

        static Mesh Quad
        {
            get
            {
                if (quad != null) return quad;
                quad = new Mesh { name = "BackdropQuad" };
                quad.vertices = new[] { new Vector3(-0.5f, -0.5f, 0f), new Vector3(0.5f, -0.5f, 0f), new Vector3(0.5f, 0.5f, 0f), new Vector3(-0.5f, 0.5f, 0f) };
                quad.uv = new[] { new Vector2(0f, 0f), new Vector2(1f, 0f), new Vector2(1f, 1f), new Vector2(0f, 1f) };
                quad.triangles = new[] { 0, 2, 1, 0, 3, 2 };
                quad.bounds = new Bounds(Vector3.zero, Vector3.one * 1e5f);   // never frustum-culled by its own size
                return quad;
            }
        }

        void LateUpdate()
        {
            if (cam == null || sun == null) return;
            var c = cam.transform.position;

            // Lens flare intensity (StarSystem::render2D): from the sun's screen position, used for the swelling.
            flareIntensity = 0f;
            var sp = cam.WorldToScreenPoint(c + sun.dir * Distance);
            if (sp.z > 0f)
            {
                float d = Vector2.Distance(new Vector2(sp.x, sp.y), new Vector2(Screen.width * 0.5f, Screen.height * 0.5f));
                flareIntensity = 64f * (1f - d / (Screen.height * 0.5f));
            }
            float e = Mathf.Max((flareIntensity - 10f) / 64f, 0f);

            float s = layout.sunScale;
            var sunRot = Quaternion.LookRotation(sun.dir, cam.transform.up);
            Place(sun, c, sunRot, new Vector3(s + e, s + e, 1f));
            // renderSunStreak: the scaled sun matrix scaled again by (e * (s + e + 1), s / ((1 - e) * 6 + 6)).
            Place(streak, c, sunRot, new Vector3((s + e) * e * (s + e + 1f), (s + e) * s / ((1f - e) * 6f + 6f), 1f));
            streak.t.gameObject.SetActive(e > 0f);

            // getPlanetScaleFactor: f = clamp(camera game z / -800000, -0.2, 0.2) (game z = -Unity z / 0.05).
            float gameZ = -c.z / OrbitLayout.MetersPerUnit;
            float zoom = Mathf.Clamp(gameZ / -800000f, -0.2f, 0.2f);
            foreach (var p in planets)
            {
                float k = p.orbitPlanet ? p.scale + zoom : p.scale;
                Place(p, c, p.rot, Vector3.one * k);
            }
            foreach (var r in rings) Place(r, c, r.rot, Vector3.one * r.scale);
        }

        static void Place(Body b, Vector3 camPos, Quaternion rot, Vector3 scale)
        {
            b.t.SetPositionAndRotation(camPos + b.dir * Distance, rot);
            b.t.localScale = scale * QuadMeters;
        }
    }
}
