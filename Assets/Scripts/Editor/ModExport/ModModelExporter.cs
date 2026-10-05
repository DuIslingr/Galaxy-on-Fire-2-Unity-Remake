// ModModelExporter.cs  (Editor only; its own assembly, GoF2.ModExport.Editor: glTFast.Export is not auto-referenced)
// Project window, right-click a model: "GoF2 > Export Model As GLB (Mods)" writes it as a binary glTF next to the asset,
// ready to go into a mod's folder (Modding/README.md, ships.json "model"). Its root is put at the origin without a turn
// (ModShipBuilder turns the model by modelYaw and scales it to modelLength, like PR #34's CustomShipBuilder did with the
// FBX). Export(..., plainMaterials: true) writes every material as plain white without textures: for a ship whose
// ships.json "materials" entries replace them all (the PR #34 ships), so the GLB carries only the geometry.

using System.IO;
using GLTFast.Export;
using GLTFast.Logging;
using UnityEditor;
using UnityEngine;

namespace GoF2Remake.EditorTools
{
    public static class ModModelExporter
    {
        [MenuItem("Assets/GoF2/Export Model As GLB (Mods)", priority = 2010)]
        static void ExportSelected()
        {
            foreach (var o in Selection.objects)
            {
                string path = AssetDatabase.GetAssetPath(o);
                if (!(o is GameObject go)) continue;
                string glb = Path.ChangeExtension(path, ".glb");
                Debug.Log(Export(go, glb, false) ? $"GoF2: {glb} written" : $"GoF2: exporting {path} failed");
            }
        }

        [MenuItem("Assets/GoF2/Export Model As GLB (Mods)", true)]
        static bool CanExport() => Selection.activeObject is GameObject;

        /// <summary>The model asset as a GLB file at 'glbPath' (outside Assets is fine).</summary>
        public static bool Export(GameObject modelAsset, string glbPath, bool plainMaterials)
        {
            var go = (GameObject)Object.Instantiate(modelAsset);
            try
            {
                go.name = modelAsset.name;
                go.transform.localPosition = Vector3.zero;
                go.transform.localRotation = Quaternion.identity;   // the ship builder turns the model itself
                var export = new GameObjectExport(
                    new ExportSettings { Format = GltfFormat.Binary, FileConflictResolution = FileConflictResolution.Overwrite },
                    new GameObjectExportSettings { OnlyActiveInHierarchy = false },
                    plainMaterials ? new PlainMaterialExport() : null);
                if (!export.AddScene(new[] { go }, modelAsset.name)) return false;
                Directory.CreateDirectory(Path.GetDirectoryName(Path.GetFullPath(glbPath)));
                var task = export.SaveToFileAndDispose(glbPath, true);
                return task.IsCompleted && task.Result;
            }
            finally { Object.DestroyImmediate(go); }
        }

        /// <summary>Every material as plain white, its name kept, no textures.</summary>
        class PlainMaterialExport : IMaterialExport
        {
            public bool ConvertMaterial(Material uMaterial, out GLTFast.Schema.Material material, IGltfWritable gltf, ICodeLogger logger)
            {
                material = new GLTFast.Schema.Material { name = uMaterial != null ? uMaterial.name : "material" };
                material.pbrMetallicRoughness = new GLTFast.Schema.PbrMetallicRoughness { metallicFactor = 0f, roughnessFactor = 0.5f };
                return true;
            }
        }
    }
}
