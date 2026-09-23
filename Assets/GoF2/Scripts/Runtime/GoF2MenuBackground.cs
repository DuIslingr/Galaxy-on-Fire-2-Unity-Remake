// GoF2MenuBackground.cs
// The main menu backdrop. Like ModMainMenu::OnInitialize, it picks a random station at start
// (Galaxy::getStation(rnd.nextInt(100))) and shows it in its own system's sky; here the choice is from a
// curated set of stations, each paired with its system's skybox index (systems.json textureIndex).

using System;
using UnityEngine;
using UnityEngine.Rendering;

namespace GoF2Remake.Visuals
{
    public class GoF2MenuBackground : MonoBehaviour
    {
        [Serializable]
        public class Setup
        {
            public string label;
            public GameObject station;
            [Tooltip("systems.json textureIndex of the station's system (skybox_0XX).")]
            public int skybox;
            [Tooltip("Degrees to turn the station so a lit side faces the camera path.")]
            public float yaw;
        }

        public Setup[] setups;
        public GoF2MenuCamera menuCamera;

        [Tooltip("Skybox materials (Skyboxes/skybox_0XX.mat, baked by GoF2 > Bake Skyboxes), indexed by skybox number.")]
        public Material[] skyboxes;

        [Tooltip("Children are spread around the station outside the camera orbit, scaled to the station size.")]
        public Transform asteroidField;

        [Tooltip("-1 = random (the original behaviour).")]
        public int forceSetup = -1;

        public GameObject Station { get; private set; }

        void Awake()
        {
            if (setups == null || setups.Length == 0) return;
            int i = forceSetup >= 0 && forceSetup < setups.Length ? forceSetup : UnityEngine.Random.Range(0, setups.Length);
            var s = setups[i];

            if (s.station != null)
            {
                Station = Instantiate(s.station, transform.position, Quaternion.Euler(0f, s.yaw, 0f), transform);
                // The menu shows the full-detail station at every distance, like this build of the game.
                foreach (var lg in Station.GetComponentsInChildren<LODGroup>()) lg.enabled = false;
                if (menuCamera != null)
                {
                    menuCamera.target = Station.transform;
                    var b = Bounds(Station);
                    menuCamera.lookOffset = Station.transform.InverseTransformPoint(b.center);
                    menuCamera.distance = b.extents.magnitude * 2.6f;
                    menuCamera.height = b.extents.y * 0.35f;
                    menuCamera.bobAmplitude = b.extents.y * 0.12f;
                }
                PlaceAsteroids(Bounds(Station), menuCamera != null ? menuCamera.distance : 4000f);
            }

            if (skyboxes != null && s.skybox >= 0 && s.skybox < skyboxes.Length && skyboxes[s.skybox] != null)
            {
                // The skybox also lights the scene: ambient and reflections come from the nebula.
                RenderSettings.skybox = skyboxes[s.skybox];
                RenderSettings.ambientMode = AmbientMode.Skybox;
                RenderSettings.defaultReflectionMode = DefaultReflectionMode.Skybox;
                DynamicGI.UpdateEnvironment();
            }
        }

        void PlaceAsteroids(Bounds station, float orbit)
        {
            if (asteroidField == null) return;
            var rnd = new System.Random(asteroidField.childCount * 7919);
            float R(float a, float b) => a + (float)rnd.NextDouble() * (b - a);
            foreach (Transform a in asteroidField)
            {
                // Beyond the camera orbit so none of them ever fills the view; a few flat, most above/below.
                float ang = R(0f, 360f) * Mathf.Deg2Rad, dist = orbit * R(1.35f, 2.6f);
                a.position = station.center + new Vector3(Mathf.Cos(ang) * dist, orbit * R(-0.45f, 0.45f), Mathf.Sin(ang) * dist);
                a.localScale = Vector3.one * orbit * R(0.00015f, 0.0005f);   // prefab is ~200 m: 3-10% of the orbit
            }
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
