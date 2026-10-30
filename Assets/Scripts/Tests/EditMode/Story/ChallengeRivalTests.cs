// ChallengeRivalTests.cs
// Feature: CLAUDE.md "Freelance" (docs/notes/bar-and-freelance.md; a player's suggestion, KiritoJPK 2026-10-30). Expected
// behaviour: the original's rival only ever says 859 "See you outside, Mr. Maxwell." at the bar once the Challenge is
// accepted; the remake's rival remembers how the contest ended (Freelance.RecordChallenge, Agent.challengeResult) and
// says one of four lines about it instead: a compliment when the player won, a jibe when the rival did. Before the end
// (or with the rival gone from the bar) it is 859 as before.

using System.Linq;
using GoF2Remake.Data;
using NUnit.Framework;

namespace GoF2Remake.Tests
{
    public class ChallengeRivalTests : StoryAreaTestBase
    {
        const int Station = 55;

        /// <summary>A rival at the bar of 'Station' whose Challenge the player accepted, and that mission running.</summary>
        static Agent AcceptedRival()
        {
            var rival = new Agent { name = "Jack Rival", race = 0, station = Station, offer = AgentOffer.Mission, known = true, accepted = true };
            rival.mission = new FreelanceMission
            {
                type = MissionType.Challenge, clientName = rival.name, clientRace = 0, clientStation = Station, target = Station, reward = 5000,
            };
            var stock = new StationStock { station = Station };
            stock.agents.Add(rival);
            Session.RecentStations.Add(stock);
            Session.FreelanceMission = rival.mission.Clone();
            return rival;
        }

        static string ChatText(Agent rival)
        {
            var chat = new LoungeChat(Db, rival, Station, null);
            chat.Start();
            return chat.Text;
        }

        [Test]
        public void AWonChallengesRivalPaysAComplimentAtTheBar()
        {
            var rival = AcceptedRival();
            Freelance.Succeed(true);
            Assert.AreEqual(Agent.PlayerWon, rival.challengeResult);
            for (int i = 0; i < 20; i++) CollectionAssert.Contains(Freelance.RivalLines(Agent.PlayerWon), ChatText(rival));
        }

        [Test]
        public void ALostChallengesRivalJibesAtTheBar()
        {
            var rival = AcceptedRival();
            Session.Credits = 10000;
            Freelance.Fail();
            Assert.AreEqual(Agent.RivalWon, rival.challengeResult);
            Assert.AreEqual(5000, Session.Credits, "the wager is still lost");
            for (int i = 0; i < 20; i++) CollectionAssert.Contains(Freelance.RivalLines(Agent.RivalWon), ChatText(rival));
        }

        [Test]
        public void BeforeTheEndTheRivalStillSaysSeeYouOutside()
        {
            var rival = AcceptedRival();
            Assert.AreEqual(Localization.Get(859), ChatText(rival));
        }

        [Test]
        public void AnotherMissionsEndLeavesTheRivalAlone()
        {
            var rival = AcceptedRival();
            Session.FreelanceMission = new FreelanceMission { type = MissionType.Courier, clientName = "Someone Else", clientStation = Station };
            Freelance.Succeed(true);
            Assert.AreEqual(Agent.ChallengeNone, rival.challengeResult);
        }

        [Test]
        public void FourLinesForEachOutcomeAndNoneWithout()
        {
            foreach (int result in new[] { Agent.PlayerWon, Agent.RivalWon })
            {
                var lines = Freelance.RivalLines(result);
                Assert.AreEqual(4, lines.Count);
                CollectionAssert.AllItemsAreNotNull(lines);
                CollectionAssert.AllItemsAreUnique(lines);
            }
            CollectionAssert.IsEmpty(Freelance.RivalLines(Agent.ChallengeNone));
            CollectionAssert.IsEmpty(Freelance.RivalLines(Agent.PlayerWon).Intersect(Freelance.RivalLines(Agent.RivalWon)));
        }
    }
}
