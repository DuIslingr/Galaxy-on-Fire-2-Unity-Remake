package net.fishlabs.gof2hdallandroid2012;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.PendingIntent;
import android.app.ProgressDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.content.res.Configuration;
import android.net.Uri;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Environment;
import android.support.annotation.NonNull;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.util.Log;
import android.view.KeyEvent;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.ProgressBar;
import android.widget.TextView;
import com.google.android.gms.drive.DriveFile;
import com.google.android.vending.expansion.downloader.DownloadProgressInfo;
import com.google.android.vending.expansion.downloader.DownloaderClientMarshaller;
import com.google.android.vending.expansion.downloader.DownloaderServiceMarshaller;
import com.google.android.vending.expansion.downloader.Helpers;
import com.google.android.vending.expansion.downloader.IDownloaderClient;
import com.google.android.vending.expansion.downloader.IDownloaderService;
import com.google.android.vending.expansion.downloader.IStub;
import java.io.File;
import java.io.IOException;
import java.util.Iterator;

/* JADX INFO: loaded from: classes.dex */
public class DownloaderActivity extends Activity implements IDownloaderClient {
    protected static final long FMODSIZE = 369545280;
    protected static String INTENT_EXTERNAL_FILES_DIR = "APP_EXTERNAL_FILES_DIR";
    protected static String INTENT_EXTERNAL_MAIN_OBB_FILE_NAME = "APP_EXTERNAL_NAME_OF_OBB_FILE_MAIN";
    protected static String INTENT_EXTERNAL_OBB_DIR = "APP_EXTERNAL_PATH_TO_OBB_FILES";
    protected static String INTENT_EXTERNAL_PATCH_OBB_FILE_NAME = "APP_EXTERNAL_NAME_OF_OBB_FILE_PATCH";
    private static final String LOG_TAG = "FishlabsDownloader";
    public static final int MAIN_OBBFIILE_VERSION_CODE = 47947006;
    protected static final long MAIN_OBBFILE_SIZE = 1011128870;
    public static final String PATCH_OBBFIILE_VERSION_CODE = "";
    static final int PERMISSION_REQUEST_ID = 7376;
    public static final String STORAGE_READ = "android.permission.READ_EXTERNAL_STORAGE";
    public static final String STORAGE_WRITE = "android.permission.WRITE_EXTERNAL_STORAGE";
    private static final XAPKFile[] xAPKS = {new XAPKFile(false, 0, 0)};
    private boolean appHasBeenStoped;
    protected String externalFilesDir;
    protected File externalStorageDir;
    private boolean fmodCopyTaskRunning;
    private String fmodExtractionErrorText;
    private FMODExtractionHandler fmodHandler;
    private boolean hasReadPermission;
    private boolean hasWritePermission;
    private IStub mDownloaderClientStub;
    private ProgressBar mPB;
    private Button mPauseButton;
    private TextView mProgressFraction;
    private TextView mProgressPercent;
    private IDownloaderService mRemoteService;
    private int mState;
    private boolean mStatePaused;
    private TextView mStatusText;
    private Button mWiFiSettingsButton;
    protected String mainObbFileName;
    protected String obbFilePath;
    protected String packageName;
    protected String patchObbFileName;
    private boolean startOnResume;
    protected ProgressDialog mLoadingDialog = null;
    protected ProgressDialog mStartingDialog = null;

    @Override // android.app.Activity
    public void onCreate(Bundle bundle) {
        super.onCreate(bundle);
        log("onCreate START");
        hideStatusBar();
        getWindow().setFlags(128, 128);
        setPaths();
        this.fmodHandler = new FMODExtractionHandler(this.externalFilesDir, FMODSIZE, getAssets(), this.obbFilePath + this.mainObbFileName);
        xAPKS[0].mIsMain = true;
        xAPKS[0].mFileSize = MAIN_OBBFILE_SIZE;
        xAPKS[0].mFileVersion = MAIN_OBBFIILE_VERSION_CODE;
        this.mDownloaderClientStub = DownloaderClientMarshaller.CreateStub(this, FishlabsDownloaderService.class);
        initProgressDialogs();
        initializeDownloadUI();
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        this.mStartingDialog.dismiss();
        log("onDestroy");
        super.onDestroy();
    }

    @Override // android.app.Activity
    protected void onActivityResult(int i, int i2, Intent intent) {
        log("onActivityResult");
        super.onActivityResult(i, i2, intent);
    }

    @Override // com.google.android.vending.expansion.downloader.IDownloaderClient
    public void onServiceConnected(android.os.Messenger messenger) {
        log("onServiceConnected");
        this.mRemoteService = DownloaderServiceMarshaller.CreateProxy(messenger);
        this.mRemoteService.onClientUpdated(this.mDownloaderClientStub.getMessenger());
    }

    @Override // android.app.Activity
    protected void onStart() {
        super.onStart();
        log("onStart");
        this.appHasBeenStoped = false;
        if (this.startOnResume) {
            startGame();
        }
        if (!this.startOnResume) {
            requestPermissionAsync(STORAGE_READ);
        }
        if (this.mDownloaderClientStub != null) {
            this.mDownloaderClientStub.connect(this);
        }
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
    }

    @Override // android.app.Activity
    protected void onStop() {
        super.onStop();
        log("onStop");
        this.appHasBeenStoped = true;
        if (this.mDownloaderClientStub != null) {
            this.mDownloaderClientStub.disconnect(this);
        }
    }

    private void startDownloadingProcess() {
        if (!expansionFilesDelivered()) {
            log("exp-files not delivered!");
            try {
                Intent intent = getIntent();
                Intent intent2 = new Intent(this, getClass());
                intent2.setFlags(335544320);
                intent2.setAction(intent.getAction());
                if (intent.getCategories() != null) {
                    Iterator<String> it = intent.getCategories().iterator();
                    while (it.hasNext()) {
                        intent2.addCategory(it.next());
                    }
                }
                if (DownloaderClientMarshaller.startDownloadServiceIfRequired(this, PendingIntent.getActivity(this, 0, intent2, 134217728), (Class<?>) FishlabsDownloaderService.class) == 0) {
                    log("startResult == No Download required?");
                    this.mStatusText.setText("ERROR! StartResult = No Download required? Is the APK/Version Linked with an OBB-File? ");
                    return;
                }
            } catch (PackageManager.NameNotFoundException e) {
                Log.e(LOG_TAG, "Cannot find own package! MAYDAY!");
                e.printStackTrace();
            }
        } else {
            onDownloadComplete();
        }
        log("onCreate FINISH");
    }

    @Override // com.google.android.vending.expansion.downloader.IDownloaderClient
    public void onDownloadProgress(DownloadProgressInfo downloadProgressInfo) {
        this.mPB.setMax((int) (downloadProgressInfo.mOverallTotal >> 8));
        this.mPB.setProgress((int) (downloadProgressInfo.mOverallProgress >> 8));
        this.mProgressPercent.setText(Long.toString((downloadProgressInfo.mOverallProgress * 100) / downloadProgressInfo.mOverallTotal) + "%");
        this.mProgressFraction.setText(Helpers.getDownloadProgressString(downloadProgressInfo.mOverallProgress, downloadProgressInfo.mOverallTotal));
    }

    @Override // android.app.Activity, android.view.KeyEvent.Callback
    public boolean onKeyDown(int i, KeyEvent keyEvent) {
        if (i == 4 && keyEvent.getRepeatCount() == 0) {
            moveTaskToBack(true);
            return true;
        }
        return super.onKeyDown(i, keyEvent);
    }

    @Override // android.app.Activity, android.content.ComponentCallbacks
    public void onConfigurationChanged(Configuration configuration) {
        log("onConfigurationChanged");
        super.onConfigurationChanged(configuration);
    }

    private void onDownloadComplete() {
        if (!this.fmodHandler.filesAlreadyExtracted() && !this.fmodCopyTaskRunning) {
            runOnUiThread(new Runnable() { // from class: net.fishlabs.gof2hdallandroid2012.DownloaderActivity.1
                @Override // java.lang.Runnable
                public void run() {
                    DownloaderActivity.this.mLoadingDialog.show();
                    new FMODCopyTask().execute(new Void[0]);
                    DownloaderActivity.this.fmodCopyTaskRunning = true;
                }
            });
        } else if (this.fmodHandler.filesAlreadyExtracted()) {
            startGame();
        }
    }

    private void hideStatusBar() {
        WindowManager.LayoutParams attributes = getWindow().getAttributes();
        attributes.flags |= 1024;
        getWindow().setAttributes(attributes);
    }

    private void initProgressDialogs() {
        this.mLoadingDialog = new ProgressDialog(this);
        this.mLoadingDialog.setTitle("Preparing for the first start!");
        this.mLoadingDialog.setMessage("Extracting necessary files in background. This could take a while. Come back later (e.g. check mails) or wait until the process is finished and the game starts automatically.");
        this.mLoadingDialog.setCancelable(false);
        this.mStartingDialog = new ProgressDialog(this);
        this.mStartingDialog.setTitle("Extraction finished!");
        this.mStartingDialog.setMessage("Game is starting ...");
        this.mStartingDialog.setCancelable(false);
    }

    private void setPaths() {
        this.externalStorageDir = Environment.getExternalStorageDirectory();
        this.packageName = getPackageName();
        this.externalFilesDir = getExternalFilesDir(null).getAbsolutePath().toString();
        this.obbFilePath = this.externalStorageDir.toString() + "/Android/obb/" + this.packageName + "/";
        StringBuilder sb = new StringBuilder();
        sb.append("main.47947006.");
        sb.append(this.packageName);
        sb.append(".obb");
        this.mainObbFileName = sb.toString();
        this.patchObbFileName = "patch.." + this.packageName + ".obb";
    }

    boolean expansionFilesDelivered() {
        for (XAPKFile xAPKFile : xAPKS) {
            if (!Helpers.doesFileExist(this, Helpers.getExpansionAPKFileName(this, xAPKFile.mIsMain, xAPKFile.mFileVersion), xAPKFile.mFileSize, false)) {
                return false;
            }
        }
        return true;
    }

    private void initializeDownloadUI() {
        setContentView(R.layout.downloader);
        this.mPB = (ProgressBar) findViewById(R.id.progressBar);
        this.mStatusText = (TextView) findViewById(R.id.statusText);
        this.mStatusText.setText("");
        this.mProgressFraction = (TextView) findViewById(R.id.progressAsFraction);
        this.mProgressPercent = (TextView) findViewById(R.id.progressAsPercentage);
        this.mPauseButton = (Button) findViewById(R.id.actionButton);
        this.mPauseButton.setText("");
        this.mWiFiSettingsButton = (Button) findViewById(R.id.wifiSettingsButton);
        this.mPauseButton.setOnClickListener(new View.OnClickListener() { // from class: net.fishlabs.gof2hdallandroid2012.DownloaderActivity.2
            @Override // android.view.View.OnClickListener
            public void onClick(View view) {
                if (DownloaderActivity.this.mStatePaused) {
                    DownloaderActivity.this.mRemoteService.requestContinueDownload();
                } else if (DownloaderActivity.this.fmodHandler.filesAlreadyExtracted()) {
                    DownloaderActivity.this.startGame();
                } else {
                    DownloaderActivity.this.mRemoteService.requestPauseDownload();
                }
                DownloaderActivity.this.setButtonPausedState(!DownloaderActivity.this.mStatePaused);
            }
        });
        this.mWiFiSettingsButton.setOnClickListener(new View.OnClickListener() { // from class: net.fishlabs.gof2hdallandroid2012.DownloaderActivity.3
            @Override // android.view.View.OnClickListener
            public void onClick(View view) {
                DownloaderActivity.this.startActivity(new Intent("android.settings.WIFI_SETTINGS"));
            }
        });
    }

    public boolean mainObbFileDownloaded() {
        return new File(this.obbFilePath + this.mainObbFileName).exists();
    }

    @Override // com.google.android.vending.expansion.downloader.IDownloaderClient
    public void onDownloadStateChanged(int i) {
        log("onDownloadStateChanged");
        setState(i);
        boolean z = false;
        boolean z2 = true;
        switch (i) {
            case 1:
            case 2:
            case 3:
                z2 = false;
                z = true;
                break;
            case 4:
                z2 = false;
                break;
            case 5:
                onDownloadComplete();
                return;
            case 6:
            case 10:
            case 11:
            case 13:
            case 17:
            default:
                z = true;
                break;
            case 7:
            case 8:
            case 9:
            case 12:
            case 14:
            case 15:
            case 16:
            case 18:
            case 19:
                break;
        }
        this.mPB.setIndeterminate(z);
        setButtonPausedState(z2);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public void setButtonPausedState(boolean z) {
        this.mStatePaused = z;
        this.mPauseButton.setText(z ? R.string.text_button_resume : R.string.text_button_pause);
    }

    private void setState(int i) {
        log("set state " + i);
        if (this.mState != i) {
            this.mState = i;
            this.mStatusText.setText(Helpers.getDownloaderStringResourceIDFromState(i));
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public void startGame() {
        log("starting game... START");
        Intent intent = new Intent(this, (Class<?>) GOF2HD2012.class);
        intent.putExtra(INTENT_EXTERNAL_FILES_DIR, this.externalFilesDir);
        intent.putExtra(INTENT_EXTERNAL_OBB_DIR, this.obbFilePath);
        intent.putExtra(INTENT_EXTERNAL_MAIN_OBB_FILE_NAME, this.mainObbFileName);
        intent.putExtra(INTENT_EXTERNAL_PATCH_OBB_FILE_NAME, this.patchObbFileName);
        startActivity(intent);
        if (this.mStartingDialog.isShowing()) {
            this.mStartingDialog.dismiss();
        }
        finish();
        log("starting game... END");
    }

    private class FMODCopyTask extends AsyncTask<Void, Void, Void> {
        private FMODCopyTask() {
        }

        @Override // android.os.AsyncTask
        protected void onPreExecute() {
            DownloaderActivity.this.runOnUiThread(new Runnable() { // from class: net.fishlabs.gof2hdallandroid2012.DownloaderActivity.FMODCopyTask.1
                @Override // java.lang.Runnable
                public void run() {
                    DownloaderActivity.this.log("FMODcopy: onPre");
                    DownloaderActivity.this.mProgressFraction.setText("Please wait...");
                    DownloaderActivity.this.mProgressPercent.setText("");
                    DownloaderActivity.this.mStatusText.setText("Extracting necessary files...");
                    DownloaderActivity.this.mPauseButton.setVisibility(4);
                    DownloaderActivity.this.log("FMODcopy: onPre finished");
                }
            });
        }

        /* JADX INFO: Access modifiers changed from: protected */
        @Override // android.os.AsyncTask
        public Void doInBackground(Void... voidArr) {
            DownloaderActivity.this.log("FMODcopy: doInBackground...");
            try {
                DownloaderActivity.this.fmodHandler.extractFMODFiles();
                DownloaderActivity.this.fmodExtractionErrorText = null;
            } catch (IOException e) {
                DownloaderActivity.this.fmodExtractionErrorText = "IOError during FMOD-Extraction: " + e.toString();
                DownloaderActivity.this.runOnUiThread(new Runnable() { // from class: net.fishlabs.gof2hdallandroid2012.DownloaderActivity.FMODCopyTask.2
                    @Override // java.lang.Runnable
                    public void run() {
                        DownloaderActivity.this.mLoadingDialog.dismiss();
                        DownloaderActivity.this.mStatusText.setText(DownloaderActivity.this.fmodExtractionErrorText);
                    }
                });
                Log.e(DownloaderActivity.LOG_TAG, DownloaderActivity.this.fmodExtractionErrorText);
            }
            DownloaderActivity.this.log("FMODcopy: doInBackground finished!");
            return null;
        }

        /* JADX INFO: Access modifiers changed from: protected */
        @Override // android.os.AsyncTask
        public void onPostExecute(Void r2) {
            DownloaderActivity.this.runOnUiThread(new Runnable() { // from class: net.fishlabs.gof2hdallandroid2012.DownloaderActivity.FMODCopyTask.3
                @Override // java.lang.Runnable
                public void run() {
                    if (!DownloaderActivity.this.isFinishing()) {
                        DownloaderActivity.this.log("FMODcopy: onPost");
                        DownloaderActivity.this.fmodCopyTaskRunning = false;
                        DownloaderActivity.this.mLoadingDialog.dismiss();
                        DownloaderActivity.this.mStatusText.setText("..extraction finished! Game should start right now!!");
                        DownloaderActivity.this.mPauseButton.setText(android.R.string.ok);
                        DownloaderActivity.this.mPauseButton.setVisibility(4);
                        DownloaderActivity.this.mWiFiSettingsButton.setVisibility(4);
                        DownloaderActivity.this.mStartingDialog.show();
                    }
                    if (!DownloaderActivity.this.appHasBeenStoped) {
                        DownloaderActivity.this.startGame();
                    } else {
                        DownloaderActivity.this.startOnResume = true;
                    }
                    DownloaderActivity.this.log("FMODcopy: onPost finished!");
                }
            });
        }
    }

    private static class XAPKFile {
        protected long mFileSize;
        protected int mFileVersion;
        protected boolean mIsMain;

        XAPKFile(boolean z, int i, long j) {
            this.mIsMain = z;
            this.mFileVersion = i;
            this.mFileSize = j;
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public void log(String str) {
        Log.i(LOG_TAG, str);
    }

    private boolean hasPermission(@NonNull String str) {
        return !str.isEmpty() && ContextCompat.checkSelfPermission(this, str) == 0;
    }

    public void requestPermissionAsync(@NonNull final String str) {
        if (!hasPermission(str)) {
            if (ActivityCompat.shouldShowRequestPermissionRationale(this, str)) {
                runOnUiThread(new Runnable() { // from class: net.fishlabs.gof2hdallandroid2012.DownloaderActivity.4
                    @Override // java.lang.Runnable
                    public void run() {
                        new AlertDialog.Builder(DownloaderActivity.this).setIcon(android.R.drawable.ic_dialog_alert).setTitle(R.string.permission_ext_storage_required_title).setMessage(R.string.permission_ext_storage_required_text).setCancelable(false).setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener() { // from class: net.fishlabs.gof2hdallandroid2012.DownloaderActivity.4.1
                            @Override // android.content.DialogInterface.OnClickListener
                            public void onClick(DialogInterface dialogInterface, int i) {
                                ActivityCompat.requestPermissions(DownloaderActivity.this, new String[]{str}, DownloaderActivity.PERMISSION_REQUEST_ID);
                            }
                        }).show();
                    }
                });
                return;
            } else {
                ActivityCompat.requestPermissions(this, new String[]{str}, PERMISSION_REQUEST_ID);
                return;
            }
        }
        onRequestPermissionsResult(PERMISSION_REQUEST_ID, new String[]{str}, new int[]{0});
    }

    @Override // android.app.Activity
    public void onRequestPermissionsResult(int i, @NonNull String[] strArr, @NonNull int[] iArr) {
        if (i == PERMISSION_REQUEST_ID && iArr.length > 0) {
            boolean z = iArr[0] == 0;
            boolean zShouldShowRequestPermissionRationale = ActivityCompat.shouldShowRequestPermissionRationale(this, strArr[0]);
            if (!z && !zShouldShowRequestPermissionRationale) {
                startSettingsActivityAsync();
                return;
            }
            if (z) {
                if (strArr[0].equals(STORAGE_READ)) {
                    this.hasReadPermission = true;
                    requestPermissionAsync(STORAGE_WRITE);
                } else if (strArr[0].equals(STORAGE_WRITE)) {
                    this.hasWritePermission = true;
                }
                if (this.hasReadPermission && this.hasWritePermission) {
                    startDownloadingProcess();
                    return;
                }
                return;
            }
            requestPermissionAsync(strArr[0]);
        }
    }

    /* JADX INFO: renamed from: net.fishlabs.gof2hdallandroid2012.DownloaderActivity$5, reason: invalid class name */
    class AnonymousClass5 implements Runnable {
        AnonymousClass5() {
        }

        @Override // java.lang.Runnable
        public void run() {
            new AlertDialog.Builder(DownloaderActivity.this).setIcon(android.R.drawable.ic_dialog_alert).setTitle(R.string.permission_ext_storage_error_title).setMessage(R.string.permission_ext_storage_error_text).setCancelable(false).setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener() { // from class: net.fishlabs.gof2hdallandroid2012.DownloaderActivity.5.1
                @Override // android.content.DialogInterface.OnClickListener
                public void onClick(DialogInterface dialogInterface, int i) {
                    DownloaderActivity.this.runOnUiThread(new Runnable() { // from class: net.fishlabs.gof2hdallandroid2012.DownloaderActivity.5.1.1
                        @Override // java.lang.Runnable
                        public void run() {
                            Intent intent = new Intent("android.settings.APPLICATION_DETAILS_SETTINGS");
                            intent.addFlags(DriveFile.MODE_READ_ONLY);
                            intent.setData(Uri.fromParts("package", DownloaderActivity.this.getPackageName(), null));
                            DownloaderActivity.this.startActivity(intent);
                            System.exit(0);
                        }
                    });
                }
            }).show();
        }
    }

    private void startSettingsActivityAsync() {
        runOnUiThread(new AnonymousClass5());
    }
}
