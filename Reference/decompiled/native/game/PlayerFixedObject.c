// Class: PlayerFixedObject
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== PlayerFixedObject::PlayerFixedObject  @0x0017ece0  (696 bytes)
/* PlayerFixedObject::PlayerFixedObject(int, int, Player*, AEGeometry*, float, float, float) */

void __thiscall
PlayerFixedObject::PlayerFixedObject
          (PlayerFixedObject *this,int param_1,int param_2,Player *param_3,AEGeometry *param_4,
          float param_5,float param_6,float param_7)

{
  Mission *this_00;
  int iVar1;
  Generator *this_01;
  Station *this_02;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  void *pvVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  float in_stack_00000004;
  float in_stack_00000008;
  float in_stack_0000000c;
  Vector local_60 [12];
  int local_54;
  
  local_54 = __stack_chk_guard;
  KIPlayer::KIPlayer((KIPlayer *)this,param_1,-1,param_3,param_4,param_5,param_6,param_7,
                     SUB41(in_stack_00000004,0));
  uVar2 = 0;
  uVar9 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar10 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar11 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined ***)this = &PTR__PlayerFixedObject_00264410;
  *(undefined4 *)(this + 0x154) = 0;
  *(undefined4 *)(this + 0x158) = uVar9;
  *(undefined4 *)(this + 0x15c) = uVar10;
  *(undefined4 *)(this + 0x160) = uVar11;
  *(undefined4 *)(this + 0x144) = 0;
  *(undefined4 *)(this + 0x148) = uVar9;
  *(undefined4 *)(this + 0x14c) = uVar10;
  *(undefined4 *)(this + 0x150) = uVar11;
  *(undefined4 *)(this + 0x134) = 0;
  *(undefined4 *)(this + 0x138) = uVar9;
  *(undefined4 *)(this + 0x13c) = uVar10;
  *(undefined4 *)(this + 0x140) = uVar11;
  AbyssEngine::String::String((String *)(this + 0x1a8));
  *(undefined4 *)(this + 0x188) = 0;
  *(undefined4 *)(this + 0x120) = 0;
  *(undefined2 *)(this + 0x180) = 0;
  *(int *)(this + 0x24) = param_2;
  *(undefined4 *)(this + 0x124) = 0;
  *(undefined4 *)(this + 0x128) = 0;
  *(undefined4 *)(this + 300) = 0;
  *(undefined4 *)(this + 0x164) = 0;
  *(undefined4 *)(this + 0x168) = 0;
  this[0x16c] = (PlayerFixedObject)0x0;
  this[0x1b0] = (PlayerFixedObject)0x0;
  *(undefined4 *)(this + 0x18c) = 0;
  *(undefined4 *)(this + 0x170) = uVar2;
  *(undefined4 *)(this + 0x174) = uVar9;
  *(undefined4 *)(this + 0x178) = uVar10;
  *(undefined4 *)(this + 0x17c) = uVar11;
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x28),local_60);
  *(int *)(this + 0x174) = (int)in_stack_00000004;
  *(int *)(this + 0x178) = (int)in_stack_00000008;
  *(int *)(this + 0x17c) = (int)in_stack_0000000c;
  this[0x130] = (PlayerFixedObject)0x0;
  *(undefined4 *)(this + 400) = 0xffffffff;
  *(undefined4 *)(this + 0x19c) = 0xffffffff;
  *(undefined4 *)(this + 0x1a0) = 0;
  AbyssEngine::String::String((String *)local_60,"",false);
  AbyssEngine::String::operator=((String *)(this + 0x1a8),local_60);
  AbyssEngine::String::~String((String *)local_60);
  this_00 = (Mission *)Status::getMission(Globals::status);
  iVar1 = Mission::isCampaignMission(this_00);
  if ((iVar1 == 1) &&
     ((iVar1 = Status::getCurrentCampaignMission(Globals::status), iVar1 == 0x28 ||
      (iVar1 = Status::getCurrentCampaignMission(Globals::status), iVar1 == 0x29)))) {
    pvVar7 = *(void **)(this + 0x4c);
    if (pvVar7 != (void *)0x0) {
      if (*(void **)((int)pvVar7 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar7 + 4));
      }
      operator_delete(pvVar7);
    }
    *(undefined4 *)(this + 0x4c) = 0;
  }
  else {
    this_01 = operator_new(1);
    Generator::Generator(this_01);
    if (param_1 == 0x37a3) {
      this[0x3d] = (PlayerFixedObject)0x1;
      this_02 = (Station *)Status::getStation(Globals::status);
      iVar1 = Station::getIndex(this_02);
      iVar8 = 0;
      do {
        if ((&DAT_00251f90)[iVar8] == iVar1) {
          uVar2 = Generator::getLootList
                            (this_01,(&DAT_002543e0)[iVar8 * 2],(&DAT_002543e4)[iVar8 * 2]);
          *(undefined4 *)(this + 0x4c) = uVar2;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < 4);
    }
    else {
      piVar3 = (int *)Generator::getLootList(this_01,-1,-1);
      *(int **)(this + 0x4c) = piVar3;
      if ((piVar3 != (int *)0x0) && (param_1 != 0x498e)) {
        if (param_1 != 0x4a88) {
          piVar3 = (int *)*piVar3;
        }
        if (param_1 != 0x4a88 && piVar3 != (int *)0x0) {
          iVar1 = 1;
          do {
            if (param_1 == 0xe) {
              iVar8 = AbyssEngine::AERandom::nextInt(Globals::rnd,8);
              puVar5 = *(uint **)(this + 0x4c);
              *(int *)(puVar5[1] + iVar1 * 4) = *(int *)(puVar5[1] + iVar1 * 4) * (iVar8 + 5);
            }
            else {
              iVar8 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
              *(int *)(*(int *)(*(int *)(this + 0x4c) + 4) + iVar1 * 4) =
                   *(int *)(*(int *)(*(int *)(this + 0x4c) + 4) + iVar1 * 4) * (iVar8 + 2);
              iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,5);
              puVar5 = *(uint **)(this + 0x4c);
              iVar8 = *(int *)(puVar5[1] + iVar1 * 4);
              if (iVar8 < iVar4 + 8) {
                iVar8 = iVar4 + 8;
              }
              *(int *)(puVar5[1] + iVar1 * 4) = iVar8;
            }
            uVar6 = iVar1 + 1;
            iVar1 = iVar1 + 2;
          } while (uVar6 < *puVar5);
        }
      }
    }
    pvVar7 = (void *)Generator::~Generator(this_01);
    operator_delete(pvVar7);
  }
  *(undefined1 *)(*(int *)(this + 4) + 0x45) = 1;
  if ((param_1 != 0x37a3) && (*(undefined4 *)(this + 0xf4) = 0x2f, param_1 == 0xe)) {
    this[0x130] = (PlayerFixedObject)0x0;
    *(undefined4 *)(this + 0xf4) = 0xffffffff;
  }
  if (__stack_chk_guard - local_54 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_54);
}

// ===== PlayerFixedObject::~PlayerFixedObject  @0x0017f004  (154 bytes)
/* PlayerFixedObject::~PlayerFixedObject() */

void __thiscall PlayerFixedObject::~PlayerFixedObject(PlayerFixedObject *this)

{
  AEGeometry *this_00;
  void *pvVar1;
  
  *(undefined ***)this = &PTR__PlayerFixedObject_00264410;
  this_00 = *(AEGeometry **)(this + 0x120);
  if (this_00 != *(AEGeometry **)(this + 8)) {
    if (this_00 != (AEGeometry *)0x0) {
      pvVar1 = (void *)AEGeometry::~AEGeometry(this_00);
      operator_delete(pvVar1);
    }
    *(undefined4 *)(this + 0x120) = 0;
  }
  if (*(Array **)(this + 0x124) != (Array *)0x0) {
    ArrayReleaseClasses<BoundingVolume*>(*(Array **)(this + 0x124));
    pvVar1 = *(void **)(this + 0x124);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x124) = 0;
  if (*(Array **)(this + 0x128) != (Array *)0x0) {
    ArrayReleaseClasses<BoundingVolume*>(*(Array **)(this + 0x128));
    pvVar1 = *(void **)(this + 0x128);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x128) = 0;
  if (*(Explosion **)(this + 0x188) != (Explosion *)0x0) {
    pvVar1 = (void *)Explosion::~Explosion(*(Explosion **)(this + 0x188));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x188) = 0;
  AbyssEngine::String::~String((String *)(this + 0x1a8));
  KIPlayer::~KIPlayer((KIPlayer *)this);
  return;
}

// ===== PlayerFixedObject::~PlayerFixedObject  @0x0017f0a4  (16 bytes)
/* PlayerFixedObject::~PlayerFixedObject() */

void __thiscall PlayerFixedObject::~PlayerFixedObject(PlayerFixedObject *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~PlayerFixedObject(this);
  operator_delete(pvVar1);
  return;
}

// ===== PlayerFixedObject::reset  @0x0017f0b4  (174 bytes)
/* PlayerFixedObject::reset() */

void __thiscall PlayerFixedObject::reset(PlayerFixedObject *this)

{
  undefined8 local_20;
  undefined4 local_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  KIPlayer::reset((KIPlayer *)this);
  (**(code **)(*(int *)this + 0x48))
            (this,*(undefined4 *)(this + 0x54),*(undefined4 *)(this + 0x58),
             *(undefined4 *)(this + 0x5c));
  *(undefined4 *)(this + 0x164) = 0;
  local_20 = *(undefined8 *)(this + 0x54);
  local_18 = *(undefined4 *)(this + 0x5c);
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x134),(Vector *)&local_20);
  local_18 = *(undefined4 *)(this + 0x13c);
  local_20 = *(undefined8 *)(this + 0x134);
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x28),(Vector *)&local_20);
  *(undefined4 *)(this + 300) = 0;
  if (*(int *)(this + 0x84) != 5) {
    *(undefined4 *)(this + 0x84) = 0;
  }
  local_20 = 0;
  local_18 = 0;
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x8c),(Vector *)&local_20);
  local_20 = 0;
  local_18 = 0;
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x140),(Vector *)&local_20);
  local_20 = 0;
  local_18 = 0;
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x14c),(Vector *)&local_20);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerFixedObject::setMoving  @0x0017f16c  (6 bytes)
/* PlayerFixedObject::setMoving(bool) */

void __thiscall PlayerFixedObject::setMoving(PlayerFixedObject *this,bool param_1)

{
  this[0x130] = (PlayerFixedObject)param_1;
  return;
}

// ===== PlayerFixedObject::setPosition  @0x0017f174  (194 bytes)
/* PlayerFixedObject::setPosition(float, float, float) */

void PlayerFixedObject::setPosition(float param_1,float param_2,float param_3)

{
  int in_r0;
  Matrix *pMVar1;
  uint *puVar2;
  int *piVar3;
  float in_r1;
  float in_r2;
  float in_r3;
  int iVar4;
  uint uVar5;
  float extraout_s0;
  float extraout_s0_00;
  float fVar6;
  float extraout_s1;
  float extraout_s1_00;
  float fVar7;
  float extraout_s2;
  float extraout_s2_00;
  float fVar8;
  Vector aVStack_30 [12];
  int local_24;
  
  local_24 = __stack_chk_guard;
  *(int *)(in_r0 + 0x174) = (int)in_r1;
  *(int *)(in_r0 + 0x178) = (int)in_r2;
  *(int *)(in_r0 + 0x17c) = (int)in_r3;
  *(float *)(in_r0 + 0x54) = in_r1;
  *(float *)(in_r0 + 0x58) = in_r2;
  *(float *)(in_r0 + 0x5c) = in_r3;
  AEGeometry::setPosition((float)(int)in_r3,param_2,in_r3);
  iVar4 = *(int *)(in_r0 + 4);
  pMVar1 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(in_r0 + 8));
  AbyssEngine::AEMath::Matrix::operator=((Matrix *)(iVar4 + 4),pMVar1);
  AEGeometry::getPosition();
  AbyssEngine::AEMath::Vector::operator=((Vector *)(in_r0 + 0x28),aVStack_30);
  puVar2 = *(uint **)(in_r0 + 0x124);
  fVar6 = extraout_s0;
  fVar7 = extraout_s1;
  fVar8 = extraout_s2;
  if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
    uVar5 = 0;
    do {
      piVar3 = *(int **)(puVar2[1] + uVar5 * 4);
      (**(code **)(*piVar3 + 4))
                (piVar3,*(undefined4 *)(in_r0 + 0x28),*(undefined4 *)(in_r0 + 0x2c),
                 *(undefined4 *)(in_r0 + 0x30));
      puVar2 = *(uint **)(in_r0 + 0x124);
      uVar5 = uVar5 + 1;
      fVar6 = extraout_s0_00;
      fVar7 = extraout_s1_00;
      fVar8 = extraout_s2_00;
    } while (uVar5 < *puVar2);
  }
  if (*(int *)(in_r0 + 0x120) != 0) {
    AEGeometry::setPosition(fVar6,fVar7,fVar8);
  }
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerFixedObject::setPosition  @0x0017f240  (26 bytes)
/* PlayerFixedObject::setPosition(AbyssEngine::AEMath::Vector const&) */

void __thiscall PlayerFixedObject::setPosition(PlayerFixedObject *this,Vector *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0017f258. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0x48))
            (this,*(undefined4 *)param_1,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
  return;
}

// ===== PlayerFixedObject::translate  @0x0017f25a  (70 bytes)
/* PlayerFixedObject::translate(AbyssEngine::AEMath::Vector const&) */

void __thiscall PlayerFixedObject::translate(PlayerFixedObject *this,Vector *param_1)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x174),(byte)(in_fpscr >> 0x16) & 3);
  fVar2 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x178),(byte)(in_fpscr >> 0x16) & 3);
  fVar3 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x17c),(byte)(in_fpscr >> 0x16) & 3);
                    /* WARNING: Could not recover jumptable at 0x0017f29e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0x48))
            (this,fVar1 + *(float *)param_1,fVar2 + *(float *)(param_1 + 4),
             fVar3 + *(float *)(param_1 + 8));
  return;
}

// ===== PlayerFixedObject::setBV  @0x0017f2a0  (6 bytes)
/* PlayerFixedObject::setBV(Array<BoundingVolume*>*) */

void __thiscall PlayerFixedObject::setBV(PlayerFixedObject *this,Array *param_1)

{
  *(Array **)(this + 0x124) = param_1;
  return;
}

// ===== PlayerFixedObject::setBV  @0x0017f2a6  (62 bytes)
/* PlayerFixedObject::setBV(BoundingVolume*) */

void __thiscall PlayerFixedObject::setBV(PlayerFixedObject *this,BoundingVolume *param_1)

{
  int *piVar1;
  undefined4 *__ptr;
  void *pvVar2;
  
  piVar1 = operator_new(0xc);
  __ptr = operator_new__(4);
  piVar1[1] = (int)__ptr;
  *__ptr = 0;
  *piVar1 = 0;
  *(int **)(this + 0x124) = piVar1;
  piVar1[2] = 1;
  pvVar2 = realloc(__ptr,4);
  piVar1[1] = (int)pvVar2;
  *(BoundingVolume **)((int)pvVar2 + *piVar1 * 4) = param_1;
  *piVar1 = piVar1[2];
  return;
}

// ===== PlayerFixedObject::getPosition  @0x0017f2f2  (38 bytes)
/* PlayerFixedObject::getPosition() */

void PlayerFixedObject::getPosition(void)

{
  undefined4 *in_r0;
  int in_r1;
  uint in_fpscr;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = VectorSignedToFloat(*(undefined4 *)(in_r1 + 0x174),(byte)(in_fpscr >> 0x16) & 3);
  uVar2 = VectorSignedToFloat(*(undefined4 *)(in_r1 + 0x178),(byte)(in_fpscr >> 0x16) & 3);
  uVar3 = VectorSignedToFloat(*(undefined4 *)(in_r1 + 0x17c),(byte)(in_fpscr >> 0x16) & 3);
  *in_r0 = uVar1;
  in_r0[1] = uVar2;
  in_r0[2] = uVar3;
  return;
}

// ===== PlayerFixedObject::setWreckedMeshId  @0x0017f318  (166 bytes)
/* PlayerFixedObject::setWreckedMeshId(int) */

void __thiscall PlayerFixedObject::setWreckedMeshId(PlayerFixedObject *this,int param_1)

{
  AEGeometry *pAVar1;
  int iVar2;
  undefined4 uVar3;
  
  *(ushort *)(this + 0x180) = (ushort)param_1;
  pAVar1 = operator_new(0xc0);
  AEGeometry::AEGeometry(pAVar1,(ushort)param_1,Globals::Canvas,true);
  *(AEGeometry **)(this + 0x120) = pAVar1;
  iVar2 = AbyssEngine::PaintCanvas::TransformGetTransform(Globals::Canvas,*(uint *)(pAVar1 + 0xc));
  *(undefined4 *)(iVar2 + 0xe0) = 0x48f42400;
  iVar2 = *(int *)(this + 0xa8);
  if (iVar2 < 0xf) {
    if (iVar2 == 0xd) {
      pAVar1 = (AEGeometry *)&DAT_00000004;
    }
    else {
      if (iVar2 != 0xe) {
LAB_0017f382:
        pAVar1 = *(AEGeometry **)(this + 400);
        if ((int)pAVar1 < 0) {
          return;
        }
        goto LAB_0017f3a6;
      }
      pAVar1 = (AEGeometry *)0x0;
    }
  }
  else if (iVar2 == 0xf) {
    if (*(int *)(this + 0x24) == 3) {
      pAVar1 = (AEGeometry *)0x1;
    }
    else if (*(int *)(this + 0x24) == 2) {
      pAVar1 = (AEGeometry *)0x2;
    }
    else {
      pAVar1 = (AEGeometry *)0x3;
    }
  }
  else {
    if (iVar2 != 0x37a3) goto LAB_0017f382;
    pAVar1 = (AEGeometry *)0x5;
  }
  *(AEGeometry **)(this + 400) = pAVar1;
LAB_0017f3a6:
  uVar3 = Globals::getWreckCollision(Globals::globals,pAVar1);
  *(undefined4 *)(this + 0x128) = uVar3;
  return;
}

// ===== PlayerFixedObject::moveForward  @0x0017f3d8  (160 bytes)
/* PlayerFixedObject::moveForward(int) */

void __thiscall PlayerFixedObject::moveForward(PlayerFixedObject *this,int param_1)

{
  Matrix *pMVar1;
  uint *puVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  uint in_fpscr;
  float fVar6;
  Vector aVStack_24 [12];
  int local_18;
  
  fVar6 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  local_18 = __stack_chk_guard;
  *(int *)(this + 0x17c) = *(int *)(this + 0x17c) + param_1;
  AEGeometry::moveForward(*(AEGeometry **)(this + 8),fVar6);
  iVar5 = *(int *)(this + 4);
  pMVar1 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
  AbyssEngine::AEMath::Matrix::operator=((Matrix *)(iVar5 + 4),pMVar1);
  AEGeometry::getPosition();
  fVar6 = (float)AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x28),aVStack_24);
  if (*(AEGeometry **)(this + 0x120) != (AEGeometry *)0x0) {
    AEGeometry::moveForward(*(AEGeometry **)(this + 0x120),fVar6);
  }
  puVar2 = *(uint **)(this + 0x124);
  if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
    uVar4 = 0;
    do {
      piVar3 = *(int **)(puVar2[1] + uVar4 * 4);
      (**(code **)(*piVar3 + 4))
                (piVar3,*(undefined4 *)(this + 0x28),*(undefined4 *)(this + 0x2c),
                 *(undefined4 *)(this + 0x30));
      puVar2 = *(uint **)(this + 0x124);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar2);
  }
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerFixedObject::update  @0x0017f480  (2740 bytes)
/* PlayerFixedObject::update(int) */

void __thiscall PlayerFixedObject::update(PlayerFixedObject *this,int param_1)

{
  uint uVar1;
  byte bVar2;
  Player PVar3;
  Player *pPVar4;
  Standing *pSVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  Explosion *pEVar11;
  uint *puVar12;
  PlayerEgo *pPVar13;
  TargetFollowCamera *pTVar14;
  ushort uVar15;
  int iVar16;
  int *piVar17;
  uint uVar18;
  Vector *pVVar19;
  Matrix *pMVar20;
  PlayerFixedObject *pPVar21;
  bool bVar22;
  bool bVar23;
  uint in_fpscr;
  float fVar24;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s1;
  longlong lVar25;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  uint local_40 [4];
  
  local_40[3] = __stack_chk_guard;
  *(int *)(this + 300) = param_1;
  if (*(int *)(this + 0xf4) == -1) {
    bVar23 = false;
  }
  else {
    bVar23 = this[0x130] != (PlayerFixedObject)0x0;
  }
  Player::update(*(Player **)(this + 4),param_1,bVar23);
  uVar18 = *(uint *)(this + 0x24);
  if ((uVar18 & 0xfffffffe) == 8) {
    PVar3 = (Player)0x1;
  }
  else {
    pSVar5 = (Standing *)Status::getStanding(Globals::status);
    PVar3 = (Player)Standing::isEnemy(pSVar5,*(int *)(this + 0x24));
    uVar18 = *(uint *)(this + 0x24);
  }
  pPVar4 = *(Player **)(this + 4);
  pPVar4[0x5c] = PVar3;
  if ((uVar18 & 0xfffffffe) == 8) {
    PVar3 = (Player)0x0;
  }
  else {
    pSVar5 = (Standing *)Status::getStanding(Globals::status);
    PVar3 = (Player)Standing::isFriend(pSVar5,*(int *)(this + 0x24));
    pPVar4 = *(Player **)(this + 4);
  }
  pPVar4[0x5d] = PVar3;
  iVar6 = Player::turnedEnemy(pPVar4);
  pPVar4 = *(Player **)(this + 4);
  if (iVar6 == 1) {
    *(undefined2 *)(pPVar4 + 0x5c) = 1;
  }
  iVar6 = Player::isAlwaysFriend(pPVar4);
  if (iVar6 == 1) {
    iVar6 = *(int *)(this + 4);
    *(undefined1 *)(iVar6 + 0x5d) = 1;
    *(undefined1 *)(iVar6 + 0x5c) = 0;
  }
  if (*(int *)(this + 0x84) != 6) {
    fVar7 = (float)Player::getBombForce(*(Player **)(this + 4));
    fVar8 = (float)Player::getEmpForce(*(Player **)(this + 4));
    in_fpscr = in_fpscr & 0xfffffff;
    uVar1 = in_fpscr | (uint)(fVar7 < 0.0) << 0x1f | (uint)(fVar7 == 0.0) << 0x1e;
    uVar18 = uVar1 | (uint)NAN(fVar7) << 0x1c;
    bVar2 = (byte)(uVar1 >> 0x18);
    if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(uVar18 >> 0x1c) & 1)) {
      fVar24 = fVar7 * 0.98;
      if (fVar7 * 0.98 < 0.05) {
        fVar24 = 0.0;
      }
      Player::setBombForce(*(Player **)(this + 4),fVar24);
      uVar18 = in_fpscr;
    }
    uVar18 = uVar18 & 0xfffffff;
    uVar1 = uVar18 | (uint)(fVar8 < 0.0) << 0x1f | (uint)(fVar8 == 0.0) << 0x1e;
    in_fpscr = uVar1 | (uint)NAN(fVar8) << 0x1c;
    bVar2 = (byte)(uVar1 >> 0x18);
    if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
      fVar7 = 0.0;
      fVar24 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
      fVar8 = fVar8 - fVar24;
      if (0.05 <= fVar8) {
        fVar7 = fVar8;
      }
      this[0x20] = (PlayerFixedObject)(0.05 <= fVar8);
      Player::setEmpForce(*(Player **)(this + 4),fVar7);
      in_fpscr = uVar18;
    }
  }
  if ((this[0x20] == (PlayerFixedObject)0x0) && (1 < *(int *)(this + 0x84) - 3U)) {
    uVar18 = *(uint *)(this + 0xa8);
    bVar23 = uVar18 != 0x37a3;
    if (bVar23) {
      uVar18 = (uint)(byte)this[0x130];
    }
    if (bVar23 && uVar18 != 0) {
      moveForward(this,param_1);
    }
    iVar6 = Status::getCurrentCampaignMission(Globals::status);
    iVar16 = *(int *)(this + 0xa8);
    bVar23 = iVar6 == 0x5b;
    if (bVar23) {
      iVar6 = 0x494e;
    }
    if (!bVar23 || iVar16 != iVar6) {
      if (iVar16 == 0x494a) {
        iVar6 = Status::getCurrentCampaignMission(Globals::status);
        if (iVar6 == 0x91) goto LAB_0017f65e;
        iVar16 = *(int *)(this + 0xa8);
      }
      if (iVar16 != 0x4220) {
        uVar9 = AbyssEngine::PaintCanvas::TransformGetTransform
                          (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc));
        AbyssEngine::Transform::Update(CONCAT44(1,uVar9),SUB41(param_1,0));
      }
    }
  }
LAB_0017f65e:
  iVar6 = Player::getHitpoints(*(Player **)(this + 4));
  if (iVar6 < 1) {
    iVar6 = *(int *)(this + 0x84);
    if (1 < iVar6 - 3U) {
      if (*(char *)(*(int *)(this + 4) + 0x5c) == '\0') {
        Level::friendDied(*(Level **)(this + 0x50));
      }
      else {
        Level::enemyDied(*(Level **)(this + 0x50),*(int *)(this + 0xa8),
                         *(bool *)(*(int *)(this + 4) + 0x44));
      }
      pPVar21 = this + 0xa8;
      if (*(int *)pPVar21 == 0x37a3) {
        Level::pirateStationAction(*(Level **)(this + 0x50),false);
      }
      *(undefined4 *)(this + 0x84) = 3;
      this[0x130] = (PlayerFixedObject)0x0;
      iVar6 = KIPlayer::cargoAvailable((KIPlayer *)this);
      this[0x48] = SUB41(iVar6,0);
      if (iVar6 != 0) {
        KIPlayer::createCrate((KIPlayer *)this,0);
      }
      setExhaustVisible(this,false);
      pMVar20 = *(Matrix **)(this + 0x120);
      AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
      AEGeometry::setMatrix(pMVar20);
      pMVar20 = *(Matrix **)(this + 0x120);
      if (pMVar20 == (Matrix *)0x0) {
        iVar6 = *(int *)(this + 0x50);
        iVar16 = *(int *)(iVar6 + 0x74);
        if (*(int *)(this + 0xa8) == 0x37a3 || *(int *)(this + 0xa8) == 0xe) {
          puVar10 = (undefined4 *)(iVar6 + 0x54);
        }
        else {
          puVar10 = (undefined4 *)(iVar6 + 0x50);
        }
        pMVar20 = (Matrix *)*puVar10;
        AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
        fVar7 = (float)ParticleSystemManager::systemSetMatrix(iVar16,pMVar20);
        pVVar19 = (Vector *)0x0;
        if (Globals::options[0xf] != '\0') {
          pVVar19 = (Vector *)(this + 0x28);
        }
        FModSound::play(Globals::sound,0x14,pVVar19,(Vector *)0x0,fVar7);
        iVar6 = *(int *)(this + 0x50);
        if (*(int *)(this + 0xa8) == 0x37a3 || *(int *)(this + 0xa8) == 0xe) {
          piVar17 = (int *)(iVar6 + 0x54);
        }
        else {
          piVar17 = (int *)(iVar6 + 0x50);
        }
        ParticleSystemManager::enableSystemEmit
                  (*(ParticleSystemManager **)(iVar6 + 0x74),*piVar17,true);
        pEVar11 = operator_new(0x68);
        Explosion::Explosion(pEVar11,0);
        *(Explosion **)(this + 0x188) = pEVar11;
        Explosion::addFireStreaks(pEVar11);
        pEVar11 = *(Explosion **)(this + 0x188);
      }
      else {
        AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
        AEGeometry::setMatrix(pMVar20);
        uVar9 = AbyssEngine::PaintCanvas::TransformGetTransform
                          (Globals::Canvas,*(uint *)(*(int *)(this + 0x120) + 0xc));
        AbyssEngine::Transform::SetAnimationState(uVar9,1,0);
        if (((*(int *)(this + 0x24) == 3) && (this[0x130] != (PlayerFixedObject)0x0)) &&
           (*(uint *)(*(int *)(this + 8) + 0x10) != 0xffffffff)) {
          AEGeometry::addChild(*(AEGeometry **)(this + 0x120),*(uint *)(*(int *)(this + 8) + 0x10));
        }
        iVar6 = *(int *)(this + 0x50);
        iVar16 = *(int *)(iVar6 + 0x74);
        if (*(int *)(this + 0xa8) == 0x37a3 || *(int *)(this + 0xa8) == 0xe) {
          puVar10 = (undefined4 *)(iVar6 + 0x54);
        }
        else {
          puVar10 = (undefined4 *)(iVar6 + 0x50);
        }
        pMVar20 = (Matrix *)*puVar10;
        AEGeometry::getMatrix(*(AEGeometry **)(this + 0x120));
        fVar7 = (float)ParticleSystemManager::systemSetMatrix(iVar16,pMVar20);
        pVVar19 = (Vector *)0x0;
        if (Globals::options[0xf] != '\0') {
          pVVar19 = (Vector *)(this + 0x28);
        }
        FModSound::play(Globals::sound,0x14,pVVar19,(Vector *)0x0,fVar7);
        iVar6 = *(int *)(this + 0x50);
        if (*(int *)(this + 0xa8) == 0x37a3 || *(int *)(this + 0xa8) == 0xe) {
          piVar17 = (int *)(iVar6 + 0x54);
        }
        else {
          piVar17 = (int *)(iVar6 + 0x50);
        }
        ParticleSystemManager::enableSystemEmit
                  (*(ParticleSystemManager **)(iVar6 + 0x74),*piVar17,true);
        pEVar11 = operator_new(0x68);
        Explosion::Explosion(pEVar11,0);
        *(Explosion **)(this + 0x188) = pEVar11;
        Explosion::addFireStreaks(pEVar11);
        pEVar11 = *(Explosion **)(this + 0x188);
      }
      AEGeometry::getPosition();
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      Explosion::start(pEVar11,(Vector *)local_40,(Vector *)&local_4c);
      if (*(int *)pPVar21 == 0xe) {
        piVar17 = (int *)Level::getEnemies(*(Level **)(this + 0x50));
        if (*piVar17 != 0) {
          uVar18 = 0;
          do {
            iVar6 = Level::getEnemies(*(Level **)(this + 0x50));
            if (*(char *)(*(int *)(*(int *)(iVar6 + 4) + uVar18 * 4) + 0x3a) != '\0') {
              iVar6 = Level::getEnemies(*(Level **)(this + 0x50));
              Player::damage(*(Player **)(*(int *)(*(int *)(iVar6 + 4) + uVar18 * 4) + 4),9999999);
            }
            puVar12 = (uint *)Level::getEnemies(*(Level **)(this + 0x50));
            uVar18 = uVar18 + 1;
          } while (uVar18 < *puVar12);
        }
        if ((*(int *)pPVar21 == 0xe) && (*(char *)(*(int *)(this + 4) + 0x44) == '\0')) {
          *(int *)(Globals::status + 0x118) = *(int *)(Globals::status + 0x118) + 1;
          iVar6 = Achievements::hasMedal(Globals::achievements,0x27,1);
          if (iVar6 == 0) {
            fVar8 = (float)VectorSignedToFloat(*(undefined4 *)(Globals::status + 0x118),
                                               (byte)(in_fpscr >> 0x16) & 3);
            uVar9 = Achievements::getValue(Globals::achievements,0x27,1);
            fVar7 = (float)VectorSignedToFloat(uVar9,(byte)(in_fpscr >> 0x16) & 3);
            if ((int)(fVar8 / fVar7) < 2) {
              pPVar13 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x50));
              iVar6 = PlayerEgo::getHUD(pPVar13);
              VectorSignedToFloat(*(undefined4 *)(Globals::status + 0x118),
                                  (byte)(in_fpscr >> 0x16) & 3);
              uVar9 = Achievements::getValue(Globals::achievements,0x27,1);
              VectorSignedToFloat(uVar9,(byte)(in_fpscr >> 0x16) & 3);
              Hud::hudEventMedal(iVar6,0x27);
            }
          }
        }
      }
      goto LAB_0017f9ca;
    }
  }
  else {
LAB_0017f9ca:
    iVar6 = *(int *)(this + 0x84);
  }
  if (iVar6 == 3) {
    if (*(Explosion **)(this + 0x188) != (Explosion *)0x0) {
      Explosion::update(*(Explosion **)(this + 0x188),param_1,(TargetFollowCamera *)0x0);
    }
    if (*(int *)(this + 0xa8) != 0x37a3) {
      if (this[0x130] != (PlayerFixedObject)0x0) {
        fVar7 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        *(int *)(this + 0x17c) = *(int *)(this + 0x17c) + param_1;
        fVar7 = (float)AEGeometry::moveForward(*(AEGeometry **)(this + 0x120),fVar7);
        if (*(AEGeometry **)(this + 0x74) != (AEGeometry *)0x0) {
          AEGeometry::moveForward(*(AEGeometry **)(this + 0x74),fVar7);
        }
      }
      iVar6 = *(int *)(this + 4);
      pMVar20 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 0x120));
      AbyssEngine::AEMath::Matrix::operator=((Matrix *)(iVar6 + 4),pMVar20);
      AEGeometry::getPosition();
      AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x28),(Vector *)local_40);
      puVar12 = *(uint **)(this + 0x124);
      if ((puVar12 != (uint *)0x0) && (*puVar12 != 0)) {
        uVar18 = 0;
        do {
          piVar17 = *(int **)(puVar12[1] + uVar18 * 4);
          (**(code **)(*piVar17 + 4))
                    (piVar17,*(undefined4 *)(this + 0x28),*(undefined4 *)(this + 0x2c),
                     *(undefined4 *)(this + 0x30));
          puVar12 = *(uint **)(this + 0x124);
          uVar18 = uVar18 + 1;
        } while (uVar18 < *puVar12);
      }
    }
    this[0xfd] = (PlayerFixedObject)0x0;
    lVar25 = AbyssEngine::PaintCanvas::TransformGetTransform
                       (Globals::Canvas,*(uint *)(*(int *)(this + 0x120) + 0xc));
    AbyssEngine::Transform::Update(lVar25,SUB41(param_1,0));
    iVar6 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 0x120) + 0xc));
    if (*(char *)(iVar6 + 0xed) == '\0') {
      *(undefined4 *)(this + 0x84) = 4;
      iVar6 = *(int *)(this + 0x50);
      if (*(int *)(this + 0xa8) == 0x37a3 || *(int *)(this + 0xa8) == 0xe) {
        piVar17 = (int *)(iVar6 + 0x54);
      }
      else {
        piVar17 = (int *)(iVar6 + 0x50);
      }
      ParticleSystemManager::enableSystemEmit
                (*(ParticleSystemManager **)(iVar6 + 0x74),*piVar17,false);
      Explosion::reset(*(Explosion **)(this + 0x188));
      fVar7 = 6.0;
      if (*(int *)(this + 0xa8) == 0x37e7) {
        fVar7 = 8.0;
      }
      if (*(int *)(this + 0xa8) == 0x37a3) {
        fVar7 = 8.0;
      }
      Explosion::setScaling(fVar7);
      local_40[0] = 0;
      local_40[1] = 0;
      local_40[2] = 0;
      Explosion::start(*(Explosion **)(this + 0x188),(Vector *)(this + 0x28),(Vector *)local_40);
      *(undefined4 *)(this + 0x18c) = 0;
      *(undefined4 *)(this + 0x194) = 1;
      iVar6 = Level::getPlayer(*(Level **)(this + 0x50));
      if (iVar6 != 0) {
        pPVar13 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x50));
        iVar6 = PlayerEgo::getTargetFollowCamera(pPVar13);
        if (iVar6 != 0) {
          pPVar13 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x50));
          pTVar14 = (TargetFollowCamera *)PlayerEgo::getTargetFollowCamera(pPVar13);
          pVVar19 = (Vector *)TargetFollowCamera::getPosition(pTVar14);
          AbyssEngine::AEMath::operator-((AEMath *)local_40,(Vector *)(this + 0x28),pVVar19);
          fVar8 = (float)AbyssEngine::AEMath::VectorLength((Vector *)local_40);
          fVar7 = 30000.0;
          if ((int)((uint)(fVar8 < 30000.0) << 0x1f) < 0) {
            fVar7 = fVar8;
          }
          *(float *)(this + 0x198) = 1.0 - fVar7 / 30000.0;
          pPVar13 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x50));
          pTVar14 = (TargetFollowCamera *)PlayerEgo::getTargetFollowCamera(pPVar13);
          TargetFollowCamera::setRumblePercentage(pTVar14,extraout_s0,*(int *)(this + 0x198));
        }
      }
    }
    goto LAB_0017ff30;
  }
  if (iVar6 != 4) {
    if (iVar6 == 5) {
      puVar12 = (uint *)Player::getEnemies(*(Player **)(this + 4));
      if ((puVar12 != (uint *)0x0) && (*(undefined4 *)(this + 0x164) = 0, *puVar12 != 0)) {
        uVar18 = 0;
        do {
          iVar6 = Player::isActive(*(Player **)(puVar12[1] + uVar18 * 4));
          if (iVar6 == 1) {
            Player::getPosition();
            AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x8c),(Vector *)local_40);
            if ((((((int)((uint)(*(float *)(this + 0x28) - *(float *)(this + 0x8c) < 50000.0) <<
                         0x1f) < 0) &&
                  (-50000.0 < *(float *)(this + 0x28) - *(float *)(this + 0x8c))) &&
                 ((int)((uint)(*(float *)(this + 0x2c) - *(float *)(this + 0x90) < 50000.0) << 0x1f)
                  < 0)) &&
                ((-50000.0 < *(float *)(this + 0x2c) - *(float *)(this + 0x90) &&
                 ((int)((uint)(*(float *)(this + 0x30) - *(float *)(this + 0x94) < 50000.0) << 0x1f)
                  < 0)))) && (-50000.0 < *(float *)(this + 0x30) - *(float *)(this + 0x94))) {
              uVar9 = Player::getEnemy(*(Player **)(this + 4),uVar18);
              *(undefined4 *)(this + 0x164) = uVar9;
              Player::getPosition();
              AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x8c),(Vector *)local_40);
              *(undefined4 *)(this + 0x140) = *(undefined4 *)(this + 0x8c);
              *(undefined4 *)(this + 0x144) = *(undefined4 *)(this + 0x90);
              *(undefined4 *)(this + 0x148) = *(undefined4 *)(this + 0x94);
              break;
            }
          }
          uVar18 = uVar18 + 1;
        } while (uVar18 < *puVar12);
      }
      fVar7 = *(float *)(this + 0x140) - *(float *)(this + 0x28);
      *(float *)(this + 0x14c) = fVar7;
      fVar8 = *(float *)(this + 0x144) - *(float *)(this + 0x2c);
      *(float *)(this + 0x150) = fVar8;
      fVar24 = *(float *)(this + 0x148) - *(float *)(this + 0x30);
      *(float *)(this + 0x154) = fVar24;
      if ((int)((uint)(fVar7 < 50000.0) << 0x1f) < 0) {
        bVar23 = fVar7 < -50000.0;
        bVar22 = fVar7 == -50000.0;
        if (!bVar22 && !bVar23) {
          bVar23 = fVar24 < -50000.0;
          bVar22 = fVar24 == -50000.0;
          fVar7 = fVar24;
        }
        if (((!bVar22 && bVar23 == NAN(fVar7)) &&
            (fVar24 < 50000.0 && (fVar24 < 50000.0 && fVar8 < 50000.0))) && (-50000.0 < fVar8)) {
          *(undefined4 *)(this + 0x84) = 1;
          Player::setActive(*(Player **)(this + 4),true);
        }
      }
    }
    goto LAB_0017ff30;
  }
  *(int *)(this + 0x18c) = *(int *)(this + 0x18c) + param_1;
  if (*(Explosion **)(this + 0x188) != (Explosion *)0x0) {
    Explosion::update(*(Explosion **)(this + 0x188),param_1,(TargetFollowCamera *)0x0);
  }
  *(int *)(this + 0xd4) = *(int *)(this + 0xd4) + param_1;
  if (((this[0x48] == (PlayerFixedObject)0x0) ||
      (iVar6 = Player::isActive(*(Player **)(this + 4)), iVar6 != 1)) ||
     (*(AEGeometry **)(this + 0x74) == (AEGeometry *)0x0)) {
    if ((*(Explosion **)(this + 0x188) != (Explosion *)0x0) &&
       (iVar6 = Explosion::isPlaying(*(Explosion **)(this + 0x188)), iVar6 == 0)) {
      if (60000 < *(int *)(this + 0xd4)) goto LAB_0017fbd0;
      goto LAB_0017fbd8;
    }
  }
  else {
    fVar7 = (float)VectorSignedToFloat(param_1 >> 1,(byte)(in_fpscr >> 0x16) & 3);
    fVar7 = (float)VectorSignedToFloat((int)(fVar7 * 1.5258789e-05 * 6.2831855),
                                       (byte)(in_fpscr >> 0x16) & 3);
    AEGeometry::rotate(*(AEGeometry **)(this + 0x74),fVar7,extraout_s1,6.2831855);
    if (60000 < *(int *)(this + 0xd4)) {
LAB_0017fbd0:
      KIPlayer::setActive(SUB41(this,0));
LAB_0017fbd8:
      this[0xfd] = (PlayerFixedObject)0x1;
    }
  }
  if (-1 < *(int *)(this + 400)) {
    if (((*(int *)(this + 0x128) != 0) && (0x8c < *(int *)(this + 0x18c))) &&
       (0x7fffffff < *(uint *)(this + 0x19c))) {
      AEGeometry::getPosition();
      AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x28),(Vector *)local_40);
      puVar12 = *(uint **)(this + 0x128);
      if (*puVar12 != 0) {
        uVar18 = 0;
        do {
          piVar17 = *(int **)(puVar12[1] + uVar18 * 4);
          (**(code **)(*piVar17 + 4))
                    (piVar17,*(undefined4 *)(this + 0x28),*(undefined4 *)(this + 0x2c),
                     *(undefined4 *)(this + 0x30));
          puVar12 = *(uint **)(this + 0x128);
          uVar18 = uVar18 + 1;
        } while (uVar18 < *puVar12);
      }
      uVar15 = 0x8248;
      switch(*(undefined4 *)(this + 400)) {
      case 0:
        uVar9 = 0x824c;
        uVar15 = 0x824c;
        break;
      case 1:
        uVar9 = 0x8248;
        break;
      case 2:
        uVar9 = 0x8249;
        uVar15 = 0x8249;
        break;
      case 3:
        uVar9 = 0x824a;
        uVar15 = 0x824a;
        break;
      case 4:
        uVar9 = 0x824b;
        uVar15 = 0x824b;
        break;
      default:
        uVar15 = 0x824d;
        uVar9 = 0x824d;
      }
      *(undefined4 *)(this + 0x19c) = uVar9;
      AbyssEngine::PaintCanvas::MaterialCreate(Globals::Canvas,uVar15,local_40);
      AbyssEngine::PaintCanvas::MeshChangeMaterial
                (Globals::Canvas,*(uint *)(*(int *)(this + 0x120) + 0x1c),(ushort)local_40[0]);
    }
    iVar6 = Level::getPlayer(*(Level **)(this + 0x50));
    if (iVar6 != 0) {
      pPVar13 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x50));
      iVar6 = PlayerEgo::getTargetFollowCamera(pPVar13);
      if ((iVar6 != 0) && (0 < *(int *)(this + 0x194))) {
        iVar6 = *(int *)(this + 0x194) + param_1;
        if (2000 < iVar6) {
          iVar6 = 2000;
        }
        *(int *)(this + 0x194) = iVar6;
        pPVar13 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x50));
        pTVar14 = (TargetFollowCamera *)PlayerEgo::getTargetFollowCamera(pPVar13);
        fVar7 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x194),
                                           (byte)(in_fpscr >> 0x16) & 3);
        fVar7 = *(float *)(this + 0x198) * (fVar7 / -2000.0 + 1.0);
        TargetFollowCamera::setRumblePercentage(pTVar14,fVar7,(int)fVar7);
        if ((*(Explosion **)(this + 0x188) != (Explosion *)0x0) &&
           (iVar6 = Explosion::isPlaying(*(Explosion **)(this + 0x188)), iVar6 == 0)) {
          pPVar13 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x50));
          pTVar14 = (TargetFollowCamera *)PlayerEgo::getTargetFollowCamera(pPVar13);
          TargetFollowCamera::setRumblePercentage(pTVar14,extraout_s0_00,0);
          *(undefined4 *)(this + 0x194) = 0;
        }
      }
    }
  }
LAB_0017ff30:
  iVar6 = *(int *)(this + 4);
  *(undefined4 *)(iVar6 + 0x48) = *(undefined4 *)(this + 0x174);
  *(undefined4 *)(iVar6 + 0x4c) = *(undefined4 *)(this + 0x178);
  *(undefined4 *)(iVar6 + 0x50) = *(undefined4 *)(this + 0x17c);
  if (__stack_chk_guard != local_40[3]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerFixedObject::setExhaustVisible  @0x0017ffc8  (44 bytes)
/* PlayerFixedObject::setExhaustVisible(bool) */

void __thiscall PlayerFixedObject::setExhaustVisible(PlayerFixedObject *this,bool param_1)

{
  Transform *this_00;
  uint uVar1;
  
  if ((*(int *)(this + 8) != 0) &&
     (uVar1 = *(uint *)(*(int *)(this + 8) + 0x14), uVar1 != 0xffffffff)) {
    this_00 = (Transform *)AbyssEngine::PaintCanvas::TransformGetTransform(Globals::Canvas,uVar1);
    AbyssEngine::Transform::SetVisible(this_00,param_1);
    return;
  }
  return;
}

// ===== PlayerFixedObject::render  @0x0017fff8  (114 bytes)
/* PlayerFixedObject::render() */

void __thiscall PlayerFixedObject::render(PlayerFixedObject *this)

{
  int iVar1;
  Explosion *this_00;
  
  if ((*(AEGeometry **)(this + 0x74) != (AEGeometry *)0x0) &&
     (this[0x1b0] == (PlayerFixedObject)0x0)) {
    AEGeometry::render(*(AEGeometry **)(this + 0x74));
  }
  iVar1 = *(int *)(this + 0x84);
  if (iVar1 == 5) {
LAB_00180056:
    if (this[0x1b0] != (PlayerFixedObject)0x0) {
      return;
    }
    AEGeometry::render(*(AEGeometry **)(this + 8));
    return;
  }
  if (iVar1 == 4) {
    if (this[0x1b0] == (PlayerFixedObject)0x0) {
      AEGeometry::render(*(AEGeometry **)(this + 0x120));
    }
    this_00 = *(Explosion **)(this + 0x188);
    if (this_00 == (Explosion *)0x0) {
      return;
    }
  }
  else {
    if (iVar1 != 3) {
      iVar1 = Player::isActive(*(Player **)(this + 4));
      if (iVar1 != 1) {
        return;
      }
      goto LAB_00180056;
    }
    if (this[0x1b0] == (PlayerFixedObject)0x0) {
      AEGeometry::render(*(AEGeometry **)(this + 0x120));
    }
    this_00 = *(Explosion **)(this + 0x188);
  }
  Explosion::render(this_00);
  return;
}

// ===== PlayerFixedObject::collide  @0x00180068  (142 bytes)
/* PlayerFixedObject::collide(float, float, float) */

undefined4 __thiscall
PlayerFixedObject::collide(PlayerFixedObject *this,float param_1,float param_2,float param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  float extraout_s0;
  float extraout_s1;
  float extraout_s2;
  
  puVar1 = *(uint **)(this + 0x128);
  if (((puVar1 != (uint *)0x0) || (*(int *)(this + 0x84) != 4)) &&
     (this[0x88] != (PlayerFixedObject)0x0)) {
    if ((*(int *)(this + 0x84) == 4) && (puVar1 != (uint *)0x0)) {
      if (*puVar1 != 0) {
        uVar3 = 0;
        do {
          iVar2 = (**(code **)(**(int **)(puVar1[1] + uVar3 * 4) + 8))();
          if (iVar2 != 0) {
            return 1;
          }
          puVar1 = *(uint **)(this + 0x128);
          uVar3 = uVar3 + 1;
        } while (uVar3 < *puVar1);
      }
    }
    else {
      puVar1 = *(uint **)(this + 0x124);
      if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
        uVar3 = 0;
        do {
          iVar2 = (**(code **)(**(int **)(puVar1[1] + uVar3 * 4) + 8))(param_1,param_2,param_3);
          if (iVar2 == 1) {
            return 1;
          }
          puVar1 = *(uint **)(this + 0x124);
          uVar3 = uVar3 + 1;
          param_1 = extraout_s0;
          param_2 = extraout_s1;
          param_3 = extraout_s2;
        } while (uVar3 < *puVar1);
      }
    }
  }
  return 0;
}

// ===== PlayerFixedObject::getProjectionVector  @0x001800f6  (64 bytes)
/* PlayerFixedObject::getProjectionVector(AbyssEngine::AEMath::Vector const&) */

void __thiscall PlayerFixedObject::getProjectionVector(PlayerFixedObject *this,Vector *param_1)

{
  if (((*(int *)(param_1 + 0x128) == 0) || (*(int *)(param_1 + 0x84) != 4)) &&
     (*(int *)(param_1 + 0x124) == 0)) {
    *(undefined4 *)this = 0;
    *(undefined4 *)(this + 4) = 0;
    *(undefined4 *)(this + 8) = 0;
    return;
  }
  BoundingVolume::getProjectionVector((Vector *)this);
  return;
}

// ===== PlayerFixedObject::projectCollisionOnSurface  @0x00180136  (58 bytes)
/* PlayerFixedObject::projectCollisionOnSurface(AbyssEngine::AEMath::Vector const&) */

void PlayerFixedObject::projectCollisionOnSurface(Vector *param_1)

{
  int in_r1;
  Vector *in_r2;
  
  if ((*(Array **)(in_r1 + 0x128) != (Array *)0x0) && (*(int *)(in_r1 + 0x84) == 4)) {
    BoundingVolume::staticProjectCollisionOnSurface
              ((BoundingVolume *)param_1,in_r2,*(Array **)(in_r1 + 0x128));
    return;
  }
  if (*(Array **)(in_r1 + 0x124) != (Array *)0x0) {
    BoundingVolume::staticProjectCollisionOnSurface
              ((BoundingVolume *)param_1,in_r2,*(Array **)(in_r1 + 0x124));
    return;
  }
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

// ===== PlayerFixedObject::outerCollide  @0x00180170  (10 bytes)
/* PlayerFixedObject::outerCollide(AbyssEngine::AEMath::Vector) */

void PlayerFixedObject::outerCollide(int *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00180178. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x3c))();
  return;
}

// ===== PlayerFixedObject::outerCollide  @0x0018017a  (148 bytes)
/* PlayerFixedObject::outerCollide(float, float, float) */

undefined4 __thiscall
PlayerFixedObject::outerCollide(PlayerFixedObject *this,float param_1,float param_2,float param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  float extraout_s0;
  float extraout_s1;
  float extraout_s2;
  
  puVar1 = *(uint **)(this + 0x128);
  if (((puVar1 != (uint *)0x0) || (*(int *)(this + 0x84) != 4)) &&
     (this[0x88] != (PlayerFixedObject)0x0)) {
    if ((*(int *)(this + 0x84) == 4) && (puVar1 != (uint *)0x0)) {
      if (*puVar1 != 0) {
        uVar3 = 0;
        do {
          iVar2 = (**(code **)(**(int **)(puVar1[1] + uVar3 * 4) + 0xc))();
          if (iVar2 == 1) {
LAB_00180204:
            *(uint *)(this + 0x168) = uVar3;
            return 1;
          }
          puVar1 = *(uint **)(this + 0x128);
          uVar3 = uVar3 + 1;
        } while (uVar3 < *puVar1);
      }
    }
    else {
      puVar1 = *(uint **)(this + 0x124);
      if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
        uVar3 = 0;
        do {
          iVar2 = (**(code **)(**(int **)(puVar1[1] + uVar3 * 4) + 0xc))(param_1,param_2,param_3);
          if (iVar2 == 1) goto LAB_00180204;
          puVar1 = *(uint **)(this + 0x124);
          uVar3 = uVar3 + 1;
          param_1 = extraout_s0;
          param_2 = extraout_s1;
          param_3 = extraout_s2;
        } while (uVar3 < *puVar1);
      }
    }
  }
  return 0;
}

// ===== PlayerFixedObject::setDockingType  @0x0018020e  (6 bytes)
/* PlayerFixedObject::setDockingType(int) */

void __thiscall PlayerFixedObject::setDockingType(PlayerFixedObject *this,int param_1)

{
  *(int *)(this + 0x1a0) = param_1;
  return;
}

// ===== PlayerFixedObject::getDockingType  @0x00180214  (6 bytes)
/* PlayerFixedObject::getDockingType() */

undefined4 __thiscall PlayerFixedObject::getDockingType(PlayerFixedObject *this)

{
  return *(undefined4 *)(this + 0x1a0);
}

// ===== PlayerFixedObject::setTransportID  @0x0018021a  (6 bytes)
/* PlayerFixedObject::setTransportID(int) */

void __thiscall PlayerFixedObject::setTransportID(PlayerFixedObject *this,int param_1)

{
  *(int *)(this + 0x1a4) = param_1;
  return;
}

// ===== PlayerFixedObject::getTransportID  @0x00180220  (6 bytes)
/* PlayerFixedObject::getTransportID() */

undefined4 __thiscall PlayerFixedObject::getTransportID(PlayerFixedObject *this)

{
  return *(undefined4 *)(this + 0x1a4);
}

// ===== PlayerFixedObject::getName  @0x00180226  (16 bytes)
/* PlayerFixedObject::getName() */

void PlayerFixedObject::getName(void)

{
  String *in_r0;
  int in_r1;
  
  AbyssEngine::String::String(in_r0,(String *)(in_r1 + 0x1a8),false);
  return;
}

// ===== PlayerFixedObject::setName  @0x00180236  (8 bytes)
/* PlayerFixedObject::setName(AbyssEngine::String) */

void __thiscall PlayerFixedObject::setName(PlayerFixedObject *this,String *param_2)

{
  AbyssEngine::String::operator=((String *)(this + 0x1a8),param_2);
  return;
}

// ===== PlayerFixedObject::hideShip  @0x0018023e  (8 bytes)
/* PlayerFixedObject::hideShip() */

void __thiscall PlayerFixedObject::hideShip(PlayerFixedObject *this)

{
  this[0x1b0] = (PlayerFixedObject)0x1;
  return;
}

// ===== PlayerFixedObject::setDeadButSelectable  @0x00180248  (88 bytes)
/* PlayerFixedObject::setDeadButSelectable() */

void __thiscall PlayerFixedObject::setDeadButSelectable(PlayerFixedObject *this)

{
  void *pvVar1;
  longlong lVar2;
  
  this[0x130] = (PlayerFixedObject)0x0;
  Player::setHitpoints(*(Player **)(this + 4),1);
  Player::setVulnerable(*(Player **)(this + 4),false);
  LODManager::removeObject((LODManager *)**(undefined4 **)(this + 0x50),*(AEGeometry **)(this + 8));
  if (*(AEGeometry **)(this + 8) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 8));
    operator_delete(pvVar1);
  }
  *(int *)(this + 8) = *(int *)(this + 0x120);
  lVar2 = AbyssEngine::PaintCanvas::TransformGetTransform
                    (Globals::Canvas,*(uint *)(*(int *)(this + 0x120) + 0xc));
  AbyssEngine::Transform::SetAnimationRangeInTime(lVar2,*(longlong *)((int)lVar2 + 0xf8));
  return;
}

