// Class: ArrayAddCached<AbyssEngine
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== ArrayAddCached<AbyssEngine::Mesh*>  @0x00089430  (64 bytes)
/* void ArrayAddCached<AbyssEngine::Mesh*>(AbyssEngine::Mesh*, Array<AbyssEngine::Mesh*>&) */

void ArrayAddCached<AbyssEngine::Mesh*>(Mesh *param_1,Array *param_2)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  
  uVar1 = *(uint *)param_2;
  if (uVar1 < *(uint *)(param_2 + 8)) {
    pvVar3 = *(void **)(param_2 + 4);
  }
  else {
    pvVar3 = realloc(*(void **)(param_2 + 4),*(uint *)(param_2 + 8) << 3);
    *(void **)(param_2 + 4) = pvVar3;
    iVar2 = *(int *)(param_2 + 8);
    __aeabi_memclr4((void *)((int)pvVar3 + iVar2 * 4),iVar2 << 2);
    *(int *)(param_2 + 8) = iVar2 << 1;
    uVar1 = *(uint *)param_2;
  }
  *(Mesh **)((int)pvVar3 + uVar1 * 4) = param_1;
  *(uint *)param_2 = uVar1 + 1;
  return;
}

