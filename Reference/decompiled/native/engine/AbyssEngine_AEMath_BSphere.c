// Class: AbyssEngine::AEMath::BSphere
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::AEMath::BSphere::Merge  @0x0007d550  (208 bytes)
/* AbyssEngine::AEMath::BSphere::Merge(AbyssEngine::Transform const&) */

void __thiscall AbyssEngine::AEMath::BSphere::Merge(BSphere *this,Transform *param_1)

{
  float fVar1;
  float fVar2;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  float local_1c;
  undefined4 local_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_18 = 0x3f800000;
  MatrixTransformVector((AEMath *)&local_34,param_1,(Vector *)(param_1 + 0xd4));
  local_28 = local_34;
  local_24 = local_30;
  local_20 = local_2c;
  local_34 = *(float *)(param_1 + 0xe0);
  local_30 = local_34;
  local_2c = local_34;
  MatrixRotateVector((AEMath *)&local_40,param_1,(Vector *)&local_34);
  local_34 = local_40;
  local_30 = local_3c;
  fVar1 = -local_40;
  if (0.0 < local_40) {
    fVar1 = local_40;
  }
  fVar2 = -local_3c;
  if (0.0 < local_3c) {
    fVar2 = local_3c;
  }
  local_1c = -local_38;
  if (0.0 < local_38) {
    local_1c = local_38;
  }
  if (fVar2 < fVar1) {
    fVar2 = fVar1;
  }
  if (local_1c < fVar2) {
    local_1c = fVar2;
  }
  local_2c = local_38;
  Merge(this,(BSphere *)&local_28);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::AEMath::BSphere::Merge  @0x0007d628  (344 bytes)
/* AbyssEngine::AEMath::BSphere::Merge(AbyssEngine::AEMath::BSphere const&) */

void __thiscall AbyssEngine::AEMath::BSphere::Merge(BSphere *this,BSphere *param_1)

{
  float extraout_r0;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  undefined8 uVar8;
  
  if (*(float *)(this + 0x10) < *(float *)(param_1 + 0x10)) {
    *(float *)(this + 0x10) = *(float *)(param_1 + 0x10);
  }
  if (*(float *)(param_1 + 0xc) != 0.0) {
    if (*(float *)(this + 0xc) == 0.0) {
      *(float *)(this + 0xc) = *(float *)(param_1 + 0xc);
      *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
      uVar8 = *(undefined8 *)(param_1 + 8);
      *(undefined8 *)this = *(undefined8 *)param_1;
      *(undefined8 *)(this + 8) = uVar8;
      *(undefined4 *)this = *(undefined4 *)param_1;
      *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
      *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
      *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
    }
    else {
      fVar7 = *(float *)param_1 - *(float *)this;
      fVar5 = *(float *)(param_1 + 4) - *(float *)(this + 4);
      fVar6 = *(float *)(param_1 + 8) - *(float *)(this + 8);
      fVar1 = fVar7 * fVar7 + fVar5 * fVar5 + fVar6 * fVar6;
      fVar2 = SQRT(fVar1);
      if (NAN(fVar2)) {
        sqrtf(fVar1);
        fVar2 = extraout_r0;
      }
      fVar1 = *(float *)(param_1 + 0xc);
      fVar3 = *(float *)(this + 0xc);
      if (fVar2 == 0.0) {
        if (fVar1 < fVar3) {
          fVar1 = fVar3;
        }
      }
      else {
        if (fVar2 + fVar1 < fVar3) {
          return;
        }
        if ((int)((uint)(fVar2 - fVar1 < -fVar3) << 0x1f) < 0) {
          *(undefined4 *)this = *(undefined4 *)param_1;
          *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
          *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
        }
        else {
          fVar4 = (((fVar2 + fVar1) - fVar3) * 0.5) / fVar2;
          fVar1 = (fVar2 + fVar3 + fVar1) * 0.5;
          *(float *)this = fVar7 * fVar4 + *(float *)this;
          *(float *)(this + 4) = fVar5 * fVar4 + *(float *)(this + 4);
          *(float *)(this + 8) = fVar6 * fVar4 + *(float *)(this + 8);
        }
      }
      *(float *)(this + 0xc) = fVar1;
    }
  }
  return;
}

// ===== AbyssEngine::AEMath::BSphere::operator=  @0x0007d780  (16 bytes)
/* AbyssEngine::AEMath::BSphere::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::BSphere const&) */

void __thiscall AbyssEngine::AEMath::BSphere::operator=(BSphere *this,BSphere *param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)this = *(undefined8 *)param_1;
  *(undefined8 *)(this + 8) = uVar1;
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  return;
}

