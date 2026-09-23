package net.fishlabs.ow_utils;

import android.app.Activity;
import android.content.Context;
import android.graphics.Point;
import android.net.wifi.WifiInfo;
import android.net.wifi.WifiManager;
import android.os.Build;
import android.telephony.TelephonyManager;
import android.util.DisplayMetrics;
import android.view.Display;
import java.security.MessageDigest;
import java.util.UUID;
import net.fishlabs.gof2hdallandroid2012.GOF2HD2012;

/* JADX INFO: loaded from: classes.dex */
public class DeviceInfo {
    protected static String deviceID;
    protected static String imeiNumber;
    protected static String wifiMacAddress;

    public static void init(Context context) throws Exception {
        imeiNumber = getImei(context);
        wifiMacAddress = getWifiMacAddress(context);
        deviceID = getDeviceId(context);
    }

    public static String getDeviceInfo() {
        return deviceID;
    }

    public static String getImei() {
        return imeiNumber;
    }

    public static String getWifiMacAddress() {
        return wifiMacAddress;
    }

    public static String getModel() {
        return Build.MODEL;
    }

    public static String getOsVersion() {
        return Build.VERSION.RELEASE;
    }

    protected static String getDeviceId(Context context) throws Exception {
        String imei = getImei(context);
        return imei != null ? imei : getWifiMacAddress(context);
    }

    protected static String getWifiMacAddress(Context context) throws Exception {
        WifiInfo connectionInfo = ((WifiManager) context.getSystemService("wifi")).getConnectionInfo();
        if (connectionInfo == null || connectionInfo.getMacAddress() == null) {
            return md5(UUID.randomUUID().toString());
        }
        return connectionInfo.getMacAddress().replace(":", "").replace(".", "");
    }

    protected static String getImei(Context context) {
        TelephonyManager telephonyManager = (TelephonyManager) context.getSystemService("phone");
        if (telephonyManager == null) {
            return null;
        }
        try {
            return telephonyManager.getDeviceId();
        } catch (Exception unused) {
            return "";
        }
    }

    protected static String md5(String str) throws Exception {
        MessageDigest messageDigest = MessageDigest.getInstance("MD5");
        messageDigest.update(str.getBytes());
        byte[] bArrDigest = messageDigest.digest();
        StringBuffer stringBuffer = new StringBuffer();
        for (byte b : bArrDigest) {
            stringBuffer.append(Integer.toHexString(255 & b));
        }
        return stringBuffer.toString();
    }

    public static boolean isPad() {
        Activity activity = GOF2HD2012.getActivity();
        if (activity == null) {
            return false;
        }
        Display defaultDisplay = activity.getWindowManager().getDefaultDisplay();
        DisplayMetrics displayMetrics = new DisplayMetrics();
        defaultDisplay.getMetrics(displayMetrics);
        return Math.sqrt(Math.pow(((double) getDisplayWidth()) / ((double) displayMetrics.xdpi), 2.0d) + Math.pow(((double) getDisplayHeight()) / ((double) displayMetrics.ydpi), 2.0d)) > 6.5d;
    }

    public static int getDisplayWidth() {
        Activity activity = GOF2HD2012.getActivity();
        if (activity == null) {
            return 0;
        }
        Display defaultDisplay = activity.getWindowManager().getDefaultDisplay();
        Point point = new Point();
        if (Build.VERSION.SDK_INT >= 17) {
            defaultDisplay.getRealSize(point);
        } else {
            defaultDisplay.getSize(point);
        }
        return point.x;
    }

    public static int getDisplayHeight() {
        Activity activity = GOF2HD2012.getActivity();
        if (activity == null) {
            return 0;
        }
        Display defaultDisplay = activity.getWindowManager().getDefaultDisplay();
        Point point = new Point();
        if (Build.VERSION.SDK_INT >= 17) {
            defaultDisplay.getRealSize(point);
        } else {
            defaultDisplay.getSize(point);
        }
        return point.y;
    }
}
