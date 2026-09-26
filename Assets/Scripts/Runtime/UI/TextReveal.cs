// TextReveal.cs
// Remake-only (option "Animated dialogue", Settings.AnimatedDialogue; off = the original's plain page at once): the
// dialogue window's and the radio box's text appears letter by letter with a little emotion, through rich text:
//   reveal     each letter fades in (FadeMs) and settles from a brighter tint to its colour; the rest of the page is laid
//              out already, invisible, so no word jumps to the next line while it types
//   pacing     ReadingSpeed letters per second, or paced to the voice line (the whole timeline ends at ~85 % of it);
//              short pauses after , ; : and . ? !, a longer hesitation after "...", sentences ending in "!" type faster
//   shouting   all-caps words ("KEITH!", "MORE!", "BANG!", "KABOOM"; 4+ letters, or 2+ before a "!", not the acronyms)
//              are bigger and bold and shake for a moment as they appear
//   actions    *Sigh* / *Yawn* (Russian: <шепотом>): italic, dimmer, the markers dropped, typed slowly
//   names      people and ships amber, places and races cyan (story speakers, stations, systems, ships, races; whole
//              words, case-sensitive)
// Alien-font pages (AlienText) fade their glyph images in the same rhythm; Arabic / Hebrew pages (joined, right to left)
// fade in whole instead, so the per-letter tags never split the letter joining. Japanese / Chinese punctuation (。！？、)
// pauses without a following space. All-caps words of item, ship, station and system names ("Micro Gun MKII") never
// count as shouting. The texts have no rich text tags of their own ('<' is escaped). Checked against all 11 text tables.
// Plain C#: the owner calls Begin after setting the text, then Tick every frame.

using System.Collections.Generic;
using System.Text;
using GoF2Remake.Data;
using UnityEngine;
using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    public class TextReveal
    {
        /// <summary>Letters per second without a voice line.</summary>
        public const float ReadingSpeed = 55f;
        const float MinSpeed = 18f, MaxSpeed = 110f, VoiceShare = 0.85f;
        const float FadeMs = 140f, SettleMs = 260f, ShakeMs = 450f, ShakeEm = 0.07f;
        const float CommaPauseMs = 90f, StopPauseMs = 220f, EllipsisPauseMs = 420f;
        const float ExclaimPace = 0.75f, ActionPace = 2.2f;
        const float ShoutSize = 130f, ActionDim = 0.65f;
        static readonly Color PersonTint = new Color32(0xFF, 0xB8, 0x55, 0xFF);
        static readonly Color PlaceTint = new Color32(0x5C, 0xD2, 0xFF, 0xFF);
        static readonly HashSet<string> Acronyms = new HashSet<string> { "EMP", "PEM", "IEM", "ЭМИ", "HUD", "AMR", "IMT", "OK" };   // EMP in es / fr / ru too

        struct Letter
        {
            public char c;
            public Color? tint;
            public bool shout, action;
            public float pace, pauseAfter, start;   // start: ms on the page's clock
        }

        readonly Label label;
        readonly List<Letter> letters = new List<Letter>();
        readonly List<VisualElement> glyphs = new List<VisualElement>();
        bool alien, running, whole;
        string speakerName;
        float clock, letterMs, endMs;
        int shown;

        public TextReveal(Label label) { this.label = label; }

        /// <summary>True while letters are still appearing (or settling).</summary>
        public bool Running => running;
        /// <summary>0..1 of the letters started (1 when not animating).</summary>
        public float Progress => running && letters.Count > 0 ? (float)shown / letters.Count : 1f;

        /// <summary>Starts revealing the label's page (already set with AlienText.Set). 'voice' paces it; 'instant' shows it
        /// styled at once (a page read before); 'speaker' (a bar agent's generated name) is tinted like the story names.
        /// Does nothing with the option off.</summary>
        public void Begin(string pageText, bool alienFont, AudioClip voice = null, bool instant = false, string speaker = null)
        {
            speakerName = speaker;
            running = false;
            glyphs.Clear();
            letters.Clear();
            whole = false;
            if (label == null) return;
            label.style.opacity = StyleKeyword.Null;
            if (!Settings.AnimatedDialogue) return;
            alien = alienFont && AlienText.CollectGlyphs(label, glyphs);
            if (!alien && IsRightToLeft(pageText))
            {
                // The page as it is, faded in whole.
                whole = true;
                clock = instant ? float.MaxValue / 4f : 0f;
                endMs = SettleMs * 1.5f;
                running = !instant;
                Render();
                return;
            }
            if (alien) for (int i = 0; i < glyphs.Count; i++) letters.Add(new Letter { c = 'A', pace = 1f });
            else Parse(pageText ?? "");
            if (letters.Count == 0) return;

            // The timeline: every letter costs letterMs x its pace, pauses on top. A voice line sets letterMs so the whole
            // page (pauses included) ends at VoiceShare of the recording.
            float paces = 0f, pauses = 0f;
            foreach (var l in letters) { paces += l.pace; pauses += l.pauseAfter; }
            letterMs = 1000f / ReadingSpeed;
            if (voice != null && voice.length > 0.5f)
                letterMs = Mathf.Clamp((voice.length * 1000f * VoiceShare - pauses) / Mathf.Max(1f, paces), 1000f / MaxSpeed, 1000f / MinSpeed);
            float t = 0f;
            for (int i = 0; i < letters.Count; i++)
            {
                var l = letters[i];
                l.start = t;
                letters[i] = l;
                t += letterMs * l.pace + l.pauseAfter;
            }
            endMs = t + SettleMs + ShakeMs;
            clock = instant ? float.MaxValue / 4f : 0f;
            running = !instant;
            Render();
        }

        /// <summary>Shows the whole page now (Next during the reveal).</summary>
        public void Finish()
        {
            if (!running) return;
            running = false;
            clock = float.MaxValue / 4f;
            Render();
        }

        public void Tick(float unscaledDtMs)
        {
            if (!running) return;
            clock += unscaledDtMs;
            if (clock >= endMs) { Finish(); return; }
            Render();
        }

        // ---- parsing -------------------------------------------------------------------------------------------

        void Parse(string page)
        {
            // *Action* markers (Russian <action>): the words stay, the markers go.
            var action = new List<bool>();
            var sb = new StringBuilder(page.Length);
            char closeMark = '\0';
            for (int i = 0; i < page.Length; i++)
            {
                char c = page[i];
                if (closeMark != '\0' && c == closeMark) { closeMark = '\0'; continue; }
                if (closeMark == '\0' && (c == '*' || c == '<'))
                {
                    char end = c == '*' ? '*' : '>';
                    int close = page.IndexOf(end, i + 1);
                    if (close > i + 1 && page.IndexOf('\n', i + 1, close - i - 1) < 0) { closeMark = end; continue; }
                }
                sb.Append(c);
                action.Add(closeMark != '\0');
            }
            string text = sb.ToString();
            var tints = Highlight(text, speakerName);
            var shout = Shouts(text);
            var exclaim = ExclaimedSentences(text);
            for (int i = 0; i < text.Length; i++)
            {
                char c = text[i];
                bool endOfWord = i + 1 >= text.Length || char.IsWhiteSpace(text[i + 1]);
                float pause = 0f;
                if (c == '.' && i >= 2 && text[i - 1] == '.' && text[i - 2] == '.') pause = EllipsisPauseMs;
                else if (c == '…') pause = EllipsisPauseMs;
                else if (endOfWord && (c == '.' || c == '?' || c == '!') && !(i + 1 < text.Length && text[i + 1] == '.')) pause = StopPauseMs;
                else if (endOfWord && (c == ',' || c == ';' || c == ':')) pause = CommaPauseMs;
                else if (c == '\u3002' || c == '\uFF01' || c == '\uFF1F') pause = StopPauseMs;   // 。！？
                else if (c == '\u3001' || c == '\uFF0C') pause = CommaPauseMs;                   // 、，
                if (i + 1 >= text.Length) pause = 0f;
                letters.Add(new Letter
                {
                    c = c, tint = tints[i], shout = shout[i], action = action[i], pauseAfter = pause,
                    pace = action[i] ? ActionPace : exclaim[i] ? ExclaimPace : 1f,
                });
            }
        }

        /// <summary>All-caps words: 4+ letters, or 2+ followed by '!' (the '!' too), not the acronyms.</summary>
        static bool[] Shouts(string text)
        {
            var result = new bool[text.Length];
            int i = 0;
            while (i < text.Length)
            {
                if (!char.IsLetter(text[i])) { i++; continue; }
                int start = i, letterCount = 0;
                bool caps = true;
                while (i < text.Length && (char.IsLetter(text[i]) || text[i] == '\'' || text[i] == '-'))
                {
                    if (char.IsLetter(text[i])) { letterCount++; if (!char.IsUpper(text[i])) caps = false; }
                    i++;
                }
                if (!caps || letterCount < 2) continue;
                string word = text.Substring(start, i - start);
                bool bang = i < text.Length && text[i] == '!';
                if (letterCount < 4 && !bang) continue;
                if (Acronyms.Contains(word)) continue;   // "Ready the EMP!" isn't a shout
                if (NameCaps().Contains(word)) continue;   // "Micro Gun MKII", not a shout
                for (int k = start; k < i; k++) result[k] = true;
                while (i < text.Length && (text[i] == '!' || text[i] == '?')) result[i++] = true;
            }
            return result;
        }

        /// <summary>The letters of sentences that end in '!'.</summary>
        static bool[] ExclaimedSentences(string text)
        {
            var result = new bool[text.Length];
            int start = 0;
            for (int i = 0; i < text.Length; i++)
            {
                char c = text[i];
                if (c != '.' && c != '!' && c != '?' && c != '\n' && c != '\u3002' && c != '\uFF01' && c != '\uFF1F') continue;
                if (c == '!' || c == '\uFF01') for (int k = start; k <= i; k++) result[k] = true;
                start = i + 1;
            }
            return result;
        }

        // ---- rendering -----------------------------------------------------------------------------------------

        static bool IsRightToLeft(string text)
        {
            if (text == null) return false;
            foreach (char c in text) if (c >= '\u0590' && c <= '\u08FF' || c >= '\uFB1D' && c <= '\uFEFC') return true;
            return false;
        }

        void Render()
        {
            shown = 0;
            if (whole)
            {
                label.style.opacity = Mathf.SmoothStep(0f, 1f, Mathf.Clamp01(clock / endMs));
                return;
            }
            if (alien)
            {
                for (int i = 0; i < glyphs.Count; i++)
                {
                    float age = clock - letters[i].start;
                    if (age >= 0f) shown++;
                    glyphs[i].style.opacity = Mathf.Clamp01(age / FadeMs);
                }
                return;
            }
            var baseColour = label.resolvedStyle.color;
            if (baseColour.a <= 0f) baseColour = Color.white;
            var sb = new StringBuilder(letters.Count * 6);
            string open = null, close = null;
            for (int i = 0; i < letters.Count; i++)
            {
                var l = letters[i];
                float age = clock - l.start;
                if (age >= 0f) shown++;
                var colour = l.tint ?? baseColour;
                if (l.action) colour = new Color(colour.r * ActionDim, colour.g * ActionDim, colour.b * ActionDim, colour.a);
                float shake = 0f;
                if (!char.IsWhiteSpace(l.c))
                {
                    // Fade in, then settle from the bright tint (16 steps each, so the rich text stays a handful of runs).
                    float alpha = Quantize(Mathf.Clamp01(age / FadeMs));
                    float settle = Quantize(Mathf.Clamp01((age - FadeMs * 0.5f) / SettleMs));
                    colour = Color.Lerp(Color.Lerp(colour, Color.white, 0.75f), colour, settle);
                    colour.a *= alpha;
                    if (l.shout && age > 0f && age < ShakeMs)
                        shake = Mathf.Round(ShakeEm * (1f - age / ShakeMs) * Mathf.Sin(age * 0.09f + i * 2.1f) * 100f) / 100f;
                }
                var tag = new StringBuilder("<color=#").Append(ColorUtility.ToHtmlStringRGBA(colour)).Append('>');
                var end = new StringBuilder();
                if (l.shout) { tag.Append("<size=").Append(ShoutSize.ToString("0")).Append("%><b>"); end.Insert(0, "</b></size>"); }
                if (l.action) { tag.Append("<i>"); end.Insert(0, "</i>"); }
                if (shake != 0f)
                {
                    tag.Append("<voffset=").Append(shake.ToString("0.00", System.Globalization.CultureInfo.InvariantCulture)).Append("em>");
                    end.Insert(0, "</voffset>");
                }
                end.Append("</color>");
                string t = tag.ToString();
                if (t != open)
                {
                    if (close != null) sb.Append(close);
                    sb.Append(t);
                    open = t;
                    close = end.ToString();
                }
                if (l.c == '<') sb.Append("<noparse><</noparse>");
                else sb.Append(l.c);
            }
            if (close != null) sb.Append(close);
            label.text = sb.ToString();
        }

        static float Quantize(float v) => Mathf.Round(v * 16f) / 16f;

        // ---- names ---------------------------------------------------------------------------------------------

        static List<(string name, bool person)> names;
        static HashSet<string> nameCaps;
        static bool hooked;

        /// <summary>The all-caps words in item, ship, station and system names.</summary>
        static HashSet<string> NameCaps()
        {
            if (nameCaps != null) return nameCaps;
            Hook();
            nameCaps = new HashSet<string>();
            void Scan(string n)
            {
                if (string.IsNullOrEmpty(n)) return;
                foreach (var w in n.Split(' ', '-', '/', '(', ')'))
                {
                    int letters = 0;
                    bool caps = true;
                    foreach (char c in w) if (char.IsLetter(c)) { letters++; if (!char.IsUpper(c)) caps = false; }
                    if (caps && letters >= 2) nameCaps.Add(w.Trim('.', ',', '!', '?'));
                }
            }
            var db = Database.Load();
            if (db != null)
            {
                for (int i = 0; i < db.Items.Count; i++) Scan(Localization.Get(1274 + i));
                for (int i = 0; i < db.Ships.Count && i < 64; i++) Scan(Localization.Get(913 + i));
                foreach (var st in db.Stations) Scan(st.name);
                foreach (var sy in db.Systems) Scan(sy.name);
            }
            return nameCaps;
        }

        static void Hook()
        {
            if (hooked) return;
            hooked = true;
            Localization.Changed += () => { names = null; nameCaps = null; };
        }

        /// <summary>The tint per letter of the names in 'page' (null = the label's colour).</summary>
        static Color?[] Highlight(string page, string speaker)
        {
            var result = new Color?[page.Length];
            var list = new List<(string, bool)>();
            if (!string.IsNullOrWhiteSpace(speaker))
            {
                list.Add((speaker.Trim(), true));
                foreach (var part in speaker.Split(' ')) if (part.Length >= 3 && char.IsUpper(part[0])) list.Add((part, true));
            }
            list.AddRange(Names());
            foreach (var (name, person) in list)
            {
                int from = 0;
                while (from < page.Length)
                {
                    int at = page.IndexOf(name, from, System.StringComparison.Ordinal);
                    if (at < 0) break;
                    from = at + name.Length;
                    if (at > 0 && char.IsLetterOrDigit(page[at - 1])) continue;
                    if (from < page.Length && char.IsLetterOrDigit(page[from])) continue;
                    bool free = true;
                    for (int i = at; i < from; i++) if (result[i].HasValue) { free = false; break; }   // longer names first
                    if (!free) continue;
                    for (int i = at; i < from; i++) if (!char.IsWhiteSpace(page[i])) result[i] = person ? PersonTint : PlaceTint;
                }
            }
            return result;
        }

        /// <summary>Story speakers with proper names (and their first / last names), ships, races, stations and systems;
        /// longest first. Rebuilt when the language changes.</summary>
        static List<(string, bool)> Names()
        {
            if (names != null) return names;
            Hook();
            var set = new Dictionary<string, bool>();
            void Add(string n, bool person)
            {
                n = n?.Trim();
                if (string.IsNullOrEmpty(n) || n.Length < 3 || n.IndexOf('�') >= 0 || set.ContainsKey(n)) return;
                set[n] = person;
            }
            // Speakers with a personal name (not "Pirate", "Computer", "Barkeeper" ...); "T." and "Dr." aren't names.
            int[] people = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 20, 24, 25, 26, 31, 32, 34, 36, 37, 38, 39, 40, 44, 45, 46, 47, 55, 60 };
            foreach (int s in people)
            {
                string full = StoryTable.SpeakerName(s);
                Add(full, true);
                foreach (var part in full.Split(' '))
                    if (part.Length >= 4 && !part.EndsWith(".") && char.IsUpper(part[0])) Add(part, true);
            }
            var db = Database.Load();
            if (db != null)
            {
                for (int i = 0; i < db.Ships.Count && i < 64; i++) Add(Localization.Get(913 + i), true);   // 977+ = descriptions
                foreach (var st in db.Stations) Add(st.name, false);
                foreach (var sy in db.Systems) Add(sy.name, false);
            }
            for (int r = 0; r <= 9; r++) if (r != 8) Add(Localization.Get(406 + r), false);   // races, not "Pirate"
            names = new List<(string, bool)>();
            foreach (var kv in set) names.Add((kv.Key, kv.Value));
            names.Sort((a, b) => b.Item1.Length.CompareTo(a.Item1.Length));
            return names;
        }
    }
}
