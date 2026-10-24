// ModExhaustsTests.cs
// Feature: CLAUDE.md "Mods" > Exhaust styles: a flame style (a model cut from its mod's own exhaust parts) isn't offered on
// that mod's own ships (ModExhausts.For / Offered / Find(key, ship)), every other style and ship keeps them; flame styles
// with one "group" are one choice whose nozzles each wear the member made for the nearest nozzle size (ForNozzle); a mount's
// "outline" stands for its nozzle only when it is plausible against the mount's glowSize (ShapesOf: the GoF3 builder's
// Vossk slivers fall back to the glowSize oval), and so a ship's own engineFx and a mobile station's take its shape
// (OutlineOf, EngineFx.CreateShaped); an "engineFx" reads its "coneProfile" / "coneFade" (CustomEngineFx).
// Expected values: the format in Modding/README.md "Exhaust styles".

using System.Collections.Generic;
using System.Reflection;
using GoF2Remake.Data;
using GoF2Remake.Modding;
using NUnit.Framework;
using UnityEngine;

namespace GoF2Remake.Tests
{
    public class ModExhaustsTests : SavesModsTest
    {
        const string StylesJson = @"[
            { 'id': 'flame', 'name': 'Flame', 'model': 'exhausts/flame.glb', 'nozzle': 0.5,
              'materials': [ { 'material': 'EngineExhaust', 'flame': true } ] },
            { 'id': 'drive', 'name': 'Drive', 'engineFx': { 'glow': 'fx/glow.png', 'coneWidth': 87 }, 'nozzle': 25 }
        ]";

        void StylesModOn()
        {
            string dir = WriteMod("ex", "t_ex", "1.0", "",
                ("exhausts.json", StylesJson),
                ("ships.json", "[ { 'id': 'own', 'name': 'Own', 'model': 'gof2:ship_005_terran' } ]"));
            WriteFile(dir, "exhausts/flame.glb", Dummy);
            WriteFile(dir, "fx/glow.png", Dummy);
            ScanAndEnable("t_ex");
            Assert.IsFalse(Installed("t_ex").Broken, AllMessages(Installed("t_ex")));
        }

        [Test]
        public void AFlameStyleIsntOfferedOnItsOwnModsShips()
        {
            StylesModOn();
            Database.Load();
            int own = ModContent.ShipIndexOf("t_ex:own");
            Assert.GreaterOrEqual(own, OriginalShips);
            Assert.AreEqual(2, ModExhausts.All().Count);

            var onOwn = ModExhausts.For(own).ConvertAll(s => s.Key);
            CollectionAssert.AreEqual(new[] { "t_ex:drive" }, onOwn, "the mod's own ships: only its engine effect");
            Assert.IsNull(ModExhausts.Find("t_ex:flame", own), "a saved build's flame style isn't shown on the own ship");
            Assert.IsNotNull(ModExhausts.Find("t_ex:drive", own));

            var onGame = ModExhausts.For(10).ConvertAll(s => s.Key);
            CollectionAssert.AreEqual(new[] { "t_ex:flame", "t_ex:drive" }, onGame, "any other ship: every style");
            Assert.IsNotNull(ModExhausts.Find("t_ex:flame", 10));
        }

        [Test]
        public void AGroupOfFlameStylesIsOneChoiceThatFitsEachNozzle()
        {
            string dir = WriteMod("gr", "t_gr", "1.0", "", ("exhausts.json", @"[
                { 'id': 'small', 'name': 'Small', 'model': 'exhausts/a.glb', 'nozzle': 0.38, 'group': 'thruster', 'groupName': 'Thruster',
                  'materials': [ { 'material': 'EngineExhaust', 'flame': true } ] },
                { 'id': 'big', 'name': 'Big', 'model': 'exhausts/b.glb', 'nozzle': 0.61, 'group': 'thruster',
                  'materials': [ { 'material': 'EngineExhaust', 'flame': true } ] },
                { 'id': 'ring', 'name': 'Ring', 'model': 'exhausts/c.glb', 'nozzle': 0.42, 'group': 'thruster',
                  'materials': [ { 'material': 'EngineExhaust', 'flame': true } ] },
                { 'id': 'alone', 'name': 'Alone', 'model': 'exhausts/a.glb', 'nozzle': 0.5, 'scale': 3,
                  'materials': [ { 'material': 'EngineExhaust', 'flame': true } ] } ]"));
            foreach (var f in new[] { "exhausts/a.glb", "exhausts/b.glb", "exhausts/c.glb" }) WriteFile(dir, f, Dummy);
            ScanAndEnable("t_gr");
            Assert.IsFalse(Installed("t_gr").Broken, AllMessages(Installed("t_gr")));

            var offered = ModExhausts.For(10);
            CollectionAssert.AreEqual(new[] { "t_gr:small", "t_gr:alone" }, offered.ConvertAll(x => x.Key), "the group is one choice, led by its first");
            var group = offered[0];
            Assert.AreEqual("Thruster", group.Name, "named by its groupName");
            Assert.AreEqual(3, group.members.Count);
            Assert.AreSame(group, ModExhausts.Find("t_gr:big", 10), "a member's key (an older build) is its group");

            Assert.AreEqual("t_gr:small", group.ForNozzle(0.30f).Key);
            Assert.AreEqual("t_gr:small", group.ForNozzle(0.39f).Key);
            Assert.AreEqual("t_gr:ring", group.ForNozzle(0.45f).Key);
            Assert.AreEqual("t_gr:big", group.ForNozzle(0.56f).Key, "nearest on a log scale: 0.56 is nearer 0.61 than 0.42");
            Assert.AreEqual("t_gr:big", group.ForNozzle(2f).Key);
            Assert.AreSame(offered[1], offered[1].ForNozzle(2f), "a style without a group is itself");
            Assert.AreEqual(3f, offered[1].scale, 1e-5f);
            Assert.AreEqual(1f, group.scale, 1e-5f, "scale defaults to 1");
        }

        [Test]
        public void AStylesNozzleIsReadAndTheEngineFxsConeShapeToo()
        {
            StylesModOn();
            var drive = ModExhausts.Find("t_ex:drive");
            Assert.AreEqual(25f, drive.nozzle, 1e-4f);
            var fxOnly = JsonUtility.FromJson<CustomEngineFx>("{ \"coneWidth\": 138, \"nozzle\": 45 }");
            Assert.AreEqual(45f, fxOnly.NozzleRadius, 1e-4f, "an engineFx's own nozzle, else its coneWidth");
            Assert.AreEqual(138f, JsonUtility.FromJson<CustomEngineFx>("{ \"coneWidth\": 138 }").NozzleRadius, 1e-4f);
            var fx = JsonUtility.FromJson<CustomEngineFx>("{ \"glow\": \"g.png\", \"coneProfile\": [0, 0, 0.1, 0.5, 1, 0.5, 1, 0, 0.9], \"coneFade\": [0, 0.3] }");
            Assert.AreEqual(9, fx.coneProfile.Length);
            Assert.AreEqual(0.3f, fx.coneFade[1], 1e-6f);
        }

        [Test]
        public void AnEngineFxsConeFlowsUnlessItsSpeedIsZero()
        {
            // GoF3's exhausts churn (their materials' UVAnim flow): the cone's material is GoF2/ModEngineFlow with the engine's
            // speed, strength and tiling, the default without "coneFlow"; a speed of 0 keeps the still additive picture.
            var flowing = typeof(GoF2Remake.Modding.EngineFx).GetMethod("Flowing", BindingFlags.NonPublic | BindingFlags.Static);
            var additive = new Material(Shader.Find("Unlit/Color"));
            try
            {
                var fx = JsonUtility.FromJson<CustomEngineFx>("{ \"cone\": \"c.png\", \"coneFlow\": [1.3, 1, 0.5] }");
                Assert.AreEqual(3, fx.coneFlow.Length);
                var mat = new Material(additive);
                flowing.Invoke(null, new object[] { mat, fx.coneFlow });
                Assert.AreEqual("GoF2/ModEngineFlow", mat.shader.name);
                Assert.AreEqual(1.3f, mat.GetFloat("_FlowSpeed"), 1e-5f);
                Assert.AreEqual(0.5f, mat.GetFloat("_FlowTiling"), 1e-5f);
                var plain = new Material(additive);
                flowing.Invoke(null, new object[] { plain, null });
                Assert.AreEqual("GoF2/ModEngineFlow", plain.shader.name, "no coneFlow: the default flow");
                Assert.AreEqual(1f, plain.GetFloat("_FlowSpeed"), 1e-5f);
                var still = new Material(additive);
                flowing.Invoke(null, new object[] { still, new[] { 0f } });
                Assert.AreEqual(additive.shader, still.shader, "speed 0: the picture stays still");
                Object.DestroyImmediate(mat); Object.DestroyImmediate(plain); Object.DestroyImmediate(still);
            }
            finally { Object.DestroyImmediate(additive); }
        }

        static ModExhausts.NozzleShape[] ShapesOf(int ship, List<WeaponMount> mounts)
        {
            var m = typeof(ModExhausts).GetMethod("ShapesOf", BindingFlags.NonPublic | BindingFlags.Static);
            var go = new GameObject("model");
            try { return (ModExhausts.NozzleShape[])m.Invoke(null, new object[] { ship, go, mounts }); }
            finally { Object.DestroyImmediate(go); }
        }

        [Test]
        public void AShipWithItsOwnEngineEffectHasNozzlesAsLargeAsItsCone()
        {
            // A GoF3 hull: its glowSize is the hot core of each nozzle's glow; its effect is drawn for an 87-unit nozzle.
            WriteMod("gf", "t_gf", "1.0", "", ("ships.json", @"[ { 'id': 'hull', 'name': 'Hull', 'model': 'gof2:ship_005_terran',
                'engineFx': { 'glow': 'g.png', 'coneWidth': 138, 'nozzle': 87 },
                'mounts': [ { 'slotType': 3, 'position_engine': [100, 0, -300], 'glowSize': [16, 16, 40] },
                            { 'slotType': 3, 'position_engine': [0, 50, -300], 'glowSize': [32, 32, 40] } ] } ]"));
            ScanAndEnable("t_gf");
            Database.Load();
            int ship = ModContent.ShipIndexOf("t_gf:hull");
            var mounts = CustomShips.Get(ship).mounts;
            var shapes = ShapesOf(ship, mounts);
            Assert.AreEqual(87f * 16f / 24f, shapes[0].Mean, 0.5f, "the median nozzle (24) becomes the effect's nozzle, 87, each keeping its size against the others");
            Assert.AreEqual(87f * 32f / 24f, shapes[1].Mean, 0.5f);
        }

        [Test]
        public void ASliverOutlineFallsBackToTheGlowSize()
        {
            // The Shaan'ra-Grth's: four points within a unit, 18 units off its mount, on a 32 x 32 nozzle.
            var sliver = new WeaponMount { slotType = 3, position_engine = new[] { 40, 50, -111 }, glowSize = new[] { 32f, 32f, 67f },
                                           outline = new[] { -3.4f, 19.8f, -3.8f, 17f, -4.3f, 17.7f, -4f, 18.8f } };
            // The Atauno Rheep's: a real hexagon around its 13 x 20 nozzle's glow, a little off it.
            var hexagon = new WeaponMount { slotType = 3, position_engine = new[] { 0, 17, -124 }, glowSize = new[] { 13f, 22f, 46f },
                                            outline = new[] { 19.2f, 14.2f, 18.6f, -15.2f, 14.9f, -20f, 3f, -24.9f, -3f, -24.9f, -8.7f, -22.7f,
                                                              -14.9f, -20f, -19.2f, 14.2f, -14.8f, 21.6f, -11.2f, 23.8f, -3f, 23.9f, 3f, 23.9f, 11.2f, 23.8f, 14.8f, 21.6f } };
            var shapes = ShapesOf(10, new List<WeaponMount> { sliver, hexagon });
            Assert.AreEqual(32f, shapes[0].Mean, 0.5f, "the sliver: the glowSize's 32-unit circle");
            Assert.AreEqual(0f, shapes[0].centreX, 1e-4f);
            Assert.Greater(shapes[1].Mean, 18f, "the hexagon kept");
            Assert.Less(shapes[1].Mean, 26f);
        }

        [Test]
        public void AMountsOutlineShapesItsOwnEffect()
        {
            // a slot three times wider than high (game units around the mount), centred 4 units to the pilot's left
            var outline = new List<float>();
            for (int k = 0; k < 16; k++)
            {
                float a = k * Mathf.PI / 8f;
                outline.Add(4f + 30f * Mathf.Cos(a)); outline.Add(10f * Mathf.Sin(a));
            }
            var slot = new WeaponMount { slotType = 3, position_engine = new[] { 0, 0, -500 }, glowSize = new[] { 30f, 10f, 90f },
                                         outline = outline.ToArray() };
            var shape = ModExhausts.OutlineOf(slot);
            Assert.IsNotNull(shape, "a plausible outline");
            var profile = shape.Normalized();
            Assert.Greater(ModExhausts.FactorOf(profile, 0f) / ModExhausts.FactorOf(profile, Mathf.PI / 2f), 2.5f, "wide, not round");
            Assert.AreEqual(-4f * 0.05f, shape.centreX, 0.02f, "centred on the nozzle (game x -> Unity -x, metres)");
            Assert.IsNull(ModExhausts.OutlineOf(new WeaponMount { slotType = 3, position_engine = new[] { 0, 0, 0 } }), "none: round");
            var sliver = new WeaponMount { slotType = 3, position_engine = new[] { 0, 0, 0 }, glowSize = new[] { 30f, 30f, 90f },
                                           outline = new float[] { -1, -1, 1, -1, 1, 1, -1, 1 } };
            Assert.IsNull(ModExhausts.OutlineOf(sliver), "a sliver against its glowSize isn't the nozzle");
        }
    }
}
