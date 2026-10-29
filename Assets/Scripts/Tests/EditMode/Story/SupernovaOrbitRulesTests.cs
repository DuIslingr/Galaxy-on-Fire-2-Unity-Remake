// SupernovaOrbitRulesTests.cs
// Feature: CLAUDE.md "Story rules" (docs/notes/supernova.md: RequirementRefusal) and the star map's visited tick
// (docs/notes/star-map.md: SpaceLevel.VisitedInSpace). From the original:
//   MGame::OnTouchBegin / StarMap::OnTouchEnd at step 0x8b (139): ship 0x2a (the Vol Noor) passes as it is; another ship
//     passes only as a Vossk ship (DAT_0025454c = race 1) with the Vossk Signature (0xbe = 190), else text 0xc8f (3215)
//   MGame::OnInitialize 0x1a76a8: Station::visit in space for stations 109, 110, 132-134 (mask 0x3800003 from 0x6d),
//     102-104, and 111 (0x6f) from campaign step 0x5e; no other station (112 not)

using GoF2Remake.Data;
using GoF2Remake.World;
using NUnit.Framework;

namespace GoF2Remake.Tests
{
    public class SupernovaOrbitRulesTests : StoryAreaTestBase
    {
        static int OtherVosskShip()
        {
            for (int i = 0; i < Shop.ShipRace.Length; i++) if (i != 42 && Shop.ShipRace[i] == 1) return i;
            Assert.Fail("no Vossk ship");
            return -1;
        }

        static int TerranShip()
        {
            for (int i = 0; i < Shop.ShipRace.Length; i++) if (Shop.ShipRace[i] == 0) return i;
            Assert.Fail("no Terran ship");
            return -1;
        }

        [Test]
        public void Step139TheVolNoorNeedsNoSignature()
        {
            Story.StartAtMission(Db, 139);
            int target = Story.Mission.station;
            Session.Equipment.RemoveAll(e => e.item == 190);
            Session.ShipIndex = 42;
            Assert.AreEqual(-1, Story.RequirementRefusal(Db, target), "the Vol Noor passes as it is");
            Session.ShipIndex = OtherVosskShip();
            Assert.AreEqual(3215, Story.RequirementRefusal(Db, target), "another Vossk ship needs the signature");
            Session.Equipment.Add(new ItemStack(190, 1));
            Assert.AreEqual(-1, Story.RequirementRefusal(Db, target), "with it");
            Session.ShipIndex = TerranShip();
            Assert.AreEqual(3215, Story.RequirementRefusal(Db, target), "not a Vossk ship: refused even with the signature");
            Assert.AreEqual(-1, Story.RequirementRefusal(Db, target == 79 ? 78 : 79), "only the step's target is checked");
        }

        [TestCase(109, 0x5d, true)]
        [TestCase(110, 0x5d, true)]
        [TestCase(111, 0x5d, false)]
        [TestCase(111, 0x5e, true)]
        [TestCase(103, 0x10, true)]
        [TestCase(133, 0x10, true)]
        [TestCase(112, 0x5e, false)]
        [TestCase(112, 162, false)]
        [TestCase(78, 0x5e, false)]
        public void OrbitsVisitedWhenFlownInto(int station, int step, bool visited)
        {
            Session.FreePlay = false;
            Session.CampaignMission = step;
            Assert.AreEqual(visited, SpaceLevel.VisitedInSpace(station));
        }
    }
}
