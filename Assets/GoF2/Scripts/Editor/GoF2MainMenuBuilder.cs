// GoF2MainMenuBuilder.cs  (Editor only)
// Menu "GoF2/Create Main Menu Scene": builds Assets/Scenes/MainMenu.unity and the assets it needs.
//   - UI images cut from the original atlases: GoF2 / FISHLABS / ABYSS ENGINE logos (gof2_logos_1440.png,
//     images 7002 / 7001 / 7000) and the Select Campaign cards (gof2_campaign_select_ipad_large.png,
//     images 9500-9505), plus two generated shading gradients.
//   - Inter font assets (SIL Open Font License), PanelSettings with the GoF2 theme, a menu post-processing
//     profile, and the scene: random station backdrop in its system's skybox (ModMainMenu::OnInitialize),
//     slow cinematic camera, background traffic, asteroids, UI Toolkit menu, music.

using System.IO;
using System.Linq;
using GoF2Remake.UI;
using GoF2Remake.Visuals;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.InputSystem.UI;
using UnityEngine.Rendering;
using UnityEngine.Rendering.Universal;
using UnityEngine.TextCore.Text;
using UnityEngine.UIElements;

namespace GoF2Remake.EditorTools
{
    public static class GoF2MainMenuBuilder
    {
        const string UiDir = GoF2ImportSettings.Root + "/UI";
        const string MenuDir = UiDir + "/MainMenu";
        const string ImageDir = MenuDir + "/Images";
        const string ScenePath = "Assets/Scenes/MainMenu.unity";

        // Background set: (assembled station prefab, skybox = systems.json textureIndex of its system, yaw).
        static readonly (string station, int skybox, float yaw)[] Stations =
        {
            ("station_000_nivelian", 4, 0f),    // Neh'bru, Suteo
            ("station_007_terran", 2, 0f),      // Pan system
            ("station_021_midorian", 8, 0f),    // Eanya
            ("station_049_nivelian", 7, 0f),    // Weymire
            ("station_056_terran", 3, 0f),      // Union
            ("station_070_terran", 5, 0f),      // Magnetar
            ("station_077_midorian", 9, 0f),    // Mido
            ("station_vossk", 9, 0f),           // Vossk space
        };

        static readonly (string code, string name)[] Languages =
        {
            ("en", "English"), ("de", "Deutsch"), ("fr", "Français"), ("es", "Español"),
            ("it", "Italiano"), ("pl", "Polski"), ("ru", "Русский"), ("pt", "Português (Brasil)"),
        };

        [MenuItem("GoF2/Create Main Menu Scene", priority = 3)]
        public static void Build()
        {
            if (!EditorSceneManager.SaveCurrentModifiedScenesIfUserWantsTo()) return;
            BuildImages();
            ConfigureSplashScreen();
            BuildAppIcons();
            BuildFonts();
            var panelSettings = BuildPanelSettings();
            var profile = BuildVolumeProfile();
            for (int i = 0; i < GoF2SkyboxBaker.SkyboxCount; i++)
                if (AssetDatabase.LoadAssetAtPath<Material>(GoF2SkyboxBaker.MaterialPath(i)) == null) GoF2SkyboxBaker.Bake(i);
            AssetDatabase.ImportAsset(MenuDir, ImportAssetOptions.ImportRecursive | ImportAssetOptions.ForceUpdate);
            BuildScene(panelSettings, profile);
        }

        // ---- images ------------------------------------------------------------------------------

        static void BuildImages()
        {
            Directory.CreateDirectory(ImageDir);
            var logos = Load($"{GoF2ImportSettings.Root}/Textures/textures/gof2_logos_1440.png");
            // Rects from _texture_manifest.json (x, y, w, h, top-left origin).
            Save(Crop(logos, 269, 71, 670, 207), "logo_gof2");
            Save(Crop(logos, 1, 71, 266, 303), "logo_fishlabs");   // ABYSS ENGINE (7000) is replaced by the Unity logo

            // 2048 cards sheet: 3 x 2 grid of cards (blue = normal, orange = selected).
            var cards = Load($"{GoF2ImportSettings.Root}/Textures/textures/gof2_campaign_select_ipad_large.png");
            Save(CardAt(cards, 1, 1), "card_gof2");
            Save(CardAt(cards, 1, 0), "card_gof2_hover");
            Save(CardAt(cards, 1, 2), "card_valkyrie");
            Save(CardAt(cards, 0, 0), "card_valkyrie_hover");
            Save(CardAt(cards, 0, 1), "card_supernova");
            Save(CardAt(cards, 0, 2), "card_supernova_hover");

            Save(Gradient(256, 4, true), "shade_left");
            Save(Gradient(4, 256, false), "shade_bottom");
            AssetDatabase.Refresh();
            foreach (var f in Directory.GetFiles(ImageDir, "*.png"))
            {
                var ti = (TextureImporter)AssetImporter.GetAtPath(f.Replace('\\', '/'));
                ti.textureType = TextureImporterType.Default;
                ti.alphaIsTransparency = true;
                ti.mipmapEnabled = false;
                ti.npotScale = TextureImporterNPOTScale.None;
                ti.wrapMode = TextureWrapMode.Clamp;
                ti.textureCompression = TextureImporterCompression.Uncompressed;
                if (Path.GetFileName(f).StartsWith("logo_"))
                {
                    ti.textureType = TextureImporterType.Sprite;   // also used by the Unity splash screen
                    ti.spriteImportMode = SpriteImportMode.Single;
                }
                ti.SaveAndReimport();
            }
        }

        static Texture2D Load(string path)
        {
            var t = new Texture2D(2, 2, TextureFormat.RGBA32, false);
            t.LoadImage(File.ReadAllBytes(path));
            return t;
        }

        static Texture2D Crop(Texture2D src, int x, int y, int w, int h)
        {
            var t = new Texture2D(w, h, TextureFormat.RGBA32, false);
            t.SetPixels(src.GetPixels(x, src.height - y - h, w, h));
            t.Apply();
            return t;
        }

        /// <summary>Card in grid cell (row from the top, col): 605 x 943 px cards on a 626 x 966 px pitch
        /// (measured; the sheet is opaque, so the edges can't come from alpha).</summary>
        static Texture2D CardAt(Texture2D sheet, int row, int col) => Crop(sheet, 2 + col * 626, 2 + row * 966, 605, 943);

        static Texture2D Gradient(int w, int h, bool horizontal)
        {
            var t = new Texture2D(w, h, TextureFormat.RGBA32, false);
            var shade = new Color(0.0f, 0.015f, 0.04f);
            for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
            {
                float k = horizontal ? 1f - x / (float)(w - 1) : 1f - y / (float)(h - 1);
                k = Mathf.SmoothStep(0f, 1f, k);
                t.SetPixel(x, y, new Color(shade.r, shade.g, shade.b, k * (horizontal ? 0.88f : 0.75f)));
            }
            t.Apply();
            return t;
        }

        static void Save(Texture2D t, string name) => File.WriteAllBytes($"{ImageDir}/{name}.png", t.EncodeToPNG());

        /// <summary>
        /// Startup logos (MTitle): FISHLABS, then "Made with Unity" where the original showed ABYSS ENGINE.
        /// Unity's splash screen plays them in builds; the menu scene only shows them in the editor.
        /// </summary>
        public static void ConfigureSplashScreen()
        {
            var fishlabs = AssetDatabase.LoadAssetAtPath<Sprite>($"{ImageDir}/logo_fishlabs.png");
            PlayerSettings.SplashScreen.show = true;
            PlayerSettings.SplashScreen.showUnityLogo = true;
            PlayerSettings.SplashScreen.drawMode = PlayerSettings.SplashScreen.DrawMode.AllSequential;
            PlayerSettings.SplashScreen.unityLogoStyle = PlayerSettings.SplashScreen.UnityLogoStyle.LightOnDark;
            PlayerSettings.SplashScreen.animationMode = PlayerSettings.SplashScreen.AnimationMode.Dolly;
            PlayerSettings.SplashScreen.backgroundColor = Color.black;
            PlayerSettings.SplashScreen.logos = fishlabs != null
                ? new[] { PlayerSettings.SplashScreenLogo.Create(2f, fishlabs), PlayerSettings.SplashScreenLogo.CreateWithUnityLogo(2f) }
                : new[] { PlayerSettings.SplashScreenLogo.CreateWithUnityLogo(2f) };
            EditorUtility.SetDirty(Unsupported.GetSerializedAssetInterfaceSingleton("PlayerSettings"));
            AssetDatabase.SaveAssets();
        }

        /// <summary>
        /// App icon: the GoF2 logo on a dark nebula (skybox_003). Android gets an adaptive icon (logo inside the
        /// 66% safe zone on a separate background layer) plus legacy/round icons; other platforms the flat one.
        /// </summary>
        public static void BuildAppIcons()
        {
            string dir = UiDir + "/AppIcon";
            Directory.CreateDirectory(dir);
            const int S = 1024;
            var logo = Load($"{ImageDir}/logo_gof2.png");
            var sky = Load($"{GoF2ImportSettings.Root}/Textures/main/skyboxes/skybox_003.png");

            var bg = new Texture2D(S, S, TextureFormat.RGBA32, false);
            for (int y = 0; y < S; y++)
            for (int x = 0; x < S; x++)
            {
                // 900 px square around the bright part of the nebula (texture rows are bottom-up).
                float u = (560f + x / (float)S * 900f) / sky.width, v = (160f + y / (float)S * 900f) / sky.height;
                var c = sky.GetPixelBilinear(u, v) * 0.6f;
                float vignette = 1f - 0.45f * ((x - S * 0.5f) * (x - S * 0.5f) + (y - S * 0.5f) * (y - S * 0.5f)) / (S * S * 0.5f);
                bg.SetPixel(x, y, new Color(c.r * vignette, c.g * vignette, c.b * vignette + 0.02f, 1f));
            }
            bg.Apply();
            var fg = new Texture2D(S, S, TextureFormat.RGBA32, false);
            fg.SetPixels(new Color[S * S]);
            Stamp(fg, logo, 0.62f);                      // adaptive foreground: inside the 66% safe zone
            var mono = new Texture2D(S, S, TextureFormat.RGBA32, false);   // Android 13 themed icon: white silhouette
            var fgPx = fg.GetPixels();
            for (int i = 0; i < fgPx.Length; i++) fgPx[i] = new Color(1f, 1f, 1f, Mathf.Clamp01(fgPx[i].a * 1.4f - 0.25f));
            mono.SetPixels(fgPx);
            mono.Apply();
            var flat = new Texture2D(S, S, TextureFormat.RGBA32, false);
            flat.SetPixels(bg.GetPixels());
            Stamp(flat, logo, 0.84f);                    // legacy / round / other platforms
            File.WriteAllBytes($"{dir}/icon_background.png", bg.EncodeToPNG());
            File.WriteAllBytes($"{dir}/icon_foreground.png", fg.EncodeToPNG());
            File.WriteAllBytes($"{dir}/icon.png", flat.EncodeToPNG());
            File.WriteAllBytes($"{dir}/icon_monochrome.png", mono.EncodeToPNG());
            AssetDatabase.Refresh();
            foreach (var n in new[] { "icon_background", "icon_foreground", "icon_monochrome", "icon" })
            {
                var ti = (TextureImporter)AssetImporter.GetAtPath($"{dir}/{n}.png");
                ti.alphaIsTransparency = true;
                ti.mipmapEnabled = false;
                ti.textureCompression = TextureImporterCompression.Uncompressed;
                ti.SaveAndReimport();
            }
            var tFlat = AssetDatabase.LoadAssetAtPath<Texture2D>($"{dir}/icon.png");
            var tBg = AssetDatabase.LoadAssetAtPath<Texture2D>($"{dir}/icon_background.png");
            var tFg = AssetDatabase.LoadAssetAtPath<Texture2D>($"{dir}/icon_foreground.png");
            var tMono = AssetDatabase.LoadAssetAtPath<Texture2D>($"{dir}/icon_monochrome.png");

            PlayerSettings.SetIcons(UnityEditor.Build.NamedBuildTarget.Unknown, new[] { tFlat }, IconKind.Any);
            var android = UnityEditor.Build.NamedBuildTarget.Android;
            foreach (var kind in PlayerSettings.GetSupportedIconKinds(android))
            {
                var icons = PlayerSettings.GetPlatformIcons(android, kind);
                foreach (var icon in icons)
                {
                    // Adaptive icons: background, foreground (+ monochrome on newer Unity/Android); else flat.
                    if (icon.minLayerCount >= 3) icon.SetTextures(tBg, tFg, tMono);
                    else if (icon.minLayerCount == 2) icon.SetTextures(tBg, tFg);
                    else icon.SetTexture(tFlat);
                }
                PlayerSettings.SetPlatformIcons(android, kind, icons);
            }
            EditorUtility.SetDirty(Unsupported.GetSerializedAssetInterfaceSingleton("PlayerSettings"));
            AssetDatabase.SaveAssets();
        }

        /// <summary>Alpha-blends 'logo' centred onto 'dst', scaled to widthFraction of its width.</summary>
        static void Stamp(Texture2D dst, Texture2D logo, float widthFraction)
        {
            int w = Mathf.RoundToInt(dst.width * widthFraction), h = Mathf.RoundToInt(w * logo.height / (float)logo.width);
            int x0 = (dst.width - w) / 2, y0 = (dst.height - h) / 2;
            for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
            {
                var c = logo.GetPixelBilinear((x + 0.5f) / w, (y + 0.5f) / h);
                var d = dst.GetPixel(x0 + x, y0 + y);
                float a = c.a + d.a * (1f - c.a);
                var rgb = a > 0f ? (new Color(c.r, c.g, c.b) * c.a + new Color(d.r, d.g, d.b) * d.a * (1f - c.a)) / a : Color.clear;
                dst.SetPixel(x0 + x, y0 + y, new Color(rgb.r, rgb.g, rgb.b, a));
            }
            dst.Apply();
        }

        // ---- fonts, panel, profile -----------------------------------------------------------------

        static void BuildFonts()
        {
            foreach (var n in new[] { "Inter-Regular", "Inter-SemiBold" })
            {
                string path = $"{UiDir}/Fonts/{n}-SDF.asset";
                if (AssetDatabase.LoadAssetAtPath<FontAsset>(path) != null) continue;
                var font = AssetDatabase.LoadAssetAtPath<Font>($"{UiDir}/Fonts/{n}.ttf");
                var fa = FontAsset.CreateFontAsset(font);
                fa.name = $"{n}-SDF";
                AssetDatabase.CreateAsset(fa, path);
                fa.material.name = fa.name + " Material";
                AssetDatabase.AddObjectToAsset(fa.material, fa);
                foreach (var tex in fa.atlasTextures)
                {
                    tex.name = fa.name + " Atlas";
                    AssetDatabase.AddObjectToAsset(tex, fa);
                }
                EditorUtility.SetDirty(fa);
            }
            AssetDatabase.SaveAssets();
        }

        static PanelSettings BuildPanelSettings()
        {
            string path = $"{UiDir}/GoF2PanelSettings.asset";
            var ps = AssetDatabase.LoadAssetAtPath<PanelSettings>(path);
            if (ps == null)
            {
                ps = ScriptableObject.CreateInstance<PanelSettings>();
                AssetDatabase.CreateAsset(ps, path);
            }
            ps.themeStyleSheet = AssetDatabase.LoadAssetAtPath<ThemeStyleSheet>($"{UiDir}/GoF2Theme.tss");
            ps.scaleMode = PanelScaleMode.ScaleWithScreenSize;
            ps.referenceResolution = new Vector2Int(1920, 1080);
            ps.screenMatchMode = PanelScreenMatchMode.MatchWidthOrHeight;
            ps.match = 0.5f;
            EditorUtility.SetDirty(ps);
            AssetDatabase.SaveAssets();
            return ps;
        }

        static VolumeProfile BuildVolumeProfile()
        {
            string path = $"{MenuDir}/MainMenuVolume.asset";
            var profile = AssetDatabase.LoadAssetAtPath<VolumeProfile>(path);
            if (profile != null) return profile;
            profile = ScriptableObject.CreateInstance<VolumeProfile>();
            AssetDatabase.CreateAsset(profile, path);
            var bloom = profile.Add<Bloom>();
            bloom.threshold.Override(1f);
            bloom.intensity.Override(1.6f);
            bloom.scatter.Override(0.72f);
            bloom.highQualityFiltering.Override(true);
            var tone = profile.Add<Tonemapping>();
            tone.mode.Override(TonemappingMode.Neutral);
            var vignette = profile.Add<Vignette>();
            vignette.intensity.Override(0.32f);
            vignette.smoothness.Override(0.45f);
            var color = profile.Add<ColorAdjustments>();
            color.postExposure.Override(0f);
            color.contrast.Override(10f);
            color.saturation.Override(6f);
            foreach (var c in profile.components) AssetDatabase.AddObjectToAsset(c, profile);
            EditorUtility.SetDirty(profile);
            AssetDatabase.SaveAssets();
            return profile;
        }

        // ---- scene ---------------------------------------------------------------------------------

        static void BuildScene(PanelSettings panelSettings, VolumeProfile profile)
        {
            var scene = EditorSceneManager.NewScene(NewSceneSetup.EmptyScene, NewSceneMode.Single);
            var skyboxes = Enumerable.Range(0, GoF2SkyboxBaker.SkyboxCount)
                .Select(i => AssetDatabase.LoadAssetAtPath<Material>(GoF2SkyboxBaker.MaterialPath(i))).ToArray();

            // Lighting: the skybox is the ambient + reflection source.
            RenderSettings.skybox = skyboxes[Stations[0].skybox];
            RenderSettings.ambientMode = AmbientMode.Skybox;
            RenderSettings.ambientIntensity = 1f;
            RenderSettings.defaultReflectionMode = DefaultReflectionMode.Skybox;
            RenderSettings.fog = false;

            var sunGo = new GameObject("Sun");
            var sun = sunGo.AddComponent<Light>();
            sun.type = LightType.Directional;
            sun.intensity = 1.5f;
            sun.color = new Color(1f, 0.95f, 0.88f);
            sun.shadows = LightShadows.None;
            sunGo.transform.rotation = Quaternion.Euler(28f, -35f, 0f);

            // Camera (CutScene: FOV ~53 deg, far 200000 game units = 10 km; stations need more here).
            var camGo = new GameObject("Menu Camera") { tag = "MainCamera" };
            var cam = camGo.AddComponent<Camera>();
            cam.clearFlags = CameraClearFlags.Skybox;
            cam.fieldOfView = 50f;
            cam.nearClipPlane = 1f;
            cam.farClipPlane = 60000f;
            cam.allowHDR = true;
            var camData = cam.GetUniversalAdditionalCameraData();
            camData.renderPostProcessing = true;
            camData.antialiasing = AntialiasingMode.SubpixelMorphologicalAntiAliasing;
            camGo.AddComponent<AudioListener>();
            var menuCam = camGo.AddComponent<GoF2MenuCamera>();
            menuCam.orbitSpeed = 1.2f;
            menuCam.driftDegrees = 0.5f;
            menuCam.framingYaw = 14f;
            menuCam.verticalFov16x9 = 50f;

            // Station backdrop.
            var bgGo = new GameObject("Background");
            var bg = bgGo.AddComponent<GoF2MenuBackground>();
            bg.menuCamera = menuCam;
            bg.skyboxes = skyboxes;
            bg.setups = Stations.Select(s => new GoF2MenuBackground.Setup
            {
                label = s.station,
                station = AssetDatabase.LoadAssetAtPath<GameObject>($"{GoF2ImportSettings.Root}/Prefabs/Assembled/main/stations/{s.station}.prefab"),
                skybox = s.skybox,
                yaw = s.yaw
            }).Where(s => s.station != null).ToArray();

            BuildTraffic();
            bg.asteroidField = BuildAsteroids();

            var volGo = new GameObject("Post Processing");
            var volume = volGo.AddComponent<Volume>();
            volume.isGlobal = true;
            volume.sharedProfile = profile;

            // UI.
            var uiGo = new GameObject("Main Menu UI");
            var panel = uiGo.AddComponent<PanelRenderer>();   // Unity 6.7's successor to UIDocument
            panel.panelSettings = panelSettings;
            panel.visualTreeAsset = AssetDatabase.LoadAssetAtPath<VisualTreeAsset>($"{MenuDir}/MainMenu.uxml");
            EditorUtility.SetDirty(panel);
            var music = uiGo.AddComponent<AudioSource>();
            music.playOnAwake = false;
            music.loop = true;
            var sfx = uiGo.AddComponent<AudioSource>();
            sfx.playOnAwake = false;
            var menu = uiGo.AddComponent<GoF2MainMenu>();
            menu.musicSource = music;
            menu.sfxSource = sfx;
            menu.menuMusic = Clip("MUSIC/Space_NoCombat_Void.ogg");
            menu.buttonPush = Clip("SFX_GENERAL/Button_Push_v06.ogg");
            menu.buttonRelease = Clip("SFX_GENERAL/Button_Release_V06.ogg");
            menu.infoSound = Clip("SFX_GENERAL/Message_Info_Screen_v04.ogg");
            menu.editorSplashLogos = new[] { AssetDatabase.LoadAssetAtPath<Texture2D>($"{ImageDir}/logo_fishlabs.png") };
            menu.languageCodes = Languages.Select(l => l.code).ToArray();
            menu.languageNames = Languages.Select(l => l.name).ToArray();
            menu.languageTables = Languages.Select(l => AssetDatabase.LoadAssetAtPath<UnityEngine.TextAsset>($"{GoF2ImportSettings.Root}/Localization/text_{l.code}.json")).ToArray();
            menu.postVolume = volume;

            var es = new GameObject("EventSystem");
            es.AddComponent<EventSystem>();
            es.AddComponent<InputSystemUIInputModule>();

            EditorSceneManager.SaveScene(scene, ScenePath);
            AddToBuildSettings(ScenePath, 0);
            AddToBuildSettings("Assets/Scenes/FlightTest.unity", 1);
            Debug.Log($"GoF2: main menu scene created at {ScenePath}. Press Play.");
        }

        /// <summary>NPC traffic crossing the view (the original spawns ambient traffic via Level::createScene mode 2).</summary>
        static void BuildTraffic()
        {
            var parent = new GameObject("Traffic").transform;
            // (ship, start, heading yaw, speed m/s, length m, pause s, delay s)
            var lanes = new (string ship, Vector3 start, float yaw, float speed, float length, float pause, float delay)[]
            {
                ("ship_001_terran", new Vector3(-4200f, 350f, -900f), 80f, 95f, 8500f, 8f, 2f),
                ("ship_005_terran", new Vector3(-4150f, 330f, -960f), 80f, 95f, 8500f, 8f, 2.4f),
                ("ship_022_terran", new Vector3(3800f, -250f, 1800f), 250f, 110f, 8000f, 14f, 12f),
                ("cargo_002_nivelian", new Vector3(-5000f, -600f, 3500f), 95f, 45f, 10000f, 20f, 0f),
                ("ship_016_nivelian", new Vector3(2500f, 900f, -4000f), 330f, 120f, 9000f, 18f, 25f),
                ("battleship_terran", new Vector3(-9000f, 1800f, 9000f), 100f, 25f, 18000f, 40f, 5f),
            };
            foreach (var l in lanes)
            {
                var prefab = AssetDatabase.LoadAssetAtPath<GameObject>($"{GoF2ImportSettings.Root}/Prefabs/Assembled/main/ships/{l.ship}.prefab");
                if (prefab == null) continue;
                var go = (GameObject)PrefabUtility.InstantiatePrefab(prefab, parent);
                go.transform.SetPositionAndRotation(l.start, Quaternion.Euler(0f, l.yaw, 0f));
                go.GetComponent<GoF2AssembledObject>()?.SetPlayerVariant(false);   // NPC engines
                var fly = go.AddComponent<GoF2Flyby>();
                fly.speed = l.speed;
                fly.length = l.length;
                fly.pause = l.pause;
                fly.startDelay = l.delay;
            }
        }

        /// <summary>Asteroids (Level::createAsteroids); GoF2MenuBackground spreads them around the chosen station.</summary>
        static Transform BuildAsteroids()
        {
            var parent = new GameObject("Asteroids").transform;
            var prefab = AssetDatabase.LoadAssetAtPath<GameObject>($"{GoF2ImportSettings.Root}/Prefabs/Assembled/main/asteroids/asteroid_01.prefab");
            if (prefab == null) return parent;
            var rnd = new System.Random(7);
            float R(float a, float b) => a + (float)rnd.NextDouble() * (b - a);
            for (int i = 0; i < 18; i++)
            {
                var go = (GameObject)PrefabUtility.InstantiatePrefab(prefab, parent);
                float ang = R(0f, 360f) * Mathf.Deg2Rad, dist = R(3500f, 9000f);
                go.transform.position = new Vector3(Mathf.Cos(ang) * dist, R(-1500f, 1500f), Mathf.Sin(ang) * dist);
                go.transform.rotation = Quaternion.Euler(R(0, 360), R(0, 360), R(0, 360));
                go.transform.localScale = Vector3.one * R(3f, 12f);
                var spin = go.AddComponent<GoF2Spin>();
                spin.degreesPerSecond = new Vector3(R(-3, 3), R(-4, 4), R(-3, 3));
            }
            return parent;
        }

        static AudioClip Clip(string rel) => AssetDatabase.LoadAssetAtPath<AudioClip>($"{GoF2ImportSettings.Root}/Audio/{rel}");

        static void AddToBuildSettings(string path, int index)
        {
            if (!File.Exists(path)) return;
            var list = EditorBuildSettings.scenes.Where(s => s.path != path).ToList();
            list.Insert(Mathf.Min(index, list.Count), new EditorBuildSettingsScene(path, true));
            EditorBuildSettings.scenes = list.ToArray();
        }
    }
}
