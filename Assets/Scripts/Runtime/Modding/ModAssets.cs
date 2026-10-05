// ModAssets.cs
// What the game needs at run time to build a mod's ship (Resources/GoF2Mods/ModAssets, made by "GoF2 > Build > Mod
// Assets", ModAssetsBuilder): the player engine glow material every ship's exhaust uses (mat_34813, GoF2/Additive: also
// the template of the throttle glows and their trails), and the URP Lit template materials a mod's materials are copied
// from. The templates fix the shader keywords (normal map, metallic / smoothness map, emission always on; opaque / alpha
// clip / transparent, each with and without URP's detail maps), so those variants are in every build (a material made
// at run time from Shader.Find would need variants the build stripped). metallicRoughness converts a glTF
// metallic-roughness texture (B metal, G roughness) into URP's metallic (R) / smoothness (A) map. fxAdditive / fxAlpha:
// the GoF2 Shader Graph materials a mod weapon's sprites and textured models are copied from (ModWeapons).

using UnityEngine;

namespace GoF2Remake.Modding
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public class ModAssets : ScriptableObject
    {
        public const string ResourcePath = "GoF2Mods/ModAssets";

        [Tooltip("The player ships' engine glow (mat_34813_ship_engine_glow, GoF2/Additive).")]
        public Material engineGlow;
        [Tooltip("URP Lit, opaque / alpha clip / transparent (premultiplied), each without and with detail maps.")]
        public Material litOpaque, litOpaqueDetail, litCutout, litCutoutDetail, litTransparent, litTransparentDetail;
        [Tooltip("The weapon fx templates of mod items (items.json \"fx\", ModWeapons): sprite_fire (GoF2/Additive) and sprite_smoke (GoF2/AlphaBlend).")]
        public Material fxAdditive, fxAlpha;
        [Tooltip("Hidden/GoF2/MetallicRoughnessToGloss: a glTF metallic-roughness texture to URP's metallic / smoothness map.")]
        public Material metallicRoughness;

        static ModAssets loaded;

        public static ModAssets Get()
        {
            if (loaded == null) loaded = Resources.Load<ModAssets>(ResourcePath);
            if (loaded == null) Debug.LogWarning("Mods: Resources/" + ResourcePath + " missing (GoF2 > Build > Mod Assets): mod ships can't be built");
            return loaded;
        }

        public Material Lit(bool cutout, bool transparent, bool detail) =>
            transparent ? (detail ? litTransparentDetail : litTransparent)
            : cutout ? (detail ? litCutoutDetail : litCutout)
            : (detail ? litOpaqueDetail : litOpaque);
    }
}
