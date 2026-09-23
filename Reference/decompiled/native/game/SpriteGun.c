// Class: SpriteGun
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== SpriteGun::SpriteGun  @0x00197854  (18 bytes)
/* SpriteGun::SpriteGun(Gun*, int) */

void __thiscall SpriteGun::SpriteGun(SpriteGun *this,Gun *param_1,int param_2)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined ***)this = &PTR__SpriteGun_002648f0;
  return;
}

// ===== SpriteGun::~SpriteGun  @0x0019786c  (2 bytes)
/* SpriteGun::~SpriteGun() */

SpriteGun * __thiscall SpriteGun::~SpriteGun(SpriteGun *this)

{
  return this;
}

// ===== SpriteGun::~SpriteGun  @0x0019786e  (4 bytes)
/* SpriteGun::~SpriteGun() */

void __thiscall SpriteGun::~SpriteGun(SpriteGun *this)

{
  operator_delete(this);
  return;
}

// ===== SpriteGun::render  @0x00197872  (2 bytes)
/* SpriteGun::render() */

void SpriteGun::render(void)

{
  return;
}

// ===== SpriteGun::update  @0x00197874  (8 bytes)
/* SpriteGun::update(int) */

void SpriteGun::update(int param_1)

{
  int in_r1;
  
  Gun::update(*(Gun **)(param_1 + 8),in_r1);
  return;
}

// ===== SpriteGun::setEnemies  @0x0019787a  (6 bytes)
/* SpriteGun::setEnemies(Array<Player*>*) */

void SpriteGun::setEnemies(Array *param_1)

{
  Array *in_r1;
  
  Gun::setEnemies(*(Gun **)(param_1 + 8),in_r1);
  return;
}

// ===== SpriteGun::setEnemy  @0x00197880  (6 bytes)
/* SpriteGun::setEnemy(Player*) */

void SpriteGun::setEnemy(Player *param_1)

{
  Player *in_r1;
  
  Gun::setEnemy(*(Gun **)(param_1 + 8),in_r1);
  return;
}

