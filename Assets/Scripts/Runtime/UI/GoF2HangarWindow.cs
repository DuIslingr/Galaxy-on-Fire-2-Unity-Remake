// GoF2HangarWindow.cs
// The station's Hangar window (HangarWindow 0x171630, HangarList 0x142b88, ListItemWindow 0x159468), driven by
// GoF2StationMenu over the 3D hangar. Rules live in GoF2Hangar; this is the list, the details and the controls.
//   Shop tab (185): header 173 "Ships" + the dealer's ships, then per type (265 / 266 / 267 / 269 / 270) everything in
//             cargo or in stock. Selected item: station stock (left, sell arrow) and cargo (right, buy arrow), price.
//   Ship tab (183): your ship, then per slot type its slots (mounted item or empty) and the cargo items of that type
//             that could be mounted. Mount (281) / Demount (282), one-per-ship categories swap (287).
// Details: icon on its type frame, stats (GoF2ItemInfo), description and known price range.
// Controls: tap / click a row; up / down select, left / right sell / buy (held arrows repeat like HangarWindow::update:
// after 200 ms, every 30 ms after 1.5 s, 5 units at a time after 4 s), Enter / A the row's action, Q / E or LB / RB
// switch tabs. Sounds: 0x7c row, 0x65 buy (Button_to_ship), 0x64 sell (Button_to_station), 0x62 mount, 0x60 demount.
//   Blueprints tab (272, HangarList::initBlueprintTab 0x143208; blueprints_mods.md 1.5): 273 "Available blueprints" with
//             the unlocked ones (progress "N%  (station)", highlighted while the hold carries a missing ingredient) and
//             274 "Products finished" waiting elsewhere. Edit (283) opens the ingredients (tab 4): the right arrow moves
//             one unit from the hold into the blueprint (held arrows repeat), invested goods can't be taken back; the
//             first unit asks 212 "Start production at this station?" (528 for 210 / 223 without gate routes); leaving
//             the ingredient commits it, at another station than the production station for 200 $ per unit (288;
//             volatile goods 289); Autocomplete (hard-coded English) for int(qty * maxPrice * 1.25) (195). A finished
//             run goes to the hold here (211) or waits at the production station (210).
// Not yet: the full-screen details window, Kaamo Club storage.

using System;
using System.Collections.Generic;
using System.Linq;
using GoF2Remake.Data;
using GoF2Remake.World;
using UnityEngine;
using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    public class GoF2HangarWindow
    {
        public enum Tab { Ship, Shop, Blueprints }
        enum RowKind { Header, ShopItem, ShopShip, OwnShip, Slot, CargoItem, Blueprint, Pending, Ingredient, Autocomplete }

        class Row
        {
            public RowKind kind;
            public int item = -1, ship = -1, equipment = -1, type = -1;
            public VisualElement element;
            public bool Selectable => kind != RowKind.Header;
            public bool Same(Row o) => o != null && o.kind == kind && o.item == item && o.ship == ship && o.type == type
                                       && (kind != RowKind.Slot || o.equipment == equipment);
        }

        readonly GoF2StationMenu menu;
        readonly GoF2StationLevel level;
        readonly VisualElement window, details, detailIcon, detailStats, tradeBox, sellButton, buyButton;
        readonly ScrollView list, detailScroll;
        readonly Label detailName, detailSub, detailText, tradeStock, tradeCargo, tradePrice, cargoLabel, creditsLabel, tradeStockLabel, tradeCargoLabel, sellLabel, buyLabel;
        readonly Button tabShip, tabShop, tabBlueprints, actionButton;
        /// <summary>Tab 4: the blueprint whose ingredients are listed (-1 = the blueprint list).</summary>
        int editing = -1;
        /// <summary>Item+0x3c blueprintAmount: units moved from the hold but not committed yet, per ingredient.</summary>
        readonly Dictionary<int, int> pendingUnits = new Dictionary<int, int>();
        bool startConfirmed;
        readonly List<Row> rows = new List<Row>();
        GoF2Hangar hangar;
        Row selected;
        Tab tab = Tab.Shop;   // HangarWindow's static lastTab starts at 1 (Shop)

        // Held trade arrow or key (HangarWindow::update 0x172626); heldPointer -2 = a key / the D-pad.
        int heldDirection, heldPointer = -1;
        float heldMs, repeatMs;
        const int KeyHold = -2;

        // Held up / down (list selection): first repeat after 350 ms, then every 80 ms.
        int moveDirection, keyDirection;
        float moveMs;

        public bool IsOpen { get; private set; }

        public GoF2HangarWindow(GoF2StationMenu menu, GoF2StationLevel level, VisualElement root)
        {
            this.menu = menu;
            this.level = level;
            window = root.Q("hangarWindow");
            list = root.Q<ScrollView>("hangarList");
            details = root.Q("hangarDetails");
            detailIcon = root.Q("detailIcon");
            detailStats = root.Q("detailStats");
            detailScroll = root.Q<ScrollView>("detailScroll");
            detailName = root.Q<Label>("detailName");
            detailSub = root.Q<Label>("detailSub");
            detailText = root.Q<Label>("detailText");
            tradeBox = root.Q("tradeBox");
            sellButton = root.Q("sellButton");
            buyButton = root.Q("buyButton");
            tradeStock = root.Q<Label>("tradeStock");
            tradeCargo = root.Q<Label>("tradeCargo");
            tradePrice = root.Q<Label>("tradePrice");
            cargoLabel = root.Q<Label>("cargoLabel");
            creditsLabel = root.Q<Label>("creditsLabel");
            tabShip = root.Q<Button>("tabShip");
            tabShop = root.Q<Button>("tabShop");
            tabBlueprints = root.Q<Button>("tabBlueprints");
            actionButton = root.Q<Button>("actionButton");
            tradeStockLabel = root.Q<Label>("tradeStockLabel");
            tradeCargoLabel = root.Q<Label>("tradeCargoLabel");

            string T(int id) => GoF2Localization.Get(id).ToUpperInvariant();
            tabShip.text = T(183);
            tabShop.text = T(185);
            tabBlueprints.text = T(272);
            sellLabel = root.Q<Label>("sellLabel");
            buyLabel = root.Q<Label>("buyLabel");
            root.Q<Button>("hangarClose").text = GoF2Localization.Extra("hudBack", "BACK");

            tabShip.clicked += () => { menu.PlayPush(); SetTab(Tab.Ship); };
            tabShop.clicked += () => { menu.PlayPush(); SetTab(Tab.Shop); };
            tabBlueprints.clicked += () => { menu.PlayPush(); SetTab(Tab.Blueprints); };
            root.Q<Button>("hangarClose").clicked += () => { menu.PlayRelease(); if (!Back()) menu.CloseHangar(); };
            actionButton.clicked += Action;
            HookArrow(sellButton, -1);
            HookArrow(buyButton, 1);
            foreach (var b in new VisualElement[] { tabShip, tabShop, tabBlueprints, actionButton }) b.focusable = false;
            list.focusable = detailScroll.focusable = false;
        }

        // ---- open / close ------------------------------------------------------------------------------------

        public void Open()
        {
            IsOpen = true;
            hangar = new GoF2Hangar(level.Database, level.Stock);   // prices are recomputed on every open, like the original
            selected = null;
            Rebuild();
        }

        public void Close()
        {
            if (!IsOpen) return;
            AutoEquip();
            IsOpen = false;
            editing = -1;
            ReleaseArrow();
        }

        /// <summary>HangarWindow::readyToClose: an uncommitted shipment to another station asks first.</summary>
        public bool ReadyToClose()
        {
            if (!HasPending) return true;
            Commit(() => menu.CloseHangar());
            return false;
        }

        /// <summary>Back inside the window: the ingredient list returns to the blueprint list (after committing).</summary>
        public bool Back()
        {
            if (editing < 0) return false;
            Commit(() => { editing = -1; selected = null; Rebuild(); });
            return true;
        }

        public void SetTab(Tab t)
        {
            if (tab == t && rows.Count > 0 && editing < 0) return;
            if (HasPending) { Commit(() => SetTab(t)); return; }
            AutoEquip();
            tab = t;
            editing = -1;
            selected = null;
            Rebuild();
        }

        public void NextTab() => SetTab(tab == Tab.Ship ? Tab.Shop : tab == Tab.Shop ? Tab.Blueprints : Tab.Ship);

        // ---- list --------------------------------------------------------------------------------------------

        void Rebuild()
        {
            if (!IsOpen) return;
            tabShip.EnableInClassList("hangar-tab--active", tab == Tab.Ship);
            tabShop.EnableInClassList("hangar-tab--active", tab == Tab.Shop);
            tabBlueprints.EnableInClassList("hangar-tab--active", tab == Tab.Blueprints);
            var keep = selected;
            float scroll = list.scrollOffset.y;
            rows.Clear();
            list.Clear();
            string T(int id) => GoF2Localization.Get(id).ToUpperInvariant();
            int[] typeHeaders = { 265, 266, 267, 269, 270 };

            if (tab == Tab.Shop)
            {
                if (hangar.Stock.ships.Count > 0)
                {
                    AddHeader(T(173));
                    foreach (int s in hangar.Stock.ships) AddRow(new Row { kind = RowKind.ShopShip, ship = s });
                }
                var items = hangar.ShopItems();
                for (int type = 0; type <= 4; type++)
                {
                    var ofType = items.Where(i => hangar.TypeOf(i) == type).ToList();
                    if (ofType.Count == 0) continue;
                    AddHeader(T(typeHeaders[type]));
                    foreach (int i in ofType) AddRow(new Row { kind = RowKind.ShopItem, item = i, type = type });
                }
            }
            else if (tab == Tab.Blueprints)
            {
                var db = level.Database;
                if (editing >= 0)
                {
                    // Tab 4 (HangarList::fillIngredientsList 0x14378c): the product, its ingredients, Autocomplete.
                    AddHeader(GoF2ItemInfo.ItemName(editing).ToUpperInvariant());
                    var parts = db.Item(editing).blueprint;
                    for (int k = 0; k < parts.Count; k++) AddRow(new Row { kind = RowKind.Ingredient, item = parts[k].item, type = k });
                    AddRow(new Row { kind = RowKind.Autocomplete, item = editing });
                }
                else
                {
                    AddHeader(T(273));
                    foreach (var p in GoF2Blueprints.Products(db))
                        if (GoF2Blueprints.IsUnlocked(p.index)) AddRow(new Row { kind = RowKind.Blueprint, item = p.index });
                    if (GoF2Session.PendingProducts.Count > 0)
                    {
                        AddHeader(T(274));
                        for (int i = 0; i < GoF2Session.PendingProducts.Count; i++)
                            AddRow(new Row { kind = RowKind.Pending, item = GoF2Session.PendingProducts[i].item, equipment = i });
                    }
                }
            }
            else
            {
                AddHeader(T(183));
                AddRow(new Row { kind = RowKind.OwnShip, ship = GoF2Session.ShipIndex });
                for (int type = 0; type <= 3; type++)
                {
                    int slots = hangar.SlotCount(type);
                    var mounted = hangar.MountedOfType(type);
                    var cargo = GoF2Session.Cargo.Where(s => s.amount > 0 && hangar.TypeOf(s.item) == type).Select(s => s.item).ToList();
                    if (slots == 0 && mounted.Count == 0 && cargo.Count == 0) continue;
                    AddHeader(T(typeHeaders[type]));
                    foreach (int e in mounted) AddRow(new Row { kind = RowKind.Slot, equipment = e, item = GoF2Session.Equipment[e].item, type = type });
                    for (int n = mounted.Count; n < slots; n++) AddRow(new Row { kind = RowKind.Slot, type = type, equipment = -1 - n });
                    foreach (int i in cargo) AddRow(new Row { kind = RowKind.CargoItem, item = i, type = type });
                }
            }

            selected = rows.FirstOrDefault(r => r.Same(keep)) ?? rows.FirstOrDefault(r => r.Selectable);
            foreach (var r in rows) r.element.EnableInClassList("list-row--selected", r == selected);
            list.schedule.Execute(() => { list.scrollOffset = new Vector2(0f, scroll); ScrollToSelected(); });
            ShowDetails();
            UpdateFooter();
        }

        void AddHeader(string text)
        {
            var l = new Label(text) { pickingMode = PickingMode.Ignore };
            l.AddToClassList("list-header");
            l.AddToClassList("gof-semibold");
            list.Add(l);
            rows.Add(new Row { kind = RowKind.Header, element = l });
        }

        void AddRow(Row row)
        {
            var db = level.Database;
            var e = new VisualElement();
            e.AddToClassList("list-row");
            var icon = new VisualElement { pickingMode = PickingMode.Ignore };
            icon.AddToClassList("row-icon");
            var texts = new VisualElement { pickingMode = PickingMode.Ignore };
            texts.AddToClassList("row-texts");
            var name = new Label { pickingMode = PickingMode.Ignore };
            name.AddToClassList("row-name");
            var sub = new VisualElement { pickingMode = PickingMode.Ignore };
            sub.AddToClassList("row-sub");
            var subText = new Label { pickingMode = PickingMode.Ignore };
            subText.AddToClassList("row-sub-text");
            var price = new Label { pickingMode = PickingMode.Ignore };
            price.AddToClassList("row-price");
            price.AddToClassList("gof-semibold");

            Texture2D tex = null;
            switch (row.kind)
            {
                case RowKind.ShopItem:
                {
                    var it = db.Item(row.item);
                    tex = GoF2ItemInfo.ItemIcon(row.item);
                    name.text = GoF2ItemInfo.ItemName(row.item);
                    if (!GoF2Session.SeenItems.Contains(row.item)) sub.Add(Badge(GoF2Localization.Extra("shopNew", "NEW"), "row-badge--new"));
                    else if (hangar.IsMounted(row.item)) sub.Add(Badge(GoF2Localization.Extra("shopMounted", "MOUNTED"), "row-badge--mounted"));
                    subText.text = $"{GoF2ItemInfo.Category(it)}   {hangar.StockOf(row.item)} t  |  {hangar.CargoOf(row.item)} t";
                    int p = hangar.PriceOf(row.item);
                    price.text = GoF2ItemInfo.Credits(p);
                    price.EnableInClassList("row-price--expensive", p > GoF2Session.Credits);
                    break;
                }
                case RowKind.ShopShip:
                {
                    tex = GoF2ItemInfo.ShipIcon(row.ship);
                    name.text = GoF2ItemInfo.ShipName(row.ship);
                    int race = row.ship < GoF2Shop.ShipRace.Length ? GoF2Shop.ShipRace[row.ship] : 0;
                    subText.text = race <= 3 || race == 8 ? GoF2Localization.Get(406 + race) : "";
                    int delta = hangar.ShipPrice(row.ship) - hangar.ShipPrice(GoF2Session.ShipIndex);   // trade-in difference
                    price.text = GoF2ItemInfo.Credits(delta);
                    price.EnableInClassList("row-price--expensive", delta > GoF2Session.Credits);
                    break;
                }
                case RowKind.OwnShip:
                {
                    var s = db.Ship(row.ship);
                    tex = GoF2ItemInfo.ShipIcon(row.ship);
                    name.text = GoF2ItemInfo.ShipName(row.ship);
                    subText.text = s != null ? $"{GoF2Localization.Get(165)} {s.armor}   {GoF2Localization.Get(166)} {hangar.Load} / {hangar.MaxLoad} t" : "";
                    break;
                }
                case RowKind.Slot when row.equipment >= 0:
                {
                    var stack = GoF2Session.Equipment[row.equipment];
                    tex = GoF2ItemInfo.ItemIcon(stack.item);
                    name.text = GoF2ItemInfo.ItemName(stack.item) + (stack.amount > 1 ? $" ({stack.amount})" : "");
                    subText.text = GoF2ItemInfo.Category(db.Item(stack.item));
                    sub.Insert(0, Badge(GoF2Localization.Extra("shopMounted", "MOUNTED"), "row-badge--mounted"));
                    break;
                }
                case RowKind.Slot:
                    name.text = GoF2Localization.Extra("shopEmptySlot", "Empty slot");
                    name.AddToClassList("row-name--empty");
                    break;
                case RowKind.CargoItem:
                {
                    tex = GoF2ItemInfo.ItemIcon(row.item);
                    int n = hangar.CargoOf(row.item);
                    name.text = GoF2ItemInfo.ItemName(row.item) + (n > 1 ? $" ({n})" : "");
                    subText.text = GoF2Localization.Get(284);   // Available in cargo
                    break;
                }
                case RowKind.Blueprint:
                {
                    tex = GoF2ItemInfo.ItemIcon(row.item);
                    name.text = GoF2ItemInfo.ItemName(row.item);
                    var st = GoF2Blueprints.State(db, row.item);
                    float rate = GoF2Blueprints.CompletionRate(db, st);
                    if (rate > 0f)
                    {
                        string where = st.station >= 0 ? $"  ({db.Stations.Find(s => s.index == st.station)?.name})" : "";
                        subText.text = $"{(int)(rate * 100f)}%{where}";
                        var bar = new VisualElement { pickingMode = PickingMode.Ignore };
                        bar.AddToClassList("bp-bar");
                        var fill = new VisualElement { pickingMode = PickingMode.Ignore };
                        fill.AddToClassList("bp-bar-fill");
                        fill.style.width = Length.Percent(rate * 100f);
                        bar.Add(fill);
                        texts.Add(bar);
                    }
                    else subText.text = GoF2ItemInfo.Category(db.Item(row.item));
                    name.EnableInClassList("row-name--helps", GoF2Blueprints.CargoHelps(db, st));
                    break;
                }
                case RowKind.Pending:
                {
                    var pp = GoF2Session.PendingProducts[row.equipment];
                    tex = GoF2ItemInfo.ItemIcon(pp.item);
                    name.text = (pp.quantity >= 2 ? $"{pp.quantity}x " : "") + GoF2ItemInfo.ItemName(pp.item);
                    subText.text = $"{GoF2Localization.Get(275)} {db.Stations.Find(s => s.index == pp.station)?.name}";
                    break;
                }
                case RowKind.Ingredient:
                {
                    tex = GoF2ItemInfo.ItemIcon(row.item);
                    name.text = GoF2ItemInfo.ItemName(row.item);
                    var st = GoF2Blueprints.State(db, editing);
                    int total = GoF2Blueprints.Total(db, editing, row.type);
                    int invested = GoF2Blueprints.Invested(db, st, row.type) + Pending(row.item);
                    subText.text = $"{GoF2Localization.Get(183)} {hangar.CargoOf(row.item)} t   |   {GoF2Localization.Get(271)} {invested} / {total} t";
                    if (invested >= total) sub.Insert(0, Badge("✓", "row-badge--mounted"));
                    break;
                }
                case RowKind.Autocomplete:
                    name.text = GoF2Localization.Extra("bpAutocomplete", "Autocomplete");   // a hard-coded English label in the original
                    subText.text = GoF2ItemInfo.ItemName(row.item);
                    price.text = GoF2ItemInfo.Credits(GoF2Blueprints.AutoCompletePrice(db, row.item));
                    price.EnableInClassList("row-price--expensive", GoF2Blueprints.AutoCompletePrice(db, row.item) > GoF2Session.Credits);
                    break;
            }
            if (tex != null) icon.style.backgroundImage = new StyleBackground(tex);
            sub.Add(subText);
            texts.Add(name);
            texts.Add(sub);
            e.Add(icon);
            e.Add(texts);
            if (price.text.Length > 0) e.Add(price);
            e.RegisterCallback<ClickEvent>(_ => Select(row, true));
            row.element = e;
            list.Add(e);
            rows.Add(row);
        }

        static Label Badge(string text, string cls)
        {
            var b = new Label(text) { pickingMode = PickingMode.Ignore };
            b.AddToClassList("row-badge");
            b.AddToClassList(cls);
            b.AddToClassList("gof-semibold");
            return b;
        }

        void Select(Row row, bool sound)
        {
            if (row == null || !row.Selectable || row == selected) return;
            if (HasPending) { Commit(() => Select(row, sound)); return; }   // leaving an ingredient commits it
            if (sound) menu.PlayPush();
            ReleaseArrow();
            selected = row;
            foreach (var r in rows) r.element.EnableInClassList("list-row--selected", r == selected);
            if (AutoEquip()) return;   // rebuilt
            ScrollToSelected();
            ShowDetails();
        }

        public void MoveSelection(int dir)
        {
            if (rows.Count == 0) return;
            int i = selected != null ? rows.IndexOf(selected) : -1;
            for (int n = i + dir; n >= 0 && n < rows.Count; n += dir)
                if (rows[n].Selectable) { Select(rows[n], true); return; }
        }

        void ScrollToSelected()
        {
            if (selected?.element != null && selected.element.panel != null && !float.IsNaN(selected.element.layout.height)) list.ScrollTo(selected.element);
        }

        /// <summary>autoEquipSecondaryWeapons, when the selection moves on: missiles bought for a mounted launcher join it.</summary>
        bool AutoEquip()
        {
            if (hangar == null) return false;
            var moved = hangar.AutoEquipSecondaries();
            if (moved.Count == 0) return false;
            menu.ShowToast(GoF2Localization.Get(208).Replace("#N", GoF2ItemInfo.ItemName(moved[0])));
            Rebuild();
            return true;
        }

        // ---- details -----------------------------------------------------------------------------------------

        void ShowDetails()
        {
            var db = level.Database;
            detailStats.Clear();
            detailText.text = "";
            details.style.visibility = selected == null ? Visibility.Hidden : Visibility.Visible;
            tradeBox.AddToClassList("trade-box--hidden");
            actionButton.AddToClassList("detail-action--hidden");
            actionButton.RemoveFromClassList("detail-action--disabled");
            if (selected == null) return;
            string T(int id) => GoF2Localization.Get(id);

            int item = selected.kind == RowKind.Slot && selected.equipment >= 0 ? GoF2Session.Equipment[selected.equipment].item : selected.item;
            if (item >= 0 && tab == Tab.Blueprints)
            {
                ShowBlueprintDetails(item);
                return;
            }
            if (item >= 0)
            {
                var it = db.Item(item);
                detailIcon.style.backgroundImage = new StyleBackground(GoF2ItemInfo.ItemIcon(item));
                detailName.text = GoF2ItemInfo.ItemName(item);
                detailSub.text = $"{GoF2ItemInfo.Category(it)}  ·  {T(133)} {it.techLevel}";
                foreach (var (label, value) in GoF2ItemInfo.ItemStats(it)) AddStat(label, value);
                detailText.text = GoF2ItemInfo.ItemText(db, it, hangar.SystemIndex);

                if (selected.kind == RowKind.ShopItem)
                {
                    tradeBox.RemoveFromClassList("trade-box--hidden");
                    tradeStockLabel.text = T(136).ToUpperInvariant();
                    tradeCargoLabel.text = T(183).ToUpperInvariant();
                    sellLabel.text = "‹ " + GoF2Localization.Extra("shopSell", "SELL");
                    buyLabel.text = GoF2Localization.Extra("shopBuy", "BUY") + " ›";
                    int stock = hangar.StockOf(item), cargo = hangar.CargoOf(item), price = hangar.PriceOf(item);
                    tradeStock.text = $"{stock} t";
                    tradeCargo.text = $"{cargo} t";
                    tradePrice.text = GoF2ItemInfo.Credits(price);
                    tradePrice.EnableInClassList("trade-price--expensive", price > GoF2Session.Credits);
                    sellButton.EnableInClassList("trade-arrow--disabled", cargo <= 0);
                    buyButton.EnableInClassList("trade-arrow--disabled", stock <= 0);
                }
                else if (selected.kind == RowKind.Slot)
                    ShowAction(T(282).ToUpperInvariant(), true);
                else if (selected.kind == RowKind.CargoItem)
                {
                    var r = hangar.CanMount(item, out _);
                    ShowAction(T(281).ToUpperInvariant(), r == GoF2Hangar.Result.Ok || r == GoF2Hangar.Result.Swap);
                }
            }
            else if (selected.ship >= 0)
            {
                var s = db.Ship(selected.ship);
                detailIcon.style.backgroundImage = new StyleBackground(GoF2ItemInfo.ShipIcon(selected.ship));
                detailName.text = GoF2ItemInfo.ShipName(selected.ship);
                int race = selected.ship < GoF2Shop.ShipRace.Length ? GoF2Shop.ShipRace[selected.ship] : 0;
                detailSub.text = race <= 3 || race == 8 ? T(406 + race) : "";
                if (s != null) foreach (var (label, value) in GoF2ItemInfo.ShipStats(s, hangar.ShipPrice(selected.ship))) AddStat(label, value);
                detailText.text = T(977 + selected.ship);
                if (selected.kind == RowKind.ShopShip)
                {
                    int delta = hangar.ShipPrice(selected.ship) - hangar.ShipPrice(GoF2Session.ShipIndex);
                    ShowAction($"{T(301).ToUpperInvariant()}   {GoF2ItemInfo.Credits(delta)}", true);
                }
            }
            else
            {
                // Empty slot.
                detailIcon.style.backgroundImage = StyleKeyword.None;
                detailName.text = GoF2Localization.Extra("shopEmptySlot", "Empty slot");
                detailSub.text = T(new[] { 265, 266, 267, 269 }[Mathf.Clamp(selected.type, 0, 3)]);
            }
            detailScroll.scrollOffset = Vector2.zero;
            if (selected.item >= 0) GoF2Session.SeenItems.Add(selected.item);   // the original marks inspected items
        }

        void ShowBlueprintDetails(int item)
        {
            var db = level.Database;
            string T(int id) => GoF2Localization.Get(id);
            var it = db.Item(item);
            detailIcon.style.backgroundImage = new StyleBackground(GoF2ItemInfo.ItemIcon(item));
            detailName.text = GoF2ItemInfo.ItemName(item);
            detailSub.text = $"{GoF2ItemInfo.Category(it)}  ·  {T(133)} {it.techLevel}";
            foreach (var (label, value) in GoF2ItemInfo.ItemStats(it)) AddStat(label, value);
            detailText.text = GoF2ItemInfo.ItemText(db, it, hangar.SystemIndex);
            switch (selected.kind)
            {
                case RowKind.Blueprint:
                    ShowAction(T(283).ToUpperInvariant(), true);   // Edit
                    break;
                case RowKind.Autocomplete:
                    ShowAction($"{GoF2Localization.Extra("bpAutocomplete", "Autocomplete").ToUpperInvariant()}   {GoF2ItemInfo.Credits(GoF2Blueprints.AutoCompletePrice(db, editing))}", true);
                    break;
                case RowKind.Ingredient:
                {
                    // Trade mode: the hold (183 "Ship") on the left, the blueprint (271) on the right; right arrow = add.
                    var st = GoF2Blueprints.State(db, editing);
                    int total = GoF2Blueprints.Total(db, editing, selected.type);
                    int invested = GoF2Blueprints.Invested(db, st, selected.type) + Pending(item);
                    int cargo = hangar.CargoOf(item);
                    tradeBox.RemoveFromClassList("trade-box--hidden");
                    tradeStockLabel.text = T(183).ToUpperInvariant();
                    tradeCargoLabel.text = T(271).ToUpperInvariant();
                    sellLabel.text = "‹";
                    buyLabel.text = GoF2Localization.Extra("bpAdd", "ADD") + " ›";
                    tradeStock.text = $"{cargo} t";
                    tradeCargo.text = $"{invested} / {total} t";
                    tradePrice.text = "";
                    sellButton.EnableInClassList("trade-arrow--disabled", true);   // invested goods can't be taken back
                    buyButton.EnableInClassList("trade-arrow--disabled", cargo <= 0 || invested >= total);
                    break;
                }
            }
            detailScroll.scrollOffset = Vector2.zero;
        }

        int Pending(int ingredient) => pendingUnits.TryGetValue(ingredient, out int n) ? n : 0;
        bool HasPending { get { foreach (var kv in pendingUnits) if (kv.Value > 0) return true; return false; } }
        int StationIndex => level.Station != null ? level.Station.index : GoF2Session.StationIndex;

        /// <summary>Item::transactionBlueprint: one unit from the hold into the blueprint (not committed yet).</summary>
        void AddIngredient(int units)
        {
            var db = level.Database;
            int item = selected.item;
            var st = GoF2Blueprints.State(db, editing);
            if (GoF2Blueprints.IsEmpty(st) && !startConfirmed && !HasPending)
            {
                ReleaseArrow();
                if (!GoF2Blueprints.CanStartIn(db, editing, StationIndex)) { menu.ShowToast(GoF2Localization.Get(528)); return; }
                menu.ShowDialog(GoF2Localization.Get(212), () => { startConfirmed = true; AddIngredient(1); });   // Start production here?
                return;
            }
            int moved = 0;
            for (int n = 0; n < units; n++)
            {
                int left = st.remaining[selected.type] - Pending(item);
                if (left <= 0 || hangar.CargoOf(item) <= 0) break;
                GoF2Shop.RemoveFromCargo(item, 1);
                pendingUnits[item] = Pending(item) + 1;
                moved++;
            }
            if (moved == 0) { ReleaseArrow(); return; }
            menu.PlayClip(menu.shopSell);
            Rebuild();
        }

        /// <summary>setSellMode(false): the pending units go into the blueprint; at another station than the production
        /// station for 200 $ per unit (288), volatile goods never (289); a completed run is produced.</summary>
        void Commit(System.Action after)
        {
            var db = level.Database;
            if (!HasPending || editing < 0) { pendingUnits.Clear(); after?.Invoke(); return; }
            var st = GoF2Blueprints.State(db, editing);
            int units = 0; bool volatileGoods = false;
            foreach (var kv in pendingUnits) { units += kv.Value; if (kv.Value > 0 && GoF2Blueprints.IsVolatile(kv.Key)) volatileGoods = true; }
            bool elsewhere = !GoF2Blueprints.IsEmpty(st) && st.station >= 0 && st.station != StationIndex;
            if (elsewhere && volatileGoods)
            {
                Revert();
                menu.ShowDialog(GoF2Localization.Get(289), null, true);
                return;
            }
            if (elsewhere)
            {
                int cost = GoF2Blueprints.ShippingPerUnit * units;
                string where = db.Stations.Find(s => s.index == st.station)?.name ?? "";
                menu.ShowDialog(GoF2Localization.Get(288).Replace("#S", where).Replace("#C", GoF2ItemInfo.Credits(cost)), () =>
                {
                    if (cost > GoF2Session.Credits)
                    {
                        int need = cost - GoF2Session.Credits;
                        Revert();
                        menu.ShowToast(GoF2Localization.Get(203).Replace("#C", GoF2ItemInfo.Credits(need)));
                        return;
                    }
                    GoF2Session.Credits -= cost;
                    Apply();
                    after?.Invoke();
                });
                // "No" reverts: the dialog's No only closes it, so revert now and re-apply on Yes.
                pendingSnapshot = new Dictionary<int, int>(pendingUnits);
                Revert();
                return;
            }
            Apply();
            after?.Invoke();
        }

        Dictionary<int, int> pendingSnapshot;

        void Apply()
        {
            var db = level.Database;
            var units = pendingSnapshot ?? pendingUnits;
            if (pendingSnapshot != null)
                foreach (var kv in pendingSnapshot) GoF2Shop.RemoveFromCargo(kv.Key, kv.Value);   // taken back out of the hold
            foreach (var kv in units) GoF2Blueprints.Invest(db, editing, kv.Key, kv.Value, StationIndex);
            pendingUnits.Clear();
            pendingSnapshot = null;
            startConfirmed = false;
            if (GoF2Blueprints.IsCompleted(GoF2Blueprints.State(db, editing))) Finish();
            else Rebuild();
        }

        void Revert()
        {
            foreach (var kv in pendingUnits) GoF2Shop.AddToCargo(kv.Key, kv.Value);
            pendingUnits.Clear();
            startConfirmed = false;
            Rebuild();
        }

        /// <summary>A completed run: 211 to the hold (then the Shop tab) or 210 waiting at the production station.</summary>
        void Finish()
        {
            var db = level.Database;
            int product = editing;
            int station = GoF2Blueprints.State(db, product).station;
            bool here = GoF2Blueprints.Produce(db, product, StationIndex);
            hangar = new GoF2Hangar(db, level.Stock);   // the new product needs its price
            string name = GoF2ItemInfo.ItemName(product);
            if (here)
            {
                menu.ShowDialog(GoF2Localization.Get(211).Replace("#N", name), null, true);
                editing = -1;
                SetTab(Tab.Shop);
            }
            else
            {
                string where = db.Stations.Find(s => s.index == station)?.name ?? "";
                menu.ShowDialog(GoF2Localization.Get(210).Replace("#N", name).Replace("#S", where), null, true);
                editing = -1;
                selected = null;
                Rebuild();
            }
        }

        /// <summary>Autocomplete (button 23): 195 "Autocomplete blueprint for #C?"; an empty blueprint takes this station.</summary>
        void AskAutocomplete()
        {
            var db = level.Database;
            int price = GoF2Blueprints.AutoCompletePrice(db, editing);
            if (price > GoF2Session.Credits) { menu.ShowToast(GoF2Localization.Get(203).Replace("#C", GoF2ItemInfo.Credits(price - GoF2Session.Credits))); return; }
            if (!GoF2Blueprints.CanStartIn(db, editing, StationIndex) && GoF2Blueprints.IsEmpty(GoF2Blueprints.State(db, editing)))
            { menu.ShowToast(GoF2Localization.Get(528)); return; }
            menu.ShowDialog(GoF2Localization.Get(195).Replace("#C", GoF2ItemInfo.Credits(price)), () =>
            {
                Revert();
                var st = GoF2Blueprints.State(db, editing);
                if (GoF2Blueprints.IsEmpty(st) || st.station < 0) st.station = StationIndex;
                for (int k = 0; k < st.remaining.Count; k++) st.remaining[k] = 0;   // BluePrint::complete
                GoF2Session.Credits -= price;
                Finish();
            });
        }

        void ShowAction(string text, bool enabled)
        {
            actionButton.text = text;
            actionButton.RemoveFromClassList("detail-action--hidden");
            actionButton.EnableInClassList("detail-action--disabled", !enabled);
        }

        void AddStat(string label, string value)
        {
            var row = new VisualElement { pickingMode = PickingMode.Ignore };
            row.AddToClassList("stat-row");
            var l = new Label(label) { pickingMode = PickingMode.Ignore };
            l.AddToClassList("stat-label");
            var v = new Label(value) { pickingMode = PickingMode.Ignore };
            v.AddToClassList("stat-value");
            v.AddToClassList("gof-semibold");
            row.Add(l);
            row.Add(v);
            detailStats.Add(row);
        }

        void UpdateFooter()
        {
            cargoLabel.text = $"{GoF2Localization.Get(184).ToUpperInvariant()}  {hangar.Load} / {hangar.MaxLoad} t";
            cargoLabel.EnableInClassList("footer-cargo--over", hangar.Overloaded);
            creditsLabel.text = GoF2ItemInfo.Credits(GoF2Session.Credits);
        }

        // ---- actions -----------------------------------------------------------------------------------------

        /// <summary>Left / right: sell / buy one unit of the selected shop item (Item::transaction).</summary>
        public void Trade(int direction, bool sound = true, int units = 1)
        {
            if (selected != null && selected.kind == RowKind.Ingredient)
            {
                if (direction > 0) AddIngredient(units); else ReleaseArrow();
                return;
            }
            if (selected == null || selected.kind != RowKind.ShopItem) return;
            bool changed = false;
            for (int n = 0; n < units; n++)
            {
                if (direction > 0)
                {
                    var r = hangar.Buy(selected.item, out int need);
                    if (r == GoF2Hangar.Result.NoCredits)
                    {
                        menu.ShowToast(GoF2Localization.Get(203).Replace("#C", GoF2ItemInfo.Credits(need)));
                        ReleaseArrow();
                        break;
                    }
                    if (r != GoF2Hangar.Result.Ok) { ReleaseArrow(); break; }
                }
                else
                {
                    var r = hangar.Sell(selected.item);
                    if (r == GoF2Hangar.Result.NotSaleable) menu.ShowToast(GoF2Localization.Get(323));
                    if (r != GoF2Hangar.Result.Ok) { ReleaseArrow(); break; }
                }
                changed = true;
            }
            if (!changed) return;
            if (sound) menu.PlayClip(direction > 0 ? menu.shopBuy : menu.shopSell);
            Rebuild();
        }

        /// <summary>Enter / A / the action button: mount, demount or buy the selected ship.</summary>
        public void Action()
        {
            if (selected == null) return;
            var db = level.Database;
            switch (selected.kind)
            {
                case RowKind.Blueprint:
                    // Edit (283) -> tab 4, the ingredients.
                    menu.PlayRelease();
                    editing = selected.item;
                    pendingUnits.Clear();
                    startConfirmed = false;
                    selected = null;
                    Rebuild();
                    break;
                case RowKind.Autocomplete:
                    AskAutocomplete();
                    break;
                case RowKind.Slot when selected.equipment >= 0:
                {
                    int item = GoF2Session.Equipment[selected.equipment].item;
                    if (!GoF2Hangar.IsSaleable(item)) { menu.ShowToast(GoF2Localization.Get(323)); break; }
                    hangar.Demount(selected.equipment);
                    menu.PlayClip(menu.shopDemount);
                    menu.ShowToast(GoF2Localization.Get(209).Replace("#N", GoF2ItemInfo.ItemName(item)));
                    selected = null;
                    Rebuild();
                    break;
                }
                case RowKind.CargoItem:
                {
                    int item = selected.item;
                    var r = hangar.CanMount(item, out int swapWith);
                    if (r == GoF2Hangar.Result.Swap)
                    {
                        string text = GoF2Localization.Get(287).Replace("#ITEM1", GoF2ItemInfo.ItemName(GoF2Session.Equipment[swapWith].item))
                                                               .Replace("#ITEM2", GoF2ItemInfo.ItemName(item));
                        menu.ShowDialog(text, () =>
                        {
                            if (!hangar.Swap(swapWith, item)) return;
                            menu.PlayClip(menu.shopMount);
                            selected = null;
                            Rebuild();
                        });
                    }
                    else if (r == GoF2Hangar.Result.Ok && hangar.Mount(item))
                    {
                        menu.PlayClip(menu.shopMount);
                        menu.ShowToast(GoF2Localization.Get(208).Replace("#N", GoF2ItemInfo.ItemName(item)));
                        selected = null;
                        Rebuild();
                    }
                    break;
                }
                case RowKind.ShopShip:
                {
                    int ship = selected.ship;
                    var r = hangar.CanBuyShip(ship, out int need);
                    if (r == GoF2Hangar.Result.SameShip) { menu.ShowToast(GoF2Localization.Get(329)); break; }
                    if (r == GoF2Hangar.Result.NoCredits) { menu.ShowToast(GoF2Localization.Get(203).Replace("#C", GoF2ItemInfo.Credits(need))); break; }
                    menu.ShowDialog(GoF2Localization.Get(304), () =>
                    {
                        if (!hangar.BuyShip(ship)) return;
                        level.ReplacePlayerShip(ship);
                        menu.ShowToast(GoF2Localization.Get(303).Replace("#N", db.Ship(ship)?.name ?? GoF2ItemInfo.ShipName(ship)));
                        selected = null;
                        Rebuild();
                    });
                    break;
                }
            }
        }

        // ---- held trade arrows ---------------------------------------------------------------------------------

        void HookArrow(VisualElement arrow, int direction)
        {
            arrow.RegisterCallback<PointerDownEvent>(e =>
            {
                if (heldPointer >= 0 || arrow.ClassListContains("trade-arrow--disabled")) return;
                heldPointer = e.pointerId;
                heldDirection = direction;
                heldMs = repeatMs = 0f;
                arrow.CapturePointer(e.pointerId);
                arrow.AddToClassList("trade-arrow--pressed");
                Trade(direction);
                e.StopPropagation();
            });
            arrow.RegisterCallback<PointerUpEvent>(e => { if (e.pointerId == heldPointer) ReleaseArrow(); });
            arrow.RegisterCallback<PointerCancelEvent>(e => { if (e.pointerId == heldPointer) ReleaseArrow(); });
        }

        void ReleaseArrow()
        {
            if (heldPointer >= 0)
            {
                if (sellButton.HasPointerCapture(heldPointer)) sellButton.ReleasePointer(heldPointer);
                if (buyButton.HasPointerCapture(heldPointer)) buyButton.ReleasePointer(heldPointer);
            }
            heldPointer = -1;
            heldDirection = 0;
            sellButton.RemoveFromClassList("trade-arrow--pressed");
            buyButton.RemoveFromClassList("trade-arrow--pressed");
        }

        /// <summary>Keyboard / controller: the held vertical (select) and horizontal (sell / buy) direction, every frame.</summary>
        public void HoldDirections(int vertical, int horizontal, float dtMs)
        {
            if (!IsOpen) return;
            if (vertical != moveDirection)
            {
                moveDirection = vertical;
                moveMs = -350f;
                if (vertical != 0) MoveSelection(vertical);
            }
            else if (vertical != 0 && (moveMs += dtMs) >= 80f)
            {
                moveMs = 0f;
                MoveSelection(vertical);
            }

            // A new press starts a hold (repeated in Update); a failed trade ends it until the key is pressed again.
            if (horizontal == keyDirection) return;
            keyDirection = horizontal;
            if (heldPointer == KeyHold) ReleaseArrow();
            if (horizontal == 0 || heldPointer >= 0) return;   // released, or a finger / the mouse holds an arrow
            heldPointer = KeyHold;
            heldDirection = horizontal;
            heldMs = repeatMs = 0f;
            (horizontal < 0 ? sellButton : buyButton).AddToClassList("trade-arrow--pressed");
            Trade(horizontal);
        }

        /// <summary>HangarWindow::update: repeat after 200 ms, every 30 ms once held 1.5 s, 5 units per repeat after 4 s.</summary>
        public void Update(float dtMs)
        {
            if (!IsOpen || heldDirection == 0) return;
            heldMs += dtMs;
            repeatMs += dtMs;
            float interval = heldMs > 1500f ? 30f : 200f;
            if (repeatMs < interval) return;
            repeatMs = 0f;
            Trade(heldDirection, false, heldMs > 4000f ? 5 : 1);
        }
    }
}
