// GoF2Standing.cs
// The player's reputation (Standing 0x14282a.., Reference/research/npc_traffic_ai.md 4.1, ship_combat.md 2.7): two axes
// clamped to +-100, s0 = Terran (+) / Vossk (-), s1 = Nivelian (+) / Midorian (-); a new game starts at s0 = 30, s1 = 0.
//   applyDelict(race, p) (p doubled on Extreme): 0: s0 -= p, 1: s0 += p, 2: s1 -= p, 3: s1 += p
//   isEnemy(0) s0 <= -71, (1) s0 > 70, (2) s1 <= -71, (3) s1 > 70; isFriend the mirror (>= 71 / < -70)
//   callers: kill 5, steal cargo 2, EMP-disable 2, mission completed -5; a pirate kill applyDelict(enemyRace(system), 1)
// Pirates (8) and the Void (9) are always enemies. Between NPCs (no standing, PlayerFighter::update / PlayerTurret::
// pickEnemy): pirates, the Void and race 10 fight everyone else, Terran fights Vossk, Nivelian fights Midorian.
// Not yet: signatures (sort 29 items override the standing).

using GoF2Remake.Data;
using UnityEngine;

namespace GoF2Remake.Flight
{
    public static class GoF2Standing
    {
        public const int Pirate = 8, Void = 9, Specter = 10;
        static readonly int[] EnemyRace = { 1, 0, 3, 2 };   // DAT_00252020, Standing::getEnemyRace

        /// <summary>The value toward 'race' (positive = liked), races 0..3.</summary>
        public static int Toward(int race) => race switch
        {
            0 => GoF2Session.Standing[0],
            1 => -GoF2Session.Standing[0],
            2 => GoF2Session.Standing[1],
            3 => -GoF2Session.Standing[1],
            _ => 0,
        };

        /// <summary>Standing::isEnemy (plus the always-hostile pirates and Void).</summary>
        public static bool IsEnemy(int race) => race == Pirate || race == Void || (race >= 0 && race <= 3 && Toward(race) <= -71);

        /// <summary>Standing::isFriend.</summary>
        public static bool IsFriend(int race) => race >= 0 && race <= 3 && Toward(race) >= 71;

        /// <summary>Standing::applyDelict: moves the race's axis away from it by p (x2 on Extreme).</summary>
        public static void ApplyDelict(int race, int p)
        {
            if (race < 0 || race > 3) return;
            if (GoF2Session.IsExtreme) p *= 2;
            int axis = race <= 1 ? 0 : 1;
            int sign = race == 0 || race == 2 ? -1 : 1;
            GoF2Session.Standing[axis] = Mathf.Clamp(GoF2Session.Standing[axis] + sign * p, -100, 100);
        }

        /// <summary>A kill by the player: race 0..3 -> delict 5; a pirate -> 1 toward the system race.</summary>
        public static void ApplyKill(int race, int systemRace)
        {
            if (race == Pirate) { int e = EnemyRaceOf(systemRace); if (e >= 0) ApplyDelict(e, 1); return; }
            ApplyDelict(race, 5);
        }

        /// <summary>SolarSystem::getAttackRace / Standing::getEnemyRace: [1, 0, 3, 2][race], else pirates.</summary>
        public static int EnemyRaceOf(int race) => race >= 0 && race <= 3 ? EnemyRace[race] : Pirate;

        /// <summary>NPC vs NPC: do ships of races a and b fight each other? (The player's ship counts as race 0.)</summary>
        public static bool RacesHostile(int a, int b) =>
            (a == Pirate) != (b == Pirate) || (a == Void) != (b == Void) || (a == Specter) != (b == Specter)
            || (a == 0 && b == 1) || (a == 1 && b == 0) || (a == 2 && b == 3) || (a == 3 && b == 2);
    }
}
