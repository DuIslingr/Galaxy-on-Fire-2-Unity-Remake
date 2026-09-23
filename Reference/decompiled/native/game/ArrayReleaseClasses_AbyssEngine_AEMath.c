// Class: ArrayReleaseClasses<AbyssEngine::AEMath
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== ArrayReleaseClasses<AbyssEngine::AEMath::Vector*>  @0x000a54f8  (60 bytes)
/* void ArrayReleaseClasses<AbyssEngine::AEMath::Vector*>(Array<AbyssEngine::AEMath::Vector*>&) */

void ArrayReleaseClasses<AbyssEngine::AEMath::Vector*>(Array *param_1)

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

