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

using System.Collections.Generic;
using GoF2Remake.Data;
using UnityEngine;

namespace GoF2Remake.Flight
{
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
            e.Setup(db, ship, shipIndex);
            return e;
        }

        void Setup(Database db, ShipController controller, int shipIndex)
        {
            ship = controller;
            var mat = CombatAssets.Load()?.particlesMaterial;
            int value = shipIndex >= 0 && shipIndex < ShipCell.Length ? ShipCell[shipIndex] : 0;
            int cell = value switch { 3 => 0, 2 => 1, 1 => 3, 8 => 4, 9 => 5, _ => 2 };
            var parent = ship.visualModel != null ? ship.visualModel : transform;
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
                var tsa = ps.textureSheetAnimation;
                tsa.enabled = true;
                tsa.mode = ParticleSystemAnimationMode.Grid;
                tsa.numTilesX = 8;
                tsa.numTilesY = 8;
                tsa.animation = ParticleSystemAnimationType.WholeSheet;
                tsa.frameOverTime = new ParticleSystem.MinMaxCurve(cell / 64f);
                var r = go.GetComponent<ParticleSystemRenderer>();
                r.renderMode = ParticleSystemRenderMode.Billboard;
                r.maxParticleSize = 10f;
                r.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
                r.receiveShadows = false;
                if (mat != null) r.sharedMaterial = mat;
                systems.Add(ps);
                baseSizes.Add(size * M);
            }
        }

        void Update()
        {
            if (ship == null) return;
            if (health == null) health = GetComponent<PlayerHealth>();
            if (cloak == null) cloak = GetComponent<PlayerCloak>();
            bool want = (glow == null || glow.activeInHierarchy) && (health == null || !health.Dead)
                        && (ship.visualModel == null || ship.visualModel.gameObject.activeInHierarchy);
            if (want != on)
            {
                on = want;
                foreach (var ps in systems) if (on) ps.Play(true); else ps.Stop(true, ParticleSystemStopBehavior.StopEmitting);
            }
            if (!on) return;
            float boost = ship.Model != null ? ship.Model.BoostVisualPercent : 0f;
            float grey = Mathf.Clamp(221f - 2.01f * (cloak != null && cloak.Rules != null ? cloak.Rules.Percentage : 0f), 0f, 255f) / 255f;
            for (int i = 0; i < systems.Count; i++)
            {
                var main = systems[i].main;
                main.startSize = baseSizes[i] * (1f + 0.5f * boost);
                main.startColor = new Color(grey, grey, grey, 1f);
            }
        }
    }
}

