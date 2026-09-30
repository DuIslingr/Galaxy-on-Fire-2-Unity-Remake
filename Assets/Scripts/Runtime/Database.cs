// Database.cs
// Loads the JSON exported from the original game data (see README) and turns ship + equipment
// into FlightStats for ShipController.
//
// The JSON lives in Assets/Resources/GoF2Data/ and is parsed with Unity's built-in JsonUtility
// (no extra packages needed).   var db = Database.Load();  var betty = db.ShipByName("Betty");

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

        /// <summary>Original attribute pairs (Item+0x30), from item_attributes.json; see Reference/research/shop.md 2.4.</summary>
        [System.NonSerialized] public int[] attrKeys = new int[0], attrValues = new int[0];

        public bool HasAttr(int id) => System.Array.IndexOf(attrKeys, id) >= 0;
        public int Attr(int id, int fallback = 0)
        {
            int i = System.Array.IndexOf(attrKeys, id);
            return i >= 0 ? attrValues[i] : fallback;
        }

        /// <summary>Attribute 1: 0 primary, 1 secondary, 2 turret, 3 equipment, 4 commodity.</summary>
        public int TypeId => Attr(1, type switch { "primary" => 0, "secondary" => 1, "turret" => 2, "equipment" => 3, _ => 4 });

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

    /// <summary>Weapon mounts of one ship (weapons_hd.json). slotType 0 = primary, 1 = secondary, 2 = turret,
    /// 3 = engine exhaust points (not a turret, see weapons.md). position_engine is game space, ship-relative.</summary>
    [System.Serializable] public class WeaponMount { public int slotType; public int[] position_engine; public float[] turretAngles; }
    [System.Serializable] public class WeaponMountSet { public int ship; public string shipName; public List<WeaponMount> mounts; }

    /// <summary>One assembled prefab (assemblies.json): Resources/Assembled/{pack}/{category}/{name}.prefab.</summary>
    [System.Serializable] public class AssemblyData
    {
        public string name, pack, category, origin;
        public int root;
    }

    /// <summary>A Most Wanted criminal (wanted.json = FileRead::loadWanted, Wanted 0x14805c; wingmen_wanted.md 2.1).</summary>
    [System.Serializable] public class WantedData
    {
        public int index;
        public string name;
        public int board, race;
        public bool male;
        public int ship, weapon, hitpoints, loot, lootAmount, reward, requiredBounties, requiredMission, numWingmen;
        public int[] portraitParts;
    }

    public class Database
    {
        public List<ShipData> Ships = new List<ShipData>();
        public List<ItemData> Items = new List<ItemData>();
        public List<SystemData> Systems = new List<SystemData>();
        public List<StationData> Stations = new List<StationData>();
        public List<AssemblyData> Assemblies = new List<AssemblyData>();

        /// <summary>Globals::getShipGroup: a ship's assembled object, the main pack's "ship_NNN_*" first, else the add-ons'
        /// "v_ship_NNN_*" / "sn_ship_NNN_*" (ships 39-41 and 44+); the variant ending in 'raceName' when there is one.</summary>
        public AssemblyData ShipAssembly(int ship, string raceName = null)
        {
            string p = $"ship_{ship:000}_";
            bool Match(AssemblyData a, bool main) =>
                a.category == "ships" && (main ? a.name.StartsWith(p) : a.name.StartsWith("v_" + p) || a.name.StartsWith("sn_" + p));
            foreach (bool main in new[] { true, false })
            {
                if (raceName != null) { var r = Assemblies.Find(a => Match(a, main) && a.name.EndsWith(raceName)); if (r != null) return r; }
                var any = Assemblies.Find(a => Match(a, main));
                if (any != null) return any;
            }
            // Ship 14, the Terran battleship, has no ship_014_* group: Level::createShip builds battleship_terran (NpcShip).
            return ship == 14 ? AssemblyByName("battleship_terran") : null;
        }
        public List<WeaponMountSet> WeaponMounts = new List<WeaponMountSet>();
        public List<WantedData> Wanted = new List<WantedData>();

        [System.Serializable] class ItemAttributes { public int index; public int[] keys, values; }

        /// <summary>economy_default.json: the Default Economy's complete values of every item / ship that differs.</summary>
        [System.Serializable] class EconomyItem
        {
            public int index, techLevel, occurrence, minPrice, maxPrice, lowestPriceSystem, highestPriceSystem;
            public int[] keys, values;
            public List<StatEntry> statList;
            public List<BlueprintPart> blueprint;
        }
        [System.Serializable] class EconomyShip { public int index, armor, cargo, price, primary, secondary, turret, equipment, handling; }
        [System.Serializable] class EconomyFile { public List<EconomyItem> items; public List<EconomyShip> ships; }

        /// <summary>The item and ship tables this instance holds (Session.Economy when it was loaded).</summary>
        public Economy Economy { get; private set; } = Economy.Android;

        /// <summary>The macOS / Windows / iPhone tables (KiritoJPK's Default Economy items.bin / ships.bin) over the Android
        /// ones: prices, tech levels, occurrences, attributes (and so the stats) and blueprint recipes; ship prices and slots.</summary>
        void ApplyDefaultEconomy(string folder)
        {
            var file = Read<EconomyFile>(folder, "economy_default");
            if (file == null || file.items == null) return;
            foreach (var e in file.items)
            {
                var it = Item(e.index);
                if (it == null) continue;
                it.techLevel = e.techLevel; it.occurrence = e.occurrence; it.minPrice = e.minPrice; it.maxPrice = e.maxPrice;
                it.lowestPriceSystem = e.lowestPriceSystem; it.highestPriceSystem = e.highestPriceSystem;
                it.attrKeys = e.keys ?? new int[0]; it.attrValues = e.values ?? new int[0];
                it.statList = e.statList ?? new List<StatEntry>();
                it.blueprint = e.blueprint ?? new List<BlueprintPart>();
            }
            if (file.ships != null)
                foreach (var e in file.ships)
                {
                    var sh = Ship(e.index);
                    if (sh == null) continue;
                    sh.armor = e.armor; sh.cargo = e.cargo; sh.price = e.price;
                    sh.slots = new ShipSlots { primary = e.primary, secondary = e.secondary, turret = e.turret, equipment = e.equipment };
                    sh.handling = e.handling; sh.handlingMultiplier = e.handling / 100f;
                }
            Economy = Economy.Default;
        }

        public static Database Load(string resourceFolder = "GoF2Data")
        {
            var db = new Database
            {
                Ships = Read<List<ShipData>>(resourceFolder, "ships"),
                Items = Read<List<ItemData>>(resourceFolder, "items"),
                Systems = Read<List<SystemData>>(resourceFolder, "systems"),
                Stations = Read<List<StationData>>(resourceFolder, "stations"),
                Assemblies = ReadAssemblies(resourceFolder),
                WeaponMounts = Read<List<WeaponMountSet>>(resourceFolder, "weapons_hd"),
                Wanted = Read<List<WantedData>>(resourceFolder, "wanted"),
            };
            // item_attributes.json (Reference/tools/shop/build_item_attributes.py): items.json keeps them in a dictionary.
            foreach (var a in Read<List<ItemAttributes>>(resourceFolder, "item_attributes"))
            {
                var item = db.Items.Find(i => i.index == a.index);
                if (item != null && a.keys != null) { item.attrKeys = a.keys; item.attrValues = a.values; }
            }
            if (Session.Economy == Economy.Default) db.ApplyDefaultEconomy(resourceFolder);
            return db;
        }

        public ItemData Item(int index) => index >= 0 && index < Items.Count && Items[index].index == index ? Items[index] : Items.Find(i => i.index == index);
        public ShipData Ship(int index) => index >= 0 && index < Ships.Count && Ships[index].index == index ? Ships[index] : Ships.Find(s => s.index == index);

        [System.Serializable] class Wrapper<W> { public W list; }

        static T Read<T>(string folder, string file) where T : new()
        {
            var ta = Resources.Load<TextAsset>(folder + "/" + file);
            if (ta == null)
            {
                Debug.LogWarning("Database: missing Resources/" + folder + "/" + file + ".json");
                return new T();
            }
            return JsonUtility.FromJson<Wrapper<T>>("{\"list\":" + ta.text + "}").list;
        }

        [System.Serializable] class AssemblyFile { public List<AssemblyData> entries; }

        static List<AssemblyData> ReadAssemblies(string folder)
        {
            var ta = Resources.Load<TextAsset>(folder + "/assemblies");
            return ta != null ? JsonUtility.FromJson<AssemblyFile>(ta.text).entries : new List<AssemblyData>();
        }

        public AssemblyData AssemblyByName(string name) => Assemblies.FirstOrDefault(a => a.name == name);

        /// <summary>Mount positions of a slot type for a ship, in the order of Ship::getSlotPos.</summary>
        public List<WeaponMount> MountsOf(int shipIndex, int slotType)
        {
            var set = WeaponMounts.FirstOrDefault(m => m.ship == shipIndex);
            return set != null ? set.mounts.Where(m => m.slotType == slotType).ToList() : new List<WeaponMount>();
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
