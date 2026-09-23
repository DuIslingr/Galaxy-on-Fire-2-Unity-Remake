package net.fishlabs.gof2hdallandroid2012;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.view.MotionEvent;

/* JADX INFO: loaded from: classes.dex */
class GLView extends GLSurfaceView implements AccelerometerListener {
    private static Context CONTEXT;
    protected static boolean useScaling = false;

    public GLView(Context context) {
        super(context);
        CONTEXT = context;
        init();
    }

    private void init() {
        setEGLContextFactory(new ContextFactory());
        setEGLConfigChooser(new ConfigChooser());
        setRenderer(new GLViewRenderer(CONTEXT));
    }

    @Override // net.fishlabs.gof2hdallandroid2012.AccelerometerListener
    public void onAccelerationChanged(float x, float y, float z) {
        ToJNI.handleAccelerometer(y, -x, z);
    }

    @Override // android.opengl.GLSurfaceView
    public void onPause() {
        super.onPause();
    }

    @Override // android.opengl.GLSurfaceView
    public void onResume() {
        super.onResume();
    }

    @Override // net.fishlabs.gof2hdallandroid2012.AccelerometerListener
    public void onShake(float force) {
    }

    @Override // android.view.View
    public boolean onTouchEvent(MotionEvent ev) {
        if (GOF2HD2012._surface_created) {
            return GOF2HD2012.touchHandler.process(ev);
        }
        return false;
    }
}
