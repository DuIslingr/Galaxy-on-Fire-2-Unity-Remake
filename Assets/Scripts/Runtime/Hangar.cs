// Hangar.cs
// One opening of the station's Hangar window (HangarWindow 0x171630) as plain C#: prices for this station, buying and
// selling one unit at a time, mounting / demounting, and buying ships. Works on Session (credits, cargo, mounted
// equipment, ship) and the station's StationStock. Rules: Reference/research/shop.md sections 3, 5, 6.
//   Item::transaction 0xf4074        buy needs stock and credits (no cargo check); sell pays the same price; anything
//                                    sold joins the station's stock
//   HangarWindow::mountItem 0x178824 first free slot of the item's type; secondaries move the whole stack (ammo)
//   HangarWindow::selectItem         one-per-ship categories swap instead (text 287)
//   autoEquipSecondaryWeapons 0x1761c4  bought missiles of a mounted type join the mounted stack
//   HangarWindow::selectItem / OnTouchEnd (ships): trade-in at full price, equipment moves to the new ship's slots,
//                                    the rest to cargo; the dealer then sells your old ship

using System.Collections.Generic;
using System.Linq;
using UnityEngine;

namespace GoF2Remake.Data
{
    public class Hangar
    {
        public enum Result { Ok, NoStock, NoCredits, NothingToSell, NoFreeSlot, Swap, NotMountable, SameShip, NotSaleable }

        readonly Database db;
        readonly Dictionary<int, int> prices = new Dictionary<int, int>();
        public readonly int Station, SystemIndex;
        public readonly StationStock Stock;

        public Hangar(Database db, StationStock stock)
        {
            this.db = db;
            Stock = stock;
            Station = stock.station;
            SystemIndex = Shop.SystemOf(db, Station);
            // HangarWindow::initialize -> Status::calcCargoPrices: each list priced with its own Random(station); the
            // station's price wins in the merged list (Item::mixItems).
            AddPrices(Session.Equipment.Select(e => e.item).ToList());
            AddPrices(Session.Cargo.Select(e => e.item).ToList());
            AddPrices(stock.items.Select(e => e.item).ToList());
            RecordKnownPrices();
        }

        void AddPrices(List<int> items)
        {
            var p = Shop.PriceList(db, Station, items);
            for (int i = 0; i < items.Count; i++) prices[items[i]] = p[i];
        }

        /// <summary>Status+0x3c..0x48: the lowest and highest price seen per item (shown in the item details).</summary>
        void RecordKnownPrices()
        {
            foreach (var kv in prices)
            {
                if (!Session.LowestKnownPrice.TryGetValue(kv.Key, out var lo) || kv.Value < lo.price)
                    Session.LowestKnownPrice[kv.Key] = (kv.Value, SystemIndex);
                if (!Session.HighestKnownPrice.TryGetValue(kv.Key, out var hi) || kv.Value > hi.price)
                    Session.HighestKnownPrice[kv.Key] = (kv.Value, SystemIndex);
            }
        }

        // ---- queries -----------------------------------------------------------------------------------------

        public ShipData Ship => db.Ship(Session.ShipIndex);
        public int PriceOf(int item) => Story.AdjustPrice(Station, item, prices.TryGetValue(item, out int p) ? p : 0);
        /// <summary>Item::isSaleable: story items (Gunant's Drill, the Alien Remains...) can't be sold or demounted (323).</summary>
        public static bool IsSaleable(int item) => !Session.Unsaleable.Contains(item);
        public int StockOf(int item) => Stock.items.Where(s => s.item == item).Sum(s => s.amount);
        public int CargoOf(int item) => Session.Cargo.Where(s => s.item == item).Sum(s => s.amount);
        public bool IsMounted(int item) => Session.Equipment.Any(e => e.item == item);

        /// <summary>Ship::getCurrentLoad: every unit in cargo weighs 1 t; mounted items weigh nothing.</summary>
        public int Load => Shop.CargoLoad();

        /// <summary>Ship::getMaxLoad: base cargo + (int)(base * sum of mounted compression (attr 22) % / 100). No ship mods yet.</summary>
        public int MaxLoad => Shop.MaxLoad(db);

        public bool Overloaded => Load > MaxLoad;

        /// <summary>Item::mixItems: everything in cargo or in stock, by item index.</summary>
        public List<int> ShopItems() =>
            Session.Cargo.Where(s => s.amount > 0).Select(s => s.item)
                .Concat(Stock.items.Where(s => s.amount > 0).Select(s => s.item)).Distinct().OrderBy(i => i).ToList();

        public int SlotCount(int type)
        {
            var s = Ship?.slots;
            if (s == null) return 0;
            return type switch { 0 => s.primary, 1 => s.secondary, 2 => s.turret, 3 => s.equipment + (Session.HasMod(2) ? 1 : 0), _ => 0 };   // mod 2: +1 equipment slot
        }

        public int TypeOf(int item) => db.Item(item)?.TypeId ?? 4;

        /// <summary>Indices into Session.Equipment of the items mounted in slots of this type, in slot order.</summary>
        public List<int> MountedOfType(int type)
        {
            var list = new List<int>();
            for (int i = 0; i < Session.Equipment.Count; i++) if (TypeOf(Session.Equipment[i].item) == type) list.Add(i);
            return list;
        }

        // ---- trading -------------------------------------------------------------------------------------------

        /// <summary>Buy one unit (Item::transaction(true)). 'need' = missing credits on NoCredits.</summary>
        public Result Buy(int item, out int need)
        {
            need = 0;
            var row = Stock.items.Find(s => s.item == item && s.amount > 0);
            if (row == null) return Result.NoStock;
            int price = PriceOf(item);
            if (Session.Credits < price) { need = price - Session.Credits; return Result.NoCredits; }
            row.amount--;
            if (row.amount <= 0) Stock.items.Remove(row);
            AddToCargo(item, 1);
            ChangeCredits(-price);
            Session.SeenItems.Add(item);
            return Result.Ok;
        }

        /// <summary>Sell one unit (Item::transaction(false)): same price as buying, the unit joins the station's stock.</summary>
        public Result Sell(int item)
        {
            var stack = Session.Cargo.Find(s => s.item == item && s.amount > 0);
            if (stack == null) return Result.NothingToSell;
            if (!IsSaleable(item)) return Result.NotSaleable;
            stack.amount--;
            if (stack.amount <= 0) Session.Cargo.Remove(stack);
            var row = Stock.items.Find(s => s.item == item);
            if (row != null) row.amount++;
            else
            {
                int at = Stock.items.FindIndex(s => s.item > item);
                Stock.items.Insert(at < 0 ? Stock.items.Count : at, new ItemStack(item, 1));   // the stock stays in index order
            }
            ChangeCredits(PriceOf(item));
            Session.SeenItems.Add(item);
            return Result.Ok;
        }

        /// <summary>Status::changeCredits: ignores absurd changes, never below 0.</summary>
        static void ChangeCredits(int delta)
        {
            if (Mathf.Abs(delta) > 1000000000) return;
            Session.Credits = Mathf.Max(0, Session.Credits + delta);
        }

        static void AddToCargo(int item, int amount) => Shop.AddToCargo(item, amount);

        // ---- mounting ------------------------------------------------------------------------------------------

        /// <summary>Can a cargo item be mounted? Swap: a one-per-ship item of the same category is mounted at 'swapWith'.</summary>
        public Result CanMount(int item, out int swapWith)
        {
            swapWith = -1;
            var it = db.Item(item);
            if (it == null || CargoOf(item) <= 0) return Result.NothingToSell;
            int type = it.TypeId;
            if (type > 3) return Result.NotMountable;
            if (!Shop.CanInstallMultiple(it.categoryId))
            {
                swapWith = Session.Equipment.FindIndex(e => db.Item(e.item)?.categoryId == it.categoryId);
                if (swapWith >= 0) return Result.Swap;
            }
            return MountedOfType(type).Count < SlotCount(type) ? Result.Ok : Result.NoFreeSlot;
        }

        /// <summary>mountItem: secondaries move the whole stack (the amount is the ammo), everything else one unit.</summary>
        public bool Mount(int item)
        {
            if (CanMount(item, out _) != Result.Ok) return false;
            MountFromCargo(item);
            return true;
        }

        /// <summary>Text 287: demount the mounted one-per-ship item and mount the cargo one.</summary>
        public bool Swap(int equipmentIndex, int item)
        {
            if (equipmentIndex < 0 || equipmentIndex >= Session.Equipment.Count || CargoOf(item) <= 0) return false;
            Demount(equipmentIndex);
            MountFromCargo(item);
            return true;
        }

        void MountFromCargo(int item)
        {
            var stack = Session.Cargo.Find(s => s.item == item);
            int amount = TypeOf(item) == 1 ? stack.amount : 1;
            stack.amount -= amount;
            if (stack.amount <= 0) Session.Cargo.Remove(stack);
            Session.Equipment.Add(new ItemStack(item, amount));
            Session.SeenItems.Add(item);
        }

        /// <summary>demountItem 0x178674: to cargo, secondaries with their ammo.</summary>
        public void Demount(int equipmentIndex)
        {
            if (equipmentIndex < 0 || equipmentIndex >= Session.Equipment.Count) return;
            var e = Session.Equipment[equipmentIndex];
            Session.Equipment.RemoveAt(equipmentIndex);
            AddToCargo(e.item, Mathf.Max(1, e.amount));
        }

        /// <summary>autoEquipSecondaryWeapons: bought missiles of a mounted type join the mounted stack. Returns the items moved.</summary>
        public List<int> AutoEquipSecondaries()
        {
            var moved = new List<int>();
            foreach (var stack in Session.Cargo.ToList())
            {
                if (TypeOf(stack.item) != 1) continue;
                var mounted = Session.Equipment.Find(e => e.item == stack.item);
                if (mounted == null) continue;
                mounted.amount += stack.amount;
                Session.Cargo.Remove(stack);
                moved.Add(stack.item);
            }
            return moved;
        }

        // ---- ships ---------------------------------------------------------------------------------------------

        public int ShipPrice(int ship) => Shop.ShipPrice(db, ship, Station);

        /// <summary>HangarWindow::selectItem (ship row): 'need' = missing credits after trading in the current ship.</summary>
        public Result CanBuyShip(int ship, out int need)
        {
            need = 0;
            if (ship == Session.ShipIndex) return Result.SameShip;
            int cost = ShipPrice(ship) - ShipPrice(Session.ShipIndex);
            if (Session.Credits < cost) { need = cost - Session.Credits; return Result.NoCredits; }
            return Result.Ok;
        }

        /// <summary>Trade-in: credits += current - new; mounted items move to the first free slot of their type in the new
        /// ship (Ship::addEquipment), the rest to cargo; the dealer's row becomes the old ship.</summary>
        public bool BuyShip(int ship)
        {
            if (CanBuyShip(ship, out _) != Result.Ok) return false;
            int old = Session.ShipIndex;
            ChangeCredits(ShipPrice(old) - ShipPrice(ship));
            var mounted = Session.Equipment;
            Session.ShipIndex = ship;
            Session.ShipMods = new List<int>();   // mods stay with the old hull (Ship::clone copies them)
            Session.Equipment = new List<ItemStack>();
            foreach (var e in mounted)
            {
                int type = TypeOf(e.item);
                if (MountedOfType(type).Count < SlotCount(type)) Session.Equipment.Add(e);
                else AddToCargo(e.item, Mathf.Max(1, e.amount));
            }
            int row = Stock.ships.IndexOf(ship);
            if (row >= 0) Stock.ships[row] = old; else Stock.ships.Add(old);
            return true;
        }
    }
}
