// OriginalSetupTests.cs
// Feature: docs/notes/player-assets.md "First start": a zip stored in a zip (an XAPK's OBB) read where it lies
// (ZipSlice), and the conversion's checks: a file that isn't Galaxy on Fire 2 installs nothing and leaves no half-made
// cache behind.

using System;
using System.IO;
using System.IO.Compression;
using System.Text;
using System.Threading;
using GoF2Remake.Data;
using NUnit.Framework;

namespace GoF2Remake.Tests
{
    public class OriginalSetupTests : SandboxTest
    {
        static byte[] InnerZip()
        {
            using var ms = new MemoryStream();
            using (var z = new ZipArchive(ms, ZipArchiveMode.Create, true))
            {
                using (var w = new StreamWriter(z.CreateEntry("data/a.txt").Open())) w.Write("hello");
                var big = new byte[100_000];
                new Random(1).NextBytes(big);
                using (var s = z.CreateEntry("data/b.bin", CompressionLevel.Optimal).Open()) s.Write(big, 0, big.Length);
            }
            return ms.ToArray();
        }

        string OuterZip(CompressionLevel obbLevel)
        {
            string path = Path.Combine(GamePaths.Data, "outer.xapk");
            Directory.CreateDirectory(GamePaths.Data);
            using var z = ZipFile.Open(path, ZipArchiveMode.Create);
            using (var w = new StreamWriter(z.CreateEntry("manifest.json").Open())) w.Write("{}");
            var inner = InnerZip();
            using (var s = z.CreateEntry("Android/obb/x/main.1.x.obb", obbLevel).Open()) s.Write(inner, 0, inner.Length);
            return path;
        }

        [Test]
        public void AStoredZipInAZipIsReadWhereItLies()
        {
            string path = OuterZip(CompressionLevel.NoCompression);
            using var fs = File.OpenRead(path);
            Assert.IsNull(ZipSlice.Stored(fs, "manifest.json"), "a compressed entry has no slice");
            var slice = ZipSlice.Stored(fs, "Android/obb/x/main.1.x.obb");
            Assert.IsNotNull(slice);
            Assert.AreEqual(InnerZip().Length, slice.Value.length);
            using var inner = new ZipArchive(new ZipSlice.SubStream(fs, slice.Value.offset, slice.Value.length), ZipArchiveMode.Read);
            using (var r = new StreamReader(inner.GetEntry("data/a.txt").Open())) Assert.AreEqual("hello", r.ReadToEnd());
            using (var s = inner.GetEntry("data/b.bin").Open()) using (var ms = new MemoryStream()) { s.CopyTo(ms); Assert.AreEqual(100_000, ms.Length); }
        }

        [TestCase(CompressionLevel.NoCompression)]
        [TestCase(CompressionLevel.Optimal)]   // (a compressed OBB: through a temporary file)
        public void SomethingElseInstallsNothing(CompressionLevel level)
        {
            string path = OuterZip(level);
            GameContent.Root = Path.Combine(GamePaths.Data, "Original");
            try
            {
                var job = OriginalSetup.Convert(new[] { path });
                for (int i = 0; i < 400 && !job.Finished; i++) Thread.Sleep(50);
                Assert.IsTrue(job.Finished, "finished");
                OriginalSetup.Finish(job);
                StringAssert.Contains("nothing of Galaxy on Fire 2", job.Error ?? "(installed)");
                Assert.IsFalse(GameContent.Installed);
                Assert.IsFalse(Directory.Exists(GameContent.Root + ".new"), "no half-made cache left");
                Assert.IsTrue(File.Exists(path), "the player's own file is left alone");
            }
            finally { GameContent.Root = null; }
        }
    }
}
