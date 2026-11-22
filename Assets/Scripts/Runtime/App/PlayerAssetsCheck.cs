// PlayerAssetsCheck.cs
// Feature: docs/notes/player-assets.md "Builds without the originals": a development build's self-check of the content
// layer in a real player, without a window: run it as
//   gamescope --backend headless -- GoF2Remake.x86_64 -gof2check <folder>   ($GOF2_ORIGINAL_CACHE naming a converted copy)
// It waits for the main menu, then flies a free-play game from a few stations (their orbits) and docks one (the hangar),
// renders the main camera of each into <folder>/<name>.png (and the menu's UI panel in both interface styles), counts the renderers whose material lost its shader (Unity's
// error shader: a shader or variant the build stripped) and writes <folder>/report.txt, then quits (exit code 1 when a
// scene had such renderers or didn't load). Development builds and the Editor only (Debug.isDebugBuild: Unity 7 defines no
// DEVELOPMENT_BUILD for scripts); nothing without the argument. A desktop session would show the player's window: run it
// in a headless compositor (gamescope --backend headless -- ./GoF2Remake.x86_64 -gof2check <folder>).
// -gof2fps <seconds> adds a frame-rate sample of each view (uncapped, no vsync; its average, median and 1 % low fps) at the
// window's size (-screen-width / -screen-height / -screen-fullscreen 1 with gamescope's -W / -H).
// -gof2fsr <quality> renders with the Upscaler option's FSR (0 native AA .. 4 ultra performance) for the run (the options
// put back at the end), and reports the FSR plugin's state (LinuxFsr on Linux) ($GOF2_FSR_VERSION=3 / 2: that FSR where FSR 4 also
// runs, UpscalerFramework.BestFsr). -gof2scale <s> renders at that render scale with the upscaler off (plain bilinear: FSR's
// cost is the GPU frame time with FSR minus this one at its render resolution). -gof2fsrlite <n>: FSR 4 Lite (the option "FSR 4
// Lite") for the run with 1; with 2 the option changed while playing: in the hangar, the last view, it goes on and off again,
// a picture and a frame-rate sample each time. The fps samples include the GPU frame
// time (FrameTimingManager: development builds made by PlayerAssetsBuild have frame timing stats on); -gof2cap <fps> caps
// them (e.g. to compare GPU timings with another program at its frame rate: the GPU's clock follows its load).
// -gof2stations <s,s,...> flies these stations' orbits instead of 0, 27 and 101, -gof2dock <s> docks that one instead of 0:
// each a station number or a mod's station key ("mod_id:id", ModWorld.StationIndexOf), e.g. a mod's stations and its own
// hangar (-gof2stations gof3_ships:manticore -gof2dock gof3_ships:manticore). Each view also reports its glowing materials
// (_EMISSION and a colour) by emission flag and shader.
// -gof2map <system,system,...> (mod system keys or numbers) opens the star map in the first orbit and shows each system's
// view straight away (StarMap.ShowSystemNow), screen-captured with its overlay into map_<n>.png: the mods' map scenes
// (systems.json "mapScene", 2026-11-22).

using System;
using System.Collections;
using System.IO;
using System.Linq;
using System.Text;
using GoF2Remake.Data;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace GoF2Remake
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public class PlayerAssetsCheck : MonoBehaviour
    {
        string folder;
        readonly StringBuilder report = new StringBuilder();
        int bad;
        float fpsSeconds;
        int fsrQuality = -1;
        int fsrLite;   // -gof2fsrlite: 1 FSR 4 Lite for the run, 2 switched in the hangar
        float renderScale;
        int fpsCap;   // -gof2cap: the fps samples' frame cap (0: uncapped)
        string[] stations = { "0", "27", "101" };   // -gof2stations
        string dock = "0";   // -gof2dock
        string[] mapSystems = new string[0];   // -gof2map

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
        static void Begin()
        {
            var args = Environment.GetCommandLineArgs();
            int i = Array.IndexOf(args, "-gof2check");
            if (i < 0 || i + 1 >= args.Length || !(Debug.isDebugBuild || Application.isEditor)) return;
            var go = new GameObject("Player assets check");
            DontDestroyOnLoad(go);
            var c = go.AddComponent<PlayerAssetsCheck>();
            c.folder = Path.GetFullPath(args[i + 1]);
            int f = Array.IndexOf(args, "-gof2fps");
            if (f >= 0 && f + 1 < args.Length) float.TryParse(args[f + 1], System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out c.fpsSeconds);
            int q = Array.IndexOf(args, "-gof2fsr");
            if (q >= 0 && q + 1 < args.Length && int.TryParse(args[q + 1], out int quality)) c.fsrQuality = Mathf.Clamp(quality, 0, 4);
            int lite = Array.IndexOf(args, "-gof2fsrlite");
            if (lite >= 0 && lite + 1 < args.Length) int.TryParse(args[lite + 1], out c.fsrLite);
            int cap = Array.IndexOf(args, "-gof2cap");
            if (cap >= 0 && cap + 1 < args.Length) int.TryParse(args[cap + 1], out c.fpsCap);
            int rs = Array.IndexOf(args, "-gof2scale");
            if (rs >= 0 && rs + 1 < args.Length) float.TryParse(args[rs + 1], System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out c.renderScale);
            int st = Array.IndexOf(args, "-gof2stations");
            if (st >= 0 && st + 1 < args.Length) c.stations = args[st + 1].Split(new[] { ',' }, StringSplitOptions.RemoveEmptyEntries).Select(s => s.Trim()).ToArray();
            int dk = Array.IndexOf(args, "-gof2dock");
            if (dk >= 0 && dk + 1 < args.Length) c.dock = args[dk + 1];
            int mp = Array.IndexOf(args, "-gof2map");
            if (mp >= 0 && mp + 1 < args.Length) c.mapSystems = args[mp + 1].Split(new[] { ',' }, StringSplitOptions.RemoveEmptyEntries).Select(s => s.Trim()).ToArray();
            Directory.CreateDirectory(c.folder);
            c.StartCoroutine(c.Run());
        }

        IEnumerator Run()
        {
            Line($"GoF2 player assets check {Application.version} {SystemInfo.graphicsDeviceType}; copy installed: {GameContent.Installed} ({GameContent.Root}); setup needed: {OriginalSetup.Needed}");
            // (packs may install first; the HD question, once: shot, then "Not now" without keeping the answer)
            int asked = PlayerPrefs.GetInt(OriginalSetup.HdAskedPref, 0);
            float until = Time.realtimeSinceStartup + 600f;
            while (SceneManager.GetActiveScene().name != "MainMenu" && Time.realtimeSinceStartup < until)
            {
                var setup = UI.OriginalSetupView.Current;
                if (setup != null && setup.AskingHd)
                {
                    yield return new WaitForSecondsRealtime(1f);
                    yield return PanelShot("hd_question");
                    setup.NotNow();
                    PlayerPrefs.SetInt(OriginalSetup.HdAskedPref, asked);
                    Line("HD question shown on the splash (answered \"Not now\" for the check)");
                }
                yield return null;
            }
            yield return Wait(() => SceneManager.GetActiveScene().name == "MainMenu", 1f, "the main menu");
            // The mods that are on: everything they load (the loading screen's work: models, hangar shadows, ship icons).
            float modsStart = Time.realtimeSinceStartup;
            yield return Wait(() => !Modding.ModLoading.Busy, 900f, "the mods to load");
            var built = Modding.ModShips.Built.ToList();
            if (built.Count > 0)
                Line($"mods loaded in {Time.realtimeSinceStartup - modsStart:0} s: {built.Count} mod ship(s); icons drawn from the model " +
                     $"{Modding.ModShipIcons.Count} ({Modding.ModShipIcons.Drawn} drawn now, the rest cached); still without an icon " +
                     $"{built.Count(b => Modding.ModShips.Icon(b.ship) == null)}");
            var keys = Enumerable.Range(0, 27).Select(k => k.ToString("000")).Where(World.RebuiltPlanets.Has).ToList();
            Line($"HD resources: {(GameContent.HdInstalled ? "own folder " + GameContent.HdRoot + (GameContent.HdActive ? ", on" : ", off") : OriginalPacks.HdInCopy(GameContent.Root) ? "in the copy" : "none")}");
            Line($"packs applied: {string.Join(", ", OriginalPacks.Applied(GameContent.Root).Keys)}; 3D planets: {keys.Count} ({string.Join(" ", keys)}); " +
                 $"HD sky stars_000: {(Visuals.OriginalSkies.Hd("stars_000") != null ? "yes" : "no")}, star list: {World.SkyStars.List("stars_000").Length}");
            int upscalerWas = Settings.Upscaler, upscalerQualityWas = Settings.UpscalerQuality;
            float renderScaleWas = Settings.RenderScale;
            bool fsrLiteWas = Settings.Fsr4Lite;
            if (renderScale > 0f)
            {
                Settings.Upscaler = Settings.UpscalerOff;
                Settings.RenderScale = renderScale;
                yield return null;
            }
            if (fsrQuality >= 0)
            {
                Settings.UpscalerQuality = fsrQuality;
                Settings.Fsr4Lite = fsrLite == 1;
                Settings.Upscaler = Settings.UpscalerFsrTemporal;
                yield return null;
            }
#if (UNITY_STANDALONE_LINUX || UNITY_STANDALONE_WIN) && ENABLE_UPSCALER_FRAMEWORK
            Line($"FSR (Linux): {LinuxFsr.Status}; best {UpscalerFramework.BestFsrLabel ?? "none"}, active upscaler {UpscalerFramework.ActiveId}" +
                 $"; FSR 4 Lite {(UpscalerFramework.Fsr4LiteAvailable ? Settings.Fsr4Lite ? "on" : "available" : "not available")}");
#endif
            yield return new WaitForSecondsRealtime(8f);
            int filled = UI.UiImageSlots.Fill();
            var button = Resources.FindObjectsOfTypeAll<Texture2D>().FirstOrDefault(t => t.name == "og_button");
            var still = Resources.FindObjectsOfTypeAll<Texture2D>().Where(t => t.width <= 4 && t.height <= 4 && UI.UiImageSlots.ImageOf(t.name) == null && (t.name.StartsWith("og_") || t.name.StartsWith("card_") || t.name.Contains("crosshair"))).Select(t => t.name).ToList();
            var title = Resources.FindObjectsOfTypeAll<Texture2D>().FirstOrDefault(t => t.name == "logo_gof2_remake");
            Line($"stylesheet images (UiImageSlots): {filled} placeholders filled now; og_button {(button != null ? button.width + "x" + button.height : "not loaded")}; " +
                 $"title logo {(title != null ? title.width + "x" + title.height : "not loaded")}; still placeholders without a source: {still.Count} {string.Join(" ", still.Take(8))}");
            Shot("menu");
            Line("  content: " + ContentTimings.Report(reset: true));
            yield return Fps("menu");
            yield return PanelShot("menu_ui");
            Settings.OriginalUi = true;   // (the Original interface style: its pieces are UiImageSlots' placeholders)
            yield return new WaitForSecondsRealtime(2f);
            yield return PanelShot("menu_ui_original");
            Settings.OriginalUi = false;
            // the HD window over the menu (Options > Graphics "HD resources…")
            var menuRoot = FindAnyObjectByType<UI.MainMenu>()?.Root;
            if (menuRoot != null && UI.HdWindow.Show(menuRoot))
            {
                yield return new WaitForSecondsRealtime(1f);
                yield return PanelShot("menu_hd_window");
                UI.OriginalSetupView.Current?.Close();
                yield return new WaitForSecondsRealtime(0.5f);
                Line($"HD window over the menu: {(UI.HdWindow.Open ? "still open" : "opened and closed")}");
                PlayerPrefs.SetInt(OriginalSetup.HdAskedPref, asked);
            }
            else Line("HD window over the menu: couldn't open");
            foreach (string name in stations)
            {
                int station = StationOf(name);
                if (station < 0) continue;
                Session.ResetNewGame();
                Session.FreePlay = true;
                Session.CampaignMission = 20;
                Session.StationIndex = station;
                Session.Credits = 100000;
                Session.LaunchedFromStation = true;
                SceneManager.LoadScene("Space");
                yield return Wait(() => SceneManager.GetActiveScene().name == "Space", 60f, "the orbit");
                yield return new WaitForSecondsRealtime(6f);
                Shot($"orbit_{station:000}");
                Line("  content: " + ContentTimings.Report(reset: true));
                Glow($"orbit_{station:000}");
                StationShots($"orbit_{station:000}");
                yield return Fps($"orbit_{station:000}");
                if (mapSystems.Length > 0) { yield return MapShots(); mapSystems = new string[0]; }
            }
            Session.ResetNewGame();
            Session.FreePlay = true;
            Session.CampaignMission = 20;
            Session.StationIndex = Mathf.Max(0, StationOf(dock));
            SceneManager.LoadScene("Station");
            yield return Wait(() => SceneManager.GetActiveScene().name == "Station", 60f, "the station");
            yield return new WaitForSecondsRealtime(6f);
            Shot("station");
            Line("  content: " + ContentTimings.Report(reset: true));
            Glow("station");
            yield return Fps("station");
            if (fsrQuality >= 0 && fsrLite == 2)
                foreach (bool on in new[] { true, false })
                {
                    Settings.Fsr4Lite = on;
                    yield return new WaitForSecondsRealtime(3f);
                    Shot(on ? "station_lite" : "station_full_again");
                    Line($"FSR 4 Lite switched {(on ? "on" : "off")} in the hangar (available: {UpscalerFramework.Fsr4LiteAvailable})");
                    yield return Fps(on ? "station_lite" : "station_full_again");
                }
            if (fsrQuality >= 0 || renderScale > 0f)
            {
                Settings.Fsr4Lite = fsrLiteWas;
                Settings.Upscaler = upscalerWas;
                Settings.UpscalerQuality = upscalerQualityWas;
                Settings.RenderScale = renderScaleWas;
            }
            Line(bad == 0 ? "OK" : $"FAILED: {bad} problem(s)");
            File.WriteAllText(Path.Combine(folder, "report.txt"), report.ToString());
            Application.Quit(bad == 0 ? 0 : 1);
        }

        /// <summary>-gof2map: the star map's view of each system, with its overlay (the screen as presented).</summary>
        IEnumerator MapShots()
        {
            var map = UI.StarMap.Open(Database.Load(), UI.StarMapMode.Station, true, _ => { });
            if (map == null) { bad++; Line("FAILED: the star map didn't open"); yield break; }
            yield return Wait(() => map != null && map.WorldReady, 30f, "the star map");
            yield return new WaitForSecondsRealtime(1f);
            // the galaxy view round the first of them, and the full map (the mods' map scene nebulae, their markers)
            int first = int.TryParse(mapSystems[0], out int f0) ? f0 : Modding.ModWorld.SystemIndexOf(mapSystems[0]);
            foreach (bool full in new[] { false, true })
            {
                if (!map.ShowGalaxyNow(first, full)) continue;
                yield return new WaitForSecondsRealtime(1.5f);
                yield return new WaitForEndOfFrame();
                var g = ScreenCapture.CaptureScreenshotAsTexture();
                string gname = full ? "map_full" : "map_galaxy";
                File.WriteAllBytes(Path.Combine(folder, gname + ".png"), g.EncodeToPNG());
                Destroy(g);
                Line($"{gname}: {map.MapGalaxyReport()}");
            }
            foreach (string key in mapSystems)
            {
                int system = int.TryParse(key, out int n) ? n : Modding.ModWorld.SystemIndexOf(key);
                if (system < 0 || !map.ShowSystemNow(system)) { bad++; Line($"FAILED: no system {key} on the map"); continue; }
                yield return new WaitForSecondsRealtime(1.5f);
                yield return new WaitForEndOfFrame();
                var tex = ScreenCapture.CaptureScreenshotAsTexture();
                string name = $"map_{system:000}";
                File.WriteAllBytes(Path.Combine(folder, name + ".png"), tex.EncodeToPNG());
                Destroy(tex);
                string mapReport = map.MapSceneReport();
                if (!mapReport.Contains("(0 with a lost shader)") && mapReport != "no map scene") bad++;
                Line($"{name} ({key}): {mapReport}");
            }
            map.CloseForCheck();
            yield return new WaitForSecondsRealtime(0.5f);
        }

        /// <summary>A station by number or by a mod's key ("mod_id:id"); -1 (and a problem) when it isn't there.</summary>
        int StationOf(string name)
        {
            int i = int.TryParse(name, out int n) ? n : Modding.ModWorld.StationIndexOf(name);
            if (i < 0) { Line($"FAILED: no station {name} (its mod off?)"); bad++; }
            else Line($"station {name}: {i}");
            return i;
        }

        /// <summary>How many renderers' materials ask for emission (_EMISSION on, a colour above the templates' 1/255) and with
        /// which emission flags: the mods' baked lighting lives there (2026-11-21). Whether the build kept the variant shows
        /// only in the picture (a stripped variant falls back to one without the keyword, which no API reports).</summary>
        void Glow(string scene)
        {
            var mats = FindObjectsByType<Renderer>(FindObjectsInactive.Exclude).SelectMany(r => r.sharedMaterials)
                .Where(m => m != null && m.IsKeywordEnabled("_EMISSION") && m.HasProperty("_EmissionColor")
                            && m.GetColor("_EmissionColor").maxColorComponent > 1f / 255f + 1e-4f).ToList();
            Line($"  emission in {scene}: {mats.Count} glowing material slots; flags " +
                 string.Join(", ", mats.GroupBy(m => m.globalIlluminationFlags).Select(g => $"{g.Key} {g.Count()}")) + "; shaders " +
                 string.Join(", ", mats.GroupBy(m => m.shader.name).Select(g => $"{g.Key} {g.Count()}")));
        }

        /// <summary>The main menu's UI panel (UI Toolkit draws over the cameras: not in Shot) rendered into a png.</summary>
        IEnumerator PanelShot(string name)
        {
            var pr = FindObjectsByType<UnityEngine.UIElements.PanelRenderer>(FindObjectsInactive.Exclude).FirstOrDefault(p => p.GetComponent<UI.MainMenu>() != null)
                     ?? FindAnyObjectByType<UnityEngine.UIElements.PanelRenderer>();
            if (pr == null || pr.panelSettings == null) { Line($"{name}: no panel"); yield break; }
            var rt = new RenderTexture(1600, 900, 24, RenderTextureFormat.ARGB32);
            var settings = pr.panelSettings;
            var before = settings.targetTexture;
            settings.targetTexture = rt;
            for (int i = 0; i < 6; i++) yield return null;
            var was = RenderTexture.active;
            RenderTexture.active = rt;
            var t = new Texture2D(1600, 900, TextureFormat.RGBA32, false);
            t.ReadPixels(new Rect(0, 0, 1600, 900), 0, 0);
            t.Apply();
            RenderTexture.active = was;
            settings.targetTexture = before;
            File.WriteAllBytes(Path.Combine(folder, name + ".png"), t.EncodeToPNG());
            Destroy(t); rt.Release(); Destroy(rt);
        }

        /// <summary>-gof2fps: the frame rate over fpsSeconds of the view as it is (after a second to settle), uncapped.</summary>
        IEnumerator Fps(string name)
        {
            if (fpsSeconds <= 0f) yield break;
            QualitySettings.vSyncCount = 0;
            Application.targetFrameRate = fpsCap > 0 ? fpsCap : -1;
            yield return new WaitForSecondsRealtime(1f);
#if (UNITY_STANDALONE_LINUX || UNITY_STANDALONE_WIN) && ENABLE_UPSCALER_FRAMEWORK
            LinuxFsr.TimingReport(reset: true);
#endif
            var ms = new System.Collections.Generic.List<double>(4096);
            var gpu = new System.Collections.Generic.List<double>(4096);
            var timing = new FrameTiming[1];
            double start = Time.realtimeSinceStartupAsDouble, last = start;
            while (last - start < fpsSeconds)
            {
                FrameTimingManager.CaptureFrameTimings();
                yield return null;
                double now = Time.realtimeSinceStartupAsDouble;
                ms.Add((now - last) * 1000.0);
                last = now;
                if (FrameTimingManager.GetLatestTimings(1, timing) == 1 && timing[0].gpuFrameTime > 0) gpu.Add(timing[0].gpuFrameTime);
            }
            gpu.Sort();
            string gpuText = gpu.Count > 0 ? $", GPU frame {gpu[gpu.Count / 2]:0.000} ms median ({gpu.Count} timed)" : ", no GPU frame times";
            ms.Sort();
            double median = ms[ms.Count / 2], p99 = ms[Math.Min(ms.Count - 1, (int)(ms.Count * 0.99))];
            Line($"  fps {name}: {Screen.width}x{Screen.height}, {ms.Count / (last - start):0} average, {1000.0 / median:0} median, " +
                 $"{1000.0 / p99:0} 1% low ({ms.Count} frames, worst {ms[ms.Count - 1]:0.0} ms){gpuText}; {SystemInfo.graphicsDeviceType}, " +
                 $"quality {QualitySettings.names[QualitySettings.GetQualityLevel()]}, upscaler {(UpscalerFramework.ActiveId is { Length: > 0 } id ? id : "none")}");
#if (UNITY_STANDALONE_LINUX || UNITY_STANDALONE_WIN) && ENABLE_UPSCALER_FRAMEWORK
            string fsr = LinuxFsr.TimingReport(reset: true);
            if (fsr.Length > 0) Line("    " + fsr);
#endif
#if ENABLE_AMD && ENABLE_AMD_MODULE
            string amd = AmdFsrReport();
            if (amd.Length > 0) Line("    " + amd);
#endif
            Bootstrap.ApplyFrameRate();
        }

#if ENABLE_AMD && ENABLE_AMD_MODULE
        /// <summary>Unity's AMD module (Windows): the FSR versions it offers and its live FSR contexts (version, quality mode,
        /// render size), to know which FSR a run measured.</summary>
        static string AmdFsrReport()
        {
            var device = UnityEngine.AMD.GraphicsDevice.device;
            if (device == null) return "";
            var sb = new StringBuilder("AMD module:");
            foreach (var f in new[] { UnityEngine.AMD.GraphicsDeviceFeature.FSRUpscale4, UnityEngine.AMD.GraphicsDeviceFeature.FSRUpscale3, UnityEngine.AMD.GraphicsDeviceFeature.FSRUpscale2 })
                if (UnityEngine.AMD.GraphicsDevice.GetFeatureVersion(f, out uint ma, out uint mi, out uint pa)) sb.Append($" {f} {ma}.{mi}.{pa}");
            var view = device.CreateDebugView();
            device.UpdateDebugView(view);
            var infos = view.upscaleFeatureInfoSpan;
            for (int i = 0; i < infos.Length; i++)
            {
                var x = infos[i];
                if (x.validFeature) sb.Append($"; context {x.majorVersion}.{x.minorVersion}.{x.patchVersion} {x.qualityMode} {x.renderWidth}x{x.renderHeight}");
            }
            device.DeleteDebugView(view);
            return sb.ToString();
        }
#endif

        IEnumerator Wait(Func<bool> done, float seconds, string what)
        {
            float end = Time.realtimeSinceStartup + seconds;
            while (!done() && Time.realtimeSinceStartup < end) yield return null;
            if (!done()) { bad++; Line($"timed out waiting for {what}"); }
        }

        /// <summary>The main camera's view as a png, and the renderers drawn with Unity's error shader.</summary>
        void Shot(string name)
        {
            var renderers = FindObjectsByType<Renderer>(FindObjectsInactive.Exclude);
            var broken = renderers.Where(r => r.sharedMaterials.Any(m => m != null && (m.shader == null || m.shader.name == "Hidden/InternalErrorShader" || !m.shader.isSupported)))
                                  .Select(r => r.name).Distinct().ToList();
            int empty = renderers.Count(r => r is MeshRenderer && r.sharedMaterials.All(m => m == null));
            var cam = Camera.main;
            if (cam != null)
            {
                var rt = new RenderTexture(1600, 900, 24, RenderTextureFormat.ARGB32);
                var prev = cam.targetTexture;
                cam.targetTexture = rt;
                cam.Render();
                cam.targetTexture = prev;
                var was = RenderTexture.active;
                RenderTexture.active = rt;
                var t = new Texture2D(1600, 900, TextureFormat.RGB24, false);
                t.ReadPixels(new Rect(0, 0, 1600, 900), 0, 0);
                t.Apply();
                RenderTexture.active = was;
                File.WriteAllBytes(Path.Combine(folder, name + ".png"), t.EncodeToPNG());
                Destroy(t);
                rt.Release();
                Destroy(rt);
            }
            if (broken.Count > 0) bad++;
            var cross = Resources.FindObjectsOfTypeAll<Texture2D>().FirstOrDefault(t => t.name == "crosshair");
            Line($"{name}: scene {SceneManager.GetActiveScene().name}, {renderers.Length} renderers, {broken.Count} with a lost shader" +
                 (broken.Count > 0 ? " (" + string.Join(", ", broken.Take(12)) + ")" : "") + $", {empty} without a material, camera {(cam != null ? "yes" : "none")}" + (cross != null ? $", crosshair {cross.width}x{cross.height}" : ""));
        }

        /// <summary>The orbit's station and its mobile stations, each framed whole by the main camera from the side it looks
        /// from (<name>_station.png, <name>_mobile_<n>.png): the flight view seldom shows them (2026-11-21, the GoF3 stations'
        /// baked lights in their emission). The camera is put back.</summary>
        void StationShots(string name)
        {
            var cam = Camera.main;
            if (cam == null) return;
            var targets = new System.Collections.Generic.List<(string, GameObject)>();
            var level = FindAnyObjectByType<World.SpaceLevel>();
            if (level != null && level.Station != null) targets.Add(($"{name}_station", level.Station));
            int n = 0;
            foreach (var m in FindObjectsByType<World.MobileStation>(FindObjectsInactive.Exclude)) targets.Add(($"{name}_mobile_{n++}", m.gameObject));
            var t = cam.transform;
            Vector3 pos = t.position; Quaternion rot = t.rotation; float far = cam.farClipPlane, near = cam.nearClipPlane;
            foreach (var (shot, go) in targets)
            {
                var rs = go.GetComponentsInChildren<Renderer>(false).Where(r => r.enabled && !(r is ParticleSystemRenderer)).ToList();
                if (rs.Count == 0) { Line($"{shot}: no renderers"); continue; }
                var b = rs[0].bounds;
                foreach (var r in rs) b.Encapsulate(r.bounds);
                var dir = pos - b.center;
                if (dir.sqrMagnitude < 1f) dir = new Vector3(0.4f, 0.35f, -1f);
                float dist = b.extents.magnitude / Mathf.Tan(cam.fieldOfView * 0.5f * Mathf.Deg2Rad) * 1.05f;
                t.position = b.center + dir.normalized * dist;
                t.LookAt(b.center);
                cam.farClipPlane = Mathf.Max(far, dist + b.extents.magnitude * 2f);
                cam.nearClipPlane = Mathf.Max(near, dist * 0.001f);
                Shot(shot);
            }
            t.SetPositionAndRotation(pos, rot); cam.farClipPlane = far; cam.nearClipPlane = near;
        }

        void Line(string s)
        {
            report.AppendLine(s);
            Debug.Log("PlayerAssetsCheck: " + s);
        }
    }
}
