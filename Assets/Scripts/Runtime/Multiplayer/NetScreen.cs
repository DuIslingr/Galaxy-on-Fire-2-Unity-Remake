// NetScreen.cs
// Remake multiplayer: what the server shows on a player's screen besides the chat (NetAdmin's /title, /timer and /dialog;
// the dialogues go to the scene's own dialogue window, DialogueView.Latest, one after another): a big
// title with an optional subtitle in the upper middle (fades in 0.3 s, holds, fades out 0.6 s), and a countdown with its
// label at the top centre under the HUD message (m:ss, the last 10 s in amber; it stays at 0:00 for 2 s). Its own panel
// (like FpsCounter: the star map's panel settings, sorted over the HUDs and menus), kept across scenes, so docking or
// jumping keeps it; cleared when the session ends.

using GoF2Remake.Data;
using GoF2Remake.UI;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UIElements;

namespace GoF2Remake.Multiplayer
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public sealed class NetScreen : MonoBehaviour
    {
        const float FadeIn = 0.3f, FadeOut = 0.6f, TimerLinger = 2f;

        static NetScreen instance;
        PanelRenderer panelRenderer;
        PanelSettings runtimePanel;
        VisualTreeAsset emptyTree;
        VisualElement titleBox, timerBox;
        Label title, subtitle, timerLabel, timerValue;
        float titleStart, titleEnd = -1f, timerEnd = -1f;
        string titleText = "", subtitleText = "", timerText = "";
        bool pending;
        static readonly Queue<List<DialogueView.Page>> dialogs = new Queue<List<DialogueView.Page>>();

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics() { instance = null; dialogs.Clear(); }

        /// <summary>A conversation from the server: shown in this scene's dialogue window once nothing else is open there.</summary>
        public static void QueueDialog(List<DialogueView.Page> pages)
        {
            if (pages == null || pages.Count == 0 || Get() == null) return;
            if (dialogs.Count < 10) dialogs.Enqueue(pages);
        }

        static NetScreen Get()
        {
            if (instance != null) return instance;
            var assets = StarMapAssets.Load();
            if (assets == null || assets.panelSettings == null) return null;
            var go = new GameObject("NetScreen");
            go.SetActive(false);
            DontDestroyOnLoad(go);
            instance = go.AddComponent<NetScreen>();
            instance.runtimePanel = Instantiate(assets.panelSettings);
            instance.runtimePanel.sortingOrder = assets.panelSettings.sortingOrder + 90;   // over the HUDs and menus, under the FPS counter
            instance.runtimePanel.referenceResolution = new Vector2Int(1920, 1080);
            instance.runtimePanel.screenMatchMode = PanelScreenMatchMode.MatchWidthOrHeight;
            instance.runtimePanel.match = 1f;
            instance.emptyTree = ScriptableObject.CreateInstance<VisualTreeAsset>();
            var pr = go.AddComponent<PanelRenderer>();
            pr.panelSettings = instance.runtimePanel;
            pr.visualTreeAsset = instance.emptyTree;
            go.SetActive(true);
            return instance;
        }

        /// <summary>A title (and subtitle) for 'seconds'; empty text clears it.</summary>
        public static void ShowTitle(string text, string sub, float seconds)
        {
            var s = Get();
            if (s == null) return;
            s.titleText = text ?? "";
            s.subtitleText = sub ?? "";
            s.titleStart = Time.unscaledTime;
            s.titleEnd = s.titleText.Length + s.subtitleText.Length == 0 ? -1f : Time.unscaledTime + Mathf.Max(0.5f, seconds);
            s.pending = true;
        }

        /// <summary>A countdown of 'seconds' with 'label'; seconds below 0 stops it.</summary>
        public static void ShowTimer(float seconds, string label)
        {
            var s = Get();
            if (s == null) return;
            s.timerEnd = seconds < 0f ? -1f : Time.unscaledTime + seconds;
            s.timerText = label ?? "";
            s.pending = true;
        }

        public static void Clear()
        {
            if (instance == null) return;
            instance.titleEnd = instance.timerEnd = -1f;
            instance.pending = true;
        }

        void OnEnable()
        {
            panelRenderer = GetComponent<PanelRenderer>();
            panelRenderer.RegisterUIReloadCallback(OnUIReload);
        }

        void OnDisable() => panelRenderer?.UnregisterUIReloadCallback(OnUIReload);

        void OnDestroy()
        {
            if (runtimePanel != null) Destroy(runtimePanel);
            if (emptyTree != null) Destroy(emptyTree);
            if (instance == this) instance = null;
        }

        static Label Text(VisualElement parent, float size, Color colour, float spacing)
        {
            var l = new Label { pickingMode = PickingMode.Ignore };
            var s = l.style;
            s.fontSize = size;
            s.color = colour;
            s.letterSpacing = spacing;
            s.unityTextAlign = TextAnchor.MiddleCenter;
            s.whiteSpace = WhiteSpace.Normal;
            s.maxWidth = 1500;
            s.textShadow = new TextShadow { offset = new Vector2(0f, 2f), blurRadius = 8f, color = new Color(0f, 0f, 0f, 0.95f) };
            parent.Add(l);
            return l;
        }

        void OnUIReload(PanelRenderer renderer, VisualElement root, int version)
        {
            root.pickingMode = PickingMode.Ignore;
            root.style.position = Position.Absolute;
            root.style.left = root.style.top = root.style.right = root.style.bottom = 0;
            titleBox = new VisualElement { pickingMode = PickingMode.Ignore };
            titleBox.style.position = Position.Absolute;
            titleBox.style.left = titleBox.style.right = 0;
            titleBox.style.top = Length.Percent(24);
            titleBox.style.alignItems = Align.Center;
            root.Add(titleBox);
            title = Text(titleBox, 64, Color.white, 8);
            title.AddToClassList("gof-semibold");
            subtitle = Text(titleBox, 30, new Color(1f, 0.75f, 0.35f), 4);
            subtitle.style.marginTop = 8;
            timerBox = new VisualElement { pickingMode = PickingMode.Ignore };
            timerBox.style.position = Position.Absolute;
            timerBox.style.left = timerBox.style.right = 0;
            timerBox.style.top = 96;
            timerBox.style.alignItems = Align.Center;
            root.Add(timerBox);
            timerLabel = Text(timerBox, 20, new Color(0.85f, 0.92f, 1f), 4);
            timerValue = Text(timerBox, 40, Color.white, 3);
            timerValue.AddToClassList("gof-semibold");
            pending = true;
        }

        void Update()
        {
            if (title == null) return;
            if (!NetGame.Active && (titleEnd >= 0f || timerEnd >= 0f)) { titleEnd = timerEnd = -1f; pending = true; }
            if (!NetGame.Active) dialogs.Clear();
            var view = DialogueView.Latest;
            if (dialogs.Count > 0 && view != null && view.Usable && !view.IsOpen && !StarMap.IsOpen) view.Show(dialogs.Dequeue(), null);
            float now = Time.unscaledTime;
            // The title: fade in, hold, fade out.
            bool titleOn = titleEnd >= 0f && now < titleEnd + FadeOut;
            if (pending) { title.text = titleText; subtitle.text = subtitleText; subtitle.style.display = subtitleText.Length > 0 ? DisplayStyle.Flex : DisplayStyle.None; }
            titleBox.style.display = titleOn ? DisplayStyle.Flex : DisplayStyle.None;
            if (titleOn) titleBox.style.opacity = Mathf.Min(Mathf.Clamp01((now - titleStart) / FadeIn), Mathf.Clamp01((titleEnd + FadeOut - now) / FadeOut));
            else if (titleEnd >= 0f) titleEnd = -1f;
            // The countdown: m:ss, amber for the last 10 s, gone 2 s after 0.
            bool timerOn = timerEnd >= 0f && now < timerEnd + TimerLinger;
            timerBox.style.display = timerOn ? DisplayStyle.Flex : DisplayStyle.None;
            if (timerOn)
            {
                if (pending) { timerLabel.text = timerText.ToUpperInvariant(); timerLabel.style.display = timerText.Length > 0 ? DisplayStyle.Flex : DisplayStyle.None; }
                int left = Mathf.CeilToInt(Mathf.Max(0f, timerEnd - now));
                timerValue.text = $"{left / 60}:{left % 60:00}";
                timerValue.style.color = left <= 10 ? new Color(1f, 0.7f, 0.25f) : Color.white;
            }
            else if (timerEnd >= 0f) timerEnd = -1f;
            pending = false;
        }
    }
}
