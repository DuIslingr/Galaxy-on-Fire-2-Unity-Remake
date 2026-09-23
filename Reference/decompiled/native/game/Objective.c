// Class: Objective
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Objective::Objective  @0x000a3600  (18 bytes)
/* Objective::Objective(int, int, Level*) */

void __thiscall Objective::Objective(Objective *this,int param_1,int param_2,Level *param_3)

{
  *(int *)this = param_1;
  *(int *)(this + 4) = param_2;
  *(undefined4 *)(this + 8) = 0;
  *(Level **)(this + 0xc) = param_3;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  return;
}

// ===== Objective::Objective  @0x000a3612  (26 bytes)
/* Objective::Objective(int, int, int, Level*) */

void __thiscall
Objective::Objective(Objective *this,int param_1,int param_2,int param_3,Level *param_4)

{
  *(int *)this = param_1;
  *(int *)(this + 4) = param_2;
  *(int *)(this + 8) = param_3;
  *(Level **)(this + 0xc) = param_4;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  if (param_1 == 0xd) {
    *(int *)(this + 0x18) = param_3;
  }
  return;
}

// ===== Objective::~Objective  @0x000a362c  (54 bytes)
/* Objective::~Objective() */

Objective * __thiscall Objective::~Objective(Objective *this)

{
  void *pvVar1;
  
  if (*(Array **)(this + 0x10) != (Array *)0x0) {
    ArrayReleaseClasses<Objective*>(*(Array **)(this + 0x10));
    pvVar1 = *(void **)(this + 0x10);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x10) = 0;
  if (*(String **)(this + 0x14) != (String *)0x0) {
    pvVar1 = (void *)AbyssEngine::String::~String(*(String **)(this + 0x14));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x14) = 0;
  return this;
}

// ===== Objective::addObjective  @0x000a36a4  (74 bytes)
/* Objective::addObjective(Objective*) */

Objective * __thiscall Objective::addObjective(Objective *this,Objective *param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  int *piVar3;
  
  piVar3 = *(int **)(this + 0x10);
  if (piVar3 == (int *)0x0) {
    piVar3 = operator_new(0xc);
    puVar1 = operator_new__(4);
    piVar3[1] = (int)puVar1;
    piVar3[2] = 1;
    *puVar1 = 0;
    *piVar3 = 0;
    *(int **)(this + 0x10) = piVar3;
  }
  piVar3[2] = *piVar3 + 1;
  pvVar2 = realloc((void *)piVar3[1],(*piVar3 + 1) * 4);
  piVar3[1] = (int)pvVar2;
  *(Objective **)((int)pvVar2 + *piVar3 * 4) = param_1;
  *piVar3 = piVar3[2];
  return this;
}

// ===== Objective::achieved  @0x000a36fc  (916 bytes)
/* Objective::achieved(int) */

uint __thiscall Objective::achieved(Objective *this,int param_1)

{
  uint *puVar1;
  int iVar2;
  Route *this_00;
  int *piVar3;
  RadioMessage *this_01;
  int iVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  uint uVar8;
  bool bVar9;
  bool bVar10;
  
  puVar1 = (uint *)Level::getEnemies(*(Level **)(this + 0xc));
  iVar2 = *(int *)this;
  uVar8 = 0;
  switch(iVar2) {
  case 0:
    iVar2 = Level::getEnemiesLeft(*(Level **)(this + 0xc));
    goto LAB_000a3818;
  case 1:
    iVar2 = Level::getEnemies(*(Level **)(this + 0xc));
    uVar8 = KIPlayer::isDead(*(KIPlayer **)(*(int *)(iVar2 + 4) + *(int *)(this + 4) * 4));
    break;
  case 2:
    this_00 = (Route *)Level::getPlayerRoute(*(Level **)(this + 0xc));
    iVar2 = Route::getLastWaypoint(this_00);
    cVar7 = *(char *)(iVar2 + 300);
    goto LAB_000a39ec;
  case 3:
    bVar10 = SBORROW4(*(int *)(this + 4),param_1);
    bVar9 = *(int *)(this + 4) - param_1 < 0;
    goto LAB_000a3ac0;
  case 4:
    iVar2 = Level::getMessages(*(Level **)(this + 0xc));
    this_01 = *(RadioMessage **)(*(int *)(iVar2 + 4) + *(int *)(this + 4) * 4);
    goto LAB_000a39ce;
  case 5:
    iVar2 = Level::getFriendsLeft(*(Level **)(this + 0xc));
LAB_000a3818:
    uVar8 = (uint)(iVar2 == 0);
    break;
  case 7:
    iVar2 = *(int *)(this + 4);
    iVar4 = 0;
    if (0 < iVar2) {
      iVar5 = 0;
      iVar4 = 0;
      do {
        iVar2 = KIPlayer::isDead(*(KIPlayer **)(puVar1[1] + iVar5 * 4));
        if (iVar2 != 0) {
          iVar4 = iVar4 + 1;
        }
        iVar2 = *(int *)(this + 4);
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar2);
    }
    uVar8 = (uint)(iVar4 == iVar2);
    break;
  case 8:
    puVar1 = (uint *)Level::getAsteroids(*(Level **)(this + 0xc));
    iVar2 = 0;
    if (*puVar1 != 0) {
      uVar8 = 0;
      iVar2 = 0;
      do {
        iVar4 = KIPlayer::isDead(*(KIPlayer **)(puVar1[1] + uVar8 * 4));
        if (iVar4 != 0) {
          iVar2 = iVar2 + 1;
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < *puVar1);
    }
    uVar8 = (uint)(*(int *)(this + 4) < iVar2);
    break;
  case 9:
    puVar1 = (uint *)Level::getAsteroids(*(Level **)(this + 0xc));
    if (*puVar1 != 0) {
      iVar2 = *(int *)(this + 4);
      uVar8 = 0;
      do {
        if (iVar2 <= (int)uVar8) {
          bVar10 = SBORROW4(iVar2,1);
          bVar9 = iVar2 + -1 < 0;
          goto LAB_000a3ac0;
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < *puVar1);
    }
  case 10:
    puVar1 = (uint *)Level::getAsteroids(*(Level **)(this + 0xc));
    if (*puVar1 != 0) {
      uVar8 = 0;
      do {
        if (*(int *)(this + 4) <= (int)uVar8) {
          return 0;
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < *puVar1);
    }
  case 0xb:
    iVar2 = Level::getEnemies(*(Level **)(this + 0xc));
    cVar7 = *(char *)(*(int *)(*(int *)(iVar2 + 4) + *(int *)(this + 4) * 4) + 0x65);
    goto LAB_000a39ec;
  case 0xc:
    iVar2 = Level::getEnemies(*(Level **)(this + 0xc));
    cVar7 = *(char *)(*(int *)(*(int *)(iVar2 + 4) + *(int *)(this + 4) * 4) + 100);
    goto LAB_000a39ec;
  case 0xf:
    iVar2 = Level::getEnemies(*(Level **)(this + 0xc));
    uVar8 = Player::isActive(*(Player **)
                              (*(int *)(*(int *)(iVar2 + 4) + *(int *)(this + 4) * 4) + 4));
    break;
  case 0x10:
    if (*puVar1 != 0) {
      uVar8 = 0;
      do {
        if (*(char *)(*(int *)(puVar1[1] + uVar8 * 4) + 0x65) == '\0') {
          return 0;
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < *puVar1);
      return 1;
    }
    goto LAB_000a3ab4;
  case 0x11:
    if (*puVar1 == 0) {
      return 0;
    }
    uVar8 = 0;
    while (*(char *)(*(int *)(puVar1[1] + uVar8 * 4) + 100) == '\0') {
      uVar8 = uVar8 + 1;
      if (*puVar1 <= uVar8) {
        return 0;
      }
    }
    goto LAB_000a3ab4;
  case 0x12:
    iVar4 = *(int *)(this + 4);
    iVar2 = *(int *)(this + 8);
    iVar5 = 0;
    if (iVar4 < iVar2) {
      do {
        iVar2 = KIPlayer::isDead(*(KIPlayer **)(puVar1[1] + iVar4 * 4));
        if (iVar2 != 0) {
          iVar5 = iVar5 + 1;
        }
        iVar2 = *(int *)(this + 8);
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar2);
      iVar4 = *(int *)(this + 4);
    }
    uVar8 = (uint)(iVar5 == iVar2 - iVar4);
    break;
  case 0x13:
    uVar8 = Level::friendCargoWasStolen(*(Level **)(this + 0xc));
    break;
  case 0x14:
  case 0x15:
    iVar6 = *(int *)(this + 4);
    iVar4 = *(int *)(this + 8);
    iVar5 = 0;
    if (iVar6 < iVar4) {
      do {
        iVar2 = KIPlayer::isDead(*(KIPlayer **)(puVar1[1] + iVar6 * 4));
        if ((iVar2 == 1) && (*(int *)(*(int *)(puVar1[1] + iVar6 * 4) + 0x24) == 8)) {
          iVar5 = iVar5 + 1;
        }
        iVar4 = *(int *)(this + 8);
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar4);
      iVar2 = *(int *)this;
      iVar6 = *(int *)(this + 4);
    }
    uVar8 = 0;
    if (iVar2 == 0x14) {
      if (iVar5 == iVar4 - iVar6) {
        uVar8 = (uint)(*(int *)(*(int *)(this + 0xc) + 0x20) < *(int *)(*(int *)(this + 0xc) + 0x24)
                      );
      }
    }
    else if (iVar5 == iVar4 - iVar6) {
      uVar8 = (uint)(*(int *)(*(int *)(this + 0xc) + 0x24) <= *(int *)(*(int *)(this + 0xc) + 0x20))
      ;
    }
    break;
  case 0x16:
    iVar2 = Level::getMessages(*(Level **)(this + 0xc));
    piVar3 = (int *)Level::getMessages(*(Level **)(this + 0xc));
    this_01 = *(RadioMessage **)(*(int *)(iVar2 + 4) + *piVar3 * 4 + -4);
LAB_000a39ce:
    uVar8 = RadioMessage::isOver(this_01);
    break;
  case 0x17:
    iVar2 = Level::getEnemies(*(Level **)(this + 0xc));
    cVar7 = *(char *)(*(int *)(*(int *)(iVar2 + 4) + *(int *)(this + 4) * 4) + 0x20);
LAB_000a39ec:
    uVar8 = (uint)(cVar7 != '\0');
    break;
  case 0x19:
    iVar2 = Level::getEnemies(*(Level **)(this + 0xc));
    uVar8 = (uint)(*(float *)(*(int *)(*(int *)(iVar2 + 4) + *(int *)(this + 4) * 4) + 0x60) == 0.0)
    ;
    break;
  case 0x1a:
    iVar2 = *(int *)(this + 4);
    if (*(int *)(this + 8) <= iVar2) {
      return 0;
    }
    while (iVar4 = KIPlayer::isDead(*(KIPlayer **)(puVar1[1] + iVar2 * 4)), iVar4 == 0) {
      iVar2 = iVar2 + 1;
      if (*(int *)(this + 8) <= iVar2) {
        return 0;
      }
    }
LAB_000a3ab4:
    uVar8 = 1;
    break;
  case 0x1b:
    iVar2 = Level::getEnemiesLeft(*(Level **)(this + 0xc));
    bVar10 = SBORROW4(iVar2,*(int *)(this + 4));
    bVar9 = iVar2 - *(int *)(this + 4) < 0;
LAB_000a3ac0:
    uVar8 = 0;
    if (bVar9 != bVar10) {
      uVar8 = 1;
    }
    break;
  case 0x1c:
    iVar2 = Level::getNumDeliveredOre(*(Level **)(this + 0xc));
    goto LAB_000a3a72;
  case 0x1d:
    iVar2 = Level::getNumDeliveredPassengers(*(Level **)(this + 0xc));
LAB_000a3a72:
    uVar8 = (uint)(*(int *)(this + 4) <= iVar2);
    break;
  case 0x1e:
    iVar2 = Level::getEnemies(*(Level **)(this + 0xc));
    uVar8 = KIPlayer::isDying(*(KIPlayer **)(*(int *)(iVar2 + 4) + *(int *)(this + 4) * 4));
  }
  return uVar8;
}

// ===== Objective::getCalcValue  @0x000a3ad0  (12 bytes)
/* Objective::getCalcValue() */

bool __thiscall Objective::getCalcValue(Objective *this)

{
  return *(int *)this == 3;
}

// ===== Objective::isSurvivalObjective  @0x000a3adc  (12 bytes)
/* Objective::isSurvivalObjective() */

bool __thiscall Objective::isSurvivalObjective(Objective *this)

{
  return *(int *)this == 3;
}

// ===== Objective::setAchievedText  @0x000a3ae8  (32 bytes)
/* Objective::setAchievedText(AbyssEngine::String*) */

void __thiscall Objective::setAchievedText(Objective *this,String *param_1)

{
  String *this_00;
  
  this_00 = operator_new(8);
  AbyssEngine::String::String(this_00,param_1,false);
  *(String **)(this + 0x14) = this_00;
  return;
}

// ===== Objective::getAchievedText  @0x000a3b16  (4 bytes)
/* Objective::getAchievedText() */

undefined4 __thiscall Objective::getAchievedText(Objective *this)

{
  return *(undefined4 *)(this + 0x14);
}

