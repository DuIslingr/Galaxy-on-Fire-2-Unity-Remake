// Class: Status
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Status::Status  @0x000b5c26  (602 bytes)
/* Status::Status() */

Status * __thiscall Status::Status(Status *this)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  Array *pAVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  Station *this_00;
  
  AbyssEngine::String::String((String *)(this + 0x168));
  pAVar4 = operator_new(0xc);
  puVar5 = operator_new__(4);
  *(undefined4 **)(pAVar4 + 4) = puVar5;
  *(undefined4 *)(pAVar4 + 8) = 1;
  *puVar5 = 0;
  *(undefined4 *)pAVar4 = 0;
  *(Array **)(this + 0x194) = pAVar4;
  puVar5 = operator_new(0xc);
  puVar6 = operator_new__(4);
  puVar5[1] = puVar6;
  puVar5[2] = 1;
  *puVar6 = 0;
  *puVar5 = 0;
  *(undefined4 **)(this + 0x19c) = puVar5;
  puVar5 = operator_new(0xc);
  puVar7 = operator_new__(1);
  puVar5[1] = puVar7;
  puVar5[2] = 1;
  *puVar7 = 0;
  *puVar5 = 0;
  *(undefined4 **)(this + 0x38) = puVar5;
  puVar5 = operator_new(0xc);
  puVar7 = operator_new__(1);
  puVar5[1] = puVar7;
  puVar5[2] = 1;
  *puVar7 = 0;
  *puVar5 = 0;
  *(undefined4 **)(this + 0x94) = puVar5;
  puVar5 = operator_new(0xc);
  puVar7 = operator_new__(1);
  puVar5[1] = puVar7;
  puVar5[2] = 1;
  *puVar7 = 0;
  *puVar5 = 0;
  *(undefined4 **)(this + 0x98) = puVar5;
  puVar5 = operator_new(0xc);
  puVar7 = operator_new__(1);
  puVar5[1] = puVar7;
  puVar5[2] = 1;
  *puVar7 = 0;
  *puVar5 = 0;
  *(undefined4 **)(this + 0xac) = puVar5;
  puVar5 = operator_new(0xc);
  puVar7 = operator_new__(1);
  puVar5[1] = puVar7;
  puVar5[2] = 1;
  *puVar7 = 0;
  *puVar5 = 0;
  *(undefined4 **)(this + 0xb4) = puVar5;
  puVar5 = operator_new(0xc);
  puVar7 = operator_new__(1);
  puVar5[1] = puVar7;
  puVar5[2] = 1;
  *puVar7 = 0;
  *puVar5 = 0;
  *(undefined4 **)(this + 0x4c) = puVar5;
  puVar5 = operator_new(0xc);
  puVar7 = operator_new__(1);
  puVar5[1] = puVar7;
  puVar5[2] = 1;
  *puVar7 = 0;
  *puVar5 = 0;
  *(undefined4 **)(this + 0x50) = puVar5;
  puVar5 = operator_new(0xc);
  puVar6 = operator_new__(4);
  puVar5[1] = puVar6;
  puVar5[2] = 1;
  *puVar6 = 0;
  *puVar5 = 0;
  *(undefined4 **)(this + 0x90) = puVar5;
  puVar5 = operator_new(0xc);
  puVar7 = operator_new__(1);
  puVar5[1] = puVar7;
  puVar5[2] = 1;
  *puVar7 = 0;
  *puVar5 = 0;
  *(undefined4 **)(this + 0x54) = puVar5;
  puVar5 = operator_new(0xc);
  puVar7 = operator_new__(1);
  puVar5[1] = puVar7;
  puVar5[2] = 1;
  *puVar7 = 0;
  *puVar5 = 0;
  *(undefined4 **)(this + 0x58) = puVar5;
  ArraySetLength<Mission*>(2,pAVar4);
  ArraySetLength<Station*>(3,*(Array **)(this + 0x19c));
  ArraySetLength<bool>(0x22,*(Array **)(this + 0x38));
  ArraySetLength<bool>(0xb,*(Array **)(this + 0x94));
  ArraySetLength<bool>(0xb,*(Array **)(this + 0x98));
  ArraySetLength<bool>(0x16,*(Array **)(this + 0xac));
  ArraySetLength<bool>(0x22,*(Array **)(this + 0xb4));
  ArraySetLength<bool>(4,*(Array **)(this + 0x4c));
  ArraySetLength<bool>(0xf,*(Array **)(this + 0x50));
  ArraySetLength<bool>(0xe9,*(Array **)(this + 0x54));
  ArraySetLength<bool>(5,*(Array **)(this + 0x58));
  *(undefined4 *)(this + 0x1c8) = 1;
  *(undefined4 *)(this + 0x1ac) = 0;
  *(undefined4 *)(this + 0x1b0) = 0;
  *(undefined4 *)(this + 0x1d0) = 0;
  *(undefined4 *)(this + 0x1e8) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x10c) = 0;
  this[0x110] = (Status)0x0;
  this[0x111] = (Status)0x0;
  *(undefined4 *)(this + 0x1b8) = 0;
  *(undefined4 *)(this + 0x1bc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x1c0) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x1c4) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  this_00 = operator_new(0x30);
  Station::Station(this_00);
  uVar1 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(Station **)(this + 0x78) = this_00;
  *(undefined4 *)(this + 0x8c) = 0;
  *(undefined4 *)(this + 0x18c) = 0;
  *(undefined4 *)(this + 400) = 0;
  *(undefined4 *)(this + 0x198) = 0;
  *(undefined4 *)(this + 0x1a0) = 0;
  *(undefined4 *)(this + 0x1a4) = 0;
  *(undefined4 *)(this + 0x1a8) = 0;
  *(undefined4 *)(this + 0x14c) = 0;
  *(undefined4 *)(this + 0x174) = 0;
  this[0x178] = (Status)0x0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = uVar1;
  *(undefined4 *)(this + 0x24) = uVar2;
  *(undefined4 *)(this + 0x28) = uVar3;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = uVar1;
  *(undefined4 *)(this + 8) = uVar2;
  *(undefined4 *)(this + 0xc) = uVar3;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = uVar1;
  *(undefined4 *)(this + 0x18) = uVar2;
  *(undefined4 *)(this + 0x1c) = uVar3;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x40) = uVar1;
  *(undefined4 *)(this + 0x44) = uVar2;
  *(undefined4 *)(this + 0x48) = uVar3;
  return this;
}

// ===== Status::~Status  @0x000b5f4c  (154 bytes)
/* Status::~Status() */

Status * __thiscall Status::~Status(Status *this)

{
  void *pvVar1;
  
  if (*(Ship **)(this + 0x18c) != (Ship *)0x0) {
    pvVar1 = (void *)Ship::~Ship(*(Ship **)(this + 0x18c));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x18c) = 0;
  if (*(Mission **)(this + 400) != (Mission *)0x0) {
    pvVar1 = (void *)Mission::~Mission(*(Mission **)(this + 400));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 400) = 0;
  if (*(Array **)(this + 0x20) != (Array *)0x0) {
    ArrayReleaseClasses<Agent*>(*(Array **)(this + 0x20));
    pvVar1 = *(void **)(this + 0x20);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x20) = 0;
  if (*(Array **)(this + 0x19c) != (Array *)0x0) {
    ArrayReleaseClasses<Station*>(*(Array **)(this + 0x19c));
    pvVar1 = *(void **)(this + 0x19c);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x19c) = 0;
  if (*(Array **)this != (Array *)0x0) {
    ArrayReleaseClasses<Wanted*>(*(Array **)this);
    pvVar1 = *(void **)this;
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)this = 0;
  AbyssEngine::String::~String((String *)(this + 0x168));
  return this;
}

// ===== Status::addPendingProduct  @0x000b606a  (170 bytes)
/* Status::addPendingProduct(BluePrint*) */

void __thiscall Status::addPendingProduct(Status *this,BluePrint *param_1)

{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  PendingProduct *this_00;
  void *pvVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  
  puVar1 = *(uint **)(this + 0x1c);
  if (puVar1 == (uint *)0x0) {
    puVar3 = operator_new(0xc);
    puVar4 = operator_new__(4);
    puVar3[1] = puVar4;
    puVar3[2] = 1;
    *puVar4 = 0;
    *puVar3 = 0;
    *(undefined4 **)(this + 0x1c) = puVar3;
  }
  else if (*puVar1 != 0) {
    uVar8 = 0;
    do {
      iVar2 = *(int *)(puVar1[1] + uVar8 * 4);
      if (((iVar2 != 0) &&
          (iVar7 = *(int *)(iVar2 + 0x10), iVar2 = BluePrint::getIndex(param_1), iVar7 == iVar2)) &&
         (iVar7 = *(int *)(*(int *)(*(int *)(*(int *)(this + 0x1c) + 4) + uVar8 * 4) + 8),
         iVar2 = BluePrint::getStationIndex(param_1), iVar7 == iVar2)) {
        iVar2 = BluePrint::getQuantity(param_1);
        iVar7 = *(int *)(*(int *)(*(int *)(this + 0x1c) + 4) + uVar8 * 4);
        *(int *)(iVar7 + 0xc) = iVar2 + *(int *)(iVar7 + 0xc);
        return;
      }
      puVar1 = *(uint **)(this + 0x1c);
      uVar8 = uVar8 + 1;
    } while (uVar8 < *puVar1);
  }
  this_00 = operator_new(0x14);
  PendingProduct::PendingProduct(this_00,param_1);
  piVar6 = *(int **)(this + 0x1c);
  piVar6[2] = *piVar6 + 1;
  pvVar5 = realloc((void *)piVar6[1],(*piVar6 + 1) * 4);
  piVar6[1] = (int)pvVar5;
  *(PendingProduct **)((int)pvVar5 + *piVar6 * 4) = this_00;
  *piVar6 = piVar6[2];
  return;
}

// ===== Status::getPendingProducts  @0x000b6124  (4 bytes)
/* Status::getPendingProducts() */

undefined4 __thiscall Status::getPendingProducts(Status *this)

{
  return *(undefined4 *)(this + 0x1c);
}

// ===== Status::getSystemVisibilities  @0x000b6128  (4 bytes)
/* Status::getSystemVisibilities() */

undefined4 __thiscall Status::getSystemVisibilities(Status *this)

{
  return *(undefined4 *)(this + 0x38);
}

// ===== Status::setSystemVisibility  @0x000b612c  (8 bytes)
/* Status::setSystemVisibility(int, bool) */

void __thiscall Status::setSystemVisibility(Status *this,int param_1,bool param_2)

{
  *(bool *)(*(int *)(*(int *)(this + 0x38) + 4) + param_1) = param_2;
  return;
}

// ===== Status::getStationStack  @0x000b6134  (6 bytes)
/* Status::getStationStack() */

undefined4 __thiscall Status::getStationStack(Status *this)

{
  return *(undefined4 *)(this + 0x19c);
}

// ===== Status::setStationStack  @0x000b613a  (6 bytes)
/* Status::setStationStack(Array<Station*>*) */

void __thiscall Status::setStationStack(Status *this,Array *param_1)

{
  *(Array **)(this + 0x19c) = param_1;
  return;
}

// ===== Status::addStationToStack  @0x000b6140  (120 bytes)
/* Status::addStationToStack(Station*) */

undefined4 __thiscall Status::addStationToStack(Status *this,Station *param_1)

{
  bool bVar1;
  Station *pSVar2;
  void *pvVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  pSVar2 = (Station *)isOnStack(this,param_1);
  if (pSVar2 == (Station *)0x0) {
    piVar5 = *(int **)(*(int *)(this + 0x19c) + 4);
    if (*piVar5 != 0) {
      if ((Station *)piVar5[2] != (Station *)0x0) {
        pvVar3 = (void *)Station::~Station((Station *)piVar5[2]);
        operator_delete(pvVar3);
        piVar5 = *(int **)(*(int *)(this + 0x19c) + 4);
      }
      iVar4 = 0;
      piVar5[2] = 0;
      iVar6 = *(int *)(this + 0x19c);
      do {
        iVar6 = *(int *)(iVar6 + 4) + iVar4 * 4;
        *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar6 + 4);
        iVar7 = iVar4 + 2;
        iVar6 = *(int *)(this + 0x19c);
        iVar4 = iVar4 + -1;
      } while (1 < iVar7);
      **(undefined4 **)(iVar6 + 4) = param_1;
LAB_000b61ac:
      setStation(this,param_1);
      return 1;
    }
    iVar4 = 2;
    do {
      if (piVar5[iVar4] == 0) {
        piVar5[iVar4] = (int)param_1;
        goto LAB_000b61ac;
      }
      bVar1 = 0 < iVar4;
      iVar4 = iVar4 + -1;
    } while (bVar1);
  }
  else {
    setStation(this,pSVar2);
  }
  return 0;
}

// ===== Status::isOnStack  @0x000b61b8  (58 bytes)
/* Status::isOnStack(Station*) */

undefined4 __thiscall Status::isOnStack(Status *this,Station *param_1)

{
  Station *this_00;
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while ((this_00 = *(Station **)(*(int *)(*(int *)(this + 0x19c) + 4) + iVar2 * 4),
         this_00 == (Station *)0x0 || (iVar1 = Station::equals(this_00,param_1), iVar1 == 0))) {
    iVar2 = iVar2 + 1;
    if (2 < iVar2) {
      return 0;
    }
  }
  return *(undefined4 *)(*(int *)(*(int *)(this + 0x19c) + 4) + iVar2 * 4);
}

// ===== Status::setStation  @0x000b61f4  (460 bytes)
/* Status::setStation(Station*) */

void __thiscall Status::setStation(Status *this,Station *param_1)

{
  Galaxy *this_00;
  int iVar1;
  FileRead *this_01;
  Array *pAVar2;
  void *pvVar3;
  Array *pAVar4;
  undefined4 *puVar5;
  int *piVar6;
  String *this_02;
  undefined4 uVar7;
  uint *puVar8;
  int iVar9;
  void *pvVar10;
  Station *this_03;
  int iVar11;
  uint uVar12;
  uint uVar13;
  
  if (*(Station **)(this + 0x198) != param_1) {
    *(Station **)(this + 0x198) = param_1;
    this_00 = Globals::galaxy;
    iVar1 = Station::getSystem(param_1);
    iVar1 = Galaxy::getSystem(this_00,iVar1);
    *(int *)(this + 0x1a0) = iVar1;
    if (iVar1 != 0) {
      iVar9 = *(int *)(this + 0xb4);
      iVar1 = Station::getSystem(*(Station **)(this + 0x198));
      *(undefined1 *)(*(int *)(iVar9 + 4) + iVar1) = 1;
      this_01 = operator_new(1);
      FileRead::FileRead(this_01);
      pAVar2 = (Array *)FileRead::loadStationsBinary(this_01,*(SolarSystem **)(this + 0x1a0));
      pvVar3 = (void *)FileRead::~FileRead(this_01);
      operator_delete(pvVar3);
      if (*(Array **)(this + 0x1a4) != (Array *)0x0) {
        ArrayReleaseClasses<AbyssEngine::String*>(*(Array **)(this + 0x1a4));
        pvVar3 = *(void **)(this + 0x1a4);
        if (pvVar3 != (void *)0x0) {
          if (*(void **)((int)pvVar3 + 4) != (void *)0x0) {
            operator_delete__(*(void **)((int)pvVar3 + 4));
          }
          operator_delete(pvVar3);
        }
      }
      *(undefined4 *)(this + 0x1a4) = 0;
      pAVar4 = operator_new(0xc);
      puVar5 = operator_new__(4);
      *(undefined4 **)(pAVar4 + 4) = puVar5;
      *(undefined4 *)(pAVar4 + 8) = 1;
      *puVar5 = 0;
      *(undefined4 *)pAVar4 = 0;
      *(Array **)(this + 0x1a4) = pAVar4;
      ArraySetLength<AbyssEngine::String*>(*(uint *)pAVar2,pAVar4);
      pvVar3 = *(void **)(this + 0x1a8);
      if (pvVar3 != (void *)0x0) {
        if (*(void **)((int)pvVar3 + 4) == (void *)0x0) {
          *(undefined4 *)((int)pvVar3 + 4) = 0;
        }
        else {
          operator_delete__(*(void **)((int)pvVar3 + 4));
          pvVar10 = *(void **)(this + 0x1a8);
          *(undefined4 *)((int)pvVar3 + 4) = 0;
          pvVar3 = pvVar10;
          if (pvVar10 == (void *)0x0) goto LAB_000b62da;
        }
        if (*(void **)((int)pvVar3 + 4) != (void *)0x0) {
          operator_delete__(*(void **)((int)pvVar3 + 4));
        }
        operator_delete(pvVar3);
      }
LAB_000b62da:
      *(undefined4 *)(this + 0x1a8) = 0;
      pAVar4 = operator_new(0xc);
      puVar5 = operator_new__(4);
      *(undefined4 **)(pAVar4 + 4) = puVar5;
      *(undefined4 *)(pAVar4 + 8) = 1;
      *puVar5 = 0;
      *(undefined4 *)pAVar4 = 0;
      *(Array **)(this + 0x1a8) = pAVar4;
      ArraySetLength<int>(*(uint *)pAVar2,pAVar4);
      iVar1 = SolarSystem::getStations(*(SolarSystem **)(this + 0x1a0));
      piVar6 = (int *)SolarSystem::getStations(*(SolarSystem **)(this + 0x1a0));
      if (*piVar6 != 0) {
        uVar13 = 0;
        do {
          if (*(int *)pAVar2 != 0) {
            uVar12 = 0;
            do {
              this_03 = *(Station **)(*(int *)(pAVar2 + 4) + uVar12 * 4);
              iVar11 = *(int *)(*(int *)(iVar1 + 4) + uVar13 * 4);
              iVar9 = Station::getIndex(this_03);
              if (iVar11 == iVar9) {
                iVar9 = *(int *)(this + 0x1e8);
                this_02 = operator_new(8);
                if (iVar9 == 0) {
                  AbyssEngine::String::String(this_02);
                }
                else {
                  Station::getName();
                }
                *(String **)(*(int *)(*(int *)(this + 0x1a4) + 4) + uVar13 * 4) = this_02;
                uVar7 = Station::getTextureIndex(this_03);
                *(undefined4 *)(*(int *)(*(int *)(this + 0x1a8) + 4) + uVar13 * 4) = uVar7;
                break;
              }
              uVar12 = uVar12 + 1;
            } while (uVar12 < *(uint *)pAVar2);
          }
          puVar8 = (uint *)SolarSystem::getStations(*(SolarSystem **)(this + 0x1a0));
          uVar13 = uVar13 + 1;
        } while (uVar13 < *puVar8);
      }
      ArrayReleaseClasses<Station*>(pAVar2);
      if (*(void **)(pAVar2 + 4) != (void *)0x0) {
        operator_delete__(*(void **)(pAVar2 + 4));
      }
      *(undefined4 *)(pAVar2 + 4) = 0;
      operator_delete(pAVar2);
      return;
    }
  }
  return;
}

// ===== Status::departStation  @0x000b63e0  (1026 bytes)
/* Status::departStation(Station*) */

void __thiscall Status::departStation(Status *this,Station *param_1)

{
  AERandom *this_00;
  int iVar1;
  Array *pAVar2;
  Generator *this_01;
  uint *puVar3;
  Mission *this_02;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  Item *this_03;
  SolarSystem *this_04;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  Station *pSVar10;
  Ship *this_05;
  bool bVar11;
  bool bVar12;
  
  iVar1 = Station::equals(*(Station **)(this + 0x198),*(Station **)(this + 0x78));
  if (iVar1 == 0) {
    iVar1 = Station::getIndex(*(Station **)(this + 0x198));
    bVar11 = iVar1 == 0x6c;
    if (bVar11) {
      iVar1 = *(int *)(this + 0x114);
    }
    if (bVar11 && iVar1 == 3) {
      pSVar10 = *(Station **)(this + 0x14c);
      pAVar2 = (Array *)Station::getItems(*(Station **)(this + 0x198));
      Station::setItems(pSVar10,pAVar2,true);
      pSVar10 = *(Station **)(this + 0x14c);
      pAVar2 = (Array *)Station::getShips(*(Station **)(this + 0x198));
      Station::setShips(pSVar10,pAVar2,true);
    }
  }
  iVar1 = Station::equals(*(Station **)(this + 0x198),*(Station **)(this + 0x78));
  if (iVar1 == 0) {
    bVar11 = false;
    if (*(Station **)(this + 0x78) != param_1) {
      iVar1 = Station::getIndex(param_1);
      iVar4 = Station::getIndex(*(Station **)(this + 0x198));
      if (iVar1 != iVar4) {
        bVar11 = true;
      }
    }
  }
  else {
    bVar11 = false;
  }
  if (*(Station **)(this + 0x78) != param_1) {
    pSVar10 = (Station *)isOnStack(this,param_1);
    addStationToStack(this,param_1);
    iVar1 = Station::getIndex(param_1);
    bVar12 = iVar1 == 0x6c;
    if (bVar12) {
      iVar1 = *(int *)(this + 0x114);
    }
    if (bVar12 && iVar1 == 3) {
      pAVar2 = (Array *)Station::getItems(*(Station **)(this + 0x14c));
      Station::setItems(param_1,pAVar2,true);
      pAVar2 = (Array *)Station::getShips(*(Station **)(this + 0x14c));
      Station::setShips(param_1,pAVar2,true);
      if ((pSVar10 != (Station *)0x0) && (pSVar10 != param_1)) {
        pAVar2 = (Array *)Station::getItems(*(Station **)(this + 0x14c));
        Station::setItems(pSVar10,pAVar2,true);
        pAVar2 = (Array *)Station::getShips(*(Station **)(this + 0x14c));
        Station::setShips(pSVar10,pAVar2,true);
      }
      if (pSVar10 == (Station *)0x0) {
        this_01 = operator_new(1);
        Generator::Generator(this_01);
        goto LAB_000b652a;
      }
    }
    else if (pSVar10 == (Station *)0x0) {
      this_01 = operator_new(1);
      Generator::Generator(this_01);
      pAVar2 = (Array *)Generator::getItemBuyList(this_01,param_1);
      Station::setItems(param_1,pAVar2,false);
      pAVar2 = (Array *)Generator::getShipBuyList(this_01,param_1);
      Station::setShips(param_1,pAVar2,false);
LAB_000b652a:
      pAVar2 = (Array *)Generator::createAgents(this_01,param_1);
      Station::setAgents(param_1,pAVar2);
    }
    *(undefined4 *)(this + 0x70) = *(undefined4 *)(this + 0x1b8);
    *(undefined4 *)(this + 0x74) = *(undefined4 *)(this + 0x1bc);
  }
  *(undefined4 *)(this + 400) = Mission::empty;
  puVar3 = *(uint **)(this + 0x194);
  if (*puVar3 != 0) {
    uVar8 = 0;
    while( true ) {
      this_02 = *(Mission **)(puVar3[1] + uVar8 * 4);
      if (this_02 == (Mission *)0x0) goto LAB_000b6688;
      iVar1 = Mission::getType(this_02);
      iVar4 = Mission::isCampaignMission
                        (*(Mission **)(*(int *)(*(int *)(this + 0x194) + 4) + uVar8 * 4));
      if (iVar1 == 0xad && iVar4 == 1) break;
LAB_000b65c2:
      if ((((*(int *)(Globals::status + 0x1e8) < 0x2d) &&
           (iVar4 = Mission::isCampaignMission
                              (*(Mission **)(*(int *)(*(int *)(this + 0x194) + 4) + uVar8 * 4)),
           iVar1 == 0xa1 && iVar4 == 1)) &&
          (iVar4 = Station::getIndex(param_1), iVar4 == *(int *)(this + 0x80))) &&
         (iVar4 = Station::equals(*(Station **)(Globals::status + 0x198),
                                  *(Station **)(Globals::status + 0x78)), iVar4 == 0))
      goto LAB_000b66b8;
      iVar4 = Mission::isEmpty(*(Mission **)(*(int *)(*(int *)(this + 0x194) + 4) + uVar8 * 4));
      if (iVar4 == 0) {
        iVar4 = Mission::getTargetStation
                          (*(Mission **)(*(int *)(*(int *)(this + 0x194) + 4) + uVar8 * 4));
        iVar5 = Station::getIndex(param_1);
        if (((iVar4 == iVar5) &&
            ((0x17 < iVar1 - 0x96U || ((1 << (iVar1 - 0x96U & 0xff) & 0x8b782bU) == 0)))) &&
           (iVar1 != 8 && iVar1 != 0xe)) {
          iVar4 = Mission::isCampaignMission
                            (*(Mission **)(*(int *)(*(int *)(this + 0x194) + 4) + uVar8 * 4));
          if ((iVar4 != 0) || ((iVar1 != 0xb && (iVar1 != 0xd)))) goto LAB_000b66b8;
          goto LAB_000b66c6;
        }
      }
      iVar4 = Mission::isEmpty(*(Mission **)(*(int *)(*(int *)(this + 0x194) + 4) + uVar8 * 4));
      if ((iVar4 == 0) &&
         (iVar4 = Mission::isCampaignMission
                            (*(Mission **)(*(int *)(*(int *)(this + 0x194) + 4) + uVar8 * 4)),
         iVar4 == 1)) {
        iVar4 = Mission::getTargetStation
                          (*(Mission **)(*(int *)(*(int *)(this + 0x194) + 4) + uVar8 * 4));
        iVar5 = Station::getIndex(param_1);
        if ((iVar1 == 0xa0) && (iVar4 != iVar5)) goto LAB_000b66b8;
      }
LAB_000b6688:
      puVar3 = *(uint **)(this + 0x194);
      uVar8 = uVar8 + 1;
      if (*puVar3 <= uVar8) goto LAB_000b66c6;
    }
    this_05 = *(Ship **)(Globals::status + 0x18c);
    iVar4 = Mission::getProductionGoodIndex
                      (*(Mission **)(*(int *)(*(int *)(this + 0x194) + 4) + uVar8 * 4));
    iVar4 = Ship::hasCargo(this_05,iVar4,1);
    if (iVar4 != 1) goto LAB_000b65c2;
LAB_000b66b8:
    *(undefined4 *)(this + 400) = *(undefined4 *)(*(int *)(*(int *)(this + 0x194) + 4) + uVar8 * 4);
  }
LAB_000b66c6:
  if (*(int *)(this + 0x1e8) < 0x2d) {
    if (*(int *)(this + 0x1e8) < 0x20) {
LAB_000b66fa:
      if (*(int *)(this + 0x1e8) < 0x2d) goto LAB_000b670e;
      goto LAB_000b6702;
    }
    iVar1 = Station::getIndex(param_1);
    iVar4 = Mission::getTargetStation((Mission *)**(undefined4 **)(*(int *)(this + 0x194) + 4));
    if ((iVar1 == iVar4) || (iVar1 = Station::getIndex(param_1), iVar1 == *(int *)(this + 0x80)))
    goto LAB_000b66fa;
    iVar1 = *(int *)(this + 0x88);
    *(int *)(this + 0x88) = iVar1 + 1;
    if (iVar1 < 10) goto LAB_000b670e;
    *(undefined4 *)(this + 0x88) = 0;
    do {
      do {
        iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x16);
        *(int *)(this + 0x7c) = iVar1;
      } while (*(char *)(*(int *)(*(int *)(this + 0x38) + 4) + iVar1) == '\0');
    } while ((iVar1 == 10 || iVar1 == 0xf) ||
            ((iVar1 = Mission::isCampaignMission(*(Mission **)(this + 400)), iVar1 == 1 &&
             (iVar1 = Mission::getTargetStation(*(Mission **)(this + 400)),
             iVar1 == *(int *)(this + 0x80)))));
    this_04 = (SolarSystem *)Galaxy::getSystem(Globals::galaxy,*(int *)(this + 0x7c));
    iVar1 = SolarSystem::getStations(this_04);
    this_00 = Globals::rnd;
    piVar7 = (int *)SolarSystem::getStations(this_04);
    iVar4 = AbyssEngine::AERandom::nextInt(this_00,*piVar7);
    uVar6 = *(undefined4 *)(*(int *)(iVar1 + 4) + iVar4 * 4);
  }
  else {
LAB_000b6702:
    uVar6 = 0xfffffff6;
    *(undefined4 *)(this + 0x7c) = 0xfffffff6;
  }
  *(undefined4 *)(this + 0x80) = uVar6;
LAB_000b670e:
  if (bVar11) {
    moveWanted(this);
  }
  puVar3 = (uint *)Ship::getCargo(*(Ship **)(this + 0x18c));
  if ((puVar3 != (uint *)0x0) && (uVar8 = *puVar3, uVar8 != 0)) {
    uVar9 = 0;
    do {
      this_03 = *(Item **)(puVar3[1] + uVar9 * 4);
      if (this_03 != (Item *)0x0) {
        Item::setStationAmount(this_03,0);
        uVar8 = *puVar3;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < uVar8);
  }
  this[0x108] = (Status)0x0;
  Ship::refreshValue(*(Ship **)(this + 0x18c));
  return;
}

// ===== Status::inAlienOrbit  @0x000b6810  (12 bytes)
/* Status::inAlienOrbit() */

void __thiscall Status::inAlienOrbit(Status *this)

{
  Station::equals(*(Station **)(this + 0x198),*(Station **)(this + 0x78));
  return;
}

// ===== Status::getStation  @0x000b681a  (6 bytes)
/* Status::getStation() */

undefined4 __thiscall Status::getStation(Status *this)

{
  return *(undefined4 *)(this + 0x198);
}

// ===== Status::getPlayingTime  @0x000b6820  (6 bytes)
/* Status::getPlayingTime() */

undefined8 __thiscall Status::getPlayingTime(Status *this)

{
  return *(undefined8 *)(this + 0x1b8);
}

// ===== Status::setMission  @0x000b6826  (6 bytes)
/* Status::setMission(Mission*) */

void __thiscall Status::setMission(Status *this,Mission *param_1)

{
  *(Mission **)(this + 400) = param_1;
  return;
}

// ===== Status::getShip  @0x000b682c  (6 bytes)
/* Status::getShip() */

undefined4 __thiscall Status::getShip(Status *this)

{
  return *(undefined4 *)(this + 0x18c);
}

// ===== Status::gameWon  @0x000b6832  (14 bytes)
/* Status::gameWon() */

bool __thiscall Status::gameWon(Status *this)

{
  return 0x2c < *(int *)(this + 0x1e8);
}

// ===== Status::getCurrentCampaignMission  @0x000b6840  (6 bytes)
/* Status::getCurrentCampaignMission() */

undefined4 __thiscall Status::getCurrentCampaignMission(Status *this)

{
  return *(undefined4 *)(this + 0x1e8);
}

// ===== Status::getCampaignMission  @0x000b6846  (10 bytes)
/* Status::getCampaignMission() */

undefined4 __thiscall Status::getCampaignMission(Status *this)

{
  return **(undefined4 **)(*(int *)(this + 0x194) + 4);
}

// ===== Status::getMission  @0x000b6850  (6 bytes)
/* Status::getMission() */

undefined4 __thiscall Status::getMission(Status *this)

{
  return *(undefined4 *)(this + 400);
}

// ===== Status::moveWanted  @0x000b6858  (868 bytes)
/* Status::moveWanted() */

void __thiscall Status::moveWanted(Status *this)

{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  FileRead *this_00;
  Station *this_01;
  Station *this_02;
  int iVar5;
  int iVar6;
  void *pvVar7;
  uint uVar8;
  Wanted *pWVar9;
  uint uVar10;
  SystemPathFinder *this_03;
  Array *local_2c;
  uint local_28;
  
  puVar2 = *(uint **)this;
  if (*puVar2 == 0) {
    return;
  }
  this_03 = (SystemPathFinder *)0x0;
  local_2c = (Array *)0x0;
  uVar8 = 0;
  bVar1 = false;
LAB_000b68aa:
  iVar3 = Wanted::isActive(*(Wanted **)(puVar2[1] + uVar8 * 4));
  if (((iVar3 == 1) &&
      (iVar3 = Wanted::isTerminated(*(Wanted **)(*(int *)(*(int *)this + 4) + uVar8 * 4)),
      iVar3 == 0)) &&
     (iVar3 = Station::equals(*(Station **)(Globals::status + 0x198),
                              *(Station **)(Globals::status + 0x78)), iVar3 == 0)) {
    iVar3 = Wanted::getCurrentLocation(*(Wanted **)(*(int *)(*(int *)this + 4) + uVar8 * 4));
    iVar4 = Station::getIndex(*(Station **)(Globals::status + 0x198));
    if (iVar3 == iVar4) goto LAB_000b6b7a;
    if (Level::programmedStation != (Station *)0x0) {
      iVar3 = Station::getIndex(Level::programmedStation);
      iVar4 = Wanted::getCurrentLocation(*(Wanted **)(*(int *)(*(int *)this + 4) + uVar8 * 4));
      if (iVar3 == iVar4) goto LAB_000b6b7a;
    }
    if (!bVar1) {
      this_00 = operator_new(1);
      FileRead::FileRead(this_00);
      local_2c = (Array *)FileRead::loadSystemsBinary();
      pvVar7 = (void *)FileRead::~FileRead(this_00);
      operator_delete(pvVar7);
      this_03 = operator_new(1);
      SystemPathFinder::SystemPathFinder(this_03);
    }
    iVar3 = Wanted::getCurrentLocation(*(Wanted **)(*(int *)(*(int *)this + 4) + uVar8 * 4));
    this_01 = (Station *)FileRead::loadStation((FileRead *)0x0,iVar3);
    iVar3 = Station::getSystem(this_01);
    iVar4 = Wanted::getTravelsTo(*(Wanted **)(*(int *)(*(int *)this + 4) + uVar8 * 4));
    this_02 = (Station *)FileRead::loadStation((FileRead *)0x0,iVar4);
    iVar4 = Station::getSystem(this_02);
    iVar5 = Station::getIndex(this_01);
    iVar6 = Station::getIndex(this_02);
    if (iVar5 == iVar6) {
      if ((int)uVar8 < 2) {
        local_28 = 4;
        uVar10 = 2;
      }
      else {
        iVar4 = (int)(uVar8 - 1) % 6;
        local_28 = iVar4 / 2 + 4;
        uVar10 = iVar4 / 3 + 2;
      }
      pWVar9 = *(Wanted **)(*(int *)(*(int *)this + 4) + uVar8 * 4);
      iVar4 = Wanted::getCurrentLocation(pWVar9);
      Wanted::setLastSeen(pWVar9,iVar4);
      if (this_02 != (Station *)0x0) {
        pvVar7 = (void *)Station::~Station(this_02);
        operator_delete(pvVar7);
      }
LAB_000b6a4c:
      this_02 = (Station *)Globals::getRandomStation();
      iVar4 = Station::getSystem(this_02);
      puVar2 = (uint *)SystemPathFinder::getSystemPath(this_03,local_2c,iVar3,iVar4);
      iVar4 = Station::getSystem(this_02);
      iVar4 = SolarSystem::getRoutes(*(SolarSystem **)(*(int *)(local_2c + 4) + iVar4 * 4));
      if ((((puVar2 != (uint *)0x0) && (iVar4 != 0)) &&
          ((uVar10 <= *puVar2 &&
           ((*puVar2 <= local_28 &&
            (iVar5 = *(int *)(Globals::status + 0x38), iVar4 = Station::getSystem(this_02),
            *(char *)(*(int *)(iVar5 + 4) + iVar4) != '\0')))))) &&
         ((iVar4 = Station::getSystem(this_02), iVar4 != 0x1b &&
          ((((iVar4 = Station::getSystem(this_02), iVar4 != 0x1c &&
             (iVar4 = Station::getSystem(this_02), iVar4 != 0x19)) &&
            (iVar4 = Station::getSystem(this_02), iVar4 != 0x1a)) &&
           (iVar4 = Station::getSystem(this_02), iVar4 != 6)))))) {
        iVar4 = Station::getSystem(this_02);
        iVar5 = Station::getSystem(this_01);
        if (iVar4 != iVar5) goto LAB_000b6afe;
      }
      if (this_02 != (Station *)0x0) {
        pvVar7 = (void *)Station::~Station(this_02);
        operator_delete(pvVar7);
      }
      goto LAB_000b6a4c;
    }
    if (iVar3 == iVar4) {
      pWVar9 = *(Wanted **)(*(int *)(*(int *)this + 4) + uVar8 * 4);
      iVar3 = Wanted::getTravelsTo(pWVar9);
      Wanted::setCurrentLocation(pWVar9,iVar3);
      puVar2 = (uint *)0x0;
    }
    else {
      puVar2 = (uint *)SystemPathFinder::getSystemPath(this_03,local_2c,iVar3,iVar4);
      iVar3 = SolarSystem::getWarpGateIndex
                        (*(SolarSystem **)(*(int *)(local_2c + 4) + *(int *)(puVar2[1] + 4) * 4));
      Wanted::setCurrentLocation(*(Wanted **)(*(int *)(*(int *)this + 4) + uVar8 * 4),iVar3);
    }
    goto LAB_000b6b4c;
  }
  goto LAB_000b6b7a;
LAB_000b6afe:
  pWVar9 = *(Wanted **)(*(int *)(*(int *)this + 4) + uVar8 * 4);
  iVar3 = Station::getIndex(this_02);
  Wanted::setTravelsTo(pWVar9,iVar3);
LAB_000b6b4c:
  if (this_02 != (Station *)0x0) {
    pvVar7 = (void *)Station::~Station(this_02);
    operator_delete(pvVar7);
  }
  if (this_01 != (Station *)0x0) {
    pvVar7 = (void *)Station::~Station(this_01);
    operator_delete(pvVar7);
  }
  if (puVar2 != (uint *)0x0) {
    if ((void *)puVar2[1] != (void *)0x0) {
      operator_delete__((void *)puVar2[1]);
    }
    operator_delete(puVar2);
  }
  bVar1 = true;
LAB_000b6b7a:
  puVar2 = *(uint **)this;
  uVar8 = uVar8 + 1;
  if (*puVar2 <= uVar8) {
    if (local_2c != (Array *)0x0) {
      ArrayReleaseClasses<SolarSystem*>(local_2c);
      if (*(void **)(local_2c + 4) != (void *)0x0) {
        operator_delete__(*(void **)(local_2c + 4));
      }
      operator_delete(local_2c);
    }
    if (this_03 == (SystemPathFinder *)0x0) {
      return;
    }
    pvVar7 = (void *)SystemPathFinder::~SystemPathFinder(this_03);
    operator_delete(pvVar7);
    return;
  }
  goto LAB_000b68aa;
}

// ===== Status::getPassengers  @0x000b6be8  (4 bytes)
/* Status::getPassengers() */

undefined4 __thiscall Status::getPassengers(Status *this)

{
  return *(undefined4 *)(this + 0x34);
}

// ===== Status::setPassengers  @0x000b6bec  (4 bytes)
/* Status::setPassengers(int) */

void __thiscall Status::setPassengers(Status *this,int param_1)

{
  *(int *)(this + 0x34) = param_1;
  return;
}

// ===== Status::getMissions  @0x000b6bf0  (6 bytes)
/* Status::getMissions() */

undefined4 __thiscall Status::getMissions(Status *this)

{
  return *(undefined4 *)(this + 0x194);
}

// ===== Status::getFreelanceMission  @0x000b6bf6  (10 bytes)
/* Status::getFreelanceMission() */

undefined4 __thiscall Status::getFreelanceMission(Status *this)

{
  return *(undefined4 *)(*(int *)(*(int *)(this + 0x194) + 4) + 4);
}

// ===== Status::setFreelanceMission  @0x000b6c00  (10 bytes)
/* Status::setFreelanceMission(Mission*) */

void __thiscall Status::setFreelanceMission(Status *this,Mission *param_1)

{
  *(Mission **)(*(int *)(*(int *)(this + 0x194) + 4) + 4) = param_1;
  return;
}

// ===== Status::setCampaignMission  @0x000b6c0c  (66 bytes)
/* Status::setCampaignMission(Mission*) */

void __thiscall Status::setCampaignMission(Status *this,Mission *param_1)

{
  Mission *this_00;
  void *pvVar1;
  undefined4 *puVar2;
  
  Mission::setCampaignMission(param_1,true);
  puVar2 = *(undefined4 **)(*(int *)(this + 0x194) + 4);
  this_00 = (Mission *)*puVar2;
  if ((this_00 != (Mission *)0x0) && (this_00 != Mission::empty)) {
    pvVar1 = (void *)Mission::~Mission(this_00);
    operator_delete(pvVar1);
    **(undefined4 **)(*(int *)(this + 0x194) + 4) = 0;
    puVar2 = *(undefined4 **)(*(int *)(this + 0x194) + 4);
  }
  *puVar2 = param_1;
  return;
}

// ===== Status::getNumberOfMissions  @0x000b6c54  (44 bytes)
/* Status::getNumberOfMissions() */

int __thiscall Status::getNumberOfMissions(Status *this)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  puVar2 = *(uint **)(this + 0x194);
  if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
    uVar4 = 0;
    iVar3 = 0;
    do {
      iVar1 = uVar4 * 4;
      uVar4 = uVar4 + 1;
      if (*(int *)(puVar2[1] + iVar1) != 0) {
        iVar3 = iVar3 + 1;
      }
    } while (uVar4 < *puVar2);
    return iVar3;
  }
  return 0;
}

// ===== Status::getMaxMissions  @0x000b6c80  (4 bytes)
/* Status::getMaxMissions() */

undefined4 Status::getMaxMissions(void)

{
  return 2;
}

// ===== Status::incMissionCount  @0x000b6c84  (12 bytes)
/* Status::incMissionCount() */

void __thiscall Status::incMissionCount(Status *this)

{
  *(int *)(this + 0x1c4) = *(int *)(this + 0x1c4) + 1;
  return;
}

// ===== Status::setCurrentCampaignMission  @0x000b6c90  (6 bytes)
/* Status::setCurrentCampaignMission(int) */

void __thiscall Status::setCurrentCampaignMission(Status *this,int param_1)

{
  *(int *)(this + 0x1e8) = param_1;
  return;
}

// ===== Status::nextCampaignMission  @0x000b6c98  (7840 bytes)
/* Status::nextCampaignMission(bool) */

void Status::nextCampaignMission(bool param_1)

{
  int *piVar1;
  Status *this;
  Array *pAVar2;
  undefined4 *puVar3;
  uint *puVar4;
  Item *pIVar5;
  Mission *pMVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  Station *pSVar11;
  uint uVar12;
  void *pvVar13;
  BluePrint *pBVar14;
  Ship *pSVar15;
  Status *pSVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined8 uVar19;
  
  this = (Status *)(uint)param_1;
  uVar17 = *(undefined4 *)(this + 0x1b8);
  uVar18 = *(undefined4 *)(this + 0x1bc);
  pSVar16 = this + 0x100;
  iVar10 = *(int *)(this + 0x1e8);
switchD_000b6cd8_caseD_34:
  iVar9 = iVar10;
  iVar10 = iVar9 + 1;
  iVar7 = 0;
  do {
    piVar1 = &DAT_00252b00 + iVar7;
    iVar7 = iVar7 + 1;
    if (iVar10 == *piVar1) {
      this[0x178] = (Status)0x1;
    }
  } while (iVar7 != 3);
  switch(iVar9) {
  case 0:
    goto switchD_000b6cd8_caseD_0;
  case 1:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0x9a,0,0x4e);
    setCampaignMission(this,pMVar6);
    goto LAB_000b762e;
  case 2:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x4e);
    goto LAB_000b6e46;
  case 3:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    Ship::setCargo(*(Ship **)(this + 0x18c),(Array *)0x0);
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0x9a,0,0x4e);
    setCampaignMission(this,pMVar6);
    iVar10 = *(int *)(this + 0x194);
    uVar8 = 0x19;
    goto LAB_000b8cbc;
  case 4:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x4e);
    goto LAB_000b6e46;
  case 5:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    Ship::removeAllCargo(*(Ship **)(this + 0x18c));
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0x9e,0,0x4e);
    goto LAB_000b6e46;
  case 6:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x4e);
    goto LAB_000b6e46;
  case 7:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    uVar19 = Ship::getEquipment(*(Ship **)(this + 0x18c));
    uVar8 = (uint)((ulonglong)uVar19 >> 0x20);
    puVar4 = (uint *)uVar19;
    if (puVar4 != (uint *)0x0) {
      uVar8 = *puVar4;
    }
    if (puVar4 != (uint *)0x0 && uVar8 != 0) {
      uVar12 = 0;
      do {
        pIVar5 = *(Item **)(puVar4[1] + uVar12 * 4);
        if (pIVar5 != (Item *)0x0) {
          Item::setUnsaleable(pIVar5,false);
          pIVar5 = *(Item **)(puVar4[1] + uVar12 * 4);
          iVar10 = Item::getSinglePrice(*(Item **)(*(int *)(Globals::items + 4) + uVar12 * 4));
          Item::setPrice(pIVar5,iVar10);
          uVar8 = *puVar4;
        }
        uVar12 = uVar12 + 1;
      } while (uVar12 < uVar8);
    }
    uVar19 = Ship::getCargo(*(Ship **)(this + 0x18c));
    uVar8 = (uint)((ulonglong)uVar19 >> 0x20);
    puVar4 = (uint *)uVar19;
    if (puVar4 != (uint *)0x0) {
      uVar8 = *puVar4;
    }
    if (puVar4 != (uint *)0x0 && uVar8 != 0) {
      uVar12 = 0;
      do {
        pIVar5 = *(Item **)(puVar4[1] + uVar12 * 4);
        if (pIVar5 != (Item *)0x0) {
          Item::setUnsaleable(pIVar5,false);
          pIVar5 = *(Item **)(puVar4[1] + uVar12 * 4);
          iVar10 = Item::getSinglePrice(*(Item **)(*(int *)(Globals::items + 4) + uVar12 * 4));
          Item::setPrice(pIVar5,iVar10);
          uVar8 = *puVar4;
        }
        uVar12 = uVar12 + 1;
      } while (uVar12 < uVar8);
    }
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x4e);
    goto LAB_000b6e46;
  case 8:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x4e);
    goto LAB_000b6e46;
  case 9:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pIVar5 = (Item *)Ship::getFirstEquipmentOfSort(*(Ship **)(this + 0x18c),0x13);
    Ship::removeEquipment(*(Ship **)(this + 0x18c),pIVar5);
    pSVar15 = *(Ship **)(this + 0x18c);
    pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x158),1);
    Ship::addEquipment(pSVar15,pIVar5);
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x4f);
    goto LAB_000b6e46;
  case 10:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x4c);
    goto LAB_000b6e46;
  case 0xb:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x4f);
    goto LAB_000b6e46;
  case 0xc:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0x96,0,0);
    setCampaignMission(this,pMVar6);
    Mission::setStatusValue
              ((Mission *)**(undefined4 **)(*(int *)(this + 0x194) + 4),*(int *)(this + 0x1c4) + 1);
    goto LAB_000b87a8;
  case 0xd:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x4f);
    goto LAB_000b6e46;
  case 0xe:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x62);
    goto LAB_000b6e46;
  case 0xf:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x62);
    goto LAB_000b6e46;
  case 0x10:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x62);
    goto LAB_000b6e46;
  case 0x11:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    Ship::setRace(*(Ship **)(this + 0x18c),0);
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0x9c,0,0x38);
    goto LAB_000b6e46;
  case 0x12:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0x9c,0,0x37);
    goto LAB_000b6e46;
  case 0x13:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xbd,0,0x37);
    setCampaignMission(this,pMVar6);
    iVar10 = *(int *)(this + 0x194);
    uVar8 = 6;
    goto LAB_000b8cbc;
  case 0x14:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x37);
    goto LAB_000b6e46;
  case 0x15:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x37);
    goto LAB_000b6e46;
  case 0x16:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    *(undefined1 *)(*(int *)(*(int *)(this + 0x38) + 4) + 6) = 1;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,20000,10);
    goto LAB_000b6e46;
  case 0x17:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    *(undefined4 *)(this + 0x80) = 0x30;
    *(undefined4 *)(this + 0x7c) = 9;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x30);
    goto LAB_000b6e46;
  case 0x18:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    puVar4 = (uint *)Ship::getCargo(*(Ship **)(this + 0x18c));
    if ((puVar4 == (uint *)0x0) || (*puVar4 == 0)) goto LAB_000b8c78;
    uVar8 = 0;
    goto LAB_000b7000;
  case 0x19:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    *(undefined4 *)(this + 0x7c) = 0xffffffff;
    *(undefined4 *)(this + 0x80) = 0xffffffff;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x30);
    goto LAB_000b6e46;
  case 0x1a:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,10);
    goto LAB_000b6e46;
  case 0x1b:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    *(undefined4 *)(this + 0x80) = 0x5b;
    *(undefined4 *)(this + 0x7c) = 0x12;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x5b);
    goto LAB_000b6e46;
  case 0x1c:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,-1);
    goto LAB_000b6e46;
  case 0x1d:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0x9c,0,0x5b);
    goto LAB_000b6e46;
  case 0x1e:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,30000,0x62);
    goto LAB_000b6e46;
  case 0x1f:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,10);
    goto LAB_000b6e46;
  case 0x20:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,8,0,10);
    setCampaignMission(this,pMVar6);
    iVar7 = 0xa4;
    iVar10 = 0x32;
    pMVar6 = (Mission *)**(undefined4 **)(*(int *)(this + 0x194) + 4);
    goto LAB_000b8b66;
  case 0x21:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    Ship::removeCargo(*(Ship **)(this + 0x18c),0xa4,0x32);
    puVar4 = *(uint **)(this + 0x18);
    if (*puVar4 == 0) goto LAB_000b8af6;
    uVar8 = 0;
    goto LAB_000b71fc;
  case 0x22:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x1d);
    goto LAB_000b6e46;
  case 0x23:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xc,0,0x1b);
    goto LAB_000b6e46;
  case 0x24:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xa0,0,0x1b);
    break;
  case 0x25:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x16);
    goto LAB_000b6e46;
  case 0x26:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x1e);
    goto LAB_000b6e46;
  case 0x27:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xa1,0,-1);
    goto LAB_000b6e46;
  case 0x28:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,-1);
    goto LAB_000b6e46;
  case 0x29:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    *(undefined4 *)(this + 0x7c) = 0xfffffff6;
    *(undefined4 *)(this + 0x80) = 0xfffffff6;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xa0,0,-1);
    goto LAB_000b6e46;
  case 0x2a:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,10);
    goto LAB_000b6e46;
  case 0x2b:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,10);
    goto LAB_000b6e46;
  case 0x2c:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    *(undefined4 *)(this + 0x7c) = 0xfffffff6;
    *(undefined4 *)(this + 0x80) = 0xfffffff6;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6);
    setCampaignMission(this,pMVar6);
    Mission::setVisible((Mission *)**(undefined4 **)(*(int *)(this + 0x194) + 4),false);
    iVar10 = *(int *)(this + 0x1ac) + 40000;
    if (iVar10 < 0) {
      iVar10 = 0;
    }
    *(int *)(this + 0x1ac) = iVar10;
    return;
  default:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    return;
  case 0x2e:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x4a);
    goto LAB_000b6e46;
  case 0x2f:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    *(undefined4 *)(this + 0x8c) = *(undefined4 *)(this + 0x18c);
    *(undefined4 *)(this + 0x18c) = 0;
    pSVar15 = (Ship *)Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0x24),-1);
    setShip(this,pSVar15);
    Ship::setRace(*(Ship **)(this + 0x18c),1);
    pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0xe8));
    Ship::setEquipment(*(Ship **)(Globals::status + 0x18c),pIVar5,0);
    pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x14c));
    Ship::setEquipment(*(Ship **)(Globals::status + 0x18c),pIVar5,1);
    *(undefined4 *)(Globals::status + 0x30) = 0;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x3a);
    goto LAB_000b6e46;
  case 0x30:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pSVar15 = (Ship *)Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0xa4),-1);
    setShip(this,pSVar15);
    Ship::setRace(*(Ship **)(this + 0x18c),1);
    iVar7 = 0;
    iVar10 = *(int *)(Globals::items + 4);
    do {
      pIVar5 = (Item *)Item::makeItem(*(Item **)(iVar10 + 0x2c4));
      Ship::setEquipment(*(Ship **)(Globals::status + 0x18c),pIVar5,iVar7);
      iVar7 = iVar7 + 1;
      iVar10 = *(int *)(Globals::items + 4);
    } while (iVar7 != 3);
    pIVar5 = (Item *)Item::makeItem(*(Item **)(iVar10 + 0xe8));
    Ship::setEquipment(*(Ship **)(Globals::status + 0x18c),pIVar5,0);
    pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x14c));
    Ship::setEquipment(*(Ship **)(Globals::status + 0x18c),pIVar5,1);
    pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0xd0));
    Ship::setEquipment(*(Ship **)(Globals::status + 0x18c),pIVar5,2);
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0x9c,0,0x3a);
    goto LAB_000b6e46;
  case 0x31:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0x9c,0,0x3e);
    goto LAB_000b6e46;
  case 0x32:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0x9c,0,0x19);
    goto LAB_000b6e46;
  case 0x33:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xa0,0,0x19);
    break;
  case 0x34:
  case 0x80:
    goto switchD_000b6cd8_caseD_34;
  case 0x35:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,200000,0x4a);
    goto LAB_000b6e46;
  case 0x36:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    *(undefined1 *)(*(int *)(*(int *)(this + 0x38) + 4) + 0x17) = 1;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x65);
    setCampaignMission(this,pMVar6);
    setShip(this,*(Ship **)(this + 0x8c));
    *(undefined4 *)(this + 0x8c) = 0;
    return;
  case 0x37:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    *(undefined4 *)(this + 0x8c) = *(undefined4 *)(this + 0x18c);
    *(undefined4 *)(this + 0x18c) = 0;
    pSVar15 = (Ship *)Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0x9c),-1);
    setShip(this,pSVar15);
    Ship::setRace(*(Ship **)(this + 0x18c),1);
    pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x2d4));
    Ship::setEquipment(*(Ship **)(Globals::status + 0x18c),pIVar5,0);
    pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0xd0));
    Ship::setEquipment(*(Ship **)(Globals::status + 0x18c),pIVar5,0);
    pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0xe8));
    Ship::setEquipment(*(Ship **)(Globals::status + 0x18c),pIVar5,1);
    pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x14c));
    Ship::setEquipment(*(Ship **)(Globals::status + 0x18c),pIVar5,2);
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x66);
    goto LAB_000b6e46;
  case 0x38:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,150000,0x65);
    goto LAB_000b6e46;
  case 0x39:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xa6,0,0x65);
    setCampaignMission(this,pMVar6);
    Mission::setProductionGoods((Mission *)**(undefined4 **)(*(int *)(this + 0x194) + 4),0xb3,10);
    puVar4 = *(uint **)(this + 0x18);
    if (*puVar4 == 0) goto LAB_000b8c56;
    uVar8 = 0;
    goto LAB_000b7820;
  case 0x3a:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pvVar13 = *(void **)(Globals::status + 0x90);
    if (pvVar13 != (void *)0x0) {
      if (*(void **)((int)pvVar13 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar13 + 4));
      }
      operator_delete(pvVar13);
    }
    iVar10 = Globals::status;
    *(undefined4 *)(Globals::status + 0x90) = 0;
    pAVar2 = operator_new(0xc);
    puVar3 = operator_new__(4);
    *(undefined4 **)(pAVar2 + 4) = puVar3;
    *(undefined4 *)(pAVar2 + 8) = 1;
    *puVar3 = 0;
    *(undefined4 *)pAVar2 = 0;
    *(Array **)(iVar10 + 0x90) = pAVar2;
    ArraySetLength<int>(3,pAVar2);
    puVar3 = *(undefined4 **)(*(int *)(Globals::status + 0x90) + 4);
    *puVar3 = 0x38;
    puVar3[1] = 0x2d;
    puVar3[2] = 0x16;
    puVar4 = *(uint **)(this + 0x18);
    if (*puVar4 != 0) {
      uVar8 = 0;
      do {
        iVar10 = BluePrint::getIndex(*(BluePrint **)(puVar4[1] + uVar8 * 4));
        if (iVar10 == 0xb3) {
          BluePrint::lock(*(BluePrint **)(*(int *)(*(int *)(this + 0x18) + 4) + uVar8 * 4));
        }
        puVar4 = *(uint **)(this + 0x18);
        uVar8 = uVar8 + 1;
      } while (uVar8 < *puVar4);
    }
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xa3,0,0x65);
    setCampaignMission(this,pMVar6);
    Mission::setStatusValue((Mission *)**(undefined4 **)(*(int *)(this + 0x194) + 4),0);
    *(undefined4 *)(Globals::status + 0x10c) = 0;
    return;
  case 0x3b:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    iVar10 = Mission::getStatusValue((Mission *)**(undefined4 **)(*(int *)(this + 0x194) + 4));
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,iVar10 * 50000 + 50000,0x65);
    setCampaignMission(this,pMVar6);
    pMVar6 = (Mission *)**(undefined4 **)(*(int *)(this + 0x194) + 4);
    uVar8 = (uint)(0 < iVar10);
    goto LAB_000b8cc0;
  case 0x3c:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xa4,0,0x65);
    goto LAB_000b6e46;
  case 0x3d:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    *(undefined1 *)(*(int *)(*(int *)(this + 0x38) + 4) + 0x16) = 1;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,100);
    goto LAB_000b6e46;
  case 0x3e:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    *(undefined1 *)(*(int *)(*(int *)(this + 0x38) + 4) + 0x18) = 1;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x67);
    goto LAB_000b6e46;
  case 0x3f:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x68);
    goto LAB_000b6e46;
  case 0x40:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,100);
    goto LAB_000b6e46;
  case 0x41:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x65);
    goto LAB_000b6e46;
  case 0x42:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x68);
    setCampaignMission(this,pMVar6);
    Mission::setStatusValue((Mission *)**(undefined4 **)(*(int *)(this + 0x194) + 4),0);
    pSVar11 = *(Station **)(Globals::status + 0x198);
    pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0xf0),5,0);
    Station::addItem(pSVar11,pIVar5);
    pSVar11 = *(Station **)(Globals::status + 0x198);
    pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0xf4),5,0);
    Station::addItem(pSVar11,pIVar5);
    pSVar11 = *(Station **)(Globals::status + 0x198);
    pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0xf8),5,0);
    Station::addItem(pSVar11,pIVar5);
    return;
  case 0x43:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,8,0,0x42);
    setCampaignMission(this,pMVar6);
    iVar10 = *(int *)(this + 0x194);
    iVar7 = 0xaf;
    goto LAB_000b8b60;
  case 0x44:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    Ship::removeCargo(*(Ship **)(Globals::status + 0x18c),0xaf);
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,6,0,0x42);
    goto LAB_000b6e46;
  case 0x45:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,6,0,0x41);
    goto LAB_000b6e46;
  case 0x46:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x42);
    goto LAB_000b6e46;
  case 0x47:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    puVar4 = *(uint **)(this + 0x18);
    if (*puVar4 != 0) {
      uVar8 = 0;
      do {
        iVar10 = BluePrint::getIndex(*(BluePrint **)(puVar4[1] + uVar8 * 4));
        if (iVar10 == 0xb7) {
          BluePrint::unlock(*(BluePrint **)(*(int *)(*(int *)(this + 0x18) + 4) + uVar8 * 4));
        }
        puVar4 = *(uint **)(this + 0x18);
        uVar8 = uVar8 + 1;
      } while (uVar8 < *puVar4);
    }
    pSVar15 = *(Ship **)(Globals::status + 0x18c);
    pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 700),1);
    Ship::addCargo(pSVar15,pIVar5);
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xa4,150000,0x65);
    setCampaignMission(this,pMVar6);
    *(undefined4 *)(this + 0x10c) = 0;
    return;
  case 0x48:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,10,0,0x51);
    goto LAB_000b6e46;
  case 0x49:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,100);
    goto LAB_000b6e46;
  case 0x4a:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    Station::removeShips(*(Station **)(Globals::status + 0x198));
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,100);
    goto LAB_000b6e46;
  case 0x4b:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,100);
    goto LAB_000b6e46;
  case 0x4c:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pIVar5 = (Item *)Ship::getFirstEquipmentOfSort(*(Ship **)(Globals::status + 0x18c),0x12);
    if (pIVar5 != (Item *)0x0) {
      Item::setUnsaleable(pIVar5,true);
    }
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x65);
    goto LAB_000b6e46;
  case 0x4d:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pIVar5 = (Item *)Ship::getFirstEquipmentOfSort(*(Ship **)(Globals::status + 0x18c),0x12);
    if (pIVar5 == (Item *)0x0) {
      pIVar5 = (Item *)Ship::getCargo(*(Ship **)(Globals::status + 0x18c),0x55);
      if (pIVar5 != (Item *)0x0) {
        Ship::removeCargo(*(Ship **)(Globals::status + 0x18c),pIVar5);
      }
    }
    else {
      Ship::removeEquipment(*(Ship **)(Globals::status + 0x18c),pIVar5);
    }
    puVar4 = *(uint **)(this + 0x18);
    if (*puVar4 != 0) {
      uVar8 = 0;
      do {
        iVar10 = BluePrint::isEmpty(*(BluePrint **)(puVar4[1] + uVar8 * 4));
        if ((iVar10 == 0) &&
           (iVar10 = BluePrint::getStationIndex
                               (*(BluePrint **)(*(int *)(*(int *)(this + 0x18) + 4) + uVar8 * 4)),
           iVar10 == 0x65)) {
          BluePrint::reset(*(BluePrint **)(*(int *)(*(int *)(this + 0x18) + 4) + uVar8 * 4));
        }
        puVar4 = *(uint **)(this + 0x18);
        uVar8 = uVar8 + 1;
      } while (uVar8 < *puVar4);
    }
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x65);
    goto LAB_000b6e46;
  case 0x4e:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xa5,0,-1);
    goto LAB_000b6e46;
  case 0x4f:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,1,0,100);
    goto LAB_000b6e46;
  case 0x50:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,-1);
    goto LAB_000b6e46;
  case 0x51:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,100);
    goto LAB_000b6e46;
  case 0x52:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,100);
    goto LAB_000b6e46;
  case 0x53:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pIVar5 = (Item *)Ship::getFirstEquipmentOfSort(*(Ship **)(Globals::status + 0x18c),0x12);
    if ((pIVar5 != (Item *)0x0) ||
       (pIVar5 = (Item *)Ship::getCargo(*(Ship **)(Globals::status + 0x18c),0x55),
       pIVar5 != (Item *)0x0)) {
      Item::setUnsaleable(pIVar5,false);
    }
    pSVar15 = *(Ship **)(Globals::status + 0x18c);
    pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x154),1);
    Ship::addCargo(pSVar15,pIVar5);
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6);
    break;
  case 0x54:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xa4,0,0);
    goto LAB_000b6e46;
  case 0x55:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,100);
    goto LAB_000b6e46;
  case 0x56:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,10);
    goto LAB_000b6e46;
  case 0x57:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,10);
    goto LAB_000b6e46;
  case 0x58:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    Ship::removeCargo(*(Ship **)(Globals::status + 0x18c),0x68,10);
    *(undefined2 *)(*(int *)(*(int *)(Globals::status + 0x38) + 4) + 0x1b) = 0x101;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x6d);
    goto LAB_000b6e46;
  case 0x59:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    *(int *)(Globals::status + 0x1d0) = *(int *)(Globals::status + 0x1d0) + -1;
    iVar10 = Galaxy::getVisited(Globals::galaxy);
    *(undefined1 *)(iVar10 + 0x6d) = 0;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,10);
    goto LAB_000b6e46;
  case 0x5a:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    *(undefined2 *)(*(int *)(*(int *)(this + 0x38) + 4) + 0x1b) = 0x101;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb8,0,0x6e);
    setCampaignMission(this,pMVar6);
    Mission::setProductionGoods((Mission *)**(undefined4 **)(*(int *)(this + 0x194) + 4),0,10);
    goto LAB_000b83c2;
  case 0x5b:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb8,0,0x71);
    setCampaignMission(this,pMVar6);
    Mission::setProductionGoods((Mission *)**(undefined4 **)(*(int *)(this + 0x194) + 4),0,10);
LAB_000b762e:
    iVar10 = *(int *)(this + 0x194);
    uVar8 = 10;
    goto LAB_000b8cbc;
  case 0x5c:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x72);
    goto LAB_000b6e46;
  case 0x5d:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x334),1);
    Ship::addCargo(*(Ship **)(Globals::status + 0x18c),pIVar5);
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb8,0,0x6f);
    setCampaignMission(this,pMVar6);
    Mission::setProductionGoods((Mission *)**(undefined4 **)(*(int *)(this + 0x194) + 4),0,0x53);
    iVar10 = *(int *)(this + 0x194);
    iVar7 = 0x53;
    goto LAB_000b83c8;
  case 0x5e:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xaa,0,10);
    goto LAB_000b8cae;
  case 0x5f:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x62);
    goto LAB_000b6e46;
  case 0x60:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x55);
    goto LAB_000b6e46;
  case 0x61:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    *(undefined1 *)(*(int *)(*(int *)(Globals::status + 0x38) + 4) + 0x1d) = 1;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x78);
    goto LAB_000b6e46;
  case 0x62:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xaa,0,10);
    goto LAB_000b8cae;
  case 99:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x62);
    goto LAB_000b6e46;
  case 100:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x62);
    goto LAB_000b6e46;
  case 0x65:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x33c),1);
    Ship::addCargo(*(Ship **)(Globals::status + 0x18c),pIVar5);
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb8,0,0x71);
    setCampaignMission(this,pMVar6);
    Mission::setProductionGoods((Mission *)**(undefined4 **)(*(int *)(this + 0x194) + 4),0,0x6a4);
    iVar10 = *(int *)(this + 0x194);
    uVar8 = 0x6a4;
    goto LAB_000b8cbc;
  case 0x66:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,10);
    goto LAB_000b6e46;
  case 0x67:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    puVar4 = *(uint **)(this + 0x18);
    if (*puVar4 == 0) goto LAB_000b8b40;
    uVar8 = 0;
    goto LAB_000b8004;
  case 0x68:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x6d);
    goto LAB_000b6e46;
  case 0x69:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x6f);
    goto LAB_000b6e46;
  case 0x6b:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,10);
    goto LAB_000b6e46;
  case 0x6c:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xaa,0,0x72);
    goto LAB_000b8cae;
  case 0x6d:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xab,0,10);
    goto LAB_000b6e46;
  case 0x6e:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xab,0,0x26);
    goto LAB_000b6e46;
  case 0x6f:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xac,0,0x26);
    setCampaignMission(this,pMVar6);
    iVar10 = *(int *)(this + 0x194);
    iVar7 = 0x92;
    goto LAB_000b8b60;
  case 0x70:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    Ship::removeCargo(*(Ship **)(Globals::status + 0x18c),0x92,1);
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xab,0,0x52);
    goto LAB_000b6e46;
  case 0x71:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x53);
    goto LAB_000b6e46;
  case 0x72:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xab,0,0x52);
    goto LAB_000b6e46;
  case 0x73:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xab,0,0x5d);
    goto LAB_000b8cae;
  case 0x74:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    *(undefined1 *)(*(int *)(*(int *)(this + 0x38) + 4) + 0x1e) = 1;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x7e);
    goto LAB_000b6e46;
  case 0x75:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,8,0,0x7e);
    goto LAB_000b81b8;
  case 0x76:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    puVar4 = (uint *)Ship::getCargo(*(Ship **)(this + 0x18c));
    if ((puVar4 == (uint *)0x0) || (*puVar4 == 0)) goto LAB_000b8c9c;
    uVar8 = 0;
    goto LAB_000b7544;
  case 0x77:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x28);
    goto LAB_000b6e46;
  case 0x78:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,8,0,0x5d);
LAB_000b81b8:
    setCampaignMission(this,pMVar6);
    iVar10 = *(int *)(this + 0x194);
    iVar7 = 0xd1;
    goto LAB_000b8b60;
  case 0x79:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    puVar4 = (uint *)Ship::getCargo(*(Ship **)(this + 0x18c));
    if ((puVar4 == (uint *)0x0) || (*puVar4 == 0)) goto LAB_000b8cd6;
    uVar8 = 0;
    goto LAB_000b81ec;
  case 0x7a:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x79);
    goto LAB_000b6e46;
  case 0x7b:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x79);
    goto LAB_000b6e46;
  case 0x7c:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x37);
    goto LAB_000b6e46;
  case 0x7d:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xaa,0,0x78);
    goto LAB_000b8cae;
  case 0x7e:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x62);
    goto LAB_000b6e46;
  case 0x7f:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6);
    break;
  case 0x81:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6);
    break;
  case 0x82:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x70);
    goto LAB_000b6e46;
  case 0x83:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x70);
    goto LAB_000b6e46;
  case 0x84:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xaa,0,0x78);
    goto LAB_000b8cae;
  case 0x85:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x16);
    goto LAB_000b8cae;
  case 0x86:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xae,0,0x67);
    setCampaignMission(this,pMVar6);
    Mission::setProductionGoods((Mission *)**(undefined4 **)(*(int *)(this + 0x194) + 4),0x9b,0x8c);
    goto LAB_000b8cb6;
  case 0x87:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x70);
    goto LAB_000b6e46;
  case 0x88:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x3a);
    goto LAB_000b6e46;
  case 0x89:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x3a);
    goto LAB_000b6e46;
  case 0x8a:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    *(undefined1 *)(*(int *)(*(int *)(this + 0x38) + 4) + 0x1f) = 1;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xa8,0,0x83);
    setCampaignMission(this,pMVar6);
LAB_000b83c2:
    iVar10 = *(int *)(this + 0x194);
    iVar7 = 10;
LAB_000b83c8:
    Mission::setStatusValue((Mission *)**(undefined4 **)(iVar10 + 4),iVar7);
    *(undefined4 *)(this + 0x174) = 0;
    return;
  case 0x8b:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x70);
    goto LAB_000b6e46;
  case 0x8c:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    puVar4 = *(uint **)(this + 0x18);
    if (*puVar4 == 0) goto LAB_000b8c16;
    uVar8 = 0;
    goto LAB_000b840a;
  case 0x8d:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pSVar15 = *(Ship **)(Globals::status + 0x18c);
    pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x314),0xf);
    Ship::addCargo(pSVar15,pIVar5);
    pSVar15 = *(Ship **)(Globals::status + 0x18c);
    pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x310),1);
    Ship::addCargo(pSVar15,pIVar5);
    pSVar15 = *(Ship **)(Globals::status + 0x18c);
    pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x318),1);
    Ship::addCargo(pSVar15,pIVar5);
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x4f);
    goto LAB_000b6e46;
  case 0x8e:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,8,0,0x70);
    setCampaignMission(this,pMVar6);
    iVar10 = *(int *)(this + 0x194);
    iVar7 = 0xd2;
    goto LAB_000b8b60;
  case 0x8f:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    Ship::removeCargo(*(Ship **)(Globals::status + 0x18c),0xd2,1);
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xaa,0,0x70);
    goto LAB_000b8cae;
  case 0x90:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x70);
    goto LAB_000b6e46;
  case 0x91:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x70);
    goto LAB_000b6e46;
  case 0x92:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,-1);
    goto LAB_000b6e46;
  case 0x93:
  case 0x94:
  case 0x95:
  case 0x96:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xab,0,0x60);
    goto LAB_000b6e46;
  case 0x97:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xa5,0,-1);
    goto LAB_000b6e46;
  case 0x98:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,0x62);
    goto LAB_000b6e46;
  case 0x99:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,-1);
    goto LAB_000b6e46;
  case 0x9a:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xa4,0,0);
    goto LAB_000b6e46;
  case 0x9b:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,99);
    goto LAB_000b6e46;
  case 0x9c:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x70);
    goto LAB_000b6e46;
  case 0x9d:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,4,0,0x6f);
    goto LAB_000b6e46;
  case 0x9e:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xb,0,10);
    goto LAB_000b6e46;
  case 0x9f:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xaa,0,10);
    goto LAB_000b6e46;
  case 0xa0:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6,0xaa,0,0x5d);
    goto LAB_000b8cae;
  case 0xa1:
    *(int *)(this + 0x1e8) = iVar10;
    *(undefined4 *)pSVar16 = uVar17;
    *(undefined4 *)(this + 0x104) = uVar18;
    pMVar6 = operator_new(100);
    Mission::Mission(pMVar6);
  }
  setCampaignMission(this,pMVar6);
LAB_000b87a8:
  Mission::setVisible((Mission *)**(undefined4 **)(*(int *)(this + 0x194) + 4),false);
  return;
  while( true ) {
    puVar4 = *(uint **)(this + 0x18);
    uVar8 = uVar8 + 1;
    if (*puVar4 <= uVar8) break;
LAB_000b840a:
    iVar10 = BluePrint::getIndex(*(BluePrint **)(puVar4[1] + uVar8 * 4));
    if (iVar10 == 0xd2) {
      BluePrint::unlock(*(BluePrint **)(*(int *)(*(int *)(this + 0x18) + 4) + uVar8 * 4));
      pBVar14 = *(BluePrint **)(*(int *)(*(int *)(this + 0x18) + 4) + uVar8 * 4);
      pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x324));
      BluePrint::addItem(pBVar14,pIVar5,0x34f,0x70);
      pBVar14 = *(BluePrint **)(*(int *)(*(int *)(this + 0x18) + 4) + uVar8 * 4);
      pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x328));
      BluePrint::addItem(pBVar14,pIVar5,0x342,0x70);
      pBVar14 = *(BluePrint **)(*(int *)(*(int *)(this + 0x18) + 4) + uVar8 * 4);
      pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x32c));
      BluePrint::addItem(pBVar14,pIVar5,0x35d,0x70);
      pBVar14 = *(BluePrint **)(*(int *)(*(int *)(this + 0x18) + 4) + uVar8 * 4);
      pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x330));
      BluePrint::addItem(pBVar14,pIVar5,0x37c,0x70);
      break;
    }
  }
LAB_000b8c16:
  pMVar6 = operator_new(100);
  Mission::Mission(pMVar6,0xb,0,0x4e);
  goto LAB_000b6e46;
  while (uVar8 = uVar8 + 1, uVar8 < *puVar4) {
LAB_000b81ec:
    iVar10 = Item::getIndex(*(Item **)(puVar4[1] + uVar8 * 4));
    if (iVar10 == 0xd1) {
      Item::setUnsaleable(*(Item **)(puVar4[1] + uVar8 * 4),false);
      break;
    }
  }
LAB_000b8cd6:
  Ship::removeCargo(*(Ship **)(Globals::status + 0x18c),0xd1,1);
  pMVar6 = operator_new(100);
  Mission::Mission(pMVar6,0xb,0,10);
  goto LAB_000b6e46;
  while( true ) {
    puVar4 = *(uint **)(this + 0x18);
    uVar8 = uVar8 + 1;
    if (*puVar4 <= uVar8) break;
LAB_000b71fc:
    iVar10 = BluePrint::getIndex(*(BluePrint **)(puVar4[1] + uVar8 * 4));
    if (iVar10 == 0x55) {
      BluePrint::unlock(*(BluePrint **)(*(int *)(*(int *)(this + 0x18) + 4) + uVar8 * 4));
      pBVar14 = *(BluePrint **)(*(int *)(*(int *)(this + 0x18) + 4) + uVar8 * 4);
      pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x290));
      BluePrint::addItem(pBVar14,pIVar5,0x32,10);
      break;
    }
  }
LAB_000b8af6:
  pMVar6 = operator_new(100);
  Mission::Mission(pMVar6,0xb,0,0x1e);
  goto LAB_000b6e46;
switchD_000b6cd8_caseD_0:
  *(int *)(this + 0x1e8) = iVar10;
  *(undefined4 *)pSVar16 = uVar17;
  *(undefined4 *)(this + 0x104) = uVar18;
  pMVar6 = operator_new(100);
  Mission::Mission(pMVar6,0xb,0,0x4e);
  setCampaignMission(this,pMVar6);
  *(undefined4 *)(this + 400) = **(undefined4 **)(*(int *)(this + 0x194) + 4);
  return;
  while (uVar8 = uVar8 + 1, uVar8 < *puVar4) {
LAB_000b7544:
    iVar10 = Item::getIndex(*(Item **)(puVar4[1] + uVar8 * 4));
    if (iVar10 == 0xd1) {
      Item::setUnsaleable(*(Item **)(puVar4[1] + uVar8 * 4),true);
      break;
    }
  }
LAB_000b8c9c:
  pMVar6 = operator_new(100);
  Mission::Mission(pMVar6,0xaa,0,10);
LAB_000b8cae:
  setCampaignMission(this,pMVar6);
LAB_000b8cb6:
  iVar10 = *(int *)(this + 0x194);
  uVar8 = 0;
LAB_000b8cbc:
  pMVar6 = (Mission *)**(undefined4 **)(iVar10 + 4);
LAB_000b8cc0:
  Mission::setStatusValue(pMVar6,uVar8);
  return;
  while( true ) {
    puVar4 = *(uint **)(this + 0x18);
    uVar8 = uVar8 + 1;
    if (*puVar4 <= uVar8) break;
LAB_000b8004:
    iVar10 = BluePrint::getIndex(*(BluePrint **)(puVar4[1] + uVar8 * 4));
    if (iVar10 == 0xce) {
      BluePrint::unlock(*(BluePrint **)(*(int *)(*(int *)(this + 0x18) + 4) + uVar8 * 4));
      pBVar14 = *(BluePrint **)(*(int *)(*(int *)(this + 0x18) + 4) + uVar8 * 4);
      pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x28c));
      BluePrint::addItem(pBVar14,pIVar5,10,10);
      break;
    }
  }
LAB_000b8b40:
  pMVar6 = operator_new(100);
  Mission::Mission(pMVar6,0xa6,0,10);
  setCampaignMission(this,pMVar6);
  iVar10 = *(int *)(this + 0x194);
  iVar7 = 0xce;
LAB_000b8b60:
  pMVar6 = (Mission *)**(undefined4 **)(iVar10 + 4);
  iVar10 = 1;
LAB_000b8b66:
  Mission::setProductionGoods(pMVar6,iVar7,iVar10);
  return;
  while( true ) {
    puVar4 = *(uint **)(this + 0x18);
    uVar8 = uVar8 + 1;
    if (*puVar4 <= uVar8) break;
LAB_000b7820:
    iVar10 = BluePrint::getIndex(*(BluePrint **)(puVar4[1] + uVar8 * 4));
    if (iVar10 == 0xb3) {
      BluePrint::unlock(*(BluePrint **)(*(int *)(*(int *)(this + 0x18) + 4) + uVar8 * 4));
      BluePrint::addItem(*(BluePrint **)(*(int *)(*(int *)(this + 0x18) + 4) + uVar8 * 4),
                         *(Item **)(*(int *)(Globals::items + 4) + 0x1fc),5,0x65);
      break;
    }
  }
LAB_000b8c56:
  setShip(this,*(Ship **)(this + 0x8c));
  *(undefined4 *)(this + 0x8c) = 0;
  return;
  while (uVar8 = uVar8 + 1, uVar8 < *puVar4) {
LAB_000b7000:
    iVar10 = Item::getIndex(*(Item **)(puVar4[1] + uVar8 * 4));
    if (iVar10 == 0x83) {
      Item::setUnsaleable(*(Item **)(puVar4[1] + uVar8 * 4),true);
      break;
    }
  }
LAB_000b8c78:
  pMVar6 = operator_new(100);
  Mission::Mission(pMVar6,0x9c,0,-1);
LAB_000b6e46:
  setCampaignMission(this,pMVar6);
  return;
}

// ===== Status::changeCredits  @0x000b8e84  (40 bytes)
/* Status::changeCredits(int) */

void __thiscall Status::changeCredits(Status *this,int param_1)

{
  int iVar1;
  
  iVar1 = param_1;
  if (param_1 < 0) {
    iVar1 = -param_1;
  }
  if (1000000000 < iVar1) {
    return;
  }
  iVar1 = param_1 + *(int *)(this + 0x1ac);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  *(int *)(this + 0x1ac) = iVar1;
  return;
}

// ===== Status::setShip  @0x000b8eac  (34 bytes)
/* Status::setShip(Ship*) */

void __thiscall Status::setShip(Status *this,Ship *param_1)

{
  void *pvVar1;
  
  if (*(Ship **)(this + 0x18c) != (Ship *)0x0) {
    pvVar1 = (void *)Ship::~Ship(*(Ship **)(this + 0x18c));
    operator_delete(pvVar1);
    *(undefined4 *)(this + 0x18c) = 0;
  }
  *(Ship **)(this + 0x18c) = param_1;
  return;
}

// ===== Status::setStationsVisited  @0x000b8ece  (6 bytes)
/* Status::setStationsVisited(int) */

void __thiscall Status::setStationsVisited(Status *this,int param_1)

{
  *(int *)(this + 0x1d0) = param_1;
  return;
}

// ===== Status::getStationsVisited  @0x000b8ed4  (6 bytes)
/* Status::getStationsVisited() */

undefined4 __thiscall Status::getStationsVisited(Status *this)

{
  return *(undefined4 *)(this + 0x1d0);
}

// ===== Status::dlc1Won  @0x000b8eda  (14 bytes)
/* Status::dlc1Won() */

bool __thiscall Status::dlc1Won(Status *this)

{
  return 0x53 < *(int *)(this + 0x1e8);
}

// ===== Status::inEmptyOrbit  @0x000b8ee8  (142 bytes)
/* Status::inEmptyOrbit() */

bool __thiscall Status::inEmptyOrbit(Status *this)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = Station::getIndex(*(Station **)(this + 0x198));
  if ((((iVar1 != 0x4e) || (1 < *(int *)(this + 0x1e8))) &&
      ((iVar2 = Station::equals(*(Station **)(this + 0x198),*(Station **)(this + 0x78)), iVar2 != 1
       || (0x28 < *(int *)(this + 0x1e8) - 0x2bU)))) &&
     ((iVar2 = Station::equals(*(Station **)(this + 0x198),*(Station **)(this + 0x78)), iVar2 != 1
      || (*(int *)(this + 0x1e8) < 0x9a)))) {
    uVar3 = iVar1 - 0x66;
    if (uVar3 < 0x20) {
      if ((1 << (uVar3 & 0xff) & 0xc0000187U) != 0) {
        return true;
      }
      if (uVar3 == 9) {
        if (0x5d < *(int *)(this + 0x1e8)) {
          return true;
        }
        goto LAB_000b8f6c;
      }
    }
    if ((iVar1 != 0x65) || (*(int *)(this + 0x1e8) < 0x54)) {
LAB_000b8f6c:
      return iVar1 == 0x86;
    }
  }
  return true;
}

// ===== Status::inPlanetRingOrbit  @0x000b8f76  (54 bytes)
/* Status::inPlanetRingOrbit() */

uint __thiscall Status::inPlanetRingOrbit(Status *this)

{
  int iVar1;
  
  iVar1 = Station::equals(*(Station **)(this + 0x198),*(Station **)(this + 0x78));
  if (iVar1 == 0) {
    iVar1 = Station::getIndex(*(Station **)(this + 0x198));
    if (iVar1 - 0x78U < 0xd) {
      return 0x1441U >> (iVar1 - 0x78U & 0xff) & 1;
    }
  }
  return 0;
}

// ===== Status::orbitHasPlanetRing  @0x000b8fac  (30 bytes)
/* Status::orbitHasPlanetRing(int) */

uint __thiscall Status::orbitHasPlanetRing(Status *this,int param_1)

{
  if (param_1 - 0x78U < 0xd) {
    return 0x1441U >> (param_1 - 0x78U & 0xff) & 1;
  }
  return 0;
}

// ===== Status::inStormOrbit  @0x000b8fca  (74 bytes)
/* Status::inStormOrbit() */

bool __thiscall Status::inStormOrbit(Status *this)

{
  int iVar1;
  
  iVar1 = Station::equals(*(Station **)(this + 0x198),*(Station **)(this + 0x78));
  if ((iVar1 != 0) || (*(int *)(this + 0x1e8) < 0x5a)) {
    return false;
  }
  iVar1 = inSupernovaSystem(this);
  if ((iVar1 == 0) &&
     (iVar1 = SolarSystem::getTextureIndex(*(SolarSystem **)(this + 0x1a0)), iVar1 != 0x10)) {
    iVar1 = SolarSystem::getTextureIndex(*(SolarSystem **)(this + 0x1a0));
    return iVar1 == 0x12;
  }
  return true;
}

// ===== Status::inSupernovaSystem  @0x000b9014  (52 bytes)
/* Status::inSupernovaSystem() */

bool __thiscall Status::inSupernovaSystem(Status *this)

{
  int iVar1;
  
  iVar1 = Station::equals(*(Station **)(this + 0x198),*(Station **)(this + 0x78));
  if (iVar1 != 0) {
    return false;
  }
  iVar1 = SolarSystem::getIndex(*(SolarSystem **)(this + 0x1a0));
  if (iVar1 != 0x1b) {
    return false;
  }
  return *(int *)(this + 0x1e8) < 0x9e;
}

// ===== Status::getSystem  @0x000b9048  (6 bytes)
/* Status::getSystem() */

undefined4 __thiscall Status::getSystem(Status *this)

{
  return *(undefined4 *)(this + 0x1a0);
}

// ===== Status::inFogSkyboxOrbit  @0x000b904e  (58 bytes)
/* Status::inFogSkyboxOrbit() */

bool __thiscall Status::inFogSkyboxOrbit(Status *this)

{
  int iVar1;
  
  iVar1 = Station::equals(*(Station **)(this + 0x198),*(Station **)(this + 0x78));
  if (iVar1 != 0) {
    return false;
  }
  iVar1 = SolarSystem::getTextureIndex(*(SolarSystem **)(this + 0x1a0));
  if (iVar1 != 0x11) {
    iVar1 = SolarSystem::getTextureIndex(*(SolarSystem **)(this + 0x1a0));
    return iVar1 == 0x12;
  }
  return true;
}

// ===== Status::inSupernovaOrbit  @0x000b9088  (38 bytes)
/* Status::inSupernovaOrbit() */

undefined4 __thiscall Status::inSupernovaOrbit(Status *this)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Station::equals(*(Station **)(this + 0x198),*(Station **)(this + 0x78));
  uVar2 = 0;
  if ((iVar1 == 0) && (iVar1 = Station::getIndex(*(Station **)(this + 0x198)), iVar1 == 0x6d)) {
    uVar2 = 1;
  }
  return uVar2;
}

// ===== Status::inDeepScienceOrbit  @0x000b90ae  (58 bytes)
/* Status::inDeepScienceOrbit() */

bool __thiscall Status::inDeepScienceOrbit(Status *this)

{
  int iVar1;
  
  iVar1 = Station::equals(*(Station **)(this + 0x198),*(Station **)(this + 0x78));
  if (iVar1 != 0) {
    return false;
  }
  iVar1 = Station::getIndex(*(Station **)(this + 0x198));
  if (iVar1 != 10) {
    iVar1 = Station::getIndex(*(Station **)(this + 0x198));
    return iVar1 == 100;
  }
  return true;
}

// ===== Status::inBlackMarketSystem  @0x000b90e8  (38 bytes)
/* Status::inBlackMarketSystem() */

undefined4 __thiscall Status::inBlackMarketSystem(Status *this)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Station::equals(*(Station **)(this + 0x198),*(Station **)(this + 0x78));
  uVar2 = 0;
  if ((iVar1 == 0) &&
     (iVar1 = SolarSystem::getIndex(*(SolarSystem **)(this + 0x1a0)), iVar1 == 0x19)) {
    uVar2 = 1;
  }
  return uVar2;
}

// ===== Status::inPirateLootOrbit  @0x000b910e  (58 bytes)
/* Status::inPirateLootOrbit() */

bool __thiscall Status::inPirateLootOrbit(Status *this)

{
  int iVar1;
  
  iVar1 = Station::equals(*(Station **)(this + 0x198),*(Station **)(this + 0x78));
  if (iVar1 != 0) {
    return false;
  }
  iVar1 = SolarSystem::getIndex(*(SolarSystem **)(this + 0x1a0));
  if (iVar1 != 0x20) {
    iVar1 = SolarSystem::getIndex(*(SolarSystem **)(this + 0x1a0));
    return iVar1 == 0x21;
  }
  return true;
}

// ===== Status::hardCoreMode  @0x000b9148  (30 bytes)
/* Status::hardCoreMode() */

bool Status::hardCoreMode(void)

{
  return (float)Globals::options._44_4_ == 1.5;
}

// ===== Status::getWantedInCurrentOrbit  @0x000b916c  (136 bytes)
/* Status::getWantedInCurrentOrbit() */

Wanted * __thiscall Status::getWantedInCurrentOrbit(Status *this)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  Wanted *this_00;
  
  puVar1 = *(uint **)this;
  if ((puVar1 == (uint *)0x0) || (*puVar1 == 0)) {
    this_00 = (Wanted *)0x0;
  }
  else {
    uVar4 = 0;
    this_00 = (Wanted *)0x0;
    do {
      iVar2 = Wanted::isActive(*(Wanted **)(puVar1[1] + uVar4 * 4));
      if ((iVar2 == 1) &&
         (iVar2 = Wanted::isTerminated(*(Wanted **)(*(int *)(*(int *)this + 4) + uVar4 * 4)),
         iVar2 == 0)) {
        iVar2 = Wanted::getCurrentLocation(*(Wanted **)(*(int *)(*(int *)this + 4) + uVar4 * 4));
        iVar3 = Station::getIndex(*(Station **)(this + 0x198));
        if (iVar2 == iVar3) {
          if (this_00 != (Wanted *)0x0) {
            iVar2 = Wanted::getRequiredBounties(this_00);
            iVar3 = Wanted::getRequiredBounties
                              (*(Wanted **)(*(int *)(*(int *)this + 4) + uVar4 * 4));
            if (iVar3 <= iVar2) goto LAB_000b91de;
          }
          this_00 = *(Wanted **)(*(int *)(*(int *)this + 4) + uVar4 * 4);
        }
      }
LAB_000b91de:
      puVar1 = *(uint **)this;
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar1);
  }
  return this_00;
}

// ===== Status::missionFailed  @0x000b91f4  (88 bytes)
/* Status::missionFailed(bool, long long) */

Mission * Status::missionFailed(bool param_1,longlong param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int in_r1;
  Mission *this;
  uint uVar4;
  
  uVar1 = (uint)param_1;
  puVar2 = *(uint **)(uVar1 + 0x194);
  if (*puVar2 != 0) {
    uVar4 = 0;
    do {
      this = *(Mission **)(puVar2[1] + uVar4 * 4);
      iVar3 = Mission::hasFailed(this);
      if (iVar3 != 0) {
        return (Mission *)0x0;
      }
      if (((this != (Mission *)0x0) && (iVar3 = Mission::getType(this), iVar3 == 0xd && in_r1 == 1))
         && (*(char *)(uVar1 + 0xf1) != '\0')) {
        return this;
      }
      puVar2 = *(uint **)(uVar1 + 0x194);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar2);
  }
  return (Mission *)0x0;
}

// ===== Status::missionCompleted  @0x000b924c  (1388 bytes)
/* Status::missionCompleted(bool, bool, long long) */

Mission * Status::missionCompleted(bool param_1,bool param_2,longlong param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint *puVar4;
  Agent *this;
  int iVar5;
  Array *pAVar6;
  Item *pIVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  Mission *this_00;
  Ship *this_01;
  uint uVar12;
  BluePrint *this_02;
  uint uVar13;
  uint in_stack_00000000;
  int in_stack_00000004;
  
  uVar9 = (uint)param_2;
  uVar3 = (uint)param_1;
  puVar4 = *(uint **)(uVar3 + 0x194);
  if (*puVar4 != 0) {
    uVar13 = 0;
    uVar10 = uVar9 & (uint)param_3;
    do {
      this_00 = *(Mission **)(puVar4[1] + uVar13 * 4);
      iVar8 = Mission::hasWon(this_00);
      if (iVar8 != 0) {
        return (Mission *)0x0;
      }
      if ((this_00 == (Mission *)0x0) ||
         ((((iVar8 = Mission::isCampaignMission(this_00), iVar8 == 0 &&
            (iVar8 = Mission::getAgent(this_00), iVar8 == 0)) &&
           (iVar8 = Mission::getClientImage(this_00), iVar8 == 0)) &&
          ((iVar8 = Mission::getTargetStation(this_00), iVar8 == 0 &&
           (iVar8 = Mission::getTargetStation(this_00), iVar8 == 0))))))
      goto switchD_000b9318_caseD_9f;
      iVar8 = Mission::getType(this_00);
      switch(iVar8) {
      case 0x96:
        iVar8 = *(int *)(uVar3 + 0x1c4);
        goto LAB_000b94d2;
      case 0x97:
        iVar8 = *(int *)(uVar3 + 0x1c0);
        goto LAB_000b94d2;
      case 0x98:
        puVar4 = (uint *)Ship::getEquipment(*(Ship **)(uVar3 + 0x18c));
        uVar11 = *puVar4;
        if (uVar11 != 0) {
          uVar12 = 0;
          do {
            pIVar7 = *(Item **)(puVar4[1] + uVar12 * 4);
            if (pIVar7 != (Item *)0x0) {
              iVar8 = Item::getIndex(pIVar7);
              iVar5 = Mission::getStatusValue(this_00);
              if (iVar8 == iVar5) {
                return this_00;
              }
              uVar11 = *puVar4;
            }
            uVar12 = uVar12 + 1;
          } while (uVar12 < uVar11);
        }
        break;
      case 0x99:
        iVar8 = *(int *)(uVar3 + 0x1d0);
        goto LAB_000b94d2;
      case 0x9a:
        iVar8 = Ship::getCurrentLoad(*(Ship **)(uVar3 + 0x18c));
        goto LAB_000b94d2;
      case 0x9b:
        iVar8 = *(int *)(uVar3 + 0x1d4);
LAB_000b94d2:
        iVar5 = Mission::getStatusValue(this_00);
LAB_000b94d8:
        if (iVar5 <= iVar8) {
LAB_000b97f4:
          Mission::setWon(this_00,true);
          return this_00;
        }
        break;
      case 0x9c:
        if (uVar9 == 0) {
          iVar8 = Station::getIndex(*(Station **)(uVar3 + 0x198));
          iVar5 = Mission::getTargetStation(this_00);
          if (in_stack_00000004 < (int)(uint)(in_stack_00000000 < 0x2711)) break;
LAB_000b970e:
          if (iVar8 == iVar5) {
            return this_00;
          }
        }
        break;
      case 0x9d:
        puVar4 = (uint *)Ship::getEquipment(*(Ship **)(uVar3 + 0x18c));
        uVar11 = *puVar4;
        if (uVar11 != 0) {
          uVar12 = 0;
          do {
            pIVar7 = *(Item **)(puVar4[1] + uVar12 * 4);
            if (pIVar7 != (Item *)0x0) {
              iVar8 = Item::getType(pIVar7);
              iVar5 = Mission::getStatusValue(this_00);
              if (iVar8 == iVar5) {
                return this_00;
              }
              uVar11 = *puVar4;
            }
            uVar12 = uVar12 + 1;
          } while (uVar12 < uVar11);
        }
        break;
      case 0x9e:
        puVar4 = (uint *)Ship::getEquipment(*(Ship **)(uVar3 + 0x18c));
        if (*puVar4 != 0) {
          uVar11 = 0;
          bVar1 = 0;
          bVar2 = 0;
          do {
            pIVar7 = *(Item **)(puVar4[1] + uVar11 * 4);
            if (pIVar7 != (Item *)0x0) {
              iVar8 = Item::getType(pIVar7);
              if (iVar8 == 0) {
                bVar2 = 1;
              }
              else {
                pIVar7 = *(Item **)(puVar4[1] + uVar11 * 4);
                if (pIVar7 != (Item *)0x0) {
                  iVar8 = Item::getSort(pIVar7);
                  bVar1 = bVar1 | iVar8 == 10;
                }
              }
            }
            uVar11 = uVar11 + 1;
          } while (uVar11 < *puVar4);
          if ((bool)(bVar2 & bVar1)) {
            return this_00;
          }
        }
        break;
      case 0x9f:
      case 0xa1:
      case 0xad:
      case 0xaf:
      case 0xb0:
      case 0xb1:
      case 0xb2:
      case 0xb3:
      case 0xb4:
      case 0xb5:
      case 0xb6:
      case 0xb7:
      case 0xb9:
      case 0xba:
      case 0xbb:
      case 0xbc:
        break;
      case 0xa0:
        if (uVar9 != 0) {
          return this_00;
        }
        iVar8 = Station::getIndex(*(Station **)(uVar3 + 0x198));
        iVar5 = Mission::getTargetStation(this_00);
        if (((int)(uint)(in_stack_00000000 < 0x2711) <= in_stack_00000004) && (iVar8 != iVar5)) {
          return this_00;
        }
        break;
      case 0xa2:
        if (uVar9 == 1) {
          iVar8 = Station::getIndex(*(Station **)(uVar3 + 0x198));
          iVar5 = Mission::getTargetStation(this_00);
          if (iVar8 == iVar5) {
            iVar5 = *(int *)(uVar3 + 0x18);
            iVar8 = Mission::getStatusValue(this_00);
            this_02 = *(BluePrint **)(*(int *)(iVar5 + 4) + iVar8 * 4);
            puVar4 = (uint *)BluePrint::getIngredientList(this_02);
            iVar8 = BluePrint::getQuantityList(this_02);
            if (*puVar4 == 0) {
              return this_00;
            }
            uVar11 = 0;
            while (iVar5 = Ship::hasCargo(*(Ship **)(uVar3 + 0x18c),*(int *)(puVar4[1] + uVar11 * 4)
                                          ,*(int *)(*(int *)(iVar8 + 4) + uVar11 * 4)), iVar5 != 0)
            {
              uVar11 = uVar11 + 1;
              if (*puVar4 <= uVar11) {
                return this_00;
              }
            }
          }
        }
        break;
      case 0xa3:
        uVar11 = **(uint **)(uVar3 + 0x90);
        if (uVar11 == 0) {
          return this_00;
        }
        uVar12 = 0;
        while (0x7fffffff < *(uint *)((*(uint **)(uVar3 + 0x90))[1] + uVar12 * 4)) {
          uVar12 = uVar12 + 1;
          if (uVar11 <= uVar12) {
            return this_00;
          }
        }
        break;
      case 0xa4:
        uVar11 = (uint)((int)(-(uint)(10000 < in_stack_00000000) - in_stack_00000004) < 0 !=
                       (SBORROW4(0,in_stack_00000004) !=
                       SBORROW4(-in_stack_00000004,(uint)(10000 < in_stack_00000000)))) &
                 (uVar9 ^ 1);
        goto LAB_000b9750;
      case 0xa5:
        if (uVar9 == 0) {
LAB_000b96fe:
          iVar8 = Station::getIndex(*(Station **)(uVar3 + 0x198));
          iVar5 = Mission::getTargetStation(this_00);
          goto LAB_000b970e;
        }
        break;
      case 0xa6:
        if (uVar9 == 1) {
          iVar8 = Station::getIndex(*(Station **)(uVar3 + 0x198));
          iVar5 = Mission::getTargetStation(this_00);
          if (iVar8 == iVar5) {
            iVar8 = Mission::getProductionGoodIndex(this_00);
            iVar5 = Mission::getProductionGoodAmount(this_00);
            pAVar6 = (Array *)Ship::getCargo(*(Ship **)(uVar3 + 0x18c));
            iVar8 = Item::isInList(iVar8,iVar5,pAVar6);
            if (iVar8 != 0) {
              return this_00;
            }
            this_01 = *(Ship **)(Globals::status + 0x18c);
            iVar8 = Mission::getProductionGoodIndex(this_00);
            uVar11 = Ship::hasEquipment(this_01,iVar8,1);
            goto LAB_000b9750;
          }
        }
        break;
      case 0xa7:
      case 0xae:
        iVar8 = Mission::getStatusValue(this_00);
        iVar5 = Mission::getProductionGoodAmount(this_00);
        goto LAB_000b94d8;
      case 0xa8:
        iVar5 = *(int *)(Globals::status + 0x174);
        iVar8 = Mission::getStatusValue(this_00);
        if (iVar8 <= iVar5) {
          Mission::setWon(this_00,true);
          *(undefined4 *)(Globals::status + 0x174) = 0;
          return this_00;
        }
        break;
      case 0xa9:
        uVar11 = (uint)((int)(-(uint)(2000 < in_stack_00000000) - in_stack_00000004) < 0 !=
                       (SBORROW4(0,in_stack_00000004) !=
                       SBORROW4(-in_stack_00000004,(uint)(2000 < in_stack_00000000)))) & (uVar9 ^ 1)
        ;
LAB_000b9750:
        if (uVar11 != 0) {
          return this_00;
        }
        break;
      case 0xaa:
        iVar8 = Mission::getStatusValue(this_00);
        if (iVar8 == 1) goto LAB_000b97f4;
        break;
      case 0xab:
        uVar11 = uVar10;
LAB_000b96fa:
        if (uVar11 == 1) goto LAB_000b96fe;
        break;
      case 0xac:
        if (uVar10 == 1) {
          iVar8 = Station::getIndex(*(Station **)(uVar3 + 0x198));
          iVar5 = Mission::getTargetStation(this_00);
          if (iVar8 == iVar5) {
            iVar5 = Mission::getProductionGoodIndex(this_00);
            iVar8 = Mission::getProductionGoodAmount(this_00);
            pAVar6 = (Array *)Ship::getCargo(*(Ship **)(uVar3 + 0x18c));
LAB_000b974c:
            uVar11 = Item::isInList(iVar5,iVar8,pAVar6);
            goto LAB_000b9750;
          }
        }
        break;
      case 0xb8:
        iVar8 = Mission::getStatusValue(this_00);
        if ((iVar8 == 0) &&
           (((*(int *)(Globals::status + 0x1e8) != 0x5c ||
             (iVar8 = Station::equals(*(Station **)(Globals::status + 0x198),
                                      *(Station **)(Globals::status + 0x78)), iVar8 != 0)) ||
            (iVar8 = Station::getIndex(*(Station **)(Globals::status + 0x198)), iVar8 != 0x71))))
        goto LAB_000b97f4;
        break;
      case 0xbd:
        if (uVar9 == 1) {
          puVar4 = (uint *)Ship::getEquipment(*(Ship **)(uVar3 + 0x18c));
          uVar11 = *puVar4;
          if (uVar11 != 0) {
            uVar12 = 0;
            do {
              pIVar7 = *(Item **)(puVar4[1] + uVar12 * 4);
              if (pIVar7 != (Item *)0x0) {
                iVar8 = Item::getSort(pIVar7);
                iVar5 = Mission::getStatusValue(this_00);
                if (iVar8 == iVar5) {
                  return this_00;
                }
                uVar11 = *puVar4;
              }
              uVar12 = uVar12 + 1;
            } while (uVar12 < uVar11);
          }
        }
        break;
      default:
        switch(iVar8) {
        case 8:
          iVar8 = Mission::isCampaignMission(this_00);
          if (iVar8 == 1) {
            uVar12 = *(uint *)(Globals::status + 0x1e8);
            uVar11 = uVar12;
            if (uVar12 == 0x8f) {
              uVar11 = uVar9;
            }
            if (uVar12 == 0x8f && uVar11 == 0) {
              iVar8 = Station::getIndex(*(Station **)(uVar3 + 0x198));
              iVar5 = Mission::getTargetStation(this_00);
              if (((iVar8 == iVar5) && (puVar4 = *(uint **)(uVar3 + 0x1c), puVar4 != (uint *)0x0))
                 && (*puVar4 != 0)) {
                uVar11 = 0;
                do {
                  iVar8 = *(int *)(puVar4[1] + uVar11 * 4);
                  if ((iVar8 != 0) && (*(int *)(iVar8 + 0x10) == 0xd2)) {
                    return this_00;
                  }
                  uVar11 = uVar11 + 1;
                } while (uVar11 < *puVar4);
              }
            }
          }
          if (uVar9 == 1) {
            iVar8 = Station::getIndex(*(Station **)(uVar3 + 0x198));
            iVar5 = Mission::getTargetStation(this_00);
            if (iVar8 == iVar5) {
              iVar5 = Mission::getProductionGoodIndex(this_00);
              iVar8 = Mission::getProductionGoodAmount(this_00);
              pAVar6 = (Array *)Ship::getCargo(*(Ship **)(uVar3 + 0x18c));
              goto LAB_000b974c;
            }
          }
          break;
        case 9:
        case 10:
        case 0xc:
          break;
        case 0xb:
switchD_000b9384_caseD_b:
          uVar11 = uVar9;
          goto LAB_000b96fa;
        case 0xd:
          if (uVar9 == 1) {
            uVar11 = (uint)*(byte *)(uVar3 + 0xf0);
            goto LAB_000b9750;
          }
          break;
        case 0xe:
          if (uVar9 == 1) {
            iVar8 = Station::getIndex(*(Station **)(uVar3 + 0x198));
            this = (Agent *)Mission::getAgent(this_00);
            iVar5 = Agent::getStation(this);
            if (iVar8 == iVar5) {
              pAVar6 = (Array *)Ship::getCargo(*(Ship **)(uVar3 + 0x18c));
              uVar11 = Item::isInList(0x73,pAVar6);
              goto LAB_000b9750;
            }
          }
          break;
        default:
          if (iVar8 == 0) goto switchD_000b9384_caseD_b;
        }
      }
switchD_000b9318_caseD_9f:
      puVar4 = *(uint **)(uVar3 + 0x194);
      uVar13 = uVar13 + 1;
    } while (uVar13 < *puVar4);
  }
  return (Mission *)0x0;
}

// ===== Status::setJumpgateUsed  @0x000b9830  (6 bytes)
/* Status::setJumpgateUsed(int) */

void __thiscall Status::setJumpgateUsed(Status *this,int param_1)

{
  *(int *)(this + 0x1dc) = param_1;
  return;
}

// ===== Status::jumpgateUsed  @0x000b9836  (12 bytes)
/* Status::jumpgateUsed() */

void __thiscall Status::jumpgateUsed(Status *this)

{
  *(int *)(this + 0x1dc) = *(int *)(this + 0x1dc) + 1;
  return;
}

// ===== Status::getJumpgateUsed  @0x000b9842  (6 bytes)
/* Status::getJumpgateUsed() */

undefined4 __thiscall Status::getJumpgateUsed(Status *this)

{
  return *(undefined4 *)(this + 0x1dc);
}

// ===== Status::crateCaptured  @0x000b9848  (12 bytes)
/* Status::crateCaptured(int) */

void __thiscall Status::crateCaptured(Status *this,int param_1)

{
  *(int *)(this + 0x1e0) = param_1 + *(int *)(this + 0x1e0);
  return;
}

// ===== Status::setCapturedCrates  @0x000b9854  (6 bytes)
/* Status::setCapturedCrates(int) */

void __thiscall Status::setCapturedCrates(Status *this,int param_1)

{
  *(int *)(this + 0x1e0) = param_1;
  return;
}

// ===== Status::getCapturedCrates  @0x000b985a  (6 bytes)
/* Status::getCapturedCrates() */

undefined4 __thiscall Status::getCapturedCrates(Status *this)

{
  return *(undefined4 *)(this + 0x1e0);
}

// ===== Status::incEquipmentBought  @0x000b9860  (12 bytes)
/* Status::incEquipmentBought() */

void __thiscall Status::incEquipmentBought(Status *this)

{
  *(int *)(this + 0x1e4) = *(int *)(this + 0x1e4) + 1;
  return;
}

// ===== Status::setBoughtEquipment  @0x000b986c  (6 bytes)
/* Status::setBoughtEquipment(int) */

void __thiscall Status::setBoughtEquipment(Status *this,int param_1)

{
  *(int *)(this + 0x1e4) = param_1;
  return;
}

// ===== Status::getBoughtEquipment  @0x000b9872  (6 bytes)
/* Status::getBoughtEquipment() */

undefined4 __thiscall Status::getBoughtEquipment(Status *this)

{
  return *(undefined4 *)(this + 0x1e4);
}

// ===== Status::removeMission  @0x000b9878  (156 bytes)
/* Status::removeMission(Mission*) */

void __thiscall Status::removeMission(Status *this,Mission *param_1)

{
  uint *puVar1;
  int iVar2;
  Agent *this_00;
  void *pvVar3;
  Mission *pMVar4;
  uint uVar5;
  uint uVar6;
  
  puVar1 = *(uint **)(this + 0x194);
  if (*puVar1 != 0) {
    uVar6 = 0;
    do {
      uVar5 = puVar1[1];
      if (*(Mission **)(uVar5 + uVar6 * 4) == param_1) {
        pMVar4 = param_1;
        if (*(Mission **)(this + 400) == param_1) {
          param_1 = (Mission *)0x0;
          *(undefined4 *)(this + 400) = 0;
          pMVar4 = *(Mission **)(uVar5 + uVar6 * 4);
        }
        iVar2 = Mission::getAgent(pMVar4);
        if (iVar2 != 0) {
          this_00 = (Agent *)Mission::getAgent(*(Mission **)
                                                (*(int *)(*(int *)(this + 0x194) + 4) + uVar6 * 4));
          Agent::setMission(this_00,(Mission *)0x0);
        }
        iVar2 = *(int *)(*(int *)(this + 0x194) + 4);
        pMVar4 = *(Mission **)(iVar2 + uVar6 * 4);
        if (pMVar4 != (Mission *)0x0) {
          pvVar3 = (void *)Mission::~Mission(pMVar4);
          operator_delete(pvVar3);
          iVar2 = *(int *)(*(int *)(this + 0x194) + 4);
        }
        *(undefined4 *)(iVar2 + uVar6 * 4) = 0;
        *(undefined4 *)(*(int *)(*(int *)(this + 0x194) + 4) + uVar6 * 4) = Mission::empty;
        puVar1 = *(uint **)(this + 0x194);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *puVar1);
  }
  return;
}

// ===== Status::visitStation  @0x000b9918  (12 bytes)
/* Status::visitStation() */

void __thiscall Status::visitStation(Status *this)

{
  *(int *)(this + 0x1d0) = *(int *)(this + 0x1d0) + 1;
  return;
}

// ===== Status::getPlanetNames  @0x000b9924  (6 bytes)
/* Status::getPlanetNames() */

undefined4 __thiscall Status::getPlanetNames(Status *this)

{
  return *(undefined4 *)(this + 0x1a4);
}

// ===== Status::getPlanetTextures  @0x000b992a  (6 bytes)
/* Status::getPlanetTextures() */

undefined4 __thiscall Status::getPlanetTextures(Status *this)

{
  return *(undefined4 *)(this + 0x1a8);
}

// ===== Status::getCredits  @0x000b9930  (6 bytes)
/* Status::getCredits() */

undefined4 __thiscall Status::getCredits(Status *this)

{
  return *(undefined4 *)(this + 0x1ac);
}

// ===== Status::setRating  @0x000b9936  (6 bytes)
/* Status::setRating(int) */

void __thiscall Status::setRating(Status *this,int param_1)

{
  *(int *)(this + 0x1b0) = param_1;
  return;
}

// ===== Status::setPlayingTime  @0x000b993c  (6 bytes)
/* Status::setPlayingTime(long long) */

void Status::setPlayingTime(longlong param_1)

{
  undefined4 in_r2;
  undefined4 in_r3;
  
  *(undefined4 *)((int)param_1 + 0x1b8) = in_r2;
  *(undefined4 *)((int)param_1 + 0x1bc) = in_r3;
  return;
}

// ===== Status::setKills  @0x000b9942  (6 bytes)
/* Status::setKills(int) */

void __thiscall Status::setKills(Status *this,int param_1)

{
  *(int *)(this + 0x1c0) = param_1;
  return;
}

// ===== Status::setMissionCount  @0x000b9948  (6 bytes)
/* Status::setMissionCount(int) */

void __thiscall Status::setMissionCount(Status *this,int param_1)

{
  *(int *)(this + 0x1c4) = param_1;
  return;
}

// ===== Status::setLevel  @0x000b994e  (6 bytes)
/* Status::setLevel(int) */

void __thiscall Status::setLevel(Status *this,int param_1)

{
  *(int *)(this + 0x1c8) = param_1;
  return;
}

// ===== Status::setLastXP  @0x000b9954  (6 bytes)
/* Status::setLastXP(int) */

void __thiscall Status::setLastXP(Status *this,int param_1)

{
  *(int *)(this + 0x1cc) = param_1;
  return;
}

// ===== Status::setGoodsProduced  @0x000b995a  (6 bytes)
/* Status::setGoodsProduced(int) */

void __thiscall Status::setGoodsProduced(Status *this,int param_1)

{
  *(int *)(this + 0x1d4) = param_1;
  return;
}

// ===== Status::getGoodsProduced  @0x000b9960  (6 bytes)
/* Status::getGoodsProduced() */

undefined4 __thiscall Status::getGoodsProduced(Status *this)

{
  return *(undefined4 *)(this + 0x1d4);
}

// ===== Status::incGoodsProduced  @0x000b9966  (12 bytes)
/* Status::incGoodsProduced(int) */

void __thiscall Status::incGoodsProduced(Status *this,int param_1)

{
  *(int *)(this + 0x1d4) = param_1 + *(int *)(this + 0x1d4);
  return;
}

// ===== Status::setCredits  @0x000b9972  (6 bytes)
/* Status::setCredits(int) */

void __thiscall Status::setCredits(Status *this,int param_1)

{
  *(int *)(this + 0x1ac) = param_1;
  return;
}

// ===== Status::checkForLevelUp  @0x000b9978  (98 bytes)
/* Status::checkForLevelUp() */

void __thiscall Status::checkForLevelUp(Status *this)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((int)(&DAT_00252b0c)[iVar1] <=
        *(int *)(this + 0xa0) / 0x32 + *(int *)(this + 0x1c0) + *(int *)(this + 0xd4) / 3 +
        *(int *)(this + 0xa4) + *(int *)(this + 0x1c4) * 2 + *(int *)(this + 0x1e8) +
        *(int *)(this + 0x1d0)) {
      *(int *)(this + 0x1c8) = iVar1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0x15);
  return;
}

// ===== Status::getRating  @0x000b99e0  (6 bytes)
/* Status::getRating() */

undefined4 __thiscall Status::getRating(Status *this)

{
  return *(undefined4 *)(this + 0x1b0);
}

// ===== Status::getLastXP  @0x000b99e6  (6 bytes)
/* Status::getLastXP() */

undefined4 __thiscall Status::getLastXP(Status *this)

{
  return *(undefined4 *)(this + 0x1cc);
}

// ===== Status::changeRating  @0x000b99ec  (36 bytes)
/* Status::changeRating(int) */

void __thiscall Status::changeRating(Status *this,int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = param_1 + *(int *)(this + 0x1b0);
  *(int *)(this + 0x1b0) = iVar1;
  if (iVar1 < 0xb) {
    if (-0xb < iVar1) {
      return;
    }
    uVar2 = 0xfffffff6;
  }
  else {
    uVar2 = 10;
  }
  *(undefined4 *)(this + 0x1b0) = uVar2;
  return;
}

// ===== Status::getKills  @0x000b9a10  (6 bytes)
/* Status::getKills() */

undefined4 __thiscall Status::getKills(Status *this)

{
  return *(undefined4 *)(this + 0x1c0);
}

// ===== Status::incKills  @0x000b9a18  (24 bytes)
/* Status::incKills() */

void __thiscall Status::incKills(Status *this)

{
  *(int *)(this + 0x1c0) = *(int *)(this + 0x1c0) + 1;
  Achievements::incKills(Globals::achievements);
  return;
}

// ===== Status::setPirateKills  @0x000b9a34  (6 bytes)
/* Status::setPirateKills(int) */

void __thiscall Status::setPirateKills(Status *this,int param_1)

{
  *(int *)(this + 0x1d8) = param_1;
  return;
}

// ===== Status::getPirateKills  @0x000b9a3a  (6 bytes)
/* Status::getPirateKills() */

undefined4 __thiscall Status::getPirateKills(Status *this)

{
  return *(undefined4 *)(this + 0x1d8);
}

// ===== Status::incPirateKills  @0x000b9a40  (24 bytes)
/* Status::incPirateKills() */

void __thiscall Status::incPirateKills(Status *this)

{
  *(int *)(this + 0x1d8) = *(int *)(this + 0x1d8) + 1;
  Achievements::incPirateKills(Globals::achievements);
  return;
}

// ===== Status::addKills  @0x000b9a5c  (12 bytes)
/* Status::addKills(int) */

void __thiscall Status::addKills(Status *this,int param_1)

{
  *(int *)(this + 0x1c0) = param_1 + *(int *)(this + 0x1c0);
  return;
}

// ===== Status::getMissionCount  @0x000b9a68  (6 bytes)
/* Status::getMissionCount() */

undefined4 __thiscall Status::getMissionCount(Status *this)

{
  return *(undefined4 *)(this + 0x1c4);
}

// ===== Status::getLevel  @0x000b9a6e  (6 bytes)
/* Status::getLevel() */

undefined4 __thiscall Status::getLevel(Status *this)

{
  return *(undefined4 *)(this + 0x1c8);
}

// ===== Status::getStanding  @0x000b9a74  (4 bytes)
/* Status::getStanding() */

undefined4 __thiscall Status::getStanding(Status *this)

{
  return *(undefined4 *)(this + 0x14);
}

// ===== Status::getBluePrints  @0x000b9a78  (4 bytes)
/* Status::getBluePrints() */

undefined4 __thiscall Status::getBluePrints(Status *this)

{
  return *(undefined4 *)(this + 0x18);
}

// ===== Status::unlockBluePrint  @0x000b9a7c  (58 bytes)
/* Status::unlockBluePrint(int) */

void __thiscall Status::unlockBluePrint(Status *this,int param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  puVar1 = *(uint **)(this + 0x18);
  if (*puVar1 != 0) {
    uVar3 = 0;
    do {
      iVar2 = BluePrint::getIndex(*(BluePrint **)(puVar1[1] + uVar3 * 4));
      if (iVar2 == param_1) {
        BluePrint::unlock(*(BluePrint **)(*(int *)(*(int *)(this + 0x18) + 4) + uVar3 * 4));
      }
      puVar1 = *(uint **)(this + 0x18);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar1);
  }
  return;
}

// ===== Status::isBlueprintUnlocked  @0x000b9ab6  (62 bytes)
/* Status::isBlueprintUnlocked(int) */

undefined4 __thiscall Status::isBlueprintUnlocked(Status *this,int param_1)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  puVar1 = *(uint **)(this + 0x18);
  if (*puVar1 != 0) {
    uVar4 = 0;
    do {
      iVar2 = BluePrint::getIndex(*(BluePrint **)(puVar1[1] + uVar4 * 4));
      if (iVar2 == param_1) {
        uVar3 = BluePrint::isUnlocked
                          (*(BluePrint **)(*(int *)(*(int *)(this + 0x18) + 4) + uVar4 * 4));
        return uVar3;
      }
      puVar1 = *(uint **)(this + 0x18);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar1);
  }
  return 0;
}

// ===== Status::getAgents  @0x000b9af4  (4 bytes)
/* Status::getAgents() */

undefined4 __thiscall Status::getAgents(Status *this)

{
  return *(undefined4 *)(this + 0x20);
}

// ===== Status::incPlayingTime  @0x000b9af8  (16 bytes)
/* Status::incPlayingTime(long long) */

void Status::incPlayingTime(longlong param_1)

{
  int iVar1;
  uint uVar2;
  uint in_r2;
  int in_r3;
  
  iVar1 = (int)param_1;
  uVar2 = *(uint *)(iVar1 + 0x1b8);
  *(uint *)(iVar1 + 0x1b8) = uVar2 + in_r2;
  *(uint *)(iVar1 + 0x1bc) = *(int *)(iVar1 + 0x1bc) + in_r3 + (uint)CARRY4(uVar2,in_r2);
  return;
}

// ===== Status::getWingmen  @0x000b9b08  (4 bytes)
/* Status::getWingmen() */

undefined4 __thiscall Status::getWingmen(Status *this)

{
  return *(undefined4 *)(this + 0x24);
}

// ===== Status::setWingmen  @0x000b9b0c  (122 bytes)
/* Status::setWingmen(Array<AbyssEngine::String*>*) */

void __thiscall Status::setWingmen(Status *this,Array *param_1)

{
  Array *pAVar1;
  undefined4 *puVar2;
  String *this_00;
  uint uVar3;
  
  if (*(Array **)(this + 0x24) != (Array *)0x0) {
    ArrayReleaseClasses<AbyssEngine::String*>(*(Array **)(this + 0x24));
  }
  if (param_1 == (Array *)0x0) {
    *(undefined4 *)(this + 0x30) = 0;
    *(undefined4 *)(this + 0x24) = 0;
    *(undefined4 *)(this + 0x28) = 0;
  }
  else {
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x24) = pAVar1;
    ArraySetLength<AbyssEngine::String*>(*(uint *)param_1,pAVar1);
    if (*(int *)param_1 != 0) {
      uVar3 = 0;
      do {
        this_00 = operator_new(8);
        AbyssEngine::String::String(this_00,*(String **)(*(int *)(param_1 + 4) + uVar3 * 4),false);
        *(String **)(*(int *)(*(int *)(this + 0x24) + 4) + uVar3 * 4) = this_00;
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(uint *)param_1);
    }
  }
  return;
}

// ===== Status::replaceHash  @0x000b9b98  (104 bytes)
/* Status::replaceHash(AbyssEngine::String, AbyssEngine::String) */

void Status::replaceHash(undefined4 param_1,undefined4 param_2,String *param_3,String *param_4)

{
  undefined8 uVar1;
  String aSStack_2c [8];
  String aSStack_24 [8];
  String aSStack_1c [8];
  int local_14;
  
  local_14 = __stack_chk_guard;
  AbyssEngine::String::String(aSStack_1c,param_3,false);
  AbyssEngine::String::String(aSStack_24,param_4,false);
  uVar1 = AbyssEngine::String::String(aSStack_2c,"#",false);
  replaceHash(param_1,(int)((ulonglong)uVar1 >> 0x20),aSStack_1c,aSStack_24,(int)uVar1);
  AbyssEngine::String::~String(aSStack_2c);
  AbyssEngine::String::~String(aSStack_24);
  AbyssEngine::String::~String(aSStack_1c);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Status::replaceHash  @0x000b9c30  (214 bytes)
/* Status::replaceHash(AbyssEngine::String, AbyssEngine::String, AbyssEngine::String) */

void Status::replaceHash(AbyssEngine *param_1,undefined4 param_2,String *param_3,String *param_4,
                        String *param_5)

{
  undefined1 *puVar1;
  int iVar2;
  String aSStack_40 [8];
  String aSStack_38 [8];
  AbyssEngine aAStack_30 [8];
  String aSStack_28 [4];
  int local_24;
  int local_20;
  
  local_20 = __stack_chk_guard;
  iVar2 = AbyssEngine::String::IndexOf(param_3,param_5);
  if (iVar2 < 0) {
    AbyssEngine::String::String((String *)param_1,param_3,false);
  }
  else {
    AbyssEngine::String::SubString((uint)aSStack_28,(uint)param_3);
    if (local_24 == 0) {
      AbyssEngine::String::String((String *)aAStack_30,param_4,false);
      AbyssEngine::String::SubString((uint)aSStack_38,(uint)param_3);
      AbyssEngine::operator+(param_1,aAStack_30,aSStack_38);
      AbyssEngine::String::~String(aSStack_38);
      puVar1 = &stack0xfffffff4;
    }
    else {
      AbyssEngine::String::String(aSStack_38,param_4,false);
      AbyssEngine::operator+(aAStack_30,aSStack_28,aSStack_38);
      AbyssEngine::String::SubString((uint)aSStack_40,(uint)param_3);
      AbyssEngine::operator+(param_1,aAStack_30,aSStack_40);
      AbyssEngine::String::~String(aSStack_40);
      AbyssEngine::String::~String((String *)aAStack_30);
      puVar1 = &stack0xffffffec;
    }
    AbyssEngine::String::~String((String *)(puVar1 + -0x24));
    AbyssEngine::String::~String(aSStack_28);
  }
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Status::stringHasToken  @0x000b9d54  (26 bytes)
/* Status::stringHasToken(AbyssEngine::String, AbyssEngine::String) */

bool __thiscall Status::stringHasToken(undefined4 param_1,String *param_2,String *param_3)

{
  uint uVar1;
  
  uVar1 = AbyssEngine::String::IndexOf(param_2,param_3);
  return uVar1 < 0x80000000;
}

// ===== Status::calcCargoPrices  @0x000b9d70  (718 bytes)
/* Status::calcCargoPrices() */

void __thiscall Status::calcCargoPrices(Status *this)

{
  Galaxy *pGVar1;
  AERandom *pAVar2;
  bool bVar3;
  int iVar4;
  uint *puVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  Item *this_00;
  int iVar12;
  uint uVar13;
  uint in_fpscr;
  float fVar14;
  float fVar15;
  float fVar16;
  
  iVar4 = Galaxy::getSystems(Globals::galaxy);
  iVar12 = 0;
  do {
    if (iVar12 == 1) {
      puVar5 = (uint *)Ship::getEquipment(*(Ship **)(this + 0x18c));
    }
    else if (iVar12 == 0) {
      puVar5 = (uint *)Ship::getCargo(*(Ship **)(this + 0x18c));
    }
    else {
      puVar5 = (uint *)Station::getItems(*(Station **)(this + 0x198));
    }
    pAVar2 = Globals::rnd;
    if (puVar5 != (uint *)0x0) {
      uVar6 = Station::getIndex(*(Station **)(this + 0x198));
      AbyssEngine::AERandom::setSeed(CONCAT44(uVar6,pAVar2));
      iVar7 = Station::equals(*(Station **)(Globals::status + 0x198),
                              *(Station **)(Globals::status + 0x78));
      if (iVar7 == 0) {
        iVar7 = SolarSystem::getIndex(*(SolarSystem **)(Globals::status + 0x1a0));
        bVar3 = false;
        if (iVar7 == 0x19) {
          bVar3 = true;
        }
      }
      else {
        bVar3 = false;
      }
      if (*puVar5 != 0) {
        uVar13 = 0;
        do {
          pGVar1 = Globals::galaxy;
          this_00 = *(Item **)(puVar5[1] + uVar13 * 4);
          if (this_00 != (Item *)0x0) {
            iVar7 = Item::getMinPriceSystem(this_00);
            iVar7 = SolarSystem::getX(*(SolarSystem **)(*(int *)(iVar4 + 4) + iVar7 * 4));
            iVar8 = Item::getMinPriceSystem(this_00);
            iVar8 = SolarSystem::getY(*(SolarSystem **)(*(int *)(iVar4 + 4) + iVar8 * 4));
            iVar9 = Item::getMaxPriceSystem(this_00);
            iVar9 = SolarSystem::getX(*(SolarSystem **)(*(int *)(iVar4 + 4) + iVar9 * 4));
            iVar10 = Item::getMaxPriceSystem(this_00);
            iVar10 = SolarSystem::getY(*(SolarSystem **)(*(int *)(iVar4 + 4) + iVar10 * 4));
            uVar6 = Galaxy::distancePercent(pGVar1,iVar7,iVar8,iVar9,iVar10);
            pGVar1 = Globals::galaxy;
            iVar7 = Item::getMinPriceSystem(*(Item **)(puVar5[1] + uVar13 * 4));
            iVar7 = SolarSystem::getX(*(SolarSystem **)(*(int *)(iVar4 + 4) + iVar7 * 4));
            iVar8 = Item::getMinPriceSystem(*(Item **)(puVar5[1] + uVar13 * 4));
            iVar8 = SolarSystem::getY(*(SolarSystem **)(*(int *)(iVar4 + 4) + iVar8 * 4));
            iVar9 = Station::getSystem(*(Station **)(this + 0x198));
            iVar9 = SolarSystem::getX(*(SolarSystem **)(*(int *)(iVar4 + 4) + iVar9 * 4));
            iVar10 = Station::getSystem(*(Station **)(this + 0x198));
            iVar10 = SolarSystem::getY(*(SolarSystem **)(*(int *)(iVar4 + 4) + iVar10 * 4));
            uVar11 = Galaxy::distancePercent(pGVar1,iVar7,iVar8,iVar9,iVar10);
            fVar14 = (float)VectorSignedToFloat(uVar6,(byte)(in_fpscr >> 0x16) & 3);
            fVar15 = (float)VectorSignedToFloat(uVar11,(byte)(in_fpscr >> 0x16) & 3);
            fVar16 = ((100.0 / fVar14) * fVar15) / 100.0;
            iVar7 = Item::getMinPrice(this_00);
            iVar8 = Item::getMaxPrice(this_00);
            iVar9 = Item::getMinPrice(this_00);
            in_fpscr = in_fpscr & 0xfffffff;
            fVar15 = (float)VectorSignedToFloat(iVar8 - iVar9,(byte)(in_fpscr >> 0x16) & 3);
            fVar14 = 1.0;
            if (fVar16 < 1.0) {
              fVar14 = fVar16;
            }
            iVar8 = Item::getSinglePrice(this_00);
            if (0 < iVar8) {
              if (bVar3) {
                iVar9 = Item::getMaxPrice(this_00);
              }
              else {
                iVar7 = iVar7 + (int)(fVar14 * fVar15);
                fVar14 = (float)VectorSignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
                iVar8 = (int)(fVar14 * 0.02);
                if (iVar8 < 1) {
                  iVar8 = 1;
                }
                iVar9 = AbyssEngine::AERandom::nextInt(Globals::rnd,iVar8 << 1 | 1);
                iVar9 = (iVar7 - iVar8) + iVar9;
              }
              if (Globals::globalPriceRaise != 0) {
                fVar14 = (float)VectorSignedToFloat(Globals::globalPriceRaise,
                                                    (byte)(in_fpscr >> 0x16) & 3);
                fVar15 = (float)VectorSignedToFloat(iVar9,(byte)(in_fpscr >> 0x16) & 3);
                iVar9 = (int)(fVar15 + fVar15 * fVar14 * 0.01);
              }
              Item::setPrice(this_00,iVar9);
            }
          }
          uVar13 = uVar13 + 1;
        } while (uVar13 < *puVar5);
      }
      AbyssEngine::AERandom::reset(Globals::rnd);
    }
    iVar12 = iVar12 + 1;
  } while (iVar12 != 3);
  return;
}

// ===== Status::loadAgents  @0x000ba06c  (40 bytes)
/* Status::loadAgents() */

void __thiscall Status::loadAgents(Status *this)

{
  FileRead *this_00;
  undefined4 uVar1;
  void *pvVar2;
  
  this_00 = operator_new(1);
  FileRead::FileRead(this_00);
  uVar1 = FileRead::loadAgents();
  *(undefined4 *)(this + 0x20) = uVar1;
  pvVar2 = (void *)FileRead::~FileRead(this_00);
  operator_delete(pvVar2);
  return;
}

// ===== Status::loadAgents  @0x000ba0a2  (2 bytes)
/* Status::loadAgents(Array<int>*) */

Array * Status::loadAgents(Array *param_1)

{
  return param_1;
}

// ===== Status::getCollectedBounties  @0x000ba0a4  (14 bytes)
/* Status::getCollectedBounties(int) */

undefined4 __thiscall Status::getCollectedBounties(Status *this,int param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 4) {
    uVar1 = *(undefined4 *)(this + param_1 * 4 + 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

// ===== Status::incCollectedBounties  @0x000ba0b2  (16 bytes)
/* Status::incCollectedBounties(int) */

void __thiscall Status::incCollectedBounties(Status *this,int param_1)

{
  int iVar1;
  
  iVar1 = param_1;
  if (param_1 < 4) {
    this = this + param_1 * 4;
    iVar1 = *(int *)(this + 4) + 1;
  }
  if (param_1 < 4) {
    *(int *)(this + 4) = iVar1;
  }
  return;
}

// ===== Status::isFreighterMissionStation  @0x000ba0c2  (64 bytes)
/* Status::isFreighterMissionStation(int) */

bool __thiscall Status::isFreighterMissionStation(Status *this,int param_1)

{
  bool bVar1;
  
  bVar1 = true;
  if ((param_1 - 0x1eU < 0x1f) && ((1 << (param_1 - 0x1eU & 0xff) & 0x40008401U) != 0)) {
    return true;
  }
  if (((0x19 < param_1 - 0x46U) || ((1 << (param_1 - 0x46U & 0xff) & 0x2008401U) == 0)) &&
     (bVar1 = param_1 == 0xf, !bVar1)) {
    return false;
  }
  return bVar1;
}

// ===== Status::getFreighterMissionStationBit  @0x000ba102  (94 bytes)
/* Status::getFreighterMissionStationBit(int) */

undefined4 __thiscall Status::getFreighterMissionStationBit(Status *this,int param_1)

{
  if (param_1 < 0x3c) {
    if (param_1 < 0x28) {
      if (param_1 == 0xf) {
        return 4;
      }
      if (param_1 == 0x1e) {
        return 2;
      }
    }
    else {
      if (param_1 == 0x28) {
        return 3;
      }
      if (param_1 == 0x2d) {
        return 9;
      }
    }
  }
  else if (param_1 < 0x50) {
    if (param_1 == 0x3c) {
      return 5;
    }
    if (param_1 == 0x46) {
      return 7;
    }
  }
  else {
    if (param_1 == 0x50) {
      return 8;
    }
    if (param_1 == 0x55) {
      return 1;
    }
    if (param_1 == 0x5f) {
      return 6;
    }
  }
  return 0;
}

// ===== Status::getGammaRayDamagePerSecond  @0x000ba160  (68 bytes)
/* Status::getGammaRayDamagePerSecond(int, int) */

undefined4 __thiscall Status::getGammaRayDamagePerSecond(Status *this,int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = param_1 - 0x6d;
  if (uVar1 < 5) {
    if (param_2 < 0x6a) {
      return *(undefined4 *)(&DAT_00252b60 + uVar1 * 4);
    }
    if (*(int *)(this + 0x1e8) < 0x9e) {
      return *(undefined4 *)(&DAT_00252b80 + uVar1 * 4);
    }
    uVar2 = 0;
    if (param_1 == 0x6d) {
      uVar2 = 0x3f800000;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

// ===== Status::loadWanted  @0x000ba1b0  (40 bytes)
/* Status::loadWanted() */

void __thiscall Status::loadWanted(Status *this)

{
  FileRead *this_00;
  undefined4 uVar1;
  void *pvVar2;
  
  this_00 = operator_new(1);
  FileRead::FileRead(this_00);
  uVar1 = FileRead::loadWanted();
  *(undefined4 *)this = uVar1;
  pvVar2 = (void *)FileRead::~FileRead(this_00);
  operator_delete(pvVar2);
  return;
}

// ===== Status::getWanted  @0x000ba1e6  (4 bytes)
/* Status::getWanted() */

undefined4 __thiscall Status::getWanted(Status *this)

{
  return *(undefined4 *)this;
}

// ===== Status::isStorylineWanted  @0x000ba1ea  (12 bytes)
/* Status::isStorylineWanted(int) */

bool __thiscall Status::isStorylineWanted(Status *this,int param_1)

{
  return (param_1 | 1U) == 1;
}

// ===== Status::wantedBoardAccessible  @0x000ba1f8  (160 bytes)
/* Status::wantedBoardAccessible() */

undefined4 Status::wantedBoardAccessible(void)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar3 = (uint *)*Globals::status;
  if (*puVar3 != 0) {
    uVar4 = 0;
    do {
      iVar1 = SolarSystem::getRace((SolarSystem *)Globals::status[0x68]);
      iVar2 = Wanted::getBoard(*(Wanted **)(puVar3[1] + uVar4 * 4));
      if ((((iVar1 == iVar2) &&
           (iVar2 = Globals::status[0x7a],
           iVar1 = Wanted::getRequiredMission(*(Wanted **)(puVar3[1] + uVar4 * 4)), iVar1 <= iVar2))
          && (iVar1 = Station::equals((Station *)Globals::status[0x66],
                                      (Station *)Globals::status[0x1e]), iVar1 == 0)) &&
         (iVar1 = Station::getIndex((Station *)Globals::status[0x66]), iVar1 != 0x6c)) {
        return 1;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar3);
  }
  return 0;
}

// ===== Status::activateNewWanted  @0x000ba2ac  (1100 bytes)
/* Status::activateNewWanted() */

int Status::activateNewWanted(void)

{
  undefined4 *puVar1;
  AERandom *this;
  uint uVar2;
  int iVar3;
  int iVar4;
  FileRead *this_00;
  Station *this_01;
  Station *this_02;
  uint *puVar5;
  int *piVar6;
  void *pvVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  Array *pAVar11;
  int local_60;
  SystemPathFinder *local_44;
  uint local_34;
  
  puVar8 = (uint *)*Globals::status;
  if (*puVar8 == 0) {
    return 0;
  }
  pAVar11 = (Array *)0x0;
  local_60 = 0;
  uVar10 = 0;
  local_44 = (SystemPathFinder *)0x0;
LAB_000ba364:
  if ((int)uVar10 < 2) {
    local_34 = 4;
    uVar2 = 2;
  }
  else {
    iVar3 = (int)(uVar10 - 1) % 6;
    local_34 = iVar3 / 2 + 4;
    uVar2 = iVar3 / 3 + 2;
  }
  iVar3 = SolarSystem::getRace((SolarSystem *)Globals::status[0x68]);
  iVar4 = Wanted::getBoard(*(Wanted **)(puVar8[1] + uVar10 * 4));
  if ((((iVar3 == iVar4) &&
       (iVar4 = Globals::status[0x7a],
       iVar3 = Wanted::getRequiredMission(*(Wanted **)(puVar8[1] + uVar10 * 4)), iVar3 <= iVar4)) &&
      (((uVar10 | 1) != 1 ||
       (iVar4 = Globals::status[0x7a],
       iVar3 = Wanted::getRequiredMission(*(Wanted **)(puVar8[1] + uVar10 * 4)), iVar4 <= iVar3))))
     && ((((iVar3 = Station::equals((Station *)Globals::status[0x66],
                                    (Station *)Globals::status[0x1e]), iVar3 == 0 &&
           (iVar3 = Station::getIndex((Station *)Globals::status[0x66]), iVar3 != 0x6c)) &&
          (iVar3 = Wanted::isActive(*(Wanted **)(puVar8[1] + uVar10 * 4)), iVar3 == 0)) &&
         (iVar3 = Wanted::isTerminated(*(Wanted **)(puVar8[1] + uVar10 * 4)),
         puVar1 = Globals::status, iVar3 == 0)))) {
    iVar3 = Wanted::getBoard(*(Wanted **)(puVar8[1] + uVar10 * 4));
    if (iVar3 < 4) {
      iVar3 = puVar1[iVar3 + 1];
    }
    else {
      iVar3 = 0;
    }
    iVar4 = Wanted::getRequiredBounties(*(Wanted **)(puVar8[1] + uVar10 * 4));
    if (iVar4 <= iVar3) {
      Wanted::setActive(*(Wanted **)(puVar8[1] + uVar10 * 4),true);
      if (local_44 == (SystemPathFinder *)0x0) {
        local_44 = operator_new(1);
        SystemPathFinder::SystemPathFinder(local_44);
        this_00 = operator_new(1);
        FileRead::FileRead(this_00);
        pAVar11 = (Array *)FileRead::loadSystemsBinary();
        pvVar7 = (void *)FileRead::~FileRead(this_00);
        operator_delete(pvVar7);
      }
      local_60 = local_60 + 1;
LAB_000ba4c4:
      this_01 = (Station *)Globals::getRandomStation();
      while( true ) {
        iVar3 = Station::getSystem(this_01);
        iVar3 = SolarSystem::getRoutes(*(SolarSystem **)(*(int *)(pAVar11 + 4) + iVar3 * 4));
        if (((iVar3 != 0) &&
            (iVar4 = Globals::status[0xe], iVar3 = Station::getSystem(this_01),
            *(char *)(*(int *)(iVar4 + 4) + iVar3) != '\0')) &&
           ((((iVar3 = Station::getSystem(this_01), iVar3 != 0x1b &&
              ((iVar3 = Station::getSystem(this_01), iVar3 != 0x1c &&
               (iVar3 = Station::getSystem(this_01), iVar3 != 0x19)))) &&
             (iVar3 = Station::getSystem(this_01), iVar3 != 6)) &&
            (iVar3 = Station::getSystem(this_01), iVar3 != 0x1a)))) break;
        if (this_01 != (Station *)0x0) {
          pvVar7 = (void *)Station::~Station(this_01);
          operator_delete(pvVar7);
        }
        this_01 = (Station *)Globals::getRandomStation();
      }
LAB_000ba54c:
      this_02 = (Station *)Globals::getRandomStation();
      iVar3 = Station::getSystem(this_02);
      iVar3 = SolarSystem::getRoutes(*(SolarSystem **)(*(int *)(pAVar11 + 4) + iVar3 * 4));
      if ((((iVar3 != 0) &&
           (iVar4 = Globals::status[0xe], iVar3 = Station::getSystem(this_02),
           *(char *)(*(int *)(iVar4 + 4) + iVar3) != '\0')) &&
          (iVar3 = Station::getSystem(this_02), iVar3 != 0x1b)) &&
         (((iVar3 = Station::getSystem(this_02), iVar3 != 0x1c &&
           (iVar3 = Station::getSystem(this_02), iVar3 != 0x19)) &&
          ((iVar3 = Station::getSystem(this_02), iVar3 != 0x1a &&
           (iVar3 = Station::getSystem(this_02), iVar3 != 6)))))) {
        iVar3 = Station::getSystem(this_02);
        iVar4 = Station::getSystem(this_01);
        if (iVar3 != iVar4) goto LAB_000ba5ce;
      }
      if (this_02 != (Station *)0x0) {
        pvVar7 = (void *)Station::~Station(this_02);
        operator_delete(pvVar7);
      }
      goto LAB_000ba54c;
    }
  }
  goto LAB_000ba6ba;
LAB_000ba5ce:
  iVar3 = Station::getIndex(this_01);
  Wanted::setLastSeen(*(Wanted **)(puVar8[1] + uVar10 * 4),iVar3);
  iVar3 = Station::getIndex(this_02);
  Wanted::setTravelsTo(*(Wanted **)(puVar8[1] + uVar10 * 4),iVar3);
  iVar3 = Station::getSystem(this_01);
  iVar4 = Station::getSystem(this_02);
  if (this_01 != (Station *)0x0) {
    pvVar7 = (void *)Station::~Station(this_01);
    operator_delete(pvVar7);
  }
  if (this_02 != (Station *)0x0) {
    pvVar7 = (void *)Station::~Station(this_02);
    operator_delete(pvVar7);
  }
  puVar5 = (uint *)SystemPathFinder::getSystemPath(local_44,pAVar11,iVar3,iVar4);
  if (((puVar5 == (uint *)0x0) || (uVar9 = *puVar5, uVar9 < uVar2)) || (local_34 < uVar9))
  goto LAB_000ba4c4;
  iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,uVar9);
  iVar4 = *(int *)(puVar5[1] + iVar3 * 4);
  iVar3 = SolarSystem::getStations(*(SolarSystem **)(*(int *)(pAVar11 + 4) + iVar4 * 4));
  this = Globals::rnd;
  if (iVar3 != 0) {
    piVar6 = (int *)SolarSystem::getStations(*(SolarSystem **)(*(int *)(pAVar11 + 4) + iVar4 * 4));
    iVar3 = AbyssEngine::AERandom::nextInt(this,*piVar6);
    iVar4 = SolarSystem::getStations(*(SolarSystem **)(*(int *)(pAVar11 + 4) + iVar4 * 4));
    Wanted::setCurrentLocation
              (*(Wanted **)(puVar8[1] + uVar10 * 4),*(int *)(*(int *)(iVar4 + 4) + iVar3 * 4));
  }
  if ((void *)puVar5[1] != (void *)0x0) {
    operator_delete__((void *)puVar5[1]);
  }
  operator_delete(puVar5);
LAB_000ba6ba:
  uVar10 = uVar10 + 1;
  if (*puVar8 <= uVar10) {
    if (local_44 != (SystemPathFinder *)0x0) {
      pvVar7 = (void *)SystemPathFinder::~SystemPathFinder(local_44);
      operator_delete(pvVar7);
    }
    if (pAVar11 == (Array *)0x0) {
      return local_60;
    }
    ArrayReleaseClasses<SolarSystem*>(pAVar11);
    if (*(void **)(pAVar11 + 4) != (void *)0x0) {
      operator_delete__(*(void **)(pAVar11 + 4));
    }
    operator_delete(pAVar11);
    return local_60;
  }
  goto LAB_000ba364;
}

// ===== Status::resetGame  @0x000ba78c  (1752 bytes)
/* Status::resetGame() */

void __thiscall Status::resetGame(Status *this)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  void *pvVar5;
  Station *pSVar6;
  Array *pAVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined1 *puVar10;
  BluePrint *this_00;
  Standing *this_01;
  Mission *this_02;
  Ship *pSVar11;
  Item *pIVar12;
  uint uVar13;
  uint *puVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  
  *(undefined4 *)(this + 0x8c) = 0;
  *(undefined4 *)(this + 0x1ac) = 0;
  *(undefined4 *)(this + 0x1b0) = 0;
  *(undefined4 *)(this + 0x1c0) = 0;
  *(undefined4 *)(this + 0x1c4) = 0;
  *(undefined4 *)(this + 0x1d4) = 0;
  *(undefined4 *)(this + 0x1d8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x1dc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x1e0) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x1e4) = 0;
  *(undefined4 *)(this + 0x1c8) = 1;
  *(undefined4 *)(this + 0x1cc) = 0;
  *(undefined4 *)(this + 0x1d0) = 0;
  *(undefined4 *)(this + 0x1b8) = 0;
  *(undefined4 *)(this + 0x1bc) = 0;
  *(undefined4 *)(this + 0x100) = 0;
  *(undefined4 *)(this + 0x104) = 0;
  *(undefined4 *)(this + 0x10c) = 0;
  this[0x110] = (Status)0x0;
  *(undefined4 *)(this + 0x118) = 0;
  *(undefined4 *)(this + 0x11c) = 0;
  *(undefined4 *)(this + 0x124) = 0;
  *(undefined4 *)(this + 300) = 0;
  *(undefined4 *)(this + 0x134) = 0;
  *(undefined4 *)(this + 0x13c) = 0;
  *(undefined4 *)(this + 0x144) = 0;
  this[0x120] = (Status)0x0;
  this[0x128] = (Status)0x0;
  this[0x130] = (Status)0x0;
  this[0x138] = (Status)0x0;
  this[0x140] = (Status)0x0;
  this[0x148] = (Status)0x0;
  uVar4 = 0;
  if (Globals::options[0x36] != '\0') {
    uVar4 = 3;
  }
  *(undefined4 *)(this + 0x114) = uVar4;
  this[0x111] = (Status)0x0;
  if (*(Station **)(this + 0x14c) != (Station *)0x0) {
    pvVar5 = (void *)Station::~Station(*(Station **)(this + 0x14c));
    operator_delete(pvVar5);
    *(undefined4 *)(this + 0x14c) = 0;
  }
  pSVar6 = operator_new(0x30);
  Station::Station(pSVar6);
  *(Station **)(this + 0x14c) = pSVar6;
  if (*(void **)(this + 0x28) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x28));
    *(undefined4 *)(this + 0x28) = 0;
  }
  if (*(Array **)(this + 0x24) != (Array *)0x0) {
    ArrayReleaseClasses<AbyssEngine::String*>(*(Array **)(this + 0x24));
    pvVar5 = *(void **)(this + 0x24);
    if (pvVar5 != (void *)0x0) {
      if (*(void **)((int)pvVar5 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar5 + 4));
      }
      operator_delete(pvVar5);
    }
  }
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  uVar13 = **(uint **)(this + 0x94);
  if (uVar13 != 0) {
    uVar16 = (*(uint **)(this + 0x94))[1];
    uVar18 = 0;
    do {
      *(undefined1 *)(uVar16 + uVar18) = 0;
      uVar18 = uVar18 + 1;
    } while (uVar18 < uVar13);
  }
  uVar13 = **(uint **)(this + 0x98);
  if (uVar13 != 0) {
    uVar16 = (*(uint **)(this + 0x98))[1];
    uVar18 = 0;
    do {
      *(undefined1 *)(uVar16 + uVar18) = 0;
      uVar18 = uVar18 + 1;
    } while (uVar18 < uVar13);
  }
  *(undefined4 *)(this + 0x9c) = 0;
  *(undefined4 *)(this + 0xa0) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0xa8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  uVar13 = **(uint **)(this + 0xac);
  if (uVar13 != 0) {
    uVar16 = (*(uint **)(this + 0xac))[1];
    uVar18 = 0;
    do {
      *(undefined1 *)(uVar16 + uVar18) = 0;
      uVar18 = uVar18 + 1;
    } while (uVar18 < uVar13);
  }
  *(undefined4 *)(this + 0xb0) = 0;
  uVar13 = **(uint **)(this + 0xb4);
  if (uVar13 != 0) {
    uVar16 = (*(uint **)(this + 0xb4))[1];
    uVar18 = 0;
    do {
      *(undefined1 *)(uVar16 + uVar18) = 0;
      uVar18 = uVar18 + 1;
    } while (uVar18 < uVar13);
  }
  puVar14 = *(uint **)(this + 0x19c);
  if ((puVar14 != (uint *)0x0) && (*puVar14 != 0)) {
    uVar13 = 0;
    do {
      pSVar6 = *(Station **)(puVar14[1] + uVar13 * 4);
      if (pSVar6 != (Station *)0x0) {
        pvVar5 = (void *)Station::~Station(pSVar6);
        operator_delete(pvVar5);
        *(undefined4 *)(*(int *)(*(int *)(this + 0x19c) + 4) + uVar13 * 4) = 0;
        puVar14 = *(uint **)(this + 0x19c);
      }
      uVar13 = uVar13 + 1;
    } while (uVar13 < *puVar14);
  }
  Globals::resetHints();
  Galaxy::reset(Globals::galaxy);
  uVar13 = **(uint **)(this + 0x50);
  if (uVar13 != 0) {
    uVar16 = (*(uint **)(this + 0x50))[1];
    uVar18 = 0;
    do {
      *(undefined1 *)(uVar16 + uVar18) = 0;
      uVar18 = uVar18 + 1;
    } while (uVar18 < uVar13);
  }
  __aeabi_memset(*(undefined4 *)(*(int *)(this + 0x54) + 4),0xb0,1);
  uVar16 = **(uint **)(this + 0x54);
  uVar13 = (*(uint **)(this + 0x54))[1];
  if (0xb0 < uVar16) {
    uVar18 = 0xb0;
    do {
      *(undefined1 *)(uVar13 + uVar18) = 0;
      uVar18 = uVar18 + 1;
    } while (uVar18 < uVar16);
  }
  uVar4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar1 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined1 *)(uVar13 + 0x3c) = 0;
  *(undefined1 *)(uVar13 + 0x3d) = 0;
  *(undefined1 *)(uVar13 + 0x3e) = 0;
  *(undefined4 *)(this + 0xb8) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0xe0) = 0;
  *(undefined4 *)(this + 0xe4) = uVar4;
  *(undefined4 *)(this + 0xe8) = uVar1;
  *(undefined4 *)(this + 0xec) = uVar2;
  *(undefined4 *)(this + 0xd0) = 0;
  *(undefined4 *)(this + 0xd4) = uVar4;
  *(undefined4 *)(this + 0xd8) = uVar1;
  *(undefined4 *)(this + 0xdc) = uVar2;
  *(undefined4 *)(this + 0xc0) = 0;
  *(undefined4 *)(this + 0xc4) = uVar4;
  *(undefined4 *)(this + 200) = uVar1;
  *(undefined4 *)(this + 0xcc) = uVar2;
  Level::programmedStation = 0;
  Level::energyCellsForNextJump = 0;
  Level::doInstantJump = 0;
  *(undefined4 *)(this + 0x160) = 0;
  *(undefined4 *)(this + 0x164) = 0;
  *(undefined4 *)(this + 0x170) = 0;
  this[0x108] = (Status)0x0;
  this[0xf9] = (Status)0x0;
  this[0xf0] = (Status)0x0;
  this[0xf1] = (Status)0x0;
  *(undefined4 *)(this + 0xf4) = 0xffffffff;
  this[0xf8] = (Status)0x1;
  Achievements::init(Globals::achievements);
  pvVar5 = *(void **)(this + 0x40);
  if (pvVar5 != (void *)0x0) {
    if (*(void **)((int)pvVar5 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar5 + 4));
    }
    operator_delete(pvVar5);
    *(undefined4 *)(this + 0x40) = 0;
  }
  pvVar5 = *(void **)(this + 0x3c);
  if (pvVar5 != (void *)0x0) {
    if (*(void **)((int)pvVar5 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar5 + 4));
    }
    operator_delete(pvVar5);
    *(undefined4 *)(this + 0x3c) = 0;
  }
  pvVar5 = *(void **)(this + 0x48);
  if (pvVar5 != (void *)0x0) {
    if (*(void **)((int)pvVar5 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar5 + 4));
    }
    operator_delete(pvVar5);
    *(undefined4 *)(this + 0x48) = 0;
  }
  pvVar5 = *(void **)(this + 0x44);
  if (pvVar5 != (void *)0x0) {
    if (*(void **)((int)pvVar5 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar5 + 4));
    }
    operator_delete(pvVar5);
    *(undefined4 *)(this + 0x44) = 0;
  }
  pAVar7 = operator_new(0xc);
  puVar8 = operator_new__(4);
  *(undefined4 **)(pAVar7 + 4) = puVar8;
  *puVar8 = 0;
  *(undefined4 *)(pAVar7 + 8) = 1;
  *(undefined4 *)pAVar7 = 0;
  *(Array **)(this + 0x40) = pAVar7;
  ArraySetLength<int>(0xe9,pAVar7);
  pAVar7 = operator_new(0xc);
  puVar8 = operator_new__(4);
  *(undefined4 **)(pAVar7 + 4) = puVar8;
  *(undefined4 *)(pAVar7 + 8) = 1;
  *puVar8 = 0;
  *(undefined4 *)pAVar7 = 0;
  *(Array **)(this + 0x3c) = pAVar7;
  ArraySetLength<int>(0xe9,pAVar7);
  pAVar7 = operator_new(0xc);
  puVar8 = operator_new__(4);
  *(undefined4 **)(pAVar7 + 4) = puVar8;
  *puVar8 = 0;
  *(undefined4 *)(pAVar7 + 8) = 1;
  *(undefined4 *)pAVar7 = 0;
  *(Array **)(this + 0x48) = pAVar7;
  ArraySetLength<int>(0xe9,pAVar7);
  pAVar7 = operator_new(0xc);
  puVar8 = operator_new__(4);
  *(undefined4 **)(pAVar7 + 4) = puVar8;
  *(undefined4 *)(pAVar7 + 8) = 1;
  *puVar8 = 0;
  *(undefined4 *)pAVar7 = 0;
  *(Array **)(this + 0x44) = pAVar7;
  ArraySetLength<int>(0xe9,pAVar7);
  iVar20 = 0;
  iVar15 = *(int *)(*(int *)(this + 0x48) + 4);
  iVar17 = *(int *)(*(int *)(this + 0x3c) + 4);
  iVar9 = *(int *)(*(int *)(this + 0x44) + 4);
  iVar19 = *(int *)(*(int *)(this + 0x40) + 4);
  do {
    *(undefined4 *)(iVar19 + iVar20 * 4) = 0;
    *(undefined4 *)(iVar17 + iVar20 * 4) = 0;
    *(undefined4 *)(iVar15 + iVar20 * 4) = 0;
    *(undefined4 *)(iVar9 + iVar20 * 4) = 0;
    iVar20 = iVar20 + 1;
  } while (iVar20 != 0xe9);
  pvVar5 = *(void **)(this + 0x4c);
  if (pvVar5 != (void *)0x0) {
    if (*(void **)((int)pvVar5 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar5 + 4));
    }
    operator_delete(pvVar5);
    *(undefined4 *)(this + 0x4c) = 0;
  }
  pAVar7 = operator_new(0xc);
  puVar10 = operator_new__(1);
  *(undefined1 **)(pAVar7 + 4) = puVar10;
  *(undefined4 *)(pAVar7 + 8) = 1;
  *puVar10 = 0;
  *(undefined4 *)pAVar7 = 0;
  *(Array **)(this + 0x4c) = pAVar7;
  ArraySetLength<bool>(4,pAVar7);
  **(undefined4 **)(*(int *)(this + 0x4c) + 4) = 0;
  pvVar5 = *(void **)(this + 0x58);
  if (pvVar5 != (void *)0x0) {
    if (*(void **)((int)pvVar5 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar5 + 4));
    }
    operator_delete(pvVar5);
    *(undefined4 *)(this + 0x58) = 0;
  }
  pAVar7 = operator_new(0xc);
  puVar10 = operator_new__(1);
  *(undefined1 **)(pAVar7 + 4) = puVar10;
  *(undefined4 *)(pAVar7 + 8) = 1;
  *puVar10 = 0;
  *(undefined4 *)pAVar7 = 0;
  *(Array **)(this + 0x58) = pAVar7;
  ArraySetLength<bool>(5,pAVar7);
  puVar8 = *(undefined4 **)(*(int *)(this + 0x58) + 4);
  *(undefined1 *)(puVar8 + 1) = 0;
  *puVar8 = 0;
  puVar14 = (uint *)Galaxy::getSystems(Globals::galaxy);
  if (*puVar14 != 0) {
    iVar9 = *(int *)(this + 0x38);
    uVar13 = 0;
    do {
      uVar3 = SolarSystem::isVisible(*(SolarSystem **)(puVar14[1] + uVar13 * 4));
      *(undefined1 *)(*(int *)(iVar9 + 4) + uVar13) = uVar3;
      uVar13 = uVar13 + 1;
    } while (uVar13 < *puVar14);
  }
  puVar14 = Globals::items;
  if (*Globals::items == 0) {
    uVar13 = 0;
  }
  else {
    uVar16 = 0;
    uVar13 = 0;
    do {
      iVar9 = Item::getIngredients(*(Item **)(puVar14[1] + uVar16 * 4));
      if (iVar9 != 0) {
        uVar13 = uVar13 + 1;
      }
      uVar16 = uVar16 + 1;
    } while (uVar16 < *puVar14);
  }
  if (*(Array **)(this + 0x18) != (Array *)0x0) {
    ArrayReleaseClasses<BluePrint*>(*(Array **)(this + 0x18));
    pvVar5 = *(void **)(this + 0x18);
    if (pvVar5 != (void *)0x0) {
      if (*(void **)((int)pvVar5 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar5 + 4));
      }
      operator_delete(pvVar5);
    }
  }
  *(undefined4 *)(this + 0x18) = 0;
  if (0 < (int)uVar13) {
    pAVar7 = operator_new(0xc);
    puVar8 = operator_new__(4);
    *(undefined4 **)(pAVar7 + 4) = puVar8;
    *(undefined4 *)(pAVar7 + 8) = 1;
    *puVar8 = 0;
    *(undefined4 *)pAVar7 = 0;
    *(Array **)(this + 0x18) = pAVar7;
    ArraySetLength<BluePrint*>(uVar13,pAVar7);
    if (*puVar14 != 0) {
      uVar13 = 0;
      iVar9 = 0;
      do {
        iVar15 = Item::getIngredients(*(Item **)(puVar14[1] + uVar13 * 4));
        if (iVar15 != 0) {
          this_00 = operator_new(0x28);
          BluePrint::BluePrint(this_00,uVar13);
          *(BluePrint **)(*(int *)(*(int *)(this + 0x18) + 4) + iVar9 * 4) = this_00;
          iVar9 = iVar9 + 1;
        }
        uVar13 = uVar13 + 1;
      } while (uVar13 < *puVar14);
    }
  }
  if (*(Array **)(this + 0x1c) != (Array *)0x0) {
    ArrayReleaseClasses<PendingProduct*>(*(Array **)(this + 0x1c));
    pvVar5 = *(void **)(this + 0x1c);
    if (pvVar5 != (void *)0x0) {
      if (*(void **)((int)pvVar5 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar5 + 4));
      }
      operator_delete(pvVar5);
    }
  }
  *(undefined4 *)(this + 0x1c) = 0;
  loadAgents(this);
  loadWanted(this);
  if (*(Standing **)(this + 0x14) != (Standing *)0x0) {
    pvVar5 = (void *)Standing::~Standing(*(Standing **)(this + 0x14));
    operator_delete(pvVar5);
    *(undefined4 *)(this + 0x14) = 0;
  }
  this_01 = operator_new(8);
  Standing::Standing(this_01);
  *(Standing **)(this + 0x14) = this_01;
  *(undefined4 *)(this + 0x7c) = 0xffffffff;
  *(undefined4 *)(this + 0x80) = 0xffffffff;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(*(int *)(*(int *)(this + 0x194) + 4) + 4) = Mission::empty;
  *(undefined4 *)(this + 0x1e8) = 0;
  this_02 = operator_new(100);
  Mission::Mission(this_02,4,0,0x4e);
  setCampaignMission(this,this_02);
  *(undefined4 *)(this + 400) = **(undefined4 **)(*(int *)(this + 0x194) + 4);
  pSVar11 = (Ship *)Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0x28),-1);
  setShip(this,pSVar11);
  Ship::priceDecline(*(Ship **)(this + 0x18c));
  pSVar6 = (Station *)Galaxy::getStation(Globals::galaxy,0x4e);
  setStation(this,pSVar6);
  Ship::setCargo(*(Ship **)(this + 0x18c),(Array *)0x0);
  pIVar12 = (Item *)Item::makeItem(*(Item **)(Globals::items[1] + 8));
  Ship::setEquipment(*(Ship **)(this + 0x18c),pIVar12,0);
  pIVar12 = (Item *)Item::makeItem(*(Item **)(Globals::items[1] + 8));
  Ship::setEquipment(*(Ship **)(this + 0x18c),pIVar12,1);
  pIVar12 = (Item *)Item::makeItem(*(Item **)(Globals::items[1] + 0xd8));
  Ship::setEquipment(*(Ship **)(this + 0x18c),pIVar12,0);
  pIVar12 = (Item *)Item::makeItem(*(Item **)(Globals::items[1] + 0xec));
  Ship::setEquipment(*(Ship **)(this + 0x18c),pIVar12,1);
  pIVar12 = (Item *)Item::makeItem(*(Item **)(Globals::items[1] + 0x148));
  Ship::setEquipment(*(Ship **)(this + 0x18c),pIVar12,2);
  pIVar12 = (Item *)Item::makeItem(*(Item **)(Globals::items[1] + 0x124));
  Ship::setEquipment(*(Ship **)(this + 0x18c),pIVar12,3);
  pIVar12 = (Item *)Item::makeItem(*(Item **)(Globals::items[1] + 0x90),6);
  Ship::setEquipment(*(Ship **)(Globals::status + 0x18c),pIVar12,0);
  if (Globals::options[0x35] != '\0') {
    *(undefined1 *)(*(int *)(*(int *)(this + 0x38) + 4) + 0x19) = 1;
  }
  uVar4 = Ship::getMaxHP(*(Ship **)(this + 0x18c));
  *(undefined4 *)(this + 100) = uVar4;
  uVar4 = Ship::getMaxShieldHP(*(Ship **)(this + 0x18c));
  *(undefined4 *)(this + 0x5c) = uVar4;
  uVar4 = Ship::getMaxArmorHP(*(Ship **)(this + 0x18c));
  *(undefined4 *)(this + 0x60) = uVar4;
  *(undefined4 *)(this + 0x68) = 100;
  *(undefined4 *)(this + 0x150) = 0xffffffff;
  *(undefined4 *)(this + 0x154) = 0xffffffff;
  *(undefined4 *)(this + 0x158) = 0xffffffff;
  return;
}

