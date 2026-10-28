// PointDefenseTests.cs
// Missile defense (Flight.PointDefense, the mods' "missileDefense"): the nearest missile at the ship within the reach is
// picked, a mirrored one never, a claimed one only once, and the claimed missile is gone once its shot arrives.

using GoF2Remake.Data;
using GoF2Remake.Flight;
using NUnit.Framework;
using UnityEngine;

namespace GoF2Remake.Tests
{
    public class PointDefenseTests
    {
        Vector3 exploded;
        System.Action<Vector3> keep;

        [SetUp]
        public void SetUp()
        {
            PointDefense.ResetStatics();
            keep = PointDefense.Exploded;
            exploded = Vector3.negativeInfinity;
            PointDefense.Exploded = at => exploded = at;
        }

        [TearDown]
        public void TearDown()
        {
            PointDefense.Exploded = keep;
            PointDefense.ResetStatics();
        }

        static Gun Missiles(bool mirror = false) =>
            new Gun(Database.Shared.Item(37), 100f, 3000f, 4, 10000f, 18f) { Mirror = mirror };

        static void Fly(Gun gun, int index, Vector3 at)
        {
            Assert.IsTrue(gun.Inject(at, Vector3.forward * 0.9f, Vector3.up, 5000f));
            IncomingMissiles.Report(gun, index, at, Vector3.forward * 0.9f);
        }

        [Test]
        public void TheNearestMissileInReachIsShotDownWhenTheShotArrives()
        {
            var gun = Missiles();
            Fly(gun, 0, new Vector3(0f, 0f, 250f));
            Fly(gun, 1, new Vector3(0f, 0f, 120f));
            Fly(gun, 2, new Vector3(0f, 0f, 900f));   // beyond the reach
            Assert.IsTrue(PointDefense.Pick(Vector3.zero, 300f, out var first));
            Assert.AreEqual(1, first.index, "the nearest");
            PointDefense.Claim(first, 0f);
            Assert.IsTrue(PointDefense.Pick(Vector3.zero, 300f, out var second));
            Assert.AreEqual(0, second.index, "a claimed missile isn't picked again");
            PointDefense.Claim(second, 0f);
            Assert.IsFalse(PointDefense.Pick(Vector3.zero, 300f, out _), "the third is out of reach");

            PointDefense.Tick();
            Assert.IsFalse(gun.IsActive(0));
            Assert.IsFalse(gun.IsActive(1));
            Assert.IsTrue(gun.IsActive(2));
            Assert.AreEqual(250f, exploded.z, 1e-3f, "the burst where it was");
        }

        [Test]
        public void AnotherGamesMissileIsLeftAlone()
        {
            Fly(Missiles(mirror: true), 0, new Vector3(0f, 0f, 100f));
            Assert.IsFalse(PointDefense.Pick(Vector3.zero, 300f, out _));
        }

        [Test]
        public void TheShotIsLedToWhereTheMissileWillBe()
        {
            var m = new IncomingMissiles.Missile { position = new Vector3(100f, 0f, 0f), velocity = new Vector3(0f, 0f, 0.5f) };
            var at = PointDefense.Lead(m, Vector3.zero, 1f, out float ms);   // the shot at 1 m/ms
            Assert.Greater(at.z, 40f);
            Assert.AreEqual(Vector3.Distance(at, Vector3.zero), ms, 5f, "the flight time to the lead point");
        }
    }
}
