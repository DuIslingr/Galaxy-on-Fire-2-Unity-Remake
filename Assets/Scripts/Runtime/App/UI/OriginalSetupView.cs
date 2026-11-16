// OriginalSetupView.cs
// Feature: docs/notes/player-assets.md "First start": the screen a build without the original's content shows on the
// startup splash before anything else (StartupSplash, when OriginalSetup.Needed): the player shows the game their copy of
// Galaxy on Fire 2 HD with the system's file picker (ModImport.Pick: Android's and iOS' document pickers, the desktops'
// dialogs), it is converted with its progress shown, then what came
// out (files per kind, what couldn't be read) and on to the logos and the menu. A copy made by an older game (GameContent
// .Stale) gets the same screen with its own title. Built in code into the splash's panel (GoF2Common.uss .original-setup*).

using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using GoF2Remake.Data;
using GoF2Remake.Modding;
using UnityEngine;
using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public sealed class OriginalSetupView
    {
        /// <summary>The screen on show (tests drive it).</summary>
        public static OriginalSetupView Current { get; private set; }

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics() => Current = null;

        static string T(string key, string english) => Localization.Extra("setup." + key, english);

        readonly VisualElement root, card;
        readonly List<string> chosen = new List<string>();
        Func<ModImport.Picked> picking;
        OriginalSetup.Job job;
        bool done;
        string pickError;

        /// <summary>The conversion running (null before and after).</summary>
        public OriginalSetup.Job Job => job;

        public OriginalSetupView(VisualElement root)
        {
            this.root = root;
            card = new VisualElement();
            card.AddToClassList("original-setup");
            root.Add(card);
        }

        /// <summary>Until a copy is installed (or the player quits); 'packsOnly': the copy is installed and kept packs wait
        /// to be written into it (one added since): their progress, then on.</summary>
        public IEnumerator Run(bool packsOnly = false)
        {
            Current = this;
            if (packsOnly) StartPacks(); else Choose();
            while (!done)
            {
                if (picking != null)
                {
                    var r = picking();
                    if (r != null) { picking = null; Picked(r); }
                }
                if (job != null)
                {
                    if (job.Finished) { var j = job; job = null; OriginalSetup.Finish(j); Result(j); }
                    else Progress();
                }
                yield return null;
            }
            card.RemoveFromHierarchy();
            if (Current == this) Current = null;
        }

        // ---- choosing the copy

        void Choose()
        {
            card.Clear();
            Title(GameContent.Stale ? T("staleTitle", "Your copy needs converting again")
                                    : T("title", "Your copy of Galaxy on Fire 2"));
            Text(GameContent.Stale
                ? T("staleText", "This version of the game reads the original's files differently from the one that converted your copy. " +
                                 "Show it your copy once more and it is converted again.")
                : T("text", "This remake comes without the original game's graphics, sounds and text: it makes them from your own copy " +
                            "of Galaxy on Fire 2 HD. Show it the Android version (the .xapk, or the .obb and .apk) or the iOS version " +
                            "(a decrypted .ipa). It is converted once, on this device, in a few minutes."));
            if (chosen.Count > 0)
            {
                Heading(T("chosen", "To convert"));
                foreach (var p in chosen.ToList())
                    Row(p, T("remove", "Remove"), () => { chosen.Remove(p); Choose(); });
            }
            var packs = OriginalPacks.Kept(OriginalPacks.Folder);
            if (packs.Count > 0)
            {
                Heading(T("packs", "Packs (written over the converted copy)"));
                foreach (var pk in packs)
                {
                    var keep = pk;
                    Row(pk.file, T("remove", "Remove"), () => { try { File.Delete(keep.file); } catch (IOException) { } Choose(); }, pk.title ?? pk.name);
                }
            }
            if (pickError != null) Problem(pickError);
            if (chosen.Count > 0)
                Hint(T("hint", "Several files: a later one's files replace an earlier one's (the iOS copy, then Android's for its " +
                               "higher-resolution textures)."));
            var buttons = Buttons();
            var pick = Button(buttons, T("pick", "Choose a file…"), StartPick);
            pick.SetEnabled(picking == null && ModImport.Available);
            var convert = Button(buttons, T("convert", "Convert"), Convert, primary: true);
            convert.SetEnabled(chosen.Count > 0 && picking == null);
            Button(buttons, T("quit", "Quit"), Quit);
            (chosen.Count > 0 ? convert : pick).Focus();
        }

        void StartPick()
        {
            pickError = null;
            picking = ModImport.Pick(T("pickTitle", "Your copy of Galaxy on Fire 2 HD"), "Galaxy on Fire 2 HD", OriginalSetup.Extensions,
                                     copyIn: Application.isMobilePlatform);
            Choose();
        }

        void Picked(ModImport.Picked r)
        {
            if (r.error != null) pickError = r.error;
            else if (!r.cancelled && r.path != null)
            {
                string path = r.path;
                if (path.StartsWith(Application.temporaryCachePath, StringComparison.Ordinal))
                {
                    // a picker's copy ("picked.tmp", replaced by the next pick): kept under its own name until the conversion
                    try
                    {
                        Directory.CreateDirectory(OriginalSetup.PickedFolder);
                        string to = Path.Combine(OriginalSetup.PickedFolder, string.IsNullOrEmpty(r.name) ? "copy.zip" : Path.GetFileName(r.name));
                        if (File.Exists(to)) File.Delete(to);
                        File.Move(path, to);
                        path = to;
                    }
                    catch (IOException e) { pickError = e.Message; path = null; }
                }
                var pack = path != null ? OriginalPacks.Read(path) : null;
                if (pack != null)
                {
                    // a pack (gof2pack.json inside): kept to be written over the copy once it is converted (moved when it is a
                    // picker's copy anyway)
                    try { OriginalPacks.Keep(pack, OriginalPacks.Folder, OriginalSetup.IsImportCopy(path)); }
                    catch (IOException e) { pickError = e.Message; }
                }
                else if (path != null && !chosen.Contains(path)) chosen.Add(path);
            }
            Choose();
        }

        /// <summary>Adds a package and starts converting (tests).</summary>
        public void ConvertNow(params string[] packages)
        {
            chosen.Clear();
            chosen.AddRange(packages);
            Convert();
        }

        /// <summary>The result's Continue (tests): false while there is no successful result on show.</summary>
        public bool Continue()
        {
            if (!succeeded) return false;
            done = true;
            return true;
        }

        bool succeeded;

        // ---- converting

        Label phase, entry, elapsed;
        VisualElement fill;
        float started;

        void Convert()
        {
            if (chosen.Count == 0 || job != null) return;
            ShowProgress(OriginalSetup.Convert(chosen), T("converting", "Converting your copy"),
                         T("convertingText", "This happens once. The game starts as soon as it is done."));
        }

        bool packsOnly;

        void StartPacks()
        {
            packsOnly = true;
            ShowProgress(OriginalSetup.ApplyPacks(), T("installingPacks", "Installing packs"),
                         T("installingPacksText", "Writing the new packs over your converted copy."));
        }

        void ShowProgress(OriginalSetup.Job j, string title, string text)
        {
            job = j;
            started = Time.realtimeSinceStartup;
            card.Clear();
            Title(title);
            Text(text);
            var bar = new VisualElement();
            bar.AddToClassList("original-setup-bar");
            fill = new VisualElement();
            fill.AddToClassList("original-setup-bar-fill");
            bar.Add(fill);
            phase = Text("");
            card.Add(bar);
            entry = Hint("");
            elapsed = Hint("");
            Progress();
        }

        void Progress()
        {
            string p = job.Phase;
            phase.text = p.StartsWith("read ") ? string.Format(T("reading", "Reading {0}"), p.Substring(5))
                       : p.StartsWith("pack ") ? string.Format(T("installingPack", "Installing {0}"), p.Substring(5))
                       : p == "tables" ? T("tables", "Making the text, the data tables and the interface images")
                       : p == "swap" || p == "done" ? T("finishing", "Finishing")
                       : T("starting", "Starting");
            float f = job.Total > 0 ? Mathf.Clamp01(job.Done / (float)job.Total) : p == "tables" || p == "swap" ? 1f : 0f;
            fill.style.width = Length.Percent(f * 100f);
            entry.text = job.Entry ?? "";
            int s = (int)(Time.realtimeSinceStartup - started);
            elapsed.text = $"{s / 60}:{s % 60:00}";
        }

        // ---- the result

        void Result(OriginalSetup.Job j)
        {
            card.Clear();
            if (j.Error != null)
            {
                Title(T("failed", "That didn't work"));
                Text(string.Format(T("failedText", "Nothing was installed: {0}"), j.Error));
                var b = Buttons();
                Button(b, T("back", "Back"), Choose, primary: true).Focus();
                Button(b, T("quit", "Quit"), Quit);
                return;
            }
            succeeded = true;
            if (packsOnly) { done = true; return; }   // (packs written: straight on)
            Title(T("done", "Your copy is ready"));
            string Kind(string k, string english) => j.Counts.TryGetValue(k, out var n) ? $"{n:N0} {T("kind." + k, english)}" : null;
            var kinds = new[] { Kind("Models", "models"), Kind("Textures", "textures"), Kind("Audio", "sounds"),
                                Kind("Localization", "languages"), Kind("Resources", "tables and images") }.Where(k => k != null);
            Text(string.Format(T("doneText", "{0:N0} files in {1:0} s: {2}."), j.Files, j.Seconds, string.Join(", ", kinds)));
            if (j.Problems.Count > 0)
            {
                Heading(string.Format(T("problems", "Not read ({0})"), j.Problems.Count));
                foreach (var p in j.Problems.Take(8)) Problem(p);
            }
            var buttons = Buttons();
            Button(buttons, T("continue", "Continue"), () => done = true, primary: true).Focus();
        }

        static void Quit()
        {
#if UNITY_EDITOR
            UnityEditor.EditorApplication.isPlaying = false;
#else
            Application.Quit();
#endif
        }

        // ---- building blocks

        void Title(string s) => Add(s, "original-setup-title");
        Label Text(string s) => Add(s, "original-setup-text");
        Label Hint(string s) => Add(s, "original-setup-hint");
        void Heading(string s) => Add(s, "original-setup-heading");
        void Problem(string s) => Add(s, "original-setup-problem");

        Label Add(string s, string cls)
        {
            var l = new Label(s);
            l.AddToClassList(cls);
            card.Add(l);
            return l;
        }

        void Row(string path, string action, Action onClick, string title = null)
        {
            var row = new VisualElement();
            row.AddToClassList("original-setup-row");
            var text = new VisualElement { style = { flexGrow = 1, flexShrink = 1 } };
            var name = new Label(title ?? Path.GetFileName(path));
            name.AddToClassList("original-setup-file");
            text.Add(name);
            string size = "";
            try { size = $"{new FileInfo(path).Length / 1048576.0:N0} MB · "; } catch (IOException) { }
            var detail = new Label(size + (OriginalSetup.IsImportCopy(path) ? T("picked", "picked") : Path.GetDirectoryName(path)));
            detail.AddToClassList("original-setup-file-detail");
            text.Add(detail);
            row.Add(text);
            Button(row, action, onClick, compact: true);
            card.Add(row);
        }

        VisualElement Buttons()
        {
            var b = new VisualElement();
            b.AddToClassList("original-setup-buttons");
            card.Add(b);
            return b;
        }

        static Button Button(VisualElement parent, string text, Action onClick, bool primary = false, bool compact = false)
        {
            var b = new Button(onClick) { text = text };
            b.AddToClassList("gof-button");
            if (primary) b.AddToClassList("gof-button--primary");
            if (compact) b.AddToClassList("gof-button--compact");
            parent.Add(b);
            return b;
        }
    }
}
