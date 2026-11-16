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

        string Pack(string name, int version, params (string path, string text)[] files)
        {
            string path = Path.Combine(GamePaths.Data, name + ".zip");
            Directory.CreateDirectory(GamePaths.Data);
            if (File.Exists(path)) File.Delete(path);
            using var z = ZipFile.Open(path, ZipArchiveMode.Create);
            using (var w = new StreamWriter(z.CreateEntry(OriginalPacks.ManifestName).Open()))
                w.Write($"{{\"name\":\"{name}\",\"title\":\"{name} pack\",\"version\":{version},\"order\":2,\"files\":{files.Length}}}");
            foreach (var (p, t) in files) using (var w = new StreamWriter(z.CreateEntry(p).Open())) w.Write(t);
            return path;
        }

        [Test]
        public void APackIsKeptAndWrittenOverTheCopy()
        {
            string root = Path.Combine(GamePaths.Data, "Original"), folder = Path.Combine(GamePaths.Data, "Packs");
            Directory.CreateDirectory(root);
            File.WriteAllText(Path.Combine(root, "_manifest.tsv"), OriginalConverter.ManifestHeader + "\n");
            var info = OriginalPacks.Read(Pack("hd", 3, ("Textures/main/a.png", "hd"), ("Resources/GoF2Planets3D/000/planet.json", "{}")));
            Assert.IsNotNull(info, "a zip with gof2pack.json is a pack");
            Assert.IsNull(OriginalPacks.Read(Pack("x", 1).Replace("x.zip", "nothing.zip")), "no file: no pack");
            OriginalPacks.Keep(info, folder, move: false);
            Assert.AreEqual(1, OriginalPacks.Pending(folder, root).Count, "kept, not yet written");
            OriginalPacks.Apply(info, root, null);
            Assert.AreEqual("hd", File.ReadAllText(Path.Combine(root, "Textures/main/a.png")));
            Assert.IsTrue(File.Exists(Path.Combine(root, "Resources/GoF2Planets3D/000/planet.json")));
            Assert.AreEqual(0, OriginalPacks.Pending(folder, root).Count, "written: recorded in _packs.tsv");
            // a newer version of it is pending again; a pack reaching outside the copy is refused
            OriginalPacks.Keep(OriginalPacks.Read(Pack("hd", 4, ("Textures/main/a.png", "hd4"))), folder, move: false);
            Assert.AreEqual(1, OriginalPacks.Kept(folder).Count, "the older version replaced");
            Assert.AreEqual(1, OriginalPacks.Pending(folder, root).Count);
            var evil = OriginalPacks.Read(Pack("evil", 1, ("../outside.txt", "no")));
            Assert.Throws<InvalidDataException>(() => OriginalPacks.Apply(evil, root, null));
            Assert.IsFalse(File.Exists(Path.Combine(GamePaths.Data, "outside.txt")));
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
