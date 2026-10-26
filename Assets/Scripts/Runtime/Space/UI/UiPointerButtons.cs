using UnityEngine.InputSystem;
using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    /// <summary>Keep a mouse drag alive while its real button is held, even if a UI move omits its pressed-button mask.
    /// Event state still counts: movement is delivered before release. Keep releases from the current input update too,
    /// so a final move with an empty mask reaches the drag before its up event.
    /// Touch/pen events must only use their own state, never an unrelated mouse's buttons.</summary>
    public static class UiPointerButtons
    {
        public static bool PrimaryHeld(IPointerEvent e) => (Held(e) & 1) != 0;
        public static bool AnyHeld(IPointerEvent e) => Held(e) != 0;

        static int Held(IPointerEvent e)
        {
            int buttons = e.pressedButtons;
            if (e.pointerType != UnityEngine.UIElements.PointerType.mouse || e.pointerId != PointerId.mousePointerId) return buttons;
            var mouse = Mouse.current;
            if (mouse == null) return buttons;
            if (mouse.leftButton.wasReleasedThisFrame || mouse.leftButton.isPressed) buttons |= 1;
            if (mouse.rightButton.wasReleasedThisFrame || mouse.rightButton.isPressed) buttons |= 2;
            if (mouse.middleButton.wasReleasedThisFrame || mouse.middleButton.isPressed) buttons |= 4;
            return buttons;
        }
    }
}
