// EventGraphUpgrade.cs
// The event graphs began as multiplayer events: their files were .gof2netevent and their option enums lived in
// GoF2Remake.Multiplayer (Graph Toolkit stores an enum option by its type's name, m_EnumType.m_Identification). Any such
// file imported into the project (an old graph, one copied in from a server's Events folder or a mod) is renamed to
// .gof2event (AssetDatabase.MoveAsset: the same GUID, so references stay) with the enum types' new namespace,
// GoF2Remake.Events, so Graph Toolkit opens it. The game itself reads both extensions (EventRunner.LegacyExtension) and
// never looks at those type names.

using System.IO;
using GoF2Remake.Events;
using UnityEditor;
using UnityEngine;

namespace GoF2Remake.EditorTools
{
    public class EventGraphUpgrade : AssetPostprocessor
    {
        static void OnPostprocessAllAssets(string[] imported, string[] deleted, string[] moved, string[] movedFrom)
        {
            foreach (string path in imported)
                if (path.EndsWith("." + EventRunner.LegacyExtension, System.StringComparison.OrdinalIgnoreCase))
                {
                    string p = path;
                    EditorApplication.delayCall += () => Upgrade(p);
                }
        }

        static void Upgrade(string path)
        {
            if (!File.Exists(path)) return;
            string text = File.ReadAllText(path);
            string target = AssetDatabase.GenerateUniqueAssetPath(Path.ChangeExtension(path, "." + EventGraph.Extension).Replace('\\', '/'));
            string error = AssetDatabase.MoveAsset(path, target);
            if (!string.IsNullOrEmpty(error)) { Debug.LogWarning($"GoF2: couldn't rename {path} to {target}: {error}"); return; }
            File.WriteAllText(target, text.Replace("GoF2Remake.Multiplayer.Event", "GoF2Remake.Events.Event"));
            AssetDatabase.ImportAsset(target);
            Debug.Log($"GoF2: event graph {path} renamed to {target} (the .gof2event format)");
        }
    }
}
