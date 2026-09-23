// Class: PlayerCreature
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== PlayerCreature::PlayerCreature  @0x00141bd0  (216 bytes)
/* PlayerCreature::PlayerCreature(int, int, Player*, AEGeometry*, float, float, float) */

PlayerCreature * __thiscall
PlayerCreature::PlayerCreature
          (PlayerCreature *this,int param_1,int param_2,Player *param_3,AEGeometry *param_4,
          float param_5,float param_6,float param_7)

{
  undefined4 uVar1;
  int iVar2;
  uint in_fpscr;
  float fVar3;
  float in_stack_00000004;
  float in_stack_00000008;
  
  KIPlayer::KIPlayer((KIPlayer *)this,param_1,-1,param_3,param_4,in_stack_00000004,param_6,
                     in_stack_00000008,SUB41(in_stack_00000004,0));
  *(undefined ***)this = &PTR__PlayerCreature_00264298;
  *(undefined4 *)(this + 0x140) = 0x3f800000;
  *(undefined4 *)(this + 0x144) = 0;
  *(undefined4 *)(this + 0x148) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x14c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x150) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x154) = 0x3f800000;
  *(undefined4 *)(this + 0x158) = 0;
  *(undefined4 *)(this + 0x15c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x160) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x164) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined8 *)(this + 0x168) = 0x3f800000;
  *(undefined8 *)(this + 0x170) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0x178) = 0x3f800000;
  this[0x126] = (PlayerCreature)0x0;
  *(undefined4 *)(this + 0x128) = 0x3f800000;
  *(int *)(this + 0x13c) = param_2;
  *(undefined4 *)(this + 0x134) = *(undefined4 *)(this + 0x130);
  *(undefined4 *)(this + 300) = 0;
  *(undefined2 *)(this + 0x124) = 0;
  uVar1 = Player::getHitpoints(*(Player **)(this + 4));
  fVar3 = (float)VectorSignedToFloat(*(undefined4 *)(&DAT_002584c0 + param_1 * 4),
                                     (byte)(in_fpscr >> 0x16) & 3);
  iVar2 = (int)((fVar3 / 10.0) * 8000.0) + 8000;
  *(int *)(this + 0x130) = iVar2;
  *(int *)(this + 0x134) = iVar2;
  *(undefined4 *)(this + 0x138) = uVar1;
  reset(this);
  return this;
}

// ===== PlayerCreature::calmDown  @0x00141ce0  (20 bytes)
/* PlayerCreature::calmDown() */

void __thiscall PlayerCreature::calmDown(PlayerCreature *this)

{
  *(undefined4 *)(this + 0x134) = *(undefined4 *)(this + 0x130);
  *(undefined4 *)(this + 300) = 0;
  *(undefined2 *)(this + 0x124) = 0;
  return;
}

// ===== PlayerCreature::reset  @0x00141d00  (132 bytes)
/* PlayerCreature::reset() */

void __thiscall PlayerCreature::reset(PlayerCreature *this)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 local_50 [5];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  KIPlayer::reset((KIPlayer *)this);
  *(undefined4 *)(this + 0x84) = 0;
  KIPlayer::setActive(SUB41(this,0));
  *(undefined4 *)(this + 0x134) = *(undefined4 *)(this + 0x130);
  uVar1 = Player::getHitpoints(*(Player **)(this + 4));
  uStack_34 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uStack_30 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uStack_2c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  puVar2 = (undefined4 *)((uint)local_50 | 4);
  *(undefined4 *)(this + 0x138) = uVar1;
  local_50[0] = 0x3f800000;
  *puVar2 = 0;
  puVar2[1] = uStack_34;
  puVar2[2] = uStack_30;
  puVar2[3] = uStack_2c;
  local_3c = 0x3f800000;
  local_38 = 0;
  local_28 = 0x3f800000;
  uStack_20 = 0x3f8000003f800000;
  local_18 = 0x3f800000;
  AbyssEngine::AEMath::Matrix::operator=((Matrix *)(this + 0x140),(Matrix *)local_50);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerCreature::~PlayerCreature  @0x00141db0  (4 bytes)
/* PlayerCreature::~PlayerCreature() */

void __thiscall PlayerCreature::~PlayerCreature(PlayerCreature *this)

{
  KIPlayer::~KIPlayer((KIPlayer *)this);
  return;
}

// ===== PlayerCreature::~PlayerCreature  @0x00141db4  (16 bytes)
/* PlayerCreature::~PlayerCreature() */

void __thiscall PlayerCreature::~PlayerCreature(PlayerCreature *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)KIPlayer::~KIPlayer((KIPlayer *)this);
  operator_delete(pvVar1);
  return;
}

// ===== PlayerCreature::rage  @0x00141dc4  (74 bytes)
/* PlayerCreature::rage(int) */

void __thiscall PlayerCreature::rage(PlayerCreature *this,int param_1)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  
  fVar1 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  this[0x124] = (PlayerCreature)0x1;
  this[0x125] = (PlayerCreature)0x1;
  *(undefined4 *)(this + 300) = 0;
  fVar2 = (float)VectorSignedToFloat(*(undefined4 *)(&DAT_002584c0 + *(int *)(this + 0xa8) * 4),
                                     (byte)(in_fpscr >> 0x16) & 3);
  *(float *)(this + 0x128) = (fVar1 / -100.0 + 1.0) * (fVar2 + 1.0);
  return;
}

// ===== PlayerCreature::isHooked  @0x00141e18  (6 bytes)
/* PlayerCreature::isHooked() */

PlayerCreature __thiscall PlayerCreature::isHooked(PlayerCreature *this)

{
  return this[0x125];
}

// ===== PlayerCreature::isCaught  @0x00141e1e  (6 bytes)
/* PlayerCreature::isCaught() */

PlayerCreature __thiscall PlayerCreature::isCaught(PlayerCreature *this)

{
  return this[0x126];
}

// ===== PlayerCreature::hook  @0x00141e24  (72 bytes)
/* PlayerCreature::hook(int) */

void __thiscall PlayerCreature::hook(PlayerCreature *this,int param_1)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  
  fVar1 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  *(undefined2 *)(this + 0x124) = 0x101;
  *(undefined4 *)(this + 300) = 0;
  fVar2 = (float)VectorSignedToFloat(*(undefined4 *)(&DAT_002584c0 + *(int *)(this + 0xa8) * 4),
                                     (byte)(in_fpscr >> 0x16) & 3);
  *(float *)(this + 0x128) = (fVar1 / -100.0 + 1.0) * (fVar2 + 1.0);
  return;
}

// ===== PlayerCreature::unhook  @0x00141e74  (24 bytes)
/* PlayerCreature::unhook() */

void __thiscall PlayerCreature::unhook(PlayerCreature *this)

{
  this[0x126] = (PlayerCreature)0x0;
  *(undefined4 *)(this + 0x134) = *(undefined4 *)(this + 0x130);
  *(undefined4 *)(this + 300) = 0;
  *(undefined2 *)(this + 0x124) = 0;
  return;
}

// ===== PlayerCreature::update  @0x00141e8c  (564 bytes)
/* PlayerCreature::update(int) */

void __thiscall PlayerCreature::update(PlayerCreature *this,int param_1)

{
  int iVar1;
  undefined4 uVar2;
  Matrix *pMVar3;
  int iVar4;
  AEGeometry *this_00;
  uint in_fpscr;
  float fVar5;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s1;
  float fVar6;
  float fVar7;
  undefined4 local_7c;
  undefined4 uStack_78;
  undefined4 local_74;
  undefined4 uStack_70;
  undefined4 local_6c;
  undefined4 uStack_68;
  int local_34;
  
  local_34 = __stack_chk_guard;
  *(int *)(this + 0x120) = param_1;
  iVar4 = *(int *)(this + 0x138);
  iVar1 = Player::getHitpoints(*(Player **)(this + 4));
  if ((iVar1 < iVar4) && (*(int *)(this + 0x84) != 4)) {
    this[0x124] = (PlayerCreature)0x1;
  }
  uVar2 = Player::getHitpoints(*(Player **)(this + 4));
  *(undefined4 *)(this + 0x138) = uVar2;
  if (this[0x124] != (PlayerCreature)0x0) {
    fVar5 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    fVar6 = fVar5 * 0.0007 + *(float *)(this + 0x128);
    *(float *)(this + 0x128) = fVar6;
    iVar1 = *(int *)(this + 300) + param_1;
    *(int *)(this + 300) = iVar1;
    iVar4 = *(int *)(this + 0x134) - param_1;
    param_1 = (int)(fVar5 * fVar6);
    *(int *)(this + 0x134) = iVar4;
    if (iVar1 < 4000) {
      this_00 = *(AEGeometry **)(this + 8);
      pMVar3 = (Matrix *)AEGeometry::getMatrix(this_00);
      AbyssEngine::AEMath::MatrixMultiply((AEMath *)&uStack_70,pMVar3,this + 0x140);
      AEGeometry::setMatrix(this_00);
    }
    else {
      iVar1 = param_1 >> 1;
      fVar6 = (float)VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x16) & 3);
      uVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,iVar1);
      fVar7 = (float)VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
      uVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,iVar1);
      fVar5 = (float)VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
      fVar7 = (fVar6 * -0.5 + fVar7) * 0.00024414062;
      fVar5 = (fVar6 * -0.5 + fVar5) * 0.00024414062;
      AbyssEngine::AEMath::MatrixSetRotation
                ((Matrix *)&uStack_70,(fVar5 + fVar5) * 3.1415927,extraout_s1,
                 (fVar7 + fVar7) * 3.1415927);
      *(undefined4 *)(this + 300) = 0;
    }
    if (*(int *)(this + 0x134) < 1) {
      if (this[0x125] == (PlayerCreature)0x0) {
        *(undefined4 *)(this + 0x134) = *(undefined4 *)(this + 0x130);
        *(undefined4 *)(this + 300) = 0;
        *(undefined2 *)(this + 0x124) = 0;
      }
      else {
        this[0x126] = (PlayerCreature)0x1;
        this[0x124] = (PlayerCreature)0x0;
      }
    }
  }
  iVar1 = Player::getHitpoints(*(Player **)(this + 4));
  if ((iVar1 < 1) && (1 < *(int *)(this + 0x84) - 3U)) {
    *(undefined4 *)(this + 0x84) = 3;
    FModSound::play(Globals::sound,0x16,(Vector *)0x0,(Vector *)0x0,extraout_s0);
    Player::setActive(*(Player **)(this + 4),false);
    iVar1 = Level::getPlayer(*(Level **)(this + 0x50));
    fVar5 = extraout_s0_00;
    if (*(PlayerCreature **)(*(int *)(iVar1 + 0x14) + 0x1c) == this) {
      iVar1 = Level::getPlayer(*(Level **)(this + 0x50));
      *(undefined4 *)(*(int *)(iVar1 + 0x14) + 0x1c) = 0;
      fVar5 = extraout_s0_01;
    }
    uStack_70 = *(undefined4 *)(this + 0x54);
    local_6c = *(undefined4 *)(this + 0x58);
    uStack_68 = *(undefined4 *)(this + 0x5c);
    local_7c = 0;
    uStack_78 = 0;
    local_74 = 0;
    ParticleSystemManager::emitManual
              (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x74),
               *(int *)(*(int *)(this + 0x50) + 0x34),(Vector *)&uStack_70,0,(Vector *)&local_7c,
               fVar5);
  }
  if (*(int *)(this + 0x84) == 3) {
    *(undefined4 *)(this + 0x84) = 4;
  }
  else if ((*(int *)(this + 0x84) == 0) && (this[0x126] == (PlayerCreature)0x0)) {
    fVar5 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    AEGeometry::moveForward(*(AEGeometry **)(this + 8),fVar5);
  }
  iVar1 = *(int *)(this + 4);
  pMVar3 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
  AbyssEngine::AEMath::Matrix::operator=((Matrix *)(iVar1 + 4),pMVar3);
  if (__stack_chk_guard != local_34) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerCreature::render  @0x001420dc  (36 bytes)
/* PlayerCreature::render() */

void __thiscall PlayerCreature::render(PlayerCreature *this)

{
  if (*(AEGeometry **)(this + 0x74) != (AEGeometry *)0x0) {
    AEGeometry::render(*(AEGeometry **)(this + 0x74));
  }
  if (1 < *(int *)(this + 0x84) - 3U) {
    (*(code *)&LAB_0006bd38)(this);
    return;
  }
  return;
}

// ===== PlayerCreature::collide  @0x00142100  (4 bytes)
/* PlayerCreature::collide(float, float, float) */

undefined4 PlayerCreature::collide(float param_1,float param_2,float param_3)

{
  return 0;
}

// ===== PlayerCreature::outerCollide  @0x00142104  (4 bytes)
/* PlayerCreature::outerCollide(float, float, float) */

undefined4 PlayerCreature::outerCollide(float param_1,float param_2,float param_3)

{
  return 0;
}

// ===== PlayerCreature::getWeight  @0x00142108  (14 bytes)
/* PlayerCreature::getWeight() */

undefined4 __thiscall PlayerCreature::getWeight(PlayerCreature *this)

{
  return *(undefined4 *)(&DAT_002584c0 + *(int *)(this + 0xa8) * 4);
}

// ===== PlayerCreature::getItemIndex  @0x0014211c  (6 bytes)
/* PlayerCreature::getItemIndex() */

undefined4 __thiscall PlayerCreature::getItemIndex(PlayerCreature *this)

{
  return *(undefined4 *)(this + 0x13c);
}

// ===== PlayerCreature::getMaxEndurance  @0x00142122  (6 bytes)
/* PlayerCreature::getMaxEndurance() */

undefined4 __thiscall PlayerCreature::getMaxEndurance(PlayerCreature *this)

{
  return *(undefined4 *)(this + 0x130);
}

// ===== PlayerCreature::getEndurance  @0x00142128  (6 bytes)
/* PlayerCreature::getEndurance() */

undefined4 __thiscall PlayerCreature::getEndurance(PlayerCreature *this)

{
  return *(undefined4 *)(this + 0x134);
}

