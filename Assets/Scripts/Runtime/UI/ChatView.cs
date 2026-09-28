// ChatView.cs
// Multiplayer chat panel (NetChat) in the flight HUD and the station menu, while a session runs: on the left, the recent
// lines (fading 12 s after they came in, all shown while typing) over an input row. B (or a tap on the "Chat" tab) opens
// the input, Enter sends, Tab switches Local / Global, Esc closes; the game's keys are off while it is open
// (NetChat.SetTyping). Local lines reach the players in this orbit or docked here, global ones everyone.
// Styles: Resources/GoF2Net/Chat.uss.

using GoF2Remake.Data;
using GoF2Remake.Multiplayer;
using UnityEngine;
using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    public sealed class ChatView : MonoBehaviour
    {
        const float ShowSeconds = 12f, FadeSeconds = 2f;
        const int Lines = 8;

        VisualElement box, log;
        TextField field;
        Button channel;
        bool open, hooked;

        /// <summary>The panel on 'parent' (again after a UI reload), on the HUD's own GameObject.</summary>
        public static void Attach(GameObject host, VisualElement parent)
        {
            if (parent == null) return;
            var view = host.GetComponent<ChatView>();
            if (view == null) view = host.AddComponent<ChatView>();
            view.Build(parent);
        }

        void Build(VisualElement parent)
        {
            box?.RemoveFromHierarchy();
            box = new VisualElement { name = "chat", pickingMode = PickingMode.Ignore };
            box.AddToClassList("chat");
            var sheet = Resources.Load<StyleSheet>("GoF2Net/Chat");
            if (sheet != null) box.styleSheets.Add(sheet);

            var tab = new Label(Localization.Extra("mpChat", "Chat") + "  (B)");
            tab.AddToClassList("chat-tab");
            tab.RegisterCallback<PointerDownEvent>(e => { if (!open) Open(); e.StopPropagation(); });
            box.Add(tab);
            log = new VisualElement { pickingMode = PickingMode.Ignore };
            log.AddToClassList("chat-log");
            box.Add(log);

            var row = new VisualElement();
            row.AddToClassList("chat-input-row");
            channel = new Button(ToggleChannel);
            channel.AddToClassList("chat-channel");
            row.Add(channel);
            field = new TextField { maxLength = NetChat.MaxLength };
            field.AddToClassList("chat-field");
            field.RegisterCallback<KeyDownEvent>(OnKey, TrickleDown.TrickleDown);
            field.RegisterCallback<NavigationCancelEvent>(e => { Close(); e.StopPropagation(); }, TrickleDown.TrickleDown);
            field.RegisterCallback<NavigationMoveEvent>(e => e.StopPropagation(), TrickleDown.TrickleDown);
            // Focus going anywhere but the row's own buttons (a click on the game, Android closing the keyboard): the
            // typing ends, the draft stays; otherwise the game's keys would stay off.
            field.RegisterCallback<FocusOutEvent>(e =>
            {
                if (e.relatedTarget is VisualElement to && (to == channel || to.name == "chatSend")) return;
                Suspend();
            });
            row.Add(field);
            var send = new Button(SendLine) { text = "›", name = "chatSend" };
            send.AddToClassList("chat-send");
            row.Add(send);
            box.Add(row);
            parent.Add(box);

            if (!hooked) { NetChat.Added += OnAdded; hooked = true; }
            RefreshChannel();
            Rebuild();
            box.EnableInClassList("chat--open", open);
        }

        void OnDestroy()
        {
            if (hooked) NetChat.Added -= OnAdded;
            if (open) NetChat.DropTyping();   // the scene's actions go with it (not enabled again)
        }

        void OnKey(KeyDownEvent e)
        {
            if (e.keyCode == KeyCode.Return || e.keyCode == KeyCode.KeypadEnter) { SendLine(); e.StopPropagation(); }
            else if (e.keyCode == KeyCode.Escape) { Close(); e.StopPropagation(); }
            else if (e.keyCode == KeyCode.Tab) { ToggleChannel(); e.StopPropagation(); field.schedule.Execute(() => field.Focus()); }
        }

        void Open()
        {
            open = true;
            box.EnableInClassList("chat--open", true);
            NetChat.SetTyping(true);
            field.schedule.Execute(() => field.Focus());
            Rebuild();
        }

        void Close()
        {
            if (!open) return;
            open = false;
            box.EnableInClassList("chat--open", false);
            field.value = "";
            field.Blur();
            NetChat.SetTyping(false);
            Rebuild();
        }

        void SendLine()
        {
            NetChat.Send(field.value);
            open = true;   // also after the field lost the focus to this button (Suspend)
            Close();
        }

        /// <summary>The field lost the focus: no more typing (the game's keys back), the draft kept for the next Open.</summary>
        void Suspend()
        {
            if (!open) return;
            open = false;
            box.EnableInClassList("chat--open", false);
            NetChat.SetTyping(false);
            Rebuild();
        }

        void ToggleChannel()
        {
            NetChat.Sending = NetChat.Sending == NetChat.Channel.Global ? NetChat.Channel.Local : NetChat.Channel.Global;
            RefreshChannel();
        }

        void RefreshChannel()
        {
            bool global = NetChat.Sending == NetChat.Channel.Global;
            channel.text = (global ? Localization.Extra("mpChatGlobal", "Global") : Localization.Extra("mpChatLocal", "Local")).ToUpperInvariant();
            channel.EnableInClassList("chat-channel--global", global);
        }

        void OnAdded(NetChat.Message m) => Rebuild();

        void Rebuild()
        {
            if (log == null) return;
            log.Clear();
            var all = NetChat.Messages;
            for (int i = Mathf.Max(0, all.Count - Lines); i < all.Count; i++)
            {
                var m = all[i];
                var line = new Label { pickingMode = PickingMode.Ignore, userData = m };
                line.AddToClassList("chat-line");
                if (m.channel == NetChat.Channel.Notice)
                {
                    line.AddToClassList("chat-line--notice");
                    line.text = m.text;
                }
                else
                {
                    string tag = m.channel == NetChat.Channel.Global ? Localization.Extra("mpChatGlobal", "Global") : Localization.Extra("mpChatLocal", "Local");
                    string color = m.channel == NetChat.Channel.Global ? "#f0b35a" : "#8fd8ff";
                    line.text = $"<color={color}>[{tag}]</color> <b>{m.from}</b>: {m.text}";
                    if (m.own) line.AddToClassList("chat-line--own");
                }
                log.Add(line);
            }
        }

        void Update()
        {
            NetChat.KeepGameKeysOff();
            if (box == null) return;
            bool session = NetGame.Active;
            box.style.display = session ? DisplayStyle.Flex : DisplayStyle.None;
            if (!session) { if (open) Close(); return; }
            var keys = NetChat.Keys;
            if (!open && keys != null && keys.bKey.wasPressedThisFrame) Open();
            // Lines fade out a while after they came in (all shown while typing).
            float now = Time.unscaledTime;
            foreach (var child in log.Children())
            {
                if (!(child.userData is NetChat.Message m)) continue;
                float age = now - m.time;
                float a = open ? 1f : Mathf.Clamp01(1f - (age - ShowSeconds) / FadeSeconds);
                child.style.opacity = a;
                child.style.display = a > 0f ? DisplayStyle.Flex : DisplayStyle.None;
            }
        }
    }
}
