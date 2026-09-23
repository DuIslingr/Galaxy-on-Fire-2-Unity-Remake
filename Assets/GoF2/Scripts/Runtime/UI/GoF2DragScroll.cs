// GoF2DragScroll.cs
// Drag-to-scroll for ScrollViews with any pointer (finger, mouse, pen), with momentum after release, like
// the original's inertial list scrolling (MenuTouchWindow: damping 0.9 per frame). Scrolling only starts
// after a small threshold, so taps on buttons inside the list still count as clicks.

using UnityEngine;
using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    public class GoF2DragScroll : PointerManipulator
    {
        const float StartThreshold = 12f;     // panel units before a press becomes a drag
        const float Damping = 0.9f;           // velocity kept per 60 Hz frame after release

        readonly ScrollView scroll;
        int pointerId = -1;
        Vector2 startPos, lastPos;
        float startOffset, velocity;
        bool dragging;
        IVisualElementScheduledItem inertia;

        public GoF2DragScroll(ScrollView scrollView)
        {
            scroll = scrollView;
            target = scrollView;
        }

        protected override void RegisterCallbacksOnTarget()
        {
            target.RegisterCallback<PointerDownEvent>(OnDown, TrickleDown.TrickleDown);
            target.RegisterCallback<PointerMoveEvent>(OnMove, TrickleDown.TrickleDown);
            target.RegisterCallback<PointerUpEvent>(OnUp, TrickleDown.TrickleDown);
            target.RegisterCallback<PointerCancelEvent>(OnCancel);
            target.RegisterCallback<WheelEvent>(_ => inertia?.Pause());
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
            if (pointerId >= 0) return;
            inertia?.Pause();
            pointerId = e.pointerId;
            startPos = lastPos = e.position;
            startOffset = scroll.scrollOffset.y;
            velocity = 0f;
            dragging = false;
        }

        void OnMove(PointerMoveEvent e)
        {
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
