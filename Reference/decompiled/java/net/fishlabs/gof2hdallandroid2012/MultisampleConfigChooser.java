package net.fishlabs.gof2hdallandroid2012;

import android.opengl.GLSurfaceView;
import android.util.Log;
import javax.microedition.khronos.egl.EGL10;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.egl.EGLDisplay;

/* JADX INFO: loaded from: classes.dex */
public class MultisampleConfigChooser implements GLSurfaceView.EGLConfigChooser {
    private static final String kTag = "GDC11";
    private int[] mValue;

    @Override // android.opengl.GLSurfaceView.EGLConfigChooser
    public EGLConfig chooseConfig(EGL10 egl10, EGLDisplay eGLDisplay) {
        int[] iArr;
        this.mValue = new int[1];
        int[] iArr2 = {12324, 5, 12323, 6, 12322, 5, 12325, 16, 12352, 4, 12338, 1, 12337, 2, 12344};
        if (!egl10.eglChooseConfig(eGLDisplay, iArr2, null, 0, this.mValue)) {
            throw new IllegalArgumentException("eglChooseConfig failed");
        }
        int i = this.mValue[0];
        if (i <= 0) {
            int[] iArr3 = {12324, 5, 12323, 6, 12322, 5, 12325, 16, 12352, 4, 12512, 1, 12513, 2, 12344};
            if (!egl10.eglChooseConfig(eGLDisplay, iArr3, null, 0, this.mValue)) {
                throw new IllegalArgumentException("2nd eglChooseConfig failed");
            }
            i = this.mValue[0];
            if (i <= 0) {
                iArr3 = new int[]{12324, 5, 12323, 6, 12322, 5, 12325, 16, 12352, 4, 12344};
                if (!egl10.eglChooseConfig(eGLDisplay, iArr3, null, 0, this.mValue)) {
                    throw new IllegalArgumentException("3rd eglChooseConfig failed");
                }
                i = this.mValue[0];
                if (i <= 0) {
                    throw new IllegalArgumentException("No configs match configSpec");
                }
            }
            iArr = iArr3;
        } else {
            iArr = iArr2;
        }
        int i2 = i;
        EGLConfig[] eGLConfigArr = new EGLConfig[i2];
        if (!egl10.eglChooseConfig(eGLDisplay, iArr, eGLConfigArr, i2, this.mValue)) {
            throw new IllegalArgumentException("data eglChooseConfig failed");
        }
        int i3 = 0;
        while (true) {
            if (i3 >= eGLConfigArr.length) {
                i3 = -1;
                break;
            }
            if (findConfigAttrib(egl10, eGLDisplay, eGLConfigArr[i3], 12324, 0) == 5) {
                break;
            }
            i3++;
        }
        if (i3 == -1) {
            Log.w(kTag, "Did not find sane config, using first");
        }
        EGLConfig eGLConfig = eGLConfigArr.length > 0 ? eGLConfigArr[i3] : null;
        if (eGLConfig == null) {
            throw new IllegalArgumentException("No config chosen");
        }
        return eGLConfig;
    }

    private int findConfigAttrib(EGL10 egl10, EGLDisplay eGLDisplay, EGLConfig eGLConfig, int i, int i2) {
        return egl10.eglGetConfigAttrib(eGLDisplay, eGLConfig, i, this.mValue) ? this.mValue[0] : i2;
    }
}
