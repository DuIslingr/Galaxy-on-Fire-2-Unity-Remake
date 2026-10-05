// ModBackdrop.cs
// Remake mods: the planets and suns of the mods' stations and systems (stations.json "planetTexture", systems.json
// "sunTexture"): Backdrop's texture name "mod:<mod id>|<path>" makes a material like the game's own (a copy of
// planet_000_big / sun_000 in Resources/GoF2Backdrop, the GoF2/Backdrop shader) with the mod's PNG. The PNG is decoded in
// the background with the station models (Preload, ModStations), so building an orbit finds it made.

using System.Collections.Generic;
using System.Threading.Tasks;
using UnityEngine;

namespace GoF2Remake.Modding
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class ModBackdrop
    {
        public const string Prefix = "mod:";

        static readonly Dictionary<string, Material> materials = new Dictionary<string, Material>();
        static int revision = -1;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics() { materials.Clear(); revision = -1; }

        public static bool IsMod(string texture) => texture != null && texture.StartsWith(Prefix);

        static bool Split(string name, out ModInfo mod, out string path)
        {
            mod = null;
            path = null;
            if (!IsMod(name)) return false;
            int bar = name.IndexOf('|');
            if (bar < 0) return false;
            mod = ModManager.Find(name.Substring(Prefix.Length, bar - Prefix.Length));
            path = name.Substring(bar + 1);
            return mod != null;
        }

        /// <summary>Decodes the PNG in the background (ModMaterials' cache).</summary>
        public static Task Preload(string name) =>
            Split(name, out var mod, out var path) ? ModMaterials.PreloadTexture(mod, path, false) : Task.CompletedTask;

        /// <summary>The texture of a "mod:" name (a skybox image; null: unreadable), decoded on first use when Preload hasn't.</summary>
        public static Texture2D Texture(string name) => Split(name, out var mod, out var path) ? ModMaterials.Texture(mod, path, false) : null;

        /// <summary>The material for a "mod:" texture name; 'sun': like the suns (else like the planets). Null: unreadable.</summary>
        public static Material Material(string name, bool sun)
        {
            if (revision != ModManager.Revision) { foreach (var m in materials.Values) if (m != null) Object.Destroy(m); materials.Clear(); revision = ModManager.Revision; }
            if (materials.TryGetValue(name, out var mat)) return mat;
            if (!Split(name, out var mod, out var path)) return null;
            var tex = ModMaterials.Texture(mod, path, false);
            var template = Resources.Load<Material>($"GoF2Backdrop/{(sun ? "sun_000" : "planet_000_big")}");
            if (tex == null || template == null) return materials[name] = null;
            tex.wrapMode = TextureWrapMode.Clamp;
            mat = new Material(template) { name = name };
            mat.SetTexture("_MainTex", tex);
            return materials[name] = mat;
        }
    }
}
