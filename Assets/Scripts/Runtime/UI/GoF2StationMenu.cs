// GoF2StationMenu.cs
// The docked-station screen (ModStation::OnRender2D 0xef208) over GoF2StationLevel's hangar / Space Lounge:
//   header "<station> Station" (136), left panel with "<system> System" (137), "Tech level: N" (133), the race (406+),
//   the screen buttons Hangar (167: opens the shop window, GoF2HangarWindow, over the 3D hangar), Space Lounge (398) and
//   Map (177: the star map, GoF2StarMap; refused with an overloaded hold, 204; picking a station leaves at once with it as
//   the programmed destination, StarMap::depart),
//   and the launch button bottom-right with the confirmation "Depart the station?" (397, ChoiceWindow, default = Yes);
//   launching with more cargo than the hold takes is refused (204, ModStation::leaveStation 0xec1ec).
// Dragging over the hangar turns the player's ship (1 rad per 120 px of a 480 px high screen, with a fling);
// a tap in the lounge skips its camera intro. Adapts to GoF2InputMode like the flight HUD:
//   Touch:      buttons, drag to turn the ship, Menu button.
//   Keyboard:   keycap hints; A/D or arrows turn the ship, 1 hangar, 2 lounge, M map, L launch, Esc back.
//   Controller: Xbox hints; right stick turns the ship, LB hangar / RB lounge, Y map, X launch, B back, Menu to the main menu.
//   In the hangar window: up / down select, left / right sell / buy, Enter / A confirm, Q / E or LB / RB switch tabs.
// Esc / B: dialog -> no, hangar window / lounge -> main view, main view -> the system menu.
// System menu (MenuTouchWindow, "Menu" 172; the Menu button, Esc on the main view, controller Menu): Save game (30) with the
// slot list (slot 0 "This slot is reserved for the auto-save game." 487; a used slot asks "Are you sure you want to
// overwrite this game?" 49; then "Game saved." 50, MenuTouchWindow::saveGame 0x14bcf8), Back to Main Menu (522, confirm
// "Are you sure? Your progress won't be saved." 523). The original's Options / Help entries are in the main menu here.
// Story (ModStation::OnUpdate 0xed2a8 / OnTouchEnd 0xea4ec, campaign_flow.md 3.1): while no window is open, a completed
// campaign mission (GoF2Story.IsComplete, docked; the lounge types need the lounge with its intro over) opens its
// success conversation (GoF2DialogueView); closing it advances the story, then by the new index: reload the station
// (9, 44, 75, 76, 83), launch into a story orbit (78, 89, 99, 109, 119, 133, 144, 160) or credit the reward. The menu
// buttons unlock with the story: Hangar from 5, Map from 9, Space Lounge from 12.
// Not yet (the original's other buttons): Missions, Status; the ending after index 43 (credits) is a plain advance.

using GoF2Remake.Data;
using GoF2Remake.World;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.SceneManagement;
using UnityEngine.UIElements;
using PointerType = UnityEngine.UIElements.PointerType;

namespace GoF2Remake.UI
{
    [RequireComponent(typeof(PanelRenderer))]
    public class GoF2StationMenu : MonoBehaviour
    {
        public GoF2StationLevel level;
        public string menuScene = "MainMenu";
        [Header("Audio (FMOD events 124 / 123 / 126)")]
        public AudioSource sfxSource;
        public AudioClip buttonPush;
        public AudioClip buttonRelease;
        public AudioClip infoSound;
        [Header("Hangar sounds (FMOD events 0x65 / 0x64 / 0x62 / 0x60)")]
        public AudioClip shopBuy;
        public AudioClip shopSell;
        public AudioClip shopMount;
        public AudioClip shopDemount;
        [Header("Text (used when the scene is started without the main menu)")]
        public string[] languageCodes;
        public TextAsset[] languageTables;
        [Header("Turning the ship")]
        [Tooltip("Keyboard / controller turn speed, game radians per second.")]
        public float keyTurnSpeed = 1.6f;

        PanelRenderer panelRenderer;
        PanelSettings runtimePanel;
        VisualElement root, safeArea, dragZone, hints, dialog;
        Button hangarButton, loungeButton, mapButton, launchButton, dialogYes, dialogNo;
        VisualElement systemMenu, systemMain, systemSave;
        ScrollView saveSlotList;
        Button saveGameButton, mainMenuButton, systemClose, saveBack;
        int lastSavedSlot = -1;
        GoF2DialogueView storyDialogue;
        AudioSource voiceSource;
        Label viewTitle, toast;
        GoF2HangarWindow hangarWindow;
        System.Action dialogAction;
        float toastMs;
        Vector2Int lastScreen;
        Rect lastSafeArea;
        bool touchMode;

        int dragPointer = -1;
        float dragLastX, dragLastTime, dragVelocity;   // velocity in game rad/s, sampled per frame
        float dragFrameRadians;                         // turned since the last frame (touch can send several moves per frame)
        const float MaxFling = 25f;                     // rad/s

        void OnEnable()
        {
            panelRenderer = GetComponent<PanelRenderer>();
            panelRenderer.RegisterUIReloadCallback(OnUIReload);
            if (runtimePanel == null && panelRenderer.panelSettings != null)
            {
                runtimePanel = Instantiate(panelRenderer.panelSettings);
                panelRenderer.panelSettings = runtimePanel;
            }
            GoF2InputMode.Changed += ApplyInputMode;
            if (level != null) level.ViewChanged += OnViewChanged;
        }

        void OnDisable()
        {
            panelRenderer?.UnregisterUIReloadCallback(OnUIReload);
            GoF2InputMode.Changed -= ApplyInputMode;
            if (level != null) level.ViewChanged -= OnViewChanged;
        }

        void OnUIReload(PanelRenderer renderer, VisualElement rootElement, int version)
        {
            // The first load can come before GoF2StationLevel.Awake has built the station: try again next frame.
            if (level != null && level.Layout == null)
            {
                rootElement.schedule.Execute(() => OnUIReload(renderer, rootElement, version)).ExecuteLater(1);
                return;
            }
            if (!GoF2Localization.IsLoaded && languageTables != null && languageTables.Length > 0)
            {
                int i = languageCodes != null ? System.Array.IndexOf(languageCodes, GoF2Settings.Language) : -1;
                if (i < 0) i = 0;
                GoF2Localization.Load(languageCodes != null && i < languageCodes.Length ? languageCodes[i] : "en", languageTables[i]);
            }
            root = rootElement;
            root.style.flexGrow = 1;
            root.pickingMode = PickingMode.Ignore;
            safeArea = root.Q("safeArea");
            dragZone = root.Q("dragZone");
            hints = root.Q("hints");
            dialog = root.Q("dialog");
            viewTitle = root.Q<Label>("viewTitle");
            toast = root.Q<Label>("toast");
            hangarButton = Bind("hangarButton", OpenHangar);
            loungeButton = Bind("loungeButton", OpenLounge);
            mapButton = Bind("mapButton", OpenMap);
            launchButton = Bind("launchButton", AskLaunch);
            dialogYes = Bind("dialogYes", () => { var a = dialogAction; CloseDialog(); a?.Invoke(); });
            dialogNo = Bind("dialogNo", CloseDialog);
            hangarWindow = new GoF2HangarWindow(this, level, root);
            root.Q("storyDialogue").pickingMode = PickingMode.Ignore;
            if (voiceSource == null)
            {
                voiceSource = gameObject.AddComponent<AudioSource>();
                voiceSource.playOnAwake = false;
                voiceSource.spatialBlend = 0f;
            }
            storyDialogue = new GoF2DialogueView(root, voiceSource) { ButtonSound = push => Play(push ? buttonPush : buttonRelease) };
            Bind("menuButton", OpenSystemMenu);
            systemMenu = root.Q("systemMenu");
            systemMain = root.Q("systemMenuMain");
            systemSave = root.Q("systemMenuSave");
            saveSlotList = root.Q<ScrollView>("saveSlotList");
            saveSlotList.mode = ScrollViewMode.Vertical;
            saveSlotList.verticalScrollerVisibility = ScrollerVisibility.Hidden;   // drag / wheel / focus scrolling instead
            saveSlotList.horizontalScrollerVisibility = ScrollerVisibility.Hidden;
            new GoF2DragScroll(saveSlotList);
            saveGameButton = Bind("saveGameButton", () => ShowSystemPage(true));
            mainMenuButton = Bind("mainMenuButton", () => ShowDialog(GoF2Localization.Get(523), BackToMenu));
            systemClose = Bind("systemMenuClose", CloseSystemMenu);
            saveBack = Bind("saveBack", () => ShowSystemPage(false));

            var st = level != null ? level.Station : null;
            string T(int id) => GoF2Localization.Get(id);
            root.Q<Label>("stationTitle").text = st == null ? "" :
                (st.index == 101 ? st.name : $"{st.name} {T(136)}").ToUpperInvariant();   // no suffix for station 101
            root.Q<Label>("systemName").text = st == null ? "" : $"{st.systemName} {T(137)}";
            root.Q<Label>("techLevel").text = st == null ? "" : $"{T(133)}: {st.techLevel}";
            int race = level != null ? level.Layout.raceId : -1;
            var raceLabel = root.Q<Label>("raceName");
            raceLabel.text = race >= 0 && race < 4 ? T(406 + race) : "";
            raceLabel.style.display = raceLabel.text.Length > 0 ? DisplayStyle.Flex : DisplayStyle.None;
            hangarButton.text = T(167).ToUpperInvariant();
            loungeButton.text = T(398).ToUpperInvariant();
            mapButton.text = T(177).ToUpperInvariant();
            launchButton.text = GoF2Localization.Extra("stationLaunch", "LAUNCH");
            dialogNo.text = T(135).ToUpperInvariant();
            root.Q<Button>("menuButton").text = GoF2Localization.Extra("hudMenu", "MENU");
            root.Q<Label>("systemMenuTitle").text = T(172).ToUpperInvariant();       // Menu
            saveGameButton.text = T(30).ToUpperInvariant();                          // Save game
            mainMenuButton.text = T(522).ToUpperInvariant();                         // Back to Main Menu
            systemClose.text = saveBack.text = GoF2Localization.Extra("hudBack", "BACK");

            HookDrag();
            root.RegisterCallback<PointerDownEvent>(OnPointerDown, TrickleDown.TrickleDown);
            root.RegisterCallback<PointerMoveEvent>(e => { if (e.pointerType == PointerType.mouse) SetTouchMode(false); }, TrickleDown.TrickleDown);
            root.RegisterCallback<NavigationMoveEvent>(OnNavigate, TrickleDown.TrickleDown);
            // The hangar window keeps its own selection; Enter / A are read in Update, so no button may also take them.
            root.RegisterCallback<NavigationSubmitEvent>(e =>
            {
                if (!HangarOpen || DialogOpen) return;
                e.StopPropagation();
                root.focusController?.IgnoreEvent(e);
            }, TrickleDown.TrickleDown);

            OnViewChanged();
            ApplyInputMode();
            UpdateLayout();
        }

        Button Bind(string name, System.Action action)
        {
            var b = root.Q<Button>(name);
            b.RegisterCallback<PointerDownEvent>(_ => Play(buttonPush), TrickleDown.TrickleDown);
            b.clicked += () => { Play(buttonRelease); action(); };
            return b;
        }

        // ---- screens -----------------------------------------------------------------------------------

        void OnViewChanged()
        {
            if (root == null || level == null) return;
            bool lounge = level.View == GoF2StationView.Lounge;
            hangarButton.EnableInClassList("station-button--current", HangarOpen);
            loungeButton.EnableInClassList("station-button--current", lounge);
            viewTitle.text = HangarOpen ? GoF2Localization.Get(167).ToUpperInvariant() : lounge ? GoF2Localization.Get(398).ToUpperInvariant() : "";
            viewTitle.style.display = viewTitle.text.Length > 0 ? DisplayStyle.Flex : DisplayStyle.None;
            dragVelocity = 0f;
            ApplyStoryLocks();
            BuildHints(GoF2InputMode.Current);
        }

        /// <summary>ModStation::OnInitialize: Hangar from index 5, Map from 9, Space Lounge from 12 (half transparent before).</summary>
        void ApplyStoryLocks()
        {
            int station = level != null && level.Station != null ? level.Station.index : -1;
            hangarButton.SetEnabled(GoF2Story.HangarUnlocked);
            mapButton.SetEnabled(GoF2Story.MapUnlocked);
            loungeButton.SetEnabled(GoF2Story.LoungeUnlocked(station));
        }

        bool HangarOpen => hangarWindow != null && hangarWindow.IsOpen;

        /// <summary>Station button 0 (ModStation::OnKeyPress): the Hangar window over the main view.</summary>
        void OpenHangar()
        {
            if (HangarOpen || level == null || !GoF2Story.HangarUnlocked) return;
            if (level.View != GoF2StationView.Hangar) level.SetView(GoF2StationView.Hangar);
            hangarWindow.Open();
            root.AddToClassList("hangar-open");
            if (root.focusController?.focusedElement is VisualElement f) f.Blur();
            OnViewChanged();
        }

        public void CloseHangar()
        {
            if (!HangarOpen) return;
            hangarWindow.Close();
            root.RemoveFromClassList("hangar-open");
            OnViewChanged();
            Select(hangarButton);
        }

        void OpenLounge()
        {
            if (level == null || !GoF2Story.LoungeUnlocked(level.Station != null ? level.Station.index : -1)) return;
            CloseHangar();
            level?.SetView(GoF2StationView.Lounge);
        }

        /// <summary>ModStation::OnKeyPress case 2: the star map (station mode; jump mode with a Khador Drive). Refused while
        /// the hold is overloaded (204). A picked station departs at once (StarMap::depart): the launch sequence, then the
        /// autopilot to it or, for another system with a drive, the Khador charge.</summary>
        void OpenMap()
        {
            if (level == null || GoF2StarMap.IsOpen || !GoF2Story.MapUnlocked) return;
            if (new GoF2Hangar(level.Database, level.Stock).Overloaded) { ShowDialog(GoF2Localization.Get(204), null, true); return; }
            CloseHangar();
            if (root.focusController?.focusedElement is VisualElement f) f.Blur();
            root.AddToClassList("station-map-open");
            var map = GoF2StarMap.Open(level.Database, GoF2StarMapMode.Station, GoF2GalaxyMap.HasJumpDrive(level.Database), OnMapClosed);
            if (map == null) root.RemoveFromClassList("station-map-open");
        }

        void OnMapClosed(GoF2StarMapResult result)
        {
            root.RemoveFromClassList("station-map-open");
            if (result.station < 0) { ApplyInputMode(); return; }
            GoF2Session.ProgrammedStation = result.station == GoF2Session.StationIndex ? -1 : result.station;
            GoF2Session.InstantJump = result.instantJump;
            GoF2Session.EnergyCellsForNextJump = result.instantJump ? result.cells : 0;
            level.Launch();
        }

        /// <summary>ModStation::leaveStation: refused while the cargo hold is overloaded (204), else "Depart the station?".</summary>
        void AskLaunch()
        {
            if (new GoF2Hangar(level.Database, level.Stock).Overloaded) { ShowDialog(GoF2Localization.Get(204), null, true); return; }
            ShowDialog(GoF2Localization.Get(397), level.Launch);
        }

        /// <summary>ChoiceWindow: yes / no, or a message with one button ('info').</summary>
        public void ShowDialog(string text, System.Action onYes, bool info = false)
        {
            dialogAction = onYes;
            root.Q<Label>("dialogText").text = text;
            dialogYes.text = info ? GoF2Localization.Extra("ok", "OK") : GoF2Localization.Get(134).ToUpperInvariant();
            dialogNo.style.display = info ? DisplayStyle.None : DisplayStyle.Flex;
            dialog.AddToClassList("station-dialog-backdrop--shown");
            Play(infoSound);
            if (root.focusController?.focusedElement is VisualElement f) f.Blur();
            Select(dialogYes);
        }

        void CloseDialog()
        {
            dialog.RemoveFromClassList("station-dialog-backdrop--shown");
            dialogAction = null;
            if (SystemMenuOpen)
            {
                // Back to the slot just picked (or the first item of the page).
                var items = SystemMenuItems();
                int i = SavePageOpen && lastSavedSlot >= 0 && lastSavedSlot < items.Length ? lastSavedSlot : 0;
                Select(items[i]);
            }
            else if (!HangarOpen) Select(launchButton);
            else if (root.focusController?.focusedElement is VisualElement f) f.Blur();
        }

        bool DialogOpen => dialog != null && dialog.ClassListContains("station-dialog-backdrop--shown");

        /// <summary>A short message at the top ("#N mounted.", "You need an additional #C." ...), 3 s.</summary>
        public void ShowToast(string text)
        {
            toast.text = text;
            toast.AddToClassList("station-toast--shown");
            toastMs = 3000f;
        }

        public void PlayPush() => Play(buttonPush);
        public void PlayRelease() => Play(buttonRelease);
        public void PlayClip(AudioClip clip) => Play(clip);

        void Back()
        {
            if (DialogOpen) { Play(buttonRelease); CloseDialog(); }
            else if (HangarOpen) { Play(buttonRelease); CloseHangar(); }
            else if (SavePageOpen) { Play(buttonRelease); ShowSystemPage(false); }
            else if (SystemMenuOpen) { Play(buttonRelease); CloseSystemMenu(); }
            else if (level != null && level.View == GoF2StationView.Lounge) { Play(buttonRelease); level.SetView(GoF2StationView.Hangar); }
            else { Play(buttonRelease); OpenSystemMenu(); }
        }

        void BackToMenu()
        {
            if (Application.CanStreamedLevelBeLoaded(menuScene)) SceneManager.LoadScene(menuScene);
        }

        // ---- story (ModStation::OnUpdate / OnTouchEnd) ---------------------------------------------------

        /// <summary>Status::missionCompleted(docked): the completed campaign mission's success conversation.</summary>
        bool CheckStory()
        {
            if (level == null || level.Station == null || GoF2Session.FreePlay) return false;
            var ctx = new GoF2StoryContext
            {
                docked = true,
                inLounge = level.View == GoF2StationView.Lounge && !level.IntroPlaying,
                station = level.Station.index,
            };
            if (!GoF2Story.IsComplete(level.Database, ctx)) return false;
            GoF2Story.Mission.won = true;
            CloseHangar();
            if (root.focusController?.focusedElement is VisualElement f) f.Blur();
            var step = GoF2Story.Step;
            if (step != null && step.success.Count > 0) storyDialogue.Show(step.success, _ => AfterStorySuccess());
            else AfterStorySuccess();
            return true;
        }

        /// <summary>ModStation::OnTouchEnd after a campaign success conversation.</summary>
        void AfterStorySuccess()
        {
            var db = level.Database;
            int reward = GoF2Story.Mission.reward;
            int n = GoF2Story.Advance(db);
            if (n == 9 || n == 44 || n == 75 || n == 76 || n == 83)
            {
                GoF2Session.Autosave();
                SceneManager.LoadScene(gameObject.scene.name);   // a fresh station module; the next conversation follows
                return;
            }
            int launchTo = n switch { 89 => 109, 99 => 10, 109 => 114, 119 => 10, 133 => 120, 144 => 112, 160 => 10, _ => -1 };
            if (n == 78) { level.Launch(); return; }   // escape from Valkyrie: departStation + space
            if (launchTo >= 0)
            {
                // initStreamOutPosition + departStation(target): straight into the story orbit.
                GoF2Session.PreviousStationIndex = GoF2Session.StationIndex;
                GoF2Session.StationIndex = launchTo;
                GoF2Session.ArrivedByTravel = n != 144 && n != 160;
                GoF2Session.LaunchedFromStation = false;
                SceneManager.LoadScene(level.spaceScene);
                return;
            }
            GoF2Session.Credits += reward;
            GoF2Session.Autosave();
            ApplyStoryLocks();
            Select(launchButton);
        }

        // ---- system menu (MenuTouchWindow: Save game, Back to Main Menu) -----------------------------------

        bool SystemMenuOpen => systemMenu != null && systemMenu.ClassListContains("station-dialog-backdrop--shown");
        bool SavePageOpen => SystemMenuOpen && systemSave.ClassListContains("system-menu-page--shown");

        void OpenSystemMenu()
        {
            if (SystemMenuOpen || level == null) return;
            CloseHangar();
            systemMenu.AddToClassList("station-dialog-backdrop--shown");
            ShowSystemPage(false);
        }

        void CloseSystemMenu()
        {
            if (!SystemMenuOpen) return;
            systemMenu.RemoveFromClassList("station-dialog-backdrop--shown");
            if (root.focusController?.focusedElement is VisualElement f) f.Blur();
            Select(launchButton);
            BuildHints(GoF2InputMode.Current);
        }

        void ShowSystemPage(bool save)
        {
            systemMain.EnableInClassList("system-menu-page--shown", !save);
            systemSave.EnableInClassList("system-menu-page--shown", save);
            root.Q<Label>("systemMenuTitle").text = GoF2Localization.Get(save ? 30 : 172).ToUpperInvariant();   // Save game / Menu
            if (save) BuildSaveSlots();
            if (root.focusController?.focusedElement is VisualElement f) f.Blur();
            Select(save ? saveSlotList.contentContainer.ElementAt(1) : saveGameButton);   // slot 1: the first manual slot
            BuildHints(GoF2InputMode.Current);
        }

        void BuildSaveSlots()
        {
            saveSlotList.Clear();
            for (int i = 0; i < GoF2SaveGame.SlotCount; i++)
            {
                int slot = i;
                var save = GoF2SaveGame.Preview(i);
                var row = GoF2SaveSlotRow.Build(level.Database, i, save, GoF2Localization.Extra("autosaveHint", "Saved automatically when you dock"));
                row.RegisterCallback<PointerDownEvent>(_ => Play(buttonPush), TrickleDown.TrickleDown);
                row.clicked += () => { Play(buttonRelease); PickSaveSlot(slot, save != null); };
                row.RegisterCallback<FocusInEvent>(_ => saveSlotList.ScrollTo(row));
                saveSlotList.Add(row);
            }
        }

        /// <summary>MenuTouchWindow::OnTouchEnd save mode: slot 0 is reserved, a used slot asks before overwriting.</summary>
        void PickSaveSlot(int slot, bool used)
        {
            lastSavedSlot = slot;
            if (slot == GoF2SaveGame.AutoSaveSlot) { ShowDialog(GoF2Localization.Get(487), null, true); return; }
            if (used) ShowDialog(GoF2Localization.Get(49), () => SaveTo(slot));
            else SaveTo(slot);
        }

        /// <summary>MenuTouchWindow::saveGame: write the slot, refresh the list, "Game saved." (50).</summary>
        void SaveTo(int slot)
        {
            bool ok = GoF2SaveGame.Save(slot);
            BuildSaveSlots();
            lastSavedSlot = slot;
            ShowDialog(ok ? GoF2Localization.Get(50) : GoF2Localization.Extra("saveFailed", "The game could not be saved."), null, true);
        }

        /// <summary>The system menu's focusable items (its buttons, or the slot rows plus Back).</summary>
        VisualElement[] SystemMenuItems()
        {
            if (!SavePageOpen) return new VisualElement[] { saveGameButton, mainMenuButton, systemClose };
            var list = new System.Collections.Generic.List<VisualElement>(saveSlotList.contentContainer.Children()) { saveBack };
            return list.ToArray();
        }

        // ---- turning the ship (ModStation::OnTouchMove / OnTouchEnd) ----------------------------------------

        /// <summary>Panel units per game radian: the original's 120 px on a 480 px high screen, a quarter of the height.</summary>
        float UnitsPerRadian => Mathf.Max(1f, root.layout.height) * (GoF2StationTables.TurntablePixelsPerRadian / 480f);

        void HookDrag()
        {
            dragZone.RegisterCallback<PointerDownEvent>(e =>
            {
                if (level == null || dragPointer >= 0) return;
                if (level.View == GoF2StationView.Lounge) { level.SkipIntro(); return; }   // OnTouchEnd case 0: jump to B
                dragPointer = e.pointerId;
                dragZone.CapturePointer(e.pointerId);
                dragLastX = e.position.x;
                dragLastTime = Time.unscaledTime;
                dragVelocity = dragFrameRadians = 0f;
                level.RotateShip(0f);   // stops a fling
            });
            dragZone.RegisterCallback<PointerMoveEvent>(e =>
            {
                if (e.pointerId != dragPointer) return;
                float rad = (e.position.x - dragLastX) / UnitsPerRadian;
                level.RotateShip(rad);
                dragFrameRadians += rad;
                dragLastX = e.position.x;
                dragLastTime = Time.unscaledTime;
            });
            dragZone.RegisterCallback<PointerUpEvent>(e => EndDrag(e.pointerId, true));
            dragZone.RegisterCallback<PointerCancelEvent>(e => EndDrag(e.pointerId, false));
        }

        void EndDrag(int pointerId, bool fling)
        {
            if (pointerId != dragPointer) return;
            if (dragZone.HasPointerCapture(dragPointer)) dragZone.ReleasePointer(dragPointer);
            dragPointer = -1;
            // OnTouchEnd: fling only if the finger was still moving (the original: last dx > 3 px).
            bool moving = Time.unscaledTime - dragLastTime < 0.08f;
            float minSpeed = 3f / GoF2StationTables.TurntablePixelsPerRadian / 0.02f;
            if (fling && moving && Mathf.Abs(dragVelocity) > minSpeed) level.FlingShip(Mathf.Clamp(dragVelocity, -MaxFling, MaxFling));
        }

        // ---- input mode, focus and navigation -------------------------------------------------------------

        void ApplyInputMode()
        {
            if (root == null) return;
            var kind = GoF2InputMode.Current;
            root.EnableInClassList("input-touch", kind == GoF2InputKind.Touch);
            root.EnableInClassList("input-keyboard", kind == GoF2InputKind.KeyboardMouse);
            root.EnableInClassList("input-gamepad", kind == GoF2InputKind.Gamepad);
            SetTouchMode(kind == GoF2InputKind.Touch);
            if (kind == GoF2InputKind.Gamepad && !HangarOpen && root.focusController?.focusedElement == null)
                Select(DialogOpen ? dialogYes : SystemMenuOpen ? SystemMenuItems()[0] : level != null && level.View == GoF2StationView.Lounge ? loungeButton : hangarButton);
            BuildHints(kind);
        }

        // Touch has no hover and shouldn't leave a focus highlight on what the finger pressed (see GoF2MainMenu).
        void SetTouchMode(bool on)
        {
            touchMode = on;
            root.EnableInClassList("can-hover", !on);
            if (on && root.focusController?.focusedElement is VisualElement focused) focused.Blur();
        }

        void OnPointerDown(PointerDownEvent e)
        {
            if (e.pointerType == PointerType.mouse) { SetTouchMode(false); return; }
            SetTouchMode(true);
            root.focusController?.IgnoreEvent(e);
        }

        void Select(VisualElement e)
        {
            if (!touchMode) e?.Focus();
        }

        /// <summary>Up/down walks the screen buttons and launch (left/right: yes/no in the dialog); left/right otherwise
        /// stay free for turning the ship.</summary>
        void OnNavigate(NavigationMoveEvent e)
        {
            SetTouchMode(false);
            bool vertical = e.direction == NavigationMoveEvent.Direction.Up || e.direction == NavigationMoveEvent.Direction.Down;
            bool horizontal = e.direction == NavigationMoveEvent.Direction.Left || e.direction == NavigationMoveEvent.Direction.Right;
            if (HangarOpen && !DialogOpen)
            {
                // Read in Update (HoldDirections): navigation events only arrive while a UI element has focus.
                e.StopPropagation();
                root.focusController?.IgnoreEvent(e);
                return;
            }
            var items = DialogOpen ? new VisualElement[] { dialogYes, dialogNo }
                      : SystemMenuOpen ? SystemMenuItems()
                      : new VisualElement[] { hangarButton, loungeButton, mapButton, launchButton };
            if (DialogOpen ? horizontal : vertical)
            {
                var focused = root.focusController?.focusedElement as VisualElement;
                int i = System.Array.IndexOf(items, focused);
                int step = e.direction == NavigationMoveEvent.Direction.Up || e.direction == NavigationMoveEvent.Direction.Left ? -1 : 1;
                items[i < 0 ? 0 : Mathf.Clamp(i + step, 0, items.Length - 1)].Focus();
            }
            e.StopPropagation();
            root.focusController?.IgnoreEvent(e);
        }

        void BuildHints(GoF2InputKind kind)
        {
            if (hints == null) return;
            hints.Clear();
            string T(string key, string english) => GoF2Localization.Extra(key, english);
            if (SystemMenuOpen)
            {
                string select = T("hudSelect", "SELECT"), confirm = T("hudConfirm", "CONFIRM"), close = T("hudBack", "BACK");
                if (kind == GoF2InputKind.KeyboardMouse)
                {
                    Hint(select, GoF2InputGlyph.Key("W"), GoF2InputGlyph.Key("S"));
                    Hint(confirm, GoF2InputGlyph.Key("ENTER", true));
                    Hint(close, GoF2InputGlyph.Key("ESC"));
                }
                else if (kind == GoF2InputKind.Gamepad)
                {
                    Hint(select, GoF2InputGlyph.Pad(GoF2PadButton.DPad));
                    Hint(confirm, GoF2InputGlyph.Pad(GoF2PadButton.A));
                    Hint(close, GoF2InputGlyph.Pad(GoF2PadButton.B));
                }
                return;
            }
            if (HangarOpen)
            {
                string select = T("hudSelect", "SELECT"), trade = $"{T("shopSell", "SELL")} / {T("shopBuy", "BUY")}";
                string tabs = $"{GoF2Localization.Get(183)} / {GoF2Localization.Get(185)}".ToUpperInvariant(), confirm = T("hudConfirm", "CONFIRM");
                if (kind == GoF2InputKind.KeyboardMouse)
                {
                    Hint(select, GoF2InputGlyph.Key("W"), GoF2InputGlyph.Key("S"));
                    Hint(trade, GoF2InputGlyph.Key("A"), GoF2InputGlyph.Key("D"));
                    Hint(confirm, GoF2InputGlyph.Key("ENTER", true));
                    Hint(tabs, GoF2InputGlyph.Key("Q"), GoF2InputGlyph.Key("E"));
                    Hint(T("hudBack", "BACK"), GoF2InputGlyph.Key("ESC"));
                }
                else if (kind == GoF2InputKind.Gamepad)
                {
                    Hint($"{select} / {trade}", GoF2InputGlyph.Pad(GoF2PadButton.DPad));
                    Hint(confirm, GoF2InputGlyph.Pad(GoF2PadButton.A));
                    Hint(tabs, GoF2InputGlyph.Pad(GoF2PadButton.LeftBumper), GoF2InputGlyph.Pad(GoF2PadButton.RightBumper));
                    Hint(T("hudBack", "BACK"), GoF2InputGlyph.Pad(GoF2PadButton.B));
                }
                return;
            }
            bool hangar = level == null || level.View == GoF2StationView.Hangar;
            string rotate = T("stationRotate", "TURN SHIP"), launch = T("stationLaunch", "LAUNCH");
            string back = hangar ? T("hudMenu", "MENU") : T("hudBack", "BACK");
            if (kind == GoF2InputKind.KeyboardMouse)
            {
                if (hangar) Hint(rotate, GoF2InputGlyph.Key("A"), GoF2InputGlyph.Key("D"));
                if (hangarButton.enabledSelf) Hint(GoF2Localization.Get(167).ToUpperInvariant(), GoF2InputGlyph.Key("1"));
                if (loungeButton.enabledSelf) Hint(GoF2Localization.Get(398).ToUpperInvariant(), GoF2InputGlyph.Key("2"));
                if (mapButton.enabledSelf) Hint(GoF2Localization.Get(177).ToUpperInvariant(), GoF2InputGlyph.Key("M"));
                Hint(launch, GoF2InputGlyph.Key("L"));
                Hint(back, GoF2InputGlyph.Key("ESC"));
            }
            else if (kind == GoF2InputKind.Gamepad)
            {
                if (hangar) Hint(rotate, GoF2InputGlyph.Pad(GoF2PadButton.RightStick));
                if (hangarButton.enabledSelf) Hint(GoF2Localization.Get(167).ToUpperInvariant(), GoF2InputGlyph.Pad(GoF2PadButton.LeftBumper));
                if (loungeButton.enabledSelf) Hint(GoF2Localization.Get(398).ToUpperInvariant(), GoF2InputGlyph.Pad(GoF2PadButton.RightBumper));
                if (mapButton.enabledSelf) Hint(GoF2Localization.Get(177).ToUpperInvariant(), GoF2InputGlyph.Pad(GoF2PadButton.Y));
                Hint(launch, GoF2InputGlyph.Pad(GoF2PadButton.X));
                Hint(T("hudBack", "BACK"), GoF2InputGlyph.Pad(GoF2PadButton.B));
                Hint(T("hudMenu", "MENU"), GoF2InputGlyph.Pad(GoF2PadButton.Menu));
            }
        }

        void Hint(string label, params VisualElement[] glyphs)
        {
            var h = new VisualElement { pickingMode = PickingMode.Ignore };
            h.AddToClassList("hint");
            foreach (var g in glyphs) h.Add(g);
            var l = new Label(label) { pickingMode = PickingMode.Ignore };
            l.AddToClassList("hint-label");
            l.AddToClassList("gof-semibold");
            h.Add(l);
            hints.Add(h);
        }

        // ---- per frame -----------------------------------------------------------------------------------

        void Update()
        {
            if (root == null || level == null) return;
            if (lastScreen != ScreenSize() || lastSafeArea != Screen.safeArea) UpdateLayout();
            if (GoF2StarMap.IsOpen) return;   // the map has its own input
            if (storyDialogue != null && storyDialogue.IsOpen) { storyDialogue.Tick(Time.unscaledDeltaTime * 1000f); return; }
            if (!DialogOpen && !SystemMenuOpen && !HangarOpen && CheckStory()) return;

            var kb = Keyboard.current;
            var pad = Gamepad.current;
            if ((kb != null && kb.escapeKey.wasPressedThisFrame) || (pad != null && pad.buttonEast.wasPressedThisFrame)) { Back(); return; }
            if (pad != null && pad.startButton.wasPressedThisFrame && !DialogOpen)
            {
                Play(buttonRelease);
                if (SystemMenuOpen) CloseSystemMenu(); else OpenSystemMenu();
                return;
            }
            if (toastMs > 0f && (toastMs -= Time.unscaledDeltaTime * 1000f) <= 0f) toast.RemoveFromClassList("station-toast--shown");
            if (DialogOpen || SystemMenuOpen) return;

            if (HangarOpen)
            {
                float dtMs = Time.unscaledDeltaTime * 1000f;
                int v = 0, h = 0;
                if (kb != null)
                {
                    if (kb.wKey.isPressed || kb.upArrowKey.isPressed) v -= 1;
                    if (kb.sKey.isPressed || kb.downArrowKey.isPressed) v += 1;
                    if (kb.aKey.isPressed || kb.leftArrowKey.isPressed) h -= 1;
                    if (kb.dKey.isPressed || kb.rightArrowKey.isPressed) h += 1;
                }
                if (pad != null)
                {
                    var stick = pad.leftStick.ReadValue() + pad.dpad.ReadValue();
                    if (stick.y > 0.5f) v -= 1; else if (stick.y < -0.5f) v += 1;
                    if (stick.x < -0.5f) h -= 1; else if (stick.x > 0.5f) h += 1;
                }
                hangarWindow.HoldDirections(System.Math.Sign(v), System.Math.Sign(h), dtMs);
                hangarWindow.Update(dtMs);
                if ((kb != null && (kb.enterKey.wasPressedThisFrame || kb.numpadEnterKey.wasPressedThisFrame)) || (pad != null && pad.buttonSouth.wasPressedThisFrame))
                    hangarWindow.Action();
                else if ((kb != null && (kb.qKey.wasPressedThisFrame || kb.eKey.wasPressedThisFrame))
                         || (pad != null && (pad.leftShoulder.wasPressedThisFrame || pad.rightShoulder.wasPressedThisFrame)))
                {
                    Play(buttonPush);
                    hangarWindow.NextTab();
                }
                else if (kb != null && kb.digit2Key.wasPressedThisFrame) OpenLounge();
                return;
            }

            if ((kb != null && kb.digit1Key.wasPressedThisFrame) || (pad != null && pad.leftShoulder.wasPressedThisFrame))
                OpenHangar();
            if ((kb != null && kb.digit2Key.wasPressedThisFrame) || (pad != null && pad.rightShoulder.wasPressedThisFrame))
                OpenLounge();
            if ((kb != null && (kb.mKey.wasPressedThisFrame || kb.digit3Key.wasPressedThisFrame)) || (pad != null && pad.buttonNorth.wasPressedThisFrame))
            {
                Play(buttonRelease);
                OpenMap();
                return;
            }
            if ((kb != null && kb.lKey.wasPressedThisFrame) || (pad != null && pad.buttonWest.wasPressedThisFrame))
            {
                Play(buttonRelease);
                AskLaunch();
                return;
            }

            if (dragPointer >= 0)
            {
                // Release velocity: the turn per frame, smoothed (the original uses the last frame's dx).
                dragVelocity = Mathf.Lerp(dragVelocity, dragFrameRadians / Mathf.Max(Time.unscaledDeltaTime, 1e-3f), 0.6f);
                dragFrameRadians = 0f;
            }
            else if (level.View == GoF2StationView.Hangar)
            {
                float turn = 0f;
                if (kb != null)
                {
                    if (kb.aKey.isPressed || kb.leftArrowKey.isPressed) turn -= 1f;
                    if (kb.dKey.isPressed || kb.rightArrowKey.isPressed) turn += 1f;
                }
                if (pad != null && Mathf.Abs(pad.rightStick.x.ReadValue()) > 0.15f) turn += pad.rightStick.x.ReadValue();
                if (turn != 0f) level.RotateShip(Mathf.Clamp(turn, -1f, 1f) * keyTurnSpeed * Time.deltaTime);
            }
            else if (level.IntroPlaying && ((kb != null && kb.anyKey.wasPressedThisFrame) || (pad != null && pad.buttonSouth.wasPressedThisFrame)))
                level.SkipIntro();
        }

        void Play(AudioClip clip)
        {
            if (sfxSource != null && clip != null) sfxSource.PlayOneShot(clip, GoF2Settings.SfxVolume);
        }

        // ---- layout (same scaling and safe-area handling as the flight HUD) ---------------------------------

        Vector2Int ScreenSize()
        {
            var rt = runtimePanel != null ? runtimePanel.targetTexture : null;
            return rt != null ? new Vector2Int(rt.width, rt.height) : new Vector2Int(Screen.width, Screen.height);
        }

        void UpdateLayout()
        {
            lastScreen = ScreenSize();
            lastSafeArea = Screen.safeArea;
            bool offscreen = runtimePanel != null && runtimePanel.targetTexture != null;
            float w = Mathf.Max(1, lastScreen.x), h = Mathf.Max(1, lastScreen.y);
            float inches = Screen.dpi > 0f ? Mathf.Sqrt(w * w + h * h) / Screen.dpi : 20f;
            bool phone = Application.isMobilePlatform && inches < 7.5f;
            if (runtimePanel != null)
            {
                runtimePanel.referenceResolution = phone ? new Vector2Int(1600, 900) : new Vector2Int(1920, 1080);
                runtimePanel.screenMatchMode = PanelScreenMatchMode.MatchWidthOrHeight;
                runtimePanel.match = 1f;
            }
            root.EnableInClassList("layout-phone", phone);
            ApplySafeArea(w, h, offscreen);
        }

        /// <summary>Device safe-area insets; retries until the panel has a real (non-NaN) size, see GoF2FlightHud.</summary>
        void ApplySafeArea(float w, float h, bool offscreen)
        {
            root.schedule.Execute(() =>
            {
                if (safeArea == null) return;
                if (!(root.layout.width > 0f)) { ApplySafeArea(w, h, offscreen); return; }
                float k = root.layout.width / w;
                var raw = offscreen ? new Rect(0f, 0f, w, h) : Screen.safeArea;
                var sa = Rect.MinMaxRect(Mathf.Clamp(raw.xMin, 0f, w), Mathf.Clamp(raw.yMin, 0f, h),
                                         Mathf.Clamp(raw.xMax, 0f, w), Mathf.Clamp(raw.yMax, 0f, h));
                if (sa.width < w * 0.5f || sa.height < h * 0.5f) sa = new Rect(0f, 0f, w, h);
                safeArea.style.left = sa.xMin * k;
                safeArea.style.right = (w - sa.xMax) * k;
                safeArea.style.top = (h - sa.yMax) * k;
                safeArea.style.bottom = sa.yMin * k;
            }).ExecuteLater(1);
        }
    }
}
