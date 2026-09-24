// DialogueView.cs
// The story dialogue window (DialogueWindow, Reference/research/dialogue_cutscenes.md 1), shared by the station menu and
// the flight HUD, which host UI/Dialogue/Dialogue.uxml as a template instance and call Tick every frame:
//   pages          (speaker, text id, voice): portrait (mirrored for Keith, speaker 0) and name (text 1597 + speaker)
//   buttons        Back (179, from page 2), Skip (395, only with more than one page: confirm "Skip the dialogue?" 396 with
//                  Yes 134 / No 135), Next (180) / Close (181) on the last page (DialogueWindow::OnTouchEnd 0x196020)
//   voice          the page's line plays when it opens; with voice on (the remake: voice volume > 0) the window turns the
//                  page when the line has ended plus a pause (the FMOD "pause" property isn't parsed: 500 ms), never past
//                  the last page (DialogueWindow::update 0x195bf0)
//   one-page note  ShowMessage: text only with OK (524) (the DialogueWindow(text, name, portrait) variant)
// Input: keyboard Enter / Space / right = next, Backspace / left = back, Esc = skip; controller A = next, B = back,
// Y / Menu = skip; the confirmation takes Enter / A = yes, Esc / B = no. The box is a little larger than the original's
// 694x486 so the remake's font reads well.

using System;
using System.Collections.Generic;
using GoF2Remake.Data;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    public class DialogueView
    {
        public struct Page
        {
            public int speaker;
            public string text;
            public string voice;
            /// <summary>A bar agent instead of a story speaker (freelance briefings / results): its name and portrait parts.</summary>
            public string agentName;
            public int[] agentPortrait;
            public static Page From(DialoguePage p) => new Page { speaker = p.speaker, text = Localization.Get(p.text), voice = p.voice };
        }

        const float VoicePauseMs = 500f;

        readonly VisualElement root, portrait, confirm;
        readonly Label speaker, text, confirmText;
        readonly ScrollView scroll;
        readonly Button back, skip, next, confirmYes, confirmNo;
        readonly AudioSource voice;
        readonly List<Page> pages = new List<Page>();
        Action<bool> closed;
        int page;
        bool message;
        float pauseMs;

        /// <summary>Button sounds (true = press, false = release), set by the host.</summary>
        public Action<bool> ButtonSound;
        public bool IsOpen => root != null && root.ClassListContains("dialogue-backdrop--shown");

        /// <summary>'container' holds the Dialogue.uxml instance; 'voiceSource' plays the lines (2D, not paused with the game).</summary>
        public DialogueView(VisualElement container, AudioSource voiceSource)
        {
            root = container.Q("dialogueRoot");
            if (root == null) { Debug.LogError("DialogueView: no dialogueRoot (Dialogue.uxml instance) in the UI"); return; }
            voice = voiceSource;
            portrait = root.Q("dialoguePortrait");
            speaker = root.Q<Label>("dialogueSpeaker");
            text = root.Q<Label>("dialogueText");
            scroll = root.Q<ScrollView>("dialogueScroll");
            scroll.verticalScrollerVisibility = ScrollerVisibility.Auto;
            scroll.horizontalScrollerVisibility = ScrollerVisibility.Hidden;
            confirm = root.Q("dialogueConfirm");
            confirmText = root.Q<Label>("dialogueConfirmText");
            back = Bind("dialogueBack", Back);
            skip = Bind("dialogueSkip", AskSkip);
            next = Bind("dialogueNext", Next);
            confirmYes = Bind("dialogueConfirmYes", () => { HideConfirm(); Close(true); });
            confirmNo = Bind("dialogueConfirmNo", HideConfirm);
            back.text = Localization.Get(179).ToUpperInvariant();
            skip.text = Localization.Get(395).ToUpperInvariant();
            confirmText.text = Localization.Get(396);
            confirmYes.text = Localization.Get(134).ToUpperInvariant();
            confirmNo.text = Localization.Get(135).ToUpperInvariant();
        }

        Button Bind(string name, Action action)
        {
            var b = root.Q<Button>(name);
            b.RegisterCallback<PointerDownEvent>(_ => ButtonSound?.Invoke(true), TrickleDown.TrickleDown);
            b.clicked += () => { ButtonSound?.Invoke(false); action(); };
            return b;
        }

        /// <summary>A campaign conversation (briefing / success). 'onClosed(skipped)' runs when it closes.</summary>
        public void Show(IList<DialoguePage> story, Action<bool> onClosed)
        {
            var list = new List<Page>();
            foreach (var p in story) list.Add(Page.From(p));
            Show(list, onClosed);
        }

        public void Show(List<Page> list, Action<bool> onClosed)
        {
            if (root == null || list.Count == 0) { onClosed?.Invoke(false); return; }
            pages.Clear();
            pages.AddRange(list);
            closed = onClosed;
            message = false;
            page = 0;
            root.AddToClassList("dialogue-backdrop--shown");
            HideConfirm();
            LoadPage();
        }

        /// <summary>The one-page note from a bar agent (DialogueWindow(mission, level, mode)): name, generated portrait, OK.</summary>
        public void ShowAgentMessage(string body, string name, int[] portraitParts, Action onClosed)
        {
            Show(new List<Page> { new Page { speaker = -1, text = body, agentName = name, agentPortrait = portraitParts } }, _ => onClosed?.Invoke());
            message = true;
            LoadPage();
        }

        /// <summary>The one-page note: text, a speaker's portrait and name, OK.</summary>
        public void ShowMessage(string body, int speakerId, Action onClosed)
        {
            Show(new List<Page> { new Page { speaker = speakerId, text = body } }, _ => onClosed?.Invoke());
            message = true;
            LoadPage();
        }

        void LoadPage()
        {
            var p = pages[page];
            speaker.text = (p.agentName ?? StoryTable.SpeakerName(p.speaker)).ToUpperInvariant();
            text.text = p.text;
            scroll.scrollOffset = Vector2.zero;
            if (p.agentPortrait != null) Portrait.Show(portrait, p.agentPortrait, false);
            else Portrait.ShowSpeaker(portrait, p.speaker, p.speaker == 0);
            bool last = page == pages.Count - 1;
            back.EnableInClassList("dialogue-button--hidden", message || page == 0);
            skip.EnableInClassList("dialogue-button--hidden", message || pages.Count <= 1);
            next.text = (message ? Localization.Get(524) : Localization.Get(last ? 181 : 180)).ToUpperInvariant();
            pauseMs = 0f;
            if (voice != null)
            {
                voice.Stop();
                var clip = StoryAssets.Load()?.Voice(p.voice);
                if (clip != null)
                {
                    voice.clip = clip;
                    voice.volume = Settings.VoiceVolume;
                    voice.Play();
                }
                else voice.clip = null;
            }
        }

        void Next()
        {
            if (!IsOpen) return;
            if (page >= pages.Count - 1) { Close(false); return; }
            page++;
            LoadPage();
        }

        void Back()
        {
            if (!IsOpen || page == 0) return;
            page--;
            LoadPage();
        }

        void AskSkip()
        {
            if (!IsOpen || message || pages.Count <= 1) return;
            confirm.AddToClassList("dialogue-confirm--shown");
        }

        void HideConfirm() => confirm?.RemoveFromClassList("dialogue-confirm--shown");
        bool ConfirmOpen => confirm != null && confirm.ClassListContains("dialogue-confirm--shown");

        void Close(bool skipped)
        {
            voice?.Stop();
            root.RemoveFromClassList("dialogue-backdrop--shown");
            var c = closed;
            closed = null;
            c?.Invoke(skipped);
        }

        /// <summary>Keyboard / controller input and the voice auto-advance; call every frame (unscaled time).</summary>
        public void Tick(float unscaledDtMs)
        {
            if (!IsOpen) return;
            var kb = Keyboard.current;
            var pad = Gamepad.current;
            bool Pressed(Func<Keyboard, bool> k, Func<Gamepad, bool> g) => (kb != null && k(kb)) || (pad != null && g(pad));
            if (ConfirmOpen)
            {
                if (Pressed(k => k.enterKey.wasPressedThisFrame || k.numpadEnterKey.wasPressedThisFrame || k.spaceKey.wasPressedThisFrame, g => g.buttonSouth.wasPressedThisFrame))
                { ButtonSound?.Invoke(false); HideConfirm(); Close(true); }
                else if (Pressed(k => k.escapeKey.wasPressedThisFrame || k.backspaceKey.wasPressedThisFrame, g => g.buttonEast.wasPressedThisFrame))
                { ButtonSound?.Invoke(false); HideConfirm(); }
                return;
            }
            if (Pressed(k => k.enterKey.wasPressedThisFrame || k.numpadEnterKey.wasPressedThisFrame || k.spaceKey.wasPressedThisFrame || k.rightArrowKey.wasPressedThisFrame,
                        g => g.buttonSouth.wasPressedThisFrame || g.dpad.right.wasPressedThisFrame))
            { ButtonSound?.Invoke(false); Next(); return; }
            if (Pressed(k => k.backspaceKey.wasPressedThisFrame || k.leftArrowKey.wasPressedThisFrame, g => g.buttonEast.wasPressedThisFrame || g.dpad.left.wasPressedThisFrame))
            { if (page > 0) { ButtonSound?.Invoke(false); Back(); } return; }
            if (Pressed(k => k.escapeKey.wasPressedThisFrame, g => g.buttonNorth.wasPressedThisFrame || g.startButton.wasPressedThisFrame))
            { ButtonSound?.Invoke(false); AskSkip(); return; }

            // DialogueWindow::update: with voice on, turn the page once the line has ended and its pause passed.
            if (voice != null && voice.clip != null && !voice.isPlaying && Settings.VoiceVolume > 0f && page < pages.Count - 1)
            {
                pauseMs += unscaledDtMs;
                if (pauseMs >= VoicePauseMs) { page++; LoadPage(); }
            }
        }
    }
}
