package net.fishlabs.googleplay;

import android.R;
import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import com.google.android.gms.common.ConnectionResult;
import com.google.android.gms.common.GooglePlayServicesUtil;
import com.google.android.gms.common.api.Api;
import com.google.android.gms.common.api.GoogleApiClient;
import com.google.android.gms.drive.Drive;
import com.google.android.gms.games.Games;
import com.google.android.gms.games.GamesActivityResultCodes;
import com.google.android.gms.games.multiplayer.Invitation;
import com.google.android.gms.games.multiplayer.Multiplayer;
import com.google.android.gms.games.multiplayer.turnbased.TurnBasedMatch;
import com.google.android.gms.games.request.GameRequest;
import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class GameHelper implements GoogleApiClient.ConnectionCallbacks, GoogleApiClient.OnConnectionFailedListener {
    public static final int CLIENT_ALL = 15;
    public static final int CLIENT_APPSTATE = 4;
    public static final int CLIENT_GAMES = 1;
    public static final int CLIENT_NONE = 0;
    public static final int CLIENT_PLUS = 2;
    public static final int CLIENT_SNAPSHOT = 8;
    static final int DEFAULT_MAX_SIGN_IN_ATTEMPTS = 3;
    static final int RC_RESOLVE = 9001;
    static final int RC_UNUSED = 9002;
    static final String TAG = "GameHelper";
    Activity mActivity;
    Context mAppContext;
    Invitation mInvitation;
    int mRequestedClients;
    ArrayList<GameRequest> mRequests;
    TurnBasedMatch mTurnBasedMatch;
    private boolean mSetupDone = false;
    private boolean mConnecting = false;
    boolean mExpectingResolution = false;
    boolean mSignInCancelled = false;
    GoogleApiClient.Builder mGoogleApiClientBuilder = null;
    Games.GamesOptions mGamesApiOptions = Games.GamesOptions.builder().build();
    Api.ApiOptions.NoOptions mAppStateApiOptions = null;
    GoogleApiClient mGoogleApiClient = null;
    boolean mConnectOnStart = true;
    boolean mUserInitiatedSignIn = false;
    ConnectionResult mConnectionResult = null;
    SignInFailureReason mSignInFailureReason = null;
    boolean mShowErrorDialogs = true;
    boolean mDebugLog = false;
    GameHelperListener mListener = null;
    int mMaxAutoSignInAttempts = 3;
    private final String GAMEHELPER_SHARED_PREFS = "GAMEHELPER_SHARED_PREFS";
    private final String KEY_SIGN_IN_CANCELLATIONS = "KEY_SIGN_IN_CANCELLATIONS";
    Handler mHandler = new Handler();

    public interface GameHelperListener {
        void onSignInFailed();

        void onSignInSucceeded();
    }

    void resolveConnectionResult() {
    }

    public GameHelper(Activity activity, int i) {
        this.mActivity = null;
        this.mAppContext = null;
        this.mRequestedClients = 0;
        this.mActivity = activity;
        this.mAppContext = activity.getApplicationContext();
        this.mRequestedClients = i;
    }

    public void setMaxAutoSignInAttempts(int i) {
        this.mMaxAutoSignInAttempts = i;
    }

    void assertConfigured(String str) {
        if (this.mSetupDone) {
            return;
        }
        String str2 = "GameHelper error: Operation attempted without setup: " + str + ". The setup() method must be called before attempting any other operation.";
        logError(str2);
        throw new IllegalStateException(str2);
    }

    private void doApiOptionsPreCheck() {
        if (this.mGoogleApiClientBuilder != null) {
            logError("GameHelper: you cannot call set*ApiOptions after the client builder has been created. Call it before calling createApiClientBuilder() or setup().");
            throw new IllegalStateException("GameHelper: you cannot call set*ApiOptions after the client builder has been created. Call it before calling createApiClientBuilder() or setup().");
        }
    }

    public void setGamesApiOptions(Games.GamesOptions gamesOptions) {
        doApiOptionsPreCheck();
        this.mGamesApiOptions = gamesOptions;
    }

    public void setAppStateApiOptions(Api.ApiOptions.NoOptions noOptions) {
        doApiOptionsPreCheck();
        this.mAppStateApiOptions = noOptions;
    }

    public GoogleApiClient.Builder createApiClientBuilder() {
        if (this.mSetupDone) {
            logError("GameHelper: you called GameHelper.createApiClientBuilder() after calling setup. You can only get a client builder BEFORE performing setup.");
            throw new IllegalStateException("GameHelper: you called GameHelper.createApiClientBuilder() after calling setup. You can only get a client builder BEFORE performing setup.");
        }
        GoogleApiClient.Builder builder = new GoogleApiClient.Builder(this.mActivity, this, this);
        if ((this.mRequestedClients & 1) != 0) {
            builder.addApi(Games.API, this.mGamesApiOptions);
            builder.addScope(Games.SCOPE_GAMES);
        }
        if ((this.mRequestedClients & 8) != 0) {
            builder.addScope(Drive.SCOPE_APPFOLDER);
            builder.addApi(Drive.API);
        }
        this.mGoogleApiClientBuilder = builder;
        return builder;
    }

    public void setup(GameHelperListener gameHelperListener) {
        if (this.mSetupDone) {
            logError("GameHelper: you cannot call GameHelper.setup() more than once!");
            throw new IllegalStateException("GameHelper: you cannot call GameHelper.setup() more than once!");
        }
        this.mListener = gameHelperListener;
        debugLog("Setup: requested clients: " + this.mRequestedClients);
        if (this.mGoogleApiClientBuilder == null) {
            createApiClientBuilder();
        }
        this.mGoogleApiClient = this.mGoogleApiClientBuilder.build();
        this.mGoogleApiClientBuilder = null;
        this.mSetupDone = true;
    }

    public GoogleApiClient getApiClient() {
        if (this.mGoogleApiClient == null) {
            throw new IllegalStateException("No GoogleApiClient. Did you call setup()?");
        }
        return this.mGoogleApiClient;
    }

    public boolean isSignedIn() {
        return this.mGoogleApiClient != null && this.mGoogleApiClient.isConnected();
    }

    public boolean isConnecting() {
        return this.mConnecting;
    }

    public boolean hasSignInError() {
        return this.mSignInFailureReason != null;
    }

    public SignInFailureReason getSignInError() {
        return this.mSignInFailureReason;
    }

    public void setShowErrorDialogs(boolean z) {
        this.mShowErrorDialogs = z;
    }

    public void onStart(Activity activity) {
        this.mActivity = activity;
        this.mAppContext = activity.getApplicationContext();
        debugLog("onStart");
        assertConfigured("onStart");
        if (this.mConnectOnStart) {
            if (this.mGoogleApiClient.isConnected()) {
                Log.w(TAG, "GameHelper: client was already connected on onStart()");
                return;
            }
            debugLog("Connecting client.");
            this.mConnecting = true;
            this.mGoogleApiClient.connect();
            return;
        }
        debugLog("Not attempting to connect becase mConnectOnStart=false");
        debugLog("Instead, reporting a sign-in failure.");
        this.mHandler.postDelayed(new Runnable() { // from class: net.fishlabs.googleplay.GameHelper.1
            @Override // java.lang.Runnable
            public void run() {
                GameHelper.this.notifyListener(false);
            }
        }, 1000L);
    }

    public void onResume(Activity activity) {
        this.mActivity = activity;
    }

    public void onStop() {
        debugLog("onStop");
        assertConfigured("onStop");
        if (this.mGoogleApiClient.isConnected()) {
            debugLog("Disconnecting client due to onStop");
            this.mGoogleApiClient.disconnect();
        } else {
            debugLog("Client already disconnected when we got onStop.");
        }
        this.mConnecting = false;
        this.mExpectingResolution = false;
        this.mActivity = null;
    }

    public String getInvitationId() {
        if (!this.mGoogleApiClient.isConnected()) {
            Log.w(TAG, "Warning: getInvitationId() should only be called when signed in, that is, after getting onSignInSuceeded()");
        }
        if (this.mInvitation == null) {
            return null;
        }
        return this.mInvitation.getInvitationId();
    }

    public Invitation getInvitation() {
        if (!this.mGoogleApiClient.isConnected()) {
            Log.w(TAG, "Warning: getInvitation() should only be called when signed in, that is, after getting onSignInSuceeded()");
        }
        return this.mInvitation;
    }

    public boolean hasInvitation() {
        return this.mInvitation != null;
    }

    public boolean hasTurnBasedMatch() {
        return this.mTurnBasedMatch != null;
    }

    public boolean hasRequests() {
        return this.mRequests != null;
    }

    public void clearInvitation() {
        this.mInvitation = null;
    }

    public void clearTurnBasedMatch() {
        this.mTurnBasedMatch = null;
    }

    public void clearRequests() {
        this.mRequests = null;
    }

    public TurnBasedMatch getTurnBasedMatch() {
        if (!this.mGoogleApiClient.isConnected()) {
            Log.w(TAG, "Warning: getTurnBasedMatch() should only be called when signed in, that is, after getting onSignInSuceeded()");
        }
        return this.mTurnBasedMatch;
    }

    public ArrayList<GameRequest> getRequests() {
        if (!this.mGoogleApiClient.isConnected()) {
            Log.w(TAG, "Warning: getRequests() should only be called when signed in, that is, after getting onSignInSuceeded()");
        }
        return this.mRequests;
    }

    public void enableDebugLog(boolean z) {
        this.mDebugLog = z;
        if (z) {
            debugLog("Debug log enabled.");
        }
    }

    @Deprecated
    public void enableDebugLog(boolean z, String str) {
        Log.w(TAG, "GameHelper.enableDebugLog(boolean,String) is deprecated. Use GameHelper.enableDebugLog(boolean)");
        enableDebugLog(z);
    }

    public void signOut() {
        if (!this.mGoogleApiClient.isConnected()) {
            debugLog("signOut: was already disconnected, ignoring.");
            return;
        }
        if ((this.mRequestedClients & 1) != 0) {
            debugLog("Signing out from the Google API Client.");
            Games.signOut(this.mGoogleApiClient);
        }
        debugLog("Disconnecting client.");
        this.mConnectOnStart = false;
        this.mConnecting = false;
        this.mGoogleApiClient.disconnect();
    }

    public void onActivityResult(int i, int i2, Intent intent) {
        StringBuilder sb = new StringBuilder();
        sb.append("onActivityResult: req=");
        sb.append(i == 9001 ? "RC_RESOLVE" : String.valueOf(i));
        sb.append(", resp=");
        sb.append(GameHelperUtils.activityResponseCodeToString(i2));
        debugLog(sb.toString());
        if (i != 9001) {
            debugLog("onActivityResult: request code not meant for us. Ignoring.");
            return;
        }
        this.mExpectingResolution = false;
        if (!this.mConnecting) {
            debugLog("onActivityResult: ignoring because we are not connecting.");
            return;
        }
        if (i2 == -1) {
            debugLog("onAR: Resolution was RESULT_OK, so connecting current client again.");
            connect();
            return;
        }
        if (i2 == 10001) {
            debugLog("onAR: Resolution was RECONNECT_REQUIRED, so reconnecting.");
            connect();
            return;
        }
        if (i2 == 0) {
            debugLog("onAR: Got a cancellation result, so disconnecting.");
            this.mSignInCancelled = true;
            this.mConnectOnStart = false;
            this.mUserInitiatedSignIn = false;
            this.mSignInFailureReason = null;
            this.mConnecting = false;
            this.mGoogleApiClient.disconnect();
            debugLog("onAR: # of cancellations " + getSignInCancellations() + " --> " + incrementSignInCancellations() + ", max " + this.mMaxAutoSignInAttempts);
            notifyListener(false);
            return;
        }
        debugLog("onAR: responseCode=" + GameHelperUtils.activityResponseCodeToString(i2) + ", so giving up.");
        giveUp(new SignInFailureReason(this.mConnectionResult.getErrorCode(), i2));
    }

    void notifyListener(boolean z) {
        String str;
        StringBuilder sb = new StringBuilder();
        sb.append("Notifying LISTENER of sign-in ");
        if (z) {
            str = "SUCCESS";
        } else {
            str = this.mSignInFailureReason != null ? "FAILURE (error)" : "FAILURE (no error)";
        }
        sb.append(str);
        debugLog(sb.toString());
        if (this.mListener != null) {
            if (z) {
                this.mListener.onSignInSucceeded();
            } else {
                this.mListener.onSignInFailed();
            }
        }
    }

    public void beginUserInitiatedSignIn() {
        debugLog("beginUserInitiatedSignIn: resetting attempt count.");
        resetSignInCancellations();
        this.mSignInCancelled = false;
        this.mConnectOnStart = true;
        if (this.mGoogleApiClient.isConnected()) {
            logWarn("beginUserInitiatedSignIn() called when already connected. Calling listener directly to notify of success.");
            notifyListener(true);
            return;
        }
        if (this.mConnecting) {
            logWarn("beginUserInitiatedSignIn() called when already connecting. Be patient! You can only call this method after you get an onSignInSucceeded() or onSignInFailed() callback. Suggestion: disable the sign-in button on startup and also when it's clicked, and re-enable when you get the callback.");
            return;
        }
        debugLog("Starting USER-INITIATED sign-in flow.");
        this.mUserInitiatedSignIn = true;
        if (this.mConnectionResult != null) {
            debugLog("beginUserInitiatedSignIn: continuing pending sign-in flow.");
            this.mConnecting = true;
            resolveConnectionResult();
        } else {
            debugLog("beginUserInitiatedSignIn: starting new sign-in flow.");
            this.mConnecting = true;
            connect();
        }
    }

    void connect() {
        if (this.mGoogleApiClient.isConnected()) {
            debugLog("Already connected.");
            return;
        }
        debugLog("Starting connection.");
        this.mConnecting = true;
        this.mInvitation = null;
        this.mTurnBasedMatch = null;
        this.mGoogleApiClient.connect();
    }

    public void reconnectClient() {
        if (!this.mGoogleApiClient.isConnected()) {
            Log.w(TAG, "reconnectClient() called when client is not connected.");
            connect();
        } else {
            debugLog("Reconnecting client.");
            this.mGoogleApiClient.reconnect();
        }
    }

    @Override // com.google.android.gms.common.api.GoogleApiClient.ConnectionCallbacks
    public void onConnected(Bundle bundle) {
        debugLog("onConnected: connected!");
        if (bundle != null) {
            debugLog("onConnected: connection hint provided. Checking for invite.");
            Invitation invitation = (Invitation) bundle.getParcelable(Multiplayer.EXTRA_INVITATION);
            if (invitation != null && invitation.getInvitationId() != null) {
                debugLog("onConnected: connection hint has a room invite!");
                this.mInvitation = invitation;
                debugLog("Invitation ID: " + this.mInvitation.getInvitationId());
            }
            this.mRequests = Games.Requests.getGameRequestsFromBundle(bundle);
            if (!this.mRequests.isEmpty()) {
                debugLog("onConnected: connection hint has " + this.mRequests.size() + " request(s)");
            }
            debugLog("onConnected: connection hint provided. Checking for TBMP game.");
            this.mTurnBasedMatch = (TurnBasedMatch) bundle.getParcelable(Multiplayer.EXTRA_TURN_BASED_MATCH);
        }
        succeedSignIn();
    }

    void succeedSignIn() {
        debugLog("succeedSignIn");
        this.mSignInFailureReason = null;
        this.mConnectOnStart = true;
        this.mUserInitiatedSignIn = false;
        this.mConnecting = false;
        notifyListener(true);
    }

    int getSignInCancellations() {
        return this.mAppContext.getSharedPreferences("GAMEHELPER_SHARED_PREFS", 0).getInt("KEY_SIGN_IN_CANCELLATIONS", 0);
    }

    int incrementSignInCancellations() {
        int signInCancellations = getSignInCancellations();
        SharedPreferences.Editor editorEdit = this.mAppContext.getSharedPreferences("GAMEHELPER_SHARED_PREFS", 0).edit();
        int i = signInCancellations + 1;
        editorEdit.putInt("KEY_SIGN_IN_CANCELLATIONS", i);
        editorEdit.commit();
        return i;
    }

    void resetSignInCancellations() {
        SharedPreferences.Editor editorEdit = this.mAppContext.getSharedPreferences("GAMEHELPER_SHARED_PREFS", 0).edit();
        editorEdit.putInt("KEY_SIGN_IN_CANCELLATIONS", 0);
        editorEdit.commit();
    }

    @Override // com.google.android.gms.common.api.GoogleApiClient.OnConnectionFailedListener
    public void onConnectionFailed(ConnectionResult connectionResult) {
        debugLog("onConnectionFailed");
        this.mConnectionResult = connectionResult;
        debugLog("Connection failure:");
        debugLog("   - code: " + GameHelperUtils.errorCodeToString(this.mConnectionResult.getErrorCode()));
        debugLog("   - resolvable: " + this.mConnectionResult.hasResolution());
        debugLog("   - details: " + this.mConnectionResult.toString());
        int signInCancellations = getSignInCancellations();
        boolean z = true;
        if (this.mUserInitiatedSignIn) {
            debugLog("onConnectionFailed: WILL resolve because user initiated sign-in.");
        } else {
            if (this.mSignInCancelled) {
                debugLog("onConnectionFailed WILL NOT resolve (user already cancelled once).");
            } else if (signInCancellations < this.mMaxAutoSignInAttempts) {
                debugLog("onConnectionFailed: WILL resolve because we have below the max# of attempts, " + signInCancellations + " < " + this.mMaxAutoSignInAttempts);
            } else {
                debugLog("onConnectionFailed: Will NOT resolve; not user-initiated and max attempts reached: " + signInCancellations + " >= " + this.mMaxAutoSignInAttempts);
            }
            z = false;
        }
        if (!z) {
            debugLog("onConnectionFailed: since we won't resolve, failing now.");
            this.mConnectionResult = connectionResult;
            this.mConnecting = false;
            notifyListener(false);
            return;
        }
        debugLog("onConnectionFailed: resolving problem...");
        resolveConnectionResult();
    }

    public void disconnect() {
        if (this.mGoogleApiClient.isConnected()) {
            debugLog("Disconnecting client.");
            this.mGoogleApiClient.disconnect();
        } else {
            Log.w(TAG, "disconnect() called when client was already disconnected.");
        }
    }

    void giveUp(SignInFailureReason signInFailureReason) {
        this.mConnectOnStart = false;
        disconnect();
        this.mSignInFailureReason = signInFailureReason;
        if (signInFailureReason.mActivityResultCode == 10004) {
            GameHelperUtils.printMisconfiguredDebugInfo(this.mAppContext);
        }
        showFailureDialog();
        this.mConnecting = false;
        notifyListener(false);
    }

    @Override // com.google.android.gms.common.api.GoogleApiClient.ConnectionCallbacks
    public void onConnectionSuspended(int i) {
        debugLog("onConnectionSuspended, cause=" + i);
        disconnect();
        this.mSignInFailureReason = null;
        debugLog("Making extraordinary call to onSignInFailed callback");
        this.mConnecting = false;
        notifyListener(false);
    }

    public void showFailureDialog() {
        if (this.mSignInFailureReason != null) {
            int serviceErrorCode = this.mSignInFailureReason.getServiceErrorCode();
            int activityResultCode = this.mSignInFailureReason.getActivityResultCode();
            if (this.mShowErrorDialogs) {
                showFailureDialog(this.mActivity, activityResultCode, serviceErrorCode);
                return;
            }
            debugLog("Not showing error dialog because mShowErrorDialogs==false. Error was: " + this.mSignInFailureReason);
        }
    }

    public static void showFailureDialog(Activity activity, int i, int i2) {
        Dialog dialogMakeSimpleDialog;
        if (activity == null) {
            Log.e(TAG, "*** No Activity. Can't show failure dialog!");
            return;
        }
        switch (i) {
            case GamesActivityResultCodes.RESULT_SIGN_IN_FAILED /* 10002 */:
                dialogMakeSimpleDialog = makeSimpleDialog(activity, GameHelperUtils.getString(activity, 1));
                break;
            case GamesActivityResultCodes.RESULT_LICENSE_FAILED /* 10003 */:
                dialogMakeSimpleDialog = makeSimpleDialog(activity, GameHelperUtils.getString(activity, 3));
                break;
            case GamesActivityResultCodes.RESULT_APP_MISCONFIGURED /* 10004 */:
                dialogMakeSimpleDialog = makeSimpleDialog(activity, GameHelperUtils.getString(activity, 2));
                break;
            default:
                Dialog errorDialog = GooglePlayServicesUtil.getErrorDialog(i2, activity, 9002, null);
                if (errorDialog != null) {
                    dialogMakeSimpleDialog = errorDialog;
                } else {
                    Log.e(TAG, "No standard error dialog available. Making fallback dialog.");
                    dialogMakeSimpleDialog = makeSimpleDialog(activity, GameHelperUtils.getString(activity, 0) + " " + GameHelperUtils.errorCodeToString(i2));
                }
                break;
        }
        dialogMakeSimpleDialog.show();
    }

    static Dialog makeSimpleDialog(Activity activity, String str) {
        return new AlertDialog.Builder(activity).setMessage(str).setNeutralButton(R.string.ok, (DialogInterface.OnClickListener) null).create();
    }

    static Dialog makeSimpleDialog(Activity activity, String str, String str2) {
        return new AlertDialog.Builder(activity).setMessage(str2).setTitle(str).setNeutralButton(R.string.ok, (DialogInterface.OnClickListener) null).create();
    }

    public Dialog makeSimpleDialog(String str) {
        if (this.mActivity == null) {
            logError("*** makeSimpleDialog failed: no current Activity!");
            return null;
        }
        return makeSimpleDialog(this.mActivity, str);
    }

    public Dialog makeSimpleDialog(String str, String str2) {
        if (this.mActivity == null) {
            logError("*** makeSimpleDialog failed: no current Activity!");
            return null;
        }
        return makeSimpleDialog(this.mActivity, str, str2);
    }

    void debugLog(String str) {
        if (this.mDebugLog) {
            Log.d(TAG, "GameHelper: " + str);
        }
    }

    void logWarn(String str) {
        Log.w(TAG, "!!! GameHelper WARNING: " + str);
    }

    void logError(String str) {
        Log.e(TAG, "*** GameHelper ERROR: " + str);
    }

    public static class SignInFailureReason {
        public static final int NO_ACTIVITY_RESULT_CODE = -100;
        int mActivityResultCode;
        int mServiceErrorCode;

        public int getServiceErrorCode() {
            return this.mServiceErrorCode;
        }

        public int getActivityResultCode() {
            return this.mActivityResultCode;
        }

        public SignInFailureReason(int i, int i2) {
            this.mServiceErrorCode = 0;
            this.mActivityResultCode = -100;
            this.mServiceErrorCode = i;
            this.mActivityResultCode = i2;
        }

        public SignInFailureReason(int i) {
            this(i, -100);
        }

        public String toString() {
            String str;
            StringBuilder sb = new StringBuilder();
            sb.append("SignInFailureReason(serviceErrorCode:");
            sb.append(GameHelperUtils.errorCodeToString(this.mServiceErrorCode));
            if (this.mActivityResultCode == -100) {
                str = ")";
            } else {
                str = ",activityResultCode:" + GameHelperUtils.activityResponseCodeToString(this.mActivityResultCode) + ")";
            }
            sb.append(str);
            return sb.toString();
        }
    }

    public void setConnectOnStart(boolean z) {
        debugLog("Forcing mConnectOnStart=" + z);
        this.mConnectOnStart = z;
    }
}
