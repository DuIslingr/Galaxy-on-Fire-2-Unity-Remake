// Class: AbyssEngine::Quaternion
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::Quaternion::Quaternion  @0x0008b826  (2 bytes)
/* AbyssEngine::Quaternion::Quaternion() */

Quaternion * __thiscall AbyssEngine::Quaternion::Quaternion(Quaternion *this)

{
  return this;
}

// ===== AbyssEngine::Quaternion::Quaternion  @0x0008b828  (14 bytes)
/* AbyssEngine::Quaternion::Quaternion(float, float, float, float) */

void __thiscall
AbyssEngine::Quaternion::Quaternion
          (Quaternion *this,float param_1,float param_2,float param_3,float param_4)

{
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  undefined4 in_stack_00000000;
  
  *(undefined4 *)(this + 0xc) = in_stack_00000000;
  *(undefined4 *)this = in_r1;
  *(undefined4 *)(this + 4) = in_r2;
  *(undefined4 *)(this + 8) = in_r3;
  return;
}

// ===== AbyssEngine::Quaternion::Quaternion  @0x0008b836  (14 bytes)
/* AbyssEngine::Quaternion::Quaternion(AbyssEngine::AEMath::Vector) */

Quaternion * __thiscall
AbyssEngine::Quaternion::Quaternion(float param_1,float param_2,float param_3,Quaternion *this)

{
  Set(this,param_1,param_2,param_3);
  return this;
}

// ===== AbyssEngine::Quaternion::Set  @0x0008b844  (4 bytes)
/* AbyssEngine::Quaternion::Set(AbyssEngine::AEMath::Vector) */

void AbyssEngine::Quaternion::Set(float param_1,float param_2,float param_3,Quaternion *param_4)

{
  Set(param_4,param_1,param_2,param_3);
  return;
}

// ===== AbyssEngine::Quaternion::Quaternion  @0x0008b848  (2 bytes)
/* AbyssEngine::Quaternion::Quaternion(AbyssEngine::Quaternion*) */

Quaternion * __thiscall AbyssEngine::Quaternion::Quaternion(Quaternion *this,Quaternion *param_1)

{
  return this;
}

// ===== AbyssEngine::Quaternion::Quaternion  @0x0008b84a  (14 bytes)
/* AbyssEngine::Quaternion::Quaternion(AbyssEngine::AEMath::Matrix const&) */

Quaternion * __thiscall AbyssEngine::Quaternion::Quaternion(Quaternion *this,Matrix *param_1)

{
  Set(this,param_1);
  return this;
}

// ===== AbyssEngine::Quaternion::Set  @0x0008b858  (528 bytes)
/* AbyssEngine::Quaternion::Set(AbyssEngine::AEMath::Matrix const&) */

void __thiscall AbyssEngine::Quaternion::Set(Quaternion *this,Matrix *param_1)

{
  float extraout_r0;
  float extraout_r0_00;
  float extraout_r0_01;
  float extraout_r0_02;
  bool bVar1;
  bool bVar2;
  bool bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  fVar4 = *(float *)param_1;
  fVar5 = *(float *)(param_1 + 0x14);
  fVar6 = *(float *)(param_1 + 0x28);
  fVar7 = fVar4 + fVar5 + fVar6 + 1.0;
  if (fVar7 <= 1e-07) {
    bVar1 = fVar4 < fVar5;
    bVar2 = fVar4 == fVar5;
    bVar3 = NAN(fVar4) || NAN(fVar5);
    if (!bVar2 && !bVar1) {
      bVar1 = fVar4 < fVar6;
      bVar2 = fVar4 == fVar6;
      bVar3 = NAN(fVar4) || NAN(fVar6);
    }
    if (bVar2 || bVar1 != bVar3) {
      if (fVar5 <= fVar6) {
        fVar7 = SQRT(((fVar6 + 1.0) - fVar4) - fVar5);
        if (NAN(fVar7)) {
          sqrtf(fVar7);
          fVar7 = extraout_r0_02;
        }
        fVar7 = fVar7 + fVar7;
        *(float *)(this + 0xc) = (*(float *)(param_1 + 0x10) - *(float *)(param_1 + 4)) / fVar7;
        *(float *)this = (*(float *)(param_1 + 0x20) + *(float *)(param_1 + 8)) / fVar7;
        fVar4 = fVar7 * 0.25;
        *(float *)(this + 4) = (*(float *)(param_1 + 0x24) + *(float *)(param_1 + 0x18)) / fVar7;
        goto LAB_0008b97c;
      }
      fVar4 = SQRT(((fVar5 + 1.0) - fVar4) - fVar6);
      if (NAN(fVar4)) {
        sqrtf(fVar4);
        fVar4 = extraout_r0_01;
      }
      fVar4 = fVar4 + fVar4;
      *(float *)(this + 0xc) = (*(float *)(param_1 + 0x20) - *(float *)(param_1 + 8)) / fVar4;
      *(float *)this = (*(float *)(param_1 + 0x10) + *(float *)(param_1 + 4)) / fVar4;
      *(float *)(this + 4) = fVar4 * 0.25;
      fVar7 = *(float *)(param_1 + 0x18);
      fVar5 = *(float *)(param_1 + 0x24);
    }
    else {
      fVar4 = SQRT(((fVar4 + 1.0) - fVar5) - fVar6);
      if (NAN(fVar4)) {
        sqrtf(fVar4);
        fVar4 = extraout_r0_00;
      }
      fVar4 = fVar4 + fVar4;
      *(float *)(this + 0xc) = (*(float *)(param_1 + 0x24) - *(float *)(param_1 + 0x18)) / fVar4;
      *(float *)this = fVar4 * 0.25;
      *(float *)(this + 4) = (*(float *)(param_1 + 0x10) + *(float *)(param_1 + 4)) / fVar4;
      fVar7 = *(float *)(param_1 + 8);
      fVar5 = *(float *)(param_1 + 0x20);
    }
    fVar4 = (fVar5 + fVar7) / fVar4;
  }
  else {
    fVar7 = SQRT(fVar7);
    if (NAN(fVar7)) {
      sqrtf(fVar7);
      fVar7 = extraout_r0;
    }
    fVar4 = (1.0 / fVar7) * 0.5;
    *(float *)(this + 0xc) = 0.25 / fVar4;
    *(float *)this = fVar4 * (*(float *)(param_1 + 0x18) - *(float *)(param_1 + 0x24));
    *(float *)(this + 4) = fVar4 * (*(float *)(param_1 + 0x20) - *(float *)(param_1 + 8));
    fVar4 = fVar4 * (*(float *)(param_1 + 4) - *(float *)(param_1 + 0x10));
  }
LAB_0008b97c:
  *(float *)(this + 8) = fVar4;
  return;
}

// ===== AbyssEngine::Quaternion::~Quaternion  @0x0008ba6c  (2 bytes)
/* AbyssEngine::Quaternion::~Quaternion() */

Quaternion * __thiscall AbyssEngine::Quaternion::~Quaternion(Quaternion *this)

{
  return this;
}

// ===== AbyssEngine::Quaternion::Set  @0x0008ba6e  (210 bytes)
/* AbyssEngine::Quaternion::Set(float, float, float) */

void __thiscall
AbyssEngine::Quaternion::Set(Quaternion *this,float param_1,float param_2,float param_3)

{
  float extraout_r0;
  float extraout_r0_00;
  float extraout_r0_01;
  float extraout_r0_02;
  float __x;
  float extraout_r0_03;
  float in_r2;
  float in_r3;
  float fVar1;
  
  cosf(in_r3 * 0.5);
  fVar1 = cosf(in_r2 * 0.5);
  fVar1 = cosf(fVar1);
  fVar1 = sinf(fVar1);
  sinf(fVar1);
  sinf(__x);
  *(float *)this =
       extraout_r0_01 * extraout_r0_02 * __x - extraout_r0 * extraout_r0_00 * extraout_r0_03;
  *(float *)(this + 4) =
       -(extraout_r0_01 * extraout_r0 * __x) - extraout_r0_00 * extraout_r0_02 * extraout_r0_03;
  *(float *)(this + 8) =
       extraout_r0 * __x * extraout_r0_03 - extraout_r0_01 * extraout_r0_00 * extraout_r0_02;
  *(float *)(this + 0xc) =
       extraout_r0 * extraout_r0_00 * extraout_r0_01 + extraout_r0_02 * __x * extraout_r0_03;
  return;
}

// ===== AbyssEngine::Quaternion::Inverse  @0x0008bb40  (86 bytes)
/* AbyssEngine::Quaternion::Inverse() const */

void AbyssEngine::Quaternion::Inverse(void)

{
  float *in_r0;
  float *in_r1;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar1 = *in_r1;
  fVar2 = in_r1[1];
  fVar3 = in_r1[2];
  fVar4 = in_r1[3];
  fVar5 = 1.0 / (fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3 + fVar4 * fVar4);
  *in_r0 = -(fVar5 * fVar1);
  in_r0[1] = -(fVar5 * fVar2);
  in_r0[2] = -(fVar5 * fVar3);
  in_r0[3] = fVar4 * fVar5;
  return;
}

// ===== AbyssEngine::Quaternion::Dot  @0x0008bb96  (66 bytes)
/* AbyssEngine::Quaternion::Dot(AbyssEngine::Quaternion const&, AbyssEngine::Quaternion const&) */

float AbyssEngine::Quaternion::Dot(Quaternion *param_1,Quaternion *param_2)

{
  return *(float *)param_1 * *(float *)param_2 + *(float *)(param_1 + 4) * *(float *)(param_2 + 4) +
         *(float *)(param_1 + 8) * *(float *)(param_2 + 8) +
         *(float *)(param_1 + 0xc) * *(float *)(param_2 + 0xc);
}

// ===== AbyssEngine::Quaternion::Lerp  @0x0008bbd8  (114 bytes)
/* AbyssEngine::Quaternion::Lerp(AbyssEngine::Quaternion const&, AbyssEngine::Quaternion const&,
   float) */

void AbyssEngine::Quaternion::Lerp(Quaternion *param_1,Quaternion *param_2,float param_3)

{
  undefined4 uVar1;
  float extraout_r0;
  undefined1 (*in_r2) [16];
  float __x;
  undefined4 in_s4;
  undefined4 in_s5;
  undefined1 auVar2 [16];
  
  auVar2 = FloatVectorSub(*in_r2,*(undefined1 (*) [16])param_2,2,0x20);
  uVar1 = VectorGetElement(CONCAT44(in_s5,in_s4),0,4,0);
  auVar2 = VectorMultiply(auVar2,uVar1,4);
  auVar2 = FloatVectorAdd(*(undefined1 (*) [16])param_2,auVar2,2);
  __x = SQRT(auVar2._0_4_ * auVar2._0_4_ + auVar2._4_4_ * auVar2._4_4_ + auVar2._8_4_ * auVar2._8_4_
             + auVar2._12_4_ * auVar2._12_4_);
  if (NAN(__x)) {
    sqrtf(__x);
    __x = extraout_r0;
  }
  *(ulonglong *)param_1 = CONCAT44(auVar2._4_4_ / __x,auVar2._0_4_ / __x);
  *(ulonglong *)(param_1 + 8) = CONCAT44(auVar2._12_4_ / __x,auVar2._8_4_ / __x);
  return;
}

// ===== AbyssEngine::Quaternion::Normalized  @0x0008bc4a  (136 bytes)
/* AbyssEngine::Quaternion::Normalized() */

void AbyssEngine::Quaternion::Normalized(void)

{
  undefined8 *in_r0;
  float extraout_r0;
  float *in_r1;
  float __x;
  undefined8 uVar1;
  
  __x = SQRT(*in_r1 * *in_r1 + in_r1[1] * in_r1[1] + in_r1[2] * in_r1[2] + in_r1[3] * in_r1[3]);
  if (NAN(__x)) {
    sqrtf(__x);
    __x = extraout_r0;
  }
  *in_r1 = *in_r1 / __x;
  in_r1[1] = in_r1[1] / __x;
  in_r1[2] = in_r1[2] / __x;
  in_r1[3] = in_r1[3] / __x;
  uVar1 = *(undefined8 *)(in_r1 + 2);
  *in_r0 = *(undefined8 *)in_r1;
  in_r0[1] = uVar1;
  return;
}

// ===== AbyssEngine::Quaternion::Lerp  @0x0008bcd2  (240 bytes)
/* AbyssEngine::Quaternion::Lerp(float const*, float const*, float) */

void __thiscall
AbyssEngine::Quaternion::Lerp(Quaternion *this,float *param_1,float *param_2,float param_3)

{
  float extraout_r0;
  float in_r3;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar7 = *param_2;
  fVar4 = *param_1;
  fVar2 = param_2[1];
  fVar5 = param_1[1];
  fVar8 = param_2[2];
  fVar3 = param_1[2];
  fVar6 = param_2[3];
  fVar1 = param_1[3];
  if ((int)((uint)(fVar4 * fVar7 + fVar5 * fVar2 + fVar3 * fVar8 + fVar1 * fVar6 < 0.0) << 0x1f) < 0
     ) {
    fVar2 = -fVar2;
    fVar7 = -fVar7;
    fVar8 = -fVar8;
    fVar6 = -fVar6;
  }
  fVar5 = fVar5 + (fVar2 - fVar5) * in_r3;
  fVar4 = fVar4 + (fVar7 - fVar4) * in_r3;
  fVar3 = fVar3 + (fVar8 - fVar3) * in_r3;
  fVar1 = fVar1 + (fVar6 - fVar1) * in_r3;
  fVar6 = fVar4 * fVar4 + fVar5 * fVar5 + fVar3 * fVar3 + fVar1 * fVar1;
  fVar2 = SQRT(fVar6);
  if (NAN(fVar2)) {
    sqrtf(fVar6);
    fVar2 = extraout_r0;
  }
  *(float *)this = fVar4 / fVar2;
  *(float *)(this + 4) = fVar5 / fVar2;
  *(float *)(this + 8) = fVar3 / fVar2;
  *(float *)(this + 0xc) = fVar1 / fVar2;
  return;
}

// ===== AbyssEngine::Quaternion::operator.cast.to.float*  @0x0008bdc2  (2 bytes)
/* AbyssEngine::Quaternion::operator float*() */

float * __thiscall AbyssEngine::Quaternion::operator_cast_to_float_(Quaternion *this)

{
  return (float *)this;
}

// ===== AbyssEngine::Quaternion::operator.cast.to.float*  @0x0008bdc4  (2 bytes)
/* AbyssEngine::Quaternion::operator float const*() const */

float * __thiscall AbyssEngine::Quaternion::operator_cast_to_float_(Quaternion *this)

{
  return (float *)this;
}

// ===== AbyssEngine::Quaternion::operator[]  @0x0008bdc6  (6 bytes)
/* AbyssEngine::Quaternion::operator[](int) */

Quaternion * __thiscall AbyssEngine::Quaternion::operator[](Quaternion *this,int param_1)

{
  return this + param_1 * 4;
}

// ===== AbyssEngine::Quaternion::operator[]  @0x0008bdcc  (6 bytes)
/* AbyssEngine::Quaternion::operator[](int) const */

undefined4 __thiscall AbyssEngine::Quaternion::operator[](Quaternion *this,int param_1)

{
  return *(undefined4 *)(this + param_1 * 4);
}

// ===== AbyssEngine::Quaternion::Length  @0x0008bdd2  (72 bytes)
/* AbyssEngine::Quaternion::Length() const */

float __thiscall AbyssEngine::Quaternion::Length(Quaternion *this)

{
  float extraout_r0;
  float __x;
  float fVar1;
  
  __x = *(float *)this * *(float *)this + *(float *)(this + 4) * *(float *)(this + 4) +
        *(float *)(this + 8) * *(float *)(this + 8) +
        *(float *)(this + 0xc) * *(float *)(this + 0xc);
  fVar1 = SQRT(__x);
  if (NAN(fVar1)) {
    sqrtf(__x);
    return extraout_r0;
  }
  return fVar1;
}

// ===== AbyssEngine::Quaternion::Convert  @0x0008be1a  (314 bytes)
/* AbyssEngine::Quaternion::Convert(AbyssEngine::AEMath::Matrix&) */

void __thiscall AbyssEngine::Quaternion::Convert(Quaternion *this,Matrix *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  
  fVar7 = *(float *)this;
  fVar8 = *(float *)(this + 4);
  fVar14 = fVar7 * fVar7;
  fVar9 = *(float *)(this + 8);
  fVar11 = fVar8 * fVar8;
  fVar10 = *(float *)(this + 0xc);
  fVar12 = fVar9 * fVar9;
  fVar13 = fVar10 * fVar10;
  fVar1 = 1.0 / (fVar13 + fVar14 + fVar11 + fVar12);
  fVar6 = fVar7 * fVar8 + fVar9 * fVar10;
  fVar5 = fVar7 * fVar8 - fVar9 * fVar10;
  fVar4 = fVar7 * fVar9 - fVar8 * fVar10;
  fVar3 = fVar7 * fVar9 + fVar8 * fVar10;
  fVar2 = fVar8 * fVar9 + fVar7 * fVar10;
  fVar7 = fVar8 * fVar9 - fVar7 * fVar10;
  *(float *)param_1 = (fVar13 + ((fVar14 - fVar11) - fVar12)) * fVar1;
  *(float *)(param_1 + 0x14) = (fVar13 + ((fVar11 - fVar14) - fVar12)) * fVar1;
  *(float *)(param_1 + 0x28) = (fVar13 + (-fVar14 - fVar11) + fVar12) * fVar1;
  *(float *)(param_1 + 4) = fVar1 * (fVar6 + fVar6);
  *(float *)(param_1 + 0x10) = fVar1 * (fVar5 + fVar5);
  *(float *)(param_1 + 8) = fVar1 * (fVar4 + fVar4);
  *(float *)(param_1 + 0x20) = fVar1 * (fVar3 + fVar3);
  *(float *)(param_1 + 0x18) = fVar1 * (fVar2 + fVar2);
  *(float *)(param_1 + 0x24) = fVar1 * (fVar7 + fVar7);
  return;
}

