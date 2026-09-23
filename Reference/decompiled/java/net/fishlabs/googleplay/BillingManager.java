package net.fishlabs.googleplay;

import android.app.Activity;
import android.content.Context;
import android.util.Log;
import com.android.billingclient.api.BillingClient;
import com.android.billingclient.api.BillingClientStateListener;
import com.android.billingclient.api.BillingFlowParams;
import com.android.billingclient.api.ConsumeResponseListener;
import com.android.billingclient.api.Purchase;
import com.android.billingclient.api.PurchasesUpdatedListener;
import com.android.billingclient.api.SkuDetails;
import com.android.billingclient.api.SkuDetailsParams;
import com.android.billingclient.api.SkuDetailsResponseListener;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;

/* JADX INFO: loaded from: classes.dex */
public class BillingManager implements PurchasesUpdatedListener {
    private static String BASE_64_ENCODED_PUBLIC_KEY = "CONSTRUCT_YOUR_KEY_AND_PLACE_IT_HERE";
    public static final int BILLING_MANAGER_NOT_INITIALIZED = -1;
    private static final String TAG = "BillingManager";
    private final Activity mActivity;
    private BillingClient mBillingClient;
    private final BillingUpdatesListener mBillingUpdatesListener;
    private boolean mIsServiceConnected;
    private Set<String> mTokensToBeConsumed;
    private final List<Purchase> mPurchases = new ArrayList();
    private int mBillingClientResponseCode = -1;

    public interface BillingUpdatesListener {
        void onBillingClientSetupFinished();

        void onConsumeFinished(String str, int i);

        void onPurchasesUpdated(List<Purchase> list);
    }

    public interface ServiceConnectedListener {
        void onServiceConnected(int i);
    }

    public BillingManager(Activity activity, BillingUpdatesListener billingUpdatesListener, String str) {
        Log.d(TAG, "Creating Billing client.");
        this.mActivity = activity;
        this.mBillingUpdatesListener = billingUpdatesListener;
        BASE_64_ENCODED_PUBLIC_KEY = str;
        this.mBillingClient = BillingClient.newBuilder(this.mActivity).setListener(this).build();
        Log.d(TAG, "Starting setup.");
        startServiceConnection(new Runnable() { // from class: net.fishlabs.googleplay.BillingManager.1
            @Override // java.lang.Runnable
            public void run() {
                BillingManager.this.mBillingUpdatesListener.onBillingClientSetupFinished();
                Log.d(BillingManager.TAG, "Setup successful. Querying inventory.");
                BillingManager.this.queryPurchases();
            }
        });
    }

    @Override // com.android.billingclient.api.PurchasesUpdatedListener
    public void onPurchasesUpdated(int i, List<Purchase> list) {
        if (i == 0) {
            if (list != null) {
                Iterator<Purchase> it = list.iterator();
                while (it.hasNext()) {
                    handlePurchase(it.next());
                }
            }
            this.mBillingUpdatesListener.onPurchasesUpdated(this.mPurchases);
            return;
        }
        if (i == 1) {
            Log.i(TAG, "onPurchasesUpdated() - user cancelled the purchase flow - skipping");
            return;
        }
        Log.w(TAG, "onPurchasesUpdated() got unknown resultCode: " + i);
    }

    public void initiatePurchaseFlow(String str, String str2) {
        initiatePurchaseFlow(str, null, str2);
    }

    public void initiatePurchaseFlow(final String str, final ArrayList<String> arrayList, final String str2) {
        executeServiceRequest(new Runnable() { // from class: net.fishlabs.googleplay.BillingManager.2
            @Override // java.lang.Runnable
            public void run() {
                StringBuilder sb = new StringBuilder();
                sb.append("Launching in-app purchase flow. Replace old SKU? ");
                sb.append(arrayList != null);
                Log.d(BillingManager.TAG, sb.toString());
                BillingManager.this.mBillingClient.launchBillingFlow(BillingManager.this.mActivity, BillingFlowParams.newBuilder().setSku(str).setType(str2).setOldSkus(arrayList).build());
            }
        });
    }

    public Context getContext() {
        return this.mActivity;
    }

    public void destroy() {
        Log.d(TAG, "Destroying the manager.");
        if (this.mBillingClient == null || !this.mBillingClient.isReady()) {
            return;
        }
        this.mBillingClient.endConnection();
        this.mBillingClient = null;
    }

    public void querySkuDetailsAsync(final String str, final List<String> list, final SkuDetailsResponseListener skuDetailsResponseListener) {
        executeServiceRequest(new Runnable() { // from class: net.fishlabs.googleplay.BillingManager.3
            @Override // java.lang.Runnable
            public void run() {
                SkuDetailsParams.Builder builderNewBuilder = SkuDetailsParams.newBuilder();
                builderNewBuilder.setSkusList(list).setType(str);
                BillingManager.this.mBillingClient.querySkuDetailsAsync(builderNewBuilder.build(), new SkuDetailsResponseListener() { // from class: net.fishlabs.googleplay.BillingManager.3.1
                    @Override // com.android.billingclient.api.SkuDetailsResponseListener
                    public void onSkuDetailsResponse(int i, List<SkuDetails> list2) {
                        skuDetailsResponseListener.onSkuDetailsResponse(i, list2);
                    }
                });
            }
        });
    }

    public void consumeAsync(final String str) {
        if (this.mTokensToBeConsumed == null) {
            this.mTokensToBeConsumed = new HashSet();
        } else if (this.mTokensToBeConsumed.contains(str)) {
            Log.i(TAG, "Token was already scheduled to be consumed - skipping...");
            return;
        }
        this.mTokensToBeConsumed.add(str);
        final ConsumeResponseListener consumeResponseListener = new ConsumeResponseListener() { // from class: net.fishlabs.googleplay.BillingManager.4
            @Override // com.android.billingclient.api.ConsumeResponseListener
            public void onConsumeResponse(int i, String str2) {
                BillingManager.this.mBillingUpdatesListener.onConsumeFinished(str2, i);
            }
        };
        executeServiceRequest(new Runnable() { // from class: net.fishlabs.googleplay.BillingManager.5
            @Override // java.lang.Runnable
            public void run() {
                BillingManager.this.mBillingClient.consumeAsync(str, consumeResponseListener);
            }
        });
    }

    public int getBillingClientResponseCode() {
        return this.mBillingClientResponseCode;
    }

    private void handlePurchase(Purchase purchase) {
        if (!verifyValidSignature(purchase.getOriginalJson(), purchase.getSignature())) {
            Log.i(TAG, "Got a purchase: " + purchase + "; but signature is bad. Skipping...");
            return;
        }
        Log.d(TAG, "Got a verified purchase: " + purchase);
        this.mPurchases.add(purchase);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public void onQueryPurchasesFinished(Purchase.PurchasesResult purchasesResult) {
        if (this.mBillingClient == null || purchasesResult.getResponseCode() != 0) {
            Log.w(TAG, "Billing client was null or result code (" + purchasesResult.getResponseCode() + ") was bad - quitting");
            return;
        }
        Log.d(TAG, "Query inventory was successful.");
        this.mPurchases.clear();
        onPurchasesUpdated(0, purchasesResult.getPurchasesList());
    }

    public boolean areSubscriptionsSupported() {
        int iIsFeatureSupported = this.mBillingClient.isFeatureSupported(BillingClient.FeatureType.SUBSCRIPTIONS);
        if (iIsFeatureSupported != 0) {
            Log.w(TAG, "areSubscriptionsSupported() got an error response: " + iIsFeatureSupported);
        }
        return iIsFeatureSupported == 0;
    }

    public void queryPurchases() {
        executeServiceRequest(new Runnable() { // from class: net.fishlabs.googleplay.BillingManager.6
            @Override // java.lang.Runnable
            public void run() {
                long jCurrentTimeMillis = System.currentTimeMillis();
                Purchase.PurchasesResult purchasesResultQueryPurchases = BillingManager.this.mBillingClient.queryPurchases(BillingClient.SkuType.INAPP);
                Log.i(BillingManager.TAG, "Querying purchases elapsed time: " + (System.currentTimeMillis() - jCurrentTimeMillis) + "ms");
                if (BillingManager.this.areSubscriptionsSupported()) {
                    Purchase.PurchasesResult purchasesResultQueryPurchases2 = BillingManager.this.mBillingClient.queryPurchases(BillingClient.SkuType.SUBS);
                    Log.i(BillingManager.TAG, "Querying purchases and subscriptions elapsed time: " + (System.currentTimeMillis() - jCurrentTimeMillis) + "ms");
                    int size = purchasesResultQueryPurchases2.getPurchasesList() != null ? purchasesResultQueryPurchases2.getPurchasesList().size() : 0;
                    Log.i(BillingManager.TAG, "Querying subscriptions result code: " + purchasesResultQueryPurchases2.getResponseCode() + " res: " + Integer.toString(size));
                    if (purchasesResultQueryPurchases2.getResponseCode() != 0) {
                        Log.e(BillingManager.TAG, "Got an error response trying to query subscription purchases");
                    } else if (size > 0) {
                        purchasesResultQueryPurchases.getPurchasesList().addAll(purchasesResultQueryPurchases2.getPurchasesList());
                    }
                } else if (purchasesResultQueryPurchases.getResponseCode() == 0) {
                    Log.i(BillingManager.TAG, "Skipped subscription purchases query since they are not supported");
                } else {
                    Log.w(BillingManager.TAG, "queryPurchases() got an error response code: " + purchasesResultQueryPurchases.getResponseCode());
                }
                BillingManager.this.onQueryPurchasesFinished(purchasesResultQueryPurchases);
            }
        });
    }

    public void startServiceConnection(final Runnable runnable) {
        this.mBillingClient.startConnection(new BillingClientStateListener() { // from class: net.fishlabs.googleplay.BillingManager.7
            @Override // com.android.billingclient.api.BillingClientStateListener
            public void onBillingSetupFinished(int i) {
                Log.d(BillingManager.TAG, "Setup finished. Response code: " + i);
                if (i == 0) {
                    BillingManager.this.mIsServiceConnected = true;
                    if (runnable != null) {
                        runnable.run();
                    }
                }
                BillingManager.this.mBillingClientResponseCode = i;
            }

            @Override // com.android.billingclient.api.BillingClientStateListener
            public void onBillingServiceDisconnected() {
                BillingManager.this.mIsServiceConnected = false;
            }
        });
    }

    private void executeServiceRequest(Runnable runnable) {
        if (this.mIsServiceConnected) {
            runnable.run();
        } else {
            startServiceConnection(runnable);
        }
    }

    private boolean verifyValidSignature(String str, String str2) {
        if (BASE_64_ENCODED_PUBLIC_KEY.contains("CONSTRUCT_YOUR")) {
            throw new RuntimeException("Please update your app's public key at: BASE_64_ENCODED_PUBLIC_KEY");
        }
        try {
            return Security.verifyPurchase(BASE_64_ENCODED_PUBLIC_KEY, str, str2);
        } catch (IOException e) {
            Log.e(TAG, "Got an exception trying to validate a purchase: " + e);
            return false;
        }
    }
}
