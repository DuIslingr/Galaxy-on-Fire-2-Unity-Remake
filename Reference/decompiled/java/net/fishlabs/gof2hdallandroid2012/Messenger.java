package net.fishlabs.gof2hdallandroid2012;

import android.util.Log;

/* JADX INFO: loaded from: classes.dex */
public class Messenger {
    private static final String _ProjectName = "GOF2HD2012";
    private static boolean _activated;

    public Messenger() {
        _activated = MessengerSwitcher.getSwitch();
    }

    public void printError(String str) {
        if (_activated) {
            Log.e(_ProjectName, str);
        } else if (_activated) {
        }
    }

    public void printInformation(String str) {
        if (_activated) {
            Log.i(_ProjectName, str);
        } else if (_activated) {
        }
    }

    public void printWarning(String str) {
        if (_activated) {
            Log.w(_ProjectName, str);
        } else if (_activated) {
        }
    }

    public void setActivation(boolean z) {
        _activated = z;
    }
}
