// Class: ArraySetLength<AbyssEngine
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== ArraySetLength<AbyssEngine::String*>  @0x00086a20  (52 bytes)
/* void ArraySetLength<AbyssEngine::String*>(unsigned int, Array<AbyssEngine::String*>&) */

void ArraySetLength<AbyssEngine::String*>(uint param_1,Array *param_2)

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

// ===== ArraySetLength<AbyssEngine::AESoundInterface*>  @0x0008a26a  (52 bytes)
/* void ArraySetLength<AbyssEngine::AESoundInterface*>(unsigned int,
   Array<AbyssEngine::AESoundInterface*>&) */

void ArraySetLength<AbyssEngine::AESoundInterface*>(uint param_1,Array *param_2)

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

// ===== ArraySetLength<AbyssEngine::Mesh*>  @0x001b1aa4  (52 bytes)
/* void ArraySetLength<AbyssEngine::Mesh*>(unsigned int, Array<AbyssEngine::Mesh*>&) */

void ArraySetLength<AbyssEngine::Mesh*>(uint param_1,Array *param_2)

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

