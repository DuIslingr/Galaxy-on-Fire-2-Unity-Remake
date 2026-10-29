// ModShipKitsBuilds.cs
// ModShipKits: builds, the ships, customizations of ships without a kit (part of the partial ModShipKits; its fields are in ModShipKits.cs).

using System;
using System.Collections.Generic;
using System.Linq;
using GoF2Remake.Data;
using Newtonsoft.Json.Linq;
using UnityEngine;

namespace GoF2Remake.Modding
{
    public static partial class ModShipKits
    {
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
            // The skin: 'b''s when the type may wear it, else the fallback's, else none (the model's own look).
            var allowedSkins = kit.SkinsFor(type);
            Skin Allowed(string id) => string.IsNullOrEmpty(id) ? null : allowedSkins.Find(k => string.Equals(k.id, id, StringComparison.OrdinalIgnoreCase));
            // "none" (Build.NoSkin) is the model's own look picked over a fallback that has a skin.
            string fb = Allowed(fallback?.skin)?.id;
            string chosen = b?.skin == Build.NoSkin ? null : Allowed(b?.skin)?.id ?? fb;
            n.skin = chosen ?? (fb != null ? Build.NoSkin : null);
            // The weapon colour the same way ("none" = the weapons' own over a fallback that has one).
            string fw = fallback != null && ResolveWeaponColor(kit, fallback.weaponColor, out _) ? fallback.weaponColor : null;
            string wc = b?.weaponColor == Build.NoSkin ? null : b != null && ResolveWeaponColor(kit, b.weaponColor, out _) ? b.weaponColor : fw;
            n.weaponColor = wc ?? (fw != null ? Build.NoSkin : null);
            // The exhaust style the same way, its colours only with it (a palette id it has, or "#RRGGBB").
            string fe = ModExhausts.Find(fallback?.exhaust) != null ? fallback.exhaust : null;
            string ex = b?.exhaust == Build.NoSkin ? null : ModExhausts.Find(b?.exhaust) != null ? b.exhaust : fe;
            n.exhaust = ex ?? (fe != null ? Build.NoSkin : null);
            var style = ModExhausts.Find(n.exhaust);
            if (style != null)
            {
                var src = ex == b?.exhaust ? b : fallback;
                n.exhaustColor = ModExhausts.ResolveColor(style, src?.exhaustColor, out _) ? src.exhaustColor : null;
                n.exhaustColor2 = ModExhausts.ResolveColor(style, src?.exhaustColor2, out _) ? src.exhaustColor2 : null;
                n.exhaustSize = ModExhausts.SizeText(ModExhausts.ParseSize(src?.exhaustSize));
            }
            // The weapon models shown or hidden, only where the kit lets the player choose ("on" = shown over a fallback that
            // hides them).
            if (kit.hardpoints != null && kit.hardpoints.toggle)
            {
                bool fallbackHides = fallback != null && fallback.WeaponsHidden;
                bool hide = b != null && b.weapons == Build.WeaponsOn ? false : b != null && b.WeaponsHidden || fallbackHides;
                n.weapons = hide ? Build.WeaponsOff : fallbackHides ? Build.WeaponsOn : null;
            }
            // The livery: 'b''s when the type may wear it, "none" kept, else the fallback's (null = the skin's).
            Livery LiveryAllowed(string id) => kit.FindLivery(id) is Livery lv && lv.Allows(type) ? lv : null;
            n.livery = b?.livery == Build.NoSkin ? Build.NoSkin : LiveryAllowed(b?.livery)?.id
                     ?? (fallback?.livery == Build.NoSkin ? Build.NoSkin : LiveryAllowed(fallback?.livery)?.id);
            // The decal the same way.
            Decal DecalAllowed(string id) => kit.FindDecal(id) is Decal dc && dc.Allows(type) ? dc : null;
            n.decal = b?.decal == Build.NoSkin ? Build.NoSkin : DecalAllowed(b?.decal)?.id
                    ?? (fallback?.decal == Build.NoSkin ? Build.NoSkin : DecalAllowed(fallback?.decal)?.id);
            // The trails: 'b''s when the kit has them, else the fallback's (null = the Default veil).
            n.trail = kit.FindTrail(b?.trail)?.id ?? kit.FindTrail(fallback?.trail)?.id;
            n.boostTrail = kit.FindTrail(b?.boostTrail)?.id ?? kit.FindTrail(fallback?.boostTrail)?.id;
            return n;
        }
        /// <summary>A kit ship's kit (null: not one, or its kit's mod is off).</summary>
        public static Kit KitOf(CustomShipData c) => c == null || string.IsNullOrEmpty(c.kit) ? null : Find(c.kit);   // ModContent made it "mod_id:kit_id"
        /// <summary>The ship number's kit ship data (null: not a kit ship).</summary>
        public static CustomShipData KitShip(int ship) => Database.Shared.Ship(ship) is CustomShipData c && !string.IsNullOrEmpty(c.kit) ? c : null;
        /// <summary>A kit ship's default build (the dealers', the NPCs').</summary>
        public static Build DefaultBuild(CustomShipData c, Kit kit) => Normalize(kit, c.kitType, Build.Parse(c.defaultBuild));
        /// <summary>The player's build of a kit ship (Session.ShipBuilds by its key; else the default), valid for the kit.</summary>
        public static Build PlayerBuild(int ship)
        {
            var kit = CustomizationOf(ship);
            if (kit == null) return null;
            string key = BuildKey(ship);
            var saved = key != null && Session.ShipBuilds.TryGetValue(key, out var text) ? Build.Parse(text) : null;
            return Normalize(kit, TypeOf(ship), saved, DefaultBuildOf(ship, kit));
        }
        /// <summary>The player's new build of a kit ship (the hangar's Customize screen).</summary>
        public static void SetPlayerBuild(int ship, Build b)
        {
            string key = BuildKey(ship);
            if (key == null || b == null) return;
            Session.ShipBuilds[key] = b.ToString();
        }
        /// <summary>The assembly that shows 'build' of a kit ship ("ship_NNN_mod#<build>", ModShips.Template assembles it).</summary>
        public static AssemblyData VariantAssembly(int ship, Build build)
        {
            // The weapon colour isn't part of the model (Flight.WeaponTint colours the shots): no variant of its own.
            // Nor the exhaust style (ModExhausts.Apply puts it on the instance).
            // Nor the weapon models' toggle (ModHardpoints shows or hides them, and the pylons, on the instance).
            // Nor the engine trails (Es2EngineVfx reads the player's build).
            if (build != null && (!string.IsNullOrEmpty(build.weaponColor) || !string.IsNullOrEmpty(build.exhaust) || !string.IsNullOrEmpty(build.exhaustColor)
                                  || !string.IsNullOrEmpty(build.exhaustColor2) || !string.IsNullOrEmpty(build.exhaustSize) || !string.IsNullOrEmpty(build.weapons)
                                  || !string.IsNullOrEmpty(build.trail) || !string.IsNullOrEmpty(build.boostTrail)))
            {
                build = build.Clone();
                build.weaponColor = build.exhaust = build.exhaustColor = build.exhaustColor2 = build.exhaustSize = build.weapons = null;
                build.trail = build.boostTrail = null;
            }
            if (KitShip(ship) == null)
            {
                // Another ship with customizations: its own model, or with a skin a skinned copy of it
                // ("<model>#ship=N;<build>", ModShips.SkinnedTemplate through AssembledObject.LoadPrefab).
                var own = Database.Shared.ShipAssembly(ship);
                var skin = CustomizationOf(ship)?.FindSkin(build?.skin);
                if (own == null || skin == null) return own;
                // A ship with textures of its own already shows its copy, "<model>#ship=N": the skin goes on the model's name.
                int ownHash = own.name.IndexOf(VariantSeparator);
                string model = ownHash > 0 ? own.name.Substring(0, ownHash) : own.name;
                return new AssemblyData { name = $"{model}{VariantSeparator}{ShipToken}{ship};skin={skin.id}", pack = own.pack, category = own.category,
                                          origin = "skin", root = own.root };
            }
            return new AssemblyData { name = $"ship_{ship:000}_mod{VariantSeparator}{build}", pack = ModContent.Pack, category = "ships", origin = "kit build" };
        }
        /// <summary>A skinned variant's parts ("<model>#ship=N;skin=id"): the model's own assembly name, the ship and the
        /// skin (false: not one).</summary>
        public static bool ParseSkinned(string assembly, out string model, out int ship, out string skin) =>
            ParseShipCopy(assembly, out model, out ship, out skin) && skin != null;
        /// <summary>A game model's copy for one ship: "<model>#ship=N" (a mod ship's own textures, Database.ShipAssembly) or
        /// "<model>#ship=N;skin=id" (a skin, VariantAssembly): the model's own assembly name, the ship and the skin (null:
        /// none); false = not one.</summary>
        public static bool ParseShipCopy(string assembly, out string model, out int ship, out string skin)
        {
            model = null; ship = -1; skin = null;
            int hash = assembly?.IndexOf(VariantSeparator) ?? -1;
            if (hash <= 0 || string.Compare(assembly, hash + 1, ShipToken, 0, ShipToken.Length, StringComparison.Ordinal) != 0) return false;
            model = assembly.Substring(0, hash);
            foreach (var pair in assembly.Substring(hash + 1).Split(';'))
            {
                if (pair.StartsWith(ShipToken)) int.TryParse(pair.Substring(ShipToken.Length), out ship);
                else if (pair.StartsWith("skin=")) skin = pair.Substring(5);
            }
            if (string.IsNullOrEmpty(skin)) skin = null;
            return ship >= 0;
        }
        /// <summary>The key a ship's build is saved under: a mod ship's key, else "gof2:<number>" (the game's own ships).</summary>
        public static string BuildKey(int ship) => ship < 0 ? null : ModContent.ShipKey(ship) ?? "gof2:" + ship;
        /// <summary>The ship type its parts and skins are matched against: a kit ship's kitType, else "" (its own kit).</summary>
        public static string TypeOf(int ship) => KitShip(ship)?.kitType ?? "";
        /// <summary>A ship's default build: a kit ship's, else none (the model's own look).</summary>
        public static Build DefaultBuildOf(int ship, Kit kit)
        {
            var c = KitShip(ship);
            return c != null ? DefaultBuild(c, kit) : Normalize(kit, "", null);
        }
        /// <summary>What the Customize screen offers for a ship: a kit ship's kit, else the customizations the mods give it (a
        /// kit with no parts: their skins and weapon colours), null = none.</summary>
        public static Kit CustomizationOf(int ship)
        {
            var c = KitShip(ship);
            if (c != null) return KitOf(c);
            if (customRevision != ModManager.Revision) ReadShipCustomizations();
            if (shipCustom.TryGetValue(ship, out var k)) return k;
            // The mods' exhaust styles, on any ship: a kit with nothing else (made once per ship and set of mods).
            if (ship < 0 || !ModExhausts.Any) return null;
            if (!exhaustOnly.TryGetValue(ship, out k))
                exhaustOnly[ship] = k = new Kit { mod = ModExhausts.All()[0].mod, localId = "ship_" + ship, weaponColorRow = false,
                                                  name = new Dictionary<string, string> { ["en"] = "ship " + ship } };
            return k;
        }
        static void ReadShipCustomizations()
        {
            customRevision = ModManager.Revision;
            shipCustom.Clear();
            exhaustOnly.Clear();
            const string ShipsFile = "ships.json";
            foreach (var mod in ModManager.Active)
            {
                try
                {
                    if (!(ModJson.Read(mod.Source, ShipsFile) is JArray list)) continue;
                    foreach (var t in list)
                    {
                        if (!(t is JObject o) || ModJson.Has(o, "kit")) continue;   // a kit ship's skins are its kit's
                        var wc = ModJson.Get(o, "weaponColors");
                        bool skins = ModJson.Get(o, "skins") != null, colors = wc != null && !(wc.Type == JTokenType.Boolean && !(bool)wc);
                        if (!skins && !colors) continue;
                        string where = ModJson.Where(t, ShipsFile);
                        int ship = -1;
                        var ov = ModJson.Get(o, "override");
                        if (ov != null) ship = ov.Type == JTokenType.Integer ? (int)ov : ModContent.ShipIndexOf((string)ov);
                        else if (ModJson.Str(o, "id") is string id) ship = ModContent.ShipIndexOf(mod.Id + ":" + id);
                        if (ship < 0) { Warn(mod, $"{where}: \"skins\" / \"weaponColors\" for a ship that isn't in the game (ignored)"); continue; }
                        if (!shipCustom.TryGetValue(ship, out var kit))
                            shipCustom[ship] = kit = new Kit { mod = mod, localId = "ship_" + ship, name = new Dictionary<string, string> { ["en"] = "ship " + ship } };
                        if (skins)
                        {
                            var own = new Kit { mod = mod, localId = kit.localId };
                            ReadSkins(o, own, mod, where, ShipsFile);
                            foreach (var sk in own.skins)
                            {
                                sk.types.Clear();   // the ship's own
                                if (kit.FindSkin(sk.id) != null) { Warn(mod, $"{where}: the skin \"{sk.id}\" is already given to this ship by another mod (ignored)"); continue; }
                                kit.skins.Add(sk);
                            }
                        }
                        if (ModJson.Get(o, "weaponColors") is JArray pa)
                        {
                            if (!kit.palettes.TryGetValue("weapons", out var pl)) kit.palettes["weapons"] = pl = new List<ColorChoice>();
                            foreach (var choice in ReadPalette(pa, ShipsFile))
                                if (!pl.Exists(x => string.Equals(x.id, choice.id, StringComparison.OrdinalIgnoreCase))) pl.Add(choice);
                        }
                    }
                }
                catch (ModJsonException e) { Warn(mod, e.Message); }
            }
        }
    }
}
