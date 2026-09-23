// Class: NewsTicker
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== NewsTicker::NewsTicker  @0x001889d4  (1022 bytes)
/* NewsTicker::NewsTicker(int, int, int, int, int) */

void __thiscall
NewsTicker::NewsTicker(NewsTicker *this,int param_1,int param_2,int param_3,int param_4,int param_5)

{
  bool bVar1;
  Status *pSVar2;
  AERandom *this_00;
  bool bVar3;
  short sVar4;
  FileRead *this_01;
  Array *pAVar5;
  void *pvVar6;
  Array *pAVar7;
  undefined4 *puVar8;
  int iVar9;
  NewsItem *pNVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  SolarSystem *this_02;
  String *pSVar14;
  uint uVar15;
  undefined4 extraout_r1;
  int iVar16;
  String *this_03;
  uint uVar17;
  int *piVar18;
  bool bVar19;
  uint in_fpscr;
  longlong lVar20;
  undefined8 uVar21;
  AbyssEngine aAStack_48 [8];
  String aSStack_40 [8];
  String aSStack_38 [8];
  String aSStack_30 [8];
  int local_28;
  
  this_03 = (String *)(this + 0x14);
  local_28 = __stack_chk_guard;
  AbyssEngine::String::String(this_03);
  *(int *)(this + 4) = param_1;
  *(int *)(this + 8) = param_2;
  *(int *)(this + 0xc) = param_3;
  AbyssEngine::String::String(aSStack_30,"",false);
  AbyssEngine::String::operator=(this_03,aSStack_30);
  AbyssEngine::String::~String(aSStack_30);
  *(undefined4 *)(this + 0x10) = 0;
  this_01 = operator_new(1);
  FileRead::FileRead(this_01);
  pAVar5 = (Array *)FileRead::loadTicker();
  pvVar6 = (void *)FileRead::~FileRead(this_01);
  operator_delete(pvVar6);
  pAVar7 = operator_new(0xc);
  puVar8 = operator_new__(4);
  *(undefined4 **)(pAVar7 + 4) = puVar8;
  *(undefined4 *)(pAVar7 + 8) = 1;
  *puVar8 = 0;
  this_00 = Globals::rnd;
  *(undefined4 *)pAVar7 = 0;
  iVar9 = AbyssEngine::AERandom::nextInt(this_00,1);
  uVar15 = *(uint *)pAVar5;
  if (uVar15 != 0) {
    uVar17 = 0;
    do {
      pNVar10 = *(NewsItem **)(*(int *)(pAVar5 + 4) + uVar17 * 4);
      if ((((0 < *(int *)(pNVar10 + 0x10)) && (*(int *)(pNVar10 + 0x10) <= param_5)) &&
          (param_5 <= *(int *)(pNVar10 + 0x14))) &&
         (*(char *)(*(int *)(pNVar10 + 8) + param_4) != '\0')) {
        uVar11 = NewsItem::clone(pNVar10);
        *(int *)(pAVar7 + 8) = *(int *)pAVar7 + 1;
        pvVar6 = realloc(*(void **)(pAVar7 + 4),(*(int *)pAVar7 + 1) * 4);
        *(void **)(pAVar7 + 4) = pvVar6;
        *(undefined4 *)((int)pvVar6 + *(int *)pAVar7 * 4) = uVar11;
        *(undefined4 *)pAVar7 = *(undefined4 *)(pAVar7 + 8);
        uVar15 = *(uint *)pAVar5;
      }
      uVar17 = uVar17 + 1;
    } while (uVar17 < uVar15);
  }
  iVar16 = 0;
  bVar1 = false;
  iVar12 = 0;
  do {
    bVar3 = bVar1;
    do {
      do {
        bVar1 = bVar3;
        if (iVar9 + 2 <= iVar12 || 99 < iVar16) {
          if (bVar1) {
            uVar11 = NewsItem::clone(*(NewsItem **)
                                      (*(int *)(pAVar5 + 4) + *(int *)(Globals::status + 0x170) * 4)
                                    );
            *(int *)(pAVar7 + 8) = *(int *)pAVar7 + 1;
            pvVar6 = realloc(*(void **)(pAVar7 + 4),(*(int *)pAVar7 + 1) * 4);
            *(void **)(pAVar7 + 4) = pvVar6;
            *(undefined4 *)((int)pvVar6 + *(int *)pAVar7 * 4) = uVar11;
            *(undefined4 *)pAVar7 = *(undefined4 *)(pAVar7 + 8);
          }
          AbyssEngine::String::String(aSStack_30,"    +++    ",false);
          if (*(int *)pAVar7 != 0) {
            uVar15 = 0;
            do {
              piVar18 = *(int **)(*(int *)(pAVar7 + 4) + uVar15 * 4);
              pSVar14 = (String *)GameText::getText(Globals::gameText,*piVar18 + 0xcbe);
              AbyssEngine::String::String(aSStack_40,pSVar14,false);
              replaceTokens(aSStack_38,extraout_r1,aSStack_40);
              AbyssEngine::String::~String(aSStack_40);
              if ((char)piVar18[1] != '\0') {
                if ((char)piVar18[6] == '\0') {
                  AbyssEngine::String::operator=(aSStack_38,(String *)(Globals::status + 0x168));
                }
                else {
                  AbyssEngine::String::operator=((String *)(Globals::status + 0x168),aSStack_38);
                }
              }
              AbyssEngine::operator+(aAStack_48,aSStack_38,aSStack_30);
              AbyssEngine::String::operator+=(this_03,aAStack_48);
              AbyssEngine::String::~String((String *)aAStack_48);
              AbyssEngine::String::~String(aSStack_38);
              uVar15 = uVar15 + 1;
            } while (uVar15 < *(uint *)pAVar7);
          }
          iVar9 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,this_03);
          *(int *)(this + 0x10) = iVar9;
          if (iVar9 < param_3) {
            AbyssEngine::String::String(aSStack_38,this_03,false);
            AbyssEngine::String::operator+=(this_03,aSStack_38);
            AbyssEngine::String::~String(aSStack_38);
            uVar11 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,this_03);
            *(undefined4 *)(this + 0x10) = uVar11;
          }
          sVar4 = GameText::getLanguage();
          if (sVar4 == 9) {
            param_3 = -*(int *)(this + 0x10);
          }
          uVar11 = VectorSignedToFloat(param_3,(byte)(in_fpscr >> 0x16) & 3);
          *(undefined4 *)this = uVar11;
          *(undefined4 *)(this + 0x28) = 0;
          this[0x24] = (NewsTicker)0x0;
          ArrayReleaseClasses<NewsItem*>(pAVar7);
          if (*(void **)(pAVar7 + 4) != (void *)0x0) {
            operator_delete__(*(void **)(pAVar7 + 4));
          }
          operator_delete(pAVar7);
          ArrayReleaseClasses<NewsItem*>(pAVar5);
          if (pAVar5 != (Array *)0x0) {
            if (*(void **)(pAVar5 + 4) != (void *)0x0) {
              operator_delete__(*(void **)(pAVar5 + 4));
            }
            *(undefined4 *)(pAVar5 + 4) = 0;
            operator_delete(pAVar5);
          }
          AbyssEngine::String::~String(aSStack_30);
          if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
            __stack_chk_fail(__stack_chk_guard - local_28);
          }
          return;
        }
        iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,*(int *)pAVar5);
        pNVar10 = *(NewsItem **)(*(int *)(pAVar5 + 4) + iVar13 * 4);
        this_02 = (SolarSystem *)Status::getSystem(Globals::status);
        iVar13 = SolarSystem::getIndex(this_02);
      } while ((0x15 < iVar13) && (bVar3 = bVar1, *(int *)pNVar10 == 0xd));
      if ((((*(int *)(pNVar10 + 0x14) < 0xa1) ||
           ((param_5 < *(int *)(pNVar10 + 0x10) ||
            (iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,100), 0x31 < iVar13)))) ||
          (*(char *)(*(int *)(pNVar10 + 8) + param_4) == '\0')) || (pNVar10[0x18] != (NewsItem)0x0))
      goto LAB_00188b2c;
      if (pNVar10[4] == (NewsItem)0x0) goto LAB_00188bee;
      lVar20 = Status::getPlayingTime(Globals::status);
      iVar13 = (int)((ulonglong)(lVar20 - *(longlong *)(Globals::status + 0x160)) >> 0x20);
      bVar19 = 599999 < (uint)(lVar20 - *(longlong *)(Globals::status + 0x160));
      bVar3 = true;
    } while ((int)(-(uint)bVar19 - iVar13) < 0 ==
             (SBORROW4(0,iVar13) != SBORROW4(-iVar13,(uint)bVar19)));
    uVar21 = Status::getPlayingTime(Globals::status);
    pSVar2 = Globals::status;
    *(undefined8 *)(Globals::status + 0x160) = uVar21;
    *(undefined4 *)(pSVar2 + 0x170) = *(undefined4 *)pNVar10;
LAB_00188bee:
    uVar11 = NewsItem::clone(pNVar10);
    *(int *)(pAVar7 + 8) = *(int *)pAVar7 + 1;
    pvVar6 = realloc(*(void **)(pAVar7 + 4),(*(int *)pAVar7 + 1) * 4);
    *(void **)(pAVar7 + 4) = pvVar6;
    *(undefined4 *)((int)pvVar6 + *(int *)pAVar7 * 4) = uVar11;
    *(undefined4 *)pAVar7 = *(undefined4 *)(pAVar7 + 8);
    pNVar10[0x18] = (NewsItem)0x1;
    iVar12 = iVar12 + 1;
LAB_00188b2c:
    iVar16 = iVar16 + 1;
  } while( true );
}

// ===== NewsTicker::replaceTokens  @0x00188ea0  (4762 bytes)
/* NewsTicker::replaceTokens(AbyssEngine::String) */

void NewsTicker::replaceTokens(String *param_1,undefined4 param_2,String *param_3)

{
  Galaxy *pGVar1;
  Status *pSVar2;
  GameText *pGVar3;
  Globals *pGVar4;
  int iVar5;
  Station *pSVar6;
  undefined4 uVar7;
  void *pvVar8;
  SolarSystem *pSVar9;
  String *pSVar10;
  undefined4 *puVar11;
  int *piVar12;
  char *pcVar13;
  undefined4 extraout_r1;
  Item *this;
  uint uVar14;
  undefined8 uVar15;
  String aSStack_380 [8];
  AbyssEngine aAStack_378 [8];
  String aSStack_370 [8];
  String aSStack_368 [8];
  String aSStack_360 [8];
  String aSStack_358 [8];
  String aSStack_350 [8];
  String aSStack_348 [8];
  String aSStack_340 [8];
  undefined4 local_338 [2];
  String aSStack_330 [8];
  String aSStack_328 [8];
  String aSStack_320 [8];
  String aSStack_318 [8];
  String aSStack_310 [8];
  String aSStack_308 [8];
  String aSStack_300 [8];
  String aSStack_2f8 [8];
  String aSStack_2f0 [8];
  String aSStack_2e8 [8];
  String aSStack_2e0 [8];
  String aSStack_2d8 [8];
  String aSStack_2d0 [8];
  String aSStack_2c8 [8];
  String aSStack_2c0 [8];
  String aSStack_2b8 [8];
  String aSStack_2b0 [8];
  String aSStack_2a8 [8];
  String aSStack_2a0 [8];
  String aSStack_298 [8];
  String aSStack_290 [8];
  String aSStack_288 [8];
  String aSStack_280 [8];
  String aSStack_278 [8];
  String aSStack_270 [8];
  String aSStack_268 [8];
  String aSStack_260 [8];
  String aSStack_258 [8];
  String aSStack_250 [8];
  String aSStack_248 [8];
  String aSStack_240 [8];
  String aSStack_238 [8];
  String aSStack_230 [8];
  String aSStack_228 [8];
  String aSStack_220 [8];
  String aSStack_218 [8];
  int local_210 [2];
  AbyssEngine aAStack_208 [8];
  String aSStack_200 [8];
  String aSStack_1f8 [8];
  String aSStack_1f0 [8];
  String aSStack_1e8 [8];
  String aSStack_1e0 [8];
  String aSStack_1d8 [8];
  String aSStack_1d0 [8];
  String aSStack_1c8 [8];
  String aSStack_1c0 [8];
  String aSStack_1b8 [8];
  String aSStack_1b0 [8];
  String aSStack_1a8 [8];
  String aSStack_1a0 [8];
  String aSStack_198 [8];
  String aSStack_190 [8];
  String aSStack_188 [8];
  String aSStack_180 [8];
  String aSStack_178 [8];
  String aSStack_170 [8];
  String aSStack_168 [8];
  String aSStack_160 [8];
  String aSStack_158 [8];
  undefined4 local_150 [2];
  AbyssEngine aAStack_148 [8];
  String aSStack_140 [8];
  String aSStack_138 [8];
  String aSStack_130 [8];
  String aSStack_128 [8];
  String aSStack_120 [8];
  String aSStack_118 [8];
  String aSStack_110 [8];
  String aSStack_108 [8];
  String aSStack_100 [8];
  String aSStack_f8 [8];
  String aSStack_f0 [8];
  String aSStack_e8 [8];
  String aSStack_e0 [8];
  String aSStack_d8 [8];
  String aSStack_d0 [8];
  String aSStack_c8 [8];
  String aSStack_c0 [8];
  String aSStack_b8 [8];
  String aSStack_b0 [8];
  String aSStack_a8 [8];
  String aSStack_a0 [8];
  String aSStack_98 [8];
  String aSStack_90 [8];
  String aSStack_88 [8];
  String aSStack_80 [8];
  String aSStack_78 [8];
  String aSStack_70 [8];
  String aSStack_68 [8];
  String aSStack_60 [8];
  String aSStack_58 [8];
  String aSStack_50 [8];
  String aSStack_48 [8];
  String aSStack_40 [8];
  String aSStack_38 [8];
  String aSStack_30 [8];
  int local_28;
  
  pSVar2 = Globals::status;
  local_28 = __stack_chk_guard;
  AbyssEngine::String::String(aSStack_30,param_3,false);
  AbyssEngine::String::String(aSStack_38,"#PLANET_NAME",false);
  iVar5 = Status::stringHasToken(pSVar2,aSStack_30,aSStack_38);
  AbyssEngine::String::~String(aSStack_38);
  AbyssEngine::String::~String(aSStack_30);
  if (iVar5 == 1) {
    pSVar6 = (Station *)Globals::getRandomStation();
    pSVar2 = Globals::status;
    AbyssEngine::String::String(aSStack_48,param_3,false);
    Station::getName();
    AbyssEngine::String::String(aSStack_50,aSStack_58,false);
    uVar7 = AbyssEngine::String::String(aSStack_60,"#PLANET_NAME",false);
    Status::replaceHash(aSStack_40,pSVar2,aSStack_48,aSStack_50,uVar7);
    AbyssEngine::String::operator=(param_3,aSStack_40);
    AbyssEngine::String::~String(aSStack_40);
    AbyssEngine::String::~String(aSStack_60);
    AbyssEngine::String::~String(aSStack_50);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_48);
    pSVar2 = Globals::status;
    AbyssEngine::String::String(aSStack_68,param_3,false);
    AbyssEngine::String::String(aSStack_70,"#SYSTEM_NAME",false);
    iVar5 = Status::stringHasToken(pSVar2,aSStack_68,aSStack_70);
    AbyssEngine::String::~String(aSStack_70);
    AbyssEngine::String::~String(aSStack_68);
    pGVar1 = Globals::galaxy;
    if (iVar5 == 1) {
      iVar5 = Station::getSystem(pSVar6);
      Galaxy::getSystem(pGVar1,iVar5);
      pSVar2 = Globals::status;
      AbyssEngine::String::String(aSStack_78,param_3,false);
      SolarSystem::getName();
      AbyssEngine::String::String(aSStack_80,aSStack_58,false);
      uVar7 = AbyssEngine::String::String(aSStack_88,"#SYSTEM_NAME",false);
      Status::replaceHash(aSStack_40,pSVar2,aSStack_78,aSStack_80,uVar7);
      AbyssEngine::String::operator=(param_3,aSStack_40);
      AbyssEngine::String::~String(aSStack_40);
      AbyssEngine::String::~String(aSStack_88);
      AbyssEngine::String::~String(aSStack_80);
      AbyssEngine::String::~String(aSStack_58);
      AbyssEngine::String::~String(aSStack_78);
    }
    if (pSVar6 != (Station *)0x0) {
      pvVar8 = (void *)Station::~Station(pSVar6);
      operator_delete(pvVar8);
    }
  }
  pSVar2 = Globals::status;
  AbyssEngine::String::String(aSStack_90,param_3,false);
  AbyssEngine::String::String(aSStack_98,"#SYSTEM_NAME",false);
  iVar5 = Status::stringHasToken(pSVar2,aSStack_90,aSStack_98);
  AbyssEngine::String::~String(aSStack_98);
  AbyssEngine::String::~String(aSStack_90);
  pSVar2 = Globals::status;
  if (iVar5 == 1) {
    AbyssEngine::String::String(aSStack_a0,param_3,false);
    AbyssEngine::String::String(aSStack_a8,"#DRINK_NAME",false);
    iVar5 = Status::stringHasToken(pSVar2,aSStack_a0,aSStack_a8);
    AbyssEngine::String::~String(aSStack_a8);
    AbyssEngine::String::~String(aSStack_a0);
    if (iVar5 == 1) {
      pSVar9 = (SolarSystem *)Status::getSystem(Globals::status);
      pSVar2 = Globals::status;
      AbyssEngine::String::String(aSStack_b0,param_3,false);
      pGVar3 = Globals::gameText;
      iVar5 = SolarSystem::getIndex(pSVar9);
      pSVar10 = (String *)GameText::getText(pGVar3,iVar5 + 0x57e);
      AbyssEngine::String::String(aSStack_b8,pSVar10,false);
      uVar7 = AbyssEngine::String::String(aSStack_c0,"#DRINK_NAME",false);
      Status::replaceHash(aSStack_40,pSVar2,aSStack_b0,aSStack_b8,uVar7);
      AbyssEngine::String::operator=(param_3,aSStack_40);
      AbyssEngine::String::~String(aSStack_40);
      AbyssEngine::String::~String(aSStack_c0);
      AbyssEngine::String::~String(aSStack_b8);
      AbyssEngine::String::~String(aSStack_b0);
    }
    else {
      Globals::getRandomSystemForDrinks();
    }
    pSVar2 = Globals::status;
    AbyssEngine::String::String(aSStack_c8,param_3,false);
    SolarSystem::getName();
    AbyssEngine::String::String(aSStack_d0,aSStack_58,false);
    uVar7 = AbyssEngine::String::String(aSStack_d8,"#SYSTEM_NAME",false);
    Status::replaceHash(aSStack_40,pSVar2,aSStack_c8,aSStack_d0,uVar7);
    AbyssEngine::String::operator=(param_3,aSStack_40);
    AbyssEngine::String::~String(aSStack_40);
    AbyssEngine::String::~String(aSStack_d8);
    AbyssEngine::String::~String(aSStack_d0);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_c8);
  }
  pSVar2 = Globals::status;
  AbyssEngine::String::String(aSStack_e0,param_3,false);
  AbyssEngine::String::String(aSStack_e8,"#CHILD_NAME",false);
  iVar5 = Status::stringHasToken(pSVar2,aSStack_e0,aSStack_e8);
  AbyssEngine::String::~String(aSStack_e8);
  AbyssEngine::String::~String(aSStack_e0);
  pGVar4 = Globals::globals;
  if (iVar5 == 1) {
    pSVar9 = (SolarSystem *)Status::getSystem(Globals::status);
    SolarSystem::getRace(pSVar9);
    Globals::getRandomName((int)aSStack_40,SUB41(pGVar4,0));
    AbyssEngine::String::String(aSStack_58," ",false);
    iVar5 = AbyssEngine::String::IndexOf(aSStack_40,aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    if (-1 < iVar5) {
      AbyssEngine::String::SubString((uint)aSStack_58,(uint)aSStack_40);
      AbyssEngine::String::operator=(aSStack_40,aSStack_58);
      AbyssEngine::String::~String(aSStack_58);
    }
    pSVar2 = Globals::status;
    AbyssEngine::String::String(aSStack_f0,param_3,false);
    AbyssEngine::String::String(aSStack_f8,aSStack_40,false);
    uVar7 = AbyssEngine::String::String(aSStack_100,"#CHILD_NAME",false);
    Status::replaceHash(aSStack_58,pSVar2,aSStack_f0,aSStack_f8,uVar7);
    AbyssEngine::String::operator=(param_3,aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_100);
    AbyssEngine::String::~String(aSStack_f8);
    AbyssEngine::String::~String(aSStack_f0);
    AbyssEngine::String::~String(aSStack_40);
  }
  pSVar2 = Globals::status;
  AbyssEngine::String::String(aSStack_108,param_3,false);
  AbyssEngine::String::String(aSStack_110,"#SHIP_NAME",false);
  iVar5 = Status::stringHasToken(pSVar2,aSStack_108,aSStack_110);
  AbyssEngine::String::~String(aSStack_110);
  AbyssEngine::String::~String(aSStack_108);
  if (iVar5 == 1) {
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
    pSVar2 = Globals::status;
    AbyssEngine::String::String(aSStack_118,param_3,false);
    pGVar3 = Globals::gameText;
    iVar5 = Globals::getRandomEnemyFighter(Globals::globals,iVar5);
    pSVar10 = (String *)GameText::getText(pGVar3,iVar5 + 0x391);
    AbyssEngine::String::String(aSStack_120,pSVar10,false);
    uVar7 = AbyssEngine::String::String(aSStack_128,"#SHIP_NAME",false);
    Status::replaceHash(aSStack_40,pSVar2,aSStack_118,aSStack_120,uVar7);
    AbyssEngine::String::operator=(param_3,aSStack_40);
    AbyssEngine::String::~String(aSStack_40);
    AbyssEngine::String::~String(aSStack_128);
    AbyssEngine::String::~String(aSStack_120);
    AbyssEngine::String::~String(aSStack_118);
  }
  pSVar2 = Globals::status;
  AbyssEngine::String::String(aSStack_130,param_3,false);
  AbyssEngine::String::String(aSStack_138,"#PLATFORM_NUMBER",false);
  iVar5 = Status::stringHasToken(pSVar2,aSStack_130,aSStack_138);
  AbyssEngine::String::~String(aSStack_138);
  AbyssEngine::String::~String(aSStack_130);
  if (iVar5 == 1) {
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,6);
    if (iVar5 == 0) {
      pcVar13 = "A";
    }
    else if (iVar5 == 1) {
      pcVar13 = "B";
    }
    else if (iVar5 == 2) {
      pcVar13 = "C";
    }
    else if (iVar5 == 3) {
      pcVar13 = "D";
    }
    else {
      pcVar13 = "E";
      if (iVar5 != 4) {
        pcVar13 = "F";
      }
    }
    AbyssEngine::String::String(aSStack_40,pcVar13,false);
    pSVar2 = Globals::status;
    AbyssEngine::String::String(aSStack_140,param_3,false);
    uVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,10);
    local_150[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar7,local_150));
    AbyssEngine::operator+(aAStack_148,aSStack_40,(String *)local_150);
    uVar7 = AbyssEngine::String::String(aSStack_158,"#PLATFORM_NUMBER",false);
    Status::replaceHash(aSStack_58,pSVar2,aSStack_140,aAStack_148,uVar7);
    AbyssEngine::String::operator=(param_3,aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_158);
    AbyssEngine::String::~String((String *)aAStack_148);
    AbyssEngine::String::~String((String *)local_150);
    AbyssEngine::String::~String(aSStack_140);
    AbyssEngine::String::~String(aSStack_40);
  }
  pSVar2 = Globals::status;
  AbyssEngine::String::String(aSStack_160,param_3,false);
  AbyssEngine::String::String(aSStack_168,"#CATASTROPHE",false);
  iVar5 = Status::stringHasToken(pSVar2,aSStack_160,aSStack_168);
  AbyssEngine::String::~String(aSStack_168);
  AbyssEngine::String::~String(aSStack_160);
  pSVar2 = Globals::status;
  if (iVar5 == 1) {
    AbyssEngine::String::String(aSStack_170,param_3,false);
    pGVar3 = Globals::gameText;
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,5);
    pSVar10 = (String *)GameText::getText(pGVar3,iVar5 + 0xca5);
    AbyssEngine::String::String(aSStack_178,pSVar10,false);
    uVar7 = AbyssEngine::String::String(aSStack_180,"#CATASTROPHE",false);
    Status::replaceHash(aSStack_40,pSVar2,aSStack_170,aSStack_178,uVar7);
    AbyssEngine::String::operator=(param_3,aSStack_40);
    AbyssEngine::String::~String(aSStack_40);
    AbyssEngine::String::~String(aSStack_180);
    AbyssEngine::String::~String(aSStack_178);
    AbyssEngine::String::~String(aSStack_170);
  }
  pSVar2 = Globals::status;
  AbyssEngine::String::String(aSStack_188,param_3,false);
  AbyssEngine::String::String(aSStack_190,"#VICTIMS",false);
  iVar5 = Status::stringHasToken(pSVar2,aSStack_188,aSStack_190);
  AbyssEngine::String::~String(aSStack_190);
  AbyssEngine::String::~String(aSStack_188);
  pSVar2 = Globals::status;
  if (iVar5 == 1) {
    AbyssEngine::String::String(aSStack_198,param_3,false);
    AbyssEngine::AERandom::nextInt(Globals::rnd,99000);
    Layout::formatNumber((int)aSStack_58);
    AbyssEngine::String::String(aSStack_1a0,aSStack_58,false);
    uVar7 = AbyssEngine::String::String(aSStack_1a8,"#VICTIMS",false);
    Status::replaceHash(aSStack_40,pSVar2,aSStack_198,aSStack_1a0,uVar7);
    AbyssEngine::String::operator=(param_3,aSStack_40);
    AbyssEngine::String::~String(aSStack_40);
    AbyssEngine::String::~String(aSStack_1a8);
    AbyssEngine::String::~String(aSStack_1a0);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_198);
  }
  pSVar2 = Globals::status;
  AbyssEngine::String::String(aSStack_1b0,param_3,false);
  AbyssEngine::String::String(aSStack_1b8,"#BERGER_LASER",false);
  iVar5 = Status::stringHasToken(pSVar2,aSStack_1b0,aSStack_1b8);
  AbyssEngine::String::~String(aSStack_1b8);
  AbyssEngine::String::~String(aSStack_1b0);
  pGVar3 = Globals::gameText;
  if (iVar5 == 1) {
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
    pSVar10 = (String *)GameText::getText(pGVar3,iVar5 + 0x4ff);
    AbyssEngine::String::String(aSStack_40,pSVar10,false);
    pSVar2 = Globals::status;
    AbyssEngine::String::String(aSStack_1c0,param_3,false);
    AbyssEngine::String::String(aSStack_1c8,aSStack_40,false);
    uVar7 = AbyssEngine::String::String(aSStack_1d0,"#BERGER_LASER",false);
    Status::replaceHash(aSStack_58,pSVar2,aSStack_1c0,aSStack_1c8,uVar7);
    AbyssEngine::String::operator=(param_3,aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_1d0);
    AbyssEngine::String::~String(aSStack_1c8);
    AbyssEngine::String::~String(aSStack_1c0);
    AbyssEngine::String::~String(aSStack_40);
  }
  pSVar2 = Globals::status;
  AbyssEngine::String::String(aSStack_1d8,param_3,false);
  AbyssEngine::String::String(aSStack_1e0,"#VOSSK_SHIP_OR_ITEM",false);
  iVar5 = Status::stringHasToken(pSVar2,aSStack_1d8,aSStack_1e0);
  AbyssEngine::String::~String(aSStack_1e0);
  AbyssEngine::String::~String(aSStack_1d8);
  if (iVar5 == 1) {
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
    AbyssEngine::String::String(aSStack_40);
    AbyssEngine::String::String(aSStack_58);
    if (iVar5 < 0x28) {
      pSVar10 = (String *)GameText::getText(Globals::gameText,0x39a);
      AbyssEngine::String::operator=(aSStack_40,pSVar10);
    }
    else {
      piVar12 = operator_new(0xc);
      puVar11 = operator_new__(4);
      piVar12[1] = (int)puVar11;
      piVar12[2] = 1;
      iVar5 = 0;
      *puVar11 = 0;
      *piVar12 = 0;
      if (*Globals::items != 0) {
        uVar14 = 0;
        do {
          this = *(Item **)(Globals::items[1] + uVar14 * 4);
          iVar5 = Item::getAttribute(this,0x3c);
          if (((iVar5 == 1) && (iVar5 = Item::getIngredients(this), iVar5 == 0)) &&
             (iVar5 = Item::getType(this), iVar5 != 4)) {
            piVar12[2] = *piVar12 + 1;
            pvVar8 = realloc((void *)piVar12[1],(*piVar12 + 1) * 4);
            piVar12[1] = (int)pvVar8;
            *(Item **)((int)pvVar8 + *piVar12 * 4) = this;
            *piVar12 = piVar12[2];
          }
          uVar14 = uVar14 + 1;
        } while (uVar14 < *Globals::items);
        iVar5 = *piVar12;
      }
      iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,iVar5);
      iVar5 = Item::getIndex(*(Item **)(piVar12[1] + iVar5 * 4));
      pSVar10 = (String *)GameText::getText(Globals::gameText,iVar5 + 0x4fa);
      AbyssEngine::String::operator=(aSStack_40,pSVar10);
      if ((void *)piVar12[1] != (void *)0x0) {
        operator_delete__((void *)piVar12[1]);
      }
      operator_delete(piVar12);
    }
    uVar15 = Status::getPlayingTime(Globals::status);
    __aeabi_ldivmod((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),1000000,0);
    Layout::formatNumber((int)local_150);
    AbyssEngine::String::operator=(aSStack_58,(String *)local_150);
    AbyssEngine::String::~String((String *)local_150);
    pSVar2 = Globals::status;
    AbyssEngine::String::String(aSStack_1e8,param_3,false);
    AbyssEngine::String::String(aSStack_1f0,aSStack_40,false);
    uVar7 = AbyssEngine::String::String(aSStack_1f8,"#VOSSK_SHIP_OR_ITEM",false);
    Status::replaceHash(local_150,pSVar2,aSStack_1e8,aSStack_1f0,uVar7);
    AbyssEngine::String::operator=(param_3,(String *)local_150);
    AbyssEngine::String::~String((String *)local_150);
    AbyssEngine::String::~String(aSStack_1f8);
    AbyssEngine::String::~String(aSStack_1f0);
    AbyssEngine::String::~String(aSStack_1e8);
    pSVar2 = Globals::status;
    AbyssEngine::String::String(aSStack_200,param_3,false);
    AbyssEngine::String::String(aSStack_218,aSStack_58,false);
    AbyssEngine::String::String(aSStack_220," ",false);
    AbyssEngine::operator+((AbyssEngine *)local_210,aSStack_218,aSStack_220);
    pSVar10 = (String *)GameText::getText(Globals::gameText,0xcaa);
    AbyssEngine::operator+(aAStack_208,(String *)local_210,pSVar10);
    uVar7 = AbyssEngine::String::String(aSStack_228,"#VOSSK_REVENUE",false);
    Status::replaceHash(local_150,pSVar2,aSStack_200,aAStack_208,uVar7);
    AbyssEngine::String::operator=(param_3,(String *)local_150);
    AbyssEngine::String::~String((String *)local_150);
    AbyssEngine::String::~String(aSStack_228);
    AbyssEngine::String::~String((String *)aAStack_208);
    AbyssEngine::String::~String((String *)local_210);
    AbyssEngine::String::~String(aSStack_220);
    AbyssEngine::String::~String(aSStack_218);
    AbyssEngine::String::~String(aSStack_200);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_40);
  }
  pSVar2 = Globals::status;
  AbyssEngine::String::String(aSStack_230,param_3,false);
  AbyssEngine::String::String(aSStack_238,"#PROFESSION",false);
  iVar5 = Status::stringHasToken(pSVar2,aSStack_230,aSStack_238);
  AbyssEngine::String::~String(aSStack_238);
  AbyssEngine::String::~String(aSStack_230);
  pSVar2 = Globals::status;
  if (iVar5 == 1) {
    AbyssEngine::String::String(aSStack_240,param_3,false);
    pGVar3 = Globals::gameText;
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
    pSVar10 = (String *)GameText::getText(pGVar3,iVar5 + 0xcab);
    AbyssEngine::String::String(aSStack_248,pSVar10,false);
    uVar7 = AbyssEngine::String::String(aSStack_250,"#PROFESSION",false);
    Status::replaceHash(aSStack_40,pSVar2,aSStack_240,aSStack_248,uVar7);
    AbyssEngine::String::operator=(param_3,aSStack_40);
    AbyssEngine::String::~String(aSStack_40);
    AbyssEngine::String::~String(aSStack_250);
    AbyssEngine::String::~String(aSStack_248);
    AbyssEngine::String::~String(aSStack_240);
    AbyssEngine::AERandom::nextInt(Globals::rnd,8);
    Globals::getRandomName((int)aSStack_40,SUB41(Globals::globals,0));
    pSVar2 = Globals::status;
    AbyssEngine::String::String(aSStack_258,param_3,false);
    AbyssEngine::String::String(aSStack_260,aSStack_40,false);
    uVar7 = AbyssEngine::String::String(aSStack_268,"#NAME",false);
    Status::replaceHash(aSStack_58,pSVar2,aSStack_258,aSStack_260,uVar7);
    AbyssEngine::String::operator=(param_3,aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_268);
    AbyssEngine::String::~String(aSStack_260);
    AbyssEngine::String::~String(aSStack_258);
    pSVar2 = Globals::status;
    AbyssEngine::String::String(aSStack_270,param_3,false);
    pGVar3 = Globals::gameText;
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
    pSVar10 = (String *)GameText::getText(pGVar3,iVar5 + 0xcaf);
    AbyssEngine::String::String(aSStack_278,pSVar10,false);
    uVar7 = AbyssEngine::String::String(aSStack_280,"#ACTIVITY",false);
    Status::replaceHash(aSStack_58,pSVar2,aSStack_270,aSStack_278,uVar7);
    AbyssEngine::String::operator=(param_3,aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_280);
    AbyssEngine::String::~String(aSStack_278);
    AbyssEngine::String::~String(aSStack_270);
    AbyssEngine::String::~String(aSStack_40);
  }
  pSVar2 = Globals::status;
  AbyssEngine::String::String(aSStack_288,param_3,false);
  AbyssEngine::String::String(aSStack_290,"#RACE_NAME",false);
  iVar5 = Status::stringHasToken(pSVar2,aSStack_288,aSStack_290);
  AbyssEngine::String::~String(aSStack_290);
  AbyssEngine::String::~String(aSStack_288);
  pSVar2 = Globals::status;
  if (iVar5 == 1) {
    AbyssEngine::String::String(aSStack_298,param_3,false);
    pGVar3 = Globals::gameText;
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
    pSVar10 = (String *)GameText::getText(pGVar3,iVar5 + 0x196);
    AbyssEngine::String::String(aSStack_2a0,pSVar10,false);
    uVar7 = AbyssEngine::String::String(aSStack_2a8,"#RACE_NAME",false);
    Status::replaceHash(aSStack_40,pSVar2,aSStack_298,aSStack_2a0,uVar7);
    AbyssEngine::String::operator=(param_3,aSStack_40);
    AbyssEngine::String::~String(aSStack_40);
    AbyssEngine::String::~String(aSStack_2a8);
    AbyssEngine::String::~String(aSStack_2a0);
    AbyssEngine::String::~String(aSStack_298);
    AbyssEngine::AERandom::nextInt(Globals::rnd,8);
    Globals::getRandomName((int)aSStack_40,SUB41(Globals::globals,0));
    pSVar2 = Globals::status;
    AbyssEngine::String::String(aSStack_2b0,param_3,false);
    AbyssEngine::String::String(aSStack_2b8,aSStack_40,false);
    uVar7 = AbyssEngine::String::String(aSStack_2c0,"#NAME",false);
    Status::replaceHash(aSStack_58,pSVar2,aSStack_2b0,aSStack_2b8,uVar7);
    AbyssEngine::String::operator=(param_3,aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_2c0);
    AbyssEngine::String::~String(aSStack_2b8);
    AbyssEngine::String::~String(aSStack_2b0);
    pSVar2 = Globals::status;
    AbyssEngine::String::String(aSStack_2c8,param_3,false);
    pGVar3 = Globals::gameText;
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,5);
    pSVar10 = (String *)GameText::getText(pGVar3,iVar5 + 0xcb3);
    AbyssEngine::String::String(aSStack_2d0,pSVar10,false);
    uVar7 = AbyssEngine::String::String(aSStack_2d8,"#CRIME",false);
    Status::replaceHash(aSStack_58,pSVar2,aSStack_2c8,aSStack_2d0,uVar7);
    AbyssEngine::String::operator=(param_3,aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_2d8);
    AbyssEngine::String::~String(aSStack_2d0);
    AbyssEngine::String::~String(aSStack_2c8);
    AbyssEngine::String::~String(aSStack_40);
  }
  pSVar2 = Globals::status;
  AbyssEngine::String::String(aSStack_2e0,param_3,false);
  AbyssEngine::String::String(aSStack_2e8,"#NIVELIAN_PLANET",false);
  iVar5 = Status::stringHasToken(pSVar2,aSStack_2e0,aSStack_2e8);
  AbyssEngine::String::~String(aSStack_2e8);
  AbyssEngine::String::~String(aSStack_2e0);
  if (iVar5 == 1) {
    piVar12 = (int *)Galaxy::getSystems(Globals::galaxy);
    uVar14 = 0xffffffff;
    while (0x7fffffff < uVar14) {
      iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,*piVar12);
      pSVar9 = *(SolarSystem **)(piVar12[1] + iVar5 * 4);
      iVar5 = SolarSystem::getRace(pSVar9);
      if (iVar5 == 2) {
        uVar14 = SolarSystem::getIndex(pSVar9);
      }
    }
    piVar12 = (int *)SolarSystem::getStations(*(SolarSystem **)(piVar12[1] + uVar14 * 4));
    pGVar1 = Globals::galaxy;
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,*piVar12);
    pSVar6 = (Station *)Galaxy::getStation(pGVar1,*(int *)(piVar12[1] + iVar5 * 4));
    pSVar2 = Globals::status;
    AbyssEngine::String::String(aSStack_2f0,param_3,false);
    Station::getName();
    AbyssEngine::String::String(aSStack_2f8,aSStack_58,false);
    uVar7 = AbyssEngine::String::String(aSStack_300,"#NIVELIAN_PLANET",false);
    Status::replaceHash(aSStack_40,pSVar2,aSStack_2f0,aSStack_2f8,uVar7);
    AbyssEngine::String::operator=(param_3,aSStack_40);
    AbyssEngine::String::~String(aSStack_40);
    AbyssEngine::String::~String(aSStack_300);
    AbyssEngine::String::~String(aSStack_2f8);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_2f0);
    AbyssEngine::AERandom::nextInt(Globals::rnd,990000);
    Layout::formatNumber((int)aSStack_40);
    pSVar2 = Globals::status;
    AbyssEngine::String::String(aSStack_308,param_3,false);
    AbyssEngine::String::String(aSStack_310,aSStack_40,false);
    uVar7 = AbyssEngine::String::String(aSStack_318,"#DEMONSTRATORS",false);
    Status::replaceHash(aSStack_58,pSVar2,aSStack_308,aSStack_310,uVar7);
    AbyssEngine::String::operator=(param_3,aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_318);
    AbyssEngine::String::~String(aSStack_310);
    AbyssEngine::String::~String(aSStack_308);
    if (pSVar6 != (Station *)0x0) {
      pvVar8 = (void *)Station::~Station(pSVar6);
      operator_delete(pvVar8);
    }
    AbyssEngine::String::~String(aSStack_40);
  }
  pSVar2 = Globals::status;
  AbyssEngine::String::String(aSStack_320,param_3,false);
  AbyssEngine::String::String(aSStack_328,"#POLL_PERCENTAGE",false);
  iVar5 = Status::stringHasToken(pSVar2,aSStack_320,aSStack_328);
  AbyssEngine::String::~String(aSStack_328);
  AbyssEngine::String::~String(aSStack_320);
  pSVar2 = Globals::status;
  if (iVar5 == 1) {
    AbyssEngine::String::String(aSStack_330,param_3,false);
    AbyssEngine::AERandom::nextInt(Globals::rnd,0x50);
    local_338[0] = 0;
    AbyssEngine::String::Set(CONCAT44(extraout_r1,local_338));
    uVar7 = AbyssEngine::String::String(aSStack_340,"#POLL_PERCENTAGE",false);
    Status::replaceHash(aSStack_40,pSVar2,aSStack_330,local_338,uVar7);
    AbyssEngine::String::operator=(param_3,aSStack_40);
    AbyssEngine::String::~String(aSStack_40);
    AbyssEngine::String::~String(aSStack_340);
    AbyssEngine::String::~String((String *)local_338);
    AbyssEngine::String::~String(aSStack_330);
    pSVar2 = Globals::status;
    AbyssEngine::String::String(aSStack_348,param_3,false);
    pGVar3 = Globals::gameText;
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,6);
    pSVar10 = (String *)GameText::getText(pGVar3,iVar5 + 0xcb8);
    AbyssEngine::String::String(aSStack_350,pSVar10,false);
    uVar7 = AbyssEngine::String::String(aSStack_358,"#POLL_TOPIC",false);
    Status::replaceHash(aSStack_40,pSVar2,aSStack_348,aSStack_350,uVar7);
    AbyssEngine::String::operator=(param_3,aSStack_40);
    AbyssEngine::String::~String(aSStack_40);
    AbyssEngine::String::~String(aSStack_358);
    AbyssEngine::String::~String(aSStack_350);
    AbyssEngine::String::~String(aSStack_348);
  }
  pSVar2 = Globals::status;
  AbyssEngine::String::String(aSStack_360,param_3,false);
  AbyssEngine::String::String(aSStack_368,"#CASUALTIES",false);
  iVar5 = Status::stringHasToken(pSVar2,aSStack_360,aSStack_368);
  AbyssEngine::String::~String(aSStack_368);
  AbyssEngine::String::~String(aSStack_360);
  pSVar2 = Globals::status;
  if (iVar5 == 1) {
    AbyssEngine::String::String(aSStack_370,param_3,false);
    local_210[0] = 2;
    uVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x30);
    local_150[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar7,local_150));
    AbyssEngine::String::String(aSStack_58,(String *)local_150,false);
    AbyssEngine::operator+(aAStack_378,local_210,aSStack_58);
    uVar7 = AbyssEngine::String::String(aSStack_380,"#CASUALTIES",false);
    Status::replaceHash(aSStack_40,pSVar2,aSStack_370,aAStack_378,uVar7);
    AbyssEngine::String::operator=(param_3,aSStack_40);
    AbyssEngine::String::~String(aSStack_40);
    AbyssEngine::String::~String(aSStack_380);
    AbyssEngine::String::~String((String *)aAStack_378);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String((String *)local_150);
    AbyssEngine::String::~String(aSStack_370);
  }
  AbyssEngine::String::String(param_1,param_3,false);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== NewsTicker::~NewsTicker  @0x0018a8aa  (18 bytes)
/* NewsTicker::~NewsTicker() */

NewsTicker * __thiscall NewsTicker::~NewsTicker(NewsTicker *this)

{
  AbyssEngine::String::~String((String *)(this + 0x14));
  return this;
}

// ===== NewsTicker::update  @0x0018a8bc  (138 bytes)
/* NewsTicker::update(int) */

void __thiscall NewsTicker::update(NewsTicker *this,int param_1)

{
  uint uVar1;
  byte bVar2;
  short sVar3;
  uint in_fpscr;
  float fVar4;
  undefined4 uVar5;
  float fVar6;
  
  if (this[0x24] == (NewsTicker)0x0) {
    fVar4 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    fVar4 = (fVar4 / 1000.0) * 50.0;
    sVar3 = GameText::getLanguage();
    if (sVar3 == 9) {
      fVar4 = fVar4 + *(float *)this;
      *(float *)this = fVar4;
      fVar6 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0xc),(byte)(in_fpscr >> 0x16) & 3);
      uVar1 = in_fpscr & 0xfffffff | (uint)(fVar4 < fVar6) << 0x1f | (uint)(fVar4 == fVar6) << 0x1e;
      bVar2 = (byte)(uVar1 >> 0x18);
      if (!(bool)(bVar2 >> 6 & 1) && (bool)(bVar2 >> 7) == (NAN(fVar4) || NAN(fVar6))) {
        uVar5 = VectorSignedToFloat(-*(int *)(this + 0x10),(byte)(uVar1 >> 0x16) & 3);
        *(undefined4 *)this = uVar5;
      }
    }
    else {
      fVar4 = *(float *)this - fVar4;
      *(float *)this = fVar4;
      fVar6 = (float)VectorSignedToFloat(-*(int *)(this + 0x10),(byte)(in_fpscr >> 0x16) & 3);
      if ((int)((uint)(fVar4 < fVar6) << 0x1f) < 0) {
        *(undefined4 *)this = 0;
      }
    }
  }
  return;
}

// ===== NewsTicker::draw  @0x0018a950  (330 bytes)
/* NewsTicker::draw() */

void __thiscall NewsTicker::draw(NewsTicker *this)

{
  uint uVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  uint in_fpscr;
  float fVar5;
  float fVar6;
  float fVar7;
  
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  AbyssEngine::PaintCanvas::FillRectangle
            (Globals::Canvas,*(int *)(this + 4),*(int *)(this + 8) + -2,*(int *)(this + 0xc),
             ((2 - *(int *)(this + 8)) + Globals::h) - *(int *)(Globals::layout + 0x10));
  AbyssEngine::PaintCanvas::EnableClip
            (Globals::Canvas,*(int *)(this + 4),*(int *)(this + 8),*(int *)(this + 0xc),Globals::h);
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  fVar5 = (float)VectorSignedToFloat(*(undefined4 *)(this + 4),(byte)(in_fpscr >> 0x16) & 3);
  AbyssEngine::PaintCanvas::DrawString
            (Globals::Canvas,Globals::font,this + 0x14,(int)(fVar5 + *(float *)this),
             *(int *)(this + 8),false);
  sVar3 = GameText::getLanguage();
  iVar4 = *(int *)(this + 0x10);
  fVar5 = *(float *)this;
  if (sVar3 == 9) {
    fVar6 = (float)VectorSignedToFloat(iVar4,(byte)(in_fpscr >> 0x16) & 3);
    uVar1 = in_fpscr & 0xfffffff | (uint)(fVar5 < fVar6) << 0x1f | (uint)(fVar5 == fVar6) << 0x1e;
    bVar2 = (byte)(uVar1 >> 0x18);
    if ((bool)(bVar2 >> 6 & 1) || (bool)(bVar2 >> 7) != (NAN(fVar5) || NAN(fVar6)))
    goto LAB_0018aa86;
    fVar6 = (float)VectorSignedToFloat(*(undefined4 *)(this + 4),(byte)(uVar1 >> 0x16) & 3);
    fVar5 = fVar5 + fVar6;
  }
  else {
    fVar6 = (float)VectorSignedToFloat(iVar4 - *(int *)(this + 0xc),(byte)(in_fpscr >> 0x16) & 3);
    if (fVar6 <= fVar5) goto LAB_0018aa86;
    fVar6 = (float)VectorSignedToFloat(*(undefined4 *)(this + 4),
                                       (byte)((in_fpscr & 0xfffffff) >> 0x16) & 3);
    fVar7 = (float)VectorSignedToFloat(iVar4,(byte)((in_fpscr & 0xfffffff) >> 0x16) & 3);
    fVar5 = fVar7 + fVar5 + fVar6;
  }
  AbyssEngine::PaintCanvas::DrawString
            (Globals::Canvas,Globals::font,this + 0x14,(int)fVar5,*(int *)(this + 8),false);
LAB_0018aa86:
  AbyssEngine::PaintCanvas::DisableClip();
  return;
}

// ===== NewsTicker::getHeight  @0x0018aabc  (28 bytes)
/* NewsTicker::getHeight() */

int __thiscall NewsTicker::getHeight(NewsTicker *this)

{
  return ((Globals::h + 2) - *(int *)(Globals::layout + 0x10)) - *(int *)(this + 8);
}

// ===== NewsTicker::OnTouchBegin  @0x0018aae0  (80 bytes)
/* NewsTicker::OnTouchBegin(int, int) */

NewsTicker __thiscall NewsTicker::OnTouchBegin(NewsTicker *this,int param_1,int param_2)

{
  if ((((*(int *)(this + 4) <= param_1) && (param_1 <= *(int *)(this + 0xc) + *(int *)(this + 4)))
      && (*(int *)(this + 8) <= param_2)) &&
     (param_2 <= (Globals::h + 2) - *(int *)(Globals::layout + 0x10))) {
    this[0x24] = (NewsTicker)0x1;
    *(int *)(this + 0x28) = param_1;
  }
  return this[0x24];
}

// ===== NewsTicker::OnTouchMove  @0x0018ab38  (70 bytes)
/* NewsTicker::OnTouchMove(int, int) */

bool NewsTicker::OnTouchMove(int param_1,int param_2)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  float fVar3;
  
  if (*(char *)(param_1 + 0x24) != '\0') {
    fVar1 = (float)VectorSignedToFloat(*(int *)(param_1 + 0x28) - param_2,
                                       (byte)(in_fpscr >> 0x16) & 3);
    fVar3 = *(float *)param_1;
    *(float *)param_1 = fVar3 - fVar1;
    fVar2 = (float)VectorSignedToFloat(Globals::w,(byte)(in_fpscr >> 0x16) & 3);
    if (fVar2 < fVar3 - fVar1) {
      *(float *)param_1 = fVar2;
    }
    *(int *)(param_1 + 0x28) = param_2;
  }
  return *(char *)(param_1 + 0x24) != '\0';
}

// ===== NewsTicker::OnTouchEnd  @0x0018ab84  (18 bytes)
/* NewsTicker::OnTouchEnd(int, int) */

bool NewsTicker::OnTouchEnd(int param_1,int param_2)

{
  bool bVar1;
  
  bVar1 = *(char *)(param_1 + 0x24) != '\0';
  if (bVar1) {
    *(undefined1 *)(param_1 + 0x24) = 0;
  }
  return bVar1;
}

