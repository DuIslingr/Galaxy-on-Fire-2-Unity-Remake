// SplashMusic.cs
// Modified: the menu theme starts with the FISHLABS logo, as MTitle does (the original plays it from the first logo). In a
// player the logos are Unity's own splash screen (Player Settings), which shows before any scene, so the music starts
// here, before the splash (RuntimeInitializeLoadType.BeforeSplashScreen), from a copy of the theme in Resources
// (GoF2Music/MenuTheme: event 145 Space_NoCombat_Void); MainMenu takes it over at the same point of the track (Take).
// The Editor draws the logos in the menu itself and starts the music there, so nothing happens here in the Editor, nor
// on a dedicated server (-batchmode / -server).

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
            if (System.Array.IndexOf(System.Environment.GetCommandLineArgs(), "-server") >= 0) return;
            var clip = Resources.Load<AudioClip>("GoF2Music/MenuTheme");
            if (clip == null) return;
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
            if (listener == null) return;
            foreach (var l in Object.FindObjectsByType<AudioListener>(FindObjectsInactive.Exclude))
                if (l != listener) { Object.Destroy(listener); listener = null; return; }
        }

        /// <summary>Where the splash's theme is (seconds), or -1 when it isn't playing; the splash's source goes either way.</summary>
        public static float Take()
        {
            if (source == null) return -1f;
            float at = source.isPlaying ? source.time : -1f;
            Object.Destroy(source.gameObject);
            source = null;
            listener = null;
            return at;
        }
    }
}
