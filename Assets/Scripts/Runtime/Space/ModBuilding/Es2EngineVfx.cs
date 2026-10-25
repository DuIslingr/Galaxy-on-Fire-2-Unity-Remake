// Es2EngineVfx.cs
// Remake mods: EVERSPACE 2's engine effects beside the flames on a ship with them (a kit's "flame" materials: the ES2
// importer's ships), at its engine sockets (exhaust mounts, slotType 3) and booster sockets (slotType 5), each sized by the
// socket's scale (WeaponMount.socketScale), as EVERSPACE 2 spawns and drives them (2026-10-24, decompiled: BP_ShipBase's
// InitializeEngineVFX / UpdateEngineVFX, BP_Ship_Player's engine lights, the Niagara systems' VM scripts and their materials'
// compiled shaders; the ES2 importer's research/engine_exhaust.md). The inputs are EngineFlame's (EVERSPACE 2's
// ThrustAmount = the linear thrust's forward part, BoostAmount); a booster socket's effects take Boost x Thrust.
// The player's ship (BP_Ship_Player, EngineFlame.Pilot):
// - its veil trails (NS_Vehicle_EngineTrail_Player_Default, the "Default" engine trail): a ribbon per socket of particles born
//   50 a second while its opacity (Thrust, a booster's Boost x Thrust) is above 0, 1 m ahead of the socket (inside the
//   nozzle), in the ship's own frame, moving backward at 25 m/s and easing toward standing still in the world by
//   1 - 0.5^(0.4 dt) a frame (InheritVelocityFalloffTime 0.4, smoothing 0.5); 0.44 s of life (BaseLifetime 0.4 x 1.1);
//   50 cm wide; the socket's colour (EngineColor / BoosterColor) x 5, alpha 0.05 x (1 + cos(pi age / life)) / 2 x the opacity
//   now; drawn with M_Vehicle_EngineTrail_Player_Veil (GoF2/ModEs2Particle kind 4);
// - its engine lights (CreateEngineLight): a point light per socket in the socket's colour, radius 300 cm x the socket's
//   scale, EngineVFXLightIntensity 20 x the thrust (a booster's: x the boost) (here x LightGain: the exposures differ);
// - no engine glow (SpawnEngineGlow false).
// Any other ship (NS_Vehicle_EngineTrail):
// - its engine glow (NE_Glow): a camera-facing sprite 100 m x the socket's scale, the colour x 3 (x 0.5 but a booster's),
//   alpha 0.5 x the thrust (a booster's: the boost) (GoF2/ModEs2Particle kind 2);
// - its trail (Trail_0, M_ShipTrail_001): a world-space ribbon of points dropped every 10 m flown (SpawnPerUnit 1000 cm), each
//   living 2 s x the socket's scale, 5 m x its scale wide, the colour (x 0.5 but a booster's) with alpha the thrust (a
//   booster's: the boost) x pow(sat(velocity^ . forward), 32) when dropped: only flying nose first (kind 3). Remake pick:
//   the live socket is the ribbon's head, so it reaches the engine between drops.
// A ship's blueprint can switch the glow and the trails off (SpawnEngineGlow / SpawnEngineTrails, or EngineVFXEnabled for
// both; ships.json "es2Engine"): EVERSPACE 2's warships and freighters have them off, their engines only their nozzles' glow.
// EVERSPACE 2's centimetres are its metres x the kit's scale here (es2Scale). Nothing of it in the docked station (the
// flames do the hangar's engines).

using System.Collections.Generic;
using System.Linq;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using UnityEngine;
using UnityEngine.Rendering;

namespace GoF2Remake.Modding
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public class Es2EngineVfx : MonoBehaviour
    {
        // the veil (NS_Vehicle_EngineTrail_Player_Default, NPC_EngineTrails_Player), EVERSPACE 2 metres and seconds
        const float VeilRate = 50f, VeilLife = 0.4f * 1.1f, VeilSpeed = -25f, VeilAhead = 1f, VeilHalfWidth = 0.25f;
        const float VeilColour = 5f, VeilAlpha = 0.05f, VeilFalloffTime = 0.4f, VeilSmoothing = 0.5f, VeilInheritLimit = 200f;
        // the NPC glow and trail (NS_Vehicle_EngineTrail)
        const float GlowHalf = 50f, GlowColour = 3f, GlowAlpha = 0.5f;
        const float TrailSpacing = 10f, TrailLife = 2f, TrailHalfWidth = 2.5f, TrailTile = 50f, TrailAlignPower = 32f;
        // the engine lights (CreateEngineLight)
        const float LightRadius = 3f, LightIntensity = 20f;
        /// <summary>EVERSPACE 2's light intensity to URP's (its exposure against the remake's; matched by eye).</summary>
        public static float LightGain = 0.08f;

        static Shader shader;
        static bool shaderLoaded;
        /// <summary>GoF2/ModEs2Particle (Resources/GoF2Mods).</summary>
        public static Shader Shader
        {
            get
            {
                if (!shaderLoaded) { shaderLoaded = true; shader = Resources.Load<Shader>("GoF2Mods/ModEs2Particle"); }
                return shader;
            }
        }

        [System.Serializable]
        struct Socket { public Vector3 at; public float scale; public bool booster; }
        [SerializeField] Socket[] sockets = new Socket[0];
        [SerializeField] float es2Scale = 1f;
        [SerializeField] bool glowOn = true, trailsOn = true;

        struct Particle { public Vector3 pos, vel; public float age, alpha, u; }
        class Trail
        {
            public readonly List<Particle> points = new List<Particle>();
            public float spawnDue;     // the veil: particles owed; the NPC trail: distance flown since the last drop
            public Vector3 last;       // the NPC trail: the socket's world position last frame
            public bool hasLast;
        }

        EngineFlame flame;
        Trail[] trails;
        MeshFilter veil, glow, npcTrail;
        Light[] lights;
        Color engineColour = Color.white, boosterColour = Color.white;
        bool ready, inStation;
        readonly List<Vector3> v = new List<Vector3>(), n = new List<Vector3>();
        readonly List<Vector2> uv = new List<Vector2>(), uv1 = new List<Vector2>();
        readonly List<Color> col = new List<Color>();
        readonly List<int> tri = new List<int>();

        /// <summary>Adds the effects for a ship template's engine (slotType 3) and booster (slotType 5) sockets (none: nothing).
        /// 'es2Scale' is Unity metres per EVERSPACE 2 metre (the kit's scale); 'effects' which of them the ship shows (null: all).</summary>
        public static void Add(GameObject root, IEnumerable<WeaponMount> mounts, float es2Scale, CustomEs2Engine effects = null)
        {
            var list = mounts?.Where(m => m != null && (m.slotType == 3 || m.slotType == 5)).ToList();
            if (list == null || list.Count == 0 || Shader == null) return;
            var c = root.AddComponent<Es2EngineVfx>();
            c.es2Scale = es2Scale > 0f ? es2Scale : 1f;
            c.glowOn = effects == null || effects.glow;
            c.trailsOn = effects == null || effects.trails;
            c.sockets = list.Select(m => new Socket { at = WeaponSystem.MountToLocal(m), scale = m.socketScale > 0f ? m.socketScale : 1f, booster = m.slotType == 5 }).ToArray();
        }

        void OnEnable()
        {
            inStation = FindAnyObjectByType<World.StationLevel>() != null;
            if (trails != null) foreach (var t in trails) { t.points.Clear(); t.hasLast = false; t.spawnDue = 0f; }
        }

        void OnDestroy()
        {
            foreach (var mf in new[] { veil, glow, npcTrail })
                if (mf != null) { Destroy(mf.sharedMesh); Destroy(mf.GetComponent<Renderer>().sharedMaterial); }
        }

        void Setup()
        {
            ready = true;
            flame = GetComponent<EngineFlame>();
            trails = sockets.Select(_ => new Trail()).ToArray();
            // the socket colours: the flames' own (EngineColor, BoosterColor; a kit's colour slots set them)
            foreach (var r in GetComponentsInChildren<Renderer>(true))
            {
                var f = r.sharedMaterials.FirstOrDefault(EngineFlame.IsFlame);
                if (f == null || ModExhausts.InHolder(r.transform)) continue;
                engineColour = f.GetColor("_EmissionColor");
                boosterColour = f.GetColor("_BoostColor");
                break;
            }
            veil = Part("es2_engine_veil", 4, true);
            glow = Part("es2_engine_glow", 2, false);
            npcTrail = Part("es2_engine_trail", 3, false);
        }

        MeshFilter Part(string name, int kind, bool alphaBlend)
        {
            var go = new GameObject(name);
            go.transform.SetParent(transform, false);
            var mf = go.AddComponent<MeshFilter>();
            // ("_add": the hull collision, shadows, levels of detail and aim spots skip it like the game's additive layers;
            // its corners all at the anchor, PhysX failed to "clean" it)
            mf.sharedMesh = new Mesh { name = name + "_add" };
            mf.sharedMesh.MarkDynamic();
            var r = go.AddComponent<MeshRenderer>();
            var mat = new Material(Shader) { name = name };
            mat.SetFloat("_Kind", kind);
            mat.SetFloat("_Gain", ModMaterials.Es2FlameGain / 1000f);
            mat.SetFloat("_Es2Scale", es2Scale);
            mat.SetFloat("_SrcBlend", alphaBlend ? (float)BlendMode.SrcAlpha : (float)BlendMode.One);
            mat.SetFloat("_DstBlend", alphaBlend ? (float)BlendMode.OneMinusSrcAlpha : (float)BlendMode.One);
            r.sharedMaterial = mat;
            r.shadowCastingMode = ShadowCastingMode.Off;
            r.receiveShadows = false;
            r.enabled = false;
            return mf;
        }

        Color ColourOf(int i) => sockets[i].booster ? boosterColour : engineColour;

        /// <summary>EVERSPACE 2's opacity input at a socket: ThrustAmount, a booster's BoostAmount x ThrustAmount.</summary>
        float Opacity(int i, float thrust, float boost) => sockets[i].booster ? boost * thrust : thrust;

        void LateUpdate()
        {
            if (!ready) Setup();
            if (flame == null || sockets.Length == 0) return;
            float dt = Time.deltaTime;
            bool pilot = flame.Pilot && !inStation;
            float thrust = inStation ? 0f : Mathf.Max(0f, flame.Thrust.z), boost = inStation ? 0f : flame.Boost;
            UpdateVeils(pilot && trailsOn, dt, thrust, boost);
            UpdateLights(pilot, thrust, boost);
            UpdateGlow(!pilot && !inStation && glowOn, thrust, boost);
            UpdateNpcTrails(!pilot && !inStation && trailsOn, dt, thrust, boost);
        }

        // ---- the veil ---------------------------------------------------------------------------------------------------
        void UpdateVeils(bool on, float dt, float thrust, float boost)
        {
            BeginMesh();
            float s = es2Scale;
            var ownerVel = transform.InverseTransformDirection(flame.Velocity);
            var inherit = -Vector3.ClampMagnitude(ownerVel, VeilInheritLimit);
            float ease = 1f - Mathf.Pow(VeilSmoothing, dt * VeilFalloffTime);
            for (int i = 0; i < sockets.Length; i++)
            {
                var t = trails[i];
                float opacity = on ? Opacity(i, thrust, boost) : 0f;
                // age, move and drop the particles (local space: the ship's frame)
                for (int k = t.points.Count - 1; k >= 0; k--)
                {
                    var p = t.points[k];
                    p.age += dt;
                    if (p.age >= VeilLife || !on) { t.points.RemoveAt(k); continue; }
                    p.vel = Vector3.Lerp(p.vel, inherit, ease);
                    p.pos += p.vel * dt;
                    t.points[k] = p;
                }
                if (opacity > 0f)
                {
                    t.spawnDue += VeilRate * dt;
                    var start = sockets[i].at + Vector3.forward * VeilAhead * s;
                    while (t.spawnDue >= 1f)
                    {
                        t.spawnDue -= 1f;
                        // (spread over the frame like the interpolated spawn: the oldest of this frame's births first)
                        float age = t.spawnDue / VeilRate;
                        var vel = new Vector3(0f, 0f, VeilSpeed * s);
                        t.points.Add(new Particle { pos = start + vel * age, vel = vel, age = age });
                    }
                }
                else t.spawnDue = 0f;
                if (t.points.Count < 2) continue;
                // newest first: the ribbon's u runs 0 at the nozzle to 1 at its end, by length
                t.points.Sort((a, b) => a.age.CompareTo(b.age));
                var c = ColourOf(i) * VeilColour;
                float total = 0f;
                for (int k = 1; k < t.points.Count; k++) total += Vector3.Distance(t.points[k].pos, t.points[k - 1].pos);
                float run = 0f;
                int first = v.Count;
                for (int k = 0; k < t.points.Count; k++)
                {
                    var p = t.points[k];
                    if (k > 0) run += Vector3.Distance(p.pos, t.points[k - 1].pos);
                    var tangent = k + 1 < t.points.Count ? t.points[k + 1].pos - p.pos : p.pos - t.points[k - 1].pos;
                    float a = VeilAlpha * 0.5f * (1f + Mathf.Cos(Mathf.PI * Mathf.Clamp01(p.age / VeilLife))) * opacity;
                    AddRibbonPoint(p.pos, tangent, total > 0f ? run / total : 0f, VeilHalfWidth * s, new Color(c.r, c.g, c.b, a));
                }
                AddRibbonStrip(first, t.points.Count);
            }
            EndMesh(veil);
        }

        // ---- the engine lights ------------------------------------------------------------------------------------------
        void UpdateLights(bool on, float thrust, float boost)
        {
            if (!on)
            {
                if (lights != null) foreach (var l in lights) if (l != null) l.enabled = false;
                return;
            }
            if (lights == null)
            {
                lights = new Light[sockets.Length];
                for (int i = 0; i < sockets.Length; i++)
                {
                    var go = new GameObject("es2_engine_light_" + i);
                    go.transform.SetParent(transform, false);
                    go.transform.localPosition = sockets[i].at;
                    var l = go.AddComponent<Light>();
                    l.type = LightType.Point;
                    l.shadows = LightShadows.None;
                    l.range = LightRadius * sockets[i].scale * es2Scale;
                    var c = ColourOf(i);
                    float peak = Mathf.Max(c.r, Mathf.Max(c.g, c.b));
                    l.color = peak > 0f ? new Color(c.r / peak, c.g / peak, c.b / peak) : Color.white;
                    lights[i] = l;
                }
            }
            for (int i = 0; i < lights.Length; i++)
            {
                var l = lights[i];
                if (l == null) continue;
                float amount = sockets[i].booster ? boost : thrust;
                l.intensity = LightIntensity * LightGain * amount;
                l.enabled = amount > 0.001f;
            }
        }

        // ---- the NPC glow -----------------------------------------------------------------------------------------------
        void UpdateGlow(bool on, float thrust, float boost)
        {
            BeginMesh();
            if (on)
                for (int i = 0; i < sockets.Length; i++)
                {
                    float a = GlowAlpha * (sockets[i].booster ? boost : thrust);
                    if (a <= 0.001f) continue;
                    var c = ColourOf(i) * GlowColour * (sockets[i].booster ? 1f : 0.5f);
                    int b = v.Count;
                    foreach (var corner in new[] { new Vector2(0, 0), new Vector2(1, 0), new Vector2(1, 1), new Vector2(0, 1) })
                    {
                        v.Add(sockets[i].at); n.Add(Vector3.forward); uv.Add(corner);
                        uv1.Add(new Vector2(GlowHalf * sockets[i].scale * es2Scale, 0f)); col.Add(new Color(c.r, c.g, c.b, a));
                    }
                    tri.AddRange(new[] { b, b + 1, b + 2, b, b + 2, b + 3 });
                }
            EndMesh(glow);
        }

        // ---- the NPC trail ----------------------------------------------------------------------------------------------
        void UpdateNpcTrails(bool on, float dt, float thrust, float boost)
        {
            BeginMesh();
            float s = es2Scale;
            var vel = flame.Velocity;
            float align = vel.sqrMagnitude > 1e-4f ? Mathf.Pow(Mathf.Clamp01(Vector3.Dot(vel.normalized, transform.forward)), TrailAlignPower) : 0f;
            for (int i = 0; i < sockets.Length; i++)
            {
                var t = trails[i];
                var at = transform.TransformPoint(sockets[i].at);
                float life = TrailLife * sockets[i].scale;
                for (int k = t.points.Count - 1; k >= 0; k--)
                {
                    var p = t.points[k];
                    p.age += dt;
                    if (p.age >= life || !on) t.points.RemoveAt(k); else t.points[k] = p;
                }
                if (!on) { t.hasLast = false; continue; }
                float alpha = (sockets[i].booster ? boost : thrust) * align;
                if (t.hasLast)
                {
                    float moved = Vector3.Distance(at, t.last);
                    // a jump moves the ship in one frame: start again
                    if (moved > TrailSpacing * s * 50f) { t.points.Clear(); t.spawnDue = 0f; }
                    else
                    {
                        float spacing = TrailSpacing * s;
                        float before = t.spawnDue;
                        t.spawnDue += moved;
                        // a point at each spacing passed this frame, along the way flown
                        for (float d = spacing - before; d <= moved && moved > 0f; d += spacing)
                            t.points.Add(new Particle { pos = Vector3.Lerp(t.last, at, d / moved), age = 0f, alpha = alpha });
                        t.spawnDue %= spacing;
                    }
                }
                t.last = at; t.hasLast = true;
                if (t.points.Count == 0) continue;
                // newest first, the live socket ahead of them; u = the distance from the head over 50 m (its tiling)
                var c = ColourOf(i) * (sockets[i].booster ? 1f : 0.5f);
                int first = v.Count, count = 0;
                var prev = at;
                float run = 0f;
                var local = transform.InverseTransformPoint(at);
                var nextLocal = transform.InverseTransformPoint(t.points[t.points.Count - 1].pos);
                AddRibbonPoint(local, nextLocal - local, 0f, TrailHalfWidth * sockets[i].scale * s, new Color(c.r, c.g, c.b, alpha)); count++;
                for (int k = t.points.Count - 1; k >= 0; k--)
                {
                    var p = t.points[k];
                    run += Vector3.Distance(p.pos, prev);
                    var pl = transform.InverseTransformPoint(p.pos);
                    var next = k > 0 ? transform.InverseTransformPoint(t.points[k - 1].pos) : pl + (pl - transform.InverseTransformPoint(prev));
                    AddRibbonPoint(pl, next - pl, run / (TrailTile * s), TrailHalfWidth * sockets[i].scale * s, new Color(c.r, c.g, c.b, p.alpha));
                    prev = p.pos; count++;
                }
                AddRibbonStrip(first, count);
            }
            EndMesh(npcTrail);
        }

        // ---- meshes -----------------------------------------------------------------------------------------------------
        void BeginMesh() { v.Clear(); n.Clear(); uv.Clear(); uv1.Clear(); col.Clear(); tri.Clear(); }

        void AddRibbonPoint(Vector3 at, Vector3 tangent, float u, float halfWidth, Color c)
        {
            var dir = tangent.sqrMagnitude > 1e-10f ? tangent.normalized : Vector3.back;
            for (int side = -1; side <= 1; side += 2)
            {
                v.Add(at); n.Add(dir); uv.Add(new Vector2(u, side < 0 ? 0f : 1f)); uv1.Add(new Vector2(halfWidth, side)); col.Add(c);
            }
        }

        void AddRibbonStrip(int first, int points)
        {
            for (int k = 0; k + 1 < points; k++)
            {
                int a = first + k * 2;
                tri.AddRange(new[] { a, a + 1, a + 3, a, a + 3, a + 2 });
            }
        }

        void EndMesh(MeshFilter mf)
        {
            if (mf == null) return;
            var r = mf.GetComponent<Renderer>();
            bool any = tri.Count > 0;
            if (r.enabled != any) r.enabled = any;
            if (!any) return;
            var m = mf.sharedMesh;
            m.Clear();
            m.SetVertices(v); m.SetNormals(n); m.SetUVs(0, uv); m.SetUVs(1, uv1); m.SetColors(col); m.SetTriangles(tri, 0);
            // (the shader spreads the points into quads and ribbons: the bounds take in the widest)
            var bounds = new Bounds(v[0], Vector3.zero);
            float reach = 0f;
            for (int i = 0; i < v.Count; i++) { bounds.Encapsulate(v[i]); reach = Mathf.Max(reach, uv1[i].x); }
            bounds.Expand(reach * 2.2f);
            m.bounds = bounds;
        }
    }
}
