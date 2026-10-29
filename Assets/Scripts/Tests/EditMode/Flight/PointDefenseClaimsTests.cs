// PointDefenseClaimsTests.cs
// Feature: CLAUDE.md "Missile defense" (docs/notes/combat-equipment.md; Flight.PointDefense). Expected behaviour (the remake
// defines it, review of #168): a claim is on the missile it was made for: a new missile fired from the same bullet slot
// before the claim ran out is picked like any other and isn't shot down by the old claim; Clear (a level left) drops the
// claims with their guns.

using GoF2Remake.Data;
using GoF2Remake.Flight;
using NUnit.Framework;
using UnityEngine;

namespace GoF2Remake.Tests
{
    public class PointDefenseClaimsTests
    {
        int bursts;
        System.Action<Vector3> keep;
        readonly System.Collections.Generic.List<Gun> guns = new System.Collections.Generic.List<Gun>();

        [SetUp]
        public void SetUp()
        {
            PointDefense.ResetStatics();
            keep = PointDefense.Exploded;
            bursts = 0;
            PointDefense.Exploded = _ => bursts++;
        }

        [TearDown]
        public void TearDown()
        {
            PointDefense.Exploded = keep;
            PointDefense.ResetStatics();
            // IncomingMissiles keeps this frame's reports (edit mode: the frame doesn't move on): no live missile left behind.
            foreach (var g in guns) g.RemoveAll();
            guns.Clear();
        }

        Gun Missiles()   // one bullet slot
        {
            var g = new Gun(Database.Shared.Item(37), 100f, 3000f, 1, 10000f, 18f);
            guns.Add(g);
            return g;
        }

        /// <summary>A missile in slot 0, 'ageMs' into its flight, reported as flying at the ship.</summary>
        static void Fly(Gun gun, float ageMs)
        {
            Assert.IsTrue(gun.Inject(new Vector3(0f, 0f, 100f), Vector3.forward * 0.9f, Vector3.up, 5000f));
            gun.bullets[0].age = ageMs;
            IncomingMissiles.Report(gun, 0, gun.bullets[0].position, gun.bullets[0].velocity);
        }

        [Test]
        public void ANewMissileInAClaimedSlotIsPickedAgain()
        {
            var gun = Missiles();
            Fly(gun, 800f);
            Assert.IsTrue(PointDefense.Pick(Vector3.zero, 300f, out var m));
            PointDefense.Claim(m, 1e7f);   // its shot is still on the way
            Assert.IsFalse(PointDefense.Pick(Vector3.zero, 300f, out _), "claimed: left to that shot");
            gun.ShootDown(0);   // it hit something else meanwhile; the slot fires again
            Fly(gun, 0f);
            Assert.IsTrue(PointDefense.Pick(Vector3.zero, 300f, out var again), "a new missile: not the claimed one");
            Assert.AreEqual(0, again.index);
        }

        [Test]
        public void TheOldClaimDoesntShootDownTheNewMissile()
        {
            var gun = Missiles();
            Fly(gun, 800f);
            Assert.IsTrue(PointDefense.Pick(Vector3.zero, 300f, out var m));
            PointDefense.Claim(m, 0f);   // due at once
            gun.ShootDown(0);
            Fly(gun, 0f);   // a new missile in the slot before the claim was settled
            PointDefense.Tick();
            Assert.IsTrue(gun.IsActive(0), "the new missile flies on");
            Assert.AreEqual(0, bursts);
        }

        [Test]
        public void TheClaimedMissileIsStillShotDown()
        {
            var gun = Missiles();
            Fly(gun, 800f);
            Assert.IsTrue(PointDefense.Pick(Vector3.zero, 300f, out var m));
            PointDefense.Claim(m, 0f);
            gun.bullets[0].age += 50f;   // it flew on
            PointDefense.Tick();
            Assert.IsFalse(gun.IsActive(0));
            Assert.AreEqual(1, bursts);
        }

        [Test]
        public void ALevelLeftDropsTheClaims()
        {
            var gun = Missiles();
            Fly(gun, 800f);
            Assert.IsTrue(PointDefense.Pick(Vector3.zero, 300f, out var m));
            PointDefense.Claim(m, 0f);
            PointDefense.Clear();
            PointDefense.Tick();
            Assert.IsTrue(gun.IsActive(0), "no burst from a level left behind");
            Assert.AreEqual(0, bursts);
        }
    }
}
