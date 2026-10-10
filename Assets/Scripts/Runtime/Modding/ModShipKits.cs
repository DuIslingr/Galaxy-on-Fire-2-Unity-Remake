// ModShipKits.cs
// Remake mods: customizable ships, assembled from parts the player picks in the hangar (EVERSPACE 2's ship modules).
// A mod's shipkits.json lists kits, each a set of parts by slot:
//   [ { "id": "medium", "name": "Medium hulls",
//       "slots": ["base", "cockpit", "body", "rear", "wings"]   (the build's slots, in assembly order; default: the parts')
//       "scale": 1.0,            Unity metres per model unit (the parts share one origin, so one scale for every build)
//       "yaw": 0,                degrees about Unity y when the parts' nose doesn't face +Z
//       "materials": [ ... ],    like a ship's: applied to every part's renderers it names (ModMaterials.FromSpec)
//       "parts": [
//         { "id": "nemesis", "slot": "wings", "name": "Nemesis" | { "en": ..., "de": ... }, "model": "parts/wings_009.glb",
//           "types": ["sentinel"],   which ship types may fit it (the ships' "kitType"; none = every type)
//           "tiers": ["parts/wings_009_t1.glb", ...],   extension meshes shown at build tier 1, 2, ... (none = no extension)
//           "mounts": [ { "slotType": 0, "position_engine": [x, y, z] }, ... ],   the part's weapon / turret / exhaust mounts,
//           "tierMounts": [ [ ... ], ... ],   and its tier extensions' (like a ship's "mounts", ship-relative game units)
//           "stats": { "armor": 10, "cargo": -5, "handling": 8 (%), "equipment": 1 (slots), "topSpeed", "turnRate",
//                      "acceleration", "strafeSpeed" (% flight bonuses, both flight styles) },
//           "slots": { "primary": 2, "secondary": 1, "turret": 1 } }
//     A build adds up its parts' stats (the hull, cargo and handling in % of the ship's own) and, per slot type, its parts'
//     slots (the ship's own count when none of its parts gives that type): BuildEffect; the hull (Shop.BaseHp, PlayerHealth,
//     StationLevel), cargo (Shop.MaxLoad), slots (Hangar.SlotCount / FitToSlots) and flight (Database.BuildFlightStats) of the
//     player's ship follow its build. The tier is cosmetic (its extensions' looks and mounts).
//     A build's mounts of each slot type are its parts' (and its tier extensions'), or the ship's own "mounts" of that type
//     when no part has any (MountsFor; Database.MountsOf: the player's build for the player's ship, else the default build).
//       ] } ]
//       "palettes": { "main": [ { "id": "white", "name": "Snow White", "color": "#F9F9F9", "metallic": 0, "smoothness": 0.5 }, ... ] },
//       "colorSlots": [ { "id": "hull1", "name": "Main colour", "palette": "main", "default": "white",
//                         "targets": [ { "material": "Paint1", "property": "base" | "emission" | "engine", "intensity": 1 } ] } ],
//       "presets": [ { "id": "scheme_4", "name": "Scheme 4", "colors": { "hull1": "#699CBF/1/0.6", "lights": "white", ... } } ]
//     The player picks a colour per slot from its palette (or a preset sets them all); each target recolours the materials whose
//     name contains 'material' (the model's own, or a kit "materials" entry's 'material' filter): base = the base colour (x
//     intensity; a value's metallic / smoothness too), emission = the emission colour x intensity, engine = the engine glow.
//     A colour value: a palette entry's id, or "#RRGGBB" with an optional "/metallic/smoothness".
//       "hardpoints": { "turret": "...glb", "weapons": [ { "slot", "model", "items", "categories" } ] }: the weapons' and the
//     turret's models on the build's mounts (ModHardpoints).
// ships.json: a new ship with "kit": "<kit id>" (this mod's) or "mod_id:kit_id" instead of "model", "kitType": "sentinel",
// and "build": { "wings": "nemesis", "body": "body_a", ..., "tier": 1 } (its default: what the dealers sell and NPCs fly;
// a slot left out takes the first part the type may fit). The player's build of each kit ship is Session.ShipBuilds (by the
// ship's key, saved), shown by PlayerHull.Assembly as the variant assembly "ship_NNN_mod#<build>" (ModShips.Template
// assembles it from the loaded parts the first time). Builds are text: "body=body_a;rear=rear_1;wings=nemesis;tier=1".

using System;
using System.Collections.Generic;
using System.Linq;
using GoF2Remake.Data;
using Newtonsoft.Json.Linq;
using UnityEngine;

namespace GoF2Remake.Modding
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class ModShipKits
    {
        public const string File = "shipkits.json";

        static readonly HashSet<string> KitFields = new HashSet<string>(StringComparer.OrdinalIgnoreCase)
            { "id", "name", "slots", "scale", "yaw", "materials", "parts", "palettes", "colorSlots", "presets", "hardpoints" };
        static readonly HashSet<string> PartFields = new HashSet<string>(StringComparer.OrdinalIgnoreCase)
            { "id", "slot", "name", "model", "types", "tiers", "mounts", "tierMounts", "stats", "slots" };

        public sealed class Part
        {
            public string id, slot, model;
            public Dictionary<string, string> name;
            public List<string> types = new List<string>(), tiers = new List<string>();
            public List<WeaponMount> mounts = new List<WeaponMount>();
            public List<List<WeaponMount>> tierMounts = new List<List<WeaponMount>>();
            public float armor, cargo, handling, topSpeed, turnRate, acceleration, strafeSpeed;   // % (stats)
            public int equipment;                                                                  // slots (stats)
            public int primarySlots = -1, secondarySlots = -1, turretSlots = -1;                  // -1 = not given
            public string Name => ModManifest.Pick(name) ?? id;
            public bool Allows(string type) => types.Count == 0 || types.Any(t => string.Equals(t, type, StringComparison.OrdinalIgnoreCase));
        }

        /// <summary>A palette entry: a colour with an optional finish (metallic / smoothness, -1 = the material's own).</summary>
        public sealed class ColorChoice
        {
            public string id;
            public Dictionary<string, string> name;
            public Color color = Color.white;
            public float metallic = -1f, smoothness = -1f;
            public string Name => ModManifest.Pick(name) ?? id;
        }

        public sealed class ColorTarget
        {
            public string material, property = "base";
            public float intensity = 1f;
        }

        public sealed class ColorSlot
        {
            public string id, palette, defaultValue;
            public Dictionary<string, string> name;
            public List<ColorTarget> targets = new List<ColorTarget>();
            public string Name => ModManifest.Pick(name) ?? id;
        }

        public sealed class Preset
        {
            public string id;
            public Dictionary<string, string> name;
            public Dictionary<string, string> colors = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase);
            public string Name => ModManifest.Pick(name) ?? id;
        }

        public sealed class Kit
        {
            public readonly Dictionary<string, List<ColorChoice>> palettes = new Dictionary<string, List<ColorChoice>>(StringComparer.OrdinalIgnoreCase);
            public readonly List<ColorSlot> colorSlots = new List<ColorSlot>();
            public readonly List<Preset> presets = new List<Preset>();

            public List<ColorChoice> PaletteOf(ColorSlot slot) => slot != null && slot.palette != null && palettes.TryGetValue(slot.palette, out var l) ? l : new List<ColorChoice>();

            public ModInfo mod;
            public string localId;
            public Dictionary<string, string> name;
            public List<string> slots = new List<string>();
            public float scale = 1f, yaw;
            public List<CustomShipMaterial> materials = new List<CustomShipMaterial>();
            public List<Part> parts = new List<Part>();
            public ModHardpoints.Set hardpoints;   // the weapon / turret models (ModHardpoints), null = none
            public string Key => mod.Id + ":" + localId;
            public string Name => ModManifest.Pick(name) ?? localId;
            public int MaxTier => parts.Count == 0 ? 0 : parts.Max(p => p.tiers.Count);

            public Part Find(string id) => parts.Find(p => string.Equals(p.id, id, StringComparison.OrdinalIgnoreCase));

            /// <summary>The parts of a slot a ship type may fit, in the file's order.</summary>
            public List<Part> PartsFor(string slot, string type) =>
                parts.Where(p => string.Equals(p.slot, slot, StringComparison.OrdinalIgnoreCase) && p.Allows(type)).ToList();
        }

        static readonly List<Kit> kits = new List<Kit>();
        static int parsedRevision = -1;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics() { kits.Clear(); parsedRevision = -1; }

        /// <summary>The kits of the mods that are on.</summary>
        public static List<Kit> All()
        {
            if (parsedRevision == ModManager.Revision) return kits;
            parsedRevision = ModManager.Revision;
            kits.Clear();
            foreach (var mod in ModManager.Active)
            {
                try { Read(mod, kits); }
                catch (ModJsonException e) { Warn(mod, e.Message); }
            }
            return kits;
        }

        /// <summary>A kit by "mod_id:kit_id", or by its kit id alone within 'mod' (a ship's own mod).</summary>
        public static Kit Find(string key, ModInfo mod = null)
        {
            if (string.IsNullOrEmpty(key)) return null;
            int colon = key.IndexOf(':');
            foreach (var k in All())
            {
                if (colon > 0 ? string.Equals(k.Key, key, StringComparison.OrdinalIgnoreCase)
                              : mod != null && k.mod == mod && string.Equals(k.localId, key, StringComparison.OrdinalIgnoreCase))
                    return k;
            }
            return null;
        }

        static void Read(ModInfo mod, List<Kit> into)
        {
            if (!(ModJson.Read(mod.Source, File) is JToken token)) return;
            if (!(token is JArray list)) throw new ModJsonException($"{File}: must be a list [ {{ ... }}, ... ]");
            var ids = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
            foreach (var t in list)
            {
                string where = ModJson.Where(t, File);
                if (!(t is JObject o)) throw new ModJsonException($"{where}: each kit must be an object {{ ... }}");
                foreach (var prop in o.Properties())
                    if (!KitFields.Contains(prop.Name)) Warn(mod, $"{ModJson.Where(prop, File)}: unknown field \"{prop.Name}\" (ignored)");
                var k = new Kit
                {
                    mod = mod, localId = ModJson.Str(o, "id"), name = ModJson.Text(o, "name"),
                    scale = ModJson.Float(o, "scale", 1f, File), yaw = ModJson.Float(o, "yaw", 0f, File),
                };
                if (string.IsNullOrEmpty(k.localId) || !ModManifest.ValidId(k.localId))
                    throw new ModJsonException($"{where}: \"id\" is missing or uses more than a-z, 0-9, _ and -");
                if (!ids.Add(k.localId)) throw new ModJsonException($"{where}: the id \"{k.localId}\" is used twice");
                if (k.scale <= 0f) throw new ModJsonException($"{where}: \"scale\" must be above 0");
                if (ModJson.Get(o, "materials") is JToken mt)
                {
                    try { k.materials = JsonUtility.FromJson<MaterialList>("{\"list\":" + mt.ToString() + "}").list ?? new List<CustomShipMaterial>(); }
                    catch (Exception e) { throw new ModJsonException($"{where}: \"materials\": {e.Message}"); }
                }
                if (!(ModJson.Get(o, "parts") is JArray parts) || parts.Count == 0)
                    throw new ModJsonException($"{where}: \"parts\" must be a list of the kit's parts");
                var partIds = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
                foreach (var pt in parts)
                {
                    string pwhere = ModJson.Where(pt, File);
                    if (!(pt is JObject po)) throw new ModJsonException($"{pwhere}: each part must be an object {{ ... }}");
                    foreach (var prop in po.Properties())
                        if (!PartFields.Contains(prop.Name)) Warn(mod, $"{ModJson.Where(prop, File)}: unknown field \"{prop.Name}\" (ignored)");
                    var p = new Part
                    {
                        id = ModJson.Str(po, "id"), slot = ModJson.Str(po, "slot"), model = ModJson.Str(po, "model"), name = ModJson.Text(po, "name"),
                        types = ModJson.Strings(po, "types") ?? new List<string>(), tiers = ModJson.Strings(po, "tiers") ?? new List<string>(),
                    };
                    if (string.IsNullOrEmpty(p.id) || !ModManifest.ValidId(p.id))
                        throw new ModJsonException($"{pwhere}: \"id\" is missing or uses more than a-z, 0-9, _ and -");
                    if (!partIds.Add(p.id)) throw new ModJsonException($"{pwhere}: the part id \"{p.id}\" is used twice in this kit");
                    if (string.IsNullOrEmpty(p.slot) || !ModManifest.ValidId(p.slot)) throw new ModJsonException($"{pwhere}: \"slot\" is missing (e.g. \"wings\")");
                    if (string.IsNullOrEmpty(p.model)) throw new ModJsonException($"{pwhere}: \"model\" is missing (the part's glTF / GLB)");
                    if (!mod.Source.Exists(p.model)) throw new ModJsonException($"{pwhere}: the model \"{p.model}\" isn't in the mod");
                    foreach (var tier in p.tiers)
                        if (!mod.Source.Exists(tier)) throw new ModJsonException($"{pwhere}: the tier model \"{tier}\" isn't in the mod");
                    p.mounts = ReadMounts(ModJson.Get(po, "mounts"), pwhere);
                    if (ModJson.Get(po, "stats") is JObject st)
                    {
                        p.armor = ModJson.Float(st, "armor", 0f, File); p.cargo = ModJson.Float(st, "cargo", 0f, File);
                        p.handling = ModJson.Float(st, "handling", 0f, File); p.equipment = ModJson.Int(st, "equipment", 0, File);
                        p.topSpeed = ModJson.Float(st, "topSpeed", 0f, File); p.turnRate = ModJson.Float(st, "turnRate", 0f, File);
                        p.acceleration = ModJson.Float(st, "acceleration", 0f, File); p.strafeSpeed = ModJson.Float(st, "strafeSpeed", 0f, File);
                    }
                    if (ModJson.Get(po, "slots") is JObject sl)
                    {
                        p.primarySlots = ModJson.Int(sl, "primary", -1, File); p.secondarySlots = ModJson.Int(sl, "secondary", -1, File);
                        p.turretSlots = ModJson.Int(sl, "turret", -1, File);
                    }
                    if (ModJson.Get(po, "tierMounts") is JArray tm)
                        foreach (var t2 in tm) p.tierMounts.Add(ReadMounts(t2, pwhere));
                    k.parts.Add(p);
                }
                var slots = ModJson.Strings(o, "slots");
                k.slots = slots != null && slots.Count > 0 ? slots : k.parts.Select(p => p.slot).Distinct(StringComparer.OrdinalIgnoreCase).ToList();
                foreach (var p in k.parts)
                    if (!k.slots.Contains(p.slot, StringComparer.OrdinalIgnoreCase))
                        throw new ModJsonException($"{where}: the part \"{p.id}\"'s slot \"{p.slot}\" isn't in \"slots\"");
                ReadColors(o, k, where);
                k.hardpoints = ModHardpoints.Read(o, mod, File, where);
                into.Add(k);
            }
        }

        [Serializable] sealed class MaterialList { public List<CustomShipMaterial> list; }

        static List<WeaponMount> ReadMounts(JToken t, string where)
        {
            var list = new List<WeaponMount>();
            if (t == null) return list;
            if (!(t is JArray arr)) throw new ModJsonException($"{where}: \"mounts\" must be a list of mounts");
            foreach (var e in arr)
            {
                if (!(e is JObject)) continue;
                try { list.Add(JsonUtility.FromJson<WeaponMount>(e.ToString())); }
                catch (Exception ex) { throw new ModJsonException($"{where}: a mount: {ex.Message}"); }
            }
            return list;
        }

        /// <summary>A build's mounts: for each slot type its parts' mounts (base and tier extension, in the kit's slot order),
        /// else the ship's own of that type.</summary>
        public static List<WeaponMount> MountsFor(CustomShipData c, Kit kit, Build build)
        {
            var fromParts = new List<WeaponMount>();
            foreach (string slot in kit.slots)
            {
                if (!build.parts.TryGetValue(slot, out var id)) continue;
                var part = kit.Find(id);
                if (part == null) continue;
                fromParts.AddRange(part.mounts);
                if (build.tier > 0 && build.tier <= part.tierMounts.Count) fromParts.AddRange(part.tierMounts[build.tier - 1]);
            }
            var all = new List<WeaponMount>();
            foreach (int type in new[] { 0, 1, 2, 3 })
            {
                var own = fromParts.Where(m => m.slotType == type).ToList();
                all.AddRange(own.Count > 0 ? own : (c.mounts ?? new List<WeaponMount>()).Where(m => m.slotType == type));
            }
            return all;
        }

        /// <summary>What a build does to its ship: the parts' stats added up, and the slots per type (-1 = the ship's own).</summary>
        public sealed class Effect
        {
            public float armor, cargo, handling;   // %
            public int equipment;
            public int primary = -1, secondary = -1, turret = -1;
            public readonly Flight.FlightBonus flight = new Flight.FlightBonus();
        }

        public static Effect EffectOf(Kit kit, Build build)
        {
            var e = new Effect();
            foreach (string slot in kit.slots)
            {
                if (!build.parts.TryGetValue(slot, out var id)) continue;
                var p = kit.Find(id);
                if (p == null) continue;
                e.armor += p.armor; e.cargo += p.cargo; e.handling += p.handling; e.equipment += p.equipment;
                e.flight.topSpeed += p.topSpeed; e.flight.turnRate += p.turnRate; e.flight.acceleration += p.acceleration; e.flight.strafeSpeed += p.strafeSpeed;
                if (p.primarySlots >= 0) e.primary = Math.Max(0, e.primary) + p.primarySlots;
                if (p.secondarySlots >= 0) e.secondary = Math.Max(0, e.secondary) + p.secondarySlots;
                if (p.turretSlots >= 0) e.turret = Math.Max(0, e.turret) + p.turretSlots;
            }
            return e;
        }

        /// <summary>The build effect of the player's ship (null: not a kit ship); 'ship' another than the player's: its default build.</summary>
        public static Effect BuildEffect(int ship)
        {
            var c = KitShip(ship);
            var kit = KitOf(c);
            if (kit == null) return null;
            return EffectOf(kit, ship == Session.ShipIndex ? PlayerBuild(ship) : DefaultBuild(c, kit));
        }

        static int Pct(int value, float pct) => Mathf.Max(1, Mathf.RoundToInt(value * (1f + pct / 100f)));

        /// <summary>A ship's hull with its build ('s' null: 'fallback').</summary>
        public static int Armor(ShipData s, int fallback) => s == null ? fallback : BuildEffect(s.index) is Effect e ? Pct(s.armor, e.armor) : s.armor;
        public static int Cargo(ShipData s, int fallback) => s == null ? fallback : BuildEffect(s.index) is Effect e ? Mathf.Max(0, Mathf.RoundToInt(s.cargo * (1f + e.cargo / 100f))) : s.cargo;
        public static float Handling(ShipData s) => BuildEffect(s.index) is Effect e ? s.handling * (1f + e.handling / 100f) : s.handling;

        /// <summary>A ship's slots with its build (a copy; the ship's own without a build).</summary>
        public static ShipSlots Slots(ShipData s)
        {
            var b = s?.slots;
            if (b == null) return null;
            if (!(BuildEffect(s.index) is Effect e)) return b;
            return new ShipSlots
            {
                primary = e.primary >= 0 ? e.primary : b.primary, secondary = e.secondary >= 0 ? e.secondary : b.secondary,
                turret = e.turret >= 0 ? e.turret : b.turret, equipment = Mathf.Max(0, b.equipment + e.equipment),
            };
        }

        /// <summary>The ship as its build makes it (a copy with the hull, cargo, handling and slots adjusted; the ship itself
        /// when it isn't a kit ship): for the stat rows (ItemInfo, ItemInfoWindow).</summary>
        public static ShipData Effective(ShipData s)
        {
            if (s == null || BuildEffect(s.index) == null) return s;
            float handling = Handling(s);
            return new ShipData { index = s.index, name = s.name, description = s.description, price = s.price, armor = Armor(s, s.armor),
                                  cargo = Cargo(s, s.cargo), handling = handling, handlingMultiplier = handling / 100f, slots = Slots(s) };
        }

        /// <summary>Database.MountsOf for a kit ship: the player's build for the player's ship, else its default build; null:
        /// not a kit ship.</summary>
        /// <summary>The mounts of a type a model of 'ship' in 'build' shows (another player's build, a hangar ship's): a kit
        /// ship's for that build (normalized; null = its default build), any other ship's Database.MountsOf.</summary>
        public static List<WeaponMount> MountsShown(Database db, int ship, int slotType, Build build)
        {
            var c = KitShip(ship);
            var kit = KitOf(c);
            if (kit == null) return db.MountsOf(ship, slotType);
            var b = build != null ? Normalize(kit, c.kitType, build, DefaultBuild(c, kit)) : DefaultBuild(c, kit);
            return MountsFor(c, kit, b).Where(m => m.slotType == slotType).ToList();
        }

        /// <summary>The build an assembly shows: "ship_NNN_mod#<build>" (VariantAssembly) -> that build, else null.</summary>
        public static Build BuildOfAssembly(string assembly)
        {
            int hash = assembly?.IndexOf(VariantSeparator) ?? -1;
            return hash > 0 ? Build.Parse(assembly.Substring(hash + 1)) : null;
        }

        /// <summary>Another player's build of their kit ship from its text (NetPlayer.BuildText), normalized against what this
        /// game's kit has (unknown parts: the default build's); the default build for an empty text; null = no kit ship.</summary>
        public static Build RemoteBuild(int ship, string text)
        {
            var c = KitShip(ship);
            var kit = KitOf(c);
            return kit == null ? null : Normalize(kit, c.kitType, string.IsNullOrEmpty(text) ? null : Build.Parse(text), DefaultBuild(c, kit));
        }

        public static List<WeaponMount> BuildMounts(int ship, int slotType)
        {
            var c = KitShip(ship);
            var kit = KitOf(c);
            if (kit == null) return null;
            var build = ship == Session.ShipIndex ? PlayerBuild(ship) : DefaultBuild(c, kit);
            return MountsFor(c, kit, build).Where(m => m.slotType == slotType).ToList();
        }

        static void ReadColors(JObject o, Kit k, string where)
        {
            if (ModJson.Get(o, "palettes") is JToken pt)
            {
                if (!(pt is JObject po)) throw new ModJsonException($"{where}: \"palettes\" must be an object {{ \"main\": [ ... ] }}");
                foreach (var prop in po.Properties())
                {
                    if (!(prop.Value is JArray arr)) throw new ModJsonException($"{ModJson.Where(prop, File)}: a palette must be a list of colours");
                    var list = new List<ColorChoice>();
                    foreach (var e in arr)
                    {
                        if (!(e is JObject eo)) continue;
                        var c = new ColorChoice
                        {
                            id = ModJson.Str(eo, "id"), name = ModJson.Text(eo, "name"),
                            metallic = ModJson.Float(eo, "metallic", -1f, File), smoothness = ModJson.Float(eo, "smoothness", -1f, File),
                        };
                        if (string.IsNullOrEmpty(c.id)) throw new ModJsonException($"{ModJson.Where(e, File)}: a palette colour needs an \"id\"");
                        if (!TryHex(ModJson.Str(eo, "color"), out c.color)) throw new ModJsonException($"{ModJson.Where(e, File)}: \"color\" must be \"#RRGGBB\"");
                        list.Add(c);
                    }
                    k.palettes[prop.Name] = list;
                }
            }
            if (ModJson.Get(o, "colorSlots") is JArray slots)
                foreach (var t in slots)
                {
                    if (!(t is JObject so)) continue;
                    var slot = new ColorSlot { id = ModJson.Str(so, "id"), palette = ModJson.Str(so, "palette"), defaultValue = ModJson.Str(so, "default"), name = ModJson.Text(so, "name") };
                    if (string.IsNullOrEmpty(slot.id) || !ModManifest.ValidId(slot.id)) throw new ModJsonException($"{ModJson.Where(t, File)}: a colour slot needs an \"id\" (a-z, 0-9, _ and -)");
                    if (slot.palette == null || !k.palettes.ContainsKey(slot.palette)) throw new ModJsonException($"{ModJson.Where(t, File)}: \"palette\" \"{slot.palette}\" isn't in \"palettes\"");
                    if (ModJson.Get(so, "targets") is JArray ta)
                        foreach (var x in ta)
                            if (x is JObject xo)
                                slot.targets.Add(new ColorTarget
                                {
                                    material = ModJson.Str(xo, "material") ?? "", property = (ModJson.Str(xo, "property") ?? "base").ToLowerInvariant(),
                                    intensity = ModJson.Float(xo, "intensity", 1f, File),
                                });
                    k.colorSlots.Add(slot);
                }
            if (ModJson.Get(o, "presets") is JArray presets)
                foreach (var t in presets)
                {
                    if (!(t is JObject pr)) continue;
                    var preset = new Preset { id = ModJson.Str(pr, "id"), name = ModJson.Text(pr, "name") };
                    if (string.IsNullOrEmpty(preset.id)) throw new ModJsonException($"{ModJson.Where(t, File)}: a preset needs an \"id\"");
                    if (ModJson.Get(pr, "colors") is JObject co)
                        foreach (var prop in co.Properties()) if (prop.Value.Type == JTokenType.String) preset.colors[prop.Name] = (string)prop.Value;
                    k.presets.Add(preset);
                }
        }

        static bool TryHex(string text, out Color c)
        {
            c = Color.white;
            if (string.IsNullOrEmpty(text)) return false;
            return ColorUtility.TryParseHtmlString(text.StartsWith("#") ? text : "#" + text, out c);
        }

        /// <summary>A colour value: a palette id of the slot's palette, or "#RRGGBB[/metallic/smoothness]".</summary>
        public static bool Resolve(Kit kit, ColorSlot slot, string value, out Color color, out float metallic, out float smoothness)
        {
            color = Color.white; metallic = smoothness = -1f;
            if (string.IsNullOrEmpty(value)) return false;
            if (value.StartsWith("#"))
            {
                var bits = value.Split('/');
                if (!TryHex(bits[0], out color)) return false;
                if (bits.Length > 1) float.TryParse(bits[1], System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out metallic);
                if (bits.Length > 2) float.TryParse(bits[2], System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out smoothness);
                return true;
            }
            var choice = kit.PaletteOf(slot).Find(c => string.Equals(c.id, value, StringComparison.OrdinalIgnoreCase));
            if (choice == null) return false;
            color = choice.color; metallic = choice.metallic; smoothness = choice.smoothness;
            return true;
        }

        static void Warn(ModInfo mod, string message)
        {
            if (!mod.Warnings.Contains(message)) mod.Warnings.Add(message);
            Debug.LogWarning($"Mods: {mod.Id}: {message}");
        }

        // ---- builds ----------------------------------------------------------------------------------------------------

        /// <summary>One ship's choice of parts (slot -> part id) and its tier (which extension meshes show).</summary>
        public sealed class Build
        {
            public readonly SortedDictionary<string, string> parts = new SortedDictionary<string, string>(StringComparer.OrdinalIgnoreCase);
            /// <summary>A colour value per colour slot (written "color.slot=value").</summary>
            public readonly SortedDictionary<string, string> colors = new SortedDictionary<string, string>(StringComparer.OrdinalIgnoreCase);
            public int tier;
            const string ColorPrefix = "color.";

            public static Build Parse(string text)
            {
                var b = new Build();
                if (string.IsNullOrEmpty(text)) return b;
                foreach (var pair in text.Split(';'))
                {
                    int eq = pair.IndexOf('=');
                    if (eq <= 0) continue;
                    string k = pair.Substring(0, eq).Trim(), v = pair.Substring(eq + 1).Trim();
                    if (k == "tier") int.TryParse(v, out b.tier);
                    else if (k.StartsWith(ColorPrefix)) { if (v.Length > 0) b.colors[k.Substring(ColorPrefix.Length)] = v; }
                    else if (v.Length > 0) b.parts[k] = v;
                }
                return b;
            }

            /// <summary>ships.json's "build" object.</summary>
            public static Build FromJson(JObject o)
            {
                var b = new Build();
                if (o == null) return b;
                foreach (var prop in o.Properties())
                {
                    if (string.Equals(prop.Name, "tier", StringComparison.OrdinalIgnoreCase)) { b.tier = prop.Value.Type == JTokenType.Integer ? (int)prop.Value : 0; continue; }
                    if (string.Equals(prop.Name, "colors", StringComparison.OrdinalIgnoreCase) && prop.Value is JObject co)
                    {
                        foreach (var c in co.Properties()) if (c.Value.Type == JTokenType.String) b.colors[c.Name] = (string)c.Value;
                        continue;
                    }
                    if (prop.Value.Type == JTokenType.String) b.parts[prop.Name] = (string)prop.Value;
                }
                return b;
            }

            public Build Clone()
            {
                var b = new Build { tier = tier };
                foreach (var kv in parts) b.parts[kv.Key] = kv.Value;
                foreach (var kv in colors) b.colors[kv.Key] = kv.Value;
                return b;
            }

            public override string ToString() => string.Join(";", parts.Select(kv => kv.Key + "=" + kv.Value)
                .Concat(colors.Select(kv => ColorPrefix + kv.Key + "=" + kv.Value)).Append("tier=" + tier));
        }

        /// <summary>'b' made valid for this kit and ship type: every slot one part the type may fit ('fallback''s part, else the
        /// slot's first), the tier within what the kit has.</summary>
        public static Build Normalize(Kit kit, string type, Build b, Build fallback = null)
        {
            var n = new Build { tier = Mathf.Clamp(b?.tier ?? fallback?.tier ?? 0, 0, kit.MaxTier) };
            foreach (string slot in kit.slots)
            {
                var allowed = kit.PartsFor(slot, type);
                if (allowed.Count == 0) continue;
                Part pick = null;
                if (b != null && b.parts.TryGetValue(slot, out var id)) pick = allowed.Find(p => string.Equals(p.id, id, StringComparison.OrdinalIgnoreCase));
                if (pick == null && fallback != null && fallback.parts.TryGetValue(slot, out var fid)) pick = allowed.Find(p => string.Equals(p.id, fid, StringComparison.OrdinalIgnoreCase));
                n.parts[slot] = (pick ?? allowed[0]).id;
            }
            foreach (var cs in kit.colorSlots)
            {
                string v = null;
                if (b != null && b.colors.TryGetValue(cs.id, out var bv) && Resolve(kit, cs, bv, out _, out _, out _)) v = bv;
                else if (fallback != null && fallback.colors.TryGetValue(cs.id, out var fv) && Resolve(kit, cs, fv, out _, out _, out _)) v = fv;
                else if (Resolve(kit, cs, cs.defaultValue, out _, out _, out _)) v = cs.defaultValue;
                else if (kit.PaletteOf(cs).Count > 0) v = kit.PaletteOf(cs)[0].id;
                if (v != null) n.colors[cs.id] = v;
            }
            return n;
        }

        // ---- the ships -------------------------------------------------------------------------------------------------

        /// <summary>A kit ship's kit (null: not one, or its kit's mod is off).</summary>
        public static Kit KitOf(CustomShipData c) => c == null || string.IsNullOrEmpty(c.kit) ? null : Find(c.kit);   // ModContent made it "mod_id:kit_id"

        /// <summary>The ship number's kit ship data (null: not a kit ship).</summary>
        public static CustomShipData KitShip(int ship) => Database.Shared.Ship(ship) is CustomShipData c && !string.IsNullOrEmpty(c.kit) ? c : null;

        /// <summary>A kit ship's default build (the dealers', the NPCs').</summary>
        public static Build DefaultBuild(CustomShipData c, Kit kit) => Normalize(kit, c.kitType, Build.Parse(c.defaultBuild));

        /// <summary>The player's build of a kit ship (Session.ShipBuilds by its key; else the default), valid for the kit.</summary>
        public static Build PlayerBuild(int ship)
        {
            var c = KitShip(ship);
            var kit = KitOf(c);
            if (kit == null) return null;
            string key = ModContent.ShipKey(ship);
            var saved = key != null && Session.ShipBuilds.TryGetValue(key, out var text) ? Build.Parse(text) : null;
            return Normalize(kit, c.kitType, saved, DefaultBuild(c, kit));
        }

        /// <summary>The player's new build of a kit ship (the hangar's Customize screen).</summary>
        public static void SetPlayerBuild(int ship, Build b)
        {
            string key = ModContent.ShipKey(ship);
            if (key == null || b == null) return;
            Session.ShipBuilds[key] = b.ToString();
        }

        public const char VariantSeparator = '#';

        /// <summary>The assembly that shows 'build' of a kit ship ("ship_NNN_mod#<build>", ModShips.Template assembles it).</summary>
        public static AssemblyData VariantAssembly(int ship, Build build) =>
            new AssemblyData { name = $"ship_{ship:000}_mod{VariantSeparator}{build}", pack = ModShips.Pack, category = "ships", origin = "kit build" };
    }
}
