// Class: PlayerTurret
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== PlayerTurret::PlayerTurret  @0x00182640  (740 bytes)
/* PlayerTurret::PlayerTurret(int, Player*, AEGeometry*, float, float, float) */

void __thiscall
PlayerTurret::PlayerTurret
          (PlayerTurret *this,int param_1,Player *param_2,AEGeometry *param_3,float param_4,
          float param_5,float param_6)

{
  AEGeometry *pAVar1;
  int iVar2;
  void *pvVar3;
  Explosion *this_00;
  ushort uVar4;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s2;
  float extraout_s2_00;
  bool in_stack_00000000;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  
  local_34 = __stack_chk_guard;
  KIPlayer::KIPlayer((KIPlayer *)this,param_1,-1,param_2,param_3,param_4,param_5,param_6,
                     in_stack_00000000);
  *(undefined ***)this = &PTR__PlayerTurret_002645c4;
  *(undefined4 *)(this + 0x154) = 0;
  *(undefined4 *)(this + 0x158) = 0;
  *(undefined4 *)(this + 0x15c) = 0;
  this[0x21] = (PlayerTurret)0x1;
  this[0x3a] = (PlayerTurret)0x1;
  *(undefined4 *)(this + 0x13c) = 0;
  *(undefined4 *)(this + 0x140) = 0;
  *(undefined4 *)(this + 0x150) = 0;
  *(undefined4 *)(this + 0x124) = 0;
  *(undefined4 *)(this + 0x160) = 50000;
  pAVar1 = operator_new(0xc0);
  AEGeometry::AEGeometry(pAVar1,(ushort)param_1,Globals::Canvas,false);
  *(AEGeometry **)(this + 0x13c) = pAVar1;
  if (param_1 == 0x381b) {
    pAVar1 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar1,0x381c,Globals::Canvas,false);
    *(AEGeometry **)(this + 0x140) = pAVar1;
    AEGeometry::setRotationOrder(pAVar1,2);
    local_40 = 0;
    local_3c = 0x440d4000;
    local_38 = 0xc4040000;
    AEGeometry::setPosition(*(Vector **)(this + 0x140));
  }
  else if (param_1 == 0x1a76) {
    pAVar1 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar1,0x1a77,Globals::Canvas,false);
    *(AEGeometry **)(this + 0x140) = pAVar1;
    AEGeometry::setRotationOrder(pAVar1,2);
    local_40 = 0;
    local_3c = 0x42700000;
    local_38 = 0;
    AEGeometry::setPosition(*(Vector **)(this + 0x140));
  }
  else if (param_1 == 0x1a74) {
    pAVar1 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar1,0x1a75,Globals::Canvas,false);
    *(AEGeometry **)(this + 0x140) = pAVar1;
    AEGeometry::setRotationOrder(pAVar1,2);
    local_40 = 0;
    local_3c = 0x42700000;
    local_38 = 0;
    AEGeometry::setPosition(*(Vector **)(this + 0x140));
  }
  pAVar1 = operator_new(0xc0);
  AEGeometry::AEGeometry(pAVar1,Globals::Canvas);
  *(AEGeometry **)(this + 0x144) = pAVar1;
  iVar2 = AbyssEngine::PaintCanvas::TransformGetTransform(Globals::Canvas,*(uint *)(pAVar1 + 0xc));
  *(undefined4 *)(iVar2 + 0xe0) = 0x49742400;
  (**(code **)(*(int *)this + 0x44))(this,&local_40);
  if (param_1 == 0x381b) {
    AEGeometry::rotate(*(AEGeometry **)(this + 0x13c),extraout_s0,extraout_s1,extraout_s2);
    AEGeometry::rotate(*(AEGeometry **)(this + 0x140),extraout_s0_00,extraout_s1_00,extraout_s2_00);
    AEGeometry::addChild(*(AEGeometry **)(this + 0x144),*(uint *)(*(int *)(this + 0x140) + 0xc));
  }
  else if ((param_1 | 2U) == 0x1a76) {
    AEGeometry::addChild(*(AEGeometry **)(this + 0x144),*(uint *)(*(int *)(this + 0x140) + 0xc));
  }
  else if (param_1 - 0x49c0U < 3) {
    this[0x3b] = (PlayerTurret)0x1;
    pAVar1 = operator_new(0xc0);
    uVar4 = 0x49c8;
    if (param_1 == 0x49c1) {
      uVar4 = 0x49c7;
    }
    if (param_1 == 0x49c0) {
      uVar4 = 0x49c6;
    }
    AEGeometry::AEGeometry(pAVar1,uVar4,Globals::Canvas,false);
    AEGeometry::addChild(param_3,*(uint *)(pAVar1 + 0xc));
    pvVar3 = (void *)AEGeometry::~AEGeometry(pAVar1);
    operator_delete(pvVar3);
    AEGeometry::setScaling(extraout_s0_01);
  }
  AEGeometry::addChild(*(AEGeometry **)(this + 0x144),*(uint *)(*(int *)(this + 0x13c) + 0xc));
  if (this[0x3b] == (PlayerTurret)0x0) {
    AEGeometry::addChild(param_3,*(uint *)(*(int *)(this + 0x144) + 0xc));
  }
  this_00 = operator_new(0x68);
  Explosion::Explosion(this_00,0);
  *(Explosion **)(this + 0x138) = this_00;
  Explosion::addFireStreaks(this_00);
  *(undefined4 *)(this + 0x148) = 0;
  *(undefined4 *)(this + 0x14c) = 0;
  *(undefined8 *)(this + 0x128) = 0;
  *(undefined8 *)(this + 0x130) = 0xffffffff00000000;
  if (__stack_chk_guard - local_34 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_34);
  }
  return;
}

// ===== PlayerTurret::~PlayerTurret  @0x001829a0  (102 bytes)
/* PlayerTurret::~PlayerTurret() */

void __thiscall PlayerTurret::~PlayerTurret(PlayerTurret *this)

{
  void *pvVar1;
  
  *(undefined ***)this = &PTR__PlayerTurret_002645c4;
  if (*(Explosion **)(this + 0x138) != (Explosion *)0x0) {
    pvVar1 = (void *)Explosion::~Explosion(*(Explosion **)(this + 0x138));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x138) = 0;
  if (*(AEGeometry **)(this + 0x13c) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x13c));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x13c) = 0;
  if (*(AEGeometry **)(this + 0x140) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x140));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x140) = 0;
  if (*(AEGeometry **)(this + 0x144) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x144));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x144) = 0;
  KIPlayer::~KIPlayer((KIPlayer *)this);
  return;
}

// ===== PlayerTurret::~PlayerTurret  @0x00182a0c  (16 bytes)
/* PlayerTurret::~PlayerTurret() */

void __thiscall PlayerTurret::~PlayerTurret(PlayerTurret *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~PlayerTurret(this);
  operator_delete(pvVar1);
  return;
}

// ===== PlayerTurret::setLevel  @0x00182a1c  (52 bytes)
/* PlayerTurret::setLevel(Level*) */

void __thiscall PlayerTurret::setLevel(PlayerTurret *this,Level *param_1)

{
  undefined4 uVar1;
  int iVar2;
  ParticleSystemManager *pPVar3;
  
  KIPlayer::setLevel((KIPlayer *)this,param_1);
  pPVar3 = *(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x74);
  uVar1 = AEGeometry::getReferenceMatrix(*(AEGeometry **)(this + 8));
  iVar2 = ParticleSystemManager::addSystem(pPVar3,uVar1,9,0);
  *(int *)(this + 0x134) = iVar2;
  ParticleSystemManager::enableSystemEmit
            (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x74),iVar2,false);
  return;
}

// ===== PlayerTurret::setScaling  @0x00182a50  (14 bytes)
/* PlayerTurret::setScaling(float) */

void PlayerTurret::setScaling(float param_1)

{
  int in_r0;
  float in_s1;
  float in_s2;
  
  AEGeometry::setScaling(*(AEGeometry **)(in_r0 + 0x144),param_1,in_s1,in_s2);
  return;
}

// ===== PlayerTurret::setPosition  @0x00182a5c  (28 bytes)
/* PlayerTurret::setPosition(AbyssEngine::AEMath::Vector const&) */

void __thiscall PlayerTurret::setPosition(PlayerTurret *this,Vector *param_1)

{
  AEGeometry::setPosition(*(Vector **)(this + 8));
  *(undefined4 *)(this + 0x54) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(param_1 + 8);
  return;
}

// ===== PlayerTurret::setTurretRange  @0x00182a78  (6 bytes)
/* PlayerTurret::setTurretRange(int) */

void __thiscall PlayerTurret::setTurretRange(PlayerTurret *this,int param_1)

{
  *(int *)(this + 0x160) = param_1;
  return;
}

// ===== PlayerTurret::setHost  @0x00182a7e  (14 bytes)
/* PlayerTurret::setHost(KIPlayer*, AbyssEngine::AEMath::Vector const&) */

void __thiscall PlayerTurret::setHost(PlayerTurret *this,KIPlayer *param_1,Vector *param_2)

{
  *(KIPlayer **)(this + 0x150) = param_1;
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x154),param_2);
  return;
}

// ===== PlayerTurret::getHost  @0x00182a8c  (6 bytes)
/* PlayerTurret::getHost() */

undefined4 __thiscall PlayerTurret::getHost(PlayerTurret *this)

{
  return *(undefined4 *)(this + 0x150);
}

// ===== PlayerTurret::reset  @0x00182a92  (28 bytes)
/* PlayerTurret::reset() */

void __thiscall PlayerTurret::reset(PlayerTurret *this)

{
  KIPlayer::reset((KIPlayer *)this);
  *(undefined4 *)(this + 0x84) = 0;
  KIPlayer::setActive(SUB41(this,0));
  return;
}

// ===== PlayerTurret::update  @0x00182ab0  (842 bytes)
/* PlayerTurret::update(int) */

void __thiscall PlayerTurret::update(PlayerTurret *this,int param_1)

{
  Player PVar1;
  int iVar2;
  Matrix *pMVar3;
  int *piVar4;
  undefined4 *__ptr;
  void *pvVar5;
  Player *pPVar6;
  Standing *pSVar7;
  uint uVar8;
  Vector *this_00;
  float extraout_s0;
  float fVar9;
  AEMath aAStack_6c [12];
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  *(int *)(this + 0x120) = param_1;
  iVar2 = Player::isActive(*(Player **)(this + 4));
  if (iVar2 == 1) {
    if ((this[0x3b] != (PlayerTurret)0x0) && (*(int *)(this + 0x124) < 3000)) {
      Player::setVulnerable(*(Player **)(this + 4),false);
      iVar2 = *(int *)(this + 0x124);
      *(int *)(this + 0x124) = iVar2 + param_1;
      if (2999 < iVar2 + param_1) {
        Player::setVulnerable(*(Player **)(this + 4),true);
      }
    }
    if (*(int *)(this + 0x150) != 0) {
      iVar2 = *(int *)(*(int *)(this + 0x150) + 4);
      local_60 = *(undefined4 *)(iVar2 + 4);
      uStack_5c = *(undefined4 *)(iVar2 + 8);
      local_58 = *(undefined4 *)(iVar2 + 0xc);
      uStack_54 = *(undefined4 *)(iVar2 + 0x10);
      uStack_50 = *(undefined4 *)(iVar2 + 0x14);
      local_4c = *(undefined4 *)(iVar2 + 0x18);
      uStack_48 = *(undefined4 *)(iVar2 + 0x1c);
      uStack_44 = *(undefined4 *)(iVar2 + 0x20);
      uStack_40 = *(undefined4 *)(iVar2 + 0x24);
      uStack_3c = *(undefined4 *)(iVar2 + 0x28);
      local_38 = *(undefined4 *)(iVar2 + 0x2c);
      uStack_34 = *(undefined4 *)(iVar2 + 0x30);
      uStack_30 = *(undefined4 *)(iVar2 + 0x34);
      uStack_2c = *(undefined4 *)(iVar2 + 0x38);
      uStack_28 = *(undefined4 *)(iVar2 + 0x3c);
      AbyssEngine::AEMath::MatrixRotateVector
                (aAStack_6c,(Matrix *)&local_60,(Vector *)(this + 0x154));
      AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x8c),(Vector *)aAStack_6c);
      AEGeometry::setMatrix(*(Matrix **)(this + 8));
      AEGeometry::translate(*(Vector **)(this + 8));
    }
    iVar2 = *(int *)(this + 4);
    pMVar3 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
    AbyssEngine::AEMath::Matrix::operator=((Matrix *)(iVar2 + 4),pMVar3);
    AEGeometry::getPosition();
    this_00 = (Vector *)(this + 0x28);
    AbyssEngine::AEMath::Vector::operator=(this_00,(Vector *)&local_60);
    iVar2 = Player::getHitpoints(*(Player **)(this + 4));
    if ((iVar2 < 1) && (1 < *(int *)(this + 0x84) - 3U)) {
      *(undefined4 *)(this + 0x84) = 3;
      *(undefined4 *)(this + 0x128) = 0;
      fVar9 = (float)FModSound::play(Globals::sound,0x16,(Vector *)0x0,(Vector *)0x0,extraout_s0);
      local_60 = 0;
      uStack_5c = 0;
      local_58 = 0;
      ParticleSystemManager::emitManual
                (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x74),
                 *(int *)(*(int *)(this + 0x50) + 0x3c),this_00,0,(Vector *)&local_60,fVar9);
      ParticleSystemManager::enableSystemEmit
                (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x74),*(int *)(this + 0x134),
                 true);
      local_60 = 0;
      uStack_5c = 0;
      local_58 = 0;
      Explosion::start(*(Explosion **)(this + 0x138),this_00,(Vector *)&local_60);
      iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
      if (iVar2 < 0) {
        this[0x48] = (PlayerTurret)0x1;
        piVar4 = operator_new(0xc);
        __ptr = operator_new__(4);
        piVar4[1] = (int)__ptr;
        *__ptr = 0;
        *piVar4 = 0;
        *(int **)(this + 0x4c) = piVar4;
        piVar4[2] = 1;
        pvVar5 = realloc(__ptr,4);
        piVar4[1] = (int)pvVar5;
        *(undefined4 *)((int)pvVar5 + *piVar4 * 4) = 99;
        *piVar4 = piVar4[2];
        iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,10);
        piVar4 = *(int **)(this + 0x4c);
        piVar4[2] = *piVar4 + 1;
        pvVar5 = realloc((void *)piVar4[1],(*piVar4 + 1) * 4);
        piVar4[1] = (int)pvVar5;
        *(int *)((int)pvVar5 + *piVar4 * 4) = iVar2 + 1;
        *piVar4 = piVar4[2];
        KIPlayer::createCrate((KIPlayer *)this,3);
        this[0x48] = (PlayerTurret)0x1;
      }
      else {
        iVar2 = Level::getPlayer(*(Level **)(this + 0x50));
        if (((iVar2 != 0) &&
            (iVar2 = Level::getPlayer(*(Level **)(this + 0x50)), *(int *)(iVar2 + 0x14) != 0)) &&
           (iVar2 = Level::getPlayer(*(Level **)(this + 0x50)),
           *(PlayerTurret **)(*(int *)(iVar2 + 0x14) + 0x1c) == this)) {
          iVar2 = Level::getPlayer(*(Level **)(this + 0x50));
          *(undefined4 *)(*(int *)(iVar2 + 0x14) + 0x1c) = 0;
        }
      }
    }
    if (*(int *)(this + 0x84) != 4) {
      if (*(int *)(this + 0x84) == 3) {
        *(int *)(this + 0x128) = *(int *)(this + 0x128) + param_1;
        Explosion::update(*(Explosion **)(this + 0x138),param_1,(TargetFollowCamera *)0x0);
        if (0x1194 < *(int *)(this + 0x128)) {
          ParticleSystemManager::enableSystemEmit
                    (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x74),
                     *(int *)(this + 0x134),false);
          *(undefined4 *)(this + 0x84) = 4;
          *(undefined4 *)(this + 0x128) = 0;
          Player::setActive(*(Player **)(this + 4),false);
          if (this[0x3b] != (PlayerTurret)0x0) {
            *(int *)(*(int *)(this + 0x50) + 0x6c) = *(int *)(*(int *)(this + 0x50) + 0x6c) + -1;
          }
        }
      }
      else {
        uVar8 = *(uint *)(this + 0x24);
        if ((uVar8 & 0xfffffffe) == 8) {
          PVar1 = (Player)0x1;
        }
        else {
          pSVar7 = (Standing *)Status::getStanding(Globals::status);
          PVar1 = (Player)Standing::isEnemy(pSVar7,*(int *)(this + 0x24));
          uVar8 = *(uint *)(this + 0x24);
        }
        pPVar6 = *(Player **)(this + 4);
        pPVar6[0x5c] = PVar1;
        if ((uVar8 & 0xfffffffe) == 8) {
          PVar1 = (Player)0x0;
        }
        else {
          pSVar7 = (Standing *)Status::getStanding(Globals::status);
          PVar1 = (Player)Standing::isFriend(pSVar7,*(int *)(this + 0x24));
          pPVar6 = *(Player **)(this + 4);
        }
        pPVar6[0x5d] = PVar1;
        iVar2 = Player::turnedEnemy(pPVar6);
        pPVar6 = *(Player **)(this + 4);
        if (iVar2 == 1) {
          *(undefined2 *)(pPVar6 + 0x5c) = 1;
        }
        iVar2 = Player::isAlwaysFriend(pPVar6);
        if (iVar2 == 1) {
          iVar2 = *(int *)(this + 4);
          *(undefined1 *)(iVar2 + 0x5d) = 1;
          *(undefined1 *)(iVar2 + 0x5c) = 0;
        }
        if (this[0x3b] == (PlayerTurret)0x0) {
          if ((this[0x21] != (PlayerTurret)0x0) && (*(int *)(this + 0x140) != 0)) {
            handleTurret(this,param_1);
          }
        }
        else {
          handleSentryGun(this,param_1);
        }
      }
    }
  }
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerTurret::handleSentryGun  @0x00182e24  (54 bytes)
/* PlayerTurret::handleSentryGun(int) */

void __thiscall PlayerTurret::handleSentryGun(PlayerTurret *this,int param_1)

{
  *(int *)(this + 300) = *(int *)(this + 300) + param_1;
  pickEnemy(this);
  if ((*(int *)(this + 0x148) != 0) && (*(char *)(*(int *)(this + 0x148) + 0x5e) == '\0')) {
    handleRotation(this,param_1,*(AEGeometry **)(this + 8),*(AEGeometry **)(this + 8));
    return;
  }
  return;
}

// ===== PlayerTurret::handleTurret  @0x00182e5a  (56 bytes)
/* PlayerTurret::handleTurret(int) */

void __thiscall PlayerTurret::handleTurret(PlayerTurret *this,int param_1)

{
  *(int *)(this + 300) = *(int *)(this + 300) + param_1;
  pickEnemy(this);
  if ((*(int *)(this + 0x148) != 0) && (*(char *)(*(int *)(this + 0x148) + 0x5e) == '\0')) {
    handleRotation(this,param_1,*(AEGeometry **)(this + 0x144),*(AEGeometry **)(this + 0x140));
    return;
  }
  return;
}

// ===== PlayerTurret::pickEnemy  @0x00182e90  (332 bytes)
/* PlayerTurret::pickEnemy() */

void __thiscall PlayerTurret::pickEnemy(PlayerTurret *this)

{
  uint *puVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  Player *this_00;
  uint uVar5;
  int iVar6;
  Vector aVStack_40 [12];
  AEMath aAStack_34 [12];
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (3000 < *(int *)(this + 300)) {
    *(undefined4 *)(this + 0x148) = 0;
    *(undefined4 *)(this + 300) = 0;
    iVar6 = *(int *)(this + 0x160);
    puVar1 = (uint *)Player::getEnemies(*(Player **)(this + 4));
    if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
      uVar5 = 0;
      do {
        this_00 = *(Player **)(puVar1[1] + uVar5 * 4);
        iVar2 = Player::isDead(this_00);
        if ((iVar2 == 0) && (iVar2 = Player::isActive(this_00), iVar2 == 1)) {
          if ((this_00[0x69] == (Player)0x0) || (*(char *)(*(int *)(this + 4) + 0x5c) == '\0')) {
            if (this[0x3b] == (PlayerTurret)0x0) {
              iVar2 = Player::getKIPlayer(this_00);
              if (iVar2 != 0) {
                iVar2 = Player::getKIPlayer(this_00);
                iVar2 = *(int *)(iVar2 + 0x24);
                iVar4 = *(int *)(this + 0x24);
                if ((((((iVar2 == 8) && (iVar4 != 8)) || ((iVar2 != 8 && (iVar4 == 8)))) ||
                     ((iVar2 == 10 && (iVar4 != 10)))) || ((iVar2 != 10 && (iVar4 == 10)))) ||
                   ((((iVar2 == 9 && (iVar4 != 9)) || ((iVar2 != 9 && (iVar4 == 9)))) ||
                    ((((iVar2 == 0 && (iVar4 == 1)) || (iVar2 == 1 && iVar4 == 0)) ||
                     ((iVar2 == 3 && iVar4 == 2 || (iVar2 == 2 && iVar4 == 3))))))))
                goto LAB_00182f74;
              }
            }
            else if (this_00[0x5c] != (Player)0x0) goto LAB_00182f74;
          }
          else {
LAB_00182f74:
            Player::getPosition();
            AbyssEngine::AEMath::operator-(aAStack_34,(Vector *)(this + 0x28),aVStack_40);
            fVar3 = (float)AbyssEngine::AEMath::VectorLength((Vector *)aAStack_34);
            if (((int)fVar3 < iVar6) &&
               ((*(int *)(this + 0x148) == 0 || (*(int *)(this + 0x148) != *(int *)(this + 0x14c))))
               ) {
              *(Player **)(this + 0x148) = this_00;
              iVar6 = (int)fVar3;
            }
          }
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < *puVar1);
    }
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerTurret::handleRotation  @0x00182fe4  (680 bytes)
/* PlayerTurret::handleRotation(int, AEGeometry*, AEGeometry*) */

void __thiscall
PlayerTurret::handleRotation(PlayerTurret *this,int param_1,AEGeometry *param_2,AEGeometry *param_3)

{
  uint uVar1;
  byte bVar2;
  bool bVar3;
  Matrix *pMVar4;
  Matrix *pMVar5;
  int iVar6;
  uint in_fpscr;
  uint uVar7;
  float fVar8;
  float fVar9;
  float extraout_s1;
  float extraout_s1_00;
  float fVar10;
  float fVar11;
  longlong lVar12;
  Vector aVStack_10c [60];
  float local_d0;
  float local_cc;
  AEMath aAStack_94 [12];
  AEMath aAStack_88 [12];
  AEMath aAStack_7c [12];
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 uStack_60;
  undefined4 local_5c;
  undefined4 uStack_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  int local_34;
  
  local_34 = __stack_chk_guard;
  iVar6 = *(int *)(this + 0x148);
  local_70 = *(undefined4 *)(iVar6 + 4);
  local_6c = *(undefined4 *)(iVar6 + 8);
  local_68 = *(undefined4 *)(iVar6 + 0xc);
  local_64 = *(undefined4 *)(iVar6 + 0x10);
  uStack_60 = *(undefined4 *)(iVar6 + 0x14);
  local_5c = *(undefined4 *)(iVar6 + 0x18);
  uStack_58 = *(undefined4 *)(iVar6 + 0x1c);
  local_54 = *(undefined4 *)(iVar6 + 0x20);
  uStack_50 = *(undefined4 *)(iVar6 + 0x24);
  uStack_4c = *(undefined4 *)(iVar6 + 0x28);
  local_48 = *(undefined4 *)(iVar6 + 0x2c);
  uStack_44 = *(undefined4 *)(iVar6 + 0x30);
  local_40 = *(undefined4 *)(iVar6 + 0x34);
  uStack_3c = *(undefined4 *)(iVar6 + 0x38);
  uStack_38 = *(undefined4 *)(iVar6 + 0x3c);
  Player::getPosition();
  AbyssEngine::AEMath::MatrixGetDir(aAStack_94,(Matrix *)&local_70);
  fVar8 = (float)AbyssEngine::AEMath::VectorNormalize(aAStack_88,(Vector *)aAStack_94);
  AbyssEngine::AEMath::operator*(aAStack_7c,(Vector *)aAStack_88,fVar8);
  AbyssEngine::AEMath::operator+((AEMath *)&local_d0,aVStack_10c,(Vector *)aAStack_7c);
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x98),(Vector *)&local_d0);
  if (this[0x3b] == (PlayerTurret)0x0) {
    pMVar4 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
    pMVar5 = (Matrix *)AEGeometry::getMatrix(param_2);
    AbyssEngine::AEMath::operator*((AEMath *)aVStack_10c,pMVar4,pMVar5);
    pMVar4 = (Matrix *)AEGeometry::getMatrix(param_3);
    AbyssEngine::AEMath::operator*((AEMath *)&local_d0,(AEMath *)aVStack_10c,pMVar4);
    AbyssEngine::AEMath::Matrix::operator=((Matrix *)&local_70,(AEMath *)&local_d0);
  }
  else {
    pMVar4 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
    AbyssEngine::AEMath::Matrix::operator=((Matrix *)&local_70,pMVar4);
  }
  AbyssEngine::AEMath::MatrixInverseTransformVector
            ((AEMath *)aVStack_10c,(Matrix *)&local_70,(Vector *)(this + 0x98));
  AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_d0,aVStack_10c);
  in_fpscr = in_fpscr & 0xfffffff;
  uVar1 = in_fpscr | (uint)(local_d0 < 0.05) << 0x1f | (uint)(local_d0 == 0.05) << 0x1e;
  uVar7 = uVar1 | (uint)NAN(local_d0) << 0x1c;
  bVar2 = (byte)(uVar1 >> 0x18);
  iVar6 = param_1;
  if ((bool)(bVar2 >> 6 & 1) || bVar2 >> 7 != ((byte)(uVar7 >> 0x1c) & 1)) {
    if (local_d0 < -0.05) {
      iVar6 = -param_1;
      uVar7 = in_fpscr;
      goto LAB_001830fe;
    }
    bVar3 = true;
    fVar8 = extraout_s1;
  }
  else {
LAB_001830fe:
    in_fpscr = uVar7;
    fVar8 = (float)VectorSignedToFloat(iVar6,(byte)(in_fpscr >> 0x16) & 3);
    bVar3 = false;
    AEGeometry::rotate(param_2,fVar8 * 0.00024414062 * 6.2831855,extraout_s1,6.2831855);
    fVar8 = extraout_s1_00;
  }
  in_fpscr = in_fpscr & 0xfffffff;
  uVar1 = in_fpscr | (uint)(local_cc < 0.05) << 0x1f | (uint)(local_cc == 0.05) << 0x1e;
  bVar2 = (byte)(uVar1 >> 0x18);
  if ((bool)(bVar2 >> 6 & 1) || (bool)(bVar2 >> 7) != NAN(local_cc)) {
    if (-0.05 <= local_cc) {
      if (bVar3) {
        Player::shoot(*(undefined4 *)(this + 4),0,param_1,param_1 >> 0x1f,0,local_70,local_6c,
                      local_68,local_64,uStack_60,local_5c,uStack_58,local_54,uStack_50,uStack_4c,
                      local_48,uStack_44,local_40,uStack_3c,uStack_38);
        lVar12 = AbyssEngine::PaintCanvas::TransformGetTransform
                           (Globals::Canvas,*(uint *)(param_3 + 0xc));
        AbyssEngine::Transform::Update(lVar12,SUB41(param_1,0));
      }
      goto LAB_0018326e;
    }
    if ((this[0x3b] == (PlayerTurret)0x0) && (99 < *(int *)(this + 0x130))) goto LAB_00183196;
    fVar11 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x120),(byte)(in_fpscr >> 0x16) & 3);
    fVar10 = fVar11 * 0.00024414062 * 6.2831855;
    fVar9 = (float)VectorSignedToFloat(*(int *)(this + 0x130),(byte)(in_fpscr >> 0x16) & 3);
    fVar11 = fVar11 + fVar9;
  }
  else {
    if ((this[0x3b] == (PlayerTurret)0x0) && (*(int *)(this + 0x130) < -599)) {
LAB_00183196:
      *(undefined4 *)(this + 0x14c) = *(undefined4 *)(this + 0x148);
      *(int *)(this + 300) = *(int *)(this + 300) + param_1;
      goto LAB_0018326e;
    }
    fVar9 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x120),(byte)(uVar1 >> 0x16) & 3);
    fVar10 = fVar9 * 0.00024414062 * -6.2831855;
    fVar11 = (float)VectorSignedToFloat(*(int *)(this + 0x130),(byte)(uVar1 >> 0x16) & 3);
    fVar11 = fVar11 - fVar9;
  }
  *(int *)(this + 0x130) = (int)fVar11;
  AEGeometry::rotate(param_3,(float)(int)fVar11,fVar8,fVar10);
  *(undefined4 *)(this + 0x14c) = 0;
LAB_0018326e:
  if (__stack_chk_guard == local_34) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== PlayerTurret::render  @0x001832ac  (52 bytes)
/* PlayerTurret::render() */

void __thiscall PlayerTurret::render(PlayerTurret *this)

{
  int iVar1;
  
  if (*(AEGeometry **)(this + 0x74) != (AEGeometry *)0x0) {
    AEGeometry::render(*(AEGeometry **)(this + 0x74));
  }
  iVar1 = *(int *)(this + 0x84);
  if (iVar1 == 3) {
    Explosion::render(*(Explosion **)(this + 0x138));
    iVar1 = *(int *)(this + 0x84);
  }
  if (1 < iVar1 - 3U) {
    (*(code *)&LAB_0006bd38)(this);
    return;
  }
  return;
}

// ===== PlayerTurret::collide  @0x001832e0  (4 bytes)
/* PlayerTurret::collide(float, float, float) */

undefined4 PlayerTurret::collide(float param_1,float param_2,float param_3)

{
  return 0;
}

// ===== PlayerTurret::outerCollide  @0x001832e4  (4 bytes)
/* PlayerTurret::outerCollide(float, float, float) */

undefined4 PlayerTurret::outerCollide(float param_1,float param_2,float param_3)

{
  return 0;
}

// ===== PlayerTurret::revive  @0x001832e8  (70 bytes)
/* PlayerTurret::revive() */

void __thiscall PlayerTurret::revive(PlayerTurret *this)

{
  AEGeometry *this_00;
  
  Player::reset(*(Player **)(this + 4));
  *(undefined4 *)(this + 0x84) = 1;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0xd4) = 0;
  KIPlayer::setActive(SUB41(this,0));
  Explosion::reset(*(Explosion **)(this + 0x138));
  this[0xf1] = (PlayerTurret)0x1;
  *(undefined4 *)(this + 0x124) = 0;
  this_00 = *(AEGeometry **)(this + 0xc);
  if (this_00 == (AEGeometry *)0x0) {
    this_00 = *(AEGeometry **)(this + 8);
  }
  AEGeometry::setVisible(this_00,true);
  return;
}

