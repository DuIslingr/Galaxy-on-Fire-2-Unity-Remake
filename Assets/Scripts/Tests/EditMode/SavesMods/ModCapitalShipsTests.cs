// ModCapitalShipsTests.cs
// Feature: CLAUDE.md "Mods (remake-only)" > Capital ships and mobile stations (Modding.ModCapitalShips, Modding.MobileStations,
// World.MobileStation): ships.json "traffic": { "capital": "battleship" | "freighter" } (never a fighter), their collision
// boxes cut from the model along its longest axis; stations.json "mobile": a station with no planet (not one of its system's
// stations, so not on the map and not counted in the 7) that cruises through its system's orbits in turn, "stayMinutes" in
// each, on a course that passes sideways 6-8 km in front of the orbit's station.

using System.Linq;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.Modding;
using NUnit.Framework;
using UnityEngine;

namespace GoF2Remake.Tests
{
    public class ModCapitalShipsTests : SavesModsTest
    {
        [TearDown] public void ClockBack() => MobileStations.ClockOverride = null;

        [Test]
        public void ACapitalShipsKindAndNoFighter()
        {
            string dir = WriteMod("c", "t_cap", "1.0", "", ("ships.json",
                "[ { 'id': 'big', 'name': 'Big', 'race': 0, 'model': 'big.glb', 'traffic': { 'capital': 'battleship' } }," +
                "  { 'id': 'hauler', 'name': 'Hauler', 'race': 1, 'model': 'big.glb', 'traffic': { 'capital': 'Freighter' } }," +
                "  { 'id': 'fighter', 'name': 'F', 'race': 0, 'model': 'big.glb' } ]"));
            WriteFile(dir, "big.glb", Dummy);
            ScanAndEnable("t_cap");
            Database.Load();
            int big = ModContent.ShipIndexOf("t_cap:big"), hauler = ModContent.ShipIndexOf("t_cap:hauler"), fighter = ModContent.ShipIndexOf("t_cap:fighter");
            Assert.AreEqual(ModCapitalShips.Battleship, ModCapitalShips.KindOf(big));
            Assert.AreEqual(ModCapitalShips.Freighter, ModCapitalShips.KindOf(hauler), "any case");
            Assert.IsNull(ModCapitalShips.KindOf(fighter));
            Assert.IsNull(ModCapitalShips.KindOf(14), "the game's battleship isn't a mod's");
            var spec = ModCapitalShips.Spawn(big, 0, new Vector3(0, 0, 100000));
            Assert.IsTrue(spec.freighter && spec.stationary && spec.modCapital, "a battleship parks on the freighters' path");
            Assert.AreEqual(NpcTables.Hull(1, 14), spec.hitpoints, "the Terran battleship's hull");
            Assert.AreEqual("Big", spec.name);
            var cruiser = ModCapitalShips.Spawn(hauler, 1, Vector3.zero);
            Assert.IsTrue(cruiser.freighter && !cruiser.stationary && cruiser.modCapital, "a freighter cruises");
            Assert.AreEqual(NpcGroup.Freighter, cruiser.group);
            // Not built (a dummy model): no boxes of its own, the race's freighter boxes stand in.
            Assert.IsNull(ModCapitalShips.HullVolumes(big, 0));
            Assert.AreEqual(CollisionVolume.ForFreighter(13, 1).Count, CollisionVolume.ForFreighter(hauler, 1).Count);
        }

        [Test]
        public void TheHullIsCutIntoBoxesAlongItsLength()
        {
            var root = new GameObject("hull");
            try
            {
                for (int i = 0; i < 8; i++)   // a 400 m hull in 50 m sections (vertices along its length)
                {
                    var cube = GameObject.CreatePrimitive(PrimitiveType.Cube);
                    cube.transform.SetParent(root.transform, false);
                    cube.transform.localScale = new Vector3(20f, 10f, 50f);
                    cube.transform.localPosition = new Vector3(0f, 0f, -175f + 50f * i);
                }
                var glow = GameObject.CreatePrimitive(PrimitiveType.Cube);
                glow.name = "engine_glow";
                glow.transform.SetParent(root.transform, false);
                glow.transform.localPosition = new Vector3(0f, 0f, -1000f);   // left out: not hull
                var boxes = ModCapitalShips.Measure(root, Quaternion.identity);
                Assert.AreEqual(8, boxes.Count);
                float lo = boxes.Min(b => b.centre.z - b.half.z), hi = boxes.Max(b => b.centre.z + b.half.z);
                Assert.AreEqual(-200f, lo, 0.5f);
                Assert.AreEqual(200f, hi, 0.5f);
                foreach (var b in boxes) { Assert.AreEqual(10f, b.half.x, 0.01f); Assert.AreEqual(5f, b.half.y, 0.01f); }
                // An NPC's root faces game +Z (Euler 0, 180, 0): the boxes turn with it.
                var turned = ModCapitalShips.Measure(root, Quaternion.Euler(0f, 180f, 0f));
                Assert.AreEqual(-boxes[0].centre.z, turned[0].centre.z, 0.01f);
            }
            finally { Object.DestroyImmediate(root); }
        }

        string MobileMod(string mobile = "{ 'stayMinutes': 10, 'speed': 0.2 }") =>
            WriteMod("m", "t_mob", "1.0", "", ("stations.json",
                "[ { 'id': 'mother', 'system': 14, 'name': 'Mother', 'techLevel': 9, 'mobile': " + mobile + " } ]"));

        [Test]
        public void AMobileStationHasNoPlanet()
        {
            MobileMod();
            ScanAndEnable("t_mob");
            var db = Database.Load();
            int mother = ModWorld.StationIndexOf("t_mob:mother");
            Assert.IsTrue(ModWorld.IsMobile(mother));
            Assert.AreEqual(14, db.Stations.Find(s => s.index == mother).system);
            CollectionAssert.DoesNotContain(db.Systems.Find(s => s.index == 14).stations, mother, "no planet: not one of the system's");
            var spec = ModWorld.MobileOf(mother);
            CollectionAssert.AreEqual(new[] { 70, 71, 72, 73, 74 }, spec.route, "every station of its system by default");
            Assert.AreEqual(10f, spec.stayMinutes);
            Assert.AreEqual(0.2f, spec.speed, 1e-5f);
            Assert.IsFalse(ModWorld.IsMobile(70));
        }

        [Test]
        public void ItCruisesFromOrbitToOrbit()
        {
            MobileMod("{ 'route': [72, 70, '74'], 'stayMinutes': 10 }");
            ScanAndEnable("t_mob");
            Database.Load();
            int mother = ModWorld.StationIndexOf("t_mob:mother");
            var route = ModWorld.MobileOf(mother).route;
            CollectionAssert.AreEqual(new[] { 72, 70, 74 }, route, "in order");
            var seen = new System.Collections.Generic.List<int>();
            for (int stay = 0; stay < 6; stay++) seen.Add(MobileStations.HostAt(mother, stay * 600.0 + 1.0));
            for (int i = 1; i < 6; i++) Assert.AreEqual(route[(route.IndexOf(seen[0]) + i) % 3], seen[i], "the next stop each stay");
            Assert.AreEqual(seen[0], MobileStations.HostAt(mother, 599.0), "the same stop through its stay");
            MobileStations.ClockOverride = () => 1.0;
            CollectionAssert.AreEqual(new[] { mother }, MobileStations.AtOrbit(seen[0], 1.0));
            Assert.AreEqual(0, MobileStations.AtOrbit(73, 1.0).Count, "not on its route");
            Assert.AreEqual(seen[0], MobileStations.HostNow(mother));
        }

        [Test]
        public void ItsCoursePassesSidewaysClearOfTheStation()
        {
            MobileMod();
            ScanAndEnable("t_mob");
            Database.Load();
            int mother = ModWorld.StationIndexOf("t_mob:mother");
            for (int stay = 0; stay < 200; stay++)
            {
                double start = stay * 600.0;
                MobileStations.CourseAt(mother, start + 300.0, out var middle, out var heading);
                Assert.AreEqual(0f, heading.y, 1e-5f, "level");
                Assert.AreEqual(1f, heading.magnitude, 1e-4f);
                Assert.Greater(middle.z, 0f, "in front of the station");
                float flat = new Vector2(middle.x, middle.z).magnitude;
                Assert.That(flat, Is.InRange(119999f, 160001f), "6-8 km out");
                Assert.AreEqual(0f, Vector3.Dot(new Vector3(middle.x, 0f, middle.z).normalized, heading), 1e-3f, "crossed sideways");
                MobileStations.CourseAt(mother, start + 1.0, out var first, out _);
                MobileStations.CourseAt(mother, start + 599.0, out var last, out _);
                Assert.AreEqual(0.2f * 598000f, (last - first).magnitude, 50f, "at its speed");
            }
        }

        [Test] public void OnlyANewStationIsMobile() =>
            StringAssert.Contains("only a new station", OpenBroken("[ { 'override': 70, 'mobile': true } ]"));
        [Test] public void MobileIsTrueOrAnObject() =>
            StringAssert.Contains("\"mobile\" must be true or", OpenBroken("[ { 'id': 'x', 'name': 'X', 'system': 14, 'mobile': 5 } ]"));

        string OpenBroken(string stations)
        {
            string dir = WriteMod("e", "t_err", "1.0", "", ("stations.json", stations));
            var m = OpenParsed(dir);
            Assert.IsTrue(m.Broken, "accepted: " + stations);
            return m.Errors[0];
        }
    }
}
