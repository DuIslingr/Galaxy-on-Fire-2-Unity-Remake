// VoidEnergyTests.cs
// Feature: docs/notes/combat-equipment.md "Rites", Modding/README.md "Devices": Chorus's Void energy (Flight.VoidEnergy):
// 3 pips, one back every 1 / 0.22 s on a tonne of Void Crystals (none aboard: none grow), the bonus pips paid first and
// running out, a cost above the total refused; Rite of the
// Hunt's numbers (Flight.Device 23: Blink's range, landing and cost), where it lands, its timelines and the camera's glide;
// the Rite of the Storm's numbers (Flight.Device 24: Pulse Zap's) and its jam (Target.Jammed).

using GoF2Remake.Flight;
using NUnit.Framework;
using UnityEngine;

namespace GoF2Remake.Tests
{
    public class VoidEnergyTests
    {
        [Test]
        public void ThePoolStartsFullAndGrowsBackAPipEvery4Point5Seconds()
        {
            var r = new VoidEnergy();
            Assert.AreEqual(3, r.Total);
            Assert.IsTrue(r.Full);
            Assert.IsTrue(r.TryPay(2));
            Assert.AreEqual(1, r.Regular);
            r.Step(4.5f);
            Assert.AreEqual(1, r.Regular, "0.99 of a pip");
            Assert.AreEqual(0.99f, r.Progress, 1e-4f);
            r.Step(0.05f);
            Assert.AreEqual(2, r.Regular, "1 / 0.22 = 4.545 s a pip");
            r.Step(10f);
            Assert.AreEqual(3, r.Regular);
            Assert.AreEqual(0f, r.Progress, "nothing grows while full");
        }

        [Test]
        public void ThePipsGrowBackOnVoidCrystals()
        {
            int crystals = 2;
            var r = new VoidEnergy { HasFuel = () => crystals >= VoidEnergy.CrystalsPerPip, Burn = () => crystals -= VoidEnergy.CrystalsPerPip };
            Assert.AreEqual(164, VoidEnergy.VoidCrystalItem);
            r.TryPay(3);
            r.Step(4.6f);
            Assert.AreEqual(1, r.Regular);
            Assert.AreEqual(1, crystals, "a tonne a pip");
            r.Step(4.6f);
            Assert.AreEqual(2, r.Regular);
            Assert.AreEqual(0, crystals);
            Assert.IsTrue(r.Starved, "the last one went");
            r.Step(30f);
            Assert.AreEqual(2, r.Regular, "none aboard: none grow");
            Assert.AreEqual(0f, r.Progress);
            crystals = 5;
            r.Step(4.6f);
            Assert.AreEqual(3, r.Regular, "more aboard: it grows again");
            Assert.IsFalse(r.Starved);
            Assert.AreEqual(4, crystals);
            r.Step(10f);
            Assert.AreEqual(4, crystals, "nothing burnt while full");
        }

        [Test]
        public void ACostAboveTheTotalIsRefusedAndNothingPaid()
        {
            var r = new VoidEnergy();
            Assert.IsTrue(r.TryPay(2));
            Assert.IsFalse(r.CanPay(2));
            Assert.IsFalse(r.TryPay(2));
            Assert.AreEqual(1, r.Regular, "untouched");
            Assert.IsTrue(r.TryPay(0), "a free Rite");
            Assert.AreEqual(0.5f, r.ChargeToward(2), 1e-4f, "the HUD's sweep: 1 of 2");
            r.Step(1f);
            Assert.AreEqual(0.61f, r.ChargeToward(2), 1e-4f, "with the pip growing back");
        }

        [Test]
        public void BonusPipsArePaidFirstAndRunOut()
        {
            var r = new VoidEnergy();
            r.AddBonus(2, 5f);
            Assert.AreEqual(5, r.Total, "past the maximum (Blink's upgrade A)");
            Assert.IsTrue(r.TryPay(3));
            Assert.AreEqual(0, r.Bonus);
            Assert.AreEqual(2, r.Regular, "the bonus ones first");
            r.AddBonus(1, 2f);
            r.Step(2.5f);
            Assert.AreEqual(0, r.Bonus, "timed out");
            r.AddRegular(5);
            Assert.AreEqual(3, r.Regular, "capped");
        }

        [Test]
        public void ARegenDelayHoldsTheGrowthAfterAPayment()
        {
            var r = new VoidEnergy(3, 0.5f, 1f);
            r.TryPay(1);
            r.Step(0.8f);
            Assert.AreEqual(0f, r.Progress);
            r.Step(0.4f);
            Assert.AreEqual(0.1f, r.Progress, 1e-4f, "the rest of the step past the delay");
            r.Refill();
            Assert.AreEqual(3, r.Total);
        }

        [Test]
        public void TheHuntsNumbersAreBlinks()
        {
            Assert.AreEqual(Device.Type.RiteHunt, (Device.Type)23);
            Assert.AreEqual(1000f, Device.HuntRangeTops * 140f, 1e-3f, "Range 100000 cm at Chorus's 140 m/s");
            Assert.AreEqual(180f, Device.HuntBehindTops * 140f, 1e-3f, "BlinkLocationOffset -18000 cm");
            Assert.AreEqual(2, Device.HuntCost);
            Assert.AreEqual(500, Device.HuntCooldownMs);
            var spot = Device.HuntSpot(new Vector3(10f, 0f, 0f), new Vector3(0f, 0f, 2f), 50f);
            Assert.Less(Vector3.Distance(new Vector3(10f, 0f, -50f), spot), 1e-4f, "on its tail, whatever the forward's length");
        }

        [Test]
        public void TheHuntsTimelinesAndTheCamerasGlide()
        {
            Assert.AreEqual(1.5f, Device.HuntPlayRate(0f), 1e-5f, "BlinkPlayRateCurve: 1.5x for a leap of nothing");
            Assert.AreEqual(1f, Device.HuntPlayRate(1f), 1e-5f, "1x at the full reach");
            Assert.AreEqual(1f, Device.HuntPlayRate(3f), 1e-5f);
            Assert.AreEqual(0f, Device.HuntVanish(0f));
            Assert.AreEqual(1f, Device.HuntVanish(1f));
            Assert.AreEqual(0.39f, Device.HuntVanish(0.733f), 0.03f, "Blink_Disappear's 0.41 at 73 %");
            Assert.AreEqual(1f, Device.HuntAppear(0f), "gone as it lands");
            Assert.AreEqual(0f, Device.HuntAppear(1f), "whole again after 0.33 s");
            Assert.AreEqual(66.667f, Device.HuntVanishMs, 1e-3f);
            Assert.AreEqual(0f, ChaseCamera.GlideAlpha(0f));
            Assert.AreEqual(0.875f, ChaseCamera.GlideAlpha(0.5f), 1e-5f, "fast at first");
            Assert.AreEqual(1f, ChaseCamera.GlideAlpha(1f));
        }

        [Test]
        public void TheStormsNumbersArePulseZaps()
        {
            Assert.AreEqual(Device.Type.RiteStorm, (Device.Type)24);
            Assert.AreEqual(100f, Device.StormChainTops * 140f, 1e-3f, "ChainRange 10000 cm");
            Assert.AreEqual(2, Device.StormCost);
            Assert.AreEqual(4000, Device.StormJamMs, "BP_Buff_Pulse's Duration 4");
            Assert.AreEqual(250, Device.StormChainMs, "ChainInterval 0.25");
            Assert.AreEqual(500, Device.StormCooldownMs);
            var go = new GameObject("jammed");
            try
            {
                var t = go.AddComponent<Target>();
                Assert.IsFalse(t.Jammed);
                t.jammedUntil = Time.time + 4f;
                Assert.IsTrue(t.Jammed, "holds its fire");
            }
            finally { Object.DestroyImmediate(go); }
        }
    }
}
