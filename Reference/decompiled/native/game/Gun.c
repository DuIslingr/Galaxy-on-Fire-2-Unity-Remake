// Class: Gun
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Gun::Gun  @0x0017cf18  (584 bytes)
/* Gun::Gun(int, int, int, int, int, int, float, AbyssEngine::AEMath::Vector,
   AbyssEngine::AEMath::Vector) */

void __thiscall
Gun::Gun(Gun *this,undefined4 param_1,undefined4 param_2,uint param_3,int param_4,undefined4 param_5
        ,undefined4 param_6,undefined4 param_8,undefined4 param_9,undefined4 param_10,
        undefined4 param_11,undefined4 param_12,undefined4 param_13,undefined4 param_14)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  void *pvVar6;
  undefined4 *puVar7;
  int iVar8;
  float fVar9;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  local_30 = param_10;
  uStack_2c = param_11;
  local_40 = param_12;
  uStack_3c = param_13;
  local_38 = param_14;
  uStack_34 = param_9;
  puVar4 = operator_new__(0xc);
  *(undefined4 **)(this + 0xc) = puVar4;
  *(undefined4 *)(this + 0x10) = 1;
  *puVar4 = 0;
  puVar4[1] = 0;
  puVar4[2] = 0;
  *(undefined4 *)(this + 8) = 0;
  puVar4 = operator_new__(0xc);
  *(undefined4 **)(this + 0x18) = puVar4;
  *(undefined4 *)(this + 0x1c) = 1;
  *puVar4 = 0;
  puVar4[1] = 0;
  puVar4[2] = 0;
  *(undefined4 *)(this + 0x14) = 0;
  puVar4 = operator_new__(0xc);
  *(undefined4 **)(this + 0x24) = puVar4;
  *(undefined4 *)(this + 0x28) = 1;
  *puVar4 = 0;
  puVar4[1] = 0;
  puVar4[2] = 0;
  *(undefined4 *)(this + 0x20) = 0;
  puVar4 = operator_new__(0xc);
  *(undefined4 **)(this + 0x30) = puVar4;
  *(undefined4 *)(this + 0x34) = 1;
  *puVar4 = 0;
  puVar4[1] = 0;
  uVar1 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  puVar4[2] = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x90) = 0;
  *(undefined4 *)(this + 0x94) = 0;
  *(undefined4 *)(this + 0x98) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0xb4) = 0;
  *(undefined4 *)(this + 0xb8) = 0;
  *(undefined4 *)(this + 0x10c) = 0;
  *(undefined4 *)(this + 0x110) = 0;
  *(undefined4 *)(this + 0xe0) = 0;
  *(undefined4 *)(this + 0xe4) = uVar1;
  *(undefined4 *)(this + 0xe8) = uVar2;
  *(undefined4 *)(this + 0xec) = uVar3;
  *(undefined4 *)(this + 0xd0) = 0;
  *(undefined4 *)(this + 0xd4) = uVar1;
  *(undefined4 *)(this + 0xd8) = uVar2;
  *(undefined4 *)(this + 0xdc) = uVar3;
  *(undefined4 *)(this + 0xc0) = 0;
  *(undefined4 *)(this + 0xc4) = uVar1;
  *(undefined4 *)(this + 200) = uVar2;
  *(undefined4 *)(this + 0xcc) = uVar3;
  *(undefined4 *)(this + 0xf4) = param_1;
  *(undefined4 *)(this + 0x60) = param_2;
  *(undefined4 *)(this + 0x50) = param_8;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  this[0xf0] = (Gun)0x0;
  this[0xa8] = (Gun)0x0;
  fVar9 = (float)AbyssEngine::AEMath::Vector::operator=
                           ((Vector *)(this + 0x7c),(Vector *)&uStack_34);
  AbyssEngine::AEMath::Vector::operator*=((Vector *)&local_40,fVar9);
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0xe4),(Vector *)&local_40);
  uVar5 = (uint)((ulonglong)param_3 * 4);
  *(undefined4 *)(this + 0x44) = param_5;
  *(undefined4 *)(this + 0x48) = param_6;
  *(undefined4 *)(this + 0x6c) = param_6;
  *(undefined4 *)(this + 0xa0) = 0;
  *(int *)(this + 0x74) = param_4;
  *(int *)(this + 0x78) = param_4 << 1;
  this[0x88] = (Gun)0x0;
  this[0xa9] = (Gun)0x0;
  if ((int)((ulonglong)param_3 * 4 >> 0x20) != 0) {
    uVar5 = 0xffffffff;
  }
  pvVar6 = operator_new__(uVar5);
  *(void **)(this + 0x3c) = pvVar6;
  uVar5 = param_3;
  if (0x7fffffff < param_3) {
    uVar5 = 0xffffffff;
  }
  pvVar6 = operator_new__(uVar5);
  *(void **)(this + 0x40) = pvVar6;
  puVar4 = operator_new(0xc);
  puVar7 = operator_new__(4);
  puVar4[1] = puVar7;
  *puVar7 = 0;
  puVar4[2] = 1;
  *puVar4 = 0;
  *(undefined4 **)(this + 0xac) = puVar4;
  ArraySetLength<AbyssEngine::AEMath::Vector>(param_3,(Array *)(this + 8));
  ArraySetLength<AbyssEngine::AEMath::Vector>(param_3,(Array *)(this + 0x14));
  ArraySetLength<AbyssEngine::AEMath::Vector>(param_3,(Array *)(this + 0x20));
  ArraySetLength<AbyssEngine::AEMath::Vector>(param_3,(Array *)(this + 0x2c));
  ArraySetLength<AbyssEngine::AEMath::Vector*>(param_3,*(Array **)(this + 0xac));
  if (0 < (int)param_3) {
    iVar8 = 0;
    uVar5 = 0;
    do {
      *(undefined4 *)(*(int *)(this + 0xc) + iVar8) = 0x47435000;
      iVar8 = iVar8 + 0xc;
      *(undefined4 *)(*(int *)(this + 0x3c) + uVar5 * 4) = 0xfff0bdc0;
      *(undefined1 *)(*(int *)(this + 0x40) + uVar5) = 0;
      *(undefined4 *)(*(int *)(*(int *)(this + 0xac) + 4) + uVar5 * 4) = 0;
      uVar5 = uVar5 + 1;
    } while (param_3 != uVar5);
  }
  this[0x4c] = (Gun)0x0;
  *(undefined4 *)(this + 0xb8) = 0;
  this[0x54] = (Gun)0x0;
  this[0x4d] = (Gun)0x0;
  *(undefined4 *)(this + 0xb4) = 0;
  *(undefined4 *)(this + 0x58) = 0xffffffff;
  *(undefined4 *)(this + 0x5c) = 0xffffffff;
  this[0xf8] = (Gun)0x1;
  this[0x68] = (Gun)0x0;
  this[0xf9] = (Gun)0x0;
  *(undefined4 *)(this + 0xfc) = 0;
  this[0x89] = (Gun)0x0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0xb0) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0xa4) = 0;
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

// ===== Gun::~Gun  @0x0017d1c8  (142 bytes)
/* Gun::~Gun() */

Gun * __thiscall Gun::~Gun(Gun *this)

{
  void *pvVar1;
  
  if (*(void **)(this + 0x3c) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x3c));
  }
  *(undefined4 *)(this + 0x3c) = 0;
  if (*(void **)(this + 0x40) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x40));
  }
  *(undefined4 *)(this + 0x40) = 0;
  if (*(void **)(this + 0x10c) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x10c));
  }
  *(undefined4 *)(this + 0x10c) = 0;
  if (*(void **)(this + 0x110) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x110));
  }
  *(undefined4 *)(this + 0x110) = 0;
  if (*(Array **)(this + 0xac) != (Array *)0x0) {
    ArrayReleaseClasses<AbyssEngine::AEMath::Vector*>(*(Array **)(this + 0xac));
    pvVar1 = *(void **)(this + 0xac);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0xac) = 0;
  if (*(void **)(this + 0x30) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x30));
  }
  *(undefined4 *)(this + 0x30) = 0;
  if (*(void **)(this + 0x24) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x24));
  }
  *(undefined4 *)(this + 0x24) = 0;
  if (*(void **)(this + 0x18) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x18));
  }
  *(undefined4 *)(this + 0x18) = 0;
  if (*(void **)(this + 0xc) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0xc));
  }
  *(undefined4 *)(this + 0xc) = 0;
  return this;
}

// ===== Gun::setIndex  @0x0017d258  (246 bytes)
/* Gun::setIndex(int) */

void __thiscall Gun::setIndex(Gun *this,int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  void *pvVar3;
  AEGeometry *this_00;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  *(int *)(this + 0x58) = param_1;
  this[0x108] = (Gun)(param_1 - 9U < 3 || param_1 == 0xe4);
  uVar1 = Item::getAttribute(*(Item **)(*(int *)(Globals::items + 4) + param_1 * 4),10);
  *(undefined4 *)(this + 100) = uVar1;
  iVar6 = *(int *)(&DAT_00259220 + param_1 * 4);
  if (-1 < iVar6) {
    uVar5 = *(uint *)(this + 8);
    uVar2 = (uint)((ulonglong)uVar5 * 4);
    if ((int)((ulonglong)uVar5 * 4 >> 0x20) != 0) {
      uVar2 = 0xffffffff;
    }
    pvVar3 = operator_new__(uVar2);
    *(void **)(this + 0x10c) = pvVar3;
    pvVar3 = operator_new__(uVar5);
    *(void **)(this + 0x110) = pvVar3;
    if (uVar5 != 0) {
      uVar2 = 0;
      do {
        this_00 = operator_new(0xc0);
        AEGeometry::AEGeometry(this_00,(ushort)iVar6,Globals::Canvas,false);
        *(undefined4 *)(*(int *)(this + 0x10c) + uVar2 * 4) = *(undefined4 *)(this_00 + 0xc);
        iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
        *(bool *)(*(int *)(this + 0x110) + uVar2) = iVar4 == 0;
        uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                          (Globals::Canvas,*(uint *)(*(int *)(this + 0x10c) + uVar2 * 4));
        AbyssEngine::Transform::SetAnimationState(uVar1,0,0);
        pvVar3 = (void *)AEGeometry::~AEGeometry(this_00);
        operator_delete(pvVar3);
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)(this + 8));
    }
  }
  return;
}

// ===== Gun::setErrorMagnitudePercentage  @0x0017d370  (14 bytes)
/* Gun::setErrorMagnitudePercentage(int) */

void __thiscall Gun::setErrorMagnitudePercentage(Gun *this,int param_1)

{
  uint in_fpscr;
  undefined4 uVar1;
  
  uVar1 = VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  *(undefined4 *)(this + 0xfc) = uVar1;
  return;
}

// ===== Gun::setFriendGun  @0x0017d37e  (6 bytes)
/* Gun::setFriendGun(bool) */

void __thiscall Gun::setFriendGun(Gun *this,bool param_1)

{
  this[0xf9] = (Gun)param_1;
  return;
}

// ===== Gun::setMagnitude  @0x0017d384  (6 bytes)
/* Gun::setMagnitude(int) */

void __thiscall Gun::setMagnitude(Gun *this,int param_1)

{
  *(int *)(this + 0x100) = param_1;
  return;
}

// ===== Gun::getMagnitude  @0x0017d38a  (6 bytes)
/* Gun::getMagnitude() */

undefined4 __thiscall Gun::getMagnitude(Gun *this)

{
  return *(undefined4 *)(this + 0x100);
}

// ===== Gun::setLevelCollision  @0x0017d390  (6 bytes)
/* Gun::setLevelCollision(bool) */

void __thiscall Gun::setLevelCollision(Gun *this,bool param_1)

{
  this[0xf8] = (Gun)param_1;
  return;
}

// ===== Gun::setOffset  @0x0017d398  (70 bytes)
/* Gun::setOffset(AbyssEngine::AEMath::Vector*) */

void __thiscall Gun::setOffset(Gun *this,Vector *param_1)

{
  undefined4 local_18;
  undefined4 uStack_14;
  float local_10;
  int local_c;
  
  local_c = __stack_chk_guard;
  local_18 = *(undefined4 *)param_1;
  uStack_14 = *(undefined4 *)(param_1 + 4);
  local_10 = *(float *)(param_1 + 8) + 100.0;
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x7c),(Vector *)&local_18);
  if (__stack_chk_guard != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Gun::setOffset  @0x0017d3ec  (144 bytes)
/* Gun::setOffset(int, int) */

void __thiscall Gun::setOffset(Gun *this,int param_1,int param_2)

{
  int iVar1;
  uint in_fpscr;
  float local_18;
  float local_14;
  float local_10;
  int local_c;
  
  iVar1 = param_1 * 6 + param_2 * 0x3c;
  local_18 = (float)VectorSignedToFloat((int)*(short *)(&UNK_002595c4 + iVar1 + -0x3c),
                                        (byte)(in_fpscr >> 0x16) & 3);
  local_14 = (float)VectorSignedToFloat((int)*(short *)(&UNK_002595c4 + iVar1 + -0x3a),
                                        (byte)(in_fpscr >> 0x16) & 3);
  local_10 = (float)VectorSignedToFloat((int)*(short *)(&UNK_002595c4 + iVar1 + -0x38),
                                        (byte)(in_fpscr >> 0x16) & 3);
  local_c = __stack_chk_guard;
  local_18 = *(float *)(this + 0x7c) + local_18;
  local_14 = *(float *)(this + 0x80) + local_14;
  local_10 = *(float *)(this + 0x84) + local_10;
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x7c),(Vector *)&local_18);
  if (__stack_chk_guard != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Gun::setImpact  @0x0017d488  (6 bytes)
/* Gun::setImpact(Sparks*) */

void __thiscall Gun::setImpact(Gun *this,Sparks *param_1)

{
  *(Sparks **)(this + 0xb8) = param_1;
  return;
}

// ===== Gun::setEnemies  @0x0017d48e  (6 bytes)
/* Gun::setEnemies(Array<Player*>*) */

void __thiscall Gun::setEnemies(Gun *this,Array *param_1)

{
  *(Array **)(this + 0xb4) = param_1;
  return;
}

// ===== Gun::getEnemies  @0x0017d494  (6 bytes)
/* Gun::getEnemies() */

undefined4 __thiscall Gun::getEnemies(Gun *this)

{
  return *(undefined4 *)(this + 0xb4);
}

// ===== Gun::setEnemy  @0x0017d49a  (86 bytes)
/* Gun::setEnemy(Player*) */

void __thiscall Gun::setEnemy(Gun *this,Player *param_1)

{
  int *piVar1;
  undefined4 *__ptr;
  void *pvVar2;
  
  pvVar2 = *(void **)(this + 0xb4);
  if (pvVar2 != (void *)0x0) {
    if (*(void **)((int)pvVar2 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar2 + 4));
    }
    operator_delete(pvVar2);
  }
  *(undefined4 *)(this + 0xb4) = 0;
  piVar1 = operator_new(0xc);
  __ptr = operator_new__(4);
  piVar1[1] = (int)__ptr;
  *__ptr = 0;
  *piVar1 = 0;
  *(int **)(this + 0xb4) = piVar1;
  piVar1[2] = 1;
  pvVar2 = realloc(__ptr,4);
  piVar1[1] = (int)pvVar2;
  *(Player **)((int)pvVar2 + *piVar1 * 4) = param_1;
  *piVar1 = piVar1[2];
  return;
}

// ===== Gun::removeAllEnemies  @0x0017d4fe  (8 bytes)
/* Gun::removeAllEnemies() */

void __thiscall Gun::removeAllEnemies(Gun *this)

{
  *(undefined4 *)(this + 0xb4) = 0;
  return;
}

// ===== Gun::setLevel  @0x0017d506  (4 bytes)
/* Gun::setLevel(Level*) */

void __thiscall Gun::setLevel(Gun *this,Level *param_1)

{
  *(Level **)(this + 0x38) = param_1;
  return;
}

// ===== Gun::setPlayerGun  @0x0017d50a  (6 bytes)
/* Gun::setPlayerGun(bool) */

void __thiscall Gun::setPlayerGun(Gun *this,bool param_1)

{
  this[0xf0] = (Gun)param_1;
  return;
}

// ===== Gun::isPlayerGun  @0x0017d510  (6 bytes)
/* Gun::isPlayerGun() */

Gun __thiscall Gun::isPlayerGun(Gun *this)

{
  return this[0xf0];
}

// ===== Gun::shootAt  @0x0017d518  (1902 bytes)
/* Gun::shootAt(AbyssEngine::AEMath::Matrix, int, Player*, bool) */

void Gun::shootAt(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
                 undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16,
                 undefined4 param_17,undefined4 param_18)

{
  byte bVar1;
  uint *puVar2;
  int iVar3;
  float fVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  float *pfVar7;
  PlayerEgo *this;
  TargetFollowCamera *this_00;
  Ship *pSVar8;
  Vector *pVVar9;
  int iVar10;
  uint uVar11;
  Item *this_01;
  uint uVar12;
  Vector *pVVar13;
  uint uVar14;
  Player *this_02;
  int iVar15;
  bool bVar16;
  bool bVar17;
  uint in_fpscr;
  float fVar18;
  Vector aVStack_b8 [12];
  Vector aVStack_ac [12];
  Vector aVStack_a0 [12];
  undefined4 local_94;
  undefined4 uStack_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  int local_4c;
  
  local_4c = __stack_chk_guard;
  local_7c = param_5;
  local_78 = param_6;
  local_74 = param_7;
  local_70 = param_8;
  local_6c = param_9;
  uStack_68 = param_10;
  uStack_64 = param_11;
  local_60 = param_12;
  uStack_5c = param_13;
  local_58 = param_14;
  uStack_54 = param_15;
  uStack_50 = param_16;
  *(undefined4 *)(param_1 + 4) = param_18;
  local_88 = param_2;
  uStack_84 = param_3;
  uStack_80 = param_4;
  if (*(char *)(param_1 + 0xf9) == '\0') {
    pSVar8 = (Ship *)Status::getShip(Globals::status);
    iVar15 = Ship::getEquipment(pSVar8);
    this_01 = *(Item **)(*(int *)(iVar15 + 4) + *(int *)(param_1 + 0xf4) * 4);
    if ((this_01 == (Item *)0x0) || (iVar15 = Item::getAmount(this_01), iVar15 == 0)) {
      bVar16 = false;
      goto LAB_0017dc74;
    }
  }
  else {
    this_01 = (Item *)0x0;
  }
  if (*(char *)(param_1 + 0x108) == '\0') {
    uVar12 = *(uint *)(param_1 + 8);
    if (uVar12 == 0) goto LAB_0017d77e;
    iVar15 = *(int *)(param_1 + 0x5c);
    pVVar13 = (Vector *)(param_1 + 0xd8);
    pVVar9 = (Vector *)(param_1 + 0x7c);
    iVar3 = 0;
    uVar14 = 0;
    uVar11 = 0;
    do {
      if ((iVar15 - 4U < 2) || (iVar15 == 0x28)) {
        iVar10 = -2000;
      }
      else {
        iVar10 = 0;
      }
      if (*(int *)(*(int *)(param_1 + 0x3c) + uVar14 * 4) <= iVar10) {
        if ((iVar15 == 0x27) && (2 < *(int *)(*(int *)(param_1 + 0x38) + 0x6c))) {
          iVar15 = 0x27;
        }
        else {
          *(undefined4 *)(param_1 + 0x6c) = 0;
          *(undefined4 *)(param_1 + 0x70) = 0;
          *(undefined1 *)(param_1 + 0x4d) = 1;
          *(undefined1 *)(param_1 + 0x4c) = 1;
          *(uint *)(param_1 + 0xa0) = uVar14;
          iVar15 = *(int *)(param_1 + 0xc);
          AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_94,(Matrix *)&local_88);
          AbyssEngine::AEMath::Vector::operator=((Vector *)(iVar3 + iVar15),(Vector *)&local_94);
          local_94 = 0;
          uStack_90 = 0;
          local_8c = 0;
          iVar15 = AbyssEngine::AEMath::operator!=(pVVar9,(Vector *)&local_94);
          if ((iVar15 == 1) && (*(int *)(param_1 + 0x5c) != 0x2a)) {
            if (*(char *)(param_1 + 0xa5) == '\0') {
              if (*(char *)(param_1 + 0xa4) != '\0') goto LAB_0017d8d0;
              iVar15 = *(int *)(param_1 + 0xc);
              AbyssEngine::AEMath::MatrixRotateVector
                        ((AEMath *)&local_94,(Matrix *)&local_88,pVVar9);
LAB_0017d908:
              AbyssEngine::AEMath::Vector::operator+=
                        ((Vector *)(iVar15 + iVar3),(Vector *)&local_94);
            }
            else if (*(char *)(param_1 + 0xa4) != '\0') {
LAB_0017d8d0:
              AbyssEngine::AEMath::Vector::operator=(pVVar13,pVVar9);
              if (*(byte *)(param_1 + 0xa6) != 0) {
                *(float *)pVVar13 = -*(float *)pVVar13;
              }
              *(byte *)(param_1 + 0xa6) = *(byte *)(param_1 + 0xa6) ^ 1;
              iVar15 = *(int *)(param_1 + 0xc);
              AbyssEngine::AEMath::MatrixRotateVector
                        ((AEMath *)&local_94,(Matrix *)&local_88,pVVar13);
              goto LAB_0017d908;
            }
            if ((*(char *)(param_1 + 0xa5) != '\0') && (*(char *)(param_1 + 0xa6) != '\0')) {
              AbyssEngine::AEMath::Vector::operator=(pVVar13,pVVar9);
              if (*(byte *)(param_1 + 0xa7) != 0) {
                *(float *)(param_1 + 0xdc) = -*(float *)(param_1 + 0xdc);
              }
              *(byte *)(param_1 + 0xa7) = *(byte *)(param_1 + 0xa7) ^ 1;
              iVar15 = *(int *)(param_1 + 0xc);
              AbyssEngine::AEMath::MatrixRotateVector
                        ((AEMath *)&local_94,(Matrix *)&local_88,pVVar13);
              AbyssEngine::AEMath::Vector::operator+=
                        ((Vector *)(iVar15 + iVar3),(Vector *)&local_94);
            }
          }
          local_94 = 0;
          uStack_90 = 0;
          local_8c = 0;
          if (*(int *)(param_1 + 0x5c) == 0xb) {
            AbyssEngine::AEMath::MatrixGetDir((AEMath *)aVStack_ac,(Matrix *)&local_88);
            AbyssEngine::AEMath::MatrixGetUp((AEMath *)aVStack_b8,(Matrix *)&local_88);
            AbyssEngine::AEMath::operator+((AEMath *)aVStack_a0,aVStack_ac,aVStack_b8);
            AbyssEngine::AEMath::Vector::operator=((Vector *)&local_94,aVStack_a0);
            iVar15 = *(int *)(param_1 + 0xac);
            if (*(int *)(*(int *)(iVar15 + 4) + uVar14 * 4) == 0) {
              puVar5 = operator_new(0xc);
              *puVar5 = 0;
              puVar5[1] = 0;
              puVar5[2] = 0;
              *(undefined4 **)(*(int *)(iVar15 + 4) + uVar14 * 4) = puVar5;
            }
            iVar15 = AbyssEngine::AERandom::nextInt(Globals::rnd,200);
            fVar4 = (float)VectorSignedToFloat(iVar15 + -100,(byte)(in_fpscr >> 0x16) & 3);
            **(float **)(*(int *)(*(int *)(param_1 + 0xac) + 4) + uVar14 * 4) = fVar4 / 50.0;
            iVar15 = AbyssEngine::AERandom::nextInt(Globals::rnd,200);
            fVar4 = (float)VectorSignedToFloat(iVar15 + -100,(byte)(in_fpscr >> 0x16) & 3);
            *(float *)(*(int *)(*(int *)(*(int *)(param_1 + 0xac) + 4) + uVar14 * 4) + 4) =
                 fVar4 / 50.0;
            iVar15 = AbyssEngine::AERandom::nextInt(Globals::rnd,200);
            fVar4 = (float)VectorSignedToFloat(iVar15 + -100,(byte)(in_fpscr >> 0x16) & 3);
            *(float *)(*(int *)(*(int *)(*(int *)(param_1 + 0xac) + 4) + uVar14 * 4) + 8) =
                 fVar4 / 50.0;
          }
          else {
            AbyssEngine::AEMath::MatrixGetDir((AEMath *)aVStack_a0,(Matrix *)&local_88);
            AbyssEngine::AEMath::Vector::operator=((Vector *)&local_94,aVStack_a0);
          }
          AbyssEngine::AEMath::MatrixRotateVector
                    ((AEMath *)aVStack_a0,(Matrix *)&local_88,(Vector *)(param_1 + 0xe4));
          AbyssEngine::AEMath::Vector::operator+=((Vector *)&local_94,aVStack_a0);
          AbyssEngine::AEMath::Vector::operator=
                    ((Vector *)(*(int *)(param_1 + 0x18) + iVar3),(Vector *)&local_94);
          iVar15 = *(int *)(param_1 + 0x24);
          AbyssEngine::AEMath::MatrixGetUp((AEMath *)aVStack_a0,(Matrix *)&local_88);
          AbyssEngine::AEMath::Vector::operator=((Vector *)(iVar3 + iVar15),aVStack_a0);
          fVar4 = *(float *)(param_1 + 0xfc);
          uVar12 = in_fpscr & 0xfffffff | (uint)(fVar4 < 0.0) << 0x1f | (uint)(fVar4 == 0.0) << 0x1e
          ;
          in_fpscr = uVar12 | (uint)NAN(fVar4) << 0x1c;
          bVar1 = (byte)(uVar12 >> 0x18);
          if ((bool)(bVar1 >> 6 & 1) || bVar1 >> 7 != ((byte)(in_fpscr >> 0x1c) & 1)) {
            iVar15 = *(int *)(param_1 + 0x18);
          }
          else {
            uVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,(int)fVar4);
            fVar4 = fVar4 * 0.005;
            fVar18 = (float)VectorSignedToFloat(uVar6,(byte)(in_fpscr >> 0x16) & 3);
            pfVar7 = (float *)(*(int *)(param_1 + 0x18) + iVar3);
            *pfVar7 = *pfVar7 + (fVar18 * 0.01 - fVar4);
            uVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,(int)*(float *)(param_1 + 0xfc));
            fVar18 = (float)VectorSignedToFloat(uVar6,(byte)(in_fpscr >> 0x16) & 3);
            iVar15 = *(int *)(param_1 + 0x18) + iVar3;
            *(float *)(iVar15 + 4) = *(float *)(iVar15 + 4) + (fVar18 * 0.01 - fVar4);
            uVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,(int)*(float *)(param_1 + 0xfc));
            fVar18 = (float)VectorSignedToFloat(uVar6,(byte)(in_fpscr >> 0x16) & 3);
            iVar15 = *(int *)(param_1 + 0x18);
            *(float *)(iVar15 + iVar3 + 8) =
                 *(float *)(iVar15 + iVar3 + 8) + (fVar18 * 0.01 - fVar4);
          }
          AbyssEngine::AEMath::VectorNormalize((AEMath *)aVStack_a0,(Vector *)(iVar15 + iVar3));
          fVar4 = (float)AbyssEngine::AEMath::Vector::operator=
                                   ((Vector *)(iVar15 + iVar3),aVStack_a0);
          AbyssEngine::AEMath::Vector::operator*=
                    ((Vector *)(*(int *)(param_1 + 0x18) + iVar3),fVar4);
          if (*(int *)(param_1 + 0x5c) == 0x27) {
            uVar6 = 0;
          }
          else {
            uVar6 = *(undefined4 *)(param_1 + 0x44);
          }
          *(undefined4 *)(*(int *)(param_1 + 0x3c) + uVar14 * 4) = uVar6;
          if (*(char *)(param_1 + 0xf9) == '\0') {
            bVar16 = true;
            if ((this_01 != (Item *)0x0) && (0 < *(int *)(param_1 + 0x74))) {
              iVar15 = Item::getType(this_01);
              if (iVar15 != 1) goto LAB_0017dbb8;
              bVar16 = false;
              if (*(int *)(param_1 + 0x58) == 0xb3) {
                *(undefined4 *)(Globals::status + 0x144) = 0;
              }
            }
          }
          else {
LAB_0017dbb8:
            bVar16 = true;
          }
          *(undefined1 *)(param_1 + 0xa9) = 1;
          if ((*(char *)(param_1 + 0xf0) != '\0') && (*(char *)(param_1 + 0x4d) != '\0')) {
            this = (PlayerEgo *)Level::getPlayer(*(Level **)(param_1 + 0x38));
            this_00 = (TargetFollowCamera *)PlayerEgo::getTargetFollowCamera(this);
            TargetFollowCamera::hitSmall(this_00);
          }
          if (*(int *)(param_1 + 0x5c) != 0x28 && !bVar16) {
            *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + -1;
            Item::changeAmount(this_01,-1);
            if (*(int *)(param_1 + 0x74) != 0) goto LAB_0017dc72;
            goto LAB_0017dc64;
          }
          if (*(int *)(param_1 + 0x5c) != 0x28) goto LAB_0017dc72;
          uVar12 = *(uint *)(param_1 + 8);
          uVar11 = 1;
          iVar15 = 0x28;
        }
      }
      uVar14 = uVar14 + 1;
      iVar3 = iVar3 + 0xc;
    } while (uVar14 < uVar12);
    uVar12 = *(uint *)(param_1 + 0x5c);
    bVar17 = uVar12 != 0x28;
    bVar16 = !bVar17;
    if (!bVar17) {
      uVar12 = uVar11 ^ 1;
    }
    if (bVar17 || (uVar12 & 1) != 0) goto LAB_0017dc74;
    *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + -1;
    if ((this_01 != (Item *)0x0) && (Item::changeAmount(this_01,-1), *(int *)(param_1 + 0x74) == 0))
    {
LAB_0017dc64:
      pSVar8 = (Ship *)Status::getShip(Globals::status);
      Ship::freeSlot(pSVar8,this_01);
    }
  }
  else {
    if (0 < **(int **)(param_1 + 0x3c)) {
LAB_0017d77e:
      bVar16 = *(int *)(param_1 + 0x5c) == 0x28;
      goto LAB_0017dc74;
    }
    *(undefined4 *)(param_1 + 0x6c) = 0;
    *(undefined4 *)(param_1 + 0x70) = 0;
    *(undefined2 *)(param_1 + 0x4c) = 0x101;
    if (*(char *)(param_1 + 0xf0) != '\0') {
      *(undefined1 *)(param_1 + 0xa9) = 1;
    }
    *(undefined4 *)(param_1 + 0x9c) = 0xffffffff;
    puVar2 = *(uint **)(param_1 + 0xb4);
    if (*puVar2 == 0) {
      **(int **)(param_1 + 0x3c) = *(int *)(param_1 + 0x44);
    }
    else {
      iVar15 = 99999999;
      uVar12 = 0;
      do {
        this_02 = *(Player **)(puVar2[1] + uVar12 * 4);
        iVar3 = Player::getKIPlayer(this_02);
        if ((((iVar3 != 0) &&
             (iVar3 = Player::getKIPlayer(this_02), *(char *)(iVar3 + 0x6f) != '\0')) &&
            (iVar3 = Player::isActive(this_02), iVar3 == 1)) &&
           (iVar3 = Player::isDead(this_02), iVar3 == 0)) {
          Player::getPosition();
          Level::getPlayer(*(Level **)(param_1 + 0x38));
          PlayerEgo::getPosition();
          AbyssEngine::AEMath::operator-((AEMath *)&local_94,aVStack_a0,aVStack_ac);
          fVar4 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_94);
          if ((int)fVar4 < iVar15) {
            *(uint *)(param_1 + 0x9c) = uVar12;
            iVar15 = (int)fVar4;
          }
        }
        puVar2 = *(uint **)(param_1 + 0xb4);
        uVar12 = uVar12 + 1;
      } while (uVar12 < *puVar2);
      iVar3 = *(int *)(param_1 + 0x9c);
      **(undefined4 **)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x44);
      if (-1 < iVar3) {
        Player::getPosition();
        Level::getPlayer(*(Level **)(param_1 + 0x38));
        PlayerEgo::getPosition();
        AbyssEngine::AEMath::operator-((AEMath *)aVStack_a0,aVStack_ac,aVStack_b8);
        AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_94,aVStack_a0);
        AbyssEngine::AEMath::Vector::operator=((Vector *)(param_1 + 0x90),(Vector *)&local_94);
        pVVar13 = *(Vector **)(param_1 + 0xc);
        Player::getPosition();
        AbyssEngine::AEMath::Vector::operator=(pVVar13,(Vector *)&local_94);
        pVVar13 = *(Vector **)(param_1 + 0x18);
        Level::getPlayer(*(Level **)(param_1 + 0x38));
        AEGeometry::getDirection();
        AbyssEngine::AEMath::Vector::operator=(pVVar13,(Vector *)&local_94);
        *(int *)(param_1 + 0x8c) = iVar15;
        goto LAB_0017dc72;
      }
    }
    Level::getPlayer(*(Level **)(param_1 + 0x38));
    AEGeometry::getDirection();
    AbyssEngine::AEMath::Vector::operator=((Vector *)(param_1 + 0x90),(Vector *)&local_94);
    pVVar13 = *(Vector **)(param_1 + 0xc);
    Level::getPlayer(*(Level **)(param_1 + 0x38));
    PlayerEgo::getPosition();
    Level::getPlayer(*(Level **)(param_1 + 0x38));
    fVar4 = (float)AEGeometry::getDirection();
    AbyssEngine::AEMath::operator*((AEMath *)aVStack_ac,fVar4,(Vector *)0x46ea6000);
    AbyssEngine::AEMath::operator+((AEMath *)&local_94,aVStack_a0,aVStack_ac);
    AbyssEngine::AEMath::Vector::operator=(pVVar13,(Vector *)&local_94);
    pVVar13 = *(Vector **)(param_1 + 0x18);
    Level::getPlayer(*(Level **)(param_1 + 0x38));
    AEGeometry::getDirection();
    AbyssEngine::AEMath::Vector::operator=(pVVar13,(Vector *)&local_94);
    *(undefined4 *)(param_1 + 0x8c) = 30000;
  }
LAB_0017dc72:
  bVar16 = true;
LAB_0017dc74:
  if (__stack_chk_guard == local_4c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(bVar16);
}

// ===== Gun::shoot  @0x0017dcb4  (84 bytes)
/* Gun::shoot(AbyssEngine::AEMath::Matrix, int, bool) */

void Gun::shoot(void)

{
  shootAt();
  return;
}

// ===== Gun::ignite  @0x0017dd08  (1056 bytes)
/* Gun::ignite() */

void __thiscall Gun::ignite(Gun *this)

{
  uint uVar1;
  byte bVar2;
  uint *puVar3;
  Player *this_00;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  PlayerEgo *this_01;
  int *piVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  Vector *this_02;
  Vector *this_03;
  uint uVar12;
  bool bVar13;
  uint in_fpscr;
  int iVar14;
  float extraout_s0;
  undefined4 uVar15;
  float extraout_s0_00;
  float extraout_s1;
  float fVar16;
  float extraout_s2;
  float fVar17;
  undefined8 local_68;
  undefined4 local_60;
  int local_5c;
  
  local_5c = __stack_chk_guard;
  iVar8 = *(int *)(this + 0x5c);
  if (iVar8 != 6) {
    if (iVar8 != 7) goto LAB_0017dd4a;
    *(int *)(Globals::status + 200) = *(int *)(Globals::status + 200) + 1;
  }
  *(undefined1 *)(*(int *)(this + 0x38) + 0x69) = 0;
LAB_0017dd4a:
  this[0x88] = (Gun)0x1;
  puVar3 = *(uint **)(this + 0xb4);
  if (puVar3 != (uint *)0x0) {
    *(undefined4 *)this = 0;
    if (*puVar3 != 0) {
      this_02 = (Vector *)(this + 0xd8);
      this_03 = (Vector *)(this + 0xc0);
      uVar11 = 0;
      do {
        this_00 = *(Player **)(puVar3[1] + uVar11 * 4);
        *(Player **)(this + 0xbc) = this_00;
        if (iVar8 == 6) {
          iVar8 = Player::isAsteroid(this_00);
          if (iVar8 == 0) {
            this_00 = *(Player **)(this + 0xbc);
            goto LAB_0017ddcc;
          }
        }
        else {
LAB_0017ddcc:
          iVar8 = Player::isActive(this_00);
          if ((iVar8 == 1) && (*(int *)(this + 8) != 0)) {
            iVar8 = 0;
            uVar12 = 0;
            do {
              local_68 = *(undefined8 *)(*(int *)(this + 0xc) + iVar8);
              local_60 = *(undefined4 *)((undefined8 *)(*(int *)(this + 0xc) + iVar8) + 1);
              AbyssEngine::AEMath::Vector::operator=(this_03,(Vector *)&local_68);
              Player::getPosition();
              AbyssEngine::AEMath::Vector::operator=(this_02,(Vector *)&local_68);
              AbyssEngine::AEMath::Vector::operator-=(this_02,this_03);
              fVar4 = (float)AbyssEngine::AEMath::VectorLength(this_02);
              iVar14 = (int)fVar4;
              if (iVar14 < *(int *)(this + 0x100)) {
                *(undefined1 *)(*(int *)(this + 0x40) + uVar12) = 1;
                AbyssEngine::AEMath::Vector::operator=
                          ((Vector *)(*(int *)(this + 0x30) + iVar8),this_03);
                fVar4 = (float)VectorSignedToFloat(*(int *)(this + 0x100),
                                                   (byte)(in_fpscr >> 0x16) & 3);
                fVar16 = (float)VectorSignedToFloat(*(int *)(this + 0x100) - iVar14,
                                                    (byte)(in_fpscr >> 0x16) & 3);
                if (*(int *)(this + 0x5c) == 0xb) {
                  fVar16 = (float)VectorSignedToFloat(10000 - iVar14,(byte)(in_fpscr >> 0x16) & 3);
                  fVar16 = fVar16 / 10000.0;
                }
                else {
                  fVar16 = fVar16 / fVar4;
                }
                uVar9 = in_fpscr & 0xfffffff;
                uVar1 = uVar9 | (uint)(fVar16 < 1.0) << 0x1f | (uint)(fVar16 == 1.0) << 0x1e;
                in_fpscr = uVar1 | (uint)NAN(fVar16) << 0x1c;
                bVar2 = (byte)(uVar1 >> 0x18);
                fVar4 = 1.0;
                if (((bool)(bVar2 >> 6 & 1) || bVar2 >> 7 != ((byte)(in_fpscr >> 0x1c) & 1)) &&
                   (in_fpscr = uVar9, fVar4 = fVar16, fVar16 < 0.0)) {
                  fVar4 = 0.0;
                }
                iVar14 = Item::getAttribute(*(Item **)(*(int *)(Globals::items + 4) +
                                                      *(int *)(this + 0x58) * 4),10);
                uVar9 = *(int *)(this + 0x5c) - 0xb;
                if (((uVar9 < 0x20) && ((1 << (uVar9 & 0xff) & 0x80800001U) != 0)) ||
                   (*(int *)(this + 0x5c) == 7)) {
                  fVar16 = extraout_s0;
                  if (iVar14 != -0x3a6687db) {
                    fVar16 = (float)VectorSignedToFloat(iVar14,(byte)(in_fpscr >> 0x16) & 3);
                    fVar16 = (float)Player::setEmpForce(*(Player **)(this + 0xbc),fVar4 * fVar16);
                  }
                  Player::setBombForce(*(Player **)(this + 0xbc),fVar16);
                  iVar5 = Player::isAsteroid(*(Player **)(this + 0xbc));
                  if (iVar5 != 0) {
                    fVar4 = fVar4 * 0.6;
                  }
                  if (0 < *(int *)(this + 0x60)) {
                    fVar16 = (float)VectorSignedToFloat(*(int *)(this + 0x60),
                                                        (byte)(in_fpscr >> 0x16) & 3);
                    Player::damage(*(Player **)(this + 0xbc),(int)(fVar4 * fVar16),(bool)this[0xf9],
                                   *(int *)(this + 0x58));
                    iVar5 = Player::isGasCloud(*(Player **)(this + 0xbc));
                    bVar13 = iVar5 == 1;
                    if (bVar13) {
                      iVar5 = *(int *)(this + 0x5c);
                    }
                    if (bVar13 && iVar5 == 0x22) {
                      uVar6 = Player::getKIPlayer(*(Player **)(this + 0xbc));
                      uVar15 = VectorSignedToFloat(*(undefined4 *)(this + 0x100),
                                                   (byte)(in_fpscr >> 0x16) & 3);
                      iVar5 = *(int *)(this + 0xc) + iVar8;
                      PlayerGasCloud::explode
                                (uVar6,*(undefined4 *)(this + 0x58),
                                 *(undefined4 *)(*(int *)(this + 0xc) + iVar8),
                                 *(undefined4 *)(iVar5 + 4),*(undefined4 *)(iVar5 + 8),uVar15);
                    }
                    if ((*(int *)(this + 0x58) == 0xb3) &&
                       (iVar5 = Player::isAsteroid(*(Player **)(this + 0xbc)), iVar5 == 1)) {
                      fVar17 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x60),
                                                          (byte)(in_fpscr >> 0x16) & 3);
                      uVar6 = Player::getHitpoints(*(Player **)(this + 0xbc));
                      fVar16 = (float)VectorSignedToFloat(uVar6,(byte)(in_fpscr >> 0x16) & 3);
                      uVar9 = in_fpscr & 0xfffffff | (uint)(fVar4 * fVar17 < fVar16) << 0x1f;
                      in_fpscr = uVar9 | (uint)(NAN(fVar4 * fVar17) || NAN(fVar16)) << 0x1c;
                      if (((byte)(uVar9 >> 0x1f) == ((byte)(in_fpscr >> 0x1c) & 1)) &&
                         (iVar5 = Achievements::hasMedal(Globals::achievements,0x2c,1), iVar5 == 0))
                      {
                        iVar10 = *(int *)(Globals::status + 0x144) + 1;
                        *(int *)(Globals::status + 0x144) = iVar10;
                        iVar5 = Achievements::getValue(Globals::achievements,0x2c,1);
                        if (iVar5 <= iVar10) {
                          this_01 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x38));
                          iVar5 = PlayerEgo::getHUD(this_01);
                          Hud::hudEventMedal(iVar5,0x2c);
                          *(undefined1 *)(Globals::status + 0x148) = 1;
                        }
                      }
                    }
                  }
                  if (0 < iVar14) {
                    fVar16 = (float)VectorSignedToFloat(iVar14,(byte)(in_fpscr >> 0x16) & 3);
                    Player::damageEmp(*(Player **)(this + 0xbc),(int)(fVar16 * fVar4),
                                      (bool)this[0xf9]);
                  }
                  if ((*(int *)(this + 0x5c) == 0x2a) &&
                     (iVar14 = Player::getKIPlayer(*(Player **)(this + 0xbc)), iVar14 != 0)) {
                    piVar7 = (int *)Player::getKIPlayer(*(Player **)(this + 0xbc));
                    (**(code **)(*piVar7 + 0x2c))(piVar7,this_03,*(undefined4 *)(this + 0x100));
                  }
                }
                else {
                  fVar16 = (float)VectorSignedToFloat(iVar14,(byte)(in_fpscr >> 0x16) & 3);
                  Player::damageEmp(*(Player **)(this + 0xbc),(int)(fVar4 * fVar16),(bool)this[0xf9]
                                   );
                }
                AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_68,this_02);
                AbyssEngine::AEMath::Vector::operator=(this_02,(Vector *)&local_68);
                Player::setHitVector
                          (*(Player **)(this + 0xbc),extraout_s0_00,extraout_s1,extraout_s2);
                local_68 = *(undefined8 *)(*(int *)(this + 0x18) + iVar8);
                local_60 = *(undefined4 *)((undefined8 *)(*(int *)(this + 0x18) + iVar8) + 1);
                AbyssEngine::AEMath::Vector::operator=(this_02,(Vector *)&local_68);
                AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_68,this_02);
                AbyssEngine::AEMath::Vector::operator=(this_02,(Vector *)&local_68);
                uVar6 = Player::getKIPlayer(*(Player **)(this + 0xbc));
                *(undefined4 *)this = uVar6;
                *(undefined4 *)(*(int *)(this + 0x3c) + uVar12 * 4) = 0xffffffff;
              }
              iVar8 = iVar8 + 0xc;
              if (*(int *)(this + 0x5c) != 0xb) {
                *(undefined4 *)(*(int *)(this + 0x3c) + uVar12 * 4) = 0xffffffff;
              }
              uVar12 = uVar12 + 1;
            } while (uVar12 < *(uint *)(this + 8));
          }
        }
        puVar3 = *(uint **)(this + 0xb4);
        iVar8 = *(int *)(this + 0x5c);
        uVar11 = uVar11 + 1;
      } while (uVar11 < *puVar3);
    }
    if (iVar8 == 6) {
      **(undefined4 **)(this + 0x3c) = 0xffffffff;
    }
  }
  if (*(Sparks **)(this + 0xb8) != (Sparks *)0x0) {
    Sparks::explode(*(Sparks **)(this + 0xb8),*(Vector **)(this + 0xc));
  }
  if (__stack_chk_guard != local_5c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Gun::calcCharacterCollision  @0x0017e154  (1968 bytes)
/* Gun::calcCharacterCollision() */

void __thiscall Gun::calcCharacterCollision(Gun *this)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  bool bVar4;
  bool bVar5;
  byte bVar6;
  bool bVar7;
  PaintCanvas *this_00;
  uint *puVar8;
  int iVar9;
  undefined8 *puVar10;
  Gun *pGVar11;
  int *piVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  PlayerEgo *pPVar15;
  Vector *this_01;
  Gun GVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  Player *this_02;
  uint in_fpscr;
  float fVar22;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s1;
  float extraout_s1_00;
  float fVar23;
  float extraout_s2;
  float extraout_s2_00;
  float fVar24;
  Vector aVStack_10c [60];
  undefined4 local_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 local_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  float local_94;
  float local_90;
  float local_8c;
  undefined8 local_88;
  float local_80;
  undefined8 local_78;
  float local_70;
  int local_6c;
  
  local_6c = __stack_chk_guard;
  puVar8 = *(uint **)(this + 0xb4);
  if (puVar8 != (uint *)0x0) {
    iVar17 = *(int *)(this + 0x5c);
    if ((iVar17 - 6U < 2) || (iVar17 == 0x2a || iVar17 == 0x22)) {
      bVar6 = 1;
      bVar7 = true;
    }
    else {
      bVar6 = 0;
      bVar7 = true;
      if ((1 < iVar17 - 4U) && (iVar17 != 0x28)) {
        bVar6 = 0;
        bVar7 = false;
      }
    }
    bVar5 = iVar17 == 0xb;
    uVar18 = 0;
    *(undefined4 *)this = 0;
    if (*puVar8 != 0) {
      this_01 = (Vector *)(this + 0xd8);
      do {
        this_02 = *(Player **)(puVar8[1] + uVar18 * 4);
        if ((((!bVar5) ||
             ((this_02[0x5c] != (Player)0x0 &&
              ((iVar9 = Player::getKIPlayer(this_02), iVar9 == 0 ||
               (iVar9 = Player::getKIPlayer(this_02), *(char *)(iVar9 + 0x3d) == '\0')))))) &&
            (iVar9 = Player::isActive(this_02), iVar9 == 1)) &&
           ((iVar9 = Player::getHitpoints(this_02), 0 < iVar9 && (*(int *)(this + 8) != 0)))) {
          uVar21 = 0;
          do {
            puVar10 = (undefined8 *)(*(int *)(this + 0xc) + uVar21 * 0xc);
            local_78 = *puVar10;
            local_70 = *(float *)(puVar10 + 1);
            puVar10 = (undefined8 *)(*(int *)(this + 0x18) + uVar21 * 0xc);
            local_88 = *puVar10;
            local_80 = *(float *)(puVar10 + 1);
            AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_94,this_02 + 4);
            pGVar11 = (Gun *)(this_02 + 0x40);
            if (this[0x68] != (Gun)0x0) {
              pGVar11 = this + 0x104;
            }
            iVar9 = *(int *)pGVar11;
            if (bVar5) {
              iVar9 = iVar9 * 5;
            }
            else if (iVar17 == 0x19) {
              Level::getPlayer(*(Level **)(this + 0x38));
              PlayerEgo::getPosition();
              AbyssEngine::AEMath::operator-((AEMath *)&local_d0,(Vector *)&local_94,aVStack_10c);
              fVar22 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_d0);
              iVar19 = Player::getKIPlayer(this_02);
              if ((iVar19 == 0) ||
                 (iVar19 = Player::getKIPlayer(this_02), *(char *)(iVar19 + 0x6d) == '\0')) {
                if ((int)fVar22 < 0x4e21) {
                  fVar24 = (float)VectorSignedToFloat(iVar9,(byte)(in_fpscr >> 0x16) & 3);
                  fVar23 = (float)VectorSignedToFloat(iVar9 << 1,(byte)(in_fpscr >> 0x16) & 3);
                  fVar24 = fVar24 * 1.5;
                  if (10000 < (int)fVar22) {
                    fVar24 = fVar23;
                  }
                }
                else {
                  fVar24 = (float)VectorSignedToFloat(iVar9 * 3,(byte)(in_fpscr >> 0x16) & 3);
                }
              }
              else {
                fVar22 = (float)VectorSignedToFloat(iVar9,(byte)(in_fpscr >> 0x16) & 3);
                fVar24 = fVar22 * 0.5;
              }
              iVar9 = (int)fVar24;
            }
            piVar12 = (int *)Player::getKIPlayer(this_02);
            if (this_02[0x69] == (Player)0x0) {
              if ((piVar12 != (int *)0x0) && ((char)piVar12[0x22] != '\0')) goto LAB_0017e350;
            }
            else if (piVar12 == (int *)0x0) {
LAB_0017e366:
              bVar4 = false;
LAB_0017e368:
              fVar22 = (float)VectorSignedToFloat(iVar9,(byte)(in_fpscr >> 0x16) & 3);
              fVar24 = (local_94 - (float)local_78) + (float)local_88;
              uVar20 = in_fpscr & 0xfffffff;
              in_fpscr = uVar20;
              if (fVar24 < fVar22) {
                fVar23 = (float)VectorSignedToFloat(-iVar9,(byte)(uVar20 >> 0x16) & 3);
                uVar1 = uVar20 | (uint)(fVar24 < fVar23) << 0x1f | (uint)(fVar24 == fVar23) << 0x1e;
                in_fpscr = uVar1 | (uint)(NAN(fVar24) || NAN(fVar23)) << 0x1c;
                bVar3 = (byte)(uVar1 >> 0x18);
                if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
                  fVar24 = (local_90 - local_78._4_4_) + local_88._4_4_;
                  in_fpscr = uVar20;
                  if ((fVar24 < fVar22) &&
                     (uVar1 = uVar20 | (uint)(fVar24 < fVar23) << 0x1f |
                              (uint)(fVar24 == fVar23) << 0x1e,
                     in_fpscr = uVar1 | (uint)(NAN(fVar24) || NAN(fVar23)) << 0x1c,
                     bVar3 = (byte)(uVar1 >> 0x18),
                     !(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1))) {
                    fVar24 = (local_8c - local_70) + local_80;
                    uVar20 = uVar20 | (uint)(fVar24 < fVar23) << 0x1f |
                             (uint)(fVar24 == fVar23) << 0x1e;
                    in_fpscr = uVar20 | (uint)(NAN(fVar24) || NAN(fVar23)) << 0x1c;
                    bVar3 = (byte)(uVar20 >> 0x18);
                    if (!bVar4 && (fVar24 < fVar22 &&
                                  (!(bool)(bVar3 >> 6 & 1) &&
                                  bVar3 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)))) goto LAB_0017e40a;
                  }
                }
              }
            }
            else {
LAB_0017e350:
              if ((char)piVar12[0xf] == '\0') goto LAB_0017e366;
              iVar19 = (**(code **)(*piVar12 + 0x40))(piVar12,&local_78);
              if (iVar19 == 0) {
                bVar4 = true;
                goto LAB_0017e368;
              }
LAB_0017e40a:
              iVar9 = Player::isAsteroid(this_02);
              if (iVar9 != 1) {
                if (!bVar5) goto LAB_0017e434;
                iVar17 = *(int *)(this_02 + 0x40);
                fVar22 = (float)VectorSignedToFloat(iVar17,(byte)(in_fpscr >> 0x16) & 3);
                fVar24 = (local_94 - (float)local_78) + (float)local_88;
                if ((fVar24 < fVar22) &&
                   (fVar23 = (float)VectorSignedToFloat(-iVar17,(byte)((in_fpscr & 0xfffffff) >>
                                                                      0x16) & 3), fVar23 < fVar24))
                {
                  fVar24 = (local_90 - local_78._4_4_) + local_88._4_4_;
                  if (((int)((uint)(fVar24 < fVar22) << 0x1f) < 0) &&
                     (((fVar23 < fVar24 &&
                       (fVar24 = (local_8c - local_70) + local_80,
                       (int)((uint)(fVar24 < fVar22) << 0x1f) < 0)) && (fVar23 < fVar24))))
                  goto LAB_0017e7aa;
                }
                iVar17 = *(int *)(this + 0x18);
                AbyssEngine::AEMath::operator-
                          ((AEMath *)aVStack_10c,(Vector *)&local_94,(Vector *)&local_78);
                AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_d0,aVStack_10c);
                fVar22 = (float)AbyssEngine::AEMath::Vector::operator=
                                          ((Vector *)(iVar17 + uVar21 * 0xc),(Vector *)&local_d0);
                iVar17 = *(int *)(this + 0xc);
                fVar22 = (float)AbyssEngine::AEMath::operator*
                                          ((AEMath *)aVStack_10c,
                                           (Vector *)(*(int *)(this + 0x18) + uVar21 * 0xc),fVar22);
                AbyssEngine::AEMath::operator*((AEMath *)&local_d0,aVStack_10c,fVar22);
                AbyssEngine::AEMath::Vector::operator+=
                          ((Vector *)(iVar17 + uVar21 * 0xc),(Vector *)&local_d0);
                goto LAB_0017e80c;
              }
              if (bVar5) goto LAB_0017e6cc;
              Player::setBombForce(this_02,extraout_s0);
              if (bVar7) {
                Player::damage(this_02,9999,false,*(int *)(this + 0x58));
                iVar17 = Achievements::hasMedal(Globals::achievements,0x29,1);
                if ((iVar17 == 0) &&
                   ((iVar17 = *(int *)(this + 0x5c), iVar17 - 4U < 2 ||
                    (iVar17 == 0x28 || iVar17 == 0x22)))) {
                  iVar9 = *(int *)(Globals::status + 300) + 1;
                  *(int *)(Globals::status + 300) = iVar9;
                  iVar17 = Achievements::getValue(Globals::achievements,0x29,1);
                  if (iVar17 <= iVar9) {
                    pPVar15 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x38));
                    iVar17 = PlayerEgo::getHUD(pPVar15);
                    Hud::hudEventMedal(iVar17,0x29);
                    *(undefined1 *)(Globals::status + 0x130) = 1;
                  }
                }
                else if ((*(int *)(this + 0x58) == 0xb3) &&
                        (iVar17 = Achievements::hasMedal(Globals::achievements,0x2c,1), iVar17 == 0)
                        ) {
                  iVar9 = *(int *)(Globals::status + 0x144) + 1;
                  *(int *)(Globals::status + 0x144) = iVar9;
                  iVar17 = Achievements::getValue(Globals::achievements,0x2c,1);
                  if (iVar17 <= iVar9) {
                    pPVar15 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x38));
                    iVar17 = PlayerEgo::getHUD(pPVar15);
                    Hud::hudEventMedal(iVar17,0x2c);
                    *(undefined1 *)(Globals::status + 0x148) = 1;
                  }
                }
                goto LAB_0017e80c;
              }
LAB_0017e434:
              if ((bool)(bVar6 | bVar5)) {
LAB_0017e7aa:
                ignite(this);
                goto LAB_0017e80c;
              }
              if (*(int *)(this + 100) != -0x3a6687db) {
                Player::damageEmp(this_02,*(int *)(this + 100),(bool)this[0xf9]);
              }
              if ((*(int *)(this + 4) == 0) || (*(char *)(*(int *)(this + 4) + 0x5c) != '\0')) {
                if ((this_02[0x69] != (Player)0x0) &&
                   (iVar9 = Level::getPlayer(*(Level **)(this + 0x38)), iVar9 != 0)) {
                  pPVar15 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x38));
                  iVar9 = PlayerEgo::isDockedToDockingPoint(pPVar15);
                  if (iVar9 == 1) {
                    fVar22 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x60),
                                                        (byte)(in_fpscr >> 0x16) & 3);
                    fVar22 = fVar22 * 3.0 * 0.25;
                    goto LAB_0017e4a8;
                  }
                }
LAB_0017e4ba:
                iVar19 = *(int *)(this + 0x58);
                iVar9 = *(int *)(this + 0x60);
                GVar16 = this[0xf9];
              }
              else {
                if (this_02[0x69] == (Player)0x0) goto LAB_0017e4ba;
                fVar22 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x60),
                                                    (byte)(in_fpscr >> 0x16) & 3);
                fVar22 = fVar22 * 0.2;
LAB_0017e4a8:
                iVar19 = *(int *)(this + 0x58);
                GVar16 = this[0xf9];
                iVar9 = (int)fVar22;
              }
              Player::damage(this_02,iVar9,(bool)GVar16,iVar19);
              this_02[0x54] = (Player)0x1;
              if (this[0xf0] != (Gun)0x0) {
                *(undefined1 *)(*(int *)(this + 0x38) + 0x30) = 1;
              }
              Player::setHitVector(this_02,extraout_s0_00,extraout_s1,extraout_s2);
              *(undefined4 *)(*(int *)(this + 0x3c) + uVar21 * 4) = 0xfff0bdc0;
              uVar13 = Player::getKIPlayer(this_02);
              *(undefined4 *)this = uVar13;
              if (bVar7) {
                ParticleSystemManager::emitManual
                          (*(ParticleSystemManager **)(*(int *)(this + 0x38) + 0x74),
                           *(int *)(*(int *)(this + 0x38) + 0x3c),(Vector *)&local_78,0,
                           (Vector *)&local_88,extraout_s0_01);
              }
              else if (*(int *)(this + 0x10c) != 0) {
                uVar13 = AbyssEngine::PaintCanvas::TransformGetTransform
                                   (Globals::Canvas,*(uint *)(*(int *)(this + 0x10c) + uVar21 * 4));
                AbyssEngine::Transform::SetAnimationState(uVar13,3,0);
                uVar13 = AbyssEngine::PaintCanvas::TransformGetTransform
                                   (Globals::Canvas,*(uint *)(*(int *)(this + 0x10c) + uVar21 * 4));
                AbyssEngine::Transform::SetAnimationState(uVar13,1,0);
                this_00 = Globals::Canvas;
                uVar20 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
                puVar14 = (undefined4 *)AbyssEngine::PaintCanvas::CameraGetLocal(this_00,uVar20);
                local_d0 = *puVar14;
                uStack_cc = puVar14[1];
                uStack_c8 = puVar14[2];
                uStack_c4 = puVar14[3];
                uStack_c0 = puVar14[4];
                local_bc = puVar14[5];
                uStack_b8 = puVar14[6];
                uStack_b4 = puVar14[7];
                uStack_b0 = puVar14[8];
                uStack_ac = puVar14[9];
                local_a8 = puVar14[10];
                uStack_a4 = puVar14[0xb];
                uStack_a0 = puVar14[0xc];
                uStack_9c = puVar14[0xd];
                uStack_98 = puVar14[0xe];
                AbyssEngine::AEMath::MatrixSetTranslation
                          ((AEMath *)aVStack_10c,(Matrix *)&local_d0,local_70,extraout_s1_00,
                           extraout_s2_00);
                AbyssEngine::PaintCanvas::TransformSetLocal
                          (Globals::Canvas,*(uint *)(*(int *)(this + 0x10c) + uVar21 * 4),
                           (Matrix *)&local_d0);
              }
              if (*(Sparks **)(this + 0xb8) != (Sparks *)0x0) {
                iVar9 = Sparks::isRocket(*(Sparks **)(this + 0xb8));
                if (iVar9 == 1) {
                  this_02[0x55] = (Player)0x1;
                }
                if (*(Sparks **)(this + 0xb8) != (Sparks *)0x0) {
                  Sparks::explode(*(Sparks **)(this + 0xb8),(Vector *)&local_78);
                }
              }
              if (iVar17 == 0x19) {
                *(undefined1 *)(*(int *)(this + 0x40) + uVar21) = 1;
                AbyssEngine::AEMath::Vector::operator=
                          ((Vector *)(*(int *)(this + 0x30) + uVar21 * 0xc),(Vector *)&local_78);
                puVar8 = *(uint **)(this + 0xb4);
                if (*puVar8 != 0) {
                  uVar20 = 0;
                  do {
                    this_02 = *(Player **)(puVar8[1] + uVar20 * 4);
                    Player::getPosition();
                    AbyssEngine::AEMath::Vector::operator=(this_01,(Vector *)&local_d0);
                    AbyssEngine::AEMath::Vector::operator-=(this_01,(Vector *)&local_78);
                    fVar22 = (float)AbyssEngine::AEMath::VectorLength(this_01);
                    iVar9 = *(int *)(this + 0x100);
                    if ((int)fVar22 < iVar9) {
                      fVar24 = (float)VectorSignedToFloat(iVar9,(byte)(in_fpscr >> 0x16) & 3);
                      fVar23 = (float)VectorSignedToFloat(iVar9 - (int)fVar22,
                                                          (byte)(in_fpscr >> 0x16) & 3);
                      fVar23 = fVar23 / fVar24;
                      uVar1 = in_fpscr & 0xfffffff;
                      uVar2 = uVar1 | (uint)(fVar23 < 1.0) << 0x1f | (uint)(fVar23 == 1.0) << 0x1e;
                      in_fpscr = uVar2 | (uint)NAN(fVar23) << 0x1c;
                      bVar3 = (byte)(uVar2 >> 0x18);
                      fVar22 = 1.0;
                      if (((bool)(bVar3 >> 6 & 1) || bVar3 >> 7 != ((byte)(in_fpscr >> 0x1c) & 1))
                         && (in_fpscr = uVar1, fVar22 = fVar23, fVar23 < 0.0)) {
                        fVar22 = 0.0;
                      }
                      fVar24 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x60),
                                                          (byte)(in_fpscr >> 0x16) & 3);
                      Player::damage(this_02,(int)(fVar22 * fVar24),(bool)this[0xf9],
                                     *(int *)(this + 0x58));
                      if (0 < *(int *)(this + 100)) {
                        fVar24 = (float)VectorSignedToFloat(*(int *)(this + 100),
                                                            (byte)(in_fpscr >> 0x16) & 3);
                        Player::damageEmp(this_02,(int)(fVar22 * fVar24),(bool)this[0xf9]);
                      }
                    }
                    puVar8 = *(uint **)(this + 0xb4);
                    uVar20 = uVar20 + 1;
                  } while (uVar20 < *puVar8);
                }
              }
            }
LAB_0017e6cc:
            uVar21 = uVar21 + 1;
          } while (uVar21 < *(uint *)(this + 8));
        }
        puVar8 = *(uint **)(this + 0xb4);
        uVar18 = uVar18 + 1;
      } while (uVar18 < *puVar8);
    }
  }
LAB_0017e80c:
  if (__stack_chk_guard != local_6c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Gun::calcLevelCollision  @0x0017e93c  (2 bytes)
/* Gun::calcLevelCollision() */

void Gun::calcLevelCollision(void)

{
  return;
}

// ===== Gun::update  @0x0017e940  (574 bytes)
/* Gun::update(int) */

void __thiscall Gun::update(Gun *this,int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint in_fpscr;
  float fVar5;
  undefined4 extraout_s1;
  undefined8 uVar6;
  ulonglong unaff_d10;
  longlong lVar7;
  AEMath aAStack_5c [12];
  AEMath aAStack_50 [12];
  int local_44;
  
  local_44 = __stack_chk_guard;
  *(int *)(this + 0x6c) = *(int *)(this + 0x6c) + param_1;
  if ((this[0xa9] != (Gun)0x0) &&
     (iVar1 = *(int *)(this + 0x70), *(int *)(this + 0x70) = iVar1 + param_1,
     *(int *)(this + 0x48) <= iVar1 + param_1)) {
    this[0xa9] = (Gun)0x0;
  }
  if (*(Sparks **)(this + 0xb8) != (Sparks *)0x0) {
    Sparks::update(*(Sparks **)(this + 0xb8),param_1);
  }
  if ((*(uint **)(this + 0x10c) != (uint *)0x0) && (*(int *)(this + 8) != 0)) {
    lVar7 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,**(uint **)(this + 0x10c));
    AbyssEngine::Transform::Update(lVar7,SUB41(param_1,0));
    if (1 < *(uint *)(this + 8)) {
      uVar4 = 1;
      do {
        lVar7 = AbyssEngine::PaintCanvas::TransformGetTransform
                          (Globals::Canvas,*(uint *)(*(int *)(this + 0x10c) + uVar4 * 4));
        AbyssEngine::Transform::Update(lVar7,SUB41(param_1,0));
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(this + 8));
    }
  }
  if (((this[0x4c] != (Gun)0x0) && (*(int *)(this + 0x5c) != 0x27)) &&
     (calcCharacterCollision(this), *(int *)(this + 8) != 0)) {
    iVar1 = 0;
    uVar4 = 0;
    fVar5 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    do {
      iVar2 = *(int *)(*(int *)(this + 0x3c) + uVar4 * 4);
      if ((*(int *)(this + 0x5c) - 4U < 2) || (*(int *)(this + 0x5c) == 0x28)) {
        iVar3 = -2000;
      }
      else {
        iVar3 = 0;
      }
      if (iVar3 < iVar2) {
        *(int *)(*(int *)(this + 0x3c) + uVar4 * 4) = iVar2 - param_1;
        iVar2 = *(int *)(this + 0xc);
        if (*(int *)(this + 0x5c) == 0xb) {
          AbyssEngine::AEMath::operator*(aAStack_5c,(Vector *)(*(int *)(this + 0x18) + iVar1),fVar5)
          ;
          fVar5 = (float)VectorSignedToFloat(*(int *)(this + 0x44) -
                                             *(int *)(*(int *)(this + 0x3c) + uVar4 * 4),
                                             (byte)(in_fpscr >> 0x16) & 3);
          uVar6 = FloatVectorMax(CONCAT44(extraout_s1,fVar5 / -500.0 + 1.0),
                                 unaff_d10 & 0xffffffff00000000,2,0x20);
          AbyssEngine::AEMath::operator*(aAStack_50,(Vector *)aAStack_5c,(float)uVar6);
        }
        else {
          AbyssEngine::AEMath::operator*(aAStack_50,(Vector *)(*(int *)(this + 0x18) + iVar1),fVar5)
          ;
        }
        fVar5 = (float)AbyssEngine::AEMath::Vector::operator+=
                                 ((Vector *)(iVar2 + iVar1),(Vector *)aAStack_50);
        iVar2 = *(int *)(*(int *)(this + 0x3c) + uVar4 * 4);
        if (iVar2 < 1) {
          if ((*(int *)(this + 0x5c) - 6U < 0x1d) &&
             ((1 << (*(int *)(this + 0x5c) - 6U & 0xff) & 0x10000003U) != 0)) {
            fVar5 = (float)ignite(this);
            iVar2 = *(int *)(*(int *)(this + 0x3c) + uVar4 * 4);
          }
          if (-2000 < iVar2) goto LAB_0017eb44;
          iVar2 = *(int *)(this + 0x5c);
          if ((iVar2 - 4U < 2) || (iVar2 == 0x28)) {
            *(undefined4 *)(Globals::status + 300) = 0;
            goto LAB_0017eb44;
          }
        }
        else {
LAB_0017eb44:
          iVar2 = *(int *)(this + 0x5c);
        }
        if (iVar2 == 0x2a) {
          fVar5 = (float)ignite(this);
        }
      }
      else {
        iVar2 = *(int *)(this + 0xc);
        *(undefined4 *)(iVar2 + iVar1) = 0x47435000;
        iVar2 = iVar2 + iVar1;
        *(undefined4 *)(iVar2 + 4) = 0x47435000;
        *(undefined4 *)(iVar2 + 8) = 0x47435000;
        iVar2 = *(int *)(this + 0x18);
        *(undefined4 *)(iVar2 + iVar1) = 0;
        iVar2 = iVar2 + iVar1;
        *(undefined4 *)(iVar2 + 4) = 0;
        *(undefined4 *)(iVar2 + 8) = 0;
      }
      iVar1 = iVar1 + 0xc;
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(this + 8));
  }
  if (__stack_chk_guard != local_44) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Gun::render  @0x0017eb9c  (262 bytes)
/* Gun::render() */

void __thiscall Gun::render(Gun *this)

{
  PaintCanvas *this_00;
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  Matrix *pMVar4;
  uint uVar5;
  float extraout_s1;
  float extraout_s2;
  AEMath aAStack_a4 [60];
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (*(Sparks **)(this + 0xb8) != (Sparks *)0x0) {
    Sparks::render(*(Sparks **)(this + 0xb8));
  }
  iVar1 = *(int *)(this + 0x10c);
  if ((iVar1 != 0) && (*(int *)(this + 8) != 0)) {
    uVar5 = 0;
    while( true ) {
      iVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(iVar1 + uVar5 * 4));
      this_00 = Globals::Canvas;
      if (*(char *)(iVar1 + 0xed) != '\0') {
        uVar2 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
        puVar3 = (undefined4 *)AbyssEngine::PaintCanvas::CameraGetLocal(this_00,uVar2);
        local_68 = *puVar3;
        uStack_64 = puVar3[1];
        uStack_60 = puVar3[2];
        uStack_5c = puVar3[3];
        uStack_58 = puVar3[4];
        local_54 = puVar3[5];
        uStack_50 = puVar3[6];
        uStack_4c = puVar3[7];
        uStack_48 = puVar3[8];
        uStack_44 = puVar3[9];
        local_40 = puVar3[10];
        uStack_3c = puVar3[0xb];
        uStack_38 = puVar3[0xc];
        uStack_34 = puVar3[0xd];
        uStack_30 = puVar3[0xe];
        pMVar4 = (Matrix *)
                 AbyssEngine::PaintCanvas::TransformGetLocal
                           (Globals::Canvas,*(uint *)(*(int *)(this + 0x10c) + uVar5 * 4));
        AbyssEngine::AEMath::MatrixGetPosition(aAStack_a4,pMVar4);
        AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0xd8),(Vector *)aAStack_a4);
        AbyssEngine::AEMath::MatrixSetTranslation
                  (aAStack_a4,(Matrix *)&local_68,*(float *)(this + 0xe0),extraout_s1,extraout_s2);
        AbyssEngine::PaintCanvas::TransformSetLocal
                  (Globals::Canvas,*(uint *)(*(int *)(this + 0x10c) + uVar5 * 4),(Matrix *)&local_68
                  );
        AbyssEngine::PaintCanvas::DrawTransform
                  (Globals::Canvas,*(uint *)(*(int *)(this + 0x10c) + uVar5 * 4),(Matrix *)0x0);
      }
      uVar5 = uVar5 + 1;
      if (*(uint *)(this + 8) <= uVar5) break;
      iVar1 = *(int *)(this + 0x10c);
    }
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Gun::translate  @0x0017ecb4  (42 bytes)
/* Gun::translate(AbyssEngine::AEMath::Vector const&) */

void __thiscall Gun::translate(Gun *this,Vector *param_1)

{
  uint uVar1;
  int iVar2;
  
  if (*(int *)(this + 8) != 0) {
    iVar2 = 0;
    uVar1 = 0;
    do {
      AbyssEngine::AEMath::Vector::operator+=((Vector *)(*(int *)(this + 0xc) + iVar2),param_1);
      iVar2 = iVar2 + 0xc;
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(this + 8));
  }
  return;
}

