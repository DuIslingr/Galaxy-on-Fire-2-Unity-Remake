// SplashMusic.cs
// Modified: the menu theme starts with the FISHLABS logo, as MTitle does (the original plays it from the first logo). In a
// player the logos are Unity's own splash screen (Player Settings), which shows before any scene, so the music starts
// here, before the splash (RuntimeInitializeLoadType.BeforeSplashScreen), from Resources/GoF2Music/MenuTheme (a
// SplashTheme that references event 145 Space_NoCombat_Void, so the clip ships once); MainMenu adopts the playing source
// as its music source (Take), so the theme carries on without a second stream. The Editor draws the logos in the menu
// itself and starts the music there, so nothing happens here in the Editor, nor on a dedicated server
// (DedicatedServer.Enabled, or -batchmode).

using GoF2Remake.Data;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace GoF2Remake.UI
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class SplashMusic
    {
        static AudioSource source;
        static AudioListener listener;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSplashScreen)]
        static void Begin()
        {
            source = null;
            listener = null;
            if (Application.isEditor || Application.isBatchMode) return;
            if (GoF2Remake.Multiplayer.DedicatedServer.Enabled) return;
            var theme = Resources.Load<SplashTheme>("GoF2Music/MenuTheme");
            var clip = theme != null ? theme.clip : null;
            if (clip == null) return;
            // Bootstrap applies the master volume before the first scene; the splash comes earlier still.
            AudioListener.volume = Settings.MasterVolume;
            var go = new GameObject("Splash music");
            Object.DontDestroyOnLoad(go);
            // No scene is loaded yet, so no camera's listener either: one of its own until the first scene brings one.
            listener = go.AddComponent<AudioListener>();
            source = go.AddComponent<AudioSource>();
            source.clip = clip;
            source.loop = true;
            source.spatialBlend = 0f;
            source.ignoreListenerPause = true;
            source.volume = Settings.MusicVolume;
            source.Play();
            SceneManager.sceneLoaded += DropListener;
        }

        /// <summary>The first scene's own listener takes over (two listeners log a warning every frame).</summary>
        static void DropListener(Scene scene, LoadSceneMode mode)
        {
            SceneManager.sceneLoaded -= DropListener;
            DropOwnListener();
        }

        static void DropOwnListener()
        {
            if (listener == null) return;
            foreach (var l in Object.FindObjectsByType<AudioListener>(FindObjectsInactive.Exclude))
                if (l != listener) { Object.Destroy(listener); listener = null; return; }
        }

        /// <summary>Modified: the splash's theme, still playing, handed over to 'scene' (moved out of DontDestroyOnLoad, so it
        /// goes with that scene), or null when it isn't playing (then it is gone either way).</summary>
        public static AudioSource Take(Scene scene)
        {
            var s = source;
            source = null;
            if (s == null) { listener = null; return null; }
            if (!s.isPlaying || s.clip == null)
            {
                Object.Destroy(s.gameObject);
                listener = null;
                return null;
            }
            DropOwnListener();
            listener = null;
            if (scene.IsValid()) SceneManager.MoveGameObjectToScene(s.gameObject, scene);
            return s;
        }
    }
}
