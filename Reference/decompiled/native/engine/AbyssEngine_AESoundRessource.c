// Class: AbyssEngine::AESoundRessource
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::AESoundRessource::getSoundInfo  @0x0008a156  (66 bytes)
/* AbyssEngine::AESoundRessource::getSoundInfo(int, AbyssEngine::AESoundInfo&, int&) */

void __thiscall
AbyssEngine::AESoundRessource::getSoundInfo
          (AESoundRessource *this,int param_1,AESoundInfo *param_2,int *param_3)

{
  uint uVar1;
  int *piVar2;
  undefined8 uVar3;
  
  *param_3 = -1;
  if (*(uint *)(this + 4) == 0) {
    return;
  }
  piVar2 = *(int **)this;
  uVar1 = 0;
  do {
    if (*piVar2 == param_1) {
      *param_3 = uVar1;
      uVar3 = *(undefined8 *)piVar2;
      *(int *)(param_2 + 8) = piVar2[2];
      *(undefined8 *)param_2 = uVar3;
      return;
    }
    uVar1 = uVar1 + 1;
    piVar2 = piVar2 + 3;
  } while (uVar1 < *(uint *)(this + 4));
  return;
}

// ===== AbyssEngine::AESoundRessource::AESoundRessource  @0x0008a198  (32 bytes)
/* AbyssEngine::AESoundRessource::AESoundRessource() */

AESoundRessource * __thiscall
AbyssEngine::AESoundRessource::AESoundRessource(AESoundRessource *this)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new__(4);
  *(undefined4 **)(this + 8) = puVar1;
  *(undefined4 *)(this + 0xc) = 1;
  *puVar1 = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  return this;
}

// ===== AbyssEngine::AESoundRessource::~AESoundRessource  @0x0008a1b8  (92 bytes)
/* AbyssEngine::AESoundRessource::~AESoundRessource() */

AESoundRessource * __thiscall
AbyssEngine::AESoundRessource::~AESoundRessource(AESoundRessource *this)

{
  void *pvVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  freeAllRessources(this);
  uVar2 = *(uint *)(this + 4);
  if (uVar2 != 0) {
    uVar4 = 0;
    do {
      iVar3 = *(int *)(this + 8);
      pvVar1 = *(void **)(iVar3 + uVar4 * 4);
      if (pvVar1 != (void *)0x0) {
        operator_delete(pvVar1);
        uVar2 = *(uint *)(this + 4);
        iVar3 = *(int *)(this + 8);
      }
      *(undefined4 *)(iVar3 + uVar4 * 4) = 0;
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar2);
  }
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0xc) = 1;
  pvVar1 = realloc(*(void **)(this + 8),4);
  *(void **)(this + 8) = pvVar1;
  __aeabi_memclr4(pvVar1,*(int *)(this + 0xc) << 2);
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(this + 8) = 0;
  return this;
}

// ===== AbyssEngine::AESoundRessource::freeAllRessources  @0x0008a214  (46 bytes)
/* AbyssEngine::AESoundRessource::freeAllRessources() */

void __thiscall AbyssEngine::AESoundRessource::freeAllRessources(AESoundRessource *this)

{
  void *pvVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(this + 4);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      pvVar1 = *(void **)(*(int *)(this + 8) + uVar3 * 4);
      if (pvVar1 != (void *)0x0) {
        operator_delete(pvVar1);
        *(undefined4 *)(*(int *)(this + 8) + uVar3 * 4) = 0;
        uVar2 = *(uint *)(this + 4);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  return;
}

// ===== AbyssEngine::AESoundRessource::SetSound  @0x0008a242  (40 bytes)
/* AbyssEngine::AESoundRessource::SetSound(AbyssEngine::AESoundInfo const*, int) */

void __thiscall
AbyssEngine::AESoundRessource::SetSound(AESoundRessource *this,AESoundInfo *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  *(AESoundInfo **)this = param_1;
  *(int *)(this + 0x10) = param_2;
  ArraySetLength<AbyssEngine::AESoundInterface*>(param_2,(Array *)(this + 4));
  uVar1 = *(uint *)(this + 4);
  if (uVar1 != 0) {
    uVar2 = 0;
    do {
      *(undefined4 *)(*(int *)(this + 8) + uVar2 * 4) = 0;
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  return;
}

// ===== AbyssEngine::AESoundRessource::initWithoutLoading  @0x0008a2a0  (64 bytes)
/* AbyssEngine::AESoundRessource::initWithoutLoading(int) */

void __thiscall
AbyssEngine::AESoundRessource::initWithoutLoading(AESoundRessource *this,int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  
  if (*(uint *)(this + 4) != 0) {
    piVar2 = *(int **)this;
    uVar3 = 0;
    do {
      if (*piVar2 == param_1) {
        if (uVar3 == 0xffffffff) {
          return;
        }
        iVar4 = *(int *)(this + 8);
        if (*(int *)(iVar4 + uVar3 * 4) != 0) {
          return;
        }
        puVar1 = operator_new(4);
        *puVar1 = &PTR_loadSound_002633b8;
        *(undefined4 **)(iVar4 + uVar3 * 4) = puVar1;
        return;
      }
      uVar3 = uVar3 + 1;
      piVar2 = piVar2 + 3;
    } while (uVar3 < *(uint *)(this + 4));
  }
  return;
}

// ===== AbyssEngine::AESoundRessource::init  @0x0008a2e4  (116 bytes)
/* AbyssEngine::AESoundRessource::init(int) */

void __thiscall AbyssEngine::AESoundRessource::init(AESoundRessource *this,int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  if (*(uint *)(this + 4) != 0) {
    uVar3 = 0;
    puVar1 = (undefined4 *)(*(int *)this + 4);
    do {
      if (puVar1[-1] == param_1) {
        if (uVar3 == 0xffffffff) {
          return;
        }
        uVar6 = *puVar1;
        uVar5 = puVar1[1];
        iVar4 = *(int *)(this + 8);
        puVar1 = *(undefined4 **)(iVar4 + uVar3 * 4);
        if (puVar1 == (undefined4 *)0x0) {
          puVar1 = operator_new(4);
          *puVar1 = &PTR_loadSound_002633b8;
          *(undefined4 **)(iVar4 + uVar3 * 4) = puVar1;
          puVar1 = *(undefined4 **)(*(int *)(this + 8) + uVar3 * 4);
        }
        (**(code **)*puVar1)(puVar1,uVar6);
        piVar2 = *(int **)(*(int *)(this + 8) + uVar3 * 4);
                    /* WARNING: Could not recover jumptable at 0x0008a350. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*piVar2 + 0x24))(piVar2,uVar5);
        return;
      }
      uVar3 = uVar3 + 1;
      puVar1 = puVar1 + 3;
    } while (uVar3 < *(uint *)(this + 4));
  }
  return;
}

// ===== AbyssEngine::AESoundRessource::setVolume  @0x0008a35c  (68 bytes)
/* AbyssEngine::AESoundRessource::setVolume(int, int) */

void __thiscall
AbyssEngine::AESoundRessource::setVolume(AESoundRessource *this,int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  
  if (*(uint *)(this + 4) == 0) {
    return;
  }
  piVar1 = *(int **)this;
  uVar2 = 0;
  while (*piVar1 != param_1) {
    uVar2 = uVar2 + 1;
    piVar1 = piVar1 + 3;
    if (*(uint *)(this + 4) <= uVar2) {
      return;
    }
  }
  if (uVar2 != 0xffffffff) {
    this = *(AESoundRessource **)(*(int *)(this + 8) + uVar2 * 4);
  }
  if (uVar2 == 0xffffffff || this == (AESoundRessource *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0008a39e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0x28))(this,param_2);
  return;
}

// ===== AbyssEngine::AESoundRessource::setVolume  @0x0008a3a0  (44 bytes)
/* AbyssEngine::AESoundRessource::setVolume(int) */

void __thiscall AbyssEngine::AESoundRessource::setVolume(AESoundRessource *this,int param_1)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(this + 4);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      piVar1 = *(int **)(*(int *)(this + 8) + uVar3 * 4);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x28))(piVar1,param_1);
        uVar2 = *(uint *)(this + 4);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  return;
}

// ===== AbyssEngine::AESoundRessource::setSoundVolume  @0x0008a3cc  (44 bytes)
/* AbyssEngine::AESoundRessource::setSoundVolume(int) */

void __thiscall AbyssEngine::AESoundRessource::setSoundVolume(AESoundRessource *this,int param_1)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(this + 4);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      piVar1 = *(int **)(*(int *)(this + 8) + uVar3 * 4);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x2c))(piVar1,param_1);
        uVar2 = *(uint *)(this + 4);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  return;
}

// ===== AbyssEngine::AESoundRessource::setMusicVolume  @0x0008a3f8  (44 bytes)
/* AbyssEngine::AESoundRessource::setMusicVolume(int) */

void __thiscall AbyssEngine::AESoundRessource::setMusicVolume(AESoundRessource *this,int param_1)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(this + 4);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      piVar1 = *(int **)(*(int *)(this + 8) + uVar3 * 4);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x30))(piVar1,param_1);
        uVar2 = *(uint *)(this + 4);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  return;
}

// ===== AbyssEngine::AESoundRessource::isPlaying  @0x0008a424  (62 bytes)
/* AbyssEngine::AESoundRessource::isPlaying(int) */

undefined4 __thiscall AbyssEngine::AESoundRessource::isPlaying(AESoundRessource *this,int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  
  if (*(uint *)(this + 4) != 0) {
    piVar2 = *(int **)this;
    uVar3 = 0;
    do {
      if (*piVar2 == param_1) {
        if (uVar3 == 0xffffffff) {
          return 0;
        }
        uVar1 = (**(code **)(**(int **)(*(int *)(this + 8) + uVar3 * 4) + 0x20))();
        return uVar1;
      }
      uVar3 = uVar3 + 1;
      piVar2 = piVar2 + 3;
    } while (uVar3 < *(uint *)(this + 4));
  }
  return 0;
}

// ===== AbyssEngine::AESoundRessource::release  @0x0008a462  (62 bytes)
/* AbyssEngine::AESoundRessource::release(int) */

void __thiscall AbyssEngine::AESoundRessource::release(AESoundRessource *this,int param_1)

{
  int *piVar1;
  uint uVar2;
  
  if (*(uint *)(this + 4) == 0) {
    return;
  }
  piVar1 = *(int **)this;
  uVar2 = 0;
  do {
    if (*piVar1 == param_1) {
      if (uVar2 == 0xffffffff) {
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x0008a49c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(*(int *)(this + 8) + uVar2 * 4) + 0x34))();
      return;
    }
    uVar2 = uVar2 + 1;
    piVar1 = piVar1 + 3;
  } while (uVar2 < *(uint *)(this + 4));
  return;
}

// ===== AbyssEngine::AESoundRessource::playMusic  @0x0008a4a0  (72 bytes)
/* AbyssEngine::AESoundRessource::playMusic(int) */

void __thiscall AbyssEngine::AESoundRessource::playMusic(AESoundRessource *this,int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  piVar1 = *(int **)(this + 4);
  if (piVar1 != (int *)0x0) {
    piVar3 = *(int **)this;
    piVar4 = (int *)0x0;
    do {
      if (*piVar3 == param_1) {
        if (piVar4 != (int *)0xffffffff) {
          piVar1 = *(int **)(*(int *)(this + 8) + (int)piVar4 * 4);
        }
        if (piVar4 == (int *)0xffffffff || piVar1 == (int *)0x0) {
          return;
        }
        iVar2 = (**(code **)(*piVar1 + 0x20))();
        if (iVar2 != 0) {
          return;
        }
                    /* WARNING: Could not recover jumptable at 0x0008a4e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(**(int **)(*(int *)(this + 8) + (int)piVar4 * 4) + 8))();
        return;
      }
      piVar4 = (int *)((int)piVar4 + 1);
      piVar3 = piVar3 + 3;
    } while (piVar4 < piVar1);
  }
  return;
}

// ===== AbyssEngine::AESoundRessource::playMusicLoop  @0x0008a4e8  (72 bytes)
/* AbyssEngine::AESoundRessource::playMusicLoop(int) */

void __thiscall AbyssEngine::AESoundRessource::playMusicLoop(AESoundRessource *this,int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  piVar1 = *(int **)(this + 4);
  if (piVar1 != (int *)0x0) {
    piVar3 = *(int **)this;
    piVar4 = (int *)0x0;
    do {
      if (*piVar3 == param_1) {
        if (piVar4 != (int *)0xffffffff) {
          piVar1 = *(int **)(*(int *)(this + 8) + (int)piVar4 * 4);
        }
        if (piVar4 == (int *)0xffffffff || piVar1 == (int *)0x0) {
          return;
        }
        iVar2 = (**(code **)(*piVar1 + 0x20))();
        if (iVar2 != 0) {
          return;
        }
                    /* WARNING: Could not recover jumptable at 0x0008a52e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(**(int **)(*(int *)(this + 8) + (int)piVar4 * 4) + 0x10))();
        return;
      }
      piVar4 = (int *)((int)piVar4 + 1);
      piVar3 = piVar3 + 3;
    } while (piVar4 < piVar1);
  }
  return;
}

// ===== AbyssEngine::AESoundRessource::play  @0x0008a530  (6 bytes)
/* AbyssEngine::AESoundRessource::play(int) */

void __thiscall AbyssEngine::AESoundRessource::play(AESoundRessource *this,int param_1)

{
  float in_s0;
  
  play(this,param_1,in_s0);
  return;
}

// ===== AbyssEngine::AESoundRessource::play  @0x0008a536  (88 bytes)
/* AbyssEngine::AESoundRessource::play(int, float) */

float __thiscall
AbyssEngine::AESoundRessource::play(AESoundRessource *this,int param_1,float param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  float extraout_s0;
  float fVar4;
  
  if (*(uint *)(this + 4) != 0) {
    piVar2 = *(int **)this;
    uVar3 = 0;
    do {
      if (*piVar2 == param_1) {
        if (uVar3 == 0xffffffff) {
          return param_2;
        }
        iVar1 = (**(code **)(**(int **)(*(int *)(this + 8) + uVar3 * 4) + 0x38))();
        fVar4 = extraout_s0;
        if (iVar1 == 0) {
          fVar4 = (float)init(this,param_1);
        }
        piVar2 = *(int **)(*(int *)(this + 8) + uVar3 * 4);
        if (piVar2 == (int *)0x0) {
          return fVar4;
        }
                    /* WARNING: Could not recover jumptable at 0x0008a588. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        fVar4 = (float)(**(code **)(*piVar2 + 0xc))();
        return fVar4;
      }
      uVar3 = uVar3 + 1;
      piVar2 = piVar2 + 3;
    } while (uVar3 < *(uint *)(this + 4));
  }
  return param_2;
}

// ===== AbyssEngine::AESoundRessource::playLoop  @0x0008a58e  (72 bytes)
/* AbyssEngine::AESoundRessource::playLoop(int) */

void __thiscall AbyssEngine::AESoundRessource::playLoop(AESoundRessource *this,int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  piVar1 = *(int **)(this + 4);
  if (piVar1 != (int *)0x0) {
    piVar3 = *(int **)this;
    piVar4 = (int *)0x0;
    do {
      if (*piVar3 == param_1) {
        if (piVar4 != (int *)0xffffffff) {
          piVar1 = *(int **)(*(int *)(this + 8) + (int)piVar4 * 4);
        }
        if (piVar4 == (int *)0xffffffff || piVar1 == (int *)0x0) {
          return;
        }
        iVar2 = (**(code **)(*piVar1 + 0x20))();
        if (iVar2 != 0) {
          return;
        }
                    /* WARNING: Could not recover jumptable at 0x0008a5d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(**(int **)(*(int *)(this + 8) + (int)piVar4 * 4) + 0x10))();
        return;
      }
      piVar4 = (int *)((int)piVar4 + 1);
      piVar3 = piVar3 + 3;
    } while (piVar4 < piVar1);
  }
  return;
}

// ===== AbyssEngine::AESoundRessource::stop  @0x0008a5d6  (66 bytes)
/* AbyssEngine::AESoundRessource::stop(int) */

void __thiscall AbyssEngine::AESoundRessource::stop(AESoundRessource *this,int param_1)

{
  int *piVar1;
  uint uVar2;
  
  if (*(uint *)(this + 4) == 0) {
    return;
  }
  piVar1 = *(int **)this;
  uVar2 = 0;
  while (*piVar1 != param_1) {
    uVar2 = uVar2 + 1;
    piVar1 = piVar1 + 3;
    if (*(uint *)(this + 4) <= uVar2) {
      return;
    }
  }
  if (uVar2 != 0xffffffff) {
    this = *(AESoundRessource **)(*(int *)(this + 8) + uVar2 * 4);
  }
  if (uVar2 == 0xffffffff || this == (AESoundRessource *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0008a616. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0x1c))();
  return;
}

// ===== AbyssEngine::AESoundRessource::stop  @0x0008a618  (36 bytes)
/* AbyssEngine::AESoundRessource::stop() */

void __thiscall AbyssEngine::AESoundRessource::stop(AESoundRessource *this)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(this + 4);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      piVar1 = *(int **)(*(int *)(this + 8) + uVar3 * 4);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x1c))();
        uVar2 = *(uint *)(this + 4);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  return;
}

// ===== AbyssEngine::AESoundRessource::checkLooping  @0x0008a63c  (2 bytes)
/* AbyssEngine::AESoundRessource::checkLooping() */

void AbyssEngine::AESoundRessource::checkLooping(void)

{
  return;
}

// ===== AbyssEngine::AESoundRessource::supend  @0x0008a63e  (36 bytes)
/* AbyssEngine::AESoundRessource::supend() */

void __thiscall AbyssEngine::AESoundRessource::supend(AESoundRessource *this)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(this + 4);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      piVar1 = *(int **)(*(int *)(this + 8) + uVar3 * 4);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))();
        uVar2 = *(uint *)(this + 4);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  return;
}

// ===== AbyssEngine::AESoundRessource::pause  @0x0008a662  (66 bytes)
/* AbyssEngine::AESoundRessource::pause(int) */

void __thiscall AbyssEngine::AESoundRessource::pause(AESoundRessource *this,int param_1)

{
  int *piVar1;
  uint uVar2;
  
  if (*(uint *)(this + 4) == 0) {
    return;
  }
  piVar1 = *(int **)this;
  uVar2 = 0;
  while (*piVar1 != param_1) {
    uVar2 = uVar2 + 1;
    piVar1 = piVar1 + 3;
    if (*(uint *)(this + 4) <= uVar2) {
      return;
    }
  }
  if (uVar2 != 0xffffffff) {
    this = *(AESoundRessource **)(*(int *)(this + 8) + uVar2 * 4);
  }
  if (uVar2 == 0xffffffff || this == (AESoundRessource *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0008a6a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0x14))();
  return;
}

// ===== AbyssEngine::AESoundRessource::pause  @0x0008a6a4  (36 bytes)
/* AbyssEngine::AESoundRessource::pause() */

void __thiscall AbyssEngine::AESoundRessource::pause(AESoundRessource *this)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(this + 4);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      piVar1 = *(int **)(*(int *)(this + 8) + uVar3 * 4);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x14))();
        uVar2 = *(uint *)(this + 4);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  return;
}

// ===== AbyssEngine::AESoundRessource::resume  @0x0008a6c8  (66 bytes)
/* AbyssEngine::AESoundRessource::resume(int) */

void __thiscall AbyssEngine::AESoundRessource::resume(AESoundRessource *this,int param_1)

{
  int *piVar1;
  uint uVar2;
  
  if (*(uint *)(this + 4) == 0) {
    return;
  }
  piVar1 = *(int **)this;
  uVar2 = 0;
  while (*piVar1 != param_1) {
    uVar2 = uVar2 + 1;
    piVar1 = piVar1 + 3;
    if (*(uint *)(this + 4) <= uVar2) {
      return;
    }
  }
  if (uVar2 != 0xffffffff) {
    this = *(AESoundRessource **)(*(int *)(this + 8) + uVar2 * 4);
  }
  if (uVar2 == 0xffffffff || this == (AESoundRessource *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0008a708. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0x18))();
  return;
}

// ===== AbyssEngine::AESoundRessource::resume  @0x0008a70a  (36 bytes)
/* AbyssEngine::AESoundRessource::resume() */

void __thiscall AbyssEngine::AESoundRessource::resume(AESoundRessource *this)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(this + 4);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      piVar1 = *(int **)(*(int *)(this + 8) + uVar3 * 4);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x18))();
        uVar2 = *(uint *)(this + 4);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  return;
}

