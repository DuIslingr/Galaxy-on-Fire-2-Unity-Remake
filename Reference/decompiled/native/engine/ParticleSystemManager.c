// Class: ParticleSystemManager
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== ParticleSystemManager::ParticleSystemManager  @0x001b4240  (126 bytes)
/* ParticleSystemManager::ParticleSystemManager(AbyssEngine::PaintCanvas*,
   ParticleSettings::CameraSet, unsigned short, bool, unsigned short, bool) */

ParticleSystemManager * __thiscall
ParticleSystemManager::ParticleSystemManager
          (ParticleSystemManager *this,undefined4 param_1,undefined4 param_3,undefined2 param_4,
          ParticleSystemManager param_5,undefined2 param_6,ParticleSystemManager param_7)

{
  undefined4 *puVar1;
  
  *(undefined4 *)(this + 4) = param_1;
  *(undefined4 *)(this + 0xc) = param_3;
  puVar1 = operator_new__(4);
  *(undefined4 **)(this + 0x1c) = puVar1;
  *(undefined4 *)(this + 0x20) = 1;
  *puVar1 = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined2 *)(this + 0x24) = param_4;
  *(undefined2 *)(this + 0x26) = 0xffff;
  *(undefined4 *)(this + 0x28) = 0;
  this[0x38] = param_5;
  puVar1 = operator_new__(4);
  *(undefined4 **)(this + 0x40) = puVar1;
  *(undefined4 *)(this + 0x44) = 1;
  *puVar1 = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined2 *)(this + 0x48) = param_6;
  *(undefined2 *)(this + 0x4a) = 0xffff;
  *(undefined4 *)(this + 0x4c) = 0;
  this[0x60] = param_7;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  this[0x14] = (ParticleSystemManager)0x0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x2c) = 0xffffffff;
  *(undefined4 *)(this + 0x30) = 0xffffffff;
  *(undefined4 *)(this + 0x54) = 0xffffffff;
  *(undefined4 *)(this + 0x58) = 0xffffffff;
  *(undefined2 *)this = 0x101;
  return this;
}

// ===== ParticleSystemManager::construct  @0x001b42ce  (30 bytes)
/* ParticleSystemManager::construct() */

void __thiscall ParticleSystemManager::construct(ParticleSystemManager *this)

{
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  this[0x14] = (ParticleSystemManager)0x0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x2c) = 0xffffffff;
  *(undefined4 *)(this + 0x30) = 0xffffffff;
  *(undefined4 *)(this + 0x54) = 0xffffffff;
  *(undefined4 *)(this + 0x58) = 0xffffffff;
  *(undefined2 *)this = 0x101;
  return;
}

// ===== ParticleSystemManager::ParticleSystemManager  @0x001b4318  (126 bytes)
/* ParticleSystemManager::ParticleSystemManager(AbyssEngine::PaintCanvas*,
   ParticleSettings::CameraSet, unsigned short, AbyssEngine::BlendMode, bool, unsigned short,
   AbyssEngine::BlendMode, bool) */

ParticleSystemManager * __thiscall
ParticleSystemManager::ParticleSystemManager
          (ParticleSystemManager *this,undefined4 param_1,undefined4 param_3,undefined2 param_4,
          undefined4 param_5,ParticleSystemManager param_6,undefined2 param_7,undefined4 param_8,
          ParticleSystemManager param_9)

{
  undefined4 *puVar1;
  
  *(undefined4 *)(this + 4) = param_1;
  *(undefined4 *)(this + 0xc) = param_3;
  puVar1 = operator_new__(4);
  *(undefined4 **)(this + 0x1c) = puVar1;
  *(undefined4 *)(this + 0x20) = 1;
  *puVar1 = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined2 *)(this + 0x24) = 0xffff;
  *(undefined2 *)(this + 0x26) = param_4;
  *(undefined4 *)(this + 0x28) = param_5;
  this[0x38] = param_6;
  puVar1 = operator_new__(4);
  *(undefined4 **)(this + 0x40) = puVar1;
  *(undefined4 *)(this + 0x44) = 1;
  *puVar1 = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined2 *)(this + 0x48) = 0xffff;
  *(undefined2 *)(this + 0x4a) = param_7;
  *(undefined4 *)(this + 0x4c) = param_8;
  this[0x60] = param_9;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  this[0x14] = (ParticleSystemManager)0x0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x2c) = 0xffffffff;
  *(undefined4 *)(this + 0x30) = 0xffffffff;
  *(undefined4 *)(this + 0x54) = 0xffffffff;
  *(undefined4 *)(this + 0x58) = 0xffffffff;
  *(undefined2 *)this = 0x101;
  return this;
}

// ===== ParticleSystemManager::init  @0x001b43a6  (36 bytes)
/* ParticleSystemManager::init() */

void __thiscall ParticleSystemManager::init(ParticleSystemManager *this)

{
  undefined4 extraout_r1;
  
  initSprites(this);
  initMesh(this);
  this[0x14] = (ParticleSystemManager)0x1;
  update(CONCAT44(extraout_r1,this));
  return;
}

// ===== ParticleSystemManager::initSprites  @0x001b43c8  (184 bytes)
/* ParticleSystemManager::initSprites() */

void __thiscall ParticleSystemManager::initSprites(ParticleSystemManager *this)

{
  ParticleSystemManager *pPVar1;
  short sVar2;
  uint uVar3;
  undefined4 *puVar4;
  code *pcVar5;
  short sVar6;
  float extraout_s1;
  float extraout_s3;
  undefined4 uVar7;
  undefined4 uVar8;
  
  if (*(int *)(this + 0x18) != 0) {
    pPVar1 = this + 0x30;
    *(uint *)pPVar1 = 0xffffffff;
    if (*(int *)(this + 0xc) != 0) {
      uVar3 = *(uint *)(this + 0x24);
      if ((uVar3 & 0xffff) == 0xffff) {
        if (uVar3 < 0xffff0000) {
          AbyssEngine::PaintCanvas::SpriteSystemCreate
                    (*(PaintCanvas **)(this + 4),*(ushort *)(this + 0x34),false,(uint *)pPVar1);
          AbyssEngine::PaintCanvas::TextureCreate
                    (*(PaintCanvas **)(this + 4),*(ushort *)(this + 0x26),(uint *)(this + 0x2c),
                     false);
        }
      }
      else {
        AbyssEngine::PaintCanvas::SpriteSystemCreate
                  (*(PaintCanvas **)(this + 4),*(ushort *)(this + 0x34),false,(ushort)uVar3,
                   (uint *)pPVar1);
      }
      AbyssEngine::PaintCanvas::SpriteSystemSetAllSize
                (*(PaintCanvas **)(this + 4),*(uint *)(this + 0x30),0);
      uVar7 = ParticleSettingsRef::cur._140_4_;
      uVar8 = ParticleSettingsRef::cur._144_4_;
      AbyssEngine::PaintCanvas::SpriteSystemSetAllUv
                (*(uint *)(this + 4),(float)ParticleSettingsRef::cur._140_4_,extraout_s1,
                 (float)ParticleSettingsRef::cur._144_4_,extraout_s3);
      if (*(int *)(this + 0x18) != 0) {
        uVar3 = 0;
        sVar6 = 0;
        do {
          puVar4 = *(undefined4 **)(*(int *)(this + 0x1c) + uVar3 * 4);
          pcVar5 = *(code **)*puVar4;
          (*pcVar5)(puVar4,*(undefined4 *)(this + 0x30),sVar6,pcVar5,uVar7,uVar8);
          sVar2 = IParticleSystem::getParticleCount
                            (*(IParticleSystem **)(*(int *)(this + 0x1c) + uVar3 * 4));
          sVar6 = sVar6 + sVar2;
          uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint *)(this + 0x18));
      }
    }
  }
  return;
}

// ===== ParticleSystemManager::initMesh  @0x001b4484  (180 bytes)
/* ParticleSystemManager::initMesh() */

void __thiscall ParticleSystemManager::initMesh(ParticleSystemManager *this)

{
  ParticleSystemManager *pPVar1;
  short sVar2;
  undefined4 *puVar3;
  uint uVar4;
  short sVar5;
  
  if (*(int *)(this + 0x3c) != 0) {
    pPVar1 = this + 0x54;
    *(undefined4 *)pPVar1 = 0xffffffff;
    *(uint *)(this + 0x58) = 0xffffffff;
    uVar4 = *(uint *)(this + 0x48) & 0xffff;
    if (uVar4 == 0xffff) {
      if (*(uint *)(this + 0x48) < 0xffff0000) {
        AbyssEngine::PaintCanvas::MeshCreate
                  (*(undefined4 *)(this + 4),(*(uint *)(this + 0x5c) & 0x3fff) << 2,
                   (*(uint *)(this + 0x5c) & 0x7fff) << 1,0x1b,pPVar1);
        AbyssEngine::PaintCanvas::TextureCreate
                  (*(PaintCanvas **)(this + 4),*(ushort *)(this + 0x4a),(uint *)(this + 0x50),false)
        ;
      }
    }
    else {
      AbyssEngine::PaintCanvas::MeshCreate
                (*(PaintCanvas **)(this + 4),(*(uint *)(this + 0x5c) & 0x3fff) << 2,
                 (*(uint *)(this + 0x5c) & 0x7fff) << 1,0x1b,uVar4,pPVar1);
    }
    AbyssEngine::PaintCanvas::TransformCreate(*(PaintCanvas **)(this + 4),(uint *)(this + 0x58));
    AbyssEngine::PaintCanvas::TransformAddMeshId
              (*(PaintCanvas **)(this + 4),*(uint *)(this + 0x58),*(uint *)(this + 0x54));
    if (*(int *)(this + 0x3c) != 0) {
      uVar4 = 0;
      sVar5 = 0;
      do {
        puVar3 = *(undefined4 **)(*(int *)(this + 0x40) + uVar4 * 4);
        (**(code **)*puVar3)(puVar3,*(undefined4 *)(this + 0x54),sVar5);
        sVar2 = (**(code **)(**(int **)(*(int *)(this + 0x40) + uVar4 * 4) + 0x10))();
        sVar5 = sVar5 + sVar2 * 4;
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(this + 0x3c));
    }
  }
  return;
}

// ===== ParticleSystemManager::update  @0x001b4538  (248 bytes)
/* ParticleSystemManager::update(long long) */

void ParticleSystemManager::update(longlong param_1)

{
  byte bVar1;
  int iVar2;
  IParticleSystem *pIVar3;
  int in_r2;
  uint uVar4;
  int iVar5;
  
  iVar2 = (int)param_1;
  if (*(char *)(iVar2 + 0x14) != '\0') {
    iVar5 = *(int *)(iVar2 + 0x10) + in_r2;
    *(int *)(iVar2 + 0x10) = iVar5;
    if (*(int *)(iVar2 + 0x18) != 0) {
      bVar1 = 0;
      uVar4 = 0;
      if (iVar5 < 10) {
        bVar1 = 1;
      }
      do {
        pIVar3 = *(IParticleSystem **)(*(int *)(iVar2 + 0x1c) + uVar4 * 4);
        if (pIVar3 != (IParticleSystem *)0x0) {
          IParticleSystem::update(pIVar3,in_r2);
          pIVar3 = *(IParticleSystem **)(*(int *)(iVar2 + 0x1c) + uVar4 * 4);
          if ((*(ushort *)(pIVar3 + 4) & 0xff) == 0) {
            if (!(bool)(*(ushort *)(pIVar3 + 4) < 0x100 & bVar1)) {
              IParticleSystem::calcEmitterVelocity(pIVar3,*(int *)(iVar2 + 0x10));
              pIVar3 = *(IParticleSystem **)(*(int *)(iVar2 + 0x1c) + uVar4 * 4);
            }
            (**(code **)(*(int *)pIVar3 + 4))();
          }
          else {
            IParticleSystem::resetEmitterVelocity(pIVar3);
          }
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(iVar2 + 0x18));
    }
    if (*(int *)(iVar2 + 0x3c) != 0) {
      bVar1 = 0;
      uVar4 = 0;
      if (iVar5 < 10) {
        bVar1 = 1;
      }
      do {
        pIVar3 = *(IParticleSystem **)(*(int *)(iVar2 + 0x40) + uVar4 * 4);
        if (pIVar3 != (IParticleSystem *)0x0) {
          IParticleSystem::update(pIVar3,in_r2);
          pIVar3 = *(IParticleSystem **)(*(int *)(iVar2 + 0x40) + uVar4 * 4);
          if ((*(ushort *)(pIVar3 + 4) & 0xff) == 0) {
            if (!(bool)(*(ushort *)(pIVar3 + 4) < 0x100 & bVar1)) {
              IParticleSystem::calcEmitterVelocity(pIVar3,*(int *)(iVar2 + 0x10));
              pIVar3 = *(IParticleSystem **)(*(int *)(iVar2 + 0x40) + uVar4 * 4);
            }
            (**(code **)(*(int *)pIVar3 + 4))();
          }
          else {
            IParticleSystem::resetEmitterVelocity(pIVar3);
          }
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(iVar2 + 0x3c));
    }
    if (9 < iVar5) {
      *(undefined4 *)(iVar2 + 0x10) = 0;
    }
  }
  return;
}

// ===== ParticleSystemManager::addSystem  @0x001b4630  (172 bytes)
/* ParticleSystemManager::addSystem(AbyssEngine::AEMath::Matrix const*,
   ParticleSettings::ParticleSet, bool) */

void __thiscall
ParticleSystemManager::addSystem
          (ParticleSystemManager *this,Matrix *param_1,int param_3,bool param_4)

{
  undefined4 *__ptr;
  int iVar1;
  undefined4 local_34;
  int *local_30;
  undefined4 local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  __ptr = operator_new__(4);
  *__ptr = 0;
  local_2c = 1;
  local_30 = realloc(__ptr,4);
  *local_30 = param_3;
  local_34 = 1;
  if ((*(uint *)(ParticleSettingsRef::cur + param_3 * 0x9c + 8) & 1) == 0) {
    if ((*(uint *)(ParticleSettingsRef::cur + param_3 * 0x9c + 8) & 2) == 0) goto LAB_001b46ba;
    iVar1 = addMeshSystem(this,param_1,(Array *)&local_34,param_4);
  }
  else {
    iVar1 = addSpriteSystem(this,param_1,(Array *)&local_34,param_4);
  }
  if ((ParticleSettingsRef::cur[param_3 * 0x9c + 0xb] & 1) != 0) {
    enableSystemUpdate(this,iVar1,false);
  }
LAB_001b46ba:
  if (local_30 != (int *)0x0) {
    operator_delete__(local_30);
  }
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

// ===== ParticleSystemManager::addSpriteSystem  @0x001b46f8  (92 bytes)
/* ParticleSystemManager::addSpriteSystem(AbyssEngine::AEMath::Matrix const*,
   Array<ParticleSettings::ParticleSet> const&, bool) */

int __thiscall
ParticleSystemManager::addSpriteSystem
          (ParticleSystemManager *this,Matrix *param_1,Array *param_2,bool param_3)

{
  ParticleSystemSprite *this_00;
  void *pvVar1;
  int iVar2;
  
  this_00 = operator_new(0x78);
  ParticleSystemSprite::ParticleSystemSprite
            (this_00,*(PaintCanvas **)(this + 4),param_1,param_2,param_3,(bool)this[0x38]);
  *(int *)(this + 0x20) = *(int *)(this + 0x18) + 1;
  pvVar1 = realloc(*(void **)(this + 0x1c),(*(int *)(this + 0x18) + 1) * 4);
  *(void **)(this + 0x1c) = pvVar1;
  *(ParticleSystemSprite **)((int)pvVar1 + *(int *)(this + 0x18) * 4) = this_00;
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(this + 0x20);
  iVar2 = IParticleSystem::getParticleCount((IParticleSystem *)this_00);
  *(int *)(this + 0x34) = iVar2 + *(int *)(this + 0x34);
  return *(int *)(this + 0x18) + -1;
}

// ===== ParticleSystemManager::addMeshSystem  @0x001b4762  (98 bytes)
/* ParticleSystemManager::addMeshSystem(AbyssEngine::AEMath::Matrix const*,
   Array<ParticleSettings::ParticleSet> const&, bool) */

uint __thiscall
ParticleSystemManager::addMeshSystem
          (ParticleSystemManager *this,Matrix *param_1,Array *param_2,bool param_3)

{
  ParticleSystemMesh *this_00;
  void *pvVar1;
  int iVar2;
  
  this_00 = operator_new(0xa0);
  ParticleSystemMesh::ParticleSystemMesh
            (this_00,*(PaintCanvas **)(this + 4),param_1,param_2,param_3,(bool)this[0x60]);
  *(int *)(this + 0x44) = *(int *)(this + 0x3c) + 1;
  pvVar1 = realloc(*(void **)(this + 0x40),(*(int *)(this + 0x3c) + 1) * 4);
  *(void **)(this + 0x40) = pvVar1;
  *(ParticleSystemMesh **)((int)pvVar1 + *(int *)(this + 0x3c) * 4) = this_00;
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(this + 0x44);
  iVar2 = (**(code **)(*(int *)this_00 + 0x10))(this_00);
  *(int *)(this + 0x5c) = iVar2 + *(int *)(this + 0x5c);
  return *(int *)(this + 0x3c) - 1U | 0x4000;
}

// ===== ParticleSystemManager::enableSystemUpdate  @0x001b47d2  (44 bytes)
/* ParticleSystemManager::enableSystemUpdate(int, bool) */

void __thiscall
ParticleSystemManager::enableSystemUpdate(ParticleSystemManager *this,int param_1,bool param_2)

{
  int iVar1;
  
  if (param_1 != -1) {
    if ((param_1 & 0x4000U) == 0) {
      iVar1 = *(int *)(this + 0x1c);
    }
    else {
      iVar1 = *(int *)(this + 0x40);
      param_1 = param_1 & 0x3fffbfff;
    }
    IParticleSystem::enableUpdate(*(IParticleSystem **)(iVar1 + param_1 * 4),param_2);
    return;
  }
  return;
}

// ===== ParticleSystemManager::setParticleSetByIndex  @0x001b47fc  (44 bytes)
/* ParticleSystemManager::setParticleSetByIndex(int, unsigned char) */

void __thiscall
ParticleSystemManager::setParticleSetByIndex(ParticleSystemManager *this,int param_1,uchar param_2)

{
  int iVar1;
  
  if (param_1 != -1) {
    if ((param_1 & 0x4000U) == 0) {
      iVar1 = *(int *)(this + 0x1c);
    }
    else {
      iVar1 = *(int *)(this + 0x40);
      param_1 = param_1 & 0x3fffbfff;
    }
    IParticleSystem::setParticleSetIndex(*(IParticleSystem **)(iVar1 + param_1 * 4),param_2);
    return;
  }
  return;
}

// ===== ParticleSystemManager::setParticleSetBySet  @0x001b4826  (44 bytes)
/* ParticleSystemManager::setParticleSetBySet(int, ParticleSettings::ParticleSet) */

void __thiscall
ParticleSystemManager::setParticleSetBySet
          (ParticleSystemManager *this,uint param_1,undefined4 param_3)

{
  int iVar1;
  
  if (param_1 != 0xffffffff) {
    if ((param_1 & 0x4000) == 0) {
      iVar1 = *(int *)(this + 0x1c);
    }
    else {
      iVar1 = *(int *)(this + 0x40);
      param_1 = param_1 & 0x3fffbfff;
    }
    IParticleSystem::setParticleSet(*(IParticleSystem **)(iVar1 + param_1 * 4),param_3);
    return;
  }
  return;
}

// ===== ParticleSystemManager::enableSystemEmit  @0x001b4850  (44 bytes)
/* ParticleSystemManager::enableSystemEmit(int, bool) */

void __thiscall
ParticleSystemManager::enableSystemEmit(ParticleSystemManager *this,int param_1,bool param_2)

{
  int iVar1;
  
  if (param_1 != -1) {
    if ((param_1 & 0x4000U) == 0) {
      iVar1 = *(int *)(this + 0x1c);
    }
    else {
      iVar1 = *(int *)(this + 0x40);
      param_1 = param_1 & 0x3fffbfff;
    }
    (*(code *)&LAB_00070fac)(*(undefined4 *)(iVar1 + param_1 * 4),param_2);
    return;
  }
  return;
}

// ===== ParticleSystemManager::enableSystemRender  @0x001b487a  (44 bytes)
/* ParticleSystemManager::enableSystemRender(int, bool) */

void __thiscall
ParticleSystemManager::enableSystemRender(ParticleSystemManager *this,int param_1,bool param_2)

{
  int iVar1;
  
  if (param_1 != -1) {
    if ((param_1 & 0x4000U) == 0) {
      iVar1 = *(int *)(this + 0x1c);
    }
    else {
      iVar1 = *(int *)(this + 0x40);
      param_1 = param_1 & 0x3fffbfff;
    }
    (*(code *)&LAB_00070fb8)(*(undefined4 *)(iVar1 + param_1 * 4),param_2);
    return;
  }
  return;
}

// ===== ParticleSystemManager::resetSystem  @0x001b48a4  (42 bytes)
/* ParticleSystemManager::resetSystem(int) */

void __thiscall ParticleSystemManager::resetSystem(ParticleSystemManager *this,int param_1)

{
  int iVar1;
  
  if (param_1 == -1) {
    return;
  }
  if ((param_1 & 0x4000U) == 0) {
    iVar1 = *(int *)(this + 0x1c);
  }
  else {
    iVar1 = *(int *)(this + 0x40);
    param_1 = param_1 & 0x3fffbfff;
  }
                    /* WARNING: Could not recover jumptable at 0x001b48cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(iVar1 + param_1 * 4) + 8))();
  return;
}

// ===== ParticleSystemManager::~ParticleSystemManager  @0x001b48ce  (48 bytes)
/* ParticleSystemManager::~ParticleSystemManager() */

ParticleSystemManager * __thiscall
ParticleSystemManager::~ParticleSystemManager(ParticleSystemManager *this)

{
  releaseSprites(this);
  *(undefined4 *)(this + 4) = 0;
  ArrayReleaseClasses<ParticleSystemMesh*>((Array *)(this + 0x3c));
  if (*(void **)(this + 0x40) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x40));
  }
  *(undefined4 *)(this + 0x40) = 0;
  if (*(void **)(this + 0x1c) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x1c));
  }
  *(undefined4 *)(this + 0x1c) = 0;
  return this;
}

// ===== ParticleSystemManager::release  @0x001b4916  (28 bytes)
/* ParticleSystemManager::release() */

void __thiscall ParticleSystemManager::release(ParticleSystemManager *this)

{
  releaseSprites(this);
  *(undefined4 *)(this + 4) = 0;
  ArrayReleaseClasses<ParticleSystemMesh*>((Array *)(this + 0x3c));
  return;
}

// ===== ParticleSystemManager::cameraToggle  @0x001b4930  (34 bytes)
/* ParticleSystemManager::cameraToggle(ParticleSettings::CameraSet) */

void __thiscall ParticleSystemManager::cameraToggle(ParticleSystemManager *this,int param_2)

{
  if (*(int *)(this + 0xc) != param_2) {
    *(int *)(this + 0xc) = param_2;
    releaseSprites(this);
    initSprites(this);
    return;
  }
  return;
}

// ===== ParticleSystemManager::releaseSprites  @0x001b4950  (38 bytes)
/* ParticleSystemManager::releaseSprites() */

void __thiscall ParticleSystemManager::releaseSprites(ParticleSystemManager *this)

{
  ArrayReleaseClasses<ParticleSystemSprite*>((Array *)(this + 0x18));
  if (*(uint *)(this + 0x30) == 0xffffffff) {
    return;
  }
  AbyssEngine::PaintCanvas::ReleaseSpriteSystemResource
            (*(PaintCanvas **)(this + 4),*(uint *)(this + 0x30));
  *(undefined4 *)(this + 0x30) = 0xffffffff;
  return;
}

// ===== ParticleSystemManager::render3d  @0x001b4976  (38 bytes)
/* ParticleSystemManager::render3d() */

void __thiscall ParticleSystemManager::render3d(ParticleSystemManager *this)

{
  if (this[0x14] != (ParticleSystemManager)0x0) {
    if (this[1] != (ParticleSystemManager)0x0) {
      renderMeshes(this);
    }
    if (*this != (ParticleSystemManager)0x0) {
      renderSprites(this);
      return;
    }
  }
  return;
}

// ===== ParticleSystemManager::renderMeshes  @0x001b499a  (50 bytes)
/* ParticleSystemManager::renderMeshes() */

void __thiscall ParticleSystemManager::renderMeshes(ParticleSystemManager *this)

{
  if (*(short *)(this + 0x48) != -1) {
    ParticleSystemMesh::render(*(PaintCanvas **)(this + 4),*(uint *)(this + 0x58));
    return;
  }
  if (*(short *)(this + 0x26) != -1) {
    ParticleSystemMesh::render
              (*(undefined4 *)(this + 4),*(undefined4 *)(this + 0x58),*(undefined4 *)(this + 0x50),
               *(undefined4 *)(this + 0x4c));
    return;
  }
  return;
}

// ===== ParticleSystemManager::renderSprites  @0x001b49c8  (50 bytes)
/* ParticleSystemManager::renderSprites() */

void __thiscall ParticleSystemManager::renderSprites(ParticleSystemManager *this)

{
  if ((*(uint *)(this + 0x24) & 0xffff) != 0xffff) {
    (*(code *)&LAB_0007103c)(*(undefined4 *)(this + 4),*(undefined4 *)(this + 0x30));
    return;
  }
  if (*(uint *)(this + 0x24) < 0xffff0000) {
    (*(code *)&LAB_00071048)
              (*(undefined4 *)(this + 4),*(undefined4 *)(this + 0x30),*(undefined4 *)(this + 0x2c),
               *(undefined4 *)(this + 0x28));
    return;
  }
  return;
}

// ===== ParticleSystemManager::renderPost3d  @0x001b49f6  (2 bytes)
/* ParticleSystemManager::renderPost3d() */

void ParticleSystemManager::renderPost3d(void)

{
  return;
}

// ===== ParticleSystemManager::reset  @0x001b49f8  (64 bytes)
/* ParticleSystemManager::reset() */

void __thiscall ParticleSystemManager::reset(ParticleSystemManager *this)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(this + 0x18);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      piVar1 = *(int **)(*(int *)(this + 0x1c) + uVar3 * 4);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))();
        uVar2 = *(uint *)(this + 0x18);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  uVar2 = *(uint *)(this + 0x3c);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      piVar1 = *(int **)(*(int *)(this + 0x40) + uVar3 * 4);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))();
        uVar2 = *(uint *)(this + 0x3c);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  return;
}

// ===== ParticleSystemManager::emitManual  @0x001b4abc  (74 bytes)
/* ParticleSystemManager::emitManual(int, AbyssEngine::AEMath::Vector const&, int,
   AbyssEngine::AEMath::Vector const&, float) */

void __thiscall
ParticleSystemManager::emitManual
          (ParticleSystemManager *this,int param_1,Vector *param_2,int param_3,Vector *param_4,
          float param_5)

{
  int iVar1;
  
  if (param_1 == -1) {
    return;
  }
  if ((param_1 & 0x4000U) == 0) {
    iVar1 = *(int *)(this + 0x1c);
  }
  else {
    iVar1 = *(int *)(this + 0x40);
    param_1 = param_1 & 0x3fffbfff;
  }
  IParticleSystem::emitManual
            (*(undefined4 *)(iVar1 + param_1 * 4),*(undefined4 *)param_2,
             *(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),param_3,param_4);
  return;
}

// ===== ParticleSystemManager::emitManual  @0x001b4b06  (74 bytes)
/* ParticleSystemManager::emitManual(int, AbyssEngine::AEMath::Vector const&, int, float) */

void __thiscall
ParticleSystemManager::emitManual
          (ParticleSystemManager *this,int param_1,Vector *param_2,int param_3,float param_4)

{
  int iVar1;
  
  if (param_1 == -1) {
    return;
  }
  if ((param_1 & 0x4000U) == 0) {
    iVar1 = *(int *)(this + 0x1c);
  }
  else {
    iVar1 = *(int *)(this + 0x40);
    param_1 = param_1 & 0x3fffbfff;
  }
  IParticleSystem::emitManual
            (*(undefined4 *)(iVar1 + param_1 * 4),*(undefined4 *)param_2,
             *(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),param_3,0);
  return;
}

// ===== ParticleSystemManager::systemSetMatrix  @0x001b4b50  (44 bytes)
/* ParticleSystemManager::systemSetMatrix(int, AbyssEngine::AEMath::Matrix const*) */

void ParticleSystemManager::systemSetMatrix(int param_1,Matrix *param_2)

{
  int iVar1;
  Matrix *in_r2;
  
  if (param_2 != (Matrix *)0xffffffff) {
    if (((uint)param_2 & 0x4000) == 0) {
      iVar1 = *(int *)(param_1 + 0x1c);
    }
    else {
      iVar1 = *(int *)(param_1 + 0x40);
      param_2 = (Matrix *)((uint)param_2 & 0x3fffbfff);
    }
    IParticleSystem::setMatrix(*(IParticleSystem **)(iVar1 + (int)param_2 * 4),in_r2);
    return;
  }
  return;
}

