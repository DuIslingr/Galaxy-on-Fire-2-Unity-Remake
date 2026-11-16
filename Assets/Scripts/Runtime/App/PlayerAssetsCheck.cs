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
            Directory.CreateDirectory(c.folder);
            c.StartCoroutine(c.Run());
        }

        IEnumerator Run()
        {
            Line($"GoF2 player assets check {Application.version} {SystemInfo.graphicsDeviceType}; copy installed: {GameContent.Installed} ({GameContent.Root}); setup needed: {OriginalSetup.Needed}");
            yield return Wait(() => SceneManager.GetActiveScene().name == "MainMenu", 600f, "the main menu");   // (packs may install first)
            var keys = Enumerable.Range(0, 27).Select(k => k.ToString("000")).Where(World.RebuiltPlanets.Has).ToList();
            Line($"packs applied: {string.Join(", ", OriginalPacks.Applied(GameContent.Root).Keys)}; 3D planets: {keys.Count} ({string.Join(" ", keys)}); " +
                 $"HD sky stars_000: {(Visuals.OriginalSkies.Hd("stars_000") != null ? "yes" : "no")}, star list: {World.SkyStars.List("stars_000").Length}");
            yield return new WaitForSecondsRealtime(8f);
            int filled = UI.UiImageSlots.Fill();
            var button = Resources.FindObjectsOfTypeAll<Texture2D>().FirstOrDefault(t => t.name == "og_button");
            var still = Resources.FindObjectsOfTypeAll<Texture2D>().Where(t => t.width <= 4 && t.height <= 4 && UI.UiImageSlots.ImageOf(t.name) == null && (t.name.StartsWith("og_") || t.name.StartsWith("card_") || t.name.Contains("crosshair"))).Select(t => t.name).ToList();
            var title = Resources.FindObjectsOfTypeAll<Texture2D>().FirstOrDefault(t => t.name == "logo_gof2_remake");
            Line($"stylesheet images (UiImageSlots): {filled} placeholders filled now; og_button {(button != null ? button.width + "x" + button.height : "not loaded")}; " +
                 $"title logo {(title != null ? title.width + "x" + title.height : "not loaded")}; still placeholders without a source: {still.Count} {string.Join(" ", still.Take(8))}");
            Shot("menu");
            yield return PanelShot("menu_ui");
            Settings.OriginalUi = true;   // (the Original interface style: its pieces are UiImageSlots' placeholders)
            yield return new WaitForSecondsRealtime(2f);
            yield return PanelShot("menu_ui_original");
            Settings.OriginalUi = false;
            foreach (int station in new[] { 0, 27, 101 })
            {
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
            }
            Session.ResetNewGame();
            Session.FreePlay = true;
            Session.CampaignMission = 20;
            Session.StationIndex = 0;
            SceneManager.LoadScene("Station");
            yield return Wait(() => SceneManager.GetActiveScene().name == "Station", 60f, "the station");
            yield return new WaitForSecondsRealtime(6f);
            Shot("station");
            Line(bad == 0 ? "OK" : $"FAILED: {bad} problem(s)");
            File.WriteAllText(Path.Combine(folder, "report.txt"), report.ToString());
            Application.Quit(bad == 0 ? 0 : 1);
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

        void Line(string s)
        {
            report.AppendLine(s);
            Debug.Log("PlayerAssetsCheck: " + s);
        }
    }
}
