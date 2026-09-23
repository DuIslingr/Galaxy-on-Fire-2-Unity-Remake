// GoF2SkyboxBaker.cs  (Editor only)
// The original draws the sky as meshes around the camera (Level::createSpace / Level::renderBG): first the
// stars layer (skybox_stars, texture skybox_stars_00(systemIndex % 3)), then the nebula mesh skybox_0XX
// (texture = SolarSystem textureIndex) added on top. This renders both into the six faces of a cubemap so
// the sky is a regular Unity skybox, which also drives URP ambient light and reflections.
//
// Menu "GoF2/Bake Skyboxes": Assets/GoF2/Skyboxes/skybox_0XX.png (6-face horizontal strip, imported as a
// Cubemap) + skybox_0XX.mat (Skybox/Cubemap).

using System.IO;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.Rendering.Universal;

namespace GoF2Remake.EditorTools
{
    public static class GoF2SkyboxBaker
    {
        public const string OutDir = GoF2ImportSettings.Root + "/Skyboxes";
        public const int SkyboxCount = 11;
        const int FaceSize = 1024;   // the nebula texture gives each face a 1024x1024 quadrant

        // Unity's horizontal-strip cubemap layout: +X, -X, +Y, -Y, +Z, -Z, each face as seen from the centre.
        static readonly Vector3[] FaceForward = { Vector3.right, Vector3.left, Vector3.up, Vector3.down, Vector3.forward, Vector3.back };
        static readonly Vector3[] FaceUp = { Vector3.up, Vector3.up, Vector3.back, Vector3.forward, Vector3.up, Vector3.up };

        public static string MaterialPath(int index) => $"{OutDir}/skybox_{index:000}.mat";

        [MenuItem("GoF2/Bake Skyboxes", priority = 23)]
        public static void BakeAll()
        {
            try
            {
                for (int i = 0; i < SkyboxCount; i++)
                {
                    EditorUtility.DisplayProgressBar("GoF2", $"Baking skybox_{i:000}", (float)i / SkyboxCount);
                    Bake(i);
                }
            }
            finally { EditorUtility.ClearProgressBar(); }
            Debug.Log($"GoF2: {SkyboxCount} skyboxes baked to {OutDir}.");
        }

        /// <summary>Bakes skybox_{index} (+ its stars layer) and returns its skybox material.</summary>
        public static Material Bake(int index)
        {
            Directory.CreateDirectory(OutDir);
            string name = $"skybox_{index:000}";
            var nebulaMesh = LoadMesh($"Models/main/skyboxes/{name}.fbx");
            var starsMesh = LoadMesh("Models/main/skyboxes/skybox_stars.fbx");
            var nebulaTex = AssetDatabase.LoadAssetAtPath<Texture2D>($"{GoF2ImportSettings.Root}/Textures/main/skyboxes/{name}.png");
            var starsTex = AssetDatabase.LoadAssetAtPath<Texture2D>($"{GoF2ImportSettings.Root}/Textures/main/skyboxes/skybox_stars_{index % 3:000}.png");
            if (nebulaMesh == null || nebulaTex == null) { Debug.LogError($"GoF2: {name} mesh or texture missing"); return null; }

            var strip = new Texture2D(FaceSize * 6, FaceSize, TextureFormat.RGB24, false);
            var scene = EditorSceneManager.NewPreviewScene();
            var rt = new RenderTexture(FaceSize, FaceSize, 24, RenderTextureFormat.ARGB32);
            var mats = new Material[2];
            try
            {
                // Stars first (opaque), nebula added on top, as Level::renderBG draws them.
                mats[0] = Layer(scene, starsMesh, Shader.Find("GoF2/Unlit"), starsTex);
                mats[1] = Layer(scene, nebulaMesh, Shader.Find("GoF2/Additive"), nebulaTex);

                var camGo = new GameObject("SkyboxCamera");
                UnityEngine.SceneManagement.SceneManager.MoveGameObjectToScene(camGo, scene);
                var cam = camGo.AddComponent<Camera>();
                cam.scene = scene;
                cam.clearFlags = CameraClearFlags.SolidColor;
                cam.backgroundColor = Color.black;
                cam.fieldOfView = 90f;
                cam.aspect = 1f;
                cam.nearClipPlane = 0.1f;
                cam.farClipPlane = 1000f;
                cam.targetTexture = rt;
                cam.GetUniversalAdditionalCameraData().renderPostProcessing = false;

                var prev = RenderTexture.active;
                for (int f = 0; f < 6; f++)
                {
                    camGo.transform.rotation = Quaternion.LookRotation(FaceForward[f], FaceUp[f]);
                    cam.Render();
                    RenderTexture.active = rt;
                    strip.ReadPixels(new Rect(0, 0, FaceSize, FaceSize), f * FaceSize, 0);
                }
                RenderTexture.active = prev;
                strip.Apply();
                cam.targetTexture = null;
            }
            finally
            {
                EditorSceneManager.ClosePreviewScene(scene);
                rt.Release();
                Object.DestroyImmediate(rt);
                foreach (var m in mats) if (m != null) Object.DestroyImmediate(m);
            }

            string pngPath = $"{OutDir}/{name}.png";
            File.WriteAllBytes(pngPath, strip.EncodeToPNG());
            Object.DestroyImmediate(strip);
            AssetDatabase.ImportAsset(pngPath, ImportAssetOptions.ForceSynchronousImport);
            var ti = (TextureImporter)AssetImporter.GetAtPath(pngPath);
            ti.textureShape = TextureImporterShape.TextureCube;
            ti.generateCubemap = TextureImporterGenerateCubemap.AutoCubemap;
            ti.mipmapEnabled = true;
            ti.maxTextureSize = FaceSize * 8;
            ti.textureCompression = TextureImporterCompression.CompressedHQ;
            ti.SaveAndReimport();
            var cube = AssetDatabase.LoadAssetAtPath<Cubemap>(pngPath);

            string matPath = MaterialPath(index);
            var mat = AssetDatabase.LoadAssetAtPath<Material>(matPath);
            if (mat == null)
            {
                mat = new Material(Shader.Find("Skybox/Cubemap"));
                AssetDatabase.CreateAsset(mat, matPath);
            }
            mat.SetTexture("_Tex", cube);
            mat.SetFloat("_Exposure", 1f);
            EditorUtility.SetDirty(mat);
            AssetDatabase.SaveAssets();
            return mat;
        }

        static Material Layer(UnityEngine.SceneManagement.Scene scene, Mesh mesh, Shader shader, Texture tex)
        {
            if (mesh == null) return null;
            var go = new GameObject(mesh.name);
            UnityEngine.SceneManagement.SceneManager.MoveGameObjectToScene(go, scene);
            go.AddComponent<MeshFilter>().sharedMesh = mesh;
            var mat = new Material(shader);
            mat.SetTexture("_MainTex", tex);
            mat.SetFloat("_Cull", 0f); // seen from inside
            var r = go.AddComponent<MeshRenderer>();
            r.sharedMaterial = mat;
            r.shadowCastingMode = ShadowCastingMode.Off;
            return mat;
        }

        static Mesh LoadMesh(string rel)
        {
            foreach (var o in AssetDatabase.LoadAllAssetsAtPath($"{GoF2ImportSettings.Root}/{rel}"))
                if (o is Mesh m) return m;
            return null;
        }
    }
}
