// Class: ArraySet<AbyssEngine
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== ArraySet<AbyssEngine::KeyFrame*>  @0x000811bc  (56 bytes)
/* void ArraySet<AbyssEngine::KeyFrame*>(AbyssEngine::KeyFrame* const*, unsigned int,
   Array<AbyssEngine::KeyFrame*>&) */

void ArraySet<AbyssEngine::KeyFrame*>(KeyFrame **param_1,uint param_2,Array *param_3)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_3 + 8) == param_2) {
    pvVar1 = *(void **)(param_3 + 4);
  }
  else {
    uVar2 = param_2;
    if (param_2 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_3 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_3 + 4),uVar2 << 2);
    *(void **)(param_3 + 4) = pvVar1;
  }
  __aeabi_memcpy4(pvVar1,param_1,param_2 << 2);
  *(uint *)param_3 = param_2;
  return;
}

