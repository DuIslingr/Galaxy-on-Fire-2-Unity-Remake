// DragScroll.cs
// Drag-to-scroll for ScrollViews with the mouse or a pen, with momentum after release, like the original's inertial
// list scrolling (MenuTouchWindow: damping 0.9 per frame). Scrolling only starts after a small threshold, so clicks on
// buttons inside the list still count. Fingers are left to the ScrollView's own touch scrolling (two handlers moving
// the same list fought after the release: the list jumped back).
// PointerActive: a pointer pressed, moved or wheeled over a list in this or the last frame. Focus changes then come
// from the pointer (a tap, the hover focus), and the menus don't scroll the focused row into view for them
// (ScrollTo against the layout of a list that is moving snapped it back).

using UnityEngine;
using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    public class DragScroll : PointerManipulator
    {
        const float StartThreshold = 12f;     // panel units before a press becomes a drag
        const float Damping = 0.9f;           // velocity kept per 60 Hz frame after release

        readonly ScrollView scroll;
        int pointerId = -1;
        Vector2 startPos, lastPos;
        float startOffset, velocity;
        bool dragging;
        IVisualElementScheduledItem inertia;

        static int lastPointerFrame = -10;

        /// <summary>A pointer acted on a list this frame or the last: the focus follows the pointer, don't ScrollTo.</summary>
        public static bool PointerActive => Time.frameCount - lastPointerFrame <= 1;

        /// <summary>A pointer event outside a DragScroll list (a menu's root) counts too.</summary>
        public static void NotePointer() => lastPointerFrame = Time.frameCount;

        public DragScroll(ScrollView scrollView)
        {
            scroll = scrollView;
            target = scrollView;
            scroll.touchScrollBehavior = ScrollView.TouchScrollBehavior.Clamped;
        }

        protected override void RegisterCallbacksOnTarget()
        {
            target.RegisterCallback<PointerDownEvent>(OnDown, TrickleDown.TrickleDown);
            target.RegisterCallback<PointerMoveEvent>(OnMove, TrickleDown.TrickleDown);
            target.RegisterCallback<PointerUpEvent>(OnUp, TrickleDown.TrickleDown);
            target.RegisterCallback<PointerCancelEvent>(OnCancel);
            target.RegisterCallback<WheelEvent>(_ => { lastPointerFrame = Time.frameCount; inertia?.Pause(); }, TrickleDown.TrickleDown);
        }

        protected override void UnregisterCallbacksFromTarget()
        {
            target.UnregisterCallback<PointerDownEvent>(OnDown, TrickleDown.TrickleDown);
            target.UnregisterCallback<PointerMoveEvent>(OnMove, TrickleDown.TrickleDown);
            target.UnregisterCallback<PointerUpEvent>(OnUp, TrickleDown.TrickleDown);
            target.UnregisterCallback<PointerCancelEvent>(OnCancel);
        }

        float MaxOffset => Mathf.Max(0f, scroll.contentContainer.layout.height - scroll.contentViewport.layout.height);

        void OnDown(PointerDownEvent e)
        {
            lastPointerFrame = Time.frameCount;
            if (pointerId >= 0 || e.pointerType == UnityEngine.UIElements.PointerType.touch) return;
            inertia?.Pause();
            pointerId = e.pointerId;
            startPos = lastPos = e.position;
            startOffset = scroll.scrollOffset.y;
            velocity = 0f;
            dragging = false;
        }

        void OnMove(PointerMoveEvent e)
        {
            lastPointerFrame = Time.frameCount;
            if (e.pointerId != pointerId) return;
            Vector2 p = e.position;
            if (!dragging)
            {
                if (Mathf.Abs(p.y - startPos.y) < StartThreshold) return;
                dragging = true;
                target.CapturePointer(pointerId);   // from here on the list owns the gesture
            }
            float dy = p.y - lastPos.y;
            velocity = Mathf.Lerp(velocity, -dy, 0.5f);
            lastPos = p;
            SetOffset(startOffset - (p.y - startPos.y));
            e.StopImmediatePropagation();   // also keeps the ScrollView's own touch handling from doubling it
        }

        void OnUp(PointerUpEvent e)
        {
            if (e.pointerId != pointerId) return;
            if (dragging)
            {
                target.ReleasePointer(pointerId);
                e.StopImmediatePropagation();   // a drag is not a click
                StartInertia();
            }
            pointerId = -1;
            dragging = false;
        }

        void OnCancel(PointerCancelEvent e)
        {
            if (e.pointerId != pointerId) return;
            if (target.HasPointerCapture(pointerId)) target.ReleasePointer(pointerId);
            pointerId = -1;
            dragging = false;
        }

        void StartInertia()
        {
            inertia?.Pause();
            inertia = scroll.schedule.Execute(t =>
            {
                float frames = t.deltaTime / 16.67f;
                velocity *= Mathf.Pow(Damping, frames);
                SetOffset(scroll.scrollOffset.y + velocity * frames);
                if (Mathf.Abs(velocity) < 0.2f) inertia.Pause();
            }).Every(16);
        }

        void SetOffset(float y) => scroll.scrollOffset = new Vector2(scroll.scrollOffset.x, Mathf.Clamp(y, 0f, MaxOffset));
    }
}
