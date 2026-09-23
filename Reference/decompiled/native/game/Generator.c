// Class: Generator
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Generator::Generator  @0x000a0534  (2 bytes)
/* Generator::Generator() */

Generator * __thiscall Generator::Generator(Generator *this)

{
  return this;
}

// ===== Generator::~Generator  @0x000a0536  (2 bytes)
/* Generator::~Generator() */

Generator * __thiscall Generator::~Generator(Generator *this)

{
  return this;
}

// ===== Generator::computerTradeGoods  @0x000a0538  (100 bytes)
/* Generator::computerTradeGoods(Station*) */

void __thiscall Generator::computerTradeGoods(Generator *this,Station *param_1)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = Station::getIndex(param_1);
  if ((iVar1 != 0x6c) && (puVar2 = (uint *)Station::getItems(param_1), puVar2 != (uint *)0x0)) {
    if (*puVar2 == 0) {
      return;
    }
    uVar4 = 0;
    do {
      iVar1 = Item::getAmount(*(Item **)(puVar2[1] + uVar4 * 4));
      iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
      if (iVar3 < iVar1) {
        Item::changeAmount(*(Item **)(puVar2[1] + uVar4 * 4),-iVar3);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar2);
  }
  return;
}

// ===== Generator::isKaamoSpecialItem  @0x000a05a0  (30 bytes)
/* Generator::isKaamoSpecialItem(int) */

void __thiscall Generator::isKaamoSpecialItem(Generator *this,int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_00251d10)[iVar1] == param_1) {
      return;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 9);
  return;
}

// ===== Generator::getItemBuyList  @0x000a05c4  (2090 bytes)
/* Generator::getItemBuyList(Station*) */

Array * __thiscall Generator::getItemBuyList(Generator *this,Station *param_1)

{
  bool bVar1;
  bool bVar2;
  Galaxy *pGVar3;
  uint *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  void *pvVar12;
  Item *pIVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  undefined4 uVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  uint in_fpscr;
  float fVar21;
  float fVar22;
  float fVar23;
  Array *local_80;
  
  iVar5 = Station::getIndex(param_1);
  if ((iVar5 == 0x4e) && (iVar5 = Status::getCurrentCampaignMission(Globals::status), iVar5 < 7)) {
    local_80 = operator_new(0xc);
    puVar6 = operator_new__(4);
    *(undefined4 **)(local_80 + 4) = puVar6;
    *(undefined4 *)(local_80 + 8) = 1;
    *puVar6 = 0;
    *(undefined4 *)local_80 = 0;
    ArraySetLength<Item*>(3,local_80);
    uVar7 = Item::makeItem(*(Item **)Globals::items[1],1,0);
    **(undefined4 **)(local_80 + 4) = uVar7;
    uVar7 = Item::makeItem(*(Item **)(Globals::items[1] + 0x58),1,0);
    *(undefined4 *)(*(int *)(local_80 + 4) + 4) = uVar7;
    uVar7 = Item::makeItem(*(Item **)(Globals::items[1] + 0xdc),1,0);
    *(undefined4 *)(*(int *)(local_80 + 4) + 8) = uVar7;
  }
  else {
    iVar5 = Station::getIndex(param_1);
    if ((iVar5 == 0x6c) || (iVar5 = Status::inSupernovaSystem(Globals::status), iVar5 != 0)) {
      local_80 = (Array *)0x0;
    }
    else {
      uVar8 = Station::getIndex(param_1);
      local_80 = operator_new(0xc);
      puVar6 = operator_new__(4);
      *(undefined4 **)(local_80 + 4) = puVar6;
      *(undefined4 *)(local_80 + 8) = 1;
      *puVar6 = 0;
      pGVar3 = Globals::galaxy;
      *(undefined4 *)local_80 = 0;
      puVar4 = Globals::items;
      iVar9 = Galaxy::getSystems(pGVar3);
      iVar10 = Station::getTecLevel(param_1);
      iVar5 = iVar10 / 2;
      if (iVar10 < 4) {
        iVar5 = 1;
      }
      if ((uVar8 | 2) == 0x6b) {
        iVar5 = 0;
      }
      iVar11 = Status::getCurrentCampaignMission(Globals::status);
      if ((iVar11 == 0x8b) && (iVar11 = Station::getSystem(param_1), iVar11 == 0x19)) {
        uVar7 = Item::makeItem(*(Item **)(puVar4[1] + 0x2f8));
        *(int *)(local_80 + 8) = *(int *)local_80 + 1;
        pvVar12 = realloc(*(void **)(local_80 + 4),(*(int *)local_80 + 1) * 4);
        *(void **)(local_80 + 4) = pvVar12;
        *(undefined4 *)((int)pvVar12 + *(int *)local_80 * 4) = uVar7;
        *(undefined4 *)local_80 = *(undefined4 *)(local_80 + 8);
      }
      if (uVar8 == 0x7e) {
        pIVar13 = (Item *)Item::makeItem(*(Item **)(puVar4[1] + 0x344));
        iVar11 = Status::getCurrentCampaignMission(Globals::status);
        if (iVar11 == 0x75) {
          iVar11 = 1;
        }
        else {
          iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,10);
          iVar11 = iVar11 + 1;
        }
        uVar7 = Item::makeItem(pIVar13,iVar11);
        *(int *)(local_80 + 8) = *(int *)local_80 + 1;
        pvVar12 = realloc(*(void **)(local_80 + 4),(*(int *)local_80 + 1) * 4);
        *(void **)(local_80 + 4) = pvVar12;
        *(undefined4 *)((int)pvVar12 + *(int *)local_80 * 4) = uVar7;
        *(undefined4 *)local_80 = *(undefined4 *)(local_80 + 8);
      }
      AbyssEngine::AERandom::reset(Globals::rnd);
      iVar11 = Status::getCurrentCampaignMission(Globals::status);
      fVar22 = 1.5;
      fVar21 = (float)VectorSignedToFloat(iVar11 + 0x19,(byte)(in_fpscr >> 0x16) & 3);
      in_fpscr = in_fpscr & 0xfffffff;
      if (fVar21 / 45.0 < 1.5) {
        iVar11 = Status::getCurrentCampaignMission(Globals::status);
        fVar22 = (float)VectorSignedToFloat(iVar11 + 0x19,(byte)(in_fpscr >> 0x16) & 3);
        fVar22 = fVar22 / 45.0;
      }
      if (*puVar4 != 0) {
        uVar20 = 0;
        do {
          pIVar13 = *(Item **)(puVar4[1] + uVar20 * 4);
          iVar11 = Item::getIndex(pIVar13);
          if (iVar11 < 0x84) {
            bVar1 = false;
          }
          else {
            iVar11 = Item::getIndex(pIVar13);
            bVar1 = iVar11 < 0x9a;
          }
          iVar11 = Station::getIndex(param_1);
          iVar14 = Item::getAttribute(pIVar13,0x3d);
          if (((iVar11 == iVar14) &&
              (((iVar11 = Item::getIndex(pIVar13), iVar11 < 0xc4 ||
                (iVar11 = Item::getIndex(pIVar13), 0xc4 < iVar11)) ||
               (iVar11 = Status::getCurrentCampaignMission(Globals::status), 0x8d < iVar11)))) &&
             (((iVar11 = Item::getIndex(pIVar13), iVar11 < 0xc6 ||
               (iVar11 = Item::getIndex(pIVar13), 200 < iVar11)) ||
              (iVar11 = Status::getCurrentCampaignMission(Globals::status), 0x8d < iVar11)))) {
            bVar2 = true;
          }
          else {
            bVar2 = false;
          }
          if (uVar8 == 0x6a) {
            iVar11 = 0;
            do {
              iVar19 = (&DAT_00251d34)[iVar11];
              iVar14 = Item::getIndex(pIVar13);
              if (iVar19 == iVar14 || bVar1) goto LAB_000a0968;
              iVar11 = iVar11 + 1;
            } while (iVar11 < 10);
          }
          else {
LAB_000a0968:
            iVar11 = Item::getOccurence(pIVar13);
            iVar14 = Item::getIndex(pIVar13);
            if ((iVar14 == 0x7a) && (Globals::energyCellsProbChange != 0)) {
              fVar21 = (float)VectorSignedToFloat(iVar11 * Globals::energyCellsProbChange,
                                                  (byte)(in_fpscr >> 0x16) & 3);
              fVar23 = (float)VectorSignedToFloat(iVar11,(byte)(in_fpscr >> 0x16) & 3);
              iVar11 = (int)(fVar23 + fVar21 * 0.01);
            }
            iVar14 = Item::getType(pIVar13);
            if ((iVar14 == 1) && (Globals::secondaryWeaponsProbChange != 0)) {
              fVar21 = (float)VectorSignedToFloat(iVar11 * Globals::secondaryWeaponsProbChange,
                                                  (byte)(in_fpscr >> 0x16) & 3);
              fVar23 = (float)VectorSignedToFloat(iVar11,(byte)(in_fpscr >> 0x16) & 3);
              iVar11 = (int)(fVar23 + fVar21 * 0.01);
            }
            uVar15 = Item::getIndex(pIVar13);
            uVar16 = Item::getSort(pIVar13);
            iVar14 = Status::getCurrentCampaignMission(Globals::status);
            if ((iVar11 == 0) &&
               (((0xc3 < (int)uVar15 && (Globals::options[0x37] != '\0')) ||
                ((iVar11 = 0, (int)uVar15 < 0xc4 && (Globals::options[0x35] != '\0')))))) {
              iVar19 = Item::getType(pIVar13);
              iVar11 = 0;
              if (uVar15 != 0x55 && iVar19 != 4) {
                iVar11 = Item::getIngredients(pIVar13);
                if (iVar11 == 0) {
                  iVar11 = 0;
                  if (((uVar15 != 0xb5) || (0x3a < iVar14)) &&
                     ((uVar16 != 0x22 && (uVar16 | 2) != 0x23 || (0x8d < iVar14)))) {
                    iVar11 = 0;
                    if ((uVar16 != 0x24) && (0x8d < iVar14 || uVar16 != 0x2b)) {
                      iVar11 = 0;
                      if ((1 < (uVar15 & 0xfffffff7) - 0xd1) && (0x5d < iVar14 || uVar15 != 0xcd)) {
                        iVar11 = 0;
                        do {
                          if ((&DAT_00251d10)[iVar11] == uVar15) goto LAB_000a0b1c;
                          iVar11 = iVar11 + 1;
                        } while (iVar11 < 9);
                        if ((uVar16 == 0x1d) &&
                           (iVar11 = Status::inBlackMarketSystem(Globals::status), iVar11 != 1))
                        goto LAB_000a0b1c;
                        uVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x1e);
                        uVar17 = Item::getTecLevel(pIVar13);
                        fVar21 = (float)VectorSignedToFloat(uVar17,(byte)(in_fpscr >> 0x16) & 3);
                        fVar23 = (float)VectorSignedToFloat(uVar7,(byte)(in_fpscr >> 0x16) & 3);
                        iVar11 = (int)(fVar23 + (fVar21 / -10.0 + 1.0) * 30.0);
                      }
                    }
                  }
                }
                else {
LAB_000a0b1c:
                  iVar11 = 0;
                }
              }
            }
            iVar14 = Item::getTecLevel(pIVar13);
            if (!bVar2) {
              iVar19 = Item::getIngredients(pIVar13);
              if (((((iVar19 != 0) || (uVar20 - 0xd9 < 2)) || (uVar20 == 0xa4 || uVar20 == 0xaf)) ||
                  ((iVar19 = Station::getTecLevel(param_1), iVar11 == 0 || (iVar19 < iVar14)))) ||
                 (iVar19 = Item::getSinglePrice(pIVar13), iVar19 == 0)) goto LAB_000a0de6;
              iVar19 = Item::getAttribute(pIVar13,0x3c);
              if (iVar19 == 1) {
                iVar19 = Station::getSystem(param_1);
                iVar19 = SolarSystem::getRace(*(SolarSystem **)(*(int *)(iVar9 + 4) + iVar19 * 4));
                if (iVar19 != 1) goto LAB_000a0de6;
              }
              if ((uVar8 != 0x6a) && (!(bool)(bVar1 ^ 1))) {
                iVar19 = Item::getIndex(pIVar13);
                iVar18 = Station::getSystem(param_1);
                if (iVar19 != iVar18 + 0x84) goto LAB_000a0de6;
              }
            }
            iVar19 = Status::hardCoreMode();
            if ((iVar19 != 1) ||
               ((iVar19 = Item::getSort(pIVar13), iVar19 != 0x17 &&
                (iVar19 = Item::getSort(pIVar13), iVar19 != 0x18)))) {
              if (uVar8 == 0x6b) {
                iVar19 = Item::getType(pIVar13);
                if (iVar19 == 3) goto LAB_000a0c18;
              }
              else if (uVar8 == 0x69) {
                iVar19 = Item::isWeapon(pIVar13);
                if ((iVar19 != 0) || (iVar19 = Item::getSort(pIVar13), iVar19 == 0x1c))
                goto LAB_000a0c18;
              }
              else if ((uVar8 != 0x65) || (iVar19 = Item::isWeapon(pIVar13), iVar19 != 0)) {
LAB_000a0c18:
                if ((uVar8 != 0x6a) || (iVar19 = Item::getType(pIVar13), iVar19 == 4)) {
                  fVar21 = (float)VectorSignedToFloat(iVar11,(byte)(in_fpscr >> 0x16) & 3);
                  if ((bVar2) ||
                     ((((iVar14 <= iVar10 || (!(bool)(bVar1 ^ 1))) &&
                       (iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,100),
                       iVar11 < (int)(fVar22 * fVar21))) &&
                      (((iVar11 = Item::getIndex(pIVar13), iVar5 <= iVar14 || (iVar11 == 0x7a)) ||
                       (iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,100), iVar11 < 0x3d))))
                     )) {
                    iVar11 = Item::getMinPriceSystem(pIVar13);
                    iVar11 = SolarSystem::getX(*(SolarSystem **)(*(int *)(iVar9 + 4) + iVar11 * 4));
                    iVar14 = Item::getMinPriceSystem(pIVar13);
                    iVar14 = SolarSystem::getY(*(SolarSystem **)(*(int *)(iVar9 + 4) + iVar14 * 4));
                    pGVar3 = Globals::galaxy;
                    iVar19 = Station::getSystem(param_1);
                    iVar19 = SolarSystem::getX(*(SolarSystem **)(*(int *)(iVar9 + 4) + iVar19 * 4));
                    iVar18 = Station::getSystem(param_1);
                    iVar18 = SolarSystem::getY(*(SolarSystem **)(*(int *)(iVar9 + 4) + iVar18 * 4));
                    iVar11 = Galaxy::invDistancePercent(pGVar3,iVar19,iVar18,iVar11,iVar14);
                    iVar14 = AbyssEngine::AERandom::nextInt(Globals::rnd,0xf);
                    iVar18 = iVar14 + 5;
                    iVar19 = Item::getType(pIVar13);
                    if ((iVar19 == 4) || (iVar19 = Item::getType(pIVar13), iVar19 == 1)) {
                      iVar14 = Item::getIndex(pIVar13);
                      if (iVar14 == 0x6d) {
                        iVar19 = iVar18 / 2;
                        if (iVar18 < 2) {
                          iVar19 = 1;
                        }
                      }
                      else {
                        iVar14 = Item::getType(pIVar13);
                        iVar19 = iVar18;
                        if (iVar14 == 4) {
                          if (0x32 < iVar11) {
                            fVar21 = (float)VectorSignedToFloat(iVar11 + -0x32,
                                                                (byte)(in_fpscr >> 0x16) & 3);
                            iVar11 = Status::hardCoreMode();
                            fVar23 = 20.0;
                            if (iVar11 != 0) {
                              fVar23 = 2.0;
                            }
                            iVar19 = (int)((fVar21 / 50.0) * fVar23);
                            if (iVar19 < 1) {
                              iVar19 = 1;
                            }
                            iVar19 = iVar19 * iVar18;
                          }
                          iVar11 = Item::getIndex(pIVar13);
                          if ((iVar11 == 0x6e) &&
                             (iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,10),
                             iVar11 + 10 < iVar19)) {
                            iVar19 = AbyssEngine::AERandom::nextInt(Globals::rnd,10);
                            iVar19 = iVar19 + 10;
                          }
                        }
                      }
                    }
                    else {
                      iVar19 = iVar18 / 5;
                      if (iVar14 < 0) {
                        iVar19 = 1;
                      }
                    }
                    uVar7 = Item::makeItem(pIVar13,iVar19);
                    *(int *)(local_80 + 8) = *(int *)local_80 + 1;
                    pvVar12 = realloc(*(void **)(local_80 + 4),(*(int *)local_80 + 1) * 4);
                    *(void **)(local_80 + 4) = pvVar12;
                    *(undefined4 *)((int)pvVar12 + *(int *)local_80 * 4) = uVar7;
                    *(undefined4 *)local_80 = *(undefined4 *)(local_80 + 8);
                  }
                }
              }
            }
          }
LAB_000a0de6:
          uVar20 = uVar20 + 1;
        } while (uVar20 < *puVar4);
      }
    }
  }
  return local_80;
}

// ===== Generator::getShipBuyList  @0x000a0eb8  (2974 bytes)
/* Generator::getShipBuyList(Station*) */

Array * __thiscall Generator::getShipBuyList(Generator *this,Station *param_1)

{
  int iVar1;
  Array *pAVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  void *pvVar6;
  int *piVar7;
  SolarSystem *this_00;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  Ship *pSVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  bool bVar20;
  
  iVar1 = Station::getSystem(param_1);
  if ((((iVar1 == 0xf) && (iVar1 = Status::getCurrentCampaignMission(Globals::status), iVar1 < 0x10)
       ) || (iVar1 = Station::getIndex(param_1), iVar1 == 0x65)) ||
     ((iVar1 = Station::getIndex(param_1), iVar1 == 0x6c ||
      (iVar1 = Status::inSupernovaSystem(Globals::status), iVar1 != 0)))) {
    return (Array *)0x0;
  }
  iVar1 = Station::getIndex(param_1);
  if ((iVar1 == 100) && (iVar1 = Status::dlc1Won(Globals::status), iVar1 == 1)) {
    pAVar2 = operator_new(0xc);
    puVar3 = operator_new__(4);
    iVar1 = 0;
    *(undefined4 **)(pAVar2 + 4) = puVar3;
    *puVar3 = 0;
    *(int *)(pAVar2 + 8) = 1;
    *(int *)pAVar2 = 0;
    do {
      pSVar15 = *(Ship **)(*(int *)(Globals::ships + 4) + iVar1 * 4);
      iVar4 = Ship::hasJumpDriveIntegrated(pSVar15);
      if (iVar4 == 1) {
        uVar5 = Ship::makeShip(pSVar15,-1);
        *(int *)(pAVar2 + 8) = *(int *)pAVar2 + 1;
        pvVar6 = realloc(*(void **)(pAVar2 + 4),(*(int *)pAVar2 + 1) * 4);
        *(void **)(pAVar2 + 4) = pvVar6;
        iVar4 = *(int *)pAVar2;
        iVar14 = *(int *)(pAVar2 + 8);
        *(int *)pAVar2 = iVar14;
        *(undefined4 *)((int)pvVar6 + iVar4 * 4) = uVar5;
        Ship::setRace(*(Ship **)((int)pvVar6 + iVar14 * 4 + -4),(&DAT_00251d5c)[iVar1]);
        Ship::adjustPrice(*(Ship **)(*(int *)(pAVar2 + 4) + *(int *)pAVar2 * 4 + -4));
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 != 0x40);
    return pAVar2;
  }
  iVar1 = Station::getIndex(param_1);
  if (iVar1 == 0x6b) {
    pAVar2 = operator_new(0xc);
    puVar3 = operator_new__(4);
    iVar1 = 0;
    *(undefined4 **)(pAVar2 + 4) = puVar3;
    *puVar3 = 0;
    *(int *)(pAVar2 + 8) = 1;
    *(int *)pAVar2 = 0;
    do {
      if ((&DAT_00251d5c)[iVar1] == 8) {
        uVar5 = Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + iVar1 * 4),-1);
        *(int *)(pAVar2 + 8) = *(int *)pAVar2 + 1;
        pvVar6 = realloc(*(void **)(pAVar2 + 4),(*(int *)pAVar2 + 1) * 4);
        *(void **)(pAVar2 + 4) = pvVar6;
        *(undefined4 *)((int)pvVar6 + *(int *)pAVar2 * 4) = uVar5;
        *(int *)pAVar2 = *(int *)(pAVar2 + 8);
        Ship::setRace(*(Ship **)((int)pvVar6 + *(int *)(pAVar2 + 8) * 4 + -4),8);
        Ship::adjustPrice(*(Ship **)(*(int *)(pAVar2 + 4) + *(int *)pAVar2 * 4 + -4));
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 != 0x32);
    if (Globals::options[0x37] == '\0') {
      return pAVar2;
    }
    piVar7 = *(int **)Globals::status;
    if (piVar7 == (int *)0x0) {
      return pAVar2;
    }
    if (*piVar7 == 0) {
      return pAVar2;
    }
    iVar1 = Wanted::isTerminated(*(Wanted **)(piVar7[1] + 0x18));
    if (iVar1 == 1) {
      uVar5 = Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0xb4),-1);
      *(int *)(pAVar2 + 8) = *(int *)pAVar2 + 1;
      pvVar6 = realloc(*(void **)(pAVar2 + 4),(*(int *)pAVar2 + 1) * 4);
      *(void **)(pAVar2 + 4) = pvVar6;
      *(undefined4 *)((int)pvVar6 + *(int *)pAVar2 * 4) = uVar5;
      *(int *)pAVar2 = *(int *)(pAVar2 + 8);
      Ship::setRace(*(Ship **)((int)pvVar6 + *(int *)(pAVar2 + 8) * 4 + -4),8);
      Ship::adjustPrice(*(Ship **)(*(int *)(pAVar2 + 4) + *(int *)pAVar2 * 4 + -4));
    }
    iVar1 = Wanted::isTerminated(*(Wanted **)(*(int *)(*(int *)Globals::status + 4) + 0x30));
    if (iVar1 == 1) {
      uVar5 = Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0xb8),-1);
      *(int *)(pAVar2 + 8) = *(int *)pAVar2 + 1;
      pvVar6 = realloc(*(void **)(pAVar2 + 4),(*(int *)pAVar2 + 1) * 4);
      *(void **)(pAVar2 + 4) = pvVar6;
      *(undefined4 *)((int)pvVar6 + *(int *)pAVar2 * 4) = uVar5;
      *(int *)pAVar2 = *(int *)(pAVar2 + 8);
      Ship::setRace(*(Ship **)((int)pvVar6 + *(int *)(pAVar2 + 8) * 4 + -4),8);
      Ship::adjustPrice(*(Ship **)(*(int *)(pAVar2 + 4) + *(int *)pAVar2 * 4 + -4));
    }
    iVar1 = Wanted::isTerminated(*(Wanted **)(*(int *)(*(int *)Globals::status + 4) + 0x48));
    if (iVar1 == 1) {
      uVar5 = Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0xbc),-1);
      *(int *)(pAVar2 + 8) = *(int *)pAVar2 + 1;
      pvVar6 = realloc(*(void **)(pAVar2 + 4),(*(int *)pAVar2 + 1) * 4);
      *(void **)(pAVar2 + 4) = pvVar6;
      *(undefined4 *)((int)pvVar6 + *(int *)pAVar2 * 4) = uVar5;
      *(int *)pAVar2 = *(int *)(pAVar2 + 8);
      Ship::setRace(*(Ship **)((int)pvVar6 + *(int *)(pAVar2 + 8) * 4 + -4),8);
      Ship::adjustPrice(*(Ship **)(*(int *)(pAVar2 + 4) + *(int *)pAVar2 * 4 + -4));
    }
    iVar1 = Wanted::isTerminated(*(Wanted **)(*(int *)(*(int *)Globals::status + 4) + 0x60));
    if (iVar1 != 1) {
      return pAVar2;
    }
    uVar5 = Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0xc0),-1);
    *(int *)(pAVar2 + 8) = *(int *)pAVar2 + 1;
    pvVar6 = realloc(*(void **)(pAVar2 + 4),(*(int *)pAVar2 + 1) * 4);
    *(void **)(pAVar2 + 4) = pvVar6;
    *(undefined4 *)((int)pvVar6 + *(int *)pAVar2 * 4) = uVar5;
    *(int *)pAVar2 = *(int *)(pAVar2 + 8);
    pvVar6 = (void *)((int)pvVar6 + *(int *)(pAVar2 + 8) * 4);
    iVar1 = 8;
    goto LAB_000a19d6;
  }
  this_00 = (SolarSystem *)Status::getSystem(Globals::status);
  iVar1 = SolarSystem::getRace(this_00);
  iVar4 = Station::getIndex(param_1);
  if (iVar4 == 10) {
    uVar8 = Achievements::gotAllGoldMedals(Globals::achievements);
  }
  else {
    uVar8 = 0;
  }
  iVar4 = Station::getIndex(param_1);
  iVar14 = Station::getIndex(param_1);
  if (uVar8 == 0) {
    uVar18 = AbyssEngine::AERandom::nextInt(Globals::rnd,6);
    if (iVar4 == 0x29) {
      uVar18 = uVar18 + 1;
    }
    if (uVar18 == 0) {
      return (Array *)0x0;
    }
  }
  else {
    uVar18 = 1;
  }
  pAVar2 = operator_new(0xc);
  puVar3 = operator_new__(4);
  uVar19 = 0;
  *(undefined4 **)(pAVar2 + 4) = puVar3;
  *(undefined4 *)(pAVar2 + 8) = 1;
  *puVar3 = 0;
  *(undefined4 *)pAVar2 = 0;
  ArraySetLength<Ship*>(uVar18,pAVar2);
  if (0 < (int)uVar18) {
    uVar9 = 10;
    if (uVar8 != 0) {
      uVar9 = 8;
    }
LAB_000a1348:
    bVar20 = uVar19 == 0;
    uVar16 = uVar8 | (bVar20 && iVar4 == 0x29);
    uVar17 = uVar16;
    if (uVar16 != 0) {
      uVar17 = uVar9;
    }
    do {
      uVar10 = uVar17;
      if (uVar16 == 0 && (iVar14 != 0x4e || !bVar20)) {
        uVar10 = Globals::getRandomEnemyFighter(Globals::globals,iVar1);
      }
      if (((uVar18 != 1) &&
          (iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,100), iVar11 < 0x16)) &&
         (iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,5), uVar10 = uVar17,
         uVar16 == 0 && (iVar14 != 0x4e || !bVar20))) {
        iVar13 = iVar11;
        if (iVar11 == iVar1) {
          iVar13 = 8;
        }
        if (iVar11 == 4) {
          iVar13 = 8;
        }
        uVar10 = Globals::getRandomEnemyFighter(Globals::globals,iVar13);
      }
      iVar11 = 0;
      while ((pSVar15 = *(Ship **)(*(int *)(pAVar2 + 4) + iVar11 * 4), pSVar15 == (Ship *)0x0 ||
             (uVar12 = Ship::getIndex(pSVar15), uVar12 != uVar10))) {
        iVar11 = iVar11 + 1;
        if ((int)uVar18 <= iVar11) {
          uVar5 = Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + uVar10 * 4),-1);
          *(undefined4 *)(*(int *)(pAVar2 + 4) + uVar19 * 4) = uVar5;
          Ship::setRace(*(Ship **)(*(int *)(pAVar2 + 4) + uVar19 * 4),(&DAT_00251d5c)[uVar10]);
          Ship::adjustPrice(*(Ship **)(*(int *)(pAVar2 + 4) + uVar19 * 4));
          uVar19 = uVar19 + 1;
          if (uVar19 == uVar18) goto LAB_000a142a;
          goto LAB_000a1348;
        }
      }
    } while( true );
  }
LAB_000a142a:
  if (iVar1 == 0) {
    iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,7);
    if (iVar1 == 0) {
      uVar5 = Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0xf8),-1);
      *(int *)(pAVar2 + 8) = *(int *)pAVar2 + 1;
      pvVar6 = realloc(*(void **)(pAVar2 + 4),(*(int *)pAVar2 + 1) * 4);
      *(void **)(pAVar2 + 4) = pvVar6;
      *(undefined4 *)((int)pvVar6 + *(int *)pAVar2 * 4) = uVar5;
      *(int *)pAVar2 = *(int *)(pAVar2 + 8);
      Ship::setRace(*(Ship **)((int)pvVar6 + *(int *)(pAVar2 + 8) * 4 + -4),3);
      Ship::adjustPrice(*(Ship **)(*(int *)(pAVar2 + 4) + *(int *)pAVar2 * 4 + -4));
    }
    bVar20 = true;
    uVar8 = 0;
  }
  else {
    if (iVar1 == 1) {
      iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,5);
      if (iVar1 != 0) {
        bVar20 = false;
        uVar8 = 1;
        goto LAB_000a155a;
      }
      uVar5 = Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0xfc),-1);
      *(int *)(pAVar2 + 8) = *(int *)pAVar2 + 1;
      pvVar6 = realloc(*(void **)(pAVar2 + 4),(*(int *)pAVar2 + 1) * 4);
      *(void **)(pAVar2 + 4) = pvVar6;
      *(undefined4 *)((int)pvVar6 + *(int *)pAVar2 * 4) = uVar5;
      uVar8 = 1;
      *(int *)pAVar2 = *(int *)(pAVar2 + 8);
      Ship::setRace(*(Ship **)((int)pvVar6 + *(int *)(pAVar2 + 8) * 4 + -4),1);
      Ship::adjustPrice(*(Ship **)(*(int *)(pAVar2 + 4) + *(int *)pAVar2 * 4 + -4));
    }
    else {
      if ((iVar1 == 2) && (iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,8), iVar1 == 0)) {
        uVar5 = Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0xf4),-1);
        *(int *)(pAVar2 + 8) = *(int *)pAVar2 + 1;
        pvVar6 = realloc(*(void **)(pAVar2 + 4),(*(int *)pAVar2 + 1) * 4);
        *(void **)(pAVar2 + 4) = pvVar6;
        *(undefined4 *)((int)pvVar6 + *(int *)pAVar2 * 4) = uVar5;
        *(int *)pAVar2 = *(int *)(pAVar2 + 8);
        Ship::setRace(*(Ship **)((int)pvVar6 + *(int *)(pAVar2 + 8) * 4 + -4),1);
        Ship::adjustPrice(*(Ship **)(*(int *)(pAVar2 + 4) + *(int *)pAVar2 * 4 + -4));
      }
      uVar8 = 0;
    }
    bVar20 = false;
  }
LAB_000a155a:
  if ((Globals::options[0x35] != '\0') &&
     (uVar18 = Status::dlc1Won(Globals::status), (uVar18 & uVar8) == 1)) {
    iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
    if (iVar1 == 0) {
      uVar5 = Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0x9c),-1);
      *(int *)(pAVar2 + 8) = *(int *)pAVar2 + 1;
      pvVar6 = realloc(*(void **)(pAVar2 + 4),(*(int *)pAVar2 + 1) * 4);
      *(void **)(pAVar2 + 4) = pvVar6;
      *(undefined4 *)((int)pvVar6 + *(int *)pAVar2 * 4) = uVar5;
      *(int *)pAVar2 = *(int *)(pAVar2 + 8);
      Ship::setRace(*(Ship **)((int)pvVar6 + *(int *)(pAVar2 + 8) * 4 + -4),1);
      Ship::adjustPrice(*(Ship **)(*(int *)(pAVar2 + 4) + *(int *)pAVar2 * 4 + -4));
    }
    iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
    if (iVar1 == 0) {
      uVar5 = Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0xa4),-1);
      *(int *)(pAVar2 + 8) = *(int *)pAVar2 + 1;
      pvVar6 = realloc(*(void **)(pAVar2 + 4),(*(int *)pAVar2 + 1) * 4);
      *(void **)(pAVar2 + 4) = pvVar6;
      *(undefined4 *)((int)pvVar6 + *(int *)pAVar2 * 4) = uVar5;
      *(int *)pAVar2 = *(int *)(pAVar2 + 8);
      Ship::setRace(*(Ship **)((int)pvVar6 + *(int *)(pAVar2 + 8) * 4 + -4),1);
      Ship::adjustPrice(*(Ship **)(*(int *)(pAVar2 + 4) + *(int *)pAVar2 * 4 + -4));
    }
  }
  if (Globals::options[0x37] != '\0') {
    if ((uVar8 == 1) && (iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,4), iVar1 == 0)) {
      uVar5 = Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0xd8),-1);
      *(int *)(pAVar2 + 8) = *(int *)pAVar2 + 1;
      pvVar6 = realloc(*(void **)(pAVar2 + 4),(*(int *)pAVar2 + 1) * 4);
      *(void **)(pAVar2 + 4) = pvVar6;
      *(undefined4 *)((int)pvVar6 + *(int *)pAVar2 * 4) = uVar5;
      *(int *)pAVar2 = *(int *)(pAVar2 + 8);
      Ship::setRace(*(Ship **)((int)pvVar6 + *(int *)(pAVar2 + 8) * 4 + -4),1);
      Ship::adjustPrice(*(Ship **)(*(int *)(pAVar2 + 4) + *(int *)pAVar2 * 4 + -4));
    }
    iVar1 = Station::getIndex(param_1);
    if (((iVar1 == 0x78) &&
        (iVar1 = Status::getCurrentCampaignMission(Globals::status), 0x9e < iVar1)) &&
       ((iVar1 = Status::hardCoreMode(), iVar1 != 0 ||
        ((iVar1 = Status::hardCoreMode(), iVar1 == 0 &&
         (iVar1 = Achievements::gotAllSupernovaMedals(Globals::achievements), iVar1 == 1)))))) {
      uVar5 = Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0xb0),-1);
      *(int *)(pAVar2 + 8) = *(int *)pAVar2 + 1;
      pvVar6 = realloc(*(void **)(pAVar2 + 4),(*(int *)pAVar2 + 1) * 4);
      *(void **)(pAVar2 + 4) = pvVar6;
      *(undefined4 *)((int)pvVar6 + *(int *)pAVar2 * 4) = uVar5;
      *(int *)pAVar2 = *(int *)(pAVar2 + 8);
      Ship::setRace(*(Ship **)((int)pvVar6 + *(int *)(pAVar2 + 8) * 4 + -4),1);
      Ship::adjustPrice(*(Ship **)(*(int *)(pAVar2 + 4) + *(int *)pAVar2 * 4 + -4));
    }
    iVar1 = Station::getIndex(param_1);
    if ((iVar1 == 0x78) &&
       (iVar1 = Status::getCurrentCampaignMission(Globals::status), 0x9e < iVar1)) {
      uVar5 = Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0xc4),-1);
      *(int *)(pAVar2 + 8) = *(int *)pAVar2 + 1;
      pvVar6 = realloc(*(void **)(pAVar2 + 4),(*(int *)pAVar2 + 1) * 4);
      *(void **)(pAVar2 + 4) = pvVar6;
      *(undefined4 *)((int)pvVar6 + *(int *)pAVar2 * 4) = uVar5;
      *(int *)pAVar2 = *(int *)(pAVar2 + 8);
      Ship::setRace(*(Ship **)((int)pvVar6 + *(int *)(pAVar2 + 8) * 4 + -4),1);
      Ship::adjustPrice(*(Ship **)(*(int *)(pAVar2 + 4) + *(int *)pAVar2 * 4 + -4));
    }
    if ((bVar20) && (iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,8), iVar1 == 0)) {
      uVar5 = Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0xcc),-1);
      *(int *)(pAVar2 + 8) = *(int *)pAVar2 + 1;
      pvVar6 = realloc(*(void **)(pAVar2 + 4),(*(int *)pAVar2 + 1) * 4);
      *(void **)(pAVar2 + 4) = pvVar6;
      *(undefined4 *)((int)pvVar6 + *(int *)pAVar2 * 4) = uVar5;
      *(int *)pAVar2 = *(int *)(pAVar2 + 8);
      Ship::setRace(*(Ship **)((int)pvVar6 + *(int *)(pAVar2 + 8) * 4 + -4),0);
      Ship::adjustPrice(*(Ship **)(*(int *)(pAVar2 + 4) + *(int *)pAVar2 * 4 + -4));
    }
  }
  iVar1 = Station::getSystem(param_1);
  if ((iVar1 == 0x11) && (iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,3), iVar1 == 0)) {
    uVar5 = Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0xa8),-1);
    *(int *)(pAVar2 + 8) = *(int *)pAVar2 + 1;
    pvVar6 = realloc(*(void **)(pAVar2 + 4),(*(int *)pAVar2 + 1) * 4);
    *(void **)(pAVar2 + 4) = pvVar6;
    *(undefined4 *)((int)pvVar6 + *(int *)pAVar2 * 4) = uVar5;
    *(int *)pAVar2 = *(int *)(pAVar2 + 8);
    Ship::setRace(*(Ship **)((int)pvVar6 + *(int *)(pAVar2 + 8) * 4 + -4),1);
    Ship::adjustPrice(*(Ship **)(*(int *)(pAVar2 + 4) + *(int *)pAVar2 * 4 + -4));
  }
  iVar1 = Station::getSystem(param_1);
  if ((iVar1 == 0x11) && (iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,3), iVar1 == 0)) {
    uVar5 = Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0xac),-1);
    *(int *)(pAVar2 + 8) = *(int *)pAVar2 + 1;
    pvVar6 = realloc(*(void **)(pAVar2 + 4),(*(int *)pAVar2 + 1) * 4);
    *(void **)(pAVar2 + 4) = pvVar6;
    *(undefined4 *)((int)pvVar6 + *(int *)pAVar2 * 4) = uVar5;
    *(int *)pAVar2 = *(int *)(pAVar2 + 8);
    Ship::setRace(*(Ship **)((int)pvVar6 + *(int *)(pAVar2 + 8) * 4 + -4),2);
    Ship::adjustPrice(*(Ship **)(*(int *)(pAVar2 + 4) + *(int *)pAVar2 * 4 + -4));
  }
  iVar1 = Station::getSystem(param_1);
  if (iVar1 != 0x11) {
    return pAVar2;
  }
  iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
  if (iVar1 != 0) {
    return pAVar2;
  }
  uVar5 = Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0xd0),-1);
  *(int *)(pAVar2 + 8) = *(int *)pAVar2 + 1;
  pvVar6 = realloc(*(void **)(pAVar2 + 4),(*(int *)pAVar2 + 1) * 4);
  *(void **)(pAVar2 + 4) = pvVar6;
  *(undefined4 *)((int)pvVar6 + *(int *)pAVar2 * 4) = uVar5;
  *(int *)pAVar2 = *(int *)(pAVar2 + 8);
  pvVar6 = (void *)((int)pvVar6 + *(int *)(pAVar2 + 8) * 4);
  iVar1 = 0;
LAB_000a19d6:
  Ship::setRace(*(Ship **)((int)pvVar6 + -4),iVar1);
  Ship::adjustPrice(*(Ship **)(*(int *)(pAVar2 + 4) + *(int *)pAVar2 * 4 + -4));
  return pAVar2;
}

// ===== Generator::getLootList  @0x000a1b78  (570 bytes)
/* Generator::getLootList(int, int) */

Array * __thiscall Generator::getLootList(Generator *this,int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  Array *pAVar3;
  undefined4 *puVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  Ship *pSVar11;
  int iVar12;
  uint uVar13;
  
  piVar1 = Globals::items;
  if (param_1 < 0) {
    iVar12 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
    iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
    if (iVar6 == 0) {
      pAVar3 = (Array *)0x0;
    }
    else {
      pAVar3 = operator_new(0xc);
      puVar4 = operator_new__(4);
      *(undefined4 **)(pAVar3 + 4) = puVar4;
      *(undefined4 *)(pAVar3 + 8) = 1;
      *puVar4 = 0;
      uVar7 = iVar12 << 1;
      *(undefined4 *)pAVar3 = 0;
      if (iVar12 == 0) {
        uVar7 = 2;
      }
      ArraySetLength<int>(uVar7,pAVar3);
      piVar2 = Globals::items;
      if (*(int *)pAVar3 != 0) {
        uVar7 = 0;
        do {
          iVar12 = -1;
          do {
            iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,*piVar1);
            iVar8 = Item::getType(*(Item **)(piVar2[1] + iVar6 * 4));
            iVar9 = Item::getIngredients(*(Item **)(piVar2[1] + iVar6 * 4));
            if ((iVar9 == 0) &&
               (iVar9 = AbyssEngine::AERandom::nextInt(Globals::rnd,100),
               iVar9 < *(int *)(&DAT_00251e5c + iVar8 * 4))) {
              iVar9 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
              iVar10 = Item::getOccurence(*(Item **)(piVar1[1] + iVar6 * 4));
              if ((iVar9 < iVar10) &&
                 (((iVar9 = Item::getSinglePrice(*(Item **)(piVar2[1] + iVar6 * 4)), 0 < iVar9 &&
                   (1 < iVar6 - 0xd9U)) && (iVar6 != 0xa4 && iVar6 != 0xaf)))) {
                if (iVar8 == 4) {
                  *(int *)(*(int *)(pAVar3 + 4) + uVar7 * 4) = iVar6;
                  goto LAB_000a1d4a;
                }
                iVar8 = Item::getTecLevel(*(Item **)(piVar2[1] + iVar6 * 4));
                if (iVar8 < 8) {
                  *(int *)(*(int *)(pAVar3 + 4) + uVar7 * 4) = iVar6;
                  iVar12 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
                  iVar6 = *(int *)(pAVar3 + 4);
                  goto LAB_000a1d58;
                }
              }
            }
            iVar12 = iVar12 + 1;
          } while (iVar12 < 99);
          iVar12 = AbyssEngine::AERandom::nextInt(Globals::rnd,10);
          *(int *)(*(int *)(pAVar3 + 4) + uVar7 * 4) = iVar12 + 0x9a;
LAB_000a1d4a:
          iVar12 = AbyssEngine::AERandom::nextInt(Globals::rnd,9);
          iVar6 = *(int *)(pAVar3 + 4);
LAB_000a1d58:
          uVar13 = uVar7 | 1;
          uVar7 = uVar7 + 2;
          *(int *)(iVar6 + uVar13 * 4) = iVar12 + 1;
        } while (uVar7 < *(uint *)pAVar3);
      }
      pSVar11 = (Ship *)Status::getShip(Globals::status);
      iVar12 = Ship::hasJumpDrive(pSVar11);
      if (iVar12 != 0) {
        pSVar11 = (Ship *)Status::getShip(Globals::status);
        iVar12 = Ship::hasCargo(pSVar11,0x7a,1);
        if ((iVar12 == 0) &&
           (iVar12 = AbyssEngine::AERandom::nextInt(Globals::rnd,100), iVar12 < 10)) {
          **(undefined4 **)(pAVar3 + 4) = 0x7a;
        }
      }
    }
  }
  else {
    pAVar3 = operator_new(0xc);
    puVar4 = operator_new__(4);
    *(undefined4 **)(pAVar3 + 4) = puVar4;
    *puVar4 = 0;
    *(undefined4 *)pAVar3 = 0;
    *(undefined4 *)(pAVar3 + 8) = 1;
    pvVar5 = realloc(puVar4,4);
    *(void **)(pAVar3 + 4) = pvVar5;
    *(int *)((int)pvVar5 + *(int *)pAVar3 * 4) = param_1;
    *(int *)pAVar3 = *(int *)(pAVar3 + 8);
    iVar12 = *(int *)(pAVar3 + 8) + 1;
    *(int *)(pAVar3 + 8) = iVar12;
    pvVar5 = realloc(pvVar5,iVar12 * 4);
    *(void **)(pAVar3 + 4) = pvVar5;
    *(int *)((int)pvVar5 + *(int *)pAVar3 * 4) = param_2;
    *(undefined4 *)pAVar3 = *(undefined4 *)(pAVar3 + 8);
  }
  return pAVar3;
}

// ===== Generator::generateStationIndex  @0x000a1e2c  (376 bytes)
/* Generator::generateStationIndex(Array<SolarSystem*>*, int) */

int __thiscall Generator::generateStationIndex(Generator *this,Array *param_1,int param_2)

{
  bool bVar1;
  AERandom *this_00;
  int iVar2;
  int iVar3;
  SolarSystem *pSVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  
  do {
    iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
    iVar3 = param_2;
    if (0x13 < iVar2) {
      iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
      if (iVar3 < 0x28) {
        pSVar4 = (SolarSystem *)Status::getSystem(Globals::status);
        iVar3 = SolarSystem::getIndex(pSVar4);
        piVar5 = (int *)SolarSystem::getStations
                                  (*(SolarSystem **)(*(int *)(param_1 + 4) + iVar3 * 4));
        iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,*piVar5);
        iVar3 = *(int *)(piVar5[1] + iVar3 * 4);
      }
      else {
        iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x87);
      }
    }
    pSVar4 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar2 = SolarSystem::getIndex(pSVar4);
    if (iVar2 == 0xf) {
      pSVar4 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar3 = SolarSystem::getStations(pSVar4);
      this_00 = Globals::rnd;
      pSVar4 = (SolarSystem *)Status::getSystem(Globals::status);
      piVar5 = (int *)SolarSystem::getStations(pSVar4);
      iVar2 = AbyssEngine::AERandom::nextInt(this_00,*piVar5);
      iVar3 = *(int *)(*(int *)(iVar3 + 4) + iVar2 * 4);
    }
    iVar2 = 0;
    do {
      if (iVar3 == (&DAT_00251e70)[iVar2]) {
        bVar1 = false;
        goto LAB_000a1f34;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x34);
    bVar1 = true;
LAB_000a1f34:
    if (*(int *)param_1 != 0) {
      uVar7 = 0;
      do {
        iVar2 = SolarSystem::stationIsInSystem
                          (*(SolarSystem **)(*(int *)(param_1 + 4) + uVar7 * 4),iVar3);
        if (iVar2 != 0) goto LAB_000a1f58;
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(uint *)param_1);
    }
    uVar7 = 0;
LAB_000a1f58:
    iVar2 = Status::getSystemVisibilities(Globals::status);
    if (*(char *)(*(int *)(iVar2 + 4) + uVar7) == '\0') {
      bVar1 = false;
    }
    if (iVar3 - 0x6dU < 5) {
      bVar1 = false;
    }
    iVar2 = SolarSystem::getRoutes(*(SolarSystem **)(*(int *)(param_1 + 4) + uVar7 * 4));
    if (iVar2 == 0) {
      pSVar4 = (SolarSystem *)Status::getSystem(Globals::status);
      uVar6 = SolarSystem::getIndex(pSVar4);
      if (uVar7 != uVar6) {
        bVar1 = false;
      }
    }
    if (bVar1) {
      return iVar3;
    }
  } while( true );
}

// ===== Generator::createAgents  @0x000a1fd0  (1564 bytes)
/* Generator::createAgents(Station*) */

void __thiscall Generator::createAgents(Generator *this,Station *param_1)

{
  bool bVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  Array *pAVar5;
  undefined4 *puVar6;
  Ship *this_00;
  void *pvVar7;
  Array *pAVar8;
  undefined4 uVar9;
  SolarSystem *pSVar10;
  undefined4 uVar11;
  int *piVar12;
  Generator *this_01;
  Standing *this_02;
  Mission *pMVar13;
  int iVar14;
  Generator *pGVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  Generator *pGVar19;
  Agent *pAVar20;
  String aSStack_38 [8];
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  iVar2 = Status::inSupernovaSystem(Globals::status);
  if (iVar2 == 0) {
    puVar3 = (uint *)Status::getAgents(Globals::status);
    iVar2 = Status::getCurrentCampaignMission(Globals::status);
    bVar1 = 0x10 < iVar2;
    iVar4 = Status::dlc1Won(Globals::status);
    if (iVar4 == 0) {
      iVar4 = Station::getIndex(param_1);
      bVar1 = 0x10 < iVar2 && iVar4 != 0x6a;
    }
    uVar16 = 0;
    if (*puVar3 != 0) {
      uVar17 = 0;
      do {
        iVar2 = Agent::getStation(*(Agent **)(puVar3[1] + uVar17 * 4));
        iVar4 = Station::getIndex(param_1);
        if (iVar2 == iVar4) {
          uVar16 = uVar16 + bVar1;
        }
        uVar17 = uVar17 + 1;
      } while (uVar17 < *puVar3);
    }
    iVar2 = Station::getIndex(param_1);
    if (iVar2 != 0x6c) {
      iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
      if ((int)(iVar2 + uVar16 + 3) < 5) {
        iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
        uVar16 = iVar2 + uVar16 + 3;
      }
      else {
        uVar16 = 5;
      }
    }
    pAVar5 = operator_new(0xc);
    puVar6 = operator_new__(4);
    pGVar15 = (Generator *)0x0;
    *(undefined4 **)(pAVar5 + 4) = puVar6;
    *(undefined4 *)(pAVar5 + 8) = 1;
    *puVar6 = 0;
    *(undefined4 *)pAVar5 = 0;
    ArraySetLength<Agent*>(uVar16,pAVar5);
    if (*puVar3 != 0) {
      uVar16 = 0;
      do {
        iVar2 = Agent::getStation(*(Agent **)(puVar3[1] + uVar16 * 4));
        iVar4 = Station::getIndex(param_1);
        if (iVar2 == iVar4 && bVar1 == 1) {
          *(undefined4 *)(*(int *)(pAVar5 + 4) + (int)pGVar15 * 4) =
               *(undefined4 *)(puVar3[1] + uVar16 * 4);
          iVar2 = Agent::getOffer(*(Agent **)(puVar3[1] + uVar16 * 4));
          pGVar15 = pGVar15 + 1;
          if (iVar2 == 9) {
            iVar2 = Status::getCurrentCampaignMission(Globals::status);
            if (iVar2 < 0x8e) {
              iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,7);
              iVar2 = iVar2 + 2;
            }
            else {
              iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,9);
            }
            iVar18 = (&DAT_00251d10)[iVar2];
            pAVar20 = *(Agent **)(puVar3[1] + uVar16 * 4);
            iVar4 = Item::getSinglePrice(*(Item **)(*(int *)(Globals::items + 4) + iVar18 * 4));
            iVar14 = 1;
            if (iVar2 - 3U < 2) {
              iVar14 = 10;
            }
            Agent::setSellItemData(pAVar20,iVar18,iVar14,iVar4 * iVar14);
            Agent::setOfferAccepted(*(Agent **)(puVar3[1] + uVar16 * 4),false);
          }
          else {
            iVar2 = Agent::getOffer(*(Agent **)(puVar3[1] + uVar16 * 4));
            if (iVar2 == 10) {
              piVar12 = operator_new(0xc);
              puVar6 = operator_new__(4);
              iVar2 = 0;
              piVar12[1] = (int)puVar6;
              piVar12[2] = 1;
              *puVar6 = 0;
              *piVar12 = 0;
              do {
                iVar14 = (&DAT_00251f40)[iVar2];
                iVar4 = Station::hasShip(*(Station **)(Globals::status + 0x14c),iVar14);
                if (iVar4 == 0) {
                  this_00 = (Ship *)Status::getShip(Globals::status);
                  iVar4 = Ship::getIndex(this_00);
                  if (iVar4 != iVar14) {
                    piVar12[2] = *piVar12 + 1;
                    pvVar7 = realloc((void *)piVar12[1],(*piVar12 + 1) * 4);
                    piVar12[1] = (int)pvVar7;
                    *(int *)((int)pvVar7 + *piVar12 * 4) = iVar14;
                    *piVar12 = piVar12[2];
                  }
                }
                iVar2 = iVar2 + 1;
              } while (iVar2 != 6);
              iVar2 = *piVar12;
              if (iVar2 == 0) {
                uVar17 = puVar3[1];
              }
              else {
                iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,iVar2);
                iVar14 = *(int *)(piVar12[1] + iVar4 * 4);
                pAVar20 = *(Agent **)(puVar3[1] + uVar16 * 4);
                iVar4 = Ship::getPrice(*(Ship **)(*(int *)(Globals::ships + 4) + iVar14 * 4));
                Agent::setSellItemData(pAVar20,iVar14,1,iVar4);
                uVar17 = puVar3[1];
              }
              Agent::setOfferAccepted(*(Agent **)(uVar17 + uVar16 * 4),iVar2 == 0);
              if ((void *)piVar12[1] != (void *)0x0) {
                operator_delete__((void *)piVar12[1]);
              }
              operator_delete(piVar12);
            }
          }
        }
        uVar16 = uVar16 + 1;
      } while (uVar16 < *puVar3);
    }
    pAVar8 = (Array *)Galaxy::getSystems(Globals::galaxy);
    iVar2 = Status::getCurrentCampaignMission(Globals::status);
    if ((iVar2 == 0x17) && (iVar2 = Station::getIndex(param_1), iVar2 == 10)) {
      pAVar20 = operator_new(0x88);
      Globals::getRandomName((int)aSStack_30,SUB41(Globals::globals,0));
      uVar9 = Station::getIndex(param_1);
      pSVar10 = (SolarSystem *)Status::getSystem(Globals::status);
      uVar11 = SolarSystem::getIndex(pSVar10);
      Agent::Agent(pAVar20,0xffffffff,aSStack_30,uVar9,uVar11,0,1,0xffffffff,0xffffffff,0xffffffff,
                   0xffffffff);
      AbyssEngine::String::~String(aSStack_30);
      Agent::setOffer(pAVar20,2);
      Agent::setSellItemData(pAVar20,0x44,1,100000);
      piVar12 = (int *)ImageFactory::createChar(Globals::imageFactory,true,0);
      Agent::setImageParts(pAVar20,piVar12);
      *(Agent **)(*(int *)(pAVar5 + 4) + (int)pGVar15 * 4) = pAVar20;
      pGVar15 = pGVar15 + 1;
    }
    this_01 = *(Generator **)pAVar5;
    if (pGVar15 < this_01) {
      bVar1 = false;
      pGVar19 = pGVar15;
      do {
        uVar9 = createAgent(this_01,param_1);
        *(undefined4 *)(*(int *)(pAVar5 + 4) + (int)pGVar19 * 4) = uVar9;
        iVar2 = Agent::getOffer(*(Agent **)(*(int *)(pAVar5 + 4) + (int)pGVar19 * 4));
        if (iVar2 == 6) {
          if (bVar1) {
            bVar1 = true;
            Agent::setOffer(*(Agent **)(*(int *)(pAVar5 + 4) + (int)pGVar19 * 4),1);
          }
          else {
            bVar1 = true;
          }
        }
        else {
          iVar2 = Agent::getOffer(*(Agent **)(*(int *)(pAVar5 + 4) + (int)pGVar19 * 4));
          if (iVar2 == 0) {
            pAVar20 = *(Agent **)(*(Generator **)(pAVar5 + 4) + (int)pGVar19 * 4);
            pMVar13 = (Mission *)createMission(*(Generator **)(pAVar5 + 4),pAVar20,pAVar8);
            Agent::setMission(pAVar20,pMVar13);
          }
        }
        pGVar19 = pGVar19 + 1;
        this_01 = *(Generator **)pAVar5;
      } while (pGVar19 < this_01);
    }
    iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
    if (iVar2 < 0x23) {
      this_02 = (Standing *)Status::getStanding(Globals::status);
      iVar2 = 0;
      do {
        iVar14 = (&DAT_00251f80)[iVar2];
        iVar4 = Standing::isEnemy(this_02,iVar14);
        if ((iVar4 == 1) && (*(int *)pAVar5 != 0)) {
          uVar16 = 0;
          do {
            iVar4 = Agent::isGenericAgent(*(Agent **)(*(int *)(pAVar5 + 4) + uVar16 * 4));
            if ((iVar4 == 1) &&
               (iVar4 = Agent::getOffer(*(Agent **)(*(int *)(pAVar5 + 4) + uVar16 * 4)), iVar4 != 7)
               ) {
              *(undefined4 *)(*(int *)(pAVar5 + 4) + uVar16 * 4) = 0;
              pAVar20 = operator_new(0x88);
              Globals::getRandomName((int)aSStack_38,SUB41(Globals::globals,0));
              uVar9 = Station::getIndex(param_1);
              pSVar10 = (SolarSystem *)Status::getSystem(Globals::status);
              uVar11 = SolarSystem::getIndex(pSVar10);
              Agent::Agent(pAVar20,0xffffffff,aSStack_38,uVar9,uVar11,iVar14,1,0xffffffff,0xffffffff
                           ,0xffffffff,0xffffffff);
              *(Agent **)(*(int *)(pAVar5 + 4) + uVar16 * 4) = pAVar20;
              AbyssEngine::String::~String(aSStack_38);
              Agent::setOffer(*(Agent **)(*(int *)(pAVar5 + 4) + uVar16 * 4),7);
              pAVar20 = *(Agent **)(*(int *)(pAVar5 + 4) + uVar16 * 4);
              piVar12 = (int *)ImageFactory::createChar(Globals::imageFactory,true,iVar14);
              Agent::setImageParts(pAVar20,piVar12);
              break;
            }
            uVar16 = uVar16 + 1;
          } while (uVar16 < *(uint *)pAVar5);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < 4);
    }
    iVar2 = Status::getCurrentCampaignMission(Globals::status);
    if ((((iVar2 == 0x17) && (iVar2 = Station::getIndex(param_1), iVar2 == 10)) ||
        (iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,100), iVar2 == 1)) &&
       (pGVar15 < *(Generator **)pAVar5)) {
      do {
        pAVar20 = *(Agent **)(*(int *)(pAVar5 + 4) + (int)pGVar15 * 4);
        iVar2 = Agent::isStoryAgent(pAVar20);
        if (((iVar2 == 0) && (iVar2 = Agent::getOffer(pAVar20), iVar2 == 0)) &&
           (iVar2 = Agent::getMission(pAVar20), iVar2 != 0)) {
          pMVar13 = (Mission *)Agent::getMission(pAVar20);
          iVar2 = Mission::getReward(pMVar13);
          if (iVar2 < 50000) {
            pMVar13 = (Mission *)Agent::getMission(pAVar20);
            iVar2 = Mission::getReward(pMVar13);
            iVar2 = iVar2 * 10;
            if (50000 < iVar2) {
              iVar2 = 50000;
            }
            pMVar13 = (Mission *)Agent::getMission(pAVar20);
            Mission::setReward(pMVar13,iVar2);
            break;
          }
        }
        pGVar15 = pGVar15 + 1;
      } while (pGVar15 < *(Generator **)pAVar5);
    }
  }
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== Generator::createAgent  @0x000a26c0  (824 bytes)
/* Generator::createAgent(Station*) */

void __thiscall Generator::createAgent(Generator *this,Station *param_1)

{
  SolarSystem *pSVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  Agent *this_00;
  undefined4 uVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  Array *pAVar9;
  undefined4 *puVar10;
  void *pvVar11;
  bool bVar12;
  Item *this_01;
  uint in_fpscr;
  float fVar13;
  float fVar14;
  String aSStack_3c [8];
  int local_34;
  
  local_34 = __stack_chk_guard;
  pSVar1 = (SolarSystem *)Status::getSystem(Globals::status);
  iVar2 = SolarSystem::getRace(pSVar1);
  iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
  if (iVar3 < 0x14) {
    iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,8);
  }
  do {
    do {
      iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,7);
    } while (iVar2 == 1 && iVar3 == 6);
  } while ((iVar3 - 3U < 8) && ((0x1cU >> (iVar3 - 3U & 0xff) & 1) == 0));
  iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
  if (iVar4 < 0x21) {
    iVar3 = 0;
  }
  else if ((iVar3 - 5U < 2) &&
          (iVar4 = Status::getCurrentCampaignMission(Globals::status), iVar4 < 0x10)) {
    iVar3 = 0;
  }
  bVar12 = true;
  if ((iVar2 == 0) && (iVar3 != 6)) {
    iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
    bVar12 = false;
    if (iVar4 < 0x3c) {
      bVar12 = true;
    }
  }
  this_00 = operator_new(0x88);
  Globals::getRandomName((int)aSStack_3c,SUB41(Globals::globals,0));
  uVar5 = Station::getIndex(param_1);
  pSVar1 = (SolarSystem *)Status::getSystem(Globals::status);
  uVar6 = SolarSystem::getIndex(pSVar1);
  Agent::Agent(this_00,0xffffffff,aSStack_3c,uVar5,uVar6,iVar2,bVar12,0xffffffff,0xffffffff,
               0xffffffff,0xffffffff);
  AbyssEngine::String::~String(aSStack_3c);
  Agent::setOffer(this_00,iVar3);
  piVar7 = (int *)ImageFactory::createChar(Globals::imageFactory,bVar12,iVar2);
  Agent::setImageParts(this_00,piVar7);
  iVar2 = Agent::getOffer(this_00);
  if (iVar2 == 6) {
    uVar8 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
    pAVar9 = operator_new(0xc);
    puVar10 = operator_new__(4);
    *(undefined4 **)(pAVar9 + 4) = puVar10;
    *(undefined4 *)(pAVar9 + 8) = 1;
    *puVar10 = 0;
    *(undefined4 *)pAVar9 = 0;
    ArraySetLength<AbyssEngine::String*>(uVar8,pAVar9);
    if (0 < (int)uVar8) {
      iVar2 = 0;
      do {
        pvVar11 = operator_new(8);
        uVar5 = Globals::globals;
        Agent::getRace(this_00);
        Globals::getRandomName((int)pvVar11,SUB41(uVar5,0));
        *(void **)(*(int *)(pAVar9 + 4) + iVar2 * 4) = pvVar11;
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)uVar8);
    }
    Agent::setWingmanFriendNames(this_00,pAVar9);
    iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x514);
    Agent::setCosts(this_00,(iVar2 + 700) * (uVar8 + 1));
    iVar2 = Status::hardCoreMode();
    if (iVar2 != 0) {
      iVar2 = Agent::getCosts(this_00);
      Agent::setCosts(this_00,iVar2 * 7);
    }
  }
  else {
    iVar2 = Agent::getOffer(this_00);
    piVar7 = Globals::items;
    if (iVar2 == 2) {
LAB_000a28fc:
      iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,*piVar7);
      if (iVar2 < 0xd9) {
        if ((iVar2 == 0x83 || iVar2 == 0xa4) || (iVar2 == 0xaf)) goto LAB_000a28fc;
      }
      else if (iVar2 - 0xd9U < 2) goto LAB_000a28fc;
      iVar3 = Item::getIngredients(*(Item **)(piVar7[1] + iVar2 * 4));
      if ((iVar3 != 0) ||
         ((iVar3 = Item::getSinglePrice(*(Item **)(piVar7[1] + iVar2 * 4)), iVar3 == 0 ||
          (iVar3 = Item::getOccurence(*(Item **)(piVar7[1] + iVar2 * 4)), iVar3 == 0))))
      goto LAB_000a28fc;
      this_01 = *(Item **)(piVar7[1] + iVar2 * 4);
      iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,0xf);
      iVar4 = Item::getType(this_01);
      if ((iVar4 == 3) ||
         ((iVar4 = Item::getType(this_01), iVar4 == 0 ||
          (iVar4 = Item::getType(this_01), iVar4 == 2)))) {
        iVar3 = 1;
      }
      else {
        iVar3 = iVar3 + 5;
      }
      iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x78);
      fVar13 = (float)VectorSignedToFloat(iVar4 + 0x28,(byte)(in_fpscr >> 0x16) & 3);
      uVar5 = Item::getSinglePrice(*(Item **)(Globals::items[1] + iVar2 * 4));
      fVar14 = (float)VectorSignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
      Agent::setSellItemData(this_00,iVar2,iVar3,(int)((fVar13 / 100.0) * fVar14) * iVar3);
    }
  }
  if (__stack_chk_guard - local_34 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_34);
  }
  return;
}

// ===== Generator::createMission  @0x000a2a7c  (2044 bytes)
/* Generator::createMission(Agent*, Array<SolarSystem*>*) */

void __thiscall Generator::createMission(Generator *this,Agent *param_1,Array *param_2)

{
  bool bVar1;
  byte *pbVar2;
  Galaxy *pGVar3;
  int *piVar4;
  Generator *pGVar5;
  SolarSystem *pSVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  Station *pSVar12;
  int iVar13;
  float fVar14;
  Standing *this_00;
  Mission *this_01;
  undefined4 uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  uint *puVar20;
  uint in_fpscr;
  float fVar21;
  float fVar22;
  int local_70;
  String aSStack_64 [8];
  String aSStack_5c [8];
  String aSStack_54 [8];
  String aSStack_4c [8];
  int local_44;
  
  local_44 = __stack_chk_guard;
  pGVar5 = (Generator *)Agent::getStation(param_1);
  local_70 = generateStationIndex(pGVar5,param_2,(int)pGVar5);
  pSVar6 = (SolarSystem *)Status::getSystem(Globals::status);
  iVar7 = SolarSystem::getIndex(pSVar6);
  if (iVar7 == 0xf) {
    pSVar6 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar7 = SolarSystem::getStations(pSVar6);
    iVar7 = **(int **)(iVar7 + 4);
    local_70 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
    local_70 = local_70 + iVar7;
  }
  uVar8 = Agent::getRace(param_1);
  puVar20 = *(uint **)(Globals::status + 0x50);
  iVar7 = 999;
  do {
    uVar9 = AbyssEngine::AERandom::nextInt(Globals::rnd,0xf);
    if (uVar9 == 8) {
      uVar9 = 8;
    }
    else {
      if ((uVar9 != 10) || (uVar8 < 4)) {
        if (puVar20 != (uint *)0x0) {
          uVar10 = puVar20[1];
          if (*(char *)(uVar10 + uVar9) != '\0') {
            uVar16 = *puVar20;
            if (uVar16 != 0) {
              iVar17 = 0;
              uVar18 = 0;
              do {
                pbVar2 = (byte *)(uVar10 + uVar18);
                uVar18 = uVar18 + 1;
                iVar17 = iVar17 + (uint)*pbVar2;
              } while (uVar18 < uVar16);
              if ((iVar17 == 0xe) && (uVar16 != 0)) {
                __aeabi_memclr();
              }
            }
            goto LAB_000a2b6e;
          }
          *(undefined1 *)(uVar10 + uVar9) = 1;
        }
        if (uVar9 == 0xc) {
          pSVar6 = (SolarSystem *)Status::getSystem(Globals::status);
          SolarSystem::getIndex(pSVar6);
          uVar9 = 0xc;
        }
        break;
      }
      uVar9 = 10;
    }
LAB_000a2b6e:
    bVar1 = 0 < iVar7;
    iVar7 = iVar7 + -1;
  } while (bVar1);
  iVar7 = Status::getCurrentCampaignMission(Globals::status);
  if (((iVar7 < 0x10) || ((uVar9 == 0xf && (Globals::options[0x37] == '\0')))) &&
     (uVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,5), uVar10 < 5)) {
    uVar9 = *(uint *)(&DAT_00251f60 + uVar10 * 4);
  }
  if (uVar9 == 0xc) {
    local_70 = Agent::getStation(param_1);
  }
  iVar7 = Agent::getOffer(param_1);
  if (iVar7 == 5) {
    local_70 = Agent::getStation(param_1);
    uVar9 = 8;
  }
  else {
    if ((uVar9 < 0xf) && ((1 << (uVar9 & 0xff) & 0x4801U) != 0)) {
      pSVar12 = (Station *)Status::getStation(Globals::status);
      iVar7 = Station::getIndex(pSVar12);
      if (local_70 == iVar7) {
        do {
          pGVar5 = (Generator *)Agent::getStation(param_1);
          local_70 = generateStationIndex(pGVar5,param_2,(int)pGVar5);
          pSVar12 = (Station *)Status::getStation(Globals::status);
          iVar7 = Station::getIndex(pSVar12);
        } while (local_70 == iVar7);
      }
    }
    if ((uVar8 < 4) && (uVar9 == 0xd)) {
      iVar7 = Agent::getSystem(param_1);
      iVar7 = SolarSystem::getRoutes(*(SolarSystem **)(*(int *)(param_2 + 4) + iVar7 * 4));
      if (iVar7 != 0) {
        do {
          do {
            pGVar5 = (Generator *)Agent::getStation(param_1);
            local_70 = generateStationIndex(pGVar5,param_2,(int)pGVar5);
          } while (*(int *)param_2 == 0);
          uVar9 = 0;
          do {
            iVar7 = SolarSystem::stationIsInSystem
                              (*(SolarSystem **)(*(int *)(param_2 + 4) + uVar9 * 4),local_70);
            if ((iVar7 == 1) &&
               (uVar10 = SolarSystem::getRace(*(SolarSystem **)(*(int *)(param_2 + 4) + uVar9 * 4)),
               uVar10 == uVar8)) {
              uVar9 = 0xd;
              goto LAB_000a2ce4;
            }
            uVar9 = uVar9 + 1;
          } while (uVar9 < *(uint *)param_2);
        } while( true );
      }
      iVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
      uVar9 = 4;
      if (iVar7 == 0) {
        uVar9 = 1;
      }
    }
  }
LAB_000a2ce4:
  Agent::getName();
  iVar7 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar7 < 0x10) {
    iVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
  }
  else {
    iVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,9);
  }
  piVar4 = Globals::items;
  if (uVar9 == 8) {
    do {
      do {
        do {
          uVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,*piVar4 + -0x61);
          iVar17 = uVar10 + 0x61;
          iVar7 = Item::getOccurence(*(Item **)(piVar4[1] + iVar17 * 4));
        } while (iVar7 == 0);
        iVar7 = Item::getSinglePrice(*(Item **)(piVar4[1] + iVar17 * 4));
      } while (iVar7 == 0);
      iVar7 = Item::getIngredients(*(Item **)(piVar4[1] + iVar17 * 4));
    } while (((((uVar10 & 0xfffffffe) == 0x78 || iVar17 == 0x75) ||
              ((uVar10 & 0xfffffffe) == 0x12 || iVar17 == 0x83)) ||
             (iVar17 == 0xa4 || iVar17 == 0xaf)) || (iVar7 != 0));
    iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,0xf);
    iVar7 = Item::getTecLevel(*(Item **)(piVar4[1] + iVar17 * 4));
    iVar11 = iVar11 + 5;
    goto switchD_000a2dbe_caseD_1;
  }
  iVar7 = iVar7 + 1;
  iVar11 = 0;
  iVar17 = 0;
  switch(uVar9) {
  case 0:
    iVar17 = AbyssEngine::AERandom::nextInt(Globals::rnd,7);
    fVar14 = (float)VectorSignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
    iVar11 = (int)((fVar14 / 10.0) * 95.0) + 5;
  case 1:
  case 4:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
    goto switchD_000a2dbe_caseD_1;
  case 2:
    uVar15 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
    iVar17 = 0;
    fVar14 = (float)VectorSignedToFloat(uVar15,(byte)(in_fpscr >> 0x16) & 3);
    break;
  case 3:
  case 5:
    iVar17 = 0x75;
    fVar14 = (float)VectorSignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
    fVar14 = (fVar14 / 10.0) * 8.0;
    if (uVar9 == 3) {
      iVar17 = 0x74;
    }
    break;
  case 0xb:
    fVar14 = (float)VectorSignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
    iVar11 = (int)((fVar14 / 10.0) * 18.0) + 2;
    goto LAB_000a2eda;
  default:
    if (uVar9 == 0xf) {
      uVar15 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x5a);
      fVar14 = (float)VectorSignedToFloat(uVar15,(byte)(in_fpscr >> 0x16) & 3);
      iVar11 = (int)fVar14 + 0x1e;
      if (*(int *)param_2 == 0) {
        iVar17 = 0;
      }
      else {
        uVar10 = 0;
        iVar17 = 0;
        do {
          iVar13 = SolarSystem::stationIsInSystem
                             (*(SolarSystem **)(*(int *)(param_2 + 4) + uVar10 * 4),local_70);
          pGVar3 = Globals::galaxy;
          if (iVar13 == 1) {
            pSVar12 = (Station *)Status::getStation(Globals::status);
            iVar17 = Galaxy::getAsteroidProbabilities(pGVar3,pSVar12);
            iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
            iVar17 = *(int *)(iVar17 + iVar13 * 8);
            break;
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < *(uint *)param_2);
      }
      goto switchD_000a2dbe_caseD_1;
    }
LAB_000a2eda:
    iVar17 = 0;
    goto switchD_000a2dbe_caseD_1;
  }
  iVar11 = (int)fVar14 + 2;
switchD_000a2dbe_caseD_1:
  pGVar3 = Globals::galaxy;
  if (9 < iVar7) {
    iVar7 = 10;
  }
  pSVar12 = (Station *)Status::getStation(Globals::status);
  iVar13 = Station::getSystem(pSVar12);
  pSVar6 = *(SolarSystem **)(*(int *)(param_2 + 4) + iVar13 * 4);
  pSVar12 = (Station *)Galaxy::getStation(Globals::galaxy,local_70);
  iVar13 = Station::getSystem(pSVar12);
  fVar14 = (float)Galaxy::distance(pGVar3,pSVar6,
                                   *(SolarSystem **)(*(int *)(param_2 + 4) + iVar13 * 4));
  fVar22 = (float)VectorSignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
  fVar22 = (float)VectorSignedToFloat((int)((fVar22 / 10.0) * 5500.0) + 0x5dc,
                                      (byte)(in_fpscr >> 0x16) & 3);
  fVar22 = fVar22 * (fVar14 / 1200.0 + 1.0);
  if (uVar9 == 9) {
    fVar22 = fVar22 * 1.2;
  }
  else if (uVar9 == 7) {
    fVar22 = fVar22 * 0.7;
  }
  else if (uVar9 == 8) {
    iVar13 = Item::getMaxPrice(*(Item **)(Globals::items[1] + iVar17 * 4));
    fVar22 = (float)VectorSignedToFloat(iVar11 * iVar13,(byte)(in_fpscr >> 0x16) & 3);
    fVar22 = fVar22 * 1.7;
  }
  else if (uVar9 == 3 || uVar9 == 5) {
    fVar22 = fVar22 + fVar22;
  }
  else if (uVar9 == 0xb) {
    fVar14 = (float)VectorSignedToFloat(iVar11,(byte)(in_fpscr >> 0x16) & 3);
    fVar22 = fVar22 * 0.6 + fVar14 * ((fVar22 * 0.6) / 5.0);
  }
  iVar13 = Status::getLevel(Globals::status);
  fVar14 = (float)VectorSignedToFloat(iVar13 * iVar13 * iVar13 * 10,(byte)(in_fpscr >> 0x16) & 3);
  fVar22 = fVar22 + fVar14;
  if ((uVar9 | 4) == 0xc) {
    iVar19 = 0;
  }
  else {
    this_00 = (Standing *)Status::getStanding(Globals::status);
    iVar13 = Agent::getRace(param_1);
    fVar14 = (float)Standing::getMissionBonus(this_00,iVar13);
    iVar13 = (int)(fVar22 * fVar14) / 0x32;
    iVar19 = (int)(fVar22 * fVar14) * 2 + iVar13 * -0x32;
    if (iVar19 % 0x32 != 0) {
      iVar19 = iVar13 * 0x32;
    }
  }
  fVar21 = (float)VectorSignedToFloat((int)fVar22 % 0x32,(byte)(in_fpscr >> 0x16) & 3);
  fVar14 = fVar22 - fVar21;
  if ((int)(fVar22 + fVar21) % 0x32 == 0) {
    fVar14 = fVar22 + fVar21;
  }
  this_01 = operator_new(100);
  AbyssEngine::String::String(aSStack_54,aSStack_4c,false);
  uVar15 = Agent::getImageParts(param_1);
  Mission::Mission(this_01,uVar9,aSStack_54,uVar15,uVar8,(int)fVar14,local_70,iVar7);
  AbyssEngine::String::~String(aSStack_54);
  uVar15 = AbyssEngine::AERandom::nextInt(Globals::rnd,(int)fVar14 / 10);
  fVar22 = (float)VectorSignedToFloat(uVar15,(byte)(in_fpscr >> 0x16) & 3);
  iVar7 = (int)(fVar14 / 10.0 + fVar22);
  if (uVar9 == 8) {
    fVar14 = (float)VectorSignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
    iVar7 = (int)(fVar14 * 0.5);
  }
  else if (uVar9 == 6) {
    Globals::getRandomName((int)aSStack_5c,SUB41(Globals::globals,0));
    Mission::setTargetName(this_01,aSStack_5c);
    AbyssEngine::String::~String(aSStack_5c);
  }
  iVar13 = iVar7 * 2 + (iVar7 / 0x32) * -0x32;
  if (iVar13 % 0x32 != 0) {
    iVar13 = (iVar7 / 0x32) * 0x32;
  }
  Mission::setCosts(this_01,iVar13);
  Mission::setProductionGoods(this_01,iVar17,iVar11);
  Mission::setBonus(this_01,iVar19);
  if (*(int *)param_2 != 0) {
    uVar8 = 0;
    do {
      iVar7 = SolarSystem::stationIsInSystem
                        (*(SolarSystem **)(*(int *)(param_2 + 4) + uVar8 * 4),local_70);
      if (iVar7 == 1) {
        SolarSystem::getName();
        Mission::setTargetSystemName(this_01,aSStack_64);
        AbyssEngine::String::~String(aSStack_64);
        break;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(uint *)param_2);
  }
  AbyssEngine::String::~String(aSStack_4c);
  if (__stack_chk_guard - local_44 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_44);
  }
  return;
}

