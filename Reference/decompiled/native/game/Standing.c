// Class: Standing
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Standing::Standing  @0x001427f4  (32 bytes)
/* Standing::Standing() */

Standing * __thiscall Standing::Standing(Standing *this)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new__(8);
  *(undefined4 **)this = puVar1;
  *puVar1 = 0x1e;
  puVar1[1] = 0;
  *(undefined4 *)(this + 4) = 0xffffffff;
  return this;
}

// ===== Standing::~Standing  @0x00142814  (22 bytes)
/* Standing::~Standing() */

Standing * __thiscall Standing::~Standing(Standing *this)

{
  if (*(void **)this != (void *)0x0) {
    operator_delete__(*(void **)this);
  }
  *(undefined4 *)this = 0;
  return this;
}

// ===== Standing::setStanding  @0x0014282a  (8 bytes)
/* Standing::setStanding(int, int) */

void __thiscall Standing::setStanding(Standing *this,int param_1,int param_2)

{
  *(int *)(*(int *)this + param_1 * 4) = param_2;
  return;
}

// ===== Standing::setStandings  @0x00142832  (4 bytes)
/* Standing::setStandings(int*) */

void __thiscall Standing::setStandings(Standing *this,int *param_1)

{
  *(int **)this = param_1;
  return;
}

// ===== Standing::getStandings  @0x00142836  (4 bytes)
/* Standing::getStandings() */

undefined4 __thiscall Standing::getStandings(Standing *this)

{
  return *(undefined4 *)this;
}

// ===== Standing::getStanding  @0x0014283a  (56 bytes)
/* Standing::getStanding(int) */

undefined4 __thiscall Standing::getStanding(Standing *this,int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(this + 4);
  if (-1 < iVar2) {
    if (param_1 == 1) {
      uVar1 = 0x46;
      if (iVar2 == 2) {
        uVar1 = 100;
      }
      if (iVar2 == 3) {
        uVar1 = 0xffffff9c;
      }
      return uVar1;
    }
    if (param_1 == 0) {
      uVar1 = 0x46;
      if (iVar2 == 0) {
        uVar1 = 100;
      }
      if (iVar2 == 1) {
        uVar1 = 0xffffff9c;
      }
      return uVar1;
    }
  }
  return *(undefined4 *)(*(int *)this + param_1 * 4);
}

// ===== Standing::getStandingRate  @0x00142874  (30 bytes)
/* Standing::getStandingRate(int) */

float __thiscall Standing::getStandingRate(Standing *this,int param_1)

{
  undefined4 uVar1;
  uint in_fpscr;
  float fVar2;
  
  uVar1 = getStanding(this,param_1);
  fVar2 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
  return fVar2 / 100.0;
}

// ===== Standing::setPlayerSignatureRace  @0x00142898  (4 bytes)
/* Standing::setPlayerSignatureRace(int) */

void __thiscall Standing::setPlayerSignatureRace(Standing *this,int param_1)

{
  *(int *)(this + 4) = param_1;
  return;
}

// ===== Standing::rehabilitate  @0x0014289c  (44 bytes)
/* Standing::rehabilitate(int) */

void __thiscall Standing::rehabilitate(Standing *this,int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  switch(param_1) {
  case 0:
    **(undefined4 **)this = 0xffffffdd;
    return;
  case 1:
    **(undefined4 **)this = 0x23;
    return;
  case 2:
    iVar1 = *(int *)this;
    uVar2 = 0xffffffdd;
    break;
  case 3:
    iVar1 = *(int *)this;
    uVar2 = 0x23;
    break;
  default:
    return;
  }
  *(undefined4 *)(iVar1 + 4) = uVar2;
  return;
}

// ===== Standing::isEnemyWithAnyone  @0x001428cc  (34 bytes)
/* Standing::isEnemyWithAnyone() */

bool __thiscall Standing::isEnemyWithAnyone(Standing *this)

{
  return 0x8c < (*(int **)this)[1] + 0x46U || 0x8c < **(int **)this + 0x46U;
}

// ===== Standing::isEnemy  @0x001428ee  (118 bytes)
/* Standing::isEnemy(int) */

bool __thiscall Standing::isEnemy(Standing *this,int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 4);
  if (iVar1 < 0) {
    if (param_1 == 1) {
      iVar1 = **(int **)this;
    }
    else {
      if (param_1 != 3) {
        if (param_1 == 2) {
          iVar1 = *(int *)(*(int *)this + 4);
        }
        else {
          if (param_1 != 0) {
            return false;
          }
          iVar1 = **(int **)this;
        }
        if (-0x47 < iVar1) {
          return false;
        }
        return true;
      }
      iVar1 = *(int *)(*(int *)this + 4);
    }
    return 0x46 < iVar1;
  }
  if (param_1 == 1) {
    return iVar1 == 0;
  }
  if (param_1 == 3) {
    return iVar1 == 2;
  }
  if (param_1 == 2) {
    return iVar1 == 3;
  }
  if (param_1 != 0) {
    return false;
  }
  return iVar1 == 1;
}

// ===== Standing::isFriend  @0x00142964  (120 bytes)
/* Standing::isFriend(int) */

bool __thiscall Standing::isFriend(Standing *this,int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 4);
  if (iVar1 < 0) {
    if (param_1 == 1) {
      iVar1 = **(int **)this;
    }
    else {
      if (param_1 != 3) {
        if (param_1 == 2) {
          iVar1 = *(int *)(*(int *)this + 4);
        }
        else {
          if (param_1 != 0) {
            return false;
          }
          iVar1 = **(int **)this;
        }
        if (iVar1 < 0x47) {
          return false;
        }
        return true;
      }
      iVar1 = *(int *)(*(int *)this + 4);
    }
    return iVar1 < -0x46;
  }
  if (param_1 == 1) {
    return iVar1 == 1;
  }
  if (param_1 == 3) {
    return iVar1 == 3;
  }
  if (param_1 == 2) {
    return iVar1 == 2;
  }
  if (param_1 != 0) {
    return false;
  }
  return iVar1 == 0;
}

// ===== Standing::isNeutral  @0x001429dc  (32 bytes)
/* Standing::isNeutral(int) */

uint __thiscall Standing::isNeutral(Standing *this,int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = isEnemy(this,param_1);
  if (iVar1 != 0) {
    return 0;
  }
  uVar2 = isFriend(this,param_1);
  return uVar2 ^ 1;
}

// ===== Standing::getEnemyRace  @0x001429fc  (18 bytes)
/* Standing::getEnemyRace(int) */

undefined4 __thiscall Standing::getEnemyRace(Standing *this,int param_1)

{
  if ((uint)param_1 < 4) {
    return *(undefined4 *)(&DAT_00252020 + param_1 * 4);
  }
  return 8;
}

// ===== Standing::applyPoints  @0x00142a14  (38 bytes)
/* Standing::applyPoints(int, int) */

void __thiscall Standing::applyPoints(Standing *this,int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)this;
  iVar2 = param_2 + *(int *)(iVar1 + param_1 * 4);
  *(int *)(iVar1 + param_1 * 4) = iVar2;
  if (iVar2 < 0x65) {
    if (-0x65 < iVar2) {
      return;
    }
    uVar3 = 0xffffff9c;
  }
  else {
    uVar3 = 100;
  }
  *(undefined4 *)(iVar1 + param_1 * 4) = uVar3;
  return;
}

// ===== Standing::applyKill  @0x00142a3c  (92 bytes)
/* Standing::applyKill(int) */

void __thiscall Standing::applyKill(Standing *this,int param_1)

{
  int iVar1;
  uint uVar2;
  SolarSystem *this_00;
  
  iVar1 = Status::inAlienOrbit(Globals::status);
  if (iVar1 == 0) {
    this_00 = (SolarSystem *)Status::getSystem(Globals::status);
    uVar2 = SolarSystem::getRace(this_00);
  }
  else {
    uVar2 = 9;
  }
  if (param_1 == 8) {
    if (-1 < *(int *)(this + 4)) {
      return;
    }
    if (uVar2 < 4) {
      iVar1 = 1;
      param_1 = *(int *)(&DAT_00252020 + uVar2 * 4);
    }
    else {
      iVar1 = 1;
      param_1 = 8;
    }
  }
  else {
    iVar1 = 5;
  }
  applyDelict(this,param_1,iVar1);
  return;
}

// ===== Standing::applyDelict  @0x00142aa4  (116 bytes)
/* Standing::applyDelict(int, int) */

void __thiscall Standing::applyDelict(Standing *this,int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  
  uVar1 = Status::hardCoreMode();
  if (3 < (uint)param_1) {
    return;
  }
  iVar2 = param_2 << (uVar1 & 0xff);
  switch(param_1) {
  case 0:
    piVar4 = *(int **)this;
    iVar2 = *piVar4 - iVar2;
    break;
  case 1:
    piVar4 = *(int **)this;
    iVar2 = iVar2 + *piVar4;
    break;
  case 2:
    iVar5 = *(int *)this;
    iVar2 = *(int *)(iVar5 + 4) - iVar2;
    goto LAB_00142af4;
  case 3:
    iVar5 = *(int *)this;
    iVar2 = iVar2 + *(int *)(iVar5 + 4);
LAB_00142af4:
    *(int *)(iVar5 + 4) = iVar2;
    if (iVar2 < 0x65) {
      if (-0x65 < iVar2) {
        return;
      }
      uVar3 = 0xffffff9c;
    }
    else {
      uVar3 = 100;
    }
    *(undefined4 *)(iVar5 + 4) = uVar3;
    return;
  }
  *piVar4 = iVar2;
  if (iVar2 < 0x65) {
    if (iVar2 < -100) {
      *piVar4 = -100;
    }
  }
  else {
    *piVar4 = 100;
  }
  return;
}

// ===== Standing::applyStealCargo  @0x00142b20  (6 bytes)
/* Standing::applyStealCargo(int) */

void __thiscall Standing::applyStealCargo(Standing *this,int param_1)

{
  applyDelict(this,param_1,2);
  return;
}

// ===== Standing::applyMissionCompleted  @0x00142b26  (8 bytes)
/* Standing::applyMissionCompleted(int) */

void __thiscall Standing::applyMissionCompleted(Standing *this,int param_1)

{
  applyDelict(this,param_1,-5);
  return;
}

// ===== Standing::applyDisable  @0x00142b2e  (8 bytes)
/* Standing::applyDisable(int) */

void __thiscall Standing::applyDisable(Standing *this,int param_1)

{
  applyDelict(this,param_1,2);
  return;
}

// ===== Standing::getMissionBonus  @0x00142b34  (72 bytes)
/* Standing::getMissionBonus(int) */

undefined4 __thiscall Standing::getMissionBonus(Standing *this,int param_1)

{
  int iVar1;
  uint in_fpscr;
  float fVar2;
  undefined8 in_d0;
  undefined8 uVar3;
  uint in_s3;
  
  switch(param_1) {
  case 0:
    iVar1 = **(int **)this;
    goto LAB_00142b66;
  case 1:
    iVar1 = **(int **)this;
    break;
  case 2:
    iVar1 = *(int *)(*(int *)this + 4);
    goto LAB_00142b66;
  case 3:
    iVar1 = *(int *)(*(int *)this + 4);
    break;
  default:
    return 0;
  }
  iVar1 = -iVar1;
LAB_00142b66:
  fVar2 = (float)VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x16) & 3);
  uVar3 = FloatVectorMax(CONCAT44((int)((ulonglong)in_d0 >> 0x20),fVar2 / 100.0),
                         (ulonglong)in_s3 << 0x20,2,0x20);
  return (int)uVar3;
}

