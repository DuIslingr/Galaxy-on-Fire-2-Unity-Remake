// GoF2SpaceSceneBuilder.cs  (Editor only)
// Menu "GoF2/Create Space Scene": Assets/Scenes/Space.unity, the flight level. The scene itself is almost empty
// (camera, two directional lights, post-processing, GoF2SpaceLevel, the flight HUD); GoF2SpaceLevel builds the
// current station orbit at runtime from the data, like the original's Level::init. This also makes what it loads by name:
//   Resources/GoF2Backdrop/<texture>.mat  sun (additive), planet and ring (alpha) materials, space dust + fog sprites
//   Resources/GoF2Sky/                    stars + nebula cubemaps (GoF2 > Bake Space Skies), if missing
// Build settings: MainMenu 0, Space 1, FlightTest 2. The main menu's "Start new game" loads Space.

using System.IO;
using System.Linq;
using GoF2Remake.World;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.Rendering.Universal;
using UnityEngine.EventSystems;
using UnityEngine.InputSystem.UI;
using UnityEngine.UIElements;

namespace GoF2Remake.EditorTools
{
    public static class GoF2SpaceSceneBuilder
    {
        public const string ScenePath = "Assets/Scenes/Space.unity";
        const string BackdropDir = GoF2ImportSettings.Root + "/Resources/" + GoF2Backdrop.MaterialFolder;

        [MenuItem("GoF2/Create Space Scene", priority = 12)]
        public static void Build()
        {
            try
            {
                BuildBackdropMaterials();
                if (!File.Exists($"{GoF2SkyboxBaker.SpaceSkyDir}/nebula_018.png")) GoF2SkyboxBaker.BakeSpaceSkies();
                BuildScene();
            }
            catch (System.Exception e) { Debug.LogException(e); }
        }

        // ---- materials ---------------------------------------------------------------------------------------

        public static void BuildBackdropMaterials()
        {
            Directory.CreateDirectory(BackdropDir);
            var backdrop = Shader.Find("GoF2/Backdrop");
            var dust = Shader.Find("GoF2/SpaceDust");
            string T = GoF2ImportSettings.Root + "/Textures";

            // Suns: RGB, drawn additive (blend 2). Planets and rings: alpha (blend 1).
            foreach (var path in Directory.GetFiles($"{T}/main/suns", "*.png")
                         .Concat(Directory.GetFiles($"{T}/supernova/suns", "*.png"))
                         .Append($"{T}/supernova/fx/sn_supernova.png"))
                MakeMaterial(path, backdrop, BlendMode.One, BlendMode.One, 2900);
            foreach (var dir in new[] { "main", "valkyrie", "supernova" })
            {
                string d = $"{T}/{dir}/planets";
                if (!Directory.Exists(d)) continue;
                foreach (var path in Directory.GetFiles(d, "*.png"))
                    MakeMaterial(path, backdrop, BlendMode.SrcAlpha, BlendMode.OneMinusSrcAlpha,
                                 Path.GetFileNameWithoutExtension(path) == "sn_planet_ring" ? 2902 : 2901);
            }
            // Space dust (material 20092) and fog sprites (20095 fog.png, 20137 v_fog_ice.png): additive.
            MakeMaterial($"{T}/main/misc/space_particle_diffuse.png", dust, BlendMode.SrcAlpha, BlendMode.One, 3000, "space_particle");
            MakeMaterial($"{T}/main/fx/fog.png", dust, BlendMode.SrcAlpha, BlendMode.One, 3000);
            MakeMaterial($"{T}/valkyrie/fx/v_fog_ice.png", dust, BlendMode.SrcAlpha, BlendMode.One, 3000);
            AssetDatabase.SaveAssets();
        }

        static void MakeMaterial(string texPath, Shader shader, BlendMode src, BlendMode dst, int queue, string name = null)
        {
            texPath = texPath.Replace('\\', '/');
            var tex = AssetDatabase.LoadAssetAtPath<Texture2D>(texPath);
            if (tex == null) { Debug.LogWarning($"GoF2: missing texture {texPath}"); return; }
            var ti = (TextureImporter)AssetImporter.GetAtPath(texPath);
            if (ti != null && ti.wrapMode != TextureWrapMode.Clamp) { ti.wrapMode = TextureWrapMode.Clamp; ti.SaveAndReimport(); }

            string matPath = $"{BackdropDir}/{name ?? Path.GetFileNameWithoutExtension(texPath)}.mat";
            var mat = AssetDatabase.LoadAssetAtPath<Material>(matPath);
            if (mat == null) { mat = new Material(shader); AssetDatabase.CreateAsset(mat, matPath); }
            mat.shader = shader;
            mat.SetTexture("_MainTex", tex);
            mat.SetFloat("_SrcBlend", (float)src);
            mat.SetFloat("_DstBlend", (float)dst);
            mat.renderQueue = queue;
            EditorUtility.SetDirty(mat);
        }

        // ---- scene -------------------------------------------------------------------------------------------

        static void BuildScene()
        {
            var scene = EditorSceneManager.NewScene(NewSceneSetup.EmptyScene, NewSceneMode.Single);

            var camGo = new GameObject("Main Camera") { tag = "MainCamera" };
            var cam = camGo.AddComponent<Camera>();
            camGo.AddComponent<AudioListener>();
            var camData = camGo.AddComponent<UniversalAdditionalCameraData>();
            camData.renderPostProcessing = true;
            camData.antialiasing = AntialiasingMode.SubpixelMorphologicalAntiAliasing;
            cam.clearFlags = CameraClearFlags.Skybox;

            var sun = new GameObject("Sun (LIGHT0)").AddComponent<Light>();
            sun.type = LightType.Directional;
            sun.shadows = LightShadows.Soft;
            var planet = new GameObject("Planet light (LIGHT1)").AddComponent<Light>();
            planet.type = LightType.Directional;
            planet.shadows = LightShadows.None;

            GoF2PostProcessing.AddToScene();

            var level = new GameObject("Space Level").AddComponent<GoF2SpaceLevel>();
            level.mainCamera = cam;
            level.sunLight = sun;
            level.planetLight = planet;

            // Flight HUD (touch controls / keyboard / controller hints, GoF2InputMode).
            var hudGo = new GameObject("Flight HUD");
            var panel = hudGo.AddComponent<PanelRenderer>();
            panel.panelSettings = AssetDatabase.LoadAssetAtPath<PanelSettings>($"{GoF2ImportSettings.Root}/UI/GoF2PanelSettings.asset");
            panel.visualTreeAsset = AssetDatabase.LoadAssetAtPath<VisualTreeAsset>($"{GoF2ImportSettings.Root}/UI/Flight/FlightHud.uxml");
            EditorUtility.SetDirty(panel);
            hudGo.AddComponent<GoF2Remake.UI.GoF2FlightHud>();
            var es = new GameObject("EventSystem");
            es.AddComponent<EventSystem>();
            es.AddComponent<InputSystemUIInputModule>();

            RenderSettings.skybox = AssetDatabase.LoadAssetAtPath<Material>($"{GoF2SkyboxBaker.SpaceSkyDir}/SpaceSky.mat");
            Directory.CreateDirectory("Assets/Scenes");
            EditorSceneManager.SaveScene(scene, ScenePath);

            var list = EditorBuildSettings.scenes.Where(s => s.path != ScenePath).ToList();
            int menu = list.FindIndex(s => s.path.EndsWith("MainMenu.unity"));
            list.Insert(menu >= 0 ? menu + 1 : 0, new EditorBuildSettingsScene(ScenePath, true));
            EditorBuildSettings.scenes = list.ToArray();
            Debug.Log($"GoF2: space scene created at {ScenePath}. Press Play (WASD/arrows steer, Q/E throttle, Space boost).");
        }
    }
}
