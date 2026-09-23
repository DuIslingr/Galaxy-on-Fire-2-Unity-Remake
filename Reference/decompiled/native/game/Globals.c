// Class: Globals
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Globals::Globals  @0x000f7580  (474 bytes)
/* Globals::Globals() */

void __thiscall Globals::Globals(Globals *this)

{
  shipTemplate = 0;
  Canvas = 0;
  recordHandler = 0;
  appManager = 0;
  options._84_4_ = 0x247;
  gameText = 0;
  generator = 0;
  font = 0;
  fontAlien = 0;
  fontLangSelect = 0;
  rnd = 0;
  globals = 0;
  layout = 0;
  *(undefined4 *)this = 0;
  options._20_8_ = 0x3f0000003f000000;
  options._28_8_ = 0x3f19999a3f19999a;
  options[0x11] = 0;
  options[0x10] = 0;
  options[0x40] = 0;
  options[0x41] = 0;
  options[0xd] = 1;
  options[0xc] = 1;
  options[0xe] = 1;
  options._0_4_ = 0x3f000000;
  options._4_4_ = 0x3f000000;
  options._8_4_ = 0x3f000000;
  options._36_4_ = 0x3f000000;
  options._40_4_ = 0x3f800000;
  options._44_4_ = 0x3f000000;
  options[0x30] = 1;
  options._80_4_ = 0;
  options._53_4_ = 0;
  options._49_4_ = 0;
  options[0x39] = 0;
  options[0x3f] = 0;
  options._59_4_ = 0;
  options[0x4e] = 0;
  options._76_2_ = 0;
  options._72_4_ = 0;
  hints[0x13] = 0;
  hints._4_4_ = 0;
  hints._0_4_ = 0;
  lastStationMusicPlayed = 0xffffffff;
  lastCampaignMissionFailed = 0xffffffff;
  lastCampaignMissionFailCount = 0;
  gameLoaded = 0;
  lastSpaceMusicPlayed = 0xffffffff;
  gameSaving = 0;
  initMemoryWarning = 0;
  if (1.0 <= (float)options._68_4_) {
    options._84_4_ = 0x33e;
  }
  options._88_4_ = 0x201;
  if ((float)options._68_4_ <= 0.0) {
    options._84_4_ = 0x19f;
  }
  if (1.0 <= (float)options._68_4_) {
    options._88_4_ = 0x2da;
  }
  if ((float)options._68_4_ <= 0.0) {
    options._88_4_ = 0x16d;
  }
  instantActionType = 0xffffffff;
  options[0x61] = 1;
  galaxy = 0;
  achievements = 0;
  instantActionScore = 0;
  instantActionPlayerName = 0;
  imageFactory = 0;
  options[0x60] = 0;
  instantActionWave = 0;
  items = 0;
  status = 0;
  ships = 0;
  *(undefined4 *)(this + 4) = 0;
  return;
}

// ===== Globals::~Globals  @0x000f77f0  (532 bytes)
/* Globals::~Globals() */

Globals * __thiscall Globals::~Globals(Globals *this)

{
  Array *pAVar1;
  void *pvVar2;
  void *pvVar3;
  
  if (recordHandler != (RecordHandler *)0x0) {
    RecordHandler::saveOptions(recordHandler);
  }
  if (galaxy != (Galaxy *)0x0) {
    pvVar2 = (void *)Galaxy::~Galaxy(galaxy);
    operator_delete(pvVar2);
  }
  galaxy = (Galaxy *)0x0;
  if (status != (Status *)0x0) {
    pvVar2 = (void *)Status::~Status(status);
    operator_delete(pvVar2);
  }
  status = (Status *)0x0;
  if (gameText != (GameText *)0x0) {
    pvVar2 = (void *)GameText::~GameText(gameText);
    operator_delete(pvVar2);
  }
  gameText = (GameText *)0x0;
  if (rnd != (AERandom *)0x0) {
    pvVar2 = (void *)AbyssEngine::AERandom::~AERandom(rnd);
    operator_delete(pvVar2);
  }
  rnd = (AERandom *)0x0;
  if (layout != (Layout *)0x0) {
    pvVar2 = (void *)Layout::~Layout(layout);
    operator_delete(pvVar2);
  }
  layout = (Layout *)0x0;
  if (generator != (Generator *)0x0) {
    pvVar2 = (void *)Generator::~Generator(generator);
    operator_delete(pvVar2);
  }
  generator = (Generator *)0x0;
  if (recordHandler != (RecordHandler *)0x0) {
    pvVar2 = (void *)RecordHandler::~RecordHandler(recordHandler);
    operator_delete(pvVar2);
  }
  recordHandler = (RecordHandler *)0x0;
  if (instantActionPlayerName != (String *)0x0) {
    pvVar2 = (void *)AbyssEngine::String::~String(instantActionPlayerName);
    operator_delete(pvVar2);
  }
  instantActionPlayerName = (String *)0x0;
  if (sound != (FModSound *)0x0) {
    pvVar2 = (void *)FModSound::~FModSound(sound);
    operator_delete(pvVar2);
  }
  sound = (FModSound *)0x0;
  if ((items != (Array *)0x0) &&
     (ArrayReleaseClasses<Item*>(items), pAVar1 = items, items != (Array *)0x0)) {
    if (*(void **)(items + 4) != (void *)0x0) {
      operator_delete__(*(void **)(items + 4));
    }
    operator_delete(pAVar1);
  }
  items = (Array *)0x0;
  if ((ships != (Array *)0x0) &&
     (ArrayReleaseClasses<Ship*>(ships), pAVar1 = ships, ships != (Array *)0x0)) {
    if (*(void **)(ships + 4) != (void *)0x0) {
      operator_delete__(*(void **)(ships + 4));
    }
    operator_delete(pAVar1);
  }
  ships = (Array *)0x0;
  if (galaxy != (Galaxy *)0x0) {
    pvVar2 = (void *)Galaxy::~Galaxy(galaxy);
    operator_delete(pvVar2);
  }
  galaxy = (Galaxy *)0x0;
  if (achievements != (Achievements *)0x0) {
    pvVar2 = (void *)Achievements::~Achievements(achievements);
    operator_delete(pvVar2);
  }
  achievements = (Achievements *)0x0;
  if (status != (Status *)0x0) {
    pvVar2 = (void *)Status::~Status(status);
    operator_delete(pvVar2);
  }
  status = (Status *)0x0;
  if (imageFactory != (ImageFactory *)0x0) {
    pvVar2 = (void *)ImageFactory::~ImageFactory(imageFactory);
    operator_delete(pvVar2);
  }
  imageFactory = (ImageFactory *)0x0;
  pvVar2 = *(void **)(this + 4);
  if (pvVar2 != (void *)0x0) {
    if (*(void **)((int)pvVar2 + 4) == (void *)0x0) {
      *(undefined4 *)((int)pvVar2 + 4) = 0;
    }
    else {
      operator_delete__(*(void **)((int)pvVar2 + 4));
      pvVar3 = *(void **)(this + 4);
      *(undefined4 *)((int)pvVar2 + 4) = 0;
      pvVar2 = pvVar3;
      if (pvVar3 == (void *)0x0) goto LAB_000f79f2;
    }
    if (*(void **)((int)pvVar2 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar2 + 4));
    }
    operator_delete(pvVar2);
  }
LAB_000f79f2:
  *(undefined4 *)(this + 4) = 0;
  globals = 0;
  return this;
}

// ===== Globals::init  @0x000f7a90  (694 bytes)
/* Globals::init(AbyssEngine::ApplicationManager*, AbyssEngine::Engine*) */

void Globals::init(ApplicationManager *param_1,Engine *param_2)

{
  Mission *this;
  Galaxy *this_00;
  Achievements *this_01;
  Status *this_02;
  ImageFactory *this_03;
  FileRead *this_04;
  void *pvVar1;
  AERandom *this_05;
  Generator *this_06;
  RecordHandler *this_07;
  FModSound *this_08;
  int iVar2;
  Layout *this_09;
  undefined4 *puVar3;
  undefined4 *puVar4;
  float fVar5;
  
  if (Mission::empty == (Mission *)0x0) {
    this = operator_new(100);
    Mission::Mission(this);
    Mission::empty = this;
  }
  options[0x10] = 1;
  options[0x11] = 1;
  options._20_8_ = 0x3f8000003f800000;
  options._28_8_ = 0x3f19999a3f19999a;
  options[0x30] = 1;
  options._0_4_ = 0x3f000000;
  options._4_4_ = 0x3f000000;
  options._8_4_ = 0x3f000000;
  options._36_4_ = 0x3f000000;
  options._40_4_ = 0x3f800000;
  options[0xf] = 1;
  recordSlots = 6;
  if (iPad != '\0') {
    recordSlots = 0xc;
  }
  startLiteVersionWithMoreCredits = 0;
  lastRecordWritten = 0xffffffff;
  this_00 = operator_new(8);
  Galaxy::Galaxy(this_00);
  galaxy = this_00;
  this_01 = operator_new(0x28);
  Achievements::Achievements(this_01);
  achievements = this_01;
  this_02 = operator_new(0x1f0);
  Status::Status(this_02);
  status = this_02;
  this_03 = operator_new(0xc);
  ImageFactory::ImageFactory(this_03);
  imageFactory = this_03;
  this_04 = operator_new(1);
  FileRead::FileRead(this_04);
  items = FileRead::loadItemsBinary();
  ships = FileRead::loadShipsBinary();
  pvVar1 = (void *)FileRead::~FileRead(this_04);
  operator_delete(pvVar1);
  if (Canvas == 0) {
    Canvas = *(int *)param_2;
  }
  appManager = param_2;
  AbyssEngine::ApplicationManager::VibrateEnable((ApplicationManager *)param_2,false);
  this_05 = operator_new(8);
  AbyssEngine::AERandom::AERandom(this_05);
  rnd = this_05;
  globals = param_1;
  this_06 = operator_new(1);
  Generator::Generator(this_06);
  generator = this_06;
  this_07 = operator_new(0x20);
  RecordHandler::RecordHandler(this_07);
  recordHandler = this_07;
  Status::resetGame(status);
  RecordHandler::loadOptions(recordHandler);
  this_08 = operator_new(0x243c);
  FModSound::FModSound(this_08);
  sound = this_08;
  FModSound::init(this_08);
  FModSound::enableCategory((int)sound,true);
  FModSound::enableCategory((int)sound,true);
  fVar5 = (float)FModSound::enableCategory((int)sound,true);
  fVar5 = (float)FModSound::setVolume(sound,1,fVar5);
  fVar5 = (float)FModSound::setVolume(sound,2,fVar5);
  FModSound::setVolume(sound,3,fVar5);
  iVar2 = FModSound::tryToStopMusicForBGMusic();
  if (iVar2 == 1) {
    options[0xd] = 0;
  }
  hints._4_4_ = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  hints._8_4_ = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  hints._12_4_ = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  hints._48_3_ = SUB43(hints._4_4_,1);
  hints._32_4_ = 0;
  hints._0_4_ = 0;
  hints._16_4_ = 0;
  initMemoryWarning = 0;
  gameLoaded = 0;
  gameSaving = 0;
  instantActionPoints = 0;
  first_start_ever = 1;
  hints._20_4_ = hints._4_4_;
  hints._24_4_ = hints._8_4_;
  hints._28_4_ = hints._12_4_;
  hints._36_4_ = hints._4_4_;
  hints._40_4_ = hints._8_4_;
  hints._44_4_ = hints._12_4_;
  hints._51_4_ = hints._8_4_;
  hints._55_4_ = hints._12_4_;
  this_09 = operator_new(0x414);
  Layout::Layout(this_09);
  layout = this_09;
  Layout::reload(this_09);
  ParticleSettings::init((ParticleSettings *)ParticleSettingsRef::cur);
  ParticleSettings::init((ParticleSettings *)ParticleSettingsRef::init);
  ParticleSettingsRef::assertInit = 0x2a;
  puVar3 = operator_new(0xc);
  puVar4 = operator_new__(4);
  puVar3[1] = puVar4;
  puVar3[2] = 1;
  *puVar4 = 0;
  *puVar3 = 0;
  *(undefined4 **)(param_1 + 4) = puVar3;
  return;
}

// ===== Globals::resetHints  @0x000f7e10  (36 bytes)
/* Globals::resetHints() */

void Globals::resetHints(void)

{
  hints._36_4_ = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  hints._51_4_ = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  hints._55_4_ = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  hints._48_3_ = SUB43(hints._36_4_,1);
  hints._32_4_ = 0;
  hints._40_4_ = hints._51_4_;
  hints._44_4_ = hints._55_4_;
  hints._0_4_ = 0;
  hints._4_4_ = hints._36_4_;
  hints._8_4_ = hints._51_4_;
  hints._12_4_ = hints._55_4_;
  hints._16_4_ = 0;
  hints._20_4_ = hints._36_4_;
  hints._24_4_ = hints._51_4_;
  hints._28_4_ = hints._55_4_;
  return;
}

// ===== Globals::longToTimeString  @0x000f7e38  (530 bytes)
/* Globals::longToTimeString(long long, AbyssEngine::String&) */

void Globals::longToTimeString(longlong param_1,String *param_2)

{
  undefined1 *puVar1;
  int iVar2;
  char *pcVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 uVar4;
  int extraout_r2;
  int extraout_r2_00;
  int extraout_r2_01;
  undefined8 uVar5;
  String *in_stack_00000000;
  String aSStack_6c [8];
  String aSStack_64 [8];
  AbyssEngine aAStack_5c [8];
  AbyssEngine aAStack_54 [8];
  undefined4 local_4c [2];
  undefined4 local_44 [2];
  undefined4 local_3c [2];
  String aSStack_34 [8];
  AbyssEngine aAStack_2c [8];
  int local_24;
  
  uVar5 = __aeabi_ldivmod(param_2);
  __aeabi_ldivmod((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0x3c,0);
  uVar5 = __aeabi_ldivmod(param_2);
  __aeabi_ldivmod((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0x3c,0);
  uVar5 = __aeabi_ldivmod(param_2);
  __aeabi_ldivmod((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0x18,0);
  local_24 = __stack_chk_guard;
  if (extraout_r2 < 10) {
    pcVar3 = "0";
  }
  else {
    pcVar3 = "";
  }
  AbyssEngine::String::String(aSStack_34,pcVar3,false);
  local_3c[0] = 0;
  AbyssEngine::String::Set(CONCAT44(extraout_r1,local_3c));
  AbyssEngine::operator+(aAStack_2c,aSStack_34,(String *)local_3c);
  AbyssEngine::String::~String((String *)local_3c);
  AbyssEngine::String::~String(aSStack_34);
  if (extraout_r2_00 < 10) {
    AbyssEngine::String::String((String *)local_3c,"0",false);
    uVar4 = extraout_r1_00;
  }
  else {
    AbyssEngine::String::String((String *)local_3c,"",false);
    uVar4 = extraout_r1_01;
  }
  local_44[0] = 0;
  AbyssEngine::String::Set(CONCAT44(uVar4,local_44));
  AbyssEngine::operator+((AbyssEngine *)aSStack_34,(String *)local_3c,(String *)local_44);
  AbyssEngine::String::~String((String *)local_44);
  AbyssEngine::String::~String((String *)local_3c);
  if (extraout_r2_01 == 0) {
    AbyssEngine::String::String((String *)local_4c,":",false);
    AbyssEngine::operator+((AbyssEngine *)local_44,aSStack_34,(String *)local_4c);
    AbyssEngine::operator+((AbyssEngine *)local_3c,(String *)local_44,aAStack_2c);
    AbyssEngine::String::operator=(in_stack_00000000,(String *)local_3c);
    AbyssEngine::String::~String((String *)local_3c);
    AbyssEngine::String::~String((String *)local_44);
    puVar1 = &stack0x00000004;
  }
  else {
    iVar2 = __aeabi_ldivmod(param_2);
    if (extraout_r2_01 + iVar2 * 0x18 < 10) {
      AbyssEngine::String::String((String *)local_44,"0",false);
      uVar4 = extraout_r1_02;
    }
    else {
      AbyssEngine::String::String((String *)local_44,"",false);
      uVar4 = extraout_r1_03;
    }
    local_4c[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar4,local_4c));
    AbyssEngine::operator+((AbyssEngine *)local_3c,(String *)local_44,(String *)local_4c);
    AbyssEngine::String::~String((String *)local_4c);
    AbyssEngine::String::~String((String *)local_44);
    AbyssEngine::String::String(aSStack_64,":",false);
    AbyssEngine::operator+(aAStack_5c,(String *)local_3c,aSStack_64);
    AbyssEngine::operator+(aAStack_54,aAStack_5c,aSStack_34);
    AbyssEngine::String::String(aSStack_6c,":",false);
    AbyssEngine::operator+((AbyssEngine *)local_4c,aAStack_54,aSStack_6c);
    AbyssEngine::operator+((AbyssEngine *)local_44,(String *)local_4c,aAStack_2c);
    AbyssEngine::String::operator=(in_stack_00000000,(String *)local_44);
    AbyssEngine::String::~String((String *)local_44);
    AbyssEngine::String::~String((String *)local_4c);
    AbyssEngine::String::~String(aSStack_6c);
    AbyssEngine::String::~String((String *)aAStack_54);
    AbyssEngine::String::~String((String *)aAStack_5c);
    AbyssEngine::String::~String(aSStack_64);
    puVar1 = &stack0x00000014;
  }
  AbyssEngine::String::~String((String *)(puVar1 + -0x50));
  AbyssEngine::String::~String(aSStack_34);
  AbyssEngine::String::~String((String *)aAStack_2c);
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Globals::longToTimeStringNoSeconds  @0x000f8124  (318 bytes)
/* Globals::longToTimeStringNoSeconds(long long, AbyssEngine::String&) */

void Globals::longToTimeStringNoSeconds(longlong param_1,String *param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 uVar3;
  int extraout_r2;
  int extraout_r2_00;
  undefined8 uVar4;
  String *in_stack_00000000;
  String aSStack_44 [8];
  undefined4 local_3c [2];
  undefined4 local_34 [2];
  String aSStack_2c [8];
  AbyssEngine aAStack_24 [8];
  int local_1c;
  
  uVar4 = __aeabi_ldivmod(param_2);
  __aeabi_ldivmod((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0x3c,0);
  uVar4 = __aeabi_ldivmod(param_2);
  __aeabi_ldivmod((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0x18,0);
  local_1c = __stack_chk_guard;
  if (extraout_r2 < 10) {
    pcVar2 = "0";
  }
  else {
    pcVar2 = "";
  }
  AbyssEngine::String::String(aSStack_2c,pcVar2,false);
  local_34[0] = 0;
  AbyssEngine::String::Set(CONCAT44(extraout_r1,local_34));
  AbyssEngine::operator+(aAStack_24,aSStack_2c,(String *)local_34);
  AbyssEngine::String::~String((String *)local_34);
  AbyssEngine::String::~String(aSStack_2c);
  iVar1 = __aeabi_ldivmod(param_2);
  if (extraout_r2_00 + iVar1 * 0x18 < 10) {
    AbyssEngine::String::String((String *)local_34,"0",false);
    uVar3 = extraout_r1_00;
  }
  else {
    AbyssEngine::String::String((String *)local_34,"",false);
    uVar3 = extraout_r1_01;
  }
  local_3c[0] = 0;
  AbyssEngine::String::Set(CONCAT44(uVar3,local_3c));
  AbyssEngine::operator+((AbyssEngine *)aSStack_2c,(String *)local_34,(String *)local_3c);
  AbyssEngine::String::~String((String *)local_3c);
  AbyssEngine::String::~String((String *)local_34);
  AbyssEngine::String::String(aSStack_44,":",false);
  AbyssEngine::operator+((AbyssEngine *)local_3c,aSStack_2c,aSStack_44);
  AbyssEngine::operator+((AbyssEngine *)local_34,(String *)local_3c,aAStack_24);
  AbyssEngine::String::operator=(in_stack_00000000,(String *)local_34);
  AbyssEngine::String::~String((String *)local_34);
  AbyssEngine::String::~String((String *)local_3c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String(aSStack_2c);
  AbyssEngine::String::~String((String *)aAStack_24);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Globals::createBillBoard  @0x000f82d4  (702 bytes)
/* Globals::createBillBoard(int, int, float, float, float, float, int) */

void Globals::createBillBoard
               (int param_1,int param_2,float param_3,float param_4,float param_5,float param_6,
               int param_7)

{
  uint in_fpscr;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s0_02;
  float extraout_s0_03;
  float extraout_s0_04;
  float extraout_s0_05;
  float extraout_s0_06;
  float extraout_s0_07;
  undefined8 uVar1;
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
  undefined2 in_stack_0000000c;
  uint local_50;
  int local_4c;
  
  local_4c = __stack_chk_guard;
  local_50 = 0;
  AbyssEngine::PaintCanvas::MeshCreate(Canvas,0xc,6,0x13,in_stack_0000000c,&local_50);
  AbyssEngine::PaintCanvas::MeshSetTriangle(Canvas,local_50,0,0,1,2);
  AbyssEngine::PaintCanvas::MeshSetTriangle(Canvas,local_50,1,2,1,3);
  AbyssEngine::PaintCanvas::MeshSetTriangle(Canvas,local_50,2,4,5,6);
  AbyssEngine::PaintCanvas::MeshSetTriangle(Canvas,local_50,3,6,5,7);
  AbyssEngine::PaintCanvas::MeshSetTriangle(Canvas,local_50,4,8,9,10);
  uVar1 = AbyssEngine::PaintCanvas::MeshSetTriangle(Canvas,local_50,5,10,9,0xb);
  uVar1 = AbyssEngine::PaintCanvas::MeshSetUv
                    (Canvas,local_50,0,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20));
  uVar1 = AbyssEngine::PaintCanvas::MeshSetUv
                    (Canvas,local_50,1,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20));
  uVar1 = AbyssEngine::PaintCanvas::MeshSetUv
                    (Canvas,local_50,2,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20));
  uVar1 = AbyssEngine::PaintCanvas::MeshSetUv
                    (Canvas,local_50,3,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20));
  uVar1 = AbyssEngine::PaintCanvas::MeshSetUv
                    (Canvas,local_50,4,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20));
  uVar1 = AbyssEngine::PaintCanvas::MeshSetUv
                    (Canvas,local_50,5,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20));
  uVar1 = AbyssEngine::PaintCanvas::MeshSetUv
                    (Canvas,local_50,6,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20));
  uVar1 = AbyssEngine::PaintCanvas::MeshSetUv
                    (Canvas,local_50,7,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20));
  uVar1 = AbyssEngine::PaintCanvas::MeshSetUv
                    (Canvas,local_50,8,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20));
  uVar1 = AbyssEngine::PaintCanvas::MeshSetUv
                    (Canvas,local_50,9,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20));
  uVar1 = AbyssEngine::PaintCanvas::MeshSetUv
                    (Canvas,local_50,10,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20));
  AbyssEngine::PaintCanvas::MeshSetUv
            (Canvas,local_50,0xb,(float)uVar1,(float)((ulonglong)uVar1 >> 0x20));
  VectorSignedToFloat(param_7,(byte)(in_fpscr >> 0x16) & 3);
  VectorSignedToFloat(-param_2,(byte)(in_fpscr >> 0x16) & 3);
  AbyssEngine::PaintCanvas::MeshSetPoint(Canvas,local_50,0,(float)-param_2,extraout_s1,extraout_s2);
  VectorSignedToFloat(-param_7,(byte)(in_fpscr >> 0x16) & 3);
  AbyssEngine::PaintCanvas::MeshSetPoint
            (Canvas,local_50,1,(float)-param_7,extraout_s1_00,extraout_s2_00);
  VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
  AbyssEngine::PaintCanvas::MeshSetPoint
            (Canvas,local_50,2,(float)param_2,extraout_s1_01,extraout_s2_01);
  AbyssEngine::PaintCanvas::MeshSetPoint
            (Canvas,local_50,3,extraout_s0,extraout_s1_02,extraout_s2_02);
  AbyssEngine::PaintCanvas::MeshSetPoint
            (Canvas,local_50,4,extraout_s0_00,extraout_s1_03,extraout_s2_03);
  AbyssEngine::PaintCanvas::MeshSetPoint
            (Canvas,local_50,5,extraout_s0_01,extraout_s1_04,extraout_s2_04);
  AbyssEngine::PaintCanvas::MeshSetPoint
            (Canvas,local_50,6,extraout_s0_02,extraout_s1_05,extraout_s2_05);
  AbyssEngine::PaintCanvas::MeshSetPoint
            (Canvas,local_50,7,extraout_s0_03,extraout_s1_06,extraout_s2_06);
  AbyssEngine::PaintCanvas::MeshSetPoint
            (Canvas,local_50,8,extraout_s0_04,extraout_s1_07,extraout_s2_07);
  AbyssEngine::PaintCanvas::MeshSetPoint
            (Canvas,local_50,9,extraout_s0_05,extraout_s1_08,extraout_s2_08);
  AbyssEngine::PaintCanvas::MeshSetPoint
            (Canvas,local_50,10,extraout_s0_06,extraout_s1_09,extraout_s2_09);
  AbyssEngine::PaintCanvas::MeshSetPoint
            (Canvas,local_50,0xb,extraout_s0_07,extraout_s1_10,extraout_s2_10);
  if (__stack_chk_guard != local_4c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_50);
  }
  return;
}

// ===== Globals::getRandomName  @0x000f85a0  (302 bytes)
/* Globals::getRandomName(int, bool) */

void Globals::getRandomName(int param_1,bool param_2)

{
  FileRead *this;
  Array *pAVar1;
  Array *pAVar2;
  int iVar3;
  void *pvVar4;
  int in_r2;
  bool in_r3;
  String aSStack_40 [8];
  AbyssEngine aAStack_38 [8];
  String aSStack_30 [4];
  int local_2c;
  String aSStack_28 [8];
  int local_20;
  
  local_20 = __stack_chk_guard;
  this = operator_new(1);
  FileRead::FileRead(this);
  pAVar1 = (Array *)FileRead::loadNamesBinary(this,in_r2,in_r3,true);
  pAVar2 = (Array *)FileRead::loadNamesBinary(this,in_r2,in_r3,false);
  if (pAVar1 == (Array *)0x0) {
    AbyssEngine::String::String(aSStack_28,"",false);
  }
  else {
    iVar3 = AbyssEngine::AERandom::nextInt(rnd,*(int *)pAVar1);
    AbyssEngine::String::String(aSStack_28,*(String **)(*(int *)(pAVar1 + 4) + iVar3 * 4),false);
  }
  if (pAVar2 == (Array *)0x0) {
    AbyssEngine::String::String(aSStack_30,"",false);
  }
  else {
    iVar3 = AbyssEngine::AERandom::nextInt(rnd,*(int *)pAVar2);
    AbyssEngine::String::String(aSStack_30,*(String **)(*(int *)(pAVar2 + 4) + iVar3 * 4),false);
  }
  if (pAVar1 != (Array *)0x0) {
    ArrayReleaseClasses<AbyssEngine::String*>(pAVar1);
    if (*(void **)(pAVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)(pAVar1 + 4));
    }
    operator_delete(pAVar1);
  }
  if (pAVar2 != (Array *)0x0) {
    ArrayReleaseClasses<AbyssEngine::String*>(pAVar2);
    if (*(void **)(pAVar2 + 4) != (void *)0x0) {
      operator_delete__(*(void **)(pAVar2 + 4));
    }
    operator_delete(pAVar2);
  }
  pvVar4 = (void *)FileRead::~FileRead(this);
  operator_delete(pvVar4);
  if (local_2c == 0) {
    AbyssEngine::String::String((String *)param_1,aSStack_28,false);
  }
  else {
    AbyssEngine::String::String(aSStack_40," ",false);
    AbyssEngine::operator+(aAStack_38,aSStack_28,aSStack_40);
    AbyssEngine::operator+((AbyssEngine *)param_1,aAStack_38,aSStack_30);
    AbyssEngine::String::~String((String *)aAStack_38);
    AbyssEngine::String::~String(aSStack_40);
  }
  AbyssEngine::String::~String(aSStack_30);
  AbyssEngine::String::~String(aSStack_28);
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Globals::getLine  @0x000f8724  (306 bytes)
/* Globals::getLine(unsigned int, AbyssEngine::String, int, AbyssEngine::String*) */

void __thiscall
Globals::getLine(undefined4 param_1_00,uint param_1,String *param_3,int param_4,String *param_5)

{
  short sVar1;
  ushort uVar2;
  short *psVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  uVar2 = GameText::getLanguage();
  iVar6 = 5;
  uVar7 = 0;
  if ((uVar2 | 1) == 0xb) {
    iVar6 = 0xf;
  }
  if (uVar2 == 0xf) {
    iVar6 = 0xf;
  }
  uVar5 = 0;
  while( true ) {
    if (*(uint *)(param_3 + 4) <= uVar5) {
      if ((int)*(uint *)(param_3 + 4) < 2) {
        AbyssEngine::String::String(aSStack_30,"",false);
        AbyssEngine::String::operator=(param_5,aSStack_30);
      }
      else {
        AbyssEngine::String::SubString((uint)aSStack_30,(uint)param_3);
        AbyssEngine::String::operator=(param_5,aSStack_30);
      }
      goto LAB_000f8838;
    }
    psVar3 = (short *)AbyssEngine::String::operator[](param_3,uVar5);
    sVar1 = *psVar3;
    iVar4 = AbyssEngine::PaintCanvas::GetTextWidth(Canvas,param_1,param_3,uVar5,uVar5 + 1);
    iVar6 = iVar6 + iVar4;
    if (sVar1 == 0x20) {
      uVar7 = uVar5;
    }
    if (param_4 <= iVar6) break;
    psVar3 = (short *)AbyssEngine::String::operator[](param_3,uVar5);
    if ((*psVar3 == 10) ||
       (psVar3 = (short *)AbyssEngine::String::operator[](param_3,uVar5), uVar5 = uVar5 + 1,
       *psVar3 == 0xd)) {
      AbyssEngine::String::SubString((uint)aSStack_30,(uint)param_3);
      AbyssEngine::String::operator=(param_5,aSStack_30);
LAB_000f8838:
      AbyssEngine::String::~String(aSStack_30);
      if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
  }
  if ((int)uVar7 < 1) {
    AbyssEngine::String::SubString((uint)aSStack_30,(uint)param_3);
    AbyssEngine::String::operator=(param_5,aSStack_30);
  }
  else {
    AbyssEngine::String::SubString((uint)aSStack_30,(uint)param_3);
    AbyssEngine::String::operator=(param_5,aSStack_30);
  }
  goto LAB_000f8838;
}

// ===== Globals::getLineArray  @0x000f887c  (454 bytes)
/* Globals::getLineArray(unsigned int, AbyssEngine::String const&, int,
   Array<AbyssEngine::String*>*) */

void __thiscall
Globals::getLineArray(Globals *this,uint param_1,String *param_2,int param_3,Array *param_4)

{
  String *pSVar1;
  Globals *pGVar2;
  void *pvVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  String aSStack_50 [8];
  String aSStack_48 [8];
  String aSStack_40 [8];
  String aSStack_38 [8];
  String aSStack_30 [4];
  int local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  pSVar1 = operator_new(8);
  AbyssEngine::String::String(pSVar1);
  AbyssEngine::String::String(aSStack_30,param_2,false);
  AbyssEngine::String::String(aSStack_38,"\n",false);
  AbyssEngine::String::operator+=(aSStack_30,aSStack_38);
  AbyssEngine::String::~String(aSStack_38);
  if (local_2c < 1) {
    uVar7 = 0;
  }
  else {
    iVar5 = 0;
    uVar7 = 0;
    do {
      AbyssEngine::String::SubString((uint)aSStack_38,(uint)aSStack_30);
      pGVar2 = (Globals *)AbyssEngine::String::String(aSStack_40,aSStack_38,false);
      getLine(pGVar2,param_1,aSStack_40,param_3,pSVar1);
      AbyssEngine::String::~String(aSStack_40);
      iVar6 = *(int *)(pSVar1 + 4);
      AbyssEngine::String::~String(aSStack_38);
      iVar5 = iVar5 + iVar6;
      uVar7 = uVar7 + 1;
    } while (iVar5 < local_2c);
  }
  pvVar3 = (void *)AbyssEngine::String::~String(pSVar1);
  operator_delete(pvVar3);
  ArraySetLength<AbyssEngine::String*>(uVar7,param_4);
  if (0 < (int)uVar7) {
    iVar5 = 0;
    do {
      pSVar1 = operator_new(8);
      AbyssEngine::String::String(pSVar1);
      *(String **)(*(int *)(param_4 + 4) + iVar5 * 4) = pSVar1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)uVar7);
    if (0 < (int)uVar7) {
      iVar5 = 0;
      do {
        AbyssEngine::String::SubString((uint)aSStack_48,(uint)aSStack_30);
        AbyssEngine::String::String(aSStack_50,aSStack_48,false);
        pGVar2 = *(Globals **)(*(int *)(param_4 + 4) + iVar5 * 4);
        getLine(pGVar2,param_1,aSStack_50,param_3,pGVar2);
        AbyssEngine::String::~String(aSStack_50);
        iVar8 = 0;
        pSVar1 = *(String **)(*(int *)(param_4 + 4) + iVar5 * 4);
        iVar6 = *(int *)(pSVar1 + 4);
        while (psVar4 = (short *)AbyssEngine::String::operator[](pSVar1,iVar8), *psVar4 == 0x20) {
          iVar8 = iVar8 + 1;
          pSVar1 = *(String **)(*(int *)(param_4 + 4) + iVar5 * 4);
        }
        iVar6 = iVar6 + 1;
        do {
          psVar4 = (short *)AbyssEngine::String::operator[]
                                      (*(String **)(*(int *)(param_4 + 4) + iVar5 * 4),iVar6 + -2);
          iVar6 = iVar6 + -1;
        } while (*psVar4 == 0x20);
        pSVar1 = *(String **)(*(int *)(param_4 + 4) + iVar5 * 4);
        AbyssEngine::String::SubString((uint)aSStack_38,(uint)pSVar1);
        AbyssEngine::String::operator=(pSVar1,aSStack_38);
        AbyssEngine::String::~String(aSStack_38);
        AbyssEngine::String::~String(aSStack_48);
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)uVar7);
    }
  }
  AbyssEngine::String::~String(aSStack_30);
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== Globals::drawLines  @0x000f8ab0  (132 bytes)
/* Globals::drawLines(unsigned int, Array<AbyssEngine::String*>*, int, int, bool) */

void __thiscall
Globals::drawLines(Globals *this,uint param_1,Array *param_2,int param_3,int param_4,bool param_5)

{
  int iVar1;
  uint uVar2;
  undefined3 in_stack_00000005;
  
  if (*(int *)param_2 != 0) {
    uVar2 = 0;
    iVar1 = 0;
    do {
      if (_param_5 == 1) {
        iVar1 = AbyssEngine::PaintCanvas::GetTextWidth
                          (Canvas,param_1,*(String **)(*(int *)(param_2 + 4) + uVar2 * 4));
        iVar1 = -(iVar1 >> 1);
      }
      AbyssEngine::PaintCanvas::DrawString
                (Canvas,param_1,*(String **)(*(int *)(param_2 + 4) + uVar2 * 4),iVar1 + param_3,
                 param_4,false);
      uVar2 = uVar2 + 1;
      param_4 = param_4 + *(int *)(layout + 4);
    } while (uVar2 < *(uint *)param_2);
  }
  return;
}

// ===== Globals::drawLines  @0x000f8b40  (130 bytes)
/* Globals::drawLines(unsigned int, Array<AbyssEngine::String*>*, int, int, unsigned int, bool) */

void __thiscall
Globals::drawLines(Globals *this,uint param_1,Array *param_2,int param_3,int param_4,uint param_5,
                  bool param_6)

{
  int iVar1;
  uint uVar2;
  undefined3 in_stack_00000009;
  
  if (*(int *)param_2 != 0) {
    uVar2 = 0;
    iVar1 = 0;
    do {
      if (_param_6 == 0) {
        iVar1 = AbyssEngine::PaintCanvas::GetTextWidth
                          (Canvas,param_1,*(String **)(*(int *)(param_2 + 4) + uVar2 * 4));
        iVar1 = param_5 - iVar1;
      }
      AbyssEngine::PaintCanvas::DrawString
                (Canvas,param_1,*(String **)(*(int *)(param_2 + 4) + uVar2 * 4),iVar1 + param_3,
                 param_4,false);
      uVar2 = uVar2 + 1;
      param_4 = param_4 + *(int *)(layout + 4);
    } while (uVar2 < *(uint *)param_2);
  }
  return;
}

// ===== Globals::drawLines  @0x000f8bd0  (24 bytes)
/* Globals::drawLines(unsigned int, Array<AbyssEngine::String*>*, int, int) */

void __thiscall
Globals::drawLines(Globals *this,uint param_1,Array *param_2,int param_3,int param_4)

{
  drawLines((Globals *)0x0,param_1,param_2,param_3,param_4,false);
  return;
}

// ===== Globals::getBoundedString  @0x000f8be8  (188 bytes)
/* Globals::getBoundedString(AbyssEngine::String const&, int) */

void Globals::getBoundedString(String *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  String *this;
  Globals *pGVar3;
  void *pvVar4;
  String *in_r2;
  int in_r3;
  String aSStack_38 [8];
  AbyssEngine aAStack_30 [8];
  String aSStack_28 [8];
  int local_20;
  
  local_20 = __stack_chk_guard;
  AbyssEngine::String::String((String *)param_1,in_r2,false);
  iVar2 = AbyssEngine::PaintCanvas::GetTextWidth(Canvas,font,in_r2);
  if (in_r3 < iVar2) {
    this = operator_new(8);
    AbyssEngine::String::String(this);
    uVar1 = font;
    pGVar3 = (Globals *)AbyssEngine::String::String(aSStack_28,in_r2,false);
    getLine(pGVar3,uVar1,aSStack_28,in_r3 + -3,this);
    AbyssEngine::String::~String(aSStack_28);
    AbyssEngine::String::String(aSStack_38,"...",false);
    AbyssEngine::operator+(aAStack_30,this,aSStack_38);
    AbyssEngine::String::operator=((String *)param_1,aAStack_30);
    AbyssEngine::String::~String((String *)aAStack_30);
    AbyssEngine::String::~String(aSStack_38);
    pvVar4 = (void *)AbyssEngine::String::~String(this);
    operator_delete(pvVar4);
  }
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Globals::releaseResources  @0x000f8cf8  (34 bytes)
/* Globals::releaseResources() */

void Globals::releaseResources(void)

{
  AbyssEngine::PaintCanvas::ReleaseAllResources(Canvas);
  Layout::reload(layout);
  return;
}

// ===== Globals::loadFont  @0x000f8d20  (622 bytes)
/* Globals::loadFont(int) */

void __thiscall Globals::loadFont(Globals *this,int param_1)

{
  ushort uVar1;
  PaintCanvas *pPVar2;
  PaintCanvas PVar3;
  short sVar4;
  
  sVar4 = -8;
  uVar1 = (ushort)Canvas;
  switch(param_1) {
  case 9:
    AbyssEngine::PaintCanvas::FontCreate(uVar1,(uint *)0x2d74,true);
    if (iPadHD == '\0') {
      if (retinaDisplay == '\0') {
        sVar4 = -4;
      }
    }
    else {
      sVar4 = -6;
    }
    AbyssEngine::PaintCanvas::FontSetSpacing(Canvas,font,sVar4);
    PVar3 = (PaintCanvas)0x0;
    goto LAB_000f8f44;
  case 10:
    AbyssEngine::PaintCanvas::FontCreate(uVar1,(uint *)0x2d78,true);
    if (iPadHD == '\0') {
      if (retinaDisplay == '\0') {
        sVar4 = -4;
      }
    }
    else {
      sVar4 = -6;
    }
    AbyssEngine::PaintCanvas::FontSetSpacing(Canvas,font,sVar4);
    break;
  case 0xb:
    AbyssEngine::PaintCanvas::FontCreate(uVar1,(uint *)0x2d76,true);
    if (iPadHD == '\0') {
      if (retinaDisplay == '\0') {
        sVar4 = -4;
      }
    }
    else {
      sVar4 = -6;
    }
    AbyssEngine::PaintCanvas::FontSetSpacing(Canvas,font,sVar4);
    break;
  default:
    if (param_1 == 0xf) {
      AbyssEngine::PaintCanvas::FontCreate(uVar1,(uint *)0x2d7e,true);
      if (iPadHD == '\0') {
        sVar4 = -5;
        if (retinaDisplay != '\0') {
          sVar4 = -10;
        }
      }
      else {
        sVar4 = -7;
      }
      AbyssEngine::PaintCanvas::FontSetSpacing(Canvas,font,sVar4);
      pPVar2 = Canvas;
      Canvas[0x1c] = (PaintCanvas)0x1;
      goto LAB_000f8f4a;
    }
    AbyssEngine::PaintCanvas::FontCreate(uVar1,(uint *)0x457,true);
    if (retinaDisplay == '\0') {
      if ((n9 == '\0') && (iPadHD == '\0')) {
        sVar4 = -2;
      }
      else {
        sVar4 = -4;
      }
    }
    else {
      sVar4 = -5;
    }
    AbyssEngine::PaintCanvas::FontSetSpacing(Canvas,font,sVar4);
    PVar3 = (PaintCanvas)0x1;
LAB_000f8f44:
    pPVar2 = Canvas;
    Canvas[0x1c] = PVar3;
    goto LAB_000f8f4a;
  case 0xe:
    AbyssEngine::PaintCanvas::FontCreate(uVar1,(uint *)0x2d7c,true);
    if (iPadHD == '\0') {
      if (retinaDisplay == '\0') {
        sVar4 = -4;
      }
    }
    else {
      sVar4 = -6;
    }
    AbyssEngine::PaintCanvas::FontSetSpacing(Canvas,font,sVar4);
  }
  pPVar2 = Canvas;
  Canvas[0x1c] = (PaintCanvas)0x1;
LAB_000f8f4a:
  AbyssEngine::PaintCanvas::FontCreate((ushort)pPVar2,(uint *)0x51e,true);
  AbyssEngine::PaintCanvas::FontSetSpacing(Canvas,fontAlien,0);
  AbyssEngine::PaintCanvas::FontCreate((ushort)Canvas,(uint *)0x2d7a,true);
  AbyssEngine::PaintCanvas::FontSetSpacing(Canvas,fontLangSelect,0);
  return;
}

// ===== Globals::getRandomEnemyFighter  @0x000f9034  (162 bytes)
/* Globals::getRandomEnemyFighter(int) */

uint __thiscall Globals::getRandomEnemyFighter(Globals *this,int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = param_1;
  if (1 < param_1 - 9U) {
    iVar2 = 8;
  }
  if (param_1 < 4) {
    iVar2 = param_1;
  }
  if (iVar2 == 1) {
    iVar2 = Status::dlc1Won(status);
    if (iVar2 == 1) {
      iVar2 = AbyssEngine::AERandom::nextInt(rnd,100);
      uVar1 = 0x27;
      if (iVar2 < 0x55) {
        uVar1 = 0x29;
      }
      if (iVar2 < 0x3c) {
        uVar1 = 9;
      }
    }
    else {
      uVar1 = 9;
    }
  }
  else if (iVar2 == 9) {
    uVar1 = 8;
  }
  else if (iVar2 == 10) {
    uVar1 = 0x2c;
  }
  else {
    do {
      do {
        uVar1 = AbyssEngine::AERandom::nextInt(rnd,0x25);
      } while ((uVar1 & 0xfffffffb) - 9 < 2);
    } while (((uVar1 < 0x10) && ((1 << (uVar1 & 0xff) & 0x8101U) != 0)) ||
            (*(int *)(&DAT_00254990 + uVar1 * 4) != iVar2));
  }
  return uVar1;
}

// ===== Globals::getRandomPlanetName  @0x000f90e8  (78 bytes)
/* Globals::getRandomPlanetName() */

void Globals::getRandomPlanetName(void)

{
  FileRead *this;
  int iVar1;
  Station *this_00;
  void *pvVar2;
  
  this = operator_new(1);
  FileRead::FileRead(this);
  iVar1 = AbyssEngine::AERandom::nextInt(rnd,100);
  this_00 = (Station *)FileRead::loadStation(this,iVar1);
  Station::getName();
  if (this_00 != (Station *)0x0) {
    pvVar2 = (void *)Station::~Station(this_00);
    operator_delete(pvVar2);
  }
  pvVar2 = (void *)FileRead::~FileRead(this);
  operator_delete(pvVar2);
  return;
}

// ===== Globals::getRandomStation  @0x000f9148  (54 bytes)
/* Globals::getRandomStation() */

undefined4 Globals::getRandomStation(void)

{
  FileRead *this;
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  this = operator_new(1);
  FileRead::FileRead(this);
  iVar1 = AbyssEngine::AERandom::nextInt(rnd,0x87);
  uVar2 = FileRead::loadStation(this,iVar1);
  pvVar3 = (void *)FileRead::~FileRead(this);
  operator_delete(pvVar3);
  return uVar2;
}

// ===== Globals::getRandomSystemForDrinks  @0x000f9190  (40 bytes)
/* Globals::getRandomSystemForDrinks() */

void Globals::getRandomSystemForDrinks(void)

{
  Galaxy *this;
  int iVar1;
  
  this = galaxy;
  iVar1 = AbyssEngine::AERandom::nextInt(rnd,0x16);
  Galaxy::getSystem(this,iVar1);
  return;
}

// ===== Globals::getItemName  @0x000f91c0  (34 bytes)
/* Globals::getItemName(int) */

void Globals::getItemName(int param_1)

{
  String *pSVar1;
  int in_r2;
  
  pSVar1 = (String *)GameText::getText(gameText,in_r2 + 0x4fa);
  AbyssEngine::String::String((String *)param_1,pSVar1,false);
  return;
}

// ===== Globals::reportLeaderboards  @0x000f91e8  (26 bytes)
/* Globals::reportLeaderboards() */

void Globals::reportLeaderboards(void)

{
  g_android_leaderboard_scores._0_4_ = Status::getKills(status);
  return;
}

// ===== Globals::reportSupernovaChallengeScore  @0x000f920c  (2 bytes)
/* Globals::reportSupernovaChallengeScore() */

void Globals::reportSupernovaChallengeScore(void)

{
  return;
}

// ===== Globals::getWreckCollision  @0x000f9210  (618 bytes)
/* Globals::getWreckCollision(int, AEGeometry*) */

void Globals::getWreckCollision(int param_1,AEGeometry *param_2)

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
  float fVar11;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s3;
  float extraout_s3_00;
  float extraout_s5;
  float extraout_s5_00;
  float extraout_s7;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  this = operator_new(1);
  FileRead::FileRead(this);
  pvVar1 = (void *)FileRead::loadWreckCollision(this,(int)param_2);
  pvVar2 = (void *)FileRead::~FileRead(this);
  operator_delete(pvVar2);
  if (pvVar1 != (void *)0x0) {
    uVar8 = **(uint **)((int)pvVar1 + 4);
    local_30 = 0.0;
    local_2c = 0.0;
    local_40 = 0.0;
    local_3c = 0.0;
    local_38 = 0.0;
    local_34 = 0.0;
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
          local_34 = (float)VectorSignedToFloat(-*(int *)(iVar5 + iVar6 * 4),
                                                (byte)(in_fpscr >> 0x16) & 3);
          local_2c = (float)VectorSignedToFloat(*(undefined4 *)(iVar7 + 8),
                                                (byte)(in_fpscr >> 0x16) & 3);
          local_30 = (float)VectorSignedToFloat(*(undefined4 *)(iVar7 + 0xc),
                                                (byte)(in_fpscr >> 0x16) & 3);
          local_40 = (float)VectorSignedToFloat(*(undefined4 *)(iVar7 + 0x10),
                                                (byte)(in_fpscr >> 0x16) & 3);
          local_38 = (float)VectorSignedToFloat(*(undefined4 *)(iVar7 + 0x14),
                                                (byte)(in_fpscr >> 0x16) & 3);
          local_3c = (float)VectorSignedToFloat(*(undefined4 *)(iVar7 + 0x18),
                                                (byte)(in_fpscr >> 0x16) & 3);
          fVar11 = (float)AbyssEngine::AEMath::Vector::operator*=((Vector *)&local_40,local_3c);
          if (param_2 == (AEGeometry *)0x0) {
            fVar11 = (float)AbyssEngine::AEMath::Vector::operator*=((Vector *)&local_34,fVar11);
            AbyssEngine::AEMath::Vector::operator*=((Vector *)&local_40,fVar11);
          }
          this_01 = operator_new(0x2c);
          BoundingAAB::BoundingAAB
                    (this_01,local_40 + local_40,extraout_s1_00,local_3c + local_3c,extraout_s3_00,
                     local_38 + local_38,extraout_s5_00,local_34,extraout_s7,local_30);
          iVar6 = iVar10 + 7;
          *(BoundingAAB **)(*(int *)(pAVar3 + 4) + iVar9 * 4) = this_01;
        }
        else if (iVar7 == 0) {
          iVar7 = iVar5 + iVar10 * 4;
          local_34 = (float)VectorSignedToFloat(-*(int *)(iVar5 + iVar6 * 4),
                                                (byte)(in_fpscr >> 0x16) & 3);
          local_2c = (float)VectorSignedToFloat(*(undefined4 *)(iVar7 + 8),
                                                (byte)(in_fpscr >> 0x16) & 3);
          local_30 = (float)VectorSignedToFloat(*(undefined4 *)(iVar7 + 0xc),
                                                (byte)(in_fpscr >> 0x16) & 3);
          local_40 = (float)VectorSignedToFloat(*(undefined4 *)(iVar7 + 0x10),
                                                (byte)(in_fpscr >> 0x16) & 3);
          AbyssEngine::AEMath::Vector::operator*=((Vector *)&local_40,local_40);
          in_fpscr = in_fpscr & 0xfffffff;
          fVar11 = local_40;
          if (local_40 < 0.0) {
            fVar11 = (float)AbyssEngine::AEMath::Vector::operator*=((Vector *)&local_40,local_40);
          }
          if (param_2 == (AEGeometry *)0x0) {
            fVar11 = (float)AbyssEngine::AEMath::Vector::operator*=((Vector *)&local_34,fVar11);
            AbyssEngine::AEMath::Vector::operator*=((Vector *)&local_40,fVar11);
          }
          this_00 = operator_new(0x48);
          BoundingSphere::BoundingSphere
                    (this_00,local_34,extraout_s1,local_30,extraout_s3,local_2c,extraout_s5,local_40
                    );
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
    *(undefined4 *)((int)pvVar1 + 4) = 0;
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

// ===== Globals::getShipGroup  @0x000f94a4  (1948 bytes)
/* Globals::getShipGroup(int, int, bool) */

void __thiscall Globals::getShipGroup(Globals *this,int param_1,int param_2,bool param_3)

{
  ushort uVar1;
  short sVar2;
  AEGeometry *pAVar3;
  Matrix *pMVar4;
  uint uVar5;
  ushort *puVar6;
  uint *puVar7;
  int *piVar8;
  ushort *puVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  undefined4 extraout_r1;
  short sVar13;
  int iVar14;
  uint uVar15;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s2;
  float extraout_s2_00;
  float extraout_s2_01;
  uint local_90;
  ushort local_8c [2];
  uint local_88 [15];
  ushort local_4c [2];
  uint local_48;
  uint local_44;
  uint local_40;
  int local_3c;
  
  local_3c = __stack_chk_guard;
  if (param_1 == 0xf) {
    if (param_2 != 0) {
      if (param_2 == 3) {
        pAVar3 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar3,0x4299,Canvas,false);
        local_48 = 0xffffffff;
        AbyssEngine::PaintCanvas::TransformCreate(Canvas,&local_48);
        AbyssEngine::PaintCanvas::TransformAddMesh(Canvas,local_48,0x429f,false);
        AEGeometry::addChild(pAVar3,local_48);
        iVar10 = AbyssEngine::AERandom::nextInt(rnd,4);
        local_90 = 0xffffffff;
        if (0 < iVar10) {
          iVar14 = 0;
          uVar12 = 0xffffffff;
          local_90 = 0xffffffff;
          do {
            local_44 = 0xffffffff;
            local_40 = 0xffffffff;
            AbyssEngine::PaintCanvas::TransformCreate(Canvas,&local_40);
            AbyssEngine::PaintCanvas::TransformCreate(Canvas,&local_44);
            AbyssEngine::PaintCanvas::TransformAddMesh(Canvas,local_40,0x429c,false);
            AbyssEngine::PaintCanvas::TransformAddMesh(Canvas,local_44,0x429d,false);
            if (uVar12 == 0xffffffff) {
              local_90 = local_44;
              uVar12 = local_40;
            }
            else {
              AbyssEngine::PaintCanvas::TransformAddChild(Canvas,uVar12,local_40);
              AbyssEngine::PaintCanvas::TransformAddChild(Canvas,local_90,local_44);
            }
            pMVar4 = (Matrix *)AbyssEngine::PaintCanvas::TransformGetLocal(Canvas,local_40);
            AbyssEngine::AEMath::MatrixSetTranslation
                      ((AEMath *)local_88,pMVar4,extraout_s0,extraout_s1,extraout_s2);
            pMVar4 = (Matrix *)AbyssEngine::PaintCanvas::TransformGetLocal(Canvas,local_44);
            AbyssEngine::AEMath::MatrixSetTranslation
                      ((AEMath *)local_88,pMVar4,extraout_s0_00,extraout_s1_00,extraout_s2_00);
            iVar14 = iVar14 + 1;
          } while (iVar10 != iVar14);
          if (uVar12 != 0xffffffff) {
            iVar10 = AbyssEngine::PaintCanvas::TransformGetTransform(Canvas,uVar12);
            *(undefined4 *)(iVar10 + 0xe0) = 0x47c35000;
            AEGeometry::addChild(pAVar3,uVar12);
          }
        }
        local_88[0] = 0xffffffff;
        AbyssEngine::PaintCanvas::TransformCreate(Canvas,local_88);
        AbyssEngine::PaintCanvas::TransformAddMesh(Canvas,local_88[0],0x429e,false);
        AEGeometry::addChild(pAVar3,local_88[0]);
        local_44 = CONCAT22(local_44._2_2_,0x429a);
        local_40 = 35000;
        AEGeometry::setLodMeshes(pAVar3,(ushort *)&local_44,(int *)&local_40,1);
        AEGeometry::setLodChildTransform(pAVar3,local_90);
      }
      else {
        pAVar3 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar3,0x42a4,Canvas,false);
        local_48 = 0xffffffff;
        AbyssEngine::PaintCanvas::TransformCreate(Canvas,&local_48);
        AbyssEngine::PaintCanvas::TransformAddMesh(Canvas,local_48,0x42a5,false);
        AEGeometry::addChild(pAVar3,local_48);
        local_40 = 0xffffffff;
        AbyssEngine::PaintCanvas::TransformCreate(Canvas,&local_40);
        AbyssEngine::PaintCanvas::TransformAddMesh(Canvas,local_40,0x42a8,false);
        AEGeometry::addChild(pAVar3,local_40);
        local_44 = 0x42a742a6;
        local_88[0] = 35000;
        local_88[1] = 60000;
        AEGeometry::setLodMeshes(pAVar3,(ushort *)&local_44,(int *)local_88,2);
      }
      goto LAB_000f9c24;
    }
    pAVar3 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar3,0x42a9,Canvas,false);
    local_48 = 0xffffffff;
    AbyssEngine::PaintCanvas::TransformCreate(Canvas,&local_48);
    AbyssEngine::PaintCanvas::TransformAddMesh(Canvas,local_48,0x42ae,false);
    AEGeometry::addChild(pAVar3,local_48);
    local_40 = 0xffffffff;
    AbyssEngine::PaintCanvas::TransformCreate(Canvas,&local_40);
    AbyssEngine::PaintCanvas::TransformAddMesh(Canvas,local_40,0x42b2,false);
    AEGeometry::addChild(pAVar3,local_40);
    local_44 = 0xffffffff;
    AbyssEngine::PaintCanvas::TransformCreate(Canvas,&local_44);
    AbyssEngine::PaintCanvas::TransformAddMesh(Canvas,local_44,0x42ad,false);
    AEGeometry::addChild(pAVar3,local_44);
    local_4c[0] = 0x42aa;
    local_4c[1] = 0x42ab;
    local_88[1] = 45000;
    local_88[0] = 25000;
    AEGeometry::setLodMeshes(pAVar3,local_4c,(int *)local_88,2);
    puVar6 = local_8c;
    local_8c[0] = 0x42ae;
    local_8c[1] = 0x42ae;
LAB_000f9aac:
    AEGeometry::setLodChildMeshes(pAVar3,puVar6);
    goto LAB_000f9c24;
  }
  if (param_1 == 0xe) {
    pAVar3 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar3,0x37e7,Canvas,false);
    local_48 = 0xffffffff;
    AbyssEngine::PaintCanvas::TransformCreate(Canvas,&local_48);
    AbyssEngine::PaintCanvas::TransformAddMesh(Canvas,local_48,0x37ec,false);
    AEGeometry::addChild(pAVar3,local_48);
    local_40 = 0xffffffff;
    AbyssEngine::PaintCanvas::TransformCreate(Canvas,&local_40);
    AbyssEngine::PaintCanvas::TransformAddMesh(Canvas,local_40,0x37eb,false);
    AEGeometry::addChild(pAVar3,local_40);
    local_44 = 0x37e937e8;
    local_88[0] = 35000;
    local_88[1] = 60000;
    AEGeometry::setLodMeshes(pAVar3,(ushort *)&local_44,(int *)local_88,2);
    local_4c[0] = 0x37ec;
    local_4c[1] = 0x37ec;
    AEGeometry::setLodChildMeshes(pAVar3,local_4c);
    AEGeometry::setScaling(pAVar3,extraout_s0_01,extraout_s1_01,extraout_s2_01);
    goto LAB_000f9c24;
  }
  if (param_1 == 0xd) {
    pAVar3 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar3,0x4275,Canvas,false);
    local_48 = 0xffffffff;
    AbyssEngine::PaintCanvas::TransformCreate(Canvas,&local_48);
    AbyssEngine::PaintCanvas::TransformAddMesh(Canvas,local_48,0x4919,false);
    AEGeometry::addChild(pAVar3,local_48);
    local_40 = 0xffffffff;
    AbyssEngine::PaintCanvas::TransformCreate(Canvas,&local_40);
    AbyssEngine::PaintCanvas::TransformAddMesh(Canvas,local_40,0x428e,false);
    AEGeometry::addChild(pAVar3,local_40);
    local_44 = 0x42f442f3;
    local_88[0] = 35000;
    local_88[1] = 45000;
    AEGeometry::setLodMeshes(pAVar3,(ushort *)&local_44,(int *)local_88,2);
    puVar6 = local_4c;
    local_4c[0] = 0x4290;
    local_4c[1] = 0x4291;
    goto LAB_000f9aac;
  }
  pAVar3 = operator_new(0xc0);
  AEGeometry::AEGeometry(pAVar3,*(ushort *)(&DAT_00254a90 + param_1 * 2),Canvas,true);
  local_88[0] = 0xffffffff;
  local_48 = 0xffffffff;
  if (*(ushort *)(&DAT_00254b10 + param_1 * 2) != 0xffff) {
    AbyssEngine::PaintCanvas::MeshCreate
              (Canvas,*(ushort *)(&DAT_00254b10 + param_1 * 2),&local_48,true);
    AbyssEngine::PaintCanvas::TransformCreate(Canvas,local_88);
    AbyssEngine::PaintCanvas::TransformAddMeshId(Canvas,local_88[0],local_48);
    AEGeometry::addChild(pAVar3,local_88[0]);
    *(uint *)(pAVar3 + 0x20) = local_48;
  }
  sVar2 = (short)param_1;
  if (!param_3) {
    local_40 = 0xffffffff;
    AbyssEngine::PaintCanvas::MaterialCreate(Canvas,sVar2 + 0x7dc8U,&local_40);
    AbyssEngine::PaintCanvas::MeshChangeResourceMaterial
              (Canvas,*(uint *)(pAVar3 + 0x1c),sVar2 + 0x7dc8U);
  }
  uVar1 = *(ushort *)(&DAT_00254b90 + param_1 * 2);
  if (uVar1 != 0xffff) {
    local_40 = 0xffffffff;
    AbyssEngine::PaintCanvas::TransformCreate(Canvas,&local_40);
    AbyssEngine::PaintCanvas::TransformAddMesh(Canvas,local_40,uVar1,false);
    AEGeometry::addChild(pAVar3,local_40);
  }
  if (param_3) {
    if (param_1 != 0x27 && param_1 != 0x29) {
      local_40 = 0xffffffff;
      AbyssEngine::PaintCanvas::TransformCreate(Canvas,&local_40);
      sVar13 = 0x45ec;
      goto LAB_000f98de;
    }
  }
  else {
    local_40 = 0xffffffff;
    AbyssEngine::PaintCanvas::TransformCreate(Canvas,&local_40);
    sVar13 = 18000;
LAB_000f98de:
    AbyssEngine::PaintCanvas::TransformAddMesh(Canvas,local_40,sVar13 + sVar2,false);
    AEGeometry::addChild(pAVar3,local_40);
  }
  iVar10 = 0;
  uVar12 = 0;
  do {
    uVar15 = uVar12;
    iVar14 = *(int *)(&DAT_00254c10 + iVar10 * 4 + param_1 * 0xc);
    iVar10 = iVar10 + 1;
    uVar12 = uVar15;
    if (iVar14 != 0xffff) {
      uVar12 = uVar15 + 1;
    }
  } while (iVar10 != 2);
  uVar11 = 2;
  if (0 < (int)uVar12) {
    uVar5 = uVar12 * 2;
    if (uVar5 < uVar12) {
      uVar5 = 0xffffffff;
    }
    puVar6 = operator_new__(uVar5);
    uVar5 = (uint)((ulonglong)uVar12 * 4);
    if ((int)((ulonglong)uVar12 * 4 >> 0x20) != 0) {
      uVar5 = 0xffffffff;
    }
    puVar7 = operator_new__(uVar5);
    piVar8 = operator_new__(uVar5);
    if (iVar14 != 0xffff) {
      uVar15 = uVar15 + 1;
    }
    iVar14 = 5000;
    iVar10 = 0;
    puVar9 = puVar6;
    do {
      uVar11 = *(undefined4 *)(&DAT_00254c10 + iVar10 + param_1 * 0xc);
      *puVar9 = (ushort)uVar11;
      *(int *)((int)piVar8 + iVar10) = iVar14;
      if (!param_3) {
        AbyssEngine::PaintCanvas::MeshCreate
                  (Canvas,(ushort)uVar11,(uint *)((int)puVar7 + iVar10),true);
        AbyssEngine::PaintCanvas::MeshChangeResourceMaterial
                  (Canvas,*(uint *)((int)puVar7 + iVar10),sVar2 + 0x7dc8);
      }
      uVar15 = uVar15 - 1;
      iVar10 = iVar10 + 4;
      iVar14 = iVar14 + 8000;
      puVar9 = puVar9 + 1;
    } while (uVar15 != 0);
    if (param_3) {
      AEGeometry::setLodMeshes(pAVar3,puVar6,piVar8,uVar12);
    }
    else {
      AEGeometry::setLodMeshesWithMeshIds(pAVar3,puVar6,puVar7,piVar8,uVar12);
    }
    iVar10 = 0;
    uVar12 = 0;
    do {
      uVar15 = uVar12;
      iVar14 = iVar10 * 4;
      iVar10 = iVar10 + 1;
      uVar12 = uVar15;
      if (*(int *)(&DAT_00254f10 + iVar14 + param_1 * 0xc) != 0xffff) {
        uVar12 = uVar15 + 1;
      }
    } while (iVar10 != 2);
    if (0 < (int)uVar12) {
      uVar5 = uVar12 * 2;
      if (*(int *)(&DAT_00254f10 + iVar14 + param_1 * 0xc) != 0xffff) {
        uVar15 = uVar15 + 1;
      }
      if (uVar5 < uVar12) {
        uVar5 = 0xffffffff;
      }
      puVar9 = operator_new__(uVar5);
      uVar12 = 0;
      do {
        puVar9[uVar12] = (ushort)*(undefined4 *)(&DAT_00254f10 + uVar12 * 4 + param_1 * 0xc);
        uVar12 = uVar12 + 1;
      } while (uVar15 != uVar12);
      AEGeometry::setLodChildMeshes(pAVar3,puVar9);
      operator_delete__(puVar9);
    }
    operator_delete__(puVar6);
    operator_delete__(piVar8);
    uVar11 = extraout_r1;
  }
  AEGeometry::setLodLastVisibleDistance(CONCAT44(uVar11,pAVar3));
LAB_000f9c24:
  if (__stack_chk_guard - local_3c == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_3c);
}

// ===== Globals::startNewSoundResourceList  @0x000f9ce8  (134 bytes)
/* Globals::startNewSoundResourceList() */

void __thiscall Globals::startNewSoundResourceList(Globals *this)

{
  int *piVar1;
  undefined4 *__ptr;
  void *pvVar2;
  void *pvVar3;
  
  pvVar3 = *(void **)(this + 4);
  if (pvVar3 != (void *)0x0) {
    if (*(void **)((int)pvVar3 + 4) == (void *)0x0) {
      *(undefined4 *)((int)pvVar3 + 4) = 0;
    }
    else {
      operator_delete__(*(void **)((int)pvVar3 + 4));
      pvVar2 = *(void **)(this + 4);
      *(undefined4 *)((int)pvVar3 + 4) = 0;
      pvVar3 = pvVar2;
      if (pvVar2 == (void *)0x0) goto LAB_000f9d1a;
    }
    if (*(void **)((int)pvVar3 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar3 + 4));
    }
    operator_delete(pvVar3);
  }
LAB_000f9d1a:
  *(undefined4 *)(this + 4) = 0;
  piVar1 = operator_new(0xc);
  __ptr = operator_new__(4);
  piVar1[1] = (int)__ptr;
  *__ptr = 0;
  *piVar1 = 0;
  *(int **)(this + 4) = piVar1;
  piVar1[2] = 1;
  pvVar3 = realloc(__ptr,4);
  piVar1[1] = (int)pvVar3;
  *(undefined4 *)((int)pvVar3 + *piVar1 * 4) = 0x7c;
  *piVar1 = piVar1[2];
  piVar1 = *(int **)(this + 4);
  piVar1[2] = *piVar1 + 1;
  pvVar3 = realloc((void *)piVar1[1],(*piVar1 + 1) * 4);
  piVar1[1] = (int)pvVar3;
  *(undefined4 *)((int)pvVar3 + *piVar1 * 4) = 0x7b;
  *piVar1 = piVar1[2];
  return;
}

// ===== Globals::getSoundResourceList  @0x000f9d7c  (4 bytes)
/* Globals::getSoundResourceList() */

undefined4 __thiscall Globals::getSoundResourceList(Globals *this)

{
  return *(undefined4 *)(this + 4);
}

// ===== Globals::addSoundResourceToList  @0x000f9d80  (62 bytes)
/* Globals::addSoundResourceToList(int) */

void __thiscall Globals::addSoundResourceToList(Globals *this,int param_1)

{
  void *pvVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar4 = *(uint **)(this + 4);
  if (puVar4 != (uint *)0x0) {
    uVar2 = *puVar4;
    if (uVar2 == 0) {
      pvVar1 = (void *)puVar4[1];
      uVar2 = 1;
    }
    else {
      pvVar1 = (void *)puVar4[1];
      uVar3 = 0;
      do {
        if (*(int *)((int)pvVar1 + uVar3 * 4) == param_1) {
          return;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar2);
      uVar2 = uVar2 + 1;
    }
    puVar4[2] = uVar2;
    pvVar1 = realloc(pvVar1,uVar2 << 2);
    puVar4[1] = (uint)pvVar1;
    *(int *)((int)pvVar1 + *puVar4 * 4) = param_1;
    *puVar4 = puVar4[2];
  }
  return;
}

// ===== Globals::playMusicAndFadeOutCurrent  @0x000f9dc0  (696 bytes)
/* Globals::playMusicAndFadeOutCurrent(int) */

Globals * __thiscall Globals::playMusicAndFadeOutCurrent(Globals *this,int param_1)

{
  SolarSystem *pSVar1;
  int iVar2;
  Station *pSVar3;
  int iVar4;
  FModSound *pFVar5;
  Globals *pGVar6;
  Mission *pMVar7;
  undefined *puVar8;
  float extraout_s0;
  float fVar9;
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
  
  if (param_1 == 2) {
    fVar9 = (float)FModSound::stop(sound,*(int *)sound);
    iVar2 = 0x91;
    pFVar5 = sound;
    goto LAB_000f9f54;
  }
  if (param_1 == 1) {
    iVar2 = Status::inAlienOrbit(status);
    if (iVar2 == 1) {
      FModSound::stop(sound,*(int *)sound);
      pFVar5 = sound;
      iVar4 = Status::getCurrentCampaignMission(status);
      iVar2 = 0x88;
      fVar9 = extraout_s0_00;
      if ((0x92 < iVar4) &&
         (iVar4 = Status::getCurrentCampaignMission(status), fVar9 = extraout_s0_01, iVar4 < 0x9a))
      {
        iVar2 = 0x91;
      }
      goto LAB_000f9f54;
    }
    pSVar1 = (SolarSystem *)Status::getSystem(status);
    iVar2 = SolarSystem::getRace(pSVar1);
    FModSound::stop(sound,*(int *)sound);
    pSVar3 = (Station *)Status::getStation(status);
    iVar4 = Station::getIndex(pSVar3);
    if (iVar4 == 0x6c) {
      iVar2 = 0x92;
      pFVar5 = sound;
      fVar9 = extraout_s0_03;
      goto LAB_000f9f54;
    }
    pSVar3 = (Station *)Status::getStation(status);
    iVar4 = Station::getIndex(pSVar3);
    if (iVar4 == 0x65) {
      iVar2 = 0x93;
      pFVar5 = sound;
      fVar9 = extraout_s0_07;
      goto LAB_000f9f54;
    }
    iVar4 = Status::inSupernovaSystem(status);
    if (iVar4 == 1) {
      iVar2 = Status::getCurrentCampaignMission(status);
      if (iVar2 == 0x59) {
        iVar2 = 0x8be;
        pFVar5 = sound;
        fVar9 = extraout_s0_08;
      }
      else {
        iVar2 = Status::getMission(status);
        fVar9 = extraout_s0_10;
        if (iVar2 != 0) {
          pMVar7 = (Mission *)Status::getMission(status);
          iVar2 = Mission::isEmpty(pMVar7);
          fVar9 = extraout_s0_11;
          if (iVar2 == 0) {
            pMVar7 = (Mission *)Status::getMission(status);
            iVar2 = Mission::getTargetStation(pMVar7);
            pSVar3 = (Station *)Status::getStation(status);
            iVar4 = Station::getIndex(pSVar3);
            fVar9 = extraout_s0_12;
            if (iVar2 == iVar4) {
              iVar2 = Status::getCurrentCampaignMission(status);
              pFVar5 = sound;
              fVar9 = extraout_s0_13;
              if (iVar2 < 0x6a) {
                iVar2 = 0x8c1;
              }
              else {
                iVar2 = 0x8c2;
              }
              goto LAB_000f9f54;
            }
          }
        }
        iVar2 = 0x94;
        pFVar5 = sound;
      }
      goto LAB_000f9f54;
    }
    iVar4 = Status::inDeepScienceOrbit(status);
    if (iVar4 == 1) {
      iVar2 = 0x98;
      pFVar5 = sound;
      fVar9 = extraout_s0_09;
      goto LAB_000f9f54;
    }
    pSVar3 = (Station *)Status::getStation(status);
    iVar4 = Station::getIndex(pSVar3);
    fVar9 = extraout_s0_14;
    if ((iVar4 == 0x78) &&
       ((iVar4 = Status::getCurrentCampaignMission(status), fVar9 = extraout_s0_15, iVar4 == 0x7e ||
        (iVar4 = Status::getCurrentCampaignMission(status), fVar9 = extraout_s0_16, iVar4 == 0x85)))
       ) {
      iVar2 = 0x8bf;
      pFVar5 = sound;
      goto LAB_000f9f54;
    }
    puVar8 = &DAT_00252010;
LAB_000fa06c:
    iVar2 = *(int *)(puVar8 + iVar2 * 4);
    pFVar5 = sound;
  }
  else {
    if (param_1 != 0) {
      return this;
    }
    pSVar1 = (SolarSystem *)Status::getSystem(status);
    iVar2 = SolarSystem::getRace(pSVar1);
    FModSound::stop(sound,*(int *)sound);
    pSVar3 = (Station *)Status::getStation(status);
    iVar4 = Station::getIndex(pSVar3);
    if (iVar4 == 0x6c) {
      iVar2 = 0x84;
      pFVar5 = sound;
      fVar9 = extraout_s0;
      goto LAB_000f9f54;
    }
    pSVar3 = (Station *)Status::getStation(status);
    iVar4 = Station::getIndex(pSVar3);
    if (iVar4 == 0x65) {
      iVar2 = 0x83;
      pFVar5 = sound;
      fVar9 = extraout_s0_02;
      goto LAB_000f9f54;
    }
    pSVar3 = (Station *)Status::getStation(status);
    iVar4 = Station::getIndex(pSVar3);
    if (iVar4 != 10) {
      pSVar3 = (Station *)Status::getStation(status);
      iVar4 = Station::getIndex(pSVar3);
      if (iVar4 != 100) {
        puVar8 = &DAT_00252000;
        fVar9 = extraout_s0_04;
        goto LAB_000fa06c;
      }
    }
    pSVar3 = (Station *)Status::getStation(status);
    iVar2 = Station::getIndex(pSVar3);
    fVar9 = extraout_s0_05;
    if ((iVar2 == 10) &&
       (iVar2 = Status::getCurrentCampaignMission(status), fVar9 = extraout_s0_06, iVar2 == 0x9f)) {
      iVar2 = 0x90;
      pFVar5 = sound;
    }
    else {
      iVar2 = 0x85;
      pFVar5 = sound;
    }
  }
LAB_000f9f54:
  pGVar6 = (Globals *)FModSound::play(pFVar5,iVar2,(Vector *)0x0,(Vector *)0x0,fVar9);
  return pGVar6;
}

// ===== Globals::getDialogueSoundId  @0x000fa110  (1258 bytes)
/* Globals::getDialogueSoundId(int, Agent*) */

int __thiscall Globals::getDialogueSoundId(Globals *this,int param_1,Agent *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = 0;
  do {
    if ((&DAT_00255210)[iVar1] == param_1) {
      return *(int *)(&UNK_00255214 + iVar1 * 4);
    }
    iVar1 = iVar1 + 2;
  } while (iVar1 < 0xbc0);
  if (param_2 == (Agent *)0x0) {
    return -1;
  }
  iVar1 = Agent::getRace(param_2);
  iVar2 = Agent::isMale(param_2);
  if (iVar1 == 3) {
    iVar1 = Agent::getImageParts(param_2);
    if (iVar1 != 0) {
      piVar3 = (int *)Agent::getImageParts(param_2);
      iVar1 = 0;
      if (*piVar3 == 2) {
        iVar1 = 3;
      }
      goto LAB_000fa166;
    }
code_r0x000fa1e8:
    iVar2 = -1;
    iVar1 = 0x26b;
    switch(param_1) {
    case 0x172:
      iVar1 = 0x27e;
      break;
    case 0x173:
      iVar1 = 0x272;
      break;
    case 0x174:
      iVar1 = 0x278;
      break;
    case 0x175:
      iVar1 = 0x279;
      break;
    case 0x176:
      iVar1 = 0x27a;
      break;
    case 0x177:
      iVar1 = 0x27b;
      break;
    case 0x178:
      iVar1 = 0x27c;
      break;
    case 0x179:
      iVar1 = 0x27d;
      break;
    case 0x17a:
      iVar1 = 0x26c;
      break;
    case 0x17b:
      iVar1 = 0x273;
      break;
    case 0x17c:
      iVar1 = 0x274;
      break;
    case 0x17d:
      iVar1 = 0x275;
      break;
    case 0x17e:
      iVar1 = 0x276;
      break;
    case 0x17f:
      iVar1 = 0x277;
      break;
    case 0x180:
      iVar1 = 0x26d;
      break;
    case 0x181:
      iVar1 = 0x26e;
      break;
    case 0x182:
      iVar1 = 0x26f;
      break;
    case 0x183:
      iVar1 = 0x270;
      break;
    case 0x184:
      iVar1 = 0x271;
      break;
    case 0x185:
      break;
    case 0x186:
    case 0x187:
    case 0x188:
    case 0x189:
    case 0x18a:
    case 0x18b:
    case 0x18c:
    case 0x18d:
    case 0x18e:
    case 399:
    case 400:
    case 0x191:
    case 0x192:
    case 0x193:
    case 0x194:
    case 0x195:
    case 0x196:
    case 0x197:
    case 0x198:
    case 0x199:
    case 0x19a:
    case 0x19b:
    case 0x19c:
    case 0x19d:
    case 0x19e:
    case 0x19f:
    case 0x1a0:
    case 0x1a1:
    case 0x1a2:
    case 0x1a3:
    case 0x1a4:
    case 0x1a5:
    case 0x1a6:
    case 0x1a7:
    case 0x1a8:
    case 0x1a9:
    case 0x1b1:
    case 0x1b3:
    case 0x1b4:
    case 0x1b5:
    case 0x1b6:
    case 0x1b7:
    case 0x1b8:
    case 0x1b9:
    case 0x1bb:
    case 0x1bc:
      goto switchD_000fa1ec_caseD_186;
    case 0x1aa:
      iVar1 = 0x285;
      break;
    case 0x1ab:
      iVar1 = 0x286;
      break;
    case 0x1ac:
      iVar1 = 0x287;
      break;
    case 0x1ad:
      iVar1 = 0x28a;
      break;
    case 0x1ae:
      iVar1 = 0x28b;
      break;
    case 0x1af:
      iVar1 = 0x28c;
      break;
    case 0x1b0:
      iVar1 = 0x24c;
      break;
    case 0x1b2:
      iVar1 = 0x24a;
      break;
    case 0x1ba:
      iVar1 = 0x24d;
      break;
    case 0x1bd:
      iVar1 = 0x27f;
      break;
    case 0x1be:
      iVar1 = 0x281;
      break;
    case 0x1bf:
      iVar1 = 0x282;
      break;
    default:
      if (param_1 != 0x139) {
        return -1;
      }
      iVar1 = 0x28f;
    }
  }
  else {
LAB_000fa166:
    switch(iVar1) {
    case 0:
    case 5:
      if (iVar2 == 1) {
        iVar1 = 0x2a8;
        switch(param_1) {
        case 0x172:
          iVar1 = 699;
          break;
        case 0x173:
          iVar1 = 0x2af;
          break;
        case 0x174:
          iVar1 = 0x2b5;
          break;
        case 0x175:
          iVar1 = 0x2b6;
          break;
        case 0x176:
          iVar1 = 0x2b7;
          break;
        case 0x177:
          iVar1 = 0x2b8;
          break;
        case 0x178:
          iVar1 = 0x2b9;
          break;
        case 0x179:
          iVar1 = 0x2ba;
          break;
        case 0x17a:
          iVar1 = 0x2a9;
          break;
        case 0x17b:
          iVar1 = 0x2b0;
          break;
        case 0x17c:
          iVar1 = 0x2b1;
          break;
        case 0x17d:
          iVar1 = 0x2b2;
          break;
        case 0x17e:
          iVar1 = 0x2b3;
          break;
        case 0x17f:
          iVar1 = 0x2b4;
          break;
        case 0x180:
          iVar1 = 0x2aa;
          break;
        case 0x181:
          iVar1 = 0x2ab;
          break;
        case 0x182:
          iVar1 = 0x2ac;
          break;
        case 0x183:
          iVar1 = 0x2ad;
          break;
        case 0x184:
          iVar1 = 0x2ae;
          break;
        case 0x185:
          break;
        default:
          iVar2 = -1;
          switch(param_1) {
          case 0x1aa:
            iVar1 = 0x2c1;
            break;
          case 0x1ab:
            iVar1 = 0x2c2;
            break;
          case 0x1ac:
            iVar1 = 0x2c3;
            break;
          case 0x1ad:
            iVar1 = 0x2c6;
            break;
          case 0x1ae:
            iVar1 = 0x2c7;
            break;
          case 0x1af:
            iVar1 = 0x2c8;
            break;
          case 0x1b0:
          case 0x1b1:
          case 0x1b2:
          case 0x1b3:
          case 0x1b4:
          case 0x1b5:
          case 0x1b6:
          case 0x1b7:
          case 0x1b8:
          case 0x1b9:
          case 0x1ba:
          case 0x1bb:
          case 0x1bc:
            goto switchD_000fa1ec_caseD_186;
          case 0x1bd:
            iVar1 = 700;
            break;
          case 0x1be:
            iVar1 = 0x2bd;
            break;
          case 0x1bf:
            iVar1 = 0x2be;
            break;
          default:
            if (param_1 != 0x139) {
              return -1;
            }
            iVar1 = 0x2cb;
          }
        }
      }
      else {
        if (0x13 < param_1 - 0x172U) {
          return -1;
        }
        iVar1 = *(int *)(&DAT_00258110 + (param_1 - 0x172U) * 4);
      }
      break;
    case 1:
      iVar1 = 0x2cc;
      switch(param_1) {
      case 0x172:
        iVar1 = 0x2df;
        break;
      case 0x173:
        iVar1 = 0x2d3;
        break;
      case 0x174:
        iVar1 = 0x2d9;
        break;
      case 0x175:
        iVar1 = 0x2da;
        break;
      case 0x176:
        iVar1 = 0x2db;
        break;
      case 0x177:
        iVar1 = 0x2dc;
        break;
      case 0x178:
        iVar1 = 0x2dd;
        break;
      case 0x179:
        iVar1 = 0x2de;
        break;
      case 0x17a:
        iVar1 = 0x2cd;
        break;
      case 0x17b:
        iVar1 = 0x2d4;
        break;
      case 0x17c:
        iVar1 = 0x2d5;
        break;
      case 0x17d:
        iVar1 = 0x2d6;
        break;
      case 0x17e:
        iVar1 = 0x2d7;
        break;
      case 0x17f:
        iVar1 = 0x2d8;
        break;
      case 0x180:
        iVar1 = 0x2ce;
        break;
      case 0x181:
        iVar1 = 0x2cf;
        break;
      case 0x182:
        iVar1 = 0x2d0;
        break;
      case 0x183:
        iVar1 = 0x2d1;
        break;
      case 0x184:
        iVar1 = 0x2d2;
        break;
      case 0x185:
        break;
      default:
        iVar2 = -1;
        switch(param_1) {
        case 0x1aa:
          iVar1 = 0x2e5;
          break;
        case 0x1ab:
          iVar1 = 0x2e6;
          break;
        case 0x1ac:
          iVar1 = 0x2e7;
          break;
        case 0x1ad:
          iVar1 = 0x2ea;
          break;
        case 0x1ae:
          iVar1 = 0x2eb;
          break;
        case 0x1af:
          iVar1 = 0x2ec;
          break;
        default:
          goto switchD_000fa1ec_caseD_186;
        case 0x1bd:
          iVar1 = 0x2e0;
          break;
        case 0x1be:
          iVar1 = 0x2e1;
          break;
        case 0x1bf:
          iVar1 = 0x2e2;
        }
      }
      break;
    case 2:
    case 3:
      goto code_r0x000fa1e8;
    case 4:
      iVar1 = 0x255;
      switch(param_1) {
      case 0x172:
        iVar1 = 0x267;
        break;
      case 0x173:
        iVar1 = 0x25b;
        break;
      case 0x174:
        iVar1 = 0x261;
        break;
      case 0x175:
        iVar1 = 0x262;
        break;
      case 0x176:
        iVar1 = 0x263;
        break;
      case 0x177:
        iVar1 = 0x264;
        break;
      case 0x178:
        iVar1 = 0x265;
        break;
      case 0x179:
        iVar1 = 0x266;
        break;
      case 0x17a:
        break;
      case 0x17b:
        iVar1 = 0x25c;
        break;
      case 0x17c:
        iVar1 = 0x25d;
        break;
      case 0x17d:
        iVar1 = 0x25e;
        break;
      case 0x17e:
        iVar1 = 0x25f;
        break;
      case 0x17f:
        iVar1 = 0x260;
        break;
      case 0x180:
        iVar1 = 0x256;
        break;
      case 0x181:
        iVar1 = 599;
        break;
      case 0x182:
        iVar1 = 600;
        break;
      case 0x183:
        iVar1 = 0x259;
        break;
      case 0x184:
        iVar1 = 0x25a;
        break;
      case 0x185:
        iVar1 = 0x26a;
        break;
      default:
        if (param_1 != 0x139) {
          return -1;
        }
        iVar1 = 0x268;
      }
      break;
    case 6:
      iVar1 = 0x2ef;
      switch(param_1) {
      case 0x172:
        iVar1 = 0x230;
        break;
      case 0x173:
        iVar1 = 0x2f6;
        break;
      case 0x174:
        iVar1 = 0x22a;
        break;
      case 0x175:
        iVar1 = 0x22b;
        break;
      case 0x176:
        iVar1 = 0x22c;
        break;
      case 0x177:
        iVar1 = 0x22d;
        break;
      case 0x178:
        iVar1 = 0x22e;
        break;
      case 0x179:
        iVar1 = 0x22f;
        break;
      case 0x17a:
        iVar1 = 0x2f0;
        break;
      case 0x17b:
        iVar1 = 0x225;
        break;
      case 0x17c:
        iVar1 = 0x226;
        break;
      case 0x17d:
        iVar1 = 0x227;
        break;
      case 0x17e:
        iVar1 = 0x228;
        break;
      case 0x17f:
        iVar1 = 0x229;
        break;
      case 0x180:
        iVar1 = 0x2f1;
        break;
      case 0x181:
        iVar1 = 0x2f2;
        break;
      case 0x182:
        iVar1 = 0x2f3;
        break;
      case 0x183:
        iVar1 = 0x2f4;
        break;
      case 0x184:
        iVar1 = 0x2f5;
        break;
      case 0x185:
        break;
      default:
        if (param_1 != 0x139) {
          return -1;
        }
        iVar1 = 0x231;
      }
      break;
    case 7:
      iVar1 = 0x233;
      switch(param_1) {
      case 0x172:
        iVar1 = 0x246;
        break;
      case 0x173:
        iVar1 = 0x23a;
        break;
      case 0x174:
        iVar1 = 0x240;
        break;
      case 0x175:
        iVar1 = 0x241;
        break;
      case 0x176:
        iVar1 = 0x242;
        break;
      case 0x177:
        iVar1 = 0x243;
        break;
      case 0x178:
        iVar1 = 0x244;
        break;
      case 0x179:
        iVar1 = 0x245;
        break;
      case 0x17a:
        iVar1 = 0x234;
        break;
      case 0x17b:
        iVar1 = 0x23b;
        break;
      case 0x17c:
        iVar1 = 0x23c;
        break;
      case 0x17d:
        iVar1 = 0x23d;
        break;
      case 0x17e:
        iVar1 = 0x23e;
        break;
      case 0x17f:
        iVar1 = 0x23f;
        break;
      case 0x180:
        iVar1 = 0x235;
        break;
      case 0x181:
        iVar1 = 0x236;
        break;
      case 0x182:
        iVar1 = 0x237;
        break;
      case 0x183:
        iVar1 = 0x238;
        break;
      case 0x184:
        iVar1 = 0x239;
        break;
      case 0x185:
        break;
      default:
        if (param_1 != 0x139) {
          return -1;
        }
        iVar1 = 0x247;
      }
      break;
    case 8:
      if (5 < param_1 - 0x1b3U) {
        return -1;
      }
      iVar1 = param_1 + 0x9b;
      break;
    default:
      return -1;
    }
  }
  iVar2 = iVar1;
switchD_000fa1ec_caseD_186:
  return iVar2;
}

// ===== Globals::getAgentMissionText  @0x000fa7d4  (7020 bytes)
/* Globals::getAgentMissionText(Agent*) */

void Globals::getAgentMissionText(Agent *param_1)

{
  byte bVar1;
  Galaxy *this;
  Status *pSVar2;
  GameText *pGVar3;
  AERandom *pAVar4;
  int iVar5;
  undefined4 uVar6;
  Ship *pSVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  Standing *pSVar11;
  Station *this_00;
  Array *pAVar12;
  float fVar13;
  Mission *pMVar14;
  String *pSVar15;
  Mission *pMVar16;
  String *pSVar17;
  int iVar18;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  Agent *in_r2;
  uint in_fpscr;
  uint uVar19;
  float fVar20;
  String aSStack_39c [8];
  String aSStack_394 [8];
  String aSStack_38c [8];
  String aSStack_384 [8];
  String aSStack_37c [8];
  String aSStack_374 [8];
  String aSStack_36c [8];
  String aSStack_364 [8];
  String aSStack_35c [8];
  String aSStack_354 [8];
  String aSStack_34c [8];
  String aSStack_344 [8];
  String aSStack_33c [8];
  String aSStack_334 [8];
  String aSStack_32c [8];
  String aSStack_324 [8];
  String aSStack_31c [8];
  String aSStack_314 [8];
  String aSStack_30c [8];
  String aSStack_304 [8];
  String aSStack_2fc [8];
  String aSStack_2f4 [8];
  String aSStack_2ec [8];
  String aSStack_2e4 [8];
  String aSStack_2dc [8];
  String aSStack_2d4 [8];
  String aSStack_2cc [8];
  String aSStack_2c4 [8];
  String aSStack_2bc [8];
  String aSStack_2b4 [8];
  String aSStack_2ac [8];
  String aSStack_2a4 [8];
  String aSStack_29c [8];
  String aSStack_294 [8];
  String aSStack_28c [8];
  String aSStack_284 [8];
  String aSStack_27c [8];
  String aSStack_274 [8];
  String aSStack_26c [8];
  String aSStack_264 [8];
  String aSStack_25c [8];
  String aSStack_254 [8];
  String aSStack_24c [8];
  String aSStack_244 [8];
  String aSStack_23c [8];
  String aSStack_234 [8];
  String aSStack_22c [8];
  String aSStack_224 [8];
  String aSStack_21c [8];
  String aSStack_214 [8];
  String aSStack_20c [8];
  String aSStack_204 [8];
  String aSStack_1fc [8];
  String aSStack_1f4 [8];
  String aSStack_1ec [8];
  String aSStack_1e4 [8];
  String aSStack_1dc [8];
  String aSStack_1d4 [8];
  AbyssEngine aAStack_1cc [8];
  String aSStack_1c4 [8];
  String aSStack_1bc [8];
  String aSStack_1b4 [8];
  undefined4 local_1ac [2];
  String aSStack_1a4 [8];
  String aSStack_19c [8];
  String aSStack_194 [8];
  undefined4 local_18c [2];
  String aSStack_184 [8];
  String aSStack_17c [8];
  String aSStack_174 [8];
  String aSStack_16c [8];
  String aSStack_164 [8];
  String aSStack_15c [8];
  String aSStack_154 [8];
  String aSStack_14c [8];
  String aSStack_144 [8];
  String aSStack_13c [8];
  String aSStack_134 [8];
  String aSStack_12c [8];
  String aSStack_124 [8];
  String aSStack_11c [8];
  String aSStack_114 [8];
  String aSStack_10c [8];
  String aSStack_104 [8];
  String aSStack_fc [8];
  String aSStack_f4 [8];
  String aSStack_ec [8];
  String aSStack_e4 [8];
  String aSStack_dc [8];
  String aSStack_d4 [8];
  String aSStack_cc [8];
  String aSStack_c4 [8];
  String aSStack_bc [8];
  String aSStack_b4 [8];
  String aSStack_ac [4];
  int local_a8;
  String aSStack_a4 [8];
  String aSStack_9c [8];
  String aSStack_94 [8];
  String aSStack_8c [8];
  String aSStack_84 [8];
  String aSStack_7c [8];
  String aSStack_74 [8];
  String aSStack_6c [8];
  String aSStack_64 [8];
  String aSStack_5c [8];
  undefined4 local_54 [2];
  String aSStack_4c [8];
  String aSStack_44 [8];
  AbyssEngine aAStack_3c [8];
  String aSStack_34 [8];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  if (in_r2 == (Agent *)0x0) {
    AbyssEngine::String::String((String *)param_1,"",false);
    goto LAB_000fc56c;
  }
  AbyssEngine::String::String(aSStack_34);
  iVar5 = Agent::isGenericAgent(in_r2);
  if (iVar5 == 1) {
    uVar6 = Agent::getOffer(in_r2);
    pGVar3 = gameText;
    switch(uVar6) {
    case 0:
      pMVar16 = (Mission *)Agent::getMission(in_r2);
      pGVar3 = gameText;
      if (pMVar16 != (Mission *)0x0) {
        iVar5 = Mission::getType(pMVar16);
        pSVar17 = (String *)GameText::getText(pGVar3,iVar5 + 0x312);
        AbyssEngine::String::operator+=(aSStack_34,pSVar17);
        iVar5 = Mission::getType(pMVar16);
        if ((iVar5 == 5) || (iVar5 = Mission::getType(pMVar16), iVar5 == 3)) {
          AbyssEngine::String::String((String *)local_54," ",false);
          pSVar17 = (String *)GameText::getText(gameText,0x322);
          AbyssEngine::operator+(aAStack_3c,(String *)local_54,pSVar17);
          AbyssEngine::String::operator+=(aSStack_34,aAStack_3c);
          AbyssEngine::String::~String((String *)aAStack_3c);
          AbyssEngine::String::~String((String *)local_54);
        }
        iVar5 = Mission::getType(pMVar16);
        pSVar2 = status;
        if (iVar5 == 0xf) {
          AbyssEngine::String::String(aSStack_fc,aSStack_34,false);
          pGVar3 = gameText;
          iVar5 = Mission::getProductionGoodIndex(pMVar16);
          pSVar17 = (String *)GameText::getText(pGVar3,iVar5 + 0x4fa);
          AbyssEngine::String::String(aSStack_104,pSVar17,false);
          uVar6 = AbyssEngine::String::String(aSStack_10c,"#P",false);
          Status::replaceHash(aAStack_3c,pSVar2,aSStack_fc,aSStack_104,uVar6);
          AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
          AbyssEngine::String::~String((String *)aAStack_3c);
          AbyssEngine::String::~String(aSStack_10c);
          AbyssEngine::String::~String(aSStack_104);
          pSVar15 = aSStack_fc;
        }
        else {
          AbyssEngine::String::String(aSStack_114,aSStack_34,false);
          pGVar3 = gameText;
          iVar5 = Mission::getProductionGoodIndex(pMVar16);
          pSVar17 = (String *)GameText::getText(pGVar3,iVar5 + 0x32d);
          AbyssEngine::String::String(aSStack_11c,pSVar17,false);
          uVar6 = AbyssEngine::String::String(aSStack_124,"#P",false);
          Status::replaceHash(aAStack_3c,pSVar2,aSStack_114,aSStack_11c,uVar6);
          AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
          AbyssEngine::String::~String((String *)aAStack_3c);
          AbyssEngine::String::~String(aSStack_124);
          AbyssEngine::String::~String(aSStack_11c);
          pSVar15 = aSStack_114;
        }
        AbyssEngine::String::~String(pSVar15);
        pSVar2 = status;
        AbyssEngine::String::String(aSStack_12c,aSStack_34,false);
        uVar6 = Mission::getProductionGoodAmount(pMVar16);
        local_54[0] = 0;
        AbyssEngine::String::Set(CONCAT44(uVar6,local_54));
        AbyssEngine::String::String(aSStack_134,(String *)local_54,false);
        uVar6 = AbyssEngine::String::String(aSStack_13c,"#Q",false);
        Status::replaceHash(aAStack_3c,pSVar2,aSStack_12c,aSStack_134,uVar6);
        AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
        AbyssEngine::String::~String((String *)aAStack_3c);
        AbyssEngine::String::~String(aSStack_13c);
        AbyssEngine::String::~String(aSStack_134);
        AbyssEngine::String::~String((String *)local_54);
        AbyssEngine::String::~String(aSStack_12c);
        iVar5 = Mission::getType(pMVar16);
        pSVar2 = status;
        if (iVar5 == 0xe) {
          AbyssEngine::String::String(aSStack_144,aSStack_34,false);
          Mission::getTargetSystemName();
          AbyssEngine::String::String(aSStack_14c,(String *)local_54,false);
          uVar6 = AbyssEngine::String::String(aSStack_154,"#S",false);
          Status::replaceHash(aAStack_3c,pSVar2,aSStack_144,aSStack_14c,uVar6);
          AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
          AbyssEngine::String::~String((String *)aAStack_3c);
          AbyssEngine::String::~String(aSStack_154);
          AbyssEngine::String::~String(aSStack_14c);
          AbyssEngine::String::~String((String *)local_54);
          pSVar15 = aSStack_144;
        }
        else {
          AbyssEngine::String::String(aSStack_15c,aSStack_34,false);
          Mission::getTargetStationName();
          AbyssEngine::String::String(aSStack_164,(String *)local_54,false);
          uVar6 = AbyssEngine::String::String(aSStack_16c,"#S",false);
          Status::replaceHash(aAStack_3c,pSVar2,aSStack_15c,aSStack_164,uVar6);
          AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
          AbyssEngine::String::~String((String *)aAStack_3c);
          AbyssEngine::String::~String(aSStack_16c);
          AbyssEngine::String::~String(aSStack_164);
          AbyssEngine::String::~String((String *)local_54);
          pSVar15 = aSStack_15c;
        }
        AbyssEngine::String::~String(pSVar15);
        pSVar2 = status;
        AbyssEngine::String::String(aSStack_174,aSStack_34,false);
        Mission::getTargetName();
        AbyssEngine::String::String(aSStack_17c,(String *)local_54,false);
        uVar6 = AbyssEngine::String::String(aSStack_184,"#N",false);
        Status::replaceHash(aAStack_3c,pSVar2,aSStack_174,aSStack_17c,uVar6);
        AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
        AbyssEngine::String::~String((String *)aAStack_3c);
        AbyssEngine::String::~String(aSStack_184);
        AbyssEngine::String::~String(aSStack_17c);
        AbyssEngine::String::~String((String *)local_54);
        AbyssEngine::String::~String(aSStack_174);
        iVar5 = *(int *)(in_r2 + 0x20);
        if (iVar5 == -1) {
          iVar5 = AbyssEngine::AERandom::nextInt(rnd,3);
          iVar5 = iVar5 + 0x2fc;
        }
        *(int *)(in_r2 + 0x20) = iVar5;
        AbyssEngine::String::String((String *)local_54,"\n",false);
        pSVar17 = (String *)GameText::getText(gameText,iVar5);
        AbyssEngine::operator+(aAStack_3c,(String *)local_54,pSVar17);
        AbyssEngine::String::operator+=(aSStack_34,aAStack_3c);
        AbyssEngine::String::~String((String *)aAStack_3c);
        AbyssEngine::String::~String((String *)local_54);
        pSVar11 = (Standing *)Status::getStanding(status);
        iVar5 = Agent::getRace(in_r2);
        fVar13 = (float)Standing::getMissionBonus(pSVar11,iVar5);
        uVar10 = in_fpscr & 0xfffffff | (uint)(fVar13 < 0.0) << 0x1f | (uint)(fVar13 == 0.0) << 0x1e
        ;
        uVar19 = uVar10 | (uint)NAN(fVar13) << 0x1c;
        bVar1 = (byte)(uVar10 >> 0x18);
        if ((bool)(bVar1 >> 6 & 1) || bVar1 >> 7 != ((byte)(uVar19 >> 0x1c) & 1)) {
          AbyssEngine::String::String((String *)aAStack_3c,"",false);
        }
        else {
          AbyssEngine::String::String((String *)local_18c," ",false);
          pSVar2 = status;
          pSVar17 = (String *)GameText::getText(gameText,0x2ff);
          AbyssEngine::String::String(aSStack_19c,pSVar17,false);
          local_1ac[0] = 0;
          AbyssEngine::String::Set(CONCAT44(extraout_r1_00,local_1ac));
          AbyssEngine::String::String(aSStack_1a4,(String *)local_1ac,false);
          uVar6 = AbyssEngine::String::String(aSStack_1b4,"#P",false);
          Status::replaceHash(aSStack_194,pSVar2,aSStack_19c,aSStack_1a4,uVar6);
          AbyssEngine::operator+((AbyssEngine *)local_54,(String *)local_18c,aSStack_194);
          AbyssEngine::String::String(aSStack_1bc," ",false);
          AbyssEngine::operator+(aAStack_3c,(String *)local_54,aSStack_1bc);
          AbyssEngine::String::~String(aSStack_1bc);
          AbyssEngine::String::~String((String *)local_54);
          AbyssEngine::String::~String(aSStack_194);
          AbyssEngine::String::~String(aSStack_1b4);
          AbyssEngine::String::~String(aSStack_1a4);
          AbyssEngine::String::~String((String *)local_1ac);
          AbyssEngine::String::~String(aSStack_19c);
          AbyssEngine::String::~String((String *)local_18c);
        }
        pMVar14 = (Mission *)Agent::getMission(in_r2);
        uVar6 = Mission::getReward(pMVar14);
        fVar20 = (float)VectorSignedToFloat(uVar6,(byte)(uVar19 >> 0x16) & 3);
        iVar8 = (int)(fVar13 * fVar20);
        pMVar14 = (Mission *)Agent::getMission(in_r2);
        iVar5 = iVar8 % 0x32 + iVar8;
        if (iVar5 % 0x32 != 0) {
          iVar5 = iVar8 - iVar8 % 0x32;
        }
        Mission::setBonus(pMVar14,iVar5);
        pSVar2 = status;
        AbyssEngine::String::String(aSStack_1c4,aSStack_34,false);
        Mission::getReward(pMVar16);
        Mission::getBonus(pMVar16);
        Layout::formatCredits((int)aSStack_194);
        AbyssEngine::String::String((String *)local_18c,aSStack_194,false);
        AbyssEngine::operator+(aAStack_1cc,(String *)local_18c,aAStack_3c);
        uVar6 = AbyssEngine::String::String(aSStack_1d4,"#C",false);
        Status::replaceHash(local_54,pSVar2,aSStack_1c4,aAStack_1cc,uVar6);
        AbyssEngine::String::operator=(aSStack_34,(String *)local_54);
        AbyssEngine::String::~String((String *)local_54);
        AbyssEngine::String::~String(aSStack_1d4);
        AbyssEngine::String::~String((String *)aAStack_1cc);
        AbyssEngine::String::~String((String *)local_18c);
        AbyssEngine::String::~String(aSStack_194);
        AbyssEngine::String::~String(aSStack_1c4);
        iVar5 = Mission::getStatusValue(pMVar16);
        if (iVar5 == -1) {
          pSVar17 = (String *)GameText::getText(gameText,0x323);
          AbyssEngine::String::operator=(aSStack_34,pSVar17);
          pSVar2 = status;
          AbyssEngine::String::String(aSStack_1dc,aSStack_34,false);
          Mission::getTargetStationName();
          uVar6 = AbyssEngine::String::String(aSStack_1ec,"#S",false);
          Status::replaceHash(local_54,pSVar2,aSStack_1dc,aSStack_1e4,uVar6);
          AbyssEngine::String::operator=(aSStack_34,(String *)local_54);
          AbyssEngine::String::~String((String *)local_54);
          AbyssEngine::String::~String(aSStack_1ec);
          AbyssEngine::String::~String(aSStack_1e4);
          AbyssEngine::String::~String(aSStack_1dc);
        }
        pSVar15 = (String *)aAStack_3c;
        goto LAB_000fbf5e;
      }
      *(undefined4 *)(in_r2 + 0x20) = 0x334;
      pSVar17 = (String *)GameText::getText(gameText,0x334);
      AbyssEngine::String::operator=(aSStack_34,pSVar17);
      break;
    case 1:
      iVar5 = *(int *)(in_r2 + 0x20);
      if (iVar5 == -1) {
        iVar5 = 0x338;
      }
      *(int *)(in_r2 + 0x20) = iVar5;
      pSVar17 = (String *)GameText::getText(gameText,iVar5);
      AbyssEngine::String::operator=(aSStack_34,pSVar17);
      pAVar4 = rnd;
      Agent::getName();
      iVar5 = Agent::getRace(in_r2);
      this_00 = (Station *)Status::getStation(status);
      Station::getIndex(this_00);
      AbyssEngine::AERandom::setSeed(CONCAT44(iVar5 * local_a8,pAVar4));
      AbyssEngine::String::~String(aSStack_ac);
      AbyssEngine::String::String((String *)aAStack_3c,"#S",false);
      iVar5 = AbyssEngine::String::IndexOf(aSStack_34,aAStack_3c);
      AbyssEngine::String::~String((String *)aAStack_3c);
      pSVar2 = status;
      if (-1 < iVar5) {
        AbyssEngine::String::String(aSStack_b4,aSStack_34,false);
        getRandomPlanetName();
        AbyssEngine::String::String(aSStack_bc,(String *)local_54,false);
        uVar6 = AbyssEngine::String::String(aSStack_c4,"#S",false);
        Status::replaceHash(aAStack_3c,pSVar2,aSStack_b4,aSStack_bc,uVar6);
        AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
        AbyssEngine::String::~String((String *)aAStack_3c);
        AbyssEngine::String::~String(aSStack_c4);
        AbyssEngine::String::~String(aSStack_bc);
        AbyssEngine::String::~String((String *)local_54);
        AbyssEngine::String::~String(aSStack_b4);
      }
      pSVar2 = status;
      AbyssEngine::String::String(aSStack_cc,aSStack_34,false);
      Agent::getName();
      AbyssEngine::String::String(aSStack_d4,(String *)local_54,false);
      uVar6 = AbyssEngine::String::String(aSStack_dc,"#N",false);
      Status::replaceHash(aAStack_3c,pSVar2,aSStack_cc,aSStack_d4,uVar6);
      AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
      AbyssEngine::String::~String((String *)aAStack_3c);
      AbyssEngine::String::~String(aSStack_dc);
      AbyssEngine::String::~String(aSStack_d4);
      AbyssEngine::String::~String((String *)local_54);
      AbyssEngine::String::~String(aSStack_cc);
      pSVar2 = status;
      AbyssEngine::String::String(aSStack_e4,aSStack_34,false);
      pGVar3 = gameText;
      iVar5 = AbyssEngine::AERandom::nextInt(rnd,10);
      pSVar17 = (String *)GameText::getText(pGVar3,iVar5 + 0x594);
      AbyssEngine::String::String(aSStack_ec,pSVar17,false);
      uVar6 = AbyssEngine::String::String(aSStack_f4,"#ORE",false);
      Status::replaceHash(aAStack_3c,pSVar2,aSStack_e4,aSStack_ec,uVar6);
      AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
      AbyssEngine::String::~String((String *)aAStack_3c);
      AbyssEngine::String::~String(aSStack_f4);
      AbyssEngine::String::~String(aSStack_ec);
      AbyssEngine::String::~String(aSStack_e4);
      AbyssEngine::AERandom::reset(rnd);
      break;
    case 2:
      iVar5 = *(int *)(in_r2 + 0x20);
      if (iVar5 == -1) {
        iVar5 = AbyssEngine::AERandom::nextInt(rnd,5);
        iVar5 = iVar5 + 0x300;
      }
      *(int *)(in_r2 + 0x20) = iVar5;
      pSVar17 = (String *)GameText::getText(gameText,iVar5);
      AbyssEngine::String::operator+=(aSStack_34,pSVar17);
      iVar5 = *(int *)(in_r2 + 0x24);
      if (iVar5 == -1) {
        iVar5 = AbyssEngine::AERandom::nextInt(rnd,2);
        iVar5 = iVar5 + 0x305;
      }
      *(int *)(in_r2 + 0x24) = iVar5;
      AbyssEngine::String::String((String *)local_54,"\n",false);
      pSVar17 = (String *)GameText::getText(gameText,iVar5);
      AbyssEngine::operator+(aAStack_3c,(String *)local_54,pSVar17);
      AbyssEngine::String::operator+=(aSStack_34,aAStack_3c);
      AbyssEngine::String::~String((String *)aAStack_3c);
      AbyssEngine::String::~String((String *)local_54);
      pSVar2 = status;
      AbyssEngine::String::String(aSStack_1f4,aSStack_34,false);
      uVar6 = Agent::getSellItemQuantity(in_r2);
      local_54[0] = 0;
      AbyssEngine::String::Set(CONCAT44(uVar6,local_54));
      AbyssEngine::String::String(aSStack_1fc,(String *)local_54,false);
      uVar6 = AbyssEngine::String::String(aSStack_204,"#Q",false);
      Status::replaceHash(aAStack_3c,pSVar2,aSStack_1f4,aSStack_1fc,uVar6);
      AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
      AbyssEngine::String::~String((String *)aAStack_3c);
      AbyssEngine::String::~String(aSStack_204);
      AbyssEngine::String::~String(aSStack_1fc);
      AbyssEngine::String::~String((String *)local_54);
      AbyssEngine::String::~String(aSStack_1f4);
      pSVar2 = status;
      AbyssEngine::String::String(aSStack_20c,aSStack_34,false);
      pGVar3 = gameText;
      iVar5 = Agent::getSellItemIndex(in_r2);
      pSVar17 = (String *)GameText::getText(pGVar3,iVar5 + 0x4fa);
      AbyssEngine::String::String(aSStack_214,pSVar17,false);
      uVar6 = AbyssEngine::String::String(aSStack_21c,"#P",false);
      Status::replaceHash(aAStack_3c,pSVar2,aSStack_20c,aSStack_214,uVar6);
      AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
      AbyssEngine::String::~String((String *)aAStack_3c);
      AbyssEngine::String::~String(aSStack_21c);
      AbyssEngine::String::~String(aSStack_214);
      AbyssEngine::String::~String(aSStack_20c);
      pSVar2 = status;
      AbyssEngine::String::String(aSStack_224,aSStack_34,false);
      Agent::getSellItemPrice(in_r2);
      Layout::formatCredits((int)local_54);
      AbyssEngine::String::String(aSStack_22c,(String *)local_54,false);
      uVar6 = AbyssEngine::String::String(aSStack_234,"#C",false);
      Status::replaceHash(aAStack_3c,pSVar2,aSStack_224,aSStack_22c,uVar6);
      AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
      AbyssEngine::String::~String((String *)aAStack_3c);
      AbyssEngine::String::~String(aSStack_234);
      AbyssEngine::String::~String(aSStack_22c);
      AbyssEngine::String::~String((String *)local_54);
      AbyssEngine::String::~String(aSStack_224);
      iVar5 = Agent::getSellItemQuantity(in_r2);
      if (1 < iVar5) {
        AbyssEngine::String::String((String *)local_54," ",false);
        pSVar17 = (String *)GameText::getText(gameText,0x307);
        AbyssEngine::operator+(aAStack_3c,(String *)local_54,pSVar17);
        AbyssEngine::String::operator+=(aSStack_34,aAStack_3c);
        AbyssEngine::String::~String((String *)aAStack_3c);
        AbyssEngine::String::~String((String *)local_54);
        pSVar2 = status;
        AbyssEngine::String::String(aSStack_23c,aSStack_34,false);
        uVar6 = Agent::getSellItemPrice(in_r2);
        uVar9 = Agent::getSellItemQuantity(in_r2);
        __aeabi_idiv(uVar6,uVar9);
        Layout::formatCredits((int)local_54);
        AbyssEngine::String::String(aSStack_244,(String *)local_54,false);
        uVar6 = AbyssEngine::String::String(aSStack_24c,"#C",false);
        Status::replaceHash(aAStack_3c,pSVar2,aSStack_23c,aSStack_244,uVar6);
        AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
        AbyssEngine::String::~String((String *)aAStack_3c);
        AbyssEngine::String::~String(aSStack_24c);
        AbyssEngine::String::~String(aSStack_244);
        AbyssEngine::String::~String((String *)local_54);
        pSVar15 = aSStack_23c;
        goto LAB_000fbf5e;
      }
      break;
    case 5:
      iVar5 = Agent::getMission(in_r2);
      if (iVar5 == 0) {
        pAVar12 = (Array *)Galaxy::getSystems(galaxy);
        pMVar16 = (Mission *)Generator::createMission(generator,in_r2,pAVar12);
        Agent::setMission(in_r2,pMVar16);
      }
      iVar5 = *(int *)(in_r2 + 0x20);
      if (iVar5 == -1) {
        iVar5 = AbyssEngine::AERandom::nextInt(rnd,2);
        iVar5 = iVar5 + 0x309;
      }
      *(int *)(in_r2 + 0x20) = iVar5;
      pSVar17 = (String *)GameText::getText(gameText,iVar5);
      AbyssEngine::String::operator+=(aSStack_34,pSVar17);
      pSVar2 = status;
      AbyssEngine::String::String(aSStack_64,aSStack_34,false);
      pMVar16 = (Mission *)Agent::getMission(in_r2);
      uVar6 = Mission::getProductionGoodAmount(pMVar16);
      local_54[0] = 0;
      AbyssEngine::String::Set(CONCAT44(uVar6,local_54));
      AbyssEngine::String::String(aSStack_6c,(String *)local_54,false);
      uVar6 = AbyssEngine::String::String(aSStack_74,"#Q",false);
      Status::replaceHash(aAStack_3c,pSVar2,aSStack_64,aSStack_6c,uVar6);
      AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
      AbyssEngine::String::~String((String *)aAStack_3c);
      AbyssEngine::String::~String(aSStack_74);
      AbyssEngine::String::~String(aSStack_6c);
      AbyssEngine::String::~String((String *)local_54);
      AbyssEngine::String::~String(aSStack_64);
      pSVar2 = status;
      AbyssEngine::String::String(aSStack_7c,aSStack_34,false);
      pGVar3 = gameText;
      pMVar16 = (Mission *)Agent::getMission(in_r2);
      iVar5 = Mission::getProductionGoodIndex(pMVar16);
      pSVar17 = (String *)GameText::getText(pGVar3,iVar5 + 0x4fa);
      AbyssEngine::String::String(aSStack_84,pSVar17,false);
      uVar6 = AbyssEngine::String::String(aSStack_8c,"#P",false);
      Status::replaceHash(aAStack_3c,pSVar2,aSStack_7c,aSStack_84,uVar6);
      AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
      AbyssEngine::String::~String((String *)aAStack_3c);
      AbyssEngine::String::~String(aSStack_8c);
      AbyssEngine::String::~String(aSStack_84);
      AbyssEngine::String::~String(aSStack_7c);
      pSVar2 = status;
      AbyssEngine::String::String(aSStack_94,aSStack_34,false);
      pMVar16 = (Mission *)Agent::getMission(in_r2);
      Mission::getReward(pMVar16);
      Layout::formatCredits((int)local_54);
      AbyssEngine::String::String(aSStack_9c,(String *)local_54,false);
      uVar6 = AbyssEngine::String::String(aSStack_a4,"#C",false);
      Status::replaceHash(aAStack_3c,pSVar2,aSStack_94,aSStack_9c,uVar6);
      AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
      AbyssEngine::String::~String((String *)aAStack_3c);
      AbyssEngine::String::~String(aSStack_a4);
      AbyssEngine::String::~String(aSStack_9c);
      AbyssEngine::String::~String((String *)local_54);
      pSVar15 = aSStack_94;
LAB_000fbf5e:
      AbyssEngine::String::~String(pSVar15);
      break;
    case 6:
      iVar5 = Achievements::gotAllMedals(achievements);
      iVar8 = Agent::getWingmanFriendsCount(in_r2);
      iVar18 = 0x30b;
      if (iVar5 != 0) {
        iVar18 = 0x30e;
      }
      pSVar17 = (String *)GameText::getText(pGVar3,iVar18 + iVar8);
      AbyssEngine::String::operator+=(aSStack_34,pSVar17);
      pSVar2 = status;
      AbyssEngine::String::String(aSStack_254,aSStack_34,false);
      Agent::getCosts(in_r2);
      Layout::formatCredits((int)local_54);
      AbyssEngine::String::String(aSStack_25c,(String *)local_54,false);
      uVar6 = AbyssEngine::String::String(aSStack_264,"#C",false);
      Status::replaceHash(aAStack_3c,pSVar2,aSStack_254,aSStack_25c,uVar6);
      AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
      AbyssEngine::String::~String((String *)aAStack_3c);
      AbyssEngine::String::~String(aSStack_264);
      AbyssEngine::String::~String(aSStack_25c);
      AbyssEngine::String::~String((String *)local_54);
      AbyssEngine::String::~String(aSStack_254);
      iVar5 = Agent::getWingmanFriendsCount(in_r2);
      pSVar2 = status;
      if (0 < iVar5) {
        AbyssEngine::String::String(aSStack_26c,aSStack_34,false);
        Agent::getWingmanName((int)local_54);
        AbyssEngine::String::String(aSStack_274,(String *)local_54,false);
        uVar6 = AbyssEngine::String::String(aSStack_27c,"#W",false);
        Status::replaceHash(aAStack_3c,pSVar2,aSStack_26c,aSStack_274,uVar6);
        AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
        AbyssEngine::String::~String((String *)aAStack_3c);
        AbyssEngine::String::~String(aSStack_27c);
        AbyssEngine::String::~String(aSStack_274);
        AbyssEngine::String::~String((String *)local_54);
        pSVar15 = aSStack_26c;
        goto LAB_000fbf5e;
      }
      break;
    case 7:
      uVar10 = Agent::getRace(in_r2);
      pSVar11 = (Standing *)Status::getStanding(status);
      iVar5 = Standing::getStanding(pSVar11,(uint)((uVar10 | 1) == 3));
      pSVar11 = (Standing *)Status::getStanding(status);
      iVar8 = Standing::isEnemy(pSVar11,uVar10);
      if (iVar8 == 1) {
        if (iVar5 < 0) {
          iVar5 = -iVar5;
        }
        iVar8 = 0x370;
        VectorSignedToFloat(iVar5,(byte)(in_fpscr >> 0x16) & 3);
        iVar5 = 0x372;
        if (uVar10 == 2) {
          iVar8 = 0x36e;
        }
        if (uVar10 == 0) {
          iVar5 = 0x371;
        }
        if ((uVar10 | 1) == 3) {
          iVar5 = iVar8;
        }
        pSVar17 = (String *)GameText::getText(gameText,iVar5);
        AbyssEngine::String::operator=(aSStack_34,pSVar17);
        pSVar2 = status;
        AbyssEngine::String::String(aSStack_44,aSStack_34,false);
        Layout::formatCredits((int)local_54);
        AbyssEngine::String::String(aSStack_4c,(String *)local_54,false);
        uVar6 = AbyssEngine::String::String(aSStack_5c,"#C",false);
        Status::replaceHash(aAStack_3c,pSVar2,aSStack_44,aSStack_4c,uVar6);
        AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
        AbyssEngine::String::~String((String *)aAStack_3c);
        AbyssEngine::String::~String(aSStack_5c);
        AbyssEngine::String::~String(aSStack_4c);
        AbyssEngine::String::~String((String *)local_54);
        pSVar15 = aSStack_44;
        goto LAB_000fbf5e;
      }
      pSVar17 = (String *)GameText::getText(gameText,0x373);
      AbyssEngine::String::operator=(aSStack_34,pSVar17);
      AbyssEngine::String::String((String *)param_1,aSStack_34,false);
      goto LAB_000fc560;
    }
    iVar5 = Agent::getMission(in_r2);
    if (iVar5 != 0) {
      pMVar16 = (Mission *)Agent::getMission(in_r2);
      iVar5 = Mission::getType(pMVar16);
      if (iVar5 == 0xc) {
        pSVar17 = (String *)GameText::getText(gameText,0x31e);
        AbyssEngine::String::operator=(aSStack_34,pSVar17);
        pSVar2 = status;
        AbyssEngine::String::String(aSStack_284,aSStack_34,false);
        pMVar16 = (Mission *)Agent::getMission(in_r2);
        Mission::getReward(pMVar16);
        pMVar16 = (Mission *)Agent::getMission(in_r2);
        Mission::getBonus(pMVar16);
        Layout::formatCredits((int)local_54);
        AbyssEngine::String::String(aSStack_28c,(String *)local_54,false);
        uVar6 = AbyssEngine::String::String(aSStack_294,"#C",false);
        Status::replaceHash(aAStack_3c,pSVar2,aSStack_284,aSStack_28c,uVar6);
        AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
        AbyssEngine::String::~String((String *)aAStack_3c);
        AbyssEngine::String::~String(aSStack_294);
        AbyssEngine::String::~String(aSStack_28c);
        AbyssEngine::String::~String((String *)local_54);
        pSVar15 = aSStack_284;
        goto LAB_000fc552;
      }
    }
  }
  else {
    AbyssEngine::String::String((String *)local_54);
    iVar5 = Agent::getEvent(in_r2);
    if (iVar5 < 1) {
      iVar5 = Agent::hasAcceptedOffer(in_r2);
      if (iVar5 == 1) {
        pSVar17 = (String *)GameText::getText(gameText,0x35a);
        AbyssEngine::String::operator=(aSStack_34,pSVar17);
      }
      else {
        *(int *)(status + 0xd0) = *(int *)(status + 0xd0) + 1;
        iVar5 = Agent::getOffer(in_r2);
        if (iVar5 == 8) {
          pSVar7 = (Ship *)Status::getShip(status);
          iVar5 = Ship::getPrice(pSVar7);
          iVar8 = Agent::getModPricePercentage(in_r2);
          Agent::setSellItemPrice(in_r2,(iVar5 * iVar8) / 100);
          pSVar7 = (Ship *)Status::getShip(status);
          iVar5 = Agent::getSellModIndex(in_r2);
          iVar5 = Ship::hasModInstalled(pSVar7,iVar5);
          if (iVar5 == 1) {
            pSVar17 = (String *)GameText::getText(gameText,0x35a);
            AbyssEngine::String::operator=(aSStack_34,pSVar17);
            *(int *)(status + 0xd0) = *(int *)(status + 0xd0) + -1;
            AbyssEngine::String::String((String *)param_1,aSStack_34,false);
            AbyssEngine::String::~String((String *)local_54);
            goto LAB_000fc560;
          }
          iVar5 = *(int *)(in_r2 + 0x20);
          if (iVar5 == -1) {
            iVar5 = AbyssEngine::AERandom::nextInt(rnd,2);
            iVar5 = iVar5 + 0x36a;
          }
          *(int *)(in_r2 + 0x20) = iVar5;
          pSVar17 = (String *)GameText::getText(gameText,iVar5);
          AbyssEngine::String::operator=(aSStack_34,pSVar17);
          AbyssEngine::String::String((String *)local_18c," ",false);
          pGVar3 = gameText;
          iVar5 = Agent::getIndex(in_r2);
          pSVar17 = (String *)GameText::getText(pGVar3,iVar5 + 0x376);
          AbyssEngine::operator+(aAStack_3c,(String *)local_18c,pSVar17);
          AbyssEngine::String::operator+=(aSStack_34,aAStack_3c);
          AbyssEngine::String::~String((String *)aAStack_3c);
          AbyssEngine::String::~String((String *)local_18c);
          AbyssEngine::String::String((String *)local_18c," ",false);
          pSVar17 = (String *)GameText::getText(gameText,0x36f);
          AbyssEngine::operator+(aAStack_3c,(String *)local_18c,pSVar17);
          AbyssEngine::String::operator+=(aSStack_34,aAStack_3c);
          AbyssEngine::String::~String((String *)aAStack_3c);
          AbyssEngine::String::~String((String *)local_18c);
          pSVar2 = status;
          AbyssEngine::String::String(aSStack_29c,(String *)local_54,false);
          if (options[0x38] == '\0') {
            uVar6 = Agent::getSellItemPrice(in_r2);
            VectorSignedToFloat(uVar6,(byte)(in_fpscr >> 0x16) & 3);
          }
          else {
            uVar6 = Agent::getSellItemPrice(in_r2);
            VectorSignedToFloat(uVar6,(byte)(in_fpscr >> 0x16) & 3);
          }
          Layout::formatCredits((int)local_18c);
          AbyssEngine::String::String(aSStack_2a4,(String *)local_18c,false);
          uVar6 = AbyssEngine::String::String(aSStack_2ac,"#C",false);
          Status::replaceHash(aAStack_3c,pSVar2,aSStack_29c,aSStack_2a4,uVar6);
          AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
          AbyssEngine::String::~String((String *)aAStack_3c);
          AbyssEngine::String::~String(aSStack_2ac);
          AbyssEngine::String::~String(aSStack_2a4);
          AbyssEngine::String::~String((String *)local_18c);
          pSVar15 = aSStack_29c;
        }
        else {
          iVar5 = Agent::getOffer(in_r2);
          if (iVar5 == 9) {
            iVar5 = *(int *)(in_r2 + 0x20);
            if (iVar5 == -1) {
              iVar5 = AbyssEngine::AERandom::nextInt(rnd,2);
              iVar5 = iVar5 + 0x36a;
            }
            *(int *)(in_r2 + 0x20) = iVar5;
            pSVar17 = (String *)GameText::getText(gameText,iVar5);
            AbyssEngine::String::operator=(aSStack_34,pSVar17);
            AbyssEngine::String::String((String *)local_18c," ",false);
            pGVar3 = gameText;
            iVar5 = Agent::getIndex(in_r2);
            pSVar17 = (String *)GameText::getText(pGVar3,iVar5 + 0x376);
            AbyssEngine::operator+(aAStack_3c,(String *)local_18c,pSVar17);
            AbyssEngine::String::operator+=(aSStack_34,aAStack_3c);
            AbyssEngine::String::~String((String *)aAStack_3c);
            AbyssEngine::String::~String((String *)local_18c);
            iVar5 = *(int *)(in_r2 + 0x24);
            if (iVar5 == -1) {
              iVar5 = AbyssEngine::AERandom::nextInt(rnd,2);
              iVar5 = iVar5 + 0x305;
            }
            *(int *)(in_r2 + 0x24) = iVar5;
            AbyssEngine::String::String((String *)local_18c,"\n",false);
            pSVar17 = (String *)GameText::getText(gameText,iVar5);
            AbyssEngine::operator+(aAStack_3c,(String *)local_18c,pSVar17);
            AbyssEngine::String::operator+=(aSStack_34,aAStack_3c);
            AbyssEngine::String::~String((String *)aAStack_3c);
            AbyssEngine::String::~String((String *)local_18c);
            pSVar2 = status;
            AbyssEngine::String::String(aSStack_2b4,aSStack_34,false);
            uVar6 = Agent::getSellItemQuantity(in_r2);
            local_18c[0] = 0;
            AbyssEngine::String::Set(CONCAT44(uVar6,local_18c));
            AbyssEngine::String::String(aSStack_2bc,(String *)local_18c,false);
            uVar6 = AbyssEngine::String::String(aSStack_2c4,"#Q",false);
            Status::replaceHash(aAStack_3c,pSVar2,aSStack_2b4,aSStack_2bc,uVar6);
            AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
            AbyssEngine::String::~String((String *)aAStack_3c);
            AbyssEngine::String::~String(aSStack_2c4);
            AbyssEngine::String::~String(aSStack_2bc);
            AbyssEngine::String::~String((String *)local_18c);
            AbyssEngine::String::~String(aSStack_2b4);
            pSVar2 = status;
            AbyssEngine::String::String(aSStack_2cc,aSStack_34,false);
            pGVar3 = gameText;
            iVar5 = Agent::getSellItemIndex(in_r2);
            pSVar17 = (String *)GameText::getText(pGVar3,iVar5 + 0x4fa);
            AbyssEngine::String::String(aSStack_2d4,pSVar17,false);
            uVar6 = AbyssEngine::String::String(aSStack_2dc,"#P",false);
            Status::replaceHash(aAStack_3c,pSVar2,aSStack_2cc,aSStack_2d4,uVar6);
            AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
            AbyssEngine::String::~String((String *)aAStack_3c);
            AbyssEngine::String::~String(aSStack_2dc);
            AbyssEngine::String::~String(aSStack_2d4);
            AbyssEngine::String::~String(aSStack_2cc);
            pSVar2 = status;
            AbyssEngine::String::String(aSStack_2e4,aSStack_34,false);
            if (options[0x38] == '\0') {
              uVar6 = Agent::getSellItemPrice(in_r2);
              VectorSignedToFloat(uVar6,(byte)(in_fpscr >> 0x16) & 3);
            }
            else {
              uVar6 = Agent::getSellItemPrice(in_r2);
              VectorSignedToFloat(uVar6,(byte)(in_fpscr >> 0x16) & 3);
            }
            Layout::formatCredits((int)local_18c);
            AbyssEngine::String::String(aSStack_2ec,(String *)local_18c,false);
            uVar6 = AbyssEngine::String::String(aSStack_2f4,"#C",false);
            Status::replaceHash(aAStack_3c,pSVar2,aSStack_2e4,aSStack_2ec,uVar6);
            AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
            AbyssEngine::String::~String((String *)aAStack_3c);
            AbyssEngine::String::~String(aSStack_2f4);
            AbyssEngine::String::~String(aSStack_2ec);
            AbyssEngine::String::~String((String *)local_18c);
            pSVar15 = aSStack_2e4;
          }
          else {
            iVar5 = Agent::getOffer(in_r2);
            if (iVar5 == 10) {
              iVar5 = *(int *)(in_r2 + 0x20);
              if (iVar5 == -1) {
                iVar5 = AbyssEngine::AERandom::nextInt(rnd,2);
                iVar5 = iVar5 + 0x36a;
              }
              *(int *)(in_r2 + 0x20) = iVar5;
              pSVar17 = (String *)GameText::getText(gameText,iVar5);
              AbyssEngine::String::operator=(aSStack_34,pSVar17);
              AbyssEngine::String::String((String *)local_18c," ",false);
              pGVar3 = gameText;
              iVar5 = Agent::getIndex(in_r2);
              pSVar17 = (String *)GameText::getText(pGVar3,iVar5 + 0x376);
              AbyssEngine::operator+(aAStack_3c,(String *)local_18c,pSVar17);
              AbyssEngine::String::operator+=(aSStack_34,aAStack_3c);
              AbyssEngine::String::~String((String *)aAStack_3c);
              AbyssEngine::String::~String((String *)local_18c);
              iVar5 = *(int *)(in_r2 + 0x24);
              if (iVar5 == -1) {
                iVar5 = AbyssEngine::AERandom::nextInt(rnd,2);
                iVar5 = iVar5 + 0x305;
              }
              *(int *)(in_r2 + 0x24) = iVar5;
              AbyssEngine::String::String((String *)local_18c,"\n",false);
              pSVar17 = (String *)GameText::getText(gameText,iVar5);
              AbyssEngine::operator+(aAStack_3c,(String *)local_18c,pSVar17);
              AbyssEngine::String::operator+=(aSStack_34,aAStack_3c);
              AbyssEngine::String::~String((String *)aAStack_3c);
              AbyssEngine::String::~String((String *)local_18c);
              pSVar2 = status;
              AbyssEngine::String::String(aSStack_2fc,aSStack_34,false);
              local_18c[0] = 0;
              AbyssEngine::String::Set(CONCAT44(extraout_r1,local_18c));
              AbyssEngine::String::String(aSStack_304,(String *)local_18c,false);
              uVar6 = AbyssEngine::String::String(aSStack_30c,"#Q",false);
              Status::replaceHash(aAStack_3c,pSVar2,aSStack_2fc,aSStack_304,uVar6);
              AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
              AbyssEngine::String::~String((String *)aAStack_3c);
              AbyssEngine::String::~String(aSStack_30c);
              AbyssEngine::String::~String(aSStack_304);
              AbyssEngine::String::~String((String *)local_18c);
              AbyssEngine::String::~String(aSStack_2fc);
              pSVar2 = status;
              AbyssEngine::String::String(aSStack_314,aSStack_34,false);
              pGVar3 = gameText;
              iVar5 = Agent::getSellItemIndex(in_r2);
              pSVar17 = (String *)GameText::getText(pGVar3,iVar5 + 0x391);
              AbyssEngine::String::String(aSStack_31c,pSVar17,false);
              uVar6 = AbyssEngine::String::String(aSStack_324,"#P",false);
              Status::replaceHash(aAStack_3c,pSVar2,aSStack_314,aSStack_31c,uVar6);
              AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
              AbyssEngine::String::~String((String *)aAStack_3c);
              AbyssEngine::String::~String(aSStack_324);
              AbyssEngine::String::~String(aSStack_31c);
              AbyssEngine::String::~String(aSStack_314);
              pSVar2 = status;
              AbyssEngine::String::String(aSStack_32c,aSStack_34,false);
              if (options[0x38] == '\0') {
                uVar6 = Agent::getSellItemPrice(in_r2);
                VectorSignedToFloat(uVar6,(byte)(in_fpscr >> 0x16) & 3);
              }
              else {
                uVar6 = Agent::getSellItemPrice(in_r2);
                VectorSignedToFloat(uVar6,(byte)(in_fpscr >> 0x16) & 3);
              }
              Layout::formatCredits((int)local_18c);
              AbyssEngine::String::String(aSStack_334,(String *)local_18c,false);
              uVar6 = AbyssEngine::String::String(aSStack_33c,"#C",false);
              Status::replaceHash(aAStack_3c,pSVar2,aSStack_32c,aSStack_334,uVar6);
              AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
              AbyssEngine::String::~String((String *)aAStack_3c);
              AbyssEngine::String::~String(aSStack_33c);
              AbyssEngine::String::~String(aSStack_334);
              AbyssEngine::String::~String((String *)local_18c);
              pSVar15 = aSStack_32c;
            }
            else {
              iVar5 = Agent::getOffer(in_r2);
              iVar8 = *(int *)(in_r2 + 0x20);
              if (iVar5 == 4) {
                if (iVar8 == -1) {
                  iVar8 = AbyssEngine::AERandom::nextInt(rnd,2);
                  iVar8 = iVar8 + 0x36a;
                }
                *(int *)(in_r2 + 0x20) = iVar8;
                pSVar17 = (String *)GameText::getText(gameText,iVar8);
                AbyssEngine::String::operator=(aSStack_34,pSVar17);
                AbyssEngine::String::String((String *)local_18c," ",false);
                pGVar3 = gameText;
                iVar5 = Agent::getIndex(in_r2);
                pSVar17 = (String *)GameText::getText(pGVar3,iVar5 + 0x376);
                AbyssEngine::operator+(aAStack_3c,(String *)local_18c,pSVar17);
                AbyssEngine::String::operator+=(aSStack_34,aAStack_3c);
                AbyssEngine::String::~String((String *)aAStack_3c);
                AbyssEngine::String::~String((String *)local_18c);
                AbyssEngine::String::String((String *)local_18c," ",false);
                pSVar17 = (String *)GameText::getText(gameText,0x36d);
                AbyssEngine::operator+(aAStack_3c,(String *)local_18c,pSVar17);
                AbyssEngine::String::operator+=(aSStack_34,aAStack_3c);
                AbyssEngine::String::~String((String *)aAStack_3c);
                AbyssEngine::String::~String((String *)local_18c);
                this = galaxy;
                iVar5 = Agent::getSellSystemIndex(in_r2);
                Galaxy::getSystem(this,iVar5);
                pSVar2 = status;
                AbyssEngine::String::String(aSStack_344,(String *)local_54,false);
                SolarSystem::getName();
                AbyssEngine::String::String(aSStack_34c,(String *)local_18c,false);
                uVar6 = AbyssEngine::String::String(aSStack_354,"#S",false);
                Status::replaceHash(aAStack_3c,pSVar2,aSStack_344,aSStack_34c,uVar6);
                AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
                AbyssEngine::String::~String((String *)aAStack_3c);
                AbyssEngine::String::~String(aSStack_354);
                AbyssEngine::String::~String(aSStack_34c);
                AbyssEngine::String::~String((String *)local_18c);
                AbyssEngine::String::~String(aSStack_344);
                pSVar2 = status;
                AbyssEngine::String::String(aSStack_35c,(String *)local_54,false);
                Agent::getSellItemPrice(in_r2);
                Layout::formatCredits((int)local_18c);
                AbyssEngine::String::String(aSStack_364,(String *)local_18c,false);
                uVar6 = AbyssEngine::String::String(aSStack_36c,"#C",false);
                Status::replaceHash(aAStack_3c,pSVar2,aSStack_35c,aSStack_364,uVar6);
                AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
                AbyssEngine::String::~String((String *)aAStack_3c);
                AbyssEngine::String::~String(aSStack_36c);
                AbyssEngine::String::~String(aSStack_364);
                AbyssEngine::String::~String((String *)local_18c);
                pSVar15 = aSStack_35c;
              }
              else {
                if (iVar8 == -1) {
                  iVar8 = AbyssEngine::AERandom::nextInt(rnd,2);
                  iVar8 = iVar8 + 0x36a;
                }
                *(int *)(in_r2 + 0x20) = iVar8;
                pSVar17 = (String *)GameText::getText(gameText,iVar8);
                AbyssEngine::String::operator=(aSStack_34,pSVar17);
                AbyssEngine::String::String((String *)local_18c," ",false);
                pGVar3 = gameText;
                iVar5 = Agent::getIndex(in_r2);
                pSVar17 = (String *)GameText::getText(pGVar3,iVar5 + 0x376);
                AbyssEngine::operator+(aAStack_3c,(String *)local_18c,pSVar17);
                AbyssEngine::String::operator+=(aSStack_34,aAStack_3c);
                AbyssEngine::String::~String((String *)aAStack_3c);
                AbyssEngine::String::~String((String *)local_18c);
                AbyssEngine::String::String((String *)local_18c," ",false);
                pSVar17 = (String *)GameText::getText(gameText,0x36c);
                AbyssEngine::operator+(aAStack_3c,(String *)local_18c,pSVar17);
                AbyssEngine::String::operator+=(aSStack_34,aAStack_3c);
                AbyssEngine::String::~String((String *)aAStack_3c);
                AbyssEngine::String::~String((String *)local_18c);
                pSVar2 = status;
                AbyssEngine::String::String(aSStack_374,(String *)local_54,false);
                iVar5 = items;
                pGVar3 = gameText;
                iVar8 = Agent::getSellBlueprintIndex(in_r2);
                iVar5 = Item::getIndex(*(Item **)(*(int *)(iVar5 + 4) + iVar8 * 4));
                pSVar17 = (String *)GameText::getText(pGVar3,iVar5 + 0x4fa);
                AbyssEngine::String::String(aSStack_37c,pSVar17,false);
                uVar6 = AbyssEngine::String::String(aSStack_384,"#N",false);
                Status::replaceHash(aAStack_3c,pSVar2,aSStack_374,aSStack_37c,uVar6);
                AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
                AbyssEngine::String::~String((String *)aAStack_3c);
                AbyssEngine::String::~String(aSStack_384);
                AbyssEngine::String::~String(aSStack_37c);
                AbyssEngine::String::~String(aSStack_374);
                pSVar2 = status;
                AbyssEngine::String::String(aSStack_38c,(String *)local_54,false);
                Agent::getSellItemPrice(in_r2);
                Layout::formatCredits((int)local_18c);
                AbyssEngine::String::String(aSStack_394,(String *)local_18c,false);
                uVar6 = AbyssEngine::String::String(aSStack_39c,"#C",false);
                Status::replaceHash(aAStack_3c,pSVar2,aSStack_38c,aSStack_394,uVar6);
                AbyssEngine::String::operator=(aSStack_34,aAStack_3c);
                AbyssEngine::String::~String((String *)aAStack_3c);
                AbyssEngine::String::~String(aSStack_39c);
                AbyssEngine::String::~String(aSStack_394);
                AbyssEngine::String::~String((String *)local_18c);
                pSVar15 = aSStack_38c;
              }
            }
          }
        }
        AbyssEngine::String::~String(pSVar15);
        AbyssEngine::String::String((String *)local_18c,"\n",false);
        pGVar3 = gameText;
        iVar5 = AbyssEngine::AERandom::nextInt(rnd,3);
        pSVar17 = (String *)GameText::getText(pGVar3,iVar5 + 0x349);
        AbyssEngine::operator+(aAStack_3c,(String *)local_18c,pSVar17);
        AbyssEngine::String::operator+=(aSStack_34,aAStack_3c);
        AbyssEngine::String::~String((String *)aAStack_3c);
        AbyssEngine::String::~String((String *)local_18c);
      }
    }
    else {
      pSVar17 = (String *)GameText::getText(gameText,0x35a);
      AbyssEngine::String::operator=(aSStack_34,pSVar17);
    }
    pSVar15 = (String *)local_54;
LAB_000fc552:
    AbyssEngine::String::~String(pSVar15);
  }
  AbyssEngine::String::String((String *)param_1,aSStack_34,false);
LAB_000fc560:
  AbyssEngine::String::~String(aSStack_34);
LAB_000fc56c:
  if (__stack_chk_guard != local_2c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Globals::setCoordsSteer  @0x000fcd6c  (736 bytes)
/* Globals::setCoordsSteer(int, int, int, int, unsigned short&, unsigned short&, unsigned short&,
   unsigned short&, unsigned short&, unsigned short&, unsigned short&, unsigned short&, unsigned
   short&, unsigned short&) */

void __thiscall
Globals::setCoordsSteer
          (Globals *this,int param_1,int param_2,int param_3,int param_4,ushort *param_5,
          ushort *param_6,ushort *param_7,ushort *param_8,ushort *param_9,ushort *param_10,
          ushort *param_11,ushort *param_12,ushort *param_13,ushort *param_14)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  short sVar4;
  undefined4 uVar5;
  char cVar6;
  float *pfVar7;
  ushort uVar8;
  int iVar9;
  int iVar10;
  float *pfVar11;
  uint in_fpscr;
  float fVar12;
  float fVar13;
  int iVar14;
  float fVar15;
  float fVar16;
  
  iVar10 = h;
  cVar6 = iPadHD;
  iVar9 = ((-0x19 - param_2) - param_3) + h;
  if (iPadHD == '\0') {
    pfVar7 = (float *)&DAT_000fd05c;
    if (iPadLarge != '\0') {
      pfVar7 = (float *)&DAT_000fd060;
    }
    fVar12 = *pfVar7;
  }
  else {
    fVar12 = 210.9375;
  }
  if (iVar9 < param_1) {
    param_1 = iVar9;
  }
  fVar13 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  uVar1 = in_fpscr & 0xfffffff;
  uVar2 = uVar1 | (uint)(fVar12 < fVar13) << 0x1f | (uint)(fVar12 == fVar13) << 0x1e;
  bVar3 = (byte)(uVar2 >> 0x18);
  if ((bool)(bVar3 >> 6 & 1) || (bool)(bVar3 >> 7) != (NAN(fVar12) || NAN(fVar13))) {
    options._84_4_ = (undefined4)fVar13;
    uVar8 = (ushort)(int)fVar13;
    if (iPadHD == '\0') goto LAB_000fce4c;
  }
  else {
    if (iPadHD == '\0') {
      options._84_4_ = 0x96;
      if (iPadLarge != '\0') {
        options._84_4_ = 300;
      }
LAB_000fce4c:
      uVar5 = options._84_4_;
      uVar8 = 0x14;
      if (iPadLarge != '\0') {
        uVar8 = 0x28;
      }
      *param_5 = uVar8;
      pfVar11 = (float *)&DAT_000fd088;
      *param_6 = (ushort)uVar5;
      *param_13 = uVar8;
      pfVar7 = (float *)&DAT_000fd080;
      fVar12 = (float)VectorUnsignedToFloat((uint)*param_6,(byte)(uVar2 >> 0x16) & 3);
      if (iPadLarge != '\0') {
        pfVar7 = (float *)&DAT_000fd084;
      }
      *param_14 = (ushort)(0.0 < fVar12 - *pfVar7) * (short)(int)(fVar12 - *pfVar7);
      *param_7 = 0x14;
      if (iPadLarge != '\0') {
        pfVar11 = (float *)&DAT_000fd08c;
      }
      fVar12 = *pfVar11;
      goto LAB_000fceac;
    }
    uVar8 = 0xd2;
    options._84_4_ = 0xd2;
  }
  *param_5 = 0x1c;
  *param_6 = uVar8;
  *param_13 = 0x1c;
  fVar13 = (float)VectorUnsignedToFloat((uint)*param_6,(byte)(uVar2 >> 0x16) & 3);
  fVar12 = 92.8125;
  *param_14 = (ushort)(0.0 < fVar13 + -126.5625) * (short)(int)(fVar13 + -126.5625);
  *param_7 = 0x14;
LAB_000fceac:
  fVar13 = (float)VectorUnsignedToFloat((uint)*param_6,(byte)(uVar2 >> 0x16) & 3);
  *param_8 = (ushort)(0.0 < fVar13 + fVar12) * (short)(int)(fVar13 + fVar12);
  sVar4 = (short)(param_2 / 2);
  *param_9 = *param_7 + sVar4;
  *param_10 = *param_8 + sVar4;
  fVar12 = (float)VectorUnsignedToFloat((uint)*param_6,(byte)(uVar2 >> 0x16) & 3);
  if (cVar6 == '\0') {
    pfVar7 = (float *)&DAT_000fd09c;
    fVar13 = 2.0;
    if (iPadLarge != '\0') {
      pfVar7 = (float *)&DAT_000fd0a0;
    }
    fVar12 = fVar12 + *pfVar7;
    if (iPadLarge != '\0') {
      fVar13 = 4.0;
    }
  }
  else {
    fVar12 = fVar12 + 313.59375;
    fVar13 = 2.8125;
  }
  iVar9 = (uint)(0.0 < fVar12) * (int)fVar12;
  *param_12 = (ushort)iVar9;
  fVar12 = (float)VectorSignedToFloat(iVar10 - param_4,(byte)(uVar2 >> 0x16) & 3);
  fVar15 = (float)VectorUnsignedToFloat(iVar9,(byte)(uVar2 >> 0x16) & 3);
  fVar13 = fVar12 - fVar13;
  uVar2 = uVar1 | (uint)(fVar15 < fVar13) << 0x1f | (uint)(fVar15 == fVar13) << 0x1e;
  bVar3 = (byte)(uVar2 >> 0x18);
  if (!(bool)(bVar3 >> 6 & 1) && (bool)(bVar3 >> 7) == (NAN(fVar15) || NAN(fVar13))) {
    if (cVar6 == '\0') {
      fVar13 = 2.0;
      iVar10 = 0xad;
      if (iPadLarge != '\0') {
        fVar13 = 4.0;
      }
      fVar15 = fVar15 - (fVar12 - fVar13);
      iVar14 = (uint)(0.0 < fVar15) * (int)fVar15;
      *param_12 = (ushort)iVar14;
      iVar9 = 0x85;
      if (iPadLarge != '\0') {
        iVar10 = 0x15a;
        iVar9 = 0x10a;
      }
    }
    else {
      iVar10 = 0xf3;
      iVar9 = 0xbb;
      fVar15 = fVar15 - (fVar12 + -2.8125);
      iVar14 = (uint)(0.0 < fVar15) * (int)fVar15;
      *param_12 = (ushort)iVar14;
    }
    fVar15 = (float)VectorUnsignedToFloat(iVar14,(byte)(uVar2 >> 0x16) & 3);
    fVar16 = (float)VectorSignedToFloat(iVar10 - iVar9,(byte)(uVar2 >> 0x16) & 3);
    fVar13 = 1.0;
    if (fVar15 / 54.0 < 1.0) {
      fVar13 = fVar15 / 54.0;
    }
    fVar15 = (float)VectorSignedToFloat(iVar9,(byte)(uVar1 >> 0x16) & 3);
    fVar15 = fVar15 + fVar16 * fVar13;
    *param_11 = (ushort)(0.0 < fVar15) * (short)(int)fVar15;
    if (cVar6 == '\0') {
      fVar13 = 2.0;
      if (iPadLarge != '\0') {
        fVar13 = 4.0;
      }
    }
    else {
      fVar13 = 2.8125;
    }
    *param_12 = (ushort)(0.0 < fVar12 - fVar13) * (short)(int)(fVar12 - fVar13);
    return;
  }
  if (cVar6 == '\0') {
    uVar8 = 0x14;
    if (iPadLarge != '\0') {
      uVar8 = 0x28;
    }
  }
  else {
    uVar8 = 0x1c;
  }
  *param_11 = uVar8;
  return;
}

// ===== Globals::setCoordsFire  @0x000fd0b8  (1084 bytes)
/* Globals::setCoordsFire(int, int, unsigned int, unsigned int, unsigned int&, unsigned short&,
   unsigned short&, unsigned short&, unsigned short&, unsigned short&, unsigned short&, unsigned
   short&, unsigned short&, unsigned short&, unsigned short&, unsigned short&, unsigned short&) */

void __thiscall
Globals::setCoordsFire
          (Globals *this,int param_1,int param_2,uint param_3,uint param_4,uint *param_5,
          ushort *param_6,ushort *param_7,ushort *param_8,ushort *param_9,ushort *param_10,
          ushort *param_11,ushort *param_12,ushort *param_13,ushort *param_14,ushort *param_15,
          ushort *param_16,ushort *param_17)

{
  uint uVar1;
  byte bVar2;
  short sVar3;
  char cVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  uint in_fpscr;
  uint uVar10;
  float fVar11;
  ushort uVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  
  cVar4 = iPadHD;
  if (iPadHD == '\0') {
    pfVar5 = (float *)&DAT_000fd508;
    pfVar6 = (float *)&DAT_000fd510;
    if (iPadLarge != '\0') {
      pfVar5 = (float *)&DAT_000fd50c;
      pfVar6 = (float *)&DAT_000fd514;
    }
    fVar14 = *pfVar5;
    fVar13 = *pfVar6;
  }
  else {
    fVar14 = 63.28125;
    fVar13 = 210.9375;
  }
  iVar8 = h - param_2;
  fVar15 = (float)VectorSignedToFloat(iVar8,(byte)(in_fpscr >> 0x16) & 3);
  fVar11 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  fVar15 = fVar15 + fVar14;
  uVar1 = in_fpscr & 0xfffffff;
  uVar10 = uVar1 | (uint)(fVar11 < fVar15) << 0x1f | (uint)(fVar11 == fVar15) << 0x1e;
  bVar2 = (byte)(uVar10 >> 0x18);
  fVar14 = fVar11;
  if (!(bool)(bVar2 >> 6 & 1) && (bool)(bVar2 >> 7) == (NAN(fVar11) || NAN(fVar15))) {
    fVar14 = (float)VectorSignedToFloat(iVar8,(byte)(uVar10 >> 0x16) & 3);
    if (iPadHD == '\0') {
      pfVar5 = (float *)&DAT_000fd508;
      if (iPadLarge != '\0') {
        pfVar5 = (float *)&DAT_000fd50c;
      }
      fVar15 = *pfVar5;
    }
    else {
      fVar15 = 63.28125;
    }
    fVar14 = fVar14 + fVar15;
  }
  uVar10 = uVar1 | (uint)(fVar13 < fVar14) << 0x1f | (uint)(fVar13 == fVar14) << 0x1e;
  bVar2 = (byte)(uVar10 >> 0x18);
  if ((bool)(bVar2 >> 6 & 1) || (bool)(bVar2 >> 7) != (NAN(fVar13) || NAN(fVar14))) {
    fVar13 = (float)VectorSignedToFloat(iVar8,(byte)(uVar10 >> 0x16) & 3);
    if (iPadHD == '\0') {
      pfVar5 = (float *)&DAT_000fd508;
      if (iPadLarge != '\0') {
        pfVar5 = (float *)&DAT_000fd50c;
      }
      fVar14 = *pfVar5;
    }
    else {
      fVar14 = 63.28125;
    }
    fVar14 = fVar13 + fVar14;
    uVar10 = uVar1 | (uint)(fVar11 < fVar14) << 0x1f | (uint)(fVar11 == fVar14) << 0x1e;
    bVar2 = (byte)(uVar10 >> 0x18);
    if (!(bool)(bVar2 >> 6 & 1) && (bool)(bVar2 >> 7) == (NAN(fVar11) || NAN(fVar14))) {
      if (iPadHD == '\0') {
        pfVar5 = (float *)&DAT_000fd508;
        if (iPadLarge != '\0') {
          pfVar5 = (float *)&DAT_000fd50c;
        }
        fVar11 = *pfVar5;
      }
      else {
        fVar11 = 63.28125;
      }
      fVar11 = fVar13 + fVar11;
    }
    options._88_4_ = (undefined4)fVar11;
    fVar13 = (float)VectorSignedToFloat(w - param_2,(byte)(uVar10 >> 0x16) & 3);
    iVar7 = (int)fVar11;
    if (iPadHD == '\0') goto LAB_000fd250;
LAB_000fd248:
    fVar14 = 56.25;
  }
  else {
    if (iPadHD != '\0') {
      iVar7 = 0xd2;
      options._88_4_ = 0xd2;
      fVar13 = (float)VectorSignedToFloat(w - param_2,(byte)(uVar10 >> 0x16) & 3);
      goto LAB_000fd248;
    }
    options._88_4_ = 0x96;
    if (iPadLarge != '\0') {
      options._88_4_ = 300;
    }
    fVar13 = (float)VectorSignedToFloat(w - param_2,(byte)(uVar10 >> 0x16) & 3);
LAB_000fd250:
    pfVar5 = (float *)&DAT_000fd54c;
    if (iPadLarge != '\0') {
      pfVar5 = (float *)&DAT_000fd550;
    }
    fVar14 = *pfVar5;
    iVar7 = options._88_4_;
  }
  bVar9 = iPadHD == '\0';
  *param_6 = (ushort)(0.0 < fVar13 + fVar14) * (short)(int)(fVar13 + fVar14);
  *param_7 = (ushort)iVar7;
  sVar3 = (short)(param_2 >> 1);
  *param_8 = *param_6 + sVar3;
  *param_9 = *param_7 + sVar3;
  fVar13 = (float)VectorUnsignedToFloat((uint)*param_6,(byte)(uVar10 >> 0x16) & 3);
  if (bVar9) {
    pfVar5 = (float *)&DAT_000fd570;
    if (iPadLarge != '\0') {
      pfVar5 = (float *)&DAT_000fd574;
    }
    fVar14 = 4.0;
    *param_10 = (ushort)(0.0 < fVar13 + *pfVar5) * (short)(int)(fVar13 + *pfVar5);
    fVar13 = (float)VectorUnsignedToFloat((uint)*param_7,(byte)(uVar10 >> 0x16) & 3);
    if (iPadLarge != '\0') {
      fVar14 = 8.0;
    }
    fVar11 = 15.0;
    *param_11 = (ushort)(0.0 < fVar13 + fVar14) * (short)(int)(fVar13 + fVar14);
    fVar13 = (float)VectorUnsignedToFloat((uint)*param_6,(byte)(uVar10 >> 0x16) & 3);
    if (iPadLarge != '\0') {
      fVar11 = 28.0;
    }
    fVar14 = 13.0;
    *param_12 = (ushort)(0.0 < fVar13 + fVar11) * (short)(int)(fVar13 + fVar11);
    fVar13 = (float)VectorUnsignedToFloat((uint)*param_7,(byte)(uVar10 >> 0x16) & 3);
    if (iPadLarge != '\0') {
      fVar14 = 27.0;
    }
    *param_13 = (ushort)(0.0 < fVar13 + fVar14) * (short)(int)(fVar13 + fVar14);
    pfVar5 = (float *)&DAT_000fd578;
    fVar13 = (float)VectorUnsignedToFloat((uint)*param_6,(byte)(uVar10 >> 0x16) & 3);
    if (iPadLarge != '\0') {
      pfVar5 = (float *)&DAT_000fd57c;
    }
    pfVar6 = (float *)&DAT_000fd580;
    uVar12 = (ushort)(0.0 < fVar13 + *pfVar5) * (short)(int)(fVar13 + *pfVar5);
    if (iPadLarge != '\0') {
      pfVar6 = (float *)&DAT_000fd584;
    }
    fVar13 = *pfVar6;
  }
  else {
    *param_10 = (ushort)(0.0 < fVar13 + 107.28125) * (short)(int)(fVar13 + 107.28125);
    fVar13 = (float)VectorUnsignedToFloat((uint)*param_7,(byte)(uVar10 >> 0x16) & 3);
    *param_11 = (ushort)(0.0 < fVar13 + 5.625) * (short)(int)(fVar13 + 5.625);
    fVar13 = (float)VectorUnsignedToFloat((uint)*param_6,(byte)(uVar10 >> 0x16) & 3);
    *param_12 = (ushort)(0.0 < fVar13 + 18.09375) * (short)(int)(fVar13 + 18.09375);
    fVar13 = (float)VectorUnsignedToFloat((uint)*param_7,(byte)(uVar10 >> 0x16) & 3);
    *param_13 = (ushort)(0.0 < fVar13 + 19.28125) * (short)(int)(fVar13 + 19.28125);
    fVar13 = (float)VectorUnsignedToFloat((uint)*param_6,(byte)(uVar10 >> 0x16) & 3);
    uVar12 = (ushort)(0.0 < fVar13 + 112.5) * (short)(int)(fVar13 + 112.5);
    fVar13 = 94.21875;
  }
  *param_16 = uVar12;
  fVar14 = (float)VectorUnsignedToFloat((uint)*param_7,(byte)(uVar10 >> 0x16) & 3);
  *param_17 = (ushort)(0.0 < fVar14 - fVar13) * (short)(int)(fVar14 - fVar13);
  if (iVar8 < iVar7) {
    *param_5 = param_3;
    fVar13 = (float)VectorUnsignedToFloat((uint)*param_6,(byte)(uVar10 >> 0x16) & 3);
    if (cVar4 != '\0') {
      uVar12 = (ushort)(0.0 < fVar13 + -2.0) * (short)(int)(fVar13 + -2.0);
      fVar13 = 132.1875;
      goto LAB_000fd4d6;
    }
    fVar14 = 0.0;
    pfVar5 = (float *)&DAT_000fd5b0;
    if (iPadLarge != '\0') {
      fVar14 = -2.0;
    }
  }
  else {
    *param_5 = param_4;
    fVar13 = (float)VectorUnsignedToFloat((uint)*param_6,(byte)(uVar10 >> 0x16) & 3);
    if (cVar4 != '\0') {
      uVar12 = (ushort)(0.0 < fVar13 + 100.0625) * (short)(int)(fVar13 + 100.0625);
      fVar13 = 209.53125;
      goto LAB_000fd4d6;
    }
    pfVar5 = (float *)&DAT_000fd594;
    if (iPadLarge != '\0') {
      pfVar5 = (float *)&DAT_000fd598;
    }
    fVar14 = *pfVar5;
    pfVar5 = (float *)&UNK_000fd59c;
  }
  uVar12 = (ushort)(0.0 < fVar13 + fVar14) * (short)(int)(fVar13 + fVar14);
  if (iPadLarge != '\0') {
    pfVar5 = pfVar5 + 1;
  }
  fVar13 = *pfVar5;
LAB_000fd4d6:
  *param_14 = uVar12;
  fVar14 = (float)VectorUnsignedToFloat((uint)*param_7,(byte)(uVar10 >> 0x16) & 3);
  *param_15 = (ushort)(0.0 < fVar14 + fVar13) * (short)(int)(fVar14 + fVar13);
  return;
}

// ===== Globals::getKeyBindingReplaceString  @0x000fd5b8  (66 bytes)
/* Globals::getKeyBindingReplaceString(int) */

void Globals::getKeyBindingReplaceString(int param_1)

{
  String *this;
  String *pSVar1;
  String aSStack_1c [8];
  int local_14;
  
  local_14 = __stack_chk_guard;
  this = (String *)AbyssEngine::String::String(aSStack_1c);
  pSVar1 = (String *)AbyssEngine::String::ToUpperCase(this);
  AbyssEngine::String::String((String *)param_1,pSVar1,false);
  AbyssEngine::String::~String(aSStack_1c);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Globals::getKeyActionName  @0x000fd610  (10 bytes)
/* Globals::getKeyActionName(int) */

void Globals::getKeyActionName(int param_1)

{
  AbyssEngine::String::String((String *)param_1);
  return;
}

// ===== Globals::replaceKeyBindingTokens  @0x000fd61a  (14 bytes)
/* Globals::replaceKeyBindingTokens(AbyssEngine::String const&) */

void Globals::replaceKeyBindingTokens(String *param_1)

{
  String *in_r2;
  
  AbyssEngine::String::String((String *)param_1,in_r2,false);
  return;
}

// ===== Globals::sqrt  @0x000fd628  (8 bytes)
/* Globals::sqrt(float) */

void Globals::sqrt(float param_1)

{
  AbyssEngine::AEMath::Sqrtf(param_1);
  return;
}

// ===== Globals::getInAppPurchaseArrayIndex  @0x000fd630  (562 bytes)
/* Globals::getInAppPurchaseArrayIndex(int, Array<AbyssEngine::String*>*) */

void __thiscall Globals::getInAppPurchaseArrayIndex(Globals *this,int param_1,Array *param_2)

{
  bool bVar1;
  char cVar2;
  String *this_00;
  uint uVar3;
  uint local_44;
  String aSStack_40 [8];
  String aSStack_38 [8];
  AbyssEngine aAStack_30 [8];
  uint local_28;
  
  local_28 = __stack_chk_guard;
  local_44 = __stack_chk_guard;
  if (param_2 != (Array *)0x0) {
    local_44 = *(uint *)param_2;
  }
  if (param_2 != (Array *)0x0 && local_44 != 0) {
    uVar3 = 0;
    do {
      this_00 = *(String **)(*(int *)(param_2 + 4) + uVar3 * 4);
      AbyssEngine::String::String(aSStack_38,"www.fishlabs.net.gof2hd",false);
      AbyssEngine::String::String(aSStack_40,".",false);
      AbyssEngine::operator+(aAStack_30,aSStack_38,aSStack_40);
      AbyssEngine::String::~String(aSStack_40);
      AbyssEngine::String::~String(aSStack_38);
      if (this_00 == (String *)0x0) {
        bVar1 = false;
        local_44 = 0xffffffff;
      }
      else {
        switch(param_1) {
        case 0:
          AbyssEngine::String::String(aSStack_40,"dlc1",false);
          AbyssEngine::operator+((AbyssEngine *)aSStack_38,aAStack_30,aSStack_40);
          cVar2 = AbyssEngine::String::Compare(this_00,aSStack_38);
          break;
        case 1:
          AbyssEngine::String::String(aSStack_40,"dlc2",false);
          AbyssEngine::operator+((AbyssEngine *)aSStack_38,aAStack_30,aSStack_40);
          cVar2 = AbyssEngine::String::Compare(this_00,aSStack_38);
          break;
        case 2:
          AbyssEngine::String::String(aSStack_40,"dlc3",false);
          AbyssEngine::operator+((AbyssEngine *)aSStack_38,aAStack_30,aSStack_40);
          cVar2 = AbyssEngine::String::Compare(this_00,aSStack_38);
          break;
        case 3:
          AbyssEngine::String::String(aSStack_40,"dlc4",false);
          AbyssEngine::operator+((AbyssEngine *)aSStack_38,aAStack_30,aSStack_40);
          cVar2 = AbyssEngine::String::Compare(this_00,aSStack_38);
          break;
        case 4:
          AbyssEngine::String::String(aSStack_40,"dlc5",false);
          AbyssEngine::operator+((AbyssEngine *)aSStack_38,aAStack_30,aSStack_40);
          cVar2 = AbyssEngine::String::Compare(this_00,aSStack_38);
          break;
        default:
          switch(param_1) {
          case 0x32:
            AbyssEngine::String::String(aSStack_40,"dlcCredits1",false);
            AbyssEngine::operator+((AbyssEngine *)aSStack_38,aAStack_30,aSStack_40);
            cVar2 = AbyssEngine::String::Compare(this_00,aSStack_38);
            break;
          case 0x33:
            AbyssEngine::String::String(aSStack_40,"dlcCredits2",false);
            AbyssEngine::operator+((AbyssEngine *)aSStack_38,aAStack_30,aSStack_40);
            cVar2 = AbyssEngine::String::Compare(this_00,aSStack_38);
            break;
          case 0x34:
            AbyssEngine::String::String(aSStack_40,"dlcCredits3",false);
            AbyssEngine::operator+((AbyssEngine *)aSStack_38,aAStack_30,aSStack_40);
            cVar2 = AbyssEngine::String::Compare(this_00,aSStack_38);
            break;
          case 0x35:
            AbyssEngine::String::String(aSStack_40,"dlcCredits4.0",false);
            AbyssEngine::operator+((AbyssEngine *)aSStack_38,aAStack_30,aSStack_40);
            cVar2 = AbyssEngine::String::Compare(this_00,aSStack_38);
            break;
          case 0x36:
            AbyssEngine::String::String(aSStack_40,"dlcCredits5",false);
            AbyssEngine::operator+((AbyssEngine *)aSStack_38,aAStack_30,aSStack_40);
            cVar2 = AbyssEngine::String::Compare(this_00,aSStack_38);
            break;
          default:
            goto switchD_000fd6ac_default;
          }
        }
        AbyssEngine::String::~String(aSStack_38);
        AbyssEngine::String::~String(aSStack_40);
        if (cVar2 == '\0') {
          bVar1 = false;
          local_44 = uVar3;
        }
        else {
switchD_000fd6ac_default:
          bVar1 = true;
        }
      }
      AbyssEngine::String::~String((String *)aAStack_30);
      if (!bVar1) goto LAB_000fd852;
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)param_2);
  }
  local_44 = 0xffffffff;
LAB_000fd852:
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_44);
}

