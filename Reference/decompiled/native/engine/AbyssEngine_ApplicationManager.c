// Class: AbyssEngine::ApplicationManager
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::ApplicationManager::ApplicationManager  @0x0008c26c  (1416 bytes)
/* AbyssEngine::ApplicationManager::ApplicationManager(AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::ApplicationManager::ApplicationManager(ApplicationManager *this,Engine *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  PaintCanvas *this_00;
  AESoundRessource *this_01;
  ConfigReader *this_02;
  CheatHandler *this_03;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 local_27c;
  String aSStack_278 [8];
  undefined4 local_270;
  String aSStack_26c [8];
  undefined4 local_264;
  String aSStack_260 [8];
  undefined4 local_258;
  String aSStack_254 [8];
  undefined4 local_24c;
  String aSStack_248 [8];
  undefined4 local_240;
  String aSStack_23c [8];
  undefined4 local_234;
  String aSStack_230 [8];
  undefined4 local_228;
  String aSStack_224 [8];
  undefined4 local_21c;
  String aSStack_218 [8];
  undefined4 local_210;
  String aSStack_20c [8];
  undefined4 local_204;
  String aSStack_200 [8];
  undefined4 local_1f8;
  String aSStack_1f4 [8];
  undefined4 local_1ec;
  String aSStack_1e8 [8];
  undefined4 local_1e0;
  String aSStack_1dc [8];
  undefined4 local_1d4;
  String aSStack_1d0 [8];
  undefined4 local_1c8;
  String aSStack_1c4 [8];
  undefined4 local_1bc;
  String aSStack_1b8 [8];
  undefined4 local_1b0;
  String aSStack_1ac [8];
  undefined4 local_1a4;
  String aSStack_1a0 [8];
  undefined4 local_198;
  String aSStack_194 [8];
  undefined4 local_18c;
  String aSStack_188 [8];
  undefined4 local_180;
  String aSStack_17c [8];
  undefined4 local_174;
  String aSStack_170 [8];
  undefined4 local_168;
  String aSStack_164 [8];
  undefined4 local_15c;
  String aSStack_158 [8];
  undefined4 local_150;
  String aSStack_14c [8];
  undefined4 local_144;
  String aSStack_140 [8];
  undefined4 local_138;
  String aSStack_134 [8];
  undefined4 local_12c;
  String aSStack_128 [8];
  undefined4 local_120;
  String aSStack_11c [8];
  undefined4 local_114;
  String aSStack_110 [8];
  undefined4 local_108;
  String aSStack_104 [8];
  undefined4 local_fc;
  String aSStack_f8 [8];
  undefined4 local_f0;
  String aSStack_ec [8];
  undefined4 local_e4;
  String aSStack_e0 [8];
  undefined4 local_d8;
  String aSStack_d4 [8];
  undefined4 local_cc;
  String aSStack_c8 [8];
  undefined4 local_c0;
  String aSStack_bc [8];
  undefined4 local_b4;
  String aSStack_b0 [8];
  undefined4 local_a8;
  String aSStack_a4 [8];
  undefined4 local_9c;
  String aSStack_98 [8];
  undefined4 local_90;
  String aSStack_8c [8];
  undefined4 local_84;
  String aSStack_80 [8];
  undefined4 local_78;
  String aSStack_74 [8];
  undefined4 local_6c;
  String aSStack_68 [8];
  undefined4 local_60;
  String aSStack_5c [8];
  undefined4 local_54;
  String aSStack_50 [8];
  undefined4 local_48;
  String aSStack_44 [8];
  undefined4 local_3c;
  String aSStack_38 [8];
  undefined4 local_30;
  String aSStack_2c [8];
  int local_24;
  
  local_24 = __stack_chk_guard;
  puVar4 = operator_new__(4);
  *(undefined4 **)(this + 0x48) = puVar4;
  *(undefined4 *)(this + 0x4c) = 1;
  *puVar4 = 0;
  *(undefined4 *)(this + 0x44) = 0;
  puVar4 = operator_new__(4);
  *(undefined4 **)(this + 0x54) = puVar4;
  *(undefined4 *)(this + 0x58) = 1;
  *puVar4 = 0;
  *(undefined4 *)(this + 0x50) = 0;
  puVar4 = operator_new__(8);
  uVar1 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 **)(this + 0x8c) = puVar4;
  *(undefined4 *)(this + 0x90) = 1;
  *puVar4 = 0;
  puVar4[1] = 0;
  *(undefined4 *)(this + 0x88) = 0;
  debugTouch._0_4_ = 0;
  debugTouch._4_4_ = uVar1;
  debugTouch._8_4_ = uVar2;
  debugTouch._12_4_ = uVar3;
  *(undefined4 *)(this + 0x3c) = 5;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x74) = uVar1;
  *(undefined4 *)(this + 0x78) = uVar2;
  *(undefined4 *)(this + 0x7c) = uVar3;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 100) = uVar1;
  *(undefined4 *)(this + 0x68) = uVar2;
  *(undefined4 *)(this + 0x6c) = uVar3;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  *(Engine **)(this + 0xa8) = param_1;
  this_00 = operator_new(0x20c);
  PaintCanvas::PaintCanvas(this_00,param_1);
  *(PaintCanvas **)this = this_00;
  this_01 = operator_new(0x14);
  AESoundRessource::AESoundRessource(this_01);
  *(AESoundRessource **)(this + 0xac) = this_01;
  this[0x34] = (ApplicationManager)0x0;
  this_02 = operator_new(0x14);
  ConfigReader::ConfigReader(this_02,param_1);
  *(ConfigReader **)(this + 0x38) = this_02;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  this[0xb1] = (ApplicationManager)0x1;
  this[0xb0] = (ApplicationManager)0x1;
  this[0xb2] = (ApplicationManager)0x1;
  this[0x14] = (ApplicationManager)0x0;
  local_27c = 0;
  String::String(aSStack_278,"0",false);
  local_270 = 1;
  String::String(aSStack_26c,"1",false);
  local_264 = 2;
  String::String(aSStack_260,"2",false);
  local_258 = 3;
  String::String(aSStack_254,"3",false);
  local_24c = 4;
  String::String(aSStack_248,"4",false);
  local_240 = 5;
  String::String(aSStack_23c,"5",false);
  local_234 = 6;
  String::String(aSStack_230,"6",false);
  local_228 = 7;
  String::String(aSStack_224,"7",false);
  local_21c = 8;
  String::String(aSStack_218,"8",false);
  local_210 = 9;
  String::String(aSStack_20c,"9",false);
  local_204 = 10;
  String::String(aSStack_200,"#",false);
  local_1f8 = 0xb;
  String::String(aSStack_1f4,"*",false);
  local_1ec = 0xc;
  String::String(aSStack_1e8,"D-pad left",false);
  local_1e0 = 0xd;
  String::String(aSStack_1dc,"D-pad right",false);
  local_1d4 = 0xe;
  String::String(aSStack_1d0,"D-pad up",false);
  local_1c8 = 0xf;
  String::String(aSStack_1c4,"D-pad down",false);
  local_1bc = 0;
  String::String(aSStack_1b8,"D-pad fire",false);
  local_1b0 = 0;
  String::String(aSStack_1ac,"Softbutton left",false);
  local_1a4 = 0;
  String::String(aSStack_1a0,"Softbutton right",false);
  local_198 = 0;
  String::String(aSStack_194,"CLR",false);
  local_18c = 0x61;
  String::String(aSStack_188,"A",false);
  local_180 = 0x62;
  String::String(aSStack_17c,"B",false);
  local_174 = 99;
  String::String(aSStack_170,"C",false);
  local_168 = 100;
  String::String(aSStack_164,"D",false);
  local_15c = 0x65;
  String::String(aSStack_158,"E",false);
  local_150 = 0x66;
  String::String(aSStack_14c,"F",false);
  local_144 = 0x67;
  String::String(aSStack_140,"G",false);
  local_138 = 0x68;
  String::String(aSStack_134,"H",false);
  local_12c = 0x69;
  String::String(aSStack_128,"I",false);
  local_120 = 0x6a;
  String::String(aSStack_11c,"J",false);
  local_114 = 0x6b;
  String::String(aSStack_110,"K",false);
  local_108 = 0x6c;
  String::String(aSStack_104,"L",false);
  local_fc = 0x6d;
  String::String(aSStack_f8,"M",false);
  local_f0 = 0x6e;
  String::String(aSStack_ec,"N",false);
  local_e4 = 0x6f;
  String::String(aSStack_e0,"O",false);
  local_d8 = 0x70;
  String::String(aSStack_d4,"P",false);
  local_cc = 0x71;
  String::String(aSStack_c8,"Q",false);
  local_c0 = 0x72;
  String::String(aSStack_bc,"R",false);
  local_b4 = 0x73;
  String::String(aSStack_b0,"S",false);
  local_a8 = 0x74;
  String::String(aSStack_a4,"T",false);
  local_9c = 0x75;
  String::String(aSStack_98,"U",false);
  local_90 = 0x76;
  String::String(aSStack_8c,"V",false);
  local_84 = 0x77;
  String::String(aSStack_80,"W",false);
  local_78 = 0x78;
  String::String(aSStack_74,"X",false);
  local_6c = 0x79;
  String::String(aSStack_68,"Y",false);
  local_60 = 0x7a;
  String::String(aSStack_5c,"Z",false);
  local_54 = 0x20;
  String::String(aSStack_50,"Space",false);
  local_48 = 10;
  String::String(aSStack_44,"Enter",false);
  local_3c = 0x10;
  String::String(aSStack_38,"Menu",false);
  local_30 = 0x11;
  String::String(aSStack_2c,"CAPLK",false);
  puVar4 = operator_new__(0x308);
  puVar7 = puVar4 + 2;
  iVar5 = 0;
  *puVar4 = 0xc;
  puVar4[1] = 0x40;
  do {
    String::String((String *)((int)puVar4 + iVar5 + 0xc));
    iVar5 = iVar5 + 0xc;
  } while (iVar5 != 0x300);
  iVar5 = 0;
  iVar6 = 0;
  *(undefined4 **)(this + 0x10) = puVar7;
  while( true ) {
    *(undefined4 *)((int)puVar7 + iVar5) = *(undefined4 *)(aSStack_278 + iVar5 + -4);
    String::operator=((String *)((undefined4 *)((int)puVar7 + iVar5) + 1),aSStack_278 + iVar5);
    iVar6 = iVar6 + 1;
    if (0x31 < iVar6) break;
    iVar5 = iVar5 + 0xc;
    puVar7 = *(undefined4 **)(this + 0x10);
  }
  this_03 = operator_new(0x10);
  CheatHandler::CheatHandler(this_03,*(KeyCode **)(this + 0x10));
  iVar5 = 0x250;
  *(CheatHandler **)(this + 0x30) = this_03;
  *(undefined4 *)(this + 0xb4) = 0xffffffff;
  *(undefined4 *)(this + 0xb8) = 0xffffffff;
  do {
    String::~String(aSStack_278 + iVar5 + -4);
    iVar5 = iVar5 + -0xc;
  } while (iVar5 != -8);
  if (__stack_chk_guard - local_24 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_24);
  }
  return;
}

// ===== AbyssEngine::ApplicationManager::~ApplicationManager  @0x0008c99c  (224 bytes)
/* AbyssEngine::ApplicationManager::~ApplicationManager() */

ApplicationManager * __thiscall
AbyssEngine::ApplicationManager::~ApplicationManager(ApplicationManager *this)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  if (*(int **)(this + 0x18) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x18) + 0xc))();
  }
  uVar4 = *(uint *)(this + 0x44);
  pvVar1 = *(void **)(this + 0x48);
  if (uVar4 != 0) {
    uVar5 = 0;
    do {
      piVar2 = *(int **)((int)pvVar1 + uVar5 * 4);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 4))(piVar2);
        uVar4 = *(uint *)(this + 0x44);
        pvVar1 = *(void **)(this + 0x48);
      }
      *(undefined4 *)((int)pvVar1 + uVar5 * 4) = 0;
      uVar5 = uVar5 + 1;
      pvVar1 = *(void **)(this + 0x48);
    } while (uVar5 < uVar4);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(this + 0x48) = 0;
  if (*(void **)(this + 0x54) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x54));
  }
  *(undefined4 *)(this + 0x54) = 0;
  if (*(PaintCanvas **)this != (PaintCanvas *)0x0) {
    pvVar1 = (void *)PaintCanvas::~PaintCanvas(*(PaintCanvas **)this);
    operator_delete(pvVar1);
  }
  *(undefined4 *)this = 0;
  if (*(AESoundRessource **)(this + 0xac) != (AESoundRessource *)0x0) {
    pvVar1 = (void *)AESoundRessource::~AESoundRessource(*(AESoundRessource **)(this + 0xac));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xac) = 0;
  if (*(CheatHandler **)(this + 0x30) != (CheatHandler *)0x0) {
    pvVar1 = (void *)CheatHandler::~CheatHandler(*(CheatHandler **)(this + 0x30));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x30) = 0;
  if (*(ConfigReader **)(this + 0x38) != (ConfigReader *)0x0) {
    pvVar1 = (void *)ConfigReader::~ConfigReader(*(ConfigReader **)(this + 0x38));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x38) = 0;
  iVar3 = *(int *)(this + 0x10);
  if (iVar3 != 0) {
    if (*(int *)(iVar3 + -4) != 0) {
      iVar6 = *(int *)(iVar3 + -4) * 0xc;
      do {
        String::~String((String *)(iVar3 + -8 + iVar6));
        iVar6 = iVar6 + -0xc;
      } while (iVar6 != 0);
    }
    operator_delete__((void *)(iVar3 + -8));
  }
  *(undefined4 *)(this + 0x10) = 0;
  if (*(void **)(this + 0x8c) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x8c));
  }
  *(undefined4 *)(this + 0x8c) = 0;
  if (*(void **)(this + 0x54) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x54));
  }
  *(undefined4 *)(this + 0x54) = 0;
  if (*(void **)(this + 0x48) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x48));
  }
  *(undefined4 *)(this + 0x48) = 0;
  return this;
}

// ===== AbyssEngine::ApplicationManager::SoundSet  @0x0008ca9c  (50 bytes)
/* AbyssEngine::ApplicationManager::SoundSet(AbyssEngine::AESoundInfo const*, int) */

void __thiscall
AbyssEngine::ApplicationManager::SoundSet(ApplicationManager *this,AESoundInfo *param_1,int param_2)

{
  int iVar1;
  
  if (((param_1 != (AESoundInfo *)0x0) &&
      (*(AESoundRessource **)(this + 0xac) != (AESoundRessource *)0x0)) &&
     (AESoundRessource::SetSound(*(AESoundRessource **)(this + 0xac),param_1,param_2), 0 < param_2))
  {
    iVar1 = 0;
    do {
      AESoundRessource::init(*(AESoundRessource **)(this + 0xac),iVar1);
      iVar1 = iVar1 + 1;
    } while (param_2 != iVar1);
  }
  return;
}

// ===== AbyssEngine::ApplicationManager::SoundRelease  @0x0008cace  (16 bytes)
/* AbyssEngine::ApplicationManager::SoundRelease(int) */

void AbyssEngine::ApplicationManager::SoundRelease(int param_1)

{
  int in_r1;
  
  if (*(AESoundRessource **)(param_1 + 0xac) == (AESoundRessource *)0x0) {
    return;
  }
  AESoundRessource::release(*(AESoundRessource **)(param_1 + 0xac),in_r1);
  return;
}

// ===== AbyssEngine::ApplicationManager::SoundPlayMusic  @0x0008cadc  (22 bytes)
/* AbyssEngine::ApplicationManager::SoundPlayMusic(int) */

void AbyssEngine::ApplicationManager::SoundPlayMusic(int param_1)

{
  int in_r1;
  
  if ((*(AESoundRessource **)(param_1 + 0xac) != (AESoundRessource *)0x0) &&
     (*(char *)(param_1 + 0xb1) != '\0')) {
    AESoundRessource::playMusic(*(AESoundRessource **)(param_1 + 0xac),in_r1);
    return;
  }
  return;
}

// ===== AbyssEngine::ApplicationManager::SoundPlayMusicLoop  @0x0008caf0  (22 bytes)
/* AbyssEngine::ApplicationManager::SoundPlayMusicLoop(int) */

void AbyssEngine::ApplicationManager::SoundPlayMusicLoop(int param_1)

{
  int in_r1;
  
  if ((*(AESoundRessource **)(param_1 + 0xac) != (AESoundRessource *)0x0) &&
     (*(char *)(param_1 + 0xb1) != '\0')) {
    AESoundRessource::playMusicLoop(*(AESoundRessource **)(param_1 + 0xac),in_r1);
    return;
  }
  return;
}

// ===== AbyssEngine::ApplicationManager::SoundPlay  @0x0008cb04  (22 bytes)
/* AbyssEngine::ApplicationManager::SoundPlay(int) */

void AbyssEngine::ApplicationManager::SoundPlay(int param_1)

{
  if ((*(int *)(param_1 + 0xac) != 0) && (*(char *)(param_1 + 0xb0) != '\0')) {
    (*(code *)&LAB_00069170)();
    return;
  }
  return;
}

// ===== AbyssEngine::ApplicationManager::SoundPlay  @0x0008cb18  (22 bytes)
/* AbyssEngine::ApplicationManager::SoundPlay(int, float) */

void AbyssEngine::ApplicationManager::SoundPlay(int param_1,float param_2)

{
  int in_r1;
  
  if ((*(AESoundRessource **)(param_1 + 0xac) != (AESoundRessource *)0x0) &&
     (*(char *)(param_1 + 0xb0) != '\0')) {
    AESoundRessource::play(*(AESoundRessource **)(param_1 + 0xac),in_r1,param_2);
    return;
  }
  return;
}

// ===== AbyssEngine::ApplicationManager::SoundPlayLoop  @0x0008cb2c  (22 bytes)
/* AbyssEngine::ApplicationManager::SoundPlayLoop(int) */

void AbyssEngine::ApplicationManager::SoundPlayLoop(int param_1)

{
  if ((*(int *)(param_1 + 0xac) != 0) && (*(char *)(param_1 + 0xb0) != '\0')) {
    (*(code *)&LAB_0006917c)();
    return;
  }
  return;
}

// ===== AbyssEngine::ApplicationManager::SoundStop  @0x0008cb40  (16 bytes)
/* AbyssEngine::ApplicationManager::SoundStop(int) */

void AbyssEngine::ApplicationManager::SoundStop(int param_1)

{
  if (*(int *)(param_1 + 0xac) == 0) {
    return;
  }
  (*(code *)&LAB_00069188)();
  return;
}

// ===== AbyssEngine::ApplicationManager::SoundStopSounds  @0x0008cb4e  (16 bytes)
/* AbyssEngine::ApplicationManager::SoundStopSounds() */

void __thiscall AbyssEngine::ApplicationManager::SoundStopSounds(ApplicationManager *this)

{
  if (*(int *)(this + 0xac) == 0) {
    return;
  }
  (*(code *)&LAB_00069194)();
  return;
}

// ===== AbyssEngine::ApplicationManager::SoundPauseSounds  @0x0008cb5c  (16 bytes)
/* AbyssEngine::ApplicationManager::SoundPauseSounds() */

void __thiscall AbyssEngine::ApplicationManager::SoundPauseSounds(ApplicationManager *this)

{
  if (*(int *)(this + 0xac) == 0) {
    return;
  }
  (*(code *)&LAB_000691a0)();
  return;
}

// ===== AbyssEngine::ApplicationManager::SoundPause  @0x0008cb6a  (16 bytes)
/* AbyssEngine::ApplicationManager::SoundPause(int) */

void AbyssEngine::ApplicationManager::SoundPause(int param_1)

{
  if (*(int *)(param_1 + 0xac) == 0) {
    return;
  }
  (*(code *)&LAB_000691ac)();
  return;
}

// ===== AbyssEngine::ApplicationManager::SoundResume  @0x0008cb78  (42 bytes)
/* AbyssEngine::ApplicationManager::SoundResume(int) */

void AbyssEngine::ApplicationManager::SoundResume(int param_1)

{
  ushort uVar1;
  
  if (*(int *)(param_1 + 0xac) == 0) {
    uVar1 = (ushort)*(byte *)(param_1 + 0xb1);
  }
  else {
    if ((*(ushort *)(param_1 + 0xb0) & 0xff) != 0) goto LAB_001d86ec;
    uVar1 = *(ushort *)(param_1 + 0xb0) >> 8;
  }
  if (uVar1 == 0) {
    return;
  }
LAB_001d86ec:
  (*(code *)&LAB_000691b8)();
  return;
}

// ===== AbyssEngine::ApplicationManager::SoundResumeSounds  @0x0008cba0  (40 bytes)
/* AbyssEngine::ApplicationManager::SoundResumeSounds() */

void __thiscall AbyssEngine::ApplicationManager::SoundResumeSounds(ApplicationManager *this)

{
  ushort uVar1;
  
  if (*(int *)(this + 0xac) == 0) {
    uVar1 = (ushort)(byte)this[0xb1];
  }
  else {
    if ((*(ushort *)(this + 0xb0) & 0xff) != 0) goto LAB_001d86fc;
    uVar1 = *(ushort *)(this + 0xb0) >> 8;
  }
  if (uVar1 == 0) {
    return;
  }
LAB_001d86fc:
  (*(code *)&LAB_000691c4)();
  return;
}

// ===== AbyssEngine::ApplicationManager::SoundEnable  @0x0008cbc8  (10 bytes)
/* AbyssEngine::ApplicationManager::SoundEnable(bool) */

void __thiscall AbyssEngine::ApplicationManager::SoundEnable(ApplicationManager *this,bool param_1)

{
  this[0xb1] = (ApplicationManager)param_1;
  this[0xb0] = (ApplicationManager)param_1;
  return;
}

// ===== AbyssEngine::ApplicationManager::SoundFxEnable  @0x0008cbd2  (6 bytes)
/* AbyssEngine::ApplicationManager::SoundFxEnable(bool) */

void __thiscall
AbyssEngine::ApplicationManager::SoundFxEnable(ApplicationManager *this,bool param_1)

{
  this[0xb0] = (ApplicationManager)param_1;
  return;
}

// ===== AbyssEngine::ApplicationManager::SoundMusicEnable  @0x0008cbd8  (6 bytes)
/* AbyssEngine::ApplicationManager::SoundMusicEnable(bool) */

void __thiscall
AbyssEngine::ApplicationManager::SoundMusicEnable(ApplicationManager *this,bool param_1)

{
  this[0xb1] = (ApplicationManager)param_1;
  return;
}

// ===== AbyssEngine::ApplicationManager::SoundSetVolume  @0x0008cbde  (16 bytes)
/* AbyssEngine::ApplicationManager::SoundSetVolume(int, int) */

void AbyssEngine::ApplicationManager::SoundSetVolume(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0xac) == 0) {
    return;
  }
  (*(code *)&LAB_000691d0)();
  return;
}

// ===== AbyssEngine::ApplicationManager::SoundSetFXVolume  @0x0008cbec  (16 bytes)
/* AbyssEngine::ApplicationManager::SoundSetFXVolume(int) */

void AbyssEngine::ApplicationManager::SoundSetFXVolume(int param_1)

{
  if (*(int *)(param_1 + 0xac) == 0) {
    return;
  }
  (*(code *)&LAB_000691dc)();
  return;
}

// ===== AbyssEngine::ApplicationManager::SoundSetMusicVolume  @0x0008cbfa  (16 bytes)
/* AbyssEngine::ApplicationManager::SoundSetMusicVolume(int) */

void AbyssEngine::ApplicationManager::SoundSetMusicVolume(int param_1)

{
  if (*(int *)(param_1 + 0xac) == 0) {
    return;
  }
  (*(code *)&LAB_000691e8)();
  return;
}

// ===== AbyssEngine::ApplicationManager::SoundIsPlaying  @0x0008cc08  (20 bytes)
/* AbyssEngine::ApplicationManager::SoundIsPlaying(int) */

undefined4 __thiscall
AbyssEngine::ApplicationManager::SoundIsPlaying(ApplicationManager *this,int param_1)

{
  undefined4 uVar1;
  
  if (*(AESoundRessource **)(this + 0xac) != (AESoundRessource *)0x0) {
    uVar1 = AESoundRessource::isPlaying(*(AESoundRessource **)(this + 0xac),param_1);
    return uVar1;
  }
  return 0;
}

// ===== AbyssEngine::ApplicationManager::SoundResume  @0x0008cc1c  (16 bytes)
/* AbyssEngine::ApplicationManager::SoundResume() */

void __thiscall AbyssEngine::ApplicationManager::SoundResume(ApplicationManager *this)

{
  if (*(int *)(this + 0xac) == 0) {
    return;
  }
  (*(code *)&LAB_000691c4)();
  return;
}

// ===== AbyssEngine::ApplicationManager::VibrateEnable  @0x0008cc2a  (6 bytes)
/* AbyssEngine::ApplicationManager::VibrateEnable(bool) */

void __thiscall
AbyssEngine::ApplicationManager::VibrateEnable(ApplicationManager *this,bool param_1)

{
  this[0xb2] = (ApplicationManager)param_1;
  return;
}

// ===== AbyssEngine::ApplicationManager::VibrateSupported  @0x0008cc30  (10 bytes)
/* AbyssEngine::ApplicationManager::VibrateSupported() */

void AbyssEngine::ApplicationManager::VibrateSupported(void)

{
  int in_r0;
  
  Engine::HasVibration(*(Engine **)(in_r0 + 0xa8));
  return;
}

// ===== AbyssEngine::ApplicationManager::Vibrate  @0x0008cc38  (18 bytes)
/* AbyssEngine::ApplicationManager::Vibrate(unsigned short) */

void AbyssEngine::ApplicationManager::Vibrate(ushort param_1)

{
  if (*(char *)(param_1 + 0xb2) == '\0') {
    return;
  }
  Engine::Vibrate((ushort)*(undefined4 *)(param_1 + 0xa8));
  return;
}

// ===== AbyssEngine::ApplicationManager::RegisterApplicationModule  @0x0008cc48  (78 bytes)
/* AbyssEngine::ApplicationManager::RegisterApplicationModule(unsigned int,
   AbyssEngine::IApplicationModule*) */

void __thiscall
AbyssEngine::ApplicationManager::RegisterApplicationModule
          (ApplicationManager *this,uint param_1,IApplicationModule *param_2)

{
  void *pvVar1;
  
  if (param_2 != (IApplicationModule *)0x0) {
    IApplicationModule::SetApplicationManager(param_2,this);
    *(int *)(this + 0x4c) = *(int *)(this + 0x44) + 1;
    pvVar1 = realloc(*(void **)(this + 0x48),(*(int *)(this + 0x44) + 1) * 4);
    *(void **)(this + 0x48) = pvVar1;
    *(IApplicationModule **)((int)pvVar1 + *(int *)(this + 0x44) * 4) = param_2;
    *(undefined4 *)(this + 0x44) = *(undefined4 *)(this + 0x4c);
    *(int *)(this + 0x58) = *(int *)(this + 0x50) + 1;
    pvVar1 = realloc(*(void **)(this + 0x54),(*(int *)(this + 0x50) + 1) * 4);
    *(void **)(this + 0x54) = pvVar1;
    *(uint *)((int)pvVar1 + *(int *)(this + 0x50) * 4) = param_1;
    *(undefined4 *)(this + 0x50) = *(undefined4 *)(this + 0x58);
  }
  return;
}

// ===== AbyssEngine::ApplicationManager::EnablePerformanceTest  @0x0008cc98  (86 bytes)
/* AbyssEngine::ApplicationManager::EnablePerformanceTest(int) */

void AbyssEngine::ApplicationManager::EnablePerformanceTest(int param_1)

{
  performanceOverallModulSwitches._0_4_ = param_1;
  performanceOverallModulSwitches._4_4_ = param_1 >> 0x1f;
  performanceModulSwitches._0_4_ = 0;
  performanceModulSwitches._4_4_ = 0;
  performanceFrameCounter._0_4_ = 0;
  performanceFrameCounter._4_4_ = 0;
  performanceTime._0_4_ = 0;
  performanceTime._4_4_ = 0;
  triDrawn._0_4_ = 0;
  triDrawn._4_4_ = 0;
  performanceTest = 1;
  performanceTestEnded = 0;
  return;
}

// ===== AbyssEngine::ApplicationManager::SetCurrentApplicationModule  @0x0008cd0c  (128 bytes)
/* AbyssEngine::ApplicationManager::SetCurrentApplicationModule(unsigned int) */

void __thiscall
AbyssEngine::ApplicationManager::SetCurrentApplicationModule(ApplicationManager *this,uint param_1)

{
  uint uVar1;
  bool bVar2;
  
  if (performanceTest != '\0') {
    bVar2 = 0xfffffffe < (uint)performanceModulSwitches;
    performanceModulSwitches._0_4_ = (uint)performanceModulSwitches + 1;
    performanceModulSwitches._4_4_ = performanceModulSwitches._4_4_ + (uint)bVar2;
    if ((int)((performanceModulSwitches._4_4_ - performanceOverallModulSwitches._4_4_) -
             (uint)((uint)performanceModulSwitches < (uint)performanceOverallModulSwitches)) < 0 ==
        (SBORROW4(performanceModulSwitches._4_4_,performanceOverallModulSwitches._4_4_) !=
        SBORROW4(performanceModulSwitches._4_4_ - performanceOverallModulSwitches._4_4_,
                 (uint)((uint)performanceModulSwitches < (uint)performanceOverallModulSwitches)))) {
      performanceTest = '\0';
      performanceTestEnded = 1;
    }
  }
  if (*(uint *)(this + 0x50) == 0) {
    return;
  }
  uVar1 = 0;
  do {
    if (*(uint *)(*(int *)(this + 0x54) + uVar1 * 4) == param_1) {
      *(undefined4 *)(this + 0x60) = *(undefined4 *)(*(int *)(this + 0x48) + uVar1 * 4);
      *(uint *)(this + 0x3c) = (uint)(*(int *)(this + 0x18) != 0);
      *(uint *)(this + 0x5c) = param_1;
      return;
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < *(uint *)(this + 0x50));
  return;
}

// ===== AbyssEngine::ApplicationManager::SetApplicationModule  @0x0008cda0  (14 bytes)
/* AbyssEngine::ApplicationManager::SetApplicationModule(AbyssEngine::IApplicationModule*) */

void __thiscall
AbyssEngine::ApplicationManager::SetApplicationModule
          (ApplicationManager *this,IApplicationModule *param_1)

{
  *(IApplicationModule **)(this + 0x60) = param_1;
  *(uint *)(this + 0x3c) = (uint)(*(int *)(this + 0x18) != 0);
  return;
}

// ===== AbyssEngine::ApplicationManager::GetCurrentApplicationModule  @0x0008cdae  (4 bytes)
/* AbyssEngine::ApplicationManager::GetCurrentApplicationModule() const */

undefined4 __thiscall
AbyssEngine::ApplicationManager::GetCurrentApplicationModule(ApplicationManager *this)

{
  return *(undefined4 *)(this + 0x5c);
}

// ===== AbyssEngine::ApplicationManager::GetApplicationModule  @0x0008cdb2  (44 bytes)
/* AbyssEngine::ApplicationManager::GetApplicationModule(unsigned int) */

undefined4 __thiscall
AbyssEngine::ApplicationManager::GetApplicationModule(ApplicationManager *this,uint param_1)

{
  uint uVar1;
  
  if (*(uint *)(this + 0x50) != 0) {
    uVar1 = 0;
    do {
      if (*(uint *)(*(int *)(this + 0x54) + uVar1 * 4) == param_1) {
        return *(undefined4 *)(*(int *)(this + 0x48) + uVar1 * 4);
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(this + 0x50));
  }
  return 0;
}

// ===== AbyssEngine::ApplicationManager::Quit  @0x0008cdde  (8 bytes)
/* AbyssEngine::ApplicationManager::Quit() */

void __thiscall AbyssEngine::ApplicationManager::Quit(ApplicationManager *this)

{
  if (*(code **)(this + 0x1c) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0008cde2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(this + 0x1c))();
    return;
  }
  return;
}

// ===== AbyssEngine::ApplicationManager::GetApplicationVersionString  @0x0008cde8  (16 bytes)
/* AbyssEngine::ApplicationManager::GetApplicationVersionString() */

void __thiscall
AbyssEngine::ApplicationManager::GetApplicationVersionString(ApplicationManager *this)

{
  String::String((String *)this,"",false);
  return;
}

// ===== AbyssEngine::ApplicationManager::SetApplicationData  @0x0008cdfc  (4 bytes)
/* AbyssEngine::ApplicationManager::SetApplicationData(void*) */

void __thiscall
AbyssEngine::ApplicationManager::SetApplicationData(ApplicationManager *this,void *param_1)

{
  *(void **)(this + 100) = param_1;
  return;
}

// ===== AbyssEngine::ApplicationManager::GetApplicationData  @0x0008ce00  (4 bytes)
/* AbyssEngine::ApplicationManager::GetApplicationData() */

undefined4 __thiscall AbyssEngine::ApplicationManager::GetApplicationData(ApplicationManager *this)

{
  return *(undefined4 *)(this + 100);
}

// ===== AbyssEngine::ApplicationManager::GetEngine  @0x0008ce04  (6 bytes)
/* AbyssEngine::ApplicationManager::GetEngine() */

undefined4 __thiscall AbyssEngine::ApplicationManager::GetEngine(ApplicationManager *this)

{
  return *(undefined4 *)(this + 0xa8);
}

// ===== AbyssEngine::ApplicationManager::Suspend  @0x0008ce0a  (48 bytes)
/* AbyssEngine::ApplicationManager::Suspend() */

void __thiscall AbyssEngine::ApplicationManager::Suspend(ApplicationManager *this)

{
  undefined4 uVar1;
  
  if (1 < *(int *)(this + 0x3c) - 3U) {
    if (*(int **)(this + 0x18) == (int *)0x0) {
      return;
    }
    (**(code **)(**(int **)(this + 0x18) + 0x3c))();
    if (*(Engine **)(this + 0xa8) != (Engine *)0x0) {
      Engine::Suspend(*(Engine **)(this + 0xa8));
    }
    uVar1 = *(undefined4 *)(this + 0x3c);
    *(undefined4 *)(this + 0x3c) = 3;
    *(undefined4 *)(this + 0x40) = uVar1;
  }
  return;
}

// ===== AbyssEngine::ApplicationManager::Resume  @0x0008ce3a  (52 bytes)
/* AbyssEngine::ApplicationManager::Resume(bool) */

void AbyssEngine::ApplicationManager::Resume(bool param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (*(int *)(uVar1 + 0x3c) == 3) {
    if (*(int **)(uVar1 + 0x18) == (int *)0x0) {
      return;
    }
    (**(code **)(**(int **)(uVar1 + 0x18) + 0x40))();
    if (*(Engine **)(uVar1 + 0xa8) != (Engine *)0x0) {
      Engine::Resume(*(Engine **)(uVar1 + 0xa8));
    }
    *(undefined4 *)(uVar1 + 0x80) = 0;
    *(undefined4 *)(uVar1 + 0x84) = 0;
    *(undefined4 *)(uVar1 + 0xa0) = 0;
    *(undefined4 *)(uVar1 + 0xa4) = 0;
    *(undefined4 *)(uVar1 + 0x3c) = 4;
  }
  return;
}

// ===== AbyssEngine::ApplicationManager::SetExitCallback  @0x0008ce6e  (4 bytes)
/* AbyssEngine::ApplicationManager::SetExitCallback(void (*)()) */

void __thiscall
AbyssEngine::ApplicationManager::SetExitCallback(ApplicationManager *this,_func_void *param_1)

{
  *(_func_void **)(this + 0x1c) = param_1;
  return;
}

// ===== AbyssEngine::ApplicationManager::SetLoadingCallback  @0x0008ce72  (6 bytes)
/* AbyssEngine::ApplicationManager::SetLoadingCallback(void (*)(AbyssEngine::PaintCanvas*, int,
   void*), void*) */

void __thiscall
AbyssEngine::ApplicationManager::SetLoadingCallback
          (ApplicationManager *this,_func_void_PaintCanvas_ptr_int_void_ptr *param_1,void *param_2)

{
  *(_func_void_PaintCanvas_ptr_int_void_ptr **)(this + 0x20) = param_1;
  *(void **)(this + 0x24) = param_2;
  return;
}

// ===== AbyssEngine::ApplicationManager::LoadingCallbackShow  @0x0008ce78  (10 bytes)
/* AbyssEngine::ApplicationManager::LoadingCallbackShow(int, void*) */

void AbyssEngine::ApplicationManager::LoadingCallbackShow(int param_1,void *param_2)

{
  if (*(code **)(param_1 + 0x20) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0008ce7e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(param_1 + 0x20))(*(undefined4 *)param_1);
    return;
  }
  return;
}

// ===== AbyssEngine::ApplicationManager::SetResumeCallback  @0x0008ce82  (6 bytes)
/* AbyssEngine::ApplicationManager::SetResumeCallback(bool (*)(AbyssEngine::PaintCanvas*, void*),
   void*) */

void __thiscall
AbyssEngine::ApplicationManager::SetResumeCallback
          (ApplicationManager *this,_func_bool_PaintCanvas_ptr_void_ptr *param_1,void *param_2)

{
  *(_func_bool_PaintCanvas_ptr_void_ptr **)(this + 0x28) = param_1;
  *(void **)(this + 0x2c) = param_2;
  return;
}

// ===== AbyssEngine::ApplicationManager::CheatSetCallback  @0x0008ce88  (14 bytes)
/* AbyssEngine::ApplicationManager::CheatSetCallback(void (*)(int, void*), void*) */

void __thiscall
AbyssEngine::ApplicationManager::CheatSetCallback
          (ApplicationManager *this,_func_void_int_void_ptr *param_1,void *param_2)

{
  if (*(CheatHandler **)(this + 0x30) == (CheatHandler *)0x0) {
    return;
  }
  CheatHandler::SetCheatFunc(*(CheatHandler **)(this + 0x30),param_1,param_2);
  return;
}

// ===== AbyssEngine::ApplicationManager::CheatAddCode  @0x0008ce94  (14 bytes)
/* AbyssEngine::ApplicationManager::CheatAddCode(AbyssEngine::String const&, int) */

void AbyssEngine::ApplicationManager::CheatAddCode(String *param_1,int param_2)

{
  int in_r2;
  
  if (*(CheatHandler **)(param_1 + 0x30) == (CheatHandler *)0x0) {
    return;
  }
  CheatHandler::AddCheatCode(*(CheatHandler **)(param_1 + 0x30),(String *)param_2,in_r2);
  return;
}

// ===== AbyssEngine::ApplicationManager::CheatEnable  @0x0008cea0  (6 bytes)
/* AbyssEngine::ApplicationManager::CheatEnable(bool) */

void __thiscall AbyssEngine::ApplicationManager::CheatEnable(ApplicationManager *this,bool param_1)

{
  this[0x34] = (ApplicationManager)param_1;
  return;
}

// ===== AbyssEngine::ApplicationManager::CheatUpdate  @0x0008cea6  (18 bytes)
/* AbyssEngine::ApplicationManager::CheatUpdate(unsigned short) */

void AbyssEngine::ApplicationManager::CheatUpdate(ushort param_1)

{
  CheatHandler *this;
  ushort in_r1;
  
  if ((*(char *)(param_1 + 0x34) != '\0') &&
     (this = *(CheatHandler **)(param_1 + 0x30), this != (CheatHandler *)0x0)) {
    CheatHandler::Update(this,in_r1);
    return;
  }
  return;
}

// ===== AbyssEngine::ApplicationManager::ConfigReadFile  @0x0008ceb8  (66 bytes)
/* AbyssEngine::ApplicationManager::ConfigReadFile(AbyssEngine::String) */

void __thiscall
AbyssEngine::ApplicationManager::ConfigReadFile(ApplicationManager *this,String *param_2)

{
  ConfigReader *pCVar1;
  String aSStack_1c [8];
  int local_14;
  
  local_14 = __stack_chk_guard;
  pCVar1 = *(ConfigReader **)(this + 0x38);
  if (pCVar1 != (ConfigReader *)0x0) {
    String::String(aSStack_1c,param_2,false);
    ConfigReader::ParseFile(pCVar1,aSStack_1c);
    String::~String(aSStack_1c);
  }
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::ApplicationManager::ConfigRegisterTokenReadFunction  @0x0008cf10  (80 bytes)
/* AbyssEngine::ApplicationManager::ConfigRegisterTokenReadFunction(AbyssEngine::String, void
   (*)(AbyssEngine::ConfigReader*, void*), void*) */

void __thiscall
AbyssEngine::ApplicationManager::ConfigRegisterTokenReadFunction
          (ApplicationManager *this,String *param_2,undefined4 param_3,undefined4 param_4)

{
  ConfigReader *pCVar1;
  String aSStack_24 [8];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  pCVar1 = *(ConfigReader **)(this + 0x38);
  if (pCVar1 != (ConfigReader *)0x0) {
    String::String(aSStack_24,param_2,false);
    ConfigReader::RegisterTokenReadFunction(pCVar1,aSStack_24,param_3,param_4);
    String::~String(aSStack_24);
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::ApplicationManager::ConfigRegisterAction  @0x0008cf78  (104 bytes)
/* AbyssEngine::ApplicationManager::ConfigRegisterAction(long long, long long) */

void AbyssEngine::ApplicationManager::ConfigRegisterAction(longlong param_1,longlong param_2)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined4 in_stack_00000000;
  undefined4 in_stack_00000004;
  
  iVar1 = (int)param_1;
  iVar3 = *(int *)(iVar1 + 0x88) + 1;
  *(int *)(iVar1 + 0x90) = iVar3;
  pvVar2 = realloc(*(void **)(iVar1 + 0x8c),iVar3 * 8);
  *(void **)(iVar1 + 0x8c) = pvVar2;
  iVar3 = *(int *)(iVar1 + 0x88);
  *(int *)((int)pvVar2 + iVar3 * 8) = (int)param_2;
  *(int *)((int)pvVar2 + iVar3 * 8 + 4) = (int)((ulonglong)param_2 >> 0x20);
  *(int *)(iVar1 + 0x88) = *(int *)(iVar1 + 0x90);
  iVar3 = *(int *)(iVar1 + 0x90) + 1;
  *(int *)(iVar1 + 0x90) = iVar3;
  pvVar2 = realloc(pvVar2,iVar3 * 8);
  *(void **)(iVar1 + 0x8c) = pvVar2;
  iVar3 = *(int *)(iVar1 + 0x88);
  *(undefined4 *)((int)pvVar2 + iVar3 * 8) = in_stack_00000000;
  *(undefined4 *)((int)pvVar2 + iVar3 * 8 + 4) = in_stack_00000004;
  *(undefined4 *)(iVar1 + 0x88) = *(undefined4 *)(iVar1 + 0x90);
  return;
}

// ===== AbyssEngine::ApplicationManager::ConfigGetKeysForAction  @0x0008cfe0  (198 bytes)
/* AbyssEngine::ApplicationManager::ConfigGetKeysForAction(long long) */

undefined8 AbyssEngine::ApplicationManager::ConfigGetKeysForAction(longlong param_1)

{
  int iVar1;
  undefined4 *puVar2;
  String *this;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  uint in_r2;
  uint in_r3;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint *puVar10;
  
  uVar5 = (uint)((ulonglong)param_1 >> 0x20);
  iVar1 = (int)param_1;
  uVar6 = *(uint *)(iVar1 + 0x88);
  puVar10 = (uint *)0x0;
  if (uVar6 != 0) {
    iVar7 = 8;
    uVar9 = 0;
    puVar10 = (uint *)0x0;
    do {
      iVar8 = *(int *)(iVar1 + 0x8c);
      iVar4 = iVar8 + iVar7;
      uVar5 = *(uint *)(iVar4 + -8) ^ in_r2 | *(uint *)(iVar4 + -4) ^ in_r3;
      if (uVar5 == 0) {
        if (puVar10 == (uint *)0x0) {
          puVar10 = operator_new(0xc);
          puVar2 = operator_new__(4);
          puVar10[1] = (uint)puVar2;
          puVar10[2] = 1;
          *puVar2 = 0;
          *puVar10 = 0;
        }
        this = operator_new(8);
        String::String(this,(String *)(*(int *)(iVar1 + 0x10) + *(int *)(iVar8 + iVar7) * 0xc + 4),
                       false);
        puVar10[2] = *puVar10 + 1;
        pvVar3 = realloc((void *)puVar10[1],(*puVar10 + 1) * 4);
        puVar10[1] = (uint)pvVar3;
        uVar5 = *puVar10;
        *(String **)((int)pvVar3 + uVar5 * 4) = this;
        *puVar10 = puVar10[2];
        uVar6 = *(uint *)(iVar1 + 0x88);
      }
      uVar9 = uVar9 + 2;
      iVar7 = iVar7 + 0x10;
    } while (uVar9 < uVar6);
  }
  return CONCAT44(uVar5,puVar10);
}

// ===== AbyssEngine::ApplicationManager::CheckForOrientationChange  @0x0008d0bc  (258 bytes)
/* AbyssEngine::ApplicationManager::CheckForOrientationChange() */

void __thiscall AbyssEngine::ApplicationManager::CheckForOrientationChange(ApplicationManager *this)

{
  double dVar1;
  
  dVar1 = *(double *)(*(int *)(this + 0xa8) + 0x4a0);
  if (((int)((uint)(dVar1 < -0.5) << 0x1f) < 0) && (*(int *)(*(PaintCanvas **)this + 0x30) == 0)) {
    orientationChangeTimer =
         (*(int *)(this + 0x70) - *(int *)(this + 0x78)) + orientationChangeTimer;
    if (orientationChangeTimer < 0xfb) {
      return;
    }
    PaintCanvas::SetGameOrientation(*(PaintCanvas **)this,1);
  }
  else {
    if (0.5 < dVar1) {
      if (*(int *)(*(PaintCanvas **)this + 0x30) == 1) {
        orientationChangeTimer =
             (*(int *)(this + 0x70) - *(int *)(this + 0x78)) + orientationChangeTimer;
        if (0xfa < orientationChangeTimer) {
          PaintCanvas::SetGameOrientation(*(PaintCanvas **)this,0);
          orientationChangeTimer = 0;
          return;
        }
        return;
      }
      if (*(int *)(*(PaintCanvas **)this + 0x30) == 3) {
        orientationChangeTimer =
             (*(int *)(this + 0x70) - *(int *)(this + 0x78)) + orientationChangeTimer;
        if (0xfa < orientationChangeTimer) {
          PaintCanvas::SetGameOrientation(*(PaintCanvas **)this,2);
          orientationChangeTimer = 0;
          return;
        }
        return;
      }
    }
    if (((int)((uint)(dVar1 < -0.5) << 0x1f) < 0) && (*(int *)(*(PaintCanvas **)this + 0x30) == 2))
    {
      orientationChangeTimer =
           (*(int *)(this + 0x70) - *(int *)(this + 0x78)) + orientationChangeTimer;
      if (orientationChangeTimer < 0xfb) {
        return;
      }
      PaintCanvas::SetGameOrientation(*(PaintCanvas **)this,3);
    }
  }
  orientationChangeTimer = 0;
  return;
}

// ===== AbyssEngine::ApplicationManager::GetElapsedTimeMillis  @0x0008d1e4  (18 bytes)
/* AbyssEngine::ApplicationManager::GetElapsedTimeMillis() */

undefined8 __thiscall
AbyssEngine::ApplicationManager::GetElapsedTimeMillis(ApplicationManager *this)

{
  return CONCAT44((*(int *)(this + 0x74) - *(int *)(this + 0x7c)) -
                  (uint)(*(uint *)(this + 0x70) < *(uint *)(this + 0x78)),
                  *(uint *)(this + 0x70) - *(uint *)(this + 0x78));
}

// ===== AbyssEngine::ApplicationManager::OnUpdate  @0x0008d1f8  (4276 bytes)
/* AbyssEngine::ApplicationManager::OnUpdate(long long) */

void AbyssEngine::ApplicationManager::OnUpdate(longlong param_1)

{
  ApplicationManager *pAVar1;
  ApplicationManager *this;
  Engine *this_00;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  undefined4 extraout_r1_05;
  undefined4 extraout_r1_06;
  undefined4 extraout_r1_07;
  uint uVar8;
  uint uVar9;
  undefined4 extraout_r1_08;
  undefined4 extraout_r1_09;
  undefined4 extraout_r1_10;
  undefined4 extraout_r1_11;
  undefined4 extraout_r1_12;
  undefined4 extraout_r1_13;
  uint in_r2;
  uint uVar10;
  int in_r3;
  int iVar11;
  PaintCanvas *pPVar12;
  PaintCanvas *this_01;
  bool bVar13;
  float fVar14;
  undefined4 local_a0 [2];
  String aSStack_98 [8];
  undefined4 local_90 [2];
  String aSStack_88 [8];
  undefined4 local_80 [2];
  String aSStack_78 [8];
  undefined4 local_70 [2];
  String aSStack_68 [8];
  undefined4 local_60 [2];
  undefined4 local_58 [2];
  undefined4 local_50 [2];
  undefined4 local_48 [2];
  undefined4 local_40 [2];
  String aSStack_38 [8];
  AbyssEngine aAStack_30 [8];
  int local_28;
  
  this = (ApplicationManager *)param_1;
  local_28 = __stack_chk_guard;
  Engine::PreUpdate();
  if (Engine::CheckForOrientationChange != '\0') {
    CheckForOrientationChange(this);
  }
  if ((*(int *)(this + 0xac) != 0) && (this[0xb0] != (ApplicationManager)0x0)) {
    AESoundRessource::checkLooping();
  }
  switch(*(undefined4 *)(this + 0x3c)) {
  case 0:
    if (0 < SwapCounter) {
      SwapCounter = SwapCounter + -1;
      Engine::ClearBuffer(*(Engine **)(this + 0xa8),0);
      if (__stack_chk_guard == local_28) {
        Engine::SwapBuffer(*(Engine **)(this + 0xa8));
        return;
      }
      goto LAB_0008e2ea;
    }
    piVar5 = *(int **)(this + 0x60);
    if (piVar5 != (int *)0x0) {
      *(int **)(this + 0x18) = piVar5;
      *(undefined4 *)(this + 0x60) = 0;
      if ((*(int *)(this + 0x20) != 0) && (iVar3 = (**(code **)(*piVar5 + 0x44))(), iVar3 == 1)) {
        (**(code **)(this + 0x20))(*(undefined4 *)this,0xffffffff,*(undefined4 *)(this + 0x24));
      }
    }
    if (*(int **)(this + 0x18) != (int *)0x0) {
      iVar3 = (**(code **)(**(int **)(this + 0x18) + 8))();
      if ((*(int *)(this + 0x20) != 0) &&
         (iVar11 = (**(code **)(**(int **)(this + 0x18) + 0x44))(), iVar11 == 1)) {
        (**(code **)(this + 0x20))(*(undefined4 *)this,iVar3,*(undefined4 *)(this + 0x24));
      }
      if (iVar3 == 0) {
        *(undefined4 *)(this + 0x3c) = 5;
        *(uint *)(this + 0x70) = in_r2;
        *(int *)(this + 0x74) = in_r3;
        *(uint *)(this + 0x78) = in_r2 - 1;
        *(uint *)(this + 0x7c) = in_r3 + ((in_r2 != 0) - 1);
        *(undefined4 *)(this + 0x68) = 0;
        *(undefined4 *)(this + 0x6c) = 0;
        *(undefined4 *)(this + 0x80) = 0;
        *(undefined4 *)(this + 0x84) = 0;
        *(undefined4 *)(this + 0xa0) = 0;
        *(undefined4 *)(this + 0xa4) = 0;
        loadTexture = 0;
        loadMesh = 0;
      }
      else {
        uVar8 = *(uint *)(this + 0x70);
        iVar3 = *(int *)(this + 0x74);
        *(uint *)(this + 0x78) = uVar8;
        *(int *)(this + 0x7c) = iVar3;
        *(uint *)(this + 0x70) = in_r2;
        *(int *)(this + 0x74) = in_r3;
        uVar10 = *(uint *)(this + 0x68);
        *(uint *)(this + 0x68) = (in_r2 - uVar8) + uVar10;
        *(uint *)(this + 0x6c) =
             ((in_r3 - iVar3) - (uint)(in_r2 < uVar8)) +
             *(int *)(this + 0x6c) + (uint)CARRY4(in_r2 - uVar8,uVar10);
      }
    }
    break;
  case 1:
    if (*(int **)(this + 0x18) != (int *)0x0) {
      (**(code **)(**(int **)(this + 0x18) + 0xc))();
      Engine::ResetLightParam(*(Engine **)(this + 0xa8));
      SwapCounter = Engine::SwapCounter;
      *(undefined4 *)(this + 0x18) = 0;
      *(undefined4 *)(this + 0x3c) = 0;
    }
    break;
  case 4:
    *(uint *)(this + 0x70) = in_r2;
    *(int *)(this + 0x74) = in_r3;
    *(uint *)(this + 0x78) = in_r2 - 1;
    *(uint *)(this + 0x7c) = in_r3 + ((in_r2 != 0) - 1);
    uVar8 = *(uint *)(this + 0x68);
    *(uint *)(this + 0x68) = uVar8 + 1;
    *(uint *)(this + 0x6c) = *(int *)(this + 0x6c) + (uint)(0xfffffffe < uVar8);
    *(undefined4 *)(this + 0x3c) = *(undefined4 *)(this + 0x40);
    *(undefined4 *)(this + 0x80) = 0;
    *(undefined4 *)(this + 0x84) = 0;
    *(undefined4 *)(this + 0xa0) = 0;
    *(undefined4 *)(this + 0xa4) = 0;
    break;
  case 5:
    if (performanceTest != '\0') {
      bVar13 = 0xfffffffe < (uint)performanceFrameCounter;
      performanceFrameCounter._0_4_ = (uint)performanceFrameCounter + 1;
      performanceFrameCounter._4_4_ = performanceFrameCounter._4_4_ + (uint)bVar13;
      uVar8 = *(uint *)(this + 0x70) - *(uint *)(this + 0x78);
      bVar13 = CARRY4(uVar8,(uint)performanceTime);
      performanceTime._0_4_ = uVar8 + (uint)performanceTime;
      performanceTime._4_4_ =
           performanceTime._4_4_ +
           ((*(int *)(this + 0x74) - *(int *)(this + 0x7c)) -
           (uint)(*(uint *)(this + 0x70) < *(uint *)(this + 0x78))) + (uint)bVar13;
    }
    if (*(int *)(this + 0x18) != 0) {
      pAVar1 = this + 0x70;
      fpsTimer = (*(int *)pAVar1 - *(int *)(this + 0x78)) + fpsTimer;
      iVar3 = fpsCounter + 1;
      fpsCounter = iVar3;
      if (1000 < fpsTimer) {
        fpsCounter = 0;
        fpsTimer = fpsTimer + -1000;
        currentFps = iVar3;
      }
      if (Engine::enableShader != '\0') {
        this_00 = (Engine *)FUN_00261aa4();
        iVar3 = Engine::IsPostEffectActivated(this_00);
        if (iVar3 == 1) {
          PostEffectFlag = '\x01';
          PaintCanvas::StartDraw2FBO(*(PaintCanvas **)this);
        }
        if (Engine::enableShader != '\0') {
          PaintCanvas::CheckNUseRefractFBO(SUB41(*(undefined4 *)this,0));
        }
      }
      (**(code **)(**(int **)(this + 0x18) + 0x30))();
      iVar3 = *(int *)(this + 0xa8);
      *(undefined4 *)(iVar3 + 0x58) = 0;
      *(undefined4 *)(iVar3 + 0x5c) = 0;
      *(undefined4 *)(iVar3 + 0x48) = 0;
      *(undefined4 *)(iVar3 + 0x4c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4)
      ;
      *(undefined4 *)(iVar3 + 0x50) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8)
      ;
      *(undefined4 *)(iVar3 + 0x54) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc)
      ;
      *(undefined4 *)(*(int *)this + 4) = 0;
      (**(code **)(**(int **)(this + 0x18) + 0x34))();
      if (((PostEffectFlag != '\0') && (Engine::enableShader != '\0')) &&
         (iVar3 = Engine::IsPostEffectActivated(*(Engine **)(this + 0xa8)), iVar3 == 1)) {
        PostEffectFlag = '\0';
        PaintCanvas::StopDraw2FBO(*(PaintCanvas **)this);
      }
      if ((*(code **)(this + 0x28) == (code *)0x0) ||
         (iVar3 = (**(code **)(this + 0x28))(*(undefined4 *)this,*(undefined4 *)(this + 0x2c)),
         iVar3 == 0)) {
        (**(code **)(**(int **)(this + 0x18) + 0x38))();
      }
      iVar3 = *(int *)(this + 0xa8);
      if (*(char *)(iVar3 + 100) != '\0') {
        *(undefined1 *)(iVar3 + 0xee) = 0;
        *(undefined1 *)(iVar3 + 0xec) = 0;
        PaintCanvas::SetColor((uchar)*(undefined4 *)this,'\0',0xff,'\0');
        pPVar12 = *(PaintCanvas **)this;
        uVar8 = *(uint *)(*(int *)(this + 0xa8) + 0x68);
        String::String(aSStack_38,"fps: ",false);
        local_40[0] = 0;
        String::Set(CONCAT44(extraout_r1,local_40));
        operator+(aAStack_30,aSStack_38,(String *)local_40);
        PaintCanvas::DrawString(pPVar12,uVar8,aAStack_30,5,5,false);
        String::~String((String *)aAStack_30);
        String::~String((String *)local_40);
        String::~String(aSStack_38);
        pPVar12 = *(PaintCanvas **)this;
        uVar8 = *(uint *)(*(int *)(this + 0xa8) + 0x68);
        String::String(aSStack_38,"t3D: ",false);
        local_40[0] = 0;
        String::Set(CONCAT44(extraout_r1_00,local_40));
        operator+(aAStack_30,aSStack_38,(String *)local_40);
        iVar3 = PaintCanvas::GetTextHeight
                          (*(PaintCanvas **)this,*(uint *)(*(int *)(this + 0xa8) + 0x68));
        PaintCanvas::DrawString(pPVar12,uVar8,aAStack_30,5,iVar3 + 10,false);
        String::~String((String *)aAStack_30);
        String::~String((String *)local_40);
        String::~String(aSStack_38);
        pPVar12 = *(PaintCanvas **)this;
        uVar8 = *(uint *)(*(int *)(this + 0xa8) + 0x68);
        String::String(aSStack_38,"t2D: ",false);
        local_40[0] = 0;
        String::Set(CONCAT44(extraout_r1_01,local_40));
        operator+(aAStack_30,aSStack_38,(String *)local_40);
        iVar3 = PaintCanvas::GetTextHeight
                          (*(PaintCanvas **)this,*(uint *)(*(int *)(this + 0xa8) + 0x68));
        PaintCanvas::DrawString(pPVar12,uVar8,aAStack_30,5,iVar3 * 2 + 0xf,false);
        String::~String((String *)aAStack_30);
        String::~String((String *)local_40);
        String::~String(aSStack_38);
        pPVar12 = *(PaintCanvas **)this;
        uVar8 = *(uint *)(*(int *)(this + 0xa8) + 0x68);
        String::String(aSStack_38,"d3D: ",false);
        local_40[0] = 0;
        String::Set(CONCAT44(extraout_r1_02,local_40));
        operator+(aAStack_30,aSStack_38,(String *)local_40);
        iVar3 = PaintCanvas::GetTextHeight
                          (*(PaintCanvas **)this,*(uint *)(*(int *)(this + 0xa8) + 0x68));
        PaintCanvas::DrawString(pPVar12,uVar8,aAStack_30,5,iVar3 * 3 + 0x14,false);
        String::~String((String *)aAStack_30);
        String::~String((String *)local_40);
        String::~String(aSStack_38);
        pPVar12 = *(PaintCanvas **)this;
        uVar8 = *(uint *)(*(int *)(this + 0xa8) + 0x68);
        String::String(aSStack_38,"d2D: ",false);
        local_40[0] = 0;
        String::Set(CONCAT44(extraout_r1_03,local_40));
        operator+(aAStack_30,aSStack_38,(String *)local_40);
        iVar3 = PaintCanvas::GetTextHeight
                          (*(PaintCanvas **)this,*(uint *)(*(int *)(this + 0xa8) + 0x68));
        PaintCanvas::DrawString(pPVar12,uVar8,aAStack_30,5,iVar3 * 4 + 0x19,false);
        String::~String((String *)aAStack_30);
        String::~String((String *)local_40);
        String::~String(aSStack_38);
        pPVar12 = *(PaintCanvas **)this;
        uVar8 = *(uint *)(*(int *)(this + 0xa8) + 0x68);
        String::String(aSStack_38,"vfC: ",false);
        local_40[0] = 0;
        String::Set(CONCAT44(extraout_r1_04,local_40));
        operator+(aAStack_30,aSStack_38,(String *)local_40);
        iVar3 = PaintCanvas::GetTextHeight
                          (*(PaintCanvas **)this,*(uint *)(*(int *)(this + 0xa8) + 0x68));
        PaintCanvas::DrawString(pPVar12,uVar8,aAStack_30,5,iVar3 * 5 + 0x1e,false);
        String::~String((String *)aAStack_30);
        String::~String((String *)local_40);
        String::~String(aSStack_38);
        pPVar12 = *(PaintCanvas **)this;
        uVar8 = *(uint *)(*(int *)(this + 0xa8) + 0x68);
        String::String((String *)local_48,"T: ",false);
        local_50[0] = 0;
        String::Set(CONCAT44(extraout_r1_05,local_50));
        operator+((AbyssEngine *)local_40,(String *)local_48,(String *)local_50);
        String::String((String *)local_58,"  ",false);
        operator+((AbyssEngine *)aSStack_38,(String *)local_40,(String *)local_58);
        local_60[0] = 0;
        String::Set(CONCAT44(extraout_r1_06,local_60));
        operator+(aAStack_30,aSStack_38,(String *)local_60);
        iVar3 = PaintCanvas::GetTextHeight
                          (*(PaintCanvas **)this,*(uint *)(*(int *)(this + 0xa8) + 0x68));
        PaintCanvas::DrawString(pPVar12,uVar8,aAStack_30,5,iVar3 * 6 + 0x23,false);
        String::~String((String *)aAStack_30);
        String::~String((String *)local_60);
        String::~String(aSStack_38);
        String::~String((String *)local_58);
        String::~String((String *)local_40);
        String::~String((String *)local_50);
        String::~String((String *)local_48);
        pPVar12 = *(PaintCanvas **)this;
        uVar8 = *(uint *)(*(int *)(this + 0xa8) + 0x68);
        String::String(aSStack_38,"vbo3D: ",false);
        local_40[0] = 0;
        String::Set(CONCAT44(extraout_r1_07,local_40));
        operator+(aAStack_30,aSStack_38,(String *)local_40);
        iVar3 = PaintCanvas::GetTextHeight
                          (*(PaintCanvas **)this,*(uint *)(*(int *)(this + 0xa8) + 0x68));
        PaintCanvas::DrawString(pPVar12,uVar8,aAStack_30,5,iVar3 * 7 + 0x23,false);
        String::~String((String *)aAStack_30);
        String::~String((String *)local_40);
        String::~String(aSStack_38);
        pPVar12 = *(PaintCanvas **)this;
        uVar8 = *(uint *)(*(int *)(this + 0xa8) + 0x68);
        String::String((String *)local_48,"vRam: ",false);
        local_50[0] = 0;
        String::Set(CONCAT44(*(int *)(*(int *)(this + 0xa8) + 0x60) >> 0x1f,local_50));
        operator+((AbyssEngine *)local_40,(String *)local_48,(String *)local_50);
        String::String((String *)local_58," + ",false);
        operator+((AbyssEngine *)aSStack_38,(String *)local_40,(String *)local_58);
        local_60[0] = 0;
        String::Set(CONCAT44(Engine::vboSize >> 0x1f,local_60));
        operator+(aAStack_30,aSStack_38,(String *)local_60);
        iVar3 = PaintCanvas::GetTextHeight
                          (*(PaintCanvas **)this,*(uint *)(*(int *)(this + 0xa8) + 0x68));
        PaintCanvas::DrawString(pPVar12,uVar8,aAStack_30,5,iVar3 * 8 + 0x23,false);
        String::~String((String *)aAStack_30);
        String::~String((String *)local_60);
        String::~String(aSStack_38);
        String::~String((String *)local_58);
        String::~String((String *)local_40);
        String::~String((String *)local_50);
        String::~String((String *)local_48);
        pPVar12 = *(PaintCanvas **)this;
        uVar8 = *(uint *)(*(int *)(this + 0xa8) + 0x68);
        fVar14 = (float)String::String(aSStack_38,"lodDist: ",false);
        local_40[0] = 0;
        String::Set(fVar14);
        operator+(aAStack_30,aSStack_38,(String *)local_40);
        iVar3 = PaintCanvas::GetTextHeight
                          (*(PaintCanvas **)this,*(uint *)(*(int *)(this + 0xa8) + 0x68));
        PaintCanvas::DrawString(pPVar12,uVar8,aAStack_30,5,iVar3 * 9 + 0x23,false);
        String::~String((String *)aAStack_30);
        String::~String((String *)local_40);
        String::~String(aSStack_38);
        pPVar12 = *(PaintCanvas **)this;
        uVar8 = *(uint *)(*(int *)(this + 0xa8) + 0x68);
        iVar3 = PaintCanvas::GetWidth();
        iVar11 = PaintCanvas::GetTextWidth
                           (*(PaintCanvas **)this,*(uint *)(*(int *)(this + 0xa8) + 0x68),
                            (String *)&Engine::vendor);
        PaintCanvas::DrawString
                  (pPVar12,uVar8,(String *)&Engine::vendor,(iVar3 - iVar11) / 2,5,false);
        pPVar12 = *(PaintCanvas **)this;
        uVar8 = *(uint *)(*(int *)(this + 0xa8) + 0x68);
        iVar3 = PaintCanvas::GetWidth();
        iVar11 = PaintCanvas::GetTextWidth
                           (*(PaintCanvas **)this,*(uint *)(*(int *)(this + 0xa8) + 0x68),
                            (String *)&Engine::renderer);
        iVar2 = PaintCanvas::GetTextHeight
                          (*(PaintCanvas **)this,*(uint *)(*(int *)(this + 0xa8) + 0x68));
        PaintCanvas::DrawString
                  (pPVar12,uVar8,(String *)&Engine::renderer,(iVar3 - iVar11) / 2,iVar2 + 10,false);
        if (Engine::enableShader == '\0') {
          iVar3 = *(int *)(this + 0xa8);
        }
        else {
          this_01 = *(PaintCanvas **)this;
          uVar8 = *(uint *)(*(int *)(this + 0xa8) + 0x68);
          String::String((String *)aAStack_30,"ES2",false);
          iVar3 = PaintCanvas::GetWidth();
          pPVar12 = *(PaintCanvas **)this;
          uVar10 = *(uint *)(*(int *)(this + 0xa8) + 0x68);
          String::String(aSStack_38,"ES2 ",false);
          iVar11 = PaintCanvas::GetTextWidth(pPVar12,uVar10,aSStack_38);
          PaintCanvas::DrawString(this_01,uVar8,aAStack_30,iVar3 - iVar11,5,false);
          String::~String(aSStack_38);
          String::~String((String *)aAStack_30);
          iVar11 = PaintCanvas::GetTextHeight
                             (*(PaintCanvas **)this,*(uint *)(*(int *)(this + 0xa8) + 0x68));
          iVar3 = *(int *)(this + 0xa8);
          if (*(int *)(iVar3 + 0x3c8) != 0) {
            iVar11 = iVar11 + 10;
            uVar8 = 0;
            do {
              if (*(int *)(*(int *)(iVar3 + 0x3cc) + uVar8 * 4) != 0) {
                uVar10 = *(uint *)(iVar3 + 0x68);
                pPVar12 = *(PaintCanvas **)this;
                local_40[0] = 0;
                String::Set(CONCAT44(uVar10,local_40));
                String::String((String *)local_48," ",false);
                operator+((AbyssEngine *)aSStack_38,(String *)local_40,(String *)local_48);
                String::String((String *)local_50,
                               (String *)
                               (*(int *)(*(int *)(*(int *)(this + 0xa8) + 0x504) + uVar8 * 4) + 0xc)
                               ,false);
                operator+(aAStack_30,aSStack_38,(String *)local_50);
                iVar3 = PaintCanvas::GetWidth();
                PaintCanvas::DrawString
                          (pPVar12,uVar10,(String *)aAStack_30,iVar3 + -300,iVar11,false);
                String::~String((String *)aAStack_30);
                String::~String((String *)local_50);
                String::~String(aSStack_38);
                String::~String((String *)local_48);
                String::~String((String *)local_40);
                iVar2 = PaintCanvas::GetTextHeight
                                  (*(PaintCanvas **)this,*(uint *)(*(int *)(this + 0xa8) + 0x68));
                iVar3 = *(int *)(this + 0xa8);
                iVar11 = iVar2 + iVar11 + 5;
              }
              uVar8 = uVar8 + 1;
            } while (uVar8 < *(uint *)(iVar3 + 0x3c8));
          }
        }
        *(undefined1 *)(iVar3 + 0xec) = 1;
        *(undefined1 *)(iVar3 + 0xee) = 1;
      }
      if (performanceTestEnded != '\0') {
        PaintCanvas::SetColor((uchar)*(undefined4 *)this,'\0',0xff,'\0');
        iVar2 = performanceTime._4_4_;
        uVar9 = (uint)performanceTime;
        iVar11 = triDrawn._4_4_;
        uVar10 = (uint)triDrawn;
        iVar3 = performanceFrameCounter._4_4_;
        uVar8 = (uint)performanceFrameCounter;
        String::String((String *)local_58,"PerfTest ended: ",false);
        local_60[0] = 0;
        iVar6 = __aeabi_ldivmod(uVar9,iVar2,1000,0);
        __aeabi_ldivmod(uVar10,iVar11,iVar6,iVar6 >> 0x1f);
        uVar7 = __aeabi_ldivmod((int)((ulonglong)uVar8 * 1000),
                                iVar3 * 1000 + (int)((ulonglong)uVar8 * 1000 >> 0x20),uVar9,iVar2);
        String::Set(CONCAT44(uVar7,local_60));
        operator+((AbyssEngine *)local_50,(String *)local_58,(String *)local_60);
        String::String(aSStack_68," / ",false);
        operator+((AbyssEngine *)local_48,(String *)local_50,aSStack_68);
        local_70[0] = 0;
        String::Set(CONCAT44(extraout_r1_08,local_70));
        operator+((AbyssEngine *)local_40,(String *)local_48,(String *)local_70);
        String::String(aSStack_78," / ",false);
        operator+((AbyssEngine *)aSStack_38,(String *)local_40,aSStack_78);
        local_80[0] = 0;
        String::Set(CONCAT44(extraout_r1_09,local_80));
        operator+(aAStack_30,aSStack_38,(String *)local_80);
        String::~String((String *)local_80);
        String::~String(aSStack_38);
        String::~String(aSStack_78);
        String::~String((String *)local_40);
        String::~String((String *)local_70);
        String::~String((String *)local_48);
        String::~String(aSStack_68);
        String::~String((String *)local_50);
        String::~String((String *)local_60);
        String::~String((String *)local_58);
        pPVar12 = *(PaintCanvas **)this;
        uVar8 = *(uint *)(*(int *)(this + 0xa8) + 0x68);
        iVar3 = PaintCanvas::GetWidth();
        iVar11 = PaintCanvas::GetTextWidth
                           (*(PaintCanvas **)this,*(uint *)(*(int *)(this + 0xa8) + 0x68),aAStack_30
                           );
        PaintCanvas::DrawString(pPVar12,uVar8,aAStack_30,iVar3 / 2 - iVar11 / 2,5,false);
        String::~String((String *)aAStack_30);
      }
      if (performanceTest != '\0') {
        iVar3 = *(int *)(this + 0xa8);
        uVar8 = *(int *)(iVar3 + 0x58) + *(int *)(iVar3 + 0x48);
        bVar13 = CARRY4(uVar8,(uint)triDrawn);
        uVar10 = uVar8 + (uint)triDrawn;
        uVar9 = *(int *)(iVar3 + 0x5c) + *(int *)(iVar3 + 0x4c);
        triDrawn._0_4_ = uVar10 + uVar9;
        triDrawn._4_4_ =
             ((int)uVar8 >> 0x1f) + triDrawn._4_4_ + (uint)bVar13 + ((int)uVar9 >> 0x1f) +
             (uint)CARRY4(uVar10,uVar9);
        PaintCanvas::SetColor((uchar)*(undefined4 *)this,'\0',0xff,'\0');
        iVar3 = performanceTime._4_4_;
        uVar8 = (uint)performanceTime;
        String::String(aSStack_68,"PerfTest (",false);
        local_70[0] = 0;
        __aeabi_ldivmod(uVar8,iVar3,1000,0);
        String::Set(CONCAT44(extraout_r1_10,local_70));
        operator+((AbyssEngine *)local_60,aSStack_68,(String *)local_70);
        String::String(aSStack_78,"/",false);
        operator+((AbyssEngine *)local_58,(String *)local_60,aSStack_78);
        local_80[0] = 0;
        String::Set(CONCAT44(extraout_r1_11,local_80));
        operator+((AbyssEngine *)local_50,(String *)local_58,(String *)local_80);
        String::String(aSStack_88,") : ",false);
        operator+((AbyssEngine *)local_48,(String *)local_50,aSStack_88);
        local_90[0] = 0;
        String::Set(CONCAT44(extraout_r1_12,local_90));
        operator+((AbyssEngine *)local_40,(String *)local_48,(String *)local_90);
        String::String(aSStack_98,"   ",false);
        operator+(aAStack_30,(String *)local_40,aSStack_98);
        local_a0[0] = 0;
        String::Set(CONCAT44(extraout_r1_13,local_a0));
        operator+((AbyssEngine *)aSStack_38,aAStack_30,(String *)local_a0);
        String::~String((String *)local_a0);
        String::~String((String *)aAStack_30);
        String::~String(aSStack_98);
        String::~String((String *)local_40);
        String::~String((String *)local_90);
        String::~String((String *)local_48);
        String::~String(aSStack_88);
        String::~String((String *)local_50);
        String::~String((String *)local_80);
        String::~String((String *)local_58);
        String::~String(aSStack_78);
        String::~String((String *)local_60);
        String::~String((String *)local_70);
        String::~String(aSStack_68);
        pPVar12 = *(PaintCanvas **)this;
        uVar8 = *(uint *)(*(int *)(this + 0xa8) + 0x68);
        iVar3 = PaintCanvas::GetWidth();
        PaintCanvas::DrawString(pPVar12,uVar8,aSStack_38,iVar3 / 2,5,false);
        uVar7 = PaintCanvas::GetWidth();
        local_48[0] = 0;
        String::Set(CONCAT44(uVar7,local_48));
        String::String((String *)local_50," / ",false);
        operator+((AbyssEngine *)local_40,(String *)local_48,(String *)local_50);
        uVar7 = PaintCanvas::GetHeight();
        local_58[0] = 0;
        String::Set(CONCAT44(uVar7,local_58));
        operator+(aAStack_30,(String *)local_40,(String *)local_58);
        String::operator=(aSStack_38,aAStack_30);
        String::~String((String *)aAStack_30);
        String::~String((String *)local_58);
        String::~String((String *)local_40);
        String::~String((String *)local_50);
        String::~String((String *)local_48);
        pPVar12 = *(PaintCanvas **)this;
        uVar8 = *(uint *)(*(int *)(this + 0xa8) + 0x68);
        iVar3 = PaintCanvas::GetWidth();
        iVar11 = PaintCanvas::GetTextHeight
                           (*(PaintCanvas **)this,*(uint *)(*(int *)(this + 0xa8) + 0x68));
        PaintCanvas::DrawString(pPVar12,uVar8,aSStack_38,iVar3 / 2,iVar11 + 10,false);
        String::~String(aSStack_38);
      }
      uVar8 = *(uint *)pAVar1;
      iVar3 = *(int *)(this + 0x74);
      *(uint *)(this + 0x78) = uVar8;
      *(int *)(this + 0x7c) = iVar3;
      *(uint *)pAVar1 = in_r2;
      *(int *)(this + 0x74) = in_r3;
      uVar10 = *(uint *)(this + 0x68);
      *(uint *)(this + 0x68) = (in_r2 - uVar8) + uVar10;
      *(uint *)(this + 0x6c) =
           ((in_r3 - iVar3) - (uint)(in_r2 < uVar8)) + *(int *)(this + 0x6c) +
           (uint)CARRY4(in_r2 - uVar8,uVar10);
    }
    break;
  case 6:
    pAVar1 = this + 0x68;
    uVar8 = *(uint *)pAVar1;
    iVar3 = *(int *)(this + 0x6c);
    if (uVar8 == 0 && iVar3 == 0) {
      iVar3 = PaintCanvas::WarmUpTexture();
      if (iVar3 == 0) {
        uVar8 = *(uint *)pAVar1;
        iVar3 = *(int *)(this + 0x6c);
      }
      else {
        *(undefined4 *)(this + 0x3c) = 5;
        *(uint *)(this + 0x70) = in_r2;
        *(int *)(this + 0x74) = in_r3;
        *(uint *)(this + 0x78) = in_r2 - 1;
        *(uint *)(this + 0x7c) = in_r3 + ((in_r2 != 0) - 1);
        uVar8 = 0;
        iVar3 = 0;
        *(undefined4 *)pAVar1 = 0;
        *(undefined4 *)(this + 0x6c) = 0;
        *(undefined4 *)(this + 0x80) = 0;
        *(undefined4 *)(this + 0x84) = 0;
        *(undefined4 *)(this + 0xa0) = 0;
        *(undefined4 *)(this + 0xa4) = 0;
      }
    }
    uVar9 = *(uint *)(this + 0x70);
    iVar11 = *(int *)(this + 0x74);
    *(uint *)(this + 0x70) = in_r2;
    *(int *)(this + 0x74) = in_r3;
    *(uint *)(this + 0x78) = uVar9;
    *(int *)(this + 0x7c) = iVar11;
    uVar10 = uVar8 + (in_r2 - uVar9);
    iVar3 = iVar3 + ((in_r3 - iVar11) - (uint)(in_r2 < uVar9)) + (uint)CARRY4(uVar8,in_r2 - uVar9);
    if ((int)(-(uint)(500 < uVar10) - iVar3) < 0 !=
        (SBORROW4(0,iVar3) != SBORROW4(-iVar3,(uint)(500 < uVar10)))) {
      iVar3 = 0;
      uVar10 = 0;
    }
    *(uint *)pAVar1 = uVar10;
    *(int *)(this + 0x6c) = iVar3;
    break;
  case 7:
    if ((loadTexture < *(uint *)(*(int *)this + 0x10)) ||
       (loadMesh < *(uint *)(*(int *)this + 0x24))) {
      if ((loadTexture == 0) &&
         ((*(int *)(this + 0x20) != 0 &&
          (iVar3 = (**(code **)(**(int **)(this + 0x18) + 0x44))(), iVar3 == 1)))) {
        (**(code **)(this + 0x20))(*(undefined4 *)this,0,*(undefined4 *)(this + 0x24));
      }
      if (loadTexture < *(uint *)(*(int *)this + 0x10)) {
        iVar3 = *(int *)(*(int *)(*(int *)this + 0x14) + loadTexture * 4);
        if ((iVar3 != 0) && (*(char *)(iVar3 + 0x11) == '\0')) {
          pcVar4 = (char *)String::GetAEChar((String *)(iVar3 + 4));
          TextureCreateFromFileIntern
                    (*(Engine **)(this + 0xa8),pcVar4,(_func_void_Image_ptr_void_ptr *)0x0,
                     (void *)0x0,(uint *)aAStack_30,*(float *)(iVar3 + 0xc),
                     (AELoadedTexture *)*(float *)(iVar3 + 0xc),SUB41(iVar3,0));
          if (pcVar4 != (char *)0x0) {
            operator_delete__(pcVar4);
          }
        }
        loadTexture = loadTexture + 1;
      }
      iVar3 = 10;
      uVar8 = loadMesh;
      do {
        if (uVar8 < *(uint *)(*(PaintCanvas **)this + 0x24)) {
          PaintCanvas::MeshConvertToVBO(*(PaintCanvas **)this,uVar8);
          uVar8 = loadMesh + 1;
          loadMesh = uVar8;
        }
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      iVar3 = *(int *)(this + 0x6c);
      uVar10 = *(uint *)(this + 0x68);
      uVar8 = *(uint *)(this + 0x70);
      iVar11 = *(int *)(this + 0x74);
    }
    else {
      *(undefined4 *)(this + 0x3c) = 5;
      *(int *)(this + 0x74) = in_r3;
      iVar3 = 0;
      *(uint *)(this + 0x70) = in_r2;
      *(uint *)(this + 0x7c) = in_r3 + ((in_r2 != 0) - 1);
      uVar10 = 0;
      *(uint *)(this + 0x78) = in_r2 - 1;
      *(undefined4 *)(this + 0x68) = 0;
      *(undefined4 *)(this + 0x6c) = 0;
      *(undefined4 *)(this + 0x80) = 0;
      *(undefined4 *)(this + 0x84) = 0;
      *(undefined4 *)(this + 0xa0) = 0;
      *(undefined4 *)(this + 0xa4) = 0;
      uVar8 = in_r2;
      iVar11 = in_r3;
    }
    *(uint *)(this + 0x78) = uVar8;
    *(int *)(this + 0x7c) = iVar11;
    *(uint *)(this + 0x70) = in_r2;
    *(int *)(this + 0x74) = in_r3;
    uVar9 = (in_r2 - uVar8) + uVar10;
    iVar3 = iVar3 + ((in_r3 - iVar11) - (uint)(in_r2 < uVar8)) + (uint)CARRY4(in_r2 - uVar8,uVar10);
    if ((int)(-(uint)(500 < uVar9) - iVar3) < 0 !=
        (SBORROW4(0,iVar3) != SBORROW4(-iVar3,(uint)(500 < uVar9)))) {
      iVar3 = 0;
      uVar9 = 0;
    }
    *(uint *)(this + 0x68) = uVar9;
    *(int *)(this + 0x6c) = iVar3;
  }
  Engine::SwapBuffer(*(Engine **)(this + 0xa8));
  if (__stack_chk_guard == local_28) {
    return;
  }
LAB_0008e2ea:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::ApplicationManager::ConvertTouchCoords  @0x0008e5f8  (90 bytes)
/* AbyssEngine::ApplicationManager::ConvertTouchCoords(int&, int&) */

void __thiscall
AbyssEngine::ApplicationManager::ConvertTouchCoords
          (ApplicationManager *this,int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)this + 0x30);
  if (iVar1 != 3) {
    if (iVar1 != 1) {
      if (iVar1 != 0) {
        return;
      }
      iVar2 = *param_1;
      iVar1 = PaintCanvas::GetWidth();
      *param_1 = iVar1 - *param_2;
      *param_2 = iVar2;
      return;
    }
    iVar2 = *param_1;
    *param_1 = *param_2;
    iVar1 = PaintCanvas::GetHeight();
    *param_2 = iVar1 - iVar2;
  }
  iVar1 = PaintCanvas::GetWidth();
  *param_1 = iVar1 - *param_1;
  iVar1 = PaintCanvas::GetHeight();
  *param_2 = iVar1 - *param_2;
  return;
}

// ===== AbyssEngine::ApplicationManager::OnTouchBegin  @0x0008e654  (378 bytes)
/* AbyssEngine::ApplicationManager::OnTouchBegin(int, int, void*) */

void __thiscall
AbyssEngine::ApplicationManager::OnTouchBegin
          (ApplicationManager *this,int param_1,int param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined **ppuVar5;
  undefined4 uVar6;
  float fVar7;
  int local_28;
  int iStack_24;
  int local_20;
  
  local_20 = __stack_chk_guard;
  local_28 = param_2;
  iStack_24 = param_1;
  if ((*(int *)(this + 0x18) == 0) || (*(int *)(this + 0x3c) != 5)) goto LAB_0008e7ba;
  ConvertTouchCoords(this,&iStack_24,&local_28);
  iVar2 = iStack_24;
  iVar1 = local_28;
  (**(code **)(**(int **)(this + 0x18) + 0x24))(*(int **)(this + 0x18),iStack_24,local_28,param_3);
  (**(code **)(**(int **)(this + 0x18) + 0x18))(*(int **)(this + 0x18),iVar2,iVar1);
  *(int *)(this + 0xb4) = iVar2;
  *(int *)(this + 0xb8) = iVar1;
  switch(debugModusIndex) {
  case 0:
    iVar3 = iVar2;
    if (iVar2 < 0x32) {
      iVar3 = iVar1;
    }
    if (0x31 < iVar3) break;
    uVar6 = 1;
    ppuVar5 = &PTR_debugModusIndex_00265650;
    goto LAB_0008e7a2;
  case 1:
    iVar3 = PaintCanvas::GetWidth();
    if ((iVar3 + -0x32 < iVar2) && (iVar1 < 0x32)) {
LAB_0008e72a:
      debugModusIndex = debugModusIndex + 1;
      goto LAB_0008e7ba;
    }
    break;
  case 2:
    iVar3 = PaintCanvas::GetWidth();
    if ((iVar3 + -0x32 < iVar2) && (iVar3 = PaintCanvas::GetHeight(), iVar3 + -0x32 < iVar1))
    goto LAB_0008e72a;
    break;
  case 3:
    if ((iVar2 < 0x32) && (iVar3 = PaintCanvas::GetHeight(), iVar3 + -0x32 < iVar1)) {
      *(byte *)(*(int *)(this + 0xa8) + 100) = *(byte *)(*(int *)(this + 0xa8) + 100) ^ 1;
      goto LAB_0008e7ba;
    }
  }
  if (*(char *)(*(int *)(this + 0xa8) + 100) != '\0') {
    if (iVar1 < 100) {
      Engine::UseAdvancedShader = Engine::UseAdvancedShader ^ 1;
    }
    else {
      iVar3 = PaintCanvas::GetHeight();
      iVar4 = PaintCanvas::GetWidth();
      if (iVar3 + -100 < iVar1) {
        if (iVar2 < iVar4 / 2) {
          uVar6 = 0;
          ppuVar5 = &PTR_LodDistShader_0026563c;
        }
        else {
          uVar6 = 0x4b189680;
          ppuVar5 = &PTR_LodDistShader_0026563c;
        }
LAB_0008e7a2:
        *(undefined4 *)*ppuVar5 = uVar6;
      }
      else {
        if (iVar2 < iVar4 / 2) {
          fVar7 = -100.0;
        }
        else {
          fVar7 = 100.0;
        }
        Engine::LodDistShader = Engine::LodDistShader + fVar7;
      }
    }
  }
LAB_0008e7ba:
  if (__stack_chk_guard == local_20) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::ApplicationManager::OnTouchMove  @0x0008e80c  (106 bytes)
/* AbyssEngine::ApplicationManager::OnTouchMove(int, int, void*) */

void __thiscall
AbyssEngine::ApplicationManager::OnTouchMove
          (ApplicationManager *this,int param_1,int param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  int local_24;
  int iStack_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  local_24 = param_2;
  iStack_20 = param_1;
  if ((*(int *)(this + 0x18) != 0) && (*(int *)(this + 0x3c) == 5)) {
    ConvertTouchCoords(this,&iStack_20,&local_24);
    iVar2 = iStack_20;
    iVar1 = local_24;
    (**(code **)(**(int **)(this + 0x18) + 0x28))(*(int **)(this + 0x18),iStack_20,local_24,param_3)
    ;
    (**(code **)(**(int **)(this + 0x18) + 0x1c))(*(int **)(this + 0x18),iVar2,iVar1);
    *(int *)(this + 0xb4) = iVar2;
    *(int *)(this + 0xb8) = iVar1;
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::ApplicationManager::OnTouchEnd  @0x0008e880  (116 bytes)
/* AbyssEngine::ApplicationManager::OnTouchEnd(int, int, void*) */

void __thiscall
AbyssEngine::ApplicationManager::OnTouchEnd
          (ApplicationManager *this,int param_1,int param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  int local_24;
  int iStack_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  debugModusIndex = 0;
  local_24 = param_2;
  iStack_20 = param_1;
  if ((*(int *)(this + 0x18) != 0) && (*(int *)(this + 0x3c) == 5)) {
    ConvertTouchCoords(this,&iStack_20,&local_24);
    iVar2 = iStack_20;
    iVar1 = local_24;
    (**(code **)(**(int **)(this + 0x18) + 0x2c))(*(int **)(this + 0x18),iStack_20,local_24,param_3)
    ;
    (**(code **)(**(int **)(this + 0x18) + 0x20))(*(int **)(this + 0x18),iVar2,iVar1);
    *(int *)(this + 0xb4) = iVar2;
    *(int *)(this + 0xb8) = iVar1;
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::ApplicationManager::OnTouchEnd  @0x0008e900  (22 bytes)
/* AbyssEngine::ApplicationManager::OnTouchEnd() */

void __thiscall AbyssEngine::ApplicationManager::OnTouchEnd(ApplicationManager *this)

{
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x98) = 0;
  *(undefined4 *)(this + 0x9c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0xa0) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  return;
}

// ===== AbyssEngine::ApplicationManager::OnKeyPress  @0x0008e916  (224 bytes)
/* AbyssEngine::ApplicationManager::OnKeyPress(int) */

void __thiscall AbyssEngine::ApplicationManager::OnKeyPress(ApplicationManager *this,int param_1)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = 0;
  *(undefined4 *)(this + 0x98) = 0;
  *(undefined4 *)(this + 0x9c) = 0;
  *(int *)(this + 8) = param_1;
  *(int *)(this + 0xc) = param_1 >> 0x1f;
  piVar2 = *(int **)(this + 0x10);
  do {
    if (*piVar2 == param_1) {
      uVar4 = 1 >> (0x20 - uVar8 & 0xff);
      if (-1 < (int)(uVar8 - 0x20)) {
        uVar4 = 1 << (uVar8 - 0x20 & 0xff);
      }
      uVar3 = 1 << (uVar8 & 0xff);
      *(uint *)(this + 0x80) = *(uint *)(this + 0x80) | uVar3;
      *(uint *)(this + 0x84) = *(uint *)(this + 0x84) | uVar4;
      if (*(uint *)(this + 0x88) == 0) {
        uVar6 = 0;
        uVar7 = 0;
      }
      else {
        puVar1 = *(uint **)(this + 0x8c);
        uVar6 = 0;
        uVar7 = 0;
        uVar5 = 0;
        do {
          if (puVar1[2] == uVar8 && puVar1[3] == (int)uVar8 >> 0x1f) {
            uVar7 = uVar7 | puVar1[1];
            uVar6 = uVar6 | *puVar1;
            *(uint *)(this + 0x98) = uVar6;
            *(uint *)(this + 0x9c) = uVar7;
            *(uint *)(this + 0xa0) = *(uint *)(this + 0xa0) | uVar6;
            *(uint *)(this + 0xa4) = *(uint *)(this + 0xa4) | uVar7;
          }
          uVar5 = uVar5 + 2;
          puVar1 = puVar1 + 4;
        } while (uVar5 < *(uint *)(this + 0x88));
      }
      goto LAB_0008e9da;
    }
    uVar8 = uVar8 + 1;
    piVar2 = piVar2 + 3;
  } while ((int)uVar8 < 0x40);
  uVar6 = 0;
  uVar7 = 0;
  uVar3 = 0;
  uVar4 = 0;
LAB_0008e9da:
  piVar2 = *(int **)(this + 0x18);
  if ((piVar2 != (int *)0x0) && (*(int *)(this + 0x3c) == 5)) {
    (**(code **)(*piVar2 + 0x10))(piVar2,piVar2,uVar3,uVar4,uVar6,uVar7);
  }
  return;
}

// ===== AbyssEngine::ApplicationManager::OnKeyRelease  @0x0008e9f6  (230 bytes)
/* AbyssEngine::ApplicationManager::OnKeyRelease(int) */

void __thiscall AbyssEngine::ApplicationManager::OnKeyRelease(ApplicationManager *this,int param_1)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = 0;
  *(undefined4 *)(this + 0x98) = 0;
  *(undefined4 *)(this + 0x9c) = 0;
  piVar2 = *(int **)(this + 0x10);
  do {
    if (*piVar2 == param_1) {
      uVar4 = 1 >> (0x20 - uVar8 & 0xff);
      if (-1 < (int)(uVar8 - 0x20)) {
        uVar4 = 1 << (uVar8 - 0x20 & 0xff);
      }
      uVar3 = 1 << (uVar8 & 0xff);
      *(uint *)(this + 0x80) = *(uint *)(this + 0x80) & ~uVar3;
      *(uint *)(this + 0x84) = *(uint *)(this + 0x84) & ~uVar4;
      if (*(uint *)(this + 0x88) == 0) {
        uVar7 = 0;
        uVar5 = 0;
      }
      else {
        uVar7 = 0;
        puVar1 = *(uint **)(this + 0x8c);
        uVar5 = 0;
        uVar6 = 0;
        do {
          if (puVar1[3] == (int)uVar8 >> 0x1f && puVar1[2] == uVar8) {
            uVar5 = uVar5 | puVar1[1];
            uVar7 = uVar7 | *puVar1;
            *(uint *)(this + 0x98) = uVar7;
            *(uint *)(this + 0x9c) = uVar5;
            *(uint *)(this + 0xa0) = *(uint *)(this + 0xa0) & (uVar7 ^ 0xffffffff);
            *(uint *)(this + 0xa4) = (uVar5 ^ 0xffffffff) & *(uint *)(this + 0xa4);
          }
          uVar6 = uVar6 + 2;
          puVar1 = puVar1 + 4;
        } while (uVar6 < *(uint *)(this + 0x88));
      }
      goto LAB_0008eac0;
    }
    uVar8 = uVar8 + 1;
    piVar2 = piVar2 + 3;
  } while ((int)uVar8 < 0x40);
  uVar7 = 0;
  uVar5 = 0;
  uVar3 = 0;
  uVar4 = 0;
LAB_0008eac0:
  piVar2 = *(int **)(this + 0x18);
  if ((piVar2 != (int *)0x0) && (*(int *)(this + 0x3c) == 5)) {
    (**(code **)(*piVar2 + 0x14))(piVar2,piVar2,uVar3,uVar4,uVar7,uVar5);
  }
  return;
}

// ===== AbyssEngine::ApplicationManager::GetKeyState  @0x0008eadc  (6 bytes)
/* AbyssEngine::ApplicationManager::GetKeyState() */

undefined8 __thiscall AbyssEngine::ApplicationManager::GetKeyState(ApplicationManager *this)

{
  return *(undefined8 *)(this + 0x80);
}

// ===== AbyssEngine::ApplicationManager::GetActionState  @0x0008eae2  (6 bytes)
/* AbyssEngine::ApplicationManager::GetActionState() */

undefined8 __thiscall AbyssEngine::ApplicationManager::GetActionState(ApplicationManager *this)

{
  return *(undefined8 *)(this + 0xa0);
}

// ===== AbyssEngine::ApplicationManager::ResetKeyState  @0x0008eae8  (8 bytes)
/* AbyssEngine::ApplicationManager::ResetKeyState() */

void __thiscall AbyssEngine::ApplicationManager::ResetKeyState(ApplicationManager *this)

{
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  return;
}

// ===== AbyssEngine::ApplicationManager::GetCurrentTimeMillis  @0x0008eaf0  (6 bytes)
/* AbyssEngine::ApplicationManager::GetCurrentTimeMillis() */

undefined8 __thiscall
AbyssEngine::ApplicationManager::GetCurrentTimeMillis(ApplicationManager *this)

{
  return *(undefined8 *)(this + 0x68);
}

// ===== AbyssEngine::ApplicationManager::GetSystemTimeMillis  @0x0008eaf6  (6 bytes)
/* AbyssEngine::ApplicationManager::GetSystemTimeMillis() */

undefined8 __thiscall AbyssEngine::ApplicationManager::GetSystemTimeMillis(ApplicationManager *this)

{
  return *(undefined8 *)(this + 0x68);
}

// ===== AbyssEngine::ApplicationManager::KeyCodeSetMapping  @0x0008eafc  (62 bytes)
/* AbyssEngine::ApplicationManager::KeyCodeSetMapping(Array<AbyssEngine::KeyCode*>*) */

void __thiscall
AbyssEngine::ApplicationManager::KeyCodeSetMapping(ApplicationManager *this,Array *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  
  if (*(int *)param_1 != 0x40) {
    return;
  }
  iVar4 = 0;
  uVar3 = 0;
  do {
    puVar2 = *(undefined4 **)(*(int *)(param_1 + 4) + uVar3 * 4);
    iVar1 = *(int *)(this + 0x10);
    *(undefined4 *)(iVar1 + iVar4) = *puVar2;
    String::operator=((String *)((undefined4 *)(iVar1 + iVar4) + 1),(String *)(puVar2 + 1));
    iVar4 = iVar4 + 0xc;
    uVar3 = uVar3 + 1;
  } while (uVar3 < *(uint *)param_1);
  return;
}

// ===== AbyssEngine::ApplicationManager::CheckCrack  @0x0008eb3a  (4 bytes)
/* AbyssEngine::ApplicationManager::CheckCrack(char const*) */

undefined4 AbyssEngine::ApplicationManager::CheckCrack(char *param_1)

{
  return 0;
}

