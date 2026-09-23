// Class: TargetFollowCamera
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== TargetFollowCamera::TargetFollowCamera  @0x001867d0  (512 bytes)
/* TargetFollowCamera::TargetFollowCamera(unsigned int, AEGeometry*, AbyssEngine::AEMath::Vector,
   AbyssEngine::AEMath::Vector) */

void __thiscall
TargetFollowCamera::TargetFollowCamera
          (TargetFollowCamera *this,undefined4 param_1,AEGeometry *param_2,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
          undefined4 param_9)

{
  undefined4 uVar1;
  undefined4 uVar2;
  Vector *this_00;
  undefined4 *puVar3;
  undefined4 uVar4;
  float extraout_s0;
  float fVar5;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 local_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  int local_28;
  
  uVar4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar1 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_28 = __stack_chk_guard;
  uStack_30 = param_5;
  local_2c = param_6;
  local_40 = param_7;
  uStack_3c = param_8;
  uStack_38 = param_9;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = uVar4;
  *(undefined4 *)(this + 0x3c) = uVar1;
  *(undefined4 *)(this + 0x40) = uVar2;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = uVar4;
  *(undefined4 *)(this + 0x30) = uVar1;
  *(undefined4 *)(this + 0x34) = uVar2;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = uVar4;
  *(undefined4 *)(this + 0x20) = uVar1;
  *(undefined4 *)(this + 0x24) = uVar2;
  this_00 = (Vector *)(this + 8);
  *(undefined4 *)this_00 = 0;
  *(undefined4 *)(this + 0xc) = uVar4;
  *(undefined4 *)(this + 0x10) = uVar1;
  *(undefined4 *)(this + 0x14) = uVar2;
  *(undefined4 *)(this + 0xb4) = 0x3f800000;
  *(undefined4 *)(this + 0xb8) = 0;
  *(undefined4 *)(this + 0xbc) = uVar4;
  *(undefined4 *)(this + 0xc0) = uVar1;
  *(undefined4 *)(this + 0xc4) = uVar2;
  *(undefined4 *)(this + 200) = 0x3f800000;
  *(undefined4 *)(this + 0xcc) = 0;
  *(undefined4 *)(this + 0xd0) = uVar4;
  *(undefined4 *)(this + 0xd4) = uVar1;
  *(undefined4 *)(this + 0xd8) = uVar2;
  *(undefined8 *)(this + 0xdc) = 0x3f800000;
  *(undefined8 *)(this + 0xe4) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0xec) = 0x3f800000;
  *(undefined4 *)(this + 0xf4) = 0;
  *(undefined4 *)(this + 0xf8) = 0;
  *(undefined4 *)(this + 0xfc) = 0;
  *(undefined4 *)(this + 0x13c) = 0x3f800000;
  *(undefined4 *)(this + 0x140) = 0;
  *(undefined4 *)(this + 0x144) = uVar4;
  *(undefined4 *)(this + 0x148) = uVar1;
  *(undefined4 *)(this + 0x14c) = uVar2;
  *(undefined4 *)(this + 0x150) = 0x3f800000;
  *(undefined4 *)(this + 0x154) = 0;
  *(undefined4 *)(this + 0x158) = uVar4;
  *(undefined4 *)(this + 0x15c) = uVar1;
  *(undefined4 *)(this + 0x160) = uVar2;
  *(undefined4 *)(this + 0x164) = 0x3f800000;
  *(undefined8 *)(this + 0x168) = 0x3f80000000000000;
  *(undefined8 *)(this + 0x170) = 0x3f8000003f800000;
  *(undefined4 *)this = param_1;
  *(AEGeometry **)(this + 4) = param_2;
  local_34 = param_4;
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x2c),(Vector *)&local_34);
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x38),(Vector *)&local_40);
  local_80 = 0;
  uStack_7c = 0;
  local_78 = 0;
  AbyssEngine::AEMath::Vector::operator=(this_00,(Vector *)&local_80);
  local_80 = 0;
  uStack_7c = 0;
  local_78 = 0;
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x14),(Vector *)&local_80);
  puVar3 = (undefined4 *)AEGeometry::getMatrix(param_2);
  local_80 = *puVar3;
  uStack_7c = puVar3[1];
  local_78 = puVar3[2];
  uStack_74 = puVar3[3];
  uStack_70 = puVar3[4];
  local_6c = puVar3[5];
  uStack_68 = puVar3[6];
  uStack_64 = puVar3[7];
  uStack_60 = puVar3[8];
  uStack_5c = puVar3[9];
  local_58 = puVar3[10];
  uStack_54 = puVar3[0xb];
  uStack_50 = puVar3[0xc];
  uStack_4c = puVar3[0xd];
  uStack_48 = puVar3[0xe];
  AbyssEngine::AEMath::MatrixTransformVector
            ((AEMath *)&local_8c,(Vector *)&local_80,(Vector *)&local_34);
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x14),(Vector *)&local_8c);
  AbyssEngine::AEMath::MatrixTransformVector
            ((AEMath *)&local_8c,(Vector *)&local_80,(Vector *)&local_40);
  AbyssEngine::AEMath::Vector::operator=(this_00,(Vector *)&local_8c);
  local_8c = 0;
  local_88 = 0x3f800000;
  uStack_84 = 0;
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x20),(Vector *)&local_8c);
  this[0x44] = (TargetFollowCamera)0x0;
  this[0x47] = (TargetFollowCamera)0x0;
  this[0x45] = (TargetFollowCamera)0x0;
  *(undefined4 *)(this + 0x48) = 0;
  this[0x46] = (TargetFollowCamera)0x1;
  this[0x4c] = (TargetFollowCamera)0x0;
  this[0xf0] = (TargetFollowCamera)0x0;
  this[0x100] = (TargetFollowCamera)0x0;
  this[0x10c] = (TargetFollowCamera)0x1;
  *(undefined4 *)(this + 0x110) = 0;
  *(undefined4 *)(this + 0x114) = 5;
  uVar4 = AbyssEngine::AEMath::VectorLength((Vector *)&local_40);
  *(undefined4 *)(this + 0xb0) = uVar4;
  *(undefined8 *)(this + 0x128) = 0x3bc49ba63ba3d70a;
  *(undefined8 *)(this + 0x130) = 0x42c8000000000000;
  this[0x138] = (TargetFollowCamera)0x0;
  fVar5 = (float)aproximateCooefficientsForAproximationOfDampingFunktion
                           (this + 0x80,extraout_s0,(double *)0x3ba3d70a,(double *)(this + 0x60),
                            (double *)(this + 0x68),(double *)(this + 0x70),(double *)(this + 0x78))
  ;
  aproximateCooefficientsForAproximationOfDampingFunktion
            (this + 0xa8,fVar5,*(double **)(this + 300),(double *)(this + 0x88),
             (double *)(this + 0x90),(double *)(this + 0x98),(double *)(this + 0xa0));
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== TargetFollowCamera::aproximateCooefficientsForAproximationOfDampingFunktion  @0x00186a10  (566 bytes)
/* TargetFollowCamera::aproximateCooefficientsForAproximationOfDampingFunktion(float, double&,
   double&, double&, double&, double&) */

void __thiscall
TargetFollowCamera::aproximateCooefficientsForAproximationOfDampingFunktion
          (TargetFollowCamera *this,float param_1,double *param_2,double *param_3,double *param_4,
          double *param_5,double *param_6)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double *in_stack_00000008;
  
  dVar1 = (double)(float)param_2;
  dVar2 = dVar1 * dVar1;
  dVar3 = dVar1 * dVar2;
  dVar4 = dVar1 * dVar3;
  dVar5 = dVar1 * dVar4;
  dVar6 = dVar1 * dVar5;
  dVar7 = dVar1 * dVar6;
  dVar8 = dVar1 * dVar7;
  *param_3 = dVar1 * 1.2102111341477596e-09 +
             dVar3 * 0.0422027858310806 +
             dVar5 * 43.75888381977114 +
             dVar7 * 15119.074437016332 + dVar8 * -103298.31437796567 + dVar6 * -969.134661736397 +
             dVar4 * -1.7133856245383816 + dVar2 * -1.233489837107569e-06;
  *param_4 = -(dVar1 * 1.4781876353802752e-07 +
               dVar2 * 0.16651597434517493 +
               dVar3 * 0.1488423578964816 +
               dVar5 * 4448.097529049415 +
               dVar7 * 1803725.9838256645 + dVar8 * -12480406.26454869 + dVar6 * -111015.302667393 +
               dVar4 * -128.52917290808267 + -4.5716904903627806e-11);
  *param_5 = dVar1 * 0.5000009352113304 +
             dVar3 * 0.3778121387254571 +
             dVar5 * 112294.22315362946 +
             dVar7 * 26011080.905412003 + dVar8 * -149924392.42871693 + dVar6 * -2122499.1658084425
             + dVar4 * -3466.199114885294 + dVar2 * -0.0009647307184731492 + -2.8527534035103244e-10
  ;
  *param_6 = dVar1 * 0.4999743866523157 +
             dVar2 * 0.19280203402657284 +
             dVar4 * 39522.4565731161 +
             dVar6 * 31896097.579336446 + dVar8 * 2837989977.8564253 + dVar7 * -448847784.8572755 +
             dVar5 * -1451302.48192741 + dVar3 * -11.25222010529228 + 7.913368945635026e-09;
  *in_stack_00000008 =
       -(dVar2 * 0.00422802001700341 +
         dVar4 * 89689.50184512888 +
         dVar6 * 56126838.41706436 + dVar8 * 3091464099.7803183 + dVar7 * -609933689.8511872 +
         dVar5 * -3103835.9217881793 + dVar3 * -1.6589554694294697 + dVar1 * -4.3754915810647766e-06
        + 1.4969893482859894e-09);
  return;
}

// ===== TargetFollowCamera::~TargetFollowCamera  @0x00186da8  (2 bytes)
/* TargetFollowCamera::~TargetFollowCamera() */

TargetFollowCamera * __thiscall TargetFollowCamera::~TargetFollowCamera(TargetFollowCamera *this)

{
  return this;
}

// ===== TargetFollowCamera::setActive  @0x00186daa  (6 bytes)
/* TargetFollowCamera::setActive(bool) */

void __thiscall TargetFollowCamera::setActive(TargetFollowCamera *this,bool param_1)

{
  this[0x46] = (TargetFollowCamera)param_1;
  return;
}

// ===== TargetFollowCamera::setTarget  @0x00186db0  (4 bytes)
/* TargetFollowCamera::setTarget(AEGeometry*) */

void __thiscall TargetFollowCamera::setTarget(TargetFollowCamera *this,AEGeometry *param_1)

{
  *(AEGeometry **)(this + 4) = param_1;
  return;
}

// ===== TargetFollowCamera::getTarget  @0x00186db4  (4 bytes)
/* TargetFollowCamera::getTarget() */

undefined4 __thiscall TargetFollowCamera::getTarget(TargetFollowCamera *this)

{
  return *(undefined4 *)(this + 4);
}

// ===== TargetFollowCamera::setTargetOffset  @0x00186db8  (6 bytes)
/* TargetFollowCamera::setTargetOffset(AbyssEngine::AEMath::Vector const&) */

void __thiscall TargetFollowCamera::setTargetOffset(TargetFollowCamera *this,Vector *param_1)

{
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x2c),param_1);
  return;
}

// ===== TargetFollowCamera::getTargetOffset  @0x00186dbe  (4 bytes)
/* TargetFollowCamera::getTargetOffset() */

TargetFollowCamera * __thiscall TargetFollowCamera::getTargetOffset(TargetFollowCamera *this)

{
  return this + 0x2c;
}

// ===== TargetFollowCamera::setCamOffset  @0x00186dc2  (28 bytes)
/* TargetFollowCamera::setCamOffset(AbyssEngine::AEMath::Vector const&) */

void __thiscall TargetFollowCamera::setCamOffset(TargetFollowCamera *this,Vector *param_1)

{
  undefined4 uVar1;
  
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x38),param_1);
  uVar1 = AbyssEngine::AEMath::VectorLength(param_1);
  *(undefined4 *)(this + 0xb0) = uVar1;
  return;
}

// ===== TargetFollowCamera::getCamOffset  @0x00186dde  (4 bytes)
/* TargetFollowCamera::getCamOffset() */

TargetFollowCamera * __thiscall TargetFollowCamera::getCamOffset(TargetFollowCamera *this)

{
  return this + 0x38;
}

// ===== TargetFollowCamera::setPosition  @0x00186de2  (6 bytes)
/* TargetFollowCamera::setPosition(float, float, float) */

TargetFollowCamera * __thiscall
TargetFollowCamera::setPosition(TargetFollowCamera *this,float param_1,float param_2,float param_3)

{
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  
  *(undefined4 *)(this + 8) = in_r1;
  *(undefined4 *)(this + 0xc) = in_r2;
  *(undefined4 *)(this + 0x10) = in_r3;
  return this + 0x14;
}

// ===== TargetFollowCamera::setPosition  @0x00186de8  (14 bytes)
/* TargetFollowCamera::setPosition(AbyssEngine::AEMath::Vector const&) */

void __thiscall TargetFollowCamera::setPosition(TargetFollowCamera *this,Vector *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 4);
  uVar1 = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 8) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0xc) = uVar2;
  *(undefined4 *)(this + 0x10) = uVar1;
  return;
}

// ===== TargetFollowCamera::getPosition  @0x00186df6  (4 bytes)
/* TargetFollowCamera::getPosition() */

TargetFollowCamera * __thiscall TargetFollowCamera::getPosition(TargetFollowCamera *this)

{
  return this + 8;
}

// ===== TargetFollowCamera::translate  @0x00186dfa  (66 bytes)
/* TargetFollowCamera::translate(float, float, float) */

void __thiscall
TargetFollowCamera::translate(TargetFollowCamera *this,float param_1,float param_2,float param_3)

{
  undefined4 in_r1;
  float in_r2;
  float in_r3;
  undefined1 auVar1 [16];
  
  auVar1._4_4_ = in_r2;
  auVar1._0_4_ = in_r1;
  auVar1._8_4_ = in_r3;
  auVar1._12_4_ = in_r1;
  auVar1 = FloatVectorAdd(auVar1,*(undefined1 (*) [16])(this + 8),2);
  *(longlong *)(this + 8) = auVar1._0_8_;
  *(longlong *)(this + 0x10) = auVar1._8_8_;
  *(float *)(this + 0x18) = *(float *)(this + 0x18) + in_r2;
  *(float *)(this + 0x1c) = *(float *)(this + 0x1c) + in_r3;
  update(this,1000);
  return;
}

// ===== TargetFollowCamera::update  @0x00186e40  (2134 bytes)
/* TargetFollowCamera::update(int) */

void __thiscall TargetFollowCamera::update(TargetFollowCamera *this,int param_1)

{
  TargetFollowCamera TVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  byte bVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined8 *puVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  AEMath *this_00;
  undefined4 *puVar13;
  Vector *this_01;
  int iVar14;
  Vector *pVVar15;
  uint in_fpscr;
  uint uVar16;
  uint uVar17;
  float fVar18;
  float fVar19;
  float extraout_s0;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s2;
  float extraout_s2_00;
  float fVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  AEMath aAStack_148 [12];
  undefined4 local_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined8 local_100;
  undefined4 local_f8;
  undefined8 local_f0;
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined4 local_b8;
  undefined8 local_b0;
  undefined4 local_a8;
  undefined4 local_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 local_94;
  undefined4 uStack_90;
  undefined4 local_8c;
  undefined4 uStack_88;
  undefined4 local_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  int local_64;
  
  local_64 = __stack_chk_guard;
  if (this[0x138] == (TargetFollowCamera)0x0) {
    if ((0 < param_1) && (this[0x46] != (TargetFollowCamera)0x0)) {
      puVar9 = (undefined8 *)AEGeometry::getMatrix(*(AEGeometry **)(this + 4));
      local_a0 = *(undefined4 *)puVar9;
      uStack_9c = *(undefined4 *)((int)puVar9 + 4);
      uStack_98 = *(undefined4 *)(puVar9 + 1);
      local_94 = *(undefined4 *)((int)puVar9 + 0xc);
      uStack_90 = *(undefined4 *)(puVar9 + 2);
      local_8c = *(undefined4 *)((int)puVar9 + 0x14);
      uStack_88 = *(undefined4 *)(puVar9 + 3);
      local_84 = *(undefined4 *)((int)puVar9 + 0x1c);
      uStack_80 = *(undefined4 *)(puVar9 + 4);
      uStack_7c = *(undefined4 *)((int)puVar9 + 0x24);
      local_78 = *(undefined4 *)(puVar9 + 5);
      local_74 = *(undefined4 *)((int)puVar9 + 0x2c);
      uStack_70 = *(undefined4 *)(puVar9 + 6);
      uStack_6c = *(undefined4 *)((int)puVar9 + 0x34);
      uStack_68 = *(undefined4 *)(puVar9 + 7);
      if (this[0x45] == (TargetFollowCamera)0x0) {
        if (this[0x44] == (TargetFollowCamera)0x0) {
          if (this[0xf0] == (TargetFollowCamera)0x0) {
            local_b0 = *(undefined8 *)(this + 0x14);
            local_a8 = *(undefined4 *)(this + 0x1c);
            local_100 = *(undefined8 *)(this + 8);
            local_f8 = *(undefined4 *)(this + 0x10);
            AbyssEngine::AEMath::MatrixGetUp((AEMath *)&local_f0,(Matrix *)&local_a0);
            AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x20),(Vector *)&local_f0);
            pVVar15 = (Vector *)(this + 8);
            this_01 = (Vector *)(this + 0x14);
            if (this[0x4c] != (TargetFollowCamera)0x0) {
              uStack_d4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
              uStack_d0 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
              uStack_cc = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
              puVar13 = (undefined4 *)((uint)&local_f0 | 4);
              local_f0 = CONCAT44(local_f0._4_4_,0x3f800000);
              *puVar13 = 0;
              puVar13[1] = uStack_d4;
              puVar13[2] = uStack_d0;
              puVar13[3] = uStack_cc;
              local_dc = 0x3f800000;
              local_d8 = 0;
              local_c8 = 0x3f800000;
              uStack_c0 = 0x3f8000003f800000;
              local_b8 = 0x3f800000;
              AbyssEngine::AEMath::MatrixSetRotation
                        (&local_13c,(AEMath *)&local_f0,*(undefined4 *)(this + 0x50),
                         *(undefined4 *)(this + 0x54),*(undefined4 *)(this + 0x58),2);
              AbyssEngine::AEMath::Matrix::operator*=((Matrix *)&local_a0,(AEMath *)&local_f0);
              fVar20 = (float)AbyssEngine::AEMath::VectorLength((Vector *)(this + 0x38));
              in_fpscr = in_fpscr & 0xfffffff | (uint)(fVar20 == *(float *)(this + 0xb0)) << 0x1e;
              if ((byte)(in_fpscr >> 0x1e) == 0) {
                AbyssEngine::AEMath::Vector::operator*=
                          ((Vector *)(this + 0x38),*(float *)(this + 0xb0) / fVar20);
              }
            }
            AbyssEngine::AEMath::MatrixTransformVector
                      ((AEMath *)&local_f0,(Matrix *)&local_a0,(Vector *)(this + 0x38));
            AbyssEngine::AEMath::Vector::operator=(pVVar15,(Vector *)&local_f0);
            AbyssEngine::AEMath::MatrixTransformVector
                      ((AEMath *)&local_f0,(Matrix *)&local_a0,(Vector *)(this + 0x2c));
            AbyssEngine::AEMath::Vector::operator=(this_01,(Vector *)&local_f0);
            AbyssEngine::AEMath::operator-((AEMath *)&local_f0,this_01,(Vector *)&local_b0);
            uVar2 = (longlong)param_1 * (longlong)param_1;
            iVar10 = (int)(uVar2 >> 0x20);
            uVar3 = (uVar2 & 0xffffffff) * (ulonglong)(uint)param_1;
            lVar4 = (uVar3 & 0xffffffff) * (ulonglong)(uint)param_1;
            iVar11 = iVar10 * param_1 + (int)uVar2 * (param_1 >> 0x1f) + (int)(uVar3 >> 0x20);
            dVar23 = (double)__aeabi_l2d((int)lVar4,
                                         iVar11 * param_1 +
                                         (int)uVar3 * (param_1 >> 0x1f) +
                                         (int)((ulonglong)lVar4 >> 0x20));
            dVar25 = (double)__aeabi_l2d((int)uVar3,iVar11);
            dVar26 = *(double *)(this + 0x60);
            dVar28 = *(double *)(this + 0x68);
            dVar21 = *(double *)(this + 0x70);
            dVar22 = *(double *)(this + 0x78);
            dVar24 = (double)__aeabi_l2d((int)uVar2,iVar10);
            dVar27 = (double)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
            fVar20 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
            AbyssEngine::AEMath::Vector::operator*=
                      ((Vector *)&local_f0,
                       (float)((double)(1.0 / fVar20) *
                              (*(double *)(this + 0x80) +
                              dVar23 * dVar26 + dVar25 * dVar28 + dVar24 * dVar21 + dVar27 * dVar22)
                              ));
            AbyssEngine::AEMath::operator+
                      ((AEMath *)&local_13c,(Vector *)&local_b0,(Vector *)&local_f0);
            AbyssEngine::AEMath::Vector::operator=(this_01,(Vector *)&local_13c);
            AbyssEngine::AEMath::operator-((AEMath *)&local_13c,pVVar15,(Vector *)&local_100);
            AbyssEngine::AEMath::Vector::operator*=
                      ((Vector *)&local_13c,
                       (float)((double)(1.0 / fVar20) *
                              (*(double *)(this + 0xa8) +
                              dVar23 * SUB168(*(undefined1 (*) [16])(this + 0x88),0) +
                              dVar25 * SUB168(*(undefined1 (*) [16])(this + 0x88),8) +
                              dVar24 * SUB168(*(undefined1 (*) [16])(this + 0x98),0) +
                              dVar27 * SUB168(*(undefined1 (*) [16])(this + 0x98),8))));
            if (this[0x100] != (TargetFollowCamera)0x0) {
              fVar20 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_13c);
              fVar18 = *(float *)(this + 0x104);
              in_fpscr = in_fpscr & 0xfffffff;
              *(float *)(this + 0x104) = fVar20 + fVar18;
              this[0x100] = (TargetFollowCamera)(fVar20 + fVar18 < 800.0);
            }
            this_00 = aAStack_148;
            AbyssEngine::AEMath::operator+(this_00,(Vector *)&local_100,(Vector *)&local_13c);
          }
          else {
            AbyssEngine::AEMath::MatrixIdentity((AEMath *)&local_f0,(Matrix *)&local_a0);
            AbyssEngine::AEMath::Matrix::operator=((Matrix *)&local_a0,(AEMath *)&local_f0);
            AbyssEngine::AEMath::MatrixSetRotation
                      ((Matrix *)&local_f0,extraout_s0,extraout_s1_00,extraout_s2_00);
            AbyssEngine::AEMath::operator*((AEMath *)&local_f0,this + 0xb4,(Matrix *)&local_a0);
            AbyssEngine::AEMath::Matrix::operator=((Matrix *)&local_a0,(AEMath *)&local_f0);
            local_f0 = *(undefined8 *)(this + 8);
            local_e8 = *(undefined4 *)(this + 0x10);
            AbyssEngine::AEMath::MatrixTransformVector
                      ((AEMath *)&local_13c,(Matrix *)&local_a0,(Vector *)(this + 0xf4));
            pVVar15 = (Vector *)(this + 8);
            AbyssEngine::AEMath::Vector::operator=(pVVar15,(Vector *)&local_13c);
            in_fpscr = in_fpscr & 0xfffffff;
            uVar17 = in_fpscr | (uint)(*(float *)(this + 0x108) == 0.0) << 0x1e;
            if (((byte)(uVar17 >> 0x1e) != 0) ||
               (uVar17 = in_fpscr, *(float *)(this + 0x104) < *(float *)(this + 0x108) * 1.5)) {
              AbyssEngine::AEMath::operator-((AEMath *)&local_13c,pVVar15,(Vector *)&local_f0);
              uVar17 = uVar17 & 0xfffffff | (uint)(*(float *)(this + 0x108) == 0.0) << 0x1e;
              if ((byte)(uVar17 >> 0x1e) != 0) {
                uVar12 = AbyssEngine::AEMath::VectorLength((Vector *)&local_13c);
                *(undefined4 *)(this + 0x108) = uVar12;
              }
              iVar10 = param_1 * param_1 * param_1;
              dVar25 = (double)VectorSignedToFloat(iVar10,(byte)(uVar17 >> 0x16) & 3);
              dVar27 = (double)VectorSignedToFloat(iVar10 * param_1,(byte)(uVar17 >> 0x16) & 3);
              dVar28 = (double)VectorSignedToFloat(param_1 * param_1,(byte)(uVar17 >> 0x16) & 3);
              dVar26 = (double)VectorSignedToFloat(param_1,(byte)(uVar17 >> 0x16) & 3);
              fVar20 = (float)VectorSignedToFloat(param_1,(byte)(uVar17 >> 0x16) & 3);
              AbyssEngine::AEMath::Vector::operator*=
                        ((Vector *)&local_13c,
                         (float)((double)(1.0 / fVar20) *
                                (*(double *)(this + 0xa8) +
                                dVar27 * *(double *)(this + 0x88) +
                                dVar25 * SUB168(*(undefined1 (*) [16])(this + 0x90),0) +
                                dVar28 * SUB168(*(undefined1 (*) [16])(this + 0x90),8) +
                                dVar26 * *(double *)(this + 0xa0))));
              fVar20 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_13c);
              fVar20 = fVar20 + *(float *)(this + 0x104);
              *(float *)(this + 0x104) = fVar20;
              fVar18 = *(float *)(this + 0x108) * 0.75;
              uVar17 = uVar17 & 0xfffffff | (uint)(fVar20 < fVar18) << 0x1f |
                       (uint)(fVar20 == fVar18) << 0x1e;
              in_fpscr = uVar17 | (uint)(NAN(fVar20) || NAN(fVar18)) << 0x1c;
              bVar5 = (byte)(uVar17 >> 0x18);
              this[0x100] = (TargetFollowCamera)
                            (!(bool)(bVar5 >> 6 & 1) && bVar5 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)
                            );
              AbyssEngine::AEMath::operator+
                        ((AEMath *)&local_b0,(Vector *)&local_f0,(Vector *)&local_13c);
              AbyssEngine::AEMath::Vector::operator=(pVVar15,(Vector *)&local_b0);
            }
            local_94 = *(undefined4 *)(this + 8);
            local_84 = *(undefined4 *)(this + 0xc);
            local_74 = *(undefined4 *)(this + 0x10);
            AbyssEngine::AEMath::MatrixGetUp((AEMath *)&local_13c,(Matrix *)&local_a0);
            AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x20),(Vector *)&local_13c);
            AbyssEngine::AEMath::MatrixGetDir((AEMath *)&local_13c,(Matrix *)&local_a0);
            this_00 = (AEMath *)&local_b0;
            AbyssEngine::AEMath::MatrixTransformVector
                      (this_00,(Matrix *)&local_a0,(Vector *)&local_13c);
            pVVar15 = (Vector *)(this + 0x14);
          }
          AbyssEngine::AEMath::Vector::operator=(pVVar15,(Vector *)this_00);
        }
        else {
          this[0x100] = (TargetFollowCamera)0x0;
          AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_f0,(Matrix *)&local_a0);
          AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x14),(Vector *)&local_f0);
          *(float *)(this + 0x14) = *(float *)(this + 0x14) - *(float *)(this + 8);
          *(float *)(this + 0x18) = *(float *)(this + 0x18) - *(float *)(this + 0xc);
          *(float *)(this + 0x1c) = *(float *)(this + 0x1c) - *(float *)(this + 0x10);
        }
      }
      else {
        uVar6 = *puVar9;
        uVar12 = uStack_98;
        uVar7 = local_94;
        uVar8 = uStack_90;
        local_dc = local_8c;
        local_d8 = uStack_88;
        uStack_d4 = local_84;
        uStack_d0 = uStack_80;
        uStack_cc = uStack_7c;
        local_c8 = puVar9[5];
        uStack_c0 = puVar9[6];
        local_b8 = uStack_68;
        if (this[0x10c] == (TargetFollowCamera)0x0) {
          puVar13 = (undefined4 *)((uint)&local_f0 | 4);
          local_f0 = CONCAT44(local_f0._4_4_,0x3f800000);
          *puVar13 = 0;
          puVar13[1] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
          puVar13[2] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
          puVar13[3] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
          local_dc = 0x3f800000;
          local_d8 = 0;
          local_c8 = 0x3f800000;
          uStack_c0 = 0x3f8000003f800000;
          local_b8 = 0x3f800000;
          uVar6 = local_f0;
          uVar12 = local_e8;
          uVar7 = uStack_e4;
          uVar8 = uStack_e0;
          uStack_d4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
          uStack_d0 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
          uStack_cc = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
        }
        uStack_e0 = uVar8;
        uStack_e4 = uVar7;
        local_e8 = uVar12;
        local_f0 = uVar6;
        AbyssEngine::AEMath::MatrixGetUp((AEMath *)&local_13c,(Matrix *)&local_f0);
        AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x20),(Vector *)&local_13c);
        AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_f0,(Matrix *)&local_a0);
        AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x14),(Vector *)&local_f0);
        this[0x100] = (TargetFollowCamera)0x0;
      }
      if (this[0xf0] != (TargetFollowCamera)0x0) {
        AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_f0,(Matrix *)&local_a0);
        AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 8),(Vector *)&local_f0);
        AbyssEngine::AEMath::MatrixGetUp((AEMath *)&local_f0,(Matrix *)&local_a0);
        AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x20),(Vector *)&local_f0);
        AbyssEngine::AEMath::MatrixGetDir((AEMath *)&local_13c,(Matrix *)&local_a0);
        AbyssEngine::AEMath::operator-
                  ((AEMath *)&local_f0,(Vector *)(this + 8),(Vector *)&local_13c);
        AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x14),(Vector *)&local_f0);
      }
      if (this[0x47] != (TargetFollowCamera)0x0) {
        iVar10 = *(int *)(this + 0x48);
        *(int *)(this + 0x48) = iVar10 - param_1;
        if (iVar10 - param_1 < 1) {
          this[0x47] = (TargetFollowCamera)0x0;
        }
        iVar10 = *(int *)(this + 0x120);
        fVar20 = 1.0;
        if (this[0xf0] != (TargetFollowCamera)0x0) {
          fVar20 = 0.001;
        }
        iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,iVar10 << 1);
        fVar18 = (float)VectorSignedToFloat(iVar11 - iVar10,(byte)(in_fpscr >> 0x16) & 3);
        *(float *)(this + 8) = *(float *)(this + 8) + fVar20 * fVar18;
        iVar11 = *(int *)(this + 0x120);
        iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,iVar11 << 1);
        fVar18 = (float)VectorSignedToFloat(iVar10 - iVar11,(byte)(in_fpscr >> 0x16) & 3);
        *(float *)(this + 0xc) = *(float *)(this + 0xc) + fVar20 * fVar18;
        iVar11 = *(int *)(this + 0x120);
        iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,iVar11 << 1);
        fVar18 = (float)VectorSignedToFloat(iVar10 - iVar11,(byte)(in_fpscr >> 0x16) & 3);
        *(float *)(this + 0x10) = *(float *)(this + 0x10) + fVar20 * fVar18;
      }
      fVar20 = *(float *)(this + 0x110);
      uVar17 = in_fpscr & 0xfffffff | (uint)(fVar20 < 0.0) << 0x1f | (uint)(fVar20 == 0.0) << 0x1e;
      uVar16 = uVar17 | (uint)NAN(fVar20) << 0x1c;
      bVar5 = (byte)(uVar17 >> 0x18);
      if (!(bool)(bVar5 >> 6 & 1) && bVar5 >> 7 == ((byte)(uVar16 >> 0x1c) & 1)) {
        iVar14 = *(int *)(this + 0x114);
        TVar1 = this[0xf0];
        iVar11 = iVar14 << 1;
        iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,iVar11);
        fVar19 = (float)VectorSignedToFloat(iVar10 - iVar14,(byte)(uVar16 >> 0x16) & 3);
        fVar18 = 1.0;
        if (TVar1 != (TargetFollowCamera)0x0) {
          fVar18 = 0.0015;
        }
        *(float *)(this + 0x14) = *(float *)(this + 0x14) + fVar18 * fVar20 * fVar19;
        fVar19 = *(float *)(this + 0x110);
        iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,iVar11);
        fVar20 = (float)VectorSignedToFloat(iVar10 - iVar14,(byte)(uVar16 >> 0x16) & 3);
        *(float *)(this + 0x18) = *(float *)(this + 0x18) + fVar18 * fVar19 * fVar20;
        fVar19 = *(float *)(this + 0x110);
        iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,iVar11);
        fVar20 = (float)VectorSignedToFloat(iVar10 - iVar14,(byte)(uVar16 >> 0x16) & 3);
        *(float *)(this + 0x1c) = *(float *)(this + 0x1c) + fVar18 * fVar19 * fVar20;
      }
      AbyssEngine::AEMath::MatrixGetLookAt
                ((AEMath *)&local_f0,(Vector *)(this + 8),(Vector *)(this + 0x14),
                 (Vector *)(this + 0x20));
      AbyssEngine::AEMath::Matrix::operator=((Matrix *)&local_a0,(AEMath *)&local_f0);
      uStack_d4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      uStack_d0 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      uStack_cc = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      puVar13 = (undefined4 *)((uint)&local_f0 | 4);
      local_f0 = CONCAT44(local_f0._4_4_,0x3f800000);
      *puVar13 = 0;
      puVar13[1] = uStack_d4;
      puVar13[2] = uStack_d0;
      puVar13[3] = uStack_cc;
      local_dc = 0x3f800000;
      local_d8 = 0;
      local_c8 = 0x3f800000;
      uStack_c0 = 0x3f8000003f800000;
      local_b8 = 0x3f800000;
      AbyssEngine::AEMath::MatrixSetRotation
                ((Matrix *)&local_13c,*(float *)(this + 0x130),extraout_s1,extraout_s2);
      AbyssEngine::AEMath::Matrix::operator*=((Matrix *)&local_a0,(AEMath *)&local_f0);
      AbyssEngine::PaintCanvas::CameraSetLocal(Globals::Canvas,*(uint *)this,(Matrix *)&local_a0);
      AbyssEngine::AEMath::Matrix::operator=((Matrix *)(this + 0x13c),(Matrix *)&local_a0);
    }
  }
  else {
    AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_13c,this + 0x13c);
    *(undefined4 *)(this + 8) = local_13c;
    *(undefined4 *)(this + 0xc) = uStack_138;
    *(undefined4 *)(this + 0x10) = uStack_134;
    AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 8),(Vector *)&local_13c);
    AbyssEngine::PaintCanvas::CameraSetLocal(Globals::Canvas,*(uint *)this,this + 0x13c);
    if (*(AEGeometry **)(this + 4) != (AEGeometry *)0x0) {
      puVar9 = (undefined8 *)AEGeometry::getMatrix(*(AEGeometry **)(this + 4));
      local_a0 = *(undefined4 *)puVar9;
      uStack_9c = *(undefined4 *)((int)puVar9 + 4);
      uStack_98 = *(undefined4 *)(puVar9 + 1);
      local_94 = *(undefined4 *)((int)puVar9 + 0xc);
      uStack_90 = *(undefined4 *)(puVar9 + 2);
      local_8c = *(undefined4 *)((int)puVar9 + 0x14);
      uStack_88 = *(undefined4 *)(puVar9 + 3);
      local_84 = *(undefined4 *)((int)puVar9 + 0x1c);
      uStack_80 = *(undefined4 *)(puVar9 + 4);
      uStack_7c = *(undefined4 *)((int)puVar9 + 0x24);
      local_78 = *(undefined4 *)(puVar9 + 5);
      local_74 = *(undefined4 *)((int)puVar9 + 0x2c);
      local_c8 = puVar9[5];
      uStack_70 = *(undefined4 *)(puVar9 + 6);
      uStack_6c = *(undefined4 *)((int)puVar9 + 0x34);
      uStack_c0 = puVar9[6];
      uStack_68 = *(undefined4 *)(puVar9 + 7);
      uVar6 = *puVar9;
      uVar12 = uStack_98;
      uVar7 = local_94;
      uVar8 = uStack_90;
      local_dc = local_8c;
      local_d8 = uStack_88;
      uStack_d4 = local_84;
      uStack_d0 = uStack_80;
      uStack_cc = uStack_7c;
      local_b8 = uStack_68;
      if (this[0x10c] == (TargetFollowCamera)0x0) {
        puVar13 = (undefined4 *)((uint)&local_f0 | 4);
        local_f0 = CONCAT44(local_f0._4_4_,0x3f800000);
        *puVar13 = 0;
        puVar13[1] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
        puVar13[2] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
        puVar13[3] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
        local_dc = 0x3f800000;
        local_d8 = 0;
        local_c8 = 0x3f800000;
        uStack_c0 = 0x3f8000003f800000;
        local_b8 = 0x3f800000;
        uVar6 = local_f0;
        uVar12 = local_e8;
        uVar7 = uStack_e4;
        uVar8 = uStack_e0;
        uStack_d4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
        uStack_d0 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
        uStack_cc = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      }
      uStack_e0 = uVar8;
      uStack_e4 = uVar7;
      local_e8 = uVar12;
      local_f0 = uVar6;
      AbyssEngine::AEMath::MatrixGetUp((AEMath *)&local_b0,(Matrix *)&local_f0);
      AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x20),(Vector *)&local_b0);
      AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_f0,(Matrix *)&local_a0);
      AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x14),(Vector *)&local_f0);
    }
  }
  if (__stack_chk_guard != local_64) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== TargetFollowCamera::translateNoUpdate  @0x001876d0  (58 bytes)
/* TargetFollowCamera::translateNoUpdate(float, float, float) */

void __thiscall
TargetFollowCamera::translateNoUpdate
          (TargetFollowCamera *this,float param_1,float param_2,float param_3)

{
  undefined4 in_r1;
  float in_r2;
  float in_r3;
  undefined1 auVar1 [16];
  
  auVar1._4_4_ = in_r2;
  auVar1._0_4_ = in_r1;
  auVar1._8_4_ = in_r3;
  auVar1._12_4_ = in_r1;
  auVar1 = FloatVectorAdd(auVar1,*(undefined1 (*) [16])(this + 8),2);
  *(longlong *)(this + 8) = auVar1._0_8_;
  *(longlong *)(this + 0x10) = auVar1._8_8_;
  *(float *)(this + 0x18) = *(float *)(this + 0x18) + in_r2;
  *(float *)(this + 0x1c) = *(float *)(this + 0x1c) + in_r3;
  return;
}

// ===== TargetFollowCamera::enableFirstPersonCam  @0x0018770c  (78 bytes)
/* TargetFollowCamera::enableFirstPersonCam(bool) */

void __thiscall TargetFollowCamera::enableFirstPersonCam(TargetFollowCamera *this,bool param_1)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  this[0xf0] = (TargetFollowCamera)param_1;
  local_20 = 0;
  local_1c = 0x43160000;
  local_18 = 0xc4480000;
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0xf4),(Vector *)&local_20);
  *(undefined4 *)(this + 0x104) = 0;
  *(undefined4 *)(this + 0x108) = 0;
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== TargetFollowCamera::hideShipForFirstPersonCam  @0x00187764  (6 bytes)
/* TargetFollowCamera::hideShipForFirstPersonCam() */

TargetFollowCamera __thiscall
TargetFollowCamera::hideShipForFirstPersonCam(TargetFollowCamera *this)

{
  return this[0x100];
}

// ===== TargetFollowCamera::setFirstPersonMatrix  @0x0018776a  (6 bytes)
/* TargetFollowCamera::setFirstPersonMatrix(AbyssEngine::AEMath::Matrix&) */

void __thiscall TargetFollowCamera::setFirstPersonMatrix(TargetFollowCamera *this,Matrix *param_1)

{
  AbyssEngine::AEMath::Matrix::operator=((Matrix *)(this + 0xb4),param_1);
  return;
}

// ===== TargetFollowCamera::setBoostPercentage  @0x00187770  (18 bytes)
/* TargetFollowCamera::setBoostPercentage(float, int) */

void __thiscall
TargetFollowCamera::setBoostPercentage(TargetFollowCamera *this,float param_1,int param_2)

{
  int in_r2;
  
  if (7 < in_r2) {
    in_r2 = 8;
  }
  if (in_r2 < 2) {
    in_r2 = 2;
  }
  *(int *)(this + 0x110) = param_2;
  *(int *)(this + 0x114) = in_r2;
  return;
}

// ===== TargetFollowCamera::setRumblePercentage  @0x00187782  (6 bytes)
/* TargetFollowCamera::setRumblePercentage(float, int) */

void __thiscall
TargetFollowCamera::setRumblePercentage(TargetFollowCamera *this,float param_1,int param_2)

{
  undefined4 in_r2;
  
  *(int *)(this + 0x110) = param_2;
  *(undefined4 *)(this + 0x114) = in_r2;
  return;
}

// ===== TargetFollowCamera::setFixed  @0x00187788  (6 bytes)
/* TargetFollowCamera::setFixed(bool) */

void __thiscall TargetFollowCamera::setFixed(TargetFollowCamera *this,bool param_1)

{
  this[0x138] = (TargetFollowCamera)param_1;
  return;
}

// ===== TargetFollowCamera::setLocal  @0x00187790  (112 bytes)
/* TargetFollowCamera::setLocal(AbyssEngine::AEMath::Matrix) */

void TargetFollowCamera::setLocal
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
               undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
               undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16)

{
  undefined4 local_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  local_58 = param_5;
  local_54 = param_6;
  local_50 = param_7;
  local_4c = param_8;
  uStack_48 = param_9;
  uStack_44 = param_10;
  uStack_40 = param_11;
  uStack_3c = param_12;
  local_38 = param_13;
  uStack_34 = param_14;
  uStack_30 = param_15;
  uStack_2c = param_16;
  local_64 = param_2;
  uStack_60 = param_3;
  uStack_5c = param_4;
  AbyssEngine::AEMath::Matrix::operator=((Matrix *)(param_1 + 0x13c),(Matrix *)&local_64);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== TargetFollowCamera::getLocal  @0x00187808  (32 bytes)
/* TargetFollowCamera::getLocal() */

void TargetFollowCamera::getLocal(void)

{
  undefined4 *in_r0;
  int in_r1;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar1 = *(undefined4 *)(in_r1 + 0x140);
  uVar2 = *(undefined4 *)(in_r1 + 0x144);
  uVar3 = *(undefined4 *)(in_r1 + 0x148);
  uVar4 = *(undefined4 *)(in_r1 + 0x14c);
  *in_r0 = *(undefined4 *)(in_r1 + 0x13c);
  in_r0[1] = uVar1;
  in_r0[2] = uVar2;
  in_r0[3] = uVar3;
  in_r0[4] = uVar4;
  uVar1 = *(undefined4 *)(in_r1 + 0x154);
  uVar2 = *(undefined4 *)(in_r1 + 0x158);
  uVar3 = *(undefined4 *)(in_r1 + 0x15c);
  uVar4 = *(undefined4 *)(in_r1 + 0x160);
  in_r0[5] = *(undefined4 *)(in_r1 + 0x150);
  in_r0[6] = uVar1;
  in_r0[7] = uVar2;
  in_r0[8] = uVar3;
  in_r0[9] = uVar4;
  uVar1 = *(undefined4 *)(in_r1 + 0x168);
  uVar2 = *(undefined4 *)(in_r1 + 0x16c);
  uVar3 = *(undefined4 *)(in_r1 + 0x170);
  uVar4 = *(undefined4 *)(in_r1 + 0x174);
  in_r0[10] = *(undefined4 *)(in_r1 + 0x164);
  in_r0[0xb] = uVar1;
  in_r0[0xc] = uVar2;
  in_r0[0xd] = uVar3;
  in_r0[0xe] = uVar4;
  return;
}

// ===== TargetFollowCamera::setLocked  @0x00187828  (132 bytes)
/* TargetFollowCamera::setLocked(bool) */

void __thiscall TargetFollowCamera::setLocked(TargetFollowCamera *this,bool param_1)

{
  undefined4 *puVar1;
  AEMath aAStack_6c [12];
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int local_20;
  
  local_20 = __stack_chk_guard;
  this[0x44] = (TargetFollowCamera)param_1;
  if (param_1) {
    puVar1 = (undefined4 *)AEGeometry::getMatrix(*(AEGeometry **)(this + 4));
    local_60 = *puVar1;
    uStack_5c = puVar1[1];
    uStack_58 = puVar1[2];
    uStack_54 = puVar1[3];
    uStack_50 = puVar1[4];
    local_4c = puVar1[5];
    uStack_48 = puVar1[6];
    uStack_44 = puVar1[7];
    uStack_40 = puVar1[8];
    uStack_3c = puVar1[9];
    local_38 = puVar1[10];
    uStack_34 = puVar1[0xb];
    uStack_30 = puVar1[0xc];
    uStack_2c = puVar1[0xd];
    uStack_28 = puVar1[0xe];
    AbyssEngine::AEMath::MatrixGetUp(aAStack_6c,(Matrix *)&local_60);
    AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x20),(Vector *)aAStack_6c);
    AbyssEngine::AEMath::MatrixTransformVector
              (aAStack_6c,(Matrix *)&local_60,(Vector *)(this + 0x38));
    AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 8),(Vector *)aAStack_6c);
    update(this,0x32);
  }
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== TargetFollowCamera::setRotationAroundTarget  @0x001878b4  (6 bytes)
/* TargetFollowCamera::setRotationAroundTarget(bool) */

void __thiscall TargetFollowCamera::setRotationAroundTarget(TargetFollowCamera *this,bool param_1)

{
  this[0x4c] = (TargetFollowCamera)param_1;
  return;
}

// ===== TargetFollowCamera::rotateAroundTarget  @0x001878bc  (58 bytes)
/* TargetFollowCamera::rotateAroundTarget(float, float, float) */

void __thiscall
TargetFollowCamera::rotateAroundTarget
          (TargetFollowCamera *this,float param_1,float param_2,float param_3)

{
  Vector local_18 [12];
  int local_c;
  
  local_c = __stack_chk_guard;
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x50),local_18);
  if (__stack_chk_guard != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== TargetFollowCamera::zoomTarget  @0x00187900  (6 bytes)
/* TargetFollowCamera::zoomTarget(float) */

void __thiscall TargetFollowCamera::zoomTarget(TargetFollowCamera *this,float param_1)

{
  undefined4 in_r1;
  
  *(undefined4 *)(this + 0xb0) = in_r1;
  return;
}

// ===== TargetFollowCamera::setLookAtCam  @0x00187906  (6 bytes)
/* TargetFollowCamera::setLookAtCam(bool) */

void __thiscall TargetFollowCamera::setLookAtCam(TargetFollowCamera *this,bool param_1)

{
  this[0x45] = (TargetFollowCamera)param_1;
  return;
}

// ===== TargetFollowCamera::calculateCoefficents  @0x0018790c  (108 bytes)
/* TargetFollowCamera::calculateCoefficents(float) */

void __thiscall TargetFollowCamera::calculateCoefficents(TargetFollowCamera *this,float param_1)

{
  float in_r1;
  
  aproximateCooefficientsForAproximationOfDampingFunktion
            (this + 0x80,*(float *)(this + 0x128) * in_r1,
             (double *)(*(float *)(this + 0x128) * in_r1),(double *)(this + 0x60),
             (double *)(this + 0x68),(double *)(this + 0x70),(double *)(this + 0x78));
  aproximateCooefficientsForAproximationOfDampingFunktion
            (this + 0xa8,*(float *)(this + 300) * in_r1,(double *)(*(float *)(this + 300) * in_r1),
             (double *)(this + 0x88),(double *)(this + 0x90),(double *)(this + 0x98),
             (double *)(this + 0xa0));
  return;
}

// ===== TargetFollowCamera::setFastForwardMode  @0x00187978  (316 bytes)
/* TargetFollowCamera::setFastForwardMode(bool) */

void __thiscall TargetFollowCamera::setFastForwardMode(TargetFollowCamera *this,bool param_1)

{
  TargetFollowCamera TVar1;
  float fVar2;
  
  if (param_1) {
    if (this[0x4d] != (TargetFollowCamera)0x0) {
      return;
    }
    fVar2 = *(float *)(this + 0x134) * 0.01 * 0.011 + 0.001;
    *(float *)(this + 0x128) = (1.0 - *(float *)(this + 0x134) * 0.01) * 0.014999999 + 0.003;
    *(float *)(this + 300) = fVar2;
    fVar2 = (float)calculateCoefficents(this,fVar2);
    fVar2 = (float)aproximateCooefficientsForAproximationOfDampingFunktion
                             (this + 0x80,fVar2,*(double **)(this + 0x128),(double *)(this + 0x60),
                              (double *)(this + 0x68),(double *)(this + 0x70),
                              (double *)(this + 0x78));
    aproximateCooefficientsForAproximationOfDampingFunktion
              (this + 0xa8,fVar2,*(double **)(this + 300),(double *)(this + 0x88),
               (double *)(this + 0x90),(double *)(this + 0x98),(double *)(this + 0xa0));
    TVar1 = (TargetFollowCamera)0x1;
  }
  else {
    if (this[0x4d] == (TargetFollowCamera)0x0) {
      return;
    }
    fVar2 = *(float *)(this + 0x134) * 0.01 * 0.011 + 0.001;
    *(float *)(this + 0x128) = (1.0 - *(float *)(this + 0x134) * 0.01) * 0.014999999 + 0.003;
    *(float *)(this + 300) = fVar2;
    fVar2 = (float)calculateCoefficents(this,fVar2);
    fVar2 = (float)aproximateCooefficientsForAproximationOfDampingFunktion
                             (this + 0x80,fVar2,*(double **)(this + 0x128),(double *)(this + 0x60),
                              (double *)(this + 0x68),(double *)(this + 0x70),
                              (double *)(this + 0x78));
    aproximateCooefficientsForAproximationOfDampingFunktion
              (this + 0xa8,fVar2,*(double **)(this + 300),(double *)(this + 0x88),
               (double *)(this + 0x90),(double *)(this + 0x98),(double *)(this + 0xa0));
    TVar1 = (TargetFollowCamera)0x0;
  }
  this[0x4d] = TVar1;
  return;
}

// ===== TargetFollowCamera::setShipHandling  @0x00187ac8  (72 bytes)
/* TargetFollowCamera::setShipHandling(float) */

void __thiscall TargetFollowCamera::setShipHandling(TargetFollowCamera *this,float param_1)

{
  float in_r1;
  float fVar1;
  
  *(float *)(this + 0x134) = in_r1;
  fVar1 = in_r1 * 0.01 * 0.011 + 0.001;
  *(float *)(this + 0x128) = (1.0 - in_r1 * 0.01) * 0.014999999 + 0.003;
  *(float *)(this + 300) = fVar1;
  calculateCoefficents(this,fVar1);
  return;
}

// ===== TargetFollowCamera::isInFastForwardMode  @0x00187b24  (6 bytes)
/* TargetFollowCamera::isInFastForwardMode() */

TargetFollowCamera __thiscall TargetFollowCamera::isInFastForwardMode(TargetFollowCamera *this)

{
  return this[0x4d];
}

// ===== TargetFollowCamera::isInLookAtMode  @0x00187b2a  (6 bytes)
/* TargetFollowCamera::isInLookAtMode() */

TargetFollowCamera __thiscall TargetFollowCamera::isInLookAtMode(TargetFollowCamera *this)

{
  return this[0x45];
}

// ===== TargetFollowCamera::resetShipHandling  @0x00187b30  (30 bytes)
/* TargetFollowCamera::resetShipHandling() */

void TargetFollowCamera::resetShipHandling(void)

{
  TargetFollowCamera *in_r0;
  float in_s0;
  
  *(undefined4 *)(in_r0 + 0x128) = 0x3ba3d70a;
  *(undefined4 *)(in_r0 + 300) = 0x3bc49ba6;
  calculateCoefficents(in_r0,in_s0);
  return;
}

// ===== TargetFollowCamera::hit  @0x00187b4c  (32 bytes)
/* TargetFollowCamera::hit() */

void __thiscall TargetFollowCamera::hit(TargetFollowCamera *this)

{
  if (this[0x47] == (TargetFollowCamera)0x0) {
    this[0x47] = (TargetFollowCamera)0x1;
    *(undefined4 *)(this + 0x48) = 1000;
    *(undefined4 *)(this + 0x120) = 6;
    this[0x124] = (TargetFollowCamera)0x0;
  }
  return;
}

// ===== TargetFollowCamera::hitSmall  @0x00187b6c  (28 bytes)
/* TargetFollowCamera::hitSmall() */

void __thiscall TargetFollowCamera::hitSmall(TargetFollowCamera *this)

{
  if (this[0x47] == (TargetFollowCamera)0x0) {
    this[0x47] = (TargetFollowCamera)0x1;
    *(undefined4 *)(this + 0x48) = 0x32;
    *(undefined4 *)(this + 0x120) = 2;
    this[0x124] = (TargetFollowCamera)0x1;
  }
  return;
}

// ===== TargetFollowCamera::useTargetsUpVector  @0x00187b88  (6 bytes)
/* TargetFollowCamera::useTargetsUpVector(bool) */

void __thiscall TargetFollowCamera::useTargetsUpVector(TargetFollowCamera *this,bool param_1)

{
  this[0x10c] = (TargetFollowCamera)param_1;
  return;
}

// ===== TargetFollowCamera::roll  @0x00187b8e  (18 bytes)
/* TargetFollowCamera::roll(float) */

void __thiscall TargetFollowCamera::roll(TargetFollowCamera *this,float param_1)

{
  float in_r1;
  
  *(float *)(this + 0x130) = *(float *)(this + 0x130) + in_r1;
  return;
}

// ===== TargetFollowCamera::setRoll  @0x00187ba0  (6 bytes)
/* TargetFollowCamera::setRoll(float) */

void __thiscall TargetFollowCamera::setRoll(TargetFollowCamera *this,float param_1)

{
  undefined4 in_r1;
  
  *(undefined4 *)(this + 0x130) = in_r1;
  return;
}

