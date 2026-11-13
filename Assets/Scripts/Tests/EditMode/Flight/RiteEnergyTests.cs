// RiteEnergyTests.cs
// Feature: docs/notes/combat-equipment.md "Rites", Modding/README.md "Devices": Chorus's Rite energy (Flight.RiteEnergy):
// 3 pips, one back every 1 / 0.22 s, the bonus pips paid first and running out, a cost above the total refused; Rite of the
// Hunt's numbers (Flight.Device 23: Blink's range, landing and cost) and where it lands.

using GoF2Remake.Flight;
using NUnit.Framework;
using UnityEngine;

namespace GoF2Remake.Tests
{
    public class RiteEnergyTests
    {
        [Test]
        public void ThePoolStartsFullAndGrowsBackAPipEvery4Point5Seconds()
        {
            var r = new RiteEnergy();
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
        public void ACostAboveTheTotalIsRefusedAndNothingPaid()
        {
            var r = new RiteEnergy();
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
            var r = new RiteEnergy();
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
            var r = new RiteEnergy(3, 0.5f, 1f);
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
    }
}
