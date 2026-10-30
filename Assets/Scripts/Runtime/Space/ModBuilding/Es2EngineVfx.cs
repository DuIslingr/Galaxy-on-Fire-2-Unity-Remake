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
// The player's chosen engine trails (the Customize screen's Engine trail / Booster trail, EVERSPACE 2's
// BP_Ship_Player.UpdateEngineTrails: ThrustParticlesID for the engine sockets, BoostParticlesID for the booster sockets) take
// the veil's place at their sockets: Es2Trails runs them, GoF2/ModEs2Trail draws them.
// EVERSPACE 2's centimetres are its metres x the kit's scale here (es2Scale). Nothing of it in the docked station (the
// flames do the hangar's engines) but the player's trails while the Customize screen runs the engines (EVERSPACE 2's
// HangarMode: the particles keep their birth velocity, the colours x 4, the alphas squared).

using System.Collections.Generic;
using System.Linq;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.Rendering.Universal;

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
        Visuals.EnginePreview preview;
        Trail[] trails;
        // the player's chosen trails per socket (null: the veil) and the build text they come from
        Es2Trails[] custom;
        string customKey;
        float distance;   // the owner's distance flown, cm (the ribbons' RibbonUVDistance)
        readonly Dictionary<Es2Trails.Render, MeshFilter> trailParts = new Dictionary<Es2Trails.Render, MeshFilter>();
        static Shader trailShader;
        static bool trailShaderLoaded;
        static Shader TrailShader
        {
            get
            {
                if (!trailShaderLoaded) { trailShaderLoaded = true; trailShader = Resources.Load<Shader>("GoF2Mods/ModEs2Trail"); }
                return trailShader;
            }
        }
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
            inStation = Visuals.EngineDrive.IsStationModel(transform);
            if (trails != null) foreach (var t in trails) { t.points.Clear(); t.hasLast = false; t.spawnDue = 0f; }
            if (custom != null) foreach (var c in custom) c?.Clear();
        }

        void OnDestroy()
        {
            foreach (var mf in new[] { veil, glow, npcTrail }.Concat(trailParts.Values))
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
            // the Customize screen's running engines (EnginePreview): the player's trails in EVERSPACE 2's HangarMode
            if (inStation && preview == null) preview = GetComponentInParent<Visuals.EnginePreview>();
            bool hangar = inStation && preview != null && preview.isActiveAndEnabled;
            float thrust = inStation && !hangar ? 0f : Mathf.Max(0f, flame.Thrust.z), boost = inStation && !hangar ? 0f : flame.Boost;
            UpdateCustomTrails((pilot || hangar) && trailsOn, hangar, dt, thrust, boost);
            UpdateVeils((pilot || hangar) && trailsOn, hangar, dt, thrust, boost);
            UpdateLights(pilot, thrust, boost);
            UpdateGlow(!pilot && !inStation && glowOn, thrust, boost);
            UpdateNpcTrails(!pilot && !inStation && trailsOn, dt, thrust, boost);
        }

        // ---- the veil ---------------------------------------------------------------------------------------------------
        void UpdateVeils(bool on, bool hangar, float dt, float thrust, float boost)
        {
            BeginMesh();
            float s = es2Scale;
            var ownerVel = transform.InverseTransformDirection(flame.Velocity);
            var inherit = -Vector3.ClampMagnitude(ownerVel, VeilInheritLimit);
            float ease = hangar ? 0f : 1f - Mathf.Pow(VeilSmoothing, dt * VeilFalloffTime);
            for (int i = 0; i < sockets.Length; i++)
            {
                var t = trails[i];
                bool socketOn = on && (custom == null || custom[i] == null);
                float opacity = socketOn ? Opacity(i, thrust, boost) : 0f;
                // age, move and drop the particles (local space: the ship's frame)
                for (int k = t.points.Count - 1; k >= 0; k--)
                {
                    var p = t.points[k];
                    p.age += dt;
                    if (p.age >= VeilLife || !socketOn) { t.points.RemoveAt(k); continue; }
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
                var c = ColourOf(i) * VeilColour * (hangar ? 4f : 1f);
                float total = 0f;
                for (int k = 1; k < t.points.Count; k++) total += Vector3.Distance(t.points[k].pos, t.points[k - 1].pos);
                float run = 0f;
                int first = v.Count;
                for (int k = 0; k < t.points.Count; k++)
                {
                    var p = t.points[k];
                    if (k > 0) run += Vector3.Distance(p.pos, t.points[k - 1].pos);
                    var tangent = k + 1 < t.points.Count ? t.points[k + 1].pos - p.pos : p.pos - t.points[k - 1].pos;
                    float a = VeilAlpha * 0.5f * (1f + Mathf.Cos(Mathf.PI * Mathf.Clamp01(p.age / VeilLife))) * opacity * (hangar ? VeilAlpha * opacity : 1f);
                    AddRibbonPoint(p.pos, tangent, total > 0f ? run / total : 0f, VeilHalfWidth * s, new Color(c.r, c.g, c.b, a));
                }
                AddRibbonStrip(first, t.points.Count);
            }
            EndMesh(veil);
        }

        // ---- the player's chosen trails ---------------------------------------------------------------------------------
        /// <summary>The player's build's trails for each socket (the engine sockets' "trail", the booster sockets'
        /// "boosttrail"), made again when the build changes (the Customize screen).</summary>
        void ResolveTrails(bool on)
        {
            if (!on) return;
            int ship = Session.ShipIndex;
            string key = ModShipKits.BuildKey(ship);
            string text = key != null && Session.ShipBuilds.TryGetValue(key, out var t) ? t : "";
            text = ship + "|" + text;
            if (text == customKey) return;
            customKey = text;
            var kit = ModShipKits.CustomizationOf(ship);
            var build = kit != null ? ModShipKits.PlayerBuild(ship) : null;
            var engine = kit?.TrailOf(build, false);
            var booster = kit?.TrailOf(build, true);
            if (engine == null && booster == null) { custom = null; return; }
            custom = new Es2Trails[sockets.Length];
            for (int i = 0; i < sockets.Length; i++)
            {
                var tr = sockets[i].booster ? booster : engine;
                custom[i] = tr != null ? new Es2Trails(tr) : null;
            }
            // each render kind's textures from the trail that uses it
            foreach (var c in custom)
                if (c != null)
                    foreach (var e in c.emitters) SetTrailTextures(TrailPart(e.render), c.trail);
        }

        MeshFilter TrailPart(Es2Trails.Render render)
        {
            if (trailParts.TryGetValue(render, out var mf) && mf != null) return mf;
            var go = new GameObject("es2_trail_" + render);
            go.transform.SetParent(transform, false);
            mf = go.AddComponent<MeshFilter>();
            mf.sharedMesh = new Mesh { name = "es2_trail_" + render + "_add" };
            mf.sharedMesh.MarkDynamic();
            var r = go.AddComponent<MeshRenderer>();
            var mat = new Material(TrailShader) { name = "es2_trail_" + render };
            mat.SetFloat("_Kind", (int)render);
            mat.SetFloat("_Gain", ModMaterials.Es2FlameGain / 1000f);
            mat.SetFloat("_Es2Scale", es2Scale);
            var urp = GraphicsSettings.currentRenderPipeline as UniversalRenderPipelineAsset;
            mat.SetFloat("_SoftParticles", urp != null && urp.supportsCameraDepthTexture ? 1f : 0f);
            mat.SetTexture("_GradTex", Es2Trails.GradientTexture);
            mat.SetTexture("_Noise3D", Es2Trails.Noise3D);
            r.sharedMaterial = mat;
            r.shadowCastingMode = ShadowCastingMode.Off;
            r.receiveShadows = false;
            r.enabled = false;
            trailParts[render] = mf;
            return mf;
        }

        static void SetTrailTextures(MeshFilter mf, ModShipKits.EngineTrail trail)
        {
            var mat = mf.GetComponent<Renderer>().sharedMaterial;
            var mod = trail.mod;
            if (!string.IsNullOrEmpty(trail.texture)) mat.SetTexture("_MainTex", ModMaterials.Texture(mod, trail.texture, false));
            if (!string.IsNullOrEmpty(trail.mask)) mat.SetTexture("_MaskTex", ModMaterials.Texture(mod, trail.mask, false));
            if (!string.IsNullOrEmpty(trail.normal)) mat.SetTexture("_NormalTex", ModMaterials.Texture(mod, trail.normal, true, false, true));
        }

        readonly List<Vector3> tv = new List<Vector3>(), tn = new List<Vector3>();
        readonly List<Vector2> tuv = new List<Vector2>(), tsize = new List<Vector2>();
        readonly List<Vector4> textra = new List<Vector4>(), tdyn = new List<Vector4>();
        readonly List<Color> tcol = new List<Color>();
        readonly List<int> ttri = new List<int>();
        readonly List<(Es2Trails trails, Es2Trails.Emitter e, int socket, int index, float depth)> sorted = new List<(Es2Trails, Es2Trails.Emitter, int, int, float)>();

        // EVERSPACE 2's socket frame (x forward, y right, z up) to the ship's (Unity: x right, y up, z forward)
        static Vector3 Map(Vector3 v) => new Vector3(v.y, v.z, v.x);

        void UpdateCustomTrails(bool on, bool hangar, float dt, float thrust, float boost)
        {
            ResolveTrails(on);
            float cm = es2Scale / 100f;   // a centimetre of EVERSPACE 2 in the ship's frame
            var local = transform.InverseTransformDirection(flame.Velocity) / cm;
            var ownerCm = new Vector3(local.z, local.x, local.y);
            if (!hangar) distance += flame.Velocity.magnitude / cm * dt;
            if (custom != null)
                for (int i = 0; i < sockets.Length; i++)
                    custom[i]?.Step(dt, on ? Opacity(i, thrust, boost) : 0f, sockets[i].scale, ColourOf(i), ownerCm, distance, hangar, on);
            var cam = Camera.main;
            foreach (var kv in trailParts)
            {
                var render = kv.Key;
                BeginTrailMesh();
                if (custom != null && on)
                {
                    if (render == Es2Trails.Render.Smoke && cam != null)
                    {
                        // (ViewDepth sort: the farthest first)
                        sorted.Clear();
                        var camLocal = transform.InverseTransformPoint(cam.transform.position);
                        for (int i = 0; i < custom.Length; i++)
                            if (custom[i] != null)
                                foreach (var e in custom[i].emitters)
                                    if (e.render == render)
                                        for (int k = 0; k < e.particles.Count; k++)
                                            sorted.Add((custom[i], e, i, k, (sockets[i].at + Map(e.particles[k].pos) * cm - camLocal).sqrMagnitude));
                        sorted.Sort((a, b) => b.depth.CompareTo(a.depth));
                        foreach (var x in sorted) AddTrailParticle(x.trails, x.e, x.socket, x.e.particles[x.index], hangar, cm);
                    }
                    else
                        for (int i = 0; i < custom.Length; i++)
                            if (custom[i] != null)
                                foreach (var e in custom[i].emitters)
                                    if (e.render == render) AddEmitter(custom[i], e, i, hangar, cm);
                }
                EndTrailMesh(kv.Value);
            }
        }

        void AddEmitter(Es2Trails tr, Es2Trails.Emitter e, int socket, bool hangar, float cm)
        {
            switch (e.render)
            {
                case Es2Trails.Render.DarkTrail:
                case Es2Trails.Render.FireTrail:
                case Es2Trails.Render.Lines:
                case Es2Trails.Render.LightningRibbon:
                case Es2Trails.Render.Veil:
                    AddTrailRibbon(tr, e, socket, hangar, cm);
                    break;
                default:
                    foreach (var p in e.particles) AddTrailParticle(tr, e, socket, p, hangar, cm);
                    break;
            }
        }

        void AddTrailParticle(Es2Trails tr, Es2Trails.Emitter e, int socket, in Es2Trails.Particle p, bool hangar, float cm)
        {
            var at = sockets[socket].at;
            var rgb = tr.Colour(e, p, hangar);
            var c = new Color(rgb.x, rgb.y, rgb.z, tr.Alpha(e, p, hangar));
            float rel = Mathf.Clamp01(p.age / Mathf.Max(p.life, 1e-5f));
            var size = tr.Size(e, p);
            if (e.render == Es2Trails.Render.Shape)
            {
                var m = tr.trail.mesh;
                if (m == null) return;
                var sc = new Vector3(size.x, size.y, size.y);
                float cs = Mathf.Cos(p.turn), sn = Mathf.Sin(p.turn);
                Vector3 Turn(Vector3 v) => new Vector3(v.x, v.y * cs - v.z * sn, v.y * sn + v.z * cs);
                int b = tv.Count;
                for (int k = 0; k < m.positions.Length; k++)
                {
                    var mp = m.positions[k];
                    var pos = Turn(new Vector3(mp.x * sc.x, mp.y * sc.y, mp.z * sc.z)) + p.pos;
                    var mn = m.normals[k];
                    var nrm = Turn(new Vector3(mn.x / Mathf.Max(sc.x, 1e-4f), mn.y / Mathf.Max(sc.y, 1e-4f), mn.z / Mathf.Max(sc.z, 1e-4f))).normalized;
                    tv.Add(at + Map(pos) * cm); tn.Add(Map(nrm)); tuv.Add(m.uv[k]); tsize.Add(Vector2.zero);
                    textra.Add(new Vector4(0f, p.random, rel, 0f)); tdyn.Add(p.dyn); tcol.Add(c);
                }
                foreach (int i in m.indices) ttri.Add(b + i);
                return;
            }
            var anchor = p.pos;
            if (e.render == Es2Trails.Render.Bubbles) anchor += Es2Trails.Orbit(p);
            var dyn = e.render == Es2Trails.Render.LightningArc ? new Vector4(0f, 0f, Mathf.Clamp01(rel * 4f), 0.01f) : p.dyn;
            var extra = new Vector4(p.rot * Mathf.Deg2Rad, p.random, rel, 0f);
            var axis = Map(p.vel.sqrMagnitude > 1e-6f ? p.vel.normalized : Vector3.left);
            var half = size * 0.5f * cm;
            int b0 = tv.Count;
            foreach (var corner in new[] { new Vector2(0, 0), new Vector2(1, 0), new Vector2(1, 1), new Vector2(0, 1) })
            {
                tv.Add(at + Map(anchor) * cm); tn.Add(axis); tuv.Add(corner); tsize.Add(half);
                textra.Add(extra); tdyn.Add(dyn); tcol.Add(c);
            }
            ttri.AddRange(new[] { b0, b0 + 1, b0 + 2, b0, b0 + 2, b0 + 3 });
        }

        void AddTrailRibbon(Es2Trails tr, Es2Trails.Emitter e, int socket, bool hangar, float cm)
        {
            var pts = e.particles;
            if (pts.Count < 2) return;
            // newest first: U1 runs 0 at the nozzle to 1 at the end, by length (ScaledUsingRibbonSegmentLength)
            pts.Sort((a, b) => a.age.CompareTo(b.age));
            var at = sockets[socket].at;
            float total = 0f;
            for (int k = 1; k < pts.Count; k++) total += Vector3.Distance(pts[k].pos, pts[k - 1].pos);
            // U0: TiledOverRibbonLength by the particles' RibbonUVDistance (Dark / Fire trail 800 cm, Lightning 2000 cm), else U1
            float tiling = e.render == Es2Trails.Render.DarkTrail || e.render == Es2Trails.Render.FireTrail ? 800f
                         : e.render == Es2Trails.Render.LightningRibbon ? 2000f : 0f;
            float run = 0f;
            int first = tv.Count;
            for (int k = 0; k < pts.Count; k++)
            {
                var p = pts[k];
                if (k > 0) run += Vector3.Distance(p.pos, pts[k - 1].pos);
                var tangent = k + 1 < pts.Count ? pts[k + 1].pos - p.pos : p.pos - pts[k - 1].pos;
                var dir = tangent.sqrMagnitude > 1e-10f ? Map(tangent.normalized) : Vector3.back;
                float u1 = total > 0f ? run / total : 0f;
                float u0 = tiling > 0f ? p.uvDistance / tiling : u1;
                var rgb = tr.Colour(e, p, hangar);
                var c = new Color(rgb.x, rgb.y, rgb.z, tr.Alpha(e, p, hangar));
                var dyn = e.render == Es2Trails.Render.Veil ? p.dyn : Vector4.zero;
                float halfWidth = p.size.x * 0.5f * cm;
                var pos = at + Map(p.pos) * cm;
                for (int side = -1; side <= 1; side += 2)
                {
                    tv.Add(pos); tn.Add(dir); tuv.Add(new Vector2(u0, side < 0 ? 0f : 1f)); tsize.Add(new Vector2(halfWidth, side));
                    textra.Add(new Vector4(0f, p.random, Mathf.Clamp01(p.age / Mathf.Max(p.life, 1e-5f)), u1)); tdyn.Add(dyn); tcol.Add(c);
                }
            }
            for (int k = 0; k + 1 < pts.Count; k++)
            {
                int a = first + k * 2;
                ttri.AddRange(new[] { a, a + 1, a + 3, a, a + 3, a + 2 });
            }
        }

        void BeginTrailMesh() { tv.Clear(); tn.Clear(); tuv.Clear(); tsize.Clear(); textra.Clear(); tdyn.Clear(); tcol.Clear(); ttri.Clear(); }

        void EndTrailMesh(MeshFilter mf)
        {
            if (mf == null) return;
            var r = mf.GetComponent<Renderer>();
            bool any = ttri.Count > 0;
            if (r.enabled != any) r.enabled = any;
            if (!any) return;
            var m = mf.sharedMesh;
            m.Clear();
            if (tv.Count > 65000) m.indexFormat = IndexFormat.UInt32;
            m.SetVertices(tv); m.SetNormals(tn); m.SetUVs(0, tuv); m.SetUVs(1, tsize); m.SetUVs(2, textra); m.SetUVs(3, tdyn);
            m.SetColors(tcol); m.SetTriangles(ttri, 0);
            // (the shader spreads the points into sprites and ribbons: the bounds take in the widest)
            var bounds = new Bounds(tv[0], Vector3.zero);
            float reach = 0f;
            for (int i = 0; i < tv.Count; i++) { bounds.Encapsulate(tv[i]); reach = Mathf.Max(reach, Mathf.Abs(tsize[i].x), Mathf.Abs(tsize[i].y)); }
            bounds.Expand(reach * 4.4f);
            m.bounds = bounds;
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
