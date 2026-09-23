package net.fishlabs.gof2hdallandroid2012;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.KeyguardManager;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.content.res.Configuration;
import android.media.AudioManager;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.os.Process;
import android.os.StrictMode;
import android.provider.Settings;
import android.support.v4.view.MotionEventCompat;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import com.google.android.gms.games.Games;
import com.setting.setting;
import java.io.File;
import java.util.Locale;
import net.fishlabs.googleplay.BaseGameActivity;
import net.fishlabs.googleplay.GooglePlayIAP;
import net.fishlabs.ow_utils.DeviceInfo;

/* JADX INFO: loaded from: classes.dex */
public class GOF2HD2012 extends BaseGameActivity implements View.OnSystemUiVisibilityChangeListener {
    private static final int DIALOG_EXIT_ID = 0;
    protected static boolean _USE_GOOGLEPLAY = true;
    protected static boolean _surface_created = false;
    protected static AudioManager audio = null;
    protected static int currentVolume = 0;
    private static boolean firstResume = false;
    private static GooglePlayIAP gpiap = null;
    private static KeyguardManager kgMgr = null;
    private static LocalizationService ls = null;
    private static GLView mGLView = null;
    private static final String packageName = "net.fishlabs.gof2hdallandroid2012";
    private static GOF2HD2012 staticGOF2;
    protected static TouchHandler touchHandler;
    private boolean googleServicesPlayLinked = false;
    private final Handler looperHandler = new Handler(Looper.getMainLooper());
    private final boolean looperPrepared = false;
    public Handler mHandler = new Handler() { // from class: net.fishlabs.gof2hdallandroid2012.GOF2HD2012.1
        @Override // android.os.Handler
        public void handleMessage(Message message) {
            int i = message.what;
            if (i == 20) {
                GOF2HD2012.this.exitApp();
            }
            switch (i) {
                case MotionEventCompat.AXIS_GENERIC_10 /* 41 */:
                    String strValueOf = String.valueOf("http://www.youtube.com/watch?feature=player_embedded&v=hN4K_5dppjU");
                    Intent intent = new Intent("android.intent.action.VIEW", Uri.parse(strValueOf));
                    intent.setDataAndType(Uri.parse(strValueOf), "video/mp4");
                    GOF2HD2012.this.startActivity(intent);
                    break;
                case MotionEventCompat.AXIS_GENERIC_11 /* 42 */:
                    GOF2HD2012.this.startActivity(new Intent("android.intent.action.VIEW", Uri.parse("https://www.facebook.com/fishlabs")));
                    break;
                case MotionEventCompat.AXIS_GENERIC_12 /* 43 */:
                    GOF2HD2012.this.startActivity(new Intent("android.intent.action.VIEW", Uri.parse("https://www.facebook.com/fishlabs")));
                    break;
                case MotionEventCompat.AXIS_GENERIC_13 /* 44 */:
                    GOF2HD2012.this.startActivity(new Intent("android.intent.action.VIEW", Uri.parse("http://www.youtube.com/user/fishlabsgames")));
                    break;
                case MotionEventCompat.AXIS_GENERIC_14 /* 45 */:
                    GOF2HD2012.this.startActivity(new Intent("android.intent.action.VIEW", Uri.parse("https://twitter.com/dsfishlabs")));
                    break;
                case MotionEventCompat.AXIS_GENERIC_15 /* 46 */:
                    Intent intent2 = new Intent("android.intent.action.VIEW");
                    intent2.setData(Uri.parse("market://details?id=net.fishlabs.gof2hdallandroid2012"));
                    GOF2HD2012.this.startActivity(intent2);
                    break;
                case MotionEventCompat.AXIS_GENERIC_16 /* 47 */:
                    GOF2HD2012.this.startActivity(new Intent("android.intent.action.VIEW", Uri.parse("market://search?q=pub:\"Deep Silver\"")));
                    break;
                case 48:
                    Intent intent3 = new Intent("android.intent.action.VIEW");
                    intent3.setData(Uri.parse("market://details?id=net.fishlabs.gof2hdallandroid2012"));
                    GOF2HD2012.this.startActivity(intent3);
                    break;
                case 49:
                    GOF2HD2012.this.startActivity(new Intent("android.intent.action.VIEW", Uri.parse("https://www.dsfishlabs.com/terms_of_services")));
                    break;
                case 50:
                    GOF2HD2012.this.startActivity(new Intent("android.intent.action.VIEW", Uri.parse("https://www.dsfishlabs.com/privacy_policy")));
                    break;
            }
        }
    };
    final int RC_RESOLVE = 5000;
    final int RC_UNUSED = 5001;

    protected static native synchronized int GetAchievementId(int i);

    protected static native synchronized int GetLeaderboardScore(int i);

    protected static native synchronized int GetLinkGameGP();

    protected static native synchronized int GetShowAchievements();

    protected static native synchronized int GetShowLeaderboards();

    protected static native synchronized void ReleaseOrigamiSuperClub(String str);

    protected static native synchronized void ResetAchievements();

    protected static native synchronized int ResetLeaderboardScore(int i);

    protected static native synchronized void ResetLinkGameGP();

    protected static native synchronized void ResetShowAchievements();

    protected static native synchronized void ResetShowLeaderboards();

    protected static native synchronized void SetGPIsLinked(int i);

    protected static native synchronized void SetOrigamiSuperClub(String str);

    public void exitApp() {
        finish();
    }

    @Override // android.app.Activity, android.view.KeyEvent.Callback
    public boolean onKeyDown(int i, KeyEvent keyEvent) {
        return false;
    }

    static {
        System.loadLibrary("fmodex");
        System.loadLibrary("fmodevent");
        System.loadLibrary("gof2hdaa");
    }

    public static Activity getActivity() {
        return staticGOF2;
    }

    public static GLView getGLView() {
        return mGLView;
    }

    public static Context getGOFContext() {
        if (staticGOF2 != null) {
            return staticGOF2.getApplicationContext();
        }
        return null;
    }

    public static GooglePlayIAP getStaticIAP() {
        if (gpiap != null) {
            return gpiap;
        }
        return null;
    }

    public void checkGooglePlayGamesServiceAppFlags() {
        if (GetShowAchievements() > 0) {
            if (isSignedIn()) {
                startActivityForResult(Games.Achievements.getAchievementsIntent(getApiClient()), 5001);
            }
            ResetShowAchievements();
        }
        if (GetShowLeaderboards() > 0) {
            if (isSignedIn()) {
                startActivityForResult(Games.Leaderboards.getAllLeaderboardsIntent(getApiClient()), 5001);
            }
            ResetShowLeaderboards();
        }
        if (GetLinkGameGP() > 0) {
            this.looperHandler.post(new Runnable() { // from class: net.fishlabs.gof2hdallandroid2012.GOF2HD2012.2
                @Override // java.lang.Runnable
                public void run() {
                    GOF2HD2012.this.beginUserInitiatedSignIn();
                }
            });
            ResetLinkGameGP();
        }
    }

    private void checkGooglePlayLogin() {
        if (isSignedIn()) {
            SetGPIsLinked(1);
            this.googleServicesPlayLinked = true;
        } else {
            SetGPIsLinked(0);
            this.googleServicesPlayLinked = false;
        }
    }

    public GooglePlayIAP getNonStatic0IAP() {
        if (gpiap != null) {
            return gpiap;
        }
        return null;
    }

    @Override // android.support.v4.app.FragmentActivity, android.app.Activity, android.content.ComponentCallbacks
    public void onConfigurationChanged(Configuration configuration) {
        super.onConfigurationChanged(configuration);
    }

    @Override // net.fishlabs.googleplay.BaseGameActivity, android.support.v4.app.FragmentActivity, android.support.v4.app.SupportActivity, android.app.Activity
    public void onCreate(Bundle bundle) {
        super.onCreate(bundle);
        Intent intent = getIntent();
        ls = new LocalizationService();
        staticGOF2 = this;
        kgMgr = (KeyguardManager) getSystemService("keyguard");
        NativeFunctionCalls.Gof2Activity = this;
        String str = intent.getStringExtra(DownloaderActivity.INTENT_EXTERNAL_FILES_DIR) + File.separator;
        String stringExtra = intent.getStringExtra(DownloaderActivity.INTENT_EXTERNAL_OBB_DIR);
        ToJNI.setZIPPath(stringExtra + intent.getStringExtra(DownloaderActivity.INTENT_EXTERNAL_MAIN_OBB_FILE_NAME));
        getWindow().setFlags(128, 128);
        getWindow().setFlags(1024, 1024);
        setSystemUiVisibilityMode();
        getWindow().getDecorView().setOnSystemUiVisibilityChangeListener(this);
        mGLView = new GLView(this);
        int displayWidth = DeviceInfo.getDisplayWidth();
        int displayHeight = DeviceInfo.getDisplayHeight();
        float f = displayWidth;
        float f2 = displayHeight;
        float f3 = displayWidth;
        float f4 = (f2 / f3) * f;
        float fMin = Math.min(displayWidth, displayHeight);
        if (!DeviceInfo.isPad() && fMin > 640.0f) {
            float f5 = 640.0f / fMin;
        }
        float finalScreenScale = setting.getFinalScreenScale(f);
        float finalScreenScale2 = setting.getFinalScreenScale(f4);
        mGLView.getHolder().setFixedSize((int) finalScreenScale, (int) finalScreenScale2);
        setContentView(mGLView);
        getWindow().takeSurface(null);
        mGLView.setKeepScreenOn(true);
        audio = (AudioManager) getSystemService("audio");
        currentVolume = audio.getStreamVolume(3);
        touchHandler = new TouchHandler(setting.getFinalTouchXSclalle(finalScreenScale / f3), setting.getFinalTouchYSclalle(finalScreenScale2 / f2));
        if (Build.VERSION.SDK_INT > 9) {
            StrictMode.setThreadPolicy(new StrictMode.ThreadPolicy.Builder().permitAll().build());
        }
        ToJNI.SetDirectories(str, stringExtra);
        try {
            ToJNI.setAPKPath(getApplication().getPackageManager().getApplicationInfo("net.fishlabs.gof2hdallandroid2012", 0).sourceDir);
            setCountry(Locale.getDefault().getLanguage(), Locale.getDefault().getCountry());
            if (_USE_GOOGLEPLAY) {
                gpiap = new GooglePlayIAP(this, this, getPackageName());
            }
            checkGooglePlayLogin();
            Settings.Secure.getString(getContentResolver(), "android_id");
            SetOrigamiSuperClub("9506fe987e36474d");
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
            throw new RuntimeException("Unable to locate assets, aborting...");
        }
    }

    @Override // android.app.Activity
    protected Dialog onCreateDialog(int i) {
        String messages = ls.getMessages(LocalizationService.MessageCodes.MESSAGE_QUIT);
        String messages2 = ls.getMessages(LocalizationService.MessageCodes.MESSAGE_YES);
        String messages3 = ls.getMessages(LocalizationService.MessageCodes.MESSAGE_NO);
        if (i != 0) {
            return null;
        }
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setMessage(messages).setCancelable(false).setPositiveButton(messages2, new DialogInterface.OnClickListener() { // from class: net.fishlabs.gof2hdallandroid2012.GOF2HD2012.4
            @Override // android.content.DialogInterface.OnClickListener
            public void onClick(DialogInterface dialogInterface, int i2) {
                GOF2HD2012.this.finish();
                if (GOF2HD2012._USE_GOOGLEPLAY && GOF2HD2012.gpiap.isSetUp()) {
                    GOF2HD2012.gpiap.destroy();
                }
                Process.killProcess(Process.myPid());
            }
        }).setNegativeButton(messages3, new DialogInterface.OnClickListener() { // from class: net.fishlabs.gof2hdallandroid2012.GOF2HD2012.3
            @Override // android.content.DialogInterface.OnClickListener
            public void onClick(DialogInterface dialogInterface, int i2) {
                dialogInterface.cancel();
            }
        });
        return builder.create();
    }

    @Override // android.support.v4.app.FragmentActivity, android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        Settings.Secure.getString(getContentResolver(), "android_id");
        ReleaseOrigamiSuperClub("9506fe987e36474d");
        if (AccelerometerManager.isListening()) {
            AccelerometerManager.stopListening();
        }
        if (_USE_GOOGLEPLAY && !gpiap.isSetUp()) {
            gpiap.destroy();
        }
        finish();
        Process.killProcess(Process.myPid());
    }

    @Override // android.app.Activity, android.view.KeyEvent.Callback
    public boolean onKeyUp(int i, KeyEvent keyEvent) {
        if (i != 4) {
            return false;
        }
        if (ToJNI.getLogoShown() == 1 || ToJNI.isInMainMenu() == 1) {
            exitApp();
            return true;
        }
        ToJNI.BackButtonPressed();
        return true;
    }

    @Override // android.support.v4.app.FragmentActivity, android.app.Activity
    protected void onPause() {
        if (AccelerometerManager.isListening()) {
            AccelerometerManager.stopListening();
        }
        ToJNI.sendPauseSignalToGame();
        super.onPause();
    }

    @Override // net.fishlabs.googleplay.BaseGameActivity, android.support.v4.app.FragmentActivity, android.app.Activity
    protected void onResume() {
        super.onResume();
        if (!kgMgr.inKeyguardRestrictedInputMode()) {
            if (!firstResume) {
                firstResume = true;
            } else {
                ToJNI.sendResumeSignalToGame();
            }
        }
        if (AccelerometerManager.isSupported()) {
            AccelerometerManager.startListening(mGLView);
        }
    }

    @Override // net.fishlabs.googleplay.BaseGameActivity, android.support.v4.app.FragmentActivity, android.app.Activity
    protected void onStart() {
        super.onStart();
    }

    @Override // net.fishlabs.googleplay.BaseGameActivity, android.support.v4.app.FragmentActivity, android.app.Activity
    protected void onStop() {
        super.onStop();
    }

    @Override // android.app.Activity
    public boolean onTouchEvent(MotionEvent motionEvent) {
        if (_surface_created) {
            return touchHandler.process(motionEvent);
        }
        return false;
    }

    @Override // android.app.Activity, android.view.Window.Callback
    public void onWindowFocusChanged(boolean z) {
        if (z) {
            setSystemUiVisibilityMode();
        }
    }

    public void reportLeaderboardsAndAchievements() {
        String strGetGoogleID;
        if (isSignedIn()) {
            int i = 0;
            while (i < 1) {
                String string = i == 0 ? getString(R.string.leaderboard_kills) : "";
                int iGetLeaderboardScore = GetLeaderboardScore(i);
                if (iGetLeaderboardScore > 0) {
                    Games.Leaderboards.submitScore(getApiClient(), string, iGetLeaderboardScore);
                }
                ResetLeaderboardScore(i);
                i++;
            }
            for (int i2 = 0; i2 < 3; i2++) {
                int iGetAchievementId = GetAchievementId(i2);
                if (iGetAchievementId > 0 && (strGetGoogleID = Gof2AchievementIDs.GetGoogleID(iGetAchievementId)) != "noId") {
                    unlockAchievement(strGetGoogleID);
                }
            }
            ResetAchievements();
        }
    }

    private void unlockAchievement(String str) {
        if (isSignedIn()) {
            Games.Achievements.unlock(getApiClient(), str);
        }
    }

    private void setCountry(String str, String str2) {
        str.toUpperCase();
        String upperCase = str2.toUpperCase();
        if (upperCase.compareTo("GB") == 0) {
            ToJNI.setCountryCodeOfDevice(0);
            return;
        }
        if (upperCase.compareTo("DE") == 0) {
            ToJNI.setCountryCodeOfDevice(1);
            return;
        }
        if (upperCase.compareTo("FR") == 0) {
            ToJNI.setCountryCodeOfDevice(2);
            return;
        }
        if (upperCase.compareTo("IT") == 0) {
            ToJNI.setCountryCodeOfDevice(3);
            return;
        }
        if (upperCase.compareTo("ES") == 0) {
            ToJNI.setCountryCodeOfDevice(4);
            return;
        }
        if (upperCase.compareTo("RU") == 0) {
            ToJNI.setCountryCodeOfDevice(5);
            return;
        }
        if (upperCase.compareTo("PL") == 0) {
            ToJNI.setCountryCodeOfDevice(6);
            return;
        }
        if (upperCase.compareTo("PT") == 0) {
            ToJNI.setCountryCodeOfDevice(7);
            return;
        }
        if (upperCase.compareTo("KR") == 0) {
            ToJNI.setCountryCodeOfDevice(14);
        } else if (upperCase.compareTo("JP") == 0) {
            ToJNI.setCountryCodeOfDevice(15);
        } else {
            ToJNI.setCountryCodeOfDevice(0);
        }
    }

    @Override // net.fishlabs.googleplay.GameHelper.GameHelperListener
    public void onSignInFailed() {
        SetGPIsLinked(0);
    }

    @Override // net.fishlabs.googleplay.GameHelper.GameHelperListener
    public void onSignInSucceeded() {
        SetGPIsLinked(1);
    }

    private final void setSystemUiVisibilityMode() {
        getWindow().getDecorView().setSystemUiVisibility(5894);
        if (Build.VERSION.SDK_INT >= 28) {
            Window window = getWindow();
            WindowManager.LayoutParams attributes = window.getAttributes();
            attributes.layoutInDisplayCutoutMode = 3;
            window.setAttributes(attributes);
        }
    }

    @Override // android.view.View.OnSystemUiVisibilityChangeListener
    public void onSystemUiVisibilityChange(int i) {
        if ((i & 4) == 0) {
            setSystemUiVisibilityMode();
        }
    }
}
