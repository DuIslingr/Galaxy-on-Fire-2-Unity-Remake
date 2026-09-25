// NpcCloak.cs
// An NPC's cloak (PlayerFighter::handleCloaking / cloak, Reference/research/npc_traffic_ai.md 5.5): the Specters (race 10)
// and Trunt Harval's Scimitar. Cloaked for a time with 2000 ms fades in and out; while more than a quarter faded in the
// ship is off the radar and can't be locked (KIPlayer+0x70) and its exhaust and lights hide. The look is the player's
// (GoF2/Cloak, PlayerCloak): the hull dissolves into the refracted screen.
//   handleCloaking   when panicking a 50 % chance, otherwise every 8000 ms a 30 % chance, for 9000 + rnd(5000) ms
//   level scripts    cloak(ms) (the ambush fly-ins), setCloakingPossible(false) (asleep / cutscene Specters)
// Plain class run by NpcShip.

using System.Collections.Generic;
using GoF2Remake.Flight;
using UnityEngine;

namespace GoF2Remake.World
{
    public class NpcCloak
    {
        const float FadeMs = 2000f, RollEveryMs = 8000f;
        static readonly int AnimValueId = Shader.PropertyToID("_AnimValue"), CloakRateId = Shader.PropertyToID("_CloakRate");

        /// <summary>setCloakingPossible: the ship may cloak on its own (handleCloaking).</summary>
        public bool Possible = true;
        public bool Cloaked => totalMs > 0f;
        /// <summary>Off the radar / lock: cloaked more than a quarter.</summary>
        public bool Hidden => Cloaked && Percentage >= 25f;
        /// <summary>0..100 of the fade (in over 2000 ms, out over the last 2000 ms).</summary>
        public float Percentage
        {
            get
            {
                if (!Cloaked) return 0f;
                float left = totalMs - elapsedMs;
                return Mathf.Clamp01(Mathf.Min(elapsedMs, left) / FadeMs) * 100f;
            }
        }

        readonly List<(Renderer r, Material[] original, Material[] cloak)> hull = new List<(Renderer, Material[], Material[])>();
        readonly List<Renderer> glow = new List<Renderer>();
        readonly object owner = new object();
        float totalMs, elapsedMs, rollMs;
        bool swapped, glowHidden;

        public NpcCloak(Transform model)
        {
            if (model == null) return;
            var assets = CombatAssets.Load();
            var shader = assets != null ? assets.cloakShader : null;
            foreach (var r in model.GetComponentsInChildren<Renderer>(true))
            {
                if (r is ParticleSystemRenderer) continue;
                var mats = r.sharedMaterials;
                bool lit = mats.Length > 0 && mats[0] != null && mats[0].shader != null && mats[0].shader.name.Contains("Lit");
                if (!lit) { glow.Add(r); continue; }
                if (shader == null) continue;
                var cloak = new Material[mats.Length];
                for (int i = 0; i < mats.Length; i++)
                {
                    var m = new Material(shader);
                    if (mats[i] != null)
                    {
                        if (mats[i].HasProperty("_BaseMap")) m.SetTexture("_BaseMap", mats[i].GetTexture("_BaseMap"));
                        if (mats[i].HasProperty("_BumpMap")) m.SetTexture("_BumpMap", mats[i].GetTexture("_BumpMap"));
                    }
                    if (assets.cloakMap != null) m.SetTexture("_CloakMap", assets.cloakMap);
                    cloak[i] = m;
                }
                hull.Add((r, mats, cloak));
            }
        }

        /// <summary>PlayerFighter::cloak(ms): cloaked for 'ms' (including the fades); 0 ends it.</summary>
        public void Cloak(float ms)
        {
            if (ms <= 0f) { Stop(); return; }
            totalMs = Mathf.Max(ms, 2f * FadeMs);
            elapsedMs = 0f;
        }

        public void Stop()
        {
            totalMs = elapsedMs = 0f;
            Swap(false);
        }

        /// <summary>Per frame; 'mayRoll' = its AI runs (not asleep, frozen or in a cutscene), 'panicking' = PlayerFighter+0x... .</summary>
        public void Update(float dtMs, bool mayRoll, bool panicking)
        {
            if (!Cloaked)
            {
                if (!Possible || !mayRoll) return;
                rollMs += dtMs;
                bool roll = panicking ? Random.Range(0, 100) < 50 : rollMs >= RollEveryMs && Random.Range(0, 100) < 30;
                if (rollMs >= RollEveryMs) rollMs = 0f;
                if (roll) Cloak(9000f + Random.Range(0, 5000));
                return;
            }
            elapsedMs += dtMs;
            if (elapsedMs >= totalMs) { Stop(); return; }
            Swap(true);
            float pct = Percentage;
            foreach (var h in hull)
                foreach (var m in h.cloak) { m.SetFloat(AnimValueId, pct / 100f); m.SetFloat(CloakRateId, elapsedMs * 0.001f); }
            bool hide = pct >= 25f;
            if (hide != glowHidden)
            {
                glowHidden = hide;
                foreach (var r in glow) if (r != null) r.forceRenderingOff = hide;
            }
        }

        void Swap(bool on)
        {
            if (swapped == on) return;
            swapped = on;
            foreach (var h in hull) if (h.r != null) h.r.sharedMaterials = on ? h.cloak : h.original;
            if (!on) { glowHidden = false; foreach (var r in glow) if (r != null) r.forceRenderingOff = false; }
            OpaqueTexture.Request(owner, on);
        }

        public void Dispose()
        {
            Swap(false);
            foreach (var h in hull) foreach (var m in h.cloak) if (m != null) Object.Destroy(m);
        }
    }
}
