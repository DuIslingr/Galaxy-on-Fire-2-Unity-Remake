// CruiseDriveTests.cs
// The remake's cruise drive rules (Core/CruiseDrive.cs; docs/notes/navigation.md "Cruise drive"): a fresh press charges
// for the charge time, releasing or a block during the charge ends it, the charge pays one leg of energy cells (x2 on
// Extreme, none with the cheat) or is refused, every leg's distance pays again and runs out of cells, the speed factor
// ramps up over 800 ms and down over 1200 ms (smoothstep) and eases down from 40000 to 8000 units of a hull ahead, which
// drops the cruise, as do the locked landmark within 20000 units, hostiles, a hit and the button released; a drop needs
// a fresh press. Expected numbers from the class's constants and the example mod's Khador Slipstream (x4, 60000 units a
// leg, 2000 ms, 1 cell).

using GoF2Remake.Flight;
using NUnit.Framework;

namespace GoF2Remake.Tests
{
    public class CruiseDriveTests
    {
        const float None = float.MaxValue;

        static CruiseDrive Slipstream(bool extreme = false) => new CruiseDrive(300, 400, 60000, 2000, 1, extreme);

        /// <summary>One frame with the button held and nothing in the way.</summary>
        static CruiseDrive.Event Step(CruiseDrive d, float dtMs, bool held = true, float moved = 0f, int cells = 10,
                                      CruiseDrive.Stop blocked = CruiseDrive.Stop.None, float obstacle = None, float landmark = None, bool free = false)
            => d.Update(dtMs, held, blocked, moved, obstacle, landmark, cells, free);

        static CruiseDrive Engaged(int cells = 10, bool extreme = false)
        {
            var d = Slipstream(extreme);
            Assert.AreEqual(CruiseDrive.Event.ChargeStarted, Step(d, 0f, cells: cells));
            Assert.AreEqual(CruiseDrive.Event.Engaged, Step(d, 2000f, cells: cells));
            return d;
        }

        [Test]
        public void TheConstructorReadsTheItemsNumbers()
        {
            var d = Slipstream();
            Assert.AreEqual(300, d.item);
            Assert.AreEqual(4f, d.speedFactor);
            Assert.AreEqual(60000, d.legUnits);
            Assert.AreEqual(2000, d.chargeMs);
            Assert.AreEqual(1, d.cellsPerLeg);
            Assert.AreEqual(2, Slipstream(true).cellsPerLeg, "Extreme pays double, like a Khador jump");
            Assert.AreEqual(1f, new CruiseDrive(300, 50, 0, -5, -1, false).speedFactor, "no slower than normal flight");
        }

        [Test]
        public void StartsOff()
        {
            var d = Slipstream();
            Assert.AreEqual(CruiseDrive.Phase.Off, d.State);
            Assert.AreEqual(1f, d.Factor);
            Assert.AreEqual(0f, d.ChargeRate);
            Assert.IsFalse(d.Charging);
            Assert.IsFalse(d.Cruising);
        }

        [Test]
        public void AFreshPressStartsTheCharge()
        {
            var d = Slipstream();
            Assert.AreEqual(CruiseDrive.Event.None, Step(d, 16f, held: false));
            Assert.AreEqual(CruiseDrive.Event.ChargeStarted, Step(d, 16f));
            Assert.IsTrue(d.Charging);
            Assert.AreEqual(CruiseDrive.Event.None, Step(d, 1000f));
            Assert.AreEqual(0.5f, d.ChargeRate, 1e-4f, "the press's own frame doesn't count");
            Assert.AreEqual(1f, d.Factor, "no speed while charging");
        }

        [Test]
        public void ReleasingDuringTheChargeEndsIt()
        {
            var d = Slipstream();
            Step(d, 0f);
            Step(d, 1000f);
            Assert.AreEqual(CruiseDrive.Event.Stopped, Step(d, 16f, held: false));
            Assert.AreEqual(CruiseDrive.Phase.Off, d.State);
            Assert.AreEqual(CruiseDrive.Stop.Released, d.LastStop);
            Assert.AreEqual(0f, d.Timer);
        }

        [Test]
        public void TheChargePaysOneLeg()
        {
            var d = Slipstream();
            Step(d, 0f);
            Assert.AreEqual(CruiseDrive.Event.None, Step(d, 1999f));
            Assert.AreEqual(0, d.CellsDue);
            Assert.AreEqual(CruiseDrive.Event.Engaged, Step(d, 1f));
            Assert.IsTrue(d.Cruising);
            Assert.AreEqual(1, d.CellsDue);
            Assert.AreEqual(60000f, d.LegLeft);
            Assert.AreEqual(CruiseDrive.Event.None, Step(d, 16f));
            Assert.AreEqual(0, d.CellsDue, "the cells are due once");
        }

        [Test]
        public void ExtremePaysTwoCellsALeg()
        {
            var d = Engaged(extreme: true);
            Assert.AreEqual(2, d.CellsDue);
        }

        [Test]
        public void TooFewCellsRefuseTheCharge()
        {
            var d = Slipstream(true);   // 2 cells a leg
            Step(d, 0f, cells: 1);
            Assert.AreEqual(CruiseDrive.Event.Refused, Step(d, 2000f, cells: 1));
            Assert.AreEqual(CruiseDrive.Phase.Off, d.State);
            Assert.AreEqual(CruiseDrive.Stop.NoCells, d.LastStop);
            Assert.AreEqual(0, d.CellsDue);
        }

        [Test]
        public void TheCheatMakesItFree()
        {
            var d = Slipstream();
            Step(d, 0f, cells: 0, free: true);
            Assert.AreEqual(CruiseDrive.Event.Engaged, Step(d, 2000f, cells: 0, free: true));
            Assert.AreEqual(0, d.CellsDue);
            Assert.AreEqual(CruiseDrive.Event.None, Step(d, 16f, moved: 200000f, cells: 0, free: true), "legs pass without cells");
            Assert.IsTrue(d.Cruising);
            Assert.Greater(d.LegLeft, 0f);
        }

        [Test]
        public void EveryLegPaysAgain()
        {
            var d = Engaged();
            Assert.AreEqual(CruiseDrive.Event.None, Step(d, 16f, moved: 59999f));
            Assert.AreEqual(1f, d.LegLeft, 1e-3f);
            Assert.AreEqual(CruiseDrive.Event.LegPaid, Step(d, 16f, moved: 1f));
            Assert.AreEqual(1, d.CellsDue);
            Assert.AreEqual(60000f, d.LegLeft, 1e-3f);
            // A long frame can cross two legs at once.
            Assert.AreEqual(CruiseDrive.Event.LegPaid, Step(d, 16f, moved: 120000f));
            Assert.AreEqual(2, d.CellsDue);
            Assert.AreEqual(60000f, d.LegLeft, 1e-3f);
        }

        [Test]
        public void OutOfCellsDropsAtTheLegsEnd()
        {
            var d = Engaged(cells: 1);
            Assert.AreEqual(CruiseDrive.Event.None, Step(d, 16f, moved: 30000f, cells: 0));
            Assert.AreEqual(CruiseDrive.Event.Stopped, Step(d, 16f, moved: 30000f, cells: 0));
            Assert.AreEqual(CruiseDrive.Stop.NoCells, d.LastStop);
            Assert.AreEqual(CruiseDrive.Phase.Off, d.State);
        }

        [Test]
        public void TheSpeedRampsUpAndDown()
        {
            var d = Engaged();
            Assert.AreEqual(0f, d.Level, "the engaging frame's dt was the charge's");
            Step(d, 400f);
            Assert.AreEqual(0.5f, d.Level, 1e-4f);
            Assert.AreEqual(1f + 3f * 0.5f, d.Factor, 1e-3f, "smoothstep(0.5) = 0.5");
            Step(d, 400f);
            Assert.AreEqual(4f, d.Factor, 1e-4f);
            Step(d, 16f, held: false);
            Assert.AreEqual(CruiseDrive.Phase.Off, d.State);
            Step(d, 600f - 16f, held: false);
            Assert.AreEqual(0.5f, d.Level, 1e-3f, "down over 1200 ms");
            Step(d, 600f, held: false);
            Assert.AreEqual(1f, d.Factor, 1e-4f);
        }

        [Test]
        public void AHullAheadSlowsThenDropsTheCruise()
        {
            var d = Engaged();
            Step(d, 800f);
            Assert.AreEqual(4f, d.Factor, 1e-4f);
            Step(d, 16f, obstacle: 24000f);   // halfway between 40000 and 8000
            Assert.AreEqual(0.5f, d.Proximity, 1e-4f);
            Assert.AreEqual(2.5f, d.Factor, 1e-3f);
            Assert.AreEqual(CruiseDrive.Event.Stopped, Step(d, 16f, obstacle: 7999f));
            Assert.AreEqual(CruiseDrive.Stop.Obstacle, d.LastStop);
            // Holding on after the drop does nothing: a fresh press is needed, and not into the hull.
            Assert.AreEqual(CruiseDrive.Event.None, Step(d, 16f, obstacle: 7999f));
            Step(d, 16f, held: false, obstacle: 7999f);
            Assert.AreEqual(CruiseDrive.Event.None, Step(d, 16f, obstacle: 7999f), "a press at a hull doesn't charge");
            Assert.AreEqual(CruiseDrive.Event.None, Step(d, 16f, held: false));
            Assert.AreEqual(CruiseDrive.Event.ChargeStarted, Step(d, 16f));
        }

        [Test]
        public void TheLockedLandmarkCloseByDropsIt()
        {
            var d = Engaged();
            Assert.AreEqual(CruiseDrive.Event.None, Step(d, 16f, landmark: 20000f));
            Assert.AreEqual(CruiseDrive.Event.Stopped, Step(d, 16f, landmark: 19999f));
            Assert.AreEqual(CruiseDrive.Stop.Arrived, d.LastStop);
        }

        [Test]
        public void ABlockDropsItWithItsReason()
        {
            var d = Engaged();
            Assert.AreEqual(CruiseDrive.Event.Stopped, Step(d, 16f, blocked: CruiseDrive.Stop.Hostiles));
            Assert.AreEqual(CruiseDrive.Stop.Hostiles, d.LastStop);
            d = Slipstream();
            Step(d, 0f);
            Assert.AreEqual(CruiseDrive.Event.Stopped, Step(d, 500f, blocked: CruiseDrive.Stop.Blocked), "a block ends the charge too");
            Assert.AreEqual(CruiseDrive.Stop.Blocked, d.LastStop);
            Assert.AreEqual(CruiseDrive.Event.None, Step(d, 16f, blocked: CruiseDrive.Stop.Blocked), "no charge while blocked");
        }

        [Test]
        public void AHitInterrupts()
        {
            var d = Slipstream();
            Assert.IsFalse(d.Interrupt(), "nothing ran");
            d = Engaged();
            Assert.IsTrue(d.Interrupt());
            Assert.AreEqual(CruiseDrive.Phase.Off, d.State);
            Assert.AreEqual(CruiseDrive.Stop.Hit, d.LastStop);
            Assert.AreEqual(CruiseDrive.Event.None, Step(d, 16f), "still held: no new charge");
        }

        [Test]
        public void ProximityStaysWhileTheRampRunsDown()
        {
            var d = Engaged();
            Step(d, 800f, obstacle: 24000f);
            Assert.AreEqual(0.5f, d.Proximity, 1e-4f);
            Step(d, 16f, held: false);
            Step(d, 16f, held: false, obstacle: None);
            Assert.AreEqual(0.5f, d.Proximity, 1e-4f, "not refreshed once off");
        }
    }
}
