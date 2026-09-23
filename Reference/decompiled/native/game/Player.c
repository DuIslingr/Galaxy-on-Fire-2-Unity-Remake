// Class: Player
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Player::Player  @0x000aed60  (552 bytes)
/* Player::Player(int, int, int, int, int) */

void __thiscall
Player::Player(Player *this,int param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  Array *pAVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  AEMath aAStack_34 [12];
  int local_28;
  
  uVar1 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_28 = __stack_chk_guard;
  *(undefined4 *)(this + 4) = 0x3f800000;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = uVar1;
  *(undefined4 *)(this + 0x10) = uVar2;
  *(undefined4 *)(this + 0x14) = uVar3;
  *(undefined4 *)(this + 0x18) = 0x3f800000;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = uVar1;
  *(undefined4 *)(this + 0x24) = uVar2;
  *(undefined4 *)(this + 0x28) = uVar3;
  *(undefined8 *)(this + 0x2c) = 0x3f800000;
  *(undefined8 *)(this + 0x34) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0x3c) = 0x3f800000;
  *(undefined4 *)(this + 0xc4) = 0;
  *(undefined4 *)(this + 200) = 0;
  *(undefined4 *)(this + 0xcc) = 0;
  *(undefined4 *)(this + 0xfc) = 0;
  *(undefined4 *)(this + 0x100) = 0;
  *(undefined4 *)(this + 0x104) = 0;
  *(int *)(this + 0x40) = param_1;
  *(int *)(this + 0x78) = param_2;
  *(int *)(this + 0x84) = param_2;
  *(int *)(this + 0x9c) = param_3;
  *(int *)(this + 0xa0) = param_4;
  *(int *)(this + 0xa4) = param_5;
  *(undefined4 *)(this + 0xb8) = 0x42c80000;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  this[0x5e] = (Player)0x0;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x8c) = uVar1;
  *(undefined4 *)(this + 0x90) = uVar2;
  *(undefined4 *)(this + 0x94) = uVar3;
  this[0xc3] = (Player)0x1;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 0xd4) = 0;
  *(undefined4 *)(this + 0xd8) = 0;
  updateDamageRate(this);
  *(undefined4 *)(this + 0x58) = 0xffffffff;
  pAVar4 = operator_new(0xc);
  puVar5 = operator_new__(4);
  *(undefined4 **)(pAVar4 + 4) = puVar5;
  *(undefined4 *)(pAVar4 + 8) = 1;
  *puVar5 = 0;
  *(undefined4 *)pAVar4 = 0;
  *(Array **)this = pAVar4;
  ArraySetLength<Array<Gun*>*>(3,pAVar4);
  if (param_3 < 1) {
    **(undefined4 **)(*(int *)this + 4) = 0;
  }
  else {
    puVar5 = operator_new(0xc);
    puVar6 = operator_new__(4);
    puVar5[1] = puVar6;
    puVar5[2] = 1;
    *puVar6 = 0;
    *puVar5 = 0;
    **(undefined4 **)(*(int *)this + 4) = puVar5;
    ArraySetLength<Gun*>(param_3,(Array *)**(undefined4 **)(*(int *)this + 4));
  }
  if (param_4 < 1) {
    *(undefined4 *)(*(int *)(*(int *)this + 4) + 4) = 0;
  }
  else {
    puVar5 = operator_new(0xc);
    puVar6 = operator_new__(4);
    puVar5[1] = puVar6;
    puVar5[2] = 1;
    *puVar6 = 0;
    *puVar5 = 0;
    *(undefined4 **)(*(int *)(*(int *)this + 4) + 4) = puVar5;
    ArraySetLength<Gun*>(param_4,*(Array **)(*(int *)(*(int *)this + 4) + 4));
  }
  if (param_5 < 1) {
    *(undefined4 *)(*(int *)(*(int *)this + 4) + 8) = 0;
  }
  else {
    puVar5 = operator_new(0xc);
    puVar6 = operator_new__(4);
    puVar5[1] = puVar6;
    puVar5[2] = 1;
    *puVar6 = 0;
    *puVar5 = 0;
    *(undefined4 **)(*(int *)(*(int *)this + 4) + 8) = puVar5;
    ArraySetLength<Gun*>(param_5,*(Array **)(*(int *)(*(int *)this + 4) + 8));
  }
  *(undefined4 *)(this + 0xd0) = 0;
  this[0x70] = (Player)0x1;
  *(undefined4 *)(this + 0x10c) = 1;
  this[0x44] = (Player)0x0;
  this[0x45] = (Player)0x0;
  this[0x68] = (Player)0x0;
  this[0xc0] = (Player)0x1;
  this[0xc1] = (Player)0x0;
  *(undefined4 *)(this + 0xb4) = 0;
  this[0xc2] = (Player)0x1;
  *(undefined4 *)(this + 0xd4) = 0;
  this[0x5d] = (Player)0x0;
  this[0x5c] = (Player)0x0;
  this[0xe0] = (Player)0x0;
  this[0xec] = (Player)0x0;
  this[0xed] = (Player)0x0;
  *(undefined4 *)(this + 0x74) = 0;
  this[0x54] = (Player)0x0;
  this[0x55] = (Player)0x0;
  this[0x69] = (Player)0x0;
  this[0xee] = (Player)0x0;
  *(undefined4 *)(this + 0x110) = 0;
  *(undefined4 *)(this + 0xf0) = 0;
  this[0xf8] = (Player)0x0;
  this[0x108] = (Player)0x0;
  *(undefined4 *)(this + 100) = 0;
  AbyssEngine::AEMath::MatrixGetPosition(aAStack_34,this + 4);
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0xfc),(Vector *)aAStack_34);
  *(undefined4 *)(this + 0xf4) = 0xffffffff;
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== Player::updateDamageRate  @0x000aefc0  (130 bytes)
/* Player::updateDamageRate() */

void __thiscall Player::updateDamageRate(Player *this)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  
  fVar2 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x84),(byte)(in_fpscr >> 0x16) & 3);
  fVar1 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x78),(byte)(in_fpscr >> 0x16) & 3);
  *(int *)(this + 0x98) = (int)((fVar1 / fVar2) * 100.0);
  fVar1 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x94),(byte)(in_fpscr >> 0x16) & 3);
  *(int *)(this + 0xa8) = (int)((*(float *)(this + 0x88) / fVar1) * 100.0);
  fVar2 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x90),(byte)(in_fpscr >> 0x16) & 3);
  fVar1 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x8c),(byte)(in_fpscr >> 0x16) & 3);
  *(int *)(this + 0xac) = (int)((fVar1 / fVar2) * 100.0);
  fVar2 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x80),(byte)(in_fpscr >> 0x16) & 3);
  fVar1 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x7c),(byte)(in_fpscr >> 0x16) & 3);
  *(int *)(this + 0xb0) = (int)((fVar1 / fVar2) * 100.0);
  return;
}

// ===== Player::getPosition  @0x000af0b0  (12 bytes)
/* Player::getPosition() */

void Player::getPosition(void)

{
  AEMath *in_r0;
  int in_r1;
  
  AbyssEngine::AEMath::MatrixGetPosition(in_r0,(Matrix *)(in_r1 + 4));
  return;
}

// ===== Player::~Player  @0x000af0bc  (132 bytes)
/* Player::~Player() */

Player * __thiscall Player::~Player(Player *this)

{
  Array *pAVar1;
  int iVar2;
  Array *pAVar3;
  void *pvVar4;
  uint uVar5;
  
  pAVar1 = *(Array **)this;
  if (pAVar1 != (Array *)0x0) {
    if (*(int *)pAVar1 != 0) {
      uVar5 = 0;
      do {
        pAVar3 = *(Array **)(*(int *)(pAVar1 + 4) + uVar5 * 4);
        if (pAVar3 != (Array *)0x0) {
          ArrayReleaseClasses<Gun*>(pAVar3);
          iVar2 = *(int *)(*(int *)this + 4);
          pvVar4 = *(void **)(iVar2 + uVar5 * 4);
          if (pvVar4 != (void *)0x0) {
            if (*(void **)((int)pvVar4 + 4) != (void *)0x0) {
              operator_delete__(*(void **)((int)pvVar4 + 4));
            }
            operator_delete(pvVar4);
            iVar2 = *(int *)(*(int *)this + 4);
          }
          *(undefined4 *)(iVar2 + uVar5 * 4) = 0;
          pAVar1 = *(Array **)this;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)pAVar1);
    }
    ArrayReleaseClasses<Array<Gun*>*>(pAVar1);
    pvVar4 = *(void **)this;
    if (pvVar4 != (void *)0x0) {
      if (*(void **)((int)pvVar4 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar4 + 4));
      }
      operator_delete(pvVar4);
    }
    *(undefined4 *)this = 0;
  }
  pvVar4 = *(void **)(this + 0x74);
  if (pvVar4 != (void *)0x0) {
    if (*(void **)((int)pvVar4 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar4 + 4));
    }
    operator_delete(pvVar4);
  }
  *(undefined4 *)(this + 0x74) = 0;
  return this;
}

// ===== Player::setShootingEnabled  @0x000af1c8  (6 bytes)
/* Player::setShootingEnabled(bool) */

void __thiscall Player::setShootingEnabled(Player *this,bool param_1)

{
  this[0xc3] = (Player)param_1;
  return;
}

// ===== Player::isAsteroid  @0x000af1ce  (22 bytes)
/* Player::isAsteroid() */

bool __thiscall Player::isAsteroid(Player *this)

{
  if (*(int *)(this + 0xd0) != 0) {
    return *(char *)(*(int *)(this + 0xd0) + 0x38) != '\0';
  }
  return false;
}

// ===== Player::isGasCloud  @0x000af1e4  (22 bytes)
/* Player::isGasCloud() */

bool __thiscall Player::isGasCloud(Player *this)

{
  if (*(int *)(this + 0xd0) != 0) {
    return *(char *)(*(int *)(this + 0xd0) + 0x40) != '\0';
  }
  return false;
}

// ===== Player::setNeverAttack  @0x000af1fa  (6 bytes)
/* Player::setNeverAttack(bool) */

void __thiscall Player::setNeverAttack(Player *this,bool param_1)

{
  this[0xee] = (Player)param_1;
  return;
}

// ===== Player::doesNeverAttack  @0x000af200  (6 bytes)
/* Player::doesNeverAttack() */

Player __thiscall Player::doesNeverAttack(Player *this)

{
  return this[0xee];
}

// ===== Player::setAlwaysEnemy  @0x000af206  (16 bytes)
/* Player::setAlwaysEnemy(bool) */

void __thiscall Player::setAlwaysEnemy(Player *this,bool param_1)

{
  this[0xec] = (Player)param_1;
  *(undefined2 *)(this + 0x5c) = 1;
  this[0xe0] = (Player)0x1;
  return;
}

// ===== Player::setAlwaysFriend  @0x000af216  (20 bytes)
/* Player::setAlwaysFriend(bool) */

void __thiscall Player::setAlwaysFriend(Player *this,bool param_1)

{
  this[0xed] = (Player)param_1;
  *(undefined2 *)(this + 0x5c) = 0x100;
  this[0xe0] = (Player)0x0;
  return;
}

// ===== Player::isAlwaysFriend  @0x000af22a  (6 bytes)
/* Player::isAlwaysFriend() */

Player __thiscall Player::isAlwaysFriend(Player *this)

{
  return this[0xed];
}

// ===== Player::isAlwaysEnemy  @0x000af230  (6 bytes)
/* Player::isAlwaysEnemy() */

Player __thiscall Player::isAlwaysEnemy(Player *this)

{
  return this[0xec];
}

// ===== Player::setEmpData  @0x000af236  (34 bytes)
/* Player::setEmpData(int, int) */

void __thiscall Player::setEmpData(Player *this,int param_1,int param_2)

{
  *(int *)(this + 0x7c) = param_1;
  if (*(int *)(this + 0x80) < param_1) {
    *(int *)(this + 0x80) = param_1;
  }
  updateDamageRate(this);
  *(int *)(this + 0xe4) = param_2;
  return;
}

// ===== Player::setPlayShootSound  @0x000af258  (10 bytes)
/* Player::setPlayShootSound(bool, int) */

void __thiscall Player::setPlayShootSound(Player *this,bool param_1,int param_2)

{
  this[0x70] = (Player)param_1;
  *(int *)(this + 0x10c) = param_2;
  return;
}

// ===== Player::setRadius  @0x000af262  (4 bytes)
/* Player::setRadius(int) */

void __thiscall Player::setRadius(Player *this,int param_1)

{
  *(int *)(this + 0x40) = param_1;
  return;
}

// ===== Player::setKIPlayer  @0x000af266  (6 bytes)
/* Player::setKIPlayer(KIPlayer*) */

void __thiscall Player::setKIPlayer(Player *this,KIPlayer *param_1)

{
  *(KIPlayer **)(this + 0xd0) = param_1;
  return;
}

// ===== Player::getKIPlayer  @0x000af26c  (6 bytes)
/* Player::getKIPlayer() */

undefined4 __thiscall Player::getKIPlayer(Player *this)

{
  return *(undefined4 *)(this + 0xd0);
}

// ===== Player::reset  @0x000af272  (104 bytes)
/* Player::reset() */

void __thiscall Player::reset(Player *this)

{
  uint in_fpscr;
  undefined4 uVar1;
  
  *(undefined4 *)(this + 0xb8) = 0x42c80000;
  *(undefined4 *)(this + 0x78) = *(undefined4 *)(this + 0x84);
  uVar1 = VectorSignedToFloat(*(undefined4 *)(this + 0x94),(byte)(in_fpscr >> 0x16) & 3);
  *(undefined4 *)(this + 0x88) = uVar1;
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(this + 0x80);
  updateDamageRate(this);
  this[0xc0] = (Player)0x1;
  this[0xc1] = (Player)0x0;
  this[0xc2] = (Player)0x1;
  this[0x54] = (Player)0x0;
  this[0x55] = (Player)0x0;
  this[0x44] = (Player)0x0;
  *(undefined4 *)(this + 0x6c) = 0;
  this[0x5e] = (Player)0x0;
  *(undefined4 *)(this + 0xb4) = 0;
  this[0x68] = (Player)0x0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0xd4) = 0;
  *(undefined4 *)(this + 0xd8) = 0;
  *(undefined4 *)(this + 0xdd) = 0;
  *(undefined4 *)(this + 0xd9) = 0;
  return;
}

// ===== Player::setEnemies  @0x000af2da  (160 bytes)
/* Player::setEnemies(Array<Player*>*) */

void __thiscall Player::setEnemies(Player *this,Array *param_1)

{
  int *piVar1;
  undefined4 *__ptr;
  uint *puVar2;
  Gun *this_00;
  int iVar3;
  uint *puVar4;
  size_t __size;
  uint uVar5;
  void *pvVar6;
  uint uVar7;
  undefined4 uVar8;
  
  pvVar6 = *(void **)(this + 0x74);
  if (pvVar6 != (void *)0x0) {
    if (*(void **)((int)pvVar6 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar6 + 4));
    }
    operator_delete(pvVar6);
  }
  *(undefined4 *)(this + 0x74) = 0;
  if (param_1 != (Array *)0x0) {
    piVar1 = operator_new(0xc);
    __ptr = operator_new__(4);
    piVar1[1] = (int)__ptr;
    *__ptr = 0;
    *piVar1 = 0;
    *(int **)(this + 0x74) = piVar1;
    iVar3 = *(int *)param_1;
    uVar8 = *(undefined4 *)(param_1 + 4);
    piVar1[2] = iVar3;
    __size = iVar3 << 2;
    pvVar6 = realloc(__ptr,__size);
    piVar1[1] = (int)pvVar6;
    __aeabi_memcpy4((void *)((int)pvVar6 + *piVar1 * 4),uVar8,__size);
    *piVar1 = piVar1[2];
  }
  puVar4 = *(uint **)this;
  if ((puVar4 != (uint *)0x0) && (*puVar4 != 0)) {
    uVar5 = 0;
    do {
      puVar2 = *(uint **)(puVar4[1] + uVar5 * 4);
      if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
        uVar7 = 0;
        do {
          this_00 = *(Gun **)(puVar2[1] + uVar7 * 4);
          if (this_00 != (Gun *)0x0) {
            Gun::setEnemies(this_00,*(Array **)(this + 0x74));
            puVar4 = *(uint **)this;
          }
          uVar7 = uVar7 + 1;
          puVar2 = *(uint **)(puVar4[1] + uVar5 * 4);
        } while (uVar7 < *puVar2);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *puVar4);
  }
  return;
}

// ===== Player::setEnemy  @0x000af388  (82 bytes)
/* Player::setEnemy(Player*) */

void __thiscall Player::setEnemy(Player *this,Player *param_1)

{
  Array *pAVar1;
  undefined4 *__ptr;
  void *pvVar2;
  
  pAVar1 = operator_new(0xc);
  __ptr = operator_new__(4);
  *(undefined4 **)(pAVar1 + 4) = __ptr;
  *__ptr = 0;
  *(undefined4 *)pAVar1 = 0;
  *(undefined4 *)(pAVar1 + 8) = 1;
  pvVar2 = realloc(__ptr,4);
  *(void **)(pAVar1 + 4) = pvVar2;
  *(Player **)((int)pvVar2 + *(int *)pAVar1 * 4) = param_1;
  *(undefined4 *)pAVar1 = *(undefined4 *)(pAVar1 + 8);
  setEnemies(this,pAVar1);
  if (*(void **)(pAVar1 + 4) != (void *)0x0) {
    operator_delete__(*(void **)(pAVar1 + 4));
  }
  operator_delete(pAVar1);
  return;
}

// ===== Player::addEnemies  @0x000af3e8  (194 bytes)
/* Player::addEnemies(Array<Player*>*) */

void __thiscall Player::addEnemies(Player *this,Array *param_1)

{
  Array *pAVar1;
  undefined4 *__ptr;
  int iVar2;
  int iVar3;
  uint *puVar4;
  undefined4 uVar5;
  uint uVar6;
  
  puVar4 = *(uint **)(this + 0x74);
  if (puVar4 == (uint *)0x0) {
    setEnemies(this,param_1);
    return;
  }
  pAVar1 = operator_new(0xc);
  __ptr = operator_new__(4);
  iVar3 = 0;
  *(undefined4 **)(pAVar1 + 4) = __ptr;
  *(undefined4 *)(pAVar1 + 8) = 1;
  *__ptr = 0;
  *(undefined4 *)pAVar1 = 0;
  if (*puVar4 != 0) {
    iVar3 = 0;
    uVar6 = 0;
    do {
      uVar5 = *(undefined4 *)(puVar4[1] + uVar6 * 4);
      *(int *)(pAVar1 + 8) = iVar3 + 1;
      __ptr = realloc(__ptr,(iVar3 + 1) * 4);
      uVar6 = uVar6 + 1;
      *(undefined4 **)(pAVar1 + 4) = __ptr;
      iVar2 = *(int *)pAVar1;
      iVar3 = *(int *)(pAVar1 + 8);
      *(int *)pAVar1 = iVar3;
      __ptr[iVar2] = uVar5;
      puVar4 = *(uint **)(this + 0x74);
    } while (uVar6 < *puVar4);
  }
  if (*(int *)param_1 != 0) {
    uVar6 = 0;
    do {
      uVar5 = *(undefined4 *)(*(int *)(param_1 + 4) + uVar6 * 4);
      *(int *)(pAVar1 + 8) = iVar3 + 1;
      __ptr = realloc(__ptr,(iVar3 + 1) * 4);
      uVar6 = uVar6 + 1;
      *(undefined4 **)(pAVar1 + 4) = __ptr;
      iVar2 = *(int *)pAVar1;
      iVar3 = *(int *)(pAVar1 + 8);
      *(int *)pAVar1 = iVar3;
      __ptr[iVar2] = uVar5;
    } while (uVar6 < *(uint *)param_1);
  }
  setEnemies(this,pAVar1);
  if (*(void **)(pAVar1 + 4) != (void *)0x0) {
    operator_delete__(*(void **)(pAVar1 + 4));
  }
  operator_delete(pAVar1);
  return;
}

// ===== Player::addEnemy  @0x000af4b8  (150 bytes)
/* Player::addEnemy(Player*) */

void __thiscall Player::addEnemy(Player *this,Player *param_1)

{
  Array *pAVar1;
  undefined4 *__ptr;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = *(int **)(this + 0x74);
  if (piVar5 == (int *)0x0) {
    setEnemy(this,param_1);
    return;
  }
  pAVar1 = operator_new(0xc);
  __ptr = operator_new__(4);
  iVar2 = 1;
  *(undefined4 **)(pAVar1 + 4) = __ptr;
  *(undefined4 *)(pAVar1 + 8) = 1;
  *__ptr = 0;
  *(undefined4 *)pAVar1 = 0;
  iVar4 = *piVar5;
  if (iVar4 != 0) {
    iVar2 = piVar5[1];
    *(int *)(pAVar1 + 8) = iVar4;
    __ptr = realloc(__ptr,iVar4 << 2);
    *(undefined4 **)(pAVar1 + 4) = __ptr;
    __aeabi_memcpy4(__ptr + *(int *)pAVar1,iVar2,iVar4 << 2);
    *(int *)pAVar1 = *(int *)(pAVar1 + 8);
    iVar2 = *(int *)(pAVar1 + 8) + 1;
  }
  *(int *)(pAVar1 + 8) = iVar2;
  pvVar3 = realloc(__ptr,iVar2 << 2);
  *(void **)(pAVar1 + 4) = pvVar3;
  *(Player **)((int)pvVar3 + *(int *)pAVar1 * 4) = param_1;
  *(undefined4 *)pAVar1 = *(undefined4 *)(pAVar1 + 8);
  setEnemies(this,pAVar1);
  if (*(void **)(pAVar1 + 4) != (void *)0x0) {
    operator_delete__(*(void **)(pAVar1 + 4));
  }
  operator_delete(pAVar1);
  return;
}

// ===== Player::getEnemies  @0x000af55a  (4 bytes)
/* Player::getEnemies() */

undefined4 __thiscall Player::getEnemies(Player *this)

{
  return *(undefined4 *)(this + 0x74);
}

// ===== Player::getEnemy  @0x000af55e  (10 bytes)
/* Player::getEnemy(int) */

undefined4 __thiscall Player::getEnemy(Player *this,int param_1)

{
  return *(undefined4 *)(*(int *)(*(int *)(this + 0x74) + 4) + param_1 * 4);
}

// ===== Player::getRadius  @0x000af568  (4 bytes)
/* Player::getRadius() */

undefined4 __thiscall Player::getRadius(Player *this)

{
  return *(undefined4 *)(this + 0x40);
}

// ===== Player::setHitpoints  @0x000af56c  (18 bytes)
/* Player::setHitpoints(int) */

void __thiscall Player::setHitpoints(Player *this,int param_1)

{
  *(int *)(this + 0x78) = param_1;
  if (*(int *)(this + 0x84) < param_1) {
    *(int *)(this + 0x84) = param_1;
  }
  updateDamageRate(this);
  return;
}

// ===== Player::setShieldHP  @0x000af57e  (38 bytes)
/* Player::setShieldHP(int) */

void __thiscall Player::setShieldHP(Player *this,int param_1)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  
  fVar2 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  *(float *)(this + 0x88) = fVar2;
  fVar1 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x94),(byte)(in_fpscr >> 0x16) & 3);
  if (fVar1 < fVar2) {
    *(float *)(this + 0x88) = fVar1;
  }
  updateDamageRate(this);
  return;
}

// ===== Player::setArmorHP  @0x000af5a4  (18 bytes)
/* Player::setArmorHP(int) */

void __thiscall Player::setArmorHP(Player *this,int param_1)

{
  if (*(int *)(this + 0x90) < param_1) {
    param_1 = *(int *)(this + 0x90);
  }
  *(int *)(this + 0x8c) = param_1;
  updateDamageRate(this);
  return;
}

// ===== Player::setGammaHP  @0x000af5b8  (48 bytes)
/* Player::setGammaHP(int) */

void __thiscall Player::setGammaHP(Player *this,int param_1)

{
  uint in_fpscr;
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  uVar2 = uVar1;
  if (param_1 != 9999999) {
    uVar2 = 0x42c80000;
  }
  if (100 < param_1) {
    uVar1 = uVar2;
  }
  *(undefined4 *)(this + 0xb8) = uVar1;
  updateDamageRate(this);
  return;
}

// ===== Player::setMaxEmpPoints  @0x000af5ec  (8 bytes)
/* Player::setMaxEmpPoints(int) */

void __thiscall Player::setMaxEmpPoints(Player *this,int param_1)

{
  *(int *)(this + 0x7c) = param_1;
  *(int *)(this + 0x80) = param_1;
  updateDamageRate(this);
  return;
}

// ===== Player::setMaxHitpoints  @0x000af5f4  (10 bytes)
/* Player::setMaxHitpoints(int) */

void __thiscall Player::setMaxHitpoints(Player *this,int param_1)

{
  *(int *)(this + 0x84) = param_1;
  *(int *)(this + 0x78) = param_1;
  updateDamageRate(this);
  return;
}

// ===== Player::setMaxShieldHP  @0x000af5fe  (20 bytes)
/* Player::setMaxShieldHP(int) */

void __thiscall Player::setMaxShieldHP(Player *this,int param_1)

{
  uint in_fpscr;
  undefined4 uVar1;
  
  uVar1 = VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  *(int *)(this + 0x94) = param_1;
  *(undefined4 *)(this + 0x88) = uVar1;
  updateDamageRate(this);
  return;
}

// ===== Player::setMaxArmorHP  @0x000af612  (8 bytes)
/* Player::setMaxArmorHP(int) */

void __thiscall Player::setMaxArmorHP(Player *this,int param_1)

{
  *(int *)(this + 0x8c) = param_1;
  *(int *)(this + 0x90) = param_1;
  updateDamageRate(this);
  return;
}

// ===== Player::getEmpPoints  @0x000af61a  (4 bytes)
/* Player::getEmpPoints() */

undefined4 __thiscall Player::getEmpPoints(Player *this)

{
  return *(undefined4 *)(this + 0x7c);
}

// ===== Player::getMaxEmpPoints  @0x000af61e  (6 bytes)
/* Player::getMaxEmpPoints() */

undefined4 __thiscall Player::getMaxEmpPoints(Player *this)

{
  return *(undefined4 *)(this + 0x80);
}

// ===== Player::getMaxShieldHP  @0x000af624  (6 bytes)
/* Player::getMaxShieldHP() */

undefined4 __thiscall Player::getMaxShieldHP(Player *this)

{
  return *(undefined4 *)(this + 0x94);
}

// ===== Player::getShieldHP  @0x000af62a  (14 bytes)
/* Player::getShieldHP() */

int __thiscall Player::getShieldHP(Player *this)

{
  return (int)*(float *)(this + 0x88);
}

// ===== Player::getCombinedHP  @0x000af638  (38 bytes)
/* Player::getCombinedHP() */

int __thiscall Player::getCombinedHP(Player *this)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  
  fVar2 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x8c),(byte)(in_fpscr >> 0x16) & 3);
  fVar1 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x78),(byte)(in_fpscr >> 0x16) & 3);
  return (int)(*(float *)(this + 0x88) + fVar2 + fVar1);
}

// ===== Player::getArmorHP  @0x000af65e  (6 bytes)
/* Player::getArmorHP() */

undefined4 __thiscall Player::getArmorHP(Player *this)

{
  return *(undefined4 *)(this + 0x8c);
}

// ===== Player::getMaxArmorHP  @0x000af664  (6 bytes)
/* Player::getMaxArmorHP() */

undefined4 __thiscall Player::getMaxArmorHP(Player *this)

{
  return *(undefined4 *)(this + 0x90);
}

// ===== Player::getGammaHP  @0x000af66a  (14 bytes)
/* Player::getGammaHP() */

int __thiscall Player::getGammaHP(Player *this)

{
  return (int)*(float *)(this + 0xb8);
}

// ===== Player::regenerateShield  @0x000af678  (42 bytes)
/* Player::regenerateShield(float) */

void __thiscall Player::regenerateShield(Player *this,float param_1)

{
  float in_r1;
  uint in_fpscr;
  float fVar1;
  
  fVar1 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x94),(byte)(in_fpscr >> 0x16) & 3);
  if ((int)((uint)(*(float *)(this + 0x88) + in_r1 < fVar1) << 0x1f) < 0) {
    fVar1 = *(float *)(this + 0x88) + in_r1;
  }
  *(float *)(this + 0x88) = fVar1;
  updateDamageRate(this);
  return;
}

// ===== Player::regenerateShield  @0x000af6a2  (42 bytes)
/* Player::regenerateShield() */

void __thiscall Player::regenerateShield(Player *this)

{
  uint in_fpscr;
  float fVar1;
  
  fVar1 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x94),(byte)(in_fpscr >> 0x16) & 3);
  if ((int)((uint)(*(float *)(this + 0x88) + 1.0 < fVar1) << 0x1f) < 0) {
    fVar1 = *(float *)(this + 0x88) + 1.0;
  }
  *(float *)(this + 0x88) = fVar1;
  updateDamageRate(this);
  return;
}

// ===== Player::regenerateArmor  @0x000af6cc  (20 bytes)
/* Player::regenerateArmor() */

void __thiscall Player::regenerateArmor(Player *this)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x8c) + 2;
  if (*(int *)(this + 0x90) < *(int *)(this + 0x8c) + 2) {
    iVar1 = *(int *)(this + 0x90);
  }
  *(int *)(this + 0x8c) = iVar1;
  updateDamageRate(this);
  return;
}

// ===== Player::regenerateHull  @0x000af6e0  (20 bytes)
/* Player::regenerateHull() */

void __thiscall Player::regenerateHull(Player *this)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x84);
  if (*(int *)(this + 0x78) + 1 < *(int *)(this + 0x84)) {
    iVar1 = *(int *)(this + 0x78) + 1;
  }
  *(int *)(this + 0x78) = iVar1;
  updateDamageRate(this);
  return;
}

// ===== Player::getHitpoints  @0x000af6f4  (4 bytes)
/* Player::getHitpoints() */

undefined4 __thiscall Player::getHitpoints(Player *this)

{
  return *(undefined4 *)(this + 0x78);
}

// ===== Player::getMaxHitpoints  @0x000af6f8  (6 bytes)
/* Player::getMaxHitpoints() */

undefined4 __thiscall Player::getMaxHitpoints(Player *this)

{
  return *(undefined4 *)(this + 0x84);
}

// ===== Player::getDamageRate  @0x000af6fe  (6 bytes)
/* Player::getDamageRate() */

undefined4 __thiscall Player::getDamageRate(Player *this)

{
  return *(undefined4 *)(this + 0x98);
}

// ===== Player::getEmpDamageRate  @0x000af704  (6 bytes)
/* Player::getEmpDamageRate() */

undefined4 __thiscall Player::getEmpDamageRate(Player *this)

{
  return *(undefined4 *)(this + 0xb0);
}

// ===== Player::getShieldDamageRate  @0x000af70a  (6 bytes)
/* Player::getShieldDamageRate() */

undefined4 __thiscall Player::getShieldDamageRate(Player *this)

{
  return *(undefined4 *)(this + 0xa8);
}

// ===== Player::getArmorDamageRate  @0x000af710  (6 bytes)
/* Player::getArmorDamageRate() */

undefined4 __thiscall Player::getArmorDamageRate(Player *this)

{
  return *(undefined4 *)(this + 0xac);
}

// ===== Player::setVulnerable  @0x000af716  (6 bytes)
/* Player::setVulnerable(bool) */

void __thiscall Player::setVulnerable(Player *this,bool param_1)

{
  this[0xc2] = (Player)param_1;
  return;
}

// ===== Player::setHitVector  @0x000af71c  (6 bytes)
/* Player::setHitVector(float, float, float) */

Player * __thiscall Player::setHitVector(Player *this,float param_1,float param_2,float param_3)

{
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  
  *(undefined4 *)(this + 0xc4) = in_r1;
  *(undefined4 *)(this + 200) = in_r2;
  *(undefined4 *)(this + 0xcc) = in_r3;
  return this + 0xd0;
}

// ===== Player::setBombForce  @0x000af722  (6 bytes)
/* Player::setBombForce(float) */

void __thiscall Player::setBombForce(Player *this,float param_1)

{
  undefined4 in_r1;
  
  *(undefined4 *)(this + 0xd4) = in_r1;
  return;
}

// ===== Player::setEmpForce  @0x000af728  (6 bytes)
/* Player::setEmpForce(float) */

void __thiscall Player::setEmpForce(Player *this,float param_1)

{
  undefined4 in_r1;
  
  *(undefined4 *)(this + 0xd8) = in_r1;
  return;
}

// ===== Player::getBombForce  @0x000af72e  (6 bytes)
/* Player::getBombForce() */

undefined4 __thiscall Player::getBombForce(Player *this)

{
  return *(undefined4 *)(this + 0xd4);
}

// ===== Player::getEmpForce  @0x000af734  (6 bytes)
/* Player::getEmpForce() */

undefined4 __thiscall Player::getEmpForce(Player *this)

{
  return *(undefined4 *)(this + 0xd8);
}

// ===== Player::getHitVector  @0x000af73a  (16 bytes)
/* Player::getHitVector() */

void Player::getHitVector(void)

{
  undefined8 *in_r0;
  int in_r1;
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(in_r1 + 0xc4);
  *(undefined4 *)(in_r0 + 1) = *(undefined4 *)(in_r1 + 0xcc);
  *in_r0 = uVar1;
  return;
}

// ===== Player::getGunRegenRate  @0x000af74a  (4 bytes)
/* Player::getGunRegenRate(int) */

undefined4 Player::getGunRegenRate(int param_1)

{
  return 0;
}

// ===== Player::damageHull  @0x000af74e  (64 bytes)
/* Player::damageHull(int) */

void __thiscall Player::damageHull(Player *this,int param_1)

{
  int iVar1;
  uint uVar2;
  
  if ((this[0xc2] != (Player)0x0) && (this[0xc0] != (Player)0x0)) {
    uVar2 = *(uint *)(this + 0x8c);
    if ((int)uVar2 < 1) {
      iVar1 = *(int *)(this + 0x78) - param_1;
      if (iVar1 < 0) {
        iVar1 = 0;
      }
      *(int *)(this + 0x78) = iVar1;
    }
    else {
      uVar2 = uVar2 - param_1;
      *(uint *)(this + 0x8c) = uVar2;
    }
    if (0x7fffffff < uVar2) {
      *(undefined4 *)(this + 0x8c) = 0;
    }
    this[0xc1] = (Player)0x1;
    updateDamageRate(this);
    return;
  }
  return;
}

// ===== Player::damageShip  @0x000af78e  (14 bytes)
/* Player::damageShip(int) */

void __thiscall Player::damageShip(Player *this,int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x78) - param_1;
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  *(int *)(this + 0x78) = iVar1;
  return;
}

// ===== Player::damageShield  @0x000af79c  (84 bytes)
/* Player::damageShield(int) */

void __thiscall Player::damageShield(Player *this,int param_1)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint in_fpscr;
  float fVar4;
  float fVar5;
  
  if ((this[0xc2] != (Player)0x0) && (this[0xc0] != (Player)0x0)) {
    fVar4 = *(float *)(this + 0x88);
    uVar1 = in_fpscr & 0xfffffff | (uint)(fVar4 == 0.0) << 0x1e | (uint)(0.0 <= fVar4) << 0x1d;
    bVar2 = (byte)(uVar1 >> 0x18);
    if (!(bool)(bVar2 >> 5 & 1) || (bool)(bVar2 >> 6)) {
      iVar3 = *(int *)(this + 0x78) - param_1;
      if (iVar3 < 0) {
        iVar3 = 0;
      }
      *(int *)(this + 0x78) = iVar3;
    }
    else {
      fVar5 = (float)VectorSignedToFloat(param_1,(byte)(uVar1 >> 0x16) & 3);
      fVar4 = fVar4 - fVar5;
      *(float *)(this + 0x88) = fVar4;
    }
    if ((int)((uint)(fVar4 < 0.0) << 0x1f) < 0) {
      *(undefined4 *)(this + 0x88) = 0;
    }
    this[0xc1] = (Player)0x1;
    updateDamageRate(this);
    return;
  }
  return;
}

// ===== Player::damageGamma  @0x000af7f0  (52 bytes)
/* Player::damageGamma(float) */

float __thiscall Player::damageGamma(Player *this,float param_1)

{
  float in_r1;
  
  if ((this[0xc2] != (Player)0x0) && (this[0xc0] != (Player)0x0)) {
    this[0x67] = (Player)0x1;
    param_1 = *(float *)(this + 0xb8) - in_r1;
    *(float *)(this + 0xb8) = param_1;
    if (0.0 > param_1 || param_1 == 0.0) {
      *(uint *)(this + 0xb8) = (uint)(0.0 <= param_1 && param_1 != 0.0);
    }
  }
  return param_1;
}

// ===== Player::resetDamageDoneByPlayer  @0x000af824  (14 bytes)
/* Player::resetDamageDoneByPlayer() */

void __thiscall Player::resetDamageDoneByPlayer(Player *this)

{
  *(undefined4 *)(this + 0xdc) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  this[0xe0] = (Player)0x0;
  return;
}

// ===== Player::damageEmp  @0x000af834  (530 bytes)
/* Player::damageEmp(int, bool) */

void __thiscall Player::damageEmp(Player *this,int param_1,bool param_2)

{
  ushort uVar1;
  int iVar2;
  KIPlayer *this_00;
  SolarSystem *pSVar3;
  Standing *this_01;
  PlayerEgo *this_02;
  int iVar4;
  uint in_fpscr;
  undefined4 uVar5;
  
  if ((this[0xc2] == (Player)0x0) || (this[0xc0] == (Player)0x0)) {
    return;
  }
  iVar2 = *(int *)(this + 0x7c);
  if (0 < iVar2) {
    iVar2 = *(int *)(this + 0x78);
  }
  if (iVar2 < 1) {
    return;
  }
  if (((param_2) || (this_00 = *(KIPlayer **)(this + 0xd0), this_00 == (KIPlayer *)0x0)) ||
     (this[0xec] != (Player)0x0)) goto LAB_000af918;
  if (1 < *(int *)(this_00 + 0x24) - 9U) {
    iVar2 = Status::getSystem(Globals::status);
    this_00 = *(KIPlayer **)(this + 0xd0);
    if ((iVar2 != 0) && (this_00[0x3e] != (KIPlayer)0x0)) {
      if (0 < param_1) {
        Level::attackWanted(*(Level **)(this_00 + 0x50),*(int *)(this_00 + 0x44));
      }
      goto LAB_000af918;
    }
    if (this_00 == (KIPlayer *)0x0) goto LAB_000af918;
  }
  if (((this[0xec] == (Player)0x0) && (iVar2 = KIPlayer::isWingMan(this_00), iVar2 == 0)) &&
     ((1 < *(int *)(*(int *)(this + 0xd0) + 0x24) - 9U &&
      (iVar2 = Status::getSystem(Globals::status), iVar2 != 0)))) {
    iVar4 = *(int *)(*(int *)(this + 0xd0) + 0x24);
    pSVar3 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar2 = SolarSystem::getRace(pSVar3);
    if ((iVar4 == iVar2) &&
       (iVar2 = *(int *)(this + 0xdc), *(int *)(this + 0xdc) = iVar2 + param_1,
       *(int *)(this + 0x80) / 3 < iVar2 + param_1)) {
      this[0xe0] = (Player)0x1;
      Level::friendTurnedEnemy(*(int *)(*(int *)(this + 0xd0) + 0x50));
    }
  }
LAB_000af918:
  iVar2 = *(int *)(this + 0x7c);
  *(int *)(this + 0x7c) = iVar2 - param_1;
  if (iVar2 - param_1 < 1) {
    if ((!param_2) && (*(int *)(this + 0xd0) != 0)) {
      if ((this[0xec] == (Player)0x0) &&
         ((1 < *(int *)(*(int *)(this + 0xd0) + 0x24) - 9U &&
          (iVar2 = Status::getSystem(Globals::status), iVar2 != 0)))) {
        iVar4 = *(int *)(*(int *)(this + 0xd0) + 0x24);
        pSVar3 = (SolarSystem *)Status::getSystem(Globals::status);
        iVar2 = SolarSystem::getRace(pSVar3);
        if (iVar4 == iVar2) {
          Level::alarmAllFriends
                    (*(Level **)(*(int *)(this + 0xd0) + 0x50),
                     *(int *)(*(int *)(this + 0xd0) + 0x24),false);
        }
      }
      uVar1 = *(ushort *)(*(int *)(this + 0xd0) + 0x38);
      if ((((uVar1 & 0xff) == 0) && (uVar1 < 0x100)) &&
         (*(char *)(*(int *)(this + 0xd0) + 0x3e) == '\0')) {
        this_01 = (Standing *)Status::getStanding(Globals::status);
        Standing::applyDisable(this_01,*(int *)(*(int *)(this + 0xd0) + 0x24));
      }
      if ((*(int *)(this + 0xd0) != 0) && (this[0x68] == (Player)0x0)) {
        if (0x7fffffff < *(uint *)(Globals::status + 0x134)) {
          *(undefined4 *)(Globals::status + 0x134) = 0;
        }
        iVar2 = Achievements::hasMedal(Globals::achievements,0x2a,1);
        if (iVar2 == 0) {
          iVar4 = *(int *)(Globals::status + 0x134);
          *(int *)(Globals::status + 0x134) = iVar4 + 1;
          iVar2 = Achievements::getValue(Globals::achievements,0x2a,1);
          if (iVar2 <= iVar4 + 1) {
            this_02 = (PlayerEgo *)Level::getPlayer(*(Level **)(*(int *)(this + 0xd0) + 0x50));
            iVar2 = PlayerEgo::getHUD(this_02);
            Hud::hudEventMedal(iVar2,0x2a);
            Globals::status[0x138] = (Status)0x1;
          }
        }
      }
    }
    uVar5 = VectorSignedToFloat(*(undefined4 *)(this + 0xe4),(byte)(in_fpscr >> 0x16) & 3);
    *(undefined4 *)(this + 0xd8) = uVar5;
    this[0x68] = (Player)0x1;
    *(undefined4 *)(this + 0x7c) = 0;
    *(undefined4 *)(this + 0xe8) = 0;
  }
  updateDamageRate(this);
  return;
}

// ===== Player::damage  @0x000afa70  (1296 bytes)
/* Player::damage(int, bool, int) */

void __thiscall Player::damage(Player *this,int param_1,bool param_2,int param_3)

{
  ushort uVar1;
  byte bVar2;
  Status *pSVar3;
  char cVar4;
  int iVar5;
  KIPlayer *this_00;
  SolarSystem *pSVar6;
  Ship *pSVar7;
  uint uVar8;
  Item *pIVar9;
  Standing *pSVar10;
  PlayerEgo *pPVar11;
  uint *puVar12;
  Standing *pSVar13;
  Mission *this_01;
  String *pSVar14;
  Player *this_02;
  undefined4 uVar15;
  int iVar16;
  uint uVar17;
  bool bVar18;
  uint in_fpscr;
  uint uVar19;
  float fVar20;
  float fVar21;
  undefined4 uVar22;
  float fVar23;
  float fVar24;
  
  if (this[0xc2] == (Player)0x0) {
    return;
  }
  if (this[0xc0] == (Player)0x0) {
    return;
  }
  if (*(int *)(this + 0x78) < 1) {
    return;
  }
  if (!param_2) {
    if (*(int *)(this + 0xd0) != 0) {
      if ((((this[0xec] == (Player)0x0) && (1 < *(int *)(*(int *)(this + 0xd0) + 0x24) - 9U)) &&
          (iVar5 = Status::getSystem(Globals::status), iVar5 != 0)) &&
         ((this[0x5c] == (Player)0x0 || (this[0xe0] != (Player)0x0)))) {
        this_00 = *(KIPlayer **)(this + 0xd0);
        if (this_00[0x3e] != (KIPlayer)0x0) {
          if (0 < param_1) {
            *(int *)(this + 0x6c) = *(int *)(this + 0x6c) + param_1;
            Level::attackWanted(*(Level **)(this_00 + 0x50),*(int *)(this_00 + 0x44));
          }
          goto LAB_000afdec;
        }
      }
      else {
        this_00 = *(KIPlayer **)(this + 0xd0);
      }
      if ((((this_00 != (KIPlayer *)0x0) && (this[0xec] == (Player)0x0)) &&
          ((1 < *(int *)(this_00 + 0x24) - 9U &&
           ((iVar5 = KIPlayer::isWingMan(this_00), iVar5 == 0 &&
            (iVar5 = Status::getSystem(Globals::status), iVar5 != 0)))))) &&
         ((this[0x5c] == (Player)0x0 || (this[0xe0] != (Player)0x0)))) {
        iVar16 = *(int *)(*(int *)(this + 0xd0) + 0x24);
        pSVar6 = (SolarSystem *)Status::getSystem(Globals::status);
        iVar5 = SolarSystem::getRace(pSVar6);
        if (iVar16 != iVar5) {
          iVar16 = *(int *)(*(int *)(this + 0xd0) + 0x24);
          pSVar6 = (SolarSystem *)Status::getSystem(Globals::status);
          iVar5 = SolarSystem::getAttackRace(pSVar6);
          if (iVar16 != iVar5) goto LAB_000afd80;
        }
        *(int *)(this + 0x6c) = *(int *)(this + 0x6c) + param_1;
        iVar5 = Status::hardCoreMode();
        fVar21 = 0.5;
        fVar20 = 0.33;
        if (iVar5 != 0) {
          fVar20 = 0.1;
        }
        fVar23 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x84),
                                            (byte)(in_fpscr >> 0x16) & 3);
        fVar24 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x6c),
                                            (byte)(in_fpscr >> 0x16) & 3);
        fVar20 = fVar20 * fVar23;
        fVar23 = 0.66;
        if (iVar5 != 0) {
          fVar21 = 0.25;
          fVar23 = 0.4;
        }
        uVar8 = in_fpscr & 0xfffffff | (uint)(fVar24 < fVar20) << 0x1f |
                (uint)(fVar24 == fVar20) << 0x1e;
        uVar19 = uVar8 | (uint)(NAN(fVar24) || NAN(fVar20)) << 0x1c;
        bVar2 = (byte)(uVar8 >> 0x18);
        if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(uVar19 >> 0x1c) & 1)) {
          Level::friendTurnedEnemy(*(int *)(*(int *)(this + 0xd0) + 0x50));
          pSVar7 = (Ship *)Status::getShip(Globals::status);
          pSVar13 = (Standing *)Status::getStanding(Globals::status);
          iVar5 = Ship::getSignatureRace(pSVar7);
          if (-1 < iVar5) {
            uVar8 = Ship::getSignatureRace(pSVar7);
            bVar18 = uVar8 == *(uint *)(*(int *)(this + 0xd0) + 0x24);
            if (bVar18) {
              uVar8 = (uint)*(byte *)(*(int *)(this + 0xd0) + 0x3e);
            }
            if (bVar18 && uVar8 == 0) {
              pIVar9 = (Item *)Ship::getFirstEquipmentOfSort(pSVar7,0x1d);
              Ship::removeEquipment(pSVar7,pIVar9);
              pSVar10 = (Standing *)Status::getStanding(Globals::status);
              iVar5 = Ship::getSignatureRace(pSVar7);
              Standing::applyDelict(pSVar10,iVar5,100);
              Standing::setPlayerSignatureRace(pSVar13,-1);
              pPVar11 = (PlayerEgo *)Level::getPlayer(*(Level **)(*(int *)(this + 0xd0) + 0x50));
              iVar5 = PlayerEgo::getHUD(pPVar11);
              iVar16 = Level::getPlayer(*(Level **)(*(int *)(this + 0xd0) + 0x50));
              Hud::hudEvent(iVar5,(PlayerEgo *)&DAT_0000001f,iVar16);
            }
          }
        }
        uVar15 = *(undefined4 *)(this + 0x84);
        uVar22 = *(undefined4 *)(this + 0x6c);
        fVar20 = (float)VectorSignedToFloat(uVar15,(byte)(uVar19 >> 0x16) & 3);
        fVar24 = (float)VectorSignedToFloat(uVar22,(byte)(uVar19 >> 0x16) & 3);
        fVar21 = fVar21 * fVar20;
        uVar8 = uVar19 & 0xfffffff | (uint)(fVar24 < fVar21) << 0x1f |
                (uint)(fVar24 == fVar21) << 0x1e;
        uVar19 = uVar8 | (uint)(NAN(fVar24) || NAN(fVar21)) << 0x1c;
        bVar2 = (byte)(uVar8 >> 0x18);
        if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(uVar19 >> 0x1c) & 1)) {
          pSVar7 = (Ship *)Status::getShip(Globals::status);
          pSVar13 = (Standing *)Status::getStanding(Globals::status);
          iVar5 = Ship::getSignatureRace(pSVar7);
          if (((-1 < iVar5) && (*(int *)(*(int *)(this + 0xd0) + 0x24) < 4)) &&
             (*(char *)(*(int *)(this + 0xd0) + 0x3e) == '\0')) {
            pIVar9 = (Item *)Ship::getFirstEquipmentOfSort(pSVar7,0x1d);
            Ship::removeEquipment(pSVar7,pIVar9);
            pSVar10 = (Standing *)Status::getStanding(Globals::status);
            iVar5 = Ship::getSignatureRace(pSVar7);
            Standing::applyDelict(pSVar10,iVar5,100);
            Standing::setPlayerSignatureRace(pSVar13,-1);
            pPVar11 = (PlayerEgo *)Level::getPlayer(*(Level **)(*(int *)(this + 0xd0) + 0x50));
            iVar5 = PlayerEgo::getHUD(pPVar11);
            iVar16 = Level::getPlayer(*(Level **)(*(int *)(this + 0xd0) + 0x50));
            Hud::hudEvent(iVar5,(PlayerEgo *)&DAT_0000001f,iVar16);
          }
          this[0xe0] = (Player)0x1;
          uVar22 = *(undefined4 *)(this + 0x6c);
          uVar15 = *(undefined4 *)(this + 0x84);
        }
        fVar20 = (float)VectorSignedToFloat(uVar15,(byte)(uVar19 >> 0x16) & 3);
        fVar21 = (float)VectorSignedToFloat(uVar22,(byte)(uVar19 >> 0x16) & 3);
        fVar23 = fVar23 * fVar20;
        uVar8 = uVar19 & 0xfffffff | (uint)(fVar21 < fVar23) << 0x1f |
                (uint)(fVar21 == fVar23) << 0x1e;
        in_fpscr = uVar8 | (uint)(NAN(fVar21) || NAN(fVar23)) << 0x1c;
        bVar2 = (byte)(uVar8 >> 0x18);
        if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
          Level::alarmAllFriends
                    (*(Level **)(*(int *)(this + 0xd0) + 0x50),
                     *(int *)(*(int *)(this + 0xd0) + 0x24),true);
        }
        goto LAB_000afdec;
      }
    }
LAB_000afd80:
    iVar5 = Status::inBlackMarketSystem(Globals::status);
    if (((iVar5 == 1) && (iVar5 = *(int *)(this + 0xd0), iVar5 != 0)) &&
       (*(int *)(iVar5 + 0x24) == 8)) {
      this[0xe0] = (Player)0x1;
      Level::alarmAllFriends(*(Level **)(iVar5 + 0x50),8,true);
      puVar12 = (uint *)Level::getEnemies(*(Level **)(*(int *)(this + 0xd0) + 0x50));
      if ((puVar12 != (uint *)0x0) && (uVar8 = *puVar12, uVar8 != 0)) {
        uVar19 = puVar12[1];
        uVar17 = 0;
        do {
          iVar5 = *(int *)(uVar19 + uVar17 * 4);
          uVar17 = uVar17 + 1;
          if (*(int *)(iVar5 + 0x24) == 8) {
            *(undefined1 *)(iVar5 + 0x21) = 1;
          }
        } while (uVar17 < uVar8);
      }
      pSVar3 = Globals::status;
      Globals::status[0x111] = (Status)0x1;
      pSVar3[0x110] = (Status)0x0;
    }
  }
LAB_000afdec:
  iVar5 = (int)*(float *)(this + 0x88) - param_1;
  if (iVar5 < 0) {
    *(undefined4 *)(this + 0x88) = 0;
    iVar5 = iVar5 + *(int *)(this + 0x8c);
    if (iVar5 < 0) {
      *(undefined4 *)(this + 0x8c) = 0;
      *(int *)(this + 0x78) = iVar5 + *(int *)(this + 0x78);
      this[0x66] = (Player)0x1;
    }
    else {
      *(int *)(this + 0x8c) = iVar5;
      this[0x65] = (Player)0x1;
    }
  }
  else {
    uVar22 = VectorSignedToFloat(iVar5,(byte)(in_fpscr >> 0x16) & 3);
    *(undefined4 *)(this + 0x88) = uVar22;
    this[100] = (Player)0x1;
  }
  iVar5 = *(int *)(this + 0xd0);
  if ((((iVar5 != 0) && ((*(ushort *)(iVar5 + 0x38) & 0xff) == 0)) &&
      (*(ushort *)(iVar5 + 0x38) < 0x100)) && (*(char *)(iVar5 + 0x3e) != '\0')) {
    iVar16 = *(int *)(this + 0x78);
    if (*(int *)(this + 0x84) / 3 <= iVar16) goto LAB_000afe80;
    Level::almostKillWanted(*(Level **)(iVar5 + 0x50),*(int *)(iVar5 + 0x44));
  }
  iVar16 = *(int *)(this + 0x78);
LAB_000afe80:
  if (iVar16 < 1) {
    *(undefined4 *)(this + 0x78) = 0;
    if (param_2) {
      this[0x44] = (Player)0x1;
    }
    else if (((*(int *)(this + 0xd0) != 0) &&
             (uVar1 = *(ushort *)(*(int *)(this + 0xd0) + 0x38), (uVar1 & 0xff) == 0)) &&
            ((uVar1 < 0x100 && (iVar5 = Status::inBlackMarketSystem(Globals::status), iVar5 == 0))))
    {
      if (*(char *)(*(int *)(this + 0xd0) + 0x3e) == '\0') {
        pSVar13 = (Standing *)Status::getStanding(Globals::status);
        Standing::applyKill(pSVar13,*(int *)(*(int *)(this + 0xd0) + 0x24));
      }
      this_01 = (Mission *)Status::getCampaignMission(Globals::status);
      iVar5 = *(int *)(this + 0xd0);
      pSVar14 = (String *)GameText::getText(Globals::gameText,0x680);
      cVar4 = AbyssEngine::String::Compare((String *)(iVar5 + 0x18),pSVar14);
      if (param_3 == 0xb3 && cVar4 == '\0') {
        iVar5 = Mission::getStatusValue(this_01);
        Mission::setStatusValue(this_01,iVar5 + 1);
      }
      if (*(char *)(*(int *)(this + 0xd0) + 0x3e) != '\0') {
        Level::killWanted(*(int *)(*(int *)(this + 0xd0) + 0x50));
      }
    }
  }
  this[0xc1] = (Player)0x1;
  *(float *)(this + 0x60) = *(float *)(this + 0x60) + 0.065;
  updateDamageRate(this);
  if ((*(int *)(this + 0xd0) != 0) && (iVar5 = *(int *)(*(int *)(this + 0xd0) + 0x10), iVar5 != 0))
  {
    this_02 = *(Player **)(iVar5 + 4);
    this_02[0xc2] = (Player)0x1;
    damage(this_02,param_1,false,-1);
    *(undefined1 *)(*(int *)(*(int *)(*(int *)(this + 0xd0) + 0x10) + 4) + 0xc2) = 0;
  }
  return;
}

// ===== Player::damage  @0x000affd0  (12 bytes)
/* Player::damage(int) */

void __thiscall Player::damage(Player *this,int param_1)

{
  damage(this,param_1,false,-1);
  return;
}

// ===== Player::turnedEnemy  @0x000affda  (6 bytes)
/* Player::turnedEnemy() */

Player __thiscall Player::turnedEnemy(Player *this)

{
  return this[0xe0];
}

// ===== Player::turnEnemy  @0x000affe0  (8 bytes)
/* Player::turnEnemy() */

void __thiscall Player::turnEnemy(Player *this)

{
  this[0xe0] = (Player)0x1;
  return;
}

// ===== Player::gunAvailable  @0x000affe8  (34 bytes)
/* Player::gunAvailable(int) */

bool __thiscall Player::gunAvailable(Player *this,int param_1)

{
  int *piVar1;
  
  if ((((uint)param_1 < 4) &&
      (piVar1 = *(int **)(*(int *)(*(int *)this + 4) + param_1 * 4), piVar1 != (int *)0x0)) &&
     (*piVar1 != 0)) {
    return *(int *)piVar1[1] != 0;
  }
  return false;
}

// ===== Player::isDead  @0x000b000a  (12 bytes)
/* Player::isDead() */

bool __thiscall Player::isDead(Player *this)

{
  return *(int *)(this + 0x78) < 1;
}

// ===== Player::isDamaged  @0x000b0016  (6 bytes)
/* Player::isDamaged() */

Player __thiscall Player::isDamaged(Player *this)

{
  return this[0xc1];
}

// ===== Player::setActive  @0x000b001c  (6 bytes)
/* Player::setActive(bool) */

void __thiscall Player::setActive(Player *this,bool param_1)

{
  this[0xc0] = (Player)param_1;
  return;
}

// ===== Player::isActive  @0x000b0022  (6 bytes)
/* Player::isActive() */

Player __thiscall Player::isActive(Player *this)

{
  return this[0xc0];
}

// ===== Player::addGun  @0x000b0028  (122 bytes)
/* Player::addGun(Gun*, int) */

void __thiscall Player::addGun(Player *this,Gun *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = *(int *)this;
  if (iVar4 != 0) {
    if ((uint)param_2 < 4) {
      puVar1 = operator_new(0xc);
      puVar2 = operator_new__(4);
      puVar1[1] = puVar2;
      puVar1[2] = 1;
      *puVar2 = 0;
      *puVar1 = 0;
      *(undefined4 **)(*(int *)(iVar4 + 4) + param_2 * 4) = puVar1;
      piVar5 = *(int **)(*(int *)(*(int *)this + 4) + param_2 * 4);
      piVar5[2] = *piVar5 + 1;
      pvVar3 = realloc((void *)piVar5[1],(*piVar5 + 1) * 4);
      piVar5[1] = (int)pvVar3;
      *(Gun **)((int)pvVar3 + *piVar5 * 4) = param_1;
      *piVar5 = piVar5[2];
    }
    if (this[0x70] != (Player)0x0) {
      calcWeaponSounds(this,*(int *)(this + 0x10c));
      return;
    }
  }
  return;
}

// ===== Player::calcWeaponSounds  @0x000b00b0  (416 bytes)
/* Player::calcWeaponSounds(int) */

void __thiscall Player::calcWeaponSounds(Player *this,int param_1)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int *piVar10;
  uint uVar11;
  uint *puVar12;
  uint uVar13;
  int iVar14;
  
  puVar12 = *(uint **)this;
  if (puVar12 != (uint *)0x0) {
    if (*(uint **)puVar12[1] != (uint *)0x0) {
      uVar13 = **(uint **)puVar12[1];
      uVar4 = (uint)((ulonglong)uVar13 * 4);
      if ((int)((ulonglong)uVar13 * 4 >> 0x20) != 0) {
        uVar4 = 0xffffffff;
      }
      pvVar5 = operator_new__(uVar4);
      if (0 < (int)uVar13) {
        uVar4 = 0;
        iVar6 = *(int *)(*(int *)puVar12[1] + 4);
        do {
          *(undefined4 *)((int)pvVar5 + uVar4 * 4) =
               *(undefined4 *)(*(int *)(iVar6 + uVar4 * 4) + 0x58);
          uVar4 = uVar4 + 1;
        } while (uVar13 != uVar4);
        if (1 < (int)uVar13) {
          iVar6 = 1;
          bVar2 = 1;
          do {
            iVar14 = iVar6 + -1;
            iVar7 = Item::getSinglePrice
                              (*(Item **)(*(int *)(Globals::items + 4) +
                                         *(int *)((int)pvVar5 + iVar14 * 4) * 4));
            iVar8 = Item::getSinglePrice
                              (*(Item **)(*(int *)(Globals::items + 4) +
                                         *(int *)((int)pvVar5 + iVar6 * 4) * 4));
            if (iVar7 < iVar8) {
              bVar2 = 0;
              uVar9 = *(undefined4 *)((int)pvVar5 + iVar14 * 4);
              *(undefined4 *)((int)pvVar5 + iVar14 * 4) = *(undefined4 *)((int)pvVar5 + iVar6 * 4);
              *(undefined4 *)((int)pvVar5 + iVar6 * 4) = uVar9;
            }
            iVar7 = iVar6 + 1;
            iVar6 = 1;
            if (iVar7 < (int)uVar13) {
              iVar6 = iVar7;
            }
            bVar3 = (int)uVar13 <= iVar7 | bVar2;
            bVar1 = (bool)(bVar2 ^ 1);
            bVar2 = bVar3;
          } while ((iVar7 < (int)uVar13) || (bVar1));
        }
        if (0 < (int)uVar13) {
          uVar4 = 0;
          do {
            uVar11 = 0;
            do {
              if ((uVar4 != uVar11) &&
                 (*(int *)((int)pvVar5 + uVar4 * 4) == *(int *)((int)pvVar5 + uVar11 * 4))) {
                *(undefined4 *)((int)pvVar5 + uVar11 * 4) = 0xffffffff;
              }
              uVar11 = uVar11 + 1;
            } while (uVar13 != uVar11);
            uVar4 = uVar4 + 1;
          } while (uVar4 != uVar13);
          if (0 < (int)uVar13) {
            iVar6 = 0;
            do {
              if (-1 < *(int *)((int)pvVar5 + iVar6 * 4)) {
                iVar7 = *(int *)(*(int *)(**(int **)(*(int *)this + 4) + 4) + iVar6 * 4);
                *(undefined1 *)(iVar7 + 0x89) = 1;
                Globals::addSoundResourceToList
                          (Globals::globals,*(int *)(&DAT_00252310 + *(int *)(iVar7 + 0x58) * 4));
                param_1 = param_1 + -1;
              }
            } while ((param_1 != 0) && (iVar6 = iVar6 + 1, iVar6 < (int)uVar13));
          }
        }
      }
      operator_delete__(pvVar5);
      puVar12 = *(uint **)this;
    }
    if ((((2 < *puVar12) && (piVar10 = *(int **)(puVar12[1] + 8), piVar10 != (int *)0x0)) &&
        (*piVar10 != 0)) && (iVar6 = *(int *)piVar10[1], iVar6 != 0)) {
      *(undefined1 *)(iVar6 + 0x89) = 1;
      Globals::addSoundResourceToList
                (Globals::globals,*(int *)(&DAT_00252310 + *(int *)(iVar6 + 0x58) * 4));
      return;
    }
  }
  return;
}

// ===== Player::addGun  @0x000b0264  (158 bytes)
/* Player::addGun(Array<Gun*>*, int) */

void __thiscall Player::addGun(Player *this,Array *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  
  iVar5 = *(int *)this;
  if (iVar5 != 0) {
    if ((uint)param_2 < 4) {
      puVar1 = operator_new(0xc);
      puVar2 = operator_new__(4);
      puVar1[1] = puVar2;
      puVar1[2] = 1;
      *puVar2 = 0;
      *puVar1 = 0;
      *(undefined4 **)(*(int *)(iVar5 + 4) + param_2 * 4) = puVar1;
      if (*(int *)param_1 != 0) {
        uVar6 = 0;
        do {
          piVar4 = *(int **)(*(int *)(*(int *)this + 4) + param_2 * 4);
          uVar7 = *(undefined4 *)(*(int *)(param_1 + 4) + uVar6 * 4);
          piVar4[2] = *piVar4 + 1;
          pvVar3 = realloc((void *)piVar4[1],(*piVar4 + 1) * 4);
          piVar4[1] = (int)pvVar3;
          uVar6 = uVar6 + 1;
          *(undefined4 *)((int)pvVar3 + *piVar4 * 4) = uVar7;
          *piVar4 = piVar4[2];
        } while (uVar6 < *(uint *)param_1);
      }
    }
    if (this[0x70] != (Player)0x0) {
      calcWeaponSounds(this,*(int *)(this + 0x10c));
      return;
    }
  }
  return;
}

// ===== Player::removeAllGuns  @0x000b030e  (38 bytes)
/* Player::removeAllGuns() */

void __thiscall Player::removeAllGuns(Player *this)

{
  void *pvVar1;
  
  if (*(Array **)this != (Array *)0x0) {
    ArrayReleaseClasses<Array<Gun*>*>(*(Array **)this);
    pvVar1 = *(void **)this;
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)this = 0;
  return;
}

// ===== Player::getGunSlots  @0x000b0334  (4 bytes)
/* Player::getGunSlots() */

undefined4 Player::getGunSlots(void)

{
  return 3;
}

// ===== Player::resetGunDelay  @0x000b0338  (50 bytes)
/* Player::resetGunDelay(int) */

void __thiscall Player::resetGunDelay(Player *this,int param_1)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  puVar2 = *(uint **)this;
  if ((((puVar2 != (uint *)0x0) && (-1 < param_1)) && ((uint)param_1 < *puVar2)) &&
     ((puVar2 = *(uint **)(puVar2[1] + param_1 * 4), puVar2 != (uint *)0x0 &&
      (uVar3 = *puVar2, uVar3 != 0)))) {
    uVar4 = puVar2[1];
    uVar5 = 0;
    do {
      iVar1 = uVar5 * 4;
      uVar5 = uVar5 + 1;
      *(undefined4 *)(*(int *)(uVar4 + iVar1) + 0x6c) = 0;
    } while (uVar5 < uVar3);
  }
  return;
}

// ===== Player::refillGunDelay  @0x000b036a  (52 bytes)
/* Player::refillGunDelay(int) */

void __thiscall Player::refillGunDelay(Player *this,int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  puVar1 = *(uint **)this;
  if ((((puVar1 != (uint *)0x0) && (-1 < param_1)) && ((uint)param_1 < *puVar1)) &&
     ((puVar1 = *(uint **)(puVar1[1] + param_1 * 4), puVar1 != (uint *)0x0 &&
      (uVar5 = *puVar1, uVar5 != 0)))) {
    uVar2 = puVar1[1];
    uVar3 = 0;
    do {
      iVar4 = *(int *)(uVar2 + uVar3 * 4);
      uVar3 = uVar3 + 1;
      *(undefined4 *)(iVar4 + 0x6c) = *(undefined4 *)(iVar4 + 0x48);
    } while (uVar3 < uVar5);
  }
  return;
}

// ===== Player::stopShootSound  @0x000b03a0  (66 bytes)
/* Player::stopShootSound(int, int) */

void __thiscall Player::stopShootSound(Player *this,int param_1,int param_2)

{
  int iVar1;
  
  if (8 < (uint)param_2) {
    return;
  }
  if ((1 << (param_2 & 0xffU) & 0x10cU) != 0) {
    if ((*(int *)(this + 0xd0) == 0) || (*(int *)(*(int *)(this + 0xd0) + 0x24) != 9)) {
      iVar1 = *(int *)(&DAT_00252310 + param_1 * 4);
    }
    else {
      iVar1 = 0x3e;
    }
    FModSound::stop(Globals::sound,iVar1);
    return;
  }
  return;
}

// ===== Player::playShootSound  @0x000b03f0  (164 bytes)
/* Player::playShootSound(int, int, AbyssEngine::AEMath::Vector*, float) */

void __thiscall
Player::playShootSound(Player *this,int param_1,int param_2,Vector *param_3,float param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  float extraout_s0;
  
  if (*(int *)(this + 0xd0) == 0) {
    iVar3 = *(int *)(&DAT_00252310 + param_1 * 4);
  }
  else {
    uVar1 = *(uint *)(*(int *)(this + 0xd0) + 0x24);
    if (uVar1 < 0xb) {
      iVar3 = *(int *)(&DAT_002526c0 + uVar1 * 4);
    }
    else {
      iVar3 = 0x3d;
    }
  }
  if (((uint)param_2 < 9) && ((1 << (param_2 & 0xffU) & 0x10cU) != 0)) {
    iVar2 = FModSound::isPlaying(Globals::sound,iVar3);
    if (iVar2 != 0) {
      if (Globals::options[0xf] != '\0') {
        FModSound::updateEvent3DAttributes(Globals::sound,iVar3,param_3,(Vector *)0x0,false);
      }
      return;
    }
    param_4 = extraout_s0;
    if (Globals::options[0xf] == '\0') {
      param_3 = (Vector *)0x0;
    }
  }
  else if (Globals::options[0xf] == '\0') {
    param_3 = (Vector *)0x0;
  }
  FModSound::play(Globals::sound,iVar3,param_3,(Vector *)0x0,param_4);
  return;
}

// ===== Player::shoot  @0x000b04b4  (402 bytes)
/* Player::shoot(int, long long, bool, AbyssEngine::AEMath::Matrix) */

void Player::shoot(Player *param_1,uint param_2,undefined4 param_3_00,undefined4 param_4,
                  undefined4 param_3,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                  undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
                  undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16,
                  undefined4 param_17,undefined4 param_18,undefined4 param_19,undefined4 param_20)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  AEMath aAStack_7c [12];
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  int local_34;
  
  local_34 = __stack_chk_guard;
  local_70 = param_6;
  local_6c = param_7;
  local_68 = param_8;
  local_64 = param_9;
  local_60 = param_10;
  local_5c = param_11;
  local_58 = param_12;
  local_54 = param_13;
  local_50 = param_14;
  uStack_4c = param_15;
  local_48 = param_16;
  uStack_44 = param_17;
  local_40 = param_18;
  uStack_3c = param_19;
  local_38 = param_20;
  puVar1 = *(uint **)param_1;
  if (((((puVar1 != (uint *)0x0) && (param_1[0xc3] != (Player)0x0)) && (-1 < (int)param_2)) &&
      ((param_2 < *puVar1 && (puVar1 = *(uint **)(puVar1[1] + param_2 * 4), puVar1 != (uint *)0x0)))
      ) && (*puVar1 != 0)) {
    uVar3 = 0;
    do {
      iVar2 = *(int *)(puVar1[1] + uVar3 * 4);
      if (*(int *)(iVar2 + 0x48) < *(int *)(iVar2 + 0x6c)) {
        iVar2 = Gun::shootAt(iVar2,local_70,local_6c,local_68,local_64,local_60,local_5c,local_58,
                             local_54,local_50,uStack_4c,local_48,uStack_44,local_40,uStack_3c,
                             local_38,param_3_00,param_1,param_3);
        if (iVar2 == 1) {
          *(float *)(param_1 + 0x60) = *(float *)(param_1 + 0x60) + 0.008;
          iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)param_1 + 4) + param_2 * 4) + 4) +
                          uVar3 * 4);
          *(undefined4 *)(iVar2 + 0x6c) = 0;
          if ((param_1[0x70] != (Player)0x0) && (*(char *)(iVar2 + 0x89) != '\0')) {
            AbyssEngine::AEMath::MatrixGetPosition(aAStack_7c,(Matrix *)&local_70);
            iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)param_1 + 4) + param_2 * 4) + 4) +
                            uVar3 * 4);
            playShootSound(param_1,*(int *)(iVar2 + 0x58),*(int *)(iVar2 + 0x5c),
                           (Vector *)aAStack_7c,*(float *)(iVar2 + 0xb0));
          }
        }
      }
      uVar3 = uVar3 + 1;
      puVar1 = *(uint **)(*(int *)(*(int *)param_1 + 4) + param_2 * 4);
    } while (uVar3 < *puVar1);
  }
  if (__stack_chk_guard - local_34 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_34);
  }
  return;
}

// ===== Player::stopShooting  @0x000b0654  (74 bytes)
/* Player::stopShooting(int) */

void __thiscall Player::stopShooting(Player *this,int param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  puVar1 = *(uint **)this;
  if ((((puVar1 != (uint *)0x0) && (-1 < param_1)) && ((uint)param_1 < *puVar1)) &&
     ((puVar1 = *(uint **)(puVar1[1] + param_1 * 4), puVar1 != (uint *)0x0 && (*puVar1 != 0)))) {
    uVar3 = 0;
    do {
      iVar2 = *(int *)(puVar1[1] + uVar3 * 4);
      stopShootSound(this,*(int *)(iVar2 + 0x58),*(int *)(iVar2 + 0x5c));
      uVar3 = uVar3 + 1;
      puVar1 = *(uint **)(*(int *)(*(int *)this + 4) + param_1 * 4);
    } while (uVar3 < *puVar1);
  }
  return;
}

// ===== Player::stopShooting  @0x000b069e  (82 bytes)
/* Player::stopShooting(int, int) */

void __thiscall Player::stopShooting(Player *this,int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  if ((((param_2 - 0x16U < 9) && (puVar1 = *(uint **)this, puVar1 != (uint *)0x0)) && (-1 < param_1)
      ) && ((((uint)param_1 < *puVar1 &&
             (puVar1 = *(uint **)(puVar1[1] + param_1 * 4), puVar1 != (uint *)0x0)) &&
            (*puVar1 != 0)))) {
    uVar3 = 0;
    do {
      iVar2 = *(int *)(puVar1[1] + uVar3 * 4);
      stopShootSound(this,*(int *)(iVar2 + 0x58),*(int *)(iVar2 + 0x5c));
      uVar3 = uVar3 + 1;
      puVar1 = *(uint **)(*(int *)(*(int *)this + 4) + param_1 * 4);
    } while (uVar3 < *puVar1);
  }
  return;
}

// ===== Player::shoot  @0x000b06f0  (448 bytes)
/* Player::shoot(int, int, long long, bool, AbyssEngine::AEMath::Matrix) */

void Player::shoot(Player *param_1,uint param_2,int param_3,undefined4 param_4_00,undefined4 param_4
                  ,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                  undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,
                  undefined4 param_14,undefined4 param_15,undefined4 param_16,undefined4 param_17,
                  undefined4 param_18,undefined4 param_19,undefined4 param_20,undefined4 param_21,
                  undefined4 param_22)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  Gun *this;
  uint uVar4;
  undefined4 local_78;
  AEMath aAStack_70 [12];
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  local_64 = param_8;
  local_60 = param_9;
  local_5c = param_10;
  local_58 = param_11;
  local_54 = param_12;
  local_50 = param_13;
  uStack_4c = param_14;
  local_48 = param_15;
  uStack_44 = param_16;
  local_40 = param_17;
  uStack_3c = param_18;
  local_38 = param_19;
  uStack_34 = param_20;
  uStack_30 = param_21;
  uStack_2c = param_22;
  puVar3 = *(uint **)param_1;
  if ((puVar3 != (uint *)0x0) && (param_1[0xc3] != (Player)0x0)) {
    local_78 = 1;
    if (((int)param_2 < 0) || (*puVar3 <= param_2)) goto LAB_000b084a;
    puVar3 = *(uint **)(puVar3[1] + param_2 * 4);
    if (puVar3 != (uint *)0x0) {
      local_78 = 1;
      if (*puVar3 != 0) {
        uVar4 = 0;
        local_78 = 1;
        do {
          this = *(Gun **)(puVar3[1] + uVar4 * 4);
          uVar1 = *(int *)(this + 0x5c) - 6;
          if (((uVar1 < 0x1d) && ((1 << (uVar1 & 0xff) & 0x10000003U) != 0)) &&
             (-1 < **(int **)(this + 0x3c))) {
            Gun::ignite(this);
          }
          else if ((*(int *)(this + 0x58) == param_3) &&
                  (*(int *)(this + 0x48) < *(int *)(this + 0x6c))) {
            if ((uVar1 < 0x1d) && ((1 << (uVar1 & 0xff) & 0x10000003U) != 0)) {
              *(undefined1 *)(*(int *)(this + 0x38) + 0x69) = 1;
            }
            iVar2 = Gun::shoot(this,param_8,param_9,param_10,param_11,param_12,param_13,param_14,
                               param_15,param_16,param_17,param_18,param_19,param_20,param_21,
                               param_22,param_4,param_7);
            if (iVar2 == 1) {
              *(float *)(param_1 + 0x60) = *(float *)(param_1 + 0x60) + 0.008;
              if (param_1[0x70] != (Player)0x0) {
                AbyssEngine::AEMath::MatrixGetPosition(aAStack_70,(Matrix *)&local_64);
                iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)param_1 + 4) + param_2 * 4) + 4)
                                + uVar4 * 4);
                playShootSound(param_1,*(int *)(iVar2 + 0x58),*(int *)(iVar2 + 0x5c),
                               (Vector *)aAStack_70,*(float *)(iVar2 + 0xb0));
              }
              *(undefined4 *)(this + 0x6c) = 0;
              local_78 = 1;
              break;
            }
            if (*(int *)(this + 0x74) < 1) {
              local_78 = 0;
            }
          }
          uVar4 = uVar4 + 1;
          puVar3 = *(uint **)(*(int *)(*(int *)param_1 + 4) + param_2 * 4);
        } while (uVar4 < *puVar3);
      }
      goto LAB_000b084a;
    }
  }
  local_78 = 1;
LAB_000b084a:
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_78);
}

// ===== Player::shoot  @0x000b08bc  (108 bytes)
/* Player::shoot(int, long long, bool) */

undefined4 Player::shoot(int param_1,longlong param_2,bool param_3)

{
  undefined4 in_r1;
  undefined3 in_stack_00000001;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  uStack_2c = (undefined4)param_2;
  uStack_28 = (undefined4)((ulonglong)param_2 >> 0x20);
  shoot(param_1,in_r1,uStack_2c,uStack_28,_param_3,*(undefined4 *)(param_1 + 4),
        *(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10),
        *(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18),
        *(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x20),
        *(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x28),
        *(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x30),
        *(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x38),
        *(undefined4 *)(param_1 + 0x3c));
  return 1;
}

// ===== Player::shoot  @0x000b0928  (118 bytes)
/* Player::shoot(int, int, long long, bool) */

void Player::shoot(int param_1,int param_2,longlong param_3,bool param_4)

{
  undefined3 in_stack_00000001;
  
  shoot(param_1,param_2,(int)param_3,_param_4,_param_4);
  return;
}

// ===== Player::PlayEngineSound  @0x000b09a0  (98 bytes)
/* Player::PlayEngineSound(int, AbyssEngine::AEMath::Vector*) */

void Player::PlayEngineSound(int param_1,Vector *param_2)

{
  undefined4 uVar1;
  AEMath aAStack_24 [12];
  int local_18;
  
  local_18 = __stack_chk_guard;
  *(Vector **)(param_1 + 0xf4) = param_2;
  if (Globals::options[0xf] != '\0') {
    AbyssEngine::AEMath::MatrixGetPosition(aAStack_24,(Matrix *)(param_1 + 4));
    uVar1 = FModSound::updateEvent3DAttributes
                      (Globals::sound,*(Event **)(param_1 + 0xf0),*(int *)(param_1 + 0xf4),
                       (Vector *)aAStack_24,(Vector *)0x0,true);
    *(undefined4 *)(param_1 + 0xf0) = uVar1;
    *(undefined1 *)(param_1 + 0x108) = 1;
  }
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Player::PauseEngineSound  @0x000b0a14  (30 bytes)
/* Player::PauseEngineSound() */

void __thiscall Player::PauseEngineSound(Player *this)

{
  Player PVar1;
  
  if (*(Event **)(this + 0xf0) != (Event *)0x0) {
    PVar1 = (Player)FModSound::pause(Globals::sound,*(Event **)(this + 0xf0));
    this[0xf8] = PVar1;
  }
  return;
}

// ===== Player::ResumeEngineSound  @0x000b0a38  (46 bytes)
/* Player::ResumeEngineSound(bool) */

void __thiscall Player::ResumeEngineSound(Player *this,bool param_1)

{
  byte bVar1;
  
  if ((*(Event **)(this + 0xf0) != (Event *)0x0) && ((this[0xf8] != (Player)0x0 || (param_1)))) {
    bVar1 = FModSound::resume(Globals::sound,*(Event **)(this + 0xf0));
    this[0xf8] = (Player)(bVar1 ^ 1);
  }
  return;
}

// ===== Player::StopEngineSound  @0x000b0a6c  (36 bytes)
/* Player::StopEngineSound() */

void __thiscall Player::StopEngineSound(Player *this)

{
  if (*(Event **)(this + 0xf0) != (Event *)0x0) {
    FModSound::stop(Globals::sound,*(Event **)(this + 0xf0));
    *(undefined4 *)(this + 0xf0) = 0;
    this[0x108] = (Player)0x0;
  }
  return;
}

// ===== Player::GetEngineEvent  @0x000b0a94  (6 bytes)
/* Player::GetEngineEvent() */

undefined4 __thiscall Player::GetEngineEvent(Player *this)

{
  return *(undefined4 *)(this + 0xf0);
}

// ===== Player::update  @0x000b0a9c  (450 bytes)
/* Player::update(int, bool) */

void __thiscall Player::update(Player *this,int param_1,bool param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  Event *pEVar4;
  Event *extraout_r1;
  Player *pPVar5;
  uint in_fpscr;
  float fVar6;
  undefined8 in_d0;
  undefined4 extraout_s1;
  undefined4 extraout_s1_00;
  undefined4 extraout_s1_01;
  undefined8 uVar7;
  float fVar8;
  float fVar9;
  uint in_s5;
  uint extraout_s5;
  uint extraout_s5_00;
  uint extraout_s5_01;
  AEMath aAStack_58 [12];
  AEMath aAStack_4c [12];
  AEMath aAStack_40 [12];
  AEMath aAStack_34 [12];
  int local_28;
  
  uVar3 = (undefined4)((ulonglong)in_d0 >> 0x20);
  pEVar4 = (Event *)0xbb9;
  local_28 = __stack_chk_guard;
  iVar2 = *(int *)(this + 0xb4);
  *(int *)(this + 0xb4) = iVar2 + param_1;
  if (3000 < iVar2 + param_1) {
    *(undefined4 *)(this + 0xb4) = 0;
    this[0xc1] = (Player)0x0;
  }
  if (this[0x68] != (Player)0x0) {
    iVar2 = *(int *)(this + 0xe8);
    *(int *)(this + 0xe8) = iVar2 + param_1;
    fVar8 = (float)VectorSignedToFloat(iVar2 + param_1,(byte)(in_fpscr >> 0x16) & 3);
    fVar6 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0xe4),(byte)(in_fpscr >> 0x16) & 3);
    iVar2 = *(int *)(this + 0x80);
    fVar9 = (float)VectorSignedToFloat(iVar2,(byte)(in_fpscr >> 0x16) & 3);
    fVar9 = (fVar8 / fVar6) * fVar9;
    *(int *)(this + 0x7c) = (int)fVar9;
    if (iVar2 < (int)fVar9) {
      *(int *)(this + 0x7c) = iVar2;
      this[0x68] = (Player)0x0;
      *(int *)(Globals::status + 0x134) = *(int *)(Globals::status + 0x134) + -1;
      *(undefined4 *)(this + 0xe8) = 0;
    }
    updateDamageRate(this);
    pEVar4 = extraout_r1;
    in_s5 = extraout_s5;
    uVar3 = extraout_s1;
  }
  uVar1 = velocity;
  if (((Globals::options[0xf] == '\0') || (!param_2)) || (*(int *)(this + 0xf4) == -1)) {
    if (this[0x108] != (Player)0x0) {
      pEVar4 = *(Event **)(this + 0xf0);
    }
    if (this[0x108] != (Player)0x0 && pEVar4 != (Event *)0x0) {
      FModSound::stop(Globals::sound,pEVar4);
      *(undefined4 *)(this + 0xf0) = 0;
      this[0x108] = (Player)0x0;
      in_s5 = extraout_s5_01;
      uVar3 = extraout_s1_01;
    }
  }
  else {
    pPVar5 = this + 4;
    AbyssEngine::AEMath::MatrixGetPosition(aAStack_58,pPVar5);
    AbyssEngine::AEMath::operator-(aAStack_4c,(Vector *)aAStack_58,(Vector *)(this + 0xfc));
    fVar6 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::AEMath::operator*(aAStack_40,fVar6,(Vector *)fVar6);
    fVar6 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::AEMath::operator/(aAStack_34,(Vector *)aAStack_40,fVar6);
    AbyssEngine::AEMath::MatrixGetPosition(aAStack_40,pPVar5);
    uVar3 = FModSound::updateEvent3DAttributes
                      (Globals::sound,*(Event **)(this + 0xf0),*(int *)(this + 0xf4),
                       (Vector *)aAStack_40,(Vector *)aAStack_34,false);
    *(undefined4 *)(this + 0xf0) = uVar3;
    this[0x108] = (Player)0x1;
    AbyssEngine::AEMath::MatrixGetPosition(aAStack_4c,pPVar5);
    AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0xfc),(Vector *)aAStack_4c);
    in_s5 = extraout_s5_00;
    uVar3 = extraout_s1_00;
  }
  fVar6 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  uVar7 = FloatVectorMax(CONCAT44(uVar3,*(float *)(this + 0x60) + fVar6 * -0.001 * 0.025),
                         (ulonglong)in_s5 << 0x20,2,0x20);
  *(int *)(this + 0x60) = (int)uVar7;
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Player::heal  @0x000b0c88  (100 bytes)
/* Player::heal(float) */

void __thiscall Player::heal(Player *this,float param_1)

{
  uint uVar1;
  byte bVar2;
  float in_r1;
  int iVar3;
  int iVar4;
  uint in_fpscr;
  uint uVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  
  fVar6 = *(float *)(this + 0x110) + in_r1;
  *(float *)(this + 0x110) = fVar6;
  uVar1 = in_fpscr & 0xfffffff | (uint)(fVar6 < 1.0) << 0x1f | (uint)(fVar6 == 1.0) << 0x1e;
  uVar5 = uVar1 | (uint)NAN(fVar6) << 0x1c;
  bVar2 = (byte)(uVar1 >> 0x18);
  if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(uVar5 >> 0x1c) & 1)) {
    iVar8 = (int)fVar6;
    iVar4 = iVar8;
    if (0 < iVar8) {
      do {
        iVar3 = *(int *)(this + 0x84);
        if (*(int *)(this + 0x78) + 1 < *(int *)(this + 0x84)) {
          iVar3 = *(int *)(this + 0x78) + 1;
        }
        *(int *)(this + 0x78) = iVar3;
        updateDamageRate(this);
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      fVar6 = *(float *)(this + 0x110);
    }
    fVar7 = (float)VectorSignedToFloat(iVar8,(byte)(uVar5 >> 0x16) & 3);
    *(float *)(this + 0x110) = fVar6 - fVar7;
  }
  return;
}

// ===== Player::pitchAllPrimaryGuns  @0x000b0cec  (38 bytes)
/* Player::pitchAllPrimaryGuns(float) */

void __thiscall Player::pitchAllPrimaryGuns(Player *this,float param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 in_r1;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  
  if (((*(int *)this != 0) &&
      (puVar4 = (uint *)**(undefined4 **)(*(int *)this + 4), puVar4 != (uint *)0x0)) &&
     (uVar2 = *puVar4, uVar2 != 0)) {
    uVar3 = puVar4[1];
    uVar5 = 0;
    do {
      iVar1 = uVar5 * 4;
      uVar5 = uVar5 + 1;
      *(undefined4 *)(*(int *)(uVar3 + iVar1) + 0xb0) = in_r1;
    } while (uVar5 < uVar2);
  }
  return;
}

// ===== Player::replaceGuns  @0x000b0d12  (2 bytes)
/* Player::replaceGuns(int, int, int, int, int, bool) */

int Player::replaceGuns(int param_1,int param_2,int param_3,int param_4,int param_5,bool param_6)

{
  return param_1;
}

