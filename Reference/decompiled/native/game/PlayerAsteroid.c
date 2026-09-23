// Class: PlayerAsteroid
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== PlayerAsteroid::PlayerAsteroid  @0x000f68e4  (796 bytes)
/* PlayerAsteroid::PlayerAsteroid(int, AEGeometry*, int, int, AbyssEngine::AEMath::Vector const&,
   float, int) */

void __thiscall
PlayerAsteroid::PlayerAsteroid
          (PlayerAsteroid *this,int param_1,AEGeometry *param_2,int param_3,int param_4,
          Vector *param_5,float param_6,int param_7)

{
  Player *pPVar1;
  int iVar2;
  undefined4 uVar3;
  Explosion *this_00;
  int iVar4;
  undefined4 uVar5;
  AEGeometry *this_01;
  uint in_fpscr;
  float fVar6;
  float extraout_s0;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s2;
  undefined4 extraout_s3;
  undefined8 unaff_d8;
  float fVar7;
  int in_stack_0000000c;
  undefined4 local_54;
  float local_50;
  undefined4 local_4c;
  float local_48;
  float local_44;
  float local_40;
  int local_3c;
  
  local_3c = __stack_chk_guard;
  pPVar1 = operator_new(0x114);
  Player::Player(pPVar1,0x5dc,0x1e,0,0,0);
  KIPlayer::KIPlayer((KIPlayer *)this,param_1,-1,pPVar1,param_2,*(float *)param_5,extraout_s1,
                     *(float *)(param_5 + 4),SUB41(*(float *)param_5,0));
  *(undefined ***)this = &PTR__PlayerAsteroid_002641b0;
  *(undefined4 *)(this + 0x13c) = 0;
  *(undefined4 *)(this + 0x140) = 0;
  *(undefined4 *)(this + 0x144) = 0;
  *(undefined4 *)(this + 0x160) = 0;
  *(undefined4 *)(this + 0x164) = 0;
  *(undefined4 *)(this + 0x168) = 0;
  Player::setKIPlayer(*(Player **)(this + 4),(KIPlayer *)this);
  *(int *)(this + 0x124) = param_4;
  this[0x120] = (PlayerAsteroid)0x0;
  *(int *)(this + 0x134) = param_7;
  *(int *)(this + 0x14c) = in_stack_0000000c;
  pPVar1 = *(Player **)(this + 4);
  iVar2 = AbyssEngine::PaintCanvas::TransformGetTransform(Globals::Canvas,*(uint *)(param_2 + 0xc));
  Player::setRadius(pPVar1,(int)(*(float *)(iVar2 + 0xe0) * (float)param_7 * 0.7));
  Player::setMaxHitpoints(*(Player **)(this + 4),(int)((float)param_7 * 100.0 + 30.0));
  uVar3 = Player::getHitpoints(*(Player **)(this + 4));
  *(undefined4 *)(this + 0x154) = uVar3;
  this[0x138] = (PlayerAsteroid)(3 < in_stack_0000000c);
  this_00 = operator_new(0x68);
  fVar6 = (float)Explosion::Explosion(this_00,param_3 + 2);
  *(Explosion **)(this + 0x128) = this_00;
  Explosion::setScaling(fVar6);
  AEGeometry::setScaling(*(AEGeometry **)(this + 8),extraout_s0,extraout_s1_00,extraout_s2);
  (**(code **)(*(int *)this + 0x44))(this,param_5);
  iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x2000);
  fVar6 = (float)VectorSignedToFloat(iVar2 + -0x1000,(byte)(in_fpscr >> 0x16) & 3);
  iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x2000);
  iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x2000);
  local_48 = fVar6 * 0.00024414062;
  local_44 = (float)VectorSignedToFloat(iVar2 + -0x1000,(byte)(in_fpscr >> 0x16) & 3);
  local_40 = (float)VectorSignedToFloat(iVar4 + -0x1000,(byte)(in_fpscr >> 0x16) & 3);
  local_44 = local_44 * 0.00024414062;
  local_40 = local_40 * 0.00024414062;
  AbyssEngine::AEMath::Vector::operator=((Vector *)tmp_vector2,(Vector *)&local_48);
  this_01 = *(AEGeometry **)(this + 8);
  uVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
  fVar7 = (float)VectorSignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
  uVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
  uVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
  VectorSignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
  fVar6 = (float)VectorSignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
  AEGeometry::setRotation(this_01,fVar6 * 0.01 * 6.2831855,extraout_s1_01,fVar7 * 0.01 * 6.2831855);
  this[0x148] = (PlayerAsteroid)0x1;
  *(undefined4 *)(this + 0x74) = 0;
  iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
  uVar3 = VectorSignedToFloat(iVar2 + -1,(byte)(in_fpscr >> 0x16) & 3);
  iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
  iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
  FloatVectorMax(CONCAT44((int)((ulonglong)unaff_d8 >> 0x20),param_7),
                 CONCAT44(extraout_s3,0x3f666666),2,0x20);
  local_50 = (float)VectorSignedToFloat(iVar2 + -1,(byte)((in_fpscr & 0xfffffff) >> 0x16) & 3);
  local_4c = VectorSignedToFloat(iVar4 + -1,(byte)((in_fpscr & 0xfffffff) >> 0x16) & 3);
  local_54 = uVar3;
  AbyssEngine::AEMath::operator*((AEMath *)&local_48,(Vector *)&local_54,local_50);
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x13c),(Vector *)&local_48);
  this[0x38] = (PlayerAsteroid)0x1;
  this[0x48] = (PlayerAsteroid)0x1;
  *(undefined4 *)(this + 0x84) = 0;
  emitTime = 0;
  *(undefined4 *)(this + 0x158) = 0;
  *(undefined4 *)(this + 0x15c) = 0x38d1b717;
  if (__stack_chk_guard - local_3c != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_3c);
  }
  return;
}

// ===== PlayerAsteroid::~PlayerAsteroid  @0x000f6c7c  (46 bytes)
/* PlayerAsteroid::~PlayerAsteroid() */

void __thiscall PlayerAsteroid::~PlayerAsteroid(PlayerAsteroid *this)

{
  void *pvVar1;
  
  *(undefined ***)this = &PTR__PlayerAsteroid_002641b0;
  if (*(Explosion **)(this + 0x128) != (Explosion *)0x0) {
    pvVar1 = (void *)Explosion::~Explosion(*(Explosion **)(this + 0x128));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x128) = 0;
  KIPlayer::~KIPlayer((KIPlayer *)this);
  return;
}

// ===== PlayerAsteroid::~PlayerAsteroid  @0x000f6cb0  (16 bytes)
/* PlayerAsteroid::~PlayerAsteroid() */

void __thiscall PlayerAsteroid::~PlayerAsteroid(PlayerAsteroid *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~PlayerAsteroid(this);
  operator_delete(pvVar1);
  return;
}

// ===== PlayerAsteroid::setAsteroidIndex  @0x000f6cc0  (6 bytes)
/* PlayerAsteroid::setAsteroidIndex(int) */

void __thiscall PlayerAsteroid::setAsteroidIndex(PlayerAsteroid *this,int param_1)

{
  *(int *)(this + 0x124) = param_1;
  return;
}

// ===== PlayerAsteroid::getPosition  @0x000f6cc6  (12 bytes)
/* PlayerAsteroid::getPosition() */

void PlayerAsteroid::getPosition(void)

{
  AEGeometry::getPosition();
  return;
}

// ===== PlayerAsteroid::setPosition  @0x000f6cd2  (6 bytes)
/* PlayerAsteroid::setPosition(AbyssEngine::AEMath::Vector const&) */

void PlayerAsteroid::setPosition(Vector *param_1)

{
  AEGeometry::setPosition(*(Vector **)(param_1 + 8));
  return;
}

// ===== PlayerAsteroid::translate  @0x000f6cd8  (6 bytes)
/* PlayerAsteroid::translate(AbyssEngine::AEMath::Vector const&) */

void PlayerAsteroid::translate(Vector *param_1)

{
  AEGeometry::translate(*(Vector **)(param_1 + 8));
  return;
}

// ===== PlayerAsteroid::isMinable  @0x000f6cde  (6 bytes)
/* PlayerAsteroid::isMinable() */

PlayerAsteroid __thiscall PlayerAsteroid::isMinable(PlayerAsteroid *this)

{
  return this[0x138];
}

// ===== PlayerAsteroid::getQuality  @0x000f6ce4  (6 bytes)
/* PlayerAsteroid::getQuality() */

undefined4 __thiscall PlayerAsteroid::getQuality(PlayerAsteroid *this)

{
  return *(undefined4 *)(this + 0x14c);
}

// ===== PlayerAsteroid::getScaling  @0x000f6cea  (6 bytes)
/* PlayerAsteroid::getScaling() */

undefined4 __thiscall PlayerAsteroid::getScaling(PlayerAsteroid *this)

{
  return *(undefined4 *)(this + 0x134);
}

// ===== PlayerAsteroid::getQualityFrameIndex  @0x000f6cf0  (10 bytes)
/* PlayerAsteroid::getQualityFrameIndex() */

int __thiscall PlayerAsteroid::getQualityFrameIndex(PlayerAsteroid *this)

{
  return 7 - *(int *)(this + 0x14c);
}

// ===== PlayerAsteroid::getQualityString  @0x000f6cfc  (60 bytes)
/* PlayerAsteroid::getQualityString() */

void PlayerAsteroid::getQualityString(void)

{
  String *in_r0;
  int in_r1;
  char *pcVar1;
  int iVar2;
  
  iVar2 = *(int *)(in_r1 + 0x14c);
  if (iVar2 == 7) {
    pcVar1 = "A";
  }
  else if (iVar2 == 6) {
    pcVar1 = "B";
  }
  else if (iVar2 == 5) {
    pcVar1 = "C";
  }
  else {
    pcVar1 = "D";
    if (iVar2 != 4) {
      pcVar1 = "E";
    }
  }
  AbyssEngine::String::String(in_r0,pcVar1,false);
  return;
}

// ===== PlayerAsteroid::setAsteroidCenter  @0x000f6d4c  (84 bytes)
/* PlayerAsteroid::setAsteroidCenter(AbyssEngine::AEMath::Vector) */

void PlayerAsteroid::setAsteroidCenter
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_20 = param_2;
  uStack_1c = param_3;
  uStack_18 = param_4;
  AbyssEngine::AEMath::Vector::operator=((Vector *)asteroidCenter,(Vector *)&local_20);
  fVar1 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_20);
  asteroidDistance = (int)fVar1;
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerAsteroid::setRotationEnabled  @0x000f6db0  (6 bytes)
/* PlayerAsteroid::setRotationEnabled(bool) */

void __thiscall PlayerAsteroid::setRotationEnabled(PlayerAsteroid *this,bool param_1)

{
  this[0x148] = (PlayerAsteroid)param_1;
  return;
}

// ===== PlayerAsteroid::initPush  @0x000f6db8  (314 bytes)
/* PlayerAsteroid::initPush(AbyssEngine::AEMath::Vector const&, int) */

void __thiscall PlayerAsteroid::initPush(PlayerAsteroid *this,Vector *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  uint in_fpscr;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  Vector aVStack_4c [12];
  AEMath aAStack_40 [12];
  int local_34;
  
  local_34 = __stack_chk_guard;
  (**(code **)(*(int *)this + 0x28))(aVStack_4c,this);
  AbyssEngine::AEMath::operator-(aAStack_40,param_1,aVStack_4c);
  fVar1 = (float)AbyssEngine::AEMath::VectorLength((Vector *)aAStack_40);
  fVar3 = (float)VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
  in_fpscr = in_fpscr & 0xfffffff;
  fVar4 = 1.0;
  if (fVar1 / fVar3 < 1.0) {
    fVar4 = fVar1 / fVar3;
  }
  fVar4 = (1.0 - fVar4) * 5000.0;
  *(int *)(this + 0x104) = (int)fVar4;
  *(int *)(this + 0x100) = (int)fVar4;
  (**(code **)(*(int *)this + 0x28))(&local_58,this);
  AbyssEngine::AEMath::operator-((AEMath *)aVStack_4c,(Vector *)&local_58,param_1);
  AbyssEngine::AEMath::VectorNormalize(aAStack_40,aVStack_4c);
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x108),(Vector *)aAStack_40);
  iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,200);
  uVar5 = VectorSignedToFloat(iVar2 + -100,(byte)(in_fpscr >> 0x16) & 3);
  iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,200);
  uVar6 = VectorSignedToFloat(iVar2 + -100,(byte)(in_fpscr >> 0x16) & 3);
  iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,200);
  local_50 = VectorSignedToFloat(iVar2 + -100,(byte)(in_fpscr >> 0x16) & 3);
  local_58 = uVar5;
  local_54 = uVar6;
  fVar4 = (float)AbyssEngine::AEMath::VectorNormalize((AEMath *)aVStack_4c,(Vector *)&local_58);
  AbyssEngine::AEMath::operator*(aAStack_40,fVar4,(Vector *)0x3e4ccccd);
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x114),(Vector *)aAStack_40);
  if (__stack_chk_guard != local_34) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerAsteroid::push  @0x000f6f10  (302 bytes)
/* PlayerAsteroid::push(int) */

void PlayerAsteroid::push(int param_1)

{
  int iVar1;
  Matrix *pMVar2;
  int in_r1;
  undefined4 *puVar3;
  AEGeometry *this;
  Vector *pVVar4;
  uint in_fpscr;
  float fVar5;
  float in_s1;
  float fVar6;
  AEMath aAStack_b0 [12];
  AEMath aAStack_a4 [60];
  undefined4 local_68 [5];
  undefined4 local_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined4 local_30;
  int local_2c;
  
  local_2c = __stack_chk_guard;
  if (0 < *(int *)(param_1 + 0x100)) {
    iVar1 = *(int *)(param_1 + 0x100) - in_r1;
    *(int *)(param_1 + 0x100) = iVar1;
    uStack_4c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uStack_48 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uStack_44 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    fVar5 = (float)VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x16) & 3);
    puVar3 = (undefined4 *)((uint)local_68 | 4);
    fVar6 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x104),(byte)(in_fpscr >> 0x16) & 3
                                      );
    local_68[0] = 0x3f800000;
    *puVar3 = 0;
    puVar3[1] = uStack_4c;
    puVar3[2] = uStack_48;
    puVar3[3] = uStack_44;
    local_54 = 0x3f800000;
    local_50 = 0;
    local_40 = 0x3f800000;
    uStack_38 = 0x3f8000003f800000;
    fVar5 = fVar5 / fVar6;
    local_30 = 0x3f800000;
    AbyssEngine::AEMath::MatrixSetRotation
              (aAStack_a4,fVar5 * *(float *)(param_1 + 0x11c),in_s1,
               fVar5 * *(float *)(param_1 + 0x118));
    iVar1 = *(int *)(param_1 + 0x130);
    if (0 < iVar1) {
      this = *(AEGeometry **)(param_1 + 8);
      pMVar2 = (Matrix *)AEGeometry::getMatrix(this);
      AbyssEngine::AEMath::operator*(aAStack_a4,pMVar2,(Matrix *)local_68);
      AEGeometry::setMatrix(this);
      iVar1 = *(int *)(param_1 + 0x130);
    }
    VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x16) & 3);
    pVVar4 = *(Vector **)(param_1 + 8);
    fVar6 = (float)VectorSignedToFloat(*(float *)(param_1 + 0x104),(byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::AEMath::operator*
              (aAStack_b0,(Vector *)(param_1 + 0x108),*(float *)(param_1 + 0x104));
    AbyssEngine::AEMath::operator*
              (aAStack_a4,(Vector *)aAStack_b0,(2.0 - fVar5) * 3.0 * (fVar6 / 5000.0));
    AEGeometry::translate(pVVar4);
  }
  if (__stack_chk_guard != local_2c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerAsteroid::update  @0x000f7060  (810 bytes)
/* PlayerAsteroid::update(int) */

void __thiscall PlayerAsteroid::update(PlayerAsteroid *this,int param_1)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  undefined4 *__ptr;
  void *pvVar5;
  Matrix *pMVar6;
  int iVar7;
  undefined4 uVar8;
  Explosion *this_00;
  Vector *pVVar9;
  uint in_fpscr;
  uint uVar10;
  float fVar11;
  float extraout_s0;
  float fVar12;
  float fVar13;
  float fVar14;
  AEMath aAStack_30 [12];
  int local_24;
  
  local_24 = __stack_chk_guard;
  *(int *)(this + 0x130) = param_1;
  if (param_1 != 0) {
    iVar3 = Player::isActive(*(Player **)(this + 4));
    if ((iVar3 == 0) && (*(int *)(this + 0x84) == 4)) {
      this[0x120] = (PlayerAsteroid)0x0;
    }
    else {
      iVar3 = Player::getHitpoints(*(Player **)(this + 4));
      iVar7 = *(int *)(this + 0x84);
      if ((iVar3 < 1) && (iVar7 == 0)) {
        *(undefined4 *)(this + 0x84) = 3;
        Level::asteroidDied(*(Level **)(this + 0x50));
        *(int *)(Globals::status + 0xd8) = *(int *)(Globals::status + 0xd8) + 1;
        if (this[0x48] == (PlayerAsteroid)0x0) {
LAB_000f7160:
          *(undefined4 *)(this + 0x4c) = 0;
          this[0x48] = (PlayerAsteroid)0x0;
        }
        else {
          iVar3 = *(int *)(this + 0x14c);
          if (iVar3 == 7) {
            iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
            if (3 < iVar3) {
              iVar3 = *(int *)(this + 0x14c);
              goto LAB_000f70f2;
            }
          }
          else {
LAB_000f70f2:
            if ((6 < iVar3) ||
               (iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,100), 0x13 < iVar3))
            goto LAB_000f7160;
          }
          piVar4 = operator_new(0xc);
          __ptr = operator_new__(4);
          piVar4[1] = (int)__ptr;
          piVar4[2] = 1;
          *__ptr = 0;
          *piVar4 = 0;
          *(int **)(this + 0x4c) = piVar4;
          iVar3 = *(int *)(this + 0x124);
          iVar7 = *(int *)(this + 0x14c);
          if (iVar3 == 0xd9) {
            piVar4[2] = 1;
            pvVar5 = realloc(__ptr,4);
            piVar4[1] = (int)pvVar5;
            uVar8 = 0xd9;
            if (iVar7 == 7) {
              uVar8 = 0xda;
            }
            *(undefined4 *)((int)pvVar5 + *piVar4 * 4) = uVar8;
          }
          else {
            piVar4[2] = 1;
            pvVar5 = realloc(__ptr,4);
            piVar4[1] = (int)pvVar5;
            if (iVar7 == 7) {
              iVar3 = iVar3 + 0xb;
            }
            *(int *)((int)pvVar5 + *piVar4 * 4) = iVar3;
          }
          iVar3 = 1;
          *piVar4 = piVar4[2];
          iVar7 = 1;
          if (*(int *)(this + 0x14c) != 7) {
            iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
            iVar3 = iVar3 + 1;
          }
          piVar4 = *(int **)(this + 0x4c);
          piVar4[2] = *piVar4 + 1;
          pvVar5 = realloc((void *)piVar4[1],(*piVar4 + 1) * 4);
          piVar4[1] = (int)pvVar5;
          *(int *)((int)pvVar5 + *piVar4 * 4) = iVar3;
          *piVar4 = piVar4[2];
          if (*(int *)(this + 0x124) == 0xa4) {
            iVar7 = 2;
          }
          KIPlayer::createCrate((KIPlayer *)this,iVar7);
        }
        this_00 = *(Explosion **)(this + 0x128);
        pMVar6 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
        if (__stack_chk_guard == local_24) {
          Explosion::start(this_00,pMVar6);
          return;
        }
        goto LAB_000f7384;
      }
      if (iVar7 == 3) {
        Explosion::update(*(Explosion **)(this + 0x128),param_1,(TargetFollowCamera *)0x0);
        iVar3 = Explosion::isPlaying(*(Explosion **)(this + 0x128));
        if (iVar3 == 0) {
          *(undefined4 *)(this + 0x84) = 4;
          fVar11 = extraout_s0;
          goto LAB_000f7186;
        }
      }
      else if (iVar7 == 4) {
        fVar11 = (float)KIPlayer::setActive(SUB41(this,0));
LAB_000f7186:
        Player::setBombForce(*(Player **)(this + 4),fVar11);
      }
      iVar7 = *(int *)(this + 0x154);
      iVar3 = Player::getHitpoints(*(Player **)(this + 4));
      if (iVar3 < iVar7) {
        *(undefined4 *)(this + 0x158) = 0x3dcccccd;
        *(undefined4 *)(this + 0x15c) = 0x3a83126f;
        uVar8 = Player::getHitpoints(*(Player **)(this + 4));
        *(undefined4 *)(this + 0x154) = uVar8;
      }
      if (this[0x148] != (PlayerAsteroid)0x0) {
        fVar11 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        pVVar9 = *(Vector **)(this + 8);
        AbyssEngine::AEMath::operator*(aAStack_30,(Vector *)(this + 0x13c),fVar11 * 0.001);
        AEGeometry::rotate(pVVar9);
      }
      fVar11 = (float)Player::getBombForce(*(Player **)(this + 4));
      uVar1 = in_fpscr & 0xfffffff | (uint)(fVar11 < 0.0) << 0x1f | (uint)(fVar11 == 0.0) << 0x1e;
      uVar10 = uVar1 | (uint)NAN(fVar11) << 0x1c;
      bVar2 = (byte)(uVar1 >> 0x18);
      if ((!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(uVar10 >> 0x1c) & 1)) &&
         (*(int *)(this + 0x84) == 3)) {
        Player::getHitVector();
        pVVar9 = (Vector *)(this + 0x8c);
        AbyssEngine::AEMath::Vector::operator=(pVVar9,(Vector *)aAStack_30);
        fVar13 = *(float *)(this + 0x134);
        uVar1 = uVar10 & 0xfffffff | (uint)(fVar13 < 1.0) << 0x1f | (uint)(fVar13 == 1.0) << 0x1e;
        fVar14 = fVar13;
        fVar12 = 1.0;
        if (fVar13 < 0.6 && fVar13 <= 1.0) {
          fVar14 = 0.6;
          fVar12 = 0.6;
        }
        bVar2 = (byte)(uVar1 >> 0x18);
        if (!(bool)(bVar2 >> 6 & 1) && (bool)(bVar2 >> 7) == NAN(fVar13)) {
          fVar14 = fVar12;
        }
        fVar12 = (float)VectorSignedToFloat((int)(fVar11 * 1024.0 * (fVar14 / -100.0 + 1.0)),
                                            (byte)(uVar1 >> 0x16) & 3);
        AbyssEngine::AEMath::Vector::operator*=(pVVar9,fVar12);
        (**(code **)(*(int *)this + 0x20))(this,pVVar9);
        Explosion::translate(*(Vector **)(this + 0x128));
        if (*(Vector **)(this + 0x74) != (Vector *)0x0) {
          AEGeometry::translate(*(Vector **)(this + 0x74));
        }
        fVar12 = fVar11 * 0.98;
        if ((int)((uint)(fVar11 * 0.98 < 0.05) << 0x1f) < 0) {
          fVar12 = 0.0;
        }
        Player::setBombForce(*(Player **)(this + 4),fVar12);
      }
    }
  }
  if (__stack_chk_guard == local_24) {
    return;
  }
LAB_000f7384:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== PlayerAsteroid::render  @0x000f73d0  (54 bytes)
/* PlayerAsteroid::render() */

void __thiscall PlayerAsteroid::render(PlayerAsteroid *this)

{
  if (this[0xf1] != (PlayerAsteroid)0x0) {
    if (*(AEGeometry **)(this + 0x74) != (AEGeometry *)0x0) {
      AEGeometry::render(*(AEGeometry **)(this + 0x74));
    }
    if (*(int *)(this + 0x84) == 0) {
      AEGeometry::render(*(AEGeometry **)(this + 8));
      return;
    }
    if (*(int *)(this + 0x84) == 3) {
      Explosion::render(*(Explosion **)(this + 0x128));
      return;
    }
  }
  return;
}

// ===== PlayerAsteroid::outerCollide  @0x000f7406  (10 bytes)
/* PlayerAsteroid::outerCollide(float, float, float) */

void PlayerAsteroid::outerCollide(float param_1,float param_2,float param_3)

{
  int *in_r0;
  
                    /* WARNING: Could not recover jumptable at 0x000f740e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_r0 + 0x38))();
  return;
}

// ===== PlayerAsteroid::outerCollide  @0x000f7410  (10 bytes)
/* PlayerAsteroid::outerCollide(AbyssEngine::AEMath::Vector) */

void PlayerAsteroid::outerCollide(int *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000f7418. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x38))();
  return;
}

// ===== PlayerAsteroid::getProjectionVector  @0x000f741c  (110 bytes)
/* PlayerAsteroid::getProjectionVector(AbyssEngine::AEMath::Vector const&) */

void PlayerAsteroid::getProjectionVector(Vector *param_1)

{
  undefined8 *in_r2;
  undefined8 uVar1;
  Vector aVStack_24 [12];
  int local_18;
  
  local_18 = __stack_chk_guard;
  uVar1 = *in_r2;
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(in_r2 + 1);
  *(undefined8 *)param_1 = uVar1;
  AEGeometry::getPosition();
  AbyssEngine::AEMath::Vector::operator=((Vector *)pos,aVStack_24);
  AbyssEngine::AEMath::Vector::operator-=((Vector *)pos,param_1);
  AbyssEngine::AEMath::Vector::operator=(param_1,(Vector *)pos);
  AbyssEngine::AEMath::VectorNormalize((AEMath *)aVStack_24,param_1);
  AbyssEngine::AEMath::Vector::operator=(param_1,aVStack_24);
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerAsteroid::collide  @0x000f7498  (216 bytes)
/* PlayerAsteroid::collide(float, float, float) */

void __thiscall
PlayerAsteroid::collide(PlayerAsteroid *this,float param_1,float param_2,float param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  float in_r1;
  float in_r2;
  float in_r3;
  uint in_fpscr;
  float fVar4;
  float fVar5;
  float local_50;
  float local_48;
  float local_40;
  
  iVar1 = __stack_chk_guard;
  iVar2 = Player::getHitpoints(*(Player **)(this + 4));
  if (0 < iVar2) {
    AEGeometry::getPosition();
    AEGeometry::getPosition();
    AEGeometry::getPosition();
    fVar4 = (float)VectorSignedToFloat(*(int *)(*(int *)(this + 4) + 0x40),
                                       (byte)(in_fpscr >> 0x16) & 3);
    if ((((in_r1 - local_40 < fVar4) &&
         (fVar5 = (float)VectorSignedToFloat(-*(int *)(*(int *)(this + 4) + 0x40),
                                             (byte)((in_fpscr & 0xfffffff) >> 0x16) & 3),
         fVar5 < in_r1 - local_40)) && ((int)((uint)(in_r2 - local_48 < fVar4) << 0x1f) < 0)) &&
       (((fVar5 < in_r2 - local_48 && ((int)((uint)(in_r3 - local_50 < fVar4) << 0x1f) < 0)) &&
        (fVar5 < in_r3 - local_50)))) {
      uVar3 = 1;
      goto LAB_000f7554;
    }
  }
  uVar3 = 0;
LAB_000f7554:
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}

