package net.fishlabs.googleplay;

import android.content.Intent;
import android.os.Bundle;
import android.support.v4.app.FragmentActivity;
import android.util.Log;
import com.google.android.gms.common.api.GoogleApiClient;

/* JADX INFO: loaded from: classes.dex */
public abstract class BaseGameActivity extends FragmentActivity implements GameHelper.GameHelperListener {
    public static final int CLIENT_ALL = 15;
    public static final int CLIENT_APPSTATE = 4;
    public static final int CLIENT_GAMES = 1;
    public static final int CLIENT_PLUS = 2;
    private static final String TAG = "BaseGameActivity";
    protected GameHelper mHelper;
    protected int mRequestedClients = 1;
    protected boolean mDebugLog = false;

    protected BaseGameActivity() {
    }

    protected BaseGameActivity(int i) {
        setRequestedClients(i);
    }

    protected void setRequestedClients(int i) {
        this.mRequestedClients = i;
    }

    public GameHelper getGameHelper() {
        if (this.mHelper == null) {
            this.mHelper = new GameHelper(this, this.mRequestedClients);
            this.mHelper.enableDebugLog(this.mDebugLog);
        }
        return this.mHelper;
    }

    @Override // android.support.v4.app.FragmentActivity, android.support.v4.app.SupportActivity, android.app.Activity
    protected void onCreate(Bundle bundle) {
        super.onCreate(bundle);
        if (this.mHelper == null) {
            getGameHelper();
        }
        this.mHelper.setup(this);
    }

    @Override // android.support.v4.app.FragmentActivity, android.app.Activity
    protected void onStart() {
        super.onStart();
        this.mHelper.onStart(this);
    }

    @Override // android.support.v4.app.FragmentActivity, android.app.Activity
    protected void onResume() {
        super.onResume();
        if (this.mHelper != null) {
            this.mHelper.onResume(this);
        }
    }

    @Override // android.support.v4.app.FragmentActivity, android.app.Activity
    protected void onStop() {
        super.onStop();
        if (this.mHelper != null) {
            this.mHelper.onStop();
        }
    }

    @Override // android.support.v4.app.FragmentActivity, android.app.Activity
    protected void onActivityResult(int i, int i2, Intent intent) {
        super.onActivityResult(i, i2, intent);
        this.mHelper.onActivityResult(i, i2, intent);
    }

    protected GoogleApiClient getApiClient() {
        return this.mHelper.getApiClient();
    }

    protected boolean isSignedIn() {
        return this.mHelper.isSignedIn();
    }

    /* JADX INFO: Access modifiers changed from: protected */
    public void beginUserInitiatedSignIn() {
        this.mHelper.beginUserInitiatedSignIn();
    }

    protected void signOut() {
        this.mHelper.signOut();
    }

    protected void showAlert(String str) {
        this.mHelper.makeSimpleDialog(str).show();
    }

    protected void showAlert(String str, String str2) {
        this.mHelper.makeSimpleDialog(str, str2).show();
    }

    protected void enableDebugLog(boolean z) {
        this.mDebugLog = true;
        if (this.mHelper != null) {
            this.mHelper.enableDebugLog(z);
        }
    }

    @Deprecated
    protected void enableDebugLog(boolean z, String str) {
        Log.w(TAG, "BaseGameActivity.enabledDebugLog(bool,String) is deprecated. Use enableDebugLog(boolean)");
        enableDebugLog(z);
    }

    protected String getInvitationId() {
        return this.mHelper.getInvitationId();
    }

    protected void reconnectClient() {
        this.mHelper.reconnectClient();
    }

    protected boolean hasSignInError() {
        return this.mHelper.hasSignInError();
    }

    protected GameHelper.SignInFailureReason getSignInError() {
        return this.mHelper.getSignInError();
    }
}
