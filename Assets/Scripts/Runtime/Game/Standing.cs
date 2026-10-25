// Standing.cs
// The player's reputation (Standing 0x14282a.., Reference/research/npc_traffic_ai.md 4.1, ship_combat.md 2.7): two axes
// clamped to +-100, s0 = Terran (+) / Vossk (-), s1 = Nivelian (+) / Midorian (-); a new game starts at s0 = 30, s1 = 0.
//   applyDelict(race, p) (p doubled on Extreme): 0: s0 -= p, 1: s0 += p, 2: s1 -= p, 3: s1 += p
//   isEnemy(0) s0 <= -71, (1) s0 > 70, (2) s1 <= -71, (3) s1 > 70; isFriend the mirror (>= 71 / < -70)
//   callers: kill 5, steal cargo 2, EMP-disable 2, mission completed -5; a pirate kill applyDelict(enemyRace(system), 1)
// Pirates (8) and the Void (9) are always enemies. Between NPCs (no standing, PlayerFighter::update / PlayerTurret::
// pickEnemy): pirates, the Void and race 10 fight everyone else, Terran fights Vossk, Nivelian fights Midorian.
// Signatures (items 189-192, sort 29; combat_equipment.md 3.3, Standing::setPlayerSignatureRace 0x142898): with a
// signature of race S mounted, S is a friend (+100), its rival an enemy (-100), the other two races neutral (70) whatever
// the axes say; a pirate kill then gives no +1. Friendly fire on the signature's race (33 % / 10 % hc) or on any race
// 0..3 (50 % / 25 % hc) makes it invalid: the item is removed, delict 100 toward S, "Signature invalid" (324).
// Remake mods: a mod's factions (Modding.ModFactions, race numbers from ModFactions.FirstRace) have one standing each
// (Session.FactionStanding), hostile at -71 and below, friends at 71 and above, always hostile when the faction says so (like
// the pirates); their relations decide NPC vs NPC (ModFactions.Relation). Signatures are the game races' only.

using GoF2Remake.Data;
using UnityEngine;

namespace GoF2Remake.Flight
{
    public static class Standing
    {
        public const int Pirate = 8, Void = 9, Specter = 10;
        static readonly int[] EnemyRace = { 1, 0, 3, 2 };   // DAT_00252020, Standing::getEnemyRace

        /// <summary>The mounted signature's race (items 189-192: Terran, Vossk, Nivelian, Midorian), -1 = none.</summary>
        public static int SignatureRace
        {
            get
            {
                foreach (var e in Session.Equipment) if (e.item >= 189 && e.item <= 192) return e.item - 189;
                return -1;
            }
        }

        /// <summary>Removes the mounted signature (Player::damage friendly fire): delict 100 toward its race.</summary>
        public static bool InvalidateSignature()
        {
            int s = SignatureRace;
            if (s < 0) return false;
            Session.Equipment.RemoveAll(e => e.item == 189 + s);
            ApplyDelict(s, 100);
            return true;
        }

        /// <summary>The value toward 'race' (positive = liked), races 0..3; a signature overrides it (Standing::getStanding).</summary>
        public static int Toward(int race) => TowardWith(race, Session.Standing[0], Session.Standing[1], SignatureRace);

        /// <summary>Toward with given axes and signature (multiplayer: another player's, NetPlayer).</summary>
        public static int TowardWith(int race, int axis0, int axis1, int signature)
        {
            if (Modding.ModFactions.Is(race)) return Modding.ModFactions.Standing(race);   // (another player's: this game's, not synced)
            if (signature >= 0 && race >= 0 && race <= 3) return race == signature ? 100 : race == EnemyRace[signature] ? -100 : 70;
            return race switch { 0 => axis0, 1 => -axis0, 2 => axis1, 3 => -axis1, _ => 0 };
        }

        /// <summary>IsEnemy / IsFriend with given axes and signature (multiplayer: another player's).</summary>
        public static bool IsEnemyWith(int race, int axis0, int axis1, int signature) =>
            Modding.ModFactions.Is(race) ? FactionEnemy(race)
            : race == Pirate || race == Void || (race >= 0 && race <= 3 && TowardWith(race, axis0, axis1, signature) <= -71);
        public static bool IsFriendWith(int race, int axis0, int axis1, int signature) =>
            Modding.ModFactions.Is(race) ? FactionFriend(race) : race >= 0 && race <= 3 && TowardWith(race, axis0, axis1, signature) >= 71;

        /// <summary>A mod faction is the player's enemy: always if "hostile", else at -71 and below.</summary>
        static bool FactionEnemy(int race) => Modding.ModFactions.Get(race) is var d && d != null && (d.hostile || Modding.ModFactions.Standing(race) <= -71);
        static bool FactionFriend(int race) => Modding.ModFactions.Get(race) is var d && d != null && !d.hostile && Modding.ModFactions.Standing(race) >= 71;

        /// <summary>The standing axes themselves (the Status window, mission bonuses).</summary>
        public static int RawToward(int race) => Modding.ModFactions.Is(race) ? Modding.ModFactions.Standing(race) : race switch
        {
            0 => Session.Standing[0],
            1 => -Session.Standing[0],
            2 => Session.Standing[1],
            3 => -Session.Standing[1],
            _ => 0,
        };

        /// <summary>Standing::isEnemy (plus the always-hostile pirates and Void).</summary>
        public static bool IsEnemy(int race) => Modding.ModFactions.Is(race) ? FactionEnemy(race) : race == Pirate || race == Void || (race >= 0 && race <= 3 && Toward(race) <= -71);

        /// <summary>Standing::isFriend.</summary>
        public static bool IsFriend(int race) => Modding.ModFactions.Is(race) ? FactionFriend(race) : race >= 0 && race <= 3 && Toward(race) >= 71;

        /// <summary>Standing::applyDelict: moves the race's axis away from it by p (x2 on Extreme).</summary>
        public static void ApplyDelict(int race, int p)
        {
            if (Modding.ModFactions.Is(race))
            {
                // a mod faction: its standing down by p (x2 on Extreme), like one end of a game axis
                if (Session.IsExtreme) p *= 2;
                Modding.ModFactions.SetStanding(race, Modding.ModFactions.Standing(race) - p);
                return;
            }
            if (race < 0 || race > 3) return;
            if (Session.IsExtreme) p *= 2;
            int axis = race <= 1 ? 0 : 1;
            int sign = race == 0 || race == 2 ? -1 : 1;
            Session.Standing[axis] = Mathf.Clamp(Session.Standing[axis] + sign * p, -100, 100);
        }

        /// <summary>A kill by the player: race 0..3 -> delict 5; a pirate -> 1 toward the system race.</summary>
        public static void ApplyKill(int race, int systemRace)
        {
            if (Modding.ModFactions.Get(race) is Modding.ModFactions.Def f)
            {
                // a hostile faction's ship, like a pirate: +1 with the system's faction when it is that faction's enemy; any
                // other faction's: delict 5
                if (f.hostile)
                {
                    if (Modding.ModFactions.Is(systemRace) && Modding.ModFactions.Relation(race, systemRace) == Modding.ModFactions.Enemy)
                        Modding.ModFactions.SetStanding(systemRace, Modding.ModFactions.Standing(systemRace) + 1);
                    return;
                }
                ApplyDelict(race, 5);
                return;
            }
            if (race == Pirate) { int e = EnemyRaceOf(systemRace); if (e >= 0 && SignatureRace < 0) ApplyDelict(e, 1); return; }
            ApplyDelict(race, 5);
        }

        /// <summary>SolarSystem::getAttackRace / Standing::getEnemyRace: [1, 0, 3, 2][race], else pirates.</summary>
        public static int EnemyRaceOf(int race)
        {
            if (Modding.ModFactions.Is(race)) { var e = Modding.ModFactions.EnemiesOf(race); return e.Count > 0 ? e[0] : Pirate; }   // remake mods
            return race >= 0 && race <= 3 ? EnemyRace[race] : Pirate;
        }

        /// <summary>NPC vs NPC: do ships of races a and b fight each other? (The player's ship counts as race 0.)</summary>
        public static bool RacesHostile(int a, int b) =>
            Modding.ModFactions.Is(a) || Modding.ModFactions.Is(b) ? Modding.ModFactions.Relation(a, b) == Modding.ModFactions.Enemy :
            (a == Pirate) != (b == Pirate) || (a == Void) != (b == Void) || (a == Specter) != (b == Specter)
            || (a == 0 && b == 1) || (a == 1 && b == 0) || (a == 2 && b == 3) || (a == 3 && b == 2);

        /// <summary>A race by its word ("vossk", "pirates", or the language's race name), -1 = none (the admin commands, mods' characters).</summary>
        public static int RaceWord(string w)
        {
            switch (w.ToLowerInvariant())
            {
                case "terran": case "terrans": return 0;
                case "vossk": return 1;
                case "nivelian": case "nivelians": return 2;
                case "midorian": case "midorians": return 3;
                case "pirate": case "pirates": return Standing.Pirate;
                case "void": return Standing.Void;
                case "specter": case "specters": return Standing.Specter;
            }
            foreach (int r in new[] { 0, 1, 2, 3, Standing.Pirate, Standing.Void, Standing.Specter })
                if (string.Equals(GoF2Remake.Data.Localization.Get(406 + r), w, System.StringComparison.OrdinalIgnoreCase)) return r;
            // remake mods: a faction by its key, id or name
            if (Modding.ModFactions.TryResolve(w, null, out int fr) && Modding.ModFactions.Is(fr)) return fr;
            foreach (var d in Modding.ModFactions.All)
                if (string.Equals(Modding.ModFactions.Name(d.race), w, System.StringComparison.OrdinalIgnoreCase)) return d.race;
            return -1;
        }

        /// <summary>The game race whose tables a race uses (hangar, bar, visitors, music, guns): a mod faction's "look".</summary>
        public static int Look(int race) => Modding.ModFactions.Look(race);

        /// <summary>A race's name: the game's (text 406 + race) or a mod faction's.</summary>
        public static string RaceName(int race) =>
            Modding.ModFactions.Is(race) ? Modding.ModFactions.Name(race) : race >= 0 && race <= 10 ? GoF2Remake.Data.Localization.Get(406 + race) : "";
    }
}
