// GoF2Localization.cs
// The game's text table (GameText::getText): Localization/text_<lang>.json is a plain array, index = text ID
// as used in the decompiled code (e.g. 28 "Start new game", 170 "Back"). Plain C#; menus pass in the
// TextAssets they reference.

using System;
using System.Collections.Generic;
using UnityEngine;

namespace GoF2Remake.Data
{
    public static class GoF2Localization
    {
        [Serializable] class Wrapper { public string[] items; }

        static string[] texts = new string[0];
        static Dictionary<string, string> extra = new Dictionary<string, string>();

        public static string Language { get; private set; } = "en";
        public static event Action Changed;

        /// <summary>Loads text_{lang}.json content (array of strings).</summary>
        public static void Load(string language, TextAsset table)
        {
            if (table == null) return;
            var w = JsonUtility.FromJson<Wrapper>("{\"items\":" + table.text + "}");
            texts = w?.items ?? new string[0];
            Language = language;
            Changed?.Invoke();
        }

        /// <summary>Text by original ID; falls back to "#id" when missing.</summary>
        public static string Get(int id) => id >= 0 && id < texts.Length && texts[id] != null ? Clean(texts[id]) : "#" + id;

        /// <summary>Remake-only strings (not in the original table), by key, with an English fallback.</summary>
        public static string Extra(string key, string english) => extra.TryGetValue(Language + "." + key, out var s) ? s : english;

        public static void SetExtra(string language, string key, string text) => extra[language + "." + key] = text;

        // The converted table lost a few non-ASCII symbols (U+FFFD); restore the ones the menus show.
        static string Clean(string s) => s.Replace("Fire 2�", "Fire 2®").Replace("� 20", "© 20").Replace("\r\n", "\n");
    }
}
