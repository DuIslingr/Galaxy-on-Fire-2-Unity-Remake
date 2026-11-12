// WreckBreakup.cs
// Remake mods (2026-11-11, after Chorus's wrecks: SK_*_Wreck skeletal meshes, one bone a piece, flung apart by its
// ABP_Explosion_* anim blueprints' ExplosionPhysics node): a ship with ships.json "wreck" (CustomShipData.wreck) breaks
// into its wreck model's pieces where it explodes (NpcShipDamage.UpdateDying). The model (Modding.ModCrates, the ship's
// own materials) is placed exactly where the hull was; each mesh is a piece that flies out from the wreck's middle at
// "speed" x a tenth of the ship's length a second (each 0.6-1.4 x that) on top of the ship's own motion, slowing by a
// third a second, turning about its own middle at "spin" x 20-90 deg a second; the largest two burn (ShipBurn) for the
// first half; the pieces shrink away over the last quarter of "seconds" and are gone. A visual only: no hull, no
// collision, nothing a multiplayer copy sees (each game breaks its own copy).

using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using UnityEngine;

namespace GoF2Remake.World
{
    public class WreckBreakup : MonoBehaviour
    {
        class Piece
        {
            public Transform t;
            public Renderer r;
            public Vector3 velocity, axis, scale;
            public float spin;
            public ShipBurn burn;
        }

        readonly List<Piece> pieces = new List<Piece>();
        float ageS, lifeS;

        /// <summary>Ship 'ship''s wreck where 'hull' (its model's hull node) is, moving at 'velocity' (Unity / s); null when the
        /// ship has none or it isn't loaded (the plain explosion alone).</summary>
        public static WreckBreakup Spawn(int ship, Transform hull, Vector3 velocity)
        {
            var spec = CustomShips.Get(ship)?.wreck;
            if (spec == null || string.IsNullOrEmpty(spec.model) || hull == null) return null;
            var go = Modding.ModCrates.InstantiateWreck(ship, hull);
            if (go == null) return null;
            go.name = "Wreck";
            return Break(go, spec, velocity);
        }

        /// <summary>Breaks 'go' (a wreck model placed where the ship was) into its meshes' pieces.</summary>
        public static WreckBreakup Break(GameObject go, CustomWreck spec, Vector3 velocity)
        {
            var w = go.AddComponent<WreckBreakup>();
            w.Setup(spec, velocity);
            return w;
        }

        /// <summary>How many pieces fly; how long the wreck lasts (s).</summary>
        public int Pieces => pieces.Count;
        public float LifeS => lifeS;

        void Setup(CustomWreck spec, Vector3 velocity)
        {
            lifeS = Mathf.Max(0.5f, spec.seconds);
            var renderers = GetComponentsInChildren<Renderer>(true);
            if (renderers.Length == 0) return;
            var all = renderers[0].bounds;
            foreach (var r in renderers) all.Encapsulate(r.bounds);
            float length = Mathf.Max(all.size.x, Mathf.Max(all.size.y, all.size.z));
            float speed = Mathf.Max(0f, spec.speed) * length * 0.1f;
            foreach (var r in renderers)
            {
                var piece = new Piece { t = r.transform, r = r };
                var out_ = r.bounds.center - all.center;
                var dir = out_.sqrMagnitude > 1e-6f ? out_.normalized : Random.onUnitSphere;
                piece.velocity = velocity + (dir + Random.insideUnitSphere * 0.35f).normalized * speed * Random.Range(0.6f, 1.4f);
                piece.axis = Random.onUnitSphere;
                piece.spin = Random.Range(20f, 90f) * Mathf.Max(0f, spec.spin);
                pieces.Add(piece);
            }
            // (each piece on its own: the wreck's root no longer carries them)
            foreach (var p in pieces) { p.t.SetParent(transform, true); p.scale = p.t.localScale; }
            pieces.Sort((a, b) => b.r.bounds.size.sqrMagnitude.CompareTo(a.r.bounds.size.sqrMagnitude));
            for (int i = 0; i < Mathf.Min(2, pieces.Count); i++)
            {
                pieces[i].burn = new ShipBurn(pieces[i].t);
                pieces[i].burn.SetBurning(true);
            }
        }

        void Update() => Step(Time.deltaTime);

        /// <summary>'dt' seconds on: the pieces fly, turn, slow and shrink; the wreck gone at its end.</summary>
        public void Step(float dt)
        {
            ageS += dt;
            float slow = Mathf.Pow(2f / 3f, dt);
            float shrink = Mathf.Clamp01((lifeS - ageS) / (lifeS * 0.25f));
            foreach (var p in pieces)
            {
                if (p.t == null) continue;
                var c = p.r.bounds.center;
                p.t.position += p.velocity * dt;
                p.velocity *= slow;
                p.t.RotateAround(c + p.velocity * dt, p.axis, p.spin * dt);
                if (shrink < 1f)
                {
                    // shrunk about its own middle (the piece's origin may be the model's)
                    var before = p.r.bounds.center;
                    p.t.localScale = p.scale * Mathf.Max(0.001f, shrink);
                    p.t.position += before - p.r.bounds.center;
                }
                if (p.burn != null && ageS > lifeS * 0.5f) { p.burn.SetBurning(false); }
            }
            if (ageS >= lifeS) { if (Application.isPlaying) Destroy(gameObject); else DestroyImmediate(gameObject); }
        }
    }
}
