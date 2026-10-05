// ModGltfMaterials.cs
// glTFast's material generator for mods' models: every glTF material becomes a copy of the game's URP Lit templates
// (ModMaterials.FromGltf) instead of glTFast's own shader graphs, which builds wouldn't carry.

using GLTFast;
using GLTFast.Logging;
using GLTFast.Materials;
using GLTFast.Schema;

namespace GoF2Remake.Modding
{
    public class ModGltfMaterials : IMaterialGenerator
    {
        public UnityEngine.Material GetDefaultMaterial(bool pointsSupport = false) => ModMaterials.Default();

        public UnityEngine.Material GenerateMaterial(MaterialBase gltfMaterial, IGltfReadable gltf, bool pointsSupport = false) =>
            ModMaterials.FromGltf(gltfMaterial, gltf);

        public void SetLogger(ICodeLogger logger) { }
    }
}
