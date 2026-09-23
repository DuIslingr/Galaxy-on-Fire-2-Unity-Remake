// Class: ArrayAdd<AbyssEngine::AEMath
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== ArrayAdd<AbyssEngine::AEMath::Matrix>  @0x000876b8  (126 bytes)
/* void ArrayAdd<AbyssEngine::AEMath::Matrix>(AbyssEngine::AEMath::Matrix,
   Array<AbyssEngine::AEMath::Matrix>&) */

void ArrayAdd<AbyssEngine::AEMath::Matrix>
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
               undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
               undefined4 param_13,undefined4 param_14,undefined4 param_15,int *param_16)

{
  void *pvVar1;
  undefined4 local_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  local_54 = param_5;
  local_50 = param_6;
  local_4c = param_7;
  local_48 = param_8;
  uStack_44 = param_9;
  uStack_40 = param_10;
  uStack_3c = param_11;
  uStack_38 = param_12;
  local_34 = param_13;
  uStack_30 = param_14;
  uStack_2c = param_15;
  param_16[2] = *param_16 + 1;
  local_64 = param_1;
  uStack_60 = param_2;
  uStack_5c = param_3;
  uStack_58 = param_4;
  pvVar1 = realloc((void *)param_16[1],(*param_16 + 1) * 0x3c);
  param_16[1] = (int)pvVar1;
  AbyssEngine::AEMath::Matrix::operator=
            ((Matrix *)((int)pvVar1 + *param_16 * 0x3c),(Matrix *)&local_64);
  *param_16 = param_16[2];
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

