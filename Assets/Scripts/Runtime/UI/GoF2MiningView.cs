// GoF2MiningView.cs
// The flight HUD's mining visuals (Reference/research/mining.md 3.1 and 4.7), driven by GoF2FlightHud:
//   lock ring    image 0x456, 24 frames around the crosshair, filling while the lock builds up
//   lock plate   0x4c4 at the top with the class letter (0x44e frame 7 - quality) and the ore name
//   messages     the HUD message queue (Hud::hudEvent / catchCargo): "Target: Asteroid", "12t Gold", ...
//   minigame     MiningGame::render2D: rock layers as discs from four mirrored quadrant images (finished layers vanish),
//                the core (class A), drill ring + 10-frame bit at the drill, energy bar (flickers red when low) with its
//                label and two scrolling data strips, the depth strip and the ore amount next to the drill (red when it
//                exceeds the free cargo, fades in on every new ton). Centre = (w / 2, h / 2 + 30), HD pixels = panel units.
// Images come from Resources/GoF2Hud (GoF2 > Build HUD Images).

using System.Collections.Generic;
using GoF2Remake.Flight;
using UnityEngine;
using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    public class GoF2MiningView
    {
        const float CenterOffsetY = 30f;   // Layout+0xd0
        const float BarY = 74f;            // Layout+0xd8
        const float BarWidth = 388f;

        readonly VisualElement overlay, lockRing, lockPlate, lockClass, messages;
        readonly Label lockOre;
        readonly VisualElement discRoot, core, drillRing, drillBit, energyFrame, energyClip, energyFill, energyLabel;
        readonly VisualElement stripRed, stripOrange, depthStrip, oreBox;
        readonly Label oreText;
        readonly Texture2D[] lockFrames = new Texture2D[24], classFrames = new Texture2D[5], drillFrames = new Texture2D[10];
        readonly List<VisualElement> discs = new List<VisualElement>();
        GoF2MiningGame builtFor;
        Texture2D coreTex;
        float frameAcc, redOffset, orangeOffset, depthOffset, oreAlpha = 1f;
        int drillFrame;

        static Texture2D Tex(string name) => Resources.Load<Texture2D>("GoF2Hud/" + name);

        public GoF2MiningView(VisualElement root)
        {
            for (int i = 0; i < 24; i++) lockFrames[i] = Tex($"lock_{i:00}");
            for (int i = 0; i < 5; i++) classFrames[i] = Tex($"class_{i:00}");
            for (int i = 0; i < 10; i++) drillFrames[i] = Tex($"drill_{i:00}");
            lockRing = root.Q("lockRing");
            lockPlate = root.Q("lockPlate");
            lockClass = root.Q("lockClass");
            lockOre = root.Q<Label>("lockOre");
            messages = root.Q("hudMessages");
            overlay = root.Q("mining");
            SetImage(lockPlate, Tex("plate"));

            discRoot = Add(overlay, null);
            core = Add(overlay, null);
            drillRing = Add(overlay, Tex("drill_ring"));
            drillBit = Add(overlay, null);
            energyFrame = Add(overlay, Tex("energy_frame"));
            energyClip = Add(overlay, null);
            energyClip.style.overflow = Overflow.Hidden;
            energyFill = Add(energyClip, Tex("energy_fill"));
            energyLabel = Add(overlay, Tex("energy_label"));
            stripRed = Strip(overlay, "strip_red", 40f);
            stripOrange = Strip(overlay, "strip_orange", 40f);
            depthStrip = Strip(overlay, "strip_blue", 100f);
            oreBox = Add(overlay, Tex("ore_box"));
            oreText = new Label { pickingMode = PickingMode.Ignore };
            oreText.AddToClassList("mining-ore");
            oreText.AddToClassList("gof-semibold");
            overlay.Add(oreText);
        }

        static VisualElement Add(VisualElement parent, Texture2D tex)
        {
            var e = new VisualElement { pickingMode = PickingMode.Ignore };
            e.style.position = Position.Absolute;
            SetImage(e, tex);
            parent.Add(e);
            return e;
        }

        static void SetImage(VisualElement e, Texture2D tex)
        {
            if (tex == null) return;
            e.style.backgroundImage = new StyleBackground(tex);
            e.style.width = tex.width;
            e.style.height = tex.height;
        }

        /// <summary>A MarqueeImage: the strip scrolls through a fixed window (repeating background).</summary>
        static VisualElement Strip(VisualElement parent, string name, float window)
        {
            var tex = Tex(name);
            var e = Add(parent, null);
            if (tex == null) return e;
            e.style.backgroundImage = new StyleBackground(tex);
            e.style.width = window;
            e.style.height = tex.height;
            e.style.backgroundRepeat = new BackgroundRepeat(Repeat.Repeat, Repeat.NoRepeat);
            e.style.backgroundSize = new BackgroundSize(new Length(tex.width, LengthUnit.Pixel), new Length(tex.height, LengthUnit.Pixel));
            return e;
        }

        static void Scroll(VisualElement strip, float offset) =>
            strip.style.backgroundPositionX = new BackgroundPosition(BackgroundPositionKeyword.Left, new Length(-offset, LengthUnit.Pixel));

        static void Place(VisualElement e, float x, float y)
        {
            e.style.left = x;
            e.style.top = y;
        }

        // ---- messages ------------------------------------------------------------------------------------------

        /// <summary>Hud message queue: each line stays 3 s (at most 4 at a time).</summary>
        /// <param name="colour">Hud::drawEventQueue colours: 0 white, 1 red (255, 42, 0), 2 green (0, 237, 0).</param>
        public void ShowMessage(string text, int colour = 0)
        {
            if (messages == null || string.IsNullOrEmpty(text)) return;
            var l = new Label(text) { pickingMode = PickingMode.Ignore };
            l.AddToClassList("hud-message");
            if (colour == 1) l.AddToClassList("hud-message--red");
            else if (colour == 2) l.AddToClassList("hud-message--green");
            l.AddToClassList("gof-semibold");
            messages.Add(l);
            while (messages.childCount > 4) messages.RemoveAt(0);
            l.schedule.Execute(() => l.AddToClassList("hud-message--fade")).ExecuteLater(2600);
            l.schedule.Execute(() => l.RemoveFromHierarchy()).ExecuteLater(3000);
        }

        // ---- lock --------------------------------------------------------------------------------------------

        /// <summary>Ring on the crosshair ('crosshairLeft/Top' = its position in the shared parent) and the ore plate.</summary>
        public void UpdateLock(GoF2Mining mining, StyleLength crosshairLeft, StyleLength crosshairTop, bool crosshairVisible)
        {
            bool idle = mining == null || mining.State == GoF2Mining.Phase.Idle;
            int frame = mining != null && idle && crosshairVisible ? mining.LockFrame : -1;
            lockRing.EnableInClassList("lock-ring--shown", frame >= 0);
            if (frame >= 0)
            {
                lockRing.style.left = crosshairLeft;
                lockRing.style.top = crosshairTop;
                SetImage(lockRing, lockFrames[Mathf.Clamp(frame, 0, 23)]);
            }

            // Radar::drawCurrentLock: the plate while an asteroid is locked, kept during the approach (hidden in the minigame).
            var target = mining == null ? null : idle ? mining.Locked : mining.Target;
            lockPlate.EnableInClassList("lock-plate--shown", target != null && mining.State != GoF2Mining.Phase.Mining);
            if (target != null)
            {
                SetImage(lockClass, classFrames[Mathf.Clamp(7 - target.quality, 0, 4)]);
                lockOre.text = GoF2ItemInfo.ItemName(target.oreItem);
            }
        }

        // ---- minigame ------------------------------------------------------------------------------------------

        public void UpdateGame(GoF2Mining mining, float dtMs)
        {
            var game = mining != null && mining.State == GoF2Mining.Phase.Mining ? mining.Game : null;
            overlay.EnableInClassList("mining--shown", game != null);
            if (game == null) { builtFor = null; return; }
            float w = overlay.layout.width, h = overlay.layout.height;
            if (!(w > 0f)) return;
            if (builtFor != game) Build(game);

            var c = new Vector2(w / 2f, h / 2f + CenterOffsetY);
            for (int i = 0; i < discs.Count; i++)
            {
                discs[i].style.display = i >= game.Layer ? DisplayStyle.Flex : DisplayStyle.None;   // finished layers vanish
                float r = game.RadiusOf(i);
                Place(discs[i], c.x - r, c.y - r);
            }
            if (coreTex != null) Place(core, c.x - coreTex.width / 2f, c.y - coreTex.height / 2f);

            // Drill: ring + bit (a new frame at 2 * LAYER_SPEEDS * 3 frames/s while inside).
            var p = c + game.Drill;
            Place(drillRing, p.x - 40.5f, p.y - 40.5f);
            if (game.Inside)
            {
                frameAcc += dtMs / 1000f * 2f * GoF2MiningGame.LayerSpeeds[game.Layer] * 3f;
                if (frameAcc >= 1f) { drillFrame = (drillFrame + 1) % 10; frameAcc = 0f; }
                depthOffset += dtMs / 1000f * 2f * GoF2MiningGame.LayerSpeeds[game.Layer];
            }
            SetImage(drillBit, drillFrames[drillFrame]);
            Place(drillBit, p.x - 33f, p.y - 33f);

            // Energy bar: frame, fill cut to the energy left, fast red flicker once a third is gone.
            float barX = w / 2f - BarWidth / 2f;
            Place(energyFrame, barX - 10f, BarY - 10f);
            Place(energyClip, barX, BarY);
            energyClip.style.width = BarWidth * game.Energy01;
            energyClip.style.height = 14f;
            float pulse = game.OutsideMs >= 834f ? Mathf.Abs(Mathf.Sin(Time.unscaledTime * 1000f * 10f)) : 1f;
            energyFill.style.unityBackgroundImageTintColor = new Color(1f, pulse, pulse);
            Place(energyLabel, c.x - 13.5f, BarY - 3f - 8f);

            // Data strips (20 / 32 px/s) and the depth strip beside the drill.
            redOffset += dtMs / 1000f * 20f;
            orangeOffset += dtMs / 1000f * 32f;
            Place(stripRed, barX, BarY + 19f);
            Place(stripOrange, barX + BarWidth - 40f, BarY + 19f);
            Scroll(stripRed, redOffset);
            Scroll(stripOrange, orangeOffset);
            Place(depthStrip, p.x + 45f, p.y - 18f);
            Scroll(depthStrip, depthOffset);

            // Ore amount "12t": red when more than the hold takes, fades in over 500 ms after every new ton.
            Place(oreBox, p.x + 35f, p.y - 4f);
            oreAlpha = Mathf.Min(1f, oreAlpha + dtMs / 500f);
            oreText.text = $"{game.OreAmount}t";
            var col = game.OreAmount > mining.FreeCargo ? new Color(1f, 42f / 255f, 0f) : Color.white;
            col.a = game.Inside ? oreAlpha : 1f;
            oreText.style.color = col;
            Place(oreText, p.x + 35f, p.y - 4f);
        }

        void Build(GoF2MiningGame game)
        {
            builtFor = game;
            discRoot.Clear();
            discs.Clear();
            game.NewTon += () => oreAlpha = 0f;
            for (int i = 0; i < game.LayerCount; i++)
            {
                float r = game.RadiusOf(i), size = r * 2f;
                string parity = i % 2 == 0 ? "even" : "odd";
                var tex = Tex($"disc_{parity}_{(size >= 400f ? "l" : size > 80f ? "m" : "s")}");
                var disc = Add(discRoot, null);
                disc.style.width = disc.style.height = size;
                // Four mirrored copies of the top-left quarter (MiningGame::render2D pivots 0x22 / 0x21 / 0x12 / 0x11).
                for (int q = 0; q < 4; q++)
                {
                    var quarter = Add(disc, null);
                    if (tex != null) quarter.style.backgroundImage = new StyleBackground(tex);
                    quarter.style.width = quarter.style.height = r;
                    quarter.style.left = q % 2 == 0 ? 0f : r;
                    quarter.style.top = q < 2 ? 0f : r;
                    quarter.style.scale = new Scale(new Vector3(q % 2 == 0 ? 1f : -1f, q < 2 ? 1f : -1f, 1f));
                }
                discs.Add(disc);
            }
            coreTex = game.HasCore ? Tex(game.OreItem == 164 ? "core_void" : "core") : null;
            core.style.display = coreTex != null ? DisplayStyle.Flex : DisplayStyle.None;
            SetImage(core, coreTex);
            frameAcc = redOffset = orangeOffset = depthOffset = 0f;
            oreAlpha = 1f;
        }
    }
}
