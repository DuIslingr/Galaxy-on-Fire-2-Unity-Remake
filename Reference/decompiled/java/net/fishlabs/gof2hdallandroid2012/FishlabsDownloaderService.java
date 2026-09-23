package net.fishlabs.gof2hdallandroid2012;

import com.google.android.vending.expansion.downloader.impl.DownloaderService;

/* JADX INFO: loaded from: classes.dex */
public class FishlabsDownloaderService extends DownloaderService {
    public static final String BASE64_PUBLIC_KEY = "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAiSfBidMj3fOEJih9J4/2RUjqwsjbcl1O1gbHSVB9LpKh5G5ds0rLsVGw52j44szFre/CinNDST/OjnDBkMlrewUxZwXPrYycO3JTE3BjS9Fl8kADtN2aU4LvdVGZBSk32TVgqBLLGDNUFfda3fv+MTQmcXDCFmTRbZwjHFhGOd56L3RO35KUszkak9ST5UL2nNJL9yOqcQ2BWkT+oI3ahALETTUCE6VdHEoliW9Mb+E9BaU2hOmowkJIWQhkbw+d4d44Y9dqVSwNS7N453IVwifLXANv7MY+9nIO7qHtGTNQC1VKgcHEs/slbpqahUBcsifJP3xgD6/pNbOzGHpYVQIDAQAB";
    private static final byte[] SALT = {1, 43, -12, -1, 54, 98, -100, -12, 43, 2, -8, -4, 9, 5, -106, -108, -33, 45, -1, 84};

    @Override // com.google.android.vending.expansion.downloader.impl.DownloaderService
    public String getPublicKey() {
        return BASE64_PUBLIC_KEY;
    }

    @Override // com.google.android.vending.expansion.downloader.impl.DownloaderService
    public byte[] getSALT() {
        return SALT;
    }

    @Override // com.google.android.vending.expansion.downloader.impl.DownloaderService
    public String getAlarmReceiverClassName() {
        return AlarmReceiver.class.getName();
    }
}
