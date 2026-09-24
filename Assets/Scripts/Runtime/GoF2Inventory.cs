// GoF2Inventory.cs
// Plain data for what the player and the stations own (the original's Item amount fields and Station objects):
//   GoF2Stack         an item and an amount: a cargo stack, a mounted item (secondaries: amount = ammo), a stock row
//   GoF2StationStock  one station's shop stock, ships for sale and bar agents, kept while the station is among the last 3
//                     visited
//                     (Status+0x19c stack, Status::addStationToStack 0xb6140)

using System;
using System.Collections.Generic;

namespace GoF2Remake.Data
{
    [Serializable]
    public class GoF2Stack
    {
        public int item;
        public int amount;

        public GoF2Stack(int item, int amount) { this.item = item; this.amount = amount; }
        public GoF2Stack Clone() => new GoF2Stack(item, amount);
    }

    [Serializable]
    public class GoF2StationStock
    {
        public int station;
        public List<GoF2Stack> items = new List<GoF2Stack>();   // Generator::getItemBuyList, in item index order
        public List<int> ships = new List<int>();               // Generator::getShipBuyList
        public List<GoF2Agent> agents = new List<GoF2Agent>();  // Generator::createAgents (the bar's visitors)
    }
}
