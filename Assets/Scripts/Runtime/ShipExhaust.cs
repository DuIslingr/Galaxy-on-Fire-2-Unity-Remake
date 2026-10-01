// ShipExhaust.cs
// The player ship's exhaust particles (Level::initParticleSystems 0xcc990; the NPCs have none, only their _engine_add
// meshes; the Trail class for NPC trails is never constructed in this build). One sprite system per weapons_hd slot-3
// anchor i (its scale s = the anchor's "turretAngles"), record 29 + i, material 20090 (additive particles.png):
//   one particle every 8 units travelled, pool 20, size 250 s.x shrinking 1000/s, life 80 min(1.5 s.x, 1) ms,
//   velocity -4000 min(1.5 s.x, 1) u/s along the ship axis + 0.8 x the ship's + -100..100 random, colour 0xDDDDDD -> 0,
//   the ship's cell of particles.png (table 0x252ba0: 3 / 2 / 0 / 1 / 8 / 9 = the first six cells of the 8 x 8 grid)
//   PlayerEgo::update ~0xa9..: while boosting the size x (1 + 0.5 ramp), the ramp up over the boost's first sixth, down
//                               over its last
//   PlayerEgo::setExhaustVisible 0xa637c   off with the engine glow (mining, object docking, cutscenes, death)
//   Level::setPlayerEngineColor            the start colour grey clamp(221 - 2.01 x cloak %)

using System;
using System.Collections.Generic;
using GoF2Remake.Data;
using UnityEngine;

namespace GoF2Remake.Flight
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public class ShipExhaust : MonoBehaviour
    {
        const float M = 0.05f;
        static readonly int[] ShipCell =
        {
            3, 0, 8, 3, 2, 0, 3, 0, 9, 1, 0, 8, 2, 0, 0, 0, 2, 0, 2, 3, 3, 2, 0, 8, 8, 8, 0, 0, 0, 8, 3, 2,
            8, 0, 0, 2, 0, 0, 0, 1, 0, 1, 1, 2, 1, 3, 3, 3, 3, 1, 1, 0, 8, 1, 1, 0, 3, 2, 0, 0, 8, 1, 3, 1,
        };

        ShipController ship;
        PlayerHealth health;
        PlayerCloak cloak;
        GameObject glow;
        readonly List<ParticleSystem> systems = new List<ParticleSystem>();
        readonly List<float> baseSizes = new List<float>();
        bool on;

        public static ShipExhaust Attach(GameObject player, Database db, ShipController ship, int shipIndex)
        {
            var e = player.AddComponent<ShipExhaust>();
            e.ship = ship;
            e.Setup(db, ship.visualModel != null ? ship.visualModel : player.transform, shipIndex);
            return e;
        }

        // Multiplayer: another player's ship (NetPlayer), its state from their game.
        Func<bool> remoteOn;
        Func<float> remoteBoost, remoteCloak;

        /// <summary>Multiplayer (NetPlayer): the exhaust of another player's ship 'model', driven by their game's engine state
        /// (on: the engine glow shows), boost (0..1) and cloak (0..100).</summary>
        public static ShipExhaust AttachRemote(GameObject host, Database db, Transform model, int shipIndex, Func<bool> on, Func<float> boost, Func<float> cloak)
        {
            var e = host.AddComponent<ShipExhaust>();
            e.remoteOn = on;
            e.remoteBoost = boost;
            e.remoteCloak = cloak;
            e.Setup(db, model, shipIndex);
            return e;
        }

        void Setup(Database db, Transform parent, int shipIndex)
        {
            var mat = CombatAssets.Load()?.particlesMaterial;
            int value = shipIndex >= 0 && shipIndex < ShipCell.Length ? ShipCell[shipIndex] : 0;
            int cell = value switch { 3 => 0, 2 => 1, 1 => 3, 8 => 4, 9 => 5, _ => 2 };
            var asm = parent.GetComponent<Visuals.AssembledObject>();
            if (asm != null && asm.playerVariantParts != null && asm.playerVariantParts.Length > 0) glow = asm.playerVariantParts[0];
            foreach (var m in db.MountsOf(shipIndex, 3))
            {
                float s = m.turretAngles != null && m.turretAngles.Length > 0 ? m.turretAngles[0] : 1f;
                float k = Mathf.Min(1.5f * s, 1f);
                var go = new GameObject("Exhaust");
                go.transform.SetParent(parent, false);
                go.transform.localPosition = WeaponSystem.MountToLocal(m);
                var ps = go.AddComponent<ParticleSystem>();
                ps.Stop(true, ParticleSystemStopBehavior.StopEmittingAndClear);
                float life = 0.08f * k, size = 250f * s;
                var main = ps.main;
                main.loop = true;
                main.playOnAwake = false;
                main.startLifetime = life;
                main.startSpeed = 0f;
                main.startSize = size * M;
                main.startColor = (Color)new Color32(0xDD, 0xDD, 0xDD, 0xFF);
                main.simulationSpace = ParticleSystemSimulationSpace.World;
                main.emitterVelocityMode = ParticleSystemEmitterVelocityMode.Transform;
                main.maxParticles = 20;
                var em = ps.emission;
                em.rateOverTime = 0f;
                em.rateOverDistance = 1f / (8f * M);   // one per 8 units
                var sh = ps.shape;
                sh.enabled = false;
                // Backwards along the ship at 4000 k u/s, +-100 u/s jitter, plus 0.8 x the ship's velocity.
                var vel = ps.velocityOverLifetime;
                vel.enabled = true;
                vel.space = ParticleSystemSimulationSpace.Local;
                vel.x = new ParticleSystem.MinMaxCurve(-100f * M, 100f * M);
                vel.y = new ParticleSystem.MinMaxCurve(-100f * M, 100f * M);
                vel.z = new ParticleSystem.MinMaxCurve(-4000f * k * M - 100f * M, -4000f * k * M + 100f * M);
                var iv = ps.inheritVelocity;
                iv.enabled = true;
                iv.mode = ParticleSystemInheritVelocityMode.Initial;
                iv.curve = new ParticleSystem.MinMaxCurve(0.8f);
                // size - 1000/s over the life
                var sol = ps.sizeOverLifetime;
                sol.enabled = true;
                sol.size = new ParticleSystem.MinMaxCurve(1f, AnimationCurve.Linear(0f, 1f, 1f, Mathf.Max(0f, (size - 1000f * life) / size)));
                // 0xDDDDDD -> black (additive: the RGB fade)
                var col = ps.colorOverLifetime;
                col.enabled = true;
                var g = new Gradient();
                g.SetKeys(new[] { new GradientColorKey(Color.white, 0f), new GradientColorKey(Color.black, 1f) },
                          new[] { new GradientAlphaKey(1f, 0f), new GradientAlphaKey(0f, 1f) });
                col.color = g;
                // The cell as a camera-facing quad whose UVs stay half a texel inside it: a texture-sheet cell reached the
                // cell's edge, and the bilinear filter pulled in the trail strips that start right under the glows (a
                // purple / red line under every particle: lines behind the thrusters).
                var r = go.GetComponent<ParticleSystemRenderer>();
                r.renderMode = ParticleSystemRenderMode.Mesh;
                r.mesh = CellQuad(cell);
                r.alignment = ParticleSystemRenderSpace.View;
                r.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
                r.receiveShadows = false;
                if (mat != null) r.sharedMaterial = mat;
                systems.Add(ps);
                baseSizes.Add(size * M);
            }
        }

        static readonly Mesh[] cellQuads = new Mesh[64];

        /// <summary>A unit quad (a billboard's size) mapping cell 'cell' of the 8 x 8, 1024 px particles.png, inset half a texel.</summary>
        static Mesh CellQuad(int cell)
        {
            if (cellQuads[cell] != null) return cellQuads[cell];
            const float px = 1f / 1024f, step = 1f / 8f;
            int cx = cell % 8, cy = cell / 8;   // rows from the top
            float u0 = cx * step + 0.5f * px, u1 = (cx + 1) * step - 0.5f * px;
            float v1 = 1f - cy * step - 0.5f * px, v0 = 1f - (cy + 1) * step + 0.5f * px;
            var m = new Mesh { name = $"ExhaustCell{cell}" };
            m.vertices = new[] { new Vector3(-0.5f, -0.5f, 0f), new Vector3(0.5f, -0.5f, 0f), new Vector3(0.5f, 0.5f, 0f), new Vector3(-0.5f, 0.5f, 0f) };
            m.uv = new[] { new Vector2(u0, v0), new Vector2(u1, v0), new Vector2(u1, v1), new Vector2(u0, v1) };
            m.triangles = new[] { 0, 2, 1, 0, 3, 2 };
            m.RecalculateBounds();
            return cellQuads[cell] = m;
        }

        void Update()
        {
            if (ship == null && remoteOn == null) return;
            bool want;
            if (remoteOn != null) want = remoteOn();
            else
            {
                if (health == null) health = GetComponent<PlayerHealth>();
                if (cloak == null) cloak = GetComponent<PlayerCloak>();
                want = (glow == null || glow.activeInHierarchy) && (health == null || !health.Dead)
                       && (ship.visualModel == null || ship.visualModel.gameObject.activeInHierarchy);
            }
            if (want != on)
            {
                on = want;
                foreach (var ps in systems) if (on) ps.Play(true); else ps.Stop(true, ParticleSystemStopBehavior.StopEmitting);
            }
            if (!on) return;
            float boost = remoteBoost != null ? remoteBoost() : ship.Model != null ? ship.Model.BoostVisualPercent : 0f;
            float cloakPct = remoteCloak != null ? remoteCloak() : cloak != null && cloak.Rules != null ? cloak.Rules.Percentage : 0f;
            float grey = Mathf.Clamp(221f - 2.01f * cloakPct, 0f, 255f) / 255f;
            for (int i = 0; i < systems.Count; i++)
            {
                var main = systems[i].main;
                main.startSize = baseSizes[i] * (1f + 0.5f * boost);
                main.startColor = new Color(grey, grey, grey, 1f);
            }
        }
    }
}

