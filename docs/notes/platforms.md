# Platforms and builds

Notes moved from `CLAUDE.md` (its index lists every notes file). Code comments citing `CLAUDE.md "<section>"` mean the section or bullet of that name here.

## UI and platforms

- Main menu research (flow, text IDs, image rects, camera, sounds): `Reference/research/mainmenu_notes.md`.
- **Discord Rich Presence** (remake, desktop; Windows so far): `DiscordPresence` + `DiscordIpc` (the desktop app's local pipe, no SDK) for the Discord application "Galaxy on Fire 2 Unity Remake" (1555054317155647571); details / state from the scene (docked, flying, mining, combat, cutscene; the freelance mission or the story step's title, multiplayer squad), the campaign art large and the system's race emblem small (assets from `Reference/tools/discord/make_assets.py`), the timer from the game's start; in the Mod Builder the project instead of the throwaway game it runs in ("Making a mod - <kind>" / "Test flight" / "Play-testing a mod", the project's name, large text "Mod Builder"); Options > Gameplay "Show what I'm doing in Discord".
- **App icon** (`MainMenuBuilder.BuildAppIcons`, run by Main Menu Scene; the art `UI/AppIcon/icon_source.png`, 2000 x 2000
  with rounded corners): `icon.png` the default icon (Windows / Linux / iOS, Android legacy and round), Android's adaptive
  icon = `icon_foreground.png` (the art at 62 % inside the 66.7 % visible area, so a circle mask keeps the title) over
  `icon_background.png` (the art's middle blurred and enlarged) + `icon_monochrome.png` (its bright parts in white, the
  themed icon); UWP's tiles, store logo and splash at 100 / 200 % in `UI/AppIcon/UWP` (`PlayerSettings.WSA` visual assets:
  squares = the art, wide / splash = the art on its blur; an image over 200 KB is left out at 200 %, the UWP packager refuses
  bigger logos (APPX3207), so the 310 x 310 and wide tiles and the splash come at 100 % only). Without the art the old icon
  (the GoF2 logo on skybox_003).
- **Android name**: package `com.joppietoppie.gof2remake`, launcher label "GoF2 Remake" (`AndroidAppLabel` rewrites the Gradle project's app_name); the product name stays "Galaxy on Fire 2" so the desktop save folder and PlayerPrefs don't move.
  **Beta builds** (fork, `AndroidBetaPackage`): with GoF2 > Build > Android Beta Package ticked (per machine) or
  `GOF2_ANDROID_BETA=1`, an Android build gets the package `com.joppietoppie.gof2remake.beta` and the label "GoF2 Beta", so it
  installs beside the published game (the same package signed with another key has to replace it); put back after the build
  like `BuildVersionStamp`. The beta has its own data folder (saves, mods, Transfer). The Java class
  `com.joppietoppie.gof2remake.ModImportActivity` keeps its name: a class's Java package is not the app's package.
- **iOS** (remake, 2026-10-17; checked in the iPhone 18 Pro simulator: main menu, flight HUD, cutscene pause button, station, hangar, lounge, star map, Missions, Status, Inspect ship, Action Freeze, pause and autopilot menus; not yet run on an iPhone): **Safe area**: `UI.SafeArea` (App/UI) turns `Screen.safeArea`
  into a panel's insets, clamped to the screen (a safe area under half the screen ignored); iPhones in landscape report the
  Dynamic Island / notch inset on both the left and the right and the home indicator's at the bottom. The main menu
  (margins: its children are absolutely placed, which a parent's padding never moves, so its old padding inset nothing),
  the flight HUD and the station (their `safeArea` element's position) and the star map (`mapSafe`, which it
  never inset before) use `SafeArea.Apply`; full-screen overlays keep their edge-anchored parts clear with
  `SafeArea.KeepClear(overlay)`, margins on every descendant with the class `safe-edge` (`SafeArea.EdgeClass`): Action
  Freeze's and Inspect ship's title, hints, footer, photo settings panel and saved notice, the Customize panel, the Mod
  Builder's top bar, side panels and status line (the overlay itself stays full screen: the photo frame bars must match the
  screenshot); the story-step label moves in by the right inset only (the bottom one lifted it onto the station's ticker). A new screen with controls at the edges uses
  these. **Player settings and Info.plist** (`IosPlayerSetup`, Editor, on Editor load and before an iOS build, each only
  while at Unity's default): bundle id `com.joppietoppie.gof2remake`, the home indicator auto-hidden, system gestures
  deferred on the top and bottom edges; after the build Info.plist gets `CFBundleDisplayName` "GoF2 Remake" (never through
  `PlayerSettings.iOS.applicationDisplayName`: that is the product name itself, which names the desktop save folder and
  PlayerPrefs), `UIFileSharingEnabled` + `LSSupportsOpeningDocumentsInPlace` (Documents = persistentDataPath in the Files
  app: Saves, Mods, Transfer, Screenshots), `CADisableMinimumFrameDurationOnPhone` (ProMotion above 60 fps),
  `NSLocalNetworkUsageDescription` (iOS 14+ blocks LAN games without it), `NSPhotoLibraryAddUsageDescription`, Game Mode
  (`LSApplicationCategoryType` action games, `GCSupportsGameMode`) and controller support (`GCSupportsControllerUserInteraction`,
  `GCSupportedGameControllers` ExtendedGamepad). **Native plugins** (`Assets/Plugins/iOS`, each .mm's meta naming its
  framework): `PhoneHaptics.mm` (Core Haptics behind `PhoneVibrator`: every pulse at its intensity, none on iPads),
  `PhotoLibrary.mm` (`PhotoMode.StoreAt`: Documents/Screenshots and the photo library, add-only), `FileImportPicker.mm`
  (`ModImport.Pick`), `SaveFolderPicker.mm` (the save folder). Local network adapters by iOS name (`NetGame.AdapterName`:
  en0 Wi-Fi, bridge Hotspot, utun VPN; mobile data and AirDrop left out). Switching the active target to iOS adds a default
  iOS entry to every texture .meta (like UWP's): harmless, revert them before committing.
- **Android Vulkan pre-transform** (Player settings > Android > "Apply display rotation during rendering",
  `PlayerSettings.vulkanEnablePreTransform`): on, with `PreTransformGuard` (Space, installed by `Bootstrap`): while it is in
  use (`PreTransformGuard.Active`: Vulkan, `SystemInfo.supportsSwapChainPreTransform`, not
  `QualitySettings.disableSwapChainPreTransform`) every base game camera drawing to the screen queues an empty render pass
  with `requiresIntermediateTexture`, so URP never draws the scene straight to the pre-rotated back buffer; only its final
  blit and the UI do. Straight to it (render scale 100 % without MSAA, FSR at 100 %+, the only cases where URP skips the
  intermediate texture) part of the screen froze (a player's report, #45): the remake's screen-space shaders (the hangar
  shadows reading the depth texture, the cloak / shield bubble refraction, the classic bloom, the bar flybys' pass) work in
  unrotated coordinates, where URP's own (`DeclareDepthTexture`, `Shadows`) correct for the rotation. It was off from
  2026-10-14 to 2026-10-21 for that: Android's compositor then rotates every frame, a full-screen GPU pass on phones whose
  display hardware can't (a Dimensity 8350: a solid 60 fps in 2026.10.09's Terran hangar, 40-60 in 2026.10.18's, at 50 %
  render scale). The guard costs a full-resolution blit at 100 % (below it, or with MSAA, URP blits anyway).
  `Bootstrap.ApplyUpscaling` still keeps FSR 1 below 100 % (there is nothing to upscale at 100 %). Not yet run on a phone.
  The freeze at 100 % was reported again with 2026.10.23 (the guard in), and doesn't happen with MSAA on (the user's test on
  a phone). The guard can't have changed anything: with post-processing on URP renders through its intermediate texture
  anyway (`UniversalRenderer.RequiresIntermediateColorTexture`); the cause is still unknown. A lead: with MSAA off the
  station camera runs URP's TAA (`StationLevel.ApplyAntialiasing`), with MSAA SMAA. So on Android 100 % with MSAA off gets
  MSAA 2x (`Bootstrap.AppliedMsaa`; the option still shows Off), and under a temporal upscaler (MSAA off) 94 %
  (`AppliedRenderScale` / `AndroidFullScale`: URP renders a scale within 5 % of 1 as exactly 1, `kRenderScaleThreshold`).
  Not yet checked on a phone.
- **UWP** (Universal Windows Platform, no build profile: `EditorUserBuildSettings.SwitchActiveBuildTarget(WSA, WSAPlayer)`
  first, then `BuildPipeline.BuildPlayer` to a folder; IL2CPP, x64, D3D): package `JoppieToppie.GoF2Remake`, Start menu
  name "GoF2 Remake", capabilities InternetClient / InternetClientServer / PrivateNetworkClientServer (multiplayer and
  hosting), signed with a test certificate `Assets/WSATestCertificate.pfx` (publisher CN=JoppieToppie, made by the internal
  `EditorUtility.WSACreateTestCertificate(path, "JoppieToppie", "", overwrite)` through reflection: a publisher given as
  "CN=..." became CN="CN=..."; git-ignored, a new clone makes its own). Unity writes a Visual Studio solution; the
  package comes from MSBuild (`MSBuild "Galaxy on Fire 2.sln" -p:Configuration=Master -p:Platform=x64 -p:AppxBundle=Never
  -p:UapAppxPackageBuildMode=SideloadOnly -p:AppxPackageDir=...`; needs Visual Studio's "C++ Universal Windows Platform
  tools", `Microsoft.VisualStudio.ComponentGroup.UWP.VC`, which Burst needs too): `<name>_x64_Master_Test` with the
  .msix, the .cer and Install.ps1 (it trusts the certificate, admin prompt, then installs); a release zips that folder
  without the .appxsym symbols and the TelemetryDependencies folder (the script then sends no sideload telemetry). Not
  in UWP: Discord, the controller gyro, the save file dialog (Transfer folder instead), the dedicated server
  (everything desktop-only is behind `UNITY_STANDALONE_WIN`), the window mode / resolution options
  (`Bootstrap.HasDisplayOptions` false under `UNITY_WSA`: `Screen.mainWindowDisplayInfo` throws NotSupportedException
  there, which stopped `Bootstrap.Init` and the main menu's options setup, a black screen after the splash). The back
  buffer took the window's view-pixel size (1920 x 1080 on a 4K TV, scaled up): `UwpDisplay` sets it to the window's
  raw pixels (`DisplayInformation.RawPixelsPerViewPixel`), on an Xbox to the HDMI mode (`HdmiDisplayInformation`; only
  the One X / Series X above 1080p, `AnalyticsInfo.DeviceForm`), again on resize / DPI change, and logs "UwpDisplay: ..."
  (not yet verified on a 4K display or an Xbox). Testing
  a UWP build here: with Developer Mode on, unpack the .msix (its entry names are URL-encoded) without
  AppxSignature.p7x / AppxBlockMap.xml / [Content_Types].xml / AppxMetadata, `Add-AppxPackage -Register` its
  AppxManifest.xml, start it from `shell:AppsFolder\<family>!App`; the log is
  `%LOCALAPPDATA%\Packages\JoppieToppie.GoF2Remake_*\TempState\UnityPlayer.log`. `BuildVersionStamp` also stamps the package version
  (yyyy.M.d.HHmm). Switching to UWP adds default WindowsStoreApps entries to every texture .meta: revert them.
- **UWP sky** (#20): the space-sky strips (`Resources/GoF2Sky`) have a WindowsStoreApps override to uncompressed RGBA32 with 1365 px faces
  (`SkyboxBaker.ApplyUwpOverride`; the asteroid belt sky layer's `skybox_asteroid_belt_diffuse` too, RGBA32 at 2048, set by `AssetImport` since 2026-10-11: compressed it showed as a checkerboard of squares on the Xbox; the Xbox runs UWP apps at D3D feature level 10, which has no BC7: the default CompressedHQ
  drew bands of shifted tiles, BC1 bands and a criss-cross; if RGBA32 still breaks it is the cubemap layout, and the next step
  is the shader's 2D strip path; unverified on the device). Menus: a text field is one
  focus stop (`MainMenu.InsideTextField`; its inner input was listed too and handed the focus back, trapping the D-pad in the
  multiplayer panel's name field), panels open on their first non-text item, and on UWP the text typed while the system keyboard
  was open is kept when it closes with B (`KeepKeyboardText`; closing counts as Cancel and put the old text back).
- **Version** (`BuildVersion`): the menu's credit line and the About page show "Galaxy on Fire 2 Unity Remake created with
  <heart sprite> by JoppieToppie · <version>" (`BuildVersion.Text`; also `/version` in the chat, the multiplayer window's
  foot and the dedicated server's first log line; no git branch / commit any more: joining compares the fingerprint); the version is the date and time of the git commit the build comes from (`yyyy.MM.dd.HHmm`, UTC; fork change, upstream
  uses the build's own time, still the fallback without git), so Windows, Linux and Android builds of one commit match; stamped into
  `PlayerSettings.bundleVersion` for each build by `BuildVersionStamp` (Editor) and put back afterwards, so
  `Application.version` and Android's versionName carry it; "editor" in the Editor.
- **Update check** (remake, `UpdateCheck`): entering the main menu (after the title screen) asks GitHub once per run for the
  newest release (`api.github.com/repos/JoppieToppie/Galaxy-on-Fire-2-Unity-Remake/releases/latest`, no token; drafts and
  pre-releases ignored). Release tags are `yyyy.MM.dd`; the build's `.HHmm` is ignored, so only a release from a later day
  than the build counts. Then "Update available · <tag>" shows at the bottom centre (`.update-row`, only while no panel is
  open; Down from the last menu row reaches it) and opens the release page (`Application.OpenURL`). A failed request is tried
  again on the next menu entry. The Editor ("editor") checks only with `MainMenu.editorTestVersion` set (e.g. 2026.09.29.2200).
- **Hitch logger** (`HitchLogger`, development builds only; in the Editor with PlayerPrefs `debug_hitchlog` = 1): frames over 33 ms on the real clock to `persistentDataPath/hitches.log` (scene, seconds since its load, campaign step / station, tags load / GC / focus, a summary per scene) and `GraphicsSettings.logWhenShaderIsCompiled` on, so logcat shows every "Uploaded shader variant to the GPU driver" with its time. Measured on the S24 Ultra (Vulkan, Adreno 750, Vulkan pipeline cache deleted, 2026-09-28): 28 variants / ~360 ms at startup before the menu shows, then only at scene loads (GoF2/Unlit 49 ms at the first station, SpaceDust 26 ms), nothing during play (the menu backdrop's live orbit already uses the flight shaders), no frame over 50 ms: no shader warm-up (`GraphicsStateCollection`) needed so far.
- **FMOD event IDs -> .ogg**: `Reference/research/fmod_event_ids.txt` (every system id, from the FEV's LGCY data; see "Known open items"). Menu theme = 145 `Space_NoCombat_Void`, new game = 143 `IntroAtmo`, buttons 124/123, dialog 126.
