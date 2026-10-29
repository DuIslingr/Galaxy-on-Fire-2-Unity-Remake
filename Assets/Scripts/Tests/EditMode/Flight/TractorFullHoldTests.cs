// TractorFullHoldTests.cs
// Feature: CLAUDE.md "NPCs and combat" > the tractor beam (CombatRadar.Capture, #176). Expected behaviour (the remake
// defines it; the original lost the crate and its loot): a crate tractored in while the hold is full stays in space with
// its loot, let go of ("Cargo hold is full.", 322), is not locked again while it stays in the box, and costs no standing;
// with room for only part of it (5 t free, 10 t in the crate) the 5 t go in the hold and the other 5 t stay in the crate.

using System.Collections.Generic;
using System.Reflection;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using NUnit.Framework;
using UnityEngine;

namespace GoF2Remake.Tests
{
    public class TractorFullHoldTests : SandboxTest
    {
        const BindingFlags Private = BindingFlags.NonPublic | BindingFlags.Instance;
        readonly List<GameObject> made = new List<GameObject>();

        [TearDown]
        public void CleanUp()
        {
            foreach (var go in made) if (go != null) Object.DestroyImmediate(go);
            made.Clear();
        }

        static int CargoItem(Database db) => db.Items.Find(i => i.TypeId != 1 && !i.modded).index;   // not a launcher's missiles

        /// <summary>A radar as the flight level's (its database and beam sound), its HUD messages into 'messages'.</summary>
        CombatRadar Radar(Database db, List<string> messages)
        {
            var go = new GameObject("radar");
            made.Add(go);
            var radar = go.AddComponent<CombatRadar>();
            typeof(CombatRadar).GetField("db", Private).SetValue(radar, db);
            typeof(CombatRadar).GetField("beamLoop", Private).SetValue(radar, go.AddComponent<AudioSource>());
            radar.Message += (text, colour, kind) => messages.Add(text);
            return radar;
        }

        Crate PulledCrate(int item, int amount)
        {
            var go = new GameObject("crate");
            made.Add(go);
            var crate = go.AddComponent<Crate>();
            crate.loot.Add(new ItemStack(item, amount));
            crate.pulled = true;
            return crate;
        }

        static void Capture(CombatRadar radar, Crate crate) =>
            typeof(CombatRadar).GetMethod("Capture", Private).Invoke(radar, new object[] { crate });

        [Test]
        public void ACrateStaysInSpaceWhenTheHoldIsFull()
        {
            var db = Database.Shared;
            int item = CargoItem(db);
            Session.Cargo.Add(new ItemStack(item, Shop.FreeCargo(db)));
            Assert.AreEqual(0, Shop.FreeCargo(db), "the hold is full");
            int cargo = Shop.CargoLoad();
            var messages = new List<string>();
            var radar = Radar(db, messages);
            var crate = PulledCrate(item, 5);
            var standing = (int[])Session.Standing.Clone();

            Capture(radar, crate);
            Assert.IsTrue(crate != null, "the crate stays");
            Assert.AreEqual(5, crate.loot[0].amount, "with all its loot");
            Assert.IsFalse(crate.pulled, "let go of");
            Assert.AreEqual(cargo, Shop.CargoLoad(), "nothing went in the hold");
            Assert.AreEqual(new[] { Localization.Get(322) }, messages.ToArray());
            Assert.AreSame(crate, typeof(CombatRadar).GetField("refusedCrate", Private).GetValue(radar), "not locked again at once");
            Assert.AreEqual(standing, Session.Standing, "no standing lost for it");
        }

        [Test]
        public void WhatDoesntFitStaysInTheCrate()
        {
            var db = Database.Shared;
            int item = CargoItem(db);
            Session.Cargo.Add(new ItemStack(item, Shop.FreeCargo(db) - 5));
            Assert.AreEqual(5, Shop.FreeCargo(db), "5 t free");
            var messages = new List<string>();
            var radar = Radar(db, messages);
            var crate = PulledCrate(item, 10);

            Capture(radar, crate);
            Assert.AreEqual(0, Shop.FreeCargo(db), "5 t went in the hold");
            Assert.IsTrue(crate != null, "the crate stays");
            Assert.AreEqual(5, crate.loot[0].amount, "with the other 5 t");
            Assert.IsFalse(crate.pulled);
            Assert.AreEqual(Localization.Get(322), messages[messages.Count - 1], "the hold is full");
        }
    }
}
