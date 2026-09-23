// Class: AbyssEngine::AEMath
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::AEMath::operator+  @0x0007d046  (14 bytes)
/* AbyssEngine::AEMath::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::Vector const&) */

void __thiscall AbyssEngine::AEMath::operator+(AEMath *this,Vector *param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)param_1;
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined8 *)this = uVar1;
  return;
}

// ===== AbyssEngine::AEMath::operator-  @0x0007d054  (38 bytes)
/* AbyssEngine::AEMath::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::Vector const&) */

void __thiscall AbyssEngine::AEMath::operator-(AEMath *this,Vector *param_1)

{
  float fVar1;
  float fVar2;
  
  fVar1 = *(float *)(param_1 + 4);
  fVar2 = *(float *)(param_1 + 8);
  *(float *)this = -*(float *)param_1;
  *(float *)(this + 4) = -fVar1;
  *(float *)(this + 8) = -fVar2;
  return;
}

// ===== AbyssEngine::AEMath::operator+  @0x0007d07a  (50 bytes)
/* AbyssEngine::AEMath::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::Vector const&,
   AbyssEngine::AEMath::Vector const&) */

void __thiscall AbyssEngine::AEMath::operator+(AEMath *this,Vector *param_1,Vector *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = *(float *)(param_2 + 4);
  fVar3 = *(float *)(param_1 + 4);
  fVar2 = *(float *)(param_2 + 8);
  fVar4 = *(float *)(param_1 + 8);
  *(float *)this = *(float *)param_1 + *(float *)param_2;
  *(float *)(this + 4) = fVar3 + fVar1;
  *(float *)(this + 8) = fVar4 + fVar2;
  return;
}

// ===== AbyssEngine::AEMath::operator-  @0x0007d0ac  (50 bytes)
/* AbyssEngine::AEMath::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::Vector const&,
   AbyssEngine::AEMath::Vector const&) */

void __thiscall AbyssEngine::AEMath::operator-(AEMath *this,Vector *param_1,Vector *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = *(float *)(param_2 + 4);
  fVar3 = *(float *)(param_1 + 4);
  fVar2 = *(float *)(param_2 + 8);
  fVar4 = *(float *)(param_1 + 8);
  *(float *)this = *(float *)param_1 - *(float *)param_2;
  *(float *)(this + 4) = fVar3 - fVar1;
  *(float *)(this + 8) = fVar4 - fVar2;
  return;
}

// ===== AbyssEngine::AEMath::operator*  @0x0007d0de  (50 bytes)
/* AbyssEngine::AEMath::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::Vector const&,
   AbyssEngine::AEMath::Vector const&) */

void __thiscall AbyssEngine::AEMath::operator*(AEMath *this,Vector *param_1,Vector *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = *(float *)(param_2 + 4);
  fVar3 = *(float *)(param_1 + 4);
  fVar2 = *(float *)(param_2 + 8);
  fVar4 = *(float *)(param_1 + 8);
  *(float *)this = *(float *)param_1 * *(float *)param_2;
  *(float *)(this + 4) = fVar3 * fVar1;
  *(float *)(this + 8) = fVar4 * fVar2;
  return;
}

// ===== AbyssEngine::AEMath::operator*  @0x0007d110  (42 bytes)
/* AbyssEngine::AEMath::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::Vector const&, float) */

void __thiscall AbyssEngine::AEMath::operator*(AEMath *this,Vector *param_1,float param_2)

{
  float in_r2;
  float fVar1;
  float fVar2;
  
  fVar1 = *(float *)(param_1 + 4);
  fVar2 = *(float *)(param_1 + 8);
  *(float *)this = *(float *)param_1 * in_r2;
  *(float *)(this + 4) = fVar1 * in_r2;
  *(float *)(this + 8) = fVar2 * in_r2;
  return;
}

// ===== AbyssEngine::AEMath::operator*  @0x0007d13a  (42 bytes)
/* AbyssEngine::AEMath::TEMPNAMEPLACEHOLDERVALUE(float, AbyssEngine::AEMath::Vector const&) */

void __thiscall AbyssEngine::AEMath::operator*(AEMath *this,float param_1,Vector *param_2)

{
  float *in_r2;
  float fVar1;
  float fVar2;
  
  fVar1 = in_r2[1];
  fVar2 = in_r2[2];
  *(float *)this = *in_r2 * (float)param_2;
  *(float *)(this + 4) = fVar1 * (float)param_2;
  *(float *)(this + 8) = fVar2 * (float)param_2;
  return;
}

// ===== AbyssEngine::AEMath::operator/  @0x0007d164  (50 bytes)
/* AbyssEngine::AEMath::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::Vector const&,
   AbyssEngine::AEMath::Vector const&) */

void __thiscall AbyssEngine::AEMath::operator/(AEMath *this,Vector *param_1,Vector *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = *(float *)(param_2 + 4);
  fVar3 = *(float *)(param_1 + 4);
  fVar2 = *(float *)(param_2 + 8);
  fVar4 = *(float *)(param_1 + 8);
  *(float *)this = *(float *)param_1 / *(float *)param_2;
  *(float *)(this + 4) = fVar3 / fVar1;
  *(float *)(this + 8) = fVar4 / fVar2;
  return;
}

// ===== AbyssEngine::AEMath::operator/  @0x0007d196  (42 bytes)
/* AbyssEngine::AEMath::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::Vector const&, float) */

void __thiscall AbyssEngine::AEMath::operator/(AEMath *this,Vector *param_1,float param_2)

{
  float in_r2;
  float fVar1;
  float fVar2;
  
  fVar1 = *(float *)(param_1 + 4);
  fVar2 = *(float *)(param_1 + 8);
  *(float *)this = *(float *)param_1 / in_r2;
  *(float *)(this + 4) = fVar1 / in_r2;
  *(float *)(this + 8) = fVar2 / in_r2;
  return;
}

// ===== AbyssEngine::AEMath::operator/  @0x0007d1c0  (42 bytes)
/* AbyssEngine::AEMath::TEMPNAMEPLACEHOLDERVALUE(float, AbyssEngine::AEMath::Vector const&) */

void __thiscall AbyssEngine::AEMath::operator/(AEMath *this,float param_1,Vector *param_2)

{
  float *in_r2;
  float fVar1;
  float fVar2;
  
  fVar1 = in_r2[1];
  fVar2 = in_r2[2];
  *(float *)this = *in_r2 / (float)param_2;
  *(float *)(this + 4) = fVar1 / (float)param_2;
  *(float *)(this + 8) = fVar2 / (float)param_2;
  return;
}

// ===== AbyssEngine::AEMath::operator==  @0x0007d1ea  (68 bytes)
/* AbyssEngine::AEMath::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::Vector const&,
   AbyssEngine::AEMath::Vector const&) */

bool AbyssEngine::AEMath::operator==(Vector *param_1,Vector *param_2)

{
  if (*(float *)param_1 != *(float *)param_2) {
    return false;
  }
  if (*(float *)(param_1 + 4) == *(float *)(param_2 + 4)) {
    return *(float *)(param_1 + 8) == *(float *)(param_2 + 8);
  }
  return false;
}

// ===== AbyssEngine::AEMath::operator!=  @0x0007d22e  (64 bytes)
/* AbyssEngine::AEMath::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::Vector const&,
   AbyssEngine::AEMath::Vector const&) */

bool AbyssEngine::AEMath::operator!=(Vector *param_1,Vector *param_2)

{
  if ((*(float *)param_1 == *(float *)param_2) &&
     (*(float *)(param_1 + 4) == *(float *)(param_2 + 4))) {
    return *(float *)(param_1 + 8) != *(float *)(param_2 + 8);
  }
  return true;
}

// ===== AbyssEngine::AEMath::operator<  @0x0007d26e  (68 bytes)
/* AbyssEngine::AEMath::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::Vector const&,
   AbyssEngine::AEMath::Vector const&) */

bool AbyssEngine::AEMath::operator<(Vector *param_1,Vector *param_2)

{
  if (-1 < (int)((uint)(*(float *)param_1 < *(float *)param_2) << 0x1f)) {
    return false;
  }
  if ((int)((uint)(*(float *)(param_1 + 4) < *(float *)(param_2 + 4)) << 0x1f) < 0) {
    return (int)((uint)(*(float *)(param_1 + 8) < *(float *)(param_2 + 8)) << 0x1f) < 0;
  }
  return false;
}

// ===== AbyssEngine::AEMath::operator>  @0x0007d2b2  (68 bytes)
/* AbyssEngine::AEMath::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::Vector const&,
   AbyssEngine::AEMath::Vector const&) */

bool AbyssEngine::AEMath::operator>(Vector *param_1,Vector *param_2)

{
  if (*(float *)param_1 <= *(float *)param_2) {
    return false;
  }
  if (*(float *)(param_2 + 4) < *(float *)(param_1 + 4)) {
    return *(float *)(param_2 + 8) < *(float *)(param_1 + 8);
  }
  return false;
}

// ===== AbyssEngine::AEMath::operator<=  @0x0007d2f6  (68 bytes)
/* AbyssEngine::AEMath::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::Vector const&,
   AbyssEngine::AEMath::Vector const&) */

bool AbyssEngine::AEMath::operator<=(Vector *param_1,Vector *param_2)

{
  if (*(float *)param_2 < *(float *)param_1) {
    return false;
  }
  if (*(float *)(param_1 + 4) <= *(float *)(param_2 + 4)) {
    return *(float *)(param_1 + 8) <= *(float *)(param_2 + 8);
  }
  return false;
}

// ===== AbyssEngine::AEMath::operator>=  @0x0007d33a  (68 bytes)
/* AbyssEngine::AEMath::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::Vector const&,
   AbyssEngine::AEMath::Vector const&) */

bool AbyssEngine::AEMath::operator>=(Vector *param_1,Vector *param_2)

{
  if (*(float *)param_1 < *(float *)param_2) {
    return false;
  }
  if (*(float *)(param_2 + 4) <= *(float *)(param_1 + 4)) {
    return *(float *)(param_2 + 8) <= *(float *)(param_1 + 8);
  }
  return false;
}

// ===== AbyssEngine::AEMath::VectorIsEqual  @0x0007d37e  (68 bytes)
/* AbyssEngine::AEMath::VectorIsEqual(AbyssEngine::AEMath::Vector const&,
   AbyssEngine::AEMath::Vector const&) */

bool AbyssEngine::AEMath::VectorIsEqual(Vector *param_1,Vector *param_2)

{
  if (*(float *)param_1 != *(float *)param_2) {
    return false;
  }
  if (*(float *)(param_1 + 4) == *(float *)(param_2 + 4)) {
    return *(float *)(param_1 + 8) == *(float *)(param_2 + 8);
  }
  return false;
}

// ===== AbyssEngine::AEMath::VectorDot  @0x0007d3c2  (50 bytes)
/* AbyssEngine::AEMath::VectorDot(AbyssEngine::AEMath::Vector const&, AbyssEngine::AEMath::Vector
   const&) */

float AbyssEngine::AEMath::VectorDot(Vector *param_1,Vector *param_2)

{
  return *(float *)param_1 * *(float *)param_2 + *(float *)(param_1 + 4) * *(float *)(param_2 + 4) +
         *(float *)(param_1 + 8) * *(float *)(param_2 + 8);
}

// ===== AbyssEngine::AEMath::VectorCross  @0x0007d3f4  (74 bytes)
/* AbyssEngine::AEMath::VectorCross(AbyssEngine::AEMath::Vector const&, AbyssEngine::AEMath::Vector
   const&) */

void __thiscall AbyssEngine::AEMath::VectorCross(AEMath *this,Vector *param_1,Vector *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar1 = *(float *)param_2;
  fVar2 = *(float *)(param_2 + 4);
  fVar6 = *(float *)(param_1 + 8);
  fVar3 = *(float *)(param_2 + 8);
  fVar5 = *(float *)(param_1 + 4);
  fVar4 = *(float *)param_1;
  *(float *)this = fVar5 * fVar3 - fVar6 * fVar2;
  *(float *)(this + 4) = fVar6 * fVar1 - fVar3 * fVar4;
  *(float *)(this + 8) = fVar2 * fVar4 - fVar5 * fVar1;
  return;
}

// ===== AbyssEngine::AEMath::VectorNormalize  @0x0007d440  (128 bytes)
/* AbyssEngine::AEMath::VectorNormalize(AbyssEngine::AEMath::Vector const&) */

void __thiscall AbyssEngine::AEMath::VectorNormalize(AEMath *this,Vector *param_1)

{
  float extraout_r0;
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = SQRT(*(float *)param_1 * *(float *)param_1 +
               *(float *)(param_1 + 4) * *(float *)(param_1 + 4) +
               *(float *)(param_1 + 8) * *(float *)(param_1 + 8));
  if (NAN(fVar1)) {
    sqrtf(fVar1);
    fVar1 = extraout_r0;
  }
  if (fVar1 == 0.0) {
    fVar1 = 0.0;
    fVar2 = 1.0;
    fVar3 = fVar1;
  }
  else {
    fVar3 = *(float *)(param_1 + 8) / fVar1;
    fVar2 = *(float *)(param_1 + 4) / fVar1;
    fVar1 = *(float *)param_1 / fVar1;
  }
  *(float *)this = fVar1;
  *(float *)(this + 4) = fVar2;
  *(float *)(this + 8) = fVar3;
  return;
}

// ===== AbyssEngine::AEMath::VectorLength  @0x0007d4c4  (60 bytes)
/* AbyssEngine::AEMath::VectorLength(AbyssEngine::AEMath::Vector const&) */

float AbyssEngine::AEMath::VectorLength(Vector *param_1)

{
  float extraout_r0;
  float __x;
  float fVar1;
  
  __x = *(float *)param_1 * *(float *)param_1 + *(float *)(param_1 + 4) * *(float *)(param_1 + 4) +
        *(float *)(param_1 + 8) * *(float *)(param_1 + 8);
  fVar1 = SQRT(__x);
  if (NAN(fVar1)) {
    sqrtf(__x);
    return extraout_r0;
  }
  return fVar1;
}

// ===== AbyssEngine::AEMath::VectorLerp  @0x0007d500  (78 bytes)
/* AbyssEngine::AEMath::VectorLerp(AbyssEngine::AEMath::Vector const&, AbyssEngine::AEMath::Vector
   const&, float) */

void __thiscall
AbyssEngine::AEMath::VectorLerp(AEMath *this,Vector *param_1,Vector *param_2,float param_3)

{
  float in_r3;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = *(float *)(param_1 + 4);
  fVar3 = *(float *)(param_2 + 4);
  fVar2 = *(float *)(param_1 + 8);
  fVar4 = *(float *)(param_2 + 8);
  *(float *)this = *(float *)param_1 + (*(float *)param_2 - *(float *)param_1) * in_r3;
  *(float *)(this + 4) = fVar1 + (fVar3 - fVar1) * in_r3;
  *(float *)(this + 8) = fVar2 + (fVar4 - fVar2) * in_r3;
  return;
}

// ===== AbyssEngine::AEMath::operator*  @0x0008a94c  (476 bytes)
/* AbyssEngine::AEMath::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::Matrix const&,
   AbyssEngine::AEMath::Matrix const&) */

void __thiscall AbyssEngine::AEMath::operator*(AEMath *this,Matrix *param_1,Matrix *param_2)

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
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  AEMath aAStack_50 [12];
  int local_44;
  
  local_44 = __stack_chk_guard;
  fVar1 = *(float *)(param_1 + 0x24);
  fVar5 = *(float *)(param_2 + 0x14);
  fVar2 = *(float *)(param_2 + 0x10);
  fVar17 = *(float *)(param_1 + 0x14);
  fVar7 = *(float *)param_2;
  fVar20 = *(float *)(param_1 + 0x20);
  fVar10 = *(float *)(param_2 + 4);
  fVar8 = *(float *)(param_1 + 0x10);
  fVar12 = *(float *)(param_2 + 8);
  fVar13 = *(float *)(param_2 + 0x18);
  fVar15 = *(float *)(param_2 + 0xc);
  fVar22 = *(float *)(param_1 + 4);
  fVar18 = *(float *)param_1;
  fVar23 = *(float *)(param_1 + 8);
  fVar24 = *(float *)(param_1 + 0xc);
  fVar14 = *(float *)(param_2 + 0x1c);
  fVar19 = *(float *)(param_2 + 0x20);
  fVar21 = *(float *)(param_1 + 0x18);
  fVar3 = *(float *)(param_2 + 0x2c);
  fVar16 = *(float *)(param_1 + 0x28);
  fVar9 = *(float *)(param_2 + 0x28);
  fVar4 = *(float *)(param_2 + 0x24);
  fVar11 = *(float *)(param_1 + 0x1c);
  fVar6 = *(float *)(param_1 + 0x2c);
  *(float *)this = fVar18 * fVar7 + fVar22 * fVar2 + fVar23 * fVar19;
  *(float *)(this + 4) = fVar18 * fVar10 + fVar22 * fVar5 + fVar23 * fVar4;
  *(float *)(this + 8) = fVar18 * fVar12 + fVar22 * fVar13 + fVar23 * fVar9;
  *(float *)(this + 0xc) = fVar24 + fVar18 * fVar15 + fVar22 * fVar14 + fVar23 * fVar3;
  *(float *)(this + 0x10) = fVar7 * fVar8 + fVar2 * fVar17 + fVar19 * fVar21;
  *(float *)(this + 0x14) = fVar10 * fVar8 + fVar5 * fVar17 + fVar4 * fVar21;
  *(float *)(this + 0x18) = fVar12 * fVar8 + fVar13 * fVar17 + fVar9 * fVar21;
  *(float *)(this + 0x1c) = fVar11 + fVar15 * fVar8 + fVar14 * fVar17 + fVar3 * fVar21;
  *(float *)(this + 0x20) = fVar7 * fVar20 + fVar2 * fVar1 + fVar19 * fVar16;
  *(float *)(this + 0x24) = fVar10 * fVar20 + fVar5 * fVar1 + fVar4 * fVar16;
  *(float *)(this + 0x28) = fVar12 * fVar20 + fVar13 * fVar1 + fVar9 * fVar16;
  *(float *)(this + 0x2c) = fVar6 + fVar15 * fVar20 + fVar14 * fVar1 + fVar3 * fVar16;
  *(undefined4 *)(this + 0x30) = 0x3f800000;
  *(undefined4 *)(this + 0x34) = 0x3f800000;
  *(undefined4 *)(this + 0x38) = 0x3f800000;
  operator*(aAStack_50,(Vector *)(param_1 + 0x30),(Vector *)(param_2 + 0x30));
  Vector::operator=((Vector *)(this + 0x30),(Vector *)aAStack_50);
  if (__stack_chk_guard != local_44) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::AEMath::operator==  @0x0008ab30  (228 bytes)
/* AbyssEngine::AEMath::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::Matrix const&,
   AbyssEngine::AEMath::Matrix const&) */

bool AbyssEngine::AEMath::operator==(Matrix *param_1,Matrix *param_2)

{
  bool bVar1;
  
  if ((((((*(float *)param_1 == *(float *)param_2) &&
         (*(float *)(param_1 + 4) == *(float *)(param_2 + 4))) &&
        (*(float *)(param_1 + 8) == *(float *)(param_2 + 8))) &&
       ((*(float *)(param_1 + 0xc) == *(float *)(param_2 + 0xc) &&
        (*(float *)(param_1 + 0x10) == *(float *)(param_2 + 0x10))))) &&
      ((*(float *)(param_1 + 0x14) == *(float *)(param_2 + 0x14) &&
       ((*(float *)(param_1 + 0x18) == *(float *)(param_2 + 0x18) &&
        (*(float *)(param_1 + 0x1c) == *(float *)(param_2 + 0x1c))))))) &&
     ((*(float *)(param_1 + 0x20) == *(float *)(param_2 + 0x20) &&
      (*(float *)(param_1 + 0x24) == *(float *)(param_2 + 0x24))))) {
    bVar1 = false;
    if (*(float *)(param_1 + 0x28) == *(float *)(param_2 + 0x28)) {
      bVar1 = *(float *)(param_1 + 0x2c) == *(float *)(param_2 + 0x2c);
    }
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}

// ===== AbyssEngine::AEMath::operator!=  @0x0008ac14  (226 bytes)
/* AbyssEngine::AEMath::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::Matrix const&,
   AbyssEngine::AEMath::Matrix const&) */

bool AbyssEngine::AEMath::operator!=(Matrix *param_1,Matrix *param_2)

{
  if ((((((*(float *)param_1 == *(float *)param_2) &&
         (*(float *)(param_1 + 4) == *(float *)(param_2 + 4))) &&
        (*(float *)(param_1 + 8) == *(float *)(param_2 + 8))) &&
       ((*(float *)(param_1 + 0xc) == *(float *)(param_2 + 0xc) &&
        (*(float *)(param_1 + 0x10) == *(float *)(param_2 + 0x10))))) &&
      ((*(float *)(param_1 + 0x14) == *(float *)(param_2 + 0x14) &&
       ((*(float *)(param_1 + 0x18) == *(float *)(param_2 + 0x18) &&
        (*(float *)(param_1 + 0x1c) == *(float *)(param_2 + 0x1c))))))) &&
     ((*(float *)(param_1 + 0x20) == *(float *)(param_2 + 0x20) &&
      ((*(float *)(param_1 + 0x24) == *(float *)(param_2 + 0x24) &&
       (*(float *)(param_1 + 0x28) == *(float *)(param_2 + 0x28))))))) {
    return *(float *)(param_1 + 0x2c) != *(float *)(param_2 + 0x2c);
  }
  return true;
}

// ===== AbyssEngine::AEMath::operator*  @0x0008acf6  (146 bytes)
/* AbyssEngine::AEMath::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::Matrix const&,
   AbyssEngine::AEMath::Vector const&) */

void __thiscall AbyssEngine::AEMath::operator*(AEMath *this,Matrix *param_1,Vector *param_2)

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
  
  fVar6 = *(float *)param_2;
  fVar8 = *(float *)(param_2 + 4);
  fVar11 = *(float *)(param_1 + 0x14);
  fVar1 = *(float *)(param_1 + 0x10);
  fVar3 = *(float *)(param_1 + 0x24);
  fVar5 = *(float *)(param_1 + 0x20);
  fVar10 = *(float *)(param_2 + 8);
  fVar4 = *(float *)(param_1 + 0x18);
  fVar2 = *(float *)(param_1 + 0x28);
  fVar9 = *(float *)(param_1 + 0x2c);
  fVar7 = *(float *)(param_1 + 0x1c);
  *(float *)this =
       *(float *)(param_1 + 0xc) +
       fVar6 * *(float *)param_1 + fVar8 * *(float *)(param_1 + 4) +
       fVar10 * *(float *)(param_1 + 8);
  *(float *)(this + 4) = fVar7 + fVar6 * fVar1 + fVar8 * fVar11 + fVar10 * fVar4;
  *(float *)(this + 8) = fVar9 + fVar6 * fVar5 + fVar8 * fVar3 + fVar10 * fVar2;
  return;
}

// ===== AbyssEngine::AEMath::MatrixMultiply  @0x0008ad88  (10 bytes)
/* AbyssEngine::AEMath::MatrixMultiply(AbyssEngine::AEMath::Matrix const&,
   AbyssEngine::AEMath::Matrix const&) */

void __thiscall AbyssEngine::AEMath::MatrixMultiply(AEMath *this,Matrix *param_1,Matrix *param_2)

{
  operator*(this,param_1,param_2);
  return;
}

// ===== AbyssEngine::AEMath::MatrixIdentity  @0x0008ad94  (104 bytes)
/* AbyssEngine::AEMath::MatrixIdentity(AbyssEngine::AEMath::Matrix&) */

void __thiscall AbyssEngine::AEMath::MatrixIdentity(AEMath *this,Matrix *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  int local_18;
  
  local_18 = __stack_chk_guard;
  *(undefined4 *)param_1 = 0x3f800000;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(param_1 + 0x14) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(param_1 + 0x28) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  local_24 = 0x3f800000;
  uStack_20 = 0x3f800000;
  local_1c = 0x3f800000;
  Vector::operator=((Vector *)(param_1 + 0x30),(Vector *)&local_24);
  uVar1 = *(undefined4 *)(param_1 + 4);
  uVar2 = *(undefined4 *)(param_1 + 8);
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  uVar4 = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = uVar1;
  *(undefined4 *)(this + 8) = uVar2;
  *(undefined4 *)(this + 0xc) = uVar3;
  *(undefined4 *)(this + 0x10) = uVar4;
  uVar1 = *(undefined4 *)(param_1 + 0x18);
  uVar2 = *(undefined4 *)(param_1 + 0x1c);
  uVar3 = *(undefined4 *)(param_1 + 0x20);
  uVar4 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = uVar1;
  *(undefined4 *)(this + 0x1c) = uVar2;
  *(undefined4 *)(this + 0x20) = uVar3;
  *(undefined4 *)(this + 0x24) = uVar4;
  uVar1 = *(undefined4 *)(param_1 + 0x2c);
  uVar2 = *(undefined4 *)(param_1 + 0x30);
  uVar3 = *(undefined4 *)(param_1 + 0x34);
  uVar4 = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = uVar1;
  *(undefined4 *)(this + 0x30) = uVar2;
  *(undefined4 *)(this + 0x34) = uVar3;
  *(undefined4 *)(this + 0x38) = uVar4;
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::AEMath::MatrixIsEqual  @0x0008ae04  (4 bytes)
/* AbyssEngine::AEMath::MatrixIsEqual(AbyssEngine::AEMath::Matrix const&,
   AbyssEngine::AEMath::Matrix const&) */

void AbyssEngine::AEMath::MatrixIsEqual(Matrix *param_1,Matrix *param_2)

{
  operator==(param_1,param_2);
  return;
}

// ===== AbyssEngine::AEMath::MatrixGetRight  @0x0008ae08  (14 bytes)
/* AbyssEngine::AEMath::MatrixGetRight(AbyssEngine::AEMath::Matrix const&) */

void __thiscall AbyssEngine::AEMath::MatrixGetRight(AEMath *this,Matrix *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 0x10);
  uVar1 = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = uVar2;
  *(undefined4 *)(this + 8) = uVar1;
  return;
}

// ===== AbyssEngine::AEMath::MatrixGetUp  @0x0008ae16  (14 bytes)
/* AbyssEngine::AEMath::MatrixGetUp(AbyssEngine::AEMath::Matrix const&) */

void __thiscall AbyssEngine::AEMath::MatrixGetUp(AEMath *this,Matrix *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 0x14);
  uVar1 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)this = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 4) = uVar2;
  *(undefined4 *)(this + 8) = uVar1;
  return;
}

// ===== AbyssEngine::AEMath::MatrixGetDir  @0x0008ae24  (14 bytes)
/* AbyssEngine::AEMath::MatrixGetDir(AbyssEngine::AEMath::Matrix const&) */

void __thiscall AbyssEngine::AEMath::MatrixGetDir(AEMath *this,Matrix *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 0x18);
  uVar1 = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)this = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 4) = uVar2;
  *(undefined4 *)(this + 8) = uVar1;
  return;
}

// ===== AbyssEngine::AEMath::MatrixGetPosition  @0x0008ae32  (14 bytes)
/* AbyssEngine::AEMath::MatrixGetPosition(AbyssEngine::AEMath::Matrix const&) */

void __thiscall AbyssEngine::AEMath::MatrixGetPosition(AEMath *this,Matrix *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 0x1c);
  uVar1 = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)this = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 4) = uVar2;
  *(undefined4 *)(this + 8) = uVar1;
  return;
}

// ===== AbyssEngine::AEMath::MatrixTransformVector  @0x0008ae40  (146 bytes)
/* AbyssEngine::AEMath::MatrixTransformVector(AbyssEngine::AEMath::Matrix const&,
   AbyssEngine::AEMath::Vector const&) */

void __thiscall
AbyssEngine::AEMath::MatrixTransformVector(AEMath *this,Matrix *param_1,Vector *param_2)

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
  
  fVar6 = *(float *)param_2;
  fVar8 = *(float *)(param_2 + 4);
  fVar11 = *(float *)(param_1 + 0x14);
  fVar1 = *(float *)(param_1 + 0x10);
  fVar3 = *(float *)(param_1 + 0x24);
  fVar5 = *(float *)(param_1 + 0x20);
  fVar10 = *(float *)(param_2 + 8);
  fVar4 = *(float *)(param_1 + 0x18);
  fVar2 = *(float *)(param_1 + 0x28);
  fVar9 = *(float *)(param_1 + 0x2c);
  fVar7 = *(float *)(param_1 + 0x1c);
  *(float *)this =
       *(float *)(param_1 + 0xc) +
       fVar6 * *(float *)param_1 + fVar8 * *(float *)(param_1 + 4) +
       fVar10 * *(float *)(param_1 + 8);
  *(float *)(this + 4) = fVar7 + fVar6 * fVar1 + fVar8 * fVar11 + fVar10 * fVar4;
  *(float *)(this + 8) = fVar9 + fVar6 * fVar5 + fVar8 * fVar3 + fVar10 * fVar2;
  return;
}

// ===== AbyssEngine::AEMath::MatrixRotateVector  @0x0008aed2  (122 bytes)
/* AbyssEngine::AEMath::MatrixRotateVector(AbyssEngine::AEMath::Matrix const&,
   AbyssEngine::AEMath::Vector const&) */

void __thiscall
AbyssEngine::AEMath::MatrixRotateVector(AEMath *this,Matrix *param_1,Vector *param_2)

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
  
  fVar7 = *(float *)(param_2 + 4);
  fVar9 = *(float *)(param_1 + 0x14);
  fVar6 = *(float *)param_2;
  fVar5 = *(float *)(param_1 + 0x10);
  fVar3 = *(float *)(param_1 + 0x24);
  fVar1 = *(float *)(param_1 + 0x20);
  fVar8 = *(float *)(param_2 + 8);
  fVar4 = *(float *)(param_1 + 0x28);
  fVar2 = *(float *)(param_1 + 0x18);
  *(float *)this =
       fVar6 * *(float *)param_1 + fVar7 * *(float *)(param_1 + 4) + fVar8 * *(float *)(param_1 + 8)
  ;
  *(float *)(this + 4) = fVar6 * fVar5 + fVar7 * fVar9 + fVar8 * fVar2;
  *(float *)(this + 8) = fVar6 * fVar1 + fVar7 * fVar3 + fVar8 * fVar4;
  return;
}

// ===== AbyssEngine::AEMath::MatrixInverseTransformVector  @0x0008af4c  (214 bytes)
/* AbyssEngine::AEMath::MatrixInverseTransformVector(AbyssEngine::AEMath::Matrix const&,
   AbyssEngine::AEMath::Vector const&) */

void __thiscall
AbyssEngine::AEMath::MatrixInverseTransformVector(AEMath *this,Matrix *param_1,Vector *param_2)

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
  
  fVar1 = *(float *)param_2;
  fVar7 = *(float *)(param_1 + 4);
  fVar3 = *(float *)(param_2 + 4);
  fVar9 = *(float *)(param_1 + 0xc);
  fVar8 = *(float *)(param_1 + 8);
  fVar2 = *(float *)(param_1 + 0x14);
  fVar6 = *(float *)(param_1 + 0x1c);
  fVar4 = *(float *)(param_1 + 0x18);
  fVar5 = *(float *)(param_2 + 8);
  fVar10 = *(float *)(param_1 + 0x24);
  fVar11 = *(float *)(param_1 + 0x28);
  fVar12 = *(float *)(param_1 + 0x2c);
  *(float *)this =
       fVar1 * *(float *)param_1 + fVar3 * *(float *)(param_1 + 0x10) +
       fVar5 * *(float *)(param_1 + 0x20) +
       ((-(*(float *)param_1 * fVar9) - *(float *)(param_1 + 0x10) * fVar6) -
       *(float *)(param_1 + 0x20) * fVar12);
  *(float *)(this + 4) =
       fVar1 * fVar7 + fVar3 * fVar2 + fVar5 * fVar10 +
       ((-(fVar9 * fVar7) - fVar6 * fVar2) - fVar12 * fVar10);
  *(float *)(this + 8) =
       fVar1 * fVar8 + fVar3 * fVar4 + fVar5 * fVar11 +
       ((-(fVar9 * fVar8) - fVar6 * fVar4) - fVar12 * fVar11);
  return;
}

// ===== AbyssEngine::AEMath::MatrixInverseRotateVector  @0x0008b022  (122 bytes)
/* AbyssEngine::AEMath::MatrixInverseRotateVector(AbyssEngine::AEMath::Matrix const&,
   AbyssEngine::AEMath::Vector const&) */

void __thiscall
AbyssEngine::AEMath::MatrixInverseRotateVector(AEMath *this,Matrix *param_1,Vector *param_2)

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
  
  fVar1 = *(float *)(param_1 + 4);
  fVar8 = *(float *)param_2;
  fVar3 = *(float *)(param_1 + 8);
  fVar6 = *(float *)(param_1 + 0x14);
  fVar9 = *(float *)(param_2 + 4);
  fVar7 = *(float *)(param_1 + 0x18);
  fVar2 = *(float *)(param_2 + 8);
  fVar4 = *(float *)(param_1 + 0x24);
  fVar5 = *(float *)(param_1 + 0x28);
  *(float *)this =
       fVar8 * *(float *)param_1 + fVar9 * *(float *)(param_1 + 0x10) +
       fVar2 * *(float *)(param_1 + 0x20);
  *(float *)(this + 4) = fVar8 * fVar1 + fVar9 * fVar6 + fVar2 * fVar4;
  *(float *)(this + 8) = fVar8 * fVar3 + fVar9 * fVar7 + fVar2 * fVar5;
  return;
}

// ===== AbyssEngine::AEMath::MatrixSetRotation  @0x0008b09c  (224 bytes)
/* AbyssEngine::AEMath::MatrixSetRotation(AbyssEngine::AEMath::Matrix&, float, float, float) */

void AbyssEngine::AEMath::MatrixSetRotation
               (Matrix *param_1,float param_2,float param_3,float param_4)

{
  float extraout_r0;
  float extraout_r0_00;
  float extraout_r0_01;
  float extraout_r0_02;
  float extraout_r0_03;
  float extraout_r0_04;
  float *in_r1;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar4 = sinf(param_2);
  fVar4 = sinf(fVar4);
  fVar4 = sinf(fVar4);
  fVar4 = cosf(fVar4);
  fVar4 = cosf(fVar4);
  cosf(fVar4);
  *in_r1 = extraout_r0_03 * extraout_r0_04;
  in_r1[1] = -(extraout_r0_01 * extraout_r0_03);
  in_r1[2] = extraout_r0_00;
  in_r1[4] = extraout_r0_01 * extraout_r0_02 + extraout_r0_00 * extraout_r0 * extraout_r0_04;
  in_r1[5] = extraout_r0_02 * extraout_r0_04 - extraout_r0 * extraout_r0_00 * extraout_r0_01;
  in_r1[6] = -(extraout_r0 * extraout_r0_03);
  in_r1[8] = extraout_r0 * extraout_r0_01 - extraout_r0_00 * extraout_r0_02 * extraout_r0_04;
  in_r1[9] = extraout_r0_01 * extraout_r0_00 * extraout_r0_02 + extraout_r0 * extraout_r0_04;
  in_r1[10] = extraout_r0_02 * extraout_r0_03;
  fVar4 = in_r1[1];
  fVar1 = in_r1[2];
  fVar2 = in_r1[3];
  fVar3 = in_r1[4];
  *(float *)param_1 = *in_r1;
  *(float *)(param_1 + 4) = fVar4;
  *(float *)(param_1 + 8) = fVar1;
  *(float *)(param_1 + 0xc) = fVar2;
  *(float *)(param_1 + 0x10) = fVar3;
  fVar4 = in_r1[6];
  fVar1 = in_r1[7];
  fVar2 = in_r1[8];
  fVar3 = in_r1[9];
  *(float *)(param_1 + 0x14) = in_r1[5];
  *(float *)(param_1 + 0x18) = fVar4;
  *(float *)(param_1 + 0x1c) = fVar1;
  *(float *)(param_1 + 0x20) = fVar2;
  *(float *)(param_1 + 0x24) = fVar3;
  fVar4 = in_r1[0xb];
  fVar1 = in_r1[0xc];
  fVar2 = in_r1[0xd];
  fVar3 = in_r1[0xe];
  *(float *)(param_1 + 0x28) = in_r1[10];
  *(float *)(param_1 + 0x2c) = fVar4;
  *(float *)(param_1 + 0x30) = fVar1;
  *(float *)(param_1 + 0x34) = fVar2;
  *(float *)(param_1 + 0x38) = fVar3;
  return;
}

// ===== AbyssEngine::AEMath::MatrixSetRotation  @0x0008b17c  (746 bytes)
/* AbyssEngine::AEMath::MatrixSetRotation(AbyssEngine::AEMath::Matrix&, float, float, float,
   AbyssEngine::AEMath::RotationOrder) */

void AbyssEngine::AEMath::MatrixSetRotation(float param_2,float *param_1,float *param_3)

{
  float extraout_r0;
  float extraout_r0_00;
  float extraout_r0_01;
  float extraout_r0_02;
  float extraout_r0_03;
  float extraout_r0_04;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 in_stack_00000004;
  
  fVar4 = sinf(param_2);
  fVar4 = sinf(fVar4);
  fVar4 = sinf(fVar4);
  fVar4 = cosf(fVar4);
  fVar4 = cosf(fVar4);
  cosf(fVar4);
  switch(in_stack_00000004) {
  case 0:
    fVar4 = extraout_r0 * extraout_r0_03;
    *param_3 = extraout_r0_03 * extraout_r0_04;
    fVar2 = extraout_r0_01 * extraout_r0_00 * extraout_r0_02 + extraout_r0 * extraout_r0_04;
    fVar1 = extraout_r0 * extraout_r0_01 - extraout_r0_00 * extraout_r0_02 * extraout_r0_04;
    param_3[1] = -(extraout_r0_01 * extraout_r0_03);
    param_3[2] = extraout_r0_00;
    param_3[4] = extraout_r0_01 * extraout_r0_02 + extraout_r0_00 * extraout_r0 * extraout_r0_04;
    param_3[5] = extraout_r0_02 * extraout_r0_04 - extraout_r0 * extraout_r0_00 * extraout_r0_01;
    break;
  case 1:
    *param_3 = extraout_r0_03 * extraout_r0_04;
    param_3[1] = -extraout_r0_01;
    param_3[2] = extraout_r0_00 * extraout_r0_04;
    fVar4 = extraout_r0 * extraout_r0_00 * extraout_r0_01 + extraout_r0_02 * extraout_r0_03;
    param_3[4] = extraout_r0 * extraout_r0_00 + extraout_r0_01 * extraout_r0_02 * extraout_r0_03;
    param_3[5] = extraout_r0_02 * extraout_r0_04;
    param_3[6] = extraout_r0_01 * extraout_r0_00 * extraout_r0_02 - extraout_r0 * extraout_r0_03;
    param_3[8] = extraout_r0_01 * extraout_r0 * extraout_r0_03 - extraout_r0_00 * extraout_r0_02;
    param_3[9] = extraout_r0 * extraout_r0_04;
    goto LAB_0008b38c;
  case 2:
    fVar1 = extraout_r0_01 * extraout_r0 * extraout_r0_03 - extraout_r0_00 * extraout_r0_04;
    fVar2 = extraout_r0_00 * extraout_r0_01 + extraout_r0 * extraout_r0_03 * extraout_r0_04;
    *param_3 = extraout_r0 * extraout_r0_00 * extraout_r0_01 + extraout_r0_03 * extraout_r0_04;
    param_3[1] = extraout_r0_00 * extraout_r0 * extraout_r0_04 - extraout_r0_01 * extraout_r0_03;
    param_3[2] = extraout_r0_00 * extraout_r0_02;
    param_3[4] = extraout_r0_01 * extraout_r0_02;
    param_3[5] = extraout_r0_02 * extraout_r0_04;
    fVar4 = extraout_r0;
    break;
  case 3:
    *param_3 = extraout_r0_03 * extraout_r0_04;
    fVar4 = extraout_r0_02 * extraout_r0_03 - extraout_r0 * extraout_r0_00 * extraout_r0_01;
    param_3[1] = extraout_r0 * extraout_r0_00 - extraout_r0_02 * extraout_r0_01 * extraout_r0_03;
    param_3[2] = extraout_r0_00 * extraout_r0_02 + extraout_r0 * extraout_r0_01 * extraout_r0_03;
    param_3[4] = extraout_r0_01;
    param_3[5] = extraout_r0_02 * extraout_r0_04;
    param_3[6] = -(extraout_r0 * extraout_r0_04);
    param_3[8] = -(extraout_r0_00 * extraout_r0_04);
    param_3[9] = extraout_r0_02 * extraout_r0_00 * extraout_r0_01 + extraout_r0 * extraout_r0_03;
LAB_0008b38c:
    param_3[10] = fVar4;
    goto switchD_0008b1de_default;
  case 4:
    fVar4 = extraout_r0_00 * extraout_r0_02;
    fVar2 = extraout_r0_00 * extraout_r0_01 - extraout_r0 * extraout_r0_03 * extraout_r0_04;
    *param_3 = extraout_r0_03 * extraout_r0_04 - extraout_r0 * extraout_r0_00 * extraout_r0_01;
    param_3[1] = -(extraout_r0_01 * extraout_r0_02);
    param_3[2] = extraout_r0 * extraout_r0_01 * extraout_r0_03 + extraout_r0_00 * extraout_r0_04;
    param_3[4] = extraout_r0_01 * extraout_r0_03 + extraout_r0_00 * extraout_r0 * extraout_r0_04;
    param_3[5] = extraout_r0_02 * extraout_r0_04;
    fVar1 = extraout_r0;
    goto LAB_0008b44c;
  case 5:
    *param_3 = extraout_r0_03 * extraout_r0_04;
    fVar1 = extraout_r0 * extraout_r0_03;
    fVar2 = extraout_r0_02 * extraout_r0_00 * extraout_r0_01 - extraout_r0 * extraout_r0_04;
    param_3[1] = extraout_r0_00 * extraout_r0 * extraout_r0_04 - extraout_r0_01 * extraout_r0_02;
    param_3[2] = extraout_r0 * extraout_r0_01 + extraout_r0_00 * extraout_r0_02 * extraout_r0_04;
    param_3[4] = extraout_r0_01 * extraout_r0_03;
    param_3[5] = extraout_r0 * extraout_r0_00 * extraout_r0_01 + extraout_r0_02 * extraout_r0_04;
    fVar4 = extraout_r0_00;
LAB_0008b44c:
    param_3[6] = fVar2;
    param_3[8] = -fVar4;
    param_3[9] = fVar1;
    goto LAB_0008b458;
  default:
    goto switchD_0008b1de_default;
  }
  param_3[6] = -fVar4;
  param_3[8] = fVar1;
  param_3[9] = fVar2;
LAB_0008b458:
  param_3[10] = extraout_r0_02 * extraout_r0_03;
switchD_0008b1de_default:
  fVar4 = param_3[1];
  fVar1 = param_3[2];
  fVar2 = param_3[3];
  fVar3 = param_3[4];
  *param_1 = *param_3;
  param_1[1] = fVar4;
  param_1[2] = fVar1;
  param_1[3] = fVar2;
  param_1[4] = fVar3;
  fVar4 = param_3[6];
  fVar1 = param_3[7];
  fVar2 = param_3[8];
  fVar3 = param_3[9];
  param_1[5] = param_3[5];
  param_1[6] = fVar4;
  param_1[7] = fVar1;
  param_1[8] = fVar2;
  param_1[9] = fVar3;
  fVar4 = param_3[0xb];
  fVar1 = param_3[0xc];
  fVar2 = param_3[0xd];
  fVar3 = param_3[0xe];
  param_1[10] = param_3[10];
  param_1[0xb] = fVar4;
  param_1[0xc] = fVar1;
  param_1[0xd] = fVar2;
  param_1[0xe] = fVar3;
  return;
}

// ===== AbyssEngine::AEMath::MatrixSetRotation  @0x0008b474  (156 bytes)
/* AbyssEngine::AEMath::MatrixSetRotation(AbyssEngine::AEMath::Matrix&, AbyssEngine::AEMath::Vector
   const&) */

void __thiscall AbyssEngine::AEMath::MatrixSetRotation(AEMath *this,Matrix *param_1,Vector *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  
  local_20 = __stack_chk_guard;
  local_44 = 0;
  local_40 = 0x3f800000;
  uStack_3c = 0;
  VectorCross((AEMath *)&local_38,(Vector *)&local_44,param_2);
  VectorNormalize((AEMath *)&local_2c,(Vector *)&local_38);
  VectorCross((AEMath *)&local_44,param_2,(Vector *)&local_2c);
  VectorNormalize((AEMath *)&local_38,(Vector *)&local_44);
  *(undefined4 *)param_1 = local_2c;
  *(undefined4 *)(param_1 + 0x10) = local_28;
  *(undefined4 *)(param_1 + 0x20) = local_24;
  *(undefined4 *)(param_1 + 4) = local_38;
  *(undefined4 *)(param_1 + 0x14) = local_34;
  *(undefined4 *)(param_1 + 0x24) = local_30;
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)param_2;
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_2 + 8);
  uVar1 = *(undefined4 *)(param_1 + 4);
  uVar2 = *(undefined4 *)(param_1 + 8);
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  uVar4 = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = uVar1;
  *(undefined4 *)(this + 8) = uVar2;
  *(undefined4 *)(this + 0xc) = uVar3;
  *(undefined4 *)(this + 0x10) = uVar4;
  uVar1 = *(undefined4 *)(param_1 + 0x18);
  uVar2 = *(undefined4 *)(param_1 + 0x1c);
  uVar3 = *(undefined4 *)(param_1 + 0x20);
  uVar4 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = uVar1;
  *(undefined4 *)(this + 0x1c) = uVar2;
  *(undefined4 *)(this + 0x20) = uVar3;
  *(undefined4 *)(this + 0x24) = uVar4;
  uVar1 = *(undefined4 *)(param_1 + 0x2c);
  uVar2 = *(undefined4 *)(param_1 + 0x30);
  uVar3 = *(undefined4 *)(param_1 + 0x34);
  uVar4 = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = uVar1;
  *(undefined4 *)(this + 0x30) = uVar2;
  *(undefined4 *)(this + 0x34) = uVar3;
  *(undefined4 *)(this + 0x38) = uVar4;
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::AEMath::MatrixSetRotation  @0x0008b518  (82 bytes)
/* AbyssEngine::AEMath::MatrixSetRotation(AbyssEngine::AEMath::Matrix&, AbyssEngine::AEMath::Vector
   const&, AbyssEngine::AEMath::Vector const&, AbyssEngine::AEMath::Vector const&) */

void __thiscall
AbyssEngine::AEMath::MatrixSetRotation
          (AEMath *this,Matrix *param_1,Vector *param_2,Vector *param_3,Vector *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  *(undefined4 *)param_1 = *(undefined4 *)param_2;
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)param_3;
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_3 + 4);
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_3 + 8);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)param_4;
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_4 + 4);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_4 + 8);
  uVar1 = *(undefined4 *)(param_1 + 4);
  uVar2 = *(undefined4 *)(param_1 + 8);
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  uVar4 = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = uVar1;
  *(undefined4 *)(this + 8) = uVar2;
  *(undefined4 *)(this + 0xc) = uVar3;
  *(undefined4 *)(this + 0x10) = uVar4;
  uVar1 = *(undefined4 *)(param_1 + 0x18);
  uVar2 = *(undefined4 *)(param_1 + 0x1c);
  uVar3 = *(undefined4 *)(param_1 + 0x20);
  uVar4 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = uVar1;
  *(undefined4 *)(this + 0x1c) = uVar2;
  *(undefined4 *)(this + 0x20) = uVar3;
  *(undefined4 *)(this + 0x24) = uVar4;
  uVar1 = *(undefined4 *)(param_1 + 0x2c);
  uVar2 = *(undefined4 *)(param_1 + 0x30);
  uVar3 = *(undefined4 *)(param_1 + 0x34);
  uVar4 = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = uVar1;
  *(undefined4 *)(this + 0x30) = uVar2;
  *(undefined4 *)(this + 0x34) = uVar3;
  *(undefined4 *)(this + 0x38) = uVar4;
  return;
}

// ===== AbyssEngine::AEMath::MatrixSetScaling  @0x0008b56c  (194 bytes)
/* AbyssEngine::AEMath::MatrixSetScaling(AbyssEngine::AEMath::Matrix&, float, float, float) */

void __thiscall
AbyssEngine::AEMath::MatrixSetScaling
          (AEMath *this,Matrix *param_1,float param_2,float param_3,float param_4)

{
  undefined4 uVar1;
  float in_r2;
  undefined4 uVar2;
  float in_r3;
  undefined4 uVar3;
  undefined4 uVar4;
  float in_stack_00000000;
  Vector local_24 [12];
  int local_18;
  
  local_18 = __stack_chk_guard;
  *(float *)param_1 = *(float *)param_1 * in_r2;
  *(float *)(param_1 + 0x10) = *(float *)(param_1 + 0x10) * in_r2;
  *(float *)(param_1 + 0x20) = *(float *)(param_1 + 0x20) * in_r2;
  *(float *)(param_1 + 4) = *(float *)(param_1 + 4) * in_r3;
  *(float *)(param_1 + 0x14) = *(float *)(param_1 + 0x14) * in_r3;
  *(float *)(param_1 + 0x24) = *(float *)(param_1 + 0x24) * in_r3;
  *(float *)(param_1 + 8) = *(float *)(param_1 + 8) * in_stack_00000000;
  *(float *)(param_1 + 0x18) = *(float *)(param_1 + 0x18) * in_stack_00000000;
  *(float *)(param_1 + 0x28) = *(float *)(param_1 + 0x28) * in_stack_00000000;
  Vector::operator=((Vector *)(param_1 + 0x30),local_24);
  uVar1 = *(undefined4 *)(param_1 + 4);
  uVar2 = *(undefined4 *)(param_1 + 8);
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  uVar4 = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = uVar1;
  *(undefined4 *)(this + 8) = uVar2;
  *(undefined4 *)(this + 0xc) = uVar3;
  *(undefined4 *)(this + 0x10) = uVar4;
  uVar1 = *(undefined4 *)(param_1 + 0x18);
  uVar2 = *(undefined4 *)(param_1 + 0x1c);
  uVar3 = *(undefined4 *)(param_1 + 0x20);
  uVar4 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = uVar1;
  *(undefined4 *)(this + 0x1c) = uVar2;
  *(undefined4 *)(this + 0x20) = uVar3;
  *(undefined4 *)(this + 0x24) = uVar4;
  uVar1 = *(undefined4 *)(param_1 + 0x2c);
  uVar2 = *(undefined4 *)(param_1 + 0x30);
  uVar3 = *(undefined4 *)(param_1 + 0x34);
  uVar4 = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = uVar1;
  *(undefined4 *)(this + 0x30) = uVar2;
  *(undefined4 *)(this + 0x34) = uVar3;
  *(undefined4 *)(this + 0x38) = uVar4;
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::AEMath::MatrixSetTranslation  @0x0008b638  (40 bytes)
/* AbyssEngine::AEMath::MatrixSetTranslation(AbyssEngine::AEMath::Matrix&, float, float, float) */

void __thiscall
AbyssEngine::AEMath::MatrixSetTranslation
          (AEMath *this,Matrix *param_1,float param_2,float param_3,float param_4)

{
  undefined4 in_r2;
  undefined4 in_r3;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 in_stack_00000000;
  
  *(undefined4 *)(param_1 + 0xc) = in_r2;
  *(undefined4 *)(param_1 + 0x1c) = in_r3;
  *(undefined4 *)(param_1 + 0x2c) = in_stack_00000000;
  uVar1 = *(undefined4 *)(param_1 + 4);
  uVar2 = *(undefined4 *)(param_1 + 8);
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  uVar4 = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = uVar1;
  *(undefined4 *)(this + 8) = uVar2;
  *(undefined4 *)(this + 0xc) = uVar3;
  *(undefined4 *)(this + 0x10) = uVar4;
  uVar1 = *(undefined4 *)(param_1 + 0x18);
  uVar2 = *(undefined4 *)(param_1 + 0x1c);
  uVar3 = *(undefined4 *)(param_1 + 0x20);
  uVar4 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = uVar1;
  *(undefined4 *)(this + 0x1c) = uVar2;
  *(undefined4 *)(this + 0x20) = uVar3;
  *(undefined4 *)(this + 0x24) = uVar4;
  uVar1 = *(undefined4 *)(param_1 + 0x2c);
  uVar2 = *(undefined4 *)(param_1 + 0x30);
  uVar3 = *(undefined4 *)(param_1 + 0x34);
  uVar4 = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = uVar1;
  *(undefined4 *)(this + 0x30) = uVar2;
  *(undefined4 *)(this + 0x34) = uVar3;
  *(undefined4 *)(this + 0x38) = uVar4;
  return;
}

// ===== AbyssEngine::AEMath::MatrixSetTranslation  @0x0008b660  (40 bytes)
/* AbyssEngine::AEMath::MatrixSetTranslation(AbyssEngine::AEMath::Matrix&,
   AbyssEngine::AEMath::Vector const&) */

void __thiscall
AbyssEngine::AEMath::MatrixSetTranslation(AEMath *this,Matrix *param_1,Vector *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)param_2;
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_2 + 8);
  uVar1 = *(undefined4 *)(param_1 + 4);
  uVar2 = *(undefined4 *)(param_1 + 8);
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  uVar4 = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = uVar1;
  *(undefined4 *)(this + 8) = uVar2;
  *(undefined4 *)(this + 0xc) = uVar3;
  *(undefined4 *)(this + 0x10) = uVar4;
  uVar1 = *(undefined4 *)(param_1 + 0x18);
  uVar2 = *(undefined4 *)(param_1 + 0x1c);
  uVar3 = *(undefined4 *)(param_1 + 0x20);
  uVar4 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = uVar1;
  *(undefined4 *)(this + 0x1c) = uVar2;
  *(undefined4 *)(this + 0x20) = uVar3;
  *(undefined4 *)(this + 0x24) = uVar4;
  uVar1 = *(undefined4 *)(param_1 + 0x2c);
  uVar2 = *(undefined4 *)(param_1 + 0x30);
  uVar3 = *(undefined4 *)(param_1 + 0x34);
  uVar4 = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = uVar1;
  *(undefined4 *)(this + 0x30) = uVar2;
  *(undefined4 *)(this + 0x34) = uVar3;
  *(undefined4 *)(this + 0x38) = uVar4;
  return;
}

// ===== AbyssEngine::AEMath::MatrixGetInverse  @0x0008b688  (178 bytes)
/* AbyssEngine::AEMath::MatrixGetInverse(AbyssEngine::AEMath::Matrix const&) */

void __thiscall AbyssEngine::AEMath::MatrixGetInverse(AEMath *this,Matrix *param_1)

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
  
  *(undefined4 *)(this + 0x30) = 0x3f800000;
  *(undefined4 *)(this + 0x34) = 0x3f800000;
  *(undefined4 *)(this + 0x38) = 0x3f800000;
  fVar1 = *(float *)param_1;
  *(float *)this = fVar1;
  fVar3 = *(float *)(param_1 + 0x10);
  *(float *)(this + 4) = fVar3;
  fVar8 = *(float *)(param_1 + 0x20);
  *(float *)(this + 8) = fVar8;
  fVar9 = *(float *)(param_1 + 4);
  *(float *)(this + 0x10) = fVar9;
  fVar5 = *(float *)(param_1 + 0x14);
  *(float *)(this + 0x14) = fVar5;
  fVar6 = *(float *)(param_1 + 0x24);
  *(float *)(this + 0x18) = fVar6;
  fVar7 = *(float *)(param_1 + 8);
  *(float *)(this + 0x20) = fVar7;
  fVar2 = *(float *)(param_1 + 0x18);
  *(float *)(this + 0x24) = fVar2;
  fVar4 = *(float *)(param_1 + 0x28);
  *(float *)(this + 0x28) = fVar4;
  fVar10 = *(float *)(param_1 + 0xc);
  fVar11 = *(float *)(param_1 + 0x1c);
  fVar12 = *(float *)(param_1 + 0x2c);
  *(float *)(this + 0xc) = (-(fVar1 * fVar10) - fVar3 * fVar11) - fVar8 * fVar12;
  *(float *)(this + 0x1c) = (-(fVar9 * fVar10) - fVar5 * fVar11) - fVar6 * fVar12;
  *(float *)(this + 0x2c) = (-(fVar7 * fVar10) - fVar2 * fVar11) - fVar4 * fVar12;
  return;
}

// ===== AbyssEngine::AEMath::MatrixGetLookAt  @0x0008b73c  (160 bytes)
/* AbyssEngine::AEMath::MatrixGetLookAt(AbyssEngine::AEMath::Vector const&,
   AbyssEngine::AEMath::Vector const&, AbyssEngine::AEMath::Vector const&) */

void __thiscall
AbyssEngine::AEMath::MatrixGetLookAt(AEMath *this,Vector *param_1,Vector *param_2,Vector *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  operator-((AEMath *)&uStack_40,param_1,param_2);
  VectorNormalize((AEMath *)&local_34,(Vector *)&uStack_40);
  VectorCross((AEMath *)&local_4c,param_3,(Vector *)&local_34);
  VectorNormalize((AEMath *)&uStack_40,(Vector *)&local_4c);
  VectorCross((AEMath *)&local_4c,(Vector *)&local_34,(Vector *)&uStack_40);
  uVar1 = *(undefined4 *)param_1;
  uVar3 = *(undefined4 *)(param_1 + 4);
  uVar2 = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)this = uStack_40;
  *(undefined4 *)(this + 4) = local_4c;
  *(undefined4 *)(this + 8) = local_34;
  *(undefined4 *)(this + 0xc) = uVar1;
  *(undefined4 *)(this + 0x10) = local_3c;
  *(undefined4 *)(this + 0x14) = uStack_48;
  *(undefined4 *)(this + 0x18) = uStack_30;
  *(undefined4 *)(this + 0x1c) = uVar3;
  *(undefined4 *)(this + 0x20) = uStack_38;
  *(undefined4 *)(this + 0x24) = local_44;
  *(undefined4 *)(this + 0x28) = local_2c;
  *(undefined4 *)(this + 0x2c) = uVar2;
  *(undefined4 *)(this + 0x30) = 0x3f800000;
  *(undefined4 *)(this + 0x34) = 0x3f800000;
  *(undefined4 *)(this + 0x38) = 0x3f800000;
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::AEMath::MatrixGetGL  @0x0008b7e4  (64 bytes)
/* AbyssEngine::AEMath::MatrixGetGL(AbyssEngine::AEMath::Matrix const&, float*) */

void AbyssEngine::AEMath::MatrixGetGL(Matrix *param_1,float *param_2)

{
  *param_2 = *(float *)param_1;
  param_2[4] = *(float *)(param_1 + 4);
  param_2[8] = *(float *)(param_1 + 8);
  param_2[0xc] = *(float *)(param_1 + 0xc);
  param_2[1] = *(float *)(param_1 + 0x10);
  param_2[5] = *(float *)(param_1 + 0x14);
  param_2[9] = *(float *)(param_1 + 0x18);
  param_2[0xd] = *(float *)(param_1 + 0x1c);
  param_2[2] = *(float *)(param_1 + 0x20);
  param_2[6] = *(float *)(param_1 + 0x24);
  param_2[10] = *(float *)(param_1 + 0x28);
  param_2[0xe] = *(float *)(param_1 + 0x2c);
  param_2[3] = 0.0;
  param_2[7] = 0.0;
  param_2[0xb] = 0.0;
  param_2[0xf] = 1.0;
  return;
}

// ===== AbyssEngine::AEMath::MatrixDebugOut  @0x0008b824  (2 bytes)
/* AbyssEngine::AEMath::MatrixDebugOut(AbyssEngine::AEMath::Matrix const&) */

Matrix * AbyssEngine::AEMath::MatrixDebugOut(Matrix *param_1)

{
  return param_1;
}

// ===== AbyssEngine::AEMath::Sqrtf  @0x000919bc  (30 bytes)
/* AbyssEngine::AEMath::Sqrtf(float) */

float AbyssEngine::AEMath::Sqrtf(float param_1)

{
  float in_r0;
  float extraout_r0;
  float __x;
  
  __x = SQRT(in_r0);
  if (!NAN(__x)) {
    return __x;
  }
  sqrtf(__x);
  return extraout_r0;
}

// ===== AbyssEngine::AEMath::Sinf  @0x000919d8  (4 bytes)
/* AbyssEngine::AEMath::Sinf(float) */

void AbyssEngine::AEMath::Sinf(float param_1)

{
  sinf(param_1);
  return;
}

// ===== AbyssEngine::AEMath::Cosf  @0x000919dc  (4 bytes)
/* AbyssEngine::AEMath::Cosf(float) */

void AbyssEngine::AEMath::Cosf(float param_1)

{
  cosf(param_1);
  return;
}

// ===== AbyssEngine::AEMath::ACosf  @0x000919e0  (4 bytes)
/* AbyssEngine::AEMath::ACosf(float) */

void AbyssEngine::AEMath::ACosf(float param_1)

{
  acosf(param_1);
  return;
}

// ===== AbyssEngine::AEMath::ATanf  @0x000919e4  (4 bytes)
/* AbyssEngine::AEMath::ATanf(float) */

void AbyssEngine::AEMath::ATanf(float param_1)

{
  atanf(param_1);
  return;
}

// ===== AbyssEngine::AEMath::Absf  @0x000919e8  (28 bytes)
/* AbyssEngine::AEMath::Absf(float) */

float AbyssEngine::AEMath::Absf(float param_1)

{
  float in_r0;
  
  if (in_r0 < 0.0) {
    in_r0 = -in_r0;
  }
  return in_r0;
}

// ===== AbyssEngine::AEMath::Max  @0x00091a04  (28 bytes)
/* AbyssEngine::AEMath::Max(float, float) */

float AbyssEngine::AEMath::Max(float param_1,float param_2)

{
  float in_r0;
  float in_r1;
  
  if (in_r1 < in_r0) {
    in_r1 = in_r0;
  }
  return in_r1;
}

// ===== AbyssEngine::AEMath::Min  @0x00091a20  (28 bytes)
/* AbyssEngine::AEMath::Min(float, float) */

float AbyssEngine::AEMath::Min(float param_1,float param_2)

{
  float in_r0;
  float in_r1;
  
  if ((int)((uint)(in_r0 < in_r1) << 0x1f) < 0) {
    in_r1 = in_r0;
  }
  return in_r1;
}

// ===== AbyssEngine::AEMath::Pow  @0x00091a3c  (4 bytes)
/* AbyssEngine::AEMath::Pow(float, float) */

void AbyssEngine::AEMath::Pow(float param_1,float param_2)

{
  powf(param_1,param_2);
  return;
}

// ===== AbyssEngine::AEMath::InvSqrt  @0x00091a40  (54 bytes)
/* AbyssEngine::AEMath::InvSqrt(float) */

float AbyssEngine::AEMath::InvSqrt(float param_1)

{
  float in_r0;
  float fVar1;
  
  fVar1 = (float)(0x5f3759df - ((int)in_r0 >> 1));
  return fVar1 * (fVar1 * in_r0 * -0.5 * fVar1 + 1.5);
}

