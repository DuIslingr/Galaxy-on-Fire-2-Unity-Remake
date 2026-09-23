// Class: DialogueWindow
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== DialogueWindow::DialogueWindow  @0x001946de  (62 bytes)
/* DialogueWindow::DialogueWindow(Mission*, Level*, int) */

DialogueWindow * __thiscall
DialogueWindow::DialogueWindow(DialogueWindow *this,Mission *param_1,Level *param_2,int param_3)

{
  AbyssEngine::String::String((String *)(this + 0x28));
  AbyssEngine::String::String((String *)(this + 0x30));
  init(this);
  *(Level **)(this + 0x50) = param_2;
  set(this,param_1,param_3,-1);
  return this;
}

// ===== DialogueWindow::init  @0x00194734  (586 bytes)
/* DialogueWindow::init() */

void __thiscall DialogueWindow::init(DialogueWindow *this)

{
  void *pvVar1;
  void *pvVar2;
  ScrollTouchWindow *this_00;
  ChoiceWindow *this_01;
  TouchButton *pTVar3;
  String *pSVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  pvVar1 = operator_new__(0x288);
  *(void **)(this + 0x54) = pvVar1;
  pvVar2 = operator_new__(0x288);
  iVar5 = 0;
  iVar9 = 0;
  iVar8 = 0;
  *(void **)(this + 0x58) = pvVar2;
  do {
    iVar6 = (&DAT_00259ed0)[iVar5];
    iVar7 = (&DAT_0025a158)[iVar5];
    *(int *)((int)pvVar1 + iVar5 * 4) = iVar8;
    iVar8 = iVar8 + iVar6;
    *(int *)((int)pvVar2 + iVar5 * 4) = iVar9;
    iVar5 = iVar5 + 1;
    iVar9 = iVar9 + iVar7;
  } while (iVar5 != 0xa2);
  AbyssEngine::String::String(aSStack_30,"",false);
  AbyssEngine::String::operator=((String *)(this + 0x30),aSStack_30);
  AbyssEngine::String::~String(aSStack_30);
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x5c) = 0xffffffff;
  *(undefined4 *)(this + 0x60) = 0;
  this[0x68] = (DialogueWindow)0x0;
  iVar5 = Globals::layout;
  iVar6 = *(int *)(Globals::layout + 0x54);
  *(int *)(this + 0x1c) = iVar6;
  iVar9 = *(int *)(iVar5 + 0x58);
  *(int *)(this + 0x20) = iVar9;
  iVar10 = Globals::w / 2 - iVar6 / 2;
  *(int *)(this + 0x14) = iVar10;
  iVar7 = Globals::h / 2 - iVar9 / 2;
  *(int *)(this + 0x18) = iVar7;
  this_00 = operator_new(0x20);
  iVar8 = *(int *)(iVar5 + 0x4c);
  ScrollTouchWindow::ScrollTouchWindow
            (this_00,iVar10 + iVar8 * 2 + *(int *)(iVar5 + 0x2d4),*(int *)(iVar5 + 8) + iVar7,
             iVar6 - (*(int *)(iVar5 + 0x2d4) + iVar8 * 2),
             (iVar9 - (*(int *)(iVar5 + 8) + iVar8 * 2)) - *(int *)(iVar5 + 0x30),false);
  *(ScrollTouchWindow **)(this + 0x38) = this_00;
  this_01 = operator_new(0x54);
  ChoiceWindow::ChoiceWindow(this_01);
  *(ChoiceWindow **)(this + 0x48) = this_01;
  pTVar3 = operator_new(0xc0);
  pSVar4 = (String *)GameText::getText(Globals::gameText,0xb3);
  TouchButton::TouchButton
            (pTVar3,pSVar4,5,*(int *)(this + 0x14) + *(int *)(Globals::layout + 0x4c),
             (*(int *)(this + 0x18) - *(int *)(Globals::layout + 0x4c)) + *(int *)(this + 0x20),
             *(int *)(Globals::layout + 0x50),'!','\x04');
  *(TouchButton **)this = pTVar3;
  pTVar3 = operator_new(0xc0);
  pSVar4 = (String *)GameText::getText(Globals::gameText,0xb4);
  TouchButton::TouchButton
            (pTVar3,pSVar4,6,
             (*(int *)(this + 0x1c) + *(int *)(this + 0x14)) - *(int *)(Globals::layout + 0x4c),
             (*(int *)(this + 0x18) - *(int *)(Globals::layout + 0x4c)) + *(int *)(this + 0x20),
             *(int *)(Globals::layout + 0x50),'\"','\x04');
  *(TouchButton **)(this + 4) = pTVar3;
  pTVar3 = operator_new(0xc0);
  pSVar4 = (String *)GameText::getText(Globals::gameText,0x18b);
  TouchButton::TouchButton
            (pTVar3,pSVar4,0,*(int *)(this + 0x14) + *(int *)(this + 0x1c) / 2,
             (*(int *)(this + 0x18) + *(int *)(this + 0x20)) - *(int *)(Globals::layout + 0x4c),
             *(int *)(this + 0x1c) + *(int *)(Globals::layout + 0x4c) * -4 +
             *(int *)(Globals::layout + 0x50) * -2,'$','\x04');
  *(TouchButton **)(this + 8) = pTVar3;
  this[0x4c] = (DialogueWindow)0x0;
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== DialogueWindow::set  @0x001949dc  (116 bytes)
/* DialogueWindow::set(Mission*, int, int) */

void __thiscall DialogueWindow::set(DialogueWindow *this,Mission *param_1,int param_2,int param_3)

{
  Agent *this_00;
  int iVar1;
  
  *(Mission **)(this + 0x44) = param_1;
  *(int *)(this + 0x3c) = param_2;
  if (param_2 == 1) {
    Mission::getAgent(param_1);
    Mission::setWon(param_1,true);
  }
  else if (param_2 == 2) {
    this_00 = (Agent *)Mission::getAgent(param_1);
    if ((this_00 != (Agent *)0x0) && (iVar1 = Agent::isGenericAgent(this_00), iVar1 == 0)) {
      Agent::setOfferAccepted(this_00,false);
    }
    Mission::setFailed(param_1,true);
  }
  *(undefined4 *)(this + 0x40) = 0;
  if (param_3 == -1) {
    param_3 = Status::getCurrentCampaignMission(Globals::status);
  }
  *(int *)(this + 0x10) = param_3;
  loadContent(this);
  return;
}

// ===== DialogueWindow::DialogueWindow  @0x00194a54  (40 bytes)
/* DialogueWindow::DialogueWindow() */

DialogueWindow * __thiscall DialogueWindow::DialogueWindow(DialogueWindow *this)

{
  AbyssEngine::String::String((String *)(this + 0x28));
  AbyssEngine::String::String((String *)(this + 0x30));
  init(this);
  return this;
}

// ===== DialogueWindow::DialogueWindow  @0x00194a94  (288 bytes)
/* DialogueWindow::DialogueWindow(AbyssEngine::String*, AbyssEngine::String*, int*) */

void __thiscall
DialogueWindow::DialogueWindow(DialogueWindow *this,String *param_1,String *param_2,int *param_3)

{
  undefined4 uVar1;
  void *pvVar2;
  TouchButton *this_00;
  String *pSVar3;
  ScrollTouchWindow *pSVar4;
  String aSStack_38 [8];
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  AbyssEngine::String::String((String *)(this + 0x28));
  AbyssEngine::String::String((String *)(this + 0x30));
  init(this);
  pSVar4 = *(ScrollTouchWindow **)(this + 0x38);
  AbyssEngine::String::String(aSStack_30,"",false);
  AbyssEngine::String::String(aSStack_38,param_1,false);
  ScrollTouchWindow::setText(pSVar4,aSStack_30,aSStack_38);
  AbyssEngine::String::~String(aSStack_38);
  AbyssEngine::String::~String(aSStack_30);
  TouchButton::setVisible(*(TouchButton **)(this + 8),false);
  TouchButton::setVisible(*(TouchButton **)this,false);
  uVar1 = ImageFactory::loadChar(Globals::imageFactory,param_3);
  *(undefined4 *)(this + 0xc) = uVar1;
  if (*(TouchButton **)(this + 4) != (TouchButton *)0x0) {
    pvVar2 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 4));
    operator_delete(pvVar2);
  }
  *(undefined4 *)(this + 4) = 0;
  this_00 = operator_new(0xc0);
  pSVar3 = (String *)GameText::getText(Globals::gameText,0x20c);
  TouchButton::TouchButton
            (this_00,pSVar3,0,*(int *)(this + 0x14) + *(int *)(this + 0x1c) / 2,
             (*(int *)(this + 0x20) + *(int *)(this + 0x18)) - *(int *)(Globals::layout + 0x4c),
             *(int *)(this + 0x1c) + *(int *)(Globals::layout + 0x4c) * -4 +
             *(int *)(Globals::layout + 0x50) * -2,'$','\x04');
  *(TouchButton **)(this + 4) = this_00;
  AbyssEngine::String::operator=((String *)(this + 0x30),param_2);
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x5c) = 0xffffffff;
  *(undefined4 *)(this + 100) = 0;
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== DialogueWindow::~DialogueWindow  @0x00194c04  (138 bytes)
/* DialogueWindow::~DialogueWindow() */

DialogueWindow * __thiscall DialogueWindow::~DialogueWindow(DialogueWindow *this)

{
  void *pvVar1;
  
  if (*(Array **)(this + 0xc) != (Array *)0x0) {
    ArrayReleaseClasses<ImagePart*>(*(Array **)(this + 0xc));
    pvVar1 = *(void **)(this + 0xc);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0xc) = 0;
  if (*(void **)(this + 0x54) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x54));
  }
  *(undefined4 *)(this + 0x54) = 0;
  if (*(void **)(this + 0x58) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x58));
  }
  *(undefined4 *)(this + 0x58) = 0;
  if (*(ScrollTouchWindow **)(this + 0x38) != (ScrollTouchWindow *)0x0) {
    pvVar1 = (void *)ScrollTouchWindow::~ScrollTouchWindow(*(ScrollTouchWindow **)(this + 0x38));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x38) = 0;
  if (*(TouchButton **)this != (TouchButton *)0x0) {
    pvVar1 = (void *)TouchButton::~TouchButton(*(TouchButton **)this);
    operator_delete(pvVar1);
  }
  *(undefined4 *)this = 0;
  if (*(TouchButton **)(this + 4) != (TouchButton *)0x0) {
    pvVar1 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 4));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 4) = 0;
  if (*(TouchButton **)(this + 8) != (TouchButton *)0x0) {
    pvVar1 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 8));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 8) = 0;
  AbyssEngine::String::~String((String *)(this + 0x30));
  AbyssEngine::String::~String((String *)(this + 0x28));
  return this;
}

// ===== DialogueWindow::hasBriefingDialogue  @0x00194c90  (26 bytes)
/* DialogueWindow::hasBriefingDialogue(int) */

bool DialogueWindow::hasBriefingDialogue(int param_1)

{
  if (0xa1 < param_1) {
    return false;
  }
  return 0 < (int)(&DAT_00259ed0)[param_1];
}

// ===== DialogueWindow::hasSuccessDialogue  @0x00194cb0  (26 bytes)
/* DialogueWindow::hasSuccessDialogue(int) */

bool DialogueWindow::hasSuccessDialogue(int param_1)

{
  if (0xa1 < param_1) {
    return false;
  }
  return 0 < (int)(&DAT_0025a158)[param_1];
}

// ===== DialogueWindow::loadContent  @0x00194cd0  (3064 bytes)
/* DialogueWindow::loadContent() */

void __thiscall DialogueWindow::loadContent(DialogueWindow *this)

{
  undefined1 *puVar1;
  Status *pSVar2;
  Globals *this_00;
  short sVar3;
  String *pSVar4;
  int iVar5;
  Standing *this_01;
  String *pSVar6;
  DialogueWindow *pDVar7;
  undefined4 uVar8;
  Agent *pAVar9;
  int iVar10;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  int iVar11;
  undefined4 *puVar12;
  undefined *puVar13;
  TouchButton *pTVar14;
  void *pvVar15;
  uint uVar16;
  ScrollTouchWindow *pSVar17;
  String *pSVar18;
  DialogueWindow DVar19;
  float fVar20;
  float extraout_s0;
  String aSStack_118 [8];
  String aSStack_110 [8];
  String aSStack_108 [8];
  undefined4 local_100 [2];
  String aSStack_f8 [8];
  undefined4 local_f0 [2];
  String aSStack_e8 [8];
  String aSStack_e0 [8];
  String aSStack_d8 [8];
  String aSStack_d0 [8];
  String aSStack_c8 [8];
  String aSStack_c0 [8];
  undefined4 local_b8 [2];
  String aSStack_b0 [8];
  undefined4 local_a8 [2];
  String aSStack_a0 [8];
  String aSStack_98 [8];
  String aSStack_90 [8];
  String aSStack_88 [8];
  String aSStack_80 [8];
  String aSStack_78 [8];
  String aSStack_70 [8];
  String aSStack_68 [8];
  String aSStack_60 [8];
  undefined4 local_58 [2];
  AbyssEngine aAStack_50 [8];
  AbyssEngine aAStack_48 [8];
  AbyssEngine aAStack_40 [8];
  AbyssEngine aAStack_38 [8];
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  pTVar14 = *(TouchButton **)(this + 4);
  pSVar4 = (String *)GameText::getText(Globals::gameText,0xb4);
  TouchButton::replaceTextKeepSize(pTVar14,pSVar4);
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 100) = 0;
  fVar20 = (float)FModSound::stop(Globals::sound,*(int *)(this + 0x5c));
  *(undefined4 *)(this + 0x5c) = 0xffffffff;
  TouchButton::setPressProgress(*(TouchButton **)(this + 4),fVar20);
  if (*(Array **)(this + 0xc) != (Array *)0x0) {
    ArrayReleaseClasses<ImagePart*>(*(Array **)(this + 0xc));
    pvVar15 = *(void **)(this + 0xc);
    if (pvVar15 != (void *)0x0) {
      if (*(void **)((int)pvVar15 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar15 + 4));
      }
      operator_delete(pvVar15);
    }
  }
  *(undefined4 *)(this + 0xc) = 0;
  iVar5 = Mission::isCampaignMission(*(Mission **)(this + 0x44));
  iVar10 = *(int *)(this + 0x3c);
  if (iVar5 == 0) {
    iVar5 = 0;
    if (iVar10 == 2) {
      iVar5 = *(int *)(this + 0x10);
    }
    if (iVar10 != 2 || iVar5 != 0x2a) {
      DVar19 = (DialogueWindow)(((byte)this[0x40] & 1) != 0);
      if ((bool)DVar19) {
        *(undefined **)(this + 0x24) = &DAT_0026d3bc;
        pSVar4 = (String *)GameText::getText(Globals::gameText,0x63d);
        AbyssEngine::String::operator=((String *)(this + 0x30),pSVar4);
      }
      else {
        uVar8 = Mission::getClientImage(*(Mission **)(this + 0x44));
        *(undefined4 *)(this + 0x24) = uVar8;
        Mission::getClientName();
        AbyssEngine::String::operator=((String *)(this + 0x30),aSStack_30);
        AbyssEngine::String::~String(aSStack_30);
      }
      this[0x68] = DVar19;
      if (*(int *)(this + 0x3c) == 1) {
        iVar5 = Mission::getAgent(*(Mission **)(this + 0x44));
        if (iVar5 == 0) {
          iVar5 = 0;
        }
        else {
          pAVar9 = (Agent *)Mission::getAgent(*(Mission **)(this + 0x44));
          iVar5 = Agent::isStoryAgent(pAVar9);
        }
        iVar10 = Mission::getType(*(Mission **)(this + 0x44));
        if ((iVar10 == 5) || (iVar10 = Mission::getType(*(Mission **)(this + 0x44)), iVar10 == 3)) {
          pSVar4 = (String *)GameText::getText(Globals::gameText,0x185);
          pSVar18 = (String *)(this + 0x28);
          AbyssEngine::String::operator=(pSVar18,pSVar4);
          pSVar2 = Globals::status;
          AbyssEngine::String::String(aSStack_68,pSVar18,false);
          Mission::getTargetStationName();
          uVar8 = AbyssEngine::String::String(aSStack_78,"#S",false);
          Status::replaceHash(aSStack_30,pSVar2,aSStack_68,aSStack_70,uVar8);
          AbyssEngine::String::operator=(pSVar18,aSStack_30);
          AbyssEngine::String::~String(aSStack_30);
          AbyssEngine::String::~String(aSStack_78);
          AbyssEngine::String::~String(aSStack_70);
          AbyssEngine::String::~String(aSStack_68);
          iVar10 = 0x185;
        }
        else {
          iVar10 = Mission::getType(*(Mission **)(this + 0x44));
          if (iVar10 == 0xc) {
            pSVar4 = (String *)GameText::getText(Globals::gameText,0x172);
            if (iVar5 != 1) {
              AbyssEngine::String::String((String *)aAStack_38,"",false);
            }
            else {
              AbyssEngine::String::String((String *)aAStack_40,"\n\n",false);
              pSVar2 = Globals::status;
              pSVar6 = (String *)GameText::getText(Globals::gameText,0x185);
              AbyssEngine::String::String(aSStack_80,pSVar6,false);
              Mission::getAgent(*(Mission **)(this + 0x44));
              Agent::getStationName();
              uVar8 = AbyssEngine::String::String(aSStack_90,"#S",false);
              Status::replaceHash(aAStack_48,pSVar2,aSStack_80,aSStack_88,uVar8);
              AbyssEngine::operator+(aAStack_38,aAStack_40,aAStack_48);
            }
            AbyssEngine::operator+((AbyssEngine *)aSStack_30,pSVar4,aAStack_38);
            pSVar18 = (String *)(this + 0x28);
            AbyssEngine::String::operator=(pSVar18,aSStack_30);
            AbyssEngine::String::~String(aSStack_30);
            AbyssEngine::String::~String((String *)aAStack_38);
            if (iVar5 == 1) {
              AbyssEngine::String::~String((String *)aAStack_48);
              AbyssEngine::String::~String(aSStack_90);
              AbyssEngine::String::~String(aSStack_88);
              AbyssEngine::String::~String(aSStack_80);
              AbyssEngine::String::~String((String *)aAStack_40);
            }
            pSVar2 = Globals::status;
            AbyssEngine::String::String(aSStack_a0,pSVar18,false);
            local_a8[0] = 0;
            AbyssEngine::String::Set(CONCAT44(extraout_r1_02,local_a8));
            uVar8 = AbyssEngine::String::String(aSStack_b0,"#Q1",false);
            Status::replaceHash(aSStack_98,pSVar2,aSStack_a0,local_a8,uVar8);
            local_b8[0] = 0;
            AbyssEngine::String::Set(CONCAT44(extraout_r1_03,local_b8));
            uVar8 = AbyssEngine::String::String(aSStack_c0,"#Q2",false);
            Status::replaceHash(aSStack_30,pSVar2,aSStack_98,local_b8,uVar8);
            AbyssEngine::String::operator=(pSVar18,aSStack_30);
            AbyssEngine::String::~String(aSStack_30);
            AbyssEngine::String::~String(aSStack_c0);
            AbyssEngine::String::~String((String *)local_b8);
            AbyssEngine::String::~String(aSStack_98);
            AbyssEngine::String::~String(aSStack_b0);
            AbyssEngine::String::~String((String *)local_a8);
            AbyssEngine::String::~String(aSStack_a0);
            iVar10 = 0x172;
          }
          else {
            iVar10 = Mission::getType(*(Mission **)(this + 0x44));
            if (iVar10 == 0xb7) {
              iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,5);
              iVar10 = *(int *)(&DAT_0025c6c4 + iVar5 * 4);
              pSVar4 = (String *)GameText::getText(Globals::gameText,iVar10);
              pSVar18 = (String *)(this + 0x28);
              AbyssEngine::String::operator=(pSVar18,pSVar4);
              AbyssEngine::String::String((String *)aAStack_48,"\n\n",false);
              pSVar4 = (String *)GameText::getText(Globals::gameText,0xb0);
              AbyssEngine::operator+(aAStack_40,aAStack_48,pSVar4);
              AbyssEngine::String::String((String *)aAStack_50,": ",false);
              AbyssEngine::operator+(aAStack_38,aAStack_40,aAStack_50);
              local_58[0] = 0;
              AbyssEngine::String::Set(CONCAT44(extraout_r1_01,local_58));
              AbyssEngine::operator+((AbyssEngine *)aSStack_30,aAStack_38,(String *)local_58);
              AbyssEngine::String::~String((String *)local_58);
              AbyssEngine::String::~String((String *)aAStack_38);
              AbyssEngine::String::~String((String *)aAStack_50);
              AbyssEngine::String::~String((String *)aAStack_40);
              AbyssEngine::String::~String((String *)aAStack_48);
              AbyssEngine::operator+(aAStack_38,pSVar18,aSStack_30);
              AbyssEngine::String::operator=(pSVar18,aAStack_38);
              AbyssEngine::String::~String((String *)aAStack_38);
              puVar1 = &stack0x000000cc;
            }
            else {
              sVar3 = GameText::getLanguage();
              if ((sVar3 == 1) &&
                 (iVar10 = Mission::getAgent(*(Mission **)(this + 0x44)), iVar10 != 0)) {
                iVar10 = *(int *)(this + 0x3c);
                pDVar7 = (DialogueWindow *)Mission::getAgent(*(Mission **)(this + 0x44));
                iVar10 = pickGermanGenericTextBecauseWeSaved100EurosWithThat
                                   (pDVar7,iVar10,(Agent *)pDVar7);
              }
              else {
                iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,5);
                iVar10 = *(int *)(&DAT_0025c6c4 + iVar10 * 4);
              }
              pSVar4 = (String *)GameText::getText(Globals::gameText,iVar10);
              pSVar18 = (String *)(this + 0x28);
              AbyssEngine::String::operator=(pSVar18,pSVar4);
              if (iVar5 == 1) {
                AbyssEngine::String::String(aSStack_30,"\n\n",false);
                pSVar2 = Globals::status;
                pSVar4 = (String *)GameText::getText(Globals::gameText,0x185);
                AbyssEngine::String::String(aSStack_c8,pSVar4,false);
                Mission::getAgent(*(Mission **)(this + 0x44));
                Agent::getStationName();
                uVar8 = AbyssEngine::String::String(aSStack_d8,"#S",false);
                Status::replaceHash(aAStack_40,pSVar2,aSStack_c8,aSStack_d0,uVar8);
                AbyssEngine::operator+(aAStack_38,aSStack_30,aAStack_40);
                AbyssEngine::String::~String((String *)aAStack_40);
                AbyssEngine::String::~String(aSStack_d8);
                AbyssEngine::String::~String(aSStack_d0);
                AbyssEngine::String::~String(aSStack_c8);
              }
              else {
                AbyssEngine::String::String(aSStack_30,"\n\n",false);
                pSVar4 = (String *)GameText::getText(Globals::gameText,0xd8);
                AbyssEngine::operator+(aAStack_38,aSStack_30,pSVar4);
              }
              AbyssEngine::String::~String(aSStack_30);
              AbyssEngine::operator+((AbyssEngine *)aSStack_30,pSVar18,aAStack_38);
              AbyssEngine::String::operator=(pSVar18,aSStack_30);
              AbyssEngine::String::~String(aSStack_30);
              puVar1 = &stack0x000000c4;
            }
            AbyssEngine::String::~String((String *)(puVar1 + -0xfc));
          }
        }
        this_01 = (Standing *)Status::getStanding(Globals::status);
        iVar5 = Mission::getClientRace(*(Mission **)(this + 0x44));
        Standing::applyMissionCompleted(this_01,iVar5);
        iVar5 = Mission::getTargetStation(*(Mission **)(this + 0x44));
        if (iVar5 != 0x6c) goto LAB_00195558;
        iVar10 = 0x1ca;
        pSVar4 = (String *)GameText::getText(Globals::gameText,0x1ca);
LAB_00195550:
        pSVar18 = (String *)(this + 0x28);
LAB_00195554:
        AbyssEngine::String::operator=(pSVar18,pSVar4);
      }
      else {
        if (*(int *)(this + 0x3c) == 0) {
          iVar5 = Mission::getType(*(Mission **)(this + 0x44));
          if (iVar5 == 0xc) {
            iVar10 = 0x174;
LAB_00195544:
            pSVar4 = (String *)GameText::getText(Globals::gameText,iVar10);
            goto LAB_00195550;
          }
          iVar5 = Mission::getType(*(Mission **)(this + 0x44));
          if (iVar5 == 7) {
            iVar10 = 0x17a;
            goto LAB_00195544;
          }
          if ((*(Mission **)(this + 0x44) == (Mission *)0x0) ||
             (iVar5 = Mission::getTargetStation(*(Mission **)(this + 0x44)), iVar5 != 0x6c)) {
            sVar3 = GameText::getLanguage();
            if ((sVar3 == 1) && (iVar5 = Mission::getAgent(*(Mission **)(this + 0x44)), iVar5 != 0))
            {
              iVar5 = *(int *)(this + 0x3c);
              pDVar7 = (DialogueWindow *)Mission::getAgent(*(Mission **)(this + 0x44));
              iVar10 = pickGermanGenericTextBecauseWeSaved100EurosWithThat
                                 (pDVar7,iVar5,(Agent *)pDVar7);
            }
            else {
              iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,5);
              iVar10 = *(int *)(&DAT_0025c6b0 + iVar5 * 4);
            }
            goto LAB_00195544;
          }
          uVar16 = *(int *)(this + 0x40) << 1 | 1;
          if (*(int *)(Globals::status + 0x114) == 2) {
            puVar13 = &DAT_0025c5f0;
            iVar10 = *(int *)(&DAT_0025c5f0 + uVar16 * 4);
            pSVar4 = (String *)GameText::getText(Globals::gameText,iVar10);
            AbyssEngine::String::operator=((String *)(this + 0x28),pSVar4);
            iVar5 = *(int *)(this + 0x40);
          }
          else {
            puVar13 = &DAT_0025c680;
            iVar10 = *(int *)(&DAT_0025c680 + uVar16 * 4);
            pSVar4 = (String *)GameText::getText(Globals::gameText,iVar10);
            AbyssEngine::String::operator=((String *)(this + 0x28),pSVar4);
            iVar5 = *(int *)(this + 0x40);
          }
          iVar5 = *(int *)(puVar13 + iVar5 * 8);
          *(undefined **)(this + 0x24) = (&PTR_DAT_002647ec)[iVar5];
          pSVar4 = (String *)GameText::getText(Globals::gameText,iVar5 + 0x63d);
          pSVar18 = (String *)(this + 0x30);
          goto LAB_00195554;
        }
        iVar5 = Mission::getType(*(Mission **)(this + 0x44));
        pSVar2 = Globals::status;
        if (iVar5 == 0xc) {
          pSVar4 = (String *)GameText::getText(Globals::gameText,0x173);
          AbyssEngine::String::String(aSStack_e8,pSVar4,false);
          local_f0[0] = 0;
          AbyssEngine::String::Set(CONCAT44(extraout_r1,local_f0));
          uVar8 = AbyssEngine::String::String(aSStack_f8,"#Q1",false);
          Status::replaceHash(aSStack_e0,pSVar2,aSStack_e8,local_f0,uVar8);
          local_100[0] = 0;
          AbyssEngine::String::Set(CONCAT44(extraout_r1_00,local_100));
          uVar8 = AbyssEngine::String::String(aSStack_108,"#Q2",false);
          Status::replaceHash(aSStack_30,pSVar2,aSStack_e0,local_100,uVar8);
          AbyssEngine::String::operator=((String *)(this + 0x28),aSStack_30);
          AbyssEngine::String::~String(aSStack_30);
          AbyssEngine::String::~String(aSStack_108);
          AbyssEngine::String::~String((String *)local_100);
          AbyssEngine::String::~String(aSStack_e0);
          AbyssEngine::String::~String(aSStack_f8);
          AbyssEngine::String::~String((String *)local_f0);
          AbyssEngine::String::~String(aSStack_e8);
          iVar5 = -1;
          iVar10 = 0x173;
          goto LAB_0019555c;
        }
        sVar3 = GameText::getLanguage();
        if ((sVar3 == 1) && (iVar5 = Mission::getAgent(*(Mission **)(this + 0x44)), iVar5 != 0)) {
          iVar5 = *(int *)(this + 0x3c);
          pDVar7 = (DialogueWindow *)Mission::getAgent(*(Mission **)(this + 0x44));
          iVar10 = pickGermanGenericTextBecauseWeSaved100EurosWithThat(pDVar7,iVar5,(Agent *)pDVar7)
          ;
        }
        else {
          iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,5);
          iVar10 = *(int *)(&DAT_0025c6d8 + iVar5 * 4);
        }
        pSVar4 = (String *)GameText::getText(Globals::gameText,iVar10);
        AbyssEngine::String::String((String *)aAStack_40,"\n\n",false);
        AbyssEngine::operator+(aAStack_38,pSVar4,(String *)aAStack_40);
        pSVar4 = (String *)GameText::getText(Globals::gameText,0x188);
        AbyssEngine::operator+((AbyssEngine *)aSStack_30,aAStack_38,pSVar4);
        AbyssEngine::String::operator=((String *)(this + 0x28),aSStack_30);
        AbyssEngine::String::~String(aSStack_30);
        AbyssEngine::String::~String((String *)aAStack_38);
        AbyssEngine::String::~String((String *)aAStack_40);
      }
LAB_00195558:
      iVar5 = -1;
      goto LAB_0019555c;
    }
LAB_00194d9a:
    iVar5 = 0x10;
  }
  else {
    if (iVar10 == 1) {
      iVar5 = *(int *)(this + 0x10);
      iVar10 = *(int *)(this + 0x40);
      puVar13 = &DAT_0025a5c0;
      iVar11 = *(int *)(this + 0x58);
    }
    else {
      if (iVar10 != 0) goto LAB_00194d9a;
      iVar5 = *(int *)(this + 0x10);
      iVar10 = *(int *)(this + 0x40);
      puVar13 = &DAT_0025a3e0;
      iVar11 = *(int *)(this + 0x54);
    }
    iVar5 = *(int *)(puVar13 + (*(int *)(iVar11 + iVar5 * 4) + iVar10 * 2) * 4);
  }
  *(undefined **)(this + 0x24) = (&PTR_DAT_002647ec)[iVar5];
  pSVar4 = (String *)GameText::getText(Globals::gameText,iVar5 + 0x63d);
  AbyssEngine::String::operator=((String *)(this + 0x30),pSVar4);
  this[0x68] = (DialogueWindow)(iVar5 == 0);
  if (*(int *)(this + 0x3c) == 1) {
    iVar10 = *(int *)(&DAT_0025a5c0 +
                     (*(int *)(*(int *)(this + 0x58) + *(int *)(this + 0x10) * 4) +
                     (*(int *)(this + 0x40) << 1 | 1U)) * 4);
    pSVar4 = (String *)GameText::getText(Globals::gameText,iVar10);
    pSVar18 = (String *)(this + 0x28);
    AbyssEngine::String::operator=(pSVar18,pSVar4);
    iVar11 = 0x6b6;
    if (iVar10 != 0x6b6) {
      iVar11 = 0x6c2;
    }
    if (iVar10 == 0x6b6 || iVar10 == iVar11) {
      Globals::replaceKeyBindingTokens(aSStack_30);
      AbyssEngine::String::operator=(pSVar18,aSStack_30);
      AbyssEngine::String::~String(aSStack_30);
    }
    else {
      if (iVar10 == 0x729) {
        fVar20 = (float)FModSound::stop(Globals::sound,*(int *)Globals::sound);
        fVar20 = (float)FModSound::play(Globals::sound,0x88,(Vector *)0x0,(Vector *)0x0,fVar20);
        FModSound::play(Globals::sound,0xa2,(Vector *)0x0,(Vector *)0x0,fVar20);
        iVar10 = 0x729;
        goto LAB_0019555c;
      }
      uVar16 = GameText::getLanguage();
      if (iVar10 == 0xade) {
        uVar16 = uVar16 & 0xffff;
      }
      if (iVar10 == 0xade && uVar16 == 1) {
        *(undefined **)(this + 0x24) = &DAT_0026d3bc;
        pSVar4 = (String *)GameText::getText(Globals::gameText,0x63d);
        AbyssEngine::String::operator=((String *)(this + 0x30),pSVar4);
        this[0x68] = (DialogueWindow)(iVar5 == 0);
      }
    }
    if ((iVar10 - 0x891U < 2) &&
       (iVar11 = Mission::getStatusValue(*(Mission **)(this + 0x44)), iVar11 == 1)) {
      iVar10 = iVar10 + -2;
      pSVar4 = (String *)GameText::getText(Globals::gameText,iVar10);
      AbyssEngine::String::operator=(pSVar18,pSVar4);
    }
  }
  else if (*(int *)(this + 0x3c) == 0) {
    uVar16 = (*(int *)(this + 0x40) << 1 | 1U) +
             *(int *)(*(int *)(this + 0x54) + *(int *)(this + 0x10) * 4);
    iVar10 = *(int *)(&DAT_0025a3e0 + uVar16 * 4);
    pSVar4 = (String *)GameText::getText(Globals::gameText,iVar10);
    AbyssEngine::String::operator=((String *)(this + 0x28),pSVar4);
    if (((uVar16 < 0x18) && ((1 << (uVar16 & 0xff) & 0xa0200aU) != 0)) || (uVar16 == 0x23)) {
      Globals::replaceKeyBindingTokens(aSStack_30);
      AbyssEngine::String::operator=((String *)(this + 0x28),aSStack_30);
      AbyssEngine::String::~String(aSStack_30);
    }
  }
  else {
    if ((*(int *)(this + 0x10) - 0x26U < 4) && (*(int *)(this + 0x10) - 0x26U != 1)) {
      pSVar4 = (String *)GameText::getText(Globals::gameText,0x20f);
      AbyssEngine::String::String(aSStack_30,pSVar4,false);
    }
    else {
      AbyssEngine::String::String(aSStack_30,"",false);
    }
    pSVar4 = (String *)GameText::getText(Globals::gameText,0x188);
    AbyssEngine::String::String((String *)local_58,"\n",false);
    AbyssEngine::operator+(aAStack_50,pSVar4,(String *)local_58);
    AbyssEngine::operator+(aAStack_48,aAStack_50,aSStack_30);
    AbyssEngine::String::String(aSStack_60,"\n\n",false);
    AbyssEngine::operator+(aAStack_40,aAStack_48,aSStack_60);
    pSVar4 = (String *)GameText::getText(Globals::gameText,0x13f);
    AbyssEngine::operator+(aAStack_38,aAStack_40,pSVar4);
    AbyssEngine::String::operator=((String *)(this + 0x28),aAStack_38);
    AbyssEngine::String::~String((String *)aAStack_38);
    AbyssEngine::String::~String((String *)aAStack_40);
    AbyssEngine::String::~String(aSStack_60);
    AbyssEngine::String::~String((String *)aAStack_48);
    AbyssEngine::String::~String((String *)aAStack_50);
    AbyssEngine::String::~String((String *)local_58);
    AbyssEngine::String::~String(aSStack_30);
    iVar10 = -1;
  }
LAB_0019555c:
  pSVar17 = *(ScrollTouchWindow **)(this + 0x38);
  AbyssEngine::String::String(aSStack_110,"",false);
  AbyssEngine::String::String(aSStack_118,this + 0x28,false);
  puVar12 = &Globals::fontAlien;
  if (iVar5 != 0x38) {
    puVar12 = &Globals::font;
  }
  if (iVar5 == 0x13) {
    puVar12 = &Globals::fontAlien;
  }
  ScrollTouchWindow::setText(pSVar17,aSStack_110,aSStack_118,*puVar12);
  AbyssEngine::String::~String(aSStack_118);
  AbyssEngine::String::~String(aSStack_110);
  TouchButton::setVisible(*(TouchButton **)this,*(int *)(this + 0x40) != 0);
  pTVar14 = *(TouchButton **)(this + 8);
  iVar5 = length(this);
  TouchButton::setVisible(pTVar14,1 < iVar5);
  uVar8 = ImageFactory::loadChar(Globals::imageFactory,*(int **)(this + 0x24));
  *(undefined4 *)(this + 0xc) = uVar8;
  iVar11 = *(int *)(this + 0x40);
  iVar5 = length(this);
  if (iVar11 == iVar5 + -1) {
    pTVar14 = *(TouchButton **)(this + 4);
    pSVar4 = (String *)GameText::getText(Globals::gameText,0xb5);
    TouchButton::replaceTextKeepSize(pTVar14,pSVar4);
  }
  this_00 = Globals::globals;
  if (*(Mission **)(this + 0x44) == (Mission *)0x0) {
    pAVar9 = (Agent *)0x0;
  }
  else {
    pAVar9 = (Agent *)Mission::getAgent(*(Mission **)(this + 0x44));
  }
  iVar5 = Globals::getDialogueSoundId(this_00,iVar10,pAVar9);
  *(int *)(this + 0x5c) = iVar5;
  if (-1 < iVar5) {
    FModSound::play(Globals::sound,iVar5,(Vector *)0x0,(Vector *)0x0,extraout_s0);
    uVar8 = FModSound::getEventPauseLength(Globals::sound,*(int *)(this + 0x5c));
    *(undefined4 *)(this + 100) = uVar8;
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== DialogueWindow::getMode  @0x00195bec  (4 bytes)
/* DialogueWindow::getMode() */

undefined4 __thiscall DialogueWindow::getMode(DialogueWindow *this)

{
  return *(undefined4 *)(this + 0x3c);
}

// ===== DialogueWindow::update  @0x00195bf0  (112 bytes)
/* DialogueWindow::update(int) */

void __thiscall DialogueWindow::update(DialogueWindow *this,int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(this + 0x38) != 0) {
    ScrollTouchWindow::update(*(int *)(this + 0x38));
  }
  if (this[0x4c] != (DialogueWindow)0x0) {
    ChoiceWindow::update(*(int *)(this + 0x48));
  }
  if ((Globals::options[0xe] != '\0') && (*(int *)(this + 0x5c) != -1)) {
    FModSound::getPlayingProgress(Globals::sound,*(int *)(this + 0x5c));
    iVar1 = FModSound::isPlaying(Globals::sound,*(int *)(this + 0x5c));
    if ((iVar1 == 0) && (iVar2 = *(int *)(this + 0x40), iVar1 = length(this), iVar2 != iVar1 + -1))
    {
      iVar1 = *(int *)(this + 0x60);
      if (*(int *)(this + 100) <= iVar1) {
        nextPage(this);
        iVar1 = *(int *)(this + 0x60);
      }
      *(int *)(this + 0x60) = iVar1 + param_1;
    }
  }
  return;
}

// ===== DialogueWindow::isLastPage  @0x00195c68  (22 bytes)
/* DialogueWindow::isLastPage() */

bool __thiscall DialogueWindow::isLastPage(DialogueWindow *this)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(this + 0x40);
  iVar1 = length(this);
  return iVar2 == iVar1 + -1;
}

// ===== DialogueWindow::nextPage  @0x00195c7e  (38 bytes)
/* DialogueWindow::nextPage() */

undefined4 __thiscall DialogueWindow::nextPage(DialogueWindow *this)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(this + 0x40);
  iVar1 = length(this);
  if (iVar2 < iVar1 + -1) {
    *(int *)(this + 0x40) = *(int *)(this + 0x40) + 1;
    loadContent(this);
    return 1;
  }
  return 0;
}

// ===== DialogueWindow::length  @0x00195ca4  (92 bytes)
/* DialogueWindow::length() */

int __thiscall DialogueWindow::length(DialogueWindow *this)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((*(Mission **)(this + 0x44) != (Mission *)0x0) &&
     (iVar1 = Mission::isCampaignMission(*(Mission **)(this + 0x44)), iVar1 == 1)) {
    if (*(int *)(this + 0x3c) == 1) {
      puVar2 = &DAT_0025a158;
    }
    else {
      if (*(int *)(this + 0x3c) != 0) {
        return 1;
      }
      puVar2 = &DAT_00259ed0;
    }
    return (int)puVar2[*(int *)(this + 0x10)] / 2;
  }
  if (((*(int *)(this + 0x3c) == 0) && (*(Mission **)(this + 0x44) != (Mission *)0x0)) &&
     (iVar1 = Mission::getTargetStation(*(Mission **)(this + 0x44)), iVar1 == 0x6c)) {
    iVar1 = 6;
    if (*(int *)(Globals::status + 0x114) == 2) {
      iVar1 = 0x12;
    }
    return iVar1;
  }
  return 1;
}

// ===== DialogueWindow::isFirstPage  @0x00195d0c  (12 bytes)
/* DialogueWindow::isFirstPage() */

bool __thiscall DialogueWindow::isFirstPage(DialogueWindow *this)

{
  return *(int *)(this + 0x40) == 0;
}

// ===== DialogueWindow::hasLevel  @0x00195d18  (10 bytes)
/* DialogueWindow::hasLevel() */

bool __thiscall DialogueWindow::hasLevel(DialogueWindow *this)

{
  return *(int *)(this + 0x50) != 0;
}

// ===== DialogueWindow::setLevel  @0x00195d22  (4 bytes)
/* DialogueWindow::setLevel(Level*) */

void __thiscall DialogueWindow::setLevel(DialogueWindow *this,Level *param_1)

{
  *(Level **)(this + 0x50) = param_1;
  return;
}

// ===== DialogueWindow::previousPage  @0x00195d26  (26 bytes)
/* DialogueWindow::previousPage() */

undefined4 __thiscall DialogueWindow::previousPage(DialogueWindow *this)

{
  if (0 < *(int *)(this + 0x40)) {
    *(int *)(this + 0x40) = *(int *)(this + 0x40) + -1;
    loadContent(this);
    return 1;
  }
  return 0;
}

// ===== DialogueWindow::pickGermanGenericTextBecauseWeSaved100EurosWithThat  @0x00195d40  (170 bytes)
/* DialogueWindow::pickGermanGenericTextBecauseWeSaved100EurosWithThat(int, Agent*) */

undefined4 __thiscall
DialogueWindow::pickGermanGenericTextBecauseWeSaved100EurosWithThat
          (DialogueWindow *this,int param_1,Agent *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined *puVar6;
  
  iVar2 = Agent::getRace(param_2);
  if (iVar2 < 10) {
    iVar2 = Agent::getRace(param_2);
    iVar3 = Agent::isMale(param_2);
    if (iVar2 == 3) {
      iVar2 = Agent::getImageParts(param_2);
      if (iVar2 == 0) {
        iVar2 = 3;
      }
      else {
        piVar4 = (int *)Agent::getImageParts(param_2);
        iVar2 = 0;
        if (*piVar4 == 2) {
          iVar2 = 3;
        }
      }
    }
  }
  else {
    iVar3 = Agent::isMale(param_2);
    iVar2 = 10;
  }
  if (param_1 == 2) {
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
    puVar6 = &UNK_0025c73c;
  }
  else if (param_1 == 0) {
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
    puVar6 = &UNK_0025c6ec;
  }
  else {
    iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
    puVar6 = &UNK_0025c78c;
  }
  iVar1 = iVar5 * 4 + 0x48;
  if (iVar3 != 0) {
    iVar1 = iVar5 * 4 + iVar2 * 8;
  }
  return *(undefined4 *)(puVar6 + iVar1);
}

// ===== DialogueWindow::draw  @0x00195e04  (326 bytes)
/* DialogueWindow::draw() */

void __thiscall DialogueWindow::draw(DialogueWindow *this)

{
  Layout *pLVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  float local_58;
  float local_50;
  float local_40;
  float local_38;
  String aSStack_2c [8];
  int local_24;
  
  local_24 = __stack_chk_guard;
  AbyssEngine::PaintCanvas::SetColor(Globals::Canvas);
  Layout::drawMask();
  pLVar1 = Globals::layout;
  uVar4 = *(undefined4 *)(this + 0x14);
  uVar5 = *(undefined4 *)(this + 0x18);
  uVar3 = *(undefined4 *)(this + 0x1c);
  uVar6 = *(undefined4 *)(this + 0x20);
  uVar2 = AbyssEngine::String::String(aSStack_2c,this + 0x30,false);
  Layout::drawBox(pLVar1,7,uVar4,uVar5,uVar3,uVar6,uVar2);
  AbyssEngine::String::~String(aSStack_2c);
  ScrollTouchWindow::draw(*(ScrollTouchWindow **)(this + 0x38));
  ImageFactory::drawChar
            (Globals::imageFactory,*(Array **)(this + 0xc),
             *(int *)(Globals::layout + 0x4c) + *(int *)(this + 0x14),
             *(int *)(Globals::layout + 0x4c) + *(int *)(this + 0x18) +
             *(int *)(Globals::layout + 8),(bool)this[0x68]);
  TouchButton::draw(*(TouchButton **)this);
  TouchButton::draw(*(TouchButton **)(this + 4));
  TouchButton::draw(*(TouchButton **)(this + 8));
  if (this[0x4c] != (DialogueWindow)0x0) {
    ChoiceWindow::draw(*(ChoiceWindow **)(this + 0x48));
  }
  if (Globals::is_choice_window_visible == 0) {
    if (*(int *)(this + 8) != 0) {
      TouchButton::getPosition();
      Globals::other_buttons_x._8_4_ = (undefined4)local_38;
      TouchButton::getPosition();
      Globals::other_buttons_y._8_4_ = (undefined4)local_40;
    }
    if (*(int *)(this + 4) != 0) {
      TouchButton::getPosition();
      Globals::other_buttons_x._12_4_ = (undefined4)local_50;
      TouchButton::getPosition();
      Globals::other_buttons_y._12_4_ = (undefined4)local_58;
    }
    Globals::is_dialogue_window_visible = 1;
  }
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== DialogueWindow::OnTouchBegin  @0x00195f88  (76 bytes)
/* DialogueWindow::OnTouchBegin(int, int) */

undefined4 __thiscall DialogueWindow::OnTouchBegin(DialogueWindow *this,int param_1,int param_2)

{
  if (this[0x4c] == (DialogueWindow)0x0) {
    ScrollTouchWindow::OnTouchBegin(*(int *)(this + 0x38),param_1);
    TouchButton::OnTouchBegin(*(TouchButton **)this,param_1,param_2);
    TouchButton::OnTouchBegin(*(TouchButton **)(this + 4),param_1,param_2);
    TouchButton::OnTouchBegin(*(TouchButton **)(this + 8),param_1,param_2);
  }
  else {
    ChoiceWindow::OnTouchBegin(*(ChoiceWindow **)(this + 0x48),param_1,param_2);
  }
  return 0;
}

// ===== DialogueWindow::OnTouchMove  @0x00195fd4  (76 bytes)
/* DialogueWindow::OnTouchMove(int, int) */

undefined4 __thiscall DialogueWindow::OnTouchMove(DialogueWindow *this,int param_1,int param_2)

{
  if (this[0x4c] == (DialogueWindow)0x0) {
    ScrollTouchWindow::OnTouchMove(*(ScrollTouchWindow **)(this + 0x38),param_1,param_2);
    TouchButton::OnTouchMove(*(TouchButton **)this,param_1,param_2);
    TouchButton::OnTouchMove(*(TouchButton **)(this + 4),param_1,param_2);
    TouchButton::OnTouchMove(*(TouchButton **)(this + 8),param_1,param_2);
  }
  else {
    ChoiceWindow::OnTouchMove(*(ChoiceWindow **)(this + 0x48),param_1,param_2);
  }
  return 0;
}

// ===== DialogueWindow::OnTouchEnd  @0x00196020  (282 bytes)
/* DialogueWindow::OnTouchEnd(int, int) */

undefined4 __thiscall DialogueWindow::OnTouchEnd(DialogueWindow *this,int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  String *pSVar4;
  float extraout_s0;
  float fVar5;
  
  if (this[0x4c] == (DialogueWindow)0x0) {
    ScrollTouchWindow::OnTouchEnd(*(int *)(this + 0x38),param_1);
    iVar2 = TouchButton::OnTouchEnd(*(TouchButton **)this,param_1,param_2);
    if (iVar2 == 1) {
      FModSound::stop(Globals::sound,*(int *)(this + 0x5c));
      if (0 < *(int *)(this + 0x40)) {
        *(int *)(this + 0x40) = *(int *)(this + 0x40) + -1;
        loadContent(this);
      }
    }
    iVar2 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 4),param_1,param_2);
    if (iVar2 == 1) {
      FModSound::stop(Globals::sound,*(int *)(this + 0x5c));
      iVar2 = nextPage(this);
      if (iVar2 != 1) goto LAB_0019612e;
    }
    iVar2 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 8),param_1,param_2);
    if (iVar2 == 1) {
      pSVar4 = *(String **)(this + 0x48);
      bVar1 = (bool)GameText::getText(Globals::gameText,0x18c);
      ChoiceWindow::set(pSVar4,bVar1);
      this[0x4c] = (DialogueWindow)0x1;
    }
    uVar3 = 0;
  }
  else {
    iVar2 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x48),param_1,param_2);
    if (iVar2 == 1) {
      this[0x4c] = (DialogueWindow)0x0;
      return 0;
    }
    if (iVar2 != 0) {
      return 0;
    }
    this[0x4c] = (DialogueWindow)0x0;
    iVar2 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar2 == 0xf) {
      FModSound::play(Globals::sound,0xa2,(Vector *)0x0,(Vector *)0x0,extraout_s0);
      fVar5 = (float)FModSound::stop(Globals::sound,*(int *)Globals::sound);
      FModSound::play(Globals::sound,0x88,(Vector *)0x0,(Vector *)0x0,fVar5);
    }
    if (*(int *)(this + 0x5c) != -1) {
      FModSound::stop(Globals::sound,*(int *)(this + 0x5c));
    }
LAB_0019612e:
    uVar3 = 1;
  }
  return uVar3;
}

