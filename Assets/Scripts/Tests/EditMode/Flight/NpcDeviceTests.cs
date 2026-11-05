// NpcDeviceTests.cs
// Feature: docs/notes/combat-equipment.md "Boss devices", Modding/README.md "Most Wanted": a criminal's device (Flight.NpcDevice,
// after GoF3's boss devices): its events fire it (a hit, an interval x its chance) while its conditions on the player hold
// (range, angles); without an event the conditions alone; then its run, then its cooldown; the flash goes off after its
// delay, weaker the further the player looks away; the shields stop only their side; the bomb spreader's mines.

using GoF2Remake.Flight;
using NUnit.Framework;

namespace GoF2Remake.Tests
{
    public class NpcDeviceTests
    {
        static NpcDeviceState.View Near(float distance = 1000f, float offNose = 0f, float facing = 0f, bool hit = false) =>
            new NpcDeviceState.View { playerNear = true, distance = distance, offNoseDeg = offNose, playerFacingDeg = facing, hit = hit };

        [Test]
        public void AHitFiresAnOnHitDeviceThenItRunsAndCoolsDown()
        {
            var s = new NpcDeviceState(new NpcDeviceSpec { kind = NpcDeviceSpec.Kind.BackShield, onHit = true, durationMs = 1000f, cooldownMs = 2000f });
            Assert.IsFalse(s.Step(100f, Near(), 0f, out _), "no hit: nothing");
            Assert.IsTrue(s.Step(100f, Near(hit: true), 0f, out _));
            Assert.IsTrue(s.Active);
            Assert.IsFalse(s.Step(500f, Near(hit: true), 0f, out _), "not again while it runs");
            Assert.IsFalse(s.Step(600f, Near(hit: true), 0f, out _), "the run ends");
            Assert.IsFalse(s.Active);
            Assert.IsFalse(s.Step(1500f, Near(hit: true), 0f, out _), "cooling down");
            Assert.IsTrue(s.Step(600f, Near(hit: true), 0f, out _), "ready again");
        }

        [Test]
        public void AnIntervalRollsItsChanceAndTheConditionsMustHold()
        {
            var spec = new NpcDeviceSpec { kind = NpcDeviceSpec.Kind.FrontShield, everyMs = 1000f, chance = 0.5f, aheadDeg = 30f, durationMs = 10f, cooldownMs = 0f };
            var s = new NpcDeviceState(spec);
            Assert.IsFalse(s.Step(900f, Near(), 0f, out _), "the interval not up");
            Assert.IsFalse(s.Step(200f, Near(), 0.7f, out _), "the roll failed");
            Assert.IsFalse(s.Step(1000f, Near(offNose: 45f), 0.1f, out _), "the player outside its 30 degrees");
            Assert.IsTrue(s.Step(1000f, Near(offNose: 20f), 0.1f, out _));
            var none = new NpcDeviceState(spec);
            Assert.IsFalse(none.Step(1100f, new NpcDeviceState.View { offNoseDeg = 0f }, 0f, out _), "no player to use it on");
        }

        [Test]
        public void WithoutAnEventTheConditionsAloneFireIt()
        {
            var s = new NpcDeviceState(new NpcDeviceSpec { kind = NpcDeviceSpec.Kind.RadarJammer, rangeMax = 1500f, cooldownMs = 20000f });
            Assert.IsFalse(s.Step(16f, Near(distance: 2000f), 0f, out _), "out of range");
            Assert.IsTrue(s.Step(16f, Near(distance: 1400f), 0f, out _));
            var o = new NpcDeviceState(new NpcDeviceSpec { kind = NpcDeviceSpec.Kind.Teleport, notAheadDeg = 60f, facingDeg = 80f });
            Assert.IsFalse(o.Step(16f, Near(offNose: 30f), 0f, out _), "the player ahead of it");
            Assert.IsFalse(o.Step(16f, Near(offNose: 90f, facing: 100f), 0f, out _), "the player not looking at it");
            Assert.IsTrue(o.Step(16f, Near(offNose: 90f, facing: 40f), 0f, out _));
        }

        [Test]
        public void TheFlashGoesOffAfterItsDelayAsStrongAsThePlayerLooksAtIt()
        {
            var s = new NpcDeviceState(new NpcDeviceSpec { kind = NpcDeviceSpec.Kind.FlashGrenade, delayMs = 3000f, durationMs = 7000f, strength = 0.8f });
            Assert.IsTrue(s.Step(16f, Near(), 0f, out bool flashed));
            Assert.IsFalse(flashed);
            Assert.IsTrue(s.Pending);
            s.Step(2000f, Near(), 0f, out flashed);
            Assert.IsFalse(flashed);
            s.Step(1000f, Near(), 0f, out flashed);
            Assert.IsTrue(flashed, "3 s after the throw");
            Assert.AreEqual(0.8f, s.FlashOpacity(0f), 1e-4f);
            Assert.AreEqual(0.4f, s.FlashOpacity(60f), 1e-4f);
            Assert.AreEqual(0f, s.FlashOpacity(95f), "looking away");
        }

        [Test]
        public void TheBombSpreaderDropsAMineAtTheStartAndThenEveryInterval()
        {
            var s = new NpcDeviceState(new NpcDeviceSpec { kind = NpcDeviceSpec.Kind.BombSpreader, durationMs = 6000f, bombEveryMs = 1200f });
            Assert.IsTrue(s.Step(16f, Near(), 0f, out _));
            int bombs = s.DueBombs;
            Assert.AreEqual(1, bombs, "one at the start");
            for (int i = 0; i < 400; i++) { s.Step(20f, Near(), 0f, out _); bombs += s.DueBombs; }
            Assert.AreEqual(5, bombs, "0, 1.2, 2.4, 3.6, 4.8 s: none at the end of its 6 s");
            Assert.IsFalse(s.Active);
        }

        [Test]
        public void AShieldStopsOnlyItsSideAndOnlyWhileItRuns()
        {
            var front = new NpcDeviceState(new NpcDeviceSpec { kind = NpcDeviceSpec.Kind.FrontShield, durationMs = 1000f, shieldDeg = 60f });
            Assert.AreEqual(1f, front.ShieldPass(0f), "not running");
            front.Step(16f, Near(), 0f, out _);
            Assert.AreEqual(0f, front.ShieldPass(10f), "head on");
            Assert.AreEqual(1f, front.ShieldPass(90f), "from the side");
            var back = new NpcDeviceState(new NpcDeviceSpec { kind = NpcDeviceSpec.Kind.BackShield, durationMs = 1000f, shieldDeg = 60f, blockShare = 0.75f });
            back.Step(16f, Near(), 0f, out _);
            Assert.AreEqual(0.25f, back.ShieldPass(170f), 1e-4f, "from behind, 75 % stopped");
            Assert.AreEqual(1f, back.ShieldPass(10f), "head on");
        }
    }
}
