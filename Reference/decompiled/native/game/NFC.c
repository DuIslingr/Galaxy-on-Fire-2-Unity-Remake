// Class: NFC
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== NFC::NFC  @0x00071a80  (2 bytes)
/* NFC::NFC() */

NFC * __thiscall NFC::NFC(NFC *this)

{
  return this;
}

// ===== NFC::iap_buy_dlc_valkyrie  @0x00071a84  (80 bytes)
/* NFC::iap_buy_dlc_valkyrie() */

void NFC::iap_buy_dlc_valkyrie(void)

{
  _jmethodID *p_Var1;
  undefined4 uVar2;
  
  if (g_pEnv != (_jclass *)0x0) {
    gi_iap_buy_dlc1_pressed = 1;
    p_Var1 = (_jmethodID *)(**(code **)(*(int *)g_pEnv + 0x18))(g_pEnv,interface_path);
    uVar2 = (**(code **)(*(int *)g_pEnv + 0x1c4))
                      (g_pEnv,p_Var1,"iap_buy_dlc_valkyrie",&DAT_0021f19b);
    _JNIEnv::CallStaticVoidMethod(g_pEnv,p_Var1,uVar2);
    return;
  }
  return;
}

// ===== NFC::iap_buy_dlc_kaamo_club  @0x00071b3c  (80 bytes)
/* NFC::iap_buy_dlc_kaamo_club() */

void NFC::iap_buy_dlc_kaamo_club(void)

{
  _jmethodID *p_Var1;
  undefined4 uVar2;
  
  if (g_pEnv != (_jclass *)0x0) {
    gi_iap_buy_dlc2_pressed = 1;
    p_Var1 = (_jmethodID *)(**(code **)(*(int *)g_pEnv + 0x18))(g_pEnv,interface_path);
    uVar2 = (**(code **)(*(int *)g_pEnv + 0x1c4))
                      (g_pEnv,p_Var1,"iap_buy_dlc_kaamo_club",&DAT_0021f19b);
    _JNIEnv::CallStaticVoidMethod(g_pEnv,p_Var1,uVar2);
    return;
  }
  return;
}

// ===== NFC::iap_buy_dlc_supernova  @0x00071ba4  (80 bytes)
/* NFC::iap_buy_dlc_supernova() */

void NFC::iap_buy_dlc_supernova(void)

{
  _jmethodID *p_Var1;
  undefined4 uVar2;
  
  if (g_pEnv != (_jclass *)0x0) {
    gi_iap_buy_dlc3_pressed = 1;
    p_Var1 = (_jmethodID *)(**(code **)(*(int *)g_pEnv + 0x18))(g_pEnv,interface_path);
    uVar2 = (**(code **)(*(int *)g_pEnv + 0x1c4))
                      (g_pEnv,p_Var1,"iap_buy_dlc_supernova",&DAT_0021f19b);
    _JNIEnv::CallStaticVoidMethod(g_pEnv,p_Var1,uVar2);
    return;
  }
  return;
}

// ===== NFC::iap_buy_dlc_vip  @0x00071c0c  (80 bytes)
/* NFC::iap_buy_dlc_vip() */

void NFC::iap_buy_dlc_vip(void)

{
  _jmethodID *p_Var1;
  undefined4 uVar2;
  
  if (g_pEnv != (_jclass *)0x0) {
    gi_iap_buy_dlc4_pressed = 1;
    p_Var1 = (_jmethodID *)(**(code **)(*(int *)g_pEnv + 0x18))(g_pEnv,interface_path);
    uVar2 = (**(code **)(*(int *)g_pEnv + 0x1c4))(g_pEnv,p_Var1,"iap_buy_dlc_vip",&DAT_0021f19b);
    _JNIEnv::CallStaticVoidMethod(g_pEnv,p_Var1,uVar2);
    return;
  }
  return;
}

// ===== NFC::iap_buy_dlc_full_package  @0x00071c74  (80 bytes)
/* NFC::iap_buy_dlc_full_package() */

void NFC::iap_buy_dlc_full_package(void)

{
  _jmethodID *p_Var1;
  undefined4 uVar2;
  
  if (g_pEnv != (_jclass *)0x0) {
    gi_iap_buy_dlc5_pressed = 1;
    p_Var1 = (_jmethodID *)(**(code **)(*(int *)g_pEnv + 0x18))(g_pEnv,interface_path);
    uVar2 = (**(code **)(*(int *)g_pEnv + 0x1c4))
                      (g_pEnv,p_Var1,"iap_buy_dlc_full_package",&DAT_0021f19b);
    _JNIEnv::CallStaticVoidMethod(g_pEnv,p_Var1,uVar2);
    return;
  }
  return;
}

// ===== NFC::iap_restore_purchases  @0x00071cdc  (70 bytes)
/* NFC::iap_restore_purchases() */

void NFC::iap_restore_purchases(void)

{
  _jmethodID *p_Var1;
  undefined4 uVar2;
  
  if (g_pEnv != (_jclass *)0x0) {
    p_Var1 = (_jmethodID *)(**(code **)(*(int *)g_pEnv + 0x18))(g_pEnv,interface_path);
    uVar2 = (**(code **)(*(int *)g_pEnv + 0x1c4))
                      (g_pEnv,p_Var1,"iap_restore_purchases",&DAT_0021f19b);
    _JNIEnv::CallStaticVoidMethod(g_pEnv,p_Var1,uVar2);
    return;
  }
  return;
}

// ===== NFC::iap_buy_credits_100_000  @0x00071d38  (80 bytes)
/* NFC::iap_buy_credits_100_000() */

void NFC::iap_buy_credits_100_000(void)

{
  _jmethodID *p_Var1;
  undefined4 uVar2;
  
  if (g_pEnv != (_jclass *)0x0) {
    gi_iap_buy_credit_pack1_pressed = 1;
    p_Var1 = (_jmethodID *)(**(code **)(*(int *)g_pEnv + 0x18))(g_pEnv,interface_path);
    uVar2 = (**(code **)(*(int *)g_pEnv + 0x1c4))
                      (g_pEnv,p_Var1,"iap_buy_credits_100_000",&DAT_0021f19b);
    _JNIEnv::CallStaticVoidMethod(g_pEnv,p_Var1,uVar2);
    return;
  }
  return;
}

// ===== NFC::iap_buy_credits_300_000  @0x00071da0  (80 bytes)
/* NFC::iap_buy_credits_300_000() */

void NFC::iap_buy_credits_300_000(void)

{
  _jmethodID *p_Var1;
  undefined4 uVar2;
  
  if (g_pEnv != (_jclass *)0x0) {
    gi_iap_buy_credit_pack2_pressed = 1;
    p_Var1 = (_jmethodID *)(**(code **)(*(int *)g_pEnv + 0x18))(g_pEnv,interface_path);
    uVar2 = (**(code **)(*(int *)g_pEnv + 0x1c4))
                      (g_pEnv,p_Var1,"iap_buy_credits_300_000",&DAT_0021f19b);
    _JNIEnv::CallStaticVoidMethod(g_pEnv,p_Var1,uVar2);
    return;
  }
  return;
}

// ===== NFC::iap_buy_credits_1_000_000  @0x00071e08  (80 bytes)
/* NFC::iap_buy_credits_1_000_000() */

void NFC::iap_buy_credits_1_000_000(void)

{
  _jmethodID *p_Var1;
  undefined4 uVar2;
  
  if (g_pEnv != (_jclass *)0x0) {
    gi_iap_buy_credit_pack3_pressed = 1;
    p_Var1 = (_jmethodID *)(**(code **)(*(int *)g_pEnv + 0x18))(g_pEnv,interface_path);
    uVar2 = (**(code **)(*(int *)g_pEnv + 0x1c4))
                      (g_pEnv,p_Var1,"iap_buy_credits_1_000_000",&DAT_0021f19b);
    _JNIEnv::CallStaticVoidMethod(g_pEnv,p_Var1,uVar2);
    return;
  }
  return;
}

// ===== NFC::iap_buy_credits_3_000_000  @0x00071e70  (80 bytes)
/* NFC::iap_buy_credits_3_000_000() */

void NFC::iap_buy_credits_3_000_000(void)

{
  _jmethodID *p_Var1;
  undefined4 uVar2;
  
  if (g_pEnv != (_jclass *)0x0) {
    gi_iap_buy_credit_pack4_pressed = 1;
    p_Var1 = (_jmethodID *)(**(code **)(*(int *)g_pEnv + 0x18))(g_pEnv,interface_path);
    uVar2 = (**(code **)(*(int *)g_pEnv + 0x1c4))
                      (g_pEnv,p_Var1,"iap_buy_credits_3_000_000",&DAT_0021f19b);
    _JNIEnv::CallStaticVoidMethod(g_pEnv,p_Var1,uVar2);
    return;
  }
  return;
}

// ===== NFC::iap_buy_credits_10_000_000  @0x00071ed8  (80 bytes)
/* NFC::iap_buy_credits_10_000_000() */

void NFC::iap_buy_credits_10_000_000(void)

{
  _jmethodID *p_Var1;
  undefined4 uVar2;
  
  if (g_pEnv != (_jclass *)0x0) {
    gi_iap_buy_credit_pack5_pressed = 1;
    p_Var1 = (_jmethodID *)(**(code **)(*(int *)g_pEnv + 0x18))(g_pEnv,interface_path);
    uVar2 = (**(code **)(*(int *)g_pEnv + 0x1c4))
                      (g_pEnv,p_Var1,"iap_buy_credits_10_000_000",&DAT_0021f19b);
    _JNIEnv::CallStaticVoidMethod(g_pEnv,p_Var1,uVar2);
    return;
  }
  return;
}

// ===== NFC::free_credits_likeGOF2OnFacebook  @0x00071f40  (70 bytes)
/* NFC::free_credits_likeGOF2OnFacebook() */

void NFC::free_credits_likeGOF2OnFacebook(void)

{
  _jmethodID *p_Var1;
  undefined4 uVar2;
  
  if (g_pEnv != (_jclass *)0x0) {
    p_Var1 = (_jmethodID *)(**(code **)(*(int *)g_pEnv + 0x18))(g_pEnv,interface_path);
    uVar2 = (**(code **)(*(int *)g_pEnv + 0x1c4))
                      (g_pEnv,p_Var1,"free_credits_likeGOF2OnFacebook",&DAT_0021f19b);
    _JNIEnv::CallStaticVoidMethod(g_pEnv,p_Var1,uVar2);
    return;
  }
  return;
}

// ===== NFC::free_credits_likeFishlabsOnFacebook  @0x00071f9c  (70 bytes)
/* NFC::free_credits_likeFishlabsOnFacebook() */

void NFC::free_credits_likeFishlabsOnFacebook(void)

{
  _jmethodID *p_Var1;
  undefined4 uVar2;
  
  if (g_pEnv != (_jclass *)0x0) {
    p_Var1 = (_jmethodID *)(**(code **)(*(int *)g_pEnv + 0x18))(g_pEnv,interface_path);
    uVar2 = (**(code **)(*(int *)g_pEnv + 0x1c4))
                      (g_pEnv,p_Var1,"free_credits_likeFishlabsOnFacebook",&DAT_0021f19b);
    _JNIEnv::CallStaticVoidMethod(g_pEnv,p_Var1,uVar2);
    return;
  }
  return;
}

// ===== NFC::free_credits_subscribeToYoutubeChannel  @0x00071ff8  (70 bytes)
/* NFC::free_credits_subscribeToYoutubeChannel() */

void NFC::free_credits_subscribeToYoutubeChannel(void)

{
  _jmethodID *p_Var1;
  undefined4 uVar2;
  
  if (g_pEnv != (_jclass *)0x0) {
    p_Var1 = (_jmethodID *)(**(code **)(*(int *)g_pEnv + 0x18))(g_pEnv,interface_path);
    uVar2 = (**(code **)(*(int *)g_pEnv + 0x1c4))
                      (g_pEnv,p_Var1,"free_credits_subscribeToYoutubeChannel",&DAT_0021f19b);
    _JNIEnv::CallStaticVoidMethod(g_pEnv,p_Var1,uVar2);
    return;
  }
  return;
}

// ===== NFC::free_credits_followOnTwitter  @0x00072054  (70 bytes)
/* NFC::free_credits_followOnTwitter() */

void NFC::free_credits_followOnTwitter(void)

{
  _jmethodID *p_Var1;
  undefined4 uVar2;
  
  if (g_pEnv != (_jclass *)0x0) {
    p_Var1 = (_jmethodID *)(**(code **)(*(int *)g_pEnv + 0x18))(g_pEnv,interface_path);
    uVar2 = (**(code **)(*(int *)g_pEnv + 0x1c4))
                      (g_pEnv,p_Var1,"free_credits_followOnTwitter",&DAT_0021f19b);
    _JNIEnv::CallStaticVoidMethod(g_pEnv,p_Var1,uVar2);
    return;
  }
  return;
}

// ===== NFC::showMoreGames  @0x000720b0  (70 bytes)
/* NFC::showMoreGames() */

void NFC::showMoreGames(void)

{
  _jmethodID *p_Var1;
  undefined4 uVar2;
  
  if (g_pEnv != (_jclass *)0x0) {
    p_Var1 = (_jmethodID *)(**(code **)(*(int *)g_pEnv + 0x18))(g_pEnv,interface_path);
    uVar2 = (**(code **)(*(int *)g_pEnv + 0x1c4))(g_pEnv,p_Var1,"showMoreGames",&DAT_0021f19b);
    _JNIEnv::CallStaticVoidMethod(g_pEnv,p_Var1,uVar2);
    return;
  }
  return;
}

// ===== NFC::rateGame  @0x0007210c  (70 bytes)
/* NFC::rateGame() */

void NFC::rateGame(void)

{
  _jmethodID *p_Var1;
  undefined4 uVar2;
  
  if (g_pEnv != (_jclass *)0x0) {
    p_Var1 = (_jmethodID *)(**(code **)(*(int *)g_pEnv + 0x18))(g_pEnv,interface_path);
    uVar2 = (**(code **)(*(int *)g_pEnv + 0x1c4))(g_pEnv,p_Var1,"rateGame",&DAT_0021f19b);
    _JNIEnv::CallStaticVoidMethod(g_pEnv,p_Var1,uVar2);
    return;
  }
  return;
}

// ===== NFC::free_credits_rateGame  @0x00072168  (70 bytes)
/* NFC::free_credits_rateGame() */

void NFC::free_credits_rateGame(void)

{
  _jmethodID *p_Var1;
  undefined4 uVar2;
  
  if (g_pEnv != (_jclass *)0x0) {
    p_Var1 = (_jmethodID *)(**(code **)(*(int *)g_pEnv + 0x18))(g_pEnv,interface_path);
    uVar2 = (**(code **)(*(int *)g_pEnv + 0x1c4))
                      (g_pEnv,p_Var1,"free_credits_rateGame",&DAT_0021f19b);
    _JNIEnv::CallStaticVoidMethod(g_pEnv,p_Var1,uVar2);
    return;
  }
  return;
}

// ===== NFC::openPrivacyPolicy  @0x000721c4  (70 bytes)
/* NFC::openPrivacyPolicy() */

void NFC::openPrivacyPolicy(void)

{
  _jmethodID *p_Var1;
  undefined4 uVar2;
  
  if (g_pEnv != (_jclass *)0x0) {
    p_Var1 = (_jmethodID *)(**(code **)(*(int *)g_pEnv + 0x18))(g_pEnv,interface_path);
    uVar2 = (**(code **)(*(int *)g_pEnv + 0x1c4))(g_pEnv,p_Var1,"openPrivacyPolicy",&DAT_0021f19b);
    _JNIEnv::CallStaticVoidMethod(g_pEnv,p_Var1,uVar2);
    return;
  }
  return;
}

// ===== NFC::openTermsOfService  @0x00072220  (70 bytes)
/* NFC::openTermsOfService() */

void NFC::openTermsOfService(void)

{
  _jmethodID *p_Var1;
  undefined4 uVar2;
  
  if (g_pEnv != (_jclass *)0x0) {
    p_Var1 = (_jmethodID *)(**(code **)(*(int *)g_pEnv + 0x18))(g_pEnv,interface_path);
    uVar2 = (**(code **)(*(int *)g_pEnv + 0x1c4))(g_pEnv,p_Var1,"openTermsOfService",&DAT_0021f19b);
    _JNIEnv::CallStaticVoidMethod(g_pEnv,p_Var1,uVar2);
    return;
  }
  return;
}

