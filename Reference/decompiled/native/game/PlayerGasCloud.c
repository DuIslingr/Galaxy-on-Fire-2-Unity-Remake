// Class: PlayerGasCloud
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== PlayerGasCloud::PlayerGasCloud  @0x001a5330  (314 bytes)
/* PlayerGasCloud::PlayerGasCloud(int, ParticleSystemManager*, AEGeometry*,
   AbyssEngine::AEMath::Vector const&) */

PlayerGasCloud * __thiscall
PlayerGasCloud::PlayerGasCloud
          (PlayerGasCloud *this,int param_1,ParticleSystemManager *param_2,AEGeometry *param_3,
          Vector *param_4)

{
  Player *this_00;
  AEGeometry *this_01;
  undefined4 uVar1;
  undefined4 uVar2;
  float extraout_s1;
  
  this_00 = operator_new(0x114);
  Player::Player(this_00,0,9999999,0,0,0);
  KIPlayer::KIPlayer((KIPlayer *)this,param_1,-1,this_00,param_3,*(float *)param_4,extraout_s1,
                     *(float *)(param_4 + 4),SUB41(*(float *)param_4,0));
  *(undefined ***)this = &PTR__PlayerGasCloud_00264990;
  *(undefined4 *)(this + 0x124) = 0;
  *(undefined4 *)(this + 0x128) = 0;
  *(undefined4 *)(this + 300) = 0;
  Player::setKIPlayer(*(Player **)(this + 4),(KIPlayer *)this);
  Player::setMaxHitpoints(*(Player **)(this + 4),1);
  (**(code **)(*(int *)this + 0x44))(this,param_4);
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x154) = 0;
  this[0x21] = (PlayerGasCloud)0x0;
  *(undefined4 *)(this + 0x141) = 0;
  *(undefined4 *)(this + 0x145) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x149) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x14d) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x134) = 0;
  *(undefined4 *)(this + 0x138) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x13c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x140) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(int *)(this + 0x15c) = param_1;
  switch(param_1) {
  default:
    uVar1 = 0x4a35;
    uVar2 = 0x4a39;
    break;
  case 0xca:
    uVar1 = 0x4a36;
    uVar2 = 0x4a3a;
    break;
  case 0xcb:
    uVar1 = 18999;
    uVar2 = 0x4a3b;
    break;
  case 0xcc:
    uVar1 = 19000;
    uVar2 = 0x4a3c;
  }
  *(undefined4 *)(this + 0x160) = uVar2;
  *(undefined4 *)(this + 0x164) = uVar1;
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x124),param_4);
  this_01 = operator_new(0xc0);
  AEGeometry::AEGeometry(this_01,*(ushort *)(this + 0x164),Globals::Canvas,false);
  *(AEGeometry **)(this + 0x130) = this_01;
  AEGeometry::setPosition((Vector *)this_01);
  this[0x40] = (PlayerGasCloud)0x1;
  this[0x48] = (PlayerGasCloud)0x1;
  *(undefined4 *)(this + 0x84) = 0;
  this[0xf1] = (PlayerGasCloud)0x1;
  this[0x158] = (PlayerGasCloud)0x0;
  return this;
}

// ===== PlayerGasCloud::~PlayerGasCloud  @0x001a5498  (222 bytes)
/* PlayerGasCloud::~PlayerGasCloud() */

void __thiscall PlayerGasCloud::~PlayerGasCloud(PlayerGasCloud *this)

{
  void *pvVar1;
  
  *(undefined ***)this = &PTR__PlayerGasCloud_00264990;
  if (*(Array **)(this + 0x134) != (Array *)0x0) {
    ArrayReleaseClasses<AEGeometry*>(*(Array **)(this + 0x134));
    pvVar1 = *(void **)(this + 0x134);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
    *(undefined4 *)(this + 0x134) = 0;
  }
  if (*(Array **)(this + 0x138) != (Array *)0x0) {
    ArrayReleaseClasses<AbyssEngine::AEMath::Vector*>(*(Array **)(this + 0x138));
    pvVar1 = *(void **)(this + 0x138);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
    *(undefined4 *)(this + 0x138) = 0;
  }
  pvVar1 = *(void **)(this + 0x13c);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x13c) = 0;
  pvVar1 = *(void **)(this + 0x140);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x140) = 0;
  pvVar1 = *(void **)(this + 0x144);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x144) = 0;
  pvVar1 = *(void **)(this + 0x148);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x148) = 0;
  if (*(AEGeometry **)(this + 0x130) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x130));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x130) = 0;
  KIPlayer::~KIPlayer((KIPlayer *)this);
  return;
}

// ===== PlayerGasCloud::~PlayerGasCloud  @0x001a557c  (16 bytes)
/* PlayerGasCloud::~PlayerGasCloud() */

void __thiscall PlayerGasCloud::~PlayerGasCloud(PlayerGasCloud *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~PlayerGasCloud(this);
  operator_delete(pvVar1);
  return;
}

// ===== PlayerGasCloud::setSparkInSight  @0x001a558c  (22 bytes)
/* PlayerGasCloud::setSparkInSight(int, bool) */

void __thiscall PlayerGasCloud::setSparkInSight(PlayerGasCloud *this,int param_1,bool param_2)

{
  uint uVar1;
  
  if (*(uint **)(this + 0x134) != (uint *)0x0) {
    uVar1 = **(uint **)(this + 0x134);
    if ((uint)param_1 < uVar1) {
      this = *(PlayerGasCloud **)(*(int *)(this + 0x14c) + 4);
    }
    if ((uint)param_1 < uVar1) {
      this[param_1] = (PlayerGasCloud)param_2;
    }
  }
  return;
}

// ===== PlayerGasCloud::isSparkAlive  @0x001a55a2  (48 bytes)
/* PlayerGasCloud::isSparkAlive(int) */

bool __thiscall PlayerGasCloud::isSparkAlive(PlayerGasCloud *this,int param_1)

{
  if (*(uint **)(this + 0x134) == (uint *)0x0) {
    return false;
  }
  if (**(uint **)(this + 0x134) <= (uint)param_1) {
    return false;
  }
  return -0x5dc < *(int *)(*(int *)(*(int *)(this + 0x148) + 4) + param_1 * 4);
}

// ===== PlayerGasCloud::getSparks  @0x001a55d2  (6 bytes)
/* PlayerGasCloud::getSparks() */

undefined4 __thiscall PlayerGasCloud::getSparks(PlayerGasCloud *this)

{
  return *(undefined4 *)(this + 0x134);
}

// ===== PlayerGasCloud::getPosition  @0x001a55d8  (12 bytes)
/* PlayerGasCloud::getPosition() */

void PlayerGasCloud::getPosition(void)

{
  AEGeometry::getPosition();
  return;
}

// ===== PlayerGasCloud::setPosition  @0x001a55e4  (8 bytes)
/* PlayerGasCloud::setPosition(AbyssEngine::AEMath::Vector const&) */

void PlayerGasCloud::setPosition(Vector *param_1)

{
  AEGeometry::setPosition(*(Vector **)(param_1 + 8));
  return;
}

// ===== PlayerGasCloud::translate  @0x001a55ea  (8 bytes)
/* PlayerGasCloud::translate(AbyssEngine::AEMath::Vector const&) */

void PlayerGasCloud::translate(Vector *param_1)

{
  AEGeometry::translate(*(Vector **)(param_1 + 8));
  return;
}

// ===== PlayerGasCloud::explode  @0x001a55f0  (992 bytes)
/* PlayerGasCloud::explode(int, AbyssEngine::AEMath::Vector, float) */

void PlayerGasCloud::explode
               (int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               float param_6)

{
  float fVar1;
  float fVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  float fVar6;
  undefined4 uVar7;
  AEGeometry *this;
  undefined4 uVar8;
  int iVar9;
  void *pvVar10;
  undefined8 *puVar11;
  int *piVar12;
  int iVar13;
  uint in_fpscr;
  int iVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  AEMath aAStack_ac [12];
  undefined8 local_a0;
  undefined4 local_98;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 local_70;
  int local_6c;
  
  local_6c = __stack_chk_guard;
  local_70 = param_5;
  local_78 = param_3;
  uStack_74 = param_4;
  if (*(char *)(param_1 + 0x150) == '\0') {
    *(undefined4 *)(param_1 + 0x84) = 3;
    KIPlayer::setActive(SUB41(param_1,0));
    *(undefined1 *)(param_1 + 0x150) = 1;
    puVar3 = operator_new(0xc);
    puVar4 = operator_new__(4);
    puVar3[1] = puVar4;
    puVar3[2] = 1;
    *puVar4 = 0;
    *puVar3 = 0;
    *(undefined4 **)(param_1 + 0x134) = puVar3;
    puVar3 = operator_new(0xc);
    puVar4 = operator_new__(4);
    puVar3[1] = puVar4;
    *puVar4 = 0;
    puVar3[2] = 1;
    *puVar3 = 0;
    *(undefined4 **)(param_1 + 0x138) = puVar3;
    puVar3 = operator_new(0xc);
    puVar4 = operator_new__(4);
    puVar3[1] = puVar4;
    puVar3[2] = 1;
    *puVar4 = 0;
    *puVar3 = 0;
    *(undefined4 **)(param_1 + 0x13c) = puVar3;
    puVar3 = operator_new(0xc);
    puVar4 = operator_new__(4);
    puVar3[1] = puVar4;
    *puVar4 = 0;
    puVar3[2] = 1;
    *puVar3 = 0;
    *(undefined4 **)(param_1 + 0x140) = puVar3;
    puVar3 = operator_new(0xc);
    puVar4 = operator_new__(4);
    puVar3[1] = puVar4;
    puVar3[2] = 1;
    *puVar4 = 0;
    *puVar3 = 0;
    *(undefined4 **)(param_1 + 0x148) = puVar3;
    puVar3 = operator_new(0xc);
    puVar5 = operator_new__(1);
    puVar3[1] = puVar5;
    *puVar5 = 0;
    puVar3[2] = 1;
    *puVar3 = 0;
    *(undefined4 **)(param_1 + 0x14c) = puVar3;
    puVar3 = operator_new(0xc);
    puVar4 = operator_new__(4);
    puVar3[1] = puVar4;
    puVar3[2] = 1;
    *puVar4 = 0;
    *puVar3 = 0;
    *(undefined4 **)(param_1 + 0x144) = puVar3;
    AbyssEngine::AEMath::operator-
              ((AEMath *)&local_84,(Vector *)&local_78,(Vector *)(param_1 + 0x124));
    fVar6 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_84);
    fVar18 = 1.5 - fVar6 / param_6;
    uVar7 = Item::getAttribute(*(Item **)(*(int *)(Globals::items + 4) + param_2 * 4),0x38);
    fVar6 = (float)VectorSignedToFloat(uVar7,(byte)(in_fpscr >> 0x16) & 3);
    iVar14 = (int)(((fVar18 * 130.0) / 1.5 + 10.0) * (fVar6 / 100.0));
    if (0 < iVar14) {
      fVar6 = fVar18 * 5000.0;
      iVar13 = 0;
      do {
        this = operator_new(0xc0);
        AEGeometry::AEGeometry(this,*(ushort *)(param_1 + 0x160),Globals::Canvas,false);
        AEGeometry::setPosition((Vector *)this);
        fVar17 = local_84;
        fVar20 = *(float *)(param_1 + 0x124);
        uVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,10000);
        fVar1 = local_80;
        fVar22 = *(float *)(param_1 + 0x128);
        uVar8 = AbyssEngine::AERandom::nextInt(Globals::rnd,10000);
        fVar2 = local_7c;
        fVar21 = (float)VectorSignedToFloat(uVar7,(byte)(in_fpscr >> 0x16) & 3);
        fVar15 = *(float *)(param_1 + 300);
        fVar19 = (float)VectorSignedToFloat(uVar8,(byte)(in_fpscr >> 0x16) & 3);
        uVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,10000);
        fVar16 = (float)VectorSignedToFloat(uVar7,(byte)(in_fpscr >> 0x16) & 3);
        local_90 = ((fVar20 + fVar17) - fVar6) + fVar18 * fVar21;
        local_8c = ((fVar22 + fVar1) - fVar6) + fVar18 * fVar19;
        local_88 = (fVar15 - fVar6) + fVar2 + fVar18 * fVar16;
        AbyssEngine::AEMath::operator-(aAStack_ac,(Vector *)(param_1 + 0x124),(Vector *)&local_90);
        AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_a0,(Vector *)aAStack_ac);
        uVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,200);
        fVar17 = (float)VectorSignedToFloat(uVar7,(byte)(in_fpscr >> 0x16) & 3);
        iVar9 = AbyssEngine::AERandom::nextInt(Globals::rnd,14000);
        piVar12 = *(int **)(param_1 + 0x13c);
        fVar17 = (fVar17 / 200.0) * 3.0 + 3.0;
        piVar12[2] = *piVar12 + 1;
        pvVar10 = realloc((void *)piVar12[1],(*piVar12 + 1) * 4);
        piVar12[1] = (int)pvVar10;
        *(float *)((int)pvVar10 + *piVar12 * 4) = fVar17 * 7.0;
        *piVar12 = piVar12[2];
        piVar12 = *(int **)(param_1 + 0x140);
        piVar12[2] = *piVar12 + 1;
        pvVar10 = realloc((void *)piVar12[1],(*piVar12 + 1) * 4);
        piVar12[1] = (int)pvVar10;
        *(float *)((int)pvVar10 + *piVar12 * 4) = fVar17;
        *piVar12 = piVar12[2];
        piVar12 = *(int **)(param_1 + 0x148);
        piVar12[2] = *piVar12 + 1;
        pvVar10 = realloc((void *)piVar12[1],(*piVar12 + 1) * 4);
        piVar12[1] = (int)pvVar10;
        *(int *)((int)pvVar10 + *piVar12 * 4) = iVar9 + 8000;
        *piVar12 = piVar12[2];
        puVar11 = operator_new(0xc);
        *(undefined4 *)(puVar11 + 1) = local_98;
        *puVar11 = local_a0;
        piVar12 = *(int **)(param_1 + 0x138);
        piVar12[2] = *piVar12 + 1;
        pvVar10 = realloc((void *)piVar12[1],(*piVar12 + 1) * 4);
        piVar12[1] = (int)pvVar10;
        *(undefined8 **)((int)pvVar10 + *piVar12 * 4) = puVar11;
        *piVar12 = piVar12[2];
        piVar12 = *(int **)(param_1 + 0x134);
        piVar12[2] = *piVar12 + 1;
        pvVar10 = realloc((void *)piVar12[1],(*piVar12 + 1) * 4);
        piVar12[1] = (int)pvVar10;
        *(AEGeometry **)((int)pvVar10 + *piVar12 * 4) = this;
        *piVar12 = piVar12[2];
        piVar12 = *(int **)(param_1 + 0x14c);
        piVar12[2] = *piVar12 + 1U;
        pvVar10 = realloc((void *)piVar12[1],*piVar12 + 1U);
        piVar12[1] = (int)pvVar10;
        *(undefined1 *)((int)pvVar10 + *piVar12) = 0;
        *piVar12 = piVar12[2];
        piVar12 = *(int **)(param_1 + 0x144);
        piVar12[2] = *piVar12 + 1;
        pvVar10 = realloc((void *)piVar12[1],(*piVar12 + 1) * 4);
        piVar12[1] = (int)pvVar10;
        iVar13 = iVar13 + 1;
        *(undefined4 *)((int)pvVar10 + *piVar12 * 4) = 0x3f800000;
        *piVar12 = piVar12[2];
      } while (iVar13 < iVar14);
    }
  }
  if (__stack_chk_guard != local_6c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerGasCloud::hasExploded  @0x001a5a14  (6 bytes)
/* PlayerGasCloud::hasExploded() */

PlayerGasCloud __thiscall PlayerGasCloud::hasExploded(PlayerGasCloud *this)

{
  return this[0x150];
}

// ===== PlayerGasCloud::update  @0x001a5a1c  (1204 bytes)
/* PlayerGasCloud::update(int) */

void __thiscall PlayerGasCloud::update(PlayerGasCloud *this,int param_1)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  PlayerEgo *pPVar4;
  Ship *pSVar5;
  Item *pIVar6;
  Hud *pHVar7;
  Mission *this_00;
  undefined4 uVar8;
  Vector *pVVar9;
  uint uVar10;
  bool bVar11;
  uint in_fpscr;
  uint uVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  AEMath aAStack_a8 [12];
  AEMath aAStack_9c [12];
  AEMath aAStack_90 [12];
  Vector aVStack_84 [12];
  Vector aVStack_78 [12];
  int local_6c;
  
  local_6c = __stack_chk_guard;
  if (param_1 != 0) {
    if (((this[0x150] == (PlayerGasCloud)0x0) || (this[0x158] != (PlayerGasCloud)0x0)) ||
       (*(int **)(this + 0x134) == (int *)0x0)) {
      uVar8 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(*(int *)(this + 0x130) + 0xc));
      AbyssEngine::Transform::Update(CONCAT44(1,uVar8),SUB41(param_1,0));
    }
    else {
      *(int *)(this + 0x154) = *(int *)(this + 0x154) + param_1;
      this[0x158] = (PlayerGasCloud)0x1;
      if (**(int **)(this + 0x134) != 0) {
        fVar15 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        iVar2 = *(int *)(this + 0x148);
        uVar10 = 0;
        do {
          *(int *)(*(int *)(iVar2 + 4) + uVar10 * 4) =
               *(int *)(*(int *)(iVar2 + 4) + uVar10 * 4) - param_1;
          pfVar3 = (float *)(*(int *)(*(int *)(this + 0x13c) + 4) + uVar10 * 4);
          fVar14 = *pfVar3 - fVar15 * 0.08;
          *pfVar3 = fVar14;
          fVar13 = *(float *)(*(int *)(*(int *)(this + 0x140) + 4) + uVar10 * 4);
          uVar12 = in_fpscr & 0xfffffff;
          if (fVar14 < fVar13) {
            *pfVar3 = fVar13;
          }
          Level::getPlayer(*(Level **)(this + 0x50));
          PlayerEgo::getTurretPosition();
          AEGeometry::getPosition();
          AbyssEngine::AEMath::operator-(aAStack_90,aVStack_78,aVStack_84);
          fVar13 = (float)AbyssEngine::AEMath::VectorLength((Vector *)aAStack_90);
          in_fpscr = uVar12 & 0xfffffff;
          if ((800.0 <= fVar13) || (*(int *)(this + 0x154) < 2000)) {
LAB_001a5d1e:
            iVar2 = *(int *)(*(int *)(*(int *)(this + 0x148) + 4) + uVar10 * 4);
            if (iVar2 < 1) {
              fVar13 = (float)VectorSignedToFloat(iVar2,(byte)(in_fpscr >> 0x16) & 3);
              pfVar3 = (float *)(*(int *)(*(int *)(this + 0x144) + 4) + uVar10 * 4);
              fVar13 = fVar13 / 1500.0 + 1.0;
              *pfVar3 = fVar13;
              if (fVar13 < 0.0) {
                *pfVar3 = 0.0;
              }
            }
            else if (fVar13 < 3500.0) {
              *(float *)(*(int *)(*(int *)(this + 0x144) + 4) + uVar10 * 4) =
                   (fVar13 + -800.0) / 2700.0;
            }
            in_fpscr = in_fpscr & 0xfffffff;
            uVar8 = AbyssEngine::PaintCanvas::TransformGetTransform
                              (Globals::Canvas,
                               *(uint *)(*(int *)(*(int *)(*(int *)(this + 0x134) + 4) + uVar10 * 4)
                                        + 0xc));
            AbyssEngine::Transform::Update(CONCAT44(1,uVar8),SUB41(param_1,0));
          }
          else {
            pPVar4 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x50));
            iVar2 = PlayerEgo::isInTurretMode(pPVar4);
            if ((iVar2 != 1) ||
               (*(int *)(*(int *)(*(int *)(this + 0x148) + 4) + uVar10 * 4) < -0x5db))
            goto LAB_001a5d1e;
            *(undefined4 *)(*(int *)(*(int *)(this + 0x148) + 4) + uVar10 * 4) = 0xfffffa24;
            pSVar5 = (Ship *)Status::getShip(Globals::status);
            iVar2 = Ship::getFreeSpace(pSVar5);
            if (iVar2 < 1) {
              iVar2 = Level::getPlayer(*(Level **)(this + 0x50));
              if (iVar2 != 0) {
                fVar13 = (float)FModSound::stop(Globals::sound,0x8d0);
                FModSound::play(Globals::sound,0x8d0,(Vector *)0x0,(Vector *)0x0,fVar13);
                pPVar4 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x50));
                pHVar7 = (Hud *)PlayerEgo::getHUD(pPVar4);
                Hud::catchCargo(pHVar7,*(int *)(this + 0x15c),0,true,false,true,false,false);
              }
            }
            else {
              pIVar6 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) +
                                                        *(int *)(this + 0x15c) * 4),1);
              iVar2 = Level::getPlayer(*(Level **)(this + 0x50));
              if (iVar2 != 0) {
                pPVar4 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x50));
                pHVar7 = (Hud *)PlayerEgo::getHUD(pPVar4);
                Hud::catchCargo(pHVar7,*(int *)(this + 0x15c),1,false,false,false,false,true);
                if ((Globals::hints[0x2d] == '\0') &&
                   (iVar2 = Status::getCurrentCampaignMission(Globals::status), 0x8e < iVar2)) {
                  this_00 = (Mission *)Status::getMission(Globals::status);
                  iVar2 = Mission::isEmpty(this_00);
                  bVar11 = iVar2 == 1;
                  if (bVar11) {
                    iVar2 = *(int *)(this + 0x15c);
                  }
                  if (bVar11 && iVar2 == 0xcc) {
                    Globals::hints[0x2d] = '\x01';
                    Level::createRadioMessage(*(Level **)(this + 0x50),0x1a,0);
                  }
                }
              }
              fVar13 = (float)FModSound::stop(Globals::sound,0x8d0);
              FModSound::play(Globals::sound,0x8d0,(Vector *)0x0,(Vector *)0x0,fVar13);
              pSVar5 = (Ship *)Status::getShip(Globals::status);
              Ship::addCargo(pSVar5,pIVar6);
            }
            *(undefined4 *)(*(int *)(*(int *)(this + 0x144) + 4) + uVar10 * 4) = 0;
          }
          if ((*(char *)(*(int *)(*(int *)(this + 0x14c) + 4) + uVar10) == '\0') ||
             (*(int *)(this + 0x154) < 2000)) {
LAB_001a5e54:
            pVVar9 = *(Vector **)(*(int *)(*(int *)(this + 0x134) + 4) + uVar10 * 4);
            fVar13 = fVar15 * *(float *)(*(int *)(*(int *)(this + 0x13c) + 4) + uVar10 * 4);
            AbyssEngine::AEMath::operator*(aAStack_9c,fVar13,(Vector *)fVar13);
            AbyssEngine::AEMath::operator+(aAStack_90,aVStack_84,(Vector *)aAStack_9c);
          }
          else {
            pSVar5 = (Ship *)Status::getShip(Globals::status);
            iVar2 = Ship::getFirstEquipmentOfSort(pSVar5,0x23);
            if (iVar2 == 0) goto LAB_001a5e54;
            AbyssEngine::AEMath::operator-(aAStack_9c,aVStack_78,aVStack_84);
            AbyssEngine::AEMath::VectorNormalize(aAStack_90,(Vector *)aAStack_9c);
            AbyssEngine::AEMath::Vector::operator=
                      (*(Vector **)(*(int *)(*(int *)(this + 0x138) + 4) + uVar10 * 4),
                       (Vector *)aAStack_90);
            pVVar9 = *(Vector **)(*(int *)(*(int *)(this + 0x134) + 4) + uVar10 * 4);
            pSVar5 = (Ship *)Status::getShip(Globals::status);
            pIVar6 = (Item *)Ship::getFirstEquipmentOfSort(pSVar5,0x23);
            iVar2 = Item::getAttribute(pIVar6,0x31);
            fVar13 = (float)VectorSignedToFloat(iVar2 * param_1,(byte)(in_fpscr >> 0x16) & 3);
            AbyssEngine::AEMath::operator*(aAStack_a8,fVar13,(Vector *)fVar13);
            AbyssEngine::AEMath::operator+(aAStack_9c,aVStack_84,(Vector *)aAStack_a8);
          }
          AEGeometry::setPosition(pVVar9);
          iVar2 = *(int *)(this + 0x148);
          iVar1 = uVar10 * 4;
          uVar10 = uVar10 + 1;
          if (-0x5dc < *(int *)(*(int *)(iVar2 + 4) + iVar1)) {
            this[0x158] = (PlayerGasCloud)0x0;
          }
        } while (uVar10 < **(uint **)(this + 0x134));
        if (this[0x158] == (PlayerGasCloud)0x0) goto LAB_001a5ed0;
      }
      this[0xf1] = (PlayerGasCloud)0x0;
    }
  }
LAB_001a5ed0:
  if (__stack_chk_guard == local_6c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== PlayerGasCloud::render  @0x001a5f2c  (268 bytes)
/* PlayerGasCloud::render() */

void __thiscall PlayerGasCloud::render(PlayerGasCloud *this)

{
  PaintCanvas *this_00;
  uint uVar1;
  undefined4 *puVar2;
  AEGeometry *pAVar3;
  float fVar4;
  AEMath aAStack_80 [12];
  AEMath aAStack_74 [12];
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
  
  this_00 = Globals::Canvas;
  local_28 = __stack_chk_guard;
  if ((this[0xf1] != (PlayerGasCloud)0x0) &&
     (*(int *)(this + 0x84) == 3 || *(int *)(this + 0x84) == 0)) {
    uVar1 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
    puVar2 = (undefined4 *)AbyssEngine::PaintCanvas::CameraGetLocal(this_00,uVar1);
    local_68 = *puVar2;
    uStack_64 = puVar2[1];
    uStack_60 = puVar2[2];
    uStack_5c = puVar2[3];
    uStack_58 = puVar2[4];
    local_54 = puVar2[5];
    uStack_50 = puVar2[6];
    uStack_4c = puVar2[7];
    uStack_48 = puVar2[8];
    uStack_44 = puVar2[9];
    local_40 = puVar2[10];
    uStack_3c = puVar2[0xb];
    uStack_38 = puVar2[0xc];
    uStack_34 = puVar2[0xd];
    uStack_30 = puVar2[0xe];
    AbyssEngine::AEMath::MatrixGetDir(aAStack_80,(Matrix *)&local_68);
    fVar4 = (float)AbyssEngine::AEMath::operator-(aAStack_74,(Vector *)aAStack_80);
    if ((this[0x150] == (PlayerGasCloud)0x0) || (*(int **)(this + 0x134) == (int *)0x0)) {
      pAVar3 = *(AEGeometry **)(this + 0x130);
      AbyssEngine::AEMath::MatrixGetUp(aAStack_80,(Matrix *)&local_68);
      AEGeometry::setDirection(pAVar3,(Vector *)aAStack_74,(Vector *)aAStack_80);
      AEGeometry::render(*(AEGeometry **)(this + 0x130));
    }
    else if (**(int **)(this + 0x134) != 0) {
      uVar1 = 0;
      do {
        AEGeometry::setScaling(fVar4);
        pAVar3 = *(AEGeometry **)(*(int *)(*(int *)(this + 0x134) + 4) + uVar1 * 4);
        AbyssEngine::AEMath::MatrixGetUp(aAStack_80,(Matrix *)&local_68);
        AEGeometry::setDirection(pAVar3,(Vector *)aAStack_74,(Vector *)aAStack_80);
        fVar4 = (float)AEGeometry::render(*(AEGeometry **)
                                           (*(int *)(*(int *)(this + 0x134) + 4) + uVar1 * 4));
        uVar1 = uVar1 + 1;
      } while (uVar1 < **(uint **)(this + 0x134));
    }
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

