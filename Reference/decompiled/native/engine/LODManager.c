// Class: LODManager
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== LODManager::LODManager  @0x000a0348  (54 bytes)
/* LODManager::LODManager() */

LODManager * __thiscall LODManager::LODManager(LODManager *this)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  puVar1 = operator_new(0xc);
  puVar2 = operator_new__(4);
  puVar1[1] = puVar2;
  *puVar2 = 0;
  puVar1[2] = 1;
  *puVar1 = 0;
  *(undefined4 **)this = puVar1;
  *(undefined4 *)(this + 0x10) = 0x3e9;
  return this;
}

// ===== LODManager::~LODManager  @0x000a038c  (32 bytes)
/* LODManager::~LODManager() */

LODManager * __thiscall LODManager::~LODManager(LODManager *this)

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

// ===== LODManager::addObject  @0x000a03ac  (50 bytes)
/* LODManager::addObject(AEGeometry*) */

void __thiscall LODManager::addObject(LODManager *this,AEGeometry *param_1)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  
  iVar1 = AEGeometry::hasLod(param_1);
  if (iVar1 != 1) {
    return;
  }
  piVar3 = *(int **)this;
  piVar3[2] = *piVar3 + 1;
  pvVar2 = realloc((void *)piVar3[1],(*piVar3 + 1) * 4);
  piVar3[1] = (int)pvVar2;
  *(AEGeometry **)((int)pvVar2 + *piVar3 * 4) = param_1;
  *piVar3 = piVar3[2];
  return;
}

// ===== LODManager::removeObject  @0x000a03de  (48 bytes)
/* LODManager::removeObject(AEGeometry*) */

void __thiscall LODManager::removeObject(LODManager *this,AEGeometry *param_1)

{
  Array *pAVar1;
  uint uVar2;
  
  pAVar1 = *(Array **)this;
  if (*(int *)pAVar1 != 0) {
    uVar2 = 0;
    do {
      if (*(AEGeometry **)(*(int *)(pAVar1 + 4) + uVar2 * 4) == param_1) {
        ArrayRemove<AEGeometry*>(param_1,pAVar1);
        pAVar1 = *(Array **)this;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)pAVar1);
  }
  return;
}

// ===== LODManager::forceUpdate  @0x000a0450  (186 bytes)
/* LODManager::forceUpdate(int, bool) */

void __thiscall LODManager::forceUpdate(LODManager *this,int param_1,bool param_2)

{
  PaintCanvas *this_00;
  uint uVar1;
  Matrix *pMVar2;
  uint *puVar3;
  AEGeometry *this_01;
  float fVar4;
  undefined8 local_40;
  undefined4 local_38;
  int local_34;
  
  this_00 = Globals::Canvas;
  local_34 = __stack_chk_guard;
  uVar1 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
  pMVar2 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(this_00,uVar1);
  AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_40,pMVar2);
  fVar4 = (float)AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 4),(Vector *)&local_40);
  puVar3 = *(uint **)this;
  if (*puVar3 != 0) {
    uVar1 = 0;
    do {
      this_01 = *(AEGeometry **)(puVar3[1] + uVar1 * 4);
      if (param_2) {
        fVar4 = (float)AEGeometry::getParentPosition();
      }
      else {
        local_40 = *(undefined8 *)(this + 4);
        local_38 = *(undefined4 *)(this + 0xc);
      }
      fVar4 = (float)AEGeometry::updateLod(this_01,(Vector *)&local_40,fVar4);
      puVar3 = *(uint **)this;
      uVar1 = uVar1 + 1;
    } while (uVar1 < *puVar3);
  }
  if (__stack_chk_guard != local_34) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== LODManager::update  @0x000a051c  (24 bytes)
/* LODManager::update(int) */

void __thiscall LODManager::update(LODManager *this,int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x10);
  *(int *)(this + 0x10) = param_1 + iVar1;
  if (1000 < param_1 + iVar1) {
    *(undefined4 *)(this + 0x10) = 0;
    forceUpdate(this,0,false);
    return;
  }
  return;
}

