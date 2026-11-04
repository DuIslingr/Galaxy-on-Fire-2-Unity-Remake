// RiftRun.cs
// Remake (2026-11-04, for mods): a rift run's rules as plain rules (World.RiftEncounter runs one; the cruise drive's "rift"
// encounter), after EVERSPACE 2's Ancient Rifts (decompiled BP_Encounter_Rift; its mutators.csv):
//   stages     Stages of them, the last the boss's; a fight stage ends at its kill points: StageKillPoints by stage (ES2's
//              GetTargetKillPointCount: 15, 21, 26, 30, 35, 35, 40, 40, 45, 45) + 0..KillPointsSpread, while at least
//              MinAliveShare of them are alive as enemies (MinEnemiesAlive = trunc(target x 0.4))
//   kills      by the ship's class (ES2's EPawnType): KillPoints (drone 0.5, fighter 1, cruiser 1.5, capital 2) toward the
//              target, and ResolveGain (0.10, 0.12, 0.15, 0.20) of the resolve back while any is left
//   resolve    1 at a stage's start, from ResolveDelayS on it drains ResolveDrainPerS a second (ES2's
//              RESOLVE_DECREASE_PER_SECOND -0.016, RESOLVE_DELAY 10; not on the boss's stage); a stage won with resolve left
//              is mastered (ES2's SetStageMastered); run out, the stage goes on, unmastered
//   loot       the boss's crate x LootFactor: 0.5 + 0.5 x the mastered share of the fight stages (ES2's GetLootQuantityFactor:
//              its stage-resolve percentage x 0.5 over the lunacy's base)
//   mutators   from the second stage on, one a stage, uniformly among the rift's mutators not yet in play, the boss's stage one
//              of the boss's (decompiled UGameplayLib::GetRandomRiftMutatorForNextStage over mutators.csv's bAllowedInRifts /
//              bAllowedOnlyForRiftBosses; ES2's three portals each offer one and the pilot flies through one, here the rift
//              picks): Mutators / BossMutators, those of ES2's the remake has; their values ES2's (its Signal Decoder items'
//              mutator attributes)
// The boss's strength is the remake's pick (ES2's comes from its NPC levelling).

using System;
using System.Collections.Generic;

namespace GoF2Remake.Flight
{
    public class RiftRun
    {
        public static readonly int[] StageKillPoints = { 15, 21, 26, 30, 35, 35, 40, 40, 45, 45 };
        public const int KillPointsSpread = 5, DefaultStages = 4;
        public const float ResolveDrainPerS = 0.016f, ResolveDelayS = 10f, MinAliveShare = 0.4f;

        public enum Kind { Drone, Fighter, Cruiser, Capital }

        public static float KillPoints(Kind k) => k == Kind.Drone ? 0.5f : k == Kind.Fighter ? 1f : k == Kind.Cruiser ? 1.5f : 2f;
        public static float ResolveGain(Kind k) => k == Kind.Drone ? 0.10f : k == Kind.Fighter ? 0.12f : k == Kind.Cruiser ? 0.15f : 0.20f;

        // ES2's rift mutators the remake has (World.RiftEncounter does them; attributes.CSV's names, its Signal Decoders' values):
        public const string HullRepair = "mutator_hull_repair",        // Enemy Regen: the enemies repair their hull
                            SpeedBonus = "mutator_speed_bonus",        // Evasive: +SpeedBonusShare speed
                            EmpResistance = "mutator_emp_resistance",  // No EMP
                            NamesHidden = "mutator_names_hidden",      // Jarred Sensors: the enemies' type names hidden
                            HpHidden = "mutator_hp_hidden",            // Hidden Health: their hit point bars hidden
                            ExplodeOnKill = "mutator_explodeonkill",   // Explosive Death: area damage when one dies
                            HealOnKill = "mutator_healonkill",         // Repair On Kill: the others repaired HealOnKillShare
                            BuffOnKill = "mutator_buffonkill",         // Strength in Death: the others +BuffOnKillShare, up to BuffOnKillMax
                            Nearsighted = "mutator_nearsighted",       // half the damage beyond NearsightedM
                            Farsighted = "mutator_farsighted",         // half the damage within FarsightedM
                            NoLock = "mutator_no_lock",                // the enemies can't be locked
                            Vengeance = "mutator_vengeance";           // a detonator drone for every kill, at the pilot
        public static readonly string[] Mutators = { HullRepair, SpeedBonus, EmpResistance, NamesHidden, HpHidden, ExplodeOnKill, HealOnKill,
                                                     BuffOnKill, Nearsighted, Farsighted, NoLock, Vengeance };
        // ... and of the boss's: Quantum Mend (teleports every BossTimerMin..Max s and repairs, invulnerable, until hit), Evasive
        // Drift (boosts away as often), Guardians (invulnerable while two guards it spawns live). Not here: Mines on Death,
        // Overheated Systems, Corrosive Death, Burst Bulbs, Phase Barrier, Stasis Snares, Apocalypse.
        public const string BossTeleportRepairs = "mutator_riftboss_teleportrepairs", BossBoost = "mutator_riftboss_boost",
                            BossBodyguards = "mutator_riftboss_bodyguards";
        public static readonly string[] BossMutators = { BossTeleportRepairs, BossBoost, BossBodyguards };
        public const float SpeedBonusShare = 0.5f, HealOnKillShare = 0.2f, BuffOnKillShare = 0.05f;
        public const int BuffOnKillMax = 10;
        /// <summary>Unity metres: ES2's 30000 / 50000 cm x the ES2 ships' 3.6.</summary>
        public const float NearsightedM = 300f * 3.6f, FarsightedM = 500f * 3.6f, SightedDamageFactor = 0.5f;
        public const float BossTimerMinS = 15f, BossTimerMaxS = 30f;

        public int Stages { get; }
        public int Stage { get; private set; }
        public float Target { get; private set; }
        public float Points { get; private set; }
        public float Resolve { get; private set; } = 1f;
        public bool Finished { get; private set; }
        public bool IsBossStage => Stage >= Stages - 1;
        public readonly List<bool> mastered = new List<bool>();
        public readonly List<string> active = new List<string>();
        float stageS;

        public RiftRun(int stages = DefaultStages) { Stages = Math.Max(2, stages); }

        public static float StageTarget(int stage, float random01) =>
            StageKillPoints[Math.Min(Math.Max(0, stage), StageKillPoints.Length - 1)] + (float)Math.Floor(random01 * (KillPointsSpread + 0.999f));

        /// <summary>How many enemies are kept alive in a fight stage (ES2's MinEnemiesAlive).</summary>
        public int MinAlive => Math.Max(1, (int)(Target * MinAliveShare));

        public bool HasMutator(string id) => active.Contains(id);

        /// <summary>The current stage begins: its target ('random01' 0..1), full resolve; from the second on a mutator
        /// ('pick' 0..1 among those not yet active) is added.</summary>
        public void BeginStage(float random01, float pick)
        {
            Target = IsBossStage ? 0f : StageTarget(Stage, random01);
            Points = 0f;
            Resolve = 1f;
            stageS = 0f;
            if (Stage > 0)
            {
                var free = new List<string>();
                foreach (var m in IsBossStage ? BossMutators : Mutators) if (!active.Contains(m)) free.Add(m);
                if (free.Count > 0) active.Add(free[Math.Min(free.Count - 1, (int)(pick * free.Count))]);
            }
        }

        /// <summary>'dt' seconds on: the resolve drains after the delay (not on the boss's stage).</summary>
        public void Tick(float dt)
        {
            if (Finished || dt <= 0f) return;
            stageS += dt;
            if (!IsBossStage && stageS > ResolveDelayS) Resolve = Math.Max(0f, Resolve - ResolveDrainPerS * dt);
        }

        /// <summary>An enemy of 'k' destroyed: its points, its resolve while any is left. True when the fight stage is won.</summary>
        public bool Kill(Kind k)
        {
            if (Finished || IsBossStage) return false;
            Points += KillPoints(k);
            if (Resolve > 0f) Resolve = Math.Min(1f, Resolve + ResolveGain(k));
            return Points >= Target;
        }

        /// <summary>The stage is over (won, or the boss beaten): mastered with resolve left; the next begins with BeginStage, or
        /// the run is Finished after the boss.</summary>
        public void EndStage()
        {
            if (Finished) return;
            if (!IsBossStage) mastered.Add(Resolve > 0f);
            if (IsBossStage) Finished = true; else Stage++;
        }

        /// <summary>The mastered share of the fight stages so far (0..1).</summary>
        public float MasteredShare
        {
            get
            {
                int n = 0;
                foreach (var m in mastered) if (m) n++;
                return mastered.Count == 0 ? 0f : n / (float)(Stages - 1);
            }
        }

        public float LootFactor => 0.5f + 0.5f * MasteredShare;
    }
}
