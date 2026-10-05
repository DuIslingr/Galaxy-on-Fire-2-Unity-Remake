// ModAssetsBuilder.cs  (Editor only)
// "GoF2 > Build > Mod Assets": Resources/GoF2Mods/ModAssets (Modding.ModAssets) and its URP Lit template materials
// (Resources/GoF2Mods/ModLit_*.mat): what the game builds mods' ships from at run time.

using System.IO;
using GoF2Remake.Modding;
using UnityEditor;
using UnityEngine;
using UnityEngine.Rendering;

namespace GoF2Remake.EditorTools
{
    public static class ModAssetsBuilder
    {
        const string Dir = ImportSettings.Root + "/Resources/GoF2Mods";
        const string EngineGlow = ImportSettings.Root + "/Materials/mat_34813_ship_engine_glow.mat";
        const string FxAdditive = ImportSettings.Root + "/Materials/mat_27250_sprite_fire.mat";
        const string FxAlpha = ImportSettings.Root + "/Materials/mat_20101_sprite_smoke.mat";

        [MenuItem("GoF2/Build/Mod Assets", priority = 209)]
        public static void Build()
        {
            Directory.CreateDirectory(Dir);
            string path = Dir + "/ModAssets.asset";
            var a = AssetDatabase.LoadAssetAtPath<ModAssets>(path);
            if (a == null) { a = ScriptableObject.CreateInstance<ModAssets>(); AssetDatabase.CreateAsset(a, path); }
            a.engineGlow = AssetDatabase.LoadAssetAtPath<Material>(EngineGlow);
            if (a.engineGlow == null) Debug.LogWarning($"GoF2: {EngineGlow} missing (Build Materials And Prefabs)");
            a.fxAdditive = AssetDatabase.LoadAssetAtPath<Material>(FxAdditive);
            a.fxAlpha = AssetDatabase.LoadAssetAtPath<Material>(FxAlpha);
            if (a.fxAdditive == null || a.fxAlpha == null) Debug.LogWarning($"GoF2: {FxAdditive} / {FxAlpha} missing (Build Materials And Prefabs)");
            a.litOpaque = Lit("ModLit_Opaque", false, false, false);
            a.litOpaqueDetail = Lit("ModLit_OpaqueDetail", false, false, true);
            a.litCutout = Lit("ModLit_Cutout", true, false, false);
            a.litCutoutDetail = Lit("ModLit_CutoutDetail", true, false, true);
            a.litTransparent = Lit("ModLit_Transparent", false, true, false);
            a.litTransparentDetail = Lit("ModLit_TransparentDetail", false, true, true);
            var shader = Shader.Find("Hidden/GoF2/MetallicRoughnessToGloss");
            string mrPath = Dir + "/ModMetallicRoughness.mat";
            var mr = AssetDatabase.LoadAssetAtPath<Material>(mrPath);
            if (mr == null && shader != null) { mr = new Material(shader); AssetDatabase.CreateAsset(mr, mrPath); }
            a.metallicRoughness = mr;
            EditorUtility.SetDirty(a);
            AssetDatabase.SaveAssets();
            Debug.Log("GoF2: Resources/GoF2Mods/ModAssets built.");
        }

        /// <summary>A URP Lit template with the keywords every mod material uses (normal map, metallic map, emission) and the
        /// surface type, so the build keeps those variants. URP sets Lit's keywords from what the material holds when it is
        /// saved, so the templates hold placeholder textures (a flat normal, white, grey details) and a faint emission;
        /// ModMaterials replaces them.</summary>
        static Material Lit(string name, bool cutout, bool transparent, bool detail)
        {
            string path = $"{Dir}/{name}.mat";
            var shader = Shader.Find("Universal Render Pipeline/Lit");
            var m = AssetDatabase.LoadAssetAtPath<Material>(path);
            bool create = m == null;
            if (create) m = new Material(shader) { name = name };
            else m.shader = shader;
            Texture2D Tex(string n) => AssetDatabase.LoadAssetAtPath<Texture2D>($"{Dir}/{n}.png");
            m.SetTexture("_BumpMap", Tex("ModFlatNormal"));
            m.SetTexture("_MetallicGlossMap", Tex("ModWhite"));
            m.SetTexture("_EmissionMap", Tex("ModWhite"));
            m.EnableKeyword("_NORMALMAP");
            m.EnableKeyword("_METALLICSPECGLOSSMAP");
            m.EnableKeyword("_EMISSION");
            m.SetColor("_EmissionColor", new Color(1f / 255f, 1f / 255f, 1f / 255f, 1f));
            m.globalIlluminationFlags = MaterialGlobalIlluminationFlags.None;
            m.SetFloat("_SmoothnessTextureChannel", 0f);
            m.SetFloat("_AlphaClip", cutout ? 1f : 0f);
            m.SetFloat("_Cutoff", 0.5f);
            if (cutout) m.EnableKeyword("_ALPHATEST_ON"); else m.DisableKeyword("_ALPHATEST_ON");
            m.SetFloat("_Surface", transparent ? 1f : 0f);
            m.SetFloat("_Blend", transparent ? 1f : 0f);   // premultiplied: highlights stay bright on glass
            m.SetFloat("_SrcBlend", (float)BlendMode.One);
            m.SetFloat("_DstBlend", transparent ? (float)BlendMode.OneMinusSrcAlpha : (float)BlendMode.Zero);
            m.SetFloat("_SrcBlendAlpha", (float)BlendMode.One);
            m.SetFloat("_DstBlendAlpha", transparent ? (float)BlendMode.OneMinusSrcAlpha : (float)BlendMode.Zero);
            m.SetFloat("_ZWrite", transparent ? 0f : 1f);
            if (transparent)
            {
                m.EnableKeyword("_SURFACE_TYPE_TRANSPARENT");
                m.EnableKeyword("_ALPHAPREMULTIPLY_ON");
                m.SetOverrideTag("RenderType", "Transparent");
                m.renderQueue = (int)RenderQueue.Transparent;
                m.SetShaderPassEnabled("DepthOnly", false);
                m.SetShaderPassEnabled("ShadowCaster", false);
            }
            else
            {
                m.DisableKeyword("_SURFACE_TYPE_TRANSPARENT");
                m.DisableKeyword("_ALPHAPREMULTIPLY_ON");
                m.SetOverrideTag("RenderType", cutout ? "TransparentCutout" : "Opaque");
                m.renderQueue = cutout ? (int)RenderQueue.AlphaTest : -1;
                m.SetShaderPassEnabled("DepthOnly", true);
                m.SetShaderPassEnabled("ShadowCaster", true);
            }
            m.SetTexture("_DetailAlbedoMap", detail ? Tex("ModGrey") : null);
            m.SetTexture("_DetailNormalMap", detail ? Tex("ModFlatNormal") : null);
            if (detail) m.EnableKeyword("_DETAIL_MULX2"); else m.DisableKeyword("_DETAIL_MULX2");
            if (create) AssetDatabase.CreateAsset(m, path); else EditorUtility.SetDirty(m);
            return m;
        }
    }
}
