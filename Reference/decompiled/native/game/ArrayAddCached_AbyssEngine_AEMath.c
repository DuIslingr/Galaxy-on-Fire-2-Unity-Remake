// Class: ArrayAddCached<AbyssEngine::AEMath
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== ArrayAddCached<AbyssEngine::AEMath::Matrix>  @0x00089470  (162 bytes)
/* void ArrayAddCached<AbyssEngine::AEMath::Matrix>(AbyssEngine::AEMath::Matrix,
   Array<AbyssEngine::AEMath::Matrix>&) */

void ArrayAddCached<AbyssEngine::AEMath::Matrix>
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
               undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
               undefined4 param_13,undefined4 param_14,undefined4 param_15,uint *param_16)

{
  uint uVar1;
  void *pvVar2;
  undefined4 local_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  local_54 = param_5;
  local_50 = param_6;
  local_4c = param_7;
  uStack_48 = param_8;
  local_44 = param_9;
  uStack_40 = param_10;
  uStack_3c = param_11;
  uStack_38 = param_12;
  local_34 = param_13;
  uStack_30 = param_14;
  local_2c = param_15;
  uVar1 = *param_16;
  local_64 = param_1;
  uStack_60 = param_2;
  uStack_5c = param_3;
  uStack_58 = param_4;
  if (uVar1 < param_16[2]) {
    pvVar2 = (void *)param_16[1];
  }
  else {
    pvVar2 = realloc((void *)param_16[1],param_16[2] * 0x78);
    param_16[1] = (uint)pvVar2;
    uVar1 = param_16[2];
    __aeabi_memclr4((void *)((int)pvVar2 + uVar1 * 0x3c),uVar1 * 0x3c);
    param_16[2] = uVar1 << 1;
    uVar1 = *param_16;
  }
  AbyssEngine::AEMath::Matrix::operator=((Matrix *)((int)pvVar2 + uVar1 * 0x3c),(Matrix *)&local_64)
  ;
  *param_16 = *param_16 + 1;
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

