// ModHullLightingTests.cs
// Feature: CLAUDE.md "Space scene" > Hull reflection, mod materials: the mods' material templates (Resources/GoF2Mods/
// ModAssets, ModAssetsBuilder) carry _GOF2_PBR, so GoF2/Hull leaves its GoF2 reflection and rim out for them (a mod's
// metallic / smoothness alpha is PBR smoothness, not the original's specular mask: the mods' hulls came out milky white in
// the hangars); in a GoF2 hangar (SkyReflection.SetHangar) their indirect light is dimmed and their main light comes from
// above, out of a system (SetSystem: space, the lounge) neither applies. A material in the specular workflow
// ("specularGlossiness" / "specularColor", glTF's KHR_materials_pbrSpecularGlossiness: Galaxy on Fire 3's hulls) takes the
// ModSpec_ templates, URP's specular setup.

using GoF2Remake.Data;
using GoF2Remake.Modding;
using GoF2Remake.World;
using NUnit.Framework;
using UnityEngine;

namespace GoF2Remake.Tests
{
    public class ModHullLightingTests
    {
        [Test]
        public void TheModTemplatesArePbrHulls()
        {
            var a = Resources.Load<ModAssets>(ModAssets.ResourcePath);
            Assert.IsNotNull(a, "Resources/" + ModAssets.ResourcePath);
            foreach (var m in new[] { a.litOpaque, a.litOpaqueDetail, a.litCutout, a.litCutoutDetail, a.litTransparent, a.litTransparentDetail })
            {
                Assert.IsNotNull(m);
                Assert.AreEqual("GoF2/Hull", m.shader.name, m.name);
                Assert.IsTrue(m.IsKeywordEnabled("_GOF2_PBR"), m.name + ": no GoF2 terms on a mod's PBR maps");
            }
        }

        [Test]
        public void TheSpecularTemplatesAreSpecularSetupHulls()
        {
            var a = Resources.Load<ModAssets>(ModAssets.ResourcePath);
            foreach (var m in new[] { a.specOpaque, a.specOpaqueDetail, a.specCutout, a.specCutoutDetail, a.specTransparent, a.specTransparentDetail })
            {
                Assert.IsNotNull(m, "GoF2 > Build > Mod Assets");
                Assert.AreEqual("GoF2/Hull", m.shader.name, m.name);
                Assert.IsTrue(m.IsKeywordEnabled("_SPECULAR_SETUP"), m.name);
                Assert.IsTrue(m.IsKeywordEnabled("_GOF2_PBR"), m.name);
                Assert.IsTrue(m.IsKeywordEnabled("_METALLICSPECGLOSSMAP"), m.name + ": the map's variant");
            }
            Assert.AreSame(a.specCutout, a.Lit(true, false, false, true));
            Assert.AreSame(a.litCutout, a.Lit(true, false, false, false));
        }

        [Test]
        public void ASpecularColourEntryTakesTheSpecularSetup()
        {
            var m = ModMaterials.FromSpec(null, new CustomShipMaterial { specularColor = new[] { 0.5f, 0.4f, 0.3f }, smoothness = 0.6f }, "spec test");
            try
            {
                Assert.IsTrue(m.IsKeywordEnabled("_SPECULAR_SETUP"));
                var t = m.GetTexture("_SpecGlossMap") as Texture2D;
                Assert.IsNotNull(t, "the colour as a 1 x 1 map");
                Assert.IsTrue(t.isDataSRGB, "read as sRGB, like a specular-glossiness map");
                Assert.AreEqual(0.6f, m.GetFloat("_Smoothness"), 1e-5f);
                var plain = ModMaterials.FromSpec(null, new CustomShipMaterial { metallic = 0.2f }, "metal test");
                Assert.IsFalse(plain.IsKeywordEnabled("_SPECULAR_SETUP"), "a metallic entry stays metallic");
                Object.DestroyImmediate(plain);
            }
            finally { Object.DestroyImmediate(m); }
        }

        [Test]
        public void AnAdditiveEntryIsAGlowLayer()
        {
            // Galaxy on Fire 3's gate electricity: DiffuseColor x Opacity, UVAnim scrolling, no vertex colours.
            var m = ModMaterials.FromSpec(null, new CustomShipMaterial { additive = true, emissionColor = new[] { 0.1f, 0.5f, 1f },
                emissionIntensity = 4f, scroll = new[] { 0.6f, -2f }, ignoreVertexColors = true }, "glow test");
            try
            {
                Assert.AreEqual("GoF2/ModGlow", m.shader.name);
                var c = m.GetColor("_EmissionColor");
                Assert.AreEqual(0.4f, c.r, 1e-4f); Assert.AreEqual(2f, c.g, 1e-4f); Assert.AreEqual(4f, c.b, 1e-4f);
                Assert.AreEqual(new Vector4(0.6f, -2f, 0f, 0f), m.GetVector("_Scroll"));
                Assert.AreEqual(0f, m.GetFloat("_UseVertexColor"));
                var plain = ModMaterials.FromSpec(null, new CustomShipMaterial { additive = true }, "plain glow");
                Assert.AreEqual(1f, plain.GetFloat("_UseVertexColor"), "the vertex colours by default");
                Assert.AreEqual(Color.white, plain.GetColor("_EmissionColor"));
                Object.DestroyImmediate(plain);
            }
            finally { Object.DestroyImmediate(m); }
        }

        [Test]
        public void AModRoomKeepsItsGlowOnPlainLit()
        {
            var a = Resources.Load<ModAssets>(ModAssets.ResourcePath);
            var m = new Material(a.litOpaque);
            var room = GameObject.CreatePrimitive(PrimitiveType.Cube);
            try
            {
                room.GetComponent<MeshRenderer>().sharedMaterial = m;
                ModMaterials.PlainLit(room);
                Assert.AreEqual("Universal Render Pipeline/Lit", m.shader.name);
                Assert.IsTrue(m.IsKeywordEnabled("_EMISSION"), "the shader switch dropped the room's emission");
            }
            finally { Object.DestroyImmediate(room); Object.DestroyImmediate(m); }
        }

        [Test]
        public void AGoF2HangarLightsTheModHullsFromAbove()
        {
            float dim = Shader.GetGlobalFloat("_GoF2PbrIndirectDim");
            var light = Shader.GetGlobalVector("_GoF2PbrLight");
            try
            {
                SkyReflection.SetHangar(0);
                Assert.AreEqual(SkyReflection.HangarPbrIndirectDim, Shader.GetGlobalFloat("_GoF2PbrIndirectDim"), 1e-5f);
                var l = Shader.GetGlobalVector("_GoF2PbrLight");
                Assert.AreEqual(1f, l.w, 1e-5f, "on in a hangar");
                Assert.Greater(l.y, 0f, "from above");
                Assert.AreEqual(SkyReflection.HangarPbrLightStrength, Shader.GetGlobalColor("_GoF2PbrLightColor").r, 1e-5f);
            }
            finally
            {
                Shader.SetGlobalFloat("_GoF2PbrIndirectDim", dim);
                Shader.SetGlobalVector("_GoF2PbrLight", light);
            }
        }
    }
}
