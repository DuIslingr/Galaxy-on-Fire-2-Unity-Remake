// ModFactionsTests.cs
// Feature: CLAUDE.md "Mods (remake-only)" > Factions (ModFactions.cs, Standing.cs, ModWorld.cs): a mod's factions.json adds
// factions as race numbers from ModFactions.FirstRace, each with its own standing (Session.FactionStanding, saved), its
// relations to the other factions and the game's races (NPC vs NPC), and a look race for the game's tables (hangar, bar,
// visitors); systems.json may give a system to a faction, fly mods' ships only there ("traffic": "mod") and name its locals
// and raiders; ships.json may name factions as a ship's race and its traffic's races; the lounges of a faction's system hold
// diplomats who restore a hostile faction to neutral.
// Expected values: the test mod's own numbers (a guild, a hostile gang and a faction that is the guild's friend, the
// standings it starts them at, the relations it writes) and the game's rules (hostile at -71, a delict of 5 per kill, x2 on
// Extreme; the game's 35 % diplomat chance; Midorian = hangar / bar 3).

using System.Linq;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.Modding;
using GoF2Remake.World;
using NUnit.Framework;
using UnityEngine;

namespace GoF2Remake.Tests
{
    public class ModFactionsTests : SavesModsTest
    {
        const string Factions = @"[
            { 'id': 'guild', 'name': 'Mining Guild', 'look': 'midorian', 'standing': 10, 'relations': { 'gang': 'enemy', 'allies': 'friend' } },
            { 'id': 'gang', 'name': 'The Gang', 'look': 'pirates', 'standing': -100, 'hostile': true },
            { 'id': 'allies', 'name': 'Allies', 'look': 'terran', 'standing': 80 } ]";
        const string Systems = @"[ { 'id': 'rim', 'name': 'Rim', 'race': 'guild', 'security': 1, 'position': [110, 50, 50],
            'traffic': 'mod', 'locals': ['guild', 'allies'], 'raiders': ['gang'] } ]";
        const string Stations = @"[ { 'id': 'rim_one', 'system': 't_fac:rim', 'name': 'Rim One', 'techLevel': 4, 'planet': 3 } ]";
        const string Ships = @"[ { 'id': 'raider', 'name': 'Raider', 'model': 'raider.glb', 'race': 'gang', 'armor': 100, 'cargo': 0,
            'handling': 100, 'price': 0, 'slots': { 'primary': 1, 'secondary': 0, 'turret': 0, 'equipment': 0 },
            'traffic': { 'races': ['gang', 'pirates'] } } ]";

        Database Load()
        {
            string dir = WriteMod("f", "t_fac", "1.0", "", ("factions.json", Factions), ("systems.json", Systems), ("stations.json", Stations),
                                  ("ships.json", Ships));
            WriteFile(dir, "raider.glb", Dummy);
            ScanAndEnable("t_fac");
            var m = Installed("t_fac");
            Assert.IsFalse(m.Broken, AllMessages(m));
            return Database.Load();
        }

        static int Race(string id) { Assert.IsTrue(ModFactions.TryResolve("t_fac:" + id, null, out int r), id); return r; }

        [Test]
        public void FactionsAreRacesOfTheirOwn()
        {
            Load();
            int guild = Race("guild"), gang = Race("gang"), allies = Race("allies");
            Assert.AreEqual(ModFactions.FirstRace, guild);
            Assert.AreEqual(ModFactions.FirstRace + 1, gang);
            Assert.AreEqual(ModFactions.FirstRace + 2, allies);
            Assert.AreEqual("Mining Guild", Standing.RaceName(guild));
            Assert.AreEqual(3, Standing.Look(guild));
            Assert.AreEqual(8, Standing.Look(gang));
            Assert.AreEqual(3, StationTables.HangarIndex(140, guild), "the guild's hangar: its look's (Midorian)");
            Assert.AreEqual(3, StationTables.BarRace(guild));
            Assert.AreEqual(2, Standing.Look(2), "a game race is its own look");
            Assert.AreEqual(guild, Standing.RaceWord("Mining Guild"));
            Assert.AreEqual(gang, Standing.RaceWord("t_fac:gang"));
        }

        [Test]
        public void EachFactionHasItsOwnStanding()
        {
            Load();
            int guild = Race("guild"), gang = Race("gang"), allies = Race("allies");
            Assert.AreEqual(10, Standing.Toward(guild), "its \"standing\" until it changes");
            Assert.IsFalse(Standing.IsEnemy(guild));
            Assert.IsTrue(Standing.IsEnemy(gang), "hostile: always an enemy");
            Assert.IsTrue(Standing.IsFriend(allies), "80: a friend");
            Standing.ApplyKill(guild, guild);
            Assert.AreEqual(5, Standing.Toward(guild), "a kill: delict 5");
            ModFactions.SetStanding(guild, -71);
            Assert.IsTrue(Standing.IsEnemy(guild), "hostile at -71");
            ModFactions.SetStanding(gang, 100);
            Assert.IsTrue(Standing.IsEnemy(gang), "a hostile faction stays an enemy whatever its standing");
            Assert.AreEqual(new[] { 30, 0 }, Session.Standing, "the game's axes untouched");
        }

        [Test]
        public void KillingTheGangPleasesItsEnemies()
        {
            Load();
            int guild = Race("guild"), gang = Race("gang");
            Standing.ApplyKill(gang, guild);
            Assert.AreEqual(11, Standing.Toward(guild), "a hostile faction's kill in its enemy's system: +1 there, like a pirate's");
        }

        [Test]
        public void RelationsDecideWhoFights()
        {
            Load();
            int guild = Race("guild"), gang = Race("gang"), allies = Race("allies");
            Assert.IsTrue(Standing.RacesHostile(guild, gang), "named enemies");
            Assert.IsTrue(Standing.RacesHostile(gang, guild), "either side's word counts");
            Assert.IsFalse(Standing.RacesHostile(guild, allies), "named friends");
            Assert.IsTrue(Standing.RacesHostile(gang, allies), "a hostile faction fights everyone it names no friend");
            Assert.IsTrue(Standing.RacesHostile(allies, Standing.Pirate), "the game's pirates fight every faction");
            Assert.IsFalse(Standing.RacesHostile(allies, 0), "a faction and a game race: neutral unless they say");
            Assert.AreEqual(gang, Standing.EnemyRaceOf(guild), "the guild's raiders: its hostile enemies");
        }

        [Test]
        public void AFactionsSystemFliesItsOwnTraffic()
        {
            var db = Load();
            int sys = ModWorld.SystemIndexOf("t_fac:rim");
            var s = db.Systems.Find(x => x.index == sys);
            Assert.AreEqual(Race("guild"), s.raceId);
            Assert.IsTrue(ModWorld.ModTrafficOnly(sys));
            CollectionAssert.AreEqual(new[] { Race("guild"), Race("allies") }, ModWorld.Locals(sys));
            CollectionAssert.AreEqual(new[] { Race("gang") }, ModWorld.Raiders(sys));
            Assert.IsFalse(ModWorld.ModTrafficOnly(0), "the game's systems as they are");
            Assert.IsFalse(PirateEventRules.Allowed(db, ModWorld.StationIndexOf("t_fac:rim_one"), s, true), "no GoF2 pirate events there");
        }

        [Test]
        public void ShipsNameFactions()
        {
            Load();
            int ship = OriginalShips;
            var c = CustomShips.All.FirstOrDefault(x => x.index == ship);
            Assert.IsNotNull(c);
            Assert.AreEqual(Race("gang"), c.race);
            CollectionAssert.AreEqual(new[] { Race("gang"), Standing.Pirate }, c.traffic.races);
        }

        [Test]
        public void FactionStandingsAreSaved()
        {
            Load();
            int guild = Race("guild");
            ModFactions.SetStanding(guild, -42);
            Assert.IsTrue(SaveGame.Save(1));
            Session.ResetNewGame();
            Assert.AreEqual(10, Standing.Toward(guild), "a new game: the faction's own start");
            Assert.IsTrue(SaveGame.Load(1));
            Assert.AreEqual(-42, Standing.Toward(guild));
        }

        [Test]
        public void DiplomatsRestoreAFactionToNeutral()
        {
            var db = Load();
            int guild = Race("guild"), allies = Race("allies");
            ModFactions.SetStanding(allies, -90);
            int station = ModWorld.StationIndexOf("t_fac:rim_one");
            Agent diplomat = null;
            for (int seed = 0; seed < 200 && diplomat == null; seed++)
            {
                Random.InitState(seed);
                diplomat = AgentGenerator.CreateAgents(db, station).Find(a => a.offer == AgentOffer.Diplomat && a.faction == allies);
            }
            Assert.IsNotNull(diplomat, "a diplomat for the hostile faction now and then (35 %)");
            Assert.AreEqual(0, diplomat.race, "it looks like the faction's look race (Terran)");
            Assert.AreEqual((int)(90 / 100f * 16000f), diplomat.costs);
            Assert.IsFalse(AgentGenerator.CreateAgents(db, station).Exists(a => a.offer == AgentOffer.Diplomat && a.faction == guild),
                           "none for a faction that isn't hostile");
        }
    }
}
