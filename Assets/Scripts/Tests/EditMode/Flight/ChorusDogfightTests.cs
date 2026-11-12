// ChorusDogfightTests.cs
// Feature: Modding/README.md traffic "ai": "chorus" (Flight.ChorusDogfight, after Chorus's BT_Fighter_CombatRoam): expected,
// an approach at twice the speed firing within 600 m (Chorus's) until 50 m or 10 s, a 4 s pass, 2 s before the next
// approach; a 2 s break when the target aims at it (every 3 s at most); a 5 s retreat below half hull (every 15 s); a jump
// back when out of view for 2 s beyond 1.2 km (every 15 s).

using GoF2Remake.Flight;
using NUnit.Framework;

namespace GoF2Remake.Tests
{
    public class ChorusDogfightTests
    {
        static ChorusDogfight.View At(float d, bool aimed = false, float hull = 1f, bool hidden = false) =>
            new ChorusDogfight.View { distance = d, aimedAt = aimed, hullRatio = hull, outOfView = hidden };

        [Test]
        public void ItApproachesPassesAndComesBack()
        {
            var f = new ChorusDogfight(() => 0.7f);
            Assert.AreEqual(ChorusDogfight.Mode.Approach, f.Current);
            Assert.AreEqual(2f, f.SpeedFactor, "twice the speed on an approach");
            Assert.IsFalse(f.Fires(50000f), "not beyond 600 m (43 200 units)");
            Assert.IsTrue(f.Fires(40000f));
            f.Step(100f, At(3000f));
            Assert.AreEqual(ChorusDogfight.Mode.PassBy, f.Current, "within 50 m: on past it");
            Assert.AreEqual(1, f.Side);
            Assert.IsFalse(f.Fires(1000f));
            f.Step(4000f, At(20000f));
            Assert.AreEqual(ChorusDogfight.Mode.Approach, f.Current);
            Assert.AreEqual(1f, f.SpeedFactor, "the 2 s wait before the next run");
            Assert.IsFalse(f.Fires(20000f));
            f.Step(2100f, At(20000f));
            Assert.IsTrue(f.Fires(20000f));
            f.Step(10000f, At(20000f));
            Assert.AreEqual(ChorusDogfight.Mode.PassBy, f.Current, "an approach lasts 10 s at most");
        }

        [Test]
        public void ItBreaksRetreatsAndJumps()
        {
            var f = new ChorusDogfight(() => 0.2f);
            f.Step(100f, At(30000f, aimed: true));
            Assert.AreEqual(ChorusDogfight.Mode.Evade, f.Current);
            Assert.AreEqual(-1, f.Side);
            f.Step(2000f, At(30000f));
            Assert.AreEqual(ChorusDogfight.Mode.Approach, f.Current, "a 2 s break");
            f.Step(100f, At(30000f, aimed: true));
            Assert.AreEqual(ChorusDogfight.Mode.Approach, f.Current, "not again within 3 s");
            f.Step(100f, At(30000f, hull: 0.4f));
            Assert.AreEqual(ChorusDogfight.Mode.Retreat, f.Current, "below half its hull");
            f.Step(5000f, At(30000f, hull: 0.4f));
            Assert.AreEqual(ChorusDogfight.Mode.Approach, f.Current, "back after 5 s, the next retreat 15 s off");
            Assert.IsFalse(f.Step(1500f, At(90000f, hidden: true)));
            Assert.IsTrue(f.Step(600f, At(90000f, hidden: true)), "2 s out of view beyond 1.2 km: it jumps");
            Assert.IsFalse(f.Step(3000f, At(90000f, hidden: true)), "not again for 15 s");
            Assert.IsFalse(new ChorusDogfight(() => 0.5f).Step(3000f, At(50000f, hidden: true)), "not within 1.2 km");
        }
    }
}
