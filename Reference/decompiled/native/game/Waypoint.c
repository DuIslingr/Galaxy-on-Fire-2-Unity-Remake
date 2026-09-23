// Class: Waypoint
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Waypoint::Waypoint  @0x00183330  (184 bytes)
/* Waypoint::Waypoint(int, int, int, Route*) */

Waypoint * __thiscall
Waypoint::Waypoint(Waypoint *this,int param_1,int param_2,int param_3,Route *param_4)

{
  Player *this_00;
  uint in_fpscr;
  float extraout_s1;
  float extraout_s2;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  this_00 = operator_new(0x114);
  Player::Player(this_00,2000,0,0,0,0);
  uVar1 = VectorSignedToFloat(param_3,(byte)(in_fpscr >> 0x16) & 3);
  uVar2 = VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
  uVar3 = VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  KIPlayer::KIPlayer((KIPlayer *)this,0,-1,this_00,(AEGeometry *)0x0,(float)param_1,extraout_s1,
                     extraout_s2,SUB41(uVar3,0));
  *(undefined ***)this = &PTR__Waypoint_00264638;
  *(Route **)(this + 0x130) = param_4;
  Player::setActive(*(Player **)(this + 4),false);
  *(int *)(this + 0x120) = param_1;
  *(int *)(this + 0x124) = param_2;
  *(int *)(this + 0x128) = param_3;
  *(undefined4 *)(this + 0x54) = uVar3;
  *(undefined4 *)(this + 0x58) = uVar2;
  *(undefined4 *)(this + 0x5c) = uVar1;
  this[300] = (Waypoint)0x0;
  this[0x12d] = (Waypoint)0x0;
  this[0x6e] = (Waypoint)0x1;
  this[0x48] = (Waypoint)0x0;
  return this;
}

// ===== Waypoint::~Waypoint  @0x00183404  (4 bytes)
/* Waypoint::~Waypoint() */

void __thiscall Waypoint::~Waypoint(Waypoint *this)

{
  KIPlayer::~KIPlayer((KIPlayer *)this);
  return;
}

// ===== Waypoint::~Waypoint  @0x00183408  (16 bytes)
/* Waypoint::~Waypoint() */

void __thiscall Waypoint::~Waypoint(Waypoint *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)KIPlayer::~KIPlayer((KIPlayer *)this);
  operator_delete(pvVar1);
  return;
}

// ===== Waypoint::getPosition  @0x00183418  (38 bytes)
/* Waypoint::getPosition() */

void Waypoint::getPosition(void)

{
  undefined4 *in_r0;
  int in_r1;
  uint in_fpscr;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = VectorSignedToFloat(*(undefined4 *)(in_r1 + 0x120),(byte)(in_fpscr >> 0x16) & 3);
  uVar2 = VectorSignedToFloat(*(undefined4 *)(in_r1 + 0x124),(byte)(in_fpscr >> 0x16) & 3);
  uVar3 = VectorSignedToFloat(*(undefined4 *)(in_r1 + 0x128),(byte)(in_fpscr >> 0x16) & 3);
  *in_r0 = uVar1;
  in_r0[1] = uVar2;
  in_r0[2] = uVar3;
  return;
}

// ===== Waypoint::setActive  @0x0018343e  (6 bytes)
/* Waypoint::setActive(bool) */

void __thiscall Waypoint::setActive(Waypoint *this,bool param_1)

{
  Player::setActive(*(Player **)(this + 4),param_1);
  return;
}

// ===== Waypoint::reached  @0x00183444  (10 bytes)
/* Waypoint::reached() */

void __thiscall Waypoint::reached(Waypoint *this)

{
  *(undefined2 *)(this + 300) = 0x101;
  return;
}

// ===== Waypoint::reset  @0x0018344e  (16 bytes)
/* Waypoint::reset() */

void __thiscall Waypoint::reset(Waypoint *this)

{
  this[300] = (Waypoint)0x0;
  Player::setActive(*(Player **)(this + 4),false);
  return;
}

