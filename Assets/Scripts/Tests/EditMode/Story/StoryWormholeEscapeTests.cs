// StoryWormholeEscapeTests.cs
// Step 42 in the Void (CLAUDE.md "Campaign levels built", #84; a Discord report, "Unable to use Khador Drive after
// destroying the Convoy in the last Void Mission"): the Khador Drive is refused there, so the way out is the wormhole and
// the mother ship's explosion; the refusal says so (Story.EscapesByWormhole, SpaceLevel's Navigation.JumpRefusalText).

using GoF2Remake.Data;
using NUnit.Framework;

namespace GoF2Remake.Tests
{
    public class StoryWormholeEscapeTests : StoryAreaTestBase
    {
        bool savedFreePlay;

        [SetUp]
        public void SaveFreePlay() { savedFreePlay = Session.FreePlay; Session.FreePlay = false; }

        [TearDown]
        public void RestoreFreePlay() => Session.FreePlay = savedFreePlay;

        [Test]
        public void Step42InTheVoidEscapesByTheWormhole()
        {
            Session.CampaignMission = 42;
            Assert.IsTrue(Story.EscapesByWormhole(Session.VoidOrbit));
        }

        [Test]
        public void Step42ElsewhereKeepsTheDrive()
        {
            Session.CampaignMission = 42;
            Assert.IsFalse(Story.EscapesByWormhole(98));
        }

        [Test]
        public void OtherStepsInTheVoidKeepTheDrive()
        {
            Session.CampaignMission = 41;
            Assert.IsFalse(Story.EscapesByWormhole(Session.VoidOrbit));
            Session.CampaignMission = 43;
            Assert.IsFalse(Story.EscapesByWormhole(Session.VoidOrbit));
        }

        [Test]
        public void FreePlayKeepsTheDrive()
        {
            Session.CampaignMission = 42;
            Session.FreePlay = true;
            Assert.IsFalse(Story.EscapesByWormhole(Session.VoidOrbit));
        }
    }
}
