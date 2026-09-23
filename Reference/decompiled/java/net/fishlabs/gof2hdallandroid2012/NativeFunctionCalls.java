package net.fishlabs.gof2hdallandroid2012;

import android.os.Message;

/* JADX INFO: loaded from: classes.dex */
public class NativeFunctionCalls {
    public static GOF2HD2012 Gof2Activity;

    protected static void free_credits_open_offerwall() {
    }

    protected static void iap_buy_dlc_valkyrie() {
        GOF2HD2012.getStaticIAP().iap_buy_valkyrie();
    }

    protected static void iap_buy_dlc_kaamo_club() {
        GOF2HD2012.getStaticIAP().iap_buy_kaamo_club();
    }

    protected static void iap_buy_dlc_supernova() {
        GOF2HD2012.getStaticIAP().iap_buy_supernova();
    }

    protected static void iap_buy_dlc_vip() {
        GOF2HD2012.getStaticIAP().iap_buy_vip_package();
    }

    protected static void iap_buy_dlc_full_package() {
        GOF2HD2012.getStaticIAP().iap_buy_full_package();
    }

    protected static void iap_restore_purchases() {
        GOF2HD2012.getStaticIAP().iap_restore_purchases();
    }

    protected static void iap_buy_credits_100_000() {
        GOF2HD2012.getStaticIAP().iap_buy_credits_100_000();
    }

    protected static void iap_buy_credits_300_000() {
        GOF2HD2012.getStaticIAP().iap_buy_credits_300_000();
    }

    protected static void iap_buy_credits_1_000_000() {
        GOF2HD2012.getStaticIAP().iap_buy_credits_1_000_000();
    }

    protected static void iap_buy_credits_3_000_000() {
        GOF2HD2012.getStaticIAP().iap_buy_credits_3_000_000();
    }

    protected static void iap_buy_credits_10_000_000() {
        GOF2HD2012.getStaticIAP().iap_buy_credits_10_000_000();
    }

    protected static void free_credits_watchVideo() {
        if (GLViewRenderer.getContext() != null) {
            try {
                Message messageObtain = Message.obtain();
                messageObtain.setTarget(GLViewRenderer.getContext().mHandler);
                messageObtain.what = 41;
                messageObtain.sendToTarget();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    protected static void free_credits_likeGOF2OnFacebook() {
        if (GLViewRenderer.getContext() != null) {
            try {
                Message messageObtain = Message.obtain();
                messageObtain.setTarget(GLViewRenderer.getContext().mHandler);
                messageObtain.what = 42;
                messageObtain.sendToTarget();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    protected static void free_credits_likeFishlabsOnFacebook() {
        if (GLViewRenderer.getContext() != null) {
            try {
                Message messageObtain = Message.obtain();
                messageObtain.setTarget(GLViewRenderer.getContext().mHandler);
                messageObtain.what = 43;
                messageObtain.sendToTarget();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    protected static void free_credits_subscribeToYoutubeChannel() {
        if (GLViewRenderer.getContext() != null) {
            try {
                Message messageObtain = Message.obtain();
                messageObtain.setTarget(GLViewRenderer.getContext().mHandler);
                messageObtain.what = 44;
                messageObtain.sendToTarget();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    protected static void free_credits_followOnTwitter() {
        if (GLViewRenderer.getContext() != null) {
            try {
                Message messageObtain = Message.obtain();
                messageObtain.setTarget(GLViewRenderer.getContext().mHandler);
                messageObtain.what = 45;
                messageObtain.sendToTarget();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    protected static void free_credits_rateGame() {
        if (GLViewRenderer.getContext() != null) {
            try {
                Message messageObtain = Message.obtain();
                messageObtain.setTarget(GLViewRenderer.getContext().mHandler);
                messageObtain.what = 46;
                messageObtain.sendToTarget();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    protected static void showMoreGames() {
        if (GLViewRenderer.getContext() != null) {
            try {
                Message messageObtain = Message.obtain();
                messageObtain.setTarget(GLViewRenderer.getContext().mHandler);
                messageObtain.what = 47;
                messageObtain.sendToTarget();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    protected static void rateGame() {
        if (GLViewRenderer.getContext() != null) {
            try {
                Message messageObtain = Message.obtain();
                messageObtain.setTarget(GLViewRenderer.getContext().mHandler);
                messageObtain.what = 48;
                messageObtain.sendToTarget();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    protected static void openPrivacyPolicy() {
        if (GLViewRenderer.getContext() != null) {
            try {
                Message messageObtain = Message.obtain();
                messageObtain.setTarget(GLViewRenderer.getContext().mHandler);
                messageObtain.what = 50;
                messageObtain.sendToTarget();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    protected static void openTermsOfService() {
        if (GLViewRenderer.getContext() != null) {
            try {
                Message messageObtain = Message.obtain();
                messageObtain.setTarget(GLViewRenderer.getContext().mHandler);
                messageObtain.what = 49;
                messageObtain.sendToTarget();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
