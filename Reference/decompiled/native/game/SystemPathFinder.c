// Class: SystemPathFinder
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== SystemPathFinder::SystemPathFinder  @0x0014062e  (2 bytes)
/* SystemPathFinder::SystemPathFinder() */

SystemPathFinder * __thiscall SystemPathFinder::SystemPathFinder(SystemPathFinder *this)

{
  return this;
}

// ===== SystemPathFinder::~SystemPathFinder  @0x00140630  (2 bytes)
/* SystemPathFinder::~SystemPathFinder() */

SystemPathFinder * __thiscall SystemPathFinder::~SystemPathFinder(SystemPathFinder *this)

{
  return this;
}

// ===== SystemPathFinder::getJumpDistance  @0x00140632  (42 bytes)
/* SystemPathFinder::getJumpDistance(Array<SolarSystem*>*, int, int) */

int __thiscall
SystemPathFinder::getJumpDistance(SystemPathFinder *this,Array *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)getSystemPath(this,param_1,param_2,param_3);
  if (piVar1 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *piVar1 + -1;
    if ((void *)piVar1[1] != (void *)0x0) {
      operator_delete__((void *)piVar1[1]);
    }
    operator_delete(piVar1);
  }
  return iVar2;
}

// ===== SystemPathFinder::getSystemPath  @0x0014065c  (372 bytes)
/* SystemPathFinder::getSystemPath(Array<SolarSystem*>*, int, int) */

Array * __thiscall
SystemPathFinder::getSystemPath(SystemPathFinder *this,Array *param_1,int param_2,int param_3)

{
  Array *pAVar1;
  undefined4 *puVar2;
  Node *this_00;
  uint *puVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  Array *pAVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  
  pAVar1 = operator_new(0xc);
  puVar2 = operator_new__(4);
  *(undefined4 **)(pAVar1 + 4) = puVar2;
  *(undefined4 *)(pAVar1 + 8) = 1;
  *puVar2 = 0;
  *(undefined4 *)pAVar1 = 0;
  ArraySetLength<Node*>(*(uint *)param_1,pAVar1);
  if (*(int *)param_1 != 0) {
    uVar9 = 0;
    do {
      this_00 = operator_new(0xc);
      Node::Node(this_00,uVar9);
      *(Node **)(*(int *)(pAVar1 + 4) + uVar9 * 4) = this_00;
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(uint *)param_1);
    if (*(uint *)param_1 != 0) {
      uVar9 = 0;
      do {
        puVar3 = (uint *)SolarSystem::getRoutes
                                   (*(SolarSystem **)(*(int *)(param_1 + 4) + uVar9 * 4));
        if ((puVar3 != (uint *)0x0) && (*puVar3 != 0)) {
          uVar10 = 0;
          do {
            iVar4 = Status::getSystemVisibilities(Globals::status);
            iVar5 = SolarSystem::getIndex
                              (*(SolarSystem **)
                                (*(int *)(param_1 + 4) + *(int *)(puVar3[1] + uVar10 * 4) * 4));
            if (*(char *)(*(int *)(iVar4 + 4) + iVar5) != '\0') {
              piVar8 = (int *)**(undefined4 **)(*(int *)(pAVar1 + 4) + uVar9 * 4);
              uVar11 = *(undefined4 *)(*(int *)(pAVar1 + 4) + *(int *)(puVar3[1] + uVar10 * 4) * 4);
              piVar8[2] = *piVar8 + 1;
              pvVar6 = realloc((void *)piVar8[1],(*piVar8 + 1) * 4);
              piVar8[1] = (int)pvVar6;
              *(undefined4 *)((int)pvVar6 + *piVar8 * 4) = uVar11;
              *piVar8 = piVar8[2];
            }
            uVar10 = uVar10 + 1;
          } while (uVar10 < *puVar3);
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < *(uint *)param_1);
    }
  }
  pAVar1 = (Array *)search(this,*(Node **)(*(int *)(pAVar1 + 4) + param_2 * 4),
                           *(Node **)(*(int *)(pAVar1 + 4) + param_3 * 4));
  if (pAVar1 == (Array *)0x0) {
    pAVar7 = (Array *)0x0;
  }
  else {
    if (*(int *)pAVar1 == 0) {
      pAVar7 = (Array *)0x0;
    }
    else {
      pAVar7 = operator_new(0xc);
      puVar2 = operator_new__(4);
      *(undefined4 **)(pAVar7 + 4) = puVar2;
      *(undefined4 *)(pAVar7 + 8) = 1;
      *puVar2 = 0;
      *(undefined4 *)pAVar7 = 0;
      ArraySetLength<int>(*(int *)pAVar1 + 1,pAVar7);
      piVar8 = *(int **)(pAVar7 + 4);
      *piVar8 = param_2;
      if (1 < *(uint *)pAVar7) {
        iVar4 = *(int *)(pAVar1 + 4);
        iVar5 = 0;
        do {
          piVar8[iVar5 + 1] = *(int *)(*(int *)(iVar4 + iVar5 * 4) + 8);
          uVar9 = iVar5 + 2;
          iVar5 = iVar5 + 1;
        } while (uVar9 < *(uint *)pAVar7);
      }
    }
    ArrayReleaseClasses<Node*>(pAVar1);
    if (*(void **)(pAVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)(pAVar1 + 4));
    }
    operator_delete(pAVar1);
  }
  return pAVar7;
}

// ===== SystemPathFinder::search  @0x00140820  (322 bytes)
/* SystemPathFinder::search(Node*, Node*) */

undefined4 __thiscall SystemPathFinder::search(SystemPathFinder *this,Node *param_1,Node *param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  Array *pAVar3;
  SystemPathFinder *this_00;
  void *pvVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  Node *pNVar11;
  
  puVar1 = operator_new(0xc);
  puVar2 = operator_new__(4);
  puVar1[1] = (uint)puVar2;
  *puVar2 = 0;
  puVar1[2] = 1;
  *puVar1 = 0;
  pAVar3 = operator_new(0xc);
  puVar2 = operator_new__(4);
  *(undefined4 **)(pAVar3 + 4) = puVar2;
  *(undefined4 *)pAVar3 = 0;
  *puVar2 = 0;
  *(undefined4 *)(pAVar3 + 8) = 1;
  puVar2 = realloc(puVar2,4);
  *(undefined4 **)(pAVar3 + 4) = puVar2;
  puVar2[*(int *)pAVar3] = param_1;
  iVar7 = *(int *)(pAVar3 + 8);
  *(int *)pAVar3 = iVar7;
  *(undefined4 *)(param_1 + 4) = 0;
  if (iVar7 == 0) {
    return 0;
  }
  while( true ) {
    pNVar11 = (Node *)*puVar2;
    ArrayRemove<Node*>(pNVar11,pAVar3);
    if (pNVar11 == param_2) {
      uVar6 = constructPath(this_00,param_2);
      return uVar6;
    }
    puVar1[2] = *puVar1 + 1;
    pvVar4 = realloc((void *)puVar1[1],(*puVar1 + 1) * 4);
    puVar1[1] = (uint)pvVar4;
    *(Node **)((int)pvVar4 + *puVar1 * 4) = pNVar11;
    uVar5 = puVar1[2];
    *puVar1 = uVar5;
    puVar8 = *(uint **)pNVar11;
    if (*puVar8 != 0) break;
LAB_00140944:
    if (*(int *)pAVar3 == 0) {
      return 0;
    }
    puVar2 = *(undefined4 **)(pAVar3 + 4);
  }
  uVar10 = 0;
  do {
    iVar7 = *(int *)(puVar8[1] + uVar10 * 4);
    if (uVar5 != 0) {
      uVar9 = 0;
      do {
        if (*(int *)(puVar1[1] + uVar9 * 4) == iVar7) goto LAB_0014093c;
        uVar9 = uVar9 + 1;
      } while (uVar9 < uVar5);
    }
    uVar5 = *(uint *)pAVar3;
    if (uVar5 == 0) {
      pvVar4 = *(void **)(pAVar3 + 4);
    }
    else {
      pvVar4 = *(void **)(pAVar3 + 4);
      uVar9 = 0;
      do {
        if (*(int *)((int)pvVar4 + uVar9 * 4) == iVar7) goto LAB_0014093c;
        uVar9 = uVar9 + 1;
      } while (uVar9 < uVar5);
    }
    *(Node **)(iVar7 + 4) = pNVar11;
    *(uint *)(pAVar3 + 8) = uVar5 + 1;
    pvVar4 = realloc(pvVar4,(uVar5 + 1) * 4);
    *(void **)(pAVar3 + 4) = pvVar4;
    *(int *)((int)pvVar4 + *(int *)pAVar3 * 4) = iVar7;
    *(undefined4 *)pAVar3 = *(undefined4 *)(pAVar3 + 8);
    puVar8 = *(uint **)pNVar11;
LAB_0014093c:
    uVar10 = uVar10 + 1;
    if (*puVar8 <= uVar10) goto LAB_00140944;
    uVar5 = *puVar1;
  } while( true );
}

// ===== SystemPathFinder::constructPath  @0x001409c8  (182 bytes)
/* SystemPathFinder::constructPath(Node*) */

Array * __thiscall SystemPathFinder::constructPath(SystemPathFinder *this,Node *param_1)

{
  int iVar1;
  uint *puVar2;
  undefined4 *puVar3;
  Array *pAVar4;
  void *pvVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  Node *pNVar9;
  uint uVar10;
  
  puVar2 = operator_new(0xc);
  puVar3 = operator_new__(4);
  uVar10 = 0;
  puVar2[1] = (uint)puVar3;
  puVar2[2] = 1;
  *puVar3 = 0;
  *puVar2 = 0;
  pNVar9 = param_1 + 4;
  if (*(int *)pNVar9 != 0) {
    uVar10 = 0;
    do {
      puVar2[2] = uVar10 + 1;
      puVar3 = realloc(puVar3,(uVar10 + 1) * 4);
      puVar2[1] = (uint)puVar3;
      uVar6 = *puVar2;
      uVar10 = puVar2[2];
      *puVar2 = uVar10;
      puVar3[uVar6] = param_1;
      param_1 = *(Node **)pNVar9;
      pNVar9 = param_1 + 4;
    } while (*(int *)pNVar9 != 0);
  }
  pAVar4 = operator_new(0xc);
  puVar3 = operator_new__(4);
  *(undefined4 **)(pAVar4 + 4) = puVar3;
  *(undefined4 *)(pAVar4 + 8) = 1;
  *puVar3 = 0;
  *(undefined4 *)pAVar4 = 0;
  ArraySetLength<Node*>(uVar10,pAVar4);
  pvVar5 = (void *)puVar2[1];
  iVar7 = *puVar2 - 1;
  if (-1 < iVar7) {
    iVar8 = 0;
    do {
      iVar1 = iVar7 * 4;
      iVar7 = iVar7 + -1;
      *(undefined4 *)(*(int *)(pAVar4 + 4) + iVar8) = *(undefined4 *)((int)pvVar5 + iVar1);
      iVar8 = iVar8 + 4;
      pvVar5 = (void *)puVar2[1];
    } while (iVar7 != -1);
  }
  if (pvVar5 != (void *)0x0) {
    operator_delete__(pvVar5);
  }
  puVar2[1] = 0;
  return pAVar4;
}

// ===== SystemPathFinder::contains  @0x00140ad4  (36 bytes)
/* SystemPathFinder::contains(Array<Node*>*, Node*) */

undefined4 __thiscall
SystemPathFinder::contains(SystemPathFinder *this,Array *param_1,Node *param_2)

{
  uint uVar1;
  
  if (*(uint *)param_1 != 0) {
    uVar1 = 0;
    do {
      if (*(Node **)(*(int *)(param_1 + 4) + uVar1 * 4) == param_2) {
        return 1;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)param_1);
  }
  return 0;
}

