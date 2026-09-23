package net.fishlabs.gof2hdallandroid2012;

import android.opengl.GLSurfaceView;
import javax.microedition.khronos.egl.EGL10;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.egl.EGLContext;
import javax.microedition.khronos.egl.EGLDisplay;

/* JADX INFO: loaded from: classes.dex */
public class ConfigChooser implements GLSurfaceView.EGLConfigChooser {
    private static final byte CONFIGURATION_QUALITY = 99;
    private static final int MAX_ANTIALIASING = 0;
    private int alpha_channel = 0;
    private int antialiasing_channel = 0;
    private int blue_channel = 0;
    private int chosenConfigIndex = 0;
    private int depth_channel = 0;
    private int green_channel = 0;
    private int red_channel = 0;
    private static int EGL_OPENGL_ES2_BIT = 4;
    private static int[] minimumConfiguration = {12324, 4, 12323, 4, 12322, 4, 12321, 0, 12337, 0, 12325, 16, 12352, EGL_OPENGL_ES2_BIT, 12344};

    @Override // android.opengl.GLSurfaceView.EGLConfigChooser
    public EGLConfig chooseConfig(EGL10 egl10, EGLDisplay eGLDisplay) {
        EGL10 egl11 = (EGL10) EGLContext.getEGL();
        EGLDisplay eGLDisplayEglGetDisplay = egl11.eglGetDisplay(EGL10.EGL_DEFAULT_DISPLAY);
        int[] iArr = new int[1];
        egl11.eglChooseConfig(eGLDisplayEglGetDisplay, minimumConfiguration, null, 0, iArr);
        int i = iArr[0];
        if (i <= 0) {
            throw new IllegalArgumentException("NO EGL CONFIGRATION FOUND");
        }
        EGLConfig[] eGLConfigArr = new EGLConfig[i];
        egl11.eglChooseConfig(eGLDisplayEglGetDisplay, minimumConfiguration, eGLConfigArr, i, iArr);
        int[] iArr2 = new int[1];
        int[] iArr3 = new int[1];
        int[] iArr4 = new int[1];
        int[] iArr5 = new int[1];
        int[] iArr6 = new int[1];
        int[] iArr7 = new int[1];
        int[] iArr8 = new int[1];
        for (int i2 = 0; i2 < i && eGLConfigArr[i2] != null; i2++) {
            egl11.eglGetConfigAttrib(eGLDisplayEglGetDisplay, eGLConfigArr[i2], 12324, iArr2);
            egl11.eglGetConfigAttrib(eGLDisplayEglGetDisplay, eGLConfigArr[i2], 12322, iArr3);
            egl11.eglGetConfigAttrib(eGLDisplayEglGetDisplay, eGLConfigArr[i2], 12323, iArr4);
            egl11.eglGetConfigAttrib(eGLDisplayEglGetDisplay, eGLConfigArr[i2], 12321, iArr6);
            egl11.eglGetConfigAttrib(eGLDisplayEglGetDisplay, eGLConfigArr[i2], 12325, iArr5);
            egl11.eglGetConfigAttrib(eGLDisplayEglGetDisplay, eGLConfigArr[i2], 12328, iArr7);
            egl11.eglGetConfigAttrib(eGLDisplayEglGetDisplay, eGLConfigArr[i2], 12337, iArr8);
            if (iArr2[0] >= this.red_channel && iArr4[0] >= this.green_channel && iArr3[0] >= this.blue_channel && iArr6[0] >= this.alpha_channel && iArr5[0] >= this.depth_channel && iArr8[0] >= this.antialiasing_channel && iArr8[0] <= 0) {
                this.red_channel = iArr2[0];
                this.green_channel = iArr4[0];
                this.blue_channel = iArr3[0];
                this.alpha_channel = iArr6[0];
                this.depth_channel = iArr5[0];
                this.antialiasing_channel = iArr8[0];
                this.chosenConfigIndex = i2;
            }
        }
        return eGLConfigArr[this.chosenConfigIndex];
    }
}
