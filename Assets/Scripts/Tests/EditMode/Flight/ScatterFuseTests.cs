// ScatterFuseTests.cs
// Feature: CLAUDE.md "Pirate events" / weapons.md (Gun.InScatterCube; a Discord report with a video, "Pirate outpost
// collision bug": near a pirate outpost every scatter shot burst at the ship's nose). Expected behaviour: the scatter gun's
// proximity fuse grows a fighter's hit cube x1.5 / x2 / x3 with the distance (Gun::calcCharacterCollision), but not a big
// object's (a hit radius past 2000 units: the outpost's +-7500 cube, which x3 reached 1.1 km out, past the shooter);
// shots at the outpost still hit it, and under Mixed collision its hull alone takes them.

using System.Collections.Generic;
using System.Linq;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using NUnit.Framework;
using UnityEngine;

namespace GoF2Remake.Tests
{
    public class ScatterFuseTests : SandboxTest
    {
        const float M = Gun.MetersPerUnit;
        readonly List<GameObject> made = new List<GameObject>();
        System.IDisposable collision;

        [SetUp]
        public void SaveCollision() => collision = new SettingsScope<int>(() => Settings.ShipCollision, v => Settings.ShipCollision = v);

        [TearDown]
        public void CleanUp()
        {
            collision?.Dispose();
            foreach (var go in made) if (go != null) Object.DestroyImmediate(go);
            made.Clear();
        }

        Target Make(string name, Vector3 at, float radiusUnits)
        {
            var go = new GameObject(name);
            made.Add(go);
            go.transform.position = at;
            var t = go.AddComponent<Target>();
            t.radius = radiusUnits * M;
            t.isShip = true;
            t.hostileToPlayer = true;
            return t;
        }

        /// <summary>The pirate outpost: its +-7500 cube (station_pirates, hitRadius 7500), 'hull' a 40 m block at its centre.</summary>
        Target Outpost(bool hull)
        {
            var t = Make("outpost", Vector3.zero, 7500f);
            if (hull)
            {
                var c = GameObject.CreatePrimitive(PrimitiveType.Cube);
                made.Add(c);
                c.transform.SetParent(t.transform, false);
                c.transform.localScale = new Vector3(40f, 40f, 40f);
                Assert.IsNotNull(HullCollision.Attach(t.gameObject, t, null), "the block is a hull");
                Physics.SyncTransforms();
            }
            return t;
        }

        static Gun Scatter()
        {
            var item = Database.Shared.Items.First(it => it.categoryId == 25 && !it.modded);
            return new Gun(item, Vector3.zero, false);
        }

        /// <summary>One scatter shot from 'from' along 'dir', flown up to 3 s: the target it struck, null = none.</summary>
        Target Shoot(Vector3 from, Vector3 dir, List<Target> targets)
        {
            var gun = Scatter();
            gun.owner = Make("player", from, 1000f);
            Target hit = null;
            gun.Hit += (_, t, __) => hit ??= t;
            Assert.AreEqual(0, gun.TryFire(from, Quaternion.LookRotation(dir), false));
            for (int f = 0; f < 180 && hit == null; f++) gun.Update(16f, targets, null);
            return hit;
        }

        [TestCase(9000f)]    // x1.5: the cube was +-11250
        [TestCase(14000f)]   // x2: +-15000
        [TestCase(21000f)]   // x3: +-22500
        public void AShotAwayFromTheOutpostDoesntBurstOnItUnderOriginalCollision(float outUnits)
        {
            Settings.ShipCollision = SessionRules.CollisionOriginal;
            var outpost = Outpost(false);
            Assert.IsNull(Shoot(new Vector3(outUnits * M, 0f, 0f), Vector3.right, new List<Target> { outpost }));
        }

        [Test]
        public void AShotAwayFromTheOutpostDoesntBurstOnItUnderMixedCollision()
        {
            Settings.ShipCollision = SessionRules.CollisionMixed;
            var outpost = Outpost(true);
            Assert.IsNull(Shoot(new Vector3(9000f * M, 0f, 0f), Vector3.right, new List<Target> { outpost }));
        }

        [Test]
        public void AShotAtTheOutpostStillHitsIt()
        {
            Settings.ShipCollision = SessionRules.CollisionOriginal;
            var outpost = Outpost(false);
            // 9000 out: its plain cube 1500 units ahead, within the scatter shot's 2000 (the Nirai's range).
            Assert.AreSame(outpost, Shoot(new Vector3(-9000f * M, 0f, 0f), Vector3.right, new List<Target> { outpost }));
        }

        [Test]
        public void TheFuseStillBurstsNearAFighter()
        {
            Settings.ShipCollision = SessionRules.CollisionOriginal;
            // A fighter's +-1000 cube, the shot passing 1200 units beside it from 2500 out: inside the fuse's x1.5.
            var fighter = Make("fighter", Vector3.zero, 1000f);
            Assert.AreSame(fighter, Shoot(new Vector3(-2500f * M, 1200f * M, 0f), Vector3.right, new List<Target> { fighter }));
        }
    }
}
