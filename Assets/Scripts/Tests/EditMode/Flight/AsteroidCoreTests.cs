// AsteroidCoreTests.cs
// Feature: CLAUDE.md "Mining": a class-A asteroid gives its ore's core (ore + 11, Novanium's 218); remake mods: an orbit's
// "ores" may be a mod's items, which have no core, so Target.CoreItem is -1 for them and mining, the mining beam and a shot
// asteroid's crate give none (ore + 11 handed out whatever item came 11 numbers after a mod ore).
// Expected values: the game's ore numbers 154-164 and 217 (OrbitLayout.Novanium) and their cores 165-175 / 218.

using GoF2Remake.Flight;
using NUnit.Framework;
using UnityEngine;

namespace GoF2Remake.Tests
{
    public class AsteroidCoreTests
    {
        static int CoreOf(int ore)
        {
            var go = new GameObject("asteroid");
            try
            {
                var t = go.AddComponent<Target>();
                t.oreItem = ore;
                return t.CoreItem;
            }
            finally { Object.DestroyImmediate(go); }
        }

        [Test]
        public void TheGamesOresGiveTheirCores()
        {
            Assert.AreEqual(165, CoreOf(154));   // Gold
            Assert.AreEqual(167, CoreOf(156));   // Iron
            Assert.AreEqual(175, CoreOf(164));   // Void Crystals: Void Essence
            Assert.AreEqual(218, CoreOf(217));   // Novanium
        }

        [Test]
        public void AnOreWithoutACoreGivesNone()
        {
            Assert.AreEqual(-1, CoreOf(233));    // a mod's ore (the first number after the game's items)
            Assert.AreEqual(-1, CoreOf(22));     // any other item
            Assert.AreEqual(-1, CoreOf(-1));     // no ore
        }
    }
}
