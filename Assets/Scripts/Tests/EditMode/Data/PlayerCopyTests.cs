// PlayerCopyTests.cs
// Feature: docs/notes/player-assets.md "The content layer": the game's tables and text read from the player's own copy of
// Galaxy on Fire 2 once it is converted (GameContent), with nothing of the original's in the build. Needs a converted copy:
// $GOF2_ORIGINAL_CACHE, else ~/GOF2UnityRemakeMods/aeitest/cache_android (Reference/tools/player_assets/convert on the
// Android XAPK); without one the tests are ignored.

using System;
using System.IO;
using System.Linq;
using GoF2Remake.Data;
using NUnit.Framework;

namespace GoF2Remake.Tests
{
    public class PlayerCopyTests : SandboxTest
    {
        static string Cache => Environment.GetEnvironmentVariable("GOF2_ORIGINAL_CACHE")
            ?? Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.UserProfile), "GOF2UnityRemakeMods", "aeitest", "cache_android");

        string language;

        [SetUp]
        public void UseTheConvertedCopy()
        {
            if (!File.Exists(Path.Combine(Cache, "_manifest.tsv"))) Assert.Ignore("no converted copy of the game at " + Cache);
            GameContent.Root = Cache;
            language = Localization.Language;
        }

        [TearDown]
        public void Back()
        {
            GameContent.Root = null;
            if (language != null) Localization.Load(language, LanguageTables.TableFor(language));
        }

        [Test]
        public void TheDatabaseComesFromTheConvertedCopy()
        {
            Assert.IsTrue(GameContent.Installed);
            var db = Database.Load();
            Assert.GreaterOrEqual(db.Items.Count, 233, "the original's 233 items (and the base content's after them)");
            Assert.AreEqual("Nirai Impulse EX 1", db.Items[0].name);
            Assert.GreaterOrEqual(db.Ships.Count, 64);
            Assert.AreEqual(34, db.Systems.Count);
            Assert.GreaterOrEqual(db.Stations.Count, 100);
            Assert.IsNotEmpty(AgentData.StoryAgents, "agents.json");
            StringAssert.StartsWith("[", GameContent.Text("GoF2Data/ticker"), "ticker.json");
        }

        [Test]
        public void TheAssembledObjectsComeFromTheConvertedCopy()
        {
            // Every assembly of assemblies.json built from the converted copy (OriginalAssemblies), as AssembledObject.LoadPrefab
            // gives it in a build without the originals. Those whose models the remake remodelled come from the common pack
            // (not installed here): listed, not failed, as long as most build.
            var db = Database.Load();
            var failed = new System.Collections.Generic.List<string>();
            int built = 0, renderers = 0;
            foreach (var e in db.Assemblies)
            {
                if (e.pack == GoF2Remake.Modding.ModShips.Pack) continue;
                var t = GoF2Remake.Visuals.OriginalAssemblies.Template(e);
                if (t == null) { failed.Add(e.name); continue; }
                built++;
                int r = t.GetComponentsInChildren<UnityEngine.Renderer>(true).Length;
                if (r == 0) failed.Add(e.name + " (no renderers)");
                renderers += r;
            }
            UnityEngine.Debug.Log($"PlayerCopyTests: {built} assemblies built ({renderers} renderers); not built: {string.Join(", ", failed)}");
            Assert.Greater(built, db.Assemblies.Count * 9 / 10, "nearly every assembly builds from the copy; not built: " + string.Join(", ", failed));
        }

        [Test]
        public void TheSoundsComeFromTheConvertedCopy()
        {
            // the story table's voice lines refilled from the copy (OriginalRefs), decoded from its MP3 (NLayer)
            // (a line at a time, when it is asked for: OriginalRefs.Entry)
            var story = StoryAssets.Load();
            Assert.IsNotNull(story);
            var names = story.VoiceNames().Take(25).ToList();
            Assert.AreEqual(25, names.Count);
            foreach (var n in names)
            {
                var line = story.OriginalVoice(n, false);
                Assert.IsNotNull(line, n);
                Assert.Greater(line.samples, 1000, n);
            }
            // an effect from its WAV (IMA ADPCM in the bank)
            var fx = OriginalAudio.Get("Audio/SFX_GENERAL/Button_Push_v06.ogg");
            Assert.IsNotNull(fx); Assert.Greater(fx.samples, 100);
            // a music track: longer than OriginalAudio.StreamSeconds, so streamed
            var music = OriginalAudio.Get("Audio/MUSIC/Space_Battle_Medium.ogg");
            Assert.IsNotNull(music);
            Assert.Greater(music.length, OriginalAudio.StreamSeconds);
        }

        [Test]
        public void TheTextComesFromTheConvertedCopy()
        {
            Assert.IsNotNull(GameContent.LanguageText("en"));
            Localization.Load("en", null);   // no table asset: the converted copy's
            Assert.AreEqual("Nirai Impulse EX 1", Localization.Get(1274), "item 0's name");
            Assert.AreEqual(Database.Load().Ships[0].name, Localization.Get(913), "ship 0's name");
        }
    }
}
