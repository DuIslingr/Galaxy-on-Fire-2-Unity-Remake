// AndroidVibratePermission.cs
// The phone's vibration (PhoneVibrator, over JNI) needs android.permission.VIBRATE (a normal permission: granted at install,
// no prompt). Unity only adds it on its own when a script calls Handheld.Vibrate, so the generated Gradle project's
// unityLibrary manifest gets it here.

using System.IO;
using UnityEditor.Android;
using UnityEngine;

namespace GoF2Remake.EditorTools
{
    public class AndroidVibratePermission : IPostGenerateGradleAndroidProject
    {
        const string Permission = "android.permission.VIBRATE";

        public int callbackOrder => 0;

        public void OnPostGenerateGradleAndroidProject(string path)
        {
            // 'path' is the unityLibrary module.
            string manifest = Path.Combine(path, "src", "main", "AndroidManifest.xml");
            if (!File.Exists(manifest))
            {
                Debug.LogWarning("AndroidVibratePermission: no manifest at " + manifest + ", phone vibration won't work");
                return;
            }
            string text = File.ReadAllText(manifest);
            if (text.Contains("\"" + Permission + "\"")) return;
            int start = text.IndexOf("<manifest", System.StringComparison.Ordinal);
            int end = start >= 0 ? text.IndexOf('>', start) : -1;
            if (end < 0)
            {
                Debug.LogWarning("AndroidVibratePermission: unexpected manifest, phone vibration won't work");
                return;
            }
            text = text.Insert(end + 1, "\n  <uses-permission android:name=\"" + Permission + "\" />");
            File.WriteAllText(manifest, text);
        }
    }
}
