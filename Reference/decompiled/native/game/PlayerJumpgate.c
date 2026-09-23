// Class: PlayerJumpgate
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== PlayerJumpgate::PlayerJumpgate  @0x000b1a8c  (250 bytes)
/* PlayerJumpgate::PlayerJumpgate(int, AEGeometry*, float, float, float, bool) */

PlayerJumpgate * __thiscall
PlayerJumpgate::PlayerJumpgate
          (PlayerJumpgate *this,int param_1,AEGeometry *param_2,float param_3,float param_4,
          float param_5,bool param_6)

{
  Array *pAVar1;
  undefined4 *puVar2;
  int iVar3;
  SolarSystem *this_00;
  BoundingSphere *this_01;
  int iVar4;
  uint in_fpscr;
  float extraout_s0;
  float fVar5;
  float extraout_s0_00;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float fVar6;
  float extraout_s2;
  float extraout_s2_00;
  float extraout_s2_01;
  float fVar7;
  float extraout_s3;
  float extraout_s4;
  float extraout_s5;
  float extraout_s6;
  int in_stack_00000008;
  
  PlayerStaticFar::PlayerStaticFar((PlayerStaticFar *)this,param_1,param_2,param_3,param_4,param_5);
  *(undefined ***)this = &PTR__PlayerJumpgate_00263e18;
  KIPlayer::setVisible((KIPlayer *)this,SUB41(in_stack_00000008,0));
  fVar5 = extraout_s0;
  fVar6 = extraout_s1;
  fVar7 = extraout_s2;
  if (in_stack_00000008 == 1) {
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 300) = pAVar1;
    ArraySetLength<BoundingVolume*>(1,pAVar1);
    iVar3 = Status::inAlienOrbit(Globals::status);
    if (iVar3 == 0) {
      this_00 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar3 = SolarSystem::getRace(this_00);
      iVar4 = 0x1d4c;
      if (iVar3 == 1) {
        iVar4 = 0x2bf2;
      }
    }
    else {
      iVar4 = 0x1d4c;
    }
    Player::setRadius(*(Player **)(this + 4),iVar4);
    this_01 = operator_new(0x48);
    fVar5 = (float)VectorSignedToFloat(iVar4,(byte)(in_fpscr >> 0x16) & 3);
    BoundingSphere::BoundingSphere
              (this_01,fVar5,extraout_s1_00,extraout_s2_00,extraout_s3,extraout_s4,extraout_s5,
               extraout_s6);
    **(undefined4 **)(*(int *)(this + 300) + 4) = this_01;
    fVar5 = extraout_s0_00;
    fVar6 = extraout_s1_01;
    fVar7 = extraout_s2_01;
  }
  this[0x13c] = (PlayerJumpgate)0x0;
  *(undefined4 *)(this + 0x140) = 0xffffffff;
  AEGeometry::setRotation(*(AEGeometry **)(this + 8),fVar5,fVar6,fVar7);
  return this;
}

// ===== PlayerJumpgate::~PlayerJumpgate  @0x000b1be4  (4 bytes)
/* PlayerJumpgate::~PlayerJumpgate() */

void __thiscall PlayerJumpgate::~PlayerJumpgate(PlayerJumpgate *this)

{
  PlayerStaticFar::~PlayerStaticFar((PlayerStaticFar *)this);
  return;
}

// ===== PlayerJumpgate::~PlayerJumpgate  @0x000b1be8  (16 bytes)
/* PlayerJumpgate::~PlayerJumpgate() */

void __thiscall PlayerJumpgate::~PlayerJumpgate(PlayerJumpgate *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)PlayerStaticFar::~PlayerStaticFar((PlayerStaticFar *)this);
  operator_delete(pvVar1);
  return;
}

// ===== PlayerJumpgate::addJumpAnimationHandle  @0x000b1bf8  (6 bytes)
/* PlayerJumpgate::addJumpAnimationHandle(unsigned int) */

void __thiscall PlayerJumpgate::addJumpAnimationHandle(PlayerJumpgate *this,uint param_1)

{
  *(uint *)(this + 0x140) = param_1;
  return;
}

// ===== PlayerJumpgate::activate  @0x000b1c00  (72 bytes)
/* PlayerJumpgate::activate() */

void __thiscall PlayerJumpgate::activate(PlayerJumpgate *this)

{
  undefined4 uVar1;
  
  if (this[0x13c] == (PlayerJumpgate)0x0) {
    if (*(uint *)(this + 0x140) != 0xffffffff) {
      uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(this + 0x140));
      AbyssEngine::Transform::SetAnimationState(uVar1,1,0);
      AbyssEngine::PaintCanvas::TransformRemoveChild
                (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc),
                 *(uint *)(*(int *)(this + 8) + 0x14));
      AEGeometry::addChild(*(AEGeometry **)(this + 8),*(uint *)(this + 0x140));
    }
    this[0x13c] = (PlayerJumpgate)0x1;
  }
  return;
}

// ===== PlayerJumpgate::timeToJump  @0x000b1c4c  (40 bytes)
/* PlayerJumpgate::timeToJump() */

bool __thiscall PlayerJumpgate::timeToJump(PlayerJumpgate *this)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar1 = AbyssEngine::PaintCanvas::TransformGetTransform(Globals::Canvas,*(uint *)(this + 0x140));
  iVar2 = *(int *)(iVar1 + 0x114);
  bVar3 = 1000 < *(uint *)(iVar1 + 0x110);
  return (int)(-(uint)bVar3 - iVar2) < 0 != (SBORROW4(0,iVar2) != SBORROW4(-iVar2,(uint)bVar3));
}

// ===== PlayerJumpgate::animationEnded  @0x000b1c78  (42 bytes)
/* PlayerJumpgate::animationEnded() */

undefined4 __thiscall PlayerJumpgate::animationEnded(PlayerJumpgate *this)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((this[0x13c] != (PlayerJumpgate)0x0) &&
     (iVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(this + 0x140)), *(char *)(iVar1 + 0xed) == '\0'))
  {
    uVar2 = 1;
  }
  return uVar2;
}

// ===== PlayerJumpgate::setPosition  @0x000b1ca8  (42 bytes)
/* PlayerJumpgate::setPosition(float, float, float) */

void PlayerJumpgate::setPosition(float param_1,float param_2,float param_3)

{
  int in_r0;
  float in_r1;
  float in_r2;
  float in_r3;
  
  *(int *)(in_r0 + 0x120) = (int)in_r1;
  *(int *)(in_r0 + 0x124) = (int)in_r2;
  *(int *)(in_r0 + 0x128) = (int)in_r3;
  AEGeometry::setPosition((float)(int)in_r3,param_2,in_r3);
  return;
}

// ===== PlayerJumpgate::update  @0x000b1cd4  (46 bytes)
/* PlayerJumpgate::update(int) */

void __thiscall PlayerJumpgate::update(PlayerJumpgate *this,int param_1)

{
  undefined4 uVar1;
  
  if (this[0xf1] != (PlayerJumpgate)0x0) {
    uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc));
    AbyssEngine::Transform::Update(CONCAT44(1,uVar1),SUB41(param_1,0));
  }
  return;
}

