// ChorusDogfight.cs
// Remake mods (2026-11-11, a mod hull's "traffic": { "ai": "chorus" }; the Chorus Ships mod's): an NPC fighter fights the way
// Chorus's fighters do (BP_NPC_Ship_Fighter's BT_Fighter_CombatRoam, its tasks' and decorators' values). World.NpcShip
// steers by it (NpcShipChorus):
//   Approach   BTTask_AttackApproach: at the target at LinearSpeedMultiplier 2, firing from FiringStartDistance (600 m) in,
//              for TaskDuration 10 s or until ClosestDistance (50 m), then a PassBy
//   PassBy     BTTask_Flee with EQQuery_PassByPosition: on past the target for 4 s, then the next approach after a
//              BTDecorator_Cooldown (2 s)
//   Evade      BTService_CheckForEnemyAttack (every 0.1 s, NeedsEvadeManeuver): the target aims at it: a 2 s break to its
//              side (BTTask_Flee 2 s), at most every 3 s (BTDecorator_Cooldown 3)
//   Retreat    BTDecorator_CompareHealthPercent < 0.5: a 5 s flight away (BTTask_Flee_14), at most every 15 s
//   Teleport   BTDecorator_CheckForOutOfView (2 s) with CheckInDistance beyond 1200 m: it jumps to 400 m from the target
//              (BTTask_Teleport TeleportToDistance), at most every 15 s
// Its distances are Chorus's centimetres x 0.72 game units (the Chorus ships' scale). The attack tokens (Gen1 / Gen11 / Gen14:
// how many may attack at once, the AI director's) are the remake's: at most MaxAttackers of a crowd on one player fire.
// Plain C#; 'random' gives 0..1.

namespace GoF2Remake.Flight
{
    public class ChorusDogfight
    {
        public enum Mode { Approach, PassBy, Evade, Retreat }

        public const float UnitsPerCm = 0.72f;
        public const float FireStartUnits = 60000f * UnitsPerCm, ClosestUnits = 5000f * UnitsPerCm;
        public const float ApproachMs = 10000f, ApproachSpeed = 2f, PassByMs = 4000f, ApproachCooldownMs = 2000f;
        public const float EvadeMs = 2000f, EvadeCooldownMs = 3000f, RetreatMs = 5000f, RetreatCooldownMs = 15000f, RetreatHull = 0.5f;
        public const float TeleportBeyondUnits = 120000f * UnitsPerCm, TeleportToUnits = 40000f * UnitsPerCm;
        public const float OutOfViewMs = 2000f, TeleportCooldownMs = 15000f;
        public const int MaxAttackers = 3;

        /// <summary>What it sees this step: the target's distance (game units), whether the target's nose is on it, its hull
        /// share, whether it is out of the player's view.</summary>
        public struct View
        {
            public float distance;
            public bool aimedAt, outOfView;
            public float hullRatio;
        }

        public Mode Current { get; private set; } = Mode.Approach;
        /// <summary>The side of its pass, break or retreat (-1 left, 1 right), chosen as it starts.</summary>
        public int Side { get; private set; } = 1;
        float modeMs, waitMs, evadeCdMs, retreatCdMs, teleportCdMs, hiddenMs;
        readonly System.Func<float> random;

        public ChorusDogfight(System.Func<float> random) { this.random = random ?? (() => 0.5f); }

        /// <summary>Its speed now: x2 on an approach.</summary>
        public float SpeedFactor => Current == Mode.Approach && waitMs <= 0f ? ApproachSpeed : 1f;

        /// <summary>It may fire now: on an approach, within its firing distance.</summary>
        public bool Fires(float distance) => Current == Mode.Approach && waitMs <= 0f && distance <= FireStartUnits;

        /// <summary>A new target: a fresh approach.</summary>
        public void NewTarget() { Enter(Mode.Approach); waitMs = 0f; hiddenMs = 0f; }

        void Enter(Mode m)
        {
            Current = m;
            modeMs = 0f;
            Side = random() < 0.5f ? -1 : 1;
        }

        /// <summary>'dtMs' on. Returns true when it should jump to TeleportToUnits from the target now.</summary>
        public bool Step(float dtMs, View v)
        {
            modeMs += dtMs;
            evadeCdMs -= dtMs; retreatCdMs -= dtMs; teleportCdMs -= dtMs; waitMs -= dtMs;
            hiddenMs = v.outOfView && v.distance > TeleportBeyondUnits ? hiddenMs + dtMs : 0f;
            if (hiddenMs >= OutOfViewMs && teleportCdMs <= 0f)
            {
                teleportCdMs = TeleportCooldownMs; hiddenMs = 0f;
                Enter(Mode.Approach); waitMs = 0f;
                return true;
            }
            if (v.hullRatio < RetreatHull && retreatCdMs <= 0f && Current != Mode.Retreat)
            {
                retreatCdMs = RetreatCooldownMs;
                Enter(Mode.Retreat);
                return false;
            }
            if (v.aimedAt && evadeCdMs <= 0f && (Current == Mode.Approach || Current == Mode.PassBy))
            {
                evadeCdMs = EvadeCooldownMs;
                Enter(Mode.Evade);
                return false;
            }
            switch (Current)
            {
                case Mode.Approach:
                    if (waitMs <= 0f && (modeMs >= ApproachMs || v.distance <= ClosestUnits)) Enter(Mode.PassBy);
                    break;
                case Mode.PassBy:
                    if (modeMs >= PassByMs) { Enter(Mode.Approach); waitMs = ApproachCooldownMs; }
                    break;
                case Mode.Evade:
                    if (modeMs >= EvadeMs) Enter(Mode.Approach);
                    break;
                case Mode.Retreat:
                    if (modeMs >= RetreatMs) Enter(Mode.Approach);
                    break;
            }
            return false;
        }
    }
}
