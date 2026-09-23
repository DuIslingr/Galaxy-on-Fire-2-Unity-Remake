// Class: FModSound
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== FModSound::FModSound  @0x0009d6fa  (84 bytes)
/* FModSound::FModSound() */

FModSound * __thiscall FModSound::FModSound(FModSound *this)

{
  undefined4 uVar1;
  
  *(undefined4 *)(this + 0x23fc) = 0;
  *(undefined4 *)(this + 0x2400) = 0;
  *(undefined4 *)(this + 0x2404) = 0;
  uVar1 = AEFile::GetAppRootDir();
  *(undefined4 *)(this + 0xc) = uVar1;
  this[0x14] = (FModSound)0x1;
  *(undefined4 *)(this + 0x10) = 0x1010101;
  __aeabi_memclr4(this + 0x18,0x23d4);
  *(undefined4 *)(this + 0x2438) = 0;
  *(undefined4 *)(this + 0x2434) = 0;
  *(undefined4 *)(this + 0x2424) = 0;
  *(undefined4 *)(this + 0x2428) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x242c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x2430) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  return this;
}

// ===== FModSound::~FModSound  @0x0009d74e  (14 bytes)
/* FModSound::~FModSound() */

FModSound * __thiscall FModSound::~FModSound(FModSound *this)

{
  release(this);
  return this;
}

// ===== FModSound::release  @0x0009d760  (44 bytes)
/* FModSound::release() */

void __thiscall FModSound::release(FModSound *this)

{
  if (*(int *)(this + 0x23fc) != 0) {
    FMOD::EventSystem::unload();
    FMOD::EventSystem::release();
    *(undefined4 *)(this + 0x23fc) = 0;
  }
  __aeabi_memclr4(this + 0x18,0x23e4);
  return;
}

// ===== FModSound::init  @0x0009d78c  (318 bytes)
/* FModSound::init() */

void __thiscall FModSound::init(FModSound *this)

{
  FModSound FVar1;
  size_t sVar2;
  FMOD_EVENT_LOADINFO *pFVar3;
  int iVar4;
  FModSound *pFVar5;
  FMOD_EVENT_LOADINFO aFStack_428 [6];
  char acStack_422 [11];
  char acStack_417 [1011];
  int iStack_24;
  
  iStack_24 = __stack_chk_guard;
  __aeabi_memset4(this + 0x2410,0x14,0xff);
  pFVar5 = this + 0x23fc;
  FMOD_EventSystem_Create(pFVar5);
  FMOD::EventSystem::init(*(int *)(this + 0x23fc),0x20,(void *)0x82,0);
  GameText::getLanguage();
  if (*(char **)(this + 0x23fc) != (char *)0x0) {
    FMOD::EventSystem::setLanguage(*(char **)(this + 0x23fc));
  }
  __aeabi_memclr8(aFStack_428,0x400);
  strcpy((char *)aFStack_428,*(char **)(this + 0xc));
  FVar1 = this[0x10];
  sVar2 = strlen((char *)aFStack_428);
  pFVar3 = aFStack_428 + sVar2;
  if (FVar1 == (FModSound)0x0) {
    *(undefined8 *)pFVar3 = 0x6475612f61746164;
    builtin_strncpy(acStack_422 + sVar2 + 2,"io/FMOD_G",9);
    builtin_strncpy(acStack_417 + sVar2,"OF2.fev",8);
  }
  else {
    *(undefined8 *)pFVar3 = 0x464f475f444f4d46;
    builtin_strncpy(acStack_422 + sVar2,"OF2.fev",8);
  }
  FMOD::EventSystem::load(*(char **)pFVar5,aFStack_428,(EventProject **)0x0);
  iVar4 = 0;
  do {
    *(undefined4 *)(this + iVar4 + 0x23ec) = 0;
    FMOD::EventSystem::getCategory
              (*(char **)pFVar5,*(EventCategory ***)((int)&DAT_00263d6c + iVar4));
    iVar4 = iVar4 + 4;
  } while (iVar4 != 0x10);
  FMOD::EventSystem::getProjectByIndex(*(int *)pFVar5,(EventProject **)0x0);
  *(undefined4 *)this = 0xffffffff;
  *(undefined4 *)(this + 4) = 0xffffffff;
  *(undefined4 *)(this + 0x240c) = 0;
  this[8] = (FModSound)0x0;
  *(undefined4 *)(this + 0x2408) = 0xffffffff;
  if (__stack_chk_guard != iStack_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== FModSound::ERRCHECK  @0x0009d8e4  (2 bytes)
/* FModSound::ERRCHECK(FMOD_RESULT) */

void FModSound::ERRCHECK(void)

{
  return;
}

// ===== FModSound::setAudioLanguage  @0x0009d8e8  (30 bytes)
/* FModSound::setAudioLanguage(int) */

void FModSound::setAudioLanguage(int param_1)

{
  if (*(char **)(param_1 + 0x23fc) == (char *)0x0) {
    return;
  }
  FMOD::EventSystem::setLanguage(*(char **)(param_1 + 0x23fc));
  return;
}

// ===== FModSound::isHeadsetPluggedIn  @0x0009d908  (4 bytes)
/* FModSound::isHeadsetPluggedIn() */

undefined4 FModSound::isHeadsetPluggedIn(void)

{
  return 0;
}

// ===== FModSound::tryToStopMusicForBGMusic  @0x0009d90c  (4 bytes)
/* FModSound::tryToStopMusicForBGMusic() */

undefined4 FModSound::tryToStopMusicForBGMusic(void)

{
  return 0;
}

// ===== FModSound::stopAllSoundFXEvents  @0x0009d910  (52 bytes)
/* FModSound::stopAllSoundFXEvents() */

void __thiscall FModSound::stopAllSoundFXEvents(FModSound *this)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(this + 0x23fc) != 0) {
    iVar1 = 1;
    do {
      do {
        iVar2 = iVar1;
        iVar1 = 2;
      } while (iVar2 == 1);
      (**(code **)(**(int **)(this + iVar2 * 4 + 0x23ec) + 0x1c))();
      iVar1 = iVar2 + 1;
    } while (iVar2 + 1 != 4);
  }
  return;
}

// ===== FModSound::freeAllEvents  @0x0009d944  (244 bytes)
/* WARNING: Removing unreachable block (ram,0x0009d978) */
/* WARNING: Removing unreachable block (ram,0x0009d986) */
/* WARNING: Removing unreachable block (ram,0x0009d98a) */
/* WARNING: Removing unreachable block (ram,0x0009d992) */
/* WARNING: Removing unreachable block (ram,0x0009d9a4) */
/* WARNING: Removing unreachable block (ram,0x0009d9b4) */
/* FModSound::freeAllEvents() */

void __thiscall FModSound::freeAllEvents(FModSound *this)

{
  int iVar1;
  
  iVar1 = __stack_chk_guard;
  if (*(char **)(this + 0x23fc) == (char *)0x0) {
    if (*(void **)(this + 0x2424) != (void *)0x0) {
      operator_delete(*(void **)(this + 0x2424));
    }
    *(undefined4 *)(this + 0x2424) = 0;
    if (*(void **)(this + 0x2428) != (void *)0x0) {
      operator_delete(*(void **)(this + 0x2428));
    }
    *(undefined4 *)(this + 0x2428) = 0;
    if (*(void **)(this + 0x242c) != (void *)0x0) {
      operator_delete(*(void **)(this + 0x242c));
    }
    *(undefined4 *)(this + 0x242c) = 0;
    if (*(void **)(this + 0x2430) != (void *)0x0) {
      operator_delete(*(void **)(this + 0x2430));
    }
    *(undefined4 *)(this + 0x2430) = 0;
    if (*(void **)(this + 0x2434) != (void *)0x0) {
      operator_delete(*(void **)(this + 0x2434));
    }
    *(undefined4 *)(this + 0x2434) = 0;
    if (*(void **)(this + 0x2438) != (void *)0x0) {
      operator_delete(*(void **)(this + 0x2438));
    }
    *(undefined4 *)(this + 0x2438) = 0;
  }
  else {
    FMOD::EventSystem::getProject(*(char **)(this + 0x23fc),(EventProject **)"FMOD_GOF2");
  }
  if (__stack_chk_guard == iVar1) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== FModSound::getParam  @0x0009da44  (68 bytes)
/* FModSound::getParam(char const*, int) */

void __thiscall FModSound::getParam(FModSound *this,char *param_1,int param_2)

{
  int iVar1;
  FModSound *pFVar2;
  char *pcVar3;
  FModSound *local_10;
  
  iVar1 = __stack_chk_guard;
  pFVar2 = (FModSound *)0x0;
  if (*(int *)(this + 0x23fc) != 0) {
    pcVar3 = *(char **)(this + param_2 * 4 + 0x18);
    pFVar2 = this + param_2 * 4;
    if (pcVar3 != (char *)0x0) {
      FMOD::Event::getParameter(pcVar3,(EventParameter **)param_1);
      pFVar2 = local_10;
    }
  }
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(pFVar2);
  }
  return;
}

// ===== FModSound::setParamValue  @0x0009da90  (74 bytes)
/* FModSound::setParamValue(int, int, float) */

void FModSound::setParamValue(int param_1,int param_2,float param_3)

{
  int iVar1;
  int iVar2;
  int in_r2;
  float fVar3;
  
  iVar1 = __stack_chk_guard;
  if (((-1 < in_r2) && (*(int *)(param_1 + 0x23fc) != 0)) &&
     (iVar2 = *(int *)(param_1 + in_r2 * 4 + 0x18), iVar2 != 0)) {
    fVar3 = (float)FMOD::Event::getParameterByIndex(iVar2,(EventParameter **)param_2);
    param_3 = (float)FMOD::EventParameter::setValue(fVar3);
  }
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_3);
  }
  return;
}

// ===== FModSound::setParamValue  @0x0009dae4  (74 bytes)
/* FModSound::setParamValue(char const*, int, float) */

void FModSound::setParamValue(char *param_1,int param_2,float param_3)

{
  int iVar1;
  int in_r2;
  float fVar2;
  
  iVar1 = __stack_chk_guard;
  if (((-1 < in_r2) && (*(int *)(param_1 + 0x23fc) != 0)) &&
     (*(char **)(param_1 + in_r2 * 4 + 0x18) != (char *)0x0)) {
    fVar2 = (float)FMOD::Event::getParameter
                             (*(char **)(param_1 + in_r2 * 4 + 0x18),(EventParameter **)param_2);
    param_3 = (float)FMOD::EventParameter::setValue(fVar2);
  }
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_3);
  }
  return;
}

// ===== FModSound::setMusicParamValue  @0x0009db38  (16 bytes)
/* FModSound::setMusicParamValue(int, float) */

void FModSound::setMusicParamValue(int param_1,float param_2)

{
  if (*(int **)(param_1 + 0x2400) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0009db44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x2400) + 0x34))();
    return;
  }
  return;
}

// ===== FModSound::setVolume  @0x0009db48  (30 bytes)
/* FModSound::setVolume(int, float) */

void __thiscall FModSound::setVolume(FModSound *this,int param_1,float param_2)

{
  if ((*(int *)(this + 0x23fc) != 0) && (*(int **)(this + param_1 * 4 + 0x23ec) != (int *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0009db62. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(this + param_1 * 4 + 0x23ec) + 0x20))();
    return;
  }
  return;
}

// ===== FModSound::setSoundVolume  @0x0009db66  (26 bytes)
/* FModSound::setSoundVolume(int, float) */

void __thiscall FModSound::setSoundVolume(FModSound *this,int param_1,float param_2)

{
  if ((*(int *)(this + 0x23fc) != 0) && (*(int *)(this + param_1 * 4 + 0x18) != 0)) {
    FMOD::Event::setVolume(param_2);
    return;
  }
  return;
}

// ===== FModSound::updateAll  @0x0009db80  (488 bytes)
/* FModSound::updateAll(AbyssEngine::AEMath::Vector*, AbyssEngine::AEMath::Vector*,
   AbyssEngine::AEMath::Vector*, AbyssEngine::AEMath::Vector*) */

void __thiscall
FModSound::updateAll
          (FModSound *this,Vector *param_1,Vector *param_2,Vector *param_3,Vector *param_4)

{
  int iVar1;
  bool bVar2;
  undefined4 *puVar3;
  FMOD_VECTOR *pFVar4;
  int iVar5;
  uint uVar6;
  FMOD_VECTOR *pFVar7;
  FMOD_VECTOR *pFVar8;
  FModSound *pFVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int *local_2c;
  
  iVar1 = __stack_chk_guard;
  iVar12 = *(int *)(this + 0x23fc);
  if (iVar12 == 0) goto LAB_0009dd50;
  if (param_1 == (Vector *)0x0) {
    uVar6 = 0;
  }
  else {
    puVar3 = *(undefined4 **)(this + 0x2424);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = operator_new(0xc);
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      *(undefined4 **)(this + 0x2424) = puVar3;
    }
    uVar6 = 1;
    *puVar3 = *(undefined4 *)param_1;
    puVar3[1] = *(undefined4 *)(param_1 + 4);
    puVar3[2] = *(undefined4 *)(param_1 + 8);
  }
  if (param_2 == (Vector *)0x0) {
    pFVar9 = (FModSound *)0x0;
  }
  else {
    puVar3 = *(undefined4 **)(this + 0x2428);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = operator_new(0xc);
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      *(undefined4 **)(this + 0x2428) = puVar3;
    }
    pFVar9 = (FModSound *)0x1;
    *puVar3 = *(undefined4 *)param_2;
    puVar3[1] = *(undefined4 *)(param_2 + 4);
    puVar3[2] = *(undefined4 *)(param_2 + 8);
  }
  if (param_3 == (Vector *)0x0) {
    uVar11 = 0;
  }
  else {
    puVar3 = *(undefined4 **)(this + 0x242c);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = operator_new(0xc);
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      *(undefined4 **)(this + 0x242c) = puVar3;
    }
    uVar11 = 1;
    *puVar3 = *(undefined4 *)param_3;
    puVar3[1] = *(undefined4 *)(param_3 + 4);
    puVar3[2] = *(undefined4 *)(param_3 + 8);
  }
  if (param_4 == (Vector *)0x0) {
    if ((uVar6 | (uint)pFVar9 | uVar11) == 1) {
      bVar2 = false;
      goto LAB_0009dca2;
    }
  }
  else {
    puVar3 = *(undefined4 **)(this + 0x2430);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = operator_new(0xc);
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      *(undefined4 **)(this + 0x2430) = puVar3;
    }
    *puVar3 = *(undefined4 *)param_4;
    puVar3[1] = *(undefined4 *)(param_4 + 4);
    puVar3[2] = *(undefined4 *)(param_4 + 8);
    bVar2 = true;
LAB_0009dca2:
    if (uVar6 == 1) {
      pFVar7 = *(FMOD_VECTOR **)(this + 0x2424);
    }
    else {
      pFVar7 = (FMOD_VECTOR *)0x0;
    }
    if (bVar2) {
      pFVar8 = *(FMOD_VECTOR **)(this + 0x2430);
    }
    else {
      pFVar8 = (FMOD_VECTOR *)0x0;
    }
    if (pFVar9 == (FModSound *)0x1) {
      pFVar4 = *(FMOD_VECTOR **)(this + 0x2428);
    }
    else {
      pFVar4 = (FMOD_VECTOR *)0x0;
    }
    FMOD::EventSystem::set3DListenerAttributes(iVar12,(FMOD_VECTOR *)0x0,pFVar7,pFVar8,pFVar4);
  }
  FMOD::EventSystem::update();
  iVar12 = 0x2410;
  iVar10 = 0;
  do {
    iVar5 = *(int *)(this + iVar10 * 4 + 0x2410);
    if (iVar5 != -1) {
      pFVar9 = this + iVar5 * 4 + 0x18;
      iVar12 = *(int *)pFVar9;
    }
    if (((iVar5 != -1 && iVar12 != 0) && (iVar12 = isPlaying(this,iVar5), iVar12 == 0)) &&
       (iVar12 = FMOD::Event::getParentGroup(*(EventGroup ***)pFVar9), iVar12 == 0)) {
      iVar12 = (**(code **)(*local_2c + 8))(local_2c,*(int *)pFVar9,0);
      *(int *)pFVar9 = 0;
      *(undefined4 *)(this + iVar10 * 4 + 0x2410) = 0xffffffff;
    }
    iVar10 = iVar10 + 1;
  } while (iVar10 != 5);
LAB_0009dd50:
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== FModSound::isPlaying  @0x0009dd70  (70 bytes)
/* FModSound::isPlaying(int) */

void __thiscall FModSound::isPlaying(FModSound *this,int param_1)

{
  int iVar1;
  uint uVar2;
  uint local_10;
  
  iVar1 = __stack_chk_guard;
  if ((*(int *)(this + 0x23fc) == 0) || (*(uint **)(this + param_1 * 4 + 0x18) == (uint *)0x0)) {
    uVar2 = 0;
  }
  else {
    FMOD::Event::getState(*(uint **)(this + param_1 * 4 + 0x18));
    uVar2 = (local_10 & 0xf) >> 3;
  }
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}

// ===== FModSound::isChannelActive  @0x0009ddc0  (70 bytes)
/* FModSound::isChannelActive(int) */

void __thiscall FModSound::isChannelActive(FModSound *this,int param_1)

{
  int iVar1;
  uint uVar2;
  uint local_10;
  
  iVar1 = __stack_chk_guard;
  if ((*(int *)(this + 0x23fc) == 0) || (*(uint **)(this + param_1 * 4 + 0x18) == (uint *)0x0)) {
    uVar2 = 0;
  }
  else {
    FMOD::Event::getState(*(uint **)(this + param_1 * 4 + 0x18));
    uVar2 = (local_10 & 0x1f) >> 4;
  }
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}

// ===== FModSound::IsCategoryEnabled  @0x0009de10  (28 bytes)
/* FModSound::IsCategoryEnabled(int) */

undefined1 __thiscall FModSound::IsCategoryEnabled(FModSound *this,int param_1)

{
  undefined1 uVar1;
  
  uVar1 = 0;
  if (((param_1 < 4) && (*(int *)(this + 0x23fc) != 0)) &&
     (uVar1 = 0, this[param_1 + 0x11] != (FModSound)0x0)) {
    uVar1 = 1;
  }
  return uVar1;
}

// ===== FModSound::enableCategory  @0x0009de2c  (122 bytes)
/* FModSound::enableCategory(int, bool) */

void FModSound::enableCategory(int param_1,bool param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  int in_r2;
  bool bVar5;
  float in_s0;
  
  uVar3 = (uint)param_2;
  if (((uVar3 < 4) && (*(int *)(param_1 + 0x23fc) != 0)) &&
     (iVar1 = param_1 + uVar3 * 4, *(int *)(iVar1 + 0x23ec) != 0)) {
    *(char *)(param_1 + uVar3 + 0x11) = (char)in_r2;
    if (in_r2 == 0) {
      (**(code **)(**(int **)(iVar1 + 0x23ec) + 0x1c))();
    }
    else if ((uVar3 == 1) && (-1 < *(int *)param_1)) {
      play((FModSound *)param_1,*(int *)param_1,(Vector *)0x0,(Vector *)0x0,in_s0);
    }
    bVar5 = false;
    iVar1 = 0x12;
    do {
      cVar4 = *(char *)(param_1 + iVar1);
      if (bVar5) {
        cVar4 = '\x01';
      }
      if (*(char *)(param_1 + iVar1) != '\0') break;
      bVar5 = cVar4 != '\0';
      iVar2 = iVar1 + -0x10;
      iVar1 = iVar1 + 1;
    } while (iVar2 < 4);
    *(char *)(param_1 + 0x11) = cVar4;
  }
  return;
}

// ===== FModSound::play  @0x0009dea8  (552 bytes)
/* WARNING: Removing unreachable block (ram,0x0009e086) */
/* WARNING: Removing unreachable block (ram,0x0009e08e) */
/* WARNING: Removing unreachable block (ram,0x0009e0a0) */
/* WARNING: Removing unreachable block (ram,0x0009e098) */
/* WARNING: Removing unreachable block (ram,0x0009e09e) */
/* FModSound::play(int, AbyssEngine::AEMath::Vector*, AbyssEngine::AEMath::Vector*, float) */

void __thiscall
FModSound::play(FModSound *this,int param_1,Vector *param_2,Vector *param_3,float param_4)

{
  FModSound *pFVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  FMOD_VECTOR *pFVar6;
  bool bVar7;
  FMOD_VECTOR *pFVar8;
  bool bVar9;
  undefined4 uVar10;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float in_stack_00000000;
  int local_44;
  int *local_40;
  undefined4 *local_3c;
  EventCategory **local_38;
  int local_34;
  
  local_34 = __stack_chk_guard;
  iVar3 = local_44;
  if (((*(int *)(this + 0x2404) != 0) && ((uint)param_1 < 0x8f5)) && (*(uint *)(this + 0x23fc) != 0)
     ) {
    pFVar1 = this + param_1 * 4 + 0x18;
    local_38 = *(EventCategory ***)pFVar1;
    bVar2 = local_38 == (EventCategory **)0x0;
    if (bVar2) {
      param_4 = (float)FMOD::EventSystem::getEventBySystemID
                                 (*(uint *)(this + 0x23fc),param_1,(Event **)&DAT_00000004);
    }
    iVar3 = local_44;
    if (local_38 != (EventCategory **)0x0) {
      uVar10 = 0;
      if (this[8] != (FModSound)0x0) {
        uVar10 = 0xbf800000;
      }
      FMOD::Event::setPitch(local_38,uVar10,1);
      if (in_stack_00000000 != 0.0) {
        FMOD::Event::setPitch(local_38,in_stack_00000000,0);
      }
      iVar3 = FMOD::Event::getCategory(local_38);
      if (iVar3 == 0) {
        param_4 = (float)(**(code **)*local_3c)(local_3c,&local_44,&local_40);
        iVar3 = local_44 + 1;
        if (local_44 == 0) {
          *(int *)this = param_1;
        }
        if ((iVar3 < 4) && (this[local_44 + 0x12] != (FModSound)0x0)) {
          local_44 = iVar3;
          if (param_2 == (Vector *)0x0) {
            bVar7 = false;
          }
          else {
            puVar5 = *(undefined4 **)(this + 0x2434);
            if (puVar5 == (undefined4 *)0x0) {
              puVar5 = operator_new(0xc);
              *puVar5 = 0;
              puVar5[1] = 0;
              puVar5[2] = 0;
              *(undefined4 **)(this + 0x2434) = puVar5;
            }
            bVar7 = true;
            *puVar5 = *(undefined4 *)param_2;
            puVar5[1] = *(undefined4 *)(param_2 + 4);
            puVar5[2] = *(undefined4 *)(param_2 + 8);
          }
          if (param_3 == (Vector *)0x0) {
            bVar9 = false;
          }
          else {
            puVar5 = *(undefined4 **)(this + 0x2438);
            if (puVar5 == (undefined4 *)0x0) {
              puVar5 = operator_new(0xc);
              *puVar5 = 0;
              puVar5[1] = 0;
              puVar5[2] = 0;
              *(undefined4 **)(this + 0x2438) = puVar5;
            }
            bVar9 = true;
            *puVar5 = *(undefined4 *)param_3;
            puVar5[1] = *(undefined4 *)(param_3 + 4);
            puVar5[2] = *(undefined4 *)(param_3 + 8);
          }
          if (bVar2) {
            iVar4 = FMOD::EventSystem::getEventBySystemID
                              (*(uint *)(this + 0x23fc),param_1,(Event **)0x0);
            param_4 = extraout_s0_01;
            iVar3 = local_44;
            if (iVar4 != 0) goto LAB_0009e0b2;
            *(EventCategory ***)pFVar1 = local_38;
          }
          if ((bool)(bVar7 | bVar9)) {
            if (bVar7) {
              pFVar6 = *(FMOD_VECTOR **)(this + 0x2434);
            }
            else {
              pFVar6 = (FMOD_VECTOR *)0x0;
            }
            if (bVar9) {
              pFVar8 = *(FMOD_VECTOR **)(this + 0x2438);
            }
            else {
              pFVar8 = (FMOD_VECTOR *)0x0;
            }
            FMOD::Event::set3DAttributes(*(FMOD_VECTOR **)pFVar1,pFVar6,pFVar8);
          }
          FMOD::Event::getProperty
                    (*(char **)pFVar1,property_name_purge,(bool)((char)&stack0xffffffdc + -0x24));
          param_4 = (float)FMOD::Event::start();
          iVar3 = local_44;
        }
      }
      else {
        param_4 = extraout_s0;
        iVar3 = local_44;
        if ((*(EventGroup ***)pFVar1 != (EventGroup **)0x0) &&
           (iVar4 = FMOD::Event::getParentGroup(*(EventGroup ***)pFVar1), param_4 = extraout_s0_00,
           iVar3 = local_44, iVar4 == 0)) {
          param_4 = (float)(**(code **)(*local_40 + 8))(local_40,*(undefined4 *)pFVar1,0);
          *(undefined4 *)pFVar1 = 0;
          iVar3 = local_44;
        }
      }
    }
  }
LAB_0009e0b2:
  local_44 = iVar3;
  if (__stack_chk_guard == local_34) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(param_4);
}

// ===== FModSound::playMusicFadeOutCurrent  @0x0009e0e0  (46 bytes)
/* FModSound::playMusicFadeOutCurrent(int) */

void FModSound::playMusicFadeOutCurrent(int param_1)

{
  int in_r1;
  float in_s0;
  
  if (*(int *)param_1 != in_r1) {
    if (*(int *)param_1 == -1) {
      *(int *)param_1 = in_r1;
    }
    setParamValue(param_1,0,in_s0);
    *(int *)(param_1 + 4) = in_r1;
    return;
  }
  return;
}

// ===== FModSound::fadeOutNow  @0x0009e10e  (30 bytes)
/* FModSound::fadeOutNow() */

void FModSound::fadeOutNow(void)

{
  int *in_r0;
  int in_r1;
  int iVar1;
  float in_s0;
  
  iVar1 = *in_r0;
  if (iVar1 != -1) {
    in_r1 = in_r0[1];
  }
  if (iVar1 == -1 || in_r1 == iVar1) {
    return;
  }
  setParamValue((int)in_r0,0,in_s0);
  return;
}

// ===== FModSound::stop  @0x0009e12c  (20 bytes)
/* FModSound::stop(int) */

void __thiscall FModSound::stop(FModSound *this,int param_1)

{
  if ((-1 < param_1) && (*(int *)(this + param_1 * 4 + 0x18) != 0)) {
    FMOD::Event::stop(SUB41(*(int *)(this + param_1 * 4 + 0x18),0));
    return;
  }
  return;
}

// ===== FModSound::stop  @0x0009e140  (14 bytes)
/* FModSound::stop(FMOD::Event*) */

FModSound * __thiscall FModSound::stop(FModSound *this,Event *param_1)

{
  FModSound *pFVar1;
  
  if (param_1 == (Event *)0x0) {
    return this;
  }
  pFVar1 = (FModSound *)FMOD::Event::stop(SUB41(param_1,0));
  return pFVar1;
}

// ===== FModSound::updateEvent3DAttributes  @0x0009e14c  (36 bytes)
/* FModSound::updateEvent3DAttributes(int, AbyssEngine::AEMath::Vector*,
   AbyssEngine::AEMath::Vector*, bool) */

void __thiscall
FModSound::updateEvent3DAttributes
          (FModSound *this,int param_1,Vector *param_2,Vector *param_3,bool param_4)

{
  undefined4 uVar1;
  
  uVar1 = updateEvent3DAttributes
                    (this,*(Event **)(this + param_1 * 4 + 0x18),param_1,param_2,param_3,param_4);
  *(undefined4 *)(this + param_1 * 4 + 0x18) = uVar1;
  return;
}

// ===== FModSound::updateEvent3DAttributes  @0x0009e170  (568 bytes)
/* FModSound::updateEvent3DAttributes(FMOD::Event*, int, AbyssEngine::AEMath::Vector*,
   AbyssEngine::AEMath::Vector*, bool) */

void __thiscall
FModSound::updateEvent3DAttributes
          (FModSound *this,Event *param_1,int param_2,Vector *param_3,Vector *param_4,bool param_5)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  FMOD_VECTOR *pFVar6;
  FMOD_VECTOR *pFVar7;
  undefined3 in_stack_00000005;
  uint local_34;
  int local_30;
  FMOD_VECTOR *local_2c;
  undefined4 *local_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  if ((*(int *)(this + 0x2404) != 0) && (this[0x11] != (FModSound)0x0)) {
    if ((param_1 == (Event *)0x0) ||
       (iVar2 = FMOD::Event::getCategory((EventCategory **)param_1), iVar2 == 0x24)) {
      iVar2 = FMOD::EventSystem::getEventBySystemID
                        (*(uint *)(this + 0x23fc),param_2,(Event **)&DAT_00000004);
      if ((((iVar2 == 0) &&
           (iVar2 = FMOD::Event::getCategory((EventCategory **)local_2c), iVar2 == 0)) &&
          (iVar2 = (**(code **)*local_28)(local_28,&local_34,&local_30), iVar2 == 0)) &&
         (uVar5 = local_34 + 1, iVar2 = local_34 + 0x12, local_34 = uVar5,
         this[iVar2] != (FModSound)0x0)) {
        if (param_3 == (Vector *)0x0) {
          bVar1 = false;
        }
        else {
          puVar4 = *(undefined4 **)(this + 0x2434);
          if (puVar4 == (undefined4 *)0x0) {
            puVar4 = operator_new(0xc);
            *puVar4 = 0;
            puVar4[1] = 0;
            puVar4[2] = 0;
            *(undefined4 **)(this + 0x2434) = puVar4;
          }
          bVar1 = true;
          *puVar4 = *(undefined4 *)param_3;
          puVar4[1] = *(undefined4 *)(param_3 + 4);
          puVar4[2] = *(undefined4 *)(param_3 + 8);
        }
        if (param_4 == (Vector *)0x0) {
          if (!bVar1) goto LAB_0009e384;
          pFVar6 = *(FMOD_VECTOR **)(this + 0x2434);
          pFVar7 = (FMOD_VECTOR *)0x0;
        }
        else {
          puVar4 = *(undefined4 **)(this + 0x2438);
          if (puVar4 == (undefined4 *)0x0) {
            puVar4 = operator_new(0xc);
            *puVar4 = 0;
            puVar4[1] = 0;
            puVar4[2] = 0;
            *(undefined4 **)(this + 0x2438) = puVar4;
          }
          *puVar4 = *(undefined4 *)param_4;
          puVar4[1] = *(undefined4 *)(param_4 + 4);
          puVar4[2] = *(undefined4 *)(param_4 + 8);
          if (bVar1) {
            pFVar6 = *(FMOD_VECTOR **)(this + 0x2434);
          }
          else {
            pFVar6 = (FMOD_VECTOR *)0x0;
          }
          pFVar7 = *(FMOD_VECTOR **)(this + 0x2438);
        }
        iVar2 = FMOD::Event::set3DAttributes(local_2c,pFVar6,pFVar7);
        if ((iVar2 == 0) &&
           (iVar2 = FMOD::EventSystem::getEventBySystemID
                              (*(uint *)(this + 0x23fc),param_2,(Event **)0x0), iVar2 == 0)) {
          FMOD::Event::start();
        }
      }
    }
    else if (((iVar2 == 0) &&
             (iVar2 = (**(code **)*local_28)(local_28,&local_30,&local_2c), iVar2 == 0)) &&
            (iVar3 = local_30 + 1, iVar2 = local_30 + 0x12, local_30 = iVar3,
            this[iVar2] != (FModSound)0x0)) {
      if (param_3 == (Vector *)0x0) {
        bVar1 = false;
      }
      else {
        puVar4 = *(undefined4 **)(this + 0x2434);
        if (puVar4 == (undefined4 *)0x0) {
          puVar4 = operator_new(0xc);
          *puVar4 = 0;
          puVar4[1] = 0;
          puVar4[2] = 0;
          *(undefined4 **)(this + 0x2434) = puVar4;
        }
        *puVar4 = *(undefined4 *)param_3;
        puVar4[1] = *(undefined4 *)(param_3 + 4);
        bVar1 = true;
        puVar4[2] = *(undefined4 *)(param_3 + 8);
      }
      if (param_4 == (Vector *)0x0) {
        if (!bVar1) goto LAB_0009e384;
        pFVar7 = (FMOD_VECTOR *)0x0;
        pFVar6 = *(FMOD_VECTOR **)(this + 0x2434);
      }
      else {
        puVar4 = *(undefined4 **)(this + 0x2438);
        if (puVar4 == (undefined4 *)0x0) {
          puVar4 = operator_new(0xc);
          *puVar4 = 0;
          puVar4[1] = 0;
          puVar4[2] = 0;
          *(undefined4 **)(this + 0x2438) = puVar4;
        }
        *puVar4 = *(undefined4 *)param_4;
        puVar4[1] = *(undefined4 *)(param_4 + 4);
        puVar4[2] = *(undefined4 *)(param_4 + 8);
        if (bVar1) {
          pFVar6 = *(FMOD_VECTOR **)(this + 0x2434);
        }
        else {
          pFVar6 = (FMOD_VECTOR *)0x0;
        }
        pFVar7 = *(FMOD_VECTOR **)(this + 0x2438);
      }
      iVar2 = FMOD::Event::set3DAttributes((FMOD_VECTOR *)param_1,pFVar6,pFVar7);
      if ((iVar2 == 0) && (_param_5 == 1)) {
        FMOD::Event::getState((uint *)param_1);
        if ((local_34 & 8) != 0) {
          FMOD::Event::stop(SUB41(param_1,0));
        }
        FMOD::Event::start();
      }
    }
  }
LAB_0009e384:
  if (__stack_chk_guard - local_24 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_24);
  }
  return;
}

// ===== FModSound::pause  @0x0009e3b0  (100 bytes)
/* FModSound::pause(FMOD::Event*) */

void __thiscall FModSound::pause(FModSound *this,Event *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  byte local_18;
  
  iVar1 = __stack_chk_guard;
  uVar2 = 0;
  if ((param_1 != (Event *)0x0) && (*(int *)(this + 0x23fc) != 0)) {
    iVar3 = FMOD::Event::getState((uint *)param_1);
    if ((iVar3 == 0) && ((local_18 & 8) != 0)) {
      iVar3 = FMOD::Event::setPaused(SUB41(param_1,0));
      uVar2 = 0;
      if (iVar3 == 0) {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}

// ===== FModSound::resume  @0x0009e41c  (36 bytes)
/* FModSound::resume(FMOD::Event*) */

undefined4 __thiscall FModSound::resume(FModSound *this,Event *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (Event *)0x0) && (*(int *)(this + 0x23fc) != 0)) {
    uVar2 = 0;
    iVar1 = FMOD::Event::setPaused(SUB41(param_1,0));
    if (iVar1 == 0) {
      uVar2 = 1;
    }
  }
  return uVar2;
}

// ===== FModSound::setParamValue  @0x0009e440  (72 bytes)
/* FModSound::setParamValue(FMOD::Event*, int, float) */

void FModSound::setParamValue(Event *param_1,int param_2,float param_3)

{
  int iVar1;
  EventParameter **in_r2;
  float fVar2;
  
  iVar1 = __stack_chk_guard;
  if ((param_2 != 0) && (*(int *)(param_1 + 0x23fc) != 0)) {
    fVar2 = (float)FMOD::Event::getParameterByIndex(param_2,in_r2);
    param_3 = (float)FMOD::EventParameter::setValue(fVar2);
  }
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_3);
  }
  return;
}

// ===== FModSound::enableReverb  @0x0009e490  (102 bytes)
/* FModSound::enableReverb(int) */

void __thiscall FModSound::enableReverb(FModSound *this,int param_1)

{
  int iVar1;
  char *apcStack_6c [20];
  int local_1c;
  int local_18;
  
  local_18 = __stack_chk_guard;
  if ((((*(int **)(this + 0x23fc) != (int *)0x0) &&
       (iVar1 = FMOD::EventSystem::getNumReverbPresets(*(int **)(this + 0x23fc)), iVar1 == 0)) &&
      (param_1 < local_1c)) && (*(int *)(this + 0x2408) != param_1)) {
    *(int *)(this + 0x2408) = param_1;
    iVar1 = FMOD::EventSystem::getReverbPresetByIndex
                      (*(int *)(this + 0x23fc),(FMOD_REVERB_PROPERTIES *)param_1,apcStack_6c);
    if (iVar1 == 0) {
      FMOD::EventSystem::setReverbProperties(*(FMOD_REVERB_PROPERTIES **)(this + 0x23fc));
    }
  }
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== FModSound::disableReverb  @0x0009e500  (80 bytes)
/* FModSound::disableReverb() */

void __thiscall FModSound::disableReverb(FModSound *this)

{
  FMOD_REVERB_PROPERTIES *pFVar1;
  undefined1 auStack_68 [80];
  int local_18;
  
  local_18 = __stack_chk_guard;
  pFVar1 = *(FMOD_REVERB_PROPERTIES **)(this + 0x23fc);
  if (pFVar1 != (FMOD_REVERB_PROPERTIES *)0x0) {
    __aeabi_memcpy8(auStack_68,&DAT_00251cb8,0x50);
    FMOD::EventSystem::setReverbProperties(pFVar1);
  }
  *(undefined4 *)(this + 0x2408) = 0xffffffff;
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== FModSound::getPlayingProgress  @0x0009e55c  (130 bytes)
/* FModSound::getPlayingProgress(int) */

void __thiscall FModSound::getPlayingProgress(FModSound *this,int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint in_fpscr;
  char *pcStack_14;
  FMOD_EVENT_INFO aFStack_10 [4];
  int local_c;
  
  local_c = __stack_chk_guard;
  if ((((*(int *)(this + 0x2404) != 0) && (*(int *)(this + 0x23fc) != 0)) &&
      (this[0x11] != (FModSound)0x0)) && (*(int **)(this + param_1 * 4 + 0x18) != (int *)0x0)) {
    uVar1 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    FMOD::Event::getInfo(*(int **)(this + param_1 * 4 + 0x18),&pcStack_14,aFStack_10);
    VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
    VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
  }
  if (__stack_chk_guard - local_c != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_c);
  }
  return;
}

// ===== FModSound::getEventPauseLength  @0x0009e5ec  (94 bytes)
/* FModSound::getEventPauseLength(int) */

void __thiscall FModSound::getEventPauseLength(FModSound *this,int param_1)

{
  int iVar1;
  
  iVar1 = __stack_chk_guard;
  if ((((*(int *)(this + 0x2404) != 0) && (*(int *)(this + 0x23fc) != 0)) &&
      (this[0x11] != (FModSound)0x0)) && (*(char **)(this + param_1 * 4 + 0x18) != (char *)0x0)) {
    FMOD::Event::getProperty(*(char **)(this + param_1 * 4 + 0x18),property_name_pause,true);
  }
  if (__stack_chk_guard == iVar1) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(0);
}

// ===== FModSound::setDownPitch  @0x0009e658  (92 bytes)
/* FModSound::setDownPitch(bool) */

void __thiscall FModSound::setDownPitch(FModSound *this,bool param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  iVar2 = 0;
  if (param_1) {
    uVar3 = 0xbf800000;
  }
  this[8] = (FModSound)param_1;
  do {
    if (((*(int *)(this + 0x23fc) != 0) && (*(int *)(this + iVar2 * 4 + 0x18) != 0)) &&
       (iVar1 = isPlaying(this,iVar2), iVar1 == 1)) {
      FMOD::Event::setPitch(*(undefined4 *)(this + iVar2 * 4 + 0x18),uVar3,1);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x8f5);
  return;
}

// ===== FModSound::promptMusicCue  @0x0009e6b8  (16 bytes)
/* FModSound::promptMusicCue(int) */

void FModSound::promptMusicCue(int param_1)

{
  if (*(int **)(param_1 + 0x2400) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0009e6c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x2400) + 0x28))();
    return;
  }
  return;
}

// ===== FModSound::pause  @0x0009e6c8  (24 bytes)
/* FModSound::pause(int) */

void __thiscall FModSound::pause(FModSound *this,int param_1)

{
  if ((*(int *)(this + 0x23fc) != 0) && (*(int *)(this + param_1 * 4 + 0x18) != 0)) {
    FMOD::Event::setPaused(SUB41(*(int *)(this + param_1 * 4 + 0x18),0));
    return;
  }
  return;
}

// ===== FModSound::resume  @0x0009e6e0  (26 bytes)
/* FModSound::resume(int) */

void __thiscall FModSound::resume(FModSound *this,int param_1)

{
  if ((*(int *)(this + 0x23fc) != 0) && (*(int *)(this + param_1 * 4 + 0x18) != 0)) {
    FMOD::Event::setPaused(SUB41(*(int *)(this + param_1 * 4 + 0x18),0));
    return;
  }
  return;
}

// ===== FModSound::pauseAll  @0x0009e6f8  (44 bytes)
/* FModSound::pauseAll() */

void __thiscall FModSound::pauseAll(FModSound *this)

{
  FModSound *pFVar1;
  int iVar2;
  
  pFVar1 = this + 0x18;
  iVar2 = 0x8f5;
  do {
    if ((*(int *)(this + 0x23fc) != 0) && (*(int *)pFVar1 != 0)) {
      FMOD::Event::setPaused(SUB41(*(int *)pFVar1,0));
    }
    pFVar1 = pFVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

// ===== FModSound::stopAll  @0x0009e724  (44 bytes)
/* FModSound::stopAll() */

void __thiscall FModSound::stopAll(FModSound *this)

{
  FModSound *pFVar1;
  int iVar2;
  
  pFVar1 = this + 0x18;
  iVar2 = 0x8f5;
  do {
    if ((*(int *)(this + 0x23fc) != 0) && (*(int *)pFVar1 != 0)) {
      FMOD::Event::stop(SUB41(*(int *)pFVar1,0));
    }
    pFVar1 = pFVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

// ===== FModSound::resumeAll  @0x0009e750  (44 bytes)
/* FModSound::resumeAll() */

void __thiscall FModSound::resumeAll(FModSound *this)

{
  FModSound *pFVar1;
  int iVar2;
  
  pFVar1 = this + 0x18;
  iVar2 = 0x8f5;
  do {
    if ((*(int *)(this + 0x23fc) != 0) && (*(int *)pFVar1 != 0)) {
      FMOD::Event::setPaused(SUB41(*(int *)pFVar1,0));
    }
    pFVar1 = pFVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

// ===== FModSound::pauseAllPlaying  @0x0009e77c  (70 bytes)
/* FModSound::pauseAllPlaying() */

void __thiscall FModSound::pauseAllPlaying(FModSound *this)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    if (((*(int *)(this + 0x23fc) != 0) && (*(int *)(this + iVar2 * 4 + 0x18) != 0)) &&
       (iVar1 = isPlaying(this,iVar2), iVar1 == 1)) {
      FMOD::Event::setPaused(SUB41(*(undefined4 *)(this + iVar2 * 4 + 0x18),0));
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x8f5);
  return;
}

// ===== FModSound::pauseAllPlayingSoundFXEvents  @0x0009e7c4  (134 bytes)
/* FModSound::pauseAllPlayingSoundFXEvents() */

void __thiscall FModSound::pauseAllPlayingSoundFXEvents(FModSound *this)

{
  int iVar1;
  int iVar2;
  int local_34;
  undefined1 auStack_30 [4];
  undefined4 *local_2c;
  int local_28;
  
  iVar2 = 0;
  local_28 = __stack_chk_guard;
  do {
    if (((*(int *)(this + 0x23fc) != 0) && (*(int *)(this + iVar2 * 4 + 0x18) != 0)) &&
       (iVar1 = isPlaying(this,iVar2), iVar1 == 1)) {
      FMOD::Event::getCategory(*(EventCategory ***)(this + iVar2 * 4 + 0x18));
      (**(code **)*local_2c)(local_2c,&local_34,auStack_30);
      if (local_34 == 1) {
        FMOD::Event::setPaused(SUB41(*(undefined4 *)(this + iVar2 * 4 + 0x18),0));
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x8f5);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

