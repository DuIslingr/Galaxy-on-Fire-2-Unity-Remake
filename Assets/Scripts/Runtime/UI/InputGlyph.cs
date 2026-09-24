// InputGlyph.cs
// Small UI Toolkit elements that show an input: a keyboard keycap or an Xbox-style controller button (the game
// always uses Xbox labels, whatever pad is connected). Styled by UI/GoF2InputGlyphs.uss (.keycap, .pad-*).

using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    public enum PadButton { A, B, X, Y, LeftStick, RightStick, DPad, LeftTrigger, RightTrigger, LeftBumper, RightBumper, Menu, View }

    public static class InputGlyph
    {
        public static VisualElement Key(string text, bool wide = false)
        {
            var l = Text(text, "keycap");
            if (wide) l.AddToClassList("keycap--wide");
            return l;
        }

        public static VisualElement Pad(PadButton button) => button switch
        {
            PadButton.A => Face("A", "pad-face--a"),
            PadButton.B => Face("B", "pad-face--b"),
            PadButton.X => Face("X", "pad-face--x"),
            PadButton.Y => Face("Y", "pad-face--y"),
            PadButton.LeftStick => Text("LS", "pad-stick"),
            PadButton.RightStick => Text("RS", "pad-stick"),
            PadButton.DPad => Text("D-PAD", "pad-menu"),
            PadButton.LeftTrigger => Text("LT", "pad-trigger"),
            PadButton.RightTrigger => Text("RT", "pad-trigger"),
            PadButton.LeftBumper => Text("LB", "pad-bumper"),
            PadButton.RightBumper => Text("RB", "pad-bumper"),
            PadButton.View => Text("VIEW", "pad-menu"),
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
