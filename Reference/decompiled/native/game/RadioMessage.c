// Class: RadioMessage
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== RadioMessage::RadioMessage  @0x0017c4d0  (52 bytes)
/* RadioMessage::RadioMessage(int, int, int, int) */

RadioMessage * __thiscall
RadioMessage::RadioMessage(RadioMessage *this,int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(int *)(this + 8) = param_1;
  *(int *)(this + 0xc) = param_2;
  *(int *)(this + 0x10) = param_3;
  *(int *)(this + 0x14) = param_4;
  piVar1 = operator_new__(4);
  *(int **)(this + 0x1c) = piVar1;
  *piVar1 = param_4;
  *(undefined4 *)(this + 0x18) = 1;
  this[0x20] = (RadioMessage)0x0;
  this[0x21] = (RadioMessage)0x0;
  *(undefined4 *)(this + 0x24) = 0;
  return this;
}

// ===== RadioMessage::reset  @0x0017c504  (14 bytes)
/* RadioMessage::reset() */

void __thiscall RadioMessage::reset(RadioMessage *this)

{
  this[0x20] = (RadioMessage)0x0;
  this[0x21] = (RadioMessage)0x0;
  *(undefined4 *)(this + 0x24) = 0;
  return;
}

// ===== RadioMessage::RadioMessage  @0x0017c512  (98 bytes)
/* RadioMessage::RadioMessage(int, int, int, int, int) */

RadioMessage * __thiscall
RadioMessage::RadioMessage
          (RadioMessage *this,int param_1,int param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  uVar1 = (uint)((ulonglong)(uint)param_5 * 4);
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(int *)(this + 8) = param_1;
  *(int *)(this + 0xc) = param_2;
  *(int *)(this + 0x10) = param_3;
  *(int *)(this + 0x14) = param_4;
  if ((int)((ulonglong)(uint)param_5 * 4 >> 0x20) != 0) {
    uVar1 = 0xffffffff;
  }
  piVar2 = operator_new__(uVar1);
  *(int **)(this + 0x1c) = piVar2;
  iVar3 = param_5;
  if (0 < param_5) {
    do {
      *piVar2 = param_4;
      param_4 = param_4 + 1;
      iVar3 = iVar3 + -1;
      piVar2 = piVar2 + 1;
    } while (iVar3 != 0);
  }
  *(int *)(this + 0x18) = param_5;
  this[0x20] = (RadioMessage)0x0;
  this[0x21] = (RadioMessage)0x0;
  *(undefined4 *)(this + 0x24) = 0;
  return this;
}

// ===== RadioMessage::RadioMessage  @0x0017c574  (34 bytes)
/* RadioMessage::RadioMessage(int, int, Objective*) */

void __thiscall
RadioMessage::RadioMessage(RadioMessage *this,int param_1,int param_2,Objective *param_3)

{
  *(undefined4 *)(this + 0x1c) = 0;
  *(int *)(this + 8) = param_1;
  *(int *)(this + 0xc) = param_2;
  *(undefined4 *)this = 0;
  *(Objective **)(this + 4) = param_3;
  *(undefined4 *)(this + 0x10) = 0xb;
  this[0x20] = (RadioMessage)0x0;
  this[0x21] = (RadioMessage)0x0;
  *(undefined4 *)(this + 0x24) = 0;
  return;
}

// ===== RadioMessage::~RadioMessage  @0x0017c596  (22 bytes)
/* RadioMessage::~RadioMessage() */

RadioMessage * __thiscall RadioMessage::~RadioMessage(RadioMessage *this)

{
  if (*(void **)(this + 0x1c) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x1c));
  }
  *(undefined4 *)(this + 0x1c) = 0;
  return this;
}

// ===== RadioMessage::getSoundID  @0x0017c5ac  (4 bytes)
/* RadioMessage::getSoundID() */

undefined4 RadioMessage::getSoundID(void)

{
  return 0;
}

// ===== RadioMessage::getTextID  @0x0017c5b0  (4 bytes)
/* RadioMessage::getTextID() */

undefined4 __thiscall RadioMessage::getTextID(RadioMessage *this)

{
  return *(undefined4 *)(this + 8);
}

// ===== RadioMessage::getImageID  @0x0017c5b4  (4 bytes)
/* RadioMessage::getImageID() */

undefined4 __thiscall RadioMessage::getImageID(RadioMessage *this)

{
  return *(undefined4 *)(this + 0xc);
}

// ===== RadioMessage::setRadio  @0x0017c5b8  (4 bytes)
/* RadioMessage::setRadio(Radio*) */

void __thiscall RadioMessage::setRadio(RadioMessage *this,Radio *param_1)

{
  *(Radio **)this = param_1;
  return;
}

// ===== RadioMessage::isTriggered  @0x0017c5bc  (6 bytes)
/* RadioMessage::isTriggered() */

RadioMessage __thiscall RadioMessage::isTriggered(RadioMessage *this)

{
  return this[0x20];
}

// ===== RadioMessage::isOver  @0x0017c5c2  (6 bytes)
/* RadioMessage::isOver() */

RadioMessage __thiscall RadioMessage::isOver(RadioMessage *this)

{
  return this[0x21];
}

// ===== RadioMessage::finish  @0x0017c5c8  (8 bytes)
/* RadioMessage::finish() */

void __thiscall RadioMessage::finish(RadioMessage *this)

{
  this[0x21] = (RadioMessage)0x1;
  return;
}

// ===== RadioMessage::trigger  @0x0017c5d0  (8 bytes)
/* RadioMessage::trigger() */

void __thiscall RadioMessage::trigger(RadioMessage *this)

{
  this[0x20] = (RadioMessage)0x1;
  return;
}

// ===== RadioMessage::triggered  @0x0017c5d8  (1782 bytes)
/* RadioMessage::triggered(long long, PlayerEgo*, LevelScript*) */

void RadioMessage::triggered(longlong param_1,PlayerEgo *param_2,LevelScript *param_3)

{
  int iVar1;
  byte bVar2;
  RadioMessage *pRVar3;
  PlayerEgo *pPVar4;
  Route *pRVar5;
  undefined4 uVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  Player *pPVar11;
  uint uVar12;
  int iVar13;
  RadioMessage RVar14;
  uint in_fpscr;
  uint uVar15;
  float fVar16;
  PlayerEgo *in_stack_00000000;
  LevelScript *in_stack_00000004;
  float local_40;
  float local_34;
  float local_28;
  
  iVar1 = __stack_chk_guard;
  pRVar3 = (RadioMessage *)param_1;
  if (pRVar3[0x20] != (RadioMessage)0x0) goto LAB_0017c9d0;
  switch(*(undefined4 *)(pRVar3 + 0x10)) {
  case 0:
    iVar8 = PlayerEgo::getRoute(in_stack_00000000);
    if (iVar8 == 0) break;
    pRVar5 = (Route *)PlayerEgo::getRoute(in_stack_00000000);
    iVar8 = Route::getCurrent(pRVar5);
    RVar14 = (RadioMessage)0x0;
    if ((*(int *)(pRVar3 + 0x24) < iVar8) && (*(int *)(pRVar3 + 0x24) == *(int *)(pRVar3 + 0x14))) {
      RVar14 = (RadioMessage)0x1;
    }
    pRVar5 = (Route *)PlayerEgo::getRoute(in_stack_00000000);
    uVar6 = Route::getCurrent(pRVar5);
    *(undefined4 *)(pRVar3 + 0x24) = uVar6;
    pRVar3[0x20] = RVar14;
    goto joined_r0x0017cc92;
  case 1:
    iVar8 = Player::getEnemies(*(Player **)in_stack_00000000);
    if (0 < *(int *)(pRVar3 + 0x18)) {
      iVar13 = 0;
      do {
        iVar9 = Player::isDead(*(Player **)
                                (*(int *)(iVar8 + 4) +
                                *(int *)(*(int *)(pRVar3 + 0x1c) + iVar13 * 4) * 4));
        if (iVar9 != 0) goto LAB_0017cbd4;
        iVar13 = iVar13 + 1;
      } while (iVar13 < *(int *)(pRVar3 + 0x18));
    }
    break;
  case 2:
    iVar8 = Player::getEnemies(*(Player **)in_stack_00000000);
    iVar13 = *(int *)(pRVar3 + 0x18);
    if (0 < iVar13) {
      iVar9 = 0;
      do {
        pPVar11 = *(Player **)
                   (*(int *)(iVar8 + 4) + *(int *)(*(int *)(pRVar3 + 0x1c) + iVar9 * 4) * 4);
        if (pPVar11[0x5d] != (Player)0x0) {
          iVar13 = Player::isDead(pPVar11);
          if (iVar13 != 0) goto LAB_0017cbd4;
          iVar13 = *(int *)(pRVar3 + 0x18);
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar13);
    }
    break;
  case 3:
    iVar8 = Level::getEnemiesLeft(*(Level **)(in_stack_00000000 + 0xc));
    goto LAB_0017cc36;
  case 4:
    iVar8 = Level::getFriendsLeft(*(Level **)(in_stack_00000000 + 0xc));
    goto LAB_0017cc36;
  case 5:
    pPVar4 = *(PlayerEgo **)(pRVar3 + 0x14);
    iVar8 = (int)pPVar4 >> 0x1f;
    RVar14 = (RadioMessage)
             ((int)(param_3 + (-(uint)(param_2 < pPVar4) - iVar8)) < 0 ==
             (SBORROW4((int)param_3,iVar8) !=
             SBORROW4((int)param_3 - iVar8,(uint)(param_2 < pPVar4))));
    pRVar3[0x20] = RVar14;
    goto joined_r0x0017cc92;
  case 6:
    iVar8 = Radio::getMessage(*(Radio **)pRVar3,*(int *)(pRVar3 + 0x14));
    goto LAB_0017c9c0;
  case 8:
    iVar8 = Player::getEnemies(*(Player **)in_stack_00000000);
    if (0 < *(int *)(pRVar3 + 0x18)) {
      iVar13 = 0;
      do {
        iVar9 = Player::isAsteroid(*(Player **)
                                    (*(int *)(iVar8 + 4) +
                                    *(int *)(*(int *)(pRVar3 + 0x1c) + iVar13 * 4) * 4));
        if ((iVar9 == 0) &&
           (iVar9 = Player::isActive(*(Player **)
                                      (*(int *)(iVar8 + 4) +
                                      *(int *)(*(int *)(pRVar3 + 0x1c) + iVar13 * 4) * 4)),
           iVar9 != 0)) goto LAB_0017cbd4;
        iVar13 = iVar13 + 1;
      } while (iVar13 < *(int *)(pRVar3 + 0x18));
    }
    break;
  case 9:
    iVar8 = Player::getEnemies(*(Player **)in_stack_00000000);
    if (0 < *(int *)(pRVar3 + 0x18)) {
      iVar13 = 0;
      do {
        iVar9 = Player::isDead(*(Player **)
                                (*(int *)(iVar8 + 4) +
                                *(int *)(*(int *)(pRVar3 + 0x1c) + iVar13 * 4) * 4));
        if (iVar9 == 0) goto switchD_0017c60a_caseD_7;
        iVar13 = iVar13 + 1;
      } while (iVar13 < *(int *)(pRVar3 + 0x18));
    }
    goto LAB_0017cbd4;
  case 10:
    iVar8 = Player::getEnemies(*(Player **)in_stack_00000000);
    if (0 < *(int *)(pRVar3 + 0x18)) {
      iVar13 = 0;
      do {
        iVar9 = Player::isAsteroid(*(Player **)
                                    (*(int *)(iVar8 + 4) +
                                    *(int *)(*(int *)(pRVar3 + 0x1c) + iVar13 * 4) * 4));
        if (((iVar9 == 0) &&
            (pPVar11 = *(Player **)
                        (*(int *)(iVar8 + 4) + *(int *)(*(int *)(pRVar3 + 0x1c) + iVar13 * 4) * 4),
            pPVar11[0x5d] != (Player)0x0)) && (iVar9 = Player::isActive(pPVar11), iVar9 != 0))
        goto LAB_0017cbd4;
        iVar13 = iVar13 + 1;
      } while (iVar13 < *(int *)(pRVar3 + 0x18));
    }
    break;
  case 0xb:
    uVar12 = Objective::achieved(*(Objective **)(pRVar3 + 4),(int)param_2);
    goto LAB_0017c9c4;
  case 0xc:
    iVar8 = Player::getEnemies(*(Player **)in_stack_00000000);
    if (0 < *(int *)(pRVar3 + 0x18)) {
      iVar13 = 0;
      do {
        iVar9 = Player::getHitpoints
                          (*(Player **)
                            (*(int *)(iVar8 + 4) +
                            *(int *)(*(int *)(pRVar3 + 0x1c) + iVar13 * 4) * 4));
        iVar10 = Player::getMaxHitpoints
                           (*(Player **)
                             (*(int *)(iVar8 + 4) +
                             *(int *)(*(int *)(pRVar3 + 0x1c) + iVar13 * 4) * 4));
        if (iVar9 < iVar10 / 2) goto LAB_0017cbd4;
        iVar13 = iVar13 + 1;
      } while (iVar13 < *(int *)(pRVar3 + 0x18));
    }
    break;
  case 0xe:
    iVar8 = Player::getEnemies(*(Player **)in_stack_00000000);
    iVar8 = Player::getKIPlayer(*(Player **)(*(int *)(iVar8 + 4) + *(int *)(pRVar3 + 0x14) * 4));
    uVar12 = (uint)*(byte *)(iVar8 + 0x65);
    goto LAB_0017c9c4;
  case 0xf:
    puVar7 = (uint *)Player::getEnemies(*(Player **)in_stack_00000000);
    if (*puVar7 != 0) {
      uVar12 = 0;
      do {
        iVar8 = Player::isAsteroid(*(Player **)(puVar7[1] + uVar12 * 4));
        if ((iVar8 == 0) &&
           (iVar8 = Player::isDead(*(Player **)(puVar7[1] + uVar12 * 4)), iVar8 != 0))
        goto LAB_0017cbd4;
        uVar12 = uVar12 + 1;
      } while (uVar12 < *puVar7);
    }
    break;
  case 0x10:
    puVar7 = (uint *)Player::getEnemies(*(Player **)in_stack_00000000);
    if (*puVar7 != 0) {
      uVar12 = 0;
      do {
        iVar8 = Player::isAsteroid(*(Player **)(puVar7[1] + uVar12 * 4));
        if (((iVar8 == 0) &&
            (iVar8 = Player::isActive(*(Player **)(puVar7[1] + uVar12 * 4)), iVar8 == 1)) &&
           (iVar8 = Player::isAlwaysFriend(*(Player **)(puVar7[1] + uVar12 * 4)), iVar8 != 1))
        goto LAB_0017cbd4;
        uVar12 = uVar12 + 1;
      } while (uVar12 < *puVar7);
    }
    break;
  case 0x11:
    puVar7 = (uint *)Player::getEnemies(*(Player **)in_stack_00000000);
    if (*puVar7 != 0) {
      uVar12 = 0;
      do {
        if (((uVar12 != *(uint *)(pRVar3 + 0x14)) &&
            (iVar8 = Player::isAsteroid(*(Player **)(puVar7[1] + uVar12 * 4)), iVar8 == 0)) &&
           (iVar8 = Player::isDead(*(Player **)(puVar7[1] + uVar12 * 4)), iVar8 != 0)) break;
        uVar12 = uVar12 + 1;
      } while (uVar12 < *puVar7);
    }
    goto LAB_0017cbd4;
  case 0x12:
    iVar8 = Player::getEnemies(*(Player **)in_stack_00000000);
    iVar8 = Player::getKIPlayer(*(Player **)(*(int *)(iVar8 + 4) + *(int *)(pRVar3 + 0x14) * 4));
    if (*(char *)(iVar8 + 0x65) == '\0') {
      iVar8 = Player::getEnemies(*(Player **)in_stack_00000000);
      iVar8 = Player::getKIPlayer(*(Player **)(*(int *)(iVar8 + 4) + *(int *)(pRVar3 + 0x14) * 4));
      uVar12 = (uint)*(byte *)(iVar8 + 0x66);
      goto LAB_0017c9c4;
    }
LAB_0017cbd4:
    pRVar3[0x20] = (RadioMessage)0x1;
    goto LAB_0017cbda;
  case 0x13:
    iVar8 = Player::getEnemies(*(Player **)in_stack_00000000);
    if (0 < *(int *)(pRVar3 + 0x18)) {
      iVar13 = 0;
      do {
        iVar9 = Player::getHitpoints
                          (*(Player **)
                            (*(int *)(iVar8 + 4) +
                            *(int *)(*(int *)(pRVar3 + 0x1c) + iVar13 * 4) * 4));
        iVar10 = Player::getMaxHitpoints
                           (*(Player **)
                             (*(int *)(iVar8 + 4) +
                             *(int *)(*(int *)(pRVar3 + 0x1c) + iVar13 * 4) * 4));
        if (iVar9 < (int)(iVar10 + ((uint)(iVar10 >> 0x1f) >> 0x1e)) >> 2) goto LAB_0017cbd4;
        iVar13 = iVar13 + 1;
      } while (iVar13 < *(int *)(pRVar3 + 0x18));
    }
    break;
  case 0x14:
    puVar7 = (uint *)Player::getEnemies(*(Player **)in_stack_00000000);
    if (*puVar7 != 0) {
      uVar12 = 0;
      iVar8 = 0;
      do {
        iVar13 = Player::isAsteroid(*(Player **)(puVar7[1] + uVar12 * 4));
        if ((iVar13 == 0) &&
           (iVar13 = Player::isDead(*(Player **)(puVar7[1] + uVar12 * 4)), iVar13 != 0)) {
          iVar8 = iVar8 + 1;
        }
        if (*(int *)(pRVar3 + 0x14) <= iVar8) goto LAB_0017cbd4;
        uVar12 = uVar12 + 1;
      } while (uVar12 < *puVar7);
    }
    break;
  case 0x15:
    iVar8 = Player::getEnemies(*(Player **)in_stack_00000000);
    iVar8 = Player::getKIPlayer(*(Player **)(*(int *)(iVar8 + 4) + *(int *)(pRVar3 + 0x14) * 4));
LAB_0017c9c0:
    uVar12 = (uint)*(byte *)(iVar8 + 0x20);
    goto LAB_0017c9c4;
  case 0x16:
    iVar8 = *(int *)(*(int *)(in_stack_00000000 + 0xc) + 0x1c);
    pRVar3[0x20] = (RadioMessage)(*(int *)(pRVar3 + 0x14) <= iVar8);
    if (iVar8 < *(int *)(pRVar3 + 0x14)) goto LAB_0017c9d0;
    goto LAB_0017cbda;
  case 0x17:
    uVar12 = Radar::stationLocked(*(Radar **)(in_stack_00000000 + 0x14));
LAB_0017c9c4:
    pRVar3[0x20] = SUB41(uVar12,0);
    if (uVar12 == 0) goto LAB_0017c9d0;
    goto LAB_0017cbda;
  case 0x18:
    iVar8 = Player::getEnemies(*(Player **)in_stack_00000000);
    iVar8 = Player::isActive(*(Player **)(*(int *)(iVar8 + 4) + *(int *)(pRVar3 + 0x14) * 4));
    if (iVar8 != 0) break;
    iVar8 = Player::getEnemies(*(Player **)in_stack_00000000);
    bVar2 = Player::isDead(*(Player **)(*(int *)(iVar8 + 4) + *(int *)(pRVar3 + 0x14) * 4));
    RVar14 = (RadioMessage)
             ((bVar2 ^ 1) &
             (int)(-(uint)((PlayerEgo *)0xea5f < param_2) - (int)param_3) < 0 !=
             (SBORROW4(0,(int)param_3) !=
             SBORROW4(-(int)param_3,(uint)((PlayerEgo *)0xea5f < param_2))));
LAB_0017c8f4:
    pRVar3[0x20] = RVar14;
    if (RVar14 == (RadioMessage)0x0) goto LAB_0017c9d0;
    goto LAB_0017cbda;
  case 0x19:
    iVar8 = PlayerEgo::getRoute(in_stack_00000000);
    if (iVar8 != 0) {
      pRVar5 = (Route *)PlayerEgo::getRoute(in_stack_00000000);
      iVar8 = Route::getCurrent(pRVar5);
      iVar13 = *(int *)(pRVar3 + 0x24);
      pRVar5 = (Route *)PlayerEgo::getRoute(in_stack_00000000);
      uVar6 = Route::getCurrent(pRVar5);
      *(undefined4 *)(pRVar3 + 0x24) = uVar6;
      puVar7 = (uint *)Player::getEnemies(*(Player **)in_stack_00000000);
      iVar9 = 0;
      if (*puVar7 != 0) {
        uVar12 = 0;
        iVar9 = 0;
        do {
          iVar10 = Player::isAsteroid(*(Player **)(puVar7[1] + uVar12 * 4));
          if ((iVar10 == 0) &&
             (iVar10 = Player::isDead(*(Player **)(puVar7[1] + uVar12 * 4)), iVar10 == 0)) {
            iVar9 = iVar9 + 1;
          }
          uVar12 = uVar12 + 1;
        } while (uVar12 < *puVar7);
      }
      RVar14 = (RadioMessage)(*(int *)(pRVar3 + 0x14) <= iVar9 && (iVar13 < iVar8 && iVar13 == 0));
      goto LAB_0017c8f4;
    }
    break;
  case 0x1a:
    iVar8 = Player::getEnemies(*(Player **)in_stack_00000000);
    pPVar11 = (Player *)**(undefined4 **)(iVar8 + 4);
    iVar8 = Player::isActive(pPVar11);
    if ((iVar8 != 1) || (iVar8 = Player::isDead(pPVar11), iVar8 != 0)) break;
    Player::getPosition();
    fVar16 = (float)VectorSignedToFloat(*(undefined4 *)(pRVar3 + 0x14),(byte)(in_fpscr >> 0x16) & 3)
    ;
    fVar16 = local_28 - fVar16;
    uVar12 = in_fpscr & 0xfffffff | (uint)(fVar16 < 0.0) << 0x1f | (uint)(fVar16 == 0.0) << 0x1e;
    uVar15 = uVar12 | (uint)NAN(fVar16) << 0x1c;
    bVar2 = (byte)(uVar12 >> 0x18);
    if ((bool)(bVar2 >> 6 & 1) || bVar2 >> 7 != ((byte)(uVar15 >> 0x1c) & 1)) {
      Player::getPosition();
      fVar16 = (float)VectorSignedToFloat(*(undefined4 *)(pRVar3 + 0x14),(byte)(uVar15 >> 0x16) & 3)
      ;
      fVar16 = -(local_40 - fVar16);
    }
    else {
      Player::getPosition();
      fVar16 = (float)VectorSignedToFloat(*(undefined4 *)(pRVar3 + 0x14),(byte)(uVar15 >> 0x16) & 3)
      ;
      fVar16 = local_34 - fVar16;
    }
    iVar8 = (uint)(fVar16 < 5000.0) << 0x1f;
    pRVar3[0x20] = (RadioMessage)(iVar8 < 0);
    if (-1 < iVar8) goto LAB_0017c9d0;
    goto LAB_0017cbda;
  case 0x1b:
    iVar8 = LevelScript::getEvent(in_stack_00000004);
    RVar14 = (RadioMessage)(iVar8 == *(int *)(pRVar3 + 0x14));
    goto LAB_0017cc86;
  case 0x1c:
    iVar8 = Player::getArmorHP(*(Player **)in_stack_00000000);
LAB_0017cc36:
    pRVar3[0x20] = (RadioMessage)(iVar8 < 1);
    if (0 < iVar8) goto LAB_0017c9d0;
    goto LAB_0017cbda;
  case 0x1e:
    iVar8 = Player::getEnemies(*(Player **)in_stack_00000000);
    iVar9 = 0;
    iVar13 = 2;
    do {
      iVar10 = Player::isAsteroid(*(Player **)(*(int *)(iVar8 + 4) + iVar13 * 4));
      if ((iVar10 == 0) &&
         (iVar10 = Player::isDead(*(Player **)(*(int *)(iVar8 + 4) + iVar13 * 4)), iVar10 != 0)) {
        iVar9 = iVar9 + 1;
      }
      iVar13 = iVar13 + 1;
    } while (iVar13 != 6);
    RVar14 = (RadioMessage)(iVar9 == *(int *)(pRVar3 + 0x14));
LAB_0017cc86:
    pRVar3[0x20] = RVar14;
joined_r0x0017cc92:
    if (!(bool)RVar14) goto LAB_0017c9d0;
LAB_0017cbda:
    Radio::setCurrentMessage(*(Radio **)pRVar3,pRVar3);
    goto LAB_0017c9d0;
  case 0x1f:
    iVar8 = Player::getEnemies(*(Player **)in_stack_00000000);
    if (0 < *(int *)(pRVar3 + 0x18)) {
      iVar13 = 0;
      do {
        iVar9 = Player::getHitpoints
                          (*(Player **)
                            (*(int *)(iVar8 + 4) +
                            *(int *)(*(int *)(pRVar3 + 0x1c) + iVar13 * 4) * 4));
        iVar10 = Player::getMaxHitpoints
                           (*(Player **)
                             (*(int *)(iVar8 + 4) +
                             *(int *)(*(int *)(pRVar3 + 0x1c) + iVar13 * 4) * 4));
        if (iVar9 < ((int)(iVar10 + ((uint)(iVar10 >> 0x1f) >> 0x1e)) >> 2) * 3) goto LAB_0017cbd4;
        iVar13 = iVar13 + 1;
      } while (iVar13 < *(int *)(pRVar3 + 0x18));
    }
  }
switchD_0017c60a_caseD_7:
  pRVar3[0x20] = (RadioMessage)0x0;
LAB_0017c9d0:
  if (__stack_chk_guard - iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - iVar1);
  }
  return;
}

