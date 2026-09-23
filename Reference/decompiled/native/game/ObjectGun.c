// Class: ObjectGun
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== ObjectGun::ObjectGun  @0x0018c020  (516 bytes)
/* ObjectGun::ObjectGun(int, Gun*, int, unsigned int, Level*) */

ObjectGun * __thiscall
ObjectGun::ObjectGun
          (ObjectGun *this,int param_1,Gun *param_2,int param_3,uint param_4,Level *param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  Array *pAVar5;
  undefined4 *puVar6;
  void *pvVar7;
  Explosion *this_00;
  AEGeometry *this_01;
  ObjectGun OVar8;
  uint *puVar9;
  uint uVar10;
  
  uVar1 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined ***)this = &PTR__ObjectGun_002647a8;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 100) = uVar1;
  *(undefined4 *)(this + 0x68) = uVar2;
  *(undefined4 *)(this + 0x6c) = uVar3;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x54) = uVar1;
  *(undefined4 *)(this + 0x58) = uVar2;
  *(undefined4 *)(this + 0x5c) = uVar3;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x74) = 0x3f800000;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x7c) = uVar1;
  *(undefined4 *)(this + 0x80) = uVar2;
  *(undefined4 *)(this + 0x84) = uVar3;
  *(undefined4 *)(this + 0x88) = 0x3f800000;
  *(undefined4 *)(this + 0x8c) = 0;
  *(undefined4 *)(this + 0x90) = uVar1;
  *(undefined4 *)(this + 0x94) = uVar2;
  *(undefined4 *)(this + 0x98) = uVar3;
  *(undefined8 *)(this + 0x9c) = 0x3f800000;
  *(undefined8 *)(this + 0xa4) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0xac) = 0x3f800000;
  this[0x24] = (ObjectGun)0x0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(Gun **)(this + 8) = param_2;
  *(Level **)(this + 0xc) = param_5;
  *(undefined4 *)(this + 4) = 0xffffffff;
  *(undefined4 *)(this + 0x14) = 0xffffffff;
  AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,(uint *)(this + 0x10));
  *(int *)(this + 0x28) = param_3;
  OVar8 = (ObjectGun)0x0;
  AbyssEngine::PaintCanvas::TransformAddMesh
            (Globals::Canvas,*(uint *)(this + 0x10),(ushort)param_3,false);
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x3c) = 0x3f8000003f800000;
  *(undefined8 *)(this + 0x44) = 0x3f800000;
  iVar4 = *(int *)(param_2 + 0x5c);
  if (iVar4 - 1U < 8) {
    OVar8 = (ObjectGun)((byte)(0x85 >> (iVar4 - 1U & 0xff)) & 1);
  }
  this[0x4c] = OVar8;
  if (Globals::iPad == '\0') {
LAB_0018c114:
    if (iVar4 == 0x19) {
LAB_0018c12c:
      pAVar5 = operator_new(0xc);
      puVar6 = operator_new__(4);
      *(undefined4 **)(pAVar5 + 4) = puVar6;
      *(undefined4 *)(pAVar5 + 8) = 1;
      *puVar6 = 0;
      *(undefined4 *)pAVar5 = 0;
      *(Array **)(this + 0x2c) = pAVar5;
      ArraySetLength<Explosion*>(*(uint *)(param_2 + 8),pAVar5);
      puVar9 = *(uint **)(this + 0x2c);
      pvVar7 = operator_new__(*puVar9);
      *(void **)(this + 0x30) = pvVar7;
      if (*puVar9 != 0) {
        uVar10 = 0;
        do {
          this_00 = operator_new(0x68);
          iVar4 = 10;
          if (*(int *)(param_2 + 0x58) == 0xb1) {
            iVar4 = 9;
          }
          if (*(int *)(param_2 + 0x58) == 0xb0) {
            iVar4 = 8;
          }
          Explosion::Explosion(this_00,iVar4);
          *(Explosion **)(*(int *)(*(int *)(this + 0x2c) + 4) + uVar10 * 4) = this_00;
          Explosion::setWeaponIndex
                    (*(Explosion **)(*(int *)(*(int *)(this + 0x2c) + 4) + uVar10 * 4),
                     *(int *)(param_2 + 0x58));
          *(undefined1 *)(*(int *)(this + 0x30) + uVar10) = 1;
          uVar10 = uVar10 + 1;
        } while (uVar10 < **(uint **)(this + 0x2c));
      }
    }
    else if (iVar4 == 0xb) {
LAB_0018c11c:
      *(undefined4 *)(this + 0x3c) = 0x3f333333;
      *(undefined4 *)(this + 0x40) = 0x3f333333;
      *(undefined4 *)(this + 0x44) = 0x3f333333;
    }
  }
  else {
    if (7 < iVar4) {
      if (iVar4 != 0x19) {
        if (iVar4 != 0xb) {
          if (iVar4 == 8) goto LAB_0018c106;
          goto LAB_0018c1ae;
        }
        goto LAB_0018c11c;
      }
      goto LAB_0018c12c;
    }
    if ((iVar4 == 1) || (iVar4 == 3)) {
LAB_0018c106:
      *(undefined4 *)(this + 0x3c) = 0x3f19999a;
      *(undefined4 *)(this + 0x40) = 0x3f19999a;
      *(undefined4 *)(this + 0x44) = 0x3f19999a;
      goto LAB_0018c114;
    }
  }
LAB_0018c1ae:
  if (param_2[0xa8] == (Gun)0x0) {
    iVar4 = Gun::isPlayerGun(param_2);
    if ((iVar4 != 1) || (*(int *)(&DAT_00259ab8 + *(int *)(param_2 + 0x58) * 4) < 0)) {
      this_01 = (AEGeometry *)0x0;
      this[0x1c] = (ObjectGun)0x0;
      goto LAB_0018c214;
    }
    iVar4 = *(int *)(param_2 + 0x5c);
    this_01 = (AEGeometry *)0x0;
    this[0x1c] = (ObjectGun)(iVar4 != 0xb);
    if (iVar4 == 0xb) goto LAB_0018c214;
  }
  else {
    this[0x1c] = (ObjectGun)0x1;
  }
  this_01 = operator_new(0xc0);
  AEGeometry::AEGeometry
            (this_01,*(ushort *)(&DAT_00259ab8 + *(int *)(param_2 + 0x58) * 4),Globals::Canvas,false
            );
LAB_0018c214:
  *(AEGeometry **)(this + 0x18) = this_01;
  this[0x1d] = (ObjectGun)0x0;
  *(undefined4 *)(this + 0x34) = 0;
  return this;
}

// ===== ObjectGun::~ObjectGun  @0x0018c280  (78 bytes)
/* ObjectGun::~ObjectGun() */

ObjectGun * __thiscall ObjectGun::~ObjectGun(ObjectGun *this)

{
  void *pvVar1;
  
  *(undefined ***)this = &PTR__ObjectGun_002647a8;
  if (*(AEGeometry **)(this + 0x18) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x18));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x18) = 0;
  if (*(Array **)(this + 0x2c) != (Array *)0x0) {
    ArrayReleaseClasses<Explosion*>(*(Array **)(this + 0x2c));
    pvVar1 = *(void **)(this + 0x2c);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
    *(undefined4 *)(this + 0x2c) = 0;
  }
  if (*(void **)(this + 0x30) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x30));
  }
  *(undefined4 *)(this + 0x30) = 0;
  return this;
}

// ===== ObjectGun::~ObjectGun  @0x0018c2d4  (16 bytes)
/* ObjectGun::~ObjectGun() */

void __thiscall ObjectGun::~ObjectGun(ObjectGun *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~ObjectGun(this);
  operator_delete(pvVar1);
  return;
}

// ===== ObjectGun::setEnemies  @0x0018c2e4  (6 bytes)
/* ObjectGun::setEnemies(Array<Player*>*) */

void ObjectGun::setEnemies(Array *param_1)

{
  Array *in_r1;
  
  Gun::setEnemies(*(Gun **)(param_1 + 8),in_r1);
  return;
}

// ===== ObjectGun::setEnemy  @0x0018c2ea  (2 bytes)
/* ObjectGun::setEnemy(Player*) */

Player * ObjectGun::setEnemy(Player *param_1)

{
  return param_1;
}

// ===== ObjectGun::update  @0x0018c2ec  (1056 bytes)
/* ObjectGun::update(int) */

void __thiscall ObjectGun::update(ObjectGun *this,int param_1)

{
  PaintCanvas *this_00;
  uint uVar1;
  int iVar2;
  AEGeometry *pAVar3;
  int *piVar4;
  undefined4 uVar5;
  Matrix *pMVar6;
  Matrix *pMVar7;
  undefined4 *puVar8;
  int *piVar9;
  float *pfVar10;
  int iVar11;
  float fVar12;
  float fVar13;
  AEMath aAStack_d8 [12];
  float local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 local_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined8 local_80;
  float local_78;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 local_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  Vector aVStack_34 [12];
  int local_28;
  
  local_28 = __stack_chk_guard;
  uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform(Globals::Canvas,*(uint *)(this + 0x10));
  AbyssEngine::Transform::Update((ulonglong)uVar1,SUB41(param_1,0));
  *(int *)(this + 0x34) = param_1;
  Gun::update(*(Gun **)(this + 8),param_1);
  if (this[0x1c] == (ObjectGun)0x0) {
    iVar2 = Gun::isPlayerGun(*(Gun **)(this + 8));
    if ((((iVar2 == 0) && (*(Player **)(*(int *)(this + 8) + 4) != (Player *)0x0)) &&
        (iVar2 = Player::getKIPlayer(*(Player **)(*(int *)(this + 8) + 4)), iVar2 != 0)) &&
       (iVar2 = Player::getKIPlayer(*(Player **)(*(int *)(this + 8) + 4)),
       *(char *)(iVar2 + 0x3b) != '\0')) {
      this[0x1c] = (ObjectGun)0x1;
      pAVar3 = operator_new(0xc0);
      AEGeometry::AEGeometry
                (pAVar3,*(ushort *)(&DAT_00259ab8 + *(int *)(*(int *)(this + 8) + 0x58) * 4),
                 Globals::Canvas,false);
      *(AEGeometry **)(this + 0x18) = pAVar3;
    }
    if (this[0x1c] == (ObjectGun)0x0) goto LAB_0018c614;
  }
  if (*(char *)(*(int *)(this + 8) + 0xa9) == '\0') {
    uVar5 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 0x18) + 0xc));
    AbyssEngine::Transform::SetAnimationState(uVar5,0,0);
    uVar5 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 0x18) + 0xc));
    AbyssEngine::Transform::SetAnimationState(uVar5,3,0);
    uVar5 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 0x18) + 0xc));
    AbyssEngine::Transform::SetAnimationState(uVar5,1,0);
  }
  else {
    piVar4 = (int *)Level::getPlayer(*(Level **)(this + 0xc));
    iVar2 = Gun::isPlayerGun(*(Gun **)(this + 8));
    if (iVar2 == 1) {
      PlayerEgo::getPosition();
    }
    else {
      Player::getPosition();
    }
    iVar2 = Gun::isPlayerGun(*(Gun **)(this + 8));
    iVar11 = *(int *)(this + 8);
    piVar9 = piVar4;
    if (iVar2 != 1) {
      piVar9 = (int *)(iVar11 + 4);
    }
    iVar2 = *piVar9;
    local_70 = *(undefined4 *)(iVar2 + 4);
    uStack_6c = *(undefined4 *)(iVar2 + 8);
    local_68 = *(undefined4 *)(iVar2 + 0xc);
    uStack_64 = *(undefined4 *)(iVar2 + 0x10);
    uStack_60 = *(undefined4 *)(iVar2 + 0x14);
    local_5c = *(undefined4 *)(iVar2 + 0x18);
    uStack_58 = *(undefined4 *)(iVar2 + 0x1c);
    uStack_54 = *(undefined4 *)(iVar2 + 0x20);
    uStack_50 = *(undefined4 *)(iVar2 + 0x24);
    uStack_4c = *(undefined4 *)(iVar2 + 0x28);
    local_48 = *(undefined4 *)(iVar2 + 0x2c);
    uStack_44 = *(undefined4 *)(iVar2 + 0x30);
    uStack_40 = *(undefined4 *)(iVar2 + 0x34);
    uStack_3c = *(undefined4 *)(iVar2 + 0x38);
    uStack_38 = *(undefined4 *)(iVar2 + 0x3c);
    local_80 = *(undefined8 *)(iVar11 + 0x7c);
    local_78 = *(float *)(iVar11 + 0x84) + -100.0;
    AbyssEngine::AEMath::MatrixRotateVector
              ((AEMath *)&local_c0,(Matrix *)&local_70,(Vector *)&local_80);
    AbyssEngine::AEMath::Vector::operator+=(aVStack_34,(Vector *)&local_c0);
    AEGeometry::setPosition(*(Vector **)(this + 0x18));
    uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 0x18) + 0xc));
    AbyssEngine::Transform::Update((ulonglong)uVar1,SUB41(param_1,0));
    this_00 = Globals::Canvas;
    if (*(int *)(*(int *)(this + 8) + 0x5c) == 8) {
      pMVar6 = (Matrix *)AEGeometry::getMatrix((AEGeometry *)piVar4[0xb]);
      pMVar7 = (Matrix *)AEGeometry::getMatrix((AEGeometry *)piVar4[10]);
      AbyssEngine::AEMath::operator*((AEMath *)&local_c0,pMVar6,pMVar7);
      iVar11 = *(int *)(this + 8);
      iVar2 = *(int *)(iVar11 + 0x58);
      if (iVar2 == 0x2f) {
        local_c4 = 0x43820000;
      }
      else if (iVar2 == 0x30) {
        local_c4 = 0x432a0000;
      }
      else if (iVar2 == 0x31) {
        local_c4 = 0x43480000;
      }
      else if (iVar2 == 0xb4) {
        local_c4 = 0x432c0000;
      }
      else if (iVar2 == 0xb5) {
        local_c4 = 0x433e0000;
      }
      else {
        puVar8 = &DAT_0018c748;
        if (iVar2 == 0xb6) {
          puVar8 = &DAT_0018c74c;
        }
        local_c4 = *puVar8;
        if (iVar2 == 0xe0) {
          local_c4 = 0x43130000;
        }
        else if (iVar2 == 0xb6) {
          local_c4 = 0x43160000;
        }
      }
      local_c8 = 0;
      local_cc = 0.0;
      uVar1 = *(uint *)(iVar11 + 0xa4);
      if ((uVar1 & 0xff) != 0) {
        if (iVar2 == 0xb5) {
          pfVar10 = (float *)&DAT_0018c758;
          if ((uVar1 >> 0x10 & 0xff) != 0) {
            pfVar10 = (float *)&DAT_0018c75c;
          }
          local_cc = *pfVar10;
        }
        else {
          if (iVar2 == 0x30) {
            fVar12 = 20.0;
            fVar13 = -20.0;
          }
          else {
            fVar12 = 45.0;
            fVar13 = -45.0;
          }
          local_cc = fVar12 - *(float *)(iVar11 + 0x7c);
          if ((uVar1 >> 0x10 & 0xff) != 0) {
            local_cc = *(float *)(iVar11 + 0x7c) + fVar13;
          }
        }
      }
      if ((uVar1 & 0xff00) != 0) {
        if (iVar2 == 0xe0) {
          local_c8 = 0x41500000;
          if (uVar1 >> 0x18 != 0) {
            local_c8 = 0xc1500000;
          }
        }
        else if (iVar2 == 0xb5) {
          puVar8 = &DAT_0018c760;
          if (uVar1 >> 0x18 != 0) {
            puVar8 = &DAT_0018c764;
          }
          local_c8 = *puVar8;
        }
      }
      AbyssEngine::AEMath::MatrixRotateVector(aAStack_d8,(Matrix *)&local_c0,(Vector *)&local_cc);
      AEGeometry::setMatrix(*(Matrix **)(this + 0x18));
      AEGeometry::translate(*(Vector **)(this + 0x18));
    }
    else {
      uVar1 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
      puVar8 = (undefined4 *)AbyssEngine::PaintCanvas::CameraGetLocal(this_00,uVar1);
      local_c0 = *puVar8;
      uStack_bc = puVar8[1];
      uStack_b8 = puVar8[2];
      uStack_b4 = puVar8[3];
      uStack_b0 = puVar8[4];
      local_ac = puVar8[5];
      uStack_a8 = puVar8[6];
      uStack_a4 = puVar8[7];
      uStack_a0 = puVar8[8];
      uStack_9c = puVar8[9];
      local_98 = puVar8[10];
      uStack_94 = puVar8[0xb];
      uStack_90 = puVar8[0xc];
      uStack_8c = puVar8[0xd];
      uStack_88 = puVar8[0xe];
      pAVar3 = *(AEGeometry **)(this + 0x18);
      AbyssEngine::AEMath::MatrixGetDir((AEMath *)&local_cc,(Matrix *)&local_70);
      AbyssEngine::AEMath::MatrixGetUp(aAStack_d8,(AEMath *)&local_c0);
      AEGeometry::setDirection(pAVar3,(Vector *)&local_cc,(Vector *)aAStack_d8);
    }
  }
LAB_0018c614:
  iVar2 = *(int *)(this + 8);
  this[0x1d] = *(ObjectGun *)(iVar2 + 0xa9);
  if ((*(int *)(iVar2 + 0x5c) == 0x19) && (*(int *)(iVar2 + 8) != 0)) {
    iVar11 = 0;
    uVar1 = 0;
    do {
      if (*(char *)(*(int *)(iVar2 + 0x40) + uVar1) != '\0') {
        if (*(char *)(*(int *)(this + 0x30) + uVar1) != '\0') {
          local_70 = 0;
          uStack_6c = 0;
          local_68 = 0;
          Explosion::start(*(Explosion **)(*(int *)(*(int *)(this + 0x2c) + 4) + uVar1 * 4),
                           (Vector *)(*(int *)(iVar2 + 0x30) + iVar11),(Vector *)&local_70);
          *(undefined1 *)(*(int *)(this + 0x30) + uVar1) = 0;
        }
        Explosion::update(*(Explosion **)(*(int *)(*(int *)(this + 0x2c) + 4) + uVar1 * 4),param_1,
                          (TargetFollowCamera *)0x0);
        iVar2 = Explosion::isPlaying
                          (*(Explosion **)(*(int *)(*(int *)(this + 0x2c) + 4) + uVar1 * 4));
        if (iVar2 == 0) {
          iVar2 = *(int *)(this + 8);
          *(undefined1 *)(*(int *)(iVar2 + 0x40) + uVar1) = 0;
          *(undefined1 *)(iVar2 + 0x88) = 0;
          *(undefined1 *)(*(int *)(this + 0x30) + uVar1) = 1;
          Explosion::reset(*(Explosion **)(*(int *)(*(int *)(this + 0x2c) + 4) + uVar1 * 4));
        }
      }
      iVar2 = *(int *)(this + 8);
      iVar11 = iVar11 + 0xc;
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(iVar2 + 8));
  }
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== ObjectGun::render  @0x0018c770  (1516 bytes)
/* ObjectGun::render() */

void __thiscall ObjectGun::render(ObjectGun *this)

{
  PaintCanvas *pPVar1;
  int iVar2;
  Matrix *pMVar3;
  uint uVar4;
  Level *this_00;
  Vector *this_01;
  Vector *this_02;
  Vector *pVVar5;
  float *pfVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  Matrix *this_03;
  Vector *this_04;
  int iVar10;
  uint in_fpscr;
  float extraout_s0;
  float fVar11;
  float extraout_s0_00;
  float fVar12;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float extraout_s1_03;
  float extraout_s1_04;
  float extraout_s1_05;
  float extraout_s1_06;
  float extraout_s1_07;
  float extraout_s1_08;
  float extraout_s1_09;
  float extraout_s1_10;
  float extraout_s1_11;
  float extraout_s1_12;
  float extraout_s1_13;
  float extraout_s1_14;
  float extraout_s1_15;
  float extraout_s2;
  float extraout_s2_00;
  float extraout_s2_01;
  float extraout_s2_02;
  float extraout_s2_03;
  float extraout_s2_04;
  float extraout_s2_05;
  float extraout_s2_06;
  float extraout_s2_07;
  float extraout_s2_08;
  float extraout_s2_09;
  float extraout_s2_10;
  float extraout_s2_11;
  float extraout_s2_12;
  float extraout_s2_13;
  float fVar13;
  float extraout_s2_14;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  int local_138;
  AEMath aAStack_134 [12];
  AEMath aAStack_128 [12];
  float local_11c;
  float local_118;
  float local_114;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 uStack_d8;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined4 local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined4 local_68;
  int local_64;
  
  local_64 = __stack_chk_guard;
  Gun::render(*(Gun **)(this + 8));
  iVar2 = *(int *)(this + 8);
  fVar12 = extraout_s1;
  fVar13 = extraout_s2;
  if ((*(int *)(iVar2 + 0x5c) == 0x19) && (*(int *)(iVar2 + 8) != 0)) {
    uVar9 = 0;
    do {
      if (*(char *)(*(int *)(iVar2 + 0x40) + uVar9) != '\0') {
        Explosion::render(*(Explosion **)(*(int *)(*(int *)(this + 0x2c) + 4) + uVar9 * 4));
        iVar2 = *(int *)(this + 8);
        fVar12 = extraout_s1_00;
        fVar13 = extraout_s2_00;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(uint *)(iVar2 + 8));
  }
  if (*(char *)(iVar2 + 0x4c) != '\0') {
    uStack_84 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    local_80 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    local_7c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    puVar8 = (undefined4 *)((uint)&local_a0 | 4);
    local_a0 = 0x3f800000;
    *puVar8 = 0;
    puVar8[1] = uStack_84;
    puVar8[2] = local_80;
    puVar8[3] = local_7c;
    pPVar1 = Globals::Canvas;
    local_8c = 0x3f800000;
    local_88 = 0;
    local_78 = 0x3f800000;
    uStack_70 = 0x3f8000003f800000;
    local_68 = 0x3f800000;
    if (*(int *)(iVar2 + 0x5c) == 8) {
      uVar9 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
      pMVar3 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar1,uVar9);
      AbyssEngine::AEMath::Matrix::operator=((Matrix *)&local_a0,pMVar3);
      fVar12 = extraout_s1_01;
      fVar13 = extraout_s2_01;
      if (this[0x4c] != (ObjectGun)0x0) {
        uStack_c4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
        uStack_c0 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
        uStack_bc = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
        puVar8 = (undefined4 *)((uint)&local_e0 | 4);
        local_e0 = 0x3f800000;
        *puVar8 = 0;
        puVar8[1] = uStack_c4;
        puVar8[2] = uStack_c0;
        puVar8[3] = uStack_bc;
        local_cc = 0x3f800000;
        local_c8 = 0;
        local_b8 = 0x3f800000;
        uStack_b0 = 0x3f8000003f800000;
        local_a8 = 0x3f800000;
        AbyssEngine::AEMath::MatrixSetRotation
                  ((Matrix *)&local_11c,*(float *)(this + 0x48),extraout_s1_01,extraout_s2_01);
        AbyssEngine::AEMath::Matrix::operator=((Matrix *)&local_e0,(Matrix *)&local_11c);
        AbyssEngine::AEMath::Matrix::operator*=((Matrix *)&local_a0,(Matrix *)&local_e0);
        fVar12 = extraout_s1_02;
        fVar13 = extraout_s2_02;
      }
    }
    iVar2 = *(int *)(this + 8);
    if (*(int *)(iVar2 + 8) == 0) {
      local_138 = 0;
    }
    else {
      uVar14 = 0;
      uVar15 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      uVar16 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      uVar17 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      puVar8 = (undefined4 *)((uint)&local_e0 | 4);
      this_01 = (Vector *)(this + 0x68);
      this_02 = (Vector *)(this + 0x5c);
      this_04 = (Vector *)(this + 0x50);
      this_03 = (Matrix *)(this + 0x74);
      iVar10 = 0;
      uVar9 = 0;
      local_138 = 0;
      do {
        pfVar6 = (float *)(*(int *)(iVar2 + 0xc) + iVar10);
        in_fpscr = in_fpscr & 0xfffffff | (uint)(*pfVar6 == 50000.0) << 0x1e;
        if ((byte)(in_fpscr >> 0x1e) == 0) {
          AbyssEngine::AEMath::MatrixSetTranslation
                    ((AEMath *)&local_e0,this_03,pfVar6[2],fVar12,fVar13);
          AbyssEngine::AEMath::VectorNormalize
                    ((AEMath *)&local_e0,(Vector *)(*(int *)(*(int *)(this + 8) + 0x18) + iVar10));
          AbyssEngine::AEMath::Vector::operator=(this_04,(Vector *)&local_e0);
          if (this[0x4c] == (ObjectGun)0x0) {
            this_00 = *(Level **)(this + 0xc);
            if (this[0x24] == (ObjectGun)0x0) {
              if (((this_00 == (Level *)0x0) || (iVar2 = Level::getPlayer(this_00), iVar2 == 0)) ||
                 (iVar2 = Gun::isPlayerGun(*(Gun **)(this + 8)), iVar2 != 1)) {
                local_e0 = 0;
                local_dc = 0x3f800000;
                uStack_d8 = 0;
                pVVar5 = (Vector *)&local_e0;
              }
              else {
                pVVar5 = (Vector *)(*(int *)(*(int *)(this + 8) + 0x24) + iVar10);
              }
              AbyssEngine::AEMath::Vector::operator=(this_02,pVVar5);
              AbyssEngine::AEMath::VectorCross((AEMath *)&local_e0,this_02,this_04);
              AbyssEngine::AEMath::Vector::operator=(this_01,(Vector *)&local_e0);
              AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_e0,this_01);
              AbyssEngine::AEMath::Vector::operator=(this_01,(Vector *)&local_e0);
              AbyssEngine::AEMath::VectorCross((AEMath *)&local_e0,this_04,this_01);
              AbyssEngine::AEMath::Vector::operator=(this_02,(Vector *)&local_e0);
              AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_e0,this_02);
              AbyssEngine::AEMath::Vector::operator=(this_02,(Vector *)&local_e0);
              *(undefined4 *)(this + 0x74) = *(undefined4 *)(this + 0x68);
              *(undefined4 *)(this + 0x84) = *(undefined4 *)(this + 0x6c);
              *(undefined4 *)(this + 0x94) = *(undefined4 *)(this + 0x70);
              *(undefined4 *)(this + 0x78) = *(undefined4 *)(this + 0x5c);
              *(undefined4 *)(this + 0x88) = *(undefined4 *)(this + 0x60);
              *(undefined4 *)(this + 0x98) = *(undefined4 *)(this + 100);
              *(undefined4 *)(this + 0x7c) = *(undefined4 *)(this + 0x50);
              *(undefined4 *)(this + 0x8c) = *(undefined4 *)(this + 0x54);
              *(undefined4 *)(this + 0x9c) = *(undefined4 *)(this + 0x58);
              iVar2 = *(int *)(*(int *)(*(int *)(this + 8) + 0x3c) + uVar9 * 4);
              if (iVar2 < 1000) {
                fVar12 = (float)VectorSignedToFloat(iVar2,(byte)(in_fpscr >> 0x16) & 3);
                AbyssEngine::AEMath::MatrixSetScaling
                          ((AEMath *)&local_e0,this_03,fVar12 / 1000.0,extraout_s1_03,extraout_s2_03
                          );
                fVar12 = extraout_s1_04;
                fVar13 = extraout_s2_04;
              }
              else {
                fVar12 = extraout_s1_03;
                fVar13 = extraout_s2_03;
                if (*(char *)(*(int *)(this + 8) + 0x4d) != '\0') {
                  AbyssEngine::AEMath::MatrixSetScaling
                            ((AEMath *)&local_e0,this_03,extraout_s0,extraout_s1_03,extraout_s2_03);
                  iVar2 = (**(code **)(*(int *)this + 0x20))(this);
                  fVar12 = extraout_s1_05;
                  fVar13 = extraout_s2_05;
                  if (iVar2 == 0) {
                    *(undefined1 *)(*(int *)(this + 8) + 0x4d) = 0;
                  }
                }
              }
            }
            else {
              iVar2 = Level::getPlayer(this_00);
              local_e0 = 0x3f800000;
              *puVar8 = uVar14;
              puVar8[1] = uVar15;
              puVar8[2] = uVar16;
              puVar8[3] = uVar17;
              local_cc = 0x3f800000;
              local_b8 = 0x3f800000;
              uStack_b0 = 0x3f8000003f800000;
              local_a8 = 0x3f800000;
              local_c8 = uVar14;
              uStack_c4 = uVar15;
              uStack_c0 = uVar16;
              uStack_bc = uVar17;
              AbyssEngine::AEMath::MatrixSetRotation
                        ((Matrix *)&local_11c,extraout_s0_00,extraout_s1_08,extraout_s2_08);
              AbyssEngine::AEMath::Matrix::operator*=((Matrix *)(iVar2 + 0x40),(Matrix *)&local_e0);
              AbyssEngine::AEMath::Matrix::operator=(this_03,(Matrix *)(iVar2 + 0x40));
              AbyssEngine::AEMath::MatrixSetTranslation
                        ((AEMath *)&local_11c,this_03,
                         *(float *)(*(int *)(*(int *)(this + 8) + 0xc) + iVar10 + 8),extraout_s1_09,
                         extraout_s2_09);
              iVar7 = *(int *)(*(int *)(this + 8) + 0x18);
              AbyssEngine::AEMath::MatrixGetDir(aAStack_134,this_03);
              fVar12 = (float)AbyssEngine::AEMath::VectorNormalize
                                        (aAStack_128,(Vector *)aAStack_134);
              AbyssEngine::AEMath::operator*((AEMath *)&local_11c,(Vector *)aAStack_128,fVar12);
              AbyssEngine::AEMath::Vector::operator=
                        ((Vector *)(iVar7 + iVar10),(Vector *)&local_11c);
              *(undefined4 *)(iVar2 + 0x7c) = 0;
              *(undefined4 *)(iVar2 + 0x80) = 0;
              AbyssEngine::AEMath::MatrixSetRotation
                        ((Matrix *)&local_11c,*(float *)(this + 0x20),extraout_s1_10,extraout_s2_10)
              ;
              AbyssEngine::PaintCanvas::TransformSetLocal
                        (Globals::Canvas,*(uint *)(this + 0x14),(Matrix *)&local_e0);
              fVar12 = extraout_s1_11;
              fVar13 = extraout_s2_11;
            }
          }
          else {
            AbyssEngine::AEMath::operator-((AEMath *)&local_11c,this_04);
            pPVar1 = Globals::Canvas;
            iVar2 = *(int *)(this + 8);
            fVar12 = extraout_s1_06;
            fVar13 = extraout_s2_06;
            if (2 < *(int *)(iVar2 + 0x58) - 0xb4U) {
              uVar4 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
              pMVar3 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar1,uVar4);
              AbyssEngine::AEMath::Matrix::operator=((Matrix *)&local_a0,pMVar3);
              AbyssEngine::AEMath::MatrixGetDir((AEMath *)&local_e0,(Matrix *)&local_a0);
              AbyssEngine::AEMath::Vector::operator=((Vector *)&local_11c,(Vector *)&local_e0);
              iVar2 = *(int *)(this + 8);
              fVar12 = extraout_s1_07;
              fVar13 = extraout_s2_07;
            }
            *(undefined4 *)(this + 0x74) = local_a0;
            *(undefined4 *)(this + 0x84) = local_90;
            *(undefined4 *)(this + 0x94) = local_80;
            *(undefined4 *)(this + 0x78) = local_9c;
            *(undefined4 *)(this + 0x88) = local_8c;
            *(undefined4 *)(this + 0x98) = local_7c;
            *(float *)(this + 0x7c) = -local_11c;
            *(float *)(this + 0x8c) = -local_118;
            fVar11 = -local_114;
            *(float *)(this + 0x9c) = fVar11;
            iVar7 = *(int *)(*(int *)(iVar2 + 0x3c) + uVar9 * 4);
            if (iVar7 < 1000) {
              fVar11 = (float)VectorSignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
              fVar11 = fVar11 / 1000.0;
            }
            else if (*(char *)(iVar2 + 0x4d) == '\0') goto LAB_0018cc28;
            AbyssEngine::AEMath::MatrixSetScaling((AEMath *)&local_e0,this_03,fVar11,fVar12,fVar13);
            fVar12 = extraout_s1_12;
            fVar13 = extraout_s2_12;
          }
LAB_0018cc28:
          if (Globals::iPad != '\0') {
            AbyssEngine::AEMath::MatrixSetScaling
                      ((AEMath *)&local_e0,this_03,*(float *)(this + 0x44),fVar12,fVar13);
            fVar12 = extraout_s1_13;
            fVar13 = extraout_s2_13;
          }
          if (*(int *)(*(int *)(this + 8) + 0x5c) == 0xb) {
            pfVar6 = *(float **)(*(int *)(*(int *)(*(int *)(this + 8) + 0xac) + 4) + uVar9 * 4);
            if ((pfVar6 != (float *)0x0) && (0 < *(int *)(this + 0x34))) {
              AbyssEngine::AEMath::MatrixSetRotation((Matrix *)&local_e0,pfVar6[2],fVar12,fVar13);
              fVar12 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x34),
                                                  (byte)(in_fpscr >> 0x16) & 3);
              in_fpscr = in_fpscr & 0xfffffff;
              fVar13 = fVar12 * 0.0005;
              fVar11 = -(fVar12 * 0.0005);
              fVar12 = fVar13;
              if (*pfVar6 < 0.0) {
                fVar12 = fVar11;
              }
              *pfVar6 = *pfVar6 + fVar12;
              fVar12 = fVar13;
              if (pfVar6[1] < 0.0) {
                fVar12 = fVar11;
              }
              pfVar6[1] = pfVar6[1] + fVar12;
              if (pfVar6[2] < 0.0) {
                fVar13 = fVar11;
              }
              pfVar6[2] = pfVar6[2] + fVar13;
              fVar12 = extraout_s1_14;
            }
            AbyssEngine::AEMath::MatrixSetScaling
                      ((AEMath *)&local_e0,this_03,*(float *)(this + 0x44),fVar12,fVar13);
          }
          AbyssEngine::PaintCanvas::TransformSetLocal
                    (Globals::Canvas,*(uint *)(this + 0x10),this_03);
          AbyssEngine::PaintCanvas::DrawTransform
                    (Globals::Canvas,*(uint *)(this + 0x10),(Matrix *)0x0);
          iVar2 = *(int *)(this + 8);
          fVar12 = extraout_s1_15;
          fVar13 = extraout_s2_14;
        }
        else {
          local_138 = local_138 + 1;
        }
        iVar10 = iVar10 + 0xc;
        uVar9 = uVar9 + 1;
      } while (uVar9 < *(uint *)(iVar2 + 8));
    }
    if (*(int *)(iVar2 + 0x14) <= local_138) {
      *(undefined1 *)(iVar2 + 0x4c) = 0;
    }
  }
  if ((this[0x1d] != (ObjectGun)0x0) && (*(AEGeometry **)(this + 0x18) != (AEGeometry *)0x0)) {
    AEGeometry::render(*(AEGeometry **)(this + 0x18));
  }
  *(undefined4 *)(this + 0x34) = 0;
  if (__stack_chk_guard == local_64) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== ObjectGun::translate  @0x0018cda0  (2 bytes)
/* ObjectGun::translate(AbyssEngine::AEMath::Vector const&) */

Vector * ObjectGun::translate(Vector *param_1)

{
  return param_1;
}

// ===== ObjectGun::setScaling  @0x0018cda2  (26 bytes)
/* ObjectGun::setScaling(int, int, int) */

void ObjectGun::setScaling(int param_1,int param_2,int param_3)

{
  uint in_fpscr;
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
  uVar2 = VectorSignedToFloat(param_3,(byte)(in_fpscr >> 0x16) & 3);
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  *(undefined4 *)(param_1 + 0x40) = uVar2;
  return;
}

// ===== ObjectGun::replaceGun  @0x0018cdbc  (48 bytes)
/* ObjectGun::replaceGun(unsigned int, int) */

void ObjectGun::replaceGun(uint param_1,int param_2)

{
  AbyssEngine::PaintCanvas::TransformRemoveMesh
            (Globals::Canvas,*(uint *)(param_1 + 0x10),*(ushort *)(param_1 + 0x28));
  *(int *)(param_1 + 0x28) = param_2;
  AbyssEngine::PaintCanvas::TransformAddMesh
            (Globals::Canvas,*(uint *)(param_1 + 0x10),(ushort)param_2,false);
  return;
}

