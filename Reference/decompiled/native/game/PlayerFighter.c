// Class: PlayerFighter
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== PlayerFighter::PlayerFighter  @0x000efec0  (1484 bytes)
/* PlayerFighter::PlayerFighter(int, int, Player*, AEGeometry*, float, float, float, bool) */

void __thiscall
PlayerFighter::PlayerFighter
          (PlayerFighter *this,int param_1,int param_2,Player *param_3,AEGeometry *param_4,
          float param_5,float param_6,float param_7,bool param_8)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  Route *pRVar5;
  Generator *this_00;
  void *pvVar6;
  Explosion *this_01;
  int iVar7;
  uint uVar8;
  uint in_fpscr;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  float fVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined3 in_stack_00000005;
  char local_d4 [4];
  int local_d0 [13];
  float local_9c [4];
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  int local_6c;
  
  local_6c = __stack_chk_guard;
  KIPlayer::KIPlayer((KIPlayer *)this,param_1,-1,param_3,param_4,param_5,param_6,param_7,param_8);
  *(undefined ***)this = &PTR__PlayerFighter_002640c8;
  *(undefined4 *)(this + 0x1f8) = 0;
  *(undefined4 *)(this + 0x1fc) = 0;
  *(undefined4 *)(this + 0x200) = 0;
  __aeabi_memclr4((Vector *)(this + 0x154),0x48);
  uVar9 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar10 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar11 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x210) = 0x3f800000;
  *(undefined4 *)(this + 0x214) = 0;
  *(undefined4 *)(this + 0x218) = uVar9;
  *(undefined4 *)(this + 0x21c) = uVar10;
  *(undefined4 *)(this + 0x220) = uVar11;
  *(undefined4 *)(this + 0x224) = 0x3f800000;
  *(undefined4 *)(this + 0x228) = 0;
  *(undefined4 *)(this + 0x22c) = uVar9;
  *(undefined4 *)(this + 0x230) = uVar10;
  *(undefined4 *)(this + 0x234) = uVar11;
  *(undefined8 *)(this + 0x238) = 0x3f800000;
  *(undefined8 *)(this + 0x240) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0x248) = 0x3f800000;
  *(undefined4 *)(this + 0x250) = 0x3f800000;
  *(undefined4 *)(this + 0x254) = 0;
  *(undefined4 *)(this + 600) = uVar9;
  *(undefined4 *)(this + 0x25c) = uVar10;
  *(undefined4 *)(this + 0x260) = uVar11;
  *(undefined4 *)(this + 0x264) = 0x3f800000;
  *(undefined4 *)(this + 0x268) = 0;
  *(undefined4 *)(this + 0x26c) = uVar9;
  *(undefined4 *)(this + 0x270) = uVar10;
  *(undefined4 *)(this + 0x274) = uVar11;
  *(undefined4 *)(this + 0x278) = 0x3f800000;
  *(undefined4 *)(this + 0x27c) = 0;
  *(undefined4 *)(this + 0x280) = 0x3f800000;
  *(undefined4 *)(this + 0x284) = 0x3f800000;
  *(undefined4 *)(this + 0x288) = 0x3f800000;
  iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,25000);
  fVar12 = (float)VectorSignedToFloat(iVar1 + -30000,(byte)(in_fpscr >> 0x16) & 3);
  iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,10000);
  iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,25000);
  uVar14 = VectorSignedToFloat(iVar2 + 20000,(byte)(in_fpscr >> 0x16) & 3);
  uVar16 = VectorSignedToFloat(iVar1 + -10000,(byte)(in_fpscr >> 0x16) & 3);
  iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,25000);
  uVar17 = VectorSignedToFloat(iVar1 + 5000,(byte)(in_fpscr >> 0x16) & 3);
  iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,10000);
  iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,25000);
  uVar18 = VectorSignedToFloat(iVar2 + 20000,(byte)(in_fpscr >> 0x16) & 3);
  uVar9 = VectorSignedToFloat(iVar1 + -10000,(byte)(in_fpscr >> 0x16) & 3);
  iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,25000);
  uVar10 = VectorSignedToFloat(iVar1 + 5000,(byte)(in_fpscr >> 0x16) & 3);
  iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,10000);
  iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,25000);
  uVar11 = VectorSignedToFloat(iVar2 + 55000,(byte)(in_fpscr >> 0x16) & 3);
  uVar13 = VectorSignedToFloat(iVar1 + -10000,(byte)(in_fpscr >> 0x16) & 3);
  iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,25000);
  uVar15 = VectorSignedToFloat(iVar1 + -30000,(byte)(in_fpscr >> 0x16) & 3);
  iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,10000);
  iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,25000);
  local_70 = VectorSignedToFloat(iVar2 + 55000,(byte)(in_fpscr >> 0x16) & 3);
  local_74 = VectorSignedToFloat(iVar1 + -10000,(byte)(in_fpscr >> 0x16) & 3);
  local_9c[0] = fVar12;
  local_9c[1] = (float)uVar16;
  local_9c[2] = (float)uVar14;
  local_9c[3] = (float)uVar17;
  local_8c = uVar9;
  local_88 = uVar18;
  local_84 = uVar10;
  local_80 = uVar13;
  local_7c = uVar11;
  local_78 = uVar15;
  iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
  uVar8 = iVar1 * 3 + 6;
  uVar3 = (uint)((ulonglong)uVar8 * 4);
  local_d4[0] = '\0';
  local_d4[1] = '\0';
  local_d4[2] = '\0';
  local_d4[3] = '\0';
  if ((int)((ulonglong)uVar8 * 4 >> 0x20) != 0) {
    uVar3 = 0xffffffff;
  }
  piVar4 = operator_new__(uVar3);
  if (0 < (int)uVar8) {
    iVar1 = 0;
    do {
      do {
        iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
      } while (local_d4[iVar2] != '\0');
      local_d4[iVar2] = '\x01';
      fVar12 = local_9c[iVar2 * 3 + 1];
      piVar4[iVar1] = (int)local_9c[iVar2 * 3];
      iVar7 = iVar1 + 3;
      piVar4[iVar1 + 1] = (int)fVar12;
      piVar4[iVar1 + 2] = (int)local_9c[iVar2 * 3 + 2];
      iVar1 = iVar7;
    } while (iVar7 < (int)uVar8);
  }
  pRVar5 = operator_new(0x18);
  Route::Route(pRVar5,piVar4,uVar8);
  *(Route **)(this + 0x140) = pRVar5;
  operator_delete__(piVar4);
  if (stationRouteAliens == (Route *)0x0) {
    local_d0[0] = 40000;
    local_d0[1] = 0;
    local_d0[2] = 40000;
    local_d0[3] = 40000;
    local_d0[4] = 0;
    local_d0[5] = 0xffff63c0;
    local_d0[6] = 0xffff63c0;
    local_d0[7] = 0;
    local_d0[8] = 0xffff63c0;
    local_d0[9] = 0xffff63c0;
    local_d0[10] = 0;
    local_d0[0xb] = 40000;
    pRVar5 = operator_new(0x18);
    Route::Route(pRVar5,local_d0,0xc);
    stationRouteAliens = pRVar5;
  }
  uVar9 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar10 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar11 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 300) = 0xffffffff;
  *(undefined4 *)(this + 0x130) = 0xffffffff;
  *(undefined4 *)(this + 0x134) = 0xffffffff;
  *(undefined4 *)(this + 0x1a0) = 0x40000000;
  *(undefined4 *)(this + 0x1a4) = 0x3bf9fff6;
  *(undefined4 *)(this + 0x1a8) = 0x40000000;
  *(undefined4 *)(this + 0x1ac) = 0x5dc;
  *(undefined4 *)(this + 0x124) = 50000;
  *(undefined4 *)(this + 0x1b0) = 5;
  *(undefined4 *)(this + 0x34) = 0;
  this[0x139] = (PlayerFighter)0x0;
  *(undefined4 *)(this + 0x13c) = 0;
  this[0x129] = (PlayerFighter)0x0;
  this[0x12a] = (PlayerFighter)0x0;
  this[0x13a] = (PlayerFighter)0x0;
  *(undefined4 *)(this + 0x1f0) = 0;
  *(undefined4 *)(this + 0xd4) = 0;
  this[299] = (PlayerFighter)0x0;
  this[500] = (PlayerFighter)0x0;
  *(undefined4 *)(this + 0x144) = 0;
  *(undefined4 *)(this + 0x148) = uVar9;
  *(undefined4 *)(this + 0x14c) = uVar10;
  *(undefined4 *)(this + 0x150) = uVar11;
  *(undefined4 *)(this + 0x1c4) = 0;
  *(undefined4 *)(this + 0x1c8) = uVar9;
  *(undefined4 *)(this + 0x1cc) = uVar10;
  *(undefined4 *)(this + 0x1d0) = uVar11;
  *(undefined4 *)(this + 0x1b4) = 0;
  *(undefined4 *)(this + 0x1b8) = uVar9;
  *(undefined4 *)(this + 0x1bc) = uVar10;
  *(undefined4 *)(this + 0x1c0) = uVar11;
  *(undefined4 *)(this + 0x1d5) = 0;
  *(undefined4 *)(this + 0x1d1) = 0;
  *(undefined4 *)(this + 0x1dc) = 0;
  *(undefined4 *)(this + 0x1e0) = uVar9;
  *(undefined4 *)(this + 0x1e4) = uVar10;
  *(undefined4 *)(this + 0x1e8) = uVar11;
  *(undefined2 *)(this + 0x1ec) = 0;
  *(int *)(this + 0x24) = param_2;
  local_d0[0] = _param_8;
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x154),(Vector *)local_d0);
  this[0x48] = (PlayerFighter)0x1;
  this[0x139] = (PlayerFighter)0x1;
  *(undefined4 *)(this + 0x1e0) = *(undefined4 *)(this + 0x1a8);
  *(undefined4 *)(this + 0x1e8) = *(undefined4 *)(this + 0x1a0);
  Route::setLoop(*(Route **)(this + 0x140),true);
  Route::setLoop(stationRouteAliens,true);
  *(undefined4 *)(this + 0x68) = 0;
  iVar1 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar1 != 0x29) {
    if (param_2 == 9) {
      uVar9 = Route::clone(stationRouteAliens);
    }
    else {
      uVar9 = Route::clone(*(Route **)(this + 0x140));
    }
    *(undefined4 *)(this + 0x68) = uVar9;
  }
  this[0x129] = (PlayerFighter)0x0;
  if (param_2 == 9) {
    *(undefined4 *)(this + 0x4c) = 0;
  }
  else {
    this_00 = operator_new(1);
    Generator::Generator(this_00);
    uVar9 = Generator::getLootList(this_00,-1,-1);
    *(undefined4 *)(this + 0x4c) = uVar9;
    pvVar6 = (void *)Generator::~Generator(this_00);
    operator_delete(pvVar6);
  }
  iVar1 = Status::inAlienOrbit(Globals::status);
  uVar9 = 50000;
  if (iVar1 != 0) {
    uVar9 = 100000;
  }
  *(undefined4 *)(this + 0x124) = uVar9;
  this_01 = operator_new(0x68);
  Explosion::Explosion(this_01,0);
  *(Explosion **)(this + 0x120) = this_01;
  Explosion::addFireStreaks(this_01);
  this[0x13a] = (PlayerFighter)0x1;
  uVar9 = Player::getHitpoints(*(Player **)(this + 4));
  *(undefined4 *)(this + 0x1d0) = uVar9;
  *(undefined4 *)(this + 0x1d4) = 0;
  this[0x1d8] = (PlayerFighter)0x0;
  *(undefined4 *)(this + 0xe0) = 1;
  this[0x21] = (PlayerFighter)0x1;
  *(undefined4 *)(this + 0x19c) = 0xffffffff;
  iVar1 = Status::getCurrentCampaignMission(Globals::status);
  uVar9 = 0xffffffff;
  if ((iVar1 != 1) && (uVar9 = 0x2e, this[0xd8] != (PlayerFighter)0x0)) {
    uVar9 = 0x30;
  }
  *(undefined4 *)(this + 0xf4) = uVar9;
  *(undefined4 *)(this + 0x204) = 0;
  *(undefined4 *)(this + 0x208) = 0;
  *(undefined4 *)(this + 0x20c) = 0;
  *(undefined4 *)(this + 0x28c) = 0x443b8000;
  *(undefined4 *)(this + 0x290) = 0x41723ace;
  this[0xfc] = (PlayerFighter)0x0;
  this[0x24d] = (PlayerFighter)0x0;
  this[0x24c] = (PlayerFighter)0x0;
  *(undefined4 *)(this + 0x2b0) = 0;
  this[0x138] = (PlayerFighter)0x0;
  *(undefined4 *)(this + 0x2cc) = 0;
  *(undefined4 *)(this + 0x29d) = 0;
  *(undefined4 *)(this + 0x2a1) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x2a5) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x2a9) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x294) = 0;
  *(undefined4 *)(this + 0x298) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x29c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x2a0) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 700) = 0;
  *(undefined4 *)(this + 0x2c0) = 0;
  *(undefined4 *)(this + 0x2c5) = 0;
  *(undefined4 *)(this + 0x2c1) = 0;
  this[0x2d0] = (PlayerFighter)0x1;
  *(undefined4 *)(this + 0x2d4) = 0xffffffff;
  this[0x2dc] = (PlayerFighter)0x0;
  *(undefined4 *)(this + 0x2e0) = 0;
  if (__stack_chk_guard - local_6c == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_6c);
}

// ===== PlayerFighter::~PlayerFighter  @0x000f0550  (156 bytes)
/* PlayerFighter::~PlayerFighter() */

void __thiscall PlayerFighter::~PlayerFighter(PlayerFighter *this)

{
  void *pvVar1;
  
  *(undefined ***)this = &PTR__PlayerFighter_002640c8;
  if (*(Route **)(this + 0x140) != (Route *)0x0) {
    pvVar1 = (void *)Route::~Route(*(Route **)(this + 0x140));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x140) = 0;
  if (*(Array **)(this + 0x14c) != (Array *)0x0) {
    ArrayReleaseClasses<BoundingVolume*>(*(Array **)(this + 0x14c));
    pvVar1 = *(void **)(this + 0x14c);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x14c) = 0;
  if (*(Trail **)(this + 0x150) != (Trail *)0x0) {
    pvVar1 = (void *)Trail::~Trail(*(Trail **)(this + 0x150));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x150) = 0;
  if (*(Explosion **)(this + 0x120) != (Explosion *)0x0) {
    pvVar1 = (void *)Explosion::~Explosion(*(Explosion **)(this + 0x120));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x120) = 0;
  pvVar1 = *(void **)(this + 0x2b0);
  if (pvVar1 != (void *)0x0) {
    AbyssEngine::Quaternion::~Quaternion((Quaternion *)((int)pvVar1 + 0x58));
    AbyssEngine::Quaternion::~Quaternion((Quaternion *)((int)pvVar1 + 0x3c));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x2b0) = 0;
  KIPlayer::~KIPlayer((KIPlayer *)this);
  return;
}

// ===== PlayerFighter::~PlayerFighter  @0x000f0632  (16 bytes)
/* PlayerFighter::~PlayerFighter() */

void __thiscall PlayerFighter::~PlayerFighter(PlayerFighter *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~PlayerFighter(this);
  operator_delete(pvVar1);
  return;
}

// ===== PlayerFighter::reset  @0x000f0644  (244 bytes)
/* PlayerFighter::reset() */

void __thiscall PlayerFighter::reset(PlayerFighter *this)

{
  undefined8 local_28;
  undefined4 local_20;
  int local_18;
  
  local_18 = __stack_chk_guard;
  KIPlayer::reset((KIPlayer *)this);
  this[0x48] = (PlayerFighter)0x1;
  local_28 = *(undefined8 *)(this + 0x54);
  local_20 = *(undefined4 *)(this + 0x5c);
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x154),(Vector *)&local_28);
  local_20 = *(undefined4 *)(this + 0x15c);
  local_28 = *(undefined8 *)(this + 0x154);
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x28),(Vector *)&local_28);
  this[0x12a] = (PlayerFighter)0x0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x144) = 0;
  this[0x128] = (PlayerFighter)0x0;
  *(undefined4 *)(this + 0x1b4) = 0;
  *(undefined4 *)(this + 0x1bc) = 0;
  *(undefined4 *)(this + 0x1c0) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x1c4) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x1c8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x1cc) = 0;
  if (*(int *)(this + 0x84) != 5) {
    *(undefined4 *)(this + 0x84) = 0;
  }
  local_28 = 0;
  local_20 = 0;
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x8c),(Vector *)&local_28);
  local_28 = 0;
  local_20 = 0;
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x160),(Vector *)&local_28);
  local_28 = 0;
  local_20 = 0;
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x16c),(Vector *)&local_28);
  this[100] = (PlayerFighter)0x0;
  this[0x65] = (PlayerFighter)0x0;
  this[0xcc] = (PlayerFighter)0x0;
  this[0x66] = (PlayerFighter)0x0;
  this[0x48] = (PlayerFighter)0x1;
  *(undefined4 *)(this + 0x13c) = 0;
  this[500] = (PlayerFighter)0x0;
  this[0x138] = (PlayerFighter)0x0;
  this[0x2c8] = (PlayerFighter)0x0;
  *(undefined4 *)(this + 0x2cc) = 0;
  *(undefined4 *)(this + 0x2c0) = 0;
  *(undefined4 *)(this + 0x2c4) = 0;
  this[0x2d0] = (PlayerFighter)0x1;
  this[0x2dc] = (PlayerFighter)0x0;
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerFighter::setLevel  @0x000f0740  (214 bytes)
/* PlayerFighter::setLevel(Level*) */

void __thiscall PlayerFighter::setLevel(PlayerFighter *this,Level *param_1)

{
  undefined4 uVar1;
  int iVar2;
  ParticleSystemManager *pPVar3;
  
  KIPlayer::setLevel((KIPlayer *)this,param_1);
  pPVar3 = *(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x74);
  uVar1 = AEGeometry::getReferenceMatrix(*(AEGeometry **)(this + 8));
  iVar2 = ParticleSystemManager::addSystem(pPVar3,uVar1,9,0);
  *(int *)(this + 0x19c) = iVar2;
  ParticleSystemManager::enableSystemEmit
            (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x74),iVar2,false);
  pPVar3 = *(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x78);
  uVar1 = AEGeometry::getReferenceMatrix(*(AEGeometry **)(this + 8));
  iVar2 = ParticleSystemManager::addSystem(pPVar3,uVar1,0xf,0);
  *(int *)(this + 0x7c) = iVar2;
  ParticleSystemManager::enableSystemEmit
            (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x78),iVar2,false);
  pPVar3 = *(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x84);
  uVar1 = AEGeometry::getReferenceMatrix(*(AEGeometry **)(this + 8));
  iVar2 = ParticleSystemManager::addSystem(pPVar3,uVar1,0x2a,0);
  *(int *)(this + 0x80) = iVar2;
  ParticleSystemManager::enableSystemEmit
            (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x84),iVar2,false);
  pPVar3 = *(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x8c);
  uVar1 = AEGeometry::getReferenceMatrix(*(AEGeometry **)(this + 8));
  iVar2 = ParticleSystemManager::addSystem(pPVar3,uVar1,0x11,0);
  *(int *)(this + 0x130) = iVar2;
  ParticleSystemManager::enableSystemEmit
            (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x8c),iVar2,false);
  pPVar3 = *(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x8c);
  uVar1 = AEGeometry::getReferenceMatrix(*(AEGeometry **)(this + 8));
  iVar2 = ParticleSystemManager::addSystem(pPVar3,uVar1,0x12,0);
  *(int *)(this + 0x134) = iVar2;
  ParticleSystemManager::enableSystemEmit
            (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x8c),iVar2,false);
  return;
}

// ===== PlayerFighter::setMissionCrate  @0x000f0818  (136 bytes)
/* PlayerFighter::setMissionCrate(bool) */

void __thiscall PlayerFighter::setMissionCrate(PlayerFighter *this,bool param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  Mission *this_00;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int *piVar6;
  
  this[0xcc] = (PlayerFighter)param_1;
  if (param_1) {
    *(undefined4 *)(this + 0x4c) = 0;
    puVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    puVar1[1] = puVar2;
    puVar1[2] = 1;
    *puVar2 = 0;
    *puVar1 = 0;
    *(undefined4 **)(this + 0x4c) = puVar1;
    this_00 = (Mission *)Status::getMission(Globals::status);
    iVar3 = Mission::getType(this_00);
    piVar6 = *(int **)(this + 0x4c);
    piVar6[2] = *piVar6 + 1;
    pvVar4 = realloc((void *)piVar6[1],(*piVar6 + 1) * 4);
    piVar6[1] = (int)pvVar4;
    uVar5 = 0x75;
    if (iVar3 == 5) {
      uVar5 = 0x74;
    }
    *(undefined4 *)((int)pvVar4 + *piVar6 * 4) = uVar5;
    *piVar6 = piVar6[2];
    piVar6 = *(int **)(this + 0x4c);
    piVar6[2] = *piVar6 + 1;
    pvVar4 = realloc((void *)piVar6[1],(*piVar6 + 1) * 4);
    piVar6[1] = (int)pvVar4;
    *(undefined4 *)((int)pvVar4 + *piVar6 * 4) = 1;
    *piVar6 = piVar6[2];
  }
  return;
}

// ===== PlayerFighter::hasMissionCrateCaptured  @0x000f08b4  (6 bytes)
/* PlayerFighter::hasMissionCrateCaptured() */

PlayerFighter __thiscall PlayerFighter::hasMissionCrateCaptured(PlayerFighter *this)

{
  return this[0x65];
}

// ===== PlayerFighter::hasMissionCrateLost  @0x000f08ba  (6 bytes)
/* PlayerFighter::hasMissionCrateLost() */

PlayerFighter __thiscall PlayerFighter::hasMissionCrateLost(PlayerFighter *this)

{
  return this[100];
}

// ===== PlayerFighter::setShipGroup  @0x000f08c0  (4 bytes)
/* PlayerFighter::setShipGroup(AEGeometry*, int, bool) */

void PlayerFighter::setShipGroup(AEGeometry *param_1,int param_2,bool param_3)

{
  KIPlayer::setShipGroup(param_1,param_2,param_3);
  return;
}

// ===== PlayerFighter::hasCrateCaptured  @0x000f08c4  (14 bytes)
/* PlayerFighter::hasCrateCaptured() */

bool __thiscall PlayerFighter::hasCrateCaptured(PlayerFighter *this)

{
  return this[0x48] == (PlayerFighter)0x0;
}

// ===== PlayerFighter::hasCrateLost  @0x000f08d2  (6 bytes)
/* PlayerFighter::hasCrateLost() */

PlayerFighter __thiscall PlayerFighter::hasCrateLost(PlayerFighter *this)

{
  return this[0x66];
}

// ===== PlayerFighter::setPosition  @0x000f08d8  (26 bytes)
/* PlayerFighter::setPosition(AbyssEngine::AEMath::Vector const&) */

void __thiscall PlayerFighter::setPosition(PlayerFighter *this,Vector *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000f08f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0x48))
            (this,*(undefined4 *)param_1,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
  return;
}

// ===== PlayerFighter::setPosition  @0x000f08f4  (110 bytes)
/* PlayerFighter::setPosition(float, float, float) */

void PlayerFighter::setPosition(float param_1,float param_2,float param_3)

{
  int in_r0;
  Matrix *pMVar1;
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  int iVar2;
  Vector local_28 [12];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  *(undefined4 *)(in_r0 + 0x54) = in_r1;
  *(undefined4 *)(in_r0 + 0x58) = in_r2;
  *(undefined4 *)(in_r0 + 0x5c) = in_r3;
  AEGeometry::setPosition(param_1,param_2,param_3);
  AbyssEngine::AEMath::Vector::operator=((Vector *)(in_r0 + 0x154),local_28);
  if (*(int *)(in_r0 + 0x150) != 0) {
    Trail::reset(*(int *)(in_r0 + 0x150),*(undefined4 *)(in_r0 + 0x154),
                 *(undefined4 *)(in_r0 + 0x158),*(undefined4 *)(in_r0 + 0x15c));
  }
  iVar2 = *(int *)(in_r0 + 4);
  pMVar1 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(in_r0 + 8));
  AbyssEngine::AEMath::Matrix::operator=((Matrix *)(iVar2 + 4),pMVar1);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerFighter::setWingmanCommand  @0x000f096c  (154 bytes)
/* PlayerFighter::setWingmanCommand(int, KIPlayer*) */

void __thiscall PlayerFighter::setWingmanCommand(PlayerFighter *this,int param_1,KIPlayer *param_2)

{
  int iVar1;
  Route *pRVar2;
  undefined4 uVar3;
  
  uVar3 = *(undefined4 *)(this + 0xe0);
  KIPlayer::setWingmanCommand((KIPlayer *)this,param_1,param_2);
  if (param_1 - 2U < 2) {
    *(undefined4 *)(this + 0x1b4) = 0x1389;
    if (*(float *)(this + 0x1e0) != 5.5) {
      *(undefined4 *)(this + 0x1bc) = 0x1389;
    }
    if (param_1 == 2) {
      iVar1 = Level::getPlayerRoute(*(Level **)(this + 0x50));
      if (iVar1 != 0) {
        pRVar2 = (Route *)Level::getPlayerRoute(*(Level **)(this + 0x50));
        pRVar2 = (Route *)Route::getExactClone(pRVar2);
        *(Route **)(this + 0x148) = pRVar2;
        uVar3 = Route::getCurrent(pRVar2);
        *(undefined4 *)(this + 0x1dc) = uVar3;
        goto LAB_000f09f2;
      }
    }
    else if (param_2 != (KIPlayer *)0x0) goto LAB_000f09f2;
  }
  else {
    if (param_1 != 0) {
      if (param_1 == 1) {
        this[0x1d8] = (PlayerFighter)0x0;
        this[0x139] = (PlayerFighter)0x0;
      }
      goto LAB_000f09f2;
    }
    *(uint *)(this + 0x13c) = (uint)(*(int *)(this + 0x13c) == 0);
  }
  *(undefined4 *)(this + 0xe0) = uVar3;
LAB_000f09f2:
  *(undefined4 *)(this + 0x1e0) = *(undefined4 *)(this + 0x1a8);
  *(undefined4 *)(this + 0x1e8) = *(undefined4 *)(this + 0x1a0);
  return;
}

// ===== PlayerFighter::setSpeed  @0x000f0a06  (16 bytes)
/* PlayerFighter::setSpeed(float) */

void __thiscall PlayerFighter::setSpeed(PlayerFighter *this,float param_1)

{
  undefined4 in_r1;
  
  this[0x139] = (PlayerFighter)0x0;
  *(undefined4 *)(this + 0x1a8) = in_r1;
  *(undefined4 *)(this + 0x1e0) = in_r1;
  return;
}

// ===== PlayerFighter::setRotate  @0x000f0a16  (24 bytes)
/* PlayerFighter::setRotate(int) */

void __thiscall PlayerFighter::setRotate(PlayerFighter *this,int param_1)

{
  uint in_fpscr;
  undefined4 uVar1;
  
  uVar1 = VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  this[0x139] = (PlayerFighter)0x0;
  *(undefined4 *)(this + 0x1a0) = uVar1;
  *(undefined4 *)(this + 0x1e8) = uVar1;
  return;
}

// ===== PlayerFighter::setShootError  @0x000f0a2e  (14 bytes)
/* PlayerFighter::setShootError(int) */

void __thiscall PlayerFighter::setShootError(PlayerFighter *this,int param_1)

{
  uint in_fpscr;
  undefined4 uVar1;
  
  uVar1 = VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  *(undefined4 *)(this + 0x1a4) = uVar1;
  return;
}

// ===== PlayerFighter::setBoostProb  @0x000f0a3c  (6 bytes)
/* PlayerFighter::setBoostProb(int) */

void __thiscall PlayerFighter::setBoostProb(PlayerFighter *this,int param_1)

{
  *(int *)(this + 0x1b0) = param_1;
  return;
}

// ===== PlayerFighter::removeTrail  @0x000f0a42  (28 bytes)
/* PlayerFighter::removeTrail() */

void __thiscall PlayerFighter::removeTrail(PlayerFighter *this)

{
  void *pvVar1;
  
  if (*(Trail **)(this + 0x150) != (Trail *)0x0) {
    pvVar1 = (void *)Trail::~Trail(*(Trail **)(this + 0x150));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x150) = 0;
  return;
}

// ===== PlayerFighter::setExhaustVisible  @0x000f0a60  (60 bytes)
/* PlayerFighter::setExhaustVisible(bool) */

void __thiscall PlayerFighter::setExhaustVisible(PlayerFighter *this,bool param_1)

{
  Transform *this_00;
  uint uVar1;
  
  if (*(int *)(this + 8) != 0) {
    if (*(int *)(this + 0xc) == 0) {
      uVar1 = *(uint *)(*(int *)(this + 8) + 0x14);
    }
    else {
      uVar1 = *(uint *)(*(int *)(this + 0xc) + 0x14);
    }
    if (uVar1 != 0xffffffff) {
      this_00 = (Transform *)AbyssEngine::PaintCanvas::TransformGetTransform(Globals::Canvas,uVar1);
      AbyssEngine::Transform::SetVisible(this_00,param_1);
      return;
    }
  }
  return;
}

// ===== PlayerFighter::cloak  @0x000f0aa4  (58 bytes)
/* PlayerFighter::cloak(int, bool) */

void __thiscall PlayerFighter::cloak(PlayerFighter *this,int param_1,bool param_2)

{
  int iVar1;
  
  if (param_1 < 1) {
    iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,5000);
    param_1 = iVar1 + 5000;
  }
  *(int *)(this + 0x2c4) = param_1 + 4000;
  this[0x2c8] = (PlayerFighter)0x1;
  this[0x2d1] = (PlayerFighter)param_2;
  return;
}

// ===== PlayerFighter::setCloakingPossible  @0x000f0ae4  (30 bytes)
/* PlayerFighter::setCloakingPossible(bool) */

void __thiscall PlayerFighter::setCloakingPossible(PlayerFighter *this,bool param_1)

{
  this[0x2d0] = (PlayerFighter)param_1;
  if ((!param_1) && (this[0x138] != (PlayerFighter)0x0)) {
    *(int *)(this + 0x2c0) = *(int *)(this + 0x2c4) + 1;
    handleCloaking(this);
    return;
  }
  return;
}

// ===== PlayerFighter::handleCloaking  @0x000f0b00  (600 bytes)
/* PlayerFighter::handleCloaking() */

void __thiscall PlayerFighter::handleCloaking(PlayerFighter *this)

{
  int iVar1;
  Mesh *pMVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  PaintCanvas *this_00;
  bool bVar6;
  uint in_fpscr;
  float fVar7;
  float fVar8;
  
  if ((((*(int *)(this + 0x24) == 10) && (*(int *)(this + 8) != 0)) &&
      (iVar1 = KIPlayer::isDead((KIPlayer *)this), iVar1 == 0)) &&
     ((*(char *)(*(int *)(this + 4) + 0x68) == '\0' && (this[0x2d0] != (PlayerFighter)0x0)))) {
    if (this[0x2c8] != (PlayerFighter)0x0) {
      iVar1 = *(int *)(this + 0x2c0);
      if (iVar1 == 0) {
        this[0x138] = (PlayerFighter)0x1;
        uVar3 = *(uint *)(this + 0x2d4);
        if (uVar3 == 0xffffffff) {
          AbyssEngine::PaintCanvas::MeshCloneMaterial
                    (Globals::Canvas,*(uint *)(*(int *)(this + 0xc) + 0x1c),(uint *)(this + 0x2d4));
          iVar1 = AbyssEngine::PaintCanvas::MeshGetPointer
                            (Globals::Canvas,*(uint *)(*(int *)(this + 0xc) + 0x1c));
          *(undefined4 *)(this + 0x2d8) = *(undefined4 *)(*(int *)(iVar1 + 0x30) + 0x20);
          uVar3 = *(uint *)(this + 0x2d4);
        }
        iVar1 = AbyssEngine::PaintCanvas::MaterialGetMaterial(Globals::Canvas,uVar3);
        *(undefined4 *)(iVar1 + 0x20) = 0xe;
        AbyssEngine::PaintCanvas::MeshChangeMaterial
                  (Globals::Canvas,*(uint *)(*(int *)(this + 0xc) + 0x1c),*(ushort *)(this + 0x2d4))
        ;
        if (this[0x2d1] == (PlayerFighter)0x0) {
          iVar1 = *(int *)(this + 0x2c0);
        }
        else {
          iVar1 = 2000;
          *(undefined4 *)(this + 0x2c0) = 2000;
          this[0x2d1] = (PlayerFighter)0x0;
        }
      }
      uVar4 = *(uint *)(this + 0x1c8);
      uVar3 = iVar1 + uVar4;
      *(uint *)(this + 0x2c0) = uVar3;
      iVar1 = (((int)uVar3 >> 0x1f) - *(int *)(this + 0x1cc)) - (uint)(uVar3 < uVar4);
      bVar6 = 2000 < uVar3 - uVar4;
      if ((int)(-(uint)bVar6 - iVar1) < 0 == (SBORROW4(0,iVar1) != SBORROW4(-iVar1,(uint)bVar6))) {
        if (1999 < (int)uVar3) {
          setExhaustVisible(this,false);
          this[0x70] = (PlayerFighter)0x1;
        }
        this_00 = Globals::Canvas;
        pMVar2 = (Mesh *)AbyssEngine::PaintCanvas::MeshGetPointer
                                   (Globals::Canvas,*(uint *)(*(int *)(this + 0xc) + 0x1c));
        fVar7 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x2c0),
                                           (byte)(in_fpscr >> 0x16) & 3);
        fVar7 = fVar7 / 2000.0;
      }
      else {
        if (*(int *)(this + 0x2c4) < (int)uVar3) {
          this[0x2c8] = (PlayerFighter)0x0;
          *(undefined4 *)(this + 0x2c0) = 0;
          this[0x138] = (PlayerFighter)0x0;
          uVar5 = *(undefined4 *)(this + 0x2d8);
          iVar1 = AbyssEngine::PaintCanvas::MaterialGetMaterial
                            (Globals::Canvas,*(uint *)(this + 0x2d4));
          *(undefined4 *)(iVar1 + 0x20) = uVar5;
          setExhaustVisible(this,true);
          return;
        }
        if ((int)uVar3 <= *(int *)(this + 0x2c4) + -2000) {
          return;
        }
        this[0x70] = (PlayerFighter)0x0;
        this_00 = Globals::Canvas;
        pMVar2 = (Mesh *)AbyssEngine::PaintCanvas::MeshGetPointer
                                   (Globals::Canvas,*(uint *)(*(int *)(this + 0xc) + 0x1c));
        fVar7 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x2c0),
                                           (byte)(in_fpscr >> 0x16) & 3);
        fVar8 = (float)VectorSignedToFloat(*(int *)(this + 0x2c4) + -2000,
                                           (byte)(in_fpscr >> 0x16) & 3);
        fVar7 = (fVar7 - fVar8) / -2000.0 + 1.0;
      }
      AbyssEngine::PaintCanvas::MeshChangeShaderAnimValue(this_00,pMVar2,fVar7,(uint)fVar7);
      return;
    }
    if ((this[0x1d8] == (PlayerFighter)0x0) ||
       (iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,100), 0x31 < iVar1)) {
      iVar1 = *(int *)(this + 0x2cc);
      *(int *)(this + 0x2cc) = *(int *)(this + 0x1c8) + iVar1;
      if (8000 < *(int *)(this + 0x1c8) + iVar1) {
        *(undefined4 *)(this + 0x2cc) = 0;
        iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
        if (iVar1 < 0x1e) {
          iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,5000);
          *(int *)(this + 0x2c4) = iVar1 + 9000;
          this[0x2c8] = (PlayerFighter)0x1;
          this[0x2d1] = (PlayerFighter)0x0;
        }
      }
    }
    else {
      iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,5000);
      *(int *)(this + 0x2c4) = iVar1 + 9000;
      this[0x2c8] = (PlayerFighter)0x1;
      this[0x2d1] = (PlayerFighter)0x0;
    }
  }
  return;
}

// ===== PlayerFighter::setAIDisabled  @0x000f0d80  (6 bytes)
/* PlayerFighter::setAIDisabled(bool) */

void __thiscall PlayerFighter::setAIDisabled(PlayerFighter *this,bool param_1)

{
  this[0x2dc] = (PlayerFighter)param_1;
  return;
}

// ===== PlayerFighter::update  @0x000f0d90  (10204 bytes)
/* PlayerFighter::update(int) */

void __thiscall PlayerFighter::update(PlayerFighter *this,int param_1)

{
  Status *pSVar1;
  undefined1 uVar2;
  Player PVar3;
  char cVar4;
  PlayerFighter PVar5;
  int iVar6;
  Player *pPVar7;
  Standing *pSVar8;
  PlayerFighter *pPVar9;
  undefined4 uVar10;
  Matrix *pMVar11;
  void *pvVar12;
  Route *pRVar13;
  KIPlayer *pKVar14;
  SpacePoint *this_00;
  SpacePoint *this_01;
  PlayerEgo *pPVar15;
  TargetFollowCamera *pTVar16;
  AEGeometry *pAVar17;
  uint *puVar18;
  int *piVar19;
  int iVar20;
  Mission *pMVar21;
  Station *this_02;
  String *pSVar22;
  undefined4 *puVar23;
  PlayerFixedObject *this_03;
  Ship *this_04;
  EaseInOutMatrix *pEVar24;
  float *pfVar25;
  Vector *pVVar26;
  uint uVar27;
  Explosion *this_05;
  int iVar28;
  Vector *pVVar29;
  Vector *pVVar30;
  byte bVar31;
  byte bVar32;
  bool bVar33;
  bool bVar34;
  uint in_fpscr;
  uint uVar35;
  uint uVar36;
  float fVar37;
  float fVar38;
  float extraout_s0;
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
  float extraout_s2;
  float extraout_s2_00;
  float extraout_s2_01;
  float fVar39;
  float fVar40;
  undefined4 uVar41;
  undefined8 local_150;
  float local_148;
  float local_10c;
  float local_100;
  Vector aVStack_f8 [12];
  AEMath aAStack_ec [12];
  undefined8 local_e0;
  undefined4 local_d8;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  float local_80;
  int local_78;
  int local_74;
  float local_70;
  float local_6c;
  int local_68;
  int local_64;
  float local_60;
  float fStack_5c;
  int local_58;
  int iStack_54;
  undefined8 local_50;
  undefined8 local_48;
  int local_40;
  int local_3c;
  
  local_3c = __stack_chk_guard;
  if (((*(int *)(this + 0x84) == 4) &&
      (iVar6 = Explosion::isPlaying(*(Explosion **)(this + 0x120)), iVar6 == 0)) &&
     ((this[0x48] == (PlayerFighter)0x0 || (60000 < *(int *)(this + 0xd4))))) {
    iVar6 = __stack_chk_guard - local_3c;
    if (iVar6 == 0) {
      KIPlayer::setActive(SUB41(this,0));
      return;
    }
    goto LAB_000f2056;
  }
  *(int *)(this + 0x1bc) = *(int *)(this + 0x1bc) + param_1;
  *(int *)(this + 0x1b4) = *(int *)(this + 0x1b4) + param_1;
  if (*(int *)(this + 0x24) == 1) {
    *(undefined4 *)(this + 0x24) = 1;
  }
  *(int *)(this + 0x1c8) = param_1;
  *(int *)(this + 0x1cc) = param_1 >> 0x1f;
  AEGeometry::getPosition();
  pVVar30 = (Vector *)(this + 0x28);
  AbyssEngine::AEMath::Vector::operator=(pVVar30,(Vector *)&local_78);
  if (this[0x3f] == (PlayerFighter)0x0) {
    if ((*(uint *)(this + 0x24) & 0xfffffffe) == 8) {
      uVar2 = 1;
    }
    else {
      iVar6 = KIPlayer::isWingMan((KIPlayer *)this);
      if (iVar6 == 0) {
        pSVar8 = (Standing *)Status::getStanding(Globals::status);
        uVar2 = Standing::isEnemy(pSVar8,*(int *)(this + 0x24));
      }
      else {
        uVar2 = 0;
      }
    }
    *(undefined1 *)(*(int *)(this + 4) + 0x5c) = uVar2;
    if ((*(uint *)(this + 0x24) & 0xfffffffe) == 8) {
      PVar3 = (Player)0x0;
    }
    else {
      iVar6 = KIPlayer::isWingMan((KIPlayer *)this);
      if (iVar6 == 0) {
        pSVar8 = (Standing *)Status::getStanding(Globals::status);
        PVar3 = (Player)Standing::isFriend(pSVar8,*(int *)(this + 0x24));
      }
      else {
        PVar3 = (Player)0x1;
      }
    }
    pPVar7 = *(Player **)(this + 4);
    pPVar7[0x5d] = PVar3;
    if (this[0x3f] != (PlayerFighter)0x0) goto LAB_000f0ebc;
  }
  else {
    pPVar7 = *(Player **)(this + 4);
LAB_000f0ebc:
    iVar28 = *(int *)(pPVar7 + 0x6c);
    iVar6 = Player::getMaxHitpoints(pPVar7);
    if (iVar6 / 0x14 < iVar28) {
      *(undefined1 *)(*(int *)(this + 4) + 0x5c) = 1;
    }
  }
  if (this[0x3e] != (PlayerFighter)0x0) {
    iVar6 = *(int *)(this + 0x2e0);
    *(int *)(this + 0x2e0) = iVar6 + param_1;
    if (20000 < iVar6 + param_1) {
      *(undefined4 *)(this + 0x2e0) = 0;
      iVar6 = Player::gunAvailable(*(Player **)(this + 4),1);
      if (iVar6 == 1) {
        *(uint *)(this + 0x13c) = (uint)(*(int *)(this + 0x13c) == 0);
      }
    }
    iVar6 = Player::isAlwaysEnemy(*(Player **)(this + 4));
    if ((iVar6 == 0) && (iVar6 = Level::getPlayer(*(Level **)(this + 0x50)), iVar6 != 0)) {
      iVar6 = Level::getPlayer(*(Level **)(this + 0x50));
      pPVar9 = *(PlayerFighter **)(*(int *)(iVar6 + 0x14) + 4);
      bVar33 = pPVar9 == this;
      if (bVar33) {
        pPVar9 = (PlayerFighter *)(uint)(byte)this[0x3f];
      }
      if (bVar33 && pPVar9 == (PlayerFighter *)0x0) {
        Player::setAlwaysEnemy(*(Player **)(this + 4),true);
        Level::uncoverWanted(*(Level **)(this + 0x50),*(int *)(this + 0x44));
      }
    }
  }
  iVar6 = Status::inBlackMarketSystem(Globals::status);
  if (((iVar6 == 1) && (Globals::status[0x110] != (Status)0x0)) && (*(int *)(this + 0x24) == 8)) {
    iVar6 = *(int *)(this + 4);
    *(undefined1 *)(iVar6 + 0x5c) = 0;
    *(undefined1 *)(iVar6 + 0x5d) = 0;
  }
  iVar6 = Player::turnedEnemy(*(Player **)(this + 4));
  pPVar7 = *(Player **)(this + 4);
  if (iVar6 == 1) {
    *(undefined2 *)(pPVar7 + 0x5c) = 1;
  }
  iVar6 = Player::isAlwaysFriend(pPVar7);
  if (iVar6 == 1) {
    iVar6 = *(int *)(this + 4);
    *(undefined1 *)(iVar6 + 0x5d) = 1;
    *(undefined1 *)(iVar6 + 0x5c) = 0;
  }
  if ((this[0xd8] == (PlayerFighter)0x0) && (*(int *)(this + 0x68) == 0)) {
    uVar10 = Route::clone(*(Route **)(this + 0x140));
    *(undefined4 *)(this + 0x68) = uVar10;
  }
  iVar6 = *(int *)(this + 0x1c4);
  *(int *)(this + 0x1c4) = iVar6 + param_1;
  if (200 < iVar6 + param_1) {
    if (*(Vector **)(this + 0x150) != (Vector *)0x0) {
      Trail::update(*(Vector **)(this + 0x150),pVVar30);
      AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x154),pVVar30);
    }
    *(undefined4 *)(this + 0x1c4) = 0;
  }
  iVar6 = *(int *)(this + 4);
  pMVar11 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
  AbyssEngine::AEMath::Matrix::operator=((Matrix *)(iVar6 + 4),pMVar11);
  if (*(AEGeometry **)(this + 0xc) != (AEGeometry *)0x0) {
    iVar6 = *(int *)(this + 4);
    pMVar11 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 0xc));
    AbyssEngine::AEMath::Matrix::operator*=((Matrix *)(iVar6 + 4),pMVar11);
  }
  if (this[0xd8] != (PlayerFighter)0x0) {
    iVar6 = *(int *)(this + 0x84);
    bVar33 = iVar6 != 4;
    if (bVar33) {
      iVar6 = *(int *)(this + 0x68);
    }
    if (bVar33 && iVar6 != 0) {
      Level::getPlayer(*(Level **)(this + 0x50));
      AEGeometry::getPosition();
      pVVar29 = (Vector *)(this + 0x8c);
      AbyssEngine::AEMath::Vector::operator=(pVVar29,(Vector *)&local_78);
      if (*(int *)(this + 0xe0) == 1) {
        iVar6 = *(int *)(this + 0xdc);
        if (iVar6 == 0) {
          Level::getPlayer(*(Level **)(this + 0x50));
          AEGeometry::getRightVector();
          pVVar26 = (Vector *)(this + 0x98);
          fVar37 = (float)AbyssEngine::AEMath::Vector::operator=(pVVar26,(Vector *)&local_78);
          AbyssEngine::AEMath::Vector::operator*=(pVVar26,fVar37);
          AbyssEngine::AEMath::Vector::operator-=(pVVar29,pVVar26);
LAB_000f112c:
          Level::getPlayer(*(Level **)(this + 0x50));
          AEGeometry::getDirection();
          fVar37 = (float)AbyssEngine::AEMath::VectorNormalize
                                    ((AEMath *)&local_d0,(Vector *)&local_150);
LAB_000f1154:
          AbyssEngine::AEMath::operator*((AEMath *)&local_78,(Vector *)&local_d0,fVar37);
          AbyssEngine::AEMath::Vector::operator-=(pVVar29,(Vector *)&local_78);
        }
        else {
          if (iVar6 == 1) {
            Level::getPlayer(*(Level **)(this + 0x50));
            AEGeometry::getRightVector();
            pVVar26 = (Vector *)(this + 0x98);
            fVar37 = (float)AbyssEngine::AEMath::Vector::operator=(pVVar26,(Vector *)&local_78);
            AbyssEngine::AEMath::Vector::operator*=(pVVar26,fVar37);
            AbyssEngine::AEMath::Vector::operator+=(pVVar29,pVVar26);
            goto LAB_000f112c;
          }
          if (iVar6 == 2) {
            Level::getPlayer(*(Level **)(this + 0x50));
            AEGeometry::getUpVector();
            pVVar26 = (Vector *)(this + 0x98);
            fVar37 = (float)AbyssEngine::AEMath::Vector::operator=(pVVar26,(Vector *)&local_78);
            AbyssEngine::AEMath::Vector::operator*=(pVVar26,fVar37);
            AbyssEngine::AEMath::Vector::operator+=(pVVar29,pVVar26);
            Level::getPlayer(*(Level **)(this + 0x50));
            AEGeometry::getDirection();
            fVar37 = (float)AbyssEngine::AEMath::VectorNormalize
                                      ((AEMath *)&local_d0,(Vector *)&local_150);
            goto LAB_000f1154;
          }
        }
        iVar6 = Route::length(*(Route **)(this + 0x68));
        if (iVar6 < 2) {
          Route::setNewCoords(*(undefined4 *)(this + 0x68),*(undefined4 *)(this + 0x8c),
                              *(undefined4 *)(this + 0x90),*(undefined4 *)(this + 0x94));
          pRVar13 = *(Route **)(this + 0x68);
        }
        else {
          local_78 = (int)*(float *)(this + 0x8c);
          local_74 = (int)*(float *)(this + 0x90);
          local_70 = (float)(int)*(float *)(this + 0x94);
          if (*(Route **)(this + 0x68) != (Route *)0x0) {
            pvVar12 = (void *)Route::~Route(*(Route **)(this + 0x68));
            operator_delete(pvVar12);
            *(undefined4 *)(this + 0x68) = 0;
          }
          pRVar13 = operator_new(0x18);
          Route::Route(pRVar13,&local_78,3);
          *(Route **)(this + 0x68) = pRVar13;
        }
        Route::setLoop(pRVar13,true);
      }
    }
  }
  if (*(int *)(this + 0x84) - 3U < 2) {
    Player::StopEngineSound(*(Player **)(this + 4));
  }
  else {
    Player::update(*(Player **)(this + 4),param_1,
                   *(int *)(this + 0x84) != 5 && *(int *)(this + 0xf4) != -1);
    puVar18 = (uint *)Player::getEnemies(*(Player **)(this + 4));
    if (this[0x2dc] == (PlayerFighter)0x0) {
      if (puVar18 == (uint *)0x0) {
        pVVar29 = *(Vector **)(this + 0x68);
        if (pVVar29 == (Vector *)0x0) {
          *(undefined4 *)(this + 0x84) = 5;
        }
        else {
          AEGeometry::getPosition();
          Route::update(pVVar29);
          iVar6 = Route::getWaypoint(*(Route **)(this + 0x68));
          if (iVar6 != 0) {
LAB_000f1866:
            iVar6 = Route::getWaypoint(*(Route **)(this + 0x68));
            uVar10 = VectorSignedToFloat(*(undefined4 *)(iVar6 + 0x120),(byte)(in_fpscr >> 0x16) & 3
                                        );
            *(undefined4 *)(this + 0x160) = uVar10;
            iVar6 = Route::getWaypoint(*(Route **)(this + 0x68));
            uVar10 = VectorSignedToFloat(*(undefined4 *)(iVar6 + 0x124),(byte)(in_fpscr >> 0x16) & 3
                                        );
            *(undefined4 *)(this + 0x164) = uVar10;
            iVar6 = Route::getWaypoint(*(Route **)(this + 0x68));
            uVar10 = VectorSignedToFloat(*(undefined4 *)(iVar6 + 0x128),(byte)(in_fpscr >> 0x16) & 3
                                        );
            *(undefined4 *)(this + 0x168) = uVar10;
LAB_000f189c:
            this[0x128] = (PlayerFighter)0x1;
          }
        }
      }
      else {
        uVar27 = *(uint *)(this + 0x34);
        if (*puVar18 <= uVar27) {
          uVar27 = 0xffffffff;
          *(undefined4 *)(this + 0x34) = 0xffffffff;
        }
        if (this[0x12a] == (PlayerFighter)0x0) {
          *(undefined4 *)(this + 0x34) = 0xffffffff;
        }
        else if ((-1 < (int)uVar27) &&
                (iVar6 = Player::isActive(*(Player **)(puVar18[1] + uVar27 * 4)), iVar6 == 0)) {
          this[0x12a] = (PlayerFighter)0x0;
        }
        *(undefined4 *)(this + 0x144) = 0;
        if (*(int *)(this + 0x1b4) < 0x1389) {
          if ((this[0x12a] == (PlayerFighter)0x0) && (*puVar18 != 0)) {
            uVar27 = 0;
            do {
              pPVar7 = *(Player **)(puVar18[1] + uVar27 * 4);
              if (((pPVar7 != (Player *)0x0) && (iVar6 = Player::isActive(pPVar7), iVar6 == 1)) &&
                 (iVar6 = Player::isDead(*(Player **)(puVar18[1] + uVar27 * 4)), iVar6 == 0)) {
                Player::getPosition();
                AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x8c),(Vector *)&local_78);
                if ((*(int *)(this + 0x24) != 8) &&
                   (iVar6 = Player::turnedEnemy(*(Player **)(this + 4)), iVar6 != 0)) {
LAB_000f364a:
                  *(uint *)(this + 0x34) = uVar27;
                  this[0x12a] = (PlayerFighter)0x1;
                  break;
                }
                fVar39 = *(float *)(this + 0x28) - *(float *)(this + 0x8c);
                fVar37 = (float)VectorSignedToFloat(*(int *)(this + 0x124),
                                                    (byte)(in_fpscr >> 0x16) & 3);
                uVar35 = in_fpscr & 0xfffffff;
                in_fpscr = uVar35;
                if (fVar39 < fVar37) {
                  fVar40 = (float)VectorSignedToFloat(-*(int *)(this + 0x124),
                                                      (byte)(uVar35 >> 0x16) & 3);
                  uVar36 = uVar35 | (uint)(fVar39 < fVar40) << 0x1f |
                           (uint)(fVar39 == fVar40) << 0x1e;
                  in_fpscr = uVar36 | (uint)(NAN(fVar39) || NAN(fVar40)) << 0x1c;
                  bVar32 = (byte)(uVar36 >> 0x18);
                  if (((!(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1))
                      && (fVar39 = *(float *)(this + 0x2c) - *(float *)(this + 0x90),
                         in_fpscr = uVar35, fVar39 < fVar37)) &&
                     ((uVar36 = uVar35 | (uint)(fVar39 < fVar40) << 0x1f |
                                (uint)(fVar39 == fVar40) << 0x1e,
                      in_fpscr = uVar36 | (uint)(NAN(fVar39) || NAN(fVar40)) << 0x1c,
                      bVar32 = (byte)(uVar36 >> 0x18),
                      !(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1) &&
                      ((fVar39 = *(float *)(this + 0x30) - *(float *)(this + 0x94),
                       in_fpscr = uVar35, fVar39 < fVar37 &&
                       (uVar35 = uVar35 | (uint)(fVar39 < fVar40) << 0x1f |
                                 (uint)(fVar39 == fVar40) << 0x1e,
                       in_fpscr = uVar35 | (uint)(NAN(fVar39) || NAN(fVar40)) << 0x1c,
                       bVar32 = (byte)(uVar35 >> 0x18),
                       !(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)))))
                     )) goto LAB_000f364a;
                }
              }
              uVar27 = uVar27 + 1;
            } while (uVar27 < *puVar18);
          }
        }
        else {
          PVar5 = (PlayerFighter)0x0;
          if (this[0x129] == (PlayerFighter)0x0) {
            iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
            PVar5 = (PlayerFighter)0x0;
            if (iVar6 < 0x14) {
              PVar5 = (PlayerFighter)0x1;
            }
          }
          this[0x129] = PVar5;
          *(undefined4 *)(this + 0x1b4) = 0;
          iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
          if ((iVar6 < 0x1e) && (1 < *puVar18)) {
            iVar6 = 0;
            this[0x12a] = (PlayerFighter)0x0;
            bVar33 = true;
            do {
              if (!bVar33) goto LAB_000f13c0;
              iVar28 = AbyssEngine::AERandom::nextInt(Globals::rnd,*puVar18);
              *(int *)(this + 0x34) = iVar28;
              iVar28 = Player::isActive(*(Player **)(puVar18[1] + iVar28 * 4));
              if (iVar28 == 1) {
                Player::getPosition();
                AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x8c),(Vector *)&local_78);
                if ((*(int *)(this + 0x24) != 8) &&
                   (iVar28 = Player::turnedEnemy(*(Player **)(this + 4)), iVar28 != 0)) {
LAB_000f342e:
                  this[0x12a] = (PlayerFighter)0x1;
                  goto LAB_000f13c0;
                }
                fVar39 = *(float *)(this + 0x28) - *(float *)(this + 0x8c);
                fVar37 = (float)VectorSignedToFloat(*(int *)(this + 0x124),
                                                    (byte)(in_fpscr >> 0x16) & 3);
                uVar27 = in_fpscr & 0xfffffff;
                in_fpscr = uVar27;
                if (fVar39 < fVar37) {
                  fVar40 = (float)VectorSignedToFloat(-*(int *)(this + 0x124),
                                                      (byte)(uVar27 >> 0x16) & 3);
                  uVar35 = uVar27 | (uint)(fVar39 < fVar40) << 0x1f |
                           (uint)(fVar39 == fVar40) << 0x1e;
                  in_fpscr = uVar35 | (uint)(NAN(fVar39) || NAN(fVar40)) << 0x1c;
                  bVar32 = (byte)(uVar35 >> 0x18);
                  if ((((!(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1))
                       && (fVar39 = *(float *)(this + 0x2c) - *(float *)(this + 0x90),
                          in_fpscr = uVar27, fVar39 < fVar37)) &&
                      (uVar35 = uVar27 | (uint)(fVar39 < fVar40) << 0x1f |
                                (uint)(fVar39 == fVar40) << 0x1e,
                      in_fpscr = uVar35 | (uint)(NAN(fVar39) || NAN(fVar40)) << 0x1c,
                      bVar32 = (byte)(uVar35 >> 0x18),
                      !(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1))) &&
                     ((fVar39 = *(float *)(this + 0x30) - *(float *)(this + 0x94), in_fpscr = uVar27
                      , fVar39 < fVar37 &&
                      (uVar27 = uVar27 | (uint)(fVar39 < fVar40) << 0x1f |
                                (uint)(fVar39 == fVar40) << 0x1e,
                      in_fpscr = uVar27 | (uint)(NAN(fVar39) || NAN(fVar40)) << 0x1c,
                      bVar32 = (byte)(uVar27 >> 0x18),
                      !(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)))))
                  goto LAB_000f342e;
                }
              }
              iVar6 = iVar6 + 1;
              bVar33 = this[0x12a] == (PlayerFighter)0x0;
            } while (iVar6 < 5);
            if (this[0x12a] == (PlayerFighter)0x0) goto LAB_000f13bc;
          }
          else {
LAB_000f13bc:
            *(undefined4 *)(this + 0x34) = 0;
          }
LAB_000f13c0:
          if (((this[0xd8] != (PlayerFighter)0x0) && (*(int *)(this + 0xe0) == 3)) &&
             (*(KIPlayer **)(this + 0xe4) != (KIPlayer *)0x0)) {
            iVar6 = KIPlayer::isDead(*(KIPlayer **)(this + 0xe4));
            if (iVar6 == 0) {
              if (*puVar18 != 0) {
                uVar27 = 0;
                do {
                  pPVar7 = *(Player **)(puVar18[1] + uVar27 * 4);
                  if (((pPVar7 == *(Player **)(*(int *)(this + 0xe4) + 4)) &&
                      (iVar6 = Player::isActive(pPVar7), iVar6 == 1)) &&
                     (iVar6 = Player::isAlwaysFriend(*(Player **)(puVar18[1] + uVar27 * 4)),
                     iVar6 == 0)) {
                    *(uint *)(this + 0x34) = uVar27;
                    break;
                  }
                  uVar27 = uVar27 + 1;
                } while (uVar27 < *puVar18);
              }
            }
            else {
              (**(code **)(*(int *)this + 0x10))(this,1,0);
            }
          }
          iVar6 = Player::isActive(*(Player **)(puVar18[1] + *(int *)(this + 0x34) * 4));
          if ((iVar6 == 1) &&
             (iVar6 = Player::isDead(*(Player **)(puVar18[1] + *(int *)(this + 0x34) * 4)),
             iVar6 == 0)) {
            Player::getPosition();
            AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x8c),(Vector *)&local_78);
            fVar39 = *(float *)(this + 0x28) - *(float *)(this + 0x8c);
            fVar37 = (float)VectorSignedToFloat(*(int *)(this + 0x124),(byte)(in_fpscr >> 0x16) & 3)
            ;
            uVar27 = in_fpscr & 0xfffffff;
            in_fpscr = uVar27;
            if (fVar39 < fVar37) {
              fVar40 = (float)VectorSignedToFloat(-*(int *)(this + 0x124),(byte)(uVar27 >> 0x16) & 3
                                                 );
              uVar35 = uVar27 | (uint)(fVar39 < fVar40) << 0x1f | (uint)(fVar39 == fVar40) << 0x1e;
              in_fpscr = uVar35 | (uint)(NAN(fVar39) || NAN(fVar40)) << 0x1c;
              bVar32 = (byte)(uVar35 >> 0x18);
              if (((!(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) &&
                  (fVar39 = *(float *)(this + 0x2c) - *(float *)(this + 0x90), in_fpscr = uVar27,
                  fVar39 < fVar37)) &&
                 ((uVar35 = uVar27 | (uint)(fVar39 < fVar40) << 0x1f |
                            (uint)(fVar39 == fVar40) << 0x1e,
                  in_fpscr = uVar35 | (uint)(NAN(fVar39) || NAN(fVar40)) << 0x1c,
                  bVar32 = (byte)(uVar35 >> 0x18),
                  !(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1) &&
                  ((fVar39 = *(float *)(this + 0x30) - *(float *)(this + 0x94), in_fpscr = uVar27,
                   fVar39 < fVar37 &&
                   (uVar27 = uVar27 | (uint)(fVar39 < fVar40) << 0x1f |
                             (uint)(fVar39 == fVar40) << 0x1e,
                   in_fpscr = uVar27 | (uint)(NAN(fVar39) || NAN(fVar40)) << 0x1c,
                   bVar32 = (byte)(uVar27 >> 0x18),
                   !(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)))))))
              goto LAB_000f15d8;
            }
            *(undefined4 *)(this + 0x34) = 0xffffffff;
          }
          else {
            *(undefined4 *)(this + 0x34) = 0xffffffff;
            this[0x12a] = (PlayerFighter)0x0;
          }
        }
LAB_000f15d8:
        if ((*(char *)(*(int *)(this + 4) + 0x5c) == '\0') && (*(int *)(this + 0x34) == 0)) {
          *(undefined4 *)(this + 0x34) = 1;
          this[0x12a] = (PlayerFighter)0x0;
        }
        PVar5 = this[0xd8];
        if ((PVar5 == (PlayerFighter)0x0) || (*(int *)(this + 0xe0) != 3)) {
          if ((0 < *(int *)(this + 0x34)) &&
             (*(undefined4 *)(this + 0x34) = 0xffffffff, 1 < *puVar18)) {
            uVar27 = 1;
            do {
              iVar6 = Player::isActive(*(Player **)(puVar18[1] + uVar27 * 4));
              if ((iVar6 == 1) &&
                 (iVar6 = Player::isDead(*(Player **)(puVar18[1] + uVar27 * 4)), iVar6 == 0)) {
                iVar6 = Player::getKIPlayer(*(Player **)(puVar18[1] + uVar27 * 4));
                pPVar7 = *(Player **)(puVar18[1] + uVar27 * 4);
                PVar3 = pPVar7[0x69];
                if (iVar6 == 0) {
                  if (PVar3 == (Player)0x0) goto LAB_000f16c4;
LAB_000f1652:
                  iVar6 = 0;
                }
                else {
                  if (PVar3 != (Player)0x0) goto LAB_000f1652;
                  iVar6 = Player::getKIPlayer(pPVar7);
                  iVar6 = *(int *)(iVar6 + 0x24);
                }
                PVar5 = this[0xd8];
                if (PVar5 == (PlayerFighter)0x0) {
                  iVar28 = *(int *)(this + 0x24);
                  if ((((((iVar6 == 8) && (iVar28 != 8)) || ((iVar6 != 8 && (iVar28 == 8)))) ||
                       ((iVar6 == 9 && (iVar28 != 9)))) || ((iVar6 != 9 && (iVar28 == 9)))) ||
                     (((((iVar6 == 0 && (iVar28 == 1)) || (iVar6 == 1 && iVar28 == 0)) ||
                       (((iVar6 == 3 && iVar28 == 2 || (iVar6 == 2 && iVar28 == 3)) ||
                        ((iVar6 == 10 && (iVar28 != 10)))))) || ((iVar6 != 10 && (iVar28 == 10))))))
                  goto LAB_000f16d4;
                }
                else {
                  iVar6 = *(int *)(puVar18[1] + uVar27 * 4);
                  if ((*(char *)(iVar6 + 0x5c) != '\0') ||
                     ((*(int *)(this + 0xe4) != 0 && (iVar6 == *(int *)(*(int *)(this + 0xe4) + 4)))
                     )) {
LAB_000f16d4:
                    *(uint *)(this + 0x34) = uVar27;
                    this[0x12a] = (PlayerFighter)0x1;
                    goto LAB_000f16dc;
                  }
                }
              }
LAB_000f16c4:
              uVar27 = uVar27 + 1;
            } while (uVar27 < *puVar18);
            PVar5 = this[0xd8];
          }
LAB_000f16dc:
          if (PVar5 != (PlayerFighter)0x0) goto LAB_000f16de;
        }
        else {
LAB_000f16de:
          if ((this[0x12a] == (PlayerFighter)0x0) && (*(int *)(this + 0xe0) == 1)) {
            *(undefined4 *)(this + 0x34) = 0xffffffff;
          }
        }
        this[0x128] = (PlayerFighter)0x0;
        if ((*(int *)(this + 0x34) == -1) &&
           (pRVar13 = *(Route **)(this + 0x68), pRVar13 != (Route *)0x0)) {
LAB_000f171a:
          iVar6 = Route::getWaypoint(pRVar13);
          if ((iVar6 == 0) || (iVar6 = Player::isActive(*(Player **)(this + 4)), iVar6 != 1)) {
            *(undefined4 *)(this + 0x34) = 0;
            iVar6 = Player::getEnemy(*(Player **)(this + 4),0);
            *(int *)(this + 0x144) = iVar6;
            if (iVar6 != 0) goto LAB_000f18b4;
          }
          else {
            pVVar29 = *(Vector **)(this + 0x68);
            AEGeometry::getPosition();
            Route::update(pVVar29);
            iVar6 = Route::getWaypoint(*(Route **)(this + 0x68));
            if (iVar6 != 0) {
              iVar6 = Route::getDockingTarget(*(Route **)(this + 0x68));
              if (iVar6 == 0) goto LAB_000f1866;
              if (*(int *)(this + 0x84) != 7) {
                if (*(int *)(this + 0x84) != 1) goto LAB_000f189c;
                *(undefined4 *)(this + 0x84) = 7;
              }
              pKVar14 = (KIPlayer *)Route::getDockingTarget(*(Route **)(this + 0x68));
              (**(code **)(*(int *)this + 0x28))((Vector *)&local_78,this);
              this_00 = (SpacePoint *)
                        KIPlayer::getNearestNavigationPoint
                                  (pKVar14,(Vector *)&local_78,*(SpacePoint **)(this + 700));
              if (this_00 != (SpacePoint *)0x0) {
                this_01 = *(SpacePoint **)(this + 700);
                if (this_01 != this_00) {
                  if (this_01 != (SpacePoint *)0x0) {
                    SpacePoint::giveFree(this_01);
                  }
                  *(SpacePoint **)(this + 700) = this_00;
                  SpacePoint::take(this_00);
                }
                piVar19 = (int *)Route::getDockingTarget(*(Route **)(this + 0x68));
                (**(code **)(*piVar19 + 0x28))((Vector *)&local_d0);
                iVar6 = Route::getDockingTarget(*(Route **)(this + 0x68));
                pMVar11 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(iVar6 + 8));
                AbyssEngine::AEMath::MatrixRotateVector
                          ((AEMath *)&local_150,pMVar11,(Vector *)this_00);
                AbyssEngine::AEMath::operator+
                          ((AEMath *)&local_78,(Vector *)&local_d0,(Vector *)&local_150);
                pVVar29 = (Vector *)(this + 0x98);
                AbyssEngine::AEMath::Vector::operator=(pVVar29,(Vector *)&local_78);
                (**(code **)(*(int *)this + 0x28))((Vector *)&local_d0,this);
                AbyssEngine::AEMath::operator-((AEMath *)&local_78,pVVar29,(Vector *)&local_d0);
                fVar37 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_78);
                if ((int)fVar37 < 2000) {
                  *(undefined4 *)(this + 0x84) = 8;
                  pvVar12 = *(void **)(this + 0x2b0);
                  if (pvVar12 != (void *)0x0) {
                    AbyssEngine::Quaternion::~Quaternion((Quaternion *)((int)pvVar12 + 0x58));
                    AbyssEngine::Quaternion::~Quaternion((Quaternion *)((int)pvVar12 + 0x3c));
                    operator_delete(pvVar12);
                  }
                  *(undefined4 *)(this + 0x2b0) = 0;
                  pKVar14 = (KIPlayer *)Route::getDockingTarget(*(Route **)(this + 0x68));
                  piVar19 = (int *)Route::getDockingTarget(*(Route **)(this + 0x68));
                  (**(code **)(*piVar19 + 0x28))((Vector *)&local_d0);
                  iVar6 = Route::getDockingTarget(*(Route **)(this + 0x68));
                  pMVar11 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(iVar6 + 8));
                  AbyssEngine::AEMath::MatrixRotateVector
                            ((AEMath *)&local_150,pMVar11,*(Vector **)(this + 700));
                  AbyssEngine::AEMath::operator+
                            ((AEMath *)&local_78,(Vector *)&local_d0,(Vector *)&local_150);
                  pVVar29 = (Vector *)KIPlayer::getNearestDockingPoint(pKVar14,(Vector *)&local_78);
                  iVar6 = Route::getDockingTarget(*(Route **)(this + 0x68));
                  pMVar11 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(iVar6 + 8));
                  AbyssEngine::AEMath::MatrixRotateVector((AEMath *)&local_78,pMVar11,pVVar29 + 0xc)
                  ;
                  AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_150,(Vector *)&local_78);
                  iVar6 = Route::getDockingTarget(*(Route **)(this + 0x68));
                  pMVar11 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(iVar6 + 8));
                  AbyssEngine::AEMath::MatrixRotateVector
                            ((AEMath *)&local_d0,pMVar11,(Vector *)this_00);
                  iVar6 = Route::getDockingTarget(*(Route **)(this + 0x68));
                  pMVar11 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(iVar6 + 8));
                  AbyssEngine::AEMath::MatrixRotateVector((AEMath *)&local_94,pMVar11,pVVar29);
                  AbyssEngine::AEMath::operator-
                            ((AEMath *)&local_78,(Vector *)&local_d0,(Vector *)&local_94);
                  AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_88,(Vector *)&local_78);
                  AbyssEngine::AEMath::VectorCross
                            ((AEMath *)&local_78,(Vector *)&local_88,(Vector *)&local_150);
                  AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_94,(Vector *)&local_78);
                  fStack_5c = *(float *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
                  local_58 = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
                  iStack_54 = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
                  puVar23 = (undefined4 *)((uint)&local_78 | 4);
                  local_78 = 0x3f800000;
                  *puVar23 = 0;
                  puVar23[1] = fStack_5c;
                  puVar23[2] = local_58;
                  puVar23[3] = iStack_54;
                  local_64 = 0x3f800000;
                  local_60 = 0.0;
                  local_50 = 0x3f800000;
                  local_48 = 0x3f8000003f800000;
                  local_40 = 0x3f800000;
                  AbyssEngine::AEMath::MatrixSetRotation
                            ((AEMath *)&local_d0,(AEMath *)&local_78,(Vector *)&local_94,
                             (Vector *)&local_88,(Vector *)&local_150);
                  pEVar24 = operator_new(0xf4);
                  iVar6 = *(int *)(this + 4);
                  AbyssEngine::EaseInOutMatrix::EaseInOutMatrix
                            (pEVar24,*(undefined4 *)(iVar6 + 4),*(undefined4 *)(iVar6 + 8),
                             *(undefined4 *)(iVar6 + 0xc));
                  *(EaseInOutMatrix **)(this + 0x2b0) = pEVar24;
                }
                else {
                  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x160),pVVar29);
                }
              }
              goto LAB_000f189c;
            }
          }
        }
        else {
          iVar6 = Player::doesNeverAttack(*(Player **)(this + 4));
          if (iVar6 == 1) {
            pRVar13 = *(Route **)(this + 0x68);
            goto LAB_000f171a;
          }
          uVar27 = *(uint *)(this + 0x34);
          if (((int)uVar27 < 0) ||
             (puVar18 = (uint *)Player::getEnemies(*(Player **)(this + 4)), *puVar18 <= uVar27)) {
            iVar6 = 0;
            *(undefined4 *)(this + 0x34) = 0;
          }
          else {
            iVar6 = *(int *)(this + 0x34);
          }
          uVar10 = Player::getEnemy(*(Player **)(this + 4),iVar6);
          *(undefined4 *)(this + 0x144) = uVar10;
LAB_000f18b4:
          Player::getPosition();
          AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x8c),(Vector *)&local_78);
          *(undefined4 *)(this + 0x160) = *(undefined4 *)(this + 0x8c);
          *(undefined4 *)(this + 0x164) = *(undefined4 *)(this + 0x90);
          *(undefined4 *)(this + 0x168) = *(undefined4 *)(this + 0x94);
        }
      }
      if ((this[0xe8] == (PlayerFighter)0x0) || (this[0x128] == (PlayerFighter)0x0)) {
        *(undefined4 *)(this + 0xec) = 0;
      }
      else {
        iVar6 = *(int *)(this + 0xec);
        *(int *)(this + 0xec) = iVar6 + param_1;
        if (19999 < iVar6 + param_1) {
          *(undefined4 *)(this + 0xec) = 0;
          *(undefined4 *)(this + 0x84) = 6;
          this[0x128] = (PlayerFighter)0x0;
        }
      }
    }
    if ((this[0xd8] != (PlayerFighter)0x0) && (*(int *)(this + 0xe0) == 2)) {
      pVVar29 = *(Vector **)(this + 0x148);
      if (pVVar29 != (Vector *)0x0) {
        AEGeometry::getPosition();
        Route::update(pVVar29);
        iVar6 = Route::getCurrent(*(Route **)(this + 0x148));
        pRVar13 = *(Route **)(this + 0x148);
        if (iVar6 <= *(int *)(this + 0x1dc)) {
          iVar6 = Route::getWaypoint(pRVar13);
          if (iVar6 != 0) {
            iVar6 = Route::getWaypoint(*(Route **)(this + 0x148));
            uVar10 = VectorSignedToFloat(*(undefined4 *)(iVar6 + 0x120),(byte)(in_fpscr >> 0x16) & 3
                                        );
            *(undefined4 *)(this + 0x160) = uVar10;
            iVar6 = Route::getWaypoint(*(Route **)(this + 0x148));
            uVar10 = VectorSignedToFloat(*(undefined4 *)(iVar6 + 0x124),(byte)(in_fpscr >> 0x16) & 3
                                        );
            *(undefined4 *)(this + 0x164) = uVar10;
            iVar6 = Route::getWaypoint(*(Route **)(this + 0x148));
            uVar10 = VectorSignedToFloat(*(undefined4 *)(iVar6 + 0x128),(byte)(in_fpscr >> 0x16) & 3
                                        );
            *(undefined4 *)(this + 0x168) = uVar10;
            this[0x128] = (PlayerFighter)0x1;
          }
          goto LAB_000f19b8;
        }
        if (pRVar13 != (Route *)0x0) {
          pvVar12 = (void *)Route::~Route(pRVar13);
          operator_delete(pvVar12);
        }
        *(undefined4 *)(this + 0x148) = 0;
      }
      (**(code **)(*(int *)this + 0x10))(this,1,0);
    }
  }
LAB_000f19b8:
  *(float *)(this + 0x16c) = *(float *)(this + 0x160) - *(float *)(this + 0x28);
  *(float *)(this + 0x170) = *(float *)(this + 0x164) - *(float *)(this + 0x2c);
  *(float *)(this + 0x174) = *(float *)(this + 0x168) - *(float *)(this + 0x30);
  if ((*(char *)(*(int *)(this + 4) + 0x5c) != '\0') &&
     (((*(int *)(this + 0x84) == 5 ||
       ((this[0xd8] != (PlayerFighter)0x0 && (*(int *)(this + 0xe0) == 1)))) &&
      (0 < *(int *)(this + 0x124))))) {
    pPVar15 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x50));
    iVar6 = PlayerEgo::isInRocketControl(pPVar15);
    if (iVar6 == 1) {
      pPVar15 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x50));
      pTVar16 = (TargetFollowCamera *)PlayerEgo::getTargetFollowCamera(pPVar15);
      TargetFollowCamera::getTarget(pTVar16);
      AEGeometry::getPosition();
    }
    else {
      Level::getPlayer(*(Level **)(this + 0x50));
      Player::getPosition();
    }
    AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x8c),(Vector *)&local_78);
    fVar40 = *(float *)(this + 0x8c) - *(float *)(this + 0x28);
    *(float *)(this + 0x16c) = fVar40;
    fVar37 = *(float *)(this + 0x90) - *(float *)(this + 0x2c);
    *(float *)(this + 0x170) = fVar37;
    fVar39 = *(float *)(this + 0x94) - *(float *)(this + 0x30);
    in_fpscr = in_fpscr & 0xfffffff;
    *(float *)(this + 0x174) = fVar39;
    if (fVar40 < 25000.0) {
      uVar27 = in_fpscr | (uint)(fVar40 < -25000.0) << 0x1f | (uint)(fVar40 == -25000.0) << 0x1e;
      uVar35 = uVar27 | (uint)NAN(fVar40) << 0x1c;
      bVar32 = (byte)(uVar27 >> 0x18);
      bVar31 = bVar32 >> 7;
      bVar33 = (bool)(bVar32 >> 6 & 1);
      bVar32 = (byte)(uVar35 >> 0x1c) & 1;
      if (!bVar33 && bVar31 == bVar32) {
        uVar35 = in_fpscr | (uint)(fVar39 < -25000.0) << 0x1f | (uint)(fVar39 == -25000.0) << 0x1e |
                 (uint)NAN(fVar39) << 0x1c;
        bVar32 = (byte)(uVar35 >> 0x18);
        bVar31 = bVar32 >> 7;
        bVar33 = (bool)(bVar32 >> 6 & 1);
        bVar32 = bVar32 >> 4 & 1;
      }
      in_fpscr = uVar35;
      if (!bVar33 && bVar31 == bVar32) {
        in_fpscr = in_fpscr & 0xfffffff;
        bVar32 = 0;
        if (fVar39 < 25000.0) {
          in_fpscr = in_fpscr | (uint)(fVar37 < 25000.0) << 0x1f;
          bVar32 = (byte)(in_fpscr >> 0x1f);
        }
        if ((bVar32 != 0) &&
           (uVar27 = in_fpscr & 0xfffffff | (uint)(fVar37 < -25000.0) << 0x1f |
                     (uint)(fVar37 == -25000.0) << 0x1e,
           in_fpscr = uVar27 | (uint)NAN(fVar37) << 0x1c, bVar32 = (byte)(uVar27 >> 0x18),
           !(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1))) {
          *(undefined4 *)(this + 0x84) = 1;
          pAVar17 = *(AEGeometry **)(this + 0xc);
          if (pAVar17 == (AEGeometry *)0x0) {
            pAVar17 = *(AEGeometry **)(this + 8);
          }
          AEGeometry::setVisible(pAVar17,true);
          Player::setActive(*(Player **)(this + 4),true);
        }
      }
    }
  }
  puVar18 = *(uint **)(this + 0x14c);
  if ((puVar18 != (uint *)0x0) && (*puVar18 != 0)) {
    uVar27 = 0;
    do {
      piVar19 = *(int **)(puVar18[1] + uVar27 * 4);
      (**(code **)(*piVar19 + 4))
                (piVar19,*(undefined4 *)(this + 0x28),*(undefined4 *)(this + 0x2c),
                 *(undefined4 *)(this + 0x30));
      puVar18 = *(uint **)(this + 0x14c);
      uVar27 = uVar27 + 1;
    } while (uVar27 < *puVar18);
  }
  iVar6 = Player::getHitpoints(*(Player **)(this + 4));
  fVar37 = (float)VectorSignedToFloat(iVar6,(byte)(in_fpscr >> 0x16) & 3);
  if (this[500] == (PlayerFighter)0x0) {
    uVar10 = Player::getMaxHitpoints(*(Player **)(this + 4));
    fVar40 = 0.33;
    fVar38 = (float)VectorSignedToFloat(uVar10,(byte)(in_fpscr >> 0x16) & 3);
    in_fpscr = in_fpscr & 0xfffffff;
    fVar39 = extraout_s1;
    if (fVar38 * 0.33 <= fVar37) {
      if (this[500] != (PlayerFighter)0x0) goto LAB_000f1b7e;
    }
    else {
      uVar27 = in_fpscr | (uint)((float)Globals::options._40_4_ < 0.0) << 0x1f |
               (uint)((float)Globals::options._40_4_ == 0.0) << 0x1e;
      in_fpscr = uVar27 | (uint)NAN((float)Globals::options._40_4_) << 0x1c;
      bVar32 = (byte)(uVar27 >> 0x18);
      if (!(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
        iVar28 = KIPlayer::isDocked((KIPlayer *)this);
        if (iVar28 == 0) {
          ParticleSystemManager::enableSystemEmit
                    (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x78),*(int *)(this + 0x7c)
                     ,true);
          iVar20 = *(int *)(this + 0x50);
        }
        else {
          ParticleSystemManager::enableSystemEmit
                    (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x78),*(int *)(this + 0x7c)
                     ,false);
          iVar20 = *(int *)(this + 0x50);
        }
        ParticleSystemManager::enableSystemEmit
                  (*(ParticleSystemManager **)(iVar20 + 0x84),*(int *)(this + 0x80),iVar28 == 0);
        fVar39 = extraout_s1_02;
        fVar40 = extraout_s2_00;
      }
      this[500] = (PlayerFighter)0x1;
    }
  }
  else {
LAB_000f1b7e:
    uVar10 = Player::getMaxHitpoints(*(Player **)(this + 4));
    fVar40 = 0.33;
    fVar39 = (float)VectorSignedToFloat(uVar10,(byte)(in_fpscr >> 0x16) & 3);
    uVar27 = in_fpscr & 0xfffffff | (uint)(fVar37 < fVar39 * 0.33) << 0x1f;
    in_fpscr = uVar27 | (uint)(NAN(fVar37) || NAN(fVar39 * 0.33)) << 0x1c;
    fVar39 = extraout_s1_00;
    if ((byte)(uVar27 >> 0x1f) == ((byte)(in_fpscr >> 0x1c) & 1)) {
      this[500] = (PlayerFighter)0x0;
      ParticleSystemManager::enableSystemEmit
                (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x78),*(int *)(this + 0x7c),
                 false);
      ParticleSystemManager::enableSystemEmit
                (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x84),*(int *)(this + 0x80),
                 false);
      fVar39 = extraout_s1_01;
      fVar40 = extraout_s2;
    }
  }
  if ((iVar6 < 1) && (1 < *(int *)(this + 0x84) - 3U)) {
    pMVar21 = (Mission *)Status::getFreelanceMission(Globals::status);
    if ((pMVar21 != (Mission *)0x0) && (iVar28 = Mission::getType(pMVar21), iVar28 == 0xd)) {
      this_02 = (Station *)Status::getStation(Globals::status);
      iVar28 = Station::getIndex(this_02);
      iVar20 = Mission::getTargetStation(pMVar21);
      if ((iVar28 == iVar20) && (Globals::status[0xf1] == (Status)0x0)) {
        if (*(int *)(this + 0x1c) != 0) {
          pSVar22 = (String *)GameText::getText(Globals::gameText,0x67f);
          cVar4 = AbyssEngine::String::Compare((String *)(this + 0x18),pSVar22);
          if (cVar4 == '\0') {
            Globals::status[0xf0] = (Status)0x1;
            goto LAB_000f1cee;
          }
        }
        *(undefined2 *)(Globals::status + 0xf0) = 0x100;
      }
    }
LAB_000f1cee:
    if (this[0x3e] != (PlayerFighter)0x0) {
      Wanted::setTerminated
                (*(Wanted **)(*(int *)(*(int *)Globals::status + 4) + *(int *)(this + 0x44) * 4),
                 true);
      Wanted::setActive(*(Wanted **)
                         (*(int *)(*(int *)Globals::status + 4) + *(int *)(this + 0x44) * 4),false);
      iVar28 = Globals::layout;
      bVar33 = (bool)Wanted::getReward(*(Wanted **)
                                        (*(int *)(*(int *)Globals::status + 4) +
                                        *(int *)(this + 0x44) * 4));
      Layout::showMissionRewardMessage(iVar28,bVar33);
      pSVar1 = Globals::status;
      iVar28 = Status::getCredits(Globals::status);
      iVar20 = Wanted::getReward(*(Wanted **)
                                  (*(int *)(*(int *)Globals::status + 4) + *(int *)(this + 0x44) * 4
                                  ));
      Status::setCredits(pSVar1,iVar20 + iVar28);
      pSVar1 = Globals::status;
      iVar28 = Wanted::getBoard(*(Wanted **)
                                 (*(int *)(*(int *)Globals::status + 4) + *(int *)(this + 0x44) * 4)
                               );
      Status::incCollectedBounties(pSVar1,iVar28);
    }
    if (*(char *)(*(int *)(this + 4) + 0x5c) == '\0') {
      Level::friendDied(*(Level **)(this + 0x50));
      if (this[0xd8] != (PlayerFighter)0x0) {
        Level::wingmanDied(*(Level **)(this + 0x50),this + 0x18);
      }
    }
    else {
      if (*(int *)(this + 0x24) == 9) {
        piVar19 = operator_new(0xc);
        puVar23 = operator_new__(4);
        piVar19[1] = (int)puVar23;
        *puVar23 = 0;
        *piVar19 = 0;
        *(int **)(this + 0x4c) = piVar19;
        piVar19[2] = 1;
        pvVar12 = realloc(puVar23,4);
        piVar19[1] = (int)pvVar12;
        *(undefined4 *)((int)pvVar12 + *piVar19 * 4) = 0x83;
        *piVar19 = piVar19[2];
        iVar28 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
        piVar19 = *(int **)(this + 0x4c);
        piVar19[2] = *piVar19 + 1;
        pvVar12 = realloc((void *)piVar19[1],(*piVar19 + 1) * 4);
        piVar19[1] = (int)pvVar12;
        *(int *)((int)pvVar12 + *piVar19 * 4) = iVar28 + 1;
        *piVar19 = piVar19[2];
      }
      else if (*(int *)(this + 0x24) == 8) {
        if (*(char *)(*(int *)(this + 4) + 0x44) == '\0') {
          Status::incPirateKills(Globals::status);
        }
      }
      else if (((this[0xcc] == (PlayerFighter)0x0) && (this[0x48] != (PlayerFighter)0x0)) &&
              (Globals::options[0x35] != '\0')) {
        uVar27 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
        bVar34 = SBORROW4(uVar27,-1);
        iVar28 = uVar27 + 1;
        bVar33 = uVar27 == 0xffffffff;
        if (0x7fffffff < uVar27) {
          iVar20 = *(int *)(this + 0x24);
          bVar34 = SBORROW4(iVar20,3);
          iVar28 = iVar20 + -3;
          bVar33 = iVar20 == 3;
        }
        if (bVar33 || iVar28 < 0 != bVar34) {
          pvVar12 = *(void **)(this + 0x4c);
          if (pvVar12 != (void *)0x0) {
            if (*(void **)((int)pvVar12 + 4) != (void *)0x0) {
              operator_delete__(*(void **)((int)pvVar12 + 4));
            }
            operator_delete(pvVar12);
          }
          *(undefined4 *)(this + 0x4c) = 0;
          piVar19 = operator_new(0xc);
          puVar23 = operator_new__(4);
          piVar19[1] = (int)puVar23;
          *puVar23 = 0;
          *piVar19 = 0;
          *(int **)(this + 0x4c) = piVar19;
          iVar28 = *(int *)(this + 0x24);
          piVar19[2] = 1;
          pvVar12 = realloc(puVar23,4);
          piVar19[1] = (int)pvVar12;
          *(int *)((int)pvVar12 + *piVar19 * 4) = iVar28 + 0xbd;
          *piVar19 = piVar19[2];
          piVar19 = *(int **)(this + 0x4c);
          piVar19[2] = *piVar19 + 1;
          pvVar12 = realloc((void *)piVar19[1],(*piVar19 + 1) * 4);
          piVar19[1] = (int)pvVar12;
          *(undefined4 *)((int)pvVar12 + *piVar19 * 4) = 1;
          *piVar19 = piVar19[2];
        }
      }
      Level::enemyDied(*(Level **)(this + 0x50),*(int *)(this + 0xa8),
                       *(bool *)(*(int *)(this + 4) + 0x44));
    }
    pPVar9 = this + 0x50;
    this[0x6f] = (PlayerFighter)0x0;
    *(undefined4 *)(this + 0x84) = 3;
    iVar28 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x5dc);
    *(int *)(this + 0x1f0) = iVar28 + 0x5dc;
    AEGeometry::getDirection();
    fVar37 = (float)AbyssEngine::AEMath::Vector::operator=
                              ((Vector *)(this + 400),(Vector *)&local_78);
    local_78 = 0;
    local_74 = 0;
    local_70 = 0.0;
    fVar37 = (float)ParticleSystemManager::emitManual
                              (*(ParticleSystemManager **)(*(int *)pPVar9 + 0x74),
                               *(int *)(*(int *)pPVar9 + 0x3c),pVVar30,0,(Vector *)&local_78,fVar37)
    ;
    pVVar29 = pVVar30;
    if (Globals::options[0xf] == '\0') {
      pVVar29 = (Vector *)0x0;
    }
    FModSound::play(Globals::sound,0x14,pVVar29,(Vector *)0x0,fVar37);
    iVar28 = AbyssEngine::AERandom::nextInt(Globals::rnd,200);
    uVar10 = VectorSignedToFloat(iVar28 + -100,(byte)(in_fpscr >> 0x16) & 3);
    iVar28 = AbyssEngine::AERandom::nextInt(Globals::rnd,200);
    uVar41 = VectorSignedToFloat(iVar28 + -100,(byte)(in_fpscr >> 0x16) & 3);
    iVar28 = AbyssEngine::AERandom::nextInt(Globals::rnd,200);
    local_c8 = VectorSignedToFloat(iVar28 + -100,(byte)(in_fpscr >> 0x16) & 3);
    local_d0 = uVar10;
    local_cc = uVar41;
    AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_78,(Vector *)&local_d0);
    fVar37 = (float)AbyssEngine::AEMath::Vector::operator=
                              ((Vector *)(this + 0x184),(Vector *)&local_78);
    AbyssEngine::AEMath::Vector::operator*=((Vector *)(this + 0x184),fVar37);
    ParticleSystemManager::enableSystemEmit
              (*(ParticleSystemManager **)(*(int *)pPVar9 + 0x74),*(int *)(this + 0x19c),true);
    ParticleSystemManager::enableSystemEmit
              (*(ParticleSystemManager **)(*(int *)pPVar9 + 0x8c),*(int *)(this + 300),false);
    ParticleSystemManager::enableSystemEmit
              (*(ParticleSystemManager **)(*(int *)pPVar9 + 0x8c),*(int *)(this + 0x130),false);
    ParticleSystemManager::enableSystemEmit
              (*(ParticleSystemManager **)(*(int *)pPVar9 + 0x8c),*(int *)(this + 0x134),false);
    PVar5 = (PlayerFighter)KIPlayer::cargoAvailable((KIPlayer *)this);
    this[0x48] = PVar5;
    setExhaustVisible(this,false);
    fVar39 = extraout_s1_03;
    fVar40 = extraout_s2_01;
  }
  if (this[0x2dc] == (PlayerFighter)0x0) {
    switch(*(undefined4 *)(this + 0x84)) {
    case 0:
      *(undefined4 *)(this + 0x84) = 1;
      break;
    case 1:
    case 7:
      pVVar29 = (Vector *)(this + 0x16c);
      handleCloaking(this);
      if (this[0x139] != (PlayerFighter)0x0) {
        if (iVar6 < *(int *)(this + 0x1d0)) {
          iVar28 = (*(int *)(this + 0x1d0) - iVar6) + *(int *)(this + 0x1d4);
          *(int *)(this + 0x1d0) = iVar6;
          *(int *)(this + 0x1d4) = iVar28;
          fVar39 = (float)VectorSignedToFloat(iVar28,(byte)(in_fpscr >> 0x16) & 3);
          uVar10 = Player::getMaxHitpoints(*(Player **)(this + 4));
          fVar37 = (float)VectorSignedToFloat(uVar10,(byte)(in_fpscr >> 0x16) & 3);
          fVar37 = (fVar39 / fVar37) * 100.0;
          uVar27 = in_fpscr & 0xfffffff | (uint)(fVar37 < 40.0) << 0x1f |
                   (uint)(fVar37 == 40.0) << 0x1e;
          in_fpscr = uVar27 | (uint)NAN(fVar37) << 0x1c;
          bVar32 = (byte)(uVar27 >> 0x18);
          if (!(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
            *(undefined4 *)(this + 0x1d4) = 0;
            *(undefined4 *)(this + 0x1bc) = 10000;
            this[0x1d8] = (PlayerFighter)0x1;
          }
        }
        if (((5000 < *(int *)(this + 0x1bc)) && (this[0x1ec] == (PlayerFighter)0x0)) &&
           ((*(undefined4 *)(this + 0x1bc) = 0, this[0x1d8] != (PlayerFighter)0x0 ||
            (iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,100),
            iVar6 < *(int *)(this + 0x1b0))))) {
          iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,3000);
          *(int *)(this + 0x1c0) = iVar6 + 5000;
          this[0x1ec] = (PlayerFighter)0x1;
          *(undefined4 *)(this + 0x1e4) = 0x40b00000;
          *(undefined4 *)(this + 0x1e8) = 0x3fa66666;
        }
        if (this[0x1ec] != (PlayerFighter)0x0) {
          if (*(int *)(this + 0x1c0) < *(int *)(this + 0x1bc)) {
            *(undefined4 *)(this + 0x1bc) = 0;
            this[0x1d8] = (PlayerFighter)0x0;
            fVar37 = *(float *)(this + 0x1a8);
            *(float *)(this + 0x1e4) = fVar37;
            *(undefined4 *)(this + 0x1e8) = *(undefined4 *)(this + 0x1a0);
          }
          else {
            fVar37 = *(float *)(this + 0x1e4);
          }
          uVar27 = in_fpscr & 0xfffffff;
          uVar35 = uVar27 | (uint)(fVar37 < 0.0) << 0x1f | (uint)(fVar37 == 0.0) << 0x1e;
          in_fpscr = uVar35 | (uint)NAN(fVar37) << 0x1c;
          bVar32 = (byte)(uVar35 >> 0x18);
          if (!(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
            pfVar25 = (float *)&DAT_000f36a0;
            if (*(float *)(this + 0x1e0) < fVar37) {
              pfVar25 = (float *)&DAT_000f36a4;
            }
            fVar39 = *(float *)(this + 0x1e0) * *pfVar25;
            *(float *)(this + 0x1e0) = fVar39;
            uVar35 = uVar27 | (uint)(fVar39 < 5.5) << 0x1f;
            uVar36 = uVar35 | (uint)NAN(fVar39) << 0x1c;
            if (((byte)(uVar35 >> 0x1f) == ((byte)(uVar36 >> 0x1c) & 1)) ||
               (in_fpscr = uVar27, uVar36 = uVar27, fVar39 < *(float *)(this + 0x1a8))) {
              in_fpscr = uVar36 & 0xfffffff | (uint)(fVar37 == *(float *)(this + 0x1a8)) << 0x1e;
              *(float *)(this + 0x1e0) = fVar37;
              if ((byte)(in_fpscr >> 0x1e) != 0) {
                this[0x1ec] = (PlayerFighter)0x0;
              }
              *(undefined4 *)(this + 0x1e4) = 0;
            }
          }
        }
      }
      if ((*(int *)(this + 0x144) != 0) && (this[0x128] == (PlayerFighter)0x0)) {
        if (*(char *)(*(int *)(this + 0x144) + 0x69) == '\0') {
          iVar6 = 8000;
        }
        else {
          iVar28 = Level::getPlayer(*(Level **)(this + 0x50));
          iVar6 = 8000;
          if (iVar28 != 0) {
            pPVar15 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x50));
            iVar28 = PlayerEgo::isDockedToDockingPoint(pPVar15);
            if (iVar28 != 0) {
              iVar6 = 12000;
            }
          }
        }
        fVar37 = (float)VectorSignedToFloat(iVar6,(byte)(in_fpscr >> 0x16) & 3);
        fVar39 = *(float *)pVVar29;
        uVar27 = in_fpscr & 0xfffffff;
        in_fpscr = uVar27;
        if (fVar39 < fVar37) {
          fVar40 = (float)VectorSignedToFloat(-iVar6,(byte)(uVar27 >> 0x16) & 3);
          uVar35 = uVar27 | (uint)(fVar39 < fVar40) << 0x1f | (uint)(fVar39 == fVar40) << 0x1e;
          in_fpscr = uVar35 | (uint)(NAN(fVar39) || NAN(fVar40)) << 0x1c;
          bVar32 = (byte)(uVar35 >> 0x18);
          if ((((!(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) &&
               (fVar39 = *(float *)(this + 0x170), in_fpscr = uVar27, fVar39 < fVar37)) &&
              (uVar35 = uVar27 | (uint)(fVar39 < fVar40) << 0x1f | (uint)(fVar39 == fVar40) << 0x1e,
              in_fpscr = uVar35 | (uint)(NAN(fVar39) || NAN(fVar40)) << 0x1c,
              bVar32 = (byte)(uVar35 >> 0x18),
              !(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1))) &&
             ((fVar39 = *(float *)(this + 0x174), in_fpscr = uVar27, fVar39 < fVar37 &&
              (uVar27 = uVar27 | (uint)(fVar39 < fVar40) << 0x1f | (uint)(fVar39 == fVar40) << 0x1e,
              in_fpscr = uVar27 | (uint)(NAN(fVar39) || NAN(fVar40)) << 0x1c,
              bVar32 = (byte)(uVar27 >> 0x18),
              !(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1))))) {
            AEGeometry::getRightVector();
            AbyssEngine::AEMath::Vector::operator=(pVVar29,(Vector *)&local_78);
          }
        }
      }
      AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_88,pVVar29);
      AbyssEngine::AEMath::MatrixGetInverse((AEMath *)&local_78,(Matrix *)(*(int *)(this + 4) + 4));
      AbyssEngine::AEMath::MatrixRotateVector
                ((AEMath *)&local_d0,(AEMath *)&local_78,(Vector *)&local_88);
      AbyssEngine::AEMath::Vector::operator=(pVVar29,(Vector *)&local_d0);
      *(float *)(this + 0x170) = -*(float *)(this + 0x170);
      this[0x20] = *(PlayerFighter *)(*(Player **)(this + 4) + 0x68);
      if (((this[0x12a] != (PlayerFighter)0x0) && (this[0x128] == (PlayerFighter)0x0)) &&
         ((*(int *)(this + 0x144) != 0 &&
          (iVar6 = Player::doesNeverAttack(*(Player **)(this + 4)), iVar6 == 0)))) {
        if ((*(Player **)(this + 0x144))[0x5e] == (Player)0x0) {
          fVar39 = *(float *)(this + 0x16c);
          fVar37 = *(float *)(this + 0x1a4);
          uVar27 = in_fpscr & 0xfffffff;
          in_fpscr = uVar27;
          if (fVar39 < fVar37) {
            fVar40 = -fVar37;
            uVar35 = uVar27 | (uint)(fVar39 < fVar40) << 0x1f | (uint)(fVar39 == fVar40) << 0x1e;
            in_fpscr = uVar35 | (uint)(NAN(fVar39) || NAN(fVar40)) << 0x1c;
            bVar32 = (byte)(uVar35 >> 0x18);
            if ((((!(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) &&
                 (fVar39 = *(float *)(this + 0x170), in_fpscr = uVar27, fVar39 < fVar37)) &&
                (uVar35 = uVar27 | (uint)(fVar39 < fVar40) << 0x1f |
                          (uint)(fVar39 == fVar40) << 0x1e,
                in_fpscr = uVar35 | (uint)(NAN(fVar39) || NAN(fVar40)) << 0x1c,
                bVar32 = (byte)(uVar35 >> 0x18),
                !(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1))) &&
               (((fVar37 = *(float *)(this + 0x160) - *(float *)(this + 0x28), in_fpscr = uVar27,
                 fVar37 < 35000.0 &&
                 (uVar35 = uVar27 | (uint)(fVar37 < -35000.0) << 0x1f |
                           (uint)(fVar37 == -35000.0) << 0x1e,
                 in_fpscr = uVar35 | (uint)NAN(fVar37) << 0x1c, bVar32 = (byte)(uVar35 >> 0x18),
                 !(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1))) &&
                (((fVar37 = *(float *)(this + 0x164) - *(float *)(this + 0x2c), in_fpscr = uVar27,
                  fVar37 < 35000.0 &&
                  ((uVar35 = uVar27 | (uint)(fVar37 < -35000.0) << 0x1f |
                             (uint)(fVar37 == -35000.0) << 0x1e,
                   in_fpscr = uVar35 | (uint)NAN(fVar37) << 0x1c, bVar32 = (byte)(uVar35 >> 0x18),
                   !(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1) &&
                   (fVar37 = *(float *)(this + 0x168) - *(float *)(this + 0x30), in_fpscr = uVar27,
                   fVar37 < 35000.0)))) &&
                 (uVar27 = uVar27 | (uint)(fVar37 < -35000.0) << 0x1f |
                           (uint)(fVar37 == -35000.0) << 0x1e,
                 in_fpscr = uVar27 | (uint)NAN(fVar37) << 0x1c, bVar32 = (byte)(uVar27 >> 0x18),
                 !(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1))))))) {
              if (((this[0x21] == (PlayerFighter)0x0) ||
                  (iVar6 = Player::isActive(*(Player **)(this + 0x144)), iVar6 != 1)) ||
                 (iVar6 = Player::isDead(*(Player **)(this + 0x144)), iVar6 != 0)) {
LAB_000f2d06:
                this[0x12a] = (PlayerFighter)0x0;
              }
              else {
                if ((*(char *)(*(int *)(this + 0x144) + 0x69) != '\0') &&
                   (iVar6 = Level::getPlayer(*(Level **)(this + 0x50)), iVar6 != 0)) {
                  pPVar15 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x50));
                  iVar6 = PlayerEgo::isDockedToDockingPoint(pPVar15);
                  if (iVar6 == 1) {
                    Player::getPosition();
                    Player::getPosition();
                    uVar27 = in_fpscr & 0xfffffff | (uint)(local_100 < local_10c) << 0x1f |
                             (uint)(local_100 == local_10c) << 0x1e;
                    in_fpscr = uVar27 | (uint)(NAN(local_100) || NAN(local_10c)) << 0x1c;
                    bVar32 = (byte)(uVar27 >> 0x18);
                    if (!(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1))
                    goto LAB_000f2d06;
                  }
                }
                Player::shoot(*(int *)(this + 4),(longlong)param_1,false);
                this[0x2ad] = (PlayerFighter)0x1;
              }
            }
          }
        }
        else {
          this[0x12a] = (PlayerFighter)0x0;
          if (this[0x2ad] != (PlayerFighter)0x0) {
            Player::stopShooting(*(Player **)(this + 4),*(int *)(this + 0x13c));
            this[0x2ad] = (PlayerFighter)0x0;
          }
        }
      }
      piVar19 = (int *)AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
      local_78 = *piVar19;
      local_74 = piVar19[1];
      local_70 = (float)piVar19[2];
      local_6c = (float)piVar19[3];
      local_68 = piVar19[4];
      local_64 = piVar19[5];
      local_60 = (float)piVar19[6];
      fStack_5c = (float)piVar19[7];
      local_58 = piVar19[8];
      iStack_54 = piVar19[9];
      local_50 = *(undefined8 *)(piVar19 + 10);
      local_48 = *(undefined8 *)(piVar19 + 0xc);
      local_40 = piVar19[0xe];
      if (this[0x129] == (PlayerFighter)0x0) {
        local_148 = local_80;
        local_150 = local_88;
        AbyssEngine::AEMath::MatrixGetDir((AEMath *)&local_94,(Matrix *)&local_78);
        AbyssEngine::AEMath::Vector::operator-=((Vector *)&local_88,(Vector *)&local_94);
        AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_d0,(Vector *)&local_88);
        AbyssEngine::AEMath::Vector::operator=((Vector *)&local_88,(Vector *)&local_d0);
        fVar37 = (float)VectorSignedToFloat(param_1 * 0x30,(byte)(in_fpscr >> 0x16) & 3);
        AbyssEngine::AEMath::Vector::operator*=((Vector *)&local_88,fVar37 * 1.5258789e-05);
        AbyssEngine::AEMath::operator+((AEMath *)&local_d0,(Vector *)&local_88,(Vector *)&local_94);
        AbyssEngine::AEMath::Vector::operator=(pVVar29,(Vector *)&local_d0);
        AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_d0,pVVar29);
        AbyssEngine::AEMath::Vector::operator=(pVVar29,(Vector *)&local_d0);
        fVar40 = *(float *)(this + 0x170) - local_150._4_4_;
        fVar39 = *(float *)(this + 0x16c) - (float)local_150;
        fVar38 = *(float *)(this + 0x174) - local_148;
        in_fpscr = in_fpscr & 0xfffffff;
        fVar37 = -fVar40;
        if (0.0 < fVar40) {
          fVar37 = fVar40;
        }
        fVar40 = -fVar39;
        if (0.0 < fVar39) {
          fVar40 = fVar39;
        }
        fVar39 = -fVar38;
        if (0.0 < fVar38) {
          fVar39 = fVar38;
        }
        if (fVar40 + fVar37 + fVar39 < 0.0625) {
          AbyssEngine::AEMath::Vector::operator=(pVVar29,(Vector *)&local_150);
        }
        AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_d0,(Vector *)&local_94);
        fVar37 = (float)AbyssEngine::AEMath::VectorDot((Vector *)&local_d0,pVVar29);
        fVar39 = 0.0;
        in_fpscr = in_fpscr & 0xfffffff;
        if ((fVar37 < 1.0) &&
           (uVar27 = in_fpscr | (uint)(fVar37 < -1.0) << 0x1f | (uint)(fVar37 == -1.0) << 0x1e,
           in_fpscr = uVar27 | (uint)NAN(fVar37) << 0x1c, bVar32 = (byte)(uVar27 >> 0x18),
           !(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1))) {
          fVar39 = (float)AbyssEngine::AEMath::ACosf(0.0);
        }
        fVar37 = -fVar39;
        if (0.0 < fVar39) {
          fVar37 = fVar39;
        }
        in_fpscr = in_fpscr & 0xfffffff | (uint)(fVar37 == 0.0) << 0x1e;
        if ((byte)(in_fpscr >> 0x1e) == 0) {
          AbyssEngine::AEMath::MatrixGetRight((AEMath *)&local_d0,(Matrix *)&local_78);
          local_e0 = *(undefined8 *)pVVar29;
          local_d8 = *(undefined4 *)(this + 0x174);
          fVar39 = (float)AbyssEngine::AEMath::VectorDot((Vector *)&local_d0,(Vector *)&local_e0);
          fVar39 = (float)AbyssEngine::AEMath::ACosf(fVar39);
          in_fpscr = in_fpscr & 0xfffffff;
          if (fVar39 < 1.5707964) {
            fVar37 = -fVar37;
          }
        }
        *(float *)(this + *(int *)(this + 0x2a8) * 4 + 0x294) = fVar37;
        if (this[0x2ac] == (PlayerFighter)0x0) {
          iVar6 = *(int *)(this + 0x2a8);
          if (iVar6 != 0) {
            fVar37 = 0.0;
            if (0 < iVar6) {
              pPVar9 = this + 0x294;
              iVar28 = 0;
              do {
                fVar39 = *(float *)pPVar9;
                iVar28 = iVar28 + 1;
                pPVar9 = pPVar9 + 4;
                fVar37 = fVar37 + fVar39;
              } while (iVar28 < iVar6);
            }
            fVar39 = (float)VectorSignedToFloat(iVar6,(byte)(in_fpscr >> 0x16) & 3);
            goto LAB_000f2f5a;
          }
          *(undefined4 *)(this + 0x2a8) = 1;
        }
        else {
          fVar37 = 0.0;
          iVar6 = 0;
          do {
            iVar28 = iVar6 + 0x294;
            iVar6 = iVar6 + 4;
            fVar37 = fVar37 + *(float *)(this + iVar28);
          } while (iVar6 != 0x14);
          fVar39 = 5.0;
          iVar6 = *(int *)(this + 0x2a8);
LAB_000f2f5a:
          fVar37 = fVar37 / fVar39;
          *(int *)(this + 0x2a8) = iVar6 + 1;
          if ((3 < iVar6) && (*(undefined4 *)(this + 0x2a8) = 0, this[0x2ac] == (PlayerFighter)0x0))
          {
            this[0x2ac] = (PlayerFighter)0x1;
          }
        }
        fVar39 = *(float *)(this + 0x28c);
        fVar37 = fVar37 * fVar39 * *(float *)(this + 0x290);
        in_fpscr = in_fpscr & 0xfffffff;
        uVar27 = in_fpscr | (uint)(fVar37 < fVar39) << 0x1f | (uint)(fVar37 == fVar39) << 0x1e;
        uVar35 = uVar27 | (uint)(NAN(fVar37) || NAN(fVar39)) << 0x1c;
        *(float *)(this + 0x204) = fVar37;
        bVar32 = (byte)(uVar27 >> 0x18);
        if ((bool)(bVar32 >> 6 & 1) || bVar32 >> 7 != ((byte)(uVar35 >> 0x1c) & 1)) {
          if (fVar37 < -fVar39) {
            *(float *)(this + 0x204) = -fVar39;
          }
        }
        else {
          *(float *)(this + 0x204) = fVar39;
          in_fpscr = uVar35;
        }
        AbyssEngine::AEMath::MatrixGetUp((AEMath *)&local_d0,(Matrix *)&local_78);
        AbyssEngine::AEMath::VectorCross((AEMath *)&local_e0,(Vector *)&local_d0,pVVar29);
        AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_d0,(Vector *)&local_e0);
        AbyssEngine::AEMath::Vector::operator=((Vector *)&local_e0,(Vector *)&local_d0);
        AbyssEngine::AEMath::VectorCross(aAStack_ec,pVVar29,(Vector *)&local_e0);
        AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_d0,(Vector *)aAStack_ec);
        AbyssEngine::AEMath::Vector::operator=((Vector *)aAStack_ec,(Vector *)&local_d0);
        AbyssEngine::AEMath::MatrixSetRotation
                  ((AEMath *)&local_d0,(Matrix *)&local_78,(Vector *)&local_e0,(Vector *)aAStack_ec,
                   pVVar29);
        AbyssEngine::AEMath::Matrix::operator=((Matrix *)&local_78,(AEMath *)&local_d0);
        fVar37 = extraout_s1_07;
      }
      else {
        *(undefined4 *)(this + 0x204) = 0;
        *(undefined4 *)(this + 0x2a8) = 0;
        this[0x2ac] = (PlayerFighter)0x0;
        fVar37 = extraout_s1_06;
      }
      if (this[0xfc] != (PlayerFighter)0x0) {
        roll(this,param_1);
        fVar37 = extraout_s1_08;
      }
      fVar40 = *(float *)(this + 0x204);
      fVar39 = *(float *)(this + 0x208);
      in_fpscr = in_fpscr & 0xfffffff;
      uVar27 = in_fpscr | (uint)(fVar39 == fVar40) << 0x1e;
      if ((byte)(uVar27 >> 0x1e) == 0) {
        fVar38 = (float)VectorSignedToFloat(param_1,(byte)(uVar27 >> 0x16) & 3);
        uVar35 = in_fpscr | (uint)(fVar39 < fVar40) << 0x1f | (uint)(fVar39 == fVar40) << 0x1e;
        uVar27 = uVar35 | (uint)(NAN(fVar39) || NAN(fVar40)) << 0x1c;
        fVar38 = (fVar38 * 1.25) / 3.8999999;
        if ((int)uVar35 < 0) {
          fVar39 = fVar38 + fVar39;
          uVar35 = in_fpscr | (uint)(fVar39 < fVar40) << 0x1f | (uint)(fVar39 == fVar40) << 0x1e;
          uVar27 = uVar35 | (uint)(NAN(fVar39) || NAN(fVar40)) << 0x1c;
          *(float *)(this + 0x208) = fVar39;
          bVar32 = (byte)(uVar35 >> 0x18);
          in_fpscr = uVar27;
          if (!(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(uVar27 >> 0x1c) & 1)) {
LAB_000f308a:
            *(float *)(this + 0x208) = fVar40;
            uVar27 = in_fpscr;
            fVar39 = fVar40;
          }
        }
        else if (!(bool)((byte)(uVar35 >> 0x1e) & 1) && ((byte)(uVar27 >> 0x1c) & 1) == 0) {
          fVar39 = fVar39 - fVar38;
          *(float *)(this + 0x208) = fVar39;
          uVar27 = in_fpscr;
          if (fVar39 < fVar40) goto LAB_000f308a;
        }
      }
      iVar6 = *(int *)(this + 0xf8);
      if (0 < iVar6) {
        iVar6 = iVar6 - param_1;
        *(int *)(this + 0xf8) = iVar6;
        if (iVar6 < 1) {
          this[0xfc] = (PlayerFighter)0x1;
        }
      }
      uVar27 = uVar27 & 0xfffffff | (uint)(fVar40 == fVar39) << 0x1e;
      if ((byte)(uVar27 >> 0x1e) == 0) {
        *(undefined4 *)(this + 0xf8) = 0x2ee;
      }
      else if ((0 < iVar6) && (*(int *)(this + 0xf8) = iVar6 - param_1, iVar6 - param_1 < 1)) {
        this[0xfc] = (PlayerFighter)0x1;
      }
      uStack_b4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      uStack_b0 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      uStack_ac = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      puVar23 = (undefined4 *)((uint)&local_d0 | 4);
      local_d0 = 0x3f800000;
      *puVar23 = 0;
      puVar23[1] = uStack_b4;
      puVar23[2] = uStack_b0;
      puVar23[3] = uStack_ac;
      local_bc = 0x3f800000;
      local_b8 = 0;
      local_a8 = 0x3f800000;
      uStack_a0 = 0x3f8000003f800000;
      local_98 = 0x3f800000;
      AbyssEngine::AEMath::MatrixSetRotation
                ((Matrix *)&local_150,fVar39 * 0.00024414062 * 3.1415927,fVar37,3.1415927);
      AbyssEngine::AEMath::Matrix::operator=((Matrix *)&local_d0,(Matrix *)&local_150);
      if (*(Matrix **)(this + 0xc) != (Matrix *)0x0) {
        AEGeometry::setMatrix(*(Matrix **)(this + 0xc));
      }
      if (*(char *)(*(int *)(this + 4) + 0x68) == '\0') {
        fVar37 = (float)VectorSignedToFloat(param_1,(byte)(uVar27 >> 0x16) & 3);
        fVar37 = (float)VectorSignedToFloat((int)(fVar37 * *(float *)(this + 0x1e0)),
                                            (byte)(uVar27 >> 0x16) & 3);
        local_6c = local_6c + local_70 * fVar37;
        fStack_5c = fStack_5c + fVar37 * local_60;
        local_50 = CONCAT44(local_50._4_4_ + fVar37 * (float)local_50,(float)local_50);
        if (this[0xfc] != (PlayerFighter)0x0) {
          AbyssEngine::AEMath::Matrix::operator*=((Matrix *)&local_78,this + 0x250);
        }
        AbyssEngine::PaintCanvas::TransformSetLocal
                  (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc),(Matrix *)&local_78);
        AbyssEngine::AEMath::Matrix::operator=
                  ((Matrix *)(*(int *)(this + 4) + 4),(Matrix *)&local_78);
        if (*(AEGeometry **)(this + 0xc) != (AEGeometry *)0x0) {
          iVar6 = *(int *)(this + 4);
          pMVar11 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 0xc));
          AbyssEngine::AEMath::Matrix::operator*=((Matrix *)(iVar6 + 4),pMVar11);
        }
        ParticleSystemManager::enableSystemEmit
                  (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x8c),*(int *)(this + 300),
                   false);
        ParticleSystemManager::enableSystemEmit
                  (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x8c),*(int *)(this + 0x130),
                   false);
        iVar6 = *(int *)(this + 0x50);
        bVar33 = false;
      }
      else {
        ParticleSystemManager::enableSystemEmit
                  (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x8c),*(int *)(this + 300),
                   true);
        ParticleSystemManager::enableSystemEmit
                  (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x8c),*(int *)(this + 0x130),
                   true);
        iVar6 = *(int *)(this + 0x50);
        bVar33 = true;
      }
      ParticleSystemManager::enableSystemEmit
                (*(ParticleSystemManager **)(iVar6 + 0x8c),*(int *)(this + 0x134),bVar33);
      AEGeometry::updateReferenceMatrix(*(AEGeometry **)(this + 8));
      if (this[0x13a] != (PlayerFighter)0x0) {
        puVar18 = (uint *)Level::getLandmarks(*(Level **)(this + 0x50));
        if ((puVar18 != (uint *)0x0) && (*puVar18 != 0)) {
          uVar35 = 0;
          do {
            piVar19 = *(int **)(puVar18[1] + uVar35 * 4);
            if ((piVar19 != (int *)0x0) &&
               (iVar6 = (**(code **)(*piVar19 + 0x40))(piVar19,pVVar30), iVar6 == 1)) {
              piVar19 = *(int **)(puVar18[1] + uVar35 * 4);
              (**(code **)(*piVar19 + 0x50))((Vector *)&local_150,piVar19,pVVar30);
              local_94 = 0;
              local_90 = 0;
              local_8c = 0;
              iVar6 = AbyssEngine::AEMath::operator!=((Vector *)&local_150,(Vector *)&local_94);
              if (iVar6 == 1) {
                AEGeometry::getDirection();
                pVVar29 = (Vector *)(this + 0x8c);
                AbyssEngine::AEMath::Vector::operator=(pVVar29,(Vector *)&local_94);
                AbyssEngine::AEMath::Vector::operator-=((Vector *)&local_150,pVVar29);
                AbyssEngine::AEMath::Vector::operator*=
                          ((Vector *)&local_150,*(float *)(this + 0x1e0) * 0.03);
                AbyssEngine::AEMath::operator+((AEMath *)&local_94,pVVar29,(Vector *)&local_150);
                pVVar29 = (Vector *)(this + 0x98);
                AbyssEngine::AEMath::Vector::operator=(pVVar29,(Vector *)&local_94);
                AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_94,pVVar29);
                AbyssEngine::AEMath::Vector::operator=(pVVar29,(Vector *)&local_94);
                local_94 = 0;
                local_90 = 0x3f800000;
                local_8c = 0;
                AEGeometry::setDirection(*(AEGeometry **)(this + 8),pVVar29,(Vector *)&local_94);
                fVar37 = (float)VectorSignedToFloat(param_1,(byte)(uVar27 >> 0x16) & 3);
                AEGeometry::moveForward
                          (*(AEGeometry **)(this + 8),fVar37 * *(float *)(this + 0x1e0));
                break;
              }
            }
            uVar35 = uVar35 + 1;
          } while (uVar35 < *puVar18);
        }
        puVar18 = (uint *)Level::getEnemies(*(Level **)(this + 0x50));
        if ((puVar18 != (uint *)0x0) && (*puVar18 != 0)) {
          uVar35 = 0;
          do {
            piVar19 = *(int **)(puVar18[1] + uVar35 * 4);
            if ((piVar19 != (int *)0x0) &&
               (iVar6 = (**(code **)(*piVar19 + 0x40))(piVar19,pVVar30), iVar6 == 1)) {
              piVar19 = *(int **)(puVar18[1] + uVar35 * 4);
              (**(code **)(*piVar19 + 0x50))((Vector *)&local_150,piVar19,pVVar30);
              local_94 = 0;
              local_90 = 0;
              local_8c = 0;
              iVar6 = AbyssEngine::AEMath::operator!=((Vector *)&local_150,(Vector *)&local_94);
              if (iVar6 == 1) {
                AEGeometry::getDirection();
                pVVar30 = (Vector *)(this + 0x8c);
                AbyssEngine::AEMath::Vector::operator=(pVVar30,(Vector *)&local_94);
                AbyssEngine::AEMath::Vector::operator-=((Vector *)&local_150,pVVar30);
                AbyssEngine::AEMath::Vector::operator*=
                          ((Vector *)&local_150,*(float *)(this + 0x1e0) * 0.03);
                AbyssEngine::AEMath::operator+((AEMath *)&local_94,pVVar30,(Vector *)&local_150);
                pVVar30 = (Vector *)(this + 0x98);
                AbyssEngine::AEMath::Vector::operator=(pVVar30,(Vector *)&local_94);
                AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_94,pVVar30);
                AbyssEngine::AEMath::Vector::operator=(pVVar30,(Vector *)&local_94);
                local_94 = 0;
                local_90 = 0x3f800000;
                local_8c = 0;
                AEGeometry::setDirection(*(AEGeometry **)(this + 8),pVVar30,(Vector *)&local_94);
                fVar37 = (float)VectorSignedToFloat(param_1,(byte)(uVar27 >> 0x16) & 3);
                AEGeometry::moveForward
                          (*(AEGeometry **)(this + 8),fVar37 * *(float *)(this + 0x1e0));
                break;
              }
            }
            uVar35 = uVar35 + 1;
          } while (uVar35 < *puVar18);
        }
      }
      (**(code **)(*(int *)this + 0x30))(this,param_1);
      break;
    case 3:
      fStack_5c = *(float *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      local_58 = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      iStack_54 = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      puVar23 = (undefined4 *)((uint)&local_78 | 4);
      this[0x13a] = (PlayerFighter)0x0;
      this[0xfd] = (PlayerFighter)0x0;
      local_78 = 0x3f800000;
      *puVar23 = 0;
      puVar23[1] = fStack_5c;
      puVar23[2] = local_58;
      puVar23[3] = iStack_54;
      local_64 = 0x3f800000;
      local_60 = 0.0;
      local_50 = 0x3f800000;
      local_48 = 0x3f8000003f800000;
      local_40 = 0x3f800000;
      AbyssEngine::AEMath::MatrixSetRotation
                ((Matrix *)&local_d0,*(float *)(this + 0x18c),fVar39,fVar40);
      if (0 < param_1) {
        pAVar17 = *(AEGeometry **)(this + 8);
        pMVar11 = (Matrix *)AEGeometry::getMatrix(pAVar17);
        AbyssEngine::AEMath::operator*((AEMath *)&local_d0,pMVar11,(Matrix *)&local_78);
        AEGeometry::setMatrix(pAVar17);
      }
      fVar37 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
      pVVar29 = *(Vector **)(this + 8);
      fVar37 = (float)AbyssEngine::AEMath::operator*
                                ((AEMath *)&local_150,(Vector *)(this + 400),fVar37);
      AbyssEngine::AEMath::operator*((AEMath *)&local_d0,(Vector *)&local_150,fVar37);
      AEGeometry::translate(pVVar29);
      AEGeometry::updateReferenceMatrix(*(AEGeometry **)(this + 8));
      iVar6 = *(int *)(this + 0x1f0);
      *(int *)(this + 0x1f0) = iVar6 - param_1;
      if (0x7fffffff < (uint)(iVar6 - param_1)) {
        local_d0 = 0;
        local_cc = 0;
        local_c8 = 0;
        Explosion::start(*(Explosion **)(this + 0x120),pVVar30,(Vector *)&local_d0);
        ParticleSystemManager::enableSystemEmit
                  (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x74),*(int *)(this + 0x19c),
                   false);
        uVar27 = in_fpscr & 0xfffffff | (uint)((float)Globals::options._40_4_ < 0.0) << 0x1f |
                 (uint)((float)Globals::options._40_4_ == 0.0) << 0x1e;
        uVar35 = uVar27 | (uint)NAN((float)Globals::options._40_4_) << 0x1c;
        bVar32 = (byte)(uVar27 >> 0x18);
        if (!(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(uVar35 >> 0x1c) & 1)) {
          ParticleSystemManager::enableSystemEmit
                    (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x78),*(int *)(this + 0x7c)
                     ,false);
          ParticleSystemManager::enableSystemEmit
                    (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x84),*(int *)(this + 0x80)
                     ,false);
        }
        pPVar7 = *(Player **)(this + 4);
        uVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x32);
        fVar37 = (float)VectorSignedToFloat(uVar10,(byte)(uVar35 >> 0x16) & 3);
        Player::setBombForce(pPVar7,fVar37 * 0.01 + 50.0);
        iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,200);
        uVar10 = VectorSignedToFloat(iVar6 + -100,(byte)(uVar35 >> 0x16) & 3);
        iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,200);
        uVar41 = VectorSignedToFloat(iVar6 + -100,(byte)(uVar35 >> 0x16) & 3);
        iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,200);
        local_148 = (float)VectorSignedToFloat(iVar6 + -100,(byte)(uVar35 >> 0x16) & 3);
        local_150 = CONCAT44(uVar41,uVar10);
        AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_d0,(Vector *)&local_150);
        AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x178),(Vector *)&local_d0);
        *(undefined4 *)(this + 0x84) = 4;
        *(undefined4 *)(this + 0x1f0) = 0;
        if ((*(SpacePoint **)(this + 700) != (SpacePoint *)0x0) &&
           (iVar6 = SpacePoint::isFree(*(SpacePoint **)(this + 700)), iVar6 == 0)) {
          SpacePoint::giveFree(*(SpacePoint **)(this + 700));
          *(undefined4 *)(this + 700) = 0;
        }
        if (this[0x48] != (PlayerFighter)0x0) {
          if ((this[0xcc] == (PlayerFighter)0x0) || (this[0x65] != (PlayerFighter)0x0)) {
            iVar6 = 0;
            if (*(int *)(this + 0x24) == 9) {
              iVar6 = 4;
            }
            KIPlayer::createCrate((KIPlayer *)this,iVar6);
          }
          else {
            this[100] = (PlayerFighter)0x1;
            this[0x48] = (PlayerFighter)0x0;
          }
        }
      }
      break;
    case 4:
      iVar6 = *(int *)(this + 0x1f0);
      *(int *)(this + 0x1f0) = iVar6 + param_1;
      if (iVar6 + param_1 < 1) {
        fStack_5c = *(float *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
        local_58 = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
        iStack_54 = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
        puVar23 = (undefined4 *)((uint)&local_78 | 4);
        local_78 = 0x3f800000;
        *puVar23 = 0;
        puVar23[1] = fStack_5c;
        puVar23[2] = local_58;
        puVar23[3] = iStack_54;
        local_64 = 0x3f800000;
        local_60 = 0.0;
        local_50 = 0x3f800000;
        local_48 = 0x3f8000003f800000;
        local_40 = 0x3f800000;
        AbyssEngine::AEMath::MatrixSetRotation
                  ((Matrix *)&local_d0,*(float *)(this + 0x18c),fVar39,fVar40);
        if (0 < param_1) {
          pAVar17 = *(AEGeometry **)(this + 8);
          pMVar11 = (Matrix *)AEGeometry::getMatrix(pAVar17);
          AbyssEngine::AEMath::operator*((AEMath *)&local_d0,pMVar11,(Matrix *)&local_78);
          AEGeometry::setMatrix(pAVar17);
        }
        fVar37 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        pVVar30 = *(Vector **)(this + 8);
        fVar37 = (float)AbyssEngine::AEMath::operator*
                                  ((AEMath *)&local_150,(Vector *)(this + 400),fVar37);
        AbyssEngine::AEMath::operator*((AEMath *)&local_d0,(Vector *)&local_150,fVar37);
        AEGeometry::translate(pVVar30);
        AEGeometry::updateReferenceMatrix(*(AEGeometry **)(this + 8));
      }
      else {
        this[0x6f] = (PlayerFighter)0x0;
      }
      AEGeometry::updateReferenceMatrix(*(AEGeometry **)(this + 8));
      this_05 = *(Explosion **)(this + 0x120);
      iVar6 = Level::getPlayer(*(Level **)(this + 0x50));
      if (iVar6 == 0) {
        pTVar16 = (TargetFollowCamera *)0x0;
      }
      else {
        pPVar15 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x50));
        pTVar16 = (TargetFollowCamera *)PlayerEgo::getTargetFollowCamera(pPVar15);
      }
      Explosion::update(this_05,param_1,pTVar16);
      *(int *)(this + 0xd4) = *(int *)(this + 0xd4) + param_1;
      if (((this[0x48] == (PlayerFighter)0x0) ||
          (iVar6 = Player::isActive(*(Player **)(this + 4)), iVar6 != 1)) ||
         ((param_1 < 1 || (*(int *)(this + 0x74) == 0)))) {
        iVar6 = Explosion::isPlaying(*(Explosion **)(this + 0x120));
        if (iVar6 == 0) {
          if ((this[0xcc] != (PlayerFighter)0x0) && (this[0x65] == (PlayerFighter)0x0)) {
            this[100] = (PlayerFighter)0x1;
          }
          if (60000 < *(int *)(this + 0xd4)) goto LAB_000f2ad4;
          goto LAB_000f2adc;
        }
      }
      else {
        fVar39 = (float)Player::getBombForce(*(Player **)(this + 4));
        uVar35 = in_fpscr & 0xfffffff | (uint)(fVar39 < 0.0) << 0x1f | (uint)(fVar39 == 0.0) << 0x1e
        ;
        uVar27 = uVar35 | (uint)NAN(fVar39) << 0x1c;
        bVar32 = (byte)(uVar35 >> 0x18);
        fVar37 = extraout_s1_04;
        if (!(bool)(bVar32 >> 6 & 1) && bVar32 >> 7 == ((byte)(uVar27 >> 0x1c) & 1)) {
          AbyssEngine::AEMath::operator*((AEMath *)&local_78,(Vector *)(this + 0x178),extraout_s0);
          AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x8c),(Vector *)&local_78);
          AEGeometry::translate(*(Vector **)(this + 0x74));
          AEGeometry::translate(*(Vector **)(this + 8));
          uVar27 = uVar27 & 0xfffffff;
          fVar37 = fVar39 * 0.98;
          if (fVar39 * 0.98 < 0.05) {
            fVar37 = 0.0;
          }
          Player::setBombForce(*(Player **)(this + 4),fVar37);
          fVar37 = extraout_s1_05;
        }
        fVar39 = (float)VectorSignedToFloat(param_1 >> 1,(byte)(uVar27 >> 0x16) & 3);
        fVar39 = (float)VectorSignedToFloat((int)(fVar39 * 1.5258789e-05 * 6.2831855),
                                            (byte)(uVar27 >> 0x16) & 3);
        AEGeometry::rotate(*(AEGeometry **)(this + 0x74),fVar39,fVar37,6.2831855);
        iVar6 = *(int *)(this + 4);
        pMVar11 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 0x74));
        AbyssEngine::AEMath::Matrix::operator=((Matrix *)(iVar6 + 4),pMVar11);
        if ((60000 < *(int *)(this + 0xd4)) &&
           (iVar6 = Explosion::isPlaying(*(Explosion **)(this + 0x120)), iVar6 == 0)) {
          iVar6 = Level::getPlayer(*(Level **)(this + 0x50));
          if ((iVar6 != 0) &&
             ((iVar6 = Level::getPlayer(*(Level **)(this + 0x50)), *(int *)(iVar6 + 0x14) != 0 &&
              (iVar6 = Level::getPlayer(*(Level **)(this + 0x50)),
              *(PlayerFighter **)(*(int *)(iVar6 + 0x14) + 0x1c) == this)))) {
            iVar6 = Level::getPlayer(*(Level **)(this + 0x50));
            *(undefined4 *)(*(int *)(iVar6 + 0x14) + 0x1c) = 0;
          }
          if ((this[0xcc] != (PlayerFighter)0x0) && (this[0x65] == (PlayerFighter)0x0)) {
            this[100] = (PlayerFighter)0x1;
          }
          if (*(AEGeometry **)(this + 0x74) != (AEGeometry *)0x0) {
            pvVar12 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x74));
            operator_delete(pvVar12);
          }
          *(undefined4 *)(this + 0x74) = 0;
          *(undefined4 *)(this + 0xd4) = 0;
LAB_000f2ad4:
          KIPlayer::setActive(SUB41(this,0));
LAB_000f2adc:
          this[0xfd] = (PlayerFighter)0x1;
        }
      }
      break;
    case 5:
      if ((*(char *)(*(int *)(this + 4) + 0x5c) != '\0') &&
         (iVar6 = Status::getCurrentCampaignMission(Globals::status), 1 < iVar6)) {
        pAVar17 = *(AEGeometry **)(this + 0xc);
        if (pAVar17 == (AEGeometry *)0x0) {
          pAVar17 = *(AEGeometry **)(this + 8);
        }
        AEGeometry::setVisible(pAVar17,false);
      }
      if ((*(int *)(this + 0x144) != 0) && (*(char *)(*(int *)(this + 0x144) + 0x5e) == '\0')) {
        fVar37 = (float)VectorSignedToFloat(*(int *)(this + 0x124),(byte)(in_fpscr >> 0x16) & 3);
        if ((*(float *)(this + 0x16c) < fVar37) &&
           ((((fVar39 = (float)VectorSignedToFloat(-*(int *)(this + 0x124),
                                                   (byte)((in_fpscr & 0xfffffff) >> 0x16) & 3),
              fVar39 < *(float *)(this + 0x16c) &&
              ((int)((uint)(*(float *)(this + 0x170) < fVar37) << 0x1f) < 0)) &&
             (fVar39 < *(float *)(this + 0x170))) &&
            (((int)((uint)(*(float *)(this + 0x174) < fVar37) << 0x1f) < 0 &&
             (fVar39 < *(float *)(this + 0x174))))))) {
          *(undefined4 *)(this + 0x84) = 1;
          pAVar17 = *(AEGeometry **)(this + 0xc);
          if (pAVar17 == (AEGeometry *)0x0) {
            pAVar17 = *(AEGeometry **)(this + 8);
          }
          AEGeometry::setVisible(pAVar17,true);
          Player::setActive(*(Player **)(this + 4),true);
          if (this[299] != (PlayerFighter)0x0) {
            Level::pirateStationAction(*(Level **)(this + 0x50),true);
          }
        }
      }
      break;
    case 6:
      fVar39 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
      fVar37 = *(float *)(this + 0x1e0) * 1.1;
      VectorSignedToFloat((int)(fVar39 * fVar37),(byte)(in_fpscr >> 0x16) & 3);
      *(float *)(this + 0x1e0) = fVar37;
      AEGeometry::moveForward(*(AEGeometry **)(this + 8),fVar37);
      if (100.0 < *(float *)(this + 0x1e0)) {
        KIPlayer::setDead((KIPlayer *)this);
      }
      break;
    case 8:
      pKVar14 = (KIPlayer *)Route::getDockingTarget(*(Route **)(this + 0x68));
      piVar19 = (int *)Route::getDockingTarget(*(Route **)(this + 0x68));
      (**(code **)(*piVar19 + 0x28))((Vector *)&local_d0);
      iVar6 = Route::getDockingTarget(*(Route **)(this + 0x68));
      pMVar11 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(iVar6 + 8));
      AbyssEngine::AEMath::MatrixRotateVector((AEMath *)&local_150,pMVar11,*(Vector **)(this + 700))
      ;
      AbyssEngine::AEMath::operator+((AEMath *)&local_78,(Vector *)&local_d0,(Vector *)&local_150);
      pVVar30 = (Vector *)KIPlayer::getNearestDockingPoint(pKVar14,(Vector *)&local_78);
      piVar19 = (int *)Route::getDockingTarget(*(Route **)(this + 0x68));
      (**(code **)(*piVar19 + 0x28))((Vector *)&local_d0);
      iVar6 = Route::getDockingTarget(*(Route **)(this + 0x68));
      pMVar11 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(iVar6 + 8));
      AbyssEngine::AEMath::MatrixRotateVector((AEMath *)&local_150,pMVar11,pVVar30);
      AbyssEngine::AEMath::operator+((AEMath *)&local_78,(Vector *)&local_d0,(Vector *)&local_150);
      pVVar30 = (Vector *)(this + 0x98);
      AbyssEngine::AEMath::Vector::operator=(pVVar30,(Vector *)&local_78);
      (**(code **)(*(int *)this + 0x28))((Vector *)&local_d0,this);
      AbyssEngine::AEMath::operator-((AEMath *)&local_78,pVVar30,(Vector *)&local_d0);
      fVar37 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_78);
      if ((int)fVar37 < *(int *)(&DAT_00254820 + *(int *)(this + 0xa8) * 4)) {
        setExhaustVisible(this,false);
        *(undefined4 *)(this + 0x2b4) = 0;
        *(undefined4 *)(this + 0x2b8) = 0;
        *(undefined4 *)(this + 0x84) = 9;
        if (this[500] != (PlayerFighter)0x0) {
          ParticleSystemManager::enableSystemEmit
                    (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x78),*(int *)(this + 0x7c)
                     ,false);
          ParticleSystemManager::enableSystemEmit
                    (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x84),*(int *)(this + 0x80)
                     ,false);
        }
      }
      else {
        fVar37 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        AbyssEngine::EaseInOutMatrix::Increase(*(EaseInOutMatrix **)(this + 0x2b0),fVar37);
        AbyssEngine::EaseInOutMatrix::GetValue();
        (**(code **)(*(int *)this + 0x28))((Vector *)&local_88,this);
        (**(code **)(*(int *)this + 0x28))(aVStack_f8,this);
        fVar37 = (float)AbyssEngine::AEMath::operator-(aAStack_ec,pVVar30,aVStack_f8);
        fVar37 = (float)AbyssEngine::AEMath::operator*
                                  ((AEMath *)&local_e0,(Vector *)aAStack_ec,fVar37);
        AbyssEngine::AEMath::operator*((AEMath *)&local_94,(Vector *)&local_e0,fVar37);
        AbyssEngine::AEMath::operator+((AEMath *)&local_150,(Vector *)&local_88,(Vector *)&local_94)
        ;
        AbyssEngine::AEMath::MatrixSetTranslation
                  ((AEMath *)&local_d0,(Matrix *)&local_78,(Vector *)&local_150);
        AEGeometry::setMatrix(*(Matrix **)(this + 8));
        AbyssEngine::AEMath::Matrix::operator=
                  ((Matrix *)(*(int *)(this + 4) + 4),(Matrix *)&local_78);
      }
      break;
    case 9:
      pMVar21 = (Mission *)Status::getMission(Globals::status);
      *(int *)(this + 0x2b4) = *(int *)(this + 0x2b4) + param_1;
      iVar6 = Mission::isEmpty(pMVar21);
      if ((iVar6 == 0) && (iVar6 = Mission::getType(pMVar21), iVar6 == 0xb8)) {
        this_03 = (PlayerFixedObject *)Route::getDockingTarget(*(Route **)(this + 0x68));
        iVar6 = PlayerFixedObject::getDockingType(this_03);
        if (iVar6 == 1) {
          fVar37 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x2b4),
                                              (byte)(in_fpscr >> 0x16) & 3);
          iVar6 = *(int *)(this + 0x2b8);
          if (*(int *)(this + 0x78) == 0x33) {
            fVar39 = 200.0;
          }
          else {
            fVar39 = 1500.0;
          }
          *(int *)(this + 0x2b8) = (int)(fVar37 / fVar39);
          iVar28 = Status::getCurrentCampaignMission(Globals::status);
          if (iVar28 == 0x5e) {
            iVar28 = Mission::getStatusValue(pMVar21);
            this_04 = (Ship *)Status::getShip(Globals::status);
            iVar20 = Ship::getMaxPassengers(this_04);
            if (iVar28 <= iVar20) goto LAB_000f26f8;
          }
          if (iVar6 < *(int *)(this + 0x2b8)) {
            iVar28 = Level::getNumDeliveredPassengers(*(Level **)(this + 0x50));
            iVar20 = Mission::getProductionGoodAmount(pMVar21);
            if (iVar28 < iVar20) {
              iVar28 = Mission::getStatusValue(pMVar21);
              Mission::setStatusValue(pMVar21,(iVar28 + iVar6) - *(int *)(this + 0x2b8));
              uVar27 = Mission::getStatusValue(pMVar21);
              if (0x7fffffff < uVar27) {
                Mission::setStatusValue(pMVar21,0);
              }
            }
          }
        }
      }
LAB_000f26f8:
      iVar28 = *(int *)(this + 0x2b4);
      iVar6 = Route::getDockingTime(*(Route **)(this + 0x68));
      if (iVar6 < iVar28) {
        setExhaustVisible(this,true);
        pRVar13 = *(Route **)(this + 0x68);
        iVar6 = Route::getCurrent(pRVar13);
        Route::reachWaypoint(pRVar13,iVar6);
        *(undefined4 *)(this + 0x84) = 1;
        if (this[500] != (PlayerFighter)0x0) {
          ParticleSystemManager::enableSystemEmit
                    (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x78),*(int *)(this + 0x7c)
                     ,true);
          ParticleSystemManager::enableSystemEmit
                    (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x84),*(int *)(this + 0x80)
                     ,true);
        }
        if (*(SpacePoint **)(this + 700) != (SpacePoint *)0x0) {
          SpacePoint::giveFree(*(SpacePoint **)(this + 700));
          *(undefined4 *)(this + 700) = 0;
        }
      }
    }
  }
  else {
    AEGeometry::updateReferenceMatrix(*(AEGeometry **)(this + 8));
    handleCloaking(this);
  }
  iVar6 = __stack_chk_guard - local_3c;
  if (iVar6 == 0) {
    return;
  }
LAB_000f2056:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar6,local_3c);
}

// ===== PlayerFighter::roll  @0x000f36b0  (416 bytes)
/* PlayerFighter::roll(int) */

void __thiscall PlayerFighter::roll(PlayerFighter *this,int param_1)

{
  byte bVar1;
  ushort uVar2;
  PlayerFighter PVar3;
  int iVar4;
  float *pfVar5;
  uint in_fpscr;
  uint uVar6;
  float fVar8;
  float extraout_s1;
  float fVar9;
  float fVar10;
  AEMath aAStack_54 [60];
  int local_18;
  uint uVar7;
  
  local_18 = __stack_chk_guard;
  if (this[0xfc] == (PlayerFighter)0x0) goto LAB_000f37c0;
  iVar4 = AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
  fVar8 = *(float *)(iVar4 + 0x10);
  fVar9 = *(float *)(iVar4 + 0x14);
  uVar7 = in_fpscr & 0xfffffff | (uint)(fVar9 < 0.0) << 0x1f | (uint)(fVar9 == 0.0) << 0x1e;
  fVar10 = -fVar8;
  if (0.0 < fVar8) {
    fVar10 = fVar8;
  }
  if (0x3c < param_1) {
    param_1 = 0x3c;
  }
  bVar1 = (byte)(uVar7 >> 0x18);
  if ((!(bool)(bVar1 >> 6 & 1) && (bool)(bVar1 >> 7) == NAN(fVar9)) &&
     (uVar7 = in_fpscr & 0xfffffff, fVar10 < 0.015)) {
    AbyssEngine::AEMath::MatrixIdentity(aAStack_54,(Matrix *)(this + 0x250));
    AbyssEngine::AEMath::Matrix::operator=((Matrix *)(this + 0x250),aAStack_54);
    this[0xfc] = (PlayerFighter)0x0;
    this[0x24d] = (PlayerFighter)0x0;
    this[0x24c] = (PlayerFighter)0x0;
    goto LAB_000f37c0;
  }
  if ((*(ushort *)(this + 0x24c) & 0xff) == 0) {
    uVar2 = *(ushort *)(this + 0x24c) >> 8;
    uVar6 = uVar7 & 0xfffffff;
    uVar7 = uVar6 | (uint)(fVar8 < 0.0) << 0x1f;
    if ((fVar8 == 0.0 || SUB41(uVar7 >> 0x1f,0) != NAN(fVar8)) || (uVar2 != 1)) {
      uVar7 = uVar6;
      if (0.0 <= fVar8) {
        if ((NAN(fVar8)) || (0.0 <= fVar9)) {
LAB_000f3810:
          uVar7 = uVar6 | (uint)(fVar8 < 0.0) << 0x1f;
          if ((fVar8 != 0.0 && SUB41(uVar7 >> 0x1f,0) == NAN(fVar8)) &&
             (uVar7 = uVar6 | (uint)(fVar9 < 0.0) << 0x1f,
             fVar9 != 0.0 && SUB41(uVar7 >> 0x1f,0) == NAN(fVar9))) {
            fVar9 = 0.3;
            pfVar5 = (float *)&UNK_000f387c;
            if (0.3 < fVar8) {
              pfVar5 = (float *)&DAT_000f3880;
            }
LAB_000f384a:
            uVar7 = uVar6;
            fVar10 = *pfVar5;
          }
        }
        else {
          fVar10 = -0.00075;
        }
      }
      else {
        if (uVar2 == 2) {
          fVar10 = 0.00035;
          goto LAB_000f3776;
        }
        if (0.0 <= fVar9) {
          if (NAN(fVar9)) goto LAB_000f3810;
          fVar9 = -0.3;
          pfVar5 = (float *)&DAT_000f3870;
          uVar6 = uVar6 | (uint)(fVar8 < -0.3) << 0x1f;
          if (fVar8 != -0.3 && SUB41(uVar6 >> 0x1f,0) == NAN(fVar8)) {
            pfVar5 = (float *)&DAT_000f3874;
          }
          goto LAB_000f384a;
        }
        fVar10 = 0.00075;
      }
    }
    else {
      fVar10 = -0.00035;
      uVar6 = uVar7;
LAB_000f3776:
      this[0x24c] = (PlayerFighter)0x1;
      uVar7 = uVar6;
    }
  }
  else {
    uVar7 = uVar7 & 0xfffffff;
    pfVar5 = (float *)&DAT_000f385c;
    if (!NAN(fVar9)) {
      pfVar5 = (float *)&DAT_000f3860;
    }
    fVar9 = *pfVar5;
    fVar10 = -0.0002;
    if (fVar8 < 0.0) {
      fVar10 = fVar9;
    }
  }
  uVar7 = uVar7 & 0xfffffff | (uint)(fVar8 < 0.0) << 0x1f | (uint)(fVar8 == 0.0) << 0x1e;
  uVar6 = uVar7 | (uint)NAN(fVar8) << 0x1c;
  if ((int)uVar7 < 0) {
    PVar3 = (PlayerFighter)0x1;
LAB_000f378c:
    this[0x24d] = PVar3;
  }
  else if (!(bool)((byte)(uVar7 >> 0x1e) & 1) && ((byte)(uVar6 >> 0x1c) & 1) == 0) {
    PVar3 = (PlayerFighter)0x2;
    goto LAB_000f378c;
  }
  fVar8 = (float)VectorSignedToFloat(param_1,(byte)(uVar6 >> 0x16) & 3);
  this[0xfc] = (PlayerFighter)0x1;
  AbyssEngine::AEMath::MatrixSetRotation(aAStack_54,fVar8 * fVar10,extraout_s1,fVar9);
  AbyssEngine::AEMath::Matrix::operator=((Matrix *)(this + 0x250),aAStack_54);
LAB_000f37c0:
  if (__stack_chk_guard == local_18) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== PlayerFighter::render  @0x000f3890  (352 bytes)
/* PlayerFighter::render() */

void __thiscall PlayerFighter::render(PlayerFighter *this)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  if (*(AEGeometry **)(this + 0x74) != (AEGeometry *)0x0) {
    AEGeometry::render(*(AEGeometry **)(this + 0x74));
  }
  iVar1 = Player::isActive(*(Player **)(this + 4));
  iVar3 = *(int *)(this + 0x84);
  if (iVar1 == 0) {
    if (iVar3 != 5) goto LAB_000f39ba;
LAB_000f38f0:
    if (*(int *)(this + 0xc) == 0) {
      AEGeometry::render(*(AEGeometry **)(this + 8));
    }
    else {
      puVar2 = (undefined4 *)
               AbyssEngine::PaintCanvas::TransformGetLocal
                         (Globals::Canvas,*(uint *)(*(int *)(this + 0xc) + 0xc));
      local_60 = *puVar2;
      uStack_5c = puVar2[1];
      uStack_58 = puVar2[2];
      uStack_54 = puVar2[3];
      uStack_50 = puVar2[4];
      local_4c = puVar2[5];
      uStack_48 = puVar2[6];
      uStack_44 = puVar2[7];
      uStack_40 = puVar2[8];
      uStack_3c = puVar2[9];
      local_38 = puVar2[10];
      uStack_34 = puVar2[0xb];
      uStack_30 = puVar2[0xc];
      uStack_2c = puVar2[0xd];
      uStack_28 = puVar2[0xe];
      AbyssEngine::PaintCanvas::TransformSetLocal
                (Globals::Canvas,*(uint *)(*(int *)(this + 0xc) + 0xc),
                 (Matrix *)(*(int *)(this + 4) + 4));
      AEGeometry::render(*(AEGeometry **)(this + 0xc));
      AbyssEngine::PaintCanvas::TransformSetLocal
                (Globals::Canvas,*(uint *)(*(int *)(this + 0xc) + 0xc),(Matrix *)&local_60);
    }
    if (*(Trail **)(this + 0x150) != (Trail *)0x0) {
      Trail::render(*(Trail **)(this + 0x150));
    }
  }
  else {
    if (1 < iVar3 - 3U) goto LAB_000f38f0;
    if (*(Explosion **)(this + 0x120) != (Explosion *)0x0) {
      Explosion::render(*(Explosion **)(this + 0x120));
      iVar3 = *(int *)(this + 0x84);
    }
    if (iVar3 == 4) {
      if (*(int *)(this + 0x1f0) < 300) {
        uVar4 = *(uint *)(*(int *)(this + 0xc) + 0xc);
        goto LAB_000f3974;
      }
    }
    else if (iVar3 == 3) {
      if (*(int *)(this + 0xc) == 0) {
        if (__stack_chk_guard == local_24) {
          AEGeometry::render(*(AEGeometry **)(this + 8));
          return;
        }
        goto LAB_000f39ce;
      }
      uVar4 = *(uint *)(*(int *)(this + 0xc) + 0xc);
LAB_000f3974:
      puVar2 = (undefined4 *)AbyssEngine::PaintCanvas::TransformGetLocal(Globals::Canvas,uVar4);
      local_60 = *puVar2;
      uStack_5c = puVar2[1];
      uStack_58 = puVar2[2];
      uStack_54 = puVar2[3];
      uStack_50 = puVar2[4];
      local_4c = puVar2[5];
      uStack_48 = puVar2[6];
      uStack_44 = puVar2[7];
      uStack_40 = puVar2[8];
      uStack_3c = puVar2[9];
      local_38 = puVar2[10];
      uStack_34 = puVar2[0xb];
      uStack_30 = puVar2[0xc];
      uStack_2c = puVar2[0xd];
      uStack_28 = puVar2[0xe];
      AbyssEngine::PaintCanvas::TransformSetLocal
                (Globals::Canvas,*(uint *)(*(int *)(this + 0xc) + 0xc),
                 (Matrix *)(*(int *)(this + 4) + 4));
      AEGeometry::render(*(AEGeometry **)(this + 0xc));
      AbyssEngine::PaintCanvas::TransformSetLocal
                (Globals::Canvas,*(uint *)(*(int *)(this + 0xc) + 0xc),(Matrix *)&local_60);
    }
  }
LAB_000f39ba:
  if (__stack_chk_guard == local_24) {
    return;
  }
LAB_000f39ce:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== PlayerFighter::setBV  @0x000f3a08  (6 bytes)
/* PlayerFighter::setBV(Array<BoundingVolume*>*) */

void __thiscall PlayerFighter::setBV(PlayerFighter *this,Array *param_1)

{
  *(Array **)(this + 0x14c) = param_1;
  return;
}

// ===== PlayerFighter::setBV  @0x000f3a0e  (62 bytes)
/* PlayerFighter::setBV(BoundingVolume*) */

void __thiscall PlayerFighter::setBV(PlayerFighter *this,BoundingVolume *param_1)

{
  int *piVar1;
  undefined4 *__ptr;
  void *pvVar2;
  
  piVar1 = operator_new(0xc);
  __ptr = operator_new__(4);
  piVar1[1] = (int)__ptr;
  *__ptr = 0;
  *piVar1 = 0;
  *(int **)(this + 0x14c) = piVar1;
  piVar1[2] = 1;
  pvVar2 = realloc(__ptr,4);
  piVar1[1] = (int)pvVar2;
  *(BoundingVolume **)((int)pvVar2 + *piVar1 * 4) = param_1;
  *piVar1 = piVar1[2];
  return;
}

// ===== PlayerFighter::collide  @0x000f3a5a  (82 bytes)
/* PlayerFighter::collide(float, float, float) */

undefined4 __thiscall
PlayerFighter::collide(PlayerFighter *this,float param_1,float param_2,float param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  float extraout_s0;
  float extraout_s1;
  float extraout_s2;
  
  if (((1 < *(int *)(this + 0x84) - 3U) &&
      (puVar1 = *(uint **)(this + 0x14c), puVar1 != (uint *)0x0)) && (*puVar1 != 0)) {
    uVar3 = 0;
    do {
      iVar2 = (**(code **)(**(int **)(puVar1[1] + uVar3 * 4) + 8))(param_1,param_2,param_3);
      if (iVar2 == 1) {
        return 1;
      }
      puVar1 = *(uint **)(this + 0x14c);
      uVar3 = uVar3 + 1;
      param_1 = extraout_s0;
      param_2 = extraout_s1;
      param_3 = extraout_s2;
    } while (uVar3 < *puVar1);
  }
  return 0;
}

// ===== PlayerFighter::outerCollide  @0x000f3aac  (82 bytes)
/* PlayerFighter::outerCollide(float, float, float) */

undefined4 __thiscall
PlayerFighter::outerCollide(PlayerFighter *this,float param_1,float param_2,float param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  float extraout_s0;
  float extraout_s1;
  float extraout_s2;
  
  if (((1 < *(int *)(this + 0x84) - 3U) &&
      (puVar1 = *(uint **)(this + 0x14c), puVar1 != (uint *)0x0)) && (*puVar1 != 0)) {
    uVar3 = 0;
    do {
      iVar2 = (**(code **)(**(int **)(puVar1[1] + uVar3 * 4) + 0xc))(param_1,param_2,param_3);
      if (iVar2 == 1) {
        return 1;
      }
      puVar1 = *(uint **)(this + 0x14c);
      uVar3 = uVar3 + 1;
      param_1 = extraout_s0;
      param_2 = extraout_s1;
      param_3 = extraout_s2;
    } while (uVar3 < *puVar1);
  }
  return 0;
}

// ===== PlayerFighter::initPush  @0x000f3b00  (314 bytes)
/* PlayerFighter::initPush(AbyssEngine::AEMath::Vector const&, int) */

void __thiscall PlayerFighter::initPush(PlayerFighter *this,Vector *param_1,int param_2)

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

// ===== PlayerFighter::push  @0x000f3c50  (320 bytes)
/* PlayerFighter::push(int) */

void PlayerFighter::push(int param_1)

{
  int iVar1;
  Matrix *pMVar2;
  int in_r1;
  int iVar3;
  undefined4 *puVar4;
  AEGeometry *this;
  Vector *pVVar5;
  uint in_fpscr;
  float fVar6;
  float in_s1;
  float fVar7;
  float fVar8;
  AEMath aAStack_bc [12];
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
    fVar6 = (float)VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x16) & 3);
    puVar4 = (undefined4 *)((uint)local_68 | 4);
    fVar7 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x104),(byte)(in_fpscr >> 0x16) & 3
                                      );
    local_68[0] = 0x3f800000;
    *puVar4 = 0;
    puVar4[1] = uStack_4c;
    puVar4[2] = uStack_48;
    puVar4[3] = uStack_44;
    local_54 = 0x3f800000;
    local_50 = 0;
    local_40 = 0x3f800000;
    uStack_38 = 0x3f8000003f800000;
    fVar6 = fVar6 / fVar7;
    local_30 = 0x3f800000;
    AbyssEngine::AEMath::MatrixSetRotation
              (aAStack_a4,fVar6 * *(float *)(param_1 + 0x11c),in_s1,
               fVar6 * *(float *)(param_1 + 0x118));
    iVar1 = *(int *)(param_1 + 0x1c8);
    iVar3 = *(int *)(param_1 + 0x1cc);
    if ((int)(uint)(iVar1 == 0) <= iVar3) {
      this = *(AEGeometry **)(param_1 + 8);
      pMVar2 = (Matrix *)AEGeometry::getMatrix(this);
      AbyssEngine::AEMath::operator*(aAStack_a4,pMVar2,(Matrix *)local_68);
      AEGeometry::setMatrix(this);
      iVar1 = *(int *)(param_1 + 0x1c8);
      iVar3 = *(int *)(param_1 + 0x1cc);
    }
    __aeabi_l2f(iVar1,iVar3);
    pVVar5 = *(Vector **)(param_1 + 8);
    fVar8 = (float)VectorSignedToFloat(*(float *)(param_1 + 0x104),(byte)(in_fpscr >> 0x16) & 3);
    fVar7 = (float)AbyssEngine::AEMath::operator*
                             (aAStack_bc,(Vector *)(param_1 + 0x108),*(float *)(param_1 + 0x104));
    AbyssEngine::AEMath::operator*(aAStack_b0,(Vector *)aAStack_bc,fVar7);
    AbyssEngine::AEMath::operator*
              (aAStack_a4,(Vector *)aAStack_b0,(2.0 - fVar6) * 3.0 * (fVar8 / 5000.0));
    AEGeometry::translate(pVVar5);
  }
  if (__stack_chk_guard != local_2c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerFighter::awake  @0x000f3db0  (48 bytes)
/* PlayerFighter::awake() */

void __thiscall PlayerFighter::awake(PlayerFighter *this)

{
  AEGeometry *this_00;
  
  *(undefined4 *)(this + 0x84) = 1;
  Player::setActive(*(Player **)(this + 4),true);
  setExhaustVisible(this,true);
  this[0xf1] = (PlayerFighter)0x1;
  this_00 = *(AEGeometry **)(this + 0xc);
  if (this_00 == (AEGeometry *)0x0) {
    this_00 = *(AEGeometry **)(this + 8);
  }
  AEGeometry::setVisible(this_00,true);
  return;
}

// ===== PlayerFighter::revive  @0x000f3de0  (284 bytes)
/* PlayerFighter::revive() */

void __thiscall PlayerFighter::revive(PlayerFighter *this)

{
  int iVar1;
  undefined4 uVar2;
  AEGeometry *this_00;
  Generator *this_01;
  void *pvVar3;
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  iVar1 = Player::turnedEnemy(*(Player **)(this + 4));
  Player::reset(*(Player **)(this + 4));
  if (iVar1 == 1) {
    Player::turnEnemy(*(Player **)(this + 4));
  }
  AbyssEngine::String::String(aSStack_20);
  AbyssEngine::String::operator=((String *)(this + 0x18),aSStack_20);
  AbyssEngine::String::~String(aSStack_20);
  *(undefined4 *)(this + 0x84) = 1;
  *(undefined4 *)(this + 0x74) = 0;
  this[0x12a] = (PlayerFighter)0x0;
  *(undefined4 *)(this + 0x34) = 0xffffffff;
  Route::reset(*(Route **)(this + 0x68));
  uVar2 = Player::getHitpoints(*(Player **)(this + 4));
  *(undefined4 *)(this + 0x1d0) = uVar2;
  *(undefined4 *)(this + 0x1d4) = 0;
  this[0x1d8] = (PlayerFighter)0x0;
  *(undefined4 *)(this + 0xd4) = 0;
  KIPlayer::setActive(SUB41(this,0));
  *(undefined4 *)(this + 0xec) = 0;
  *(undefined4 *)(this + 0x1e0) = *(undefined4 *)(this + 0x1a8);
  Explosion::reset(*(Explosion **)(this + 0x120));
  this[0x20] = (PlayerFighter)0x0;
  *(undefined4 *)(this + 0x100) = 0;
  setExhaustVisible(this,true);
  this[0xf1] = (PlayerFighter)0x1;
  this_00 = *(AEGeometry **)(this + 0xc);
  if (this_00 == (AEGeometry *)0x0) {
    this_00 = *(AEGeometry **)(this + 8);
  }
  AEGeometry::setVisible(this_00,true);
  if (*(int *)(this + 0x24) - 9U < 2) {
    pvVar3 = *(void **)(this + 0x4c);
    if (pvVar3 != (void *)0x0) {
      if (*(void **)((int)pvVar3 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar3 + 4));
      }
      operator_delete(pvVar3);
    }
    *(undefined4 *)(this + 0x4c) = 0;
  }
  else {
    this_01 = operator_new(1);
    Generator::Generator(this_01);
    pvVar3 = *(void **)(this + 0x4c);
    if (pvVar3 != (void *)0x0) {
      if (*(void **)((int)pvVar3 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar3 + 4));
      }
      operator_delete(pvVar3);
      *(undefined4 *)(this + 0x4c) = 0;
    }
    uVar2 = Generator::getLootList(this_01,-1,-1);
    *(undefined4 *)(this + 0x4c) = uVar2;
    pvVar3 = (void *)Generator::~Generator(this_01);
    operator_delete(pvVar3);
  }
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

