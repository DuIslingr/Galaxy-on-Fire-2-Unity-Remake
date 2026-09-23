// Class: Level
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Level::Level  @0x000baf80  (350 bytes)
/* Level::Level(int) */

Level * __thiscall Level::Level(Level *this,int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar1 = 0;
  uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0xb4) = 0;
  *(undefined4 *)(this + 0xb8) = 0;
  *(undefined4 *)(this + 0xbc) = 0;
  *(undefined4 *)(this + 200) = 0;
  *(undefined4 *)(this + 0xcc) = 0;
  *(undefined4 *)(this + 0xd0) = 0;
  *(undefined4 *)(this + 0x18c) = 0;
  *(undefined4 *)(this + 400) = 0;
  *(undefined4 *)(this + 0x194) = 0;
  *(undefined4 *)(this + 0x1d0) = 0x3f800000;
  *(undefined4 *)(this + 0x1d4) = 0;
  *(undefined4 *)(this + 0x1d8) = uVar2;
  *(undefined4 *)(this + 0x1dc) = uVar3;
  *(undefined4 *)(this + 0x1e0) = uVar4;
  *(undefined4 *)(this + 0x1e4) = 0x3f800000;
  *(undefined4 *)(this + 0x1e8) = 0;
  *(undefined4 *)(this + 0x1ec) = uVar2;
  *(undefined4 *)(this + 0x1f0) = uVar3;
  *(undefined4 *)(this + 500) = uVar4;
  *(undefined8 *)(this + 0x1f8) = 0x3f800000;
  *(undefined8 *)(this + 0x200) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0x208) = 0x3f800000;
  *(undefined4 *)(this + 0x20c) = 0x3f800000;
  *(undefined4 *)(this + 0x210) = 0;
  *(undefined4 *)(this + 0x214) = uVar2;
  *(undefined4 *)(this + 0x218) = uVar3;
  *(undefined4 *)(this + 0x21c) = uVar4;
  *(undefined4 *)(this + 0x220) = 0x3f800000;
  *(undefined4 *)(this + 0x224) = 0;
  *(undefined4 *)(this + 0x228) = uVar2;
  *(undefined4 *)(this + 0x22c) = uVar3;
  *(undefined4 *)(this + 0x230) = uVar4;
  *(undefined8 *)(this + 0x234) = 0x3f800000;
  *(undefined8 *)(this + 0x23c) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0x244) = 0x3f800000;
  *(undefined4 *)(this + 0x248) = 0x3f800000;
  *(undefined4 *)(this + 0x24c) = 0;
  *(undefined4 *)(this + 0x250) = uVar2;
  *(undefined4 *)(this + 0x254) = uVar3;
  *(undefined4 *)(this + 600) = uVar4;
  *(undefined4 *)(this + 0x25c) = 0x3f800000;
  *(undefined4 *)(this + 0x260) = 0;
  *(undefined4 *)(this + 0x264) = uVar2;
  *(undefined4 *)(this + 0x268) = uVar3;
  *(undefined4 *)(this + 0x26c) = uVar4;
  *(undefined8 *)(this + 0x270) = 0x3f800000;
  *(undefined8 *)(this + 0x278) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0x280) = 0x3f800000;
  *(int *)(this + 0xc0) = param_1;
  *(undefined4 *)(this + 0xc) = 0xffffffff;
  *(undefined4 *)(this + 0x10) = 0xffffffff;
  *(undefined4 *)(this + 4) = 0xffffffff;
  *(undefined4 *)(this + 8) = 0xffffffff;
  *(undefined4 *)(this + 0xc4) = 0;
  *(undefined4 *)(this + 0xb0) = 0;
  *(undefined4 *)(this + 0x148) = 0;
  *(undefined4 *)(this + 0x140) = 0;
  *(undefined4 *)(this + 0x144) = 0;
  *(undefined4 *)(this + 0x150) = 0;
  *(undefined4 *)(this + 0x154) = 0;
  this[0x158] = (Level)0x0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = uVar2;
  *(undefined4 *)(this + 0x24) = uVar3;
  *(undefined4 *)(this + 0x28) = uVar4;
  *(undefined4 *)(this + 0x2d) = 0;
  *(undefined4 *)(this + 0x29) = 0;
  *(undefined4 *)(this + 0x90) = 0;
  *(undefined4 *)(this + 0x94) = uVar2;
  *(undefined4 *)(this + 0x98) = uVar3;
  *(undefined4 *)(this + 0x9c) = uVar4;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x88) = uVar2;
  *(undefined4 *)(this + 0x8c) = uVar3;
  *(undefined4 *)(this + 0x90) = uVar4;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x78) = uVar2;
  *(undefined4 *)(this + 0x7c) = uVar3;
  *(undefined4 *)(this + 0x80) = uVar4;
  __aeabi_memclr4(this + 0xd8,0x65);
  *(undefined4 *)(this + 0x16c) = uVar1;
  *(undefined4 *)(this + 0x170) = uVar2;
  *(undefined4 *)(this + 0x174) = uVar3;
  *(undefined4 *)(this + 0x178) = uVar4;
  *(undefined4 *)(this + 0x15c) = uVar1;
  *(undefined4 *)(this + 0x160) = uVar2;
  *(undefined4 *)(this + 0x164) = uVar3;
  *(undefined4 *)(this + 0x168) = uVar4;
  *(undefined4 *)(this + 0x180) = 0;
  *(undefined4 *)(this + 0x184) = 0;
  this[0x18a] = (Level)0x0;
  *(undefined2 *)(this + 0x188) = 0;
  *(undefined4 *)(this + 100) = 0xffffffff;
  *(undefined4 *)(this + 0x284) = 0xffffffff;
  *(undefined4 *)(this + 0x34) = 0xffffffff;
  *(undefined4 *)(this + 0x38) = 0xffffffff;
  *(undefined4 *)(this + 0x3c) = 0xffffffff;
  *(undefined4 *)(this + 0x48) = 0xffffffff;
  *(undefined4 *)(this + 0x4c) = 0xffffffff;
  *(undefined4 *)(this + 0x17c) = 0;
  *(undefined4 *)(this + 0xa0) = 0;
  *(undefined4 *)(this + 0xa4) = 0;
  *(undefined4 *)(this + 0xa8) = 0;
  this[0x69] = (Level)0x0;
  *(undefined4 *)(this + 0x6c) = 0;
  this[0x288] = (Level)0x0;
  this[0x289] = (Level)0x0;
  *(undefined4 *)(this + 0xac) = 0xffffffff;
  *(undefined4 *)(this + 0x28c) = 0;
  *(undefined4 *)(this + 0x290) = 0;
  *(undefined4 *)(this + 0x294) = 0;
  *(undefined2 *)(this + 0x29c) = 0;
  this[0x29e] = (Level)0x0;
  *(undefined4 *)(this + 0x1bc) = 0xffffffff;
  *(undefined4 *)(this + 0x1c0) = 0xffffffff;
  *(undefined4 *)(this + 0x1b4) = 0xffffffff;
  *(undefined4 *)(this + 0x1b8) = 0xffffffff;
  return this;
}

// ===== Level::~Level  @0x000bb0f0  (734 bytes)
/* Level::~Level() */

Level * __thiscall Level::~Level(Level *this)

{
  void *pvVar1;
  void *pvVar2;
  
  *(undefined4 *)(this + 4) = 0xffffffff;
  *(undefined4 *)(this + 8) = 0xffffffff;
  *(undefined4 *)(this + 0xc) = 0xffffffff;
  if (*(Objective **)(this + 0x28) != (Objective *)0x0) {
    pvVar1 = (void *)Objective::~Objective(*(Objective **)(this + 0x28));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x28) = 0;
  if (*(Objective **)(this + 0x2c) != (Objective *)0x0) {
    pvVar1 = (void *)Objective::~Objective(*(Objective **)(this + 0x2c));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x2c) = 0;
  if (*(BoundingVolume **)(this + 0xc4) != (BoundingVolume *)0x0) {
    pvVar1 = (void *)BoundingVolume::~BoundingVolume(*(BoundingVolume **)(this + 0xc4));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xc4) = 0;
  if (*(int **)(this + 0xd8) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0xd8) + 4))();
  }
  *(undefined4 *)(this + 0xd8) = 0;
  if (*(StarSystem **)(this + 0xec) != (StarSystem *)0x0) {
    pvVar1 = (void *)StarSystem::~StarSystem(*(StarSystem **)(this + 0xec));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xec) = 0;
  if (*(PlayerEgo **)(this + 0xf0) != (PlayerEgo *)0x0) {
    pvVar1 = (void *)PlayerEgo::~PlayerEgo(*(PlayerEgo **)(this + 0xf0));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xf0) = 0;
  if (*(Route **)(this + 0x180) != (Route *)0x0) {
    pvVar1 = (void *)Route::~Route(*(Route **)(this + 0x180));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x180) = 0;
  if (*(ParticleSystemManager **)(this + 0x80) != (ParticleSystemManager *)0x0) {
    pvVar1 = (void *)ParticleSystemManager::~ParticleSystemManager
                               (*(ParticleSystemManager **)(this + 0x80));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x80) = 0;
  if (*(ParticleSystemManager **)(this + 0x88) != (ParticleSystemManager *)0x0) {
    pvVar1 = (void *)ParticleSystemManager::~ParticleSystemManager
                               (*(ParticleSystemManager **)(this + 0x88));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x88) = 0;
  if (*(ParticleSystemManager **)(this + 0x74) != (ParticleSystemManager *)0x0) {
    pvVar1 = (void *)ParticleSystemManager::~ParticleSystemManager
                               (*(ParticleSystemManager **)(this + 0x74));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x74) = 0;
  if (*(ParticleSystemManager **)(this + 0x78) != (ParticleSystemManager *)0x0) {
    pvVar1 = (void *)ParticleSystemManager::~ParticleSystemManager
                               (*(ParticleSystemManager **)(this + 0x78));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x78) = 0;
  if (*(ParticleSystemManager **)(this + 0x7c) != (ParticleSystemManager *)0x0) {
    pvVar1 = (void *)ParticleSystemManager::~ParticleSystemManager
                               (*(ParticleSystemManager **)(this + 0x7c));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x7c) = 0;
  if (*(ParticleSystemManager **)(this + 0x90) != (ParticleSystemManager *)0x0) {
    pvVar1 = (void *)ParticleSystemManager::~ParticleSystemManager
                               (*(ParticleSystemManager **)(this + 0x90));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x90) = 0;
  if (*(ParticleSystemManager **)(this + 0x84) != (ParticleSystemManager *)0x0) {
    pvVar1 = (void *)ParticleSystemManager::~ParticleSystemManager
                               (*(ParticleSystemManager **)(this + 0x84));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x84) = 0;
  if (*(ParticleSystemManager **)(this + 0x98) != (ParticleSystemManager *)0x0) {
    pvVar1 = (void *)ParticleSystemManager::~ParticleSystemManager
                               (*(ParticleSystemManager **)(this + 0x98));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x98) = 0;
  if (*(ParticleSystemManager **)(this + 0x9c) != (ParticleSystemManager *)0x0) {
    pvVar1 = (void *)ParticleSystemManager::~ParticleSystemManager
                               (*(ParticleSystemManager **)(this + 0x9c));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x9c) = 0;
  if (*(Array **)(this + 0xa4) != (Array *)0x0) {
    ArrayReleaseClasses<AEGeometry*>(*(Array **)(this + 0xa4));
    pvVar1 = *(void **)(this + 0xa4);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0xa4) = 0;
  pvVar1 = *(void **)(this + 0xa8);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) == (void *)0x0) {
      *(undefined4 *)((int)pvVar1 + 4) = 0;
    }
    else {
      operator_delete__(*(void **)((int)pvVar1 + 4));
      pvVar2 = *(void **)(this + 0xa8);
      *(undefined4 *)((int)pvVar1 + 4) = 0;
      pvVar1 = pvVar2;
      if (pvVar2 == (void *)0x0) goto LAB_000bb270;
    }
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
LAB_000bb270:
  *(undefined4 *)(this + 0xa8) = 0;
  if (*(Array **)(this + 0xe4) != (Array *)0x0) {
    ArrayReleaseClasses<AbstractGun*>(*(Array **)(this + 0xe4));
    pvVar1 = *(void **)(this + 0xe4);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0xe4) = 0;
  if (*(Array **)(this + 0xe8) != (Array *)0x0) {
    ArrayReleaseClasses<AbstractGun*>(*(Array **)(this + 0xe8));
    pvVar1 = *(void **)(this + 0xe8);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0xe8) = 0;
  if (*(Array **)(this + 0xf8) != (Array *)0x0) {
    ArrayReleaseClasses<KIPlayer*>(*(Array **)(this + 0xf8));
    pvVar1 = *(void **)(this + 0xf8);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0xf8) = 0;
  if (*(Array **)(this + 0xfc) != (Array *)0x0) {
    ArrayReleaseClasses<KIPlayer*>(*(Array **)(this + 0xfc));
    pvVar1 = *(void **)(this + 0xfc);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0xfc) = 0;
  if (*(Array **)(this + 0xf4) != (Array *)0x0) {
    ArrayReleaseClasses<KIPlayer*>(*(Array **)(this + 0xf4));
    pvVar1 = *(void **)(this + 0xf4);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0xf4) = 0;
  if (*(Array **)(this + 0x100) != (Array *)0x0) {
    ArrayReleaseClasses<KIPlayer*>(*(Array **)(this + 0x100));
    pvVar1 = *(void **)(this + 0x100);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x100) = 0;
  if (*(Array **)(this + 0x114) != (Array *)0x0) {
    ArrayReleaseClasses<RadioMessage*>(*(Array **)(this + 0x114));
    pvVar1 = *(void **)(this + 0x114);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x114) = 0;
  if (*(Array **)(this + 0x104) != (Array *)0x0) {
    ArrayReleaseClasses<AEGeometry*>(*(Array **)(this + 0x104));
    pvVar1 = *(void **)(this + 0x104);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x104) = 0;
  if (*(LODManager **)this != (LODManager *)0x0) {
    pvVar1 = (void *)LODManager::~LODManager(*(LODManager **)this);
    operator_delete(pvVar1);
  }
  *(undefined4 *)this = 0;
  if (*(LodMeshMerger **)(this + 0xa0) != (LodMeshMerger *)0x0) {
    pvVar1 = (void *)LodMeshMerger::~LodMeshMerger(*(LodMeshMerger **)(this + 0xa0));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xa0) = 0;
  pvVar1 = *(void **)(this + 0xb0);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xb0) = 0;
  return this;
}

// ===== Level::setInitStreamOut  @0x000bb48c  (12 bytes)
/* Level::setInitStreamOut() */

void Level::setInitStreamOut(void)

{
  initStreamOutPosition = 1;
  return;
}

// ===== Level::init  @0x000bb49c  (1638 bytes)
/* Level::init() */

void __thiscall Level::init(Level *this)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  void *pvVar4;
  LODManager *this_00;
  ParticleSystemManager *pPVar5;
  SolarSystem *pSVar6;
  int iVar7;
  Mission *pMVar8;
  KIPlayer *this_01;
  uint *puVar9;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s0_02;
  float extraout_s0_03;
  float fVar13;
  float extraout_s1;
  float extraout_s1_00;
  float fVar14;
  float extraout_s1_01;
  float extraout_s2;
  float extraout_s2_00;
  float fVar15;
  float extraout_s2_01;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  float local_2c;
  float local_28;
  float local_24;
  int local_20;
  
  local_20 = __stack_chk_guard;
  iVar3 = *(int *)(this + 0x134);
  if (iVar3 == 0) {
    this[0x1b0] = (Level)0x0;
    this[0x68] = (Level)0x0;
    this[0x189] = (Level)0x0;
    this[0x18a] = (Level)0x0;
    if (*(Route **)(this + 0x108) != (Route *)0x0) {
      pvVar4 = (void *)Route::~Route(*(Route **)(this + 0x108));
      operator_delete(pvVar4);
    }
    *(undefined4 *)(this + 0x108) = 0;
    if (*(Route **)(this + 0x110) != (Route *)0x0) {
      pvVar4 = (void *)Route::~Route(*(Route **)(this + 0x110));
      operator_delete(pvVar4);
    }
    *(undefined4 *)(this + 0x110) = 0;
    if (*(Route **)(this + 0x10c) != (Route *)0x0) {
      pvVar4 = (void *)Route::~Route(*(Route **)(this + 0x10c));
      operator_delete(pvVar4);
    }
    *(undefined4 *)(this + 0x10c) = 0;
    if (*(Objective **)(this + 0x2c) != (Objective *)0x0) {
      pvVar4 = (void *)Objective::~Objective(*(Objective **)(this + 0x2c));
      operator_delete(pvVar4);
    }
    *(undefined4 *)(this + 0x2c) = 0;
    if (*(Objective **)(this + 0x28) != (Objective *)0x0) {
      pvVar4 = (void *)Objective::~Objective(*(Objective **)(this + 0x28));
      operator_delete(pvVar4);
    }
    *(undefined4 *)(this + 0x28) = 0;
    this_00 = operator_new(0x14);
    LODManager::LODManager(this_00);
    *(LODManager **)this = this_00;
    pPVar5 = operator_new(100);
    ParticleSystemManager::ParticleSystemManager(pPVar5,Globals::Canvas,1,0x4e85,0,0xffff,0);
    *(ParticleSystemManager **)(this + 0x78) = pPVar5;
    iVar3 = Status::inAlienOrbit(Globals::status);
    bVar2 = false;
    if (iVar3 == 0) {
      pSVar6 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar3 = SolarSystem::getTextureIndex(pSVar6);
      bVar2 = false;
      if (iVar3 == 0xc) {
        bVar2 = true;
      }
    }
    pPVar5 = operator_new(100);
    ParticleSystemManager::ParticleSystemManager(pPVar5,Globals::Canvas,1,0x6a72,0,0xffff,0);
    *(ParticleSystemManager **)(this + 0x84) = pPVar5;
    pPVar5 = operator_new(100);
    ParticleSystemManager::ParticleSystemManager(pPVar5,Globals::Canvas,1,0x4e83,1,0xffff,0);
    *(ParticleSystemManager **)(this + 0x74) = pPVar5;
    pPVar5 = operator_new(100);
    ParticleSystemManager::ParticleSystemManager(pPVar5,Globals::Canvas,1,0x4e7a,1,0x4e7a,1);
    *(ParticleSystemManager **)(this + 0x80) = pPVar5;
    pPVar5 = operator_new(100);
    ParticleSystemManager::ParticleSystemManager(pPVar5,Globals::Canvas,1,0x5e20,1,0x5e20,1);
    *(ParticleSystemManager **)(this + 0x98) = pPVar5;
    pPVar5 = operator_new(100);
    uVar10 = 0x4e7f;
    if (bVar2) {
      uVar10 = 0x4ea9;
    }
    ParticleSystemManager::ParticleSystemManager(pPVar5,Globals::Canvas,1,uVar10,1,0,0);
    *(ParticleSystemManager **)(this + 0x7c) = pPVar5;
    pPVar5 = operator_new(100);
    ParticleSystemManager::ParticleSystemManager(pPVar5,Globals::Canvas,1,0x4e7c,0,0x4e7c,0);
    *(ParticleSystemManager **)(this + 0x88) = pPVar5;
    pPVar5 = operator_new(100);
    ParticleSystemManager::ParticleSystemManager(pPVar5,Globals::Canvas,1,0x6a7c,1,0x6a7c,1);
    *(ParticleSystemManager **)(this + 0x8c) = pPVar5;
    pPVar5 = operator_new(100);
    ParticleSystemManager::ParticleSystemManager(pPVar5,Globals::Canvas,1,0x6ab9,1,0xffff,0);
    *(ParticleSystemManager **)(this + 0x9c) = pPVar5;
    pPVar5 = operator_new(100);
    ParticleSystemManager::ParticleSystemManager(pPVar5,Globals::Canvas,1,0x6aaf,1,0xffff,0);
    *(ParticleSystemManager **)(this + 0x94) = pPVar5;
    createSpace(this);
    if (*(int *)(this + 0xc0) == 3) {
      createPlayer(this);
      fVar13 = extraout_s0;
      fVar14 = extraout_s1;
      fVar15 = extraout_s2;
      if ((initStreamOutPosition == '\0') || (*(int *)(*(int *)(this + 0xf0) + 8) == 0)) {
LAB_000bb7b8:
        PlayerEgo::setPosition(fVar13,fVar14,fVar15);
      }
      else {
        iVar7 = Status::getStationStack(Globals::status);
        iVar3 = 0;
        if (iVar7 != 0) {
          iVar3 = *(int *)(*(int *)(iVar7 + 4) + 4);
        }
        if ((iVar7 == 0 || iVar3 == 0) || (iVar3 = Status::getSystem(Globals::status), iVar3 == 0))
        {
LAB_000bb78e:
          (**(code **)(**(int **)(*(int *)(*(int *)(this + 0x100) + 4) + 8) + 0x28))(&local_2c);
          fVar13 = extraout_s0_00;
          fVar14 = extraout_s1_00;
          fVar15 = extraout_s2_00;
          goto LAB_000bb7b8;
        }
        pSVar6 = (SolarSystem *)Status::getSystem(Globals::status);
        iVar3 = SolarSystem::currentOrbitHasWarpGate(pSVar6);
        if (iVar3 != 0) goto LAB_000bb78e;
        pSVar6 = (SolarSystem *)Status::getSystem(Globals::status);
        puVar9 = (uint *)SolarSystem::getStations(pSVar6);
        fVar13 = extraout_s0_02;
        if (*puVar9 != 0) {
          uVar11 = 0;
          do {
            iVar12 = *(int *)(puVar9[1] + uVar11 * 4);
            iVar3 = Station::getIndex(*(Station **)(*(int *)(iVar7 + 4) + 4));
            fVar13 = extraout_s0_03;
            if (iVar12 == iVar3) goto LAB_000bba62;
            uVar11 = uVar11 + 1;
          } while (uVar11 < *puVar9);
        }
        uVar11 = 0xffffffff;
LAB_000bba62:
        local_2c = 0.0;
        local_28 = 0.0;
        local_24 = 25000.0;
        if (-1 < (int)uVar11) {
          StarSystem::getPlanets(*(StarSystem **)(this + 0xec));
          AEGeometry::getPosition();
          fVar13 = (float)AbyssEngine::AEMath::Vector::operator=
                                    ((Vector *)&local_2c,(Vector *)&local_38);
        }
        AbyssEngine::AEMath::Vector::operator*=((Vector *)&local_2c,fVar13);
        PlayerEgo::setPosition(*(undefined4 *)(this + 0xf0),local_2c,local_28,local_24);
        local_2c = -local_2c;
        local_28 = -local_28;
        local_24 = -local_24;
        AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_38,(Vector *)&local_2c);
        AbyssEngine::AEMath::Vector::operator=((Vector *)&local_2c,(Vector *)&local_38);
        local_38 = 0;
        local_34 = 0x3f800000;
        local_30 = 0;
        AEGeometry::setDirection
                  (*(AEGeometry **)(*(int *)(this + 0xf0) + 8),(Vector *)&local_2c,
                   (Vector *)&local_38);
      }
      iVar3 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar3 == 1) {
        PlayerEgo::setPosition(extraout_s0_01,extraout_s1_01,extraout_s2_01);
      }
    }
    iVar3 = *(int *)(this + 0x134);
  }
  if (iVar3 != 1) {
    *(int *)(this + 0x134) = iVar3 + 1;
    uVar10 = 0;
    goto LAB_000bba0c;
  }
  if (*(int *)(this + 0xc0) != 4 && *(int *)(this + 0xc0) != 0x17) {
    createAsteroids(this);
    createGasClouds(this);
  }
  pMVar8 = (Mission *)Status::getMission(Globals::status);
  if (pMVar8 == (Mission *)0x0) {
    Status::setMission(Globals::status,Mission::empty);
  }
  iVar3 = *(int *)(this + 0xc0);
  if (iVar3 == 3) {
    iVar3 = Mission::isEmpty(pMVar8);
    if ((iVar3 == 0) && (iVar3 = Mission::isCampaignMission(pMVar8), iVar3 == 1)) {
      iVar3 = *(int *)(this + 0xc0);
      if (iVar3 != 3) goto LAB_000bb906;
      iVar3 = Status::gameWon(Globals::status);
      if ((iVar3 == 1) && (Globals::options[0x37] == '\0' && Globals::options[0x35] == '\0'))
      goto LAB_000bb86e;
      iVar3 = *(int *)(this + 0xc0);
      if (iVar3 != 3) goto LAB_000bb906;
      pMVar8 = (Mission *)Status::getMission(Globals::status);
      iVar3 = Mission::isEmpty(pMVar8);
      if (iVar3 == 0) {
        pMVar8 = (Mission *)Status::getMission(Globals::status);
        iVar3 = Mission::isCampaignMission(pMVar8);
        if (iVar3 == 1) {
          createCampaignMission(this);
        }
      }
    }
    else {
LAB_000bb86e:
      createMission(this);
      iVar3 = Status::inBlackMarketSystem(Globals::status);
      if ((initStreamOutPosition != '\0') && (iVar3 == 1)) {
        uVar10 = *(undefined4 *)(this + 0xf0);
        PlayerEgo::getPosition();
        local_38 = 0;
        local_34 = 0;
        local_30 = 0x471c4000;
        AbyssEngine::AEMath::operator+((AEMath *)&local_44,(Vector *)&local_2c,(Vector *)&local_38);
        PlayerEgo::setPosition(uVar10,local_44,uStack_40,uStack_3c);
      }
    }
  }
  else {
LAB_000bb906:
    createScene(this);
    *(int *)(this + 0xc0) = iVar3;
  }
  createStaticObjects(this);
  iVar3 = *(int *)(this + 0xc0);
  if ((iVar3 != 0x17 && iVar3 != 4) &&
     ((iVar3 != 2 || (iVar3 = Status::getCurrentCampaignMission(Globals::status), iVar3 != 0x2b))))
  {
    createSentryGuns(this);
    createFighterTurrets(this);
    createWingmen(this);
  }
  assignGuns(this);
  if (*(int *)(this + 0xc0) != 3) {
    *(undefined4 *)(this + 0xc0) = 3;
  }
  connectPlayers(this);
  if (*(PlayerEgo **)(this + 0xf0) != (PlayerEgo *)0x0) {
    PlayerEgo::setRoute(*(PlayerEgo **)(this + 0xf0),*(Route **)(this + 0x108));
  }
  puVar9 = *(uint **)(this + 0xf8);
  uVar10 = 0;
  iVar3 = 0;
  if (puVar9 != (uint *)0x0) {
    if (*puVar9 == 0) {
      iVar3 = 0;
    }
    else {
      uVar11 = 0;
      iVar3 = 0;
      do {
        this_01 = *(KIPlayer **)(puVar9[1] + uVar11 * 4);
        if (((this_01[0x3d] == (KIPlayer)0x0) && (this_01[0x6d] == (KIPlayer)0x0)) &&
           (this_01[0x3b] == (KIPlayer)0x0)) {
          iVar7 = KIPlayer::isWingMan(this_01);
          puVar9 = *(uint **)(this + 0xf8);
          if (((iVar7 == 0) &&
              (iVar7 = *(int *)(puVar9[1] + uVar11 * 4), *(char *)(iVar7 + 0x40) == '\0')) &&
             (uVar1 = *(ushort *)(iVar7 + 0x38), (uVar1 & 0xff) == 0)) {
            iVar3 = iVar3 + (uVar1 >> 8 ^ 1);
          }
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 < *puVar9);
      if (puVar9 == (uint *)0x0) {
        iVar3 = 0;
        goto LAB_000bb9de;
      }
    }
    iVar3 = iVar3 - *(int *)(this + 0x120);
  }
LAB_000bb9de:
  *(int *)(this + 0x118) = iVar3;
  *(undefined4 *)(this + 0x128) = 0;
  if (*(undefined4 **)(this + 0xfc) != (undefined4 *)0x0) {
    uVar10 = **(undefined4 **)(this + 0xfc);
  }
  *(undefined4 *)(this + 0x128) = uVar10;
  *(undefined4 *)(this + 0x184) = 0;
  this[0x188] = (Level)0x0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 300) = 0;
  this[0x13c] = (Level)0x0;
  uVar10 = 1;
  this[0x70] = (Level)0x1;
LAB_000bba0c:
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar10);
  }
  return;
}

// ===== Level::createSpace  @0x000bbba0  (3234 bytes)
/* Level::createSpace() */

void __thiscall Level::createSpace(Level *this)

{
  Level *pLVar1;
  AERandom *pAVar2;
  byte bVar3;
  short sVar4;
  int iVar5;
  PaintCanvas *pPVar6;
  Engine *this_00;
  Station *pSVar7;
  Array *pAVar8;
  undefined4 *puVar9;
  PlayerStation *this_01;
  void *pvVar10;
  SolarSystem *pSVar11;
  int iVar12;
  AEGeometry *pAVar13;
  PlayerJumpgate *this_02;
  int *piVar14;
  PlayerWormHole *this_03;
  int iVar15;
  StarSystem *this_04;
  ushort uVar16;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  int iVar17;
  float *pfVar18;
  uint uVar19;
  uint in_fpscr;
  float fVar20;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float fVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  longlong lVar26;
  undefined8 uVar27;
  uint local_108 [3];
  ushort local_fc [2];
  uint local_f8;
  uint local_f4 [15];
  uint local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined4 local_80;
  undefined8 local_78;
  float local_70;
  ushort local_68;
  undefined2 local_66;
  int local_64;
  
  local_64 = __stack_chk_guard;
  pLVar1 = this + 4;
  if (*(uint *)pLVar1 == 0xffffffff) {
    iVar5 = Status::inAlienOrbit(Globals::status);
    pPVar6 = Globals::Canvas;
    if (iVar5 == 1) {
      AbyssEngine::PaintCanvas::MeshCreate(Globals::Canvas,0x45bc,(uint *)(this + 8),false);
      AbyssEngine::PaintCanvas::TextureCreate(Globals::Canvas,0x2768,(uint *)(this + 0x19c),false);
      AbyssEngine::PaintCanvas::MeshCreate(Globals::Canvas,0x4592,(uint *)pLVar1,false);
      AbyssEngine::PaintCanvas::TextureCreate(Globals::Canvas,0x275b,(uint *)(this + 0x198),false);
    }
    else {
      pSVar11 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar5 = SolarSystem::getIndex(pSVar11);
      AbyssEngine::PaintCanvas::MeshCreate
                (pPVar6,(short)iVar5 +
                        ((short)((ulonglong)((longlong)iVar5 * 0x55555556) >> 0x20) -
                        (short)((longlong)iVar5 * 0x55555556 >> 0x3f)) * -3 + 0x45ba,
                 (uint *)(this + 8),false);
      pPVar6 = Globals::Canvas;
      pSVar11 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar5 = SolarSystem::getIndex(pSVar11);
      AbyssEngine::PaintCanvas::TextureCreate
                (pPVar6,(short)iVar5 +
                        ((short)((ulonglong)((longlong)iVar5 * 0x55555556) >> 0x20) -
                        (short)((longlong)iVar5 * 0x55555556 >> 0x3f)) * -3 + 0x2766,
                 (uint *)(this + 0x19c),false);
      iVar5 = Status::getCurrentCampaignMission(Globals::status);
      if ((iVar5 == 0) && (*(int *)(this + 0xc0) == 3)) {
        AbyssEngine::PaintCanvas::MeshCreate(Globals::Canvas,0x458b,(uint *)pLVar1,false);
        iVar5 = 0x198;
        uVar16 = 0x2754;
LAB_000bbf52:
        AbyssEngine::PaintCanvas::TextureCreate(Globals::Canvas,uVar16,(uint *)(this + iVar5),false)
        ;
      }
      else {
        iVar5 = Status::inSupernovaSystem(Globals::status);
        pPVar6 = Globals::Canvas;
        if (iVar5 == 1) {
          iVar5 = Status::getCurrentCampaignMission(Globals::status);
          if (iVar5 == 0x59) {
            AbyssEngine::PaintCanvas::MeshCreate(Globals::Canvas,0x458d,(uint *)pLVar1,false);
            uVar16 = 0x2756;
            pPVar6 = Globals::Canvas;
          }
          else {
            iVar5 = Status::getCurrentCampaignMission(Globals::status);
            if (iVar5 < 0x9e) {
              AbyssEngine::PaintCanvas::MeshCreate
                        (Globals::Canvas,0x45a0,(uint *)(this + 0xc),false);
              AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,(uint *)(this + 0x10));
              AbyssEngine::PaintCanvas::TransformAddMeshId
                        (Globals::Canvas,*(uint *)(this + 0x10),*(uint *)(this + 0xc));
              lVar26 = AbyssEngine::PaintCanvas::TransformGetTransform
                                 (Globals::Canvas,*(uint *)(this + 0x10));
              AbyssEngine::Transform::Update(lVar26,true);
              AbyssEngine::PaintCanvas::MeshCreate
                        (Globals::Canvas,0x45a1,(uint *)(this + 0x14),false);
              AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,(uint *)(this + 0x18));
              AbyssEngine::PaintCanvas::TransformAddMeshId
                        (Globals::Canvas,*(uint *)(this + 0x18),*(uint *)(this + 0x14));
              lVar26 = AbyssEngine::PaintCanvas::TransformGetTransform
                                 (Globals::Canvas,*(uint *)(this + 0x18));
              AbyssEngine::Transform::Update(lVar26,true);
              iVar5 = Status::getCurrentCampaignMission(Globals::status);
              if (iVar5 < 0x6a) {
                uVar16 = 0x2764;
              }
              else {
                uVar16 = 0x2765;
              }
              AbyssEngine::PaintCanvas::TextureCreate
                        (Globals::Canvas,uVar16,(uint *)(this + 0x1a0),false);
            }
            AbyssEngine::PaintCanvas::MeshCreate(Globals::Canvas,0x4597,(uint *)pLVar1,false);
            uVar16 = 0x2760;
            pPVar6 = Globals::Canvas;
          }
        }
        else {
          pSVar11 = (SolarSystem *)Status::getSystem(Globals::status);
          sVar4 = SolarSystem::getTextureIndex(pSVar11);
          AbyssEngine::PaintCanvas::MeshCreate(pPVar6,sVar4 + 0x4588,(uint *)pLVar1,false);
          pPVar6 = Globals::Canvas;
          pSVar11 = (SolarSystem *)Status::getSystem(Globals::status);
          sVar4 = SolarSystem::getTextureIndex(pSVar11);
          uVar16 = sVar4 + 0x2751;
        }
        AbyssEngine::PaintCanvas::TextureCreate(pPVar6,uVar16,(uint *)(this + 0x198),false);
        pSVar11 = (SolarSystem *)Status::getSystem(Globals::status);
        uVar19 = SolarSystem::getIndex(pSVar11);
        pSVar11 = (SolarSystem *)Status::getSystem(Globals::status);
        iVar5 = SolarSystem::getIndex(pSVar11);
        if ((uVar19 | 2) == 0x1a || iVar5 == 0x19) {
          this[0x289] = (Level)0x1;
          AbyssEngine::PaintCanvas::MeshCreate(Globals::Canvas,0x3827,(uint *)(this + 0x1cc),false);
          AbyssEngine::PaintCanvas::TextureCreate
                    (Globals::Canvas,0x8282,(uint *)(this + 0x1c4),false);
          AbyssEngine::PaintCanvas::TextureCreate
                    (Globals::Canvas,0x8283,(uint *)(this + 0x1c8),false);
        }
        iVar5 = Status::inPlanetRingOrbit(Globals::status);
        if (iVar5 == 1) {
          AbyssEngine::PaintCanvas::MeshCreate(Globals::Canvas,0x499f,&local_b8,false);
          AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,(uint *)(this + 0x1b4));
          AbyssEngine::PaintCanvas::TransformAddMeshId
                    (Globals::Canvas,*(uint *)(this + 0x1b4),local_b8);
          AbyssEngine::PaintCanvas::TextureCreate
                    (Globals::Canvas,0x715a,(uint *)(this + 0x1b8),false);
        }
        iVar5 = Status::inStormOrbit(Globals::status);
        if (iVar5 == 1) {
          AbyssEngine::PaintCanvas::MeshCreate(Globals::Canvas,0x49a0,&local_b8,false);
          AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,(uint *)(this + 0x1bc));
          AbyssEngine::PaintCanvas::TransformAddMeshId
                    (Globals::Canvas,*(uint *)(this + 0x1bc),local_b8);
          iVar5 = 0x1c0;
          uVar16 = 0x715b;
          goto LAB_000bbf52;
        }
      }
      pSVar11 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar5 = SolarSystem::getTextureIndex(pSVar11);
      if (0xf < iVar5) {
        this_00 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
        iVar5 = AbyssEngine::Engine::IsPostEffectActivated(this_00);
        if (iVar5 == 1) {
          iVar5 = AbyssEngine::PaintCanvas::MeshGetPointer(Globals::Canvas,*(uint *)pLVar1);
          *(undefined4 *)(iVar5 + 0x1c) = 0x3e6147ae;
        }
      }
    }
    iVar5 = Status::inFogSkyboxOrbit(Globals::status);
    pAVar2 = Globals::rnd;
    if (iVar5 == 1) {
      *(undefined4 *)(this + 0x1a4) = 0;
      *(undefined4 *)(this + 0x1a8) = 0;
      *(undefined4 *)(this + 0x1ac) = 0;
    }
    else {
      uVar27 = Status::getStation(Globals::status);
      uVar22 = (undefined4)((ulonglong)uVar27 >> 0x20);
      if ((int)uVar27 != 0) {
        pSVar7 = (Station *)Status::getStation(Globals::status);
        Station::getIndex(pSVar7);
        uVar22 = extraout_r1;
      }
      AbyssEngine::AERandom::setSeed(CONCAT44(uVar22,pAVar2));
      uVar22 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x10000);
      fVar20 = (float)VectorSignedToFloat(uVar22,(byte)(in_fpscr >> 0x16) & 3);
      *(float *)(this + 0x1a4) = fVar20 * 1.5258789e-05 * 6.2831855;
      uVar22 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x10000);
      fVar20 = (float)VectorSignedToFloat(uVar22,(byte)(in_fpscr >> 0x16) & 3);
      *(float *)(this + 0x1a8) = fVar20 * 1.5258789e-05 * 6.2831855;
      uVar22 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x10000);
      fVar20 = (float)VectorSignedToFloat(uVar22,(byte)(in_fpscr >> 0x16) & 3);
      *(float *)(this + 0x1ac) = fVar20 * 1.5258789e-05 * 6.2831855;
      AbyssEngine::AERandom::reset(Globals::rnd);
    }
  }
  iVar5 = *(int *)(this + 0xc0);
  if (iVar5 == 4 || iVar5 == 0x17) goto LAB_000bc738;
  if (comingFromAlienWorld == '\0') {
    pSVar7 = (Station *)Status::getStation(Globals::status);
    iVar5 = Station::isAttackedByAliens(pSVar7);
    if (iVar5 != 0) goto LAB_000bc09c;
    bVar3 = Status::inAlienOrbit(Globals::status);
  }
  else {
LAB_000bc09c:
    bVar3 = 1;
  }
  iVar5 = Status::getCurrentCampaignMission(Globals::status);
  if ((bVar3 & iVar5 < 0x2b) == 1) {
    Globals::addSoundResourceToList(Globals::globals,0x22);
  }
  pAVar8 = operator_new(0xc);
  puVar9 = operator_new__(4);
  *(undefined4 **)(pAVar8 + 4) = puVar9;
  *(undefined4 *)(pAVar8 + 8) = 1;
  *puVar9 = 0;
  *(undefined4 *)pAVar8 = 0;
  *(Array **)(this + 0x100) = pAVar8;
  ArraySetLength<KIPlayer*>(4,pAVar8);
  iVar5 = Status::inEmptyOrbit(Globals::status);
  if (iVar5 == 1) {
    iVar5 = Status::inAlienOrbit(Globals::status);
    if (iVar5 == 0) {
      pSVar7 = (Station *)Status::getStation(Globals::status);
      iVar5 = Station::getIndex(pSVar7);
      if (iVar5 != 0x1b) {
        pSVar7 = (Station *)Status::getStation(Globals::status);
        iVar5 = Station::getIndex(pSVar7);
        if (iVar5 != 0x6e) {
          pSVar7 = (Station *)Status::getStation(Globals::status);
          iVar5 = Station::getIndex(pSVar7);
          if (iVar5 != 0x6f) goto LAB_000bc1ec;
        }
      }
      goto LAB_000bc15a;
    }
LAB_000bc1ec:
    **(undefined4 **)(*(int *)(this + 0x100) + 4) = 0;
  }
  else {
LAB_000bc15a:
    this_01 = operator_new(0x170);
    pSVar7 = (Station *)Status::getStation(Globals::status);
    PlayerStation::PlayerStation(this_01,pSVar7);
    **(undefined4 **)(*(int *)(this + 0x100) + 4) = this_01;
    LODManager::addObject
              (*(LODManager **)this,*(AEGeometry **)(**(int **)(*(int *)(this + 0x100) + 4) + 0x13c)
              );
    iVar5 = Status::dlc1Won(Globals::status);
    if (iVar5 == 1) {
      pSVar7 = (Station *)Galaxy::getStation(Globals::galaxy,0x65);
      iVar5 = **(int **)(*(int *)(this + 0x100) + 4);
      Station::getName();
      AbyssEngine::String::operator=((String *)(iVar5 + 0x18),(String *)&local_b8);
      AbyssEngine::String::~String((String *)&local_b8);
      if (pSVar7 != (Station *)0x0) {
        pvVar10 = (void *)Station::~Station(pSVar7);
        operator_delete(pvVar10);
      }
    }
  }
  local_78 = *(ulonglong *)(this + 0x18c);
  local_70 = *(float *)(this + 0x194);
  *(undefined4 *)(this + 0x138) = 0;
  pAVar2 = Globals::rnd;
  uVar27 = Status::getStation(Globals::status);
  uVar22 = (undefined4)((ulonglong)uVar27 >> 0x20);
  if ((int)uVar27 != 0) {
    pSVar7 = (Station *)Status::getStation(Globals::status);
    Station::getIndex(pSVar7);
    uVar22 = extraout_r1_00;
  }
  AbyssEngine::AERandom::setSeed(CONCAT44(uVar22,pAVar2));
  puVar9 = (undefined4 *)((uint)&local_b8 | 4);
  uVar22 = 0;
  uVar23 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar24 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar25 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  iVar5 = 1;
LAB_000bc2e2:
  do {
    iVar15 = iVar5;
    if (iVar15 == 1) {
      iVar5 = Status::getSystem(Globals::status);
      if (iVar5 != 0) {
        pSVar11 = (SolarSystem *)Status::getSystem(Globals::status);
        iVar5 = SolarSystem::currentOrbitHasWarpGate(pSVar11);
        if (iVar5 != 0) goto LAB_000bc304;
      }
      piVar14 = *(int **)(*(int *)(*(int *)(this + 0x100) + 4) + 4);
      iVar5 = 2;
      if (piVar14 == (int *)0x0) goto LAB_000bc2e2;
      (**(code **)(*piVar14 + 4))();
      *(undefined4 *)(*(int *)(*(int *)(this + 0x100) + 4) + 4) = 0;
    }
    else {
LAB_000bc304:
      iVar5 = Status::getStation(Globals::status);
      if (iVar5 != 0) {
        iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
        iVar12 = AbyssEngine::AERandom::nextInt(Globals::rnd,500);
        iVar17 = iVar12 + 0xfa;
        if (iVar5 == 0) {
          iVar17 = -0xfa - iVar12;
        }
        iVar5 = *(int *)(this + 0x138) + iVar17 * 0x10;
        pfVar18 = (float *)&DAT_000bc968;
        fVar20 = (float)VectorSignedToFloat(iVar5,(byte)(in_fpscr >> 0x16) & 3);
        if (iVar15 == 1) {
          pfVar18 = (float *)&DAT_000bc96c;
        }
        fVar21 = *pfVar18;
        *(int *)(this + 0x138) = iVar5;
        fVar21 = fVar21 + fVar20 * 3.0;
        *(float *)(this + 0x194) = fVar21;
        local_b8 = 0x3f800000;
        *puVar9 = uVar22;
        puVar9[1] = uVar23;
        puVar9[2] = uVar24;
        puVar9[3] = uVar25;
        local_a4 = 0x3f800000;
        uStack_90 = 0x3f800000;
        uStack_88 = 0x3f8000003f800000;
        local_80 = 0x3f800000;
        local_a0 = uVar22;
        uStack_9c = uVar23;
        uStack_98 = uVar24;
        uStack_94 = uVar25;
        AbyssEngine::AEMath::MatrixSetRotation
                  ((AEMath *)local_f4,fVar21,extraout_s1,fVar20 * 1.5258789e-05 * 6.2831855);
        AbyssEngine::AEMath::MatrixRotateVector
                  ((AEMath *)local_f4,(Matrix *)&local_b8,(Vector *)(this + 0x18c));
        AbyssEngine::AEMath::Vector::operator=((Vector *)&local_78,(Vector *)local_f4);
        local_78 = local_78 & 0xffffffff;
      }
      iVar5 = Status::inAlienOrbit(Globals::status);
      if (iVar5 == 0) {
        pSVar11 = (SolarSystem *)Status::getSystem(Globals::status);
        iVar5 = SolarSystem::getRace(pSVar11);
      }
      else {
        iVar5 = 0;
      }
      pAVar13 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar13,(&DAT_00254360)[iVar5 * 4],Globals::Canvas,false);
      uVar19 = iVar5 << 2;
      local_f4[0] = 0xffffffff;
      AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,local_f4);
      AbyssEngine::PaintCanvas::TransformAddMesh
                (Globals::Canvas,local_f4[0],(&DAT_00254360)[uVar19 | 1],false);
      local_108[0] = 0xffffffff;
      AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,local_108);
      AbyssEngine::PaintCanvas::TransformAddMesh
                (Globals::Canvas,local_108[0],(&DAT_00254360)[uVar19 | 2],false);
      AEGeometry::addChild(pAVar13,local_f4[0]);
      AEGeometry::addChild(pAVar13,local_108[0]);
      this_02 = operator_new(0x144);
      PlayerJumpgate::PlayerJumpgate
                (this_02,0xf,pAVar13,local_78._4_4_,extraout_s1_00,local_70,SUB81(local_78,0));
      *(PlayerJumpgate **)(*(int *)(*(int *)(this + 0x100) + 4) + iVar15 * 4) = this_02;
      if (iVar15 == 2) {
        *(undefined4 *)(*(int *)(*(int *)(*(int *)(*(int *)(this + 0x100) + 4) + 8) + 4) + 0x40) = 0
        ;
      }
      local_f8 = 0xffffffff;
      AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,&local_f8);
      AbyssEngine::PaintCanvas::TransformAddMesh
                (Globals::Canvas,local_f8,(&DAT_00254360)[uVar19 | 3],false);
      PlayerJumpgate::addJumpAnimationHandle
                (*(PlayerJumpgate **)(*(int *)(*(int *)(this + 0x100) + 4) + iVar15 * 4),local_f8);
      local_66 = *(undefined2 *)((int)&DAT_00251fa0 + (iVar5 << 2 | 2U));
      local_68 = (&DAT_00251fa0)[iVar5 * 2];
      local_b4 = 70000;
      local_b8 = 40000;
      AEGeometry::setLodMeshes
                (*(AEGeometry **)(*(int *)(*(int *)(*(int *)(this + 0x100) + 4) + iVar15 * 4) + 8),
                 &local_68,(int *)&local_b8,2);
      LODManager::addObject
                (*(LODManager **)this,
                 *(AEGeometry **)(*(int *)(*(int *)(*(int *)(this + 0x100) + 4) + iVar15 * 4) + 8));
      if (iVar5 == 1) {
        local_fc[0] = 0x3ab0;
        local_fc[1] = 0x3ab1;
        AEGeometry::setLodChildMeshes
                  (*(AEGeometry **)(*(int *)(*(int *)(*(int *)(this + 0x100) + 4) + iVar15 * 4) + 8)
                   ,local_fc);
      }
    }
    iVar5 = iVar15 + 1;
  } while (iVar15 + 1 < 3);
  AbyssEngine::AERandom::reset(Globals::rnd);
  iVar5 = Status::inAlienOrbit(Globals::status);
  if (iVar5 != 0) {
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
    uVar22 = VectorSignedToFloat(iVar5 + -10000,(byte)(in_fpscr >> 0x16) & 3);
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,50000);
    local_b0 = VectorSignedToFloat("_ZN6AEFile18GetDeviceFreeSpaceEv" + iVar5 + 8,
                                   (byte)(in_fpscr >> 0x16) & 3);
    local_b8 = 0;
    piVar14 = *(int **)(*(int *)(*(int *)(this + 0x100) + 4) + 8);
    local_b4 = uVar22;
    (**(code **)(*piVar14 + 0x44))(piVar14,(Vector *)&local_b8);
    pAVar13 = *(AEGeometry **)(*(int *)(*(int *)(*(int *)(this + 0x100) + 4) + 8) + 8);
    AbyssEngine::AEMath::operator-((AEMath *)local_f4,(Vector *)&local_b8);
    local_108[0] = 0;
    local_108[1] = 0x3f800000;
    local_108[2] = 0;
    AEGeometry::setDirection(pAVar13,(Vector *)local_f4,(Vector *)local_108);
    *(undefined4 *)(this + 0x138) = 0;
  }
  iVar5 = Status::gameWon(Globals::status);
  if (iVar5 == 0) {
    this_03 = operator_new(0x160);
    pAVar13 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar13,0x4262,Globals::Canvas,false);
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,80000);
    uVar22 = VectorSignedToFloat(iVar5 + -40000,(byte)(in_fpscr >> 0x16) & 3);
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,40000);
    iVar15 = AbyssEngine::AERandom::nextInt(Globals::rnd,40000);
    fVar20 = (float)VectorSignedToFloat(iVar15 + 40000,(byte)(in_fpscr >> 0x16) & 3);
    fVar21 = (float)VectorSignedToFloat(iVar5 + -20000,(byte)(in_fpscr >> 0x16) & 3);
    PlayerWormHole::PlayerWormHole
              (this_03,0x4262,pAVar13,fVar20,extraout_s1_01,fVar21,SUB41(uVar22,0));
    *(PlayerWormHole **)(*(int *)(*(int *)(this + 0x100) + 4) + 0xc) = this_03;
    piVar14 = *(int **)(*(int *)(*(int *)(this + 0x100) + 4) + 0xc);
    (**(code **)(*piVar14 + 0x14))(piVar14,this);
  }
  *(int *)(this + 0x138) = *(int *)(this + 0x138) + 0x8000;
  if (initStreamOutPosition == '\0') {
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
    uVar22 = 0xfffff9c0;
    if (iVar5 == 0) {
      uVar22 = 0x640;
    }
    *(undefined4 *)(this + 0x138) = uVar22;
  }
  iVar5 = *(int *)(this + 0xc0);
LAB_000bc738:
  this_04 = operator_new(0x60);
  StarSystem::StarSystem(this_04,iVar5);
  *(StarSystem **)(this + 0xec) = this_04;
  puVar9 = (undefined4 *)Status::getSystem(Globals::status);
  if (puVar9 == (undefined4 *)0x0) {
    r = 10.0;
    b = 10.0;
    g = 136.0;
  }
  else {
    r = (float)VectorSignedToFloat(*puVar9,(byte)(in_fpscr >> 0x16) & 3);
    g = (float)VectorSignedToFloat(puVar9[1],(byte)(in_fpscr >> 0x16) & 3);
    b = (float)VectorSignedToFloat(puVar9[2],(byte)(in_fpscr >> 0x16) & 3);
  }
  r_min = (int)(r / 3.0);
  g_min = (int)(g / 3.0);
  b_min = (int)(b / 3.0);
  i_r = r;
  i_b = b;
  i_g = g;
  if (__stack_chk_guard != local_64) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Level::createPlayer  @0x000bca00  (1404 bytes)
/* Level::createPlayer() */

void __thiscall Level::createPlayer(Level *this)

{
  int iVar1;
  Ship *this_00;
  Ship *pSVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  Player *this_01;
  int iVar8;
  PlayerEgo *this_02;
  int iVar9;
  Array *pAVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  FileRead *this_03;
  Array *pAVar13;
  void *pvVar14;
  AEGeometry *this_04;
  int iVar15;
  int iVar16;
  float fVar17;
  float fVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  Gun *this_05;
  undefined4 uVar22;
  Array *pAVar23;
  Item *pIVar24;
  int *piVar25;
  uint in_fpscr;
  float fVar26;
  float fVar27;
  int local_5c;
  
  iVar1 = __stack_chk_guard;
  this_00 = (Ship *)Status::getShip(Globals::status);
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  puVar3 = (uint *)Ship::getEquipment(pSVar2);
  puVar4 = operator_new__(0xc);
  uVar5 = Ship::getUsedSlots(this_00,0);
  *puVar4 = uVar5;
  uVar6 = Ship::getUsedSlots(this_00,1);
  puVar4[1] = uVar6;
  uVar7 = Ship::getUsedSlots(this_00,2);
  puVar4[2] = uVar7;
  this_01 = operator_new(0x114);
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  iVar8 = Ship::getMaxHP(pSVar2);
  Player::Player(this_01,0x4b0,iVar8,uVar5,uVar6,uVar7);
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  iVar8 = Ship::getMaxShieldHP(pSVar2);
  Player::setMaxShieldHP(this_01,iVar8);
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  iVar8 = Ship::getMaxArmorHP(pSVar2);
  Player::setMaxArmorHP(this_01,iVar8);
  this_01[0x69] = (Player)0x1;
  this_02 = operator_new(0x3a0);
  PlayerEgo::PlayerEgo(this_02,this_01);
  *(PlayerEgo **)(this + 0xf0) = this_02;
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  iVar8 = Ship::getIndex(pSVar2);
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  iVar9 = Ship::getRace(pSVar2);
  PlayerEgo::setShip(this_02,iVar8,iVar9);
  PlayerEgo::setLevel(*(PlayerEgo **)(this + 0xf0),this);
  VectorSignedToFloat(*(undefined4 *)(this + 0x138),(byte)(in_fpscr >> 0x16) & 3);
  AEGeometry::setRotation(*(Vector **)(*(int *)(this + 0xf0) + 8));
  pAVar10 = operator_new(0xc);
  puVar11 = operator_new__(4);
  *(undefined4 **)(pAVar10 + 4) = puVar11;
  *puVar11 = 0;
  *(undefined4 *)(pAVar10 + 8) = 1;
  *(undefined4 *)pAVar10 = 0;
  ArraySetLength<Array<Gun*>*>(3,pAVar10);
  iVar8 = 0;
  while( true ) {
    if (0 < (int)uVar5) {
      puVar11 = operator_new(0xc);
      puVar12 = operator_new__(4);
      puVar11[1] = puVar12;
      puVar11[2] = 1;
      *puVar12 = 0;
      *puVar11 = 0;
      *(undefined4 **)(*(int *)(pAVar10 + 4) + iVar8 * 4) = puVar11;
      ArraySetLength<Gun*>(uVar5,*(Array **)(*(int *)(pAVar10 + 4) + iVar8 * 4));
    }
    if (2 < iVar8 + 1) break;
    uVar5 = puVar4[iVar8 + 1];
    iVar8 = iVar8 + 1;
  }
  if (puVar3 != (uint *)0x0) {
    this_03 = operator_new(1);
    FileRead::FileRead(this_03);
    pSVar2 = (Ship *)Status::getShip(Globals::status);
    iVar8 = Ship::getIndex(pSVar2);
    pAVar13 = (Array *)FileRead::loadWeaponPositions(this_03,iVar8);
    pvVar14 = (void *)FileRead::~FileRead(this_03);
    operator_delete(pvVar14);
    if (*(int *)(*(int *)(pAVar13 + 4) + 0xc) != 0) {
      puVar11 = operator_new(0xc);
      puVar12 = operator_new__(4);
      puVar11[1] = puVar12;
      puVar11[2] = 1;
      *puVar12 = 0;
      *puVar11 = 0;
      *(undefined4 **)(this + 0xa4) = puVar11;
      if (**(int **)(*(int *)(pAVar13 + 4) + 0xc) != 0) {
        uVar5 = 0;
        do {
          this_04 = operator_new(0xc0);
          AEGeometry::AEGeometry(this_04,Globals::Canvas);
          piVar25 = *(int **)(this + 0xa4);
          piVar25[2] = *piVar25 + 1;
          pvVar14 = realloc((void *)piVar25[1],(*piVar25 + 1) * 4);
          piVar25[1] = (int)pvVar14;
          *(AEGeometry **)((int)pvVar14 + *piVar25 * 4) = this_04;
          *piVar25 = piVar25[2];
          uVar6 = (uVar5 - ((int)uVar5 >> 0x1f)) * 2 & 0xfffffffc;
          AEGeometry::setPosition(*(Vector **)(*(int *)(*(int *)(this + 0xa4) + 4) + uVar6));
          AEGeometry::setScaling(*(Vector **)(*(int *)(*(int *)(this + 0xa4) + 4) + uVar6));
          uVar5 = uVar5 + 2;
        } while (uVar5 < **(uint **)(*(int *)(pAVar13 + 4) + 0xc));
      }
    }
    if (*puVar3 != 0) {
      iVar8 = 0;
      uVar5 = 0;
      do {
        if ((*(Item **)(puVar3[1] + iVar8) != (Item *)0x0) &&
           (iVar9 = Item::isWeapon(*(Item **)(puVar3[1] + iVar8)), iVar9 == 1)) {
          iVar9 = Item::getType(*(Item **)(puVar3[1] + iVar8));
          if (iVar9 == 1) {
            iVar9 = Item::getAmount(*(Item **)(puVar3[1] + iVar8));
          }
          else {
            iVar9 = -1;
          }
          local_5c = Item::getAttribute(*(Item **)(puVar3[1] + iVar8),9);
          iVar15 = Item::getAttribute(*(Item **)(puVar3[1] + iVar8),0xb);
          iVar16 = Item::getType(*(Item **)(puVar3[1] + iVar8));
          if (iVar16 == 0) {
            pSVar2 = (Ship *)Status::getShip(Globals::status);
            fVar17 = (float)Ship::getDamageFactor(pSVar2);
            if ((9 < local_5c) || (in_fpscr = in_fpscr & 0xfffffff, 0.0 <= fVar17)) {
              fVar27 = (float)VectorSignedToFloat(local_5c,(byte)(in_fpscr >> 0x16) & 3);
              fVar26 = (float)VectorSignedToFloat(iVar15,(byte)(in_fpscr >> 0x16) & 3);
              pSVar2 = (Ship *)Status::getShip(Globals::status);
              fVar18 = (float)Ship::getFireRateFactor(pSVar2);
              local_5c = (int)(fVar27 * fVar17);
              fVar26 = fVar26 * fVar18;
            }
            else {
              pSVar2 = (Ship *)Status::getShip(Globals::status);
              fVar17 = (float)Ship::getFireRateFactor(pSVar2);
              fVar26 = (float)VectorSignedToFloat(iVar15,(byte)(in_fpscr >> 0x16) & 3);
              fVar26 = fVar26 * fVar17 * 0.7;
            }
            iVar15 = (int)fVar26;
          }
          iVar16 = Item::getIndex(*(Item **)(puVar3[1] + iVar8));
          iVar19 = Item::getSort(*(Item **)(puVar3[1] + iVar8));
          iVar20 = Item::getAttribute(*(Item **)(puVar3[1] + iVar8),0xc);
          iVar21 = Item::getAttribute(*(Item **)(puVar3[1] + iVar8),0xd);
          this_05 = (Gun *)createGun(this,iVar16,uVar5,iVar19,iVar9,local_5c,iVar15,iVar20,iVar21);
          uVar22 = Item::getIndex(*(Item **)(puVar3[1] + iVar8));
          *(undefined4 *)(this_05 + 0x58) = uVar22;
          uVar22 = Item::getSort(*(Item **)(puVar3[1] + iVar8));
          *(undefined4 *)(this_05 + 0x5c) = uVar22;
          iVar9 = Item::getAttribute(*(Item **)(puVar3[1] + iVar8),0xe);
          Gun::setMagnitude(this_05,iVar9);
          iVar9 = Item::getType(*(Item **)(puVar3[1] + iVar8));
          if (iVar9 == 2) {
            uVar6 = puVar4[2];
            iVar9 = *(int *)(*(int *)(pAVar10 + 4) + 8);
            puVar4[2] = uVar6 - 1;
            *(Gun **)(*(int *)(iVar9 + 4) + (uVar6 - 1) * 4) = this_05;
            puVar11 = (undefined4 *)**(undefined4 **)(*(int *)(*(int *)(pAVar13 + 4) + 8) + 4);
            PlayerEgo::setTurretPosition
                      (*(undefined4 *)(this + 0xf0),*puVar11,puVar11[1],puVar11[2]);
          }
          else {
            if (iVar9 == 1) {
              uVar6 = puVar4[1];
              iVar9 = *(int *)(*(int *)(pAVar10 + 4) + 4);
              puVar4[1] = uVar6 - 1;
              *(Gun **)(*(int *)(iVar9 + 4) + (uVar6 - 1) * 4) = this_05;
              pIVar24 = *(Item **)(puVar3[1] + iVar8);
              iVar9 = *(int *)(*(int *)(pAVar13 + 4) + 4);
            }
            else {
              if (iVar9 != 0) goto LAB_000bcede;
              uVar6 = *puVar4;
              iVar9 = **(int **)(pAVar10 + 4);
              *puVar4 = uVar6 - 1;
              *(Gun **)(*(int *)(iVar9 + 4) + (uVar6 - 1) * 4) = this_05;
              pIVar24 = *(Item **)(puVar3[1] + iVar8);
              iVar9 = **(int **)(pAVar13 + 4);
            }
            iVar15 = Ship::getSlotPos(this_00,pIVar24);
            Gun::setOffset(this_05,*(Vector **)(*(int *)(iVar9 + 4) + iVar15 * 4));
          }
        }
LAB_000bcede:
        iVar8 = iVar8 + 4;
        uVar5 = uVar5 + 1;
      } while (uVar5 < *puVar3);
    }
    if (pAVar13 != (Array *)0x0) {
      uVar5 = *(uint *)pAVar13;
      if (uVar5 != 0) {
        uVar6 = 0;
        do {
          pAVar23 = *(Array **)(*(int *)(pAVar13 + 4) + uVar6 * 4);
          if (pAVar23 != (Array *)0x0) {
            ArrayReleaseClasses<AbyssEngine::AEMath::Vector*>(pAVar23);
            iVar8 = *(int *)(pAVar13 + 4);
            pvVar14 = *(void **)(iVar8 + uVar6 * 4);
            if (pvVar14 != (void *)0x0) {
              if (*(void **)((int)pvVar14 + 4) != (void *)0x0) {
                operator_delete__(*(void **)((int)pvVar14 + 4));
              }
              operator_delete(pvVar14);
              iVar8 = *(int *)(pAVar13 + 4);
            }
            *(undefined4 *)(iVar8 + uVar6 * 4) = 0;
            uVar5 = *(uint *)pAVar13;
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar5);
      }
      ArrayReleaseClasses<Array<AbyssEngine::AEMath::Vector*>*>(pAVar13);
      if (*(void **)(pAVar13 + 4) != (void *)0x0) {
        operator_delete__(*(void **)(pAVar13 + 4));
      }
      operator_delete(pAVar13);
    }
  }
  uVar5 = *(uint *)pAVar10;
  if (uVar5 != 0) {
    uVar6 = 0;
    do {
      pAVar13 = *(Array **)(*(int *)(pAVar10 + 4) + uVar6 * 4);
      if (pAVar13 != (Array *)0x0) {
        PlayerEgo::addGun(*(PlayerEgo **)(this + 0xf0),pAVar13,uVar6);
        uVar5 = *(uint *)pAVar10;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar5);
  }
  operator_delete__(puVar4);
  if (__stack_chk_guard == iVar1) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== Level::createAsteroids  @0x000bcfd0  (1722 bytes)
/* Level::createAsteroids() */

void __thiscall Level::createAsteroids(Level *this)

{
  bool bVar1;
  ushort uVar2;
  Galaxy *this_00;
  AERandom *pAVar3;
  int iVar4;
  SolarSystem *this_01;
  undefined4 *puVar5;
  undefined4 *puVar6;
  Station *pSVar7;
  void *pvVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  Waypoint *this_02;
  BoundingSphere *this_03;
  uint uVar14;
  AEGeometry *this_04;
  PlayerAsteroid *this_05;
  int *piVar15;
  uint uVar16;
  uint in_fpscr;
  float extraout_s0;
  float fVar17;
  float extraout_s0_00;
  float extraout_s1;
  float extraout_s2;
  float extraout_s3;
  float extraout_s4;
  float extraout_s5;
  float extraout_s6;
  float fVar18;
  int local_b4;
  int local_a8;
  int local_98;
  float local_80;
  float local_7c;
  float local_78;
  short local_74;
  short local_72;
  short local_70;
  undefined8 local_68;
  undefined4 local_60;
  int local_5c;
  
  local_5c = __stack_chk_guard;
  iVar4 = Status::inAlienOrbit(Globals::status);
  local_a8 = 0;
  if (iVar4 == 0) {
    this_01 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar4 = SolarSystem::getIndex(this_01);
    local_a8 = 0;
    if (iVar4 == 0x16) {
      local_a8 = 2;
    }
  }
  puVar5 = operator_new(0xc);
  puVar6 = operator_new__(4);
  puVar5[1] = puVar6;
  puVar5[2] = 1;
  *puVar6 = 0;
  *puVar5 = 0;
  *(undefined4 **)(this + 0xfc) = puVar5;
  this_00 = Globals::galaxy;
  pSVar7 = (Station *)Status::getStation(Globals::status);
  pvVar8 = (void *)Galaxy::getAsteroidProbabilities(this_00,pSVar7);
  pAVar3 = Globals::rnd;
  pSVar7 = (Station *)Status::getStation(Globals::status);
  uVar9 = Station::getIndex(pSVar7);
  AbyssEngine::AERandom::setSeed(CONCAT44(uVar9,pAVar3));
  iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x28);
  ArraySetLength<KIPlayer*>(iVar4 + 0x28,*(Array **)(this + 0xfc));
  iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,100000);
  iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,100000);
  iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,100000);
  iVar12 = Status::inAlienOrbit(Globals::status);
  iVar13 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar12 == 1) {
    iVar10 = 0;
    iVar4 = -30000;
    if (iVar13 == 0x9a) {
      iVar4 = -70000;
    }
    uVar16 = 30000;
    goto LAB_000bd1fa;
  }
  if (iVar13 == 0x72) {
    pSVar7 = (Station *)Status::getStation(Globals::status);
    iVar12 = Station::getIndex(pSVar7);
    if (iVar12 != 0x53) goto LAB_000bd11e;
    uVar16 = 0x3880;
    iVar4 = 30000;
LAB_000bd1bc:
    iVar10 = 0;
    uVar16 = uVar16 | 0x10000;
  }
  else {
LAB_000bd11e:
    iVar12 = Status::getCurrentCampaignMission(Globals::status);
    if ((iVar12 == 0x59) && (iVar12 = Status::inSupernovaOrbit(Globals::status), iVar12 != 0)) {
      uVar16 = 0xffff3cb0;
      iVar4 = -100000;
      iVar10 = 0;
      goto LAB_000bd1fa;
    }
    iVar12 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar12 == 0x5b) {
      pSVar7 = (Station *)Status::getStation(Globals::status);
      iVar12 = Station::getIndex(pSVar7);
      if (iVar12 == 0x6e) {
        iVar4 = 60000;
        iVar10 = 0;
        uVar16 = 50000;
        goto LAB_000bd1fa;
      }
    }
    iVar12 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar12 == 0x91) {
      pSVar7 = (Station *)Status::getStation(Globals::status);
      iVar12 = Station::getIndex(pSVar7);
      if (iVar12 == 0x70) {
        uVar16 = 0x1170;
        iVar4 = 50000;
        goto LAB_000bd1bc;
      }
    }
    iVar4 = iVar4 + -50000;
    iVar10 = iVar10 + -50000;
    uVar16 = iVar11 + 20000;
    iVar11 = Status::getCurrentCampaignMission(Globals::status);
    if ((iVar11 == 0) && (*(int *)(this + 0xc0) == 3)) {
      iVar4 = 0;
      iVar10 = 0;
      uVar16 = 0;
    }
  }
LAB_000bd1fa:
  AbyssEngine::AERandom::reset(Globals::rnd);
  local_80 = (float)VectorSignedToFloat(iVar4,(byte)(in_fpscr >> 0x16) & 3);
  local_7c = (float)VectorSignedToFloat(iVar10,(byte)(in_fpscr >> 0x16) & 3);
  local_78 = (float)VectorSignedToFloat(uVar16,(byte)(in_fpscr >> 0x16) & 3);
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 200),(Vector *)&local_80);
  this_02 = operator_new(0x134);
  Waypoint::Waypoint(this_02,iVar4,iVar10,uVar16,(Route *)0x0);
  *(Waypoint **)(this + 0xd8) = this_02;
  this_03 = operator_new(0x48);
  BoundingSphere::BoundingSphere
            (this_03,extraout_s0,extraout_s1,extraout_s2,extraout_s3,extraout_s4,extraout_s5,
             extraout_s6);
  *(BoundingSphere **)(this + 0xc4) = this_03;
  iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,8);
  iVar10 = Status::inAlienOrbit(Globals::status);
  local_80 = 0.0;
  local_7c = 0.0;
  local_b4 = 0;
  local_78 = 0.0;
  if (**(int **)(this + 0xfc) != 0) {
    iVar4 = iVar4 + 2;
    local_98 = 0x9a;
    uVar16 = 0;
    do {
      if (iVar10 == 0) {
        bVar1 = false;
        iVar11 = local_b4;
        while (local_b4 = iVar11, !bVar1) {
          iVar12 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
          bVar1 = false;
          iVar11 = 0;
          if (iVar12 < *(int *)((int)pvVar8 + local_b4 * 4 + 4)) {
            local_98 = *(int *)((int)pvVar8 + local_b4 * 4);
            bVar1 = local_98 < 0xa4 || local_98 == 0xd9;
            iVar11 = local_b4 + 2;
            if (10 < local_b4 + 2) {
              iVar11 = 0;
            }
          }
        }
      }
      else {
        local_98 = 0xa4;
      }
      uVar14 = 100000;
      if ((int)uVar16 < iVar4) {
        uVar14 = 60000;
      }
      fVar18 = (float)VectorSignedToFloat(uVar14 >> 1,(byte)(in_fpscr >> 0x16) & 3);
      iVar12 = Status::inAlienOrbit(Globals::status);
      iVar11 = local_a8;
      if (iVar12 != 0) {
        iVar11 = 1;
      }
      if (local_98 == 0xd9) {
        iVar11 = 3;
      }
      iVar12 = *(int *)(&UNK_00251fb0 + iVar11 * 4);
      do {
        fVar17 = *(float *)(this + 200);
        uVar9 = AbyssEngine::AERandom::nextInt(Globals::rnd,uVar14);
        local_80 = (float)VectorSignedToFloat(uVar9,(byte)(in_fpscr >> 0x16) & 3);
        local_80 = (fVar17 - fVar18) + local_80;
        fVar17 = *(float *)(this + 0xcc);
        uVar9 = AbyssEngine::AERandom::nextInt(Globals::rnd,uVar14);
        local_7c = (float)VectorSignedToFloat(uVar9,(byte)(in_fpscr >> 0x16) & 3);
        local_7c = (fVar17 - fVar18) + local_7c;
        fVar17 = *(float *)(this + 0xd0);
        uVar9 = AbyssEngine::AERandom::nextInt(Globals::rnd,uVar14);
        local_78 = (float)VectorSignedToFloat(uVar9,(byte)(in_fpscr >> 0x16) & 3);
        local_78 = (fVar17 - fVar18) + local_78;
        if ((int)uVar16 < 1 || (int)uVar16 >= iVar4) break;
        iVar13 = 0;
        bVar1 = false;
        do {
          (**(code **)(**(int **)(*(int *)(*(int *)(this + 0xfc) + 4) + iVar13 * 4) + 0x28))
                    ((Vector *)&local_74);
          AbyssEngine::AEMath::operator-
                    ((AEMath *)&local_68,(Vector *)&local_74,(Vector *)&local_80);
          fVar17 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_68);
          iVar13 = iVar13 + 1;
          bVar1 = (bool)(bVar1 | 8000 < (int)fVar17);
          if ((int)uVar16 <= iVar13) break;
        } while ((int)fVar17 < 0x1f41);
      } while (!bVar1);
      this_04 = operator_new(0xc0);
      uVar2 = (ushort)iVar12;
      AEGeometry::AEGeometry(this_04,uVar2,Globals::Canvas,false);
      local_74 = uVar2 + 1;
      local_72 = uVar2 + 2;
      local_70 = uVar2 + 3;
      if (Globals::iPad == '\0') {
        if ((int)uVar16 < iVar4) {
          local_60 = 120000;
          local_68 = 0x186a00000ea60;
          AEGeometry::setLodMeshes(this_04,(ushort *)&local_74,(int *)&local_68,3);
          LODManager::addObject(*(LODManager **)this,this_04);
          goto LAB_000bd564;
        }
        local_60 = 90000;
        local_68 = 0x1117000009c40;
        AEGeometry::setLodMeshes(this_04,(ushort *)&local_74,(int *)&local_68,3);
        LODManager::addObject(*(LODManager **)this,this_04);
LAB_000bd596:
        iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x46);
        iVar13 = iVar13 + 0x1e;
      }
      else {
        local_60 = 150000;
        local_68 = 0x1d4c0000186a0;
        AEGeometry::setLodMeshes(this_04,(ushort *)&local_74,(int *)&local_68,3);
        LODManager::addObject(*(LODManager **)this,this_04);
        if (iVar4 <= (int)uVar16) goto LAB_000bd596;
LAB_000bd564:
        iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
        iVar13 = iVar13 + 0x78;
      }
      fVar18 = (float)VectorSignedToFloat(iVar13,(byte)(in_fpscr >> 0x16) & 3);
      fVar18 = fVar18 * 0.01;
      in_fpscr = in_fpscr & 0xfffffff;
      if ((((0.4 <= fVar18) && (0.7 <= fVar18)) && (0.92 <= fVar18)) &&
         (iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,2), iVar13 != 0)) {
        AbyssEngine::AERandom::nextInt(Globals::rnd,3);
      }
      this_05 = operator_new(0x16c);
      PlayerAsteroid::PlayerAsteroid
                (this_05,iVar12,this_04,iVar11,local_98,(Vector *)&local_80,extraout_s0_00,
                 (int)fVar18);
      *(PlayerAsteroid **)(*(int *)(*(int *)(this + 0xfc) + 4) + uVar16 * 4) = this_05;
      piVar15 = *(int **)(*(int *)(*(int *)(this + 0xfc) + 4) + uVar16 * 4);
      (**(code **)(*piVar15 + 0x14))(piVar15,this);
      PlayerAsteroid::setAsteroidCenter
                (*(undefined4 *)(*(int *)(*(int *)(this + 0xfc) + 4) + uVar16 * 4),
                 *(undefined4 *)(this + 200),*(undefined4 *)(this + 0xcc),
                 *(undefined4 *)(this + 0xd0));
      uVar16 = uVar16 + 1;
    } while (uVar16 < **(uint **)(this + 0xfc));
  }
  if (pvVar8 != (void *)0x0) {
    operator_delete__(pvVar8);
  }
  if (__stack_chk_guard == local_5c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== Level::createGasClouds  @0x000bd750  (706 bytes)
/* Level::createGasClouds() */

void __thiscall Level::createGasClouds(Level *this)

{
  uint uVar1;
  byte bVar2;
  bool bVar3;
  Galaxy *this_00;
  Station *pSVar4;
  int *piVar5;
  Ship *this_01;
  int iVar6;
  SolarSystem *pSVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  AEGeometry *this_02;
  PlayerGasCloud *this_03;
  int *piVar11;
  uint in_fpscr;
  float fVar12;
  float fVar13;
  float fVar14;
  uint local_58;
  AEMath aAStack_54 [12];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  
  this_00 = Globals::galaxy;
  local_3c = __stack_chk_guard;
  pSVar4 = (Station *)Status::getStation(Globals::status);
  piVar5 = (int *)Galaxy::getPlasmaProbabilities(this_00,pSVar4);
  this_01 = (Ship *)Status::getShip(Globals::status);
  iVar6 = Ship::getFirstEquipmentOfSort(this_01,0x21);
  if ((iVar6 != 0) && (iVar6 = Status::inAlienOrbit(Globals::status), iVar6 == 0)) {
    pSVar7 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar6 = SolarSystem::getIndex(pSVar7);
    if ((iVar6 != 10) && (*piVar5 == 0xcc)) {
      pSVar7 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar6 = SolarSystem::getRoutes(pSVar7);
      if (iVar6 == 0) goto LAB_000bd9f4;
    }
    bVar3 = false;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    puVar8 = operator_new(0xc);
    puVar9 = operator_new__(4);
    puVar8[1] = puVar9;
    puVar8[2] = 1;
    *puVar9 = 0;
    *puVar8 = 0;
    *(undefined4 **)(this + 0xf4) = puVar8;
    iVar6 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar6 == 0x8e) {
      pSVar4 = (Station *)Status::getStation(Globals::status);
      iVar6 = Station::getIndex(pSVar4);
      bVar3 = false;
      if (iVar6 == 0x4f) {
        bVar3 = true;
      }
    }
    iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
    fVar14 = 0.0;
    fVar12 = (float)VectorSignedToFloat(piVar5[1],(byte)(in_fpscr >> 0x16) & 3);
    fVar13 = (float)VectorSignedToFloat(iVar6 + 4,(byte)(in_fpscr >> 0x16) & 3);
    if (bVar3) {
      fVar14 = 3.0;
    }
    fVar14 = fVar14 + fVar13 * (fVar12 / 100.0);
    ArraySetLength<KIPlayer*>((uint)(0.0 < fVar14) * (int)fVar14,*(Array **)(this + 0xf4));
    if (**(int **)(this + 0xf4) != 0) {
      local_58 = 0;
      do {
        iVar6 = *piVar5;
        do {
          do {
            iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,160000);
            local_48 = VectorSignedToFloat(iVar10 + -80000,(byte)(in_fpscr >> 0x16) & 3);
            iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,160000);
            local_44 = VectorSignedToFloat(iVar10 + -80000,(byte)(in_fpscr >> 0x16) & 3);
            iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,160000);
            local_40 = VectorSignedToFloat(iVar10 + -80000,(byte)(in_fpscr >> 0x16) & 3);
            fVar12 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_48);
            uVar1 = in_fpscr & 0xfffffff | (uint)(fVar12 < 25000.0) << 0x1f |
                    (uint)(fVar12 == 25000.0) << 0x1e;
            in_fpscr = uVar1 | (uint)NAN(fVar12) << 0x1c;
            bVar2 = (byte)(uVar1 >> 0x18);
          } while ((bool)(bVar2 >> 6 & 1) || bVar2 >> 7 != ((byte)(in_fpscr >> 0x1c) & 1));
          AbyssEngine::AEMath::operator-(aAStack_54,(Vector *)&local_48,(Vector *)(this + 200));
          fVar12 = (float)AbyssEngine::AEMath::VectorLength((Vector *)aAStack_54);
          uVar1 = in_fpscr & 0xfffffff | (uint)(fVar12 < 30000.0) << 0x1f |
                  (uint)(fVar12 == 30000.0) << 0x1e;
          in_fpscr = uVar1 | (uint)NAN(fVar12) << 0x1c;
          bVar2 = (byte)(uVar1 >> 0x18);
        } while ((bool)(bVar2 >> 6 & 1) || bVar2 >> 7 != ((byte)(in_fpscr >> 0x1c) & 1));
        if ((bool)(local_58 == 0 & bVar3)) {
          local_48 = 0x47b3b000;
          local_44 = 0;
          local_40 = 0x470ca000;
        }
        this_02 = operator_new(0xc0);
        AEGeometry::AEGeometry(this_02,0x37d1,Globals::Canvas,false);
        this_03 = operator_new(0x168);
        PlayerGasCloud::PlayerGasCloud
                  (this_03,iVar6,*(ParticleSystemManager **)(this + 0x94),this_02,
                   (Vector *)&local_48);
        *(PlayerGasCloud **)(*(int *)(*(int *)(this + 0xf4) + 4) + local_58 * 4) = this_03;
        piVar11 = *(int **)(*(int *)(*(int *)(this + 0xf4) + 4) + local_58 * 4);
        (**(code **)(*piVar11 + 0x14))(piVar11,this);
        local_58 = local_58 + 1;
      } while (local_58 < **(uint **)(this + 0xf4));
    }
  }
LAB_000bd9f4:
  if (__stack_chk_guard != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Level::createMission  @0x000bda70  (18916 bytes)
/* Level::createMission() */

void __thiscall Level::createMission(Level *this)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  Status *this_00;
  AERandom *pAVar8;
  Globals *this_01;
  PlayerFixedObject PVar9;
  Mission *pMVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  Array *pAVar14;
  undefined4 *puVar15;
  SolarSystem *pSVar16;
  Station *pSVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  Route *pRVar21;
  Standing *pSVar22;
  Level *pLVar23;
  Level *pLVar24;
  Wanted *this_02;
  int iVar25;
  Route *pRVar26;
  Waypoint *pWVar27;
  Objective *pOVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  int iVar32;
  undefined4 *puVar33;
  int iVar34;
  int iVar35;
  Generator *this_03;
  FileRead *this_04;
  String *pSVar36;
  Agent *pAVar37;
  Mission *pMVar38;
  code *pcVar39;
  uint *puVar40;
  int iVar41;
  int iVar42;
  Route *pRVar43;
  uint uVar44;
  Player *pPVar45;
  KIPlayer *pKVar46;
  void *pvVar47;
  uint uVar48;
  int *piVar49;
  PlayerFixedObject *pPVar50;
  uint uVar51;
  int iVar52;
  bool bVar53;
  uint in_fpscr;
  float extraout_s0;
  float extraout_s1;
  float fVar54;
  float extraout_s2;
  float fVar55;
  undefined4 uVar56;
  float fVar57;
  undefined4 uVar58;
  float fVar59;
  uint uVar60;
  float fVar61;
  float fVar62;
  float fVar63;
  uint local_1c4;
  int local_194;
  int local_188;
  float local_15c;
  String aSStack_158 [8];
  String aSStack_150 [8];
  String aSStack_148 [8];
  String aSStack_140 [8];
  String aSStack_138 [8];
  undefined4 local_130;
  undefined4 uStack_12c;
  undefined4 local_128;
  float local_124;
  float local_120;
  float local_11c;
  float local_118;
  float local_114;
  float local_110;
  float local_10c;
  float local_108;
  float local_104;
  String aSStack_100 [8];
  undefined4 local_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  int local_e0;
  float fStack_dc;
  int local_d8;
  undefined4 uStack_d4;
  undefined8 local_d0;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  float local_b8;
  undefined8 local_b4;
  int local_ac;
  int local_a8;
  int iStack_a4;
  ulonglong local_a0;
  char *local_98;
  undefined4 uStack_94;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined4 local_80;
  float local_7c;
  float local_78;
  float local_74;
  int local_70 [4];
  
  local_70[3] = __stack_chk_guard;
  pMVar10 = (Mission *)Status::getMission(Globals::status);
  if (pMVar10 == (Mission *)0x0) goto switchD_000bddd6_caseD_8;
  AEGeometry::getPosition();
  iVar11 = Status::inAlienOrbit(Globals::status);
  if (iVar11 == 1) {
    uVar12 = Status::getLevel(Globals::status);
    fVar54 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
    uVar44 = 2;
    uVar12 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
    fVar55 = fVar54 * 0.5 + -1.0;
    fVar54 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
    in_fpscr = in_fpscr & 0xfffffff;
    if (2.0 <= fVar55 + fVar54) {
      uVar12 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
      fVar54 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
      uVar44 = (uint)(fVar55 + fVar54);
    }
    iVar11 = Status::getCurrentCampaignMission(Globals::status);
    iVar13 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar13 == 0x21) {
      uVar44 = 2;
    }
    if (iVar11 == 0x44) {
      uVar44 = 2;
    }
    pAVar14 = operator_new(0xc);
    puVar15 = operator_new__(4);
    *(undefined4 **)(pAVar14 + 4) = puVar15;
    *puVar15 = 0;
    *(undefined4 *)(pAVar14 + 8) = 1;
    *(undefined4 *)pAVar14 = 0;
    *(Array **)(this + 0xf8) = pAVar14;
    ArraySetLength<KIPlayer*>(uVar44,pAVar14);
    if (0 < (int)uVar44) {
      uVar51 = 0;
      do {
        iVar11 = Globals::getRandomEnemyFighter(Globals::globals,9);
        uVar12 = createShip(this,9,0,iVar11,(Waypoint *)0x0,true,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar51 * 4) = uVar12;
        piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar51 * 4);
        pcVar39 = *(code **)(*piVar49 + 0x48);
        iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,120000);
        iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,80000);
        uVar56 = VectorSignedToFloat(iVar11 + -60000,(byte)(in_fpscr >> 0x16) & 3);
        uVar58 = VectorSignedToFloat(iVar13 + -40000,(byte)(in_fpscr >> 0x16) & 3);
        iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,120000);
        uVar12 = VectorSignedToFloat(iVar11 + -60000,(byte)(in_fpscr >> 0x16) & 3);
        (*pcVar39)(piVar49,uVar56,uVar58,uVar12);
        Player::setAlwaysEnemy
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar51 * 4) + 4),true
                  );
        uVar51 = uVar51 + 1;
      } while (uVar44 != uVar51);
    }
    goto switchD_000bddd6_caseD_8;
  }
  iVar11 = Mission::isEmpty(pMVar10);
  if (iVar11 == 1) {
    AbyssEngine::AERandom::reset(Globals::rnd);
    bVar6 = false;
    *(undefined4 *)(this + 0xc0) = 0;
    createScene(this);
    *(undefined4 *)(this + 0xc0) = 3;
    pSVar16 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar11 = SolarSystem::getIndex(pSVar16);
    if ((iVar11 == 0xf) &&
       (iVar11 = Status::getCurrentCampaignMission(Globals::status), iVar11 < 0x10)) {
      bVar6 = true;
    }
    pSVar17 = (Station *)Status::getStation(Globals::status);
    iVar11 = Station::getIndex(pSVar17);
    iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
    pMVar10 = (Mission *)Status::getFreelanceMission(Globals::status);
    if ((pMVar10 == (Mission *)0x0) ||
       (((iVar18 = Mission::getType(pMVar10), iVar18 != 0 &&
         (iVar18 = Mission::getType(pMVar10), iVar18 != 0xb)) &&
        (iVar18 = Mission::getType(pMVar10), iVar18 != 0xf)))) {
      local_194 = 0;
    }
    else {
      uVar12 = Mission::getDifficulty(pMVar10);
      fVar54 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
      local_194 = (int)((fVar54 / 10.0) * 5.0);
    }
    iVar18 = Status::getSystem(Globals::status);
    if (iVar18 != 0) {
      pSVar16 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar18 = SolarSystem::hasPirateBase(pSVar16);
      if (iVar18 == 1) {
        local_194 = AbyssEngine::AERandom::nextInt(Globals::rnd,1);
        local_194 = local_194 + 2;
      }
    }
    pSVar16 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar19 = SolarSystem::getSecurityLevel(pSVar16);
    iVar20 = Status::hardCoreMode();
    iVar18 = iVar19;
    if (iVar20 != 0) {
      iVar18 = iVar19 + -1;
    }
    if (iVar19 < 1) {
      iVar18 = iVar19;
    }
    if ((bVar6) && (iVar19 = Status::hardCoreMode(), iVar19 != 1)) {
      bVar1 = false;
    }
    else {
      if (iVar18 == 0) {
        iVar19 = 0x5a;
      }
      else if (iVar18 == 1) {
        iVar19 = 0x41;
      }
      else {
        iVar19 = 10;
        if (iVar18 == 2) {
          iVar19 = 0x23;
        }
      }
      bVar1 = iVar13 < iVar19;
    }
    local_e0 = AbyssEngine::AERandom::nextInt(Globals::rnd,100000);
    local_e0 = local_e0 + -50000;
    fStack_dc = 0.0;
    local_d8 = AbyssEngine::AERandom::nextInt(Globals::rnd,50000);
    local_d8 = local_d8 + 50000;
    pRVar21 = operator_new(0x18);
    Route::Route(pRVar21,&local_e0,3);
    *(Route **)(this + 0x180) = pRVar21;
    pSVar16 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar13 = SolarSystem::getRace(pSVar16);
    iVar19 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
    if (iVar19 < 0x4b) {
      local_188 = 8;
    }
    else {
      pSVar22 = (Standing *)Status::getStanding(Globals::status);
      local_188 = Standing::getEnemyRace(pSVar22,iVar13);
    }
    if (bVar1) {
      uVar12 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
      fVar54 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
    }
    else {
      fVar54 = 0.0;
    }
    *(int *)(this + 0x16c) = (int)fVar54;
    if (0 < (int)fVar54) {
      iVar19 = Status::hardCoreMode();
      if (iVar19 == 0) {
        iVar19 = *(int *)(this + 0x16c);
      }
      else {
        iVar19 = AbyssEngine::AERandom::nextInt(Globals::rnd,6);
        iVar19 = iVar19 + 2;
        *(int *)(this + 0x16c) = iVar19;
      }
      fVar54 = (float)VectorSignedToFloat(iVar19,(byte)(in_fpscr >> 0x16) & 3);
      *(int *)(this + 0x16c) = (int)(fVar54 + fVar54 * ((float)Globals::options._44_4_ + -0.5));
      iVar19 = Status::getLevel(Globals::status);
      *(int *)(this + 0x16c) =
           *(int *)(this + 0x16c) + ((int)(iVar19 + ((uint)(iVar19 >> 0x1f) >> 0x1e)) >> 2);
    }
    if (((bool)(iVar18 == 3 & bVar1)) &&
       (in_fpscr = in_fpscr & 0xfffffff, (float)Globals::options._44_4_ < 1.0)) {
      iVar19 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
      *(int *)(this + 0x16c) = iVar19 + 1;
    }
    if (iVar11 == 0x4e) {
      iVar11 = 0;
      *(undefined4 *)(this + 0x164) = 0;
      *(undefined4 *)(this + 0x168) = 0;
    }
    else {
      uVar12 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
      *(undefined4 *)(this + 0x164) = uVar12;
      uVar12 = AbyssEngine::AERandom::nextInt(Globals::rnd,5);
      *(undefined4 *)(this + 0x168) = uVar12;
      iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
    }
    pLVar23 = this + 0x168;
    pLVar24 = this + 0x164;
    if (bVar6) {
      iVar18 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
    }
    *(int *)(this + 0x160) =
         iVar18 + iVar11 +
         ((int)(*(int *)(this + 0x168) + ((uint)(*(int *)(this + 0x168) >> 0x1f) >> 0x1e)) >> 2);
    if (((bVar1) && (iVar11 = Status::getCurrentCampaignMission(Globals::status), 0x1f < iVar11)) &&
       (iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,100), iVar11 < 8)) {
      *(undefined4 *)(this + 0x16c) = 9;
      *(undefined4 *)(this + 0x160) = 9;
    }
    pSVar17 = (Station *)Status::getStation(Globals::status);
    iVar11 = Station::stationHasPirateBase(pSVar17);
    if (iVar11 == 1) {
      fVar54 = ((float)Globals::options._44_4_ + -0.5) * 5.0 + 5.0;
    }
    else {
      fVar54 = 0.0;
    }
    iVar18 = Status::getSystem(Globals::status);
    if (iVar18 != 0) {
      pSVar16 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar18 = SolarSystem::hasPirateBase(pSVar16);
      if (iVar18 == 1) {
        local_194 = AbyssEngine::AERandom::nextInt(Globals::rnd,1);
        local_194 = local_194 + 2;
        iVar18 = Status::hardCoreMode();
        if (iVar18 == 1) {
          iVar18 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
          local_194 = iVar18 + local_194 * 2;
        }
        bVar1 = false;
        *(undefined4 *)(this + 0x16c) = 0;
      }
    }
    pSVar17 = (Station *)Status::getStation(Globals::status);
    iVar18 = Station::stationHasHiddenBlueprint(pSVar17,true);
    if (comingFromAlienWorld == '\0') {
      pSVar17 = (Station *)Status::getStation(Globals::status);
      iVar19 = Station::isAttackedByAliens(pSVar17);
      if (iVar19 == 1) goto LAB_000be2de;
    }
    else {
LAB_000be2de:
      iVar19 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar19 != 0x2a) {
        iVar19 = *(int *)(this + 0x168);
        if (iVar19 < 2) {
          iVar19 = 2;
        }
        *(int *)(this + 0x168) = iVar19;
        iVar19 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
        *(int *)(this + 0x16c) = iVar19 + 2;
        if ((*(int *)(this + 0x100) != 0) &&
           (piVar49 = *(int **)(*(int *)(*(int *)(this + 0x100) + 4) + 0xc), piVar49 != (int *)0x0))
        {
          uVar12 = *(undefined4 *)(this + 0x180);
          (**(code **)(*piVar49 + 0x28))(&local_f8);
          Route::setNewCoords(uVar12,local_f8,uStack_f4,uStack_f0);
        }
        bVar1 = true;
        local_188 = 9;
      }
    }
    this_02 = (Wanted *)Status::getWantedInCurrentOrbit(Globals::status);
    if (this_02 == (Wanted *)0x0) {
      bVar6 = false;
    }
    else {
      if (2 < *(int *)(this + 0x160)) {
        *(undefined4 *)(this + 0x160) = 2;
      }
      bVar6 = true;
    }
    iVar19 = Status::getCurrentCampaignMission(Globals::status);
    fVar55 = 0.0;
    if ((100 < iVar19) &&
       (iVar19 = Status::getCurrentCampaignMission(Globals::status), iVar19 < 0x91)) {
      uVar12 = Status::getCurrentCampaignMission(Globals::status);
      fVar55 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
      fVar55 = (fVar55 / 144.0) * 15.0 + 5.0;
    }
    uVar44 = Status::hardCoreMode();
    iVar19 = (int)fVar55 << (uVar44 & 0xff);
    if ((iVar19 < 1) ||
       (iVar20 = AbyssEngine::AERandom::nextInt(Globals::rnd,100), iVar19 <= iVar20)) {
      iVar19 = 0;
    }
    else {
      iVar19 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
      uVar44 = Status::hardCoreMode();
      iVar19 = iVar19 + 2 << (uVar44 & 0xff);
    }
    if (((pMVar10 == (Mission *)0x0) || (iVar20 = Mission::getType(pMVar10), iVar20 != 0xd)) ||
       (Globals::status[0xf1] != (Status)0x0)) {
LAB_000be484:
      pSVar17 = (Station *)Status::getStation(Globals::status);
      iVar20 = Station::hasAttackedFriends(pSVar17);
      iVar25 = *(int *)(this + 0x160);
      if (iVar20 == 1) {
        if (iVar25 < 7) {
          iVar25 = 7;
        }
        *(int *)(this + 0x160) = iVar25;
        *(undefined2 *)(this + 0x189) = 0x101;
      }
      bVar53 = false;
      if (*(int *)(this + 0x164) + iVar25 + *(int *)(this + 0x168) + *(int *)(this + 0x16c) +
          local_194 == 0) {
        *(undefined4 *)(this + 0x160) = 4;
      }
    }
    else {
      iVar20 = Mission::getTargetStation(pMVar10);
      pSVar17 = (Station *)Status::getStation(Globals::status);
      iVar25 = Station::getIndex(pSVar17);
      if (iVar20 != iVar25) goto LAB_000be484;
      *(undefined4 *)(this + 0x164) = 0;
      *(undefined4 *)(this + 0x168) = 0;
      *(undefined4 *)(this + 0x16c) = 0;
      bVar53 = Globals::status[0xf0] == (Status)0x0;
      if (bVar53) {
        uVar12 = 7;
      }
      else {
        uVar12 = 6;
      }
      *(undefined4 *)(this + 0x160) = uVar12;
      bVar1 = false;
      local_194 = 0;
    }
    pSVar17 = (Station *)Status::getStation(Globals::status);
    iVar20 = Station::getIndex(pSVar17);
    if (iVar20 - 100U < 9) {
      uVar44 = 1 << (iVar20 - 100U & 0xff);
      if ((uVar44 & 0x103) != 0) goto LAB_000be526;
      if ((uVar44 & 0x1c) == 0) goto LAB_000be522;
      *(undefined4 *)(this + 0x160) = 0;
      iVar20 = AbyssEngine::AERandom::nextInt(Globals::rnd,5);
      *(undefined4 *)(this + 0x164) = 0;
      *(undefined4 *)(this + 0x168) = 0;
      *(int *)(this + 0x16c) = iVar20 + 3;
      bVar1 = true;
      local_188 = 8;
    }
    else {
LAB_000be522:
      if (iVar20 == 10) {
LAB_000be526:
        *(undefined4 *)(this + 0x160) = 0;
        *(undefined4 *)(this + 0x164) = 0;
        *(undefined4 *)(this + 0x168) = 0;
        bVar1 = false;
        *(undefined4 *)(this + 0x16c) = 0;
      }
    }
    iVar20 = Status::getCurrentCampaignMission(Globals::status);
    if (((iVar20 == 0x24) ||
        (iVar20 = Status::getCurrentCampaignMission(Globals::status), iVar20 == 0x25)) &&
       (iVar20 = Status::getSystem(Globals::status), iVar20 != 0)) {
      pSVar16 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar20 = SolarSystem::getIndex(pSVar16);
      if (iVar20 == 5) {
        *(undefined4 *)(this + 0x160) = 0;
        bVar1 = false;
        *(undefined4 *)(this + 0x16c) = 0;
      }
    }
    iVar20 = Status::getCurrentCampaignMission(Globals::status);
    if (((0x29 < iVar20) &&
        (iVar20 = Status::getCurrentCampaignMission(Globals::status), iVar20 < 0x2c)) &&
       (iVar20 = Status::inAlienOrbit(Globals::status), iVar20 == 0)) {
      local_194 = 0;
      bVar1 = false;
      *(undefined4 *)(this + 0x16c) = 0;
    }
    iVar20 = Status::inBlackMarketSystem(Globals::status);
    if (iVar20 == 1) {
      local_194 = 0;
      *(undefined4 *)(this + 0x160) = 0;
      iVar20 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
      *(int *)(this + 0x16c) = iVar20 + 6;
      iVar20 = Status::hardCoreMode();
      if (iVar20 == 1) {
        iVar25 = *(int *)(this + 0x16c);
        iVar20 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
        *(int *)(this + 0x16c) = iVar20 + iVar25 * 2;
      }
      *(undefined4 *)pLVar23 = 0;
      *(undefined4 *)pLVar24 = 0;
      bVar1 = true;
      local_188 = 8;
    }
    iVar20 = Status::inPirateLootOrbit(Globals::status);
    if (iVar20 == 1) {
      local_194 = 0;
      *(undefined4 *)(this + 0x160) = 0;
      iVar20 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
      *(int *)(this + 0x16c) = iVar20 + 10;
      iVar20 = Status::hardCoreMode();
      if (iVar20 == 1) {
        iVar25 = *(int *)(this + 0x16c);
        iVar20 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
        *(int *)(this + 0x16c) = iVar20 + iVar25 * 2;
      }
      *(undefined4 *)pLVar23 = 0;
      *(undefined4 *)pLVar24 = 0;
      bVar1 = true;
      local_188 = 8;
    }
    pSVar17 = (Station *)Status::getStation(Globals::status);
    iVar20 = Station::getIndex(pSVar17);
    this_00 = Globals::status;
    if (iVar20 == 0x6c) {
      if (*(int *)(Globals::status + 0x114) == 0) {
        iVar13 = 0;
        this[0x288] = (Level)0x1;
        *(undefined4 *)(this + 0x160) = 0;
        iVar11 = Status::hardCoreMode();
        uVar12 = 6;
        if (iVar11 != 0) {
          uVar12 = 8;
        }
        *(undefined4 *)(this + 0x164) = 0;
        *(undefined4 *)(this + 0x168) = 0;
        *(undefined4 *)(this + 0x16c) = uVar12;
        pAVar14 = operator_new(0xc);
        puVar15 = operator_new__(4);
        *(undefined4 **)(pAVar14 + 4) = puVar15;
        *(undefined4 *)(pAVar14 + 8) = 1;
        *puVar15 = 0;
        *(undefined4 *)pAVar14 = 0;
        *(Array **)(this + 0xf8) = pAVar14;
        ArraySetLength<KIPlayer*>(*(int *)(this + 0x16c) + 4,pAVar14);
        do {
          uVar12 = createStaticObject(this,(Waypoint *)0x0,0x37a3,true);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar13 * 4) = uVar12;
          iVar11 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar13 * 4);
          pSVar36 = (String *)GameText::getText(Globals::gameText,0x1b9);
          AbyssEngine::String::operator=((String *)(iVar11 + 0x18),pSVar36);
          iVar13 = iVar13 + 1;
        } while (iVar13 != 4);
        (**(code **)(*(int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4) + 0x48))
                  ((int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),0x472fc800,0x459c4000,
                   0x4756d800);
        piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + 4);
        (**(code **)(*piVar49 + 0x48))(piVar49,0x479c4000,0xc6ea6000,0xc63b8000);
        piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + 8);
        (**(code **)(*piVar49 + 0x48))(piVar49,0xc66a6000,0x472fc800,0x4756d800);
        piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + 0xc);
        (**(code **)(*piVar49 + 0x48))(piVar49,0xc77de800,0xc69c4000,0xc72fc800);
        if (4 < **(uint **)(this + 0xf8)) {
          uVar44 = 4;
          do {
            iVar11 = Globals::getRandomEnemyFighter(Globals::globals,8);
            uVar12 = createShip(this,8,0,iVar11,(Waypoint *)0x0,true,false);
            *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar44 * 4) = uVar12;
            uVar44 = uVar44 + 1;
          } while (uVar44 < **(uint **)(this + 0xf8));
        }
        pMVar10 = operator_new(100);
        pSVar36 = (String *)GameText::getText(Globals::gameText,0x641);
        AbyssEngine::String::String(aSStack_100,pSVar36,false);
        Mission::Mission(pMVar10,4,aSStack_100,&DAT_0026a1b0,4,0,0x6c,0);
        AbyssEngine::String::~String(aSStack_100);
        Status::setFreelanceMission(Globals::status,pMVar10);
        Status::setMission(Globals::status,pMVar10);
        pOVar28 = operator_new(0x1c);
        Objective::Objective(pOVar28,0x12,0,**(int **)(this + 0xf8),this);
        goto LAB_000c1c1e;
      }
      bVar1 = false;
      *(undefined4 *)(this + 0x16c) = 0;
    }
    iVar20 = Status::getCampaignMission(this_00);
    if (iVar20 != 0) {
      pMVar10 = (Mission *)Status::getCampaignMission(Globals::status);
      iVar20 = Mission::getType(pMVar10);
      if (((iVar20 == 0xa3) &&
          (puVar40 = *(uint **)(Globals::status + 0x90), puVar40 != (uint *)0x0)) && (*puVar40 != 0)
         ) {
        uVar44 = 0;
        do {
          iVar25 = *(int *)(puVar40[1] + uVar44 * 4);
          pSVar17 = (Station *)Status::getStation(Globals::status);
          iVar20 = Station::getIndex(pSVar17);
          if (iVar25 == iVar20) {
            bVar2 = true;
            goto LAB_000be742;
          }
          uVar44 = uVar44 + 1;
          puVar40 = *(uint **)(Globals::status + 0x90);
        } while (uVar44 < *puVar40);
      }
    }
    bVar2 = false;
LAB_000be742:
    iVar20 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
    local_70[0] = iVar20 + -10000;
    iVar20 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
    local_70[1] = iVar20 + -10000;
    local_70[2] = AbyssEngine::AERandom::nextInt(Globals::rnd,30000);
    local_70[2] = local_70[2] + 20000;
    pRVar21 = operator_new(0x18);
    Route::Route(pRVar21,local_70,3);
    if (bVar2) {
      *(undefined4 *)(this + 0x164) = 0;
      *(undefined4 *)(this + 0x16c) = 0;
      pAVar14 = operator_new(0xc);
      puVar15 = operator_new__(4);
      *(undefined4 **)(pAVar14 + 4) = puVar15;
      *(undefined4 *)(pAVar14 + 8) = 1;
      *puVar15 = 0;
      *(undefined4 *)pAVar14 = 0;
      *(Array **)(this + 0xf8) = pAVar14;
      ArraySetLength<KIPlayer*>(*(int *)(this + 0x160) + 8,pAVar14);
      iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,30000);
      iVar18 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
      iVar19 = -1;
      if (iVar18 == 0) {
        iVar19 = 1;
      }
      local_7c = (float)(iVar19 * (iVar11 + 80000));
      iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,3000);
      local_78 = (float)(iVar11 + -6000);
      iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,50000);
      local_74 = (float)(iVar11 + 120000);
      pRVar26 = operator_new(0x18);
      Route::Route(pRVar26,(int *)&local_7c,3);
      *(Route **)(this + 0x108) = pRVar26;
      pRVar26 = (Route *)Route::clone(pRVar26);
      *(Route **)(this + 0x110) = pRVar26;
      Route::setLoop(pRVar26,true);
      pWVar27 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x108));
      iVar11 = 0xf;
      if (iVar13 == 1) {
        iVar11 = 0xd;
      }
      uVar12 = createShip(this,iVar13,1,iVar11,pWVar27,true,false);
      **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar12;
      PlayerFixedObject::setMoving
                ((PlayerFixedObject *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),false);
      uVar12 = VectorSignedToFloat(local_7c,(byte)(in_fpscr >> 0x16) & 3);
      uVar56 = VectorSignedToFloat(local_78,(byte)(in_fpscr >> 0x16) & 3);
      uVar58 = VectorSignedToFloat(local_74,(byte)(in_fpscr >> 0x16) & 3);
      (**(code **)(*(int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4) + 0x48))
                ((int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),uVar12,uVar56,uVar58);
      if (*(int *)(**(int **)(*(int *)(this + 0xf8) + 4) + 0x4c) != 0) {
        iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,6);
        if (iVar11 == 3) {
          iVar11 = 0x24;
        }
        else if (iVar11 == 4) {
          iVar11 = 0x16;
        }
        else if (iVar11 == 5) {
          iVar11 = 0x17;
        }
        iVar18 = **(int **)(*(int *)(this + 0xf8) + 4);
        **(int **)(*(int *)(iVar18 + 0x4c) + 4) = iVar11;
        pSVar36 = (String *)GameText::getText(Globals::gameText,0x680);
        AbyssEngine::String::operator=((String *)(iVar18 + 0x18),pSVar36);
      }
      iVar11 = 1;
      do {
        iVar18 = Globals::getRandomEnemyFighter(Globals::globals,iVar13);
        pWVar27 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x108));
        uVar12 = createShip(this,iVar13,0,iVar18,pWVar27,true,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar11 * 4) = uVar12;
        pKVar46 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar11 * 4);
        pRVar26 = (Route *)Route::clone(*(Route **)(this + 0x110));
        KIPlayer::setRoute(pKVar46,pRVar26);
        iVar11 = iVar11 + 1;
      } while (iVar11 != 6);
      local_98 = *(char **)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      uStack_94 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      puVar15 = (undefined4 *)((uint)&local_b8 | 4);
      iVar11 = 0;
      local_b8 = 1.0;
      *puVar15 = 0;
      puVar15[1] = *(uint *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      puVar15[2] = local_98;
      puVar15[3] = uStack_94;
      iStack_a4 = 0x3f800000;
      local_a0 = (ulonglong)*(uint *)((undefined1  [16])0x0 + (undefined1  [16])0x4) << 0x20;
      local_90 = 0x3f800000;
      uStack_88 = 0x3f8000003f800000;
      local_80 = 0x3f800000;
      local_10c = 0.0;
      local_108 = 0.0;
      local_104 = 0.0;
      (**(code **)(*(int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4) + 0x28))(&local_118);
      iVar18 = 0x18;
      do {
        uVar12 = createStaticObject(this,(Waypoint *)0x0,0x381b,true);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar18) = uVar12;
        piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar18);
        Player::setMaxHitpoints((Player *)piVar49[1],1000);
        iVar19 = iVar11 + iVar13 * 0x38;
        uVar56 = *(undefined4 *)(&UNK_00253464 + iVar19 + 4);
        uVar58 = *(undefined4 *)(&UNK_00253464 + iVar19 + 8);
        uVar12 = *(undefined4 *)(&UNK_00253464 + iVar19 + 0xc);
        local_130 = *(undefined4 *)(&UNK_00253464 + iVar19 + 0x10);
        uStack_12c = *(undefined4 *)(&UNK_00253464 + iVar19 + 0x14);
        local_128 = *(undefined4 *)(&UNK_00253464 + iVar19 + 0x18);
        AbyssEngine::AEMath::MatrixRotateVector
                  ((AEMath *)&local_124,(Matrix *)&local_b8,(Vector *)&local_130);
        AbyssEngine::AEMath::Vector::operator=((Vector *)&local_10c,(Vector *)&local_124);
        AEGeometry::setRotation((Vector *)piVar49[2]);
        local_130 = uVar56;
        uStack_12c = uVar58;
        local_128 = uVar12;
        AbyssEngine::AEMath::MatrixRotateVector
                  ((AEMath *)&local_124,(Matrix *)&local_b8,(Vector *)&local_130);
        AbyssEngine::AEMath::Vector::operator=((Vector *)&local_10c,(Vector *)&local_124);
        local_124 = local_118 + local_10c;
        local_120 = local_114 + local_108;
        local_11c = local_110 + local_104;
        fVar54 = (float)(**(code **)(*piVar49 + 0x44))(piVar49,(AEMath *)&local_124);
        PlayerTurret::setScaling(fVar54);
        iVar11 = iVar11 + 0x1c;
        piVar49[9] = iVar13;
        iVar18 = iVar18 + 4;
      } while (iVar11 != 0x38);
      if (0 < *(int *)(this + 0x160)) {
        iVar11 = 8;
        do {
          iVar18 = Globals::getRandomEnemyFighter(Globals::globals,iVar13);
          pWVar27 = (Waypoint *)Route::getWaypoint(pRVar21);
          uVar12 = createShip(this,iVar13,0,iVar18,pWVar27,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar11 * 4) = uVar12;
          bVar6 = iVar11 < *(int *)(this + 0x160) + 7;
          iVar11 = iVar11 + 1;
        } while (bVar6);
      }
    }
    else {
      iVar20 = Status::getCampaignMission(Globals::status);
      if (iVar20 == 0) {
        local_1c4 = 0;
      }
      else {
        pMVar10 = (Mission *)Status::getCampaignMission(Globals::status);
        iVar20 = Mission::getType(pMVar10);
        local_1c4 = 0;
        if (iVar20 == 0xa7) {
          pSVar17 = (Station *)Status::getStation(Globals::status);
          iVar20 = Station::getIndex(pSVar17);
          pMVar10 = (Mission *)Status::getCampaignMission(Globals::status);
          iVar25 = Mission::getTargetStation(pMVar10);
          local_1c4 = (uint)(iVar20 == iVar25);
        }
      }
      iVar20 = *(int *)pLVar23;
      bVar2 = false;
      if ((iVar13 == 0) && (0 < iVar20)) {
        iVar25 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
        iVar20 = *(int *)pLVar23;
        bVar2 = iVar25 < 0x1e;
      }
      bVar3 = false;
      if ((iVar13 == 1) && (0 < iVar20)) {
        iVar20 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
        bVar3 = false;
        if (iVar20 < 0x1e) {
          iVar20 = Status::getCurrentCampaignMission(Globals::status);
          bVar3 = 0x8c < iVar20;
        }
      }
      if (bVar2) {
        iVar20 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
        bVar4 = false;
        if (iVar20 < 0x1e) {
          iVar20 = Status::getCurrentCampaignMission(Globals::status);
          bVar4 = 0x67 < iVar20;
        }
      }
      else {
        bVar4 = false;
      }
      iVar20 = Status::inSupernovaSystem(Globals::status);
      if (iVar20 == 1) {
        *(undefined4 *)(this + 0x160) = 0;
        *(undefined4 *)(this + 0x164) = 0;
        *(undefined4 *)(this + 0x168) = 0;
        bVar2 = false;
        *(undefined4 *)(this + 0x16c) = 0;
        bVar1 = false;
      }
      if (bVar6) {
        iVar20 = Wanted::getNumWingmen(this_02);
        *(int *)(this + 0x160) = iVar20 + *(int *)(this + 0x160) + 1;
      }
      iVar20 = 7;
      if (bVar4) {
        iVar20 = 8;
      }
      if (!bVar2) {
        iVar20 = 0;
      }
      iVar25 = 0;
      if (bVar3) {
        iVar25 = 5;
      }
      pAVar14 = operator_new(0xc);
      puVar15 = operator_new__(4);
      *(undefined4 **)(pAVar14 + 4) = puVar15;
      *(undefined4 *)(pAVar14 + 8) = 1;
      *puVar15 = 0;
      *(undefined4 *)pAVar14 = 0;
      *(Array **)(this + 0xf8) = pAVar14;
      iVar41 = (int)fVar54 + iVar11;
      ArraySetLength<KIPlayer*>
                (iVar18 + iVar41 + iVar19 + local_194 + local_1c4 + iVar25 + iVar20 +
                 *(int *)(this + 0x160) + *(int *)(this + 0x164) + *(int *)(this + 0x168) +
                 *(int *)(this + 0x16c),pAVar14);
      iVar29 = *(int *)(this + 0x160);
      if (0 < iVar29) {
        iVar42 = 0;
        do {
          if ((bool)(iVar42 == 0 & bVar6)) {
            uVar44 = Wanted::getRace(this_02);
            if (uVar44 < 4) {
              iVar29 = Wanted::getRace(this_02);
            }
            else {
              iVar29 = 8;
            }
            iVar30 = Wanted::getShip(this_02);
            pWVar27 = (Waypoint *)Route::getWaypoint(pRVar21);
            uVar12 = createShip(this,iVar29,0,iVar30,pWVar27,true,false);
            **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar12;
            iVar30 = Wanted::getHitpoints(this_02);
            iVar31 = Status::getLevel(Globals::status);
            if (iVar31 < 0x15) {
              iVar31 = Status::getLevel(Globals::status);
            }
            else {
              iVar31 = 0x14;
            }
            iVar32 = Status::gameWon(Globals::status);
            if (iVar32 == 0) {
              iVar32 = Status::getCurrentCampaignMission(Globals::status);
            }
            else {
              iVar32 = 0x2d;
            }
            fVar55 = (float)VectorSignedToFloat(iVar31 * 0xf + iVar30 + iVar32 * 4,
                                                (byte)(in_fpscr >> 0x16) & 3);
            iVar32 = (int)(fVar55 + ((float)Globals::options._44_4_ + -0.5) * fVar55);
            Player::setMaxHitpoints(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),iVar32);
            Player::setHitpoints(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),iVar32);
            iVar30 = **(int **)(*(int *)(this + 0xf8) + 4);
            Wanted::getName();
            AbyssEngine::String::operator=((String *)(iVar30 + 0x18),(String *)&local_b8);
            AbyssEngine::String::~String((String *)&local_b8);
            iVar31 = *(int *)(this + 0xf8);
            iVar30 = **(int **)(iVar31 + 4);
            pvVar47 = *(void **)(iVar30 + 0x4c);
            if (pvVar47 != (void *)0x0) {
              if (*(void **)((int)pvVar47 + 4) != (void *)0x0) {
                operator_delete__(*(void **)((int)pvVar47 + 4));
              }
              operator_delete(pvVar47);
              iVar31 = *(int *)(this + 0xf8);
              iVar30 = **(int **)(iVar31 + 4);
            }
            *(undefined4 *)(iVar30 + 0x4c) = 0;
            puVar15 = operator_new(0xc);
            puVar33 = operator_new__(4);
            puVar15[1] = puVar33;
            puVar15[2] = 1;
            *puVar33 = 0;
            *puVar15 = 0;
            *(undefined4 **)(**(int **)(iVar31 + 4) + 0x4c) = puVar15;
            uVar12 = Wanted::getLoot(this_02);
            piVar49 = *(int **)(**(int **)(*(int *)(this + 0xf8) + 4) + 0x4c);
            piVar49[2] = *piVar49 + 1;
            pvVar47 = realloc((void *)piVar49[1],(*piVar49 + 1) * 4);
            piVar49[1] = (int)pvVar47;
            *(undefined4 *)((int)pvVar47 + *piVar49 * 4) = uVar12;
            *piVar49 = piVar49[2];
            uVar12 = Wanted::getLootAmount(this_02);
            piVar49 = *(int **)(**(int **)(*(int *)(this + 0xf8) + 4) + 0x4c);
            piVar49[2] = *piVar49 + 1;
            pvVar47 = realloc((void *)piVar49[1],(*piVar49 + 1) * 4);
            piVar49[1] = (int)pvVar47;
            *(undefined4 *)((int)pvVar47 + *piVar49 * 4) = uVar12;
            *piVar49 = piVar49[2];
            *(undefined1 *)(**(int **)(*(int *)(this + 0xf8) + 4) + 0x3e) = 1;
            iVar30 = Wanted::getIndex(this_02);
            piVar49 = (int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4);
            piVar49[0x11] = iVar30;
            (**(code **)(*piVar49 + 0x1c))(piVar49,0x40900000);
            iVar30 = Wanted::getNumWingmen(this_02);
            if (0 < iVar30) {
              iVar30 = 1;
              do {
                iVar31 = Globals::getRandomEnemyFighter(Globals::globals,iVar29);
                pWVar27 = (Waypoint *)Route::getWaypoint(pRVar21);
                uVar12 = createShip(this,iVar29,0,iVar31,pWVar27,true,false);
                *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar30 * 4) = uVar12;
                Player::setMaxHitpoints
                          (*(Player **)
                            (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar30 * 4) + 4),
                           iVar32 / 2);
                Player::setHitpoints
                          (*(Player **)
                            (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar30 * 4) + 4),
                           iVar32 / 2);
                iVar31 = Wanted::getNumWingmen(this_02);
                bVar5 = iVar30 < iVar31;
                iVar30 = iVar30 + 1;
              } while (bVar5);
            }
          }
          else if ((!bVar6) || (iVar29 = Wanted::getNumWingmen(this_02), iVar29 < iVar42)) {
            iVar29 = Globals::getRandomEnemyFighter(Globals::globals,iVar13);
            pWVar27 = (Waypoint *)Route::getWaypoint(pRVar21);
            uVar12 = createShip(this,iVar13,0,iVar29,pWVar27,true,false);
            *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar42 * 4) = uVar12;
          }
          iVar29 = *(int *)(this + 0x160);
          iVar42 = iVar42 + 1;
        } while (iVar42 < iVar29);
      }
      iVar30 = *(int *)pLVar24;
      iVar42 = iVar29;
      if (iVar30 < 1) {
        iVar31 = iVar30 + iVar29;
      }
      else {
        do {
          iVar29 = Globals::getRandomEnemyFighter(Globals::globals,iVar13);
          uVar12 = createShip(this,iVar13,0,iVar29,(Waypoint *)0x0,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar42 * 4) = uVar12;
          KIPlayer::setDead(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar42 * 4));
          iVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,400000);
          local_b8 = (float)(iVar29 + -200000);
          iVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,200000);
          local_b4 = CONCAT44(local_b4._4_4_,iVar29 + -100000);
          iVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,100000);
          local_b4 = CONCAT44(iVar29 + 50000,(float)local_b4);
          pRVar21 = operator_new(0x18);
          Route::Route(pRVar21,(int *)&local_b8,3);
          KIPlayer::setRoute(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar42 * 4),
                             pRVar21);
          KIPlayer::setJumper(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar42 * 4),true)
          ;
          iVar29 = *(int *)(this + 0x160);
          iVar30 = *(int *)(this + 0x164);
          iVar42 = iVar42 + 1;
          iVar31 = iVar30 + iVar29;
        } while (iVar42 < iVar31);
      }
      iVar32 = iVar30 + iVar29;
      iVar42 = *(int *)pLVar23;
      if (iVar31 < iVar32 + iVar42) {
        iVar34 = iVar13;
        if (iVar13 == 2) {
          iVar34 = 0;
        }
        do {
          if ((bool)(iVar31 == iVar32 & bVar2)) {
            if (bVar4) {
              iVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,80000);
              fVar57 = (float)VectorSignedToFloat(iVar29 + -40000,(byte)(in_fpscr >> 0x16) & 3);
              iVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,40000);
              fVar59 = (float)VectorSignedToFloat(iVar29 + -20000,(byte)(in_fpscr >> 0x16) & 3);
              iVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,80000);
              fVar55 = (float)VectorSignedToFloat(iVar29 + 100000,(byte)(in_fpscr >> 0x16) & 3);
              local_b4 = CONCAT44(fVar55,fVar59);
              local_b8 = fVar57;
              pWVar27 = operator_new(0x134);
              Waypoint::Waypoint(pWVar27,(int)fVar57,(int)fVar59,(int)fVar55,(Route *)0x0);
              uVar12 = createStaticObject(this,pWVar27,0x4974,true);
              *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar32 * 4) = uVar12;
              KIPlayer::setSpacePoints
                        (*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar32 * 4),
                         (Array *)0x0);
              piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar32 * 4);
              (**(code **)(*piVar49 + 0x44))(piVar49,&local_b8);
              PlayerFixedObject::setMoving
                        (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar32 * 4),
                         false);
              Player::setHitpoints
                        (*(Player **)
                          (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar32 * 4) + 4),9999999);
              iVar29 = *(int *)(this + 0xf8);
              iVar42 = *(int *)(iVar29 + 4);
              iVar30 = *(int *)(iVar42 + iVar32 * 4);
              pvVar47 = *(void **)(iVar30 + 0x4c);
              if (pvVar47 != (void *)0x0) {
                if (*(void **)((int)pvVar47 + 4) != (void *)0x0) {
                  operator_delete__(*(void **)((int)pvVar47 + 4));
                }
                operator_delete(pvVar47);
                iVar29 = *(int *)(this + 0xf8);
                iVar42 = *(int *)(iVar29 + 4);
                iVar30 = *(int *)(iVar42 + iVar32 * 4);
              }
              *(undefined4 *)(iVar30 + 0x4c) = 0;
              *(undefined1 *)(*(int *)(iVar42 + iVar32 * 4) + 0x6c) = 0;
            }
            else {
              uVar12 = createShip(this,iVar13,1,0xe,(Waypoint *)0x0,true,false);
              *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar32 * 4) = uVar12;
              iVar29 = *(int *)(this + 0xf8);
            }
            PlayerFixedObject::setMoving
                      (*(PlayerFixedObject **)(*(int *)(iVar29 + 4) + iVar32 * 4),false);
            piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar32 * 4);
            pcVar39 = *(code **)(*piVar49 + 0x48);
            iVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,80000);
            uVar56 = VectorSignedToFloat(iVar29 + -40000,(byte)(in_fpscr >> 0x16) & 3);
            iVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,10000);
            uVar58 = VectorSignedToFloat(iVar29 + -5000,(byte)(in_fpscr >> 0x16) & 3);
            iVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,80000);
            uVar12 = VectorSignedToFloat(iVar29 + 40000,(byte)(in_fpscr >> 0x16) & 3);
            (*pcVar39)(piVar49,uVar56,uVar58,uVar12);
          }
          else if ((bool)(iVar31 == iVar32 & bVar3)) {
            iVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,80000);
            fVar57 = (float)VectorSignedToFloat(iVar29 + -40000,(byte)(in_fpscr >> 0x16) & 3);
            iVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,40000);
            fVar59 = (float)VectorSignedToFloat(iVar29 + -20000,(byte)(in_fpscr >> 0x16) & 3);
            iVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,80000);
            fVar55 = (float)VectorSignedToFloat(iVar29 + 60000,(byte)(in_fpscr >> 0x16) & 3);
            local_b4 = CONCAT44(fVar55,fVar59);
            local_b8 = fVar57;
            pWVar27 = operator_new(0x134);
            Waypoint::Waypoint(pWVar27,(int)fVar57,(int)fVar59,(int)fVar55,(Route *)0x0);
            uVar12 = createStaticObject(this,pWVar27,0x4a6b,true);
            *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar32 * 4) = uVar12;
            KIPlayer::setSpacePoints
                      (*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar32 * 4),(Array *)0x0
                      );
            piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar32 * 4);
            (**(code **)(*piVar49 + 0x44))(piVar49,&local_b8);
            PlayerFixedObject::setMoving
                      (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar32 * 4),
                       false);
            Player::setHitpoints
                      (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar32 * 4) + 4),
                       9999999);
            pPVar50 = *(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar32 * 4);
            pSVar36 = (String *)GameText::getText(Globals::gameText,0x683);
            AbyssEngine::String::String(aSStack_138,pSVar36,false);
            PlayerFixedObject::setName(pPVar50,aSStack_138);
            AbyssEngine::String::~String(aSStack_138);
            iVar29 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar32 * 4);
            *(undefined1 *)(iVar29 + 0x6c) = 0;
            pvVar47 = *(void **)(iVar29 + 0x4c);
            if (pvVar47 != (void *)0x0) {
              if (*(void **)((int)pvVar47 + 4) != (void *)0x0) {
                operator_delete__(*(void **)((int)pvVar47 + 4));
              }
              operator_delete(pvVar47);
              iVar29 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar32 * 4);
            }
            *(undefined4 *)(iVar29 + 0x4c) = 0;
          }
          else {
            iVar30 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
            iVar32 = 0xf;
            iVar42 = iVar34;
            iVar29 = 2;
            if (0x1d < iVar30) {
              iVar42 = iVar13;
              iVar29 = iVar13;
            }
            if (iVar13 == 0) {
              iVar42 = iVar29;
            }
            if (iVar42 == 1) {
              iVar32 = 0xd;
            }
            uVar12 = createShip(this,iVar42,1,iVar32,(Waypoint *)0x0,true,false);
            *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar31 * 4) = uVar12;
            PlayerFixedObject::setMoving
                      (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar31 * 4),
                       true);
            piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar31 * 4);
            pcVar39 = *(code **)(*piVar49 + 0x48);
            iVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,60000);
            iVar42 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
            iVar30 = -1;
            if (iVar42 == 0) {
              iVar30 = 1;
            }
            iVar42 = AbyssEngine::AERandom::nextInt(Globals::rnd,40000);
            uVar56 = VectorSignedToFloat(iVar30 * (iVar29 + -80000),(byte)(in_fpscr >> 0x16) & 3);
            uVar58 = VectorSignedToFloat(iVar42 + -20000,(byte)(in_fpscr >> 0x16) & 3);
            iVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,160000);
            uVar12 = VectorSignedToFloat(iVar29 + -80000,(byte)(in_fpscr >> 0x16) & 3);
            (*pcVar39)(piVar49,uVar56,uVar58,uVar12);
          }
          iVar31 = iVar31 + 1;
          iVar29 = *(int *)(this + 0x160);
          iVar30 = *(int *)(this + 0x164);
          iVar42 = *(int *)(this + 0x168);
          iVar32 = iVar30 + iVar29;
        } while (iVar31 < iVar32 + iVar42);
      }
      if (iVar20 != 0) {
        local_98 = *(char **)((undefined1  [16])0x0 + (undefined1  [16])0x8);
        uStack_94 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
        puVar15 = (undefined4 *)((uint)&local_b8 | 4);
        local_b8 = 1.0;
        *puVar15 = 0;
        puVar15[1] = *(uint *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
        puVar15[2] = local_98;
        puVar15[3] = uStack_94;
        iStack_a4 = 0x3f800000;
        local_a0 = (ulonglong)*(uint *)((undefined1  [16])0x0 + (undefined1  [16])0x4) << 0x20;
        local_90 = 0x3f800000;
        uStack_88 = 0x3f8000003f800000;
        local_80 = 0x3f800000;
        local_7c = 0.0;
        local_78 = 0.0;
        local_74 = 0.0;
        (**(code **)(**(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + (iVar29 + iVar30) * 4) + 0x28)
        )(&local_10c);
        iVar29 = *(int *)(this + 0x160);
        iVar30 = *(int *)(this + 0x164);
        iVar42 = *(int *)(this + 0x168);
        iVar31 = iVar30 + iVar29 + iVar42;
        if (iVar31 < iVar29 + iVar20 + iVar30 + iVar42) {
          iVar32 = 0;
          do {
            uVar12 = createStaticObject(this,(Waypoint *)0x0,0x1a74,true);
            *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar31 * 4) = uVar12;
            piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar31 * 4);
            Player::setMaxHitpoints((Player *)piVar49[1],1000);
            if (bVar4) {
              local_15c = *(float *)((int)&DAT_00253548 + iVar32);
              fVar55 = *(float *)((int)&DAT_0025354c + iVar32);
              local_124 = *(float *)((int)&DAT_00253550 + iVar32);
              local_120 = *(float *)((int)&DAT_00253554 + iVar32);
              local_11c = *(float *)((int)&DAT_00253558 + iVar32);
              AbyssEngine::AEMath::MatrixRotateVector
                        ((AEMath *)&local_118,(Matrix *)&local_b8,(Vector *)&local_124);
              AbyssEngine::AEMath::Vector::operator=((Vector *)&local_7c,(Vector *)&local_118);
              AEGeometry::setRotation((Vector *)piVar49[2]);
              puVar15 = &DAT_00253544;
            }
            else {
              local_15c = *(float *)((int)&DAT_00253608 + iVar32);
              fVar55 = *(float *)((int)&DAT_0025360c + iVar32);
              local_124 = *(float *)((int)&DAT_00253610 + iVar32);
              local_120 = *(float *)((int)&DAT_00253614 + iVar32);
              local_11c = *(float *)((int)&DAT_00253618 + iVar32);
              AbyssEngine::AEMath::MatrixRotateVector
                        ((AEMath *)&local_118,(Matrix *)&local_b8,(Vector *)&local_124);
              AbyssEngine::AEMath::Vector::operator=((Vector *)&local_7c,(Vector *)&local_118);
              AEGeometry::setRotation((Vector *)piVar49[2]);
              puVar15 = &DAT_00253604;
            }
            local_124 = *(float *)((int)puVar15 + iVar32);
            local_120 = local_15c;
            local_11c = fVar55;
            AbyssEngine::AEMath::MatrixRotateVector
                      ((AEMath *)&local_118,(Matrix *)&local_b8,(Vector *)&local_124);
            AbyssEngine::AEMath::Vector::operator=((Vector *)&local_7c,(Vector *)&local_118);
            local_118 = local_10c + local_7c;
            local_114 = local_108 + local_78;
            local_110 = local_104 + local_74;
            fVar55 = (float)(**(code **)(*piVar49 + 0x44))(piVar49,(AEMath *)&local_118);
            PlayerTurret::setScaling(fVar55);
            piVar49[9] = iVar13;
            piVar49[0x13] = 0;
            iVar32 = iVar32 + 0x18;
            iVar29 = *(int *)(this + 0x160);
            iVar30 = *(int *)(this + 0x164);
            iVar42 = *(int *)(this + 0x168);
            iVar31 = iVar31 + 1;
          } while (iVar31 < iVar29 + iVar20 + iVar30 + iVar42);
        }
      }
      if (bVar3) {
        local_98 = *(char **)((undefined1  [16])0x0 + (undefined1  [16])0x8);
        uStack_94 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
        puVar15 = (undefined4 *)((uint)&local_b8 | 4);
        local_b8 = 1.0;
        *puVar15 = 0;
        puVar15[1] = *(uint *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
        puVar15[2] = local_98;
        puVar15[3] = uStack_94;
        iStack_a4 = 0x3f800000;
        local_a0 = (ulonglong)*(uint *)((undefined1  [16])0x0 + (undefined1  [16])0x4) << 0x20;
        local_90 = 0x3f800000;
        uStack_88 = 0x3f8000003f800000;
        local_80 = 0x3f800000;
        local_7c = 0.0;
        local_78 = 0.0;
        local_74 = 0.0;
        (**(code **)(**(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + (iVar29 + iVar30) * 4) + 0x28)
        )(&local_10c);
        iVar29 = *(int *)(this + 0x160);
        iVar30 = *(int *)(this + 0x164);
        iVar42 = *(int *)(this + 0x168);
        iVar13 = iVar30 + iVar29 + iVar42;
        if (iVar13 < iVar29 + iVar25 + iVar30 + iVar42) {
          puVar15 = &DAT_002536c0;
          do {
            uVar12 = createStaticObject(this,(Waypoint *)0x0,0x1a76,true);
            *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar13 * 4) = uVar12;
            piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar13 * 4);
            Player::setMaxHitpoints((Player *)piVar49[1],1000);
            local_124 = (float)puVar15[-2];
            local_120 = (float)puVar15[-1];
            local_11c = (float)*puVar15;
            AbyssEngine::AEMath::MatrixRotateVector
                      ((AEMath *)&local_118,(Matrix *)&local_b8,(Vector *)&local_124);
            AbyssEngine::AEMath::Vector::operator=((Vector *)&local_7c,(Vector *)&local_118);
            AEGeometry::setRotation((Vector *)piVar49[2]);
            local_124 = (float)puVar15[-5];
            local_120 = (float)puVar15[-4];
            local_11c = (float)puVar15[-3];
            AbyssEngine::AEMath::MatrixRotateVector
                      ((AEMath *)&local_118,(Matrix *)&local_b8,(Vector *)&local_124);
            AbyssEngine::AEMath::Vector::operator=((Vector *)&local_7c,(Vector *)&local_118);
            local_118 = local_10c + local_7c;
            local_114 = local_108 + local_78;
            local_110 = local_104 + local_74;
            fVar55 = (float)(**(code **)(*piVar49 + 0x44))(piVar49,(AEMath *)&local_118);
            PlayerTurret::setScaling(fVar55);
            piVar49[9] = 1;
            piVar49[0x13] = 0;
            puVar15 = puVar15 + 6;
            iVar13 = iVar13 + 1;
            iVar29 = *(int *)(this + 0x160);
            iVar30 = *(int *)(this + 0x164);
            iVar42 = *(int *)(this + 0x168);
          } while (iVar13 < iVar29 + iVar25 + iVar30 + iVar42);
        }
      }
      if (bVar1) {
        iVar31 = Globals::getRandomEnemyFighter(Globals::globals,local_188);
        iVar13 = Status::hardCoreMode();
        if ((local_188 == 8) && (initStreamOutPosition != '\0')) {
          iVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
          iVar42 = 0x14;
          if (iVar13 != 0) {
            iVar42 = 0x28;
          }
          iVar13 = Status::getLevel(Globals::status);
          if (iVar29 < iVar13 + iVar42) {
            fVar55 = (float)PlayerEgo::getPosition();
            AbyssEngine::AEMath::operator/((AEMath *)&local_b8,(Vector *)&local_7c,fVar55);
            AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x18c),(Vector *)&local_b8);
            Route::setNewCoords(*(undefined4 *)(this + 0x180),*(undefined4 *)(this + 0x18c),
                                *(undefined4 *)(this + 400),*(undefined4 *)(this + 0x194));
          }
        }
        iVar29 = *(int *)(this + 0x160);
        iVar30 = *(int *)(this + 0x164);
        iVar34 = *(int *)(this + 0x168);
        iVar13 = *(int *)(this + 0x16c);
        iVar32 = iVar20 + iVar25 + iVar29 + iVar30;
        iVar42 = iVar34;
        if (iVar32 + iVar34 < iVar32 + iVar34 + iVar13) {
          iVar35 = iVar34 * 4;
          do {
            pWVar27 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x180));
            uVar12 = createShip(this,local_188,0,iVar31,pWVar27,true,false);
            *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar35 + iVar32 * 4) = uVar12;
            iVar13 = Status::inPirateLootOrbit(Globals::status);
            if (iVar13 == 1) {
              pPVar45 = *(Player **)
                         (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar35 + iVar32 * 4) + 4);
              iVar13 = Player::getMaxHitpoints(pPVar45);
              Player::setHitpoints(pPVar45,iVar13 << 1);
              piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar35 + iVar32 * 4);
              (**(code **)(*piVar49 + 0x1c))(piVar49,0x40600000);
              PlayerFighter::setRotate
                        (*(PlayerFighter **)
                          (*(int *)(*(int *)(this + 0xf8) + 4) + iVar35 + iVar32 * 4),3);
              PlayerEgo::getPosition();
              AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x18c),(Vector *)&local_b8);
              iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,50000);
              iVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
              iVar42 = -1;
              if (iVar29 == 0) {
                iVar42 = 1;
              }
              fVar55 = (float)VectorSignedToFloat(iVar42 * iVar13 + 20000,
                                                  (byte)(in_fpscr >> 0x16) & 3);
              *(float *)(this + 0x18c) = *(float *)(this + 0x18c) + fVar55;
              iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,50000);
              iVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
              iVar42 = -1;
              if (iVar29 == 0) {
                iVar42 = 1;
              }
              fVar55 = (float)VectorSignedToFloat(iVar42 * iVar13 + 10000,
                                                  (byte)(in_fpscr >> 0x16) & 3);
              *(float *)(this + 400) = *(float *)(this + 400) + fVar55;
              iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,50000);
              iVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
              iVar42 = -1;
              if (iVar29 == 0) {
                iVar42 = 1;
              }
              fVar55 = (float)VectorSignedToFloat(iVar42 * iVar13 + 20000,
                                                  (byte)(in_fpscr >> 0x16) & 3);
              *(float *)(this + 0x194) = *(float *)(this + 0x194) + fVar55;
              piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar35 + iVar32 * 4);
              (**(code **)(*piVar49 + 0x44))(piVar49,(Vector *)(this + 0x18c));
            }
            iVar32 = iVar32 + 1;
            iVar29 = *(int *)(this + 0x160);
            iVar30 = *(int *)(this + 0x164);
            iVar42 = *(int *)(this + 0x168);
            iVar13 = *(int *)(this + 0x16c);
          } while (iVar34 + iVar32 < iVar20 + iVar25 + iVar29 + iVar30 + iVar42 + iVar13);
        }
      }
      else {
        iVar13 = *(int *)(this + 0x16c);
      }
      iVar34 = iVar20 + iVar25 + iVar29 + iVar30 + iVar42;
      iVar32 = local_194 + iVar25 + iVar20;
      iVar31 = iVar13;
      if (iVar34 + iVar13 < iVar32 + iVar29 + iVar30 + iVar42 + iVar13) {
        do {
          iVar29 = Globals::getRandomEnemyFighter(Globals::globals,8);
          uVar12 = createShip(this,8,0,iVar29,(Waypoint *)0x0,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar13 * 4 + iVar34 * 4) = uVar12;
          PlayerEgo::getPosition();
          AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x18c),(Vector *)&local_b8);
          fVar59 = *(float *)(this + 0x18c);
          piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar13 * 4 + iVar34 * 4);
          pcVar39 = *(code **)(*piVar49 + 0x48);
          uVar12 = AbyssEngine::AERandom::nextInt(Globals::rnd,160000);
          fVar61 = *(float *)(this + 400);
          fVar62 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
          uVar12 = AbyssEngine::AERandom::nextInt(Globals::rnd,100000);
          fVar55 = *(float *)(this + 0x194);
          fVar63 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
          uVar12 = AbyssEngine::AERandom::nextInt(Globals::rnd,160000);
          fVar57 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
          (*pcVar39)(piVar49,fVar59 + -80000.0 + fVar62,fVar61 + -50000.0 + fVar63,
                     fVar55 + -80000.0 + fVar57);
          iVar34 = iVar34 + 1;
          iVar29 = *(int *)(this + 0x160);
          iVar30 = *(int *)(this + 0x164);
          iVar42 = *(int *)(this + 0x168);
          iVar31 = *(int *)(this + 0x16c);
        } while (iVar13 + iVar34 < iVar32 + iVar29 + iVar30 + iVar42 + iVar31);
      }
      if (iVar11 != 0) {
        local_b8 = 0.0;
        local_b4 = 0;
        iVar34 = local_194 + iVar11 + iVar25 + iVar20;
        iVar35 = iVar34 + iVar29 + iVar30 + iVar42 + iVar31;
        iVar13 = iVar31;
        if (iVar32 + iVar29 + iVar30 + iVar42 + iVar31 < iVar35) {
          iVar52 = iVar31 * 4;
          iVar32 = iVar29 + iVar25 + iVar20 + local_194 + iVar30 + iVar42;
          do {
            pSVar17 = (Station *)Status::getStation(Globals::status);
            iVar13 = Station::getPirateStationIndex(pSVar17);
            local_7c = *(float *)(&DAT_00253724 + iVar13 * 0xc);
            local_78 = *(float *)(&DAT_00253728 + iVar13 * 0xc);
            local_74 = *(float *)(&DAT_0025372c + iVar13 * 0xc);
            pRVar21 = operator_new(0x18);
            Route::Route(pRVar21,(int *)&local_7c,3);
            pWVar27 = (Waypoint *)Route::getWaypoint(pRVar21);
            uVar12 = createStaticObject(this,pWVar27,0x37a3,true);
            *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar52 + iVar32 * 4) = uVar12;
            piVar49 = (int *)Route::getWaypoint(pRVar21);
            (**(code **)(*piVar49 + 0x28))((Vector *)&local_10c);
            AbyssEngine::AEMath::Vector::operator=((Vector *)&local_b8,(Vector *)&local_10c);
            KIPlayer::setToSleep
                      (*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar52 + iVar32 * 4));
            iVar13 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar52 + iVar32 * 4);
            pSVar36 = (String *)GameText::getText(Globals::gameText,0x1b9);
            AbyssEngine::String::operator=((String *)(iVar13 + 0x18),pSVar36);
            iVar32 = iVar32 + 1;
            iVar29 = *(int *)(this + 0x160);
            iVar30 = *(int *)(this + 0x164);
            iVar42 = *(int *)(this + 0x168);
            iVar13 = *(int *)(this + 0x16c);
            iVar35 = iVar34 + iVar29 + iVar30 + iVar42 + iVar13;
          } while (iVar31 + iVar32 < iVar35);
        }
        iVar31 = iVar20 + local_194 + iVar41 + iVar25;
        if (iVar35 < iVar29 + iVar31 + iVar30 + iVar42 + iVar13) {
          do {
            iVar13 = Globals::getRandomEnemyFighter(Globals::globals,8);
            uVar12 = createShip(this,8,0,iVar13,(Waypoint *)0x0,true,false);
            fVar55 = local_b8;
            *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar35 * 4) = uVar12;
            iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
            iVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
            fVar57 = (float)local_b4;
            iVar42 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
            iVar30 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
            iVar32 = -1;
            if (iVar30 == 0) {
              iVar32 = 1;
            }
            iVar30 = -1;
            if (iVar29 == 0) {
              iVar30 = 1;
            }
            fVar59 = local_b4._4_4_;
            iVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
            fVar61 = (float)VectorSignedToFloat(iVar30 * iVar13 + 10000,(byte)(in_fpscr >> 0x16) & 3
                                               );
            fVar62 = (float)VectorSignedToFloat(iVar32 * iVar42 + 10000,(byte)(in_fpscr >> 0x16) & 3
                                               );
            iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
            iVar42 = -1;
            if (iVar13 == 0) {
              iVar42 = 1;
            }
            fVar63 = (float)VectorSignedToFloat(iVar42 * iVar29 + 10000,(byte)(in_fpscr >> 0x16) & 3
                                               );
            uVar56 = VectorSignedToFloat((int)(fVar55 + fVar61),(byte)(in_fpscr >> 0x16) & 3);
            uVar58 = VectorSignedToFloat((int)(fVar57 + fVar62),(byte)(in_fpscr >> 0x16) & 3);
            uVar12 = VectorSignedToFloat((int)(fVar59 + fVar63),(byte)(in_fpscr >> 0x16) & 3);
            piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar35 * 4);
            (**(code **)(*piVar49 + 0x48))(piVar49,uVar56,uVar58,uVar12);
            KIPlayer::setToSleep(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar35 * 4));
            iVar13 = iVar35 * 4;
            iVar35 = iVar35 + 1;
            *(undefined1 *)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar13) + 299) = 1;
          } while (iVar35 < *(int *)(this + 0x160) + iVar31 + *(int *)(this + 0x164) +
                            *(int *)(this + 0x168) + *(int *)(this + 0x16c));
        }
      }
      if (0 < iVar19) {
        PlayerEgo::getPosition();
        AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x18c),(Vector *)&local_b8);
        iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,50000);
        iVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
        iVar42 = -1;
        if (iVar29 == 0) {
          iVar42 = 1;
        }
        iVar30 = -1;
        fVar55 = (float)VectorSignedToFloat(iVar42 * iVar13 + 20000,(byte)(in_fpscr >> 0x16) & 3);
        *(float *)(this + 0x18c) = *(float *)(this + 0x18c) + fVar55;
        iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,50000);
        iVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
        iVar42 = -1;
        if (iVar29 == 0) {
          iVar42 = 1;
        }
        fVar55 = (float)VectorSignedToFloat(iVar42 * iVar13 + 10000,(byte)(in_fpscr >> 0x16) & 3);
        *(float *)(this + 400) = *(float *)(this + 400) + fVar55;
        iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,50000);
        iVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
        if (iVar29 == 0) {
          iVar30 = 1;
        }
        fVar55 = (float)VectorSignedToFloat(iVar30 * iVar13 + 20000,(byte)(in_fpscr >> 0x16) & 3);
        fVar57 = *(float *)(this + 0x194);
        *(float *)(this + 0x194) = fVar57 + fVar55;
        local_b8 = (float)(int)*(float *)(this + 0x18c);
        local_b4 = CONCAT44((int)(fVar57 + fVar55),(int)*(float *)(this + 400));
        pRVar21 = operator_new(0x18);
        Route::Route(pRVar21,(int *)&local_b8,3);
        iVar13 = *(int *)(this + 0x160);
        iVar30 = *(int *)(this + 0x164);
        iVar31 = *(int *)(this + 0x168);
        iVar29 = *(int *)(this + 0x16c);
        iVar42 = iVar19 + iVar41 + local_194 + iVar25 + iVar20;
        if (iVar41 + local_194 + iVar25 + iVar20 + iVar13 + iVar30 + iVar31 + iVar29 <
            iVar42 + iVar13 + iVar30 + iVar31 + iVar29) {
          iVar29 = iVar13 + iVar25 + iVar20 + local_194 + (int)fVar54 + iVar30 + iVar31 + iVar29;
          do {
            pWVar27 = (Waypoint *)Route::getWaypoint(pRVar21);
            uVar12 = createShip(this,10,0,0x2c,pWVar27,true,false);
            *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar11 * 4 + iVar29 * 4) = uVar12;
            Player::setAlwaysEnemy
                      (*(Player **)
                        (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar11 * 4 + iVar29 * 4) + 4
                        ),true);
            iVar29 = iVar29 + 1;
          } while (iVar11 + iVar29 <
                   *(int *)(this + 0x160) + iVar42 + *(int *)(this + 0x164) + *(int *)(this + 0x168)
                   + *(int *)(this + 0x16c));
        }
        pvVar47 = (void *)Route::~Route(pRVar21);
        operator_delete(pvVar47);
      }
      if (local_1c4 != 0) {
        *(int *)(this + 0xac) =
             *(int *)(this + 0x160) + iVar19 + iVar41 + local_194 + iVar25 + iVar20 +
             *(int *)(this + 0x164) + *(int *)(this + 0x168) + *(int *)(this + 0x16c);
        pWVar27 = operator_new(0x134);
        Waypoint::Waypoint(pWVar27,-90000,0,20000,(Route *)0x0);
        uVar12 = createStaticObject(this,pWVar27,0x4a88,true);
        iVar11 = *(int *)(this + 0xac);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar11 * 4) = uVar12;
        PlayerFixedObject::setDockingType
                  (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar11 * 4),1);
        PlayerFixedObject::setMoving
                  (*(PlayerFixedObject **)
                    (*(int *)(*(int *)(this + 0xf8) + 4) + *(int *)(this + 0xac) * 4),false);
        piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + *(int *)(this + 0xac) * 4);
        (**(code **)(*piVar49 + 0x44))(piVar49,this + 200);
        Player::setAlwaysFriend
                  (*(Player **)
                    (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + *(int *)(this + 0xac) * 4) + 4),
                   true);
        pPVar50 = *(PlayerFixedObject **)
                   (*(int *)(*(int *)(this + 0xf8) + 4) + *(int *)(this + 0xac) * 4);
        pSVar36 = (String *)GameText::getText(Globals::gameText,0xc8a);
        AbyssEngine::String::String(aSStack_140,pSVar36,false);
        PlayerFixedObject::setName(pPVar50,aSStack_140);
        AbyssEngine::String::~String(aSStack_140);
      }
      if (iVar18 == 1) {
        iVar18 = *(int *)(this + 0x160);
        iVar42 = *(int *)(this + 0x164);
        iVar30 = *(int *)(this + 0x168);
        iVar29 = *(int *)(this + 0x16c);
        pSVar17 = (Station *)Status::getStation(Globals::status);
        iVar11 = Station::getHiddenBlueprintIndex(pSVar17);
        iVar13 = 0xf;
        if (iVar11 == 0) {
          iVar13 = 0xd;
        }
        uVar12 = createShip(this,*(int *)(&DAT_00253754 + iVar11 * 4),1,iVar13,(Waypoint *)0x0,true,
                            false);
        iVar29 = iVar19 + iVar41 + local_194 + local_1c4 + iVar25 + iVar20 + iVar18 + iVar42 +
                 iVar30 + iVar29;
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar29 * 4) = uVar12;
        pPVar50 = *(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar29 * 4);
        PlayerFixedObject::setDockingType(pPVar50,3);
        pSVar17 = (Station *)Status::getStation(Globals::status);
        PVar9 = (PlayerFixedObject)Station::stationHasHiddenBlueprint(pSVar17,false);
        pPVar50[0x6c] = PVar9;
        (**(code **)(*(int *)pPVar50 + 0x44))(pPVar50,this + 200);
        PlayerFixedObject::setDeadButSelectable(pPVar50);
        piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar29 * 4);
        (**(code **)(*piVar49 + 0x48))
                  (piVar49,*(undefined4 *)(&DAT_00253768 + iVar11 * 0xc),
                   *(undefined4 *)(&DAT_0025376c + iVar11 * 0xc),
                   *(undefined4 *)(&DAT_00253770 + iVar11 * 0xc));
        pvVar47 = *(void **)(pPVar50 + 0x4c);
        if (pvVar47 != (void *)0x0) {
          if (*(void **)((int)pvVar47 + 4) != (void *)0x0) {
            operator_delete__(*(void **)((int)pvVar47 + 4));
          }
          operator_delete(pvVar47);
        }
        *(undefined4 *)(pPVar50 + 0x4c) = 0;
        pSVar17 = (Station *)Status::getStation(Globals::status);
        iVar13 = Station::stationHasHiddenBlueprint(pSVar17,false);
        if (iVar13 == 1) {
          this_03 = operator_new(1);
          Generator::Generator(this_03);
          uVar12 = Generator::getLootList(this_03,0x73,1);
          *(undefined4 *)(pPVar50 + 0x4c) = uVar12;
          pvVar47 = (void *)Generator::~Generator(this_03);
          operator_delete(pvVar47);
        }
        this_04 = operator_new(1);
        FileRead::FileRead(this_04);
        pAVar14 = (Array *)FileRead::loadSpacePoints
                                     (this_04,*(int *)(&DAT_002537a4 + iVar11 * 4),-1);
        pvVar47 = (void *)FileRead::~FileRead(this_04);
        operator_delete(pvVar47);
        KIPlayer::setSpacePoints((KIPlayer *)pPVar50,pAVar14);
      }
      if (bVar53) {
        iVar11 = **(int **)(*(int *)(this + 0xf8) + 4);
        pSVar36 = (String *)GameText::getText(Globals::gameText,0x67f);
        AbyssEngine::String::operator=((String *)(iVar11 + 0x18),pSVar36);
      }
    }
  }
  else {
    pSVar16 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar11 = SolarSystem::getRace(pSVar16);
    iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
    if (iVar13 < 0x4b) {
      iVar13 = 8;
    }
    else {
      pSVar22 = (Standing *)Status::getStanding(Globals::status);
      iVar13 = Standing::getEnemyRace(pSVar22,iVar11);
    }
    iVar18 = Mission::getType(pMVar10);
    switch(iVar18) {
    case 1:
      iVar18 = AbyssEngine::AERandom::nextInt(Globals::rnd,100000);
      local_b8 = (float)(iVar18 + -50000);
      local_b4 = 0xc35000000000;
      local_ac = AbyssEngine::AERandom::nextInt(Globals::rnd,100000);
      local_ac = local_ac + -50000;
      local_a8 = 0;
      iStack_a4 = 75000;
      iVar18 = AbyssEngine::AERandom::nextInt(Globals::rnd,100000);
      local_a0 = (ulonglong)(iVar18 - 50000);
      local_98 = "\x04";
      pRVar21 = operator_new(0x18);
      Route::Route(pRVar21,(int *)&local_b8,9);
      *(Route **)(this + 0x110) = pRVar21;
      pMVar10 = (Mission *)Status::getMission(Globals::status);
      uVar12 = Mission::getDifficulty(pMVar10);
      fVar54 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
      iVar18 = AbyssEngine::AERandom::nextInt(Globals::rnd,5);
      fVar54 = (float)VectorSignedToFloat((int)((fVar54 / 10.0) * 5.0) + 3,
                                          (byte)(in_fpscr >> 0x16) & 3);
      uVar44 = (uint)(fVar54 + ((float)Globals::options._44_4_ + -0.5) * fVar54);
      pAVar14 = operator_new(0xc);
      puVar15 = operator_new__(4);
      *(undefined4 **)(pAVar14 + 4) = puVar15;
      *puVar15 = 0;
      *(undefined4 *)(pAVar14 + 8) = 1;
      *(undefined4 *)pAVar14 = 0;
      *(Array **)(this + 0xf8) = pAVar14;
      ArraySetLength<KIPlayer*>(iVar18 + uVar44 + 3,pAVar14);
      if (0 < (int)uVar44) {
        uVar51 = 0;
        do {
          iVar18 = Globals::getRandomEnemyFighter(Globals::globals,iVar13);
          uVar12 = createShip(this,iVar13,0,iVar18,(Waypoint *)0x0,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar51 * 4) = uVar12;
          Player::setAlwaysEnemy
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar51 * 4) + 4),
                     true);
          uVar51 = uVar51 + 1;
        } while (uVar44 != uVar51);
      }
      uVar51 = uVar44;
      if (uVar44 < **(uint **)(this + 0xf8)) {
        do {
          iVar13 = Globals::getRandomEnemyFighter(Globals::globals,iVar11);
          pAVar8 = Globals::rnd;
          pRVar21 = *(Route **)(this + 0x110);
          iVar18 = Route::length(pRVar21);
          iVar18 = AbyssEngine::AERandom::nextInt(pAVar8,iVar18);
          pWVar27 = (Waypoint *)Route::getWaypoint(pRVar21,iVar18);
          uVar12 = createShip(this,iVar11,0,iVar13,pWVar27,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar51 * 4) = uVar12;
          Player::setAlwaysFriend
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar51 * 4) + 4),
                     true);
          uVar51 = uVar51 + 1;
        } while (uVar51 < **(uint **)(this + 0xf8));
      }
      pOVar28 = operator_new(0x1c);
      Objective::Objective(pOVar28,7,uVar44,this);
      *(Objective **)(this + 0x28) = pOVar28;
      break;
    case 2:
      local_e0 = 0;
      fStack_dc = 0.0;
      local_d8 = 0;
      iVar18 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
      fVar54 = (float)VectorSignedToFloat(-20000 - iVar18,(byte)(in_fpscr >> 0x16) & 3);
      local_b8 = (float)(int)fVar54;
      local_b4 = local_b4 & 0xffffffff00000000;
      iVar18 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
      fVar54 = (float)VectorSignedToFloat(-20000 - iVar18,(byte)(in_fpscr >> 0x16) & 3);
      local_b4 = CONCAT44((int)fVar54,(float)local_b4);
      local_ac = 0;
      local_a8 = 0;
      iStack_a4 = 0;
      pRVar21 = operator_new(0x18);
      Route::Route(pRVar21,(int *)&local_b8,6);
      *(Route **)(this + 0x110) = pRVar21;
      iVar18 = Mission::getProductionGoodAmount(pMVar10);
      uVar12 = Mission::getDifficulty(pMVar10);
      fVar54 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
      iVar19 = (int)((fVar54 / 10.0) * 4.0);
      pAVar14 = operator_new(0xc);
      puVar15 = operator_new__(4);
      *(undefined4 **)(pAVar14 + 4) = puVar15;
      *puVar15 = 0;
      *(undefined4 *)(pAVar14 + 8) = 1;
      *(undefined4 *)pAVar14 = 0;
      *(Array **)(this + 0xf8) = pAVar14;
      uVar44 = iVar19 + 2;
      ArraySetLength<KIPlayer*>(uVar44 + iVar18,pAVar14);
      if (-2 < iVar19) {
        iVar20 = 0;
        iVar25 = 0;
        do {
          iVar29 = Globals::getRandomEnemyFighter(Globals::globals,iVar13);
          uVar12 = createShip(this,iVar13,0,iVar29,(Waypoint *)0x0,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar25 * 4) = uVar12;
          piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar25 * 4);
          pcVar39 = *(code **)(*piVar49 + 0x48);
          iVar29 = Route::getWaypoint(*(Route **)(this + 0x110),0);
          iVar41 = *(int *)(iVar29 + 0x120);
          iVar29 = Route::getWaypoint(*(Route **)(this + 0x110),0);
          iVar42 = *(int *)(iVar29 + 0x124);
          iVar29 = Route::getWaypoint(*(Route **)(this + 0x110),0);
          uVar12 = VectorSignedToFloat(iVar20 + iVar41,(byte)(in_fpscr >> 0x16) & 3);
          uVar56 = VectorSignedToFloat(iVar20 + iVar42,(byte)(in_fpscr >> 0x16) & 3);
          uVar58 = VectorSignedToFloat(*(int *)(iVar29 + 0x128) + iVar20,
                                       (byte)(in_fpscr >> 0x16) & 3);
          (*pcVar39)(piVar49,uVar12,uVar56,uVar58);
          Player::setAlwaysEnemy
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar25 * 4) + 4),
                     true);
          pKVar46 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar25 * 4);
          pRVar21 = (Route *)Route::clone(*(Route **)(this + 0x110));
          KIPlayer::setRoute(pKVar46,pRVar21);
          pRVar21 = (Route *)KIPlayer::getRoute(*(KIPlayer **)
                                                 (*(int *)(*(int *)(this + 0xf8) + 4) + iVar25 * 4))
          ;
          Route::reachWaypoint(pRVar21,0);
          iVar25 = iVar25 + 1;
          iVar20 = iVar20 + 2000;
        } while (iVar25 < (int)uVar44);
      }
      if (uVar44 < **(uint **)(this + 0xf8)) {
        iVar20 = 0;
        iVar13 = iVar19 * 4 + 8;
        do {
          iVar19 = Globals::getRandomEnemyFighter(Globals::globals,iVar11);
          uVar12 = createShip(this,iVar11,0,iVar19,(Waypoint *)0x0,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar13 + iVar20 * 4) = uVar12;
          Player::setAlwaysFriend
                    (*(Player **)
                      (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar13 + iVar20 * 4) + 4),true
                    );
          (**(code **)(**(int **)((*(uint **)(this + 0xfc))[1] +
                                 (iVar20 + (**(uint **)(this + 0xfc) >> 1)) * 4) + 0x28))
                    ((Vector *)local_70);
          AbyssEngine::AEMath::Vector::operator=((Vector *)&local_e0,(Vector *)local_70);
          piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar13 + iVar20 * 4);
          (**(code **)(*piVar49 + 0x48))(piVar49,local_e0,fStack_dc + 2000.0,local_d8);
          iVar19 = *(int *)(*(int *)(this + 0xf8) + 4) + iVar13;
          iVar25 = *(int *)(iVar19 + iVar20 * 4);
          *(undefined1 *)(iVar25 + 0x48) = 0;
          *(undefined4 *)(iVar25 + 0x4c) = 0;
          piVar49 = *(int **)(iVar19 + iVar20 * 4);
          fVar54 = (float)(**(code **)(*piVar49 + 0x1c))(piVar49,0);
          KIPlayer::setRotationSpeed
                    (*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar13 + iVar20 * 4),
                     fVar54);
          pPVar45 = *(Player **)
                     (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar13 + iVar20 * 4) + 4);
          iVar19 = Player::getMaxHitpoints(pPVar45);
          Player::setHitpoints(pPVar45,iVar19 * 3);
          iVar20 = iVar20 + 1;
        } while (uVar44 + iVar20 < **(uint **)(this + 0xf8));
      }
      pOVar28 = operator_new(0x1c);
      Objective::Objective(pOVar28,0x12,0,uVar44,this);
      *(Objective **)(this + 0x28) = pOVar28;
      pOVar28 = operator_new(0x1c);
      Objective::Objective(pOVar28,0x12,uVar44,uVar44 + iVar18,this);
      *(Objective **)(this + 0x2c) = pOVar28;
      break;
    case 3:
    case 5:
      iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,80000);
      iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
      iVar18 = -1;
      if (iVar13 == 0) {
        iVar18 = 1;
      }
      local_b8 = (float)((iVar11 + 40000) * iVar18);
      iVar18 = -1;
      local_b4 = (ulonglong)(uint)local_b4._4_4_ << 0x20;
      iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,80000);
      iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
      if (iVar13 == 0) {
        iVar18 = 1;
      }
      local_b4 = CONCAT44(iVar18 * (iVar11 + 40000),(float)local_b4);
      pRVar21 = operator_new(0x18);
      Route::Route(pRVar21,(int *)&local_b8,3);
      *(Route **)(this + 0x108) = pRVar21;
      puVar15 = operator_new(0xc);
      puVar33 = operator_new__(4);
      puVar15[1] = puVar33;
      *puVar33 = 0;
      puVar15[2] = 1;
      *puVar15 = 0;
      *(undefined4 **)(this + 0xf8) = puVar15;
      uVar44 = Mission::getProductionGoodAmount(pMVar10);
      ArraySetLength<KIPlayer*>(uVar44,*(Array **)(this + 0xf8));
      puVar40 = *(uint **)(this + 0xf8);
      if (*puVar40 == 0) {
        iVar11 = -1;
      }
      else {
        uVar44 = 0;
        do {
          iVar11 = Globals::getRandomEnemyFighter(Globals::globals,8);
          pWVar27 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x108),0);
          uVar12 = createShip(this,8,0,iVar11,pWVar27,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar44 * 4) = uVar12;
          KIPlayer::setToSleep(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar44 * 4));
          puVar40 = *(uint **)(this + 0xf8);
          uVar44 = uVar44 + 1;
        } while (uVar44 < *puVar40);
        iVar11 = *puVar40 - 1;
      }
      PlayerFighter::setMissionCrate(*(PlayerFighter **)(puVar40[1] + iVar11 * 4),true);
      iVar11 = *(int *)((*(int **)(this + 0xf8))[1] + **(int **)(this + 0xf8) * 4 + -4);
      pSVar36 = (String *)GameText::getText(Globals::gameText,0x64b);
      AbyssEngine::String::operator=((String *)(iVar11 + 0x18),pSVar36);
      pOVar28 = operator_new(0x1c);
      Objective::Objective(pOVar28,0xb,**(int **)(this + 0xf8) + -1,this);
      *(Objective **)(this + 0x28) = pOVar28;
      pOVar28 = operator_new(0x1c);
      Objective::Objective(pOVar28,0xc,**(int **)(this + 0xf8) + -1,this);
      *(Objective **)(this + 0x2c) = pOVar28;
      break;
    case 4:
      iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
      if (iVar11 == 0) {
        local_b8 = (float)(int)*(float *)(this + 200);
        local_b4 = CONCAT44((int)*(float *)(this + 0xd0),(int)*(float *)(this + 0xcc));
        pRVar21 = operator_new(0x18);
        Route::Route(pRVar21,(int *)&local_b8,3);
        *(Route **)(this + 0x108) = pRVar21;
      }
      else {
        pLVar23 = (Level *)AbyssEngine::AERandom::nextInt(Globals::rnd,2);
        uVar12 = createRoute(pLVar23,(int)(pLVar23 + 2));
        *(undefined4 *)(this + 0x108) = uVar12;
      }
      pMVar10 = (Mission *)Status::getMission(Globals::status);
      uVar12 = Mission::getDifficulty(pMVar10);
      fVar54 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
      fVar54 = (float)VectorSignedToFloat((int)((fVar54 / 10.0) * 5.0) + 2,
                                          (byte)(in_fpscr >> 0x16) & 3);
      uVar44 = (uint)(fVar54 + ((float)Globals::options._44_4_ + -0.5) * fVar54);
      pAVar14 = operator_new(0xc);
      puVar15 = operator_new__(4);
      *(undefined4 **)(pAVar14 + 4) = puVar15;
      *(undefined4 *)(pAVar14 + 8) = 1;
      *puVar15 = 0;
      *(undefined4 *)pAVar14 = 0;
      *(Array **)(this + 0xf8) = pAVar14;
      ArraySetLength<KIPlayer*>(uVar44,pAVar14);
      if (**(int **)(this + 0xf8) != 0) {
        uVar51 = 0;
        do {
          iVar11 = Globals::getRandomEnemyFighter(Globals::globals,8);
          pAVar8 = Globals::rnd;
          pRVar21 = *(Route **)(this + 0x108);
          iVar13 = Route::length(pRVar21);
          iVar13 = AbyssEngine::AERandom::nextInt(pAVar8,iVar13);
          pWVar27 = (Waypoint *)Route::getWaypoint(pRVar21,iVar13);
          uVar12 = createShip(this,8,0,iVar11,pWVar27,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar51 * 4) = uVar12;
          KIPlayer::setToSleep(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar51 * 4));
          uVar51 = uVar51 + 1;
        } while (uVar51 < **(uint **)(this + 0xf8));
      }
      pOVar28 = operator_new(0x1c);
      Objective::Objective(pOVar28,0x12,0,uVar44,this);
      *(Objective **)(this + 0x28) = pOVar28;
      break;
    case 6:
      iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,80000);
      iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
      iVar18 = -1;
      if (iVar13 == 0) {
        iVar18 = 1;
      }
      local_b8 = (float)((iVar11 + 60000) * iVar18);
      iVar18 = -1;
      local_b4 = (ulonglong)(uint)local_b4._4_4_ << 0x20;
      iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,80000);
      iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
      if (iVar13 == 0) {
        iVar18 = 1;
      }
      local_b4 = CONCAT44(iVar18 * (iVar11 + 60000),(float)local_b4);
      pRVar21 = operator_new(0x18);
      Route::Route(pRVar21,(int *)&local_b8,3);
      *(Route **)(this + 0x108) = pRVar21;
      pAVar14 = operator_new(0xc);
      puVar15 = operator_new__(4);
      *(undefined4 **)(pAVar14 + 4) = puVar15;
      *puVar15 = 0;
      *(undefined4 *)(pAVar14 + 8) = 1;
      *(undefined4 *)pAVar14 = 0;
      *(Array **)(this + 0xf8) = pAVar14;
      ArraySetLength<KIPlayer*>(1,pAVar14);
      iVar11 = Globals::getRandomEnemyFighter(Globals::globals,8);
      pWVar27 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x108),0);
      uVar12 = createShip(this,8,0,iVar11,pWVar27,true,false);
      **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar12;
      KIPlayer::setToSleep((KIPlayer *)**(undefined4 **)(*(int *)(this + 0xf8) + 4));
      pPVar45 = *(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4);
      iVar11 = Player::getMaxHitpoints(pPVar45);
      Player::setMaxHitpoints(pPVar45,iVar11 * 3);
      (**(code **)(*(int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4) + 0x1c))
                ((int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),0x40400000);
      PlayerFighter::setRotate((PlayerFighter *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),3);
      pOVar28 = operator_new(0x1c);
      Objective::Objective(pOVar28,1,0,this);
      goto LAB_000c12b6;
    case 7:
      iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,40000);
      local_b8 = (float)(iVar11 + -20000);
      iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
      local_b4 = CONCAT44(local_b4._4_4_,iVar11 + -10000);
      iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,30000);
      local_b4 = CONCAT44(iVar11 + 40000,(float)local_b4);
      pRVar21 = operator_new(0x18);
      Route::Route(pRVar21,(int *)&local_b8,3);
      pMVar10 = (Mission *)Status::getMission(Globals::status);
      uVar12 = Mission::getDifficulty(pMVar10);
      fVar54 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
      uVar60 = (uint)(fVar54 / 10.0 + fVar54 / 10.0);
      pMVar10 = (Mission *)Status::getMission(Globals::status);
      uVar12 = Mission::getDifficulty(pMVar10);
      pAVar14 = operator_new(0xc);
      puVar15 = operator_new__(4);
      uVar51 = 0;
      fVar54 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
      *(undefined4 **)(pAVar14 + 4) = puVar15;
      *(undefined4 *)(pAVar14 + 8) = 1;
      *puVar15 = 0;
      *(undefined4 *)pAVar14 = 0;
      *(Array **)(this + 0xf8) = pAVar14;
      ArraySetLength<KIPlayer*>((int)((fVar54 / 10.0) * 20.0) + uVar60 + 0xf,pAVar14);
      puVar40 = *(uint **)(this + 0xf8);
      uVar44 = *puVar40;
      if (uVar44 != uVar60) {
        uVar48 = 0;
        do {
          pWVar27 = (Waypoint *)Route::getWaypoint(pRVar21,0);
          uVar12 = createStaticObject(this,pWVar27,0x4215,true);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar48 * 4) = uVar12;
          Player::setAlwaysEnemy
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar48 * 4) + 4),
                     true);
          puVar40 = *(uint **)(this + 0xf8);
          uVar48 = uVar48 + 1;
          uVar44 = *puVar40;
          uVar51 = uVar44 - uVar60;
        } while (uVar48 < uVar51);
      }
      if (uVar51 < uVar44) {
        do {
          iVar11 = Globals::getRandomEnemyFighter(Globals::globals,8);
          uVar12 = createShip(this,8,0,iVar11,(Waypoint *)0x0,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar51 * 4) = uVar12;
          uVar51 = uVar51 + 1;
          puVar40 = *(uint **)(this + 0xf8);
        } while (uVar51 < *puVar40);
      }
      pOVar28 = operator_new(0x1c);
      Objective::Objective(pOVar28,7,*puVar40 - uVar60,this);
      *(Objective **)(this + 0x28) = pOVar28;
      *(undefined4 *)(this + 0x130) = 0x1d8a8;
      Globals::addSoundResourceToList(Globals::globals,0x16);
      break;
    case 8:
    case 0xb:
    case 0xd:
    case 0xe:
      break;
    case 9:
      local_a8 = 0;
      local_b8 = 1.4013e-41;
      local_b4 = 0x186a000000000;
      local_ac = 10000;
      iStack_a4 = 150000;
      local_a0 = 10000;
      local_98 = "ppEPFvPS0_E";
      pRVar21 = operator_new(0x18);
      Route::Route(pRVar21,(int *)&local_b8,9);
      *(Route **)(this + 0x110) = pRVar21;
      pMVar38 = (Mission *)Status::getMission(Globals::status);
      uVar12 = Mission::getDifficulty(pMVar38);
      fVar54 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
      fVar54 = (float)VectorSignedToFloat((int)((fVar54 / 10.0) * 5.0) + 3,
                                          (byte)(in_fpscr >> 0x16) & 3);
      iVar18 = (int)(fVar54 + ((float)Globals::options._44_4_ + -0.5) * fVar54);
      pAVar14 = operator_new(0xc);
      puVar15 = operator_new__(4);
      *(undefined4 **)(pAVar14 + 4) = puVar15;
      *(undefined4 *)(pAVar14 + 8) = 1;
      *puVar15 = 0;
      local_15c = 0.0;
      *(undefined4 *)pAVar14 = 0;
      *(Array **)(this + 0xf8) = pAVar14;
      ArraySetLength<KIPlayer*>(iVar18 + 5U,pAVar14);
      pSVar22 = (Standing *)Status::getStanding(Globals::status);
      iVar11 = Mission::getClientRace(pMVar10);
      iVar11 = Standing::getEnemyRace(pSVar22,iVar11);
      iVar13 = Mission::getClientRace(pMVar10);
      if (iVar13 < 4) {
        local_15c = (float)Mission::getClientRace(pMVar10);
      }
      puVar40 = *(uint **)(this + 0xf8);
      if (*puVar40 != 0) {
        iVar13 = 0xf;
        if (local_15c == 1.4013e-45) {
          iVar13 = 0xd;
        }
        uVar44 = 0;
        do {
          if ((int)uVar44 < iVar18) {
            iVar19 = Globals::getRandomEnemyFighter(Globals::globals,iVar11);
            pAVar8 = Globals::rnd;
            pRVar21 = *(Route **)(this + 0x110);
            iVar20 = Route::length(pRVar21);
            iVar20 = AbyssEngine::AERandom::nextInt(pAVar8,iVar20);
            pWVar27 = (Waypoint *)Route::getWaypoint(pRVar21,iVar20);
            uVar12 = createShip(this,iVar11,0,iVar19,pWVar27,true,false);
            *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar44 * 4) = uVar12;
            KIPlayer::setToSleep(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar44 * 4));
            Player::setAlwaysEnemy
                      (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar44 * 4) + 4),
                       true);
            puVar40 = *(uint **)(this + 0xf8);
          }
          else {
            uVar12 = createShip(this,(int)local_15c,1,iVar13,(Waypoint *)0x0,true,false);
            *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar44 * 4) = uVar12;
            pPVar45 = *(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar44 * 4) + 4);
            iVar19 = Status::getLevel(Globals::status);
            if (iVar19 < 0x15) {
              iVar19 = Status::getLevel(Globals::status);
            }
            else {
              iVar19 = 0x14;
            }
            fVar54 = (float)VectorSignedToFloat(iVar19 << 1,(byte)(in_fpscr >> 0x16) & 3);
            iVar19 = Status::gameWon(Globals::status);
            if (iVar19 == 0) {
              iVar19 = Status::getCurrentCampaignMission(Globals::status);
            }
            else {
              iVar19 = 0x2d;
            }
            fVar57 = (float)VectorSignedToFloat(iVar19 << 1,(byte)(in_fpscr >> 0x16) & 3);
            uVar51 = in_fpscr & 0xfffffff | (uint)((float)Globals::options._44_4_ < 0.7) << 0x1f |
                     (uint)((float)Globals::options._44_4_ == 0.7) << 0x1e;
            in_fpscr = uVar51 | (uint)NAN((float)Globals::options._44_4_) << 0x1c;
            bVar7 = (byte)(uVar51 >> 0x18);
            fVar55 = 1.0;
            if (!(bool)(bVar7 >> 6 & 1) && bVar7 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
              fVar55 = 1.4;
            }
            Player::setMaxHitpoints(pPVar45,(int)((fVar54 + 150.0 + fVar57) * fVar55));
            PlayerFixedObject::setMoving
                      (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar44 * 4),
                       true);
            Player::setAlwaysFriend
                      (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar44 * 4) + 4),
                       true);
            puVar40 = *(uint **)(this + 0xf8);
            iVar19 = *(int *)(puVar40[1] + uVar44 * 4);
            *(undefined1 *)(iVar19 + 0x48) = 0;
            *(undefined4 *)(iVar19 + 0x4c) = 0;
          }
          uVar44 = uVar44 + 1;
        } while (uVar44 < *puVar40);
      }
      piVar49 = *(int **)(puVar40[1] + iVar18 * 4);
      (**(code **)(*piVar49 + 0x48))(piVar49,0xc51c4000,0xc3960000,0x46d2f000);
      piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar18 * 4 + 4);
      (**(code **)(*piVar49 + 0x48))(piVar49,0x45cb2000,0x453b8000,0x46bb8000);
      piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar18 * 4 + 8);
      (**(code **)(*piVar49 + 0x48))(piVar49,0xc57a0000,0xc4fa0000,0x46947000);
      piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar18 * 4 + 0xc);
      (**(code **)(*piVar49 + 0x48))(piVar49,0x460ca000,0xc5bb8000,0x4684d000);
      piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar18 * 4 + 0x10);
      (**(code **)(*piVar49 + 0x48))(piVar49,0x453b8000,0x45dac000,0x466a6000);
      pOVar28 = operator_new(0x1c);
      Objective::Objective(pOVar28,0x12,0,iVar18,this);
      *(Objective **)(this + 0x28) = pOVar28;
      pOVar28 = operator_new(0x1c);
      Objective::Objective(pOVar28,0x12,iVar18,iVar18 + 5U,this);
      *(Objective **)(this + 0x2c) = pOVar28;
      break;
    case 10:
      iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,5000);
      local_b8 = (float)(iVar11 + -0x9c4);
      iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,5000);
      local_b4 = CONCAT44(local_b4._4_4_,iVar11 + -0x9c4);
      iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,30000);
      local_b4 = CONCAT44(iVar11 + 80000,(float)local_b4);
      local_ac = AbyssEngine::AERandom::nextInt(Globals::rnd,5000);
      local_ac = local_ac + -0x9c4;
      local_a8 = AbyssEngine::AERandom::nextInt(Globals::rnd,5000);
      local_a8 = local_a8 + -0x9c4;
      iStack_a4 = AbyssEngine::AERandom::nextInt(Globals::rnd,30000);
      iStack_a4 = iStack_a4 + 120000;
      pRVar21 = operator_new(0x18);
      Route::Route(pRVar21,(int *)&local_b8,6);
      *(Route **)(this + 0x108) = pRVar21;
      iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
      pMVar38 = (Mission *)Status::getMission(Globals::status);
      uVar56 = Mission::getDifficulty(pMVar38);
      uVar12 = Globals::options._44_4_;
      fVar54 = (float)VectorSignedToFloat(uVar56,(byte)(in_fpscr >> 0x16) & 3);
      pSVar22 = (Standing *)Status::getStanding(Globals::status);
      iVar13 = Mission::getClientRace(pMVar10);
      fVar54 = (float)VectorSignedToFloat((int)((fVar54 / 10.0) * 5.0) + 3,
                                          (byte)(in_fpscr >> 0x16) & 3);
      iVar13 = Standing::getEnemyRace(pSVar22,iVar13);
      if (iVar13 == 8) {
        iVar13 = 0;
      }
      pAVar14 = operator_new(0xc);
      puVar15 = operator_new__(4);
      *(undefined4 **)(pAVar14 + 4) = puVar15;
      uVar44 = iVar11 + 2;
      *(undefined4 *)(pAVar14 + 8) = 1;
      *puVar15 = 0;
      *(undefined4 *)pAVar14 = 0;
      *(Array **)(this + 0xf8) = pAVar14;
      ArraySetLength<KIPlayer*>((int)(fVar54 + ((float)uVar12 + -0.5) * fVar54) + uVar44,pAVar14);
      if (-2 < iVar11) {
        iVar11 = 0xf;
        if (iVar13 == 1) {
          iVar11 = 0xd;
        }
        iVar18 = 0;
        do {
          pWVar27 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x108),1);
          uVar12 = createShip(this,iVar13,1,iVar11,pWVar27,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar18 * 4) = uVar12;
          KIPlayer::setToSleep(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar18 * 4));
          Player::setAlwaysEnemy
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar18 * 4) + 4),
                     true);
          PlayerFixedObject::setMoving
                    (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar18 * 4),false
                    );
          piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar18 * 4);
          pcVar39 = *(code **)(*piVar49 + 0x48);
          iVar19 = Route::getWaypoint(*(Route **)(this + 0x108),1);
          iVar19 = *(int *)(iVar19 + 0x120);
          iVar20 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
          iVar25 = Route::getWaypoint(*(Route **)(this + 0x108),1);
          iVar25 = *(int *)(iVar25 + 0x124);
          iVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
          uVar56 = VectorSignedToFloat(iVar20 + iVar19 + -10000,(byte)(in_fpscr >> 0x16) & 3);
          iVar19 = Route::getWaypoint(*(Route **)(this + 0x108),1);
          iVar20 = *(int *)(iVar19 + 0x128);
          uVar58 = VectorSignedToFloat(iVar29 + iVar25 + -10000,(byte)(in_fpscr >> 0x16) & 3);
          iVar19 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
          uVar12 = VectorSignedToFloat(iVar19 + iVar20 + -10000,(byte)(in_fpscr >> 0x16) & 3);
          (*pcVar39)(piVar49,uVar56,uVar58,uVar12);
          pPVar45 = *(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar18 * 4) + 4);
          uVar12 = Player::getMaxHitpoints(pPVar45);
          fVar55 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
          uVar51 = in_fpscr & 0xfffffff | (uint)((float)Globals::options._44_4_ < 0.7) << 0x1f |
                   (uint)((float)Globals::options._44_4_ == 0.7) << 0x1e;
          in_fpscr = uVar51 | (uint)NAN((float)Globals::options._44_4_) << 0x1c;
          bVar7 = (byte)(uVar51 >> 0x18);
          fVar54 = 1.0;
          if (!(bool)(bVar7 >> 6 & 1) && bVar7 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
            fVar54 = 1.4;
          }
          Player::setMaxHitpoints(pPVar45,(int)(fVar55 * 0.7 * fVar54));
          iVar18 = iVar18 + 1;
        } while (iVar18 < (int)uVar44);
      }
      uVar51 = uVar44;
      if (uVar44 < **(uint **)(this + 0xf8)) {
        do {
          iVar11 = Globals::getRandomEnemyFighter(Globals::globals,iVar13);
          pAVar8 = Globals::rnd;
          pRVar21 = *(Route **)(this + 0x108);
          iVar18 = Route::length(pRVar21);
          iVar18 = AbyssEngine::AERandom::nextInt(pAVar8,iVar18);
          pWVar27 = (Waypoint *)Route::getWaypoint(pRVar21,iVar18);
          uVar12 = createShip(this,iVar13,0,iVar11,pWVar27,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar51 * 4) = uVar12;
          KIPlayer::setToSleep(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar51 * 4));
          Player::setAlwaysEnemy
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar51 * 4) + 4),
                     true);
          uVar51 = uVar51 + 1;
        } while (uVar51 < **(uint **)(this + 0xf8));
      }
      pOVar28 = operator_new(0x1c);
      Objective::Objective(pOVar28,7,uVar44,this);
LAB_000c1c1e:
      *(Objective **)(this + 0x28) = pOVar28;
      break;
    case 0xc:
      pLVar23 = (Level *)AbyssEngine::AERandom::nextInt(Globals::rnd,2);
      uVar12 = createRoute(pLVar23,(int)(pLVar23 + 3));
      *(undefined4 *)(this + 0x108) = uVar12;
      uVar12 = Mission::getDifficulty(pMVar10);
      fVar54 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
      iVar11 = (int)((fVar54 / 10.0) * 4.0);
      pAVar14 = operator_new(0xc);
      puVar15 = operator_new__(4);
      *(undefined4 **)(pAVar14 + 4) = puVar15;
      *(undefined4 *)(pAVar14 + 8) = 1;
      *puVar15 = 0;
      *(undefined4 *)pAVar14 = 0;
      *(Array **)(this + 0xf8) = pAVar14;
      uVar44 = iVar11 + 3;
      if ((uVar44 & 1) == 0) {
        uVar44 = iVar11 + 4;
      }
      uVar44 = uVar44 + 1;
      ArraySetLength<KIPlayer*>(uVar44,pAVar14);
      pAVar37 = (Agent *)Mission::getAgent(pMVar10);
      iVar11 = Agent::getRace(pAVar37);
      this_01 = Globals::globals;
      pAVar37 = (Agent *)Mission::getAgent(pMVar10);
      iVar13 = Agent::getRace(pAVar37);
      iVar13 = Globals::getRandomEnemyFighter(this_01,iVar13);
      uVar12 = createShip(this,iVar11,0,iVar13,(Waypoint *)0x0,true,false);
      **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar12;
      piVar49 = (int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4);
      pcVar39 = *(code **)(*piVar49 + 0x48);
      iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x578);
      fVar55 = (float)VectorSignedToFloat(iVar11 + -700,(byte)(in_fpscr >> 0x16) & 3);
      iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x578);
      fVar54 = (float)VectorSignedToFloat(iVar11 + -700,(byte)(in_fpscr >> 0x16) & 3);
      (*pcVar39)(piVar49,local_ec + fVar55,local_e8 + fVar54,local_e4 + 1000.0);
      (**(code **)(*(int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4) + 0x1c))
                ((int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),0x40400000);
      PlayerFighter::setRotate((PlayerFighter *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),3);
      Player::setHitpoints(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),9999999);
      pKVar46 = (KIPlayer *)**(undefined4 **)(*(int *)(this + 0xf8) + 4);
      pRVar21 = (Route *)Route::clone(*(Route **)(this + 0x108));
      KIPlayer::setRoute(pKVar46,pRVar21);
      Player::setAlwaysFriend(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),true);
      iVar11 = **(int **)(*(int *)(this + 0xf8) + 4);
      Mission::getAgent(pMVar10);
      Agent::getName();
      AbyssEngine::String::operator=((String *)(iVar11 + 0x18),(String *)&local_b8);
      AbyssEngine::String::~String((String *)&local_b8);
      puVar40 = *(uint **)(this + 0xf8);
      *(undefined4 *)(*(int *)puVar40[1] + 0x4c) = 0;
      if (1 < *puVar40) {
        uVar51 = 1;
        do {
          iVar11 = Globals::getRandomEnemyFighter(Globals::globals,8);
          pAVar8 = Globals::rnd;
          pRVar21 = *(Route **)(this + 0x108);
          iVar13 = Route::length(pRVar21);
          iVar13 = AbyssEngine::AERandom::nextInt(pAVar8,iVar13);
          pWVar27 = (Waypoint *)Route::getWaypoint(pRVar21,iVar13);
          uVar12 = createShip(this,8,0,iVar11,pWVar27,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar51 * 4) = uVar12;
          KIPlayer::setToSleep(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar51 * 4));
          uVar51 = uVar51 + 1;
        } while (uVar51 < **(uint **)(this + 0xf8));
      }
      pOVar28 = operator_new(0x1c);
      Objective::Objective(pOVar28,0x14,1,uVar44,this);
      *(Objective **)(this + 0x28) = pOVar28;
      pOVar28 = operator_new(0x1c);
      Objective::Objective(pOVar28,0x15,1,uVar44,this);
      *(Objective **)(this + 0x2c) = pOVar28;
      break;
    case 0xf:
      iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,140000);
      local_b8 = (float)(iVar11 + -70000);
      local_b4 = 0x1117000000000;
      local_ac = AbyssEngine::AERandom::nextInt(Globals::rnd,140000);
      local_ac = local_ac + -70000;
      local_a8 = 0;
      iStack_a4 = 100000;
      iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,140000);
      local_a0 = (ulonglong)(iVar11 - 70000);
      local_98 = "t";
      pRVar21 = operator_new(0x18);
      Route::Route(pRVar21,(int *)&local_b8,3);
      *(Route **)(this + 0x110) = pRVar21;
      pMVar38 = (Mission *)Status::getMission(Globals::status);
      uVar12 = Mission::getDifficulty(pMVar38);
      fVar54 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
      fVar55 = (float)Globals::options._44_4_ + -0.5;
      fVar54 = (float)VectorSignedToFloat((int)(fVar54 / 10.0 + fVar54 / 10.0) + 1,
                                          (byte)(in_fpscr >> 0x16) & 3);
      pSVar22 = (Standing *)Status::getStanding(Globals::status);
      iVar11 = Mission::getClientRace(pMVar10);
      iVar11 = Standing::getEnemyRace(pSVar22,iVar11);
      iVar18 = (int)(fVar54 + fVar55 * fVar54);
      iVar13 = Mission::getClientRace(pMVar10);
      *(undefined4 *)(this + 0x28c) = 1;
      pAVar14 = operator_new(0xc);
      puVar15 = operator_new__(4);
      *(undefined4 **)(pAVar14 + 4) = puVar15;
      *(undefined4 *)(pAVar14 + 8) = 1;
      *puVar15 = 0;
      *(undefined4 *)pAVar14 = 0;
      *(Array **)(this + 0xf8) = pAVar14;
      ArraySetLength<KIPlayer*>(iVar18 + 3,pAVar14);
      if (0 < iVar18) {
        iVar19 = 0;
        do {
          iVar20 = Globals::getRandomEnemyFighter(Globals::globals,iVar11);
          pAVar8 = Globals::rnd;
          pRVar21 = *(Route **)(this + 0x110);
          iVar25 = Route::length(pRVar21);
          iVar25 = AbyssEngine::AERandom::nextInt(pAVar8,iVar25);
          pWVar27 = (Waypoint *)Route::getWaypoint(pRVar21,iVar25);
          uVar12 = createShip(this,iVar11,0,iVar20,pWVar27,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar19 * 4) = uVar12;
          Player::setAlwaysEnemy
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar19 * 4) + 4),
                     true);
          iVar19 = iVar19 + 1;
        } while (iVar18 != iVar19);
      }
      *(int *)(this + 0xac) = iVar18;
      uVar12 = createStaticObject(this,*(Waypoint **)(this + 0xd8),0x4a88,true);
      iVar11 = *(int *)(this + 0xac);
      *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar11 * 4) = uVar12;
      PlayerFixedObject::setDockingType
                (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar11 * 4),1);
      PlayerFixedObject::setMoving
                (*(PlayerFixedObject **)
                  (*(int *)(*(int *)(this + 0xf8) + 4) + *(int *)(this + 0xac) * 4),false);
      piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + *(int *)(this + 0xac) * 4);
      (**(code **)(*piVar49 + 0x44))(piVar49,this + 200);
      uStack_d4 = 0xffffffff;
      local_d0 = 0xffffffffffffffff;
      local_e0 = (int)(*(float *)(this + 200) + 0.0);
      fStack_dc = (float)(int)(*(float *)(this + 0xcc) + 0.0);
      local_d8 = (int)(*(float *)(this + 0xd0) + -30000.0);
      local_70[0] = 0;
      local_70[1] = 6000;
      pAVar14 = operator_new(0xc);
      puVar15 = operator_new__(4);
      *(undefined4 **)(pAVar14 + 4) = puVar15;
      *(undefined4 *)(pAVar14 + 8) = 1;
      *puVar15 = 0;
      *(undefined4 *)pAVar14 = 0;
      ArraySetLength<KIPlayer*>(2,pAVar14);
      *(undefined4 *)(*(int *)(pAVar14 + 4) + 4) =
           *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + *(int *)(this + 0xac) * 4);
      pRVar21 = operator_new(0x18);
      Route::Route(pRVar21,&local_e0,pAVar14,local_70,6);
      Route::setLoop(pRVar21,true);
      pRVar26 = (Route *)Route::clone(pRVar21);
      iVar19 = *(int *)(this + 0x28c) + iVar18;
      iVar11 = iVar19;
      do {
        iVar20 = Globals::getRandomEnemyFighter(Globals::globals,iVar13);
        if (iVar11 == iVar19) {
          pWVar27 = (Waypoint *)Route::getWaypoint(pRVar21,0);
          uVar12 = createShip(this,iVar13,0,iVar20,pWVar27,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar19 * 4) = uVar12;
          pKVar46 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar19 * 4);
          pRVar43 = pRVar21;
        }
        else {
          pWVar27 = (Waypoint *)Route::getWaypoint(pRVar26,0);
          uVar12 = createShip(this,iVar13,0,iVar20,pWVar27,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar11 * 4) = uVar12;
          pKVar46 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar11 * 4);
          pRVar43 = pRVar26;
        }
        KIPlayer::setRoute(pKVar46,pRVar43);
        Player::setAlwaysFriend
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar11 * 4) + 4),true
                  );
        Player::setNeverAttack
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar11 * 4) + 4),true
                  );
        iVar19 = *(int *)(this + 0x28c) + iVar18;
        bVar6 = iVar11 <= iVar19;
        iVar11 = iVar11 + 1;
      } while (bVar6);
      pOVar28 = operator_new(0x1c);
      iVar11 = Mission::getProductionGoodAmount(pMVar10);
      iVar13 = Mission::getProductionGoodIndex(pMVar10);
      Objective::Objective(pOVar28,0x1c,iVar11,iVar13,this);
      *(Objective **)(this + 0x28) = pOVar28;
      break;
    default:
      if (iVar18 == 0xb8) {
        iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,140000);
        local_b8 = (float)(iVar11 + -70000);
        local_b4 = 0x1117000000000;
        local_ac = AbyssEngine::AERandom::nextInt(Globals::rnd,140000);
        local_ac = local_ac + -70000;
        local_a8 = 0;
        iStack_a4 = 100000;
        iVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,140000);
        local_a0 = (ulonglong)(iVar11 - 70000);
        local_98 = "t";
        pRVar21 = operator_new(0x18);
        Route::Route(pRVar21,(int *)&local_b8,3);
        *(Route **)(this + 0x110) = pRVar21;
        pMVar38 = (Mission *)Status::getMission(Globals::status);
        Mission::getDifficulty(pMVar38);
        pSVar22 = (Standing *)Status::getStanding(Globals::status);
        iVar11 = Mission::getClientRace(pMVar10);
        Standing::getEnemyRace(pSVar22,iVar11);
        iVar11 = Mission::getClientRace(pMVar10);
        pAVar14 = operator_new(0xc);
        puVar15 = operator_new__(4);
        *(undefined4 **)(pAVar14 + 4) = puVar15;
        *(undefined4 *)(pAVar14 + 8) = 1;
        *puVar15 = 0;
        *(undefined4 *)pAVar14 = 0;
        *(Array **)(this + 0xf8) = pAVar14;
        ArraySetLength<KIPlayer*>(4,pAVar14);
        pWVar27 = operator_new(0x134);
        Waypoint::Waypoint(pWVar27,-30000,0,40000,(Route *)0x0);
        uVar12 = createStaticObject(this,pWVar27,0x4a88,true);
        **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar12;
        PlayerFixedObject::setMoving
                  ((PlayerFixedObject *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),false);
        PlayerFixedObject::setDockingType
                  ((PlayerFixedObject *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),2);
        pPVar50 = (PlayerFixedObject *)**(undefined4 **)(*(int *)(this + 0xf8) + 4);
        pSVar36 = (String *)GameText::getText(Globals::gameText,0xc88);
        AbyssEngine::String::String(aSStack_150,pSVar36,false);
        PlayerFixedObject::setName(pPVar50,aSStack_150);
        AbyssEngine::String::~String(aSStack_150);
        pWVar27 = operator_new(0x134);
        Waypoint::Waypoint(pWVar27,30000,0,40000,(Route *)0x0);
        uVar12 = createStaticObject(this,pWVar27,0x498e,true);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 4) = uVar12;
        PlayerFixedObject::setMoving
                  (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 4),false);
        PlayerFixedObject::setDockingType
                  (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 4),1);
        pPVar50 = *(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 4);
        pSVar36 = (String *)GameText::getText(Globals::gameText,0xc89);
        AbyssEngine::String::String(aSStack_158,pSVar36,false);
        PlayerFixedObject::setName(pPVar50,aSStack_158);
        AbyssEngine::String::~String(aSStack_158);
        local_e0 = -1;
        fStack_dc = -NAN;
        local_d8 = -1;
        uStack_d4 = 0;
        local_d0 = 0x9c4000000000;
        uStack_c8 = 0xffffffff;
        uStack_c4 = 0xffffffff;
        uStack_c0 = 0xffffffff;
        local_70[2] = 10000;
        local_70[0] = 10000;
        local_70[1] = 0;
        pAVar14 = operator_new(0xc);
        puVar15 = operator_new__(4);
        *(undefined4 **)(pAVar14 + 4) = puVar15;
        *(undefined4 *)(pAVar14 + 8) = 1;
        *puVar15 = 0;
        *(undefined4 *)pAVar14 = 0;
        ArraySetLength<KIPlayer*>(3,pAVar14);
        **(undefined4 **)(pAVar14 + 4) = **(undefined4 **)(*(int *)(this + 0xf8) + 4);
        *(undefined4 *)(*(int *)(pAVar14 + 4) + 8) =
             *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 4);
        pRVar21 = operator_new(0x18);
        Route::Route(pRVar21,&local_e0,pAVar14,local_70,9);
        Route::setLoop(pRVar21,true);
        pRVar26 = (Route *)Route::clone(pRVar21);
        iVar13 = 8;
        do {
          iVar18 = Globals::getRandomEnemyFighter(Globals::globals,iVar11);
          if (iVar13 == 8) {
            pWVar27 = (Waypoint *)Route::getWaypoint(pRVar21,0);
            uVar12 = createShip(this,iVar11,0,iVar18,pWVar27,true,false);
            *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 8) = uVar12;
            pKVar46 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + 8);
            pRVar43 = pRVar21;
          }
          else {
            pWVar27 = (Waypoint *)Route::getWaypoint(pRVar26,0);
            uVar12 = createShip(this,iVar11,0,iVar18,pWVar27,true,false);
            *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar13) = uVar12;
            pKVar46 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar13);
            pRVar43 = pRVar26;
          }
          KIPlayer::setRoute(pKVar46,pRVar43);
          Player::setAlwaysFriend
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar13) + 4),true);
          Player::setNeverAttack
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar13) + 4),true);
          iVar13 = iVar13 + 4;
        } while (iVar13 != 0x10);
        pOVar28 = operator_new(0x1c);
        iVar11 = Mission::getProductionGoodAmount(pMVar10);
        iVar13 = Mission::getProductionGoodIndex(pMVar10);
        Objective::Objective(pOVar28,0x1d,iVar11,iVar13,this);
        *(Objective **)(this + 0x28) = pOVar28;
      }
      else if (iVar18 == 0xb7) {
        local_e0 = -55000;
        fStack_dc = 0.0;
        local_d8 = -35000;
        uStack_d4 = 0xffff8ad0;
        local_d0 = 0xffff3cb000000000;
        pRVar21 = operator_new(0x18);
        Route::Route(pRVar21,&local_e0,6);
        *(Route **)(this + 0x110) = pRVar21;
        pAVar14 = operator_new(0xc);
        puVar15 = operator_new__(4);
        *(undefined4 **)(pAVar14 + 4) = puVar15;
        *puVar15 = 0;
        *(undefined4 *)(pAVar14 + 8) = 1;
        *(undefined4 *)pAVar14 = 0;
        *(Array **)(this + 0xf8) = pAVar14;
        ArraySetLength<KIPlayer*>(0xe,pAVar14);
        iVar11 = 0;
        do {
          pWVar27 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110),0);
          uVar12 = createShip(this,10,0,0x2c,pWVar27,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar11 * 4) = uVar12;
          Player::setAlwaysEnemy
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar11 * 4) + 4),
                     true);
          Player::setMaxHitpoints
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar11 * 4) + 4),
                     0xfa);
          iVar11 = iVar11 + 1;
        } while (iVar11 != 8);
        uVar12 = createStaticObject(this,(Waypoint *)0x0,0x495d,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x20) = uVar12;
        PlayerFixedObject::setMoving
                  (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x20),false);
        PlayerFixedObject::setDockingType
                  (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x20),2);
        pPVar50 = *(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x20);
        pSVar36 = (String *)GameText::getText(Globals::gameText,0xc88);
        AbyssEngine::String::String(aSStack_148,pSVar36,false);
        PlayerFixedObject::setName(pPVar50,aSStack_148);
        AbyssEngine::String::~String(aSStack_148);
        Player::setAlwaysFriend
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x20) + 4),true);
        local_b8 = 0.0;
        local_b4 = 0xc016cbe4;
        AEGeometry::rotate(*(Vector **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x20) + 8));
        iVar11 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x20);
        *(undefined1 *)(iVar11 + 0x70) = 1;
        *(undefined4 *)(iVar11 + 0x24) = 10;
        pvVar47 = *(void **)(iVar11 + 0x4c);
        if (pvVar47 != (void *)0x0) {
          if (*(void **)((int)pvVar47 + 4) != (void *)0x0) {
            operator_delete__(*(void **)((int)pvVar47 + 4));
          }
          operator_delete(pvVar47);
          iVar11 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x20);
        }
        *(undefined4 *)(iVar11 + 0x4c) = 0;
        pWVar27 = operator_new(0x134);
        Waypoint::Waypoint(pWVar27,-70000,-5000,-35000,(Route *)0x0);
        uVar12 = createStaticObject(this,pWVar27,0x4974,true);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x24) = uVar12;
        piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x24);
        pcVar39 = *(code **)(*piVar49 + 0x44);
        (**(code **)(*(int *)pWVar27 + 0x28))(&local_b8,pWVar27);
        (*pcVar39)(piVar49,&local_b8);
        PlayerFixedObject::setMoving
                  (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x24),false);
        pPVar50 = *(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x24);
        pPVar50[0x6c] = (PlayerFixedObject)0x0;
        PlayerFixedObject::setDockingType(pPVar50,1);
        Player::setAlwaysFriend
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x24) + 4),true);
        Player::setHitpoints
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x24) + 4),9999999);
        iVar11 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x24);
        *(undefined1 *)(iVar11 + 0x70) = 1;
        *(undefined4 *)(iVar11 + 0x24) = 10;
        pvVar47 = *(void **)(iVar11 + 0x4c);
        if (pvVar47 != (void *)0x0) {
          if (*(void **)((int)pvVar47 + 4) != (void *)0x0) {
            operator_delete__(*(void **)((int)pvVar47 + 4));
          }
          operator_delete(pvVar47);
          iVar11 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x24);
        }
        *(undefined4 *)(iVar11 + 0x4c) = 0;
        local_b8 = -NAN;
        local_b4 = 0xffffffffffffffff;
        local_ac = 30000;
        local_a8 = 1000;
        iStack_a4 = 40000;
        local_a0 = 0xffffffffffffffff;
        local_98 = (char *)0xffffffff;
        local_70[2] = 20000;
        local_70[0] = 20000;
        local_70[1] = 0;
        pAVar14 = operator_new(0xc);
        puVar15 = operator_new__(4);
        *(undefined4 **)(pAVar14 + 4) = puVar15;
        *(undefined4 *)(pAVar14 + 8) = 1;
        *puVar15 = 0;
        *(undefined4 *)pAVar14 = 0;
        ArraySetLength<KIPlayer*>(3,pAVar14);
        **(undefined4 **)(pAVar14 + 4) = *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x24)
        ;
        *(undefined4 *)(*(int *)(pAVar14 + 4) + 8) =
             *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x20);
        pRVar21 = operator_new(0x18);
        Route::Route(pRVar21,(int *)&local_b8,pAVar14,local_70,9);
        Route::setLoop(pRVar21,true);
        iVar11 = 0x28;
        iVar13 = 0;
        do {
          pWVar27 = (Waypoint *)Route::getWaypoint(pRVar21,0);
          uVar12 = createShip(this,0,0,0x33,pWVar27,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar11) = uVar12;
          pKVar46 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar11);
          pRVar26 = (Route *)Route::clone(pRVar21);
          KIPlayer::setRoute(pKVar46,pRVar26);
          Player::setAlwaysFriend
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar11) + 4),true);
          piVar49 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar11);
          *(undefined2 *)((int)piVar49 + 0x139) = 0;
          if (iVar13 == 2) {
            pcVar39 = *(code **)(*piVar49 + 0x44);
            local_7c = 25000.0;
            local_78 = 0.0;
            local_74 = -36000.0;
LAB_000bf0c4:
            (*pcVar39)(piVar49,&local_7c);
          }
          else {
            if (iVar13 == 1) {
              pcVar39 = *(code **)(*piVar49 + 0x44);
              local_7c = 10000.0;
              local_78 = -7000.0;
              local_74 = -30000.0;
              goto LAB_000bf0c4;
            }
            if (iVar13 == 0) {
              pcVar39 = *(code **)(*piVar49 + 0x44);
              local_7c = 20000.0;
              local_78 = -3000.0;
              local_74 = -50000.0;
              goto LAB_000bf0c4;
            }
            local_7c = 12000.0;
            local_78 = 6000.0;
            local_74 = -45000.0;
            (**(code **)(*piVar49 + 0x44))(piVar49,&local_7c);
            if (iVar13 == 3) goto code_r0x000bf102;
          }
          iVar13 = iVar13 + 1;
          iVar11 = iVar11 + 4;
        } while( true );
      }
    }
  }
switchD_000bddd6_caseD_8:
  if (__stack_chk_guard == local_70[3]) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
code_r0x000bf102:
  PlayerEgo::setPosition(extraout_s0,extraout_s1,extraout_s2);
  PlayerEgo::getPosition();
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 200),(Vector *)&local_7c);
  *(char **)(this + 0x130) = "nvas8DrawMeshEPNS_4MeshERNS_6AEMath6MatrixES5_jS5_";
  pOVar28 = operator_new(0x1c);
  Objective::Objective(pOVar28,3,0x2c308,this);
LAB_000c12b6:
  *(Objective **)(this + 0x28) = pOVar28;
  goto switchD_000bddd6_caseD_8;
}

// ===== Level::createScene  @0x000c2910  (2398 bytes)
/* Level::createScene() */

void __thiscall Level::createScene(Level *this)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  Station *pSVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  int *piVar8;
  SolarSystem *pSVar9;
  Array *pAVar10;
  undefined4 *puVar11;
  Ship *pSVar12;
  int iVar13;
  undefined4 uVar14;
  AEGeometry *pAVar15;
  PlayerStatic *pPVar16;
  AEGeometry *this_00;
  uint *puVar17;
  KIPlayer *this_01;
  void *pvVar18;
  uint uVar19;
  undefined *puVar20;
  undefined1 *puVar21;
  undefined *puVar22;
  undefined *puVar23;
  void *pvVar24;
  int *piVar25;
  int iVar26;
  uint uVar27;
  int iVar28;
  uint in_fpscr;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s0_02;
  float extraout_s0_03;
  float extraout_s0_04;
  undefined4 uVar29;
  float extraout_s0_05;
  float fVar30;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float extraout_s1_03;
  float extraout_s1_04;
  float extraout_s1_05;
  float extraout_s1_06;
  float extraout_s2;
  float extraout_s2_00;
  float extraout_s2_01;
  float extraout_s2_02;
  float extraout_s2_03;
  float extraout_s2_04;
  float extraout_s2_05;
  float extraout_s2_06;
  undefined4 uVar31;
  undefined4 uVar32;
  uint local_68;
  uint local_64;
  
  iVar2 = __stack_chk_guard;
  if (*(Array **)(this + 0xf8) != (Array *)0x0) {
    ArrayReleaseClasses<KIPlayer*>(*(Array **)(this + 0xf8));
    pvVar24 = *(void **)(this + 0xf8);
    if (pvVar24 != (void *)0x0) {
      if (*(void **)((int)pvVar24 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar24 + 4));
      }
      operator_delete(pvVar24);
    }
  }
  *(undefined4 *)(this + 0xf8) = 0;
  iVar3 = *(int *)(this + 0xc0);
  if (iVar3 == 2) {
    createPlayer(this);
    Status::setMission(Globals::status,Mission::empty);
    createMission(this);
    iVar3 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar3 == 0x2b) {
      pAVar15 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar15,0x37d0,Globals::Canvas,false);
      pPVar16 = operator_new(300);
      PlayerStatic::PlayerStatic(pPVar16,-1,pAVar15,extraout_s0,extraout_s1,extraout_s2);
      piVar25 = *(int **)(this + 0xf8);
      piVar25[2] = *piVar25 + 1;
      pvVar24 = realloc((void *)piVar25[1],(*piVar25 + 1) * 4);
      piVar25[1] = (int)pvVar24;
      *(PlayerStatic **)((int)pvVar24 + *piVar25 * 4) = pPVar16;
      *piVar25 = piVar25[2];
      pAVar15 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar15,0x37d1,Globals::Canvas,false);
      pPVar16 = operator_new(300);
      PlayerStatic::PlayerStatic(pPVar16,-1,pAVar15,extraout_s0_00,extraout_s1_00,extraout_s2_00);
      piVar25 = *(int **)(this + 0xf8);
      piVar25[2] = *piVar25 + 1;
      pvVar24 = realloc((void *)piVar25[1],(*piVar25 + 1) * 4);
      piVar25[1] = (int)pvVar24;
      *(PlayerStatic **)((int)pvVar24 + *piVar25 * 4) = pPVar16;
      *piVar25 = piVar25[2];
    }
  }
  else {
    if (iVar3 == 4) {
      pSVar9 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar3 = SolarSystem::getRace(pSVar9);
      iVar13 = 3;
      if (iVar3 == 1) {
        iVar13 = 2;
      }
      pSVar4 = (Station *)Status::getStation(Globals::status);
      piVar25 = (int *)Station::getAgents(pSVar4);
      puVar11 = operator_new__(7);
      if (piVar25 == (int *)0x0) {
        pAVar10 = operator_new(0xc);
        puVar6 = operator_new__(4);
        *(undefined4 **)(pAVar10 + 4) = puVar6;
        *(undefined4 *)(pAVar10 + 8) = 1;
        *puVar6 = 0;
        *(undefined4 *)pAVar10 = 0;
        *(Array **)(this + 0xf8) = pAVar10;
        ArraySetLength<KIPlayer*>(3,pAVar10);
      }
      else {
        iVar26 = *piVar25;
        pAVar10 = operator_new(0xc);
        puVar6 = operator_new__(4);
        *(undefined4 **)(pAVar10 + 4) = puVar6;
        *(undefined4 *)(pAVar10 + 8) = 1;
        *puVar6 = 0;
        *(undefined4 *)pAVar10 = 0;
        *(Array **)(this + 0xf8) = pAVar10;
        ArraySetLength<KIPlayer*>(iVar26 * 3 + iVar13,pAVar10);
        *(undefined1 *)((int)puVar11 + 6) = 0;
        *(undefined2 *)(puVar11 + 1) = 0;
        *puVar11 = 0;
        if (0 < iVar26) {
          iVar28 = 0;
          do {
            iVar7 = Agent::getRace(*(Agent **)(piVar25[1] + iVar28 * 4));
            if (iVar7 == 3) {
              iVar7 = Agent::getImageParts(*(Agent **)(piVar25[1] + iVar28 * 4));
              if (iVar7 == 0) {
                iVar7 = 3;
              }
              else {
                piVar8 = (int *)Agent::getImageParts(*(Agent **)(piVar25[1] + iVar28 * 4));
                iVar7 = *piVar8;
                if (iVar7 != 2) {
                  iVar7 = 3;
                }
              }
            }
            uVar14 = *(undefined4 *)(&DAT_00254380 + iVar7 * 4);
            iVar7 = Agent::getRace(*(Agent **)(piVar25[1] + iVar28 * 4));
            if ((iVar7 == 0) &&
               (iVar7 = Agent::isMale(*(Agent **)(piVar25[1] + iVar28 * 4)), iVar7 == 0)) {
              uVar14 = 0x3984;
            }
            do {
              iVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,7);
            } while (*(char *)((int)puVar11 + iVar7) != '\0');
            puVar6 = (undefined4 *)(&UNK_00254000 + iVar7 * 0xc + iVar3 * 0x54);
            uVar29 = *puVar6;
            uVar32 = puVar6[1];
            uVar31 = puVar6[2];
            *(undefined1 *)((int)puVar11 + iVar7) = 1;
            VectorSignedToFloat(uVar31,(byte)(in_fpscr >> 0x16) & 3);
            VectorSignedToFloat(uVar32,(byte)(in_fpscr >> 0x16) & 3);
            VectorSignedToFloat(uVar29,(byte)(in_fpscr >> 0x16) & 3);
            pAVar15 = operator_new(0xc0);
            AEGeometry::AEGeometry(pAVar15,(ushort)uVar14,Globals::Canvas,false);
            pPVar16 = operator_new(300);
            PlayerStatic::PlayerStatic
                      (pPVar16,-1,pAVar15,extraout_s0_01,extraout_s1_01,extraout_s2_01);
            *(PlayerStatic **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar28 * 4) = pPVar16;
            pAVar15 = operator_new(0xc0);
            AEGeometry::AEGeometry(pAVar15,*(ushort *)(&DAT_00251fe0 + iVar3),Globals::Canvas,false)
            ;
            pPVar16 = operator_new(300);
            PlayerStatic::PlayerStatic
                      (pPVar16,-1,pAVar15,extraout_s0_02,extraout_s1_02,extraout_s2_02);
            *(PlayerStatic **)(*(int *)(*(int *)(this + 0xf8) + 4) + (iVar28 + iVar26) * 4) =
                 pPVar16;
            pAVar15 = operator_new(0xc0);
            AEGeometry::AEGeometry(pAVar15,0x380c,Globals::Canvas,false);
            pPVar16 = operator_new(300);
            PlayerStatic::PlayerStatic
                      (pPVar16,-1,pAVar15,extraout_s0_03,extraout_s1_03,extraout_s2_03);
            iVar7 = iVar26 * 2 + iVar28;
            iVar28 = iVar28 + 1;
            *(PlayerStatic **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar7 * 4) = pPVar16;
          } while (iVar28 < iVar26);
        }
      }
      iVar26 = 0;
      do {
        pAVar15 = operator_new(0xc0);
        AEGeometry::AEGeometry
                  (pAVar15,*(ushort *)(&DAT_00254150 + iVar26 * 4 + iVar3 * 0xc),Globals::Canvas,
                   false);
        pPVar16 = operator_new(300);
        PlayerStatic::PlayerStatic(pPVar16,-1,pAVar15,extraout_s0_04,extraout_s1_04,extraout_s2_04);
        iVar28 = iVar26 - iVar13;
        iVar26 = iVar26 + 1;
        *(PlayerStatic **)((*(int **)(this + 0xf8))[1] + (**(int **)(this + 0xf8) + iVar28) * 4) =
             pPVar16;
      } while (iVar26 < iVar13);
      if (__stack_chk_guard == iVar2) {
        operator_delete__(puVar11);
        return;
      }
      goto LAB_000c326a;
    }
    if (iVar3 == 0x17) {
      pSVar4 = (Station *)Status::getStation(Globals::status);
      iVar3 = Station::getIndex(pSVar4);
      if (iVar3 == 0x65) {
        uVar5 = 8;
      }
      else {
        pSVar4 = (Station *)Status::getStation(Globals::status);
        iVar3 = Station::getIndex(pSVar4);
        if (iVar3 == 100) {
          uVar5 = 7;
        }
        else {
          pSVar9 = (SolarSystem *)Status::getSystem(Globals::status);
          uVar5 = SolarSystem::getRace(pSVar9);
        }
      }
      pAVar10 = operator_new(0xc);
      puVar11 = operator_new__(4);
      *(undefined4 **)(pAVar10 + 4) = puVar11;
      *(undefined4 *)(pAVar10 + 8) = 1;
      *puVar11 = 0;
      *(undefined4 *)pAVar10 = 0;
      *(Array **)(this + 0xf8) = pAVar10;
      ArraySetLength<KIPlayer*>(1,pAVar10);
      pSVar12 = (Ship *)Status::getShip(Globals::status);
      iVar3 = Ship::getIndex(pSVar12);
      pSVar12 = (Ship *)Status::getShip(Globals::status);
      iVar13 = Ship::getRace(pSVar12);
      uVar14 = createShip(this,iVar13,0,iVar3,(Waypoint *)0x0,*(int *)(this + 0xc0) != 0x17,false);
      uVar29 = VectorSignedToFloat(*(undefined4 *)(&DAT_00253d48 + iVar3 * 4),
                                   (byte)(in_fpscr >> 0x16) & 3);
      **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar14;
      (**(code **)(*(int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4) + 0x48))
                ((int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),0,uVar29,0);
      PlayerFighter::removeTrail((PlayerFighter *)**(undefined4 **)(*(int *)(this + 0xf8) + 4));
      PlayerFighter::setExhaustVisible
                ((PlayerFighter *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),false);
      KIPlayer::setToSleep((KIPlayer *)**(undefined4 **)(*(int *)(this + 0xf8) + 4));
      Player::setAlwaysFriend(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),true);
      iVar3 = 0;
      do {
        iVar13 = *(int *)(&UNK_00253e48 + iVar3 * 4 + uVar5 * 0x10);
        if (-1 < iVar13) {
          pAVar15 = operator_new(0xc0);
          AEGeometry::AEGeometry(pAVar15,(ushort)iVar13,Globals::Canvas,false);
          AEGeometry::setRotation((Vector *)pAVar15);
          pPVar16 = operator_new(300);
          PlayerStatic::PlayerStatic
                    (pPVar16,-1,pAVar15,extraout_s0_05,extraout_s1_05,extraout_s2_05);
          if ((int)uVar5 < 4 && uVar5 != 1) {
            iVar13 = 0;
            uVar14 = *(undefined4 *)(&DAT_00251fd0 + uVar5 * 4);
            do {
              this_00 = operator_new(0xc0);
              AEGeometry::AEGeometry(this_00,(short)uVar14 + (short)iVar13,Globals::Canvas,false);
              AEGeometry::addChild(pAVar15,*(uint *)(this_00 + 0xc));
              pvVar24 = (void *)AEGeometry::~AEGeometry(this_00);
              operator_delete(pvVar24);
              iVar13 = iVar13 + 1;
            } while (iVar13 < *(int *)(&UNK_00251fc0 + uVar5 * 4));
          }
          piVar25 = *(int **)(this + 0xf8);
          piVar25[2] = *piVar25 + 1;
          pvVar24 = realloc((void *)piVar25[1],(*piVar25 + 1) * 4);
          piVar25[1] = (int)pvVar24;
          *(PlayerStatic **)((int)pvVar24 + *piVar25 * 4) = pPVar16;
          *piVar25 = piVar25[2];
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 4);
      pSVar4 = (Station *)Status::getStation(Globals::status);
      iVar3 = Station::getIndex(pSVar4);
      bVar1 = false;
      if ((iVar3 == 0x6c) && (*(int *)(Globals::status + 0x114) == 3)) {
        bVar1 = true;
      }
      uVar27 = *(uint *)(&UNK_00253ee8 + uVar5 * 4);
      local_68 = AbyssEngine::AERandom::nextInt(Globals::rnd,uVar27 + 1);
      if (bVar1) {
        puVar17 = (uint *)Station::getShips(*(Station **)(Globals::status + 0x14c));
        if (puVar17 == (uint *)0x0) {
          local_68 = 0;
        }
        else {
          local_68 = *puVar17;
          if (uVar27 <= *puVar17) {
            local_68 = uVar27;
          }
        }
      }
      pvVar24 = operator_new__(uVar27);
      if ((0x8fU >> (uVar5 & 0xff) & 1) != 0) {
        uVar19 = uVar27;
        if ((int)uVar27 < 2) {
          uVar19 = 1;
        }
        __aeabi_memclr(pvVar24,uVar19);
      }
      if (0 < (int)local_68) {
        puVar23 = &UNK_00253fc4;
        if (uVar5 != 7) {
          puVar23 = &DAT_00253fe8;
        }
        if (uVar5 == 8) {
          puVar23 = &DAT_00253fb8;
        }
        puVar20 = &UNK_00253f10;
        if (uVar5 != 0) {
          puVar20 = &DAT_00253f28;
        }
        if ((uVar5 | 1) != 1) {
          puVar20 = &DAT_00253f94;
        }
        local_64 = 0;
        do {
          iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
          uVar19 = uVar5;
          if (iVar3 < 0x1e) {
            uVar19 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
            iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
            if (iVar3 < 0x1e) {
              uVar19 = 8;
            }
          }
          iVar3 = Globals::getRandomEnemyFighter(Globals::globals,uVar19);
          pSVar4 = (Station *)Status::getStation(Globals::status);
          iVar13 = Station::getIndex(pSVar4);
          if (iVar13 == 100) {
            iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
            iVar3 = 0x28;
            if (iVar13 == 1) {
              iVar3 = 0x26;
            }
            if (iVar13 == 0) {
              iVar3 = 0x25;
            }
          }
          if (bVar1) {
            iVar3 = Station::getShips(*(Station **)(Globals::status + 0x14c));
            iVar3 = Ship::getIndex(*(Ship **)(*(int *)(iVar3 + 4) + local_64 * 4));
          }
          this_01 = (KIPlayer *)createShip(this,0,0,iVar3,(Waypoint *)0x0,false,false);
          iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,uVar27);
          if (*(char *)((int)pvVar24 + iVar13) == '\0') {
            puVar21 = (undefined1 *)((int)pvVar24 + iVar13);
          }
          else {
            iVar26 = 100;
            do {
              iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,uVar27);
              puVar21 = (undefined1 *)((int)pvVar24 + iVar13);
              if (iVar26 < 2) break;
              iVar26 = iVar26 + -1;
            } while (*(char *)((int)pvVar24 + iVar13) != '\0');
          }
          *puVar21 = 1;
          puVar22 = puVar23;
          if ((uVar5 < 4) && (puVar22 = puVar20, uVar5 == 2)) {
            puVar22 = puVar23;
          }
          puVar11 = (undefined4 *)(puVar22 + iVar13 * 0xc);
          uVar14 = VectorSignedToFloat(*puVar11,(byte)(in_fpscr >> 0x16) & 3);
          uVar29 = VectorSignedToFloat(puVar11[2],(byte)(in_fpscr >> 0x16) & 3);
          uVar32 = VectorSignedToFloat(puVar11[1] + *(int *)(&DAT_00253d48 + iVar3 * 4),
                                       (byte)(in_fpscr >> 0x16) & 3);
          (**(code **)(*(int *)this_01 + 0x48))(this_01,uVar14,uVar32,uVar29);
          Player::setAlwaysFriend(*(Player **)(this_01 + 4),true);
          KIPlayer::setToSleep(this_01);
          pAVar15 = *(AEGeometry **)(this_01 + 8);
          uVar14 = AbyssEngine::AERandom::nextInt(Globals::rnd,300);
          fVar30 = (float)VectorSignedToFloat(uVar14,(byte)(in_fpscr >> 0x16) & 3);
          AEGeometry::setRotation(pAVar15,fVar30 / 100.0,extraout_s1_06,extraout_s2_06);
          PlayerFighter::setExhaustVisible((PlayerFighter *)this_01,false);
          piVar25 = *(int **)(this + 0xf8);
          piVar25[2] = *piVar25 + 1;
          pvVar18 = realloc((void *)piVar25[1],(*piVar25 + 1) * 4);
          piVar25[1] = (int)pvVar18;
          *(KIPlayer **)((int)pvVar18 + *piVar25 * 4) = this_01;
          *piVar25 = piVar25[2];
          local_64 = local_64 + 1;
        } while (local_64 != local_68);
      }
      operator_delete__(pvVar24);
    }
  }
  if (__stack_chk_guard == iVar2) {
    return;
  }
LAB_000c326a:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== Level::createCampaignMission  @0x000c3370  (29754 bytes)
/* Level::createCampaignMission() */

void __thiscall Level::createCampaignMission(Level *this)

{
  ulonglong uVar1;
  AERandom *pAVar2;
  byte bVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  Route *pRVar7;
  Array *pAVar8;
  undefined4 *puVar9;
  Waypoint *pWVar10;
  Waypoint *pWVar11;
  Waypoint *this_00;
  int iVar12;
  Objective *pOVar13;
  ulonglong *puVar14;
  int iVar15;
  Mission *this_01;
  Agent *pAVar16;
  uint *puVar17;
  undefined4 *puVar18;
  Station *pSVar19;
  PlayerStation *pPVar20;
  AEGeometry *pAVar21;
  AEGeometry *pAVar22;
  AEGeometry *pAVar23;
  AEGeometry *this_02;
  String *pSVar24;
  uint uVar25;
  Route *pRVar26;
  PlayerFighter *pPVar27;
  Route *pRVar28;
  undefined4 uVar29;
  int iVar30;
  float *pfVar31;
  int iVar32;
  PlayerFixedObject *pPVar33;
  int *piVar34;
  KIPlayer *pKVar35;
  void *pvVar36;
  int *piVar37;
  uint uVar38;
  Player *pPVar39;
  int iVar40;
  int iVar41;
  Vector *pVVar42;
  int iVar43;
  int iVar44;
  code *pcVar45;
  uint uVar46;
  float fVar47;
  uint in_fpscr;
  float fVar48;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s0_02;
  float extraout_s0_03;
  float extraout_s0_04;
  float fVar49;
  float extraout_s0_05;
  float extraout_s0_06;
  float extraout_s0_07;
  float extraout_s0_08;
  float extraout_s0_09;
  float extraout_s0_10;
  float extraout_s0_11;
  float extraout_s0_12;
  float extraout_s0_13;
  float extraout_s0_14;
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
  undefined4 uVar50;
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
  float fVar51;
  float extraout_s2_12;
  float extraout_s2_13;
  float extraout_s2_14;
  undefined4 uVar52;
  float fVar53;
  float fVar54;
  undefined1 auVar55 [16];
  int local_210;
  int local_20c;
  String aSStack_204 [8];
  undefined1 auStack_1fc [8];
  float local_1f4;
  undefined1 auStack_1f0 [4];
  float local_1ec;
  float local_1e4 [3];
  undefined1 auStack_1d8 [8];
  float local_1d0;
  undefined1 auStack_1cc [4];
  float local_1c8;
  float local_1c0 [3];
  AbyssEngine aAStack_1b4 [8];
  AbyssEngine aAStack_1ac [8];
  String aSStack_1a4 [8];
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 uStack_194;
  Vector aVStack_190 [12];
  undefined4 local_184;
  undefined4 local_180;
  float local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  String aSStack_16c [8];
  String aSStack_164 [8];
  String aSStack_15c [8];
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 local_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  float local_130;
  float local_12c;
  float local_128;
  String aSStack_124 [8];
  float local_11c;
  float local_118;
  float local_114;
  undefined8 local_110;
  char *local_108;
  undefined4 uStack_104;
  undefined8 local_100;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  char *local_e8;
  float fStack_e4;
  char *local_e0;
  int local_dc;
  undefined8 local_d8;
  int local_d0;
  undefined4 uStack_cc;
  undefined4 local_c8;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  int local_90;
  undefined4 uStack_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  ulonglong local_80;
  ulonglong uStack_78;
  undefined4 local_70;
  undefined8 local_68;
  float local_60;
  int local_5c;
  
  local_5c = __stack_chk_guard;
  AEGeometry::getPosition();
  iVar6 = Status::getCurrentCampaignMission(Globals::status);
  iVar43 = 70000;
  if (iVar6 < 0x78) {
    switch(iVar6) {
    case 0x24:
      this_01 = (Mission *)Status::getMission(Globals::status);
      pAVar16 = operator_new(0x88);
      pSVar24 = (String *)GameText::getText(Globals::gameText,0x644);
      AbyssEngine::String::String(aSStack_124,pSVar24,false);
      Agent::Agent(pAVar16,0xffffffff,aSStack_124,0x1d,5,1,1,0xffffffff,0xffffffff,0xffffffff,
                   0xffffffff);
      Mission::setAgent(this_01,pAVar16);
      AbyssEngine::String::~String(aSStack_124);
      local_a8 = 0xffffd8f00001adb0;
      local_a0 = 0x11170fffec780;
      local_98 = 0xfffe796000000000;
      local_90 = -100000;
      uStack_8c = 10000;
      local_88 = 0xfffec780;
      uStack_84 = 0xfffe0430;
      local_80 = 0xfffdb610ffff3cb0;
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_a8,0xc);
      *(Route **)(this + 0x108) = pRVar7;
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *puVar9 = 0;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(8,pAVar8);
      uVar29 = createShip(this,1,0,9,(Waypoint *)0x0,true,false);
      **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar29;
      piVar37 = (int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4);
      pcVar45 = *(code **)(*piVar37 + 0x48);
      iVar43 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x578);
      fVar51 = (float)VectorSignedToFloat(iVar43 + -700,(byte)(in_fpscr >> 0x16) & 3);
      iVar43 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x578);
      fVar48 = (float)VectorSignedToFloat(iVar43 + -700,(byte)(in_fpscr >> 0x16) & 3);
      (*pcVar45)(piVar37,local_11c + fVar51,local_118 + fVar48,local_114 + 1000.0);
      (**(code **)(*(int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4) + 0x1c))
                ((int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),0x40400000);
      PlayerFighter::setRotate((PlayerFighter *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),3);
      Player::setHitpoints(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),9999999);
      pKVar35 = (KIPlayer *)**(undefined4 **)(*(int *)(this + 0xf8) + 4);
      pRVar7 = (Route *)Route::clone(*(Route **)(this + 0x108));
      KIPlayer::setRoute(pKVar35,pRVar7);
      Player::setAlwaysFriend(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),true);
      iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
      pSVar24 = (String *)GameText::getText(Globals::gameText,0x644);
      AbyssEngine::String::operator=((String *)(iVar43 + 0x18),pSVar24);
      puVar17 = *(uint **)(this + 0xf8);
      *(undefined4 *)(*(int *)puVar17[1] + 0x4c) = 0;
      if (1 < *puVar17) {
        uVar25 = 1;
        do {
          iVar43 = Globals::getRandomEnemyFighter(Globals::globals,8);
          pAVar2 = Globals::rnd;
          pRVar7 = *(Route **)(this + 0x108);
          iVar6 = Route::length(pRVar7);
          iVar6 = AbyssEngine::AERandom::nextInt(pAVar2,iVar6);
          pWVar10 = (Waypoint *)Route::getWaypoint(pRVar7,iVar6);
          uVar29 = createShip(this,8,0,iVar43,pWVar10,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) = uVar29;
          KIPlayer::setToSleep(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4));
          uVar25 = uVar25 + 1;
        } while (uVar25 < **(uint **)(this + 0xf8));
      }
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,0x14,1,8,this);
      *(Objective **)(this + 0x28) = pOVar13;
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,0x15,1,8,this);
      goto LAB_000c8668;
    case 0x25:
    case 0x27:
    case 0x2a:
    case 0x2b:
    case 0x2c:
    case 0x2d:
    case 0x2e:
    case 0x2f:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x39:
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x3e:
    case 0x42:
    case 0x44:
    case 0x47:
    case 0x48:
    case 0x4a:
    case 0x4b:
    case 0x4c:
    case 0x4d:
    case 0x52:
    case 0x53:
    case 0x54:
    case 0x55:
    case 0x56:
    case 0x58:
    case 0x5a:
    case 0x5d:
    case 0x5f:
    case 0x60:
    case 0x62:
    case 99:
    case 0x65:
    case 0x67:
    case 0x68:
    case 0x6b:
    case 0x6c:
    case 0x6d:
    case 0x6e:
    case 0x6f:
    case 0x70:
    case 0x71:
      break;
    case 0x26:
      local_a0 = CONCAT44(local_a0._4_4_,80000);
      local_a8 = 0x271000015f90;
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_a8,3);
      *(Route **)(this + 0x110) = pRVar7;
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *puVar9 = 0;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(7,pAVar8);
      iVar43 = 0;
      do {
        pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110));
        uVar29 = createShip(this,2,1,0xf,pWVar10,true,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
        Player::setAlwaysFriend
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) + 4),true
                  );
        PlayerFixedObject::setMoving
                  (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4),false);
        piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4);
        pcVar45 = *(code **)(*piVar37 + 0x48);
        iVar6 = Route::getWaypoint(*(Route **)(this + 0x110));
        iVar12 = *(int *)(iVar6 + 0x120);
        iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
        iVar40 = Route::getWaypoint(*(Route **)(this + 0x110));
        iVar40 = *(int *)(iVar40 + 0x124);
        iVar30 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
        uVar50 = VectorSignedToFloat(iVar12 + -10000 + iVar6,(byte)(in_fpscr >> 0x16) & 3);
        iVar6 = Route::getWaypoint(*(Route **)(this + 0x110));
        iVar12 = *(int *)(iVar6 + 0x128);
        uVar52 = VectorSignedToFloat(iVar30 + iVar40 + -10000,(byte)(in_fpscr >> 0x16) & 3);
        iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
        uVar29 = VectorSignedToFloat(iVar6 + iVar12 + -10000,(byte)(in_fpscr >> 0x16) & 3);
        (*pcVar45)(piVar37,uVar50,uVar52,uVar29);
        iVar43 = iVar43 + 1;
      } while (iVar43 != 2);
      if (2 < **(uint **)(this + 0xf8)) {
        uVar25 = 2;
        do {
          iVar43 = Globals::getRandomEnemyFighter(Globals::globals,3);
          pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110));
          uVar29 = createShip(this,3,0,iVar43,pWVar10,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) = uVar29;
          Player::setAlwaysEnemy
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) + 4),
                     true);
          uVar25 = uVar25 + 1;
        } while (uVar25 < **(uint **)(this + 0xf8));
      }
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,0x12,2,7,this);
      *(Objective **)(this + 0x28) = pOVar13;
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,7,2,this);
      goto LAB_000c8e78;
    case 0x28:
      local_e0 = "ppEPFvPS0_E";
      local_e8 = (char *)0xffffb1e0;
      fStack_e4 = -NAN;
      local_a8 = 0xfffff448ffffb1e0;
      local_a0 = 0xffffb1e0000088b8;
      local_98 = 0x30d40fffff448;
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_e8,3);
      *(Route **)(this + 0x110) = pRVar7;
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_a8,6);
      *(Route **)(this + 0x10c) = pRVar7;
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *puVar9 = 0;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(0xd,pAVar8);
      uVar29 = createShip(this,0,1,0xd,(Waypoint *)0x0,true,false);
      **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar29;
      Player::setAlwaysFriend(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),true);
      iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
      pSVar24 = (String *)GameText::getText(Globals::gameText,0x644);
      AbyssEngine::String::operator=((String *)(iVar43 + 0x18),pSVar24);
      pPVar39 = *(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4);
      iVar43 = Status::getLevel(Globals::status);
      Player::setMaxHitpoints(pPVar39,iVar43 * 5 + 0x708);
      (**(code **)(*(int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4) + 0x48))
                ((int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),0xcb18967f,0xcb18967f,
                 0xcb18967f);
      KIPlayer::setToSleep((KIPlayer *)**(undefined4 **)(*(int *)(this + 0xf8) + 4));
      KIPlayer::setVisible((KIPlayer *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),false);
      iVar43 = 1;
      do {
        while( true ) {
          iVar6 = Globals::getRandomEnemyFighter(Globals::globals,0);
          uVar29 = createShip(this,0,0,iVar6,(Waypoint *)0x0,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
          pKVar35 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4);
          pRVar7 = (Route *)Route::clone(*(Route **)(this + 0x10c));
          KIPlayer::setRoute(pKVar35,pRVar7);
          Player::setAlwaysFriend
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) + 4),
                     true);
          if (iVar43 != 2) break;
          iVar43 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 8);
          pSVar24 = (String *)GameText::getText(Globals::gameText,0x645);
          AbyssEngine::String::operator=((String *)(iVar43 + 0x18),pSVar24);
          iVar43 = 3;
        }
        iVar43 = iVar43 + 1;
      } while (iVar43 != 5);
      iVar43 = 5;
      do {
        pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110));
        uVar29 = createShip(this,9,0,8,pWVar10,true,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
        Player::setAlwaysEnemy
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) + 4),true
                  );
        iVar43 = iVar43 + 1;
      } while (iVar43 != 9);
      iVar43 = 9;
      do {
        uVar29 = createShip(this,9,0,8,(Waypoint *)0x0,true,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
        piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4);
        local_110 = 0xc8f42400c8f42400;
        local_108 = (char *)0xc8f42400;
        (**(code **)(*piVar37 + 0x44))(piVar37,&local_110);
        Player::setAlwaysEnemy
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) + 4),true
                  );
        KIPlayer::setToSleep(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4));
        iVar43 = iVar43 + 1;
      } while (iVar43 != 0xd);
      piVar37 = *(int **)(*(int *)(*(int *)(this + 0x100) + 4) + 0xc);
      (**(code **)(*piVar37 + 0x48))(piVar37,0xc69c4000,0xc53b8000,0x48435000);
      if (initStreamOutPosition != '\0') {
        PlayerEgo::setPosition(extraout_s0_01,extraout_s1_02,extraout_s2_01);
        AEGeometry::setRotation
                  (*(AEGeometry **)(*(int *)(this + 0xf0) + 8),extraout_s0_02,extraout_s1_03,
                   extraout_s2_02);
      }
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,7,1,this);
      *(Objective **)(this + 0x2c) = pOVar13;
      break;
    case 0x29:
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *puVar9 = 0;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(8,pAVar8);
      uVar29 = createShip(this,1,1,0xd,(Waypoint *)0x0,true,false);
      **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar29;
      Player::setAlwaysFriend(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),true);
      iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
      pSVar24 = (String *)GameText::getText(Globals::gameText,0x644);
      AbyssEngine::String::operator=((String *)(iVar43 + 0x18),pSVar24);
      if (lastMissionFreighterHitpoints < 1) {
        iVar43 = Status::getLevel(Globals::status);
        fVar48 = (float)VectorSignedToFloat(iVar43 * 5 + 0x708,(byte)(in_fpscr >> 0x16) & 3);
        lastMissionFreighterHitpoints = (int)(fVar48 * 0.7);
      }
      Player::setHitpoints
                (*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),
                 lastMissionFreighterHitpoints);
      PlayerFixedObject::setMoving
                ((PlayerFixedObject *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),true);
      (**(code **)(*(int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4) + 0x48))
                ((int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),0,0,0xc8927c00);
      iVar43 = 1;
      do {
        uVar29 = createShip(this,9,0,8,(Waypoint *)0x0,true,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
        Player::setAlwaysEnemy
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) + 4),true
                  );
        iVar43 = iVar43 + 1;
      } while (iVar43 != 8);
      piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + 4);
      (**(code **)(*piVar37 + 0x48))(piVar37,0,0,0xc87de800);
      piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + 8);
      (**(code **)(*piVar37 + 0x48))(piVar37,0xc61c4000,0x461c4000,0xc86a6000);
      piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + 0xc);
      (**(code **)(*piVar37 + 0x48))(piVar37,0x464b2000,0x44fa0000,0xc856d800);
      piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x10);
      (**(code **)(*piVar37 + 0x48))(piVar37,0xc78ca000,0xc57a0000,0xc84d1400);
      piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x14);
      (**(code **)(*piVar37 + 0x48))(piVar37,0x476a6000,0xc71c4000,0xc8398c00);
      piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x18);
      (**(code **)(*piVar37 + 0x48))(piVar37,0xc68ca000,0x46ea6000,0xc81c4000);
      piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x1c);
      (**(code **)(*piVar37 + 0x48))(piVar37,0x4684d000,0x471c4000,0xc808b800);
      PlayerEgo::setPosition(extraout_s0_03,extraout_s1_04,extraout_s2_03);
      AEGeometry::setRotation
                (*(AEGeometry **)(*(int *)(this + 0xf0) + 8),extraout_s0_04,extraout_s1_05,
                 extraout_s2_04);
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,0x19,0,this);
      *(Objective **)(this + 0x28) = pOVar13;
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,7,1,this);
      *(Objective **)(this + 0x2c) = pOVar13;
      break;
    case 0x30:
    case 0x31:
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *puVar9 = 0;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(5,pAVar8);
      if (**(int **)(this + 0xf8) != 0) {
        uVar25 = 0;
        do {
          uVar29 = createShip(this,1,0,9,(Waypoint *)0x0,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) = uVar29;
          Player::setAlwaysEnemy
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) + 4),
                     false);
          Player::setAlwaysFriend
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) + 4),
                     true);
          uVar25 = uVar25 + 1;
        } while (uVar25 < **(uint **)(this + 0xf8));
      }
      break;
    case 0x32:
      piVar37 = *(int **)(*(int *)(*(int *)(this + 0x100) + 4) + 4);
      if (piVar37 == (int *)0x0) {
        local_a8 = 0;
        local_a0 = CONCAT44(local_a0._4_4_,0x471c4000);
      }
      else {
        (**(code **)(*piVar37 + 0x28))(&local_a8);
      }
      AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x18c),(Vector *)&local_a8);
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *puVar9 = 0;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(4,pAVar8);
      if (**(int **)(this + 0xf8) != 0) {
        uVar25 = 0;
        do {
          uVar29 = createShip(this,1,0,9,(Waypoint *)0x0,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) = uVar29;
          Player::setAlwaysEnemy
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) + 4),
                     false);
          Player::setAlwaysFriend
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) + 4),
                     true);
          uVar25 = uVar25 + 1;
        } while (uVar25 < **(uint **)(this + 0xf8));
      }
      break;
    case 0x33:
      pVVar42 = (Vector *)(this + 0x18c);
      piVar37 = *(int **)(*(int *)(*(int *)(this + 0x100) + 4) + 4);
      if (piVar37 == (int *)0x0) {
        local_a8 = 0;
        local_a0 = CONCAT44(local_a0._4_4_,0x471c4000);
      }
      else {
        (**(code **)(*piVar37 + 0x28))(&local_a8);
      }
      AbyssEngine::AEMath::Vector::operator=(pVVar42,(Vector *)&local_a8);
      local_a8 = CONCAT44((int)*(float *)(this + 400),(int)*(float *)(this + 0x18c));
      local_a0 = CONCAT44(local_a0._4_4_,(int)*(float *)(this + 0x194));
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_a8,3);
      *(Route **)(this + 0x110) = pRVar7;
      Route::setLoop(pRVar7,true);
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *puVar9 = 0;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(6,pAVar8);
      uVar29 = createShip(this,1,1,0xd,(Waypoint *)0x0,true,false);
      **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar29;
      Player::setAlwaysEnemy(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),true);
      PlayerEgo::getPosition();
      fVar48 = (float)AbyssEngine::AEMath::operator-
                                ((AEMath *)&local_68,(Vector *)&local_130,pVVar42);
      AbyssEngine::AEMath::operator/((AEMath *)&local_110,(Vector *)&local_68,fVar48);
      AbyssEngine::AEMath::operator+((AEMath *)&local_e8,pVVar42,(Vector *)&local_110);
      AbyssEngine::AEMath::Vector::operator=(pVVar42,(Vector *)&local_e8);
      (**(code **)(*(int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4) + 0x48))
                ((int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),*(undefined4 *)(this + 0x18c),
                 *(undefined4 *)(this + 400),*(undefined4 *)(this + 0x194));
      if (1 < **(uint **)(this + 0xf8)) {
        uVar25 = 1;
        do {
          pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110));
          uVar29 = createShip(this,1,0,9,pWVar10,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) = uVar29;
          Player::setAlwaysEnemy
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) + 4),
                     true);
          pKVar35 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4);
          pRVar7 = (Route *)Route::clone(*(Route **)(this + 0x110));
          KIPlayer::setRoute(pKVar35,pRVar7);
          uVar25 = uVar25 + 1;
        } while (uVar25 < **(uint **)(this + 0xf8));
      }
      break;
    case 0x34:
      pVVar42 = (Vector *)(this + 0x18c);
      piVar37 = *(int **)(*(int *)(*(int *)(this + 0x100) + 4) + 4);
      if (piVar37 == (int *)0x0) {
        local_a8 = 0;
        local_a0 = CONCAT44(local_a0._4_4_,0x471c4000);
      }
      else {
        (**(code **)(*piVar37 + 0x28))(&local_a8);
      }
      AbyssEngine::AEMath::Vector::operator=(pVVar42,(Vector *)&local_a8);
      local_a8 = CONCAT44((int)*(float *)(this + 400),(int)*(float *)(this + 0x18c));
      local_a0 = CONCAT44(local_a0._4_4_,(int)*(float *)(this + 0x194));
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_a8,3);
      *(Route **)(this + 0x110) = pRVar7;
      Route::setLoop(pRVar7,true);
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *puVar9 = 0;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(8,pAVar8);
      uVar29 = createShip(this,1,1,0xd,(Waypoint *)0x0,true,false);
      **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar29;
      Player::setAlwaysEnemy(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),true);
      PlayerEgo::getPosition();
      fVar48 = (float)AbyssEngine::AEMath::operator-
                                ((AEMath *)&local_68,(Vector *)&local_130,pVVar42);
      AbyssEngine::AEMath::operator/((AEMath *)&local_110,(Vector *)&local_68,fVar48);
      AbyssEngine::AEMath::operator+((AEMath *)&local_e8,pVVar42,(Vector *)&local_110);
      AbyssEngine::AEMath::Vector::operator=(pVVar42,(Vector *)&local_e8);
      (**(code **)(*(int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4) + 0x48))
                ((int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),*(undefined4 *)(this + 0x18c),
                 *(undefined4 *)(this + 400),*(undefined4 *)(this + 0x194));
      uVar29 = createShip(this,1,1,0xd,(Waypoint *)0x0,true,false);
      *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 4) = uVar29;
      Player::setAlwaysEnemy
                (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 4) + 4),true);
      fVar48 = *(float *)(this + 400);
      *(float *)(this + 400) = fVar48 + 13000.0;
      fVar51 = *(float *)(this + 0x18c);
      *(float *)(this + 0x18c) = fVar51 + 16000.0;
      fVar47 = *(float *)(this + 0x194);
      *(float *)(this + 0x194) = fVar47 + 16000.0;
      piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + 4);
      (**(code **)(*piVar37 + 0x48))(piVar37,fVar51 + 16000.0,fVar48 + 13000.0,fVar47 + 16000.0);
      if (2 < **(uint **)(this + 0xf8)) {
        uVar25 = 2;
        do {
          pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110));
          uVar29 = createShip(this,1,0,9,pWVar10,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) = uVar29;
          Player::setAlwaysEnemy
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) + 4),
                     true);
          pKVar35 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4);
          pRVar7 = (Route *)Route::clone(*(Route **)(this + 0x110));
          KIPlayer::setRoute(pKVar35,pRVar7);
          uVar25 = uVar25 + 1;
        } while (uVar25 < **(uint **)(this + 0xf8));
      }
      break;
    case 0x38:
      local_a8 = 0;
      local_a0 = 0xffffd120ffff15a0;
      local_98 = 0xfffe5250ffffe4a8;
      local_90 = 15000;
      uStack_8c = 3000;
      local_88 = 0xfffd8f00;
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_a8,9);
      *(Route **)(this + 0x108) = pRVar7;
      uVar29 = Route::clone(pRVar7);
      *(undefined4 *)(this + 0x10c) = uVar29;
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *puVar9 = 0;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(9,pAVar8);
      iVar43 = 0;
      do {
        uVar29 = createShip(this,8,0,0x18,(Waypoint *)0x0,true,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
        Player::setAlwaysFriend
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) + 4),true
                  );
        Player::setAlwaysEnemy
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) + 4),
                   false);
        KIPlayer::setToSleep(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4));
        fVar48 = (float)PlayerEgo::getPosition();
        AbyssEngine::AEMath::operator*((AEMath *)&local_e8,(Vector *)&local_110,fVar48);
        AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x18c),(Vector *)&local_e8);
        fVar47 = *(float *)(this + 0x18c);
        piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4);
        pcVar45 = *(code **)(*piVar37 + 0x48);
        uVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,7000);
        fVar49 = *(float *)(this + 400);
        fVar53 = (float)VectorSignedToFloat(uVar29,(byte)(in_fpscr >> 0x16) & 3);
        uVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,7000);
        fVar48 = *(float *)(this + 0x194);
        fVar54 = (float)VectorSignedToFloat(uVar29,(byte)(in_fpscr >> 0x16) & 3);
        uVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,7000);
        fVar51 = (float)VectorSignedToFloat(uVar29,(byte)(in_fpscr >> 0x16) & 3);
        (*pcVar45)(piVar37,fVar47 + -3500.0 + fVar53,fVar49 + -3500.0 + fVar54,
                   fVar48 + -3500.0 + fVar51);
        pKVar35 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4);
        pRVar7 = (Route *)Route::clone(*(Route **)(this + 0x10c));
        KIPlayer::setRoute(pKVar35,pRVar7);
        Player::setHitpoints
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) + 4),
                   9999999);
        iVar43 = iVar43 + 1;
      } while (iVar43 != 3);
      if (3 < **(uint **)(this + 0xf8)) {
        uVar25 = 3;
        do {
          iVar43 = Globals::getRandomEnemyFighter(Globals::globals,8);
          iVar6 = 2;
          if ((int)uVar25 < 10) {
            iVar6 = 1;
          }
          if ((int)uVar25 < 5) {
            iVar6 = 0;
          }
          pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x108),iVar6);
          uVar29 = createShip(this,8,0,iVar43,pWVar10,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) = uVar29;
          KIPlayer::setToSleep(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4));
          uVar25 = uVar25 + 1;
        } while (uVar25 < **(uint **)(this + 0xf8));
      }
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,0x12,3,9,this);
      goto LAB_000c9d7e;
    case 0x3f:
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *puVar9 = 0;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(7,pAVar8);
      local_a8 = 0;
      local_a0 = (ulonglong)local_a0._4_4_ << 0x20;
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_a8,3);
      pWVar10 = (Waypoint *)Route::getWaypoint(pRVar7);
      uVar29 = createStaticObject(this,pWVar10,0x37a3,true);
      **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar29;
      piVar37 = (int *)Route::getWaypoint(pRVar7);
      (**(code **)(*piVar37 + 0x28))(&local_e8);
      KIPlayer::setToSleep((KIPlayer *)**(undefined4 **)(*(int *)(this + 0xf8) + 4));
      iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
      pSVar24 = (String *)GameText::getText(Globals::gameText,0x1b9);
      AbyssEngine::String::operator=((String *)(iVar43 + 0x18),pSVar24);
      if (1 < **(uint **)(this + 0xf8)) {
        uVar25 = 1;
        do {
          iVar43 = Globals::getRandomEnemyFighter(Globals::globals,8);
          uVar29 = createShip(this,8,0,iVar43,(Waypoint *)0x0,true,false);
          pcVar4 = local_e8;
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) = uVar29;
          iVar43 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
          iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
          fVar48 = fStack_e4;
          iVar40 = -1;
          if (iVar6 == 0) {
            iVar40 = 1;
          }
          iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
          iVar30 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
          pcVar5 = local_e0;
          iVar12 = -1;
          if (iVar30 == 0) {
            iVar12 = 1;
          }
          fVar51 = (float)VectorSignedToFloat(iVar40 * iVar43 + 10000,(byte)(in_fpscr >> 0x16) & 3);
          iVar43 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
          fVar47 = (float)VectorSignedToFloat(iVar12 * iVar6 + 10000,(byte)(in_fpscr >> 0x16) & 3);
          iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
          iVar40 = -1;
          if (iVar6 == 0) {
            iVar40 = 1;
          }
          fVar49 = (float)VectorSignedToFloat(iVar40 * iVar43 + 10000,(byte)(in_fpscr >> 0x16) & 3);
          uVar50 = VectorSignedToFloat((int)((float)pcVar4 + fVar51),(byte)(in_fpscr >> 0x16) & 3);
          uVar52 = VectorSignedToFloat((int)(fVar48 + fVar47),(byte)(in_fpscr >> 0x16) & 3);
          uVar29 = VectorSignedToFloat((int)((float)pcVar5 + fVar49),(byte)(in_fpscr >> 0x16) & 3);
          piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4);
          (**(code **)(*piVar37 + 0x48))(piVar37,uVar50,uVar52,uVar29);
          KIPlayer::setToSleep(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4));
          uVar25 = uVar25 + 1;
        } while (uVar25 < **(uint **)(this + 0xf8));
      }
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,0x1b,4,this);
LAB_000ca4fe:
      *(Objective **)(this + 0x28) = pOVar13;
      break;
    case 0x40:
      uVar29 = *(undefined4 *)(this + 0xf0);
      PlayerEgo::getPosition();
      fVar48 = (float)AEGeometry::getDirection();
      AbyssEngine::AEMath::operator*((AEMath *)&local_e8,(Vector *)&local_110,fVar48);
      AbyssEngine::AEMath::operator-((AEMath *)&local_13c,(Vector *)&local_a8,(Vector *)&local_e8);
      PlayerEgo::setPosition(uVar29,local_13c,uStack_138,uStack_134);
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *puVar9 = 0;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(9,pAVar8);
      local_a0 = (ulonglong)local_a0._4_4_ << 0x20;
      local_a8 = 100000;
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_a8,3);
      *(Route **)(this + 0x110) = pRVar7;
      uVar29 = createShip(this,0,0,0x26,(Waypoint *)0x0,true,false);
      **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar29;
      Player::setAlwaysFriend(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),true);
      iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
      pSVar24 = (String *)GameText::getText(Globals::gameText,0x651);
      AbyssEngine::String::operator=((String *)(iVar43 + 0x18),pSVar24);
      (**(code **)(*(int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4) + 0x48))
                ((int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),0,0,0);
      local_e8 = (char *)0x3f800000;
      fStack_e4 = 0.0;
      local_e0 = (char *)0x0;
      local_110 = 0x3f80000000000000;
      local_108 = (char *)0x0;
      AEGeometry::setDirection
                (*(AEGeometry **)(**(int **)(*(int *)(this + 0xf8) + 4) + 8),(Vector *)&local_e8,
                 (Vector *)&local_110);
      pKVar35 = (KIPlayer *)**(undefined4 **)(*(int *)(this + 0xf8) + 4);
      pRVar7 = (Route *)Route::clone(*(Route **)(this + 0x110));
      KIPlayer::setRoute(pKVar35,pRVar7);
      puVar17 = *(uint **)(this + 0xf8);
      *(undefined4 *)(*(int *)puVar17[1] + 0x4c) = 0;
      if (1 < *puVar17) {
        uVar25 = 1;
        do {
          iVar43 = Globals::getRandomEnemyFighter(Globals::globals,8);
          uVar29 = createShip(this,8,0,iVar43,(Waypoint *)0x0,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) = uVar29;
          piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4);
          pcVar45 = *(code **)(*piVar37 + 0x48);
          iVar43 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x5dc);
          iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
          iVar40 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x5dc);
          iVar30 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
          iVar12 = -1;
          if (iVar30 == 0) {
            iVar12 = 1;
          }
          iVar30 = -1;
          if (iVar6 == 0) {
            iVar30 = 1;
          }
          iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x5dc);
          uVar29 = VectorSignedToFloat((iVar43 + 1000) * iVar30,(byte)(in_fpscr >> 0x16) & 3);
          iVar43 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
          iVar30 = -1;
          if (iVar43 == 0) {
            iVar30 = 1;
          }
          uVar50 = VectorSignedToFloat(iVar12 * (iVar40 + 1000),(byte)(in_fpscr >> 0x16) & 3);
          uVar52 = VectorSignedToFloat((iVar6 + 1000) * iVar30,(byte)(in_fpscr >> 0x16) & 3);
          (*pcVar45)(piVar37,uVar29,uVar50,uVar52);
          local_e8 = (char *)0x3f800000;
          fStack_e4 = 0.0;
          local_e0 = (char *)0x0;
          local_110 = 0x3f80000000000000;
          local_108 = (char *)0x0;
          AEGeometry::setDirection
                    (*(AEGeometry **)
                      (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) + 8),
                     (Vector *)&local_e8,(Vector *)&local_110);
          pKVar35 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4);
          pRVar7 = (Route *)Route::clone(*(Route **)(this + 0x110));
          KIPlayer::setRoute(pKVar35,pRVar7);
          uVar25 = uVar25 + 1;
        } while (uVar25 < **(uint **)(this + 0xf8));
      }
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,0x16,0,this);
      *(Objective **)(this + 0x28) = pOVar13;
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,1,0,this);
      goto LAB_000c8000;
    case 0x41:
      local_a8 = 0;
      local_a0 = (ulonglong)local_a0._4_4_ << 0x20;
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_a8,3);
      *(Route **)(this + 0x110) = pRVar7;
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *puVar9 = 0;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(1,pAVar8);
      uVar29 = createShip(this,0,0,0x26,(Waypoint *)0x0,true,false);
      **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar29;
      Player::setAlwaysFriend(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),true);
      iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
      pSVar24 = (String *)GameText::getText(Globals::gameText,0x651);
      AbyssEngine::String::operator=((String *)(iVar43 + 0x18),pSVar24);
      pKVar35 = (KIPlayer *)**(undefined4 **)(*(int *)(this + 0xf8) + 4);
      pRVar7 = (Route *)Route::clone(*(Route **)(this + 0x110));
      KIPlayer::setRoute(pKVar35,pRVar7);
      Player::setHitpoints(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),9999999);
      break;
    case 0x43:
      local_a0 = CONCAT44(local_a0._4_4_,0xffffd8f0);
      local_a8 = 0xffffb1e000035b60;
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_a8,3);
      *(Route **)(this + 0x110) = pRVar7;
      uVar29 = Route::clone(pRVar7);
      *(undefined4 *)(this + 0x108) = uVar29;
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *puVar9 = 0;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(0xb,pAVar8);
      uVar29 = createStaticObject(this,(Waypoint *)0x0,0x37a3,true);
      **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar29;
      iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
      pSVar24 = (String *)GameText::getText(Globals::gameText,0x1b9);
      AbyssEngine::String::operator=((String *)(iVar43 + 0x18),pSVar24);
      uVar29 = VectorSignedToFloat((float)local_a8,(byte)(in_fpscr >> 0x16) & 3);
      uVar50 = VectorSignedToFloat(local_a8._4_4_,(byte)(in_fpscr >> 0x16) & 3);
      uVar52 = VectorSignedToFloat((float)local_a0,(byte)(in_fpscr >> 0x16) & 3);
      (**(code **)(*(int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4) + 0x48))
                ((int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),uVar29,uVar50,uVar52);
      Player::setAlwaysEnemy(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),false);
      Player::setAlwaysFriend(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),true);
      KIPlayer::setToSleep((KIPlayer *)**(undefined4 **)(*(int *)(this + 0xf8) + 4));
      piVar37 = *(int **)(this + 0xf8);
      if (1 < *piVar37 - 1U) {
        uVar25 = 1;
        do {
          iVar43 = Globals::getRandomEnemyFighter(Globals::globals,8);
          pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110));
          uVar29 = createShip(this,8,0,iVar43,pWVar10,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) = uVar29;
          KIPlayer::setToSleep(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4));
          piVar37 = *(int **)(this + 0xf8);
          piVar34 = *(int **)(piVar37[1] + uVar25 * 4);
          piVar34[0x49] = 150000;
          if (4 < (int)uVar25) {
            (**(code **)(*piVar34 + 0x48))(piVar34,0x49435000,0x49435000,0x49435000);
            piVar37 = *(int **)(this + 0xf8);
          }
          uVar25 = uVar25 + 1;
        } while (uVar25 < *piVar37 - 1U);
      }
      uVar29 = VectorSignedToFloat(local_a8._4_4_,(byte)(in_fpscr >> 0x16) & 3);
      uVar50 = VectorSignedToFloat((float)local_a0,(byte)(in_fpscr >> 0x16) & 3);
      uVar52 = VectorSignedToFloat((int)(float)local_a8 + 30000,(byte)(in_fpscr >> 0x16) & 3);
      (**(code **)(**(int **)(piVar37[1] + 4) + 0x48))
                (*(int **)(piVar37[1] + 4),uVar52,uVar29,uVar50);
      uVar29 = createShip(this,0,0,0x1b,(Waypoint *)0x0,true,false);
      *(undefined4 *)((*(int **)(this + 0xf8))[1] + **(int **)(this + 0xf8) * 4 + -4) = uVar29;
      PlayerEgo::getPosition();
      piVar37 = *(int **)((*(int **)(this + 0xf8))[1] + **(int **)(this + 0xf8) * 4 + -4);
      pcVar45 = *(code **)(*piVar37 + 0x44);
      local_68 = 0x43fa000044fa0000;
      local_60 = -7000.0;
      AbyssEngine::AEMath::operator+((AEMath *)&local_110,(Vector *)&local_e8,(Vector *)&local_68);
      (*pcVar45)(piVar37,(AEMath *)&local_110);
      Player::setAlwaysFriend
                (*(Player **)
                  (*(int *)((*(int **)(this + 0xf8))[1] + **(int **)(this + 0xf8) * 4 + -4) + 4),
                 true);
      iVar43 = *(int *)((*(int **)(this + 0xf8))[1] + **(int **)(this + 0xf8) * 4 + -4);
      pSVar24 = (String *)GameText::getText(Globals::gameText,0x661);
      AbyssEngine::String::operator=((String *)(iVar43 + 0x18),pSVar24);
      Player::setMaxHitpoints
                (*(Player **)
                  (*(int *)((*(int **)(this + 0xf8))[1] + **(int **)(this + 0xf8) * 4 + -4) + 4),
                 9999999);
      pKVar35 = *(KIPlayer **)((*(int **)(this + 0xf8))[1] + **(int **)(this + 0xf8) * 4 + -4);
      pRVar7 = (Route *)Route::clone(*(Route **)(this + 0x108));
      KIPlayer::setRoute(pKVar35,pRVar7);
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,0x16,0,this);
      *(Objective **)(this + 0x28) = pOVar13;
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,1,0,this);
      goto LAB_000c8668;
    case 0x45:
      StarSystem::getPlanets(*(StarSystem **)(this + 0xec));
      fVar48 = (float)AEGeometry::getPosition();
      AbyssEngine::AEMath::Vector::operator*=((Vector *)&local_e8,fVar48);
      auVar55._4_4_ = fStack_e4;
      auVar55._0_4_ = local_e8;
      auVar55._8_4_ = local_e0;
      auVar55._12_4_ = (float)local_e8 * 10.0;
      auVar55 = FPToFixed(auVar55,0,0,3,0x20);
      local_a8 = auVar55._0_8_;
      local_a0 = auVar55._8_8_;
      local_98 = CONCAT44((int)((float)local_e0 * 10.0),(int)(fStack_e4 * 10.0));
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_a8,6);
      *(Route **)(this + 0x110) = pRVar7;
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *puVar9 = 0;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(5,pAVar8);
      uVar29 = createShip(this,0,0,0xc,(Waypoint *)0x0,true,false);
      **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar29;
      Player::setAlwaysFriend(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),true);
      iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
      pSVar24 = (String *)GameText::getText(Globals::gameText,0x65f);
      AbyssEngine::String::operator=((String *)(iVar43 + 0x18),pSVar24);
      pKVar35 = (KIPlayer *)**(undefined4 **)(*(int *)(this + 0xf8) + 4);
      pRVar7 = (Route *)Route::clone(*(Route **)(this + 0x110));
      KIPlayer::setRoute(pKVar35,pRVar7);
      (**(code **)(*(int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4) + 0x44))
                ((int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),(Vector *)&local_e8);
      (**(code **)(*(int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4) + 0x1c))
                ((int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),0x40b00000);
      AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_110,(Vector *)&local_e8);
      AbyssEngine::AEMath::Vector::operator=((Vector *)&local_e8,(Vector *)&local_110);
      local_110 = 0x3f80000000000000;
      local_108 = (char *)0x0;
      AEGeometry::setDirection
                (*(AEGeometry **)(**(int **)(*(int *)(this + 0xf8) + 4) + 8),(Vector *)&local_e8,
                 (Vector *)&local_110);
      local_108 = (char *)0x4e20;
      local_110 = 0;
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_110,3);
      *(Route **)(this + 0x10c) = pRVar7;
      if (1 < **(uint **)(this + 0xf8)) {
        uVar25 = 1;
        do {
          iVar43 = Globals::getRandomEnemyFighter(Globals::globals,0);
          pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x10c));
          uVar29 = createShip(this,0,0,iVar43,pWVar10,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) = uVar29;
          uVar25 = uVar25 + 1;
        } while (uVar25 < **(uint **)(this + 0xf8));
      }
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,0x16,0,this);
      goto LAB_000c9d7e;
    case 0x46:
      uVar29 = *(undefined4 *)(this + 0xf0);
      PlayerEgo::getPosition();
      fVar48 = (float)AEGeometry::getDirection();
      AbyssEngine::AEMath::operator*((AEMath *)&local_e8,(Vector *)&local_110,fVar48);
      AbyssEngine::AEMath::operator-((AEMath *)&local_148,(Vector *)&local_a8,(Vector *)&local_e8);
      PlayerEgo::setPosition(uVar29,local_148,uStack_144,uStack_140);
      (**(code **)(**(int **)(*(int *)(*(int *)(this + 0x100) + 4) + 4) + 0x28))(&local_a8);
      PlayerEgo::getPosition();
      local_110 = CONCAT44((int)local_a8._4_4_,(int)(float)local_a8);
      local_108 = (char *)(int)(float)local_a0;
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_110,3);
      *(Route **)(this + 0x110) = pRVar7;
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *puVar9 = 0;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(1,pAVar8);
      uVar29 = createShip(this,0,0,0xc,(Waypoint *)0x0,true,false);
      **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar29;
      Player::setAlwaysFriend(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),true);
      iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
      pSVar24 = (String *)GameText::getText(Globals::gameText,0x65f);
      AbyssEngine::String::operator=((String *)(iVar43 + 0x18),pSVar24);
      pKVar35 = (KIPlayer *)**(undefined4 **)(*(int *)(this + 0xf8) + 4);
      pRVar7 = (Route *)Route::clone(*(Route **)(this + 0x110));
      KIPlayer::setRoute(pKVar35,pRVar7);
      fVar48 = (float)AbyssEngine::AEMath::operator-
                                ((AEMath *)&local_154,(Vector *)&local_a8,(Vector *)&local_e8);
      AbyssEngine::AEMath::operator/((AEMath *)&local_130,(Vector *)&local_154,fVar48);
      AbyssEngine::AEMath::operator+((AEMath *)&local_68,(Vector *)&local_e8,(Vector *)&local_130);
      AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x18c),(Vector *)&local_68);
      (**(code **)(*(int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4) + 0x44))
                ((int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),(Vector *)(this + 0x18c));
      AbyssEngine::AEMath::operator-((AEMath *)&local_130,(Vector *)&local_a8,(Vector *)&local_e8);
      AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_68,(Vector *)&local_130);
      local_130 = 0.0;
      local_12c = 1.0;
      local_128 = 0.0;
      AEGeometry::setDirection
                (*(AEGeometry **)(**(int **)(*(int *)(this + 0xf8) + 4) + 8),(Vector *)&local_68,
                 (Vector *)&local_130);
      pPVar39 = *(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4);
      uVar29 = Player::getMaxHitpoints(pPVar39);
      fVar48 = (float)VectorSignedToFloat(uVar29,(byte)(in_fpscr >> 0x16) & 3);
      Player::setHitpoints(pPVar39,(int)(fVar48 * 2.5));
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,1,0,this);
      *(Objective **)(this + 0x28) = pOVar13;
      break;
    case 0x49:
      local_a8 = 80000;
      local_a0 = 0x249f00000ea60;
      local_98 = 0xffff3cb000000000;
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_a8,6);
      *(Route **)(this + 0x110) = pRVar7;
      PlayerEgo::setPosition(extraout_s0_05,extraout_s1_06,extraout_s2_05);
      uVar50 = VectorSignedToFloat(local_a0._4_4_ + 20000,(byte)(in_fpscr >> 0x16) & 3);
      uVar29 = VectorSignedToFloat((undefined4)local_98,(byte)(in_fpscr >> 0x16) & 3);
      local_108 = (char *)VectorSignedToFloat(local_98._4_4_,(byte)(in_fpscr >> 0x16) & 3);
      local_110 = CONCAT44(uVar29,uVar50);
      PlayerEgo::getPosition();
      AbyssEngine::AEMath::operator-((AEMath *)&local_e8,(Vector *)&local_110,(Vector *)&local_68);
      pAVar21 = *(AEGeometry **)(*(int *)(this + 0xf0) + 8);
      AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_110,(Vector *)&local_e8);
      local_68 = 0x3f80000000000000;
      local_60 = 0.0;
      AEGeometry::setDirection(pAVar21,(Vector *)&local_110,(Vector *)&local_68);
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *puVar9 = 0;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(0xc,pAVar8);
      iVar43 = 0;
      do {
        iVar6 = Globals::getRandomEnemyFighter(Globals::globals,8);
        pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110),0);
        uVar29 = createShip(this,8,0,iVar6,pWVar10,true,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
        Player::setAlwaysEnemy
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) + 4),true
                  );
        KIPlayer::setToSleep(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4));
        if (3 < iVar43) {
          piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4);
          local_110 = 0xc9435000c9435000;
          local_108 = (char *)0xc9435000;
          (**(code **)(*piVar37 + 0x44))(piVar37,&local_110);
        }
        iVar43 = iVar43 + 1;
      } while (iVar43 != 8);
      if (8 < **(uint **)(this + 0xf8)) {
        uVar25 = 8;
        do {
          uVar29 = createShip(this,0,1,0xf,(Waypoint *)0x0,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) = uVar29;
          Player::setAlwaysFriend
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) + 4),
                     true);
          iVar43 = *(int *)(*(int *)(this + 0xf8) + 4);
          *(undefined4 *)(*(int *)(iVar43 + uVar25 * 4) + 0x4c) = 0;
          PlayerFixedObject::setMoving(*(PlayerFixedObject **)(iVar43 + uVar25 * 4),true);
          piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4);
          pcVar45 = *(code **)(*piVar37 + 0x48);
          iVar43 = Route::getWaypoint(*(Route **)(this + 0x110),1);
          iVar43 = *(int *)(iVar43 + 0x120);
          iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
          iVar40 = Route::getWaypoint(*(Route **)(this + 0x110),1);
          iVar40 = *(int *)(iVar40 + 0x124);
          iVar30 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
          uVar50 = VectorSignedToFloat(iVar6 + iVar43 + -10000,(byte)(in_fpscr >> 0x16) & 3);
          iVar43 = Route::getWaypoint(*(Route **)(this + 0x110),1);
          iVar6 = *(int *)(iVar43 + 0x128);
          uVar52 = VectorSignedToFloat(iVar30 + iVar40 + -10000,(byte)(in_fpscr >> 0x16) & 3);
          iVar43 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
          uVar29 = VectorSignedToFloat(iVar43 + iVar6 + -10000,(byte)(in_fpscr >> 0x16) & 3);
          (*pcVar45)(piVar37,uVar50,uVar52,uVar29);
          uVar25 = uVar25 + 1;
        } while (uVar25 < **(uint **)(this + 0xf8));
      }
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,0x12,0,8,this);
      *(Objective **)(this + 0x28) = pOVar13;
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,0x12,8,0xc,this);
      *(Objective **)(this + 0x2c) = pOVar13;
      break;
    case 0x4e:
      uStack_8c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      local_88 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      uStack_84 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      puVar9 = (undefined4 *)((uint)&local_a8 | 4);
      iVar43 = 0;
      local_a8 = CONCAT44(local_a8._4_4_,0x3f800000);
      *puVar9 = 0;
      puVar9[1] = uStack_8c;
      puVar9[2] = local_88;
      puVar9[3] = uStack_84;
      local_98 = CONCAT44(0x3f800000,(undefined4)local_98);
      local_90 = 0;
      local_80 = 0x3f800000;
      uStack_78 = 0x3f8000003f800000;
      local_70 = 0x3f800000;
      local_e8 = (char *)0x0;
      fStack_e4 = 0.0;
      local_e0 = (char *)0x0;
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *puVar9 = 0;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(0x16,pAVar8);
      iVar6 = 0;
      do {
        uVar29 = createStaticObject(this,(Waypoint *)0x0,0x381b,true);
        uVar50 = *(undefined4 *)((int)&DAT_002539e4 + iVar6);
        local_60 = *(float *)((int)&DAT_002539e8 + iVar6);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43) = uVar29;
        uVar1 = *(ulonglong *)((int)&DAT_002539d4 + iVar6);
        fVar48 = *(float *)((int)&DAT_002539dc + iVar6);
        local_68 = CONCAT44(uVar50,*(undefined4 *)((int)&DAT_002539e0 + iVar6));
        AbyssEngine::AEMath::MatrixRotateVector
                  ((AEMath *)&local_110,(Matrix *)&local_a8,(Vector *)&local_68);
        AbyssEngine::AEMath::Vector::operator=((Vector *)&local_e8,(Vector *)&local_110);
        AEGeometry::setRotation
                  (*(Vector **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43) + 8));
        local_68 = uVar1;
        local_60 = fVar48;
        AbyssEngine::AEMath::MatrixRotateVector
                  ((AEMath *)&local_110,(Matrix *)&local_a8,(Vector *)&local_68);
        AbyssEngine::AEMath::Vector::operator=((Vector *)&local_e8,(Vector *)&local_110);
        piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43);
        pfVar31 = (float *)&DAT_000c8034;
        if (iVar6 == 0) {
          pfVar31 = (float *)&DAT_000c8038;
        }
        local_110 = CONCAT44(fStack_e4,*pfVar31 + (float)local_e8);
        local_108 = local_e0;
        (**(code **)(*piVar37 + 0x44))(piVar37,(AEMath *)&local_110);
        iVar6 = iVar6 + 0x1c;
        iVar43 = iVar43 + 4;
      } while (iVar6 != 0x38);
      if (2 < **(uint **)(this + 0xf8)) {
        uVar25 = 2;
        iVar43 = -17000;
        do {
          iVar6 = Globals::getRandomEnemyFighter(Globals::globals,8);
          uVar29 = createShip(this,8,0,iVar6,(Waypoint *)0x0,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) = uVar29;
          Player::setAlwaysEnemy
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) + 4),
                     true);
          piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4);
          pcVar45 = *(code **)(*piVar37 + 0x44);
          iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,2000);
          iVar40 = AbyssEngine::AERandom::nextInt(Globals::rnd,10000);
          uVar29 = VectorSignedToFloat(iVar6 + iVar43,(byte)(in_fpscr >> 0x16) & 3);
          uVar50 = VectorSignedToFloat(iVar40 + -5000,(byte)(in_fpscr >> 0x16) & 3);
          iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,10000);
          local_108 = (char *)VectorSignedToFloat("fclose" + iVar6 + 1,(byte)(in_fpscr >> 0x16) & 3)
          ;
          local_110 = CONCAT44(uVar50,uVar29);
          (*pcVar45)(piVar37,(Vector *)&local_110);
          local_110 = 0;
          local_108 = (char *)0xbf800000;
          local_68 = 0x3f80000000000000;
          local_60 = 0.0;
          AEGeometry::setDirection
                    (*(AEGeometry **)
                      (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) + 8),
                     (Vector *)&local_110,(Vector *)&local_68);
          KIPlayer::setToSleep(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4));
          iVar43 = iVar43 + 2000;
          uVar25 = uVar25 + 1;
        } while (uVar25 < **(uint **)(this + 0xf8));
      }
      break;
    case 0x4f:
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *puVar9 = 0;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(7,pAVar8);
      if (**(int **)(this + 0xf8) != 0) {
        uVar25 = 0;
        do {
          iVar43 = Globals::getRandomEnemyFighter(Globals::globals,9);
          uVar29 = createShip(this,9,0,iVar43,(Waypoint *)0x0,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) = uVar29;
          Player::setAlwaysEnemy
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) + 4),
                     true);
          uVar25 = uVar25 + 1;
        } while (uVar25 < **(uint **)(this + 0xf8));
      }
      break;
    case 0x50:
      puVar9 = operator_new(0xc);
      puVar18 = operator_new__(4);
      puVar9[1] = puVar18;
      puVar9[2] = 1;
      *puVar18 = 0;
      *puVar9 = 0;
      *(undefined4 **)(this + 0xf8) = puVar9;
      local_110 = 0;
      local_108 = (char *)0x481c4000;
      pSVar19 = (Station *)Galaxy::getStation(Globals::galaxy,0x65);
      pPVar20 = operator_new(0x170);
      PlayerStation::PlayerStation(pPVar20,pSVar19);
      piVar37 = *(int **)(this + 0xf8);
      piVar37[2] = *piVar37 + 1;
      pvVar36 = realloc((void *)piVar37[1],(*piVar37 + 1) * 4);
      piVar37[1] = (int)pvVar36;
      *(PlayerStation **)((int)pvVar36 + *piVar37 * 4) = pPVar20;
      *piVar37 = piVar37[2];
      iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
      Station::getName();
      AbyssEngine::String::operator=((String *)(iVar43 + 0x18),(String *)&local_a8);
      AbyssEngine::String::~String((String *)&local_a8);
      piVar37 = (int *)**(int **)(*(int *)(this + 0xf8) + 4);
      piVar37[9] = 8;
      (**(code **)(*piVar37 + 0x44))(piVar37,&local_110);
      local_a8 = 0;
      local_a0 = (ulonglong)local_a0._4_4_ << 0x20;
      AEGeometry::setRotation(*(Vector **)(**(int **)(*(int *)(this + 0xf8) + 4) + 0x13c));
      fVar48 = extraout_s0_06;
      fVar51 = extraout_s1_07;
      fVar47 = extraout_s2_06;
      if (pSVar19 != (Station *)0x0) {
        pvVar36 = (void *)Station::~Station(pSVar19);
        operator_delete(pvVar36);
        fVar48 = extraout_s0_07;
        fVar51 = extraout_s1_08;
        fVar47 = extraout_s2_07;
      }
      uStack_8c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      local_88 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      uStack_84 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      puVar9 = (undefined4 *)((uint)&local_a8 | 4);
      local_a8 = CONCAT44(local_a8._4_4_,0x3f800000);
      *puVar9 = 0;
      puVar9[1] = uStack_8c;
      puVar9[2] = local_88;
      puVar9[3] = uStack_84;
      local_98 = CONCAT44(0x3f800000,(undefined4)local_98);
      local_90 = 0;
      local_80 = 0x3f800000;
      uStack_78 = 0x3f8000003f800000;
      local_70 = 0x3f800000;
      AbyssEngine::AEMath::MatrixSetRotation((Matrix *)&local_e8,fVar48,fVar51,fVar47);
      local_e8 = (char *)0x0;
      fStack_e4 = 0.0;
      local_e0 = (char *)0x0;
      iVar43 = Status::getLevel(Globals::status);
      if (iVar43 < 0x15) {
        iVar43 = Status::getLevel(Globals::status);
        iVar43 = iVar43 * 0xf + 0xdc;
      }
      else {
        iVar43 = 0x208;
      }
      iVar6 = 0;
      iVar40 = 1;
      do {
        if ((0x9f3U >> (iVar40 - 1U & 0xff) & 1) == 0) {
          iVar30 = 0x381d;
        }
        else {
          iVar30 = 0x381b;
        }
        uVar29 = createStaticObject(this,(Waypoint *)0x0,iVar30,true);
        piVar37 = *(int **)(this + 0xf8);
        piVar37[2] = *piVar37 + 1;
        pvVar36 = realloc((void *)piVar37[1],(*piVar37 + 1) * 4);
        piVar37[1] = (int)pvVar36;
        *(undefined4 *)((int)pvVar36 + *piVar37 * 4) = uVar29;
        *piVar37 = piVar37[2];
        piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar40 * 4);
        Player::setMaxHitpoints((Player *)piVar37[1],iVar43);
        fVar48 = *(float *)((int)&DAT_002539d4 + iVar6);
        fVar51 = *(float *)((int)&DAT_002539d8 + iVar6);
        fVar47 = *(float *)((int)&DAT_002539dc + iVar6);
        local_130 = *(float *)((int)&DAT_002539e0 + iVar6);
        local_12c = *(float *)((int)&DAT_002539e4 + iVar6);
        local_128 = *(float *)((int)&DAT_002539e8 + iVar6);
        AbyssEngine::AEMath::MatrixRotateVector
                  ((AEMath *)&local_68,(Matrix *)&local_a8,(Vector *)&local_130);
        AbyssEngine::AEMath::Vector::operator=((Vector *)&local_e8,(Vector *)&local_68);
        AEGeometry::setRotation((Vector *)piVar37[2]);
        local_130 = fVar48;
        local_12c = fVar51;
        local_128 = fVar47;
        AbyssEngine::AEMath::MatrixRotateVector
                  ((AEMath *)&local_68,(Matrix *)&local_a8,(Vector *)&local_130);
        AbyssEngine::AEMath::Vector::operator=((Vector *)&local_e8,(Vector *)&local_68);
        local_60 = (float)local_108 + (float)local_e0;
        local_68 = CONCAT44(local_110._4_4_ + fStack_e4,(float)local_110 + (float)local_e8);
        (**(code **)(*piVar37 + 0x44))(piVar37,(AEMath *)&local_68);
        piVar37[9] = 8;
        Player::setAlwaysEnemy((Player *)piVar37[1],true);
        iVar6 = iVar6 + 0x1c;
        iVar40 = iVar40 + 1;
      } while (iVar6 != 0x150);
      local_68 = 0;
      local_60 = (float)(int)((float)local_108 * 0.5);
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_68,3);
      iVar43 = 6;
      *(Route **)(this + 0x110) = pRVar7;
      do {
        iVar6 = Globals::getRandomEnemyFighter(Globals::globals,8);
        pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110));
        iVar6 = createShip(this,8,0,iVar6,pWVar10,true,false);
        Player::setAlwaysEnemy(*(Player **)(iVar6 + 4),true);
        Player::setAlwaysFriend(*(Player **)(iVar6 + 4),false);
        piVar37 = *(int **)(this + 0xf8);
        piVar37[2] = *piVar37 + 1;
        pvVar36 = realloc((void *)piVar37[1],(*piVar37 + 1) * 4);
        piVar37[1] = (int)pvVar36;
        iVar43 = iVar43 + -1;
        *(int *)((int)pvVar36 + *piVar37 * 4) = iVar6;
        *piVar37 = piVar37[2];
      } while (iVar43 != 0);
      iVar43 = 3;
      do {
        pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110));
        iVar6 = createShip(this,0,0,0x11,pWVar10,true,false);
        Player::setAlwaysFriend(*(Player **)(iVar6 + 4),true);
        Player::setAlwaysEnemy(*(Player **)(iVar6 + 4),false);
        piVar37 = *(int **)(this + 0xf8);
        piVar37[2] = *piVar37 + 1;
        pvVar36 = realloc((void *)piVar37[1],(*piVar37 + 1) * 4);
        piVar37[1] = (int)pvVar36;
        iVar43 = iVar43 + -1;
        *(int *)((int)pvVar36 + *piVar37 * 4) = iVar6;
        *piVar37 = piVar37[2];
      } while (iVar43 != 0);
      PlayerEgo::setPosition(extraout_s0_14,extraout_s1_15,extraout_s2_14);
      local_130 = 1.0;
      local_12c = 0.0;
      local_128 = 1.0;
      local_154 = 0;
      local_150 = 0x3f800000;
      local_14c = 0;
      AEGeometry::setDirection
                (*(AEGeometry **)(*(int *)(this + 0xf0) + 8),(Vector *)&local_130,
                 (Vector *)&local_154);
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,0x16,0,this);
      goto LAB_000ca772;
    case 0x51:
      puVar9 = operator_new(0xc);
      puVar18 = operator_new__(4);
      puVar9[1] = puVar18;
      puVar9[2] = 1;
      *puVar18 = 0;
      *puVar9 = 0;
      *(undefined4 **)(this + 0xf8) = puVar9;
      pSVar19 = (Station *)Galaxy::getStation(Globals::galaxy,0x65);
      pPVar20 = operator_new(0x170);
      PlayerStation::PlayerStation(pPVar20,pSVar19);
      piVar37 = *(int **)(this + 0xf8);
      piVar37[2] = *piVar37 + 1;
      pvVar36 = realloc((void *)piVar37[1],(*piVar37 + 1) * 4);
      piVar37[1] = (int)pvVar36;
      *(PlayerStation **)((int)pvVar36 + *piVar37 * 4) = pPVar20;
      *piVar37 = piVar37[2];
      iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
      Station::getName();
      AbyssEngine::String::operator=((String *)(iVar43 + 0x18),(String *)&local_a8);
      AbyssEngine::String::~String((String *)&local_a8);
      *(undefined4 *)(**(int **)(*(int *)(this + 0xf8) + 4) + 0x24) = 8;
      if (pSVar19 != (Station *)0x0) {
        pvVar36 = (void *)Station::~Station(pSVar19);
        operator_delete(pvVar36);
      }
      iVar43 = 8;
      do {
        uVar29 = createShip(this,9,0,8,(Waypoint *)0x0,true,false);
        piVar37 = *(int **)(this + 0xf8);
        piVar37[2] = *piVar37 + 1;
        pvVar36 = realloc((void *)piVar37[1],(*piVar37 + 1) * 4);
        piVar37[1] = (int)pvVar36;
        iVar43 = iVar43 + -1;
        *(undefined4 *)((int)pvVar36 + *piVar37 * 4) = uVar29;
        *piVar37 = piVar37[2];
      } while (iVar43 != 0);
      break;
    case 0x57:
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,0x16,0,this);
      goto LAB_000c999e;
    case 0x59:
      local_a8 = 0xffff09e8;
      local_a0 = 0xffff15a0000124f8;
      local_98 = 0x1adb000000000;
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_a8,6);
      *(Route **)(this + 0x10c) = pRVar7;
      Route::setLoop(pRVar7,true);
      local_e8 = (char *)0xffff09e8;
      fStack_e4 = -NAN;
      local_e0 = "$J";
      local_dc = -60000;
      local_d8 = 0x1adb0ffffec78;
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_e8,6);
      *(Route **)(this + 0x110) = pRVar7;
      Route::setLoop(pRVar7,true);
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *puVar9 = 0;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(0xc,pAVar8);
      uVar29 = createStaticObject(this,(Waypoint *)0x0,0x4260,false);
      **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar29;
      PlayerFixedObject::setMoving
                ((PlayerFixedObject *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),false);
      pPVar39 = operator_new(0x114);
      Player::Player(pPVar39,0x1d4c,9999999,0,0,0);
      pPVar33 = operator_new(0x1b4);
      PlayerFixedObject::PlayerFixedObject
                (pPVar33,0x495d,0,pPVar39,(AEGeometry *)0x0,extraout_s0_08,extraout_s1_09,
                 extraout_s2_08);
      *(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 4) = pPVar33;
      pAVar21 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar21,0x5254,Globals::Canvas,false);
      pAVar22 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar22,0x5574,Globals::Canvas,false);
      pAVar23 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar23,0x563c,Globals::Canvas,false);
      AEGeometry::addChild(pAVar21,*(uint *)(pAVar22 + 0xc));
      AEGeometry::addChild(pAVar21,*(uint *)(pAVar23 + 0xc));
      pvVar36 = (void *)AEGeometry::~AEGeometry(pAVar22);
      operator_delete(pvVar36);
      pvVar36 = (void *)AEGeometry::~AEGeometry(pAVar23);
      operator_delete(pvVar36);
      piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + 4);
      (**(code **)(*piVar37 + 8))(piVar37,pAVar21,0xffffffff,0);
      piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + 4);
      local_110 = 0xc53b8000c7966400;
      local_108 = (char *)0x47afc800;
      (**(code **)(*piVar37 + 0x44))(piVar37,&local_110);
      AEGeometry::setRotation
                (*(AEGeometry **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 4) + 8),
                 extraout_s0_09,extraout_s1_10,extraout_s2_09);
      pPVar39 = operator_new(0x114);
      Player::Player(pPVar39,0x1d4c,9999999,0,0,0);
      pPVar33 = operator_new(0x1b4);
      PlayerFixedObject::PlayerFixedObject
                (pPVar33,0x495d,0,pPVar39,(AEGeometry *)0x0,extraout_s0_10,extraout_s1_11,
                 extraout_s2_10);
      *(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 8) = pPVar33;
      pAVar21 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar21,0x5254,Globals::Canvas,false);
      pAVar22 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar22,0x5574,Globals::Canvas,false);
      pAVar23 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar23,0x4990,Globals::Canvas,false);
      this_02 = operator_new(0xc0);
      AEGeometry::AEGeometry(this_02,0x4991,Globals::Canvas,false);
      AEGeometry::addChild(pAVar21,*(uint *)(pAVar22 + 0xc));
      AEGeometry::addChild(pAVar21,*(uint *)(pAVar23 + 0xc));
      AEGeometry::addChild(pAVar21,*(uint *)(this_02 + 0xc));
      pvVar36 = (void *)AEGeometry::~AEGeometry(pAVar22);
      operator_delete(pvVar36);
      pvVar36 = (void *)AEGeometry::~AEGeometry(pAVar23);
      operator_delete(pvVar36);
      pvVar36 = (void *)AEGeometry::~AEGeometry(this_02);
      operator_delete(pvVar36);
      piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + 8);
      (**(code **)(*piVar37 + 8))(piVar37,pAVar21,0xffffffff,0);
      KIPlayer::setVisible(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + 8),false);
      piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + 8);
      local_110 = 0xc53b8000c7966400;
      local_108 = (char *)0x47afc800;
      (**(code **)(*piVar37 + 0x44))(piVar37,(Vector *)&local_110);
      AEGeometry::setRotation
                (*(AEGeometry **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 8) + 8),
                 extraout_s0_11,extraout_s1_12,extraout_s2_11);
      iVar43 = 0;
      do {
        if (iVar43 < 4) {
          pRVar7 = *(Route **)(this + 0x10c);
          uVar25 = (uint)(1 < iVar43);
        }
        else {
          uVar25 = 0;
          pRVar7 = *(Route **)(this + 0x110);
          if (iVar43 < 7) {
            uVar25 = 1;
          }
        }
        pWVar10 = (Waypoint *)Route::getWaypoint(pRVar7,uVar25);
        iVar6 = Globals::getRandomEnemyFighter(Globals::globals,3);
        pKVar35 = (KIPlayer *)createShip(this,3,0,iVar6,pWVar10,true,false);
        pRVar7 = (Route *)Route::clone(*(Route **)(this + 0x10c));
        KIPlayer::setRoute(pKVar35,pRVar7);
        (**(code **)(*(int *)pKVar35 + 0x28))((Vector *)&local_110,pKVar35);
        AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x18c),(Vector *)&local_110);
        fVar48 = *(float *)(this + 400);
        if ((-4000.0 < fVar48) && ((int)((uint)(fVar48 < 2000.0) << 0x1f) < 0)) {
          (**(code **)(*(int *)pKVar35 + 0x48))
                    (pKVar35,*(undefined4 *)(this + 0x18c),fVar48 + fVar48,
                     *(undefined4 *)(this + 0x194));
        }
        pKVar35[0x13a] = (KIPlayer)0x0;
        iVar6 = iVar43 * 4;
        iVar43 = iVar43 + 1;
        *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 + 0xc) = pKVar35;
      } while (iVar43 != 8);
      uVar29 = createShip(this,3,1,0xf,(Waypoint *)0x0,true,false);
      *(undefined4 *)((*(int **)(this + 0xf8))[1] + **(int **)(this + 0xf8) * 4 + -4) = uVar29;
      piVar37 = *(int **)((*(int **)(this + 0xf8))[1] + **(int **)(this + 0xf8) * 4 + -4);
      (**(code **)(*piVar37 + 0x48))(piVar37,0xc7761800,0xc53b8000,0x477de800);
      break;
    case 0x5b:
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *puVar9 = 0;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(1,pAVar8);
      pWVar10 = operator_new(0x134);
      Waypoint::Waypoint(pWVar10,-20000,0,60000,(Route *)0x0);
      uVar29 = createStaticObject(this,pWVar10,0x494e,false);
      **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar29;
      PlayerFixedObject::setMoving
                ((PlayerFixedObject *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),false);
      PlayerFixedObject::setDockingType
                ((PlayerFixedObject *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),0);
      piVar37 = (int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4);
      pcVar45 = *(code **)(*piVar37 + 0x44);
      (**(code **)(*(int *)pWVar10 + 0x28))(&local_a8,pWVar10);
      (*pcVar45)(piVar37,&local_a8);
      Player::setAlwaysFriend(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),true);
      pPVar39 = *(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4);
      iVar43 = Player::getHitpoints(pPVar39);
      Player::setHitpoints(pPVar39,iVar43 / 0x14);
      local_a8 = 0x40afede000000000;
      local_a0 = (ulonglong)local_a0._4_4_ << 0x20;
      AEGeometry::setRotation(*(Vector **)(**(int **)(*(int *)(this + 0xf8) + 4) + 8));
      KIPlayer::setActive(SUB41(**(undefined4 **)(*(int *)(this + 0xf8) + 4),0));
      iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
      pvVar36 = *(void **)(iVar43 + 0x4c);
      if (pvVar36 != (void *)0x0) {
        if (*(void **)((int)pvVar36 + 4) != (void *)0x0) {
          operator_delete__(*(void **)((int)pvVar36 + 4));
        }
        operator_delete(pvVar36);
        iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
      }
      *(undefined4 *)(iVar43 + 0x4c) = 0;
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,1,0,this);
LAB_000c8000:
      *(Objective **)(this + 0x2c) = pOVar13;
      break;
    case 0x5c:
      iVar43 = AbyssEngine::AERandom::nextInt(Globals::rnd,140000);
      local_a8 = (ulonglong)(iVar43 - 70000);
      local_a0 = CONCAT44(local_a0._4_4_,0xfffeee90);
      iVar43 = AbyssEngine::AERandom::nextInt(Globals::rnd,140000);
      local_a0 = CONCAT44(iVar43 + -70000,(float)local_a0);
      local_98 = 0xfffe796000000000;
      local_90 = AbyssEngine::AERandom::nextInt(Globals::rnd,140000);
      local_90 = local_90 + -70000;
      uStack_8c = 0;
      local_88 = 0xfffddd20;
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_a8,9);
      *(Route **)(this + 0x110) = pRVar7;
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *puVar9 = 0;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(4,pAVar8);
      iVar43 = 0;
      do {
        pAVar2 = Globals::rnd;
        pRVar7 = *(Route **)(this + 0x110);
        iVar6 = Route::length(pRVar7);
        iVar6 = AbyssEngine::AERandom::nextInt(pAVar2,iVar6);
        pWVar10 = (Waypoint *)Route::getWaypoint(pRVar7,iVar6);
        uVar29 = createShip(this,10,0,0x2c,pWVar10,true,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
        KIPlayer::setToSleep(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4));
        Player::setAlwaysEnemy
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) + 4),true
                  );
        PlayerFighter::setAIDisabled
                  (*(PlayerFighter **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4),true);
        PlayerFighter::setCloakingPossible
                  (*(PlayerFighter **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4),false);
        iVar43 = iVar43 + 1;
      } while (iVar43 != 3);
      pWVar10 = operator_new(0x134);
      Waypoint::Waypoint(pWVar10,80000,0,110000,(Route *)0x0);
      uVar29 = createStaticObject(this,pWVar10,0x4299,false);
      *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0xc) = uVar29;
      PlayerFixedObject::setMoving
                (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 0xc),false);
      Player::setAlwaysFriend
                (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0xc) + 4),true);
      PlayerFixedObject::setDockingType
                (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 0xc),1);
      pPVar33 = *(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 0xc);
      pSVar24 = (String *)GameText::getText(Globals::gameText,0xc89);
      AbyssEngine::String::String(aSStack_15c,pSVar24,false);
      PlayerFixedObject::setName(pPVar33,aSStack_15c);
      AbyssEngine::String::~String(aSStack_15c);
      iVar43 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0xc);
      pvVar36 = *(void **)(iVar43 + 0x4c);
      if (pvVar36 != (void *)0x0) {
        if (*(void **)((int)pvVar36 + 4) != (void *)0x0) {
          operator_delete__(*(void **)((int)pvVar36 + 4));
        }
        operator_delete(pvVar36);
        iVar43 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0xc);
      }
      *(undefined4 *)(iVar43 + 0x4c) = 0;
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,0x16,0,this);
      *(Objective **)(this + 0x28) = pOVar13;
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,1,3,this);
      goto LAB_000c8668;
    case 0x5e:
      local_e0 = (char *)0xfff551a0;
      local_e8 = (char *)0xfff551a0;
      fStack_e4 = 0.0;
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_e8,3);
      *(Route **)(this + 0x110) = pRVar7;
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *puVar9 = 0;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(10,pAVar8);
      iVar43 = 0;
      do {
        pAVar2 = Globals::rnd;
        pRVar7 = *(Route **)(this + 0x110);
        iVar6 = Route::length(pRVar7);
        iVar6 = AbyssEngine::AERandom::nextInt(pAVar2,iVar6);
        pWVar10 = (Waypoint *)Route::getWaypoint(pRVar7,iVar6);
        uVar29 = createShip(this,10,0,0x2c,pWVar10,true,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
        KIPlayer::setToSleep(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4));
        Player::setAlwaysEnemy
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) + 4),true
                  );
        iVar43 = iVar43 + 1;
      } while (iVar43 != 6);
      uVar29 = createStaticObject(this,(Waypoint *)0x0,0x495d,false);
      *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x18) = uVar29;
      PlayerFixedObject::setMoving
                (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x18),false);
      PlayerFixedObject::setDockingType
                (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x18),2);
      pPVar33 = *(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x18);
      pSVar24 = (String *)GameText::getText(Globals::gameText,0xc88);
      AbyssEngine::String::String(aSStack_164,pSVar24,false);
      PlayerFixedObject::setName(pPVar33,aSStack_164);
      AbyssEngine::String::~String(aSStack_164);
      Player::setAlwaysFriend
                (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x18) + 4),true);
      local_a8 = 0xc016cbe400000000;
      local_a0 = (ulonglong)local_a0._4_4_ << 0x20;
      AEGeometry::rotate(*(Vector **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x18) + 8));
      iVar43 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x18);
      pvVar36 = *(void **)(iVar43 + 0x4c);
      if (pvVar36 != (void *)0x0) {
        if (*(void **)((int)pvVar36 + 4) != (void *)0x0) {
          operator_delete__(*(void **)((int)pvVar36 + 4));
        }
        operator_delete(pvVar36);
        iVar43 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x18);
      }
      *(undefined4 *)(iVar43 + 0x4c) = 0;
      pWVar10 = operator_new(0x134);
      Waypoint::Waypoint(pWVar10,30000,-5000,40000,(Route *)0x0);
      uVar29 = createStaticObject(this,pWVar10,0x4299,false);
      *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x1c) = uVar29;
      PlayerFixedObject::setMoving
                (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x1c),false);
      PlayerFixedObject::setDockingType
                (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x1c),1);
      pPVar33 = *(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x1c);
      pSVar24 = (String *)GameText::getText(Globals::gameText,0xc89);
      AbyssEngine::String::String(aSStack_16c,pSVar24,false);
      PlayerFixedObject::setName(pPVar33,aSStack_16c);
      AbyssEngine::String::~String(aSStack_16c);
      Player::setAlwaysFriend
                (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x1c) + 4),true);
      iVar43 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x1c);
      pvVar36 = *(void **)(iVar43 + 0x4c);
      if (pvVar36 != (void *)0x0) {
        if (*(void **)((int)pvVar36 + 4) != (void *)0x0) {
          operator_delete__(*(void **)((int)pvVar36 + 4));
        }
        operator_delete(pvVar36);
        iVar43 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x1c);
      }
      *(undefined4 *)(iVar43 + 0x4c) = 0;
      local_a8 = 0xffffffffffffffff;
      local_a0 = 0x4e20ffffffff;
      local_98 = 0x7530fffff448;
      local_90 = -1;
      uStack_8c = 0xffffffff;
      local_88 = 0xffffffff;
      local_108 = (char *)0x2ee0;
      local_110 = 12000;
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *puVar9 = 0;
      *(undefined4 *)pAVar8 = 0;
      ArraySetLength<KIPlayer*>(3,pAVar8);
      **(undefined4 **)(pAVar8 + 4) = *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x18);
      *(undefined4 *)(*(int *)(pAVar8 + 4) + 8) =
           *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x1c);
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_a8,pAVar8,(int *)&local_110,9);
      Route::setLoop(pRVar7,true);
      pRVar26 = (Route *)Route::clone(pRVar7);
      iVar43 = 0x20;
      do {
        iVar6 = Globals::getRandomEnemyFighter(Globals::globals,3);
        if (iVar43 == 0x20) {
          pWVar10 = (Waypoint *)Route::getWaypoint(pRVar7,0);
          uVar29 = createShip(this,3,0,iVar6,pWVar10,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x20) = uVar29;
          pKVar35 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x20);
          pRVar28 = pRVar7;
        }
        else {
          pWVar10 = (Waypoint *)Route::getWaypoint(pRVar26,0);
          uVar29 = createShip(this,3,0,iVar6,pWVar10,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43) = uVar29;
          pKVar35 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43);
          pRVar28 = pRVar26;
        }
        KIPlayer::setRoute(pKVar35,pRVar28);
        Player::setAlwaysFriend
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43) + 4),true);
        Player::setNeverAttack
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43) + 4),true);
        iVar43 = iVar43 + 4;
      } while (iVar43 != 0x28);
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,1,7,this);
LAB_000c8668:
      *(Objective **)(this + 0x2c) = pOVar13;
      break;
    case 0x61:
      local_a0 = CONCAT44(local_a0._4_4_,50000);
      local_a8 = 0;
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_a8,3);
      iVar43 = 8;
      *(Route **)(this + 0x110) = pRVar7;
      bVar3 = Globals::isRunningHDonWeakDevice;
      if (Globals::isRunningHDonWeakDevice == 0) {
        iVar43 = 0xc;
      }
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *puVar9 = 0;
      uVar25 = 0xb;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      if (bVar3 == 0) {
        uVar25 = 0x13;
      }
      ArraySetLength<KIPlayer*>(uVar25,pAVar8);
      iVar6 = 0;
      do {
        iVar40 = Globals::getRandomEnemyFighter(Globals::globals,8);
        pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110),0);
        uVar29 = createShip(this,8,0,iVar40,pWVar10,true,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4) = uVar29;
        Player::setAlwaysEnemy
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4) + 4),true)
        ;
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar43);
      iVar40 = 0xb;
      iVar6 = iVar43;
      if (bVar3 == 0) {
        iVar40 = 0x10;
      }
      do {
        iVar30 = Globals::getRandomEnemyFighter(Globals::globals,2);
        pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110),0);
        uVar29 = createShip(this,2,0,iVar30,pWVar10,true,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4) = uVar29;
        Player::setAlwaysFriend
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4) + 4),true)
        ;
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar40);
      if (bVar3 == 0) {
        iVar6 = 0x10;
        do {
          pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110),0);
          uVar29 = createShip(this,2,1,0xf,pWVar10,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4) = uVar29;
          PlayerFixedObject::setMoving
                    (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4),false)
          ;
          Player::setAlwaysFriend
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4) + 4),
                     true);
          iVar6 = iVar6 + 1;
        } while (iVar6 < (int)uVar25);
      }
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,0x12,0,iVar43,this);
      *(Objective **)(this + 0x28) = pOVar13;
      break;
    case 100:
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *puVar9 = 0;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(2,pAVar8);
      PlayerEgo::getPosition();
      AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x18c),(Vector *)&local_a8);
      iVar43 = AbyssEngine::AERandom::nextInt(Globals::rnd,50000);
      iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
      iVar40 = -1;
      if (iVar6 == 0) {
        iVar40 = 1;
      }
      iVar30 = -1;
      fVar48 = (float)VectorSignedToFloat(iVar40 * iVar43 + 20000,(byte)(in_fpscr >> 0x16) & 3);
      *(float *)(this + 0x18c) = *(float *)(this + 0x18c) + fVar48;
      iVar43 = AbyssEngine::AERandom::nextInt(Globals::rnd,50000);
      iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
      iVar40 = -1;
      if (iVar6 == 0) {
        iVar40 = 1;
      }
      fVar48 = (float)VectorSignedToFloat(iVar40 * iVar43 + 10000,(byte)(in_fpscr >> 0x16) & 3);
      *(float *)(this + 400) = *(float *)(this + 400) + fVar48;
      iVar43 = AbyssEngine::AERandom::nextInt(Globals::rnd,50000);
      iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
      if (iVar6 == 0) {
        iVar30 = 1;
      }
      fVar48 = (float)VectorSignedToFloat(iVar30 * iVar43 + 20000,(byte)(in_fpscr >> 0x16) & 3);
      fVar51 = *(float *)(this + 0x194);
      *(float *)(this + 0x194) = fVar51 + fVar48;
      local_a8 = CONCAT44((int)*(float *)(this + 400),(int)*(float *)(this + 0x18c));
      local_a0 = CONCAT44(local_a0._4_4_,(int)(fVar51 + fVar48));
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_a8,3);
      iVar43 = 0;
      do {
        pWVar10 = (Waypoint *)Route::getWaypoint(pRVar7);
        uVar29 = createShip(this,10,0,0x2c,pWVar10,true,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
        Player::setAlwaysEnemy
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) + 4),true
                  );
        iVar43 = iVar43 + 1;
      } while (iVar43 != 2);
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,4,1,this);
LAB_000c9d7e:
      *(Objective **)(this + 0x28) = pOVar13;
      break;
    case 0x66:
      iVar43 = AbyssEngine::AERandom::nextInt(Globals::rnd,140000);
      local_a8 = (ulonglong)(iVar43 - 70000);
      local_a0 = CONCAT44(local_a0._4_4_,0xfffeee90);
      iVar43 = AbyssEngine::AERandom::nextInt(Globals::rnd,140000);
      local_a0 = CONCAT44(iVar43 + -70000,(float)local_a0);
      local_98 = 0xfffe796000000000;
      local_90 = AbyssEngine::AERandom::nextInt(Globals::rnd,140000);
      local_90 = local_90 + -70000;
      uStack_8c = 0;
      local_88 = 0xfffddd20;
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_a8,9);
      *(Route **)(this + 0x110) = pRVar7;
      iVar43 = AbyssEngine::AERandom::nextInt(Globals::rnd,140000);
      local_e8 = (char *)(iVar43 + -70000);
      fStack_e4 = 0.0;
      local_e0 = (char *)0xffffb1e0;
      local_dc = AbyssEngine::AERandom::nextInt(Globals::rnd,140000);
      local_dc = local_dc + -70000;
      local_d8 = 0xfff85ee000000000;
      local_d0 = AbyssEngine::AERandom::nextInt(Globals::rnd,140000);
      local_d0 = local_d0 + -70000;
      uStack_cc = 0;
      local_c8 = 0xfffeee90;
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_e8,9);
      *(Route **)(this + 0x10c) = pRVar7;
      pWVar10 = operator_new(0x134);
      Waypoint::Waypoint(pWVar10,-50000,1000,70000,(Route *)0x0);
      pWVar11 = operator_new(0x134);
      Waypoint::Waypoint(pWVar11,20000,10000,10000,(Route *)0x0);
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *puVar9 = 0;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(10,pAVar8);
      uVar29 = createStaticObject(this,pWVar10,0x4974,true);
      **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar29;
      piVar37 = (int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4);
      pcVar45 = *(code **)(*piVar37 + 0x44);
      (**(code **)(*(int *)pWVar10 + 0x28))(&local_110,pWVar10);
      (*pcVar45)(piVar37,&local_110);
      PlayerFixedObject::setMoving
                ((PlayerFixedObject *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),false);
      piVar37 = *(int **)(*(int *)(this + 0xf8) + 4);
      *(undefined1 *)(*piVar37 + 0x6c) = 0;
      PlayerFixedObject::setDockingType((PlayerFixedObject *)*piVar37,1);
      Player::setAlwaysFriend(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),true);
      Player::setHitpoints(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),9999999);
      iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
      *(undefined1 *)(iVar43 + 0x70) = 1;
      pvVar36 = *(void **)(iVar43 + 0x4c);
      if (pvVar36 != (void *)0x0) {
        if (*(void **)((int)pvVar36 + 4) != (void *)0x0) {
          operator_delete__(*(void **)((int)pvVar36 + 4));
        }
        operator_delete(pvVar36);
        iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
      }
      *(undefined4 *)(iVar43 + 0x4c) = 0;
      uVar29 = createStaticObject(this,pWVar10,0x5279,true);
      *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 4) = uVar29;
      piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + 4);
      (**(code **)(*piVar37 + 0x48))(piVar37,0,0,0);
      PlayerFixedObject::setMoving
                (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 4),false);
      PlayerFixedObject::setDockingType
                (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 4),0);
      Player::setAlwaysFriend
                (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 4) + 4),true);
      Player::setHitpoints
                (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 4) + 4),9999999);
      local_110 = 0x40490fdb00000000;
      local_108 = (char *)0x0;
      AEGeometry::rotate(*(Vector **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 4) + 8));
      KIPlayer::setActive(SUB41(*(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 4),0));
      iVar43 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 4);
      pvVar36 = *(void **)(iVar43 + 0x4c);
      if (pvVar36 != (void *)0x0) {
        if (*(void **)((int)pvVar36 + 4) != (void *)0x0) {
          operator_delete__(*(void **)((int)pvVar36 + 4));
        }
        operator_delete(pvVar36);
        iVar43 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 4);
      }
      iVar40 = 8;
      iVar30 = 25000;
      iVar6 = -30000;
      *(undefined4 *)(iVar43 + 0x4c) = 0;
      do {
        uVar29 = createShip(this,0,0,0x33,pWVar11,true,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar40) = uVar29;
        piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar40);
        pcVar45 = *(code **)(*piVar37 + 0x44);
        if (iVar40 == 8) {
          (**(code **)(*(int *)pWVar10 + 0x28))((Vector *)&local_68);
          local_130 = 10000.0;
          local_12c = 6000.0;
          local_128 = -20000.0;
        }
        else {
          (**(code **)(*(int *)pWVar10 + 0x28))((Vector *)&local_68);
          local_130 = (float)VectorSignedToFloat(iVar30,(byte)(in_fpscr >> 0x16) & 3);
          local_128 = (float)VectorSignedToFloat(iVar6,(byte)(in_fpscr >> 0x16) & 3);
          local_12c = 8000.0;
        }
        AbyssEngine::AEMath::operator+
                  ((AEMath *)&local_110,(Vector *)&local_68,(Vector *)&local_130);
        (*pcVar45)(piVar37,(AEMath *)&local_110);
        Player::setAlwaysFriend
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar40) + 4),true);
        piVar37 = (int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar40);
        iVar40 = iVar40 + 4;
        *(undefined2 *)(*piVar37 + 0x139) = 0;
        iVar6 = iVar6 + -5000;
        iVar30 = iVar30 + 5000;
      } while (iVar40 != 0x18);
      local_110 = 0xffffffffffffffff;
      local_108 = (char *)0xffffffff;
      uStack_104 = 0xffff8ad0;
      local_100 = 0x9c40000003e8;
      uStack_f8 = 0xffffffff;
      uStack_f4 = 0xffffffff;
      uStack_f0 = 0xffffffff;
      local_60 = 2.8026e-41;
      local_68 = 20000;
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *puVar9 = 0;
      *(undefined4 *)pAVar8 = 0;
      ArraySetLength<KIPlayer*>(3,pAVar8);
      **(undefined4 **)(pAVar8 + 4) = **(undefined4 **)(*(int *)(this + 0xf8) + 4);
      *(undefined4 *)(*(int *)(pAVar8 + 4) + 8) =
           *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 4);
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_110,pAVar8,(int *)&local_68,9);
      Route::setLoop(pRVar7,true);
      iVar43 = 2;
      do {
        while (pKVar35 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4),
              iVar43 == 2) {
          KIPlayer::setRoute(pKVar35,pRVar7);
          iVar43 = 3;
        }
        pRVar26 = (Route *)Route::clone(pRVar7);
        KIPlayer::setRoute(pKVar35,pRVar26);
        iVar43 = iVar43 + 1;
      } while (iVar43 != 6);
      iVar43 = 6;
      do {
        uVar29 = createShip(this,10,0,0x2c,pWVar11,true,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
        piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4);
        local_130 = 1e+06;
        local_12c = 1e+06;
        local_128 = 1e+06;
        (**(code **)(*piVar37 + 0x44))(piVar37,&local_130);
        KIPlayer::setToSleep(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4));
        Player::setAlwaysEnemy
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) + 4),true
                  );
        iVar43 = iVar43 + 1;
      } while (iVar43 != 10);
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,4,8,this);
      *(Objective **)(this + 0x28) = pOVar13;
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,0x12,2,6,this);
LAB_000c8e78:
      *(Objective **)(this + 0x2c) = pOVar13;
      break;
    case 0x69:
      local_a8 = 0x6acfc0006acfc0;
      local_a0 = 7000000;
      local_98 = 0;
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_a8,3);
      *(Route **)(this + 0x110) = pRVar7;
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *puVar9 = 0;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(5,pAVar8);
      iVar43 = 0;
      do {
        pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110),0);
        uVar29 = createShip(this,0,0,0x25,pWVar10,true,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
        Player::setAlwaysFriend
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) + 4),true
                  );
        iVar43 = iVar43 + 1;
      } while (iVar43 != 2);
      iVar43 = 2;
      do {
        pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110),0);
        uVar29 = createShip(this,10,0,0x2c,pWVar10,true,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
        KIPlayer::setToSleep(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4));
        Player::setAlwaysEnemy
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) + 4),true
                  );
        iVar43 = iVar43 + 1;
      } while (iVar43 != 5);
      StarSystem::getLightDirection();
      AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_e8,(Vector *)&local_110);
      local_110 = (ulonglong)(uint)(int)((float)local_e8 * 650000.0);
      local_108 = (char *)(int)((float)local_e0 * 650000.0);
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_110,3);
      local_68 = 0x3f80000000000000;
      local_60 = 0.0;
      AEGeometry::setDirection
                (*(AEGeometry **)(*(int *)(this + 0xf0) + 8),(Vector *)&local_e8,(Vector *)&local_68
                );
      PlayerEgo::setRoute(*(PlayerEgo **)(this + 0xf0),pRVar7);
      setPlayerRoute(this,pRVar7);
      iVar43 = 0;
      do {
        piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4);
        pcVar45 = *(code **)(*piVar37 + 0x44);
        PlayerEgo::getPosition();
        fVar48 = (float)AEGeometry::getRightVector();
        AbyssEngine::AEMath::operator*((AEMath *)&local_178,(Vector *)&local_184,fVar48);
        AbyssEngine::AEMath::operator+
                  ((AEMath *)&local_130,(Vector *)&local_154,(Vector *)&local_178);
        fVar48 = (float)AEGeometry::getDirection();
        AbyssEngine::AEMath::operator*((AEMath *)aVStack_190,(Vector *)&local_19c,fVar48);
        AbyssEngine::AEMath::operator+((AEMath *)&local_68,(Vector *)&local_130,aVStack_190);
        (*pcVar45)(piVar37,(AEMath *)&local_68);
        local_68 = 0x3f80000000000000;
        local_60 = 0.0;
        AEGeometry::setDirection
                  (*(AEGeometry **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) + 8),
                   (Vector *)&local_e8,(Vector *)&local_68);
        pKVar35 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4);
        pRVar26 = (Route *)Route::clone(pRVar7);
        KIPlayer::setRoute(pKVar35,pRVar26);
        KIPlayer::setEnemies(*(Array **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4));
        pPVar27 = *(PlayerFighter **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4);
        pPVar27[0x139] = (PlayerFighter)0x0;
        PlayerFighter::setAIDisabled(pPVar27,true);
        iVar43 = iVar43 + 1;
      } while (iVar43 != 2);
      break;
    case 0x6a:
      local_a8 = 0xfff85ee0;
      local_a0 = 0xfff85ee0ffe60f60;
      local_98 = 0xffc78ae000000000;
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_a8,6);
      *(Route **)(this + 0x110) = pRVar7;
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *puVar9 = 0;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(1,pAVar8);
      pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110),0);
      uVar29 = createShip(this,10,0,0x2c,pWVar10,true,false);
      **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar29;
      piVar34 = (int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4);
      pcVar45 = *(code **)(*piVar34 + 0x44);
      piVar37 = (int *)Route::getWaypoint(*(Route **)(this + 0x110),0);
      (**(code **)(*piVar37 + 0x28))(&local_e8);
      (*pcVar45)(piVar34,&local_e8);
      local_e8 = (char *)0xbf800000;
      fStack_e4 = 0.0;
      local_e0 = (char *)0x0;
      local_110 = 0x3f80000000000000;
      local_108 = (char *)0x0;
      AEGeometry::setDirection
                (*(AEGeometry **)(**(int **)(*(int *)(this + 0xf8) + 4) + 8),(Vector *)&local_e8,
                 (Vector *)&local_110);
      pKVar35 = (KIPlayer *)**(undefined4 **)(*(int *)(this + 0xf8) + 4);
      pRVar7 = (Route *)Route::clone(*(Route **)(this + 0x110));
      KIPlayer::setRoute(pKVar35,pRVar7);
      Player::setAlwaysFriend(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),true);
      Player::setAlwaysEnemy(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),false);
      Player::setHitpoints(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),1);
      PlayerFighter::setCloakingPossible
                ((PlayerFighter *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),false);
      break;
    case 0x72:
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *puVar9 = 0;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(6,pAVar8);
      local_a8 = 0;
      local_a0 = (ulonglong)local_a0._4_4_ << 0x20;
      local_e0 = (char *)0x7530;
      local_e8 = (char *)0x0;
      fStack_e4 = 0.0;
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_e8,3);
      iVar43 = 0;
      *(Route **)(this + 0x110) = pRVar7;
      do {
        iVar6 = Globals::getRandomEnemyFighter(Globals::globals,8);
        pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110),0);
        uVar29 = createShip(this,8,0,iVar6,pWVar10,true,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
        (**(code **)(**(int **)((*(uint **)(this + 0xfc))[1] +
                               (iVar43 + (**(uint **)(this + 0xfc) >> 1)) * 4) + 0x28))
                  ((Vector *)&local_110);
        AbyssEngine::AEMath::Vector::operator=((Vector *)&local_a8,(Vector *)&local_110);
        piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4);
        (**(code **)(*piVar37 + 0x48))
                  (piVar37,(float)local_a8,local_a8._4_4_ + 2000.0,(float)local_a0);
        KIPlayer::setToSleep(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4));
        iVar6 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4);
        *(undefined4 *)(iVar6 + 0x124) = 7000;
        pPVar39 = *(Player **)(iVar6 + 4);
        iVar6 = Player::getMaxHitpoints(pPVar39);
        Player::setMaxHitpoints(pPVar39,iVar6 << 1);
        pPVar39 = *(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) + 4);
        iVar6 = Player::getMaxHitpoints(pPVar39);
        Player::setHitpoints(pPVar39,iVar6);
        iVar43 = iVar43 + 1;
      } while (iVar43 != 6);
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,0x12,0,6,this);
      goto LAB_000c999e;
    default:
      switch(iVar6) {
      case 0:
        pAVar8 = operator_new(0xc);
        puVar9 = operator_new__(4);
        *(undefined4 **)(pAVar8 + 4) = puVar9;
        *puVar9 = 0;
        *(undefined4 *)(pAVar8 + 8) = 1;
        *(undefined4 *)pAVar8 = 0;
        *(Array **)(this + 0xf8) = pAVar8;
        ArraySetLength<KIPlayer*>(3,pAVar8);
        if (**(int **)(this + 0xf8) != 0) {
          uVar25 = 0;
          do {
            iVar43 = 2;
            if (uVar25 == 1) {
              iVar43 = 0x17;
            }
            uVar29 = createShip(this,8,0,iVar43,(Waypoint *)0x0,true,false);
            *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) = uVar29;
            KIPlayer::setToSleep(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4));
            Player::setAlwaysEnemy
                      (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) + 4),
                       true);
            piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4);
            (**(code **)(*piVar37 + 0x48))(piVar37,0x47435000,0x47435000,0x47435000);
            iVar43 = *(int *)(*(int *)(this + 0xf8) + 4);
            iVar6 = *(int *)(iVar43 + uVar25 * 4);
            *(undefined1 *)(iVar6 + 0x48) = 0;
            *(undefined4 *)(iVar6 + 0x4c) = 0;
            Player::setHitpoints(*(Player **)(*(int *)(iVar43 + uVar25 * 4) + 4),0x96);
            if ((int)uVar25 < 3) {
              PlayerFighter::setExhaustVisible
                        (*(PlayerFighter **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4),false
                        );
            }
            uVar25 = uVar25 + 1;
          } while (uVar25 < **(uint **)(this + 0xf8));
        }
        Player::setHitpoints((Player *)**(undefined4 **)(this + 0xf0),9999999);
        *(undefined4 *)(Globals::status + 100) = 9999999;
        *(undefined1 *)(**(int **)(this + 0xf0) + 0x5e) = 1;
        break;
      case 1:
        pAVar8 = operator_new(0xc);
        puVar9 = operator_new__(4);
        *(undefined4 **)(pAVar8 + 4) = puVar9;
        *puVar9 = 0;
        *(undefined4 *)(pAVar8 + 8) = 1;
        *(undefined4 *)pAVar8 = 0;
        *(Array **)(this + 0xf8) = pAVar8;
        ArraySetLength<KIPlayer*>(1,pAVar8);
        uVar29 = createShip(this,3,0,0x1e,(Waypoint *)0x0,true,false);
        **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar29;
        (**(code **)(*(int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4) + 0x48))
                  ((int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),0x43960000,0x42480000,
                   0xc5bb8000);
        local_a8 = 0;
        local_a0 = 0xffffec78;
        local_98 = 0;
        pRVar7 = operator_new(0x18);
        Route::Route(pRVar7,(int *)&local_a8,6);
        *(Route **)(this + 0x110) = pRVar7;
        KIPlayer::setRoute((KIPlayer *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),pRVar7);
        (**(code **)(*(int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4) + 0x1c))
                  ((int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),0);
        PlayerFighter::setExhaustVisible
                  ((PlayerFighter *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),false);
        break;
      case 4:
        pAVar8 = operator_new(0xc);
        puVar9 = operator_new__(4);
        *(undefined4 **)(pAVar8 + 4) = puVar9;
        *puVar9 = 0;
        *(undefined4 *)(pAVar8 + 8) = 1;
        *(undefined4 *)pAVar8 = 0;
        *(Array **)(this + 0xf8) = pAVar8;
        ArraySetLength<KIPlayer*>(1,pAVar8);
        uVar29 = createShip(this,8,0,2,(Waypoint *)0x0,true,false);
        **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar29;
        KIPlayer::setInitActive((KIPlayer *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),false);
        Player::setAlwaysEnemy(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),true);
        (**(code **)(*(int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4) + 0x48))
                  ((int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),0,0,0xc8435000);
        KIPlayer::setToSleep((KIPlayer *)**(undefined4 **)(*(int *)(this + 0xf8) + 4));
        break;
      case 7:
        local_a8 = 0xfffff448fffff060;
        local_a0 = 0x271000013880;
        local_98 = 0x2710000001b58;
        pRVar7 = operator_new(0x18);
        Route::Route(pRVar7,(int *)&local_a8,6);
        *(Route **)(this + 0x108) = pRVar7;
        pAVar8 = operator_new(0xc);
        puVar9 = operator_new__(4);
        *(undefined4 **)(pAVar8 + 4) = puVar9;
        *puVar9 = 0;
        *(undefined4 *)(pAVar8 + 8) = 1;
        *(undefined4 *)pAVar8 = 0;
        *(Array **)(this + 0xf8) = pAVar8;
        ArraySetLength<KIPlayer*>(4,pAVar8);
        iVar43 = 0;
        do {
          pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x108),1);
          uVar29 = createShip(this,8,0,2,pWVar10,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
          KIPlayer::setToSleep(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4));
          iVar43 = iVar43 + 1;
        } while (iVar43 != 3);
        uVar29 = createShip(this,3,0,0x1e,(Waypoint *)0x0,true,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0xc) = uVar29;
        Player::setAlwaysFriend
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0xc) + 4),true);
        piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + 0xc);
        (**(code **)(*piVar37 + 0x48))
                  (piVar37,local_11c + 700.0,local_118 + 50.0,local_114 + 6000.0);
        pKVar35 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + 0xc);
        pRVar7 = (Route *)Route::clone(*(Route **)(this + 0x108));
        KIPlayer::setRoute(pKVar35,pRVar7);
        Player::setHitpoints
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0xc) + 4),9999999);
        iVar43 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0xc);
        pSVar24 = (String *)GameText::getText(Globals::gameText,0x63f);
        AbyssEngine::String::operator=((String *)(iVar43 + 0x18),pSVar24);
        PlayerFighter::setBoostProb
                  (*(PlayerFighter **)(*(int *)(*(int *)(this + 0xf8) + 4) + 0xc),0);
        pOVar13 = operator_new(0x1c);
        Objective::Objective(pOVar13,0x12,0,3,this);
        goto LAB_000c999e;
      case 0xe:
        local_a0 = CONCAT44(local_a0._4_4_,30000);
        local_a8 = 0x138800009c40;
        pRVar7 = operator_new(0x18);
        Route::Route(pRVar7,(int *)&local_a8,3);
        *(Route **)(this + 0x110) = pRVar7;
        pAVar8 = operator_new(0xc);
        puVar9 = operator_new__(4);
        *(undefined4 **)(pAVar8 + 4) = puVar9;
        *puVar9 = 0;
        *(undefined4 *)(pAVar8 + 8) = 1;
        *(undefined4 *)pAVar8 = 0;
        *(Array **)(this + 0xf8) = pAVar8;
        ArraySetLength<KIPlayer*>(7,pAVar8);
        iVar43 = 0;
        do {
          pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110));
          uVar29 = createShip(this,8,0,0,pWVar10,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
          iVar43 = iVar43 + 1;
        } while (iVar43 != 3);
        iVar43 = 3;
        do {
          pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110));
          uVar29 = createShip(this,0,0,5,pWVar10,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
          iVar43 = iVar43 + 1;
        } while (iVar43 != 5);
        iVar43 = 5;
        do {
          pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110));
          uVar29 = createShip(this,0,1,0xe,pWVar10,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
          iVar43 = iVar43 + 1;
        } while (iVar43 != 7);
        piVar37 = (int *)Route::getWaypoint(*(Route **)(this + 0x110));
        (**(code **)(*piVar37 + 0x28))((Vector *)&local_e8);
        local_e8 = (char *)((float)local_e8 + 7000.0);
        piVar37 = *(int **)((*(int **)(this + 0xf8))[1] + **(int **)(this + 0xf8) * 4 + -8);
        (**(code **)(*piVar37 + 0x44))(piVar37,(Vector *)&local_e8);
        piVar37 = (int *)Route::getWaypoint(*(Route **)(this + 0x110));
        (**(code **)(*piVar37 + 0x28))((Vector *)&local_110);
        AbyssEngine::AEMath::Vector::operator=((Vector *)&local_e8,(Vector *)&local_110);
        local_e8 = (char *)((float)local_e8 + -9000.0);
        fStack_e4 = fStack_e4 + 2000.0;
        local_e0 = (char *)((float)local_e0 + 7000.0);
        piVar37 = *(int **)((*(int **)(this + 0xf8))[1] + **(int **)(this + 0xf8) * 4 + -4);
        (**(code **)(*piVar37 + 0x44))(piVar37,(Vector *)&local_e8);
        PlayerEgo::setPosition(extraout_s0_12,extraout_s1_13,extraout_s2_12);
        pOVar13 = operator_new(0x1c);
        Objective::Objective(pOVar13,0x1f,0,this);
        goto LAB_000c999e;
      case 0x10:
        local_a0 = CONCAT44(local_a0._4_4_,"le18GetDeviceFreeSpaceEv");
        local_a8 = 0;
        pRVar7 = operator_new(0x18);
        Route::Route(pRVar7,(int *)&local_a8,3);
        *(Route **)(this + 0x110) = pRVar7;
        pAVar8 = operator_new(0xc);
        puVar9 = operator_new__(4);
        *(undefined4 **)(pAVar8 + 4) = puVar9;
        *puVar9 = 0;
        *(undefined4 *)(pAVar8 + 8) = 1;
        *(undefined4 *)pAVar8 = 0;
        *(Array **)(this + 0xf8) = pAVar8;
        ArraySetLength<KIPlayer*>(10,pAVar8);
        iVar43 = Route::getWaypoint(*(Route **)(this + 0x110));
        iVar6 = 0;
        do {
          pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110));
          uVar29 = createShip(this,0,1,0xf,pWVar10,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4) = uVar29;
          Player::setAlwaysFriend
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4) + 4),
                     true);
          PlayerFixedObject::setMoving
                    (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4),false)
          ;
          pPVar39 = *(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4) + 4);
          iVar40 = Player::getMaxHitpoints(pPVar39);
          Player::setMaxHitpoints(pPVar39,iVar40 / 3);
          iVar40 = *(int *)(this + 0xf8);
          iVar30 = *(int *)(*(int *)(iVar40 + 4) + iVar6 * 4);
          pvVar36 = *(void **)(iVar30 + 0x4c);
          if (pvVar36 != (void *)0x0) {
            if (*(void **)((int)pvVar36 + 4) != (void *)0x0) {
              operator_delete__(*(void **)((int)pvVar36 + 4));
            }
            operator_delete(pvVar36);
            iVar40 = *(int *)(this + 0xf8);
            iVar30 = *(int *)(*(int *)(iVar40 + 4) + iVar6 * 4);
          }
          iVar6 = iVar6 + 1;
          *(undefined4 *)(iVar30 + 0x4c) = 0;
        } while (iVar6 != 3);
        uVar29 = VectorSignedToFloat(*(undefined4 *)(iVar43 + 0x120),(byte)(in_fpscr >> 0x16) & 3);
        uVar50 = VectorSignedToFloat(*(undefined4 *)(iVar43 + 0x124),(byte)(in_fpscr >> 0x16) & 3);
        uVar52 = VectorSignedToFloat(*(undefined4 *)(iVar43 + 0x128),(byte)(in_fpscr >> 0x16) & 3);
        (**(code **)(*(int *)**(undefined4 **)(iVar40 + 4) + 0x48))
                  ((int *)**(undefined4 **)(iVar40 + 4),uVar29,uVar50,uVar52);
        pPVar39 = *(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4);
        iVar6 = Player::getMaxHitpoints(pPVar39);
        Player::setMaxHitpoints(pPVar39,iVar6 / 6);
        uVar29 = VectorSignedToFloat(*(int *)(iVar43 + 0x120) + 3000,(byte)(in_fpscr >> 0x16) & 3);
        uVar50 = VectorSignedToFloat(*(int *)(iVar43 + 0x124) + 2000,(byte)(in_fpscr >> 0x16) & 3);
        uVar52 = VectorSignedToFloat(*(int *)(iVar43 + 0x128) + -3000,(byte)(in_fpscr >> 0x16) & 3);
        piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + 4);
        (**(code **)(*piVar37 + 0x48))(piVar37,uVar29,uVar50,uVar52);
        uVar29 = VectorSignedToFloat(*(int *)(iVar43 + 0x120) + -9000,(byte)(in_fpscr >> 0x16) & 3);
        uVar50 = VectorSignedToFloat(*(int *)(iVar43 + 0x124) + -8000,(byte)(in_fpscr >> 0x16) & 3);
        uVar52 = VectorSignedToFloat(*(int *)(iVar43 + 0x128) + -7000,(byte)(in_fpscr >> 0x16) & 3);
        piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + 8);
        (**(code **)(*piVar37 + 0x48))(piVar37,uVar29,uVar50,uVar52);
        iVar6 = 3;
        do {
          pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110));
          uVar29 = createShip(this,9,0,8,pWVar10,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4) = uVar29;
          pPVar39 = *(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4) + 4);
          iVar40 = Player::getMaxHitpoints(pPVar39);
          Player::setMaxHitpoints(pPVar39,iVar40 * 10);
          iVar30 = *(int *)(iVar43 + 0x120);
          piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4);
          pcVar45 = *(code **)(*piVar37 + 0x48);
          iVar40 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
          iVar12 = *(int *)(iVar43 + 0x124);
          uVar52 = VectorSignedToFloat(iVar40 + iVar30 + -10000,(byte)(in_fpscr >> 0x16) & 3);
          iVar40 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
          uVar29 = VectorSignedToFloat(iVar40 + iVar12 + -10000,(byte)(in_fpscr >> 0x16) & 3);
          uVar50 = VectorSignedToFloat(*(int *)(iVar43 + 0x128) + 50000,(byte)(in_fpscr >> 0x16) & 3
                                      );
          (*pcVar45)(piVar37,uVar52,uVar29,uVar50);
          iVar6 = iVar6 + 1;
        } while (iVar6 != 7);
        iVar6 = 7;
        do {
          uVar29 = createShip(this,0,0,5,(Waypoint *)0x0,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4) = uVar29;
          Player::setAlwaysFriend
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4) + 4),
                     true);
          Player::setHitpoints
                    (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4) + 4),600
                    );
          fVar48 = local_11c;
          piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4);
          pcVar45 = *(code **)(*piVar37 + 0x48);
          iVar40 = AbyssEngine::AERandom::nextInt(Globals::rnd,4000);
          fVar51 = local_118;
          fVar49 = (float)VectorSignedToFloat(iVar40 + -2000,(byte)(in_fpscr >> 0x16) & 3);
          iVar40 = AbyssEngine::AERandom::nextInt(Globals::rnd,0xd48);
          fVar54 = local_114 + 2000.0;
          fVar53 = (float)VectorSignedToFloat(iVar40 + -0x6a4,(byte)(in_fpscr >> 0x16) & 3);
          iVar40 = AbyssEngine::AERandom::nextInt(Globals::rnd,4000);
          fVar47 = (float)VectorSignedToFloat(iVar40 + -2000,(byte)(in_fpscr >> 0x16) & 3);
          (*pcVar45)(piVar37,fVar48 + fVar49,fVar51 + fVar53,fVar54 + fVar47);
          iVar6 = iVar6 + 1;
        } while (iVar6 != 10);
        pKVar35 = *(KIPlayer **)(*(int *)(*(int *)(this + 0x100) + 4) + 0xc);
        if (pKVar35 != (KIPlayer *)0x0) {
          KIPlayer::setVisible(pKVar35,true);
          uVar50 = VectorSignedToFloat(*(undefined4 *)(iVar43 + 0x120),(byte)(in_fpscr >> 0x16) & 3)
          ;
          uVar29 = VectorSignedToFloat(*(undefined4 *)(iVar43 + 0x124),(byte)(in_fpscr >> 0x16) & 3)
          ;
          uVar52 = VectorSignedToFloat(*(int *)(iVar43 + 0x128) + 40000,(byte)(in_fpscr >> 0x16) & 3
                                      );
          piVar37 = *(int **)(*(int *)(*(int *)(this + 0x100) + 4) + 0xc);
          (**(code **)(*piVar37 + 0x48))(piVar37,uVar50,uVar29,uVar52);
        }
        pOVar13 = operator_new(0x1c);
        Objective::Objective(pOVar13,0x16,0,this);
        goto LAB_000ca4fe;
      case 0x15:
        local_a8 = 0xffff63c000009c40;
        local_a0 = 0xffffd8f00001d4c0;
        local_98 = 0x2e63000004e20;
        pRVar7 = operator_new(0x18);
        Route::Route(pRVar7,(int *)&local_a8,6);
        *(Route **)(this + 0x108) = pRVar7;
        local_e8 = (char *)0x9c40;
        fStack_e4 = -NAN;
        local_e0 = "\x04";
        local_dc = 0;
        local_d8 = 0;
        pRVar7 = operator_new(0x18);
        Route::Route(pRVar7,(int *)&local_e8,3);
        Route::setLoop(pRVar7,true);
        local_110 = 0x4e20ffffd8f0;
        local_108 = "ne11SetUVMatrixERKNS_6AEMath6MatrixE";
        uStack_104 = 0;
        local_100 = 0;
        pRVar26 = operator_new(0x18);
        Route::Route(pRVar26,(int *)&local_110,3);
        Route::setLoop(pRVar26,true);
        pAVar8 = operator_new(0xc);
        puVar9 = operator_new__(4);
        *(undefined4 **)(pAVar8 + 4) = puVar9;
        *(undefined4 *)(pAVar8 + 8) = 1;
        *puVar9 = 0;
        *(undefined4 *)pAVar8 = 0;
        *(Array **)(this + 0xf8) = pAVar8;
        ArraySetLength<KIPlayer*>(4,pAVar8);
        pWVar10 = (Waypoint *)Route::getWaypoint(pRVar7);
        uVar29 = createShip(this,0,0,5,pWVar10,true,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 4) = uVar29;
        pWVar10 = (Waypoint *)Route::getWaypoint(pRVar7);
        uVar29 = createShip(this,0,0,5,pWVar10,true,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 8) = uVar29;
        pWVar10 = (Waypoint *)Route::getWaypoint(pRVar7);
        uVar29 = createShip(this,0,0,5,pWVar10,true,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0xc) = uVar29;
        pWVar10 = (Waypoint *)Route::getWaypoint(pRVar26);
        uVar29 = createShip(this,0,0,0x11,pWVar10,true,false);
        **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar29;
        iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
        pSVar24 = (String *)GameText::getText(Globals::gameText,0x64b);
        AbyssEngine::String::operator=((String *)(iVar43 + 0x18),pSVar24);
        Player::setAlwaysEnemy(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),true);
        puVar9 = (undefined4 *)(*(int **)(this + 0xf8))[1];
        if (**(int **)(this + 0xf8) != 0) {
          uVar25 = 0;
          do {
            KIPlayer::setToSleep((KIPlayer *)puVar9[uVar25]);
            pKVar35 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4);
            pRVar28 = pRVar26;
            if (uVar25 != 0) {
              pRVar28 = (Route *)Route::clone(pRVar7);
            }
            KIPlayer::setRoute(pKVar35,pRVar28);
            AEGeometry::setRotation
                      (*(AEGeometry **)
                        (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 4) + 8),
                       extraout_s0_13,extraout_s1_14,extraout_s2_13);
            uVar25 = uVar25 + 1;
            puVar9 = (undefined4 *)(*(uint **)(this + 0xf8))[1];
          } while (uVar25 < **(uint **)(this + 0xf8));
        }
        piVar37 = (int *)*puVar9;
        pcVar45 = *(code **)(*piVar37 + 0x48);
        iVar43 = Route::getWaypoint(pRVar26);
        iVar6 = *(int *)(iVar43 + 0x120);
        iVar43 = Route::getWaypoint(pRVar26);
        uVar29 = *(undefined4 *)(iVar43 + 0x124);
        iVar43 = Route::getWaypoint(pRVar26);
        uVar50 = VectorSignedToFloat(iVar6 + 1000,(byte)(in_fpscr >> 0x16) & 3);
        uVar29 = VectorSignedToFloat(uVar29,(byte)(in_fpscr >> 0x16) & 3);
        uVar52 = VectorSignedToFloat(*(int *)(iVar43 + 0x128) + 2000,(byte)(in_fpscr >> 0x16) & 3);
        (*pcVar45)(piVar37,uVar50,uVar29,uVar52);
        pOVar13 = operator_new(0x1c);
        Objective::Objective(pOVar13,0x16,0,this);
        *(Objective **)(this + 0x28) = pOVar13;
        pOVar13 = operator_new(0x1c);
        Objective::Objective(pOVar13,7,1,this);
        *(Objective **)(this + 0x2c) = pOVar13;
        pvVar36 = (void *)Route::~Route(pRVar7);
        operator_delete(pvVar36);
        break;
      case 0x18:
        local_a8 = 100000;
        local_a0 = 0x186a000000000;
        local_98 = 0xffff8ad000000000;
        pRVar7 = operator_new(0x18);
        Route::Route(pRVar7,(int *)&local_a8,6);
        *(Route **)(this + 0x110) = pRVar7;
        pAVar8 = operator_new(0xc);
        puVar9 = operator_new__(4);
        *(undefined4 **)(pAVar8 + 4) = puVar9;
        *puVar9 = 0;
        *(undefined4 *)(pAVar8 + 8) = 1;
        *(undefined4 *)pAVar8 = 0;
        *(Array **)(this + 0xf8) = pAVar8;
        ArraySetLength<KIPlayer*>(5,pAVar8);
        iVar43 = 0;
        do {
          pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110));
          uVar29 = createShip(this,9,0,8,pWVar10,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
          pKVar35 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4);
          pRVar7 = (Route *)Route::clone(*(Route **)(this + 0x110));
          KIPlayer::setRoute(pKVar35,pRVar7);
          iVar43 = iVar43 + 1;
        } while (iVar43 != 3);
        iVar43 = 3;
        do {
          pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110));
          uVar29 = createShip(this,2,1,0xf,pWVar10,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
          PlayerFixedObject::setMoving
                    (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4),false
                    );
          pPVar39 = *(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) + 4);
          iVar6 = Player::getMaxHitpoints(pPVar39);
          Player::setMaxHitpoints(pPVar39,iVar6 / 3);
          iVar6 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4);
          pvVar36 = *(void **)(iVar6 + 0x4c);
          if (pvVar36 != (void *)0x0) {
            if (*(void **)((int)pvVar36 + 4) != (void *)0x0) {
              operator_delete__(*(void **)((int)pvVar36 + 4));
            }
            operator_delete(pvVar36);
            iVar6 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4);
          }
          iVar43 = iVar43 + 1;
          *(undefined4 *)(iVar6 + 0x4c) = 0;
        } while (iVar43 != 5);
        KIPlayer::setVisible(*(KIPlayer **)(*(int *)(*(int *)(this + 0x100) + 4) + 0xc),false);
        pOVar13 = operator_new(0x1c);
        Objective::Objective(pOVar13,0x1f,0,this);
        goto LAB_000c9d7e;
      case 0x19:
      case 0x1d:
        pAVar8 = operator_new(0xc);
        puVar9 = operator_new__(4);
        *(undefined4 **)(pAVar8 + 4) = puVar9;
        *(undefined4 *)(pAVar8 + 8) = 1;
        *puVar9 = 0;
        *(undefined4 *)pAVar8 = 0;
        *(Array **)(this + 0xf8) = pAVar8;
        ArraySetLength<KIPlayer*>(3,pAVar8);
        iVar43 = 0;
        do {
          uVar29 = createShip(this,9,0,8,(Waypoint *)0x0,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
          iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
          iVar40 = -1;
          if (iVar6 == 0) {
            iVar40 = 1;
          }
          iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,80000);
          iVar30 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
          iVar12 = -1;
          if (iVar30 == 0) {
            iVar12 = 1;
          }
          iVar30 = AbyssEngine::AERandom::nextInt(Globals::rnd,80000);
          uVar29 = VectorSignedToFloat((iVar6 + 20000) * iVar40,(byte)(in_fpscr >> 0x16) & 3);
          iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
          iVar40 = -1;
          if (iVar6 == 0) {
            iVar40 = 1;
          }
          iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,80000);
          uVar50 = VectorSignedToFloat((iVar30 + 20000) * iVar12,(byte)(in_fpscr >> 0x16) & 3);
          uVar52 = VectorSignedToFloat(iVar40 * (iVar6 + 20000),(byte)(in_fpscr >> 0x16) & 3);
          piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4);
          (**(code **)(*piVar37 + 0x48))(piVar37,uVar29,uVar50,uVar52);
          iVar43 = iVar43 + 1;
        } while (iVar43 != 3);
        break;
      case 0x1a:
        pAVar8 = operator_new(0xc);
        puVar9 = operator_new__(4);
        *(undefined4 **)(pAVar8 + 4) = puVar9;
        *(undefined4 *)(pAVar8 + 8) = 1;
        *puVar9 = 0;
        *(undefined4 *)pAVar8 = 0;
        *(Array **)(this + 0xf8) = pAVar8;
        ArraySetLength<KIPlayer*>(2,pAVar8);
        iVar43 = 0;
        do {
          uVar29 = createShip(this,9,0,8,(Waypoint *)0x0,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
          PlayerEgo::getPosition();
          AEGeometry::getDirection();
          fVar48 = (float)AbyssEngine::AEMath::VectorNormalize
                                    ((AEMath *)&local_e8,(Vector *)&local_110);
          AbyssEngine::AEMath::operator*((AEMath *)&local_110,(Vector *)&local_e8,fVar48);
          AbyssEngine::AEMath::Vector::operator-=((Vector *)&local_a8,(Vector *)&local_110);
          iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x578);
          fVar48 = (float)VectorSignedToFloat(iVar6 + -700,(byte)(in_fpscr >> 0x16) & 3);
          local_a8._0_4_ = (float)local_a8 + fVar48;
          iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x578);
          fVar48 = (float)VectorSignedToFloat(iVar6 + -700,(byte)(in_fpscr >> 0x16) & 3);
          local_a8 = CONCAT44(local_a8._4_4_ + fVar48,(float)local_a8);
          iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x578);
          fVar48 = (float)VectorSignedToFloat(iVar6 + -700,(byte)(in_fpscr >> 0x16) & 3);
          local_a0 = CONCAT44(local_a0._4_4_,(float)local_a0 + fVar48);
          piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4);
          (**(code **)(*piVar37 + 0x44))(piVar37,(Vector *)&local_a8);
          iVar43 = iVar43 + 1;
        } while (iVar43 != 2);
        pOVar13 = operator_new(0x1c);
        Objective::Objective(pOVar13,7,2,this);
        goto LAB_000ca772;
      case 0x1c:
        piVar37 = *(int **)(*(int *)(*(int *)(this + 0x100) + 4) + 0xc);
        (**(code **)(*piVar37 + 0x48))(piVar37,0x47c35000,0xc7435000,0xc71c4000);
        (**(code **)(**(int **)(*(int *)(*(int *)(this + 0x100) + 4) + 0xc) + 0x28))
                  ((Vector *)&local_a8);
        AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x18c),(Vector *)&local_a8);
        local_a8 = CONCAT44((int)*(float *)(this + 400),(int)*(float *)(this + 0x18c));
        local_a0 = CONCAT44(local_a0._4_4_,(int)*(float *)(this + 0x194));
        pRVar7 = operator_new(0x18);
        Route::Route(pRVar7,(int *)&local_a8,3);
        *(Route **)(this + 0x110) = pRVar7;
        pAVar8 = operator_new(0xc);
        puVar9 = operator_new__(4);
        *(undefined4 **)(pAVar8 + 4) = puVar9;
        *puVar9 = 0;
        *(undefined4 *)(pAVar8 + 8) = 1;
        *(undefined4 *)pAVar8 = 0;
        *(Array **)(this + 0xf8) = pAVar8;
        ArraySetLength<KIPlayer*>(8,pAVar8);
        iVar43 = 0;
        do {
          pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110));
          uVar29 = createShip(this,9,0,8,pWVar10,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
          iVar43 = iVar43 + 1;
        } while (iVar43 != 5);
        iVar43 = 5;
        do {
          pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110));
          uVar29 = createShip(this,0,1,0xf,pWVar10,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
          PlayerFixedObject::setMoving
                    (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4),false
                    );
          pPVar39 = *(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) + 4);
          iVar6 = Player::getMaxHitpoints(pPVar39);
          Player::setMaxHitpoints(pPVar39,(int)(iVar6 + ((uint)(iVar6 >> 0x1f) >> 0x1e)) >> 2);
          iVar6 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4);
          pvVar36 = *(void **)(iVar6 + 0x4c);
          if (pvVar36 != (void *)0x0) {
            if (*(void **)((int)pvVar36 + 4) != (void *)0x0) {
              operator_delete__(*(void **)((int)pvVar36 + 4));
            }
            operator_delete(pvVar36);
            iVar6 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4);
          }
          iVar43 = iVar43 + 1;
          *(undefined4 *)(iVar6 + 0x4c) = 0;
        } while (iVar43 != 8);
      }
    }
    goto switchD_000c340a_caseD_25;
  }
  if (iVar6 < 0x83) {
    if (iVar6 == 0x78) {
      local_a0 = CONCAT44(local_a0._4_4_,0xfffec780);
      local_a8 = 0;
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_a8,3);
      *(Route **)(this + 0x110) = pRVar7;
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *puVar9 = 0;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(2,pAVar8);
      iVar43 = 0;
      do {
        pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110),0);
        uVar29 = createShip(this,10,0,0x2c,pWVar10,true,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
        Player::setAlwaysEnemy
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) + 4),true
                  );
        piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4);
        pcVar45 = *(code **)(*piVar37 + 0x44);
        PlayerEgo::getPosition();
        fVar48 = (float)AEGeometry::getRightVector();
        AbyssEngine::AEMath::operator*((AEMath *)&local_130,(Vector *)&local_154,fVar48);
        AbyssEngine::AEMath::operator+
                  ((AEMath *)&local_110,(Vector *)&local_68,(Vector *)&local_130);
        fVar48 = (float)AEGeometry::getDirection();
        AbyssEngine::AEMath::operator*((AEMath *)&local_178,(Vector *)&local_184,fVar48);
        AbyssEngine::AEMath::operator+
                  ((AEMath *)&local_e8,(Vector *)&local_110,(Vector *)&local_178);
        (*pcVar45)(piVar37,(AEMath *)&local_e8);
        iVar43 = iVar43 + 1;
      } while (iVar43 != 2);
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,4,0,this);
    }
    else if (iVar6 == 0x7b) {
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,4,3,this);
    }
    else {
      if (iVar6 != 0x7d) goto switchD_000c340a_caseD_25;
      local_a8 = 0;
      local_a0 = 0x6acfc000000000;
      local_98 = 0x6acfc0006acfc0;
      pRVar7 = operator_new(0x18);
      Route::Route(pRVar7,(int *)&local_a8,6);
      *(Route **)(this + 0x110) = pRVar7;
      pAVar8 = operator_new(0xc);
      puVar9 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar9;
      *puVar9 = 0;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *(undefined4 *)pAVar8 = 0;
      *(Array **)(this + 0xf8) = pAVar8;
      ArraySetLength<KIPlayer*>(0xf,pAVar8);
      iVar43 = 0;
      do {
        iVar6 = Globals::getRandomEnemyFighter(Globals::globals,8);
        if (iVar43 < 2) {
          pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110),0);
          uVar29 = createShip(this,8,0,iVar6,pWVar10,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
        }
        else {
          pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110),1);
          uVar29 = createShip(this,8,0,iVar6,pWVar10,true,false);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
          KIPlayer::setToSleep(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4));
        }
        Player::setAlwaysEnemy
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) + 4),true
                  );
        iVar43 = iVar43 + 1;
      } while (iVar43 != 8);
      pWVar10 = operator_new(0x134);
      iVar40 = -72000;
      Waypoint::Waypoint(pWVar10,-80000,0,-160000,(Route *)0x0);
      pWVar11 = operator_new(0x134);
      Waypoint::Waypoint(pWVar11,-72000,0,-190000,(Route *)0x0);
      this_00 = operator_new(0x134);
      Waypoint::Waypoint(this_00,-66000,53000,-170000,(Route *)0x0);
      uVar29 = createStaticObject(this,pWVar10,0x4961,true);
      *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x20) = uVar29;
      uVar29 = createStaticObject(this,pWVar11,0x4961,true);
      *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x24) = uVar29;
      uVar29 = createStaticObject(this,this_00,0x4961,true);
      *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 0x28) = uVar29;
      iVar6 = 0;
      iVar43 = *(int *)(*(int *)(this + 0xf8) + 4);
      do {
        PlayerFixedObject::setMoving(*(PlayerFixedObject **)(iVar43 + iVar6 + 0x20),false);
        PlayerFixedObject::setDockingType
                  (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 + 0x20),3);
        Player::setAlwaysEnemy
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 + 0x20) + 4),
                   false);
        Player::setAlwaysFriend
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 + 0x20) + 4),
                   true);
        iVar43 = *(int *)(*(int *)(this + 0xf8) + 4);
        iVar30 = *(int *)(iVar43 + iVar6 + 0x20);
        *(undefined1 *)(iVar30 + 0x70) = 1;
        pvVar36 = *(void **)(iVar30 + 0x4c);
        if (pvVar36 != (void *)0x0) {
          if (*(void **)((int)pvVar36 + 4) != (void *)0x0) {
            operator_delete__(*(void **)((int)pvVar36 + 4));
          }
          operator_delete(pvVar36);
          iVar43 = *(int *)(*(int *)(this + 0xf8) + 4);
          iVar30 = *(int *)(iVar43 + iVar6 + 0x20);
        }
        iVar6 = iVar6 + 4;
        *(undefined4 *)(iVar30 + 0x4c) = 0;
      } while (iVar6 != 0xc);
      iVar6 = 0xb;
      iVar43 = -0x23668;
      iVar30 = 0;
      do {
        uVar29 = createStaticObject(this,(Waypoint *)0x0,0x4962,true);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4) = uVar29;
        PlayerFixedObject::setMoving
                  (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4),false);
        piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4);
        pcVar45 = *(code **)(*piVar37 + 0x48);
        iVar12 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x5dc);
        uVar29 = VectorSignedToFloat(iVar40,(byte)(in_fpscr >> 0x16) & 3);
        uVar50 = VectorSignedToFloat(iVar43,(byte)(in_fpscr >> 0x16) & 3);
        uVar52 = VectorSignedToFloat(iVar12 + iVar30,(byte)(in_fpscr >> 0x16) & 3);
        (*pcVar45)(piVar37,uVar29,uVar52,uVar50);
        fVar48 = (float)VectorSignedToFloat(iVar6,(byte)(in_fpscr >> 0x16) & 3);
        AEGeometry::rotate(*(AEGeometry **)
                            (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4) + 8),
                           fVar48 + -5.759587,extraout_s1,fVar48 + -4.31969);
        iVar12 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4);
        *(undefined1 *)(iVar12 + 0x70) = 1;
        pvVar36 = *(void **)(iVar12 + 0x4c);
        if (pvVar36 != (void *)0x0) {
          if (*(void **)((int)pvVar36 + 4) != (void *)0x0) {
            operator_delete__(*(void **)((int)pvVar36 + 4));
          }
          operator_delete(pvVar36);
          iVar12 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4);
        }
        iVar6 = iVar6 + 1;
        *(undefined4 *)(iVar12 + 0x4c) = 0;
        iVar43 = iVar43 + -4000;
        iVar40 = iVar40 + 4000;
        iVar30 = iVar30 + -200;
      } while (iVar6 != 0xf);
      pOVar13 = operator_new(0x1c);
      Objective::Objective(pOVar13,4,7,this);
    }
    goto LAB_000c999e;
  }
  switch(iVar6) {
  case 0x83:
    pOVar13 = operator_new(0x1c);
    Objective::Objective(pOVar13,4,0,this);
    goto LAB_000c999e;
  case 0x87:
    local_a0 = CONCAT44(local_a0._4_4_,7000000);
    local_a8 = 0x6acfc0006acfc0;
    pRVar7 = operator_new(0x18);
    Route::Route(pRVar7,(int *)&local_a8,3);
    *(Route **)(this + 0x110) = pRVar7;
    pAVar8 = operator_new(0xc);
    puVar9 = operator_new__(4);
    *(undefined4 **)(pAVar8 + 4) = puVar9;
    *(undefined4 *)(pAVar8 + 8) = 1;
    *puVar9 = 0;
    *(undefined4 *)pAVar8 = 0;
    *(Array **)(this + 0xf8) = pAVar8;
    ArraySetLength<KIPlayer*>(3,pAVar8);
    uVar29 = createStaticObject(this,(Waypoint *)0x0,0x4a88,true);
    **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar29;
    (**(code **)(*(int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4) + 0x48))
              ((int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),0,0,0);
    PlayerFixedObject::setMoving
              ((PlayerFixedObject *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),false);
    pPVar33 = (PlayerFixedObject *)**(undefined4 **)(*(int *)(this + 0xf8) + 4);
    pSVar24 = (String *)GameText::getText(Globals::gameText,0xc8a);
    AbyssEngine::String::String(aSStack_1a4,pSVar24,false);
    PlayerFixedObject::setName(pPVar33,aSStack_1a4);
    AbyssEngine::String::~String(aSStack_1a4);
    PlayerFixedObject::setDockingType
              ((PlayerFixedObject *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),1);
    Player::setAlwaysFriend(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),true);
    iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
    pvVar36 = *(void **)(iVar43 + 0x4c);
    if (pvVar36 != (void *)0x0) {
      if (*(void **)((int)pvVar36 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar36 + 4));
      }
      operator_delete(pvVar36);
      iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
    }
    iVar6 = 1;
    *(undefined4 *)(iVar43 + 0x4c) = 0;
    do {
      iVar43 = Globals::getRandomEnemyFighter(Globals::globals,8);
      pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110),0);
      uVar29 = createShip(this,8,0,iVar43,pWVar10,true,false);
      *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4) = uVar29;
      KIPlayer::setToSleep(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4));
      Player::setAlwaysEnemy
                (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4) + 4),true);
      iVar6 = iVar6 + 1;
    } while (iVar6 != 3);
    puVar17 = *(uint **)(this + 0xfc);
    if (*puVar17 != 0) {
      uVar25 = 0;
      do {
        PlayerAsteroid::setAsteroidIndex(*(PlayerAsteroid **)(puVar17[1] + uVar25 * 4),0x9b);
        puVar17 = *(uint **)(this + 0xfc);
        uVar25 = uVar25 + 1;
      } while (uVar25 < *puVar17);
    }
    break;
  case 0x89:
    pOVar13 = operator_new(0x1c);
    Objective::Objective(pOVar13,4,4,this);
    goto LAB_000c999e;
  case 0x8b:
    *(undefined4 *)(Globals::status + 0x174) = 0;
    local_e8 = (char *)0xfffeee90;
    fStack_e4 = 0.0;
    local_e0 = "d";
    local_dc = -30000;
    local_d8 = 0xea6000000000;
    pRVar7 = operator_new(0x18);
    Route::Route(pRVar7,(int *)&local_e8,6);
    *(Route **)(this + 0x110) = pRVar7;
    Route::setLoop(pRVar7,true);
    local_110 = 0xfffca4a0;
    local_108 = (char *)0x9c40;
    uStack_104 = 0xfffd40e0;
    local_100 = 0x4e2000000000;
    pRVar7 = operator_new(0x18);
    Route::Route(pRVar7,(int *)&local_110,6);
    *(Route **)(this + 0x10c) = pRVar7;
    Route::setLoop(pRVar7,true);
    pAVar8 = operator_new(0xc);
    puVar9 = operator_new__(4);
    *(undefined4 **)(pAVar8 + 4) = puVar9;
    *(undefined4 *)(pAVar8 + 8) = 1;
    *puVar9 = 0;
    *(undefined4 *)pAVar8 = 0;
    *(Array **)(this + 0xf8) = pAVar8;
    ArraySetLength<KIPlayer*>(0x16,pAVar8);
    pWVar10 = operator_new(0x134);
    Waypoint::Waypoint(pWVar10,-50000,-0x5dc,70000,(Route *)0x0);
    pWVar11 = operator_new(0x134);
    Waypoint::Waypoint(pWVar11,-200000,-0x5dc,30000,(Route *)0x0);
    uVar29 = createStaticObject(this,pWVar10,0x4a6b,true);
    **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar29;
    piVar37 = (int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4);
    pcVar45 = *(code **)(*piVar37 + 0x44);
    (**(code **)(*(int *)pWVar10 + 0x28))(&local_a8,pWVar10);
    (*pcVar45)(piVar37,&local_a8);
    PlayerFixedObject::setMoving
              ((PlayerFixedObject *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),false);
    PlayerFixedObject::setDockingType
              ((PlayerFixedObject *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),3);
    Player::setHitpoints(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),9999999);
    pPVar33 = (PlayerFixedObject *)**(undefined4 **)(*(int *)(this + 0xf8) + 4);
    pSVar24 = (String *)GameText::getText(Globals::gameText,0x683);
    AbyssEngine::String::String((String *)&local_a8,"",false);
    AbyssEngine::operator+(aAStack_1ac,pSVar24,(String *)&local_a8);
    PlayerFixedObject::setName(pPVar33,aAStack_1ac);
    AbyssEngine::String::~String((String *)aAStack_1ac);
    AbyssEngine::String::~String((String *)&local_a8);
    iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
    pvVar36 = *(void **)(iVar43 + 0x4c);
    if (pvVar36 != (void *)0x0) {
      if (*(void **)((int)pvVar36 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar36 + 4));
      }
      operator_delete(pvVar36);
      iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
    }
    *(undefined4 *)(iVar43 + 0x4c) = 0;
    uVar29 = createStaticObject(this,pWVar11,0x4a6b,true);
    *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 4) = uVar29;
    piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + 4);
    pcVar45 = *(code **)(*piVar37 + 0x44);
    (**(code **)(*(int *)pWVar11 + 0x28))(&local_a8,pWVar11);
    (*pcVar45)(piVar37,&local_a8);
    PlayerFixedObject::setMoving
              (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 4),false);
    PlayerFixedObject::setDockingType
              (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 4),3);
    Player::setHitpoints
              (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 4) + 4),9999999);
    pPVar33 = *(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 4);
    pSVar24 = (String *)GameText::getText(Globals::gameText,0x683);
    AbyssEngine::String::String((String *)&local_a8," 2",false);
    AbyssEngine::operator+(aAStack_1b4,pSVar24,(String *)&local_a8);
    PlayerFixedObject::setName(pPVar33,aAStack_1b4);
    AbyssEngine::String::~String((String *)aAStack_1b4);
    AbyssEngine::String::~String((String *)&local_a8);
    iVar43 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 4);
    pvVar36 = *(void **)(iVar43 + 0x4c);
    if (pvVar36 != (void *)0x0) {
      if (*(void **)((int)pvVar36 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar36 + 4));
      }
      operator_delete(pvVar36);
      iVar43 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 4);
    }
    uStack_8c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    local_88 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uStack_84 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    puVar9 = (undefined4 *)((uint)&local_a8 | 4);
    *(undefined4 *)(iVar43 + 0x4c) = 0;
    local_a8 = CONCAT44(local_a8._4_4_,0x3f800000);
    iVar43 = 2;
    *puVar9 = 0;
    puVar9[1] = uStack_8c;
    puVar9[2] = local_88;
    puVar9[3] = uStack_84;
    iVar6 = 0;
    local_98 = CONCAT44(0x3f800000,(undefined4)local_98);
    local_90 = 0;
    local_80 = 0x3f800000;
    uStack_78 = 0x3f8000003f800000;
    local_70 = 0x3f800000;
    local_68 = 0;
    local_60 = 0.0;
    do {
      uVar29 = createStaticObject(this,(Waypoint *)0x0,0x1a76,true);
      *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
      piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4);
      Player::setMaxHitpoints((Player *)piVar37[1],1000);
      uVar50 = (&DAT_002536b0)[iVar6 * 6];
      uVar29 = (&DAT_002536b4)[iVar6 * 6];
      local_154 = (&DAT_002536b8)[iVar6 * 6];
      local_150 = (&DAT_002536bc)[iVar6 * 6];
      local_14c = (&DAT_002536c0)[iVar6 * 6];
      AbyssEngine::AEMath::MatrixRotateVector
                ((AEMath *)&local_130,(Matrix *)&local_a8,(Vector *)&local_154);
      AbyssEngine::AEMath::Vector::operator=((Vector *)&local_68,(Vector *)&local_130);
      AEGeometry::setRotation((Vector *)piVar37[2]);
      local_154 = (&DAT_002536ac)[iVar6 * 6];
      local_150 = uVar50;
      local_14c = uVar29;
      AbyssEngine::AEMath::MatrixRotateVector
                ((AEMath *)&local_130,(Matrix *)&local_a8,(Vector *)&local_154);
      AbyssEngine::AEMath::Vector::operator=((Vector *)&local_68,(Vector *)&local_130);
      pcVar45 = *(code **)(*piVar37 + 0x44);
      if (iVar43 < 7) {
        (**(code **)(*(int *)pWVar10 + 0x28))(local_1e4,pWVar10);
        fVar51 = local_1e4[0];
        fVar47 = (float)local_68;
        (**(code **)(*(int *)pWVar10 + 0x28))(auStack_1f0,pWVar10);
        fVar48 = local_1ec;
        fVar49 = local_68._4_4_;
        (**(code **)(*(int *)pWVar10 + 0x28))(auStack_1fc,pWVar10);
        local_130 = fVar51 + fVar47;
        local_128 = local_1f4;
      }
      else {
        (**(code **)(*(int *)pWVar11 + 0x28))(local_1c0,pWVar11);
        fVar51 = local_1c0[0];
        fVar47 = (float)local_68;
        (**(code **)(*(int *)pWVar11 + 0x28))(auStack_1cc,pWVar11);
        fVar48 = local_1c8;
        fVar49 = local_68._4_4_;
        (**(code **)(*(int *)pWVar11 + 0x28))(auStack_1d8,pWVar11);
        local_130 = fVar51 + fVar47;
        local_128 = local_1d0;
      }
      local_12c = fVar48 + fVar49;
      local_128 = local_128 + local_60;
      fVar48 = (float)(*pcVar45)(piVar37,(AEMath *)&local_130);
      PlayerTurret::setScaling(fVar48);
      iVar6 = iVar6 + 1;
      piVar37[9] = 1;
      piVar37[0x13] = 0;
      if (iVar6 == 5) {
        iVar6 = 0;
      }
      iVar43 = iVar43 + 1;
    } while (iVar43 != 0xc);
    iVar43 = 0xc;
    do {
      iVar6 = Globals::getRandomEnemyFighter(Globals::globals,1);
      if (iVar43 < 0x11) {
        uVar29 = createShip(this,1,0,iVar6,pWVar10,true,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
        iVar6 = *(int *)(this + 0xf8);
        pRVar7 = *(Route **)(this + 0x110);
      }
      else {
        uVar29 = createShip(this,1,0,iVar6,pWVar11,true,false);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4) = uVar29;
        iVar6 = *(int *)(this + 0xf8);
        pRVar7 = *(Route **)(this + 0x10c);
      }
      pKVar35 = *(KIPlayer **)(*(int *)(iVar6 + 4) + iVar43 * 4);
      pRVar7 = (Route *)Route::clone(pRVar7);
      KIPlayer::setRoute(pKVar35,pRVar7);
      iVar43 = iVar43 + 1;
    } while (iVar43 != 0x16);
    break;
  case 0x8e:
    local_a0 = CONCAT44(local_a0._4_4_,42000);
    local_a8 = 90000;
    pRVar7 = operator_new(0x18);
    Route::Route(pRVar7,(int *)&local_a8,3);
    *(Route **)(this + 0x108) = pRVar7;
    pAVar8 = operator_new(0xc);
    puVar9 = operator_new__(4);
    *(undefined4 **)(pAVar8 + 4) = puVar9;
    *puVar9 = 0;
    *(undefined4 *)(pAVar8 + 8) = 1;
    *(undefined4 *)pAVar8 = 0;
    *(Array **)(this + 0xf8) = pAVar8;
    ArraySetLength<KIPlayer*>(1,pAVar8);
    uVar29 = createShip(this,3,0,0x1e,(Waypoint *)0x0,true,false);
    **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar29;
    Player::setAlwaysFriend(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),true);
    pKVar35 = (KIPlayer *)**(undefined4 **)(*(int *)(this + 0xf8) + 4);
    pRVar7 = (Route *)Route::clone(*(Route **)(this + 0x108));
    KIPlayer::setRoute(pKVar35,pRVar7);
    Player::setHitpoints(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),9999999);
    iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
    pSVar24 = (String *)GameText::getText(Globals::gameText,0x63f);
    AbyssEngine::String::operator=((String *)(iVar43 + 0x18),pSVar24);
    PlayerFighter::setBoostProb((PlayerFighter *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),0);
    piVar37 = (int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4);
    pcVar45 = *(code **)(*piVar37 + 0x44);
    PlayerEgo::getPosition();
    fVar48 = (float)AEGeometry::getRightVector();
    AbyssEngine::AEMath::operator*((AEMath *)&local_130,(Vector *)&local_154,fVar48);
    AbyssEngine::AEMath::operator+((AEMath *)&local_110,(Vector *)&local_68,(Vector *)&local_130);
    fVar48 = (float)AEGeometry::getDirection();
    AbyssEngine::AEMath::operator*((AEMath *)&local_178,(Vector *)&local_184,fVar48);
    AbyssEngine::AEMath::operator+((AEMath *)&local_e8,(Vector *)&local_110,(Vector *)&local_178);
    (*pcVar45)(piVar37,(AEMath *)&local_e8);
    pAVar21 = *(AEGeometry **)(**(int **)(*(int *)(this + 0xf8) + 4) + 8);
    PlayerEgo::GetDirVector();
    local_110 = 0x3f80000000000000;
    local_108 = (char *)0x0;
    AEGeometry::setDirection(pAVar21,(Vector *)&local_e8,(Vector *)&local_110);
    pOVar13 = operator_new(0x1c);
    Objective::Objective(pOVar13,4,4,this);
    goto LAB_000ca772;
  case 0x90:
    local_210 = -5000;
    local_e8 = (char *)0xea60;
    fStack_e4 = 1.4013e-41;
    local_e0 = "\x04";
    local_dc = -50000;
    local_d8 = 0xc35000000000;
    pRVar7 = operator_new(0x18);
    Route::Route(pRVar7,(int *)&local_e8,6);
    *(Route **)(this + 0x110) = pRVar7;
    pWVar10 = (Waypoint *)Route::getWaypoint(pRVar7,0);
    Waypoint::reached(pWVar10);
    pAVar8 = operator_new(0xc);
    puVar9 = operator_new__(4);
    *(undefined4 **)(pAVar8 + 4) = puVar9;
    *puVar9 = 0;
    *(undefined4 *)(pAVar8 + 8) = 1;
    *(undefined4 *)pAVar8 = 0;
    *(Array **)(this + 0xf8) = pAVar8;
    ArraySetLength<KIPlayer*>(0xd,pAVar8);
    piVar37 = (int *)Route::getWaypoint(*(Route **)(this + 0x110),1);
    (**(code **)(*piVar37 + 0x28))((Vector *)&local_a8);
    piVar37 = (int *)Route::getWaypoint(*(Route **)(this + 0x110),0);
    (**(code **)(*piVar37 + 0x28))((Vector *)&local_68);
    AbyssEngine::AEMath::operator-((AEMath *)&local_110,(Vector *)&local_a8,(Vector *)&local_68);
    local_110 = (ulonglong)(uint)(float)local_110;
    AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_a8,(Vector *)&local_110);
    AbyssEngine::AEMath::Vector::operator=((Vector *)&local_110,(Vector *)&local_a8);
    piVar37 = (int *)Route::getWaypoint(*(Route **)(this + 0x110),0);
    (**(code **)(*piVar37 + 0x28))(&local_68);
    uVar29 = createShip(this,2,0,0x31,(Waypoint *)0x0,true,false);
    **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar29;
    piVar34 = (int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4);
    pcVar45 = *(code **)(*piVar34 + 0x44);
    piVar37 = (int *)Route::getWaypoint(*(Route **)(this + 0x110),0);
    (**(code **)(*piVar37 + 0x28))(&local_a8);
    (*pcVar45)(piVar34,&local_a8);
    Player::setAlwaysEnemy(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),true);
    pKVar35 = (KIPlayer *)**(undefined4 **)(*(int *)(this + 0xf8) + 4);
    pRVar7 = (Route *)Route::getExactClone(*(Route **)(this + 0x110));
    KIPlayer::setRoute(pKVar35,pRVar7);
    iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
    pSVar24 = (String *)GameText::getText(Globals::gameText,0x664);
    AbyssEngine::String::operator=((String *)(iVar43 + 0x18),pSVar24);
    local_a8 = 0x3f80000000000000;
    local_a0 = (ulonglong)local_a0._4_4_ << 0x20;
    AEGeometry::setDirection
              (*(AEGeometry **)(**(int **)(*(int *)(this + 0xf8) + 4) + 8),(Vector *)&local_110,
               (Vector *)&local_a8);
    PlayerFighter::setAIDisabled((PlayerFighter *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),true)
    ;
    PlayerFighter::setCloakingPossible
              ((PlayerFighter *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),false);
    puVar14 = (ulonglong *)
              AEGeometry::getMatrix(*(AEGeometry **)(**(int **)(*(int *)(this + 0xf8) + 4) + 8));
    local_a8 = *puVar14;
    local_a0 = puVar14[1];
    local_98 = puVar14[2];
    local_90 = (int)puVar14[3];
    uStack_8c = *(undefined4 *)((int)puVar14 + 0x1c);
    local_88 = (undefined4)puVar14[4];
    uStack_84 = *(undefined4 *)((int)puVar14 + 0x24);
    local_80 = puVar14[5];
    uStack_78 = puVar14[6];
    local_70 = (undefined4)puVar14[7];
    pVVar42 = (Vector *)(this + 0x18c);
    AbyssEngine::AEMath::Vector::operator=(pVVar42,(Vector *)&local_68);
    local_20c = -0x4c2c;
    iVar6 = -65000;
    iVar40 = 8000;
    iVar43 = 0;
    do {
      uVar29 = createShip(this,10,0,0x2c,(Waypoint *)0x0,true,false);
      *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4 + 4) = uVar29;
      Player::setAlwaysEnemy
                (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4 + 4) + 4),
                 true);
      local_130 = 0.0;
      local_12c = 1.0;
      local_128 = 0.0;
      AEGeometry::setDirection
                (*(AEGeometry **)
                  (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4 + 4) + 8),
                 (Vector *)&local_110,(Vector *)&local_130);
      PlayerFighter::setAIDisabled
                (*(PlayerFighter **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4 + 4),true);
      PlayerFighter::setCloakingPossible
                (*(PlayerFighter **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4 + 4),false);
      pKVar35 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4 + 4);
      pRVar7 = (Route *)Route::getExactClone(*(Route **)(this + 0x110));
      KIPlayer::setRoute(pKVar35,pRVar7);
      iVar30 = iVar43 + 1;
      if (iVar30 < 3) {
        local_130 = (float)VectorSignedToFloat(local_210,(byte)(in_fpscr >> 0x16) & 3);
        local_12c = 300.0;
        local_128 = 200.0;
        AbyssEngine::AEMath::Vector::operator=(pVVar42,(Vector *)&local_130);
      }
      else if (iVar30 < 5) {
        local_130 = (float)VectorSignedToFloat(iVar40,(byte)(in_fpscr >> 0x16) & 3);
        local_12c = 300.0;
        local_128 = 200.0;
        AbyssEngine::AEMath::Vector::operator=(pVVar42,(Vector *)&local_130);
      }
      else {
        if (iVar30 < 10) {
          pfVar31 = (float *)&DAT_000c4130;
          local_130 = (float)VectorSignedToFloat(local_20c,(byte)(in_fpscr >> 0x16) & 3);
          if (iVar43 == 6) {
            pfVar31 = (float *)&DAT_000c4134;
          }
          local_12c = *pfVar31;
        }
        else {
          local_130 = (float)VectorSignedToFloat(iVar6,(byte)(in_fpscr >> 0x16) & 3);
          local_12c = -400.0;
        }
        local_128 = -5000.0;
        AbyssEngine::AEMath::Vector::operator=(pVVar42,(Vector *)&local_130);
      }
      iVar12 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x3c);
      fVar48 = (float)VectorSignedToFloat(iVar12 + -0x1e,(byte)(in_fpscr >> 0x16) & 3);
      *(float *)(this + 0x18c) = *(float *)(this + 0x18c) + fVar48;
      iVar12 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x3c);
      fVar48 = (float)VectorSignedToFloat(iVar12 + -0x1e,(byte)(in_fpscr >> 0x16) & 3);
      *(float *)(this + 400) = *(float *)(this + 400) + fVar48;
      iVar12 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x3c);
      fVar48 = (float)VectorSignedToFloat(iVar12 + -0x1e,(byte)(in_fpscr >> 0x16) & 3);
      *(float *)(this + 0x194) = *(float *)(this + 0x194) + fVar48;
      AbyssEngine::AEMath::MatrixTransformVector((AEMath *)&local_130,(Matrix *)&local_a8,pVVar42);
      AbyssEngine::AEMath::Vector::operator=(pVVar42,(Vector *)&local_130);
      piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4 + 4);
      (**(code **)(*piVar37 + 0x44))(piVar37,pVVar42);
      local_210 = local_210 + 0x5dc;
      iVar6 = iVar6 + 0x1964;
      iVar40 = iVar40 + -0x5dc;
      local_20c = local_20c + 0xcb2;
      iVar43 = iVar30;
    } while (iVar30 != 0xc);
    break;
  case 0x91:
    local_a0 = CONCAT44(local_a0._4_4_,60000);
    local_a8 = 0xffff5038;
    pRVar7 = operator_new(0x18);
    Route::Route(pRVar7,(int *)&local_a8,3);
    *(Route **)(this + 0x110) = pRVar7;
    pAVar8 = operator_new(0xc);
    puVar9 = operator_new__(4);
    *(undefined4 **)(pAVar8 + 4) = puVar9;
    *puVar9 = 0;
    *(undefined4 *)(pAVar8 + 8) = 1;
    *(undefined4 *)pAVar8 = 0;
    *(Array **)(this + 0xf8) = pAVar8;
    ArraySetLength<KIPlayer*>(0xe,pAVar8);
    uVar29 = createShip(this,2,0,0x31,(Waypoint *)0x0,true,false);
    **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar29;
    local_e8 = (char *)0x46ea6000;
    fStack_e4 = 0.0;
    local_e0 = (char *)0x479c4000;
    AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x18c),(Vector *)&local_e8);
    (**(code **)(*(int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4) + 0x44))
              ((int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),(Vector *)(this + 0x18c));
    Player::setAlwaysEnemy(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),true);
    iVar6 = **(int **)(*(int *)(this + 0xf8) + 4);
    pSVar24 = (String *)GameText::getText(Globals::gameText,0x664);
    AbyssEngine::String::operator=((String *)(iVar6 + 0x18),pSVar24);
    pKVar35 = (KIPlayer *)**(undefined4 **)(*(int *)(this + 0xf8) + 4);
    pRVar7 = (Route *)Route::clone(*(Route **)(this + 0x110));
    KIPlayer::setRoute(pKVar35,pRVar7);
    piVar37 = *(int **)(*(int *)(this + 0xf8) + 4);
    *(undefined1 *)(*piVar37 + 0x139) = 0;
    pAVar21 = *(AEGeometry **)(*piVar37 + 8);
    local_68 = 0xc7435000;
    local_60 = 50000.0;
    (**(code **)(*(int *)*piVar37 + 0x28))((Vector *)&local_130);
    AbyssEngine::AEMath::operator-((AEMath *)&local_110,(Vector *)&local_68,(Vector *)&local_130);
    AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_e8,(Vector *)&local_110);
    local_154 = 0;
    local_150 = 0x3f800000;
    local_14c = 0;
    AEGeometry::setDirection(pAVar21,(Vector *)&local_e8,(Vector *)&local_154);
    PlayerFighter::setAIDisabled((PlayerFighter *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),true)
    ;
    iVar40 = 23000;
    iVar6 = 1;
    do {
      iVar43 = iVar43 + 2000;
      pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110),0);
      uVar29 = createShip(this,10,0,0x2c,pWVar10,true,false);
      *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4) = uVar29;
      piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4);
      pcVar45 = *(code **)(*piVar37 + 0x48);
      iVar30 = AbyssEngine::AERandom::nextInt(Globals::rnd,1000);
      iVar12 = AbyssEngine::AERandom::nextInt(Globals::rnd,1000);
      iVar15 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x9c4);
      uVar50 = VectorSignedToFloat(iVar40,(byte)(in_fpscr >> 0x16) & 3);
      uVar29 = VectorSignedToFloat(iVar15 + iVar43,(byte)(in_fpscr >> 0x16) & 3);
      uVar52 = VectorSignedToFloat((iVar12 + -500) * iVar6 + iVar30,(byte)(in_fpscr >> 0x16) & 3);
      (*pcVar45)(piVar37,uVar50,uVar52,uVar29);
      pKVar35 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4);
      pRVar7 = (Route *)Route::clone(*(Route **)(this + 0x110));
      KIPlayer::setRoute(pKVar35,pRVar7);
      Player::setAlwaysEnemy
                (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4) + 4),true);
      PlayerFighter::setAIDisabled
                (*(PlayerFighter **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4),true);
      pPVar27 = *(PlayerFighter **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4);
      pPVar27[0x139] = (PlayerFighter)0x0;
      PlayerFighter::setCloakingPossible(pPVar27,false);
      piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4);
      pAVar21 = (AEGeometry *)piVar37[2];
      local_68 = 0xc7435000;
      local_60 = 50000.0;
      (**(code **)(*piVar37 + 0x28))((Vector *)&local_130);
      AbyssEngine::AEMath::operator-((AEMath *)&local_110,(Vector *)&local_68,(Vector *)&local_130);
      AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_e8,(Vector *)&local_110);
      local_154 = 0;
      local_150 = 0x3f800000;
      local_14c = 0;
      AEGeometry::setDirection(pAVar21,(Vector *)&local_e8,(Vector *)&local_154);
      iVar6 = iVar6 + 1;
      iVar40 = iVar40 + 3000;
    } while (iVar6 != 0xd);
    uVar29 = createStaticObject(this,(Waypoint *)0x0,0x4a6a,true);
    *(undefined4 *)((*(int **)(this + 0xf8))[1] + **(int **)(this + 0xf8) * 4 + -4) = uVar29;
    piVar37 = *(int **)((*(int **)(this + 0xf8))[1] + **(int **)(this + 0xf8) * 4 + -4);
    (**(code **)(*piVar37 + 0x48))(piVar37,0xc7435000,0,0x47435000);
    KIPlayer::setVisible
              (*(KIPlayer **)((*(int **)(this + 0xf8))[1] + **(int **)(this + 0xf8) * 4 + -4),false)
    ;
    KIPlayer::setActive(SUB41(*(undefined4 *)
                               ((*(int **)(this + 0xf8))[1] + **(int **)(this + 0xf8) * 4 + -4),0));
    iVar43 = *(int *)((*(int **)(this + 0xf8))[1] + **(int **)(this + 0xf8) * 4 + -4);
    pSVar24 = (String *)GameText::getText(Globals::gameText,0xc87);
    AbyssEngine::String::operator=((String *)(iVar43 + 0x18),pSVar24);
    iVar43 = *(int *)((*(int **)(this + 0xf8))[1] + **(int **)(this + 0xf8) * 4 + -4);
    *(undefined4 *)(iVar43 + 0x24) = 3;
    Player::setHitpoints(*(Player **)(iVar43 + 4),9999999);
    *(undefined1 *)(*(int *)((*(int **)(this + 0xf8))[1] + **(int **)(this + 0xf8) * 4 + -4) + 0x70)
         = 1;
    pOVar13 = operator_new(0x1c);
    Objective::Objective(pOVar13,4,2,this);
    goto LAB_000ca772;
  case 0x93:
    pOVar13 = operator_new(0x1c);
    Objective::Objective(pOVar13,4,1,this);
    goto LAB_000c999e;
  case 0x9a:
    local_e0 = "(\x03";
    local_e8 = "ppEPFvPS0_E";
    fStack_e4 = 0.0;
    pRVar7 = operator_new(0x18);
    Route::Route(pRVar7,(int *)&local_e8,3);
    *(Route **)(this + 0x110) = pRVar7;
    pAVar8 = operator_new(0xc);
    puVar9 = operator_new__(4);
    *(undefined4 **)(pAVar8 + 4) = puVar9;
    *puVar9 = 0;
    *(undefined4 *)(pAVar8 + 8) = 1;
    *(undefined4 *)pAVar8 = 0;
    *(Array **)(this + 0xf8) = pAVar8;
    ArraySetLength<KIPlayer*>(0x16,pAVar8);
    local_108 = (char *)0x9c40;
    local_110 = 0;
    pRVar7 = operator_new(0x18);
    Route::Route(pRVar7,(int *)&local_110,3);
    *(Route **)(this + 0x10c) = pRVar7;
    pWVar10 = (Waypoint *)Route::getWaypoint(pRVar7,0);
    uVar29 = createShip(this,0,0,0x33,pWVar10,true,false);
    **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar29;
    Player::setAlwaysFriend(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),true);
    piVar37 = (int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4);
    pcVar45 = *(code **)(*piVar37 + 0x44);
    PlayerEgo::getPosition();
    fVar48 = (float)AEGeometry::getRightVector();
    AbyssEngine::AEMath::operator*((AEMath *)&local_154,(Vector *)&local_178,fVar48);
    AbyssEngine::AEMath::operator+((AEMath *)&local_68,(Vector *)&local_130,(Vector *)&local_154);
    fVar48 = (float)AEGeometry::getDirection();
    AbyssEngine::AEMath::operator*((AEMath *)&local_184,aVStack_190,fVar48);
    AbyssEngine::AEMath::operator+((AEMath *)&local_a8,(Vector *)&local_68,(Vector *)&local_184);
    (*pcVar45)(piVar37,(AEMath *)&local_a8);
    pAVar21 = *(AEGeometry **)(**(int **)(*(int *)(this + 0xf8) + 4) + 8);
    PlayerEgo::GetDirVector();
    local_68 = 0x3f80000000000000;
    local_60 = 0.0;
    AEGeometry::setDirection(pAVar21,(Vector *)&local_a8,(Vector *)&local_68);
    KIPlayer::setEnemies((Array *)**(undefined4 **)(*(int *)(this + 0xf8) + 4));
    piVar37 = *(int **)(*(int *)(this + 0xf8) + 4);
    *(undefined1 *)(*piVar37 + 0x139) = 0;
    iVar43 = *piVar37;
    pvVar36 = *(void **)(iVar43 + 0x4c);
    if (pvVar36 != (void *)0x0) {
      if (*(void **)((int)pvVar36 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar36 + 4));
      }
      operator_delete(pvVar36);
      iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
    }
    *(undefined4 *)(iVar43 + 0x4c) = 0;
    uVar29 = createStaticObject(this,(Waypoint *)0x0,0x4220,false);
    *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 4) = uVar29;
    PlayerFixedObject::setMoving
              (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 4),false);
    PlayerFixedObject::setDockingType
              (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 4),3);
    pPVar33 = *(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + 4);
    pSVar24 = (String *)GameText::getText(Globals::gameText,0x4d);
    AbyssEngine::String::String(aSStack_204,pSVar24,false);
    PlayerFixedObject::setName(pPVar33,aSStack_204);
    AbyssEngine::String::~String(aSStack_204);
    Player::setAlwaysFriend
              (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 4) + 4),true);
    AEGeometry::setRotation
              (*(AEGeometry **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 4) + 8),extraout_s0,
               extraout_s1_00,extraout_s2);
    iVar43 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 4);
    *(undefined1 *)(iVar43 + 0x70) = 1;
    *(undefined1 *)(iVar43 + 0x6c) = 0;
    pvVar36 = *(void **)(iVar43 + 0x4c);
    if (pvVar36 != (void *)0x0) {
      if (*(void **)((int)pvVar36 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar36 + 4));
      }
      operator_delete(pvVar36);
      iVar43 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + 4);
    }
    *(undefined4 *)(iVar43 + 0x4c) = 0;
    local_a8 = 0x3e8ffffd8f0;
    local_a0 = 0xffffffff00003a98;
    local_98 = 0xffffffffffffffff;
    local_90 = -10000;
    uStack_8c = 1000;
    local_88 = 15000;
    local_60 = 0.0;
    local_68 = 0x271000000000;
    pAVar8 = operator_new(0xc);
    puVar9 = operator_new__(4);
    *(undefined4 **)(pAVar8 + 4) = puVar9;
    *(undefined4 *)(pAVar8 + 8) = 1;
    *puVar9 = 0;
    *(undefined4 *)pAVar8 = 0;
    ArraySetLength<KIPlayer*>(3,pAVar8);
    *(undefined4 *)(*(int *)(pAVar8 + 4) + 4) =
         *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + 4);
    pRVar7 = operator_new(0x18);
    Route::Route(pRVar7,(int *)&local_a8,pAVar8,(int *)&local_68,9);
    KIPlayer::setRoute((KIPlayer *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),pRVar7);
    piVar37 = *(int **)(*(int *)(this + 0xf8) + 4);
    *(undefined1 *)(*piVar37 + 0x13a) = 0;
    Player::setVulnerable(*(Player **)(*piVar37 + 4),false);
    local_130 = 0.0;
    local_12c = 0.0;
    uVar25 = 4;
    local_128 = 40000.0;
    iVar43 = 2;
    do {
      iVar6 = Globals::getRandomEnemyFighter(Globals::globals,9);
      pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x110),0);
      uVar29 = createShip(this,9,0,iVar6,pWVar10,true,false);
      *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 2) = uVar29;
      KIPlayer::setActive(SUB41(*(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 2),0)
                         );
      Player::setAlwaysEnemy
                (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 2) + 4),true);
      piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 2);
      pcVar45 = *(code **)(*piVar37 + 0x44);
      if (iVar43 < 0xb) {
        iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
        pVVar42 = (Vector *)VectorSignedToFloat(iVar43,(byte)(in_fpscr >> 0x16) & 3);
        iVar40 = AbyssEngine::AERandom::nextInt(Globals::rnd,200);
        uVar29 = VectorSignedToFloat((iVar6 + 900) * ((~uVar25 & 2) - 1),
                                     (byte)(in_fpscr >> 0x16) & 3);
        uVar50 = VectorSignedToFloat(iVar40 + -200,(byte)(in_fpscr >> 0x16) & 3);
        iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,400);
        iVar6 = iVar6 + -200;
      }
      else {
        iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
        pVVar42 = (Vector *)VectorSignedToFloat(iVar43,(byte)(in_fpscr >> 0x16) & 3);
        iVar40 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
        uVar29 = VectorSignedToFloat((iVar6 + 0x640) * ((~uVar25 & 2) - 1),
                                     (byte)(in_fpscr >> 0x16) & 3);
        uVar50 = VectorSignedToFloat(iVar40 + -200,(byte)(in_fpscr >> 0x16) & 3);
        iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,500);
        iVar6 = iVar6 + 1000;
      }
      local_17c = (float)VectorSignedToFloat(iVar6,(byte)(in_fpscr >> 0x16) & 3);
      local_184 = uVar29;
      local_180 = uVar50;
      AbyssEngine::AEMath::operator*((AEMath *)&local_178,local_17c,pVVar42);
      AbyssEngine::AEMath::operator+((AEMath *)&local_154,(Vector *)&local_130,(Vector *)&local_178)
      ;
      (*pcVar45)(piVar37,(AEMath *)&local_154);
      pAVar21 = *(AEGeometry **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 2) + 8);
      PlayerEgo::getPosition();
      (**(code **)(**(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar25 * 2) + 0x28))
                (aVStack_190);
      AbyssEngine::AEMath::operator-((AEMath *)&local_178,(Vector *)&local_184,aVStack_190);
      AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_154,(Vector *)&local_178);
      local_19c = 0;
      local_198 = 0x3f800000;
      uStack_194 = 0;
      AEGeometry::setDirection(pAVar21,(Vector *)&local_154,(Vector *)&local_19c);
      uVar25 = uVar25 + 2;
      iVar43 = iVar43 + 1;
    } while (uVar25 != 0x2c);
    pOVar13 = operator_new(0x1c);
    Objective::Objective(pOVar13,4,0xb,this);
LAB_000ca772:
    *(Objective **)(this + 0x28) = pOVar13;
    break;
  case 0x9b:
    pOVar13 = operator_new(0x1c);
    Objective::Objective(pOVar13,4,2,this);
    goto LAB_000c999e;
  case 0x9d:
    local_a8 = 70000;
    local_a0 = 0x753000004e20;
    local_98 = 0xea6000002710;
    pRVar7 = operator_new(0x18);
    Route::Route(pRVar7,(int *)&local_a8,6);
    *(Route **)(this + 0x10c) = pRVar7;
    pWVar10 = (Waypoint *)Route::getWaypoint(pRVar7,0);
    Waypoint::reached(pWVar10);
    local_e8 = (char *)0xfffe5250;
    fStack_e4 = 1.4013e-41;
    local_e0 = "le18GetDeviceFreeSpaceEv";
    local_dc = -110000;
    local_d8 = 0x4e2000000000;
    pRVar7 = operator_new(0x18);
    Route::Route(pRVar7,(int *)&local_e8,6);
    *(Route **)(this + 0x110) = pRVar7;
    pWVar10 = (Waypoint *)Route::getWaypoint(pRVar7,0);
    Waypoint::reached(pWVar10);
    pAVar8 = operator_new(0xc);
    puVar9 = operator_new__(4);
    *(undefined4 **)(pAVar8 + 4) = puVar9;
    *(undefined4 *)(pAVar8 + 8) = 1;
    *puVar9 = 0;
    uVar25 = 10;
    *(undefined4 *)pAVar8 = 0;
    *(Array **)(this + 0xf8) = pAVar8;
    uVar38 = (uint)Globals::isRunningHDonWeakDevice;
    if (uVar38 == 0) {
      uVar25 = 0x14;
    }
    uVar46 = uVar38 ^ 1;
    ArraySetLength<KIPlayer*>((uVar25 | uVar46) + 3,pAVar8);
    iVar43 = 5;
    local_110 = 0xc7ea6000;
    local_108 = (char *)0x469c4000;
    if (uVar38 == 0) {
      iVar43 = 10;
    }
    pSVar19 = (Station *)Galaxy::getStation(Globals::galaxy,0x65);
    pPVar20 = operator_new(0x170);
    PlayerStation::PlayerStation(pPVar20,pSVar19);
    iVar40 = iVar43 + uVar46;
    iVar30 = iVar40 + iVar43;
    iVar12 = iVar30 + 2;
    *(PlayerStation **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar12 * 4) = pPVar20;
    iVar6 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar12 * 4);
    Station::getName();
    AbyssEngine::String::operator=((String *)(iVar6 + 0x18),(String *)&local_68);
    AbyssEngine::String::~String((String *)&local_68);
    piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar12 * 4);
    piVar37[9] = 3;
    (**(code **)(*piVar37 + 0x44))(piVar37,&local_110);
    iVar6 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar12 * 4);
    pvVar36 = *(void **)(iVar6 + 0x4c);
    if (pvVar36 != (void *)0x0) {
      if (*(void **)((int)pvVar36 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar36 + 4));
      }
      operator_delete(pvVar36);
      iVar6 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar12 * 4);
    }
    *(undefined4 *)(iVar6 + 0x4c) = 0;
    if (pSVar19 != (Station *)0x0) {
      pvVar36 = (void *)Station::~Station(pSVar19);
      operator_delete(pvVar36);
    }
    iVar6 = 0;
    do {
      iVar15 = Globals::getRandomEnemyFighter(Globals::globals,0);
      pWVar10 = (Waypoint *)Route::getWaypoint(*(Route **)(this + 0x10c),0);
      uVar29 = createShip(this,0,0,iVar15,pWVar10,true,false);
      *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4) = uVar29;
      Player::setAlwaysFriend
                (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4) + 4),true);
      pKVar35 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4);
      pRVar7 = (Route *)Route::getExactClone(*(Route **)(this + 0x10c));
      KIPlayer::setRoute(pKVar35,pRVar7);
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar43);
    iVar6 = iVar43;
    if (uVar46 != 0) {
      do {
        uVar29 = createStaticObject(this,(Waypoint *)0x0,0x4974,true);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4) = uVar29;
        PlayerFixedObject::setMoving
                  (*(PlayerFixedObject **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4),false);
        Player::setAlwaysFriend
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4) + 4),true)
        ;
        piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4);
        (**(code **)(*piVar37 + 0x48))(piVar37,0x46ea6000,0xc66a6000,0xc7435000);
        iVar15 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4);
        pvVar36 = *(void **)(iVar15 + 0x4c);
        if (pvVar36 != (void *)0x0) {
          if (*(void **)((int)pvVar36 + 4) != (void *)0x0) {
            operator_delete__(*(void **)((int)pvVar36 + 4));
          }
          operator_delete(pvVar36);
          iVar15 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar6 * 4);
        }
        *(undefined4 *)(iVar15 + 0x4c) = 0;
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar40);
    }
    piVar37 = (int *)Route::getWaypoint(*(Route **)(this + 0x110),1);
    (**(code **)(*piVar37 + 0x28))((Vector *)&local_130);
    piVar37 = (int *)Route::getWaypoint(*(Route **)(this + 0x110),0);
    (**(code **)(*piVar37 + 0x28))((Vector *)&local_154);
    AbyssEngine::AEMath::operator-((AEMath *)&local_68,(Vector *)&local_130,(Vector *)&local_154);
    local_68 = (ulonglong)(uint)(float)local_68;
    AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_130,(Vector *)&local_68);
    AbyssEngine::AEMath::Vector::operator=((Vector *)&local_68,(Vector *)&local_130);
    piVar37 = (int *)Route::getWaypoint(*(Route **)(this + 0x110),0);
    (**(code **)(*piVar37 + 0x28))(&local_130);
    iVar32 = 0;
    iVar44 = iVar43 * 4 + uVar46 * 4;
    iVar15 = -1000;
    iVar6 = iVar40;
    do {
      uVar29 = createShip(this,10,0,0x2c,(Waypoint *)0x0,true,false);
      *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar44 + iVar32 * 4) = uVar29;
      Player::setAlwaysEnemy
                (*(Player **)
                  (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar44 + iVar32 * 4) + 4),true);
      KIPlayer::setVisible
                (*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar44 + iVar32 * 4),false);
      KIPlayer::setActive(SUB41(*(undefined4 *)
                                 (*(int *)(*(int *)(this + 0xf8) + 4) + iVar44 + iVar32 * 4),0));
      local_154 = 0;
      local_150 = 0x3f800000;
      local_14c = 0;
      AEGeometry::setDirection
                (*(AEGeometry **)
                  (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar44 + iVar32 * 4) + 8),
                 (Vector *)&local_68,(Vector *)&local_154);
      PlayerFighter::setAIDisabled
                (*(PlayerFighter **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar44 + iVar32 * 4),true
                );
      PlayerFighter::setCloakingPossible
                (*(PlayerFighter **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar44 + iVar32 * 4),
                 false);
      pKVar35 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar44 + iVar32 * 4);
      pRVar7 = (Route *)Route::getExactClone(*(Route **)(this + 0x110));
      KIPlayer::setRoute(pKVar35,pRVar7);
      iVar41 = iVar15;
      local_14c = 0x459c4000;
      if (1 < iVar32) {
        if (iVar32 < 5) {
          iVar41 = (iVar6 - iVar40) * 3000 + -9000;
          local_14c = 0x45dac000;
        }
        else if (iVar32 < 9) {
          iVar41 = (iVar6 - iVar40) * 3000 + -20000;
          local_14c = 0x460ca000;
        }
        else {
          iVar41 = 0;
          local_14c = 0x462be000;
        }
      }
      local_154 = VectorSignedToFloat(iVar41,(byte)(in_fpscr >> 0x16) & 3);
      local_150 = 0;
      AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x18c),(Vector *)&local_154);
      iVar41 = AbyssEngine::AERandom::nextInt(Globals::rnd,200);
      fVar48 = (float)VectorSignedToFloat(iVar41 + -100,(byte)(in_fpscr >> 0x16) & 3);
      *(float *)(this + 0x18c) = *(float *)(this + 0x18c) + fVar48;
      iVar41 = AbyssEngine::AERandom::nextInt(Globals::rnd,200);
      fVar48 = (float)VectorSignedToFloat(iVar41 + -100,(byte)(in_fpscr >> 0x16) & 3);
      *(float *)(this + 400) = *(float *)(this + 400) + fVar48;
      iVar41 = AbyssEngine::AERandom::nextInt(Globals::rnd,200);
      fVar48 = (float)VectorSignedToFloat(iVar41 + -100,(byte)(in_fpscr >> 0x16) & 3);
      *(float *)(this + 0x194) = *(float *)(this + 0x194) + fVar48;
      piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar44 + iVar32 * 4);
      pcVar45 = *(code **)(*piVar37 + 0x44);
      AbyssEngine::AEMath::operator+
                ((AEMath *)&local_154,(Vector *)&local_130,(Vector *)(this + 0x18c));
      (*pcVar45)(piVar37,(AEMath *)&local_154);
      iVar32 = iVar32 + 1;
      iVar6 = iVar6 + 1;
      iVar15 = iVar15 + 2000;
    } while (iVar40 + iVar32 < iVar30);
    uVar29 = createShip(this,2,0,0x31,(Waypoint *)0x0,true,false);
    *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar30 * 4) = uVar29;
    piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar30 * 4);
    (**(code **)(*piVar37 + 0x44))(piVar37,&local_130);
    Player::setAlwaysEnemy
              (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar30 * 4) + 4),true);
    PlayerFighter::setAIDisabled
              (*(PlayerFighter **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar30 * 4),true);
    local_154 = 0;
    local_150 = 0x3f800000;
    local_14c = 0;
    AEGeometry::setDirection
              (*(AEGeometry **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar30 * 4) + 8),
               (Vector *)&local_68,(Vector *)&local_154);
    KIPlayer::setActive(SUB41(*(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar30 * 4),0));
    KIPlayer::setVisible(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar30 * 4),false);
    piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar30 * 4);
    (**(code **)(*piVar37 + 0x1c))(piVar37,0x40a00000);
    iVar6 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar30 * 4);
    pSVar24 = (String *)GameText::getText(Globals::gameText,0x664);
    AbyssEngine::String::operator=((String *)(iVar6 + 0x18),pSVar24);
    iVar6 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar30 * 4);
    pvVar36 = *(void **)(iVar6 + 0x4c);
    if (pvVar36 != (void *)0x0) {
      if (*(void **)((int)pvVar36 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar36 + 4));
      }
      operator_delete(pvVar36);
      iVar6 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar30 * 4);
    }
    *(undefined4 *)(iVar6 + 0x4c) = 0;
    iVar43 = uVar46 + iVar43 * 2;
    do {
      uVar29 = createShip(this,3,0,0x14,(Waypoint *)0x0,true,false);
      *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4 + 4) = uVar29;
      piVar37 = *(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4 + 4);
      (**(code **)(*piVar37 + 0x48))(piVar37,0x47435000,0x47435000,0x47435000);
      PlayerFighter::setAIDisabled
                (*(PlayerFighter **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4 + 4),true);
      KIPlayer::setActive(SUB41(*(undefined4 *)
                                 (*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4 + 4),0));
      KIPlayer::setVisible
                (*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4 + 4),false);
      iVar6 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar43 * 4 + 4);
      pSVar24 = (String *)GameText::getText(Globals::gameText,0x657);
      AbyssEngine::String::operator=((String *)(iVar6 + 0x18),pSVar24);
      iVar6 = iVar43 + 2;
      iVar43 = iVar43 + 1;
    } while (iVar6 < iVar12);
    PlayerEgo::setPosition(extraout_s0_00,extraout_s1_01,extraout_s2_00);
    pAVar21 = *(AEGeometry **)(*(int *)(this + 0xf0) + 8);
    local_178 = 0xbf800000;
    local_174 = 0xbe4ccccd;
    local_170 = 0xbf000000;
    AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_154,(Vector *)&local_178);
    local_184 = 0;
    local_180 = 0x3f800000;
    local_17c = 0.0;
    AEGeometry::setDirection(pAVar21,(Vector *)&local_154,(Vector *)&local_184);
    break;
  case 0x9e:
    pAVar8 = operator_new(0xc);
    puVar9 = operator_new__(4);
    *(undefined4 **)(pAVar8 + 4) = puVar9;
    *puVar9 = 0;
    *(undefined4 *)(pAVar8 + 8) = 1;
    *(undefined4 *)pAVar8 = 0;
    *(Array **)(this + 0xf8) = pAVar8;
    ArraySetLength<KIPlayer*>(1,pAVar8);
    uVar29 = createShip(this,10,0,0x31,(Waypoint *)0x0,true,false);
    **(undefined4 **)(*(int *)(this + 0xf8) + 4) = uVar29;
    (**(code **)(*(int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4) + 0x48))
              ((int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),0x460ca000,0,0xc64b2000);
    pAVar21 = *(AEGeometry **)(**(int **)(*(int *)(this + 0xf8) + 4) + 8);
    local_e8 = (char *)0xbf800000;
    fStack_e4 = 0.0;
    local_e0 = (char *)0x40400000;
    AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_a8,(Vector *)&local_e8);
    local_110 = 0x3f80000000000000;
    local_108 = (char *)0x0;
    AEGeometry::setDirection(pAVar21,(Vector *)&local_a8,(Vector *)&local_110);
    Player::setAlwaysEnemy(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),true);
    (**(code **)(*(int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4) + 0x1c))
              ((int *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),0x40a9999a);
    pPVar39 = *(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4);
    iVar43 = Player::getMaxEmpPoints(pPVar39);
    Player::setMaxEmpPoints(pPVar39,iVar43 * 3);
    PlayerFighter::setCloakingPossible
              ((PlayerFighter *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),false);
    iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
    pSVar24 = (String *)GameText::getText(Globals::gameText,0x664);
    AbyssEngine::String::operator=((String *)(iVar43 + 0x18),pSVar24);
    PlayerFighter::setAIDisabled((PlayerFighter *)**(undefined4 **)(*(int *)(this + 0xf8) + 4),true)
    ;
    iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
    pvVar36 = *(void **)(iVar43 + 0x4c);
    if (pvVar36 != (void *)0x0) {
      if (*(void **)((int)pvVar36 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar36 + 4));
      }
      operator_delete(pvVar36);
      iVar43 = **(int **)(*(int *)(this + 0xf8) + 4);
    }
    *(undefined4 *)(iVar43 + 0x4c) = 0;
    iVar43 = 3;
    do {
      piVar37 = (int *)createStaticObject(this,(Waypoint *)0x0,0x49c2,true);
      Player::setRadius((Player *)piVar37[1],800);
      Player::setAlwaysEnemy((Player *)piVar37[1],true);
      Player::setAlwaysFriend((Player *)piVar37[1],false);
      Player::setMaxHitpoints((Player *)piVar37[1],100);
      (**(code **)(*piVar37 + 0x48))(piVar37,0x47435000,0x47435000,0x47435000);
      KIPlayer::setActive(SUB41(piVar37,0));
      piVar34 = *(int **)(this + 0xf8);
      piVar34[2] = *piVar34 + 1;
      pvVar36 = realloc((void *)piVar34[1],(*piVar34 + 1) * 4);
      piVar34[1] = (int)pvVar36;
      iVar43 = iVar43 + -1;
      *(int **)((int)pvVar36 + *piVar34 * 4) = piVar37;
      *piVar34 = piVar34[2];
    } while (iVar43 != 0);
    pOVar13 = operator_new(0x1c);
    Objective::Objective(pOVar13,0x16,0,this);
LAB_000c999e:
    *(Objective **)(this + 0x28) = pOVar13;
  }
switchD_000c340a_caseD_25:
  iVar43 = Status::getCurrentCampaignMission(Globals::status);
  uVar29 = createRadioMessages(this,iVar43);
  *(undefined4 *)(this + 0x114) = uVar29;
  if (__stack_chk_guard == local_5c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== Level::createStaticObjects  @0x000cadb0  (716 bytes)
/* Level::createStaticObjects() */

void __thiscall Level::createStaticObjects(Level *this)

{
  int iVar1;
  Station *pSVar2;
  PlayerFixedObject *pPVar3;
  String *pSVar4;
  void *pvVar5;
  undefined4 *puVar6;
  int *piVar7;
  AEGeometry *this_00;
  String aSStack_40 [8];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 uStack_30;
  Vector aVStack_2c [12];
  int local_20;
  
  local_20 = __stack_chk_guard;
  iVar1 = Status::inAlienOrbit(Globals::status);
  if (iVar1 == 0) {
    pSVar2 = (Station *)Status::getStation(Globals::status);
    iVar1 = Station::getIndex(pSVar2);
    if ((iVar1 == 0x70) &&
       (iVar1 = Status::getCurrentCampaignMission(Globals::status), 0x7f < iVar1)) {
      iVar1 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar1 < 0x83) {
        iVar1 = 0x493e;
      }
      else {
        iVar1 = Status::getCurrentCampaignMission(Globals::status);
        if (iVar1 < 0x87) {
          iVar1 = 0x4941;
        }
        else {
          iVar1 = Status::getCurrentCampaignMission(Globals::status);
          if (iVar1 < 0x8a) {
            iVar1 = 0x4944;
          }
          else {
            iVar1 = Status::getCurrentCampaignMission(Globals::status);
            if (iVar1 < 0x8e) {
              iVar1 = 0x4947;
            }
            else {
              iVar1 = Status::getCurrentCampaignMission(Globals::status);
              if (0x91 < iVar1) goto LAB_000caf50;
              iVar1 = 0x494a;
            }
          }
        }
      }
      pPVar3 = (PlayerFixedObject *)createStaticObject(this,(Waypoint *)0x0,iVar1,false);
      (**(code **)(*(int *)pPVar3 + 0x48))(pPVar3,0xc7435000,0,0x47435000);
      PlayerFixedObject::setMoving(pPVar3,false);
      pPVar3[0x6c] = (PlayerFixedObject)0x0;
      this_00 = *(AEGeometry **)(pPVar3 + 8);
      StarSystem::getLightDirection();
      local_38 = 0;
      local_34 = 0x3f800000;
      uStack_30 = 0;
      AEGeometry::setDirection(this_00,aVStack_2c,(Vector *)&local_38);
      pSVar4 = (String *)GameText::getText(Globals::gameText,0xc87);
      AbyssEngine::String::operator=((String *)(pPVar3 + 0x18),pSVar4);
      Player::setAlwaysFriend(*(Player **)(pPVar3 + 4),true);
      piVar7 = *(int **)(this + 0xf8);
      if (piVar7 == (int *)0x0) {
        piVar7 = operator_new(0xc);
        puVar6 = operator_new__(4);
        piVar7[1] = (int)puVar6;
        *puVar6 = 0;
        *piVar7 = 0;
        *(int **)(this + 0xf8) = piVar7;
        piVar7[2] = 1;
        pvVar5 = realloc(puVar6,4);
        piVar7[1] = (int)pvVar5;
        *(PlayerFixedObject **)((int)pvVar5 + *piVar7 * 4) = pPVar3;
        *piVar7 = piVar7[2];
      }
      else {
        piVar7[2] = *piVar7 + 1;
        pvVar5 = realloc((void *)piVar7[1],(*piVar7 + 1) * 4);
        piVar7[1] = (int)pvVar5;
        *(PlayerFixedObject **)((int)pvVar5 + *piVar7 * 4) = pPVar3;
        *piVar7 = piVar7[2];
      }
      pvVar5 = *(void **)(pPVar3 + 0x4c);
      if (pvVar5 != (void *)0x0) {
        if (*(void **)((int)pvVar5 + 4) != (void *)0x0) {
          operator_delete__(*(void **)((int)pvVar5 + 4));
        }
        operator_delete(pvVar5);
      }
      *(undefined4 *)(pPVar3 + 0x4c) = 0;
    }
  }
LAB_000caf50:
  iVar1 = Status::getCurrentCampaignMission(Globals::status);
  if (((0x54 < iVar1) && (iVar1 = Status::getCurrentCampaignMission(Globals::status), iVar1 != 0x87)
      ) && (iVar1 = Status::inAlienOrbit(Globals::status), iVar1 == 0)) {
    pSVar2 = (Station *)Status::getStation(Globals::status);
    iVar1 = Station::getIndex(pSVar2);
    if (iVar1 == 0x67) {
      pPVar3 = (PlayerFixedObject *)createStaticObject(this,(Waypoint *)0x0,0x4a88,false);
      (**(code **)(*(int *)pPVar3 + 0x48))(pPVar3,0,0,0);
      PlayerFixedObject::setMoving(pPVar3,false);
      pPVar3[0x6c] = (PlayerFixedObject)0x1;
      pSVar4 = (String *)GameText::getText(Globals::gameText,0xc8a);
      AbyssEngine::String::String(aSStack_40,pSVar4,false);
      PlayerFixedObject::setName(pPVar3,aSStack_40);
      AbyssEngine::String::~String(aSStack_40);
      PlayerFixedObject::setDockingType(pPVar3,1);
      pvVar5 = *(void **)(pPVar3 + 0x4c);
      if (pvVar5 != (void *)0x0) {
        if (*(void **)((int)pvVar5 + 4) != (void *)0x0) {
          operator_delete__(*(void **)((int)pvVar5 + 4));
        }
        operator_delete(pvVar5);
      }
      *(undefined4 *)(pPVar3 + 0x4c) = 0;
      Player::setAlwaysFriend(*(Player **)(pPVar3 + 4),true);
      piVar7 = *(int **)(this + 0xf8);
      if (piVar7 == (int *)0x0) {
        piVar7 = operator_new(0xc);
        puVar6 = operator_new__(4);
        piVar7[1] = (int)puVar6;
        *puVar6 = 0;
        *piVar7 = 0;
        *(int **)(this + 0xf8) = piVar7;
        piVar7[2] = 1;
        pvVar5 = realloc(puVar6,4);
        piVar7[1] = (int)pvVar5;
        *(PlayerFixedObject **)((int)pvVar5 + *piVar7 * 4) = pPVar3;
        *piVar7 = piVar7[2];
      }
      else {
        piVar7[2] = *piVar7 + 1;
        pvVar5 = realloc((void *)piVar7[1],(*piVar7 + 1) * 4);
        piVar7[1] = (int)pvVar5;
        *(PlayerFixedObject **)((int)pvVar5 + *piVar7 * 4) = pPVar3;
        *piVar7 = piVar7[2];
      }
    }
  }
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Level::createSentryGuns  @0x000cb0d8  (276 bytes)
/* Level::createSentryGuns() */

void __thiscall Level::createSentryGuns(Level *this)

{
  Ship *this_00;
  int iVar1;
  Array *pAVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  void *pvVar6;
  int *piVar7;
  uint uVar8;
  int *piVar9;
  
  this_00 = (Ship *)Status::getShip(Globals::status);
  iVar1 = Ship::getFirstEquipmentOfSort(this_00,0x27);
  if (iVar1 != 0) {
    pAVar2 = operator_new(0xc);
    puVar3 = operator_new__(4);
    *(undefined4 **)(pAVar2 + 4) = puVar3;
    *(undefined4 *)(pAVar2 + 8) = 1;
    *puVar3 = 0;
    *(undefined4 *)pAVar2 = 0;
    *(Array **)(this + 0xb0) = pAVar2;
    ArraySetLength<KIPlayer*>(9,pAVar2);
    if (*(int *)(this + 0xf8) == 0) {
      puVar3 = operator_new(0xc);
      puVar4 = operator_new__(4);
      puVar3[1] = puVar4;
      puVar3[2] = 1;
      *puVar4 = 0;
      *puVar3 = 0;
      *(undefined4 **)(this + 0xf8) = puVar3;
    }
    if (**(int **)(this + 0xb0) != 0) {
      uVar8 = 0;
      do {
        uVar5 = createStaticObject(this,(Waypoint *)0x0,(int)uVar8 / 3 + 0x49c0,true);
        *(undefined4 *)(*(int *)(*(int *)(this + 0xb0) + 4) + uVar8 * 4) = uVar5;
        piVar9 = *(int **)(*(int *)(*(int *)(this + 0xb0) + 4) + uVar8 * 4);
        Player::setRadius((Player *)piVar9[1],800);
        Player::setAlwaysFriend((Player *)piVar9[1],true);
        Player::setMaxHitpoints((Player *)piVar9[1],100);
        (**(code **)(*piVar9 + 0x48))(piVar9,0x47435000,0x47435000,0x47435000);
        KIPlayer::setActive(SUB41(piVar9,0));
        piVar7 = *(int **)(this + 0xf8);
        piVar7[2] = *piVar7 + 1;
        pvVar6 = realloc((void *)piVar7[1],(*piVar7 + 1) * 4);
        piVar7[1] = (int)pvVar6;
        uVar8 = uVar8 + 1;
        *(int **)((int)pvVar6 + *piVar7 * 4) = piVar9;
        *piVar7 = piVar7[2];
      } while (uVar8 < **(uint **)(this + 0xb0));
    }
  }
  return;
}

// ===== Level::createFighterTurrets  @0x000cb200  (304 bytes)
/* Level::createFighterTurrets() */

void __thiscall Level::createFighterTurrets(Level *this)

{
  uint *puVar1;
  PlayerTurret *this_00;
  int iVar2;
  void *pvVar3;
  Player *pPVar4;
  int *piVar5;
  KIPlayer *pKVar6;
  uint uVar7;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  puVar1 = *(uint **)(this + 0xf8);
  if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
    uVar7 = 0;
    do {
      pKVar6 = *(KIPlayer **)(puVar1[1] + uVar7 * 4);
      if (pKVar6 != (KIPlayer *)0x0) {
        if (*(int *)(pKVar6 + 0x78) == 0x2d) {
          this_00 = (PlayerTurret *)createStaticObject(this,(Waypoint *)0x0,0x1a74,true);
          Player::setVulnerable(*(Player **)(this_00 + 4),false);
          pPVar4 = *(Player **)(this_00 + 4);
          iVar2 = Player::getMaxHitpoints(*(Player **)(pKVar6 + 4));
          Player::setMaxHitpoints(pPVar4,iVar2);
          local_34 = 0;
          local_30 = 0x432c4000;
          local_2c = 0xc3e6599a;
          PlayerTurret::setHost(this_00,pKVar6,(Vector *)&local_34);
          *(PlayerTurret **)(pKVar6 + 0x10) = this_00;
          this_00[0x70] = (PlayerTurret)0x1;
          *(undefined4 *)(this_00 + 0x24) = 8;
        }
        else {
          if (*(int *)(pKVar6 + 0x78) != 0x33) goto LAB_000cb30a;
          this_00 = (PlayerTurret *)createStaticObject(this,(Waypoint *)0x0,0x1a74,true);
          Player::setVulnerable(*(Player **)(this_00 + 4),false);
          pPVar4 = *(Player **)(this_00 + 4);
          iVar2 = Player::getMaxHitpoints(*(Player **)(pKVar6 + 4));
          Player::setMaxHitpoints(pPVar4,iVar2);
          local_34 = 0;
          local_30 = 0x43eb0000;
          local_2c = 0xc2a60000;
          PlayerTurret::setHost(this_00,pKVar6,(Vector *)&local_34);
          *(PlayerTurret **)(pKVar6 + 0x10) = this_00;
          this_00[0x70] = (PlayerTurret)0x1;
          *(undefined4 *)(this_00 + 0x24) = 0;
        }
        piVar5 = *(int **)(this + 0xf8);
        piVar5[2] = *piVar5 + 1;
        pvVar3 = realloc((void *)piVar5[1],(*piVar5 + 1) * 4);
        piVar5[1] = (int)pvVar3;
        *(PlayerTurret **)((int)pvVar3 + *piVar5 * 4) = this_00;
        *piVar5 = piVar5[2];
      }
LAB_000cb30a:
      puVar1 = *(uint **)(this + 0xf8);
      uVar7 = uVar7 + 1;
    } while (uVar7 < *puVar1);
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Level::createWingmen  @0x000cb338  (692 bytes)
/* Level::createWingmen() */

void __thiscall Level::createWingmen(Level *this)

{
  Status *this_00;
  AERandom *pAVar1;
  int iVar2;
  Array *pAVar3;
  undefined4 *puVar4;
  uint *puVar5;
  uint uVar6;
  undefined4 uVar7;
  float *pfVar8;
  int *piVar9;
  Mission *this_01;
  void *pvVar10;
  undefined4 extraout_r1;
  AEGeometry *this_02;
  int iVar11;
  uint uVar12;
  float fVar13;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  AEMath aAStack_58 [12];
  Vector aVStack_4c [12];
  Vector aVStack_40 [4];
  float local_3c;
  int local_34;
  
  local_34 = __stack_chk_guard;
  iVar2 = Status::inSupernovaSystem(Globals::status);
  if ((((iVar2 == 0) && (iVar2 = Status::getCurrentCampaignMission(Globals::status), iVar2 != 0x9e))
      && (iVar2 = Status::getWingmen(Globals::status), iVar2 != 0)) && (*(int *)(this + 0xf0) != 0))
  {
    pAVar3 = operator_new(0xc);
    puVar4 = operator_new__(4);
    *(undefined4 **)(pAVar3 + 4) = puVar4;
    *(undefined4 *)(pAVar3 + 8) = 1;
    *puVar4 = 0;
    *(undefined4 *)pAVar3 = 0;
    puVar5 = (uint *)Status::getWingmen(Globals::status);
    ArraySetLength<KIPlayer*>(*puVar5,pAVar3);
    uVar6 = 0;
    if (*(int *)pAVar3 != 0) {
      uVar12 = 0;
      do {
        pAVar1 = Globals::rnd;
        Status::getWingmen(Globals::status);
        AbyssEngine::AERandom::setSeed(CONCAT44(extraout_r1,pAVar1));
        iVar2 = Globals::getRandomEnemyFighter(Globals::globals,*(int *)(Globals::status + 0x2c));
        uVar7 = createShip(this,5,0,iVar2,(Waypoint *)0x0,true,false);
        *(undefined4 *)(*(int *)(pAVar3 + 4) + uVar12 * 4) = uVar7;
        AEGeometry::getPosition();
        AEGeometry::getRightVector();
        pfVar8 = (float *)&DAT_000cb61c;
        if (uVar12 == 1) {
          pfVar8 = (float *)&DAT_000cb620;
        }
        fVar13 = *pfVar8;
        if (uVar12 == 0) {
          fVar13 = -1000.0;
        }
        AbyssEngine::AEMath::operator*(aAStack_58,aVStack_4c,fVar13);
        AbyssEngine::AEMath::Vector::operator+=(aVStack_40,(Vector *)aAStack_58);
        fVar13 = (float)AEGeometry::getDirection();
        AbyssEngine::AEMath::operator*(aAStack_58,(Vector *)&local_64,fVar13);
        AbyssEngine::AEMath::Vector::operator-=(aVStack_40,(Vector *)aAStack_58);
        pfVar8 = (float *)&DAT_000cb628;
        if (uVar12 == 2) {
          pfVar8 = (float *)&DAT_000cb62c;
        }
        local_3c = *pfVar8 + local_3c;
        piVar9 = *(int **)(*(int *)(pAVar3 + 4) + uVar12 * 4);
        (**(code **)(*piVar9 + 0x44))(piVar9,aVStack_40);
        this_02 = *(AEGeometry **)(*(int *)(*(int *)(pAVar3 + 4) + uVar12 * 4) + 8);
        AEGeometry::getDirection();
        local_64 = 0;
        local_60 = 0x3f800000;
        local_5c = 0;
        AEGeometry::setDirection(this_02,(Vector *)aAStack_58,(Vector *)&local_64);
        KIPlayer::setWingman(*(KIPlayer **)(*(int *)(pAVar3 + 4) + uVar12 * 4),true,uVar12);
        Player::setAlwaysFriend(*(Player **)(*(int *)(*(int *)(pAVar3 + 4) + uVar12 * 4) + 4),true);
        Player::setHitpoints(*(Player **)(*(int *)(*(int *)(pAVar3 + 4) + uVar12 * 4) + 4),600);
        iVar11 = *(int *)(*(int *)(pAVar3 + 4) + uVar12 * 4);
        iVar2 = Status::getWingmen(Globals::status);
        AbyssEngine::String::operator=
                  ((String *)(iVar11 + 0x18),*(String **)(*(int *)(iVar2 + 4) + uVar12 * 4));
        this_00 = Globals::status;
        *(undefined4 *)(*(int *)(*(int *)(pAVar3 + 4) + uVar12 * 4) + 0x24) =
             *(undefined4 *)(Globals::status + 0x2c);
        this_01 = (Mission *)Status::getMission(this_00);
        iVar2 = Mission::getType(this_01);
        if (iVar2 == 0xc) {
          *(undefined1 *)(*(int *)(*(int *)(pAVar3 + 4) + uVar12 * 4) + 0x21) = 0;
        }
        uVar6 = *(uint *)pAVar3;
        uVar12 = uVar12 + 1;
      } while (uVar12 < uVar6);
    }
    piVar9 = *(int **)(this + 0xf8);
    if (piVar9 == (int *)0x0) {
      *(Array **)(this + 0xf8) = pAVar3;
    }
    else if (uVar6 != 0) {
      uVar6 = 0;
      while( true ) {
        uVar7 = *(undefined4 *)(*(int *)(pAVar3 + 4) + uVar6 * 4);
        piVar9[2] = *piVar9 + 1;
        pvVar10 = realloc((void *)piVar9[1],(*piVar9 + 1) * 4);
        piVar9[1] = (int)pvVar10;
        uVar6 = uVar6 + 1;
        *(undefined4 *)((int)pvVar10 + *piVar9 * 4) = uVar7;
        *piVar9 = piVar9[2];
        if (*(uint *)pAVar3 <= uVar6) break;
        piVar9 = *(int **)(this + 0xf8);
      }
    }
    AbyssEngine::AERandom::reset(Globals::rnd);
  }
  if (__stack_chk_guard == local_34) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== Level::assignGuns  @0x000cb638  (3116 bytes)
/* Level::assignGuns() */

void __thiscall Level::assignGuns(Level *this)

{
  byte bVar1;
  int iVar2;
  Wanted *this_00;
  KIPlayer *pKVar3;
  int iVar4;
  int iVar5;
  Array *pAVar6;
  undefined4 *puVar7;
  Mission *pMVar8;
  int iVar9;
  int iVar10;
  Gun *pGVar11;
  int iVar12;
  PlayerTurret *this_01;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  RocketGun *pRVar16;
  ObjectGun *pOVar17;
  undefined4 uVar18;
  uint *puVar19;
  int *piVar20;
  void *pvVar21;
  uint uVar22;
  uint uVar23;
  Player *this_02;
  uint in_fpscr;
  uint uVar24;
  float fVar25;
  float fVar26;
  int iVar27;
  double dVar28;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 local_70;
  int local_6c;
  
  local_6c = __stack_chk_guard;
  if (*(Array **)(this + 0xe8) != (Array *)0x0) {
    ArrayReleaseClasses<AbstractGun*>(*(Array **)(this + 0xe8));
    pvVar21 = *(void **)(this + 0xe8);
    if (pvVar21 != (void *)0x0) {
      if (*(void **)((int)pvVar21 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar21 + 4));
      }
      operator_delete(pvVar21);
    }
    *(undefined4 *)(this + 0xe8) = 0;
  }
  *(undefined4 *)(this + 0xe8) = 0;
  iVar2 = Status::getLevel(Globals::status);
  fVar26 = 20.0;
  fVar25 = (float)VectorSignedToFloat(iVar2 + -2,(byte)(in_fpscr >> 0x16) & 3);
  fVar25 = fVar25 * 0.9;
  uVar22 = in_fpscr & 0xfffffff | (uint)(fVar25 < 20.0) << 0x1f | (uint)(fVar25 == 20.0) << 0x1e;
  uVar24 = uVar22 | (uint)NAN(fVar25) << 0x1c;
  bVar1 = (byte)(uVar22 >> 0x18);
  if ((bool)(bVar1 >> 6 & 1) || bVar1 >> 7 != ((byte)(uVar24 >> 0x1c) & 1)) {
    iVar2 = Status::getLevel(Globals::status);
    fVar25 = (float)VectorSignedToFloat(iVar2 + -2,(byte)(uVar24 >> 0x16) & 3);
    uVar24 = uVar24 & 0xfffffff;
    if (fVar25 * 0.9 < 0.0) {
      fVar26 = 0.0;
      goto LAB_000cb722;
    }
  }
  iVar2 = Status::getLevel(Globals::status);
  fVar25 = (float)VectorSignedToFloat(iVar2 + -2,(byte)(uVar24 >> 0x16) & 3);
  fVar25 = fVar25 * 0.9;
  uVar22 = uVar24 & 0xfffffff | (uint)(fVar25 < 20.0) << 0x1f | (uint)(fVar25 == 20.0) << 0x1e;
  uVar24 = uVar22 | (uint)NAN(fVar25) << 0x1c;
  bVar1 = (byte)(uVar22 >> 0x18);
  if ((bool)(bVar1 >> 6 & 1) || bVar1 >> 7 != ((byte)(uVar24 >> 0x1c) & 1)) {
    iVar2 = Status::getLevel(Globals::status);
    fVar25 = (float)VectorSignedToFloat(iVar2 + -2,(byte)(uVar24 >> 0x16) & 3);
    fVar26 = (float)VectorSignedToFloat((int)(fVar25 * 0.9),(byte)(uVar24 >> 0x16) & 3);
  }
LAB_000cb722:
  fVar25 = (float)Globals::options._44_4_ + -0.5;
  iVar2 = Status::getCurrentCampaignMission(Globals::status);
  iVar27 = (int)(fVar26 + fVar25 * fVar26);
  this_00 = (Wanted *)Status::getWantedInCurrentOrbit(Globals::status);
  puVar19 = *(uint **)(this + 0xf8);
  if (0x15 < iVar27) {
    iVar27 = 0x16;
  }
  if (puVar19 != (uint *)0x0) {
    uVar22 = 0;
    if (*puVar19 != 0) {
      uVar23 = 0;
      do {
        pKVar3 = *(KIPlayer **)(puVar19[1] + uVar23 * 4);
        if ((pKVar3 != (KIPlayer *)0x0) && (pKVar3[0x21] != (KIPlayer)0x0)) {
          iVar4 = KIPlayer::isWingMan(pKVar3);
          iVar5 = 1;
          if (iVar4 != 0) {
            iVar5 = 2;
          }
          puVar19 = *(uint **)(this + 0xf8);
          uVar22 = uVar22 + iVar5;
        }
        uVar23 = uVar23 + 1;
      } while (uVar23 < *puVar19);
    }
    pAVar6 = operator_new(0xc);
    puVar7 = operator_new__(4);
    *(undefined4 **)(pAVar6 + 4) = puVar7;
    *(undefined4 *)(pAVar6 + 8) = 1;
    *puVar7 = 0;
    *(undefined4 *)pAVar6 = 0;
    *(Array **)(this + 0xe8) = pAVar6;
    ArraySetLength<AbstractGun*>(uVar22,pAVar6);
    puVar19 = *(uint **)(this + 0xf8);
    if (*puVar19 != 0) {
      iVar4 = iVar27 + 2;
      if (iVar27 == 0) {
        iVar4 = 3;
      }
      iVar27 = iVar4;
      if (iVar2 == 4) {
        iVar27 = 1;
      }
      iVar5 = 0;
      uVar22 = 0;
      do {
        pKVar3 = *(KIPlayer **)(puVar19[1] + uVar22 * 4);
        if (pKVar3 != (KIPlayer *)0x0) {
          if (pKVar3[0x21] != (KIPlayer)0x0) {
            if (*(int *)(this + 0xc0) == 2) {
              Player::setPlayShootSound(*(Player **)(pKVar3 + 4),false,2);
            }
            pMVar8 = (Mission *)Status::getMission(Globals::status);
            iVar9 = Mission::getType(pMVar8);
            if ((iVar9 == 6) &&
               (iVar9 = Player::isAlwaysFriend
                                  (*(Player **)
                                    (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar22 * 4) + 4)
                                  ), iVar9 != 1)) {
LAB_000cb998:
              iVar9 = Status::getLevel(Globals::status);
              uVar18 = 0x41e00000;
              iVar9 = iVar9 + iVar4;
            }
            else {
              pMVar8 = (Mission *)Status::getMission(Globals::status);
              iVar10 = Mission::getType(pMVar8);
              uVar18 = 0x41800000;
              iVar9 = iVar27;
              if (iVar10 == 0xc) {
                iVar10 = Player::isAlwaysFriend
                                   (*(Player **)
                                     (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar22 * 4) + 4
                                     ));
                uVar18 = 0x41800000;
                if (iVar10 == 1) goto LAB_000cb998;
              }
            }
            iVar10 = KIPlayer::isWingMan(*(KIPlayer **)
                                          (*(int *)(*(int *)(this + 0xf8) + 4) + uVar22 * 4));
            if (((iVar10 == 0) &&
                (iVar10 = Player::isAlwaysFriend
                                    (*(Player **)
                                      (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar22 * 4) +
                                      4)), iVar10 == 0)) &&
               (iVar10 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar22 * 4),
               *(int *)(iVar10 + 0x24) == 9)) {
              fVar25 = (float)VectorSignedToFloat(iVar9,(byte)(uVar24 >> 0x16) & 3);
              if (iVar2 != 0x10) {
                iVar9 = (int)(fVar25 * 0.8);
                goto LAB_000cba1c;
              }
              iVar9 = (int)(fVar25 + fVar25);
            }
            else {
LAB_000cba1c:
              iVar10 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar22 * 4);
              if ((0x8fU >> (iVar2 - 0x31U & 0xff) & (uint)(iVar2 - 0x31U < 8)) != 0) {
                iVar9 = 5;
              }
            }
            if ((iVar2 == 0x50) && (*(char *)(iVar10 + 0x3a) != '\0')) {
              fVar25 = (float)VectorSignedToFloat(iVar9,(byte)(uVar24 >> 0x16) & 3);
              iVar9 = (int)(fVar25 * 1.7);
            }
            iVar10 = Status::getCurrentCampaignMission(Globals::status);
            if ((iVar10 == 0x46) &&
               (iVar10 = KIPlayer::isWingMan(*(KIPlayer **)
                                              (*(int *)(*(int *)(this + 0xf8) + 4) + uVar22 * 4)),
               iVar10 == 0)) {
              fVar25 = (float)VectorSignedToFloat(iVar9,(byte)(uVar24 >> 0x16) & 3);
              iVar9 = (int)(fVar25 * 2.5);
            }
            iVar10 = Status::getMission(Globals::status);
            if (iVar10 != 0) {
              pMVar8 = (Mission *)Status::getMission(Globals::status);
              iVar10 = Mission::getType(pMVar8);
              if (iVar10 == 0xb7) {
                iVar9 = 1;
              }
            }
            pGVar11 = operator_new(0x114);
            iVar10 = Status::gameWon(Globals::status);
            if (iVar10 == 0) {
              iVar10 = Status::getCurrentCampaignMission(Globals::status);
            }
            else {
              iVar10 = 0x2d;
            }
            Gun::Gun(pGVar11,0,iVar9,4,0xffffffff,3000,iVar10 * -2 + 600,uVar18,0,0,0,0,0,0);
            Gun::setFriendGun(pGVar11,true);
            Gun::setLevel(pGVar11,this);
            Gun::setIndex(pGVar11,0);
            *(undefined4 *)(pGVar11 + 0x5c) = 0;
            switch(*(undefined4 *)
                    (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar22 * 4) + 0x24)) {
            case 0:
              *(undefined4 *)(pGVar11 + 0x5c) = 0;
              Gun::setIndex(pGVar11,0);
              iVar10 = 0x1a62;
              break;
            case 1:
              Gun::setIndex(pGVar11,3);
              iVar10 = 0x1a68;
              break;
            case 2:
              *(undefined4 *)(pGVar11 + 0x5c) = 0;
              Gun::setIndex(pGVar11,7);
              iVar10 = 0x1a6c;
              break;
            case 3:
              Gun::setIndex(pGVar11,0x19);
              iVar10 = 0x1a92;
              break;
            default:
              *(undefined4 *)(pGVar11 + 0x5c) = 1;
              Gun::setIndex(pGVar11,0x13);
              iVar10 = 0x1a8b;
              break;
            case 9:
              Gun::setIndex(pGVar11,5);
              iVar10 = 0x1a6a;
              break;
            case 10:
              Gun::setIndex(pGVar11,0xe5);
              iVar10 = 0x4a93;
              fVar25 = (float)VectorSignedToFloat(*(undefined4 *)(pGVar11 + 0x60),
                                                  (byte)(uVar24 >> 0x16) & 3);
              *(int *)(pGVar11 + 0x60) = (int)(fVar25 * 0.7);
            }
            iVar12 = Status::getCurrentCampaignMission(Globals::status);
            this_01 = *(PlayerTurret **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar22 * 4);
            if (this_01[0x3a] != (PlayerTurret)0x0) {
              iVar10 = PlayerTurret::getHost(this_01);
              if ((iVar10 == 0) ||
                 (*(int *)(iVar10 + 0x78) != 0x2d && *(int *)(iVar10 + 0x78) != 0x33)) {
                pKVar3 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar22 * 4);
                if (pKVar3[0x3b] == (KIPlayer)0x0) {
                  iVar10 = *(int *)(pKVar3 + 0x24);
                  *(undefined4 *)(pGVar11 + 0x5c) = 1;
                  if (iVar10 == 1) {
                    Gun::setIndex(pGVar11,0xf);
                    iVar10 = 0x1a87;
                  }
                  else {
                    Gun::setIndex(pGVar11,0x14);
                    iVar10 = 0x1a8c;
                  }
                }
                else {
                  iVar13 = KIPlayer::getType(pKVar3);
                  if (iVar13 == 0x49c1) {
                    *(undefined4 *)(pGVar11 + 0x5c) = 1;
                    Gun::setIndex(pGVar11,0x14);
                    local_78 = 0;
                    uStack_74 = 0;
                    local_70 = 0x437a0000;
                    AbyssEngine::AEMath::Vector::operator=
                              ((Vector *)(pGVar11 + 0x7c),(Vector *)&local_78);
                    pGVar11[0xa8] = (Gun)0x1;
                    iVar14 = 0xd4;
                    iVar10 = 0x1a8d;
                  }
                  else if (iVar13 == 0x49c0) {
                    *(undefined4 *)(pGVar11 + 0x5c) = 0;
                    Gun::setIndex(pGVar11,2);
                    local_78 = 0;
                    uStack_74 = 0;
                    local_70 = 0x437a0000;
                    AbyssEngine::AEMath::Vector::operator=
                              ((Vector *)(pGVar11 + 0x7c),(Vector *)&local_78);
                    iVar14 = 0xd3;
                    pGVar11[0xa8] = (Gun)0x1;
                    iVar10 = 0x1a64;
                  }
                  else {
                    *(undefined4 *)(pGVar11 + 0x5c) = 1;
                    Gun::setIndex(pGVar11,0xe);
                    local_78 = 0;
                    uStack_74 = 0;
                    local_70 = 0x43960000;
                    AbyssEngine::AEMath::Vector::operator=
                              ((Vector *)(pGVar11 + 0x7c),(Vector *)&local_78);
                    iVar14 = 0xd5;
                    iVar10 = 0x1a86;
                    pGVar11[0xa8] = (Gun)0x1;
                  }
                  uVar15 = Item::getAttribute(*(Item **)(*(int *)(Globals::items + 4) + iVar14 * 4),
                                              9);
                  *(undefined4 *)(pGVar11 + 0x60) = uVar15;
                  uVar15 = Item::getAttribute(*(Item **)(*(int *)(Globals::items + 4) + iVar14 * 4),
                                              0xb);
                  *(undefined4 *)(pGVar11 + 0x48) = uVar15;
                  uVar15 = Item::getAttribute(*(Item **)(*(int *)(Globals::items + 4) + iVar14 * 4),
                                              0xc);
                  *(undefined4 *)(pGVar11 + 0x44) = uVar15;
                  uVar15 = Item::getAttribute(*(Item **)(*(int *)(Globals::items + 4) + iVar14 * 4),
                                              0xd);
                  uVar15 = VectorSignedToFloat(uVar15,(byte)(uVar24 >> 0x16) & 3);
                  *(undefined4 *)(pGVar11 + 0x50) = uVar15;
                  if (((iVar12 == 0x9e) && (iVar13 == 0x49c2)) &&
                     (iVar13 = Player::isAlwaysEnemy
                                         (*(Player **)
                                           (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) +
                                                    uVar22 * 4) + 4)), iVar13 == 1)) {
                    fVar25 = (float)VectorSignedToFloat(*(undefined4 *)(pGVar11 + 0x60),
                                                        (byte)(uVar24 >> 0x16) & 3);
                    *(int *)(pGVar11 + 0x60) = (int)(fVar25 * 1.5);
                    *(float *)(pGVar11 + 0x50) = *(float *)(pGVar11 + 0x50) * 1.2;
                    this_02 = *(Player **)
                               (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar22 * 4) + 4);
                    uVar15 = Player::getMaxHitpoints(this_02);
                    fVar25 = (float)VectorSignedToFloat(uVar15,(byte)(uVar24 >> 0x16) & 3);
                    Player::setMaxHitpoints(this_02,(int)(fVar25 * 5.0));
                  }
                }
              }
              else {
                *(undefined4 *)(pGVar11 + 0x5c) = 2;
                Gun::setIndex(pGVar11,0x16);
                iVar10 = 0x1a8e;
                dVar28 = (double)VectorSignedToFloat(*(undefined4 *)(pGVar11 + 0x60),
                                                     (byte)(uVar24 >> 0x16) & 3);
                *(int *)(pGVar11 + 0x60) = (int)(longlong)(dVar28 * 0.5);
              }
            }
            if (iVar12 == 7) {
              if (*(int *)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar22 * 4) + 0x24) == 8)
              {
                fVar25 = (float)VectorSignedToFloat(*(undefined4 *)(pGVar11 + 0x60),
                                                    (byte)(uVar24 >> 0x16) & 3);
                *(int *)(pGVar11 + 0x60) = (int)(fVar25 * 0.5);
              }
            }
            else if ((iVar12 == 0x46) &&
                    (iVar13 = KIPlayer::isWingMan(*(KIPlayer **)
                                                   (*(int *)(*(int *)(this + 0xf8) + 4) + uVar22 * 4
                                                   )), iVar13 == 0)) {
              Gun::setIndex(pGVar11,0xb7);
              iVar10 = 0x37d9;
            }
            iVar13 = Status::getMission(Globals::status);
            if (iVar13 == 0) {
LAB_000cbe50:
              iVar13 = *(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar22 * 4);
              iVar14 = *(int *)(iVar13 + 0x78);
              if (iVar12 == 0x91 && iVar14 == 0x31) {
                *(undefined4 *)(pGVar11 + 0x5c) = 0x28;
                Gun::setIndex(pGVar11,0xd6);
                iVar10 = 0x37a0;
                iVar13 = *(int *)(pGVar11 + 0x60) << 1;
              }
              else if ((iVar12 - 0x9dU < 2) && (iVar14 == 0x31)) {
                *(undefined4 *)(pGVar11 + 0x5c) = 0;
                Gun::setIndex(pGVar11,7);
                iVar10 = 0x1a6c;
                iVar13 = *(int *)(pGVar11 + 0x60) * 3;
              }
              else {
                if ((this_00 == (Wanted *)0x0) || (*(char *)(iVar13 + 0x3e) == '\0'))
                goto LAB_000cbedc;
                iVar10 = Wanted::getWeapon(this_00);
                Gun::setIndex(pGVar11,iVar10);
                uVar15 = Item::getAttribute(*(Item **)(*(int *)(Globals::items + 4) + iVar10 * 4),2)
                ;
                *(undefined4 *)(pGVar11 + 0x5c) = uVar15;
                iVar10 = *(int *)(&DAT_00252d1c + iVar10 * 4);
                iVar13 = *(int *)(pGVar11 + 0x60) << 2;
              }
              *(int *)(pGVar11 + 0x60) = iVar13;
            }
            else {
              pMVar8 = (Mission *)Status::getMission(Globals::status);
              iVar14 = Mission::isCampaignMission(pMVar8);
              iVar13 = Globals::lastCampaignMissionFailed;
              if (iVar14 != 1) goto LAB_000cbe50;
              iVar14 = Status::getCurrentCampaignMission(Globals::status);
              if (((iVar13 == iVar14) && (2 < Globals::lastCampaignMissionFailCount)) &&
                 (iVar13 = KIPlayer::isEnemy(*(KIPlayer **)
                                              (*(int *)(*(int *)(this + 0xf8) + 4) + uVar22 * 4)),
                 iVar13 == 1)) {
                fVar25 = (float)VectorSignedToFloat(*(undefined4 *)(pGVar11 + 0x60),
                                                    (byte)(uVar24 >> 0x16) & 3);
                *(int *)(pGVar11 + 0x60) = (int)(fVar25 * 0.7);
              }
            }
LAB_000cbedc:
            iVar13 = *(int *)(pGVar11 + 0x5c);
            if (iVar13 == 0x28 || iVar13 == 5) {
              pRVar16 = operator_new(0xe8);
              RocketGun::RocketGun
                        (pRVar16,*(int *)(pGVar11 + 0x58),pGVar11,iVar10,0,0,iVar13,iVar13 == 5,this
                        );
              *(RocketGun **)(*(int *)(*(int *)(this + 0xe8) + 4) + iVar5 * 4) = pRVar16;
              *(undefined4 *)(pGVar11 + 0x50) = 0x41000000;
              *(undefined4 *)(pGVar11 + 0x44) = 10000;
              *(undefined4 *)(pGVar11 + 0x48) = 3000;
              *(int *)(pGVar11 + 0x60) = *(int *)(pGVar11 + 0x60) << 2;
            }
            else {
              pOVar17 = operator_new(0xb0);
              ObjectGun::ObjectGun(pOVar17,0,pGVar11,iVar10,0x2711,this);
              *(ObjectGun **)(*(int *)(*(int *)(this + 0xe8) + 4) + iVar5 * 4) = pOVar17;
            }
            KIPlayer::addGun(*(Gun **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar22 * 4),
                             (int)pGVar11);
            iVar10 = 0x3d;
            if (*(int *)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar22 * 4) + 0x24) == 9) {
              iVar10 = 0x3e;
            }
            Globals::addSoundResourceToList(Globals::globals,iVar10);
            pKVar3 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar22 * 4);
            if (((this_00 != (Wanted *)0x0) && (pKVar3[0x3e] != (KIPlayer)0x0)) &&
               (*(int *)(pKVar3 + 0x78) - 0x2dU < 4)) {
              pGVar11 = operator_new(0x114);
              Gun::Gun(pGVar11,0,iVar9 << 2,4,0xffffffff,10000,3000,0x41000000,0,0,0,0,0,0);
              Gun::setFriendGun(pGVar11,true);
              Gun::setLevel(pGVar11,this);
              *(undefined4 *)(pGVar11 + 0x5c) = 4;
              Gun::setIndex(pGVar11,0x1f);
              pRVar16 = operator_new(0xe8);
              RocketGun::RocketGun
                        (pRVar16,*(int *)(pGVar11 + 0x58),pGVar11,0x37a0,0,0,
                         *(int *)(pGVar11 + 0x5c),false,this);
              piVar20 = *(int **)(this + 0xe8);
              piVar20[2] = *piVar20 + 1;
              pvVar21 = realloc((void *)piVar20[1],(*piVar20 + 1) * 4);
              piVar20[1] = (int)pvVar21;
              *(RocketGun **)((int)pvVar21 + *piVar20 * 4) = pRVar16;
              *piVar20 = piVar20[2];
              KIPlayer::addGun(*(Gun **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar22 * 4),
                               (int)pGVar11);
              Globals::addSoundResourceToList(Globals::globals,0x54);
              pKVar3 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar22 * 4);
            }
            if ((iVar12 - 0x9dU < 2) && (*(int *)(pKVar3 + 0x78) == 0x31)) {
              pGVar11 = operator_new(0x114);
              iVar10 = Status::gameWon(Globals::status);
              if (iVar10 == 0) {
                iVar10 = Status::getCurrentCampaignMission(Globals::status);
              }
              else {
                iVar10 = 0x2d;
              }
              Gun::Gun(pGVar11,0,iVar9,4,0xffffffff,3000,iVar10 * -2 + 600,uVar18,0,0,0,0,0,0);
              Gun::setFriendGun(pGVar11,true);
              Gun::setLevel(pGVar11,this);
              *(undefined4 *)(pGVar11 + 0x5c) = 0x28;
              Gun::setIndex(pGVar11,0xd6);
              pRVar16 = operator_new(0xe8);
              RocketGun::RocketGun
                        (pRVar16,*(int *)(pGVar11 + 0x58),pGVar11,0x37a0,0,0,
                         *(int *)(pGVar11 + 0x5c),*(int *)(pGVar11 + 0x5c) == 5,this);
              piVar20 = *(int **)(this + 0xe8);
              piVar20[2] = *piVar20 + 1;
              pvVar21 = realloc((void *)piVar20[1],(*piVar20 + 1) * 4);
              piVar20[1] = (int)pvVar21;
              *(RocketGun **)((int)pvVar21 + *piVar20 * 4) = pRVar16;
              *piVar20 = piVar20[2];
              *(undefined4 *)(pGVar11 + 0x50) = 0x41000000;
              *(undefined4 *)(pGVar11 + 0x44) = 10000;
              *(undefined4 *)(pGVar11 + 0x48) = 3000;
              *(int *)(pGVar11 + 0x60) = *(int *)(pGVar11 + 0x60) << 2;
              KIPlayer::addGun(*(Gun **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar22 * 4),
                               (int)pGVar11);
              Globals::addSoundResourceToList(Globals::globals,0x54);
              pKVar3 = *(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar22 * 4);
            }
            iVar5 = iVar5 + 1;
            if (pKVar3 == (KIPlayer *)0x0) goto LAB_000cc25c;
          }
          iVar9 = KIPlayer::isWingMan(pKVar3);
          if ((iVar9 == 1) &&
             (*(char *)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar22 * 4) + 0x21) != '\0'))
          {
            pGVar11 = operator_new(0x114);
            Gun::Gun(pGVar11,0x12,0,4,0xffffffff,3000,400,0x41800000,0,0,0,0,0,0);
            Gun::setFriendGun(pGVar11,true);
            Gun::setLevel(pGVar11,this);
            *(undefined4 *)(pGVar11 + 0x58) = 0x12;
            *(undefined4 *)(pGVar11 + 0x5c) = 1;
            pOVar17 = operator_new(0xb0);
            ObjectGun::ObjectGun(pOVar17,0x12,pGVar11,0x1a8a,0x2711,this);
            *(ObjectGun **)(*(int *)(*(int *)(this + 0xe8) + 4) + iVar5 * 4) = pOVar17;
            Gun::setIndex(pGVar11,0x12);
            uVar18 = Item::getAttribute(*(Item **)(*(int *)(Globals::items + 4) + 0x48),10);
            *(undefined4 *)(pGVar11 + 100) = uVar18;
            KIPlayer::addGun(*(Gun **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar22 * 4),
                             (int)pGVar11);
            Globals::addSoundResourceToList(Globals::globals,0x4a);
            iVar5 = iVar5 + 1;
          }
        }
LAB_000cc25c:
        puVar19 = *(uint **)(this + 0xf8);
        uVar22 = uVar22 + 1;
      } while (uVar22 < *puVar19);
    }
  }
  if (__stack_chk_guard != local_6c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Level::connectPlayers  @0x000cc330  (1440 bytes)
/* Level::connectPlayers() */

void __thiscall Level::connectPlayers(Level *this)

{
  int iVar1;
  Array *pAVar2;
  undefined4 *puVar3;
  uint uVar4;
  Station *pSVar5;
  int iVar6;
  KIPlayer *pKVar7;
  int iVar8;
  Mission *pMVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  PlayerFixedObject *this_00;
  int iVar13;
  bool bVar14;
  uint local_30;
  
  iVar1 = AbyssEngine::ApplicationManager::GetCurrentApplicationModule(Globals::appManager);
  if (iVar1 != 5) {
    puVar11 = *(uint **)(this + 0xf8);
    if ((puVar11 != (uint *)0x0) && (*(int *)(this + 0xf0) != 0)) {
      pAVar2 = operator_new(0xc);
      puVar3 = operator_new__(4);
      *(undefined4 **)(pAVar2 + 4) = puVar3;
      *(undefined4 *)(pAVar2 + 8) = 1;
      *puVar3 = 0;
      *(undefined4 *)pAVar2 = 0;
      ArraySetLength<Player*>(*puVar11,pAVar2);
      uVar4 = *(uint *)pAVar2;
      if (uVar4 != 0) {
        uVar10 = 0;
        do {
          *(undefined4 *)(*(int *)(pAVar2 + 4) + uVar10 * 4) =
               *(undefined4 *)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar10 * 4) + 4);
          uVar10 = uVar10 + 1;
        } while (uVar10 < uVar4);
      }
      Player::setEnemies((Player *)**(undefined4 **)(this + 0xf0),pAVar2);
      if (*(void **)(pAVar2 + 4) != (void *)0x0) {
        operator_delete__(*(void **)(pAVar2 + 4));
      }
      operator_delete(pAVar2);
    }
    puVar11 = *(uint **)(this + 0xfc);
    if ((puVar11 != (uint *)0x0) && (*(int *)(this + 0xf0) != 0)) {
      pAVar2 = operator_new(0xc);
      puVar3 = operator_new__(4);
      *(undefined4 **)(pAVar2 + 4) = puVar3;
      *(undefined4 *)(pAVar2 + 8) = 1;
      *puVar3 = 0;
      *(undefined4 *)pAVar2 = 0;
      ArraySetLength<Player*>(*puVar11,pAVar2);
      uVar4 = *(uint *)pAVar2;
      if (uVar4 != 0) {
        uVar10 = 0;
        do {
          *(undefined4 *)(*(int *)(pAVar2 + 4) + uVar10 * 4) =
               *(undefined4 *)(*(int *)(*(int *)(*(int *)(this + 0xfc) + 4) + uVar10 * 4) + 4);
          uVar10 = uVar10 + 1;
        } while (uVar10 < uVar4);
      }
      Player::addEnemies((Player *)**(undefined4 **)(this + 0xf0),pAVar2);
      if (*(void **)(pAVar2 + 4) != (void *)0x0) {
        operator_delete__(*(void **)(pAVar2 + 4));
      }
      operator_delete(pAVar2);
    }
    puVar11 = *(uint **)(this + 0xf4);
    if ((puVar11 != (uint *)0x0) && (*(int *)(this + 0xf0) != 0)) {
      pAVar2 = operator_new(0xc);
      puVar3 = operator_new__(4);
      *(undefined4 **)(pAVar2 + 4) = puVar3;
      *(undefined4 *)(pAVar2 + 8) = 1;
      *puVar3 = 0;
      *(undefined4 *)pAVar2 = 0;
      ArraySetLength<Player*>(*puVar11,pAVar2);
      uVar4 = *(uint *)pAVar2;
      if (uVar4 != 0) {
        uVar10 = 0;
        do {
          *(undefined4 *)(*(int *)(pAVar2 + 4) + uVar10 * 4) =
               *(undefined4 *)(*(int *)(*(int *)(*(int *)(this + 0xf4) + 4) + uVar10 * 4) + 4);
          uVar10 = uVar10 + 1;
        } while (uVar10 < uVar4);
      }
      Player::addEnemies((Player *)**(undefined4 **)(this + 0xf0),pAVar2);
      if (*(void **)(pAVar2 + 4) != (void *)0x0) {
        operator_delete__(*(void **)(pAVar2 + 4));
      }
      operator_delete(pAVar2);
    }
    if (*(int *)(this + 0xf8) != 0) {
      iVar1 = Status::getCurrentCampaignMission(Globals::status);
      puVar11 = *(uint **)(this + 0xf8);
      if (*puVar11 != 0) {
        uVar4 = 0;
        do {
          this_00 = *(PlayerFixedObject **)(puVar11[1] + uVar4 * 4);
          iVar13 = *(int *)(this_00 + 0x24);
          iVar6 = KIPlayer::isWingMan((KIPlayer *)this_00);
          puVar11 = *(uint **)(this + 0xf8);
          uVar10 = 0;
          if (*puVar11 != 0) {
            uVar12 = 0;
            do {
              pKVar7 = *(KIPlayer **)(puVar11[1] + uVar12 * 4);
              if (((pKVar7 != (KIPlayer *)this_00) &&
                  (*(int *)(pKVar7 + 0x24) != iVar13 || iVar6 != 0)) &&
                 ((iVar1 != 0x24 || uVar4 != 0 || (iVar8 = KIPlayer::isWingMan(pKVar7), iVar8 == 0))
                 )) {
                if (iVar1 == 0x9a) {
                  iVar8 = Status::inAlienOrbit(Globals::status);
                  if ((uVar12 != 8 || iVar8 != 1) || (*(int *)(this_00 + 0x24) != 8))
                  goto LAB_000cc66a;
                }
                else if ((iVar1 != 0x40) ||
                        (((uVar4 != 0 && (this_00 != (PlayerFixedObject *)0x0)) && (uVar12 != 0))))
                {
LAB_000cc66a:
                  if ((this_00[0x3c] != (PlayerFixedObject)0x0) &&
                     (iVar8 = PlayerFixedObject::getDockingType(this_00), iVar8 == 3)) {
                    pSVar5 = (Station *)Status::getStation(Globals::status);
                    iVar8 = Station::stationHasHiddenBlueprint(pSVar5,true);
                    if (iVar8 != 0) goto LAB_000cc68c;
                  }
                  uVar10 = uVar10 + 1;
                }
              }
LAB_000cc68c:
              puVar11 = *(uint **)(this + 0xf8);
              uVar12 = uVar12 + 1;
            } while (uVar12 < *puVar11);
          }
          pAVar2 = operator_new(0xc);
          puVar3 = operator_new__(4);
          *(undefined4 **)(pAVar2 + 4) = puVar3;
          *(undefined4 *)(pAVar2 + 8) = 1;
          *puVar3 = 0;
          *(undefined4 *)pAVar2 = 0;
          if (*(int *)(this + 0xf0) != 0) {
            uVar10 = uVar10 + 1;
          }
          ArraySetLength<Player*>(uVar10,pAVar2);
          pMVar9 = (Mission *)Status::getMission(Globals::status);
          iVar8 = Mission::getType(pMVar9);
          if ((((int)uVar4 % 2 == 1 && iVar8 == 0xc) ||
              (iVar8 = Mission::getType(pMVar9), iVar8 == 2)) ||
             (iVar8 = Mission::getType(pMVar9), iVar8 == 9)) {
LAB_000cc790:
            iVar8 = Player::isAlwaysFriend(*(Player **)(this_00 + 4));
            if (iVar8 == 0) {
              puVar11 = *(uint **)(this + 0xf8);
              if (*puVar11 != 0) {
                uVar10 = 0;
                local_30 = 0;
                do {
                  pKVar7 = *(KIPlayer **)(puVar11[1] + uVar10 * 4);
                  if ((((pKVar7 != (KIPlayer *)this_00) && (pKVar7[0x38] == (KIPlayer)0x0)) &&
                      (*(int *)(pKVar7 + 0x24) != iVar13 || iVar6 != 0)) &&
                     ((iVar1 != 0x24 || uVar4 != 0 ||
                      (iVar8 = KIPlayer::isWingMan(pKVar7), iVar8 == 0)))) {
                    if ((iVar1 != 0x40) || (uVar10 != 0 && uVar4 != 0)) {
                      *(undefined4 *)(*(int *)(pAVar2 + 4) + local_30 * 4) =
                           *(undefined4 *)
                            (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar10 * 4) + 4);
                      local_30 = local_30 + 1;
                    }
                  }
                  puVar11 = *(uint **)(this + 0xf8);
                  uVar10 = uVar10 + 1;
                } while (uVar10 < *puVar11);
              }
            }
            else {
              if (*(void **)(pAVar2 + 4) != (void *)0x0) {
                operator_delete__(*(void **)(pAVar2 + 4));
              }
              operator_delete(pAVar2);
              pAVar2 = operator_new(0xc);
              puVar3 = operator_new__(4);
              *(undefined4 **)(pAVar2 + 4) = puVar3;
              *(undefined4 *)(pAVar2 + 8) = 1;
              *puVar3 = 0;
              *(undefined4 *)pAVar2 = 0;
              ArraySetLength<Player*>(1,pAVar2);
            }
            *(undefined4 *)(*(int *)(pAVar2 + 4) + *(int *)pAVar2 * 4 + -4) =
                 **(undefined4 **)(this + 0xf0);
          }
          else {
            iVar8 = Mission::isCampaignMission(pMVar9);
            if (iVar8 == 1) {
              iVar8 = Status::getCurrentCampaignMission(Globals::status);
              bVar14 = iVar8 == 0x10;
              if (bVar14) {
                iVar8 = *(int *)(this_00 + 0x24);
              }
              if (bVar14 && iVar8 == 9) goto LAB_000cc790;
            }
            iVar8 = Mission::isCampaignMission(pMVar9);
            if (iVar8 == 1) {
              iVar8 = Status::getCurrentCampaignMission(Globals::status);
              bVar14 = iVar8 == 0x18;
              if (bVar14) {
                iVar8 = *(int *)(this_00 + 0x24);
              }
              if (bVar14 && iVar8 == 9) goto LAB_000cc790;
            }
            iVar8 = Mission::isCampaignMission(pMVar9);
            if (iVar8 == 1) {
              iVar8 = Status::getCurrentCampaignMission(Globals::status);
              bVar14 = iVar8 == 0x1c;
              if (bVar14) {
                iVar8 = *(int *)(this_00 + 0x24);
              }
              if (bVar14 && iVar8 == 9) goto LAB_000cc790;
            }
            iVar8 = Mission::isCampaignMission(pMVar9);
            if (iVar8 == 1) {
              Status::getCurrentCampaignMission(Globals::status);
            }
            iVar8 = Mission::isCampaignMission(pMVar9);
            if (iVar8 == 1) {
              Status::getCurrentCampaignMission(Globals::status);
            }
            puVar3 = *(undefined4 **)(this + 0xf0);
            if (puVar3 != (undefined4 *)0x0) {
              **(undefined4 **)(pAVar2 + 4) = *puVar3;
            }
            local_30 = (uint)(puVar3 != (undefined4 *)0x0);
            puVar11 = *(uint **)(this + 0xf8);
            if (*puVar11 != 0) {
              uVar10 = 0;
              do {
                pKVar7 = *(KIPlayer **)(puVar11[1] + uVar10 * 4);
                if (((pKVar7 != (KIPlayer *)this_00) &&
                    (*(int *)(pKVar7 + 0x24) != iVar13 || iVar6 != 0)) &&
                   ((uVar4 != 0 || iVar1 != 0x24 ||
                    (iVar8 = KIPlayer::isWingMan(pKVar7), iVar8 == 0)))) {
                  if (iVar1 == 0x9a) {
                    iVar8 = Status::inAlienOrbit(Globals::status);
                    if ((uVar10 != 8 || iVar8 != 1) || (*(int *)(this_00 + 0x24) != 8))
                    goto LAB_000cc592;
                  }
                  else if ((iVar1 != 0x40) ||
                          (((uVar4 != 0 && (this_00 != (PlayerFixedObject *)0x0)) && (uVar10 != 0)))
                          ) {
LAB_000cc592:
                    if ((this_00[0x3c] != (PlayerFixedObject)0x0) &&
                       (iVar8 = PlayerFixedObject::getDockingType(this_00), iVar8 == 3)) {
                      pSVar5 = (Station *)Status::getStation(Globals::status);
                      iVar8 = Station::stationHasHiddenBlueprint(pSVar5,true);
                      if (iVar8 != 0) goto LAB_000cc5cc;
                    }
                    *(undefined4 *)(*(int *)(pAVar2 + 4) + local_30 * 4) =
                         *(undefined4 *)
                          (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar10 * 4) + 4);
                    local_30 = local_30 + 1;
                  }
                }
LAB_000cc5cc:
                puVar11 = *(uint **)(this + 0xf8);
                uVar10 = uVar10 + 1;
              } while (uVar10 < *puVar11);
            }
          }
          Player::addEnemies(*(Player **)(this_00 + 4),pAVar2);
          if (*(void **)(pAVar2 + 4) != (void *)0x0) {
            operator_delete__(*(void **)(pAVar2 + 4));
          }
          operator_delete(pAVar2);
          pMVar9 = (Mission *)Status::getMission(Globals::status);
          iVar6 = Mission::isEmpty(pMVar9);
          if (iVar13 == 10 && iVar6 == 1) {
            Player::setEnemy(*(Player **)(this_00 + 4),(Player *)**(undefined4 **)(this + 0xf0));
          }
          puVar11 = *(uint **)(this + 0xf8);
          uVar4 = uVar4 + 1;
        } while (uVar4 < *puVar11);
      }
    }
  }
  return;
}

// ===== Level::enableParticleEffects  @0x000cc920  (42 bytes)
/* Level::enableParticleEffects(bool, bool) */

void __thiscall Level::enableParticleEffects(Level *this,bool param_1,bool param_2)

{
  ParticleSystemManager::enableSystemEmit
            (*(ParticleSystemManager **)(this + 0x7c),*(int *)(this + 0x284),param_2);
  ParticleSystemManager::enableSystemRender
            (*(ParticleSystemManager **)(this + 0x7c),*(int *)(this + 0x284),param_2);
  *(bool *)*(undefined4 *)(this + 0x84) = param_2;
  *(bool *)*(undefined4 *)(this + 0x78) = param_2;
  return;
}

// ===== Level::setPlayerEngineColor  @0x000cc94c  (56 bytes)
/* Level::setPlayerEngineColor(short) */

void __thiscall Level::setPlayerEngineColor(Level *this,short param_1)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  
  iVar2 = (int)param_1;
  if (((*(int *)(this + 0xf0) != 0) && (*(uint **)(this + 0xa4) != (uint *)0x0)) &&
     (uVar1 = **(uint **)(this + 0xa4), uVar1 != 0)) {
    uVar4 = 0;
    puVar3 = (uint *)(ParticleSettingsRef::cur + 0x11dc);
    do {
      uVar4 = uVar4 + 1;
      *puVar3 = iVar2 << 0x10 | iVar2 << 0x18 | iVar2 << 8 | 0xff;
      puVar3 = puVar3 + 0x27;
    } while (uVar4 < uVar1);
  }
  return;
}

// ===== Level::initParticleSystems  @0x000cc990  (1858 bytes)
/* Level::initParticleSystems() */

void __thiscall Level::initParticleSystems(Level *this)

{
  Status *this_00;
  PaintCanvas *pPVar1;
  Array *pAVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  Ship *this_01;
  int iVar5;
  SolarSystem *pSVar6;
  undefined4 uVar7;
  ParticleSystemManager *pPVar8;
  KIPlayer *this_02;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  uint in_fpscr;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 unaff_s23;
  undefined1 auVar18 [16];
  undefined4 uVar21;
  double dVar22;
  undefined8 uVar23;
  undefined8 local_310;
  undefined8 uStack_308;
  undefined8 local_300;
  undefined8 uStack_2f8;
  undefined8 local_2f0;
  undefined8 uStack_2e8;
  undefined8 local_2e0;
  undefined8 uStack_2d8;
  undefined8 local_2d0;
  undefined8 uStack_2c8;
  undefined4 local_2c0 [5];
  undefined4 local_2ac;
  undefined4 local_2a8;
  undefined4 uStack_2a4;
  undefined4 uStack_2a0;
  undefined4 uStack_29c;
  undefined8 uStack_298;
  undefined8 uStack_290;
  undefined4 local_288;
  undefined4 local_280 [5];
  undefined4 local_26c;
  undefined4 local_268;
  undefined4 uStack_264;
  undefined4 uStack_260;
  undefined4 uStack_25c;
  undefined8 uStack_258;
  undefined8 uStack_250;
  undefined4 local_248;
  undefined4 local_240 [5];
  undefined4 local_22c;
  undefined4 local_228;
  undefined4 uStack_224;
  undefined4 uStack_220;
  undefined4 uStack_21c;
  undefined8 uStack_218;
  undefined8 uStack_210;
  undefined4 local_208;
  undefined4 local_200 [5];
  undefined4 local_1ec;
  undefined4 local_1e8;
  undefined4 uStack_1e4;
  undefined4 uStack_1e0;
  undefined4 uStack_1dc;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined4 local_1c8;
  undefined4 local_1c0 [5];
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 uStack_1a4;
  undefined4 uStack_1a0;
  undefined4 uStack_19c;
  undefined8 uStack_198;
  undefined8 uStack_190;
  undefined4 local_188;
  undefined4 local_180 [5];
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined8 uStack_158;
  undefined8 uStack_150;
  undefined4 local_148;
  undefined4 local_140 [5];
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined4 local_108;
  float local_100;
  float local_fc;
  float local_f8;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined4 local_c8;
  float local_c4;
  float local_b8;
  undefined4 local_a4;
  float local_a0;
  float local_94;
  float local_88;
  undefined4 local_78;
  undefined4 local_70;
  int local_64;
  
  local_64 = __stack_chk_guard;
  if (*(int *)(this + 0xf0) != 0) {
    puVar9 = *(uint **)(this + 0xa4);
    if (puVar9 != (uint *)0x0) {
      pAVar2 = operator_new(0xc);
      puVar3 = operator_new__(4);
      *(undefined4 **)(pAVar2 + 4) = puVar3;
      *(undefined4 *)(pAVar2 + 8) = 1;
      *puVar3 = 0;
      *(undefined4 *)pAVar2 = 0;
      *(Array **)(this + 0xa8) = pAVar2;
      ArraySetLength<int>(*puVar9,pAVar2);
      if (**(int **)(this + 0xa4) != 0) {
        iVar11 = 0;
        uVar10 = 0;
        puVar12 = (undefined8 *)(ParticleSettingsRef::cur + 0x1230);
        local_2d0 = 0x3b0000003e810000;
        uStack_2c8 = 0x3dfc00003ebf0000;
        local_2e0 = 0x3b0000003ec10000;
        uStack_2d8 = 0x3dfc00003eff0000;
        local_2f0 = 0x3bc000003e040000;
        uStack_2e8 = 0x3df800003e7c0000;
        local_300 = 0x3bc000003bc00000;
        uStack_2f8 = 0x3df400003df40000;
        auVar18._8_4_ = 0x437a0000;
        auVar18._0_8_ = 0x4054000000000000;
        auVar18._12_4_ = unaff_s23;
        local_310 = 0x3b0000003f008000;
        uStack_308 = 0x3dfc00003f1f8000;
        do {
          uVar4 = ParticleSystemManager::addSystem
                            (*(ParticleSystemManager **)(this + 0x80),**(int **)(this + 0xf0) + 4,
                             uVar10 + 0x1d,0);
          *(undefined4 *)(*(int *)(*(int *)(this + 0xa8) + 4) + iVar11) = uVar4;
          AEGeometry::getPosition();
          *(undefined4 *)(puVar12 + -2) = local_70;
          AEGeometry::getPosition();
          *(undefined4 *)((int)puVar12 + -0xc) = local_78;
          AEGeometry::getScaling();
          in_fpscr = in_fpscr & 0xfffffff;
          dVar22 = 1.0;
          if (local_88 * 1.5 < 1.0) {
            AEGeometry::getScaling();
            dVar22 = (double)local_94 * 1.5;
          }
          *(int *)(puVar12 + -0xc) = (int)(longlong)(dVar22 * auVar18._0_8_);
          AEGeometry::getScaling();
          *(float *)((int)puVar12 + -0x74) = local_a0 * auVar18._8_4_;
          *(undefined4 *)((int)puVar12 + -0x5c) = 0x41000000;
          *(undefined4 *)(puVar12 + -0xf) = 0x14;
          *(undefined4 *)((int)puVar12 + -0x44) = 0xfffffc18;
          AEGeometry::getPosition();
          *(undefined4 *)(puVar12 + -1) = local_a4;
          AEGeometry::getScaling();
          in_fpscr = in_fpscr & 0xfffffff;
          dVar22 = 1.0;
          if (local_b8 * 1.5 < 1.0) {
            AEGeometry::getScaling();
            dVar22 = (double)local_c4 * 1.5;
          }
          *(float *)(puVar12 + -3) = (float)(dVar22 * -4000.0);
          *(undefined4 *)((int)puVar12 + -0x54) = 0xddddddff;
          *(undefined4 *)(puVar12 + -10) = 0;
          this_00 = Globals::status;
          *(undefined4 *)((int)puVar12 + -0x24) = 0x3f4ccccd;
          this_01 = (Ship *)Status::getShip(this_00);
          iVar5 = Ship::getIndex(this_01);
          switch(*(undefined4 *)(&DAT_00252ba0 + iVar5 * 4)) {
          case 1:
            puVar13 = &local_2e0;
            break;
          case 2:
            puVar13 = &local_2f0;
            break;
          case 3:
            puVar13 = &local_300;
            break;
          default:
            puVar13 = &local_2d0;
            break;
          case 8:
            puVar13 = &local_310;
            break;
          case 9:
            *puVar12 = 0x3b0000003f208000;
            puVar12[1] = 0x3dfc00003f3f8000;
            goto LAB_000ccc3a;
          }
          uVar23 = puVar13[1];
          *puVar12 = *puVar13;
          puVar12[1] = uVar23;
LAB_000ccc3a:
          iVar11 = iVar11 + 4;
          puVar12 = (undefined8 *)((int)puVar12 + 0x9c);
          uVar10 = uVar10 + 1;
        } while (uVar10 < **(uint **)(this + 0xa4));
      }
    }
    pPVar1 = Globals::Canvas;
    pPVar8 = *(ParticleSystemManager **)(this + 0x88);
    uVar10 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
    uVar4 = AbyssEngine::PaintCanvas::CameraGetLocal(pPVar1,uVar10);
    uVar4 = ParticleSystemManager::addSystem(pPVar8,uVar4,4,0);
    *(undefined4 *)(this + 100) = uVar4;
    iVar11 = Status::getSystem(Globals::status);
    if (iVar11 != 0) {
      pSVar6 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar11 = SolarSystem::hasPirateBase(pSVar6);
      if (((iVar11 == 1) && (puVar9 = *(uint **)(this + 0xf8), puVar9 != (uint *)0x0)) &&
         (*puVar9 != 0)) {
        uVar10 = 0;
        do {
          this_02 = *(KIPlayer **)(puVar9[1] + uVar10 * 4);
          if (this_02 != (KIPlayer *)0x0) {
            iVar11 = KIPlayer::getType(this_02);
            if (iVar11 == 0x37a3) {
              AEGeometry::updateReferenceMatrix(*(AEGeometry **)(this_02 + 8));
              pPVar8 = *(ParticleSystemManager **)(this + 0x7c);
              uVar4 = AEGeometry::getReferenceMatrix(*(AEGeometry **)(this_02 + 8));
              ParticleSystemManager::addSystem(pPVar8,uVar4,8,0);
              break;
            }
            puVar9 = *(uint **)(this + 0xf8);
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < *puVar9);
      }
    }
    pPVar1 = Globals::Canvas;
    pPVar8 = *(ParticleSystemManager **)(this + 0x7c);
    uVar10 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
    uVar4 = AbyssEngine::PaintCanvas::CameraGetLocal(pPVar1,uVar10);
    uVar4 = ParticleSystemManager::addSystem(pPVar8,uVar4,7,0);
    *(undefined4 *)(this + 0x284) = uVar4;
    iVar11 = Status::inAlienOrbit(Globals::status);
    if (iVar11 == 0) {
      ParticleSettingsRef::cur._1296_4_ = 0xe2282880;
      ParticleSettingsRef::cur._1300_4_ = 0xff0080;
      pSVar6 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar11 = SolarSystem::getTextureIndex(pSVar6);
      fVar17 = 0.6;
      uVar10 = *(uint *)(&DAT_00252ca0 + iVar11 * 4);
      iVar11 = Status::inSupernovaSystem(Globals::status);
      if (iVar11 != 0) {
        fVar17 = 0.5;
      }
      fVar14 = (float)VectorSignedToFloat(uVar10 >> 0x18,(byte)(in_fpscr >> 0x16) & 3);
      fVar15 = (float)VectorSignedToFloat((uVar10 & 0xffffff) >> 0x10,(byte)(in_fpscr >> 0x16) & 3);
      fVar16 = (float)VectorSignedToFloat((uVar10 & 0xffff) >> 8,(byte)(in_fpscr >> 0x16) & 3);
      uVar10 = 0xbb;
      if (iVar11 != 0) {
        uVar10 = 0xff;
      }
      ParticleSettingsRef::cur._1140_4_ =
           (int)(fVar14 * fVar17) << 0x18 | (int)(fVar15 * fVar17) << 0x10 |
           (int)(fVar16 * fVar17) << 8 | uVar10;
      ParticleSettingsRef::cur._1144_4_ = ParticleSettingsRef::cur._1140_4_;
    }
    else {
      ParticleSettingsRef::cur._1296_4_ = ParticleSettingsRef::cur._1296_4_ & 0xff | 0x9274d400;
      ParticleSettingsRef::cur._1140_4_ = ParticleSettingsRef::cur._1140_4_ & 0xff | 0x9274d400;
    }
  }
  iVar11 = Status::inSupernovaSystem(Globals::status);
  if (((iVar11 == 1) &&
      (iVar11 = Status::getCurrentCampaignMission(Globals::status), iVar11 != 0x59)) &&
     (iVar11 = Status::getCurrentCampaignMission(Globals::status), iVar11 < 0x9e)) {
    StarSystem::getLightDirection();
    AbyssEngine::AEMath::VectorNormalize((AEMath *)local_140,(Vector *)local_180);
    AbyssEngine::AEMath::operator-((AEMath *)&local_100,(Vector *)local_140);
    ParticleSettingsRef::cur._1176_4_ = local_100 * 2000.0;
    ParticleSettingsRef::cur._1180_4_ = local_fc * 2000.0;
    ParticleSettingsRef::cur._1184_4_ = local_f8 * 2000.0;
  }
  else {
    ParticleSettingsRef::cur._1176_4_ = 0;
    ParticleSettingsRef::cur._1180_4_ = 0;
    ParticleSettingsRef::cur._1184_4_ = 0;
  }
  if (*(ParticleSystemManager **)(this + 0x80) != (ParticleSystemManager *)0x0) {
    ParticleSystemManager::init(*(ParticleSystemManager **)(this + 0x80));
  }
  if (*(ParticleSystemManager **)(this + 0x7c) != (ParticleSystemManager *)0x0) {
    ParticleSystemManager::init(*(ParticleSystemManager **)(this + 0x7c));
  }
  if (*(ParticleSystemManager **)(this + 0x88) != (ParticleSystemManager *)0x0) {
    ParticleSystemManager::init(*(ParticleSystemManager **)(this + 0x88));
  }
  if (*(ParticleSystemManager **)(this + 0x8c) != (ParticleSystemManager *)0x0) {
    ParticleSystemManager::init(*(ParticleSystemManager **)(this + 0x8c));
  }
  if (*(ParticleSystemManager **)(this + 0x98) != (ParticleSystemManager *)0x0) {
    ParticleSystemManager::init(*(ParticleSystemManager **)(this + 0x98));
  }
  uVar4 = 0;
  uVar19 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar20 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar21 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  puVar3 = (undefined4 *)((uint)&local_100 | 4);
  local_100 = 1.0;
  *puVar3 = 0;
  puVar3[1] = uVar19;
  puVar3[2] = uVar20;
  puVar3[3] = uVar21;
  local_ec = 0x3f800000;
  local_e8 = 0;
  uStack_d8 = 0x3f800000;
  uStack_d0 = 0x3f8000003f800000;
  local_c8 = 0x3f800000;
  uStack_e4 = uVar19;
  uStack_e0 = uVar20;
  uStack_dc = uVar21;
  uVar7 = ParticleSystemManager::addSystem(*(ParticleSystemManager **)(this + 0x74),&local_100,10,0)
  ;
  *(undefined4 *)(this + 0x38) = uVar7;
  puVar3 = (undefined4 *)((uint)local_140 | 4);
  local_140[0] = 0x3f800000;
  *puVar3 = uVar4;
  puVar3[1] = uVar19;
  puVar3[2] = uVar20;
  puVar3[3] = uVar21;
  local_12c = 0x3f800000;
  uStack_118 = 0x3f800000;
  uStack_110 = 0x3f8000003f800000;
  local_108 = 0x3f800000;
  local_128 = uVar4;
  uStack_124 = uVar19;
  uStack_120 = uVar20;
  uStack_11c = uVar21;
  uVar7 = ParticleSystemManager::addSystem(*(ParticleSystemManager **)(this + 0x74),local_140,0xb,0)
  ;
  *(undefined4 *)(this + 0x3c) = uVar7;
  puVar3 = (undefined4 *)((uint)local_180 | 4);
  local_180[0] = 0x3f800000;
  *puVar3 = uVar4;
  puVar3[1] = uVar19;
  puVar3[2] = uVar20;
  puVar3[3] = uVar21;
  local_16c = 0x3f800000;
  uStack_158 = 0x3f800000;
  uStack_150 = 0x3f8000003f800000;
  local_148 = 0x3f800000;
  local_168 = uVar4;
  uStack_164 = uVar19;
  uStack_160 = uVar20;
  uStack_15c = uVar21;
  uVar7 = ParticleSystemManager::addSystem
                    (*(ParticleSystemManager **)(this + 0x74),local_180,0x14,0);
  *(undefined4 *)(this + 0x48) = uVar7;
  puVar3 = (undefined4 *)((uint)local_1c0 | 4);
  local_1c0[0] = 0x3f800000;
  *puVar3 = uVar4;
  puVar3[1] = uVar19;
  puVar3[2] = uVar20;
  puVar3[3] = uVar21;
  local_1ac = 0x3f800000;
  uStack_198 = 0x3f800000;
  uStack_190 = 0x3f8000003f800000;
  local_188 = 0x3f800000;
  local_1a8 = uVar4;
  uStack_1a4 = uVar19;
  uStack_1a0 = uVar20;
  uStack_19c = uVar21;
  uVar7 = ParticleSystemManager::addSystem
                    (*(ParticleSystemManager **)(this + 0x74),local_1c0,0x15,0);
  *(undefined4 *)(this + 0x34) = uVar7;
  puVar3 = (undefined4 *)((uint)local_200 | 4);
  local_200[0] = 0x3f800000;
  *puVar3 = uVar4;
  puVar3[1] = uVar19;
  puVar3[2] = uVar20;
  puVar3[3] = uVar21;
  local_1ec = 0x3f800000;
  uStack_1d8 = 0x3f800000;
  uStack_1d0 = 0x3f8000003f800000;
  local_1c8 = 0x3f800000;
  local_1e8 = uVar4;
  uStack_1e4 = uVar19;
  uStack_1e0 = uVar20;
  uStack_1dc = uVar21;
  uVar7 = ParticleSystemManager::addSystem
                    (*(ParticleSystemManager **)(this + 0x74),local_200,0x16,0);
  *(undefined4 *)(this + 0x50) = uVar7;
  puVar3 = (undefined4 *)((uint)local_240 | 4);
  local_240[0] = 0x3f800000;
  *puVar3 = uVar4;
  puVar3[1] = uVar19;
  puVar3[2] = uVar20;
  puVar3[3] = uVar21;
  local_22c = 0x3f800000;
  uStack_218 = 0x3f800000;
  uStack_210 = 0x3f8000003f800000;
  local_208 = 0x3f800000;
  local_228 = uVar4;
  uStack_224 = uVar19;
  uStack_220 = uVar20;
  uStack_21c = uVar21;
  uVar7 = ParticleSystemManager::addSystem
                    (*(ParticleSystemManager **)(this + 0x74),local_240,0x17,0);
  *(undefined4 *)(this + 0x54) = uVar7;
  iVar11 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar11 == 0x50) {
    local_280[0] = 0x3f800000;
    puVar3 = (undefined4 *)((uint)local_280 | 4);
    *puVar3 = uVar4;
    puVar3[1] = uVar19;
    puVar3[2] = uVar20;
    puVar3[3] = uVar21;
    local_26c = 0x3f800000;
    uStack_258 = 0x3f800000;
    uStack_250 = 0x3f8000003f800000;
    local_248 = 0x3f800000;
    local_268 = uVar4;
    uStack_264 = uVar19;
    uStack_260 = uVar20;
    uStack_25c = uVar21;
    uVar7 = ParticleSystemManager::addSystem
                      (*(ParticleSystemManager **)(this + 0x74),local_280,0x18,0);
    *(undefined4 *)(this + 0x58) = uVar7;
    puVar3 = (undefined4 *)((uint)local_2c0 | 4);
    local_2c0[0] = 0x3f800000;
    *puVar3 = uVar4;
    puVar3[1] = uVar19;
    puVar3[2] = uVar20;
    puVar3[3] = uVar21;
    local_2ac = 0x3f800000;
    uStack_298 = 0x3f800000;
    uStack_290 = 0x3f8000003f800000;
    local_288 = 0x3f800000;
    local_2a8 = uVar4;
    uStack_2a4 = uVar19;
    uStack_2a0 = uVar20;
    uStack_29c = uVar21;
    uVar4 = ParticleSystemManager::addSystem
                      (*(ParticleSystemManager **)(this + 0x74),local_2c0,0x18,0);
    *(undefined4 *)(this + 0x5c) = uVar4;
  }
  ParticleSystemManager::init(*(ParticleSystemManager **)(this + 0x74));
  ParticleSystemManager::enableSystemEmit
            (*(ParticleSystemManager **)(this + 0x74),*(int *)(this + 0x50),false);
  ParticleSystemManager::enableSystemEmit
            (*(ParticleSystemManager **)(this + 0x74),*(int *)(this + 0x54),false);
  iVar11 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar11 == 0x50) {
    ParticleSystemManager::enableSystemEmit
              (*(ParticleSystemManager **)(this + 0x74),*(int *)(this + 0x58),false);
    ParticleSystemManager::enableSystemEmit
              (*(ParticleSystemManager **)(this + 0x74),*(int *)(this + 0x5c),false);
  }
  ParticleSystemManager::init(*(ParticleSystemManager **)(this + 0x9c));
  ParticleSystemManager::init(*(ParticleSystemManager **)(this + 0x78));
  ParticleSystemManager::init(*(ParticleSystemManager **)(this + 0x84));
  if (*(ParticleSystemManager **)(this + 0x94) != (ParticleSystemManager *)0x0) {
    ParticleSystemManager::init(*(ParticleSystemManager **)(this + 0x94));
  }
  if (__stack_chk_guard != local_64) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Level::getStarSystem  @0x000cd1e0  (6 bytes)
/* Level::getStarSystem() */

undefined4 __thiscall Level::getStarSystem(Level *this)

{
  return *(undefined4 *)(this + 0xec);
}

// ===== Level::getGasClouds  @0x000cd21a  (6 bytes)
/* Level::getGasClouds() */

undefined4 __thiscall Level::getGasClouds(Level *this)

{
  return *(undefined4 *)(this + 0xf4);
}

// ===== Level::createGun  @0x000cd220  (1854 bytes)
/* Level::createGun(int, int, int, int, int, int, int, int) */

Gun * __thiscall
Level::createGun(Level *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6
                ,int param_7,int param_8)

{
  int iVar1;
  undefined4 *puVar2;
  void *pvVar3;
  undefined4 uVar4;
  int *piVar5;
  ObjectGun *this_00;
  Gun *this_01;
  uint in_fpscr;
  undefined4 uVar6;
  undefined4 uVar7;
  
  this_00 = (ObjectGun *)0x0;
  uVar6 = 0x43960000;
  this_01 = (Gun *)0x0;
  switch(param_3) {
  case 0:
  case 1:
  case 3:
    iVar1 = *(int *)(&DAT_00252d1c + param_1 * 4);
    if (iVar1 < 0) {
      this_01 = operator_new(0x114);
      uVar6 = VectorSignedToFloat(param_8,(byte)(in_fpscr >> 0x16) & 3);
      Gun::Gun(this_01,param_2,param_5,1,param_4,param_7,param_6,uVar6,0,0,0,0,0,0);
      Gun::setIndex(this_01,param_1);
      *(int *)(this_01 + 0x5c) = param_3;
      Gun::setPlayerGun(this_01,true);
      this_00 = operator_new(0x24);
      BeamGun::BeamGun((BeamGun *)this_00,param_2,this_01,param_1,this);
    }
    else {
      uVar6 = 0x14;
      uVar4 = VectorSignedToFloat(param_8,(byte)(in_fpscr >> 0x16) & 3);
      if (param_1 - 9U < 3) {
        uVar6 = 1;
      }
      if (param_1 == 0xe4) {
        uVar6 = 1;
      }
      this_01 = operator_new(0x114);
      if (param_3 == 3) {
        Gun::Gun(this_01,param_2,param_5,uVar6,param_4,param_7,param_6,uVar4,0,0,0x43960000,0,0,0);
        Gun::setIndex(this_01,param_1);
        *(undefined4 *)(this_01 + 0x5c) = 3;
        Gun::setPlayerGun(this_01,true);
        Gun::setErrorMagnitudePercentage(this_01,0x14);
        this_00 = operator_new(0xe8);
        RocketGun::RocketGun((RocketGun *)this_00,param_2,this_01,iVar1,0,0,0,true,this);
      }
      else {
        Gun::Gun(this_01,param_2,param_5,uVar6,param_4,param_7,param_6,uVar4,0,0,0,0,0,0);
        Gun::setIndex(this_01,param_1);
        *(int *)(this_01 + 0x5c) = param_3;
        Gun::setPlayerGun(this_01,true);
        this_00 = operator_new(0xb0);
        ObjectGun::ObjectGun(this_00,param_2,this_01,iVar1,1000,this);
      }
    }
    break;
  case 2:
  case 0x19:
    this_01 = operator_new(0x114);
    uVar6 = VectorSignedToFloat(param_8,(byte)(in_fpscr >> 0x16) & 3);
    Gun::Gun(this_01,param_2,param_5,0x19,param_4,param_7,param_6,uVar6,0,0,0x43c80000,0,0,0);
    Gun::setIndex(this_01,param_1);
    *(int *)(this_01 + 0x5c) = param_3;
    Gun::setPlayerGun(this_01,true);
    this_00 = operator_new(0xb0);
    ObjectGun::ObjectGun(this_00,param_2,this_01,*(int *)(&DAT_00252d1c + param_1 * 4),1000,this);
    Gun::setErrorMagnitudePercentage(this_01,2);
    break;
  case 4:
  case 5:
switchD_000cd25e_caseD_4:
    this_01 = operator_new(0x114);
    uVar6 = VectorSignedToFloat(param_8,(byte)(in_fpscr >> 0x16) & 3);
    iVar1 = 5;
    if (param_3 == 0x28) {
      iVar1 = param_1 + -0xd3;
    }
    Gun::Gun(this_01,param_2,param_5,iVar1,param_4,param_7,param_6,uVar6,0,0,0,0,0,0);
    Gun::setIndex(this_01,param_1);
    *(int *)(this_01 + 0x5c) = param_3;
    Gun::setPlayerGun(this_01,true);
    this_00 = operator_new(0xe8);
    RocketGun::RocketGun
              ((RocketGun *)this_00,param_2,this_01,*(int *)(&DAT_00252d1c + param_1 * 4),0,0,
               param_3,param_3 == 0x28 || param_3 == 5,this);
    goto LAB_000cd768;
  case 6:
  case 7:
switchD_000cd25e_caseD_6:
    this_01 = operator_new(0x114);
    uVar6 = VectorSignedToFloat(param_8,(byte)(in_fpscr >> 0x16) & 3);
    Gun::Gun(this_01,param_2,param_5,1,param_4,param_7,param_6,uVar6,0,0,0x43c80000,0,0,0);
    Gun::setIndex(this_01,param_1);
    *(int *)(this_01 + 0x5c) = param_3;
    Gun::setPlayerGun(this_01,true);
    iVar1 = Item::getAttribute(*(Item **)(*(int *)(Globals::items + 4) + param_1 * 4),0xf);
    this_00 = operator_new(300);
    BombGun::BombGun((BombGun *)this_00,this_01,*(uint *)(&DAT_00252d1c + param_1 * 4),1,param_3,
                     iVar1 == 1,this);
    goto LAB_000cd768;
  case 8:
    if (param_1 == 0xb5) {
      uVar4 = 0;
      uVar6 = 0xc3960000;
    }
    else if (param_1 == 0x30) {
      uVar4 = 0x42a00000;
    }
    else {
      uVar4 = 0;
    }
    this_01 = operator_new(0x114);
    uVar7 = VectorSignedToFloat(param_8,(byte)(in_fpscr >> 0x16) & 3);
    Gun::Gun(this_01,param_2,param_5,0xf,param_4,param_7,param_6,uVar7,uVar4,0,uVar6,0,0,0);
    Gun::setIndex(this_01,param_1);
    *(undefined4 *)(this_01 + 0x5c) = 8;
    Gun::setPlayerGun(this_01,true);
    if (((param_1 == 0x30 || param_1 == 0xe0) || (param_1 == 0xb5)) &&
       (this_01[0xa4] = (Gun)0x1, param_1 == 0xe0)) {
      this_01[0xa5] = (Gun)0x1;
    }
    this_00 = operator_new(0xb0);
    ObjectGun::ObjectGun(this_00,param_2,this_01,*(int *)(&DAT_00252d1c + param_1 * 4),1000,this);
    break;
  case 9:
  case 10:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
    break;
  case 0xb:
    this_01 = operator_new(0x114);
    Gun::Gun(this_01,param_2,param_5,10,param_4,param_7,param_6,0x40000000,0,0,0,0,0,0);
    Gun::setIndex(this_01,param_1);
    *(undefined4 *)(this_01 + 0x5c) = 0xb;
    Gun::setPlayerGun(this_01,true);
    this_00 = operator_new(0xd4);
    MineGun::MineGun((MineGun *)this_00,this_01,*(int *)(&DAT_00252d1c + param_1 * 4),1,0xb,this);
LAB_000cd768:
    Globals::addSoundResourceToList(Globals::globals,*(int *)(&DAT_002530c0 + param_1 * 4));
    break;
  default:
    this_01 = (Gun *)0x0;
    switch(param_3) {
    case 0x22:
      goto switchD_000cd25e_caseD_6;
    case 0x23:
      if (param_1 == 0xb5) {
        uVar4 = 0;
        uVar6 = 0xc3960000;
      }
      else if (param_1 == 0x30) {
        uVar4 = 0x42a00000;
      }
      else {
        uVar4 = 0;
      }
      this_01 = operator_new(0x114);
      uVar7 = VectorSignedToFloat(param_8,(byte)(in_fpscr >> 0x16) & 3);
      Gun::Gun(this_01,param_2,param_5,0xf,param_4,param_7,param_6,uVar7,uVar4,0,uVar6,0,0,0);
      Gun::setIndex(this_01,param_1);
      *(undefined4 *)(this_01 + 0x5c) = 0x23;
      Gun::setPlayerGun(this_01,true);
      this_00 = operator_new(0xb0);
      ObjectGun::ObjectGun(this_00,param_2,this_01,*(int *)(&DAT_00252d1c + param_1 * 4),1000,this);
      break;
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x29:
      break;
    case 0x27:
      this_01 = operator_new(0x114);
      Gun::Gun(this_01,param_2,0,3,param_4,param_7,param_6,0x40000000,0,0,0,0,0,0);
      Gun::setIndex(this_01,param_1);
      *(undefined4 *)(this_01 + 0x5c) = 0x27;
      Gun::setPlayerGun(this_01,true);
      this_00 = operator_new(0xb4);
      SentryGun::SentryGun
                ((SentryGun *)this_00,this_01,*(int *)(&DAT_00252d1c + param_1 * 4),1,0x27,this);
      goto LAB_000cd768;
    case 0x28:
      goto switchD_000cd25e_caseD_4;
    case 0x2a:
      this_01 = operator_new(0x114);
      uVar6 = VectorSignedToFloat(param_8,(byte)(in_fpscr >> 0x16) & 3);
      Gun::Gun(this_01,param_2,param_5,1,param_4,1,param_6,uVar6,0,0,0,0,0,0);
      Gun::setIndex(this_01,param_1);
      *(undefined4 *)(this_01 + 0x5c) = 0x2a;
      Gun::setPlayerGun(this_01,true);
      this_00 = operator_new(300);
      BombGun::BombGun((BombGun *)this_00,this_01,*(uint *)(&DAT_00252d1c + param_1 * 4),1,0x2a,
                       false,this);
      goto LAB_000cd768;
    default:
      this_01 = (Gun *)0x0;
    }
  }
  switch(param_1) {
  case 0x29:
    Globals::addSoundResourceToList(Globals::globals,0xf);
  case 0x2a:
    Globals::addSoundResourceToList(Globals::globals,0x10);
  case 0x2b:
    Globals::addSoundResourceToList(Globals::globals,0x11);
  case 0x2c:
    Globals::addSoundResourceToList(Globals::globals,0xe);
  case 0x2d:
    Globals::addSoundResourceToList(Globals::globals,0xd);
  case 0x2e:
    Globals::addSoundResourceToList(Globals::globals,0xc);
  default:
    Gun::setLevel(this_01,this);
    piVar5 = *(int **)(this + 0xe4);
    if (piVar5 == (int *)0x0) {
      piVar5 = operator_new(0xc);
      puVar2 = operator_new__(4);
      piVar5[1] = (int)puVar2;
      piVar5[2] = 1;
      *puVar2 = 0;
      *piVar5 = 0;
      *(int **)(this + 0xe4) = piVar5;
    }
    piVar5[2] = *piVar5 + 1;
    pvVar3 = realloc((void *)piVar5[1],(*piVar5 + 1) * 4);
    piVar5[1] = (int)pvVar3;
    *(ObjectGun **)((int)pvVar3 + *piVar5 * 4) = this_00;
    *piVar5 = piVar5[2];
    return this_01;
  }
}

// ===== Level::createStaticObject  @0x000cda54  (7056 bytes)
/* Level::createStaticObject(Waypoint*, int, bool) */

void __thiscall Level::createStaticObject(Level *this,Waypoint *param_1,int param_2,bool param_3)

{
  int iVar1;
  AEGeometry *pAVar2;
  Player *pPVar3;
  PlayerJunk *this_00;
  AEGeometry *pAVar4;
  void *pvVar5;
  undefined4 uVar6;
  FileRead *pFVar7;
  Array *pAVar8;
  String *pSVar9;
  AEGeometry *this_01;
  uint uVar10;
  AEGeometry *pAVar11;
  AEGeometry *pAVar12;
  AEGeometry *pAVar13;
  AEGeometry *pAVar14;
  AEGeometry *pAVar15;
  AEGeometry *pAVar16;
  int iVar17;
  Matrix *pMVar18;
  undefined4 *puVar19;
  BoundingAAB *pBVar20;
  ushort uVar21;
  code *pcVar22;
  int iVar23;
  float fVar24;
  int iVar25;
  uint in_fpscr;
  float extraout_s0;
  float fVar26;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s0_02;
  float extraout_s0_03;
  float extraout_s0_04;
  float extraout_s0_05;
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
  float extraout_s1_16;
  float extraout_s1_17;
  float extraout_s1_18;
  float extraout_s1_19;
  float extraout_s1_20;
  float extraout_s1_21;
  float extraout_s1_22;
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
  float extraout_s2_14;
  float extraout_s2_15;
  float extraout_s2_16;
  float extraout_s2_17;
  float extraout_s2_18;
  float extraout_s2_19;
  float extraout_s3;
  float extraout_s3_00;
  float extraout_s3_01;
  float extraout_s3_02;
  float fVar27;
  float extraout_s4;
  float extraout_s4_00;
  float extraout_s4_01;
  float extraout_s4_02;
  float extraout_s5;
  float extraout_s5_00;
  float extraout_s5_01;
  float extraout_s5_02;
  float extraout_s6;
  float extraout_s6_00;
  float extraout_s6_01;
  float extraout_s6_02;
  float extraout_s7;
  float extraout_s7_00;
  float extraout_s7_01;
  float extraout_s7_02;
  float extraout_s8;
  float extraout_s8_00;
  float extraout_s8_01;
  float extraout_s8_02;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  undefined8 uVar33;
  undefined4 uVar34;
  undefined4 uVar35;
  undefined4 uVar36;
  uint local_a4;
  uint local_9c [15];
  uint local_60;
  uint local_5c;
  uint local_58;
  int local_54;
  
  local_54 = __stack_chk_guard;
  if (param_1 == (Waypoint *)0x0) {
    iVar25 = 0;
    iVar23 = 0;
    fVar24 = 0.0;
  }
  else {
    iVar23 = *(int *)(param_1 + 0x120);
    iVar25 = *(int *)(param_1 + 0x124);
    fVar24 = *(float *)(param_1 + 0x128);
  }
  if (param_3) {
    iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
    iVar23 = iVar23 + iVar1 + -10000;
    iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
    iVar25 = iVar25 + iVar1 + -10000;
    iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
    fVar24 = (float)(iVar1 + (int)fVar24 + -10000);
  }
  if (param_2 == 0x4215) {
    iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
    uVar21 = 0x4217;
    if (iVar1 == 1) {
      uVar21 = 0x4216;
    }
    if (iVar1 == 0) {
      uVar21 = 0x4215;
    }
    pAVar2 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar2,uVar21,Globals::Canvas,false);
    pPVar3 = operator_new(0x114);
    Player::Player(pPVar3,1000,1,0,0,0);
    this_00 = operator_new(0x124);
    VectorSignedToFloat(iVar23,(byte)(in_fpscr >> 0x16) & 3);
    VectorSignedToFloat(iVar25,(byte)(in_fpscr >> 0x16) & 3);
    VectorSignedToFloat(fVar24,(byte)(in_fpscr >> 0x16) & 3);
    PlayerJunk::PlayerJunk(this_00,0x4215,pPVar3,pAVar2,fVar24,extraout_s1,extraout_s2);
    AEGeometry::rotate(*(AEGeometry **)(this_00 + 8),extraout_s0,extraout_s1_00,extraout_s2_00);
    goto LAB_000cdef0;
  }
  pAVar2 = operator_new(0xc0);
  iVar1 = 0x1a74;
  if (param_2 != 0x1a74) {
    iVar1 = 0x381b;
  }
  uVar21 = (ushort)param_2;
  if ((param_2 == 0x1a74 || param_2 == iVar1) || (param_2 == 0x1a76)) {
    AEGeometry::AEGeometry(pAVar2,Globals::Canvas);
  }
  else {
    AEGeometry::AEGeometry(pAVar2,uVar21,Globals::Canvas,false);
  }
  if (param_2 < 0x4220) {
    if (param_2 < 0x37a3) {
      iVar1 = 0x1a74;
      if (param_2 != 0x1a74) {
        iVar1 = 0x1a76;
      }
      if (param_2 != 0x1a74 && param_2 != iVar1) goto LAB_000ce236;
LAB_000cde6a:
      pPVar3 = operator_new(0x114);
      Player::Player(pPVar3,1000,100,0,0,0);
      this_00 = operator_new(0x164);
      fVar24 = (float)VectorSignedToFloat(fVar24,(byte)(in_fpscr >> 0x16) & 3);
      fVar26 = (float)VectorSignedToFloat(iVar25,(byte)(in_fpscr >> 0x16) & 3);
      VectorSignedToFloat(iVar23,(byte)(in_fpscr >> 0x16) & 3);
      PlayerTurret::PlayerTurret
                ((PlayerTurret *)this_00,param_2,pPVar3,pAVar2,fVar24,extraout_s1_03,fVar26);
      (**(code **)(*(int *)this_00 + 0x14))(this_00,this);
      pSVar9 = (String *)GameText::getText(Globals::gameText,0x682);
      AbyssEngine::String::operator=((String *)(this_00 + 0x18),pSVar9);
    }
    else {
      if (param_2 == 0x37a3) {
        iVar1 = Status::getLevel(Globals::status);
        if (iVar1 < 0x15) {
          iVar1 = Status::getLevel(Globals::status);
          iVar1 = iVar1 * 0xf + 0x14;
        }
        else {
          iVar1 = 0x140;
        }
        iVar17 = Status::gameWon(Globals::status);
        if (iVar17 == 0) {
          iVar17 = Status::getCurrentCampaignMission(Globals::status);
          iVar17 = iVar17 << 2;
        }
        else {
          iVar17 = 0xb4;
        }
        fVar27 = (float)VectorSignedToFloat((iVar17 + iVar1) * 5,(byte)(in_fpscr >> 0x16) & 3);
        fVar26 = (float)Globals::options._44_4_ + -0.5;
        pPVar3 = operator_new(0x114);
        Player::Player(pPVar3,0x1d4c,(int)(fVar27 + fVar26 * fVar27),0,0,0);
        this_00 = operator_new(0x1b4);
        uVar28 = VectorSignedToFloat(iVar23,(byte)(in_fpscr >> 0x16) & 3);
        uVar29 = VectorSignedToFloat(iVar25,(byte)(in_fpscr >> 0x16) & 3);
        uVar31 = VectorSignedToFloat(fVar24,(byte)(in_fpscr >> 0x16) & 3);
        uVar34 = 0;
        uVar6 = uVar28;
        uVar30 = uVar29;
        uVar32 = uVar31;
        PlayerFixedObject::PlayerFixedObject
                  ((PlayerFixedObject *)this_00,0x37a3,8,pPVar3,(AEGeometry *)0x0,fVar24,
                   extraout_s1_07,extraout_s2_04);
        pcVar22 = *(code **)(*(int *)this_00 + 8);
        pAVar2 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar2,0x37a3,Globals::Canvas,false);
        (*pcVar22)(this_00,pAVar2,0xffffffff,0,uVar34,uVar6,uVar30,uVar32);
        pAVar2 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar2,0x37a4,Globals::Canvas,false);
        pAVar4 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar4,0x37a5,Globals::Canvas,false);
        AEGeometry::addChild(*(AEGeometry **)(this_00 + 8),*(uint *)(pAVar2 + 0xc));
        AEGeometry::addChild(*(AEGeometry **)(this_00 + 8),*(uint *)(pAVar4 + 0xc));
        pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar4);
        operator_delete(pvVar5);
        pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar2);
        operator_delete(pvVar5);
        iVar23 = PlayerFixedObject::setWreckedMeshId((PlayerFixedObject *)this_00,0x37a6);
        pAVar2 = (AEGeometry *)0x3ea;
LAB_000ce530:
        pAVar8 = (Array *)getBoundingVolume(iVar23,pAVar2);
        PlayerFixedObject::setBV((PlayerFixedObject *)this_00,pAVar8);
        (**(code **)(*(int *)this_00 + 0x48))(this_00,uVar28,uVar29,uVar31);
        goto LAB_000cdef0;
      }
      if (param_2 == 0x381b) goto LAB_000cde6a;
      if (param_2 != 0x381d) goto LAB_000ce236;
      pPVar3 = operator_new(0x114);
      Player::Player(pPVar3,1000,100,0,0,0);
      this_00 = operator_new(0x164);
      fVar24 = (float)VectorSignedToFloat(fVar24,(byte)(in_fpscr >> 0x16) & 3);
      fVar26 = (float)VectorSignedToFloat(iVar25,(byte)(in_fpscr >> 0x16) & 3);
      VectorSignedToFloat(iVar23,(byte)(in_fpscr >> 0x16) & 3);
      PlayerTurret::PlayerTurret
                ((PlayerTurret *)this_00,0x381d,pPVar3,pAVar2,fVar24,extraout_s1_02,fVar26);
      (**(code **)(*(int *)this_00 + 0x14))(this_00,this);
      pSVar9 = (String *)GameText::getText(Globals::gameText,0x681);
      AbyssEngine::String::operator=((String *)(this_00 + 0x18),pSVar9);
      *(PlayerTurret *)(this_00 + 0x21) = (PlayerTurret)0x0;
    }
    *(undefined4 *)(this_00 + 0x4c) = 0;
    goto LAB_000cdef0;
  }
  if (param_2 < 0x4a6a) {
    if (param_2 - 0x49c0U < 3) goto LAB_000cde6a;
    if (param_2 == 0x4220) {
      pPVar3 = operator_new(0x114);
      Player::Player(pPVar3,1000,9999999,0,0,0);
      this_00 = operator_new(0x1b4);
      uVar28 = VectorSignedToFloat(iVar23,(byte)(in_fpscr >> 0x16) & 3);
      uVar29 = VectorSignedToFloat(iVar25,(byte)(in_fpscr >> 0x16) & 3);
      uVar31 = VectorSignedToFloat(fVar24,(byte)(in_fpscr >> 0x16) & 3);
      uVar34 = 0;
      uVar6 = uVar28;
      uVar30 = uVar29;
      uVar32 = uVar31;
      PlayerFixedObject::PlayerFixedObject
                ((PlayerFixedObject *)this_00,0x4220,0,pPVar3,(AEGeometry *)0x0,fVar24,
                 extraout_s1_01,extraout_s2_01);
      pcVar22 = *(code **)(*(int *)this_00 + 8);
      pAVar2 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar2,0x4220,Globals::Canvas,false);
      (*pcVar22)(this_00,pAVar2,0xffffffff,0,uVar34,uVar6,uVar30,uVar32);
      pAVar2 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar2,0x4221,Globals::Canvas,false);
      pAVar4 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar4,0x4222,Globals::Canvas,false);
      AEGeometry::addChild(*(AEGeometry **)(this_00 + 8),*(uint *)(pAVar2 + 0xc));
      AEGeometry::addChild(*(AEGeometry **)(this_00 + 8),*(uint *)(pAVar4 + 0xc));
      pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar4);
      operator_delete(pvVar5);
      pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar2);
      operator_delete(pvVar5);
      uVar6 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(*(int *)(this_00 + 8) + 0xc));
      uVar33 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (Globals::Canvas,*(uint *)(*(int *)(this_00 + 8) + 0xc));
      AbyssEngine::Transform::Update
                (CONCAT44((int)((ulonglong)uVar33 >> 0x20),uVar6),
                 SUB41(*(undefined4 *)((int)uVar33 + 0xf8),0));
      uVar6 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(*(int *)(this_00 + 8) + 0x14));
      uVar33 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (Globals::Canvas,*(uint *)(*(int *)(this_00 + 8) + 0x14));
      AbyssEngine::Transform::Update
                (CONCAT44((int)((ulonglong)uVar33 >> 0x20),uVar6),
                 SUB41(*(undefined4 *)((int)uVar33 + 0xf8),0));
      uVar6 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(*(int *)(this_00 + 8) + 0x10));
      uVar33 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (Globals::Canvas,*(uint *)(*(int *)(this_00 + 8) + 0x10));
      AbyssEngine::Transform::Update
                (CONCAT44((int)((ulonglong)uVar33 >> 0x20),uVar6),
                 SUB41(*(undefined4 *)((int)uVar33 + 0xf8),0));
      *(PlayerFixedObject *)(this_00 + 0x6c) = (PlayerFixedObject)0x1;
      PlayerFixedObject::setWreckedMeshId((PlayerFixedObject *)this_00,0x37a6);
      pFVar7 = operator_new(1);
      FileRead::FileRead(pFVar7);
      pAVar8 = (Array *)FileRead::loadSpacePoints(pFVar7,7,-1);
      pvVar5 = (void *)FileRead::~FileRead(pFVar7);
      operator_delete(pvVar5);
      iVar23 = KIPlayer::setSpacePoints((KIPlayer *)this_00,pAVar8);
      pAVar2 = (AEGeometry *)0x3eb;
      goto LAB_000ce530;
    }
  }
  else {
    if (param_2 == 0x4a88) {
      pPVar3 = operator_new(0x114);
      Player::Player(pPVar3,1000,9999999,0,0,0);
      Player::setVulnerable(pPVar3,false);
      this_00 = operator_new(0x1b4);
      uVar6 = VectorSignedToFloat(iVar23,(byte)(in_fpscr >> 0x16) & 3);
      uVar30 = VectorSignedToFloat(iVar25,(byte)(in_fpscr >> 0x16) & 3);
      uVar32 = VectorSignedToFloat(fVar24,(byte)(in_fpscr >> 0x16) & 3);
      PlayerFixedObject::PlayerFixedObject
                ((PlayerFixedObject *)this_00,0x4a88,3,pPVar3,(AEGeometry *)0x0,fVar24,
                 extraout_s1_05,extraout_s2_02);
      pAVar2 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar2,0x4a88,Globals::Canvas,false);
      pAVar4 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar4,0x4a8d,Globals::Canvas,false);
      pAVar11 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar11,0x4a8c,Globals::Canvas,false);
      pAVar12 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar12,0x4a89,Globals::Canvas,false);
      pAVar13 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar13,0x4a8a,Globals::Canvas,false);
      pAVar14 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar14,0x4a8b,Globals::Canvas,false);
      AEGeometry::addChild(pAVar2,*(uint *)(pAVar4 + 0xc));
      AEGeometry::addChild(pAVar2,*(uint *)(pAVar11 + 0xc));
      AEGeometry::addChild(pAVar2,*(uint *)(pAVar12 + 0xc));
      pAVar15 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar15,0x4a8e,Globals::Canvas,false);
      pAVar16 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar16,0x4a90,Globals::Canvas,false);
      this_01 = operator_new(0xc0);
      AEGeometry::AEGeometry(this_01,0x4a8f,Globals::Canvas,false);
      AEGeometry::addChild(pAVar2,*(uint *)(pAVar15 + 0xc));
      AEGeometry::addChild(pAVar2,*(uint *)(pAVar16 + 0xc));
      AEGeometry::addChild(pAVar2,*(uint *)(this_01 + 0xc));
      pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar15);
      operator_delete(pvVar5);
      pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar16);
      operator_delete(pvVar5);
      pvVar5 = (void *)AEGeometry::~AEGeometry(this_01);
      operator_delete(pvVar5);
      AEGeometry::addChild(pAVar2,*(uint *)(pAVar13 + 0xc));
      AEGeometry::addChild(pAVar2,*(uint *)(pAVar14 + 0xc));
      pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar4);
      operator_delete(pvVar5);
      pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar11);
      operator_delete(pvVar5);
      pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar12);
      operator_delete(pvVar5);
      pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar13);
      operator_delete(pvVar5);
      pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar14);
      operator_delete(pvVar5);
      (**(code **)(*(int *)this_00 + 8))(this_00,pAVar2,0xffffffff,0);
      *(PlayerFixedObject *)(this_00 + 0x6c) = (PlayerFixedObject)0x1;
      (**(code **)(*(int *)this_00 + 0x48))(this_00,uVar6,uVar30,uVar32);
      PlayerFixedObject::setWreckedMeshId((PlayerFixedObject *)this_00,0x4a88);
      pFVar7 = operator_new(1);
      FileRead::FileRead(pFVar7);
      pAVar8 = (Array *)FileRead::loadSpacePoints(pFVar7,1,-1);
      pvVar5 = (void *)FileRead::~FileRead(pFVar7);
      operator_delete(pvVar5);
      iVar23 = KIPlayer::setSpacePoints((KIPlayer *)this_00,pAVar8);
      pAVar8 = (Array *)getBoundingVolume(iVar23,(AEGeometry *)0x7d0);
      PlayerFixedObject::setBV((PlayerFixedObject *)this_00,pAVar8);
      *(undefined4 *)(*(int *)(this_00 + 4) + 0x40) = 0;
      goto LAB_000cdef0;
    }
    if (param_2 == 0x4a6a) {
      pPVar3 = operator_new(0x114);
      Player::Player(pPVar3,1000,9999999,0,0,0);
      this_00 = operator_new(300);
      VectorSignedToFloat(iVar23,(byte)(in_fpscr >> 0x16) & 3);
      fVar24 = (float)VectorSignedToFloat(fVar24,(byte)(in_fpscr >> 0x16) & 3);
      fVar26 = (float)VectorSignedToFloat(iVar25,(byte)(in_fpscr >> 0x16) & 3);
      PlayerStatic::PlayerStatic((PlayerStatic *)this_00,0x4a6a,pAVar2,fVar24,extraout_s1_04,fVar26)
      ;
      goto LAB_000cdef0;
    }
  }
LAB_000ce236:
  this_00 = (PlayerJunk *)0x0;
  if (param_2 < 0x4961) {
    uVar10 = param_2 - 0x493e;
    if (0x1f < uVar10) {
LAB_000ce8a8:
      if (param_2 == 0x4260) {
        pPVar3 = operator_new(0x114);
        Player::Player(pPVar3,1000,9999999,0,0,0);
        this_00 = operator_new(0x1b4);
        uVar28 = VectorSignedToFloat(iVar23,(byte)(in_fpscr >> 0x16) & 3);
        uVar29 = VectorSignedToFloat(iVar25,(byte)(in_fpscr >> 0x16) & 3);
        uVar31 = VectorSignedToFloat(fVar24,(byte)(in_fpscr >> 0x16) & 3);
        uVar34 = 0;
        uVar6 = uVar28;
        uVar30 = uVar29;
        uVar32 = uVar31;
        PlayerFixedObject::PlayerFixedObject
                  ((PlayerFixedObject *)this_00,0x4260,0,pPVar3,(AEGeometry *)0x0,fVar24,
                   extraout_s1_13,extraout_s2_10);
        pcVar22 = *(code **)(*(int *)this_00 + 8);
        pAVar2 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar2,0x4260,Globals::Canvas,false);
        (*pcVar22)(this_00,pAVar2,0xffffffff,0,uVar34,uVar6,uVar30,uVar32);
        *(PlayerFixedObject *)(this_00 + 0x6c) = (PlayerFixedObject)0x1;
        (**(code **)(*(int *)this_00 + 0x48))(this_00,uVar28,uVar29,uVar31);
        PlayerFixedObject::setWreckedMeshId((PlayerFixedObject *)this_00,0x477c);
        pFVar7 = operator_new(1);
        FileRead::FileRead(pFVar7);
        iVar23 = 2;
      }
      else {
        this_00 = (PlayerJunk *)0x0;
        if (param_2 != 0x4299) goto LAB_000cdef0;
        iVar1 = Status::getLevel(Globals::status);
        if (iVar1 < 0x15) {
          iVar1 = Status::getLevel(Globals::status);
          iVar1 = iVar1 * 0xf + 100;
        }
        else {
          iVar1 = 400;
        }
        iVar17 = Status::gameWon(Globals::status);
        if (iVar17 == 0) {
          iVar17 = Status::getCurrentCampaignMission(Globals::status);
          iVar17 = iVar17 << 2;
        }
        else {
          iVar17 = 0xb4;
        }
        fVar27 = (float)VectorSignedToFloat((iVar17 + iVar1) * 5,(byte)(in_fpscr >> 0x16) & 3);
        fVar26 = (float)Globals::options._44_4_ + -0.5;
        pPVar3 = operator_new(0x114);
        Player::Player(pPVar3,1000,(int)(fVar27 + fVar26 * fVar27),0,0,0);
        this_00 = operator_new(0x1b4);
        uVar6 = VectorSignedToFloat(iVar23,(byte)(in_fpscr >> 0x16) & 3);
        uVar30 = VectorSignedToFloat(iVar25,(byte)(in_fpscr >> 0x16) & 3);
        uVar32 = VectorSignedToFloat(fVar24,(byte)(in_fpscr >> 0x16) & 3);
        PlayerFixedObject::PlayerFixedObject
                  ((PlayerFixedObject *)this_00,0x4299,3,pPVar3,(AEGeometry *)0x0,fVar24,
                   extraout_s1_14,extraout_s2_11);
        pAVar2 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar2,0x4299,Globals::Canvas,false);
        local_60 = 0xffffffff;
        AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,&local_60);
        iVar23 = 0;
        AbyssEngine::PaintCanvas::TransformAddMesh(Globals::Canvas,local_60,0x429f,false);
        AEGeometry::addChild(pAVar2,local_60);
        uVar10 = 0xffffffff;
        local_a4 = 0xffffffff;
        do {
          local_5c = 0xffffffff;
          local_58 = 0xffffffff;
          AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,&local_58);
          AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,&local_5c);
          AbyssEngine::PaintCanvas::TransformAddMesh(Globals::Canvas,local_58,0x429c,false);
          AbyssEngine::PaintCanvas::TransformAddMesh(Globals::Canvas,local_5c,0x429d,false);
          pMVar18 = (Matrix *)AbyssEngine::PaintCanvas::TransformGetLocal(Globals::Canvas,local_58);
          AbyssEngine::AEMath::MatrixSetTranslation
                    ((AEMath *)local_9c,pMVar18,extraout_s0_00,extraout_s1_15,extraout_s2_12);
          pMVar18 = (Matrix *)AbyssEngine::PaintCanvas::TransformGetLocal(Globals::Canvas,local_5c);
          AbyssEngine::AEMath::MatrixSetTranslation
                    ((AEMath *)local_9c,pMVar18,extraout_s0_01,extraout_s1_16,extraout_s2_13);
          if (uVar10 == 0xffffffff) {
            local_a4 = local_5c;
            uVar10 = local_58;
          }
          else {
            AbyssEngine::PaintCanvas::TransformAddChild(Globals::Canvas,uVar10,local_58);
            AbyssEngine::PaintCanvas::TransformAddChild(Globals::Canvas,local_a4,local_5c);
          }
          iVar23 = iVar23 + 1;
        } while (iVar23 != 3);
        AEGeometry::addChild(pAVar2,uVar10);
        local_9c[0] = 0xffffffff;
        AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,local_9c);
        AbyssEngine::PaintCanvas::TransformAddMesh(Globals::Canvas,local_9c[0],0x429e,false);
        AEGeometry::addChild(pAVar2,local_9c[0]);
        local_5c = CONCAT22(local_5c._2_2_,0x429a);
        local_58 = 35000;
        AEGeometry::setLodMeshes(pAVar2,(ushort *)&local_5c,(int *)&local_58,1);
        AEGeometry::setLodChildTransform(pAVar2,local_a4);
        (**(code **)(*(int *)this_00 + 8))(this_00,pAVar2,0xffffffff,0);
        *(PlayerFixedObject *)(this_00 + 0x6c) = (PlayerFixedObject)0x1;
        *(PlayerFixedObject *)(this_00 + 0x3c) = (PlayerFixedObject)0x1;
        pAVar8 = operator_new(0xc);
        puVar19 = operator_new__(4);
        *(undefined4 **)(pAVar8 + 4) = puVar19;
        *(undefined4 *)(pAVar8 + 8) = 1;
        *puVar19 = 0;
        *(undefined4 *)pAVar8 = 0;
        ArraySetLength<BoundingVolume*>(2,pAVar8);
        pBVar20 = operator_new(0x2c);
        BoundingAAB::BoundingAAB
                  (pBVar20,extraout_s0_02,extraout_s1_17,extraout_s2_14,extraout_s3,extraout_s4,
                   extraout_s5,extraout_s6,extraout_s7,extraout_s8);
        **(undefined4 **)(pAVar8 + 4) = pBVar20;
        pBVar20 = operator_new(0x2c);
        uVar28 = 0;
        uVar29 = 0xc1600000;
        uVar31 = 0xc2c40000;
        uVar34 = 0x458ca000;
        uVar35 = 0x44afa000;
        uVar36 = 0x460a7000;
        BoundingAAB::BoundingAAB
                  (pBVar20,extraout_s0_03,extraout_s1_18,extraout_s2_15,extraout_s3_00,
                   extraout_s4_00,extraout_s5_00,extraout_s6_00,extraout_s7_00,extraout_s8_00);
        *(BoundingAAB **)(*(int *)(pAVar8 + 4) + 4) = pBVar20;
        PlayerFixedObject::setBV((PlayerFixedObject *)this_00,pAVar8);
        (**(code **)(*(int *)this_00 + 0x48))
                  (this_00,uVar6,uVar30,uVar32,uVar28,uVar29,uVar31,uVar34,uVar35,uVar36);
        PlayerFixedObject::setWreckedMeshId((PlayerFixedObject *)this_00,0x477c);
        *(undefined4 *)(this_00 + 0x24) = 3;
        pFVar7 = operator_new(1);
        FileRead::FileRead(pFVar7);
        iVar23 = 4;
      }
LAB_000cf67c:
      pAVar8 = (Array *)FileRead::loadSpacePoints(pFVar7,iVar23,-1);
      pvVar5 = (void *)FileRead::~FileRead(pFVar7);
      operator_delete(pvVar5);
      KIPlayer::setSpacePoints((KIPlayer *)this_00,pAVar8);
      goto LAB_000cdef0;
    }
    if ((1 << (uVar10 & 0xff) & 0x1249U) == 0) {
      if (uVar10 == 0x10) {
        iVar1 = Status::getLevel(Globals::status);
        if (iVar1 < 0x15) {
          iVar1 = Status::getLevel(Globals::status);
          iVar1 = iVar1 * 0xf + 100;
        }
        else {
          iVar1 = 400;
        }
        iVar17 = Status::gameWon(Globals::status);
        if (iVar17 == 0) {
          iVar17 = Status::getCurrentCampaignMission(Globals::status);
          iVar17 = iVar17 << 2;
        }
        else {
          iVar17 = 0xb4;
        }
        fVar27 = (float)VectorSignedToFloat((iVar17 + iVar1) * 5,(byte)(in_fpscr >> 0x16) & 3);
        fVar26 = (float)Globals::options._44_4_ + -0.5;
        pPVar3 = operator_new(0x114);
        Player::Player(pPVar3,1000,(int)(fVar27 + fVar26 * fVar27),0,0,0);
        this_00 = operator_new(0x1b4);
        uVar6 = VectorSignedToFloat(iVar23,(byte)(in_fpscr >> 0x16) & 3);
        uVar30 = VectorSignedToFloat(iVar25,(byte)(in_fpscr >> 0x16) & 3);
        uVar32 = VectorSignedToFloat(fVar24,(byte)(in_fpscr >> 0x16) & 3);
        PlayerFixedObject::PlayerFixedObject
                  ((PlayerFixedObject *)this_00,0x494e,3,pPVar3,(AEGeometry *)0x0,fVar24,
                   extraout_s1_20,extraout_s2_17);
        pAVar2 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar2,0x4a80,Globals::Canvas,false);
        pAVar4 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar4,0x494e,Globals::Canvas,false);
        pAVar11 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar11,0x4a81,Globals::Canvas,false);
        pAVar12 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar12,0x4a82,Globals::Canvas,false);
        pAVar13 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar13,0x4a83,Globals::Canvas,false);
        pAVar14 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar14,0x4a84,Globals::Canvas,false);
        AEGeometry::addChild(pAVar2,*(uint *)(pAVar4 + 0xc));
        AEGeometry::addChild(pAVar4,*(uint *)(pAVar11 + 0xc));
        AEGeometry::addChild(pAVar4,*(uint *)(pAVar12 + 0xc));
        AEGeometry::addChild(pAVar4,*(uint *)(pAVar13 + 0xc));
        AEGeometry::addChild(pAVar4,*(uint *)(pAVar14 + 0xc));
        pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar4);
        operator_delete(pvVar5);
        pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar11);
        operator_delete(pvVar5);
        pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar12);
        operator_delete(pvVar5);
        pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar13);
        operator_delete(pvVar5);
        pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar14);
        operator_delete(pvVar5);
        (**(code **)(*(int *)this_00 + 8))(this_00,pAVar2,0xffffffff,0);
        *(PlayerFixedObject *)(this_00 + 0x6c) = (PlayerFixedObject)0x1;
        *(PlayerFixedObject *)(this_00 + 0x3c) = (PlayerFixedObject)0x1;
        pAVar8 = operator_new(0xc);
        puVar19 = operator_new__(4);
        *(undefined4 **)(pAVar8 + 4) = puVar19;
        *(undefined4 *)(pAVar8 + 8) = 1;
        *puVar19 = 0;
        *(undefined4 *)pAVar8 = 0;
        ArraySetLength<BoundingVolume*>(2,pAVar8);
        pBVar20 = operator_new(0x2c);
        BoundingAAB::BoundingAAB
                  (pBVar20,extraout_s0_04,extraout_s1_21,extraout_s2_18,extraout_s3_01,
                   extraout_s4_01,extraout_s5_01,extraout_s6_01,extraout_s7_01,extraout_s8_01);
        **(undefined4 **)(pAVar8 + 4) = pBVar20;
        pBVar20 = operator_new(0x2c);
        uVar28 = 0;
        uVar29 = 0xc1600000;
        uVar31 = 0xc2c40000;
        uVar34 = 0x458ca000;
        uVar35 = 0x44afa000;
        uVar36 = 0x460a7000;
        BoundingAAB::BoundingAAB
                  (pBVar20,extraout_s0_05,extraout_s1_22,extraout_s2_19,extraout_s3_02,
                   extraout_s4_02,extraout_s5_02,extraout_s6_02,extraout_s7_02,extraout_s8_02);
        *(BoundingAAB **)(*(int *)(pAVar8 + 4) + 4) = pBVar20;
        PlayerFixedObject::setBV((PlayerFixedObject *)this_00,pAVar8);
        (**(code **)(*(int *)this_00 + 0x48))
                  (this_00,uVar6,uVar30,uVar32,uVar28,uVar29,uVar31,uVar34,uVar35,uVar36);
        PlayerFixedObject::setWreckedMeshId((PlayerFixedObject *)this_00,0x477c);
        pFVar7 = operator_new(1);
        FileRead::FileRead(pFVar7);
        iVar23 = 3;
        goto LAB_000cf67c;
      }
      if (uVar10 != 0x1f) goto LAB_000ce8a8;
      pPVar3 = operator_new(0x114);
      Player::Player(pPVar3,1000,9999999,0,0,0);
      this_00 = operator_new(0x1b4);
      uVar6 = VectorSignedToFloat(iVar23,(byte)(in_fpscr >> 0x16) & 3);
      uVar30 = VectorSignedToFloat(iVar25,(byte)(in_fpscr >> 0x16) & 3);
      uVar32 = VectorSignedToFloat(fVar24,(byte)(in_fpscr >> 0x16) & 3);
      PlayerFixedObject::PlayerFixedObject
                ((PlayerFixedObject *)this_00,0x495d,3,pPVar3,(AEGeometry *)0x0,fVar24,
                 extraout_s1_09,extraout_s2_06);
      pAVar2 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar2,0x5254,Globals::Canvas,false);
      pAVar4 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar4,0x5574,Globals::Canvas,false);
      pAVar11 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar11,0x563c,Globals::Canvas,false);
      pAVar12 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar12,0x495d,Globals::Canvas,false);
      pAVar13 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar13,0x495d,Globals::Canvas,false);
      pAVar14 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar14,0x495e,Globals::Canvas,false);
      pAVar15 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar15,0x495f,Globals::Canvas,false);
      pAVar16 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar16,0x4960,Globals::Canvas,false);
      AEGeometry::addChild(pAVar2,*(uint *)(pAVar16 + 0xc));
      AEGeometry::addChild(pAVar2,*(uint *)(pAVar4 + 0xc));
      AEGeometry::addChild(pAVar2,*(uint *)(pAVar11 + 0xc));
      AEGeometry::addChild(pAVar2,*(uint *)(pAVar12 + 0xc));
      AEGeometry::addChild(pAVar2,*(uint *)(pAVar13 + 0xc));
      AEGeometry::addChild(pAVar2,*(uint *)(pAVar14 + 0xc));
      AEGeometry::addChild(pAVar2,*(uint *)(pAVar15 + 0xc));
      pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar4);
      operator_delete(pvVar5);
      pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar11);
      operator_delete(pvVar5);
      pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar12);
      operator_delete(pvVar5);
      pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar13);
      operator_delete(pvVar5);
      pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar14);
      operator_delete(pvVar5);
      pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar15);
      operator_delete(pvVar5);
      pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar16);
      operator_delete(pvVar5);
      (**(code **)(*(int *)this_00 + 8))(this_00,pAVar2,0xffffffff,0);
      *(PlayerFixedObject *)(this_00 + 0x6c) = (PlayerFixedObject)0x1;
      (**(code **)(*(int *)this_00 + 0x48))(this_00,uVar6,uVar30,uVar32);
      PlayerFixedObject::setWreckedMeshId((PlayerFixedObject *)this_00,0x477c);
      pFVar7 = operator_new(1);
      FileRead::FileRead(pFVar7);
      pAVar8 = (Array *)FileRead::loadSpacePoints(pFVar7,6,-1);
      pvVar5 = (void *)FileRead::~FileRead(pFVar7);
      operator_delete(pvVar5);
      iVar23 = KIPlayer::setSpacePoints((KIPlayer *)this_00,pAVar8);
      pAVar2 = (AEGeometry *)0x6f;
    }
    else {
      pPVar3 = operator_new(0x114);
      Player::Player(pPVar3,1000,9999999,0,0,0);
      Player::setVulnerable(pPVar3,false);
      this_00 = operator_new(0x1b4);
      uVar6 = VectorSignedToFloat(iVar23,(byte)(in_fpscr >> 0x16) & 3);
      uVar30 = VectorSignedToFloat(iVar25,(byte)(in_fpscr >> 0x16) & 3);
      uVar32 = VectorSignedToFloat(fVar24,(byte)(in_fpscr >> 0x16) & 3);
      PlayerFixedObject::PlayerFixedObject
                ((PlayerFixedObject *)this_00,param_2,3,pPVar3,(AEGeometry *)0x0,fVar24,
                 extraout_s1_06,extraout_s2_03);
      pAVar2 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar2,uVar21,Globals::Canvas,false);
      pAVar4 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar4,uVar21 + 2,Globals::Canvas,false);
      pAVar11 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar11,uVar21 + 1,Globals::Canvas,false);
      AEGeometry::addChild(pAVar2,*(uint *)(pAVar4 + 0xc));
      AEGeometry::addChild(pAVar2,*(uint *)(pAVar11 + 0xc));
      if ((param_2 == 0x494a) &&
         (iVar23 = Status::getCurrentCampaignMission(Globals::status), iVar23 == 0x91)) {
        pAVar12 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar12,0x494d,Globals::Canvas,false);
        AEGeometry::addChild(pAVar2,*(uint *)(pAVar12 + 0xc));
        pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar12);
        operator_delete(pvVar5);
      }
      pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar4);
      operator_delete(pvVar5);
      pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar11);
      operator_delete(pvVar5);
      (**(code **)(*(int *)this_00 + 8))(this_00,pAVar2,0xffffffff,0);
      *(PlayerFixedObject *)(this_00 + 0x6c) = (PlayerFixedObject)0x1;
      iVar23 = (**(code **)(*(int *)this_00 + 0x48))(this_00,uVar6,uVar30,uVar32);
      pAVar2 = (AEGeometry *)0x7d1;
    }
  }
  else if (param_2 < 0x4974) {
    if (param_2 != 0x4961) {
      if (param_2 == 0x4962) {
        pPVar3 = operator_new(0x114);
        Player::Player(pPVar3,0,9999999,0,0,0);
        this_00 = operator_new(0x1b4);
        uVar28 = VectorSignedToFloat(iVar23,(byte)(in_fpscr >> 0x16) & 3);
        uVar29 = VectorSignedToFloat(iVar25,(byte)(in_fpscr >> 0x16) & 3);
        uVar31 = VectorSignedToFloat(fVar24,(byte)(in_fpscr >> 0x16) & 3);
        uVar34 = 0;
        uVar6 = uVar28;
        uVar30 = uVar29;
        uVar32 = uVar31;
        PlayerFixedObject::PlayerFixedObject
                  ((PlayerFixedObject *)this_00,0x4962,2,pPVar3,(AEGeometry *)0x0,fVar24,
                   extraout_s1_10,extraout_s2_07);
        pcVar22 = *(code **)(*(int *)this_00 + 8);
        pAVar2 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar2,0x4962,Globals::Canvas,false);
        (*pcVar22)(this_00,pAVar2,0xffffffff,0,uVar34,uVar6,uVar30,uVar32);
        *(PlayerFixedObject *)(this_00 + 0x6c) = (PlayerFixedObject)0x0;
        (**(code **)(*(int *)this_00 + 0x48))(this_00,uVar28,uVar29,uVar31);
        PlayerFixedObject::setWreckedMeshId((PlayerFixedObject *)this_00,0x477c);
      }
      goto LAB_000cdef0;
    }
    pPVar3 = operator_new(0x114);
    Player::Player(pPVar3,1000,9999999,0,0,0);
    this_00 = operator_new(0x1b4);
    uVar6 = VectorSignedToFloat(iVar23,(byte)(in_fpscr >> 0x16) & 3);
    uVar30 = VectorSignedToFloat(iVar25,(byte)(in_fpscr >> 0x16) & 3);
    uVar32 = VectorSignedToFloat(fVar24,(byte)(in_fpscr >> 0x16) & 3);
    PlayerFixedObject::PlayerFixedObject
              ((PlayerFixedObject *)this_00,0x4961,2,pPVar3,(AEGeometry *)0x0,fVar24,extraout_s1_12,
               extraout_s2_09);
    pAVar2 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar2,0x4961,Globals::Canvas,false);
    pAVar4 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar4,0x498f,Globals::Canvas,false);
    AEGeometry::addChild(pAVar2,*(uint *)(pAVar4 + 0xc));
    pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar4);
    operator_delete(pvVar5);
    (**(code **)(*(int *)this_00 + 8))(this_00,pAVar2,0xffffffff,0);
    *(PlayerFixedObject *)(this_00 + 0x6c) = (PlayerFixedObject)0x1;
    (**(code **)(*(int *)this_00 + 0x48))(this_00,uVar6,uVar30,uVar32);
    PlayerFixedObject::setWreckedMeshId((PlayerFixedObject *)this_00,0x477c);
    *(undefined4 *)(this_00 + 0x24) = 2;
    pFVar7 = operator_new(1);
    FileRead::FileRead(pFVar7);
    pAVar8 = (Array *)FileRead::loadSpacePoints(pFVar7,2,-1);
    pvVar5 = (void *)FileRead::~FileRead(pFVar7);
    operator_delete(pvVar5);
    iVar23 = KIPlayer::setSpacePoints((KIPlayer *)this_00,pAVar8);
    pAVar2 = (AEGeometry *)0x7d3;
  }
  else if (param_2 == 0x4974) {
    iVar1 = Status::getLevel(Globals::status);
    if (iVar1 < 0x15) {
      iVar1 = Status::getLevel(Globals::status);
      iVar1 = iVar1 * 0xf + 100;
    }
    else {
      iVar1 = 400;
    }
    iVar17 = Status::gameWon(Globals::status);
    if (iVar17 == 0) {
      iVar17 = Status::getCurrentCampaignMission(Globals::status);
      iVar17 = iVar17 << 2;
    }
    else {
      iVar17 = 0xb4;
    }
    fVar27 = (float)VectorSignedToFloat((iVar17 + iVar1) * 5,(byte)(in_fpscr >> 0x16) & 3);
    fVar26 = (float)Globals::options._44_4_ + -0.5;
    pPVar3 = operator_new(0x114);
    Player::Player(pPVar3,0,(int)(fVar27 + fVar26 * fVar27),0,0,0);
    this_00 = operator_new(0x1b4);
    uVar6 = VectorSignedToFloat(iVar23,(byte)(in_fpscr >> 0x16) & 3);
    uVar30 = VectorSignedToFloat(iVar25,(byte)(in_fpscr >> 0x16) & 3);
    uVar32 = VectorSignedToFloat(fVar24,(byte)(in_fpscr >> 0x16) & 3);
    PlayerFixedObject::PlayerFixedObject
              ((PlayerFixedObject *)this_00,0x4974,0,pPVar3,(AEGeometry *)0x0,fVar24,extraout_s1_19,
               extraout_s2_16);
    pAVar2 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar2,0x4974,Globals::Canvas,false);
    pAVar4 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar4,0x4975,Globals::Canvas,false);
    pAVar11 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar11,0x4977,Globals::Canvas,false);
    pAVar12 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar12,0x4978,Globals::Canvas,false);
    pAVar13 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar13,0x4979,Globals::Canvas,false);
    pAVar14 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar14,0x497a,Globals::Canvas,false);
    pAVar15 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar15,0x4976,Globals::Canvas,false);
    AEGeometry::addChild(pAVar2,*(uint *)(pAVar4 + 0xc));
    AEGeometry::addChild(pAVar2,*(uint *)(pAVar11 + 0xc));
    AEGeometry::addChild(pAVar2,*(uint *)(pAVar12 + 0xc));
    AEGeometry::addChild(pAVar2,*(uint *)(pAVar13 + 0xc));
    AEGeometry::addChild(pAVar2,*(uint *)(pAVar14 + 0xc));
    AEGeometry::addChild(pAVar2,*(uint *)(pAVar15 + 0xc));
    pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar4);
    operator_delete(pvVar5);
    pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar11);
    operator_delete(pvVar5);
    pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar12);
    operator_delete(pvVar5);
    pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar13);
    operator_delete(pvVar5);
    pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar14);
    operator_delete(pvVar5);
    pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar15);
    operator_delete(pvVar5);
    (**(code **)(*(int *)this_00 + 8))(this_00,pAVar2,0xffffffff,0);
    *(PlayerFixedObject *)(this_00 + 0x6c) = (PlayerFixedObject)0x1;
    PlayerFixedObject::setWreckedMeshId((PlayerFixedObject *)this_00,0x494e);
    (**(code **)(*(int *)this_00 + 0x48))(this_00,uVar6,uVar30,uVar32);
    pFVar7 = operator_new(1);
    FileRead::FileRead(pFVar7);
    pAVar8 = (Array *)FileRead::loadSpacePoints(pFVar7,5,-1);
    pvVar5 = (void *)FileRead::~FileRead(pFVar7);
    operator_delete(pvVar5);
    iVar23 = KIPlayer::setSpacePoints((KIPlayer *)this_00,pAVar8);
    pAVar2 = (AEGeometry *)0x7d5;
  }
  else if (param_2 == 0x4a6b) {
    pPVar3 = operator_new(0x114);
    Player::Player(pPVar3,0,9999999,0,0,0);
    this_00 = operator_new(0x1b4);
    uVar6 = VectorSignedToFloat(iVar23,(byte)(in_fpscr >> 0x16) & 3);
    uVar30 = VectorSignedToFloat(iVar25,(byte)(in_fpscr >> 0x16) & 3);
    uVar32 = VectorSignedToFloat(fVar24,(byte)(in_fpscr >> 0x16) & 3);
    PlayerFixedObject::PlayerFixedObject
              ((PlayerFixedObject *)this_00,0x4a6b,1,pPVar3,(AEGeometry *)0x0,fVar24,extraout_s1_11,
               extraout_s2_08);
    pAVar2 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar2,0x4a6b,Globals::Canvas,false);
    pAVar4 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar4,0x4a6c,Globals::Canvas,false);
    AEGeometry::addChild(pAVar2,*(uint *)(pAVar4 + 0xc));
    pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar4);
    operator_delete(pvVar5);
    pAVar4 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar4,0x4a6d,Globals::Canvas,false);
    AEGeometry::addChild(pAVar2,*(uint *)(pAVar4 + 0xc));
    pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar4);
    operator_delete(pvVar5);
    (**(code **)(*(int *)this_00 + 8))(this_00,pAVar2,0xffffffff,0);
    *(PlayerFixedObject *)(this_00 + 0x6c) = (PlayerFixedObject)0x1;
    (**(code **)(*(int *)this_00 + 0x48))(this_00,uVar6,uVar30,uVar32);
    PlayerFixedObject::setWreckedMeshId((PlayerFixedObject *)this_00,0x477c);
    pFVar7 = operator_new(1);
    FileRead::FileRead(pFVar7);
    pAVar8 = (Array *)FileRead::loadSpacePoints(pFVar7,8,-1);
    pvVar5 = (void *)FileRead::~FileRead(pFVar7);
    operator_delete(pvVar5);
    iVar23 = KIPlayer::setSpacePoints((KIPlayer *)this_00,pAVar8);
    pAVar2 = (AEGeometry *)0x7d6;
  }
  else {
    if (param_2 != 0x5279) goto LAB_000cdef0;
    pPVar3 = operator_new(0x114);
    Player::Player(pPVar3,0,9999999,0,0,0);
    Player::setVulnerable(pPVar3,false);
    this_00 = operator_new(0x1b4);
    uVar28 = VectorSignedToFloat(iVar23,(byte)(in_fpscr >> 0x16) & 3);
    uVar29 = VectorSignedToFloat(iVar25,(byte)(in_fpscr >> 0x16) & 3);
    uVar31 = VectorSignedToFloat(fVar24,(byte)(in_fpscr >> 0x16) & 3);
    uVar34 = 0;
    uVar6 = uVar28;
    uVar30 = uVar29;
    uVar32 = uVar31;
    PlayerFixedObject::PlayerFixedObject
              ((PlayerFixedObject *)this_00,0x41a0,1,pPVar3,(AEGeometry *)0x0,fVar24,extraout_s1_08,
               extraout_s2_05);
    pAVar2 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar2,0x41a0,Globals::Canvas,false);
    (**(code **)(*(int *)this_00 + 8))(this_00,pAVar2,0xffffffff,0,uVar34,uVar6,uVar30,uVar32);
    *(PlayerFixedObject *)(this_00 + 0x6c) = (PlayerFixedObject)0x1;
    (**(code **)(*(int *)this_00 + 0x48))(this_00,uVar28,uVar29,uVar31);
    PlayerFixedObject::setWreckedMeshId((PlayerFixedObject *)this_00,0x5279);
    pFVar7 = operator_new(1);
    FileRead::FileRead(pFVar7);
    pAVar8 = (Array *)FileRead::loadSpacePoints(pFVar7,10,-1);
    pvVar5 = (void *)FileRead::~FileRead(pFVar7);
    operator_delete(pvVar5);
    iVar23 = KIPlayer::setSpacePoints((KIPlayer *)this_00,pAVar8);
    pAVar2 = (AEGeometry *)0x7d2;
  }
  pAVar8 = (Array *)getBoundingVolume(iVar23,pAVar2);
  PlayerFixedObject::setBV((PlayerFixedObject *)this_00,pAVar8);
LAB_000cdef0:
  (**(code **)(*(int *)this_00 + 0x14))(this_00,this);
  if (__stack_chk_guard - local_54 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_54);
  }
  return;
}

// ===== Level::createShip  @0x000cf83c  (2968 bytes)
/* Level::createShip(int, int, int, Waypoint*, bool, bool) */

PlayerFixedObject * __thiscall
Level::createShip(Level *this,int param_1,int param_2,int param_3,Waypoint *param_4,bool param_5,
                 bool param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  Player *this_00;
  Array *pAVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  BoundingAAB *pBVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  AEGeometry *pAVar16;
  void *pvVar17;
  code *pcVar18;
  PlayerFixedObject *this_01;
  uint in_fpscr;
  float fVar19;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s0_02;
  float extraout_s0_03;
  float extraout_s0_04;
  float extraout_s0_05;
  float extraout_s0_06;
  float extraout_s0_07;
  float extraout_s0_08;
  float extraout_s0_09;
  float extraout_s0_10;
  float extraout_s0_11;
  float extraout_s0_12;
  float extraout_s0_13;
  float extraout_s0_14;
  float extraout_s0_15;
  float extraout_s0_16;
  float extraout_s0_17;
  float extraout_s0_18;
  float extraout_s0_19;
  float extraout_s0_20;
  float extraout_s0_21;
  float extraout_s0_22;
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
  float extraout_s1_16;
  float extraout_s1_17;
  float extraout_s1_18;
  float extraout_s1_19;
  float extraout_s1_20;
  float extraout_s1_21;
  float extraout_s1_22;
  float extraout_s1_23;
  float extraout_s1_24;
  float fVar20;
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
  float extraout_s2_14;
  float extraout_s2_15;
  float extraout_s2_16;
  float extraout_s2_17;
  float extraout_s2_18;
  float extraout_s2_19;
  float extraout_s2_20;
  float extraout_s2_21;
  float extraout_s2_22;
  float extraout_s2_23;
  float extraout_s3;
  float extraout_s3_00;
  float extraout_s3_01;
  float extraout_s3_02;
  float extraout_s3_03;
  float extraout_s3_04;
  float extraout_s3_05;
  float extraout_s3_06;
  float extraout_s3_07;
  float extraout_s3_08;
  float extraout_s3_09;
  float extraout_s3_10;
  float extraout_s3_11;
  float extraout_s3_12;
  float extraout_s3_13;
  float extraout_s3_14;
  float extraout_s3_15;
  float extraout_s3_16;
  float extraout_s3_17;
  float extraout_s3_18;
  float extraout_s3_19;
  float extraout_s3_20;
  float extraout_s3_21;
  float extraout_s3_22;
  float extraout_s4;
  float extraout_s4_00;
  float extraout_s4_01;
  float extraout_s4_02;
  float extraout_s4_03;
  float extraout_s4_04;
  float extraout_s4_05;
  float extraout_s4_06;
  float extraout_s4_07;
  float extraout_s4_08;
  float extraout_s4_09;
  undefined4 uVar21;
  float extraout_s4_10;
  float extraout_s4_11;
  float extraout_s4_12;
  float extraout_s4_13;
  float extraout_s4_14;
  float extraout_s4_15;
  float extraout_s4_16;
  float extraout_s4_17;
  float extraout_s4_18;
  float extraout_s4_19;
  float extraout_s4_20;
  float extraout_s4_21;
  float extraout_s4_22;
  float extraout_s5;
  float extraout_s5_00;
  float extraout_s5_01;
  float extraout_s5_02;
  float extraout_s5_03;
  float extraout_s5_04;
  float extraout_s5_05;
  float extraout_s5_06;
  float extraout_s5_07;
  float extraout_s5_08;
  float extraout_s5_09;
  float extraout_s5_10;
  float extraout_s5_11;
  float extraout_s5_12;
  float extraout_s5_13;
  float extraout_s5_14;
  float extraout_s5_15;
  float extraout_s5_16;
  float extraout_s5_17;
  float extraout_s5_18;
  float extraout_s5_19;
  float extraout_s5_20;
  float extraout_s5_21;
  float extraout_s5_22;
  float extraout_s6;
  float extraout_s6_00;
  float extraout_s6_01;
  float extraout_s6_02;
  float extraout_s6_03;
  float extraout_s6_04;
  float extraout_s6_05;
  float extraout_s6_06;
  float extraout_s6_07;
  float extraout_s6_08;
  float extraout_s6_09;
  float extraout_s6_10;
  float extraout_s6_11;
  float extraout_s6_12;
  float extraout_s6_13;
  float extraout_s6_14;
  float extraout_s6_15;
  float extraout_s6_16;
  float extraout_s6_17;
  float extraout_s6_18;
  float extraout_s6_19;
  float extraout_s6_20;
  float extraout_s6_21;
  float extraout_s6_22;
  float extraout_s7;
  float extraout_s7_00;
  float extraout_s7_01;
  float extraout_s7_02;
  float extraout_s7_03;
  float extraout_s7_04;
  float extraout_s7_05;
  float extraout_s7_06;
  float extraout_s7_07;
  float extraout_s7_08;
  float extraout_s7_09;
  float extraout_s7_10;
  float extraout_s7_11;
  float extraout_s7_12;
  float extraout_s7_13;
  float extraout_s7_14;
  float extraout_s7_15;
  float extraout_s7_16;
  float extraout_s7_17;
  float extraout_s7_18;
  float extraout_s7_19;
  float extraout_s7_20;
  float extraout_s7_21;
  float extraout_s7_22;
  float extraout_s8;
  float extraout_s8_00;
  float extraout_s8_01;
  float extraout_s8_02;
  float extraout_s8_03;
  float extraout_s8_04;
  float extraout_s8_05;
  float extraout_s8_06;
  float extraout_s8_07;
  float extraout_s8_08;
  float extraout_s8_09;
  float extraout_s8_10;
  float extraout_s8_11;
  float extraout_s8_12;
  float extraout_s8_13;
  float extraout_s8_14;
  float extraout_s8_15;
  float extraout_s8_16;
  float extraout_s8_17;
  float extraout_s8_18;
  float extraout_s8_19;
  float extraout_s8_20;
  float extraout_s8_21;
  float extraout_s8_22;
  undefined3 in_stack_00000005;
  undefined4 uVar22;
  int local_58;
  int local_54;
  
  iVar1 = Status::getCurrentCampaignMission(Globals::status);
  if (param_4 == (Waypoint *)0x0) {
    local_54 = 0;
    local_58 = 0;
    iVar2 = 0;
  }
  else {
    local_58 = *(int *)(param_4 + 0x120);
    local_54 = *(int *)(param_4 + 0x124);
    iVar2 = *(int *)(param_4 + 0x128);
  }
  iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,40000);
  iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,40000);
  iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,40000);
  iVar6 = Status::getLevel(Globals::status);
  if (iVar6 < 0x15) {
    iVar6 = Status::getLevel(Globals::status);
  }
  else {
    iVar6 = 0x14;
  }
  iVar7 = Status::gameWon(Globals::status);
  iVar14 = iVar1 << 2;
  if (iVar7 != 0) {
    iVar14 = 0xb4;
  }
  iVar6 = iVar14 + iVar6 * 0xe + 0x14;
  if (param_3 == 0x33) {
    fVar20 = (float)VectorSignedToFloat(iVar6,(byte)(in_fpscr >> 0x16) & 3);
    fVar20 = fVar20 * 1.7;
LAB_000cf930:
    iVar6 = (int)fVar20;
  }
  else {
    if (param_3 == 0x31) {
      fVar19 = 17.0;
LAB_000cf924:
      fVar20 = (float)VectorSignedToFloat(iVar6,(byte)(in_fpscr >> 0x16) & 3);
      fVar20 = fVar20 * fVar19;
      goto LAB_000cf930;
    }
    if (param_3 == 0x2c) {
      fVar19 = 2.25;
      goto LAB_000cf924;
    }
  }
  if ((iVar1 - 0x31U < 8) && ((0x8fU >> (iVar1 - 0x31U & 0xff) & 1) != 0)) {
    iVar6 = 0x10e;
  }
  iVar7 = Status::getLevel(Globals::status);
  if (iVar7 < 0x15) {
    iVar7 = Status::getLevel(Globals::status);
  }
  else {
    iVar7 = 0x14;
  }
  iVar7 = iVar7 * 5 + 0x28;
  if (param_2 == 1) {
    iVar14 = 5;
    if (param_3 == 0xe) {
      iVar14 = 0x19;
    }
    iVar7 = iVar7 * 3;
    iVar6 = iVar14 * iVar6;
    iVar14 = 45000;
  }
  else {
    iVar14 = 15000;
  }
  fVar20 = (float)VectorSignedToFloat(iVar6,(byte)(in_fpscr >> 0x16) & 3);
  iVar6 = (int)(fVar20 + fVar20 * ((float)Globals::options._44_4_ + -0.5));
  if (iVar1 == 0x9a) {
    uVar8 = Status::inAlienOrbit(Globals::status);
    iVar6 = iVar6 << (uVar8 & param_1 == 9);
  }
  iVar1 = Status::hardCoreMode();
  this_00 = operator_new(0x114);
  iVar15 = 1000;
  if (iVar1 != 0) {
    iVar15 = 0x28a;
  }
  Player::Player(this_00,iVar15,iVar6,1,1,0);
  iVar3 = local_58 + -20000 + iVar3;
  iVar4 = local_54 + -20000 + iVar4;
  fVar20 = (float)(iVar2 + -20000 + iVar5);
  Player::setEmpData(this_00,iVar7,iVar14);
  this_01 = (PlayerFixedObject *)0x0;
  if (param_2 == 0) {
    this_01 = operator_new(0x2e8);
    fVar19 = (float)VectorSignedToFloat(iVar3,(byte)(in_fpscr >> 0x16) & 3);
    fVar20 = (float)VectorSignedToFloat(fVar20,(byte)(in_fpscr >> 0x16) & 3);
    uVar21 = VectorSignedToFloat(iVar4,(byte)(in_fpscr >> 0x16) & 3);
    uVar22 = 0;
    uVar13 = _param_5;
    PlayerFighter::PlayerFighter
              ((PlayerFighter *)this_01,param_3,param_1,this_00,(AEGeometry *)0x0,fVar19,
               extraout_s1_11,fVar20,SUB41(fVar19,0));
    pcVar18 = *(code **)(*(int *)this_01 + 8);
    uVar11 = Globals::getShipGroup(Globals::globals,param_3,param_1,param_6);
    (*pcVar18)(this_01,uVar11,param_3,_param_5,uVar22,fVar19,uVar21,fVar20,uVar13);
    if (*(int *)(this + 0xc0) != 1 && *(int *)(this + 0xc0) != 0x17) {
      pAVar16 = *(AEGeometry **)(this_01 + 0xc);
      if (pAVar16 == (AEGeometry *)0x0) {
        pAVar16 = *(AEGeometry **)(this_01 + 8);
      }
      LODManager::addObject(*(LODManager **)this,pAVar16);
    }
    if (param_3 != 0x2c) {
      if (param_3 == 0x33) {
        *(PlayerFighter *)(this_01 + 0x21) = (PlayerFighter)0x0;
        goto LAB_000d03c6;
      }
      if (param_3 != 0x31) goto LAB_000d03c6;
    }
    pvVar17 = *(void **)(this_01 + 0x4c);
    if (pvVar17 != (void *)0x0) {
      if (*(void **)((int)pvVar17 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar17 + 4));
      }
      operator_delete(pvVar17);
    }
    *(undefined4 *)(this_01 + 0x4c) = 0;
    goto LAB_000d03c6;
  }
  if (param_2 != 1) goto LAB_000d03c6;
  this_01 = operator_new(0x1b4);
  VectorSignedToFloat(iVar3,(byte)(in_fpscr >> 0x16) & 3);
  VectorSignedToFloat(iVar4,(byte)(in_fpscr >> 0x16) & 3);
  VectorSignedToFloat(fVar20,(byte)(in_fpscr >> 0x16) & 3);
  PlayerFixedObject::PlayerFixedObject
            (this_01,param_3,param_1,this_00,(AEGeometry *)0x0,fVar20,extraout_s1,extraout_s2);
  pAVar9 = operator_new(0xc);
  puVar10 = operator_new__(4);
  *(undefined4 **)(pAVar9 + 4) = puVar10;
  *(undefined4 *)(pAVar9 + 8) = 1;
  *puVar10 = 0;
  *(undefined4 *)pAVar9 = 0;
  switch(param_1) {
  case 0:
    if (param_3 != 0xe) {
      ArraySetLength<BoundingVolume*>(3,pAVar9);
      pBVar12 = operator_new(0x2c);
      BoundingAAB::BoundingAAB
                (pBVar12,extraout_s0_20,extraout_s1_22,extraout_s2_21,extraout_s3_20,extraout_s4_20,
                 extraout_s5_20,extraout_s6_20,extraout_s7_20,extraout_s8_20);
      **(undefined4 **)(pAVar9 + 4) = pBVar12;
      pBVar12 = operator_new(0x2c);
      BoundingAAB::BoundingAAB
                (pBVar12,extraout_s0_21,extraout_s1_23,extraout_s2_22,extraout_s3_21,extraout_s4_21,
                 extraout_s5_21,extraout_s6_21,extraout_s7_21,extraout_s8_21);
      *(BoundingAAB **)(*(int *)(pAVar9 + 4) + 4) = pBVar12;
      pBVar12 = operator_new(0x2c);
      BoundingAAB::BoundingAAB
                (pBVar12,extraout_s0_22,extraout_s1_24,extraout_s2_23,extraout_s3_22,extraout_s4_22,
                 extraout_s5_22,extraout_s6_22,extraout_s7_22,extraout_s8_22);
      iVar2 = *(int *)(pAVar9 + 4);
      iVar1 = 0x477e;
      goto LAB_000d037e;
    }
    ArraySetLength<BoundingVolume*>(0xb,pAVar9);
    pBVar12 = operator_new(0x2c);
    BoundingAAB::BoundingAAB
              (pBVar12,extraout_s0,extraout_s1_00,extraout_s2_00,extraout_s3,extraout_s4,extraout_s5
               ,extraout_s6,extraout_s7,extraout_s8);
    **(undefined4 **)(pAVar9 + 4) = pBVar12;
    pBVar12 = operator_new(0x2c);
    BoundingAAB::BoundingAAB
              (pBVar12,extraout_s0_00,extraout_s1_01,extraout_s2_01,extraout_s3_00,extraout_s4_00,
               extraout_s5_00,extraout_s6_00,extraout_s7_00,extraout_s8_00);
    *(BoundingAAB **)(*(int *)(pAVar9 + 4) + 4) = pBVar12;
    pBVar12 = operator_new(0x2c);
    BoundingAAB::BoundingAAB
              (pBVar12,extraout_s0_01,extraout_s1_02,extraout_s2_02,extraout_s3_01,extraout_s4_01,
               extraout_s5_01,extraout_s6_01,extraout_s7_01,extraout_s8_01);
    *(BoundingAAB **)(*(int *)(pAVar9 + 4) + 8) = pBVar12;
    pBVar12 = operator_new(0x2c);
    BoundingAAB::BoundingAAB
              (pBVar12,extraout_s0_02,extraout_s1_03,extraout_s2_03,extraout_s3_02,extraout_s4_02,
               extraout_s5_02,extraout_s6_02,extraout_s7_02,extraout_s8_02);
    *(BoundingAAB **)(*(int *)(pAVar9 + 4) + 0xc) = pBVar12;
    pBVar12 = operator_new(0x2c);
    BoundingAAB::BoundingAAB
              (pBVar12,extraout_s0_03,extraout_s1_04,extraout_s2_04,extraout_s3_03,extraout_s4_03,
               extraout_s5_03,extraout_s6_03,extraout_s7_03,extraout_s8_03);
    *(BoundingAAB **)(*(int *)(pAVar9 + 4) + 0x10) = pBVar12;
    pBVar12 = operator_new(0x2c);
    BoundingAAB::BoundingAAB
              (pBVar12,extraout_s0_04,extraout_s1_05,extraout_s2_05,extraout_s3_04,extraout_s4_04,
               extraout_s5_04,extraout_s6_04,extraout_s7_04,extraout_s8_04);
    *(BoundingAAB **)(*(int *)(pAVar9 + 4) + 0x14) = pBVar12;
    pBVar12 = operator_new(0x2c);
    BoundingAAB::BoundingAAB
              (pBVar12,extraout_s0_05,extraout_s1_06,extraout_s2_06,extraout_s3_05,extraout_s4_05,
               extraout_s5_05,extraout_s6_05,extraout_s7_05,extraout_s8_05);
    *(BoundingAAB **)(*(int *)(pAVar9 + 4) + 0x18) = pBVar12;
    pBVar12 = operator_new(0x2c);
    BoundingAAB::BoundingAAB
              (pBVar12,extraout_s0_06,extraout_s1_07,extraout_s2_07,extraout_s3_06,extraout_s4_06,
               extraout_s5_06,extraout_s6_06,extraout_s7_06,extraout_s8_06);
    *(BoundingAAB **)(*(int *)(pAVar9 + 4) + 0x1c) = pBVar12;
    pBVar12 = operator_new(0x2c);
    BoundingAAB::BoundingAAB
              (pBVar12,extraout_s0_07,extraout_s1_08,extraout_s2_08,extraout_s3_07,extraout_s4_07,
               extraout_s5_07,extraout_s6_07,extraout_s7_07,extraout_s8_07);
    *(BoundingAAB **)(*(int *)(pAVar9 + 4) + 0x20) = pBVar12;
    pBVar12 = operator_new(0x2c);
    BoundingAAB::BoundingAAB
              (pBVar12,extraout_s0_08,extraout_s1_09,extraout_s2_09,extraout_s3_08,extraout_s4_08,
               extraout_s5_08,extraout_s6_08,extraout_s7_08,extraout_s8_08);
    *(BoundingAAB **)(*(int *)(pAVar9 + 4) + 0x24) = pBVar12;
    pBVar12 = operator_new(0x2c);
    BoundingAAB::BoundingAAB
              (pBVar12,extraout_s0_09,extraout_s1_10,extraout_s2_10,extraout_s3_09,extraout_s4_09,
               extraout_s5_09,extraout_s6_09,extraout_s7_09,extraout_s8_09);
    iVar1 = 0x4780;
    *(BoundingAAB **)(*(int *)(pAVar9 + 4) + 0x28) = pBVar12;
    break;
  case 1:
    ArraySetLength<BoundingVolume*>(5,pAVar9);
    pBVar12 = operator_new(0x2c);
    BoundingAAB::BoundingAAB
              (pBVar12,extraout_s0_10,extraout_s1_12,extraout_s2_11,extraout_s3_10,extraout_s4_10,
               extraout_s5_10,extraout_s6_10,extraout_s7_10,extraout_s8_10);
    **(undefined4 **)(pAVar9 + 4) = pBVar12;
    pBVar12 = operator_new(0x2c);
    BoundingAAB::BoundingAAB
              (pBVar12,extraout_s0_11,extraout_s1_13,extraout_s2_12,extraout_s3_11,extraout_s4_11,
               extraout_s5_11,extraout_s6_11,extraout_s7_11,extraout_s8_11);
    *(BoundingAAB **)(*(int *)(pAVar9 + 4) + 4) = pBVar12;
    pBVar12 = operator_new(0x2c);
    BoundingAAB::BoundingAAB
              (pBVar12,extraout_s0_12,extraout_s1_14,extraout_s2_13,extraout_s3_12,extraout_s4_12,
               extraout_s5_12,extraout_s6_12,extraout_s7_12,extraout_s8_12);
    *(BoundingAAB **)(*(int *)(pAVar9 + 4) + 8) = pBVar12;
    pBVar12 = operator_new(0x2c);
    BoundingAAB::BoundingAAB
              (pBVar12,extraout_s0_13,extraout_s1_15,extraout_s2_14,extraout_s3_13,extraout_s4_13,
               extraout_s5_13,extraout_s6_13,extraout_s7_13,extraout_s8_13);
    *(BoundingAAB **)(*(int *)(pAVar9 + 4) + 0xc) = pBVar12;
    pBVar12 = operator_new(0x2c);
    BoundingAAB::BoundingAAB
              (pBVar12,extraout_s0_14,extraout_s1_16,extraout_s2_15,extraout_s3_14,extraout_s4_14,
               extraout_s5_14,extraout_s6_14,extraout_s7_14,extraout_s8_14);
    iVar1 = 0x477f;
    *(BoundingAAB **)(*(int *)(pAVar9 + 4) + 0x10) = pBVar12;
    break;
  case 2:
    ArraySetLength<BoundingVolume*>(3,pAVar9);
    pBVar12 = operator_new(0x2c);
    BoundingAAB::BoundingAAB
              (pBVar12,extraout_s0_15,extraout_s1_17,extraout_s2_16,extraout_s3_15,extraout_s4_15,
               extraout_s5_15,extraout_s6_15,extraout_s7_15,extraout_s8_15);
    **(undefined4 **)(pAVar9 + 4) = pBVar12;
    pBVar12 = operator_new(0x2c);
    BoundingAAB::BoundingAAB
              (pBVar12,extraout_s0_16,extraout_s1_18,extraout_s2_17,extraout_s3_16,extraout_s4_16,
               extraout_s5_16,extraout_s6_16,extraout_s7_16,extraout_s8_16);
    *(BoundingAAB **)(*(int *)(pAVar9 + 4) + 4) = pBVar12;
    pBVar12 = operator_new(0x2c);
    BoundingAAB::BoundingAAB
              (pBVar12,extraout_s0_17,extraout_s1_19,extraout_s2_18,extraout_s3_17,extraout_s4_17,
               extraout_s5_17,extraout_s6_17,extraout_s7_17,extraout_s8_17);
    iVar2 = *(int *)(pAVar9 + 4);
    iVar1 = 0x477d;
LAB_000d037e:
    *(BoundingAAB **)(iVar2 + 8) = pBVar12;
    goto LAB_000d0380;
  case 3:
    ArraySetLength<BoundingVolume*>(2,pAVar9);
    pBVar12 = operator_new(0x2c);
    BoundingAAB::BoundingAAB
              (pBVar12,extraout_s0_18,extraout_s1_20,extraout_s2_19,extraout_s3_18,extraout_s4_18,
               extraout_s5_18,extraout_s6_18,extraout_s7_18,extraout_s8_18);
    **(undefined4 **)(pAVar9 + 4) = pBVar12;
    pBVar12 = operator_new(0x2c);
    BoundingAAB::BoundingAAB
              (pBVar12,extraout_s0_19,extraout_s1_21,extraout_s2_20,extraout_s3_19,extraout_s4_19,
               extraout_s5_19,extraout_s6_19,extraout_s7_19,extraout_s8_19);
    iVar1 = 0x477c;
    *(BoundingAAB **)(*(int *)(pAVar9 + 4) + 4) = pBVar12;
LAB_000d0380:
    PlayerFixedObject::setWreckedMeshId(this_01,iVar1);
  default:
    goto switchD_000cfad8_default;
  }
  PlayerFixedObject::setWreckedMeshId(this_01,iVar1);
switchD_000cfad8_default:
  PlayerFixedObject::setBV(this_01,pAVar9);
  pcVar18 = *(code **)(*(int *)this_01 + 8);
  uVar13 = Globals::getShipGroup(Globals::globals,param_3,param_1,false);
  (*pcVar18)(this_01,uVar13,param_3,0);
  LODManager::addObject(*(LODManager **)this,*(AEGeometry **)(this_01 + 8));
  this_01[0x3c] = (PlayerFixedObject)0x1;
LAB_000d03c6:
  (**(code **)(*(int *)this_01 + 0x14))(this_01,this);
  return this_01;
}

// ===== Level::createRoute  @0x000d0464  (218 bytes)
/* Level::createRoute(int) */

Route * __thiscall Level::createRoute(Level *this,int param_1)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  Route *this_00;
  int iVar5;
  int *piVar6;
  int iVar7;
  
  uVar1 = param_1 * 3;
  uVar2 = (uint)((ulonglong)uVar1 * 4);
  if ((int)((ulonglong)uVar1 * 4 >> 0x20) != 0) {
    uVar2 = 0xffffffff;
  }
  piVar3 = operator_new__(uVar2);
  if (0 < param_1) {
    iVar5 = 0;
    piVar6 = piVar3 + 1;
    do {
      iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
      iVar7 = -1;
      if (iVar4 == 0) {
        iVar7 = 1;
      }
      iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,30000);
      piVar6[-1] = (iVar4 + 50000) * iVar7;
      iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
      *piVar6 = iVar4 + -10000;
      if (iVar5 == 0) {
        iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,30000);
        piVar3[2] = iVar4 + 50000;
      }
      else {
        iVar7 = piVar6[-2];
        iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,30000);
        piVar6[1] = iVar4 + iVar7 + 50000;
      }
      iVar5 = iVar5 + 3;
      piVar6 = piVar6 + 3;
    } while (iVar5 < (int)uVar1);
  }
  this_00 = operator_new(0x18);
  Route::Route(this_00,piVar3,uVar1);
  return this_00;
}

// ===== Level::setPlayerRoute  @0x000d0558  (28 bytes)
/* Level::setPlayerRoute(Route*) */

void __thiscall Level::setPlayerRoute(Level *this,Route *param_1)

{
  void *pvVar1;
  
  if (*(Route **)(this + 0x108) != (Route *)0x0) {
    pvVar1 = (void *)Route::~Route(*(Route **)(this + 0x108));
    operator_delete(pvVar1);
  }
  *(Route **)(this + 0x108) = param_1;
  return;
}

// ===== Level::createRadioMessages  @0x000d0574  (12642 bytes)
/* Level::createRadioMessages(int) */

undefined4 __thiscall Level::createRadioMessages(Level *this,int param_1)

{
  Array *pAVar1;
  undefined4 *puVar2;
  RadioMessage *pRVar3;
  
  *(undefined4 *)(this + 0x114) = 0;
  switch(param_1) {
  case 0:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(0x17,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x684,0x11,5,0x5dc);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x685,0,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x686,0,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x687,10,6,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x688,0xb,6,3);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x10) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x689,9,6,4);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x14) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x68a,9,6,5);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x18) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x68b,9,6,6);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x1c) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x68c,0,6,7);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x20) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x693,0,9,0,3);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x24) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x694,0,6,9);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x28) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x695,0,6,10);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x2c) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x696,0xf,6,0xb);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x30) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x697,0,6,0xc);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x34) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x698,0,6,0xd);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x38) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x699,0,6,0xe);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x3c) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x69a,0,0x1b,0xc);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x40) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x69b,0xf,6,0x10);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x44) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x69c,0,6,0x11);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x48) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x69d,0xf,6,0x12);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x4c) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x69e,0,6,0x13);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x50) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x69f,0,6,0x14);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x54) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x6a0,0xf,6,0x15);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x58) = pRVar3;
    goto switchD_000d058a_caseD_2;
  case 1:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(3,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x6a1,2,5,10000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x6a2,2,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x6a3,2,6,1);
    goto LAB_000d2da2;
  default:
    goto switchD_000d058a_caseD_2;
  case 7:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(2,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x6dc,2,0x10,0);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x6dd,0,6,0);
    goto LAB_000d3206;
  case 0xe:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(5,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x71c,0x12,5,10000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x71d,0x12,0x14,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x71e,0,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x71f,0x12,6,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x720,0x11,6,3);
    goto LAB_000d30ee;
  case 0x10:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(5,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x72e,0x13,5,10000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x72f,0,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x730,0,9,0,3);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x731,1,6,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x732,0,6,3);
    goto LAB_000d30ee;
  case 0x15:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(5,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x759,10,0x10,0);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x75a,0,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x75b,10,0x19,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x75c,0xe,8,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x75d,0xe,0x15,0);
    goto LAB_000d30ee;
  case 0x18:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(5,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x77d,0x13,5,12000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x77e,6,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x77f,0,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x780,6,0x16,3);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x781,6,6,3);
    goto LAB_000d30ee;
  case 0x19:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(3,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x785,0,5,20000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x786,6,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x787,0,6,1);
    goto LAB_000d2da2;
  case 0x1c:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(3,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x798,0,5,20000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x799,0x13,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x79a,0,6,1);
    goto LAB_000d2da2;
  case 0x1d:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(6,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x79c,0,0x17,0);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x79d,0,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x79e,0,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x79f,0,6,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x7a0,0x13,5,120000);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x10) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x7a1,0,6,4);
    goto LAB_000d2b18;
  case 0x26:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(1,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x7ed,0x15,5,15000);
    break;
  case 0x28:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(7,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x7fa,0,5,10000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x7fb,8,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x7fc,0,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x7fd,7,5,40000);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x7fe,0,6,3);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x10) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x7ff,7,0xc,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x14) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x800,0,0x18,0);
    goto LAB_000d195c;
  case 0x29:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(8,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x804,0,5,80000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x805,7,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x806,0,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x807,7,6,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x808,7,0x1a,-100000);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x10) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x809,7,6,4);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x14) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x80f,0,1,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x18) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x810,0,6,6);
    goto LAB_000d1ff4;
  case 0x31:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(1,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x848,0,5,8000);
    break;
  case 0x32:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(4,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x849,0x3f,5,8000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x84a,0,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x84b,0x3f,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x84c,0,6,2);
    goto LAB_000d319c;
  case 0x33:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(2,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x84d,0x3f,5,8000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x84e,0,6,0);
    goto LAB_000d3206;
  case 0x34:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(2,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x84f,0x3f,5,8000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x850,0,6,0);
    goto LAB_000d3206;
  case 0x35:
  case 0x36:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(1,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x851,0,5,8000);
    break;
  case 0x37:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(2,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x85a,0,5,8000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x85b,0,6,0);
    goto LAB_000d3206;
  case 0x38:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(6,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x86a,0x1b,5,8000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x86b,0,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x86c,0x1c,0x10,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x86d,0,0x14,3);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x86e,0,6,3);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x10) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x86f,0x1b,0x1c,0);
    goto LAB_000d2b18;
  case 0x3e:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(1,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8a1,0,5,8000);
    break;
  case 0x3f:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(3,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8af,0,5,8000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8b0,0,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8b1,0x1d,6,1);
    goto LAB_000d2da2;
  case 0x40:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(7,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8b4,0,5,8000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8b5,0x14,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8b6,0,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8b7,0x1e,6,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8b8,0,6,3);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x10) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8b9,0x1e,0x14,5);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x14) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8ba,0,6,5);
    goto LAB_000d195c;
  case 0x41:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(3,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8cb,0,5,12000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8cc,0x14,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8cd,0,6,1);
    goto LAB_000d2da2;
  case 0x43:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(0xc,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8ef,0,0x10,0);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8f0,0x1f,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8f1,0x1e,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8f2,0,0x14,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8f3,0x1f,6,3);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x10) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8f4,0,6,4);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x14) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8f5,0,0x14,8);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x18) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8f6,0x1f,6,6);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x1c) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8f7,0,6,7);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x20) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8f8,0x1f,6,8);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x24) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8f9,0,6,9);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x28) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x8fa,0x1f,6,10);
    goto LAB_000d33c4;
  case 0x45:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(2,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x90e,0,5,8000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x90f,0,6,0);
    goto LAB_000d3206;
  case 0x46:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(4,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x910,0,5,8000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x911,0,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x912,0x22,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x913,0,6,2);
    goto LAB_000d319c;
  case 0x49:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(8,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x92b,0,5,8000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x92c,0,0x10,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x92d,0xb,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x92e,0,6,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x92f,0,0x1b,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x10) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x930,0x21,0x1b,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x14) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x931,0,0x1b,3);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x18) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x932,0,6,6);
    goto LAB_000d1ff4;
  case 0x4e:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(4,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x969,0,5,2000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x96a,0,0x1b,9);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x96b,0,0x1b,0xb);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x96c,0xb,6,2);
    goto LAB_000d319c;
  case 0x4f:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(1,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x96d,0,5,6000);
    break;
  case 0x50:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(0xc,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x96e,0,5,8000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x96f,6,5,25000);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x970,0x1a,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x971,0,6,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x972,6,6,3);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x10) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x973,0x1a,6,4);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x14) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x974,6,6,5);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x18) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x975,0x1a,6,6);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x1c) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x976,0,6,7);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x20) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x977,0x1a,9,1,0x12);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x24) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x978,0x1a,0x1b,0xc);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x28) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x979,0x1a,6,10);
    goto LAB_000d33c4;
  case 0x51:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(4,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x980,0x1a,5,16000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x981,0x1f,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x982,0x1a,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x983,0x1a,6,2);
    goto LAB_000d319c;
  case 0x57:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(6,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9b0,6,5,0x5dc);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9b1,0,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9b2,6,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9b3,0,6,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9b4,6,6,3);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x10) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9b5,0,6,4);
    goto LAB_000d2b18;
  case 0x59:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(1,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9be,0x11,5,2000);
    break;
  case 0x5b:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(7,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9c8,0,5,0x5dc);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9c9,0,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9ca,0,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9cb,0x3c,6,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9cc,0,6,3);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x10) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9cd,0,0x1b,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x14) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9ce,0x3c,0x1b,4);
LAB_000d195c:
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x18) = pRVar3;
    goto switchD_000d058a_caseD_2;
  case 0x5c:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(10,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9d1,0x3b,5,0x5dc);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9d2,0,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9d3,0x3b,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9d4,0,6,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9d5,0,0x1b,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x10) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9d6,0,6,4);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x14) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9d7,0,0x1b,6);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x18) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9d8,0,6,6);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x1c) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9d9,0,9,0,3);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x20) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9da,0x3b,0x1b,10);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x24) = pRVar3;
    goto switchD_000d058a_caseD_2;
  case 0x5e:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(6,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9ed,0,5,0x5dc);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9ee,0x3b,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9ef,0,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9f0,0,0x1b,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9f1,0,6,3);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x10) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9f2,0,6,4);
    goto LAB_000d2b18;
  case 0x5f:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(1,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0x9fb,0x11,0x1b,1);
    break;
  case 0x61:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(3,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa16,0,5,0x5dc);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa17,0x16,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa18,0,6,1);
    goto LAB_000d2da2;
  case 99:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(1,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa28,0x11,0x1b,1);
    break;
  case 100:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(2,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa35,0,5,0x5dc);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa36,0,6,0);
    goto LAB_000d3206;
  case 0x66:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(9,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa41,0x12,5,8000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa42,0x12,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa43,0x12,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa44,0x12,0x1b,3);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa45,0,0x1e,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x10) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa46,0,0x1e,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x14) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa47,0,0x1e,3);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x18) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa48,0x12,0x1b,5);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x1c) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa49,0,0x1b,7);
    goto LAB_000d2cd4;
  case 0x69:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(9,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa61,0x14,5,0);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa62,0x3d,0x1b,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa63,0,0x1b,5);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa64,0x14,0x1b,6);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa65,0,6,3);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x10) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa66,0,0x1b,7);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x14) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa67,0x14,6,5);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x18) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa68,0,0x1b,9);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x1c) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa69,0,0x1b,10);
LAB_000d2cd4:
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x20) = pRVar3;
    goto switchD_000d058a_caseD_2;
  case 0x6a:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(6,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa6a,0,5,0x5dc);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa6b,0x14,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa6c,0x14,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa6d,0,6,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa6e,0,6,3);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x10) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa6f,0,0x1b,6);
    goto LAB_000d2b18;
  case 0x6d:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(1,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa7f,0x11,0x1b,1);
    break;
  case 0x72:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(3,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa94,0,5,8000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa95,10,0x1b,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xa96,0,6,1);
    goto LAB_000d2da2;
  case 0x77:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(1,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xab9,0x11,0x1b,1);
    break;
  case 0x78:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(1,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xac5,0,5,0x5dc);
    break;
  case 0x7b:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(4,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xae1,0x16,5,8000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xae2,0x26,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xae3,0x16,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xae4,0,6,2);
    goto LAB_000d319c;
  case 0x7d:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(8,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xaf4,0,5,0x5dc);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xafe,0,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xaff,0,0x1b,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb00,10,0x1b,3);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb01,0,0x1b,4);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x10) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb02,0,0x1b,5);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x14) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb04,0,0x1b,6);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x18) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb05,0,0x1b,7);
LAB_000d1ff4:
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x1c) = pRVar3;
    goto switchD_000d058a_caseD_2;
  case 0x7e:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(1,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb0c,0x11,0x1b,1);
    break;
  case 0x83:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(1,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb2b,0,0x1b,2);
    break;
  case 0x85:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(1,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb33,0x11,0x1b,1);
    break;
  case 0x87:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *puVar2 = 0;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(4,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb43,0x31,0x1b,1);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb44,0,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb45,0,0x1b,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb46,0,0x1b,3);
    goto LAB_000d319c;
  case 0x89:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(5,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb4f,0x32,5,0x5dc);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb50,0,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb51,0x32,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb52,0,6,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb53,0x32,6,3);
    goto LAB_000d30ee;
  case 0x8b:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(6,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb6c,0,5,8000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb6d,0,0x1b,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb6e,0x32,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb6f,0x32,6,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb70,0,0x1b,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x10) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb71,0,0x1b,3);
LAB_000d2b18:
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x14) = pRVar3;
    goto switchD_000d058a_caseD_2;
  case 0x8e:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(5,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb88,2,5,0x5dc);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb89,2,0x1b,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb8a,0,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb8b,2,6,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb8c,2,0x1b,3);
LAB_000d30ee:
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x10) = pRVar3;
    goto switchD_000d058a_caseD_2;
  case 0x90:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(4,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb98,0x27,5,7000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb99,0x27,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb9a,0,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb9b,0x27,6,2);
LAB_000d319c:
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    goto switchD_000d058a_caseD_2;
  case 0x91:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(3,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb9c,0,5,7000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb9d,0x27,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xb9e,0x27,0x1b,5);
LAB_000d2da2:
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    goto switchD_000d058a_caseD_2;
  case 0x93:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(2,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xbac,0,5,7000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xbad,0,6,0);
LAB_000d3206:
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    goto switchD_000d058a_caseD_2;
  case 0x9a:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(0xc,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xbdf,0,5,9000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xbe0,0x1a,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xbe1,0,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xbe2,0x1a,6,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xbe3,0,6,3);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x10) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xbe4,0x1a,6,4);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x14) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xbe5,0,6,5);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x18) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xbe6,0x1a,0x1b,9);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x1c) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xbe7,0,0x1b,10);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x20) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xbe8,0x37,6,8);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x24) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xbe9,0,6,9);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x28) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xbea,0,0x1b,0xb);
LAB_000d33c4:
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x2c) = pRVar3;
    goto switchD_000d058a_caseD_2;
  case 0x9d:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(0x11,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc05,0,5,7000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc06,0x26,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc07,0,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc08,0x27,6,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc09,1,0x1b,5);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x10) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc0a,0,6,4);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x14) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc0b,6,0xc,0x15);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x18) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc0c,0,6,6);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x1c) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc0d,6,0x1b,6);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x20) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc0e,0x1a,6,8);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x24) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc0f,6,6,9);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x28) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc10,1,6,10);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x2c) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc11,0x27,0x1b,8);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x30) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc12,0,0x1b,9);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x34) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc13,0x1a,6,0xd);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x38) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc14,0,6,0xe);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x3c) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc15,0x1a,6,0xf);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x40) = pRVar3;
    goto switchD_000d058a_caseD_2;
  case 0x9e:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(0xb,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc16,0,5,10000);
    **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc17,0,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 4) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc18,0x27,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 8) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc19,0,6,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0xc) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc1a,0x27,6,3);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x10) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc1b,0x27,0x1f,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x14) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc1c,0,6,5);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x18) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc1d,0x27,0xc,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x1c) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc1e,0,6,7);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x20) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc1f,0x27,0x13,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x24) = pRVar3;
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc20,0,1,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x114) + 4) + 0x28) = pRVar3;
    goto switchD_000d058a_caseD_2;
  case 0xa0:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(1,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc31,0x11,0x1b,1);
    break;
  case 0xa1:
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    *(Array **)(this + 0x114) = pAVar1;
    ArraySetLength<RadioMessage*>(1,pAVar1);
    pRVar3 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar3,0xc35,0x11,0x1b,1);
  }
  **(undefined4 **)(*(int *)(this + 0x114) + 4) = pRVar3;
switchD_000d058a_caseD_2:
  return *(undefined4 *)(this + 0x114);
}

// ===== Level::getBoundingVolume  @0x000d3b78  (560 bytes)
/* Level::getBoundingVolume(int, AEGeometry*) */

void Level::getBoundingVolume(int param_1,AEGeometry *param_2)

{
  FileRead *this;
  void *pvVar1;
  void *pvVar2;
  Array *pAVar3;
  undefined4 *puVar4;
  int iVar5;
  BoundingSphere *this_00;
  BoundingAAB *this_01;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint in_fpscr;
  float extraout_s0;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s2;
  float extraout_s3;
  float extraout_s3_00;
  float extraout_s4;
  float extraout_s5;
  float extraout_s5_00;
  float extraout_s6;
  float extraout_s7;
  float extraout_s8;
  float fVar11;
  float local_58;
  float local_54;
  float local_50;
  int local_4c;
  
  local_4c = __stack_chk_guard;
  this = operator_new(1);
  FileRead::FileRead(this);
  if ((int)param_2 < 2000) {
    pvVar1 = (void *)FileRead::loadStationCollision(this,(int)param_2);
  }
  else {
    pvVar1 = (void *)FileRead::loadStaticCollision(this,(int)param_2);
  }
  pvVar2 = (void *)FileRead::~FileRead(this);
  operator_delete(pvVar2);
  if (pvVar1 != (void *)0x0) {
    uVar8 = **(uint **)((int)pvVar1 + 4);
    local_58 = 0.0;
    local_54 = 0.0;
    local_50 = 0.0;
    pAVar3 = operator_new(0xc);
    puVar4 = operator_new__(4);
    *(undefined4 **)(pAVar3 + 4) = puVar4;
    *(undefined4 *)(pAVar3 + 8) = 1;
    *puVar4 = 0;
    *(undefined4 *)pAVar3 = 0;
    ArraySetLength<BoundingVolume*>(uVar8,pAVar3);
    if (0 < (int)uVar8) {
      iVar9 = 0;
      iVar10 = 1;
      do {
        iVar5 = *(int *)((int)pvVar1 + 4);
        iVar6 = iVar10 + 1;
        iVar7 = *(int *)(iVar5 + iVar10 * 4);
        if (iVar7 == 1) {
          iVar7 = iVar5 + iVar10 * 4;
          local_58 = (float)VectorSignedToFloat(*(undefined4 *)(iVar7 + 0x10),
                                                (byte)(in_fpscr >> 0x16) & 3);
          VectorSignedToFloat(*(undefined4 *)(iVar7 + 0xc),(byte)(in_fpscr >> 0x16) & 3);
          iVar5 = *(int *)(iVar5 + iVar6 * 4);
          VectorSignedToFloat(*(undefined4 *)(iVar7 + 8),(byte)(in_fpscr >> 0x16) & 3);
          local_50 = (float)VectorSignedToFloat(*(undefined4 *)(iVar7 + 0x14),
                                                (byte)(in_fpscr >> 0x16) & 3);
          local_54 = (float)VectorSignedToFloat(*(undefined4 *)(iVar7 + 0x18),
                                                (byte)(in_fpscr >> 0x16) & 3);
          AbyssEngine::AEMath::Vector::operator*=((Vector *)&local_58,local_54);
          fVar11 = (float)VectorSignedToFloat(-iVar5,(byte)(in_fpscr >> 0x16) & 3);
          this_01 = operator_new(0x2c);
          BoundingAAB::BoundingAAB
                    (this_01,local_58 + local_58,extraout_s1_00,local_54 + local_54,extraout_s3_00,
                     local_50 + local_50,extraout_s5_00,-fVar11,extraout_s7,extraout_s8);
          iVar6 = iVar10 + 7;
          *(BoundingAAB **)(*(int *)(pAVar3 + 4) + iVar9 * 4) = this_01;
        }
        else if (iVar7 == 0) {
          iVar7 = iVar5 + iVar10 * 4;
          local_58 = (float)VectorSignedToFloat(*(undefined4 *)(iVar7 + 0x10),
                                                (byte)(in_fpscr >> 0x16) & 3);
          VectorSignedToFloat(*(undefined4 *)(iVar7 + 0xc),(byte)(in_fpscr >> 0x16) & 3);
          iVar5 = *(int *)(iVar5 + iVar6 * 4);
          VectorSignedToFloat(*(float *)(iVar7 + 8),(byte)(in_fpscr >> 0x16) & 3);
          AbyssEngine::AEMath::Vector::operator*=((Vector *)&local_58,*(float *)(iVar7 + 8));
          fVar11 = (float)-iVar5;
          VectorSignedToFloat(fVar11,(byte)(in_fpscr >> 0x16) & 3);
          in_fpscr = in_fpscr & 0xfffffff;
          if (local_58 < 0.0) {
            AbyssEngine::AEMath::Vector::operator*=((Vector *)&local_58,fVar11);
          }
          this_00 = operator_new(0x48);
          BoundingSphere::BoundingSphere
                    (this_00,extraout_s0,extraout_s1,extraout_s2,extraout_s3,extraout_s4,extraout_s5
                     ,extraout_s6);
          iVar6 = iVar10 + 5;
          *(BoundingSphere **)(*(int *)(pAVar3 + 4) + iVar9 * 4) = this_00;
        }
        iVar9 = iVar9 + 1;
        iVar10 = iVar6;
      } while (iVar9 < (int)uVar8);
    }
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  if (__stack_chk_guard - local_4c == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_4c);
}

// ===== Level::getPlayer  @0x000d3e00  (6 bytes)
/* Level::getPlayer() */

undefined4 __thiscall Level::getPlayer(Level *this)

{
  return *(undefined4 *)(this + 0xf0);
}

// ===== Level::getEnemies  @0x000d3e06  (6 bytes)
/* Level::getEnemies() */

undefined4 __thiscall Level::getEnemies(Level *this)

{
  return *(undefined4 *)(this + 0xf8);
}

// ===== Level::getLandmarks  @0x000d3e0c  (6 bytes)
/* Level::getLandmarks() */

undefined4 __thiscall Level::getLandmarks(Level *this)

{
  return *(undefined4 *)(this + 0x100);
}

// ===== Level::getAsteroids  @0x000d3e12  (6 bytes)
/* Level::getAsteroids() */

undefined4 __thiscall Level::getAsteroids(Level *this)

{
  return *(undefined4 *)(this + 0xfc);
}

// ===== Level::getAsteroidWaypoint  @0x000d3e18  (6 bytes)
/* Level::getAsteroidWaypoint() */

undefined4 __thiscall Level::getAsteroidWaypoint(Level *this)

{
  return *(undefined4 *)(this + 0xd8);
}

// ===== Level::getPlayerRoute  @0x000d3e1e  (6 bytes)
/* Level::getPlayerRoute() */

undefined4 __thiscall Level::getPlayerRoute(Level *this)

{
  return *(undefined4 *)(this + 0x108);
}

// ===== Level::getEnemyRoute  @0x000d3e24  (6 bytes)
/* Level::getEnemyRoute() */

undefined4 __thiscall Level::getEnemyRoute(Level *this)

{
  return *(undefined4 *)(this + 0x110);
}

// ===== Level::getFriendRoute  @0x000d3e2a  (6 bytes)
/* Level::getFriendRoute() */

undefined4 __thiscall Level::getFriendRoute(Level *this)

{
  return *(undefined4 *)(this + 0x10c);
}

// ===== Level::flashScreen  @0x000d3e30  (330 bytes)
/* Level::flashScreen(int) */

void __thiscall Level::flashScreen(Level *this,int param_1)

{
  undefined4 uVar1;
  uint in_fpscr;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  this[0x158] = (Level)0x1;
  uVar1 = 2000;
  *(int *)(this + 0x15c) = param_1;
  if (param_1 == 1) {
    uVar1 = 7000;
  }
  if (2 < param_1) {
    uVar1 = 10000;
  }
  *(undefined4 *)(this + 0x150) = uVar1;
  *(undefined4 *)(this + 0x154) = uVar1;
  if (param_1 == 2) {
    *(float *)(this + 0x140) = i_r * 1.5;
    *(float *)(this + 0x144) = i_g * 1.5;
    *(float *)(this + 0x148) = i_b * 1.5;
  }
  else if (param_1 == 4) {
    *(undefined4 *)(this + 0x140) = 0;
    *(undefined4 *)(this + 0x144) = 0;
    *(undefined4 *)(this + 0x148) = 0x437f0000;
  }
  else if (param_1 == 3) {
    *(undefined4 *)(this + 0x140) = 0;
    *(undefined4 *)(this + 0x144) = 0;
    *(undefined4 *)(this + 0x148) = 0;
    PlayerEgo::hitCamera(*(PlayerEgo **)(this + 0xf0));
  }
  else {
    fVar2 = 5.0;
    uVar1 = 0x437f0000;
    if (param_1 == 1) {
      fVar2 = 8.0;
    }
    iVar3 = (int)(fVar2 * i_r);
    uVar4 = VectorSignedToFloat(iVar3,(byte)(in_fpscr >> 0x16) & 3);
    uVar5 = uVar1;
    if (iVar3 < 0xff) {
      uVar5 = uVar4;
    }
    if (iVar3 < 10) {
      uVar5 = 0x41200000;
    }
    *(undefined4 *)(this + 0x140) = uVar5;
    iVar3 = (int)(fVar2 * i_g);
    uVar4 = VectorSignedToFloat(iVar3,(byte)(in_fpscr >> 0x16) & 3);
    uVar5 = uVar1;
    if (iVar3 < 0xff) {
      uVar5 = uVar4;
    }
    if (iVar3 < 10) {
      uVar5 = 0x41200000;
    }
    *(undefined4 *)(this + 0x144) = uVar5;
    iVar3 = (int)(fVar2 * i_b);
    uVar5 = VectorSignedToFloat(iVar3,(byte)(in_fpscr >> 0x16) & 3);
    if (iVar3 < 0xff) {
      uVar1 = uVar5;
    }
    if (iVar3 < 10) {
      uVar1 = 0x41200000;
    }
    *(undefined4 *)(this + 0x148) = uVar1;
  }
  *(undefined4 *)(this + 0x14c) = 0x437f0000;
  return;
}

// ===== Level::enemyDied  @0x000d3f98  (564 bytes)
/* Level::enemyDied(int, bool) */

void __thiscall Level::enemyDied(Level *this,int param_1,bool param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint in_fpscr;
  float fVar4;
  float fVar5;
  
  *(int *)(this + 0x118) = *(int *)(this + 0x118) + -1;
  *(int *)(this + 300) = *(int *)(this + 300) + 1;
  if (param_2) {
    *(int *)(this + 0x20) = *(int *)(this + 0x20) + 1;
  }
  else {
    Status::incKills(Globals::status);
    *(int *)(this + 0x24) = *(int *)(this + 0x24) + 1;
    if (*(int *)(this + 0xf0) != 0) {
      iVar1 = Radar::hasScanner(*(Radar **)(*(int *)(this + 0xf0) + 0x14));
      if ((iVar1 == 0) && (iVar1 = Achievements::hasMedal(Globals::achievements,0x28,1), iVar1 == 0)
         ) {
        iVar1 = *(int *)(Globals::status + 0x11c);
        if (Globals::status[0x120] == (Status)0x0) {
          iVar1 = iVar1 + 1;
          *(int *)(Globals::status + 0x11c) = iVar1;
        }
        uVar2 = Achievements::getValue(Globals::achievements,0x28,1);
        fVar4 = (float)VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x16) & 3);
        fVar5 = (float)VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
        iVar1 = (int)((fVar4 / fVar5) * 100.0);
        if (iVar1 == (iVar1 / 10) * 10) {
          iVar1 = PlayerEgo::getHUD(*(PlayerEgo **)(this + 0xf0));
          VectorSignedToFloat(*(undefined4 *)(Globals::status + 0x11c),(byte)(in_fpscr >> 0x16) & 3)
          ;
          uVar2 = Achievements::getValue(Globals::achievements,0x28,1);
          VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
          Hud::hudEventMedal(iVar1,0x28);
        }
        iVar3 = *(int *)(Globals::status + 0x11c);
        iVar1 = Achievements::getValue(Globals::achievements,0x28,1);
        if (iVar1 <= iVar3) {
          Globals::status[0x120] = (Status)0x1;
        }
      }
      if (((*(PlayerEgo **)(this + 0xf0) != (PlayerEgo *)0x0) &&
          (iVar1 = PlayerEgo::emergencySystemActive(*(PlayerEgo **)(this + 0xf0)), iVar1 == 1)) &&
         (iVar1 = Achievements::hasMedal(Globals::achievements,0x2b,1), iVar1 == 0)) {
        iVar1 = *(int *)(Globals::status + 0x13c);
        *(int *)(Globals::status + 0x13c) = iVar1 + 1;
        uVar2 = Achievements::getValue(Globals::achievements,0x2b,1);
        fVar4 = (float)VectorSignedToFloat(iVar1 + 1,(byte)(in_fpscr >> 0x16) & 3);
        fVar5 = (float)VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
        if (0 < (int)(fVar4 / fVar5)) {
          iVar1 = PlayerEgo::getHUD(*(PlayerEgo **)(this + 0xf0));
          VectorSignedToFloat(*(undefined4 *)(Globals::status + 0x13c),(byte)(in_fpscr >> 0x16) & 3)
          ;
          uVar2 = Achievements::getValue(Globals::achievements,0x2b,1);
          VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
          Hud::hudEventMedal(iVar1,0x2b);
        }
        iVar3 = *(int *)(Globals::status + 0x13c);
        iVar1 = Achievements::getValue(Globals::achievements,0x2b,1);
        if (iVar1 <= iVar3) {
          Globals::status[0x140] = (Status)0x1;
        }
      }
    }
  }
  return;
}

// ===== Level::junkDied  @0x000d4214  (30 bytes)
/* Level::junkDied() */

void __thiscall Level::junkDied(Level *this)

{
  *(int *)(Globals::status + 0xb0) = *(int *)(Globals::status + 0xb0) + 1;
  *(int *)(this + 0x118) = *(int *)(this + 0x118) + -1;
  return;
}

// ===== Level::applyKills  @0x000d4238  (44 bytes)
/* Level::applyKills() */

void __thiscall Level::applyKills(Level *this)

{
  int iVar1;
  
  iVar1 = Status::getMission(Globals::status);
  if (iVar1 != 0) {
    Status::addKills(Globals::status,*(int *)(this + 300));
    *(undefined4 *)(this + 300) = 0;
  }
  return;
}

// ===== Level::friendDied  @0x000d426c  (12 bytes)
/* Level::friendDied() */

void __thiscall Level::friendDied(Level *this)

{
  *(int *)(this + 0x11c) = *(int *)(this + 0x11c) + -1;
  return;
}

// ===== Level::wingmanDied  @0x000d4278  (104 bytes)
/* Level::wingmanDied(AbyssEngine::String const&) */

void __thiscall Level::wingmanDied(Level *this,String *param_1)

{
  char cVar1;
  Array *pAVar2;
  uint uVar3;
  
  pAVar2 = (Array *)Status::getWingmen(Globals::status);
  if (pAVar2 != (Array *)0x0) {
    if (*(uint *)pAVar2 < 2) {
      Status::setWingmen(Globals::status,(Array *)0x0);
      return;
    }
    uVar3 = 0;
    do {
      cVar1 = AbyssEngine::String::Compare(*(String **)(*(int *)(pAVar2 + 4) + uVar3 * 4),param_1);
      if (cVar1 == '\0') {
        ArrayRemove<AbyssEngine::String*>(*(String **)(*(int *)(pAVar2 + 4) + uVar3 * 4),pAVar2);
        return;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)pAVar2);
  }
  return;
}

// ===== Level::asteroidDied  @0x000d4326  (12 bytes)
/* Level::asteroidDied() */

void __thiscall Level::asteroidDied(Level *this)

{
  *(int *)(this + 0x128) = *(int *)(this + 0x128) + -1;
  return;
}

// ===== Level::getAsteroidsLeft  @0x000d4332  (6 bytes)
/* Level::getAsteroidsLeft() */

undefined4 __thiscall Level::getAsteroidsLeft(Level *this)

{
  return *(undefined4 *)(this + 0x128);
}

// ===== Level::getEnemiesLeft  @0x000d4338  (6 bytes)
/* Level::getEnemiesLeft() */

undefined4 __thiscall Level::getEnemiesLeft(Level *this)

{
  return *(undefined4 *)(this + 0x118);
}

// ===== Level::getFriendsLeft  @0x000d433e  (6 bytes)
/* Level::getFriendsLeft() */

undefined4 __thiscall Level::getFriendsLeft(Level *this)

{
  return *(undefined4 *)(this + 0x11c);
}

// ===== Level::getMessages  @0x000d4344  (6 bytes)
/* Level::getMessages() */

undefined4 __thiscall Level::getMessages(Level *this)

{
  return *(undefined4 *)(this + 0x114);
}

// ===== Level::getTimeLimit  @0x000d434a  (6 bytes)
/* Level::getTimeLimit() */

undefined4 __thiscall Level::getTimeLimit(Level *this)

{
  return *(undefined4 *)(this + 0x130);
}

// ===== Level::collide  @0x000d4350  (26 bytes)
/* Level::collide(AbyssEngine::AEMath::Vector, bool) */

undefined4 Level::collide(int param_1)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0xc4) != (int *)0x0) {
    uVar1 = (**(code **)(**(int **)(param_1 + 0xc4) + 8))();
    return uVar1;
  }
  return 0;
}

// ===== Level::isInAsteroidCenterRange  @0x000d436a  (14 bytes)
/* Level::isInAsteroidCenterRange(AbyssEngine::AEMath::Vector) */

void Level::isInAsteroidCenterRange(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000d4376. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0xc4) + 8))();
  return;
}

// ===== Level::collideStream  @0x000d4378  (30 bytes)
/* Level::collideStream(AbyssEngine::AEMath::Vector) */

undefined4 Level::collideStream(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 0x100) + 4) + 4);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x38))();
    return uVar2;
  }
  return 0;
}

// ===== Level::collideStation  @0x000d4398  (70 bytes)
/* Level::collideStation(AbyssEngine::AEMath::Vector) */

undefined4
Level::collideStation(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if (((*(int *)(param_1 + 0x100) != 0) && (**(int **)(*(int *)(param_1 + 0x100) + 4) != 0)) &&
     (iVar1 = Status::inEmptyOrbit(Globals::status), iVar1 == 0)) {
    piVar2 = (int *)**(undefined4 **)(*(int *)(param_1 + 0x100) + 4);
    uVar3 = (**(code **)(*piVar2 + 0x38))(piVar2,param_2,param_3,param_4);
    return uVar3;
  }
  return 0;
}

// ===== Level::renderBG  @0x000d43f0  (1266 bytes)
/* Level::renderBG(int) */

void __thiscall Level::renderBG(Level *this,int param_1)

{
  PaintCanvas *pPVar1;
  bool bVar2;
  uint uVar3;
  Matrix *pMVar4;
  int iVar5;
  SolarSystem *this_00;
  undefined4 uVar6;
  Engine *this_01;
  undefined4 extraout_r1;
  undefined4 *puVar7;
  int iVar8;
  Matrix *this_02;
  uint in_fpscr;
  float fVar9;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s2;
  float extraout_s2_00;
  float extraout_s2_01;
  float fVar10;
  longlong lVar11;
  AEMath aAStack_c4 [12];
  AEMath aAStack_b8 [12];
  AEMath aAStack_ac [12];
  AEMath aAStack_a0 [12];
  undefined4 local_94;
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined4 local_88 [5];
  undefined4 local_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_50;
  int local_4c;
  
  local_4c = __stack_chk_guard;
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  AbyssEngine::PaintCanvas::BeginBG(Globals::Canvas);
  pPVar1 = Globals::Canvas;
  uVar3 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
  pMVar4 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar1,uVar3);
  AbyssEngine::AEMath::MatrixGetInverse((AEMath *)local_88,pMVar4);
  this_02 = (Matrix *)(this + 0x1d0);
  AbyssEngine::AEMath::Matrix::operator=(this_02,(AEMath *)local_88);
  *(undefined4 *)(this + 0x1dc) = 0;
  *(undefined4 *)(this + 0x1ec) = 0;
  *(undefined4 *)(this + 0x1fc) = 0;
  iVar5 = Status::inAlienOrbit(Globals::status);
  fVar9 = extraout_s1;
  fVar10 = extraout_s2;
  if (iVar5 == 0) {
    this_00 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar5 = SolarSystem::getIndex(this_00);
    fVar9 = extraout_s1_00;
    fVar10 = extraout_s2_00;
    if (iVar5 == 0x1b) {
      local_94 = 0x3f800000;
      local_90 = 0;
      uStack_8c = 0;
      StarSystem::getLightDirection();
      AbyssEngine::AEMath::VectorNormalize(aAStack_a0,(Vector *)local_88);
      AbyssEngine::AEMath::VectorCross((AEMath *)local_88,(Vector *)&local_94,(Vector *)aAStack_a0);
      AbyssEngine::AEMath::VectorNormalize(aAStack_ac,(Vector *)local_88);
      AbyssEngine::AEMath::VectorCross(aAStack_c4,(Vector *)aAStack_ac,(Vector *)aAStack_a0);
      AbyssEngine::AEMath::VectorNormalize(aAStack_b8,(Vector *)aAStack_c4);
      AbyssEngine::AEMath::operator-((AEMath *)local_88,(Vector *)aAStack_b8);
      AbyssEngine::AEMath::Vector::operator=((Vector *)&local_94,(Vector *)local_88);
      AbyssEngine::AEMath::MatrixSetRotation
                ((AEMath *)local_88,this + 0x20c,(Vector *)&local_94,(Vector *)aAStack_a0,
                 (Vector *)aAStack_ac);
      goto LAB_000d451e;
    }
  }
  AbyssEngine::AEMath::MatrixSetRotation((Matrix *)local_88,*(float *)(this + 0x1ac),fVar9,fVar10);
LAB_000d451e:
  AbyssEngine::AEMath::Matrix::operator*=(this_02,this + 0x20c);
  AbyssEngine::PaintCanvas::SetWorldViewMatrix(Globals::Canvas);
  AbyssEngine::PaintCanvas::SetTexture(Globals::Canvas,*(uint *)(this + 0x19c),0xffffffff);
  AbyssEngine::PaintCanvas::SetBlendMode(Globals::Canvas,0);
  AbyssEngine::PaintCanvas::DrawMesh(Globals::Canvas,*(uint *)(this + 8));
  AbyssEngine::PaintCanvas::SetTexture(Globals::Canvas,*(uint *)(this + 0x198),0xffffffff);
  AbyssEngine::PaintCanvas::SetBlendMode(Globals::Canvas,2);
  AbyssEngine::PaintCanvas::DrawMesh(Globals::Canvas,*(uint *)(this + 4));
  if (*(int *)(this + 0x1b4) != -1) {
    AbyssEngine::PaintCanvas::SetTexture(Globals::Canvas,*(uint *)(this + 0x1b8),0xffffffff);
    AbyssEngine::PaintCanvas::SetBlendMode(Globals::Canvas,1);
    pPVar1 = Globals::Canvas;
    uVar3 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
    pMVar4 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar1,uVar3);
    AbyssEngine::AEMath::MatrixGetInverse((AEMath *)local_88,pMVar4);
    AbyssEngine::AEMath::Matrix::operator=(this_02,(AEMath *)local_88);
    *(undefined4 *)(this + 0x1dc) = 0;
    *(undefined4 *)(this + 0x1ec) = 0;
    *(undefined4 *)(this + 0x1fc) = 0;
    AbyssEngine::AEMath::MatrixGetInverse((AEMath *)local_88,this_02);
    AbyssEngine::PaintCanvas::DrawTransform
              (Globals::Canvas,*(uint *)(this + 0x1b4),(AEMath *)local_88);
  }
  StarSystem::render(*(StarSystem **)(this + 0xec));
  iVar5 = Status::inSupernovaSystem(Globals::status);
  if ((iVar5 == 1) && (*(int *)(this + 0xc) != -1)) {
    iVar5 = Status::getCurrentCampaignMission(Globals::status);
    AbyssEngine::PaintCanvas::SetTexture(Globals::Canvas,*(uint *)(this + 0x1a0),0xffffffff);
    AbyssEngine::PaintCanvas::SetBlendMode(Globals::Canvas,2);
    fVar9 = 1.0;
    fVar10 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    if (0x6a < iVar5) {
      fVar9 = 1.5;
    }
    uVar6 = AbyssEngine::PaintCanvas::TransformGetTransform(Globals::Canvas,*(uint *)(this + 0x10));
    bVar2 = (bool)__aeabi_f2lz(fVar10 * fVar9);
    AbyssEngine::Transform::Update(CONCAT44(extraout_r1,uVar6),bVar2);
    AbyssEngine::AEMath::MatrixGetInverse((AEMath *)local_88,this_02);
    AbyssEngine::PaintCanvas::DrawTransform
              (Globals::Canvas,*(uint *)(this + 0x10),(AEMath *)local_88);
    uVar3 = AbyssEngine::PaintCanvas::TransformGetTransform(Globals::Canvas,*(uint *)(this + 0x18));
    AbyssEngine::Transform::Update((ulonglong)uVar3,bVar2);
    AbyssEngine::PaintCanvas::DrawTransform
              (Globals::Canvas,*(uint *)(this + 0x18),(AEMath *)local_88);
  }
  if (*(int *)(this + 0x1bc) != -1) {
    AbyssEngine::PaintCanvas::SetTexture(Globals::Canvas,*(uint *)(this + 0x1c0),0xffffffff);
    AbyssEngine::PaintCanvas::SetBlendMode(Globals::Canvas,2);
    pPVar1 = Globals::Canvas;
    uVar3 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
    pMVar4 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar1,uVar3);
    AbyssEngine::AEMath::MatrixGetInverse((AEMath *)local_88,pMVar4);
    AbyssEngine::AEMath::Matrix::operator=(this_02,(AEMath *)local_88);
    iVar5 = AbyssEngine::PaintCanvas::TransformGetTransform(Globals::Canvas,*(uint *)(this + 0x1bc))
    ;
    iVar8 = *(int *)(iVar5 + 0x110);
    lVar11 = AbyssEngine::PaintCanvas::TransformGetTransform
                       (Globals::Canvas,*(uint *)(this + 0x1bc));
    AbyssEngine::Transform::Update(lVar11,SUB41(param_1,0));
    if (*(int *)(iVar5 + 0x110) < iVar8) {
      uVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x10000);
      VectorSignedToFloat(uVar6,(byte)(in_fpscr >> 0x16) & 3);
      uVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x10000);
      VectorSignedToFloat(uVar6,(byte)(in_fpscr >> 0x16) & 3);
      uVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x10000);
      fVar9 = (float)VectorSignedToFloat(uVar6,(byte)(in_fpscr >> 0x16) & 3);
      AbyssEngine::AEMath::MatrixSetRotation
                ((Matrix *)local_88,fVar9 * 1.5258789e-05 * 6.2831855,extraout_s1_01,extraout_s2_01)
      ;
    }
    AbyssEngine::AEMath::Matrix::operator*=(this_02,this + 0x248);
    *(undefined4 *)(this + 0x1dc) = 0;
    *(undefined4 *)(this + 0x1ec) = 0;
    *(undefined4 *)(this + 0x1fc) = 0;
    AbyssEngine::AEMath::MatrixGetInverse((AEMath *)local_88,this_02);
    AbyssEngine::PaintCanvas::DrawTransform
              (Globals::Canvas,*(uint *)(this + 0x1bc),(AEMath *)local_88);
  }
  pPVar1 = Globals::Canvas;
  if ((this[0x289] != (Level)0x0) && (1.0 <= (float)Globals::options._40_4_)) {
    uVar3 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
    pMVar4 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar1,uVar3);
    AbyssEngine::AEMath::MatrixGetInverse((AEMath *)local_88,pMVar4);
    AbyssEngine::AEMath::Matrix::operator=(this_02,(AEMath *)local_88);
    *(undefined4 *)(this + 0x1dc) = 0;
    *(undefined4 *)(this + 0x1ec) = 0;
    *(undefined4 *)(this + 0x1fc) = 0;
    AbyssEngine::PaintCanvas::SetWorldViewMatrix(Globals::Canvas);
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    uStack_6c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uStack_68 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uStack_64 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    puVar7 = (undefined4 *)((uint)local_88 | 4);
    this_01 = *(Engine **)(Globals::Canvas + 0x34);
    local_88[0] = 0x3f800000;
    *puVar7 = 0;
    puVar7[1] = uStack_6c;
    puVar7[2] = uStack_68;
    puVar7[3] = uStack_64;
    local_74 = 0x3f800000;
    local_70 = 0;
    local_60 = 0x3f800000;
    uStack_58 = 0x3f8000003f800000;
    local_50 = 0x3f800000;
    AbyssEngine::Engine::SetModelMatrix(this_01,(AEMath *)local_88);
    AbyssEngine::PaintCanvas::SetTexture
              (Globals::Canvas,*(uint *)(this + 0x1c4),*(uint *)(this + 0x1c8));
    AbyssEngine::PaintCanvas::SetBlendMode(Globals::Canvas,8);
    AbyssEngine::Engine::LightSetLight(*(Engine **)(Globals::Canvas + 0x34),0x4000);
    AbyssEngine::Engine::GlEnable(*(Engine **)(Globals::Canvas + 0x34),0x1100013,true);
    AbyssEngine::PaintCanvas::DrawMesh(Globals::Canvas,*(uint *)(this + 0x1cc));
    AbyssEngine::Engine::GlEnable(*(Engine **)(Globals::Canvas + 0x34),0x1100013,false);
    AbyssEngine::Engine::LightEnable(SUB41(*(undefined4 *)(Globals::Canvas + 0x34),0));
  }
  AbyssEngine::PaintCanvas::EndBG(Globals::Canvas);
  if (__stack_chk_guard != local_4c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Level::render  @0x000d4950  (410 bytes)
/* Level::render(int) */

void __thiscall Level::render(Level *this,int param_1)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  
  puVar1 = *(uint **)(this + 0xe4);
  if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
    uVar3 = 0;
    do {
      (**(code **)(**(int **)(puVar1[1] + uVar3 * 4) + 0x14))();
      puVar1 = *(uint **)(this + 0xe4);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar1);
  }
  puVar1 = *(uint **)(this + 0xe8);
  if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
    uVar3 = 0;
    do {
      (**(code **)(**(int **)(puVar1[1] + uVar3 * 4) + 0x14))();
      puVar1 = *(uint **)(this + 0xe8);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar1);
  }
  puVar1 = *(uint **)(this + 0xf8);
  if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
    uVar3 = 0;
    do {
      piVar2 = *(int **)(puVar1[1] + uVar3 * 4);
      (**(code **)(*piVar2 + 0x34))(piVar2,param_1);
      (**(code **)(**(int **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar3 * 4) + 0x24))();
      puVar1 = *(uint **)(this + 0xf8);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar1);
  }
  puVar1 = *(uint **)(this + 0xfc);
  if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
    uVar3 = 0;
    do {
      piVar2 = *(int **)(puVar1[1] + uVar3 * 4);
      (**(code **)(*piVar2 + 0x34))(piVar2,param_1);
      (**(code **)(**(int **)(*(int *)(*(int *)(this + 0xfc) + 4) + uVar3 * 4) + 0x24))();
      puVar1 = *(uint **)(this + 0xfc);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar1);
  }
  puVar1 = *(uint **)(this + 0xf4);
  if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
    uVar3 = 0;
    do {
      piVar2 = *(int **)(puVar1[1] + uVar3 * 4);
      (**(code **)(*piVar2 + 0x34))(piVar2,param_1);
      (**(code **)(**(int **)(*(int *)(*(int *)(this + 0xf4) + 4) + uVar3 * 4) + 0x24))();
      puVar1 = *(uint **)(this + 0xf4);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar1);
  }
  puVar1 = *(uint **)(this + 0x100);
  if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
    uVar3 = 0;
    do {
      piVar2 = *(int **)(puVar1[1] + uVar3 * 4);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x34))(piVar2,param_1);
        (**(code **)(**(int **)(*(int *)(*(int *)(this + 0x100) + 4) + uVar3 * 4) + 0x24))();
        puVar1 = *(uint **)(this + 0x100);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar1);
  }
  if (*(ParticleSystemManager **)(this + 0x80) != (ParticleSystemManager *)0x0) {
    ParticleSystemManager::render3d(*(ParticleSystemManager **)(this + 0x80));
  }
  if (*(ParticleSystemManager **)(this + 0x74) != (ParticleSystemManager *)0x0) {
    ParticleSystemManager::render3d(*(ParticleSystemManager **)(this + 0x74));
  }
  if (*(ParticleSystemManager **)(this + 0x78) != (ParticleSystemManager *)0x0) {
    ParticleSystemManager::render3d(*(ParticleSystemManager **)(this + 0x78));
  }
  if (*(ParticleSystemManager **)(this + 0x7c) != (ParticleSystemManager *)0x0) {
    ParticleSystemManager::render3d(*(ParticleSystemManager **)(this + 0x7c));
  }
  if (*(ParticleSystemManager **)(this + 0x88) != (ParticleSystemManager *)0x0) {
    ParticleSystemManager::render3d(*(ParticleSystemManager **)(this + 0x88));
  }
  if (*(ParticleSystemManager **)(this + 0x84) != (ParticleSystemManager *)0x0) {
    ParticleSystemManager::render3d(*(ParticleSystemManager **)(this + 0x84));
  }
  if (*(ParticleSystemManager **)(this + 0x8c) != (ParticleSystemManager *)0x0) {
    ParticleSystemManager::render3d(*(ParticleSystemManager **)(this + 0x8c));
  }
  if (*(ParticleSystemManager **)(this + 0x98) != (ParticleSystemManager *)0x0) {
    ParticleSystemManager::render3d(*(ParticleSystemManager **)(this + 0x98));
  }
  if (*(ParticleSystemManager **)(this + 0x94) != (ParticleSystemManager *)0x0) {
    ParticleSystemManager::render3d(*(ParticleSystemManager **)(this + 0x94));
  }
  if (*(ParticleSystemManager **)(this + 0x9c) != (ParticleSystemManager *)0x0) {
    ParticleSystemManager::render3d(*(ParticleSystemManager **)(this + 0x9c));
  }
  StarSystem::renderSunStreak(*(StarSystem **)(this + 0xec));
  return;
}

// ===== Level::render2D  @0x000d4ae8  (10 bytes)
/* Level::render2D() */

void Level::render2D(void)

{
  int in_r0;
  
  StarSystem::render2D(*(StarSystem **)(in_r0 + 0xec));
  return;
}

// ===== Level::renderPause  @0x000d4af0  (226 bytes)
/* Level::renderPause(long long) */

void Level::renderPause(longlong param_1)

{
  int iVar1;
  uint *puVar2;
  int *piVar3;
  uint uVar4;
  
  iVar1 = (int)param_1;
  puVar2 = *(uint **)(iVar1 + 0xe4);
  if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
    uVar4 = 0;
    do {
      (**(code **)(**(int **)(puVar2[1] + uVar4 * 4) + 0x14))();
      puVar2 = *(uint **)(iVar1 + 0xe4);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar2);
  }
  puVar2 = *(uint **)(iVar1 + 0xe8);
  if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
    uVar4 = 0;
    do {
      (**(code **)(**(int **)(puVar2[1] + uVar4 * 4) + 0x14))();
      puVar2 = *(uint **)(iVar1 + 0xe8);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar2);
  }
  puVar2 = *(uint **)(iVar1 + 0xf8);
  if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
    uVar4 = 0;
    do {
      (**(code **)(**(int **)(puVar2[1] + uVar4 * 4) + 0x24))();
      puVar2 = *(uint **)(iVar1 + 0xf8);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar2);
  }
  puVar2 = *(uint **)(iVar1 + 0xfc);
  if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
    uVar4 = 0;
    do {
      (**(code **)(**(int **)(puVar2[1] + uVar4 * 4) + 0x24))();
      puVar2 = *(uint **)(iVar1 + 0xfc);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar2);
  }
  puVar2 = *(uint **)(iVar1 + 0xf4);
  if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
    uVar4 = 0;
    do {
      (**(code **)(**(int **)(puVar2[1] + uVar4 * 4) + 0x24))();
      puVar2 = *(uint **)(iVar1 + 0xf4);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar2);
  }
  puVar2 = *(uint **)(iVar1 + 0x100);
  if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
    uVar4 = 0;
    do {
      piVar3 = *(int **)(puVar2[1] + uVar4 * 4);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x24))();
        puVar2 = *(uint **)(iVar1 + 0x100);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar2);
  }
  return;
}

// ===== Level::updateMissionOrbit  @0x000d4bd4  (1204 bytes)
/* Level::updateMissionOrbit(int) */

void __thiscall Level::updateMissionOrbit(Level *this,int param_1)

{
  int iVar1;
  Mission *pMVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  KIPlayer *pKVar9;
  uint in_fpscr;
  float fVar10;
  float local_34;
  float local_30;
  float local_2c;
  
  iVar1 = __stack_chk_guard;
  if (this[0x288] != (Level)0x0) {
    pMVar2 = (Mission *)Status::getMission(Globals::status);
    iVar3 = Mission::isEmpty(pMVar2);
    if ((iVar3 == 0) &&
       (iVar3 = *(int *)(this + 0x174), *(int *)(this + 0x174) = iVar3 + param_1,
       0x57e4 < iVar3 + param_1)) {
      iVar3 = 0;
      iVar8 = 0;
      *(undefined4 *)(this + 0x174) = 0;
      do {
        iVar4 = KIPlayer::isDead(*(KIPlayer **)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar8 * 4));
        iVar8 = iVar8 + 1;
        if (iVar4 == 0) {
          iVar3 = iVar3 + 1;
        }
      } while (iVar8 != 4);
      if ((0 < iVar3) && (puVar5 = *(uint **)(this + 0xf8), 4 < *puVar5)) {
        uVar7 = 4;
        do {
          pKVar9 = *(KIPlayer **)(puVar5[1] + uVar7 * 4);
          iVar3 = KIPlayer::isDead(pKVar9);
          if ((iVar3 == 1) && (iVar3 = Player::isActive(*(Player **)(pKVar9 + 4)), iVar3 == 0)) {
            (**(code **)(*(int *)pKVar9 + 0x18))(pKVar9);
            PlayerEgo::getPosition();
            iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,40000);
            iVar8 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
            iVar4 = -1;
            if (iVar8 == 0) {
              iVar4 = 1;
            }
            fVar10 = (float)VectorSignedToFloat(iVar4 * (iVar3 + 40000),(byte)(in_fpscr >> 0x16) & 3
                                               );
            local_34 = local_34 + fVar10;
            iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,5000);
            iVar8 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
            iVar4 = -1;
            if (iVar8 == 0) {
              iVar4 = 1;
            }
            fVar10 = (float)VectorSignedToFloat(iVar4 * (iVar3 + 5000),(byte)(in_fpscr >> 0x16) & 3)
            ;
            local_30 = local_30 + fVar10;
            iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,40000);
            iVar8 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
            iVar4 = -1;
            if (iVar8 == 0) {
              iVar4 = 1;
            }
            fVar10 = (float)VectorSignedToFloat(iVar4 * (iVar3 + 40000),(byte)(in_fpscr >> 0x16) & 3
                                               );
            local_2c = local_2c + fVar10;
            (**(code **)(*(int *)pKVar9 + 0x48))(pKVar9,local_34,local_30,local_2c);
          }
          puVar5 = *(uint **)(this + 0xf8);
          uVar7 = uVar7 + 1;
        } while (uVar7 < *puVar5);
      }
    }
  }
  iVar3 = Status::getMission(Globals::status);
  if (iVar3 != 0) {
    pMVar2 = (Mission *)Status::getMission(Globals::status);
    iVar3 = Mission::getType(pMVar2);
    if ((iVar3 == 0xb7) &&
       (iVar3 = *(int *)(this + 0x174), *(int *)(this + 0x174) = iVar3 + param_1,
       0x1d4c < iVar3 + param_1)) {
      *(undefined4 *)(this + 0x174) = 0;
      puVar5 = *(uint **)(this + 0xf8);
      if (*puVar5 != 0) {
        uVar7 = 0;
        do {
          pKVar9 = *(KIPlayer **)(puVar5[1] + uVar7 * 4);
          iVar3 = KIPlayer::isDead(pKVar9);
          if (((iVar3 == 1) && (iVar3 = Player::isActive(*(Player **)(pKVar9 + 4)), iVar3 == 0)) &&
             (*(int *)(pKVar9 + 0x78) != 0x33)) {
            (**(code **)(*(int *)pKVar9 + 0x18))(pKVar9);
            PlayerEgo::getPosition();
            iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,30000);
            iVar8 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
            iVar4 = -1;
            if (iVar8 == 0) {
              iVar4 = 1;
            }
            fVar10 = (float)VectorSignedToFloat(iVar4 * (iVar3 + 50000),(byte)(in_fpscr >> 0x16) & 3
                                               );
            local_34 = local_34 + fVar10;
            iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,10000);
            iVar8 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
            iVar4 = -1;
            if (iVar8 == 0) {
              iVar4 = 1;
            }
            fVar10 = (float)VectorSignedToFloat((iVar3 + 10000) * iVar4,(byte)(in_fpscr >> 0x16) & 3
                                               );
            local_30 = local_30 + fVar10;
            iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,30000);
            iVar8 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
            iVar4 = -1;
            if (iVar8 == 0) {
              iVar4 = 1;
            }
            fVar10 = (float)VectorSignedToFloat((iVar3 + 50000) * iVar4,(byte)(in_fpscr >> 0x16) & 3
                                               );
            local_2c = local_2c + fVar10;
            (**(code **)(*(int *)pKVar9 + 0x48))(pKVar9,local_34,local_30,local_2c);
            *(undefined4 *)(pKVar9 + 0x4c) = 0;
          }
          puVar5 = *(uint **)(this + 0xf8);
          uVar7 = uVar7 + 1;
        } while (uVar7 < *puVar5);
      }
    }
  }
  pMVar2 = (Mission *)Status::getMission(Globals::status);
  iVar3 = Mission::isEmpty(pMVar2);
  if (iVar3 == 0) {
    pMVar2 = (Mission *)Status::getMission(Globals::status);
    iVar3 = Mission::getType(pMVar2);
    if ((iVar3 == 0xf) &&
       (iVar3 = *(int *)(this + 0x174), *(int *)(this + 0x174) = iVar3 + param_1,
       50000 < iVar3 + param_1)) {
      *(undefined4 *)(this + 0x174) = 0;
      piVar6 = *(int **)(this + 0xf8);
      if (*piVar6 != 1) {
        uVar7 = 0;
        do {
          iVar3 = KIPlayer::isDead(*(KIPlayer **)(piVar6[1] + uVar7 * 4));
          piVar6 = *(int **)(this + 0xf8);
          if (iVar3 != 1) break;
          uVar7 = uVar7 + 1;
        } while (uVar7 < *piVar6 - 1U);
        if ((*piVar6 != 1) && (iVar3 == 1)) {
          uVar7 = 0;
          do {
            pKVar9 = *(KIPlayer **)(piVar6[1] + uVar7 * 4);
            iVar3 = KIPlayer::isDead(pKVar9);
            if ((iVar3 == 1) && (iVar3 = Player::isActive(*(Player **)(pKVar9 + 4)), iVar3 == 0)) {
              (**(code **)(*(int *)pKVar9 + 0x18))(pKVar9);
              PlayerEgo::getPosition();
              iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,40000);
              iVar8 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
              iVar4 = -1;
              if (iVar8 == 0) {
                iVar4 = 1;
              }
              fVar10 = (float)VectorSignedToFloat(iVar4 * (iVar3 + 40000),
                                                  (byte)(in_fpscr >> 0x16) & 3);
              local_34 = local_34 + fVar10;
              iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,5000);
              iVar8 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
              iVar4 = -1;
              if (iVar8 == 0) {
                iVar4 = 1;
              }
              fVar10 = (float)VectorSignedToFloat(iVar4 * (iVar3 + 5000),
                                                  (byte)(in_fpscr >> 0x16) & 3);
              local_30 = local_30 + fVar10;
              iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,40000);
              iVar8 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
              iVar4 = -1;
              if (iVar8 == 0) {
                iVar4 = 1;
              }
              fVar10 = (float)VectorSignedToFloat(iVar4 * (iVar3 + 40000),
                                                  (byte)(in_fpscr >> 0x16) & 3);
              local_2c = local_2c + fVar10;
              (**(code **)(*(int *)pKVar9 + 0x48))(pKVar9,local_34,local_30,local_2c);
            }
            piVar6 = *(int **)(this + 0xf8);
            uVar7 = uVar7 + 1;
          } while (uVar7 < *piVar6 - 1U);
        }
      }
    }
  }
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Level::updateOrbit  @0x000d50b0  (1016 bytes)
/* Level::updateOrbit(int) */

void __thiscall Level::updateOrbit(Level *this,int param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  SolarSystem *pSVar6;
  uint *puVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  KIPlayer *pKVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint in_fpscr;
  float fVar16;
  float local_34;
  float local_30;
  float local_2c;
  
  iVar4 = __stack_chk_guard;
  *(int *)(this + 0x174) = *(int *)(this + 0x174) + param_1;
  iVar5 = *(int *)(this + 0x178) + param_1;
  *(int *)(this + 0x178) = iVar5;
  if (this[0x18a] != (Level)0x0) {
    iVar5 = Status::getSystem(Globals::status);
    if ((iVar5 != 0) && (*(int *)(*(int *)(this + 0xf0) + 0x18) != 0)) {
      pSVar6 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar5 = SolarSystem::getRace(pSVar6);
      alarmAllFriends(this,iVar5,false);
      pSVar6 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar5 = SolarSystem::getRace(pSVar6);
      createRadioMessage(this,2,iVar5);
      this[0x18a] = (Level)0x0;
    }
    iVar5 = *(int *)(this + 0x178);
  }
  if (10000 < iVar5) {
    *(undefined4 *)(this + 0x178) = 0;
    puVar7 = *(uint **)(this + 0xf8);
    if ((puVar7 != (uint *)0x0) && (*puVar7 != 0)) {
      uVar13 = 0;
      do {
        pKVar11 = *(KIPlayer **)(puVar7[1] + uVar13 * 4);
        iVar5 = KIPlayer::isJumper(pKVar11);
        if ((((iVar5 == 1) && (iVar5 = KIPlayer::isDead(pKVar11), iVar5 == 1)) &&
            (iVar5 = Player::isActive(*(Player **)(pKVar11 + 4)), iVar5 == 0)) &&
           (pKVar11[0x3e] == (KIPlayer)0x0)) {
          (**(code **)(*(int *)pKVar11 + 0x18))(pKVar11);
          if ((int)uVar13 < *(int *)(this + 0x160) + *(int *)(this + 0x164)) {
            iVar5 = *(int *)pKVar11;
            uVar9 = 0;
            uVar10 = 0;
          }
          else {
            iVar5 = *(int *)pKVar11;
            uVar9 = 0x461c4000;
            uVar10 = 0xc788b800;
          }
          (**(code **)(iVar5 + 0x48))(pKVar11,uVar9,0,uVar10);
          break;
        }
        puVar7 = *(uint **)(this + 0xf8);
        uVar13 = uVar13 + 1;
      } while (uVar13 < *puVar7);
    }
  }
  if (*(int *)(this + 0x174) < 0xafc9) goto LAB_000d5458;
  iVar14 = 0;
  *(undefined4 *)(this + 0x174) = 0;
  iVar5 = *(int *)(this + 0x16c);
  puVar7 = *(uint **)(this + 0xf8);
  if (iVar5 < 1) {
LAB_000d5204:
    if (puVar7 == (uint *)0x0) goto LAB_000d5458;
  }
  else {
    if (puVar7 == (uint *)0x0) goto LAB_000d5458;
    uVar13 = *puVar7;
    iVar14 = 0;
    if (uVar13 != 0) {
      uVar12 = 0;
      while( true ) {
        if (((uVar13 - iVar5 <= uVar12) &&
            (iVar5 = KIPlayer::isWingMan(*(KIPlayer **)(puVar7[1] + uVar12 * 4)), iVar5 == 0)) &&
           ((iVar5 = KIPlayer::isDead(*(KIPlayer **)
                                       (*(int *)(*(int *)(this + 0xf8) + 4) + uVar12 * 4)),
            iVar5 == 1 &&
            (iVar5 = Player::isActive(*(Player **)
                                       (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar12 * 4) +
                                       4)), iVar5 == 0)))) {
          iVar14 = iVar14 + 1;
        }
        puVar7 = *(uint **)(this + 0xf8);
        uVar12 = uVar12 + 1;
        uVar13 = *puVar7;
        if (uVar13 <= uVar12) break;
        iVar5 = *(int *)(this + 0x16c);
      }
      goto LAB_000d5204;
    }
  }
  if (*puVar7 != 0) {
    uVar13 = 0;
    bVar2 = false;
    do {
      pKVar11 = *(KIPlayer **)(puVar7[1] + uVar13 * 4);
      if (((0 < *(int *)(this + 0x160)) && ((int)uVar13 < *(int *)(this + 0x160))) &&
         ((iVar5 = KIPlayer::isDead(pKVar11), iVar5 == 1 &&
          ((iVar5 = Player::isActive(*(Player **)(pKVar11 + 4)), iVar5 == 0 &&
           (pKVar11[0x3e] == (KIPlayer)0x0)))))) {
        (**(code **)(*(int *)pKVar11 + 0x18))(pKVar11);
        (**(code **)(*(int *)pKVar11 + 0x48))(pKVar11,0,0,0);
      }
      if ((((1 < iVar14) && (*(int *)(this + 0x184) < 2)) && (0 < *(int *)(this + 0x16c))) &&
         ((uint)(**(int **)(this + 0xf8) - *(int *)(this + 0x16c)) <= uVar13)) {
        iVar15 = *(int *)(pKVar11 + 0x24);
        iVar5 = Status::inAlienOrbit(Globals::status);
        if (iVar5 == 0) {
          pSVar6 = (SolarSystem *)Status::getSystem(Globals::status);
          iVar5 = SolarSystem::getSecurityLevel(pSVar6);
          bVar1 = false;
          if (iVar5 == 0) {
            bVar1 = true;
          }
        }
        else {
          bVar1 = false;
        }
        iVar5 = Status::inAlienOrbit(Globals::status);
        if (iVar5 == 0) {
          pSVar6 = (SolarSystem *)Status::getSystem(Globals::status);
          iVar5 = SolarSystem::getSecurityLevel(pSVar6);
          bVar3 = true;
          if (iVar5 != 1) {
            bVar3 = false;
          }
        }
        else {
          bVar3 = false;
        }
        iVar5 = KIPlayer::isDead(pKVar11);
        if (((iVar5 == 1) && (iVar5 = Player::isActive(*(Player **)(pKVar11 + 4)), iVar5 == 0)) &&
           (pKVar11[0x3e] == (KIPlayer)0x0)) {
          if (iVar15 == 9 || bVar1) {
            iVar5 = *(int *)(this + 0x17c);
          }
          else if ((!bVar3) || (iVar5 = *(int *)(this + 0x17c), 2 < iVar5)) goto LAB_000d5438;
          *(int *)(this + 0x17c) = iVar5 + 1;
          (**(code **)(*(int *)pKVar11 + 0x18))(pKVar11);
          PlayerEgo::getPosition();
          iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,60000);
          iVar15 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
          iVar8 = -1;
          if (iVar15 == 0) {
            iVar8 = 1;
          }
          fVar16 = (float)VectorSignedToFloat(iVar8 * (iVar5 + 60000),(byte)(in_fpscr >> 0x16) & 3);
          local_34 = local_34 + fVar16;
          iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,5000);
          iVar15 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
          iVar8 = -1;
          if (iVar15 == 0) {
            iVar8 = 1;
          }
          fVar16 = (float)VectorSignedToFloat(iVar8 * (iVar5 + 5000),(byte)(in_fpscr >> 0x16) & 3);
          local_30 = local_30 + fVar16;
          iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,60000);
          iVar15 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
          iVar8 = -1;
          if (iVar15 == 0) {
            iVar8 = 1;
          }
          fVar16 = (float)VectorSignedToFloat(iVar8 * (iVar5 + 60000),(byte)(in_fpscr >> 0x16) & 3);
          local_2c = local_2c + fVar16;
          (**(code **)(*(int *)pKVar11 + 0x48))(pKVar11,local_34,local_30,local_2c);
          bVar2 = true;
        }
      }
LAB_000d5438:
      puVar7 = *(uint **)(this + 0xf8);
      uVar13 = uVar13 + 1;
    } while (uVar13 < *puVar7);
    if (bVar2) {
      *(int *)(this + 0x184) = *(int *)(this + 0x184) + 1;
    }
  }
LAB_000d5458:
  if (__stack_chk_guard != iVar4) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Level::alarmAllFriends  @0x000d54cc  (150 bytes)
/* Level::alarmAllFriends(int, bool) */

void __thiscall Level::alarmAllFriends(Level *this,int param_1,bool param_2)

{
  uint *puVar1;
  SolarSystem *this_00;
  Station *this_01;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  puVar1 = *(uint **)(this + 0xf8);
  if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
    uVar3 = 0;
    do {
      iVar2 = *(int *)(puVar1[1] + uVar3 * 4);
      if (*(int *)(iVar2 + 0x24) == param_1) {
        Player::setAlwaysEnemy(*(Player **)(iVar2 + 4),true);
        puVar1 = *(uint **)(this + 0xf8);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar1);
  }
  if ((this[0x189] == (Level)0x0) && (param_2)) {
    iVar4 = 1;
    this[0x189] = (Level)0x1;
    iVar2 = Status::inBlackMarketSystem(Globals::status);
    if (iVar2 != 0) {
      iVar4 = 0xc;
    }
    createRadioMessage(this,iVar4,param_1);
    this_00 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar2 = SolarSystem::getRace(this_00);
    if (iVar2 == param_1) {
      this_01 = (Station *)Status::getStation(Globals::status);
      Station::setAttackedFriends(this_01,true);
      return;
    }
  }
  return;
}

// ===== Level::createRadioMessage  @0x000d5568  (1684 bytes)
/* Level::createRadioMessage(int, int) */

void __thiscall Level::createRadioMessage(Level *this,int param_1,int param_2)

{
  Mission *this_00;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  Station *pSVar4;
  int iVar5;
  RadioMessage *pRVar6;
  uint *puVar7;
  Array *pAVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  void *pvVar12;
  int *piVar13;
  uint uVar14;
  int iVar15;
  
  if ((*(int *)(this + 0xf0) == 0) || (*(int *)(*(int *)(this + 0xf0) + 0x18) == 0)) {
    return;
  }
  this_00 = (Mission *)Status::getMission(Globals::status);
  iVar1 = Mission::isEmpty(this_00);
  if (iVar1 != 1) {
    return;
  }
  pvVar12 = *(void **)(this + 0x114);
  if (pvVar12 != (void *)0x0) {
    if (*(void **)((int)pvVar12 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar12 + 4));
    }
    operator_delete(pvVar12);
    *(undefined4 *)(this + 0x114) = 0;
  }
  puVar2 = operator_new(0xc);
  puVar3 = operator_new__(4);
  puVar2[1] = puVar3;
  puVar2[2] = 1;
  *puVar3 = 0;
  *puVar2 = 0;
  *(undefined4 **)(this + 0x114) = puVar2;
  if (param_2 == 2) {
    iVar1 = 0x41;
  }
  else if (param_2 == 0) {
    iVar1 = 0x40;
  }
  else if (param_2 == 3) {
    iVar1 = 0x15;
  }
  else {
    iVar1 = 0x3f;
    if (param_2 == 8) {
      iVar1 = 9;
    }
  }
  iVar15 = 0;
  iVar5 = 0x1ba;
  switch(param_1) {
  case 0:
    puVar7 = *(uint **)(Globals::status + 0x90);
    if ((puVar7 != (uint *)0x0) && (*puVar7 != 0)) {
      uVar14 = 0;
      do {
        iVar15 = *(int *)(puVar7[1] + uVar14 * 4);
        pSVar4 = (Station *)Status::getStation(Globals::status);
        iVar5 = Station::getIndex(pSVar4);
        if (iVar15 == iVar5) goto LAB_000d59d8;
        uVar14 = uVar14 + 1;
        puVar7 = *(uint **)(Globals::status + 0x90);
      } while (uVar14 < *puVar7);
    }
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
    iVar5 = iVar5 + 0x1aa;
    break;
  case 1:
    puVar7 = *(uint **)(Globals::status + 0x90);
    if ((puVar7 != (uint *)0x0) && (*puVar7 != 0)) {
      uVar14 = 0;
      do {
        iVar15 = *(int *)(puVar7[1] + uVar14 * 4);
        pSVar4 = (Station *)Status::getStation(Globals::status);
        iVar5 = Station::getIndex(pSVar4);
        if (iVar15 == iVar5) goto LAB_000d59d8;
        uVar14 = uVar14 + 1;
        puVar7 = *(uint **)(Globals::status + 0x90);
      } while (uVar14 < *puVar7);
    }
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
    iVar5 = iVar5 + 0x1ad;
    break;
  default:
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
    iVar5 = iVar5 + 0x1bd;
    break;
  case 3:
    this[0x1b0] = (Level)0x1;
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
    iVar5 = iVar5 + 0x1b3;
    break;
  case 4:
    this[0x68] = (Level)0x1;
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
    iVar5 = iVar5 + 0x1b6;
    break;
  case 5:
    iVar5 = 0x1bb;
    goto LAB_000d5bd8;
  case 6:
    iVar5 = 0x1bc;
    goto LAB_000d5bd8;
  case 7:
    goto switchD_000d5614_caseD_7;
  case 8:
    iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,8);
    if (iVar1 < 1) {
      iVar5 = 0;
    }
    else {
      iVar5 = 0;
      piVar13 = &DAT_002543a0;
      iVar15 = iVar1;
      do {
        iVar15 = iVar15 + -1;
        iVar5 = iVar5 + *piVar13;
        piVar13 = piVar13 + 1;
      } while (iVar15 != 0);
    }
    iVar15 = 0;
    do {
      iVar11 = iVar15 + -1;
      iVar9 = (&DAT_002541c8)[iVar5 * 2 + iVar15 * 2];
      if (iVar15 == 0) {
        iVar11 = 5000;
      }
      pRVar6 = operator_new(0x28);
      iVar10 = 6;
      if (iVar15 == 0) {
        iVar10 = 5;
      }
      RadioMessage::RadioMessage
                (pRVar6,(&DAT_002541c8)[iVar5 * 2 + iVar15 * 2 + 1],iVar9,iVar10,iVar11);
      piVar13 = *(int **)(this + 0x114);
      piVar13[2] = *piVar13 + 1;
      pvVar12 = realloc((void *)piVar13[1],(*piVar13 + 1) * 4);
      piVar13[1] = (int)pvVar12;
      iVar15 = iVar15 + 1;
      *(RadioMessage **)((int)pvVar12 + *piVar13 * 4) = pRVar6;
      *piVar13 = piVar13[2];
    } while (iVar15 < (int)(&DAT_002543a0)[iVar1]);
    goto LAB_000d5c14;
  case 9:
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
    iVar5 = iVar5 + 0x1c1;
    break;
  case 10:
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
    iVar5 = iVar5 + 0x1c3;
    break;
  case 0xb:
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
    iVar5 = iVar5 + 0x1c5;
    break;
  case 0xc:
    iVar15 = 0;
    iVar5 = 0x1c5;
    goto switchD_000d5614_caseD_7;
  case 0xd:
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
    iVar5 = iVar5 + 0x1c7;
    break;
  case 0xe:
    puVar7 = *(uint **)(Globals::status + 0x90);
    if ((puVar7 == (uint *)0x0) || (*puVar7 == 0)) {
      iVar15 = 0;
      iVar5 = 0x88f;
    }
    else {
      iVar5 = 0x88f;
      uVar14 = 0;
      iVar15 = 0;
      do {
        iVar9 = uVar14 * 4;
        uVar14 = uVar14 + 1;
        if (-1 < *(int *)(puVar7[1] + iVar9)) {
          iVar5 = iVar5 + -2;
        }
      } while (uVar14 < *puVar7);
    }
    goto switchD_000d5614_caseD_7;
  case 0xf:
    puVar7 = *(uint **)(Globals::status + 0x90);
    if ((puVar7 != (uint *)0x0) && (*puVar7 != 0)) {
      iVar5 = 0x88e;
      uVar14 = 0;
      do {
        iVar1 = uVar14 * 4;
        uVar14 = uVar14 + 1;
        if (-1 < *(int *)(puVar7[1] + iVar1)) {
          iVar5 = iVar5 + -2;
        }
      } while (uVar14 < *puVar7);
      if (iVar5 - 0x889U < 5) goto LAB_000d5bd8;
    }
LAB_000d59de:
    if ((void *)puVar2[1] != (void *)0x0) {
      operator_delete__((void *)puVar2[1]);
    }
    operator_delete(puVar2);
    goto LAB_000d59ec;
  case 0x10:
    if (param_2 < 1) {
      iVar1 = 0;
    }
    else {
      iVar1 = 0;
      piVar13 = &DAT_00254270;
      iVar5 = param_2;
      do {
        iVar5 = iVar5 + -1;
        iVar1 = iVar1 + *piVar13;
        piVar13 = piVar13 + 1;
      } while (iVar5 != 0);
    }
    if ((param_2 | 1U) == 1) {
      uVar14 = iVar1 << 1;
      iVar1 = 0;
      iVar5 = 0;
      do {
        iVar15 = iVar5 + -1;
        if (iVar1 == 0) {
          iVar15 = 5000;
        }
        pRVar6 = operator_new(0x28);
        iVar11 = 6;
        iVar9 = *(int *)(&UNK_002542d4 + uVar14 * 4);
        if ((0x111U >> (uVar14 & 0xff) & 1) != 0) {
          iVar9 = iVar9 + param_2;
        }
        if (iVar1 == 0) {
          iVar11 = 5;
        }
        RadioMessage::RadioMessage(pRVar6,*(int *)(&UNK_002542d8 + uVar14 * 4),iVar9,iVar11,iVar15);
        piVar13 = *(int **)(this + 0x114);
        piVar13[2] = *piVar13 + 1;
        pvVar12 = realloc((void *)piVar13[1],(*piVar13 + 1) * 4);
        piVar13[1] = (int)pvVar12;
        uVar14 = uVar14 + 2;
        iVar1 = iVar1 + -1;
        iVar5 = iVar5 + 1;
        *(RadioMessage **)((int)pvVar12 + *piVar13 * 4) = pRVar6;
        *piVar13 = piVar13[2];
      } while (iVar5 < (int)(&DAT_00254270)[param_2]);
    }
    if ((param_2 | 4U) != 6) {
      iVar1 = *(int *)(this + 0xf0);
      pAVar8 = *(Array **)(this + 0x114);
      goto LAB_000d5c1c;
    }
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,5);
    iVar1 = param_2 + 10000;
    iVar5 = iVar5 + 0xc4a;
    iVar15 = 0;
    goto switchD_000d5614_caseD_7;
  case 0x11:
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,5);
    iVar5 = iVar5 + 0xc4f;
    iVar1 = 0;
    iVar15 = *(int *)(*(int *)(*(int *)(this + 0xf0) + 0x10) + 8) + 6000;
    goto switchD_000d5614_caseD_7;
  case 0x12:
    if (param_2 < 1) {
      iVar1 = 0;
    }
    else {
      iVar1 = 0;
      piVar13 = &DAT_002542fc;
      iVar5 = param_2;
      do {
        iVar5 = iVar5 + -1;
        iVar1 = iVar1 + *piVar13;
        piVar13 = piVar13 + 1;
      } while (iVar5 != 0);
    }
    if ((param_2 | 1U) != 1) {
      iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,5);
      iVar5 = iVar5 + 0xc45;
      goto LAB_000d5bd8;
    }
    uVar14 = iVar1 << 1;
    iVar1 = 0;
    iVar5 = 0;
    do {
      iVar15 = iVar5 + -1;
      if (iVar1 == 0) {
        iVar15 = 5000;
      }
      pRVar6 = operator_new(0x28);
      iVar11 = 6;
      iVar9 = *(int *)(&UNK_002543c0 + uVar14 * 4);
      if ((uVar14 | 4) == 6) {
        iVar9 = iVar9 + param_2;
      }
      if (iVar1 == 0) {
        iVar11 = 5;
      }
      RadioMessage::RadioMessage(pRVar6,*(int *)(&UNK_002543c4 + uVar14 * 4),iVar9,iVar11,iVar15);
      piVar13 = *(int **)(this + 0x114);
      piVar13[2] = *piVar13 + 1;
      pvVar12 = realloc((void *)piVar13[1],(*piVar13 + 1) * 4);
      piVar13[1] = (int)pvVar12;
      uVar14 = uVar14 + 2;
      iVar1 = iVar1 + -1;
      iVar5 = iVar5 + 1;
      *(RadioMessage **)((int)pvVar12 + *piVar13 * 4) = pRVar6;
      *piVar13 = piVar13[2];
    } while (iVar5 < (int)(&DAT_002542fc)[param_2]);
    goto LAB_000d5c14;
  case 0x13:
    pRVar6 = operator_new(0x28);
    iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
    RadioMessage::RadioMessage(pRVar6,iVar1 + 0xaf4,0,5,0x5dc);
    piVar13 = *(int **)(this + 0x114);
    piVar13[2] = *piVar13 + 1;
    pvVar12 = realloc((void *)piVar13[1],(*piVar13 + 1) * 4);
    piVar13[1] = (int)pvVar12;
    *(RadioMessage **)((int)pvVar12 + *piVar13 * 4) = pRVar6;
    *piVar13 = piVar13[2];
    pRVar6 = operator_new(0x28);
    iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
    RadioMessage::RadioMessage(pRVar6,iVar1 + 0xafa,0,6,0);
    goto LAB_000d5bf6;
  case 0x15:
    iVar5 = 0xc54;
    goto LAB_000d5bd8;
  case 0x16:
    iVar5 = 0xc55;
    goto LAB_000d5bd8;
  case 0x17:
    iVar5 = 0xc56;
    goto LAB_000d5bd8;
  case 0x18:
    iVar5 = 0xc57;
    goto LAB_000d5bd8;
  case 0x19:
    iVar5 = 0xc58;
    goto LAB_000d5bd8;
  case 0x1a:
    iVar5 = 0xc59;
LAB_000d5bd8:
    iVar1 = 0;
    break;
  case 0x1b:
    pRVar6 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar6,param_2 * 2 + 0xc60,6,5,0x5dc);
    piVar13 = *(int **)(this + 0x114);
    piVar13[2] = *piVar13 + 1;
    pvVar12 = realloc((void *)piVar13[1],(*piVar13 + 1) * 4);
    piVar13[1] = (int)pvVar12;
    *(RadioMessage **)((int)pvVar12 + *piVar13 * 4) = pRVar6;
    *piVar13 = piVar13[2];
    pRVar6 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar6,param_2 * 2 + 0xc61,0,6,0);
    goto LAB_000d5bf6;
  case 0x1c:
    iVar15 = 0;
    iVar1 = 0x26;
    iVar5 = param_2;
    goto switchD_000d5614_caseD_7;
  }
  iVar15 = 0;
switchD_000d5614_caseD_7:
  pRVar6 = operator_new(0x28);
  RadioMessage::RadioMessage(pRVar6,iVar5,iVar1,5,iVar15);
LAB_000d5bf6:
  piVar13 = *(int **)(this + 0x114);
  piVar13[2] = *piVar13 + 1;
  pvVar12 = realloc((void *)piVar13[1],(*piVar13 + 1) * 4);
  piVar13[1] = (int)pvVar12;
  *(RadioMessage **)((int)pvVar12 + *piVar13 * 4) = pRVar6;
  *piVar13 = piVar13[2];
LAB_000d5c14:
  iVar1 = *(int *)(this + 0xf0);
  pAVar8 = *(Array **)(this + 0x114);
LAB_000d5c1c:
  Radio::setMessages(*(Radio **)(iVar1 + 0x18),pAVar8);
  return;
LAB_000d59d8:
  puVar2 = *(undefined4 **)(this + 0x114);
  if (puVar2 != (undefined4 *)0x0) goto LAB_000d59de;
LAB_000d59ec:
  pAVar8 = (Array *)0x0;
  *(undefined4 *)(this + 0x114) = 0;
  iVar1 = *(int *)(this + 0xf0);
  goto LAB_000d5c1c;
}

// ===== Level::updateAlienAttackers  @0x000d5ce0  (680 bytes)
/* Level::updateAlienAttackers(int) */

void __thiscall Level::updateAlienAttackers(Level *this,int param_1)

{
  Mission *this_00;
  int iVar1;
  uint *puVar2;
  Station *this_01;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  KIPlayer *this_02;
  uint in_fpscr;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float local_ac;
  float local_a4;
  float local_9c;
  undefined1 auStack_90 [8];
  float local_88;
  undefined1 auStack_84 [4];
  float local_80;
  float local_78 [3];
  int local_6c;
  
  local_6c = __stack_chk_guard;
  *(int *)(this + 0x170) = *(int *)(this + 0x170) + param_1;
  this_00 = (Mission *)Status::getMission(Globals::status);
  if (((this_00 == (Mission *)0x0) || (iVar1 = Mission::isCampaignMission(this_00), iVar1 != 1)) ||
     ((iVar1 = Status::getCurrentCampaignMission(Globals::status), iVar1 != 0x28 &&
      ((iVar1 = Status::getCurrentCampaignMission(Globals::status), iVar1 != 0x93 &&
       (iVar1 = Status::getCurrentCampaignMission(Globals::status), iVar1 != 0x9a)))))) {
    iVar8 = *(int *)(this + 0x170);
    iVar1 = Status::getCurrentCampaignMission(Globals::status);
    iVar7 = 45000;
    if (iVar1 == 0x29) {
      iVar7 = 10000;
    }
    if (iVar7 < iVar8) {
      *(undefined4 *)(this + 0x170) = 0;
      puVar2 = *(uint **)(this + 0xf8);
      if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
        uVar9 = 0;
        do {
          this_02 = *(KIPlayer **)(puVar2[1] + uVar9 * 4);
          if (((*(int *)(this_02 + 0x24) == 9) && (iVar1 = KIPlayer::isDead(this_02), iVar1 == 1))
             && (iVar1 = Player::isActive(*(Player **)(this_02 + 4)), iVar1 == 0)) {
            (**(code **)(*(int *)this_02 + 0x18))(this_02);
            iVar1 = Status::inAlienOrbit(Globals::status);
            if (iVar1 == 0) {
              this_01 = (Station *)Status::getStation(Globals::status);
              iVar1 = Station::isAttackedByAliens(this_01);
              if (iVar1 == 1) {
                pcVar3 = *(code **)(*(int *)this_02 + 0x48);
                (**(code **)(**(int **)(*(int *)(*(int *)(this + 0x100) + 4) + 0xc) + 0x28))
                          (local_78);
                fVar12 = local_78[0];
                uVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
                (**(code **)(**(int **)(*(int *)(*(int *)(this + 0x100) + 4) + 0xc) + 0x28))
                          (auStack_84);
                fVar11 = local_80;
                uVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
                (**(code **)(**(int **)(*(int *)(*(int *)(this + 0x100) + 4) + 0xc) + 0x28))
                          (auStack_90);
                fVar13 = (float)VectorSignedToFloat(uVar4,(byte)(in_fpscr >> 0x16) & 3);
                fVar14 = (float)VectorSignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
                fVar15 = local_88 + -10000.0;
                uVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
                fVar10 = (float)VectorSignedToFloat(uVar4,(byte)(in_fpscr >> 0x16) & 3);
                (*pcVar3)(this_02,fVar12 + -10000.0 + fVar13,fVar11 + -10000.0 + fVar14,
                          fVar15 + fVar10);
                goto LAB_000d5f5a;
              }
            }
            pcVar3 = *(code **)(*(int *)this_02 + 0x48);
            PlayerEgo::getPosition();
            uVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,80000);
            PlayerEgo::getPosition();
            uVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,60000);
            PlayerEgo::getPosition();
            fVar12 = (float)VectorSignedToFloat(uVar4,(byte)(in_fpscr >> 0x16) & 3);
            fVar10 = (float)VectorSignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
            uVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
            puVar6 = &DAT_000d5fbc;
            fVar11 = (float)VectorSignedToFloat(uVar4,(byte)(in_fpscr >> 0x16) & 3);
            in_fpscr = in_fpscr & 0xfffffff | (uint)(local_ac + fVar11 == 0.0) << 0x1e;
            if ((byte)(in_fpscr >> 0x1e) != 0) {
              puVar6 = &DAT_000d5fc0;
            }
            (*pcVar3)(this_02,local_9c + -40000.0 + fVar12,local_a4 + -30000.0 + fVar10,*puVar6);
          }
LAB_000d5f5a:
          puVar2 = *(uint **)(this + 0xf8);
          uVar9 = uVar9 + 1;
        } while (uVar9 < *puVar2);
      }
    }
  }
  if (__stack_chk_guard != local_6c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Level::updateAsteroidCluster  @0x000d5fc8  (2 bytes)
/* Level::updateAsteroidCluster() */

void Level::updateAsteroidCluster(void)

{
  return;
}

// ===== Level::update  @0x000d5fcc  (748 bytes)
/* Level::update(long long, bool) */

void Level::update(longlong param_1,bool param_2)

{
  undefined4 uVar1;
  undefined1 auVar2 [16];
  byte bVar3;
  Status *this;
  Level *this_00;
  uint uVar4;
  int iVar5;
  Mission *this_01;
  Station *pSVar6;
  uint *puVar7;
  int *piVar8;
  int iVar9;
  Ship *this_02;
  Item *this_03;
  undefined4 extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  undefined4 extraout_r1_03;
  int extraout_r1_04;
  int extraout_r1_05;
  int extraout_r1_06;
  int extraout_r1_07;
  int extraout_r1_08;
  int extraout_r1_09;
  uint uVar10;
  uint in_fpscr;
  uint uVar11;
  float fVar12;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  undefined4 in_s1;
  float fVar13;
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  int in_stack_00000000;
  Vector aVStack_38 [12];
  int local_2c;
  
  this_00 = (Level *)param_1;
  uVar10 = (uint)param_2;
  local_2c = __stack_chk_guard;
  if (this_00[0x158] != (Level)0x0) {
    uVar4 = *(int *)(this_00 + 0x150) - uVar10;
    *(uint *)(this_00 + 0x150) = uVar4;
    if (0x7fffffff < uVar4) {
      this_00[0x158] = (Level)0x0;
    }
    fVar13 = (float)VectorSignedToFloat(uVar4,(byte)(in_fpscr >> 0x16) & 3);
    fVar12 = (float)VectorSignedToFloat(*(undefined4 *)(this_00 + 0x154),
                                        (byte)(in_fpscr >> 0x16) & 3);
    uVar1 = VectorGetElement(CONCAT44(in_s1,fVar13 / fVar12),0,4,0);
    auVar14 = VectorMultiply(*(undefined1 (*) [16])(this_00 + 0x140),uVar1,4);
    auVar15._4_4_ = i_g;
    auVar15._0_4_ = i_r;
    auVar15._8_4_ = i_b;
    auVar15._12_4_ = i_a;
    auVar15 = FloatVectorCompareGreaterThan(auVar15,auVar14,2);
    auVar2._4_4_ = i_g;
    auVar2._0_4_ = i_r;
    auVar2._8_4_ = i_b;
    auVar2._12_4_ = i_a;
    auVar15 = VectorBitwiseSelect(auVar15,auVar2,auVar14);
    *(longlong *)(this_00 + 0x140) = auVar15._0_8_;
    *(longlong *)(this_00 + 0x148) = auVar15._8_8_;
  }
  iVar5 = Status::getMission(Globals::status);
  if (iVar5 != 0) {
    this_01 = (Mission *)Status::getMission(Globals::status);
    iVar5 = Mission::isEmpty(this_01);
    if (iVar5 != 1) {
      updateMissionOrbit(this_00,uVar10);
      goto LAB_000d608e;
    }
  }
  updateOrbit(this_00,uVar10);
LAB_000d608e:
  pSVar6 = (Station *)Status::getStation(Globals::status);
  iVar5 = Station::isAttackedByAliens(pSVar6);
  if ((iVar5 != 0) || (iVar5 = Status::inAlienOrbit(Globals::status), iVar5 == 1)) {
    updateAlienAttackers(this_00,uVar10);
  }
  puVar7 = *(uint **)(this_00 + 0xe4);
  if ((puVar7 != (uint *)0x0) && (*puVar7 != 0)) {
    uVar4 = 0;
    do {
      piVar8 = *(int **)(puVar7[1] + uVar4 * 4);
      (**(code **)(*piVar8 + 0x10))(piVar8,uVar10);
      puVar7 = *(uint **)(this_00 + 0xe4);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar7);
  }
  puVar7 = *(uint **)(this_00 + 0xe8);
  if ((puVar7 != (uint *)0x0) && (*puVar7 != 0)) {
    uVar4 = 0;
    do {
      piVar8 = *(int **)(puVar7[1] + uVar4 * 4);
      (**(code **)(*piVar8 + 0x10))(piVar8,uVar10);
      puVar7 = *(uint **)(this_00 + 0xe8);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar7);
  }
  this = Globals::status;
  pSVar6 = (Station *)Status::getStation(Globals::status);
  iVar5 = Station::getIndex(pSVar6);
  iVar9 = Status::getCurrentCampaignMission(Globals::status);
  fVar12 = (float)Status::getGammaRayDamagePerSecond(this,iVar5,iVar9);
  iVar5 = *(int *)(this_00 + 0xf0);
  uVar4 = in_fpscr & 0xfffffff | (uint)(fVar12 < 0.0) << 0x1f | (uint)(fVar12 == 0.0) << 0x1e;
  uVar11 = uVar4 | (uint)NAN(fVar12) << 0x1c;
  bVar3 = (byte)(uVar4 >> 0x18);
  if ((!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(uVar11 >> 0x1c) & 1)) && (iVar5 != 0)) {
    this_02 = (Ship *)Status::getShip(Globals::status);
    this_03 = (Item *)Ship::getFirstEquipmentOfSort(this_02,0x26);
    fVar12 = extraout_s0;
    if ((this_03 != (Item *)0x0) &&
       (iVar5 = Item::getAttribute(this_03,0x34), fVar12 = extraout_s0_00, 0 < iVar5)) {
      fVar12 = (float)VectorSignedToFloat(iVar5,(byte)(uVar11 >> 0x16) & 3);
      fVar12 = (100.0 - fVar12) / 100.0;
    }
    __aeabi_l2f(fVar12,uVar10);
    iVar5 = Player::getGammaHP((Player *)**(undefined4 **)(this_00 + 0xf0));
    Player::damageGamma((Player *)**(undefined4 **)(this_00 + 0xf0),extraout_s0_01);
    if ((0xe < iVar5) &&
       (iVar5 = Player::getGammaHP((Player *)**(undefined4 **)(this_00 + 0xf0)), iVar5 < 0xf)) {
      iVar5 = PlayerEgo::getHUD(*(PlayerEgo **)(this_00 + 0xf0));
      Hud::hudEvent(iVar5,(PlayerEgo *)0x2c,*(int *)(this_00 + 0xf0));
    }
    iVar5 = *(int *)(this_00 + 0xf0);
  }
  if (iVar5 != 0) {
    if (*(int *)(this_00 + 0x80) != 0) {
      PlayerEgo::getPosition();
      AbyssEngine::AEMath::Vector::operator=((Vector *)(this_00 + 0xb4),aVStack_38);
      ParticleSystemManager::update(CONCAT44(extraout_r1,*(undefined4 *)(this_00 + 0x80)));
      iVar5 = extraout_r1_00;
    }
    if (*(int *)(this_00 + 0x74) != 0) {
      ParticleSystemManager::update(CONCAT44(iVar5,*(int *)(this_00 + 0x74)));
      iVar5 = extraout_r1_01;
    }
    if (*(int *)(this_00 + 0x78) != 0) {
      ParticleSystemManager::update(CONCAT44(iVar5,*(int *)(this_00 + 0x78)));
      iVar5 = extraout_r1_02;
    }
    if (*(int *)(this_00 + 0x88) != 0) {
      PlayerEgo::getPosition();
      AbyssEngine::AEMath::Vector::operator=((Vector *)(this_00 + 0xb4),aVStack_38);
      ParticleSystemManager::update(CONCAT44(extraout_r1_03,*(undefined4 *)(this_00 + 0x88)));
      iVar5 = extraout_r1_04;
    }
    if (*(int *)(this_00 + 0x7c) != 0) {
      ParticleSystemManager::update(CONCAT44(iVar5,*(int *)(this_00 + 0x7c)));
      iVar5 = extraout_r1_05;
    }
    if (*(int *)(this_00 + 0x84) != 0) {
      ParticleSystemManager::update(CONCAT44(iVar5,*(int *)(this_00 + 0x84)));
      iVar5 = extraout_r1_06;
    }
    if (*(int *)(this_00 + 0x8c) != 0) {
      ParticleSystemManager::update(CONCAT44(iVar5,*(int *)(this_00 + 0x8c)));
      iVar5 = extraout_r1_07;
    }
    if (*(int *)(this_00 + 0x98) != 0) {
      ParticleSystemManager::update(CONCAT44(iVar5,*(int *)(this_00 + 0x98)));
      iVar5 = extraout_r1_08;
    }
    if (*(int *)(this_00 + 0x94) != 0) {
      ParticleSystemManager::update(CONCAT44(iVar5,*(int *)(this_00 + 0x94)));
      iVar5 = extraout_r1_09;
    }
    if (*(int *)(this_00 + 0x9c) != 0) {
      ParticleSystemManager::update(CONCAT44(iVar5,*(int *)(this_00 + 0x9c)));
    }
  }
  if (in_stack_00000000 == 0) {
    LODManager::update(*(LODManager **)this_00,uVar10);
  }
  if (__stack_chk_guard != local_2c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Level::checkObjective  @0x000d62f0  (18 bytes)
/* Level::checkObjective(int) */

undefined4 __thiscall Level::checkObjective(Level *this,int param_1)

{
  undefined4 uVar1;
  
  if (*(Objective **)(this + 0x28) != (Objective *)0x0) {
    uVar1 = Objective::achieved(*(Objective **)(this + 0x28),param_1);
    return uVar1;
  }
  return 0;
}

// ===== Level::stealFriendCargo  @0x000d6302  (8 bytes)
/* Level::stealFriendCargo() */

void __thiscall Level::stealFriendCargo(Level *this)

{
  this[0x13c] = (Level)0x1;
  return;
}

// ===== Level::friendCargoWasStolen  @0x000d630a  (6 bytes)
/* Level::friendCargoWasStolen() */

Level __thiscall Level::friendCargoWasStolen(Level *this)

{
  return this[0x13c];
}

// ===== Level::removeObjectives  @0x000d6310  (8 bytes)
/* Level::removeObjectives() */

void __thiscall Level::removeObjectives(Level *this)

{
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  return;
}

// ===== Level::getPlayerGuns  @0x000d6318  (6 bytes)
/* Level::getPlayerGuns() */

undefined4 __thiscall Level::getPlayerGuns(Level *this)

{
  return *(undefined4 *)(this + 0xe4);
}

// ===== Level::getEnemyGuns  @0x000d631e  (6 bytes)
/* Level::getEnemyGuns() */

undefined4 __thiscall Level::getEnemyGuns(Level *this)

{
  return *(undefined4 *)(this + 0xe8);
}

// ===== Level::checkGameOver  @0x000d6324  (18 bytes)
/* Level::checkGameOver(int) */

undefined4 __thiscall Level::checkGameOver(Level *this,int param_1)

{
  undefined4 uVar1;
  
  if (*(Objective **)(this + 0x2c) != (Objective *)0x0) {
    uVar1 = Objective::achieved(*(Objective **)(this + 0x2c),param_1);
    return uVar1;
  }
  return 0;
}

// ===== Level::pirateStationAction  @0x000d6338  (106 bytes)
/* Level::pirateStationAction(bool) */

void __thiscall Level::pirateStationAction(Level *this,bool param_1)

{
  Station *pSVar1;
  int iVar2;
  int iVar3;
  
  if (param_1) {
    if (this[0x1b0] == (Level)0x0) {
LAB_000d638a:
      iVar2 = 4;
      if (param_1) {
        iVar2 = 3;
      }
      createRadioMessage(this,iVar2,8);
      return;
    }
  }
  else if (this[0x68] == (Level)0x0) {
    pSVar1 = (Station *)Status::getStation(Globals::status);
    iVar2 = Station::getPirateStationIndex(pSVar1);
    if (-1 < iVar2) {
      iVar3 = *(int *)(Globals::status + 0x4c);
      pSVar1 = (Station *)Status::getStation(Globals::status);
      iVar2 = Station::getPirateStationIndex(pSVar1);
      *(undefined1 *)(*(int *)(iVar3 + 4) + iVar2) = 1;
      Globals::status[0xf9] = (Status)0x1;
      goto LAB_000d638a;
    }
  }
  return;
}

// ===== Level::uncoverWanted  @0x000d63ac  (118 bytes)
/* Level::uncoverWanted(int) */

void __thiscall Level::uncoverWanted(Level *this,int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if (this[0x29c] == (Level)0x0) {
    createRadioMessage(this,0x12,param_1);
    iVar2 = Wanted::getNumWingmen(*(Wanted **)(*(int *)(*Globals::status + 4) + param_1 * 4));
    if (0 < iVar2) {
      iVar2 = 1;
      do {
        Player::setAlwaysEnemy
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar2 * 4) + 4),true)
        ;
        Player::turnEnemy(*(Player **)
                           (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar2 * 4) + 4));
        iVar3 = Wanted::getNumWingmen(*(Wanted **)(*(int *)(*Globals::status + 4) + param_1 * 4));
        bVar1 = iVar2 < iVar3;
        iVar2 = iVar2 + 1;
      } while (bVar1);
    }
  }
  return;
}

// ===== Level::attackWanted  @0x000d642c  (124 bytes)
/* Level::attackWanted(int) */

void __thiscall Level::attackWanted(Level *this,int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if (this[0x29c] == (Level)0x0) {
    this[0x29c] = (Level)0x1;
    createRadioMessage(this,0x10,param_1);
    iVar2 = Wanted::getNumWingmen(*(Wanted **)(*(int *)(*Globals::status + 4) + param_1 * 4));
    if (0 < iVar2) {
      iVar2 = 1;
      do {
        Player::setAlwaysEnemy
                  (*(Player **)(*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar2 * 4) + 4),true)
        ;
        Player::turnEnemy(*(Player **)
                           (*(int *)(*(int *)(*(int *)(this + 0xf8) + 4) + iVar2 * 4) + 4));
        iVar3 = Wanted::getNumWingmen(*(Wanted **)(*(int *)(*Globals::status + 4) + param_1 * 4));
        bVar1 = iVar2 < iVar3;
        iVar2 = iVar2 + 1;
      } while (bVar1);
    }
  }
  return;
}

// ===== Level::almostKillWanted  @0x000d64b0  (248 bytes)
/* Level::almostKillWanted(int) */

void __thiscall Level::almostKillWanted(Level *this,int param_1)

{
  int iVar1;
  Mission *this_00;
  Station *this_01;
  void *pvVar2;
  Objective *this_02;
  
  if (this[0x29e] == (Level)0x0) {
    this[0x29e] = (Level)0x1;
    iVar1 = Status::isStorylineWanted(Globals::status,param_1);
    if (iVar1 == 1) {
      this_00 = operator_new(100);
      this_01 = (Station *)Status::getStation(Globals::status);
      iVar1 = Station::getIndex(this_01);
      Mission::Mission(this_00,4,0,iVar1);
      Mission::setCampaignMission(this_00,true);
      Mission::setWon(this_00,true);
      Status::setMission(Globals::status,this_00);
      Status::setCampaignMission(Globals::status,this_00);
      if (*(Objective **)(this + 0x28) != (Objective *)0x0) {
        pvVar2 = (void *)Objective::~Objective(*(Objective **)(this + 0x28));
        operator_delete(pvVar2);
      }
      *(undefined4 *)(this + 0x28) = 0;
      this_02 = operator_new(0x1c);
      Objective::Objective(this_02,3,0,0,this);
      *(Objective **)(this + 0x28) = this_02;
      Player::setAlwaysEnemy(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4),false);
      Player::resetDamageDoneByPlayer(*(Player **)(**(int **)(*(int *)(this + 0xf8) + 4) + 4));
      iVar1 = **(int **)(*(int *)(this + 0xf8) + 4);
      *(undefined1 *)(*(int *)(iVar1 + 4) + 0x5c) = 0;
      *(undefined1 *)(iVar1 + 0x3f) = 1;
      iVar1 = Status::getWanted(Globals::status);
      Wanted::setActive(*(Wanted **)(*(int *)(iVar1 + 4) + param_1 * 4),false);
      return;
    }
  }
  return;
}

// ===== Level::killWanted  @0x000d65c8  (22 bytes)
/* Level::killWanted(int) */

void Level::killWanted(int param_1)

{
  if (*(char *)(param_1 + 0x29d) == '\0') {
    *(undefined1 *)(param_1 + 0x29d) = 1;
    createRadioMessage((Level *)param_1,0x11,0);
    return;
  }
  return;
}

// ===== Level::friendTurnedEnemy  @0x000d65de  (24 bytes)
/* Level::friendTurnedEnemy(int) */

void Level::friendTurnedEnemy(int param_1)

{
  int in_r1;
  
  if (*(char *)(param_1 + 0x188) == '\0') {
    *(undefined1 *)(param_1 + 0x188) = 1;
    createRadioMessage((Level *)param_1,0,in_r1);
    return;
  }
  return;
}

// ===== Level::enableFog  @0x000d65f4  (12 bytes)
/* Level::enableFog(bool) */

void __thiscall Level::enableFog(Level *this,bool param_1)

{
  ParticleSystemManager::enableSystemRender
            (*(ParticleSystemManager **)(this + 0x7c),*(int *)(this + 0x284),param_1);
  return;
}

// ===== Level::enableMovingStars  @0x000d6600  (20 bytes)
/* Level::enableMovingStars(bool) */

void __thiscall Level::enableMovingStars(Level *this,bool param_1)

{
  if (*(int *)(this + 100) < 0) {
    return;
  }
  ParticleSystemManager::enableSystemRender
            (*(ParticleSystemManager **)(this + 0x88),*(int *)(this + 100),param_1);
  return;
}

// ===== Level::reset  @0x000d6612  (262 bytes)
/* Level::reset() */

void __thiscall Level::reset(Level *this)

{
  ushort uVar1;
  uint *puVar2;
  KIPlayer *this_00;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  
  if (*(Route **)(this + 0x108) != (Route *)0x0) {
    Route::reset(*(Route **)(this + 0x108));
  }
  if (*(Route **)(this + 0x110) != (Route *)0x0) {
    Route::reset(*(Route **)(this + 0x110));
  }
  if (*(Route **)(this + 0x10c) != (Route *)0x0) {
    Route::reset(*(Route **)(this + 0x10c));
  }
  puVar2 = *(uint **)(this + 0xf8);
  if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
    uVar5 = 0;
    do {
      KIPlayer::reset(*(KIPlayer **)(puVar2[1] + uVar5 * 4));
      puVar2 = *(uint **)(this + 0xf8);
      uVar5 = uVar5 + 1;
    } while (uVar5 < *puVar2);
  }
  createPlayer(this);
  assignGuns(this);
  connectPlayers(this);
  puVar2 = *(uint **)(this + 0x114);
  if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
    uVar5 = 0;
    do {
      RadioMessage::reset(*(RadioMessage **)(puVar2[1] + uVar5 * 4));
      puVar2 = *(uint **)(this + 0x114);
      uVar5 = uVar5 + 1;
    } while (uVar5 < *puVar2);
  }
  PlayerEgo::setRoute(*(PlayerEgo **)(this + 0xf0),*(Route **)(this + 0x108));
  puVar2 = *(uint **)(this + 0xf8);
  if (puVar2 == (uint *)0x0) {
LAB_000d66f2:
    iVar6 = 0;
  }
  else {
    if (*puVar2 == 0) {
      iVar6 = 0;
    }
    else {
      uVar5 = 0;
      iVar6 = 0;
      do {
        this_00 = *(KIPlayer **)(puVar2[1] + uVar5 * 4);
        if (((this_00[0x3d] == (KIPlayer)0x0) && (this_00[0x6d] == (KIPlayer)0x0)) &&
           (this_00[0x3b] == (KIPlayer)0x0)) {
          iVar3 = KIPlayer::isWingMan(this_00);
          puVar2 = *(uint **)(this + 0xf8);
          if (((iVar3 == 0) &&
              (iVar3 = *(int *)(puVar2[1] + uVar5 * 4), *(char *)(iVar3 + 0x40) == '\0')) &&
             (uVar1 = *(ushort *)(iVar3 + 0x38), (uVar1 & 0xff) == 0)) {
            iVar6 = iVar6 + (uVar1 >> 8 ^ 1);
          }
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < *puVar2);
      if (puVar2 == (uint *)0x0) goto LAB_000d66f2;
    }
    iVar6 = iVar6 - *(int *)(this + 0x120);
  }
  *(int *)(this + 0x118) = iVar6;
  uVar4 = 0;
  if (*(undefined4 **)(this + 0xfc) != (undefined4 *)0x0) {
    uVar4 = **(undefined4 **)(this + 0xfc);
  }
  *(undefined4 *)(this + 0x128) = uVar4;
  *(undefined4 *)(this + 300) = 0;
  return;
}

// ===== Level::switchSkyboxForIntro  @0x000d6718  (78 bytes)
/* Level::switchSkyboxForIntro() */

void __thiscall Level::switchSkyboxForIntro(Level *this)

{
  uint *puVar1;
  uint uVar2;
  
  AbyssEngine::PaintCanvas::MeshCreate(Globals::Canvas,0x4591,(uint *)(this + 4),false);
  AbyssEngine::PaintCanvas::TextureCreate(Globals::Canvas,0x275a,(uint *)(this + 0x198),false);
  puVar1 = *(uint **)(this + 0xfc);
  if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
    uVar2 = 0;
    do {
      KIPlayer::setDead(*(KIPlayer **)(puVar1[1] + uVar2 * 4));
      puVar1 = *(uint **)(this + 0xfc);
      uVar2 = uVar2 + 1;
    } while (uVar2 < *puVar1);
  }
  return;
}

// ===== Level::switchSkyboxForSupernovaReversal  @0x000d676c  (94 bytes)
/* Level::switchSkyboxForSupernovaReversal() */

void __thiscall Level::switchSkyboxForSupernovaReversal(Level *this)

{
  PaintCanvas *pPVar1;
  short sVar2;
  SolarSystem *pSVar3;
  
  pPVar1 = Globals::Canvas;
  pSVar3 = (SolarSystem *)Status::getSystem(Globals::status);
  sVar2 = SolarSystem::getTextureIndex(pSVar3);
  AbyssEngine::PaintCanvas::MeshCreate(pPVar1,sVar2 + 0x4588,(uint *)(this + 4),false);
  pPVar1 = Globals::Canvas;
  pSVar3 = (SolarSystem *)Status::getSystem(Globals::status);
  sVar2 = SolarSystem::getTextureIndex(pSVar3);
  AbyssEngine::PaintCanvas::TextureCreate(pPVar1,sVar2 + 0x2751,(uint *)(this + 0x198),false);
  *(undefined4 *)(this + 0xc) = 0xffffffff;
  return;
}

// ===== Level::getNumDockingTargets  @0x000d67d4  (44 bytes)
/* Level::getNumDockingTargets() */

int __thiscall Level::getNumDockingTargets(Level *this)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  puVar2 = *(uint **)(this + 0xf8);
  if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
    uVar4 = 0;
    iVar3 = 0;
    do {
      iVar1 = uVar4 * 4;
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + (uint)*(byte *)(*(int *)(puVar2[1] + iVar1) + 0x6c);
    } while (uVar4 < *puVar2);
    return iVar3;
  }
  return 0;
}

// ===== Level::getDockingTarget  @0x000d6800  (54 bytes)
/* Level::getDockingTarget(int) */

int __thiscall Level::getDockingTarget(Level *this,int param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  puVar1 = *(uint **)(this + 0xf8);
  if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
    uVar4 = 0;
    iVar3 = 0;
    do {
      iVar2 = *(int *)(puVar1[1] + uVar4 * 4);
      if (*(char *)(iVar2 + 0x6c) != '\0') {
        if (iVar3 == param_1) {
          return iVar2;
        }
        iVar3 = iVar3 + 1;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar1);
  }
  return 0;
}

// ===== Level::hasMiningPlant  @0x000d6836  (14 bytes)
/* Level::hasMiningPlant() */

bool __thiscall Level::hasMiningPlant(Level *this)

{
  return 0 < *(int *)(this + 0x28c);
}

// ===== Level::getMiningPlant  @0x000d6844  (22 bytes)
/* Level::getMiningPlant() */

undefined4 __thiscall Level::getMiningPlant(Level *this)

{
  undefined4 uVar1;
  
  if (*(int *)(this + 0xac) < 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(*(int *)(this + 0xf8) + 4) + *(int *)(this + 0xac) * 4);
  }
  return uVar1;
}

// ===== Level::getNumDeliveredOre  @0x000d685a  (6 bytes)
/* Level::getNumDeliveredOre() */

undefined4 __thiscall Level::getNumDeliveredOre(Level *this)

{
  return *(undefined4 *)(this + 0x290);
}

// ===== Level::incNumDeliveredOre  @0x000d6860  (12 bytes)
/* Level::incNumDeliveredOre(int) */

void __thiscall Level::incNumDeliveredOre(Level *this,int param_1)

{
  *(int *)(this + 0x290) = param_1 + *(int *)(this + 0x290);
  return;
}

// ===== Level::getNumDeliveredPassengers  @0x000d686c  (6 bytes)
/* Level::getNumDeliveredPassengers() */

undefined4 __thiscall Level::getNumDeliveredPassengers(Level *this)

{
  return *(undefined4 *)(this + 0x294);
}

// ===== Level::incNumDeliveredPassengers  @0x000d6872  (12 bytes)
/* Level::incNumDeliveredPassengers(int) */

void __thiscall Level::incNumDeliveredPassengers(Level *this,int param_1)

{
  *(int *)(this + 0x294) = param_1 + *(int *)(this + 0x294);
  return;
}

