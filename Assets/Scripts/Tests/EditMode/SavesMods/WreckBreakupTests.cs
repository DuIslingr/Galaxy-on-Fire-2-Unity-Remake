// WreckBreakupTests.cs
// Feature: docs/notes/mods-models.md "Wrecks that break apart": ships.json "wreck" (CustomShipData.wreck) is read with its
// defaults; World.WreckBreakup flings its model's meshes apart from the wreck's middle with the ship's motion, slows them,
// shrinks them away over the last quarter and is gone at its end.

using GoF2Remake.Data;
using NUnit.Framework;
using UnityEngine;

namespace GoF2Remake.Tests
{
    public class WreckBreakupTests
    {
        [Test]
        public void TheWreckIsReadWithItsDefaults()
        {
            var c = JsonUtility.FromJson<CustomShipData>("{ \"id\": \"x\", \"wreck\": { \"model\": \"wrecks/x.glb\", \"seconds\": 9 } }");
            Assert.AreEqual("wrecks/x.glb", c.wreck.model);
            Assert.AreEqual(9f, c.wreck.seconds);
            Assert.AreEqual(1f, c.wreck.speed);
            Assert.IsNull(JsonUtility.FromJson<CustomShipData>("{ \"id\": \"x\" }").wreck?.model, "none: it explodes and is gone");
        }

        [Test]
        public void ThePiecesFlyApartSlowAndShrinkAway()
        {
            var root = new GameObject("wreck");
            try
            {
                var left = GameObject.CreatePrimitive(PrimitiveType.Cube); left.transform.SetParent(root.transform); left.transform.localPosition = new Vector3(-5f, 0f, 0f);
                var right = GameObject.CreatePrimitive(PrimitiveType.Cube); right.transform.SetParent(root.transform); right.transform.localPosition = new Vector3(5f, 0f, 0f);
                var w = GoF2Remake.World.WreckBreakup.Break(root, new CustomWreck { seconds = 4f, speed = 1f, spin = 0f }, new Vector3(0f, 0f, 10f));
                Assert.AreEqual(2, w.Pieces);
                w.Step(1f);
                var lc = left.GetComponent<Renderer>().bounds.center; var rc = right.GetComponent<Renderer>().bounds.center;
                Assert.Less(lc.x, -5f, "the left piece flies left");
                Assert.Greater(rc.x, 5f, "the right one right");
                Assert.Greater(lc.z, 5f, "both with the ship's motion");
                float gap1 = rc.x - lc.x;
                w.Step(1f);
                float gap2 = right.GetComponent<Renderer>().bounds.center.x - left.GetComponent<Renderer>().bounds.center.x;
                Assert.Less(gap2 - gap1, gap1 - 10f, "slowing down");
                w.Step(1.6f);
                Assert.Less(left.transform.localScale.x, 0.5f, "shrinking over the last quarter");
                w.Step(1f);
                Assert.IsTrue(root == null, "gone at its end");
            }
            finally { if (root != null) Object.DestroyImmediate(root); }
        }
    }
}
