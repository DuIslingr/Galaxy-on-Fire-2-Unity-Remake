// GoF2Database.cs
// Loads the JSON exported from the original game data (see README) and turns ship + equipment
// into FlightStats for GoF2ShipController.
//
// The JSON lives in Assets/GoF2/Resources/GoF2Data/ and is parsed with Unity's built-in JsonUtility
// (no extra packages needed).   var db = GoF2Database.Load();  var betty = db.ShipByName("Betty");

using System.Collections.Generic;
using System.Linq;
using UnityEngine;
using GoF2Remake.Flight;

namespace GoF2Remake.Data
{
    [System.Serializable] public class ShipSlots { public int primary, secondary, turret, equipment; }

    [System.Serializable] public class ShipData
    {
        public int index;
        public string name, description;
        public int armor, cargo, price;
        public ShipSlots slots;
        public float handling;            // UI value, e.g. 120
        public float handlingMultiplier;  // handling / 100
    }

    [System.Serializable] public class StatEntry { public string key; public int value; }

    [System.Serializable] public class BlueprintPart { public int item; public string name; public int amount; }

    [System.Serializable] public class ItemData
    {
        public int index;
        public string name, description;
        public string type;       // primary | secondary | turret | equipment | commodity
        public string category;   // Laser, Blaster, Shield, Booster, ...
        public int categoryId;
        public int techLevel, occurrence, minPrice, maxPrice, lowestPriceSystem, highestPriceSystem;
        public List<StatEntry> statList = new List<StatEntry>();   // e.g. damage, range, boostSpeed ...
        public List<BlueprintPart> blueprint = new List<BlueprintPart>();

        public int Stat(string key, int fallback = 0)
        {
            if (statList != null) foreach (var s in statList) if (s.key == key) return s.value;
            return fallback;
        }
    }

    [System.Serializable] public class MapPos { public int x, y, z; }

    [System.Serializable] public class SystemData
    {
        public int index;
        public string name;
        public int securityLevel;
        public bool initiallyVisible;
        public string race;
        public int raceId;
        public MapPos mapPosition;
        public int jumpgateStation;
        public int textureIndex;
        public List<int> stations, jumpRoutesTo, unknownTriple, forbiddenGoodsOrUnknown;
    }

    [System.Serializable] public class StationData
    {
        public int index;
        public string name;
        public int system;
        public string systemName;
        public int techLevel;
        public int textureIndex;
    }

    public class GoF2Database
    {
        public List<ShipData> Ships = new List<ShipData>();
        public List<ItemData> Items = new List<ItemData>();
        public List<SystemData> Systems = new List<SystemData>();
        public List<StationData> Stations = new List<StationData>();

        public static GoF2Database Load(string resourceFolder = "GoF2Data")
        {
            return new GoF2Database
            {
                Ships = Read<List<ShipData>>(resourceFolder, "ships"),
                Items = Read<List<ItemData>>(resourceFolder, "items"),
                Systems = Read<List<SystemData>>(resourceFolder, "systems"),
                Stations = Read<List<StationData>>(resourceFolder, "stations"),
            };
        }

        [System.Serializable] class Wrapper<W> { public W list; }

        static T Read<T>(string folder, string file) where T : new()
        {
            var ta = Resources.Load<TextAsset>(folder + "/" + file);
            if (ta == null)
            {
                Debug.LogWarning("GoF2Database: missing Resources/" + folder + "/" + file + ".json");
                return new T();
            }
            return JsonUtility.FromJson<Wrapper<T>>("{\"list\":" + ta.text + "}").list;
        }

        public ShipData ShipByName(string name) => Ships.FirstOrDefault(s => s.name == name);
        public ItemData ItemByName(string name) => Items.FirstOrDefault(i => i.name == name);
        public IEnumerable<StationData> StationsIn(int systemIndex) => Stations.Where(s => s.system == systemIndex);

        /// <summary>
        /// Builds flight stats the same way the original combines Ship + installed equipment
        /// (Ship::refreshValue / PlayerEgo ctor): booster = category "Booster", agility = "Steering nozzle".
        /// </summary>
        public static FlightStats BuildFlightStats(ShipData ship, IEnumerable<ItemData> equipment, int handlingUpgrades = 0)
        {
            var fs = new FlightStats { handling = ship.handling, handlingUpgrades = handlingUpgrades };
            foreach (var item in equipment ?? Enumerable.Empty<ItemData>())
            {
                switch (item.categoryId)
                {
                    case 14: // Booster
                        fs.boostSpeed = item.Stat("boostSpeed");
                        fs.boostDurationMs = item.Stat("boostDurationMs");
                        fs.boostRechargeMs = item.Stat("boostRechargeMs");
                        break;
                    case 16: // Steering nozzle
                        fs.agility = item.Stat("agility");
                        break;
                }
            }
            return fs;
        }
    }
}
