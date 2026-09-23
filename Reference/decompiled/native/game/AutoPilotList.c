// Class: AutoPilotList
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AutoPilotList::AutoPilotList  @0x00158d54  (706 bytes)
/* AutoPilotList::AutoPilotList(Level*) */

void __thiscall AutoPilotList::AutoPilotList(AutoPilotList *this,Level *param_1)

{
  Array *pAVar1;
  undefined4 *puVar2;
  AbyssEngine *pAVar3;
  String *pSVar4;
  SolarSystem *this_00;
  int iVar5;
  String *pSVar6;
  PlayerEgo *pPVar7;
  Route *this_01;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  String aSStack_38 [8];
  String aSStack_30 [8];
  AbyssEngine aAStack_28 [8];
  int local_20;
  
  local_20 = __stack_chk_guard;
  pAVar1 = operator_new(0xc);
  puVar2 = operator_new__(4);
  *(undefined4 **)(pAVar1 + 4) = puVar2;
  *(undefined4 *)(pAVar1 + 8) = 1;
  *puVar2 = 0;
  *(undefined4 *)pAVar1 = 0;
  *(Array **)(this + 0x10) = pAVar1;
  ArraySetLength<AbyssEngine::String*>(5,pAVar1);
  *(undefined4 *)(this + 0x14) = 0;
  if (Level::programmedStation != 0) {
    pAVar3 = operator_new(8);
    pSVar4 = (String *)GameText::getText(Globals::gameText,0x222);
    AbyssEngine::String::String(aSStack_30,": ",false);
    AbyssEngine::operator+(aAStack_28,pSVar4,aSStack_30);
    Station::getName();
    AbyssEngine::operator+(pAVar3,aAStack_28,aSStack_38);
    **(undefined4 **)(*(int *)(this + 0x10) + 4) = pAVar3;
    AbyssEngine::String::~String(aSStack_38);
    AbyssEngine::String::~String((String *)aAStack_28);
    AbyssEngine::String::~String(aSStack_30);
    *(int *)(this + 0x14) = *(int *)(this + 0x14) + 1;
  }
  this_00 = (SolarSystem *)Status::getSystem(Globals::status);
  iVar5 = SolarSystem::currentOrbitHasWarpGate(this_00);
  if (iVar5 == 1) {
    pSVar6 = operator_new(8);
    pSVar4 = (String *)GameText::getText(Globals::gameText,0x223);
    AbyssEngine::String::String(pSVar6,pSVar4,false);
    *(String **)(*(int *)(*(int *)(this + 0x10) + 4) + 4) = pSVar6;
    *(int *)(this + 0x14) = *(int *)(this + 0x14) + 1;
  }
  iVar5 = Status::inEmptyOrbit(Globals::status);
  if (iVar5 == 0) {
    pAVar3 = operator_new(8);
    Status::getStation(Globals::status);
    Station::getName();
    AbyssEngine::String::String(aSStack_38," ",false);
    AbyssEngine::operator+(aAStack_28,aSStack_30,aSStack_38);
    pSVar4 = (String *)GameText::getText(Globals::gameText,0x88);
    AbyssEngine::operator+(pAVar3,aAStack_28,pSVar4);
    *(AbyssEngine **)(*(int *)(*(int *)(this + 0x10) + 4) + 8) = pAVar3;
    AbyssEngine::String::~String((String *)aAStack_28);
    AbyssEngine::String::~String(aSStack_38);
    AbyssEngine::String::~String(aSStack_30);
    *(int *)(this + 0x14) = *(int *)(this + 0x14) + 1;
  }
  pSVar6 = operator_new(8);
  pSVar4 = (String *)GameText::getText(Globals::gameText,0x225);
  AbyssEngine::String::String(pSVar6,pSVar4,false);
  *(String **)(*(int *)(*(int *)(this + 0x10) + 4) + 0xc) = pSVar6;
  *(int *)(this + 0x14) = *(int *)(this + 0x14) + 1;
  pPVar7 = (PlayerEgo *)Level::getPlayer(param_1);
  iVar5 = PlayerEgo::getRoute(pPVar7);
  if (iVar5 != 0) {
    pPVar7 = (PlayerEgo *)Level::getPlayer(param_1);
    this_01 = (Route *)PlayerEgo::getRoute(pPVar7);
    iVar5 = Route::getLastWaypoint(this_01);
    if (*(char *)(iVar5 + 300) == '\0') {
      pSVar6 = operator_new(8);
      pSVar4 = (String *)GameText::getText(Globals::gameText,0x23d);
      AbyssEngine::String::String(pSVar6,pSVar4,false);
      *(String **)(*(int *)(*(int *)(this + 0x10) + 4) + 0x10) = pSVar6;
      *(int *)(this + 0x14) = *(int *)(this + 0x14) + 1;
    }
  }
  iVar5 = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 0xc) = 0;
  puVar8 = *(uint **)(this + 0x10);
  if (*puVar8 == 0) {
    iVar9 = 0;
  }
  else {
    iVar9 = 0;
    uVar10 = 0;
    do {
      pSVar4 = *(String **)(puVar8[1] + uVar10 * 4);
      if (pSVar4 != (String *)0x0) {
        iVar5 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,pSVar4);
        iVar5 = iVar5 + 0x13;
        iVar9 = *(int *)(this + 0xc);
        if (*(int *)(this + 0xc) < iVar5) {
          *(int *)(this + 0xc) = iVar5;
          iVar9 = iVar5;
        }
      }
      puVar8 = *(uint **)(this + 0x10);
      uVar10 = uVar10 + 1;
    } while (uVar10 < *puVar8);
    iVar5 = *(int *)this;
  }
  *(int *)(this + 4) = (Globals::w - iVar9) / 2;
  *(int *)(this + 8) = (*(int *)(this + 0x14) * -0xf + Globals::h + -0xc) / 2;
  if (*(int *)(puVar8[1] + iVar5 * 4) == 0) {
    do {
      iVar9 = 0;
      if (iVar5 < 4) {
        iVar9 = iVar5 + 1;
      }
      iVar5 = iVar9;
    } while (*(int *)(puVar8[1] + iVar9 * 4) == 0);
    *(int *)this = iVar9;
  }
  if (__stack_chk_guard - local_20 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_20);
  }
  return;
}

// ===== AutoPilotList::down  @0x001590b0  (28 bytes)
/* AutoPilotList::down() */

void __thiscall AutoPilotList::down(AutoPilotList *this)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)this;
  do {
    iVar1 = 0;
    if (iVar2 < 4) {
      iVar1 = iVar2 + 1;
    }
    iVar2 = iVar1;
  } while (*(int *)(*(int *)(*(int *)(this + 0x10) + 4) + iVar2 * 4) == 0);
  *(int *)this = iVar2;
  return;
}

// ===== AutoPilotList::~AutoPilotList  @0x001590cc  (38 bytes)
/* AutoPilotList::~AutoPilotList() */

AutoPilotList * __thiscall AutoPilotList::~AutoPilotList(AutoPilotList *this)

{
  void *pvVar1;
  
  ArrayReleaseClasses<AbyssEngine::String*>(*(Array **)(this + 0x10));
  pvVar1 = *(void **)(this + 0x10);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x10) = 0;
  return this;
}

// ===== AutoPilotList::fire  @0x001590f2  (4 bytes)
/* AutoPilotList::fire() */

undefined4 __thiscall AutoPilotList::fire(AutoPilotList *this)

{
  return *(undefined4 *)this;
}

// ===== AutoPilotList::getTargetString  @0x001590f8  (44 bytes)
/* AutoPilotList::getTargetString() */

void AutoPilotList::getTargetString(void)

{
  String *in_r0;
  uint *in_r1;
  uint uVar1;
  
  uVar1 = *in_r1;
  if ((-1 < (int)uVar1) && (uVar1 < *(uint *)in_r1[4])) {
    AbyssEngine::String::String(in_r0,*(String **)(((uint *)in_r1[4])[1] + uVar1 * 4),false);
    return;
  }
  AbyssEngine::String::String(in_r0,"",false);
  return;
}

// ===== AutoPilotList::up  @0x00159128  (28 bytes)
/* AutoPilotList::up() */

void __thiscall AutoPilotList::up(AutoPilotList *this)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)this;
  do {
    iVar1 = 4;
    if (0 < iVar2) {
      iVar1 = iVar2 + -1;
    }
    iVar2 = iVar1;
  } while (*(int *)(*(int *)(*(int *)(this + 0x10) + 4) + iVar2 * 4) == 0);
  *(int *)this = iVar2;
  return;
}

// ===== AutoPilotList::draw  @0x00159144  (200 bytes)
/* AutoPilotList::draw() */

void __thiscall AutoPilotList::draw(AutoPilotList *this)

{
  Layout *pLVar1;
  String *pSVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  String aSStack_30 [8];
  int local_28;
  
  pLVar1 = Globals::layout;
  local_28 = __stack_chk_guard;
  pSVar2 = (String *)GameText::getText(Globals::gameText,0x23c);
  AbyssEngine::String::String(aSStack_30,pSVar2,false);
  Layout::drawWindow(pLVar1,aSStack_30,*(undefined4 *)(this + 4),*(undefined4 *)(this + 8),
                     *(undefined4 *)(this + 0xc),*(int *)(this + 0x14) * 0xf + 0x16);
  AbyssEngine::String::~String(aSStack_30);
  puVar3 = *(uint **)(this + 0x10);
  if (*puVar3 != 0) {
    uVar4 = 0;
    iVar5 = 0;
    do {
      pSVar2 = *(String **)(puVar3[1] + uVar4 * 4);
      if (pSVar2 != (String *)0x0) {
        AbyssEngine::PaintCanvas::DrawString
                  (Globals::Canvas,Globals::font,pSVar2,*(int *)(this + 4),
                   iVar5 * 0xf + *(int *)(this + 8) + 0x12,false);
        puVar3 = *(uint **)(this + 0x10);
        iVar5 = iVar5 + 1;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar3);
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AutoPilotList::touch  @0x00159234  (126 bytes)
/* AutoPilotList::touch(int, int) */

int __thiscall AutoPilotList::touch(AutoPilotList *this,int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if ((*(int *)(this + 4) <= param_1) && (param_1 < *(int *)(this + 0xc) + *(int *)(this + 4))) {
    uVar3 = (param_2 - *(int *)(this + 8)) - 0xe;
    if (-0x1e < (int)uVar3) {
      iVar4 = (int)((longlong)(int)uVar3 * -0x77777777 + ((ulonglong)uVar3 << 0x20) >> 0x20);
      iVar4 = (iVar4 >> 3) - (iVar4 >> 0x1f);
      if (iVar4 + 1U < **(uint **)(this + 0x10)) {
        *(undefined4 *)this = 0;
        if (param_2 - *(int *)(this + 8) < 0) {
          return 0;
        }
        iVar5 = 0;
        iVar6 = 0;
        do {
          iVar2 = 0;
          if (iVar5 < 4) {
            iVar2 = iVar5 + 1;
          }
          iVar5 = iVar2;
        } while ((*(int *)((*(uint **)(this + 0x10))[1] + iVar2 * 4) == 0) ||
                (bVar1 = iVar6 < iVar4, iVar6 = iVar6 + 1, bVar1));
        *(int *)this = iVar2;
        return iVar2;
      }
    }
  }
  return -1;
}

