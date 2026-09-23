// Class: AbyssEngine::EaseInOut
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::EaseInOut::EaseInOut  @0x0007aa34  (38 bytes)
/* AbyssEngine::EaseInOut::EaseInOut() */

EaseInOut * __thiscall AbyssEngine::EaseInOut::EaseInOut(EaseInOut *this)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0x40c90fdb;
  *(undefined4 *)(this + 8) = 0x4096cbe4;
  UpdateCurrentValue(this);
  return this;
}

// ===== AbyssEngine::EaseInOut::UpdateCurrentValue  @0x0007aa60  (104 bytes)
/* AbyssEngine::EaseInOut::UpdateCurrentValue() */

void __thiscall AbyssEngine::EaseInOut::UpdateCurrentValue(EaseInOut *this)

{
  float fVar1;
  
  if (*(float *)(this + 8) == 7.853982) {
    fVar1 = *(float *)this + *(float *)(this + 4);
  }
  else {
    fVar1 = (float)AEMath::Sinf(*(float *)(this + 8));
    fVar1 = *(float *)this + *(float *)(this + 4) * (fVar1 * 0.5 + 0.5);
  }
  *(float *)(this + 0xc) = fVar1;
  return;
}

// ===== AbyssEngine::EaseInOut::EaseInOut  @0x0007aad0  (44 bytes)
/* AbyssEngine::EaseInOut::EaseInOut(float, float) */

EaseInOut * __thiscall
AbyssEngine::EaseInOut::EaseInOut(EaseInOut *this,float param_1,float param_2)

{
  float in_r1;
  float in_r2;
  
  *(float *)this = in_r1;
  *(float *)(this + 4) = in_r2 - in_r1;
  *(undefined4 *)(this + 8) = 0x4096cbe4;
  UpdateCurrentValue(this);
  return this;
}

// ===== AbyssEngine::EaseInOut::SetRange  @0x0007aafc  (32 bytes)
/* AbyssEngine::EaseInOut::SetRange(float, float) */

void __thiscall AbyssEngine::EaseInOut::SetRange(EaseInOut *this,float param_1,float param_2)

{
  float in_r1;
  float in_r2;
  
  *(float *)this = in_r1;
  *(float *)(this + 4) = in_r2 - in_r1;
  *(undefined4 *)(this + 8) = 0x4096cbe4;
  UpdateCurrentValue(this);
  return;
}

// ===== AbyssEngine::EaseInOut::Increase  @0x0007ab20  (74 bytes)
/* AbyssEngine::EaseInOut::Increase(float) */

void __thiscall AbyssEngine::EaseInOut::Increase(EaseInOut *this,float param_1)

{
  float in_r1;
  float fVar1;
  
  fVar1 = in_r1 * 1.5258789e-05 * 6.2831855 + *(float *)(this + 8);
  if (7.853982 < fVar1) {
    fVar1 = 7.853982;
  }
  *(float *)(this + 8) = fVar1;
  UpdateCurrentValue(this);
  return;
}

// ===== AbyssEngine::EaseInOut::Decrease  @0x0007ab90  (74 bytes)
/* AbyssEngine::EaseInOut::Decrease(float) */

void __thiscall AbyssEngine::EaseInOut::Decrease(EaseInOut *this,float param_1)

{
  float in_r1;
  float fVar1;
  
  fVar1 = *(float *)(this + 8) + in_r1 * -1.5258789e-05 * 6.2831855;
  if ((int)((uint)(fVar1 < 4.712389) << 0x1f) < 0) {
    fVar1 = 4.712389;
  }
  *(float *)(this + 8) = fVar1;
  UpdateCurrentValue(this);
  return;
}

// ===== AbyssEngine::EaseInOut::RunOut  @0x0007ac00  (136 bytes)
/* AbyssEngine::EaseInOut::RunOut(float) */

void __thiscall AbyssEngine::EaseInOut::RunOut(EaseInOut *this,float param_1)

{
  byte bVar1;
  float in_r1;
  char cVar2;
  float fVar3;
  
  fVar3 = *(float *)(this + 8);
  bVar1 = (byte)(((uint)(fVar3 == 6.2831855) << 0x1e) >> 0x18);
  cVar2 = -((char)((byte)(((uint)(fVar3 < 6.2831855) << 0x1f) >> 0x18) | bVar1) >> 7);
  if ((bool)(bVar1 >> 6) || (bool)cVar2 != NAN(fVar3)) {
    if ((cVar2 == '\0') ||
       (fVar3 = in_r1 * 1.5258789e-05 * 6.2831855 + fVar3, *(float *)(this + 8) = fVar3,
       fVar3 <= 6.2831855)) goto LAB_001d831c;
  }
  else {
    fVar3 = fVar3 + in_r1 * -1.5258789e-05 * 6.2831855;
    *(float *)(this + 8) = fVar3;
    if (-1 < (int)((uint)(fVar3 < 6.2831855) << 0x1f)) goto LAB_001d831c;
  }
  *(undefined4 *)(this + 8) = 0x40c90fdb;
LAB_001d831c:
  UpdateCurrentValue(this);
  return;
}

// ===== AbyssEngine::EaseInOut::GetValue  @0x0007aca8  (4 bytes)
/* AbyssEngine::EaseInOut::GetValue() */

undefined4 __thiscall AbyssEngine::EaseInOut::GetValue(EaseInOut *this)

{
  return *(undefined4 *)(this + 0xc);
}

// ===== AbyssEngine::EaseInOut::SetToMaxValue  @0x0007acac  (14 bytes)
/* AbyssEngine::EaseInOut::SetToMaxValue() */

void __thiscall AbyssEngine::EaseInOut::SetToMaxValue(EaseInOut *this)

{
  *(undefined4 *)(this + 8) = 0x40fb53d2;
  UpdateCurrentValue(this);
  return;
}

// ===== AbyssEngine::EaseInOut::SetToMinValue  @0x0007acba  (16 bytes)
/* AbyssEngine::EaseInOut::SetToMinValue() */

void __thiscall AbyssEngine::EaseInOut::SetToMinValue(EaseInOut *this)

{
  *(undefined4 *)(this + 8) = 0x4096cbe4;
  UpdateCurrentValue(this);
  return;
}

// ===== AbyssEngine::EaseInOut::GetMinValue  @0x0007acc8  (4 bytes)
/* AbyssEngine::EaseInOut::GetMinValue() */

undefined4 __thiscall AbyssEngine::EaseInOut::GetMinValue(EaseInOut *this)

{
  return *(undefined4 *)this;
}

// ===== AbyssEngine::EaseInOut::GetMaxValue  @0x0007accc  (18 bytes)
/* AbyssEngine::EaseInOut::GetMaxValue() */

float __thiscall AbyssEngine::EaseInOut::GetMaxValue(EaseInOut *this)

{
  return *(float *)this + *(float *)(this + 4);
}

