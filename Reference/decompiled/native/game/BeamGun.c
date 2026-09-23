// Class: BeamGun
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== BeamGun::BeamGun  @0x001a69a8  (196 bytes)
/* BeamGun::BeamGun(int, Gun*, int, Level*) */

BeamGun * __thiscall
BeamGun::BeamGun(BeamGun *this,int param_1,Gun *param_2,int param_3,Level *param_4)

{
  AEGeometry *pAVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  
  iVar4 = param_3 + -9;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined ***)this = &PTR__BeamGun_00264a04;
  if (param_3 == 0xe4) {
    iVar4 = 2;
  }
  *(Gun **)(this + 8) = param_2;
  *(Level **)(this + 0xc) = param_4;
  *(int *)(this + 0x10) = param_1;
  *(int *)(this + 0x14) = iVar4;
  pAVar1 = operator_new(0xc0);
  uVar3 = (short)iVar4 + 0x3795;
  if (param_3 == 0xe4) {
    uVar3 = 0x4a92;
  }
  AEGeometry::AEGeometry(pAVar1,uVar3,Globals::Canvas,false);
  *(AEGeometry **)(this + 0x18) = pAVar1;
  iVar4 = Gun::isPlayerGun(param_2);
  if ((iVar4 == 1) && (iVar4 = *(int *)(&DAT_0025d020 + *(int *)(param_2 + 0x58) * 4), -1 < iVar4))
  {
    iVar2 = *(int *)(param_2 + 0x5c);
    pAVar1 = (AEGeometry *)0x0;
    this[0x20] = (BeamGun)(iVar2 != 0xb);
    if (iVar2 != 0xb) {
      pAVar1 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar1,(ushort)iVar4,Globals::Canvas,false);
    }
  }
  else {
    pAVar1 = (AEGeometry *)0x0;
    this[0x20] = (BeamGun)0x0;
  }
  *(AEGeometry **)(this + 0x1c) = pAVar1;
  this[0x21] = (BeamGun)0x0;
  return this;
}

// ===== BeamGun::~BeamGun  @0x001a6a94  (50 bytes)
/* BeamGun::~BeamGun() */

BeamGun * __thiscall BeamGun::~BeamGun(BeamGun *this)

{
  void *pvVar1;
  
  *(undefined ***)this = &PTR__BeamGun_00264a04;
  if (*(AEGeometry **)(this + 0x18) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x18));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x18) = 0;
  if (*(AEGeometry **)(this + 0x1c) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x1c));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x1c) = 0;
  return this;
}

// ===== BeamGun::~BeamGun  @0x001a6acc  (16 bytes)
/* BeamGun::~BeamGun() */

void __thiscall BeamGun::~BeamGun(BeamGun *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~BeamGun(this);
  operator_delete(pvVar1);
  return;
}

// ===== BeamGun::render  @0x001a6adc  (42 bytes)
/* BeamGun::render() */

void __thiscall BeamGun::render(BeamGun *this)

{
  if (((*(char *)(*(int *)(this + 8) + 0x4c) != '\0') &&
      (AEGeometry::render(*(AEGeometry **)(this + 0x18)), this[0x21] != (BeamGun)0x0)) &&
     (*(AEGeometry **)(this + 0x1c) != (AEGeometry *)0x0)) {
    AEGeometry::render(*(AEGeometry **)(this + 0x1c));
    return;
  }
  return;
}

// ===== BeamGun::update  @0x001a6b04  (612 bytes)
/* BeamGun::update(int) */

void __thiscall BeamGun::update(BeamGun *this,int param_1)

{
  undefined4 uVar1;
  int iVar2;
  Matrix *pMVar3;
  Matrix *pMVar4;
  int *piVar5;
  AEGeometry *this_00;
  uint in_fpscr;
  float fVar6;
  float extraout_s1;
  float extraout_s2;
  longlong lVar7;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  AEMath aAStack_88 [12];
  undefined4 local_7c;
  undefined4 uStack_78;
  undefined4 local_74;
  undefined8 local_40;
  float local_38;
  Vector aVStack_30 [12];
  int local_24;
  
  local_24 = __stack_chk_guard;
  Gun::update(*(Gun **)(this + 8),param_1);
  if ((*(ushort *)(*(int *)(this + 8) + 0x4c) & 0xff) == 0) {
    if (__stack_chk_guard == local_24) {
      AEGeometry::setVisible(*(AEGeometry **)(this + 0x18),false);
      return;
    }
  }
  else {
    if (0xff < *(ushort *)(*(int *)(this + 8) + 0x4c)) {
      uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(*(int *)(this + 0x18) + 0xc));
      AbyssEngine::Transform::SetAnimationState(uVar1,3,0);
      uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(*(int *)(this + 0x18) + 0xc));
      AbyssEngine::Transform::SetAnimationState(uVar1,1,0);
      *(undefined1 *)(*(int *)(this + 8) + 0x4d) = 0;
    }
    lVar7 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 0x18) + 0xc));
    AbyssEngine::Transform::Update(lVar7,SUB41(param_1,0));
    fVar6 = (float)VectorSignedToFloat(*(undefined4 *)(*(int *)(this + 8) + 0x8c),
                                       (byte)(in_fpscr >> 0x16) & 3);
    AEGeometry::setScaling(*(AEGeometry **)(this + 0x18),fVar6,extraout_s1,extraout_s2);
    local_7c = 0;
    uStack_78 = 0x3f800000;
    local_74 = 0;
    AEGeometry::setDirection
              (*(AEGeometry **)(this + 0x18),(Vector *)(*(int *)(this + 8) + 0x90),
               (Vector *)&local_7c);
    Level::getPlayer(*(Level **)(this + 0xc));
    PlayerEgo::getPosition();
    local_7c = 0;
    uStack_78 = 0;
    local_74 = 0;
    iVar2 = AbyssEngine::AEMath::operator!=
                      ((Vector *)(*(int *)(this + 8) + 0x7c),(Vector *)&local_7c);
    if (iVar2 == 1) {
      iVar2 = Level::getPlayer(*(Level **)(this + 0xc));
      pMVar3 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(iVar2 + 8));
      iVar2 = Level::getPlayer(*(Level **)(this + 0xc));
      pMVar4 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(iVar2 + 4));
      AbyssEngine::AEMath::operator*((AEMath *)&local_7c,pMVar3,pMVar4);
      local_94 = 0;
      local_90 = 0;
      local_8c = 0xc2c80000;
      AbyssEngine::AEMath::operator+
                (aAStack_88,(Vector *)(*(int *)(this + 8) + 0x7c),(Vector *)&local_94);
      AbyssEngine::AEMath::MatrixRotateVector
                ((AEMath *)&local_40,(AEMath *)&local_7c,(Vector *)aAStack_88);
      AbyssEngine::AEMath::Vector::operator+=(aVStack_30,(Vector *)&local_40);
    }
    AEGeometry::setPosition(*(Vector **)(this + 0x18));
    AEGeometry::setVisible(*(AEGeometry **)(this + 0x18),true);
    if (this[0x20] != (BeamGun)0x0) {
      if (*(char *)(*(int *)(this + 8) + 0xa9) == '\0') {
        uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                          (Globals::Canvas,*(uint *)(*(int *)(this + 0x1c) + 0xc));
        AbyssEngine::Transform::SetAnimationState(uVar1,0,0);
        uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                          (Globals::Canvas,*(uint *)(*(int *)(this + 0x1c) + 0xc));
        AbyssEngine::Transform::SetAnimationState(uVar1,3,0);
        uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                          (Globals::Canvas,*(uint *)(*(int *)(this + 0x1c) + 0xc));
        AbyssEngine::Transform::SetAnimationState(uVar1,1,0);
      }
      else {
        piVar5 = (int *)Level::getPlayer(*(Level **)(this + 0xc));
        PlayerEgo::getPosition();
        local_40 = *(undefined8 *)(*(int *)(this + 8) + 0x7c);
        local_38 = *(float *)(*(int *)(this + 8) + 0x84) + -100.0;
        AbyssEngine::AEMath::MatrixRotateVector
                  (aAStack_88,(Matrix *)(*piVar5 + 4),(Vector *)&local_40);
        AbyssEngine::AEMath::Vector::operator+=((Vector *)&local_7c,(Vector *)aAStack_88);
        AEGeometry::setPosition(*(Vector **)(this + 0x1c));
        lVar7 = AbyssEngine::PaintCanvas::TransformGetTransform
                          (Globals::Canvas,*(uint *)(*(int *)(this + 0x1c) + 0xc));
        AbyssEngine::Transform::Update(lVar7,SUB41(param_1,0));
        this_00 = *(AEGeometry **)(this + 0x1c);
        AbyssEngine::AEMath::MatrixGetDir(aAStack_88,(Matrix *)(*piVar5 + 4));
        local_94 = 0;
        local_90 = 0x3f800000;
        local_8c = 0;
        AEGeometry::setDirection(this_00,(Vector *)aAStack_88,(Vector *)&local_94);
      }
    }
    this[0x21] = *(BeamGun *)(*(int *)(this + 8) + 0xa9);
    if (__stack_chk_guard == local_24) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== BeamGun::setEnemies  @0x001a6d88  (8 bytes)
/* BeamGun::setEnemies(Array<Player*>*) */

void BeamGun::setEnemies(Array *param_1)

{
  Array *in_r1;
  
  Gun::setEnemies(*(Gun **)(param_1 + 8),in_r1);
  return;
}

// ===== BeamGun::setEnemy  @0x001a6d8e  (8 bytes)
/* BeamGun::setEnemy(Player*) */

void BeamGun::setEnemy(Player *param_1)

{
  Player *in_r1;
  
  Gun::setEnemy(*(Gun **)(param_1 + 8),in_r1);
  return;
}

// ===== BeamGun::translate  @0x001a6d94  (2 bytes)
/* BeamGun::translate(AbyssEngine::AEMath::Vector const&) */

Vector * BeamGun::translate(Vector *param_1)

{
  return param_1;
}

// ===== BeamGun::replaceGun  @0x001a6d96  (2 bytes)
/* BeamGun::replaceGun(unsigned int, int) */

uint BeamGun::replaceGun(uint param_1,int param_2)

{
  return param_1;
}

