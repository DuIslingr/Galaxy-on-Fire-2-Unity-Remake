// BuildFingerprint.cs
// What decides whether two builds can play together (NetGame's connection approval, the server browser): a hash of what
// the multiplayer depends on, the same for every build of the same code whenever and on whatever platform it was built:
// the runtime scripts (Assets/Scripts/Runtime), the network prefabs (Resources/GoF2Net), the game data
// (Resources/GoF2Data) and the package list (Packages/manifest.json). Paths sorted, line endings normalised (a checkout with
// CRLF and one with LF hash the same), SHA-256, the first 12 hex digits. BuildVersionStamp writes it into
// Resources/GoF2Build/BuildFingerprint.txt for the build (git-ignored, deleted afterwards); the game reads it through
// BuildVersion.Fingerprint. The build's date and time stays its shown version.

using System;
using System.Collections.Generic;
using System.IO;
using System.Security.Cryptography;
using System.Text;

namespace GoF2Remake.EditorTools
{
    public static class BuildFingerprint
    {
        public const string Folder = "Assets/Resources/GoF2Build";
        public const string FilePath = Folder + "/BuildFingerprint.txt";

        static readonly (string folder, string pattern)[] Inputs =
        {
            ("Assets/Scripts/Runtime", "*.cs"),
            ("Assets/Resources/GoF2Net", "*.prefab"),
            ("Assets/Resources/GoF2Data", "*.json"),
        };

        public static string Compute()
        {
            var files = new List<string>();
            foreach (var (folder, pattern) in Inputs)
                if (Directory.Exists(folder))
                    foreach (var f in Directory.GetFiles(folder, pattern, SearchOption.AllDirectories)) files.Add(f.Replace('\\', '/'));
            if (File.Exists("Packages/manifest.json")) files.Add("Packages/manifest.json");
            files.Sort(StringComparer.Ordinal);
            using (var sha = SHA256.Create())
            {
                foreach (var f in files)
                {
                    string text = File.ReadAllText(f).Replace("\r\n", "\n").Replace('\r', '\n');
                    byte[] bytes = Encoding.UTF8.GetBytes(f + "\n" + text + "\n");
                    sha.TransformBlock(bytes, 0, bytes.Length, null, 0);
                }
                sha.TransformFinalBlock(Array.Empty<byte>(), 0, 0);
                var sb = new StringBuilder();
                for (int i = 0; i < 6; i++) sb.Append(sha.Hash[i].ToString("x2"));
                return sb.ToString();
            }
        }
    }
}
