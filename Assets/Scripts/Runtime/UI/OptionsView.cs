// OptionsView.cs
// Remake: the in-game Options page (the flight pause menu's and the station's system menu), built like the main menu's
// Options panel (MainMenu.uxml optionsPanel) with the same classes (GoF2Common.uss): the title with its amber accent,
// the tabs Sound / Graphics / Controls / Gameplay / Language (only those with rows), one scrolling page of OptionsCatalog
// rows per tab, then Back and Default settings (497) under them. Every option of the catalog is here, the in-game ones
// (OptionDef.inGameOnly) too; the text language stays in the main menu (the HUDs would need rebuilding).
// The host drives the keys / controller: NavItems is what Up / Down walks (the tab row, the active tab's rows, Back,
// Default settings); Q / E and LB / RB switch tabs (StepTab). Rows are focusable for a host that uses the panel's focus
// (the station); the pause menu moves a highlight instead (Select).

using System;
using System.Collections.Generic;
using GoF2Remake.Data;
using UnityEngine;
using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    public sealed class OptionsView
    {
        static readonly OptionPage[] PageOrder = { OptionPage.Sound, OptionPage.Graphics, OptionPage.Controls, OptionPage.Gameplay, OptionPage.Language };

        sealed class Tab
        {
            public OptionPage page;
            public Button button;
            public ScrollView scroll;
            public readonly List<OptionControl> rows = new List<OptionControl>();
        }

        readonly List<Tab> tabs = new List<Tab>();
        readonly List<OptionControl> all = new List<OptionControl>();
        readonly Dictionary<VisualElement, OptionControl> byField = new Dictionary<VisualElement, OptionControl>();
        readonly bool focusableRows;
        readonly Label title;
        VisualElement selected;

        /// <summary>The panel: add it where the menu's panel goes.</summary>
        public readonly VisualElement Root;
        public readonly Button BackButton, DefaultsButton;
        public int TabIndex { get; private set; }

        /// <summary>The player changed an option through a row (after every other row has followed).</summary>
        public event Action<OptionControl> Changed;
        /// <summary>Another tab is shown (a click, StepTab).</summary>
        public event Action TabChanged;
        /// <summary>Default settings (497) put every option back.</summary>
        public event Action DefaultsRestored;

        static string T(int id) => Localization.Get(id).ToUpperInvariant();

        public OptionsView(Action back, bool focusableRows)
        {
            this.focusableRows = focusableRows;
            Root = new VisualElement();
            Root.AddToClassList("options-panel");
            title = new Label(T(31)) { pickingMode = PickingMode.Ignore };
            title.AddToClassList("panel-title");
            title.AddToClassList("gof-semibold");
            Root.Add(title);
            var accent = new VisualElement { pickingMode = PickingMode.Ignore };
            accent.AddToClassList("panel-accent");
            Root.Add(accent);

            var tabRow = new VisualElement();
            tabRow.AddToClassList("tab-row");
            Root.Add(tabRow);
            var defs = OptionsCatalog.All();
            foreach (var page in PageOrder)
            {
                if (!defs.Exists(d => d.page == page)) continue;
                var tab = new Tab { page = page };
                int index = tabs.Count;
                tab.button = new Button { text = OptionsCatalog.PageTitle(page).ToUpperInvariant(), focusable = focusableRows };
                tab.button.AddToClassList("tab-button");
                tab.button.AddToClassList("gof-semibold");
                tab.button.clicked += () => SelectTab(index);
                tabRow.Add(tab.button);
                // Like the main menu's pages: wheel, touch and focus scrolling, no scroll bars (a drag would fight the sliders).
                tab.scroll = new ScrollView(ScrollViewMode.Vertical)
                {
                    horizontalScrollerVisibility = ScrollerVisibility.Hidden,
                    verticalScrollerVisibility = ScrollerVisibility.Hidden,
                };
                tab.scroll.AddToClassList("tab-page");
                tab.scroll.AddToClassList("options-scroll");
                Root.Add(tab.scroll);
                tabs.Add(tab);
            }
            foreach (var def in defs)
            {
                var tab = tabs.Find(t => t.page == def.page);
                if (tab == null) continue;
                var c = new OptionControl(def);
                c.Field.AddToClassList("option-row");
                c.Field.focusable = focusableRows;
                // Options depend on each other (STP turns MSAA off): every row follows a change.
                c.Changed += () => { foreach (var o in all) if (o != c) o.Refresh(); Changed?.Invoke(c); };
                var row = c.Root;
                var scroll = tab.scroll;
                if (focusableRows) c.Field.RegisterCallback<FocusInEvent>(_ => { if (!DragScroll.PointerActive) scroll.ScrollTo(row); });
                tab.scroll.Add(c.Root);
                tab.rows.Add(c);
                all.Add(c);
                byField[c.Field] = c;
            }

            var footer = new VisualElement();
            footer.AddToClassList("options-footer");
            Root.Add(footer);
            BackButton = new Button(() => back?.Invoke()) { text = "‹  " + T(170), focusable = focusableRows };
            BackButton.AddToClassList("menu-button");
            BackButton.AddToClassList("back-button");
            BackButton.AddToClassList("gof-semibold");
            footer.Add(BackButton);
            DefaultsButton = new Button(RestoreDefaults) { text = T(497), focusable = focusableRows };
            DefaultsButton.AddToClassList("menu-button");
            DefaultsButton.AddToClassList("back-button");
            DefaultsButton.AddToClassList("options-defaults");
            DefaultsButton.AddToClassList("gof-semibold");
            footer.Add(DefaultsButton);

            SelectTab(0, false);
        }

        public bool IsShown => Root.resolvedStyle.display != DisplayStyle.None && Root.style.display != DisplayStyle.None;

        public void SetShown(bool shown) => Root.style.display = shown ? DisplayStyle.Flex : DisplayStyle.None;

        /// <summary>The active tab's button (the tab row's place in NavItems).</summary>
        public Button ActiveTab => tabs.Count > 0 ? tabs[TabIndex].button : null;

        public bool IsTab(VisualElement e) => e != null && tabs.Exists(t => t.button == e);

        /// <summary>The row whose field this is (null for the tabs and the footer).</summary>
        public OptionControl RowOf(VisualElement field) => field != null && byField.TryGetValue(field, out var c) ? c : null;

        /// <summary>What Up / Down walks: the active tab, the active page's rows, Back, Default settings.</summary>
        public List<VisualElement> NavItems()
        {
            var list = new List<VisualElement>();
            if (ActiveTab != null) list.Add(ActiveTab);
            if (tabs.Count > 0) foreach (var c in tabs[TabIndex].rows) list.Add(c.Field);
            list.Add(BackButton);
            list.Add(DefaultsButton);
            return list;
        }

        public void SelectTab(int index) => SelectTab(index, true);

        void SelectTab(int index, bool notify)
        {
            if (tabs.Count == 0) return;
            TabIndex = Mathf.Clamp(index, 0, tabs.Count - 1);
            for (int i = 0; i < tabs.Count; i++)
            {
                tabs[i].button.EnableInClassList("tab-button--active", i == TabIndex);
                tabs[i].scroll.EnableInClassList("tab-page--active", i == TabIndex);
            }
            tabs[TabIndex].scroll.scrollOffset = Vector2.zero;
            if (notify) TabChanged?.Invoke();
        }

        /// <summary>The next / previous tab, wrapping (Q / E, LB / RB, left / right on the tab row).</summary>
        public void StepTab(int dir)
        {
            if (tabs.Count > 1) SelectTab(((TabIndex + dir) % tabs.Count + tabs.Count) % tabs.Count);
        }

        /// <summary>The pause menu's highlight (its rows don't take focus): the row, tab or footer button looks focused.</summary>
        public void Select(VisualElement item)
        {
            if (selected != null) Mark(selected, false);
            selected = item;
            if (selected == null) return;
            Mark(selected, true);
            var row = RowOf(selected);
            if (row != null) tabs[TabIndex].scroll.ScrollTo(row.Root);
        }

        static void Mark(VisualElement e, bool on)
        {
            e.EnableInClassList("options-selected", on);
            // The shared controls' selected look (ChoiceRow values, BindingRow cells) keys on this class too.
            e.EnableInClassList("autopilot-menu-item--selected", on);
        }

        /// <summary>Every row re-reads its setting (a change made elsewhere).</summary>
        public void RefreshAll()
        {
            foreach (var c in all) c.Refresh();
        }

        /// <summary>Default settings (497): every option back to its default, the rows with it.</summary>
        public void RestoreDefaults()
        {
            Settings.ResetToDefaults();
            RefreshAll();
            DefaultsRestored?.Invoke();
        }
    }
}
