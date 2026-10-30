// ModAudioCacheTests.cs
// Feature: CLAUDE.md "Mods" > Music (docs/notes/mods-weapons-audio.md; a Discord report, "replacing existing music in mod
// builder also causes crashes"). Expected behaviour: a mod's audio file is read into one clip (ModAudio.Load's cache), the
// same for every loader and every mod revision while the file is unchanged; when the file changes, goes or its mod is
// turned off, the next revision destroys the old clip (ModAudio.Sweep) and a load reads the file again. A load that ends
// after its file changed is dropped, not kept. The Mod Builder read the project again after every edit and loaded every
// track afresh, keeping the old copies, until the game ran out of memory. A replaced file always gets a new date
// (ModProject.SetAudio), so the cache sees the change even when the new file was copied with an old one.

using System;
using System.Collections.Generic;
using System.IO;
using GoF2Remake.Modding;
using NUnit.Framework;
using UnityEngine;

namespace GoF2Remake.Tests
{
    public class ModAudioCacheTests : SavesModsTest
    {
        int reads;
        Action<AudioClip> held;   // a read that hasn't finished (Hold)
        bool hold;

        [SetUp]
        public void FakeReads()
        {
            ModAudio.Clear();
            reads = 0;
            held = null;
            hold = false;
            ModAudio.Reader = (mod, file, compressed, done) =>
            {
                reads++;
                var clip = AudioClip.Create(Path.GetFileNameWithoutExtension(file), 64, 1, 8000, false);
                if (hold) held = c => done(clip);
                else done(clip);
            };
        }

        [TearDown]
        public void RealReads()
        {
            ModAudio.Clear();
            Invoke(typeof(ModAudio), "ResetStatics");
        }

        string Track()
        {
            string dir = WriteMod("mus", "t_music", "1.0", "", ("music/Station_Terraner.ogg", "one"));
            ScanAndEnable("t_music");
            return Path.Combine(dir, "music", "Station_Terraner.ogg");
        }

        AudioClip Load()
        {
            AudioClip got = null;
            ModAudio.Load(Installed("t_music"), "music/Station_Terraner.ogg", c => got = c);
            return got;
        }

        static void Changed(string file, string text)
        {
            File.WriteAllText(file, text);
            File.SetLastWriteTimeUtc(file, DateTime.UtcNow.AddMinutes(1));
        }

        [Test]
        public void AnUnchangedFileIsReadOnceForEveryRevision()
        {
            Track();
            var a = Load();
            Assert.IsNotNull(a);
            ModManager.Scan();   // a new revision (the Mod Builder's reload after an edit)
            var b = Load();
            Assert.AreSame(a, b, "the same clip");
            Assert.AreEqual(1, reads);
        }

        [Test]
        public void AChangedFileIsReadAgainAndItsOldClipGoes()
        {
            string file = Track();
            var a = Load();
            Changed(file, "two, longer");
            ModManager.Scan();
            var b = Load();
            Assert.IsNotNull(b);
            Assert.AreNotSame(a, b);
            Assert.AreEqual(2, reads);
            Assert.IsTrue(a == null, "the old clip is destroyed");
            Assert.AreEqual(1, ModAudio.CachedCount);
        }

        [Test]
        public void AModTurnedOffLosesItsClips()
        {
            Track();
            var a = Load();
            ModManager.SetEnabled("t_music", false);
            ModAudio.Sweep();
            Assert.IsTrue(a == null);
            Assert.AreEqual(0, ModAudio.CachedCount);
        }

        [Test]
        public void ALoadEndingAfterItsFileChangedIsDropped()
        {
            string file = Track();
            hold = true;
            var results = new List<AudioClip>();
            ModAudio.Load(Installed("t_music"), "music/Station_Terraner.ogg", c => results.Add(c));
            ModAudio.Load(Installed("t_music"), "music/Station_Terraner.ogg", c => results.Add(c));
            Assert.AreEqual(1, reads, "the second waits for the first");
            Changed(file, "two, longer");
            ModManager.Scan();
            ModAudio.Sweep();
            held(null);
            Assert.AreEqual(2, results.Count);
            Assert.IsTrue(results[0] == null && results[1] == null, "a stale clip isn't handed out");
            Assert.AreEqual(0, ModAudio.CachedCount);
        }

        [Test]
        public void AReplacedFileGetsANewDate()
        {
            var p = ModProject.Create("t audio date", "Tests");
            string src = Path.Combine(ModsFolder, "src.ogg");
            Directory.CreateDirectory(ModsFolder);
            File.WriteAllText(src, "x");
            File.SetLastWriteTimeUtc(src, new DateTime(2020, 1, 1, 0, 0, 0, DateTimeKind.Utc));
            string path = p.SetAudio(ModProject.MusicFolder, "Station_Terraner", src);
            var date = File.GetLastWriteTimeUtc(Path.Combine(p.Folder, path));
            Assert.Greater(date, DateTime.UtcNow.AddMinutes(-5), "not the source's old date");
        }
    }
}
