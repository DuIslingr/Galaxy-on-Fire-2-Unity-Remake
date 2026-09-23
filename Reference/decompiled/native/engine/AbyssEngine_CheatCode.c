// Class: AbyssEngine::CheatCode
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::CheatCode::CheatCode  @0x0007d9ae  (42 bytes)
/* AbyssEngine::CheatCode::CheatCode() */

CheatCode * __thiscall AbyssEngine::CheatCode::CheatCode(CheatCode *this)

{
  undefined4 *puVar1;
  undefined2 *puVar2;
  
  puVar1 = operator_new(0xc);
  puVar2 = operator_new__(2);
  puVar1[1] = puVar2;
  puVar1[2] = 1;
  *puVar2 = 0;
  *puVar1 = 0;
  *(undefined4 **)this = puVar1;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return this;
}

// ===== AbyssEngine::CheatCode::~CheatCode  @0x0007d9e6  (32 bytes)
/* AbyssEngine::CheatCode::~CheatCode() */

CheatCode * __thiscall AbyssEngine::CheatCode::~CheatCode(CheatCode *this)

{
  void *pvVar1;
  
  pvVar1 = *(void **)this;
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)this = 0;
  return this;
}

// ===== AbyssEngine::CheatCode::Update  @0x0007da06  (92 bytes)
/* AbyssEngine::CheatCode::Update(unsigned short) */

bool __thiscall AbyssEngine::CheatCode::Update(CheatCode *this,ushort param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  ushort *puVar4;
  bool bVar5;
  
  puVar3 = *(uint **)this;
  uVar1 = *(uint *)(this + 8);
  uVar2 = *puVar3;
  if (uVar2 <= uVar1) {
    return false;
  }
  puVar4 = (ushort *)puVar3[1];
  if (puVar4[uVar1] != param_1) {
    *(undefined4 *)(this + 8) = 0;
    uVar1 = (uint)(*puVar4 == param_1);
    *(uint *)(this + 8) = uVar1;
    bVar5 = uVar1 == *puVar3;
    if (bVar5) {
      uVar1 = 0;
    }
    *(uint *)(this + 8) = uVar1;
    return bVar5;
  }
  uVar1 = uVar1 + 1;
  bVar5 = uVar1 == uVar2;
  if (bVar5) {
    uVar1 = 0;
  }
  *(uint *)(this + 8) = uVar1;
  return bVar5;
}

