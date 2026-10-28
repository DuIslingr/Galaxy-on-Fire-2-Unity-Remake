// HangarInspectWallTests.cs
// Feature: CLAUDE.md "Station scene" > Inspect ship's camera collision (#190): the orbit camera stops short of a wall between
// it and the hull (HangarInspect.Blocked, StationLevel's casts). In at once; out at once where nothing held it (the zoom
// eases by itself: a per-frame lerp lagged every zoom-out); out from a wall eased by the time passed, the same at any frame
// rate; a new orbit finds its limit afresh; Settled (the Mod Builder MCP's captures) waits for the ease out.
// Expected values: HangarInspect's own (WallEase 0.01 per ms); the ship a 4 m cube (radius sqrt(12) ~ 3.46 m).

using GoF2Remake.World;
using NUnit.Framework;
using UnityEngine;

namespace GoF2Remake.Tests
{
    public class HangarInspectWallTests
    {
        static readonly Bounds Ship = new Bounds(Vector3.zero, new Vector3(4f, 4f, 4f));

        /// <summary>An orbit looking from +z at 'radii' ship radii, blended in; 'wall' how far the way out is clear.</summary>
        static HangarInspect Orbit(float radii, System.Func<float> wall)
        {
            var insp = new HangarInspect();
            insp.Begin(new Vector3(0f, 0f, 50f), Ship);
            insp.SetView(Vector3.forward, radii);
            insp.Blocked = (from, dir, max) => Mathf.Min(max, wall());
            insp.Tick(1000f);   // the blend done
            return insp;
        }

        static float Shown(HangarInspect insp, Transform cam, float dtMs)
        {
            insp.Tick(dtMs);
            insp.Apply(cam, Vector3.zero, Quaternion.identity, 1f);
            return Vector3.Distance(cam.position, insp.Centre);
        }

        [Test]
        public void WithNoWallTheCameraFollowsTheZoomAtOnce()
        {
            var go = new GameObject("cam");
            try
            {
                var insp = Orbit(2f, () => float.MaxValue);
                Assert.AreEqual(insp.Distance, Shown(insp, go.transform, 16f), 1e-3f);
                insp.Zoom(1.5f);   // out
                float before = insp.Distance;
                for (int i = 0; i < 5; i++)
                {
                    float shown = Shown(insp, go.transform, 16f);   // (Shown ticks the zoom on: read Distance after it)
                    Assert.AreEqual(insp.Distance, shown, 1e-3f, "frame " + i);
                }
                Assert.Greater(insp.Distance, before + 1f, "zooming out");
                Assert.IsFalse(insp.Settled, "the zoom itself still easing");
                for (int i = 0; i < 200; i++) Shown(insp, go.transform, 16f);
                Assert.IsTrue(insp.Settled);
            }
            finally { Object.DestroyImmediate(go); }
        }

        [Test]
        public void AWallStopsItAtOnceAndItEasesBackOutByTime()
        {
            var go = new GameObject("cam");
            try
            {
                float wall = 5f;
                var insp = Orbit(3f, () => wall);   // 10.4 m wanted
                Assert.AreEqual(5f, Shown(insp, go.transform, 16f), 1e-3f, "in at once");
                Assert.IsFalse(insp.Settled, "held in by the wall");
                wall = float.MaxValue;
                float first = Shown(insp, go.transform, 16f);
                Assert.That(first, Is.GreaterThan(5.1f).And.LessThan(insp.Distance - 1f), "out eased");
                Assert.IsFalse(insp.Settled, "still easing out");
                for (int i = 0; i < 100; i++) Shown(insp, go.transform, 16f);
                Assert.AreEqual(insp.Distance, Shown(insp, go.transform, 16f), 1e-3f);
                Assert.IsTrue(insp.Settled);
            }
            finally { Object.DestroyImmediate(go); }
        }

        [Test]
        public void TheEaseOutIsTheSameAtAnyFrameRate()
        {
            var go = new GameObject("cam");
            try
            {
                float At(float dtMs, int frames)
                {
                    float wall = 5f;
                    var insp = Orbit(3f, () => wall);
                    Shown(insp, go.transform, dtMs);
                    wall = float.MaxValue;
                    float d = 0f;
                    for (int i = 0; i < frames; i++) d = Shown(insp, go.transform, dtMs);
                    return d;
                }
                float fast = At(1000f / 120f, 24), slow = At(1000f / 30f, 6);   // 200 ms either way
                Assert.That(fast, Is.GreaterThan(6f));
                Assert.AreEqual(fast, slow, 0.01f);
            }
            finally { Object.DestroyImmediate(go); }
        }

        [Test]
        public void ANewOrbitFindsItsLimitAfresh()
        {
            var go = new GameObject("cam");
            try
            {
                float wall = 5f;
                var insp = Orbit(3f, () => wall);
                Shown(insp, go.transform, 16f);   // held at the wall
                wall = float.MaxValue;
                insp.End();     // left and opened again at once (Begin resets it, not only Reset)
                insp.Begin(new Vector3(0f, 0f, 50f), Ship);
                insp.SetView(Vector3.forward, 3f);
                insp.Tick(1000f);
                Assert.AreEqual(insp.Distance, Shown(insp, go.transform, 16f), 1e-3f, "no ease from the old wall");
            }
            finally { Object.DestroyImmediate(go); }
        }
    }
}
