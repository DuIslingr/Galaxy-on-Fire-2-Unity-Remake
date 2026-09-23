// Class: Achievements
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Achievements::Achievements  @0x00181e7c  (34 bytes)
/* Achievements::Achievements() */

Achievements * __thiscall Achievements::Achievements(Achievements *this)

{
  void *pvVar1;
  
  pvVar1 = operator_new__(0xb4);
  *(void **)this = pvVar1;
  pvVar1 = operator_new__(0xb4);
  *(void **)(this + 4) = pvVar1;
  this[0x22] = (Achievements)0x0;
  *(undefined2 *)(this + 0x20) = 0;
  return this;
}

// ===== Achievements::~Achievements  @0x00181e9e  (32 bytes)
/* Achievements::~Achievements() */

Achievements * __thiscall Achievements::~Achievements(Achievements *this)

{
  if (*(void **)this != (void *)0x0) {
    operator_delete__(*(void **)this);
  }
  *(undefined4 *)this = 0;
  if (*(void **)(this + 4) != (void *)0x0) {
    operator_delete__(*(void **)(this + 4));
  }
  *(undefined4 *)(this + 4) = 0;
  return this;
}

// ===== Achievements::checkForNewMedal  @0x00181ec0  (970 bytes)
/* Achievements::checkForNewMedal(PlayerEgo*) */

void Achievements::checkForNewMedal(PlayerEgo *param_1)

{
  byte *pbVar1;
  int iVar2;
  Status *pSVar3;
  Standing *this;
  Ship *this_00;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  undefined8 uVar13;
  
  initCheckEquipmentAndWeapons((Achievements *)param_1);
  iVar10 = 0;
  iVar2 = *(int *)param_1;
  do {
    if (*(int *)(iVar2 + iVar10 * 4) == 1) {
      iVar11 = 0;
LAB_00181eee:
      *(int *)(*(int *)(param_1 + 4) + iVar10 * 4) = iVar11;
    }
    else {
      iVar2 = 0;
      iVar11 = 0;
      do {
        uVar8 = *(uint *)(&UNK_00259860 + iVar2 * 4 + iVar10 * 0xc);
        if ((int)uVar8 < 0) goto switchD_00181f22_default;
        if (0 < iVar11) break;
        switch(iVar10) {
        case 1:
          iVar6 = PlayerEgo::getHullDamageRate();
          if (iVar6 <= (int)uVar8) goto LAB_00182262;
          goto switchD_00181f22_default;
        case 2:
          pSVar3 = Globals::status + 0x94;
          goto LAB_00181fac;
        case 3:
        case 9:
          if (iVar10 == 3) {
            pSVar3 = Globals::status + 0x98;
          }
          else {
            pSVar3 = Globals::status + 0xac;
          }
LAB_00181fac:
          uVar5 = **(uint **)pSVar3;
          if (uVar5 == 0) {
LAB_001820c6:
            iVar6 = 0;
          }
          else {
            iVar6 = 0;
            uVar7 = 0;
            do {
              pbVar1 = (byte *)((*(uint **)pSVar3)[1] + uVar7);
              uVar7 = uVar7 + 1;
              iVar6 = iVar6 + (uint)*pbVar1;
            } while (uVar7 < uVar5);
          }
          goto joined_r0x00182098;
        case 4:
          iVar6 = Status::getKills(Globals::status);
          goto joined_r0x00182098;
        case 5:
          iVar6 = *(int *)(Globals::status + 0x9c);
          break;
        case 6:
          iVar6 = *(int *)(Globals::status + 0xa0);
          break;
        case 7:
          iVar6 = *(int *)(Globals::status + 0xa4);
          break;
        case 8:
          iVar6 = *(int *)(Globals::status + 0xa8);
          break;
        case 10:
          iVar6 = *(int *)(Globals::status + 0xb0);
          break;
        case 0xb:
          iVar6 = Status::getStationsVisited(Globals::status);
          goto joined_r0x00182098;
        case 0xc:
          iVar9 = 0;
          iVar6 = 0;
          do {
            pbVar1 = (byte *)(*(int *)(*(int *)(Globals::status + 0xb4) + 4) + iVar9);
            iVar9 = iVar9 + 1;
            iVar6 = iVar6 + (uint)*pbVar1;
          } while (iVar9 != 0x16);
          goto joined_r0x00182098;
        case 0xd:
          iVar6 = 0;
          puVar4 = *(uint **)(Globals::status + 0x18);
          if (*puVar4 != 0) {
            uVar5 = 0;
            do {
              iVar9 = BluePrint::isUnlocked(*(BluePrint **)(puVar4[1] + uVar5 * 4));
              uVar5 = uVar5 + 1;
              puVar4 = *(uint **)(Globals::status + 0x18);
              if (iVar9 != 0) {
                iVar6 = iVar6 + 1;
              }
            } while (uVar5 < *puVar4);
          }
          goto joined_r0x00182098;
        case 0xe:
          uVar5 = **(uint **)(Globals::status + 0x18);
          if (uVar5 != 0) {
            iVar6 = 0;
            uVar7 = 0;
            do {
              iVar9 = uVar7 * 4;
              uVar7 = uVar7 + 1;
              if (0 < *(int *)(*(int *)((*(uint **)(Globals::status + 0x18))[1] + iVar9) + 0xc)) {
                iVar6 = iVar6 + 1;
              }
            } while (uVar7 < uVar5);
            goto joined_r0x00182098;
          }
          goto LAB_001820c6;
        case 0xf:
          uVar8 = uVar8 * 3600000;
          iVar9 = (int)uVar8 >> 0x1f;
          uVar13 = Status::getPlayingTime(Globals::status);
          iVar6 = (int)((ulonglong)uVar13 >> 0x20);
          bVar12 = uVar8 < (uint)uVar13;
          if ((int)((iVar9 - iVar6) - (uint)bVar12) < 0 !=
              (SBORROW4(iVar9,iVar6) != SBORROW4(iVar9 - iVar6,(uint)bVar12))) goto LAB_00182262;
          goto switchD_00181f22_default;
        case 0x10:
          iVar6 = Status::getMissionCount(Globals::status);
          break;
        case 0x11:
          iVar6 = Status::getJumpgateUsed(Globals::status);
          goto joined_r0x00182098;
        case 0x12:
          iVar6 = *(int *)(Globals::status + 0xb8);
          break;
        case 0x13:
          uVar13 = __aeabi_ldivmod(*(undefined4 *)(Globals::status + 0xc0),
                                   *(undefined4 *)(Globals::status + 0xc4),60000,0);
          iVar9 = (int)((ulonglong)uVar13 >> 0x20);
          bVar12 = (uint)uVar13 < uVar8;
          iVar6 = (int)uVar8 >> 0x1f;
          if ((int)((iVar9 - iVar6) - (uint)bVar12) < 0 ==
              (SBORROW4(iVar9,iVar6) != SBORROW4(iVar9 - iVar6,(uint)bVar12))) goto LAB_00182262;
          goto switchD_00181f22_default;
        case 0x14:
          iVar6 = *(int *)(Globals::status + 200);
          break;
        case 0x15:
          iVar6 = *(int *)(Globals::status + 0xcc);
          break;
        case 0x16:
          if (param_1[0x18] == (PlayerEgo)0x0) goto LAB_00182262;
          goto switchD_00181f22_default;
        case 0x17:
          iVar6 = *(int *)(param_1 + 0x14);
          goto joined_r0x00182098;
        case 0x18:
          iVar6 = Status::getCapturedCrates(Globals::status);
          goto joined_r0x00182098;
        case 0x19:
          iVar6 = *(int *)(param_1 + 0x1c);
          goto joined_r0x00182098;
        case 0x1a:
          iVar6 = *(int *)(Globals::status + 0xd0);
          break;
        case 0x1b:
          iVar6 = *(int *)(Globals::status + 0xd4);
          break;
        case 0x1c:
          this = (Standing *)Status::getStanding(Globals::status);
          uVar8 = Standing::isEnemyWithAnyone(this);
          goto LAB_001822ac;
        case 0x1d:
          iVar6 = *(int *)(Globals::status + 0xd8);
          break;
        case 0x1e:
          uVar8 = Status::gameWon(Globals::status);
          goto LAB_001822ac;
        case 0x1f:
          iVar6 = *(int *)(Globals::status + 0xdc);
          break;
        case 0x20:
          iVar6 = *(int *)(Globals::status + 0xe0);
          break;
        case 0x21:
          iVar6 = *(int *)(Globals::status + 0xe8);
          break;
        case 0x22:
          iVar6 = *(int *)(Globals::status + 0xec);
          break;
        case 0x23:
          iVar6 = 0;
          do {
            if (*(int *)(*(int *)param_1 + iVar6 * 4) == 0) goto switchD_00181f22_default;
            iVar6 = iVar6 + 1;
          } while (iVar6 < 0x2c);
          goto LAB_00182262;
        case 0x24:
          this_00 = (Ship *)Status::getShip(Globals::status);
          iVar6 = Ship::getMaxLoad(this_00);
          break;
        case 0x25:
          puVar4 = (uint *)Station::getShips(*(Station **)(Globals::status + 0x14c));
          if ((puVar4 != (uint *)0x0) && (uVar8 <= *puVar4)) goto LAB_00182262;
          goto switchD_00181f22_default;
        case 0x26:
          uVar8 = (uint)(byte)Globals::status[0x128];
          goto LAB_001822ac;
        case 0x27:
          iVar6 = *(int *)(Globals::status + 0x118);
joined_r0x00182098:
          if ((int)uVar8 <= iVar6) goto LAB_00182262;
          goto switchD_00181f22_default;
        case 0x28:
          uVar8 = (uint)(byte)Globals::status[0x120];
          goto LAB_001822ac;
        case 0x29:
          uVar8 = (uint)(byte)Globals::status[0x130];
          goto LAB_001822ac;
        case 0x2a:
          uVar8 = (uint)(byte)Globals::status[0x138];
          goto LAB_001822ac;
        case 0x2b:
          uVar8 = (uint)(byte)Globals::status[0x140];
          goto LAB_001822ac;
        case 0x2c:
          uVar8 = (uint)(byte)Globals::status[0x148];
LAB_001822ac:
          if (uVar8 != 0) {
            iVar11 = iVar2 + 1;
          }
        default:
          goto switchD_00181f22_default;
        }
        if ((int)uVar8 < iVar6) {
LAB_00182262:
          iVar11 = iVar2 + 1;
        }
switchD_00181f22_default:
        iVar2 = iVar2 + 1;
      } while (iVar2 < 3);
      iVar2 = *(int *)param_1;
      iVar6 = *(int *)(iVar2 + iVar10 * 4);
      if ((iVar11 < iVar6) || (iVar6 == 0)) goto LAB_00181eee;
    }
    iVar10 = iVar10 + 1;
    if (iVar10 == 0x2d) {
      return;
    }
  } while( true );
}

// ===== Achievements::initCheckEquipmentAndWeapons  @0x00182388  (178 bytes)
/* Achievements::initCheckEquipmentAndWeapons() */

void __thiscall Achievements::initCheckEquipmentAndWeapons(Achievements *this)

{
  Achievements AVar1;
  int iVar2;
  Ship *this_00;
  uint *puVar3;
  Item *this_01;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar2 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar2 < 8) {
    AVar1 = (Achievements)0x1;
  }
  else {
    this_00 = (Ship *)Status::getShip(Globals::status);
    puVar3 = (uint *)Ship::getEquipment(this_00);
    iVar2 = 0;
    iVar6 = 0;
    if (puVar3 != (uint *)0x0) {
      if (*puVar3 == 0) {
        iVar2 = 0;
        iVar6 = 0;
      }
      else {
        uVar5 = 0;
        iVar6 = 0;
        iVar2 = 0;
        do {
          this_01 = *(Item **)(puVar3[1] + uVar5 * 4);
          if ((this_01 != (Item *)0x0) && (iVar4 = Item::getType(this_01), iVar4 != 4)) {
            iVar4 = Item::getType(*(Item **)(puVar3[1] + uVar5 * 4));
            if (iVar4 == 0) {
              *(int *)(this + 0x14) = *(int *)(this + 0x14) + 1;
            }
            else {
              iVar4 = Item::getType(*(Item **)(puVar3[1] + uVar5 * 4));
              if (iVar4 == 3) {
                iVar6 = iVar6 + 1;
                goto LAB_00182406;
              }
            }
            iVar2 = iVar2 + 1;
          }
LAB_00182406:
          uVar5 = uVar5 + 1;
        } while (uVar5 < *puVar3);
      }
    }
    AVar1 = (Achievements)(0 < iVar6 && 0 < iVar2);
  }
  this[0x18] = AVar1;
  return;
}

// ===== Achievements::countMedals  @0x00182444  (130 bytes)
/* Achievements::countMedals() */

void __thiscall Achievements::countMedals(Achievements *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar2 = 0;
  *(undefined4 *)(this + 0x24) = 0;
  iVar4 = 0;
  do {
    iVar3 = *(int *)(*(int *)this + iVar2 * 4);
    if (iVar3 != 0) {
      iVar5 = iVar5 + 1;
      if (iVar3 == 1) {
        *(int *)(this + 0x24) = iVar5;
        iVar4 = iVar4 + 1;
      }
      else {
        *(int *)(this + 0x24) = iVar5;
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x24);
  iVar3 = 0;
  iVar2 = 0;
  do {
    iVar1 = iVar3 * 4;
    iVar3 = iVar3 + 1;
    if (*(int *)(*(int *)this + 0x90 + iVar1) != 0) {
      iVar2 = iVar2 + 1;
    }
  } while (iVar3 != 9);
  this[0x20] = (Achievements)(iVar5 == 0x24);
  this[0x21] = (Achievements)(iVar4 == 0x24);
  this[0x22] = (Achievements)(iVar4 == 0x24 && iVar2 == 9);
  return;
}

// ===== Achievements::gotAllMedals  @0x001824c6  (6 bytes)
/* Achievements::gotAllMedals() */

Achievements __thiscall Achievements::gotAllMedals(Achievements *this)

{
  return this[0x20];
}

// ===== Achievements::gotAllGoldMedals  @0x001824cc  (6 bytes)
/* Achievements::gotAllGoldMedals() */

Achievements __thiscall Achievements::gotAllGoldMedals(Achievements *this)

{
  return this[0x21];
}

// ===== Achievements::gotAllSupernovaMedals  @0x001824d2  (6 bytes)
/* Achievements::gotAllSupernovaMedals() */

Achievements __thiscall Achievements::gotAllSupernovaMedals(Achievements *this)

{
  return this[0x22];
}

// ===== Achievements::getMedals  @0x001824d8  (4 bytes)
/* Achievements::getMedals() */

undefined4 __thiscall Achievements::getMedals(Achievements *this)

{
  return *(undefined4 *)this;
}

// ===== Achievements::getNewMedals  @0x001824dc  (4 bytes)
/* Achievements::getNewMedals() */

undefined4 __thiscall Achievements::getNewMedals(Achievements *this)

{
  return *(undefined4 *)(this + 4);
}

// ===== Achievements::incKills  @0x001824e0  (8 bytes)
/* Achievements::incKills() */

void __thiscall Achievements::incKills(Achievements *this)

{
  *(int *)(this + 8) = *(int *)(this + 8) + 1;
  return;
}

// ===== Achievements::getKills  @0x001824e8  (4 bytes)
/* Achievements::getKills() */

undefined4 __thiscall Achievements::getKills(Achievements *this)

{
  return *(undefined4 *)(this + 8);
}

// ===== Achievements::incPirateKills  @0x001824ec  (8 bytes)
/* Achievements::incPirateKills() */

void __thiscall Achievements::incPirateKills(Achievements *this)

{
  *(int *)(this + 0x10) = *(int *)(this + 0x10) + 1;
  return;
}

// ===== Achievements::getPirateKills  @0x001824f4  (4 bytes)
/* Achievements::getPirateKills() */

undefined4 __thiscall Achievements::getPirateKills(Achievements *this)

{
  return *(undefined4 *)(this + 0x10);
}

// ===== Achievements::resetPirateKills  @0x001824f8  (6 bytes)
/* Achievements::resetPirateKills() */

void __thiscall Achievements::resetPirateKills(Achievements *this)

{
  *(undefined4 *)(this + 0x10) = 0;
  return;
}

// ===== Achievements::incCatches  @0x001824fe  (8 bytes)
/* Achievements::incCatches() */

void __thiscall Achievements::incCatches(Achievements *this)

{
  *(int *)(this + 0xc) = *(int *)(this + 0xc) + 1;
  return;
}

// ===== Achievements::getCatches  @0x00182506  (4 bytes)
/* Achievements::getCatches() */

undefined4 __thiscall Achievements::getCatches(Achievements *this)

{
  return *(undefined4 *)(this + 0xc);
}

// ===== Achievements::updateCredits  @0x0018250a  (10 bytes)
/* Achievements::updateCredits(int) */

void __thiscall Achievements::updateCredits(Achievements *this,int param_1)

{
  if (*(int *)(this + 0x1c) < param_1) {
    *(int *)(this + 0x1c) = param_1;
  }
  return;
}

// ===== Achievements::setMedals  @0x00182514  (62 bytes)
/* Achievements::setMedals(int*, int) */

void __thiscall Achievements::setMedals(Achievements *this,int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (0 < param_2) {
    iVar3 = *(int *)this;
    iVar1 = 0;
    do {
      uVar2 = param_1[iVar1];
      if (3 < uVar2) {
        uVar2 = 0;
      }
      *(uint *)(iVar3 + iVar1 * 4) = uVar2;
      iVar1 = iVar1 + 1;
    } while (param_2 != iVar1);
    if (0x2c < param_2) {
      return;
    }
  }
  __aeabi_memclr4(*(int *)this + param_2 * 4,param_2 * -4 + 0xb4);
  return;
}

// ===== Achievements::setMedal  @0x00182552  (8 bytes)
/* Achievements::setMedal(int, int) */

void __thiscall Achievements::setMedal(Achievements *this,int param_1,int param_2)

{
  *(int *)(*(int *)this + param_1 * 4) = param_2;
  return;
}

// ===== Achievements::init  @0x0018255a  (48 bytes)
/* Achievements::init() */

void __thiscall Achievements::init(Achievements *this)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)this;
  __aeabi_memclr4(puVar1 + 1,0xb0);
  *puVar1 = 1;
  __aeabi_memclr4(*(undefined4 *)(this + 4),0xb4);
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  this[0x18] = (Achievements)0x0;
  *(undefined4 *)(this + 0x1c) = 0;
  return;
}

// ===== Achievements::resetNewMedals  @0x0018258a  (32 bytes)
/* Achievements::resetNewMedals() */

void __thiscall Achievements::resetNewMedals(Achievements *this)

{
  __aeabi_memclr4(*(undefined4 *)(this + 4),0xb4);
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  this[0x18] = (Achievements)0x0;
  return;
}

// ===== Achievements::applyNewMedals  @0x001825aa  (88 bytes)
/* Achievements::applyNewMedals() */

void __thiscall Achievements::applyNewMedals(Achievements *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = 0;
  iVar1 = *(int *)(this + 4);
  do {
    iVar3 = *(int *)(iVar1 + iVar2 * 4);
    if (0 < iVar3) {
      iVar4 = *(int *)this;
      iVar5 = *(int *)(iVar4 + iVar2 * 4);
      if (iVar3 < iVar5) {
        *(int *)(iVar4 + iVar2 * 4) = iVar3;
      }
      else if (iVar5 == 0) {
        *(int *)(iVar4 + iVar2 * 4) = iVar3;
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x2d);
  countMedals(this);
  if (*(int *)(this + 0x24) == 0x23) {
    *(undefined4 *)(*(int *)(this + 4) + 0x8c) = 1;
    *(undefined4 *)(*(int *)this + 0x8c) = 1;
    countMedals(this);
    return;
  }
  return;
}

// ===== Achievements::hasMedal  @0x00182600  (16 bytes)
/* Achievements::hasMedal(int, int) */

bool __thiscall Achievements::hasMedal(Achievements *this,int param_1,int param_2)

{
  return *(int *)(*(int *)this + param_1 * 4) == param_2;
}

// ===== Achievements::getValue  @0x00182610  (22 bytes)
/* Achievements::getValue(int, int) */

undefined4 __thiscall Achievements::getValue(Achievements *this,int param_1,int param_2)

{
  return *(undefined4 *)("7MineGun" + param_1 * 0xc + param_2 * 4 + 8);
}

// ===== Achievements::isEliteMedal  @0x0018262c  (10 bytes)
/* Achievements::isEliteMedal(int) */

bool __thiscall Achievements::isEliteMedal(Achievements *this,int param_1)

{
  return 0x23 < param_1;
}

