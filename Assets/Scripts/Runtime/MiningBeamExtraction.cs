// MiningBeamExtraction.cs
// Remake: the ore a mining beam cuts from one asteroid (Mining's beam mode: a drill item, sort 19, with attribute 100 = 1,
// e.g. a mod's), as plain C#. It is the minigame's ore logic (MiningGame) without the minigame: the asteroid's layers
// (class A 7, B 6, C 5, D 4) are cut one after the other while the beam is on it, at the minigame's rate
// MiningGame.OreRate(layer, attr 33 / 100). Attribute 102 sets the time per layer (default the minigame's 6000 ms); the
// rate is scaled with it, so a faster beam gets the same ore sooner: a whole asteroid gives the minigame's perfect run x the
// yield (class A 62.7 t x yield + its core, D 23.7 t x yield). There is no off-target energy and nothing is lost when the
// beam lets go: the progress stays with the asteroid (Mining keeps one per asteroid). All layers cut = depleted, and a
// class-A asteroid gives its core then (the minigame's won run, PlayerEgo::stopMining).

using UnityEngine;

namespace GoF2Remake.Flight
{
    public class MiningBeamExtraction
    {
        public readonly int Quality;
        public readonly float Yield, LayerMs;

        public int Layer { get; private set; }
        public float LayerTime { get; private set; }
        public bool Depleted { get; private set; }
        /// <summary>Set when a class-A asteroid is depleted: its core is due.</summary>
        public bool GotCore { get; private set; }
        /// <summary>0..1 of the asteroid cut away (the lock plate's percentage).</summary>
        public float Progress01 => Depleted ? 1f : Mathf.Clamp01((Layer + LayerTime / LayerMs) / Quality);

        float ore;

        /// <param name="yieldPercent">Attr 33 (100 = Gunant's Drill).</param>
        /// <param name="layerMs">Attr 102: the time per layer.</param>
        public MiningBeamExtraction(int quality, int yieldPercent, float layerMs)
        {
            Quality = Mathf.Clamp(quality, 4, 7);
            Yield = Mathf.Max(0, yieldPercent) / 100f;
            LayerMs = Mathf.Max(100f, layerMs);
        }

        /// <summary>The beam on the asteroid for dtMs: returns the whole tons cut in this step.</summary>
        public int Update(float dtMs)
        {
            if (Depleted || dtMs <= 0f) return 0;
            float before = ore;
            while (dtMs > 0f && !Depleted)
            {
                // A step never runs past the end of a layer, so a long frame still pays each layer at its own rate.
                float step = Mathf.Min(dtMs, LayerMs - LayerTime);
                ore += step * MiningGame.OreRate(Layer, Yield) * (MiningGame.LayerMs / LayerMs) / 1000f;
                LayerTime += step;
                dtMs -= step;
                if (LayerTime < LayerMs) break;
                LayerTime = 0f;
                if (++Layer >= Quality)
                {
                    Layer = Quality - 1;
                    LayerTime = LayerMs;
                    Depleted = true;
                    GotCore = Quality == 7;
                }
            }
            return (int)ore - (int)before;
        }
    }
}
