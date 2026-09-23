// Class: AbyssEngine::AERandom
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::AERandom::AERandom  @0x0007acde  (38 bytes)
/* AbyssEngine::AERandom::AERandom() */

AERandom * __thiscall AbyssEngine::AERandom::AERandom(AERandom *this)

{
  uint uVar1;
  
  uVar1 = time((time_t *)0x0);
  *(uint *)this = uVar1 ^ 0xdeece66d;
  *(uint *)(this + 4) = (ushort)((int)uVar1 >> 0x1f) ^ 5;
  return this;
}

// ===== AbyssEngine::AERandom::setSeed  @0x0007ad04  (22 bytes)
/* AbyssEngine::AERandom::setSeed(long long) */

void AbyssEngine::AERandom::setSeed(longlong param_1)

{
  uint in_r2;
  ushort in_r3;
  
  *(uint *)param_1 = in_r2 ^ 0xdeece66d;
  ((uint *)param_1)[1] = in_r3 ^ 5;
  return;
}

// ===== AbyssEngine::AERandom::AERandom  @0x0007ad1a  (22 bytes)
/* AbyssEngine::AERandom::AERandom(long long) */

void __thiscall AbyssEngine::AERandom::AERandom(AERandom *this,longlong param_1)

{
  *(uint *)this = (uint)param_1 ^ 0xdeece66d;
  *(uint *)(this + 4) = (ushort)((ulonglong)param_1 >> 0x20) ^ 5;
  return;
}

// ===== AbyssEngine::AERandom::~AERandom  @0x0007ad30  (2 bytes)
/* AbyssEngine::AERandom::~AERandom() */

AERandom * __thiscall AbyssEngine::AERandom::~AERandom(AERandom *this)

{
  return this;
}

// ===== AbyssEngine::AERandom::reset  @0x0007ad32  (36 bytes)
/* AbyssEngine::AERandom::reset() */

void __thiscall AbyssEngine::AERandom::reset(AERandom *this)

{
  uint uVar1;
  
  uVar1 = time((time_t *)0x0);
  *(uint *)this = uVar1 ^ 0xdeece66d;
  *(uint *)(this + 4) = (ushort)((int)uVar1 >> 0x1f) ^ 5;
  return;
}

// ===== AbyssEngine::AERandom::next  @0x0007ad56  (74 bytes)
/* AbyssEngine::AERandom::next(int) */

uint __thiscall AbyssEngine::AERandom::next(AERandom *this,int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  lVar1 = (ulonglong)*(uint *)this * 0xdeece66d;
  uVar3 = (uint)lVar1;
  uVar4 = uVar3 + 0xb;
  uVar2 = *(int *)(this + 4) * -0x21131993 + *(uint *)this * 5 + (int)((ulonglong)lVar1 >> 0x20) +
          (uint)(0xfffffff4 < uVar3) & 0xffff;
  *(uint *)this = uVar4;
  *(uint *)(this + 4) = uVar2;
  uVar3 = uVar4 >> (0x30U - param_1 & 0xff) | uVar2 << (0x20 - (0x30U - param_1) & 0xff);
  if (-1 < (int)(0x10U - param_1)) {
    uVar3 = uVar2 >> (0x10U - param_1 & 0xff);
  }
  return uVar3;
}

// ===== AbyssEngine::AERandom::nextInt  @0x0007ada0  (50 bytes)
/* AbyssEngine::AERandom::nextInt() */

uint __thiscall AbyssEngine::AERandom::nextInt(AERandom *this)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  
  lVar1 = (ulonglong)*(uint *)this * 0xdeece66d;
  uVar3 = (uint)lVar1;
  uVar2 = uVar3 + 0xb;
  uVar3 = *(int *)(this + 4) * -0x21131993 + *(uint *)this * 5 + (int)((ulonglong)lVar1 >> 0x20) +
          (uint)(0xfffffff4 < uVar3);
  *(uint *)this = uVar2;
  *(uint *)(this + 4) = uVar3 & 0xffff;
  return uVar2 >> 0x10 | uVar3 * 0x10000;
}

// ===== AbyssEngine::AERandom::nextInt  @0x0007add2  (152 bytes)
/* AbyssEngine::AERandom::nextInt(int) */

uint __thiscall AbyssEngine::AERandom::nextInt(AERandom *this,int param_1)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  uint extraout_r1;
  uint uVar6;
  
  if ((-param_1 & param_1) == param_1) {
    lVar3 = (ulonglong)*(uint *)this * 0xdeece66d;
    uVar6 = (uint)lVar3;
    uVar5 = uVar6 + 0xb;
    uVar6 = *(int *)(this + 4) * -0x21131993 + *(uint *)this * 5 + (int)((ulonglong)lVar3 >> 0x20) +
            (uint)(0xfffffff4 < uVar6) & 0xffff;
    *(uint *)this = uVar5;
    *(uint *)(this + 4) = uVar6;
    lVar3 = (longlong)(int)(uVar5 >> 0x11 | uVar6 << 0xf) * (longlong)param_1;
    uVar5 = (uint)lVar3 >> 0x1f | (int)((ulonglong)lVar3 >> 0x20) << 1;
  }
  else {
    uVar5 = *(uint *)this;
    uVar6 = *(uint *)(this + 4);
    do {
      uVar2 = (ulonglong)uVar5;
      uVar4 = (uint)(uVar2 * 0xdeece66d);
      iVar1 = uVar5 * 5;
      uVar5 = uVar4 + 0xb;
      uVar6 = uVar6 * -0x21131993 + iVar1 + (int)(uVar2 * 0xdeece66d >> 0x20) +
              (uint)(0xfffffff4 < uVar4) & 0xffff;
      uVar4 = uVar5 >> 0x11 | uVar6 << 0xf;
      __aeabi_idivmod(uVar4,param_1);
    } while ((int)(((param_1 + -1) - extraout_r1) + uVar4) < 0);
    *(uint *)this = uVar5;
    *(uint *)(this + 4) = uVar6;
    uVar5 = extraout_r1;
  }
  return uVar5;
}

