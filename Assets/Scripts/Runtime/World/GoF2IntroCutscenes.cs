// GoF2IntroCutscenes.cs
// The new game's opening, campaign indices 0 and 1 (LevelScript::LevelScript 0x15e650 / process 0x160d50; positions and
// timings from the Thumb disassembly, Reference/research/levelscript_cutscenes.md 2, campaign_levels_a.md 3.1 / 3.2):
//   index 0, the prologue "3598 A.D. - Dareius Asteroid Belt" (orbit of Var Hastra, no station, intro sky): Keith's
//     Phantom (unkillable) finds three pirates hiding in the belt, the player fights them, then the hyperdrive fails:
//     a time jump (hyper_drive fx) out of the belt into Var Hastra's orbit, the broken ship tumbling while its oxygen runs
//     out; fade to black, nextCampaignMission, the flight level again
//   index 1, the rescue: the drifting Phantom, Gunant Breh's salvager (Midorian ship 30) closes in, his three radio lines,
//     fade to black, docked at Var Hastra (the first station conversation follows)
// The state number is the level-script event (radio trigger 27). Plain C#, run by GoF2CampaignLevel.
// Not reproduced: the broken ship's smoke particles and the player engine sound; the original's unreachable skip branches.

using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.Visuals;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace GoF2Remake.World
{
    public class GoF2IntroCutscenes
    {
        const float M = 0.05f;

        readonly GoF2CampaignLevel campaign;
        readonly GoF2SpaceLevel level;
        readonly GoF2CutsceneCamera cam;
        readonly GoF2StoryAssets assets;
        readonly int index;
        float stepMs, playerSpeed = 2f;   // u/ms
        float fxMs, fxLength;
        bool soundsPlayed, loading;
        GameObject fx;
        readonly Vector3[] bobBase = new Vector3[3];

        GoF2ShipController Ship => level.Player;
        Transform Player => level.Player.transform;
        int Step { get => campaign.Event; set { campaign.Event = value; stepMs = 0f; } }

        static Vector3 ToUnity(Vector3 game) => new Vector3(game.x, game.y, -game.z) * M;
        static Vector3 Dir(Vector3 game) => new Vector3(game.x, game.y, -game.z).normalized;

        public GoF2IntroCutscenes(GoF2CampaignLevel campaignLevel, GoF2SpaceLevel spaceLevel, int storyIndex)
        {
            campaign = campaignLevel;
            level = spaceLevel;
            index = storyIndex;
            assets = GoF2StoryAssets.Load();
            cam = new GoF2CutsceneCamera(level.mainCamera);
        }

        public GoF2CutsceneCamera Camera => cam;

        // ---- set-up (Level::createCampaignMission cases 0 / 1 + the LevelScript constructor) ------------------------

        public void Build()
        {
            campaign.PlayerInvulnerable = true;   // HP 9 999 999
            campaign.Cutscene = true;
            campaign.CollisionOff = true;
            campaign.StartSequenceOver = false;
            campaign.MusicOwned = true;
            Ship.externalControl = true;
            if (level.Weapons != null) level.Weapons.Blocked = true;
            if (index == 0) BuildPrologue(); else BuildRescue();
        }

        void BuildPrologue()
        {
            // Pirates: ships 2 Hiro, 23 Azov, 2 Hiro at (50 000, 50 000, 50 000), asleep and invisible, always-enemy, no loot,
            // HP 150, exhausts hidden.
            int[] ships = { 2, 23, 2 };
            foreach (int s in ships)
            {
                var p = campaign.SpawnShip(GoF2Standing.Pirate, s, new Vector3(50000, 50000, 50000), false,
                                           spec => { spec.inactive = true; spec.alwaysEnemy = true; spec.noLoot = true; spec.hitpoints = 150; });
                p.SetVisible(false);
                p.SetExhaust(false);
            }
            // Player at (0, 0, -60 000) facing +Z, computer-controlled; camera (-1000, -500, -40 000) looking at it.
            Player.SetPositionAndRotation(ToUnity(new Vector3(0, 0, -60000)), Quaternion.LookRotation(Dir(new Vector3(0, 0, 1)), Vector3.up));
            cam.LookAt(new Vector3(-1000, -500, -40000), Player);
            campaign.PlayMusic(assets?.introAtmo, true);   // MenuTouchWindow::startGOF2: 143 IntroAtmo
            Step = 0;
        }

        void BuildRescue()
        {
            // The salvager: Midorian ship 30 at (300, 50, -6000), heading for the Phantom, asleep, engines off.
            var g = campaign.SpawnShip(3, 30, new Vector3(300, 50, -6000), false, spec => { spec.inactive = true; spec.alwaysFriend = true; spec.nameText = 1599; });
            g.Place(ToUnity(new Vector3(300, 50, -6000)), Dir(new Vector3(0, 0, 1)));
            g.SetExhaust(false);
            g.SetEngineSound(false);
            // Player frozen at the origin, rotation (0.462, 0.462, 1.5339) rad, exhaust off; camera (1500, 1600, -3000).
            Player.SetPositionAndRotation(Vector3.zero, GoF2OrbitLayout.RotationToUnity(new Vector3(0.462f, 0.462f, 1.5339f)));
            SetPlayerExhaust(false);
            playerSpeed = 0f;
            cam.LookAt(new Vector3(1500, 1600, -3000), Player);
            campaign.Fade(true, Color.black, 5000f, fromOpaque: true);
            Step = 0;
        }

        void SetPlayerExhaust(bool on)
        {
            var asm = Ship.visualModel != null ? Ship.visualModel.GetComponent<GoF2AssembledObject>() : null;
            asm?.SetExhaust(on, true);
        }

        void SetPlayerVisible(bool on)
        {
            if (Ship.visualModel != null) Ship.visualModel.gameObject.SetActive(on);
        }

        bool Over(int line) => campaign.Radio != null && campaign.Radio.Over(line);
        bool Triggered(int line) => campaign.Radio != null && campaign.Radio.Triggered(line);

        // ---- per frame ----------------------------------------------------------------------------------------

        public void Tick(float dtMs)
        {
            stepMs += dtMs;
            if (fx != null) fxMs += dtMs;
            if (index == 0) TickPrologue(dtMs); else TickRescue(dtMs);
            // Computer-controlled flight: straight on at the script's speed.
            if (Ship.externalControl)
            {
                Player.position += Player.forward * playerSpeed * dtMs * M;
                Ship.ExternalSpeedMetersPerSecond = playerSpeed * 1000f * M;
            }
        }

        public void LateTick(float dtMs)
        {
            cam.LateTick(dtMs);
            if (fx != null && cam.Camera != null) fx.transform.rotation = cam.Camera.rotation;   // billboarded to the camera
        }

        void TickPrologue(float dtMs)
        {
            var pirates = campaign.Ships;
            switch (Step)
            {
                case 0:
                    if (Over(2))
                    {
                        Player.position = ToUnity(new Vector3(18000, -3000, -40000));
                        cam.LookAt(new Vector3(-3000, 2000, -500), Player);
                        Vector3[] at = { new Vector3(-10000, 500, 0), new Vector3(-10000, -300, -1700), new Vector3(-10000, -200, 2000) };
                        for (int i = 0; i < 3 && i < pirates.Count; i++)
                        {
                            pirates[i].Place(ToUnity(at[i]), Vector3.right);   // facing +X
                            pirates[i].SetVisible(true);
                            bobBase[i] = ToUnity(at[i]);
                        }
                        Step = 1;
                    }
                    break;
                case 1:
                case 2:
                    // While step < 3 the pirates bob (getPulseValue(0.0005) - 0.5).
                    for (int i = 0; i < 3 && i < pirates.Count; i++)
                        pirates[i].transform.position = bobBase[i] + Vector3.up * (Mathf.Sin(Time.time * Mathf.PI * 2f * 0.5f + i) * 0.5f) * 200f * M;
                    if (Step == 1 && Over(6))
                    {
                        if (pirates.Count > 0) cam.LookAt(new Vector3(-5000, 300, -5000), pirates[0].transform);
                        campaign.PlayMusic(assets?.battleFull, true);   // music stop, 142
                        cam.SetDolly(new Vector3(0.2f, 0f, 2.2f));
                        Step = 2;
                    }
                    else if (Step == 2 && Over(7))
                    {
                        foreach (var p in pirates) { p.SetExhaust(true); p.SetVisible(true); p.Wake(); }
                        cam.SetDolly(Vector3.zero);
                        Step = 3;
                    }
                    break;
                case 3:
                    if (Over(8))
                    {
                        // Player control: radar, collision, HUD; the start sequence is over (the steering briefing opens).
                        Ship.externalControl = false;
                        if (level.Weapons != null) level.Weapons.Blocked = false;
                        campaign.Cutscene = false;
                        campaign.CollisionOff = false;
                        campaign.StartSequenceOver = true;
                        cam.Release();
                        Step = 4;
                    }
                    break;
                case 4:
                    if (Over(10))
                    {
                        // The pirates are dead: back to the cutscene, guns off, facing +X, camera out to the side.
                        campaign.PlayMusic(assets?.introAtmo, true);
                        campaign.Cutscene = true;
                        campaign.CollisionOff = true;
                        Ship.externalControl = true;
                        playerSpeed = 2f;
                        if (level.Weapons != null) level.Weapons.Blocked = true;
                        Player.rotation = Quaternion.LookRotation(Vector3.right, Vector3.up);
                        cam.LookAtUnity(Player.position + ToUnity(new Vector3(25000, -200, -1000)), Player);
                        soundsPlayed = false;
                        Step = 5;
                    }
                    break;
                case 5:
                    if (!soundsPlayed && Over(12))
                    {
                        // "Activating hyperdrive": the explosion and rumble at the ship, the broken engine, slowing down.
                        soundsPlayed = true;
                        GoF2Sfx.PlayAt(assets?.cutsceneExplosion, Player.position);
                        campaign.PlayLoop(0, assets?.rumble);
                        campaign.PlayLoop(1, assets?.engineBroken);
                    }
                    if (soundsPlayed) playerSpeed *= Mathf.Pow(0.98f, dtMs / 33.3f);
                    if (Over(13)) cam.SetDolly(new Vector3(-0.2f, 0f, 0.3f));
                    if (Triggered(14)) Step = 6;
                    break;
                case 6:
                    playerSpeed *= Mathf.Pow(0.98f, dtMs / 33.3f);
                    cam.Rumble = Mathf.Min(1f, stepMs / 4000f);
                    if (Over(15))
                    {
                        SpawnFx(Player.position);
                        GoF2Sfx.PlayAt(assets?.timeJump, Player.position);   // 160
                        campaign.StopLoop(1);
                        Step = 7;
                    }
                    break;
                case 7:
                    if (stepMs >= 2000f && Ship.visualModel != null && Ship.visualModel.gameObject.activeSelf)
                    {
                        campaign.StopLoop(0);
                        SetPlayerVisible(false);
                        cam.Rumble = 0f;
                        playerSpeed = 0f;
                    }
                    if (fx == null || fxMs >= fxLength)
                    {
                        campaign.PlayMusic(assets?.timeShift, false);   // music stop, 141
                        Step = 8;
                    }
                    break;
                case 8:
                    cam.Rumble = Mathf.Max(1f - stepMs / 3000f, 0f);
                    if (stepMs >= 4000f)
                    {
                        HideFx();
                        Step = 9;
                    }
                    break;
                case 9:
                {
                    // Out of the belt: the intro sky and planet switch, the asteroids gone; the ship at the origin.
                    if (assets != null && assets.introSkyAfterJump != null) { RenderSettings.skybox = assets.introSkyAfterJump; DynamicGI.UpdateEnvironment(); }
                    level.Backdrop?.SwitchOrbitPlanetForIntro();
                    if (level.Asteroids != null) Object.Destroy(level.Asteroids.gameObject);
                    Player.SetPositionAndRotation(Vector3.zero, Quaternion.LookRotation(Dir(new Vector3(0, 0, -1)), Vector3.up));
                    Player.Rotate(45f, 45f, 45f, Space.Self);
                    cam.LookAt(new Vector3(5000, 500, -10000), Player);
                    Step = 10;
                    break;
                }
                case 10:
                    cam.Rumble = Mathf.Min(1f, stepMs / 2000f);
                    if (stepMs >= 2000f)
                    {
                        GoF2Sfx.PlayAt(assets?.timeJumpEnd, Player.position);   // 159
                        SpawnFx(Player.position);
                        Step = 11;
                    }
                    break;
                case 11:
                    cam.Rumble = Mathf.Max(1f - stepMs / 2500f, 0f);
                    if (stepMs >= 2500f)
                    {
                        // The broken ship drifts out: visible, broken engine, no exhaust, speed 2.
                        SetPlayerVisible(true);
                        SetPlayerExhaust(false);
                        campaign.PlayLoop(2, assets?.engineBrokenLoop);
                        playerSpeed = 2f;
                        cam.Rumble = 0f;
                        Step = 12;
                    }
                    break;
                case 12:
                    Tumble(dtMs / 3000f);
                    if (Over(17)) { cam.LookAtUnity(Player.position + ToUnity(new Vector3(-2000, -2000, -5000)), Player); Step = 13; }
                    break;
                case 13:
                    Tumble(dtMs / 4000f);
                    if (stepMs >= 6000f) { cam.LookAtUnity(Player.position + ToUnity(new Vector3(700, 0, -1700)), Player); Step = 14; }
                    break;
                case 14:
                    Tumble(dtMs / 5000f);
                    cam.SetDolly(new Vector3(-2f, 0f, 0f));
                    if (stepMs >= 12000f) { cam.LookAtUnity(Player.position + ToUnity(new Vector3(-3000, 3500, -6700)), Player); Step = 15; }
                    break;
                case 15:
                    if (Over(22)) { campaign.Fade(false, Color.black, 5000f); Step = 16; }
                    break;
                case 16:
                    if (!loading && campaign.FadeDone)
                    {
                        // nextCampaignMission (-> 1) and a new flight level: the rescue.
                        loading = true;
                        GoF2Story.Advance(level.Database);
                        GoF2Session.LaunchedFromStation = GoF2Session.ArrivedByTravel = false;
                        SceneManager.LoadScene(SceneManager.GetActiveScene().name);
                    }
                    break;
            }
        }

        void TickRescue(float dtMs)
        {
            // The Phantom turns slowly (rotate(0, a, a), a = (2dt & ~15) / 65536 * 2pi), the camera drifts (0.1dt, 0, 0), the
            // salvager slows as it arrives (0.2dt * min(z / -5000, 1)).
            float a = ((int)(2f * dtMs) & ~15) / 65536f * 360f;
            Player.Rotate(0f, a, a, Space.Self);
            cam.SetDolly(new Vector3(0.1f, 0f, 0f));
            if (campaign.Ships.Count > 0)
            {
                var g = campaign.Ships[0].transform;
                float z = -g.position.z / M;   // game z
                g.position += g.forward * (0.2f * dtMs * Mathf.Min(z / -5000f, 1f)) * M;
            }
            switch (Step)
            {
                case 0:
                    if (Over(2)) { campaign.Fade(false, Color.black, 5000f); Step = 1; }
                    break;
                case 1:
                    if (!loading && campaign.FadeDone)
                    {
                        // Module 5: docked at Var Hastra; the index-1 mission completes there (the first conversation).
                        loading = true;
                        level.Dock();
                    }
                    break;
            }
        }

        /// <summary>The drifting wreck turns (rotate(dt / 3000) ...); only the model, so the drift stays straight.</summary>
        void Tumble(float rad)
        {
            var t = Ship.visualModel != null ? Ship.visualModel : Player;
            t.Rotate(rad * Mathf.Rad2Deg, rad * Mathf.Rad2Deg, rad * Mathf.Rad2Deg, Space.Self);
        }

        void SpawnFx(Vector3 at)
        {
            HideFx();
            if (assets == null || assets.hyperDrive == null) { fxLength = 2000f; fxMs = 0f; return; }
            fx = Object.Instantiate(assets.hyperDrive, at, cam.Camera != null ? cam.Camera.rotation : Quaternion.identity);
            float len = GoF2PartAnimation.PlayOnce(fx);
            fxLength = len > 0f ? len : 3000f;
            fxMs = 0f;
        }

        void HideFx()
        {
            if (fx != null) Object.Destroy(fx);
            fx = null;
        }
    }
}
