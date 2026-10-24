// EngineFx.cs
// Remake mods: Galaxy on Fire 3's engine effect at a mod ship's exhausts (ships.json "engineFx", Data.CustomEngineFx), in
// place of the glow disc and the exhaust particles. GoF3 puts two things at each engine helper (its data.pdb's
// EngineAttachment and VfxList, e.g. NivelianEngine = /assets/vfx/engines/nivelian/vfx_engine_nivelian_000.ae4scene and
// TrailNivelian = particles/ship_engine_nivelian.psb):
//   - the flare ("glow"): GoF3's glow_mesh, two camera-facing quads (a_pos2dOffset): a 9 x 9 unit square of the whole
//     texture (the hot star) and a 27 x 2.7 streak at half brightness with the texture turned a quarter (its vertical
//     middle stretched sideways), its AngleBlend dimming it seen from the front;
//   - the cone ("cone"): four crossed cards along the exhaust (GoF3's exhaust mesh: radius 1.62, rings at 0 / 1.73 / 6.91 /
//     12.09 units with vertex colours 0 / 0.77 / 0.2 / 0, u 0.39 -> 0.69 along, v 0 -> 1 across), here as long as the
//     throttle; an engine's own rings by "coneProfile" (the Terran / Vossk exhaust meshes), and "coneFade" its material's
//     AngleBlend: each card fades as it turns edge-on to the camera (FadeCards), so from straight behind only the flares show;
//   - the stream ("trail"): GoF3's Fork particle trail of stretched streaks (beam_001.bmp) that wander off sideways, so
//     each stream wavers like lightning and bends when the ship turns: here 'trailCount' camera-facing ribbons per exhaust,
//     points emitted at the nozzle that keep the ship's velocity (the stream stays with the ship) plus their own speed
//     backward (trailLength / trailTime at full throttle) and a random sideways drift that grows with their age; the ribbon
//     takes the streak texture's middle row across it (a continuous stream; whole copies per segment read as beads) and
//     each point a random brightness, as the overlapping streaks give GoF3's streams their flicker.
// Each exhaust blows along its mount's "rotation" (ModHardpoints.MountTurn: GoF3's engine helper turned, the Vossk hulls'
// engines 8.5-10 deg outward) and is sized by its "fxScale".
//   - the helix ("spiral"): GoF3's spiral, two ribbon strands winding round the exhaust (radius 0.5 -> 0.1 units over 10.5,
//     bright down the middle, fading toward the end) that its animation spins, a thin bolt running along each (GoF3 draws a
//     beam through a flow map; its files name the textures by GUID only: the mod gives vfx_generic_electricity_000, the
//     lightning crackling in each strand): here 'spiralCount' camera-facing strands per exhaust on a helix that spins, the
//     texture scrolling along them, as long as the throttle like the cone.
// With "meshes" (EngineModel, the GoF3 importer's file of an engine scene) GoF3's engine is drawn as GoF3 draws it instead of
// the flare, cone and helix: each part's own mesh with GoF2/ModEngineMesh, the options and values of the shader variant GoF3
// compiled for its material, in the engine's frame (GoF3 units x "meshScale", +z backward) at every exhaust, sized by its
// fxScale and spread to its nozzle's outline (all but the sprites); a little shorter at idle; its animations played: "loop"
// always (the Nivelian spiral's turn), "ignite" as the engines light and a boost starts (the Terran burst), "off" as they go
// out (the capital engines' flicker). The trails are drawn on top when given.
// "trailParticles" / "contrailParticles" (Data.CustomForkEmitter): GoF3's own trail and contrails, its Fork Particle Studio
// emitters (romfs particles/ship_engine_<race>.psb, ship_engine_contrail.psb; each ship's VfxList names its own) run as the
// Fork runtime runs them (libgofm.so: frkPEmitterEmit, _frkPEmitterEmitProcess, _frkParticleProcessFullSim): 'rate' particles
// a second born at the exhaust (or the "contrails" point), spread along the path it moved since the last frame, never moving
// themselves, so they lie along the wake; each lives 'life' s, sized start -> mid -> end and coloured through four keys by its
// age; the texture (a vertical streak) drawn on a quad facing the camera, stretched along the wake. In place of "trail".
// "boostParticles": GoF3's booster flash (ad_engine_booster_<race>.psb), emitted at the exhausts only while boosting, riding
// with the ship ("local": the .psb's flag 0x20000).
// Level: EngineDrive like EngineFlame (0 idle .. 1 full throttle .. 2 a full boost; off while the engine glow part is, a
// quarter-second fade; in the docked station capped at full throttle). Every part is under the engine glow part, so it goes
// with the engines; the trails' points are kept in world space and written into their meshes in the part's space.

using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.Visuals;
using UnityEngine;
using UnityEngine.Rendering;

namespace GoF2Remake.Modding
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public class EngineFx : MonoBehaviour
    {
        const float M = 0.05f;              // metres per game unit
        const float FadePerSecond = 4f;
        const float Response = 6f;          // 1/s: how fast the effect follows the throttle
        const float EmitInterval = 1f / 60f;
        const float MinWakeSpeed = 2f;      // m/s: the Fork trails emit only faster than this
        const int MaxPoints = 64;
        const float SwayEase = 0.12f;       // per emitted point: how fast a stream's sideways motion turns
        // The materials' _Glow (HDR for the bloom), per part: matched by eye against GoF3 (the Moornta in its ship viewer and
        // in flight), the trails the brightest, the cone a soft glow at the nozzle, the helix's bolts kept below white.
        const float GlowHdr = 0.75f, ConeHdr = 0.5f, TrailHdr = 1f, SpiralHdr = 0.45f;
        const int StrandPoints = 40;

        static readonly int ColorId = Shader.PropertyToID("_Color");

        // GoF3's exhaust cards (vfx_engine_nivelian_000_exhaust): rings along the length (share of it), their brightness and u;
        // the default when the engine gives no "coneProfile" of its own.
        static readonly float[] ConeRings = { 0f, 1.73f / 12.09f, 6.91f / 12.09f, 1f };
        static readonly float[] ConeBright = { 0f, 0.77f, 0.2f, 0f };
        static readonly float[] ConeU = { 0.39f, 0.44f, 0.56f, 0.69f };
        const int ConeCards = 4;

        [SerializeField] GameObject engineGlow;
        [SerializeField] List<Vector3> nozzles = new List<Vector3>();   // root space
        [SerializeField] List<float> scales = new List<float>();         // the mount's fxScale (an oval's mean)
        [SerializeField] List<Profile> profiles = new List<Profile>();   // each nozzle's outline (ModExhausts' normalized profile)

        [System.Serializable] sealed class Profile { public float[] r; }
        [SerializeField] List<Quaternion> turns = new List<Quaternion>();   // the mount's rotation (GoF3's engine helper's turn)
        [SerializeField] List<Color> colours = new List<Color>();
        // engineFx coneColor / trailColor / spiralColor: alpha 0 = not given (the engine's colour, 'colours')
        [SerializeField] Color flareTint, coneTint, trailTint, spiralTint;
        [SerializeField] Material glowMaterial, coneMaterial, trailMaterial, spiralMaterial;
        [SerializeField] Vector3 glowHalf;   // the square's half size, the streak's half width and half height
        [SerializeField] float glowIntensity, coneLength, coneHalfWidth, coneIntensity;
        [SerializeField] float[] coneRings, coneBright, coneU;   // the engine's own cone rings ("coneProfile"; null: the default)
        [SerializeField] Vector2 coneFade;                        // "coneFade" |N.V| from .. to (to <= 0: none)
        [SerializeField] int trailCount;
        [SerializeField] float trailLength, trailHalfWidth, trailWander, trailTime, trailIntensity;
        [SerializeField] int spiralCount;
        [SerializeField] float spiralLength, spiralRadius0, spiralRadius1, spiralHalfWidth, spiralTurns, spiralSpin, spiralScroll, spiralRepeat, spiralIntensity;
        // GoF3's own engine parts (EngineModel): shared meshes and materials, each part's place and animations
        [System.Serializable] sealed class MeshPart
        {
            public Vector3 pos, scale;
            public Quaternion rot;
            public bool sprite;
            public EngineAnim[] anims;
        }
        [SerializeField] List<Mesh> partMeshes = new List<Mesh>();
        [SerializeField] List<Material> partMaterials = new List<Material>();
        [SerializeField] List<MeshPart> partInfo = new List<MeshPart>();
        [SerializeField] float meshScale = 1f;
        const float MeshIdleLength = 0.6f;   // the parts' length at idle against full throttle (the remake's: GoF3's stay put)
        static readonly int LevelId = Shader.PropertyToID("_Level");
        [SerializeField] CustomForkEmitter forkTrail, forkContrail, forkBoost;
        [SerializeField] Material forkTrailMaterial, forkContrailMaterial, forkBoostMaterial;
        [SerializeField] List<Vector3> contrailPoints = new List<Vector3>();   // root space
        [SerializeField] float forkUnit = 1f;   // Unity metres per unit of the emitters' sizes

        class ForkParticle { public Vector3 pos, along; public float age, life, s0, s1, s2, spacing; }
        class ForkRun
        {
            public readonly List<ForkParticle> particles = new List<ForkParticle>();
            public CustomForkEmitter em;
            public Mesh mesh;
            public MeshRenderer renderer;
            public Vector3 point, last;   // the emitter in root space; its world place last frame
            public bool hasLast;
            public float carry, scale;
            public int engine = -1;       // the exhaust it follows (-1: a contrail point)
            public bool boost;            // emits only while boosting
        }
        readonly List<ForkRun> forkRuns = new List<ForkRun>();

        class Point { public Vector3 pos, vel, drift; public float age, bright; }
        class Trail
        {
            public readonly List<Point> points = new List<Point>();
            public Mesh mesh;
            public MeshRenderer renderer;
            public int engine;
            public float emitTimer;
            public Vector3 sway;   // the sideways motion the next point takes: it wanders smoothly, so the stream undulates
            public Vector2 start;  // where on the nozzle it leaves (its plane, in its half sizes: an oval's streams spread along it)
        }

        readonly List<(Transform t, MeshRenderer r, int engine)> flares = new List<(Transform, MeshRenderer, int)>();
        readonly List<(Transform t, float s)> meshHolders = new List<(Transform, float)>();
        readonly List<(Transform t, MeshRenderer r, int part)> meshParts = new List<(Transform, MeshRenderer, int)>();
        float igniteMs = -1f, offMs = -1f, offLength, prevBoost;
        bool wasOn;
        readonly List<(Transform t, MeshRenderer r, int engine, Mesh mesh)> cones = new List<(Transform, MeshRenderer, int, Mesh)>();
        Color[] coneBase;                      // the cone mesh's own vertex colours (the edge-on fade scales each card's)
        readonly List<Color> coneColours = new List<Color>();
        readonly List<Trail> trails = new List<Trail>();
        readonly List<(Mesh mesh, MeshRenderer r, int engine, int strand)> strands = new List<(Mesh, MeshRenderer, int, int)>();
        readonly List<Vector3> rpos = new List<Vector3>();
        readonly List<float> rwidth = new List<float>(), rv = new List<float>();
        readonly List<Color> rcol = new List<Color>();
        float spinTime;
        readonly List<Vector3> verts = new List<Vector3>();
        readonly List<Vector2> uvs = new List<Vector2>();
        readonly List<Color> vcolours = new List<Color>();
        readonly List<int> tris = new List<int>();
        MaterialPropertyBlock block;
        EngineDrive drive;
        bool ready, inStation;
        float thrust = -1f, boost, level = -1f;
        Vector3 lastPos, velocity;
        bool hasLast;

        /// <summary>Sets it up on a ship template: the parts under 'glowPart' (the engine glow part: they go with the engines),
        /// one per exhaust mount of 'c'; the materials made here (copies of ModAssets.fxAdditive with the mod's PNGs).</summary>
        public static void Add(GameObject root, GameObject glowPart, CustomShipData c, ModInfo mod)
        {
            if (c?.engineFx == null || c.mounts == null) return;
            CreateShaped(root, glowPart, c.engineFx, c.mounts, mod, c.assembly ?? c.name,
                         m => m.glowColor != null && m.glowColor.Length >= 3 ? m.glowColor : c.engineGlowColor);
        }

        /// <summary>Create with each exhaust sized by its mount's fxScale and shaped by its mount's "outline" (the nozzle's
        /// cross-section, ModExhausts.OutlineOf: the cards reach it, the trails spread along its long side, centred on it), as an
        /// exhaust style is on the same mounts; round without one.</summary>
        public static EngineFx CreateShaped(GameObject host, GameObject glowPart, CustomEngineFx fx, IEnumerable<WeaponMount> mounts, ModInfo mod,
                                            string label, System.Func<WeaponMount, float[]> colourOf)
        {
            var shapes = new Dictionary<WeaponMount, ModExhausts.NozzleShape>();
            foreach (var m in mounts) if (m != null && m.slotType == 3 && ModExhausts.OutlineOf(m) is ModExhausts.NozzleShape o) shapes[m] = o;
            return Create(host, glowPart, fx, mounts, mod, label, m => m.fxScale > 0f ? m.fxScale : 1f, colourOf,
                          centreOf: m => shapes.TryGetValue(m, out var o) ? new Vector2(o.centreX, o.centreY) : Vector2.zero,
                          profileOf: m => shapes.TryGetValue(m, out var o) ? o.Normalized() : null);
        }

        /// <summary>The effect 'fx' at every exhaust mount (slotType 3) of 'mounts' (ship-relative game units, as the host's
        /// own frame: 'host' is the ship's root, or a child of the engine glow part aligned with it, ModExhausts), its parts
        /// under 'glowPart'. 'scaleOf' sizes each exhaust, 'profileOf' gives its nozzle's outline (ModExhausts' normalized
        /// profile: the cone's cards and the helix follow it, the trails spread along its long side; null = round), 'centreOf'
        /// moves it in its mount's plane (Unity metres), 'colourOf' its colour (null: fx.color); 'main' / 'second' (a
        /// customized exhaust's colours, ModExhausts) replace the flare and cone colour / the trails' and helix's. 'materials'
        /// (by part name) are reused across ships when given (made once there).</summary>
        public static EngineFx Create(GameObject host, GameObject glowPart, CustomEngineFx fx, IEnumerable<WeaponMount> mounts, ModInfo mod, string label,
                                      System.Func<WeaponMount, float> scaleOf, System.Func<WeaponMount, float[]> colourOf = null,
                                      Color? main = null, Color? second = null, Dictionary<string, Material> materials = null,
                                      System.Func<WeaponMount, Vector2> centreOf = null, System.Func<WeaponMount, float[]> profileOf = null)
        {
            var additive = ModAssets.Get()?.fxAdditive;
            if (fx == null || host == null || glowPart == null || additive == null || mounts == null) return null;
            var e = host.AddComponent<EngineFx>();
            e.engineGlow = glowPart;
            Color fallback = fx.color != null && fx.color.Length >= 3 ? new Color(fx.color[0], fx.color[1], fx.color[2], 1f) : new Color(0.22f, 0.86f, 1f, 1f);
            foreach (var m in mounts)
            {
                if (m == null || m.slotType != 3) continue;
                var g = colourOf?.Invoke(m);
                var turn = ModHardpoints.MountTurn(m);
                var centre = centreOf?.Invoke(m) ?? Vector2.zero;
                e.nozzles.Add(WeaponSystem.MountToLocal(m) + turn * new Vector3(centre.x, centre.y, 0f));
                e.scales.Add(Mathf.Max(0.01f, scaleOf != null ? scaleOf(m) : 1f));
                e.profiles.Add(new Profile { r = profileOf?.Invoke(m) });
                e.turns.Add(turn);
                e.colours.Add(main ?? (g != null && g.Length >= 3 ? new Color(g[0], g[1], g[2], 1f) : fallback));
            }
            Color Tint(float[] rgb) => rgb != null && rgb.Length >= 3 ? new Color(rgb[0], rgb[1], rgb[2], 1f) : Color.clear;
            e.flareTint = main ?? Tint(fx.flareColor);
            e.coneTint = main ?? Tint(fx.coneColor);
            e.trailTint = second ?? Tint(fx.trailColor);
            e.spiralTint = second ?? Tint(fx.spiralColor);
            Material Made(string file, string part, bool repeatV, float hdr)
            {
                if (string.IsNullOrEmpty(file)) return null;
                if (materials != null && materials.TryGetValue(part, out var have) && have != null) return have;
                var tex = ModMaterials.Texture(mod, file, false);
                if (tex == null) { Debug.LogWarning($"Mods: {mod?.Id}: \"{label}\" engineFx: {file} isn't a PNG / JPG the game can read"); return null; }
                tex.wrapModeU = TextureWrapMode.Clamp;
                tex.wrapModeV = repeatV ? TextureWrapMode.Repeat : TextureWrapMode.Clamp;
                var mat = ModMaterials.CopyOf(additive, $"{label} engine {part}");
                mat.SetTexture("_MainTex", tex);
                mat.SetTextureScale("_MainTex", Vector2.one);
                mat.SetTextureOffset("_MainTex", Vector2.zero);
                mat.SetColor("_Color", Color.white);
                if (mat.HasProperty("_Glow")) mat.SetFloat("_Glow", hdr);
                if (materials != null) materials[part] = mat;
                return mat;
            }
            bool meshes = !string.IsNullOrEmpty(fx.meshes) && e.MeshParts(fx, mod, label);
            e.glowMaterial = meshes ? null : Made(fx.glow, "glow", false, GlowHdr);
            e.coneMaterial = meshes ? null : Made(fx.cone, "cone", false, ConeHdr);
            Flowing(e.coneMaterial, fx.coneFlow);
            bool forkTrail = fx.trailParticles?.Any == true;
            e.trailMaterial = forkTrail ? null : Made(fx.trail, "trail", false, TrailHdr);
            e.ForkEmitters(fx, mod, label);
            var gs = fx.glowSize;
            e.glowHalf = new Vector3(gs != null && gs.Length >= 1 ? gs[0] : 240f, gs != null && gs.Length >= 2 ? gs[1] : 720f,
                                     gs != null && gs.Length >= 3 ? gs[2] : (gs != null && gs.Length >= 2 ? gs[1] * 0.1f : 72f)) * M;
            e.glowIntensity = fx.glowIntensity;
            e.coneLength = fx.coneLength * M;
            e.coneHalfWidth = fx.coneWidth * M;
            e.coneIntensity = fx.coneIntensity;
            var cp = fx.coneProfile;
            if (cp != null && cp.Length >= 6 && cp.Length % 3 == 0)
            {
                int n = cp.Length / 3;
                e.coneRings = new float[n]; e.coneBright = new float[n]; e.coneU = new float[n];
                for (int k = 0; k < n; k++) { e.coneRings[k] = cp[3 * k]; e.coneBright[k] = cp[3 * k + 1]; e.coneU[k] = cp[3 * k + 2]; }
            }
            if (fx.coneFade != null && fx.coneFade.Length >= 2 && fx.coneFade[1] > fx.coneFade[0])
                e.coneFade = new Vector2(Mathf.Max(0f, fx.coneFade[0]), fx.coneFade[1]);
            e.trailCount = Mathf.Clamp(fx.trailCount, 0, 4);
            e.trailLength = fx.trailLength * M;
            e.trailHalfWidth = fx.trailWidth * M;
            e.trailWander = fx.trailWander * M;
            e.trailTime = Mathf.Max(0.05f, fx.trailTime);
            e.trailIntensity = fx.trailIntensity;
            e.spiralMaterial = meshes ? null : Made(fx.spiral, "spiral", true, SpiralHdr);
            e.spiralCount = Mathf.Clamp(fx.spiralCount, 0, 4);
            e.spiralLength = fx.spiralLength * M;
            var sr = fx.spiralRadius;
            e.spiralRadius0 = (sr != null && sr.Length >= 1 ? sr[0] : 27f) * M;
            e.spiralRadius1 = (sr != null && sr.Length >= 2 ? sr[1] : 5f) * M;
            e.spiralHalfWidth = fx.spiralWidth * M;
            e.spiralTurns = fx.spiralTurns;
            e.spiralSpin = fx.spiralSpin;
            e.spiralScroll = fx.spiralScroll;
            e.spiralRepeat = fx.spiralRepeat;
            e.spiralIntensity = fx.spiralIntensity;
            return e;
        }

        static Shader meshShader;
        static bool meshShaderLoaded;
        static readonly Dictionary<string, (Mesh mesh, Material mat)> partCache = new Dictionary<string, (Mesh, Material)>();
        static int partCacheRevision = -1;

        /// <summary>GoF3's engine parts from fx.meshes: a mesh and a material per part, shared by every ship with that file in
        /// the mod for the set of mods; false when the file or the shader can't be had (the cards are drawn then).</summary>
        bool MeshParts(CustomEngineFx fx, ModInfo mod, string label)
        {
            var file = EngineModels.Get(mod, fx.meshes);
            if (file == null) return false;
            if (!meshShaderLoaded) { meshShaderLoaded = true; meshShader = Resources.Load<Shader>("GoF2Mods/ModEngineMesh"); }
            if (meshShader == null || !meshShader.isSupported) return false;
            if (partCacheRevision != ModManager.Revision) { partCache.Clear(); partCacheRevision = ModManager.Revision; }
            meshScale = fx.meshScale > 0f ? fx.meshScale : 1f;
            for (int k = 0; k < file.parts.Length; k++)
            {
                var p = file.parts[k];
                if (p?.v == null || p.i == null || p.v.Length < 9) continue;
                string key = $"{mod.Id}|{fx.meshes}|{k}|{fx.meshGlow}";
                if (!partCache.TryGetValue(key, out var made) || made.mesh == null || made.mat == null)
                {
                    made = (PartMesh(p, $"{label} {p.name}"), PartMaterial(p, mod, fx, $"{label} {p.name}"));
                    if (made.mat == null) continue;
                    partCache[key] = made;
                }
                partMeshes.Add(made.mesh);
                partMaterials.Add(made.mat);
                partInfo.Add(new MeshPart
                {
                    pos = Vec(p.pos, Vector3.zero), scale = Vec(p.scale, Vector3.one),
                    rot = p.rot != null && p.rot.Length >= 4 ? new Quaternion(p.rot[0], p.rot[1], p.rot[2], p.rot[3]) : Quaternion.identity,
                    sprite = p.sprite, anims = p.anims,
                });
            }
            return partMeshes.Count > 0;
        }

        static Vector3 Vec(float[] a, Vector3 fallback) => a != null && a.Length >= 3 ? new Vector3(a[0], a[1], a[2]) : fallback;
        static Color Col(float[] a) => a != null && a.Length >= 4 ? new Color(a[0], a[1], a[2], a[3]) : a != null && a.Length >= 3 ? new Color(a[0], a[1], a[2], 1f) : Color.white;

        static Mesh PartMesh(EnginePart p, string name)
        {
            int n = p.v.Length / 3;
            var v = new Vector3[n]; var nm = new Vector3[n]; var uv = new Vector2[n]; var off = new Vector2[n]; var c = new Color[n];
            float reach = 0f;
            for (int j = 0; j < n; j++)
            {
                v[j] = new Vector3(p.v[3 * j], p.v[3 * j + 1], p.v[3 * j + 2]);
                nm[j] = p.n != null && p.n.Length >= 3 * n ? new Vector3(p.n[3 * j], p.n[3 * j + 1], p.n[3 * j + 2]) : Vector3.forward;
                if (p.uv != null && p.uv.Length >= 2 * n) uv[j] = new Vector2(p.uv[2 * j], p.uv[2 * j + 1]);
                if (p.o != null && p.o.Length >= 2 * n) { off[j] = new Vector2(p.o[2 * j], p.o[2 * j + 1]); reach = Mathf.Max(reach, off[j].magnitude); }
                c[j] = p.c != null && p.c.Length >= 4 * n ? new Color(p.c[4 * j], p.c[4 * j + 1], p.c[4 * j + 2], p.c[4 * j + 3]) : Color.white;
            }
            var m = new Mesh { name = name };
            if (n > 65000) m.indexFormat = IndexFormat.UInt32;
            m.SetVertices(v); m.SetNormals(nm); m.SetUVs(0, uv); m.SetUVs(1, off); m.SetColors(c);
            m.SetTriangles(p.i, 0);
            m.RecalculateBounds();
            // a sprite's corners and the wobble reach past the vertices
            float grow = 2f * (reach + (p.vertexAnim ? Mathf.Abs(p.vaStrength) : 0f));
            if (grow > 0f) { var b = m.bounds; b.Expand(grow); m.bounds = b; }
            return m;
        }

        static Material PartMaterial(EnginePart p, ModInfo mod, CustomEngineFx fx, string name)
        {
            var mat = new Material(meshShader) { name = name, renderQueue = (int)RenderQueue.Transparent };
            Texture2D Tex(string file)
            {
                if (string.IsNullOrEmpty(file)) return null;
                var t = ModMaterials.Texture(mod, file, true);   // raw: GoF3's maths runs on the stored values
                if (t == null) { mod?.Warnings.Add($"engineFx: {file} isn't a PNG / JPG the game can read"); return null; }
                t.wrapMode = TextureWrapMode.Repeat;
                return t;
            }
            var tex = p.useTex ? Tex(p.texture) : null;
            if (p.useTex && tex == null) return null;
            if (tex != null) mat.SetTexture("_MainTex", tex);
            var flow = p.flow ? Tex(p.flowMap) : null;
            if (flow != null) mat.SetTexture("_FlowMap", flow);
            mat.SetColor("_Diffuse", Col(p.diffuse));
            mat.SetColor("_C1", Col(p.c1));
            mat.SetColor("_C2", Col(p.c2));
            mat.SetFloat("_Opacity", p.opacity);
            mat.SetFloat("_ColorizeMul", p.colorizeMul);
            mat.SetFloat("_AngleMin", p.angleMin);
            mat.SetFloat("_AngleMax", p.angleMax);
            mat.SetFloat("_PulseMin", p.pulseMin);
            mat.SetFloat("_PulseMax", p.pulseMax);
            mat.SetFloat("_PulseFreq", p.pulseFreq);
            mat.SetVector("_UVSpeed", p.uvSpeed != null && p.uvSpeed.Length >= 2 ? new Vector4(p.uvSpeed[0], p.uvSpeed[1], 0f, 0f) : Vector4.zero);
            mat.SetFloat("_FlowTiling", p.flowTiling);
            mat.SetFloat("_FlowStrength", p.flowStrength);
            mat.SetFloat("_VAFreq", p.vaFreq);
            mat.SetFloat("_VAStrength", p.vaStrength);
            mat.SetFloat("_Alpha", p.alpha);
            mat.SetFloat("_Intensity", p.intensity > 0f ? p.intensity : 4f);
            mat.SetFloat("_Glow", fx.meshGlow > 0f ? fx.meshGlow : 1f);
            mat.SetFloat("_Sprite", p.sprite ? 1f : 0f);
            mat.SetFloat("_UseTex", tex != null ? 1f : 0f);
            mat.SetFloat("_LumAlpha", p.lumAlpha ? 1f : 0f);
            mat.SetFloat("_RgbFromDc", p.rgbFromDc ? 1f : 0f);
            mat.SetFloat("_MulDc", p.mulDc ? 1f : 0f);
            mat.SetFloat("_Flow", flow != null ? 1f : 0f);
            mat.SetFloat("_ScrollDirect", p.scrollDirect ? 1f : 0f);
            mat.SetFloat("_ScrollFlow", p.scrollFlow ? 1f : 0f);
            mat.SetFloat("_Colorize", p.colorize);
            mat.SetFloat("_ColorizeVtx", p.colorizeVtx ? 1f : 0f);
            mat.SetFloat("_Angle", p.angle);
            mat.SetFloat("_Pulsate", p.pulsate ? 1f : 0f);
            mat.SetFloat("_VertexAnim", p.vertexAnim ? 1f : 0f);
            mat.SetFloat("_OpaqueVtxAlpha", p.opaqueVtxAlpha || p.vertexAnim ? 1f : 0f);
            bool additive = p.blend != 1;
            mat.SetFloat("_Additive", additive ? 1f : 0f);
            mat.SetFloat("_SrcBlend", (float)(additive ? BlendMode.One : BlendMode.SrcAlpha));
            mat.SetFloat("_DstBlend", (float)(additive ? BlendMode.One : BlendMode.OneMinusSrcAlpha));
            // (both faces: the engine's frame is mirrored onto the remake's, which turns GoF3's winding over; its angle
            // blend already hides the faces it would cull)
            mat.SetFloat("_Cull", (float)CullMode.Off);
            return mat;
        }

        /// <summary>GoF3's trail / contrail emitters: their materials (GoF2/ModEngineMesh, additive, the texture read raw) and
        /// the contrail points.</summary>
        void ForkEmitters(CustomEngineFx fx, ModInfo mod, string label)
        {
            forkUnit = (fx.meshScale > 0f ? fx.meshScale : 1f) * M;
            Material Mat(CustomForkEmitter em, string part)
            {
                if (em?.Any != true) return null;
                if (!meshShaderLoaded) { meshShaderLoaded = true; meshShader = Resources.Load<Shader>("GoF2Mods/ModEngineMesh"); }
                if (meshShader == null || !meshShader.isSupported) return null;
                if (partCacheRevision != ModManager.Revision) { partCache.Clear(); partCacheRevision = ModManager.Revision; }
                string key = $"{mod?.Id}|fork|{part}|{em.texture}|{fx.meshGlow}";
                if (partCache.TryGetValue(key, out var made) && made.mat != null) return made.mat;
                var p = new EnginePart { name = part, texture = em.texture, useTex = true, blend = 2, opacity = 1f };
                var mat = PartMaterial(p, mod, fx, $"{label} {part}");
                if (mat != null) { mat.SetFloat("_VertexGain", 1f); mat.SetFloat("_Intensity", 1f); partCache[key] = (null, mat); }
                return mat;
            }
            forkTrailMaterial = Mat(fx.trailParticles, "trail particles");
            if (forkTrailMaterial != null) forkTrail = fx.trailParticles;
            forkBoostMaterial = Mat(fx.boostParticles, "boost particles");
            if (forkBoostMaterial != null) forkBoost = fx.boostParticles;
            forkContrailMaterial = Mat(fx.contrailParticles, "contrail particles");
            if (forkContrailMaterial != null && fx.contrails != null)
            {
                forkContrail = fx.contrailParticles;
                for (int k = 0; k + 2 < fx.contrails.Length; k += 3)
                    contrailPoints.Add(new Vector3(-fx.contrails[k], fx.contrails[k + 1], fx.contrails[k + 2]) * M);
            }
        }

        /// <summary>A copy of 'mesh' with each vertex pushed out from the axis to nozzle i's outline (its x / y; the
        /// engine frame's x is the mount's).</summary>
        Mesh Warped(Mesh mesh, int i)
        {
            var copy = Instantiate(mesh);
            copy.name = mesh.name + "_shaped";
            var v = copy.vertices;
            for (int j = 0; j < v.Length; j++)
            {
                if (v[j].x == 0f && v[j].y == 0f) continue;
                float f = Factor(i, Mathf.Atan2(v[j].y, v[j].x));
                v[j] = new Vector3(v[j].x * f, v[j].y * f, v[j].z);
            }
            copy.vertices = v;
            copy.RecalculateBounds();
            owned.Add(copy);
            return copy;
        }

        void OnEnable()
        {
            drive?.Reset();
            hasLast = false;
            foreach (var t in trails) t.points.Clear();
            inStation = FindAnyObjectByType<World.StationLevel>() != null;
        }

        readonly List<Mesh> owned = new List<Mesh>();

        void OnDestroy()
        {
            foreach (var m in owned) if (m != null) Destroy(m);
        }

        void Setup()
        {
            ready = true;
            block = new MaterialPropertyBlock();
            drive = new EngineDrive(transform);
            if (engineGlow == null) return;
            var parent = engineGlow.transform;
            SetupContrails(parent);
            Mesh quad = glowMaterial != null ? Flare() : null;
            if (quad != null) owned.Add(quad);
            bool fading = coneFade.y > 0f;
            Mesh cone = coneMaterial != null ? Cone() : null;
            if (cone != null) { owned.Add(cone); coneBase = cone.colors; }
            for (int i = 0; i < nozzles.Count; i++)
            {
                var at = transform.TransformPoint(nozzles[i]);
                if (partMeshes.Count > 0)
                {
                    // GoF3's engine frame on the exhaust: its x / y the mount's, its +z backward (the mount's -z), in GoF3 units
                    var holder = new GameObject($"engine_fx_mesh_{i}").transform;
                    holder.SetParent(parent, false);
                    holder.position = at;
                    holder.rotation = transform.rotation * turns[i];
                    float s = meshScale * M * scales[i] / Mathf.Max(1e-4f, parent.lossyScale.x);
                    holder.localScale = new Vector3(s, s, -s);
                    meshHolders.Add((holder, s));
                    for (int k = 0; k < partMeshes.Count; k++)
                    {
                        var info = partInfo[k];
                        var mesh = Shaped(i) && !info.sprite ? Warped(partMeshes[k], i) : partMeshes[k];
                        var t = Child(holder, $"engine_fx_part_{i}_{k}", mesh, partMaterials[k], at, out var r);
                        t.localPosition = info.pos; t.localRotation = info.rot; t.localScale = info.scale;
                        meshParts.Add((t, r, k));
                        if (info.anims != null)
                            foreach (var a in info.anims) if (a?.kind == "off") offLength = Mathf.Max(offLength, a.length);
                    }
                }
                if (glowMaterial != null)
                {
                    var t = Child(parent, $"engine_fx_glow_{i}", quad, glowMaterial, at, out var r);
                    t.localScale = Vector3.one * (scales[i] / Mathf.Max(1e-4f, parent.lossyScale.x));
                    flares.Add((t, r, i));
                }
                if (coneMaterial != null)
                {
                    var mesh = cone;
                    // its cards reach the nozzle's outline; each fading cone its own mesh (the cards' colours per view)
                    if (Shaped(i) || fading) { mesh = Cone(Shaped(i) ? i : -1); owned.Add(mesh); if (fading) mesh.MarkDynamic(); }
                    var t = Child(parent, $"engine_fx_cone_{i}", mesh, coneMaterial, at, out var r);
                    t.rotation = transform.rotation * turns[i] * Quaternion.LookRotation(Vector3.back, Vector3.up);   // +z of the cone = backward
                    cones.Add((t, r, i, mesh));
                }
                if (spiralMaterial != null)
                    for (int k = 0; k < spiralCount; k++)
                    {
                        var mesh = new Mesh { name = $"engine_fx_spiral_{i}_{k}" };
                        mesh.MarkDynamic();
                        owned.Add(mesh);
                        var t = Child(parent, mesh.name, mesh, spiralMaterial, parent.position, out var r);
                        t.localPosition = Vector3.zero; t.localRotation = Quaternion.identity; t.localScale = Vector3.one;
                        strands.Add((mesh, r, i, k));
                    }
                if (forkTrail?.Any == true && forkTrailMaterial != null)
                    forkRuns.Add(ForkRunAt(parent, $"engine_fx_fork_{i}", forkTrail, forkTrailMaterial, nozzles[i], forkUnit * scales[i], i));
                if (forkBoost?.Any == true && forkBoostMaterial != null)
                {
                    var run = ForkRunAt(parent, $"engine_fx_boost_{i}", forkBoost, forkBoostMaterial, nozzles[i], forkUnit * scales[i], i);
                    run.boost = true;
                    forkRuns.Add(run);
                }
                if (trailMaterial != null)
                    for (int k = 0; k < trailCount; k++)
                    {
                        var mesh = new Mesh { name = $"engine_fx_trail_{i}_{k}" };
                        mesh.MarkDynamic();
                        owned.Add(mesh);
                        var t = Child(parent, mesh.name, mesh, trailMaterial, parent.position, out var r);
                        t.localPosition = Vector3.zero; t.localRotation = Quaternion.identity; t.localScale = Vector3.one;
                        // A long nozzle's streams leave spread along its long side (a slot's along the slot).
                        float wide = Factor(i, 0f) + Factor(i, Mathf.PI), tall = Factor(i, 0.5f * Mathf.PI) + Factor(i, 1.5f * Mathf.PI);
                        float along = trailCount > 1 && Mathf.Max(wide, tall) > 1.3f * Mathf.Min(wide, tall) ? (2f * k / (trailCount - 1) - 1f) * 0.6f : 0f;
                        var start = wide >= tall ? new Vector2(along, 0f) : new Vector2(0f, along);
                        trails.Add(new Trail { mesh = mesh, renderer = r, engine = i, start = start, emitTimer = Random.value * EmitInterval });
                    }
            }
        }

        void SetupContrails(Transform parent)
        {
            if (forkContrail?.Any != true || forkContrailMaterial == null) return;
            for (int k = 0; k < contrailPoints.Count; k++)
                forkRuns.Add(ForkRunAt(parent, $"engine_fx_contrail_{k}", forkContrail, forkContrailMaterial, contrailPoints[k], forkUnit, -1));
        }

        ForkRun ForkRunAt(Transform parent, string name, CustomForkEmitter em, Material mat, Vector3 point, float scale, int engine)
        {
            var mesh = new Mesh { name = name };
            mesh.MarkDynamic();
            owned.Add(mesh);
            var t = Child(parent, name, mesh, mat, parent.position, out var r);
            t.localPosition = Vector3.zero; t.localRotation = Quaternion.identity; t.localScale = Vector3.one;
            return new ForkRun { em = em, mesh = mesh, renderer = r, point = point, scale = scale, engine = engine };
        }

        static Transform Child(Transform parent, string name, Mesh mesh, Material mat, Vector3 at, out MeshRenderer r)
        {
            var go = new GameObject(name);
            go.transform.SetParent(parent, false);
            go.transform.position = at;
            go.AddComponent<MeshFilter>().sharedMesh = mesh;
            r = go.AddComponent<MeshRenderer>();
            r.sharedMaterial = mat;
            r.shadowCastingMode = ShadowCastingMode.Off;
            r.receiveShadows = false;
            return go.transform;
        }

        /// <summary>GoF3's glow_mesh in metres: the square (the whole texture, brightness 1) and the streak (brightness 0.5, the
        /// texture turned a quarter: u across the streak, v along it), both faces.</summary>
        Mesh Flare()
        {
            float s = glowHalf.x, w = glowHalf.y, h = glowHalf.z;
            var half = new Color(0.5f, 0.5f, 0.5f, 1f);
            var m = new Mesh { name = "engine_fx_glow" };
            m.SetVertices(new[] { new Vector3(-s, -s, 0), new Vector3(s, -s, 0), new Vector3(s, s, 0), new Vector3(-s, s, 0),
                                  new Vector3(-w, -h, 0), new Vector3(w, -h, 0), new Vector3(w, h, 0), new Vector3(-w, h, 0) });
            m.SetUVs(0, new[] { new Vector2(1, 0), new Vector2(0, 0), new Vector2(0, 1), new Vector2(1, 1),
                                new Vector2(1, 1), new Vector2(1, 0), new Vector2(0, 0), new Vector2(0, 1) });
            m.SetColors(new[] { Color.white, Color.white, Color.white, Color.white, half, half, half, half });
            var tri = new List<int>();
            for (int q = 0; q < 8; q += 4) tri.AddRange(new[] { q, q + 2, q + 1, q, q + 3, q + 2, q, q + 1, q + 2, q, q + 2, q + 3 });
            m.SetTriangles(tri, 0);
            m.RecalculateBounds();
            return m;
        }

        /// <summary>GoF3's exhaust: four cards through the axis (0, 45, 90, 135 deg), along +z, 1 long and 1 wide (half), in
        /// its own space; the transform scales it to the cone's size.</summary>
        Mesh Cone(int nozzle = -1)
        {
            var m = new Mesh { name = "engine_fx_cone" };
            var v = new List<Vector3>(); var uv = new List<Vector2>(); var col = new List<Color>(); var tr = new List<int>();
            // The engine's own rings only when they were given: Instantiate copies a null serialized array as an empty one,
            // so every ship (a copy of its template) without a "coneProfile" had no rings and no cone.
            bool own = coneRings != null && coneRings.Length >= 2 && coneBright != null && coneBright.Length == coneRings.Length
                       && coneU != null && coneU.Length == coneRings.Length;
            float[] rings = own ? coneRings : ConeRings, bright = own ? coneBright : ConeBright, us = own ? coneU : ConeU;
            for (int card = 0; card < ConeCards; card++)
            {
                float a = card * Mathf.PI / 4f;
                var side = new Vector3(Mathf.Cos(a), Mathf.Sin(a), 0f);
                int start = v.Count;
                for (int ring = 0; ring < rings.Length; ring++)
                    for (int s = 0; s < 2; s++)
                    {
                        // (the cone's x is the mount's -x: LookRotation backward)
                        var d = side * (s == 0 ? -1f : 1f);
                        float f = nozzle >= 0 ? Factor(nozzle, Mathf.Atan2(d.y, -d.x)) : 1f;
                        v.Add(d * f + Vector3.forward * rings[ring]);
                        uv.Add(new Vector2(us[ring], s));
                        col.Add(new Color(bright[ring], bright[ring], bright[ring], 1f));
                    }
                for (int ring = 0; ring < rings.Length - 1; ring++)
                {
                    int a0 = start + ring * 2, b0 = a0 + 2;
                    tr.AddRange(new[] { a0, b0, a0 + 1, a0 + 1, b0, b0 + 1, a0, a0 + 1, b0, a0 + 1, b0 + 1, b0 });   // both faces
                }
            }
            m.SetVertices(v); m.SetUVs(0, uv); m.SetColors(col); m.SetTriangles(tr, 0);
            m.RecalculateBounds();
            return m;
        }

        void LateUpdate()
        {
            if (!ready) Setup();
            if (engineGlow == null || nozzles.Count == 0) return;
            float dt = Time.deltaTime;
            float d = drive.Sample(dt, engineGlow);
            if (inStation && !drive.Previewing) d = Mathf.Min(d, 1f);
            float t = Mathf.Clamp01(d), b = Mathf.Clamp01(d - 1f);
            if (thrust < 0f) { thrust = t; boost = b; }
            else
            {
                float k = 1f - Mathf.Exp(-dt * Response);
                thrust = Mathf.Lerp(thrust, t, k);
                boost = Mathf.Lerp(boost, b, k);
            }
            bool on = engineGlow.activeInHierarchy && !drive.Off;
            level = level < 0f ? (on ? 1f : 0f) : Mathf.MoveTowards(level, on ? 1f : 0f, Time.unscaledDeltaTime * FadePerSecond);

            var p = transform.position;
            if (hasLast && dt > 0f)
            {
                var v = (p - lastPos) / dt;
                if (v.magnitude < 2000f) velocity = v;   // (a jump or respawn moves the ship in one frame)
            }
            lastPos = p; hasLast = true;

            var cam = Camera.main;
            float power = level * (0.35f + 0.65f * thrust) * (1f + 0.5f * boost);
            foreach (var (ft, r, i) in flares)
            {
                if (ft == null) continue;
                float face = 1f;
                if (cam != null)
                {
                    ft.rotation = Quaternion.LookRotation(ft.position - cam.transform.position, cam.transform.up);
                    float along = Vector3.Dot((cam.transform.position - ft.position).normalized, Back(i));   // 1 = seen from behind
                    face = 0.3f + 0.7f * Mathf.SmoothStep(0f, 1f, Mathf.InverseLerp(-0.2f, 0.7f, along));
                }
                SetColour(r, Tinted(flareTint, i) * (glowIntensity * power * face));
            }
            float coneScale = Mathf.Lerp(0.3f, 1f, thrust) * (1f + 0.3f * boost);
            foreach (var (ct, r, i, mesh) in cones)
            {
                if (ct == null) continue;
                float lossy = Mathf.Max(1e-4f, ct.parent.lossyScale.x);
                ct.localScale = new Vector3(coneHalfWidth, coneHalfWidth, coneLength * coneScale) * (scales[i] / lossy);
                SetColour(r, Tinted(coneTint, i) * (coneIntensity * level * (0.5f + 0.5f * thrust)));
                if (coneFade.y > 0f && cam != null) FadeCards(ct, mesh, cam.transform.position);
            }
            if (trails.Count > 0) UpdateTrails(dt, cam, power);
            if (strands.Count > 0) UpdateStrands(dt, cam, power, coneScale);
            if (meshParts.Count > 0) UpdateMeshes(dt, on);
            if (forkRuns.Count > 0) UpdateFork(dt, cam, on);
        }

        /// <summary>GoF3's Fork emitters: age and drop the particles, emit while the engines run (spread along the path the
        /// emitter moved), and build each run's quads facing the camera, stretched along the wake.</summary>
        void UpdateFork(float dt, Camera cam, bool on)
        {
            var eye = cam != null ? cam.transform.position : transform.position - transform.forward * 100f;
            foreach (var run in forkRuns)
            {
                var em = run.em; var ps = run.particles;
                for (int j = ps.Count - 1; j >= 0; j--) { ps[j].age += dt; if (ps[j].age >= ps[j].life) ps.RemoveAt(j); }
                var here = transform.TransformPoint(run.point);
                if (!run.hasLast || (here - run.last).sqrMagnitude > 1e8f) run.last = here;   // (a jump: no wake across it)
                // a wake needs a ship moving through it: standing still (the hangar's Customize preview, a ship at rest) the
                // particles piled up on the nozzle into a blot GoF3's ship viewer never shows (a local one rides along anyway)
                bool moving = em.local || (here - run.last).magnitude > MinWakeSpeed * dt;
                if (on && moving && level > 0.02f && dt > 0f && (!run.boost || boost > 0.05f))
                {
                    var moved = here - run.last;
                    var along = moved.sqrMagnitude > 1e-8f ? moved.normalized : (run.engine >= 0 ? -Back(run.engine) : -transform.forward);
                    run.carry += em.rate * dt;
                    int n = Mathf.Min((int)run.carry, Mathf.Max(0, em.max - ps.Count));
                    float spacing = n > 0 ? moved.magnitude / n : 0f;
                    run.carry -= (int)run.carry;
                    for (int j = 0; j < n; j++)
                    {
                        float f = (j + 1f) / n, age = (1f - f) * dt;   // born along the way, aged by when
                        ps.Add(new ForkParticle
                        {
                            pos = em.local ? run.point : Vector3.Lerp(run.last, here, f),
                            along = em.local ? transform.InverseTransformDirection(along) : along, age = age, life = Range(em.life),
                            s0 = Range(em.sizeStart), s1 = Range(em.sizeMid ?? em.sizeStart), s2 = Range(em.sizeEnd ?? em.sizeStart), spacing = spacing,
                        });
                    }
                }
                run.last = here; run.hasLast = true;
                BuildFork(run, eye);
            }
        }

        static float Range(float[] r) => r == null || r.Length == 0 ? 0f : r.Length == 1 ? r[0] : Random.Range(r[0], r[1]);

        static Color ForkColour(CustomForkEmitter em, float t)
        {
            var c = em.colors; var k = em.colorTimes;
            if (c == null || c.Length < 16) return Color.white;
            Color Key(int i) => new Color(c[4 * i], c[4 * i + 1], c[4 * i + 2], c[4 * i + 3]);
            float t1 = k != null && k.Length >= 4 ? k[1] : 1f / 3f, t2 = k != null && k.Length >= 4 ? k[2] : 2f / 3f;
            if (t < t1) return Color.Lerp(Key(0), Key(1), t1 > 0f ? t / t1 : 1f);
            if (t < t2) return Color.Lerp(Key(1), Key(2), t2 > t1 ? (t - t1) / (t2 - t1) : 1f);
            return Color.Lerp(Key(2), Key(3), t2 < 1f ? (t - t2) / (1f - t2) : 1f);
        }

        void BuildFork(ForkRun run, Vector3 eye)
        {
            var mesh = run.mesh; var space = run.renderer.transform; var em = run.em;
            verts.Clear(); uvs.Clear(); vcolours.Clear(); tris.Clear(); gains.Clear();
            foreach (var q in run.particles)
            {
                float t = Mathf.Clamp01(q.age / Mathf.Max(1e-4f, q.life)), m = em.sizeMidTime;
                float size = (t < m ? Mathf.Lerp(q.s0, q.s1, m > 0f ? t / m : 1f) : Mathf.Lerp(q.s1, q.s2, m < 1f ? (t - m) / (1f - m) : 1f)) * run.scale;
                if (size <= 0f) continue;
                var pos = em.local ? transform.TransformPoint(q.pos) : q.pos;   // (a local one rides with the ship)
                var dir = em.local ? transform.TransformDirection(q.along) : q.along;
                var view = (eye - pos).normalized;
                var along = dir - view * Vector3.Dot(dir, view);
                if (along.sqrMagnitude < 1e-8f) along = Vector3.Cross(view, Vector3.up);
                along.Normalize();
                var side = Vector3.Cross(along, view) * (0.5f * size);
                along *= 0.5f * size;
                int b = verts.Count;
                verts.Add(space.InverseTransformPoint(pos - along - side)); uvs.Add(new Vector2(0f, 0f));
                verts.Add(space.InverseTransformPoint(pos - along + side)); uvs.Add(new Vector2(1f, 0f));
                verts.Add(space.InverseTransformPoint(pos + along + side)); uvs.Add(new Vector2(1f, 1f));
                verts.Add(space.InverseTransformPoint(pos + along - side)); uvs.Add(new Vector2(0f, 1f));
                var c = ForkColour(em, t);
                vcolours.Add(c); vcolours.Add(c); vcolours.Add(c); vcolours.Add(c);
                // GoF3's gamma-space sum of the overlapping streaks (GoF2/ModEngineMesh's _VertexGain): N^1.2, N the overlap
                float overlap = Mathf.Clamp(q.spacing > 1e-4f ? size / q.spacing : em.max, 1f, Mathf.Max(1f, em.max));
                var g = new Vector2(Mathf.Pow(overlap, 1.2f), 0f);
                gains.Add(g); gains.Add(g); gains.Add(g); gains.Add(g);
                tris.AddRange(new[] { b, b + 1, b + 2, b, b + 2, b + 3 });
            }
            mesh.Clear();
            if (verts.Count == 0) return;
            mesh.SetVertices(verts); mesh.SetUVs(0, uvs); mesh.SetUVs(1, gains); mesh.SetColors(vcolours); mesh.SetTriangles(tris, 0);
            mesh.RecalculateBounds();
        }
        readonly List<Vector2> gains = new List<Vector2>();

        /// <summary>GoF3's engine parts: shorter at idle, the animations played, the level (the engines' fade, or their
        /// "off" animation's flicker) on each part.</summary>
        void UpdateMeshes(float dt, bool on)
        {
            if (on && !wasOn) { igniteMs = 0f; offMs = -1f; }
            else if (!on && wasOn && offLength > 0f) offMs = 0f;
            wasOn = on;
            if (boost > 0.05f && prevBoost <= 0.05f) igniteMs = 0f;
            prevBoost = boost;
            float ms = dt * 1000f;
            if (igniteMs >= 0f) igniteMs += ms;
            if (offMs >= 0f) { offMs += ms; if (offMs > offLength) offMs = -1f; }
            float lengthScale = Mathf.Lerp(MeshIdleLength, 1f, thrust) * (1f + 0.3f * boost);
            foreach (var (h, s) in meshHolders) if (h != null) h.localScale = new Vector3(s, s, -s * lengthScale);
            float shown = offMs >= 0f ? 1f : level;
            float loopMs = Time.time * 1000f;
            bool igniting = false;
            foreach (var (t, r, k) in meshParts)
            {
                if (t == null) continue;
                var info = partInfo[k];
                float alpha = 1f;
                if (info.anims != null && info.anims.Length > 0)
                {
                    Vector3 pos = info.pos, scl = info.scale;
                    var q = new Vector4(info.rot.x, info.rot.y, info.rot.z, info.rot.w);
                    foreach (var a in info.anims)
                    {
                        if (a?.channels == null || a.length <= 0f) continue;
                        float at;
                        if (a.kind == "loop") at = loopMs % a.length;
                        else if (a.kind == "ignite") { if (igniteMs < 0f || igniteMs > a.length) continue; at = igniteMs; igniting = true; }
                        else if (a.kind == "off") { if (offMs < 0f) continue; at = offMs; }
                        else continue;
                        foreach (var c in a.channels)
                        {
                            if (c?.name == null) continue;
                            float v = c.Sample(at);
                            switch (c.name)
                            {
                                case "alpha": alpha *= v; break;
                                case "translation.x": pos.x = v; break;
                                case "translation.y": pos.y = v; break;
                                case "translation.z": pos.z = v; break;
                                case "scale.x": scl.x = v; break;
                                case "scale.y": scl.y = v; break;
                                case "scale.z": scl.z = v; break;
                                case "rotation.x": q.x = v; break;
                                case "rotation.y": q.y = v; break;
                                case "rotation.z": q.z = v; break;
                                case "rotation.w": q.w = v; break;
                            }
                        }
                    }
                    // (every frame: a part an animation left, the "off" flicker's end, comes back to its rest)
                    {
                        var n = q.sqrMagnitude > 1e-8f ? q.normalized : new Vector4(0f, 0f, 0f, 1f);
                        t.localPosition = pos; t.localRotation = new Quaternion(n.x, n.y, n.z, n.w); t.localScale = scl;
                    }
                }
                float lvl = shown * alpha;
                if (r == null) continue;
                r.enabled = lvl > 0.001f;
                if (!r.enabled) continue;
                r.GetPropertyBlock(block);
                block.SetFloat(LevelId, lvl);
                r.SetPropertyBlock(block);
            }
            if (!igniting && igniteMs >= 0f) igniteMs = -1f;
        }

        /// <summary>GoF3's AngleBlend on the exhaust cards: each card's vertex colours x smoothstep(from, to, |N.V|), so a card
        /// seen edge-on (from straight behind: every card contains the axis) vanishes and the flare alone shows.</summary>
        void FadeCards(Transform cone, Mesh mesh, Vector3 eye)
        {
            if (mesh == null || coneBase == null) return;
            var view = (eye - cone.position).normalized;
            int perCard = coneBase.Length / ConeCards;
            coneColours.Clear();
            for (int card = 0; card < ConeCards; card++)
            {
                float a = card * Mathf.PI / ConeCards;
                // the card spans (cos a, sin a, 0) and +z: its normal; the cone's x and y are scaled alike, so it holds
                var n = cone.rotation * new Vector3(-Mathf.Sin(a), Mathf.Cos(a), 0f);
                float f = Mathf.SmoothStep(0f, 1f, Mathf.InverseLerp(coneFade.x, coneFade.y, Mathf.Abs(Vector3.Dot(n, view))));
                for (int k = 0; k < perCard; k++)
                {
                    var c = coneBase[card * perCard + k];
                    coneColours.Add(new Color(c.r * f, c.g * f, c.b * f, 1f));
                }
            }
            mesh.SetColors(coneColours);
        }

        /// <summary>The helix: each strand's points along the exhaust (its own frame: +z backward, the mount's turn), spun about
        /// the axis, tapering, the texture scrolled along it; drawn facing the camera.</summary>
        void UpdateStrands(float dt, Camera cam, float power, float lengthScale)
        {
            spinTime += dt;
            foreach (var (mesh, r, i, k) in strands)
            {
                if (mesh == null) continue;
                if (cam == null || power <= 0.01f) { mesh.Clear(); continue; }
                float size = scales[i], length = spiralLength * lengthScale * size;
                var frame = transform.rotation * turns[i] * Quaternion.LookRotation(Vector3.back, Vector3.up);
                var origin = transform.TransformPoint(nozzles[i]);
                float phase = (float)k / Mathf.Max(1, spiralCount) + spiralSpin * spinTime;
                float scroll = spiralScroll * spinTime + k * 0.37f;
                var c = Tinted(spiralTint, i) * (spiralIntensity * power);
                rpos.Clear(); rwidth.Clear(); rcol.Clear(); rv.Clear();
                for (int j = 0; j < StrandPoints; j++)
                {
                    float s = j / (StrandPoints - 1f);
                    float a = 2f * Mathf.PI * (spiralTurns * s + phase);
                    float radius = Mathf.Lerp(spiralRadius0, spiralRadius1, s) * size;
                    // (the nozzle's outline: the helix runs along it; the frame's x is the mount's -x)
                    float f = Factor(i, Mathf.PI - a);
                    rpos.Add(origin + frame * new Vector3(Mathf.Cos(a) * radius * f, Mathf.Sin(a) * radius * f, s * length));
                    rwidth.Add(spiralHalfWidth * size * Mathf.Lerp(1f, 0.5f, s));
                    // GoF3's strands: about half bright at the nozzle, full a tenth along, then down to nothing at the end
                    // (squared: in GoF3's flight the crackle is gone well before the strands' full length).
                    float fade = Mathf.Lerp(0.45f, 1f, Mathf.Clamp01(s * 10f)) * (1f - s) * (1f - s);
                    rcol.Add(new Color(c.r * fade, c.g * fade, c.b * fade, 1f));
                    rv.Add(s * spiralRepeat - scroll);
                }
                Ribbon(mesh, r.transform, cam.transform.position);
            }
        }

        /// <summary>A camera-facing ribbon through rpos (rwidth half widths, rcol colours, rv the texture's v along it; u across)
        /// into 'mesh' in 'space', both faces.</summary>
        void Ribbon(Mesh mesh, Transform space, Vector3 eye)
        {
            verts.Clear(); uvs.Clear(); vcolours.Clear(); tris.Clear();
            int n = rpos.Count;
            for (int j = 0; j < n; j++)
            {
                var along = rpos[Mathf.Min(n - 1, j + 1)] - rpos[Mathf.Max(0, j - 1)];
                if (along.sqrMagnitude < 1e-8f) along = transform.forward;
                var side = Vector3.Cross(along, eye - rpos[j]).normalized * rwidth[j];
                verts.Add(space.InverseTransformPoint(rpos[j] - side));
                verts.Add(space.InverseTransformPoint(rpos[j] + side));
                uvs.Add(new Vector2(0f, rv[j])); uvs.Add(new Vector2(1f, rv[j]));
                vcolours.Add(rcol[j]); vcolours.Add(rcol[j]);
                int m = verts.Count;
                if (m >= 4) tris.AddRange(new[] { m - 4, m - 2, m - 3, m - 3, m - 2, m - 1, m - 4, m - 3, m - 2, m - 3, m - 1, m - 2 });   // both faces
            }
            mesh.Clear();
            if (n < 2) return;
            mesh.SetVertices(verts); mesh.SetUVs(0, uvs); mesh.SetColors(vcolours); mesh.SetTriangles(tris, 0);
            mesh.RecalculateBounds();
        }

        static Shader flowShader;
        static bool flowLoaded;

        /// <summary>The cone's cards drawn with GoF3's flow (GoF2/ModEngineFlow: the texture churning in a moving field, as GoF3's
        /// exhaust materials' UVAnim flow does): 'flow' is the engineFx's [speed, strength, tiling] (null = 1, 1, 0.5; speed 0 =
        /// the plain additive, a still texture). Before, every GoF3 engine's exhaust stood still: the Terran and Vossk ones,
        /// whose streak is straight, had nothing moving at all.</summary>
        static void Flowing(Material mat, float[] flow)
        {
            if (mat == null || mat.shader != null && mat.shader.name == "GoF2/ModEngineFlow") return;   // (a shared one, made before)
            float speed = flow != null && flow.Length >= 1 ? flow[0] : 1f;
            if (speed <= 0f) return;
            if (!flowLoaded) { flowLoaded = true; flowShader = Resources.Load<Shader>("GoF2Mods/ModEngineFlow"); }
            if (flowShader == null || !flowShader.isSupported) return;
            mat.shader = flowShader;
            mat.SetFloat("_FlowSpeed", speed);
            mat.SetFloat("_FlowStrength", flow != null && flow.Length >= 2 ? flow[1] : 1f);
            mat.SetFloat("_FlowTiling", flow != null && flow.Length >= 3 ? flow[2] : 0.5f);
        }

        void SetColour(Renderer r, Color c)
        {
            if (r == null) return;
            r.GetPropertyBlock(block);
            block.SetColor(ColorId, new Color(c.r, c.g, c.b, 1f));
            r.SetPropertyBlock(block);
        }

        Color Tinted(Color tint, int i) => tint.a > 0f ? tint : colours[i];

        /// <summary>The way exhaust 'i' blows (world space): the ship's backward, turned by the mount.</summary>
        Vector3 Back(int i) => transform.rotation * (turns[i] * Vector3.back);

        /// <summary>Nozzle i's outline against its mean radius in a direction of its mount's plane (1: round).</summary>
        float Factor(int i, float angle) => i < profiles.Count ? ModExhausts.FactorOf(profiles[i]?.r, angle) : 1f;

        bool Shaped(int i) => i < profiles.Count && profiles[i]?.r != null;

        void UpdateTrails(float dt, Camera cam, float power)
        {
            float speed0 = trailLength / trailTime * Mathf.Lerp(0.3f, 1f, thrust) * (1f + 0.5f * boost);
            var right = transform.right; var up = transform.up;
            foreach (var tr in trails)
            {
                var pts = tr.points;
                float size = scales[tr.engine], speed = speed0 * size, wander = trailWander * size;
                var back = Back(tr.engine);
                // Age, move and drift: the sideways drift grows (a random walk), so each stream wanders more toward its end.
                for (int j = pts.Count - 1; j >= 0; j--)
                {
                    var q = pts[j];
                    q.age += dt;
                    if (q.age >= trailTime) { pts.RemoveAt(j); continue; }
                    var kick = Random.insideUnitSphere;
                    kick -= Vector3.Project(kick, q.vel);   // across the stream only
                    q.drift += kick * (wander * 0.25f * Mathf.Sqrt(dt) / (trailTime * Mathf.Sqrt(trailTime)));   // a little turbulence (a random walk: the same at any frame rate)
                    q.pos += (q.vel + q.drift) * dt;
                }
                if (power > 0.02f)
                {
                    tr.emitTimer -= dt;
                    float half = coneHalfWidth * scales[tr.engine];   // the effect's nozzle radius, sized like the cone
                    var off = tr.start * (half * Factor(tr.engine, Mathf.Atan2(tr.start.y, tr.start.x)));   // out to the outline
                    var nozzle = transform.TransformPoint(nozzles[tr.engine] + turns[tr.engine] * new Vector3(off.x, off.y, 0f));
                    while (tr.emitTimer <= 0f && pts.Count < MaxPoints)
                    {
                        tr.emitTimer += EmitInterval;
                        // The sway: an ease toward a new random sideways speed, so successive points move alike and the stream
                        // bends in smooth waves (each point on its own made a zigzag).
                        var target = (right * Random.Range(-1f, 1f) + up * Random.Range(-1f, 1f)) * (wander / trailTime);
                        tr.sway = Vector3.Lerp(tr.sway, target, SwayEase);
                        pts.Add(new Point { pos = nozzle, vel = velocity + back * speed, drift = tr.sway, age = 0f, bright = Random.Range(0.7f, 1.15f) });
                    }
                    if (pts.Count > 0) pts[pts.Count - 1].pos = nozzle;   // the newest point stays on the nozzle
                }
                Build(tr, cam, power);
            }
        }

        void Build(Trail tr, Camera cam, float power)
        {
            var pts = tr.points;
            verts.Clear(); uvs.Clear(); vcolours.Clear(); tris.Clear();
            var mesh = tr.mesh;
            if (pts.Count < 2 || cam == null) { mesh.Clear(); return; }
            var space = tr.renderer.transform;
            var eye = cam.transform.position;
            var c = Tinted(trailTint, tr.engine) * (trailIntensity * power);
            float halfWidth = trailHalfWidth * scales[tr.engine];
            for (int j = pts.Count - 1; j >= 0; j--)   // newest (the nozzle) first
            {
                var q = pts[j];
                var next = pts[Mathf.Max(0, j - 1)].pos; var prev = pts[Mathf.Min(pts.Count - 1, j + 1)].pos;
                var along = next - prev;
                if (along.sqrMagnitude < 1e-8f) along = transform.forward;
                var side = Vector3.Cross(along, eye - q.pos).normalized;
                float life = q.age / trailTime;
                float w = halfWidth * Mathf.Lerp(1f, 0.35f, life);
                // In from the nozzle, out toward the end; each point its own brightness (GoF3's streaks overlap unevenly: the
                // stream flickers along its length).
                float fade = Mathf.Clamp01(life * 12f) * (1f - life) * (1f - life) * q.bright;
                verts.Add(space.InverseTransformPoint(q.pos - side * w));
                verts.Add(space.InverseTransformPoint(q.pos + side * w));
                uvs.Add(new Vector2(0f, 0.5f)); uvs.Add(new Vector2(1f, 0.5f));   // the streak's middle across: one continuous stream
                var col = new Color(c.r * fade, c.g * fade, c.b * fade, 1f);
                vcolours.Add(col); vcolours.Add(col);
                int n = verts.Count;
                if (n >= 4) tris.AddRange(new[] { n - 4, n - 2, n - 3, n - 3, n - 2, n - 1, n - 4, n - 3, n - 2, n - 3, n - 1, n - 2 });   // both faces
            }
            mesh.Clear();
            mesh.SetVertices(verts); mesh.SetUVs(0, uvs); mesh.SetColors(vcolours); mesh.SetTriangles(tris, 0);
            mesh.RecalculateBounds();
        }
    }
}
