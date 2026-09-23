// Class: SentryGun
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== SentryGun::SentryGun  @0x001888f0  (56 bytes)
/* SentryGun::SentryGun(Gun*, int, int, int, Level*) */

void __thiscall
SentryGun::SentryGun
          (SentryGun *this,Gun *param_1,int param_2,int param_3,int param_4,Level *param_5)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)ObjectGun::ObjectGun((ObjectGun *)this,param_3,param_1,param_2,0,param_5);
  *puVar1 = &PTR__SentryGun_002646ac;
  puVar1[0x2c] = *(int *)(param_1 + 0x58) * 3 + -0x279;
  return;
}

// ===== SentryGun::~SentryGun  @0x0018892c  (4 bytes)
/* SentryGun::~SentryGun() */

void __thiscall SentryGun::~SentryGun(SentryGun *this)

{
  ObjectGun::~ObjectGun((ObjectGun *)this);
  return;
}

// ===== SentryGun::~SentryGun  @0x00188930  (16 bytes)
/* SentryGun::~SentryGun() */

void __thiscall SentryGun::~SentryGun(SentryGun *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)ObjectGun::~ObjectGun((ObjectGun *)this);
  operator_delete(pvVar1);
  return;
}

// ===== SentryGun::render  @0x00188940  (2 bytes)
/* SentryGun::render() */

void SentryGun::render(void)

{
  return;
}

// ===== SentryGun::update  @0x00188942  (146 bytes)
/* SentryGun::update(int) */

void __thiscall SentryGun::update(SentryGun *this,int param_1)

{
  bool bVar1;
  int iVar2;
  KIPlayer *this_00;
  int iVar3;
  
  Gun::update(*(Gun **)(this + 8),param_1);
  if (*(char *)(*(int *)(this + 8) + 0x4d) != '\0') {
    *(undefined1 *)(*(int *)(this + 8) + 0x4d) = 0;
    iVar3 = *(int *)(this + 0xb0);
    do {
      this_00 = *(KIPlayer **)(*(int *)(*(int *)(*(int *)(this + 0xc) + 0xb0) + 4) + iVar3 * 4);
      iVar2 = KIPlayer::isDying(this_00);
      if ((iVar2 == 0) &&
         ((iVar2 = Player::isActive(*(Player **)(this_00 + 4)), iVar2 != 1 ||
          (iVar2 = Player::isDead(*(Player **)(this_00 + 4)), iVar2 == 1)))) {
        *(int *)(*(int *)(this + 0xc) + 0x6c) = *(int *)(*(int *)(this + 0xc) + 0x6c) + 1;
        (**(code **)(*(int *)this_00 + 0x18))(this_00);
        (**(code **)(*(int *)this_00 + 0x44))
                  (this_00,*(int *)(*(int *)(this + 8) + 0xc) +
                           *(int *)(*(int *)(this + 8) + 0xa0) * 0xc);
        KIPlayer::setActive(SUB41(this_00,0));
        return;
      }
      bVar1 = iVar3 < *(int *)(this + 0xb0) + 2;
      iVar3 = iVar3 + 1;
    } while (bVar1);
  }
  return;
}

