// Class: ArrayReleaseClasses<Array<AbyssEngine::AEMath
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== ArrayReleaseClasses<Array<AbyssEngine::AEMath::Vector*>*>  @0x000a5534  (70 bytes)
/* void 
   ArrayReleaseClasses<Array<AbyssEngine::AEMath::Vector*>*>(Array<Array<AbyssEngine::AEMath::Vector*>*>&)
    */

void ArrayReleaseClasses<Array<AbyssEngine::AEMath::Vector*>*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  void *pvVar3;
  uint uVar4;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar4 = 0;
    do {
      pvVar3 = *(void **)((int)pvVar1 + uVar4 * 4);
      if (pvVar3 != (void *)0x0) {
        if (*(void **)((int)pvVar3 + 4) != (void *)0x0) {
          operator_delete__(*(void **)((int)pvVar3 + 4));
        }
        operator_delete(pvVar3);
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

