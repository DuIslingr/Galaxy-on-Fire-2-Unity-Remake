// Es2Trails.cs
// Remake mods: EVERSPACE 2's customization engine trails (DT_ShipExhaustParticles: Stardust, Raw Combustion, Coolant Leak,
// Firestarter, Void Reverb, Thermal Blaze, Residuum, Voltaic Tendrils, Rings of Nerea, Tetragons, Delta Surge, Ion Veils;
// the Default veil stays Es2EngineVfx's own), run as EVERSPACE 2 runs them (2026-10-25, decompiled: the
// NS_Vehicle_EngineTrail_Player_* Niagara systems' VM scripts, their parameters, curves and renderers, and BP_Ship_Player's
// UpdateEngineTrails; the ES2 importer's research/engine_trails.md has every number and where it comes from). A kit's
// "trails" (ModShipKits.EngineTrail, written by the importer from the game's tables) give each one's kind, curves (the
// systems' 128-entry LUTs over the normalized age, in the order below), textures and the shape trails' mesh; the build's
// "trail" / "boosttrail" (the Customize screen's Engine trail / Booster trail) pick one for the engine sockets and one for the
// booster sockets. Drawn with GoF2/ModEs2Trail (its _Kind per material).
// Each socket's emitters live in the socket's own frame like the Niagara emitters (local space): EVERSPACE 2's X forward, Y
// right, Z up, centimetres; the Unity ship's frame is (Y, Z, X) x es2Scale / 100. What every system shares (the parameter
// collection NPC_EngineTrails_Player): particles born moving backward at 2500 cm/s, easing each frame toward standing still in
// the world (-the owner's velocity, at most 20000 cm/s) by 1 - 0.5^(dt x 0.4 [x SpeedFactor]); lifetimes from 0.4 s; the
// opacity input Booster ? Boost x Thrust : Thrust gates the births. In the hangar (the Customize screen's running engines:
// EVERSPACE 2's HangarMode) the particles keep their birth velocity, the colours are x 4 and the alphas squared.
// Curves per kind: Glitter [alpha]; Smoke [size, alpha]; Bubbles [colour, size, alpha]; Sparks [size, -]; Dark trail, Fire
// trail, Speed lines [alpha]; Lightning [ribbon alpha, arc size, arc alpha]; Rings [alpha, scale]; Squares and Triangles
// [alpha, -]; Veils [veil 1 alpha, veil 2 alpha].

using System.Collections.Generic;
using UnityEngine;

namespace GoF2Remake.Modding
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public sealed class Es2Trails
    {
        // NPC_EngineTrails_Player (cm, s)
        const float BaseVelocity = -2500f, BaseLifetime = 0.4f, FalloffTime = 0.4f, Smoothing = 0.5f, InheritLimit = 20000f;
        static readonly Vector3 SpawnOffset = new Vector3(100f, 0f, 0f);

        /// <summary>The render kinds of GoF2/ModEs2Trail.</summary>
        public enum Render { Glitter = 0, Smoke = 1, Bubbles = 2, Sparks = 3, DarkTrail = 4, FireTrail = 5, Lines = 6, LightningRibbon = 7, LightningArc = 8, Shape = 9, Veil = 10 }

        /// <summary>A trail kind's name (ModShipKits.EngineTrail.kind) to its emitters; null = not one (the Default veil).</summary>
        public static bool Known(string kind) => kind != null && Emitters(kind) != null;

        static Render[] Emitters(string kind)
        {
            switch (kind)
            {
                case "glitter": return new[] { Render.Glitter };
                case "smoke": return new[] { Render.Smoke };
                case "bubbles": return new[] { Render.Bubbles };
                case "sparks": return new[] { Render.Sparks };
                case "darktrail": return new[] { Render.DarkTrail };
                case "firetrail": return new[] { Render.FireTrail };
                case "lines": return new[] { Render.Lines };
                case "lightning": return new[] { Render.LightningRibbon, Render.LightningArc };
                case "rings": case "squares": case "triangles": return new[] { Render.Shape };
                case "veils": return new[] { Render.Veil, Render.Veil };
                default: return null;
            }
        }

        public struct Particle
        {
            public Vector3 pos, vel;        // cm, cm/s, the socket's frame
            public float age, life;
            public Vector2 size;            // full size (sprites), width (ribbons, x), scale (shapes)
            public float rot, random, uvDistance;
            public Vector4 colour;          // HDR rgb, a
            public float alpha0;            // the birth alpha (curves multiply it)
            public Vector3 axis, axisU, axisV;   // Bubbles: the turn around a random axis
            public Vector4 dyn;
            public float turn;              // Triangles: the turn about X at birth
        }

        public sealed class Emitter
        {
            public Render render;
            public int index;               // a kind's second emitter (Lightning's arcs, the second veil)
            public float due;               // particles owed
            public float phase1, phase2;    // Veils: the fixed random phases
            public readonly List<Particle> particles = new List<Particle>();
        }

        public readonly ModShipKits.EngineTrail trail;
        public readonly Emitter[] emitters;
        readonly float speedFactor;
        float emitterAge;

        public Es2Trails(ModShipKits.EngineTrail trail)
        {
            this.trail = trail;
            var r = Emitters(trail.kind);
            emitters = new Emitter[r.Length];
            for (int i = 0; i < r.Length; i++)
                emitters[i] = new Emitter { render = r[i], index = i, phase1 = Random.value * 10f, phase2 = Random.value * 10f };
            // User.SpeedFactor's defaults (the systems' exposed parameters)
            speedFactor = trail.kind == "bubbles" ? 0.7f : trail.kind == "sparks" ? 1.5f : 1f;
        }

        public void Clear() { foreach (var e in emitters) { e.particles.Clear(); e.due = 0f; } emitterAge = 0f; }

        /// <summary>A curve of the trail at a normalized age (1 without it).</summary>
        public float Curve(int index, float t)
        {
            var c = trail.curves != null && index < trail.curves.Count ? trail.curves[index] : null;
            if (c == null || c.Length == 0) return 1f;
            if (c.Length == 1) return c[0];
            float x = Mathf.Clamp01(t) * (c.Length - 1);
            int i = Mathf.Min((int)x, c.Length - 2);
            return Mathf.Lerp(c[i], c[i + 1], x - i);
        }

        static Vector3 Cone(float cosMin)
        {
            // a direction within acos(cosMin) of +X (UE's AddVelocityInCone: cos uniform in [cosMin, 1])
            float c = Mathf.Clamp(cosMin + Random.value * (1f - cosMin), -1f, 1f), s = Mathf.Sqrt(1f - c * c), a = Random.value * Mathf.PI * 2f;
            return new Vector3(c, s * Mathf.Cos(a), s * Mathf.Sin(a));
        }

        static Vector3 Box(float size) => new Vector3(Random.value - 0.5f, Random.value - 0.5f, Random.value - 0.5f) * size;

        /// <summary>One frame: 'opacity' EVERSPACE 2's InputOpacityResult, 'scale' the socket's, 'colour' its User.Color,
        /// 'ownerVelocity' the ship's velocity in the socket's frame (cm/s), 'distance' the owner's distance flown (cm, the
        /// ribbons' RibbonUVDistance), 'hangar' EVERSPACE 2's HangarMode.</summary>
        public void Step(float dt, float opacity, float scale, Color colour, Vector3 ownerVelocity, float distance, bool hangar, bool on)
        {
            emitterAge += dt;
            float sf = speedFactor;
            var inherit = -Vector3.ClampMagnitude(ownerVelocity, InheritLimit);
            foreach (var e in emitters)
            {
                bool sfFall = e.render == Render.Bubbles || e.render == Render.Sparks;
                float ease = 1f - Mathf.Pow(Smoothing, dt * FalloffTime * (sfFall ? sf : 1f));
                for (int k = e.particles.Count - 1; k >= 0; k--)
                {
                    var p = e.particles[k];
                    p.age += dt;
                    if (p.age >= Mathf.Max(p.life, 1e-5f) || !on) { e.particles.RemoveAt(k); continue; }
                    if (!hangar) p.vel = Vector3.Lerp(p.vel, inherit, ease);
                    p.pos += p.vel * dt;
                    e.particles[k] = p;
                }
                if (!on) { e.due = 0f; continue; }
                // the spawn rate and its gate (SpawnRate x the system's "random <= (opacity > 0)": none at 0; Sparks always)
                float rate;
                switch (e.render)
                {
                    case Render.Glitter: rate = 200f * scale; break;
                    case Render.Smoke: rate = 200f / Mathf.Max(scale, 1e-3f); break;
                    case Render.Bubbles: rate = 50f * scale * opacity; break;
                    case Render.Sparks: rate = 50f * sf * scale; break;
                    case Render.LightningArc: rate = 20f; break;
                    case Render.Shape: rate = 15f; break;
                    default: rate = 50f; break;
                }
                if (e.render != Render.Sparks && opacity <= 0f) { e.due = 0f; continue; }
                e.due += rate * dt;
                while (e.due >= 1f)
                {
                    e.due -= 1f;
                    // (spread over the frame like Niagara's interpolated spawn: this frame's oldest birth first)
                    float age = rate > 0f ? e.due / rate : 0f;
                    var p = Spawn(e, opacity, scale, colour, hangar, distance);
                    float easeAge = hangar ? 0f : 1f - Mathf.Pow(Smoothing, age * FalloffTime * (sfFall ? sf : 1f));
                    p.vel = Vector3.Lerp(p.vel, inherit, easeAge);
                    p.pos += p.vel * age;
                    p.age = age;
                    e.particles.Add(p);
                }
            }
        }

        Particle Spawn(Emitter e, float opacity, float scale, Color c, bool hangar, float distance)
        {
            float sf = speedFactor;
            var rgb = new Vector3(c.r, c.g, c.b);
            float hx = hangar ? 4f : 1f;
            var p = new Particle { random = Random.value, uvDistance = distance };
            Vector4 Rgb(float k) => new Vector4(rgb.x * k * hx, rgb.y * k * hx, rgb.z * k * hx, 0f);
            switch (e.render)
            {
                case Render.Glitter:
                    p.life = Random.value * 0.8f * BaseLifetime;
                    p.pos = Box(50f * scale);
                    p.vel = Cone(0.999048f) * BaseVelocity;
                    p.size = Vector2.one * 50f * (1f + Random.value);
                    p.colour = new Vector4(rgb.x, rgb.y, rgb.z, 0f);
                    p.alpha0 = c.a * Random.value * opacity;
                    break;
                case Render.Smoke:
                    p.life = BaseLifetime * (0.7f + Random.value * 0.3f);
                    p.vel = Cone(0.997564f) * BaseVelocity;
                    p.size = Vector2.one * 100f * (0.5f + Random.value * 0.5f) * scale;
                    p.rot = Random.value * 360f;
                    p.colour = Rgb(10f);
                    p.alpha0 = c.a * Mathf.Pow(Mathf.Max(0f, opacity), 3f) * (1f + Random.value);
                    p.dyn = new Vector4(Random.value, 0f, 0f, 0f);
                    break;
                case Render.Bubbles:
                {
                    p.life = (0.4f + Random.value * 0.3f) * BaseLifetime / sf;
                    p.pos = Box(50f * scale);
                    p.vel = Cone(0.996195f) * BaseVelocity * sf;
                    p.size = Vector2.one * 10f * (1f + Random.value);
                    p.colour = new Vector4(rgb.x * hx, rgb.y * hx, rgb.z * hx, 0f);
                    p.alpha0 = c.a;
                    p.axis = Random.onUnitSphere;
                    p.axisU = Vector3.Cross(p.axis, Mathf.Abs(p.axis.y) < 0.99f ? Vector3.up : Vector3.right).normalized;
                    p.axisV = Vector3.Cross(p.axis, p.axisU);
                    p.dyn = new Vector4(Random.value, 0f, 0f, 0f);
                    break;
                }
                case Render.Sparks:
                    p.life = BaseLifetime / sf * 0.8f;
                    p.pos = Box(50f * scale);
                    p.vel = Cone(0.996195f) * BaseVelocity * sf;
                    p.size = Vector2.one * 2f * (1f + Random.value);
                    p.colour = Rgb(50f);
                    p.alpha0 = c.a * Random.value * opacity;
                    break;
                case Render.DarkTrail:
                case Render.FireTrail:
                case Render.Lines:
                case Render.LightningRibbon:
                    p.life = e.render == Render.Lines || e.render == Render.LightningRibbon ? BaseLifetime : BaseLifetime * 1.1f;
                    p.pos = SpawnOffset;
                    p.vel = new Vector3(BaseVelocity, 0f, 0f);
                    p.size = new Vector2((e.render == Render.FireTrail ? 80f : e.render == Render.LightningRibbon ? 120f : 60f) * scale, 0f);
                    p.colour = Rgb(e.render == Render.FireTrail ? 30f : e.render == Render.LightningRibbon ? 100f : 10f);
                    p.alpha0 = c.a * Mathf.Pow(Mathf.Max(0f, opacity), e.render == Render.Lines ? 2f : 4f);
                    break;
                case Render.LightningArc:
                    p.life = (0.5f + Random.value * 0.5f) * BaseLifetime;
                    p.vel = new Vector3(BaseVelocity, 0f, 0f);
                    p.rot = Random.value * 360f;
                    p.size = Vector2.one * (1f + Random.value) * 80f * scale;
                    p.colour = Rgb(5000f);
                    p.alpha0 = c.a * Random.value * 2f * opacity;
                    break;
                case Render.Shape:
                    p.life = BaseLifetime;
                    p.vel = new Vector3(BaseVelocity, 0f, 0f);
                    p.size = Vector2.one * 25f * scale;
                    p.colour = Rgb(0.5f);
                    p.alpha0 = c.a * opacity;
                    // Delta Surge: each triangle turned about X by the emitter's age (0.3 turns a second)
                    p.turn = trail.kind == "triangles" ? Mathf.PI * 2f * 0.3f * emitterAge : 0f;
                    break;
                case Render.Veil:
                {
                    p.life = BaseLifetime;
                    p.pos = SpawnOffset;
                    float t = Time.time;
                    float W(float phi) => (Mathf.Sin(phi) + Mathf.Sin(phi * 2.67235f) + Mathf.Sin(phi * 1.23498f)) / 3f;
                    p.vel = new Vector3(BaseVelocity, 200f * W(10f * e.phase1 + 10f * t), 200f * W(10f * e.phase2 + 10f * t));
                    p.size = new Vector2(50f * scale, 0f);
                    p.colour = Rgb(5f);
                    p.alpha0 = c.a * Mathf.Pow(Mathf.Max(0f, opacity), 4f);
                    p.dyn = e.index == 0 ? new Vector4(0.05f, 2f, 0.05f, 1.5f) : new Vector4(0.05f, 2f, 0.05f, 1f);
                    break;
                }
            }
            return p;
        }

        /// <summary>A particle's alpha now (its curves, HangarMode's squaring).</summary>
        public float Alpha(Emitter e, in Particle p, bool hangar)
        {
            float t = Mathf.Clamp01(p.age / Mathf.Max(p.life, 1e-5f));
            float a0 = p.alpha0, k;
            switch (e.render)
            {
                case Render.Glitter: return a0 * Curve(0, t);
                case Render.Smoke: k = Curve(1, t); break;
                case Render.Bubbles: k = Curve(2, t); break;
                case Render.Sparks: k = 1f - t; break;
                case Render.DarkTrail: k = Curve(0, t) * 10f; break;
                case Render.FireTrail: case Render.Lines: k = Curve(0, t); break;
                case Render.LightningRibbon: k = Curve(0, t); break;
                case Render.LightningArc: k = Curve(2, t); break;
                case Render.Shape: k = Curve(0, t); break;
                case Render.Veil: k = Curve(e.index, t); break;
                default: k = 1f; break;
            }
            return hangar ? a0 * a0 * k : a0 * k;
        }

        /// <summary>A particle's colour now (Bubbles brighten with their age).</summary>
        public Vector3 Colour(Emitter e, in Particle p, bool hangar)
        {
            var c = (Vector3)p.colour;
            if (e.render == Render.Bubbles && !hangar)
                c *= Mathf.Lerp(1f, 10f, Curve(0, Mathf.Clamp01(p.age / Mathf.Max(p.life, 1e-5f))));
            return c;
        }

        /// <summary>A sprite's drawn size (cm) now.</summary>
        public Vector2 Size(Emitter e, in Particle p)
        {
            float t = Mathf.Clamp01(p.age / Mathf.Max(p.life, 1e-5f));
            switch (e.render)
            {
                case Render.Smoke: return p.size * Mathf.Lerp(1f, 3f, Curve(0, t));
                case Render.Bubbles: return p.size * Mathf.Lerp(1f, 3f, Curve(1, t));
                case Render.Sparks:
                {
                    float speed = Mathf.Clamp(p.vel.magnitude, 1e-4f, 1000f) / 1000f, c = Curve(0, t);
                    return new Vector2(Mathf.Lerp(1f, 2f, speed) * c * p.size.x, Mathf.Lerp(1f, 20f, speed) * c * p.size.y);
                }
                case Render.LightningArc:
                {
                    float c = Curve(1, t);
                    return new Vector2(p.size.x * 0.5f * c, p.size.y * c);
                }
                case Render.Shape:
                {
                    float c = trail.kind == "rings" ? Curve(1, t) : 1f;
                    return new Vector2(p.size.x * 2f * c, p.size.y * c);
                }
                default: return p.size;
            }
        }

        /// <summary>Bubbles' turn around their random axis: 1 turn a second, radius 10 cm x the normalized age.</summary>
        public static Vector3 Orbit(in Particle p)
        {
            float t = Mathf.Clamp01(p.age / Mathf.Max(p.life, 1e-5f)), a = p.age * Mathf.PI * 2f;
            return (p.axisU * Mathf.Cos(a) + p.axisV * Mathf.Sin(a)) * 10f * t;
        }

        // ---- UE's engine noise textures --------------------------------------------------------------------------------

        static Texture2D gradTex;
        static Texture3D noise3D;

        /// <summary>UE's FRandomStream (MutateSeed, GetFraction).</summary>
        struct RandomStream
        {
            uint seed;
            public RandomStream(uint s) { seed = s; }
            public float Fraction()
            {
                seed = seed * 196314165u + 907633515u;
                float f = System.BitConverter.Int32BitsToSingle((int)(0x3F800000u | (seed & 0x007FFFFFu)));
                return f - 1f;
            }
        }

        // the 12 cube edge midpoints (FSystemTextures)
        static readonly Vector3Int[] Edges =
        {
            new Vector3Int(0, 1, 1), new Vector3Int(1, 0, 1), new Vector3Int(1, 1, 0), new Vector3Int(0, 1, -1), new Vector3Int(1, 0, -1), new Vector3Int(1, -1, 0),
            new Vector3Int(0, -1, 1), new Vector3Int(-1, 0, 1), new Vector3Int(-1, 1, 0), new Vector3Int(0, -1, -1), new Vector3Int(-1, 0, -1), new Vector3Int(-1, -1, 0),
        };

        /// <summary>View.PerlinNoiseGradientTexture: 128 x 128, each texel one of the edge midpoints (its table's bytes: 0x88
        /// for 0, 0xff for 1, 0 for -1), picked by FRandomStream(12345).</summary>
        public static Texture2D GradientTexture
        {
            get
            {
                if (gradTex != null) return gradTex;
                byte B(int v) => v > 0 ? (byte)0xff : v < 0 ? (byte)0 : (byte)0x88;
                var rs = new RandomStream(12345);
                var px = new Color32[128 * 128];
                for (int i = 0; i < px.Length; i++)
                {
                    var g = Edges[(int)(rs.Fraction() * 11.9999999f)];
                    px[i] = new Color32(B(g.x), B(g.y), B(g.z), 0);
                }
                gradTex = new Texture2D(128, 128, TextureFormat.RGBA32, false, true) { name = "ES2 PerlinNoiseGradient", filterMode = FilterMode.Point, wrapMode = TextureWrapMode.Repeat };
                gradTex.SetPixels32(px);
                gradTex.Apply(false, false);
                return gradTex;
            }
        }

        /// <summary>View.PerlinNoise3DTexture: 16^3, a gradient per texel (x 127 + 127: 0 -> 0x7f, 1 -> 0xfe, -1 -> 0), wrapping
        /// every 15 (texel 15 repeats texel 0's gradient), and in alpha 127 + dot(gradient, the texel) so that its hardware
        /// interpolation gives gradient noise.</summary>
        public static Texture3D Noise3D
        {
            get
            {
                if (noise3D != null) return noise3D;
                const int N = 16, P = 15;
                var rs = new RandomStream(0x1234);
                var grads = new Vector3Int[P * P * P];
                for (int i = 0; i < grads.Length; i++) grads[i] = Edges[(int)(rs.Fraction() * 11.9999999f)];
                var px = new Color32[N * N * N];
                for (int z = 0; z < N; z++)
                    for (int y = 0; y < N; y++)
                        for (int x = 0; x < N; x++)
                        {
                            var g = grads[(x % P) + (y % P) * P + (z % P) * P * P];
                            int a = 127 + g.x * x + g.y * y + g.z * z;
                            px[x + y * N + z * N * N] = new Color32((byte)(127 + 127 * g.x), (byte)(127 + 127 * g.y), (byte)(127 + 127 * g.z), (byte)Mathf.Clamp(a, 0, 255));
                        }
                noise3D = new Texture3D(N, N, N, UnityEngine.Experimental.Rendering.GraphicsFormat.R8G8B8A8_UNorm, UnityEngine.Experimental.Rendering.TextureCreationFlags.None)
                    { name = "ES2 PerlinNoise3D", filterMode = FilterMode.Bilinear, wrapMode = TextureWrapMode.Clamp };
                noise3D.SetPixels32(px);
                noise3D.Apply(false, false);
                return noise3D;
            }
        }
    }
}
