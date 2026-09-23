// Class: KIPlayer
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== KIPlayer::initPush  @0x000b1d08  (2 bytes)
/* KIPlayer::initPush(AbyssEngine::AEMath::Vector const&, int) */

Vector * KIPlayer::initPush(Vector *param_1,int param_2)

{
  return param_1;
}

// ===== KIPlayer::push  @0x000b1d0a  (2 bytes)
/* KIPlayer::push(int) */

int KIPlayer::push(int param_1)

{
  return param_1;
}

// ===== KIPlayer::outerCollide  @0x000b1d0c  (26 bytes)
/* KIPlayer::outerCollide(AbyssEngine::AEMath::Vector const&) */

void __thiscall KIPlayer::outerCollide(KIPlayer *this,Vector *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000b1d24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0x3c))
            (this,*(undefined4 *)param_1,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
  return;
}

// ===== KIPlayer::getSpeed  @0x000b1d26  (4 bytes)
/* KIPlayer::getSpeed() */

undefined4 KIPlayer::getSpeed(void)

{
  return 0;
}

// ===== KIPlayer::getCollisionNormal  @0x000b1d2a  (10 bytes)
/* KIPlayer::getCollisionNormal(AbyssEngine::AEMath::Vector const&) */

void KIPlayer::getCollisionNormal(Vector *param_1)

{
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

// ===== KIPlayer::setState  @0x000b1d34  (6 bytes)
/* KIPlayer::setState(int) */

void __thiscall KIPlayer::setState(KIPlayer *this,int param_1)

{
  *(int *)(this + 0x84) = param_1;
  return;
}

// ===== KIPlayer::KIPlayer  @0x000b2328  (546 bytes)
/* KIPlayer::KIPlayer(int, int, Player*, AEGeometry*, float, float, float, bool) */

void __thiscall
KIPlayer::KIPlayer(KIPlayer *this,int param_1,int param_2,Player *param_3,AEGeometry *param_4,
                  float param_5,float param_6,float param_7,bool param_8)

{
  AEGeometry *this_00;
  Matrix *pMVar1;
  int iVar2;
  float extraout_s0;
  float extraout_s1;
  float extraout_s2;
  undefined3 in_stack_00000005;
  undefined4 in_stack_00000008;
  undefined4 in_stack_0000000c;
  int in_stack_00000010;
  String aSStack_44 [8];
  int local_3c;
  
  local_3c = __stack_chk_guard;
  *(undefined ***)this = &PTR__KIPlayer_00263f00;
  AbyssEngine::String::String((String *)(this + 0x18));
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0xb0) = 0;
  *(undefined4 *)(this + 0xc0) = 0;
  *(undefined4 *)(this + 0xc4) = 0;
  *(undefined4 *)(this + 0x8c) = 0;
  *(undefined4 *)(this + 0x90) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x94) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x98) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x9c) = 0;
  *(undefined4 *)(this + 0xa0) = 0;
  *(undefined4 *)(this + 0x108) = 0;
  *(undefined4 *)(this + 0x10c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x110) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x114) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x118) = 0;
  *(undefined4 *)(this + 0x11c) = 0;
  *(Player **)(this + 4) = param_3;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 200) = 0;
  if ((param_4 == (AEGeometry *)0x0) || (in_stack_00000010 != 1)) {
    *(AEGeometry **)(this + 8) = param_4;
    *(undefined4 *)(this + 0xc) = 0;
  }
  else {
    *(AEGeometry **)(this + 0xc) = param_4;
    this_00 = operator_new(0xc0);
    AEGeometry::AEGeometry(this_00,Globals::Canvas);
    *(AEGeometry **)(this + 8) = this_00;
    AEGeometry::addChild(this_00,*(uint *)(*(int *)(this + 0xc) + 0xc));
    *(undefined4 *)(*(int *)(this + 0xc) + 0x24) = *(undefined4 *)(*(int *)(this + 8) + 0xc);
  }
  *(int *)(this + 0x24) = param_2;
  *(undefined4 *)(this + 0x4c) = 0;
  this[0x6e] = (KIPlayer)0x0;
  this[0x21] = (KIPlayer)0x0;
  this[0x71] = (KIPlayer)0x0;
  this[0x38] = (KIPlayer)0x0;
  this[0x39] = (KIPlayer)0x0;
  this[0x3a] = (KIPlayer)0x0;
  this[0x3e] = (KIPlayer)0x0;
  this[0x3f] = (KIPlayer)0x0;
  this[0x40] = (KIPlayer)0x0;
  *(undefined4 *)(this + 0x44) = 0xffffffff;
  this[0x88] = (KIPlayer)0x1;
  this[0x3b] = (KIPlayer)0x0;
  this[0x48] = (KIPlayer)0x0;
  this[0xcc] = (KIPlayer)0x0;
  this[100] = (KIPlayer)0x0;
  this[0x65] = (KIPlayer)0x0;
  this[0x66] = (KIPlayer)0x0;
  this[0xd8] = (KIPlayer)0x0;
  this[0xe8] = (KIPlayer)0x0;
  this[0xf0] = (KIPlayer)0x0;
  AbyssEngine::String::String(aSStack_44,"",false);
  AbyssEngine::String::operator=((String *)(this + 0x18),aSStack_44);
  AbyssEngine::String::~String(aSStack_44);
  this[0xf1] = (KIPlayer)0x1;
  this[0x20] = (KIPlayer)0x0;
  *(undefined4 *)(this + 0xe4) = 0;
  this[0x3c] = (KIPlayer)0x0;
  this[0x6d] = (KIPlayer)0x0;
  this[0x6c] = (KIPlayer)0x0;
  this[0x3d] = (KIPlayer)0x0;
  *(undefined4 *)(this + 0xd4) = 0;
  *(undefined4 *)(this + 0x7c) = 0xffffffff;
  *(undefined4 *)(this + 0x80) = 0xffffffff;
  *(undefined4 *)(this + 0x100) = 0;
  Player::setKIPlayer(*(Player **)(this + 4),this);
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  this[0xad] = (KIPlayer)0x0;
  this[0xae] = (KIPlayer)0x1;
  this[0xb8] = (KIPlayer)0x0;
  *(undefined4 *)(this + 0xbc) = 0xff;
  *(int *)(this + 0xa8) = param_1;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0xa4) = 0x40a00000;
  *(undefined4 *)(this + 0x60) = 0x40066666;
  if (param_4 != (AEGeometry *)0x0) {
    AEGeometry::setPosition(extraout_s0,extraout_s1,extraout_s2);
    iVar2 = *(int *)(this + 4);
    pMVar1 = (Matrix *)AEGeometry::getMatrix(param_4);
    AbyssEngine::AEMath::Matrix::operator=((Matrix *)(iVar2 + 4),pMVar1);
    if (*(AEGeometry **)(this + 0xc) != (AEGeometry *)0x0) {
      iVar2 = *(int *)(this + 4);
      pMVar1 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 0xc));
      AbyssEngine::AEMath::Matrix::operator*=((Matrix *)(iVar2 + 4),pMVar1);
    }
  }
  *(undefined4 *)(this + 0x54) = _param_8;
  *(undefined4 *)(this + 0x58) = in_stack_00000008;
  *(undefined4 *)(this + 0x5c) = in_stack_0000000c;
  *(undefined4 *)(this + 0x14) = 0;
  this[0x70] = (KIPlayer)0x0;
  this[0x6f] = (KIPlayer)0x0;
  this[0x72] = (KIPlayer)0x0;
  *(undefined4 *)(this + 0xf4) = 0xffffffff;
  *(undefined4 *)(this + 0xf8) = 0;
  *(undefined2 *)(this + 0xfc) = 0x100;
  if (__stack_chk_guard - local_3c != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_3c);
  }
  return;
}

// ===== KIPlayer::~KIPlayer  @0x000b2584  (190 bytes)
/* KIPlayer::~KIPlayer() */

KIPlayer * __thiscall KIPlayer::~KIPlayer(KIPlayer *this)

{
  void *pvVar1;
  
  *(undefined ***)this = &PTR__KIPlayer_00263f00;
  if (*(Player **)(this + 4) != (Player *)0x0) {
    pvVar1 = (void *)Player::~Player(*(Player **)(this + 4));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 4) = 0;
  if (*(Route **)(this + 0x68) != (Route *)0x0) {
    pvVar1 = (void *)Route::~Route(*(Route **)(this + 0x68));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x68) = 0;
  if (*(AEGeometry **)(this + 0x74) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x74));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x74) = 0;
  pvVar1 = *(void **)(this + 0xc0);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xc0) = 0;
  if (*(AEGeometry **)(this + 8) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 8));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 8) = 0;
  if (*(AEGeometry **)(this + 0xc) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0xc));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xc) = 0;
  pvVar1 = *(void **)(this + 0x4c);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x4c) = 0;
  if (*(Array **)(this + 200) != (Array *)0x0) {
    ArrayReleaseClasses<SpacePoint*>(*(Array **)(this + 200));
    pvVar1 = *(void **)(this + 200);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
    *(undefined4 *)(this + 200) = 0;
  }
  AbyssEngine::String::~String((String *)(this + 0x18));
  return this;
}

// ===== KIPlayer::~KIPlayer  @0x000b268a  (16 bytes)
/* KIPlayer::~KIPlayer() */

void __thiscall KIPlayer::~KIPlayer(KIPlayer *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~KIPlayer(this);
  operator_delete(pvVar1);
  return;
}

// ===== KIPlayer::isVisible  @0x000b269a  (6 bytes)
/* KIPlayer::isVisible() */

KIPlayer __thiscall KIPlayer::isVisible(KIPlayer *this)

{
  return this[0xf1];
}

// ===== KIPlayer::setVisible  @0x000b26a0  (16 bytes)
/* KIPlayer::setVisible(bool) */

void __thiscall KIPlayer::setVisible(KIPlayer *this,bool param_1)

{
  this[0xf1] = (KIPlayer)param_1;
  if (*(AEGeometry **)(this + 8) == (AEGeometry *)0x0) {
    return;
  }
  AEGeometry::setVisible(*(AEGeometry **)(this + 8),param_1);
  return;
}

// ===== KIPlayer::setSpacePoints  @0x000b26b0  (6 bytes)
/* KIPlayer::setSpacePoints(Array<SpacePoint*>*) */

void __thiscall KIPlayer::setSpacePoints(KIPlayer *this,Array *param_1)

{
  *(Array **)(this + 200) = param_1;
  return;
}

// ===== KIPlayer::getSpacePoints  @0x000b26b6  (6 bytes)
/* KIPlayer::getSpacePoints() */

undefined4 __thiscall KIPlayer::getSpacePoints(KIPlayer *this)

{
  return *(undefined4 *)(this + 200);
}

// ===== KIPlayer::getNearestNavigationPoint  @0x000b26bc  (264 bytes)
/* KIPlayer::getNearestNavigationPoint(AbyssEngine::AEMath::Vector const&, SpacePoint*) */

void __thiscall
KIPlayer::getNearestNavigationPoint(KIPlayer *this,Vector *param_1,SpacePoint *param_2)

{
  Matrix *pMVar1;
  float fVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  AEMath aAStack_6c [12];
  AEMath aAStack_60 [12];
  AEMath aAStack_54 [12];
  Vector aVStack_48 [12];
  int local_3c;
  
  local_3c = __stack_chk_guard;
  if (*(int *)(this + 200) != 0) {
    (**(code **)(*(int *)this + 0x28))(aVStack_48,this);
    puVar4 = *(uint **)(this + 200);
    if (*puVar4 != 0) {
      fVar6 = 1e+08;
      uVar5 = 0;
      do {
        if (*(int *)(*(int *)(puVar4[1] + uVar5 * 4) + 0x18) == 1) {
          pMVar1 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
          AbyssEngine::AEMath::MatrixRotateVector
                    (aAStack_6c,pMVar1,*(Vector **)(*(int *)(*(int *)(this + 200) + 4) + uVar5 * 4))
          ;
          AbyssEngine::AEMath::operator+(aAStack_60,aVStack_48,(Vector *)aAStack_6c);
          AbyssEngine::AEMath::operator-(aAStack_54,(Vector *)aAStack_60,param_1);
          fVar2 = (float)AbyssEngine::AEMath::VectorLength((Vector *)aAStack_54);
          fVar7 = -fVar2;
          if (0.0 < fVar2) {
            fVar7 = fVar2;
          }
          puVar4 = *(uint **)(this + 200);
          if ((int)((uint)(fVar7 < fVar6) << 0x1f) < 0) {
            iVar3 = SpacePoint::isFree(*(SpacePoint **)(puVar4[1] + uVar5 * 4));
            puVar4 = *(uint **)(this + 200);
            if ((iVar3 != 0) || (*(SpacePoint **)(puVar4[1] + uVar5 * 4) == param_2)) {
              fVar6 = fVar7;
            }
          }
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < *puVar4);
    }
  }
  if (__stack_chk_guard - local_3c == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_3c);
}

// ===== KIPlayer::getNearestDockingPoint  @0x000b27d0  (234 bytes)
/* KIPlayer::getNearestDockingPoint(AbyssEngine::AEMath::Vector const&) */

void __thiscall KIPlayer::getNearestDockingPoint(KIPlayer *this,Vector *param_1)

{
  uint *puVar1;
  Matrix *pMVar2;
  float fVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  AEMath aAStack_64 [12];
  AEMath aAStack_58 [12];
  AEMath aAStack_4c [12];
  Vector aVStack_40 [12];
  int local_34;
  
  local_34 = __stack_chk_guard;
  if (*(int *)(this + 200) != 0) {
    (**(code **)(*(int *)this + 0x28))(aVStack_40,this);
    puVar1 = *(uint **)(this + 200);
    if (*puVar1 != 0) {
      fVar6 = 1e+08;
      uVar4 = 0;
      do {
        if (*(int *)(*(int *)(puVar1[1] + uVar4 * 4) + 0x18) == 2) {
          pMVar2 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
          AbyssEngine::AEMath::MatrixRotateVector
                    (aAStack_64,pMVar2,*(Vector **)(*(int *)(*(int *)(this + 200) + 4) + uVar4 * 4))
          ;
          AbyssEngine::AEMath::operator+(aAStack_58,aVStack_40,(Vector *)aAStack_64);
          AbyssEngine::AEMath::operator-(aAStack_4c,(Vector *)aAStack_58,param_1);
          fVar3 = (float)AbyssEngine::AEMath::VectorLength((Vector *)aAStack_4c);
          fVar5 = -fVar3;
          if (0.0 < fVar3) {
            fVar5 = fVar3;
          }
          puVar1 = *(uint **)(this + 200);
          if ((int)((uint)(fVar5 < fVar6) << 0x1f) < 0) {
            fVar6 = fVar5;
          }
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *puVar1);
    }
  }
  if (__stack_chk_guard - local_34 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_34);
}

// ===== KIPlayer::setShipGroup  @0x000b28c8  (142 bytes)
/* KIPlayer::setShipGroup(AEGeometry*, int, bool) */

void KIPlayer::setShipGroup(AEGeometry *param_1,int param_2,bool param_3)

{
  void *pvVar1;
  Matrix *pMVar2;
  int in_r3;
  AEGeometry *this;
  int iVar3;
  float in_s0;
  float extraout_s0;
  float extraout_s0_00;
  float in_s1;
  float extraout_s1;
  float extraout_s1_00;
  float in_s2;
  float extraout_s2;
  float extraout_s2_00;
  
  *(uint *)(param_1 + 0x78) = (uint)param_3;
  if ((param_2 == 0) || (in_r3 != 1)) {
    *(int *)(param_1 + 8) = param_2;
    if (*(AEGeometry **)(param_1 + 0xc) != (AEGeometry *)0x0) {
      pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(param_1 + 0xc));
      operator_delete(pvVar1);
      in_s0 = extraout_s0_00;
      in_s1 = extraout_s1_00;
      in_s2 = extraout_s2_00;
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  else {
    *(int *)(param_1 + 0xc) = param_2;
    this = *(AEGeometry **)(param_1 + 8);
    if (this == (AEGeometry *)0x0) {
      this = operator_new(0xc0);
      AEGeometry::AEGeometry(this,Globals::Canvas);
      *(AEGeometry **)(param_1 + 8) = this;
      param_2 = *(int *)(param_1 + 0xc);
    }
    AEGeometry::addChild(this,*(uint *)(param_2 + 0xc));
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x24) = *(undefined4 *)(*(int *)(param_1 + 8) + 0xc);
    in_s0 = extraout_s0;
    in_s1 = extraout_s1;
    in_s2 = extraout_s2;
  }
  AEGeometry::setPosition(in_s0,in_s1,in_s2);
  iVar3 = *(int *)(param_1 + 4);
  pMVar2 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(param_1 + 8));
  AbyssEngine::AEMath::Matrix::operator=((Matrix *)(iVar3 + 4),pMVar2);
  if (*(AEGeometry **)(param_1 + 0xc) == (AEGeometry *)0x0) {
    return;
  }
  iVar3 = *(int *)(param_1 + 4);
  pMVar2 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(param_1 + 0xc));
  AbyssEngine::AEMath::Matrix::operator*=((Matrix *)(iVar3 + 4),pMVar2);
  return;
}

// ===== KIPlayer::setJumper  @0x000b2968  (6 bytes)
/* KIPlayer::setJumper(bool) */

void __thiscall KIPlayer::setJumper(KIPlayer *this,bool param_1)

{
  this[0xe8] = (KIPlayer)param_1;
  return;
}

// ===== KIPlayer::isJumper  @0x000b296e  (6 bytes)
/* KIPlayer::isJumper() */

KIPlayer __thiscall KIPlayer::isJumper(KIPlayer *this)

{
  return this[0xe8];
}

// ===== KIPlayer::setInitialRotation  @0x000b2974  (2 bytes)
/* KIPlayer::setInitialRotation(AbyssEngine::AEMath::Vector) */

void KIPlayer::setInitialRotation(void)

{
  return;
}

// ===== KIPlayer::reset  @0x000b2976  (82 bytes)
/* KIPlayer::reset() */

void __thiscall KIPlayer::reset(KIPlayer *this)

{
  Route *this_00;
  
  if (*(Player **)(this + 4) != (Player *)0x0) {
    Player::reset(*(Player **)(this + 4));
  }
  if ((this[0xad] != (KIPlayer)0x0) || (this[0xae] == (KIPlayer)0x0)) {
    *(undefined4 *)(this + 0x84) = 5;
    Player::setActive(*(Player **)(this + 4),false);
    this[0xad] = (KIPlayer)0x1;
  }
  this_00 = *(Route **)(this + 0xb0);
  if (this_00 == (Route *)0x0) {
    if (*(Route **)(this + 0x68) != (Route *)0x0) {
      Route::reset(*(Route **)(this + 0x68));
    }
  }
  else {
    *(Route **)(this + 0x68) = this_00;
    Route::reset(this_00);
  }
  *(undefined4 *)(this + 0xf8) = 0;
  this[0xfc] = (KIPlayer)0x0;
  return;
}

// ===== KIPlayer::setToSleep  @0x000b29c8  (28 bytes)
/* KIPlayer::setToSleep() */

void __thiscall KIPlayer::setToSleep(KIPlayer *this)

{
  *(undefined4 *)(this + 0x84) = 5;
  Player::setActive(*(Player **)(this + 4),false);
  this[0xad] = (KIPlayer)0x1;
  return;
}

// ===== KIPlayer::setActive  @0x000b29e4  (6 bytes)
/* KIPlayer::setActive(bool) */

void KIPlayer::setActive(bool param_1)

{
  bool in_r1;
  
  Player::setActive(*(Player **)(param_1 + 4),in_r1);
  return;
}

// ===== KIPlayer::setInitActive  @0x000b29ea  (20 bytes)
/* KIPlayer::setInitActive(bool) */

void __thiscall KIPlayer::setInitActive(KIPlayer *this,bool param_1)

{
  Player::setActive(*(Player **)(this + 4),param_1);
  this[0xae] = (KIPlayer)0x0;
  return;
}

// ===== KIPlayer::captureCrate  @0x000b2a00  (720 bytes)
/* KIPlayer::captureCrate(Hud*) */

void __thiscall KIPlayer::captureCrate(KIPlayer *this,Hud *param_1)

{
  bool bVar1;
  Status *this_00;
  Ship *pSVar2;
  int iVar3;
  int iVar4;
  Item *this_01;
  Standing *this_02;
  Item *pIVar5;
  uint *puVar6;
  bool bVar7;
  int iVar8;
  uint uVar9;
  
  if ((*(int *)(this + 0x84) - 3U < 2) && (this[0x48] = (KIPlayer)0x0, this[0xfd] != (KIPlayer)0x0))
  {
    Player::setActive(*(Player **)(this + 4),false);
  }
  *(undefined4 *)(this + 0x74) = 0;
  puVar6 = *(uint **)(this + 0x4c);
  if ((puVar6 != (uint *)0x0) && (*puVar6 != 0)) {
    uVar9 = 0;
    do {
      iVar8 = *(int *)(puVar6[1] + 4 + uVar9 * 4);
      if (0 < iVar8) {
        if (1 < *(int *)(this + 0x84) - 3U) {
          iVar8 = AbyssEngine::AERandom::nextInt(Globals::rnd,iVar8);
        }
        pSVar2 = (Ship *)Status::getShip(Globals::status);
        iVar3 = Ship::getFreeSpace(pSVar2);
        iVar4 = iVar8;
        if (iVar3 <= iVar8) {
          pSVar2 = (Ship *)Status::getShip(Globals::status);
          iVar4 = Ship::getFreeSpace(pSVar2);
        }
        if (iVar4 < 1) {
          iVar8 = 1;
        }
        else {
          pSVar2 = (Ship *)Status::getShip(Globals::status);
          iVar4 = Ship::getFreeSpace(pSVar2);
          if (iVar4 <= iVar8) {
            pSVar2 = (Ship *)Status::getShip(Globals::status);
            iVar8 = Ship::getFreeSpace(pSVar2);
          }
        }
        this_01 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) +
                                                   *(int *)(*(int *)(*(int *)(this + 0x4c) + 4) +
                                                           uVar9 * 4) * 4),iVar8);
        iVar4 = *(int *)(*(int *)(this + 0x4c) + 4) + uVar9 * 4;
        *(int *)(iVar4 + 4) = *(int *)(iVar4 + 4) - iVar8;
        if (this_01 == (Item *)0x0) {
          return;
        }
        if (*(char *)(*(int *)(this + 4) + 0x5d) != '\0') {
          Level::stealFriendCargo(*(Level **)(this + 0x50));
        }
        if (this[0x38] == (KIPlayer)0x0) {
          this_02 = (Standing *)Status::getStanding(Globals::status);
          Standing::applyStealCargo(this_02,*(int *)(this + 0x24));
        }
        if (this[0xcc] == (KIPlayer)0x0) {
          bVar1 = false;
        }
        else {
          iVar8 = Item::getIndex(this_01);
          if (iVar8 == 0x74) {
            bVar1 = true;
          }
          else {
            iVar8 = Item::getIndex(this_01);
            bVar1 = false;
            if (iVar8 == 0x75) {
              bVar1 = true;
            }
          }
        }
        pSVar2 = (Ship *)Status::getShip(Globals::status);
        iVar8 = Item::getAmount(this_01);
        iVar8 = Ship::spaceAvailable(pSVar2,iVar8);
        this_00 = Globals::status;
        if (iVar8 != 1) {
          if (bVar1) {
            this[100] = (KIPlayer)0x1;
          }
          iVar8 = Item::getIndex(this_01);
          iVar4 = Item::getAmount(this_01);
          bVar1 = false;
          bVar7 = true;
          goto LAB_000b2cc6;
        }
        iVar8 = Item::getAmount(this_01);
        Status::crateCaptured(this_00,iVar8);
        if (bVar1) {
          Item::setUnsaleable(this_01,true);
        }
        iVar8 = Item::getType(this_01);
        if (iVar8 != 1) goto LAB_000b2bfe;
        pSVar2 = (Ship *)Status::getShip(Globals::status);
        puVar6 = (uint *)Ship::getEquipment(pSVar2);
        uVar9 = 0;
        if (puVar6 != (uint *)0x0) {
          uVar9 = *puVar6;
        }
        if (puVar6 == (uint *)0x0 || uVar9 == 0) goto LAB_000b2bfe;
        uVar9 = 0;
        bVar7 = false;
        do {
          pIVar5 = *(Item **)(puVar6[1] + uVar9 * 4);
          if (pIVar5 != (Item *)0x0) {
            iVar8 = Item::getIndex(pIVar5);
            iVar4 = Item::getIndex(this_01);
            if (iVar8 == iVar4) {
              pIVar5 = *(Item **)(puVar6[1] + uVar9 * 4);
              iVar8 = Item::getAmount(this_01);
              Item::changeAmount(pIVar5,iVar8);
              bVar7 = true;
            }
          }
          uVar9 = uVar9 + 1;
        } while (uVar9 < *puVar6);
        if (!bVar7) {
LAB_000b2bfe:
          pSVar2 = (Ship *)Status::getShip(Globals::status);
          Ship::addCargo(pSVar2,this_01);
        }
        iVar8 = Item::getAmount(this_01);
        *(int *)(*(int *)(this + 0x50) + 0x1c) = iVar8 + *(int *)(*(int *)(this + 0x50) + 0x1c);
        if (bVar1) {
          this[0x65] = (KIPlayer)0x1;
        }
        else if (*(int *)(this + 0x24) == 9) {
          iVar8 = Item::getAmount(this_01);
          *(int *)(Globals::status + 0xcc) = iVar8 + *(int *)(Globals::status + 0xcc);
        }
        else {
          iVar8 = Item::getIndex(this_01);
          if ((0x83 < iVar8) && (iVar8 = Item::getIndex(this_01), iVar8 < 0x9a)) {
            iVar4 = *(int *)(Globals::status + 0xac);
            iVar8 = Item::getIndex(this_01);
            *(undefined1 *)(iVar8 + *(int *)(iVar4 + 4) + -0x84) = 1;
          }
        }
        iVar8 = Item::getIndex(this_01);
        iVar4 = Item::getAmount(this_01);
        bVar7 = false;
LAB_000b2cc6:
        Hud::catchCargo(param_1,iVar8,iVar4,bVar7,bVar1,false,false,false);
        return;
      }
      uVar9 = uVar9 + 2;
    } while (uVar9 < *puVar6);
  }
  return;
}

// ===== KIPlayer::isDead  @0x000b2d04  (14 bytes)
/* KIPlayer::isDead() */

bool __thiscall KIPlayer::isDead(KIPlayer *this)

{
  return *(int *)(this + 0x84) == 4;
}

// ===== KIPlayer::isDying  @0x000b2d12  (14 bytes)
/* KIPlayer::isDying() */

bool __thiscall KIPlayer::isDying(KIPlayer *this)

{
  return *(int *)(this + 0x84) == 3;
}

// ===== KIPlayer::isWingMan  @0x000b2d20  (6 bytes)
/* KIPlayer::isWingMan() */

KIPlayer __thiscall KIPlayer::isWingMan(KIPlayer *this)

{
  return this[0xd8];
}

// ===== KIPlayer::setWingman  @0x000b2d26  (12 bytes)
/* KIPlayer::setWingman(bool, int) */

void __thiscall KIPlayer::setWingman(KIPlayer *this,bool param_1,int param_2)

{
  this[0xd8] = (KIPlayer)param_1;
  *(int *)(this + 0xdc) = param_2;
  *(undefined4 *)(this + 0xe0) = 1;
  return;
}

// ===== KIPlayer::setWingmanCommand  @0x000b2d32  (6 bytes)
/* KIPlayer::setWingmanCommand(int, KIPlayer*) */

void __thiscall KIPlayer::setWingmanCommand(KIPlayer *this,int param_1,KIPlayer *param_2)

{
  *(int *)(this + 0xe0) = param_1;
  *(KIPlayer **)(this + 0xe4) = param_2;
  return;
}

// ===== KIPlayer::setSpeed  @0x000b2d38  (4 bytes)
/* KIPlayer::setSpeed(float) */

void __thiscall KIPlayer::setSpeed(KIPlayer *this,float param_1)

{
  undefined4 in_r1;
  
  *(undefined4 *)(this + 0x60) = in_r1;
  return;
}

// ===== KIPlayer::setRotationSpeed  @0x000b2d3c  (6 bytes)
/* KIPlayer::setRotationSpeed(float) */

void __thiscall KIPlayer::setRotationSpeed(KIPlayer *this,float param_1)

{
  undefined4 in_r1;
  
  *(undefined4 *)(this + 0xa4) = in_r1;
  return;
}

// ===== KIPlayer::setLevel  @0x000b2d42  (4 bytes)
/* KIPlayer::setLevel(Level*) */

void __thiscall KIPlayer::setLevel(KIPlayer *this,Level *param_1)

{
  *(Level **)(this + 0x50) = param_1;
  return;
}

// ===== KIPlayer::enableExplosion  @0x000b2d46  (2 bytes)
/* KIPlayer::enableExplosion() */

void KIPlayer::enableExplosion(void)

{
  return;
}

// ===== KIPlayer::setRoute  @0x000b2d48  (36 bytes)
/* KIPlayer::setRoute(Route*) */

void __thiscall KIPlayer::setRoute(KIPlayer *this,Route *param_1)

{
  void *pvVar1;
  
  if (*(Route **)(this + 0x68) != (Route *)0x0) {
    pvVar1 = (void *)Route::~Route(*(Route **)(this + 0x68));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x68) = 0;
  if (param_1 != (Route *)0x0) {
    *(Route **)(this + 0xb0) = param_1;
  }
  *(Route **)(this + 0x68) = param_1;
  return;
}

// ===== KIPlayer::getRoute  @0x000b2d6c  (4 bytes)
/* KIPlayer::getRoute() */

undefined4 __thiscall KIPlayer::getRoute(KIPlayer *this)

{
  return *(undefined4 *)(this + 0x68);
}

// ===== KIPlayer::setEnemies  @0x000b2d70  (8 bytes)
/* KIPlayer::setEnemies(Array<Player*>*) */

void KIPlayer::setEnemies(Array *param_1)

{
  Array *in_r1;
  
  Player::setEnemies(*(Player **)(param_1 + 4),in_r1);
  return;
}

// ===== KIPlayer::PauseEngineSound  @0x000b2d76  (24 bytes)
/* KIPlayer::PauseEngineSound() */

void __thiscall KIPlayer::PauseEngineSound(KIPlayer *this)

{
  if ((*(Player **)(this + 4) != (Player *)0x0) && (*(int *)(this + 0xf4) != -1)) {
    Player::PauseEngineSound(*(Player **)(this + 4));
    return;
  }
  return;
}

// ===== KIPlayer::PlayEngineSound  @0x000b2d8c  (26 bytes)
/* KIPlayer::PlayEngineSound() */

void __thiscall KIPlayer::PlayEngineSound(KIPlayer *this)

{
  if ((*(int *)(this + 4) != 0) && (*(Vector **)(this + 0xf4) != (Vector *)0xffffffff)) {
    Player::PlayEngineSound(*(int *)(this + 4),*(Vector **)(this + 0xf4));
    return;
  }
  return;
}

// ===== KIPlayer::ResumeEngineSound  @0x000b2da4  (26 bytes)
/* KIPlayer::ResumeEngineSound() */

void __thiscall KIPlayer::ResumeEngineSound(KIPlayer *this)

{
  if ((*(Player **)(this + 4) != (Player *)0x0) && (*(int *)(this + 0xf4) != -1)) {
    Player::ResumeEngineSound(*(Player **)(this + 4),false);
    return;
  }
  return;
}

// ===== KIPlayer::StopEngineSound  @0x000b2dbc  (24 bytes)
/* KIPlayer::StopEngineSound() */

void __thiscall KIPlayer::StopEngineSound(KIPlayer *this)

{
  if ((*(Player **)(this + 4) != (Player *)0x0) && (*(int *)(this + 0xf4) != -1)) {
    Player::StopEngineSound(*(Player **)(this + 4));
    return;
  }
  return;
}

// ===== KIPlayer::addGun  @0x000b2dd2  (8 bytes)
/* KIPlayer::addGun(Gun*, int) */

void KIPlayer::addGun(Gun *param_1,int param_2)

{
  int in_r2;
  
  Player::addGun(*(Player **)(param_1 + 4),(Gun *)param_2,in_r2);
  return;
}

// ===== KIPlayer::addGun  @0x000b2dd8  (8 bytes)
/* KIPlayer::addGun(Array<Gun*>*, int) */

void KIPlayer::addGun(Array *param_1,int param_2)

{
  int in_r2;
  
  Player::addGun(*(Player **)(param_1 + 4),(Array *)param_2,in_r2);
  return;
}

// ===== KIPlayer::getType  @0x000b2dde  (6 bytes)
/* KIPlayer::getType() */

undefined4 __thiscall KIPlayer::getType(KIPlayer *this)

{
  return *(undefined4 *)(this + 0xa8);
}

// ===== KIPlayer::isEnemy  @0x000b2de4  (8 bytes)
/* KIPlayer::isEnemy() */

undefined1 __thiscall KIPlayer::isEnemy(KIPlayer *this)

{
  return *(undefined1 *)(*(int *)(this + 4) + 0x5c);
}

// ===== KIPlayer::getPosition  @0x000b2dec  (14 bytes)
/* KIPlayer::getPosition() */

void KIPlayer::getPosition(void)

{
  AEMath *in_r0;
  int in_r1;
  
  AbyssEngine::AEMath::MatrixGetPosition(in_r0,(Matrix *)(*(int *)(in_r1 + 4) + 4));
  return;
}

// ===== KIPlayer::isDocked  @0x000b2dfa  (14 bytes)
/* KIPlayer::isDocked() */

bool __thiscall KIPlayer::isDocked(KIPlayer *this)

{
  return *(int *)(this + 0x84) == 9;
}

// ===== KIPlayer::setDead  @0x000b2e08  (14 bytes)
/* KIPlayer::setDead() */

void __thiscall KIPlayer::setDead(KIPlayer *this)

{
  *(undefined4 *)(this + 0x84) = 4;
  Player::setActive(*(Player **)(this + 4),false);
  return;
}

// ===== KIPlayer::awake  @0x000b2e16  (14 bytes)
/* KIPlayer::awake() */

void __thiscall KIPlayer::awake(KIPlayer *this)

{
  *(undefined4 *)(this + 0x84) = 1;
  Player::setActive(*(Player **)(this + 4),true);
  return;
}

// ===== KIPlayer::setJumpSphere  @0x000b2e24  (6 bytes)
/* KIPlayer::setJumpSphere(unsigned int) */

void __thiscall KIPlayer::setJumpSphere(KIPlayer *this,uint param_1)

{
  *(uint *)(this + 0xd0) = param_1;
  return;
}

// ===== KIPlayer::createCrate  @0x000b2e2c  (186 bytes)
/* KIPlayer::createCrate(int) */

void __thiscall KIPlayer::createCrate(KIPlayer *this,int param_1)

{
  int iVar1;
  ushort uVar2;
  AEGeometry *this_00;
  Matrix *pMVar3;
  int iVar4;
  
  iVar1 = __stack_chk_guard;
  this_00 = operator_new(0xc0);
  if (param_1 == 1) {
    uVar2 = 0x421e;
  }
  else if (param_1 == 2) {
    uVar2 = 0x421f;
  }
  else if (param_1 == 3) {
    uVar2 = 0x4218;
  }
  else {
    iVar4 = *(int *)(this + 0x24);
    if (iVar4 == 1) {
      uVar2 = 0x425f;
    }
    else if (iVar4 == 9) {
      uVar2 = 0x4214;
    }
    else if (iVar4 == 3) {
      uVar2 = 0x425e;
    }
    else {
      uVar2 = 0x4261;
      if (iVar4 == 0) {
        uVar2 = 0x4260;
      }
    }
  }
  AEGeometry::AEGeometry(this_00,uVar2,Globals::Canvas,false);
  *(AEGeometry **)(this + 0x74) = this_00;
  AEGeometry::getPosition();
  AEGeometry::setPosition((Vector *)this_00);
  iVar4 = *(int *)(this + 4);
  pMVar3 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 0x74));
  AbyssEngine::AEMath::Matrix::operator=((Matrix *)(iVar4 + 4),pMVar3);
  Player::setKIPlayer(*(Player **)(this + 4),this);
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== KIPlayer::cargoAvailable  @0x000b2f00  (36 bytes)
/* KIPlayer::cargoAvailable() */

undefined4 __thiscall KIPlayer::cargoAvailable(KIPlayer *this)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = *(uint **)(this + 0x4c);
  if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
    uVar2 = 0;
    do {
      if (0 < *(int *)(puVar1[1] + 4 + uVar2 * 4)) {
        return 1;
      }
      uVar2 = uVar2 + 2;
    } while (uVar2 < *puVar1);
  }
  return 0;
}

// ===== KIPlayer::levelCollision  @0x000b2f24  (4 bytes)
/* KIPlayer::levelCollision(AbyssEngine::AEMath::Vector*, long long) */

undefined4 KIPlayer::levelCollision(Vector *param_1,longlong param_2)

{
  return 0;
}

// ===== KIPlayer::render  @0x000b2f28  (6 bytes)
/* KIPlayer::render() */

void KIPlayer::render(void)

{
  int in_r0;
  
  AEGeometry::render(*(AEGeometry **)(in_r0 + 8));
  return;
}

// ===== KIPlayer::translate  @0x000b2f2e  (32 bytes)
/* KIPlayer::translate(AbyssEngine::AEMath::Vector const&) */

void __thiscall KIPlayer::translate(KIPlayer *this,Vector *param_1)

{
  AEGeometry::translate(*(Vector **)(this + 8));
  if (*(Route **)(this + 0x68) == (Route *)0x0) {
    return;
  }
  Route::translate(*(Route **)(this + 0x68),param_1);
  return;
}

// ===== KIPlayer::jump  @0x000b2f4c  (14 bytes)
/* KIPlayer::jump() */

void __thiscall KIPlayer::jump(KIPlayer *this)

{
  this[0xf0] = (KIPlayer)0x0;
  this[0xe8] = (KIPlayer)0x1;
  return;
}

// ===== KIPlayer::revive  @0x000b2f5a  (2 bytes)
/* KIPlayer::revive() */

void KIPlayer::revive(void)

{
  return;
}

// ===== KIPlayer::setPosition  @0x000b2f5c  (58 bytes)
/* KIPlayer::setPosition(AbyssEngine::AEMath::Vector const&) */

void KIPlayer::setPosition(Vector *param_1)

{
  Matrix *pMVar1;
  int iVar2;
  
  if (*(Vector **)(param_1 + 8) != (Vector *)0x0) {
    AEGeometry::setPosition(*(Vector **)(param_1 + 8));
    iVar2 = *(int *)(param_1 + 4);
    pMVar1 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(param_1 + 8));
    AbyssEngine::AEMath::Matrix::operator=((Matrix *)(iVar2 + 4),pMVar1);
    if (*(AEGeometry **)(param_1 + 0xc) != (AEGeometry *)0x0) {
      iVar2 = *(int *)(param_1 + 4);
      pMVar1 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(param_1 + 0xc));
      AbyssEngine::AEMath::Matrix::operator*=((Matrix *)(iVar2 + 4),pMVar1);
      return;
    }
  }
  return;
}

// ===== KIPlayer::setPosition  @0x000b2f94  (58 bytes)
/* KIPlayer::setPosition(float, float, float) */

void __thiscall KIPlayer::setPosition(KIPlayer *this,float param_1,float param_2,float param_3)

{
  undefined1 local_18 [12];
  int local_c;
  
  local_c = __stack_chk_guard;
  (**(code **)(*(int *)this + 0x44))(this,local_18);
  if (__stack_chk_guard != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== KIPlayer::update  @0x000b2fd8  (2 bytes)
/* KIPlayer::update(int) */

int KIPlayer::update(int param_1)

{
  return param_1;
}

// ===== KIPlayer::collide  @0x000b2fda  (4 bytes)
/* KIPlayer::collide(float, float, float) */

undefined4 KIPlayer::collide(float param_1,float param_2,float param_3)

{
  return 0;
}

// ===== KIPlayer::outerCollide  @0x000b2fde  (4 bytes)
/* KIPlayer::outerCollide(float, float, float) */

undefined4 KIPlayer::outerCollide(float param_1,float param_2,float param_3)

{
  return 0;
}

// ===== KIPlayer::getProjectionVector  @0x000b2fe2  (10 bytes)
/* KIPlayer::getProjectionVector(AbyssEngine::AEMath::Vector const&) */

void KIPlayer::getProjectionVector(Vector *param_1)

{
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

// ===== KIPlayer::projectCollisionOnSurface  @0x000b2fec  (10 bytes)
/* KIPlayer::projectCollisionOnSurface(AbyssEngine::AEMath::Vector const&) */

void KIPlayer::projectCollisionOnSurface(Vector *param_1)

{
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

