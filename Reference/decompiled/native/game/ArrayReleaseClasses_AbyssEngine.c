// Class: ArrayReleaseClasses<AbyssEngine
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== ArrayReleaseClasses<AbyssEngine::KeyFrame*>  @0x0008117a  (60 bytes)
/* void ArrayReleaseClasses<AbyssEngine::KeyFrame*>(Array<AbyssEngine::KeyFrame*>&) */

void ArrayReleaseClasses<AbyssEngine::KeyFrame*>(Array *param_1)

{
  void *pvVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar3 = *(uint *)(param_1 + 8);
  if (uVar3 != 0) {
    uVar4 = 0;
    do {
      pvVar2 = *(void **)((int)pvVar1 + uVar4 * 4);
      if (pvVar2 != (void *)0x0) {
        operator_delete(pvVar2);
        pvVar1 = *(void **)(param_1 + 4);
        uVar3 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar4 * 4) = 0;
      uVar4 = uVar4 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar4 < uVar3);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArrayReleaseClasses<AbyssEngine::String*>  @0x000822c8  (66 bytes)
/* void ArrayReleaseClasses<AbyssEngine::String*>(Array<AbyssEngine::String*>&) */

void ArrayReleaseClasses<AbyssEngine::String*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  String *this;
  uint uVar3;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      this = *(String **)((int)pvVar1 + uVar3 * 4);
      if (this != (String *)0x0) {
        pvVar1 = (void *)AbyssEngine::String::~String(this);
        operator_delete(pvVar1);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar3 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArrayReleaseClasses<AbyssEngine::ShaderBaseStruct*>  @0x0008eeb0  (86 bytes)
/* void ArrayReleaseClasses<AbyssEngine::ShaderBaseStruct*>(Array<AbyssEngine::ShaderBaseStruct*>&)
    */

void ArrayReleaseClasses<AbyssEngine::ShaderBaseStruct*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar4 = 0;
    do {
      puVar3 = *(undefined4 **)((int)pvVar1 + uVar4 * 4);
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = &PTR___cxa_pure_virtual_00263918;
        AbyssEngine::String::~String((String *)(puVar3 + 3));
        operator_delete(puVar3);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar4 * 4) = 0;
      uVar4 = uVar4 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar4 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

