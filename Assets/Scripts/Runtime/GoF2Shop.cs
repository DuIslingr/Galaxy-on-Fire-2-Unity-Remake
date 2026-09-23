// GoF2Shop.cs
// The station shop's rules as plain C# (Reference/research/shop.md; price reference code tools/shop/prices.py):
//   Status::calcCargoPrices 0xb9d70   prices per station: java.util.Random(station), min + distance factor * (max - min)
//                                     +- 2 %, reseeded for each list (cargo, mounted, stock); selling pays the same price
//   Generator::getItemBuyList 0xa05c4 random stock by tech level, occurrence and campaign progress
//   Generator::getShipBuyList 0xa0eb8 0..5 ships of the system's race (sometimes another race)
//   Generator::computerTradeGoods     re-entering after > 30 s nibbles 0..2 units off each stock row
//   Status::departStation / addStationToStack: stock is kept for the last 3 visited stations
//   Ship::adjustPrice 0x1a433c         ship price -1 % in systems of its race
// The time-seeded parts (stock, ships) use UnityEngine.Random, like the rest of the per-visit randomness.
// Hardcore = Extreme difficulty. Both add-ons count as owned (their assets are part of the remake).
// Not ported: DLC-won and supernova extras, Kaamo Club storage, black-market signatures, blueprints.

using System.Collections.Generic;
using System.Linq;
using UnityEngine;

namespace GoF2Remake.Data
{
    public static class GoF2Shop
    {
        public const int RecentStationCount = 3;
        public const float TradeGoodsDelaySeconds = 30f;   // Generator::computerTradeGoods after > 30000 ms

        /// <summary>DAT_00254990 = DAT_0025cee4: race per ship (0 Terran, 1 Vossk, 2 Nivelian, 3 Midorian, 8 pirate, 9 void).</summary>
        public static readonly int[] ShipRace =
        {
            3, 0, 8, 3, 2, 0, 3, 0, 9, 1, 0, 8, 2, 0, 0, 0, 2, 0, 2, 3, 3, 2, 0, 8, 8, 8, 0, 0, 0, 8, 3, 2,
            8, 0, 0, 2, 0, 0, 0, 1, 0, 1, 1, 2, 1, 3, 3, 3, 3, 1, 1, 0, 8, 1, 1, 0, 3, 2, 0, 0, 8, 1, 3, 1,
        };

        /// <summary>DAT_00254930 (Item::canBeInstalledMultipleTimes): categories a ship can mount only once.</summary>
        static readonly HashSet<int> OnePerShip = new HashSet<int> { 8, 9, 10, 13, 14, 15, 16, 17, 18, 19, 21, 26, 27, 28, 29, 33, 35, 37, 38, 41 };
        public static bool CanInstallMultiple(int category) => !OnePerShip.Contains(category);

        /// <summary>DAT_00251d10: Kaamo Club specials, never in a normal shop.</summary>
        static readonly HashSet<int> KaamoSpecials = new HashSet<int> { 200, 220, 208, 213, 216, 228, 229, 230, 231 };
        static readonly HashSet<int> SaoPerulaGoods = new HashSet<int> { 101, 102, 103, 107, 108, 109, 114, 124 };

        // ---- cargo (Ship::getCurrentLoad / getMaxLoad) -----------------------------------------------------------

        /// <summary>Every unit in cargo weighs 1 t; mounted items weigh nothing.</summary>
        public static int CargoLoad() => GoF2Session.Cargo.Sum(s => s.amount);

        /// <summary>Base cargo + (int)(base * sum of mounted compression (attr 22, category 12) % / 100). No ship mods yet.</summary>
        public static int MaxLoad(GoF2Database db)
        {
            int b = db.Ship(GoF2Session.ShipIndex)?.cargo ?? 0, pct = 0;
            foreach (var e in GoF2Session.Equipment) { var it = db.Item(e.item); if (it != null && it.categoryId == 12) pct += it.Attr(22); }
            return b + (int)(b * pct / 100f);
        }

        public static int FreeCargo(GoF2Database db) => MaxLoad(db) - CargoLoad();

        public static void AddToCargo(int item, int amount)
        {
            if (amount <= 0) return;
            var stack = GoF2Session.Cargo.Find(s => s.item == item);
            if (stack != null) stack.amount += amount;
            else GoF2Session.Cargo.Add(new GoF2Stack(item, amount));
        }

        /// <summary>Ship::getFirstEquipmentOfSort: the first mounted item of a category, or null.</summary>
        public static ItemData FirstMounted(GoF2Database db, int category)
        {
            foreach (var e in GoF2Session.Equipment) { var it = db.Item(e.item); if (it != null && it.categoryId == category) return it; }
            return null;
        }

        // ---- geometry ----------------------------------------------------------------------------------------

        public static int SystemOf(GoF2Database db, int station) => db.Stations.Find(s => s.index == station)?.system ?? 0;
        public static int RaceOfSystem(GoF2Database db, int system) => db.Systems.Find(s => s.index == system)?.raceId ?? 0;

        /// <summary>Galaxy::distancePercent 0x1a4e40: (int)sqrt(dx^2 + dy^2) on the galaxy map.</summary>
        public static int Distance(GoF2Database db, int systemA, int systemB)
        {
            var a = db.Systems.Find(s => s.index == systemA)?.mapPosition;
            var b = db.Systems.Find(s => s.index == systemB)?.mapPosition;
            if (a == null || b == null) return 0;
            float dx = b.x - a.x, dy = b.y - a.y;
            return (int)Mathf.Sqrt(dy * dy + dx * dx);
        }

        // ---- prices ------------------------------------------------------------------------------------------

        /// <summary>Status::calcCargoPrices: the prices of 'items' at 'station', in list order with a fresh
        /// java.util.Random(station) (so the same list always gets the same prices).</summary>
        public static int[] PriceList(GoF2Database db, int station, IList<int> items)
        {
            int system = SystemOf(db, station);
            var rnd = new GoF2JavaRandom(station);
            var prices = new int[items.Count];
            for (int n = 0; n < items.Count; n++)
            {
                var it = db.Item(items[n]);
                if (it == null) continue;
                if (system == 25) { prices[n] = it.maxPrice; continue; }   // Loma: always the maximum (shop.md uncertainty 4)
                float span = Distance(db, it.lowestPriceSystem, it.highestPriceSystem);
                float cur = Distance(db, it.lowestPriceSystem, system);
                float f = 100f / span * cur / 100f;                         // span 0 -> inf / NaN -> 1
                if (!(f < 1f)) f = 1f;
                int b = it.minPrice + (int)(f * (it.maxPrice - it.minPrice));
                int d = Mathf.Max(1, (int)(b * 0.02f));
                prices[n] = b - d + rnd.NextInt(2 * d + 1);
            }
            return prices;
        }

        /// <summary>Ship::adjustPrice: ships.json price, 1 % less in a system of the ship's race.</summary>
        public static int ShipPrice(GoF2Database db, int ship, int station)
        {
            var s = db.Ship(ship);
            if (s == null) return 0;
            int race = RaceOfSystem(db, SystemOf(db, station));
            return ship < ShipRace.Length && ShipRace[ship] == race ? (int)(s.price * 0.99f) : s.price;
        }

        // ---- docking: stock kept for the last 3 stations ------------------------------------------------------

        /// <summary>Status::departStation (on arrival) + ModStation::OnInitialize: the station's stock, generated when the
        /// station isn't among the last 3 visited, otherwise nibbled by computerTradeGoods after > 30 s away.</summary>
        public static GoF2StationStock EnterStation(GoF2Database db, int station)
        {
            var recent = GoF2Session.RecentStations;
            var stock = recent.Find(s => s.station == station);
            if (stock == null)
            {
                stock = new GoF2StationStock { station = station, items = GenerateItems(db, station), ships = GenerateShips(db, station) };
                recent.Add(stock);
                while (recent.Count > RecentStationCount) recent.RemoveAt(0);
            }
            else if (GoF2Session.LastDepartureTime >= 0f && Time.realtimeSinceStartup - GoF2Session.LastDepartureTime > TradeGoodsDelaySeconds
                     && station != 108)
            {
                foreach (var row in stock.items)
                {
                    int r = Random.Range(0, 3);
                    if (r < row.amount) row.amount -= r;
                }
            }
            return stock;
        }

        /// <summary>Generator::getItemBuyList 0xa05c4 (see shop.md 4.3).</summary>
        public static List<GoF2Stack> GenerateItems(GoF2Database db, int station)
        {
            var list = new List<GoF2Stack>();
            int mission = GoF2Session.CampaignMission;
            if (station == 78 && mission < 7)   // tutorial: the free starter gear only
            {
                list.Add(new GoF2Stack(0, 1)); list.Add(new GoF2Stack(22, 1)); list.Add(new GoF2Stack(55, 1));
                return list;
            }
            if (station == 108) return list;

            var st = db.Stations.Find(s => s.index == station);
            int techS = st?.techLevel ?? 1;
            int system = st?.system ?? 0;
            int race = RaceOfSystem(db, system);
            bool hardcore = GoF2Session.IsExtreme;
            float k = Mathf.Min(1.5f, (mission + 25) / 45f);
            int lowTech = station == 105 || station == 107 ? 0 : techS < 4 ? 1 : techS / 2;

            foreach (var it in db.Items)
            {
                int idx = it.index, type = it.TypeId, sort = it.categoryId, techI = it.techLevel, occ = it.occurrence;
                bool specialty = idx >= 132 && idx <= 153;
                bool exclusive = it.Attr(61, -1) == station && !((idx == 196 || (idx >= 198 && idx <= 200)) && mission < 142);
                if (station == 106 && !(SaoPerulaGoods.Contains(idx) || specialty)) continue;

                // Owned add-ons give items without an occurrence one (Valkyrie for idx < 196, Supernova above).
                if (occ == 0 && !exclusive && type != 4 && idx != 85 && it.blueprint.Count == 0 && !(idx == 181 && mission < 59)
                    && !((sort >= 33 && sort <= 35 || sort == 43) && mission < 142) && sort != 36 && sort != 29
                    && idx != 209 && idx != 210 && idx != 217 && idx != 218 && !(idx == 205 && mission < 94) && !KaamoSpecials.Contains(idx))
                    occ = Random.Range(0, 30) + (int)((1f - techI / 10f) * 30f);

                if (!exclusive)
                {
                    if (it.blueprint.Count > 0 || idx == 217 || idx == 218 || idx == 164 || idx == 175) continue;
                    if (techS < techI || occ == 0 || it.maxPrice == 0) continue;
                    if (it.Attr(60) == 1 && race != 1) continue;                            // Vossk-only gear
                    if (specialty && idx != 132 + system && station != 106) continue;       // one specialty per system
                }
                if (hardcore && (sort == 23 || sort == 24)) continue;
                if (station == 107 && type != 3) continue;
                if (station == 105 && !(type <= 2 || sort == 28)) continue;
                if (station == 101 && type > 2) continue;
                if (station == 106 && type != 4) continue;

                if (!exclusive)
                {
                    if (!((techI <= techS || specialty) && Random.Range(0, 100) < (int)(k * occ))) continue;
                    if (techI < lowTech && idx != 122 && !(Random.Range(0, 100) < 61)) continue;
                }

                int r = Random.Range(0, 15) + 5;   // 5..19
                int amount;
                if (idx == 109) amount = Mathf.Max(1, r / 2);
                else if (type == 1) amount = r;
                else if (type == 4)
                {
                    amount = r;
                    int inv = 100 - Distance(db, system, it.lowestPriceSystem);
                    if (inv > 50) amount = r * Mathf.Max(1, (int)((inv - 50) / 50f * (hardcore ? 2 : 20)));
                    if (idx == 110) amount = Mathf.Min(amount, Random.Range(0, 10) + 10);
                }
                else amount = Mathf.Max(1, r / 5);   // weapons, turrets, equipment: 1..3
                list.Add(new GoF2Stack(idx, amount));
            }
            // Remake-only, while there is no campaign: the starting station always sells the cheapest drill (IMT Extract 1.3,
            // normally a 70 % chance there) to keep mining reachable, and energy cells, which the free-play Khador jump out of
            // gateless Mido needs (GoF2GalaxyMap.HasJumpDrive).
            if (station == 78 && !list.Any(s => db.Item(s.item)?.categoryId == 19)) InsertSorted(list, new GoF2Stack(86, 1));
            if (station == 78 && !list.Any(s => s.item == GoF2GalaxyMap.EnergyCellItem))
                InsertSorted(list, new GoF2Stack(GoF2GalaxyMap.EnergyCellItem, Random.Range(0, 15) + 5));
            return list;
        }

        /// <summary>Keeps the stock in item index order.</summary>
        static void InsertSorted(List<GoF2Stack> list, GoF2Stack row)
        {
            int at = list.FindIndex(s => s.item > row.item);
            list.Insert(at < 0 ? list.Count : at, row);
        }

        /// <summary>Generator::getShipBuyList 0xa0eb8 (shop.md 4.4, without the DLC-won and supernova extras).</summary>
        public static List<int> GenerateShips(GoF2Database db, int station)
        {
            var ships = new List<int>();
            int system = SystemOf(db, station);
            if (station == 101 || station == 108 || (system == 15 && GoF2Session.CampaignMission < 16)) return ships;
            int race = RaceOfSystem(db, system);
            int n = Random.Range(0, 6) + (station == 41 ? 1 : 0);
            for (int i = 0; i < n; i++)
            {
                int ship;
                if (i == 0 && station == 41) ship = 10;          // Phantom
                else if (i == 0 && station == 78) ship = 0;      // Betty
                else
                {
                    int r = race;
                    if (n > 1 && Random.value < 0.22f) { r = Random.Range(0, 5); if (r == race || r == 4) r = 8; }
                    ship = RandomFighter(r);
                }
                if (!ships.Contains(ship)) ships.Add(ship);
            }
            if (race == 0 && Random.Range(0, 7) == 0) ships.Add(62);
            if (race == 1 && Random.Range(0, 5) == 0) ships.Add(63);
            if (race == 2 && Random.Range(0, 8) == 0) ships.Add(61);
            if (race == 1 && Random.Range(0, 4) == 0) ships.Add(54);
            if (race == 0 && Random.Range(0, 8) == 0) ships.Add(51);
            if (system == 17) foreach (int s in new[] { 42, 43, 52 }) if (Random.Range(0, 3) == 0) ships.Add(s);
            return ships.Distinct().ToList();
        }

        /// <summary>Globals::getRandomEnemyFighter 0xf9034.</summary>
        public static int RandomFighter(int race)
        {
            if (race == 1) return 9;
            if (race == 9 || (race >= 4 && race <= 7)) return 8;   // void and the minor races: VoidX
            if (race == 10) return 44;
            var list = race == 8 ? World.GoF2StationTables.PirateFighters : World.GoF2StationTables.RaceFighters[Mathf.Clamp(race, 0, 3)];
            return list[Random.Range(0, list.Length)];
        }
    }
}
