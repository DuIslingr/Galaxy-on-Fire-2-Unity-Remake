// Class: Galaxy
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Galaxy::Galaxy  @0x001a4cda  (54 bytes)
/* Galaxy::Galaxy() */

Galaxy * __thiscall Galaxy::Galaxy(Galaxy *this)

{
  void *pvVar1;
  FileRead *this_00;
  undefined4 uVar2;
  
  pvVar1 = operator_new__(0x87);
  *(void **)this = pvVar1;
  __aeabi_memclr(pvVar1,0x87);
  this_00 = operator_new(1);
  FileRead::FileRead(this_00);
  uVar2 = FileRead::loadSystemsBinary();
  *(undefined4 *)(this + 4) = uVar2;
  pvVar1 = (void *)FileRead::~FileRead(this_00);
  operator_delete(pvVar1);
  return this;
}

// ===== Galaxy::~Galaxy  @0x001a4d1e  (52 bytes)
/* Galaxy::~Galaxy() */

Galaxy * __thiscall Galaxy::~Galaxy(Galaxy *this)

{
  void *pvVar1;
  
  if (*(void **)this != (void *)0x0) {
    operator_delete__(*(void **)this);
  }
  *(undefined4 *)this = 0;
  ArrayReleaseClasses<SolarSystem*>(*(Array **)(this + 4));
  pvVar1 = *(void **)(this + 4);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 4) = 0;
  return this;
}

// ===== Galaxy::reset  @0x001a4d52  (14 bytes)
/* Galaxy::reset() */

void __thiscall Galaxy::reset(Galaxy *this)

{
  __aeabi_memclr(*(undefined4 *)this,0x87);
  return;
}

// ===== Galaxy::getSystems  @0x001a4d60  (4 bytes)
/* Galaxy::getSystems() */

undefined4 __thiscall Galaxy::getSystems(Galaxy *this)

{
  return *(undefined4 *)(this + 4);
}

// ===== Galaxy::getSystem  @0x001a4d64  (16 bytes)
/* Galaxy::getSystem(int) */

undefined4 __thiscall Galaxy::getSystem(Galaxy *this,int param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(*(int *)(this + 4) + 4) + param_1 * 4);
  }
  return uVar1;
}

// ===== Galaxy::getStation  @0x001a4d74  (58 bytes)
/* Galaxy::getStation(int) */

undefined4 __thiscall Galaxy::getStation(Galaxy *this,int param_1)

{
  FileRead *this_00;
  undefined4 uVar1;
  void *pvVar2;
  
  if (-1 < param_1) {
    this_00 = operator_new(1);
    FileRead::FileRead(this_00);
    uVar1 = FileRead::loadStation(this_00,param_1);
    pvVar2 = (void *)FileRead::~FileRead(this_00);
    operator_delete(pvVar2);
    return uVar1;
  }
  return *(undefined4 *)(Globals::status + 0x78);
}

// ===== Galaxy::setVisited  @0x001a4dc0  (52 bytes)
/* Galaxy::setVisited(bool*, int) */

void __thiscall Galaxy::setVisited(Galaxy *this,bool *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (0 < param_2) {
    iVar1 = *(int *)this;
    iVar2 = 0;
    do {
      *(bool *)(iVar1 + iVar2) = param_1[iVar2];
      iVar2 = iVar2 + 1;
    } while (param_2 != iVar2);
    if (0x86 < param_2) {
      return;
    }
  }
  __aeabi_memclr(*(int *)this + param_2,0x87 - param_2);
  return;
}

// ===== Galaxy::getVisited  @0x001a4df4  (4 bytes)
/* Galaxy::getVisited() */

undefined4 __thiscall Galaxy::getVisited(Galaxy *this)

{
  return *(undefined4 *)this;
}

// ===== Galaxy::visitStation  @0x001a4df8  (8 bytes)
/* Galaxy::visitStation(int) */

void __thiscall Galaxy::visitStation(Galaxy *this,int param_1)

{
  *(undefined1 *)(*(int *)this + param_1) = 1;
  return;
}

// ===== Galaxy::invDistancePercent  @0x001a4e00  (58 bytes)
/* Galaxy::invDistancePercent(int, int, int, int) */

int __thiscall
Galaxy::invDistancePercent(Galaxy *this,int param_1,int param_2,int param_3,int param_4)

{
  uint in_fpscr;
  float fVar1;
  
  fVar1 = (float)VectorSignedToFloat((param_4 - param_2) * (param_4 - param_2) +
                                     (param_3 - param_1) * (param_3 - param_1),
                                     (byte)(in_fpscr >> 0x16) & 3);
  fVar1 = (float)Globals::sqrt(fVar1);
  return 100 - (int)fVar1;
}

// ===== Galaxy::distancePercent  @0x001a4e40  (54 bytes)
/* Galaxy::distancePercent(int, int, int, int) */

int __thiscall Galaxy::distancePercent(Galaxy *this,int param_1,int param_2,int param_3,int param_4)

{
  uint in_fpscr;
  float fVar1;
  
  fVar1 = (float)VectorSignedToFloat((param_4 - param_2) * (param_4 - param_2) +
                                     (param_3 - param_1) * (param_3 - param_1),
                                     (byte)(in_fpscr >> 0x16) & 3);
  fVar1 = (float)Globals::sqrt(fVar1);
  return (int)fVar1;
}

// ===== Galaxy::distance  @0x001a4e7c  (286 bytes)
/* Galaxy::distance(SolarSystem*, SolarSystem*) */

void __thiscall Galaxy::distance(Galaxy *this,SolarSystem *param_1,SolarSystem *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint in_fpscr;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  float local_2c;
  float local_28;
  float local_24;
  int local_20;
  
  local_20 = __stack_chk_guard;
  iVar1 = SolarSystem::getIndex(param_1);
  iVar2 = SolarSystem::getIndex(param_2);
  if (iVar1 != iVar2) {
    uVar3 = SolarSystem::getX(param_1);
    uVar4 = SolarSystem::getY(param_1);
    iVar1 = SolarSystem::getZ(param_1);
    local_2c = (float)VectorSignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
    local_28 = (float)VectorSignedToFloat(uVar4,(byte)(in_fpscr >> 0x16) & 3);
    local_24 = (float)VectorSignedToFloat(iVar1 / 10,(byte)(in_fpscr >> 0x16) & 3);
    uVar3 = SolarSystem::getX(param_2);
    uVar4 = SolarSystem::getY(param_2);
    iVar1 = SolarSystem::getZ(param_2);
    local_38 = VectorSignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
    local_34 = VectorSignedToFloat(uVar4,(byte)(in_fpscr >> 0x16) & 3);
    local_30 = VectorSignedToFloat(iVar1 / 10,(byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::AEMath::Vector::operator-=((Vector *)&local_2c,(Vector *)&local_38);
    Globals::sqrt(local_2c * local_2c + local_28 * local_28 + local_24 * local_24);
  }
  if (__stack_chk_guard - local_20 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_20);
}

// ===== Galaxy::getAsteroidProbabilities  @0x001a4fb0  (458 bytes)
/* Galaxy::getAsteroidProbabilities(Station*) */

void * __thiscall Galaxy::getAsteroidProbabilities(Galaxy *this,Station *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  void *pvVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  void *pvVar11;
  uint uVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint in_fpscr;
  float fVar17;
  
  iVar2 = Status::inAlienOrbit(Globals::status);
  iVar3 = Status::inSupernovaOrbit(Globals::status);
  iVar14 = Globals::items;
  if (iVar2 == 0) {
    iVar4 = *(int *)(this + 4);
  }
  else {
    iVar4 = 0;
  }
  piVar5 = operator_new__(0x2c);
  pvVar6 = operator_new__(0x2c);
  iVar16 = 0x9a;
  iVar15 = 0;
  do {
    *(int *)((int)pvVar6 + iVar15 * 4) = iVar16;
    if (iVar2 == 0) {
      iVar8 = Station::getSystem(param_1);
      iVar8 = SolarSystem::getX(*(SolarSystem **)(*(int *)(iVar4 + 4) + iVar8 * 4));
      iVar7 = Station::getSystem(param_1);
      iVar7 = SolarSystem::getY(*(SolarSystem **)(*(int *)(iVar4 + 4) + iVar7 * 4));
      iVar9 = Item::getMinPriceSystem(*(Item **)(*(int *)(iVar14 + 4) + iVar16 * 4));
      iVar9 = SolarSystem::getX(*(SolarSystem **)(*(int *)(iVar4 + 4) + iVar9 * 4));
      iVar10 = Item::getMinPriceSystem(*(Item **)(*(int *)(iVar14 + 4) + iVar16 * 4));
      iVar10 = SolarSystem::getY(*(SolarSystem **)(*(int *)(iVar4 + 4) + iVar10 * 4));
      fVar17 = (float)VectorSignedToFloat((iVar10 - iVar7) * (iVar10 - iVar7) +
                                          (iVar9 - iVar8) * (iVar9 - iVar8),
                                          (byte)(in_fpscr >> 0x16) & 3);
      fVar17 = (float)Globals::sqrt(fVar17);
      iVar8 = iVar15 + 1;
      iVar7 = 100 - (int)fVar17;
      if (iVar7 < 0x32) {
        iVar7 = 0;
      }
    }
    else {
      iVar7 = 0;
      iVar8 = iVar15;
    }
    iVar16 = iVar16 + 1;
    piVar5[iVar15] = iVar7;
    iVar15 = iVar8;
  } while (iVar16 != 0xa4);
  *(undefined4 *)((int)pvVar6 + 0x28) = 0xa4;
  iVar14 = 0;
  if (iVar2 != 0) {
    iVar14 = 100;
  }
  piVar5[10] = iVar14;
  do {
    bVar1 = true;
    iVar2 = 0;
    iVar14 = *piVar5;
    do {
      iVar4 = piVar5[iVar2 + 1];
      if (iVar14 < iVar4) {
        piVar5[iVar2] = iVar4;
        uVar13 = *(undefined4 *)((int)pvVar6 + iVar2 * 4);
        *(undefined4 *)((int)pvVar6 + iVar2 * 4) = *(undefined4 *)((int)pvVar6 + iVar2 * 4 + 4);
        *(undefined4 *)((int)pvVar6 + iVar2 * 4 + 4) = uVar13;
        bVar1 = false;
        piVar5[iVar2 + 1] = iVar14;
        iVar4 = iVar14;
      }
      iVar2 = iVar2 + 1;
      iVar14 = iVar4;
    } while (iVar2 != 10);
  } while (!bVar1);
  iVar14 = 0;
  iVar2 = 0;
  do {
    if (0 < piVar5[iVar2]) {
      piVar5[iVar2] = piVar5[iVar2] + iVar14;
    }
    iVar2 = iVar2 + 1;
    iVar14 = iVar14 + -2;
  } while (iVar2 != 0xb);
  pvVar11 = operator_new__(0x58);
  iVar14 = 0;
  do {
    uVar12 = (iVar14 - (iVar14 >> 0x1f)) * 2 & 0xfffffffc;
    *(undefined4 *)((int)pvVar11 + iVar14 * 4) = *(undefined4 *)((int)pvVar6 + uVar12);
    *(undefined4 *)((int)pvVar11 + iVar14 * 4 + 4) = *(undefined4 *)((int)piVar5 + uVar12);
    if ((iVar3 == 1) && (iVar2 = Status::getCurrentCampaignMission(Globals::status), 0x59 < iVar2))
    {
      *(undefined4 *)((int)pvVar11 + iVar14 * 4) = 0xd9;
    }
    iVar14 = iVar14 + 2;
  } while (iVar14 < 0x16);
  operator_delete__(piVar5);
  operator_delete__(pvVar6);
  return pvVar11;
}

// ===== Galaxy::getPlasmaProbabilities  @0x001a518c  (406 bytes)
/* Galaxy::getPlasmaProbabilities(Station*) */

void * __thiscall Galaxy::getPlasmaProbabilities(Galaxy *this,Station *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  void *pvVar11;
  undefined4 uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint in_fpscr;
  float fVar16;
  
  iVar2 = Status::inAlienOrbit(Globals::status);
  iVar10 = Globals::items;
  if (iVar2 == 0) {
    iVar3 = *(int *)(this + 4);
  }
  else {
    iVar3 = 0;
  }
  piVar4 = operator_new__(0x10);
  pvVar5 = operator_new__(0x10);
  iVar15 = 0xc9;
  iVar14 = 0;
  do {
    *(int *)((int)pvVar5 + iVar14 * 4) = iVar15;
    if (iVar2 == 0) {
      iVar7 = Station::getSystem(param_1);
      iVar7 = SolarSystem::getX(*(SolarSystem **)(*(int *)(iVar3 + 4) + iVar7 * 4));
      iVar6 = Station::getSystem(param_1);
      iVar6 = SolarSystem::getY(*(SolarSystem **)(*(int *)(iVar3 + 4) + iVar6 * 4));
      iVar8 = Item::getMinPriceSystem(*(Item **)(*(int *)(iVar10 + 4) + iVar15 * 4));
      iVar8 = SolarSystem::getX(*(SolarSystem **)(*(int *)(iVar3 + 4) + iVar8 * 4));
      iVar9 = Item::getMinPriceSystem(*(Item **)(*(int *)(iVar10 + 4) + iVar15 * 4));
      iVar9 = SolarSystem::getY(*(SolarSystem **)(*(int *)(iVar3 + 4) + iVar9 * 4));
      fVar16 = (float)VectorSignedToFloat((iVar9 - iVar6) * (iVar9 - iVar6) +
                                          (iVar8 - iVar7) * (iVar8 - iVar7),
                                          (byte)(in_fpscr >> 0x16) & 3);
      fVar16 = (float)Globals::sqrt(fVar16);
      iVar7 = iVar14 + 1;
      iVar6 = 100 - (int)fVar16;
      if (iVar6 < 0x32) {
        iVar6 = 0;
      }
    }
    else {
      iVar6 = 0;
      iVar7 = iVar14;
    }
    iVar15 = iVar15 + 1;
    piVar4[iVar14] = iVar6;
    iVar14 = iVar7;
  } while (iVar15 != 0xcd);
  do {
    bVar1 = true;
    iVar2 = 0;
    iVar10 = *piVar4;
    do {
      iVar3 = piVar4[iVar2 + 1];
      if (iVar10 < iVar3) {
        piVar4[iVar2] = iVar3;
        uVar12 = *(undefined4 *)((int)pvVar5 + iVar2 * 4);
        *(undefined4 *)((int)pvVar5 + iVar2 * 4) = *(undefined4 *)((int)pvVar5 + iVar2 * 4 + 4);
        *(undefined4 *)((int)pvVar5 + iVar2 * 4 + 4) = uVar12;
        bVar1 = false;
        piVar4[iVar2 + 1] = iVar10;
        iVar3 = iVar10;
      }
      iVar2 = iVar2 + 1;
      iVar10 = iVar3;
    } while (iVar2 != 3);
  } while (!bVar1);
  iVar10 = 0;
  iVar2 = 0;
  do {
    if (0 < piVar4[iVar2]) {
      piVar4[iVar2] = piVar4[iVar2] + iVar10;
    }
    iVar2 = iVar2 + 1;
    iVar10 = iVar10 + -2;
  } while (iVar2 != 4);
  pvVar11 = operator_new__(0x20);
  iVar10 = 0;
  do {
    uVar13 = (iVar10 - (iVar10 >> 0x1f)) * 2 & 0xfffffffc;
    *(undefined4 *)((int)pvVar11 + iVar10 * 4) = *(undefined4 *)((int)pvVar5 + uVar13);
    iVar2 = iVar10 * 4;
    iVar10 = iVar10 + 2;
    *(undefined4 *)((int)pvVar11 + iVar2 + 4) = *(undefined4 *)((int)piVar4 + uVar13);
  } while (iVar10 < 8);
  operator_delete__(piVar4);
  operator_delete__(pvVar5);
  return pvVar11;
}

