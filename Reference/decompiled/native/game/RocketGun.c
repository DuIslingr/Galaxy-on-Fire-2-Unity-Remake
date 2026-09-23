// Class: RocketGun
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== RocketGun::isRocketGun  @0x00171620  (4 bytes)
/* RocketGun::isRocketGun() */

undefined4 RocketGun::isRocketGun(void)

{
  return 1;
}

// ===== RocketGun::RocketGun  @0x0018b150  (186 bytes)
/* RocketGun::RocketGun(int, Gun*, int, int, unsigned int, int, bool, Level*) */

RocketGun * __thiscall
RocketGun::RocketGun
          (RocketGun *this,int param_1,Gun *param_2,int param_3,int param_4,uint param_5,int param_6
          ,bool param_7,Level *param_8)

{
  int iVar1;
  AEGeometry *this_00;
  void *pvVar2;
  ushort uVar3;
  
  ObjectGun::ObjectGun((ObjectGun *)this,param_1,param_2,param_3,param_5,param_8);
  *(undefined ***)this = &PTR__RocketGun_00264764;
  *(undefined4 *)(this + 0xb4) = 0;
  *(undefined4 *)(this + 0xb8) = 0;
  *(undefined4 *)(this + 0xbc) = 0;
  *(undefined4 *)(this + 4) = 0xffffffff;
  *(int *)(this + 0xd0) = param_6;
  this[0xc0] = (RocketGun)param_7;
  *(undefined4 *)(this + 0xc4) = 0xffffffff;
  *(undefined4 *)(this + 200) = 0x3e99999a;
  *(undefined4 *)(this + 0xcc) = 0xffffffff;
  *(undefined4 *)(this + 0xd4) = 0;
  *(undefined4 *)(this + 0xd8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0xdc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0xe0) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0xe4) = 0;
  iVar1 = 0x37a9;
  if (param_3 != 0x37a9) {
    iVar1 = 0x37a7;
  }
  if (param_3 == 0x37a9 || param_3 == iVar1) {
    this_00 = operator_new(0xc0);
    uVar3 = 0x37aa;
    if (param_1 == 0x37a7) {
      uVar3 = 0x37a8;
    }
    AEGeometry::AEGeometry(this_00,uVar3,Globals::Canvas,false);
    AbyssEngine::PaintCanvas::TransformAddChild
              (Globals::Canvas,*(uint *)(this + 0x10),*(uint *)(this_00 + 0xc));
    pvVar2 = (void *)AEGeometry::~AEGeometry(this_00);
    operator_delete(pvVar2);
  }
  return this;
}

// ===== RocketGun::~RocketGun  @0x0018b230  (108 bytes)
/* RocketGun::~RocketGun() */

void __thiscall RocketGun::~RocketGun(RocketGun *this)

{
  void *pvVar1;
  
  *(undefined ***)this = &PTR__RocketGun_00264764;
  pvVar1 = *(void **)(this + 0xd8);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xd8) = 0;
  pvVar1 = *(void **)(this + 0xdc);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xdc) = 0;
  pvVar1 = *(void **)(this + 0xe0);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xe0) = 0;
  ObjectGun::~ObjectGun((ObjectGun *)this);
  return;
}

// ===== RocketGun::~RocketGun  @0x0018b2a0  (16 bytes)
/* RocketGun::~RocketGun() */

void __thiscall RocketGun::~RocketGun(RocketGun *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~RocketGun(this);
  operator_delete(pvVar1);
  return;
}

// ===== RocketGun::setRadar  @0x0018b2b0  (746 bytes)
/* RocketGun::setRadar(Radar*) */

void RocketGun::setRadar(Radar *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  Array *pAVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  ParticleSystemManager *pPVar7;
  int *in_r1;
  int iVar8;
  int in_r2;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  
  *(int **)(param_1 + 0xb0) = in_r1;
  iVar3 = *in_r1;
  *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(iVar3 + 0x80);
  iVar9 = *(int *)(param_1 + 8);
  iVar8 = *(int *)(iVar9 + 0x58);
  uVar11 = iVar8 - 0x1c;
  if (2 < uVar11) {
    if (iVar8 != 0xc1) {
      in_r2 = *(int *)(iVar9 + 0x5c);
    }
    if (iVar8 != 0xc1 && in_r2 != 0x28) {
      if ((1 < *(int *)(param_1 + 0xd0) - 4U) && (*(int *)(param_1 + 0xd0) != 0x28)) {
        if (iVar8 == 0xe8) {
          pPVar7 = *(ParticleSystemManager **)(iVar3 + 0x9c);
          uVar10 = AbyssEngine::PaintCanvas::TransformGetLocal
                             (Globals::Canvas,*(uint *)(param_1 + 0x10));
          iVar3 = ParticleSystemManager::addSystem(pPVar7,uVar10,0x2f,0);
          *(int *)(param_1 + 0xcc) = iVar3;
          pPVar7 = *(ParticleSystemManager **)(*in_r1 + 0x9c);
        }
        else {
          pPVar7 = *(ParticleSystemManager **)(iVar3 + 0x84);
          uVar10 = AbyssEngine::PaintCanvas::TransformGetLocal
                             (Globals::Canvas,*(uint *)(param_1 + 0x10));
          iVar3 = ParticleSystemManager::addSystem(pPVar7,uVar10,0xc,0);
          *(int *)(param_1 + 0xcc) = iVar3;
          pPVar7 = *(ParticleSystemManager **)(*in_r1 + 0x84);
        }
        ParticleSystemManager::enableSystemEmit(pPVar7,iVar3,false);
        return;
      }
      pAVar4 = operator_new(0xc);
      puVar5 = operator_new__(0x3c);
      uVar10 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      uVar1 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      *(undefined4 **)(pAVar4 + 4) = puVar5;
      *(undefined4 *)(pAVar4 + 8) = 1;
      puVar5[0xb] = 0;
      puVar5[0xc] = uVar10;
      puVar5[0xd] = uVar1;
      puVar5[0xe] = uVar2;
      puVar5[8] = 0;
      puVar5[9] = uVar10;
      puVar5[10] = uVar1;
      puVar5[0xb] = uVar2;
      *puVar5 = 0;
      puVar5[1] = uVar10;
      puVar5[2] = uVar1;
      puVar5[3] = uVar2;
      puVar5[4] = 0;
      puVar5[5] = uVar10;
      puVar5[6] = uVar1;
      puVar5[7] = uVar2;
      *(undefined4 *)pAVar4 = 0;
      *(Array **)(param_1 + 0xd8) = pAVar4;
      puVar5 = operator_new(0xc);
      puVar6 = operator_new__(4);
      puVar5[1] = puVar6;
      puVar5[2] = 1;
      *puVar6 = 0;
      *puVar5 = 0;
      *(undefined4 **)(param_1 + 0xdc) = puVar5;
      puVar5 = operator_new(0xc);
      puVar6 = operator_new__(4);
      puVar5[1] = puVar6;
      puVar5[2] = 1;
      *puVar6 = 0;
      *puVar5 = 0;
      *(undefined4 **)(param_1 + 0xe0) = puVar5;
      ArraySetLength<AbyssEngine::AEMath::Matrix>(*(uint *)(iVar9 + 8),pAVar4);
      ArraySetLength<int>(*(uint *)(*(int *)(param_1 + 8) + 8),*(Array **)(param_1 + 0xdc));
      ArraySetLength<int>(*(uint *)(*(int *)(param_1 + 8) + 8),*(Array **)(param_1 + 0xe0));
      if (*(int *)(*(int *)(param_1 + 8) + 8) == 0) {
        return;
      }
      iVar3 = 0;
      uVar11 = 0;
      do {
        iVar8 = ParticleSystemManager::addSystem
                          (*(ParticleSystemManager **)(*in_r1 + 0x80),
                           *(int *)(*(int *)(param_1 + 0xd8) + 4) + iVar3,0x27,0);
        *(int *)(*(int *)(*(int *)(param_1 + 0xdc) + 4) + uVar11 * 4) = iVar8;
        ParticleSystemManager::enableSystemEmit
                  (*(ParticleSystemManager **)(*in_r1 + 0x80),iVar8,false);
        iVar3 = iVar3 + 0x3c;
        *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xe0) + 4) + uVar11 * 4) = 0;
        uVar11 = uVar11 + 1;
      } while (uVar11 < *(uint *)(*(int *)(param_1 + 8) + 8));
      return;
    }
  }
  if (*(int *)(iVar9 + 0x5c) == 0x28) {
    uVar11 = 0;
  }
  else if (iVar8 == 0xc1) {
    uVar11 = 3;
  }
  pAVar4 = operator_new(0xc);
  puVar5 = operator_new__(0x3c);
  uVar10 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar1 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 **)(pAVar4 + 4) = puVar5;
  *(undefined4 *)(pAVar4 + 8) = 1;
  puVar5[0xb] = 0;
  puVar5[0xc] = uVar10;
  puVar5[0xd] = uVar1;
  puVar5[0xe] = uVar2;
  puVar5[8] = 0;
  puVar5[9] = uVar10;
  puVar5[10] = uVar1;
  puVar5[0xb] = uVar2;
  *puVar5 = 0;
  puVar5[1] = uVar10;
  puVar5[2] = uVar1;
  puVar5[3] = uVar2;
  puVar5[4] = 0;
  puVar5[5] = uVar10;
  puVar5[6] = uVar1;
  puVar5[7] = uVar2;
  *(undefined4 *)pAVar4 = 0;
  *(Array **)(param_1 + 0xd8) = pAVar4;
  puVar5 = operator_new(0xc);
  puVar6 = operator_new__(4);
  puVar5[1] = puVar6;
  puVar5[2] = 1;
  *puVar6 = 0;
  *puVar5 = 0;
  *(undefined4 **)(param_1 + 0xdc) = puVar5;
  puVar5 = operator_new(0xc);
  puVar6 = operator_new__(4);
  puVar5[1] = puVar6;
  puVar5[2] = 1;
  *puVar6 = 0;
  *puVar5 = 0;
  *(undefined4 **)(param_1 + 0xe0) = puVar5;
  ArraySetLength<AbyssEngine::AEMath::Matrix>(*(uint *)(iVar9 + 8),pAVar4);
  ArraySetLength<int>(*(uint *)(*(int *)(param_1 + 8) + 8),*(Array **)(param_1 + 0xdc));
  ArraySetLength<int>(*(uint *)(*(int *)(param_1 + 8) + 8),*(Array **)(param_1 + 0xe0));
  iVar3 = *(int *)(param_1 + 8);
  if (*(int *)(iVar3 + 8) != 0) {
    uVar10 = 0x1c;
    if (uVar11 == 2) {
      uVar10 = 0x1b;
    }
    if (uVar11 == 1) {
      uVar10 = 0x1a;
    }
    if (uVar11 == 0) {
      uVar10 = 0x19;
    }
    iVar8 = 0;
    uVar11 = 0;
    do {
      if (*(int *)(iVar3 + 0x58) == 0xc1) {
        pPVar7 = *(ParticleSystemManager **)(*in_r1 + 0x98);
        *(ParticleSystemManager **)(param_1 + 0xe4) = pPVar7;
      }
      else {
        pPVar7 = *(ParticleSystemManager **)(param_1 + 0xe4);
      }
      iVar3 = ParticleSystemManager::addSystem
                        (pPVar7,*(int *)(*(int *)(param_1 + 0xd8) + 4) + iVar8,uVar10,0);
      *(int *)(*(int *)(*(int *)(param_1 + 0xdc) + 4) + uVar11 * 4) = iVar3;
      ParticleSystemManager::enableSystemEmit
                (*(ParticleSystemManager **)(param_1 + 0xe4),iVar3,false);
      iVar8 = iVar8 + 0x3c;
      *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xe0) + 4) + uVar11 * 4) = 0;
      uVar11 = uVar11 + 1;
      iVar3 = *(int *)(param_1 + 8);
    } while (uVar11 < *(uint *)(iVar3 + 8));
  }
  return;
}

// ===== RocketGun::render  @0x0018b5fc  (4 bytes)
/* RocketGun::render() */

void RocketGun::render(void)

{
  ObjectGun *in_r0;
  
  ObjectGun::render(in_r0);
  return;
}

// ===== RocketGun::update  @0x0018b600  (1866 bytes)
/* RocketGun::update(int) */

void __thiscall RocketGun::update(RocketGun *this,int param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  Matrix *pMVar4;
  undefined8 *puVar5;
  undefined4 *puVar6;
  ParticleSystemManager *pPVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  AEGeometry *this_00;
  int iVar11;
  int iVar12;
  bool bVar13;
  uint in_fpscr;
  float fVar14;
  float fVar15;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float extraout_s2;
  float extraout_s2_00;
  float extraout_s2_01;
  float fVar16;
  AEMath aAStack_c4 [12];
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 uStack_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 uStack_9c;
  undefined4 local_98;
  undefined4 local_94;
  float local_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  float local_58;
  undefined4 local_50;
  undefined4 uStack_4c;
  float local_48;
  int local_44;
  
  local_44 = __stack_chk_guard;
  local_50 = 0;
  uStack_4c = 0;
  local_48 = 0.0;
  Gun::update(*(Gun **)(this + 8),param_1);
  uVar1 = param_1;
  if (this[0x1c] != (RocketGun)0x0) {
    uVar1 = (uint)*(byte *)(*(int *)(this + 8) + 0xa9);
  }
  if (this[0x1c] != (RocketGun)0x0 && uVar1 != 0) {
    piVar2 = (int *)Level::getPlayer(*(Level **)(this + 0xc));
    PlayerEgo::getPosition();
    local_60 = *(undefined8 *)(*(int *)(this + 8) + 0x7c);
    local_58 = *(float *)(*(int *)(this + 8) + 0x84) + -100.0;
    AbyssEngine::AEMath::MatrixRotateVector
              ((AEMath *)&local_6c,(Matrix *)(*piVar2 + 4),(Vector *)&local_60);
    AbyssEngine::AEMath::Vector::operator+=((Vector *)&local_b8,(Vector *)&local_6c);
    AEGeometry::setPosition(*(Vector **)(this + 0x18));
    fVar14 = (float)VectorSignedToFloat(*(undefined4 *)(*(int *)(this + 8) + 0x70),
                                        (byte)(in_fpscr >> 0x16) & 3);
    fVar14 = (float)VectorSignedToFloat((int)((fVar14 / -200.0 + 1.0) * 255.0),
                                        (byte)(in_fpscr >> 0x16) & 3);
    AEGeometry::setScaling(*(AEGeometry **)(this + 0x18),fVar14 / 255.0,extraout_s1,255.0);
    this_00 = *(AEGeometry **)(this + 0x18);
    AbyssEngine::AEMath::MatrixGetDir((AEMath *)&local_6c,(Matrix *)(*piVar2 + 4));
    local_78 = 0;
    local_74 = 0x3f800000;
    local_70 = 0;
    AEGeometry::setDirection(this_00,(Vector *)&local_6c,(Vector *)&local_78);
  }
  iVar3 = *(int *)(this + 8);
  this[0x1d] = *(RocketGun *)(iVar3 + 0xa9);
  if (*(char *)(iVar3 + 0x4d) == '\0') goto LAB_0018b98a;
  *(undefined4 *)(this + 0xd4) = 0;
  *(undefined4 *)(this + 0xc4) = 0xffffffff;
  *(undefined1 *)(iVar3 + 0x4d) = 0;
  pMVar4 = (Matrix *)
           AbyssEngine::PaintCanvas::TransformGetLocal(Globals::Canvas,*(uint *)(this + 0x10));
  AbyssEngine::AEMath::MatrixSetTranslation
            ((AEMath *)&local_b8,pMVar4,
             *(float *)(*(int *)(*(int *)(this + 8) + 0xc) +
                        *(int *)(*(int *)(this + 8) + 0xa0) * 0xc + 8),extraout_s1_00,extraout_s2);
  puVar5 = (undefined8 *)
           (*(int *)(*(int *)(this + 8) + 0x18) + *(int *)(*(int *)(this + 8) + 0xa0) * 0xc);
  local_60 = *puVar5;
  local_58 = *(float *)(puVar5 + 1);
  puVar6 = (undefined4 *)
           AbyssEngine::PaintCanvas::TransformGetLocal(Globals::Canvas,*(uint *)(this + 0x10));
  local_b8 = *puVar6;
  local_b4 = puVar6[1];
  local_b0 = puVar6[2];
  uStack_ac = puVar6[3];
  local_a8 = puVar6[4];
  local_a4 = puVar6[5];
  local_a0 = puVar6[6];
  uStack_9c = puVar6[7];
  local_98 = puVar6[8];
  local_94 = puVar6[9];
  local_90 = (float)puVar6[10];
  uStack_8c = puVar6[0xb];
  uStack_88 = puVar6[0xc];
  uStack_84 = puVar6[0xd];
  uStack_80 = puVar6[0xe];
  local_6c = 0;
  local_68 = 0x3f800000;
  local_64 = 0;
  AbyssEngine::AEMath::VectorCross((AEMath *)&local_78,(Vector *)&local_6c,(Vector *)&local_60);
  AbyssEngine::AEMath::VectorNormalize(aAStack_c4,(Vector *)&local_78);
  AbyssEngine::AEMath::Vector::operator=((Vector *)&local_78,(Vector *)aAStack_c4);
  AbyssEngine::AEMath::VectorCross(aAStack_c4,(Vector *)&local_60,(Vector *)&local_78);
  AbyssEngine::AEMath::Vector::operator=((Vector *)&local_6c,(Vector *)aAStack_c4);
  AbyssEngine::AEMath::VectorNormalize(aAStack_c4,(Vector *)&local_6c);
  AbyssEngine::AEMath::Vector::operator=((Vector *)&local_6c,(Vector *)aAStack_c4);
  local_b8 = local_78;
  local_a8 = local_74;
  local_98 = local_70;
  local_b4 = local_6c;
  local_a4 = local_68;
  local_94 = local_64;
  local_b0 = (undefined4)local_60;
  local_a0 = local_60._4_4_;
  local_90 = local_58;
  AbyssEngine::PaintCanvas::TransformSetLocal
            (Globals::Canvas,*(uint *)(this + 0x10),(AEMath *)&local_b8);
  if (*(int *)(this + 0xd8) == 0) {
    if ((*(int *)(this + 0xd0) - 4U < 2) || (*(int *)(this + 0xd0) == 0x28)) {
      ParticleSystemManager::enableSystemRender
                (*(ParticleSystemManager **)(**(int **)(this + 0xb0) + 0x80),*(int *)(this + 0xcc),
                 true);
      iVar3 = *(int *)(this + 0xcc);
      pPVar7 = *(ParticleSystemManager **)(**(int **)(this + 0xb0) + 0x80);
LAB_0018b8d2:
      bVar13 = true;
    }
    else {
      iVar3 = *(int *)(this + 0xcc);
      if (*(int *)(*(int *)(this + 8) + 0x58) == 0xe8) {
        pPVar7 = *(ParticleSystemManager **)(**(int **)(this + 0xb0) + 0x9c);
        goto LAB_0018b8d2;
      }
      pPVar7 = *(ParticleSystemManager **)(**(int **)(this + 0xb0) + 0x84);
      bVar13 = *(int *)(*(int *)(this + 8) + 0x58) != 0xb3;
    }
    ParticleSystemManager::enableSystemEmit(pPVar7,iVar3,bVar13);
  }
  else {
    iVar3 = *(int *)(*(int *)(this + 8) + 0xa0);
    in_fpscr = in_fpscr & 0xfffffff |
               (uint)(*(float *)(*(int *)(*(int *)(this + 8) + 0xc) + iVar3 * 0xc + 8) == 50000.0)
               << 0x1e;
    if ((byte)(in_fpscr >> 0x1e) == 0) {
      AbyssEngine::AEMath::Matrix::operator=
                ((Matrix *)(*(int *)(*(int *)(this + 0xd8) + 4) + iVar3 * 0x3c),(Matrix *)&local_b8)
      ;
      ParticleSystemManager::resetSystem
                (*(ParticleSystemManager **)(this + 0xe4),
                 *(int *)(*(int *)(*(int *)(this + 0xdc) + 4) +
                         *(int *)(*(int *)(this + 8) + 0xa0) * 4));
      ParticleSystemManager::enableSystemEmit
                (*(ParticleSystemManager **)(this + 0xe4),
                 *(int *)(*(int *)(*(int *)(this + 0xdc) + 4) +
                         *(int *)(*(int *)(this + 8) + 0xa0) * 4),true);
      ParticleSystemManager::enableSystemRender
                (*(ParticleSystemManager **)(this + 0xe4),
                 *(int *)(*(int *)(*(int *)(this + 0xdc) + 4) +
                         *(int *)(*(int *)(this + 8) + 0xa0) * 4),true);
      *(undefined4 *)(*(int *)(*(int *)(this + 0xe0) + 4) + *(int *)(*(int *)(this + 8) + 0xa0) * 4)
           = 0;
    }
    else {
      ParticleSystemManager::enableSystemEmit
                (*(ParticleSystemManager **)(this + 0xe4),
                 *(int *)(*(int *)(*(int *)(this + 0xdc) + 4) + iVar3 * 4),false);
      ParticleSystemManager::resetSystem
                (*(ParticleSystemManager **)(this + 0xe4),
                 *(int *)(*(int *)(*(int *)(this + 0xdc) + 4) +
                         *(int *)(*(int *)(this + 8) + 0xa0) * 4));
      *(undefined4 *)(*(int *)(*(int *)(this + 0xe0) + 4) + *(int *)(*(int *)(this + 8) + 0xa0) * 4)
           = 0;
    }
  }
  iVar3 = *(int *)(this + 8);
  if ((*(int *)(iVar3 + 0x5c) == 0x28) && (0 < *(int *)(iVar3 + 0xa0))) {
    *(int *)(iVar3 + 0xa0) = *(int *)(iVar3 + 0xa0) + -1;
    *(undefined1 *)(iVar3 + 0x4d) = 1;
    (**(code **)(*(int *)this + 0x10))(this,param_1);
    Gun::update(*(Gun **)(this + 8),param_1);
    iVar3 = *(int *)(this + 8);
  }
LAB_0018b98a:
  if (((*(char *)(iVar3 + 0x4c) == '\0') || (*(int *)(iVar3 + 8) != 1)) ||
     (in_fpscr = in_fpscr & 0xfffffff |
                 (uint)(*(float *)(*(int *)(iVar3 + 0xc) + 8) == 50000.0) << 0x1e,
     (byte)(in_fpscr >> 0x1e) == 0)) {
    if (((0 < *(int *)(this + 0xd4)) && (*(int *)(iVar3 + 8) == 1)) &&
       ((in_fpscr = in_fpscr & 0xfffffff |
                    (uint)(*(float *)(*(int *)(iVar3 + 0xc) + 8) == 50000.0) << 0x1e,
        (byte)(in_fpscr >> 0x1e) != 0 &&
        (iVar3 = *(int *)(this + 0xd4) - param_1, *(int *)(this + 0xd4) = iVar3, iVar3 < 1)))) {
      *(undefined4 *)(this + 0xd4) = 0;
      ParticleSystemManager::enableSystemRender
                (*(ParticleSystemManager **)(this + 0xe4),*(int *)(this + 0xcc),false);
    }
  }
  else {
    *(undefined1 *)(iVar3 + 0x4c) = 0;
    if ((*(int *)(this + 0xd0) - 4U < 2) || (*(int *)(this + 0xd0) == 0x28)) {
      if (*(int *)(this + 0xd4) == 0) {
        *(undefined4 *)(this + 0xd4) = 2000;
      }
      iVar9 = *(int *)(this + 0xcc);
      pPVar7 = *(ParticleSystemManager **)(**(int **)(this + 0xb0) + 0x80);
    }
    else {
      iVar9 = *(int *)(this + 0xcc);
      if (*(int *)(iVar3 + 0x58) == 0xe8) {
        pPVar7 = *(ParticleSystemManager **)(**(int **)(this + 0xb0) + 0x9c);
      }
      else {
        pPVar7 = *(ParticleSystemManager **)(**(int **)(this + 0xb0) + 0x84);
      }
    }
    ParticleSystemManager::enableSystemEmit(pPVar7,iVar9,false);
  }
  iVar3 = *(int *)(this + 8);
  if (*(int *)(iVar3 + 8) != 0) {
    iVar12 = 0;
    iVar9 = 0;
    uVar1 = 0;
    fVar14 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    do {
      iVar10 = *(int *)(iVar3 + 0xc);
      fVar14 = (float)AbyssEngine::AEMath::operator*
                                ((AEMath *)&local_6c,(Vector *)(*(int *)(iVar3 + 0x18) + iVar9),
                                 fVar14);
      AbyssEngine::AEMath::operator*((AEMath *)&local_60,(Vector *)&local_6c,fVar14);
      AbyssEngine::AEMath::operator+
                ((AEMath *)&local_b8,(Vector *)(iVar10 + iVar9),(Vector *)&local_60);
      fVar14 = (float)AbyssEngine::AEMath::Vector::operator=
                                ((Vector *)&local_50,(Vector *)&local_b8);
      iVar3 = *(int *)(this + 8);
      if (*(char *)(iVar3 + 0x4c) != '\0') {
        in_fpscr = in_fpscr & 0xfffffff | (uint)(local_48 == 50000.0) << 0x1e;
        fVar14 = local_48;
        if ((byte)(in_fpscr >> 0x1e) == 0) {
          if ((this[0xc0] != (RocketGun)0x0) &&
             ((iVar10 = *(int *)(this + 0xd8), iVar10 != 0 ||
              (iVar10 = *(int *)(*(int *)(iVar3 + 0x3c) + uVar1 * 4),
              iVar10 < *(int *)(iVar3 + 0x44) + -1000)))) {
            fVar14 = (float)seekEnemy(this,iVar10,uVar1);
            iVar3 = *(int *)(this + 8);
          }
          if (*(int *)(iVar3 + 0x5c) == 0x28) {
            iVar11 = *(int *)(iVar3 + 0x44);
            iVar10 = *(int *)(iVar3 + 0x3c);
            uVar8 = __aeabi_uidiv(iVar11 * uVar1,*(undefined4 *)(iVar3 + 8));
            fVar14 = (float)VectorSignedToFloat(iVar11 - *(int *)(iVar10 + uVar1 * 4),
                                                (byte)(in_fpscr >> 0x16) & 3);
            fVar16 = (float)VectorUnsignedToFloat(uVar8,(byte)(in_fpscr >> 0x16) & 3);
            fVar14 = (float)AbyssEngine::AEMath::Sinf((fVar16 + fVar14) * 0.003);
            fVar15 = (float)VectorSignedToFloat(*(int *)(*(int *)(this + 8) + 0x44) -
                                                *(int *)(*(int *)(*(int *)(this + 8) + 0x3c) +
                                                        uVar1 * 4),(byte)(in_fpscr >> 0x16) & 3);
            fVar15 = (float)AbyssEngine::AEMath::Cosf((fVar16 + fVar15) * 0.003);
            AbyssEngine::AEMath::VectorCross
                      ((AEMath *)&local_60,(Vector *)(*(int *)(*(int *)(this + 8) + 0x18) + iVar9),
                       (Vector *)(*(int *)(*(int *)(this + 8) + 0x24) + iVar9));
            AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_b8,(Vector *)&local_60);
            iVar3 = *(int *)(*(int *)(this + 8) + 0xc);
            fVar14 = (float)AbyssEngine::AEMath::operator*
                                      ((AEMath *)&local_6c,(Vector *)&local_b8,fVar14 + fVar14);
            AbyssEngine::AEMath::operator*((AEMath *)&local_60,(Vector *)&local_6c,fVar14);
            AbyssEngine::AEMath::Vector::operator+=((Vector *)(iVar3 + iVar9),(Vector *)&local_60);
            iVar3 = *(int *)(*(int *)(this + 8) + 0xc);
            fVar14 = (float)AbyssEngine::AEMath::operator*
                                      ((AEMath *)&local_6c,
                                       (Vector *)(*(int *)(*(int *)(this + 8) + 0x24) + iVar9),
                                       fVar15 + fVar15);
            AbyssEngine::AEMath::operator*((AEMath *)&local_60,(Vector *)&local_6c,fVar14);
            fVar14 = (float)AbyssEngine::AEMath::Vector::operator+=
                                      ((Vector *)(iVar3 + iVar9),(Vector *)&local_60);
          }
        }
        else {
          if (*(int *)(this + 0xd8) == 0) goto LAB_0018bcd2;
          fVar14 = (float)ParticleSystemManager::enableSystemEmit
                                    (*(ParticleSystemManager **)(this + 0xe4),
                                     *(int *)(*(int *)(*(int *)(this + 0xdc) + 4) + uVar1 * 4),false
                                    );
          if (*(int *)(*(int *)(*(int *)(this + 0xe0) + 4) + uVar1 * 4) == 0) {
            *(undefined4 *)(*(int *)(*(int *)(this + 0xe0) + 4) + uVar1 * 4) = 2000;
          }
        }
        if (*(int *)(this + 0xd8) != 0) {
          iVar3 = *(int *)(*(int *)(this + 8) + 0xc);
          fVar14 = (float)AbyssEngine::AEMath::operator*
                                    ((AEMath *)&local_6c,
                                     (Vector *)(*(int *)(*(int *)(this + 8) + 0x18) + iVar9),fVar14)
          ;
          AbyssEngine::AEMath::operator*((AEMath *)&local_60,(Vector *)&local_6c,fVar14);
          AbyssEngine::AEMath::operator+
                    ((AEMath *)&local_b8,(Vector *)(iVar3 + iVar9),(Vector *)&local_60);
          AbyssEngine::AEMath::Vector::operator=((Vector *)&local_50,(Vector *)&local_b8);
          AbyssEngine::AEMath::MatrixSetTranslation
                    ((AEMath *)&local_b8,(Matrix *)(*(int *)(*(int *)(this + 0xd8) + 4) + iVar12),
                     local_48,extraout_s1_01,extraout_s2_00);
          AbyssEngine::AEMath::VectorNormalize
                    ((AEMath *)&local_60,(Vector *)(*(int *)(*(int *)(this + 8) + 0x18) + iVar9));
          iVar3 = *(int *)(*(int *)(this + 0xd8) + 4);
          iVar10 = iVar9 * 5 + iVar3;
          *(undefined4 *)(iVar10 + 8) = (undefined4)local_60;
          *(undefined4 *)(iVar10 + 0x18) = local_60._4_4_;
          *(float *)(iVar10 + 0x28) = local_58;
          fVar14 = (float)AbyssEngine::AEMath::MatrixSetTranslation
                                    ((AEMath *)&local_b8,(Matrix *)(iVar3 + iVar12),local_48,
                                     extraout_s1_02,extraout_s2_01);
        }
      }
LAB_0018bcd2:
      if ((*(int *)(this + 0xe0) != 0) &&
         (in_fpscr = in_fpscr & 0xfffffff | (uint)(local_48 == 50000.0) << 0x1e, fVar14 = local_48,
         (byte)(in_fpscr >> 0x1e) != 0)) {
        iVar3 = *(int *)(*(int *)(this + 0xe0) + 4);
        iVar10 = *(int *)(iVar3 + uVar1 * 4);
        if ((0 < iVar10) &&
           (iVar10 = iVar10 - param_1, *(int *)(iVar3 + uVar1 * 4) = iVar10, iVar10 < 1)) {
          *(undefined4 *)(iVar3 + uVar1 * 4) = 0;
          fVar14 = (float)ParticleSystemManager::enableSystemRender
                                    (*(ParticleSystemManager **)(this + 0xe4),
                                     *(int *)(*(int *)(*(int *)(this + 0xdc) + 4) + uVar1 * 4),false
                                    );
        }
      }
      iVar3 = *(int *)(this + 8);
      iVar12 = iVar12 + 0x3c;
      iVar9 = iVar9 + 0xc;
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(iVar3 + 8));
  }
  if (__stack_chk_guard == local_44) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== RocketGun::seekEnemy  @0x0018bd70  (326 bytes)
/* RocketGun::seekEnemy(int, int) */

void __thiscall RocketGun::seekEnemy(RocketGun *this,int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  PlayerEgo *this_00;
  Vector *this_01;
  Player *this_02;
  float fVar4;
  Vector aVStack_44 [12];
  AEMath aAStack_38 [12];
  AEMath aAStack_2c [12];
  int local_20;
  
  local_20 = __stack_chk_guard;
  iVar1 = Gun::getEnemies(*(Gun **)(this + 8));
  if ((((*(int *)(*(Gun **)(this + 8) + 4) == 0) ||
       (iVar2 = Gun::isPlayerGun(*(Gun **)(this + 8)), iVar2 != 0)) ||
      (*(Player **)(*(int *)(this + 8) + 4) == (Player *)0x0)) ||
     ((iVar2 = Player::getKIPlayer(*(Player **)(*(int *)(this + 8) + 4)), *(int *)(iVar2 + 0x34) < 0
      || (iVar2 = Player::getEnemies(*(Player **)(*(int *)(this + 8) + 4)), iVar2 == 0)))) {
    if ((((iVar1 == 0) ||
         ((puVar3 = *(undefined4 **)(this + 0xb0), puVar3 == (undefined4 *)0x0 ||
          (iVar1 = puVar3[1], iVar1 == 0)))) || (*(char *)(iVar1 + 0x72) == '\0')) ||
       (*(char *)(iVar1 + 0x70) != '\0')) goto LAB_0018be9e;
    this_00 = (PlayerEgo *)Level::getPlayer((Level *)*puVar3);
    iVar1 = PlayerEgo::isInFreeLookMode(this_00);
    if (iVar1 != 0) goto LAB_0018be9e;
    iVar1 = *(int *)(*(int *)(*(int *)(this + 0xb0) + 4) + 4);
  }
  else {
    this_02 = *(Player **)(*(int *)(this + 8) + 4);
    iVar1 = Player::getKIPlayer(this_02);
    iVar1 = Player::getEnemy(this_02,*(int *)(iVar1 + 0x34));
  }
  if (iVar1 != 0) {
    Player::getPosition();
    AbyssEngine::AEMath::operator-
              (aAStack_38,aVStack_44,(Vector *)(*(int *)(*(int *)(this + 8) + 0xc) + param_2 * 0xc))
    ;
    AbyssEngine::AEMath::VectorNormalize(aAStack_2c,(Vector *)aAStack_38);
    this_01 = (Vector *)(this + 0xb4);
    AbyssEngine::AEMath::Vector::operator=(this_01,(Vector *)aAStack_2c);
    AbyssEngine::AEMath::VectorNormalize
              (aAStack_2c,(Vector *)(*(int *)(*(int *)(this + 8) + 0x18) + param_2 * 0xc));
    AbyssEngine::AEMath::Vector::operator-=(this_01,(Vector *)aAStack_2c);
    AbyssEngine::AEMath::Vector::operator/=(this_01,*(float *)(this + 200) * 20.0);
    AbyssEngine::AEMath::Vector::operator+=((Vector *)aAStack_2c,this_01);
    iVar1 = *(int *)(*(int *)(this + 8) + 0x18);
    AbyssEngine::AEMath::VectorNormalize(aAStack_38,(Vector *)aAStack_2c);
    fVar4 = (float)AbyssEngine::AEMath::Vector::operator=
                             ((Vector *)(iVar1 + param_2 * 0xc),(Vector *)aAStack_38);
    AbyssEngine::AEMath::Vector::operator*=
              ((Vector *)(*(int *)(*(int *)(this + 8) + 0x18) + param_2 * 0xc),fVar4);
  }
LAB_0018be9e:
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== RocketGun::translate  @0x0018bec0  (2 bytes)
/* RocketGun::translate(AbyssEngine::AEMath::Vector const&) */

Vector * RocketGun::translate(Vector *param_1)

{
  return param_1;
}

