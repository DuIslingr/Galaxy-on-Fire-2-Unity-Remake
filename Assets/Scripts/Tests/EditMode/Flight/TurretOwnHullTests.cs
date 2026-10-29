// TurretOwnHullTests.cs
// Feature: CLAUDE.md "Turrets don't fire through their own ship" (docs/notes/mods.md; TurretCore.Host / Blocked,
// HullCollision.RayHits, Obstacle.RayInto). Expected behaviour (the remake defines it, review of #168): a turret whose barrel
// points into its own ship holds its fire, and once it turns away it fires again: Blocked follows the barrel (it used to be
// set only by a ready Fire, which the owners stopped calling once it was set, so an auto turret blocked once never fired
// again); the own hull is found among many other hulls on the ray (the shared 64-hit buffer could be filled by others).

using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using NUnit.Framework;
using UnityEngine;

namespace GoF2Remake.Tests
{
    public class TurretOwnHullTests
    {
        readonly List<GameObject> made = new List<GameObject>();

        [TearDown]
        public void CleanUp()
        {
            foreach (var go in made) if (go != null) Object.DestroyImmediate(go);
            made.Clear();
        }

        GameObject New(string name)
        {
            var go = new GameObject(name);
            made.Add(go);
            return go;
        }

        /// <summary>A turret model (root -> "pivot" -> "x_gun", the gun 1 m above the root) whose gun sits at 'gunAt', with a
        /// ready gun.</summary>
        (TurretCore core, Gun gun) Turret(Vector3 gunAt)
        {
            var root = New("turret").transform;
            root.position = gunAt - Vector3.up;
            var pivot = new GameObject("pivot").transform;
            pivot.SetParent(root, false);
            var gunNode = new GameObject("turret_002_gun").transform;
            gunNode.SetParent(pivot, false);
            gunNode.localPosition = Vector3.up;
            var core = TurretCore.Wrap(root, pivot, gunNode, TurretCore.StaticAim(pivot, gunNode), TurretCore.ShotFrom.AheadOfBarrel);
            var gun = new Gun(new ItemData { index = 0, categoryId = 0, lookIndex = 0 }, 10f, 100f, 15, 2000f, 20f);
            core.SetGun(gun, null);
            return (core, gun);
        }

        /// <summary>A point 'deg' degrees above (negative: below) straight ahead of 'from'.</summary>
        static Vector3 Ahead(Vector3 from, float deg) =>
            from + new Vector3(0f, Mathf.Sin(deg * Mathf.Deg2Rad), Mathf.Cos(deg * Mathf.Deg2Rad)) * 100f;

        /// <summary>The owners' frame (PlayerTurret.AutoAim, NpcMountedTurrets.Update): aim, drop the target when blocked, else
        /// fire. The bullet, or -1 (also when blocked).</summary>
        static int OwnerFrame(TurretCore core, Vector3 at, out bool blocked)
        {
            // The frames of turning first (steps of the turn rate, TurretAim.Step), until it is aligned.
            for (int i = 0; i < 5000 && !core.StepToward(at, 16f); i++) { }
            bool aligned = core.StepToward(at, 16f);
            Assert.IsTrue(aligned, "turned to the point");
            blocked = aligned && core.Blocked;
            return blocked || !aligned ? -1 : core.Fire();
        }

        [Test]
        public void ATurretBlockedByItsOwnHullFiresAgainOnceItTurnsAway()
        {
            var host = New("host");
            var o = host.AddComponent<Obstacle>();
            // The hull, and a tower on its back 60 m ahead of the turret (its own ship's superstructure).
            o.volumes = new List<CollisionVolume>
            {
                CollisionVolume.Box(Vector3.zero, new Vector3(20f, 10f, 100f)),
                CollisionVolume.Box(new Vector3(0f, 12f, 60f), new Vector3(5f, 5f, 5f)),
            };
            var top = new Vector3(0f, 9.5f, 0f);   // on the hull's back, inside its box
            var (core, gun) = Turret(top);
            core.Host = host.transform;

            Assert.AreEqual(-1, OwnerFrame(core, Ahead(top, 0f), out bool blocked), "into its own ship's tower: no shot");
            Assert.IsTrue(blocked, "the owner drops that target");
            Assert.AreEqual(-1, core.Fire(), "Fire holds it too, the gun ready");
            Assert.IsTrue(gun.Ready);

            int b = OwnerFrame(core, Ahead(top, 30f), out blocked);
            Assert.IsFalse(blocked, "turned up and away: no longer blocked (it stayed blocked for good)");
            Assert.GreaterOrEqual(b, 0, "and it fires again");

            gun.reloadAcc = 1e6f;
            Assert.AreEqual(-1, OwnerFrame(core, Ahead(top, 0f), out blocked), "back at the tower: blocked again");
            Assert.IsTrue(blocked);
        }

        [Test]
        public void WithoutAHostNothingBlocks()
        {
            var top = new Vector3(0f, 9.5f, 0f);
            var (core, _) = Turret(top);
            for (int i = 0; i < 5000 && !core.StepToward(Ahead(top, 0f), 16f); i++) { }
            Assert.IsFalse(core.Blocked, "a sentry gun: no ship of its own");
            Assert.GreaterOrEqual(core.Fire(), 0);
        }

        [Test]
        public void TheOwnHullIsFoundAmongManyOthersOnTheRay()
        {
            var hull = GameObject.CreatePrimitive(PrimitiveType.Cube);
            made.Add(hull);
            hull.transform.localScale = new Vector3(20f, 10f, 100f);
            var body = HullCollision.Attach(hull, null, null);
            Assert.IsNotNull(body, "the cube's mesh is a hull");
            // 80 other hulls straight above it, all on the ray (more than the 64 hits the shared buffer holds).
            for (int i = 0; i < 80; i++)
            {
                var other = GameObject.CreatePrimitive(PrimitiveType.Cube);
                made.Add(other);
                other.transform.position = new Vector3(0f, 30f + 3f * i, 0f);
                other.transform.localScale = new Vector3(4f, 1f, 4f);
                Assert.IsNotNull(HullCollision.Attach(other, null, null));
            }
            Physics.SyncTransforms();
            var below = new Vector3(0f, -40f, 0f);
            Assert.IsTrue(HullCollision.RayHits(below, Vector3.up, 30000f, body, null), "up through its own hull and the others");
            Assert.IsFalse(HullCollision.RayHits(below, Vector3.down, 30000f, body, null), "away from it");
            Assert.IsFalse(HullCollision.RayHits(new Vector3(0f, 25f, 0f), Vector3.up, 30000f, body, null),
                           "only the others on the way: not its own");
            Assert.IsFalse(HullCollision.RayHits(below, Vector3.up, 30000f, body, hull.transform), "its own meshes ignored");
        }
    }
}
