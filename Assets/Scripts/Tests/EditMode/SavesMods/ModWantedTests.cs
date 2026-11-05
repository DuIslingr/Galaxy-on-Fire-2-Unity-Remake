// ModWantedTests.cs
// Feature: docs/notes/supernova.md "Most Wanted", Modding/README.md "Most Wanted": a mod's wanted.json adds criminals after
// the game's 25 (Modding.ModWanted), with their state by key (Session.ModWanted, saved by key), on their board in free play
// too while the game's stay off there, their kills counted apart (Session.ModBounties), their trips picked at docking.

using System.Linq;
using GoF2Remake.Data;
using GoF2Remake.Modding;
using NUnit.Framework;

namespace GoF2Remake.Tests
{
    public class ModWantedTests : SavesModsTest
    {
        Database Load()
        {
            WriteMod("w", "t_wanted", "1.0", "", ("wanted.json",
                "[ { 'id': 'khador', 'name': 'Khador', 'description': 'The Void prophet.', 'board': 'terran', 'race': 'nivelian', " +
                "'ship': 5, 'weapon': 2, 'secondary': 36, 'hitpoints': 8000, 'reward': 250000, 'loot': 113, 'lootAmount': 3, " +
                "'wingmen': 3, 'route': [1, 20], 'escorts': [7, 8, 'nope:y'], 'taunt': 'You will not leave.', 'music': 'nope' }, " +
                "{ 'id': 'later', 'name': 'Later', 'ship': 5, 'requiredBounties': 1, 'board': 'terran' }, " +
                "{ 'id': 'broken', 'name': 'Broken', 'ship': 'nope:x' } ]"));
            ScanAndEnable("t_wanted");
            return Database.Load();
        }

        static int TerranStation(Database db) =>
            db.Stations.First(s => db.Systems.Find(x => x.index == s.system) is SystemData sys && sys.raceId == 0
                                   && sys.jumpRoutesTo != null && sys.jumpRoutesTo.Count > 0 && s.index != 108).index;

        [Test]
        public void AModsCriminalsFollowTheGames()
        {
            var db = Load();
            var w = db.Wanted.Find(x => x.key == "t_wanted:khador");
            Assert.IsNotNull(w);
            Assert.AreEqual(25, db.Wanted.FindIndex(x => x.IsMod), "after the game's 25");
            Assert.AreEqual(w.index, db.Wanted.IndexOf(w));
            Assert.AreEqual(0, w.board);
            Assert.AreEqual(2, w.race);
            Assert.AreEqual(5, w.ship);
            Assert.AreEqual(36, w.secondary);
            Assert.AreEqual(3, w.numWingmen);
            Assert.AreEqual("The Void prophet.", w.description);
            CollectionAssert.AreEqual(new[] { 7, 8 }, w.escorts, "a ship that isn't: left out of the escorts");
            Assert.AreEqual("You will not leave.", w.taunt);
            Assert.IsNull(w.music, "no such track: the game's wanted music");
            Assert.IsNull(db.Wanted.Find(x => x.key == "t_wanted:later").escorts);
            Assert.IsNull(db.Wanted.Find(x => x.key == "t_wanted:broken"), "a ship that isn't: left out");
            StringAssert.Contains("is no ship", AllMessages(Installed("t_wanted")));
        }

        [Test]
        public void DamageTakenGoesByTheItemThenItsCategoryThenItsKind()
        {
            WriteMod("w", "t_weak", "1.0", "", ("wanted.json",
                "[ { 'id': 'weak', 'name': 'Weak', 'ship': 5, " +
                "'damageTaken': { 'primary': 70, 'secondary': 96, 'laser': 140, '2': 120, 'nope': 50, 'turret': 'x' } }, " +
                "{ 'id': 'plain', 'name': 'Plain', 'ship': 5, 'damageTaken': { 'primary': 100 } } ]"));
            ScanAndEnable("t_weak");
            var db = Database.Load();
            var taken = db.Wanted.Find(x => x.key == "t_weak:weak").damageTaken;
            Assert.IsNotNull(taken);
            Assert.AreEqual(1.2f, taken.Factor(db.Item(2)), 1e-4f, "the item itself first");
            Assert.AreEqual(1.4f, taken.Factor(db.Item(0)), 1e-4f, "then its category (any case)");
            Assert.AreEqual(0.7f, taken.Factor(db.Item(12)), 1e-4f, "then its kind: a blaster is a primary");
            Assert.AreEqual(0.96f, taken.Factor(db.Item(31)), 1e-4f, "a rocket is a secondary");
            Assert.AreEqual(1f, taken.Factor(null), "not a weapon of the player's");
            Assert.IsNull(db.Wanted.Find(x => x.key == "t_weak:plain").damageTaken, "nothing changed: none");
            string messages = AllMessages(Installed("t_weak"));
            StringAssert.Contains("nope is no weapon kind", messages);
            StringAssert.Contains("turret must be a percentage", messages);
        }

        [Test]
        public void DevicesAreReadWithTheirTriggersAndNumbers()
        {
            WriteMod("w", "t_dev", "1.0", "", ("wanted.json",
                "[ { 'id': 'boss', 'name': 'Boss', 'ship': 5, 'devices': [ " +
                "{ 'type': 'teleport', 'everyMs': 15000, 'chance': 50, 'distance': [2000, 1000], 'cooldownMs': 15000 }, " +
                "{ 'type': 'FrontShield', 'durationMs': 10000, 'ahead': 30, 'shieldAngle': 70, 'blockPercent': 90 }, " +
                "{ 'type': 'flashGrenade', 'range': [0, 1500], 'facing': 80, 'strength': 70, 'colour': 'red' }, " +
                "{ 'type': 'warp' }, { 'type': '3' } ] }, " +
                "{ 'id': 'none', 'name': 'None', 'ship': 5, 'devices': [ { 'type': 'nope' } ] } ]"));
            ScanAndEnable("t_dev");
            var db = Database.Load();
            var d = db.Wanted.Find(x => x.key == "t_dev:boss").devices;
            Assert.AreEqual(3, d.Count, "the unknown types left out (a number isn't a type)");
            Assert.AreEqual(Flight.NpcDeviceSpec.Kind.Teleport, d[0].kind);
            Assert.AreEqual(15000f, d[0].everyMs);
            Assert.AreEqual(0.5f, d[0].chance, 1e-4f);
            Assert.AreEqual(1000f, d[0].distanceMin, "sorted");
            Assert.AreEqual(2000f, d[0].distanceMax);
            Assert.AreEqual(Flight.NpcDeviceSpec.Kind.FrontShield, d[1].kind, "any case");
            Assert.AreEqual(30f, d[1].aheadDeg);
            Assert.AreEqual(70f, d[1].shieldDeg);
            Assert.AreEqual(0.9f, d[1].blockShare, 1e-4f);
            Assert.AreEqual(3000f, d[2].delayMs, "the flash's default delay");
            Assert.AreEqual(1500f, d[2].rangeMax);
            Assert.AreEqual(0.7f, d[2].strength, 1e-4f);
            Assert.IsNull(db.Wanted.Find(x => x.key == "t_dev:none").devices, "none valid: none");
            string messages = AllMessages(Installed("t_dev"));
            StringAssert.Contains("unknown device field \"colour\"", messages);
            StringAssert.Contains("warp", messages);
        }

        [Test]
        public void InFreePlayOnlyTheModsAreOnTheBoard()
        {
            var db = Load();
            Session.FreePlay = true;
            int station = TerranStation(db);
            Assert.IsTrue(WantedBoard.Accessible(db, station));
            var list = WantedBoard.ListFor(db, station);
            Assert.IsTrue(list.All(x => x.IsMod), "the game's stay off in free play");
            Assert.IsTrue(list.Exists(x => x.key == "t_wanted:khador"));
        }

        [Test]
        public void TheStateIsByKeyAndTheBountiesApart()
        {
            var db = Load();
            Session.FreePlay = true;
            var w = db.Wanted.Find(x => x.key == "t_wanted:khador");
            int station = TerranStation(db);
            Assert.AreEqual(1, WantedBoard.ActivateNew(db, station), "khador on a trip; 'later' waits for a bounty");
            var st = WantedBoard.State(db, w.index);
            Assert.IsTrue(st.active);
            Assert.AreSame(st, Session.ModWanted["t_wanted:khador"]);
            Assert.IsTrue(st.current >= 0 && st.travelsTo >= 0);
            long credits = Session.Credits;
            Assert.AreEqual(250000, WantedBoard.OnKilled(db, w.index));
            Assert.AreEqual(credits + 250000, Session.Credits);
            Assert.AreEqual(1, Session.ModBounties[0]);
            Assert.AreEqual(0, Session.CollectedBounties[0], "the game's tally untouched");
            Assert.AreEqual(1, WantedBoard.ActivateNew(db, station), "one bounty: 'later' comes");
            var saved = ModWantedSave.To(ModWantedSave.From(Session.ModWanted));
            Assert.IsTrue(saved["t_wanted:khador"].terminated);
            Assert.IsTrue(saved["t_wanted:later"].active);
        }
    }
}
