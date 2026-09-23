package net.fishlabs.gof2hdallandroid2012;

import android.support.v4.view.MotionEventCompat;
import android.view.MotionEvent;

/* JADX INFO: loaded from: classes.dex */
public class TouchHandler {
    private static final int _NEIGHBORHOOD = 5;
    private static final int _POINTER_ID_ADD = 722;
    private static final int _POINTER_INFORMATION_CAPACITY = 20;
    private static _pointerInformation[] pointerInformation;
    private final float xScaler;
    private final float yScaler;

    private class _pointerInformation {
        private int X;
        private int Y;

        void setID(int i) {
        }

        _pointerInformation() {
            this.X = 0;
            this.Y = 0;
            this.X = -1;
            this.Y = -1;
        }

        int getX() {
            return this.X;
        }

        int getY() {
            return this.Y;
        }

        void setX(int i) {
            this.X = i;
        }

        void setY(int i) {
            this.Y = i;
        }
    }

    public TouchHandler(float f, float f2) {
        this.xScaler = f;
        this.yScaler = f2;
        pointerInformation = new _pointerInformation[20];
        for (int i = 0; i < pointerInformation.length; i++) {
            pointerInformation[i] = new _pointerInformation();
        }
        GOF2HD2012.getGLView().getWidth();
        GOF2HD2012.getGLView().getHeight();
    }

    protected boolean process(MotionEvent motionEvent) {
        try {
            int action = motionEvent.getAction() & 255;
            int pointerCount = motionEvent.getPointerCount();
            if (pointerCount >= pointerInformation.length) {
                return false;
            }
            switch (action) {
                case 0:
                case 5:
                    int action2 = (motionEvent.getAction() & MotionEventCompat.ACTION_POINTER_INDEX_MASK) >> 8;
                    int pointerId = motionEvent.getPointerId(action2) + _POINTER_ID_ADD;
                    int x = (int) (motionEvent.getX(action2) * this.xScaler);
                    int y = (int) (motionEvent.getY(action2) * this.yScaler);
                    int i = pointerId - 722;
                    pointerInformation[i].setID(pointerId);
                    pointerInformation[i].setX(x);
                    pointerInformation[i].setY(y);
                    ToJNI.handleTouchEvent(pointerId, 0, x, y);
                    return true;
                case 1:
                case 6:
                    int action3 = (motionEvent.getAction() & MotionEventCompat.ACTION_POINTER_INDEX_MASK) >> 8;
                    int pointerId2 = motionEvent.getPointerId(action3) + _POINTER_ID_ADD;
                    int x2 = (int) (motionEvent.getX(action3) * this.xScaler);
                    int y2 = (int) (motionEvent.getY(action3) * this.yScaler);
                    int i2 = pointerId2 - 722;
                    pointerInformation[i2].setID(-1);
                    pointerInformation[i2].setX(-1);
                    pointerInformation[i2].setY(-1);
                    ToJNI.handleTouchEvent(pointerId2, 1, x2, y2);
                    if (action == 1) {
                        for (int i3 = 0; i3 < pointerInformation.length; i3++) {
                            pointerInformation[i3].setID(-1);
                            pointerInformation[i3].setX(-1);
                            pointerInformation[i3].setY(-1);
                        }
                    }
                    return true;
                case 2:
                    for (int i4 = 0; i4 < pointerCount; i4++) {
                        int pointerId3 = motionEvent.getPointerId(i4) + _POINTER_ID_ADD;
                        int x3 = (int) (motionEvent.getX(i4) * this.xScaler);
                        int y3 = (int) (motionEvent.getY(i4) * this.yScaler);
                        int i5 = pointerId3 - 722;
                        if (Math.abs(pointerInformation[i5].getX() - x3) > -1 && Math.abs(pointerInformation[i5].getY() - y3) > -1) {
                            ToJNI.handleTouchEvent(pointerId3, 2, x3, y3);
                        }
                    }
                    return true;
                case 3:
                case 4:
                default:
                    return true;
            }
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }
}
