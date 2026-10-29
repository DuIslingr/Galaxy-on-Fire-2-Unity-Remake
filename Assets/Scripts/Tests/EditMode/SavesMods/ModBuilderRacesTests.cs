// ModBuilderRacesTests.cs
// Feature: CLAUDE.md "Mods" > Mod Builder: the Races kind (docs/notes/mod-builder.md "Its other kinds"). A project keeps the
// mod's own races in races.json (ProjectRace: written, read back, in the undo steps, unknown fields kept; an older
// project's factions.json read and written back as races.json); a system's owner, locals and raiders and a ship's race and
// traffic races hold a mod race's reference as the string it was through a load, an edit of other fields and a save, and a
// game race picked replaces it; removing a race (ModProject.RemoveRace) takes every reference to it in the project along:
// owners and ships back to its look race, list entries and relations gone. The pickers' values (ModRefs.RaceValue): a game
// race's number or word as its word, a project race's id as its key.
// Expected values: the formats in Modding/README.md "Races" and "Systems" (race, locals, raiders, traffic "mod"), ships.json
// "traffic" "races".

using System.IO;
using System.Linq;
using GoF2Remake.Modding;
using Newtonsoft.Json.Linq;
using NUnit.Framework;
using UnityEngine;

namespace GoF2Remake.Tests
{
    public class ModBuilderRacesTests : SavesModsTest
    {
        [Test]
        public void ARaceIsWrittenAndReadBack()
        {
            var p = ModProject.Create("Races test", "tests");
            var r = p.AddRace("Mining Guild");
            Assert.AreEqual("mining_guild", r.Id);
            r.Description = "Diggers.";
            r.Look = 3;
            r.Colour = new Color(1f, 0.7f, 0.2f);
            r.Standing = 10;
            r.Diplomats = false;
            r.Gun = "28";
            r.SetRelation("gang", "enemy");
            r.SetRelation("terran", "friend");
            r.Json["future"] = "kept";   // a field the builder doesn't know
            p.Save();
            Assert.IsTrue(File.Exists(Path.Combine(p.Folder, "races.json")));

            var back = ModProject.Load(p.Folder);
            Assert.IsNull(back.LoadError);
            var b = back.Races.Single();
            Assert.AreEqual("Mining Guild", b.Name);
            Assert.AreEqual("Diggers.", b.Description);
            Assert.AreEqual(3, b.Look);
            Assert.AreEqual(3, b.LookRace);
            Assert.AreEqual("midorian", (string)b.Json["look"]);
            Assert.AreEqual(0.7f, b.Colour.Value.g, 0.001f);
            Assert.AreEqual(10, b.Standing);
            Assert.IsFalse(b.Hostile);
            Assert.IsFalse(b.Diplomats);
            Assert.AreEqual(28, (int)b.Json["gun"], "a game item stays a number");
            CollectionAssert.AreEqual(new[] { ("gang", "enemy"), ("terran", "friend") }, b.Relations);
            Assert.AreEqual("kept", (string)b.Json["future"]);
            Assert.IsTrue(back.TranslatableTexts().Any(t => t.key == "races.mining_guild.name" && t.english == "Mining Guild"));

            // Defaults go from the file: a hostile race has no diplomats unless it says so, a standing of 0 isn't written.
            b.Standing = 0;
            b.Hostile = true;
            b.Diplomats = false;
            Assert.IsNull(b.Json["standing"]);
            Assert.IsNull(b.Json["diplomats"], "false is a hostile race's default");
            b.SetRelation("gang", null);
            b.SetRelation("terran", null);
            Assert.IsNull(b.Json["relations"], "an empty relations object goes");

            // Undo: the races are part of a step.
            var state = back.CaptureState();
            back.Races.Clear();
            back.RestoreState(state);
            Assert.AreEqual("mining_guild", back.Races.Single().Id);
        }

        [Test]
        public void AnOldFactionsFileIsReadAndWrittenBackAsRaces()
        {
            var p = ModProject.Create("Old factions", "tests");
            File.WriteAllText(Path.Combine(p.Folder, "factions.json"), new JArray(new JObject { ["id"] = "guild", ["name"] = "Guild" }).ToString());
            var back = ModProject.Load(p.Folder);
            Assert.AreEqual("guild", back.Races.Single().Id);
            back.Save();
            Assert.IsTrue(File.Exists(Path.Combine(p.Folder, "races.json")));
            Assert.IsFalse(File.Exists(Path.Combine(p.Folder, "factions.json")), "the old file goes");
            Assert.AreEqual("guild", ModProject.Load(p.Folder).Races.Single().Id);
        }

        [Test]
        public void ARaceOwnedSystemAndShipKeepTheirRacesThroughAnEdit()
        {
            var p = ModProject.Create("Race owned", "tests");
            File.WriteAllText(Path.Combine(p.Folder, "systems.json"), new JArray(new JObject
            {
                ["id"] = "kepler", ["name"] = "Kepler", ["race"] = "guild", ["security"] = 1, ["position"] = new JArray(50, 50, 50),
                ["locals"] = new JArray("guild", "terran"), ["raiders"] = new JArray("other_mod:gang"), ["traffic"] = "mod",
            }).ToString());
            File.WriteAllText(Path.Combine(p.Folder, "ships.json"), new JArray(new JObject
            {
                ["id"] = "digger", ["name"] = "Digger", ["race"] = "guild", ["traffic"] = new JObject { ["weight"] = 2, ["races"] = new JArray("guild", 8) },
            }).ToString());

            var a = ModProject.Load(p.Folder);
            Assert.IsNull(a.LoadError);
            var s = a.Systems.Single();
            Assert.AreEqual(-1, s.Race, "a mod race owns it");
            Assert.AreEqual("guild", s.ModRace);
            CollectionAssert.AreEqual(new[] { "guild", "terran" }, s.Locals);
            CollectionAssert.AreEqual(new[] { "other_mod:gang" }, s.Raiders);
            Assert.IsTrue(s.ModTraffic);
            var sh = a.Ships.Single();
            Assert.AreEqual(-1, sh.Race);
            Assert.AreEqual("guild", sh.ModRace);
            CollectionAssert.AreEqual(new[] { "guild", "8" }, sh.TrafficRaces);

            // Other fields edited, saved and read again: the races are as they were.
            s.Name = "Kepler Prime";
            s.Security = 3;
            s.Gates = new System.Collections.Generic.List<string> { "4" };
            sh.Armor = 500;
            a.Save();
            var b = ModProject.Load(p.Folder);
            s = b.Systems.Single();
            Assert.AreEqual("guild", (string)s.Json["race"]);
            CollectionAssert.AreEqual(new[] { "guild", "terran" }, s.Locals);
            CollectionAssert.AreEqual(new[] { "other_mod:gang" }, s.Raiders);
            Assert.AreEqual("mod", (string)s.Json["traffic"]);
            sh = b.Ships.Single();
            Assert.AreEqual("guild", (string)sh.Json["race"]);
            Assert.AreEqual(2, (int)sh.Json["traffic"]["weight"]);
            Assert.AreEqual(JTokenType.Integer, sh.Json["traffic"]["races"][1].Type, "a game race stays a number");

            // A game race picked replaces the mod race; a mod race picked replaces the game race.
            s.Race = 2;
            Assert.AreEqual(2, (int)s.Json["race"]);
            Assert.IsNull(s.ModRace);
            s.ModRace = "race_owned:guild";
            Assert.AreEqual(-1, s.Race);
            sh.Race = 8;
            Assert.AreEqual(8, sh.Race);
            Assert.IsNull(sh.ModRace);
            // Race words read as the game races they are.
            s.Json["race"] = "vossk";
            Assert.AreEqual(1, s.Race);
            Assert.IsNull(s.ModRace);
        }

        [Test]
        public void RemovingARaceTakesItsReferencesAlong()
        {
            var p = ModProject.Create("Race removal", "tests");
            var guild = p.AddRace("Guild");
            guild.Look = 3;
            var gang = p.AddRace("Gang");
            gang.SetRelation(p.Key("guild"), "enemy");
            gang.SetRelation("terran", "enemy");
            var sys = p.AddSystem("Kepler", new Vector3(50, 50, 50), 0);
            sys.ModRace = p.Key("guild");
            sys.Locals = new System.Collections.Generic.List<string> { "guild", "vossk" };
            sys.Raiders = new System.Collections.Generic.List<string> { "guild" };
            var other = p.AddSystem("Far", new Vector3(60, 60, 50), 1);
            other.Raiders = new System.Collections.Generic.List<string> { "gang" };
            var ship = p.AddNewShip("digger", "Digger", "models/digger.glb");
            ship.ModRace = "guild";
            ship.TrafficRaces = new System.Collections.Generic.List<string> { p.Key("guild"), "8" };

            Assert.AreEqual(6, p.RaceUses(guild), "owner, a local, a raider, a ship, its traffic, a relation");
            Assert.AreEqual(1, p.RaceUses(gang));
            Assert.AreEqual("pirates", ModRefs.RaceValue("8", p));
            Assert.AreEqual("terran", ModRefs.RaceValue("terrans", p));
            Assert.AreEqual("race_removal:guild", ModRefs.RaceValue("guild", p));

            p.RemoveRace(guild);
            Assert.AreEqual("gang", p.Races.Single().Id);
            Assert.AreEqual(3, sys.Race, "back to its look race");
            CollectionAssert.AreEqual(new[] { "vossk" }, sys.Locals);
            Assert.IsNull(sys.Json["raiders"], "an emptied list goes: the default again");
            CollectionAssert.AreEqual(new[] { "gang" }, other.Raiders, "the other race's references stay");
            Assert.AreEqual(3, ship.Race);
            CollectionAssert.AreEqual(new[] { "8" }, ship.TrafficRaces);
            CollectionAssert.AreEqual(new[] { ("terran", "enemy") }, gang.Relations);

            p.Save();
            var back = ModProject.Load(p.Folder);
            Assert.AreEqual("gang", back.Races.Single().Id);
            Assert.AreEqual(3, (int)back.Systems[0].Json["race"]);
        }
    }
}
