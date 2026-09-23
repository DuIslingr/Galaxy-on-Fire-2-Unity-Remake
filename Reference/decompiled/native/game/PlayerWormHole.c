// Class: PlayerWormHole
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== PlayerWormHole::PlayerWormHole  @0x000b1d3c  (128 bytes)
/* PlayerWormHole::PlayerWormHole(int, AEGeometry*, float, float, float, bool) */

PlayerWormHole * __thiscall
PlayerWormHole::PlayerWormHole
          (PlayerWormHole *this,int param_1,AEGeometry *param_2,float param_3,float param_4,
          float param_5,bool param_6)

{
  String *pSVar1;
  undefined4 uVar2;
  float in_stack_00000000;
  float in_stack_00000004;
  bool in_stack_00000008;
  
  PlayerStaticFar::PlayerStaticFar
            ((PlayerStaticFar *)this,param_1,param_2,in_stack_00000000,param_4,in_stack_00000004);
  *(undefined ***)this = &PTR__PlayerWormHole_00263e8c;
  pSVar1 = (String *)GameText::getText(Globals::gameText,0x221);
  AbyssEngine::String::operator=((String *)(this + 0x18),pSVar1);
  KIPlayer::setVisible((KIPlayer *)this,in_stack_00000008);
  Player::setRadius(*(Player **)(this + 4),40000);
  uVar2 = AbyssEngine::PaintCanvas::TransformGetTransform
                    (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc));
  AbyssEngine::Transform::SetAnimationState(uVar2,2,0);
  this[0x15c] = (PlayerWormHole)0x1;
  *(undefined4 *)(this + 0x150) = 0;
  *(undefined4 *)(this + 0x154) = 0x1000;
  return this;
}

// ===== PlayerWormHole::reset  @0x000b1dd8  (18 bytes)
/* PlayerWormHole::reset(bool) */

void __thiscall PlayerWormHole::reset(PlayerWormHole *this,bool param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1) {
    uVar1 = 59000;
  }
  *(undefined4 *)(this + 0x150) = uVar1;
  *(undefined4 *)(this + 0x154) = 0x1000;
  return;
}

// ===== PlayerWormHole::~PlayerWormHole  @0x000b1dea  (4 bytes)
/* PlayerWormHole::~PlayerWormHole() */

void __thiscall PlayerWormHole::~PlayerWormHole(PlayerWormHole *this)

{
  PlayerStaticFar::~PlayerStaticFar((PlayerStaticFar *)this);
  return;
}

// ===== PlayerWormHole::~PlayerWormHole  @0x000b1dee  (16 bytes)
/* PlayerWormHole::~PlayerWormHole() */

void __thiscall PlayerWormHole::~PlayerWormHole(PlayerWormHole *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)PlayerStaticFar::~PlayerStaticFar((PlayerStaticFar *)this);
  operator_delete(pvVar1);
  return;
}

// ===== PlayerWormHole::open  @0x000b1dfe  (16 bytes)
/* PlayerWormHole::open() */

void __thiscall PlayerWormHole::open(PlayerWormHole *this)

{
  *(undefined4 *)(this + 0x150) = 0xfffff448;
  *(undefined4 *)(this + 0x154) = 0;
  return;
}

// ===== PlayerWormHole::isShrinking  @0x000b1e0e  (18 bytes)
/* PlayerWormHole::isShrinking() */

bool __thiscall PlayerWormHole::isShrinking(PlayerWormHole *this)

{
  return 60000 < *(int *)(this + 0x150);
}

// ===== PlayerWormHole::setPosition  @0x000b1e20  (52 bytes)
/* PlayerWormHole::setPosition(float, float, float) */

void PlayerWormHole::setPosition(float param_1,float param_2,float param_3)

{
  int in_r0;
  float in_r1;
  float in_r2;
  float in_r3;
  
  *(int *)(in_r0 + 0x120) = (int)in_r1;
  *(int *)(in_r0 + 0x124) = (int)in_r2;
  *(int *)(in_r0 + 0x128) = (int)in_r3;
  *(float *)(in_r0 + 0x54) = in_r1;
  *(float *)(in_r0 + 0x58) = in_r2;
  *(float *)(in_r0 + 0x5c) = in_r3;
  AEGeometry::setPosition((float)(int)in_r3,param_2,in_r3);
  return;
}

// ===== PlayerWormHole::render  @0x000b1e52  (14 bytes)
/* PlayerWormHole::render() */

void __thiscall PlayerWormHole::render(PlayerWormHole *this)

{
  if (this[0xf1] == (PlayerWormHole)0x0) {
    return;
  }
  AEGeometry::render(*(AEGeometry **)(this + 8));
  return;
}

// ===== PlayerWormHole::freeMissionLock  @0x000b1e60  (8 bytes)
/* PlayerWormHole::freeMissionLock() */

void __thiscall PlayerWormHole::freeMissionLock(PlayerWormHole *this)

{
  this[0x15c] = (PlayerWormHole)0x0;
  return;
}

// ===== PlayerWormHole::update  @0x000b1e68  (1104 bytes)
/* PlayerWormHole::update(int) */

void __thiscall PlayerWormHole::update(PlayerWormHole *this,int param_1)

{
  PlayerWormHole *pPVar1;
  PaintCanvas *this_00;
  uint uVar2;
  int iVar3;
  int iVar4;
  Matrix *pMVar5;
  Station *this_01;
  int iVar6;
  int iVar7;
  int iVar8;
  PlayerEgo *pPVar9;
  Vector *this_02;
  uint in_fpscr;
  float fVar10;
  undefined4 uVar11;
  float extraout_s1;
  float fVar12;
  undefined4 uVar13;
  float fVar14;
  undefined4 uVar15;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  uVar2 = AbyssEngine::PaintCanvas::TransformGetTransform
                    (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc));
  AbyssEngine::Transform::Update((ulonglong)uVar2,SUB41(param_1,0));
  if (this[0xf1] == (PlayerWormHole)0x0) goto LAB_000b1fea;
  iVar3 = *(int *)(this + 0x150) + param_1;
  *(int *)(this + 0x150) = iVar3;
  if (iVar3 < 0) {
    fVar10 = (float)VectorSignedToFloat(-iVar3,(byte)(in_fpscr >> 0x16) & 3);
    *(int *)(this + 0x154) = 0x1000 - (int)((fVar10 / 3000.0) * 4096.0);
  }
  else if (60000 < iVar3) {
    iVar3 = Status::getCurrentCampaignMission(Globals::status);
    if (this[0x15c] == (PlayerWormHole)0x0) {
LAB_000b201c:
      iVar4 = *(int *)(this + 0x150);
    }
    else {
      if (iVar3 == 0x2a) {
        iVar4 = Status::inAlienOrbit(Globals::status);
        if (iVar4 != 1) goto LAB_000b201c;
      }
      else if ((iVar3 != 0x28) || (iVar4 = Status::inAlienOrbit(Globals::status), iVar4 != 0))
      goto LAB_000b201c;
      iVar4 = 60000;
      *(undefined4 *)(this + 0x150) = 60000;
    }
    fVar10 = (float)VectorSignedToFloat(iVar4 + -60000,(byte)(in_fpscr >> 0x16) & 3);
    *(int *)(this + 0x154) = 0x1000 - (int)((fVar10 / 3000.0) * 4096.0);
    if (63000 < iVar4) {
      iVar4 = Status::inAlienOrbit(Globals::status);
      if (iVar4 == 0) {
        this_01 = (Station *)Status::getStation(Globals::status);
        iVar4 = Station::isAttackedByAliens(this_01);
        if (iVar4 == 1) goto LAB_000b207c;
LAB_000b209c:
        this[0xf1] = (PlayerWormHole)0x0;
        AEGeometry::setVisible(*(AEGeometry **)(this + 8),false);
      }
      else {
LAB_000b207c:
        if (this[0x15c] != (PlayerWormHole)0x0) {
          uVar2 = Status::inAlienOrbit(Globals::status);
          if (iVar3 == 0x2a) {
            uVar2 = uVar2 ^ 1;
          }
          if (iVar3 == 0x2a && uVar2 == 1) goto LAB_000b209c;
        }
        *(undefined4 *)(this + 0x150) = 0xfffff448;
        iVar4 = Status::inAlienOrbit(Globals::status);
        if (iVar4 == 1) {
          iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,60000);
          iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
          local_38 = -1;
          if (iVar6 == 0) {
            local_38 = 1;
          }
          local_38 = local_38 * (iVar4 + 30000);
          iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,40000);
          iVar4 = iVar4 + 20000;
          iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,40000);
          iVar6 = -60000 - iVar6;
        }
        else {
          iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,40000);
          iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
          local_38 = -1;
          if (iVar6 == 0) {
            local_38 = 1;
          }
          local_38 = local_38 * (iVar4 + 20000);
          iVar6 = -1;
          iVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,40000);
          iVar8 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
          iVar4 = -1;
          if (iVar8 == 0) {
            iVar4 = 1;
          }
          iVar4 = iVar4 * (iVar7 + 20000);
          iVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,40000);
          iVar8 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
          if (iVar8 == 0) {
            iVar6 = 1;
          }
          iVar6 = iVar6 * (iVar7 + 20000);
        }
        if (iVar3 == 0x1d || iVar3 == 0x29) {
          Level::getPlayer(*(Level **)(this + 0x50));
          PlayerEgo::getPosition();
          AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x8c),(Vector *)&local_34);
          fVar10 = (float)VectorSignedToFloat(iVar6,(byte)(in_fpscr >> 0x16) & 3);
          fVar12 = (float)VectorSignedToFloat(iVar4,(byte)(in_fpscr >> 0x16) & 3);
          fVar14 = (float)VectorSignedToFloat(local_38,(byte)(in_fpscr >> 0x16) & 3);
          iVar6 = (int)(fVar10 + fVar10 * 1.7 + *(float *)(this + 0x94));
          iVar4 = (int)(fVar12 + fVar12 * 1.7 + *(float *)(this + 0x90));
          local_38 = (int)(fVar14 + fVar14 * 1.7 + *(float *)(this + 0x8c));
        }
        uVar11 = VectorSignedToFloat(local_38,(byte)(in_fpscr >> 0x16) & 3);
        uVar13 = VectorSignedToFloat(iVar4,(byte)(in_fpscr >> 0x16) & 3);
        uVar15 = VectorSignedToFloat(iVar6,(byte)(in_fpscr >> 0x16) & 3);
        (**(code **)(*(int *)this + 0x48))(this,uVar11,uVar13,uVar15);
        pPVar1 = this + 0x50;
        pPVar9 = (PlayerEgo *)Level::getPlayer(*(Level **)pPVar1);
        iVar3 = PlayerEgo::goingToWormhole(pPVar9);
        if (iVar3 == 1) {
          pPVar9 = (PlayerEgo *)Level::getPlayer(*(Level **)pPVar1);
          iVar3 = PlayerEgo::getHUD(pPVar9);
          iVar4 = Level::getPlayer(*(Level **)pPVar1);
          Hud::hudEvent(iVar3,(PlayerEgo *)0x6,iVar4);
          pPVar9 = (PlayerEgo *)Level::getPlayer(*(Level **)pPVar1);
          PlayerEgo::setAutoPilot(pPVar9,(KIPlayer *)0x0);
        }
      }
    }
  }
  PlayerStaticFar::update((int)this);
  this_00 = Globals::Canvas;
  uVar2 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
  pMVar5 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(this_00,uVar2);
  AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_34,pMVar5);
  this_02 = (Vector *)(this + 0x8c);
  AbyssEngine::AEMath::Vector::operator=(this_02,(Vector *)&local_34);
  fVar10 = (float)VectorSignedToFloat(*(int *)(this + 0x154) << 4,(byte)(in_fpscr >> 0x16) & 3);
  AEGeometry::setScaling
            (*(AEGeometry **)(this + 8),fVar10 * 1.5258789e-05,extraout_s1,1.5258789e-05);
  AEGeometry::getPosition();
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x130),(Vector *)&local_34);
  AbyssEngine::AEMath::Vector::operator-=(this_02,(Vector *)(this + 0x130));
  AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_34,this_02);
  AbyssEngine::AEMath::Vector::operator=(this_02,(Vector *)&local_34);
  *(float *)(this + 0x8c) = *(float *)(this + 0x8c) + 0.5;
  local_34 = 0;
  local_30 = 0x3f800000;
  uStack_2c = 0;
  AEGeometry::setDirection(*(AEGeometry **)(this + 8),this_02,(Vector *)&local_34);
LAB_000b1fea:
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerWormHole::getPosition  @0x000b2300  (38 bytes)
/* PlayerWormHole::getPosition() */

void PlayerWormHole::getPosition(void)

{
  undefined4 *in_r0;
  int in_r1;
  uint in_fpscr;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = VectorSignedToFloat(*(undefined4 *)(in_r1 + 0x120),(byte)(in_fpscr >> 0x16) & 3);
  uVar2 = VectorSignedToFloat(*(undefined4 *)(in_r1 + 0x124),(byte)(in_fpscr >> 0x16) & 3);
  uVar3 = VectorSignedToFloat(*(undefined4 *)(in_r1 + 0x128),(byte)(in_fpscr >> 0x16) & 3);
  *in_r0 = uVar1;
  in_r0[1] = uVar2;
  in_r0[2] = uVar3;
  return;
}

