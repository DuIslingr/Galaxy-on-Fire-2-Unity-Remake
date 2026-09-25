// NpcTables.cs
// NPC rules as plain C# (Reference/research/npc_traffic_ai.md 2-3, ship_combat.md 3-5; reference implementation
// Reference/tools/npc/npc_tables.py):
//   Globals::getRandomEnemyFighter 0xf9034   ship pool per race (races 4-8 and >= 11 use the pirates')
//   Level::createShip 0xcf83c               hull (4 * campaign + 14 * rank + 20, freighters x5, battleship x25,
//                                           Extreme x2), hit cube half-size 1000 (650 Extreme), EMP 5 * rank + 40
//   Level::assignGuns 0xcb638               one gun: 4 bullets, 16 u/ms, 3000 ms, reload 600 - 2 * campaign ms, damage
//                                           clamp(int(0.9 * (rank - 2)), 0, 20) (x2 Extreme, cap 22) + 2, 3 minimum;
//                                           the look (projectile, impact) and shot sound of one item per race
//   Level::createMission 0xbda70            raider chance per security level 90 / 65 / 35 / 10 %
//   Generator::getLootList 0xa1b78          what an NPC carries (1/3 nothing; 1-2 entries)

using System.Collections.Generic;
using GoF2Remake.Data;
using UnityEngine;

namespace GoF2Remake.Flight
{
    public static class NpcTables
    {
        public const float BaseSpeed = 2f, BoostSpeed = 5.5f, FreighterSpeed = 1f;   // u/ms
        public const int GunPool = 4;
        public const float GunLifetimeMs = 3000f, GunSpeed = 16f;
        public const float DetectRange = 50000f, FireRange = 35000f, BreakOffRange = 8000f;
        public const float FireCone = 0.0076294f;   // PlayerFighter+0x1a4, 0x3bf9fff6

        static readonly Dictionary<int, int[]> Fighters = new Dictionary<int, int[]>
        {
            [0] = new[] { 1, 5, 7, 17, 22, 26, 27, 28, 33, 34, 36 },
            [1] = new[] { 9 },
            [2] = new[] { 4, 12, 16, 18, 21, 31, 35 },
            [3] = new[] { 3, 6, 19, 20, 30 },
            [8] = new[] { 2, 11, 23, 24, 25, 29, 32 },
            [9] = new[] { 8 },
            [10] = new[] { 44 },
        };

        /// <summary>Globals::getRandomEnemyFighter.</summary>
        public static int RandomFighter(int race)
        {
            if (!Fighters.TryGetValue(race, out var pool)) pool = Fighters[8];
            return pool[Random.Range(0, pool.Length)];
        }

        /// <summary>Freighter ship index and its race (30 % Nivelian in Terran systems and the other way round).</summary>
        public static (int ship, int race) RandomFreighter(int systemRace)
        {
            int race = systemRace;
            if (Random.Range(0, 100) < 30) race = systemRace == 0 ? 2 : systemRace == 2 ? 0 : systemRace;
            if (race < 0 || race > 3) race = 0;
            return (race == 1 ? 13 : 15, race);
        }

        public static string FreighterAssembly(int race) => race switch
        {
            1 => "cargo_004_vossk",
            2 => "cargo_002_nivelian",
            3 => "cargo_001_midorian",
            _ => "cargo_003_terran",
        };

        static float Difficulty => Session.IsExtreme ? 2f : 1f;   // x + x * (options[0x2c] - 0.5)

        /// <summary>The campaign index the NPC formulas use: capped at 45 once the main story is won (Level::createShip's
        /// "gameWon ? 180 : 4 * campaign", assignGuns' 600 - 2 * 45).</summary>
        static int StatCampaign => !Session.FreePlay && Session.CampaignMission >= Story.GameWonIndex ? Story.GameWonIndex : Session.CampaignMission;

        /// <summary>Level::createShip hull. kind: 0 fighter, 1 fixed object (freighter / battleship 14).</summary>
        public static int Hull(int kind, int ship)
        {
            int rank = Mathf.Min(Session.Rank, 20);
            float hp = 4 * StatCampaign + 14 * rank + 20;
            if (ship == 51) hp *= 1.7f; else if (ship == 49) hp *= 17f; else if (ship == 44) hp *= 2.25f;
            if (kind == 1) hp *= ship == 14 ? 25 : 5;
            return (int)(hp * Difficulty);
        }

        public static int Emp(int kind) => (5 * Mathf.Min(Session.Rank, 20) + 40) * (kind == 1 ? 3 : 1);
        public static float EmpRecoveryMs(int kind) => kind == 1 ? 45000f : 15000f;
        public static float HitRadiusUnits => Session.IsExtreme ? 650f : 1000f;

        /// <summary>Level::assignGuns damage (race 9 x0.8, race 10 x0.7).</summary>
        public static int GunDamage(int race)
        {
            float f = 0.9f * (Session.Rank - 2);
            int b = f >= 20 ? 20 : f < 0 ? 0 : (int)f;
            int d = (int)(b * Difficulty);
            if (d > 21) d = 22;
            int dmg = d == 0 ? 3 : d + 2;
            if (race == 9) dmg = (int)(dmg * 0.8f); else if (race == 10) dmg = (int)(dmg * 0.7f);
            // Level::assignGuns: the same campaign mission failed 3+ times in a row -> NPC guns x0.7.
            if (!Session.FreePlay && Session.FailCount >= 3 && Session.LastFailedMission == Session.CampaignMission) dmg = (int)(dmg * 0.7f);
            return Mathf.Max(1, dmg);
        }

        public static float GunReloadMs => 600f - 2f * StatCampaign;

        /// <summary>The item whose projectile / impact an NPC gun of this race shows.</summary>
        public static int GunItem(int race) => race switch { 0 => 0, 1 => 3, 2 => 7, 3 => 25, 9 => 5, 10 => 229, _ => 19 };

        /// <summary>DAT_002526c0 shot sound per race, as an index into CombatAssets.shots: 0 Nirai EX1 (52),
        /// 1 Shkoom (55), 2 Nirai Charged (54), 3 Nirai EX2 (53), 4 Laser_Enemy (61, also the Void's 62 stand-in).</summary>
        public static int ShotSound(int race) => race switch { 0 => 0, 1 => 1, 2 => 2, 3 => 3, _ => 4 };

        /// <summary>Level::createMission: raider group chance for the (effective) security level.</summary>
        public static int RaiderChance(int security) => security <= 0 ? 90 : security == 1 ? 65 : security == 2 ? 35 : 10;

        static readonly int[] LootTypeChance = { 10, 40, 2, 10, 100, 10 };   // DAT_00251e5c by item type

        /// <summary>Generator::getLootList(-1, -1): the cargo an NPC drops (empty 1/3 of the time).</summary>
        public static List<ItemStack> RollLoot(Database db, bool freighter)
        {
            var list = new List<ItemStack>();
            int n = Random.Range(0, 3);
            if (Random.Range(0, 3) == 0) return list;
            for (int e = 0; e < Mathf.Max(1, n); e++)
            {
                ItemStack entry = null;
                for (int tries = 0; tries < 100 && entry == null; tries++)
                {
                    var it = db.Items[Random.Range(0, db.Items.Count)];
                    int type = it.TypeId;
                    if (it.blueprint.Count > 0 || it.maxPrice <= 0) continue;
                    if (it.index == 164 || it.index == 175 || it.index == 217 || it.index == 218) continue;
                    if (Random.Range(0, 100) >= (type >= 0 && type < LootTypeChance.Length ? LootTypeChance[type] : 10)) continue;
                    if (Random.Range(0, 100) >= it.occurrence) continue;
                    if (type == 4) entry = new ItemStack(it.index, Random.Range(0, 9) + 1);
                    else if (it.techLevel < 8) entry = new ItemStack(it.index, Random.Range(0, 3) + 1);
                }
                entry ??= new ItemStack(154 + Random.Range(0, 10), Random.Range(0, 9) + 1);
                if (freighter) entry.amount = Mathf.Max(entry.amount * (Random.Range(0, 4) + 2), Random.Range(0, 5) + 8);
                list.Add(entry);
            }
            if (GalaxyMap.HasJumpDrive(db) && GalaxyMap.CellsInCargo() == 0 && Random.Range(0, 100) < 10)
                list[0] = new ItemStack(GalaxyMap.EnergyCellItem, Random.Range(0, 9) + 1);
            return list;
        }
    }
}
