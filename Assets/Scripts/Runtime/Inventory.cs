// Inventory.cs
// Plain data for what the player and the stations own (the original's Item amount fields and Station objects):
//   ItemStack         an item and an amount: a cargo stack, a mounted item (secondaries: amount = ammo), a stock row
//   StationStock  one station's shop stock, ships for sale and bar agents, kept while the station is among the last 3
//                     visited
//                     (Status+0x19c stack, Status::addStationToStack 0xb6140)
//   StoredShip        a hull parked at the Kaamo Club (Station::addShip on the storage: index, race, mods; no equipment)

using System;
using System.Collections.Generic;

namespace GoF2Remake.Data
{
    [Serializable]
    public class ItemStack
    {
        public int item;
        public int amount;

        public ItemStack(int item, int amount) { this.item = item; this.amount = amount; }
        public ItemStack Clone() => new ItemStack(item, amount);
    }

    [Serializable]
    public class StationStock
    {
        public int station;
        public List<ItemStack> items = new List<ItemStack>();   // Generator::getItemBuyList, in item index order
        public List<int> ships = new List<int>();               // Generator::getShipBuyList
        public List<Agent> agents = new List<Agent>();  // Generator::createAgents (the bar's visitors)
    }

    [Serializable]
    public class StoredShip
    {
        public int ship;
        public int race;
        public List<int> mods = new List<int>();

        public StoredShip(int ship, int race, List<int> mods)
        {
            this.ship = ship;
            this.race = race;
            this.mods = mods != null ? new List<int>(mods) : new List<int>();
        }
    }
}
