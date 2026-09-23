package net.fishlabs.gof2hdallandroid2012;

import android.content.Context;
import android.content.res.Configuration;
import android.graphics.Bitmap;
import android.opengl.EGL14;
import android.opengl.GLSurfaceView;
import android.os.Environment;
import android.os.Message;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.ShortBuffer;
import java.util.Calendar;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/* JADX INFO: loaded from: classes.dex */
public class GLViewRenderer implements GLSurfaceView.Renderer {
    private static Context CONTEXT = null;
    private static GOF2HD2012 GOFContext = null;
    private static final boolean _USE_FPS_LIMITER = true;
    private static final long frameRate = 33;
    private static GL10 gl10 = null;
    private static boolean initialized = false;
    private static final boolean justRender = false;
    private static final Messenger printLog = new Messenger();
    private static boolean setSystemTime = true;
    private static int surface_height = 0;
    private static int surface_width = 0;
    private static long systemTime = 0;
    private static long waitingTime = 10000;
    Configuration myStartConfig = new Configuration();
    private final boolean switchSoundMode = false;
    private final boolean switchSoundStateSwitched = false;

    private static native void setKeyboardStatus(int i);

    protected static GOF2HD2012 getContext() {
        return GOFContext;
    }

    public static void StoreScreenshot() {
        int i = surface_width;
        int i2 = surface_height;
        int i3 = i * i2;
        ByteBuffer byteBufferAllocateDirect = ByteBuffer.allocateDirect(i3 * 4);
        byteBufferAllocateDirect.order(ByteOrder.nativeOrder());
        gl10.glReadPixels(0, 0, i, i2, 6408, 5121, byteBufferAllocateDirect);
        int[] iArr = new int[i3];
        byteBufferAllocateDirect.asIntBuffer().get(iArr);
        Bitmap bitmapCreateBitmap = Bitmap.createBitmap(i, i2, Bitmap.Config.RGB_565);
        bitmapCreateBitmap.setPixels(iArr, i3 - i, -i, 0, 0, i, i2);
        short[] sArr = new short[i3];
        ShortBuffer shortBufferWrap = ShortBuffer.wrap(sArr);
        bitmapCreateBitmap.copyPixelsToBuffer(shortBufferWrap);
        for (int i4 = 0; i4 < i3; i4++) {
            short s = sArr[i4];
            sArr[i4] = (short) (((s & 63488) >> 11) | ((s & 31) << 11) | (s & 2016));
        }
        shortBufferWrap.rewind();
        bitmapCreateBitmap.copyPixelsFromBuffer(shortBufferWrap);
        try {
            Calendar calendar = Calendar.getInstance();
            int i5 = calendar.get(13);
            int i6 = calendar.get(12);
            int i7 = calendar.get(11);
            int i8 = calendar.get(5);
            int i9 = calendar.get(2);
            int i10 = calendar.get(1);
            StringBuilder sb = new StringBuilder();
            sb.append("");
            sb.append(i10);
            sb.append(i9 < 10 ? "0" + i9 : Integer.valueOf(i9));
            sb.append(i8 < 10 ? "0" + i8 : Integer.valueOf(i8));
            sb.append("_");
            sb.append(i7 < 10 ? "0" + i7 : Integer.valueOf(i7));
            sb.append(i6 < 10 ? "0" + i6 : Integer.valueOf(i6));
            sb.append(i5 < 10 ? "0" + i5 : Integer.valueOf(i5));
            sb.append(")");
            String string = sb.toString();
            File externalStoragePublicDirectory = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES);
            externalStoragePublicDirectory.mkdir();
            File file = new File(externalStoragePublicDirectory + "/GOF2HD");
            if (!file.exists()) {
                file.mkdir();
            }
            try {
                FileOutputStream fileOutputStream = new FileOutputStream(new File(file + "/GOF2HD_" + string + ".png"));
                bitmapCreateBitmap.compress(Bitmap.CompressFormat.PNG, 100, fileOutputStream);
                System.out.println("StoreScreenshot Success");
                fileOutputStream.close();
            } catch (IOException e) {
                System.out.println("StoreScreenshot Error1 " + e.toString());
            }
        } catch (Exception e2) {
            System.out.println("StoreScreenshot Error2 " + e2.toString());
        }
    }

    public GLViewRenderer(Context context) {
        CONTEXT = context;
        GOFContext = (GOF2HD2012) GOF2HD2012.class.cast(CONTEXT);
    }

    @Override // android.opengl.GLSurfaceView.Renderer
    public void onDrawFrame(GL10 gl11) {
        long jCurrentTimeMillis = System.currentTimeMillis();
        if (setSystemTime) {
            systemTime = System.currentTimeMillis();
            setSystemTime = false;
        }
        if (GOF2HD2012._USE_GOOGLEPLAY && Math.abs(systemTime - jCurrentTimeMillis) >= waitingTime) {
            int dlc1bought = ToJNI.getDLC1BOUGHT();
            int dlc2bought = ToJNI.getDLC2BOUGHT();
            int dlc3bought = ToJNI.getDLC3BOUGHT();
            int dlc4bought = ToJNI.getDLC4BOUGHT();
            int dlc5bought = ToJNI.getDLC5BOUGHT();
            boolean dlc_1_bought = GOF2HD2012.getStaticIAP().getDLC_1_BOUGHT();
            boolean dlc_2_bought = GOF2HD2012.getStaticIAP().getDLC_2_BOUGHT();
            boolean dlc_3_bought = GOF2HD2012.getStaticIAP().getDLC_3_BOUGHT();
            boolean dlc_4_bought = GOF2HD2012.getStaticIAP().getDLC_4_BOUGHT();
            boolean dlc_5_bought = GOF2HD2012.getStaticIAP().getDLC_5_BOUGHT();
            if (dlc1bought == 0 && dlc_1_bought) {
                ToJNI.correctBoughtDLC1(1);
            }
            if (dlc1bought == 1 && !dlc_1_bought) {
                ToJNI.correctBoughtDLC1(0);
            }
            if (dlc2bought == 0 && dlc_2_bought) {
                ToJNI.correctBoughtDLC2(1);
            }
            if (dlc2bought == 1 && !dlc_2_bought) {
                ToJNI.correctBoughtDLC2(0);
            }
            if (dlc3bought == 0 && dlc_3_bought) {
                ToJNI.correctBoughtDLC3(1);
            }
            if (dlc3bought == 1 && !dlc_3_bought) {
                ToJNI.correctBoughtDLC3(0);
            }
            if (dlc4bought == 0 && dlc_4_bought) {
                ToJNI.correctBoughtDLC4(1);
            }
            if (dlc4bought == 1 && !dlc_4_bought) {
                ToJNI.correctBoughtDLC4(0);
            }
            if (dlc5bought == 0 && dlc_5_bought) {
                ToJNI.correctBoughtDLC5(1);
            }
            if (dlc5bought == 1 && !dlc_5_bought) {
                ToJNI.correctBoughtDLC5(0);
            }
            setSystemTime = true;
        }
        if (ToJNI.getExitFlag() == -1 && GOFContext != null) {
            try {
                Message messageObtain = Message.obtain();
                messageObtain.setTarget(GOFContext.mHandler);
                messageObtain.what = 20;
                messageObtain.sendToTarget();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        if (ToJNI.getScreenshotFlag() == 1) {
            printLog.printWarning("TAKE SCREENSHOT");
            ToJNI.resetScreenshotFlag();
            StoreScreenshot();
        }
        GOFContext.reportLeaderboardsAndAchievements();
        GOFContext.checkGooglePlayGamesServiceAppFlags();
        try {
            ToJNI.renderstep(System.currentTimeMillis());
        } catch (Exception e2) {
            e2.printStackTrace();
        }
        long jCurrentTimeMillis2 = System.currentTimeMillis() - jCurrentTimeMillis;
        if (jCurrentTimeMillis2 < 0) {
            try {
                Thread.sleep(0 - jCurrentTimeMillis2);
            } catch (InterruptedException e3) {
                e3.printStackTrace();
            }
        }
    }

    @Override // android.opengl.GLSurfaceView.Renderer
    public void onSurfaceChanged(GL10 gl11, int i, int i2) {
        printLog.printInformation("Surface changing... width: " + i + " height: " + i2);
        if (!initialized) {
            printLog.printInformation("Initializing Engine...");
            try {
                printLog.printInformation("Surface initializing... width: " + i + " height: " + i2);
                ToJNI.initialize(i, i2);
            } catch (Exception e) {
                e.printStackTrace();
            }
            initialized = true;
        }
        ToJNI.resize(i, i2);
        printLog.printInformation("Resizing...");
        surface_width = i;
        surface_height = i2;
        try {
            EGL14.eglSurfaceAttrib(EGL14.eglGetCurrentDisplay(), EGL14.eglGetCurrentSurface(12377), 12435, 12436);
        } catch (Throwable th) {
        }
    }

    @Override // android.opengl.GLSurfaceView.Renderer
    public void onSurfaceCreated(GL10 gl11, EGLConfig eGLConfig) {
        printLog.printInformation("Surface created");
        gl10 = gl11;
        GOF2HD2012._surface_created = true;
        ToJNI.setEnvironmentVariables(CONTEXT);
        try {
            EGL14.eglSurfaceAttrib(EGL14.eglGetCurrentDisplay(), EGL14.eglGetCurrentSurface(12377), 12435, 12436);
        } catch (Throwable th) {
        }
    }
}
