package net.fishlabs.gof2hdallandroid2012;

import android.content.Context;

/* JADX INFO: loaded from: classes.dex */
final class ToJNI {
    protected static final int MESSAGE_CHECK_CONNECTION = 10;
    protected static final int MESSAGE_EXIT_APP = 20;
    protected static final int MESSAGE_FREE_CREDITS_FOLLOW_ON_TWITTER = 45;
    protected static final int MESSAGE_FREE_CREDITS_LIKE_FISHLABS = 43;
    protected static final int MESSAGE_FREE_CREDITS_LIKE_GOF2 = 42;
    protected static final int MESSAGE_FREE_CREDITS_RATE_GAME = 46;
    protected static final int MESSAGE_FREE_CREDITS_SUBSCRIBE_YOUTUBE_CHANNEL = 44;
    protected static final int MESSAGE_FREE_CREDITS_WATCH_VIDEO = 41;
    protected static final int MESSAGE_RATE_GAME = 48;
    protected static final int MESSAGE_SET_BRIGHTNESS = 30;
    protected static final int MESSAGE_SHOW_MORE_GAMES = 47;
    protected static final int MESSAGE_SHOW_PRIVACY_POLICY = 50;
    protected static final int MESSAGE_SHOW_TERMS_OF_SERVICE = 49;

    protected static native synchronized void BackButtonPressed();

    protected static native synchronized void SetDirectories(String str, String str2);

    protected static native synchronized void correctBoughtDLC1(int i);

    protected static native synchronized void correctBoughtDLC2(int i);

    protected static native synchronized void correctBoughtDLC3(int i);

    protected static native synchronized void correctBoughtDLC4(int i);

    protected static native synchronized void correctBoughtDLC5(int i);

    protected static native synchronized int getDLC1BOUGHT();

    protected static native synchronized int getDLC2BOUGHT();

    protected static native synchronized int getDLC3BOUGHT();

    protected static native synchronized int getDLC4BOUGHT();

    protected static native synchronized int getDLC5BOUGHT();

    protected static native synchronized int getExitFlag();

    protected static native synchronized int getLogoShown();

    protected static native synchronized int getScreenshotFlag();

    protected static native synchronized void handleAccelerometer(float f, float f2, float f3);

    protected static native synchronized void handleTouchEvent(int i, int i2, int i3, int i4);

    protected static native synchronized void initialize(int i, int i2);

    protected static native synchronized int isInMainMenu();

    protected static native synchronized void renderstep(long j);

    protected static native synchronized void resetScreenshotFlag();

    protected static native synchronized void resize(int i, int i2);

    protected static native synchronized void sendPauseSignalToGame();

    protected static native synchronized void sendResumeSignalToGame();

    protected static native synchronized void setAPKPath(String str);

    protected static native synchronized void setCountryCodeOfDevice(int i);

    protected static native synchronized void setEnvironmentVariables(Context context);

    protected static native synchronized void setZIPPath(String str);

    protected static native synchronized void testPurchase(int i);

    ToJNI() {
    }
}
