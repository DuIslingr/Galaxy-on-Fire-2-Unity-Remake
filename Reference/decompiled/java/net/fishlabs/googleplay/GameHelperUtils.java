package net.fishlabs.googleplay;

import android.content.Context;
import android.content.pm.PackageManager;
import android.content.pm.Signature;
import android.content.res.Resources;
import android.util.Log;
import com.google.android.gms.games.GamesActivityResultCodes;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import net.fishlabs.gof2hdallandroid2012.R;

/* JADX INFO: loaded from: classes.dex */
class GameHelperUtils {
    private static final String[] FALLBACK_STRINGS = {"*Unknown error.", "*Failed to sign in. Please check your network connection and try again.", "*The application is incorrectly configured. Check that the package name and signing certificate match the client ID created in Developer Console. Also, if the application is not yet published, check that the account you are trying to sign in with is listed as a tester account. See logs for more information.", "*License check failed."};
    private static final int[] RES_IDS = {R.string.gamehelper_unknown_error, R.string.gamehelper_sign_in_failed, R.string.gamehelper_app_misconfigured, R.string.gamehelper_license_failed};
    public static final int R_APP_MISCONFIGURED = 2;
    public static final int R_LICENSE_FAILED = 3;
    public static final int R_SIGN_IN_FAILED = 1;
    public static final int R_UNKNOWN_ERROR = 0;

    GameHelperUtils() {
    }

    static String activityResponseCodeToString(int i) {
        switch (i) {
            case -1:
                return "RESULT_OK";
            case 0:
                return "RESULT_CANCELED";
            default:
                switch (i) {
                    case GamesActivityResultCodes.RESULT_RECONNECT_REQUIRED /* 10001 */:
                        return "RESULT_RECONNECT_REQUIRED";
                    case GamesActivityResultCodes.RESULT_SIGN_IN_FAILED /* 10002 */:
                        return "SIGN_IN_FAILED";
                    case GamesActivityResultCodes.RESULT_LICENSE_FAILED /* 10003 */:
                        return "RESULT_LICENSE_FAILED";
                    case GamesActivityResultCodes.RESULT_APP_MISCONFIGURED /* 10004 */:
                        return "RESULT_APP_MISCONFIGURED";
                    case GamesActivityResultCodes.RESULT_LEFT_ROOM /* 10005 */:
                        return "RESULT_LEFT_ROOM";
                    default:
                        return String.valueOf(i);
                }
        }
    }

    static String errorCodeToString(int i) {
        switch (i) {
            case 0:
                return "SUCCESS(" + i + ")";
            case 1:
                return "SERVICE_MISSING(" + i + ")";
            case 2:
                return "SERVICE_VERSION_UPDATE_REQUIRED(" + i + ")";
            case 3:
                return "SERVICE_DISABLED(" + i + ")";
            case 4:
                return "SIGN_IN_REQUIRED(" + i + ")";
            case 5:
                return "INVALID_ACCOUNT(" + i + ")";
            case 6:
                return "RESOLUTION_REQUIRED(" + i + ")";
            case 7:
                return "NETWORK_ERROR(" + i + ")";
            case 8:
                return "INTERNAL_ERROR(" + i + ")";
            case 9:
                return "SERVICE_INVALID(" + i + ")";
            case 10:
                return "DEVELOPER_ERROR(" + i + ")";
            case 11:
                return "LICENSE_CHECK_FAILED(" + i + ")";
            default:
                return "Unknown error code " + i;
        }
    }

    static void printMisconfiguredDebugInfo(Context context) {
        Log.w("GameHelper", "****");
        Log.w("GameHelper", "****");
        Log.w("GameHelper", "**** APP NOT CORRECTLY CONFIGURED TO USE GOOGLE PLAY GAME SERVICES");
        Log.w("GameHelper", "**** This is usually caused by one of these reasons:");
        Log.w("GameHelper", "**** (1) Your package name and certificate fingerprint do not match");
        Log.w("GameHelper", "****     the client ID you registered in Developer Console.");
        Log.w("GameHelper", "**** (2) Your App ID was incorrectly entered.");
        Log.w("GameHelper", "**** (3) Your game settings have not been published and you are ");
        Log.w("GameHelper", "****     trying to log in with an account that is not listed as");
        Log.w("GameHelper", "****     a test account.");
        Log.w("GameHelper", "****");
        if (context == null) {
            Log.w("GameHelper", "*** (no Context, so can't print more debug info)");
            return;
        }
        Log.w("GameHelper", "**** To help you debug, here is the information about this app");
        Log.w("GameHelper", "**** Package name         : " + context.getPackageName());
        Log.w("GameHelper", "**** Cert SHA1 fingerprint: " + getSHA1CertFingerprint(context));
        Log.w("GameHelper", "**** App ID from          : " + getAppIdFromResource(context));
        Log.w("GameHelper", "****");
        Log.w("GameHelper", "**** Check that the above information matches your setup in ");
        Log.w("GameHelper", "**** Developer Console. Also, check that you're logging in with the");
        Log.w("GameHelper", "**** right account (it should be listed in the Testers section if");
        Log.w("GameHelper", "**** your project is not yet published).");
        Log.w("GameHelper", "****");
        Log.w("GameHelper", "**** For more information, refer to the troubleshooting guide:");
        Log.w("GameHelper", "****   http://developers.google.com/games/services/android/troubleshooting");
    }

    static String getAppIdFromResource(Context context) {
        try {
            Resources resources = context.getResources();
            return resources.getString(resources.getIdentifier("app_id", "string", context.getPackageName()));
        } catch (Exception e) {
            e.printStackTrace();
            return "??? (failed to retrieve APP ID)";
        }
    }

    static String getSHA1CertFingerprint(Context context) {
        try {
            Signature[] signatureArr = context.getPackageManager().getPackageInfo(context.getPackageName(), 64).signatures;
            if (signatureArr.length == 0) {
                return "ERROR: NO SIGNATURE.";
            }
            if (signatureArr.length > 1) {
                return "ERROR: MULTIPLE SIGNATURES";
            }
            byte[] bArrDigest = MessageDigest.getInstance("SHA1").digest(signatureArr[0].toByteArray());
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < bArrDigest.length; i++) {
                if (i > 0) {
                    sb.append(":");
                }
                byteToString(sb, bArrDigest[i]);
            }
            return sb.toString();
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
            return "(ERROR: package not found)";
        } catch (NoSuchAlgorithmException e2) {
            e2.printStackTrace();
            return "(ERROR: SHA1 algorithm not found)";
        }
    }

    static void byteToString(StringBuilder sb, byte b) {
        int i = b;
        if (b < 0) {
            i = b + 256;
        }
        int i2 = i / 16;
        int i3 = i % 16;
        sb.append("0123456789ABCDEF".substring(i2, i2 + 1));
        sb.append("0123456789ABCDEF".substring(i3, i3 + 1));
    }

    static String getString(Context context, int i) {
        if (i < 0 || i >= RES_IDS.length) {
            i = 0;
        }
        int i2 = RES_IDS[i];
        try {
            return context.getString(i2);
        } catch (Exception e) {
            e.printStackTrace();
            Log.w("GameHelper", "*** GameHelper could not found resource id #" + i2 + ". This probably happened because you included it as a stand-alone JAR. BaseGameUtils should be compiled as a LIBRARY PROJECT, so that it can access its resources. Using a fallback string.");
            return FALLBACK_STRINGS[i];
        }
    }
}
