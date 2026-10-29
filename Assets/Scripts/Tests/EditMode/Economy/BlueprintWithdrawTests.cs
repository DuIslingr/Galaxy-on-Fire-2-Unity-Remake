// BlueprintWithdrawTests.cs
// Feature: CLAUDE.md "Bar and freelance" > Blueprints, the remake's TAKE (Blueprints.Withdraw, PR #166 as fixed on
// 2026-10-28): the original has no way to take invested goods back (BluePrint has addItem and complete, nothing that
// removes), so the remake gives back only what the player put in himself (BlueprintState.playerUnits), never the story's
// pre-invested goods (UnlockFromStory: steps 34 / 58 / 104 / 141), and moneySpent goes down by what those units added to it
// (playerSpent), not by today's price. Expected values: the recipes and story amounts of blueprint_table.py (BlueprintTests);
// the refunds are arbitrary test data.

using System.Collections.Generic;
using GoF2Remake.Data;
using NUnit.Framework;

namespace GoF2Remake.Tests
{
    public class BlueprintWithdrawTests : EconomyTest
    {
        [Test]
        public void TheStorysPreInvestedGoodsCantBeTakenBack()
        {
            // 141: Chromo Plasma with 847 / 834 / 861 / 892 plasma at Var Lupra (112)
            Blueprints.UnlockFromStory(Db, 141);
            var s = Blueprints.State(Db, 210);
            int spent = s.moneySpent;
            for (int slot = 0; slot < 4; slot++)
            {
                Assert.AreEqual(0, Blueprints.Withdrawable(Db, s, slot), "slot " + slot);
                Assert.IsFalse(Blueprints.Withdraw(Db, 210, slot, 1, 112), "slot " + slot);
            }
            CollectionAssert.AreEqual(new[] { 83, 96, 69, 38 }, s.remaining);
            Assert.AreEqual(spent, s.moneySpent);
            Assert.AreEqual(112, s.station);
        }

        [Test]
        public void ThePlayersOwnUnitsCanBeTakenBackBesideTheStorys()
        {
            // 104: Gamma Shield II with 10 Hypanium (slot 3, 100 needed) at Thynome (10); the player adds 30 more
            Blueprints.UnlockFromStory(Db, 104);
            var s = Blueprints.State(Db, 206);
            int storySpent = s.moneySpent;
            Blueprints.Invest(Db, 206, 163, 30, 10, true);
            Assert.AreEqual(40, Blueprints.Invested(Db, s, 3));
            Assert.AreEqual(30, Blueprints.Withdrawable(Db, s, 3));
            Assert.IsFalse(Blueprints.Withdraw(Db, 206, 3, 5, 70), "only at the production station");
            Assert.IsFalse(Blueprints.Withdraw(Db, 206, 3, 31, 10), "not more than the player's own");
            Assert.IsTrue(Blueprints.Withdraw(Db, 206, 3, 30, 10));
            Assert.AreEqual(10, Blueprints.Invested(Db, s, 3), "the story's 10 stay");
            Assert.AreEqual(0, Blueprints.Withdrawable(Db, s, 3));
            Assert.IsFalse(Blueprints.Withdraw(Db, 206, 3, 1, 10));
            Assert.AreEqual(storySpent, s.moneySpent, "back to the story's investment");
            Assert.AreEqual(10, s.station);
            Assert.IsFalse(Blueprints.IsEmpty(s));
        }

        [Test]
        public void TheStorysInvestmentDoesntCountAsThePlayers()
        {
            Blueprints.UnlockFromStory(Db, 34);   // 50 Void Crystals into 85 at Thynome
            var s = Blueprints.State(Db, 85);
            CollectionAssert.AreEqual(new int[9], s.playerUnits);
            CollectionAssert.AreEqual(new int[9], s.playerSpent);
        }

        [Test]
        public void TheRefundIsWhatTheUnitsAddedNotTodaysPrice()
        {
            // 11's Titanium (slot 1): 10 of the player's units that added 3 000 (an older price), beside 1 unit in slot 0
            var s = new BlueprintState
            {
                item = 11, remaining = new List<int> { 0, 40, 75, 20, 20, 20 }, moneySpent = 5000, station = 70,
                playerUnits = new List<int> { 0, 10, 0, 0, 0, 0 }, playerSpent = new List<int> { 0, 3000, 0, 0, 0, 0 },
            };
            Session.Blueprints.Add(s);
            Assert.IsTrue(Blueprints.Withdraw(Db, 11, 1, 4, 70));
            Assert.AreEqual(5000 - 1200, s.moneySpent, "4 / 10 of 3 000");
            Assert.AreEqual((6, 1800), (s.playerUnits[1], s.playerSpent[1]));
            Assert.IsTrue(Blueprints.Withdraw(Db, 11, 1, 6, 70));
            Assert.AreEqual(2000, s.moneySpent, "the rest of what they added, still started");
            Assert.AreEqual((0, 0), (s.playerUnits[1], s.playerSpent[1]));
            Assert.AreEqual(70, s.station);
            Assert.AreEqual(50, s.remaining[1]);
        }

        [Test]
        public void TakingEverythingBackLeavesItUnstarted()
        {
            Blueprints.Invest(Db, 11, 155, 20, 70, true);
            Blueprints.Invest(Db, 11, 120, 5, 70, true);
            var s = Blueprints.State(Db, 11);
            Assert.IsTrue(Blueprints.Withdraw(Db, 11, 1, 20, 70));
            Assert.AreEqual(70, s.station, "slot 2's 5 units are still in");
            Assert.IsTrue(Blueprints.Withdraw(Db, 11, 2, 5, 70));
            Assert.AreEqual(0, s.moneySpent);
            Assert.AreEqual(-1, s.station, "the next unit may start it at another station");
            Assert.IsTrue(Blueprints.IsEmpty(s));
            CollectionAssert.AreEqual(new[] { 1, 50, 75, 20, 20, 20 }, s.remaining);
        }

        [Test]
        public void AFinishedRunOrALostStationForgetsThePlayersShare()
        {
            Blueprints.Invest(Db, 11, 155, 20, 70, true);
            Blueprints.Produce(Db, 11, 70);
            var s = Blueprints.State(Db, 11);
            CollectionAssert.AreEqual(new int[6], s.playerUnits);
            CollectionAssert.AreEqual(new int[6], s.playerSpent);
            Blueprints.Invest(Db, 11, 155, 20, 101, true);
            Blueprints.ResetAtStation(Db, 101);
            CollectionAssert.AreEqual(new int[6], s.playerUnits);
            Assert.AreEqual(0, Blueprints.Withdrawable(Db, s, 1));
        }

        [Test]
        public void AStateFromBeforeThePlayersShareCountsNothing()
        {
            // an old save: no playerUnits / playerSpent (JsonUtility may leave them null or empty)
            var s = new BlueprintState { item = 11, remaining = new List<int> { 0, 30, 75, 20, 20, 20 }, moneySpent = 4000, station = 70,
                                         playerUnits = null, playerSpent = new List<int>() };
            Session.Blueprints.Add(s);
            Assert.AreEqual(0, Blueprints.Withdrawable(Db, s, 1));
            Assert.IsFalse(Blueprints.Withdraw(Db, 11, 1, 1, 70));
            Assert.AreEqual(6, s.playerUnits.Count);
            Assert.AreEqual(6, s.playerSpent.Count);
            Assert.AreEqual(4000, s.moneySpent);
        }
    }
}
