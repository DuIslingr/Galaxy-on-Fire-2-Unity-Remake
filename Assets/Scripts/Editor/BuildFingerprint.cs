// BuildFingerprint.cs
// What decides whether two builds can play together (NetGame's connection approval, the server browser): a hash of what
// the multiplayer depends on, the same for every build of the same code whenever and on whatever platform it was built:
// the runtime scripts (Assets/Scripts/Runtime), the network prefabs (Resources/GoF2Net), the game data
// (Resources/GoF2Data) and the versions of the multiplayer packages (Netcode, Unity Transport, Multiplayer Services, as
// resolved in Packages/packages-lock.json). Not the rest of the package list: a package that only helps one machine build
// (a toolchain, an IDE, the test framework) or only draws (URP) doesn't change playing together. Paths sorted, line
// endings normalised (a checkout with CRLF and one with LF hash the same), SHA-256, the first 12 hex digits.
// BuildVersionStamp writes it into Resources/GoF2Build/BuildFingerprint.txt for the build (git-ignored, deleted
// afterwards); the game reads it through BuildVersion.Fingerprint. The build's date and time stays its shown version.

using System;
using System.Collections.Generic;
using System.IO;
using System.Security.Cryptography;
using System.Text;
using System.Text.RegularExpressions;

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

        /// <summary>The packages whose versions decide whether two builds can talk to each other.</summary>
        static readonly string[] NetworkPackages = { "com.unity.netcode.gameobjects", "com.unity.transport", "com.unity.services.multiplayer" };

        /// <summary>"name version" per multiplayer package, as resolved in the lock file ("name ?" when it isn't there).</summary>
        static string PackageVersions()
        {
            string lockText = File.Exists("Packages/packages-lock.json") ? File.ReadAllText("Packages/packages-lock.json") : "";
            var sb = new StringBuilder();
            foreach (var name in NetworkPackages)
            {
                var m = Regex.Match(lockText, "\"" + Regex.Escape(name) + @"""\s*:\s*\{\s*""version""\s*:\s*""([^""]*)""");
                sb.Append(name).Append(' ').Append(m.Success ? m.Groups[1].Value : "?").Append('\n');
            }
            return sb.ToString();
        }

        public static string Compute()
        {
            var files = new List<string>();
            foreach (var (folder, pattern) in Inputs)
                if (Directory.Exists(folder))
                    foreach (var f in Directory.GetFiles(folder, pattern, SearchOption.AllDirectories)) files.Add(f.Replace('\\', '/'));
            files.Sort(StringComparer.Ordinal);
            using (var sha = SHA256.Create())
            {
                byte[] packages = Encoding.UTF8.GetBytes(PackageVersions());
                sha.TransformBlock(packages, 0, packages.Length, null, 0);
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
