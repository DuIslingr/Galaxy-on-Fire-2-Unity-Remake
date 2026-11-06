// HazardTests.cs
// Feature: Modding/README.md orbit "hazards", docs/notes/navigation.md "Hazard volumes": Flight.Hazards, after EVERSPACE 2's
// BP_HeatDamageVolume (200 dps x (1 - d / r)^2 each 0.25 s) and the radiated condition (the hull's maximum x 0.85 a token,
// at most 10, cleared by docking). Expected values: those sums by hand.

using GoF2Remake.Flight;
using NUnit.Framework;

namespace GoF2Remake.Tests
{
    public class HazardTests
    {
        [TearDown] public void Clear() => Hazards.ClearRadiation();

        [Test]
        public void HeatFallsOffWithTheSquareOfTheDistance()
        {
            Assert.AreEqual(50f, Hazards.HeatDamage(200f, 0f, 1000f), 1e-3f, "the centre: 200 a second over a quarter second");
            Assert.AreEqual(12.5f, Hazards.HeatDamage(200f, 500f, 1000f), 1e-3f, "halfway: a quarter of it");
            Assert.AreEqual(0f, Hazards.HeatDamage(200f, 1000f, 1000f), "the edge");
            Assert.AreEqual(0f, Hazards.HeatDamage(200f, 1500f, 1000f), "outside");
        }

        [Test]
        public void RadiationLowersTheHullsLimitUntilDocking()
        {
            Assert.AreEqual(1f, Hazards.RadiationFactor(0));
            Assert.IsTrue(Hazards.AddRadiation());
            Assert.AreEqual(0.85f, Hazards.RadiationFactor(Hazards.RadiationTokens), 1e-5f);
            for (int i = 0; i < 20; i++) Hazards.AddRadiation();
            Assert.AreEqual(Hazards.MaxRadiationTokens, Hazards.RadiationTokens, "at most 10");
            Assert.IsFalse(Hazards.AddRadiation());
            Assert.AreEqual(UnityEngine.Mathf.Pow(0.85f, 10), Hazards.RadiationFactor(Hazards.RadiationTokens), 1e-5f);
            Hazards.ClearRadiation();
            Assert.AreEqual(0, Hazards.RadiationTokens, "docked");
        }

        [Test]
        public void FrostBuildsForFiveSecondsAndDrainsOverSixty()
        {
            float b = Hazards.FrostStep(0f, 4000f, true, out bool frozen);
            Assert.IsFalse(frozen);
            Assert.AreEqual(4000f, b);
            b = Hazards.FrostStep(b, 12000f, false, out frozen);
            Assert.AreEqual(3000f, b, 1e-3f, "12 s outside drain a fifth of the 5 s (60 s for all)");
            b = Hazards.FrostStep(b, 2000f, true, out frozen);
            Assert.IsTrue(frozen, "5 s built: frozen");
            Assert.AreEqual(0f, b, "and it builds again");
            Assert.AreEqual(0f, Hazards.FrostStep(100f, 60000f, false, out frozen), "never below none");
        }
    }
}
