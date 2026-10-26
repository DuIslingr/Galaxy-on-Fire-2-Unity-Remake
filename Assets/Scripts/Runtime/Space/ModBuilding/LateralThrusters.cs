// LateralThrusters.cs
// Remake mods: a mod ship's manoeuvring jets (mounts of slotType 4 with a 'direction'; EVERSPACE 2's SKT_LateralThruster
// sockets, which fire its P_Vehicle_LateralThruster), as EVERSPACE 2 draws and drives them (2026-10-24, decompiled: the
// Cascade system's emitters, M_Vehicle_LateralThruster's compiled shader and BP_Ship_Player's tick; the ES2 importer's
// research/engine_exhaust.md). Each jet is the system's two sprites (GoF2/ModEs2Particle kinds 0 and 1): a 300 x 80 cm
// card along the way it blows, turned about it toward the camera, whose half beyond the socket shows, and a 100 x 100 cm
// disc facing along it, both in the jet's colour x 20 with alpha Opacity x (1 + 3 Boost). Per tick, f the jet's way:
//   Opacity = sat(f . -input + sat(f . velocity^) x (no input) + gravity term)   (the jets pushing the ship where it is
//             asked to go; with no input, those blowing along the velocity: the dampers braking it; no gravity in space)
//   Boost   = max(f . -input x boosting, gravity term)
// at once, no easing; only on the player's ship (BP_Ship_Player; EngineFlame.Pilot) and while the hangar's Customize screen
// runs the engines (every jet at 0.35, as EVERSPACE 2's customization screen shows them), hidden in the turret view's
// cockpit cameras as EVERSPACE 2 hides them in its first-person view (not done: the remake has no such view of these ships).
// The colour: a kit colour slot targeting the "lateral thruster" material ("property": "boost", EVERSPACE 2's lateral thruster
// colour) sets its hue, else the boost colour of the ship's own flames, else EVERSPACE 2's default (0.05, 0.405, 1). Not done: the
// system's third emitter, a point light of 2 m at each jet (exponent 16: only the hull right at the socket). The jets sit under
// the engine glow part, so they go with the engines (parked, mining, cutscenes) and the hangar heights and shadows leave them out.

using System.Collections.Generic;
using System.Linq;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using UnityEngine;
using UnityEngine.Rendering;

namespace GoF2Remake.Modding
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public class LateralThrusters : MonoBehaviour
    {
        const float CardHalfLength = 1.5f, CardHalfWidth = 0.4f;   // EVERSPACE 2 metres (300 x 80 cm)
        const float DiscHalf = 0.5f, DiscCameraOffset = 0.1f;     // 100 x 100 cm, 10 cm toward the camera
        const float ColourScale = 20f;                             // ColorScaleOverLife 20
        const float PreviewLevel = 0.35f;                          // each jet while the Customize screen runs the engines

        static readonly int BoostColorId = Shader.PropertyToID("_BoostColor");
        static readonly Color DefaultColour = new Color(0.05f, 0.405164f, 1f, 1f);   // the system's "Color" default

        [SerializeField] MeshFilter cards, discs;
        [SerializeField] Vector3[] directions = new Vector3[0];   // ship space, where each jet blows

        /// <summary>Testing (the Editor's eval): overrides what the ship asks for while set (ship frame, x right, y up, z forward).</summary>
        public static Vector3? TestInput;

        EngineFlame flame;
        bool ready, inStation;
        Color colour;
        readonly List<Color> colours = new List<Color>();

        /// <summary>Adds the jets for the slotType-4 mounts to a ship template (none: nothing). 'parent' is the engine glow
        /// part when there is one; 'es2Scale' Unity metres per EVERSPACE 2 metre (the kit's scale).</summary>
        public static void Add(GameObject root, Transform parent, IEnumerable<WeaponMount> mounts, float es2Scale)
        {
            var list = mounts?.Where(m => m != null && m.slotType == 4 && m.direction != null && m.direction.Length >= 3).ToList();
            var shader = Es2EngineVfx.Shader;
            if (list == null || list.Count == 0 || shader == null) return;
            var dirs = new List<Vector3>(); var at = new List<Vector3>();
            foreach (var m in list)
            {
                var d = new Vector3(-m.direction[0], m.direction[1], m.direction[2]).normalized;
                if (d == Vector3.zero) continue;
                dirs.Add(d); at.Add(WeaponSystem.MountToLocal(m));
            }
            if (dirs.Count == 0) return;
            var holder = new GameObject("engine_glow_thruster");
            holder.transform.SetParent(parent != null ? parent : root.transform, false);
            var c = root.AddComponent<LateralThrusters>();
            c.directions = dirs.ToArray();
            float s = es2Scale > 0f ? es2Scale : 1f;
            c.cards = Part(holder.transform, "engine_glow_thruster_cards", 0, Quads(at, dirs, new Vector2(CardHalfLength * s, CardHalfWidth * s)), shader);
            c.discs = Part(holder.transform, "engine_glow_thruster_discs", 1, Quads(at, dirs, new Vector2(DiscHalf * s, DiscCameraOffset * s)), shader);
        }

        static MeshFilter Part(Transform parent, string name, int kind, Mesh mesh, Shader shader)
        {
            var go = new GameObject(name);
            go.transform.SetParent(parent, false);
            var mf = go.AddComponent<MeshFilter>();
            mf.sharedMesh = mesh;
            var r = go.AddComponent<MeshRenderer>();
            // (named for the kit colour slots, which colour the "lateral thruster" material's _BoostColor)
            var mat = new Material(shader) { name = "lateral thruster" };
            mat.SetFloat("_Kind", kind);
            mat.SetFloat("_Gain", ModMaterials.Es2FlameGain / 1000f);
            mat.SetColor(BoostColorId, DefaultColour);
            var noise = ModAssets.Get()?.engineFlame;
            if (noise != null && noise.HasProperty("_NoiseMap")) mat.SetTexture("_NoiseMap", noise.GetTexture("_NoiseMap"));
            r.sharedMaterial = mat;
            r.shadowCastingMode = ShadowCastingMode.Off;
            r.receiveShadows = false;
            return mf;
        }

        /// <summary>One quad per jet: every corner at the socket with the jet's way as its normal (the shader spreads it).</summary>
        static Mesh Quads(List<Vector3> at, List<Vector3> dirs, Vector2 size)
        {
            var v = new List<Vector3>(); var n = new List<Vector3>(); var uv = new List<Vector2>(); var uv1 = new List<Vector2>();
            var t = new List<int>(); var col = new List<Color>();
            float reach = Mathf.Max(size.x, size.y);
            var bounds = new Bounds(at[0], Vector3.zero);
            for (int i = 0; i < at.Count; i++)
            {
                int b = v.Count;
                foreach (var corner in new[] { new Vector2(0, 0), new Vector2(1, 0), new Vector2(1, 1), new Vector2(0, 1) })
                {
                    v.Add(at[i]); n.Add(dirs[i]); uv.Add(corner); uv1.Add(size); col.Add(Color.clear);
                }
                t.AddRange(new[] { b, b + 1, b + 2, b, b + 2, b + 3 });
                bounds.Encapsulate(new Bounds(at[i], Vector3.one * reach * 2.2f));
            }
            // ("_add": the hull collision, shadows, levels of detail and aim spots skip it like the game's additive layers;
            // its corners all at the socket, PhysX failed to "clean" it as a hull)
            var m = new Mesh { name = "lateral_thrusters_add" };
            m.SetVertices(v); m.SetNormals(n); m.SetUVs(0, uv); m.SetUVs(1, uv1); m.SetColors(col); m.SetTriangles(t, 0);
            m.bounds = bounds;
            m.MarkDynamic();
            return m;
        }

        void OnEnable()
        {
            inStation = Visuals.EngineDrive.IsStationModel(transform);
        }

        void OnDestroy()
        {
            if (!ready) return;
            if (cards != null) Destroy(cards.sharedMesh);
            if (discs != null) Destroy(discs.sharedMesh);
        }

        void Setup()
        {
            ready = true;
            flame = GetComponent<EngineFlame>();
            // (the template's meshes are shared by every copy of the ship: each copy colours its own)
            if (cards != null) cards.sharedMesh = Instantiate(cards.sharedMesh);
            if (discs != null) discs.sharedMesh = Instantiate(discs.sharedMesh);
            // The jets' own colour when a colour slot set it, else the ship's own flames' boost colour, else the default.
            var own = cards != null ? cards.GetComponent<Renderer>().sharedMaterial : null;
            colour = own != null ? own.GetColor(BoostColorId) : DefaultColour;
            if (own == null || own.GetColor(BoostColorId) == DefaultColour)
                foreach (var r in GetComponentsInChildren<Renderer>(true))
                {
                    var f = r.sharedMaterials.FirstOrDefault(EngineFlame.IsFlame);
                    if (f == null) continue;
                    colour = f.GetColor(BoostColorId);
                    break;
                }
            // (the discs carry the cards' colour: a colour slot recolours both materials alike)
            // EVERSPACE 2's jet colour is a plain colour (its default's brightest channel 1) scaled x 20 by the system; a
            // colour slot's or flame's boost colour carries its own intensity (the ES2 kits' x 8): only its hue counts here.
            float top = Mathf.Max(colour.r, Mathf.Max(colour.g, colour.b));
            colour = top > 1e-4f ? new Color(colour.r / top, colour.g / top, colour.b / top, 1f) : DefaultColour;
        }

        void LateUpdate()
        {
            if (!ready) Setup();
            if (directions.Length == 0 || cards == null || discs == null) return;
            var preview = inStation ? GetComponentInParent<Visuals.EnginePreview>() : null;
            bool previewing = preview != null && preview.isActiveAndEnabled;
            bool pilot = flame != null && flame.Pilot;
            colours.Clear();
            bool any = false;
            Vector3 input = TestInput ?? (pilot ? flame.Input : Vector3.zero);
            Vector3 vel = pilot ? transform.InverseTransformDirection(flame.Velocity) : Vector3.zero;
            var velDir = vel.sqrMagnitude > 1e-4f ? vel.normalized : Vector3.zero;
            bool noInput = input.sqrMagnitude < 1e-6f;
            bool boosting = pilot && flame.Boosting;
            for (int i = 0; i < directions.Length; i++)
            {
                float opacity = 0f, boost = 0f;
                if (pilot || TestInput.HasValue)
                {
                    float a = Vector3.Dot(directions[i], -input);
                    float brake = noInput ? Mathf.Clamp01(Vector3.Dot(directions[i], velDir)) : 0f;
                    opacity = Mathf.Clamp01(a + brake);
                    boost = Mathf.Max(0f, a * (boosting ? 1f : 0f));
                }
                if (previewing) opacity = Mathf.Max(opacity, PreviewLevel);
                float alpha = opacity * (1f + 3f * Mathf.Clamp01(boost));
                if (alpha > 0.001f) any = true;
                var c = new Color(colour.r * ColourScale, colour.g * ColourScale, colour.b * ColourScale, alpha);
                for (int k = 0; k < 4; k++) colours.Add(c);
            }
            SetColours(cards, any);
            SetColours(discs, any);
        }

        void SetColours(MeshFilter mf, bool on)
        {
            var r = mf.GetComponent<Renderer>();
            if (r.enabled != on) r.enabled = on;
            if (on) mf.sharedMesh.SetColors(colours);
        }
    }
}
