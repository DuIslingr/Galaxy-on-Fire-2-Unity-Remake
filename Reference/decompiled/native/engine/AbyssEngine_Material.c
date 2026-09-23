// Class: AbyssEngine::Material
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::Material::Material  @0x00084428  (350 bytes)
/* AbyssEngine::Material::Material(AbyssEngine::Material*) */

void __thiscall AbyssEngine::Material::Material(Material *this,Material *param_1)

{
  Vector *this_00;
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  int local_34;
  
  local_34 = __stack_chk_guard;
  puVar1 = operator_new__(0x3c);
  uVar5 = 0;
  uVar6 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar7 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar8 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 **)(this + 0x30) = puVar1;
  *(undefined4 *)(this + 0x34) = 1;
  puVar1[0xb] = 0;
  puVar1[0xc] = uVar6;
  puVar1[0xd] = uVar7;
  puVar1[0xe] = uVar8;
  puVar1[8] = 0;
  puVar1[9] = uVar6;
  puVar1[10] = uVar7;
  puVar1[0xb] = uVar8;
  *puVar1 = 0;
  puVar1[1] = uVar6;
  puVar1[2] = uVar7;
  puVar1[3] = uVar8;
  puVar1[4] = 0;
  puVar1[5] = uVar6;
  puVar1[6] = uVar7;
  puVar1[7] = uVar8;
  *(undefined4 *)(this + 0x2c) = 0;
  puVar1 = operator_new__(0x3c);
  *(undefined4 **)(this + 0x3c) = puVar1;
  *(undefined4 *)(this + 0x40) = 1;
  puVar1[0xb] = uVar5;
  puVar1[0xc] = uVar6;
  puVar1[0xd] = uVar7;
  puVar1[0xe] = uVar8;
  puVar1[8] = uVar5;
  puVar1[9] = uVar6;
  puVar1[10] = uVar7;
  puVar1[0xb] = uVar8;
  *puVar1 = uVar5;
  puVar1[1] = uVar6;
  puVar1[2] = uVar7;
  puVar1[3] = uVar8;
  puVar1[4] = uVar5;
  puVar1[5] = uVar6;
  puVar1[6] = uVar7;
  puVar1[7] = uVar8;
  *(undefined4 *)(this + 0x38) = 0;
  puVar1 = operator_new__(4);
  *(undefined4 **)(this + 0x48) = puVar1;
  *(undefined4 *)(this + 0x4c) = 1;
  *puVar1 = 0;
  *(undefined4 *)(this + 0x44) = 0;
  puVar1 = operator_new__(4);
  *(undefined4 **)(this + 0x54) = puVar1;
  *(undefined4 *)(this + 0x58) = 1;
  *puVar1 = 0;
  *(undefined4 *)(this + 0x50) = 0;
  puVar1 = operator_new__(0x3c);
  uVar5 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar6 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar7 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 **)(this + 0x60) = puVar1;
  *(undefined4 *)(this + 100) = 1;
  puVar1[0xb] = 0;
  puVar1[0xc] = uVar5;
  puVar1[0xd] = uVar6;
  puVar1[0xe] = uVar7;
  puVar1[8] = 0;
  puVar1[9] = uVar5;
  puVar1[10] = uVar6;
  puVar1[0xb] = uVar7;
  *puVar1 = 0;
  puVar1[1] = uVar5;
  puVar1[2] = uVar6;
  puVar1[3] = uVar7;
  puVar1[4] = 0;
  puVar1[5] = uVar5;
  puVar1[6] = uVar6;
  puVar1[7] = uVar7;
  *(undefined4 *)(this + 0x5c) = 0;
  this_00 = (Vector *)(this + 0x68);
  *(undefined4 *)this_00 = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  if (param_1 == (Material *)0x0) {
    *(undefined4 *)(this + 0x20) = 0;
    local_40 = 0xc1200000;
    uStack_3c = 0;
    local_38 = 0;
    AEMath::Vector::operator=(this_00,(Vector *)&local_40);
    __aeabi_memset4(this,0x20,0xff);
  }
  else {
    iVar2 = 0;
    do {
      *(undefined4 *)(this + iVar2 * 4) = *(undefined4 *)(param_1 + iVar2 * 4);
      iVar2 = iVar2 + 1;
    } while (iVar2 != 8);
    *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
    uVar3 = *(uint *)(param_1 + 0x28);
    *(uint *)(this + 0x28) = uVar3;
    if (uVar3 == 0) {
      pvVar4 = (void *)0x0;
    }
    else {
      if (0x7fffffff < uVar3) {
        uVar3 = 0xffffffff;
      }
      pvVar4 = operator_new__(uVar3);
    }
    *(void **)(this + 0x24) = pvVar4;
    AEMath::Vector::operator=(this_00,(Vector *)(param_1 + 0x68));
  }
  if (__stack_chk_guard - local_34 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_34);
  }
  return;
}

// ===== AbyssEngine::Material::Material  @0x00086448  (244 bytes)
/* AbyssEngine::Material::Material() */

Material * __thiscall AbyssEngine::Material::Material(Material *this)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  *(undefined4 *)(this + 0x20) = 0;
  puVar1 = operator_new__(0x3c);
  uVar2 = 0;
  uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar5 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 **)(this + 0x30) = puVar1;
  *(undefined4 *)(this + 0x34) = 1;
  puVar1[0xb] = 0;
  puVar1[0xc] = uVar3;
  puVar1[0xd] = uVar4;
  puVar1[0xe] = uVar5;
  puVar1[8] = 0;
  puVar1[9] = uVar3;
  puVar1[10] = uVar4;
  puVar1[0xb] = uVar5;
  *puVar1 = 0;
  puVar1[1] = uVar3;
  puVar1[2] = uVar4;
  puVar1[3] = uVar5;
  puVar1[4] = 0;
  puVar1[5] = uVar3;
  puVar1[6] = uVar4;
  puVar1[7] = uVar5;
  *(undefined4 *)(this + 0x2c) = 0;
  puVar1 = operator_new__(0x3c);
  *(undefined4 **)(this + 0x3c) = puVar1;
  *(undefined4 *)(this + 0x40) = 1;
  puVar1[0xb] = uVar2;
  puVar1[0xc] = uVar3;
  puVar1[0xd] = uVar4;
  puVar1[0xe] = uVar5;
  puVar1[8] = uVar2;
  puVar1[9] = uVar3;
  puVar1[10] = uVar4;
  puVar1[0xb] = uVar5;
  *puVar1 = uVar2;
  puVar1[1] = uVar3;
  puVar1[2] = uVar4;
  puVar1[3] = uVar5;
  puVar1[4] = uVar2;
  puVar1[5] = uVar3;
  puVar1[6] = uVar4;
  puVar1[7] = uVar5;
  *(undefined4 *)(this + 0x38) = 0;
  puVar1 = operator_new__(4);
  *(undefined4 **)(this + 0x48) = puVar1;
  *(undefined4 *)(this + 0x4c) = 1;
  *puVar1 = 0;
  *(undefined4 *)(this + 0x44) = 0;
  puVar1 = operator_new__(4);
  *(undefined4 **)(this + 0x54) = puVar1;
  *(undefined4 *)(this + 0x58) = 1;
  *puVar1 = 0;
  *(undefined4 *)(this + 0x50) = 0;
  puVar1 = operator_new__(0x3c);
  uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 **)(this + 0x60) = puVar1;
  *(undefined4 *)(this + 100) = 1;
  puVar1[0xb] = 0;
  puVar1[0xc] = uVar2;
  puVar1[0xd] = uVar3;
  puVar1[0xe] = uVar4;
  puVar1[8] = 0;
  puVar1[9] = uVar2;
  puVar1[10] = uVar3;
  puVar1[0xb] = uVar4;
  *puVar1 = 0;
  puVar1[1] = uVar2;
  puVar1[2] = uVar3;
  puVar1[3] = uVar4;
  puVar1[4] = 0;
  puVar1[5] = uVar2;
  puVar1[6] = uVar3;
  puVar1[7] = uVar4;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x68) = 0xc1200000;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  __aeabi_memset4(this + 4,0x1c,0xff);
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  return this;
}

