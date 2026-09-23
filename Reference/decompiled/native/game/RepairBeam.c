// Class: RepairBeam
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== RepairBeam::RepairBeam  @0x000b3fb8  (300 bytes)
/* RepairBeam::RepairBeam(int, int) */

RepairBeam * __thiscall RepairBeam::RepairBeam(RepairBeam *this,int param_1,int param_2)

{
  ushort uVar1;
  Ship *this_00;
  Item *this_01;
  uint uVar2;
  Array *pAVar3;
  undefined4 *puVar4;
  AEGeometry *this_02;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(int *)(this + 0x1c) = param_2;
  *(int *)this = param_1;
  this_00 = (Ship *)Status::getShip(Globals::status);
  this_01 = (Item *)Ship::getFirstEquipmentOfSort(this_00,*(int *)(this + 0x1c));
  uVar2 = Item::getAttribute(this_01,0x37);
  pAVar3 = operator_new(0xc);
  puVar4 = operator_new__(4);
  *(undefined4 **)(pAVar3 + 4) = puVar4;
  *(undefined4 *)(pAVar3 + 8) = 1;
  *puVar4 = 0;
  *(undefined4 *)pAVar3 = 0;
  *(Array **)(this + 0x10) = pAVar3;
  ArraySetLength<AEGeometry*>(uVar2,pAVar3);
  if (0 < (int)uVar2) {
    uVar1 = 0x4a95;
    if (param_2 == 0x25) {
      uVar1 = 0x4a94;
    }
    iVar8 = 0;
    do {
      this_02 = operator_new(0xc0);
      AEGeometry::AEGeometry(this_02,uVar1,Globals::Canvas,false);
      *(AEGeometry **)(*(int *)(*(int *)(this + 0x10) + 4) + iVar8 * 4) = this_02;
      iVar8 = iVar8 + 1;
    } while (iVar8 < (int)uVar2);
  }
  pAVar3 = operator_new(0xc);
  puVar4 = operator_new__(4);
  *(undefined4 **)(pAVar3 + 4) = puVar4;
  *(undefined4 *)(pAVar3 + 8) = 1;
  *puVar4 = 0;
  *(undefined4 *)pAVar3 = 0;
  *(Array **)(this + 0x14) = pAVar3;
  ArraySetLength<int>(uVar2,pAVar3);
  *(undefined4 *)(this + 0x20) = 0x9c4;
  puVar5 = *(uint **)(this + 0x14);
  if (*puVar5 != 0) {
    uVar6 = puVar5[1];
    uVar7 = 0;
    do {
      *(undefined4 *)(uVar6 + uVar7 * 4) = 0xffffffff;
      uVar7 = uVar7 + 1;
    } while (uVar7 < *puVar5);
  }
  pAVar3 = operator_new(0xc);
  puVar4 = operator_new__(4);
  *(undefined4 **)(pAVar3 + 4) = puVar4;
  *(undefined4 *)(pAVar3 + 8) = 1;
  *puVar4 = 0;
  *(undefined4 *)pAVar3 = 0;
  *(Array **)(this + 0x18) = pAVar3;
  ArraySetLength<float>(uVar2,pAVar3);
  uVar2 = **(uint **)(this + 0x18);
  if (uVar2 != 0) {
    uVar6 = 0;
    puVar4 = (undefined4 *)(*(uint **)(this + 0x18))[1];
    do {
      uVar6 = uVar6 + 1;
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    } while (uVar6 < uVar2);
  }
  return this;
}

// ===== RepairBeam::~RepairBeam  @0x000b416c  (86 bytes)
/* RepairBeam::~RepairBeam() */

RepairBeam * __thiscall RepairBeam::~RepairBeam(RepairBeam *this)

{
  void *pvVar1;
  
  if (*(Array **)(this + 0x10) != (Array *)0x0) {
    ArrayReleaseClasses<AEGeometry*>(*(Array **)(this + 0x10));
    pvVar1 = *(void **)(this + 0x10);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
    *(undefined4 *)(this + 0x10) = 0;
  }
  pvVar1 = *(void **)(this + 0x14);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x14) = 0;
  pvVar1 = *(void **)(this + 0x18);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x18) = 0;
  return this;
}

// ===== RepairBeam::update  @0x000b41c4  (1954 bytes)
/* RepairBeam::update(int, Radar*, Level*, Hud*) */

void RepairBeam::update(int param_1,Radar *param_2,Level *param_3,Hud *param_4)

{
  byte bVar1;
  uint *puVar2;
  PlayerEgo *pPVar3;
  int iVar4;
  Ship *pSVar5;
  Item *pIVar6;
  undefined4 uVar7;
  Player *pPVar8;
  int iVar9;
  undefined4 *puVar10;
  float fVar11;
  int iVar12;
  float *pfVar13;
  uint *puVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  KIPlayer *this;
  Vector *pVVar19;
  Vector *pVVar20;
  AEGeometry *this_00;
  bool bVar21;
  uint in_fpscr;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s1;
  float extraout_s2;
  float fVar22;
  Vector aVStack_a8 [12];
  AEMath aAStack_9c [12];
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 uStack_88;
  Vector aVStack_84 [12];
  AEMath aAStack_78 [12];
  undefined4 local_6c;
  undefined4 uStack_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  int local_54;
  
  local_54 = __stack_chk_guard;
  puVar2 = (uint *)Level::getEnemies((Level *)param_4);
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) - (int)param_2;
  if (puVar2 != (uint *)0x0) {
    pPVar3 = (PlayerEgo *)Level::getPlayer((Level *)param_4);
    iVar4 = PlayerEgo::isDead(pPVar3);
    if (iVar4 == 0) {
      pSVar5 = (Ship *)Status::getShip(Globals::status);
      pIVar6 = (Item *)Ship::getFirstEquipmentOfSort(pSVar5,*(int *)(param_1 + 0x1c));
      uVar7 = Item::getAttribute(pIVar6,0x35);
      uVar16 = *(uint *)(param_1 + 0x20);
      if (0x7fffffff < uVar16) {
        puVar14 = *(uint **)(param_1 + 0x14);
        if (*puVar14 != 0) {
          uVar16 = puVar14[1];
          uVar18 = 0;
          puVar10 = *(undefined4 **)(*(int *)(param_1 + 0x18) + 4);
          do {
            *(undefined4 *)(uVar16 + uVar18 * 4) = 0xffffffff;
            uVar18 = uVar18 + 1;
            *puVar10 = 0;
            puVar10 = puVar10 + 1;
          } while (uVar18 < *puVar14);
          uVar16 = *(uint *)(param_1 + 0x20);
        }
        *(uint *)(param_1 + 0x20) = uVar16 + 0x9c4;
        if (*puVar2 != 0) {
          pVVar20 = (Vector *)(param_1 + 4);
          uVar16 = 0;
          fVar22 = (float)VectorSignedToFloat(uVar7,(byte)(in_fpscr >> 0x16) & 3);
          do {
            this = *(KIPlayer **)(puVar2[1] + uVar16 * 4);
            iVar4 = KIPlayer::isDead(this);
            if ((iVar4 == 0) && (iVar4 = KIPlayer::isDying(this), iVar4 == 0)) {
              uVar18 = *(uint *)(param_1 + 0x1c);
              if (uVar18 == 0x25) {
                pPVar8 = *(Player **)(this + 4);
                if (pPVar8[0x5d] != (Player)0x0) {
                  iVar4 = Player::getHitpoints(pPVar8);
                  iVar9 = Player::getMaxHitpoints(*(Player **)(this + 4));
                  if (iVar9 <= iVar4) {
                    uVar18 = *(uint *)(param_1 + 0x1c);
                    goto LAB_000b42e4;
                  }
LAB_000b4322:
                  Player::getPosition();
                  AbyssEngine::AEMath::Vector::operator=(pVVar20,(Vector *)&local_60);
                  Level::getPlayer((Level *)param_4);
                  PlayerEgo::getPosition();
                  AbyssEngine::AEMath::Vector::operator-=(pVVar20,(Vector *)&local_60);
                  fVar11 = (float)AbyssEngine::AEMath::VectorLength(pVVar20);
                  in_fpscr = in_fpscr & 0xfffffff | (uint)(fVar11 == fVar22) << 0x1e |
                             (uint)(fVar22 <= fVar11) << 0x1d;
                  bVar1 = (byte)(in_fpscr >> 0x18);
                  if (!(bool)(bVar1 >> 5 & 1) || (bool)(bVar1 >> 6)) {
                    uVar18 = **(uint **)(param_1 + 0x14);
                    if (uVar18 != 0) {
                      uVar15 = (*(uint **)(param_1 + 0x14))[1];
                      uVar17 = 0;
                      do {
                        if (*(int *)(uVar15 + uVar17 * 4) == -1) {
                          *(uint *)(uVar15 + uVar17 * 4) = uVar16;
                          goto LAB_000b43f8;
                        }
                        uVar17 = uVar17 + 1;
                      } while (uVar17 < uVar18);
                    }
                    iVar4 = Player::getHitpoints(*(Player **)(this + 4));
                    puVar14 = *(uint **)(param_1 + 0x14);
                    if (*puVar14 != 0) {
                      uVar18 = 0xffffffff;
                      iVar9 = 9999999;
                      uVar15 = 0;
                      do {
                        iVar12 = *(int *)(puVar14[1] + uVar15 * 4);
                        if (iVar12 != -1) {
                          iVar12 = Player::getHitpoints
                                             (*(Player **)(*(int *)(puVar2[1] + iVar12 * 4) + 4));
                          puVar14 = *(uint **)(param_1 + 0x14);
                          if (iVar12 < iVar9 && iVar4 < iVar12) {
                            uVar18 = uVar15;
                            iVar9 = iVar12;
                          }
                        }
                        uVar15 = uVar15 + 1;
                      } while (uVar15 < *puVar14);
                      if (uVar18 != 0xffffffff) {
                        *(uint *)(puVar14[1] + uVar18 * 4) = uVar16;
                      }
                    }
                  }
                }
              }
              else {
LAB_000b42e4:
                bVar21 = uVar18 == 0x29;
                if (bVar21) {
                  uVar18 = (uint)(byte)this[0x70];
                }
                if ((bVar21 && uVar18 == 0) && (*(char *)(*(int *)(this + 4) + 0x5c) != '\0')) {
                  puVar10 = (undefined4 *)Level::getPlayer((Level *)param_4);
                  iVar4 = Player::getShieldDamageRate((Player *)*puVar10);
                  if (iVar4 < 100) {
                    pSVar5 = (Ship *)Status::getShip(Globals::status);
                    iVar4 = Ship::getFirstEquipmentOfSort(pSVar5,9);
                    if (iVar4 != 0) goto LAB_000b4322;
                  }
                }
              }
            }
LAB_000b43f8:
            uVar16 = uVar16 + 1;
          } while (uVar16 < *puVar2);
        }
      }
      puVar14 = *(uint **)(param_1 + 0x14);
      if (*puVar14 != 0) {
        pVVar20 = (Vector *)(param_1 + 4);
        fVar22 = (float)VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
        bVar21 = true;
        uVar16 = 0;
        do {
          if (*(int *)(puVar14[1] + uVar16 * 4) != -1) {
            uVar18 = AbyssEngine::PaintCanvas::TransformGetTransform
                               (Globals::Canvas,
                                *(uint *)(*(int *)(*(int *)(*(int *)(param_1 + 0x10) + 4) +
                                                  uVar16 * 4) + 0xc));
            AbyssEngine::Transform::Update((ulonglong)uVar18,SUB41(param_2,0));
            Player::getPosition();
            AbyssEngine::AEMath::Vector::operator=(pVVar20,(Vector *)&local_60);
            iVar4 = *(int *)(*(int *)(puVar2[1] +
                                     *(int *)(*(int *)(*(int *)(param_1 + 0x14) + 4) + uVar16 * 4) *
                                     4) + 0x78);
            if (iVar4 == 0x2c) {
              AEGeometry::getDirection();
              fVar11 = (float)AbyssEngine::AEMath::VectorNormalize
                                        ((AEMath *)&local_6c,(Vector *)aAStack_78);
              AbyssEngine::AEMath::operator*((AEMath *)&local_60,(Vector *)&local_6c,fVar11);
            }
            else if (iVar4 == 0x31) {
              AEGeometry::getDirection();
              fVar11 = (float)AbyssEngine::AEMath::VectorNormalize(aAStack_78,aVStack_84);
              AbyssEngine::AEMath::operator*((AEMath *)&local_6c,(Vector *)aAStack_78,fVar11);
              AEGeometry::getUpVector();
              fVar11 = (float)AbyssEngine::AEMath::VectorNormalize(aAStack_9c,aVStack_a8);
              AbyssEngine::AEMath::operator*((AEMath *)&local_90,(Vector *)aAStack_9c,fVar11);
              AbyssEngine::AEMath::operator+
                        ((AEMath *)&local_60,(Vector *)&local_6c,(Vector *)&local_90);
            }
            else {
              local_60 = 0;
              uStack_5c = 0;
              local_58 = 0;
            }
            AbyssEngine::AEMath::Vector::operator+=(pVVar20,(Vector *)&local_60);
            Level::getPlayer((Level *)param_4);
            PlayerEgo::getPosition();
            AbyssEngine::AEMath::Vector::operator-=(pVVar20,(Vector *)&local_6c);
            pSVar5 = (Ship *)Status::getShip(Globals::status);
            iVar4 = Ship::getIndex(pSVar5);
            if (iVar4 == 0x2c) {
              Level::getPlayer((Level *)param_4);
              fVar11 = (float)PlayerEgo::GetDirVector();
              AbyssEngine::AEMath::operator*((AEMath *)&local_6c,(Vector *)aAStack_78,fVar11);
            }
            else {
              pSVar5 = (Ship *)Status::getShip(Globals::status);
              iVar4 = Ship::getIndex(pSVar5);
              if (iVar4 == 0x31) {
                Level::getPlayer((Level *)param_4);
                fVar11 = (float)PlayerEgo::GetDirVector();
                AbyssEngine::AEMath::operator*(aAStack_78,aVStack_84,fVar11);
                Level::getPlayer((Level *)param_4);
                fVar11 = (float)PlayerEgo::GetUpVector();
                AbyssEngine::AEMath::operator*((AEMath *)&local_90,(Vector *)aAStack_9c,fVar11);
                AbyssEngine::AEMath::operator+
                          ((AEMath *)&local_6c,(Vector *)aAStack_78,(Vector *)&local_90);
              }
              else {
                local_6c = 0;
                uStack_68 = 0;
                local_64 = 0;
              }
            }
            AbyssEngine::AEMath::VectorLength(pVVar20);
            AEGeometry::setScaling
                      (*(AEGeometry **)(*(int *)(*(int *)(param_1 + 0x10) + 4) + uVar16 * 4),
                       extraout_s0,extraout_s1,extraout_s2);
            this_00 = *(AEGeometry **)(*(int *)(*(int *)(param_1 + 0x10) + 4) + uVar16 * 4);
            AbyssEngine::AEMath::operator-((AEMath *)aVStack_84,pVVar20,(Vector *)&local_6c);
            AbyssEngine::AEMath::VectorNormalize(aAStack_78,aVStack_84);
            local_90 = 0;
            local_8c = 0x3f800000;
            uStack_88 = 0;
            AEGeometry::setDirection(this_00,(Vector *)aAStack_78,(Vector *)&local_90);
            pVVar19 = *(Vector **)(*(int *)(*(int *)(param_1 + 0x10) + 4) + uVar16 * 4);
            Level::getPlayer((Level *)param_4);
            PlayerEgo::getPosition();
            AbyssEngine::AEMath::operator+(aAStack_78,aVStack_84,(Vector *)&local_6c);
            AEGeometry::setPosition(pVVar19);
            uVar18 = AbyssEngine::PaintCanvas::TransformGetTransform
                               (Globals::Canvas,
                                *(uint *)(*(int *)(*(int *)(*(int *)(param_1 + 0x10) + 4) +
                                                  uVar16 * 4) + 0xc));
            AbyssEngine::Transform::Update((ulonglong)uVar18,SUB41(param_2,0));
            if (*(int *)(param_1 + 0x1c) == 0x29) {
              puVar10 = (undefined4 *)Level::getPlayer((Level *)param_4);
              iVar4 = Player::getShieldDamageRate((Player *)*puVar10);
              if (iVar4 < 100) {
                pSVar5 = (Ship *)Status::getShip(Globals::status);
                pIVar6 = (Item *)Ship::getFirstEquipmentOfSort(pSVar5,*(int *)(param_1 + 0x1c));
                uVar7 = Item::getAttribute(pIVar6,0x36);
                fVar11 = (float)VectorSignedToFloat(uVar7,(byte)(in_fpscr >> 0x16) & 3);
                pfVar13 = (float *)(*(int *)(*(int *)(param_1 + 0x18) + 4) + uVar16 * 4);
                fVar11 = *pfVar13 + (fVar22 * 0.01 * fVar11) / 100.0;
                uVar18 = in_fpscr & 0xfffffff | (uint)(fVar11 < 1.0) << 0x1f;
                in_fpscr = uVar18 | (uint)NAN(fVar11) << 0x1c;
                *pfVar13 = fVar11;
                if ((byte)(uVar18 >> 0x1f) == ((byte)(in_fpscr >> 0x1c) & 1)) {
                  Player::damage(*(Player **)
                                  (*(int *)(puVar2[1] +
                                           *(int *)(*(int *)(*(int *)(param_1 + 0x14) + 4) +
                                                   uVar16 * 4) * 4) + 4),1,false,-1);
                  pfVar13 = (float *)(*(int *)(*(int *)(param_1 + 0x18) + 4) + uVar16 * 4);
                  *pfVar13 = *pfVar13 + -1.0;
                }
                puVar10 = (undefined4 *)Level::getPlayer((Level *)param_4);
                pPVar8 = (Player *)*puVar10;
                pSVar5 = (Ship *)Status::getShip(Globals::status);
                pIVar6 = (Item *)Ship::getFirstEquipmentOfSort(pSVar5,*(int *)(param_1 + 0x1c));
                uVar7 = Item::getAttribute(pIVar6,0x36);
                fVar11 = (float)VectorSignedToFloat(uVar7,(byte)(in_fpscr >> 0x16) & 3);
                Player::regenerateShield(pPVar8,(fVar22 * 0.01 * fVar11) / 100.0);
              }
            }
            else if (*(int *)(param_1 + 0x1c) == 0x25) {
              pPVar8 = *(Player **)
                        (*(int *)(puVar2[1] +
                                 *(int *)(*(int *)(*(int *)(param_1 + 0x14) + 4) + uVar16 * 4) * 4)
                        + 4);
              pSVar5 = (Ship *)Status::getShip(Globals::status);
              pIVar6 = (Item *)Ship::getFirstEquipmentOfSort(pSVar5,*(int *)(param_1 + 0x1c));
              uVar7 = Item::getAttribute(pIVar6,0x36);
              fVar11 = (float)VectorSignedToFloat(uVar7,(byte)(in_fpscr >> 0x16) & 3);
              Player::heal(pPVar8,(fVar22 * 0.03 * fVar11) / 100.0);
            }
            iVar4 = FModSound::isPlaying
                              (Globals::sound,*(int *)(&DAT_00252750 + *(int *)param_1 * 4));
            if (iVar4 == 0) {
              FModSound::play(Globals::sound,*(int *)(&DAT_00252750 + *(int *)param_1 * 4),
                              (Vector *)0x0,(Vector *)0x0,extraout_s0_00);
            }
            puVar14 = *(uint **)(param_1 + 0x14);
            bVar21 = false;
          }
          uVar16 = uVar16 + 1;
        } while (uVar16 < *puVar14);
        if (!bVar21) goto LAB_000b48b6;
      }
      FModSound::stop(Globals::sound,*(int *)(&DAT_00252750 + *(int *)param_1 * 4));
    }
  }
LAB_000b48b6:
  pPVar3 = (PlayerEgo *)Level::getPlayer((Level *)param_4);
  iVar4 = PlayerEgo::isDead(pPVar3);
  if ((iVar4 == 1) &&
     (iVar4 = FModSound::isPlaying(Globals::sound,*(int *)(&DAT_00252750 + *(int *)param_1 * 4)),
     iVar4 == 1)) {
    FModSound::stop(Globals::sound,*(int *)(&DAT_00252750 + *(int *)param_1 * 4));
  }
  if ((Globals::options[0xf] != '\0') &&
     (iVar4 = FModSound::isPlaying(Globals::sound,*(int *)(&DAT_00252750 + *(int *)param_1 * 4)),
     iVar4 == 1)) {
    iVar4 = *(int *)param_1;
    Level::getPlayer((Level *)param_4);
    PlayerEgo::getPosition();
    AbyssEngine::AEMath::Vector::operator=((Vector *)(param_1 + 4),(Vector *)&local_60);
    FModSound::updateEvent3DAttributes
              (Globals::sound,*(int *)(&DAT_00252750 + iVar4 * 4),(Vector *)(param_1 + 4),
               (Vector *)0x0,false);
  }
  if (__stack_chk_guard != local_54) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== RepairBeam::render  @0x000b49dc  (50 bytes)
/* RepairBeam::render() */

void __thiscall RepairBeam::render(RepairBeam *this)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = *(uint **)(this + 0x14);
  if (*puVar1 != 0) {
    uVar2 = 0;
    do {
      if (*(int *)(puVar1[1] + uVar2 * 4) != -1) {
        AEGeometry::render(*(AEGeometry **)(*(int *)(*(int *)(this + 0x10) + 4) + uVar2 * 4));
        puVar1 = *(uint **)(this + 0x14);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *puVar1);
  }
  return;
}

