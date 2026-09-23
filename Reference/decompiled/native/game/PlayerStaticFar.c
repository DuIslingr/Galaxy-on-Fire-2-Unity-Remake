// Class: PlayerStaticFar
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== PlayerStaticFar::PlayerStaticFar  @0x00141284  (92 bytes)
/* PlayerStaticFar::PlayerStaticFar(int, AEGeometry*, float, float, float) */

PlayerStaticFar * __thiscall
PlayerStaticFar::PlayerStaticFar
          (PlayerStaticFar *this,int param_1,AEGeometry *param_2,float param_3,float param_4,
          float param_5)

{
  undefined4 in_r3;
  undefined4 in_stack_00000000;
  undefined4 in_stack_00000004;
  
  PlayerStatic::PlayerStatic((PlayerStatic *)this,param_1,param_2,param_3,param_4,param_5);
  *(undefined ***)this = &PTR__PlayerStaticFar_00264224;
  *(undefined4 *)(this + 0x130) = 0;
  *(undefined4 *)(this + 0x134) = 0;
  *(undefined4 *)(this + 0x138) = 0;
  *(undefined4 *)(this + 0x54) = in_r3;
  *(undefined4 *)(this + 0x58) = in_stack_00000000;
  *(undefined4 *)(this + 0x5c) = in_stack_00000004;
  Player::setRadius(*(Player **)(this + 4),0x1d4c);
  *(undefined4 *)(this + 300) = 0;
  return this;
}

// ===== PlayerStaticFar::~PlayerStaticFar  @0x001412f4  (4 bytes)
/* PlayerStaticFar::~PlayerStaticFar() */

void __thiscall PlayerStaticFar::~PlayerStaticFar(PlayerStaticFar *this)

{
  PlayerStatic::~PlayerStatic((PlayerStatic *)this);
  return;
}

// ===== PlayerStaticFar::~PlayerStaticFar  @0x001412f8  (16 bytes)
/* PlayerStaticFar::~PlayerStaticFar() */

void __thiscall PlayerStaticFar::~PlayerStaticFar(PlayerStaticFar *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)PlayerStatic::~PlayerStatic((PlayerStatic *)this);
  operator_delete(pvVar1);
  return;
}

// ===== PlayerStaticFar::setYRotation  @0x00141308  (2 bytes)
/* PlayerStaticFar::setYRotation(int) */

int PlayerStaticFar::setYRotation(int param_1)

{
  return param_1;
}

// ===== PlayerStaticFar::render  @0x0014130a  (4 bytes)
/* PlayerStaticFar::render() */

void PlayerStaticFar::render(void)

{
  PlayerStatic::render();
  return;
}

// ===== PlayerStaticFar::update  @0x00141310  (366 bytes)
/* PlayerStaticFar::update(int) */

void PlayerStaticFar::update(int param_1)

{
  PaintCanvas *this;
  uint uVar1;
  Matrix *pMVar2;
  float fVar3;
  Vector *this_00;
  Vector *this_01;
  uint in_fpscr;
  float fVar4;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s2;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  
  this = Globals::Canvas;
  local_24 = __stack_chk_guard;
  if (*(int *)(param_1 + 8) != 0) {
    uVar1 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
    pMVar2 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(this,uVar1);
    AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_30,pMVar2);
    this_01 = (Vector *)(param_1 + 0x8c);
    AbyssEngine::AEMath::Vector::operator=(this_01,(Vector *)&local_30);
    local_30 = VectorSignedToFloat(*(undefined4 *)(param_1 + 0x120),(byte)(in_fpscr >> 0x16) & 3);
    local_2c = VectorSignedToFloat(*(undefined4 *)(param_1 + 0x124),(byte)(in_fpscr >> 0x16) & 3);
    local_28 = VectorSignedToFloat(*(undefined4 *)(param_1 + 0x128),(byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::AEMath::Vector::operator=((Vector *)(param_1 + 0x98),(Vector *)&local_30);
    AbyssEngine::AEMath::operator-((AEMath *)&local_30,(Vector *)(param_1 + 0x98),this_01);
    this_00 = (Vector *)(param_1 + 0x130);
    AbyssEngine::AEMath::Vector::operator=(this_00,(Vector *)&local_30);
    fVar3 = (float)AbyssEngine::AEMath::VectorLength(this_00);
    if ((int)fVar3 < 0x48059) {
      AEGeometry::setScaling(*(AEGeometry **)(param_1 + 8),fVar3,extraout_s1,extraout_s2);
      fVar3 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x120),
                                         (byte)(in_fpscr >> 0x16) & 3);
      fVar4 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x124),
                                         (byte)(in_fpscr >> 0x16) & 3);
      VectorSignedToFloat(*(undefined4 *)(param_1 + 0x128),(byte)(in_fpscr >> 0x16) & 3);
      AEGeometry::setPosition(fVar3,extraout_s1_01,fVar4);
    }
    else {
      AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_30,this_00);
      fVar4 = (float)AbyssEngine::AEMath::Vector::operator=(this_00,(Vector *)&local_30);
      AbyssEngine::AEMath::Vector::operator*=(this_00,fVar4);
      AbyssEngine::AEMath::Vector::operator+=(this_00,this_01);
      AEGeometry::setPosition(*(Vector **)(param_1 + 8));
      fVar3 = (float)VectorSignedToFloat((int)fVar3,(byte)(in_fpscr >> 0x16) & 3);
      fVar3 = (float)VectorSignedToFloat((int)((295000.0 / fVar3) * 4096.0),
                                         (byte)(in_fpscr >> 0x16) & 3);
      AEGeometry::setScaling
                (*(AEGeometry **)(param_1 + 8),fVar3 * 0.00024414062,extraout_s1_00,0.00024414062);
    }
  }
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerStaticFar::collide  @0x00141498  (142 bytes)
/* PlayerStaticFar::collide(float, float, float) */

undefined4 __thiscall
PlayerStaticFar::collide(PlayerStaticFar *this,float param_1,float param_2,float param_3)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  float in_r1;
  float in_r2;
  float in_r3;
  uint in_fpscr;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar5 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x120),(byte)(in_fpscr >> 0x16) & 3);
  fVar5 = in_r1 - fVar5;
  fVar4 = (float)VectorSignedToFloat(*(int *)(*(int *)(this + 4) + 0x40),
                                     (byte)(in_fpscr >> 0x16) & 3);
  uVar1 = in_fpscr & 0xfffffff;
  if (fVar5 < fVar4) {
    fVar6 = (float)VectorSignedToFloat(-*(int *)(*(int *)(this + 4) + 0x40),
                                       (byte)(uVar1 >> 0x16) & 3);
    uVar2 = uVar1 | (uint)(fVar5 < fVar6) << 0x1f | (uint)(fVar5 == fVar6) << 0x1e;
    bVar3 = (byte)(uVar2 >> 0x18);
    if (!(bool)(bVar3 >> 6 & 1) && (bool)(bVar3 >> 7) == (NAN(fVar5) || NAN(fVar6))) {
      fVar5 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x124),(byte)(uVar2 >> 0x16) & 3);
      fVar5 = in_r2 - fVar5;
      if ((fVar5 < fVar4) &&
         (uVar1 = uVar1 | (uint)(fVar5 < fVar6) << 0x1f | (uint)(fVar5 == fVar6) << 0x1e,
         bVar3 = (byte)(uVar1 >> 0x18),
         !(bool)(bVar3 >> 6 & 1) && (bool)(bVar3 >> 7) == (NAN(fVar5) || NAN(fVar6)))) {
        fVar5 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x128),(byte)(uVar1 >> 0x16) & 3);
        if (((int)((uint)(in_r3 - fVar5 < fVar4) << 0x1f) < 0) && (fVar6 < in_r3 - fVar5)) {
          return 1;
        }
      }
    }
  }
  return 0;
}

// ===== PlayerStaticFar::getInitPosition  @0x00141526  (14 bytes)
/* PlayerStaticFar::getInitPosition(AbyssEngine::AEMath::Vector) */

void __thiscall PlayerStaticFar::getInitPosition(PlayerStaticFar *this,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x58);
  uVar1 = *(undefined4 *)(param_2 + 0x5c);
  *(undefined4 *)this = *(undefined4 *)(param_2 + 0x54);
  *(undefined4 *)(this + 4) = uVar2;
  *(undefined4 *)(this + 8) = uVar1;
  return;
}

// ===== PlayerStaticFar::outerCollide  @0x00141534  (10 bytes)
/* PlayerStaticFar::outerCollide(float, float, float) */

void PlayerStaticFar::outerCollide(float param_1,float param_2,float param_3)

{
  int *in_r0;
  
                    /* WARNING: Could not recover jumptable at 0x0014153c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_r0 + 0x38))();
  return;
}

// ===== PlayerStaticFar::outerCollide  @0x0014153e  (10 bytes)
/* PlayerStaticFar::outerCollide(AbyssEngine::AEMath::Vector) */

void PlayerStaticFar::outerCollide(int *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00141546. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x38))();
  return;
}

// ===== PlayerStaticFar::getProjectionVector  @0x00141548  (30 bytes)
/* PlayerStaticFar::getProjectionVector(AbyssEngine::AEMath::Vector const&) */

void __thiscall PlayerStaticFar::getProjectionVector(PlayerStaticFar *this,Vector *param_1)

{
  if (*(int *)(param_1 + 300) != 0) {
    BoundingVolume::getProjectionVector((Vector *)this);
    return;
  }
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}

// ===== PlayerStaticFar::projectCollisionOnSurface  @0x00141566  (30 bytes)
/* PlayerStaticFar::projectCollisionOnSurface(AbyssEngine::AEMath::Vector const&) */

void PlayerStaticFar::projectCollisionOnSurface(Vector *param_1)

{
  int in_r1;
  Vector *in_r2;
  
  if (*(Array **)(in_r1 + 300) != (Array *)0x0) {
    BoundingVolume::staticProjectCollisionOnSurface
              ((BoundingVolume *)param_1,in_r2,*(Array **)(in_r1 + 300));
    return;
  }
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

