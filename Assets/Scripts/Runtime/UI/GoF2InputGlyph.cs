// GoF2InputGlyph.cs
// Small UI Toolkit elements that show an input: a keyboard keycap or an Xbox-style controller button (the game
// always uses Xbox labels, whatever pad is connected). Styled by UI/GoF2InputGlyphs.uss (.keycap, .pad-*).

using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    public enum GoF2PadButton { A, B, X, Y, LeftStick, RightStick, DPad, LeftTrigger, RightTrigger, LeftBumper, RightBumper, Menu }

    public static class GoF2InputGlyph
    {
        public static VisualElement Key(string text, bool wide = false)
        {
            var l = Text(text, "keycap");
            if (wide) l.AddToClassList("keycap--wide");
            return l;
        }

        public static VisualElement Pad(GoF2PadButton button) => button switch
        {
            GoF2PadButton.A => Face("A", "pad-face--a"),
            GoF2PadButton.B => Face("B", "pad-face--b"),
            GoF2PadButton.X => Face("X", "pad-face--x"),
            GoF2PadButton.Y => Face("Y", "pad-face--y"),
            GoF2PadButton.LeftStick => Text("LS", "pad-stick"),
            GoF2PadButton.RightStick => Text("RS", "pad-stick"),
            GoF2PadButton.DPad => Text("D-PAD", "pad-menu"),
            GoF2PadButton.LeftTrigger => Text("LT", "pad-trigger"),
            GoF2PadButton.RightTrigger => Text("RT", "pad-trigger"),
            GoF2PadButton.LeftBumper => Text("LB", "pad-bumper"),
            GoF2PadButton.RightBumper => Text("RB", "pad-bumper"),
            _ => Text("MENU", "pad-menu"),
        };

        static VisualElement Face(string letter, string colour)
        {
            var l = Text(letter, "pad-face");
            l.AddToClassList(colour);
            return l;
        }

        static Label Text(string text, string cls)
        {
            var l = new Label(text) { pickingMode = PickingMode.Ignore };
            l.AddToClassList(cls);
            l.AddToClassList("gof-semibold");
            return l;
        }
    }
}
