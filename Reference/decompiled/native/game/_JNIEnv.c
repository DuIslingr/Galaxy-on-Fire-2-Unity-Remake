// Class: _JNIEnv
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== _JNIEnv::CallStaticVoidMethod  @0x00071aec  (70 bytes)
/* _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...) */

void _JNIEnv::CallStaticVoidMethod(_jclass *param_1,_jmethodID *param_2,...)

{
  int iVar1;
  
  iVar1 = __stack_chk_guard;
  (**(code **)(*(int *)param_1 + 0x238))();
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== _JNIEnv::CallIntMethod  @0x000771cc  (70 bytes)
/* _JNIEnv::CallIntMethod(_jobject*, _jmethodID*, ...) */

void _JNIEnv::CallIntMethod(_jobject *param_1,_jmethodID *param_2,...)

{
  int iVar1;
  
  iVar1 = __stack_chk_guard;
  (**(code **)(*(int *)param_1 + 200))();
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== _JNIEnv::CallVoidMethod  @0x000772d8  (70 bytes)
/* _JNIEnv::CallVoidMethod(_jobject*, _jmethodID*, ...) */

void _JNIEnv::CallVoidMethod(_jobject *param_1,_jmethodID *param_2,...)

{
  int iVar1;
  
  iVar1 = __stack_chk_guard;
  (**(code **)(*(int *)param_1 + 0xf8))();
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

