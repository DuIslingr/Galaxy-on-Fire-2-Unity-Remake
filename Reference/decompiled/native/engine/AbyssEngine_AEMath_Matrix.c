// Class: AbyssEngine::AEMath::Matrix
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::AEMath::Matrix::operator.cast.to.float*  @0x0008a750  (2 bytes)
/* AbyssEngine::AEMath::Matrix::operator float*() */

float * __thiscall AbyssEngine::AEMath::Matrix::operator_cast_to_float_(Matrix *this)

{
  return (float *)this;
}

// ===== AbyssEngine::AEMath::Matrix::operator.cast.to.float*  @0x0008a752  (2 bytes)
/* AbyssEngine::AEMath::Matrix::operator float const*() const */

float * __thiscall AbyssEngine::AEMath::Matrix::operator_cast_to_float_(Matrix *this)

{
  return (float *)this;
}

// ===== AbyssEngine::AEMath::Matrix::operator=  @0x0008a754  (56 bytes)
/* AbyssEngine::AEMath::Matrix::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::Matrix const&) */

Matrix * __thiscall AbyssEngine::AEMath::Matrix::operator=(Matrix *this,Matrix *param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)this = *(undefined8 *)param_1;
  *(undefined8 *)(this + 8) = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x18);
  *(undefined8 *)(this + 0x10) = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(this + 0x18) = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x28);
  *(undefined8 *)(this + 0x20) = *(undefined8 *)(param_1 + 0x20);
  *(undefined8 *)(this + 0x28) = uVar1;
  Vector::operator=((Vector *)(this + 0x30),(Vector *)(param_1 + 0x30));
  return this;
}

// ===== AbyssEngine::AEMath::Matrix::operator*=  @0x0008a78c  (448 bytes)
/* AbyssEngine::AEMath::Matrix::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::Matrix const&) */

Matrix * __thiscall AbyssEngine::AEMath::Matrix::operator*=(Matrix *this,Matrix *param_1)

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
  
  fVar9 = *(float *)this;
  fVar8 = *(float *)(param_1 + 0x10);
  fVar10 = *(float *)(this + 4);
  fVar1 = *(float *)(param_1 + 0x20);
  fVar11 = *(float *)(this + 8);
  *(float *)this = fVar9 * *(float *)param_1 + fVar10 * fVar8 + fVar11 * fVar1;
  fVar2 = *(float *)(param_1 + 0x14);
  fVar3 = *(float *)(param_1 + 0x24);
  *(float *)(this + 4) = fVar9 * *(float *)(param_1 + 4) + fVar10 * fVar2 + fVar11 * fVar3;
  fVar4 = *(float *)(param_1 + 0x18);
  fVar5 = *(float *)(param_1 + 0x28);
  *(float *)(this + 8) = fVar9 * *(float *)(param_1 + 8) + fVar10 * fVar4 + fVar11 * fVar5;
  fVar7 = *(float *)(param_1 + 0x1c);
  fVar6 = *(float *)(param_1 + 0x2c);
  *(float *)(this + 0xc) =
       *(float *)(this + 0xc) + fVar9 * *(float *)(param_1 + 0xc) + fVar10 * fVar7 + fVar11 * fVar6;
  fVar11 = *(float *)(this + 0x14);
  fVar10 = *(float *)(this + 0x10);
  fVar9 = *(float *)param_1;
  fVar12 = *(float *)(this + 0x18);
  *(float *)(this + 0x10) = fVar10 * fVar9 + fVar11 * fVar8 + fVar12 * fVar1;
  fVar8 = *(float *)(param_1 + 4);
  *(float *)(this + 0x14) = fVar10 * fVar8 + fVar11 * fVar2 + fVar12 * fVar3;
  fVar2 = *(float *)(param_1 + 8);
  *(float *)(this + 0x18) = fVar10 * fVar2 + fVar11 * fVar4 + fVar12 * fVar5;
  fVar4 = *(float *)(param_1 + 0xc);
  *(float *)(this + 0x1c) =
       *(float *)(this + 0x1c) + fVar10 * fVar4 + fVar11 * fVar7 + fVar12 * fVar6;
  fVar7 = *(float *)(this + 0x20);
  fVar10 = *(float *)(this + 0x24);
  fVar11 = *(float *)(this + 0x28);
  *(float *)(this + 0x20) = fVar7 * fVar9 + fVar10 * *(float *)(param_1 + 0x10) + fVar11 * fVar1;
  *(float *)(this + 0x24) = fVar7 * fVar8 + fVar10 * *(float *)(param_1 + 0x14) + fVar11 * fVar3;
  *(float *)(this + 0x28) = fVar7 * fVar2 + fVar10 * *(float *)(param_1 + 0x18) + fVar11 * fVar5;
  *(float *)(this + 0x2c) =
       *(float *)(this + 0x2c) +
       fVar7 * fVar4 + fVar10 * *(float *)(param_1 + 0x1c) + fVar11 * fVar6;
  Vector::operator*=((Vector *)(this + 0x30),(Vector *)(param_1 + 0x30));
  return this;
}

