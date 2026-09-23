// Class: ArraySetLength<Array<AbyssEngine::AEMath
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== ArraySetLength<Array<AbyssEngine::AEMath::Vector*>*>  @0x001469f0  (52 bytes)
/* void ArraySetLength<Array<AbyssEngine::AEMath::Vector*>*>(unsigned int,
   Array<Array<AbyssEngine::AEMath::Vector*>*>&) */

void ArraySetLength<Array<AbyssEngine::AEMath::Vector*>*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

