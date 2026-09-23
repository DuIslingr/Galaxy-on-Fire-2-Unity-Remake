// Class: ArraySetLength<AbyssEngine::AEMath
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== ArraySetLength<AbyssEngine::AEMath::Vector*>  @0x000d6cec  (52 bytes)
/* void ArraySetLength<AbyssEngine::AEMath::Vector*>(unsigned int,
   Array<AbyssEngine::AEMath::Vector*>&) */

void ArraySetLength<AbyssEngine::AEMath::Vector*>(uint param_1,Array *param_2)

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

// ===== ArraySetLength<AbyssEngine::AEMath::Vector>  @0x0015d044  (60 bytes)
/* void ArraySetLength<AbyssEngine::AEMath::Vector>(unsigned int,
   Array<AbyssEngine::AEMath::Vector>&) */

void ArraySetLength<AbyssEngine::AEMath::Vector>(uint param_1,Array *param_2)

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
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 * 0xc);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 * 0xc);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArraySetLength<AbyssEngine::AEMath::Matrix>  @0x0018b5c0  (60 bytes)
/* void ArraySetLength<AbyssEngine::AEMath::Matrix>(unsigned int,
   Array<AbyssEngine::AEMath::Matrix>&) */

void ArraySetLength<AbyssEngine::AEMath::Matrix>(uint param_1,Array *param_2)

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
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 * 0x3c);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 * 0x3c);
  *(uint *)param_2 = param_1;
  return;
}

