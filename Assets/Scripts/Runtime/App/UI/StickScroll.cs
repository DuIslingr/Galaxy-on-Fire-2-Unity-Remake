// StickScroll.cs
// Remake (#169): the controller's right stick, up and down, scrolls the long texts the focus never moves through: the
// lounge's dialogue and the shop's and the item window's descriptions. It moves the scroll view on screen whose content
// overflows and which doesn't hold the focus (a list the focus moves through scrolls to it by itself, and moving it away
// with the stick was snapped back); of several, the last in the document (a window over a page). Left and right stay the
// hangar's ship turning (StationMenu, ItemInfoWindow): a stick pushed more sideways than up or down scrolls nothing. The
// hosts call Watch with their document's root (MainMenu, StationMenu) and say when the stick is theirs (not while Inspect
// ship's camera has it). The flight HUD and the star map are left out: the right stick steers and turns the map there.

using System;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class StickScroll
    {
        const string Watched = "gof-stick-scroll-watched";
        const float DeadZone = 0.2f, Speed = 900f;   // panel units a second with the stick all the way

        static readonly List<ScrollView> views = new List<ScrollView>();

        /// <summary>The right stick scrolls this document's texts while 'active' (null = always) says so.</summary>
        public static void Watch(VisualElement root, Func<bool> active = null)
        {
            if (root == null || root.ClassListContains(Watched)) return;
            root.AddToClassList(Watched);
            int frame = -1;
            root.schedule.Execute(() =>
            {
                if (frame == Time.frameCount) return;   // once a frame
                frame = Time.frameCount;
                Tick(root, active);
            }).Every(0);
        }

        static void Tick(VisualElement root, Func<bool> active)
        {
            var pad = Gamepad.current;
            if (pad == null || root.panel == null) return;
            var s = pad.rightStick.ReadValue();
            float y = Mathf.Abs(s.y);
            if (y < DeadZone || y < Mathf.Abs(s.x)) return;
            if (active != null && !active()) return;
            var view = Pick(root, root.panel.focusController?.focusedElement as VisualElement);
            if (view == null) return;
            float max = ScrollMax(view);
            float step = Mathf.Sign(s.y) * (y - DeadZone) / (1f - DeadZone) * Speed * Time.unscaledDeltaTime;
            var offset = view.scrollOffset;
            view.scrollOffset = new Vector2(offset.x, Mathf.Clamp(offset.y - step, 0f, max));   // stick up: toward the top
        }

        /// <summary>The scroll view the stick moves: shown, overflowing, without the focus; the last of them; null = none.</summary>
        public static ScrollView Pick(VisualElement root, VisualElement focused)
        {
            views.Clear();
            root.Query<ScrollView>().ToList(views);
            for (int i = views.Count - 1; i >= 0; i--)
            {
                var v = views[i];
                if (v.mode == ScrollViewMode.Horizontal || ScrollMax(v) < 1f || !Shown(v)) continue;
                if (focused != null && v.Contains(focused)) continue;
                return v;
            }
            return null;
        }

        static float ScrollMax(ScrollView v)
        {
            float content = v.contentContainer.layout.height, viewport = v.contentViewport.layout.height;
            return float.IsNaN(content) || float.IsNaN(viewport) ? 0f : Mathf.Max(0f, content - viewport);
        }

        /// <summary>On screen: neither it nor a parent hidden or faded out.</summary>
        static bool Shown(VisualElement e)
        {
            if (!e.enabledInHierarchy || e.worldBound.height < 1f) return false;
            for (; e != null; e = e.parent)
            {
                var st = e.resolvedStyle;
                if (st.display == DisplayStyle.None || st.visibility == Visibility.Hidden || st.opacity < 0.01f) return false;
            }
            return true;
        }
    }
}
