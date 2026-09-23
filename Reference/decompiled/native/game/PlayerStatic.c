// Class: PlayerStatic
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== PlayerStatic::PlayerStatic  @0x000f48dc  (138 bytes)
/* PlayerStatic::PlayerStatic(int, AEGeometry*, float, float, float) */

PlayerStatic * __thiscall
PlayerStatic::PlayerStatic
          (PlayerStatic *this,int param_1,AEGeometry *param_2,float param_3,float param_4,
          float param_5)

{
  Player *this_00;
  float in_r3;
  float extraout_s0;
  float extraout_s1;
  float extraout_s2;
  float in_stack_00000000;
  float in_stack_00000004;
  
  this_00 = operator_new(0x114);
  Player::Player(this_00,2000,0,0,0,0);
  KIPlayer::KIPlayer((KIPlayer *)this,param_1,-1,this_00,param_2,extraout_s0,extraout_s1,extraout_s2
                     ,SUB41(in_r3,0));
  *(undefined ***)this = &PTR__PlayerStatic_0026413c;
  *(int *)(this + 0x120) = (int)in_r3;
  *(int *)(this + 0x124) = (int)in_stack_00000000;
  *(int *)(this + 0x128) = (int)in_stack_00000004;
  return this;
}

// ===== PlayerStatic::~PlayerStatic  @0x000f4978  (4 bytes)
/* PlayerStatic::~PlayerStatic() */

void __thiscall PlayerStatic::~PlayerStatic(PlayerStatic *this)

{
  KIPlayer::~KIPlayer((KIPlayer *)this);
  return;
}

// ===== PlayerStatic::~PlayerStatic  @0x000f497c  (16 bytes)
/* PlayerStatic::~PlayerStatic() */

void __thiscall PlayerStatic::~PlayerStatic(PlayerStatic *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)KIPlayer::~KIPlayer((KIPlayer *)this);
  operator_delete(pvVar1);
  return;
}

// ===== PlayerStatic::update  @0x000f498c  (2 bytes)
/* PlayerStatic::update(int) */

int PlayerStatic::update(int param_1)

{
  return param_1;
}

// ===== PlayerStatic::getPosition  @0x000f498e  (54 bytes)
/* PlayerStatic::getPosition() */

void PlayerStatic::getPosition(void)

{
  undefined4 *in_r0;
  int in_r1;
  uint in_fpscr;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (*(int *)(in_r1 + 8) != 0) {
    AEGeometry::getPosition();
    return;
  }
  uVar1 = VectorSignedToFloat(*(undefined4 *)(in_r1 + 0x120),(byte)(in_fpscr >> 0x16) & 3);
  uVar2 = VectorSignedToFloat(*(undefined4 *)(in_r1 + 0x124),(byte)(in_fpscr >> 0x16) & 3);
  uVar3 = VectorSignedToFloat(*(undefined4 *)(in_r1 + 0x128),(byte)(in_fpscr >> 0x16) & 3);
  *in_r0 = uVar1;
  in_r0[1] = uVar2;
  in_r0[2] = uVar3;
  return;
}

// ===== PlayerStatic::render  @0x000f49c4  (6 bytes)
/* PlayerStatic::render() */

void PlayerStatic::render(void)

{
  int in_r0;
  
  AEGeometry::render(*(AEGeometry **)(in_r0 + 8));
  return;
}

// ===== PlayerStatic::translate  @0x000f49ca  (2 bytes)
/* PlayerStatic::translate(AbyssEngine::AEMath::Vector const&) */

Vector * PlayerStatic::translate(Vector *param_1)

{
  return param_1;
}

// ===== PlayerStatic::collide  @0x000f49cc  (4 bytes)
/* PlayerStatic::collide(float, float, float) */

undefined4 PlayerStatic::collide(float param_1,float param_2,float param_3)

{
  return 0;
}

// ===== PlayerStatic::outerCollide  @0x000f49d0  (4 bytes)
/* PlayerStatic::outerCollide(float, float, float) */

undefined4 PlayerStatic::outerCollide(float param_1,float param_2,float param_3)

{
  return 0;
}

