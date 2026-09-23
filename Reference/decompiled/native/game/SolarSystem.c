// Class: SolarSystem
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== SolarSystem::SolarSystem  @0x00180914  (150 bytes)
/* SolarSystem::SolarSystem(int, AbyssEngine::String, int, bool, int, int, int, int, int, int, int*,
   Array<int>*, Array<int>*, Array<int>*) */

void __thiscall
SolarSystem::SolarSystem
          (SolarSystem *this,undefined4 param_1,String *param_3,undefined4 param_4,
          SolarSystem param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
          undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 *param_12,
          undefined4 param_13,undefined4 param_14,undefined4 param_15)

{
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  AbyssEngine::String::String((String *)(this + 0xc));
  *(undefined4 *)(this + 0x14) = param_1;
  AbyssEngine::String::String(aSStack_30,param_3,false);
  AbyssEngine::String::operator=((String *)(this + 0xc),aSStack_30);
  AbyssEngine::String::~String(aSStack_30);
  *(undefined4 *)(this + 0x18) = param_4;
  this[0x40] = param_5;
  *(undefined4 *)(this + 0x1c) = param_6;
  *(undefined4 *)(this + 0x20) = param_7;
  *(undefined4 *)(this + 0x24) = param_8;
  *(undefined4 *)(this + 0x28) = param_9;
  *(undefined4 *)(this + 0x2c) = param_10;
  *(undefined4 *)(this + 0x30) = param_11;
  *(undefined4 *)this = *param_12;
  *(undefined4 *)(this + 4) = param_12[1];
  *(undefined4 *)(this + 8) = param_12[2];
  *(undefined4 *)(this + 0x34) = param_13;
  *(undefined4 *)(this + 0x38) = param_15;
  *(undefined4 *)(this + 0x3c) = param_14;
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== SolarSystem::~SolarSystem  @0x001809cc  (164 bytes)
/* SolarSystem::~SolarSystem() */

SolarSystem * __thiscall SolarSystem::~SolarSystem(SolarSystem *this)

{
  void *pvVar1;
  void *pvVar2;
  
  pvVar2 = *(void **)(this + 0x34);
  if (pvVar2 != (void *)0x0) {
    if (*(void **)((int)pvVar2 + 4) == (void *)0x0) {
      *(undefined4 *)((int)pvVar2 + 4) = 0;
    }
    else {
      operator_delete__(*(void **)((int)pvVar2 + 4));
      pvVar1 = *(void **)(this + 0x34);
      *(undefined4 *)((int)pvVar2 + 4) = 0;
      pvVar2 = pvVar1;
      if (pvVar1 == (void *)0x0) goto LAB_001809fe;
    }
    if (*(void **)((int)pvVar2 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar2 + 4));
    }
    operator_delete(pvVar2);
  }
LAB_001809fe:
  *(undefined4 *)(this + 0x34) = 0;
  pvVar2 = *(void **)(this + 0x38);
  if (pvVar2 != (void *)0x0) {
    if (*(void **)((int)pvVar2 + 4) == (void *)0x0) {
      *(undefined4 *)((int)pvVar2 + 4) = 0;
    }
    else {
      operator_delete__(*(void **)((int)pvVar2 + 4));
      pvVar1 = *(void **)(this + 0x38);
      *(undefined4 *)((int)pvVar2 + 4) = 0;
      pvVar2 = pvVar1;
      if (pvVar1 == (void *)0x0) goto LAB_00180a30;
    }
    if (*(void **)((int)pvVar2 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar2 + 4));
    }
    operator_delete(pvVar2);
  }
LAB_00180a30:
  *(undefined4 *)(this + 0x38) = 0;
  pvVar2 = *(void **)(this + 0x3c);
  if (pvVar2 != (void *)0x0) {
    if (*(void **)((int)pvVar2 + 4) == (void *)0x0) {
      *(undefined4 *)((int)pvVar2 + 4) = 0;
    }
    else {
      operator_delete__(*(void **)((int)pvVar2 + 4));
      pvVar1 = *(void **)(this + 0x3c);
      *(undefined4 *)((int)pvVar2 + 4) = 0;
      pvVar2 = pvVar1;
      if (pvVar1 == (void *)0x0) goto LAB_00180a5e;
    }
    if (*(void **)((int)pvVar2 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar2 + 4));
    }
    operator_delete(pvVar2);
  }
LAB_00180a5e:
  *(undefined4 *)(this + 0x3c) = 0;
  AbyssEngine::String::~String((String *)(this + 0xc));
  return this;
}

// ===== SolarSystem::getIndex  @0x00180a70  (4 bytes)
/* SolarSystem::getIndex() */

undefined4 __thiscall SolarSystem::getIndex(SolarSystem *this)

{
  return *(undefined4 *)(this + 0x14);
}

// ===== SolarSystem::getName  @0x00180a74  (14 bytes)
/* SolarSystem::getName() */

void SolarSystem::getName(void)

{
  String *in_r0;
  int in_r1;
  
  AbyssEngine::String::String(in_r0,(String *)(in_r1 + 0xc),false);
  return;
}

// ===== SolarSystem::getSecurityLevel  @0x00180a82  (4 bytes)
/* SolarSystem::getSecurityLevel() */

undefined4 __thiscall SolarSystem::getSecurityLevel(SolarSystem *this)

{
  return *(undefined4 *)(this + 0x18);
}

// ===== SolarSystem::getRace  @0x00180a86  (4 bytes)
/* SolarSystem::getRace() */

undefined4 __thiscall SolarSystem::getRace(SolarSystem *this)

{
  return *(undefined4 *)(this + 0x1c);
}

// ===== SolarSystem::getAttackRace  @0x00180a8c  (20 bytes)
/* SolarSystem::getAttackRace() */

undefined4 __thiscall SolarSystem::getAttackRace(SolarSystem *this)

{
  if (*(uint *)(this + 0x1c) < 4) {
    return *(undefined4 *)(&DAT_00252020 + *(uint *)(this + 0x1c) * 4);
  }
  return 8;
}

// ===== SolarSystem::hasPirateBase  @0x00180aa4  (74 bytes)
/* SolarSystem::hasPirateBase() */

undefined4 __thiscall SolarSystem::hasPirateBase(SolarSystem *this)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  uVar1 = **(uint **)(this + 0x34);
  do {
    if (uVar1 != 0) {
      uVar3 = 0;
      do {
        if (*(int *)((*(uint **)(this + 0x34))[1] + uVar3 * 4) == (&DAT_00251f90)[iVar2]) {
          if (*(char *)(*(int *)(*(int *)(Globals::status + 0x4c) + 4) + iVar2) == '\0') {
            return 1;
          }
          break;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar1);
    }
    iVar2 = iVar2 + 1;
    if (3 < iVar2) {
      return 0;
    }
  } while( true );
}

// ===== SolarSystem::stationIsInSystem  @0x00180af8  (38 bytes)
/* SolarSystem::stationIsInSystem(int) */

undefined4 __thiscall SolarSystem::stationIsInSystem(SolarSystem *this,int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = **(uint **)(this + 0x34);
  if (uVar2 != 0) {
    uVar1 = 0;
    do {
      if (*(int *)((*(uint **)(this + 0x34))[1] + uVar1 * 4) == param_1) {
        return 1;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < uVar2);
  }
  return 0;
}

// ===== SolarSystem::hasHiddenBlueprint  @0x00180b20  (74 bytes)
/* SolarSystem::hasHiddenBlueprint() */

undefined4 __thiscall SolarSystem::hasHiddenBlueprint(SolarSystem *this)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  uVar1 = **(uint **)(this + 0x34);
  do {
    if (uVar1 != 0) {
      uVar3 = 0;
      do {
        if (*(int *)((*(uint **)(this + 0x34))[1] + uVar3 * 4) == (&DAT_00259840)[iVar2]) {
          if (*(char *)(*(int *)(*(int *)(Globals::status + 0x58) + 4) + iVar2) == '\0') {
            return 1;
          }
          break;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar1);
    }
    iVar2 = iVar2 + 1;
    if (4 < iVar2) {
      return 0;
    }
  } while( true );
}

// ===== SolarSystem::getX  @0x00180b74  (4 bytes)
/* SolarSystem::getX() */

undefined4 __thiscall SolarSystem::getX(SolarSystem *this)

{
  return *(undefined4 *)(this + 0x20);
}

// ===== SolarSystem::getY  @0x00180b78  (4 bytes)
/* SolarSystem::getY() */

undefined4 __thiscall SolarSystem::getY(SolarSystem *this)

{
  return *(undefined4 *)(this + 0x24);
}

// ===== SolarSystem::getZ  @0x00180b7c  (4 bytes)
/* SolarSystem::getZ() */

undefined4 __thiscall SolarSystem::getZ(SolarSystem *this)

{
  return *(undefined4 *)(this + 0x28);
}

// ===== SolarSystem::getTextureIndex  @0x00180b80  (4 bytes)
/* SolarSystem::getTextureIndex() */

undefined4 __thiscall SolarSystem::getTextureIndex(SolarSystem *this)

{
  return *(undefined4 *)(this + 0x30);
}

// ===== SolarSystem::getWarpGateIndex  @0x00180b84  (4 bytes)
/* SolarSystem::getWarpGateIndex() */

undefined4 __thiscall SolarSystem::getWarpGateIndex(SolarSystem *this)

{
  return *(undefined4 *)(this + 0x2c);
}

// ===== SolarSystem::getWarpGateEnumIndex  @0x00180b88  (40 bytes)
/* SolarSystem::getWarpGateEnumIndex() */

uint __thiscall SolarSystem::getWarpGateEnumIndex(SolarSystem *this)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = **(uint **)(this + 0x34);
  if (uVar2 != 0) {
    uVar1 = 0;
    do {
      if (*(int *)((*(uint **)(this + 0x34))[1] + uVar1 * 4) == *(int *)(this + 0x2c)) {
        return uVar1;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < uVar2);
  }
  return 0xffffffff;
}

// ===== SolarSystem::getStationEnumIndex  @0x00180bb0  (38 bytes)
/* SolarSystem::getStationEnumIndex(int) */

uint __thiscall SolarSystem::getStationEnumIndex(SolarSystem *this,int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = **(uint **)(this + 0x34);
  if (uVar2 != 0) {
    uVar1 = 0;
    do {
      if (*(int *)((*(uint **)(this + 0x34))[1] + uVar1 * 4) == param_1) {
        return uVar1;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < uVar2);
  }
  return 0xffffffff;
}

// ===== SolarSystem::currentOrbitHasWarpGate  @0x00180bd8  (34 bytes)
/* SolarSystem::currentOrbitHasWarpGate() */

bool __thiscall SolarSystem::currentOrbitHasWarpGate(SolarSystem *this)

{
  Station *this_00;
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(this + 0x2c);
  this_00 = (Station *)Status::getStation(Globals::status);
  iVar1 = Station::getIndex(this_00);
  return iVar2 == iVar1;
}

// ===== SolarSystem::stationIsInSystem  @0x00180c00  (48 bytes)
/* SolarSystem::stationIsInSystem(Station*) */

undefined4 __thiscall SolarSystem::stationIsInSystem(SolarSystem *this,Station *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 != (Station *)0x0) {
    iVar1 = Station::getIndex(param_1);
    uVar2 = **(uint **)(this + 0x34);
    if (uVar2 != 0) {
      uVar3 = 0;
      do {
        if (*(int *)((*(uint **)(this + 0x34))[1] + uVar3 * 4) == iVar1) {
          return 1;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar2);
    }
  }
  return 0;
}

// ===== SolarSystem::isFullyDiscovered  @0x00180c30  (64 bytes)
/* SolarSystem::isFullyDiscovered() */

undefined4 __thiscall SolarSystem::isFullyDiscovered(SolarSystem *this)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  puVar1 = *(uint **)(this + 0x34);
  if (*puVar1 != 0) {
    uVar4 = 0;
    do {
      iVar3 = *(int *)(puVar1[1] + uVar4 * 4);
      iVar2 = Galaxy::getVisited(Globals::galaxy);
      if (*(char *)(iVar2 + iVar3) == '\0') {
        return 0;
      }
      puVar1 = *(uint **)(this + 0x34);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar1);
  }
  return 1;
}

// ===== SolarSystem::setCoords  @0x00180c74  (6 bytes)
/* SolarSystem::setCoords(int, int) */

void __thiscall SolarSystem::setCoords(SolarSystem *this,int param_1,int param_2)

{
  *(int *)(this + 0x20) = param_1;
  *(int *)(this + 0x24) = param_2;
  return;
}

// ===== SolarSystem::getStations  @0x00180c7a  (4 bytes)
/* SolarSystem::getStations() */

undefined4 __thiscall SolarSystem::getStations(SolarSystem *this)

{
  return *(undefined4 *)(this + 0x34);
}

// ===== SolarSystem::getForbiddenGoods  @0x00180c7e  (4 bytes)
/* SolarSystem::getForbiddenGoods() */

undefined4 __thiscall SolarSystem::getForbiddenGoods(SolarSystem *this)

{
  return *(undefined4 *)(this + 0x38);
}

// ===== SolarSystem::getRoutes  @0x00180c82  (4 bytes)
/* SolarSystem::getRoutes() */

undefined4 __thiscall SolarSystem::getRoutes(SolarSystem *this)

{
  return *(undefined4 *)(this + 0x3c);
}

// ===== SolarSystem::systemIsInSystemRoutes  @0x00180c86  (46 bytes)
/* SolarSystem::systemIsInSystemRoutes(int) */

undefined4 __thiscall SolarSystem::systemIsInSystemRoutes(SolarSystem *this,int param_1)

{
  uint *puVar1;
  uint uVar2;
  
  if (*(int *)(this + 0x14) == param_1) {
    return 1;
  }
  puVar1 = *(uint **)(this + 0x3c);
  if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
    uVar2 = 0;
    do {
      if (*(int *)(puVar1[1] + uVar2 * 4) == param_1) {
        return 1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *puVar1);
  }
  return 0;
}

// ===== SolarSystem::isVisible  @0x00180cb4  (6 bytes)
/* SolarSystem::isVisible() */

SolarSystem __thiscall SolarSystem::isVisible(SolarSystem *this)

{
  return this[0x40];
}

// ===== SolarSystem::setVisible  @0x00180cba  (6 bytes)
/* SolarSystem::setVisible(bool) */

void __thiscall SolarSystem::setVisible(SolarSystem *this,bool param_1)

{
  this[0x40] = (SolarSystem)param_1;
  return;
}

// ===== SolarSystem::hasNoOwner  @0x00180cc0  (30 bytes)
/* SolarSystem::hasNoOwner() */

uint __thiscall SolarSystem::hasNoOwner(SolarSystem *this)

{
  if (*(int *)(this + 0x14) - 0x17U < 0xb) {
    return 0x60bU >> (*(int *)(this + 0x14) - 0x17U & 0xff) & 1;
  }
  return 0;
}

