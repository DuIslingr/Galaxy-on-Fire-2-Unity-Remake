package net.fishlabs.googleplay;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import com.android.billingclient.api.BillingClient;
import com.android.billingclient.api.Purchase;
import com.android.billingclient.api.SkuDetails;
import com.android.billingclient.api.SkuDetailsResponseListener;
import com.google.android.vending.expansion.downloader.Constants;
import java.util.HashMap;
import java.util.List;
import java.util.concurrent.ConcurrentHashMap;

/* JADX INFO: loaded from: classes.dex */
public class GooglePlayIAP implements BillingManager.BillingUpdatesListener, SkuDetailsResponseListener {
    private static boolean DLC_1_BOUGHT = false;
    private static boolean DLC_2_BOUGHT = false;
    private static boolean DLC_3_BOUGHT = false;
    private static boolean DLC_4_BOUGHT = false;
    private static boolean DLC_5_BOUGHT = false;
    private static final int _AVAILABLE_CONSUMABLES = 5;
    private static final int _AVAILABLE_PREMIUM_SKUS = 5;
    private Activity ACTIVITY;
    private Context CONTEXT;
    private String base64EncodedPublicKey;
    private final HashMap<String, Integer> consumableSkuList = new HashMap<>();
    private final ConcurrentHashMap<String, Integer> consumableTokens = new ConcurrentHashMap<>();
    private boolean mBillingClientSetupFinished = false;
    private BillingManager mBillingManager;
    private static final String _DESCRIPTION_MARKER = String.valueOf(" $");
    private static final String _DESCRIPTION_100_000 = String.valueOf("100.000");
    private static final String _DESCRIPTION_300_000 = String.valueOf("300.000");
    private static final String _DESCRIPTION_1_000_000 = String.valueOf("1.000.000");
    private static final String _DESCRIPTION_3_000_000 = String.valueOf("3.000.000");
    private static final String _DESCRIPTION_10_000_000 = String.valueOf("10.000.000");
    private static final String _notAvailable = String.valueOf(Constants.FILENAME_SEQUENCE_SEPARATOR);
    private static String[] itemListCurrency = new String[5];
    private static String[] itemListDescription = new String[5];
    private static String[] itemListIDs = new String[5];
    private static String[] itemListNames = new String[5];
    private static String[] itemListPrices = new String[5];

    public void iap_buy_kaamo_club() {
        ToJNI.iapBoughtPremium(1, 1);
        setDLC_2_BOUGHT(true);
    }

    public GooglePlayIAP(Context context, Activity activity, String str) {
        setUpConsumables();
        this.CONTEXT = context;
        this.ACTIVITY = activity;
        this.base64EncodedPublicKey = ToJNI.gof2hd2012apk();
        this.mBillingManager = new BillingManager(this.ACTIVITY, this, this.base64EncodedPublicKey);
        ToJNI.iapBoughtPremium(0, 1);
        setDLC_1_BOUGHT(true);
        ToJNI.iapBoughtPremium(2, 1);
        setDLC_3_BOUGHT(true);
        ToJNI.iapBoughtPremium(3, 1);
        setDLC_4_BOUGHT(true);
        ToJNI.iapBoughtPremium(4, 1);
        setDLC_5_BOUGHT(true);
    }

    private void setUpConsumables() {
        itemListDescription[0] = _DESCRIPTION_100_000 + _DESCRIPTION_MARKER;
        itemListDescription[1] = _DESCRIPTION_300_000 + _DESCRIPTION_MARKER;
        itemListDescription[2] = _DESCRIPTION_1_000_000 + _DESCRIPTION_MARKER;
        itemListDescription[3] = _DESCRIPTION_3_000_000 + _DESCRIPTION_MARKER;
        itemListDescription[4] = _DESCRIPTION_10_000_000 + _DESCRIPTION_MARKER;
        for (int i = 0; i < 5; i++) {
            itemListIDs[i] = _notAvailable;
            itemListNames[i] = _notAvailable;
            itemListCurrency[i] = _notAvailable;
            itemListPrices[i] = _notAvailable;
        }
        ToJNI.iapSetNativeItemInformationList(itemListIDs, itemListNames, itemListDescription, itemListCurrency, itemListPrices);
    }

    public void destroy() {
        if (this.mBillingManager != null) {
            this.mBillingManager.destroy();
        }
        this.mBillingClientSetupFinished = false;
    }

    public boolean isSetUp() {
        return this.mBillingManager != null && this.mBillingClientSetupFinished;
    }

    public void iap_buy_valkyrie() {
        if (this.mBillingManager != null) {
            this.mBillingManager.initiatePurchaseFlow(ToJNI.gof2hd2012getPremiumSKU(0), BillingClient.SkuType.INAPP);
        }
    }

    public void iap_buy_supernova() {
        if (this.mBillingManager != null) {
            this.mBillingManager.initiatePurchaseFlow(ToJNI.gof2hd2012getPremiumSKU(2), BillingClient.SkuType.INAPP);
        }
    }

    public void iap_buy_vip_package() {
        if (this.mBillingManager != null) {
            this.mBillingManager.initiatePurchaseFlow(ToJNI.gof2hd2012getPremiumSKU(3), BillingClient.SkuType.INAPP);
        }
    }

    public void iap_buy_full_package() {
        if (this.mBillingManager != null) {
            this.mBillingManager.initiatePurchaseFlow(ToJNI.gof2hd2012getPremiumSKU(4), BillingClient.SkuType.INAPP);
        }
    }

    public void iap_restore_purchases() {
        if (this.mBillingManager != null) {
            this.mBillingManager.queryPurchases();
        }
    }

    public void iap_buy_credits_100_000() {
        if (this.mBillingManager != null) {
            this.mBillingManager.initiatePurchaseFlow(ToJNI.gof2hd2012getConsumableSKU(0), BillingClient.SkuType.INAPP);
        }
    }

    public void iap_buy_credits_300_000() {
        if (this.mBillingManager != null) {
            this.mBillingManager.initiatePurchaseFlow(ToJNI.gof2hd2012getConsumableSKU(1), BillingClient.SkuType.INAPP);
        }
    }

    public void iap_buy_credits_1_000_000() {
        if (this.mBillingManager != null) {
            this.mBillingManager.initiatePurchaseFlow(ToJNI.gof2hd2012getConsumableSKU(2), BillingClient.SkuType.INAPP);
        }
    }

    public void iap_buy_credits_3_000_000() {
        if (this.mBillingManager != null) {
            this.mBillingManager.initiatePurchaseFlow(ToJNI.gof2hd2012getConsumableSKU(3), BillingClient.SkuType.INAPP);
        }
    }

    public void iap_buy_credits_10_000_000() {
        if (this.mBillingManager != null) {
            this.mBillingManager.initiatePurchaseFlow(ToJNI.gof2hd2012getConsumableSKU(4), BillingClient.SkuType.INAPP);
        }
    }

    private void complain(String str) {
        alert(str);
    }

    private void alert(String str) {
        if (this.CONTEXT != null) {
            AlertDialog.Builder builder = new AlertDialog.Builder(this.CONTEXT);
            builder.setMessage(str);
            builder.setNeutralButton("OK", (DialogInterface.OnClickListener) null);
            builder.create().show();
        }
    }

    public boolean getDLC_1_BOUGHT() {
        boolean z = DLC_1_BOUGHT;
        return true;
    }

    public boolean getDLC_2_BOUGHT() {
        return DLC_2_BOUGHT;
    }

    public boolean getDLC_3_BOUGHT() {
        boolean z = DLC_3_BOUGHT;
        return true;
    }

    public boolean getDLC_4_BOUGHT() {
        boolean z = DLC_4_BOUGHT;
        return true;
    }

    public boolean getDLC_5_BOUGHT() {
        boolean z = DLC_5_BOUGHT;
        return true;
    }

    public void setDLC_1_BOUGHT(boolean z) {
        DLC_1_BOUGHT = z;
    }

    public void setDLC_2_BOUGHT(boolean z) {
        DLC_2_BOUGHT = z;
    }

    public void setDLC_3_BOUGHT(boolean z) {
        DLC_3_BOUGHT = z;
    }

    public void setDLC_4_BOUGHT(boolean z) {
        DLC_4_BOUGHT = z;
    }

    public void setDLC_5_BOUGHT(boolean z) {
        DLC_5_BOUGHT = z;
    }

    @Override // net.fishlabs.googleplay.BillingManager.BillingUpdatesListener
    public void onBillingClientSetupFinished() {
        this.mBillingClientSetupFinished = true;
        this.consumableSkuList.clear();
        for (int i = 0; i < 5; i++) {
            String strGof2hd2012getConsumableSKU = ToJNI.gof2hd2012getConsumableSKU(i);
            if (strGof2hd2012getConsumableSKU != null) {
                this.consumableSkuList.put(strGof2hd2012getConsumableSKU, Integer.valueOf(i));
            }
        }
    }

    @Override // net.fishlabs.googleplay.BillingManager.BillingUpdatesListener
    public void onConsumeFinished(String str, int i) {
        Integer num;
        if (i != 0 || (num = this.consumableTokens.get(str)) == null) {
            return;
        }
        ToJNI.iapBoughtConsumable(num.intValue());
        this.consumableSkuList.remove(str);
    }

    @Override // net.fishlabs.googleplay.BillingManager.BillingUpdatesListener
    public void onPurchasesUpdated(List<Purchase> list) {
        HashMap map = new HashMap();
        for (int i = 0; i < 5; i++) {
            String strGof2hd2012getPremiumSKU = ToJNI.gof2hd2012getPremiumSKU(i);
            if (strGof2hd2012getPremiumSKU != null) {
                map.put(strGof2hd2012getPremiumSKU, Integer.valueOf(i));
            }
        }
        for (Purchase purchase : list) {
            if (purchase != null) {
                String sku = purchase.getSku();
                Integer num = (Integer) map.get(sku);
                if (num != null) {
                    ToJNI.iapBoughtPremium(num.intValue(), 1);
                    switch (num.intValue()) {
                        case 0:
                            setDLC_1_BOUGHT(true);
                            break;
                        case 1:
                            setDLC_2_BOUGHT(true);
                            break;
                        case 2:
                            setDLC_3_BOUGHT(true);
                            break;
                        case 3:
                            setDLC_4_BOUGHT(true);
                            break;
                        case 4:
                            setDLC_5_BOUGHT(true);
                            break;
                    }
                } else {
                    Integer num2 = this.consumableSkuList.get(sku);
                    if (num2 != null) {
                        String purchaseToken = purchase.getPurchaseToken();
                        this.consumableTokens.put(purchaseToken, Integer.valueOf(num2.intValue()));
                        this.mBillingManager.consumeAsync(purchaseToken);
                    }
                }
            }
        }
    }

    @Override // com.android.billingclient.api.SkuDetailsResponseListener
    public void onSkuDetailsResponse(int i, List<SkuDetails> list) {
        if (i == 0) {
            for (SkuDetails skuDetails : list) {
                Integer num = this.consumableSkuList.get(skuDetails.getSku());
                if (num != null) {
                    itemListPrices[num.intValue()] = skuDetails.getPrice();
                }
            }
            ToJNI.iapSetNativeItemInformationList(itemListIDs, itemListNames, itemListDescription, itemListCurrency, itemListPrices);
        }
    }
}
