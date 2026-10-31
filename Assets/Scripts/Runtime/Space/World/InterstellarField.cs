// InterstellarField.cs
// Remake: what the space between the systems shows (Data.InterstellarSpace, added by SpaceLevel): each system on the star
// map as its sun, the map's own sun material on a quad kept inside the far plane and growing as the ship closes in, and
// the warp tunnel (Visuals.WarpTunnel) and a mod's warp.json sounds following the cruise drive.

using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.Modding;
using GoF2Remake.UI;
using GoF2Remake.Visuals;
using UnityEngine;

namespace GoF2Remake.World
{
    public class InterstellarField : MonoBehaviour
    {
        /// <summary>A sun's size in the space, and how small and large it may look (half its angle, radians).</summary>
        const float SunRadiusMeters = 600f, MinAngle = 0.012f, MaxAngle = 0.35f;
        /// <summary>The Khador flash fades into the open space over this long.</summary>
        const float EntryFadeMs = 900f;

        struct Sun { public Navigation.Target target; public Transform quad; }

        readonly List<Sun> suns = new List<Sun>();
        Navigation nav;
        ShipController ship;
        WarpTunnel tunnel;
        AudioSource loop, shot;
        AudioClip enterClip;
        float entryMs = EntryFadeMs;
        bool wasCruising;

        public void Setup(SpaceLevel level)
        {
            nav = level.Navigation;
            ship = level.Player;
            var materials = StarMapAssets.Load()?.sunMaterials;
            var mesh = Quad();
            foreach (var t in nav.Targets)
            {
                if (t.kind != Navigation.Kind.System) continue;
                var go = new GameObject("Sun " + t.name);
                go.transform.SetParent(transform, false);
                go.AddComponent<MeshFilter>().sharedMesh = mesh;
                var r = go.AddComponent<MeshRenderer>();
                int texture = level.Database.Systems.Find(s => s.index == t.system)?.textureIndex ?? 0;
                if (materials != null && materials.Length > 0) r.sharedMaterial = materials[texture >= 0 && texture < materials.Length ? texture : 0];
                r.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
                r.receiveShadows = false;
                suns.Add(new Sun { target = t, quad = go.transform });
            }
            tunnel = WarpTunnel.Spawn(transform);
            var warp = ModWarp.Current;
            if (warp == null) return;
            loop = gameObject.AddComponent<AudioSource>();
            loop.playOnAwake = false;
            loop.loop = true;
            shot = gameObject.AddComponent<AudioSource>();
            shot.playOnAwake = false;
            if (!string.IsNullOrEmpty(warp.loop)) ModAudio.Load(warp.mod, warp.loop, c => { if (this != null && loop != null) { loop.clip = c; loop.volume = 0f; if (c != null) loop.Play(); } }, false);
            if (!string.IsNullOrEmpty(warp.enter)) ModAudio.Load(warp.mod, warp.enter, c => enterClip = c, false);
        }

        static Mesh Quad()
        {
            var m = new Mesh { name = "InterstellarSun" };
            m.vertices = new[] { new Vector3(-1f, -1f), new Vector3(1f, -1f), new Vector3(-1f, 1f), new Vector3(1f, 1f) };
            m.uv = new[] { new Vector2(0f, 0f), new Vector2(1f, 0f), new Vector2(0f, 1f), new Vector2(1f, 1f) };
            m.triangles = new[] { 0, 2, 1, 1, 2, 3 };
            m.bounds = new Bounds(Vector3.zero, Vector3.one * 2f);
            return m;
        }

        void LateUpdate()
        {
            var cam = Camera.main;
            if (cam == null || ship == null) return;
            float inner = cam.farClipPlane * 0.5f;
            var eye = cam.transform.position;
            foreach (var s in suns)
            {
                bool shown = !s.target.hidden;
                if (s.quad.gameObject.activeSelf != shown) s.quad.gameObject.SetActive(shown);
                if (!shown) continue;
                var to = s.target.Position - eye;
                float distance = Mathf.Max(1f, to.magnitude), at = Mathf.Min(distance, inner);
                s.quad.SetPositionAndRotation(eye + to / distance * at, cam.transform.rotation);
                s.quad.localScale = Vector3.one * (at * Mathf.Clamp(SunRadiusMeters / distance, MinAngle, MaxAngle));
            }
            float dtMs = Time.deltaTime * 1000f;
            entryMs = Mathf.Max(0f, entryMs - dtMs);
            float drive = nav != null && nav.Drive != null ? nav.Drive.Level : 0f;
            float level = Mathf.Max(drive, entryMs / EntryFadeMs);
            if (tunnel != null) tunnel.Show(level, eye, ship.transform.rotation, dtMs);
            bool cruising = nav != null && nav.DriveCruising;
            if (cruising && !wasCruising && enterClip != null && shot != null) shot.PlayOneShot(enterClip, Settings.SfxVolume);
            wasCruising = cruising;
            if (loop != null) loop.volume = drive * Settings.SfxVolume;
        }
    }
}
