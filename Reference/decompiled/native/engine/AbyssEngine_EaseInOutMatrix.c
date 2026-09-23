// Class: AbyssEngine::EaseInOutMatrix
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::EaseInOutMatrix::EaseInOutMatrix  @0x000775d0  (246 bytes)
/* AbyssEngine::EaseInOutMatrix::EaseInOutMatrix() */

EaseInOutMatrix * __thiscall AbyssEngine::EaseInOutMatrix::EaseInOutMatrix(EaseInOutMatrix *this)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar1 = 0;
  uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)this = 0x3f800000;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = uVar2;
  *(undefined4 *)(this + 0xc) = uVar3;
  *(undefined4 *)(this + 0x10) = uVar4;
  *(undefined4 *)(this + 0x14) = 0x3f800000;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = uVar2;
  *(undefined4 *)(this + 0x20) = uVar3;
  *(undefined4 *)(this + 0x24) = uVar4;
  *(undefined8 *)(this + 0x28) = 0x3f800000;
  *(undefined8 *)(this + 0x30) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0x38) = 0x3f800000;
  Quaternion::Quaternion((Quaternion *)(this + 0x3c));
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  Quaternion::Quaternion((Quaternion *)(this + 0x58));
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x78) = 0x3f800000;
  *(undefined4 *)(this + 0x7c) = uVar1;
  *(undefined4 *)(this + 0x80) = uVar2;
  *(undefined4 *)(this + 0x84) = uVar3;
  *(undefined4 *)(this + 0x88) = uVar4;
  *(undefined4 *)(this + 0x8c) = 0x3f800000;
  *(undefined4 *)(this + 0x90) = uVar1;
  *(undefined4 *)(this + 0x94) = uVar2;
  *(undefined4 *)(this + 0x98) = uVar3;
  *(undefined4 *)(this + 0x9c) = uVar4;
  *(undefined8 *)(this + 0xa0) = 0x3f800000;
  *(undefined8 *)(this + 0xa8) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0xb0) = 0x3f800000;
  *(undefined4 *)(this + 0xb4) = 0x3f800000;
  *(undefined4 *)(this + 0xb8) = uVar1;
  *(undefined4 *)(this + 0xbc) = uVar2;
  *(undefined4 *)(this + 0xc0) = uVar3;
  *(undefined4 *)(this + 0xc4) = uVar4;
  *(undefined4 *)(this + 200) = 0x3f800000;
  *(undefined4 *)(this + 0xcc) = uVar1;
  *(undefined4 *)(this + 0xd0) = uVar2;
  *(undefined4 *)(this + 0xd4) = uVar3;
  *(undefined4 *)(this + 0xd8) = uVar4;
  *(undefined8 *)(this + 0xdc) = 0x3f800000;
  *(undefined8 *)(this + 0xe4) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0xec) = 0x3f800000;
  SetRange(this,0x3f800000,0,0,0,0,0x3f800000,0,0,0,0,0x3f800000,0,0x3f800000,0x3f800000,0x3f800000,
           0x3f800000,0,0,0,0,0x3f800000,0,0,0,0,0x3f800000,0,0x3f800000,0x3f800000,0x3f800000);
  *(undefined4 *)(this + 0xf0) = 0;
  return this;
}

// ===== AbyssEngine::EaseInOutMatrix::SetRange  @0x000776f0  (456 bytes)
/* AbyssEngine::EaseInOutMatrix::SetRange(AbyssEngine::AEMath::Matrix, AbyssEngine::AEMath::Matrix)
    */

void AbyssEngine::EaseInOutMatrix::SetRange
               (Matrix *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
               undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
               undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16,
               undefined4 param_17,undefined4 param_18,undefined4 param_19,undefined4 param_20,
               undefined4 param_21,undefined4 param_22,undefined4 param_23,undefined4 param_24,
               undefined4 param_25,undefined4 param_26,undefined4 param_27,undefined4 param_28,
               undefined4 param_29,undefined4 param_30,undefined4 param_31)

{
  Quaternion *pQVar1;
  undefined4 *puVar2;
  float extraout_s1;
  float extraout_s3;
  undefined8 uVar3;
  Quaternion local_110 [4];
  float local_10c;
  float local_104;
  AEMath aAStack_100 [16];
  Quaternion aQStack_f0 [16];
  undefined4 local_e0 [5];
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined4 local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  local_58 = param_5;
  local_54 = param_6;
  local_50 = param_7;
  local_4c = param_8;
  local_48 = param_9;
  local_44 = param_10;
  local_40 = param_11;
  local_a0 = param_17;
  local_9c = param_18;
  local_3c = param_12;
  local_98 = param_19;
  local_38 = param_13;
  local_34 = param_14;
  local_30 = param_15;
  local_2c = param_16;
  local_94 = param_20;
  local_90 = param_21;
  local_8c = param_22;
  local_88 = param_23;
  uStack_84 = param_24;
  local_80 = param_25;
  uStack_7c = param_26;
  local_78 = param_27;
  uStack_74 = param_28;
  local_70 = param_29;
  uStack_6c = param_30;
  local_68 = param_31;
  local_64 = param_2;
  uStack_60 = param_3;
  uStack_5c = param_4;
  AEMath::Matrix::operator=(param_1,(Matrix *)&local_64);
  AEMath::Matrix::operator=(param_1 + 0xb4,(Matrix *)&local_a0);
  Quaternion::Set((Quaternion *)(param_1 + 0x3c),(Matrix *)&local_64);
  uStack_c4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uStack_c0 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uStack_bc = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  puVar2 = (undefined4 *)((uint)local_e0 | 4);
  local_e0[0] = 0x3f800000;
  *puVar2 = 0;
  puVar2[1] = uStack_c4;
  puVar2[2] = uStack_c0;
  puVar2[3] = uStack_bc;
  local_cc = 0x3f800000;
  local_c8 = 0;
  local_b8 = 0x3f800000;
  uStack_b0 = 0x3f8000003f800000;
  local_a8 = 0x3f800000;
  Quaternion::Convert((Quaternion *)(param_1 + 0x3c),(Matrix *)local_e0);
  pQVar1 = (Quaternion *)Quaternion::Quaternion(aQStack_f0);
  Quaternion::Set(pQVar1,(Matrix *)local_e0);
  AEMath::MatrixGetPosition(aAStack_100,(Matrix *)&local_64);
  AEMath::Vector::operator=((Vector *)(param_1 + 0x4c),(Vector *)aAStack_100);
  Quaternion::Quaternion(local_110,(Matrix *)&local_a0);
  pQVar1 = (Quaternion *)
           Quaternion::Quaternion
                     ((Quaternion *)aAStack_100,local_104 - *(float *)(param_1 + 0x48),extraout_s1,
                      local_10c - *(float *)(param_1 + 0x40),extraout_s3);
  uVar3 = *(undefined8 *)(pQVar1 + 8);
  *(undefined8 *)(param_1 + 0x58) = *(undefined8 *)pQVar1;
  *(undefined8 *)(param_1 + 0x60) = uVar3;
  Quaternion::~Quaternion(pQVar1);
  Quaternion::~Quaternion(local_110);
  AEMath::MatrixGetPosition((AEMath *)local_110,(Matrix *)&local_a0);
  AEMath::operator-(aAStack_100,(Vector *)local_110,(Vector *)(param_1 + 0x4c));
  AEMath::Vector::operator=((Vector *)(param_1 + 0x68),(Vector *)aAStack_100);
  *(undefined4 *)(param_1 + 0x74) = 0x3f400000;
  UpdateCurrentValue((EaseInOutMatrix *)param_1);
  Quaternion::~Quaternion(aQStack_f0);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::EaseInOutMatrix::SetDuration  @0x00077900  (14 bytes)
/* AbyssEngine::EaseInOutMatrix::SetDuration(int) */

void __thiscall AbyssEngine::EaseInOutMatrix::SetDuration(EaseInOutMatrix *this,int param_1)

{
  uint in_fpscr;
  undefined4 uVar1;
  
  uVar1 = VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  *(undefined4 *)(this + 0xf0) = uVar1;
  return;
}

// ===== AbyssEngine::EaseInOutMatrix::EaseInOutMatrix  @0x00077910  (322 bytes)
/* AbyssEngine::EaseInOutMatrix::EaseInOutMatrix(AbyssEngine::AEMath::Matrix,
   AbyssEngine::AEMath::Matrix, int) */

EaseInOutMatrix * __thiscall
AbyssEngine::EaseInOutMatrix::EaseInOutMatrix
          (EaseInOutMatrix *this,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
          undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
          undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16,
          undefined4 param_17,undefined4 param_18,undefined4 param_19,undefined4 param_20,
          undefined4 param_21,undefined4 param_22,undefined4 param_23,undefined4 param_24,
          undefined4 param_25,undefined4 param_26,undefined4 param_27,undefined4 param_28,
          undefined4 param_29,undefined4 param_30,undefined4 param_31,undefined4 param_32)

{
  Quaternion *this_00;
  uint in_fpscr;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar1 = 0;
  uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)this = 0x3f800000;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = uVar2;
  *(undefined4 *)(this + 0xc) = uVar3;
  *(undefined4 *)(this + 0x10) = uVar4;
  *(undefined4 *)(this + 0x14) = 0x3f800000;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = uVar2;
  *(undefined4 *)(this + 0x20) = uVar3;
  *(undefined4 *)(this + 0x24) = uVar4;
  *(undefined8 *)(this + 0x28) = 0x3f800000;
  *(undefined8 *)(this + 0x30) = 0x3f8000003f800000;
  this_00 = (Quaternion *)(this + 0x3c);
  *(undefined4 *)(this + 0x38) = 0x3f800000;
  Quaternion::Quaternion(this_00);
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  Quaternion::Quaternion((Quaternion *)(this + 0x58));
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x78) = 0x3f800000;
  *(undefined4 *)(this + 0x7c) = uVar1;
  *(undefined4 *)(this + 0x80) = uVar2;
  *(undefined4 *)(this + 0x84) = uVar3;
  *(undefined4 *)(this + 0x88) = uVar4;
  *(undefined4 *)(this + 0x8c) = 0x3f800000;
  *(undefined4 *)(this + 0x90) = uVar1;
  *(undefined4 *)(this + 0x94) = uVar2;
  *(undefined4 *)(this + 0x98) = uVar3;
  *(undefined4 *)(this + 0x9c) = uVar4;
  *(undefined8 *)(this + 0xa0) = 0x3f800000;
  *(undefined8 *)(this + 0xa8) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0xb0) = 0x3f800000;
  *(undefined4 *)(this + 0xb4) = 0x3f800000;
  *(undefined4 *)(this + 0xb8) = uVar1;
  *(undefined4 *)(this + 0xbc) = uVar2;
  *(undefined4 *)(this + 0xc0) = uVar3;
  *(undefined4 *)(this + 0xc4) = uVar4;
  *(undefined4 *)(this + 200) = 0x3f800000;
  *(undefined4 *)(this + 0xcc) = uVar1;
  *(undefined4 *)(this + 0xd0) = uVar2;
  *(undefined4 *)(this + 0xd4) = uVar3;
  *(undefined4 *)(this + 0xd8) = uVar4;
  *(undefined8 *)(this + 0xdc) = 0x3f800000;
  *(undefined8 *)(this + 0xe4) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0xec) = 0x3f800000;
  SetRange(this,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,
           param_12,param_13,param_14,param_15,param_16,param_17,param_18,param_19,param_20,param_21
           ,param_22,param_23,param_24,param_25,param_26,param_27,param_28,param_29,param_30,
           param_31,this_00);
  uVar1 = VectorSignedToFloat(param_32,(byte)(in_fpscr >> 0x16) & 3);
  *(undefined4 *)(this + 0xf0) = uVar1;
  return this;
}

// ===== AbyssEngine::EaseInOutMatrix::UpdateCurrentValue  @0x00077a80  (340 bytes)
/* WARNING: Removing unreachable block (ram,0x00077ad2) */
/* AbyssEngine::EaseInOutMatrix::UpdateCurrentValue() */

void __thiscall AbyssEngine::EaseInOutMatrix::UpdateCurrentValue(EaseInOutMatrix *this)

{
  float fVar1;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s3;
  float extraout_s3_00;
  Quaternion local_88 [4];
  float local_84;
  float local_7c;
  AEMath aAStack_4c [12];
  AEMath aAStack_40 [12];
  Quaternion aQStack_34 [16];
  int local_24;
  
  local_24 = __stack_chk_guard;
  if (*(float *)(this + 0x74) == 1.25) {
    AEMath::Matrix::operator=((Matrix *)(this + 0x78),this + 0xb4);
    return;
  }
  fVar1 = (float)AEMath::Sinf(*(float *)(this + 0x74) * 6.2831855);
  fVar1 = fVar1 * 0.5 + 0.5;
  Quaternion::Quaternion
            (local_88,fVar1 * *(float *)(this + 100),extraout_s1,*(float *)(this + 0x5c) * fVar1,
             extraout_s3);
  Quaternion::Quaternion
            (aQStack_34,local_7c + *(float *)(this + 0x48),extraout_s1_00,
             local_84 + *(float *)(this + 0x40),extraout_s3_00);
  Quaternion::Convert(aQStack_34,this + 0x78);
  Quaternion::~Quaternion(aQStack_34);
  fVar1 = (float)Quaternion::~Quaternion(local_88);
  AEMath::operator*(aAStack_4c,(Vector *)(this + 0x68),fVar1);
  AEMath::operator+(aAStack_40,(Vector *)aAStack_4c,(Vector *)(this + 0x4c));
  AEMath::MatrixSetTranslation((AEMath *)local_88,this + 0x78,(Vector *)aAStack_40);
  if (__stack_chk_guard == local_24) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::EaseInOutMatrix::Increase  @0x00077bfc  (44 bytes)
/* AbyssEngine::EaseInOutMatrix::Increase(float) */

void __thiscall AbyssEngine::EaseInOutMatrix::Increase(EaseInOutMatrix *this,float param_1)

{
  float in_r1;
  undefined4 in_s1;
  undefined8 uVar1;
  undefined4 in_s5;
  
  uVar1 = FloatVectorMin(CONCAT44(in_s1,*(float *)(this + 0x74) +
                                        (in_r1 * 0.5) / *(float *)(this + 0xf0)),
                         CONCAT44(in_s5,0x3fa00000),2,0x20);
  *(int *)(this + 0x74) = (int)uVar1;
  UpdateCurrentValue(this);
  return;
}

// ===== AbyssEngine::EaseInOutMatrix::Decrease  @0x00077c28  (44 bytes)
/* AbyssEngine::EaseInOutMatrix::Decrease(float) */

void __thiscall AbyssEngine::EaseInOutMatrix::Decrease(EaseInOutMatrix *this,float param_1)

{
  float in_r1;
  undefined4 in_s1;
  undefined8 uVar1;
  undefined4 in_s5;
  
  uVar1 = FloatVectorMax(CONCAT44(in_s1,*(float *)(this + 0x74) +
                                        (in_r1 * -0.5) / *(float *)(this + 0xf0)),
                         CONCAT44(in_s5,0x3f400000),2,0x20);
  *(int *)(this + 0x74) = (int)uVar1;
  UpdateCurrentValue(this);
  return;
}

// ===== AbyssEngine::EaseInOutMatrix::RunOut  @0x00077c54  (108 bytes)
/* AbyssEngine::EaseInOutMatrix::RunOut(float) */

void __thiscall AbyssEngine::EaseInOutMatrix::RunOut(EaseInOutMatrix *this,float param_1)

{
  byte bVar1;
  float in_r1;
  char cVar2;
  float fVar3;
  
  fVar3 = *(float *)(this + 0x74);
  bVar1 = (byte)(((uint)(fVar3 == 1.0) << 0x1e) >> 0x18);
  cVar2 = -((char)((byte)(((uint)(fVar3 < 1.0) << 0x1f) >> 0x18) | bVar1) >> 7);
  if ((bool)(bVar1 >> 6) || (bool)cVar2 != NAN(fVar3)) {
    if ((cVar2 == '\0') ||
       (fVar3 = fVar3 + (in_r1 * 0.5) / *(float *)(this + 0xf0), *(float *)(this + 0x74) = fVar3,
       fVar3 <= 1.0)) goto LAB_001d82dc;
  }
  else {
    fVar3 = fVar3 + (in_r1 * -0.5) / *(float *)(this + 0xf0);
    *(float *)(this + 0x74) = fVar3;
    if (-1 < (int)((uint)(fVar3 < 1.0) << 0x1f)) goto LAB_001d82dc;
  }
  *(undefined4 *)(this + 0x74) = 0x3f800000;
LAB_001d82dc:
  UpdateCurrentValue(this);
  return;
}

// ===== AbyssEngine::EaseInOutMatrix::GetValue  @0x00077cc0  (30 bytes)
/* AbyssEngine::EaseInOutMatrix::GetValue() */

void AbyssEngine::EaseInOutMatrix::GetValue(void)

{
  undefined4 *in_r0;
  int in_r1;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar1 = *(undefined4 *)(in_r1 + 0x7c);
  uVar2 = *(undefined4 *)(in_r1 + 0x80);
  uVar3 = *(undefined4 *)(in_r1 + 0x84);
  uVar4 = *(undefined4 *)(in_r1 + 0x88);
  *in_r0 = *(undefined4 *)(in_r1 + 0x78);
  in_r0[1] = uVar1;
  in_r0[2] = uVar2;
  in_r0[3] = uVar3;
  in_r0[4] = uVar4;
  uVar1 = *(undefined4 *)(in_r1 + 0x90);
  uVar2 = *(undefined4 *)(in_r1 + 0x94);
  uVar3 = *(undefined4 *)(in_r1 + 0x98);
  uVar4 = *(undefined4 *)(in_r1 + 0x9c);
  in_r0[5] = *(undefined4 *)(in_r1 + 0x8c);
  in_r0[6] = uVar1;
  in_r0[7] = uVar2;
  in_r0[8] = uVar3;
  in_r0[9] = uVar4;
  uVar1 = *(undefined4 *)(in_r1 + 0xa4);
  uVar2 = *(undefined4 *)(in_r1 + 0xa8);
  uVar3 = *(undefined4 *)(in_r1 + 0xac);
  uVar4 = *(undefined4 *)(in_r1 + 0xb0);
  in_r0[10] = *(undefined4 *)(in_r1 + 0xa0);
  in_r0[0xb] = uVar1;
  in_r0[0xc] = uVar2;
  in_r0[0xd] = uVar3;
  in_r0[0xe] = uVar4;
  return;
}

// ===== AbyssEngine::EaseInOutMatrix::SetToMaxValue  @0x00077cde  (12 bytes)
/* AbyssEngine::EaseInOutMatrix::SetToMaxValue() */

void __thiscall AbyssEngine::EaseInOutMatrix::SetToMaxValue(EaseInOutMatrix *this)

{
  *(undefined4 *)(this + 0x74) = 0x3fa00000;
  UpdateCurrentValue(this);
  return;
}

// ===== AbyssEngine::EaseInOutMatrix::SetToMinValue  @0x00077cea  (12 bytes)
/* AbyssEngine::EaseInOutMatrix::SetToMinValue() */

void __thiscall AbyssEngine::EaseInOutMatrix::SetToMinValue(EaseInOutMatrix *this)

{
  *(undefined4 *)(this + 0x74) = 0x3f400000;
  UpdateCurrentValue(this);
  return;
}

// ===== AbyssEngine::EaseInOutMatrix::GetMinValue  @0x00077cf4  (28 bytes)
/* AbyssEngine::EaseInOutMatrix::GetMinValue() */

void AbyssEngine::EaseInOutMatrix::GetMinValue(void)

{
  undefined4 *in_r0;
  undefined4 *in_r1;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar1 = in_r1[1];
  uVar2 = in_r1[2];
  uVar3 = in_r1[3];
  uVar4 = in_r1[4];
  *in_r0 = *in_r1;
  in_r0[1] = uVar1;
  in_r0[2] = uVar2;
  in_r0[3] = uVar3;
  in_r0[4] = uVar4;
  uVar1 = in_r1[6];
  uVar2 = in_r1[7];
  uVar3 = in_r1[8];
  uVar4 = in_r1[9];
  in_r0[5] = in_r1[5];
  in_r0[6] = uVar1;
  in_r0[7] = uVar2;
  in_r0[8] = uVar3;
  in_r0[9] = uVar4;
  uVar1 = in_r1[0xb];
  uVar2 = in_r1[0xc];
  uVar3 = in_r1[0xd];
  uVar4 = in_r1[0xe];
  in_r0[10] = in_r1[10];
  in_r0[0xb] = uVar1;
  in_r0[0xc] = uVar2;
  in_r0[0xd] = uVar3;
  in_r0[0xe] = uVar4;
  return;
}

// ===== AbyssEngine::EaseInOutMatrix::GetMaxValue  @0x00077d10  (30 bytes)
/* AbyssEngine::EaseInOutMatrix::GetMaxValue() */

void AbyssEngine::EaseInOutMatrix::GetMaxValue(void)

{
  undefined4 *in_r0;
  int in_r1;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar1 = *(undefined4 *)(in_r1 + 0xb8);
  uVar2 = *(undefined4 *)(in_r1 + 0xbc);
  uVar3 = *(undefined4 *)(in_r1 + 0xc0);
  uVar4 = *(undefined4 *)(in_r1 + 0xc4);
  *in_r0 = *(undefined4 *)(in_r1 + 0xb4);
  in_r0[1] = uVar1;
  in_r0[2] = uVar2;
  in_r0[3] = uVar3;
  in_r0[4] = uVar4;
  uVar1 = *(undefined4 *)(in_r1 + 0xcc);
  uVar2 = *(undefined4 *)(in_r1 + 0xd0);
  uVar3 = *(undefined4 *)(in_r1 + 0xd4);
  uVar4 = *(undefined4 *)(in_r1 + 0xd8);
  in_r0[5] = *(undefined4 *)(in_r1 + 200);
  in_r0[6] = uVar1;
  in_r0[7] = uVar2;
  in_r0[8] = uVar3;
  in_r0[9] = uVar4;
  uVar1 = *(undefined4 *)(in_r1 + 0xe0);
  uVar2 = *(undefined4 *)(in_r1 + 0xe4);
  uVar3 = *(undefined4 *)(in_r1 + 0xe8);
  uVar4 = *(undefined4 *)(in_r1 + 0xec);
  in_r0[10] = *(undefined4 *)(in_r1 + 0xdc);
  in_r0[0xb] = uVar1;
  in_r0[0xc] = uVar2;
  in_r0[0xd] = uVar3;
  in_r0[0xe] = uVar4;
  return;
}

