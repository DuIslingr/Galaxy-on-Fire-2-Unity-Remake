// GraphQuestRepeatTests.cs
// Feature: CLAUDE.md "Repeatable story missions" (docs/notes/event-graphs.md: a quest with "repeat" minutes waits in
// Session.GraphQuestRepeats, name -> the PlaySeconds it may start again, saved as graphQuestRepeats "name|seconds").
// Expected values: the remake defines the feature (review of #168): the save round trip keeps each name and time, a new
// game clears them.

using GoF2Remake.Data;
using NUnit.Framework;

namespace GoF2Remake.Tests
{
    public class GraphQuestRepeatTests : StoryAreaTestBase
    {
        [Test]
        public void TheRepeatTimesAreSavedAndRestored()
        {
            Session.StationIndex = 55;
            Session.GraphQuestRepeats["dreadnought_raid"] = 5400.5f;
            Session.GraphQuestRepeats["convoy|odd name"] = 120f;   // a bar in the name: split at the last one
            Session.GraphQuestsDone.Add("prologue_side");
            Assert.IsTrue(SaveGame.Save(8));
            Session.ResetNewGame();
            Assert.AreEqual(0, Session.GraphQuestRepeats.Count, "a new game has none");
            Assert.IsTrue(SaveGame.Load(8));
            Assert.AreEqual(2, Session.GraphQuestRepeats.Count);
            Assert.AreEqual(5400.5f, Session.GraphQuestRepeats["dreadnought_raid"], 1e-3f);
            Assert.AreEqual(120f, Session.GraphQuestRepeats["convoy|odd name"], 1e-3f);
            Assert.IsFalse(Session.GraphQuestsDone.Contains("dreadnought_raid"), "waiting to come again, not done for good");
            Assert.IsTrue(Session.GraphQuestsDone.Contains("prologue_side"));
        }

        [Test]
        public void ASaveWithoutThemLoadsNone()
        {
            Session.StationIndex = 55;
            Assert.IsTrue(SaveGame.Save(9));
            Session.GraphQuestRepeats["left_over"] = 10f;
            Assert.IsTrue(SaveGame.Load(9));
            Assert.AreEqual(0, Session.GraphQuestRepeats.Count);
        }
    }
}
