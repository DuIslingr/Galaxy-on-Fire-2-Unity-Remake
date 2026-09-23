// Class: ArrayRemove<AbyssEngine
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== ArrayRemove<AbyssEngine::Mesh*>  @0x000854d0  (66 bytes)
/* void ArrayRemove<AbyssEngine::Mesh*>(AbyssEngine::Mesh*, Array<AbyssEngine::Mesh*>&) */

void ArrayRemove<AbyssEngine::Mesh*>(Mesh *param_1,Array *param_2)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  Mesh *pMVar5;
  
  uVar3 = *(uint *)param_2;
  if (uVar3 == 0) {
    iVar2 = 0;
  }
  else {
    uVar4 = 0;
    iVar2 = 0;
    do {
      pMVar5 = *(Mesh **)(*(int *)(param_2 + 4) + uVar4 * 4);
      uVar4 = uVar4 + 1;
      if (pMVar5 != param_1) {
        *(Mesh **)(*(int *)(param_2 + 4) + iVar2 * 4) = pMVar5;
        iVar2 = iVar2 + 1;
      }
    } while (uVar4 < uVar3);
  }
  *(int *)param_2 = iVar2;
  if (iVar2 == 0) {
    iVar2 = 1;
  }
  *(int *)(param_2 + 8) = iVar2;
  pvVar1 = realloc(*(void **)(param_2 + 4),iVar2 << 2);
  *(void **)(param_2 + 4) = pvVar1;
  return;
}

// ===== ArrayRemove<AbyssEngine::Transform*>  @0x000855d8  (66 bytes)
/* void ArrayRemove<AbyssEngine::Transform*>(AbyssEngine::Transform*,
   Array<AbyssEngine::Transform*>&) */

void ArrayRemove<AbyssEngine::Transform*>(Transform *param_1,Array *param_2)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  Transform *pTVar5;
  
  uVar3 = *(uint *)param_2;
  if (uVar3 == 0) {
    iVar2 = 0;
  }
  else {
    uVar4 = 0;
    iVar2 = 0;
    do {
      pTVar5 = *(Transform **)(*(int *)(param_2 + 4) + uVar4 * 4);
      uVar4 = uVar4 + 1;
      if (pTVar5 != param_1) {
        *(Transform **)(*(int *)(param_2 + 4) + iVar2 * 4) = pTVar5;
        iVar2 = iVar2 + 1;
      }
    } while (uVar4 < uVar3);
  }
  *(int *)param_2 = iVar2;
  if (iVar2 == 0) {
    iVar2 = 1;
  }
  *(int *)(param_2 + 8) = iVar2;
  pvVar1 = realloc(*(void **)(param_2 + 4),iVar2 << 2);
  *(void **)(param_2 + 4) = pvVar1;
  return;
}

// ===== ArrayRemove<AbyssEngine::String*>  @0x000d42e4  (66 bytes)
/* void ArrayRemove<AbyssEngine::String*>(AbyssEngine::String*, Array<AbyssEngine::String*>&) */

void ArrayRemove<AbyssEngine::String*>(String *param_1,Array *param_2)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  String *pSVar5;
  
  uVar3 = *(uint *)param_2;
  if (uVar3 == 0) {
    iVar2 = 0;
  }
  else {
    uVar4 = 0;
    iVar2 = 0;
    do {
      pSVar5 = *(String **)(*(int *)(param_2 + 4) + uVar4 * 4);
      uVar4 = uVar4 + 1;
      if (pSVar5 != param_1) {
        *(String **)(*(int *)(param_2 + 4) + iVar2 * 4) = pSVar5;
        iVar2 = iVar2 + 1;
      }
    } while (uVar4 < uVar3);
  }
  *(int *)param_2 = iVar2;
  if (iVar2 == 0) {
    iVar2 = 1;
  }
  *(int *)(param_2 + 8) = iVar2;
  pvVar1 = realloc(*(void **)(param_2 + 4),iVar2 << 2);
  *(void **)(param_2 + 4) = pvVar1;
  return;
}

