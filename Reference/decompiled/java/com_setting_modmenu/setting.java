package com.setting;

import android.content.Context;
import android.content.SharedPreferences;
import android.preference.PreferenceManager;

/* JADX INFO: loaded from: classes.dex */
public class setting {
    public static setting sungelon;
    public Context cont;
    public float screenscale;
    public float touchfix_x;
    public float touchfix_y;

    public static float getFinalScreenScale(float or) {
        return DB().screenscale * or;
    }

    public static float getFinalTouchXSclalle(float or) {
        return DB().touchfix_x * or;
    }

    public static float getFinalTouchYSclalle(float or) {
        return DB().touchfix_y * or;
    }

    public void presettest() {
        DB(null).load();
        float f = 10;
        float f2 = 20;
        float f3 = 10;
        float f4 = (f2 / f3) * f;
        Math.min(10, 20);
        float f5 = getFinalScreenScale(f * 1.0f);
        float f6 = getFinalScreenScale(f4 * 1.0f);
        System.out.println(getFinalTouchXSclalle(f5 / f3) + "" + getFinalTouchYSclalle(f6 / f2));
    }

    public static setting DB(Context contex) {
        setting settingVar = sungelon;
        if (settingVar != null) {
            return settingVar;
        }
        setting settingVar2 = new setting();
        sungelon = settingVar2;
        settingVar2.cont = contex;
        return settingVar2;
    }

    public static setting DB() {
        setting settingVar = sungelon;
        if (settingVar != null) {
            return settingVar;
        }
        return null;
    }

    public void load() {
        restore(sungelon.cont);
    }

    public void restore(Context context) {
        SharedPreferences sharedPreferences = PreferenceManager.getDefaultSharedPreferences(context);
        this.cont = context;
        sungelon = this;
        this.screenscale = sharedPreferences.getFloat("screenscale", 1.0f);
        this.touchfix_x = sharedPreferences.getFloat("touchfix_x", 1.0f);
        this.touchfix_y = sharedPreferences.getFloat("touchfix_y", 1.0f);
    }

    public void save() {
        save(sungelon.cont);
    }

    public void save(Context context) {
        SharedPreferences.Editor editor = PreferenceManager.getDefaultSharedPreferences(context).edit();
        editor.putFloat("screenscale", this.screenscale);
        editor.putFloat("touchfix_x", this.touchfix_x);
        editor.putFloat("touchfix_y", this.touchfix_y);
        editor.commit();
    }
}
