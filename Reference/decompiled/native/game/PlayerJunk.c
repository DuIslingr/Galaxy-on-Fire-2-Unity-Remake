// Class: PlayerJunk
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== PlayerJunk::PlayerJunk  @0x0018af3c  (68 bytes)
/* PlayerJunk::PlayerJunk(int, Player*, AEGeometry*, float, float, float) */

void __thiscall
PlayerJunk::PlayerJunk
          (PlayerJunk *this,int param_1,Player *param_2,AEGeometry *param_3,float param_4,
          float param_5,float param_6)

{
  undefined4 *puVar1;
  float in_stack_00000000;
  float in_stack_00000004;
  
  puVar1 = (undefined4 *)
           KIPlayer::KIPlayer((KIPlayer *)this,param_1,-1,param_2,param_3,in_stack_00000000,param_5,
                              in_stack_00000004,SUB41(in_stack_00000000,0));
  *puVar1 = &PTR__PlayerJunk_002646f0;
  *(undefined1 *)((int)puVar1 + 0x39) = 1;
  return;
}

// ===== PlayerJunk::~PlayerJunk  @0x0018af84  (4 bytes)
/* PlayerJunk::~PlayerJunk() */

void __thiscall PlayerJunk::~PlayerJunk(PlayerJunk *this)

{
  KIPlayer::~KIPlayer((KIPlayer *)this);
  return;
}

// ===== PlayerJunk::~PlayerJunk  @0x0018af88  (16 bytes)
/* PlayerJunk::~PlayerJunk() */

void __thiscall PlayerJunk::~PlayerJunk(PlayerJunk *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)KIPlayer::~KIPlayer((KIPlayer *)this);
  operator_delete(pvVar1);
  return;
}

// ===== PlayerJunk::reset  @0x0018af98  (30 bytes)
/* PlayerJunk::reset() */

void __thiscall PlayerJunk::reset(PlayerJunk *this)

{
  KIPlayer::reset((KIPlayer *)this);
  *(undefined4 *)(this + 0x84) = 0;
  KIPlayer::setActive(SUB41(this,0));
  return;
}

// ===== PlayerJunk::update  @0x0018afb4  (332 bytes)
/* PlayerJunk::update(int) */

void __thiscall PlayerJunk::update(PlayerJunk *this,int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *__ptr;
  void *pvVar3;
  float fVar4;
  float extraout_s0;
  float extraout_s0_00;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  *(int *)(this + 0x120) = param_1;
  iVar1 = Player::getHitpoints(*(Player **)(this + 4));
  if ((iVar1 < 1) && (1 < *(int *)(this + 0x84) - 3U)) {
    fVar4 = (float)Level::junkDied(*(Level **)(this + 0x50));
    *(undefined4 *)(this + 0x84) = 3;
    FModSound::play(Globals::sound,0x16,(Vector *)0x0,(Vector *)0x0,fVar4);
    iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
    if (iVar1 < 10) {
      this[0x48] = (PlayerJunk)0x1;
      piVar2 = operator_new(0xc);
      __ptr = operator_new__(4);
      piVar2[1] = (int)__ptr;
      *__ptr = 0;
      *piVar2 = 0;
      *(int **)(this + 0x4c) = piVar2;
      piVar2[2] = 1;
      pvVar3 = realloc(__ptr,4);
      piVar2[1] = (int)pvVar3;
      *(undefined4 *)((int)pvVar3 + *piVar2 * 4) = 99;
      *piVar2 = piVar2[2];
      iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,10);
      piVar2 = *(int **)(this + 0x4c);
      piVar2[2] = *piVar2 + 1;
      pvVar3 = realloc((void *)piVar2[1],(*piVar2 + 1) * 4);
      piVar2[1] = (int)pvVar3;
      *(int *)((int)pvVar3 + *piVar2 * 4) = iVar1 + 1;
      *piVar2 = piVar2[2];
      fVar4 = (float)KIPlayer::createCrate((KIPlayer *)this,3);
      this[0x48] = (PlayerJunk)0x1;
    }
    else {
      Player::setActive(*(Player **)(this + 4),false);
      iVar1 = Level::getPlayer(*(Level **)(this + 0x50));
      fVar4 = extraout_s0;
      if (*(PlayerJunk **)(*(int *)(iVar1 + 0x14) + 0x1c) == this) {
        iVar1 = Level::getPlayer(*(Level **)(this + 0x50));
        *(undefined4 *)(*(int *)(iVar1 + 0x14) + 0x1c) = 0;
        fVar4 = extraout_s0_00;
      }
    }
    local_28 = *(undefined4 *)(this + 0x54);
    uStack_24 = *(undefined4 *)(this + 0x58);
    uStack_20 = *(undefined4 *)(this + 0x5c);
    local_34 = 0;
    uStack_30 = 0;
    local_2c = 0;
    ParticleSystemManager::emitManual
              (*(ParticleSystemManager **)(*(int *)(this + 0x50) + 0x74),
               *(int *)(*(int *)(this + 0x50) + 0x34),(Vector *)&local_28,0,(Vector *)&local_34,
               fVar4);
  }
  if (*(int *)(this + 0x84) == 3) {
    *(undefined4 *)(this + 0x84) = 4;
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerJunk::render  @0x0018b124  (38 bytes)
/* PlayerJunk::render() */

void __thiscall PlayerJunk::render(PlayerJunk *this)

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

// ===== PlayerJunk::collide  @0x0018b148  (4 bytes)
/* PlayerJunk::collide(float, float, float) */

undefined4 PlayerJunk::collide(float param_1,float param_2,float param_3)

{
  return 0;
}

// ===== PlayerJunk::outerCollide  @0x0018b14c  (4 bytes)
/* PlayerJunk::outerCollide(float, float, float) */

undefined4 PlayerJunk::outerCollide(float param_1,float param_2,float param_3)

{
  return 0;
}

