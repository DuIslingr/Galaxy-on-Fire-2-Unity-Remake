// Class: Station
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Station::Station  @0x000b378e  (56 bytes)
/* Station::Station(AbyssEngine::String, int, int, int, int) */

Station * __thiscall
Station::Station(Station *this,String *param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6)

{
  String *this_00;
  
  this_00 = (String *)AbyssEngine::String::String((String *)this);
  AbyssEngine::String::operator=(this_00,param_2);
  *(undefined4 *)(this + 8) = param_3;
  *(undefined4 *)(this + 0xc) = param_4;
  *(undefined4 *)(this + 0x1c) = param_5;
  *(undefined4 *)(this + 0x14) = param_6;
  this[0x18] = (Station)0x0;
  this[0x20] = (Station)0x0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  return this;
}

// ===== Station::Station  @0x000b37d4  (100 bytes)
/* Station::Station() */

void __thiscall Station::Station(Station *this)

{
  String aSStack_1c [8];
  int local_14;
  
  local_14 = __stack_chk_guard;
  AbyssEngine::String::String((String *)this);
  AbyssEngine::String::String(aSStack_1c,"",false);
  AbyssEngine::String::operator=((String *)this,aSStack_1c);
  AbyssEngine::String::~String(aSStack_1c);
  *(undefined4 *)(this + 8) = 0xffffffff;
  *(undefined4 *)(this + 0xc) = 0xffffffff;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  this[0x18] = (Station)0x0;
  this[0x20] = (Station)0x0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  if (__stack_chk_guard - local_14 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_14);
  }
  return;
}

// ===== Station::~Station  @0x000b385c  (264 bytes)
/* Station::~Station() */

void __thiscall Station::~Station(Station *this)

{
  int iVar1;
  Mission *pMVar2;
  Agent *pAVar3;
  Agent *pAVar4;
  uint uVar5;
  void *pvVar6;
  uint *puVar7;
  Agent *this_00;
  
  if (*(Array **)(this + 0x28) != (Array *)0x0) {
    ArrayReleaseClasses<Ship*>(*(Array **)(this + 0x28));
    pvVar6 = *(void **)(this + 0x28);
    if (pvVar6 != (void *)0x0) {
      if (*(void **)((int)pvVar6 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar6 + 4));
      }
      operator_delete(pvVar6);
    }
    *(undefined4 *)(this + 0x28) = 0;
  }
  if (*(Array **)(this + 0x24) != (Array *)0x0) {
    ArrayReleaseClasses<Item*>(*(Array **)(this + 0x24));
    pvVar6 = *(void **)(this + 0x24);
    if (pvVar6 != (void *)0x0) {
      if (*(void **)((int)pvVar6 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar6 + 4));
      }
      operator_delete(pvVar6);
    }
    *(undefined4 *)(this + 0x24) = 0;
  }
  puVar7 = *(uint **)(this + 0x2c);
  if (puVar7 == (uint *)0x0) goto LAB_000b3958;
  if (*puVar7 == 0) {
LAB_000b3944:
    if ((void *)puVar7[1] != (void *)0x0) {
      operator_delete__((void *)puVar7[1]);
    }
    operator_delete(puVar7);
  }
  else {
    uVar5 = 0;
    do {
      this_00 = *(Agent **)(puVar7[1] + uVar5 * 4);
      iVar1 = Status::getCampaignMission(Globals::status);
      if (iVar1 == 0) {
        pAVar3 = (Agent *)0x0;
      }
      else {
        pMVar2 = (Mission *)Status::getCampaignMission(Globals::status);
        pAVar3 = (Agent *)Mission::getAgent(pMVar2);
      }
      iVar1 = Status::getFreelanceMission(Globals::status);
      if (iVar1 == 0) {
        pAVar4 = (Agent *)0x0;
      }
      else {
        pMVar2 = (Mission *)Status::getFreelanceMission(Globals::status);
        pAVar4 = (Agent *)Mission::getAgent(pMVar2);
      }
      if (((this_00 != (Agent *)0x0) && (this_00 != pAVar3 && this_00 != pAVar4)) &&
         (iVar1 = Agent::isStoryAgent(this_00), iVar1 == 0)) {
        pvVar6 = (void *)Agent::~Agent(this_00);
        operator_delete(pvVar6);
      }
      puVar7 = *(uint **)(this + 0x2c);
      uVar5 = uVar5 + 1;
    } while (uVar5 < *puVar7);
    if (puVar7 != (uint *)0x0) goto LAB_000b3944;
  }
  *(undefined4 *)(this + 0x2c) = 0;
LAB_000b3958:
  AbyssEngine::String::~String((String *)this);
  return;
}

// ===== Station::getSystem  @0x000b3a0c  (4 bytes)
/* Station::getSystem() */

undefined4 __thiscall Station::getSystem(Station *this)

{
  return *(undefined4 *)(this + 0xc);
}

// ===== Station::getName  @0x000b3a10  (12 bytes)
/* Station::getName() */

void Station::getName(void)

{
  String *in_r0;
  String *in_r1;
  
  AbyssEngine::String::String(in_r0,in_r1,false);
  return;
}

// ===== Station::getIndex  @0x000b3a1c  (4 bytes)
/* Station::getIndex() */

undefined4 __thiscall Station::getIndex(Station *this)

{
  return *(undefined4 *)(this + 8);
}

// ===== Station::setAttackedFriends  @0x000b3a20  (6 bytes)
/* Station::setAttackedFriends(bool) */

void __thiscall Station::setAttackedFriends(Station *this,bool param_1)

{
  this[0x20] = (Station)param_1;
  return;
}

// ===== Station::hasAttackedFriends  @0x000b3a26  (6 bytes)
/* Station::hasAttackedFriends() */

Station __thiscall Station::hasAttackedFriends(Station *this)

{
  return this[0x20];
}

// ===== Station::isAttackedByAliens  @0x000b3a2c  (24 bytes)
/* Station::isAttackedByAliens() */

bool __thiscall Station::isAttackedByAliens(Station *this)

{
  return *(int *)(this + 8) == *(int *)(Globals::status + 0x80);
}

// ===== Station::isPlanet  @0x000b3a48  (4 bytes)
/* Station::isPlanet() */

Station __thiscall Station::isPlanet(Station *this)

{
  return this[0x10];
}

// ===== Station::getTextureIndex  @0x000b3a4c  (4 bytes)
/* Station::getTextureIndex() */

undefined4 __thiscall Station::getTextureIndex(Station *this)

{
  return *(undefined4 *)(this + 0x14);
}

// ===== Station::isDiscovered  @0x000b3a50  (22 bytes)
/* Station::isDiscovered() */

undefined1 __thiscall Station::isDiscovered(Station *this)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(this + 8);
  iVar1 = Galaxy::getVisited(Globals::galaxy);
  return *(undefined1 *)(iVar1 + iVar2);
}

// ===== Station::visit  @0x000b3a6c  (62 bytes)
/* Station::visit() */

void __thiscall Station::visit(Station *this)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(this + 8);
  iVar1 = Galaxy::getVisited(Globals::galaxy);
  if (*(char *)(iVar1 + iVar2) == '\0') {
    this[0x18] = (Station)0x1;
    Status::visitStation(Globals::status);
    Galaxy::visitStation(Globals::galaxy,*(int *)(this + 8));
    return;
  }
  return;
}

// ===== Station::getTecLevel  @0x000b3ab4  (4 bytes)
/* Station::getTecLevel() */

undefined4 __thiscall Station::getTecLevel(Station *this)

{
  return *(undefined4 *)(this + 0x1c);
}

// ===== Station::getShips  @0x000b3ab8  (4 bytes)
/* Station::getShips() */

undefined4 __thiscall Station::getShips(Station *this)

{
  return *(undefined4 *)(this + 0x28);
}

// ===== Station::getItems  @0x000b3abc  (4 bytes)
/* Station::getItems() */

undefined4 __thiscall Station::getItems(Station *this)

{
  return *(undefined4 *)(this + 0x24);
}

// ===== Station::getAgents  @0x000b3ac0  (4 bytes)
/* Station::getAgents() */

undefined4 __thiscall Station::getAgents(Station *this)

{
  return *(undefined4 *)(this + 0x2c);
}

// ===== Station::removeShips  @0x000b3ac4  (38 bytes)
/* Station::removeShips() */

void __thiscall Station::removeShips(Station *this)

{
  void *pvVar1;
  
  if (*(Array **)(this + 0x28) != (Array *)0x0) {
    ArrayReleaseClasses<Ship*>(*(Array **)(this + 0x28));
    pvVar1 = *(void **)(this + 0x28);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x28) = 0;
  return;
}

// ===== Station::removeShip  @0x000b3aea  (16 bytes)
/* Station::removeShip(Ship*) */

void __thiscall Station::removeShip(Station *this,Ship *param_1)

{
  if (*(Array **)(this + 0x28) == (Array *)0x0) {
    return;
  }
  ArrayRemove<Ship*>(param_1,*(Array **)(this + 0x28));
  return;
}

// ===== Station::setShips  @0x000b3b3a  (134 bytes)
/* Station::setShips(Array<Ship*>*, bool) */

void __thiscall Station::setShips(Station *this,Array *param_1,bool param_2)

{
  Array *pAVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  void *pvVar4;
  uint uVar5;
  
  if (*(Array **)(this + 0x28) != (Array *)0x0) {
    ArrayReleaseClasses<Ship*>(*(Array **)(this + 0x28));
    pvVar4 = *(void **)(this + 0x28);
    if (pvVar4 != (void *)0x0) {
      if (*(void **)((int)pvVar4 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar4 + 4));
      }
      operator_delete(pvVar4);
    }
  }
  *(undefined4 *)(this + 0x28) = 0;
  if ((param_1 == (Array *)0x0) || (!param_2)) {
    *(Array **)(this + 0x28) = param_1;
  }
  else {
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x28) = pAVar1;
    ArraySetLength<Ship*>(*(uint *)param_1,pAVar1);
    if (*(int *)param_1 == 0) {
      return;
    }
    uVar5 = 0;
    do {
      uVar3 = Ship::clone(*(Ship **)(*(int *)(param_1 + 4) + uVar5 * 4));
      *(undefined4 *)(*(int *)(*(int *)(this + 0x28) + 4) + uVar5 * 4) = uVar3;
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)param_1);
  }
  return;
}

// ===== Station::setItems  @0x000b3bce  (126 bytes)
/* Station::setItems(Array<Item*>*, bool) */

void __thiscall Station::setItems(Station *this,Array *param_1,bool param_2)

{
  Array *pAVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  void *pvVar4;
  uint uVar5;
  
  pvVar4 = *(void **)(this + 0x24);
  if (pvVar4 != (void *)0x0) {
    if (*(void **)((int)pvVar4 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar4 + 4));
    }
    operator_delete(pvVar4);
  }
  *(undefined4 *)(this + 0x24) = 0;
  if ((param_1 == (Array *)0x0) || (!param_2)) {
    *(Array **)(this + 0x24) = param_1;
  }
  else {
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x24) = pAVar1;
    ArraySetLength<Item*>(*(uint *)param_1,pAVar1);
    if (*(int *)param_1 == 0) {
      return;
    }
    uVar5 = 0;
    do {
      uVar3 = Item::clone(*(Item **)(*(int *)(param_1 + 4) + uVar5 * 4));
      *(undefined4 *)(*(int *)(*(int *)(this + 0x24) + 4) + uVar5 * 4) = uVar3;
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)param_1);
  }
  return;
}

// ===== Station::setAgents  @0x000b3c5a  (46 bytes)
/* Station::setAgents(Array<Agent*>*) */

void __thiscall Station::setAgents(Station *this,Array *param_1)

{
  Array *pAVar1;
  void *pvVar2;
  
  pAVar1 = *(Array **)(this + 0x2c);
  if (pAVar1 != param_1) {
    if (pAVar1 != (Array *)0x0) {
      ArrayReleaseClasses<Agent*>(pAVar1);
      pvVar2 = *(void **)(this + 0x2c);
      if (pvVar2 != (void *)0x0) {
        if (*(void **)((int)pvVar2 + 4) != (void *)0x0) {
          operator_delete__(*(void **)((int)pvVar2 + 4));
        }
        operator_delete(pvVar2);
      }
    }
    *(Array **)(this + 0x2c) = param_1;
  }
  return;
}

// ===== Station::hasItem  @0x000b3cca  (56 bytes)
/* Station::hasItem(int) */

undefined4 __thiscall Station::hasItem(Station *this,int param_1)

{
  Item *this_00;
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = *(uint **)(this + 0x24);
  if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
    uVar3 = 0;
    do {
      this_00 = *(Item **)(puVar2[1] + uVar3 * 4);
      if (this_00 != (Item *)0x0) {
        iVar1 = Item::getIndex(this_00);
        if (iVar1 == param_1) {
          return 1;
        }
        puVar2 = *(uint **)(this + 0x24);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar2);
  }
  return 0;
}

// ===== Station::hasShip  @0x000b3d02  (56 bytes)
/* Station::hasShip(int) */

undefined4 __thiscall Station::hasShip(Station *this,int param_1)

{
  Ship *this_00;
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = *(uint **)(this + 0x28);
  if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
    uVar3 = 0;
    do {
      this_00 = *(Ship **)(puVar2[1] + uVar3 * 4);
      if (this_00 != (Ship *)0x0) {
        iVar1 = Ship::getIndex(this_00);
        if (iVar1 == param_1) {
          return 1;
        }
        puVar2 = *(uint **)(this + 0x28);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar2);
  }
  return 0;
}

// ===== Station::addItem  @0x000b3d3a  (146 bytes)
/* Station::addItem(Item*) */

void __thiscall Station::addItem(Station *this,Item *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  void *pvVar3;
  size_t __size;
  uint uVar4;
  uint *puVar5;
  Item *this_00;
  
  puVar5 = *(uint **)(this + 0x24);
  if (puVar5 == (uint *)0x0) {
    puVar5 = operator_new(0xc);
    puVar2 = operator_new__(4);
    puVar5[1] = (uint)puVar2;
    puVar5[2] = 1;
    *puVar2 = 0;
    *puVar5 = 0;
    *(uint **)(this + 0x24) = puVar5;
  }
  else if (*puVar5 != 0) {
    uVar4 = 0;
    do {
      iVar1 = Item::equals(*(Item **)(puVar5[1] + uVar4 * 4),param_1);
      if (iVar1 != 0) {
        puVar5 = *(uint **)(this + 0x24);
        if (-1 < (int)uVar4) {
          this_00 = *(Item **)(puVar5[1] + uVar4 * 4);
          iVar1 = Item::getAmount(param_1);
          Item::changeAmount(this_00,iVar1);
          return;
        }
        break;
      }
      puVar5 = *(uint **)(this + 0x24);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar5);
    puVar5[2] = *puVar5 + 1;
    pvVar3 = (void *)puVar5[1];
    __size = (*puVar5 + 1) * 4;
    goto LAB_000b3db6;
  }
  __size = 4;
  puVar5[2] = 1;
  pvVar3 = (void *)puVar5[1];
LAB_000b3db6:
  pvVar3 = realloc(pvVar3,__size);
  puVar5[1] = (uint)pvVar3;
  *(Item **)((int)pvVar3 + *puVar5 * 4) = param_1;
  *puVar5 = puVar5[2];
  return;
}

// ===== Station::addShip  @0x000b3dd8  (126 bytes)
/* Station::addShip(Ship*) */

void __thiscall Station::addShip(Station *this,Ship *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  void *pvVar4;
  size_t __size;
  uint uVar5;
  uint *puVar6;
  
  puVar6 = *(uint **)(this + 0x28);
  if (puVar6 == (uint *)0x0) {
    puVar6 = operator_new(0xc);
    puVar3 = operator_new__(4);
    puVar6[1] = (uint)puVar3;
    puVar6[2] = 1;
    *puVar3 = 0;
    *puVar6 = 0;
    *(uint **)(this + 0x28) = puVar6;
  }
  else if (*puVar6 != 0) {
    uVar5 = 0;
    do {
      iVar1 = Ship::equals(*(Ship **)(puVar6[1] + uVar5 * 4),param_1);
      if (iVar1 != 0) {
        if (-1 < (int)uVar5) {
          return;
        }
        puVar6 = *(uint **)(this + 0x28);
        uVar2 = *puVar6;
        break;
      }
      puVar6 = *(uint **)(this + 0x28);
      uVar5 = uVar5 + 1;
      uVar2 = *puVar6;
    } while (uVar5 < uVar2);
    puVar6[2] = uVar2 + 1;
    pvVar4 = (void *)puVar6[1];
    __size = (uVar2 + 1) * 4;
    goto LAB_000b3e42;
  }
  __size = 4;
  puVar6[2] = 1;
  pvVar4 = (void *)puVar6[1];
LAB_000b3e42:
  pvVar4 = realloc(pvVar4,__size);
  puVar6[1] = (uint)pvVar4;
  *(Ship **)((int)pvVar4 + *puVar6 * 4) = param_1;
  *puVar6 = puVar6[2];
  return;
}

// ===== Station::stationHasPirateBase  @0x000b3e64  (54 bytes)
/* Station::stationHasPirateBase() */

undefined4 __thiscall Station::stationHasPirateBase(Station *this)

{
  int iVar1;
  
  iVar1 = 0;
  while (((&DAT_00251f90)[iVar1] != *(int *)(this + 8) ||
         (*(char *)(*(int *)(*(int *)(Globals::status + 0x4c) + 4) + iVar1) != '\0'))) {
    iVar1 = iVar1 + 1;
    if (3 < iVar1) {
      return 0;
    }
  }
  return 1;
}

// ===== Station::getPirateStationIndex  @0x000b3ea4  (30 bytes)
/* Station::getPirateStationIndex() */

int __thiscall Station::getPirateStationIndex(Station *this)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_00251f90)[iVar1] == *(int *)(this + 8)) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 4);
  return -1;
}

// ===== Station::stationHasHiddenBlueprint  @0x000b3ec8  (56 bytes)
/* Station::stationHasHiddenBlueprint(bool) */

undefined4 __thiscall Station::stationHasHiddenBlueprint(Station *this,bool param_1)

{
  int iVar1;
  
  iVar1 = 0;
  while (((&DAT_0025273c)[iVar1] != *(int *)(this + 8) ||
         ((!param_1 && (*(char *)(*(int *)(*(int *)(Globals::status + 0x58) + 4) + iVar1) != '\0')))
         )) {
    iVar1 = iVar1 + 1;
    if (4 < iVar1) {
      return 0;
    }
  }
  return 1;
}

// ===== Station::getHiddenBlueprintIndex  @0x000b3f08  (30 bytes)
/* Station::getHiddenBlueprintIndex() */

int __thiscall Station::getHiddenBlueprintIndex(Station *this)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_0025273c)[iVar1] == *(int *)(this + 8)) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 5);
  return -1;
}

// ===== Station::clone  @0x000b3f2c  (86 bytes)
/* Station::clone() */

void __thiscall Station::clone(Station *this)

{
  Station *pSVar1;
  String aSStack_1c [8];
  int local_14;
  
  local_14 = __stack_chk_guard;
  pSVar1 = operator_new(0x30);
  AbyssEngine::String::String(aSStack_1c,this,false);
  Station(pSVar1,aSStack_1c,*(undefined4 *)(this + 8),*(undefined4 *)(this + 0xc),
          *(undefined4 *)(this + 0x1c),*(undefined4 *)(this + 0x14));
  AbyssEngine::String::~String(aSStack_1c);
  if (__stack_chk_guard - local_14 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_14);
  }
  return;
}

// ===== Station::equals  @0x000b3fa4  (18 bytes)
/* Station::equals(Station*) */

undefined4 __thiscall Station::equals(Station *this,Station *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (Station *)0x0) && (*(int *)(this + 8) == *(int *)(param_1 + 8))) {
    uVar1 = 1;
  }
  return uVar1;
}

