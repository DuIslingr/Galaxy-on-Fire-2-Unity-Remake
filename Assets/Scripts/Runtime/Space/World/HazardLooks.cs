// HazardLooks.cs
// Remake (2026-11-06, for mods): how an orbit's hazard volumes look (World.HazardZones; stations.json "orbit.hazards"), after
// EVERSPACE 2's fields, which are particles in the volume and a post-process inside it, never a surface:
//   corrosion  P_CorrosionField: clouds (M_CorrosionField_Cloud, 5 a second for 2-4 s, 1-2 x the radius across, their
//              alpha up and down over the life) and a fizz of bubbles (M_Condition_Corrosion_Bubble), all (0.84, 1, 0.09)
//   radiation  NS_RadiationField: clouds (M_RadiationField_Cloud) and sparks (M_Particle_Spark_002) in RadiationColor
//              (1, 1, 0.39); inside, M_Condition_Radiated_PostProcess's dots (GoF2/HazardVolume mode 2)
//   frost      NS_FrostField: drifting ice shards (mesh particles, M_WebField_Plasma) in (0.19, 0.77, 1); inside,
//              M_Condition_Frozen_PostProcess's frost from the edges as the buildup grows (GoF2/HazardVolume mode 1)
//   heat       BP_HeatDamageVolume: no particles (ES2's heat volumes lie on hot ground); inside, its post-process raises
//              the bloom to 2 (here a global volume doubling the scene's bloom, weighted by the depth inside); a faint
//              orange haze added so the volume shows in open space (remake)
//   damage     BP_DamageField: the burning mining prop's fire (BP_Mining_Fire_001): GoF2's fire sprites and embers
// The particles are GoF2's own sprites (the pirate base's fog for the clouds, the particle atlas for the motes, the burning
// ships' fire), simulated in the volume's space with its sphere as the emitter.

using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.Rendering.Universal;

namespace GoF2Remake.World
{
    public static class HazardLooks
    {
        const int GlowCell = 3, SparkCell = 61;   // particles.png cells (MiningBeamFx's ore glow and sparks)

        /// <summary>ES2's colour of a kind's particles (heat: the remake's haze).</summary>
        public static Color KindColor(Modding.ModWorld.HazardKind kind) => kind switch
        {
            Modding.ModWorld.HazardKind.Heat => new Color(1f, 0.42f, 0.12f),
            Modding.ModWorld.HazardKind.Radiation => new Color(1f, 1f, 0.39f),
            Modding.ModWorld.HazardKind.Frost => new Color(0.19f, 0.77f, 1f),
            Modding.ModWorld.HazardKind.Corrosion => new Color(0.84f, 1f, 0.09f),
            _ => new Color(1f, 0.45f, 0.12f),
        };

        /// <summary>The volumes' particles under 'parent'; the inside overlays (null for the kinds without one), one per zone.</summary>
        public static Material[] Build(Transform parent, Modding.ModWorld.HazardSpec[] zones)
        {
            var overlays = new Material[zones.Length];
            var assets = CombatAssets.Load();
            var overlayShader = Resources.Load<Shader>("GoF2Combat/HazardVolume");
            for (int i = 0; i < zones.Length; i++)
            {
                var z = zones[i];
                var at = OrbitLayout.ToUnity(z.centre);
                float r = z.radius * OrbitLayout.MetersPerUnit;
                var root = new GameObject("Hazard " + z.kind);
                root.transform.SetParent(parent, false);
                root.transform.position = at;
                var c = KindColor(z.kind);
                switch (z.kind)
                {
                    case Modding.ModWorld.HazardKind.Corrosion:
                        Clouds(root.transform, assets, r, c, 0.45f, 5f, 2f, 4f, 1f, 2f);
                        Motes(root.transform, assets, r, c, GlowCell, 60f, 0.4f, 1f, 0.02f, 0.06f, 0f);
                        break;
                    case Modding.ModWorld.HazardKind.Radiation:
                        Clouds(root.transform, assets, r, c, 0.35f, 3f, 3f, 5f, 1f, 2f);
                        Motes(root.transform, assets, r, c, SparkCell, 30f, 0.5f, 1f, 0.01f, 0.03f, 0f);
                        overlays[i] = Overlay(root.transform, overlayShader, r, new Color(1f, 1f, 0.659f), 2f);   // (RadiationColor FFFFA8)
                        break;
                    case Modding.ModWorld.HazardKind.Frost:
                        Clouds(root.transform, assets, r, c, 0.18f, 2f, 3f, 5f, 0.8f, 1.5f);
                        Motes(root.transform, assets, r, c, GlowCell, 40f, 2f, 4f, 0.015f, 0.04f, 30f);
                        overlays[i] = Overlay(root.transform, overlayShader, r, new Color(0.82f, 0.93f, 1f), 1f);
                        break;
                    case Modding.ModWorld.HazardKind.Heat:
                        Clouds(root.transform, assets, r, c, 0.12f, 2f, 3f, 5f, 0.8f, 1.6f);
                        break;
                    default:
                        Fire(root.transform, assets, r);
                        Motes(root.transform, assets, r, c, GlowCell, 25f, 0.6f, 1.2f, 0.01f, 0.03f, 0f);
                        break;
                }
            }
            return overlays;
        }

        static ParticleSystem MakeSystem(Transform parent, string name, float radius, int max, float rate, float lifeMin, float lifeMax)
        {
            var go = new GameObject(name);
            go.transform.SetParent(parent, false);
            var ps = go.AddComponent<ParticleSystem>();
            ps.Stop(true, ParticleSystemStopBehavior.StopEmittingAndClear);
            var main = ps.main;
            main.duration = 5f;
            main.loop = true;
            main.prewarm = true;   // (full on arrival)
            main.playOnAwake = false;
            main.startLifetime = new ParticleSystem.MinMaxCurve(lifeMin, lifeMax);
            main.startSpeed = 0f;
            main.startRotation = new ParticleSystem.MinMaxCurve(0f, Mathf.PI * 2f);
            main.simulationSpace = ParticleSystemSimulationSpace.Local;
            main.maxParticles = max;
            main.cullingMode = ParticleSystemCullingMode.Automatic;
            var em = ps.emission;
            em.rateOverTime = rate;
            var sh = ps.shape;
            sh.enabled = true;
            sh.shapeType = ParticleSystemShapeType.Sphere;
            sh.radius = radius;
            sh.radiusThickness = 1f;   // (all through the volume, not its surface)
            return ps;
        }

        /// <summary>A triangle over the life, black -> 'c' x 'strength' -> black (the sprites are additive: their brightness is
        /// their visibility; ES2's clouds' AlphaScaleOverLife 0 -> 1 -> 0).</summary>
        static void FadeInOut(ParticleSystem ps, Color c, float strength)
        {
            var col = ps.colorOverLifetime;
            col.enabled = true;
            var g = new Gradient();
            g.SetKeys(new[] { new GradientColorKey(Color.black, 0f), new GradientColorKey(c * strength, 0.5f), new GradientColorKey(Color.black, 1f) },
                      new[] { new GradientAlphaKey(1f, 0f), new GradientAlphaKey(1f, 1f) });
            col.color = g;
        }

        static void Finish(ParticleSystem ps, Material mat, Mesh mesh, float maxScreen)
        {
            var r = ps.GetComponent<ParticleSystemRenderer>();
            if (mesh != null) { r.renderMode = ParticleSystemRenderMode.Mesh; r.mesh = mesh; r.alignment = ParticleSystemRenderSpace.View; }
            else r.renderMode = ParticleSystemRenderMode.Billboard;
            r.maxParticleSize = maxScreen;
            r.shadowCastingMode = ShadowCastingMode.Off;
            r.receiveShadows = false;
            if (mat != null) r.sharedMaterial = mat;
            ps.Play();
        }

        static Material Tinted(Material source, string name)
        {
            if (source == null) return null;
            var m = new Material(source) { name = name };
            if (m.HasProperty("_UseVertexColor")) m.SetFloat("_UseVertexColor", 1f);
            if (m.HasProperty("_Glow")) m.SetFloat("_Glow", 1f);
            return m;
        }

        /// <summary>Soft clouds through the volume: 'rate' a second for lifeMin-lifeMax s, sizeMin-sizeMax x the radius.</summary>
        static void Clouds(Transform parent, CombatAssets assets, float radius, Color c, float strength, float rate, float lifeMin, float lifeMax, float sizeMin, float sizeMax)
        {
            var ps = MakeSystem(parent, "Clouds", radius, Mathf.CeilToInt(rate * lifeMax) + 2, rate, lifeMin, lifeMax);
            var main = ps.main;
            main.startSize = new ParticleSystem.MinMaxCurve(radius * sizeMin, radius * sizeMax);
            var rot = ps.rotationOverLifetime;
            rot.enabled = true;
            rot.z = new ParticleSystem.MinMaxCurve(-0.15f, 0.15f);
            FadeInOut(ps, c, strength);
            Finish(ps, Tinted(assets != null ? assets.fogMaterial : null, "Hazard clouds"), null, 4f);
        }

        /// <summary>Small motes (bubbles, sparks, shards) of particles.png cell 'cell', sizeMin-sizeMax x the radius; 'spin'
        /// degrees a second at most.</summary>
        static void Motes(Transform parent, CombatAssets assets, float radius, Color c, int cell, float rate, float lifeMin, float lifeMax, float sizeMin, float sizeMax, float spin)
        {
            var ps = MakeSystem(parent, "Motes", radius, Mathf.CeilToInt(rate * lifeMax) + 4, rate, lifeMin, lifeMax);
            var main = ps.main;
            main.startSize = new ParticleSystem.MinMaxCurve(radius * sizeMin, radius * sizeMax);
            if (spin > 0f)
            {
                var rot = ps.rotationOverLifetime;
                rot.enabled = true;
                rot.z = new ParticleSystem.MinMaxCurve(-spin * Mathf.Deg2Rad, spin * Mathf.Deg2Rad);
            }
            FadeInOut(ps, c, 1f);
            Finish(ps, Tinted(assets != null ? assets.particlesMaterial : null, "Hazard motes"), ShipExhaust.CellQuad(cell), 0.5f);
        }

        /// <summary>The burning prop's fire: GoF2's burning ships' fire sprites (4 x 4 sheet, once over the life), rising slowly.</summary>
        static void Fire(Transform parent, CombatAssets assets, float radius)
        {
            var ps = MakeSystem(parent, "Fire", radius * 0.6f, 20, 12f, 0.6f, 1.2f);
            var main = ps.main;
            main.startSize = new ParticleSystem.MinMaxCurve(radius * 0.25f, radius * 0.5f);
            main.startSpeed = new ParticleSystem.MinMaxCurve(radius * 0.05f, radius * 0.15f);
            var tsa = ps.textureSheetAnimation;
            tsa.enabled = true;
            tsa.mode = ParticleSystemAnimationMode.Grid;
            tsa.numTilesX = 4;
            tsa.numTilesY = 4;
            tsa.animation = ParticleSystemAnimationType.WholeSheet;
            tsa.cycleCount = 1;
            Finish(ps, assets != null ? assets.fireMaterial : null, null, 2f);
        }

        /// <summary>The inside view's overlay (GoF2/HazardVolume in 'mode') on the volume's sphere, its amount 0.</summary>
        static Material Overlay(Transform parent, Shader shader, float radius, Color c, float mode)
        {
            if (shader == null) return null;
            var go = GameObject.CreatePrimitive(PrimitiveType.Sphere);
            go.name = "Inside view";
            Object.Destroy(go.GetComponent<Collider>());
            go.transform.SetParent(parent, false);
            go.transform.localScale = Vector3.one * radius * 2f;
            var r = go.GetComponent<MeshRenderer>();
            r.shadowCastingMode = ShadowCastingMode.Off;
            r.receiveShadows = false;
            var m = new Material(shader) { name = "Hazard inside view" };
            m.SetColor("_Color", c);
            m.SetFloat("_Mode", mode);
            m.SetFloat("_Amount", 0f);
            r.sharedMaterial = m;
            return m;
        }

        /// <summary>The heat volumes' bloom (BP_HeatDamageVolume's PostProcess, BloomIntensity 2): a global volume over the
        /// scene's, its bloom twice the scene's own, weighted by how deep the camera is in a heat volume (SetHeat); null
        /// without heat volumes or with the bloom off.</summary>
        public static Volume HeatBloom(Transform parent, Modding.ModWorld.HazardSpec[] zones)
        {
            bool any = false;
            foreach (var z in zones) any |= z.kind == Modding.ModWorld.HazardKind.Heat;
            if (!any || !Settings.Bloom) return null;
            float scene = 1f;
            foreach (var v in Object.FindObjectsByType<Volume>(FindObjectsInactive.Exclude))
                if (v.isGlobal && v.sharedProfile != null && v.sharedProfile.TryGet(out Bloom b) && b.intensity.overrideState) { scene = b.intensity.value; break; }
            var go = new GameObject("Heat bloom");
            go.transform.SetParent(parent, false);
            var vol = go.AddComponent<Volume>();
            vol.isGlobal = true;
            vol.priority = 60f;   // (over the game's and the hangar's depth of field, under the photo tools' 1000)
            vol.weight = 0f;
            var profile = ScriptableObject.CreateInstance<VolumeProfile>();
            profile.Add<Bloom>(false).intensity.Override(scene * 2f);
            vol.sharedProfile = profile;
            return vol;
        }

        /// <summary>How deep 'camera' (Unity) is in the heat volumes: 1 within 85 % of a radius, fading to 0 at its edge.</summary>
        public static float HeatDepth(Modding.ModWorld.HazardSpec[] zones, Vector3 camera)
        {
            float w = 0f;
            foreach (var z in zones)
            {
                if (z.kind != Modding.ModWorld.HazardKind.Heat) continue;
                float r = z.radius * OrbitLayout.MetersPerUnit;
                float d = (camera - OrbitLayout.ToUnity(z.centre)).magnitude;
                w = Mathf.Max(w, Mathf.Clamp01((r - d) / (r * 0.15f)));
            }
            return w;
        }
    }
}
