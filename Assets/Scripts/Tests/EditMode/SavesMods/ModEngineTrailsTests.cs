// ModEngineTrailsTests.cs
// Feature: CLAUDE.md "Mods" > Liveries, decals and engine trails: a kit's "trails" (EVERSPACE 2's customization engine trails,
// ModShipKits.EngineTrail) are picked per build for the engine sockets ("trail=") and the booster sockets ("boosttrail="), not
// part of the model's variant; Es2Trails runs each kind as EVERSPACE 2's Niagara system does (spawn rates, the opacity gate,
// lifetimes, the particles easing to rest in the world, HangarMode), its curve tables read linearly over the normalized age;
// UE's noise textures are rebuilt as FSystemTextures makes them.
// Expected values: the ES2 importer's research/engine_trails.md (Stardust 200 x Scale a second for U(0, 0.8) x 0.4 s;
// Firestarter 50 x 1.5 x Scale whatever the opacity, 0.4 / 1.5 x 0.8 s; the parameter collection's -2500 cm/s, falloff
// 0.4, smoothing 0.5, limit 20000).

using System.Linq;
using GoF2Remake.Data;
using GoF2Remake.Modding;
using NUnit.Framework;
using UnityEngine;

namespace GoF2Remake.Tests
{
    public class ModEngineTrailsTests : SavesModsTest
    {
        const string Kits = @"[ { 'id': 'hulls', 'slots': ['body'], 'parts': [ { 'id': 'b', 'slot': 'body', 'model': 'b.glb' } ],
            'trails': [
                { 'id': 'default', 'name': 'Default', 'kind': 'default' },
                { 'id': 'glitter', 'name': 'Stardust', 'kind': 'glitter', 'curves': [[1, 0.5, 0]], 'texture': 'barcode.png' },
                { 'id': 'triangles', 'name': 'Delta Surge', 'kind': 'triangles', 'curves': [[0, 1, 0], [1, 1]],
                  'mesh': { 'positions': [0, 0, 1, 0, 1, -1, 0, -1, -1], 'normals': [1, 0, 0, 1, 0, 0, 1, 0, 0], 'uv': [0, 0, 1, 0, 0, 1], 'indices': [0, 1, 2] } } ] } ]";

        int KitShip(string id, string kits = Kits)
        {
            string dir = WriteMod(id, id, "1.0", "", ("shipkits.json", kits),
                ("ships.json", "[ { 'id': 'raptor', 'name': 'Raptor', 'kit': 'hulls', 'kitType': 'fighter', 'build': { 'body': 'b' } } ]"));
            WriteFile(dir, "b.glb", Dummy);
            WriteFile(dir, "barcode.png", Dummy);
            ScanAndEnable(id);
            Database.Load();
            return ModContent.ShipIndexOf(id + ":raptor");
        }

        [Test]
        public void AKitsTrailsAreRead()
        {
            int ship = KitShip("t_trails");
            Assert.IsFalse(Installed("t_trails").Broken, AllMessages(Installed("t_trails")));
            var kit = ModShipKits.CustomizationOf(ship);
            Assert.AreEqual(3, kit.trails.Count);
            Assert.IsTrue(kit.FindTrail("default").IsDefault, "the Default veil is Es2EngineVfx's own");
            var g = kit.FindTrail("GLITTER");
            Assert.AreEqual("Stardust", g.Name);
            Assert.AreEqual("barcode.png", g.texture);
            Assert.AreEqual(3, kit.FindTrail("triangles").mesh.positions.Length);
            Assert.AreEqual(new Vector3(0f, 1f, -1f), kit.FindTrail("triangles").mesh.positions[1]);
        }

        [Test]
        public void AShapeTrailWithoutItsMeshLeavesTheKitOut()
        {
            int ship = KitShip("t_trailbad", @"[ { 'id': 'hulls', 'slots': ['body'], 'parts': [ { 'id': 'b', 'slot': 'body', 'model': 'b.glb' } ],
                'trails': [ { 'id': 'rings', 'kind': 'rings' } ] } ]");
            ModShipKits.CustomizationOf(ship);
            StringAssert.Contains("needs its \"mesh\"", AllMessages(Installed("t_trailbad")));
            Assert.IsNull(ModShipKits.Find("t_trailbad:hulls"), "the kit with the error is left out, as any kit's error");
        }

        [Test]
        public void ABuildPicksTheEngineAndBoosterTrails()
        {
            int ship = KitShip("t_trailbuild");
            var kit = ModShipKits.CustomizationOf(ship);
            var b = ModShipKits.Build.Parse("body=b;trail=glitter;boosttrail=triangles;tier=0");
            Assert.AreEqual("glitter", b.trail);
            Assert.AreEqual("triangles", b.boostTrail);
            Assert.IsFalse(b.parts.ContainsKey("trail"), "not a slot");
            Assert.IsTrue(ModShipKits.Build.Reserved("trail") && ModShipKits.Build.Reserved("boosttrail"));
            var round = ModShipKits.Build.Parse(b.ToString());
            Assert.AreEqual("glitter", round.trail);
            Assert.AreEqual("triangles", b.Clone().boostTrail);
            Assert.AreEqual("glitter", kit.TrailOf(b, false).id);
            Assert.AreEqual("triangles", kit.TrailOf(b, true).id);
            Assert.IsNull(kit.TrailOf(ModShipKits.Build.Parse("trail=default"), false), "the Default: the veil");
            var n = ModShipKits.Normalize(kit, "fighter", ModShipKits.Build.Parse("body=b;trail=nonsense;boosttrail=glitter"));
            Assert.IsNull(n.trail, "an unknown trail is dropped");
            Assert.AreEqual("glitter", n.boostTrail);
            Assert.AreEqual(ModShipKits.VariantAssembly(ship, ModShipKits.Build.Parse("body=b;tier=0")).name,
                            ModShipKits.VariantAssembly(ship, ModShipKits.Build.Parse("body=b;trail=glitter;boosttrail=triangles;tier=0")).name,
                            "the trails aren't part of the model");
        }

        static ModShipKits.EngineTrail Trail(string kind, params float[][] curves)
        {
            var t = new ModShipKits.EngineTrail { id = kind, kind = kind };
            foreach (var c in curves) t.curves.Add(c);
            return t;
        }

        [Test]
        public void StardustSpawnsWhileTheEnginesBurn()
        {
            Random.InitState(1);
            var tr = new Es2Trails(Trail("glitter", new[] { 1f, 0f }));
            for (int i = 0; i < 10; i++) tr.Step(0.01f, 1f, 2f, Color.white, Vector3.zero, 0f, false, true);
            var e = tr.emitters[0];
            // 200 x Scale a second, each living U(0, 0.8) x 0.4 s: the ones still alive after 0.1 s
            Assert.Greater(e.particles.Count, 20);
            Assert.LessOrEqual(e.particles.Count, 40);
            Assert.IsTrue(e.particles.All(p => p.life <= 0.32f + 1e-4f));
            Assert.IsTrue(e.particles.All(p => p.vel.x < 0f), "flying backward");
            tr.Clear();
            for (int i = 0; i < 10; i++) tr.Step(0.01f, 0f, 2f, Color.white, Vector3.zero, 0f, false, true);
            Assert.AreEqual(0, e.particles.Count, "none while the opacity is 0");
        }

        [Test]
        public void FirestarterSparksAlwaysSpawn()
        {
            Random.InitState(2);
            var tr = new Es2Trails(Trail("sparks", new[] { 1f }, new[] { 0f, 1f }));
            tr.Step(0.1f, 0f, 1f, Color.white, Vector3.zero, 0f, false, true);
            var e = tr.emitters[0];
            Assert.AreEqual(7, e.particles.Count, "50 x 1.5 a second for 0.1 s");
            Assert.AreEqual(0.4f / 1.5f * 0.8f, e.particles[0].life, 1e-5f);
            Assert.AreEqual(0f, tr.Alpha(e, e.particles[0], false), "alpha U(0, opacity)");
        }

        [Test]
        public void TheParticlesComeToRestInTheWorld()
        {
            Random.InitState(3);
            var owner = new Vector3(3000f, 0f, 0f);   // the ship flying forward at 30 m/s (cm/s, the socket's frame)
            var tr = new Es2Trails(Trail("darktrail", new[] { 1f }));
            tr.Step(0.05f, 1f, 1f, Color.white, owner, 0f, false, true);
            var e = tr.emitters[0];
            for (int i = 0; i < 6; i++) tr.Step(0.05f, 1f, 1f, Color.white, owner, 0f, false, true);
            var oldest = e.particles.OrderByDescending(p => p.age).First();
            // born at -2500 cm/s, eased toward -3000 (the owner's velocity, reversed) by 1 - 0.5^(0.4 x age)
            float expected = Mathf.Lerp(-2500f, -3000f, 1f - Mathf.Pow(0.5f, 0.4f * oldest.age));
            Assert.AreEqual(expected, oldest.vel.x, 2f);
            Assert.Less(oldest.vel.x, -2500f);
            // HangarMode: the birth velocity kept, the colour x 4, the alpha squared
            var hangar = new Es2Trails(Trail("darktrail", new[] { 1f }));
            for (int i = 0; i < 4; i++) hangar.Step(0.05f, 0.5f, 1f, Color.white, owner, 0f, true, true);
            var h = hangar.emitters[0];
            Assert.IsTrue(h.particles.All(p => Mathf.Approximately(p.vel.x, -2500f)));
            Assert.AreEqual(40f, h.particles[0].colour.x, 1e-4f, "x 10 x 4");
            float a0 = Mathf.Pow(0.5f, 4f);
            Assert.AreEqual(a0 * a0 * 10f, hangar.Alpha(h, h.particles[0], true), 1e-4f, "alpha0^2 x curve x 10");
        }

        [Test]
        public void ACurveIsReadLinearlyOverTheAge()
        {
            var tr = new Es2Trails(Trail("glitter", new[] { 0f, 1f, 0f }));
            Assert.AreEqual(0.5f, tr.Curve(0, 0.25f), 1e-5f);
            Assert.AreEqual(1f, tr.Curve(0, 0.5f), 1e-5f);
            Assert.AreEqual(0f, tr.Curve(0, 2f), 1e-5f, "clamped");
            Assert.AreEqual(1f, tr.Curve(3, 0.5f), "a missing curve counts as 1");
        }

        [Test]
        public void UesNoiseTexturesAreRebuilt()
        {
            var g = Es2Trails.GradientTexture;
            Assert.AreEqual(128, g.width);
            byte[] ok = { 0x00, 0x88, 0xff };
            foreach (var c in g.GetPixels32())
            {
                Assert.IsTrue(ok.Contains(c.r) && ok.Contains(c.g) && ok.Contains(c.b));
                Assert.AreEqual(2, new[] { c.r, c.g, c.b }.Count(v => v != 0x88), "an edge midpoint: two non-zero components");
            }
            var n = Es2Trails.Noise3D;
            Assert.AreEqual(16, n.width);
            var px = n.GetPixels32();
            Color32 At(int x, int y, int z) => px[x + y * 16 + z * 256];
            for (int y = 0; y < 16; y += 5)
                for (int z = 0; z < 16; z += 5)
                {
                    var a = At(0, y, z); var b = At(15, y, z);
                    Assert.IsTrue(a.r == b.r && a.g == b.g && a.b == b.b, "texel 15 repeats texel 0's gradient");
                    int gx = (b.r - 127) / 127, gy = (b.g - 127) / 127, gz = (b.b - 127) / 127;
                    Assert.AreEqual(127 + gx * 15 + gy * y + gz * z, b.a, "alpha 127 + dot(gradient, texel)");
                }
        }
    }
}
