// Class: Radio
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Radio::Radio  @0x001802a4  (68 bytes)
/* Radio::Radio() */

void __thiscall Radio::Radio(Radio *this)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined2 *)(this + 0x2c) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x30) = 0xffffffff;
  iVar1 = Globals::layout;
  iVar2 = *(int *)(Globals::layout + 0x98);
  *(int *)(this + 0x38) = iVar2;
  *(int *)(this + 0x3c) = Globals::w - iVar2 >> 1;
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(iVar1 + 0x9c);
  return;
}

// ===== Radio::~Radio  @0x001802f0  (80 bytes)
/* Radio::~Radio() */

Radio * __thiscall Radio::~Radio(Radio *this)

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
  if (*(void **)(this + 0x10) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x10));
  }
  *(undefined4 *)(this + 0x10) = 0;
  if (*(Array **)(this + 8) != (Array *)0x0) {
    ArrayReleaseClasses<AbyssEngine::String*>(*(Array **)(this + 8));
    pvVar1 = *(void **)(this + 8);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 8) = 0;
  return this;
}

// ===== Radio::setMessages  @0x00180340  (44 bytes)
/* Radio::setMessages(Array<RadioMessage*>*) */

void __thiscall Radio::setMessages(Radio *this,Array *param_1)

{
  uint uVar1;
  
  *(Array **)this = param_1;
  if ((param_1 != (Array *)0x0) && (*(int *)param_1 != 0)) {
    uVar1 = 0;
    do {
      RadioMessage::setRadio(*(RadioMessage **)(*(int *)(param_1 + 4) + uVar1 * 4),this);
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)param_1);
  }
  return;
}

// ===== Radio::setCurrentMessage  @0x0018036c  (4 bytes)
/* Radio::setCurrentMessage(RadioMessage*) */

void __thiscall Radio::setCurrentMessage(Radio *this,RadioMessage *param_1)

{
  *(RadioMessage **)(this + 4) = param_1;
  return;
}

// ===== Radio::getMessage  @0x00180370  (10 bytes)
/* Radio::getMessage(int) */

undefined4 __thiscall Radio::getMessage(Radio *this,int param_1)

{
  return *(undefined4 *)(*(int *)(*(int *)this + 4) + param_1 * 4);
}

// ===== Radio::lastMessageShown  @0x0018037a  (6 bytes)
/* Radio::lastMessageShown() */

Radio __thiscall Radio::lastMessageShown(Radio *this)

{
  return this[0x2c];
}

// ===== Radio::update  @0x00180380  (724 bytes)
/* Radio::update(long, PlayerEgo*, LevelScript*) */

void Radio::update(long param_1,PlayerEgo *param_2,LevelScript *param_3)

{
  GameText *this;
  Globals *this_00;
  uint *puVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  undefined *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  String *pSVar9;
  Agent *this_01;
  uint uVar10;
  int *piVar11;
  int iVar12;
  uint uVar13;
  bool bVar14;
  int local_3c;
  String aSStack_38 [8];
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  puVar1 = *(uint **)param_1;
  if ((puVar1 != (uint *)0x0) && (uVar10 = *puVar1, uVar10 != 0)) {
    uVar13 = 0;
    do {
      iVar2 = RadioMessage::triggered
                        (CONCAT44(uVar10,*(undefined4 *)(puVar1[1] + uVar13 * 4)),param_2,
                         (LevelScript *)((int)param_2 >> 0x1f));
      if (iVar2 == 1) {
        iVar2 = RadioMessage::getImageID
                          (*(RadioMessage **)(*(int *)(*(int *)param_1 + 4) + uVar13 * 4));
        if (iVar2 < 10000) {
          if ((iVar2 < 0x3f) && (iVar2 != 0x15)) {
            if (*(void **)(param_1 + 0x10) != (void *)0x0) {
              operator_delete__(*(void **)(param_1 + 0x10));
            }
            piVar11 = operator_new__(0x14);
            iVar12 = 0;
            *(int **)(param_1 + 0x10) = piVar11;
            puVar5 = (&PTR_DAT_0026447c)[iVar2];
            do {
              piVar11[iVar12] = *(int *)(puVar5 + iVar12 * 4);
              iVar12 = iVar12 + 1;
            } while (iVar12 != 5);
            local_3c = *piVar11;
            bVar14 = local_3c != 10;
            if (!bVar14) {
              local_3c = 0;
            }
            if (iVar2 == 9) {
              local_3c = 8;
            }
          }
          else {
            if (iVar2 == 0x41) {
              local_3c = 2;
            }
            else {
              local_3c = 1;
              if (iVar2 == 0x15) {
                local_3c = 3;
              }
              if (iVar2 == 0x40) {
                local_3c = 0;
              }
            }
            if (*(void **)(param_1 + 0x10) != (void *)0x0) {
              operator_delete__(*(void **)(param_1 + 0x10));
            }
            *(undefined4 *)(param_1 + 0x10) = 0;
            bVar14 = true;
            piVar11 = (int *)ImageFactory::createChar(Globals::imageFactory,true,local_3c);
            *(int **)(param_1 + 0x10) = piVar11;
          }
        }
        else {
          if (*(void **)(param_1 + 0x10) != (void *)0x0) {
            operator_delete__(*(void **)(param_1 + 0x10));
          }
          pvVar3 = operator_new__(0x14);
          *(void **)(param_1 + 0x10) = pvVar3;
          iVar12 = 0;
          do {
            iVar4 = Wanted::getImageParts
                              (*(Wanted **)(*(int *)(*Globals::status + 4) + (iVar2 + -10000) * 4));
            piVar11 = *(int **)(param_1 + 0x10);
            piVar11[iVar12] = *(int *)(iVar4 + iVar12 * 4);
            iVar12 = iVar12 + 1;
          } while (iVar12 != 5);
          bVar14 = true;
          local_3c = 0;
        }
        uVar6 = ImageFactory::loadChar(Globals::imageFactory,piVar11);
        *(undefined4 *)(param_1 + 0xc) = uVar6;
        if (*(Array **)(param_1 + 8) != (Array *)0x0) {
          ArrayReleaseClasses<AbyssEngine::String*>(*(Array **)(param_1 + 8));
          pvVar3 = *(void **)(param_1 + 8);
          if (pvVar3 != (void *)0x0) {
            if (*(void **)((int)pvVar3 + 4) != (void *)0x0) {
              operator_delete__(*(void **)((int)pvVar3 + 4));
            }
            operator_delete(pvVar3);
          }
        }
        *(undefined4 *)(param_1 + 8) = 0;
        puVar7 = operator_new(0xc);
        puVar8 = operator_new__(4);
        puVar7[1] = puVar8;
        puVar7[2] = 1;
        *puVar8 = 0;
        *puVar7 = 0;
        *(undefined4 **)(param_1 + 8) = puVar7;
        this = Globals::gameText;
        iVar12 = RadioMessage::getTextID
                           (*(RadioMessage **)(*(int *)(*(int *)param_1 + 4) + uVar13 * 4));
        pSVar9 = (String *)GameText::getText(this,iVar12);
        AbyssEngine::String::String(aSStack_30,pSVar9,false);
        puVar1 = &Globals::fontAlien;
        if (iVar2 != 0x38) {
          puVar1 = &Globals::font;
        }
        if (iVar2 == 0x13) {
          puVar1 = &Globals::fontAlien;
        }
        uVar10 = *puVar1;
        *(uint *)(param_1 + 0x34) = uVar10;
        Globals::getLineArray
                  (Globals::globals,uVar10,aSStack_30,
                   (*(int *)(param_1 + 0x38) + -10) - *(int *)(Globals::layout + 0x2d4),
                   *(Array **)(param_1 + 8));
        *(PlayerEgo **)(param_1 + 0x18) = param_2;
        *(LevelScript **)(param_1 + 0x1c) = (LevelScript *)((int)param_2 >> 0x1f);
        *(int *)(param_1 + 0x28) = **(int **)(param_1 + 8) * 2000 + 0x5dc;
        *(undefined1 *)(param_1 + 0x2d) = 1;
        this_01 = operator_new(0x88);
        AbyssEngine::String::String(aSStack_38,"",false);
        Agent::Agent(this_01,0,aSStack_38,0,0,local_3c,bVar14,0,0,0,0);
        AbyssEngine::String::~String(aSStack_38);
        this_00 = Globals::globals;
        iVar2 = RadioMessage::getTextID
                          (*(RadioMessage **)(*(int *)(*(int *)param_1 + 4) + uVar13 * 4));
        uVar6 = Globals::getDialogueSoundId(this_00,iVar2,this_01);
        *(undefined4 *)(param_1 + 0x30) = uVar6;
        pvVar3 = (void *)Agent::~Agent(this_01);
        operator_delete(pvVar3);
        AbyssEngine::String::~String(aSStack_30);
        break;
      }
      puVar1 = *(uint **)param_1;
      uVar13 = uVar13 + 1;
      uVar10 = *puVar1;
    } while (uVar13 < uVar10);
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Radio::draw  @0x001806b8  (530 bytes)
/* WARNING: Removing unreachable block (ram,0x001807ca) */
/* Radio::draw(long long, PlayerEgo*, LevelScript*) */

void Radio::draw(longlong param_1,PlayerEgo *param_2,LevelScript *param_3)

{
  uint *puVar1;
  undefined1 *puVar2;
  Layout *pLVar3;
  undefined4 *puVar4;
  String *pSVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int extraout_r1;
  uint uVar10;
  int iVar11;
  uint uVar12;
  bool bVar13;
  float in_s0;
  LevelScript *in_stack_00000000;
  String aSStack_38 [16];
  int local_28;
  
  puVar4 = (undefined4 *)param_1;
  local_28 = __stack_chk_guard;
  if (puVar4[1] == 0) {
    update((long)puVar4,param_2,in_stack_00000000);
    return;
  }
  puVar1 = puVar4 + 6;
  iVar7 = puVar4[7] + (uint)(0xfffff82f < *puVar1);
  bVar13 = (PlayerEgo *)(*puVar1 + 2000) < param_2;
  if ((int)((iVar7 - (int)param_3) - (uint)bVar13) < 0 !=
      (SBORROW4(iVar7,(int)param_3) != SBORROW4(iVar7 - (int)param_3,(uint)bVar13))) {
    if ((*(char *)((int)puVar4 + 0x2d) != '\0') && (-1 < (int)puVar4[0xc])) {
      FModSound::play(Globals::sound,puVar4[0xc],(Vector *)0x0,(Vector *)0x0,in_s0);
      *(undefined1 *)((int)puVar4 + 0x2d) = 0;
    }
    AbyssEngine::PaintCanvas::SetColor(Globals::Canvas);
    iVar7 = RadioMessage::getImageID((RadioMessage *)puVar4[1]);
    Layout::setDrawColor(Globals::layout,-0xd1);
    pLVar3 = Globals::layout;
    uVar8 = puVar4[0xf];
    uVar9 = puVar4[0x10];
    if (iVar7 < 10000) {
      pSVar5 = (String *)GameText::getText(Globals::gameText,iVar7 + 0x63d);
      AbyssEngine::String::String(aSStack_38,pSVar5,false);
      Layout::drawBox(pLVar3,7,uVar8,uVar9);
      puVar2 = &stack0xfffffff4;
    }
    else {
      Wanted::getName();
      Layout::drawBox(pLVar3,7,uVar8,uVar9);
      puVar2 = &stack0xfffffffc;
    }
    AbyssEngine::String::~String((String *)(puVar2 + -0x2c));
    Layout::setDrawColor(Globals::layout,-1);
    ImageFactory::drawChar
              (Globals::imageFactory,(Array *)puVar4[3],puVar4[0xf] + 5,
               *(int *)(Globals::layout + 8) + puVar4[0x10] + 5,false);
    Globals::drawLines(Globals::globals,puVar4[0xd],(Array *)puVar4[2],
                       *(int *)(Globals::layout + 0x2d4) + puVar4[0xf] + 7,
                       *(int *)(Globals::layout + 8) + puVar4[0x10] + 7);
    if (*(char *)((int)puVar4 + 0x2d) != '\0') {
      *(undefined1 *)((int)puVar4 + 0x2d) = 0;
    }
    piVar6 = (int *)*puVar4;
    iVar7 = extraout_r1;
    if (piVar6 != (int *)0x0) {
      iVar7 = *piVar6;
    }
    if (piVar6 != (int *)0x0 && iVar7 != 0) {
      uVar12 = puVar4[10];
      uVar10 = *puVar1 + uVar12;
      iVar11 = puVar4[7] + ((int)uVar12 >> 0x1f) + (uint)CARRY4(*puVar1,uVar12) +
               (uint)(0xfffff82f < uVar10);
      bVar13 = (PlayerEgo *)(uVar10 + 2000) < param_2;
      if ((int)((iVar11 - (int)param_3) - (uint)bVar13) < 0 !=
          (SBORROW4(iVar11,(int)param_3) != SBORROW4(iVar11 - (int)param_3,(uint)bVar13))) {
        if ((RadioMessage *)puVar4[1] == *(RadioMessage **)(piVar6[1] + iVar7 * 4 + -4)) {
          *(undefined1 *)(puVar4 + 0xb) = 1;
        }
        *puVar1 = 0;
        puVar4[7] = 0;
        RadioMessage::finish((RadioMessage *)puVar4[1]);
        puVar4[1] = 0;
      }
    }
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Radio::isShowingMessage  @0x00180908  (10 bytes)
/* Radio::isShowingMessage() */

bool __thiscall Radio::isShowingMessage(Radio *this)

{
  return *(int *)(this + 4) != 0;
}

