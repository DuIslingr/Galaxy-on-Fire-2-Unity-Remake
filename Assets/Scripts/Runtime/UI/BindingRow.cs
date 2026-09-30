// BindingRow.cs
// One line of the key bindings list (remake, Options > Controls; OptionKind.Binding, styled by GoF2Common.uss .binding-*):
// the control's name, then its slots as cells: two keyboard / mouse keys and the controller button (GameControls). A click or
// tap on a cell, or Enter / A on the row (left / right pick the cell), waits for the new key: Esc cancels, Backspace / Delete
// unbinds, a right click unbinds a cell. The row itself is the focusable element, like ChoiceRow. While a key is being
// captured the panel's navigation events are swallowed (the menus' own keys would act on it too).

using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public class BindingRow : VisualElement
    {
        readonly ControlRow row;
        readonly Label label;
        readonly Button[] cells = new Button[3];
        int selected;
        int listening = -1;
        string part;

        static readonly HashSet<IPanel> blockedPanels = new HashSet<IPanel>();

        [UnityEngine.RuntimeInitializeOnLoadMethod(UnityEngine.RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics() => blockedPanels.Clear();

        public BindingRow(ControlRow row)
        {
            this.row = row;
            focusable = true;
            AddToClassList("binding-row");
            label = new Label { pickingMode = PickingMode.Ignore };
            label.AddToClassList("binding-label");
            Add(label);
            for (int s = 0; s < 3; s++)
            {
                int slot = s;
                var b = new Button { focusable = false };
                b.AddToClassList("binding-cell");
                b.AddToClassList("gof-semibold");
                if (s == (int)BindSlot.Pad) b.AddToClassList("binding-cell--pad");
                if (!row.HasSlot((BindSlot)s)) { b.AddToClassList("binding-cell--none"); b.SetEnabled(false); }
                b.clicked += () => { selected = slot; Listen(slot); };
                b.RegisterCallback<PointerUpEvent>(e =>
                {
                    if (e.button != 1 || !row.HasSlot((BindSlot)slot)) return;   // right click: unbind
                    GameControls.CancelRebind();
                    GameControls.Clear(row, (BindSlot)slot);
                });
                cells[s] = b;
                Add(b);
            }
            if (!row.HasSlot(BindSlot.Key1)) selected = 2;
            RegisterCallback<NavigationSubmitEvent>(e =>
            {
                if (GameControls.BlocksMenus) return;
                Activate();
                e.StopPropagation();
                focusController?.IgnoreEvent(e);
            });
            RegisterCallback<AttachToPanelEvent>(e => { GameControls.Changed += Refresh; BlockWhileRebinding(e.destinationPanel); Refresh(); });
            RegisterCallback<DetachFromPanelEvent>(_ =>
            {
                GameControls.Changed -= Refresh;
                if (listening >= 0) GameControls.CancelRebind();
            });
            Refresh();
        }

        /// <summary>The column titles over the rows (under Reset key bindings): Key, Second key, Controller.</summary>
        public static VisualElement Header()
        {
            var h = new VisualElement { pickingMode = PickingMode.Ignore };
            h.AddToClassList("binding-row");
            h.AddToClassList("binding-header");
            var spacer = new VisualElement { pickingMode = PickingMode.Ignore };
            spacer.AddToClassList("binding-label");
            h.Add(spacer);
            foreach (var text in new[] { Localization.Extra("bindKey", "Key"), Localization.Extra("bindKey2", "Second key"), Localization.Extra("bindPad", "Controller") })
            {
                var l = new Label(text) { pickingMode = PickingMode.Ignore };
                l.AddToClassList("binding-cell");
                l.AddToClassList("binding-header-cell");
                h.Add(l);
            }
            return h;
        }

        /// <summary>Left / right on the row: the next cell that has a slot.</summary>
        public void Step(int dir)
        {
            if (listening >= 0) return;
            for (int i = selected + dir; i >= 0 && i < 3; i += dir)
                if (row.HasSlot((BindSlot)i)) { selected = i; break; }
            Refresh();
        }

        /// <summary>Enter / A on the row: capture the selected cell's key.</summary>
        public void Activate() => Listen(selected);

        void Listen(int slot)
        {
            if (!row.HasSlot((BindSlot)slot)) return;
            listening = slot;
            part = null;
            Refresh();
            GameControls.Rebind(row, (BindSlot)slot, p => { part = p; Refresh(); }, () => { listening = -1; part = null; Refresh(); });
            // A menu page closed meanwhile (Back with the mouse): stop waiting.
            schedule.Execute(() => { if (listening >= 0 && !IsShown()) GameControls.CancelRebind(); }).Every(100).Until(() => listening < 0);
        }

        bool IsShown()
        {
            if (panel == null) return false;
            for (VisualElement v = this; v != null; v = v.parent)
                if (v.resolvedStyle.display == DisplayStyle.None) return false;
            return true;
        }

        public void Refresh()
        {
            label.text = row.label();
            for (int s = 0; s < 3; s++)
            {
                var b = cells[s];
                bool has = row.HasSlot((BindSlot)s);
                bool wait = s == listening;
                string text = !has ? "" : wait ? Prompt() : GameControls.SlotText(row, (BindSlot)s);
                b.text = has && text.Length == 0 ? "—" : text;
                b.EnableInClassList("binding-cell--unbound", has && !wait && !GameControls.IsBound(row, (BindSlot)s));
                b.EnableInClassList("binding-cell--listening", wait);
                b.EnableInClassList("binding-cell--selected", s == selected);
            }
        }

        string Prompt()
        {
            string press = listening == (int)BindSlot.Pad ? Localization.Extra("bindPressButton", "Press a button") : Localization.Extra("bindPressKey", "Press a key");
            return part != null ? $"{press}: {part}" : press + "…";
        }

        /// <summary>While a key is being captured (and the frame after), the panel's navigation events don't reach the menus:
        /// Esc would also go back, Enter confirm, the arrows move.</summary>
        static void BlockWhileRebinding(IPanel p)
        {
            if (p == null || !blockedPanels.Add(p)) return;
            void Swallow(EventBase e)
            {
                if (!GameControls.BlocksMenus) return;
                e.StopImmediatePropagation();
                (e.target as VisualElement)?.focusController?.IgnoreEvent(e);
            }
            var tree = p.visualTree;
            tree.RegisterCallback<NavigationMoveEvent>(Swallow, TrickleDown.TrickleDown);
            tree.RegisterCallback<NavigationSubmitEvent>(Swallow, TrickleDown.TrickleDown);
            tree.RegisterCallback<NavigationCancelEvent>(Swallow, TrickleDown.TrickleDown);
            tree.RegisterCallback<KeyDownEvent>(Swallow, TrickleDown.TrickleDown);
        }
    }
}
