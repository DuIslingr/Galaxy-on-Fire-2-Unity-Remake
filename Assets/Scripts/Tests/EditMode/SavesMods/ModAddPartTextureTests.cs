// ModAddPartTextureTests.cs
// Feature: CLAUDE.md "Mods" ship models (docs/notes/mods-models.md, ships.json "addParts"; a Discord report, "Custom
// Engine glow not using custom texture"). Expected behaviour: a glowing part (lights, engine glow, NPC engine) is drawn
// with the game's material for its role, showing the part's "texture" if it has one, else its model's own base colour
// texture (a custom engine glow showed the race's glow sprite); a model without textures (the original-game imports'
// parts, a GLB without materials) keeps the game's. The Mod Builder sets and clears a part's texture.

using GoF2Remake.Data;
using GoF2Remake.Modding;
using Newtonsoft.Json.Linq;
using NUnit.Framework;
using UnityEngine;

namespace GoF2Remake.Tests
{
    public class ModAddPartTextureTests : SandboxTest
    {
        GameObject go;
        Texture2D own;
        readonly System.Collections.Generic.List<Material> made = new System.Collections.Generic.List<Material>();

        [TearDown]
        public void CleanUp()
        {
            if (go != null) Object.DestroyImmediate(go);
            foreach (var m in made) if (m != null) Object.DestroyImmediate(m);
            made.Clear();
            if (own != null) Object.DestroyImmediate(own);
        }

        static CustomShipData Ship() => new CustomShipData { name = "Saber", assembly = "mod_saber", index = -1, race = 0 };
        static CustomAddPart Glow(string texture = null) => new CustomAddPart { model = "models/glow.glb", role = CustomAddPart.EngineGlow, texture = texture };

        /// <summary>A glTF part's material as ModMaterials.FromGltf leaves it: its base map the GLB's texture, or none. Plain
        /// URP Lit: reading the mod templates themselves drops their _EMISSION in the Editor (ModShipBuilder.OwnTexture).</summary>
        Material GltfMaterial(Texture baseMap = null)
        {
            var m = new Material(Shader.Find("Universal Render Pipeline/Lit"));
            made.Add(m);
            m.SetTexture("_BaseMap", baseMap);
            return m;
        }

        Renderer PartWith(Material m)
        {
            go = GameObject.CreatePrimitive(PrimitiveType.Quad);
            var r = go.GetComponent<Renderer>();
            r.sharedMaterial = m;
            return r;
        }

        [Test]
        public void APartWithItsOwnTextureShowsIt()
        {
            own = new Texture2D(4, 4) { name = "saber_engine_glow" };
            var gltfMat = GltfMaterial(own);
            gltfMat.SetTextureScale("_BaseMap", new Vector2(1f, -1f));   // glTF's Y flip
            var found = ModShipBuilder.OwnTexture(new[] { PartWith(gltfMat) });
            Assert.AreSame(own, found.tex);
            Assert.AreEqual(new Vector2(1f, -1f), found.scale);

            var mat = ModShipBuilder.AddPartMaterial(Ship(), null, Glow(), found);
            Assert.IsNotNull(mat);
            made.Add(mat);
            Assert.AreSame(own, mat.GetTexture("_MainTex"), "the part's own texture, not the race's glow sprite");
            Assert.AreEqual(new Vector2(1f, -1f), mat.GetTextureScale("_MainTex"));
            var gameMat = ModShipBuilder.AddPartMaterial(Ship(), null, Glow());
            Assert.AreEqual(gameMat.shader, mat.shader, "still drawn like the game's glow");
        }

        [Test]
        public void APartWithoutTexturesKeepsTheGamesGlow()
        {
            var plain = GltfMaterial();   // an .aem import's untextured "hull" material, or a GLB without any (empty base map)
            var found = ModShipBuilder.OwnTexture(new[] { PartWith(plain) });
            Assert.IsNull(found.tex);
            var a = ModShipBuilder.AddPartMaterial(Ship(), null, Glow(), found);
            var b = ModShipBuilder.AddPartMaterial(Ship(), null, Glow());
            Assert.AreSame(b, a, "the game's shared material, not a copy");
        }

        [Test]
        public void TheBuilderSetsAndClearsAPartsTexture()
        {
            var s = new ProjectShip(new JObject());
            s.AddPart(CustomAddPart.EngineGlow, "models/glow.glb");
            Assert.IsNull(s.AddParts[0].texture);
            s.SetPartTexture(0, "textures/glow.png");
            Assert.AreEqual("textures/glow.png", s.AddParts[0].texture);
            s.SetPartTexture(0, null);
            Assert.IsNull(s.AddParts[0].texture);
            s.SetPartTexture(5, "textures/glow.png");   // no such part: nothing happens
            Assert.AreEqual(1, s.AddParts.Count);
        }
    }
}
