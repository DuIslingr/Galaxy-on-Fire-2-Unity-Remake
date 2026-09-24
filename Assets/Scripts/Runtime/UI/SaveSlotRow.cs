// SaveSlotRow.cs
// One save slot row (MenuTouchWindow::drawLoadSaveMenu 0x14bfbc), shared by the main menu's Load list and the station
// menu's Save game list: index, "Auto-save" (486) / "Slot N", the preview (RecordHandler::recordStoreWritePreview:
// station, system, ship, credits, playing time) or "-BLANK-" (174). Styles: .slot-* in GoF2Common.uss.

using GoF2Remake.Data;
using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    public static class SaveSlotRow
    {
        public static Button Build(Database db, int slot, SaveData save, string emptyAutoSaveHint)
        {
            var row = new Button { focusable = true };
            row.AddToClassList("slot-row");
            row.EnableInClassList("slot-row--empty", save == null);

            var index = new Label(slot.ToString("00"));
            index.AddToClassList("slot-index");
            index.AddToClassList("gof-semibold");
            var info = new VisualElement();
            info.AddToClassList("slot-info");
            var name = new Label(slot == SaveGame.AutoSaveSlot ? Localization.Get(486) : $"{Localization.Extra("slot", "Slot")} {slot}");
            name.AddToClassList("slot-name");
            info.Add(name);

            string subText = null;
            if (save != null)
            {
                var st = db.Stations.Find(x => x.index == save.station);
                var ship = db.Ship(save.ship);
                subText = $"{st?.name} · {st?.systemName}  ·  {ship?.name}";
            }
            else if (slot == SaveGame.AutoSaveSlot) subText = emptyAutoSaveHint;
            if (subText != null)
            {
                var sub = new Label(subText);
                sub.AddToClassList("slot-sub");
                info.Add(sub);
            }
            var state = new Label(save == null ? Localization.Get(174)   // -BLANK-
                : $"{save.credits:N0} Cr  ·  {(int)(save.playSeconds / 3600)}:{(int)(save.playSeconds / 60) % 60:00} h");
            state.AddToClassList("slot-state");

            foreach (var e in new VisualElement[] { index, info, state }) e.pickingMode = PickingMode.Ignore;
            row.Add(index);
            row.Add(info);
            row.Add(state);
            return row;
        }
    }
}
