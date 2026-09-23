// Class: MGame
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== MGame::MGame  @0x001a6d98  (214 bytes)
/* MGame::MGame() */

MGame * __thiscall MGame::MGame(MGame *this)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  *(undefined ***)this = &PTR__MGame_00264a48;
  AbyssEngine::String::String((String *)(this + 100));
  uVar1 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0xe0) = 0;
  *(undefined4 *)(this + 0xe4) = 0;
  *(undefined4 *)(this + 0xe8) = 0;
  *(undefined4 *)(this + 0x1b4) = 0;
  *(undefined4 *)(this + 0x1b8) = 0;
  *(undefined4 *)(this + 0x1bc) = 0;
  *(undefined4 *)(this + 0xa0) = 0;
  *(undefined4 *)(this + 0xa4) = uVar1;
  *(undefined4 *)(this + 0xa8) = uVar2;
  *(undefined4 *)(this + 0xac) = uVar3;
  *(undefined4 *)(this + 0xb0) = 0;
  *(undefined4 *)(this + 0xb4) = 0;
  *(undefined4 *)(this + 0x134) = 0;
  *(undefined4 *)(this + 0x138) = uVar1;
  *(undefined4 *)(this + 0x13c) = uVar2;
  *(undefined4 *)(this + 0x140) = uVar3;
  *(undefined4 *)(this + 0x144) = 0;
  *(undefined4 *)(this + 0x148) = 0;
  *(undefined4 *)(this + 0x184) = 0;
  *(undefined4 *)(this + 0x188) = uVar1;
  *(undefined4 *)(this + 0x18c) = uVar2;
  *(undefined4 *)(this + 400) = uVar3;
  *(undefined4 *)(this + 0x194) = 0;
  *(undefined4 *)(this + 0x198) = 0;
  *(undefined4 *)(this + 0xc) = 100;
  *(undefined4 *)(this + 0x10) = 0xffffffff;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  this[0x54] = (MGame)0x0;
  this[0x19e] = (MGame)0x0;
  this[0xd1] = (MGame)0x0;
  this[0xd2] = (MGame)0x0;
  *(undefined4 *)(this + 0x10c) = 0;
  *(undefined4 *)(this + 0xf0) = 0;
  this[0x1dc] = (MGame)0x0;
  *(undefined4 *)(this + 0x1cc) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = uVar1;
  *(undefined4 *)(this + 0x38) = uVar2;
  *(undefined4 *)(this + 0x3c) = uVar3;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = uVar1;
  *(undefined4 *)(this + 0x28) = uVar2;
  *(undefined4 *)(this + 0x2c) = uVar3;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined2 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x80) = uVar1;
  *(undefined4 *)(this + 0x84) = uVar2;
  *(undefined4 *)(this + 0x88) = uVar3;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x70) = uVar1;
  *(undefined4 *)(this + 0x74) = uVar2;
  *(undefined4 *)(this + 0x78) = uVar3;
  *(undefined4 *)(this + 0x8c) = 0;
  *(undefined4 *)(this + 0x90) = 0;
  this[0xc4] = (MGame)0x0;
  *(undefined4 *)(this + 0xc0) = 0;
  *(undefined2 *)(this + 0xca) = 0;
  *(undefined4 *)(this + 0xc6) = 0;
  *(undefined4 *)(this + 0xd4) = 0;
  *(undefined4 *)(this + 0xd8) = 0;
  *(undefined4 *)(this + 0x1d0) = 0x42c80000;
  *(undefined4 *)(this + 0x1d8) = 0;
  return this;
}

// ===== MGame::~MGame  @0x001a6e74  (34 bytes)
/* MGame::~MGame() */

MGame * __thiscall MGame::~MGame(MGame *this)

{
  *(undefined ***)this = &PTR__MGame_00264a48;
  OnRelease(this);
  AbyssEngine::String::~String((String *)(this + 100));
  return this;
}

// ===== MGame::~MGame  @0x001a6eac  (16 bytes)
/* MGame::~MGame() */

void __thiscall MGame::~MGame(MGame *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~MGame(this);
  operator_delete(pvVar1);
  return;
}

// ===== MGame::OnInitialize  @0x001a6ebc  (2394 bytes)
/* MGame::OnInitialize() */

void __thiscall MGame::OnInitialize(MGame *this)

{
  Status *pSVar1;
  Globals *this_00;
  short sVar2;
  int iVar3;
  SolarSystem *pSVar4;
  Ship *pSVar5;
  undefined4 uVar6;
  Station *pSVar7;
  int iVar8;
  float fVar9;
  uint uVar10;
  Item *pIVar11;
  uint *puVar12;
  uint uVar13;
  Mission *pMVar14;
  Mission *this_01;
  PlayerEgo *pPVar15;
  Hud *this_02;
  StarSystem *this_03;
  Engine *this_04;
  MenuTouchWindow *this_05;
  undefined4 *puVar16;
  undefined4 *puVar17;
  String *pSVar18;
  ushort uVar19;
  uint uVar20;
  Level *pLVar21;
  PaintCanvas *this_06;
  ulonglong in_d16;
  ulonglong in_d17;
  uint local_2c [3];
  int local_20;
  
  local_20 = __stack_chk_guard;
  *(undefined4 *)(this + 0xc) = 100;
  this[0x1d4] = (MGame)0x0;
  pLVar21 = *(Level **)(this + 0x74);
  if (pLVar21 == (Level *)0x0) {
    iVar3 = Status::inAlienOrbit(Globals::status);
    this_06 = *(PaintCanvas **)(this + 4);
    if (iVar3 == 1) {
      uVar19 = 0x2f08;
    }
    else {
      pSVar4 = (SolarSystem *)Status::getSystem(Globals::status);
      sVar2 = SolarSystem::getTextureIndex(pSVar4);
      uVar19 = sVar2 + 0x2efe;
    }
    AbyssEngine::PaintCanvas::TextureCreate(this_06,uVar19,local_2c,false);
    AbyssEngine::PaintCanvas::ChangeCubeTexture(*(PaintCanvas **)(this + 4),local_2c[0]);
    Globals::startNewSoundResourceList(Globals::globals);
    Globals::addSoundResourceToList(Globals::globals,0x66);
    Globals::addSoundResourceToList(Globals::globals,0x68);
    Globals::addSoundResourceToList(Globals::globals,0x69);
    Globals::addSoundResourceToList(Globals::globals,0x6a);
    Globals::addSoundResourceToList(Globals::globals,0x6b);
    Globals::addSoundResourceToList(Globals::globals,0x67);
    Globals::addSoundResourceToList(Globals::globals,0x7e);
    Globals::addSoundResourceToList(Globals::globals,5);
    Globals::addSoundResourceToList(Globals::globals,0x18);
    Globals::addSoundResourceToList(Globals::globals,0x15);
    Globals::addSoundResourceToList(Globals::globals,0x12);
    Globals::addSoundResourceToList(Globals::globals,0x13);
    Globals::addSoundResourceToList(Globals::globals,0x14);
    Globals::addSoundResourceToList(Globals::globals,0x1c);
    Globals::addSoundResourceToList(Globals::globals,0x1d);
    Globals::addSoundResourceToList(Globals::globals,0x1b);
    Globals::addSoundResourceToList(Globals::globals,0x25);
    Globals::addSoundResourceToList(Globals::globals,0x1a);
    Globals::addSoundResourceToList(Globals::globals,0x2e);
    Globals::addSoundResourceToList(Globals::globals,0x2f);
    iVar3 = Status::getWingmen(Globals::status);
    if (iVar3 != 0) {
      Globals::addSoundResourceToList(Globals::globals,0x30);
    }
    Globals::addSoundResourceToList(Globals::globals,0x3e);
    Globals::addSoundResourceToList(Globals::globals,0x3d);
    Globals::addSoundResourceToList(Globals::globals,0x24);
    iVar3 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar3 < 2) {
      Globals::addSoundResourceToList(Globals::globals,0x9c);
      Globals::addSoundResourceToList(Globals::globals,0x9d);
    }
    iVar3 = Status::inAlienOrbit(Globals::status);
    if (iVar3 == 0) {
      pSVar4 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar3 = SolarSystem::currentOrbitHasWarpGate(pSVar4);
      if (iVar3 == 1) {
        Globals::addSoundResourceToList(Globals::globals,0x1f);
      }
    }
    iVar3 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar3 == 0) {
      Globals::addSoundResourceToList(Globals::globals,0x8f);
      Globals::addSoundResourceToList(Globals::globals,0x9d);
      Globals::addSoundResourceToList(Globals::globals,0x9e);
      Globals::addSoundResourceToList(Globals::globals,0xa1);
      Globals::addSoundResourceToList(Globals::globals,0xa0);
      iVar3 = 0x9f;
LAB_001a7122:
      Globals::addSoundResourceToList(Globals::globals,iVar3);
    }
    else {
      iVar3 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar3 == 0xe) {
        iVar3 = 0xf;
        goto LAB_001a7122;
      }
      iVar3 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar3 == 0x18) {
        iVar3 = 0x22;
        goto LAB_001a7122;
      }
      iVar3 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar3 == 0x1d) {
        iVar3 = 0xe;
        goto LAB_001a7122;
      }
      iVar3 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar3 == 0x29) {
        Globals::addSoundResourceToList(Globals::globals,0x9b);
        Globals::addSoundResourceToList(Globals::globals,0x99);
        iVar3 = 0x9a;
        goto LAB_001a7122;
      }
    }
    Status::checkForLevelUp(Globals::status);
    pLVar21 = operator_new(0x2a0);
    Level::Level(pLVar21,3);
    *(Level **)(this + 0x74) = pLVar21;
  }
  iVar3 = Level::init(pLVar21);
  if (iVar3 != 1) goto LAB_001a77ce;
  reset(this);
  if (-1 < *(int *)(Globals::status + 100)) {
    Player::setHitpoints((Player *)**(undefined4 **)(this + 0x58),*(int *)(Globals::status + 100));
  }
  if (-1 < *(int *)(Globals::status + 0x5c)) {
    Player::setShieldHP((Player *)**(undefined4 **)(this + 0x58),*(int *)(Globals::status + 0x5c));
  }
  if (-1 < *(int *)(Globals::status + 0x60)) {
    Player::setArmorHP((Player *)**(undefined4 **)(this + 0x58),*(int *)(Globals::status + 0x60));
  }
  if (-1 < *(int *)(Globals::status + 0x68)) {
    Player::setGammaHP((Player *)**(undefined4 **)(this + 0x58),*(int *)(Globals::status + 0x68));
  }
  PlayerEgo::resetLastHP(*(PlayerEgo **)(this + 0x58));
  iVar3 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar3 != 0x5f) {
    pSVar5 = (Ship *)Status::getShip(Globals::status);
    uVar6 = Ship::getMaxHP(pSVar5);
    pSVar1 = Globals::status;
    *(undefined4 *)(Globals::status + 100) = uVar6;
    pSVar5 = (Ship *)Status::getShip(pSVar1);
    uVar6 = Ship::getMaxShieldHP(pSVar5);
    pSVar1 = Globals::status;
    *(undefined4 *)(Globals::status + 0x5c) = uVar6;
    pSVar5 = (Ship *)Status::getShip(pSVar1);
    uVar6 = Ship::getMaxArmorHP(pSVar5);
    pSVar1 = Globals::status;
    *(undefined4 *)(Globals::status + 0x60) = uVar6;
    *(undefined4 *)(pSVar1 + 0x68) = 100;
    pSVar7 = (Station *)Status::getStation(pSVar1);
    iVar3 = Station::getIndex(pSVar7);
    iVar8 = Status::getCurrentCampaignMission(Globals::status);
    fVar9 = (float)Status::getGammaRayDamagePerSecond(pSVar1,iVar3,iVar8);
    if (fVar9 == 0.0) {
      Player::setGammaHP((Player *)**(undefined4 **)(this + 0x58),100);
    }
  }
  iVar3 = Status::inAlienOrbit(Globals::status);
  if (iVar3 == 0) {
    pSVar7 = (Station *)Status::getStation(Globals::status);
    uVar6 = Station::getIndex(pSVar7);
    *(undefined4 *)(Globals::status + 0x84) = uVar6;
  }
  uVar10 = AbyssEngine::ApplicationManager::GetCurrentTimeMillis(Globals::appManager);
  *(ulonglong *)(this + 0x20) = in_d16 & 0xffff0000ffff0000 | (ulonglong)uVar10 & 0xffff;
  *(ulonglong *)(this + 0x28) = in_d17 & 0xffff0000ffff0000 | (ulonglong)uVar10 & 0xffff;
  *(undefined4 *)(this + 0x164) = 0;
  *(undefined4 *)(this + 0x16c) = 0;
  iVar3 = Radar::hasScanner(*(Radar **)(this + 0x7c));
  pSVar1 = Globals::status;
  if (iVar3 == 1) {
    *(undefined4 *)(Globals::status + 0x11c) = 0;
  }
  *(undefined4 *)(pSVar1 + 0x134) = 0;
  *(undefined4 *)(pSVar1 + 300) = 0;
  *(undefined4 *)(pSVar1 + 0x13c) = 0;
  *(undefined4 *)(pSVar1 + 0x144) = 0;
  pSVar5 = (Ship *)Status::getShip(pSVar1);
  pIVar11 = (Item *)Ship::getFirstEquipmentOfSort(pSVar5,0x1a);
  if (pIVar11 != (Item *)0x0) {
    uVar6 = Item::getAttribute(pIVar11,0x2a);
    *(undefined4 *)(this + 0x16c) = uVar6;
    uVar6 = Item::getAttribute(pIVar11,0x2b);
    *(undefined4 *)(this + 0x168) = uVar6;
    Hud::setTimeExtender(*(Hud **)(this + 0x70),true,false,true,false);
  }
  iVar3 = Status::dlc1Won(Globals::status);
  if (((iVar3 == 1) && (iVar3 = Status::inAlienOrbit(Globals::status), iVar3 == 1)) &&
     (iVar3 = Status::getCurrentCampaignMission(Globals::status), iVar3 < 0x93)) {
    if ((*(int *)(this + 0x58) != 0) && (*(int *)(this + 0x80) != 0)) {
      *(int *)(*(int *)(this + 0x58) + 0x18) = *(int *)(this + 0x80);
    }
    Level::createRadioMessage(*(Level **)(this + 0x74),8,0);
  }
  iVar3 = Status::inBlackMarketSystem(Globals::status);
  pSVar1 = Globals::status;
  if (iVar3 == 1) {
    if ((*(int *)(this + 0x58) != 0) && (*(int *)(this + 0x80) != 0)) {
      *(int *)(*(int *)(this + 0x58) + 0x18) = *(int *)(this + 0x80);
    }
    if ((*(ushort *)(Globals::status + 0x110) & 0xff) == 0) {
      pLVar21 = *(Level **)(this + 0x74);
      if (*(ushort *)(Globals::status + 0x110) < 0x100) {
        puVar12 = (uint *)Level::getEnemies(pLVar21);
        if ((puVar12 != (uint *)0x0) && (uVar10 = *puVar12, uVar10 != 0)) {
          uVar13 = puVar12[1];
          uVar20 = 0;
          do {
            iVar3 = *(int *)(uVar13 + uVar20 * 4);
            uVar20 = uVar20 + 1;
            if (*(int *)(iVar3 + 0x24) == 8) {
              *(undefined1 *)(iVar3 + 0x21) = 0;
            }
          } while (uVar20 < uVar10);
        }
        pLVar21 = *(Level **)(this + 0x74);
        iVar3 = 9;
      }
      else {
        iVar3 = 0xd;
      }
      Level::createRadioMessage(pLVar21,iVar3,8);
    }
    else {
      puVar12 = (uint *)Level::getEnemies(*(Level **)(this + 0x74));
      if ((puVar12 != (uint *)0x0) && (uVar10 = *puVar12, uVar10 != 0)) {
        uVar13 = puVar12[1];
        uVar20 = 0;
        do {
          iVar3 = *(int *)(uVar13 + uVar20 * 4);
          uVar20 = uVar20 + 1;
          if (*(int *)(iVar3 + 0x24) == 8) {
            *(undefined1 *)(iVar3 + 0x21) = 0;
          }
        } while (uVar20 < uVar10);
      }
    }
  }
  else {
    Globals::status[0x110] = (Status)0x0;
    pSVar1[0x111] = (Status)0x0;
  }
  iVar3 = Status::inAlienOrbit(Globals::status);
  if ((iVar3 == 0) &&
     (iVar3 = Status::getCurrentCampaignMission(Globals::status), pSVar1 = Globals::status,
     iVar3 == 0x7d)) {
    pSVar7 = (Station *)Status::getStation(Globals::status);
    iVar3 = Station::getIndex(pSVar7);
    iVar3 = Status::isFreighterMissionStation(pSVar1,iVar3);
    if (iVar3 == 1) {
      pMVar14 = (Mission *)Status::getCampaignMission(Globals::status);
      uVar10 = Mission::getStatusValue(pMVar14);
      pSVar1 = Globals::status;
      pSVar7 = (Station *)Status::getStation(Globals::status);
      iVar3 = Station::getIndex(pSVar7);
      uVar13 = Status::getFreighterMissionStationBit(pSVar1,iVar3);
      if ((1 << (uVar13 & 0xff) & uVar10) == 0) {
        pMVar14 = (Mission *)Status::getCampaignMission(Globals::status);
        this_01 = (Mission *)Status::getCampaignMission(Globals::status);
        uVar10 = Mission::getStatusValue(this_01);
        pSVar1 = Globals::status;
        pSVar7 = (Station *)Status::getStation(Globals::status);
        iVar3 = Station::getIndex(pSVar7);
        uVar13 = Status::getFreighterMissionStationBit(pSVar1,iVar3);
        Mission::setStatusValue(pMVar14,1 << (uVar13 & 0xff) | uVar10);
        if ((*(int *)(this + 0x58) != 0) && (*(int *)(this + 0x80) != 0)) {
          *(int *)(*(int *)(this + 0x58) + 0x18) = *(int *)(this + 0x80);
        }
        Level::createRadioMessage(*(Level **)(this + 0x74),0x13,0);
      }
    }
  }
  pSVar5 = (Ship *)Status::getShip(Globals::status);
  puVar12 = (uint *)Ship::getEquipment(pSVar5,1);
  if (puVar12 != (uint *)0x0) {
    pSVar5 = (Ship *)Status::getShip(Globals::status);
    iVar3 = Ship::hasEquipment(pSVar5,*(int *)(Globals::status + 0xf4),1);
    if (iVar3 == 1) {
      uVar10 = *puVar12;
      if (uVar10 != 0) {
        uVar13 = 0;
        do {
          pIVar11 = *(Item **)(puVar12[1] + uVar13 * 4);
          if (pIVar11 != (Item *)0x0) {
            iVar3 = Item::getIndex(pIVar11);
            if (iVar3 == *(int *)(Globals::status + 0xf4)) {
              pPVar15 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x74));
              iVar3 = Item::getIndex(pIVar11);
              PlayerEgo::setCurrentSecondaryWeaponIndex(pPVar15,iVar3);
              this_02 = *(Hud **)(this + 0x70);
              goto LAB_001a7582;
            }
            uVar10 = *puVar12;
          }
          uVar13 = uVar13 + 1;
        } while (uVar13 < uVar10);
      }
    }
    else if (*(Item **)puVar12[1] != (Item *)0x0) {
      pPVar15 = *(PlayerEgo **)(this + 0x58);
      iVar3 = Item::getIndex(*(Item **)puVar12[1]);
      PlayerEgo::setCurrentSecondaryWeaponIndex(pPVar15,iVar3);
      this_02 = *(Hud **)(this + 0x70);
      pIVar11 = *(Item **)puVar12[1];
LAB_001a7582:
      Hud::setCurrentSecondaryWeapon(this_02,pIVar11);
    }
  }
  *(undefined2 *)(this + 0x19c) = 0;
  if (Globals::options[0xf] == '\0') {
    iVar3 = Status::getCurrentCampaignMission(Globals::status);
    if (1 < iVar3) {
      fVar9 = (float)PlayerEgo::getPosition();
      FModSound::play(Globals::sound,*(int *)(*(int *)(this + 0x58) + 0x1c),(Vector *)local_2c,
                      (Vector *)0x0,fVar9);
    }
  }
  else {
    PlayerEgo::PlayEngineSound(*(PlayerEgo **)(this + 0x58));
    puVar12 = (uint *)Level::getEnemies(*(Level **)(this + 0x74));
    if ((puVar12 != (uint *)0x0) && (*puVar12 != 0)) {
      uVar10 = 0;
      do {
        KIPlayer::PlayEngineSound(*(KIPlayer **)(puVar12[1] + uVar10 * 4));
        uVar10 = uVar10 + 1;
      } while (uVar10 < *puVar12);
    }
  }
  *(undefined4 *)(this + 0x50) = 0;
  this_03 = (StarSystem *)Level::getStarSystem(*(Level **)(this + 0x74));
  StarSystem::initLight(this_03);
  Level::enableParticleEffects
            (*(Level **)(this + 0x74),0.25 <= (float)Globals::options._40_4_,
             0.7 < (float)Globals::options._40_4_);
  pSVar5 = (Ship *)Status::getShip(Globals::status);
  fVar9 = (float)Ship::getFireRateFactor(pSVar5);
  if (0.0 <= 1.0 - fVar9) {
    PlayerEgo::pitchAllPrimaryGuns(1.0 - fVar9);
  }
  iVar3 = Status::inAlienOrbit(Globals::status);
  if (iVar3 == 0) {
    pSVar7 = (Station *)Status::getStation(Globals::status);
    iVar3 = Station::getIndex(pSVar7);
    uVar10 = iVar3 - 0x6d;
    if (uVar10 < 0x1a) {
      if ((1 << (uVar10 & 0xff) & 0x3800003U) == 0) {
        if (uVar10 != 2) goto LAB_001a76be;
        iVar3 = Status::getCurrentCampaignMission(Globals::status);
        if (iVar3 < 0x5e) goto LAB_001a76d4;
      }
    }
    else {
LAB_001a76be:
      if (2 < iVar3 - 0x66U) goto LAB_001a76d4;
    }
    pSVar7 = (Station *)Status::getStation(Globals::status);
    Station::visit(pSVar7);
  }
LAB_001a76d4:
  if (Globals::switch_to_target_setting != -1) {
    Globals::playMusicAndFadeOutCurrent(Globals::globals,Globals::switch_to_target_setting);
  }
  Globals::switch_to_target_setting = -1;
  FModSound::setDownPitch(Globals::sound,false);
  this_04 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(*(ApplicationManager **)(this + 8))
  ;
  AbyssEngine::Engine::SetPostEffect(this_04,0x1400000,true);
  iVar3 = Status::getCurrentCampaignMission(Globals::status);
  if ((iVar3 == 0x9e) && (iVar3 = Level::getEnemies(*(Level **)(this + 0x74)), iVar3 != 0)) {
    iVar3 = Level::getEnemies(*(Level **)(this + 0x74));
    PlayerFighter::cloak((PlayerFighter *)**(undefined4 **)(iVar3 + 4),1,true);
  }
  if (*(int *)(this + 0x84) == 0) {
    this_05 = operator_new(0x240);
    MenuTouchWindow::MenuTouchWindow(this_05,1);
    *(MenuTouchWindow **)(this + 0x84) = this_05;
  }
  puVar16 = operator_new(0xc);
  puVar17 = operator_new__(4);
  puVar16[1] = puVar17;
  *puVar17 = 0;
  puVar16[2] = 1;
  *puVar16 = 0;
  *(undefined4 **)(this + 0x1e4) = puVar16;
  this_00 = Globals::globals;
  uVar10 = Globals::font;
  pSVar18 = (String *)GameText::getText(Globals::gameText,0xc4);
  Globals::getLineArray
            (this_00,uVar10,pSVar18,Globals::w + *(int *)(Globals::layout + 0x28) * -2,
             *(Array **)(this + 0x1e4));
  this[0x54] = (MGame)0x1;
LAB_001a77ce:
  if (__stack_chk_guard - local_20 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_20);
  }
  return;
}

// ===== MGame::reset  @0x001a793c  (658 bytes)
/* MGame::reset() */

void __thiscall MGame::reset(MGame *this)

{
  Status *pSVar1;
  PaintCanvas *pPVar2;
  MGame MVar3;
  undefined4 uVar4;
  Hud *this_00;
  Radio *this_01;
  Array *pAVar5;
  int iVar6;
  void *pvVar7;
  TargetFollowCamera *pTVar8;
  Radar *this_02;
  Mission *this_03;
  LevelScript *this_04;
  ChoiceWindow *this_05;
  uint uVar9;
  float *pfVar10;
  float fVar11;
  float extraout_s1;
  float extraout_s1_00;
  float fVar12;
  float extraout_s2;
  float extraout_s2_00;
  float fVar13;
  undefined1 auVar14 [16];
  
  *(undefined4 *)(this + 0xb8) = 0;
  *(undefined4 *)(this + 0xbc) = 0;
  *(undefined4 *)(this + 0x94) = 0;
  *(undefined4 *)(this + 0x98) = 0;
  *(undefined4 *)(this + 0x9c) = 0;
  *(undefined4 *)(this + 0x11c) = 0;
  *(undefined4 *)(this + 0x120) = 0;
  *(undefined4 *)(this + 0x14c) = 0;
  *(undefined4 *)(this + 0x150) = 0;
  *(undefined4 *)(this + 300) = 0;
  *(undefined4 *)(this + 0x130) = 0;
  this[0x154] = (MGame)0x0;
  *(undefined4 *)(this + 0x110) = 0x41c80000;
  *(undefined4 *)(this + 0x114) = 0xc2480000;
  *(undefined4 *)(this + 0x118) = 0x451c4000;
  *(undefined4 *)(this + 0x124) = 0;
  *(undefined4 *)(this + 0x128) = 0;
  uVar4 = Level::getPlayer(*(Level **)(this + 0x74));
  *(undefined4 *)(this + 0x58) = uVar4;
  this_00 = operator_new(0x4d4);
  Hud::Hud(this_00);
  *(Hud **)(this + 0x70) = this_00;
  this_01 = operator_new(0x48);
  Radio::Radio(this_01);
  *(Radio **)(this + 0x80) = this_01;
  pAVar5 = (Array *)Level::getMessages(*(Level **)(this + 0x74));
  Radio::setMessages(this_01,pAVar5);
  AbyssEngine::PaintCanvas::CameraCreate(Globals::Canvas,(uint *)(this + 0xec));
  pPVar2 = Globals::Canvas;
  iVar6 = Status::inAlienOrbit(Globals::status);
  if (iVar6 == 1) {
    iVar6 = Status::getCurrentCampaignMission(Globals::status);
    pfVar10 = (float *)&DAT_001a7bf8;
    if (iVar6 < 0x50) {
      pfVar10 = (float *)&DAT_001a7bfc;
    }
    fVar11 = *pfVar10;
    fVar12 = extraout_s1_00;
    fVar13 = extraout_s2_00;
  }
  else {
    fVar11 = 300000.0;
    fVar12 = extraout_s1;
    fVar13 = extraout_s2;
  }
  AbyssEngine::PaintCanvas::CameraSetPerspective((uint)pPVar2,fVar11,fVar12,fVar13);
  if (*(TargetFollowCamera **)(this + 0xf0) != (TargetFollowCamera *)0x0) {
    pvVar7 = (void *)TargetFollowCamera::~TargetFollowCamera(*(TargetFollowCamera **)(this + 0xf0));
    operator_delete(pvVar7);
    *(undefined4 *)(this + 0xf0) = 0;
  }
  pTVar8 = operator_new(0x178);
  TargetFollowCamera::TargetFollowCamera
            (pTVar8,*(undefined4 *)(this + 0xec),*(undefined4 *)(*(int *)(this + 0x58) + 8),0,0,0,0,
             0,0);
  *(TargetFollowCamera **)(this + 0xf0) = pTVar8;
  AbyssEngine::PaintCanvas::CameraSetCurrent((uint)Globals::Canvas);
  PlayerEgo::setTargetFollowCamera(*(TargetFollowCamera **)(this + 0x58));
  TargetFollowCamera::resetShipHandling();
  this_02 = operator_new(0x244);
  Radar::Radar(this_02,*(Level **)(this + 0x74));
  *(Radar **)(this + 0x7c) = this_02;
  iVar6 = Status::getMission(Globals::status);
  if (iVar6 != 0) {
    this_03 = (Mission *)Status::getMission(Globals::status);
    MVar3 = (MGame)Mission::isCampaignMission(this_03);
    this[0x61] = MVar3;
  }
  this_04 = operator_new(0xe8);
  LevelScript::LevelScript
            (this_04,*(Level **)(this + 0x74),*(Hud **)(this + 0x70),*(Radar **)(this + 0x7c),
             *(TargetFollowCamera **)(this + 0xf0));
  *(LevelScript **)(this + 0x78) = this_04;
  LevelScript::resetCamera(this_04,*(Level **)(this + 0x74));
  Level::initParticleSystems(*(Level **)(this + 0x74));
  this_05 = operator_new(0x54);
  ChoiceWindow::ChoiceWindow(this_05);
  *(ChoiceWindow **)(this + 0x90) = this_05;
  this[0x5c] = (MGame)0x0;
  this[0x60] = (MGame)0x0;
  *(undefined4 *)(this + 0x14) = 0;
  this[0x18] = (MGame)0x0;
  this[0x5d] = (MGame)0x0;
  this[0x5f] = (MGame)0x0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  this[0xc4] = (MGame)0x0;
  *(undefined2 *)(this + 0xc0) = 0;
  this[0xc2] = (MGame)0x0;
  this[0xc5] = (MGame)0x0;
  this[0xdc] = (MGame)0x0;
  this[0x156] = (MGame)0x0;
  *(undefined8 *)(this + 0xf8) = 0;
  *(undefined8 *)(this + 0x100) = 0;
  auVar14 = ZEXT816(0) << 0x40;
  this[0x108] = (MGame)0x0;
  *(undefined4 *)(this + 0x160) = 0x3f800000;
  *(undefined4 *)(this + 0x1a8) = 0;
  *(undefined4 *)(this + 0x1ac) = 0x42c80000;
  *(undefined2 *)(this + 0x1b0) = 0;
  uVar4 = *(undefined4 *)(Globals::layout + 0x2f4);
  *(undefined4 *)(this + 0x1e0) = 0;
  *(undefined4 *)(this + 0x1c4) = uVar4;
  *(undefined4 *)(this + 0x1c8) = 0;
  *(undefined4 *)(this + 0x170) = 0;
  this[0x174] = (MGame)0x0;
  *(undefined8 *)(this + 0x178) = 0;
  uVar9 = AbyssEngine::ApplicationManager::GetCurrentTimeMillis(Globals::appManager);
  *(ulonglong *)(this + 0x20) = auVar14._0_8_ & 0xffff0000ffff0000 | (ulonglong)uVar9 & 0xffff;
  *(ulonglong *)(this + 0x28) = auVar14._8_8_ & 0xffff0000ffff0000 | (ulonglong)uVar9 & 0xffff;
  this[0x109] = (MGame)0x1;
  this[0x10a] = (MGame)0x1;
  this[0xcb] = (MGame)0x0;
  *(undefined4 *)(this + 0xcc) = 0;
  this[0xd0] = (MGame)0x0;
  this[0x1dc] = (MGame)0x0;
  this[0x1dd] = (MGame)0x0;
  this[0x1de] = (MGame)0x0;
  this[0x1d5] = AbyssEngine::Engine::UseAdvancedShader;
  pSVar1 = Globals::status;
  *(undefined4 *)(Globals::status + 0x180) = 0;
  *(undefined4 *)(pSVar1 + 0x184) = 1;
  *(undefined4 *)(pSVar1 + 0x188) = 1;
  return;
}

// ===== MGame::handleAccelerometer  @0x001a7c1c  (538 bytes)
/* MGame::handleAccelerometer() */

void __thiscall MGame::handleAccelerometer(MGame *this)

{
  char cVar1;
  undefined4 uVar2;
  Engine *pEVar3;
  int iVar4;
  double *pdVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  double dVar9;
  float fVar10;
  
  pEVar3 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(*(ApplicationManager **)(this + 8));
  iVar4 = AbyssEngine::Engine::GetAccelValue(pEVar3);
  fVar6 = (float)(*(double *)(iVar4 + 8) * 2.5);
  fVar10 = 1.0;
  if (fVar6 <= 1.0) {
    fVar10 = -1.0;
    if (((int)((uint)(fVar6 < -1.0) << 0x1f) < 0) || (fVar10 = fVar6, fVar6 < 0.0)) {
      PlayerEgo::left(*(int *)(this + 0x58),fVar10 * fVar10);
      goto LAB_001a7cae;
    }
    if (fVar6 == 0.0) goto LAB_001a7cae;
  }
  PlayerEgo::right(*(int *)(this + 0x58),fVar10 * fVar10);
LAB_001a7cae:
  pEVar3 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(*(ApplicationManager **)(this + 8));
  pdVar5 = (double *)AbyssEngine::Engine::GetAccelValue(pEVar3);
  dVar9 = *pdVar5;
  pEVar3 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(*(ApplicationManager **)(this + 8));
  iVar4 = AbyssEngine::Engine::GetAccelValue(pEVar3);
  uVar2 = Globals::options._28_4_;
  cVar1 = Globals::options[0x10];
  fVar10 = (float)dVar9;
  dVar9 = *(double *)(iVar4 + 0x10);
  pEVar3 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(*(ApplicationManager **)(this + 8));
  iVar4 = AbyssEngine::Engine::GetAccelValue(pEVar3);
  if (cVar1 == '\0') {
    fVar6 = fVar10;
    if (0.0 < *(double *)(iVar4 + 0x10)) {
      fVar6 = 1.0;
      if (fVar10 <= 1.0) {
        fVar6 = (1.0 - fVar10) + 1.0;
      }
    }
    fVar6 = (float)uVar2 - fVar6;
    fVar10 = (float)Globals::options._32_4_ - (float)dVar9;
  }
  else {
    fVar6 = fVar10;
    if (0.0 < *(double *)(iVar4 + 0x10)) {
      fVar6 = 1.0;
      if (fVar10 <= 1.0) {
        fVar6 = (1.0 - fVar10) + 1.0;
      }
    }
    fVar6 = fVar6 - (float)uVar2;
    fVar10 = (float)dVar9 - (float)Globals::options._32_4_;
  }
  fVar7 = fVar6 * 3.0;
  fVar8 = fVar10 * 3.0;
  fVar6 = fVar6 * -3.0;
  if (0.0 < fVar7) {
    fVar6 = fVar7;
  }
  fVar10 = fVar10 * -3.0;
  if (0.0 < fVar8) {
    fVar10 = fVar8;
  }
  if (fVar6 < fVar10) {
    fVar7 = fVar8;
  }
  fVar10 = 1.0;
  if (fVar7 <= 1.0) {
    fVar10 = -1.0;
    if (((int)((uint)(fVar7 < -1.0) << 0x1f) < 0) || (fVar10 = fVar7, fVar7 < 0.0)) {
      PlayerEgo::down(*(int *)(this + 0x58),fVar10 * fVar10);
      return;
    }
    if (fVar7 == 0.0) {
      return;
    }
  }
  PlayerEgo::up(*(int *)(this + 0x58),fVar10 * fVar10);
  return;
}

// ===== MGame::maneuverTouchBegin  @0x001a7e40  (18 bytes)
/* MGame::maneuverTouchBegin(int, int, void*) */

void MGame::maneuverTouchBegin(int param_1,int param_2,void *param_3)

{
  *(undefined1 *)(param_1 + 0x174) = 1;
  *(int *)(param_1 + 0x178) = param_2;
  *(void **)(param_1 + 0x17c) = param_3;
  *(undefined4 *)(param_1 + 0x170) = 0;
  return;
}

// ===== MGame::maneuverTouchMove  @0x001a7e54  (76 bytes)
/* MGame::maneuverTouchMove(int, int, void*) */

void MGame::maneuverTouchMove(int param_1,int param_2,void *param_3)

{
  int iVar1;
  uint in_fpscr;
  float fVar2;
  float fVar3;
  
  if (*(char *)(param_1 + 0x174) != '\0') {
    fVar2 = (float)VectorSignedToFloat(Globals::h,(byte)(in_fpscr >> 0x16) & 3);
    iVar1 = (int)param_3 - *(int *)(param_1 + 0x17c);
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    fVar3 = (float)VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x16) & 3);
    if ((fVar2 / 320.0) * 90.0 < fVar3) {
      *(undefined1 *)(param_1 + 0x174) = 0;
      *(undefined4 *)(param_1 + 0x170) = 0;
    }
  }
  return;
}

// ===== MGame::maneuverTouchEnd  @0x001a7eac  (104 bytes)
/* MGame::maneuverTouchEnd(int, int, void*) */

void MGame::maneuverTouchEnd(int param_1,int param_2,void *param_3)

{
  int iVar1;
  uint in_fpscr;
  float fVar2;
  float fVar3;
  
  if ((*(char *)(param_1 + 0x174) != '\0') && (*(int *)(param_1 + 0x170) < 0x259)) {
    fVar2 = (float)VectorSignedToFloat(Globals::w,(byte)(in_fpscr >> 0x16) & 3);
    iVar1 = param_2 - *(int *)(param_1 + 0x178);
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    fVar3 = (float)VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x16) & 3);
    if ((fVar2 / 480.0) * 70.0 < fVar3) {
      iVar1 = 1;
      if (*(int *)(param_1 + 0x178) < param_2) {
        iVar1 = 2;
      }
      PlayerEgo::initManeuver(*(PlayerEgo **)(param_1 + 0x58),iVar1);
    }
  }
  *(undefined1 *)(param_1 + 0x174) = 0;
  return;
}

// ===== MGame::freeCamTouchBegin  @0x001a7f20  (202 bytes)
/* MGame::freeCamTouchBegin(int, int, void*) */

void __thiscall MGame::freeCamTouchBegin(MGame *this,int param_1,int param_2,void *param_3)

{
  int iVar1;
  Vector *pVVar2;
  undefined4 uVar3;
  uint in_fpscr;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  
  local_20 = __stack_chk_guard;
  if (*(int *)(this + 0x94) == 0) {
    if (*(int *)(this + 0x98) == 0) {
      *(undefined4 *)(this + 0x9c) = 0;
    }
    local_2c = VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    local_28 = VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
    *(void **)(this + 0x94) = param_3;
    iVar1 = 0xa0;
  }
  else {
    if (999 < *(int *)(this + 0x9c)) goto LAB_001a7fbe;
    *(undefined4 *)(this + 0xb8) = 0;
    pVVar2 = (Vector *)TargetFollowCamera::getCamOffset(*(TargetFollowCamera **)(this + 0xf0));
    uVar3 = AbyssEngine::AEMath::VectorLength(pVVar2);
    local_2c = VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    local_28 = VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
    *(undefined4 *)(this + 0xb8) = uVar3;
    iVar1 = 0xac;
    *(void **)(this + 0x98) = param_3;
  }
  local_24 = 0;
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + iVar1),(Vector *)&local_2c);
LAB_001a7fbe:
  *(int *)(this + 0x11c) = param_1;
  *(int *)(this + 0x120) = param_2;
  *(int *)(this + 0x14c) = param_1;
  *(int *)(this + 0x150) = param_2;
  *(undefined4 *)(this + 300) = 0;
  *(undefined4 *)(this + 0x130) = 0;
  this[0x154] = (MGame)0x1;
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== MGame::freeCamTouchMove  @0x001a7ff4  (580 bytes)
/* MGame::freeCamTouchMove(int, int, void*) */

void __thiscall MGame::freeCamTouchMove(MGame *this,int param_1,int param_2,void *param_3)

{
  int iVar1;
  float fVar2;
  int extraout_r2;
  Vector *this_00;
  Vector *pVVar3;
  uint in_fpscr;
  float fVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  int local_44;
  
  local_44 = __stack_chk_guard;
  iVar1 = PlayerEgo::isMining(*(PlayerEgo **)(this + 0x58));
  if (iVar1 == 1) {
    this[0x109] = (MGame)0x1;
    if (__stack_chk_guard == local_44) {
      freeCamTouchEnd(this,local_44,extraout_r2,param_3);
      return;
    }
    goto LAB_001a8232;
  }
  this[0x109] = (MGame)0x0;
  if ((*(int *)(this + 0x94) == 0) || (*(int *)(this + 0x98) == 0)) {
    fVar4 = (float)VectorSignedToFloat(param_1 - *(int *)(this + 0x11c),(byte)(in_fpscr >> 0x16) & 3
                                      );
    *(int *)(this + 300) = param_1 - *(int *)(this + 0x11c);
    *(int *)(this + 0x11c) = param_1;
    *(undefined4 *)(this + 0x134) = 0x3f800000;
    *(float *)(this + 0x110) = fVar4 + *(float *)(this + 0x110);
    fVar4 = (float)VectorSignedToFloat(param_2 - *(int *)(this + 0x120),(byte)(in_fpscr >> 0x16) & 3
                                      );
    *(int *)(this + 0x130) = param_2 - *(int *)(this + 0x120);
    *(int *)(this + 0x120) = param_2;
    *(undefined4 *)(this + 0x138) = 0x3f800000;
    *(float *)(this + 0x114) = fVar4 + *(float *)(this + 0x114);
    if (*(int *)(this + 0x94) != 0) goto LAB_001a80b4;
    local_50 = VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    local_4c = VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
    iVar1 = 0xac;
LAB_001a8170:
    local_48 = 0;
    AbyssEngine::AEMath::Vector::operator=((Vector *)(this + iVar1),(Vector *)&local_50);
  }
  else {
LAB_001a80b4:
    if (*(int *)(this + 0x98) == 0) {
      local_50 = VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
      local_4c = VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
      iVar1 = 0xa0;
      goto LAB_001a8170;
    }
    this_00 = (Vector *)(this + 0xa0);
    pVVar3 = (Vector *)(this + 0xac);
    AbyssEngine::AEMath::operator-((AEMath *)&local_50,this_00,pVVar3);
    fVar4 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_50);
    if (*(void **)(this + 0x94) == param_3) {
      uVar5 = VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
      uVar6 = VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
      local_54 = 0;
      local_5c = uVar5;
      local_58 = uVar6;
      AbyssEngine::AEMath::operator-((AEMath *)&local_50,(Vector *)&local_5c,pVVar3);
      fVar2 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_50);
      local_50 = uVar5;
      local_4c = uVar6;
LAB_001a81b6:
      local_48 = 0;
      AbyssEngine::AEMath::Vector::operator=(this_00,(Vector *)&local_50);
    }
    else {
      fVar2 = fVar4;
      if (*(void **)(this + 0x98) == param_3) {
        uVar5 = VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        uVar6 = VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
        local_54 = 0;
        local_5c = uVar5;
        local_58 = uVar6;
        AbyssEngine::AEMath::operator-((AEMath *)&local_50,(Vector *)&local_5c,this_00);
        fVar2 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_50);
        this_00 = pVVar3;
        local_50 = uVar5;
        local_4c = uVar6;
        goto LAB_001a81b6;
      }
    }
    fVar4 = *(float *)(this + 0xb8) + (fVar2 - fVar4) * -50.0;
    *(float *)(this + 0xb8) = fVar4;
    if (fVar4 <= 20000.0) {
      if ((int)((uint)(fVar4 < 1500.0) << 0x1f) < 0) {
        uVar5 = 0x44bb8000;
        fVar4 = 1500.0;
        goto LAB_001a8204;
      }
    }
    else {
      uVar5 = 0x469c4000;
      fVar4 = 20000.0;
LAB_001a8204:
      *(undefined4 *)(this + 0xb8) = uVar5;
    }
    TargetFollowCamera::zoomTarget(*(TargetFollowCamera **)(this + 0xf0),fVar4);
  }
  if (__stack_chk_guard == local_44) {
    return;
  }
LAB_001a8232:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== MGame::freeCamTouchEnd  @0x001a8250  (174 bytes)
/* MGame::freeCamTouchEnd(int, int, void*) */

void __thiscall MGame::freeCamTouchEnd(MGame *this,int param_1,int param_2,void *param_3)

{
  int iVar1;
  uint in_fpscr;
  float fVar2;
  float fVar3;
  float fVar4;
  
  if (*(void **)(this + 0x94) == param_3) {
    *(undefined4 *)(this + 0x94) = 0;
    *(undefined4 *)(this + 0x9c) = 0;
  }
  else {
    *(undefined8 *)(this + 0x98) = 0;
  }
  this[0x109] = (MGame)0x1;
  iVar1 = *(int *)(this + 300);
  fVar2 = (float)VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x16) & 3);
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  fVar4 = 0.0;
  if (3 < iVar1) {
    fVar4 = fVar2;
  }
  *(float *)(this + 0x140) = fVar4;
  *(undefined4 *)(this + 0x134) = 0x3f666666;
  iVar1 = *(int *)(this + 0x130);
  fVar4 = (float)VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x16) & 3);
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  fVar3 = 0.0;
  if (3 < iVar1) {
    fVar3 = fVar4;
  }
  *(float *)(this + 0x144) = fVar3;
  *(undefined4 *)(this + 0x138) = 0x3f666666;
  this[0x154] = (MGame)0x0;
  fVar3 = *(float *)(this + 0x110);
  *(float *)(this + 0x110) = fVar3 + fVar2;
  *(int *)(this + 0x124) = (int)(fVar3 + fVar2);
  fVar2 = *(float *)(this + 0x114);
  *(float *)(this + 0x114) = fVar2 + fVar4;
  *(int *)(this + 0x128) = (int)(fVar2 + fVar4);
  return;
}

// ===== MGame::pauseSounds  @0x001a8304  (68 bytes)
/* MGame::pauseSounds() */

void __thiscall MGame::pauseSounds(MGame *this)

{
  uint *puVar1;
  uint uVar2;
  
  this[0x19e] = this[0x5d];
  FModSound::pauseAllPlayingSoundFXEvents(Globals::sound);
  PlayerEgo::PauseEngineSound(*(PlayerEgo **)(this + 0x58));
  puVar1 = (uint *)Level::getEnemies(*(Level **)(this + 0x74));
  if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
    uVar2 = 0;
    do {
      KIPlayer::PauseEngineSound(*(KIPlayer **)(puVar1[1] + uVar2 * 4));
      uVar2 = uVar2 + 1;
    } while (uVar2 < *puVar1);
  }
  return;
}

// ===== MGame::resumeSounds  @0x001a834c  (60 bytes)
/* MGame::resumeSounds() */

void __thiscall MGame::resumeSounds(MGame *this)

{
  uint *puVar1;
  uint uVar2;
  
  FModSound::resumeAll(Globals::sound);
  PlayerEgo::ResumeEngineSound(*(PlayerEgo **)(this + 0x58));
  puVar1 = (uint *)Level::getEnemies(*(Level **)(this + 0x74));
  if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
    uVar2 = 0;
    do {
      KIPlayer::ResumeEngineSound(*(KIPlayer **)(puVar1[1] + uVar2 * 4));
      uVar2 = uVar2 + 1;
    } while (uVar2 < *puVar1);
  }
  return;
}

// ===== MGame::OnTouchBegin  @0x001a838c  (3072 bytes)
/* MGame::OnTouchBegin(int, int, void*) */

void __thiscall MGame::OnTouchBegin(MGame *this,int param_1,int param_2,void *param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  Ship *pSVar5;
  int iVar6;
  KIPlayer *pKVar7;
  Mission *pMVar8;
  void *pvVar9;
  DialogueWindow *this_00;
  String *pSVar10;
  String *pSVar11;
  PlayerEgo *pPVar12;
  int iVar13;
  ChoiceWindow *pCVar14;
  MGame *pMVar15;
  bool bVar16;
  uint in_fpscr;
  float extraout_s0;
  undefined4 uVar17;
  float fVar18;
  undefined4 uVar19;
  longlong lVar20;
  longlong lVar21;
  
  if (*(int *)(this + 0xbc) == 0) {
    *(void **)(this + 0xbc) = param_3;
  }
  if (this[0x5d] == (MGame)0x0) {
    if ((this[0x60] != (MGame)0x0) && (3999 < *(int *)(this + 0x50))) {
      iVar4 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar4 == 0x9e) {
        uVar2 = 2;
        this[0x54] = (MGame)0x0;
LAB_001a845c:
        AbyssEngine::ApplicationManager::SetCurrentApplicationModule
                  (*(ApplicationManager **)(this + 8),uVar2);
        return;
      }
      if (*(GameRecord **)(this + 0x1e0) != (GameRecord *)0x0) {
        GameRecord::load(*(GameRecord **)(this + 0x1e0));
        Globals::playMusicAndFadeOutCurrent(Globals::globals,0);
        this[0x54] = (MGame)0x0;
        uVar2 = 5;
        goto LAB_001a845c;
      }
      Globals::playMusicAndFadeOutCurrent(Globals::globals,2);
      this[0x54] = (MGame)0x0;
      AbyssEngine::ApplicationManager::SetCurrentApplicationModule
                (*(ApplicationManager **)(this + 8),1);
    }
  }
  else {
    if (this[0xc3] != (MGame)0x0) {
      if (*Globals::layout == (Layout)0x0) {
        bVar1 = StarMap::OnTouchBegin(*(StarMap **)(this + 0x8c),param_1,param_2);
        this[0xc3] = (MGame)(bVar1 ^ 1);
        return;
      }
      Layout::OnTouchBegin(Globals::layout,param_1,param_2);
      return;
    }
    if (((this[0xc1] != (MGame)0x0) || (this[0xca] != (MGame)0x0)) || (this[0xc0] != (MGame)0x0)) {
      ChoiceWindow::OnTouchBegin(*(ChoiceWindow **)(this + 0x90),param_1,param_2);
      return;
    }
    if (this[0x5e] != (MGame)0x0) {
      DialogueWindow::OnTouchBegin(*(DialogueWindow **)(this + 0x88),param_1,param_2);
      return;
    }
    if (this[0xc5] != (MGame)0x0) {
      iVar4 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
      if (*(char *)(iVar4 + 5) != '\0') {
        return;
      }
      if (*(char *)(iVar4 + 0xc) != '\0') {
        return;
      }
      MenuTouchWindow::OnTouchBegin(*(int *)(this + 0x84),param_1,(void *)param_2);
      if (this[0x156] == (MGame)0x0) {
        return;
      }
      iVar4 = MenuTouchWindow::isShowingMessage(*(MenuTouchWindow **)(this + 0x84));
      if (iVar4 != 0) {
        return;
      }
      iVar4 = MenuTouchWindow::isMakingScreenshot(*(MenuTouchWindow **)(this + 0x84));
      if (iVar4 != 0) {
        return;
      }
      goto LAB_001a87f8;
    }
  }
  uVar2 = Hud::touchBegin(*(Hud **)(this + 0x70),param_1,param_2,param_3);
  *(uint *)(this + 0xf4) = uVar2;
  if (((uVar2 & 0x10) == 0) || (this[0xd8] != (MGame)0x0)) {
    if ((uVar2 & 0x20) != 0) {
      lVar20 = Status::getPlayingTime(Globals::status);
      iVar4 = (int)((ulonglong)(lVar20 - *(longlong *)(this + 0x100)) >> 0x20);
      bVar16 = 499 < (uint)(lVar20 - *(longlong *)(this + 0x100));
      if ((int)(-(uint)bVar16 - iVar4) < 0 == (SBORROW4(0,iVar4) != SBORROW4(-iVar4,(uint)bVar16)))
      {
        PlayerEgo::alignToHorizon(*(PlayerEgo **)(this + 0x58));
      }
      *(longlong *)(this + 0x100) = lVar20;
      if (this[0x5f] != (MGame)0x0) {
        return;
      }
      if (*(void **)(this + 0xbc) == param_3) {
        return;
      }
      if (*(int *)(this + 0xf4) != 0x20) {
        return;
      }
LAB_001a85a8:
      uVar17 = VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
      uVar19 = VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
      this[0x1b0] = (MGame)0x1;
      *(undefined4 *)(this + 0x1b4) = uVar17;
      *(undefined4 *)(this + 0x1b8) = uVar19;
      return;
    }
    if ((uVar2 & 1) == 0) {
      if (((uVar2 & 0x100) != 0) &&
         ((((iVar4 = PlayerEgo::isAutoPilot(*(PlayerEgo **)(this + 0x58)), iVar4 != 0 ||
            (iVar4 = PlayerEgo::isDockingToAsteroid(*(PlayerEgo **)(this + 0x58)), iVar4 != 0)) ||
           (iVar4 = PlayerEgo::isDockingToDockingPoint(*(PlayerEgo **)(this + 0x58)), iVar4 == 1))
          && ((*(char *)(*(int *)(*(PlayerEgo **)(this + 0x58) + 0x14) + 0x54) == '\0' &&
              (iVar4 = PlayerEgo::aboutToReachAutoTarget(*(PlayerEgo **)(this + 0x58)), iVar4 == 0))
             )))) {
        *(undefined4 *)(this + 0x160) = 0x40a00000;
        TargetFollowCamera::setFastForwardMode(*(TargetFollowCamera **)(this + 0xf0),true);
        return;
      }
      iVar3 = *(int *)(this + 0x16c);
      iVar4 = iVar3;
      if (0 < iVar3) {
        iVar4 = *(int *)(this + 0x164);
      }
      iVar6 = iVar3 + -1;
      if (iVar3 >= 1) {
        iVar6 = iVar4;
      }
      if ((iVar6 < 0 != (iVar3 < 1 && SBORROW4(iVar3,1))) || (((byte)this[0xf5] & 1) == 0)) {
        uVar2 = *(uint *)(this + 0x14);
        if (uVar2 == 3) {
          iVar4 = PlayerEgo::isMining(*(PlayerEgo **)(this + 0x58));
          if ((iVar4 == 0) && (this[0x5f] == (MGame)0x0)) {
LAB_001a87f8:
            freeCamTouchBegin(this,param_1,param_2,param_3);
            return;
          }
          uVar2 = *(uint *)(this + 0x14);
        }
        if (1 < uVar2) {
          return;
        }
        this[0x174] = (MGame)0x1;
        *(int *)(this + 0x178) = param_1;
        *(int *)(this + 0x17c) = param_2;
        *(undefined4 *)(this + 0x170) = 0;
        if (this[0x5f] != (MGame)0x0) {
          return;
        }
        if (*(int *)(this + 0xf4) != 0) {
          return;
        }
        goto LAB_001a85a8;
      }
      if (iVar4 < 1) {
        Hud::setTimeExtender(*(Hud **)(this + 0x70),true,false,true,true);
        fVar18 = (float)FModSound::setDownPitch(Globals::sound,true);
        iVar4 = 0x460;
        *(undefined4 *)(this + 0x164) = *(undefined4 *)(this + 0x16c);
      }
      else {
        *(undefined4 *)(this + 0x164) = 0xffffffff;
        FModSound::setDownPitch(Globals::sound,false);
        fVar18 = (float)Hud::setTimeExtender(*(Hud **)(this + 0x70),true,false,false,false);
        iVar4 = 0x45f;
      }
    }
    else {
      iVar4 = 0x7c;
      fVar18 = extraout_s0;
    }
    FModSound::play(Globals::sound,iVar4,(Vector *)0x0,(Vector *)0x0,fVar18);
    return;
  }
  if ((*(int *)(*(int *)(this + 0x7c) + 0x24) == 0) ||
     (iVar4 = Status::inAlienOrbit(Globals::status), iVar4 != 0)) {
LAB_001a860c:
    pMVar15 = this + 0x58;
    if (((*(int *)(*(int *)(this + 0x7c) + 0x14) != 0) &&
        (iVar4 = PlayerEgo::isDockingToPlanet(*(PlayerEgo **)pMVar15), iVar4 == 0)) &&
       (iVar4 = PlayerEgo::isDockedToDockingPoint(*(PlayerEgo **)pMVar15), iVar4 == 0)) {
      iVar4 = Status::getCurrentCampaignMission(Globals::status);
      if ((iVar4 < 10) ||
         (iVar4 = Status::getCurrentCampaignMission(Globals::status), iVar4 == 0x30)) {
        iVar3 = *(int *)(this + 0x58);
        pPVar12 = (PlayerEgo *)0x15;
        iVar4 = *(int *)(this + 0x70);
LAB_001a8740:
        Hud::hudEvent(iVar4,pPVar12,iVar3);
        return;
      }
      iVar4 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar4 == 0x18) {
        iVar4 = Radar::getPlanetDockIndex(*(Radar **)(this + 0x7c));
        pMVar8 = (Mission *)Status::getCampaignMission(Globals::status);
        iVar3 = Mission::getTargetStation(pMVar8);
        if (iVar4 == iVar3) {
          pSVar5 = (Ship *)Status::getShip(Globals::status);
          iVar4 = Ship::getFirstEquipmentOfSort(pSVar5,0xd);
          if (iVar4 == 0) {
LAB_001a8de8:
            this[0x5d] = (MGame)0x1;
            pauseSounds(this);
            if (*(DialogueWindow **)(this + 0x88) != (DialogueWindow *)0x0) {
              pvVar9 = (void *)DialogueWindow::~DialogueWindow(*(DialogueWindow **)(this + 0x88));
              operator_delete(pvVar9);
              *(undefined4 *)(this + 0x88) = 0;
            }
            this_00 = operator_new(0x6c);
            pSVar11 = (String *)GameText::getText(Globals::gameText,0x214);
            pSVar10 = (String *)GameText::getText(Globals::gameText,0x643);
            DialogueWindow::DialogueWindow(this_00,pSVar11,pSVar10,(int *)&DAT_0026b8e0);
            *(DialogueWindow **)(this + 0x88) = this_00;
            this[0x5e] = (MGame)0x1;
            return;
          }
          pSVar5 = (Ship *)Status::getShip(Globals::status);
          iVar4 = Ship::getFirstEquipmentOfSort(pSVar5,0x11);
          if (iVar4 == 0) goto LAB_001a8de8;
        }
      }
      iVar4 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar4 == 0x87) {
        iVar4 = Radar::getPlanetDockIndex(*(Radar **)(this + 0x7c));
        pMVar8 = (Mission *)Status::getCampaignMission(Globals::status);
        iVar3 = Mission::getTargetStation(pMVar8);
        if (iVar4 == iVar3) {
          pSVar5 = (Ship *)Status::getShip(Globals::status);
          iVar4 = Ship::getFirstEquipmentOfSort(pSVar5,0x13);
          if (iVar4 == 0) {
            this[0x5d] = (MGame)0x1;
            pauseSounds(this);
            pCVar14 = *(ChoiceWindow **)(this + 0x90);
            if (pCVar14 == (ChoiceWindow *)0x0) {
              pCVar14 = operator_new(0x54);
              ChoiceWindow::ChoiceWindow(pCVar14);
              *(ChoiceWindow **)(this + 0x90) = pCVar14;
            }
            iVar4 = 0xc8d;
            goto LAB_001a8f72;
          }
        }
      }
      iVar4 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar4 == 0x5b) {
        iVar4 = Radar::getPlanetDockIndex(*(Radar **)(this + 0x7c));
        pMVar8 = (Mission *)Status::getCampaignMission(Globals::status);
        iVar3 = Mission::getTargetStation(pMVar8);
        if (iVar4 != iVar3) goto LAB_001a8bb4;
        pSVar5 = (Ship *)Status::getShip(Globals::status);
        iVar4 = Ship::getMaxPassengers(pSVar5);
        if (9 < iVar4) goto LAB_001a8bb4;
        this[0x5d] = (MGame)0x1;
        pauseSounds(this);
        pCVar14 = *(ChoiceWindow **)(this + 0x90);
        if (pCVar14 == (ChoiceWindow *)0x0) {
          pCVar14 = operator_new(0x54);
          ChoiceWindow::ChoiceWindow(pCVar14);
          *(ChoiceWindow **)(this + 0x90) = pCVar14;
        }
LAB_001a8f12:
        iVar4 = 0xc8e;
        goto LAB_001a8f72;
      }
LAB_001a8bb4:
      iVar4 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar4 == 0x5e) {
        iVar4 = Radar::getPlanetDockIndex(*(Radar **)(this + 0x7c));
        pMVar8 = (Mission *)Status::getCampaignMission(Globals::status);
        iVar3 = Mission::getTargetStation(pMVar8);
        if (iVar4 == iVar3) {
          pSVar5 = (Ship *)Status::getShip(Globals::status);
          iVar4 = Ship::getMaxPassengers(pSVar5);
          if (iVar4 == 0) {
            this[0x5d] = (MGame)0x1;
            pauseSounds(this);
            pCVar14 = *(ChoiceWindow **)(this + 0x90);
            if (pCVar14 == (ChoiceWindow *)0x0) {
              pCVar14 = operator_new(0x54);
              ChoiceWindow::ChoiceWindow(pCVar14);
              *(ChoiceWindow **)(this + 0x90) = pCVar14;
            }
            goto LAB_001a8f12;
          }
        }
      }
      iVar4 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar4 == 0x69) {
        iVar4 = Radar::getPlanetDockIndex(*(Radar **)(this + 0x7c));
        pMVar8 = (Mission *)Status::getCampaignMission(Globals::status);
        iVar3 = Mission::getTargetStation(pMVar8);
        if (iVar4 == iVar3) {
          pSVar5 = (Ship *)Status::getShip(Globals::status);
          iVar4 = Ship::hasEquipment(pSVar5,0xce,1);
          if (iVar4 == 0) {
            this[0x5d] = (MGame)0x1;
            pauseSounds(this);
            pCVar14 = *(ChoiceWindow **)(this + 0x90);
            if (pCVar14 == (ChoiceWindow *)0x0) {
              pCVar14 = operator_new(0x54);
              ChoiceWindow::ChoiceWindow(pCVar14);
              *(ChoiceWindow **)(this + 0x90) = pCVar14;
            }
            pSVar11 = (String *)GameText::getText(Globals::gameText,0xc91);
            ChoiceWindow::set(pCVar14,pSVar11);
            this[0xca] = (MGame)0x1;
            this[0x109] = (MGame)0x1;
            return;
          }
        }
      }
      iVar4 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar4 == 0x8b) {
        iVar4 = Radar::getPlanetDockIndex(*(Radar **)(this + 0x7c));
        pMVar8 = (Mission *)Status::getCampaignMission(Globals::status);
        iVar3 = Mission::getTargetStation(pMVar8);
        if (iVar4 == iVar3) {
          pSVar5 = (Ship *)Status::getShip(Globals::status);
          iVar4 = Ship::getIndex(pSVar5);
          if (iVar4 != 0x2a) {
            pSVar5 = (Ship *)Status::getShip(Globals::status);
            iVar4 = Ship::getIndex(pSVar5);
            if (*(int *)(&DAT_0025d3d0 + iVar4 * 4) == 1) {
              pSVar5 = (Ship *)Status::getShip(Globals::status);
              iVar4 = Ship::hasEquipment(pSVar5,0xbe,1);
              if (iVar4 != 0) goto LAB_001a8ccc;
            }
            this[0x5d] = (MGame)0x1;
            pauseSounds(this);
            pCVar14 = *(ChoiceWindow **)(this + 0x90);
            if (pCVar14 == (ChoiceWindow *)0x0) {
              pCVar14 = operator_new(0x54);
              ChoiceWindow::ChoiceWindow(pCVar14);
              *(ChoiceWindow **)(this + 0x90) = pCVar14;
            }
            iVar4 = 0xc8f;
            goto LAB_001a8f72;
          }
        }
      }
LAB_001a8ccc:
      iVar4 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar4 == 0x8e) {
        iVar4 = Radar::getPlanetDockIndex(*(Radar **)(this + 0x7c));
        pMVar8 = (Mission *)Status::getCampaignMission(Globals::status);
        iVar3 = Mission::getTargetStation(pMVar8);
        if (iVar4 == iVar3) {
          pSVar5 = (Ship *)Status::getShip(Globals::status);
          iVar4 = Ship::getFirstEquipmentOfSort(pSVar5,0x21);
          if (iVar4 != 0) {
            pSVar5 = (Ship *)Status::getShip(Globals::status);
            iVar4 = Ship::hasEquipment(pSVar5,0xc5,0xf);
            if (iVar4 == 1) {
              pSVar5 = (Ship *)Status::getShip(Globals::status);
              iVar4 = Ship::getFirstEquipmentOfSort(pSVar5,0x23);
              if (iVar4 != 0) goto LAB_001a8d44;
            }
          }
          this[0x5d] = (MGame)0x1;
          pauseSounds(this);
          pCVar14 = *(ChoiceWindow **)(this + 0x90);
          if (pCVar14 == (ChoiceWindow *)0x0) {
            pCVar14 = operator_new(0x54);
            ChoiceWindow::ChoiceWindow(pCVar14);
            *(ChoiceWindow **)(this + 0x90) = pCVar14;
          }
          iVar4 = 0xc90;
          goto LAB_001a8f72;
        }
      }
LAB_001a8d44:
      iVar4 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar4 == 0x8e) {
        iVar4 = Radar::getPlanetDockIndex(*(Radar **)(this + 0x7c));
        pMVar8 = (Mission *)Status::getCampaignMission(Globals::status);
        iVar3 = Mission::getTargetStation(pMVar8);
        if (iVar4 == iVar3) {
          pSVar5 = (Ship *)Status::getShip(Globals::status);
          iVar4 = Ship::getFreeSpace(pSVar5);
          if (iVar4 == 0) {
            this[0x5d] = (MGame)0x1;
            pauseSounds(this);
            pCVar14 = *(ChoiceWindow **)(this + 0x90);
            if (pCVar14 == (ChoiceWindow *)0x0) {
              pCVar14 = operator_new(0x54);
              ChoiceWindow::ChoiceWindow(pCVar14);
              *(ChoiceWindow **)(this + 0x90) = pCVar14;
            }
            iVar4 = 0xc92;
LAB_001a8f72:
            pSVar11 = (String *)GameText::getText(Globals::gameText,iVar4);
            ChoiceWindow::set(pCVar14,pSVar11);
            this[0xca] = (MGame)0x1;
            this[0x109] = (MGame)0x1;
            return;
          }
        }
      }
      TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0xf0),true);
      PlayerEgo::dockToPlanet(*(PlayerEgo **)(this + 0x58));
      this[0x5c] = (MGame)0x0;
      this[0x108] = (MGame)0x0;
      Hud::enableFireForTutorial(*(Hud **)(this + 0x70),false);
      *(undefined1 *)(*(int *)(this + 0x78) + 0x11) = 1;
      this[0x5f] = (MGame)0x1;
      return;
    }
    iVar4 = PlayerEgo::isMining(*(PlayerEgo **)pMVar15);
    if ((iVar4 == 0) &&
       (iVar4 = PlayerEgo::isDockedToDockingPoint(*(PlayerEgo **)pMVar15), iVar4 == 0)) {
      iVar4 = Radar::getLockedAsteroid(*(Radar **)(this + 0x7c));
      if ((iVar4 != 0) &&
         (iVar4 = PlayerEgo::isDockingToAsteroid(*(PlayerEgo **)pMVar15), iVar4 == 0)) {
        pSVar5 = (Ship *)Status::getShip(Globals::status);
        iVar6 = Ship::getFreeSpace(pSVar5);
        iVar3 = *(int *)(this + 0x58);
        iVar4 = *(int *)(this + 0x70);
        if (iVar6 < 1) {
          pPVar12 = (PlayerEgo *)&DAT_0000001b;
          goto LAB_001a8740;
        }
        pPVar12 = (PlayerEgo *)0xb;
LAB_001a8a1a:
        Hud::hudEvent(iVar4,pPVar12,iVar3);
        pPVar12 = *(PlayerEgo **)(this + 0x58);
        pKVar7 = (KIPlayer *)Radar::getLockedAsteroid(*(Radar **)(this + 0x7c));
        PlayerEgo::dockToAsteroid(pPVar12,pKVar7,*(Radar **)(this + 0x7c));
        Hud::releaseAllKeys(*(Hud **)(this + 0x70));
        return;
      }
      iVar4 = PlayerEgo::isDockingToAsteroid(*(PlayerEgo **)pMVar15);
      if (iVar4 == 1) {
        iVar3 = *(int *)(this + 0x58);
        pPVar12 = (PlayerEgo *)0x6;
        iVar4 = *(int *)(this + 0x70);
        goto LAB_001a8a1a;
      }
      pPVar12 = *(PlayerEgo **)(this + 0x58);
      pKVar7 = (KIPlayer *)Radar::getLockedAsteroid(*(Radar **)(this + 0x7c));
      PlayerEgo::dockToAsteroid(pPVar12,pKVar7,*(Radar **)(this + 0x7c));
    }
  }
  else {
    pMVar15 = this + 0x58;
    iVar4 = PlayerEgo::isDockedToDockingPoint(*(PlayerEgo **)pMVar15);
    if (iVar4 != 0) goto LAB_001a860c;
    iVar4 = PlayerEgo::isAutoPilot(*(PlayerEgo **)pMVar15);
    if ((iVar4 == 0) && (iVar4 = PlayerEgo::isInTurretMode(*(PlayerEgo **)pMVar15), iVar4 == 0)) {
      PlayerEgo::setAutoPilot
                (*(PlayerEgo **)(this + 0x58),*(KIPlayer **)(*(int *)(this + 0x7c) + 0x24));
      iVar3 = *(int *)(*(int *)(this + 0x7c) + 0x24);
      iVar4 = Level::getLandmarks(*(Level **)(this + 0x74));
      if (iVar3 == **(int **)(iVar4 + 4)) {
        iVar3 = *(int *)(this + 0x58);
        pPVar12 = (PlayerEgo *)0xa;
        iVar4 = *(int *)(this + 0x70);
      }
      else {
        iVar13 = *(int *)(*(int *)(this + 0x7c) + 0x24);
        iVar6 = Level::getLandmarks(*(Level **)(this + 0x74));
        iVar3 = *(int *)(this + 0x58);
        iVar4 = *(int *)(this + 0x70);
        if (iVar13 == *(int *)(*(int *)(iVar6 + 4) + 0xc)) {
          pPVar12 = (PlayerEgo *)0xf;
        }
        else {
          pPVar12 = (PlayerEgo *)0xc;
        }
      }
      Hud::hudEvent(iVar4,pPVar12,iVar3);
      uVar17 = Hud::touchEnd(*(Hud **)(this + 0x70),param_1,param_2,param_3);
      *(undefined4 *)(this + 0xf4) = uVar17;
      return;
    }
    iVar4 = PlayerEgo::isInTurretMode(*(PlayerEgo **)pMVar15);
    if (iVar4 == 0) {
      Hud::hudEvent(*(int *)(this + 0x70),(PlayerEgo *)0x6,*(int *)(this + 0x58));
      PlayerEgo::setAutoPilot(*(PlayerEgo **)(this + 0x58),(KIPlayer *)0x0);
      iVar4 = *(int *)(this + 0x7c);
      *(undefined4 *)(iVar4 + 0x24) = 0;
      *(undefined4 *)(iVar4 + 0x28) = 0;
      PlayerEgo::resetGunDelay(*(PlayerEgo **)(this + 0x58));
    }
  }
  pMVar15 = this + 0x58;
  iVar4 = PlayerEgo::isMining(*(PlayerEgo **)pMVar15);
  if (iVar4 != 0) {
LAB_001a888a:
    iVar4 = PlayerEgo::isMining(*(PlayerEgo **)pMVar15);
    if (iVar4 != 1) {
      Hud::enableFireForTutorial(*(Hud **)(this + 0x70),false);
      lVar21 = Status::getPlayingTime(Globals::status);
      lVar20 = lVar21 - *(longlong *)(this + 0xf8);
      iVar4 = (int)((ulonglong)lVar20 >> 0x20);
      bVar16 = 0xf9 < (uint)lVar20;
      if ((int)(-(uint)bVar16 - iVar4) < 0 == (SBORROW4(0,iVar4) != SBORROW4(-iVar4,(uint)bVar16)))
      {
        this[0x5c] = (MGame)0x1;
        Hud::enableFireForTutorial(*(Hud **)(this + 0x70),true);
      }
      else {
        if (this[0x5c] != (MGame)0x0) {
          uVar17 = Hud::touchEnd(*(Hud **)(this + 0x70),param_1,param_2,param_3);
          *(undefined4 *)(this + 0xf4) = uVar17;
        }
        this[0x5c] = (MGame)0x0;
      }
      *(longlong *)(this + 0xf8) = lVar21;
      this[0x108] = (MGame)0x1;
      return;
    }
    *(undefined4 *)(Globals::status + 0x124) = 0;
    PlayerEgo::stopMining(*(PlayerEgo **)pMVar15);
    return;
  }
  if ((*(int *)(*(int *)(this + 0x7c) + 4) == 0) ||
     (*(char *)(*(int *)(*(int *)(this + 0x7c) + 4) + 0x6c) == '\0')) {
    iVar4 = PlayerEgo::isDockedToDockingPoint(*(PlayerEgo **)pMVar15);
    if (iVar4 != 1) goto LAB_001a888a;
    if (*(int *)(*(int *)(this + 0x7c) + 4) != 0) goto LAB_001a884c;
LAB_001a88f8:
    iVar4 = PlayerEgo::isDockingToDockingPoint(*(PlayerEgo **)pMVar15);
    if ((iVar4 == 0) &&
       ((iVar4 = PlayerEgo::isDockedToDockingPoint(*(PlayerEgo **)pMVar15), iVar4 != 1 ||
        (iVar4 = PlayerEgo::isInTurretMode(*(PlayerEgo **)pMVar15), iVar4 != 0))))
    goto LAB_001a898a;
    iVar4 = PlayerEgo::isDockedToDockingPoint(*(PlayerEgo **)pMVar15);
    if (iVar4 != 1) {
      iVar4 = PlayerEgo::isDockingToDockingPoint((PlayerEgo *)*(KIPlayer **)pMVar15);
      if ((iVar4 == 1) &&
         (iVar4 = PlayerEgo::isLandingOrTakingOff(*(PlayerEgo **)pMVar15), iVar4 == 0)) {
        Hud::hudEvent(*(int *)(this + 0x70),(PlayerEgo *)0x6,*(int *)pMVar15);
      }
      goto LAB_001a898a;
    }
    PlayerEgo::dockToDockingPoint(*(KIPlayer **)pMVar15,*(Radar **)(*(int *)(this + 0x7c) + 4));
    PlayerEgo::setAutoPilot(*(PlayerEgo **)pMVar15,(KIPlayer *)0x0);
    PlayerEgo::resetGunDelay(*(PlayerEgo **)pMVar15);
  }
  else {
LAB_001a884c:
    iVar4 = PlayerEgo::isDockingToDockingPoint(*(PlayerEgo **)pMVar15);
    if (((iVar4 != 0) ||
        (iVar4 = PlayerEgo::isDockedToDockingPoint(*(PlayerEgo **)pMVar15), iVar4 != 0)) ||
       (*(char *)(*(int *)(*(int *)(this + 0x7c) + 4) + 0x71) == '\0')) goto LAB_001a88f8;
    Hud::hudEvent(*(int *)(this + 0x70),(PlayerEgo *)0x22,*(int *)pMVar15);
    PlayerEgo::dockToDockingPoint(*(KIPlayer **)pMVar15,*(Radar **)(*(int *)(this + 0x7c) + 4));
  }
  Hud::releaseAllKeys(*(Hud **)(this + 0x70));
LAB_001a898a:
  Hud::enableFireForTutorial(*(Hud **)(this + 0x70),false);
  lVar21 = Status::getPlayingTime(Globals::status);
  lVar20 = lVar21 - *(longlong *)(this + 0xf8);
  iVar4 = (int)((ulonglong)lVar20 >> 0x20);
  bVar16 = 0xf9 < (uint)lVar20;
  if ((int)(-(uint)bVar16 - iVar4) < 0 == (SBORROW4(0,iVar4) != SBORROW4(-iVar4,(uint)bVar16))) {
    this[0x5c] = (MGame)0x1;
    Hud::enableFireForTutorial(*(Hud **)(this + 0x70),true);
  }
  else {
    if (this[0x5c] != (MGame)0x0) {
      uVar17 = Hud::touchEnd(*(Hud **)(this + 0x70),param_1,param_2,param_3);
      *(undefined4 *)(this + 0xf4) = uVar17;
    }
    this[0x5c] = (MGame)0x0;
  }
  *(longlong *)(this + 0xf8) = lVar21;
  return;
}

// ===== MGame::OnTouchMove  @0x001a9088  (626 bytes)
/* MGame::OnTouchMove(int, int, void*) */

void __thiscall MGame::OnTouchMove(MGame *this,int param_1,int param_2,void *param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint in_fpscr;
  float fVar4;
  undefined4 uVar5;
  undefined4 extraout_s1;
  undefined4 extraout_s1_00;
  undefined8 uVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  uint extraout_s7;
  uint extraout_s7_00;
  uint uVar10;
  
  if (((this[0x5d] == (MGame)0x0) ||
      (((this[0x156] != (MGame)0x0 &&
        (iVar2 = MenuTouchWindow::isShowingMessage(*(MenuTouchWindow **)(this + 0x84)), iVar2 == 0))
       && (iVar2 = MenuTouchWindow::isMakingScreenshot(*(MenuTouchWindow **)(this + 0x84)),
          iVar2 == 0)))) &&
     (((this[0x154] != (MGame)0x0 && (*(int *)(this + 0xf4) == 0)) && (*(int *)(this + 0x14) == 3)))
     ) {
    freeCamTouchMove(this,param_1,param_2,param_3);
  }
  else {
    if (this[0x5d] != (MGame)0x0) goto LAB_001a9238;
    iVar2 = Hud::touchMove(*(Hud **)(this + 0x70),param_1,param_2,param_3);
    *(int *)(this + 0xf4) = iVar2;
    if (*(uint *)(this + 0x14) < 2) {
      if (this[0x174] != (MGame)0x0) {
        fVar4 = (float)VectorSignedToFloat(Globals::h,(byte)(in_fpscr >> 0x16) & 3);
        iVar3 = param_2 - *(int *)(this + 0x17c);
        if (iVar3 < 0) {
          iVar3 = -iVar3;
        }
        fVar8 = (float)VectorSignedToFloat(iVar3,(byte)(in_fpscr >> 0x16) & 3);
        fVar4 = (fVar4 / 320.0) * 90.0;
        uVar10 = in_fpscr & 0xfffffff | (uint)(fVar8 < fVar4) << 0x1f |
                 (uint)(fVar8 == fVar4) << 0x1e;
        in_fpscr = uVar10 | (uint)(NAN(fVar8) || NAN(fVar4)) << 0x1c;
        bVar1 = (byte)(uVar10 >> 0x18);
        if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
          this[0x174] = (MGame)0x0;
          *(undefined4 *)(this + 0x170) = 0;
        }
      }
      if ((((*(ushort *)(this + 0x1b0) & 0xff) != 0) && (this[0x5f] == (MGame)0x0)) &&
         ((iVar2 == 0 || ((iVar2 == 0x20 && (*(void **)(this + 0xbc) != param_3)))))) {
        if (*(ushort *)(this + 0x1b0) < 0x100) {
          fVar4 = (float)VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
          fVar7 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x1c4),
                                             (byte)(in_fpscr >> 0x16) & 3);
          fVar9 = fVar4 - *(float *)(this + 0x1b8);
          in_fpscr = in_fpscr & 0xfffffff;
          fVar8 = -fVar9;
          if (0.0 < fVar9) {
            fVar8 = fVar9;
          }
          if (fVar8 <= fVar7) goto LAB_001a9230;
          iVar2 = -1;
          if (fVar4 < *(float *)(this + 0x1b8)) {
            iVar2 = 1;
          }
          uVar5 = VectorSignedToFloat(iVar2 + param_2,(byte)(in_fpscr >> 0x16) & 3);
          *(undefined4 *)(this + 0x1c0) = 0;
          *(undefined4 *)(this + 0x1b8) = uVar5;
          uVar5 = PlayerEgo::getThrust(*(PlayerEgo **)(this + 0x58));
          *(undefined4 *)(this + 0x1c8) = uVar5;
          uVar10 = extraout_s7_00;
          uVar5 = extraout_s1_00;
        }
        else {
          fVar4 = (float)VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
          uVar10 = extraout_s7;
          uVar5 = extraout_s1;
        }
        this[0x1b1] = (MGame)0x1;
        fVar8 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x1c0),
                                           (byte)(in_fpscr >> 0x16) & 3);
        uVar6 = FloatVectorMax(CONCAT44(uVar5,((*(float *)(this + 0x1b8) - fVar4) - fVar8) /
                                              *(float *)(Globals::layout + 0x2f8) +
                                              *(float *)(this + 0x1c8)),(ulonglong)uVar10 << 0x20,2,
                               0x20);
        PlayerEgo::setThrust(*(PlayerEgo **)(this + 0x58),(float)uVar6);
        PlayerEgo::throttleChanged(*(PlayerEgo **)(this + 0x58));
      }
    }
  }
LAB_001a9230:
  if (this[0x5d] == (MGame)0x0) {
    return;
  }
LAB_001a9238:
  if ((((this[0x60] != (MGame)0x0) || (this[0xc1] != (MGame)0x0)) || (this[0xca] != (MGame)0x0)) ||
     ((*(uint *)(this + 0xc0) & 0xff) != 0)) {
    ChoiceWindow::OnTouchMove(*(ChoiceWindow **)(this + 0x90),param_1,param_2);
    return;
  }
  if (0xffffff < *(uint *)(this + 0xc0)) {
    if (*Globals::layout == (Layout)0x0) {
      StarMap::OnTouchMove(*(StarMap **)(this + 0x8c),param_1,param_2);
      return;
    }
    Layout::OnTouchMove(Globals::layout,param_1,param_2);
    return;
  }
  if (this[0x5e] == (MGame)0x0) {
    if (((this[0xc5] != (MGame)0x0) &&
        (iVar2 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager),
        *(char *)(iVar2 + 5) == '\0')) && (*(char *)(iVar2 + 0xc) == '\0')) {
      MenuTouchWindow::OnTouchMove(*(MenuTouchWindow **)(this + 0x84),param_1,param_2,param_3);
      return;
    }
    return;
  }
  DialogueWindow::OnTouchMove(*(DialogueWindow **)(this + 0x88),param_1,param_2);
  return;
}

// ===== MGame::useCloak  @0x001a930c  (274 bytes)
/* MGame::useCloak() */

void __thiscall MGame::useCloak(MGame *this)

{
  int iVar1;
  ChoiceWindow *pCVar2;
  Ship *this_00;
  Item *this_01;
  String *pSVar3;
  undefined4 extraout_r1;
  String aSStack_58 [8];
  undefined4 local_50 [2];
  String aSStack_48 [8];
  AbyssEngine aAStack_40 [8];
  AbyssEngine aAStack_38 [8];
  AbyssEngine aAStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  iVar1 = PlayerEgo::toggleCloaking();
  if (iVar1 == 0) {
    if (*(int *)(this + 0x90) == 0) {
      pCVar2 = operator_new(0x54);
      ChoiceWindow::ChoiceWindow(pCVar2);
      *(ChoiceWindow **)(this + 0x90) = pCVar2;
    }
    this_00 = (Ship *)Status::getShip(Globals::status);
    this_01 = (Item *)Ship::getFirstEquipmentOfSort(this_00,0x15);
    if (this_01 != (Item *)0x0) {
      Item::getAttribute(this_01,0x26);
    }
    pCVar2 = *(ChoiceWindow **)(this + 0x90);
    pSVar3 = (String *)GameText::getText(Globals::gameText,0x247);
    AbyssEngine::String::String(aSStack_48," ",false);
    AbyssEngine::operator+(aAStack_40,pSVar3,aSStack_48);
    local_50[0] = 0;
    AbyssEngine::String::Set(CONCAT44(extraout_r1,local_50));
    AbyssEngine::operator+(aAStack_38,aAStack_40,(String *)local_50);
    AbyssEngine::String::String(aSStack_58,".",false);
    AbyssEngine::operator+(aAStack_30,aAStack_38,aSStack_58);
    ChoiceWindow::set(pCVar2,aAStack_30);
    AbyssEngine::String::~String((String *)aAStack_30);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String((String *)aAStack_38);
    AbyssEngine::String::~String((String *)local_50);
    AbyssEngine::String::~String((String *)aAStack_40);
    AbyssEngine::String::~String(aSStack_48);
    this[0xca] = (MGame)0x1;
    this[0x5d] = (MGame)0x1;
    pauseSounds(this);
  }
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== MGame::UseKhadorDrive  @0x001a9480  (594 bytes)
/* MGame::UseKhadorDrive() */

void __thiscall MGame::UseKhadorDrive(MGame *this)

{
  int iVar1;
  Mission *pMVar2;
  Station *this_00;
  int iVar3;
  String *pSVar4;
  StarMap *this_01;
  Engine *this_02;
  ChoiceWindow *this_03;
  
  iVar1 = PlayerEgo::isChargingDrive(*(PlayerEgo **)(this + 0x58));
  if (iVar1 != 0) {
    return;
  }
  pMVar2 = (Mission *)Status::getMission(Globals::status);
  iVar1 = Mission::isEmpty(pMVar2);
  if (((((iVar1 == 0) && (iVar1 = Status::getCurrentCampaignMission(Globals::status), iVar1 != 0x4e)
        ) && (iVar1 = Mission::getType(pMVar2), iVar1 != 0xb)) &&
      ((iVar1 = Mission::getType(pMVar2), iVar1 != 0 &&
       (iVar1 = Mission::getType(pMVar2), iVar1 != 0xbd)))) &&
     ((iVar1 = Mission::getType(pMVar2), iVar1 != 0xd &&
      ((iVar1 = Mission::getType(pMVar2), iVar1 != 0xab &&
       (iVar1 = Mission::getType(pMVar2), iVar1 != 0xac)))))) {
LAB_001a9530:
    iVar3 = *(int *)(this + 0x70);
    iVar1 = Level::getPlayer(*(Level **)(this + 0x74));
    Hud::hudEvent(iVar3,(PlayerEgo *)0x15,iVar1);
    return;
  }
  iVar1 = Status::getCurrentCampaignMission(Globals::status);
  if ((iVar1 == 0x41) && (iVar1 = Status::inAlienOrbit(Globals::status), iVar1 == 0)) {
    this_00 = (Station *)Status::getStation(Globals::status);
    iVar1 = Station::getIndex(this_00);
    pMVar2 = (Mission *)Status::getCampaignMission(Globals::status);
    iVar3 = Mission::getTargetStation(pMVar2);
    if (iVar1 == iVar3) goto LAB_001a9530;
  }
  PlayerEgo::resetGunDelay(*(PlayerEgo **)(this + 0x58));
  iVar1 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar1 == 0x4e) {
    Level::programmedStation = *(undefined4 *)(Globals::status + 0x78);
    this[0xd9] = (MGame)0x1;
    startChargingJumpDrive(this);
    this[0x5d] = (MGame)0x0;
    resumeSounds(this);
    this[0xd2] = (MGame)0x0;
    Hud::closeHudMenu(*(Hud **)(this + 0x70));
    Status::nextCampaignMission(SUB41(Globals::status,0));
    return;
  }
  iVar1 = Status::inAlienOrbit(Globals::status);
  if (iVar1 == 1) {
    iVar1 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar1 == 0x50) {
      iVar1 = 100;
      *(undefined4 *)(Globals::status + 0x84) = 100;
    }
    else {
      iVar1 = *(int *)(Globals::status + 0x84);
    }
    Level::programmedStation = Galaxy::getStation(Globals::galaxy,iVar1);
    this[0xd9] = (MGame)0x1;
    startChargingJumpDrive(this);
    this[0x5d] = (MGame)0x0;
    resumeSounds(this);
  }
  else {
    iVar1 = PlayerEgo::hasVolatileGoods(*(PlayerEgo **)(this + 0x58));
    if (iVar1 == 1) {
      this_03 = *(ChoiceWindow **)(this + 0x90);
      pSVar4 = (String *)GameText::getText(Globals::gameText,0x264);
      ChoiceWindow::set(this_03,pSVar4);
      this[0xca] = (MGame)0x1;
      this[0x5d] = (MGame)0x1;
      this[0x109] = (MGame)0x1;
      this[0xd2] = (MGame)0x0;
      Hud::closeHudMenu(*(Hud **)(this + 0x70));
      pauseSounds(this);
      this[0x174] = (MGame)0x0;
      return;
    }
    if (*(int *)(this + 0x8c) == 0) {
      this_01 = operator_new(0x1e8);
      StarMap::StarMap(this_01,false,(Mission *)0x0,false,-1);
      *(StarMap **)(this + 0x8c) = this_01;
    }
    this_02 = (Engine *)
              AbyssEngine::ApplicationManager::GetEngine(*(ApplicationManager **)(this + 8));
    AbyssEngine::Engine::SetPostEffect(this_02,0x1400002,false);
    StarMap::initLights();
    this[0xd9] = (MGame)0x1;
    StarMap::setJumpMapMode(*(StarMap **)(this + 0x8c),true,true);
    iVar1 = Status::inAlienOrbit(Globals::status);
    if (iVar1 == 0) {
      StarMap::askForJumpIntoAlienWorld(*(StarMap **)(this + 0x8c));
    }
    this[0xc3] = (MGame)0x1;
    this[0x5d] = (MGame)0x1;
    pauseSounds(this);
  }
  this[0xd2] = (MGame)0x0;
  Hud::closeHudMenu(*(Hud **)(this + 0x70));
  return;
}

// ===== MGame::startChargingJumpDrive  @0x001a9710  (384 bytes)
/* MGame::startChargingJumpDrive() */

void __thiscall MGame::startChargingJumpDrive(MGame *this)

{
  Ship *pSVar1;
  int iVar2;
  int iVar3;
  Item *this_00;
  ChoiceWindow *pCVar4;
  String *pSVar5;
  int iVar6;
  
  if (this[0xd9] != (MGame)0x0) {
    pSVar1 = (Ship *)Status::getShip(Globals::status);
    iVar6 = 1;
    iVar2 = Ship::hasCargo(pSVar1,0x7a,1);
    if (iVar2 == 0) {
      pCVar4 = *(ChoiceWindow **)(this + 0x90);
      if (pCVar4 == (ChoiceWindow *)0x0) {
        pCVar4 = operator_new(0x54);
        ChoiceWindow::ChoiceWindow(pCVar4);
        *(ChoiceWindow **)(this + 0x90) = pCVar4;
      }
      pSVar5 = (String *)GameText::getText(Globals::gameText,0x243);
      ChoiceWindow::set(pCVar4,pSVar5);
      this[0xca] = (MGame)0x1;
      this[0x5d] = (MGame)0x1;
      pauseSounds(this);
    }
    else {
      iVar2 = Status::hardCoreMode();
      if (iVar2 != 0) {
        iVar6 = 2;
      }
      if (Level::programmedStation == *(int *)(Globals::status + 0x78)) {
        iVar2 = iVar6 << 1;
      }
      else {
        iVar3 = Status::inAlienOrbit(Globals::status);
        iVar2 = Level::energyCellsForNextJump;
        if (iVar3 != 0) {
          iVar2 = iVar6;
        }
      }
      pSVar1 = (Ship *)Status::getShip(Globals::status);
      this_00 = (Item *)Ship::getCargo(pSVar1,0x7a);
      iVar3 = Item::getAmount(this_00);
      if (iVar2 <= iVar3) {
        PlayerEgo::startJumpDrive();
        if ((Level::programmedStation != *(int *)(Globals::status + 0x78)) &&
           (iVar2 = Status::inAlienOrbit(Globals::status), iVar2 == 0)) {
          iVar6 = Level::energyCellsForNextJump;
        }
        Hud::hudEvent(*(int *)(this + 0x70),(PlayerEgo *)0x1e,*(int *)(this + 0x58));
        pSVar1 = (Ship *)Status::getShip(Globals::status);
        Ship::removeCargo(pSVar1,0x7a,iVar6);
        return;
      }
      if (*(int *)(this + 0x90) == 0) {
        pCVar4 = operator_new(0x54);
        ChoiceWindow::ChoiceWindow(pCVar4);
        *(ChoiceWindow **)(this + 0x90) = pCVar4;
      }
      iVar6 = Status::hardCoreMode();
      pCVar4 = *(ChoiceWindow **)(this + 0x90);
      if (iVar6 == 1) {
        iVar6 = 0x243;
      }
      else {
        iVar6 = 0x244;
      }
      pSVar5 = (String *)GameText::getText(Globals::gameText,iVar6);
      ChoiceWindow::set(pCVar4,pSVar5);
      this[0xca] = (MGame)0x1;
      this[0x5d] = (MGame)0x1;
      pauseSounds(this);
    }
    Level::programmedStation = 0;
  }
  return;
}

// ===== MGame::OnTouchEnd  @0x001a98d8  (8834 bytes)
/* MGame::OnTouchEnd(int, int, void*) */

void __thiscall MGame::OnTouchEnd(MGame *this,int param_1,int param_2,void *param_3)

{
  MGame MVar1;
  Layout *pLVar2;
  bool bVar3;
  undefined1 uVar4;
  byte bVar5;
  char cVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  Ship *pSVar10;
  int iVar11;
  int iVar12;
  Item *pIVar13;
  String *pSVar14;
  StarMap *this_00;
  Engine *this_01;
  uint uVar15;
  KIPlayer *pKVar16;
  Route *this_02;
  undefined4 uVar17;
  Radar *pRVar18;
  FileRead *pFVar19;
  Station *pSVar20;
  void *pvVar21;
  StarSystem *pSVar22;
  Status *pSVar23;
  Mission *pMVar24;
  Hud *this_03;
  uint *puVar25;
  undefined4 extraout_r1;
  uint extraout_r1_00;
  uint extraout_r1_01;
  uint extraout_r1_02;
  uint extraout_r1_03;
  uint uVar26;
  uint extraout_r1_04;
  uint extraout_r1_05;
  uint uVar27;
  void *extraout_r2;
  void *extraout_r2_00;
  void *extraout_r2_01;
  void *extraout_r2_02;
  int extraout_r2_03;
  void *extraout_r2_04;
  void *extraout_r2_05;
  void *extraout_r2_06;
  void *extraout_r2_07;
  void *extraout_r2_08;
  void *extraout_r2_09;
  void *extraout_r2_10;
  void *extraout_r2_11;
  void *extraout_r2_12;
  void *extraout_r2_13;
  void *extraout_r2_14;
  void *extraout_r2_15;
  void *extraout_r2_16;
  void *extraout_r2_17;
  void *extraout_r2_18;
  void *extraout_r2_19;
  void *extraout_r2_20;
  void *extraout_r2_21;
  Level *pLVar28;
  ChoiceWindow *this_04;
  String *pSVar29;
  PlayerEgo *pPVar30;
  AEGeometry *this_05;
  MenuTouchWindow *pMVar31;
  int iVar32;
  MGame *pMVar33;
  code *pcVar34;
  int iVar35;
  float fVar36;
  float extraout_s0;
  undefined8 uVar37;
  String aSStack_94 [8];
  undefined4 local_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  String aSStack_74 [12];
  String aSStack_68 [8];
  undefined4 local_60 [2];
  String aSStack_58 [8];
  AbyssEngine aAStack_50 [8];
  AbyssEngine aAStack_48 [8];
  String aSStack_40 [8];
  String aSStack_38 [8];
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (*(void **)(this + 0xbc) == param_3) {
    *(undefined4 *)(this + 0xbc) = 0;
  }
  iVar8 = PlayerEgo::isAutoPilot(*(PlayerEgo **)(this + 0x58));
  *(undefined4 *)(this + 0x160) = 0x3f800000;
  TargetFollowCamera::setFastForwardMode(*(TargetFollowCamera **)(this + 0xf0),false);
  *(undefined1 *)(*(int *)(this + 0x58) + 0x84) = 1;
  if (this[0x5d] == (MGame)0x0) {
LAB_001a9f2c:
    uVar15 = Hud::touchEnd(*(Hud **)(this + 0x70),param_1,param_2,param_3);
    *(uint *)(this + 0xf4) = uVar15;
    if (uVar15 != 0) {
      *(undefined4 *)(this + 0x94) = 0;
      *(undefined4 *)(this + 0x98) = 0;
      if ((uVar15 & 1) != 0) {
        pauseSounds(this);
        if (this[0x5d] == (MGame)0x0) {
          pMVar31 = *(MenuTouchWindow **)(this + 0x84);
          if (pMVar31 == (MenuTouchWindow *)0x0) {
            pMVar31 = operator_new(0x240);
            MenuTouchWindow::MenuTouchWindow(pMVar31,1);
            *(MenuTouchWindow **)(this + 0x84) = pMVar31;
          }
          bVar3 = (bool)LevelScript::canSkipCutsceneNow(*(LevelScript **)(this + 0x78));
          MenuTouchWindow::setSkipButtonVisible(pMVar31,bVar3);
          this[0x5d] = (MGame)0x1;
          pauseSounds(this);
          this[0x19e] = this[0x5d];
          bVar5 = FModSound::IsCategoryEnabled(Globals::sound,2);
          this[0x19c] = (MGame)(bVar5 ^ 1);
          FModSound::pauseAllPlaying(Globals::sound);
          PlayerEgo::PauseEngineSound(*(PlayerEgo **)(this + 0x58));
          puVar25 = (uint *)Level::getEnemies(*(Level **)(this + 0x74));
          if ((puVar25 != (uint *)0x0) && (*puVar25 != 0)) {
            uVar15 = 0;
            do {
              KIPlayer::PauseEngineSound(*(KIPlayer **)(puVar25[1] + uVar15 * 4));
              uVar15 = uVar15 + 1;
            } while (uVar15 < *puVar25);
          }
          pMVar31 = *(MenuTouchWindow **)(this + 0x84);
          uVar4 = true;
          if (this[0x5f] == (MGame)0x0) {
            uVar4 = PlayerEgo::isDead(*(PlayerEgo **)(this + 0x58));
          }
          fVar36 = (float)MenuTouchWindow::setCutsceneMode(pMVar31,(bool)uVar4);
          this[0xc5] = (MGame)0x1;
          FModSound::play(Globals::sound,0x7b,(Vector *)0x0,(Vector *)0x0,fVar36);
        }
        Hud::releaseAllKeys(*(Hud **)(this + 0x70));
        goto LAB_001abc1a;
      }
    }
    iVar9 = LevelScript::startSequence(*(LevelScript **)(this + 0x78));
    if ((iVar9 == 0) && (iVar9 = PlayerEgo::isDead(*(PlayerEgo **)(this + 0x58)), iVar9 != 1)) {
      if ((this[0x5f] == (MGame)0x0) && (this[0xd8] == (MGame)0x0)) {
        if ((((byte)this[0xf4] & 2) != 0) &&
           ((((iVar9 = PlayerEgo::isBoostRefreshed(*(PlayerEgo **)(this + 0x58)), iVar9 != 0 &&
              (iVar9 = PlayerEgo::boosting(*(PlayerEgo **)(this + 0x58)), iVar9 == 0)) &&
             (iVar9 = PlayerEgo::isMining(*(PlayerEgo **)(this + 0x58)), iVar9 == 0)) &&
            (iVar9 = PlayerEgo::isDockedToDockingPoint(*(PlayerEgo **)(this + 0x58)), iVar9 == 0))))
        {
          PlayerEgo::setThrust(*(PlayerEgo **)(this + 0x58),extraout_s0);
          *(undefined4 *)(this + 0x1a8) = 0x3f800000;
          *(undefined4 *)(this + 0x1ac) = 0x42c80000;
          iVar9 = AbyssEngine::ApplicationManager::GetEngine(*(ApplicationManager **)(this + 8));
          *(undefined4 *)(iVar9 + 0x350) = 0;
          PlayerEgo::boost(*(PlayerEgo **)(this + 0x58));
        }
        if ((((((byte)this[0xf4] & 8) != 0) &&
             (iVar9 = Player::gunAvailable((Player *)**(undefined4 **)(this + 0x58),1), iVar9 == 1))
            && ((iVar9 = PlayerEgo::isMining(*(PlayerEgo **)(this + 0x58)), iVar9 == 0 &&
                ((iVar9 = PlayerEgo::isInTurretMode(*(PlayerEgo **)(this + 0x58)), iVar9 == 0 &&
                 (iVar9 = PlayerEgo::isDockedToDockingPoint(*(PlayerEgo **)(this + 0x58)),
                 iVar9 == 0)))))) &&
           (iVar9 = PlayerEgo::isLandingOrTakingOff(*(PlayerEgo **)(this + 0x58)), iVar9 == 0)) {
          PlayerEgo::shoot(*(PlayerEgo **)(this + 0x58),*(int *)(this + 0x40),1);
          Hud::checkIfQuickMenuIsEmpty(*(Hud **)(this + 0x70));
        }
        iVar9 = PlayerEgo::isHacking(*(PlayerEgo **)(this + 0x58));
        if (iVar9 == 1) {
          uVar15 = *(uint *)(this + 0xf4);
          if ((uVar15 & 0x200) != 0) {
            PlayerEgo::hackingRotateLCW(*(PlayerEgo **)(this + 0x58));
            uVar15 = *(uint *)(this + 0xf4);
          }
          if ((uVar15 & 0x400) != 0) {
            PlayerEgo::hackingRotateRCW(*(PlayerEgo **)(this + 0x58));
          }
        }
        iVar9 = PlayerEgo::isInRocketControl(*(PlayerEgo **)(this + 0x58));
        if (iVar9 == 0) {
          iVar9 = PlayerEgo::hasAutoTurret(*(PlayerEgo **)(this + 0x58));
          pvVar21 = extraout_r2;
          if ((iVar9 == 1) && (((byte)this[0xf7] & 0x20) != 0)) {
            pPVar30 = *(PlayerEgo **)(this + 0x58);
            bVar5 = PlayerEgo::autoTurretIsEnabled(pPVar30);
            PlayerEgo::setAutoTurret(pPVar30,(bool)(bVar5 ^ 1));
            iVar35 = *(int *)(this + 0x70);
            iVar9 = PlayerEgo::autoTurretIsEnabled(*(PlayerEgo **)(this + 0x58));
            pPVar30 = (PlayerEgo *)0x21;
            if (iVar9 != 0) {
              pPVar30 = (PlayerEgo *)0x20;
            }
            Hud::hudEvent(iVar35,pPVar30,*(int *)(this + 0x58));
            pvVar21 = extraout_r2_00;
          }
          uVar15 = *(uint *)(this + 0xf4);
          if ((uVar15 & 0x40) == 0) {
            uVar26 = 0;
            if (this[0xc4] != (MGame)0x0) {
              if ((uVar15 & 0x200000) != 0) {
                LevelScript::setAutoPilotToProgrammedStation(*(LevelScript **)(this + 0x78));
                uVar15 = *(uint *)(this + 0xf4);
              }
              if ((uVar15 & 0x400000) != 0) {
                pPVar30 = *(PlayerEgo **)(this + 0x58);
                iVar9 = Level::getLandmarks(*(Level **)(this + 0x74));
                PlayerEgo::setAutoPilot(pPVar30,*(KIPlayer **)(*(int *)(iVar9 + 4) + 4));
                Hud::hudEvent(*(int *)(this + 0x70),(PlayerEgo *)0xc,*(int *)(this + 0x58));
                uVar15 = *(uint *)(this + 0xf4);
              }
              if ((uVar15 & 0x800000) != 0) {
                pPVar30 = *(PlayerEgo **)(this + 0x58);
                iVar9 = Level::getLandmarks(*(Level **)(this + 0x74));
                PlayerEgo::setAutoPilot(pPVar30,(KIPlayer *)**(undefined4 **)(iVar9 + 4));
                Hud::hudEvent(*(int *)(this + 0x70),(PlayerEgo *)0xa,*(int *)(this + 0x58));
                uVar15 = *(uint *)(this + 0xf4);
              }
              if ((uVar15 & 0x1000000) != 0) {
                pPVar30 = *(PlayerEgo **)(this + 0x58);
                pKVar16 = (KIPlayer *)Level::getAsteroidWaypoint(*(Level **)(this + 0x74));
                PlayerEgo::setAutoPilot(pPVar30,pKVar16);
                Hud::hudEvent(*(int *)(this + 0x70),(PlayerEgo *)0xe,*(int *)(this + 0x58));
                uVar15 = *(uint *)(this + 0xf4);
              }
              if (((uVar15 & 0x2000000) != 0) &&
                 (iVar9 = Level::getPlayerRoute(*(Level **)(this + 0x74)), iVar9 != 0)) {
                pPVar30 = *(PlayerEgo **)(this + 0x58);
                this_02 = (Route *)Level::getPlayerRoute(*(Level **)(this + 0x74));
                pKVar16 = (KIPlayer *)Route::getWaypoint(this_02);
                PlayerEgo::setAutoPilot(pPVar30,pKVar16);
                Hud::hudEvent(*(int *)(this + 0x70),(PlayerEgo *)0xd,*(int *)(this + 0x58));
              }
              iVar9 = Level::getNumDockingTargets(*(Level **)(this + 0x74));
              if (0 < iVar9) {
                uVar15 = 0;
                do {
                  if (((*(uint *)(this + 0xf4) & 0x4000000 << (uVar15 & 0xff)) != 0) &&
                     (iVar9 = Level::getDockingTarget(*(Level **)(this + 0x74),uVar15), iVar9 != 0))
                  {
                    uVar17 = Level::getDockingTarget(*(Level **)(this + 0x74),uVar15);
                    *(undefined4 *)(*(int *)(this + 0x7c) + 4) = uVar17;
                    Hud::hudEvent(*(int *)(this + 0x70),(PlayerEgo *)0x22,*(int *)(this + 0x58));
                    pKVar16 = *(KIPlayer **)(this + 0x58);
                    pRVar18 = (Radar *)Level::getDockingTarget(*(Level **)(this + 0x74),uVar15);
                    PlayerEgo::dockToDockingPoint(pKVar16,pRVar18);
                    iVar9 = *(int *)(this + 0x7c);
                    *(undefined4 *)(iVar9 + 8) = 0;
                    *(undefined4 *)(iVar9 + 0xc) = 0;
                    *(undefined4 *)(iVar9 + 0x10) = 0;
                    Hud::releaseAllKeys(*(Hud **)(this + 0x70));
                  }
                  uVar15 = uVar15 + 1;
                  iVar9 = Level::getNumDockingTargets(*(Level **)(this + 0x74));
                } while ((int)uVar15 < iVar9);
              }
              goto LAB_001aa316;
            }
          }
          else {
            iVar9 = Status::inAlienOrbit(Globals::status);
            if ((iVar9 == 1) &&
               (iVar9 = PlayerEgo::isDockingToAsteroid(*(PlayerEgo **)(this + 0x58)), iVar9 == 1)) {
              PlayerEgo::dockToAsteroid
                        (*(PlayerEgo **)(this + 0x58),(KIPlayer *)0x0,*(Radar **)(this + 0x7c));
            }
            iVar9 = Status::inAlienOrbit(Globals::status);
            if (iVar9 == 1) {
              uVar37 = Status::inAlienOrbit(Globals::status);
              uVar26 = (uint)((ulonglong)uVar37 >> 0x20);
              pvVar21 = extraout_r2_04;
              if ((int)uVar37 == 1) {
                uVar37 = Status::getCurrentCampaignMission(Globals::status);
                uVar26 = (uint)((ulonglong)uVar37 >> 0x20);
                pvVar21 = extraout_r2_05;
                if ((int)uVar37 == 0x9a) {
                  uVar37 = Level::getNumDockingTargets(*(Level **)(this + 0x74));
                  uVar26 = (uint)((ulonglong)uVar37 >> 0x20);
                  pvVar21 = extraout_r2_06;
                  if (0 < (int)uVar37) goto LAB_001aa4d4;
                }
              }
            }
            else {
LAB_001aa4d4:
              uVar37 = Status::getCurrentCampaignMission(Globals::status);
              uVar26 = (uint)((ulonglong)uVar37 >> 0x20);
              pvVar21 = extraout_r2_07;
              if (1 < (int)uVar37) {
                uVar37 = Status::getCurrentCampaignMission(Globals::status);
                uVar26 = (uint)((ulonglong)uVar37 >> 0x20);
                pvVar21 = extraout_r2_08;
                if ((int)uVar37 != 0x30) {
                  uVar37 = PlayerEgo::isDockedToDockingPoint(*(PlayerEgo **)(this + 0x58));
                  uVar26 = (uint)((ulonglong)uVar37 >> 0x20);
                  pvVar21 = extraout_r2_09;
                  if ((int)uVar37 == 0) {
                    uVar37 = PlayerEgo::isLandingOrTakingOff(*(PlayerEgo **)(this + 0x58));
                    uVar26 = (uint)((ulonglong)uVar37 >> 0x20);
                    pvVar21 = extraout_r2_10;
                    if ((int)uVar37 == 0) {
                      if (this[0xc4] == (MGame)0x0) {
                        uVar37 = PlayerEgo::isMining(*(PlayerEgo **)(this + 0x58));
                        uVar26 = (uint)((ulonglong)uVar37 >> 0x20);
                        if ((int)uVar37 == 0) {
                          uVar37 = PlayerEgo::isAutoPilot(*(PlayerEgo **)(this + 0x58));
                          uVar26 = (uint)((ulonglong)uVar37 >> 0x20);
                          if ((int)uVar37 == 1) {
                            PlayerEgo::setAutoPilot(*(PlayerEgo **)(this + 0x58),(KIPlayer *)0x0);
                          }
                          else {
                            pvVar21 = extraout_r2_12;
                            if (this[0xc4] != (MGame)0x0) goto LAB_001aba3c;
                            iVar9 = PlayerEgo::isDockingToAsteroid(*(PlayerEgo **)(this + 0x58));
                            pPVar30 = *(PlayerEgo **)(this + 0x58);
                            if (iVar9 == 1) {
                              pKVar16 = (KIPlayer *)
                                        Radar::getLockedAsteroid(*(Radar **)(this + 0x7c));
                              pRVar18 = *(Radar **)(this + 0x7c);
                            }
                            else {
                              iVar9 = PlayerEgo::isDockingToDockingPoint(pPVar30);
                              if (iVar9 == 1) {
                                *(undefined4 *)(*(int *)(this + 0x7c) + 4) = 0;
                                PlayerEgo::dockToDockingPoint
                                          (*(KIPlayer **)(this + 0x58),(Radar *)0x0);
                                goto LAB_001ab50e;
                              }
                              iVar9 = PlayerEgo::isDockingToStream(*(PlayerEgo **)(this + 0x58));
                              if (iVar9 != 1) {
                                iVar9 = Status::inAlienOrbit(Globals::status);
                                if (iVar9 == 1) {
                                  uVar37 = Status::inAlienOrbit(Globals::status);
                                  uVar26 = (uint)((ulonglong)uVar37 >> 0x20);
                                  pvVar21 = extraout_r2_14;
                                  if ((int)uVar37 == 1) {
                                    uVar37 = Status::getCurrentCampaignMission(Globals::status);
                                    uVar26 = (uint)((ulonglong)uVar37 >> 0x20);
                                    pvVar21 = extraout_r2_15;
                                    if ((int)uVar37 == 0x9a) goto LAB_001ab9f8;
                                  }
                                }
                                else {
LAB_001ab9f8:
                                  iVar9 = Status::getMission(Globals::status);
                                  if (iVar9 != 0) {
                                    pMVar24 = (Mission *)Status::getMission(Globals::status);
                                    uVar37 = Mission::getType(pMVar24);
                                    uVar26 = (uint)((ulonglong)uVar37 >> 0x20);
                                    pvVar21 = extraout_r2_16;
                                    if ((int)uVar37 == 0xb7) goto LAB_001aba3c;
                                  }
                                  this[0xd2] = (MGame)0x1;
                                  this[0x5d] = (MGame)0x1;
                                  pauseSounds(this);
                                  Hud::initHudMenu(*(Hud **)(this + 0x70),3,*(Level **)(this + 0x74)
                                                  );
                                  this[0xc4] = (MGame)0x1;
                                  uVar26 = extraout_r1_03;
                                  pvVar21 = extraout_r2_17;
                                }
                                goto LAB_001aba3c;
                              }
                              pRVar18 = *(Radar **)(this + 0x7c);
                              pPVar30 = *(PlayerEgo **)(this + 0x58);
                              pKVar16 = *(KIPlayer **)(pRVar18 + 0x24);
                            }
                            PlayerEgo::dockToAsteroid(pPVar30,pKVar16,pRVar18);
                          }
LAB_001ab50e:
                          Hud::hudEvent(*(int *)(this + 0x70),(PlayerEgo *)0x6,*(int *)(this + 0x58)
                                       );
                          uVar26 = extraout_r1_02;
                          pvVar21 = extraout_r2_13;
                          goto LAB_001aba3c;
                        }
                        pvVar21 = extraout_r2_11;
                        if (this[0xc4] == (MGame)0x0) goto LAB_001aba3c;
                      }
LAB_001aa316:
                      this[0xc4] = (MGame)0x0;
                      this[0xd2] = (MGame)0x0;
                      this[0x5d] = (MGame)0x0;
                      resumeSounds(this);
                      Hud::closeHudMenu(*(Hud **)(this + 0x70));
                      uVar26 = extraout_r1_00;
                      pvVar21 = extraout_r2_01;
                      if (*(PlayerEgo **)(this + 0x58) != (PlayerEgo *)0x0) {
                        PlayerEgo::resetGunDelay(*(PlayerEgo **)(this + 0x58));
                        uVar26 = extraout_r1_01;
                        pvVar21 = extraout_r2_02;
                      }
                    }
                  }
                }
              }
            }
          }
LAB_001aba3c:
          if (((byte)this[0xf4] & 4) != 0) {
            uVar37 = PlayerEgo::isMining(*(PlayerEgo **)(this + 0x58));
            uVar26 = (uint)((ulonglong)uVar37 >> 0x20);
            pvVar21 = extraout_r2_18;
            if ((int)uVar37 == 0) {
              MVar1 = this[0xd2];
              this[0xd2] = (MGame)((byte)MVar1 ^ 1);
              uVar26 = (byte)this[0x5d] ^ 1;
              this[0x5d] = SUB41(uVar26,0);
              if (MVar1 == (MGame)0x0) {
                pauseSounds(this);
                Hud::initHudMenu(*(Hud **)(this + 0x70),0,*(Level **)(this + 0x74));
                uVar26 = extraout_r1_04;
                pvVar21 = extraout_r2_19;
              }
            }
          }
          if (((byte)this[0xf4] & 0x80) != 0) {
            uVar37 = PlayerEgo::isMining(*(PlayerEgo **)(this + 0x58));
            uVar26 = (uint)((ulonglong)uVar37 >> 0x20);
            pvVar21 = extraout_r2_20;
            if ((int)uVar37 == 0) {
              switchCamera(this,*(int *)(this + 0x14) + 1);
              uVar26 = extraout_r1_05;
              pvVar21 = extraout_r2_21;
            }
          }
          if (this[0xd2] == (MGame)0x0) {
            if (*(int *)(this + 0x14) == 0) {
              maneuverTouchEnd((int)this,param_1,pvVar21);
              *(undefined2 *)(this + 0x1b0) = 0;
            }
            else if (*(int *)(this + 0x14) == 3) {
              freeCamTouchEnd(this,uVar26,(int)pvVar21,param_3);
            }
          }
          else {
            uVar15 = *(uint *)(this + 0xf4);
            if ((uVar15 & 0x200) == 0) {
              if ((uVar15 & 0x800) == 0) {
                if ((uVar15 & 0x400) == 0) {
                  if ((uVar15 & 0x2000) == 0) {
                    if ((uVar15 & 0x4000) == 0) {
                      if ((uVar15 & 0x8000) == 0) {
                        if ((uVar15 & 0x10000) == 0) {
                          if ((uVar15 & 0x20000) == 0) {
                            if ((uVar15 & 0x40000) == 0) {
                              if ((uVar15 & 0x80000) == 0) {
                                if ((uVar15 & 0x100000) == 0) {
                                  if ((uVar15 & 0x1000) != 0) {
                                    UseKhadorDrive(this);
                                  }
                                  goto LAB_001abb5a;
                                }
                                iVar9 = 0;
                                Globals::status[0xf8] = (Status)((byte)Globals::status[0xf8] ^ 1);
                              }
                              else {
                                iVar9 = 2;
                              }
                            }
                            else {
                              iVar9 = 3;
                            }
                          }
                          else {
                            iVar9 = 1;
                          }
                          puVar25 = (uint *)Level::getEnemies(*(Level **)(this + 0x74));
                          if ((puVar25 != (uint *)0x0) && (*puVar25 != 0)) {
                            uVar15 = 0;
                            do {
                              pKVar16 = *(KIPlayer **)(puVar25[1] + uVar15 * 4);
                              iVar35 = KIPlayer::isWingMan(pKVar16);
                              if ((iVar35 == 1) && (iVar35 = KIPlayer::isDead(pKVar16), iVar35 == 0)
                                 ) {
                                pcVar34 = *(code **)(*(int *)pKVar16 + 0x10);
                                if (iVar9 == 3) {
                                  uVar17 = Radar::getLockedEnemy(*(Radar **)(this + 0x7c));
                                }
                                else {
                                  uVar17 = 0;
                                }
                                (*pcVar34)(pKVar16,iVar9,uVar17);
                              }
                              uVar15 = uVar15 + 1;
                            } while (uVar15 < *puVar25);
                          }
                          this[0xd2] = (MGame)0x0;
                          Hud::closeHudMenu(*(Hud **)(this + 0x70));
                          this[0x5d] = (MGame)0x0;
                          resumeSounds(this);
                          goto LAB_001abb5a;
                        }
                        iVar9 = 3;
                      }
                      else {
                        iVar9 = 2;
                      }
                    }
                    else {
                      iVar9 = 1;
                    }
                  }
                  else {
                    iVar9 = 0;
                  }
                  pSVar10 = (Ship *)Status::getShip(Globals::status);
                  iVar35 = Ship::getEquipment(pSVar10,1);
                  if (iVar35 != 0) {
                    pPVar30 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x74));
                    iVar11 = Item::getIndex(*(Item **)(*(int *)(iVar35 + 4) + iVar9 * 4));
                    PlayerEgo::setCurrentSecondaryWeaponIndex(pPVar30,iVar11);
                    Hud::setCurrentSecondaryWeapon
                              (*(Hud **)(this + 0x70),*(Item **)(*(int *)(iVar35 + 4) + iVar9 * 4));
                  }
                  this[0xd2] = (MGame)0x0;
                  this[0x5d] = (MGame)0x0;
                  resumeSounds(this);
                  Hud::closeHudMenu(*(Hud **)(this + 0x70));
                  goto LAB_001abbfa;
                }
                this_03 = *(Hud **)(this + 0x70);
                pLVar28 = *(Level **)(this + 0x74);
                iVar9 = 2;
                goto LAB_001abb56;
              }
              this[0xd2] = (MGame)0x0;
              Hud::closeHudMenu(*(Hud **)(this + 0x70));
              this[0x5d] = (MGame)0x0;
              resumeSounds(this);
              useCloak(this);
            }
            else {
              this_03 = *(Hud **)(this + 0x70);
              pLVar28 = *(Level **)(this + 0x74);
              iVar9 = 1;
LAB_001abb56:
              Hud::initHudMenu(this_03,iVar9,pLVar28);
            }
LAB_001abb5a:
            if (*(int *)(this + 0xf4) == 0) {
              Hud::closeHudMenu(*(Hud **)(this + 0x70));
              this[0xd2] = (MGame)0x0;
              *(undefined4 *)(this + 0x94) = 0;
              *(undefined4 *)(this + 0x98) = 0;
              this[0x5d] = (MGame)0x0;
              resumeSounds(this);
              if (this[0xc4] != (MGame)0x0) {
                this[0xc4] = (MGame)0x0;
                if (*(PlayerEgo **)(this + 0x58) != (PlayerEgo *)0x0) {
                  PlayerEgo::resetGunDelay(*(PlayerEgo **)(this + 0x58));
                }
              }
            }
          }
LAB_001abbfa:
          iVar9 = PlayerEgo::isAutoPilot(*(PlayerEgo **)(this + 0x58));
          if (iVar9 == 1 && iVar8 == 0) {
            *(undefined4 *)(this + 0x1a8) = 0x3f800000;
            *(undefined4 *)(this + 0x1ac) = 0x42c80000;
          }
        }
      }
    }
    else {
      LevelScript::skipSequence(*(LevelScript **)(this + 0x78));
    }
  }
  else {
    if ((*(ushort *)(this + 0xca) & 0xff) != 0) {
      if (*(ushort *)(this + 0xca) < 0x100) {
        if (this[0xc6] == (MGame)0x0) {
          MVar1 = this[0x1dc];
          iVar9 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x90),param_1,param_2);
          if (MVar1 == (MGame)0x0) {
            if (iVar9 == 0) goto LAB_001a9ef4;
          }
          else {
            if (iVar9 == 2) goto LAB_001abc1a;
            if (iVar9 == 1) {
              Globals::playMusicAndFadeOutCurrent(Globals::globals,2);
              this[0x54] = (MGame)0x0;
              AbyssEngine::ApplicationManager::SetCurrentApplicationModule
                        (*(ApplicationManager **)(this + 8),1);
LAB_001aa3a0:
              pSVar23 = Globals::status;
              if (__stack_chk_guard == local_28) {
                Status::resetGame(Globals::status);
                return;
              }
              goto LAB_001abc2e;
            }
            if (iVar9 == 0) {
              if (*(int *)(this + 0x84) == 0) {
                pMVar31 = operator_new(0x240);
                MenuTouchWindow::MenuTouchWindow(pMVar31,1);
                *(MenuTouchWindow **)(this + 0x84) = pMVar31;
              }
              pSVar23 = (Status *)(__stack_chk_guard - local_28);
              if ((Status *)(__stack_chk_guard - local_28) == (Status *)0x0) {
                MenuTouchWindow::startSupernovaChallenge();
                return;
              }
              goto LAB_001abc2e;
            }
          }
        }
        else {
          iVar9 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x90),param_1,param_2);
          if (iVar9 == 1) {
            this[0xc6] = (MGame)0x0;
LAB_001a9ef4:
            this[0xca] = (MGame)0x0;
            this[0x5d] = (MGame)0x0;
            resumeSounds(this);
          }
          else if (iVar9 == 0) {
            AbyssEngine::String::String(aSStack_74);
            pSVar10 = (Ship *)Status::getShip(Globals::status);
            iVar9 = 0x9a;
            bVar3 = false;
            do {
              iVar35 = iVar9 + 0xb;
              if (iVar9 == 0xa5) {
                iVar35 = 0xda;
                iVar9 = 0xd9;
              }
              iVar11 = Status::hardCoreMode();
              iVar32 = 0x1e;
              if (iVar11 != 0) {
                iVar32 = 100;
              }
              iVar11 = 0;
              while (iVar12 = Ship::hasCargo(pSVar10,iVar9,iVar32), iVar12 == 1) {
                Ship::removeCargo(pSVar10,iVar9,iVar32);
                pIVar13 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) +
                                                           iVar35 * 4),1);
                Ship::addCargo(pSVar10,pIVar13);
                iVar11 = iVar11 + 1;
                bVar3 = true;
              }
              if (0 < iVar11) {
                AbyssEngine::String::String(aSStack_58,"\n",false);
                local_60[0] = 0;
                AbyssEngine::String::Set(CONCAT44(extraout_r1,local_60));
                AbyssEngine::operator+(aAStack_50,aSStack_58,(String *)local_60);
                AbyssEngine::String::String(aSStack_68,"t ",false);
                AbyssEngine::operator+(aAStack_48,aAStack_50,aSStack_68);
                pSVar14 = (String *)GameText::getText(Globals::gameText,iVar35 + 0x4fa);
                AbyssEngine::operator+((AbyssEngine *)&local_80,aAStack_48,pSVar14);
                AbyssEngine::String::operator+=(aSStack_74,(AbyssEngine *)&local_80);
                AbyssEngine::String::~String((String *)&local_80);
                AbyssEngine::String::~String((String *)aAStack_48);
                AbyssEngine::String::~String(aSStack_68);
                AbyssEngine::String::~String((String *)aAStack_50);
                AbyssEngine::String::~String((String *)local_60);
                AbyssEngine::String::~String(aSStack_58);
              }
              iVar9 = iVar9 + 1;
            } while (iVar9 < 0xa6);
            this[0xc6] = (MGame)0x0;
            this_04 = *(ChoiceWindow **)(this + 0x90);
            if (bVar3) {
              pSVar14 = (String *)GameText::getText(Globals::gameText,0x123);
              AbyssEngine::String::String((String *)aAStack_50,"\n",false);
              AbyssEngine::operator+(aAStack_48,pSVar14,aAStack_50);
              AbyssEngine::operator+((AbyssEngine *)&local_80,aAStack_48,aSStack_74);
              ChoiceWindow::set(this_04,(String *)&local_80);
              AbyssEngine::String::~String((String *)&local_80);
              AbyssEngine::String::~String((String *)aAStack_48);
              AbyssEngine::String::~String((String *)aAStack_50);
            }
            else {
              pSVar14 = (String *)GameText::getText(Globals::gameText,0x124);
              ChoiceWindow::set(this_04,pSVar14);
            }
            AbyssEngine::String::~String(aSStack_74);
          }
        }
      }
      else {
        iVar9 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x90),param_1,param_2);
        if (iVar9 == 1) {
          puVar25 = (uint *)Level::getEnemies(*(Level **)(this + 0x74));
          if ((puVar25 != (uint *)0x0) && (uVar15 = *puVar25, uVar15 != 0)) {
            uVar26 = puVar25[1];
            uVar27 = 0;
            do {
              iVar9 = *(int *)(uVar26 + uVar27 * 4);
              uVar27 = uVar27 + 1;
              if (*(int *)(iVar9 + 0x24) == 8) {
                *(undefined1 *)(iVar9 + 0x21) = 1;
              }
            } while (uVar27 < uVar15);
          }
          Globals::status[0x111] = (Status)0x1;
          Level::createRadioMessage(*(Level **)(this + 0x74),0xb,8);
          this[0xcb] = (MGame)0x0;
          this[0xca] = (MGame)0x0;
          this[0x5d] = (MGame)0x0;
          resumeSounds(this);
        }
        else if (iVar9 == 0) {
          iVar9 = Status::getCredits(Globals::status);
          pSVar23 = Globals::status;
          if (iVar9 < *(int *)(this + 0xcc)) {
            pSVar29 = *(String **)(this + 0x90);
            pSVar14 = (String *)GameText::getText(Globals::gameText,0xcb);
            AbyssEngine::String::String(aSStack_30,pSVar14,false);
            Layout::formatCredits((int)&local_80);
            AbyssEngine::String::String(aSStack_38,(String *)&local_80,false);
            AbyssEngine::String::String(aSStack_40,"#C",false);
            Status::replaceHash(aSStack_74,pSVar23,aSStack_30,aSStack_38);
            ChoiceWindow::set(pSVar29,(bool)((char)&stack0x00000028 + 'd'));
            AbyssEngine::String::~String(aSStack_74);
            AbyssEngine::String::~String(aSStack_40);
            AbyssEngine::String::~String(aSStack_38);
            AbyssEngine::String::~String((String *)&local_80);
            AbyssEngine::String::~String(aSStack_30);
            this[0xcb] = (MGame)0x0;
            Level::createRadioMessage(*(Level **)(this + 0x74),0xb,8);
            puVar25 = (uint *)Level::getEnemies(*(Level **)(this + 0x74));
            if ((puVar25 != (uint *)0x0) && (uVar15 = *puVar25, uVar15 != 0)) {
              uVar26 = puVar25[1];
              uVar27 = 0;
              do {
                iVar8 = *(int *)(uVar26 + uVar27 * 4);
                uVar27 = uVar27 + 1;
                if (*(int *)(iVar8 + 0x24) == 8) {
                  *(undefined1 *)(iVar8 + 0x21) = 1;
                }
              } while (uVar27 < uVar15);
            }
            Globals::status[0x111] = (Status)0x1;
            goto LAB_001abc1a;
          }
          puVar25 = (uint *)Level::getEnemies(*(Level **)(this + 0x74));
          if ((puVar25 != (uint *)0x0) && (uVar15 = *puVar25, uVar15 != 0)) {
            uVar26 = puVar25[1];
            uVar27 = 0;
            do {
              iVar9 = *(int *)(uVar26 + uVar27 * 4);
              uVar27 = uVar27 + 1;
              if (*(int *)(iVar9 + 0x24) == 8) {
                *(undefined1 *)(iVar9 + 0x21) = 0;
              }
            } while (uVar27 < uVar15);
          }
          Status::changeCredits(Globals::status,-*(int *)(this + 0xcc));
          Level::createRadioMessage(*(Level **)(this + 0x74),10,8);
          Globals::status[0x110] = (Status)0x1;
          this[0xcb] = (MGame)0x0;
          this[0xca] = (MGame)0x0;
          this[0x5d] = (MGame)0x0;
          resumeSounds(this);
        }
      }
      goto LAB_001a9f2c;
    }
    if (this[0xc1] != (MGame)0x0) {
      iVar8 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x90),param_1,param_2);
      if (iVar8 == 1) {
        this[0xc1] = (MGame)0x0;
        if (*(int *)(this + 0x8c) == 0) {
          this_00 = operator_new(0x1e8);
          StarMap::StarMap(this_00,false,(Mission *)0x0,false,-1);
          *(StarMap **)(this + 0x8c) = this_00;
        }
        this_01 = (Engine *)
                  AbyssEngine::ApplicationManager::GetEngine(*(ApplicationManager **)(this + 8));
        AbyssEngine::Engine::SetPostEffect(this_01,0x1400002,false);
        StarMap::initLights();
        StarMap::setJumpMapMode(*(StarMap **)(this + 0x8c),true,false);
        this[0xc3] = (MGame)0x1;
        this[0x5d] = (MGame)0x1;
        pSVar23 = (Status *)(__stack_chk_guard - local_28);
        if ((Status *)(__stack_chk_guard - local_28) == (Status *)0x0) {
          pauseSounds(this);
          return;
        }
        goto LAB_001abc2e;
      }
      if (iVar8 == 0) {
        this[0xc1] = (MGame)0x0;
        iVar8 = PlayerEgo::isInTurretMode(*(PlayerEgo **)(this + 0x58));
        if (iVar8 == 1) {
          PlayerEgo::setTurretMode(*(PlayerEgo **)(this + 0x58),false);
        }
        this[0xd9] = (MGame)0x0;
        startJumpScene(this);
        pSVar23 = (Status *)*(PlayerEgo **)(this + 0x58);
        if (__stack_chk_guard == local_28) {
          PlayerEgo::resetGunDelay(*(PlayerEgo **)(this + 0x58));
          return;
        }
        goto LAB_001abc2e;
      }
      goto LAB_001abc1a;
    }
    if ((*(uint *)(this + 0xc0) & 0xff) != 0) goto LAB_001a9f2c;
    if (*(uint *)(this + 0xc0) < 0x1000000) {
      if (this[0x5e] == (MGame)0x0) {
        if (this[0xc5] == (MGame)0x0) goto LAB_001a9f2c;
        if (this[0x156] != (MGame)0x0) {
          iVar8 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
          if ((*(char *)(iVar8 + 5) != '\0') || (*(char *)(iVar8 + 0xc) != '\0')) goto LAB_001abc1a;
          iVar8 = MenuTouchWindow::isShowingMessage(*(MenuTouchWindow **)(this + 0x84));
          if (iVar8 == 0) {
            uVar37 = MenuTouchWindow::isMakingScreenshot(*(MenuTouchWindow **)(this + 0x84));
            if ((int)uVar37 == 0) {
              freeCamTouchEnd(this,(int)((ulonglong)uVar37 >> 0x20),extraout_r2_03,param_3);
            }
          }
        }
        pMVar33 = this + 0x84;
        iVar8 = MenuTouchWindow::OnTouchEnd(*(MenuTouchWindow **)pMVar33,param_1,param_2,param_3);
        if (iVar8 == 1) {
          this[0x5d] = (MGame)0x0;
          this[0x19e] = (MGame)0x0;
          resumeSounds(this);
          iVar8 = FModSound::IsCategoryEnabled(Globals::sound,2);
          pPVar30 = *(PlayerEgo **)(this + 0x58);
          if (iVar8 == 0) {
            if (this[0x19c] != (MGame)0x0) goto LAB_001aab0e;
            if (pPVar30 != (PlayerEgo *)0x0) {
              PlayerEgo::StopEngineSound(pPVar30);
            }
            puVar25 = (uint *)Level::getEnemies(*(Level **)(this + 0x74));
            if ((puVar25 != (uint *)0x0) && (*puVar25 != 0)) {
              uVar15 = 0;
              do {
                KIPlayer::StopEngineSound(*(KIPlayer **)(puVar25[1] + uVar15 * 4));
                uVar15 = uVar15 + 1;
              } while (uVar15 < *puVar25);
            }
          }
          else if (this[0x19c] == (MGame)0x0) {
            PlayerEgo::ResumeEngineSound(pPVar30);
            puVar25 = (uint *)Level::getEnemies(*(Level **)(this + 0x74));
            if ((puVar25 != (uint *)0x0) && (*puVar25 != 0)) {
              uVar15 = 0;
              do {
                KIPlayer::ResumeEngineSound(*(KIPlayer **)(puVar25[1] + uVar15 * 4));
                uVar15 = uVar15 + 1;
              } while (uVar15 < *puVar25);
            }
          }
          else {
LAB_001aab0e:
            PlayerEgo::PlayEngineSound(pPVar30);
            puVar25 = (uint *)Level::getEnemies(*(Level **)(this + 0x74));
            if ((puVar25 != (uint *)0x0) && (*puVar25 != 0)) {
              uVar15 = 0;
              do {
                KIPlayer::PlayEngineSound(*(KIPlayer **)(puVar25[1] + uVar15 * 4));
                uVar15 = uVar15 + 1;
              } while (uVar15 < *puVar25);
            }
          }
          this[0xc5] = (MGame)0x0;
          *(undefined4 *)(this + 0x94) = 0;
          *(undefined4 *)(this + 0x98) = 0;
          *(undefined4 *)(this + 0xbc) = 0;
          pSVar22 = (StarSystem *)Level::getStarSystem(*(Level **)(this + 0x74));
          StarSystem::initLight(pSVar22);
          Level::enableParticleEffects
                    (*(Level **)(this + 0x74),0.0 < (float)Globals::options._40_4_,
                     0.7 < (float)Globals::options._40_4_);
          if (**(char **)pMVar33 != '\0') {
            **(char **)pMVar33 = '\0';
            iVar8 = Status::getCurrentCampaignMission(Globals::status);
            if ((iVar8 - 0x9aU < 5) && ((1 << (iVar8 - 0x9aU & 0xff) & 0x19U) != 0)) {
              LevelScript::skipCutscene(*(LevelScript **)(this + 0x78));
            }
            else if (iVar8 == 1) {
              Globals::switch_to_target_setting = 0;
              this[0x54] = (MGame)0x0;
              AbyssEngine::ApplicationManager::SetCurrentApplicationModule(Globals::appManager,5);
            }
            else if (iVar8 == 0) {
              Status::nextCampaignMission(SUB41(Globals::status,0));
              Status::setKills(Globals::status,3);
              Globals::switch_to_target_setting = 1;
              this[0x54] = (MGame)0x0;
              AbyssEngine::ApplicationManager::SetCurrentApplicationModule(Globals::appManager,2);
              Level::initStreamOutPosition = 0;
            }
          }
          this[0x156] = (MGame)0x0;
LAB_001ab1c2:
          iVar8 = MenuTouchWindow::inCinematicMode(*(MenuTouchWindow **)pMVar33);
          if (iVar8 == 1) {
            setCinematicMode(this,true);
            *(undefined4 *)(this + 0xf4) = 0;
            pSVar23 = (Status *)Level::getStarSystem(*(Level **)(this + 0x74));
            if (__stack_chk_guard == local_28) {
              StarSystem::initLight((StarSystem *)pSVar23);
              return;
            }
            goto LAB_001abc2e;
          }
          if (this[0x156] == (MGame)0x0) goto LAB_001abc1a;
        }
        else if (this[0x156] == (MGame)0x0) goto LAB_001ab1c2;
        iVar8 = MenuTouchWindow::inCinematicMode(*(MenuTouchWindow **)pMVar33);
        if (iVar8 == 0) {
          this[0x156] = (MGame)0x0;
          Globals::isCinematicModeActive = 0;
          AbyssEngine::Engine::UseAdvancedShader = this[0x1d5];
          switchCamera(this,*(int *)(this + 0x158));
          TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0xf0),(bool)this[0x15c]);
          *(undefined4 *)(this + 0xf4) = 0;
        }
      }
      else {
        iVar8 = DialogueWindow::OnTouchEnd(*(DialogueWindow **)(this + 0x88),param_1,param_2);
        if (iVar8 == 1) {
          this[0x5d] = (MGame)0x0;
          resumeSounds(this);
          this[0x5e] = (MGame)0x0;
          pMVar24 = (Mission *)Status::getMission(Globals::status);
          iVar8 = Mission::hasFailed(pMVar24);
          pMVar24 = (Mission *)Status::getMission(Globals::status);
          if (iVar8 == 1) {
            iVar8 = Mission::isCampaignMission(pMVar24);
            if ((iVar8 != 0) ||
               (iVar8 = Status::getCurrentCampaignMission(Globals::status), iVar8 == 0x2a)) {
              Globals::playMusicAndFadeOutCurrent(Globals::globals,2);
              this[0x54] = (MGame)0x0;
              AbyssEngine::ApplicationManager::SetCurrentApplicationModule
                        (*(ApplicationManager **)(this + 8),1);
              goto LAB_001aa3a0;
            }
            pMVar24 = (Mission *)Status::getMission(Globals::status);
            iVar8 = Mission::getType(pMVar24);
            pSVar23 = Globals::status;
            pMVar24 = (Mission *)Status::getMission(Globals::status);
            if (iVar8 == 0xc) {
              iVar8 = Mission::getReward(pMVar24);
              Status::changeCredits(pSVar23,-iVar8);
            }
            else {
              iVar8 = Mission::getType(pMVar24);
              if (iVar8 != 3) {
                pMVar24 = (Mission *)Status::getMission(Globals::status);
                iVar8 = Mission::getType(pMVar24);
                if (iVar8 != 5) {
                  pMVar24 = (Mission *)Status::getMission(Globals::status);
                  iVar8 = Mission::getType(pMVar24);
                  if (iVar8 != 0xb) goto LAB_001ab318;
                }
              }
              pSVar10 = (Ship *)Status::getShip(Globals::status);
              puVar25 = (uint *)Ship::getCargo(pSVar10);
              if ((puVar25 != (uint *)0x0) && (*puVar25 != 0)) {
                uVar15 = 0;
                do {
                  iVar8 = Item::isUnsaleable(*(Item **)(puVar25[1] + uVar15 * 4));
                  if ((iVar8 == 1) &&
                     ((iVar8 = Item::getIndex(*(Item **)(puVar25[1] + uVar15 * 4)), iVar8 == 0x74 ||
                      (iVar8 = Item::getIndex(*(Item **)(puVar25[1] + uVar15 * 4)), iVar8 == 0x75)))
                     ) {
                    pSVar10 = (Ship *)Status::getShip(Globals::status);
                    Ship::removeCargo(pSVar10,*(Item **)(puVar25[1] + uVar15 * 4));
                    break;
                  }
                  uVar15 = uVar15 + 1;
                } while (uVar15 < *puVar25);
              }
            }
LAB_001ab318:
            Status::setFreelanceMission(Globals::status,Mission::empty);
            Level::removeObjectives(*(Level **)(this + 0x74));
            **(undefined4 **)(this + 0x78) = 0;
            Status::setMission(Globals::status,Mission::empty);
            PlayerEgo::setRoute(*(PlayerEgo **)(this + 0x58),(Route *)0x0);
            iVar8 = PlayerEgo::goingToWaypoint(*(PlayerEgo **)(this + 0x58));
            if (iVar8 == 1) {
              PlayerEgo::setAutoPilot(*(PlayerEgo **)(this + 0x58),(KIPlayer *)0x0);
            }
            PlayerEgo::removeRoute(*(PlayerEgo **)(this + 0x58));
            Level::setPlayerRoute(*(Level **)(this + 0x74),(Route *)0x0);
LAB_001ab37a:
            *(undefined4 *)(this + 0x30) = 0;
            *(undefined4 *)(this + 0x34) = 0;
            Hud::resetAnalogStick(*(Hud **)(this + 0x70));
            pSVar23 = *(Status **)(this + 0x70);
            if (__stack_chk_guard == local_28) {
              Hud::releaseAllKeys((Hud *)pSVar23);
              return;
            }
            goto LAB_001abc2e;
          }
          iVar8 = Mission::hasWon(pMVar24);
          if (iVar8 == 0) {
            pMVar24 = (Mission *)Status::getCampaignMission(Globals::status);
            iVar8 = Mission::hasWon(pMVar24);
            if (iVar8 != 1) {
              LevelScript::resetStartSequenceOver(*(LevelScript **)(this + 0x78));
              goto LAB_001ab37a;
            }
          }
          pMVar24 = (Mission *)Status::getCampaignMission(Globals::status);
          iVar8 = Mission::hasWon(pMVar24);
          if (iVar8 == 1) {
            pMVar24 = (Mission *)Status::getMission(Globals::status);
            uVar15 = Mission::isCampaignMission(pMVar24);
            uVar15 = uVar15 ^ 1;
          }
          else {
            uVar15 = 0;
          }
          pMVar24 = (Mission *)Status::getMission(Globals::status);
          iVar8 = Mission::hasWon(pMVar24);
          if (iVar8 == 1) {
            pMVar24 = (Mission *)Status::getMission(Globals::status);
          }
          else {
            pMVar24 = (Mission *)Status::getCampaignMission(Globals::status);
          }
          iVar8 = Mission::isInstantActionMission(pMVar24);
          if (iVar8 == 1) {
            Globals::switch_to_target_setting = 2;
            this[0x54] = (MGame)0x0;
            pSVar23 = *(Status **)(this + 8);
            if (__stack_chk_guard == local_28) {
              uVar15 = 1;
              goto LAB_001ab8d6;
            }
            goto LAB_001abc2e;
          }
          iVar8 = Mission::isCampaignMission(pMVar24);
          if (iVar8 == 1) {
            Status::nextCampaignMission(SUB41(Globals::status,0));
          }
          else {
            Status::setFreelanceMission(Globals::status,Mission::empty);
            pLVar2 = Globals::layout;
            cVar6 = Mission::getReward(pMVar24);
            cVar7 = Mission::getBonus(pMVar24);
            Layout::showMissionRewardMessage((int)pLVar2,(bool)(cVar7 + cVar6));
          }
          pSVar23 = Globals::status;
          iVar8 = Mission::getReward(pMVar24);
          iVar9 = Mission::getBonus(pMVar24);
          Status::changeCredits(pSVar23,iVar9 + iVar8);
          **(undefined4 **)(this + 0x78) = 0;
          iVar8 = Mission::isCampaignMission(pMVar24);
          if ((iVar8 == 1) &&
             (iVar8 = Status::getCurrentCampaignMission(Globals::status), iVar8 == 0xf)) {
            pFVar19 = operator_new(1);
            FileRead::FileRead(pFVar19);
            pSVar23 = Globals::status;
            pSVar20 = (Station *)FileRead::loadStation(pFVar19,0x62);
            Status::setStation(pSVar23,pSVar20);
            pvVar21 = (void *)FileRead::~FileRead(pFVar19);
            operator_delete(pvVar21);
            Globals::switch_to_target_setting = 0;
            uVar17 = Player::getHitpoints((Player *)**(undefined4 **)(this + 0x58));
            *(undefined4 *)(Globals::status + 100) = uVar17;
            uVar17 = Player::getShieldHP((Player *)**(undefined4 **)(this + 0x58));
            *(undefined4 *)(Globals::status + 0x5c) = uVar17;
            uVar17 = Player::getArmorHP((Player *)**(undefined4 **)(this + 0x58));
            *(undefined4 *)(Globals::status + 0x60) = uVar17;
            uVar17 = Player::getGammaHP((Player *)**(undefined4 **)(this + 0x58));
            *(undefined4 *)(Globals::status + 0x68) = uVar17;
            this[0x54] = (MGame)0x0;
            pSVar23 = *(Status **)(this + 8);
          }
          else {
            iVar8 = Mission::isCampaignMission(pMVar24);
            if ((iVar8 == 1) &&
               (iVar8 = Status::getCurrentCampaignMission(Globals::status), iVar8 == 0x16)) {
              Globals::switch_to_target_setting = 0;
              uVar17 = Player::getHitpoints((Player *)**(undefined4 **)(this + 0x58));
              *(undefined4 *)(Globals::status + 100) = uVar17;
              uVar17 = Player::getShieldHP((Player *)**(undefined4 **)(this + 0x58));
              *(undefined4 *)(Globals::status + 0x5c) = uVar17;
              uVar17 = Player::getArmorHP((Player *)**(undefined4 **)(this + 0x58));
              *(undefined4 *)(Globals::status + 0x60) = uVar17;
              uVar17 = Player::getGammaHP((Player *)**(undefined4 **)(this + 0x58));
              *(undefined4 *)(Globals::status + 0x68) = uVar17;
              this[0x54] = (MGame)0x0;
              pSVar23 = *(Status **)(this + 8);
            }
            else {
              iVar8 = Mission::isCampaignMission(pMVar24);
              if ((iVar8 != 1) ||
                 (iVar8 = Status::getCurrentCampaignMission(Globals::status), iVar8 != 0x2b)) {
                iVar8 = Mission::isCampaignMission(pMVar24);
                if ((iVar8 == 1) &&
                   (iVar8 = Status::getCurrentCampaignMission(Globals::status), iVar8 == 0x2a)) {
                  iVar8 = *(int *)(this + 0x74);
                  if (*(Objective **)(iVar8 + 0x2c) != (Objective *)0x0) {
                    pvVar21 = (void *)Objective::~Objective(*(Objective **)(iVar8 + 0x2c));
                    operator_delete(pvVar21);
                    iVar8 = *(int *)(this + 0x74);
                  }
                  *(undefined4 *)(iVar8 + 0x2c) = 0;
                  if (*(Objective **)(iVar8 + 0x28) != (Objective *)0x0) {
                    pvVar21 = (void *)Objective::~Objective(*(Objective **)(iVar8 + 0x28));
                    operator_delete(pvVar21);
                    iVar8 = *(int *)(this + 0x74);
                  }
                  *(undefined4 *)(iVar8 + 0x28) = 0;
LAB_001aab8c:
                  if (uVar15 == 0) {
                    Level::removeObjectives(*(Level **)(this + 0x74));
                    Status::setMission(Globals::status,Mission::empty);
                    PlayerEgo::setRoute(*(PlayerEgo **)(this + 0x58),(Route *)0x0);
                    iVar8 = PlayerEgo::goingToWaypoint(*(PlayerEgo **)(this + 0x58));
                    if (iVar8 == 1) {
                      PlayerEgo::setAutoPilot(*(PlayerEgo **)(this + 0x58),(KIPlayer *)0x0);
                    }
                    PlayerEgo::removeRoute(*(PlayerEgo **)(this + 0x58));
                    Level::setPlayerRoute(*(Level **)(this + 0x74),(Route *)0x0);
                  }
                  iVar8 = Mission::isCampaignMission(pMVar24);
                  if ((iVar8 == 0) && (iVar8 = Mission::getType(pMVar24), iVar8 == 0xb7)) {
                    *(undefined4 *)(this + 0x1d8) = *(undefined4 *)(*(int *)(this + 0x74) + 0x24);
                    pIVar13 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x360
                                                               ),10);
                    pSVar10 = (Ship *)Status::getShip(Globals::status);
                    Ship::setEquipment(pSVar10,pIVar13,0);
                    pMVar24 = operator_new(100);
                    AbyssEngine::String::String(aSStack_94,"Client",false);
                    uVar17 = ImageFactory::createChar(Globals::imageFactory,true,0);
                    pSVar20 = (Station *)Status::getStation(Globals::status);
                    Station::getIndex(pSVar20);
                    Mission::Mission(pMVar24,0xb7,aSStack_94,uVar17);
                    AbyssEngine::String::~String(aSStack_94);
                    Status::setMission(Globals::status,pMVar24);
                    Status::setFreelanceMission(Globals::status,pMVar24);
                    this[0x54] = (MGame)0x0;
                    AbyssEngine::ApplicationManager::SetCurrentApplicationModule
                              (Globals::appManager,2);
                    goto LAB_001abc1a;
                  }
                  goto LAB_001ab37a;
                }
                iVar8 = Mission::isCampaignMission(pMVar24);
                if ((iVar8 == 1) &&
                   (iVar8 = Status::getCurrentCampaignMission(Globals::status), iVar8 == 0x41)) {
                  Globals::switch_to_target_setting = 1;
                  uVar17 = Player::getHitpoints((Player *)**(undefined4 **)(this + 0x58));
                  *(undefined4 *)(Globals::status + 100) = uVar17;
                  uVar17 = Player::getShieldHP((Player *)**(undefined4 **)(this + 0x58));
                  *(undefined4 *)(Globals::status + 0x5c) = uVar17;
                  uVar17 = Player::getArmorHP((Player *)**(undefined4 **)(this + 0x58));
                  *(undefined4 *)(Globals::status + 0x60) = uVar17;
                  uVar17 = Player::getGammaHP((Player *)**(undefined4 **)(this + 0x58));
                  *(undefined4 *)(Globals::status + 0x68) = uVar17;
                  Level::initStreamOutPosition = 1;
                  pFVar19 = operator_new(1);
                  FileRead::FileRead(pFVar19);
                  pSVar23 = Globals::status;
                  pSVar20 = (Station *)FileRead::loadStation(pFVar19,100);
                  Status::departStation(pSVar23,pSVar20);
                  pvVar21 = (void *)FileRead::~FileRead(pFVar19);
                  operator_delete(pvVar21);
                  this[0x54] = (MGame)0x0;
                  pSVar23 = *(Status **)(this + 8);
                }
                else {
                  iVar8 = Mission::isCampaignMission(pMVar24);
                  if ((iVar8 == 1) &&
                     (iVar8 = Status::getCurrentCampaignMission(Globals::status), iVar8 == 0x51)) {
                    Globals::switch_to_target_setting = 1;
                    uVar17 = Player::getHitpoints((Player *)**(undefined4 **)(this + 0x58));
                    *(undefined4 *)(Globals::status + 100) = uVar17;
                    uVar17 = Player::getShieldHP((Player *)**(undefined4 **)(this + 0x58));
                    *(undefined4 *)(Globals::status + 0x5c) = uVar17;
                    uVar17 = Player::getArmorHP((Player *)**(undefined4 **)(this + 0x58));
                    *(undefined4 *)(Globals::status + 0x60) = uVar17;
                    uVar17 = Player::getGammaHP((Player *)**(undefined4 **)(this + 0x58));
                    pSVar23 = Globals::status;
                    *(undefined4 *)(Globals::status + 0x68) = uVar17;
                    Level::initStreamOutPosition = 1;
                    Status::setStation(pSVar23,*(Station **)(pSVar23 + 0x78));
                    Status::departStation(Globals::status,*(Station **)(Globals::status + 0x78));
                    this[0x54] = (MGame)0x0;
                    pSVar23 = *(Status **)(this + 8);
                  }
                  else {
                    iVar8 = Mission::isCampaignMission(pMVar24);
                    if ((iVar8 == 1) &&
                       (iVar8 = Status::getCurrentCampaignMission(Globals::status), iVar8 == 0x4a))
                    {
                      pFVar19 = operator_new(1);
                      FileRead::FileRead(pFVar19);
                      pSVar23 = Globals::status;
                      pSVar20 = (Station *)FileRead::loadStation(pFVar19,100);
                      Status::setStation(pSVar23,pSVar20);
                      pvVar21 = (void *)FileRead::~FileRead(pFVar19);
                      operator_delete(pvVar21);
                      FModSound::stopAll(Globals::sound);
                      Globals::switch_to_target_setting = 0;
                      uVar17 = Player::getHitpoints((Player *)**(undefined4 **)(this + 0x58));
                      *(undefined4 *)(Globals::status + 100) = uVar17;
                      uVar17 = Player::getShieldHP((Player *)**(undefined4 **)(this + 0x58));
                      *(undefined4 *)(Globals::status + 0x5c) = uVar17;
                      uVar17 = Player::getArmorHP((Player *)**(undefined4 **)(this + 0x58));
                      *(undefined4 *)(Globals::status + 0x60) = uVar17;
                      uVar17 = Player::getGammaHP((Player *)**(undefined4 **)(this + 0x58));
                      *(undefined4 *)(Globals::status + 0x68) = uVar17;
                      this[0x54] = (MGame)0x0;
                      pSVar23 = *(Status **)(this + 8);
                      goto LAB_001aaf4e;
                    }
                    iVar8 = Mission::isCampaignMission(pMVar24);
                    if ((iVar8 == 1) &&
                       (iVar8 = Status::getCurrentCampaignMission(Globals::status), iVar8 == 0x5f))
                    {
                      Globals::switch_to_target_setting = 1;
                      uVar17 = Player::getHitpoints((Player *)**(undefined4 **)(this + 0x58));
                      *(undefined4 *)(Globals::status + 100) = uVar17;
                      uVar17 = Player::getShieldHP((Player *)**(undefined4 **)(this + 0x58));
                      *(undefined4 *)(Globals::status + 0x5c) = uVar17;
                      uVar17 = Player::getArmorHP((Player *)**(undefined4 **)(this + 0x58));
                      *(undefined4 *)(Globals::status + 0x60) = uVar17;
                      uVar17 = Player::getGammaHP((Player *)**(undefined4 **)(this + 0x58));
                      pSVar23 = Globals::status;
                      *(undefined4 *)(Globals::status + 0x68) = uVar17;
                      Level::initStreamOutPosition = 1;
                      pSVar20 = (Station *)Galaxy::getStation(Globals::galaxy,10);
                      Status::departStation(pSVar23,pSVar20);
                      this[0x54] = (MGame)0x0;
                      pSVar23 = *(Status **)(this + 8);
                    }
                    else {
                      iVar8 = Mission::isCampaignMission(pMVar24);
                      if ((iVar8 != 1) ||
                         (iVar8 = Status::getCurrentCampaignMission(Globals::status), iVar8 != 0x60)
                         ) {
                        iVar8 = Mission::isCampaignMission(pMVar24);
                        if ((iVar8 == 1) &&
                           (iVar8 = Status::getCurrentCampaignMission(Globals::status), iVar8 == 100
                           )) {
                          uVar17 = Player::getHitpoints((Player *)**(undefined4 **)(this + 0x58));
                          *(undefined4 *)(Globals::status + 100) = uVar17;
                          uVar17 = Player::getShieldHP((Player *)**(undefined4 **)(this + 0x58));
                          *(undefined4 *)(Globals::status + 0x5c) = uVar17;
                          uVar17 = Player::getArmorHP((Player *)**(undefined4 **)(this + 0x58));
                          *(undefined4 *)(Globals::status + 0x60) = uVar17;
                          uVar17 = Player::getGammaHP((Player *)**(undefined4 **)(this + 0x58));
                          pSVar23 = Globals::status;
                          *(undefined4 *)(Globals::status + 0x68) = uVar17;
                          Level::initStreamOutPosition = 0;
                          Globals::switch_to_target_setting = 0;
                          pSVar20 = (Station *)Galaxy::getStation(Globals::galaxy,0x78);
                          Status::departStation(pSVar23,pSVar20);
                          AbyssEngine::ApplicationManager::SetCurrentApplicationModule
                                    (Globals::appManager,5);
                          this[0x54] = (MGame)0x0;
                        }
                        else {
                          iVar8 = Mission::isCampaignMission(pMVar24);
                          if ((iVar8 != 1) ||
                             (iVar8 = Status::getCurrentCampaignMission(Globals::status),
                             iVar8 != 0x6e)) {
                            iVar8 = Mission::isCampaignMission(pMVar24);
                            if ((iVar8 == 1) &&
                               (iVar8 = Status::getCurrentCampaignMission(Globals::status),
                               iVar8 == 0x78)) {
                              Globals::switch_to_target_setting = 1;
                              uVar17 = Player::getHitpoints
                                                 ((Player *)**(undefined4 **)(this + 0x58));
                              *(undefined4 *)(Globals::status + 100) = uVar17;
                              uVar17 = Player::getShieldHP((Player *)**(undefined4 **)(this + 0x58))
                              ;
                              *(undefined4 *)(Globals::status + 0x5c) = uVar17;
                              uVar17 = Player::getArmorHP((Player *)**(undefined4 **)(this + 0x58));
                              *(undefined4 *)(Globals::status + 0x60) = uVar17;
                              uVar17 = Player::getGammaHP((Player *)**(undefined4 **)(this + 0x58));
                              pSVar23 = Globals::status;
                              *(undefined4 *)(Globals::status + 0x68) = uVar17;
                              Level::initStreamOutPosition = 0;
                              pSVar20 = (Station *)Galaxy::getStation(Globals::galaxy,0x7e);
                              Status::departStation(pSVar23,pSVar20);
                              this[0x54] = (MGame)0x0;
                              pSVar23 = *(Status **)(this + 8);
                              goto LAB_001aaf4e;
                            }
                            iVar8 = Mission::isCampaignMission(pMVar24);
                            if ((iVar8 == 1) &&
                               (iVar8 = Status::getCurrentCampaignMission(Globals::status),
                               iVar8 == 0x7e)) {
                              Globals::switch_to_target_setting = 1;
                              uVar17 = Player::getHitpoints
                                                 ((Player *)**(undefined4 **)(this + 0x58));
                              *(undefined4 *)(Globals::status + 100) = uVar17;
                              uVar17 = Player::getShieldHP((Player *)**(undefined4 **)(this + 0x58))
                              ;
                              *(undefined4 *)(Globals::status + 0x5c) = uVar17;
                              uVar17 = Player::getArmorHP((Player *)**(undefined4 **)(this + 0x58));
                              *(undefined4 *)(Globals::status + 0x60) = uVar17;
                              uVar17 = Player::getGammaHP((Player *)**(undefined4 **)(this + 0x58));
                              pSVar23 = Globals::status;
                              *(undefined4 *)(Globals::status + 0x68) = uVar17;
                              Level::initStreamOutPosition = 0;
                              pSVar20 = (Station *)Galaxy::getStation(Globals::galaxy,0x78);
                              Status::departStation(pSVar23,pSVar20);
                              this[0x54] = (MGame)0x0;
                              pSVar23 = *(Status **)(this + 8);
                            }
                            else {
                              iVar8 = Mission::isCampaignMission(pMVar24);
                              if ((iVar8 == 1) &&
                                 (iVar8 = Status::getCurrentCampaignMission(Globals::status),
                                 iVar8 == 0x7f)) {
                                Globals::switch_to_target_setting = 1;
                                uVar17 = Player::getHitpoints
                                                   ((Player *)**(undefined4 **)(this + 0x58));
                                *(undefined4 *)(Globals::status + 100) = uVar17;
                                uVar17 = Player::getShieldHP((Player *)
                                                             **(undefined4 **)(this + 0x58));
                                *(undefined4 *)(Globals::status + 0x5c) = uVar17;
                                uVar17 = Player::getArmorHP((Player *)**(undefined4 **)(this + 0x58)
                                                           );
                                *(undefined4 *)(Globals::status + 0x60) = uVar17;
                                uVar17 = Player::getGammaHP((Player *)**(undefined4 **)(this + 0x58)
                                                           );
                                pSVar23 = Globals::status;
                                *(undefined4 *)(Globals::status + 0x68) = uVar17;
                                Level::initStreamOutPosition = 1;
                                pSVar20 = (Station *)Galaxy::getStation(Globals::galaxy,0x62);
                                Status::departStation(pSVar23,pSVar20);
                                this[0x54] = (MGame)0x0;
                                pSVar23 = *(Status **)(this + 8);
                              }
                              else {
                                iVar8 = Mission::isCampaignMission(pMVar24);
                                if ((iVar8 == 1) &&
                                   (iVar8 = Status::getCurrentCampaignMission(Globals::status),
                                   iVar8 == 0x86)) {
                                  Globals::switch_to_target_setting = 0;
                                  uVar17 = Player::getHitpoints
                                                     ((Player *)**(undefined4 **)(this + 0x58));
                                  *(undefined4 *)(Globals::status + 100) = uVar17;
                                  uVar17 = Player::getShieldHP((Player *)
                                                               **(undefined4 **)(this + 0x58));
                                  *(undefined4 *)(Globals::status + 0x5c) = uVar17;
                                  uVar17 = Player::getArmorHP((Player *)
                                                              **(undefined4 **)(this + 0x58));
                                  *(undefined4 *)(Globals::status + 0x60) = uVar17;
                                  uVar17 = Player::getGammaHP((Player *)
                                                              **(undefined4 **)(this + 0x58));
                                  pSVar23 = Globals::status;
                                  *(undefined4 *)(Globals::status + 0x68) = uVar17;
                                  Level::initStreamOutPosition = 0;
                                  pSVar20 = (Station *)Galaxy::getStation(Globals::galaxy,0x70);
                                  Status::departStation(pSVar23,pSVar20);
                                  this[0x54] = (MGame)0x0;
                                  pSVar23 = *(Status **)(this + 8);
                                  goto LAB_001aaf4e;
                                }
                                iVar8 = Mission::isCampaignMission(pMVar24);
                                if ((iVar8 == 1) &&
                                   (iVar8 = Status::getCurrentCampaignMission(Globals::status),
                                   iVar8 == 0x90)) {
                                  Globals::switch_to_target_setting = 1;
                                  uVar17 = Player::getHitpoints
                                                     ((Player *)**(undefined4 **)(this + 0x58));
                                  *(undefined4 *)(Globals::status + 100) = uVar17;
                                  uVar17 = Player::getShieldHP((Player *)
                                                               **(undefined4 **)(this + 0x58));
                                  *(undefined4 *)(Globals::status + 0x5c) = uVar17;
                                  uVar17 = Player::getArmorHP((Player *)
                                                              **(undefined4 **)(this + 0x58));
                                  *(undefined4 *)(Globals::status + 0x60) = uVar17;
                                  uVar17 = Player::getGammaHP((Player *)
                                                              **(undefined4 **)(this + 0x58));
                                  pSVar23 = Globals::status;
                                  *(undefined4 *)(Globals::status + 0x68) = uVar17;
                                  Level::initStreamOutPosition = 0;
                                  pSVar20 = (Station *)Galaxy::getStation(Globals::galaxy,0x70);
                                  Status::departStation(pSVar23,pSVar20);
                                  this[0x54] = (MGame)0x0;
                                  pSVar23 = *(Status **)(this + 8);
                                }
                                else {
                                  iVar8 = Mission::isCampaignMission(pMVar24);
                                  if ((iVar8 == 1) &&
                                     (iVar8 = Status::getCurrentCampaignMission(Globals::status),
                                     pSVar23 = Globals::status, iVar8 == 0x9b)) {
                                    Globals::switch_to_target_setting = 1;
                                    Level::initStreamOutPosition = 1;
                                    pSVar20 = (Station *)
                                              Galaxy::getStation(Globals::galaxy,
                                                                 *(int *)(Globals::status + 0x84));
                                    Status::departStation(pSVar23,pSVar20);
                                    this[0x54] = (MGame)0x0;
                                    pSVar23 = *(Status **)(this + 8);
                                  }
                                  else {
                                    iVar8 = Mission::isCampaignMission(pMVar24);
                                    if ((iVar8 != 1) ||
                                       (iVar8 = Status::getCurrentCampaignMission(Globals::status),
                                       iVar8 != 0xa1)) {
                                      iVar8 = Mission::isCampaignMission(pMVar24);
                                      if ((iVar8 != 1) ||
                                         (iVar8 = Status::getCurrentCampaignMission(Globals::status)
                                         , iVar8 != 0xa2)) goto LAB_001aab8c;
                                      uVar17 = Player::getHitpoints
                                                         ((Player *)**(undefined4 **)(this + 0x58));
                                      *(undefined4 *)(Globals::status + 100) = uVar17;
                                      uVar17 = Player::getShieldHP((Player *)
                                                                   **(undefined4 **)(this + 0x58));
                                      *(undefined4 *)(Globals::status + 0x5c) = uVar17;
                                      uVar17 = Player::getArmorHP((Player *)
                                                                  **(undefined4 **)(this + 0x58));
                                      *(undefined4 *)(Globals::status + 0x60) = uVar17;
                                      uVar17 = Player::getGammaHP((Player *)
                                                                  **(undefined4 **)(this + 0x58));
                                      pSVar23 = Globals::status;
                                      *(undefined4 *)(Globals::status + 0x68) = uVar17;
                                      Level::initStreamOutPosition = 0;
                                      Globals::switch_to_target_setting = 0;
                                      pSVar20 = (Station *)Galaxy::getStation(Globals::galaxy,0x5d);
                                      Status::departStation(pSVar23,pSVar20);
                                      this[0x54] = (MGame)0x0;
                                      pSVar23 = *(Status **)(this + 8);
                                      goto LAB_001aaf4e;
                                    }
                                    uVar17 = Player::getHitpoints
                                                       ((Player *)**(undefined4 **)(this + 0x58));
                                    *(undefined4 *)(Globals::status + 100) = uVar17;
                                    uVar17 = Player::getShieldHP((Player *)
                                                                 **(undefined4 **)(this + 0x58));
                                    *(undefined4 *)(Globals::status + 0x5c) = uVar17;
                                    uVar17 = Player::getArmorHP((Player *)
                                                                **(undefined4 **)(this + 0x58));
                                    *(undefined4 *)(Globals::status + 0x60) = uVar17;
                                    uVar17 = Player::getGammaHP((Player *)
                                                                **(undefined4 **)(this + 0x58));
                                    pSVar23 = Globals::status;
                                    *(undefined4 *)(Globals::status + 0x68) = uVar17;
                                    Level::initStreamOutPosition = 0;
                                    Globals::switch_to_target_setting = 0;
                                    pSVar20 = (Station *)Galaxy::getStation(Globals::galaxy,0x5d);
                                    Status::departStation(pSVar23,pSVar20);
                                    this[0x54] = (MGame)0x0;
                                    pSVar23 = *(Status **)(this + 8);
                                  }
                                }
                              }
                            }
                            goto LAB_001ab8c8;
                          }
                          uVar17 = Player::getHitpoints((Player *)**(undefined4 **)(this + 0x58));
                          *(undefined4 *)(Globals::status + 100) = uVar17;
                          uVar17 = Player::getShieldHP((Player *)**(undefined4 **)(this + 0x58));
                          *(undefined4 *)(Globals::status + 0x5c) = uVar17;
                          uVar17 = Player::getArmorHP((Player *)**(undefined4 **)(this + 0x58));
                          *(undefined4 *)(Globals::status + 0x60) = uVar17;
                          uVar17 = Player::getGammaHP((Player *)**(undefined4 **)(this + 0x58));
                          pSVar23 = Globals::status;
                          *(undefined4 *)(Globals::status + 0x68) = uVar17;
                          Level::initStreamOutPosition = 0;
                          Globals::switch_to_target_setting = 0;
                          pSVar20 = (Station *)Galaxy::getStation(Globals::galaxy,10);
                          Status::departStation(pSVar23,pSVar20);
                          AbyssEngine::ApplicationManager::SetCurrentApplicationModule
                                    (Globals::appManager,5);
                          Globals::enterSpaceLounge = 1;
                          this[0x54] = (MGame)0x0;
                        }
                        goto LAB_001abc1a;
                      }
                      Globals::switch_to_target_setting = 1;
                      uVar17 = Player::getHitpoints((Player *)**(undefined4 **)(this + 0x58));
                      *(undefined4 *)(Globals::status + 100) = uVar17;
                      uVar17 = Player::getShieldHP((Player *)**(undefined4 **)(this + 0x58));
                      *(undefined4 *)(Globals::status + 0x5c) = uVar17;
                      uVar17 = Player::getArmorHP((Player *)**(undefined4 **)(this + 0x58));
                      *(undefined4 *)(Globals::status + 0x60) = uVar17;
                      uVar17 = Player::getGammaHP((Player *)**(undefined4 **)(this + 0x58));
                      pSVar23 = Globals::status;
                      *(undefined4 *)(Globals::status + 0x68) = uVar17;
                      Level::initStreamOutPosition = 1;
                      pSVar20 = (Station *)Galaxy::getStation(Globals::galaxy,0x62);
                      Status::departStation(pSVar23,pSVar20);
                      this[0x54] = (MGame)0x0;
                      pSVar23 = *(Status **)(this + 8);
                    }
                  }
                }
LAB_001ab8c8:
                if (__stack_chk_guard == local_28) {
                  uVar15 = 2;
                  goto LAB_001ab8d6;
                }
                goto LAB_001abc2e;
              }
              pFVar19 = operator_new(1);
              FileRead::FileRead(pFVar19);
              pSVar23 = Globals::status;
              pSVar20 = (Station *)FileRead::loadStation(pFVar19,10);
              Status::setStation(pSVar23,pSVar20);
              pvVar21 = (void *)FileRead::~FileRead(pFVar19);
              operator_delete(pvVar21);
              Globals::switch_to_target_setting = 0;
              uVar17 = Player::getHitpoints((Player *)**(undefined4 **)(this + 0x58));
              *(undefined4 *)(Globals::status + 100) = uVar17;
              uVar17 = Player::getShieldHP((Player *)**(undefined4 **)(this + 0x58));
              *(undefined4 *)(Globals::status + 0x5c) = uVar17;
              uVar17 = Player::getArmorHP((Player *)**(undefined4 **)(this + 0x58));
              *(undefined4 *)(Globals::status + 0x60) = uVar17;
              uVar17 = Player::getGammaHP((Player *)**(undefined4 **)(this + 0x58));
              *(undefined4 *)(Globals::status + 0x68) = uVar17;
              this[0x54] = (MGame)0x0;
              pSVar23 = *(Status **)(this + 8);
            }
          }
LAB_001aaf4e:
          if (__stack_chk_guard == local_28) {
            uVar15 = 5;
LAB_001ab8d6:
            AbyssEngine::ApplicationManager::SetCurrentApplicationModule
                      ((ApplicationManager *)pSVar23,uVar15);
            return;
          }
          goto LAB_001abc2e;
        }
      }
    }
    else if (*Globals::layout == (Layout)0x0) {
      iVar8 = StarMap::OnTouchEnd(*(StarMap **)(this + 0x8c),param_1,param_2);
      if (iVar8 == 1) {
        pSVar22 = (StarSystem *)Level::getStarSystem(*(Level **)(this + 0x74));
        StarSystem::initLight(pSVar22);
        this[0xc3] = (MGame)0x0;
        this[0x5d] = (MGame)0x0;
        resumeSounds(this);
        if (**(char **)(this + 0x8c) == '\0') {
          if (this[199] != (MGame)0x0) {
            PlayerEgo::dockToStream(*(PlayerEgo **)(this + 0x58),false);
            PlayerEgo::setAutoPilot(*(PlayerEgo **)(this + 0x58),(KIPlayer *)0x0);
            this_05 = *(AEGeometry **)(*(int *)(this + 0x58) + 4);
            Level::getLandmarks(*(Level **)(this + 0x74));
            AEGeometry::getDirection();
            local_80 = 0;
            local_7c = 0x3f800000;
            local_78 = 0;
            AEGeometry::setDirection(this_05,(Vector *)aSStack_74,(Vector *)&local_80);
            uVar17 = *(undefined4 *)(this + 0x58);
            Level::getLandmarks(*(Level **)(this + 0x74));
            AEGeometry::getPosition();
            local_80 = 0;
            local_7c = 0;
            local_78 = 0x45fa0000;
            AbyssEngine::AEMath::operator+
                      ((AEMath *)&local_8c,(Vector *)aSStack_74,(Vector *)&local_80);
            PlayerEgo::setPosition(uVar17,local_8c,uStack_88,uStack_84);
          }
        }
        else if (this[199] == (MGame)0x0) {
          if (Level::doInstantJump == '\0') {
            LevelScript::setAutoPilotToProgrammedStation(*(LevelScript **)(this + 0x78));
          }
        }
        else {
          this[0xd9] = (MGame)0x0;
          startJumpScene(this);
        }
        if (*(StarMap **)(this + 0x8c) != (StarMap *)0x0) {
          pvVar21 = (void *)StarMap::~StarMap(*(StarMap **)(this + 0x8c));
          operator_delete(pvVar21);
        }
        *(undefined4 *)(this + 0x8c) = 0;
      }
    }
    else {
      iVar8 = Layout::OnTouchEnd(Globals::layout,param_1,param_2);
      if (iVar8 == 1) {
        *Globals::layout = (Layout)0x0;
      }
    }
  }
LAB_001abc1a:
  pSVar23 = (Status *)(__stack_chk_guard - local_28);
  if ((Status *)(__stack_chk_guard - local_28) == (Status *)0x0) {
    return;
  }
LAB_001abc2e:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pSVar23);
}

// ===== MGame::startJumpScene  @0x001abf10  (848 bytes)
/* MGame::startJumpScene() */

void __thiscall MGame::startJumpScene(MGame *this)

{
  PaintCanvas *pPVar1;
  int iVar2;
  Engine *this_00;
  AEGeometry *this_01;
  undefined4 uVar3;
  float *pfVar4;
  Vector *this_02;
  float fVar5;
  float fVar6;
  float extraout_s0;
  float fVar7;
  float extraout_s0_00;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float extraout_s1_03;
  float extraout_s1_04;
  float extraout_s2;
  float extraout_s2_00;
  float extraout_s2_01;
  float extraout_s2_02;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  Vector aVStack_38 [12];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  Player::setVulnerable((Player *)**(undefined4 **)(this + 0x58),false);
  Level::enableFog(*(Level **)(this + 0x74),false);
  iVar2 = PlayerEgo::isDockedToDockingPoint(*(PlayerEgo **)(this + 0x58));
  if (iVar2 == 1) {
    PlayerEgo::dockToDockingPoint(*(KIPlayer **)(this + 0x58),(Radar *)0x0);
    TargetFollowCamera::setActive(*(TargetFollowCamera **)(this + 0xf0),true);
    TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0xf0),false);
    fVar5 = (float)TargetFollowCamera::useTargetsUpVector
                             (*(TargetFollowCamera **)(this + 0xf0),false);
    PlayerEgo::setSpeed(*(PlayerEgo **)(this + 0x58),fVar5);
    PlayerEgo::setDockingState(*(PlayerEgo **)(this + 0x58),0);
  }
  iVar2 = PlayerEgo::isInTurretMode(*(PlayerEgo **)(this + 0x58));
  if (iVar2 == 1) {
    PlayerEgo::setTurretMode(*(PlayerEgo **)(this + 0x58),false);
  }
  FModSound::stop(Globals::sound,0x23);
  switchCamera(this,0);
  *(undefined4 *)(this + 0x6c) = 0x3f9c28f6;
  Hud::releaseAllKeys(*(Hud **)(this + 0x70));
  this[0x5c] = (MGame)0x0;
  this[0x108] = (MGame)0x0;
  pPVar1 = Globals::Canvas;
  iVar2 = Status::inAlienOrbit(Globals::status);
  if (iVar2 == 1) {
    iVar2 = Status::getCurrentCampaignMission(Globals::status);
    pfVar4 = (float *)&DAT_001ac288;
    if (iVar2 < 0x50) {
      pfVar4 = (float *)&DAT_001ac28c;
    }
    fVar6 = *pfVar4;
    fVar5 = extraout_s1_00;
    fVar7 = extraout_s2_00;
  }
  else {
    fVar6 = 300000.0;
    fVar5 = extraout_s1;
    fVar7 = extraout_s2;
  }
  AbyssEngine::PaintCanvas::CameraSetPerspective((uint)pPVar1,fVar6,fVar5,fVar7);
  PlayerEgo::setAutoPilot(*(PlayerEgo **)(this + 0x58),(KIPlayer *)0x0);
  this[0xd2] = (MGame)0x0;
  this[0x5d] = (MGame)0x0;
  this[0xd8] = (MGame)0x1;
  this[0x5f] = (MGame)0x1;
  PlayerEgo::setCollide(*(PlayerEgo **)(this + 0x58),false);
  TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0xf0),true);
  PlayerEgo::stopBoost(*(PlayerEgo **)(this + 0x58));
  this_00 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(*(ApplicationManager **)(this + 8))
  ;
  AbyssEngine::Engine::SetPostEffect(this_00,0x1400002,false);
  if (this[0xd9] == (MGame)0x0) {
    iVar2 = Level::getLandmarks(*(Level **)(this + 0x74));
    (**(code **)(**(int **)(*(int *)(iVar2 + 4) + 4) + 0x28))(aVStack_38);
    AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0xe0),aVStack_38);
    fVar5 = *(float *)(this + 0xe8);
    *(float *)(this + 0xe8) = fVar5 + -10000.0;
    PlayerEgo::setPosition
              (*(undefined4 *)(this + 0x58),*(undefined4 *)(this + 0xe0),
               *(undefined4 *)(this + 0xe4),fVar5 + -10000.0);
    PlayerEgo::setComputerControlled(*(PlayerEgo **)(this + 0x58),true);
    AEGeometry::setRotation
              (*(AEGeometry **)(*(int *)(this + 0x58) + 8),extraout_s0_00,extraout_s1_03,
               extraout_s2_02);
    fVar7 = *(float *)(this + 0xe0) + -2000.0;
    *(float *)(this + 0xe0) = fVar7;
    fVar6 = *(float *)(this + 0xe4) + 300.0;
    *(float *)(this + 0xe4) = fVar6;
    *(float *)(this + 0xe8) = *(float *)(this + 0xe8) + 4000.0;
    fVar5 = extraout_s1_04;
  }
  else {
    PlayerEgo::resetMovement(*(PlayerEgo **)(this + 0x58));
    PlayerEgo::setComputerControlled(*(PlayerEgo **)(this + 0x58),true);
    this_01 = operator_new(0xc0);
    AEGeometry::AEGeometry(this_01,0x3ab2,Globals::Canvas,false);
    *(AEGeometry **)(this + 0x10c) = this_01;
    uVar3 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(this_01 + 0xc));
    AbyssEngine::Transform::SetAnimationState(uVar3,1,0);
    PlayerEgo::getPosition();
    this_02 = (Vector *)(this + 0xe0);
    AbyssEngine::AEMath::Vector::operator=(this_02,aVStack_38);
    fVar5 = (float)AEGeometry::getDirection();
    AbyssEngine::AEMath::operator*((AEMath *)aVStack_38,(Vector *)&local_44,fVar5);
    AbyssEngine::AEMath::Vector::operator+=(this_02,aVStack_38);
    AEGeometry::setPosition(*(Vector **)(this + 0x10c));
    AEGeometry::getDirection();
    AEGeometry::setScaling(*(AEGeometry **)(this + 0x10c),extraout_s0,extraout_s1_01,extraout_s2_01)
    ;
    local_44 = 0;
    local_40 = 0x3f800000;
    uStack_3c = 0;
    AEGeometry::setDirection(*(AEGeometry **)(this + 0x10c),aVStack_38,(Vector *)&local_44);
    local_44 = 0xc4fa0000;
    local_40 = 0x43960000;
    uStack_3c = 0xc4fa0000;
    AbyssEngine::AEMath::Vector::operator=(aVStack_38,(Vector *)&local_44);
    AbyssEngine::AEMath::MatrixRotateVector
              ((AEMath *)&local_44,(Matrix *)(**(int **)(this + 0x58) + 4),aVStack_38);
    AbyssEngine::AEMath::Vector::operator=(aVStack_38,(Vector *)&local_44);
    AbyssEngine::AEMath::Vector::operator+=(this_02,aVStack_38);
    FModSound::stop(Globals::sound,*(int *)(*(int *)(this + 0x58) + 0x1c));
    FModSound::stop(Globals::sound,0x23);
    FModSound::stop(Globals::sound,0x8d5);
    fVar5 = (float)FModSound::stop(Globals::sound,0x8d4);
    FModSound::play(Globals::sound,0x20,(Vector *)0x0,(Vector *)0x0,fVar5);
    fVar7 = *(float *)(this + 0xe0);
    fVar6 = *(float *)(this + 0xe4);
    fVar5 = extraout_s1_02;
  }
  TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0xf0),fVar7,fVar5,fVar6);
  if (__stack_chk_guard != local_2c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== MGame::setCinematicMode  @0x001ac2b0  (146 bytes)
/* MGame::setCinematicMode(bool) */

void __thiscall MGame::setCinematicMode(MGame *this,bool param_1)

{
  MGame MVar1;
  
  this[0x156] = (MGame)param_1;
  Globals::isCinematicModeActive = param_1;
  if (!param_1) {
    AbyssEngine::Engine::UseAdvancedShader = this[0x1d5];
    switchCamera(this,*(int *)(this + 0x158));
    TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0xf0),(bool)this[0x15c]);
    return;
  }
  this[0x1d5] = AbyssEngine::Engine::UseAdvancedShader;
  AbyssEngine::Engine::UseAdvancedShader = (MGame)0x1;
  if ((this[0xd8] == (MGame)0x0) && (this[0x5f] == (MGame)0x0)) {
    *(undefined4 *)(this + 0x158) = *(undefined4 *)(this + 0x14);
    MVar1 = (MGame)TargetFollowCamera::isInLookAtMode(*(TargetFollowCamera **)(this + 0xf0));
    this[0x15c] = MVar1;
    TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0xf0),false);
    switchCamera(this,3);
    LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x74),*(int *)(this + 0x40),true)
    ;
    return;
  }
  return;
}

// ===== MGame::switchCamera  @0x001ac34c  (314 bytes)
/* MGame::switchCamera(int) */

void __thiscall MGame::switchCamera(MGame *this,int param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  PlayerEgo *this_00;
  
LAB_001ac35c:
  iVar3 = *(int *)(this + 0x14);
  if (param_1 == 2) {
    param_1 = 3;
  }
  *(int *)(this + 0x14) = param_1;
  if (param_1 == 1) {
    iVar2 = PlayerEgo::isDockingToAsteroid(*(PlayerEgo **)(this + 0x58));
    if (iVar2 == 1) {
      iVar2 = 0;
      this[0xd1] = (MGame)0x0;
    }
    else {
      iVar2 = PlayerEgo::setTurretMode(*(PlayerEgo **)(this + 0x58),true);
      this[0xd1] = SUB41(iVar2,0);
      if (iVar2 == 1) {
        param_1 = *(int *)(this + 0x14);
        goto LAB_001ac3a0;
      }
    }
    param_1 = *(int *)(this + 0x14) + 1;
    *(int *)(this + 0x14) = param_1;
  }
  else {
    iVar2 = 0;
    this[0xd1] = (MGame)0x0;
  }
LAB_001ac3a0:
  if (param_1 == 2) {
    *(undefined4 *)(this + 0x14) = 3;
  }
  else if (3 < param_1) {
    *(undefined4 *)(this + 0x14) = 0;
  }
  this[0x18] = (MGame)0x0;
  PlayerEgo::setTurretMode(*(PlayerEgo **)(this + 0x58),SUB41(iVar2,0));
  switch(*(undefined4 *)(this + 0x14)) {
  case 0:
    break;
  case 1:
  case 3:
    iVar3 = PlayerEgo::isDockedToDockingPoint(*(PlayerEgo **)(this + 0x58));
    if (iVar3 == 1) {
      TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0xf0),false);
    }
    LevelScript::lookBehind(*(LevelScript **)(this + 0x78));
    TargetFollowCamera::setRotationAroundTarget(*(TargetFollowCamera **)(this + 0xf0),true);
    PlayerEgo::setFreeLookMode(*(PlayerEgo **)(this + 0x58),true);
    goto switchD_001ac3be_default;
  case 2:
    LevelScript::resetCamera(*(LevelScript **)(this + 0x78),*(Level **)(this + 0x74));
    TargetFollowCamera::setRotationAroundTarget(*(TargetFollowCamera **)(this + 0xf0),false);
    PlayerEgo::setFreeLookMode(*(PlayerEgo **)(this + 0x58),false);
    if (iVar3 == 1) {
      this[0x18] = (MGame)0x1;
    }
  default:
    goto switchD_001ac3be_default;
  }
  iVar3 = PlayerEgo::isDockedToDockingPoint(*(PlayerEgo **)(this + 0x58));
  param_1 = 1;
  if (iVar3 == 0) {
    LevelScript::resetCamera(*(LevelScript **)(this + 0x78),*(Level **)(this + 0x74));
    TargetFollowCamera::setRotationAroundTarget(*(TargetFollowCamera **)(this + 0xf0),false);
    PlayerEgo::setFreeLookMode(*(PlayerEgo **)(this + 0x58),false);
    iVar3 = AbyssEngine::ApplicationManager::GetEngine(*(ApplicationManager **)(this + 8));
    *(undefined4 *)(iVar3 + 0x350) = 0;
switchD_001ac3be_default:
    TargetFollowCamera::enableFirstPersonCam
              (*(TargetFollowCamera **)(this + 0xf0),*(int *)(this + 0x14) == 2);
    this_00 = *(PlayerEgo **)(this + 0x58);
    if (this[0x18] == (MGame)0x0) {
      uVar1 = TargetFollowCamera::hideShipForFirstPersonCam(*(TargetFollowCamera **)(this + 0xf0));
    }
    else {
      uVar1 = true;
    }
    PlayerEgo::hideShipForFirstPersonCameraView(this_00,(bool)uVar1);
    return;
  }
  goto LAB_001ac35c;
}

// ===== MGame::nextCamId  @0x001ac488  (162 bytes)
/* MGame::nextCamId(int) */

int __thiscall MGame::nextCamId(MGame *this,int param_1)

{
  int iVar1;
  Ship *pSVar2;
  int iVar3;
  
  iVar1 = param_1 + 1;
  if (iVar1 == 2) {
    iVar1 = param_1 + 2;
  }
  if (iVar1 != 1) goto LAB_001ac4d2;
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  iVar1 = Ship::getFirstEquipmentOfSort(pSVar2,8);
  if (iVar1 == 0) {
    pSVar2 = (Ship *)Status::getShip(Globals::status);
    iVar1 = Ship::getFirstEquipmentOfSort(pSVar2,0x23);
    if (iVar1 != 0) goto LAB_001ac4c2;
  }
  else {
LAB_001ac4c2:
    iVar1 = PlayerEgo::hasAutoTurret(*(PlayerEgo **)(this + 0x58));
    if (iVar1 != 1) {
      iVar1 = 1;
      goto LAB_001ac4d2;
    }
  }
  iVar1 = 2;
LAB_001ac4d2:
  if (iVar1 == 2) {
    iVar1 = 3;
  }
  if (3 < iVar1) {
    iVar1 = PlayerEgo::isDockedToDockingPoint(*(PlayerEgo **)(this + 0x58));
    if (iVar1 != 1) {
      return 0;
    }
    pSVar2 = (Ship *)Status::getShip(Globals::status);
    iVar1 = Ship::getFirstEquipmentOfSort(pSVar2,8);
    if (iVar1 == 0) {
      pSVar2 = (Ship *)Status::getShip(Globals::status);
      iVar1 = Ship::getFirstEquipmentOfSort(pSVar2,0x23);
      if (iVar1 == 0) {
        return 3;
      }
    }
    iVar1 = PlayerEgo::hasAutoTurret(*(PlayerEgo **)(this + 0x58));
    iVar3 = 1;
    if (iVar1 != 0) {
      iVar3 = 3;
    }
    return iVar3;
  }
  return iVar1;
}

// ===== MGame::OnRelease  @0x001ac53c  (524 bytes)
/* MGame::OnRelease() */

void __thiscall MGame::OnRelease(MGame *this)

{
  Globals *this_00;
  Engine *this_01;
  void *pvVar1;
  int iVar2;
  
  this_01 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(*(ApplicationManager **)(this + 8))
  ;
  AbyssEngine::Engine::SetPostEffect(this_01,0x1400002,false);
  if (Globals::sound != (FModSound *)0x0) {
    FModSound::setDownPitch(Globals::sound,false);
    FModSound::disableReverb(Globals::sound);
    FModSound::stopAllSoundFXEvents(Globals::sound);
  }
  if (*(Level **)(this + 0x74) != (Level *)0x0) {
    pvVar1 = (void *)Level::~Level(*(Level **)(this + 0x74));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  this[0x54] = (MGame)0x0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined2 *)(this + 0x60) = 0;
  if (*(AEGeometry **)(this + 0x10c) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x10c));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x10c) = 0;
  if (*(Hud **)(this + 0x70) != (Hud *)0x0) {
    pvVar1 = (void *)Hud::~Hud(*(Hud **)(this + 0x70));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x70) = 0;
  if (*(LevelScript **)(this + 0x78) != (LevelScript *)0x0) {
    pvVar1 = (void *)LevelScript::~LevelScript(*(LevelScript **)(this + 0x78));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x78) = 0;
  if (*(Radar **)(this + 0x7c) != (Radar *)0x0) {
    pvVar1 = (void *)Radar::~Radar(*(Radar **)(this + 0x7c));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x7c) = 0;
  if (*(Radio **)(this + 0x80) != (Radio *)0x0) {
    pvVar1 = (void *)Radio::~Radio(*(Radio **)(this + 0x80));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x80) = 0;
  iVar2 = AbyssEngine::ApplicationManager::GetApplicationModule(Globals::appManager,5);
  if (*(int *)(iVar2 + 0x10) != 0) {
    iVar2 = AbyssEngine::ApplicationManager::GetApplicationModule(Globals::appManager,5);
    if (*(StarMap **)(iVar2 + 0x10) != (StarMap *)0x0) {
      pvVar1 = (void *)StarMap::~StarMap(*(StarMap **)(iVar2 + 0x10));
      operator_delete(pvVar1);
    }
  }
  iVar2 = AbyssEngine::ApplicationManager::GetApplicationModule(Globals::appManager,5);
  *(undefined4 *)(iVar2 + 0x10) = 0;
  if (*(MenuTouchWindow **)(this + 0x84) != (MenuTouchWindow *)0x0) {
    pvVar1 = (void *)MenuTouchWindow::~MenuTouchWindow(*(MenuTouchWindow **)(this + 0x84));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x84) = 0;
  if (*(DialogueWindow **)(this + 0x88) != (DialogueWindow *)0x0) {
    pvVar1 = (void *)DialogueWindow::~DialogueWindow(*(DialogueWindow **)(this + 0x88));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x88) = 0;
  if (*(StarMap **)(this + 0x8c) != (StarMap *)0x0) {
    pvVar1 = (void *)StarMap::~StarMap(*(StarMap **)(this + 0x8c));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x8c) = 0;
  if (*(ChoiceWindow **)(this + 0x90) != (ChoiceWindow *)0x0) {
    pvVar1 = (void *)ChoiceWindow::~ChoiceWindow(*(ChoiceWindow **)(this + 0x90));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x90) = 0;
  this[0xd1] = (MGame)0x0;
  this[0xd2] = (MGame)0x0;
  *(undefined4 *)(this + 0x10c) = 0;
  *(undefined4 *)(this + 0xc1) = 0;
  *(undefined4 *)(this + 199) = 0;
  *(undefined4 *)(this + 0xd4) = 0;
  *(undefined4 *)(this + 0xd8) = 0;
  if (*(TargetFollowCamera **)(this + 0xf0) != (TargetFollowCamera *)0x0) {
    pvVar1 = (void *)TargetFollowCamera::~TargetFollowCamera(*(TargetFollowCamera **)(this + 0xf0));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xf0) = 0;
  if (*(GameRecord **)(this + 0x1e0) != (GameRecord *)0x0) {
    pvVar1 = (void *)GameRecord::~GameRecord(*(GameRecord **)(this + 0x1e0));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x1e0) = 0;
  AbyssEngine::PaintCanvas::ReleaseAllResources(Globals::Canvas);
  this_00 = Globals::globals;
  iVar2 = GameText::getLanguage();
  Globals::loadFont(this_00,iVar2);
  if (Globals::layout != (Layout *)0x0) {
    Layout::reload(Globals::layout);
    ImageFactory::reload(Globals::imageFactory);
    Layout::initTip(Globals::layout);
  }
  ArrayReleaseClasses<AbyssEngine::String*>(*(Array **)(this + 0x1e4));
  pvVar1 = *(void **)(this + 0x1e4);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x1e4) = 0;
  if (Globals::sound == (FModSound *)0x0) {
    return;
  }
  FModSound::freeAllEvents(Globals::sound);
  return;
}

// ===== MGame::OnKeyPress  @0x001ac774  (2 bytes)
/* MGame::OnKeyPress(long long, long long) */

longlong MGame::OnKeyPress(longlong param_1,longlong param_2)

{
  return param_1;
}

// ===== MGame::OnUpdate  @0x001ac778  (11744 bytes)
/* MGame::OnUpdate() */

void __thiscall MGame::OnUpdate(MGame *this)

{
  byte bVar1;
  Galaxy *this_00;
  GameText *this_01;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 uVar7;
  MGame *pMVar8;
  ChoiceWindow *pCVar9;
  String *pSVar10;
  Ship *pSVar11;
  undefined4 *puVar12;
  Mission *pMVar13;
  Station *pSVar14;
  void *pvVar15;
  DialogueWindow *pDVar16;
  String *pSVar17;
  Standing *this_02;
  SolarSystem *pSVar18;
  Engine *pEVar19;
  float *pfVar20;
  Status *pSVar21;
  MGame MVar22;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int iVar23;
  int extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  MGame *pMVar24;
  bool bVar25;
  int extraout_r2;
  int extraout_r2_00;
  int extraout_r2_01;
  uint extraout_r2_02;
  uint uVar26;
  PaintCanvas *pPVar27;
  TargetFollowCamera *this_03;
  PlayerEgo *this_04;
  int iVar28;
  int iVar29;
  Item *pIVar30;
  bool bVar31;
  uint in_fpscr;
  uint uVar32;
  float fVar33;
  float fVar34;
  float extraout_s0;
  float fVar35;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float extraout_s1_03;
  float extraout_s1_04;
  float extraout_s1_05;
  float extraout_s1_06;
  float extraout_s2;
  float extraout_s2_00;
  float extraout_s2_01;
  float extraout_s2_02;
  float extraout_s2_03;
  float fVar36;
  undefined1 in_q8 [16];
  undefined1 auVar37 [16];
  undefined8 uVar38;
  longlong lVar39;
  String aSStack_104 [8];
  undefined4 local_fc [2];
  String aSStack_f4 [8];
  String aSStack_ec [8];
  String aSStack_e4 [8];
  String aSStack_dc [8];
  undefined4 local_d4 [3];
  String aSStack_c8 [12];
  AbyssEngine aAStack_bc [12];
  AbyssEngine aAStack_b0 [12];
  String aSStack_a4 [12];
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 local_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  String aSStack_5c [8];
  String aSStack_54 [8];
  undefined4 local_4c [2];
  String aSStack_44 [8];
  int local_3c;
  
  local_3c = __stack_chk_guard;
  iVar4 = AbyssEngine::ApplicationManager::GetElapsedTimeMillis(*(ApplicationManager **)(this + 8));
  if ((iVar4 < 0x97) &&
     (iVar4 = AbyssEngine::ApplicationManager::GetElapsedTimeMillis
                        (*(ApplicationManager **)(this + 8)), iVar4 < 0)) {
    uVar5 = 0;
  }
  else {
    iVar4 = AbyssEngine::ApplicationManager::GetElapsedTimeMillis
                      (*(ApplicationManager **)(this + 8));
    if (iVar4 < 0x97) {
      uVar5 = AbyssEngine::ApplicationManager::GetElapsedTimeMillis
                        (*(ApplicationManager **)(this + 8));
    }
    else {
      uVar5 = 0x96;
    }
  }
  auVar37._8_8_ = in_q8._8_8_ & 0xffff0000ffff0000 | (ulonglong)uVar5 & 0xffff;
  auVar37._0_8_ = in_q8._0_8_ & 0xffff0000ffff0000 | (ulonglong)uVar5 & 0xffff;
  pMVar24 = this + 0x40;
  *(uint *)pMVar24 = uVar5;
  auVar37 = VectorAdd(*(undefined1 (*) [16])(this + 0x30),auVar37,8);
  *(longlong *)(this + 0x30) = auVar37._0_8_;
  *(longlong *)(this + 0x38) = auVar37._8_8_;
  if (this[0x156] != (MGame)0x0) {
    iVar4 = GetKeyState("Right");
    if (iVar4 == 0) {
      if (this[0x156] == (MGame)0x0) goto LAB_001ac8d6;
      iVar4 = GetKeyState("Left");
      if (iVar4 != 0) {
        freeCamTouchBegin(this,400,400,(void *)0x3039);
        iVar4 = 0x194;
        goto LAB_001ac81e;
      }
    }
    else {
      freeCamTouchBegin(this,400,400,(void *)0x3039);
      iVar4 = 0x18c;
LAB_001ac81e:
      freeCamTouchMove(this,iVar4,400,(void *)0x3039);
      freeCamTouchEnd(this,extraout_r1,extraout_r2,(void *)0x3039);
    }
    if (this[0x156] != (MGame)0x0) {
      iVar4 = GetKeyState("Down");
      if (iVar4 == 0) {
        if ((this[0x156] == (MGame)0x0) || (iVar4 = GetKeyState("Up"), iVar4 == 0))
        goto LAB_001ac8d6;
        freeCamTouchBegin(this,400,400,(void *)0x3039);
        iVar4 = 0x18c;
      }
      else {
        freeCamTouchBegin(this,400,400,(void *)0x3039);
        iVar4 = 0x194;
      }
      freeCamTouchMove(this,400,iVar4,(void *)0x3039);
      freeCamTouchEnd(this,extraout_r1_00,extraout_r2_00,(void *)0x3039);
    }
  }
LAB_001ac8d6:
  iVar23 = Globals::mouseDeltaY;
  iVar4 = Globals::mouseDeltaX;
  if ((((*(int *)(this + 0x14) == 3) && (Globals::mouseCursorActivated != 0)) &&
      (Globals::is_hacking_visible == 0)) &&
     (Globals::mouseDeltaY != 0 || Globals::mouseDeltaX != 0)) {
    iVar28 = *(int *)(this + 0x1a0);
    iVar29 = *(int *)(this + 0x1a4);
    freeCamTouchBegin(this,400,400,(void *)0x3039);
    freeCamTouchMove(this,(iVar4 - iVar28) / 2 + 400,(iVar23 - iVar29) / 2 + 400,(void *)0x3039);
    freeCamTouchEnd(this,extraout_r1_01,extraout_r2_01,(void *)0x3039);
    Globals::mouseDeltaX = 0;
    Globals::mouseDeltaY = 0;
  }
  iVar4 = Globals::mouseDeltaY;
  *(int *)(this + 0x1a0) = Globals::mouseDeltaX;
  *(int *)(this + 0x1a4) = iVar4;
  iVar4 = PlayerEgo::isDockingToAsteroid(*(PlayerEgo **)(this + 0x58));
  if (iVar4 == 1) {
    Globals::mouseDeltaX = 0;
    Globals::mouseDeltaY = 0;
  }
  if (Globals::showWingmanMenu != '\0') {
    iVar4 = PlayerEgo::isMining(*(PlayerEgo **)(this + 0x58));
    if ((iVar4 == 0) && (iVar4 = Status::getWingmen(Globals::status), iVar4 != 0)) {
      if (this[0xd2] == (MGame)0x0) {
        this[0xd2] = (MGame)0x1;
        this[0x5d] = (MGame)((byte)this[0x5d] ^ 1);
        pauseSounds(this);
        Hud::initHudMenu(*(Hud **)(this + 0x70),2,*(Level **)(this + 0x74));
      }
      else {
        this[0xd2] = (MGame)0x0;
        Hud::closeHudMenu(*(Hud **)(this + 0x70));
        this[0x5d] = (MGame)0x0;
        resumeSounds(this);
      }
    }
    Globals::showWingmanMenu = '\0';
  }
  MVar22 = this[0x5d];
  if (MVar22 != this[0x19e]) {
    if (MVar22 == (MGame)0x0) {
      PlayerEgo::ResumeEngineSound(*(PlayerEgo **)(this + 0x58));
      puVar6 = (uint *)Level::getEnemies(*(Level **)(this + 0x74));
      if ((puVar6 != (uint *)0x0) && (*puVar6 != 0)) {
        uVar5 = 0;
        do {
          KIPlayer::ResumeEngineSound(*(KIPlayer **)(puVar6[1] + uVar5 * 4));
          uVar5 = uVar5 + 1;
        } while (uVar5 < *puVar6);
      }
    }
    else {
      PlayerEgo::PauseEngineSound(*(PlayerEgo **)(this + 0x58));
      puVar6 = (uint *)Level::getEnemies(*(Level **)(this + 0x74));
      if ((puVar6 != (uint *)0x0) && (*puVar6 != 0)) {
        uVar5 = 0;
        do {
          KIPlayer::PauseEngineSound(*(KIPlayer **)(puVar6[1] + uVar5 * 4));
          uVar5 = uVar5 + 1;
        } while (uVar5 < *puVar6);
      }
    }
    MVar22 = this[0x5d];
    this[0x19e] = MVar22;
  }
  if (((MVar22 == (MGame)0x0) ||
      (((this[0x156] != (MGame)0x0 &&
        (iVar4 = MenuTouchWindow::isShowingMessage(*(MenuTouchWindow **)(this + 0x84)), iVar4 == 0))
       && (iVar4 = MenuTouchWindow::isMakingScreenshot(*(MenuTouchWindow **)(this + 0x84)),
          iVar4 == 0)))) && (*(int *)(this + 0x14) == 3)) {
    if (this[0x156] != (MGame)0x0) {
      Level::update((ulonglong)CONCAT14(this[0x5f],*(undefined4 *)(this + 0x74)),false);
    }
    iVar4 = AbyssEngine::ApplicationManager::GetEngine(*(ApplicationManager **)(this + 8));
    fVar33 = *(float *)(iVar4 + 0x350);
    uVar5 = in_fpscr & 0xfffffff;
    fVar34 = -fVar33;
    if (0.0 < fVar33) {
      fVar34 = fVar33;
    }
    uVar26 = uVar5 | (uint)(fVar34 < 0.2) << 0x1f | (uint)(fVar34 == 0.2) << 0x1e;
    in_fpscr = uVar26 | (uint)NAN(fVar34) << 0x1c;
    bVar1 = (byte)(uVar26 >> 0x18);
    if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
      fVar34 = *(float *)(this + 0xb8) + fVar33 * -50.0;
      uVar26 = uVar5 | (uint)(fVar34 < 20000.0) << 0x1f | (uint)(fVar34 == 20000.0) << 0x1e;
      uVar32 = uVar26 | (uint)NAN(fVar34) << 0x1c;
      *(float *)(this + 0xb8) = fVar34;
      bVar1 = (byte)(uVar26 >> 0x18);
      if ((bool)(bVar1 >> 6 & 1) || bVar1 >> 7 != ((byte)(uVar32 >> 0x1c) & 1)) {
        in_fpscr = uVar5;
        if (fVar34 < 1500.0) {
          uVar7 = 0x44bb8000;
          fVar34 = 1500.0;
          goto LAB_001acb22;
        }
      }
      else {
        uVar7 = 0x469c4000;
        uVar5 = uVar32;
        fVar34 = 20000.0;
LAB_001acb22:
        *(undefined4 *)(this + 0xb8) = uVar7;
        in_fpscr = uVar5;
      }
      TargetFollowCamera::zoomTarget(*(TargetFollowCamera **)(this + 0xf0),fVar34);
    }
    iVar4 = AbyssEngine::ApplicationManager::GetEngine(*(ApplicationManager **)(this + 8));
    *(float *)(iVar4 + 0x350) = *(float *)(iVar4 + 0x350) * 0.9;
  }
  if (this[0x5d] == (MGame)0x0) {
    iVar23 = *(int *)(this + 0x164);
    iVar4 = 0;
    if (iVar23 != 0) {
      iVar28 = *(int *)pMVar24;
      if (iVar23 < 0) {
        *(int *)(this + 0x164) = iVar23 - iVar28;
        iVar4 = -*(int *)(this + 0x168);
        if (iVar23 - iVar28 < iVar4) {
          bVar31 = false;
          bVar25 = true;
          *(undefined4 *)(this + 0x164) = 0;
LAB_001acbf6:
          Hud::setTimeExtender(*(Hud **)(this + 0x70),true,bVar25,true,bVar31);
          iVar4 = extraout_r1_02;
        }
      }
      else {
        if (iVar23 <= iVar28) {
          FModSound::setDownPitch(Globals::sound,false);
          fVar34 = (float)Hud::setTimeExtender(*(Hud **)(this + 0x70),true,false,false,false);
          FModSound::play(Globals::sound,0x45f,(Vector *)0x0,(Vector *)0x0,fVar34);
          iVar28 = *(int *)(this + 0x40);
          iVar23 = *(int *)(this + 0x164);
        }
        iVar4 = iVar23 - iVar28;
        *(int *)(this + 0x164) = iVar4;
        if (iVar4 == 0) {
          *(undefined4 *)(this + 0x164) = 0xffffffff;
        }
        else if (0 < iVar4) {
          bVar31 = true;
          fVar34 = (float)VectorSignedToFloat(iVar28,(byte)(in_fpscr >> 0x16) & 3);
          bVar25 = false;
          *(int *)(this + 0x44) = (int)(fVar34 * 0.7);
          *(int *)(this + 0x40) = (int)(fVar34 * 0.3);
          goto LAB_001acbf6;
        }
      }
    }
    Status::incPlayingTime(CONCAT44(iVar4,Globals::status));
    if (((*(char *)(*(int *)(this + 0x7c) + 0x54) == '\0') &&
        (iVar4 = PlayerEgo::aboutToReachAutoTarget(*(PlayerEgo **)(this + 0x58)), iVar4 == 0)) &&
       (iVar4 = Radio::isShowingMessage(*(Radio **)(this + 0x80)), iVar4 != 1)) {
      fVar34 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x40),(byte)(in_fpscr >> 0x16) & 3)
      ;
      uVar5 = (uint)(*(float *)(this + 0x160) * fVar34);
      *(int *)(this + 0x40) = (int)(*(float *)(this + 0x160) * fVar34);
    }
    else {
      *(undefined4 *)(this + 0x160) = 0x3f800000;
      TargetFollowCamera::setFastForwardMode(*(TargetFollowCamera **)(this + 0xf0),false);
      *(undefined1 *)(*(int *)(this + 0x58) + 0x84) = 1;
      uVar5 = *(uint *)(this + 0x40);
    }
    iVar23 = *(int *)(this + 0x78);
    uVar26 = *(uint *)(iVar23 + 8);
    iVar4 = ((int)uVar5 >> 0x1f) + *(int *)(iVar23 + 0xc) + (uint)CARRY4(uVar5,uVar26);
    *(uint *)(iVar23 + 8) = uVar5 + uVar26;
    *(int *)(iVar23 + 0xc) = iVar4;
    if ((((int)uVar26 < 0x1389) && ((int)(uint)(uVar5 + uVar26 < 0x1389) <= iVar4)) &&
       (iVar4 = PlayerEgo::hasVolatileGoods(*(PlayerEgo **)(this + 0x58)), iVar4 == 1)) {
      Hud::hudEvent(*(int *)(this + 0x70),(PlayerEgo *)0x2d,*(int *)(this + 0x58));
    }
    if (this[0x5f] == (MGame)0x0) {
      uVar5 = *(uint *)(this + 0x40);
      uVar26 = *(uint *)(this + 0x48);
      *(uint *)(this + 0x48) = uVar26 + uVar5;
      *(uint *)(this + 0x4c) =
           *(int *)(this + 0x4c) + ((int)uVar5 >> 0x1f) + (uint)CARRY4(uVar26,uVar5);
      if (((*(int *)(this + 0x14) != 3) &&
          (iVar4 = PlayerEgo::isDockingToAsteroid(*(PlayerEgo **)(this + 0x58)), iVar4 == 0)) &&
         (iVar4 = PlayerEgo::isDockedToAsteroid(*(PlayerEgo **)(this + 0x58)), iVar4 == 0)) {
        iVar4 = AbyssEngine::ApplicationManager::GetEngine(*(ApplicationManager **)(this + 8));
        fVar34 = *(float *)(iVar4 + 0x350);
        uVar5 = in_fpscr & 0xfffffff;
        uVar26 = uVar5 | (uint)(fVar34 < 1.0) << 0x1f;
        in_fpscr = uVar26 | (uint)NAN(fVar34) << 0x1c;
        if (((byte)(uVar26 >> 0x1f) == ((byte)(in_fpscr >> 0x1c) & 1)) ||
           (in_fpscr = uVar5 | (uint)(fVar34 == -1.0) << 0x1e | (uint)(-1.0 <= fVar34) << 0x1d,
           bVar1 = (byte)(in_fpscr >> 0x18), !(bool)(bVar1 >> 5 & 1) || (bool)(bVar1 >> 6))) {
          *(float *)(this + 0x1ac) = fVar34 + *(float *)(this + 0x1ac);
          iVar4 = AbyssEngine::ApplicationManager::GetEngine(*(ApplicationManager **)(this + 8));
          *(undefined4 *)(iVar4 + 0x350) = 0;
          fVar34 = *(float *)(this + 0x1ac);
          in_fpscr = in_fpscr & 0xfffffff;
          fVar33 = 100.0;
          if (fVar34 < 100.0) {
            fVar33 = fVar34;
          }
          fVar36 = 100.0;
          if (fVar33 < 0.0) {
            fVar36 = 0.0;
          }
          if (100.0 <= fVar34) {
            fVar34 = fVar36;
          }
          if (fVar33 < 0.0) {
            fVar34 = fVar36;
          }
          *(float *)(this + 0x1ac) = fVar34;
          PlayerEgo::setThrust(*(PlayerEgo **)(this + 0x58),fVar34);
          *(float *)(this + 0x1a8) = 1.0 - *(float *)(this + 0x1ac) / 100.0;
          PlayerEgo::throttleChanged(*(PlayerEgo **)(this + 0x58));
        }
      }
      iVar4 = PlayerEgo::isDockingToAsteroid(*(PlayerEgo **)(this + 0x58));
      if ((iVar4 != 0) ||
         (iVar4 = PlayerEgo::isDockedToAsteroid(*(PlayerEgo **)(this + 0x58)), iVar4 == 1)) {
        fVar34 = (float)PlayerEgo::getThrust(*(PlayerEgo **)(this + 0x58));
        in_fpscr = in_fpscr & 0xfffffff;
        if (fVar34 < 1.0) {
          *(undefined4 *)(this + 0x1ac) = 0x42c80000;
          PlayerEgo::setThrust(*(PlayerEgo **)(this + 0x58),1.0);
          iVar4 = AbyssEngine::ApplicationManager::GetEngine(*(ApplicationManager **)(this + 8));
          *(undefined4 *)(iVar4 + 0x350) = 0;
        }
      }
      iVar4 = PlayerEgo::isDockedToAsteroid(*(PlayerEgo **)(this + 0x58));
      if ((iVar4 == 1) && (*(int *)(this + 0x14) != 0)) {
        switchCamera(this,0);
      }
    }
    Layout::update(Globals::layout,*(int *)pMVar24);
    *(int *)(Globals::status + 0x30) = *(int *)(Globals::status + 0x30) - *(int *)pMVar24;
    if (Globals::options[0xf] == '\0') {
      FModSound::updateAll(Globals::sound,(Vector *)0x0,(Vector *)0x0,(Vector *)0x0,(Vector *)0x0);
    }
    iVar4 = PlayerEgo::isDockedToMiningPlant(*(PlayerEgo **)(this + 0x58));
    if (*(int *)(this + 0x50) < 4000) {
      pMVar8 = pMVar24;
      if (0 < *(int *)(this + 0x164)) {
        pMVar8 = this + 0x44;
      }
      PlayerEgo::update(*(PlayerEgo **)(this + 0x58),*(int *)pMVar8,*(Radar **)(this + 0x7c),
                        *(Hud **)(this + 0x70),*(Radio **)(this + 0x80),
                        *(LevelScript **)(this + 0x78),*(int *)(this + 0xd4),(bool)this[0x5f],
                        *(int *)(this + 0x14));
    }
    iVar23 = PlayerEgo::isInRocketControl(*(PlayerEgo **)(this + 0x58));
    Level::update((ulonglong)CONCAT14(this[0x5f],*(undefined4 *)(this + 0x74)),
                  SUB41(*(undefined4 *)(this + 0x40),0));
    if ((iVar23 == 1) &&
       (iVar23 = PlayerEgo::isInRocketControl(*(PlayerEgo **)(this + 0x58)), iVar23 == 0)) {
      switchCamera(this,0);
    }
    if (iVar4 == 0) {
      uVar5 = PlayerEgo::isDockedToMiningPlant(*(PlayerEgo **)(this + 0x58));
      bVar31 = uVar5 == 1;
      if (bVar31) {
        uVar5 = (uint)(byte)this[0xca];
      }
      if (bVar31 && uVar5 == 0) {
        if (*(int *)(this + 0x90) == 0) {
          pCVar9 = operator_new(0x54);
          ChoiceWindow::ChoiceWindow(pCVar9);
          *(ChoiceWindow **)(this + 0x90) = pCVar9;
        }
        pSVar10 = (String *)GameText::getText(Globals::gameText,0x122);
        AbyssEngine::String::String(aSStack_a4,"\n",false);
        AbyssEngine::operator+((AbyssEngine *)&local_98,pSVar10,aSStack_a4);
        AbyssEngine::String::~String(aSStack_a4);
        Status::hardCoreMode();
        pSVar21 = Globals::status;
        AbyssEngine::String::String(aSStack_44,(String *)&local_98,false);
        local_4c[0] = 0;
        AbyssEngine::String::Set(CONCAT44(extraout_r1_03,local_4c));
        uVar7 = AbyssEngine::String::String(aSStack_54,"#",false);
        Status::replaceHash(aSStack_a4,pSVar21,aSStack_44,local_4c,uVar7);
        AbyssEngine::String::operator=((String *)&local_98,aSStack_a4);
        AbyssEngine::String::~String(aSStack_a4);
        AbyssEngine::String::~String(aSStack_54);
        AbyssEngine::String::~String((String *)local_4c);
        AbyssEngine::String::~String(aSStack_44);
        pSVar11 = (Ship *)Status::getShip(Globals::status);
        puVar6 = (uint *)Ship::getCargo(pSVar11);
        if ((puVar6 == (uint *)0x0) || (*puVar6 == 0)) {
LAB_001ad0cc:
          AbyssEngine::String::String((String *)aAStack_b0,"\n",false);
          pSVar10 = (String *)GameText::getText(Globals::gameText,0x11e);
          AbyssEngine::operator+((AbyssEngine *)aSStack_a4,aAStack_b0,pSVar10);
          AbyssEngine::String::operator+=((String *)&local_98,aSStack_a4);
          AbyssEngine::String::~String(aSStack_a4);
          AbyssEngine::String::~String((String *)aAStack_b0);
        }
        else {
          bVar31 = false;
          uVar5 = 0;
          do {
            pIVar30 = *(Item **)(puVar6[1] + uVar5 * 4);
            if ((pIVar30 != (Item *)0x0) && (iVar4 = Item::getSort(pIVar30), iVar4 == 0x17)) {
              AbyssEngine::String::String(aSStack_c8,"\n",false);
              uVar7 = Item::getAmount(pIVar30);
              local_d4[0] = 0;
              AbyssEngine::String::Set(CONCAT44(uVar7,local_d4));
              AbyssEngine::operator+(aAStack_bc,aSStack_c8,(String *)local_d4);
              AbyssEngine::String::String(aSStack_5c,"t ",false);
              AbyssEngine::operator+(aAStack_b0,aAStack_bc,aSStack_5c);
              this_01 = Globals::gameText;
              iVar4 = Item::getIndex(pIVar30);
              pSVar10 = (String *)GameText::getText(this_01,iVar4 + 0x4fa);
              AbyssEngine::operator+((AbyssEngine *)aSStack_a4,aAStack_b0,pSVar10);
              AbyssEngine::String::operator+=((String *)&local_98,(AbyssEngine *)aSStack_a4);
              AbyssEngine::String::~String(aSStack_a4);
              AbyssEngine::String::~String((String *)aAStack_b0);
              AbyssEngine::String::~String(aSStack_5c);
              AbyssEngine::String::~String((String *)aAStack_bc);
              AbyssEngine::String::~String((String *)local_d4);
              AbyssEngine::String::~String(aSStack_c8);
              bVar31 = true;
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 < *puVar6);
          if (!bVar31) goto LAB_001ad0cc;
        }
        ChoiceWindow::set(*(String **)(this + 0x90),(bool)((char)&stack0xffffffdc + -0x74));
        this[0x109] = (MGame)0x1;
        this[0x5d] = (MGame)0x1;
        pauseSounds(this);
        this[0xc6] = (MGame)0x1;
        this[0xca] = (MGame)0x1;
        AbyssEngine::String::~String((String *)&local_98);
      }
    }
  }
  if (Globals::options[0xf] != '\0') {
    pPVar27 = *(PaintCanvas **)(this + 4);
    uVar5 = AbyssEngine::PaintCanvas::CameraGetCurrent(pPVar27);
    puVar12 = (undefined4 *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar27,uVar5);
    uVar7 = Player::velocity;
    local_98 = *puVar12;
    uStack_94 = puVar12[1];
    local_90 = puVar12[2];
    uStack_8c = puVar12[3];
    uStack_88 = puVar12[4];
    local_84 = puVar12[5];
    uStack_80 = puVar12[6];
    uStack_7c = puVar12[7];
    uStack_78 = puVar12[8];
    uStack_74 = puVar12[9];
    local_70 = puVar12[10];
    uStack_6c = puVar12[0xb];
    uStack_68 = puVar12[0xc];
    uStack_64 = puVar12[0xd];
    uStack_60 = puVar12[0xe];
    AbyssEngine::AEMath::MatrixGetPosition((AEMath *)aSStack_c8,(Matrix *)&local_98);
    AbyssEngine::AEMath::operator-((AEMath *)aAStack_bc,(Vector *)aSStack_c8,(Vector *)(this + 400))
    ;
    fVar34 = (float)VectorSignedToFloat(uVar7,(byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::AEMath::operator*((AEMath *)aAStack_b0,fVar34,(Vector *)fVar34);
    fVar34 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x40),(byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::AEMath::operator/((AEMath *)aSStack_a4,(Vector *)aAStack_b0,fVar34);
    AbyssEngine::AEMath::MatrixGetDir((AEMath *)aAStack_bc,(Matrix *)&local_98);
    AbyssEngine::AEMath::operator-((AEMath *)aAStack_b0,(Vector *)aAStack_bc);
    AbyssEngine::AEMath::MatrixGetPosition((AEMath *)aAStack_bc,(Matrix *)&local_98);
    AbyssEngine::AEMath::MatrixGetUp((AEMath *)aSStack_c8,(Matrix *)&local_98);
    FModSound::updateAll
              (Globals::sound,(Vector *)aAStack_bc,(Vector *)aAStack_b0,(Vector *)aSStack_c8,
               (Vector *)aSStack_a4);
    AbyssEngine::AEMath::MatrixGetPosition((AEMath *)local_d4,(Matrix *)&local_98);
    AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 400),(Vector *)local_d4);
  }
  if ((this[0x60] == (MGame)0x0) && (iVar4 = PlayerEgo::getHitpoints(), 0 < iVar4)) {
    if (this[0x5d] != (MGame)0x0) {
      if (((*(int *)(this + 0x84) != 0) && (this[0xd2] == (MGame)0x0)) && (this[0x5e] == (MGame)0x0)
         ) {
        bVar31 = (*(uint *)(this + 0xc4) & 0xff) == 0;
        uVar5 = extraout_r2_02;
        if (bVar31) {
          uVar5 = (uint)(byte)this[0xc1];
        }
        if (((bVar31 && uVar5 == 0) && (this[0xc2] == (MGame)0x0)) &&
           ((this[0xca] == (MGame)0x0 && ((*(uint *)(this + 0xc4) & 0xff0000) == 0)))) {
          fVar34 = (float)MenuTouchWindow::update(*(int *)(this + 0x84));
          if (this[0x156] != (MGame)0x0) {
            TargetFollowCamera::setRumblePercentage(*(TargetFollowCamera **)(this + 0xf0),fVar34,0);
            *(int *)(this + 0x9c) = *(int *)(this + 0x40) + *(int *)(this + 0x9c);
            if (this[0x154] == (MGame)0x0) {
              fVar33 = *(float *)(this + 0x134) * *(float *)(this + 0x140);
              fVar34 = -(*(float *)(this + 0x134) * *(float *)(this + 0x140));
              if (0.0 < fVar33) {
                fVar34 = fVar33;
              }
              *(float *)(this + 0x140) = fVar33;
              if (1.0 < fVar34) {
                *(float *)(this + 0x110) = fVar33 + *(float *)(this + 0x110);
              }
              fVar33 = *(float *)(this + 0x138) * *(float *)(this + 0x144);
              fVar34 = -(*(float *)(this + 0x138) * *(float *)(this + 0x144));
              if (0.0 < fVar33) {
                fVar34 = fVar33;
              }
              *(float *)(this + 0x144) = fVar33;
              if (1.0 < fVar34) {
                fVar33 = fVar33 + *(float *)(this + 0x114);
                *(float *)(this + 0x114) = fVar33;
                if (fVar33 <= 200.0) {
                  if (-1 < (int)((uint)(fVar33 < -200.0) << 0x1f)) goto LAB_001aecb6;
                  uVar7 = 0xc3480000;
                }
                else {
                  uVar7 = 0x43480000;
                }
                *(undefined4 *)(this + 0x114) = uVar7;
              }
            }
LAB_001aecb6:
            TargetFollowCamera::rotateAroundTarget
                      (*(TargetFollowCamera **)(this + 0xf0),*(float *)(this + 0x110) * -0.005,
                       extraout_s1_00,*(float *)(this + 0x110));
            TargetFollowCamera::update(*(TargetFollowCamera **)(this + 0xf0),*(int *)(this + 0x40));
          }
          iVar4 = MenuTouchWindow::isInMissionScreen(*(MenuTouchWindow **)(this + 0x84));
          if (iVar4 == 1) {
            Status::incPlayingTime(CONCAT44(pMVar24,Globals::status));
          }
        }
      }
      if (((this[0x54] != (MGame)0x0) && (this[0xc4] == (MGame)0x0)) &&
         ((this[0xc1] == (MGame)0x0 && ((*(ushort *)(this + 0xc2) & 0xff) == 0)))) {
        if (this[0xca] == (MGame)0x0) {
          if (this[0xd2] == (MGame)0x0) {
            if (*(ushort *)(this + 0xc2) < 0x100) {
              if (this[0x5e] != (MGame)0x0) {
                Layout::update(Globals::layout,*(int *)(this + 0x40));
                DialogueWindow::update(*(DialogueWindow **)(this + 0x88),*(int *)(this + 0x40));
              }
            }
            else {
              Status::incPlayingTime(ZEXT48(Globals::status));
              StarMap::update(*(int *)(this + 0x8c));
            }
          }
        }
        else {
          ChoiceWindow::update(*(int *)(this + 0x90));
        }
      }
      goto LAB_001af898;
    }
    iVar4 = PlayerEgo::isDockingToPlanet(*(PlayerEgo **)(this + 0x58));
    if ((iVar4 == 1) && (iVar4 = Status::getCurrentCampaignMission(Globals::status), iVar4 == 0x18))
    {
      iVar4 = Radar::getPlanetDockIndex(*(Radar **)(this + 0x7c));
      pMVar13 = (Mission *)Status::getCampaignMission(Globals::status);
      iVar23 = Mission::getTargetStation(pMVar13);
      if (iVar4 == iVar23) {
        pSVar11 = (Ship *)Status::getShip(Globals::status);
        iVar4 = Ship::getFirstEquipmentOfSort(pSVar11,0xd);
        if (iVar4 != 0) {
          pSVar11 = (Ship *)Status::getShip(Globals::status);
          iVar4 = Ship::getFirstEquipmentOfSort(pSVar11,0x11);
          if (iVar4 != 0) goto LAB_001ad30e;
        }
        this[0x5d] = (MGame)0x1;
        pauseSounds(this);
        if (*(DialogueWindow **)(this + 0x88) != (DialogueWindow *)0x0) {
          pvVar15 = (void *)DialogueWindow::~DialogueWindow(*(DialogueWindow **)(this + 0x88));
          operator_delete(pvVar15);
          *(undefined4 *)(this + 0x88) = 0;
        }
        pDVar16 = operator_new(0x6c);
        pSVar10 = (String *)GameText::getText(Globals::gameText,0x214);
        pSVar17 = (String *)GameText::getText(Globals::gameText,0x643);
        DialogueWindow::DialogueWindow(pDVar16,pSVar10,pSVar17,(int *)&DAT_0026b8e0);
        *(DialogueWindow **)(this + 0x88) = pDVar16;
        this[0x5e] = (MGame)0x1;
        PlayerEgo::stopPlanetDock(*(PlayerEgo **)(this + 0x58));
        PlayerEgo::setAutoPilot(*(PlayerEgo **)(this + 0x58),(KIPlayer *)0x0);
        goto LAB_001af898;
      }
    }
LAB_001ad30e:
    iVar4 = PlayerEgo::isDockedToPlanet(*(PlayerEgo **)(this + 0x58));
    pSVar21 = Globals::status;
    this_00 = Globals::galaxy;
    if (iVar4 == 1) {
      iVar4 = Radar::getPlanetDockIndex(*(Radar **)(this + 0x7c));
      pSVar14 = (Station *)Galaxy::getStation(this_00,iVar4);
      Status::departStation(pSVar21,pSVar14);
      Level::setInitStreamOut();
      uVar7 = Player::getHitpoints((Player *)**(undefined4 **)(this + 0x58));
      *(undefined4 *)(Globals::status + 100) = uVar7;
      uVar7 = Player::getShieldHP((Player *)**(undefined4 **)(this + 0x58));
      *(undefined4 *)(Globals::status + 0x5c) = uVar7;
      uVar7 = Player::getArmorHP((Player *)**(undefined4 **)(this + 0x58));
      *(undefined4 *)(Globals::status + 0x60) = uVar7;
      uVar7 = Player::getGammaHP((Player *)**(undefined4 **)(this + 0x58));
      *(undefined4 *)(Globals::status + 0x68) = uVar7;
      uVar7 = PlayerEgo::getCurrentSecondaryWeaponIndex(*(PlayerEgo **)(this + 0x58));
      *(undefined4 *)(Globals::status + 0xf4) = uVar7;
      Globals::switch_to_target_setting = 1;
      this[0x54] = (MGame)0x0;
      AbyssEngine::ApplicationManager::SetCurrentApplicationModule
                (*(ApplicationManager **)(this + 8),2);
      goto LAB_001af898;
    }
    iVar4 = PlayerEgo::shouldSwitchToStandardCam(*(PlayerEgo **)(this + 0x58));
    if (iVar4 == 1) {
      switchCamera(this,0);
    }
    iVar4 = PlayerEgo::shouldSwitchToFreeLookCam(*(PlayerEgo **)(this + 0x58));
    if (iVar4 == 1) {
      switchCamera(this,3);
      *(undefined4 *)(this + 0x110) = 0xc2c40000;
      *(undefined4 *)(this + 0x114) = 0x420c0000;
      *(undefined4 *)(this + 0xb8) = 0x456d8000;
      fVar34 = (float)TargetFollowCamera::rotateAroundTarget
                                (*(TargetFollowCamera **)(this + 0xf0),extraout_s0,extraout_s1,
                                 extraout_s2);
      TargetFollowCamera::zoomTarget(*(TargetFollowCamera **)(this + 0xf0),fVar34);
    }
    if (this[0xd8] == (MGame)0x0) {
      iVar4 = PlayerEgo::isChargingDrive(*(PlayerEgo **)(this + 0x58));
      if ((iVar4 == 1) && (iVar4 = PlayerEgo::driveReady(*(PlayerEgo **)(this + 0x58)), iVar4 == 1))
      {
        startJumpScene(this);
        goto LAB_001af898;
      }
    }
    else {
      iVar4 = updateJumpScene(this);
      if (iVar4 != 0) goto LAB_001af898;
    }
    uVar38 = LevelScript::startSequenceOver(*(LevelScript **)(this + 0x78));
    iVar4 = (int)((ulonglong)uVar38 >> 0x20);
    if ((int)uVar38 == 0) {
      uVar38 = LevelScript::startSequence(*(LevelScript **)(this + 0x78));
      iVar4 = (int)((ulonglong)uVar38 >> 0x20);
      if ((int)uVar38 == 0) goto LAB_001ad486;
    }
    else {
LAB_001ad486:
      if (((this[0xc1] == (MGame)0x0) && (this[0xc2] == (MGame)0x0)) &&
         ((iVar4 = dockEvent((int)this,iVar4), iVar4 != 0 || (this[0xc3] != (MGame)0x0))))
      goto LAB_001af898;
    }
    if ((int)(uint)(*(uint *)(this + 0x48) < 0x1389) <= *(int *)(this + 0x4c)) {
      if ((((int)(uint)(*(uint *)(*(int *)(this + 0x78) + 8) < 0x1389) <=
            *(int *)(*(int *)(this + 0x78) + 0xc)) && (this[0xd8] == (MGame)0x0)) &&
         (this[0x5e] == (MGame)0x0)) {
        iVar4 = Status::getCurrentCampaignMission(Globals::status);
        if ((iVar4 == 0x17) &&
           (iVar4 = PlayerEgo::isMining(*(PlayerEgo **)(this + 0x58)), iVar4 == 0)) {
          pMVar13 = (Mission *)Status::getMission(Globals::status);
          iVar4 = Mission::isEmpty(pMVar13);
          if (iVar4 != 1) goto LAB_001ada30;
          lVar39 = Status::getPlayingTime(Globals::status);
          iVar4 = (int)((ulonglong)(lVar39 - *(longlong *)(Globals::status + 0x100)) >> 0x20);
          bVar31 = 3600000 < (uint)(lVar39 - *(longlong *)(Globals::status + 0x100));
          if ((int)(-(uint)bVar31 - iVar4) < 0 ==
              (SBORROW4(0,iVar4) != SBORROW4(-iVar4,(uint)bVar31))) goto LAB_001ada30;
          this[0x5d] = (MGame)0x1;
          pauseSounds(this);
          if (*(DialogueWindow **)(this + 0x88) != (DialogueWindow *)0x0) {
            pvVar15 = (void *)DialogueWindow::~DialogueWindow(*(DialogueWindow **)(this + 0x88));
            operator_delete(pvVar15);
            *(undefined4 *)(this + 0x88) = 0;
          }
          iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
          iVar23 = 0x216;
          if (iVar4 == 0) {
            iVar23 = 0x215;
          }
          pDVar16 = operator_new(0x6c);
          pSVar10 = (String *)GameText::getText(Globals::gameText,iVar23);
          pSVar17 = (String *)GameText::getText(Globals::gameText,0x642);
          fVar34 = (float)DialogueWindow::DialogueWindow
                                    (pDVar16,pSVar10,pSVar17,(int *)&DAT_0026b8cc);
          *(DialogueWindow **)(this + 0x88) = pDVar16;
          iVar23 = 0x1d1;
          if (iVar4 == 0) {
            iVar23 = 0x1d0;
          }
          FModSound::play(Globals::sound,iVar23,(Vector *)0x0,(Vector *)0x0,fVar34);
LAB_001adb3e:
          this[0x5e] = (MGame)0x1;
          this[0x109] = (MGame)0x1;
          uVar38 = Status::getPlayingTime(Globals::status);
          *(undefined8 *)(Globals::status + 0x100) = uVar38;
        }
        else {
LAB_001ada30:
          iVar4 = Status::getCurrentCampaignMission(Globals::status);
          if ((iVar4 == 0x18) &&
             (iVar4 = PlayerEgo::isMining(*(PlayerEgo **)(this + 0x58)), iVar4 == 0)) {
            pMVar13 = (Mission *)Status::getMission(Globals::status);
            iVar4 = Mission::isEmpty(pMVar13);
            if (iVar4 == 1) {
              lVar39 = Status::getPlayingTime(Globals::status);
              iVar4 = (int)((ulonglong)(lVar39 - *(longlong *)(Globals::status + 0x100)) >> 0x20);
              bVar31 = 3600000 < (uint)(lVar39 - *(longlong *)(Globals::status + 0x100));
              if ((int)(-(uint)bVar31 - iVar4) < 0 !=
                  (SBORROW4(0,iVar4) != SBORROW4(-iVar4,(uint)bVar31))) {
                this[0x5d] = (MGame)0x1;
                pauseSounds(this);
                if (*(DialogueWindow **)(this + 0x88) != (DialogueWindow *)0x0) {
                  pvVar15 = (void *)DialogueWindow::~DialogueWindow
                                              (*(DialogueWindow **)(this + 0x88));
                  operator_delete(pvVar15);
                  *(undefined4 *)(this + 0x88) = 0;
                }
                iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
                iVar23 = 0x218;
                if (iVar4 == 0) {
                  iVar23 = 0x217;
                }
                pDVar16 = operator_new(0x6c);
                pSVar10 = (String *)GameText::getText(Globals::gameText,iVar23);
                pSVar17 = (String *)GameText::getText(Globals::gameText,0x643);
                fVar34 = (float)DialogueWindow::DialogueWindow
                                          (pDVar16,pSVar10,pSVar17,(int *)&DAT_0026b8e0);
                *(DialogueWindow **)(this + 0x88) = pDVar16;
                iVar23 = 0x1d4;
                if (iVar4 == 0) {
                  iVar23 = 0x1d3;
                }
                FModSound::play(Globals::sound,iVar23,(Vector *)0x0,(Vector *)0x0,fVar34);
                goto LAB_001adb3e;
              }
            }
          }
          iVar4 = Status::getCurrentCampaignMission(Globals::status);
          if (((0x79 < iVar4) &&
              (iVar4 = Status::getCurrentCampaignMission(Globals::status), iVar4 < 0x7d)) &&
             (iVar4 = PlayerEgo::isMining(*(PlayerEgo **)(this + 0x58)), iVar4 == 0)) {
            pMVar13 = (Mission *)Status::getMission(Globals::status);
            iVar4 = Mission::isEmpty(pMVar13);
            if (iVar4 == 1) {
              lVar39 = Status::getPlayingTime(Globals::status);
              iVar4 = (int)((ulonglong)(lVar39 - *(longlong *)(Globals::status + 0x100)) >> 0x20);
              bVar31 = 3600000 < (uint)(lVar39 - *(longlong *)(Globals::status + 0x100));
              if ((((int)(-(uint)bVar31 - iVar4) < 0 !=
                    (SBORROW4(0,iVar4) != SBORROW4(-iVar4,(uint)bVar31))) &&
                  ((*(ushort *)(this + 0xd8) & 0xff) == 0)) && (*(ushort *)(this + 0xd8) < 0x100)) {
                iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
                iVar23 = Status::getCurrentCampaignMission(Globals::status);
                iVar28 = 0xc5e;
                if (iVar23 == 0x7a) {
                  iVar28 = 0xc5c;
                }
                Level::createRadioMessage(*(Level **)(this + 0x74),0x1c,iVar28 + iVar4);
                uVar38 = Status::getPlayingTime(Globals::status);
                *(undefined8 *)(Globals::status + 0x100) = uVar38;
                goto LAB_001adcca;
              }
            }
          }
          iVar4 = Status::inAlienOrbit(Globals::status);
          if (((iVar4 == 0) && (Globals::status[0x178] != (Status)0x0)) &&
             ((lVar39 = Status::getPlayingTime(Globals::status),
              (int)(uint)((uint)(lVar39 - *(longlong *)(Globals::status + 0x100)) < 0x2ee1) <=
              (int)((ulonglong)(lVar39 - *(longlong *)(Globals::status + 0x100)) >> 0x20) &&
              (((*(ushort *)(this + 0xd8) & 0xff) == 0 && (*(ushort *)(this + 0xd8) < 0x100)))))) {
            iVar4 = Status::getCurrentCampaignMission(Globals::status);
            uVar5 = 0;
            iVar23 = 0;
            if (iVar4 < 0x5d) {
              uVar5 = 0xffffffff;
            }
            do {
              iVar28 = (&DAT_0025d4d4)[iVar23];
              iVar4 = Status::getCurrentCampaignMission(Globals::status);
              iVar23 = iVar23 + 1;
              if (iVar28 <= iVar4) {
                uVar5 = uVar5 + 1;
              }
            } while (iVar23 != 2);
            if (uVar5 < 3) {
              Globals::status[0x178] = (Status)0x0;
              Level::createRadioMessage(*(Level **)(this + 0x74),0x1b,uVar5);
            }
          }
        }
LAB_001adcca:
        if (Globals::hints[0x17] == '\0') {
          pSVar11 = (Ship *)Status::getShip(Globals::status);
          iVar4 = Ship::hasBooster(pSVar11);
          if ((iVar4 != 1) ||
             (iVar4 = Status::getCurrentCampaignMission(Globals::status), iVar4 < 2))
          goto LAB_001add68;
          if (*(int *)(this + 0x90) == 0) {
            pCVar9 = operator_new(0x54);
            ChoiceWindow::ChoiceWindow(pCVar9);
            *(ChoiceWindow **)(this + 0x90) = pCVar9;
          }
          GameText::getText(Globals::gameText,0x254);
          Globals::replaceKeyBindingTokens((String *)&local_98);
          ChoiceWindow::set(*(ChoiceWindow **)(this + 0x90),(String *)&local_98);
          this[0xca] = (MGame)0x1;
          this[0x109] = (MGame)0x1;
          this[0x5d] = (MGame)0x1;
          pauseSounds(this);
          Globals::hints[0x17] = '\x01';
        }
        else {
LAB_001add68:
          if (Globals::hints[0x21] == '\0') {
            pSVar11 = (Ship *)Status::getShip(Globals::status);
            iVar4 = Ship::hasJumpDrive(pSVar11);
            if (iVar4 == 1) {
              if (*(int *)(this + 0x90) == 0) {
                pCVar9 = operator_new(0x54);
                ChoiceWindow::ChoiceWindow(pCVar9);
                *(ChoiceWindow **)(this + 0x90) = pCVar9;
              }
              GameText::getText(Globals::gameText,0x24e);
              Globals::replaceKeyBindingTokens((String *)&local_98);
              ChoiceWindow::set(*(ChoiceWindow **)(this + 0x90),(String *)&local_98);
              this[0xca] = (MGame)0x1;
              this[0x109] = (MGame)0x1;
              this[0x5d] = (MGame)0x1;
              pauseSounds(this);
              Globals::hints[0x21] = '\x01';
              goto LAB_001adfbe;
            }
          }
          if (Globals::hints[0x22] == '\0') {
            pSVar11 = (Ship *)Status::getShip(Globals::status);
            iVar4 = Ship::hasCloak(pSVar11);
            if (iVar4 == 1) {
              if (*(int *)(this + 0x90) == 0) {
                pCVar9 = operator_new(0x54);
                ChoiceWindow::ChoiceWindow(pCVar9);
                *(ChoiceWindow **)(this + 0x90) = pCVar9;
              }
              GameText::getText(Globals::gameText,0x251);
              Globals::replaceKeyBindingTokens((String *)&local_98);
              ChoiceWindow::set(*(ChoiceWindow **)(this + 0x90),(String *)&local_98);
              this[0xca] = (MGame)0x1;
              this[0x109] = (MGame)0x1;
              this[0x5d] = (MGame)0x1;
              pauseSounds(this);
              Globals::hints[0x22] = '\x01';
              goto LAB_001adfbe;
            }
          }
          if (((Globals::hints[0x20] == '\0') &&
              (iVar4 = PlayerEgo::isAutoPilot(*(PlayerEgo **)(this + 0x58)), iVar4 == 0)) &&
             (iVar4 = Status::getCurrentCampaignMission(Globals::status), 9 < iVar4)) {
            pMVar13 = (Mission *)Status::getMission(Globals::status);
            iVar4 = Mission::isEmpty(pMVar13);
            if (iVar4 == 1) {
              if (*(int *)(this + 0x90) == 0) {
                pCVar9 = operator_new(0x54);
                ChoiceWindow::ChoiceWindow(pCVar9);
                *(ChoiceWindow **)(this + 0x90) = pCVar9;
              }
              GameText::getText(Globals::gameText,0x248);
              Globals::replaceKeyBindingTokens((String *)&local_98);
              ChoiceWindow::set(*(ChoiceWindow **)(this + 0x90),(String *)&local_98);
              this[0xca] = (MGame)0x1;
              this[0x109] = (MGame)0x1;
              this[0x5d] = (MGame)0x1;
              pauseSounds(this);
              Globals::hints[0x20] = '\x01';
              goto LAB_001adfbe;
            }
          }
          if ((*(int *)(Globals::status + 0x24) == 0) || (Globals::hints[0x15] != '\0')) {
            if (Globals::hints[0x1c] == '\0') {
              this_02 = (Standing *)Status::getStanding(Globals::status);
              iVar4 = Standing::isEnemyWithAnyone(this_02);
              if (iVar4 == 1) {
                this[0x5d] = (MGame)0x1;
                pauseSounds(this);
                pCVar9 = *(ChoiceWindow **)(this + 0x90);
                if (pCVar9 == (ChoiceWindow *)0x0) {
                  pCVar9 = operator_new(0x54);
                  ChoiceWindow::ChoiceWindow(pCVar9);
                  *(ChoiceWindow **)(this + 0x90) = pCVar9;
                }
                pSVar10 = (String *)GameText::getText(Globals::gameText,0x288);
                ChoiceWindow::set(pCVar9,pSVar10);
                this[0xca] = (MGame)0x1;
                this[0x109] = (MGame)0x1;
                Globals::hints[0x1c] = '\x01';
                goto LAB_001af898;
              }
            }
            if ((this[0x1de] == (MGame)0x0) &&
               (iVar4 = Status::getCurrentCampaignMission(Globals::status), iVar4 == 5)) {
              this[0x5d] = (MGame)0x1;
              pauseSounds(this);
              pCVar9 = *(ChoiceWindow **)(this + 0x90);
              if (pCVar9 == (ChoiceWindow *)0x0) {
                pCVar9 = operator_new(0x54);
                ChoiceWindow::ChoiceWindow(pCVar9);
                *(ChoiceWindow **)(this + 0x90) = pCVar9;
              }
              pSVar10 = (String *)GameText::getText(Globals::gameText,0x26b);
              ChoiceWindow::set(pCVar9,pSVar10);
              this[0xca] = (MGame)0x1;
              this[0x109] = (MGame)0x1;
              this[0x1de] = (MGame)0x1;
              goto LAB_001af898;
            }
            if (Globals::hints[0x11] == '\0') {
              iVar4 = PlayerEgo::isMining(*(PlayerEgo **)(this + 0x58));
              if (((iVar4 == 0) && (this[0x1dd] == (MGame)0x0)) &&
                 (iVar4 = Status::getCurrentCampaignMission(Globals::status), iVar4 == 2)) {
                iVar4 = Player::getHitpoints((Player *)**(undefined4 **)(this + 0x58));
                iVar23 = Player::getMaxHitpoints((Player *)**(undefined4 **)(this + 0x58));
                if ((iVar4 < iVar23) ||
                   ((int)(uint)(*(uint *)(*(int *)(this + 0x78) + 8) < 0x9c41) <=
                    *(int *)(*(int *)(this + 0x78) + 0xc))) {
                  this[0x5d] = (MGame)0x1;
                  pauseSounds(this);
                  if (*(int *)(this + 0x90) == 0) {
                    pCVar9 = operator_new(0x54);
                    ChoiceWindow::ChoiceWindow(pCVar9);
                    *(ChoiceWindow **)(this + 0x90) = pCVar9;
                  }
                  pSVar10 = (String *)GameText::getText(Globals::gameText,0x6bd);
                  AbyssEngine::String::String((String *)&local_98,pSVar10,false);
                  Globals::replaceKeyBindingTokens(aSStack_a4);
                  AbyssEngine::String::operator=((String *)&local_98,aSStack_a4);
                  AbyssEngine::String::~String(aSStack_a4);
                  ChoiceWindow::set(*(ChoiceWindow **)(this + 0x90),(String *)&local_98);
                  this[0xca] = (MGame)0x1;
                  this[0x109] = (MGame)0x1;
                  this[0x1dd] = (MGame)0x1;
                  goto LAB_001adfbe;
                }
              }
              if (((Globals::hints[0x11] == '\0') &&
                  (iVar4 = PlayerEgo::isMining(*(PlayerEgo **)(this + 0x58)), iVar4 == 1)) &&
                 (Globals::hints[0x11] == '\0')) {
                this[0x5d] = (MGame)0x1;
                pauseSounds(this);
                pCVar9 = *(ChoiceWindow **)(this + 0x90);
                if (pCVar9 == (ChoiceWindow *)0x0) {
                  pCVar9 = operator_new(0x54);
                  ChoiceWindow::ChoiceWindow(pCVar9);
                  *(ChoiceWindow **)(this + 0x90) = pCVar9;
                }
                pSVar10 = (String *)GameText::getText(Globals::gameText,0x26c);
                ChoiceWindow::set(pCVar9,pSVar10);
                this[0xca] = (MGame)0x1;
                this[0x109] = (MGame)0x1;
                Globals::hints[0x11] = '\x01';
                goto LAB_001af898;
              }
            }
            if (((Globals::hints[0x12] == '\0') &&
                (iVar4 = PlayerEgo::isMining(*(PlayerEgo **)(this + 0x58)), iVar4 == 1)) &&
               (iVar4 = Status::getCurrentCampaignMission(Globals::status), 3 < iVar4)) {
              this[0x5d] = (MGame)0x1;
              pauseSounds(this);
              pCVar9 = *(ChoiceWindow **)(this + 0x90);
              if (pCVar9 == (ChoiceWindow *)0x0) {
                pCVar9 = operator_new(0x54);
                ChoiceWindow::ChoiceWindow(pCVar9);
                *(ChoiceWindow **)(this + 0x90) = pCVar9;
              }
              pSVar10 = (String *)GameText::getText(Globals::gameText,0x26d);
              ChoiceWindow::set(pCVar9,pSVar10);
              this[0xca] = (MGame)0x1;
              this[0x109] = (MGame)0x1;
              Globals::hints[0x12] = '\x01';
              goto LAB_001af898;
            }
            iVar4 = Status::getCurrentCampaignMission(Globals::status);
            if (((iVar4 == 2) && (Globals::hints[0x37] == '\0')) &&
               (iVar4 = PlayerEgo::lostMiningGame(*(PlayerEgo **)(this + 0x58)), iVar4 == 1)) {
              this[0x5d] = (MGame)0x1;
              pauseSounds(this);
              pCVar9 = *(ChoiceWindow **)(this + 0x90);
              if (pCVar9 == (ChoiceWindow *)0x0) {
                pCVar9 = operator_new(0x54);
                ChoiceWindow::ChoiceWindow(pCVar9);
                *(ChoiceWindow **)(this + 0x90) = pCVar9;
              }
              pSVar10 = (String *)GameText::getText(Globals::gameText,0x269);
              ChoiceWindow::set(pCVar9,pSVar10);
              this[0xca] = (MGame)0x1;
              this[0x109] = (MGame)0x1;
              Globals::hints[0x37] = '\x01';
              goto LAB_001af898;
            }
            if (((Globals::hints[0x14] == '\0') &&
                (iVar4 = Hud::cargoFull(*(Hud **)(this + 0x70)), iVar4 == 1)) &&
               (iVar4 = Status::getCurrentCampaignMission(Globals::status), 6 < iVar4)) {
              this[0x5d] = (MGame)0x1;
              pauseSounds(this);
              pCVar9 = *(ChoiceWindow **)(this + 0x90);
              if (pCVar9 == (ChoiceWindow *)0x0) {
                pCVar9 = operator_new(0x54);
                ChoiceWindow::ChoiceWindow(pCVar9);
                *(ChoiceWindow **)(this + 0x90) = pCVar9;
              }
              pSVar10 = (String *)GameText::getText(Globals::gameText,0x27c);
              ChoiceWindow::set(pCVar9,pSVar10);
              this[0xca] = (MGame)0x1;
              this[0x109] = (MGame)0x1;
              Globals::hints[0x14] = '\x01';
              goto LAB_001af898;
            }
            if ((Globals::hints[0x23] == '\0') &&
               (iVar4 = Status::inAlienOrbit(Globals::status), iVar4 == 0)) {
              pSVar18 = (SolarSystem *)Status::getSystem(Globals::status);
              iVar4 = SolarSystem::getRace(pSVar18);
              if (iVar4 == 2) {
                Level::createRadioMessage(*(Level **)(this + 0x74),5,0);
                Globals::hints[0x23] = '\x01';
                this[0xdc] = (MGame)0x1;
                goto LAB_001af898;
              }
            }
            if (((Globals::hints[0x23] != '\0') &&
                (Globals::hints[0x24] == '\0' && this[0xdc] == (MGame)0x0)) &&
               (iVar4 = Status::inAlienOrbit(Globals::status), iVar4 == 0)) {
              pSVar18 = (SolarSystem *)Status::getSystem(Globals::status);
              iVar4 = SolarSystem::getRace(pSVar18);
              if (iVar4 == 2) {
                Level::createRadioMessage(*(Level **)(this + 0x74),6,0);
                Globals::hints[0x24] = '\x01';
                goto LAB_001af898;
              }
            }
            if (Globals::hints[0x25] == '\0') {
              pSVar11 = (Ship *)Status::getShip(Globals::status);
              iVar4 = Ship::getFirstEquipmentOfSort(pSVar11,0xd);
              if ((iVar4 != 0) &&
                 (iVar4 = PlayerEgo::isMining(*(PlayerEgo **)(this + 0x58)), iVar4 == 0)) {
                pMVar13 = (Mission *)Status::getMission(Globals::status);
                iVar4 = Mission::isEmpty(pMVar13);
                if ((iVar4 == 1) &&
                   (iVar4 = Status::getCurrentCampaignMission(Globals::status), iVar4 == 0x18)) {
                  this[0x5d] = (MGame)0x1;
                  pauseSounds(this);
                  if (*(DialogueWindow **)(this + 0x88) != (DialogueWindow *)0x0) {
                    pvVar15 = (void *)DialogueWindow::~DialogueWindow
                                                (*(DialogueWindow **)(this + 0x88));
                    operator_delete(pvVar15);
                    *(undefined4 *)(this + 0x88) = 0;
                  }
                  pDVar16 = operator_new(0x6c);
                  pSVar10 = (String *)GameText::getText(Globals::gameText,0x778);
                  pSVar17 = (String *)GameText::getText(Globals::gameText,0x643);
                  fVar34 = (float)DialogueWindow::DialogueWindow
                                            (pDVar16,pSVar10,pSVar17,(int *)&DAT_0026b8e0);
                  *(DialogueWindow **)(this + 0x88) = pDVar16;
                  FModSound::play(Globals::sound,0x1cf,(Vector *)0x0,(Vector *)0x0,fVar34);
                  this[0x5e] = (MGame)0x1;
                  this[0x109] = (MGame)0x1;
                  Globals::hints[0x25] = '\x01';
                  goto LAB_001af898;
                }
              }
            }
            if ((Globals::hints[0x28] == '\0') &&
               (iVar4 = PlayerEgo::isHacking(*(PlayerEgo **)(this + 0x58)), iVar4 == 1)) {
              this[0x5d] = (MGame)0x1;
              pauseSounds(this);
              pCVar9 = *(ChoiceWindow **)(this + 0x90);
              if (pCVar9 == (ChoiceWindow *)0x0) {
                pCVar9 = operator_new(0x54);
                ChoiceWindow::ChoiceWindow(pCVar9);
                *(ChoiceWindow **)(this + 0x90) = pCVar9;
              }
              pSVar10 = (String *)GameText::getText(Globals::gameText,599);
              ChoiceWindow::set(pCVar9,pSVar10);
              this[0xca] = (MGame)0x1;
              this[0x109] = (MGame)0x1;
              Globals::hints[0x28] = '\x01';
              goto LAB_001af898;
            }
            if (Globals::hints[0x29] == '\0') {
              iVar4 = Status::getCurrentCampaignMission(Globals::status);
              if (iVar4 == 0x5b) {
                pSVar14 = (Station *)Status::getStation(Globals::status);
                iVar4 = Station::getIndex(pSVar14);
                if (iVar4 != 0x6e) goto LAB_001ae5fc;
                iVar4 = Level::getMessages(*(Level **)(this + 0x74));
                iVar4 = RadioMessage::isOver(*(RadioMessage **)(*(int *)(iVar4 + 4) + 0x10));
                if (iVar4 == 0) goto LAB_001ae5fc;
LAB_001ae642:
                this[0x5d] = (MGame)0x1;
                pauseSounds(this);
                pCVar9 = *(ChoiceWindow **)(this + 0x90);
                if (pCVar9 == (ChoiceWindow *)0x0) {
                  pCVar9 = operator_new(0x54);
                  ChoiceWindow::ChoiceWindow(pCVar9);
                  *(ChoiceWindow **)(this + 0x90) = pCVar9;
                }
                pSVar10 = (String *)GameText::getText(Globals::gameText,600);
                ChoiceWindow::set(pCVar9,pSVar10);
                this[0xca] = (MGame)0x1;
                this[0x109] = (MGame)0x1;
                Globals::hints[0x29] = '\x01';
                goto LAB_001af898;
              }
LAB_001ae5fc:
              iVar4 = Status::getCurrentCampaignMission(Globals::status);
              pSVar21 = Globals::status;
              if (iVar4 != 0x5b) {
                pSVar14 = (Station *)Status::getStation(Globals::status);
                iVar4 = Station::getIndex(pSVar14);
                iVar23 = Status::getCurrentCampaignMission(Globals::status);
                fVar34 = (float)Status::getGammaRayDamagePerSecond(pSVar21,iVar4,iVar23);
                uVar5 = in_fpscr & 0xfffffff | (uint)(fVar34 < 0.0) << 0x1f |
                        (uint)(fVar34 == 0.0) << 0x1e;
                in_fpscr = uVar5 | (uint)NAN(fVar34) << 0x1c;
                bVar1 = (byte)(uVar5 >> 0x18);
                if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1))
                goto LAB_001ae642;
              }
            }
            if ((Globals::hints[0x2c] == '\0') &&
               (iVar4 = PlayerEgo::hasVolatileGoods(*(PlayerEgo **)(this + 0x58)), iVar4 == 1)) {
              this[0x5d] = (MGame)0x1;
              pauseSounds(this);
              pCVar9 = *(ChoiceWindow **)(this + 0x90);
              if (pCVar9 == (ChoiceWindow *)0x0) {
                pCVar9 = operator_new(0x54);
                ChoiceWindow::ChoiceWindow(pCVar9);
                *(ChoiceWindow **)(this + 0x90) = pCVar9;
              }
              pSVar10 = (String *)GameText::getText(Globals::gameText,0x25a);
              ChoiceWindow::set(pCVar9,pSVar10);
              this[0xca] = (MGame)0x1;
              this[0x109] = (MGame)0x1;
              Globals::hints[0x2c] = '\x01';
              goto LAB_001af898;
            }
            if ((Globals::hints[0x2e] == '\0') &&
               (iVar4 = Status::getCurrentCampaignMission(Globals::status), iVar4 == 0x5b)) {
              pSVar14 = (Station *)Status::getStation(Globals::status);
              iVar4 = Station::getIndex(pSVar14);
              if (iVar4 == 0x6e) {
                iVar4 = Level::getMessages(*(Level **)(this + 0x74));
                iVar4 = RadioMessage::isOver(*(RadioMessage **)(*(int *)(iVar4 + 4) + 0x10));
                if (iVar4 == 1) {
                  this[0x5d] = (MGame)0x1;
                  pauseSounds(this);
                  if (*(int *)(this + 0x90) == 0) {
                    pCVar9 = operator_new(0x54);
                    ChoiceWindow::ChoiceWindow(pCVar9);
                    *(ChoiceWindow **)(this + 0x90) = pCVar9;
                  }
                  GameText::getText(Globals::gameText,0x25b);
                  Globals::replaceKeyBindingTokens((String *)&local_98);
                  ChoiceWindow::set(*(ChoiceWindow **)(this + 0x90),(String *)&local_98);
                  this[0xca] = (MGame)0x1;
                  this[0x109] = (MGame)0x1;
                  Globals::hints[0x2e] = '\x01';
                  goto LAB_001adfbe;
                }
              }
            }
            if ((Globals::hints[0x2f] == '\0') &&
               (iVar4 = Status::getCurrentCampaignMission(Globals::status), iVar4 == 0x5b)) {
              pSVar14 = (Station *)Status::getStation(Globals::status);
              iVar4 = Station::getIndex(pSVar14);
              if ((iVar4 == 0x6e) &&
                 ((iVar4 = PlayerEgo::isDockedToDockingPoint(*(PlayerEgo **)(this + 0x58)),
                  iVar4 == 1 && (*(int *)(Globals::status + 0x174) == 10)))) {
                iVar4 = Level::getMessages(*(Level **)(this + 0x74));
                iVar4 = RadioMessage::isOver(*(RadioMessage **)(*(int *)(iVar4 + 4) + 0x18));
                if (iVar4 == 1) {
                  this[0x5d] = (MGame)0x1;
                  pauseSounds(this);
                  if (*(int *)(this + 0x90) == 0) {
                    pCVar9 = operator_new(0x54);
                    ChoiceWindow::ChoiceWindow(pCVar9);
                    *(ChoiceWindow **)(this + 0x90) = pCVar9;
                  }
                  GameText::getText(Globals::gameText,0x25e);
                  Globals::replaceKeyBindingTokens((String *)&local_98);
                  ChoiceWindow::set(*(ChoiceWindow **)(this + 0x90),(String *)&local_98);
                  this[0xca] = (MGame)0x1;
                  this[0x109] = (MGame)0x1;
                  Globals::hints[0x2f] = '\x01';
                  goto LAB_001adfbe;
                }
              }
            }
            if ((Globals::hints[0x30] == '\0') &&
               (iVar4 = Status::getCurrentCampaignMission(Globals::status), iVar4 == 0x5c)) {
              pSVar14 = (Station *)Status::getStation(Globals::status);
              iVar4 = Station::getIndex(pSVar14);
              if ((iVar4 == 0x71) &&
                 ((iVar4 = PlayerEgo::isDockedToDockingPoint(*(PlayerEgo **)(this + 0x58)),
                  iVar4 == 1 && (*(int *)(Globals::status + 0x174) == 0)))) {
                this[0x5d] = (MGame)0x1;
                pauseSounds(this);
                if (*(int *)(this + 0x90) == 0) {
                  pCVar9 = operator_new(0x54);
                  ChoiceWindow::ChoiceWindow(pCVar9);
                  *(ChoiceWindow **)(this + 0x90) = pCVar9;
                }
                GameText::getText(Globals::gameText,0x261);
                Globals::replaceKeyBindingTokens((String *)&local_98);
                ChoiceWindow::set(*(ChoiceWindow **)(this + 0x90),(String *)&local_98);
                this[0xca] = (MGame)0x1;
                this[0x109] = (MGame)0x1;
                Globals::hints[0x30] = '\x01';
                goto LAB_001adfbe;
              }
            }
            if ((((Globals::options[0x35] != '\0') && (Globals::hints[0x26] == '\0')) &&
                (this[0x5e] == (MGame)0x0)) &&
               (iVar4 = PlayerEgo::isMining(*(PlayerEgo **)(this + 0x58)), iVar4 == 0)) {
              pMVar13 = (Mission *)Status::getMission(Globals::status);
              iVar4 = Mission::isEmpty(pMVar13);
              if (((iVar4 != 1) ||
                  (iVar4 = PlayerEgo::isAutoPilot(*(PlayerEgo **)(this + 0x58)), iVar4 != 0)) ||
                 (iVar4 = Status::gameWon(Globals::status), iVar4 != 1)) goto LAB_001ae9d0;
              this[0x5d] = (MGame)0x1;
              pauseSounds(this);
              if (*(DialogueWindow **)(this + 0x88) != (DialogueWindow *)0x0) {
                pvVar15 = (void *)DialogueWindow::~DialogueWindow(*(DialogueWindow **)(this + 0x88))
                ;
                operator_delete(pvVar15);
                *(undefined4 *)(this + 0x88) = 0;
              }
              pDVar16 = operator_new(0x6c);
              DialogueWindow::DialogueWindow(pDVar16);
              *(DialogueWindow **)(this + 0x88) = pDVar16;
              pMVar13 = operator_new(100);
              Mission::Mission(pMVar13,0xa0,0,-1);
              DialogueWindow::set(*(DialogueWindow **)(this + 0x88),pMVar13,1,0x2e);
              this[0x5e] = (MGame)0x1;
              this[0x109] = (MGame)0x1;
              Globals::hints[0x26] = '\x01';
LAB_001aeaaa:
              Status::nextCampaignMission(SUB41(Globals::status,0));
              Status::nextCampaignMission(SUB41(Globals::status,0));
              goto LAB_001af898;
            }
LAB_001ae9d0:
            if (((Globals::options[0x37] != '\0') && (Globals::hints[0x31] == '\0')) &&
               ((this[0x5e] == (MGame)0x0 &&
                (iVar4 = PlayerEgo::isMining(*(PlayerEgo **)(this + 0x58)), iVar4 == 0)))) {
              pMVar13 = (Mission *)Status::getMission(Globals::status);
              iVar4 = Mission::isEmpty(pMVar13);
              if (((iVar4 == 1) &&
                  (iVar4 = PlayerEgo::isAutoPilot(*(PlayerEgo **)(this + 0x58)), iVar4 == 0)) &&
                 (iVar4 = Status::dlc1Won(Globals::status), iVar4 == 1)) {
                this[0x5d] = (MGame)0x1;
                pauseSounds(this);
                if (*(DialogueWindow **)(this + 0x88) != (DialogueWindow *)0x0) {
                  pvVar15 = (void *)DialogueWindow::~DialogueWindow
                                              (*(DialogueWindow **)(this + 0x88));
                  operator_delete(pvVar15);
                  *(undefined4 *)(this + 0x88) = 0;
                }
                pDVar16 = operator_new(0x6c);
                DialogueWindow::DialogueWindow(pDVar16);
                *(DialogueWindow **)(this + 0x88) = pDVar16;
                pMVar13 = operator_new(100);
                Mission::Mission(pMVar13,0xa0,0,-1);
                DialogueWindow::set(*(DialogueWindow **)(this + 0x88),pMVar13,1,0x55);
                this[0x5e] = (MGame)0x1;
                this[0x109] = (MGame)0x1;
                Globals::hints[0x31] = '\x01';
                goto LAB_001aeaaa;
              }
            }
            iVar4 = Status::inBlackMarketSystem(Globals::status);
            if (((iVar4 == 1) && ((*(ushort *)(Globals::status + 0x110) & 0xff) == 0)) &&
               ((*(ushort *)(Globals::status + 0x110) < 0x100 &&
                ((this[0xd0] == (MGame)0x0 &&
                 (iVar4 = Level::getMessages(*(Level **)(this + 0x74)), iVar4 != 0)))))) {
              iVar4 = Level::getMessages(*(Level **)(this + 0x74));
              iVar4 = RadioMessage::isOver((RadioMessage *)**(undefined4 **)(iVar4 + 4));
              if (iVar4 == 1) {
                this[0x5d] = (MGame)0x1;
                pauseSounds(this);
                if (*(int *)(this + 0x90) == 0) {
                  pCVar9 = operator_new(0x54);
                  ChoiceWindow::ChoiceWindow(pCVar9);
                  *(ChoiceWindow **)(this + 0x90) = pCVar9;
                }
                *(undefined4 *)(this + 0xcc) = 0;
                pSVar11 = (Ship *)Status::getShip(Globals::status);
                uVar38 = Ship::getCargo(pSVar11);
                uVar5 = (uint)((ulonglong)uVar38 >> 0x20);
                puVar6 = (uint *)uVar38;
                if (puVar6 != (uint *)0x0) {
                  uVar5 = *puVar6;
                }
                if (puVar6 != (uint *)0x0 && uVar5 != 0) {
                  uVar26 = 0;
                  do {
                    pIVar30 = *(Item **)(puVar6[1] + uVar26 * 4);
                    if (pIVar30 != (Item *)0x0) {
                      iVar4 = Item::getAmount(pIVar30);
                      iVar23 = Item::getSinglePrice(*(Item **)(puVar6[1] + uVar26 * 4));
                      *(int *)(this + 0xcc) = iVar23 * iVar4 + *(int *)(this + 0xcc);
                      uVar5 = *puVar6;
                    }
                    uVar26 = uVar26 + 1;
                  } while (uVar26 < uVar5);
                }
                iVar4 = *(int *)(this + 0xcc);
                if (iVar4 == 0) {
                  iVar4 = 100;
                  *(undefined4 *)(this + 0xcc) = 100;
                }
                uVar5 = in_fpscr & 0xfffffff;
                in_fpscr = uVar5 | (uint)((float)Globals::options._44_4_ == 0.0) << 0x1e |
                           (uint)(0.0 <= (float)Globals::options._44_4_) << 0x1d;
                bVar1 = (byte)(in_fpscr >> 0x18);
                if (!(bool)(bVar1 >> 5 & 1) || (bool)(bVar1 >> 6)) {
                  fVar34 = 0.02;
                }
                else {
                  in_fpscr = uVar5 | (uint)((float)Globals::options._44_4_ == 0.5) << 0x1e;
                  if ((byte)(in_fpscr >> 0x1e) == 0) {
                    pfVar20 = (float *)&DAT_001af9f0;
                    in_fpscr = uVar5 | (uint)((float)Globals::options._44_4_ == 1.0) << 0x1e;
                    if ((byte)(in_fpscr >> 0x1e) != 0) {
                      pfVar20 = (float *)&DAT_001af9f4;
                    }
                    fVar34 = *pfVar20;
                  }
                  else {
                    fVar34 = 0.05;
                  }
                }
                fVar33 = (float)VectorSignedToFloat(iVar4,(byte)(in_fpscr >> 0x16) & 3);
                *(int *)(this + 0xcc) = (int)(fVar34 * fVar33);
                pSVar21 = Globals::status;
                pSVar10 = (String *)GameText::getText(Globals::gameText,0x1c0);
                AbyssEngine::String::String(aSStack_dc,pSVar10,false);
                Layout::formatCredits((int)aSStack_e4);
                uVar7 = AbyssEngine::String::String(aSStack_ec,"#C",false);
                Status::replaceHash(aSStack_a4,pSVar21,aSStack_dc,aSStack_e4,uVar7);
                AbyssEngine::String::~String(aSStack_ec);
                AbyssEngine::String::~String(aSStack_e4);
                AbyssEngine::String::~String(aSStack_dc);
                pSVar21 = Globals::status;
                AbyssEngine::String::String(aSStack_f4,aSStack_a4,false);
                local_fc[0] = 0;
                AbyssEngine::String::Set(CONCAT44(extraout_r1_04,local_fc));
                uVar7 = AbyssEngine::String::String(aSStack_104,"#P",false);
                Status::replaceHash(&local_98,pSVar21,aSStack_f4,local_fc,uVar7);
                AbyssEngine::String::operator=(aSStack_a4,(String *)&local_98);
                AbyssEngine::String::~String((String *)&local_98);
                AbyssEngine::String::~String(aSStack_104);
                AbyssEngine::String::~String((String *)local_fc);
                AbyssEngine::String::~String(aSStack_f4);
                ChoiceWindow::set(*(String **)(this + 0x90),(bool)((char)&stack0xffffffdc + -0x80));
                *(undefined2 *)(this + 0xca) = 0x101;
                this[0x109] = (MGame)0x1;
                this[0xd0] = (MGame)0x1;
                AbyssEngine::String::~String(aSStack_a4);
                goto LAB_001aeed0;
              }
            }
            if ((*(int *)(Globals::status + 0x114) == 0) &&
               (iVar4 = Status::inAlienOrbit(Globals::status), iVar4 == 0)) {
              pSVar14 = (Station *)Status::getStation(Globals::status);
              iVar4 = Station::getIndex(pSVar14);
              if (iVar4 == 0x6c) {
                this[0x5d] = (MGame)0x1;
                pauseSounds(this);
                if (*(DialogueWindow **)(this + 0x88) != (DialogueWindow *)0x0) {
                  pvVar15 = (void *)DialogueWindow::~DialogueWindow
                                              (*(DialogueWindow **)(this + 0x88));
                  operator_delete(pvVar15);
                  *(undefined4 *)(this + 0x88) = 0;
                }
                pDVar16 = operator_new(0x6c);
                pSVar10 = (String *)GameText::getText(Globals::gameText,0x1c9);
                pSVar17 = (String *)GameText::getText(Globals::gameText,0x641);
                fVar34 = (float)DialogueWindow::DialogueWindow
                                          (pDVar16,pSVar10,pSVar17,(int *)&DAT_0026b8b8);
                *(DialogueWindow **)(this + 0x88) = pDVar16;
                FModSound::play(Globals::sound,0x5bc,(Vector *)0x0,(Vector *)0x0,fVar34);
                this[0x5e] = (MGame)0x1;
                this[0x109] = (MGame)0x1;
                *(undefined4 *)(Globals::status + 0x114) = 1;
                goto LAB_001af898;
              }
            }
            goto LAB_001aeed0;
          }
          this[0x5d] = (MGame)0x1;
          pauseSounds(this);
          if (*(int *)(this + 0x90) == 0) {
            pCVar9 = operator_new(0x54);
            ChoiceWindow::ChoiceWindow(pCVar9);
            *(ChoiceWindow **)(this + 0x90) = pCVar9;
          }
          GameText::getText(Globals::gameText,0x27d);
          Globals::replaceKeyBindingTokens((String *)&local_98);
          ChoiceWindow::set(*(ChoiceWindow **)(this + 0x90),(String *)&local_98);
          this[0xca] = (MGame)0x1;
          this[0x109] = (MGame)0x1;
          Globals::hints[0x15] = '\x01';
        }
LAB_001adfbe:
        AbyssEngine::String::~String((String *)&local_98);
        goto LAB_001af898;
      }
LAB_001aeed0:
      if (((int)(uint)(*(uint *)(this + 0x48) < 0x1389) <= *(int *)(this + 0x4c)) &&
         (this[0x5e] == (MGame)0x0)) {
        pMVar13 = (Mission *)Status::getMission(Globals::status);
        iVar4 = Mission::hasFailed(pMVar13);
        if (iVar4 == 0) {
          pMVar13 = (Mission *)Status::getMission(Globals::status);
          iVar4 = Mission::hasWon(pMVar13);
          if (iVar4 == 0) {
            dialogueEvent(this);
          }
        }
      }
    }
  }
  iVar4 = PlayerEgo::boosting(*(PlayerEgo **)(this + 0x58));
  if ((iVar4 == 1) &&
     (iVar4 = PlayerEgo::isDockingToPlanet(*(PlayerEgo **)(this + 0x58)), iVar4 == 0)) {
    pEVar19 = (Engine *)
              AbyssEngine::ApplicationManager::GetEngine(*(ApplicationManager **)(this + 8));
    AbyssEngine::Engine::SetPostEffect(pEVar19,0x1400002,true);
    fVar33 = (float)PlayerEgo::getBoostPercentage(*(PlayerEgo **)(this + 0x58));
    fVar36 = 0.0;
    uVar5 = in_fpscr & 0xfffffff | (uint)(fVar33 < 0.0) << 0x1f | (uint)(fVar33 == 0.0) << 0x1e;
    in_fpscr = uVar5 | (uint)NAN(fVar33) << 0x1c;
    bVar1 = (byte)(uVar5 >> 0x18);
    fVar34 = fVar36;
    if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
      fVar34 = fVar33;
    }
    iVar4 = AbyssEngine::ApplicationManager::GetEngine(*(ApplicationManager **)(this + 8));
    *(float *)(iVar4 + 0x3b8) = fVar34;
    pPVar27 = Globals::Canvas;
    local_98 = 0;
    uStack_94 = 0;
    local_90 = 0;
    PlayerEgo::getPosition();
    AbyssEngine::PaintCanvas::GetScreenPosition(pPVar27,(Vector *)aSStack_a4,(Vector *)&local_98);
    pEVar19 = (Engine *)
              AbyssEngine::ApplicationManager::GetEngine(*(ApplicationManager **)(this + 8));
    uVar7 = AbyssEngine::Engine::GetDisplayWidth(pEVar19);
    pfVar20 = (float *)AbyssEngine::AEMath::Vector::operator[]((Vector *)&local_98,0);
    fVar34 = (float)VectorSignedToFloat(uVar7,(byte)(in_fpscr >> 0x16) & 3);
    *pfVar20 = *pfVar20 / fVar34;
    pfVar20 = (float *)AbyssEngine::AEMath::Vector::operator[]((Vector *)&local_98,1);
    fVar33 = *pfVar20;
    pEVar19 = (Engine *)
              AbyssEngine::ApplicationManager::GetEngine(*(ApplicationManager **)(this + 8));
    uVar7 = AbyssEngine::Engine::GetDisplayHeight(pEVar19);
    fVar34 = (float)VectorSignedToFloat(uVar7,(byte)(in_fpscr >> 0x16) & 3);
    pfVar20 = (float *)AbyssEngine::AEMath::Vector::operator[]((Vector *)&local_98,1);
    *pfVar20 = 1.0 - fVar33 / fVar34;
    iVar4 = AbyssEngine::ApplicationManager::GetEngine(*(ApplicationManager **)(this + 8));
    AbyssEngine::AEMath::Vector::operator=((Vector *)(iVar4 + 0x3bc),(Vector *)&local_98);
    fVar34 = (float)PlayerEgo::getBoostPercentage(*(PlayerEgo **)(this + 0x58));
    *(float *)(this + 0x6c) = fVar34 * 0.35000002 + 1.22;
    pPVar27 = Globals::Canvas;
    iVar4 = Status::inAlienOrbit(Globals::status);
    if (iVar4 == 1) {
      iVar4 = Status::getCurrentCampaignMission(Globals::status);
      pfVar20 = (float *)&DAT_001afa40;
      if (iVar4 < 0x50) {
        pfVar20 = (float *)&DAT_001afa44;
      }
      fVar35 = *pfVar20;
      fVar34 = extraout_s1_02;
      fVar33 = extraout_s2_01;
    }
    else {
      fVar35 = 300000.0;
      fVar34 = extraout_s1_01;
      fVar33 = extraout_s2_00;
    }
    AbyssEngine::PaintCanvas::CameraSetPerspective((uint)pPVar27,fVar35,fVar34,fVar33);
    this_03 = *(TargetFollowCamera **)(this + 0xf0);
    fVar34 = (float)PlayerEgo::getBoostPercentage(*(PlayerEgo **)(this + 0x58));
    in_fpscr = in_fpscr & 0xfffffff;
    if (0.0 <= fVar34) {
      fVar36 = (float)PlayerEgo::getBoostPercentage(*(PlayerEgo **)(this + 0x58));
    }
    fVar34 = (float)PlayerEgo::getBoostSpeed(*(PlayerEgo **)(this + 0x58));
    TargetFollowCamera::setBoostPercentage(this_03,fVar34,(int)fVar36);
  }
  if (this[0x60] == (MGame)0x0) {
    iVar4 = PlayerEgo::isDead(*(PlayerEgo **)(this + 0x58));
    if (iVar4 == 0) {
      pMVar13 = (Mission *)Status::getMission(Globals::status);
      iVar4 = Mission::hasFailed(pMVar13);
      if ((iVar4 == 0) && (iVar4 = successCheck(), iVar4 != 0)) goto LAB_001af898;
    }
    gameOverCheck(this);
  }
  else if ((int)(uint)(*(uint *)(this + 0x48) < 0xbb9) <= *(int *)(this + 0x4c)) {
    *(int *)(this + 0x50) = *(int *)(this + 0x40) + *(int *)(this + 0x50);
  }
  MVar22 = this[0x5f];
  uVar5 = LevelScript::process(*(LevelScript **)(this + 0x78),*(int *)(this + 0x40));
  this[0x5f] = SUB41(uVar5,0);
  if ((MVar22 == (MGame)0x0) && ((uVar5 ^ 1) == 0)) {
    this[0x1d5] = AbyssEngine::Engine::UseAdvancedShader;
    AbyssEngine::Engine::UseAdvancedShader = (MGame)0x1;
    if (0 < *(int *)(this + 0x164)) {
      FModSound::setDownPitch(Globals::sound,false);
      Hud::setTimeExtender(*(Hud **)(this + 0x70),(bool)**(Hud **)(this + 0x70),false,false,false);
    }
    *(undefined4 *)(this + 0x94) = 0;
    *(undefined4 *)(this + 0x98) = 0;
    *(undefined4 *)(this + 0x9c) = 0;
    this[0x154] = (MGame)0x0;
    this[0x5c] = (MGame)0x0;
    this[0x108] = (MGame)0x0;
    Hud::enableFireForTutorial(*(Hud **)(this + 0x70),false);
    iVar4 = PlayerEgo::boosting(*(PlayerEgo **)(this + 0x58));
    if (iVar4 == 1) {
      PlayerEgo::stopBoost(*(PlayerEgo **)(this + 0x58));
    }
    *(undefined4 *)(this + 0x6c) = 0x3f9c28f6;
    pPVar27 = Globals::Canvas;
    iVar4 = Status::inAlienOrbit(Globals::status);
    if (iVar4 == 1) {
      iVar4 = Status::getCurrentCampaignMission(Globals::status);
      pfVar20 = (float *)&DAT_001afa40;
      if (iVar4 < 0x50) {
        pfVar20 = (float *)&DAT_001afa44;
      }
      fVar36 = *pfVar20;
      fVar34 = extraout_s1_05;
      fVar33 = extraout_s2_03;
    }
    else {
      fVar36 = 300000.0;
      fVar34 = extraout_s1_04;
      fVar33 = extraout_s2_02;
    }
    fVar34 = (float)AbyssEngine::PaintCanvas::CameraSetPerspective
                              ((uint)pPVar27,fVar36,fVar34,fVar33);
    TargetFollowCamera::setBoostPercentage(*(TargetFollowCamera **)(this + 0xf0),fVar34,0);
    pEVar19 = (Engine *)
              AbyssEngine::ApplicationManager::GetEngine(*(ApplicationManager **)(this + 8));
    AbyssEngine::Engine::SetPostEffect(pEVar19,0x1400002,false);
    fVar34 = extraout_s1_06;
  }
  else {
    fVar34 = extraout_s1_03;
    if (((uVar5 ^ 1) & (uint)(MVar22 != (MGame)0x0)) == 1) {
      AbyssEngine::Engine::UseAdvancedShader = this[0x1d5];
    }
  }
  if (*(char *)(*(int *)(this + 0x78) + 0x13) != '\0') goto LAB_001af898;
  if (*(char *)(*(int *)(this + 0x78) + 0x12) != '\0') {
    *(undefined4 *)(this + 0x48) = 0x1389;
    *(undefined4 *)(this + 0x4c) = 0;
  }
  if (*(int *)(this + 0x14) == 3) {
    if (this[0x154] == (MGame)0x0) {
      fVar36 = *(float *)(this + 0x134) * *(float *)(this + 0x140);
      in_fpscr = in_fpscr & 0xfffffff;
      fVar33 = -(*(float *)(this + 0x134) * *(float *)(this + 0x140));
      if (0.0 < fVar36) {
        fVar33 = fVar36;
      }
      *(float *)(this + 0x140) = fVar36;
      if (1.0 < fVar33) {
        *(float *)(this + 0x110) = fVar36 + *(float *)(this + 0x110);
      }
      fVar36 = *(float *)(this + 0x138) * *(float *)(this + 0x144);
      fVar33 = -(*(float *)(this + 0x138) * *(float *)(this + 0x144));
      if (0.0 < fVar36) {
        fVar33 = fVar36;
      }
      *(float *)(this + 0x144) = fVar36;
      fVar35 = *(float *)(this + 0x114);
      if (1.0 < fVar33) {
        fVar35 = fVar36 + fVar35;
        *(float *)(this + 0x114) = fVar35;
      }
      uVar5 = in_fpscr | (uint)(fVar35 < 200.0) << 0x1f | (uint)(fVar35 == 200.0) << 0x1e;
      uVar26 = uVar5 | (uint)NAN(fVar35) << 0x1c;
      bVar1 = (byte)(uVar5 >> 0x18);
      if ((bool)(bVar1 >> 6 & 1) || bVar1 >> 7 != ((byte)(uVar26 >> 0x1c) & 1)) {
        if (-200.0 <= fVar35) goto LAB_001af324;
        uVar7 = 0xc3480000;
        fVar35 = -200.0;
      }
      else {
        uVar7 = 0x43480000;
        in_fpscr = uVar26;
        fVar35 = 200.0;
      }
      *(undefined4 *)(this + 0x114) = uVar7;
    }
    else {
      fVar35 = *(float *)(this + 0x114);
    }
LAB_001af324:
    TargetFollowCamera::rotateAroundTarget
              (*(TargetFollowCamera **)(this + 0xf0),fVar35 * -0.005,fVar34,
               *(float *)(this + 0x110) * -0.005);
  }
  pMVar8 = this + 0xf0;
  fVar34 = *(float *)(this + 0x160);
  uVar5 = in_fpscr & 0xfffffff | (uint)(fVar34 < 1.0) << 0x1f | (uint)(fVar34 == 1.0) << 0x1e;
  uVar26 = uVar5 | (uint)NAN(fVar34) << 0x1c;
  bVar1 = (byte)(uVar5 >> 0x18);
  if ((bool)(bVar1 >> 6 & 1) || bVar1 >> 7 != ((byte)(uVar26 >> 0x1c) & 1)) {
    if (0 < *(int *)(this + 0x164)) {
      pMVar24 = this + 0x44;
    }
    TargetFollowCamera::update(*(TargetFollowCamera **)(this + 0xf0),*(int *)pMVar24);
  }
  else {
    iVar4 = 5;
    do {
      if (*(int *)(this + 0x164) < 1) {
        fVar34 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x40),(byte)(uVar26 >> 0x16) & 3)
        ;
        fVar34 = fVar34 / *(float *)(this + 0x160);
      }
      else {
        fVar34 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x44),(byte)(uVar26 >> 0x16) & 3)
        ;
      }
      TargetFollowCamera::update(*(TargetFollowCamera **)(this + 0xf0),(int)fVar34);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  if (this[0x174] != (MGame)0x0) {
    *(int *)(this + 0x170) = *(int *)(this + 0x40) + *(int *)(this + 0x170);
  }
  if (*(int *)(this + 0x14) == 2) {
    TargetFollowCamera::setFirstPersonMatrix
              (*(TargetFollowCamera **)(this + 0xf0),(Matrix *)(**(int **)(this + 0x58) + 4));
    if ((this[0x19d] == (MGame)0x0) &&
       (iVar4 = TargetFollowCamera::hideShipForFirstPersonCam(*(TargetFollowCamera **)pMVar8),
       iVar4 == 1)) {
      this[0x19d] = (MGame)0x1;
      FModSound::enableReverb(Globals::sound,1);
    }
  }
  else if ((this[0x19d] != (MGame)0x0) &&
          (iVar4 = TargetFollowCamera::hideShipForFirstPersonCam(*(TargetFollowCamera **)pMVar8),
          iVar4 == 0)) {
    FModSound::disableReverb(Globals::sound);
    this[0x19d] = (MGame)0x0;
  }
  this_04 = *(PlayerEgo **)(this + 0x58);
  if (this[0x18] == (MGame)0x0) {
    uVar3 = TargetFollowCamera::hideShipForFirstPersonCam(*(TargetFollowCamera **)pMVar8);
  }
  else {
    uVar3 = true;
  }
  PlayerEgo::hideShipForFirstPersonCameraView(this_04,(bool)uVar3);
  if (((this[0x60] == (MGame)0x0) && (this[0x5f] == (MGame)0x0)) &&
     (iVar4 = PlayerEgo::isDead(*(PlayerEgo **)(this + 0x58)), iVar4 == 0)) {
    if ((Level::doInstantJump != '\0') &&
       ((int)(uint)(*(uint *)(*(int *)(this + 0x78) + 8) < 0x1389) <=
        *(int *)(*(int *)(this + 0x78) + 0xc))) {
      Level::doInstantJump = '\0';
      this[0xd9] = (MGame)0x1;
      startChargingJumpDrive(this);
    }
    if ((((this[0x5c] == (MGame)0x0) && (this[0x108] == (MGame)0x0)) &&
        (iVar4 = Hud::firePressed(*(Hud **)(this + 0x70)), iVar4 != 1)) ||
       (iVar4 = PlayerEgo::isDockingToPlanet(*(PlayerEgo **)(this + 0x58)), iVar4 != 0)) {
      if (this[0x155] != (MGame)0x0) {
        this[0x155] = (MGame)0x0;
        PlayerEgo::stopShooting(*(PlayerEgo **)(this + 0x58),0);
      }
    }
    else {
      PlayerEgo::shoot(*(PlayerEgo **)(this + 0x58),*(int *)(this + 0x40),0);
      this[0x155] = (MGame)0x1;
    }
    iVar4 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar4 != 0x30) {
      if (Globals::options[0x11] == '\0') {
        handleAccelerometer(this);
      }
      else {
        fVar34 = (float)Hud::getAnalogX(*(Hud **)(this + 0x70));
        if ((int)((uint)(fVar34 < 0.0) << 0x1f) < 0) {
          iVar4 = *(int *)(this + 0x58);
          fVar34 = (float)Hud::getAnalogX(*(Hud **)(this + 0x70));
          fVar33 = (float)Hud::getAnalogX(*(Hud **)(this + 0x70));
          PlayerEgo::left(iVar4,fVar34 * fVar33);
        }
        else {
          fVar34 = (float)Hud::getAnalogX(*(Hud **)(this + 0x70));
          if (0.0 < fVar34) {
            iVar4 = *(int *)(this + 0x58);
            fVar34 = (float)Hud::getAnalogX(*(Hud **)(this + 0x70));
            fVar33 = (float)Hud::getAnalogX(*(Hud **)(this + 0x70));
            PlayerEgo::right(iVar4,fVar34 * fVar33);
          }
        }
        cVar2 = Globals::options[0x10];
        fVar34 = (float)Hud::getAnalogY(*(Hud **)(this + 0x70));
        iVar4 = (uint)(fVar34 < 0.0) << 0x1f;
        if (cVar2 == '\0') {
          if (iVar4 < 0) {
LAB_001af60e:
            iVar4 = *(int *)(this + 0x58);
            fVar34 = (float)Hud::getAnalogY(*(Hud **)(this + 0x70));
            fVar33 = (float)Hud::getAnalogY(*(Hud **)(this + 0x70));
            PlayerEgo::up(iVar4,fVar34 * fVar33);
          }
          else {
            fVar34 = (float)Hud::getAnalogY(*(Hud **)(this + 0x70));
            if (0.0 < fVar34) goto LAB_001af664;
          }
        }
        else if (iVar4 < 0) {
LAB_001af664:
          iVar4 = *(int *)(this + 0x58);
          fVar34 = (float)Hud::getAnalogY(*(Hud **)(this + 0x70));
          fVar33 = (float)Hud::getAnalogY(*(Hud **)(this + 0x70));
          PlayerEgo::down(iVar4,fVar34 * fVar33);
        }
        else {
          fVar34 = (float)Hud::getAnalogY(*(Hud **)(this + 0x70));
          if (0.0 < fVar34) goto LAB_001af60e;
        }
      }
    }
  }
  this[0x108] = (MGame)0x0;
  iVar4 = PlayerEgo::isInWormhole(*(PlayerEgo **)(this + 0x58));
  if (iVar4 != 1) goto LAB_001af898;
  pMVar13 = (Mission *)Status::getMission(Globals::status);
  iVar4 = Mission::isCampaignMission(pMVar13);
  if (iVar4 == 1) {
    iVar4 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar4 < 0x29) {
      if (iVar4 != 0x1d) {
        if (iVar4 != 0x28) {
LAB_001af786:
          Status::nextCampaignMission(SUB41(Globals::status,0));
          goto LAB_001af794;
        }
        iVar4 = LevelScript::getEvent(*(LevelScript **)(this + 0x78));
        if (3 < iVar4) {
          Status::nextCampaignMission(SUB41(Globals::status,0));
          iVar4 = Level::getEnemies(*(Level **)(this + 0x74));
          Level::lastMissionFreighterHitpoints =
               Player::getHitpoints(*(Player **)(**(int **)(iVar4 + 4) + 4));
          goto LAB_001af794;
        }
      }
    }
    else if (iVar4 != 0x29) {
      if (iVar4 != 0x2a) goto LAB_001af786;
LAB_001af794:
      Level::removeObjectives(*(Level **)(this + 0x74));
      Status::setMission(Globals::status,Mission::empty);
      goto LAB_001af7b0;
    }
    Player::setHitpoints((Player *)**(undefined4 **)(this + 0x58),0);
  }
  else {
LAB_001af7b0:
    Status::setMission(Globals::status,Mission::empty);
    iVar4 = Status::inAlienOrbit(Globals::status);
    if (iVar4 == 1) {
      iVar4 = Status::getCurrentCampaignMission(Globals::status);
      pSVar21 = Globals::status;
      if (iVar4 == 0x2a) goto LAB_001af898;
      pSVar14 = (Station *)Galaxy::getStation(Globals::galaxy,*(int *)(Globals::status + 0x84));
    }
    else {
      Status::setStation(Globals::status,*(Station **)(Globals::status + 0x78));
      pSVar14 = *(Station **)(Globals::status + 0x78);
      pSVar21 = Globals::status;
    }
    Status::departStation(pSVar21,pSVar14);
    uVar7 = Player::getHitpoints((Player *)**(undefined4 **)(this + 0x58));
    *(undefined4 *)(Globals::status + 100) = uVar7;
    uVar7 = Player::getShieldHP((Player *)**(undefined4 **)(this + 0x58));
    *(undefined4 *)(Globals::status + 0x5c) = uVar7;
    uVar7 = Player::getArmorHP((Player *)**(undefined4 **)(this + 0x58));
    *(undefined4 *)(Globals::status + 0x60) = uVar7;
    uVar7 = Player::getGammaHP((Player *)**(undefined4 **)(this + 0x58));
    *(undefined4 *)(Globals::status + 0x68) = uVar7;
    uVar7 = PlayerEgo::getCurrentSecondaryWeaponIndex(*(PlayerEgo **)(this + 0x58));
    *(undefined4 *)(Globals::status + 0xf4) = uVar7;
    Level::programmedStation = 0;
    Level::initStreamOutPosition = 1;
    Level::comingFromAlienWorld = 1;
    Globals::switch_to_target_setting = 1;
    AbyssEngine::ApplicationManager::SetCurrentApplicationModule
              (*(ApplicationManager **)(this + 8),2);
    this[0x54] = (MGame)0x0;
  }
LAB_001af898:
  if (__stack_chk_guard != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== MGame::updateJumpScene  @0x001afad4  (916 bytes)
/* MGame::updateJumpScene() */

void __thiscall MGame::updateJumpScene(MGame *this)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  PlayerEgo *this_00;
  undefined4 uVar4;
  int iVar5;
  bool bVar6;
  uint in_fpscr;
  float extraout_s0;
  float fVar7;
  float extraout_s1;
  float extraout_s2;
  float local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  AEMath aAStack_28 [12];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  if ((this[0xd9] == (MGame)0x0) || (*(int *)(this + 0x10c) == 0)) {
    iVar1 = Level::getLandmarks(*(Level **)(this + 0x74));
    if (*(int *)(*(int *)(iVar1 + 4) + 4) != 0) {
      iVar1 = Level::getLandmarks(*(Level **)(this + 0x74));
      iVar1 = PlayerJumpgate::timeToJump(*(PlayerJumpgate **)(*(int *)(iVar1 + 4) + 4));
      if (iVar1 == 0) goto LAB_001afb36;
    }
LAB_001afb32:
    bVar6 = true;
  }
  else {
    iVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 0x10c) + 0xc));
    iVar5 = *(int *)(iVar1 + 0x114);
    bVar6 = 0x6a4 < *(uint *)(iVar1 + 0x110);
    if ((int)(-(uint)bVar6 - iVar5) < 0 != (SBORROW4(0,iVar5) != SBORROW4(-iVar5,(uint)bVar6)))
    goto LAB_001afb32;
LAB_001afb36:
    iVar1 = *(int *)(this + 0x40);
    if (this[0xd9] == (MGame)0x0) {
      iVar5 = iVar1 * -3;
    }
    else {
      iVar5 = iVar1 * -5;
    }
    local_34 = VectorSignedToFloat(iVar1 * 5,(byte)(in_fpscr >> 0x16) & 3);
    local_30 = VectorSignedToFloat(iVar1 << 1,(byte)(in_fpscr >> 0x16) & 3);
    local_2c = VectorSignedToFloat(iVar5,(byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::AEMath::MatrixRotateVector
              (aAStack_28,(Matrix *)(**(int **)(this + 0x58) + 4),(Vector *)&local_34);
    AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0xe0),(Vector *)aAStack_28);
    TargetFollowCamera::translate
              (*(TargetFollowCamera **)(this + 0xf0),extraout_s0,extraout_s1,extraout_s2);
    if (this[0xd9] == (MGame)0x0) {
      iVar1 = Level::getLandmarks(*(Level **)(this + 0x74));
      (**(code **)(**(int **)(*(int *)(iVar1 + 4) + 4) + 0x28))(aAStack_28);
    }
    else {
      AEGeometry::getPosition();
    }
    AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0xe0),(Vector *)aAStack_28);
    bVar6 = false;
  }
  if (this[0xd9] != (MGame)0x0) {
    uVar2 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 0x10c) + 0xc));
    AbyssEngine::Transform::Update((ulonglong)uVar2,SUB41(*(undefined4 *)(this + 0x40),0));
  }
  iVar1 = TargetFollowCamera::getPosition(*(TargetFollowCamera **)(this + 0xf0));
  fVar7 = *(float *)(this + 0xe8) + -10000.0;
  if (((int)((uint)(*(float *)(iVar1 + 8) < fVar7) << 0x1f) < 0) && (this[0xd9] == (MGame)0x0)) {
    iVar1 = Level::getLandmarks(*(Level **)(this + 0x74));
    PlayerJumpgate::activate(*(PlayerJumpgate **)(*(int *)(iVar1 + 4) + 4));
    PlayerEgo::getPosition();
    fVar7 = *(float *)(this + 0xe8) + -16500.0;
    if ((fVar7 <= local_38) && (this[0xc9] == (MGame)0x0)) {
      FModSound::stop(Globals::sound,*(int *)(*(int *)(this + 0x58) + 0x1c));
      FModSound::stop(Globals::sound,0x8d5);
      FModSound::stop(Globals::sound,0x8d4);
      fVar7 = (float)FModSound::stop(Globals::sound,0x23);
      fVar7 = (float)FModSound::play(Globals::sound,0x1f,(Vector *)0x0,(Vector *)0x0,fVar7);
      this[0xc9] = (MGame)0x1;
    }
  }
  if (bVar6) {
    PlayerEgo::setSpeed(*(PlayerEgo **)(this + 0x58),fVar7);
    PlayerEgo::setVisible(*(PlayerEgo **)(this + 0x58),false);
    PlayerEgo::setExhaustVisible(*(PlayerEgo **)(this + 0x58),false);
  }
  if (this[0xd9] == (MGame)0x0) {
    iVar1 = Level::getLandmarks(*(Level **)(this + 0x74));
    iVar1 = PlayerJumpgate::animationEnded(*(PlayerJumpgate **)(*(int *)(iVar1 + 4) + 4));
    if (iVar1 != 1) goto LAB_001afe4e;
  }
  else {
    iVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 0x10c) + 0xc));
    if (*(char *)(iVar1 + 0xed) != '\0') goto LAB_001afe4e;
  }
  iVar1 = Status::getCurrentCampaignMission(Globals::status);
  if ((iVar1 == 0x2a) && (iVar1 = Status::inAlienOrbit(Globals::status), iVar1 == 1)) {
    fVar7 = (float)LevelScript::setEvent(*(LevelScript **)(this + 0x78),6);
    PlayerEgo::setSpeed(*(PlayerEgo **)(this + 0x58),fVar7);
    iVar1 = Level::getLandmarks(*(Level **)(this + 0x74));
    piVar3 = *(int **)(*(int *)(iVar1 + 4) + 0xc);
    (**(code **)(*piVar3 + 0x48))(piVar3,0x46c35000,0x469c4000,0xc756d800);
    iVar1 = Level::getLandmarks(*(Level **)(this + 0x74));
    (**(code **)(**(int **)(*(int *)(iVar1 + 4) + 0xc) + 0x28))((Vector *)aAStack_28);
    AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0xe0),(Vector *)aAStack_28);
    PlayerEgo::setPosition
              (*(undefined4 *)(this + 0x58),*(undefined4 *)(this + 0xe0),
               *(undefined4 *)(this + 0xe4),*(undefined4 *)(this + 0xe8));
    this_00 = *(PlayerEgo **)(this + 0x58);
    this_00[0x25] = (PlayerEgo)0x1;
    this[0xd8] = (MGame)0x0;
    PlayerEgo::resetChargingDrive(this_00);
  }
  else {
    Status::departStation(Globals::status,Level::programmedStation);
    Level::setInitStreamOut();
    if (this[0xd9] == (MGame)0x0) {
      Status::jumpgateUsed(Globals::status);
    }
    iVar1 = Station::equals(Level::programmedStation,*(Station **)(Globals::status + 0x78));
    if (iVar1 == 1) {
      Level::initStreamOutPosition = 1;
      Level::comingFromAlienWorld = 1;
      Status::setStation(Globals::status,*(Station **)(Globals::status + 0x78));
    }
    Level::programmedStation = (Station *)0x0;
    uVar4 = Player::getHitpoints((Player *)**(undefined4 **)(this + 0x58));
    *(undefined4 *)(Globals::status + 100) = uVar4;
    uVar4 = Player::getShieldHP((Player *)**(undefined4 **)(this + 0x58));
    *(undefined4 *)(Globals::status + 0x5c) = uVar4;
    uVar4 = Player::getArmorHP((Player *)**(undefined4 **)(this + 0x58));
    *(undefined4 *)(Globals::status + 0x60) = uVar4;
    uVar4 = Player::getGammaHP((Player *)**(undefined4 **)(this + 0x58));
    *(undefined4 *)(Globals::status + 0x68) = uVar4;
    uVar4 = PlayerEgo::getCurrentSecondaryWeaponIndex(*(PlayerEgo **)(this + 0x58));
    *(undefined4 *)(Globals::status + 0xf4) = uVar4;
    Globals::switch_to_target_setting = 1;
    this[0x54] = (MGame)0x0;
    AbyssEngine::ApplicationManager::SetCurrentApplicationModule
              (*(ApplicationManager **)(this + 8),2);
  }
LAB_001afe4e:
  if (__stack_chk_guard - local_1c == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_1c);
}

// ===== MGame::dockEvent  @0x001afebc  (1266 bytes)
/* MGame::dockEvent(int, int) */

void MGame::dockEvent(int param_1,int param_2)

{
  undefined1 uVar1;
  Mission *pMVar2;
  int iVar3;
  String *pSVar4;
  int iVar5;
  Station *this;
  StarMap *this_00;
  Engine *this_01;
  undefined4 uVar6;
  ChoiceWindow *pCVar7;
  String aSStack_6c [8];
  String aSStack_64 [8];
  String aSStack_5c [8];
  AbyssEngine aAStack_54 [8];
  AbyssEngine aAStack_4c [8];
  AbyssEngine aAStack_44 [8];
  AbyssEngine aAStack_3c [8];
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  uVar6 = *(undefined4 *)(param_1 + 0x74);
  PlayerEgo::getPosition();
  uVar1 = Level::collideStream(uVar6,local_28,uStack_24,uStack_20);
  *(undefined1 *)(param_1 + 199) = uVar1;
  uVar6 = *(undefined4 *)(param_1 + 0x74);
  PlayerEgo::getPosition();
  uVar1 = Level::collideStation(uVar6,local_34,uStack_30,uStack_2c);
  *(undefined1 *)(param_1 + 200) = uVar1;
  pMVar2 = (Mission *)Status::getMission(Globals::status);
  iVar3 = Mission::isEmpty(pMVar2);
  if (iVar3 == 0) {
    pMVar2 = (Mission *)Status::getMission(Globals::status);
    iVar3 = Mission::getType(pMVar2);
    if (iVar3 == 0xb) goto LAB_001aff84;
    pMVar2 = (Mission *)Status::getMission(Globals::status);
    iVar3 = Mission::getType(pMVar2);
    if (iVar3 == 0) goto LAB_001aff84;
    pMVar2 = (Mission *)Status::getMission(Globals::status);
    iVar3 = Mission::getType(pMVar2);
    if (iVar3 == 0xbd) goto LAB_001aff84;
    pMVar2 = (Mission *)Status::getMission(Globals::status);
    iVar3 = Mission::getType(pMVar2);
    if (iVar3 == 0xab) goto LAB_001aff84;
    pMVar2 = (Mission *)Status::getMission(Globals::status);
    iVar3 = Mission::getType(pMVar2);
    if (iVar3 == 0xac) goto LAB_001aff84;
    if (((*(char *)(param_1 + 200) == '\0') && (*(char *)(param_1 + 199) == '\0')) ||
       (iVar3 = PlayerEgo::isAutoPilot(*(PlayerEgo **)(param_1 + 0x58)), iVar3 != 1))
    goto LAB_001b0320;
LAB_001b030e:
    Hud::hudEvent(*(int *)(param_1 + 0x70),(PlayerEgo *)0x15,*(int *)(param_1 + 0x58));
  }
  else {
LAB_001aff84:
    if (*(char *)(param_1 + 199) != '\0') {
      iVar3 = PlayerEgo::goingToStream(*(PlayerEgo **)(param_1 + 0x58));
      if (((iVar3 == 1) &&
          (iVar3 = PlayerEgo::isDockingToStream(*(PlayerEgo **)(param_1 + 0x58)), iVar3 == 0)) &&
         (iVar3 = PlayerEgo::isDockedToStream(*(PlayerEgo **)(param_1 + 0x58)), iVar3 == 0)) {
        PlayerEgo::dockToStream(*(PlayerEgo **)(param_1 + 0x58),true);
        *(undefined1 *)(param_1 + 0x109) = 1;
        *(undefined1 *)(param_1 + 0x154) = 0;
        goto LAB_001b0320;
      }
      if (*(char *)(param_1 + 199) != '\0') {
        uVar6 = Player::getHitpoints((Player *)**(undefined4 **)(param_1 + 0x58));
        *(undefined4 *)(Globals::status + 100) = uVar6;
        uVar6 = Player::getShieldHP((Player *)**(undefined4 **)(param_1 + 0x58));
        *(undefined4 *)(Globals::status + 0x5c) = uVar6;
        uVar6 = Player::getArmorHP((Player *)**(undefined4 **)(param_1 + 0x58));
        *(undefined4 *)(Globals::status + 0x60) = uVar6;
        uVar6 = Player::getGammaHP((Player *)**(undefined4 **)(param_1 + 0x58));
        *(undefined4 *)(Globals::status + 0x68) = uVar6;
        uVar6 = PlayerEgo::getCurrentSecondaryWeaponIndex(*(PlayerEgo **)(param_1 + 0x58));
        *(undefined4 *)(Globals::status + 0xf4) = uVar6;
        iVar3 = PlayerEgo::isAutoPilot(*(PlayerEgo **)(param_1 + 0x58));
        if ((Level::programmedStation == 0) || (iVar3 != 1)) {
          if (*(char *)(param_1 + 0xc3) != '\0') {
            *(undefined4 *)(param_1 + 0x30) = 0;
            *(undefined4 *)(param_1 + 0x34) = 0;
            goto LAB_001b0320;
          }
          PlayerEgo::isAutoPilot(*(PlayerEgo **)(param_1 + 0x58));
          iVar3 = PlayerEgo::goingToStream(*(PlayerEgo **)(param_1 + 0x58));
          if (iVar3 != 1) goto LAB_001b0320;
          if (Level::programmedStation == 0) {
            *(undefined1 *)(param_1 + 0x109) = 1;
            *(undefined1 *)(param_1 + 0x154) = 0;
            if (*(int *)(param_1 + 0x8c) == 0) {
              this_00 = operator_new(0x1e8);
              StarMap::StarMap(this_00,false,(Mission *)0x0,false,-1);
              *(StarMap **)(param_1 + 0x8c) = this_00;
            }
            this_01 = (Engine *)
                      AbyssEngine::ApplicationManager::GetEngine
                                (*(ApplicationManager **)(param_1 + 8));
            AbyssEngine::Engine::SetPostEffect(this_01,0x1400002,false);
            StarMap::initLights();
            StarMap::setJumpMapMode(*(StarMap **)(param_1 + 0x8c),true,false);
            PlayerEgo::setAutoPilot(*(PlayerEgo **)(param_1 + 0x58),(KIPlayer *)0x0);
            *(undefined1 *)(param_1 + 0xc3) = 1;
            *(undefined1 *)(param_1 + 0x5d) = 1;
            pauseSounds((MGame *)param_1);
            *(undefined1 *)(param_1 + 0x109) = 1;
            goto LAB_001b0320;
          }
          if (*(char *)(param_1 + 0xc1) != '\0') goto LAB_001b0320;
          *(undefined1 *)(param_1 + 0x109) = 1;
          *(undefined1 *)(param_1 + 0x154) = 0;
          pCVar7 = *(ChoiceWindow **)(param_1 + 0x90);
          if (pCVar7 == (ChoiceWindow *)0x0) {
            pCVar7 = operator_new(0x54);
            ChoiceWindow::ChoiceWindow(pCVar7);
            *(ChoiceWindow **)(param_1 + 0x90) = pCVar7;
          }
          pSVar4 = (String *)GameText::getText(Globals::gameText,0x23e);
          AbyssEngine::String::String(aSStack_5c,": ",false);
          AbyssEngine::operator+(aAStack_54,pSVar4,aSStack_5c);
          Station::getName();
          AbyssEngine::operator+(aAStack_4c,aAStack_54,aSStack_64);
          AbyssEngine::String::String(aSStack_6c,"\n",false);
          AbyssEngine::operator+(aAStack_44,aAStack_4c,aSStack_6c);
          pSVar4 = (String *)GameText::getText(Globals::gameText,0x1a5);
          AbyssEngine::operator+(aAStack_3c,aAStack_44,pSVar4);
          ChoiceWindow::set(pCVar7,(bool)((char)&stack0x0000001c + -0x58));
        }
        else {
          if (*(char *)(param_1 + 0xc1) != '\0') goto LAB_001b0320;
          *(undefined1 *)(param_1 + 0x109) = 1;
          *(undefined1 *)(param_1 + 0x154) = 0;
          pCVar7 = *(ChoiceWindow **)(param_1 + 0x90);
          if (pCVar7 == (ChoiceWindow *)0x0) {
            pCVar7 = operator_new(0x54);
            ChoiceWindow::ChoiceWindow(pCVar7);
            *(ChoiceWindow **)(param_1 + 0x90) = pCVar7;
          }
          pSVar4 = (String *)GameText::getText(Globals::gameText,0x23e);
          AbyssEngine::String::String(aSStack_5c,": ",false);
          AbyssEngine::operator+(aAStack_54,pSVar4,aSStack_5c);
          Station::getName();
          AbyssEngine::operator+(aAStack_4c,aAStack_54,aSStack_64);
          AbyssEngine::String::String(aSStack_6c,"\n",false);
          AbyssEngine::operator+(aAStack_44,aAStack_4c,aSStack_6c);
          pSVar4 = (String *)GameText::getText(Globals::gameText,0x1a5);
          AbyssEngine::operator+(aAStack_3c,aAStack_44,pSVar4);
          ChoiceWindow::set(pCVar7,(bool)((char)&stack0x0000001c + -0x58));
        }
        AbyssEngine::String::~String((String *)aAStack_3c);
        AbyssEngine::String::~String((String *)aAStack_44);
        AbyssEngine::String::~String(aSStack_6c);
        AbyssEngine::String::~String((String *)aAStack_4c);
        AbyssEngine::String::~String(aSStack_64);
        AbyssEngine::String::~String((String *)aAStack_54);
        AbyssEngine::String::~String(aSStack_5c);
        ChoiceWindow::left();
        *(undefined1 *)(param_1 + 0xc1) = 1;
        *(undefined1 *)(param_1 + 0x5d) = 1;
        pauseSounds((MGame *)param_1);
        PlayerEgo::setAutoPilot(*(PlayerEgo **)(param_1 + 0x58),(KIPlayer *)0x0);
        goto LAB_001b0320;
      }
    }
    if (*(char *)(param_1 + 200) == '\0') {
      iVar3 = PlayerEgo::getAutoPilotTarget(*(PlayerEgo **)(param_1 + 0x58));
      iVar5 = Level::getLandmarks(*(Level **)(param_1 + 0x74));
      if ((iVar3 != **(int **)(iVar5 + 4)) ||
         (iVar3 = PlayerEgo::collidesWithStation(*(PlayerEgo **)(param_1 + 0x58)), iVar3 != 1))
      goto LAB_001b0320;
    }
    iVar3 = Status::getCurrentCampaignMission(Globals::status);
    if ((0x30 < iVar3) && (iVar3 = Status::getCurrentCampaignMission(Globals::status), iVar3 < 0x37)
       ) {
      this = (Station *)Status::getStation(Globals::status);
      iVar3 = Station::getIndex(this);
      if (iVar3 != 0x4a) goto LAB_001b030e;
    }
    iVar3 = PlayerEgo::goingToStation(*(PlayerEgo **)(param_1 + 0x58));
    if (((iVar3 == 1) && (iVar3 = Status::inAlienOrbit(Globals::status), iVar3 == 0)) &&
       (iVar3 = Status::inEmptyOrbit(Globals::status), iVar3 == 0)) {
      Achievements::checkForNewMedal(Globals::achievements);
      Globals::switch_to_target_setting = 0;
      uVar6 = Player::getHitpoints((Player *)**(undefined4 **)(param_1 + 0x58));
      *(undefined4 *)(Globals::status + 100) = uVar6;
      uVar6 = Player::getShieldHP((Player *)**(undefined4 **)(param_1 + 0x58));
      *(undefined4 *)(Globals::status + 0x5c) = uVar6;
      uVar6 = Player::getArmorHP((Player *)**(undefined4 **)(param_1 + 0x58));
      *(undefined4 *)(Globals::status + 0x60) = uVar6;
      uVar6 = Player::getGammaHP((Player *)**(undefined4 **)(param_1 + 0x58));
      *(undefined4 *)(Globals::status + 0x68) = uVar6;
      AbyssEngine::ApplicationManager::SetCurrentApplicationModule
                (*(ApplicationManager **)(param_1 + 8),5);
      *(undefined1 *)(param_1 + 0x54) = 0;
    }
  }
LAB_001b0320:
  if (__stack_chk_guard - local_1c == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_1c);
}

// ===== MGame::dialogueEvent  @0x001b0498  (334 bytes)
/* MGame::dialogueEvent() */

void __thiscall MGame::dialogueEvent(MGame *this)

{
  int iVar1;
  Mission *pMVar2;
  DialogueWindow *this_00;
  
  iVar1 = LevelScript::startSequenceOver(*(LevelScript **)(this + 0x78));
  if (iVar1 == 1) {
    iVar1 = Status::getCurrentCampaignMission(Globals::status);
    iVar1 = DialogueWindow::hasBriefingDialogue(iVar1);
    if (iVar1 == 0) {
      pMVar2 = (Mission *)Status::getMission(Globals::status);
      iVar1 = Mission::isCampaignMission(pMVar2);
      if (iVar1 != 0) {
        return;
      }
    }
    pMVar2 = (Mission *)Status::getMission(Globals::status);
    iVar1 = Mission::isEmpty(pMVar2);
    if (iVar1 == 0) {
      pMVar2 = (Mission *)Status::getMission(Globals::status);
      iVar1 = Mission::getType(pMVar2);
      if (iVar1 != 8) {
        pMVar2 = (Mission *)Status::getMission(Globals::status);
        iVar1 = Mission::getType(pMVar2);
        if (iVar1 != 0xa6) {
          pMVar2 = (Mission *)Status::getMission(Globals::status);
          iVar1 = Mission::getType(pMVar2);
          if (iVar1 != 0) {
            pMVar2 = (Mission *)Status::getMission(Globals::status);
            iVar1 = Mission::getType(pMVar2);
            if (iVar1 != 0xb7) {
              pMVar2 = (Mission *)Status::getMission(Globals::status);
              iVar1 = Mission::isVisible(pMVar2);
              if (iVar1 == 1) {
                pMVar2 = (Mission *)Status::getMission(Globals::status);
                iVar1 = Mission::isCampaignMission(pMVar2);
                if (iVar1 == 0) {
                  pMVar2 = (Mission *)Status::getMission(Globals::status);
                  iVar1 = Mission::getType(pMVar2);
                  if (iVar1 == 0xb) {
                    return;
                  }
                }
                if (*(int *)(this + 0x88) == 0) {
                  this_00 = operator_new(0x6c);
                  pMVar2 = (Mission *)Status::getMission(Globals::status);
                  DialogueWindow::DialogueWindow(this_00,pMVar2,*(Level **)(this + 0x74),0);
                  *(DialogueWindow **)(this + 0x88) = this_00;
                }
                PlayerEgo::setTurretMode(*(PlayerEgo **)(this + 0x58),false);
                LevelScript::resetCamera(*(LevelScript **)(this + 0x78),*(Level **)(this + 0x74));
                PlayerEgo::setFreeLookMode(*(PlayerEgo **)(this + 0x58),false);
                TargetFollowCamera::enableFirstPersonCam
                          (*(TargetFollowCamera **)(this + 0xf0),false);
                PlayerEgo::hideShipForFirstPersonCameraView(*(PlayerEgo **)(this + 0x58),false);
                this[0x109] = (MGame)0x1;
                iVar1 = *(int *)(this + 0x78);
                *(undefined4 *)(iVar1 + 8) = 0;
                *(undefined4 *)(iVar1 + 0xc) = 0;
                this[0x5d] = (MGame)0x1;
                pauseSounds(this);
                this[0x5e] = (MGame)0x1;
              }
            }
          }
        }
      }
    }
  }
  return;
}

// ===== MGame::successCheck  @0x001b0620  (1538 bytes)
/* MGame::successCheck() */

void MGame::successCheck(void)

{
  Status *pSVar1;
  MGame *in_r0;
  Mission *pMVar2;
  int iVar3;
  Mission *pMVar4;
  DialogueWindow *pDVar5;
  Agent *pAVar6;
  String *pSVar7;
  undefined4 uVar8;
  void *pvVar9;
  uint *puVar10;
  StarSystem *this;
  Route *this_00;
  Route *pRVar11;
  Station *this_01;
  Level *pLVar12;
  uint in_r3;
  uint extraout_r3;
  KIPlayer *pKVar13;
  uint uVar14;
  uint uVar15;
  float fVar16;
  float local_58;
  float local_54;
  float local_50;
  String aSStack_4c [8];
  String aSStack_44 [8];
  String aSStack_3c [8];
  String aSStack_34 [8];
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  local_20 = __stack_chk_guard;
  if ((*(int *)(in_r0 + 0x4c) < (int)(uint)(*(uint *)(in_r0 + 0x48) < 0x1389)) ||
     (in_r0[0xd8] != (MGame)0x0)) {
    pMVar2 = (Mission *)Status::getCampaignMission(Globals::status);
    iVar3 = Mission::getType(pMVar2);
    in_r3 = extraout_r3;
    if (iVar3 != 0xaa) goto LAB_001b09a6;
  }
  pMVar2 = (Mission *)
           Status::missionCompleted(SUB41(Globals::status,0),false,(ulonglong)in_r3 << 0x20);
  iVar3 = Level::checkObjective(*(Level **)(in_r0 + 0x74),*(int *)(*(int *)(in_r0 + 0x78) + 8));
  if ((pMVar2 == (Mission *)0x0) && (iVar3 != 1)) goto LAB_001b09a6;
  pMVar4 = (Mission *)Status::getMission(Globals::status);
  iVar3 = Mission::getType(pMVar4);
  if (iVar3 != 5) {
    pMVar4 = (Mission *)Status::getMission(Globals::status);
    iVar3 = Mission::getType(pMVar4);
    if (iVar3 != 3) {
      pMVar4 = (Mission *)Status::getMission(Globals::status);
      iVar3 = Mission::isCampaignMission(pMVar4);
      if (iVar3 == 0) {
        Status::incMissionCount(Globals::status);
      }
      pMVar4 = (Mission *)Status::getMission(Globals::status);
      iVar3 = Mission::isCampaignMission(pMVar4);
      if (iVar3 == 1) {
        pMVar4 = (Mission *)Status::getMission(Globals::status);
        iVar3 = Mission::isCampaignMission(pMVar4);
        if (iVar3 == 1) {
          iVar3 = Status::getCurrentCampaignMission(Globals::status);
          iVar3 = DialogueWindow::hasSuccessDialogue(iVar3);
          if (iVar3 == 1) goto LAB_001b092c;
        }
        iVar3 = Status::getCurrentCampaignMission(Globals::status);
        if (0x2d < iVar3) {
          pMVar2 = (Mission *)Status::getMission(Globals::status);
          iVar3 = Mission::isCampaignMission(pMVar2);
          if (iVar3 == 1) {
            iVar3 = Status::getCurrentCampaignMission(Globals::status);
            iVar3 = DialogueWindow::hasSuccessDialogue(iVar3);
            if (iVar3 == 0) {
              Status::nextCampaignMission(SUB41(Globals::status,0));
              Level::removeObjectives(*(Level **)(in_r0 + 0x74));
              Status::setMission(Globals::status,Mission::empty);
            }
          }
        }
        goto LAB_001b09a6;
      }
LAB_001b092c:
      if (*(DialogueWindow **)(in_r0 + 0x88) == (DialogueWindow *)0x0) {
        pDVar5 = operator_new(0x6c);
        DialogueWindow::DialogueWindow(pDVar5);
        *(DialogueWindow **)(in_r0 + 0x88) = pDVar5;
        pLVar12 = *(Level **)(in_r0 + 0x74);
        if (pLVar12 != (Level *)0x0) goto LAB_001b09d8;
      }
      else {
        iVar3 = DialogueWindow::hasLevel(*(DialogueWindow **)(in_r0 + 0x88));
        if ((iVar3 == 0) && (pLVar12 = *(Level **)(in_r0 + 0x74), pLVar12 != (Level *)0x0)) {
          pDVar5 = *(DialogueWindow **)(in_r0 + 0x88);
LAB_001b09d8:
          DialogueWindow::setLevel(pDVar5,pLVar12);
        }
      }
      pDVar5 = *(DialogueWindow **)(in_r0 + 0x88);
      if (pMVar2 == (Mission *)0x0) {
        pMVar2 = (Mission *)Status::getMission(Globals::status);
      }
      DialogueWindow::set(pDVar5,pMVar2,1,-1);
      *(undefined2 *)(in_r0 + 0x5d) = 0x101;
      pauseSounds(in_r0);
      pMVar2 = (Mission *)Status::getMission(Globals::status);
      iVar3 = Mission::isCampaignMission(pMVar2);
      if ((iVar3 == 1) &&
         (iVar3 = Status::getCurrentCampaignMission(Globals::status), iVar3 == 0x26)) {
        puVar10 = (uint *)Level::getEnemies(*(Level **)(in_r0 + 0x74));
        if (*puVar10 != 0) {
          uVar15 = 0;
          do {
            pKVar13 = *(KIPlayer **)(puVar10[1] + uVar15 * 4);
            if ((pKVar13[0x3c] != (KIPlayer)0x0) && (iVar3 = KIPlayer::isDead(pKVar13), iVar3 == 0))
            {
              Player::setHitpoints(*(Player **)(pKVar13 + 4),9999999);
            }
            uVar15 = uVar15 + 1;
          } while (uVar15 < *puVar10);
        }
      }
      else {
        pMVar2 = (Mission *)Status::getMission(Globals::status);
        iVar3 = Mission::isCampaignMission(pMVar2);
        if ((iVar3 == 1) &&
           (iVar3 = Status::getCurrentCampaignMission(Globals::status), iVar3 == 0x38)) {
          this = (StarSystem *)Level::getStarSystem(*(Level **)(in_r0 + 0x74));
          StarSystem::getPlanets(this);
          fVar16 = (float)AEGeometry::getPosition();
          AbyssEngine::AEMath::operator*((AEMath *)&local_58,(Vector *)&local_2c,fVar16);
          local_2c = (int)local_58;
          local_28 = (int)local_54;
          local_24 = (int)local_50;
          this_00 = operator_new(0x18);
          Route::Route(this_00,&local_2c,3);
          puVar10 = (uint *)Level::getEnemies(*(Level **)(in_r0 + 0x74));
          uVar15 = *puVar10;
          if (uVar15 != 0) {
            uVar14 = 0;
            do {
              pKVar13 = *(KIPlayer **)(puVar10[1] + uVar14 * 4);
              if (*(int *)(pKVar13 + 0x24) == 1) {
                pRVar11 = (Route *)Route::clone(this_00);
                KIPlayer::setRoute(pKVar13,pRVar11);
                uVar15 = *puVar10;
              }
              uVar14 = uVar14 + 1;
            } while (uVar14 < uVar15);
          }
          pvVar9 = (void *)Route::~Route(this_00);
          operator_delete(pvVar9);
        }
        else {
          pMVar2 = (Mission *)Status::getMission(Globals::status);
          iVar3 = Mission::isCampaignMission(pMVar2);
          if ((iVar3 == 1) &&
             (iVar3 = Status::getCurrentCampaignMission(Globals::status), iVar3 == 0x3f)) {
            puVar10 = (uint *)Level::getEnemies(*(Level **)(in_r0 + 0x74));
            uVar15 = *puVar10;
            if (uVar15 != 0) {
              uVar14 = 0;
              do {
                iVar3 = *(int *)(puVar10[1] + uVar14 * 4);
                if (*(int *)(iVar3 + 0x24) == 8) {
                  Player::removeAllGuns(*(Player **)(iVar3 + 4));
                  uVar15 = *puVar10;
                }
                uVar14 = uVar14 + 1;
              } while (uVar14 < uVar15);
            }
          }
          else {
            pMVar2 = (Mission *)Status::getMission(Globals::status);
            iVar3 = Mission::isCampaignMission(pMVar2);
            if ((iVar3 == 1) &&
               (iVar3 = Status::getCurrentCampaignMission(Globals::status), iVar3 == 0x49)) {
              puVar10 = (uint *)Level::getEnemies(*(Level **)(in_r0 + 0x74));
              if (*puVar10 != 0) {
                uVar15 = 0;
                do {
                  pKVar13 = *(KIPlayer **)(puVar10[1] + uVar15 * 4);
                  if ((pKVar13[0x3c] != (KIPlayer)0x0) &&
                     (iVar3 = KIPlayer::isDead(pKVar13), iVar3 == 0)) {
                    Player::setHitpoints(*(Player **)(pKVar13 + 4),9999999);
                    PlayerFixedObject::setMoving((PlayerFixedObject *)pKVar13,true);
                  }
                  uVar15 = uVar15 + 1;
                } while (uVar15 < *puVar10);
              }
            }
            else {
              this_01 = (Station *)Status::getStation(Globals::status);
              iVar3 = Station::getIndex(this_01);
              if ((iVar3 == 0x70) &&
                 (iVar3 = Status::getCurrentCampaignMission(Globals::status), iVar3 == 0x8f)) {
                Level::initStreamOutPositionAfterCutscene = 1;
              }
            }
          }
        }
      }
      goto LAB_001b09a6;
    }
  }
  if (*(DialogueWindow **)(in_r0 + 0x88) == (DialogueWindow *)0x0) {
    pDVar5 = operator_new(0x6c);
    DialogueWindow::DialogueWindow(pDVar5);
    *(DialogueWindow **)(in_r0 + 0x88) = pDVar5;
    pLVar12 = *(Level **)(in_r0 + 0x74);
    if (pLVar12 != (Level *)0x0) goto LAB_001b06f6;
  }
  else {
    iVar3 = DialogueWindow::hasLevel(*(DialogueWindow **)(in_r0 + 0x88));
    if ((iVar3 == 0) && (pLVar12 = *(Level **)(in_r0 + 0x74), pLVar12 != (Level *)0x0)) {
      pDVar5 = *(DialogueWindow **)(in_r0 + 0x88);
LAB_001b06f6:
      DialogueWindow::setLevel(pDVar5,pLVar12);
    }
  }
  pMVar2 = (Mission *)Status::getMission(Globals::status);
  pMVar4 = (Mission *)Status::getMission(Globals::status);
  pAVar6 = (Agent *)Mission::getAgent(pMVar4);
  iVar3 = Agent::getStation(pAVar6);
  Mission::setTargetStation(pMVar2,iVar3);
  pDVar5 = *(DialogueWindow **)(in_r0 + 0x88);
  pMVar2 = (Mission *)Status::getMission(Globals::status);
  DialogueWindow::set(pDVar5,pMVar2,1,-1);
  pMVar2 = (Mission *)Status::getMission(Globals::status);
  Mission::setType(pMVar2,0xb);
  PlayerEgo::setTurretMode(*(PlayerEgo **)(in_r0 + 0x58),false);
  LevelScript::resetCamera(*(LevelScript **)(in_r0 + 0x78),*(Level **)(in_r0 + 0x74));
  PlayerEgo::setFreeLookMode(*(PlayerEgo **)(in_r0 + 0x58),false);
  TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(in_r0 + 0xf0),false);
  PlayerEgo::hideShipForFirstPersonCameraView(*(PlayerEgo **)(in_r0 + 0x58),false);
  in_r0[0x109] = (MGame)0x1;
  pMVar2 = (Mission *)Status::getMission(Globals::status);
  Mission::setStatusValue(pMVar2,-1);
  pMVar2 = (Mission *)Status::getMission(Globals::status);
  Mission::setWon(pMVar2,false);
  pSVar7 = (String *)GameText::getText(Globals::gameText,0x323);
  AbyssEngine::String::String((String *)&local_58,pSVar7,false);
  pSVar1 = Globals::status;
  AbyssEngine::String::String(aSStack_34,(String *)&local_58,false);
  Status::getMission(Globals::status);
  Mission::getTargetStationName();
  uVar8 = AbyssEngine::String::String(aSStack_44,"#S",false);
  Status::replaceHash(&local_2c,pSVar1,aSStack_34,aSStack_3c,uVar8);
  AbyssEngine::String::operator=((String *)&local_58,(String *)&local_2c);
  AbyssEngine::String::~String((String *)&local_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String(aSStack_3c);
  AbyssEngine::String::~String(aSStack_34);
  pMVar2 = (Mission *)Status::getMission(Globals::status);
  pAVar6 = (Agent *)Mission::getAgent(pMVar2);
  AbyssEngine::String::String(aSStack_4c,(String *)&local_58,false);
  Agent::setMissionString(pAVar6,aSStack_4c);
  AbyssEngine::String::~String(aSStack_4c);
  Status::setMission(Globals::status,Mission::empty);
  PlayerEgo::setRoute(*(PlayerEgo **)(in_r0 + 0x58),(Route *)0x0);
  iVar3 = PlayerEgo::goingToWaypoint(*(PlayerEgo **)(in_r0 + 0x58));
  if (iVar3 == 1) {
    PlayerEgo::setAutoPilot(*(PlayerEgo **)(in_r0 + 0x58),(KIPlayer *)0x0);
  }
  PlayerEgo::removeRoute(*(PlayerEgo **)(in_r0 + 0x58));
  Level::setPlayerRoute(*(Level **)(in_r0 + 0x74),(Route *)0x0);
  iVar3 = *(int *)(in_r0 + 0x74);
  if (*(Objective **)(iVar3 + 0x28) != (Objective *)0x0) {
    pvVar9 = (void *)Objective::~Objective(*(Objective **)(iVar3 + 0x28));
    operator_delete(pvVar9);
    iVar3 = *(int *)(in_r0 + 0x74);
  }
  *(undefined4 *)(iVar3 + 0x28) = 0;
  if (*(Objective **)(iVar3 + 0x2c) != (Objective *)0x0) {
    pvVar9 = (void *)Objective::~Objective(*(Objective **)(iVar3 + 0x2c));
    operator_delete(pvVar9);
    iVar3 = *(int *)(in_r0 + 0x74);
  }
  *(undefined4 *)(iVar3 + 0x2c) = 0;
  *(undefined2 *)(in_r0 + 0x5d) = 0x101;
  pauseSounds(in_r0);
  AbyssEngine::String::~String((String *)&local_58);
LAB_001b09a6:
  if (__stack_chk_guard - local_20 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_20);
}

// ===== MGame::gameOverCheck  @0x001b0d04  (618 bytes)
/* MGame::gameOverCheck() */

void __thiscall MGame::gameOverCheck(MGame *this)

{
  MGame *pMVar1;
  int iVar2;
  String *pSVar3;
  Mission *pMVar4;
  undefined4 uVar5;
  DialogueWindow *pDVar6;
  uint uVar7;
  Level *pLVar8;
  uint *puVar9;
  uint uVar10;
  float extraout_s0;
  float fVar11;
  float extraout_s0_00;
  float extraout_s0_01;
  
  iVar2 = PlayerEgo::getHitpoints();
  if (iVar2 < 1) {
    iVar2 = PlayerEgo::tryToStartEmergencySystem(*(PlayerEgo **)(this + 0x58));
    if (iVar2 != 0) {
      return;
    }
    iVar2 = PlayerEgo::isInWormhole(*(PlayerEgo **)(this + 0x58));
    if (iVar2 == 1) {
      this[0x60] = (MGame)0x1;
      pSVar3 = (String *)GameText::getText(Globals::gameText,0x13f);
      AbyssEngine::String::operator=((String *)(this + 100),pSVar3);
      this[0x109] = (MGame)0x1;
    }
    else {
      PlayerEgo::setTurretMode(*(PlayerEgo **)(this + 0x58),false);
      LevelScript::resetCamera(*(LevelScript **)(this + 0x78),*(Level **)(this + 0x74));
      PlayerEgo::setFreeLookMode(*(PlayerEgo **)(this + 0x58),false);
      TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0xf0),false);
      PlayerEgo::hideShipForFirstPersonCameraView(*(PlayerEgo **)(this + 0x58),false);
      this[0x109] = (MGame)0x1;
      PlayerEgo::explode(*(PlayerEgo **)(this + 0x58));
      iVar2 = PlayerEgo::explosionEnded(*(PlayerEgo **)(this + 0x58));
      if (iVar2 == 1) {
        this[0x60] = (MGame)0x1;
        pSVar3 = (String *)GameText::getText(Globals::gameText,0x13f);
        AbyssEngine::String::operator=((String *)(this + 100),pSVar3);
      }
    }
    if (this[0x60] != (MGame)0x0) {
      iVar2 = Status::getMission(Globals::status);
      if (iVar2 != 0) {
        pMVar4 = (Mission *)Status::getMission(Globals::status);
        iVar2 = Mission::isCampaignMission(pMVar4);
        if (iVar2 == 1) {
          iVar2 = Status::getCurrentCampaignMission(Globals::status);
          if (iVar2 == Globals::lastCampaignMissionFailed) {
            Globals::lastCampaignMissionFailCount = Globals::lastCampaignMissionFailCount + 1;
            Globals::lastCampaignMissionFailed = iVar2;
          }
          else {
            Globals::lastCampaignMissionFailCount = 1;
            Globals::lastCampaignMissionFailed = iVar2;
          }
        }
      }
      uVar5 = RecordHandler::recordStoreRead(Globals::recordHandler,Globals::lastRecordWritten);
      *(undefined4 *)(this + 0x1e0) = uVar5;
    }
  }
  iVar2 = Level::checkGameOver(*(Level **)(this + 0x74),*(int *)(*(int *)(this + 0x78) + 8));
  fVar11 = extraout_s0;
  if (iVar2 == 1) {
    if (*(DialogueWindow **)(this + 0x88) == (DialogueWindow *)0x0) {
      pDVar6 = operator_new(0x6c);
      DialogueWindow::DialogueWindow(pDVar6);
      *(DialogueWindow **)(this + 0x88) = pDVar6;
      pLVar8 = *(Level **)(this + 0x74);
      if (pLVar8 != (Level *)0x0) goto LAB_001b0e6e;
    }
    else {
      iVar2 = DialogueWindow::hasLevel(*(DialogueWindow **)(this + 0x88));
      if ((iVar2 == 0) && (pLVar8 = *(Level **)(this + 0x74), pLVar8 != (Level *)0x0)) {
        pDVar6 = *(DialogueWindow **)(this + 0x88);
LAB_001b0e6e:
        DialogueWindow::setLevel(pDVar6,pLVar8);
      }
    }
    pDVar6 = *(DialogueWindow **)(this + 0x88);
    pMVar4 = (Mission *)Status::getMission(Globals::status);
    DialogueWindow::set(pDVar6,pMVar4,2,-1);
    this[0x5e] = (MGame)0x1;
    fVar11 = (float)pauseSounds(this);
    this[0x5d] = (MGame)0x1;
  }
  pMVar1 = this + 0x48;
  if (*(int *)(this + 0x4c) < (int)(uint)(*(uint *)pMVar1 < 0x1389)) goto LAB_001b0f48;
  *(undefined4 *)pMVar1 = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  puVar9 = *(uint **)(this + 0x78);
  uVar7 = *puVar9;
  if ((int)uVar7 < 1) goto LAB_001b0f48;
  uVar10 = puVar9[3];
  iVar2 = (int)uVar7 >> 0x1f;
  if (((int)((iVar2 - uVar10) - (uint)(uVar7 < puVar9[2])) < 0 ==
       (SBORROW4(iVar2,uVar10) != SBORROW4(iVar2 - uVar10,(uint)(uVar7 < puVar9[2])))) ||
     ((iVar2 = Status::getCurrentCampaignMission(Globals::status), iVar2 != 0x2a &&
      ((fVar11 = extraout_s0_00, *(Objective **)(*(int *)(this + 0x74) + 0x28) == (Objective *)0x0
       || (iVar2 = Objective::isSurvivalObjective(*(Objective **)(*(int *)(this + 0x74) + 0x28)),
          fVar11 = extraout_s0_01, iVar2 != 0)))))) goto LAB_001b0f48;
  if (*(DialogueWindow **)(this + 0x88) == (DialogueWindow *)0x0) {
    pDVar6 = operator_new(0x6c);
    DialogueWindow::DialogueWindow(pDVar6);
    *(DialogueWindow **)(this + 0x88) = pDVar6;
    pLVar8 = *(Level **)(this + 0x74);
    if (pLVar8 != (Level *)0x0) goto LAB_001b0f18;
  }
  else {
    iVar2 = DialogueWindow::hasLevel(*(DialogueWindow **)(this + 0x88));
    if ((iVar2 == 0) && (pLVar8 = *(Level **)(this + 0x74), pLVar8 != (Level *)0x0)) {
      pDVar6 = *(DialogueWindow **)(this + 0x88);
LAB_001b0f18:
      DialogueWindow::setLevel(pDVar6,pLVar8);
    }
  }
  pDVar6 = *(DialogueWindow **)(this + 0x88);
  pMVar4 = (Mission *)Status::getMission(Globals::status);
  DialogueWindow::set(pDVar6,pMVar4,2,-1);
  *(undefined2 *)(this + 0x5d) = 0x101;
  fVar11 = (float)pauseSounds(this);
LAB_001b0f48:
  if (this[0x60] != (MGame)0x0) {
    *(undefined4 *)pMVar1 = 0;
    *(undefined4 *)(this + 0x4c) = 0;
    *(undefined4 *)(this + 0x50) = 0;
    FModSound::play(Globals::sound,0x25,(Vector *)0x0,(Vector *)0x0,fVar11);
  }
  return;
}

// ===== MGame::OnResume  @0x001b0fc0  (52 bytes)
/* MGame::OnResume() */

void MGame::OnResume(void)

{
  int iVar1;
  float extraout_s0;
  
  if ((Globals::sound != 0) && (iVar1 = FModSound::tryToStopMusicForBGMusic(), iVar1 == 0)) {
    FModSound::setVolume((FModSound *)Globals::sound,1,extraout_s0);
    return;
  }
  return;
}

// ===== MGame::OnSuspend  @0x001b1000  (168 bytes)
/* MGame::OnSuspend() */

void __thiscall MGame::OnSuspend(MGame *this)

{
  undefined1 uVar1;
  MenuTouchWindow *pMVar2;
  uint *puVar3;
  uint uVar4;
  
  if (Globals::recordHandler != (RecordHandler *)0x0) {
    RecordHandler::saveOptions(Globals::recordHandler);
  }
  pauseSounds(this);
  if (this[0x5d] == (MGame)0x0) {
    if (*(int *)(this + 0x84) == 0) {
      pMVar2 = operator_new(0x240);
      MenuTouchWindow::MenuTouchWindow(pMVar2,1);
      *(MenuTouchWindow **)(this + 0x84) = pMVar2;
    }
    this[0x5d] = (MGame)0x1;
    this[0x19e] = (MGame)0x1;
    FModSound::pauseAllPlaying(Globals::sound);
    PlayerEgo::PauseEngineSound(*(PlayerEgo **)(this + 0x58));
    puVar3 = (uint *)Level::getEnemies(*(Level **)(this + 0x74));
    if ((puVar3 != (uint *)0x0) && (*puVar3 != 0)) {
      uVar4 = 0;
      do {
        KIPlayer::PauseEngineSound(*(KIPlayer **)(puVar3[1] + uVar4 * 4));
        uVar4 = uVar4 + 1;
      } while (uVar4 < *puVar3);
    }
    pMVar2 = *(MenuTouchWindow **)(this + 0x84);
    uVar1 = true;
    if (this[0x5f] == (MGame)0x0) {
      uVar1 = PlayerEgo::isDead(*(PlayerEgo **)(this + 0x58));
    }
    MenuTouchWindow::setCutsceneMode(pMVar2,(bool)uVar1);
    this[0xc5] = (MGame)0x1;
  }
  Hud::releaseAllKeys(*(Hud **)(this + 0x70));
  return;
}

// ===== MGame::OnRender2D  @0x001b10bc  (1282 bytes)
/* MGame::OnRender2D() */

void __thiscall MGame::OnRender2D(MGame *this)

{
  MGame MVar1;
  PaintCanvas *pPVar2;
  Globals *this_00;
  uint uVar3;
  StarSystem *pSVar4;
  int iVar5;
  Mission *this_01;
  float fVar6;
  String *pSVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  undefined4 uVar11;
  int iVar12;
  Array *pAVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  bool bVar17;
  uint in_fpscr;
  int local_48;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  int local_34;
  
  local_34 = __stack_chk_guard;
  if (this[0x54] != (MGame)0x0) {
    AbyssEngine::PaintCanvas::Begin2d(Globals::Canvas);
    if ((this[0x5d] == (MGame)0x0) || (this[0xc5] == (MGame)0x0)) {
      if (this[0x109] == (MGame)0x0) {
        pSVar4 = (StarSystem *)Level::getStarSystem(*(Level **)(this + 0x74));
        StarSystem::render2D(pSVar4);
        iVar5 = LevelScript::startSequenceOver(*(LevelScript **)(this + 0x78));
        if ((iVar5 != 0) ||
           (iVar5 = LevelScript::startSequence(*(LevelScript **)(this + 0x78)), iVar5 == 0)) {
          Radio::draw(CONCAT44(*(undefined4 *)(this + 0x58),*(undefined4 *)(this + 0x80)),
                      *(PlayerEgo **)(*(int *)(this + 0x78) + 8),
                      *(LevelScript **)(*(int *)(this + 0x78) + 0xc));
        }
      }
      else {
        if (this[0xc3] == (MGame)0x0) {
          Level::render2D();
          if (Globals::mouseCursorActivated == 0) {
            Hud::drawPauseButton(*(Hud **)(this + 0x70));
          }
          this_01 = (Mission *)Status::getCampaignMission(Globals::status);
          iVar5 = Mission::getType(this_01);
          if (iVar5 == 0xaa) {
            iVar5 = LevelScript::getEvent(*(LevelScript **)(this + 0x78));
            if (iVar5 == 0) {
              Hud::drawOrbitInformation(*(Hud **)(this + 0x70));
            }
LAB_001b127a:
            Radio::draw(CONCAT44(*(undefined4 *)(this + 0x58),*(undefined4 *)(this + 0x80)),
                        *(PlayerEgo **)(*(int *)(this + 0x78) + 8),
                        *(LevelScript **)(*(int *)(this + 0x78) + 0xc));
LAB_001b128e:
            if (this[0x5e] != (MGame)0x0) {
              DialogueWindow::draw(*(DialogueWindow **)(this + 0x88));
            }
            this[0x5c] = (MGame)0x0;
            this[0x108] = (MGame)0x0;
          }
          else {
            if ((this[0x5f] != (MGame)0x0) || (this[0xd8] != (MGame)0x0)) {
              iVar5 = Status::getCurrentCampaignMission(Globals::status);
              if (((7 < iVar5) &&
                  (((*(char *)(*(int *)(this + 0x78) + 0x10) == '\0' && (this[0xd8] == (MGame)0x0))
                   && (iVar5 = PlayerEgo::isDockingToPlanet(*(PlayerEgo **)(this + 0x58)),
                      iVar5 == 0)))) &&
                 (iVar5 = LevelScript::getEvent(*(LevelScript **)(this + 0x78)), iVar5 == 0)) {
                Hud::drawOrbitInformation(*(Hud **)(this + 0x70));
              }
              iVar5 = LevelScript::startSequenceOver(*(LevelScript **)(this + 0x78));
              if ((iVar5 != 0) ||
                 (iVar5 = LevelScript::startSequence(*(LevelScript **)(this + 0x78)), iVar5 == 0))
              goto LAB_001b127a;
              goto LAB_001b128e;
            }
            if (this[0x60] == (MGame)0x0) {
              PlayerEgo::draw(*(PlayerEgo **)(this + 0x58),true);
              iVar5 = PlayerEgo::isMining(*(PlayerEgo **)(this + 0x58));
              if ((iVar5 == 0) && (this[0xc3] == (MGame)0x0)) {
                uVar3 = PlayerEgo::isHacking(*(PlayerEgo **)(this + 0x58));
                bVar17 = uVar3 == 1;
                if (bVar17) {
                  uVar3 = (uint)(byte)this[0xd1];
                }
                if (!bVar17 || uVar3 != 0) {
                  if (this[0x5d] == (MGame)0x0) {
                    iVar5 = *(int *)(this + 0x40);
                  }
                  else {
                    iVar5 = 0;
                  }
                  Radar::draw(*(Radar **)(this + 0x7c),(Player *)**(undefined4 **)(this + 0x58),
                              *(Hud **)(this + 0x70),iVar5);
                }
              }
              if (this[0x5e] == (MGame)0x0) {
                uVar11 = *(undefined4 *)(this + 0x70);
                if (this[0x5d] == (MGame)0x0) {
                  local_48 = *(int *)(this + 0x40);
                  iVar5 = local_48 >> 0x1f;
                }
                else {
                  local_48 = 0;
                  iVar5 = 0;
                }
                puVar10 = *(uint **)(this + 0x78);
                uVar15 = puVar10[2];
                uVar16 = puVar10[3];
                uVar14 = *puVar10;
                uVar3 = *(uint *)(this + 0x58);
                MVar1 = this[0x5c];
                nextCamId(this,*(int *)(this + 0x14));
                iVar12 = (((int)uVar14 >> 0x1f) - uVar16) - (uint)(uVar14 < uVar15);
                Hud::draw(CONCAT44(iVar12,uVar11),CONCAT44(iVar5,local_48),
                          (PlayerEgo *)(uVar14 - uVar15),SUB41(iVar12,0),uVar3,(uint)(byte)MVar1);
                Radio::draw(CONCAT44(*(undefined4 *)(this + 0x58),*(undefined4 *)(this + 0x80)),
                            *(PlayerEgo **)(*(int *)(this + 0x78) + 8),
                            *(LevelScript **)(*(int *)(this + 0x78) + 0xc));
                Radar::drawCurrentLock(*(Hud **)(this + 0x7c));
                Layout::drawMissionRewardMessage(Globals::layout,false);
              }
              else {
                DialogueWindow::draw(*(DialogueWindow **)(this + 0x88));
              }
              if ((((this[0xc1] != (MGame)0x0) || (this[0xc2] != (MGame)0x0)) ||
                  (this[0xca] != (MGame)0x0)) || (this[0xc0] != (MGame)0x0)) {
                ChoiceWindow::draw(*(ChoiceWindow **)(this + 0x90));
              }
              if (this[0xd2] != (MGame)0x0) {
                Hud::drawMenu(*(int *)(this + 0x70));
              }
            }
            else if ((int)(uint)(*(uint *)(this + 0x48) < 0xbb9) <= *(int *)(this + 0x4c)) {
              if (*(int *)(this + 0x50) < 4000) {
                VectorSignedToFloat(*(int *)(this + 0x50),(byte)(in_fpscr >> 0x16) & 3);
              }
              AbyssEngine::PaintCanvas::SetColor(*(uint *)(this + 4));
              AbyssEngine::PaintCanvas::DrawImage2D
                        (Globals::Canvas,*(uint *)(this + 0x10),0,0,'D','D');
              pPVar2 = Globals::Canvas;
              if (3999 < *(int *)(this + 0x50)) {
                AbyssEngine::ApplicationManager::GetSystemTimeMillis(Globals::appManager);
                fVar6 = (float)__aeabi_l2f();
                AbyssEngine::AEMath::Sinf(fVar6 * 0.003);
                AbyssEngine::ApplicationManager::GetSystemTimeMillis(Globals::appManager);
                fVar6 = (float)__aeabi_l2f();
                AbyssEngine::AEMath::Sinf(fVar6 * 0.003);
                AbyssEngine::PaintCanvas::SetColor((uchar)pPVar2,0xff,0xff,0xff);
                pSVar7 = (String *)GameText::getText(Globals::gameText,199);
                AbyssEngine::String::String((String *)&local_40,pSVar7,false);
                iVar12 = Globals::h;
                this_00 = Globals::globals;
                uVar3 = Globals::font;
                pPVar2 = Globals::Canvas;
                iVar5 = Globals::w >> 1;
                if (*(int *)(this + 0x1e0) == 0) {
                  iVar8 = AbyssEngine::PaintCanvas::GetTextWidth
                                    (Globals::Canvas,Globals::font,(String *)&local_40);
                  iVar12 = Globals::h;
                  iVar9 = AbyssEngine::PaintCanvas::GetImage2DHeight
                                    (Globals::Canvas,*(uint *)(this + 0x10));
                  AbyssEngine::PaintCanvas::DrawString
                            (pPVar2,uVar3,(String *)&local_40,iVar5 - (iVar8 >> 1),
                             (iVar12 >> 1) + (iVar9 >> 1) + 10,false);
                }
                else {
                  pAVar13 = *(Array **)(this + 0x1e4);
                  iVar8 = AbyssEngine::PaintCanvas::GetImage2DHeight
                                    (Globals::Canvas,*(uint *)(this + 0x10));
                  Globals::drawLines(this_00,uVar3,pAVar13,iVar5,(iVar12 >> 1) + (iVar8 >> 1) + 10,
                                     true);
                }
                AbyssEngine::String::~String((String *)&local_40);
              }
            }
          }
          Layout::drawFade(Globals::layout);
          goto LAB_001b12b6;
        }
        StarMap::draw(*(StarMap **)(this + 0x8c));
        if (*Globals::layout != (Layout)0x0) {
          Layout::drawHelpWindow();
        }
      }
      if (__stack_chk_guard == local_34) {
        AbyssEngine::PaintCanvas::End2d(Globals::Canvas);
        return;
      }
      goto LAB_001b12d8;
    }
    if (((this[0x156] == (MGame)0x0) || ((*(uint *)(this + 0x154) & 0xff) == 0)) ||
       (*(char *)(*(int *)(this + 0x84) + 1) != '\0')) {
      MenuTouchWindow::draw(*(MenuTouchWindow **)(this + 0x84));
      uVar3 = (uint)(byte)this[0x156];
    }
    else {
      uVar3 = *(uint *)(this + 0x154) >> 0x10;
    }
    if ((uVar3 & 0xff) != 0) {
      pSVar4 = (StarSystem *)Level::getStarSystem(*(Level **)(this + 0x74));
      StarSystem::render2D(pSVar4);
    }
    iVar5 = AbyssEngine::ApplicationManager::GetEngine(*(ApplicationManager **)(this + 8));
    local_40 = 0x3f000000;
    uStack_3c = 0x3f000000;
    local_38 = 0;
    AbyssEngine::AEMath::Vector::operator=((Vector *)(iVar5 + 0x3bc),(Vector *)&local_40);
LAB_001b12b6:
    AbyssEngine::PaintCanvas::End2d(Globals::Canvas);
  }
  if (__stack_chk_guard == local_34) {
    return;
  }
LAB_001b12d8:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== MGame::OnRender3D  @0x001b164c  (296 bytes)
/* MGame::OnRender3D() */

void __thiscall MGame::OnRender3D(MGame *this)

{
  Level *this_00;
  bool bVar1;
  int iVar2;
  
  if (this[0x54] == (MGame)0x0) {
    return;
  }
  AbyssEngine::PaintCanvas::ClearBuffer((uint)Globals::Canvas);
  if (this[0x5d] == (MGame)0x0) {
    this_00 = *(Level **)(this + 0x74);
    if (this[0x156] != (MGame)0x0) goto LAB_001b1686;
    iVar2 = *(int *)(this + 0x40);
  }
  else {
    if (this[0x156] == (MGame)0x0) {
      if (this[0xc5] == (MGame)0x0) {
        if (this[0xc3] == (MGame)0x0) {
          bVar1 = false;
          Level::renderBG(*(Level **)(this + 0x74),0);
          AbyssEngine::PaintCanvas::Begin3d(Globals::Canvas);
          Level::render(*(Level **)(this + 0x74),0);
          if ((this[0x5f] == (MGame)0x0) && (this[0xd8] == (MGame)0x0)) {
            bVar1 = true;
          }
          PlayerEgo::render(*(PlayerEgo **)(this + 0x58),bVar1);
          if (*(AEGeometry **)(this + 0x10c) != (AEGeometry *)0x0) {
            AEGeometry::render(*(AEGeometry **)(this + 0x10c));
          }
          LevelScript::render3D(*(LevelScript **)(this + 0x78));
        }
        else {
          AbyssEngine::PaintCanvas::Begin3d(Globals::Canvas);
          StarMap::render(*(StarMap **)(this + 0x8c));
        }
      }
      else {
        AbyssEngine::PaintCanvas::Begin3d(Globals::Canvas);
        MenuTouchWindow::render3D(*(MenuTouchWindow **)(this + 0x84));
      }
      goto LAB_001d8a78;
    }
    this_00 = *(Level **)(this + 0x74);
LAB_001b1686:
    iVar2 = 0;
  }
  Level::renderBG(this_00,iVar2);
  AbyssEngine::PaintCanvas::Begin3d(Globals::Canvas);
  if (this[0x156] == (MGame)0x0) {
    iVar2 = *(int *)(this + 0x40);
  }
  else {
    iVar2 = 0;
  }
  Level::render(*(Level **)(this + 0x74),iVar2);
  bVar1 = false;
  if ((this[0x5f] == (MGame)0x0) && (this[0xd8] == (MGame)0x0)) {
    bVar1 = true;
  }
  PlayerEgo::render(*(PlayerEgo **)(this + 0x58),bVar1);
  if (*(AEGeometry **)(this + 0x10c) != (AEGeometry *)0x0) {
    AEGeometry::render(*(AEGeometry **)(this + 0x10c));
  }
  LevelScript::render3D(*(LevelScript **)(this + 0x78));
LAB_001d8a78:
  AbyssEngine::PaintCanvas::End3d(Globals::Canvas);
  return;
}

// ===== MGame::pause  @0x001b1790  (2 bytes)
/* MGame::pause() */

void MGame::pause(void)

{
  return;
}

// ===== MGame::showLiteScreen  @0x001b1792  (2 bytes)
/* MGame::showLiteScreen() */

void MGame::showLiteScreen(void)

{
  return;
}

// ===== MGame::OnKeyRelease  @0x001b1794  (2 bytes)
/* MGame::OnKeyRelease(long long, long long) */

longlong MGame::OnKeyRelease(longlong param_1,longlong param_2)

{
  return param_1;
}

// ===== MGame::OnTouchBegin  @0x001b1796  (2 bytes)
/* MGame::OnTouchBegin(int, int) */

int MGame::OnTouchBegin(int param_1,int param_2)

{
  return param_1;
}

// ===== MGame::OnTouchMove  @0x001b1798  (2 bytes)
/* MGame::OnTouchMove(int, int) */

int MGame::OnTouchMove(int param_1,int param_2)

{
  return param_1;
}

// ===== MGame::OnTouchEnd  @0x001b179a  (2 bytes)
/* MGame::OnTouchEnd(int, int) */

int MGame::OnTouchEnd(int param_1,int param_2)

{
  return param_1;
}

// ===== MGame::ShowLoadingScreen  @0x001b179c  (4 bytes)
/* MGame::ShowLoadingScreen() */

undefined4 MGame::ShowLoadingScreen(void)

{
  return 1;
}

