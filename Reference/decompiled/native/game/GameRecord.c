// Class: GameRecord
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== GameRecord::GameRecord  @0x00180cde  (180 bytes)
/* GameRecord::GameRecord() */

GameRecord * __thiscall GameRecord::GameRecord(GameRecord *this)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  AbyssEngine::String::String((String *)(this + 0x188));
  AbyssEngine::String::String((String *)(this + 400));
  pvVar1 = operator_new__(0x87);
  *(void **)this = pvVar1;
  *(undefined4 *)(this + 0x11c) = 0;
  __aeabi_memclr8(this + 8,0x8c);
  uVar2 = 0;
  uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar5 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0xb8) = 0;
  *(undefined4 *)(this + 0xbc) = uVar3;
  *(undefined4 *)(this + 0xc0) = uVar4;
  *(undefined4 *)(this + 0xc4) = uVar5;
  *(undefined4 *)(this + 0xa8) = 0;
  *(undefined4 *)(this + 0xac) = uVar3;
  *(undefined4 *)(this + 0xb0) = uVar4;
  *(undefined4 *)(this + 0xb4) = uVar5;
  *(undefined4 *)(this + 0x98) = 0;
  *(undefined4 *)(this + 0x9c) = uVar3;
  *(undefined4 *)(this + 0xa0) = uVar4;
  *(undefined4 *)(this + 0xa4) = uVar5;
  *(undefined4 *)(this + 0x198) = 0xffffffff;
  *(undefined4 *)(this + 200) = 0;
  *(undefined4 *)(this + 0xcc) = 0;
  *(undefined4 *)(this + 0xd0) = 0;
  this[0xd4] = (GameRecord)0x0;
  *(undefined4 *)(this + 0xd8) = 0;
  this[0xdc] = (GameRecord)0x0;
  this[0x1b8] = (GameRecord)0x0;
  *(undefined4 *)(this + 0x10b) = 0;
  *(undefined4 *)(this + 0x10f) = uVar3;
  *(undefined4 *)(this + 0x113) = uVar4;
  *(undefined4 *)(this + 0x117) = uVar5;
  *(undefined4 *)(this + 0x100) = 0;
  *(undefined4 *)(this + 0x104) = uVar3;
  *(undefined4 *)(this + 0x108) = uVar4;
  *(undefined4 *)(this + 0x10c) = uVar5;
  *(undefined4 *)(this + 0xf0) = 0;
  *(undefined4 *)(this + 0xf4) = uVar3;
  *(undefined4 *)(this + 0xf8) = uVar4;
  *(undefined4 *)(this + 0xfc) = uVar5;
  *(undefined4 *)(this + 0xe0) = 0;
  *(undefined4 *)(this + 0xe4) = uVar3;
  *(undefined4 *)(this + 0xe8) = uVar4;
  *(undefined4 *)(this + 0xec) = uVar5;
  __aeabi_memclr8(this + 0x130,0x58);
  *(undefined4 *)(this + 0x19c) = uVar2;
  *(undefined4 *)(this + 0x1a0) = uVar3;
  *(undefined4 *)(this + 0x1a4) = uVar4;
  *(undefined4 *)(this + 0x1a8) = uVar5;
  *(undefined4 *)(this + 0x1ac) = 0;
  *(undefined4 *)(this + 0x1b0) = 0;
  return this;
}

// ===== GameRecord::~GameRecord  @0x00180daa  (26 bytes)
/* GameRecord::~GameRecord() */

GameRecord * __thiscall GameRecord::~GameRecord(GameRecord *this)

{
  AbyssEngine::String::~String((String *)(this + 400));
  AbyssEngine::String::~String((String *)(this + 0x188));
  return this;
}

// ===== GameRecord::load  @0x00180dc4  (2936 bytes)
/* GameRecord::load() */

void __thiscall GameRecord::load(GameRecord *this)

{
  int iVar1;
  int iVar2;
  Galaxy *pGVar3;
  int iVar4;
  Mission *pMVar5;
  Ship *pSVar6;
  Item *pIVar7;
  uint *puVar8;
  BluePrint *this_00;
  Station *pSVar9;
  SolarSystem *this_01;
  Status *pSVar10;
  uint *puVar11;
  undefined4 extraout_r1;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  void *pvVar16;
  uint uVar17;
  undefined4 uVar18;
  GameRecord *pGVar19;
  undefined8 uVar20;
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  Status::resetGame(Globals::status);
  Galaxy::setVisited(Globals::galaxy,*(bool **)this,*(int *)(this + 4));
  Status::setLastXP(Globals::status,*(int *)(this + 0x24));
  Status::setCredits(Globals::status,*(int *)(this + 8));
  Status::setRating(Globals::status,*(int *)(this + 0xc));
  Status::setPlayingTime(CONCAT44(extraout_r1,Globals::status));
  Status::setKills(Globals::status,*(int *)(this + 0x18));
  Status::setMissionCount(Globals::status,*(int *)(this + 0x1c));
  Status::setLevel(Globals::status,*(int *)(this + 0x20));
  Status::setLastXP(Globals::status,*(int *)(this + 0x24));
  Status::setGoodsProduced(Globals::status,*(int *)(this + 0x28));
  Status::setPirateKills(Globals::status,*(int *)(this + 0x2c));
  Status::setJumpgateUsed(Globals::status,*(int *)(this + 0x30));
  Status::setCapturedCrates(Globals::status,*(int *)(this + 0x34));
  Status::setBoughtEquipment(Globals::status,*(int *)(this + 0x38));
  Status::setStationsVisited(Globals::status,*(int *)(this + 0x3c));
  pSVar10 = Globals::status;
  *(undefined4 *)(Globals::status + 0x80) = *(undefined4 *)(this + 0x44);
  *(undefined4 *)(pSVar10 + 0x7c) = *(undefined4 *)(this + 0x48);
  *(undefined4 *)(pSVar10 + 0x84) = *(undefined4 *)(this + 0x4c);
  *(undefined4 *)(pSVar10 + 0x88) = *(undefined4 *)(this + 0x50);
  if (this[0x115] == (GameRecord)0x0) {
    if (this[0x117] == (GameRecord)0x0) {
      if (0x2d < *(int *)(this + 0x40)) {
        *(undefined4 *)(this + 0x40) = 0x2d;
      }
      goto LAB_00180ec4;
    }
LAB_00180ed4:
    if ((*(int *)(this + 0x40) == 0x2e) &&
       (iVar4 = Mission::isEmpty(*(Mission **)(this + 0x58)), iVar4 == 1)) {
      *(undefined4 *)(this + 0x40) = 0x2d;
    }
  }
  else {
    if (this[0x117] != (GameRecord)0x0) goto LAB_00180ed4;
LAB_00180ec4:
    if (0x54 < *(int *)(this + 0x40)) {
      *(undefined4 *)(this + 0x40) = 0x54;
    }
    if (this[0x115] != (GameRecord)0x0) goto LAB_00180ed4;
  }
  pGVar19 = this + 0x40;
  Status::setCurrentCampaignMission(Globals::status,*(int *)pGVar19);
  this[0x102] = (GameRecord)(0x2d < *(int *)pGVar19);
  this[0x119] = (GameRecord)(0x55 < *(int *)pGVar19);
  Status::setFreelanceMission(Globals::status,*(Mission **)(this + 0x54));
  Status::setCampaignMission(Globals::status,*(Mission **)(this + 0x58));
  Status::setStationStack(Globals::status,*(Array **)(this + 0x5c));
  iVar4 = *(int *)pGVar19;
  if (iVar4 == 0x23) {
    iVar4 = Mission::getTargetStation(*(Mission **)(this + 0x58));
    pSVar10 = Globals::status;
    if (iVar4 != 0x1d) {
      pMVar5 = operator_new(100);
      Mission::Mission(pMVar5,0xb,0,0x1d);
      Status::setCampaignMission(pSVar10,pMVar5);
    }
    iVar4 = *(int *)pGVar19;
  }
  if (iVar4 == 0x1d) {
    *(undefined4 *)(this + 0x44) = 0x5b;
    *(undefined4 *)(this + 0x48) = 0x12;
    Status::setCurrentCampaignMission(Globals::status,0x1c);
    pSVar10 = Globals::status;
    pMVar5 = operator_new(100);
    Mission::Mission(pMVar5,4,0,0x5b);
    Status::setCampaignMission(pSVar10,pMVar5);
    iVar4 = *(int *)pGVar19;
  }
  if (iVar4 == 0x19) {
    *(undefined4 *)(this + 0x44) = 0x30;
    *(undefined4 *)(this + 0x48) = 9;
    Status::setCurrentCampaignMission(Globals::status,0x18);
    pSVar10 = Globals::status;
    pMVar5 = operator_new(100);
    Mission::Mission(pMVar5,4,0,0x30);
    Status::setCampaignMission(pSVar10,pMVar5);
    iVar4 = *(int *)pGVar19;
  }
  if (iVar4 == 0x29) {
    Status::setCurrentCampaignMission(Globals::status,0x27);
    pSVar10 = Globals::status;
    pMVar5 = operator_new(100);
    Mission::Mission(pMVar5,0xb,0,0x1e);
    Status::setCampaignMission(pSVar10,pMVar5);
  }
  if ((((this[0x117] != (GameRecord)0x0) || (this[0x118] != (GameRecord)0x0)) &&
      (*(int *)pGVar19 == 0x56)) &&
     (iVar4 = Mission::getTargetStation(*(Mission **)(this + 0x58)), pSVar10 = Globals::status,
     iVar4 != 100)) {
    Globals::hints[0x31] = (GameRecord)0x1;
    pMVar5 = operator_new(100);
    Mission::Mission(pMVar5,0xb,0,100);
    Status::setCampaignMission(pSVar10,pMVar5);
  }
  if (((this[0x117] != (GameRecord)0x0) || (this[0x118] != (GameRecord)0x0)) &&
     ((*(int *)pGVar19 == 0x57 &&
      (iVar4 = Mission::getTargetStation(*(Mission **)(this + 0x58)), pSVar10 = Globals::status,
      iVar4 != 10)))) {
    Globals::hints[0x31] = (GameRecord)0x1;
    pMVar5 = operator_new(100);
    Mission::Mission(pMVar5,4,0,10);
    Status::setCampaignMission(pSVar10,pMVar5);
  }
  if (((this[0x117] != (GameRecord)0x0) || (this[0x118] != (GameRecord)0x0)) &&
     ((*(int *)pGVar19 == 0x58 &&
      (iVar4 = Mission::getTargetStation(*(Mission **)(this + 0x58)), pSVar10 = Globals::status,
      iVar4 != 10)))) {
    Globals::hints[0x31] = (GameRecord)0x1;
    pMVar5 = operator_new(100);
    Mission::Mission(pMVar5,0xb,0,10);
    Status::setCampaignMission(pSVar10,pMVar5);
  }
  if ((((this[0x117] != (GameRecord)0x0) || (this[0x118] != (GameRecord)0x0)) &&
      (*(int *)pGVar19 == 0x59)) &&
     (iVar4 = Mission::getTargetStation(*(Mission **)(this + 0x58)), iVar4 != 10)) {
    Globals::hints[0x31] = (GameRecord)0x1;
    Status::setCurrentCampaignMission(Globals::status,0x56);
    pSVar10 = Globals::status;
    pMVar5 = operator_new(100);
    Mission::Mission(pMVar5,0xb,0,100);
    Status::setCampaignMission(pSVar10,pMVar5);
  }
  if ((this[0x117] != (GameRecord)0x0) || (this[0x118] != (GameRecord)0x0)) {
    iVar4 = *(int *)pGVar19;
    if (iVar4 == 0x5b) {
      iVar4 = Mission::getTargetStation(*(Mission **)(this + 0x58));
      if (iVar4 == 0x6e) {
        iVar4 = *(int *)pGVar19;
        goto LAB_0018119a;
      }
    }
    else {
LAB_0018119a:
      if ((0xc < iVar4 - 0x5bU) || (*(char *)(*(int *)(*(int *)(this + 0x160) + 4) + 0x1b) != '\0'))
      goto LAB_001811ea;
    }
    Globals::hints[0x31] = (GameRecord)0x1;
    *(undefined4 *)pGVar19 = 0x56;
    Status::setCurrentCampaignMission(Globals::status,0x56);
    pSVar10 = Globals::status;
    pMVar5 = operator_new(100);
    Mission::Mission(pMVar5,0xb,0,100);
    Status::setCampaignMission(pSVar10,pMVar5);
  }
LAB_001811ea:
  Station::setItems(*(Station **)(Globals::status + 0x14c),*(Array **)(this + 0x180),true);
  Station::setShips(*(Station **)(Globals::status + 0x14c),*(Array **)(this + 0x184),true);
  pvVar16 = *(void **)(Globals::status + 0x94);
  if (pvVar16 != (void *)0x0) {
    if (*(void **)((int)pvVar16 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar16 + 4));
    }
    operator_delete(pvVar16);
  }
  pSVar10 = Globals::status;
  *(undefined4 *)(Globals::status + 0x94) = *(undefined4 *)(this + 0x68);
  pvVar16 = *(void **)(pSVar10 + 0x98);
  if (pvVar16 != (void *)0x0) {
    if (*(void **)((int)pvVar16 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar16 + 4));
    }
    operator_delete(pvVar16);
    pSVar10 = Globals::status;
  }
  *(undefined4 *)(pSVar10 + 0x98) = *(undefined4 *)(this + 0x6c);
  pvVar16 = *(void **)(pSVar10 + 0x90);
  if (pvVar16 != (void *)0x0) {
    if (*(void **)((int)pvVar16 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar16 + 4));
    }
    operator_delete(pvVar16);
    pSVar10 = Globals::status;
  }
  *(undefined4 *)(pSVar10 + 0x90) = *(undefined4 *)(this + 0x70);
  *(undefined4 *)(pSVar10 + 0x10c) = *(undefined4 *)(this + 0xd0);
  pSVar10[0x110] = *(Status *)(this + 0xd4);
  pSVar10[0x111] = *(Status *)(this + 0xdc);
  if (Globals::options[0x36] == '\0') {
    uVar12 = *(undefined4 *)(this + 0xd8);
  }
  else {
    uVar12 = 3;
  }
  *(undefined4 *)(pSVar10 + 0x114) = uVar12;
  uVar20 = *(undefined8 *)(this + 0x7c);
  *(undefined8 *)(pSVar10 + 0x9c) = *(undefined8 *)(this + 0x74);
  *(undefined8 *)(pSVar10 + 0xa4) = uVar20;
  pvVar16 = *(void **)(pSVar10 + 0xac);
  if (pvVar16 != (void *)0x0) {
    if (*(void **)((int)pvVar16 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar16 + 4));
    }
    operator_delete(pvVar16);
    pSVar10 = Globals::status;
  }
  *(undefined4 *)(pSVar10 + 0xac) = *(undefined4 *)(this + 0x84);
  *(undefined4 *)(pSVar10 + 0xb0) = *(undefined4 *)(this + 0x88);
  uVar13 = **(uint **)(this + 0x8c);
  if (uVar13 != 0) {
    uVar17 = 0;
    uVar14 = (*(uint **)(this + 0x8c))[1];
    iVar4 = *(int *)(*(int *)(pSVar10 + 0xb4) + 4);
    do {
      *(undefined1 *)(iVar4 + uVar17) = *(undefined1 *)(uVar14 + uVar17);
      uVar17 = uVar17 + 1;
    } while (uVar17 < uVar13);
  }
  *(undefined4 *)(pSVar10 + 0xb8) = *(undefined4 *)(this + 0x90);
  uVar12 = *(undefined4 *)(this + 0x9c);
  *(undefined4 *)(pSVar10 + 0xc0) = *(undefined4 *)(this + 0x98);
  *(undefined4 *)(pSVar10 + 0xc4) = uVar12;
  uVar20 = *(undefined8 *)(this + 0xa8);
  *(undefined8 *)(pSVar10 + 200) = *(undefined8 *)(this + 0xa0);
  *(undefined8 *)(pSVar10 + 0xd0) = uVar20;
  uVar20 = *(undefined8 *)(this + 0xb8);
  *(undefined8 *)(pSVar10 + 0xd8) = *(undefined8 *)(this + 0xb0);
  *(undefined8 *)(pSVar10 + 0xe0) = uVar20;
  *(undefined4 *)(pSVar10 + 0xe8) = *(undefined4 *)(this + 0xc0);
  *(undefined4 *)(pSVar10 + 0xec) = *(undefined4 *)(this + 0xc4);
  Achievements::init(Globals::achievements);
  if (*(int **)(this + 0x60) != (int *)0x0) {
    Achievements::setMedals(Globals::achievements,*(int **)(this + 0x60),*(int *)(this + 100));
  }
  Status::setShip(Globals::status,*(Ship **)(this + 0x130));
  iVar4 = Status::dlc1Won(Globals::status);
  if (iVar4 == 1) {
    pSVar6 = (Ship *)Status::getShip(Globals::status);
    pIVar7 = (Item *)Ship::getFirstEquipmentOfSort(pSVar6,0x12);
    if (pIVar7 == (Item *)0x0) {
      pSVar6 = (Ship *)Status::getShip(Globals::status);
      pIVar7 = (Item *)Ship::getCargo(pSVar6,0x55);
      if (pIVar7 == (Item *)0x0) goto LAB_001813c6;
    }
    Item::setUnsaleable(pIVar7,false);
  }
LAB_001813c6:
  iVar4 = Status::gameWon(Globals::status);
  if (iVar4 == 1) {
    pSVar6 = (Ship *)Status::getShip(Globals::status);
    puVar8 = (uint *)Ship::getCargo(pSVar6);
    if ((puVar8 != (uint *)0x0) && (*puVar8 != 0)) {
      uVar13 = 0;
      do {
        pIVar7 = *(Item **)(puVar8[1] + uVar13 * 4);
        if ((pIVar7 != (Item *)0x0) && (iVar4 = Item::getIndex(pIVar7), iVar4 == 0x83)) {
          Item::setUnsaleable(*(Item **)(puVar8[1] + uVar13 * 4),false);
        }
        uVar13 = uVar13 + 1;
      } while (uVar13 < *puVar8);
    }
  }
  if (0x79 < *(int *)pGVar19) {
    pSVar6 = (Ship *)Status::getShip(Globals::status);
    puVar8 = (uint *)Ship::getCargo(pSVar6);
    if ((puVar8 != (uint *)0x0) && (*puVar8 != 0)) {
      uVar13 = 0;
      do {
        pIVar7 = *(Item **)(puVar8[1] + uVar13 * 4);
        if ((pIVar7 != (Item *)0x0) && (iVar4 = Item::getIndex(pIVar7), iVar4 == 0xd1)) {
          Item::setUnsaleable(*(Item **)(puVar8[1] + uVar13 * 4),false);
        }
        uVar13 = uVar13 + 1;
      } while (uVar13 < *puVar8);
    }
  }
  puVar8 = *(uint **)(this + 0x140);
  if ((puVar8 != (uint *)0x0) && (*puVar8 != 0)) {
    uVar13 = 0;
    do {
      this_00 = *(BluePrint **)(puVar8[1] + uVar13 * 4);
      if ((this_00 != (BluePrint *)0x0) &&
         (((iVar4 = BluePrint::getIndex(this_00), iVar4 == 0xdf ||
           (iVar4 = BluePrint::getIndex(*(BluePrint **)
                                         (*(int *)(*(int *)(this + 0x140) + 4) + uVar13 * 4)),
           iVar4 == 0xd2)) &&
          (iVar4 = BluePrint::isEmpty(*(BluePrint **)
                                       (*(int *)(*(int *)(this + 0x140) + 4) + uVar13 * 4)),
          pGVar3 = Globals::galaxy, iVar4 == 0)))) {
        iVar4 = BluePrint::getStationIndex
                          (*(BluePrint **)(*(int *)(*(int *)(this + 0x140) + 4) + uVar13 * 4));
        pSVar9 = (Station *)Galaxy::getStation(pGVar3,iVar4);
        pGVar3 = Globals::galaxy;
        if (pSVar9 != (Station *)0x0) {
          iVar4 = Station::getSystem(pSVar9);
          this_01 = (SolarSystem *)Galaxy::getSystem(pGVar3,iVar4);
          iVar4 = SolarSystem::getRoutes(this_01);
          if (iVar4 == 0) {
            *(undefined4 *)(*(int *)(*(int *)(*(int *)(this + 0x140) + 4) + uVar13 * 4) + 0x10) = 10
            ;
            pvVar16 = (void *)Station::~Station(pSVar9);
            operator_delete(pvVar16);
            pSVar9 = (Station *)Galaxy::getStation(Globals::galaxy,10);
            iVar4 = *(int *)(*(int *)(*(int *)(this + 0x140) + 4) + uVar13 * 4);
            Station::getName();
            AbyssEngine::String::operator=((String *)(iVar4 + 0x14),aSStack_30);
            AbyssEngine::String::~String(aSStack_30);
            if (pSVar9 == (Station *)0x0) goto LAB_00181550;
          }
          pvVar16 = (void *)Station::~Station(pSVar9);
          operator_delete(pvVar16);
        }
      }
LAB_00181550:
      puVar8 = *(uint **)(this + 0x140);
      uVar13 = uVar13 + 1;
    } while (uVar13 < *puVar8);
  }
  pSVar10 = Globals::status;
  *(undefined4 *)(Globals::status + 0x8c) = *(undefined4 *)(this + 0x134);
  Status::setStation(pSVar10,*(Station **)(this + 0x138));
  Status::setMission(Globals::status,Mission::empty);
  pSVar10 = Globals::status;
  *(undefined4 *)(Globals::status + 0x14) = *(undefined4 *)(this + 0x13c);
  puVar8 = *(uint **)(this + 0x140);
  if (*puVar8 != 0) {
    uVar13 = 0;
    do {
      *(undefined4 *)(*(int *)(*(int *)(pSVar10 + 0x18) + 4) + uVar13 * 4) =
           *(undefined4 *)(puVar8[1] + uVar13 * 4);
      uVar13 = uVar13 + 1;
      puVar8 = *(uint **)(this + 0x140);
      pSVar10 = Globals::status;
    } while (uVar13 < *puVar8);
  }
  *(undefined4 *)(pSVar10 + 0x1c) = *(undefined4 *)(this + 0x144);
  puVar8 = *(uint **)(this + 0x148);
  if (*puVar8 != 0) {
    uVar13 = 0;
    do {
      *(undefined4 *)(*(int *)(*(int *)(pSVar10 + 0x20) + 4) + uVar13 * 4) =
           *(undefined4 *)(puVar8[1] + uVar13 * 4);
      uVar13 = uVar13 + 1;
      puVar8 = *(uint **)(this + 0x148);
      pSVar10 = Globals::status;
    } while (uVar13 < *puVar8);
  }
  *(undefined4 *)(pSVar10 + 0x24) = *(undefined4 *)(this + 0x14c);
  *(undefined4 *)(pSVar10 + 0x2c) = *(undefined4 *)(this + 0x150);
  *(undefined4 *)(pSVar10 + 0x30) = *(undefined4 *)(this + 0x154);
  *(undefined4 *)(pSVar10 + 0x28) = *(undefined4 *)(this + 0x158);
  *(undefined4 *)(pSVar10 + 0x34) = *(undefined4 *)(this + 0x15c);
  uVar13 = **(uint **)(this + 0x160);
  if (uVar13 != 0) {
    uVar17 = 0;
    uVar14 = (*(uint **)(this + 0x160))[1];
    iVar4 = *(int *)(*(int *)(pSVar10 + 0x38) + 4);
    do {
      *(undefined1 *)(iVar4 + uVar17) = *(undefined1 *)(uVar14 + uVar17);
      uVar17 = uVar17 + 1;
    } while (uVar17 < uVar13);
  }
  iVar4 = *(int *)(*(int *)(pSVar10 + 0x38) + 4);
  if (Globals::options[0x35] != '\0') {
    *(undefined1 *)(iVar4 + 0x19) = 1;
  }
  *(undefined1 *)(iVar4 + 0x1a) = 1;
  puVar8 = *(uint **)(this + 0x164);
  if (*puVar8 != 0) {
    uVar14 = 0;
    uVar13 = puVar8[1];
    iVar4 = *(int *)(*(int *)(pSVar10 + 0x3c) + 4);
    do {
      *(undefined4 *)(iVar4 + uVar14 * 4) = *(undefined4 *)(uVar13 + uVar14 * 4);
      uVar14 = uVar14 + 1;
    } while (uVar14 < *puVar8);
  }
  puVar8 = *(uint **)(this + 0x168);
  if (*puVar8 != 0) {
    uVar14 = 0;
    uVar13 = puVar8[1];
    iVar4 = *(int *)(*(int *)(pSVar10 + 0x40) + 4);
    do {
      *(undefined4 *)(iVar4 + uVar14 * 4) = *(undefined4 *)(uVar13 + uVar14 * 4);
      uVar14 = uVar14 + 1;
    } while (uVar14 < *puVar8);
  }
  puVar8 = *(uint **)(this + 0x16c);
  if (*puVar8 != 0) {
    uVar14 = 0;
    uVar13 = puVar8[1];
    iVar4 = *(int *)(*(int *)(pSVar10 + 0x44) + 4);
    do {
      *(undefined4 *)(iVar4 + uVar14 * 4) = *(undefined4 *)(uVar13 + uVar14 * 4);
      uVar14 = uVar14 + 1;
    } while (uVar14 < *puVar8);
  }
  puVar8 = *(uint **)(this + 0x170);
  if (*puVar8 != 0) {
    uVar14 = 0;
    uVar13 = puVar8[1];
    iVar4 = *(int *)(*(int *)(pSVar10 + 0x48) + 4);
    do {
      *(undefined4 *)(iVar4 + uVar14 * 4) = *(undefined4 *)(uVar13 + uVar14 * 4);
      uVar14 = uVar14 + 1;
    } while (uVar14 < *puVar8);
  }
  *(undefined4 *)(pSVar10 + 0x4c) = *(undefined4 *)(this + 0x174);
  uVar13 = **(uint **)(this + 0x178);
  if ((**(uint **)(pSVar10 + 0x54) <= uVar13) && (uVar13 != 0)) {
    uVar14 = (*(uint **)(this + 0x178))[1];
    uVar15 = 0;
    uVar17 = (*(uint **)(pSVar10 + 0x54))[1];
    do {
      *(undefined1 *)(uVar17 + uVar15) = *(undefined1 *)(uVar14 + uVar15);
      uVar15 = uVar15 + 1;
    } while (uVar15 < uVar13);
  }
  pSVar10 = Globals::status;
  uVar12 = *(undefined4 *)(this + 0xe4);
  Globals::hints[8] = (undefined1)uVar12;
  Globals::hints[9] = (undefined1)((uint)uVar12 >> 8);
  Globals::hints[10] = (undefined1)((uint)uVar12 >> 0x10);
  Globals::hints[0xb] = (undefined1)((uint)uVar12 >> 0x18);
  uVar12 = *(undefined4 *)(this + 0xe8);
  Globals::hints[0xc] = (undefined1)uVar12;
  Globals::hints[0xd] = (undefined1)((uint)uVar12 >> 8);
  Globals::hints[0xe] = (undefined1)((uint)uVar12 >> 0x10);
  Globals::hints[0xf] = (undefined1)((uint)uVar12 >> 0x18);
  uVar12 = *(undefined4 *)(this + 0xec);
  Globals::hints[0x10] = (undefined1)uVar12;
  Globals::hints[0x11] = (undefined1)((uint)uVar12 >> 8);
  Globals::hints[0x12] = (undefined1)((uint)uVar12 >> 0x10);
  Globals::hints[0x13] = (undefined1)((uint)uVar12 >> 0x18);
  uVar12 = *(undefined4 *)(this + 0xf0);
  Globals::hints[0x14] = (undefined1)uVar12;
  Globals::hints[0x15] = (undefined1)((uint)uVar12 >> 8);
  Globals::hints[0x16] = (undefined1)((uint)uVar12 >> 0x10);
  Globals::hints[0x17] = (undefined1)((uint)uVar12 >> 0x18);
  uVar12 = *(undefined4 *)(this + 0xf4);
  Globals::hints[0x18] = (undefined1)uVar12;
  Globals::hints[0x19] = (undefined1)((uint)uVar12 >> 8);
  Globals::hints[0x1a] = (undefined1)((uint)uVar12 >> 0x10);
  Globals::hints[0x1b] = (undefined1)((uint)uVar12 >> 0x18);
  uVar12 = *(undefined4 *)(this + 0xf8);
  Globals::hints[0x1c] = (undefined1)uVar12;
  Globals::hints[0x1d] = (undefined1)((uint)uVar12 >> 8);
  Globals::hints[0x1e] = (undefined1)((uint)uVar12 >> 0x10);
  Globals::hints[0x1f] = (undefined1)((uint)uVar12 >> 0x18);
  uVar12 = *(undefined4 *)(this + 0xfc);
  Globals::hints[0x20] = (undefined1)uVar12;
  Globals::hints[0x21] = (undefined1)((uint)uVar12 >> 8);
  Globals::hints[0x22] = (undefined1)((uint)uVar12 >> 0x10);
  Globals::hints[0x23] = (undefined1)((uint)uVar12 >> 0x18);
  uVar18 = *(undefined4 *)(this + 0x100);
  Globals::hints[0x24] = (undefined1)uVar18;
  Globals::options._44_4_ = *(undefined4 *)(this + 0x11c);
  uVar12 = *(undefined4 *)(this + 0xcc);
  *(undefined4 *)(Globals::status + 0x100) = *(undefined4 *)(this + 200);
  *(undefined4 *)(pSVar10 + 0x104) = uVar12;
  Globals::hints[0x25] = (undefined1)((uint)uVar18 >> 8);
  Globals::hints[0x26] = (undefined1)((uint)uVar18 >> 0x10);
  Globals::hints[0x27] = (undefined1)((uint)uVar18 >> 0x18);
  if (*(int *)(this + 0x1b4) == 0x6e6a78) {
    Globals::hints[0x29] = this[0x105];
    uVar12 = *(undefined4 *)(this + 0x104);
    Globals::hints[0x28] = (undefined1)uVar12;
    Globals::hints[0x2a] = (undefined1)((uint)uVar12 >> 0x10);
    Globals::hints[0x2b] = (undefined1)((uint)uVar12 >> 0x18);
    uVar12 = *(undefined4 *)(this + 0x108);
    Globals::hints[0x2c] = (undefined1)uVar12;
    Globals::hints[0x2d] = (undefined1)((uint)uVar12 >> 8);
    Globals::hints[0x2e] = (undefined1)((uint)uVar12 >> 0x10);
    Globals::hints[0x2f] = (undefined1)((uint)uVar12 >> 0x18);
    uVar12 = *(undefined4 *)(this + 0x10c);
    Globals::hints[0x30] = (undefined1)uVar12;
    *(undefined4 *)(pSVar10 + 0x174) = *(undefined4 *)(this + 0x1b0);
    pSVar10 = Globals::status;
    Globals::hints[0x31] = this[0x119];
    Globals::hints[0x32] = this[0x11a];
    Globals::hints[0x33] = (undefined1)((uint)uVar12 >> 8);
    Globals::hints[0x34] = (undefined1)((uint)uVar12 >> 0x10);
    Globals::hints[0x35] = (undefined1)((uint)uVar12 >> 0x18);
    uVar12 = *(undefined4 *)(this + 0x110);
    Globals::hints[0x36] = (undefined1)uVar12;
    Globals::hints[0x37] = (undefined1)((uint)uVar12 >> 8);
    Globals::hints[0x38] = (undefined1)((uint)uVar12 >> 0x18);
    Globals::hints[0x39] = (undefined1)((uint)uVar12 >> 0x10);
    Globals::hints[0x3a] = this[0x114];
    *(undefined4 *)(Globals::status + 0x58) = *(undefined4 *)(this + 0x17c);
    puVar8 = *(uint **)(this + 0x1ac);
    if ((puVar8 != (uint *)0x0) && (*puVar8 != 0)) {
      uVar13 = 0;
      do {
        *(undefined4 *)(*(int *)(*(int *)pSVar10 + 4) + uVar13 * 4) =
             *(undefined4 *)(puVar8[1] + uVar13 * 4);
        uVar13 = uVar13 + 1;
        puVar8 = *(uint **)(this + 0x1ac);
        pSVar10 = Globals::status;
      } while (uVar13 < *puVar8);
    }
    iVar4 = 0;
    do {
      iVar1 = iVar4 * 4;
      iVar2 = iVar4 * 4;
      iVar4 = iVar4 + 1;
      *(undefined4 *)(pSVar10 + iVar2 + 4) = *(undefined4 *)(this + iVar1 + 0x19c);
    } while (iVar4 != 4);
    pSVar9 = (Station *)Status::getStation(pSVar10);
    iVar4 = Station::getIndex(pSVar9);
    if (iVar4 == 0x6c) {
      pSVar9 = (Station *)Status::getStation(Globals::status);
      puVar8 = (uint *)Station::getShips(pSVar9);
      uVar13 = 0;
      if (puVar8 != (uint *)0x0) {
        uVar13 = *puVar8;
      }
      if (puVar8 != (uint *)0x0 && uVar13 != 0) {
        uVar13 = 0;
        do {
          puVar11 = (uint *)Ship::getMods(*(Ship **)(*(int *)(*(int *)(this + 0x184) + 4) +
                                                    uVar13 * 4));
          uVar14 = 0;
          if (puVar11 != (uint *)0x0) {
            uVar14 = *puVar11;
          }
          if (puVar11 != (uint *)0x0 && uVar14 != 0) {
            uVar14 = 0;
            do {
              Ship::addMod(*(Ship **)(puVar8[1] + uVar13 * 4),*(int *)(puVar11[1] + uVar14 * 4));
              uVar14 = uVar14 + 1;
            } while (uVar14 < *puVar11);
          }
          uVar13 = uVar13 + 1;
        } while (uVar13 < *puVar8);
      }
    }
    pSVar10 = Globals::status;
    *(undefined4 *)(Globals::status + 0x118) = *(undefined4 *)(this + 0xe0);
    pSVar10[0x178] = *(Status *)(this + 0x1b8);
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

