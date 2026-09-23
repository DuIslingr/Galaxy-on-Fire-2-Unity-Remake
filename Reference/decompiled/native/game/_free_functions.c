// Class: _free_functions
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== _FINI_0  @0x00071940  (24 bytes)
void _FINI_0(void)

{
  __cxa_finalize(&DAT_00269000);
  return;
}

// ===== _INIT_0  @0x00071950  (106 bytes)
void _INIT_0(void)

{
  AbyssEngine::Engine::tv_modes._4_4_ = operator_new__(4);
  AbyssEngine::Engine::tv_modes._8_4_ = 1;
  *(undefined4 *)AbyssEngine::Engine::tv_modes._4_4_ = 0;
  AbyssEngine::Engine::tv_modes._0_4_ = 0;
  __cxa_atexit(Array<int>::~Array,AbyssEngine::Engine::tv_modes,&DAT_00269000);
  AbyssEngine::String::String((String *)&AbyssEngine::Engine::renderer);
  __cxa_atexit(AbyssEngine::String::~String,&AbyssEngine::Engine::renderer,&DAT_00269000);
  AbyssEngine::String::String((String *)&AbyssEngine::Engine::vendor);
  __cxa_atexit(AbyssEngine::String::~String,&AbyssEngine::Engine::vendor,&DAT_00269000);
  return;
}

// ===== _INIT_1  @0x000719d4  (22 bytes)
void _INIT_1(void)

{
  touches = realloc(touches,0x10);
  return;
}

// ===== _INIT_2  @0x000719f0  (70 bytes)
void _INIT_2(void)

{
  ParticleSettings::ParticleSettings((ParticleSettings *)ParticleSettingsRef::init);
  __cxa_atexit(ParticleSettings::~ParticleSettings,ParticleSettingsRef::init,&DAT_00269000);
  ParticleSettings::ParticleSettings((ParticleSettings *)ParticleSettingsRef::cur);
  __cxa_atexit(ParticleSettings::~ParticleSettings,ParticleSettingsRef::cur,&DAT_00269000);
  return;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_ToJNI_BackButtonPressed  @0x00071a70  (12 bytes)
void Java_net_fishlabs_gof2hdallandroid2012_ToJNI_BackButtonPressed(void)

{
  g_android_back_button_pressed = 1;
  return;
}

// ===== IsInGameSubMenuNotActive  @0x0007227c  (44 bytes)
/* IsInGameSubMenuNotActive(int) */

undefined4 IsInGameSubMenuNotActive(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((Globals::subMenuIndex == -1) && (Globals::is_menu_visible == 0)) &&
     (uVar1 = 0, Globals::isStarMapVisible == '\0')) {
    uVar1 = 1;
  }
  return uVar1;
}

// ===== IsDialogNotVisible2  @0x000722b4  (38 bytes)
/* IsDialogNotVisible2(int) */

bool IsDialogNotVisible2(int param_1)

{
  return (Globals::is_dialogue_window_visible == 0 && Globals::is_choice_window_visible == 0) &&
         Globals::is_menu_visible == 0;
}

// ===== IsDialogVisible  @0x000722e8  (24 bytes)
/* IsDialogVisible(int) */

bool IsDialogVisible(int param_1)

{
  return Globals::is_dialogue_window_visible != 0 || Globals::is_choice_window_visible != 0;
}

// ===== IsStarMapNotVisible  @0x00072308  (14 bytes)
/* IsStarMapNotVisible(int) */

byte IsStarMapNotVisible(int param_1)

{
  return Globals::isStarMapVisible ^ 1;
}

// ===== IsDialogNotVisible  @0x0007231c  (28 bytes)
/* IsDialogNotVisible(int) */

bool IsDialogNotVisible(int param_1)

{
  return Globals::is_dialogue_window_visible == 0 && Globals::is_choice_window_visible == 0;
}

// ===== IsInPrimaryMenu  @0x00072340  (88 bytes)
/* IsInPrimaryMenu(int) */

undefined4 IsInPrimaryMenu(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (Globals::is_menu_visible != 0) {
    if (Globals::is_choice_window_visible != 0 ||
        ((Globals::menu_touch_window_type != 0 || Globals::topMenuIndex != 0) ||
        Globals::is_dialogue_window_visible != 0)) {
      return 0;
    }
    uVar1 = 0;
    if (Globals::isStarMapVisible == '\0') {
      uVar1 = 1;
    }
  }
  return uVar1;
}

// ===== IsSubMenuActive  @0x000723b0  (130 bytes)
/* IsSubMenuActive(int) */

bool IsSubMenuActive(int param_1)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = false;
  if (0x578 < (int)(&DAT_00269048)[param_1 * 0x16]) {
    if (Globals::sub_menu_button_count <= (&DAT_00269048)[param_1 * 0x16] + -0x579) {
      return false;
    }
    if (Globals::is_menu_visible != 0) {
      return 1 < Globals::topMenuIndex - 1U || Globals::is_menu_visible == 0;
    }
    if (Globals::subMenuIndex != -1) {
      return true;
    }
    iVar1 = AbyssEngine::ApplicationManager::GetCurrentApplicationModule(Globals::appManager);
    bVar2 = iVar1 == 5;
  }
  return bVar2;
}

// ===== IsInGameSubMenuActive  @0x0007244c  (20 bytes)
/* IsInGameSubMenuActive(int) */

bool IsInGameSubMenuActive(int param_1)

{
  return Globals::subMenuIndex != -1;
}

// ===== HideMouse  @0x00072464  (8 bytes)
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* HideMouse() */

undefined4 HideMouse(void)

{
  return DAT_0026b960;
}

// ===== CaptureMouse  @0x00072470  (8 bytes)
/* CaptureMouse(int) */

void CaptureMouse(int param_1)

{
  DAT_0026b960 = param_1;
  return;
}

// ===== SwitchToOtherMouseConifguration  @0x0007247c  (10 bytes)
/* SwitchToOtherMouseConifguration(int) */

undefined4 SwitchToOtherMouseConifguration(int param_1)

{
  DAT_0026a088 = param_1;
  return 0;
}

// ===== UseJoystick  @0x0007248c  (8 bytes)
/* UseJoystick(int) */

void UseJoystick(int param_1)

{
  DAT_0026b964 = param_1;
  return;
}

// ===== GetUseJoystick  @0x00072498  (8 bytes)
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* GetUseJoystick() */

undefined4 GetUseJoystick(void)

{
  return DAT_0026b964;
}

// ===== SetKeyCode  @0x000724a4  (130 bytes)
/* SetKeyCode(char const*, int, int) */

void SetKeyCode(char *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != (char *)0x0) {
    iVar2 = 0;
    do {
      iVar1 = strcmp(&keys + iVar2,param_1);
      if (iVar1 == 0) {
        switch(param_2) {
        case 0:
          *(int *)((int)&DAT_00269020 + iVar2) = param_3;
          break;
        case 1:
          *(int *)((int)&DAT_00269024 + iVar2) = param_3;
          break;
        case 2:
          *(int *)((int)&DAT_00269028 + iVar2) = param_3;
          break;
        case 3:
          *(int *)((int)&DAT_0026902c + iVar2) = param_3;
        }
      }
      iVar2 = iVar2 + 0x58;
    } while (iVar2 != 0x1080);
  }
  return;
}

// ===== GetKeyState  @0x00072540  (24 bytes)
/* GetKeyState(int) */

undefined4 GetKeyState(int param_1)

{
  if ((uint)param_1 < 0x30) {
    return (&DAT_0026901c)[param_1 * 0x16];
  }
  return 0;
}

// ===== GetKeyState  @0x0007255c  (48 bytes)
/* GetKeyState(char*) */

undefined4 GetKeyState(char *param_1)

{
  int iVar1;
  char *__s1;
  int iVar2;
  
  iVar2 = 0;
  __s1 = &keys;
  while ((iVar1 = strcmp(__s1,param_1), iVar1 != 0 || (*(int *)(__s1 + 0x14) == 0))) {
    iVar2 = iVar2 + 1;
    __s1 = __s1 + 0x58;
    if (0x2f < iVar2) {
      return 0;
    }
  }
  return 1;
}

// ===== keyEventPressed  @0x00072590  (64 bytes)
/* keyEventPressed(AbyssEngine::Engine*, char*) */

void keyEventPressed(Engine *param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = strcmp(&keys + iVar2,param_2);
    if (iVar1 == 0) {
      keyPressed(param_1,*(int *)((int)&DAT_00269020 + iVar2));
    }
    iVar2 = iVar2 + 0x58;
  } while (iVar2 != 0x1080);
  return;
}

// ===== keyPressed  @0x000725d8  (796 bytes)
/* keyPressed(AbyssEngine::Engine*, int) */

void keyPressed(Engine *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  undefined **ppuVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  int iVar10;
  int iVar11;
  int local_34;
  
  if (param_1 == (Engine *)0x0) {
    return;
  }
  if (param_2 == 0xe) {
    if (DAT_0026c96c == 4) {
      DAT_0026c96c = 5;
    }
    else if (DAT_0026c96c == 6) {
      DAT_0026c96c = 7;
    }
    else if (DAT_0026c96c != 9) {
      DAT_0026c96c = 1;
    }
  }
  else if (param_2 == 0x40000000 && DAT_0026c96c == 1) {
    DAT_0026c96c = 2;
  }
  else if (param_2 == 1 && DAT_0026c96c == 2) {
    DAT_0026c96c = 3;
  }
  else if (param_2 == 0x11 && DAT_0026c96c == 3) {
    DAT_0026c96c = 4;
  }
  else if (param_2 == 0xf && DAT_0026c96c == 5) {
    DAT_0026c96c = 6;
  }
  else if (param_2 == 5 && DAT_0026c96c == 7) {
    DAT_0026c96c = 8;
  }
  else if (DAT_0026c96c == 8 && param_2 == 5) {
    DAT_0026c96c = 9;
  }
  else if (DAT_0026c96c != 9) {
    DAT_0026c96c = 0;
  }
  iVar2 = AbyssEngine::ApplicationManager::GetCurrentApplicationModule(Globals::appManager);
  local_34 = -1;
  iVar4 = 2;
  do {
    iVar11 = 0;
    iVar10 = 0;
    do {
      if (((((iVar4 == *(int *)((int)&DAT_00269058 + iVar11)) &&
            ((((*(int *)((int)&DAT_00269020 + iVar11) == param_2 ||
               (*(int *)((int)&DAT_00269024 + iVar11) == param_2)) ||
              (*(int *)((int)&DAT_00269028 + iVar11) == param_2)) ||
             (*(int *)((int)&DAT_0026902c + iVar11) == param_2)))) &&
           ((*(int *)((int)&DAT_0026901c + iVar11) == 0 &&
            (iVar2 == *(int *)((int)&DAT_0026904c + iVar11) ||
             *(int *)((int)&DAT_0026904c + iVar11) == -1)))) &&
          ((*(int *)((int)&DAT_00269050 + iVar11) == 0 ||
           (DAT_0026c970 == *(int *)((int)&DAT_00269050 + iVar11))))) &&
         ((*(code **)((int)&DAT_0026905c + iVar11) == (code *)0x0 ||
          (iVar3 = (**(code **)((int)&DAT_0026905c + iVar11))(iVar10), iVar3 != 0)))) {
        *(undefined4 *)((int)&DAT_0026901c + iVar11) = 1;
        if (iVar10 < 0xb) {
          local_34 = iVar10;
        }
        if (iVar11 == 0x688) {
          local_34 = 0x13;
        }
        if (*(int **)((int)&DAT_00269030 + iVar11) != (int *)0x0) {
          AbyssEngine::ApplicationManager::OnTouchBegin
                    (*(ApplicationManager **)(param_1 + 0x28),
                     *(int *)((int)&DAT_00269038 + iVar11) + **(int **)((int)&DAT_00269030 + iVar11)
                     ,*(int *)((int)&DAT_0026903c + iVar11) +
                      **(int **)((int)&DAT_00269034 + iVar11),
                     *(void **)((int)&DAT_00269048 + iVar11));
          *(undefined4 *)((int)&DAT_00269040 + iVar11) =
               **(undefined4 **)((int)&DAT_00269030 + iVar11);
          *(undefined4 *)((int)&DAT_00269044 + iVar11) =
               **(undefined4 **)((int)&DAT_00269034 + iVar11);
        }
        if (0 < iVar4) goto LAB_00072808;
      }
      iVar10 = iVar10 + 1;
      iVar11 = iVar11 + 0x58;
    } while (iVar10 < 0x30);
    bVar1 = 0 < iVar4;
    iVar4 = iVar4 + -1;
  } while (bVar1);
LAB_00072808:
  if (DAT_0026c96c == 9) {
    iVar4 = GetKeyState("Accelerate");
    if (iVar4 == 0) {
      iVar4 = GetKeyState("Decelerate");
      if (iVar4 == 0) {
        if (Globals::keys._168_4_ != 0) {
          DAT_0026c978 = 0;
          DAT_0026c974 = 0;
        }
        goto LAB_00072842;
      }
      puVar5 = &DAT_0026c978;
      puVar9 = &DAT_0026c974;
    }
    else {
      puVar5 = &DAT_0026c974;
      puVar9 = &DAT_0026c978;
    }
    *puVar5 = 1;
    *puVar9 = 0;
  }
LAB_00072842:
  switch(local_34) {
  case 0:
    puVar6 = &DAT_0026a08c;
    goto LAB_00072896;
  case 1:
    puVar6 = &DAT_0026a08c;
    goto LAB_00072886;
  case 2:
    puVar6 = &DAT_0026a090;
LAB_00072886:
    *puVar6 = 0x3dcccccd;
    return;
  case 3:
    puVar6 = &DAT_0026a090;
LAB_00072896:
    *puVar6 = 0xbdcccccd;
    return;
  case 4:
    uVar8 = 0xffffffff;
    ppuVar7 = &PTR_keyboard_swipe_002654ac;
    break;
  case 5:
    uVar8 = 1;
    ppuVar7 = &PTR_keyboard_swipe_002654ac;
    break;
  case 6:
    uVar8 = 0xbc23d70a;
    ppuVar7 = &PTR_bankZ_002654a8;
    break;
  case 7:
    uVar8 = 0x3c23d70a;
    ppuVar7 = &PTR_bankZ_002654a8;
    break;
  case 8:
    uVar8 = 0x3f800000;
    goto LAB_000728d6;
  case 9:
    uVar8 = 0xbf800000;
LAB_000728d6:
    *(undefined4 *)(param_1 + 0x350) = uVar8;
    return;
  default:
    goto switchD_00072848_caseD_a;
  case 0x13:
    Globals::showWingmanMenu = 1;
    goto switchD_00072848_caseD_a;
  }
  *(undefined4 *)*ppuVar7 = uVar8;
switchD_00072848_caseD_a:
  return;
}

// ===== keyEventReleased  @0x000729b4  (64 bytes)
/* keyEventReleased(AbyssEngine::Engine*, char*) */

void keyEventReleased(Engine *param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = strcmp(&keys + iVar2,param_2);
    if (iVar1 == 0) {
      keyReleased(param_1,*(int *)((int)&DAT_00269020 + iVar2));
    }
    iVar2 = iVar2 + 0x58;
  } while (iVar2 != 0x1080);
  return;
}

// ===== keyReleased  @0x000729fc  (462 bytes)
/* keyReleased(AbyssEngine::Engine*, int) */

void keyReleased(Engine *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  Globals::is_dialogue_window_visible = 0;
  Globals::is_choice_window_visible = 0;
  Globals::is_menu_visible = 0;
  Globals::is_hacking_visible = 0;
  if (param_1 == (Engine *)0x0) {
    Globals::is_dialogue_window_visible = 0;
    Globals::is_choice_window_visible = 0;
    Globals::is_menu_visible = 0;
    Globals::is_hacking_visible = 0;
    return;
  }
  AbyssEngine::ApplicationManager::GetCurrentApplicationModule(Globals::appManager);
  iVar1 = -1;
  iVar3 = 0;
  iVar2 = 0;
  do {
    if (((((*(int *)((int)&DAT_00269020 + iVar3) == param_2) ||
          (*(int *)((int)&DAT_00269024 + iVar3) == param_2)) ||
         (*(int *)((int)&DAT_00269028 + iVar3) == param_2)) ||
        (*(int *)((int)&DAT_0026902c + iVar3) == param_2)) &&
       (*(int *)((int)&DAT_0026901c + iVar3) == 1)) {
      *(undefined4 *)((int)&DAT_0026901c + iVar3) = 0;
      if (iVar2 < 0xb) {
        iVar1 = iVar2;
      }
      if (*(int *)((int)&DAT_00269030 + iVar3) != 0) {
        AbyssEngine::ApplicationManager::OnTouchEnd
                  (*(ApplicationManager **)(param_1 + 0x28),
                   *(int *)((int)&DAT_00269038 + iVar3) + *(int *)((int)&DAT_00269040 + iVar3),
                   *(int *)((int)&DAT_0026903c + iVar3) + *(int *)((int)&DAT_00269044 + iVar3),
                   *(void **)((int)&DAT_00269048 + iVar3));
        AbyssEngine::ApplicationManager::OnTouchEnd(*(ApplicationManager **)(param_1 + 0x28));
        AbyssEngine::Engine::DrawQuad
                  (param_1,*(int *)((int)&DAT_00269040 + iVar3),*(int *)((int)&DAT_00269044 + iVar3)
                   ,10,10);
        if (*(int *)((int)&DAT_00269054 + iVar3) != 0) {
          DAT_0026c970 = *(int *)((int)&DAT_00269054 + iVar3);
        }
      }
    }
    iVar3 = iVar3 + 0x58;
    iVar2 = iVar2 + 1;
  } while (iVar3 != 0x1080);
  switch(iVar1) {
  case 0:
    DAT_0026a08c = 0x3f000000;
    if (DAT_00269074 != 0) {
      DAT_0026a08c = 0x3dcccccd;
    }
    break;
  case 1:
    DAT_0026a08c = 0x3f000000;
    if (DAT_0026901c != 0) {
      DAT_0026a08c = 0xbdcccccd;
    }
    break;
  case 2:
    DAT_0026a090 = 0x3f000000;
    if (DAT_00269124 != 0) {
      DAT_0026a090 = 0xbdcccccd;
    }
    break;
  case 3:
    DAT_0026a090 = 0x3f000000;
    if (DAT_002690cc != 0) {
      DAT_0026a090 = 0x3dcccccd;
    }
    break;
  case 6:
    goto LAB_00072bc6;
  case 7:
LAB_00072bc6:
    Globals::bankZ = 0;
  }
  return;
}

// ===== SendStoredKeyUpEvents  @0x00072c38  (60 bytes)
/* SendStoredKeyUpEvents(AbyssEngine::Engine*) */

void SendStoredKeyUpEvents(Engine *param_1)

{
  int iVar1;
  
  if (0 < DAT_0026b968) {
    iVar1 = 0;
    do {
      keyReleased(param_1,(&DAT_0026b96c)[iVar1]);
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_0026b968);
  }
  DAT_0026b968 = 0;
  return;
}

// ===== keyReleasedWithDelay  @0x00072c84  (32 bytes)
/* keyReleasedWithDelay(AbyssEngine::Engine*, int) */

void keyReleasedWithDelay(Engine *param_1,int param_2)

{
  if (0x400 < DAT_0026b968) {
    return;
  }
  (&DAT_0026b96c)[DAT_0026b968] = param_2;
  DAT_0026b968 = DAT_0026b968 + 1;
  return;
}

// ===== ArrowKeyPressed  @0x00072cb0  (30 bytes)
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* ArrowKeyPressed() */

bool ArrowKeyPressed(void)

{
  return DAT_00269124 != 0 || ((DAT_0026901c != 0 || DAT_00269074 != 0) || DAT_002690cc != 0);
}

// ===== keyIsPressed  @0x00072cd4  (48 bytes)
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* keyIsPressed() */

bool keyIsPressed(void)

{
  return (DAT_00269124 != 0 || (DAT_002690cc != 0 || (DAT_00269074 != 0 || DAT_0026901c != 0))) ||
         DAT_0026b960 != 0;
}

// ===== actualizeButtonPositions  @0x00072d0c  (2 bytes)
/* actualizeButtonPositions(AbyssEngine::Engine*) */

Engine * actualizeButtonPositions(Engine *param_1)

{
  return param_1;
}

// ===== LowerMouseWheel  @0x00072d10  (290 bytes)
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* LowerMouseWheel() */

void LowerMouseWheel(void)

{
  uint in_fpscr;
  double dVar1;
  
  if (Globals::mouse_wheel < 1) {
    if (Globals::mouse_wheel < 0) {
      dVar1 = (double)VectorSignedToFloat(Globals::mouse_wheel,(byte)(in_fpscr >> 0x16) & 3);
      Globals::mouse_wheel = (int)(longlong)(dVar1 * 0.95);
      if (0 < Globals::mouse_wheel) {
        Globals::mouse_wheel = 0;
      }
    }
  }
  else {
    dVar1 = (double)VectorSignedToFloat(Globals::mouse_wheel,(byte)(in_fpscr >> 0x16) & 3);
    Globals::mouse_wheel = (int)(longlong)(dVar1 * 0.95);
    if (Globals::mouse_wheel < 0) {
      Globals::mouse_wheel = 0;
    }
  }
  if (Globals::mouse_wheelX < 1) {
    if (Globals::mouse_wheelX < 0) {
      dVar1 = (double)VectorSignedToFloat(Globals::mouse_wheelX,(byte)(in_fpscr >> 0x16) & 3);
      Globals::mouse_wheelX = (int)(longlong)(dVar1 * 0.95);
      if (0 < Globals::mouse_wheelX) {
        Globals::mouse_wheelX = 0;
      }
    }
  }
  else {
    dVar1 = (double)VectorSignedToFloat(Globals::mouse_wheelX,(byte)(in_fpscr >> 0x16) & 3);
    Globals::mouse_wheelX = (int)(longlong)(dVar1 * 0.95);
    if (Globals::mouse_wheelX < 0) {
      Globals::mouse_wheelX = 0;
    }
  }
  if (Globals::mouse_wheelY < 1) {
    if (-1 < Globals::mouse_wheelY) {
      return;
    }
    dVar1 = (double)VectorSignedToFloat(Globals::mouse_wheelY,(byte)(in_fpscr >> 0x16) & 3);
    Globals::mouse_wheelY = (int)(longlong)(dVar1 * 0.95);
    if (0 < Globals::mouse_wheelY) {
      Globals::mouse_wheelY = 0;
    }
  }
  else {
    dVar1 = (double)VectorSignedToFloat(Globals::mouse_wheelY,(byte)(in_fpscr >> 0x16) & 3);
    Globals::mouse_wheelY = (int)(longlong)(dVar1 * 0.95);
    if (Globals::mouse_wheelY < 0) {
      Globals::mouse_wheelY = 0;
    }
  }
  return;
}

// ===== MouseWheel  @0x00072e68  (136 bytes)
/* MouseWheel(float, float) */

void MouseWheel(float param_1,float param_2)

{
  byte bVar1;
  float in_r0;
  int iVar2;
  float in_r1;
  uint in_fpscr;
  uint uVar3;
  uint uVar4;
  float fVar5;
  
  uVar3 = in_fpscr & 0xfffffff;
  if ((in_r0 < -4.0) &&
     (iVar2 = AbyssEngine::ApplicationManager::GetCurrentApplicationModule(Globals::appManager),
     iVar2 == 2)) {
    Globals::keyboard_swipe = 1;
  }
  uVar3 = uVar3 & 0xfffffff | (uint)(in_r0 < 4.0) << 0x1f | (uint)(in_r0 == 4.0) << 0x1e;
  uVar4 = uVar3 | (uint)NAN(in_r0) << 0x1c;
  bVar1 = (byte)(uVar3 >> 0x18);
  if ((!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(uVar4 >> 0x1c) & 1)) &&
     (iVar2 = AbyssEngine::ApplicationManager::GetCurrentApplicationModule(Globals::appManager),
     iVar2 == 2)) {
    Globals::keyboard_swipe = 0xffffffff;
  }
  fVar5 = (float)VectorSignedToFloat(wheelStack,(byte)(uVar4 >> 0x16) & 3);
  wheelStack = (int)(in_r0 + in_r1 + fVar5);
  return;
}

// ===== MouseInput  @0x00072f04  (66 bytes)
/* MouseInput(int, int) */

void MouseInput(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = stackX;
  iVar2 = stackY;
  if ((DAT_0026b960 != 0) && (iVar1 = param_1, iVar2 = param_2, DAT_0026a088 == 0)) {
    stackX = param_1 + stackX;
    stackY = stackY + param_2;
    return;
  }
  stackY = iVar2;
  stackX = iVar1;
  return;
}

// ===== KeyboardAnimationTimer  @0x00072f60  (2 bytes)
/* KeyboardAnimationTimer(AbyssEngine::Engine*) */

Engine * KeyboardAnimationTimer(Engine *param_1)

{
  return param_1;
}

// ===== ActualizeMouseVisibilty  @0x00072f64  (606 bytes)
/* ActualizeMouseVisibilty(int) */

undefined4 ActualizeMouseVisibilty(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = DAT_00269124;
  iVar2 = DAT_002690cc;
  iVar1 = DAT_00269074;
  iVar5 = DAT_0026901c;
  if (Globals::mouseCursorActivated != 0) {
    if (((DAT_0026a094 == -1) && (Globals::isCinematicModeActive == '\0')) ||
       (iVar4 = AbyssEngine::ApplicationManager::GetCurrentApplicationModule(Globals::appManager),
       iVar4 != 2)) {
LAB_0007307a:
      Globals::mouseCursorActivated = 0;
      if (param_1 == 0) {
        if ((DAT_0026a094 == -1) || (Globals::is_hacking_visible != 0)) {
          DAT_0026a094 = 0;
        }
        else {
          DAT_0026a094 = 1;
        }
      }
      if ((((iVar5 != 0 || iVar1 != 0) || iVar2 != 0) || iVar3 != 0) ||
         (Globals::showMouseDuringGameOver != '\0')) {
        DAT_0026a094 = 0;
      }
      return 1;
    }
    if ((Globals::subMenuIndex == -1 && Globals::is_menu_visible == 0) &&
       (Globals::isStarMapVisible != '\x01')) {
      if ((Globals::is_dialogue_window_visible != 0 || Globals::is_choice_window_visible != 0) ||
          Globals::is_hacking_visible != 0) goto LAB_0007307a;
    }
    else if ((Globals::isCinematicModeActive == '\0') ||
            ((Globals::is_choice_window_visible != 0 || Globals::is_dialogue_window_visible != 0) ||
             Globals::is_hacking_visible != 0)) goto LAB_0007307a;
    if (((Globals::is_menu_visible != 0 && Globals::isCinematicModeActive == '\0') ||
        (Globals::isStarMapVisible != '\0' || param_1 != 0)) ||
       ((Globals::showMouseDuringGameOver != '\0' ||
        ((((iVar5 != 0 || iVar1 != 0) || iVar2 != 0) || iVar3 != 0 &&
         (iVar4 = AbyssEngine::ApplicationManager::GetCurrentApplicationModule(Globals::appManager),
         iVar4 == 2)))))) goto LAB_0007307a;
    if (Globals::mouseCursorActivated != 0) goto LAB_00073192;
  }
  if (((DAT_0026a094 == 1) || (Globals::isCinematicModeActive != '\0')) &&
     ((Globals::isCinematicModeActive != '\0' ||
      (((((iVar5 = AbyssEngine::ApplicationManager::GetCurrentApplicationModule(Globals::appManager)
          , iVar5 == 2 && (Globals::subMenuIndex == -1)) && (Globals::is_menu_visible == 0)) &&
        ((Globals::isStarMapVisible == '\0' &&
         (Globals::is_dialogue_window_visible == 0 && Globals::is_choice_window_visible == 0)))) &&
       ((Globals::is_hacking_visible == 0 && (Globals::isCinematicModeActive == '\0')))))))) {
    Globals::mouseCursorActivated = 1;
    DAT_0026a094 = (int)((uint)(Globals::isCinematicModeActive != '\0' && DAT_0026a094 != 1) << 0x1f
                        ) >> 0x1f;
    return 0xffffffff;
  }
LAB_00073192:
  if ((DAT_0026a094 != 0) &&
     (iVar5 = AbyssEngine::ApplicationManager::GetCurrentApplicationModule(Globals::appManager),
     iVar5 == 5)) {
    if (*(char *)(Globals::keyBindings + 4) != '\0') {
      DAT_0026a094 = 0;
    }
    return 0;
  }
  return 0;
}

// ===== simulateTouch  @0x00073278  (2126 bytes)
/* simulateTouch(AbyssEngine::Engine*) */

void simulateTouch(Engine *param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  ApplicationManager *this;
  uint uVar5;
  char cVar6;
  byte bVar7;
  uint in_fpscr;
  uint uVar8;
  uint uVar9;
  float fVar10;
  undefined8 in_d0;
  uint extraout_s1;
  ulonglong uVar11;
  float fVar12;
  ulonglong in_d1;
  uint extraout_s3;
  undefined4 uVar15;
  undefined4 uVar16;
  ulonglong uVar13;
  undefined8 uVar14;
  float fVar17;
  longlong in_d2;
  uint extraout_s5;
  undefined8 in_d3;
  undefined4 uVar18;
  undefined4 extraout_s7;
  undefined4 in_s9;
  undefined4 extraout_s9;
  undefined8 unaff_d8;
  undefined8 uVar19;
  undefined8 uVar20;
  
  uVar8 = (uint)((ulonglong)in_d0 >> 0x20);
  uVar18 = (undefined4)((ulonglong)in_d3 >> 0x20);
  if (Globals::keys._188_4_ != 0) {
    AbyssEngine::Engine::EnablePostEffect = AbyssEngine::Engine::EnablePostEffect ^ 1;
  }
  if (DAT_0026c97c == '\0') {
    Globals::left_edge = 10;
    iVar3 = AbyssEngine::Engine::GetDisplayWidth(param_1);
    Globals::right_edge = iVar3 + -10;
    Globals::top_edge = 10;
    iVar3 = AbyssEngine::Engine::GetDisplayHeight(param_1);
    in_d2 = (ulonglong)extraout_s5 << 0x20;
    in_d1 = (ulonglong)extraout_s3 << 0x20;
    Globals::bottom_edge = iVar3 + -10;
    DAT_0026c97c = '\x01';
    in_s9 = extraout_s9;
    uVar18 = extraout_s7;
    uVar8 = extraout_s1;
  }
  if (Globals::resetKeyboard != 0) {
    Globals::resetKeyboard = 0;
    stackX = 0;
    stackY = 0;
    DAT_0026a098 = 0.5;
    DAT_0026a09c = 0.5;
  }
  if (DAT_002692dc != 0) {
    *(undefined4 *)(param_1 + 0x350) = 0xbf800000;
  }
  if (DAT_00269334 != 0) {
    *(undefined4 *)(param_1 + 0x350) = 0x3f800000;
  }
  uVar15 = (undefined4)(in_d1 >> 0x20);
  if (DAT_002693e4 == 0) {
    if (DAT_0026943c != 0) {
      in_d1 = CONCAT44(uVar15,0x41a00000);
      Globals::rotateShipInStation = 40.0;
      iVar3 = DAT_00269494;
      goto LAB_000733ac;
    }
    if (DAT_00269494 == 0) {
      if (DAT_002694ec != 0) {
        Globals::rotateShipInStation = -20.0;
      }
    }
    else {
      Globals::rotateShipInStation = 20.0;
    }
  }
  else {
    in_d1 = CONCAT44(uVar15,0xc1a00000);
    Globals::rotateShipInStation = -40.0;
    iVar3 = DAT_002694ec;
LAB_000733ac:
    if (iVar3 == 0) {
      Globals::rotateShipInStation = (float)in_d1;
    }
  }
  uVar5 = Globals::is_menu_visible;
  if (Globals::is_dialogue_window_visible != 0 || Globals::is_choice_window_visible != 0) {
    uVar5 = Globals::is_menu_visible | 1;
  }
  if (uVar5 == 0) {
    uVar15 = (undefined4)(in_d1 >> 0x20);
    fVar10 = (float)VectorSignedToFloat(wheelStack,(byte)(in_fpscr >> 0x16) & 3);
    Globals::rotateShipInStation = Globals::rotateShipInStation + fVar10;
    in_d2 = CONCAT44((int)((ulonglong)in_d2 >> 0x20),0x42200000);
    in_fpscr = in_fpscr & 0xfffffff;
    uVar5 = in_fpscr | (uint)(Globals::rotateShipInStation < 40.0) << 0x1f |
            (uint)(Globals::rotateShipInStation == 40.0) << 0x1e;
    uVar9 = uVar5 | (uint)NAN(Globals::rotateShipInStation) << 0x1c;
    wheelStack = (int)(fVar10 * 0.9);
    in_d1 = CONCAT44(uVar15,wheelStack);
    bVar7 = (byte)(uVar5 >> 0x18);
    if ((bool)(bVar7 >> 6 & 1) || bVar7 >> 7 != ((byte)(uVar9 >> 0x1c) & 1)) {
      in_d1 = CONCAT44(uVar15,0xc2200000);
      if (Globals::rotateShipInStation < -40.0) {
        Globals::rotateShipInStation = -40.0;
      }
    }
    else {
      Globals::rotateShipInStation = 40.0;
      in_fpscr = uVar9;
    }
  }
  else {
    wheelStack = 0;
    Globals::rotateShipInStation = 0.0;
  }
  if (DAT_002693e4 == 0 && DAT_00269544 == 0) {
    if (DAT_0026959c == 0 && DAT_0026943c == 0) {
      Globals::translateStarMapInXDirection = 0;
    }
    else {
      Globals::translateStarMapInXDirection = 0xc1200000;
    }
  }
  else {
    Globals::translateStarMapInXDirection = 0x41200000;
  }
  if (DAT_002695f4 == 0 && DAT_00269494 == 0) {
    if (DAT_0026964c == 0 && DAT_002694ec == 0) {
      Globals::translateStarMapInYDirection = 0;
    }
    else {
      Globals::translateStarMapInYDirection = 0x41200000;
    }
  }
  else {
    Globals::translateStarMapInYDirection = 0xc1200000;
  }
  if (DAT_0026b960 == 0) {
    uVar11 = CONCAT44(uVar8,DAT_0026a098);
  }
  else {
    if ((int)stackX < 0) {
      bVar1 = false;
      DAT_0026a098 = 0.0;
    }
    else if (stackX == 0) {
      bVar1 = false;
    }
    else {
      DAT_0026a098 = 1.0;
      bVar1 = true;
    }
    if ((int)stackY < 0) {
      bVar2 = false;
      DAT_0026a09c = 0.0;
    }
    else if (stackY == 0) {
      bVar2 = false;
    }
    else {
      DAT_0026a09c = 1.0;
      bVar2 = true;
    }
    if (bVar1) {
      stackX = stackX - 1;
    }
    else if (0x7fffffff < stackX) {
      stackX = stackX + 1;
    }
    if (bVar2) {
      stackY = stackY - 1;
    }
    else if (0x7fffffff < stackY) {
      stackY = stackY + 1;
    }
    in_d1 = CONCAT44((int)(in_d1 >> 0x20),0x3f800000);
    uVar5 = in_fpscr & 0xfffffff;
    uVar9 = uVar5 | (uint)(DAT_0026a098 < 1.0) << 0x1f | (uint)(DAT_0026a098 == 1.0) << 0x1e;
    bVar7 = (byte)(uVar9 >> 0x18);
    if ((bool)(bVar7 >> 6 & 1) || (bool)(bVar7 >> 7) != NAN(DAT_0026a098)) {
      uVar11 = CONCAT44(uVar8,DAT_0026a098);
      if (DAT_0026a098 < 0.0) {
        DAT_0026a098 = 0.0;
        uVar11 = (ulonglong)uVar8 << 0x20;
      }
    }
    else {
      DAT_0026a098 = 1.0;
      uVar5 = uVar9;
      uVar11 = in_d1;
    }
    in_d2 = CONCAT44((int)((ulonglong)in_d2 >> 0x20),DAT_0026a09c);
    in_fpscr = uVar5 & 0xfffffff;
    uVar8 = in_fpscr | (uint)(DAT_0026a09c < 1.0) << 0x1f | (uint)(DAT_0026a09c == 1.0) << 0x1e;
    uVar5 = uVar8 | (uint)NAN(DAT_0026a09c) << 0x1c;
    bVar7 = (byte)(uVar8 >> 0x18);
    if ((bool)(bVar7 >> 6 & 1) || bVar7 >> 7 != ((byte)(uVar5 >> 0x1c) & 1)) {
      if (DAT_0026a09c < 0.0) {
        DAT_0026a09c = 0.0;
      }
    }
    else {
      DAT_0026a09c = 1.0;
      in_fpscr = uVar5;
    }
  }
  uVar16 = (undefined4)(in_d1 >> 0x20);
  uVar13 = CONCAT44(uVar16,DAT_0026a08c);
  uVar8 = in_fpscr & 0xfffffff;
  fVar10 = (float)uVar11;
  uVar15 = (undefined4)(uVar11 >> 0x20);
  uVar5 = uVar8;
  if (DAT_0026a08c == 0.5) {
    uVar13 = CONCAT44(uVar16,0x3f000000);
    bVar7 = (byte)(((uint)(fVar10 == 0.5) << 0x1e) >> 0x18);
    cVar6 = -((char)((byte)(uVar8 >> 0x18) | (byte)(((uint)(fVar10 < 0.5) << 0x1f) >> 0x18) | bVar7)
             >> 7);
    if ((bool)(bVar7 >> 6) || (bool)cVar6 != NAN(fVar10)) {
      if (cVar6 != '\0') {
        fVar12 = 0.05;
        goto LAB_000736f0;
      }
    }
    else {
      fVar12 = -0.05;
LAB_000736f0:
      DAT_0026a098 = fVar10 + fVar12;
      uVar11 = CONCAT44(uVar15,DAT_0026a098);
    }
    fVar10 = (float)uVar11;
    uVar9 = uVar8 | (uint)(fVar10 < 0.4) << 0x1f | (uint)(fVar10 == 0.4) << 0x1e;
    uVar5 = uVar9 | (uint)NAN(fVar10) << 0x1c;
    bVar7 = (byte)(uVar9 >> 0x18);
    if ((!(bool)(bVar7 >> 6 & 1) && bVar7 >> 7 == ((byte)(uVar5 >> 0x1c) & 1)) &&
       (uVar5 = uVar8, fVar10 < 0.6)) {
      DAT_0026a098 = 0.5;
      uVar11 = uVar13;
    }
  }
  else {
    in_d2 = CONCAT44((int)((ulonglong)in_d2 >> 0x20),0x3f800000);
    uVar11 = FloatVectorMin(CONCAT44(uVar15,DAT_0026a08c + fVar10),in_d2,2,0x20);
    DAT_0026a098 = (float)uVar11;
    if (DAT_0026a098 < 0.0) {
      DAT_0026a098 = 0.0;
      uVar11 = uVar11 & 0xffffffff00000000;
    }
  }
  uVar15 = (undefined4)(uVar13 >> 0x20);
  uVar5 = uVar5 & 0xfffffff;
  uVar8 = uVar5;
  if (DAT_0026a090 == 0.5) {
    bVar7 = (byte)(((uint)(DAT_0026a09c == 0.5) << 0x1e) >> 0x18);
    cVar6 = -((char)((byte)(uVar5 >> 0x18) | (byte)(((uint)(DAT_0026a09c < 0.5) << 0x1f) >> 0x18) |
                    bVar7) >> 7);
    if ((bool)(bVar7 >> 6) || (bool)cVar6 != NAN(DAT_0026a09c)) {
      if (cVar6 != '\0') {
        fVar10 = 0.05;
        goto LAB_000737a2;
      }
    }
    else {
      fVar10 = -0.05;
LAB_000737a2:
      DAT_0026a09c = DAT_0026a09c + fVar10;
    }
    uVar13 = CONCAT44(uVar15,DAT_0026a09c);
    uVar9 = uVar5 | (uint)(DAT_0026a09c < 0.4) << 0x1f | (uint)(DAT_0026a09c == 0.4) << 0x1e;
    uVar8 = uVar9 | (uint)NAN(DAT_0026a09c) << 0x1c;
    bVar7 = (byte)(uVar9 >> 0x18);
    if ((!(bool)(bVar7 >> 6 & 1) && bVar7 >> 7 == ((byte)(uVar8 >> 0x1c) & 1)) &&
       (uVar8 = uVar5, DAT_0026a09c < 0.6)) {
      DAT_0026a09c = 0.5;
      uVar13 = CONCAT44((int)((ulonglong)unaff_d8 >> 0x20),0x3f000000);
    }
  }
  else {
    uVar13 = FloatVectorMin(CONCAT44(uVar15,DAT_0026a090 + DAT_0026a09c),CONCAT44(uVar18,0x3f800000)
                            ,2,0x20);
    DAT_0026a09c = (float)uVar13;
    if (DAT_0026a09c < 0.0) {
      DAT_0026a09c = 0.0;
      uVar13 = uVar13 & 0xffffffff00000000;
    }
  }
  if (DAT_0026b960 != 0) {
    fVar10 = ABS((float)uVar11);
    fVar12 = ABS((float)uVar13);
    uVar8 = uVar8 & 0xfffffff;
    uVar5 = uVar8 | (uint)(fVar10 < 500.0) << 0x1f | (uint)(fVar10 == 500.0) << 0x1e;
    uVar9 = uVar5 | (uint)NAN(fVar10) << 0x1c;
    bVar7 = (byte)(uVar5 >> 0x18);
    iVar3 = (int)fVar10;
    if ((bool)(bVar7 >> 6 & 1) || bVar7 >> 7 != ((byte)(uVar9 >> 0x1c) & 1)) {
      iVar3 = 500;
    }
    fVar10 = (float)VectorSignedToFloat(iVar3,(byte)(uVar9 >> 0x16) & 3);
    uVar5 = uVar8 | (uint)(fVar12 < fVar10) << 0x1f | (uint)(fVar12 == fVar10) << 0x1e;
    uVar9 = uVar5 | (uint)(NAN(fVar12) || NAN(fVar10)) << 0x1c;
    bVar7 = (byte)(uVar5 >> 0x18);
    iVar4 = (int)fVar12;
    if ((bool)(bVar7 >> 6 & 1) || bVar7 >> 7 != ((byte)(uVar9 >> 0x1c) & 1)) {
      iVar4 = iVar3;
    }
    fVar10 = (float)VectorSignedToFloat(iVar4,(byte)(uVar9 >> 0x16) & 3);
    fVar12 = (float)VectorSignedToFloat(stackX,(byte)(uVar9 >> 0x16) & 3);
    fVar17 = (float)VectorSignedToFloat(stackY,(byte)(uVar9 >> 0x16) & 3);
    uVar20 = CONCAT44((int)(uVar11 >> 0x20),0x3f800000);
    uVar14 = CONCAT44((int)(uVar13 >> 0x20),0xbf800000);
    uVar19 = FloatVectorMin(CONCAT44(in_s9,fVar12 / fVar10),uVar20,2,0x20);
    uVar20 = FloatVectorMin(CONCAT44((int)((ulonglong)in_d2 >> 0x20),fVar17 / (fVar10 * 0.5)),uVar20
                            ,2,0x20);
    uVar19 = FloatVectorMax(uVar19,uVar14,2,0x20);
    uVar20 = FloatVectorMax(uVar20,uVar14,2,0x20);
    fVar10 = (float)uVar19;
    if (fVar10 <= 0.0) {
      fVar10 = -(1.0 - (fVar10 + 1.0) * (fVar10 + 1.0));
    }
    else {
      fVar10 = 1.0 - (fVar10 + -1.0) * (fVar10 + -1.0);
    }
    fVar12 = (float)uVar20;
    if (fVar12 <= 0.0) {
      fVar12 = -(1.0 - (fVar12 + 1.0) * (fVar12 + 1.0));
    }
    else {
      fVar12 = 1.0 - (fVar12 + -1.0) * (fVar12 + -1.0);
    }
    DAT_0026a098 = fVar10 + 0.5;
    DAT_0026a09c = fVar12 + 0.5;
    if (DAT_0026a098 < 0.0) {
      DAT_0026a098 = 0.0;
    }
    if (DAT_0026a09c < 0.0) {
      DAT_0026a09c = 0.0;
    }
    if (1.0 < DAT_0026a098) {
      DAT_0026a098 = 1.0;
    }
    uVar5 = uVar8 | (uint)(DAT_0026a09c < 1.0) << 0x1f | (uint)(DAT_0026a09c == 1.0) << 0x1e;
    uVar8 = uVar5 | (uint)NAN(DAT_0026a09c) << 0x1c;
    bVar7 = (byte)(uVar5 >> 0x18);
    if (!(bool)(bVar7 >> 6 & 1) && bVar7 >> 7 == ((byte)(uVar8 >> 0x1c) & 1)) {
      DAT_0026a09c = 1.0;
    }
  }
  if (DAT_0026b964 != 0) {
    DAT_0026a098 = DAT_0026a0a0;
    DAT_0026a09c = DAT_0026a0a4;
  }
  iVar3 = AbyssEngine::ApplicationManager::GetCurrentApplicationModule(Globals::appManager);
  if (iVar3 == 2) {
    fVar10 = (float)VectorSignedToFloat(Globals::smallButton_dim,(byte)(uVar8 >> 0x16) & 3);
    fVar12 = (float)VectorSignedToFloat(Globals::touch_stick_y,(byte)(uVar8 >> 0x16) & 3);
    fVar17 = (float)VectorSignedToFloat(Globals::touch_stick_x,(byte)(uVar8 >> 0x16) & 3);
    if ((DAT_0026c980 != 0) ||
       (DAT_0026b960 != 0 ||
        (((DAT_0026901c != 0 || DAT_00269074 != 0) || DAT_002690cc != 0) || DAT_00269124 != 0))) {
      fVar12 = (fVar12 - fVar10) + (fVar10 + fVar10) * DAT_0026a09c;
      fVar10 = (fVar17 - fVar10) + (fVar10 + fVar10) * DAT_0026a098;
      if (((DAT_0026b960 == 0 &&
           (((DAT_0026901c == 0 && DAT_00269074 == 0) && DAT_002690cc == 0) && DAT_00269124 == 0)) &
          DAT_0026c980) == 1) {
        this = *(ApplicationManager **)(param_1 + 0x28);
        uVar5 = uVar8 & 0xfffffff;
        uVar8 = uVar5 | (uint)(DAT_0026a098 == 0.5) << 0x1e;
        bVar7 = 0;
        if ((byte)(uVar8 >> 0x1e) != 0) {
          uVar8 = uVar5 | (uint)(DAT_0026a09c == 0.5) << 0x1e;
          bVar7 = (byte)(uVar8 >> 0x1e);
        }
        if (bVar7 != 0) {
          AbyssEngine::ApplicationManager::OnTouchEnd(this,(int)fVar10,(int)fVar12,(void *)0xe8b);
          DAT_0026c980 = 0;
          goto LAB_00073a94;
        }
      }
      else {
        if (((DAT_0026b960 != 0 ||
             (((DAT_0026901c != 0 || DAT_00269074 != 0) || DAT_002690cc != 0) || DAT_00269124 != 0))
            & DAT_0026c980) != 1) {
          if (((DAT_0026c980 ^ 1) &
              (DAT_0026b960 != 0 ||
              (((DAT_0026901c != 0 || DAT_00269074 != 0) || DAT_002690cc != 0) || DAT_00269124 != 0)
              )) == 1) {
            AbyssEngine::ApplicationManager::OnTouchBegin
                      (*(ApplicationManager **)(param_1 + 0x28),(int)fVar10,(int)fVar12,
                       (void *)0xe8b);
            AbyssEngine::ApplicationManager::OnTouchMove
                      (*(ApplicationManager **)(param_1 + 0x28),(int)fVar10,(int)fVar12,
                       (void *)0xe8b);
            DAT_0026c980 = 1;
          }
          goto LAB_00073a94;
        }
        this = *(ApplicationManager **)(param_1 + 0x28);
      }
      AbyssEngine::ApplicationManager::OnTouchMove(this,(int)fVar10,(int)fVar12,(void *)0xe8b);
    }
  }
LAB_00073a94:
  if (DAT_0026a088 == 0) {
    fVar10 = (float)VectorSignedToFloat(stackX,(byte)(uVar8 >> 0x16) & 3);
    stackX = (uint)(fVar10 * 0.96);
    fVar10 = (float)VectorSignedToFloat(stackY,(byte)(uVar8 >> 0x16) & 3);
    stackY = (uint)(fVar10 * 0.96);
  }
  return;
}

// ===== SlowMotion  @0x00073cb8  (8 bytes)
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* SlowMotion() */

undefined1 SlowMotion(void)

{
  return DAT_0026c978;
}

// ===== SpeedUp  @0x00073cc4  (8 bytes)
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* SpeedUp() */

undefined1 SpeedUp(void)

{
  return DAT_0026c974;
}

// ===== setValuesForGamepad  @0x00073cd0  (14 bytes)
/* setValuesForGamepad(float, float) */

void setValuesForGamepad(float param_1,float param_2)

{
  undefined4 in_r0;
  undefined4 in_r1;
  
  DAT_0026a0a0 = in_r0;
  DAT_0026a0a4 = in_r1;
  return;
}

// ===== opensubkeyfile  @0x00073ce8  (40 bytes)
undefined4 opensubkeyfile(void)

{
  undefined4 uVar1;
  
  SubkeyFile = fopen("Blowfish.dat","rb");
  uVar1 = 0;
  if (SubkeyFile == (FILE *)0x0) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

// ===== F  @0x00073d1c  (54 bytes)
int F(uint param_1)

{
  return (*(uint *)(S + ((param_1 & 0xffff) >> 8) * 4 + 0x800) ^
         *(int *)(S + (param_1 >> 0x18) * 4) +
         *(int *)(S + ((param_1 & 0xffffff) >> 0x10) * 4 + 0x400)) +
         *(int *)(S + (param_1 & 0xff) * 4 + 0xc00);
}

// ===== Blowfish_encipher  @0x00073d58  (120 bytes)
void Blowfish_encipher(uint *param_1,uint *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = P._64_4_;
  iVar3 = 0;
  uVar5 = *param_1;
  uVar4 = *param_2;
  do {
    iVar1 = iVar3 * 4;
    iVar3 = iVar3 + 1;
    uVar6 = *(uint *)(P + iVar1) ^ uVar5;
    uVar5 = (*(uint *)(S + ((uVar6 & 0xffff) >> 8) * 4 + 0x800) ^
            *(int *)(S + ((uVar6 & 0xffffff) >> 0x10) * 4 + 0x400) +
            *(int *)(S + (uVar6 >> 0x18) * 4)) + *(int *)(S + (uVar6 & 0xff) * 4 + 0xc00) ^ uVar4;
    uVar4 = uVar6;
  } while (iVar3 != 0x10);
  *param_1 = P._68_4_ ^ uVar6;
  *param_2 = uVar2 ^ uVar5;
  return;
}

// ===== Blowfish_decipher  @0x00073ddc  (120 bytes)
void Blowfish_decipher(uint *param_1,uint *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = P._4_4_;
  iVar3 = 0x11;
  uVar5 = *param_1;
  uVar4 = *param_2;
  do {
    iVar1 = iVar3 * 4;
    iVar3 = iVar3 + -1;
    uVar6 = *(uint *)(P + iVar1) ^ uVar5;
    uVar5 = (*(uint *)(S + ((uVar6 & 0xffff) >> 8) * 4 + 0x800) ^
            *(int *)(S + ((uVar6 & 0xffffff) >> 0x10) * 4 + 0x400) +
            *(int *)(S + (uVar6 >> 0x18) * 4)) + *(int *)(S + (uVar6 & 0xff) * 4 + 0xc00) ^ uVar4;
    uVar4 = uVar6;
  } while (1 < iVar3);
  *param_1 = P._0_4_ ^ uVar6;
  *param_2 = uVar2 ^ uVar5;
  return;
}

// ===== InitializeBlowfish  @0x00073e60  (452 bytes)
void InitializeBlowfish(int param_1,int param_2)

{
  short sVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  short sVar7;
  uint *puVar8;
  undefined4 local_34;
  undefined4 local_30;
  uint local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  SubkeyFile = fopen("Blowfish.dat","rb");
  if (SubkeyFile == (FILE *)0x0) {
    FUN_001d652c("Unable to open subkey initialization file : %d\n",0xffffffff);
  }
  else {
    sVar2 = fread(&local_2c,4,1,SubkeyFile);
    if ((sVar2 & 0xffff) == 1) {
      iVar4 = 0;
      do {
        *(uint *)(P + iVar4 * 4) = local_2c;
        iVar4 = iVar4 + 1;
        if (0x11 < iVar4) {
          iVar4 = 0;
          puVar6 = S;
          do {
            iVar5 = 0;
            puVar8 = (uint *)puVar6;
            do {
              sVar2 = fread(&local_2c,4,1,SubkeyFile);
              if ((sVar2 & 0xffff) != 1) goto LAB_0007400a;
              iVar5 = iVar5 + 1;
              *puVar8 = local_2c;
              puVar8 = puVar8 + 1;
            } while (iVar5 < 0x100);
            puVar6 = (undefined1 *)((int)puVar6 + 0x400);
            iVar4 = iVar4 + 1;
          } while (iVar4 < 4);
          fclose(SubkeyFile);
          iVar4 = 0;
          iVar5 = 0;
          do {
            local_2c = 0;
            sVar7 = 0;
            do {
              sVar1 = (short)iVar5;
              iVar5 = sVar1 + 1;
              sVar7 = sVar7 + 1;
              local_2c = (uint)*(byte *)(param_1 + sVar1) | local_2c << 8;
              if (param_2 <= (short)iVar5) {
                iVar5 = 0;
              }
            } while (sVar7 < 4);
            *(uint *)(P + iVar4 * 4) = *(uint *)(P + iVar4 * 4) ^ local_2c;
            iVar4 = iVar4 + 1;
          } while (iVar4 != 0x12);
          iVar4 = 0;
          local_34 = 0;
          local_30 = 0;
          do {
            Blowfish_encipher(&local_30,&local_34);
            *(undefined4 *)(P + iVar4 * 4) = local_30;
            *(undefined4 *)(P + iVar4 * 4 + 4) = local_34;
            iVar5 = iVar4 * 0x10000 + 0x20000;
            iVar4 = iVar5 >> 0x10;
          } while (iVar5 < 0x120000);
          iVar4 = 0;
          do {
            iVar5 = 0;
            do {
              Blowfish_encipher(&local_30,&local_34);
              *(undefined4 *)(S + iVar5 * 4 + iVar4 * 0x400) = local_30;
              *(undefined4 *)(S + iVar5 * 4 + iVar4 * 0x400 + 4) = local_34;
              iVar3 = iVar5 * 0x10000 + 0x20000;
              iVar5 = iVar3 >> 0x10;
            } while (iVar3 < 0x1000000);
            iVar4 = iVar4 + 1;
          } while (iVar4 != 4);
          break;
        }
        sVar2 = fread(&local_2c,4,1,SubkeyFile);
      } while ((sVar2 & 0xffff) == 1);
    }
  }
LAB_0007400a:
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

// ===== JNI_OnLoad  @0x0007405c  (96 bytes)
void JNI_OnLoad(int *param_1)

{
  int iVar1;
  int *local_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_18 = (int *)0x0;
  g_pVM = param_1;
  iVar1 = (**(code **)(*param_1 + 0x18))(param_1,&local_18,0x10004);
  if (iVar1 == 0) {
    (**(code **)(*local_18 + 0x18))(local_18,"net/fishlabs/gof2hdallandroid2012/GOF2HD2012");
  }
  if (__stack_chk_guard - local_14 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_14);
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_ToJNI_setEnvironmentVariables  @0x000740cc  (40 bytes)
void Java_net_fishlabs_gof2hdallandroid2012_ToJNI_setEnvironmentVariables
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  g_pClass = param_2;
  g_pEnv = param_1;
  g_pActivity = param_3;
  return;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_ToJNI_setAPKPath  @0x00074100  (104 bytes)
void Java_net_fishlabs_gof2hdallandroid2012_ToJNI_setAPKPath
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  char *__s;
  size_t sVar1;
  char cStack_19;
  int local_18;
  
  local_18 = __stack_chk_guard;
  __s = (char *)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,&cStack_19);
  sVar1 = strlen(__s);
  ndk_APK_Path = malloc(sVar1 + 1);
  if (cStack_19 != '\0') {
    strcpy(ndk_APK_Path,__s);
    (**(code **)(*param_1 + 0x2a8))(param_1,param_3,__s);
  }
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_ToJNI_setZIPPath  @0x00074174  (104 bytes)
void Java_net_fishlabs_gof2hdallandroid2012_ToJNI_setZIPPath
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  char *__s;
  size_t sVar1;
  char cStack_19;
  int local_18;
  
  local_18 = __stack_chk_guard;
  __s = (char *)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,&cStack_19);
  sVar1 = strlen(__s);
  ndk_ZIP_Path = malloc(sVar1 + 1);
  if (cStack_19 != '\0') {
    strcpy(ndk_ZIP_Path,__s);
    (**(code **)(*param_1 + 0x2a8))(param_1,param_3,__s);
  }
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_ToJNI_setCountryCodeOfDevice  @0x000741e8  (8 bytes)
void Java_net_fishlabs_gof2hdallandroid2012_ToJNI_setCountryCodeOfDevice
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  ndk23_setCountryCode(param_3);
  return;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_ToJNI_SetDirectories  @0x000741f0  (280 bytes)
void Java_net_fishlabs_gof2hdallandroid2012_ToJNI_SetDirectories
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  size_t sVar2;
  char *__dest;
  char cStack_2a;
  char cStack_29;
  int local_28;
  
  local_28 = __stack_chk_guard;
  pcVar1 = (char *)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,&cStack_29);
  sVar2 = strlen(pcVar1);
  __dest = malloc(sVar2 + 1);
  dataDirectory = __dest;
  flstat_rootPath = malloc(sVar2 + 1);
  if (cStack_29 != '\0') {
    strcpy(__dest,pcVar1);
    strcpy(flstat_rootPath,pcVar1);
    ndk23_setRootDirectory(dataDirectory);
    __android_log_print(6,"GOF2_NATIVE","dataDirectory in main.c: %s",dataDirectory);
    __android_log_print(6,"GOF2_NATIVE","rootPath in main.c: %s",flstat_rootPath);
    (**(code **)(*param_1 + 0x2a8))(param_1,param_3,pcVar1);
  }
  pcVar1 = (char *)(**(code **)(*param_1 + 0x2a4))(param_1,param_4,&cStack_2a);
  sVar2 = strlen(pcVar1);
  zipDirectory = malloc(sVar2 + 1);
  if (cStack_2a != '\0') {
    strcpy(zipDirectory,pcVar1);
    ndk23_setZipDirectory(zipDirectory);
    __android_log_print(6,"GOF2_NATIVE","zipDirectory in main.c: %s",zipDirectory);
    (**(code **)(*param_1 + 0x2a8))(param_1,param_4,pcVar1);
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_ToJNI_initialize  @0x0007433c  (52 bytes)
undefined4
Java_net_fishlabs_gof2hdallandroid2012_ToJNI_initialize
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ndk23_InitWithZip(ndk_APK_Path,ndk_ZIP_Path,param_3,param_4,0x3f800000);
  ndk23_setDisplayHeightAndWidth(param_3,param_4);
  return 0;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_ToJNI_renderstep  @0x00074378  (10 bytes)
void Java_net_fishlabs_gof2hdallandroid2012_ToJNI_renderstep
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ndk23_newrender(param_3,param_4);
  return;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_ToJNI_resetScreenshotFlag  @0x00074388  (12 bytes)
undefined4 Java_net_fishlabs_gof2hdallandroid2012_ToJNI_resetScreenshotFlag(void)

{
  ndk23_resetScreenshotFlag();
  return 0;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_ToJNI_STARTUP  @0x0007439c  (2 bytes)
void Java_net_fishlabs_gof2hdallandroid2012_ToJNI_STARTUP(void)

{
  return;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_ToJNI_handleAccelerometer  @0x0007439e  (18 bytes)
void Java_net_fishlabs_gof2hdallandroid2012_ToJNI_handleAccelerometer
               (undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4,
               undefined4 param_5)

{
  ndk23_handleAcceleration(param_3 ^ 0x80000000,param_4,param_5);
  return;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_ToJNI_resize  @0x000743ae  (10 bytes)
void Java_net_fishlabs_gof2hdallandroid2012_ToJNI_resize
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ndk23_resize(param_3,param_4);
  return;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_ToJNI_handleTouchEvent  @0x000743b6  (24 bytes)
void Java_net_fishlabs_gof2hdallandroid2012_ToJNI_handleTouchEvent
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  (*(code *)&LAB_00067d54)(param_3,param_4,param_5,param_6);
  return;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_ToJNI_correctBoughtDLC1  @0x000743e0  (8 bytes)
void Java_net_fishlabs_gof2hdallandroid2012_ToJNI_correctBoughtDLC1(void)

{
  ndk_iapBoughtPremium(0,1);
  return;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_ToJNI_correctBoughtDLC2  @0x000743e8  (8 bytes)
void Java_net_fishlabs_gof2hdallandroid2012_ToJNI_correctBoughtDLC2(void)

{
  ndk_iapBoughtPremium(1,1);
  return;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_ToJNI_correctBoughtDLC3  @0x000743f0  (8 bytes)
void Java_net_fishlabs_gof2hdallandroid2012_ToJNI_correctBoughtDLC3(void)

{
  ndk_iapBoughtPremium(2,1);
  return;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_ToJNI_correctBoughtDLC4  @0x000743f8  (8 bytes)
void Java_net_fishlabs_gof2hdallandroid2012_ToJNI_correctBoughtDLC4(void)

{
  ndk_iapBoughtPremium(3,1);
  return;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_ToJNI_correctBoughtDLC5  @0x00074400  (8 bytes)
void Java_net_fishlabs_gof2hdallandroid2012_ToJNI_correctBoughtDLC5(void)

{
  ndk_iapBoughtPremium(4,1);
  return;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_ToJNI_testPurchase  @0x00074408  (6 bytes)
void Java_net_fishlabs_gof2hdallandroid2012_ToJNI_testPurchase(void)

{
  ndk_iapBoughtConsumable(0);
  return;
}

// ===== decrypt  @0x0007440e  (2 bytes)
int decrypt(EVP_PKEY_CTX *ctx,uchar *out,size_t *outlen,uchar *in,size_t inlen)

{
  return (int)ctx;
}

// ===== Java_net_fishlabs_googleplay_ToJNI_gof2hd2012apk  @0x00074410  (12 bytes)
void Java_net_fishlabs_googleplay_ToJNI_gof2hd2012apk(int *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0007441a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x29c))(param_1,&UNK_0021f441);
  return;
}

// ===== Java_net_fishlabs_googleplay_ToJNI_gof2hd2012getPremiumSKU  @0x00074420  (72 bytes)
void Java_net_fishlabs_googleplay_ToJNI_gof2hd2012getPremiumSKU
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  switch(param_3) {
  case 0:
                    /* WARNING: Could not recover jumptable at 0x0007443c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x29c))(param_1,"iap_managed_valkyrie");
    return;
  case 1:
                    /* WARNING: Could not recover jumptable at 0x00074448. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x29c))(param_1,"iap_managed_kaamo_club");
    return;
  case 2:
                    /* WARNING: Could not recover jumptable at 0x00074454. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x29c))(param_1,"iap_managed_supernova");
    return;
  case 3:
                    /* WARNING: Could not recover jumptable at 0x00074460. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x29c))(param_1,"iap_managed_vip");
    return;
  case 4:
                    /* WARNING: Could not recover jumptable at 0x0007446c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x29c))(param_1,"iap_managed_full_package");
    return;
  default:
    return;
  }
}

// ===== Java_net_fishlabs_googleplay_ToJNI_gof2hd2012getConsumableSKU  @0x00074484  (72 bytes)
void Java_net_fishlabs_googleplay_ToJNI_gof2hd2012getConsumableSKU
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  switch(param_3) {
  case 0:
                    /* WARNING: Could not recover jumptable at 0x000744a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x29c))(param_1,"iap_managed_credits_100_000");
    return;
  case 1:
                    /* WARNING: Could not recover jumptable at 0x000744ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x29c))(param_1,"iap_managed_credits_300_000");
    return;
  case 2:
                    /* WARNING: Could not recover jumptable at 0x000744b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x29c))(param_1,"iap_managed_credits_1_000_000");
    return;
  case 3:
                    /* WARNING: Could not recover jumptable at 0x000744c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x29c))(param_1,"iap_managed_credits_3_000_000");
    return;
  case 4:
                    /* WARNING: Could not recover jumptable at 0x000744d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x29c))(param_1,"iap_managed_10_000_000");
    return;
  default:
    return;
  }
}

// ===== Java_net_fishlabs_googleplay_ToJNI_iapBoughtPremium  @0x000744e8  (10 bytes)
void Java_net_fishlabs_googleplay_ToJNI_iapBoughtPremium
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ndk_iapBoughtPremium(param_3,param_4);
  return;
}

// ===== Java_net_fishlabs_googleplay_ToJNI_iapBoughtConsumable  @0x000744f0  (8 bytes)
void Java_net_fishlabs_googleplay_ToJNI_iapBoughtConsumable
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  ndk_iapBoughtConsumable(param_3);
  return;
}

// ===== Java_net_fishlabs_tapjoy_ToJNI_spentAmountOfCredits  @0x00074500  (14 bytes)
void Java_net_fishlabs_tapjoy_ToJNI_spentAmountOfCredits
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  gb_android_offerwallCreditAmount = param_3;
  ndk_checkPlaytimeAndSpendOfferwallCredits();
  return;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_GetLeaderboardScore  @0x0007451c  (12 bytes)
undefined4
Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_GetLeaderboardScore
          (undefined4 param_1,undefined4 param_2,int param_3)

{
  return *(undefined4 *)(g_android_leaderboard_scores + param_3 * 4);
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_ResetLeaderboardScore  @0x0007452c  (14 bytes)
void Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_ResetLeaderboardScore
               (undefined4 param_1,undefined4 param_2,int param_3)

{
  *(undefined4 *)(g_android_leaderboard_scores + param_3 * 4) = 0;
  return;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_GetAchievementId  @0x00074540  (12 bytes)
undefined4
Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_GetAchievementId
          (undefined4 param_1,undefined4 param_2,int param_3)

{
  return *(undefined4 *)(g_android_current_achievements + param_3 * 4);
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_ResetAchievements  @0x00074550  (16 bytes)
void Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_ResetAchievements(void)

{
  g_android_current_achievements._0_4_ = 0;
  g_android_current_achievements._4_4_ = 0;
  g_android_current_achievements._8_4_ = 0;
  return;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_GetShowAchievements  @0x00074564  (10 bytes)
undefined4 Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_GetShowAchievements(void)

{
  return g_android_show_achievements;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_ResetShowAchievements  @0x00074574  (12 bytes)
void Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_ResetShowAchievements(void)

{
  g_android_show_achievements = 0;
  return;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_GetLinkGameGP  @0x00074584  (10 bytes)
undefined4 Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_GetLinkGameGP(void)

{
  return g_android_link_game_gp;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_ResetLinkGameGP  @0x00074594  (12 bytes)
void Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_ResetLinkGameGP(void)

{
  g_android_link_game_gp = 0;
  return;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_GetShowLeaderboards  @0x000745a4  (10 bytes)
undefined4 Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_GetShowLeaderboards(void)

{
  return g_android_show_leaderboards;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_ResetShowLeaderboards  @0x000745b4  (12 bytes)
void Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_ResetShowLeaderboards(void)

{
  g_android_show_leaderboards = 0;
  return;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_SetGPIsLinked  @0x000745c4  (10 bytes)
void Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_SetGPIsLinked
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  g_android_gp_is_linked = param_3;
  return;
}

// ===== glShadeModel  @0x00076720  (2 bytes)
void glShadeModel(void)

{
  return;
}

// ===== glMatrixMode  @0x00076722  (2 bytes)
void glMatrixMode(void)

{
  return;
}

// ===== glVertexPointer  @0x00076724  (2 bytes)
void glVertexPointer(void)

{
  return;
}

// ===== glAlphaFunc  @0x00076726  (2 bytes)
void glAlphaFunc(void)

{
  return;
}

// ===== glLoadIdentity  @0x00076728  (2 bytes)
void glLoadIdentity(void)

{
  return;
}

// ===== glScalef  @0x0007672a  (2 bytes)
void glScalef(void)

{
  return;
}

// ===== glFogf  @0x0007672c  (2 bytes)
void glFogf(void)

{
  return;
}

// ===== glFogfv  @0x0007672e  (2 bytes)
void glFogfv(void)

{
  return;
}

// ===== glLoadMatrixf  @0x00076730  (2 bytes)
void glLoadMatrixf(void)

{
  return;
}

// ===== glTexEnvi  @0x00076732  (2 bytes)
void glTexEnvi(void)

{
  return;
}

// ===== glMultMatrixf  @0x00076734  (2 bytes)
void glMultMatrixf(void)

{
  return;
}

// ===== glTexCoordPointer  @0x00076736  (2 bytes)
void glTexCoordPointer(void)

{
  return;
}

// ===== glNormalPointer  @0x00076738  (2 bytes)
void glNormalPointer(void)

{
  return;
}

// ===== glColorPointer  @0x0007673a  (2 bytes)
void glColorPointer(void)

{
  return;
}

// ===== glTexEnvf  @0x0007673c  (2 bytes)
void glTexEnvf(void)

{
  return;
}

// ===== glEnableClientState  @0x0007673e  (2 bytes)
void glEnableClientState(void)

{
  return;
}

// ===== glClientActiveTexture  @0x00076740  (2 bytes)
void glClientActiveTexture(void)

{
  return;
}

// ===== glMaterialfv  @0x00076742  (2 bytes)
void glMaterialfv(void)

{
  return;
}

// ===== glColor4f  @0x00076744  (2 bytes)
void glColor4f(void)

{
  return;
}

// ===== glLightfv  @0x00076746  (2 bytes)
void glLightfv(void)

{
  return;
}

// ===== glDisableClientState  @0x00076748  (2 bytes)
void glDisableClientState(void)

{
  return;
}

// ===== glLightModelfv  @0x0007674a  (2 bytes)
void glLightModelfv(void)

{
  return;
}

// ===== glHint  @0x0007674c  (2 bytes)
void glHint(void)

{
  return;
}

// ===== glMaterialf  @0x0007674e  (2 bytes)
void glMaterialf(void)

{
  return;
}

// ===== AELabelObject  @0x00076750  (2 bytes)
/* AELabelObject(unsigned int, unsigned int, char const*) */

uint AELabelObject(uint param_1,uint param_2,char *param_3)

{
  return param_1;
}

// ===== logi  @0x00076a68  (2 bytes)
/* logi(char*) */

char * logi(char *param_1)

{
  return param_1;
}

// ===== loge  @0x00076a6a  (2 bytes)
/* loge(char*) */

char * loge(char *param_1)

{
  return param_1;
}

// ===== GetStringLength  @0x000773a4  (38 bytes)
/* GetStringLength(AbyssEngine::String) */

int GetStringLength(String *param_1)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  short *psVar4;
  
  psVar2 = (short *)AbyssEngine::String::GetAEWChar(param_1);
  do {
    psVar4 = psVar2 + 1;
    sVar1 = *psVar2;
    psVar2 = psVar4;
  } while (sVar1 != 0);
  iVar3 = AbyssEngine::String::GetAEWChar(param_1);
  return ((int)psVar4 - iVar3 >> 1) + -1;
}

// ===== OpenAppend  @0x000775a6  (4 bytes)
/* OpenAppend(unsigned short*, int, bool, unsigned int) */

undefined4 OpenAppend(ushort *param_1,int param_2,bool param_3,uint param_4)

{
  return 0;
}

// ===== ArrayReleaseClasses<AELowLevelFile*>  @0x000792bc  (62 bytes)
/* void ArrayReleaseClasses<AELowLevelFile*>(Array<AELowLevelFile*>&) */

void ArrayReleaseClasses<AELowLevelFile*>(Array *param_1)

{
  void *pvVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar3 = *(uint *)(param_1 + 8);
  if (uVar3 != 0) {
    uVar4 = 0;
    do {
      piVar2 = *(int **)((int)pvVar1 + uVar4 * 4);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 4))(piVar2);
        pvVar1 = *(void **)(param_1 + 4);
        uVar3 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar4 * 4) = 0;
      uVar4 = uVar4 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar4 < uVar3);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArrayAddCached<unsigned_int>  @0x0008951c  (66 bytes)
/* void ArrayAddCached<unsigned int>(unsigned int, Array<unsigned int>&) */

void ArrayAddCached<unsigned_int>(uint param_1,Array *param_2)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  
  uVar1 = *(uint *)param_2;
  if (uVar1 < *(uint *)(param_2 + 8)) {
    pvVar3 = *(void **)(param_2 + 4);
  }
  else {
    pvVar3 = realloc(*(void **)(param_2 + 4),*(uint *)(param_2 + 8) << 3);
    *(void **)(param_2 + 4) = pvVar3;
    iVar2 = *(int *)(param_2 + 8);
    __aeabi_memclr4((void *)((int)pvVar3 + iVar2 * 4),iVar2 << 2);
    *(int *)(param_2 + 8) = iVar2 << 1;
    uVar1 = *(uint *)param_2;
  }
  *(uint *)((int)pvVar3 + uVar1 * 4) = param_1;
  *(int *)param_2 = *(int *)param_2 + 1;
  return;
}

// ===== glError  @0x0008eb3e  (4 bytes)
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* glError() */

void glError(void)

{
  glGetError();
  return;
}

// ===== GetEngine  @0x0009e854  (10 bytes)
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* GetEngine() */

undefined4 GetEngine(void)

{
  return gEngine;
}

// ===== ExitFunction  @0x0009e864  (14 bytes)
void ExitFunction(void)

{
  forceExit = 0xffffffff;
  return;
}

// ===== ndk23_getScreenshotFlag  @0x0009e878  (4 bytes)
undefined4 ndk23_getScreenshotFlag(void)

{
  return 0;
}

// ===== ndk23_resetScreenshotFlag  @0x0009e87c  (2 bytes)
void ndk23_resetScreenshotFlag(void)

{
  return;
}

// ===== ndk23_getExitFlag  @0x0009e880  (10 bytes)
undefined4 ndk23_getExitFlag(void)

{
  return forceExit;
}

// ===== loadAPK  @0x0009e890  (78 bytes)
undefined4 loadAPK(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = 0;
  APKArchive = zip_open(param_1,0,0);
  if (APKArchive != 0) {
    iVar1 = zip_get_num_files();
    if (iVar1 < 1) {
      uVar3 = 1;
    }
    else {
      iVar4 = 0;
      uVar3 = 1;
      do {
        iVar2 = zip_get_name(APKArchive,iVar4,0);
        if (iVar2 == 0) {
          return 1;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar1);
    }
  }
  return uVar3;
}

// ===== loadAPKAndZip  @0x0009e8e8  (56 bytes)
bool loadAPKAndZip(undefined4 param_1,undefined4 param_2)

{
  APKArchive = zip_open(param_1,0,0);
  ZIPArchive = zip_open(param_2,0,0);
  return APKArchive != 0 && ZIPArchive != 0;
}

// ===== ndk23_setDisplayHeightAndWidth  @0x0009e928  (2 bytes)
void ndk23_setDisplayHeightAndWidth(void)

{
  return;
}

// ===== ndk23_getCurrentFiredStatus  @0x0009e92a  (4 bytes)
undefined4 ndk23_getCurrentFiredStatus(void)

{
  return 0;
}

// ===== ndk23_Init  @0x0009e930  (276 bytes)
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ndk23_Init(undefined4 param_1,int param_2,int param_3)

{
  Engine *this;
  String aSStack_2c [8];
  int local_24;
  
  local_24 = __stack_chk_guard;
  ndkEntrance = "ndkInit";
  glViewport(0,0,param_2,param_3);
  _DAT_0026cb28 = 0;
  DAT_0026cb2c = 0;
  _DAT_0026cb30 = 0;
  DAT_0026cb34 = 0;
  _DAT_0026cb38 = 0;
  DAT_0026cb3c = 0;
  _DAT_0026cb40 = 0;
  DAT_0026cb44 = 0;
  _DAT_0026cb48 = 0;
  DAT_0026cb4c = 0;
  _DAT_0026cb50 = 0;
  DAT_0026cb54 = 0;
  gRealWidth = param_3;
  gRealHeight = param_2;
  loadAPK(param_1);
  this = operator_new(0x510);
  AbyssEngine::Engine::Engine(this);
  gEngine = this;
  AbyssEngine::String::String(aSStack_2c,"2.0.16",false);
  AbyssEngine::String::operator=((String *)(this + 0x34),aSStack_2c);
  AbyssEngine::String::~String(aSStack_2c);
  AbyssEngine::Engine::InitGL(gEngine,true,param_2,param_3);
  if (rootDirectory != (void *)0x0) {
    AEFile::SetAppRootDir(rootDirectory);
  }
  AbyssEngine::Engine::Initialize(gEngine,OnCreateApplication);
  AbyssEngine::Engine::SetOnDestroyApp(gEngine,OnDestroyApplication);
  AbyssEngine::PaintCanvas::SetGameOrientation((PaintCanvas *)**(undefined4 **)(gEngine + 0x28),2);
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ndk23_InitWithZip  @0x0009eaa8  (306 bytes)
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ndk23_InitWithZip(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  Engine *this;
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  ndkEntrance = "ndkInit";
  glViewport(0,0,param_3);
  _DAT_0026cb28 = 0;
  DAT_0026cb2c = 0;
  _DAT_0026cb30 = 0;
  DAT_0026cb34 = 0;
  _DAT_0026cb38 = 0;
  DAT_0026cb3c = 0;
  _DAT_0026cb40 = 0;
  DAT_0026cb44 = 0;
  _DAT_0026cb48 = 0;
  DAT_0026cb4c = 0;
  _DAT_0026cb50 = 0;
  DAT_0026cb54 = 0;
  gRealWidth = param_4;
  gRealHeight = param_3;
  APKArchive = zip_open(param_1,0,0);
  ZIPArchive = zip_open(param_2,0,0);
  this = operator_new(0x510);
  AbyssEngine::Engine::Engine(this);
  gEngine = this;
  AbyssEngine::String::String(aSStack_30,"2.0.16",false);
  AbyssEngine::String::operator=((String *)(this + 0x34),aSStack_30);
  AbyssEngine::String::~String(aSStack_30);
  AbyssEngine::Engine::InitGL(gEngine,true,param_3,param_4);
  if (rootDirectory != (void *)0x0) {
    AEFile::SetAppRootDir(rootDirectory);
  }
  AbyssEngine::Engine::Initialize(gEngine,OnCreateApplication);
  AbyssEngine::Engine::SetOnDestroyApp(gEngine,OnDestroyApplication);
  AbyssEngine::PaintCanvas::SetGameOrientation((PaintCanvas *)**(undefined4 **)(gEngine + 0x28),2);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ndk23_resize  @0x0009ec48  (54 bytes)
void ndk23_resize(undefined4 param_1,undefined4 param_2)

{
  glViewport(0,0,param_1,param_2);
  gRealWidth = param_1;
  gRealHeight = param_2;
  simulateTouch(gEngine);
  return;
}

// ===== ndk23_ndkDone  @0x0009ec88  (52 bytes)
void ndk23_ndkDone(void)

{
  void *pvVar1;
  
  if (gEngine != (Engine *)0x0) {
    AbyssEngine::Engine::Release();
    if (gEngine != (Engine *)0x0) {
      pvVar1 = (void *)AbyssEngine::Engine::~Engine(gEngine);
      operator_delete(pvVar1);
    }
    gEngine = (Engine *)0x0;
  }
  return;
}

// ===== ndk23_handleAcceleration  @0x0009ecd0  (352 bytes)
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ndk23_handleAcceleration
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               float param_5,float param_6,float param_7)

{
  undefined4 extraout_s0;
  undefined4 extraout_s1;
  undefined4 extraout_s2;
  undefined4 extraout_s3;
  undefined4 extraout_s4;
  double in_d2;
  undefined4 extraout_s5;
  double dVar1;
  
  _DAT_0026cb40 = (double)param_5;
  _DAT_0026cb48 = (double)param_6;
  _DAT_0026cb50 = (double)param_7;
  if (rotateAccelValues != 0) {
    dVar1 = -_DAT_0026cb40;
    _DAT_0026cb40 = _DAT_0026cb48;
    _DAT_0026cb48 = dVar1;
  }
  DAT_0026cb60 = -_DAT_0026cb48;
  DAT_0026cb58 = -_DAT_0026cb40;
  DAT_0026cb68 = -_DAT_0026cb50;
  if (gEngine == 0) {
    return;
  }
  if (*(char *)**(undefined4 **)(gEngine + 0x28) == '\0') {
    _DAT_0026cb38 = _DAT_0026cb40 * 0.95;
    _DAT_0026cb30 = _DAT_0026cb38;
    _DAT_0026cb28 = _DAT_0026cb38;
  }
  else {
    _DAT_0026cb38 = _DAT_0026cb50 * 0.05 + _DAT_0026cb38 * 0.95;
    _DAT_0026cb30 = _DAT_0026cb48 * 0.05 + _DAT_0026cb30 * 0.95;
    _DAT_0026cb28 = _DAT_0026cb40 * 0.05 + _DAT_0026cb28 * 0.95;
  }
  DAT_0026cb78 = -_DAT_0026cb30;
  DAT_0026cb70 = -_DAT_0026cb28;
  DAT_0026cb80 = -_DAT_0026cb38;
  AbyssEngine::Engine::SetAccelValue
            ((double)CONCAT44(param_2,param_7),(double)CONCAT44(param_4,param_6),in_d2);
  AbyssEngine::Engine::SetGravValue
            ((double)CONCAT44(extraout_s1,extraout_s0),(double)CONCAT44(extraout_s3,extraout_s2),
             (double)CONCAT44(extraout_s5,extraout_s4));
  return;
}

// ===== ndk23_newrender  @0x0009ee90  (406 bytes)
void ndk23_newrender(void)

{
  int iVar1;
  undefined4 extraout_r1;
  uint uVar2;
  int iVar3;
  void *local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  AbyssEngine::ApplicationManager::SetExitCallback
            (*(ApplicationManager **)(gEngine + 0x28),ExitFunction);
  iVar1 = GetTouchCount();
  if (0 < iVar1) {
    iVar3 = 0;
    do {
      GetTouch((int)&local_38);
      DAT_0026cb20 = local_30;
      DAT_0026cb24 = local_2c;
      DAT_0026a19c = local_38;
      if (local_34 == 2) {
        AbyssEngine::ApplicationManager::OnTouchMove
                  (*(ApplicationManager **)(gEngine + 0x28),local_30,local_2c,local_38);
      }
      else if (local_34 == 1) {
        AbyssEngine::ApplicationManager::OnTouchEnd
                  (*(ApplicationManager **)(gEngine + 0x28),local_30,local_2c,local_38);
        AbyssEngine::ApplicationManager::OnTouchEnd(*(ApplicationManager **)(gEngine + 0x28));
      }
      else if (local_34 == 0) {
        AbyssEngine::ApplicationManager::OnTouchBegin
                  (*(ApplicationManager **)(gEngine + 0x28),local_30,local_2c,local_38);
      }
      iVar3 = iVar3 + 1;
    } while (iVar1 != iVar3);
  }
  if (g_android_back_button_pressed != 0) {
    keyPressed(gEngine,0x35);
    keyReleased(gEngine,0x35);
    g_android_back_button_pressed = 0;
  }
  RemoveTouches();
  AbyssEngine::ApplicationManager::OnUpdate(CONCAT44(extraout_r1,*(undefined4 *)(gEngine + 0x28)));
  iVar1 = AbyssEngine::ApplicationManager::GetApplicationData
                    (*(ApplicationManager **)(gEngine + 0x28));
  if (*(char *)(iVar1 + 0x31) == '\0') {
    uVar2 = *(uint *)(iVar1 + 0x30);
    if ((uVar2 & 0xff) == 0) {
      if ((uVar2 & 0xff0000) == 0) {
        if (uVar2 < 0x1000000) {
          uVar2 = *(uint *)(iVar1 + 0x88);
          if ((uVar2 & 0xff) == 0) {
            if ((uVar2 & 0xff00) == 0) {
              if ((uVar2 & 0xff0000) == 0) {
                if (0xffffff < uVar2) {
                  *(undefined1 *)(iVar1 + 0x8b) = 0;
                }
              }
              else {
                *(undefined1 *)(iVar1 + 0x8a) = 0;
              }
            }
            else {
              *(undefined1 *)(iVar1 + 0x89) = 0;
            }
          }
          else {
            *(undefined1 *)(iVar1 + 0x88) = 0;
          }
        }
        else {
          *(undefined1 *)(iVar1 + 0x33) = 0;
        }
      }
      else {
        *(undefined1 *)(iVar1 + 0x32) = 0;
      }
    }
    else {
      *(undefined1 *)(iVar1 + 0x30) = 0;
    }
  }
  else {
    *(undefined1 *)(iVar1 + 0x31) = 0;
    *(undefined1 *)(iVar1 + 0x34) = 1;
  }
  ndk_checkPlaytimeAndSpendOfferwallCredits();
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== ndk_checkPlaytimeAndSpendOfferwallCredits  @0x0009f060  (66 bytes)
void ndk_checkPlaytimeAndSpendOfferwallCredits(void)

{
  undefined8 uVar1;
  
  uVar1 = Status::getPlayingTime(Globals::status);
  if ((int)(uint)((int)uVar1 == 0) <= (int)((ulonglong)uVar1 >> 0x20)) {
    if (gb_android_offerwallCreditAmount < 1) {
      return;
    }
    Status::changeCredits(Globals::status,gb_android_offerwallCreditAmount);
    ndk_autosave();
    gb_android_offerwallCreditAmount = 0;
  }
  return;
}

// ===== ndk23_handleTouchPadEvent  @0x0009f0b4  (148 bytes)
void ndk23_handleTouchPadEvent
               (undefined4 param_1,void *param_2,int param_3,float param_4,float param_5)

{
  if (param_3 == 2) {
    AbyssEngine::ApplicationManager::OnTouchMove
              (*(ApplicationManager **)(gEngine + 0x28),(int)param_4,(int)param_5,param_2);
    return;
  }
  if (param_3 == 1) {
    AbyssEngine::ApplicationManager::OnTouchEnd
              (*(ApplicationManager **)(gEngine + 0x28),(int)param_4,(int)param_5,param_2);
    AbyssEngine::ApplicationManager::OnTouchEnd(*(ApplicationManager **)(gEngine + 0x28));
    return;
  }
  if (param_3 != 0) {
    return;
  }
  AbyssEngine::ApplicationManager::OnTouchBegin
            (*(ApplicationManager **)(gEngine + 0x28),(int)param_4,(int)param_5,param_2);
  return;
}

// ===== ndk23_setRootDirectory  @0x0009f150  (34 bytes)
void ndk23_setRootDirectory(char *param_1)

{
  size_t sVar1;
  
  sVar1 = strlen(param_1);
  rootDirectory = malloc(sVar1 + 1);
  strcpy(rootDirectory,param_1);
  return;
}

// ===== ndk23_setZipDirectory  @0x0009f178  (36 bytes)
void ndk23_setZipDirectory(char *param_1)

{
  size_t sVar1;
  
  sVar1 = strlen(param_1);
  ZIPDirectory = malloc(sVar1 + 1);
  strcpy(ZIPDirectory,param_1);
  return;
}

// ===== ndk23_setCountryCode  @0x0009f1a0  (148 bytes)
void ndk23_setCountryCode(undefined4 param_1)

{
  switch(param_1) {
  case 0:
  default:
    AbyssEngine::Engine::countryCode = 0;
    break;
  case 1:
    AbyssEngine::Engine::countryCode = 1;
    break;
  case 2:
    AbyssEngine::Engine::countryCode = 2;
    break;
  case 3:
    AbyssEngine::Engine::countryCode = 3;
    break;
  case 4:
    AbyssEngine::Engine::countryCode = 4;
    break;
  case 5:
    AbyssEngine::Engine::countryCode = 5;
    break;
  case 6:
    AbyssEngine::Engine::countryCode = 6;
    break;
  case 7:
    AbyssEngine::Engine::countryCode = 7;
    break;
  case 8:
    AbyssEngine::Engine::countryCode = 8;
    break;
  case 9:
    AbyssEngine::Engine::countryCode = 9;
    break;
  case 10:
    AbyssEngine::Engine::countryCode = 10;
    break;
  case 0xb:
    AbyssEngine::Engine::countryCode = 0xb;
    break;
  case 0xc:
    AbyssEngine::Engine::countryCode = 0xc;
    break;
  case 0xd:
    AbyssEngine::Engine::countryCode = 0xd;
    break;
  case 0xe:
    AbyssEngine::Engine::countryCode = 0xe;
    break;
  case 0xf:
    AbyssEngine::Engine::countryCode = 0xf;
  }
  return;
}

// ===== ndk23_sendingPauseSignal  @0x0009f288  (50 bytes)
void ndk23_sendingPauseSignal(void)

{
  if (gEngine != 0) {
    FModSound::pauseAll(Globals::sound);
                    /* WARNING: Could not recover jumptable at 0x0009f2b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(*(int *)(gEngine + 0x28) + 0x18) + 0x3c))();
    return;
  }
  return;
}

// ===== ndk23_sendingResumeSignal  @0x0009f2c8  (26 bytes)
void ndk23_sendingResumeSignal(void)

{
  if (gEngine == 0) {
    return;
  }
  FModSound::resumeAll(Globals::sound);
  return;
}

// ===== ndk_iapBoughtPremium  @0x0009f2e8  (244 bytes)
void ndk_iapBoughtPremium(uint param_1,uint param_2)

{
  bool bVar1;
  
  if (gEngine == 0) {
    return;
  }
  if (param_1 < 5) {
    if ((param_2 | 1) != 1) {
      return;
    }
    bVar1 = param_2 == 1;
    switch(param_1) {
    case 0:
      Globals::options[0x35] = bVar1;
      if (gi_iap_buy_dlc1_pressed != 0) {
        gi_iap_buy_dlc1_pressed = 0;
      }
      break;
    case 1:
      if (gi_iap_buy_dlc2_pressed != 0) {
        gi_iap_buy_dlc2_pressed = 0;
      }
      Globals::options[0x36] = bVar1;
      *(undefined4 *)(Globals::status + 0x114) = 3;
      return;
    case 2:
      Globals::options[0x37] = bVar1;
      if (gi_iap_buy_dlc3_pressed != 0) {
        gi_iap_buy_dlc3_pressed = 0;
      }
      break;
    case 3:
      if (gi_iap_buy_dlc4_pressed == 0) {
        Globals::options[0x38] = bVar1;
        return;
      }
      gi_iap_buy_dlc4_pressed = 0;
      Globals::options[0x38] = bVar1;
      return;
    case 4:
      Globals::options[0x35] = bVar1;
      Globals::options[0x37] = bVar1;
      Globals::options[0x39] = bVar1;
      if (gi_iap_buy_dlc5_pressed != 0) {
        gi_iap_buy_dlc5_pressed = 0;
      }
      break;
    default:
      return;
    }
    Status::setSystemVisibility(Globals::status,0x19,true);
    return;
  }
  return;
}

// ===== ndk_getDLC_1_BOUGHT  @0x0009f430  (26 bytes)
undefined1 ndk_getDLC_1_BOUGHT(void)

{
  undefined1 uVar1;
  
  uVar1 = Globals::options[0x35];
  if (gEngine == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

// ===== ndk_getDLC_2_BOUGHT  @0x0009f454  (26 bytes)
undefined1 ndk_getDLC_2_BOUGHT(void)

{
  undefined1 uVar1;
  
  uVar1 = Globals::options[0x36];
  if (gEngine == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

// ===== ndk_getDLC_3_BOUGHT  @0x0009f478  (26 bytes)
undefined1 ndk_getDLC_3_BOUGHT(void)

{
  undefined1 uVar1;
  
  uVar1 = Globals::options[0x37];
  if (gEngine == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

// ===== ndk_getDLC_4_BOUGHT  @0x0009f49c  (26 bytes)
undefined1 ndk_getDLC_4_BOUGHT(void)

{
  undefined1 uVar1;
  
  uVar1 = Globals::options[0x38];
  if (gEngine == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

// ===== ndk_getDLC_5_BOUGHT  @0x0009f4c0  (26 bytes)
undefined1 ndk_getDLC_5_BOUGHT(void)

{
  undefined1 uVar1;
  
  uVar1 = Globals::options[0x39];
  if (gEngine == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

// ===== ndk_iapBoughtConsumable  @0x0009f4e4  (88 bytes)
void ndk_iapBoughtConsumable(uint param_1)

{
  char *pcVar1;
  
  if ((param_1 < 5) && (gEngine != 0)) {
    switch(param_1) {
    case 0:
      pcVar1 = "\x04";
      break;
    case 1:
      pcVar1 = "eERKN11AbyssEngine6AEMath6VectorE";
      break;
    case 2:
      pcVar1 = (char *)0xf4240;
      break;
    case 3:
      pcVar1 = (char *)0x2dc6c0;
      break;
    case 4:
      pcVar1 = (char *)0x989680;
      break;
    default:
      return;
    }
    setBaughtCredits(pcVar1);
    return;
  }
  return;
}

// ===== setBaughtCredits  @0x0009f544  (280 bytes)
undefined4 setBaughtCredits(char *param_1)

{
  undefined **ppuVar1;
  
  if ((int)param_1 < 1000000) {
    if (param_1 == "\x04") {
      Status::changeCredits(Globals::status,100000);
      if (gi_iap_buy_credit_pack1_pressed == 0) goto LAB_0009f654;
      ppuVar1 = &PTR_gi_iap_buy_credit_pack1_pressed_00265464;
    }
    else {
      if (param_1 != "eERKN11AbyssEngine6AEMath6VectorE") {
        return 0;
      }
      Status::changeCredits(Globals::status,300000);
      if (gi_iap_buy_credit_pack2_pressed == 0) goto LAB_0009f654;
      ppuVar1 = &PTR_gi_iap_buy_credit_pack2_pressed_00265468;
    }
  }
  else if (param_1 == (char *)0xf4240) {
    Status::changeCredits(Globals::status,1000000);
    if (gi_iap_buy_credit_pack3_pressed == 0) goto LAB_0009f654;
    ppuVar1 = &PTR_gi_iap_buy_credit_pack3_pressed_0026546c;
  }
  else if (param_1 == (char *)0x2dc6c0) {
    Status::changeCredits(Globals::status,3000000);
    if (gi_iap_buy_credit_pack4_pressed == 0) goto LAB_0009f654;
    ppuVar1 = &PTR_gi_iap_buy_credit_pack4_pressed_00265470;
  }
  else {
    if (param_1 != (char *)0x989680) {
      return 0;
    }
    Status::changeCredits(Globals::status,10000000);
    if (gi_iap_buy_credit_pack5_pressed == 0) goto LAB_0009f654;
    ppuVar1 = &PTR_gi_iap_buy_credit_pack5_pressed_00265474;
  }
  *(undefined4 *)*ppuVar1 = 0;
  checkFirstCreditPackBoughtWriteAction();
LAB_0009f654:
  ndk_autosave();
  return 1;
}

// ===== checkFirstCreditPackBoughtWriteAction  @0x0009f698  (90 bytes)
void checkFirstCreditPackBoughtWriteAction(void)

{
  RecordHandler *this;
  RecordHandler aRStack_34 [32];
  int local_14;
  
  local_14 = __stack_chk_guard;
  Status::getCurrentCampaignMission(Globals::status);
  if (Globals::options[0x62] == '\0') {
    Globals::options[0x62] = '\x01';
    this = (RecordHandler *)RecordHandler::RecordHandler(aRStack_34);
    RecordHandler::saveOptions(this);
    RecordHandler::~RecordHandler(aRStack_34);
  }
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ndk_autosave  @0x0009f714  (46 bytes)
void ndk_autosave(void)

{
  RecordHandler *this;
  void *pvVar1;
  
  this = operator_new(0x20);
  RecordHandler::RecordHandler(this);
  RecordHandler::recordStoreWrite(this,0);
  RecordHandler::recordStoreWritePreview(this,0);
  pvVar1 = (void *)RecordHandler::~RecordHandler(this);
  operator_delete(pvVar1);
  return;
}

// ===== ndk_getCurrentApplicationModule  @0x0009f750  (30 bytes)
undefined4 ndk_getCurrentApplicationModule(void)

{
  undefined4 uVar1;
  
  if (gEngine == 0) {
    return 0xffffffff;
  }
  uVar1 = AbyssEngine::ApplicationManager::GetCurrentApplicationModule(Globals::appManager);
  return uVar1;
}

// ===== ndk_getLogoShown  @0x0009f774  (10 bytes)
undefined4 ndk_getLogoShown(void)

{
  return Globals::logoIsShown;
}

// ===== ndk_isInMainMenu  @0x0009f784  (10 bytes)
undefined4 ndk_isInMainMenu(void)

{
  return Globals::isInMainMenu;
}

// ===== pConstToNonConst  @0x0009f794  (40 bytes)
char * pConstToNonConst(char *param_1)

{
  size_t sVar1;
  char *__dest;
  
  if (param_1 != (char *)0x0) {
    sVar1 = strlen(param_1);
    __dest = malloc(sVar1 + 1);
    if (__dest != (char *)0x0) {
      strcpy(__dest,param_1);
      return __dest;
    }
  }
  return (char *)0x0;
}

// ===== getStringUTFChars  @0x0009f7bc  (16 bytes)
undefined4 getStringUTFChars(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 != (int *)0x0) && (param_2 != 0)) {
                    /* WARNING: Could not recover jumptable at 0x0009f7c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x2a4))();
    return uVar1;
  }
  return 0;
}

// ===== releaseStringUTFChars  @0x0009f7cc  (48 bytes)
void releaseStringUTFChars(int *param_1,void *param_2,void *param_3)

{
  if (((param_1 != (int *)0x0) && (param_2 != (void *)0x0)) && (param_3 != (void *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0009f7e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x2a8))(param_1,param_2);
    return;
  }
  if (param_3 != (void *)0x0) {
    operator_delete(param_3);
  }
  if (param_2 != (void *)0x0) {
    operator_delete(param_2);
    return;
  }
  return;
}

// ===== ndk_setNativeItemInformationList  @0x0009f7fc  (1482 bytes)
void ndk_setNativeItemInformationList
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  undefined4 uVar35;
  undefined4 uVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  undefined4 uVar39;
  undefined4 uVar40;
  undefined4 uVar41;
  undefined4 uVar42;
  undefined4 uVar43;
  undefined4 uVar44;
  undefined4 uVar45;
  undefined4 uVar46;
  undefined4 uVar47;
  undefined4 uVar48;
  undefined4 uVar49;
  undefined4 uVar50;
  
  if (param_1 == (int *)0x0) {
    return;
  }
  uVar1 = (**(code **)(*param_1 + 0x2b4))(param_1,param_3,0);
  uVar2 = (**(code **)(*param_1 + 0x2b4))(param_1,param_3,1);
  uVar3 = (**(code **)(*param_1 + 0x2b4))(param_1,param_3,2);
  uVar4 = (**(code **)(*param_1 + 0x2b4))(param_1,param_3,3);
  uVar5 = (**(code **)(*param_1 + 0x2b4))(param_1,param_3,4);
  uVar6 = (**(code **)(*param_1 + 0x2b4))(param_1,param_4,0);
  uVar7 = (**(code **)(*param_1 + 0x2b4))(param_1,param_4,1);
  uVar8 = (**(code **)(*param_1 + 0x2b4))(param_1,param_4,2);
  uVar9 = (**(code **)(*param_1 + 0x2b4))(param_1,param_4,3);
  uVar10 = (**(code **)(*param_1 + 0x2b4))(param_1,param_4,4);
  uVar11 = (**(code **)(*param_1 + 0x2b4))(param_1,param_5,0);
  uVar12 = (**(code **)(*param_1 + 0x2b4))(param_1,param_5,1);
  uVar13 = (**(code **)(*param_1 + 0x2b4))(param_1,param_5,2);
  uVar14 = (**(code **)(*param_1 + 0x2b4))(param_1,param_5,3);
  uVar15 = (**(code **)(*param_1 + 0x2b4))(param_1,param_5,4);
  uVar16 = (**(code **)(*param_1 + 0x2b4))(param_1,param_6,0);
  uVar17 = (**(code **)(*param_1 + 0x2b4))(param_1,param_6,1);
  uVar18 = (**(code **)(*param_1 + 0x2b4))(param_1,param_6,2);
  uVar19 = (**(code **)(*param_1 + 0x2b4))(param_1,param_6,3);
  uVar20 = (**(code **)(*param_1 + 0x2b4))(param_1,param_6,4);
  uVar21 = (**(code **)(*param_1 + 0x2b4))(param_1,param_7,0);
  uVar22 = (**(code **)(*param_1 + 0x2b4))(param_1,param_7,1);
  uVar23 = (**(code **)(*param_1 + 0x2b4))(param_1,param_7,2);
  uVar24 = (**(code **)(*param_1 + 0x2b4))(param_1,param_7,3);
  uVar25 = (**(code **)(*param_1 + 0x2b4))(param_1,param_7,4);
  uVar26 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar1,0);
  uVar27 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar2,0);
  uVar28 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar3,0);
  uVar29 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar4,0);
  uVar30 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar5,0);
  uVar31 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar6,0);
  uVar32 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar7,0);
  uVar33 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar8,0);
  uVar34 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar9,0);
  uVar35 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar10,0);
  uVar36 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar11,0);
  uVar37 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar12,0);
  uVar38 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar13,0);
  uVar39 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar14,0);
  uVar40 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar15,0);
  uVar41 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar16,0);
  uVar42 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar17,0);
  uVar43 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar18,0);
  uVar44 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar19,0);
  uVar45 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar20,0);
  uVar46 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar21,0);
  uVar47 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar22,0);
  uVar48 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar23,0);
  uVar49 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar24,0);
  uVar50 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar25,0);
  Globals::cItemListID_00 = pConstToNonConst(uVar26);
  Globals::cItemListID_01 = pConstToNonConst(uVar27);
  Globals::cItemListID_02 = pConstToNonConst(uVar28);
  Globals::cItemListID_03 = pConstToNonConst(uVar29);
  Globals::cItemListID_04 = pConstToNonConst(uVar30);
  Globals::cItemListName_00 = pConstToNonConst(uVar31);
  Globals::cItemListName_01 = pConstToNonConst(uVar32);
  Globals::cItemListName_02 = pConstToNonConst(uVar33);
  Globals::cItemListName_03 = pConstToNonConst(uVar34);
  Globals::cItemListName_04 = pConstToNonConst(uVar34);
  Globals::cItemListDescription_00 = pConstToNonConst(uVar36);
  Globals::cItemListDescription_01 = pConstToNonConst(uVar37);
  Globals::cItemListDescription_02 = pConstToNonConst(uVar38);
  Globals::cItemListDescription_03 = pConstToNonConst(uVar39);
  Globals::cItemListDescription_04 = pConstToNonConst(uVar40);
  Globals::cItemListCurrency_00 = pConstToNonConst(uVar41);
  Globals::cItemListCurrency_01 = pConstToNonConst(uVar42);
  Globals::cItemListCurrency_02 = pConstToNonConst(uVar43);
  Globals::cItemListCurrency_03 = pConstToNonConst(uVar44);
  Globals::cItemListCurrency_04 = pConstToNonConst(uVar45);
  Globals::cItemListPrice_00 = pConstToNonConst(uVar46);
  Globals::cItemListPrice_01 = pConstToNonConst(uVar47);
  Globals::cItemListPrice_02 = pConstToNonConst(uVar48);
  Globals::cItemListPrice_03 = pConstToNonConst(uVar49);
  Globals::cItemListPrice_04 = pConstToNonConst(uVar50);
  releaseStringUTFChars(param_1,uVar1,uVar26);
  releaseStringUTFChars(param_1,uVar2,uVar27);
  releaseStringUTFChars(param_1,uVar3,uVar28);
  releaseStringUTFChars(param_1,uVar4,uVar29);
  releaseStringUTFChars(param_1,uVar5,uVar30);
  releaseStringUTFChars(param_1,uVar6,uVar31);
  releaseStringUTFChars(param_1,uVar7,uVar32);
  releaseStringUTFChars(param_1,uVar8,uVar33);
  releaseStringUTFChars(param_1,uVar9,uVar34);
  releaseStringUTFChars(param_1,uVar10,uVar35);
  releaseStringUTFChars(param_1,uVar11,uVar36);
  releaseStringUTFChars(param_1,uVar12,uVar37);
  releaseStringUTFChars(param_1,uVar13,uVar38);
  releaseStringUTFChars(param_1,uVar14,uVar39);
  releaseStringUTFChars(param_1,uVar15,uVar40);
  releaseStringUTFChars(param_1,uVar16,uVar41);
  releaseStringUTFChars(param_1,uVar17,uVar42);
  releaseStringUTFChars(param_1,uVar18,uVar43);
  releaseStringUTFChars(param_1,uVar19,uVar44);
  releaseStringUTFChars(param_1,uVar20,uVar45);
  releaseStringUTFChars(param_1,uVar21,uVar46);
  releaseStringUTFChars(param_1,uVar22,uVar47);
  releaseStringUTFChars(param_1,uVar23,uVar48);
  releaseStringUTFChars(param_1,uVar24,uVar49);
  releaseStringUTFChars(param_1,uVar25,uVar50);
  return;
}

// ===== ndk_resetNativeItemInformationList  @0x0009fe28  (826 bytes)
void ndk_resetNativeItemInformationList(void)

{
  if ((((Globals::cItemListID_00 != (void *)0x0) && (Globals::cItemListID_01 != (void *)0x0)) &&
      (Globals::cItemListID_02 != (void *)0x0)) &&
     ((Globals::cItemListID_03 != (void *)0x0 && (Globals::cItemListID_04 != (void *)0x0)))) {
    operator_delete__(Globals::cItemListID_00);
    if (Globals::cItemListID_01 != (void *)0x0) {
      operator_delete__(Globals::cItemListID_01);
    }
    if (Globals::cItemListID_02 != (void *)0x0) {
      operator_delete__(Globals::cItemListID_02);
    }
    if (Globals::cItemListID_03 != (void *)0x0) {
      operator_delete__(Globals::cItemListID_03);
    }
    if (Globals::cItemListID_04 != (void *)0x0) {
      operator_delete__(Globals::cItemListID_04);
    }
    Globals::cItemListID_00 = (void *)0x0;
    Globals::cItemListID_01 = (void *)0x0;
    Globals::cItemListID_02 = (void *)0x0;
    Globals::cItemListID_03 = (void *)0x0;
    Globals::cItemListID_04 = (void *)0x0;
  }
  if (((Globals::cItemListName_00 != (void *)0x0) && (Globals::cItemListName_01 != (void *)0x0)) &&
     ((Globals::cItemListName_02 != (void *)0x0 &&
      ((Globals::cItemListName_03 != (void *)0x0 && (Globals::cItemListName_04 != (void *)0x0))))))
  {
    operator_delete__(Globals::cItemListName_00);
    if (Globals::cItemListName_01 != (void *)0x0) {
      operator_delete__(Globals::cItemListName_01);
    }
    if (Globals::cItemListName_02 != (void *)0x0) {
      operator_delete__(Globals::cItemListName_02);
    }
    if (Globals::cItemListName_03 != (void *)0x0) {
      operator_delete__(Globals::cItemListName_03);
    }
    if (Globals::cItemListName_04 != (void *)0x0) {
      operator_delete__(Globals::cItemListName_04);
    }
    Globals::cItemListName_00 = (void *)0x0;
    Globals::cItemListName_01 = (void *)0x0;
    Globals::cItemListName_02 = (void *)0x0;
    Globals::cItemListName_03 = (void *)0x0;
    Globals::cItemListName_04 = (void *)0x0;
  }
  if ((((Globals::cItemListDescription_00 != (void *)0x0) &&
       (Globals::cItemListDescription_01 != (void *)0x0)) &&
      (Globals::cItemListDescription_02 != (void *)0x0)) &&
     ((Globals::cItemListDescription_03 != (void *)0x0 &&
      (Globals::cItemListDescription_04 != (void *)0x0)))) {
    operator_delete__(Globals::cItemListDescription_00);
    if (Globals::cItemListDescription_01 != (void *)0x0) {
      operator_delete__(Globals::cItemListDescription_01);
    }
    if (Globals::cItemListDescription_02 != (void *)0x0) {
      operator_delete__(Globals::cItemListDescription_02);
    }
    if (Globals::cItemListDescription_03 != (void *)0x0) {
      operator_delete__(Globals::cItemListDescription_03);
    }
    if (Globals::cItemListDescription_04 != (void *)0x0) {
      operator_delete__(Globals::cItemListDescription_04);
    }
    Globals::cItemListDescription_00 = (void *)0x0;
    Globals::cItemListDescription_01 = (void *)0x0;
    Globals::cItemListDescription_02 = (void *)0x0;
    Globals::cItemListDescription_03 = (void *)0x0;
    Globals::cItemListDescription_04 = (void *)0x0;
  }
  if (((Globals::cItemListCurrency_00 != (void *)0x0) &&
      (Globals::cItemListCurrency_01 != (void *)0x0)) &&
     ((Globals::cItemListCurrency_02 != (void *)0x0 &&
      ((Globals::cItemListCurrency_03 != (void *)0x0 &&
       (Globals::cItemListCurrency_04 != (void *)0x0)))))) {
    operator_delete__(Globals::cItemListCurrency_00);
    if (Globals::cItemListCurrency_01 != (void *)0x0) {
      operator_delete__(Globals::cItemListCurrency_01);
    }
    if (Globals::cItemListCurrency_02 != (void *)0x0) {
      operator_delete__(Globals::cItemListCurrency_02);
    }
    if (Globals::cItemListCurrency_03 != (void *)0x0) {
      operator_delete__(Globals::cItemListCurrency_03);
    }
    if (Globals::cItemListCurrency_04 != (void *)0x0) {
      operator_delete__(Globals::cItemListCurrency_04);
    }
    Globals::cItemListCurrency_00 = (void *)0x0;
    Globals::cItemListCurrency_01 = (void *)0x0;
    Globals::cItemListCurrency_02 = (void *)0x0;
    Globals::cItemListCurrency_03 = (void *)0x0;
    Globals::cItemListCurrency_04 = (void *)0x0;
  }
  if ((((Globals::cItemListPrice_00 != (void *)0x0) && (Globals::cItemListPrice_01 != (void *)0x0))
      && (Globals::cItemListPrice_02 != (void *)0x0)) &&
     ((Globals::cItemListPrice_03 != (void *)0x0 && (Globals::cItemListPrice_04 != (void *)0x0)))) {
    operator_delete__(Globals::cItemListPrice_00);
    if (Globals::cItemListPrice_01 != (void *)0x0) {
      operator_delete__(Globals::cItemListPrice_01);
    }
    if (Globals::cItemListPrice_02 != (void *)0x0) {
      operator_delete__(Globals::cItemListPrice_02);
    }
    if (Globals::cItemListPrice_03 != (void *)0x0) {
      operator_delete__(Globals::cItemListPrice_03);
    }
    if (Globals::cItemListPrice_04 != (void *)0x0) {
      operator_delete__(Globals::cItemListPrice_04);
    }
    Globals::cItemListPrice_00 = (void *)0x0;
    Globals::cItemListPrice_01 = (void *)0x0;
    Globals::cItemListPrice_02 = (void *)0x0;
    Globals::cItemListPrice_03 = (void *)0x0;
    Globals::cItemListPrice_04 = (void *)0x0;
  }
  return;
}

// ===== AddTouch  @0x000a027c  (116 bytes)
/* AddTouch(int, int, int, int) */

void AddTouch(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  void *pvVar2;
  int iVar3;
  
  iVar3 = curTouchSize + 1;
  bVar1 = maxTouchSize <= curTouchSize;
  curTouchSize = iVar3;
  if (bVar1) {
    maxTouchSize = iVar3;
    touches = realloc(touches,iVar3 * 0x10);
  }
  pvVar2 = touches;
  *(int *)((int)touches + curTouchSize * 0x10 + -0x10) = param_1;
  iVar3 = curTouchSize;
  *(int *)((int)pvVar2 + curTouchSize * 0x10 + -0xc) = param_2;
  *(int *)((int)pvVar2 + iVar3 * 0x10 + -8) = param_3;
  *(int *)((int)pvVar2 + iVar3 * 0x10 + -4) = param_4;
  return;
}

// ===== GetTouchCount  @0x000a030c  (10 bytes)
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* GetTouchCount() */

undefined4 GetTouchCount(void)

{
  return curTouchSize;
}

// ===== RemoveTouches  @0x000a031c  (12 bytes)
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* RemoveTouches() */

void RemoveTouches(void)

{
  curTouchSize = 0;
  return;
}

// ===== GetTouch  @0x000a032c  (22 bytes)
/* GetTouch(int) */

void GetTouch(int param_1)

{
  int in_r1;
  undefined8 *puVar1;
  undefined8 uVar2;
  
  puVar1 = (undefined8 *)(touches + in_r1 * 0x10);
  uVar2 = puVar1[1];
  *(undefined8 *)param_1 = *puVar1;
  *(undefined8 *)(param_1 + 8) = uVar2;
  return;
}

// ===== ArrayRemove<AEGeometry*>  @0x000a040e  (66 bytes)
/* void ArrayRemove<AEGeometry*>(AEGeometry*, Array<AEGeometry*>&) */

void ArrayRemove<AEGeometry*>(AEGeometry *param_1,Array *param_2)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  AEGeometry *pAVar5;
  
  uVar3 = *(uint *)param_2;
  if (uVar3 == 0) {
    iVar2 = 0;
  }
  else {
    uVar4 = 0;
    iVar2 = 0;
    do {
      pAVar5 = *(AEGeometry **)(*(int *)(param_2 + 4) + uVar4 * 4);
      uVar4 = uVar4 + 1;
      if (pAVar5 != param_1) {
        *(AEGeometry **)(*(int *)(param_2 + 4) + iVar2 * 4) = pAVar5;
        iVar2 = iVar2 + 1;
      }
    } while (uVar4 < uVar3);
  }
  *(int *)param_2 = iVar2;
  if (iVar2 == 0) {
    iVar2 = 1;
  }
  *(int *)(param_2 + 8) = iVar2;
  pvVar1 = realloc(*(void **)(param_2 + 4),iVar2 << 2);
  *(void **)(param_2 + 4) = pvVar1;
  return;
}

// ===== ArraySetLength<Item*>  @0x000a0e84  (52 bytes)
/* void ArraySetLength<Item*>(unsigned int, Array<Item*>&) */

void ArraySetLength<Item*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArraySetLength<Ship*>  @0x000a1b44  (52 bytes)
/* void ArraySetLength<Ship*>(unsigned int, Array<Ship*>&) */

void ArraySetLength<Ship*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArraySetLength<int>  @0x000a1df8  (52 bytes)
/* void ArraySetLength<int>(unsigned int, Array<int>&) */

void ArraySetLength<int>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArraySetLength<Agent*>  @0x000a268c  (52 bytes)
/* void ArraySetLength<Agent*>(unsigned int, Array<Agent*>&) */

void ArraySetLength<Agent*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArrayReleaseClasses<Objective*>  @0x000a3662  (66 bytes)
/* void ArrayReleaseClasses<Objective*>(Array<Objective*>&) */

void ArrayReleaseClasses<Objective*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  Objective *this;
  uint uVar3;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      this = *(Objective **)((int)pvVar1 + uVar3 * 4);
      if (this != (Objective *)0x0) {
        pvVar1 = (void *)Objective::~Objective(this);
        operator_delete(pvVar1);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar3 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArrayReleaseClasses<AEGeometry*>  @0x000a3f08  (66 bytes)
/* void ArrayReleaseClasses<AEGeometry*>(Array<AEGeometry*>&) */

void ArrayReleaseClasses<AEGeometry*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  AEGeometry *this;
  uint uVar3;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      this = *(AEGeometry **)((int)pvVar1 + uVar3 * 4);
      if (this != (AEGeometry *)0x0) {
        pvVar1 = (void *)AEGeometry::~AEGeometry(this);
        operator_delete(pvVar1);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar3 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArrayReleaseClasses<RepairBeam*>  @0x000a6046  (66 bytes)
/* void ArrayReleaseClasses<RepairBeam*>(Array<RepairBeam*>&) */

void ArrayReleaseClasses<RepairBeam*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  RepairBeam *this;
  uint uVar3;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      this = *(RepairBeam **)((int)pvVar1 + uVar3 * 4);
      if (this != (RepairBeam *)0x0) {
        pvVar1 = (void *)RepairBeam::~RepairBeam(this);
        operator_delete(pvVar1);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar3 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArraySetLength<Array<Gun*>*>  @0x000af048  (52 bytes)
/* void ArraySetLength<Array<Gun*>*>(unsigned int, Array<Array<Gun*>*>&) */

void ArraySetLength<Array<Gun*>*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArraySetLength<Gun*>  @0x000af07c  (52 bytes)
/* void ArraySetLength<Gun*>(unsigned int, Array<Gun*>&) */

void ArraySetLength<Gun*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArrayReleaseClasses<Gun*>  @0x000af140  (66 bytes)
/* void ArrayReleaseClasses<Gun*>(Array<Gun*>&) */

void ArrayReleaseClasses<Gun*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  Gun *this;
  uint uVar3;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      this = *(Gun **)((int)pvVar1 + uVar3 * 4);
      if (this != (Gun *)0x0) {
        pvVar1 = (void *)Gun::~Gun(this);
        operator_delete(pvVar1);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar3 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArrayReleaseClasses<Array<Gun*>*>  @0x000af182  (70 bytes)
/* void ArrayReleaseClasses<Array<Gun*>*>(Array<Array<Gun*>*>&) */

void ArrayReleaseClasses<Array<Gun*>*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  void *pvVar3;
  uint uVar4;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar4 = 0;
    do {
      pvVar3 = *(void **)((int)pvVar1 + uVar4 * 4);
      if (pvVar3 != (void *)0x0) {
        if (*(void **)((int)pvVar3 + 4) != (void *)0x0) {
          operator_delete__(*(void **)((int)pvVar3 + 4));
        }
        operator_delete(pvVar3);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar4 * 4) = 0;
      uVar4 = uVar4 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar4 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArraySetLength<BoundingVolume*>  @0x000b1bb0  (52 bytes)
/* void ArraySetLength<BoundingVolume*>(unsigned int, Array<BoundingVolume*>&) */

void ArraySetLength<BoundingVolume*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArrayReleaseClasses<SpacePoint*>  @0x000b2648  (66 bytes)
/* void ArrayReleaseClasses<SpacePoint*>(Array<SpacePoint*>&) */

void ArrayReleaseClasses<SpacePoint*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  SpacePoint *this;
  uint uVar3;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      this = *(SpacePoint **)((int)pvVar1 + uVar3 * 4);
      if (this != (SpacePoint *)0x0) {
        pvVar1 = (void *)SpacePoint::~SpacePoint(this);
        operator_delete(pvVar1);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar3 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArrayReleaseClasses<Ship*>  @0x000b3988  (66 bytes)
/* void ArrayReleaseClasses<Ship*>(Array<Ship*>&) */

void ArrayReleaseClasses<Ship*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  Ship *this;
  uint uVar3;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      this = *(Ship **)((int)pvVar1 + uVar3 * 4);
      if (this != (Ship *)0x0) {
        pvVar1 = (void *)Ship::~Ship(this);
        operator_delete(pvVar1);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar3 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArrayReleaseClasses<Item*>  @0x000b39ca  (66 bytes)
/* void ArrayReleaseClasses<Item*>(Array<Item*>&) */

void ArrayReleaseClasses<Item*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  Item *this;
  uint uVar3;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      this = *(Item **)((int)pvVar1 + uVar3 * 4);
      if (this != (Item *)0x0) {
        pvVar1 = (void *)Item::~Item(this);
        operator_delete(pvVar1);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar3 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArrayRemove<Ship*>  @0x000b3af8  (66 bytes)
/* void ArrayRemove<Ship*>(Ship*, Array<Ship*>&) */

void ArrayRemove<Ship*>(Ship *param_1,Array *param_2)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  Ship *pSVar5;
  
  uVar3 = *(uint *)param_2;
  if (uVar3 == 0) {
    iVar2 = 0;
  }
  else {
    uVar4 = 0;
    iVar2 = 0;
    do {
      pSVar5 = *(Ship **)(*(int *)(param_2 + 4) + uVar4 * 4);
      uVar4 = uVar4 + 1;
      if (pSVar5 != param_1) {
        *(Ship **)(*(int *)(param_2 + 4) + iVar2 * 4) = pSVar5;
        iVar2 = iVar2 + 1;
      }
    } while (uVar4 < uVar3);
  }
  *(int *)param_2 = iVar2;
  if (iVar2 == 0) {
    iVar2 = 1;
  }
  *(int *)(param_2 + 8) = iVar2;
  pvVar1 = realloc(*(void **)(param_2 + 4),iVar2 << 2);
  *(void **)(param_2 + 4) = pvVar1;
  return;
}

// ===== ArrayReleaseClasses<Agent*>  @0x000b3c88  (66 bytes)
/* void ArrayReleaseClasses<Agent*>(Array<Agent*>&) */

void ArrayReleaseClasses<Agent*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  Agent *this;
  uint uVar3;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      this = *(Agent **)((int)pvVar1 + uVar3 * 4);
      if (this != (Agent *)0x0) {
        pvVar1 = (void *)Agent::~Agent(this);
        operator_delete(pvVar1);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar3 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArraySetLength<AEGeometry*>  @0x000b4104  (52 bytes)
/* void ArraySetLength<AEGeometry*>(unsigned int, Array<AEGeometry*>&) */

void ArraySetLength<AEGeometry*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArraySetLength<float>  @0x000b4138  (52 bytes)
/* void ArraySetLength<float>(unsigned int, Array<float>&) */

void ArraySetLength<float>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArraySetLength<Mission*>  @0x000b5eb4  (52 bytes)
/* void ArraySetLength<Mission*>(unsigned int, Array<Mission*>&) */

void ArraySetLength<Mission*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArraySetLength<Station*>  @0x000b5ee8  (52 bytes)
/* void ArraySetLength<Station*>(unsigned int, Array<Station*>&) */

void ArraySetLength<Station*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArraySetLength<bool>  @0x000b5f1c  (48 bytes)
/* void ArraySetLength<bool>(unsigned int, Array<bool>&) */

void ArraySetLength<bool>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr(pvVar1,uVar2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArrayReleaseClasses<Station*>  @0x000b5fe6  (66 bytes)
/* void ArrayReleaseClasses<Station*>(Array<Station*>&) */

void ArrayReleaseClasses<Station*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  Station *this;
  uint uVar3;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      this = *(Station **)((int)pvVar1 + uVar3 * 4);
      if (this != (Station *)0x0) {
        pvVar1 = (void *)Station::~Station(this);
        operator_delete(pvVar1);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar3 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArrayReleaseClasses<Wanted*>  @0x000b6028  (66 bytes)
/* void ArrayReleaseClasses<Wanted*>(Array<Wanted*>&) */

void ArrayReleaseClasses<Wanted*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  Wanted *this;
  uint uVar3;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      this = *(Wanted **)((int)pvVar1 + uVar3 * 4);
      if (this != (Wanted *)0x0) {
        pvVar1 = (void *)Wanted::~Wanted(this);
        operator_delete(pvVar1);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar3 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArrayReleaseClasses<SolarSystem*>  @0x000ba748  (66 bytes)
/* void ArrayReleaseClasses<SolarSystem*>(Array<SolarSystem*>&) */

void ArrayReleaseClasses<SolarSystem*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  SolarSystem *this;
  uint uVar3;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      this = *(SolarSystem **)((int)pvVar1 + uVar3 * 4);
      if (this != (SolarSystem *)0x0) {
        pvVar1 = (void *)SolarSystem::~SolarSystem(this);
        operator_delete(pvVar1);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar3 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArrayReleaseClasses<BluePrint*>  @0x000baec8  (66 bytes)
/* void ArrayReleaseClasses<BluePrint*>(Array<BluePrint*>&) */

void ArrayReleaseClasses<BluePrint*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  BluePrint *this;
  uint uVar3;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      this = *(BluePrint **)((int)pvVar1 + uVar3 * 4);
      if (this != (BluePrint *)0x0) {
        pvVar1 = (void *)BluePrint::~BluePrint(this);
        operator_delete(pvVar1);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar3 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArraySetLength<BluePrint*>  @0x000baf0a  (52 bytes)
/* void ArraySetLength<BluePrint*>(unsigned int, Array<BluePrint*>&) */

void ArraySetLength<BluePrint*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArrayReleaseClasses<PendingProduct*>  @0x000baf3e  (66 bytes)
/* void ArrayReleaseClasses<PendingProduct*>(Array<PendingProduct*>&) */

void ArrayReleaseClasses<PendingProduct*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  PendingProduct *this;
  uint uVar3;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      this = *(PendingProduct **)((int)pvVar1 + uVar3 * 4);
      if (this != (PendingProduct *)0x0) {
        pvVar1 = (void *)PendingProduct::~PendingProduct(this);
        operator_delete(pvVar1);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar3 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArrayReleaseClasses<AbstractGun*>  @0x000bb3ce  (62 bytes)
/* void ArrayReleaseClasses<AbstractGun*>(Array<AbstractGun*>&) */

void ArrayReleaseClasses<AbstractGun*>(Array *param_1)

{
  void *pvVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar3 = *(uint *)(param_1 + 8);
  if (uVar3 != 0) {
    uVar4 = 0;
    do {
      piVar2 = *(int **)((int)pvVar1 + uVar4 * 4);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 4))(piVar2);
        pvVar1 = *(void **)(param_1 + 4);
        uVar3 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar4 * 4) = 0;
      uVar4 = uVar4 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar4 < uVar3);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArrayReleaseClasses<KIPlayer*>  @0x000bb40c  (62 bytes)
/* void ArrayReleaseClasses<KIPlayer*>(Array<KIPlayer*>&) */

void ArrayReleaseClasses<KIPlayer*>(Array *param_1)

{
  void *pvVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar3 = *(uint *)(param_1 + 8);
  if (uVar3 != 0) {
    uVar4 = 0;
    do {
      piVar2 = *(int **)((int)pvVar1 + uVar4 * 4);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 4))(piVar2);
        pvVar1 = *(void **)(param_1 + 4);
        uVar3 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar4 * 4) = 0;
      uVar4 = uVar4 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar4 < uVar3);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArrayReleaseClasses<RadioMessage*>  @0x000bb44a  (66 bytes)
/* void ArrayReleaseClasses<RadioMessage*>(Array<RadioMessage*>&) */

void ArrayReleaseClasses<RadioMessage*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  RadioMessage *this;
  uint uVar3;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      this = *(RadioMessage **)((int)pvVar1 + uVar3 * 4);
      if (this != (RadioMessage *)0x0) {
        pvVar1 = (void *)RadioMessage::~RadioMessage(this);
        operator_delete(pvVar1);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar3 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArraySetLength<KIPlayer*>  @0x000cd1e6  (52 bytes)
/* void ArraySetLength<KIPlayer*>(unsigned int, Array<KIPlayer*>&) */

void ArraySetLength<KIPlayer*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArraySetLength<AbstractGun*>  @0x000d3b10  (52 bytes)
/* void ArraySetLength<AbstractGun*>(unsigned int, Array<AbstractGun*>&) */

void ArraySetLength<AbstractGun*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArraySetLength<Player*>  @0x000d3b44  (52 bytes)
/* void ArraySetLength<Player*>(unsigned int, Array<Player*>&) */

void ArraySetLength<Player*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArraySetLength<RadioMessage*>  @0x000d3dcc  (52 bytes)
/* void ArraySetLength<RadioMessage*>(unsigned int, Array<RadioMessage*>&) */

void ArraySetLength<RadioMessage*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArraySetLength<GameRecord*>  @0x000dc544  (52 bytes)
/* void ArraySetLength<GameRecord*>(unsigned int, Array<GameRecord*>&) */

void ArraySetLength<GameRecord*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArraySetLength<PendingProduct*>  @0x000df510  (52 bytes)
/* void ArraySetLength<PendingProduct*>(unsigned int, Array<PendingProduct*>&) */

void ArraySetLength<PendingProduct*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArraySetLength<Wanted*>  @0x000df544  (52 bytes)
/* void ArraySetLength<Wanted*>(unsigned int, Array<Wanted*>&) */

void ArraySetLength<Wanted*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArraySetLength<signed_char*>  @0x000e18e4  (52 bytes)
/* void ArraySetLength<signed char*>(unsigned int, Array<signed char*>&) */

void ArraySetLength<signed_char*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArrayReleaseArrays<signed_char*>  @0x000e1918  (60 bytes)
/* void ArrayReleaseArrays<signed char*>(Array<signed char*>&) */

void ArrayReleaseArrays<signed_char*>(Array *param_1)

{
  void *pvVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar3 = *(uint *)(param_1 + 8);
  if (uVar3 != 0) {
    uVar4 = 0;
    do {
      pvVar2 = *(void **)((int)pvVar1 + uVar4 * 4);
      if (pvVar2 != (void *)0x0) {
        operator_delete__(pvVar2);
        pvVar1 = *(void **)(param_1 + 4);
        uVar3 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar4 * 4) = 0;
      uVar4 = uVar4 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar4 < uVar3);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_SetOrigamiSuperClub  @0x000e1af4  (62 bytes)
void Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_SetOrigamiSuperClub
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uStack_d;
  int local_c;
  
  local_c = __stack_chk_guard;
  g_android_origami_super_club = (**(code **)(*param_1 + 0x2a4))(param_1,param_3,&uStack_d);
  if (__stack_chk_guard != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_ReleaseOrigamiSuperClub  @0x000e1b40  (20 bytes)
void Java_net_fishlabs_gof2hdallandroid2012_GOF2HD2012_ReleaseOrigamiSuperClub
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
                    /* WARNING: Could not recover jumptable at 0x000e1b52. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,g_android_origami_super_club);
  return;
}

// ===== loadingScreen  @0x000e1b58  (682 bytes)
/* loadingScreen(AbyssEngine::PaintCanvas*, int, void*) */

void loadingScreen(PaintCanvas *param_1,int param_2,void *param_3)

{
  PaintCanvas *this;
  Globals *this_00;
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  String *pSVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint in_fpscr;
  float fVar11;
  float fVar12;
  float fVar13;
  String aSStack_38 [8];
  uint local_30;
  uint local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  AbyssEngine::PaintCanvas::ClearBuffer((uint)param_1);
  AbyssEngine::PaintCanvas::Begin2d(param_1);
  AbyssEngine::PaintCanvas::SetColor((uint)param_1);
  if (param_3 != (void *)0x0) {
    uVar8 = *(uint *)param_3;
    sVar1 = GameText::getLanguage();
    if ((sVar1 == 9) ||
       (iVar2 = AbyssEngine::PaintCanvas::ResourceLoaded(param_1,uVar8,1), iVar2 == 0)) {
      this_00 = Globals::globals;
      iVar2 = GameText::getLanguage();
      Globals::loadFont(this_00,iVar2);
      *(uint *)param_3 = uVar8;
    }
    local_2c = 0xffffffff;
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x504,&local_2c);
    local_30 = 0xffffffff;
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x505,&local_30);
    iVar2 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,local_30);
    iVar3 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,local_2c);
    iVar4 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,local_30);
    iVar10 = *(int *)(Globals::layout + 0x27c);
    Layout::drawBG(Globals::layout);
    Layout::drawHeader(Globals::layout);
    Layout::drawEmptyFooter(Globals::layout,false);
    iVar7 = 0x189;
    if (Globals::gameSaving != '\0') {
      iVar7 = 0x18a;
    }
    pSVar5 = (String *)GameText::getText(Globals::gameText,iVar7);
    AbyssEngine::String::String(aSStack_38,pSVar5,false);
    iVar7 = Globals::w;
    this = Globals::Canvas;
    iVar9 = 100 - param_2;
    if (param_2 < 0) {
      iVar9 = 0;
    }
    if (iVar9 < 0) {
      iVar9 = 0;
    }
    iVar6 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,uVar8,aSStack_38);
    AbyssEngine::PaintCanvas::DrawString
              (this,uVar8,aSStack_38,(iVar7 >> 1) - iVar6 / 2,
               (((Globals::h >> 1) - iVar10) - *(int *)(Globals::layout + 4)) -
               *(int *)(Globals::layout + 0x280),false);
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,local_2c,(Globals::w >> 1) - (iVar3 >> 1),(Globals::h >> 1) - iVar10)
    ;
    sVar1 = GameText::getLanguage();
    if (sVar1 == 9) {
      fVar11 = (float)VectorSignedToFloat(iVar9,(byte)(in_fpscr >> 0x16) & 3);
      fVar13 = (float)VectorSignedToFloat(iVar2,(byte)(in_fpscr >> 0x16) & 3);
      fVar11 = fVar11 * 0.01 * fVar13;
      fVar12 = (float)VectorSignedToFloat((Globals::w >> 1) + (iVar2 >> 1),
                                          (byte)(in_fpscr >> 0x16) & 3);
      AbyssEngine::PaintCanvas::DrawRegion2D
                (Globals::Canvas,local_30,(int)(fVar13 - fVar11),0,(int)fVar11,iVar4,
                 (float)(int)fVar11,0,0,0,(int)(fVar12 - fVar11));
    }
    else {
      fVar11 = (float)VectorSignedToFloat(iVar9,(byte)(in_fpscr >> 0x16) & 3);
      fVar12 = (float)VectorSignedToFloat(iVar2,(byte)(in_fpscr >> 0x16) & 3);
      iVar3 = (int)(fVar11 * 0.01 * fVar12);
      AbyssEngine::PaintCanvas::DrawRegion2D
                (Globals::Canvas,local_30,0,0,iVar3,iVar4,(float)iVar3,0,0,0,
                 (Globals::w >> 1) - (iVar2 >> 1));
    }
    AbyssEngine::String::~String(aSStack_38);
  }
  AbyssEngine::PaintCanvas::End2d(param_1);
  AbyssEngine::PaintCanvas::SwapBuffer();
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== OnDestroyApplication  @0x000e1e64  (108 bytes)
/* OnDestroyApplication(AbyssEngine::Engine*) */

void OnDestroyApplication(Engine *param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  
  puVar1 = (undefined4 *)
           AbyssEngine::ApplicationManager::GetApplicationData
                     (*(ApplicationManager **)(param_1 + 0x28));
  if ((Globals *)*puVar1 != (Globals *)0x0) {
    pvVar2 = (void *)Globals::~Globals((Globals *)*puVar1);
    operator_delete(pvVar2);
  }
  *puVar1 = 0;
  if (puVar1 != (undefined4 *)0x0) {
    AbyssEngine::String::~String((String *)(puVar1 + 0x27));
    AbyssEngine::String::~String((String *)(puVar1 + 0x24));
    AbyssEngine::String::~String((String *)(puVar1 + 0x20));
    AbyssEngine::String::~String((String *)(puVar1 + 0x1e));
    AbyssEngine::String::~String((String *)(puVar1 + 0x1c));
    AbyssEngine::String::~String((String *)(puVar1 + 10));
    AbyssEngine::String::~String((String *)(puVar1 + 8));
    AbyssEngine::String::~String((String *)(puVar1 + 6));
    operator_delete(puVar1);
    return;
  }
  return;
}

// ===== OnCreateApplication  @0x000e1ed0  (1518 bytes)
/* OnCreateApplication(AbyssEngine::Engine*) */

void OnCreateApplication(Engine *param_1)

{
  GameData *this;
  Globals *pGVar1;
  int iVar2;
  int iVar3;
  GameText *this_00;
  int iVar4;
  MGame *this_01;
  ModMainMenu *this_02;
  ModStation *this_03;
  MTitle *this_04;
  ApplicationManager *pAVar5;
  String *pSVar6;
  PaintCanvas *pPVar7;
  bool bVar8;
  String aSStack_34 [8];
  String aSStack_2c [8];
  int local_24;
  
  local_24 = __stack_chk_guard;
  this = operator_new(0xa8);
  __aeabi_memclr4(this,0xa8);
  GameData::GameData(this);
  this[4] = (GameData)0x0;
  this[5] = (GameData)0x0;
  this[0xc] = (GameData)0x0;
  this[0xd] = (GameData)0x0;
  this[0x14] = (GameData)0x0;
  this[0xe] = (GameData)0x0;
  this[0x15] = (GameData)0x0;
  *(undefined4 *)(this + 0x10) = 0xffffffff;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  this[0x38] = (GameData)0x0;
  *(undefined4 *)(this + 0x3c) = 0xffffffff;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x54) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x48) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  this[0x40] = (GameData)0x1;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0x65) = 0;
  *(undefined4 *)(this + 0x61) = 0;
  this[0x6b] = (GameData)0x0;
  *(undefined2 *)(this + 0x69) = 0;
  pGVar1 = operator_new(8);
  Globals::Globals(pGVar1);
  *(Globals **)this = pGVar1;
  iVar2 = AbyssEngine::PaintCanvas::GetWidth();
  iVar3 = AbyssEngine::PaintCanvas::GetHeight();
  bVar8 = SBORROW4(iVar2,0x800);
  iVar4 = iVar2 + -0x800;
  if (0x7ff < iVar2) {
    bVar8 = SBORROW4(iVar3,0x5a0);
    iVar4 = iVar3 + -0x5a0;
  }
  if (iVar4 < 0 == bVar8) {
LAB_000e1ff0:
    Globals::retinaDisplay = true;
    Globals::iPad = '\x01';
    Globals::iPadLarge = 1;
  }
  else {
    bVar8 = SBORROW4(iVar2,0x6a4);
    iVar4 = iVar2 + -0x6a4;
    if (0x6a3 < iVar2) {
      bVar8 = SBORROW4(iVar3,0x468);
      iVar4 = iVar3 + -0x468;
    }
    if (iVar4 < 0 == bVar8) goto LAB_000e1ff0;
    bVar8 = SBORROW4(iVar2,0x6a4);
    iVar4 = iVar2 + -0x6a4;
    if (0x6a3 < iVar2) {
      bVar8 = SBORROW4(iVar3,0x438);
      iVar4 = iVar3 + -0x438;
    }
    if (iVar4 < 0 == bVar8) goto LAB_000e1ff0;
    bVar8 = SBORROW4(iVar2,0x5a0);
    iVar4 = iVar2 + -0x5a0;
    if (0x59f < iVar2) {
      bVar8 = SBORROW4(iVar3,0x438);
      iVar4 = iVar3 + -0x438;
    }
    if (iVar4 < 0 != bVar8) {
      bVar8 = SBORROW4(iVar2,0x400);
      iVar4 = iVar2 + -0x400;
      if (0x3ff < iVar2) {
        bVar8 = SBORROW4(iVar3,0x2f0);
        iVar4 = iVar3 + -0x2f0;
      }
      if (iVar4 < 0 == bVar8) {
        Globals::n9 = 0;
        if ((iVar2 == 0x500) && (0x2ff < iVar3)) {
          Globals::retinaDisplay = true;
          Globals::iPad = '\0';
          Globals::iPadLarge = 0;
          goto LAB_000e2008;
        }
        Globals::retinaDisplay = false;
        Globals::iPad = '\x01';
      }
      else {
        bVar8 = SBORROW4(iVar2,0x3c0);
        iVar4 = iVar2 + -0x3c0;
        if (0x3bf < iVar2) {
          bVar8 = SBORROW4(iVar3,0x21c);
          iVar4 = iVar3 + -0x21c;
        }
        if (iVar4 < 0 != bVar8) {
          bVar8 = SBORROW4(iVar2,0x360);
          iVar4 = iVar2 + -0x360;
          if (0x35f < iVar2) {
            bVar8 = SBORROW4(iVar3,0x1e0);
            iVar4 = iVar3 + -0x1e0;
          }
          if (iVar4 < 0 == bVar8) {
            Globals::n9 = 1;
            Globals::retinaDisplay = false;
            Globals::iPad = '\0';
            Globals::iPadLarge = 0;
            goto LAB_000e2008;
          }
          Globals::iPad = '\0';
          goto LAB_000e2390;
        }
        Globals::retinaDisplay = iVar3 != 0x21c;
        Globals::iPad = '\0';
      }
      Globals::n9 = 0;
      Globals::iPadLarge = 0;
      goto LAB_000e2008;
    }
    Globals::iPad = '\x01';
LAB_000e2390:
    Globals::retinaDisplay = false;
    Globals::iPadLarge = 0;
  }
  Globals::n9 = 0;
LAB_000e2008:
  Globals::iPadHD = 0;
  AbyssEngine::String::String(aSStack_2c,"",false);
  AbyssEngine::String::operator=((String *)(this + 0x90),aSStack_2c);
  AbyssEngine::String::~String(aSStack_2c);
  this[0x8d] = (GameData)0x0;
  AbyssEngine::String::String(aSStack_2c,"",false);
  AbyssEngine::String::operator=((String *)(this + 0x9c),aSStack_2c);
  AbyssEngine::String::~String(aSStack_2c);
  this[0x98] = (GameData)0x0;
  this[0xa4] = (GameData)0x0;
  *(undefined2 *)(this + 0x6c) = 0;
  this[0x6e] = (GameData)0x0;
  AbyssEngine::String::String(aSStack_2c,"",false);
  AbyssEngine::String::operator=((String *)(this + 0x70),aSStack_2c);
  AbyssEngine::String::~String(aSStack_2c);
  AbyssEngine::String::String(aSStack_2c,"",false);
  AbyssEngine::String::operator=((String *)(this + 0x78),aSStack_2c);
  AbyssEngine::String::~String(aSStack_2c);
  AbyssEngine::String::String(aSStack_2c,"",false);
  AbyssEngine::String::operator=((String *)(this + 0x80),aSStack_2c);
  AbyssEngine::String::~String(aSStack_2c);
  this[0x8c] = (GameData)0x0;
  *(undefined4 *)(this + 0x88) = 0;
  Globals::iPadAssetsWithLowerRes = Globals::iPad != '\0' && (iVar2 < 0x400 && iVar3 < 0x300);
  Globals::switch_to_target_setting = 0xffffffff;
  Globals::enterSpaceLounge = 0;
  BuildResourceList(param_1);
  Globals::appManager = *(undefined4 **)(param_1 + 0x28);
  Globals::Canvas = *Globals::appManager;
  Globals::w = AbyssEngine::PaintCanvas::GetWidth();
  Globals::h = AbyssEngine::PaintCanvas::GetHeight();
  this_00 = operator_new(0x1c);
  GameText::GameText(this_00);
  Globals::gameText = this_00;
  GameText::setLanguage(this_00,(short)AbyssEngine::Engine::countryCode,0xd49);
  pGVar1 = Globals::globals;
  iVar4 = GameText::getLanguage();
  Globals::loadFont(pGVar1,iVar4);
  Globals::init(*(ApplicationManager **)this,*(Engine **)(param_1 + 0x28));
  AbyssEngine::ApplicationManager::SetApplicationData(*(ApplicationManager **)(param_1 + 0x28),this)
  ;
  AbyssEngine::ApplicationManager::SetLoadingCallback
            (*(ApplicationManager **)(param_1 + 0x28),loadingScreen,&Globals::font);
  this_01 = operator_new(0x1f0);
  MGame::MGame(this_01);
  AbyssEngine::ApplicationManager::RegisterApplicationModule
            (*(ApplicationManager **)(param_1 + 0x28),2,(IApplicationModule *)this_01);
  pAVar5 = *(ApplicationManager **)(param_1 + 0x28);
  this_02 = operator_new(0x2c);
  ModMainMenu::ModMainMenu(this_02);
  AbyssEngine::ApplicationManager::RegisterApplicationModule(pAVar5,1,(IApplicationModule *)this_02)
  ;
  pAVar5 = *(ApplicationManager **)(param_1 + 0x28);
  this_03 = operator_new(0x148);
  ModStation::ModStation(this_03);
  AbyssEngine::ApplicationManager::RegisterApplicationModule(pAVar5,5,(IApplicationModule *)this_03)
  ;
  pAVar5 = *(ApplicationManager **)(param_1 + 0x28);
  this_04 = operator_new(0x20);
  MTitle::MTitle(this_04);
  AbyssEngine::ApplicationManager::RegisterApplicationModule(pAVar5,0,(IApplicationModule *)this_04)
  ;
  AbyssEngine::ApplicationManager::CheatSetCallback
            (*(ApplicationManager **)(param_1 + 0x28),(_func_void_int_void_ptr *)&DAT_000e26ef,
             this_01);
  pSVar6 = *(String **)(param_1 + 0x28);
  AbyssEngine::String::String(aSStack_2c,"754753835",false);
  AbyssEngine::ApplicationManager::CheatAddCode(pSVar6,(int)aSStack_2c);
  AbyssEngine::String::~String(aSStack_2c);
  pSVar6 = *(String **)(param_1 + 0x28);
  AbyssEngine::String::String(aSStack_2c,"448366639",false);
  AbyssEngine::ApplicationManager::CheatAddCode(pSVar6,(int)aSStack_2c);
  AbyssEngine::String::~String(aSStack_2c);
  pSVar6 = *(String **)(param_1 + 0x28);
  AbyssEngine::String::String(aSStack_2c,"373352623",false);
  AbyssEngine::ApplicationManager::CheatAddCode(pSVar6,(int)aSStack_2c);
  AbyssEngine::String::~String(aSStack_2c);
  Layout::initTip(Globals::layout);
  Status::resetGame(Globals::status);
  AbyssEngine::Engine::vfc = 1;
  AbyssEngine::AERandom::reset(Globals::rnd);
  AbyssEngine::ApplicationManager::SetCurrentApplicationModule
            (*(ApplicationManager **)(param_1 + 0x28),0);
  AbyssEngine::Engine::clampTextures = 0;
  pPVar7 = (PaintCanvas *)**(undefined4 **)(param_1 + 0x28);
  AbyssEngine::String::String(aSStack_34,"data/textures/pow_texture.aei",false);
  AbyssEngine::PaintCanvas::TextureCreateGlobal(pPVar7,aSStack_34,2);
  AbyssEngine::String::~String(aSStack_34);
  AbyssEngine::Engine::clampTextures = 0;
  AbyssEngine::Engine::vboSupported = 1;
  param_1[100] = (Engine)0x0;
  AbyssEngine::Engine::lodBiasDiffuse = 0xbfa66666;
  AbyssEngine::Engine::lodBiasNormal = 0xbf000000;
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ArraySetLength<TouchButton*>  @0x000e9e80  (52 bytes)
/* void ArraySetLength<TouchButton*>(unsigned int, Array<TouchButton*>&) */

void ArraySetLength<TouchButton*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArrayReleaseClasses<TouchButton*>  @0x000ec6b4  (66 bytes)
/* void ArrayReleaseClasses<TouchButton*>(Array<TouchButton*>&) */

void ArrayReleaseClasses<TouchButton*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  TouchButton *this;
  uint uVar3;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      this = *(TouchButton **)((int)pvVar1 + uVar3 * 4);
      if (this != (TouchButton *)0x0) {
        pvVar1 = (void *)TouchButton::~TouchButton(this);
        operator_delete(pvVar1);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar3 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArraySetLength<int*>  @0x000efc40  (52 bytes)
/* void ArraySetLength<int*>(unsigned int, Array<int*>&) */

void ArraySetLength<int*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArrayReleaseClasses<BoundingVolume*>  @0x000f05f0  (66 bytes)
/* void ArrayReleaseClasses<BoundingVolume*>(Array<BoundingVolume*>&) */

void ArrayReleaseClasses<BoundingVolume*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  BoundingVolume *this;
  uint uVar3;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      this = *(BoundingVolume **)((int)pvVar1 + uVar3 * 4);
      if (this != (BoundingVolume *)0x0) {
        pvVar1 = (void *)BoundingVolume::~BoundingVolume(this);
        operator_delete(pvVar1);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar3 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArrayRemove<Item*>  @0x000f451e  (66 bytes)
/* void ArrayRemove<Item*>(Item*, Array<Item*>&) */

void ArrayRemove<Item*>(Item *param_1,Array *param_2)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  Item *pIVar5;
  
  uVar3 = *(uint *)param_2;
  if (uVar3 == 0) {
    iVar2 = 0;
  }
  else {
    uVar4 = 0;
    iVar2 = 0;
    do {
      pIVar5 = *(Item **)(*(int *)(param_2 + 4) + uVar4 * 4);
      uVar4 = uVar4 + 1;
      if (pIVar5 != param_1) {
        *(Item **)(*(int *)(param_2 + 4) + iVar2 * 4) = pIVar5;
        iVar2 = iVar2 + 1;
      }
    } while (uVar4 < uVar3);
  }
  *(int *)param_2 = iVar2;
  if (iVar2 == 0) {
    iVar2 = 1;
  }
  *(int *)(param_2 + 8) = iVar2;
  pvVar1 = realloc(*(void **)(param_2 + 4),iVar2 << 2);
  *(void **)(param_2 + 4) = pvVar1;
  return;
}

// ===== ArrayReleaseClasses<ImagePart*>  @0x000f504e  (66 bytes)
/* void ArrayReleaseClasses<ImagePart*>(Array<ImagePart*>&) */

void ArrayReleaseClasses<ImagePart*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  ImagePart *this;
  uint uVar3;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      this = *(ImagePart **)((int)pvVar1 + uVar3 * 4);
      if (this != (ImagePart *)0x0) {
        pvVar1 = (void *)ImagePart::~ImagePart(this);
        operator_delete(pvVar1);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar3 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== BuildResourceList  @0x000fd934  (200688 bytes)
/* decompile failed: Exception while decompiling 000fd934: Decompiler process died
 */

// ===== loadPortraits  @0x00135f90  (19306 bytes)
/* loadPortraits(AbyssEngine::Engine*) */

void loadPortraits(Engine *param_1)

{
  Resource *pRVar1;
  ResourceTexture *pRVar2;
  char *pcVar3;
  PaintCanvas *this;
  float fVar4;
  String aSStack_44 [8];
  String aSStack_3c [8];
  AbyssEngine aAStack_34 [8];
  AbyssEngine aAStack_2c [8];
  String aSStack_24 [8];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  this = (PaintCanvas *)**(undefined4 **)(param_1 + 0x28);
  if (Globals::iPadLarge == '\0') {
    if (Globals::iPadHD == '\0') {
      pcVar3 = "_ipad";
      if ((Globals::retinaDisplay == '\0' && Globals::iPad == '\0') && Globals::n9 == '\0') {
        pcVar3 = "";
      }
    }
    else {
      pcVar3 = "_ipad_1440";
    }
  }
  else {
    pcVar3 = "_ipad_large";
  }
  AbyssEngine::String::String(aSStack_24,pcVar3,false);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_0_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27d8;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_0_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27d9;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_0_2",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27da;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_0_3",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27db;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_0_4",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27dc;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_0_5",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27dd;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_0_6",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27de;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_0_7",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27df;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_0_8",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27e0;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_0_9",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27e1;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_0_10",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27e2;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_1_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27e3;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_1_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27e4;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_1_2",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27e5;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_1_3",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27e6;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_1_4",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27e7;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_1_5",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27e8;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_1_6",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27e9;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_1_7",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27ea;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_1_8",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27eb;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_1_9",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27ec;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_1_10",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27ed;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_2_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27ee;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_2_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27ef;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_2_2",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27f0;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_2_3",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27f1;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_2_4",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27f2;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_2_5",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27f3;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_2_6",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27f4;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_2_7",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27f5;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_2_8",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27f6;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_2_9",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27f7;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_2_10",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27f8;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_3_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27f9;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_3_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27fa;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_3_2",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27fb;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_3_3",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27fc;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_3_4",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27fd;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_3_5",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27fe;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_3_6",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x27ff;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_3_7",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2800;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_3_8",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2801;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_3_9",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2802;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/0_3_10",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2803;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/1_0_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2804;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/1_0_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2805;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/1_0_2",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2806;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/1_0_3",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2807;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/1_1_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2808;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/1_1_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2809;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/1_1_2",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x280a;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/1_1_3",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x280b;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/1_1_4",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x280c;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/1_2_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x280d;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/1_2_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x280e;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/1_2_2",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x280f;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/1_2_3",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2810;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/1_2_4",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2811;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/1_2_5",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2812;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/1_3_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2813;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/1_3_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2814;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/1_3_2",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2815;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/1_3_3",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2816;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/1_3_4",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2817;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/1_3_5",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2818;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/1_3_6",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2819;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/1_3_7",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x281a;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/1_3_8",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x281b;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/2_0_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x281c;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/2_0_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x281d;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/2_0_2",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x281e;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/2_0_3",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x281f;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/2_0_4",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2820;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/2_1_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2821;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/2_1_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2822;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/2_1_2",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2823;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/2_1_3",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2824;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/2_1_4",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2825;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/2_2_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2826;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/2_2_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2827;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/2_2_2",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2828;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/2_2_3",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2829;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/2_2_4",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x282a;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/2_3_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x282b;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/2_3_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x282c;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/2_3_2",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x282d;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/2_3_3",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x282e;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/2_3_4",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x282f;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/4_0_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2830;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/4_0_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2831;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/4_0_2",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2832;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/4_1_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2833;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/4_1_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2834;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/4_1_2",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2835;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/4_2_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2836;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/4_2_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2837;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/4_2_2",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2838;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/4_2_3",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2839;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/4_2_4",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x283a;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/4_3_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x283b;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/4_3_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x283c;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/4_3_2",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x283d;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/4_3_3",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x283e;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/6_0_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x283f;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/6_0_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2840;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/6_1_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2841;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/6_1_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2842;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/6_1_2",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2843;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/6_2_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2844;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/6_2_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2845;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/6_2_2",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2846;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/6_2_3",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2847;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/6_2_4",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2848;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/7_0_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2849;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/7_0_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x284a;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/7_1_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x284b;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/7_1_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x284c;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/7_2_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x284d;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/7_2_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x284e;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/7_2_2",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x284f;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/7_3_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2850;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/7_3_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2851;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/9_0_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2852;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/9_1_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2853;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/9_2_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2854;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/9_3_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2855;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/10_0_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2856;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/10_0_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2857;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/10_0_2",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2858;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/10_0_3",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2859;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/10_1_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x285a;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/10_1_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x285b;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/10_1_2",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x285c;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/10_1_3",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x285d;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/10_2_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x285e;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/10_2_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x285f;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/10_2_2",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2860;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/10_2_3",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2861;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/10_2_4",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2862;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/10_3_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2863;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/10_3_1",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2864;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/10_3_2",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2865;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/10_3_3",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2866;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/10_3_4",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2867;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/10_3_5",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2868;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/10_3_6",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x2869;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/11_3_2",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x286a;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/11_3_3",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x286b;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/12_0_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x286c;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/12_1_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x286d;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/12_2_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x286e;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  pRVar1 = operator_new(0x10);
  pRVar2 = operator_new(8);
  AbyssEngine::String::String(aSStack_3c,"data/textures/12_3_0",false);
  AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_24);
  AbyssEngine::String::String(aSStack_44,".aei",false);
  fVar4 = (float)AbyssEngine::operator+(aAStack_2c,aAStack_34,aSStack_44);
  AbyssEngine::ResourceTexture::ResourceTexture(pRVar2,aAStack_2c,fVar4);
  *(undefined2 *)pRVar1 = 0x286f;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(ResourceTexture **)(pRVar1 + 0xc) = pRVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  AbyssEngine::String::~String((String *)aAStack_2c);
  AbyssEngine::String::~String(aSStack_44);
  AbyssEngine::String::~String((String *)aAStack_34);
  AbyssEngine::String::~String(aSStack_3c);
  AbyssEngine::String::~String(aSStack_24);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== loadLowTexturesAndMaterials  @0x0013baec  (16924 bytes)
/* loadLowTexturesAndMaterials(AbyssEngine::Engine*) */

void loadLowTexturesAndMaterials(Engine *param_1)

{
  Resource *pRVar1;
  undefined4 *puVar2;
  int iVar3;
  void *pvVar4;
  undefined2 *puVar5;
  PaintCanvas *this;
  
  this = (PaintCanvas *)**(undefined4 **)(param_1 + 0x28);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_000_midorian_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_000_midorian_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 32000;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_001_terran_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_001_terran_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d01;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_002_pirates_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_002_pirates_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d02;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_003_midorian_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_003_midorian_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d03;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_004_nivelian_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_004_nivelian_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d04;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_005_terran_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_005_terran_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d05;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_006_midorian_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_006_midorian_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d06;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_007_terran_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_007_terran_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d07;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_008_void_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_008_void_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d08;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_009_vossk_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_009_vossk_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d09;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_010_terran_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_010_terran_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d0a;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_011_pirates_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_011_pirates_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d0b;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_012_nivelian_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_012_nivelian_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d0c;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_016_nivelian_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_016_nivelian_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d10;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_017_terran_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_017_terran_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d11;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_018_nivelian_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_018_nivelian_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d12;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_019_midorian_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_019_midorian_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d13;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_020_midorian_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_020_midorian_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d14;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_021_nivelian_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_021_nivelian_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d15;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_022_terran_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_022_terran_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d16;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_023_pirates_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_023_pirates_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d17;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_024_pirates_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_024_pirates_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d18;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_025_pirates_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_025_pirates_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d19;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_026_terran_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_026_terran_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d1a;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_027_terran_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_027_terran_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d1b;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_028_terran_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_028_terran_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d1c;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_029_pirates_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_029_pirates_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d1d;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_030_midorian_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_030_midorian_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d1e;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_031_nivelian_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_031_nivelian_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d1f;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_032_pirates_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_032_pirates_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d20;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_033_terran_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_033_terran_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d21;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_034_terran_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_034_terran_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d22;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_035_nivelian_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_035_nivelian_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d23;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_036_terran_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/ship_036_terran_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d24;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_000_midorian_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_000_midorian_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d64;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_001_terran_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_001_terran_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d65;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_002_pirates_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_002_pirates_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d66;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_003_midorian_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_003_midorian_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d67;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_004_nivelian_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_004_nivelian_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d68;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_005_terran_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_005_terran_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d69;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_006_midorian_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_006_midorian_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d6a;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_007_terran_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_007_terran_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d6b;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_008_void_normal_specular.aei")
  ;
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_008_void_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d6c;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/ship_009_vossk_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_009_vossk_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d6d;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_010_terran_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_010_terran_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d6e;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_011_pirates_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_011_pirates_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d6f;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_012_nivelian_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_012_nivelian_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d70;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_016_nivelian_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_016_nivelian_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d74;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_017_terran_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_017_terran_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d75;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_018_nivelian_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_018_nivelian_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d76;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_019_midorian_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_019_midorian_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d77;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_020_midorian_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_020_midorian_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d78;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_021_nivelian_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_021_nivelian_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d79;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_022_terran_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_022_terran_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d7a;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_023_pirates_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_023_pirates_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d7b;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_024_pirates_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_024_pirates_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d7c;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_025_pirates_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_025_pirates_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d7d;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_026_terran_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_026_terran_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d7e;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_027_terran_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_027_terran_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d7f;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_028_terran_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_028_terran_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d80;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_029_pirates_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_029_pirates_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d81;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_030_midorian_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_030_midorian_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d82;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_031_nivelian_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_031_nivelian_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d83;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_032_pirates_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_032_pirates_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d84;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_033_terran_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_033_terran_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d85;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_034_terran_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_034_terran_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d86;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_035_nivelian_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_035_nivelian_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d87;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/ship_036_terran_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/ship_036_terran_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7d88;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 32000;
  puVar5[1] = 0x7d64;
  *(undefined2 *)pRVar1 = 0x7dc8;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d01;
  puVar5[1] = 0x7d65;
  *(undefined2 *)pRVar1 = 0x7dc9;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d02;
  puVar5[1] = 0x7d66;
  *(undefined2 *)pRVar1 = 0x7dca;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d03;
  puVar5[1] = 0x7d67;
  *(undefined2 *)pRVar1 = 0x7dcb;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d04;
  puVar5[1] = 0x7d68;
  *(undefined2 *)pRVar1 = 0x7dcc;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d05;
  puVar5[1] = 0x7d69;
  *(undefined2 *)pRVar1 = 0x7dcd;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d06;
  puVar5[1] = 0x7d6a;
  *(undefined2 *)pRVar1 = 0x7dce;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d07;
  puVar5[1] = 0x7d6b;
  *(undefined2 *)pRVar1 = 0x7dcf;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d08;
  puVar5[1] = 0x7d6c;
  *(undefined2 *)pRVar1 = 0x7dd0;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d09;
  puVar5[1] = 0x7d6d;
  *(undefined2 *)pRVar1 = 0x7dd1;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d0a;
  puVar5[1] = 0x7d6e;
  *(undefined2 *)pRVar1 = 0x7dd2;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d0b;
  puVar5[1] = 0x7d6f;
  *(undefined2 *)pRVar1 = 0x7dd3;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d0c;
  puVar5[1] = 0x7d70;
  *(undefined2 *)pRVar1 = 0x7dd4;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d10;
  puVar5[1] = 0x7d74;
  *(undefined2 *)pRVar1 = 0x7dd8;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d11;
  puVar5[1] = 0x7d75;
  *(undefined2 *)pRVar1 = 0x7dd9;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d12;
  puVar5[1] = 0x7d76;
  *(undefined2 *)pRVar1 = 0x7dda;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d13;
  puVar5[1] = 0x7d77;
  *(undefined2 *)pRVar1 = 0x7ddb;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d14;
  puVar5[1] = 0x7d78;
  *(undefined2 *)pRVar1 = 0x7ddc;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d15;
  puVar5[1] = 0x7d79;
  *(undefined2 *)pRVar1 = 0x7ddd;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d16;
  puVar5[1] = 0x7d7a;
  *(undefined2 *)pRVar1 = 0x7dde;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d17;
  puVar5[1] = 0x7d7b;
  *(undefined2 *)pRVar1 = 0x7ddf;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d18;
  puVar5[1] = 0x7d7c;
  *(undefined2 *)pRVar1 = 0x7de0;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d19;
  puVar5[1] = 0x7d7d;
  *(undefined2 *)pRVar1 = 0x7de1;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d1a;
  puVar5[1] = 0x7d7e;
  *(undefined2 *)pRVar1 = 0x7de2;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d1b;
  puVar5[1] = 0x7d7f;
  *(undefined2 *)pRVar1 = 0x7de3;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d1c;
  puVar5[1] = 0x7d80;
  *(undefined2 *)pRVar1 = 0x7de4;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d1d;
  puVar5[1] = 0x7d81;
  *(undefined2 *)pRVar1 = 0x7de5;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d1e;
  puVar5[1] = 0x7d82;
  *(undefined2 *)pRVar1 = 0x7de6;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d1f;
  puVar5[1] = 0x7d83;
  *(undefined2 *)pRVar1 = 0x7de7;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d20;
  puVar5[1] = 0x7d84;
  *(undefined2 *)pRVar1 = 0x7de8;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d21;
  puVar5[1] = 0x7d85;
  *(undefined2 *)pRVar1 = 0x7de9;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d22;
  puVar5[1] = 0x7d86;
  *(undefined2 *)pRVar1 = 0x7dea;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d23;
  puVar5[1] = 0x7d87;
  *(undefined2 *)pRVar1 = 0x7deb;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7d24;
  puVar5[1] = 0x7d88;
  *(undefined2 *)pRVar1 = 0x7dec;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/stations/stations_terran_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/stations/stations_terran_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7e96;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/stations/stations_terran_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/stations/stations_terran_normal_specular.aei"
                 ,iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7e97;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/stations/stations_pirates_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/stations/stations_pirates_diffuse.aei"
                 ,iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x7e94;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/stations/stations_pirates_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/stations/stations_pirates_normal_specular.aei"
                 ,iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x7e95;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/stations/stations_nivelian_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/stations/stations_nivelian_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7e92;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/stations/stations_nivelian_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/stations/stations_nivelian_normal_specular.aei"
                 ,iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7e93;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/stations/stations_midorian_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/stations/stations_midorian_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7e90;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/stations/stations_midorian_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/stations/stations_midorian_normal_specular.aei"
                 ,iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7e91;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/stations/stations_vossk_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/stations/stations_vossk_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7e9a;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/stations/stations_vossk_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/stations/stations_vossk_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7e9b;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/stations/stations_void_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/stations/stations_void_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7e98;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/stations/stations_void_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/stations/stations_void_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x7e99;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7e96;
  puVar5[1] = 0x7e97;
  *(undefined2 *)pRVar1 = 0x7e9d;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  puVar5[7] = 0xffff;
  *(undefined4 *)(puVar5 + 5) = 0xffffffff;
  *(undefined4 *)(puVar5 + 3) = 0xffffffff;
  *(undefined4 *)(puVar5 + 1) = 0xffffffff;
  *(undefined2 *)pRVar1 = 0x7e9c;
  *puVar5 = 0x7e96;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7e92;
  puVar5[1] = 0x7e93;
  *(undefined2 *)pRVar1 = 0x7e9e;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  puVar5[7] = 0xffff;
  *(undefined4 *)(puVar5 + 5) = 0xffffffff;
  *(undefined4 *)(puVar5 + 3) = 0xffffffff;
  *(undefined4 *)(puVar5 + 1) = 0xffffffff;
  *(undefined2 *)pRVar1 = 0x7e9f;
  *puVar5 = 0x7e92;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7e94;
  puVar5[1] = 0x7e95;
  *(undefined2 *)pRVar1 = 0x7ea9;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  puVar5[7] = 0xffff;
  *(undefined4 *)(puVar5 + 5) = 0xffffffff;
  *(undefined4 *)(puVar5 + 3) = 0xffffffff;
  *(undefined4 *)(puVar5 + 1) = 0xffffffff;
  *(undefined2 *)pRVar1 = 0x7eaa;
  *puVar5 = 0x7e94;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7e90;
  puVar5[1] = 0x7e91;
  *(undefined2 *)pRVar1 = 0x7ea0;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  puVar5[7] = 0xffff;
  *(undefined4 *)(puVar5 + 5) = 0xffffffff;
  *(undefined4 *)(puVar5 + 3) = 0xffffffff;
  *(undefined4 *)(puVar5 + 1) = 0xffffffff;
  *(undefined2 *)pRVar1 = 0x7ea1;
  *puVar5 = 0x7e90;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  puVar5[7] = 0xffff;
  *(undefined4 *)(puVar5 + 5) = 0xffffffff;
  *(undefined4 *)(puVar5 + 3) = 0xffffffff;
  *(undefined4 *)(puVar5 + 1) = 0xffffffff;
  *puVar5 = 0x80f4;
  *(undefined2 *)pRVar1 = 0x7ea6;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7e98;
  puVar5[1] = 0x7e99;
  *(undefined2 *)pRVar1 = 0x7ea5;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 2;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  puVar5[7] = 0xffff;
  *(undefined4 *)(puVar5 + 5) = 0xffffffff;
  *(undefined4 *)(puVar5 + 3) = 0xffffffff;
  *(undefined4 *)(puVar5 + 1) = 0xffffffff;
  *(undefined2 *)pRVar1 = 0x7ea7;
  *puVar5 = 0x7e98;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 1;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  puVar5[7] = 0xffff;
  *(undefined4 *)(puVar5 + 5) = 0xffffffff;
  *(undefined4 *)(puVar5 + 3) = 0xffffffff;
  *(undefined4 *)(puVar5 + 1) = 0xffffffff;
  *puVar5 = 0x7e98;
  *(undefined2 *)pRVar1 = 0x7eab;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0x1c;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  *(undefined4 *)(puVar5 + 6) = 0xffffffff;
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  *(undefined4 *)(puVar5 + 2) = 0xffffffff;
  *puVar5 = 0x7e9a;
  puVar5[1] = 0x7e9b;
  *(undefined2 *)pRVar1 = 0x7ea3;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 0;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  puVar5[7] = 0xffff;
  *(undefined4 *)(puVar5 + 5) = 0xffffffff;
  *(undefined4 *)(puVar5 + 3) = 0xffffffff;
  *(undefined4 *)(puVar5 + 1) = 0xffffffff;
  *(undefined2 *)pRVar1 = 0x7ea2;
  *puVar5 = 0x7e9a;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 2;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  puVar5[7] = 0xffff;
  *(undefined4 *)(puVar5 + 5) = 0xffffffff;
  *(undefined4 *)(puVar5 + 3) = 0xffffffff;
  *(undefined4 *)(puVar5 + 1) = 0xffffffff;
  *puVar5 = 0x7e9a;
  *(undefined2 *)pRVar1 = 0x7ea4;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/fx/projectiles.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/fx/projectiles.aei",iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x5e88;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/valkyrie/3d/textures/low/etc/fx/v_projectiles.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/valkyrie/3d/textures/low/etc/fx/v_projectiles.aei",iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x5e1f;
  puVar2[1] = 0;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 2;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  puVar5[7] = 0xffff;
  *(undefined4 *)(puVar5 + 5) = 0xffffffff;
  *(undefined4 *)(puVar5 + 3) = 0xffffffff;
  *(undefined4 *)(puVar5 + 1) = 0xffffffff;
  *puVar5 = 0x5e88;
  *(undefined2 *)pRVar1 = 0x5e89;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar5 = operator_new(0x28);
  *(undefined4 *)(puVar5 + 8) = 3;
  *(undefined4 *)(puVar5 + 10) = 0;
  *(undefined4 *)(puVar5 + 0xc) = 0;
  *(undefined4 *)(puVar5 + 0xe) = 0xc1200000;
  *(undefined4 *)(puVar5 + 0x10) = 0;
  *(undefined4 *)(puVar5 + 0x12) = 0;
  puVar5[7] = 0xffff;
  *(undefined4 *)(puVar5 + 5) = 0xffffffff;
  *(undefined4 *)(puVar5 + 3) = 0xffffffff;
  *(undefined4 *)(puVar5 + 1) = 0xffffffff;
  *puVar5 = 0x5e1f;
  *(undefined2 *)pRVar1 = 0x5e20;
  *(undefined4 *)(pRVar1 + 4) = 6;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined2 **)(pRVar1 + 0xc) = puVar5;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/skyboxes/skybox_stars_000.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/skyboxes/skybox_stars_000.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2766;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/skyboxes/skybox_stars_001.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/skyboxes/skybox_stars_001.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2767;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/skyboxes/skybox_stars_002.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/skyboxes/skybox_stars_002.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2768;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/planets/planet_000_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/planets/planet_000_big.aei",iVar3 + 1U
                );
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x273a;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/planets/planet_001_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/planets/planet_001_big.aei",iVar3 + 1U
                );
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x273b;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/planets/planet_002_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/planets/planet_002_big.aei",iVar3 + 1U
                );
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x273c;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/planets/planet_003_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/planets/planet_003_big.aei",iVar3 + 1U
                );
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x273d;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/planets/planet_004_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/planets/planet_004_big.aei",iVar3 + 1U
                );
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x273e;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/planets/planet_005_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/planets/planet_005_big.aei",iVar3 + 1U
                );
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x273f;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/planets/planet_006_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/planets/planet_006_big.aei",iVar3 + 1U
                );
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2740;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/planets/planet_007_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/planets/planet_007_big.aei",iVar3 + 1U
                );
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2741;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/planets/planet_008_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/planets/planet_008_big.aei",iVar3 + 1U
                );
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2742;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/planets/planet_009_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/planets/planet_009_big.aei",iVar3 + 1U
                );
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2743;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/planets/planet_010_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/planets/planet_010_big.aei",iVar3 + 1U
                );
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2744;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/planets/planet_011_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/planets/planet_011_big.aei",iVar3 + 1U
                );
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2745;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/planets/planet_012_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/planets/planet_012_big.aei",iVar3 + 1U
                );
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2746;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/planets/planet_013_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/planets/planet_013_big.aei",iVar3 + 1U
                );
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2747;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/planets/planet_014_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/planets/planet_014_big.aei",iVar3 + 1U
                );
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2748;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/planets/planet_015_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/planets/planet_015_big.aei",iVar3 + 1U
                );
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2749;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/planets/planet_016_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/planets/planet_016_big.aei",iVar3 + 1U
                );
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x274a;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/planets/planet_017_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/planets/planet_017_big.aei",iVar3 + 1U
                );
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x274b;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/planets/planet_018_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/planets/planet_018_big.aei",iVar3 + 1U
                );
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x274c;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/planets/planet_019_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/planets/planet_019_big.aei",iVar3 + 1U
                );
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x274d;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/valkyrie/3d/textures/low/etc/planets/v_planet_020_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/valkyrie/3d/textures/low/etc/planets/v_planet_020_big.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2d68;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/valkyrie/3d/textures/low/etc/planets/v_planet_021_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/valkyrie/3d/textures/low/etc/planets/v_planet_021_big.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2d69;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/valkyrie/3d/textures/low/etc/planets/v_planet_022_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/valkyrie/3d/textures/low/etc/planets/v_planet_022_big.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2d6a;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/planets/planet_void_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/planets/planet_void_big.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2719;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/supernova/3d/textures/low/etc/planets/sn_planet_024_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/supernova/3d/textures/low/etc/planets/sn_planet_024_big.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2e14;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/supernova/3d/textures/low/etc/planets/sn_planet_025_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/supernova/3d/textures/low/etc/planets/sn_planet_025_big.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2e15;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/supernova/3d/textures/low/etc/planets/sn_planet_026_big.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/supernova/3d/textures/low/etc/planets/sn_planet_026_big.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2e16;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/skyboxes/skybox_000.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/skyboxes/skybox_000.aei",iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2751;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/skyboxes/skybox_001.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/skyboxes/skybox_001.aei",iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2752;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/skyboxes/skybox_002.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/skyboxes/skybox_002.aei",iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2753;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/skyboxes/skybox_003.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/skyboxes/skybox_003.aei",iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2754;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/skyboxes/skybox_004.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/skyboxes/skybox_004.aei",iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2755;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/skyboxes/skybox_005.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/skyboxes/skybox_005.aei",iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2756;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/skyboxes/skybox_006.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/skyboxes/skybox_006.aei",iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2757;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/skyboxes/skybox_007.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/skyboxes/skybox_007.aei",iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2758;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/skyboxes/skybox_008.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/skyboxes/skybox_008.aei",iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2759;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/skyboxes/skybox_009.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/skyboxes/skybox_009.aei",iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x275a;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/skyboxes/skybox_010.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/skyboxes/skybox_010.aei",iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x275b;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/valkyrie/3d/textures/low/etc/skyboxes/v_skybox_011.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/valkyrie/3d/textures/low/etc/skyboxes/v_skybox_011.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x275c;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/valkyrie/3d/textures/low/etc/skyboxes/v_skybox_012.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/valkyrie/3d/textures/low/etc/skyboxes/v_skybox_012.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x275d;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/valkyrie/3d/textures/low/etc/skyboxes/v_skybox_013.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/valkyrie/3d/textures/low/etc/skyboxes/v_skybox_013.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x275e;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/valkyrie/3d/textures/low/etc/skyboxes/v_skybox_014.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/valkyrie/3d/textures/low/etc/skyboxes/v_skybox_014.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x275f;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/misc/asteroid_01_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/misc/asteroid_01_diffuse.aei",
                 iVar3 + 1U);
  puVar2[1] = 0xbf800000;
  *(undefined2 *)pRVar1 = 33000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/misc/asteroid_01_normal_specular.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/misc/asteroid_01_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x80e9;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/misc/asteroid_void_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/misc/asteroid_void_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x80ea;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/misc/asteroid_void_normal_specular.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/misc/asteroid_void_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x80eb;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/supernova/3d/textures/low/etc/skyboxes/sn_skybox_015.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/supernova/3d/textures/low/etc/skyboxes/sn_skybox_015.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2760;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/supernova/3d/textures/low/etc/skyboxes/sn_skybox_015_flares.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/supernova/3d/textures/low/etc/skyboxes/sn_skybox_015_flares.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2764;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/supernova/3d/textures/low/etc/skyboxes/sn_skybox_015_flares_nasty.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/supernova/3d/textures/low/etc/skyboxes/sn_skybox_015_flares_nasty.aei"
                 ,iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2765;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/supernova/3d/textures/low/etc/skyboxes/sn_skybox_016.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/supernova/3d/textures/low/etc/skyboxes/sn_skybox_016.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2761;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/supernova/3d/textures/low/etc/skyboxes/sn_skybox_017.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/supernova/3d/textures/low/etc/skyboxes/sn_skybox_017.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2762;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/supernova/3d/textures/low/etc/skyboxes/sn_skybox_018.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/supernova/3d/textures/low/etc/skyboxes/sn_skybox_018.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2763;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/bars/bar_terran_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/bars/bar_terran_diffuse.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2798;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/bars/bar_terran_normal_specular.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/bars/bar_terran_normal_specular.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x279c;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/bars/bar_midorian_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/bars/bar_midorian_diffuse.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x279b;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/bars/bar_midorian_normal_specular.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/bars/bar_midorian_normal_specular.aei"
                 ,iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x279f;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/bars/bar_nivelian_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/bars/bar_nivelian_diffuse.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x279a;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/bars/bar_nivelian_normal_specular.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/bars/bar_nivelian_normal_specular.aei"
                 ,iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x279e;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/bars/bar_vossk_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/bars/bar_vossk_diffuse.aei",iVar3 + 1U
                );
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x2799;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/bars/bar_vossk_normal_specular.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/bars/bar_vossk_normal_specular.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x279d;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/hangars/hangar_midorian_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/hangars/hangar_midorian_diffuse.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x816a;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/hangars/hangar_midorian_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/hangars/hangar_midorian_normal_specular.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x816b;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/hangars/hangar_vossk_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/hangars/hangar_vossk_diffuse.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x816c;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/hangars/hangar_vossk_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/hangars/hangar_vossk_normal_specular.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x816d;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/hangars/hangar_nivelian_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/hangars/hangar_nivelian_diffuse.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x816e;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/hangars/hangar_nivelian_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/hangars/hangar_nivelian_normal_specular.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x816f;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/hangars/hangar_terran_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/hangars/hangar_terran_diffuse.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x8170;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/hangars/hangar_terran_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/hangars/hangar_terran_normal_specular.aei",
                 iVar3 + 1U);
  puVar2[1] = 0;
  *(undefined2 *)pRVar1 = 0x8171;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/cargo_midorian_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/cargo_midorian_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x8160;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/cargo_midorian_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/cargo_midorian_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x8161;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/cargo_nivelian_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/cargo_nivelian_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x8162;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/cargo_nivelian_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/cargo_nivelian_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x8163;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/cargo_terran_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/cargo_terran_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x8164;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/cargo_terran_normal_specular.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/cargo_terran_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x8165;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/cargo_vossk_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/cargo_vossk_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x8166;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/cargo_vossk_normal_specular.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/cargo_vossk_normal_specular.aei"
                 ,iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x8167;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/battleship_terran_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/battleship_terran_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x8168;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/battleship_terran_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/battleship_terran_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x8169;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/cargo_midorian_dmg_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/cargo_midorian_dmg_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x823e;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/cargo_midorian_dmg_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/cargo_midorian_dmg_normal_specular.aei"
                 ,iVar3 + 1U);
  puVar2[1] = 0xbf800000;
  *(undefined2 *)pRVar1 = 0x823f;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/cargo_nivelian_dmg_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/cargo_nivelian_dmg_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x8240;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/cargo_nivelian_dmg_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/cargo_nivelian_dmg_normal_specular.aei"
                 ,iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x8241;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/cargo_terran_dmg_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/cargo_terran_dmg_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x8242;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/cargo_terran_dmg_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/cargo_terran_dmg_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x8243;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/cargo_vossk_dmg_diffuse.aei");
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,"data/assets/main/3d/textures/low/etc/ships/cargo_vossk_dmg_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x8244;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/cargo_vossk_dmg_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/cargo_vossk_dmg_normal_specular.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x8245;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    ("data/assets/main/3d/textures/low/etc/ships/battleship_terran_dmg_diffuse.aei")
  ;
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/battleship_terran_dmg_diffuse.aei",
                 iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x8246;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  pRVar1 = operator_new(0x10);
  puVar2 = operator_new(8);
  iVar3 = AbyssEngine::String::GetStringLength
                    (
                    "data/assets/main/3d/textures/low/etc/ships/battleship_terran_dmg_normal_specular.aei"
                    );
  pvVar4 = operator_new__(iVar3 + 1U);
  *puVar2 = pvVar4;
  __aeabi_memcpy(pvVar4,
                 "data/assets/main/3d/textures/low/etc/ships/battleship_terran_dmg_normal_specular.aei"
                 ,iVar3 + 1U);
  *(undefined2 *)pRVar1 = 0x8247;
  puVar2[1] = 0xbf800000;
  *(undefined4 *)(pRVar1 + 4) = 2;
  *(undefined4 *)(pRVar1 + 8) = 0xffffffff;
  *(undefined4 **)(pRVar1 + 0xc) = puVar2;
  AbyssEngine::PaintCanvas::AddResource(this,pRVar1);
  return;
}

// ===== ArraySetLength<Node*>  @0x001407ec  (52 bytes)
/* void ArraySetLength<Node*>(unsigned int, Array<Node*>&) */

void ArraySetLength<Node*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArrayReleaseClasses<Node*>  @0x00140974  (84 bytes)
/* void ArrayReleaseClasses<Node*>(Array<Node*>&) */

void ArrayReleaseClasses<Node*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar5 = 0;
    do {
      piVar4 = *(int **)((int)pvVar1 + uVar5 * 4);
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        pvVar1 = *(void **)(iVar3 + 4);
        if (pvVar1 != (void *)0x0) {
          operator_delete__(pvVar1);
        }
        *(undefined4 *)(iVar3 + 4) = 0;
        operator_delete(piVar4);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar5 * 4) = 0;
      uVar5 = uVar5 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar5 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArrayRemove<Node*>  @0x00140a92  (66 bytes)
/* void ArrayRemove<Node*>(Node*, Array<Node*>&) */

void ArrayRemove<Node*>(Node *param_1,Array *param_2)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  Node *pNVar5;
  
  uVar3 = *(uint *)param_2;
  if (uVar3 == 0) {
    iVar2 = 0;
  }
  else {
    uVar4 = 0;
    iVar2 = 0;
    do {
      pNVar5 = *(Node **)(*(int *)(param_2 + 4) + uVar4 * 4);
      uVar4 = uVar4 + 1;
      if (pNVar5 != param_1) {
        *(Node **)(*(int *)(param_2 + 4) + iVar2 * 4) = pNVar5;
        iVar2 = iVar2 + 1;
      }
    } while (uVar4 < uVar3);
  }
  *(int *)param_2 = iVar2;
  if (iVar2 == 0) {
    iVar2 = 1;
  }
  *(int *)(param_2 + 8) = iVar2;
  pvVar1 = realloc(*(void **)(param_2 + 4),iVar2 << 2);
  *(void **)(param_2 + 4) = pvVar1;
  return;
}

// ===== ArrayReleaseClasses<Waypoint*>  @0x00140d50  (62 bytes)
/* void ArrayReleaseClasses<Waypoint*>(Array<Waypoint*>&) */

void ArrayReleaseClasses<Waypoint*>(Array *param_1)

{
  void *pvVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar3 = *(uint *)(param_1 + 8);
  if (uVar3 != 0) {
    uVar4 = 0;
    do {
      piVar2 = *(int **)((int)pvVar1 + uVar4 * 4);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 4))(piVar2);
        pvVar1 = *(void **)(param_1 + 4);
        uVar3 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar4 * 4) = 0;
      uVar4 = uVar4 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar4 < uVar3);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArraySetLength<ImagePart*>  @0x0014183c  (52 bytes)
/* void ArraySetLength<ImagePart*>(unsigned int, Array<ImagePart*>&) */

void ArraySetLength<ImagePart*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArrayReleaseClasses<ListItem*>  @0x00142c10  (66 bytes)
/* void ArrayReleaseClasses<ListItem*>(Array<ListItem*>&) */

void ArrayReleaseClasses<ListItem*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  ListItem *this;
  uint uVar3;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      this = *(ListItem **)((int)pvVar1 + uVar3 * 4);
      if (this != (ListItem *)0x0) {
        pvVar1 = (void *)ListItem::~ListItem(this);
        operator_delete(pvVar1);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar3 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArrayReleaseClasses<Array<ListItem*>*>  @0x00142c52  (70 bytes)
/* void ArrayReleaseClasses<Array<ListItem*>*>(Array<Array<ListItem*>*>&) */

void ArrayReleaseClasses<Array<ListItem*>*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  void *pvVar3;
  uint uVar4;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar4 = 0;
    do {
      pvVar3 = *(void **)((int)pvVar1 + uVar4 * 4);
      if (pvVar3 != (void *)0x0) {
        if (*(void **)((int)pvVar3 + 4) != (void *)0x0) {
          operator_delete__(*(void **)((int)pvVar3 + 4));
        }
        operator_delete(pvVar3);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar4 * 4) = 0;
      uVar4 = uVar4 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar4 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArraySetLength<ListItem*>  @0x00142f68  (52 bytes)
/* void ArraySetLength<ListItem*>(unsigned int, Array<ListItem*>&) */

void ArraySetLength<ListItem*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArraySetLength<Array<ListItem*>*>  @0x00143458  (52 bytes)
/* void ArraySetLength<Array<ListItem*>*>(unsigned int, Array<Array<ListItem*>*>&) */

void ArraySetLength<Array<ListItem*>*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArraySetLength<signed_char>  @0x00145be0  (48 bytes)
/* void ArraySetLength<signed char>(unsigned int, Array<signed char>&) */

void ArraySetLength<signed_char>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr(pvVar1,uVar2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArraySetLength<SolarSystem*>  @0x00145f14  (52 bytes)
/* void ArraySetLength<SolarSystem*>(unsigned int, Array<SolarSystem*>&) */

void ArraySetLength<SolarSystem*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArraySetLength<NewsItem*>  @0x0014677c  (52 bytes)
/* void ArraySetLength<NewsItem*>(unsigned int, Array<NewsItem*>&) */

void ArraySetLength<NewsItem*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArrayReleaseClasses<TouchSlider*>  @0x0014b4a6  (66 bytes)
/* void ArrayReleaseClasses<TouchSlider*>(Array<TouchSlider*>&) */

void ArrayReleaseClasses<TouchSlider*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  TouchSlider *this;
  uint uVar3;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      this = *(TouchSlider **)((int)pvVar1 + uVar3 * 4);
      if (this != (TouchSlider *)0x0) {
        pvVar1 = (void *)TouchSlider::~TouchSlider(this);
        operator_delete(pvVar1);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar3 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArraySetLength<unsigned_int>  @0x0015d010  (52 bytes)
/* void ArraySetLength<unsigned int>(unsigned int, Array<unsigned int>&) */

void ArraySetLength<unsigned_int>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArraySetLength<Explosion*>  @0x00181b68  (52 bytes)
/* void ArraySetLength<Explosion*>(unsigned int, Array<Explosion*>&) */

void ArraySetLength<Explosion*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArrayReleaseClasses<Explosion*>  @0x00181c00  (66 bytes)
/* void ArrayReleaseClasses<Explosion*>(Array<Explosion*>&) */

void ArrayReleaseClasses<Explosion*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  Explosion *this;
  uint uVar3;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      this = *(Explosion **)((int)pvVar1 + uVar3 * 4);
      if (this != (Explosion *)0x0) {
        pvVar1 = (void *)Explosion::~Explosion(this);
        operator_delete(pvVar1);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar3 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArrayReleaseClasses<NewsItem*>  @0x0018a868  (66 bytes)
/* void ArrayReleaseClasses<NewsItem*>(Array<NewsItem*>&) */

void ArrayReleaseClasses<NewsItem*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  NewsItem *this;
  uint uVar3;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      this = *(NewsItem **)((int)pvVar1 + uVar3 * 4);
      if (this != (NewsItem *)0x0) {
        pvVar1 = (void *)NewsItem::~NewsItem(this);
        operator_delete(pvVar1);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar3 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArraySetLength<void*>  @0x0018de02  (52 bytes)
/* void ArraySetLength<void*>(unsigned int, Array<void*>&) */

void ArraySetLength<void*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== drawControlsInterface  @0x00193a34  (2 bytes)
/* drawControlsInterface(long long, long long, PlayerEgo*, bool, unsigned int, unsigned int) */

longlong drawControlsInterface
                   (longlong param_1,longlong param_2,PlayerEgo *param_3,bool param_4,uint param_5,
                   uint param_6)

{
  return param_1;
}

// ===== ArrayRemove<Agent*>  @0x00198770  (66 bytes)
/* void ArrayRemove<Agent*>(Agent*, Array<Agent*>&) */

void ArrayRemove<Agent*>(Agent *param_1,Array *param_2)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  Agent *pAVar5;
  
  uVar3 = *(uint *)param_2;
  if (uVar3 == 0) {
    iVar2 = 0;
  }
  else {
    uVar4 = 0;
    iVar2 = 0;
    do {
      pAVar5 = *(Agent **)(*(int *)(param_2 + 4) + uVar4 * 4);
      uVar4 = uVar4 + 1;
      if (pAVar5 != param_1) {
        *(Agent **)(*(int *)(param_2 + 4) + iVar2 * 4) = pAVar5;
        iVar2 = iVar2 + 1;
      }
    } while (uVar4 < uVar3);
  }
  *(int *)param_2 = iVar2;
  if (iVar2 == 0) {
    iVar2 = 1;
  }
  *(int *)(param_2 + 8) = iVar2;
  pvVar1 = realloc(*(void **)(param_2 + 4),iVar2 << 2);
  *(void **)(param_2 + 4) = pvVar1;
  return;
}

// ===== ArrayReleaseClasses<Array<ImagePart*>*>  @0x001988f2  (70 bytes)
/* void ArrayReleaseClasses<Array<ImagePart*>*>(Array<Array<ImagePart*>*>&) */

void ArrayReleaseClasses<Array<ImagePart*>*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  void *pvVar3;
  uint uVar4;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar4 = 0;
    do {
      pvVar3 = *(void **)((int)pvVar1 + uVar4 * 4);
      if (pvVar3 != (void *)0x0) {
        if (*(void **)((int)pvVar3 + 4) != (void *)0x0) {
          operator_delete__(*(void **)((int)pvVar3 + 4));
        }
        operator_delete(pvVar3);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar4 * 4) = 0;
      uVar4 = uVar4 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar4 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArraySetLength<Array<ImagePart*>*>  @0x00198938  (52 bytes)
/* void ArraySetLength<Array<ImagePart*>*>(unsigned int, Array<Array<ImagePart*>*>&) */

void ArraySetLength<Array<ImagePart*>*>(uint param_1,Array *param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 + 8) == param_1) {
    pvVar1 = *(void **)(param_2 + 4);
    uVar2 = param_1;
  }
  else {
    uVar2 = param_1;
    if (param_1 == 0) {
      uVar2 = 1;
    }
    *(uint *)(param_2 + 8) = uVar2;
    pvVar1 = realloc(*(void **)(param_2 + 4),uVar2 << 2);
    *(void **)(param_2 + 4) = pvVar1;
    uVar2 = *(uint *)(param_2 + 8);
  }
  __aeabi_memclr4(pvVar1,uVar2 << 2);
  *(uint *)param_2 = param_1;
  return;
}

// ===== ArrayReleaseClasses<ParticleSystemMesh*>  @0x001b4a38  (66 bytes)
/* void ArrayReleaseClasses<ParticleSystemMesh*>(Array<ParticleSystemMesh*>&) */

void ArrayReleaseClasses<ParticleSystemMesh*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  ParticleSystemMesh *this;
  uint uVar3;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      this = *(ParticleSystemMesh **)((int)pvVar1 + uVar3 * 4);
      if (this != (ParticleSystemMesh *)0x0) {
        pvVar1 = (void *)ParticleSystemMesh::~ParticleSystemMesh(this);
        operator_delete(pvVar1);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar3 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== ArrayReleaseClasses<ParticleSystemSprite*>  @0x001b4a7a  (66 bytes)
/* void ArrayReleaseClasses<ParticleSystemSprite*>(Array<ParticleSystemSprite*>&) */

void ArrayReleaseClasses<ParticleSystemSprite*>(Array *param_1)

{
  void *pvVar1;
  uint uVar2;
  ParticleSystemSprite *this;
  uint uVar3;
  
  pvVar1 = *(void **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      this = *(ParticleSystemSprite **)((int)pvVar1 + uVar3 * 4);
      if (this != (ParticleSystemSprite *)0x0) {
        pvVar1 = (void *)ParticleSystemSprite::~ParticleSystemSprite(this);
        operator_delete(pvVar1);
        pvVar1 = *(void **)(param_1 + 4);
        uVar2 = *(uint *)(param_1 + 8);
      }
      *(undefined4 *)((int)pvVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      pvVar1 = *(void **)(param_1 + 4);
    } while (uVar3 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== inflateReset  @0x001b7ade  (64 bytes)
undefined4 inflateReset(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if ((param_1 != 0) && (puVar2 = *(undefined4 **)(param_1 + 0x1c), puVar2 != (undefined4 *)0x0)) {
    puVar2[7] = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x30) = 1;
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[3] = 0;
    puVar2[5] = 0x8000;
    puVar1 = puVar2 + 0x14c;
    puVar2[8] = 0;
    puVar2[10] = 0;
    puVar2[0xb] = 0;
    puVar2[0xc] = 0;
    puVar2[0xe] = 0;
    puVar2[0xf] = 0;
    puVar2[0x1b] = puVar1;
    puVar2[0x13] = puVar1;
    puVar2[0x14] = puVar1;
    return 0;
  }
  return 0xfffffffe;
}

// ===== inflatePrime  @0x001b7b1e  (58 bytes)
undefined4 inflatePrime(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  if (((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x1c), iVar1 != 0)) && ((int)param_2 < 0x11)) {
    uVar2 = *(uint *)(iVar1 + 0x3c) + param_2;
    if (uVar2 < 0x21) {
      *(uint *)(iVar1 + 0x38) =
           (((1 << (param_2 & 0xff)) - 1U & param_3) << (*(uint *)(iVar1 + 0x3c) & 0xff)) +
           *(int *)(iVar1 + 0x38);
      *(uint *)(iVar1 + 0x3c) = uVar2;
      return 0;
    }
  }
  return 0xfffffffe;
}

// ===== inflateInit2_  @0x001b7b58  (154 bytes)
undefined4 inflateInit2_(int param_1,uint param_2,byte *param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  
  uVar1 = 0xfffffffa;
  if (param_3 == (byte *)0x0) {
    return 0xfffffffa;
  }
  uVar3 = param_2;
  if (param_4 == 0x38) {
    uVar3 = (uint)*param_3;
  }
  if (param_4 == 0x38 && uVar3 == 0x31) {
    if (param_1 != 0) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      pcVar4 = *(code **)(param_1 + 0x20);
      if (pcVar4 == (code *)0x0) {
        pcVar4 = zcalloc;
        *(code **)(param_1 + 0x20) = zcalloc;
        *(undefined4 *)(param_1 + 0x28) = 0;
      }
      if (*(int *)(param_1 + 0x24) == 0) {
        *(code **)(param_1 + 0x24) = zcfree;
      }
      iVar2 = (*pcVar4)(*(undefined4 *)(param_1 + 0x28),1,0x2530);
      if (iVar2 == 0) {
        return 0xfffffffc;
      }
      *(int *)(param_1 + 0x1c) = iVar2;
      if ((int)param_2 < 0) {
        param_2 = -param_2;
        *(undefined4 *)(iVar2 + 8) = 0;
      }
      else {
        *(int *)(iVar2 + 8) = ((int)param_2 >> 4) + 1;
        if ((int)param_2 < 0x30) {
          param_2 = param_2 & 0xf;
        }
      }
      if ((param_2 & 0xfffffff8) == 8) {
        *(uint *)(iVar2 + 0x24) = param_2;
        *(undefined4 *)(iVar2 + 0x34) = 0;
        uVar1 = inflateReset(param_1);
        return uVar1;
      }
      (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28));
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}

// ===== inflateInit_  @0x001b7bf8  (12 bytes)
void inflateInit_(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  inflateInit2_(param_1,0xf,param_2,param_3);
  return;
}

// ===== inflate  @0x001b7c04  (4388 bytes)
void inflate(undefined4 *param_1,int param_2)

{
  ushort *puVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  uint *puVar5;
  uint *puVar6;
  char *pcVar7;
  int iVar8;
  undefined2 uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined1 *puVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  uint *puVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  uint *puVar25;
  uint uVar26;
  byte *pbVar27;
  byte *pbVar28;
  undefined1 *in_r12;
  undefined1 *puVar29;
  uint uVar30;
  bool bVar31;
  uint *puVar32;
  int local_40;
  uint local_3c;
  undefined2 local_2c;
  undefined1 local_2a;
  undefined1 local_29;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (param_1 != (undefined4 *)0x0) {
    puVar25 = (uint *)param_1[7];
    if (puVar25 != (uint *)0x0) {
      in_r12 = (undefined1 *)param_1[3];
    }
    if ((puVar25 != (uint *)0x0 && in_r12 != (undefined1 *)0x0) &&
       ((pbVar27 = (byte *)*param_1, pbVar27 != (byte *)0x0 || (param_1[1] == 0)))) {
      puVar5 = puVar25 + 0xbc;
      uVar10 = *puVar25;
      puVar20 = puVar25 + 0x1b;
      if (uVar10 == 0xb) {
        uVar10 = 0xc;
        *puVar25 = 0xc;
      }
      uVar26 = puVar25[0xe];
      uVar17 = puVar25[0xf];
      uVar23 = param_1[1];
      uVar30 = param_1[4];
      puVar6 = puVar25 + 0x14c;
      puVar32 = puVar25 + 0x16;
      local_40 = 0;
      uVar24 = uVar23;
      local_3c = uVar30;
      do {
        iVar8 = -4;
        iVar19 = 1;
        switch(uVar10) {
        case 0:
          uVar10 = puVar25[2];
          if (uVar10 != 0) {
            for (; uVar17 < 0x10; uVar17 = uVar17 + 8) {
              if (uVar24 == 0) goto LAB_001b8c40;
              uVar24 = uVar24 - 1;
              uVar26 = uVar26 + ((uint)*pbVar27 << (uVar17 & 0xff));
              pbVar27 = pbVar27 + 1;
            }
            if ((uVar26 != 0x8b1f) || ((uVar10 & 2) == 0)) {
              puVar25[4] = 0;
              if (puVar25[8] != 0) {
                *(undefined4 *)(puVar25[8] + 0x30) = 0xffffffff;
              }
              if (((uVar10 & 1) == 0) ||
                 (uVar10 = (uVar26 >> 8) + (uVar26 & 0xff) * 0x100,
                 uVar10 != (uVar10 / 0x1f) * 0x20 - uVar10 / 0x1f)) {
                pcVar7 = "incorrect header check";
              }
              else if ((uVar26 & 0xf) == 8) {
                uVar10 = ((uVar26 & 0xff) >> 4) + 8;
                if (uVar10 <= puVar25[9]) {
                  puVar25[5] = 1 << uVar10;
                  uVar17 = 0;
                  uVar10 = adler32(0,0,0);
                  puVar25[6] = uVar10;
                  param_1[0xc] = uVar10;
                  uVar10 = uVar26 >> 0xc;
                  uVar26 = 0;
                  uVar10 = uVar10 & 2 ^ 0xb;
                  goto LAB_001b8720;
                }
                uVar26 = uVar26 >> 4;
                uVar17 = uVar17 - 4;
                pcVar7 = "invalid window size";
              }
              else {
                pcVar7 = "unknown compression method";
              }
              goto LAB_001b871c;
            }
            uVar26 = 0;
            uVar10 = crc32(0,0,0);
            puVar25[6] = uVar10;
            local_2c = 0x8b1f;
            uVar10 = crc32(uVar10,&local_2c,2);
            puVar25[6] = uVar10;
            *puVar25 = 1;
            uVar17 = 0;
            break;
          }
          uVar10 = 0xc;
          goto LAB_001b8720;
        case 1:
          for (; uVar17 < 0x10; uVar17 = uVar17 + 8) {
            if (uVar24 == 0) goto LAB_001b8c40;
            uVar24 = uVar24 - 1;
            uVar26 = uVar26 + ((uint)*pbVar27 << (uVar17 & 0xff));
            pbVar27 = pbVar27 + 1;
          }
          puVar25[4] = uVar26;
          if ((uVar26 & 0xff) == 8) {
            if ((uVar26 & 0xe000) == 0) {
              if ((uint *)puVar25[8] != (uint *)0x0) {
                *(uint *)puVar25[8] = (uVar26 & 0x1ff) >> 8;
              }
              if ((uVar26 & 0x200) != 0) {
                local_2c = (undefined2)uVar26;
                uVar10 = crc32(puVar25[6],&local_2c,2);
                puVar25[6] = uVar10;
              }
              uVar17 = 0;
              *puVar25 = 2;
              uVar26 = 0;
              do {
                if (uVar24 == 0) goto LAB_001b8c40;
                uVar24 = uVar24 - 1;
                uVar10 = uVar17 & 0xff;
                uVar17 = uVar17 + 8;
                uVar26 = uVar26 + ((uint)*pbVar27 << uVar10);
                pbVar27 = pbVar27 + 1;
joined_r0x001b7da4:
              } while (uVar17 < 0x20);
              if (puVar25[8] != 0) {
                *(uint *)(puVar25[8] + 4) = uVar26;
              }
              if ((*(byte *)((int)puVar25 + 0x11) & 2) != 0) {
                local_2c = (undefined2)uVar26;
                local_2a = (undefined1)(uVar26 >> 0x10);
                local_29 = (undefined1)(uVar26 >> 0x18);
                uVar10 = crc32(puVar25[6],&local_2c,4);
                puVar25[6] = uVar10;
              }
              uVar17 = 0;
              *puVar25 = 3;
              uVar26 = 0;
              do {
                if (uVar24 == 0) goto LAB_001b8c40;
                uVar24 = uVar24 - 1;
                uVar10 = uVar17 & 0xff;
                uVar17 = uVar17 + 8;
                uVar26 = uVar26 + ((uint)*pbVar27 << uVar10);
                pbVar27 = pbVar27 + 1;
joined_r0x001b7dac:
              } while (uVar17 < 0x10);
              uVar10 = puVar25[8];
              if (uVar10 != 0) {
                *(uint *)(uVar10 + 8) = uVar26 & 0xff;
                *(uint *)(uVar10 + 0xc) = uVar26 >> 8;
              }
              if ((*(byte *)((int)puVar25 + 0x11) & 2) != 0) {
                local_2c = (undefined2)uVar26;
                uVar10 = crc32(puVar25[6],&local_2c,2);
                puVar25[6] = uVar10;
              }
              uVar26 = 0;
              uVar17 = 0;
              *puVar25 = 4;
              goto switchD_001b7ca8_caseD_4;
            }
            pcVar7 = "unknown header flags set";
          }
          else {
            pcVar7 = "unknown compression method";
          }
          goto LAB_001b871c;
        case 2:
          goto joined_r0x001b7da4;
        case 3:
          goto joined_r0x001b7dac;
        case 4:
switchD_001b7ca8_caseD_4:
          uVar10 = puVar25[4];
          if ((uVar10 & 0x400) == 0) {
            if (puVar25[8] != 0) {
              *(undefined4 *)(puVar25[8] + 0x10) = 0;
            }
          }
          else {
            for (; uVar17 < 0x10; uVar17 = uVar17 + 8) {
              if (uVar24 == 0) goto LAB_001b8c40;
              uVar24 = uVar24 - 1;
              uVar26 = uVar26 + ((uint)*pbVar27 << (uVar17 & 0xff));
              pbVar27 = pbVar27 + 1;
            }
            puVar25[0x10] = uVar26;
            if (puVar25[8] != 0) {
              *(uint *)(puVar25[8] + 0x14) = uVar26;
            }
            if ((uVar10 & 0x200) != 0) {
              local_2c = (undefined2)uVar26;
              uVar10 = crc32(puVar25[6],&local_2c,2);
              puVar25[6] = uVar10;
            }
            uVar26 = 0;
            uVar17 = 0;
          }
          *puVar25 = 5;
        case 5:
          uVar10 = puVar25[4];
          if ((uVar10 & 0x400) != 0) {
            uVar12 = puVar25[0x10];
            uVar14 = uVar12;
            if (uVar24 < uVar12) {
              uVar14 = uVar24;
            }
            if (uVar14 != 0) {
              uVar11 = puVar25[8];
              if ((uVar11 != 0) && (*(int *)(uVar11 + 0x10) != 0)) {
                iVar8 = *(int *)(uVar11 + 0x14) - uVar12;
                uVar10 = uVar14;
                if (*(uint *)(uVar11 + 0x18) < iVar8 + uVar14) {
                  uVar10 = *(uint *)(uVar11 + 0x18) - iVar8;
                }
                __aeabi_memcpy(iVar8 + *(int *)(uVar11 + 0x10),pbVar27,uVar10);
                uVar10 = puVar25[4];
              }
              if ((uVar10 & 0x200) != 0) {
                uVar10 = crc32(puVar25[6],pbVar27,uVar14);
                puVar25[6] = uVar10;
              }
              pbVar27 = pbVar27 + uVar14;
              uVar24 = uVar24 - uVar14;
              uVar12 = puVar25[0x10] - uVar14;
              puVar25[0x10] = uVar12;
            }
            iVar19 = local_40;
            if (uVar12 != 0) goto switchD_001b7ca8_caseD_1a;
          }
          puVar25[0x10] = 0;
          *puVar25 = 6;
switchD_001b7ca8_caseD_6:
          if ((*(byte *)((int)puVar25 + 0x11) & 8) != 0) {
            if (uVar24 != 0) {
              uVar10 = 0;
              do {
                bVar2 = pbVar27[uVar10];
                uVar10 = uVar10 + 1;
                uVar14 = puVar25[8];
                if ((uVar14 != 0) && (iVar8 = *(int *)(uVar14 + 0x1c), iVar8 != 0)) {
                  uVar12 = puVar25[0x10];
                  bVar31 = uVar12 < *(uint *)(uVar14 + 0x20);
                  if (bVar31) {
                    puVar25[0x10] = uVar12 + 1;
                  }
                  if (bVar31) {
                    *(byte *)(iVar8 + uVar12) = bVar2;
                  }
                }
              } while ((bVar2 != 0) && (uVar10 < uVar24));
              if ((*(byte *)((int)puVar25 + 0x11) & 2) != 0) {
                uVar14 = crc32(puVar25[6],pbVar27,uVar10);
                puVar25[6] = uVar14;
              }
              pbVar27 = pbVar27 + uVar10;
              uVar24 = uVar24 - uVar10;
              iVar19 = local_40;
              if (bVar2 != 0) goto switchD_001b7ca8_caseD_1a;
              goto LAB_001b859a;
            }
LAB_001b8c40:
            uVar24 = 0;
            iVar19 = local_40;
            goto switchD_001b7ca8_caseD_1a;
          }
          if (puVar25[8] != 0) {
            *(undefined4 *)(puVar25[8] + 0x1c) = 0;
          }
LAB_001b859a:
          puVar25[0x10] = 0;
          *puVar25 = 7;
switchD_001b7ca8_caseD_7:
          if ((*(byte *)((int)puVar25 + 0x11) & 0x10) == 0) {
            if (puVar25[8] != 0) {
              *(undefined4 *)(puVar25[8] + 0x24) = 0;
            }
          }
          else {
            if (uVar24 == 0) goto LAB_001b8c40;
            uVar10 = 0;
            do {
              bVar2 = pbVar27[uVar10];
              uVar10 = uVar10 + 1;
              uVar14 = puVar25[8];
              if ((uVar14 != 0) && (iVar8 = *(int *)(uVar14 + 0x24), iVar8 != 0)) {
                uVar12 = puVar25[0x10];
                bVar31 = uVar12 < *(uint *)(uVar14 + 0x28);
                if (bVar31) {
                  puVar25[0x10] = uVar12 + 1;
                }
                if (bVar31) {
                  *(byte *)(iVar8 + uVar12) = bVar2;
                }
              }
            } while ((bVar2 != 0) && (uVar10 < uVar24));
            if ((*(byte *)((int)puVar25 + 0x11) & 2) != 0) {
              uVar14 = crc32(puVar25[6],pbVar27,uVar10);
              puVar25[6] = uVar14;
            }
            pbVar27 = pbVar27 + uVar10;
            uVar24 = uVar24 - uVar10;
            iVar19 = local_40;
            if (bVar2 != 0) goto switchD_001b7ca8_caseD_1a;
          }
          *puVar25 = 8;
switchD_001b7ca8_caseD_8:
          if ((puVar25[4] & 0x200) != 0) {
            for (; uVar17 < 0x10; uVar17 = uVar17 + 8) {
              if (uVar24 == 0) goto LAB_001b8c40;
              uVar24 = uVar24 - 1;
              uVar26 = uVar26 + ((uint)*pbVar27 << (uVar17 & 0xff));
              pbVar27 = pbVar27 + 1;
            }
            if (uVar26 != (ushort)puVar25[6]) {
              pcVar7 = "header crc mismatch";
              goto LAB_001b871c;
            }
            uVar26 = 0;
            uVar17 = 0;
          }
          uVar10 = puVar25[8];
          if (uVar10 != 0) {
            *(uint *)(uVar10 + 0x2c) = (puVar25[4] & 0x3ff) >> 9;
            *(undefined4 *)(uVar10 + 0x30) = 1;
          }
          uVar10 = crc32(0,0,0);
          puVar25[6] = uVar10;
          param_1[0xc] = uVar10;
          uVar10 = 0xb;
LAB_001b8692:
          *puVar25 = uVar10;
          break;
        case 6:
          goto switchD_001b7ca8_caseD_6;
        case 7:
          goto switchD_001b7ca8_caseD_7;
        case 8:
          goto switchD_001b7ca8_caseD_8;
        case 9:
          for (; uVar17 < 0x20; uVar17 = uVar17 + 8) {
            if (uVar24 == 0) goto LAB_001b8c40;
            uVar24 = uVar24 - 1;
            uVar26 = uVar26 + ((uint)*pbVar27 << (uVar17 & 0xff));
            pbVar27 = pbVar27 + 1;
          }
          uVar10 = uVar26 << 0x18 | (uVar26 >> 8 & 0xff) << 0x10 | (uVar26 >> 0x10 & 0xff) << 8 |
                   uVar26 >> 0x18;
          puVar25[6] = uVar10;
          param_1[0xc] = uVar10;
          uVar26 = 0;
          uVar17 = 0;
          *puVar25 = 10;
        case 10:
          if (puVar25[3] != 0) {
            uVar10 = adler32(0,0,0);
            puVar25[6] = uVar10;
            param_1[0xc] = uVar10;
            *puVar25 = 0xb;
switchD_001b7ca8_caseD_b:
            iVar19 = local_40;
            if (param_2 == 5) goto switchD_001b7ca8_caseD_1a;
switchD_001b7ca8_caseD_c:
            if (puVar25[1] != 0) {
              *puVar25 = 0x18;
              uVar10 = uVar17 & 7;
              uVar17 = uVar17 - uVar10;
              uVar26 = uVar26 >> uVar10;
              break;
            }
            if (2 < uVar17) {
LAB_001b7e52:
              puVar25[1] = uVar26 & 1;
              uVar10 = (uVar26 & 7) >> 1;
              if (uVar10 == 1) {
                puVar25[0x13] = (uint)&DAT_0025d576;
                puVar25[0x14] = (uint)&DAT_0025dd76;
                uVar10 = 0x12;
                puVar25[0x15] = 9;
                puVar25[0x16] = 5;
              }
              else if (uVar10 == 2) {
                uVar10 = 0xf;
              }
              else if (uVar10 == 3) {
                param_1[6] = "invalid block type";
                uVar10 = 0x1b;
              }
              else {
                uVar10 = 0xd;
              }
              *puVar25 = uVar10;
              uVar17 = uVar17 - 3;
              uVar26 = uVar26 >> 3;
              break;
            }
            if (uVar24 != 0) {
              uVar24 = uVar24 - 1;
              uVar26 = uVar26 + ((uint)*pbVar27 << (uVar17 & 0xff));
              uVar17 = uVar17 + 8;
              pbVar27 = pbVar27 + 1;
              goto LAB_001b7e52;
            }
            goto LAB_001b8c40;
          }
          param_1[3] = in_r12;
          param_1[4] = uVar30;
          *param_1 = pbVar27;
          param_1[1] = uVar24;
          puVar25[0xe] = uVar26;
          puVar25[0xf] = uVar17;
          iVar8 = 2;
          goto switchD_001b7ca8_caseD_1c;
        case 0xb:
          goto switchD_001b7ca8_caseD_b;
        case 0xc:
          goto switchD_001b7ca8_caseD_c;
        case 0xd:
          uVar26 = uVar26 >> (uVar17 & 7);
          for (uVar17 = uVar17 - (uVar17 & 7); uVar17 < 0x20; uVar17 = uVar17 + 8) {
            if (uVar24 == 0) goto LAB_001b8c40;
            uVar24 = uVar24 - 1;
            uVar26 = uVar26 + ((uint)*pbVar27 << (uVar17 & 0xff));
            pbVar27 = pbVar27 + 1;
          }
          uVar10 = uVar26 & 0xffff;
          if (uVar10 == (uVar26 >> 0x10 ^ 0xffff)) {
            uVar26 = 0;
            uVar17 = 0;
            puVar25[0x10] = uVar10;
            *puVar25 = 0xe;
            goto LAB_001b7ecc;
          }
          pcVar7 = "invalid stored block lengths";
LAB_001b871c:
          param_1[6] = pcVar7;
          uVar10 = 0x1b;
LAB_001b8720:
          *puVar25 = uVar10;
          break;
        case 0xe:
          uVar10 = puVar25[0x10];
LAB_001b7ecc:
          if (uVar10 == 0) {
            uVar10 = 0xb;
            goto LAB_001b8720;
          }
          if (uVar24 < uVar10) {
            uVar10 = uVar24;
          }
          if (uVar30 < uVar10) {
            uVar10 = uVar30;
          }
          iVar19 = local_40;
          if (uVar10 == 0) goto switchD_001b7ca8_caseD_1a;
          __aeabi_memcpy(in_r12,pbVar27,uVar10);
          in_r12 = in_r12 + uVar10;
          uVar30 = uVar30 - uVar10;
          puVar25[0x10] = puVar25[0x10] - uVar10;
          pbVar27 = pbVar27 + uVar10;
          uVar24 = uVar24 - uVar10;
          break;
        case 0xf:
          for (; uVar17 < 0xe; uVar17 = uVar17 + 8) {
            if (uVar24 == 0) goto LAB_001b8c40;
            uVar24 = uVar24 - 1;
            uVar26 = uVar26 + ((uint)*pbVar27 << (uVar17 & 0xff));
            pbVar27 = pbVar27 + 1;
          }
          uVar17 = uVar17 - 0xe;
          uVar11 = (uVar26 & 0x1f) + 0x101;
          puVar25[0x18] = uVar11;
          bVar31 = 0x11d < uVar11;
          uVar12 = ((uVar26 & 0x3ff) >> 5) + 1;
          puVar25[0x19] = uVar12;
          uVar10 = uVar26 & 0x3fff;
          uVar26 = uVar26 >> 0xe;
          uVar14 = (uVar10 >> 10) + 4;
          puVar25[0x17] = uVar14;
          if (uVar11 < 0x11f) {
            bVar31 = 0x1e < uVar12;
          }
          if (bVar31) {
            pcVar7 = "too many length or distance symbols";
            goto LAB_001b871c;
          }
          uVar10 = 0;
          puVar25[0x1a] = 0;
          *puVar25 = 0x10;
          do {
            pbVar28 = pbVar27;
            if (uVar17 < 3) {
              if (uVar24 == 0) goto LAB_001b8d2c;
              pbVar28 = pbVar27 + 1;
              uVar24 = uVar24 - 1;
              uVar26 = uVar26 + ((uint)*pbVar27 << (uVar17 & 0xff));
              uVar17 = uVar17 + 8;
            }
            uVar4 = (ushort)uVar26;
            uVar17 = uVar17 - 3;
            uVar26 = uVar26 >> 3;
            uVar3 = (&DAT_0025d550)[uVar10];
            uVar10 = uVar10 + 1;
            puVar25[0x1a] = uVar10;
            *(ushort *)((int)puVar25 + (uint)uVar3 * 2 + 0x70) = uVar4 & 7;
            pbVar27 = pbVar28;
LAB_001b87e4:
          } while (uVar10 < uVar14);
          if (uVar10 < 0x13) {
            do {
              puVar1 = &DAT_0025d550 + uVar10;
              uVar10 = uVar10 + 1;
              *(undefined2 *)((int)puVar25 + (uint)*puVar1 * 2 + 0x70) = 0;
            } while (uVar10 != 0x13);
            puVar25[0x1a] = 0x13;
          }
          puVar25[0x1b] = (uint)puVar6;
          puVar25[0x13] = (uint)puVar6;
          puVar25[0x15] = 7;
          local_40 = inflate_table(0,puVar25 + 0x1c,0x13,puVar20,puVar25 + 0x15,puVar5,puVar32);
          if (local_40 == 0) {
            puVar25[0x1a] = 0;
            *puVar25 = 0x11;
            uVar10 = 0;
            local_40 = 0;
            goto LAB_001b885c;
          }
          param_1[6] = "invalid code lengths set";
          uVar10 = 0x1b;
          goto LAB_001b8692;
        case 0x10:
          uVar14 = puVar25[0x17];
          uVar10 = puVar25[0x1a];
          goto LAB_001b87e4;
        case 0x11:
          uVar10 = puVar25[0x1a];
LAB_001b885c:
          uVar14 = puVar25[0x18];
          uVar12 = puVar25[0x19];
          if (uVar10 < uVar12 + uVar14) {
            do {
              uVar16 = puVar25[0x13];
              uVar11 = (1 << (puVar25[0x15] & 0xff)) - 1;
              uVar21 = uVar11 & uVar26;
              bVar2 = *(byte *)(uVar16 + uVar21 * 4 + 1);
              for (; uVar15 = (uint)bVar2, uVar17 < uVar15; uVar17 = uVar17 + 8) {
                if (uVar24 == 0) goto LAB_001b8d1e;
                uVar24 = uVar24 - 1;
                uVar26 = uVar26 + ((uint)*pbVar27 << (uVar17 & 0xff));
                uVar21 = uVar11 & uVar26;
                bVar2 = *(byte *)(uVar16 + uVar21 * 4 + 1);
                pbVar27 = pbVar27 + 1;
              }
              uVar3 = *(ushort *)(uVar16 + uVar21 * 4 + 2);
              if (uVar3 < 0x10) {
                for (; uVar17 < uVar15; uVar17 = uVar17 + 8) {
                  if (uVar24 == 0) goto LAB_001b8d2c;
                  uVar24 = uVar24 - 1;
                  uVar26 = uVar26 + ((uint)*pbVar27 << (uVar17 & 0xff));
                  pbVar27 = pbVar27 + 1;
                }
                puVar25[0x1a] = uVar10 + 1;
                uVar17 = uVar17 - uVar15;
                uVar26 = uVar26 >> uVar15;
                *(ushort *)((int)puVar25 + uVar10 * 2 + 0x70) = uVar3;
              }
              else {
                if (uVar3 == 0x10) {
                  for (; uVar17 < uVar15 + 2; uVar17 = uVar17 + 8) {
                    if (uVar24 == 0) goto LAB_001b8d3c;
                    uVar24 = uVar24 - 1;
                    uVar26 = uVar26 + ((uint)*pbVar27 << (uVar17 & 0xff));
                    pbVar27 = pbVar27 + 1;
                  }
                  uVar17 = uVar17 - uVar15;
                  uVar26 = uVar26 >> uVar15;
                  if (uVar10 == 0) {
                    param_1[6] = "invalid bit length repeat";
                    *puVar25 = 0x1b;
                    goto LAB_001b7c98;
                  }
                  uVar17 = uVar17 - 2;
                  uVar9 = *(undefined2 *)((int)puVar25 + uVar10 * 2 + 0x6e);
                  iVar8 = (uVar26 & 3) + 3;
                  uVar26 = uVar26 >> 2;
                }
                else {
                  if (uVar3 == 0x11) {
                    for (; uVar17 < uVar15 + 3; uVar17 = uVar17 + 8) {
                      if (uVar24 == 0) goto LAB_001b8d3c;
                      uVar24 = uVar24 - 1;
                      uVar26 = uVar26 + ((uint)*pbVar27 << (uVar17 & 0xff));
                      pbVar27 = pbVar27 + 1;
                    }
                    uVar17 = uVar17 + (-3 - uVar15);
                    uVar11 = (uVar26 >> uVar15) >> 3;
                    iVar8 = (uVar26 >> uVar15 & 7) + 3;
                  }
                  else {
                    for (; uVar17 < uVar15 + 7; uVar17 = uVar17 + 8) {
                      if (uVar24 == 0) goto LAB_001b8d3c;
                      uVar24 = uVar24 - 1;
                      uVar26 = uVar26 + ((uint)*pbVar27 << (uVar17 & 0xff));
                      pbVar27 = pbVar27 + 1;
                    }
                    uVar17 = uVar17 + (-7 - uVar15);
                    uVar11 = (uVar26 >> uVar15) >> 7;
                    iVar8 = (uVar26 >> uVar15 & 0x7f) + 0xb;
                  }
                  uVar9 = 0;
                  uVar26 = uVar11;
                }
                if (uVar12 + uVar14 < uVar10 + iVar8) {
                  param_1[6] = "invalid bit length repeat";
                  *puVar25 = 0x1b;
                  goto LAB_001b7c98;
                }
                puVar25[0x1a] = uVar10 + 1;
                *(undefined2 *)((int)puVar25 + uVar10 * 2 + 0x70) = uVar9;
                if (iVar8 != 1) {
                  iVar8 = 1 - iVar8;
                  do {
                    uVar10 = puVar25[0x1a];
                    iVar8 = iVar8 + 1;
                    puVar25[0x1a] = uVar10 + 1;
                    *(undefined2 *)((int)puVar25 + uVar10 * 2 + 0x70) = uVar9;
                  } while (iVar8 != 0);
                }
              }
              uVar14 = puVar25[0x18];
              uVar12 = puVar25[0x19];
              uVar10 = puVar25[0x1a];
            } while (uVar10 < uVar12 + uVar14);
            if (*puVar25 == 0x1b) break;
          }
          puVar25[0x1b] = (uint)puVar6;
          puVar25[0x13] = (uint)puVar6;
          puVar25[0x15] = 9;
          local_40 = inflate_table(1,puVar25 + 0x1c,uVar14,puVar20,puVar25 + 0x15,puVar5,puVar32);
          if (local_40 == 0) {
            puVar25[0x14] = puVar25[0x1b];
            puVar25[0x16] = 6;
            local_40 = inflate_table(2,(int)puVar25 + puVar25[0x18] * 2 + 0x70,puVar25[0x19],puVar20
                                     ,puVar32,puVar5);
            if (local_40 == 0) {
              *puVar25 = 0x12;
              local_40 = 0;
              goto switchD_001b7ca8_caseD_12;
            }
            pcVar7 = "invalid distances set";
          }
          else {
            pcVar7 = "invalid literal/lengths set";
          }
          param_1[6] = pcVar7;
          *puVar25 = 0x1b;
          break;
        case 0x12:
switchD_001b7ca8_caseD_12:
          bVar31 = uVar30 == 0x102;
          if (0x101 < uVar30) {
            bVar31 = uVar24 == 5;
          }
          if ((0x101 < uVar30 && 4 < uVar24) && !bVar31) {
            param_1[3] = in_r12;
            param_1[4] = uVar30;
            *param_1 = pbVar27;
            param_1[1] = uVar24;
            puVar25[0xe] = uVar26;
            puVar25[0xf] = uVar17;
            inflate_fast(param_1,local_3c);
            pbVar27 = (byte *)*param_1;
            uVar24 = param_1[1];
            in_r12 = (undefined1 *)param_1[3];
            uVar30 = param_1[4];
            uVar26 = puVar25[0xe];
            uVar17 = puVar25[0xf];
          }
          else {
            uVar14 = puVar25[0x13];
            uVar10 = (1 << (puVar25[0x15] & 0xff)) - 1;
            uVar12 = uVar10 & uVar26;
            bVar2 = *(byte *)(uVar14 + uVar12 * 4 + 1);
            for (; uVar11 = (uint)bVar2, uVar17 < uVar11; uVar17 = uVar17 + 8) {
              if (uVar24 == 0) goto LAB_001b8d14;
              uVar24 = uVar24 - 1;
              uVar26 = uVar26 + ((uint)*pbVar27 << (uVar17 & 0xff));
              uVar12 = uVar10 & uVar26;
              bVar2 = *(byte *)(uVar14 + uVar12 * 4 + 1);
              pbVar27 = pbVar27 + 1;
            }
            bVar2 = *(byte *)(uVar14 + uVar12 * 4);
            uVar10 = (uint)bVar2;
            uVar12 = (uint)*(ushort *)(uVar14 + uVar12 * 4 + 2);
            if ((uVar10 != 0) && ((bVar2 & 0xf0) == 0)) {
              uVar10 = (1 << (uVar11 + uVar10 & 0xff)) - 1;
              iVar8 = ((uVar26 & uVar10) >> uVar11) + uVar12;
              bVar2 = *(byte *)(uVar14 + iVar8 * 4 + 1);
              for (; uVar17 < bVar2 + uVar11; uVar17 = uVar17 + 8) {
                if (uVar24 == 0) goto LAB_001b8d1e;
                uVar24 = uVar24 - 1;
                uVar26 = uVar26 + ((uint)*pbVar27 << (uVar17 & 0xff));
                iVar8 = ((uVar26 & uVar10) >> uVar11) + uVar12;
                bVar2 = *(byte *)(uVar14 + iVar8 * 4 + 1);
                pbVar27 = pbVar27 + 1;
              }
              uVar10 = (uint)*(byte *)(uVar14 + iVar8 * 4);
              uVar12 = (uint)*(ushort *)(uVar14 + iVar8 * 4 + 2);
              uVar17 = uVar17 - uVar11;
              uVar26 = uVar26 >> uVar11;
              uVar11 = (uint)bVar2;
            }
            uVar17 = uVar17 - uVar11;
            uVar26 = uVar26 >> uVar11;
            puVar25[0x10] = uVar12;
            if (uVar10 == 0) {
              *puVar25 = 0x17;
            }
            else {
              if ((uVar10 & 0x20) == 0) {
                if ((uVar10 & 0x40) != 0) {
                  pcVar7 = "invalid literal/length code";
                  goto LAB_001b871c;
                }
                uVar10 = uVar10 & 0xf;
                puVar25[0x12] = uVar10;
                *puVar25 = 0x13;
                goto LAB_001b7f8e;
              }
              *puVar25 = 0xb;
            }
          }
          break;
        case 0x13:
          uVar10 = puVar25[0x12];
LAB_001b7f8e:
          if (uVar10 != 0) {
            for (; uVar17 < uVar10; uVar17 = uVar17 + 8) {
              if (uVar24 == 0) goto LAB_001b8c40;
              uVar24 = uVar24 - 1;
              uVar26 = uVar26 + ((uint)*pbVar27 << (uVar17 & 0xff));
              pbVar27 = pbVar27 + 1;
            }
            uVar17 = uVar17 - uVar10;
            uVar14 = (1 << (uVar10 & 0xff)) - 1U & uVar26;
            uVar26 = uVar26 >> (uVar10 & 0xff);
            puVar25[0x10] = uVar14 + puVar25[0x10];
          }
          *puVar25 = 0x14;
        case 0x14:
          uVar14 = puVar25[0x14];
          uVar10 = (1 << (puVar25[0x16] & 0xff)) - 1;
          uVar12 = uVar10 & uVar26;
          bVar2 = *(byte *)(uVar14 + uVar12 * 4 + 1);
          for (; uVar11 = (uint)bVar2, uVar17 < uVar11; uVar17 = uVar17 + 8) {
            if (uVar24 == 0) goto LAB_001b8d14;
            uVar24 = uVar24 - 1;
            uVar26 = uVar26 + ((uint)*pbVar27 << (uVar17 & 0xff));
            uVar12 = uVar10 & uVar26;
            bVar2 = *(byte *)(uVar14 + uVar12 * 4 + 1);
            pbVar27 = pbVar27 + 1;
          }
          bVar2 = *(byte *)(uVar14 + uVar12 * 4);
          uVar10 = (uint)bVar2;
          uVar12 = (uint)*(ushort *)(uVar14 + uVar12 * 4 + 2);
          if ((bVar2 & 0xf0) == 0) {
            uVar10 = (1 << (uVar11 + uVar10 & 0xff)) - 1;
            iVar8 = ((uVar26 & uVar10) >> uVar11) + uVar12;
            bVar2 = *(byte *)(uVar14 + iVar8 * 4 + 1);
            for (; uVar17 < bVar2 + uVar11; uVar17 = uVar17 + 8) {
              if (uVar24 == 0) goto LAB_001b8d1e;
              uVar24 = uVar24 - 1;
              uVar26 = uVar26 + ((uint)*pbVar27 << (uVar17 & 0xff));
              iVar8 = ((uVar26 & uVar10) >> uVar11) + uVar12;
              bVar2 = *(byte *)(uVar14 + iVar8 * 4 + 1);
              pbVar27 = pbVar27 + 1;
            }
            uVar10 = (uint)*(byte *)(uVar14 + iVar8 * 4);
            uVar17 = uVar17 - uVar11;
            uVar12 = (uint)*(ushort *)(uVar14 + iVar8 * 4 + 2);
            uVar26 = uVar26 >> uVar11;
            uVar11 = (uint)bVar2;
          }
          uVar17 = uVar17 - uVar11;
          uVar26 = uVar26 >> uVar11;
          if ((uVar10 & 0x40) == 0) {
            uVar10 = uVar10 & 0xf;
            puVar25[0x11] = uVar12;
            puVar25[0x12] = uVar10;
            *puVar25 = 0x15;
LAB_001b812e:
            if (uVar10 == 0) {
              uVar14 = puVar25[0x11];
            }
            else {
              for (; uVar17 < uVar10; uVar17 = uVar17 + 8) {
                if (uVar24 == 0) goto LAB_001b8c40;
                uVar24 = uVar24 - 1;
                uVar26 = uVar26 + ((uint)*pbVar27 << (uVar17 & 0xff));
                pbVar27 = pbVar27 + 1;
              }
              uVar17 = uVar17 - uVar10;
              uVar14 = (1 << (uVar10 & 0xff)) - 1U & uVar26;
              uVar26 = uVar26 >> (uVar10 & 0xff);
              uVar14 = uVar14 + puVar25[0x11];
              puVar25[0x11] = uVar14;
            }
            if (puVar25[0xb] + (local_3c - uVar30) < uVar14) {
              pcVar7 = "invalid distance too far back";
              goto LAB_001b871c;
            }
            *puVar25 = 0x16;
switchD_001b7ca8_caseD_16:
            if (uVar30 == 0) {
LAB_001b8d4a:
              uVar30 = 0;
              iVar19 = local_40;
              goto switchD_001b7ca8_caseD_1a;
            }
            uVar10 = puVar25[0x11];
            if (local_3c - uVar30 < uVar10) {
              uVar12 = puVar25[0xc];
              uVar14 = uVar10 - (local_3c - uVar30);
              if (uVar12 < uVar14) {
                uVar14 = uVar14 - uVar12;
                puVar13 = (undefined1 *)((puVar25[10] - uVar14) + puVar25[0xd]);
              }
              else {
                puVar13 = (undefined1 *)((uVar12 - uVar14) + puVar25[0xd]);
              }
              uVar10 = puVar25[0x10];
              if (uVar10 < uVar14) {
                uVar14 = uVar10;
              }
            }
            else {
              uVar14 = puVar25[0x10];
              puVar13 = in_r12 + -uVar10;
              uVar10 = uVar14;
            }
            uVar12 = uVar14;
            if (uVar30 < uVar14) {
              uVar12 = uVar30;
            }
            puVar25[0x10] = uVar10 - uVar12;
            uVar10 = ~uVar14;
            if (~uVar14 < ~uVar30) {
              uVar10 = ~uVar30;
            }
            iVar8 = uVar10 + 1;
            puVar29 = in_r12;
            do {
              iVar8 = iVar8 + 1;
              in_r12 = puVar29 + 1;
              *puVar29 = *puVar13;
              puVar13 = puVar13 + 1;
              puVar29 = in_r12;
            } while (iVar8 != 0);
            uVar30 = uVar30 - uVar12;
            if (puVar25[0x10] == 0) {
              *puVar25 = 0x12;
            }
            break;
          }
          param_1[6] = "invalid distance code";
          uVar10 = 0x1b;
          goto LAB_001b8692;
        case 0x15:
          uVar10 = puVar25[0x12];
          goto LAB_001b812e;
        case 0x16:
          goto switchD_001b7ca8_caseD_16;
        case 0x17:
          if (uVar30 != 0) {
            uVar30 = uVar30 - 1;
            *in_r12 = (char)puVar25[0x10];
            uVar10 = 0x12;
            in_r12 = in_r12 + 1;
            goto LAB_001b8720;
          }
          goto LAB_001b8d4a;
        case 0x18:
          if (puVar25[2] != 0) {
            for (; uVar17 < 0x20; uVar17 = uVar17 + 8) {
              if (uVar24 == 0) goto LAB_001b8c40;
              uVar24 = uVar24 - 1;
              uVar26 = uVar26 + ((uint)*pbVar27 << (uVar17 & 0xff));
              pbVar27 = pbVar27 + 1;
            }
            iVar8 = local_3c - uVar30;
            param_1[5] = param_1[5] + iVar8;
            puVar25[7] = puVar25[7] + iVar8;
            if (iVar8 == 0) {
              uVar10 = puVar25[6];
            }
            else {
              if (puVar25[4] == 0) {
                uVar10 = adler32(puVar25[6],(int)in_r12 - iVar8);
              }
              else {
                uVar10 = crc32();
              }
              puVar25[6] = uVar10;
              param_1[0xc] = uVar10;
            }
            uVar14 = uVar26;
            if (puVar25[4] == 0) {
              uVar14 = uVar26 << 0x18 | (uVar26 >> 8 & 0xff) << 0x10 | (uVar26 >> 0x10 & 0xff) << 8
                       | uVar26 >> 0x18;
            }
            local_3c = uVar30;
            if (uVar14 != uVar10) {
              param_1[6] = "incorrect data check";
              *puVar25 = 0x1b;
              break;
            }
            uVar26 = 0;
            uVar17 = 0;
          }
          *puVar25 = 0x19;
        case 0x19:
          if ((puVar25[2] != 0) && (puVar25[4] != 0)) {
            for (; uVar17 < 0x20; uVar17 = uVar17 + 8) {
              if (uVar24 == 0) goto LAB_001b8c40;
              uVar24 = uVar24 - 1;
              uVar26 = uVar26 + ((uint)*pbVar27 << (uVar17 & 0xff));
              pbVar27 = pbVar27 + 1;
            }
            if (uVar26 != puVar25[7]) {
              pcVar7 = "incorrect length check";
              goto LAB_001b871c;
            }
            uVar26 = 0;
            uVar17 = 0;
          }
          *puVar25 = 0x1a;
          iVar19 = 1;
        case 0x1a:
          goto switchD_001b7ca8_caseD_1a;
        case 0x1b:
          iVar19 = -3;
          goto switchD_001b7ca8_caseD_1a;
        case 0x1c:
          goto switchD_001b7ca8_caseD_1c;
        default:
          goto switchD_001b7ca8_default;
        }
LAB_001b7c98:
        uVar10 = *puVar25;
      } while( true );
    }
  }
switchD_001b7ca8_default:
  iVar8 = -2;
switchD_001b7ca8_caseD_1c:
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar8);
LAB_001b8d3c:
  uVar24 = 0;
  iVar19 = local_40;
  goto switchD_001b7ca8_caseD_1a;
LAB_001b8d2c:
  uVar24 = 0;
  iVar19 = local_40;
  goto switchD_001b7ca8_caseD_1a;
LAB_001b8d14:
  uVar24 = 0;
  iVar19 = local_40;
  goto switchD_001b7ca8_caseD_1a;
LAB_001b8d1e:
  uVar24 = 0;
  iVar19 = local_40;
switchD_001b7ca8_caseD_1a:
  param_1[3] = in_r12;
  param_1[4] = uVar30;
  *param_1 = pbVar27;
  param_1[1] = uVar24;
  puVar25[0xe] = uVar26;
  puVar25[0xf] = uVar17;
  if ((puVar25[10] != 0) || ((*puVar25 < 0x18 && (local_3c != uVar30)))) {
    iVar8 = FUN_001b8dc8(param_1,local_3c);
    if (iVar8 != 0) {
      *puVar25 = 0x1c;
      iVar8 = -4;
      goto switchD_001b7ca8_caseD_1c;
    }
    uVar24 = param_1[1];
    uVar30 = param_1[4];
  }
  iVar18 = local_3c - uVar30;
  iVar22 = uVar23 - uVar24;
  param_1[2] = param_1[2] + iVar22;
  param_1[5] = param_1[5] + iVar18;
  uVar10 = puVar25[7] + iVar18;
  puVar25[7] = uVar10;
  if (iVar18 != 0) {
    uVar10 = puVar25[2];
  }
  if (iVar18 != 0 && uVar10 != 0) {
    if (puVar25[4] == 0) {
      uVar10 = adler32(puVar25[6],param_1[3] - iVar18,iVar18);
    }
    else {
      uVar10 = crc32(puVar25[6],param_1[3] - iVar18,iVar18);
    }
    puVar25[6] = uVar10;
    param_1[0xc] = uVar10;
  }
  uVar10 = puVar25[0xf];
  if (puVar25[1] != 0) {
    uVar10 = uVar10 + 0x40;
  }
  if (*puVar25 == 0xb) {
    uVar10 = uVar10 + 0x80;
  }
  param_1[0xb] = uVar10;
  iVar8 = iVar19;
  if (iVar18 == 0 && iVar22 == 0) {
    iVar8 = -5;
  }
  if (param_2 == 4) {
    iVar8 = -5;
  }
  if (iVar19 != 0) {
    iVar8 = iVar19;
  }
  goto switchD_001b7ca8_caseD_1c;
}

// ===== inflateEnd  @0x001b8e80  (46 bytes)
undefined4 inflateEnd(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  if (((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x1c), iVar1 != 0)) &&
     (pcVar2 = *(code **)(param_1 + 0x24), pcVar2 != (code *)0x0)) {
    if (*(int *)(iVar1 + 0x34) != 0) {
      (*pcVar2)(*(undefined4 *)(param_1 + 0x28),*(int *)(iVar1 + 0x34));
      iVar1 = *(int *)(param_1 + 0x1c);
      pcVar2 = *(code **)(param_1 + 0x24);
    }
    (*pcVar2)(*(undefined4 *)(param_1 + 0x28),iVar1);
    *(undefined4 *)(param_1 + 0x1c) = 0;
    return 0;
  }
  return 0xfffffffe;
}

// ===== inflateSetDictionary  @0x001b8eae  (140 bytes)
undefined4 inflateSetDictionary(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  
  if ((param_1 == 0) || (piVar4 = *(int **)(param_1 + 0x1c), piVar4 == (int *)0x0)) {
    return 0xfffffffe;
  }
  if (piVar4[2] == 0) {
    if (*piVar4 != 10) goto LAB_001b8eee;
  }
  else if (*piVar4 != 10) {
    return 0xfffffffe;
  }
  uVar1 = adler32(0,0,0);
  iVar2 = adler32(uVar1,param_2,param_3);
  if (iVar2 != piVar4[6]) {
    return 0xfffffffd;
  }
LAB_001b8eee:
  iVar2 = FUN_001b8dc8(param_1,*(undefined4 *)(param_1 + 0x10));
  if (iVar2 == 0) {
    uVar3 = piVar4[10];
    if (uVar3 < param_3) {
      __aeabi_memcpy(piVar4[0xd],(param_2 + param_3) - uVar3);
      param_3 = piVar4[10];
    }
    else {
      __aeabi_memcpy((piVar4[0xd] + uVar3) - param_3,param_2,param_3);
    }
    piVar4[0xb] = param_3;
    piVar4[3] = 1;
    return 0;
  }
  *piVar4 = 0x1c;
  return 0xfffffffc;
}

// ===== inflateGetHeader  @0x001b8f3a  (28 bytes)
undefined4 inflateGetHeader(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x1c), iVar1 != 0)) {
    if ((*(byte *)(iVar1 + 8) & 2) != 0) {
      *(int *)(iVar1 + 0x20) = param_2;
      *(undefined4 *)(param_2 + 0x30) = 0;
      return 0;
    }
  }
  return 0xfffffffe;
}

// ===== inflateSync  @0x001b8f58  (262 bytes)
void inflateSync(int *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  undefined1 auStack_20 [4];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  if ((param_1 == (int *)0x0) || (piVar9 = (int *)param_1[7], piVar9 == (int *)0x0)) {
    uVar1 = 0xfffffffe;
  }
  else {
    iVar6 = param_1[1];
    if ((iVar6 == 0) && ((uint)piVar9[0xf] < 8)) {
      uVar1 = 0xfffffffb;
    }
    else {
      if (*piVar9 != 0x1d) {
        *piVar9 = 0x1d;
        uVar7 = piVar9[0xf] & 0xfffffff8;
        iVar6 = 0;
        uVar4 = piVar9[0xe] << (piVar9[0xf] & 7U);
        piVar9[0xe] = uVar4;
        piVar9[0xf] = uVar7;
        if (7 < uVar7) {
          uVar2 = 7 - uVar7;
          if (uVar2 < 0xfffffff9) {
            uVar2 = 0xfffffff8;
          }
          iVar6 = (uVar2 + uVar7 >> 3) + 1;
          puVar3 = auStack_20;
          iVar5 = iVar6;
          do {
            *puVar3 = (char)uVar4;
            iVar5 = iVar5 + -1;
            uVar4 = uVar4 >> 8;
            puVar3 = puVar3 + 1;
          } while (iVar5 != 0);
          piVar9[0xe] = uVar4;
          piVar9[0xf] = (uVar7 - 8) - (uVar2 + uVar7 & 0xfffffff8);
        }
        piVar9[0x1a] = 0;
        FUN_001b9068(piVar9 + 0x1a,auStack_20,iVar6);
        iVar6 = param_1[1];
      }
      iVar6 = FUN_001b9068(piVar9 + 0x1a,*param_1,iVar6);
      param_1[1] = param_1[1] - iVar6;
      *param_1 = *param_1 + iVar6;
      iVar5 = param_1[2];
      param_1[2] = iVar5 + iVar6;
      if (piVar9[0x1a] == 4) {
        iVar8 = param_1[5];
        inflateReset(param_1);
        param_1[2] = iVar5 + iVar6;
        param_1[5] = iVar8;
        *piVar9 = 0xb;
        uVar1 = 0;
      }
      else {
        uVar1 = 0xfffffffd;
      }
    }
  }
  if (__stack_chk_guard == local_1c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar1);
}

// ===== inflateSyncPoint  @0x001b90b4  (32 bytes)
uint inflateSyncPoint(int param_1)

{
  int *piVar1;
  
  if ((param_1 != 0) && (piVar1 = *(int **)(param_1 + 0x1c), piVar1 != (int *)0x0)) {
    if (*piVar1 != 0xd) {
      return 0;
    }
    return (uint)(piVar1[0xf] == 0);
  }
  return 0xfffffffe;
}

// ===== inflateCopy  @0x001b90d4  (248 bytes)
undefined4 inflateCopy(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,code *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  
  if (param_1 == (undefined4 *)0x0 || param_2 == (undefined4 *)0x0) {
    return 0xfffffffe;
  }
  iVar10 = param_2[7];
  if (iVar10 != 0) {
    param_4 = (code *)param_2[8];
  }
  if ((iVar10 == 0 || param_4 == (code *)0x0) || (param_2[9] == 0)) {
    return 0xfffffffe;
  }
  iVar1 = (*param_4)(param_2[10],1,0x2530);
  if (iVar1 == 0) {
LAB_001b913c:
    uVar3 = 0xfffffffc;
  }
  else {
    if (*(int *)(iVar10 + 0x34) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(code *)param_2[8])(param_2[10],1 << (*(uint *)(iVar10 + 0x24) & 0xff),1);
      if (iVar2 == 0) {
        (*(code *)param_2[9])(param_2[10],iVar1);
        goto LAB_001b913c;
      }
    }
    uVar3 = param_2[1];
    uVar7 = param_2[2];
    uVar8 = param_2[3];
    *param_1 = *param_2;
    param_1[1] = uVar3;
    param_1[2] = uVar7;
    param_1[3] = uVar8;
    uVar3 = param_2[5];
    uVar7 = param_2[6];
    uVar8 = param_2[7];
    uVar9 = param_2[8];
    param_1[4] = param_2[4];
    param_1[5] = uVar3;
    param_1[6] = uVar7;
    param_1[7] = uVar8;
    param_1[8] = uVar9;
    uVar3 = param_2[10];
    uVar7 = param_2[0xb];
    uVar8 = param_2[0xc];
    uVar9 = param_2[0xd];
    param_1[9] = param_2[9];
    param_1[10] = uVar3;
    param_1[0xb] = uVar7;
    param_1[0xc] = uVar8;
    param_1[0xd] = uVar9;
    __aeabi_memcpy4(iVar1,iVar10,0x2530);
    uVar6 = *(uint *)(iVar10 + 0x4c);
    uVar5 = iVar10 + 0x530;
    iVar4 = iVar1 + 0x530;
    if ((uVar5 <= uVar6) && (uVar6 <= iVar10 + 0x252cU)) {
      *(uint *)(iVar1 + 0x4c) = (uVar6 - uVar5) + iVar4;
      *(uint *)(iVar1 + 0x50) = (*(int *)(iVar10 + 0x50) - uVar5) + iVar4;
    }
    *(uint *)(iVar1 + 0x6c) = iVar4 + (*(int *)(iVar10 + 0x6c) - uVar5);
    if (iVar2 != 0) {
      __aeabi_memcpy(iVar2,*(undefined4 *)(iVar10 + 0x34),1 << (*(uint *)(iVar10 + 0x24) & 0xff));
    }
    uVar3 = 0;
    *(int *)(iVar1 + 0x34) = iVar2;
    param_1[7] = iVar1;
  }
  return uVar3;
}

// ===== compress2  @0x001b91cc  (124 bytes)
void compress2(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5)

{
  int iVar1;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 local_24;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_3c = *param_2;
  local_2c = 0;
  uStack_28 = 0;
  local_24 = 0;
  local_4c = param_3;
  uStack_48 = param_4;
  local_40 = param_1;
  iVar1 = deflateInit_(&local_4c,param_5,"1.2.3",0x38);
  if (iVar1 == 0) {
    iVar1 = deflate(&local_4c,4);
    if (iVar1 == 1) {
      *param_2 = local_38;
      deflateEnd(&local_4c);
    }
    else {
      deflateEnd(&local_4c);
    }
  }
  if (__stack_chk_guard - local_14 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_14);
}

// ===== compress  @0x001b9254  (22 bytes)
void compress(void)

{
  compress2();
  return;
}

// ===== compressBound  @0x001b926a  (12 bytes)
int compressBound(uint param_1)

{
  return param_1 + (param_1 >> 0xc) + (param_1 >> 0xe) + 0xb;
}

// ===== deflateInit_  @0x001b9276  (34 bytes)
void deflateInit_(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  deflateInit2_(param_1,param_2,8,0xf,8,0,param_3,param_4);
  return;
}

// ===== deflateInit2_  @0x001b9298  (404 bytes)
undefined4
deflateInit2_(int param_1,uint param_2,int param_3,uint param_4,int param_5,uint param_6,
             byte *param_7,int param_8)

{
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  bool bVar8;
  
  if (param_7 == (byte *)0x0) {
    uVar1 = 0xfffffffa;
  }
  else {
    uVar1 = 0xfffffffa;
    if (param_8 == 0x38) {
      param_7 = (byte *)(uint)*param_7;
    }
    if (param_8 == 0x38 && param_7 == (byte *)0x31) {
      if (param_1 == 0) {
        uVar1 = 0xfffffffe;
      }
      else {
        *(undefined4 *)(param_1 + 0x18) = 0;
        pcVar4 = *(code **)(param_1 + 0x20);
        if (pcVar4 == (code *)0x0) {
          pcVar4 = zcalloc;
          *(code **)(param_1 + 0x20) = zcalloc;
          *(undefined4 *)(param_1 + 0x28) = 0;
        }
        if (*(int *)(param_1 + 0x24) == 0) {
          *(code **)(param_1 + 0x24) = zcfree;
        }
        if (param_2 == 0xffffffff) {
          param_2 = 6;
        }
        if ((int)param_4 < 0) {
          param_4 = -param_4;
          iVar6 = 0;
        }
        else {
          iVar6 = 1;
          if (0xf < (int)param_4) {
            iVar6 = 2;
            param_4 = param_4 - 0x10;
          }
        }
        bVar8 = 3 < param_6;
        bVar7 = param_6 == 4;
        uVar1 = 0xfffffffe;
        if (param_6 < 5) {
          bVar8 = 8 < param_2;
          bVar7 = param_2 == 9;
        }
        if ((((!bVar8 || bVar7) && (param_3 == 8)) && (param_5 - 1U < 9)) &&
           ((param_4 & 0xfffffff8) == 8)) {
          piVar2 = (int *)(*pcVar4)(*(undefined4 *)(param_1 + 0x28),1,0x16c0);
          if (param_4 == 8) {
            param_4 = 9;
          }
          if (piVar2 != (int *)0x0) {
            *(int **)(param_1 + 0x1c) = piVar2;
            *piVar2 = param_1;
            piVar2[6] = iVar6;
            piVar2[7] = 0;
            iVar6 = 1 << (param_4 & 0xff);
            piVar2[0xc] = param_4;
            piVar2[0xb] = iVar6;
            piVar2[0xd] = iVar6 + -1;
            iVar5 = 1 << (param_5 + 7U & 0xff);
            piVar2[0x13] = iVar5;
            piVar2[0x14] = param_5 + 7U;
            piVar2[0x15] = iVar5 + -1;
            piVar2[0x16] = (param_5 + 9U) / 3;
            iVar6 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),iVar6,2);
            piVar2[0xe] = iVar6;
            iVar6 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),piVar2[0xb],2);
            piVar2[0x10] = iVar6;
            iVar6 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),piVar2[0x13],2);
            piVar2[0x11] = iVar6;
            iVar6 = 1 << (param_5 + 6U & 0xff);
            piVar2[0x5a7] = iVar6;
            iVar6 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),iVar6,4);
            piVar2[2] = iVar6;
            uVar3 = piVar2[0x5a7];
            piVar2[3] = uVar3 << 2;
            if (((piVar2[0xe] != 0) && (piVar2[0x10] != 0)) && ((piVar2[0x11] != 0 && (iVar6 != 0)))
               ) {
              piVar2[0x5a9] = (uVar3 & 0xfffffffe) + iVar6;
              piVar2[0x5a6] = iVar6 + uVar3 * 3;
              piVar2[0x21] = param_2;
              piVar2[0x22] = param_6;
              *(undefined1 *)(piVar2 + 9) = 8;
              uVar1 = deflateReset(param_1);
              return uVar1;
            }
            piVar2[1] = 0x29a;
            *(undefined4 *)(param_1 + 0x18) = 0x221999;
            deflateEnd(param_1);
          }
          uVar1 = 0xfffffffc;
        }
      }
    }
  }
  return uVar1;
}

// ===== deflateEnd  @0x001b9438  (158 bytes)
undefined4 deflateEnd(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 != 0) && (iVar2 = *(int *)(param_1 + 0x1c), iVar2 != 0)) {
    iVar3 = *(int *)(iVar2 + 4);
    if (((iVar3 - 0x2aU < 0x20) && ((1 << (iVar3 - 0x2aU & 0xff) & 0x88000001U) != 0)) ||
       (((iVar3 - 0x5bU < 0x17 && ((1 << (iVar3 - 0x5bU & 0xff) & 0x401001U) != 0)) ||
        (iVar3 == 0x29a)))) {
      if (*(int *)(iVar2 + 8) != 0) {
        (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),*(int *)(iVar2 + 8));
        iVar2 = *(int *)(param_1 + 0x1c);
      }
      if (*(int *)(iVar2 + 0x44) != 0) {
        (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),*(int *)(iVar2 + 0x44));
        iVar2 = *(int *)(param_1 + 0x1c);
      }
      if (*(int *)(iVar2 + 0x40) != 0) {
        (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),*(int *)(iVar2 + 0x40));
        iVar2 = *(int *)(param_1 + 0x1c);
      }
      if (*(int *)(iVar2 + 0x38) != 0) {
        (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),*(int *)(iVar2 + 0x38));
        iVar2 = *(int *)(param_1 + 0x1c);
      }
      (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),iVar2);
      uVar1 = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0;
      if (iVar3 == 0x71) {
        uVar1 = 0xfffffffd;
      }
      return uVar1;
    }
  }
  return 0xfffffffe;
}

// ===== deflateReset  @0x001b94d8  (182 bytes)
undefined4 deflateReset(int param_1)

{
  int iVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  
  if ((((param_1 == 0) || (iVar7 = *(int *)(param_1 + 0x1c), iVar7 == 0)) ||
      (*(int *)(param_1 + 0x20) == 0)) || (*(int *)(param_1 + 0x24) == 0)) {
    uVar6 = 0xfffffffe;
  }
  else {
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 2;
    uVar6 = 0x71;
    *(undefined4 *)(iVar7 + 0x14) = 0;
    *(undefined4 *)(iVar7 + 0x10) = *(undefined4 *)(iVar7 + 8);
    uVar5 = *(uint *)(iVar7 + 0x18);
    if (0x7fffffff < uVar5) {
      uVar5 = -uVar5;
      *(uint *)(iVar7 + 0x18) = uVar5;
    }
    if (uVar5 != 0) {
      uVar6 = 0x2a;
    }
    *(undefined4 *)(iVar7 + 4) = uVar6;
    if (uVar5 == 2) {
      uVar6 = crc32(0,0,0);
    }
    else {
      uVar6 = adler32(0,0,0);
    }
    *(undefined4 *)(param_1 + 0x30) = uVar6;
    uVar6 = 0;
    *(undefined4 *)(iVar7 + 0x28) = 0;
    _tr_init(iVar7);
    *(int *)(iVar7 + 0x3c) = *(int *)(iVar7 + 0x2c) << 1;
    *(undefined2 *)(*(int *)(iVar7 + 0x44) + *(int *)(iVar7 + 0x4c) * 2 + -2) = 0;
    __aeabi_memclr();
    iVar1 = *(int *)(iVar7 + 0x84) * 0xc;
    uVar2 = *(ushort *)(&DAT_00264b2c + iVar1);
    uVar3 = *(ushort *)(&DAT_00264b2a + iVar1);
    uVar4 = *(ushort *)(&DAT_00264b2e + iVar1);
    *(uint *)(iVar7 + 0x8c) = (uint)*(ushort *)(&DAT_00264b28 + *(int *)(iVar7 + 0x84) * 0xc);
    *(uint *)(iVar7 + 0x90) = (uint)uVar2;
    *(uint *)(iVar7 + 0x7c) = (uint)uVar4;
    *(uint *)(iVar7 + 0x80) = (uint)uVar3;
    *(undefined4 *)(iVar7 + 0x6c) = 0;
    *(undefined4 *)(iVar7 + 0x5c) = 0;
    *(undefined4 *)(iVar7 + 0x74) = 0;
    *(undefined4 *)(iVar7 + 0x78) = 2;
    *(undefined4 *)(iVar7 + 0x60) = 2;
    *(undefined4 *)(iVar7 + 0x68) = 0;
    *(undefined4 *)(iVar7 + 0x48) = 0;
  }
  return uVar6;
}

// ===== deflateSetDictionary  @0x001b9594  (214 bytes)
undefined4 deflateSetDictionary(int param_1,int param_2,uint param_3)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  
  if (param_1 == 0) {
    return 0xfffffffe;
  }
  uVar2 = 0xfffffffe;
  if ((param_2 != 0) && (iVar9 = *(int *)(param_1 + 0x1c), iVar9 != 0)) {
    iVar3 = *(int *)(iVar9 + 0x18);
    if (iVar3 != 0) {
      if (iVar3 == 2) {
        return 0xfffffffe;
      }
      if ((iVar3 == 1) && (*(int *)(iVar9 + 4) != 0x2a)) {
        return 0xfffffffe;
      }
      uVar2 = adler32(*(undefined4 *)(param_1 + 0x30),param_2,param_3);
      *(undefined4 *)(param_1 + 0x30) = uVar2;
    }
    if (2 < param_3) {
      uVar5 = *(int *)(iVar9 + 0x2c) - 0x106;
      if (uVar5 <= param_3 && param_3 - uVar5 != 0) {
        param_2 = param_2 + (param_3 - uVar5);
        param_3 = uVar5;
      }
      __aeabi_memcpy(*(undefined4 *)(iVar9 + 0x38),param_2,param_3);
      *(uint *)(iVar9 + 0x6c) = param_3;
      *(uint *)(iVar9 + 0x5c) = param_3;
      pbVar4 = *(byte **)(iVar9 + 0x38);
      bVar1 = *pbVar4;
      *(uint *)(iVar9 + 0x48) = (uint)bVar1;
      uVar10 = *(uint *)(iVar9 + 0x54);
      uVar11 = *(uint *)(iVar9 + 0x58);
      uVar6 = ((uint)bVar1 << (uVar11 & 0xff) ^ (uint)pbVar4[1]) & uVar10;
      *(uint *)(iVar9 + 0x48) = uVar6;
      uVar8 = *(uint *)(iVar9 + 0x34);
      uVar5 = 0;
      iVar7 = *(int *)(iVar9 + 0x40);
      iVar3 = *(int *)(iVar9 + 0x44);
      do {
        uVar6 = ((uint)pbVar4[uVar5 + 2] ^ uVar6 << (uVar11 & 0xff)) & uVar10;
        *(uint *)(iVar9 + 0x48) = uVar6;
        *(undefined2 *)(iVar7 + (uVar8 & uVar5) * 2) = *(undefined2 *)(iVar3 + uVar6 * 2);
        *(short *)(iVar3 + uVar6 * 2) = (short)uVar5;
        uVar5 = uVar5 + 1;
      } while (uVar5 <= param_3 - 3);
    }
    uVar2 = 0;
  }
  return uVar2;
}

// ===== deflateSetHeader  @0x001b966a  (24 bytes)
undefined4 deflateSetHeader(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x1c), iVar1 != 0)) &&
     (*(int *)(iVar1 + 0x18) == 2)) {
    *(undefined4 *)(iVar1 + 0x1c) = param_2;
    return 0;
  }
  return 0xfffffffe;
}

// ===== deflatePrime  @0x001b9682  (42 bytes)
undefined4 deflatePrime(int param_1,uint param_2,ushort param_3)

{
  int iVar1;
  
  if ((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x1c), iVar1 != 0)) {
    *(uint *)(iVar1 + 0x16bc) = param_2;
    *(ushort *)(iVar1 + 0x16b8) = (short)(1 << (param_2 & 0xff)) - 1U & param_3;
    return 0;
  }
  return 0xfffffffe;
}

// ===== deflateParams  @0x001b96ac  (144 bytes)
undefined4 deflateParams(int param_1,uint param_2,uint param_3)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  bool bVar9;
  
  if ((param_1 != 0) && (iVar7 = *(int *)(param_1 + 0x1c), iVar7 != 0)) {
    if (param_2 == 0xffffffff) {
      param_2 = 6;
    }
    bVar9 = 3 < param_3;
    bVar8 = param_3 == 4;
    uVar4 = 0xfffffffe;
    if (param_3 < 5) {
      bVar9 = 8 < param_2;
      bVar8 = param_2 == 9;
    }
    if (!bVar9 || bVar8) {
      uVar6 = *(uint *)(iVar7 + 0x84);
      iVar5 = *(int *)(&DAT_00264b30 + uVar6 * 0xc);
      bVar8 = iVar5 != *(int *)(&DAT_00264b30 + param_2 * 0xc);
      if (bVar8) {
        iVar5 = *(int *)(param_1 + 8);
      }
      if (bVar8 && iVar5 != 0) {
        uVar4 = deflate(param_1,1);
        uVar6 = *(uint *)(iVar7 + 0x84);
      }
      else {
        uVar4 = 0;
      }
      if (uVar6 != param_2) {
        *(uint *)(iVar7 + 0x84) = param_2;
        iVar5 = param_2 * 0xc;
        uVar1 = *(ushort *)(&DAT_00264b2c + iVar5);
        uVar2 = *(ushort *)(&DAT_00264b2e + iVar5);
        uVar3 = *(ushort *)(&DAT_00264b2a + iVar5);
        *(uint *)(iVar7 + 0x8c) = (uint)*(ushort *)(&DAT_00264b28 + param_2 * 0xc);
        *(uint *)(iVar7 + 0x90) = (uint)uVar1;
        *(uint *)(iVar7 + 0x7c) = (uint)uVar2;
        *(uint *)(iVar7 + 0x80) = (uint)uVar3;
      }
      *(uint *)(iVar7 + 0x88) = param_3;
    }
    return uVar4;
  }
  return 0xfffffffe;
}

// ===== deflate  @0x001b9744  (1692 bytes)
uint deflate(int *param_1,uint param_2)

{
  char cVar1;
  undefined2 uVar2;
  bool bVar3;
  undefined1 uVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  byte bVar17;
  
  if (param_1 == (int *)0x0) {
    return 0xfffffffe;
  }
  if (4 < param_2) {
    return 0xfffffffe;
  }
  piVar12 = (int *)param_1[7];
  if (piVar12 == (int *)0x0) {
    return 0xfffffffe;
  }
  if (((param_1[3] == 0) || ((*param_1 == 0 && (param_1[1] != 0)))) ||
     ((iVar5 = piVar12[1], param_2 != 4 && (iVar5 == 0x29a)))) {
    param_1[6] = 0x221981;
    return 0xfffffffe;
  }
  if (param_1[4] == 0) goto LAB_001b9c64;
  *piVar12 = (int)param_1;
  iVar14 = piVar12[10];
  piVar12[10] = param_2;
  if (iVar5 == 0x2a) {
    if (piVar12[6] != 2) {
      if ((piVar12[0x22] < 2) && (iVar5 = piVar12[0x21], 1 < iVar5)) {
        if (iVar5 < 6) {
          uVar9 = 0x40;
        }
        else {
          uVar9 = 0xc0;
          if (iVar5 == 6) {
            uVar9 = 0x80;
          }
        }
      }
      else {
        uVar9 = 0;
      }
      piVar12[1] = 0x71;
      uVar9 = piVar12[0xc] * 0x1000 - 0x7800U | uVar9;
      iVar5 = piVar12[5];
      piVar12[5] = iVar5 + 1;
      if (piVar12[0x1b] != 0) {
        uVar9 = uVar9 | 0x20;
      }
      *(char *)(piVar12[2] + iVar5) = (char)(uVar9 >> 8);
      iVar5 = piVar12[5];
      piVar12[5] = iVar5 + 1;
      *(byte *)(piVar12[2] + iVar5) =
           ((byte)uVar9 | (byte)uVar9 - ((char)(uVar9 / 0x1f) * ' ' - (char)(uVar9 / 0x1f))) ^ 0x1f;
      if (piVar12[0x1b] != 0) {
        iVar5 = piVar12[5];
        iVar10 = param_1[0xc];
        piVar12[5] = iVar5 + 1;
        *(char *)(piVar12[2] + iVar5) = (char)((uint)iVar10 >> 0x18);
        iVar5 = piVar12[5];
        piVar12[5] = iVar5 + 1;
        *(char *)(piVar12[2] + iVar5) = (char)((uint)iVar10 >> 0x10);
        iVar5 = piVar12[5];
        iVar10 = param_1[0xc];
        piVar12[5] = iVar5 + 1;
        *(char *)(piVar12[2] + iVar5) = (char)((uint)iVar10 >> 8);
        iVar5 = piVar12[5];
        piVar12[5] = iVar5 + 1;
        *(char *)(piVar12[2] + iVar5) = (char)iVar10;
      }
      iVar5 = adler32(0,0,0);
      param_1[0xc] = iVar5;
      iVar5 = piVar12[1];
      goto LAB_001b9930;
    }
    iVar5 = crc32(0,0,0);
    param_1[0xc] = iVar5;
    iVar5 = piVar12[5];
    piVar12[5] = iVar5 + 1;
    *(undefined1 *)(piVar12[2] + iVar5) = 0x1f;
    iVar5 = piVar12[5];
    piVar12[5] = iVar5 + 1;
    *(undefined1 *)(piVar12[2] + iVar5) = 0x8b;
    iVar5 = piVar12[5];
    piVar12[5] = iVar5 + 1;
    *(undefined1 *)(piVar12[2] + iVar5) = 8;
    piVar6 = (int *)piVar12[7];
    if (piVar6 != (int *)0x0) {
      iVar13 = piVar12[5];
      iVar10 = piVar6[4];
      iVar16 = piVar6[7];
      bVar17 = *piVar6 != 0;
      iVar15 = piVar6[9];
      iVar5 = piVar6[0xb];
      piVar12[5] = iVar13 + 1;
      if (iVar5 != 0) {
        bVar17 = bVar17 | 2;
      }
      if (iVar10 != 0) {
        bVar17 = bVar17 | 4;
      }
      if (iVar16 != 0) {
        bVar17 = bVar17 | 8;
      }
      if (iVar15 != 0) {
        bVar17 = bVar17 | 0x10;
      }
      *(byte *)(piVar12[2] + iVar13) = bVar17;
      iVar5 = piVar12[5];
      uVar7 = *(undefined4 *)(piVar12[7] + 4);
      piVar12[5] = iVar5 + 1;
      *(char *)(piVar12[2] + iVar5) = (char)uVar7;
      iVar5 = piVar12[5];
      uVar7 = *(undefined4 *)(piVar12[7] + 4);
      piVar12[5] = iVar5 + 1;
      *(char *)(piVar12[2] + iVar5) = (char)((uint)uVar7 >> 8);
      iVar5 = piVar12[5];
      uVar2 = *(undefined2 *)(piVar12[7] + 6);
      piVar12[5] = iVar5 + 1;
      *(char *)(piVar12[2] + iVar5) = (char)uVar2;
      iVar5 = piVar12[5];
      uVar4 = *(undefined1 *)(piVar12[7] + 7);
      piVar12[5] = iVar5 + 1;
      *(undefined1 *)(piVar12[2] + iVar5) = uVar4;
      if (piVar12[0x21] == 9) {
        uVar4 = 2;
      }
      else {
        uVar4 = 0;
        if (1 < piVar12[0x22]) {
          uVar4 = 4;
        }
        if (piVar12[0x21] < 2) {
          uVar4 = 4;
        }
      }
      iVar5 = piVar12[5];
      piVar12[5] = iVar5 + 1;
      *(undefined1 *)(piVar12[2] + iVar5) = uVar4;
      iVar5 = piVar12[5];
      uVar7 = *(undefined4 *)(piVar12[7] + 0xc);
      piVar12[5] = iVar5 + 1;
      *(char *)(piVar12[2] + iVar5) = (char)uVar7;
      iVar5 = piVar12[7];
      if (*(int *)(iVar5 + 0x10) != 0) {
        iVar10 = piVar12[5];
        uVar7 = *(undefined4 *)(iVar5 + 0x14);
        piVar12[5] = iVar10 + 1;
        *(char *)(piVar12[2] + iVar10) = (char)uVar7;
        iVar5 = piVar12[5];
        uVar7 = *(undefined4 *)(piVar12[7] + 0x14);
        piVar12[5] = iVar5 + 1;
        *(char *)(piVar12[2] + iVar5) = (char)((uint)uVar7 >> 8);
        iVar5 = piVar12[7];
      }
      if (*(int *)(iVar5 + 0x2c) != 0) {
        iVar5 = crc32(param_1[0xc],piVar12[2],piVar12[5]);
        param_1[0xc] = iVar5;
      }
      piVar12[8] = 0;
      piVar12[1] = 0x45;
      goto LAB_001b99ec;
    }
    iVar5 = piVar12[5];
    piVar12[5] = iVar5 + 1;
    *(undefined1 *)(piVar12[2] + iVar5) = 0;
    iVar5 = piVar12[5];
    piVar12[5] = iVar5 + 1;
    *(undefined1 *)(piVar12[2] + iVar5) = 0;
    iVar5 = piVar12[5];
    piVar12[5] = iVar5 + 1;
    *(undefined1 *)(piVar12[2] + iVar5) = 0;
    iVar5 = piVar12[5];
    piVar12[5] = iVar5 + 1;
    *(undefined1 *)(piVar12[2] + iVar5) = 0;
    iVar5 = piVar12[5];
    piVar12[5] = iVar5 + 1;
    *(undefined1 *)(piVar12[2] + iVar5) = 0;
    if (piVar12[0x21] == 9) {
      uVar4 = 2;
    }
    else {
      uVar4 = 0;
      if (1 < piVar12[0x22]) {
        uVar4 = 4;
      }
      if (piVar12[0x21] < 2) {
        uVar4 = 4;
      }
    }
    iVar5 = piVar12[5];
    piVar12[5] = iVar5 + 1;
    *(undefined1 *)(piVar12[2] + iVar5) = uVar4;
    iVar5 = piVar12[5];
    piVar12[5] = iVar5 + 1;
    *(undefined1 *)(piVar12[2] + iVar5) = 3;
LAB_001b9c2a:
    piVar12[1] = 0x71;
  }
  else {
LAB_001b9930:
    if (iVar5 == 0x45) {
LAB_001b99ec:
      iVar5 = piVar12[7];
      if (*(int *)(iVar5 + 0x10) != 0) {
        uVar8 = piVar12[5];
        uVar11 = piVar12[8];
        uVar9 = uVar8;
        if (uVar11 < *(ushort *)(iVar5 + 0x14)) {
          do {
            if (uVar9 == piVar12[3]) {
              if ((uVar8 < uVar9) && (*(int *)(iVar5 + 0x2c) != 0)) {
                iVar5 = crc32(param_1[0xc],piVar12[2] + uVar8,uVar9 - uVar8);
                param_1[0xc] = iVar5;
              }
              FUN_001b9e38(param_1);
              uVar8 = piVar12[5];
              if (uVar8 == piVar12[3]) {
                iVar5 = piVar12[7];
                break;
              }
              iVar5 = piVar12[7];
              uVar11 = piVar12[8];
              uVar9 = uVar8;
            }
            uVar4 = *(undefined1 *)(*(int *)(iVar5 + 0x10) + uVar11);
            piVar12[5] = uVar9 + 1;
            *(undefined1 *)(piVar12[2] + uVar9) = uVar4;
            uVar11 = piVar12[8] + 1;
            piVar12[8] = uVar11;
            iVar5 = piVar12[7];
            if (*(ushort *)(iVar5 + 0x14) <= uVar11) break;
            uVar9 = piVar12[5];
          } while( true );
        }
        if ((*(int *)(iVar5 + 0x2c) != 0) && (uVar8 < (uint)piVar12[5])) {
          iVar5 = crc32(param_1[0xc],uVar8 + piVar12[2],piVar12[5] - uVar8);
          param_1[0xc] = iVar5;
          iVar5 = piVar12[7];
        }
        if (piVar12[8] != *(int *)(iVar5 + 0x14)) {
          iVar5 = piVar12[1];
          goto LAB_001b9a90;
        }
        piVar12[8] = 0;
      }
      piVar12[1] = 0x49;
LAB_001b9a9a:
      piVar6 = piVar12 + 7;
      if (*(int *)(iVar5 + 0x1c) != 0) {
        uVar9 = piVar12[5];
        uVar8 = uVar9;
        while( true ) {
          if (uVar9 == piVar12[3]) {
            if ((uVar8 < uVar9) && (*(int *)(*piVar6 + 0x2c) != 0)) {
              iVar5 = crc32(param_1[0xc],piVar12[2] + uVar8,uVar9 - uVar8);
              param_1[0xc] = iVar5;
            }
            FUN_001b9e38(param_1);
            uVar8 = piVar12[5];
            uVar9 = uVar8;
            if (uVar8 == piVar12[3]) {
              bVar3 = true;
              goto LAB_001b9af8;
            }
          }
          iVar5 = piVar12[8];
          piVar12[8] = iVar5 + 1;
          cVar1 = *(char *)(*(int *)(*piVar6 + 0x1c) + iVar5);
          piVar12[5] = uVar9 + 1;
          *(char *)(piVar12[2] + uVar9) = cVar1;
          if (cVar1 == '\0') break;
          uVar9 = piVar12[5];
        }
        bVar3 = false;
LAB_001b9af8:
        if ((*(int *)(*piVar6 + 0x2c) != 0) && (uVar8 < (uint)piVar12[5])) {
          iVar5 = crc32(param_1[0xc],uVar8 + piVar12[2],piVar12[5] - uVar8);
          param_1[0xc] = iVar5;
        }
        if (bVar3) {
          iVar5 = piVar12[1];
          goto LAB_001b9b18;
        }
        piVar12[8] = 0;
      }
      piVar12[1] = 0x5b;
LAB_001b9b2a:
      piVar6 = piVar12 + 7;
      if (*(int *)(*piVar6 + 0x24) != 0) {
        uVar9 = piVar12[5];
        uVar8 = uVar9;
        while( true ) {
          if (uVar9 == piVar12[3]) {
            if ((uVar8 < uVar9) && (*(int *)(*piVar6 + 0x2c) != 0)) {
              iVar5 = crc32(param_1[0xc],piVar12[2] + uVar8,uVar9 - uVar8);
              param_1[0xc] = iVar5;
            }
            FUN_001b9e38(param_1);
            uVar8 = piVar12[5];
            uVar9 = uVar8;
            if (uVar8 == piVar12[3]) {
              bVar3 = true;
              goto LAB_001b9b8c;
            }
          }
          iVar5 = piVar12[8];
          piVar12[8] = iVar5 + 1;
          cVar1 = *(char *)(*(int *)(*piVar6 + 0x24) + iVar5);
          piVar12[5] = uVar9 + 1;
          *(char *)(piVar12[2] + uVar9) = cVar1;
          if (cVar1 == '\0') break;
          uVar9 = piVar12[5];
        }
        bVar3 = false;
LAB_001b9b8c:
        if ((*(int *)(*piVar6 + 0x2c) != 0) && (uVar8 < (uint)piVar12[5])) {
          iVar5 = crc32(param_1[0xc],uVar8 + piVar12[2],piVar12[5] - uVar8);
          param_1[0xc] = iVar5;
        }
        if (bVar3) {
          iVar5 = piVar12[1];
          goto LAB_001b9bac;
        }
      }
      piVar12[1] = 0x67;
LAB_001b9bba:
      if (*(int *)(piVar12[7] + 0x2c) != 0) {
        iVar5 = piVar12[5];
        uVar9 = piVar12[3];
        if (uVar9 < iVar5 + 2U) {
          FUN_001b9e38(param_1);
          uVar9 = piVar12[3];
          iVar5 = piVar12[5];
        }
        if (uVar9 < iVar5 + 2U) goto LAB_001b9c2e;
        iVar10 = param_1[0xc];
        piVar12[5] = iVar5 + 1;
        *(char *)(piVar12[2] + iVar5) = (char)iVar10;
        iVar5 = piVar12[5];
        iVar10 = param_1[0xc];
        piVar12[5] = iVar5 + 1;
        *(char *)(piVar12[2] + iVar5) = (char)((uint)iVar10 >> 8);
        iVar5 = crc32(0,0,0);
        param_1[0xc] = iVar5;
      }
      goto LAB_001b9c2a;
    }
LAB_001b9a90:
    if (iVar5 == 0x49) {
      iVar5 = piVar12[7];
      goto LAB_001b9a9a;
    }
LAB_001b9b18:
    if (iVar5 == 0x5b) goto LAB_001b9b2a;
LAB_001b9bac:
    if (iVar5 == 0x67) goto LAB_001b9bba;
  }
LAB_001b9c2e:
  if (piVar12[5] == 0) {
    if (((param_2 != 4) && ((int)param_2 <= iVar14)) && (param_1[1] == 0)) goto LAB_001b9c64;
LAB_001b9c52:
    if (piVar12[1] == 0x29a) {
      if (param_1[1] != 0) {
LAB_001b9c64:
        param_1[6] = 0x2219ad;
        return 0xfffffffb;
      }
LAB_001b9c72:
      if ((piVar12[0x1d] != 0) || (piVar12[1] != 0x29a && param_2 != 0)) goto LAB_001b9c94;
    }
    else {
      if (param_1[1] == 0) goto LAB_001b9c72;
LAB_001b9c94:
      uVar9 = (**(code **)(&DAT_00264b30 + piVar12[0x21] * 0xc))(piVar12,param_2);
      if ((uVar9 | 1) == 3) {
        piVar12[1] = 0x29a;
      }
      if ((uVar9 | 2) == 2) {
        if (param_1[4] != 0) {
          return 0;
        }
        goto LAB_001b9d7c;
      }
      if (uVar9 == 1) {
        if (param_2 == 1) {
          _tr_align(piVar12);
        }
        else {
          _tr_stored_block(piVar12,0,0,0);
          if (param_2 == 3) {
            *(undefined2 *)(piVar12[0x11] + piVar12[0x13] * 2 + -2) = 0;
            __aeabi_memclr();
          }
        }
        FUN_001b9e38(param_1);
        if (param_1[4] == 0) goto LAB_001b9d7c;
      }
    }
    if (param_2 == 4) {
      if (piVar12[6] < 1) {
        return 1;
      }
      iVar5 = param_1[0xc];
      if (piVar12[6] == 2) {
        iVar14 = piVar12[5];
        piVar12[5] = iVar14 + 1;
        *(char *)(piVar12[2] + iVar14) = (char)iVar5;
        iVar5 = piVar12[5];
        iVar14 = param_1[0xc];
        piVar12[5] = iVar5 + 1;
        *(char *)(piVar12[2] + iVar5) = (char)((uint)iVar14 >> 8);
        iVar5 = piVar12[5];
        uVar2 = *(undefined2 *)((int)param_1 + 0x32);
        piVar12[5] = iVar5 + 1;
        *(char *)(piVar12[2] + iVar5) = (char)uVar2;
        iVar5 = piVar12[5];
        uVar4 = *(undefined1 *)((int)param_1 + 0x33);
        piVar12[5] = iVar5 + 1;
        *(undefined1 *)(piVar12[2] + iVar5) = uVar4;
        iVar5 = piVar12[5];
        iVar14 = param_1[2];
        piVar12[5] = iVar5 + 1;
        *(char *)(piVar12[2] + iVar5) = (char)iVar14;
        iVar5 = piVar12[5];
        iVar14 = param_1[2];
        piVar12[5] = iVar5 + 1;
        *(char *)(piVar12[2] + iVar5) = (char)((uint)iVar14 >> 8);
        iVar5 = piVar12[5];
        uVar2 = *(undefined2 *)((int)param_1 + 10);
        piVar12[5] = iVar5 + 1;
        *(char *)(piVar12[2] + iVar5) = (char)uVar2;
        iVar5 = piVar12[5];
        uVar9 = (uint)*(byte *)((int)param_1 + 0xb);
      }
      else {
        iVar14 = piVar12[5];
        piVar12[5] = iVar14 + 1;
        *(char *)(piVar12[2] + iVar14) = (char)((uint)iVar5 >> 0x18);
        iVar14 = piVar12[5];
        piVar12[5] = iVar14 + 1;
        *(char *)(piVar12[2] + iVar14) = (char)((uint)iVar5 >> 0x10);
        iVar5 = piVar12[5];
        uVar9 = param_1[0xc];
        piVar12[5] = iVar5 + 1;
        *(char *)(piVar12[2] + iVar5) = (char)(uVar9 >> 8);
        iVar5 = piVar12[5];
      }
      piVar12[5] = iVar5 + 1;
      *(char *)(piVar12[2] + iVar5) = (char)uVar9;
      FUN_001b9e38(param_1);
      if (0 < piVar12[6]) {
        piVar12[6] = -piVar12[6];
      }
      return (uint)(piVar12[5] == 0);
    }
  }
  else {
    FUN_001b9e38(param_1);
    if (param_1[4] != 0) goto LAB_001b9c52;
LAB_001b9d7c:
    piVar12[10] = -1;
  }
  return 0;
}

// ===== deflateTune  @0x001b9df4  (28 bytes)
undefined4
deflateTune(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  if ((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x1c), iVar1 != 0)) {
    *(undefined4 *)(iVar1 + 0x8c) = param_2;
    *(undefined4 *)(iVar1 + 0x90) = param_4;
    *(undefined4 *)(iVar1 + 0x7c) = param_5;
    *(undefined4 *)(iVar1 + 0x80) = param_3;
    return 0;
  }
  return 0xfffffffe;
}

// ===== deflateBound  @0x001b9e10  (42 bytes)
int deflateBound(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  
  if ((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x1c), iVar1 != 0)) {
    bVar2 = *(int *)(iVar1 + 0x30) == 0xf;
    if (bVar2) {
      iVar1 = *(int *)(iVar1 + 0x50);
    }
    if (bVar2 && iVar1 == 0xf) {
      iVar1 = compressBound(param_2);
      return iVar1;
    }
  }
  return param_2 + (param_2 + 7U >> 3) + (param_2 + 0x3fU >> 6) + 0xb;
}

// ===== deflateCopy  @0x001b9e7e  (332 bytes)
undefined4 deflateCopy(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  
  uVar1 = 0xfffffffe;
  if (param_1 != (undefined4 *)0x0 && param_2 != (undefined4 *)0x0) {
    iVar8 = param_2[7];
    if (iVar8 == 0) {
      uVar1 = 0xfffffffe;
    }
    else {
      uVar1 = param_2[1];
      uVar5 = param_2[2];
      uVar6 = param_2[3];
      *param_1 = *param_2;
      param_1[1] = uVar1;
      param_1[2] = uVar5;
      param_1[3] = uVar6;
      uVar1 = param_2[5];
      uVar5 = param_2[6];
      uVar6 = param_2[7];
      uVar7 = param_2[8];
      param_1[4] = param_2[4];
      param_1[5] = uVar1;
      param_1[6] = uVar5;
      param_1[7] = uVar6;
      param_1[8] = uVar7;
      uVar1 = param_2[10];
      uVar5 = param_2[0xb];
      uVar6 = param_2[0xc];
      uVar7 = param_2[0xd];
      param_1[9] = param_2[9];
      param_1[10] = uVar1;
      param_1[0xb] = uVar5;
      param_1[0xc] = uVar6;
      param_1[0xd] = uVar7;
      piVar2 = (int *)(*(code *)param_1[8])(param_1[10],1,0x16c0);
      if (piVar2 != (int *)0x0) {
        param_1[7] = piVar2;
        __aeabi_memcpy4(piVar2,iVar8,0x16c0);
        *piVar2 = (int)param_1;
        iVar3 = (*(code *)param_1[8])(param_1[10],piVar2[0xb],2);
        piVar2[0xe] = iVar3;
        iVar3 = (*(code *)param_1[8])(param_1[10],piVar2[0xb],2);
        piVar2[0x10] = iVar3;
        iVar3 = (*(code *)param_1[8])(param_1[10],piVar2[0x13],2);
        piVar2[0x11] = iVar3;
        iVar3 = (*(code *)param_1[8])(param_1[10],piVar2[0x5a7],4);
        piVar2[2] = iVar3;
        if ((piVar2[0xe] != 0) && (iVar4 = piVar2[0x10], iVar4 != 0)) {
          if (iVar3 != 0) {
            iVar4 = piVar2[0x11];
          }
          if (iVar3 != 0 && iVar4 != 0) {
            __aeabi_memcpy(piVar2[0xe],*(undefined4 *)(iVar8 + 0x38),piVar2[0xb] << 1);
            __aeabi_memcpy(piVar2[0x10],*(undefined4 *)(iVar8 + 0x40),piVar2[0xb] << 1);
            __aeabi_memcpy(piVar2[0x11],*(undefined4 *)(iVar8 + 0x44),piVar2[0x13] << 1);
            __aeabi_memcpy(piVar2[2],*(undefined4 *)(iVar8 + 8),piVar2[3]);
            piVar2[4] = (*(int *)(iVar8 + 0x10) - *(int *)(iVar8 + 8)) + piVar2[2];
            piVar2[0x5a9] = (piVar2[0x5a7] & 0xfffffffeU) + iVar3;
            piVar2[0x5a6] = piVar2[0x5a7] * 3 + piVar2[2];
            piVar2[0x2c6] = (int)(piVar2 + 0x25);
            piVar2[0x2c9] = (int)(piVar2 + 0x262);
            piVar2[0x2cc] = (int)(piVar2 + 0x29f);
            return 0;
          }
        }
        deflateEnd(param_1);
      }
      uVar1 = 0xfffffffc;
    }
  }
  return uVar1;
}

// ===== get_crc_table  @0x001baa8c  (6 bytes)
undefined * get_crc_table(void)

{
  return &DAT_0025de2c;
}

// ===== crc32  @0x001baa98  (692 bytes)
uint crc32(uint param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  
  if (param_2 == 0) {
    param_1 = 0;
  }
  else {
    param_1 = ~param_1;
    if (param_3 != 0) {
      uVar5 = param_3 - 0x20;
      iVar7 = 0;
LAB_001baab4:
      puVar6 = (uint *)(param_2 + iVar7);
      if (((uint)puVar6 & 3) != 0) goto code_r0x001baabe;
      uVar3 = param_3 - iVar7;
      if (0x1f < uVar3) {
        iVar1 = 0;
        do {
          uVar3 = uVar3 - 0x20;
          param_1 = param_1 ^ *(uint *)((int)puVar6 + iVar1);
          uVar2 = *(uint *)(&DAT_0025e62c + ((param_1 & 0xffff) >> 8) * 4) ^
                  *(uint *)(&DAT_0025ea2c + (param_1 & 0xff) * 4) ^
                  *(uint *)(&DAT_0025e22c + ((param_1 & 0xffffff) >> 0x10) * 4) ^
                  *(uint *)(&DAT_0025de2c + (param_1 >> 0x18) * 4) ^
                  *(uint *)((int)puVar6 + iVar1 + 4);
          uVar2 = *(uint *)(&DAT_0025de2c + (uVar2 >> 0x18) * 4) ^
                  *(uint *)(&DAT_0025ea2c + (uVar2 & 0xff) * 4) ^
                  *(uint *)(&DAT_0025e62c + ((uVar2 & 0xffff) >> 8) * 4) ^
                  *(uint *)(&DAT_0025e22c + ((uVar2 & 0xffffff) >> 0x10) * 4) ^
                  *(uint *)((int)puVar6 + iVar1 + 8);
          uVar2 = *(uint *)(&DAT_0025de2c + (uVar2 >> 0x18) * 4) ^
                  *(uint *)(&DAT_0025ea2c + (uVar2 & 0xff) * 4) ^
                  *(uint *)(&DAT_0025e62c + ((uVar2 & 0xffff) >> 8) * 4) ^
                  *(uint *)(&DAT_0025e22c + ((uVar2 & 0xffffff) >> 0x10) * 4) ^
                  *(uint *)((int)puVar6 + iVar1 + 0xc);
          uVar2 = *(uint *)(&DAT_0025de2c + (uVar2 >> 0x18) * 4) ^
                  *(uint *)(&DAT_0025ea2c + (uVar2 & 0xff) * 4) ^
                  *(uint *)(&DAT_0025e62c + ((uVar2 & 0xffff) >> 8) * 4) ^
                  *(uint *)(&DAT_0025e22c + ((uVar2 & 0xffffff) >> 0x10) * 4) ^
                  *(uint *)((int)puVar6 + iVar1 + 0x10);
          uVar2 = *(uint *)(&DAT_0025de2c + (uVar2 >> 0x18) * 4) ^
                  *(uint *)(&DAT_0025ea2c + (uVar2 & 0xff) * 4) ^
                  *(uint *)(&DAT_0025e62c + ((uVar2 & 0xffff) >> 8) * 4) ^
                  *(uint *)(&DAT_0025e22c + ((uVar2 & 0xffffff) >> 0x10) * 4) ^
                  *(uint *)((int)puVar6 + iVar1 + 0x14);
          uVar2 = *(uint *)(&DAT_0025e22c + ((uVar2 & 0xffffff) >> 0x10) * 4) ^
                  *(uint *)(&DAT_0025ea2c + (uVar2 & 0xff) * 4) ^
                  *(uint *)(&DAT_0025e62c + ((uVar2 & 0xffff) >> 8) * 4) ^
                  *(uint *)(&DAT_0025de2c + (uVar2 >> 0x18) * 4) ^
                  *(uint *)((int)puVar6 + iVar1 + 0x18);
          uVar2 = *(uint *)(&DAT_0025e22c + ((uVar2 & 0xffffff) >> 0x10) * 4) ^
                  *(uint *)(&DAT_0025ea2c + (uVar2 & 0xff) * 4) ^
                  *(uint *)(&DAT_0025e62c + ((uVar2 & 0xffff) >> 8) * 4) ^
                  *(uint *)(&DAT_0025de2c + (uVar2 >> 0x18) * 4) ^
                  *(uint *)((int)puVar6 + iVar1 + 0x1c);
          param_1 = *(uint *)(&DAT_0025e22c + ((uVar2 & 0xffffff) >> 0x10) * 4) ^
                    *(uint *)(&DAT_0025ea2c + (uVar2 & 0xff) * 4) ^
                    *(uint *)(&DAT_0025e62c + ((uVar2 & 0xffff) >> 8) * 4) ^
                    *(uint *)(&DAT_0025de2c + (uVar2 >> 0x18) * 4);
          iVar1 = iVar1 + 0x20;
        } while (0x1f < uVar3);
        uVar3 = ((-0x20 - (uVar5 & 0xffffffe0)) + param_3) - iVar7;
        puVar6 = (uint *)(param_2 + (uVar5 & 0xffffffe0) + iVar7 + 0x20);
      }
      if (3 < uVar3) {
        uVar2 = uVar3 - 4;
        uVar5 = uVar2 >> 2;
        puVar4 = puVar6;
        do {
          uVar3 = uVar3 - 4;
          param_1 = param_1 ^ *puVar4;
          param_1 = *(uint *)(&DAT_0025ea2c + (param_1 & 0xff) * 4) ^
                    *(uint *)(&DAT_0025e62c + ((param_1 & 0xffff) >> 8) * 4) ^
                    *(uint *)(&DAT_0025e22c + ((param_1 & 0xffffff) >> 0x10) * 4) ^
                    *(uint *)(&DAT_0025de2c + (param_1 >> 0x18) * 4);
          puVar4 = puVar4 + 1;
        } while (3 < uVar3);
        uVar3 = uVar2 + uVar5 * -4;
        puVar6 = puVar6 + uVar5 + 1;
      }
      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
        param_1 = *(uint *)(&DAT_0025de2c + ((uint)(byte)*puVar6 ^ param_1 & 0xff) * 4) ^
                  param_1 >> 8;
        puVar6 = (uint *)((int)puVar6 + 1);
      }
    }
LAB_001bad44:
    param_1 = ~param_1;
  }
  return param_1;
code_r0x001baabe:
  iVar7 = iVar7 + 1;
  uVar5 = uVar5 - 1;
  param_1 = *(uint *)(&DAT_0025de2c + ((uint)(byte)*puVar6 ^ param_1 & 0xff) * 4) ^ param_1 >> 8;
  if (param_3 == iVar7) goto LAB_001bad44;
  goto LAB_001baab4;
}

// ===== crc32_combine  @0x001bad60  (386 bytes)
/* WARNING: Removing unreachable block (ram,0x001baede) */

void crc32_combine(uint param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint auStack_128 [33];
  uint local_a4 [32];
  undefined4 local_24;
  
  local_24 = __stack_chk_guard;
  if (param_3 != 0) {
    iVar5 = 1;
    auStack_128[1] = 0xedb88320;
    uVar2 = 1;
    do {
      auStack_128[iVar5 + 1] = uVar2;
      iVar5 = iVar5 + 1;
      uVar2 = uVar2 << 1;
    } while (iVar5 != 0x20);
    iVar5 = 0;
    do {
      uVar4 = 0;
      puVar3 = auStack_128;
      for (uVar2 = auStack_128[iVar5 + 1]; uVar2 != 0; uVar2 = uVar2 >> 1) {
        puVar3 = puVar3 + 1;
        if ((uVar2 & 1) != 0) {
          uVar4 = uVar4 ^ *puVar3;
        }
      }
      local_a4[iVar5] = uVar4;
      iVar5 = iVar5 + 1;
    } while (iVar5 != 0x20);
    iVar5 = 0;
    do {
      uVar2 = 0;
      if (local_a4[iVar5] != 0) {
        puVar3 = local_a4;
        uVar4 = local_a4[iVar5];
        do {
          if ((uVar4 & 1) != 0) {
            uVar2 = uVar2 ^ *puVar3;
          }
          puVar3 = puVar3 + 1;
          uVar1 = uVar4 >> 1;
          uVar4 = uVar4 >> 1;
        } while (uVar1 != 0);
      }
      auStack_128[iVar5 + 1] = uVar2;
      iVar5 = iVar5 + 1;
    } while (iVar5 != 0x20);
    do {
      iVar5 = 0;
      do {
        uVar4 = 0;
        puVar3 = auStack_128;
        for (uVar2 = auStack_128[iVar5 + 1]; uVar2 != 0; uVar2 = uVar2 >> 1) {
          puVar3 = puVar3 + 1;
          if ((uVar2 & 1) != 0) {
            uVar4 = uVar4 ^ *puVar3;
          }
        }
        local_a4[iVar5] = uVar4;
        iVar5 = iVar5 + 1;
      } while (iVar5 != 0x20);
      uVar2 = param_1;
      if (((param_3 & 1) != 0) && (uVar2 = 0, param_1 != 0)) {
        puVar3 = local_a4;
        do {
          if ((param_1 & 1) != 0) {
            uVar2 = uVar2 ^ *puVar3;
          }
          puVar3 = puVar3 + 1;
          uVar4 = param_1 >> 1;
          param_1 = param_1 >> 1;
        } while (uVar4 != 0);
      }
      param_1 = uVar2;
      if ((int)param_3 >> 1 == 0) {
        return;
      }
      iVar5 = 0;
      do {
        uVar2 = 0;
        if (local_a4[iVar5] != 0) {
          puVar3 = local_a4;
          uVar4 = local_a4[iVar5];
          do {
            if ((uVar4 & 1) != 0) {
              uVar2 = uVar2 ^ *puVar3;
            }
            puVar3 = puVar3 + 1;
            uVar1 = uVar4 >> 1;
            uVar4 = uVar4 >> 1;
          } while (uVar1 != 0);
        }
        auStack_128[iVar5 + 1] = uVar2;
        iVar5 = iVar5 + 1;
      } while (iVar5 != 0x20);
      if (((int)param_3 >> 1 & 1U) != 0) {
        uVar4 = 0;
        puVar3 = auStack_128;
        for (uVar2 = param_1; param_1 = uVar4, uVar2 != 0; uVar2 = uVar2 >> 1) {
          puVar3 = puVar3 + 1;
          if ((uVar2 & 1) != 0) {
            param_1 = param_1 ^ *puVar3;
          }
          uVar4 = param_1;
        }
      }
      param_3 = (int)param_3 >> 2;
    } while (param_3 != 0);
  }
  return;
}

// ===== inflateBackInit_  @0x001baeec  (138 bytes)
undefined4 inflateBackInit_(int param_1,uint param_2,int param_3,byte *param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  bool bVar5;
  
  if (param_4 == (byte *)0x0) {
    return 0xfffffffa;
  }
  uVar1 = 0xfffffffa;
  if (param_5 == 0x38) {
    uVar3 = (uint)*param_4;
    bVar5 = uVar3 == 0x31;
    if (bVar5) {
      uVar3 = param_2 & 0xfffffff8;
      uVar1 = 0xfffffffe;
    }
    if (((bVar5 && uVar3 == 8) && (param_1 != 0)) && (param_3 != 0)) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      pcVar4 = *(code **)(param_1 + 0x20);
      if (pcVar4 == (code *)0x0) {
        pcVar4 = zcalloc;
        *(code **)(param_1 + 0x20) = zcalloc;
        *(undefined4 *)(param_1 + 0x28) = 0;
      }
      if (*(int *)(param_1 + 0x24) == 0) {
        *(code **)(param_1 + 0x24) = zcfree;
      }
      iVar2 = (*pcVar4)(*(undefined4 *)(param_1 + 0x28),1,0x2530);
      if (iVar2 == 0) {
        return 0xfffffffc;
      }
      *(int *)(param_1 + 0x1c) = iVar2;
      *(undefined4 *)(iVar2 + 0x14) = 0x8000;
      uVar1 = 0;
      *(uint *)(iVar2 + 0x24) = param_2;
      *(int *)(iVar2 + 0x28) = 1 << (param_2 & 0xff);
      *(undefined4 *)(iVar2 + 0x2c) = 0;
      *(undefined4 *)(iVar2 + 0x30) = 0;
      *(int *)(iVar2 + 0x34) = param_3;
    }
  }
  return uVar1;
}

// ===== inflateBack  @0x001baf80  (2796 bytes)
void inflateBack(undefined4 *param_1,code *param_2,undefined4 param_3,code *param_4,
                undefined4 param_5)

{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  byte *pbVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int *unaff_r10;
  int *piVar18;
  uint uVar19;
  bool bVar20;
  uint local_38;
  undefined1 *local_34;
  byte *local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (param_1 != (undefined4 *)0x0) {
    unaff_r10 = (int *)param_1[7];
  }
  if (param_1 != (undefined4 *)0x0 && unaff_r10 != (int *)0x0) {
    uVar14 = 0;
    param_1[6] = 0;
    piVar18 = unaff_r10 + 0x1b;
    unaff_r10[0xb] = 0;
    uVar13 = 0;
    *unaff_r10 = 0xb;
    unaff_r10[1] = 0;
    uVar15 = 0;
    local_2c = (byte *)*param_1;
    if (local_2c != (byte *)0x0) {
      uVar14 = param_1[1];
    }
    local_38 = unaff_r10[10];
    piVar5 = unaff_r10 + 0xbc;
    piVar6 = unaff_r10 + 0x14c;
    iVar7 = 0xb;
    local_34 = (undefined1 *)unaff_r10[0xd];
LAB_001bb024:
    switch(iVar7) {
    case 0xb:
      if (unaff_r10[1] == 0) {
        if (uVar15 < 3) {
          if ((uVar14 == 0) && (uVar14 = (*param_2)(param_3,&local_2c), uVar14 == 0)) {
LAB_001bba0c:
            uVar14 = 0;
            uVar4 = 0xfffffffb;
            local_2c = (byte *)0x0;
            goto LAB_001bba5e;
          }
          uVar14 = uVar14 - 1;
          uVar13 = uVar13 + ((uint)*local_2c << (uVar15 & 0xff));
          uVar15 = uVar15 + 8;
          local_2c = local_2c + 1;
        }
        unaff_r10[1] = uVar13 & 1;
        uVar8 = (uVar13 & 7) >> 1;
        if (uVar8 == 1) {
          unaff_r10[0x13] = (int)&DAT_0025fe52;
          unaff_r10[0x14] = (int)&DAT_00260652;
          unaff_r10[0x15] = 9;
          unaff_r10[0x16] = 5;
          iVar7 = 0x12;
        }
        else if (uVar8 == 2) {
          iVar7 = 0xf;
        }
        else if (uVar8 == 3) {
          param_1[6] = "invalid block type";
          iVar7 = 0x1b;
        }
        else {
          iVar7 = 0xd;
        }
        uVar15 = uVar15 - 3;
        uVar13 = uVar13 >> 3;
        *unaff_r10 = iVar7;
        goto LAB_001bb8ac;
      }
      uVar8 = uVar15 & 7;
      iVar7 = 0x1a;
      *unaff_r10 = 0x1a;
      uVar15 = uVar15 - uVar8;
      uVar13 = uVar13 >> uVar8;
      goto LAB_001bb024;
    case 0xd:
      uVar13 = uVar13 >> (uVar15 & 7);
      for (uVar15 = uVar15 - (uVar15 & 7); uVar15 < 0x20; uVar15 = uVar15 + 8) {
        if ((uVar14 == 0) && (uVar14 = (*param_2)(param_3,&local_2c), uVar14 == 0))
        goto LAB_001bba0c;
        uVar14 = uVar14 - 1;
        uVar13 = uVar13 + ((uint)*local_2c << (uVar15 & 0xff));
        local_2c = local_2c + 1;
      }
      uVar8 = uVar13 & 0xffff;
      if (uVar8 != (uVar13 >> 0x10 ^ 0xffff)) {
        pcVar9 = "invalid stored block lengths";
        goto LAB_001bb7d4;
      }
      unaff_r10[0x10] = uVar8;
      while (uVar8 != 0) {
        if ((uVar14 == 0) && (uVar14 = (*param_2)(param_3,&local_2c), uVar14 == 0))
        goto LAB_001bba16;
        if (local_38 == 0) {
          local_34 = (undefined1 *)unaff_r10[0xd];
          local_38 = unaff_r10[10];
          unaff_r10[0xb] = local_38;
          iVar7 = (*param_4)(param_5,local_34,local_38);
          if (iVar7 != 0) goto LAB_001bba1a;
        }
        if (uVar14 < uVar8) {
          uVar8 = uVar14;
        }
        if (local_38 < uVar8) {
          uVar8 = local_38;
        }
        __aeabi_memcpy(local_34,local_2c,uVar8);
        uVar14 = uVar14 - uVar8;
        local_34 = local_34 + uVar8;
        local_38 = local_38 - uVar8;
        local_2c = local_2c + uVar8;
        uVar8 = unaff_r10[0x10] - uVar8;
        unaff_r10[0x10] = uVar8;
      }
      iVar7 = 0xb;
      uVar13 = 0;
      *unaff_r10 = 0xb;
      uVar15 = 0;
      goto LAB_001bb024;
    case 0xf:
      for (; uVar15 < 0xe; uVar15 = uVar15 + 8) {
        if ((uVar14 == 0) && (uVar14 = (*param_2)(param_3,&local_2c), uVar14 == 0))
        goto LAB_001bba0c;
        uVar14 = uVar14 - 1;
        uVar13 = uVar13 + ((uint)*local_2c << (uVar15 & 0xff));
        local_2c = local_2c + 1;
      }
      uVar15 = uVar15 - 0xe;
      uVar17 = (uVar13 & 0x1f) + 0x101;
      unaff_r10[0x18] = uVar17;
      bVar20 = 0x11d < uVar17;
      uVar16 = ((uVar13 & 0x3ff) >> 5) + 1;
      unaff_r10[0x19] = uVar16;
      uVar8 = uVar13 & 0x3fff;
      uVar13 = uVar13 >> 0xe;
      uVar8 = (uVar8 >> 10) + 4;
      unaff_r10[0x17] = uVar8;
      if (uVar17 < 0x11f) {
        bVar20 = 0x1e < uVar16;
      }
      if (!bVar20) {
        unaff_r10[0x1a] = 0;
        uVar16 = 0;
        uVar17 = uVar13;
        do {
          uVar13 = uVar16;
          if (uVar15 < 3) {
            if ((uVar14 == 0) && (uVar14 = (*param_2)(param_3,&local_2c), uVar14 == 0))
            goto LAB_001bba0c;
            uVar14 = uVar14 - 1;
            uVar8 = unaff_r10[0x17];
            uVar13 = unaff_r10[0x1a];
            uVar17 = uVar17 + ((uint)*local_2c << (uVar15 & 0xff));
            uVar15 = uVar15 + 8;
            local_2c = local_2c + 1;
          }
          uVar16 = uVar13 + 1;
          uVar15 = uVar15 - 3;
          unaff_r10[0x1a] = uVar16;
          uVar2 = (ushort)uVar17;
          uVar17 = uVar17 >> 3;
          *(ushort *)((int)unaff_r10 + (uint)*(ushort *)(&DAT_0025fe2c + uVar13 * 2) * 2 + 0x70) =
               uVar2 & 7;
        } while (uVar16 < uVar8);
        if (uVar16 < 0x13) {
          do {
            iVar7 = uVar13 * 2;
            iVar12 = uVar13 + 2;
            uVar13 = uVar13 + 1;
            unaff_r10[0x1a] = iVar12;
            *(undefined2 *)((int)unaff_r10 + (uint)*(ushort *)(&DAT_0025fe2e + iVar7) * 2 + 0x70) =
                 0;
          } while (uVar13 != 0x12);
        }
        unaff_r10[0x1b] = (int)piVar6;
        unaff_r10[0x13] = (int)piVar6;
        unaff_r10[0x15] = 7;
        iVar7 = inflate_table(0,unaff_r10 + 0x1c,0x13,piVar18,unaff_r10 + 0x15,piVar5);
        uVar13 = uVar17;
        if (iVar7 == 0) goto LAB_001bb2b4;
        pcVar9 = "invalid code lengths set";
        goto LAB_001bb2a4;
      }
      param_1[6] = "too many length or distance symbols";
      iVar7 = 0x1b;
      *unaff_r10 = 0x1b;
      goto LAB_001bb024;
    case 0x12:
      goto switchD_001bb02e_caseD_12;
    default:
      if (iVar7 == 0x1a) {
        if (local_38 < (uint)unaff_r10[10]) {
          iVar7 = (*param_4)(param_5,unaff_r10[0xd],unaff_r10[10] - local_38);
          uVar4 = 0xfffffffb;
          if (iVar7 == 0) {
            uVar4 = 1;
          }
        }
        else {
          uVar4 = 1;
        }
        goto LAB_001bba5e;
      }
      if (iVar7 == 0x1b) {
        uVar4 = 0xfffffffd;
        goto LAB_001bba5e;
      }
    case 0xc:
    case 0xe:
    case 0x10:
    case 0x11:
      uVar4 = 0xfffffffe;
LAB_001bba5e:
      *param_1 = local_2c;
      param_1[1] = uVar14;
    }
  }
  else {
    uVar4 = 0xfffffffe;
  }
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar4);
LAB_001bb2b4:
  unaff_r10[0x1a] = 0;
  iVar12 = unaff_r10[0x18];
  if (unaff_r10[0x19] + iVar12 != 0) {
    do {
      uVar13 = unaff_r10[0x15];
      iVar7 = unaff_r10[0x13];
      iVar12 = iVar7 + ((1 << (uVar13 & 0xff)) - 1U & uVar17) * 4;
      bVar1 = *(byte *)(iVar12 + 1);
      for (; uVar8 = (uint)bVar1, uVar15 < uVar8; uVar15 = uVar15 + 8) {
        if (uVar14 == 0) {
          uVar14 = (*param_2)(param_3,&local_2c);
          if (uVar14 == 0) goto LAB_001bba0c;
          iVar7 = unaff_r10[0x13];
          uVar13 = unaff_r10[0x15];
        }
        uVar14 = uVar14 - 1;
        uVar17 = uVar17 + ((uint)*local_2c << (uVar15 & 0xff));
        iVar12 = iVar7 + ((1 << (uVar13 & 0xff)) - 1U & uVar17) * 4;
        bVar1 = *(byte *)(iVar12 + 1);
        local_2c = local_2c + 1;
      }
      uVar2 = *(ushort *)(iVar12 + 2);
      if (uVar2 < 0x10) {
        for (; uVar15 < uVar8; uVar15 = uVar15 + 8) {
          if ((uVar14 == 0) && (uVar14 = (*param_2)(param_3,&local_2c), uVar14 == 0))
          goto LAB_001bba0c;
          uVar14 = uVar14 - 1;
          uVar17 = uVar17 + ((uint)*local_2c << (uVar15 & 0xff));
          local_2c = local_2c + 1;
        }
        iVar7 = unaff_r10[0x1a];
        uVar15 = uVar15 - uVar8;
        uVar17 = uVar17 >> uVar8;
        unaff_r10[0x1a] = iVar7 + 1;
        *(ushort *)((int)unaff_r10 + iVar7 * 2 + 0x70) = uVar2;
      }
      else {
        if (uVar2 == 0x10) {
          for (; uVar15 < uVar8 + 2; uVar15 = uVar15 + 8) {
            if ((uVar14 == 0) && (uVar14 = (*param_2)(param_3,&local_2c), uVar14 == 0))
            goto LAB_001bba0c;
            uVar14 = uVar14 - 1;
            uVar17 = uVar17 + ((uint)*local_2c << (uVar15 & 0xff));
            local_2c = local_2c + 1;
          }
          uVar15 = uVar15 - uVar8;
          uVar13 = uVar17 >> uVar8;
          if (unaff_r10[0x1a] == 0) {
            param_1[6] = "invalid bit length repeat";
            iVar7 = 0x1b;
            *unaff_r10 = 0x1b;
            goto LAB_001bb024;
          }
          uVar17 = uVar13 >> 2;
          uVar15 = uVar15 - 2;
          uVar3 = *(undefined2 *)((int)unaff_r10 + unaff_r10[0x1a] * 2 + 0x6e);
          iVar7 = (uVar13 & 3) + 3;
        }
        else {
          if (uVar2 == 0x11) {
            for (; uVar15 < uVar8 + 3; uVar15 = uVar15 + 8) {
              if ((uVar14 == 0) && (uVar14 = (*param_2)(param_3,&local_2c), uVar14 == 0))
              goto LAB_001bba0c;
              uVar14 = uVar14 - 1;
              uVar17 = uVar17 + ((uint)*local_2c << (uVar15 & 0xff));
              local_2c = local_2c + 1;
            }
            uVar15 = uVar15 + (-3 - uVar8);
            uVar13 = uVar17 >> uVar8;
            uVar17 = uVar13 >> 3;
            iVar7 = (uVar13 & 7) + 3;
          }
          else {
            for (; uVar15 < uVar8 + 7; uVar15 = uVar15 + 8) {
              if ((uVar14 == 0) && (uVar14 = (*param_2)(param_3,&local_2c), uVar14 == 0))
              goto LAB_001bba0c;
              uVar14 = uVar14 - 1;
              uVar17 = uVar17 + ((uint)*local_2c << (uVar15 & 0xff));
              local_2c = local_2c + 1;
            }
            uVar15 = uVar15 + (-7 - uVar8);
            uVar13 = uVar17 >> uVar8;
            uVar17 = uVar13 >> 7;
            iVar7 = (uVar13 & 0x7f) + 0xb;
          }
          uVar3 = 0;
        }
        iVar12 = unaff_r10[0x1a];
        if ((uint)(unaff_r10[0x19] + unaff_r10[0x18]) < (uint)(iVar12 + iVar7)) {
          pcVar9 = "invalid bit length repeat";
          uVar13 = uVar17;
          goto LAB_001bb2a4;
        }
        unaff_r10[0x1a] = iVar12 + 1;
        *(undefined2 *)((int)unaff_r10 + iVar12 * 2 + 0x70) = uVar3;
        if (iVar7 != 1) {
          iVar7 = 1 - iVar7;
          do {
            iVar12 = unaff_r10[0x1a];
            iVar7 = iVar7 + 1;
            unaff_r10[0x1a] = iVar12 + 1;
            *(undefined2 *)((int)unaff_r10 + iVar12 * 2 + 0x70) = uVar3;
          } while (iVar7 != 0);
        }
      }
      iVar12 = unaff_r10[0x18];
      uVar13 = uVar17;
    } while ((uint)unaff_r10[0x1a] < (uint)(unaff_r10[0x19] + iVar12));
  }
  iVar7 = 0x1b;
  if (*unaff_r10 == 0x1b) goto LAB_001bb024;
  unaff_r10[0x1b] = (int)piVar6;
  unaff_r10[0x13] = (int)piVar6;
  unaff_r10[0x15] = 9;
  iVar7 = inflate_table(1,unaff_r10 + 0x1c,iVar12,piVar18,unaff_r10 + 0x15,piVar5);
  if (iVar7 == 0) {
    unaff_r10[0x14] = unaff_r10[0x1b];
    unaff_r10[0x16] = 6;
    iVar7 = inflate_table(2,(int)unaff_r10 + unaff_r10[0x18] * 2 + 0x70,unaff_r10[0x19],piVar18,
                          unaff_r10 + 0x16,piVar5);
    if (iVar7 == 0) {
      *unaff_r10 = 0x12;
switchD_001bb02e_caseD_12:
      bVar20 = local_38 == 0x102;
      if (0x101 < local_38) {
        bVar20 = uVar14 == 5;
      }
      if ((0x101 >= local_38 || uVar14 < 5) || bVar20) {
        uVar8 = unaff_r10[0x15];
        iVar7 = unaff_r10[0x13];
        pbVar10 = (byte *)(iVar7 + ((1 << (uVar8 & 0xff)) - 1U & uVar13) * 4);
        bVar1 = pbVar10[1];
        for (; uVar16 = (uint)bVar1, uVar15 < uVar16; uVar15 = uVar15 + 8) {
          if (uVar14 == 0) {
            uVar14 = (*param_2)(param_3,&local_2c);
            if (uVar14 == 0) goto LAB_001bba0c;
            iVar7 = unaff_r10[0x13];
            uVar8 = unaff_r10[0x15];
          }
          uVar14 = uVar14 - 1;
          uVar13 = uVar13 + ((uint)*local_2c << (uVar15 & 0xff));
          pbVar10 = (byte *)(iVar7 + ((1 << (uVar8 & 0xff)) - 1U & uVar13) * 4);
          bVar1 = pbVar10[1];
          local_2c = local_2c + 1;
        }
        uVar8 = (uint)*pbVar10;
        uVar17 = (uint)*(ushort *)(pbVar10 + 2);
        if ((uVar8 != 0) && ((*pbVar10 & 0xf0) == 0)) {
          uVar8 = (1 << (uVar16 + uVar8 & 0xff)) - 1;
          iVar12 = ((uVar13 & uVar8) >> uVar16) + uVar17;
          bVar1 = *(byte *)(iVar7 + iVar12 * 4 + 1);
          for (; uVar15 < bVar1 + uVar16; uVar15 = uVar15 + 8) {
            if (uVar14 == 0) {
              uVar14 = (*param_2)(param_3,&local_2c);
              if (uVar14 == 0) goto LAB_001bba16;
              iVar7 = unaff_r10[0x13];
            }
            uVar14 = uVar14 - 1;
            uVar13 = uVar13 + ((uint)*local_2c << (uVar15 & 0xff));
            iVar12 = ((uVar13 & uVar8) >> uVar16) + uVar17;
            bVar1 = *(byte *)(iVar7 + iVar12 * 4 + 1);
            local_2c = local_2c + 1;
          }
          uVar8 = (uint)*(byte *)(iVar7 + iVar12 * 4);
          uVar17 = (uint)*(ushort *)(iVar7 + iVar12 * 4 + 2);
          uVar15 = uVar15 - uVar16;
          uVar13 = uVar13 >> uVar16;
          uVar16 = (uint)bVar1;
        }
        unaff_r10[0x10] = uVar17;
        uVar15 = uVar15 - uVar16;
        uVar13 = uVar13 >> uVar16;
        if (uVar8 == 0) {
          if (local_38 == 0) {
            local_34 = (undefined1 *)unaff_r10[0xd];
            local_38 = unaff_r10[10];
            unaff_r10[0xb] = local_38;
            iVar7 = (*param_4)(param_5);
            if (iVar7 != 0) goto LAB_001bba1a;
            uVar17 = unaff_r10[0x10];
          }
          local_38 = local_38 - 1;
          *local_34 = (char)uVar17;
          iVar7 = 0x12;
          *unaff_r10 = 0x12;
          local_34 = local_34 + 1;
          goto LAB_001bb024;
        }
        if ((uVar8 & 0x20) == 0) {
          if ((uVar8 & 0x40) == 0) {
            uVar8 = uVar8 & 0xf;
            unaff_r10[0x12] = uVar8;
            if (uVar8 != 0) {
              if (uVar15 < uVar8) {
                do {
                  if (uVar14 == 0) {
                    uVar14 = (*param_2)(param_3,&local_2c);
                    if (uVar14 == 0) goto LAB_001bba0c;
                    uVar8 = unaff_r10[0x12];
                  }
                  uVar14 = uVar14 - 1;
                  pbVar10 = local_2c + 1;
                  uVar16 = uVar15 & 0xff;
                  uVar15 = uVar15 + 8;
                  uVar13 = uVar13 + ((uint)*local_2c << uVar16);
                  local_2c = pbVar10;
                } while (uVar15 < uVar8);
                uVar17 = unaff_r10[0x10];
              }
              uVar15 = uVar15 - uVar8;
              uVar16 = (1 << (uVar8 & 0xff)) - 1U & uVar13;
              uVar13 = uVar13 >> (uVar8 & 0xff);
              unaff_r10[0x10] = uVar16 + uVar17;
            }
            uVar8 = unaff_r10[0x16];
            iVar7 = unaff_r10[0x14];
            pbVar10 = (byte *)(iVar7 + ((1 << (uVar8 & 0xff)) - 1U & uVar13) * 4);
            bVar1 = pbVar10[1];
            for (; uVar16 = (uint)bVar1, uVar15 < uVar16; uVar15 = uVar15 + 8) {
              if (uVar14 == 0) {
                uVar14 = (*param_2)(param_3,&local_2c);
                if (uVar14 == 0) goto LAB_001bba0c;
                iVar7 = unaff_r10[0x14];
                uVar8 = unaff_r10[0x16];
              }
              uVar14 = uVar14 - 1;
              uVar13 = uVar13 + ((uint)*local_2c << (uVar15 & 0xff));
              pbVar10 = (byte *)(iVar7 + ((1 << (uVar8 & 0xff)) - 1U & uVar13) * 4);
              bVar1 = pbVar10[1];
              local_2c = local_2c + 1;
            }
            uVar8 = (uint)*pbVar10;
            uVar17 = (uint)*(ushort *)(pbVar10 + 2);
            if ((*pbVar10 & 0xf0) == 0) {
              uVar8 = (1 << (uVar16 + uVar8 & 0xff)) - 1;
              iVar12 = ((uVar13 & uVar8) >> uVar16) + uVar17;
              bVar1 = *(byte *)(iVar7 + iVar12 * 4 + 1);
              for (; uVar15 < bVar1 + uVar16; uVar15 = uVar15 + 8) {
                if (uVar14 == 0) {
                  uVar14 = (*param_2)(param_3,&local_2c);
                  if (uVar14 == 0) goto LAB_001bba16;
                  iVar7 = unaff_r10[0x14];
                }
                uVar14 = uVar14 - 1;
                uVar13 = uVar13 + ((uint)*local_2c << (uVar15 & 0xff));
                iVar12 = ((uVar13 & uVar8) >> uVar16) + uVar17;
                bVar1 = *(byte *)(iVar7 + iVar12 * 4 + 1);
                local_2c = local_2c + 1;
              }
              uVar8 = (uint)*(byte *)(iVar7 + iVar12 * 4);
              uVar17 = (uint)*(ushort *)(iVar7 + iVar12 * 4 + 2);
              uVar15 = uVar15 - uVar16;
              uVar13 = uVar13 >> uVar16;
              uVar16 = (uint)bVar1;
            }
            uVar15 = uVar15 - uVar16;
            uVar13 = uVar13 >> uVar16;
            if ((uVar8 & 0x40) == 0) {
              uVar8 = uVar8 & 0xf;
              unaff_r10[0x11] = uVar17;
              unaff_r10[0x12] = uVar8;
              if (uVar8 != 0) {
                if (uVar15 < uVar8) {
                  do {
                    if (uVar14 == 0) {
                      uVar14 = (*param_2)(param_3,&local_2c);
                      if (uVar14 == 0) goto LAB_001bba0c;
                      uVar8 = unaff_r10[0x12];
                    }
                    uVar14 = uVar14 - 1;
                    pbVar10 = local_2c + 1;
                    uVar16 = uVar15 & 0xff;
                    uVar15 = uVar15 + 8;
                    uVar13 = uVar13 + ((uint)*local_2c << uVar16);
                    local_2c = pbVar10;
                  } while (uVar15 < uVar8);
                  uVar17 = unaff_r10[0x11];
                }
                uVar15 = uVar15 - uVar8;
                uVar16 = (1 << (uVar8 & 0xff)) - 1U & uVar13;
                uVar13 = uVar13 >> (uVar8 & 0xff);
                uVar17 = uVar17 + uVar16;
                unaff_r10[0x11] = uVar17;
              }
              uVar8 = unaff_r10[10];
              if ((uint)unaff_r10[0xb] < uVar8) {
                uVar8 = uVar8 - local_38;
              }
              if (uVar17 <= uVar8) {
                do {
                  if (local_38 == 0) {
                    local_34 = (undefined1 *)unaff_r10[0xd];
                    local_38 = unaff_r10[10];
                    unaff_r10[0xb] = local_38;
                    iVar7 = (*param_4)(param_5,local_34,local_38);
                    if (iVar7 != 0) goto LAB_001bba1a;
                  }
                  uVar17 = unaff_r10[0x10];
                  uVar8 = unaff_r10[10] - unaff_r10[0x11];
                  uVar16 = 0;
                  if (uVar8 < local_38) {
                    uVar16 = uVar8;
                  }
                  uVar19 = local_38 - uVar16;
                  if (uVar17 < local_38 - uVar16) {
                    uVar19 = uVar17;
                  }
                  unaff_r10[0x10] = uVar17 - uVar19;
                  uVar16 = (uVar16 - 1) - local_38;
                  if (local_38 <= uVar8) {
                    uVar8 = -unaff_r10[0x11];
                  }
                  uVar11 = ~uVar17;
                  if (~uVar17 < uVar16) {
                    uVar11 = uVar16;
                  }
                  iVar7 = uVar11 + 1;
                  do {
                    iVar7 = iVar7 + 1;
                    *local_34 = local_34[uVar8];
                    local_34 = local_34 + 1;
                  } while (iVar7 != 0);
                  local_38 = local_38 - uVar19;
                } while (unaff_r10[0x10] != 0);
                goto LAB_001bb8ac;
              }
              pcVar9 = "invalid distance too far back";
            }
            else {
              pcVar9 = "invalid distance code";
            }
            param_1[6] = pcVar9;
            iVar7 = 0x1b;
            *unaff_r10 = 0x1b;
            goto LAB_001bb024;
          }
          pcVar9 = "invalid literal/length code";
LAB_001bb7d4:
          param_1[6] = pcVar9;
          iVar7 = 0x1b;
        }
        else {
          iVar7 = 0xb;
        }
        *unaff_r10 = iVar7;
        goto LAB_001bb024;
      }
      param_1[3] = local_34;
      param_1[4] = local_38;
      *param_1 = local_2c;
      param_1[1] = uVar14;
      unaff_r10[0xe] = uVar13;
      unaff_r10[0xf] = uVar15;
      if ((uint)unaff_r10[0xb] < (uint)unaff_r10[10]) {
        unaff_r10[0xb] = unaff_r10[10] - local_38;
      }
      inflate_fast(param_1);
      local_34 = (undefined1 *)param_1[3];
      local_2c = (byte *)*param_1;
      local_38 = param_1[4];
      uVar13 = unaff_r10[0xe];
      uVar15 = unaff_r10[0xf];
      uVar14 = param_1[1];
LAB_001bb8ac:
      iVar7 = *unaff_r10;
      goto LAB_001bb024;
    }
    pcVar9 = "invalid distances set";
  }
  else {
    pcVar9 = "invalid literal/lengths set";
  }
LAB_001bb2a4:
  param_1[6] = pcVar9;
  iVar7 = 0x1b;
  *unaff_r10 = 0x1b;
  goto LAB_001bb024;
LAB_001bba16:
  uVar14 = 0;
  local_2c = (byte *)0x0;
LAB_001bba1a:
  uVar4 = 0xfffffffb;
  goto LAB_001bba5e;
}

// ===== inflateBackEnd  @0x001bbac0  (32 bytes)
undefined4 inflateBackEnd(int param_1)

{
  if (((param_1 != 0) && (*(int *)(param_1 + 0x1c) != 0)) &&
     (*(code **)(param_1 + 0x24) != (code *)0x0)) {
    (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28));
    *(undefined4 *)(param_1 + 0x1c) = 0;
    return 0;
  }
  return 0xfffffffe;
}

// ===== zlibVersion  @0x001bbae0  (6 bytes)
char * zlibVersion(void)

{
  return "1.2.3";
}

// ===== zlibCompileFlags  @0x001bbaec  (4 bytes)
undefined4 zlibCompileFlags(void)

{
  return 0x55;
}

// ===== zError  @0x001bbaf0  (16 bytes)
undefined4 zError(int param_1)

{
  return *(undefined4 *)(z_errmsg + (2 - param_1) * 4);
}

// ===== zcalloc  @0x001bbb04  (10 bytes)
void zcalloc(undefined4 param_1,int param_2,int param_3)

{
  malloc(param_3 * param_2);
  return;
}

// ===== zcfree  @0x001bbb0c  (6 bytes)
void zcfree(undefined4 param_1,void *param_2)

{
  free(param_2);
  return;
}

// ===== inflate_table  @0x001bbb14  (906 bytes)
void inflate_table(int param_1,ushort *param_2,int param_3,int *param_4,uint *param_5,
                  undefined *param_6)

{
  short sVar1;
  byte bVar2;
  ushort *puVar3;
  undefined1 *puVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  undefined1 uVar20;
  uint uVar21;
  uint local_9c;
  undefined *local_94;
  undefined *local_90;
  uint local_84;
  ushort auStack_68 [16];
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  local_48 = 0;
  uStack_44 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uStack_40 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uStack_3c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_38 = 0;
  uStack_34 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uStack_30 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uStack_2c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  puVar3 = param_2;
  for (iVar6 = param_3; iVar6 != 0; iVar6 = iVar6 + -1) {
    *(short *)((int)&local_48 + (uint)*puVar3 * 2) =
         *(short *)((int)&local_48 + (uint)*puVar3 * 2) + 1;
    puVar3 = puVar3 + 1;
  }
  uVar18 = 0xf;
  do {
    if (*(short *)((int)&local_48 + uVar18 * 2) != 0) {
      uVar15 = *param_5;
      if (uVar18 < *param_5) {
        uVar15 = uVar18;
      }
      uVar13 = 1;
      goto LAB_001bbba0;
    }
    uVar18 = uVar18 - 1;
  } while (uVar18 != 0);
  puVar4 = (undefined1 *)*param_4;
  *param_4 = (int)(puVar4 + 4);
  *puVar4 = 0x40;
  puVar4[1] = 1;
  *(undefined2 *)(puVar4 + 2) = 0;
  puVar4 = (undefined1 *)*param_4;
  *param_4 = (int)(puVar4 + 4);
  *puVar4 = 0x40;
  puVar4[1] = 1;
  *(undefined2 *)(puVar4 + 2) = 0;
  *param_5 = 1;
  goto LAB_001bbe84;
joined_r0x001bbe0c:
  if (uVar21 == 0) goto LAB_001bbe70;
  if ((uVar14 != 0) && ((uVar7 & uVar21) != local_84)) {
    uVar14 = 0;
    iVar11 = *param_4;
    uVar10 = uVar15;
    uVar18 = uVar15;
  }
  uVar13 = uVar21 >> (uVar14 & 0xff);
  *(undefined1 *)(iVar11 + uVar13 * 4) = 0x40;
  iVar6 = iVar11 + uVar13 * 4;
  *(char *)(iVar6 + 1) = (char)uVar10;
  *(undefined2 *)(iVar6 + 2) = 0;
  uVar13 = 1 << (uVar18 - 1 & 0xff);
  do {
    uVar19 = uVar13;
    uVar13 = uVar19 >> 1;
  } while ((uVar19 & uVar21) != 0);
  if (uVar19 == 0) goto LAB_001bbe70;
  uVar21 = (uVar19 - 1 & uVar21) + uVar19;
  goto joined_r0x001bbe0c;
LAB_001bbe70:
  *param_4 = *param_4 + local_9c * 4;
  *param_5 = uVar15;
  goto LAB_001bbe84;
  while (uVar13 = uVar13 + 1, uVar13 < 0x10) {
LAB_001bbba0:
    if (*(short *)((int)&local_48 + uVar13 * 2) != 0) break;
  }
  if (uVar15 < uVar13) {
    uVar15 = uVar13;
  }
  iVar6 = 1;
  uVar14 = 1;
  do {
    iVar6 = iVar6 * 2 - (uint)*(ushort *)((int)&local_48 + uVar14 * 2);
    if (iVar6 < 0) goto LAB_001bbe84;
    uVar14 = uVar14 + 1;
  } while (uVar14 < 0x10);
  if ((iVar6 < 1) || ((param_1 != 0 && (uVar18 == 1)))) {
    iVar6 = 0;
    uVar5 = 0;
    auStack_68[1] = 0;
    do {
      uVar5 = *(short *)(((uint)&local_48 | 2) + iVar6 * 2) + uVar5;
      auStack_68[iVar6 + 2] = uVar5;
      iVar6 = iVar6 + 1;
    } while (iVar6 != 0xe);
    if (param_3 != 0) {
      iVar6 = 0;
      do {
        uVar14 = (uint)param_2[iVar6];
        if (uVar14 != 0) {
          uVar5 = auStack_68[uVar14];
          auStack_68[uVar14] = uVar5 + 1;
          *(short *)(param_6 + (uint)uVar5 * 2) = (short)iVar6;
        }
        iVar6 = iVar6 + 1;
      } while (param_3 != iVar6);
    }
    if (param_1 == 0) {
      iVar6 = 0x13;
      bVar2 = 0;
      local_94 = param_6;
      local_90 = param_6;
    }
    else if (param_1 == 1) {
      if (10 < uVar15) goto LAB_001bbe84;
      iVar6 = 0x100;
      local_90 = &DAT_00260500;
      local_94 = &DAT_0026053e;
      bVar2 = 1;
    }
    else {
      iVar6 = -1;
      local_90 = &DAT_0026077e;
      local_94 = &DAT_002607be;
      bVar2 = 0;
    }
    uVar14 = 0;
    local_9c = 1 << (uVar15 & 0xff);
    uVar7 = local_9c - 1;
    local_84 = 0xffffffff;
    iVar8 = 0;
    iVar11 = *param_4;
    uVar21 = 0;
    uVar10 = uVar15;
    do {
      iVar9 = 1 << (uVar10 & 0xff);
      do {
        uVar5 = *(ushort *)(param_6 + iVar8 * 2);
        uVar19 = (uint)uVar5;
        uVar10 = uVar13 - uVar14;
        if ((int)uVar19 < iVar6) {
          uVar20 = 0;
        }
        else if (iVar6 < (int)uVar19) {
          uVar5 = *(ushort *)(local_90 + uVar19 * 2);
          uVar20 = local_94[uVar19 * 2];
        }
        else {
          uVar20 = 0x60;
          uVar5 = 0;
        }
        iVar16 = 1 << (uVar10 & 0xff);
        puVar4 = (undefined1 *)(iVar11 + 1 + (((uVar21 >> (uVar14 & 0xff)) + iVar9) - iVar16) * 4);
        iVar12 = -iVar9;
        do {
          puVar4[-1] = uVar20;
          iVar12 = iVar12 + iVar16;
          *puVar4 = (char)uVar10;
          *(ushort *)(puVar4 + 1) = uVar5;
          puVar4 = puVar4 + iVar16 * -4;
        } while (iVar12 != 0);
        uVar19 = 1 << (uVar13 - 1 & 0xff);
        do {
          uVar17 = uVar19;
          uVar19 = uVar17 >> 1;
        } while ((uVar17 & uVar21) != 0);
        if (uVar17 == 0) {
          uVar21 = 0;
        }
        else {
          uVar21 = (uVar17 - 1 & uVar21) + uVar17;
        }
        iVar8 = iVar8 + 1;
        sVar1 = *(short *)((int)&local_48 + uVar13 * 2);
        *(short *)((int)&local_48 + uVar13 * 2) = sVar1 + -1;
        if (sVar1 == 1) {
          if (uVar13 == uVar18) goto joined_r0x001bbe0c;
          uVar13 = (uint)param_2[*(ushort *)(param_6 + iVar8 * 2)];
        }
      } while ((uVar13 <= uVar15) || (uVar19 = uVar7 & uVar21, uVar19 == local_84));
      if (uVar14 == 0) {
        uVar14 = uVar15;
      }
      uVar10 = uVar13 - uVar14;
      if (uVar13 < uVar18) {
        iVar12 = 1 << (uVar10 & 0xff);
        uVar10 = uVar13;
        do {
          iVar12 = iVar12 - (uint)*(ushort *)((int)&local_48 + uVar10 * 2);
          if (iVar12 < 1) break;
          uVar10 = uVar10 + 1;
          iVar12 = iVar12 * 2;
        } while (uVar10 < uVar18);
        uVar10 = uVar10 - uVar14;
      }
      local_9c = local_9c + (1 << (uVar10 & 0xff));
      if ((bool)(bVar2 & 0x5a < local_9c >> 4)) break;
      iVar12 = *param_4;
      iVar11 = iVar11 + iVar9 * 4;
      iVar9 = iVar12 + uVar19 * 4;
      *(char *)(iVar12 + uVar19 * 4) = (char)uVar10;
      *(char *)(iVar9 + 1) = (char)uVar15;
      *(short *)(iVar9 + 2) = (short)((uint)(iVar11 - iVar12) >> 2);
      local_84 = uVar19;
    } while( true );
  }
LAB_001bbe84:
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

// ===== uncompress  @0x001bbeb8  (134 bytes)
void uncompress(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_2c;
  undefined4 uStack_28;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_3c = *param_2;
  local_2c = 0;
  uStack_28 = 0;
  local_4c = param_3;
  local_48 = param_4;
  local_40 = param_1;
  iVar1 = inflateInit_(&local_4c,"1.2.3",0x38);
  if (iVar1 == 0) {
    iVar1 = inflate(&local_4c,4);
    if (iVar1 == 1) {
      *param_2 = local_38;
      inflateEnd(&local_4c);
    }
    else {
      inflateEnd(&local_4c);
    }
  }
  if (__stack_chk_guard - local_14 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_14);
}

// ===== _tr_init  @0x001bbf4c  (76 bytes)
void _tr_init(int param_1)

{
  *(int *)(param_1 + 0xb18) = param_1 + 0x94;
  *(undefined **)(param_1 + 0xb20) = &DAT_0026b8f8;
  *(int *)(param_1 + 0xb24) = param_1 + 0x988;
  *(undefined **)(param_1 + 0xb38) = &DAT_0026b920;
  *(undefined **)(param_1 + 0xb2c) = &DAT_0026b90c;
  *(int *)(param_1 + 0xb30) = param_1 + 0xa7c;
  *(undefined2 *)(param_1 + 0x16b8) = 0;
  *(undefined4 *)(param_1 + 0x16bc) = 0;
  *(undefined4 *)(param_1 + 0x16b4) = 8;
  FUN_001bbfa4();
  return;
}

// ===== _tr_stored_block  @0x001bbffe  (256 bytes)
void _tr_stored_block(int param_1,undefined1 *param_2,uint param_3,uint param_4)

{
  int *piVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = *(uint *)(param_1 + 0x16bc);
  uVar3 = (uint)*(ushort *)(param_1 + 0x16b8) | param_4 << (uVar4 & 0xff);
  *(short *)(param_1 + 0x16b8) = (short)uVar3;
  if ((int)uVar4 < 0xe) {
    iVar5 = uVar4 + 3;
  }
  else {
    piVar1 = (int *)(param_1 + 0x14);
    iVar5 = *piVar1;
    *piVar1 = iVar5 + 1;
    *(char *)(*(int *)(param_1 + 8) + iVar5) = (char)uVar3;
    iVar5 = *piVar1;
    *piVar1 = iVar5 + 1;
    *(undefined1 *)(*(int *)(param_1 + 8) + iVar5) = *(undefined1 *)(param_1 + 0x16b9);
    iVar5 = *(int *)(param_1 + 0x16bc);
    *(short *)(param_1 + 0x16b8) = (short)((param_4 & 0xffff) >> (0x10U - iVar5 & 0xff));
    iVar5 = iVar5 + -0xd;
  }
  *(int *)(param_1 + 0x16bc) = iVar5;
  FUN_001bccb0(param_1);
  *(undefined4 *)(param_1 + 0x16b4) = 8;
  piVar1 = (int *)(param_1 + 0x14);
  iVar5 = *piVar1;
  *(int *)(param_1 + 0x14) = iVar5 + 1;
  *(char *)(*(int *)(param_1 + 8) + iVar5) = (char)param_3;
  iVar5 = *(int *)(param_1 + 0x14);
  *(int *)(param_1 + 0x14) = iVar5 + 1;
  *(char *)(*(int *)(param_1 + 8) + iVar5) = (char)(param_3 >> 8);
  iVar5 = *(int *)(param_1 + 0x14);
  *(int *)(param_1 + 0x14) = iVar5 + 1;
  *(char *)(*(int *)(param_1 + 8) + iVar5) = (char)(~param_3 & 0xffff);
  iVar5 = *(int *)(param_1 + 0x14);
  *(int *)(param_1 + 0x14) = iVar5 + 1;
  *(char *)(*(int *)(param_1 + 8) + iVar5) = (char)((~param_3 & 0xffff) >> 8);
  for (; param_3 != 0; param_3 = param_3 - 1) {
    iVar5 = *piVar1;
    uVar2 = *param_2;
    *piVar1 = iVar5 + 1;
    *(undefined1 *)(*(int *)(param_1 + 8) + iVar5) = uVar2;
    param_2 = param_2 + 1;
  }
  return;
}

// ===== _tr_align  @0x001bc0fe  (272 bytes)
void _tr_align(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  ushort *puVar5;
  
  uVar2 = *(uint *)(param_1 + 0x16bc);
  uVar1 = (uint)*(ushort *)(param_1 + 0x16b8) | 2 << (uVar2 & 0xff);
  *(short *)(param_1 + 0x16b8) = (short)uVar1;
  puVar5 = (ushort *)(param_1 + 0x16b8);
  puVar4 = (uint *)(param_1 + 0x16bc);
  if ((int)uVar2 < 0xe) {
    uVar2 = uVar2 + 3;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar3 + 1;
    *(char *)(*(int *)(param_1 + 8) + iVar3) = (char)uVar1;
    iVar3 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar3 + 1;
    *(undefined1 *)(*(int *)(param_1 + 8) + iVar3) = *(undefined1 *)(param_1 + 0x16b9);
    uVar1 = 2 >> (0x10 - *puVar4 & 0xff);
    uVar2 = *puVar4 - 0xd;
    *puVar5 = (ushort)uVar1;
  }
  *puVar4 = uVar2;
  if ((int)uVar2 < 10) {
    uVar2 = uVar2 + 7;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar3 + 1;
    *(char *)(*(int *)(param_1 + 8) + iVar3) = (char)uVar1;
    iVar3 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar3 + 1;
    *(undefined1 *)(*(int *)(param_1 + 8) + iVar3) = *(undefined1 *)(param_1 + 0x16b9);
    *puVar5 = 0;
    uVar2 = *puVar4 - 9;
  }
  *puVar4 = uVar2;
  FUN_001bc20e(param_1);
  uVar1 = *puVar4;
  if ((int)((*(int *)(param_1 + 0x16b4) + 0xb) - uVar1) < 9) {
    uVar2 = (uint)*puVar5 | 2 << (uVar1 & 0xff);
    *puVar5 = (ushort)uVar2;
    if ((int)uVar1 < 0xe) {
      uVar1 = uVar1 + 3;
    }
    else {
      iVar3 = *(int *)(param_1 + 0x14);
      *(int *)(param_1 + 0x14) = iVar3 + 1;
      *(char *)(*(int *)(param_1 + 8) + iVar3) = (char)uVar2;
      iVar3 = *(int *)(param_1 + 0x14);
      *(int *)(param_1 + 0x14) = iVar3 + 1;
      *(undefined1 *)(*(int *)(param_1 + 8) + iVar3) = *(undefined1 *)(param_1 + 0x16b9);
      uVar2 = 2 >> (0x10 - *puVar4 & 0xff);
      uVar1 = *puVar4 - 0xd;
      *puVar5 = (ushort)uVar2;
    }
    *puVar4 = uVar1;
    if ((int)uVar1 < 10) {
      uVar1 = uVar1 + 7;
    }
    else {
      iVar3 = *(int *)(param_1 + 0x14);
      *(int *)(param_1 + 0x14) = iVar3 + 1;
      *(char *)(*(int *)(param_1 + 8) + iVar3) = (char)uVar2;
      iVar3 = *(int *)(param_1 + 0x14);
      *(int *)(param_1 + 0x14) = iVar3 + 1;
      *(undefined1 *)(*(int *)(param_1 + 8) + iVar3) = *(undefined1 *)(param_1 + 0x16b9);
      *puVar5 = 0;
      uVar1 = *puVar4 - 9;
    }
    *puVar4 = uVar1;
    FUN_001bc20e(param_1);
  }
  *(undefined4 *)(param_1 + 0x16b4) = 7;
  return;
}

// ===== _tr_flush_block  @0x001bc27c  (920 bytes)
void _tr_flush_block(int *param_1,int param_2,int param_3,int param_4)

{
  byte *pbVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  ushort uVar9;
  uint uVar10;
  ushort *puVar11;
  uint *puVar12;
  bool bVar13;
  
  if (param_1[0x21] < 1) {
    uVar5 = param_3 + 5;
    iVar2 = 0;
    uVar10 = uVar5;
  }
  else {
    if ((param_3 != 0) && (*(int *)(*param_1 + 0x2c) == 2)) {
      iVar2 = 0;
      do {
        if ((short)param_1[iVar2 + 0x25] != 0) goto LAB_001bc2d6;
        iVar2 = iVar2 + 1;
      } while (iVar2 < 9);
      if (iVar2 == 9) {
        iVar4 = 0x33;
        do {
          iVar2 = iVar4;
          if ((short)param_1[iVar2] != 0) {
            iVar2 = iVar2 + -0x25;
            goto LAB_001bc2d6;
          }
          iVar4 = iVar2 + 1;
        } while (iVar2 + -0x24 < 0x20);
        iVar2 = iVar2 + -0x24;
      }
LAB_001bc2d6:
      *(uint *)(*param_1 + 0x2c) = (uint)(iVar2 == 0x20);
    }
    FUN_001bc624(param_1,param_1 + 0x2c6);
    FUN_001bc624(param_1,param_1 + 0x2c9);
    FUN_001bce66(param_1,param_1 + 0x25,param_1[0x2c7]);
    FUN_001bce66(param_1,param_1 + 0x262,param_1[0x2ca]);
    FUN_001bc624(param_1,param_1 + 0x2cc);
    iVar2 = 0x12;
    do {
      if (*(short *)((int)param_1 + (uint)(byte)(&DAT_00261130)[iVar2] * 4 + 0xa7e) != 0) break;
      iVar2 = iVar2 + -1;
    } while (2 < iVar2);
    iVar4 = param_1[0x5aa] + iVar2 * 3;
    param_1[0x5aa] = iVar4 + 0x11;
    uVar8 = iVar4 + 0x1b;
    uVar5 = param_1[0x5ab] + 10U >> 3;
    uVar10 = uVar5;
    if (uVar8 >> 3 < uVar5) {
      uVar10 = uVar8 >> 3;
    }
  }
  if ((param_2 == 0) || (uVar10 < param_3 + 4U)) {
    puVar12 = (uint *)(param_1 + 0x5af);
    uVar8 = param_1[0x5af];
    bVar13 = uVar5 != uVar10;
    if (bVar13) {
      uVar5 = param_1[0x22];
    }
    if (bVar13 && uVar5 != 4) {
      puVar11 = (ushort *)(param_1 + 0x5ae);
      uVar5 = (uint)*(ushort *)(param_1 + 0x5ae) | param_4 + 4U << (uVar8 & 0xff);
      uVar9 = (ushort)uVar5;
      *(ushort *)(param_1 + 0x5ae) = uVar9;
      if ((int)uVar8 < 0xe) {
        uVar8 = uVar8 + 3;
      }
      else {
        iVar4 = param_1[5];
        param_1[5] = iVar4 + 1;
        *(char *)(param_1[2] + iVar4) = (char)uVar5;
        iVar4 = param_1[5];
        param_1[5] = iVar4 + 1;
        *(undefined1 *)(param_1[2] + iVar4) = *(undefined1 *)((int)param_1 + 0x16b9);
        uVar8 = *puVar12 - 0xd;
        uVar9 = (ushort)((param_4 + 4U & 0xffff) >> (0x10 - *puVar12 & 0xff));
        *puVar11 = uVar9;
      }
      *puVar12 = uVar8;
      iVar4 = param_1[0x2c7];
      uVar10 = param_1[0x2ca];
      uVar5 = iVar4 - 0x100U << (uVar8 & 0xff) | (uint)uVar9;
      uVar9 = (ushort)uVar5;
      *puVar11 = uVar9;
      if ((int)uVar8 < 0xc) {
        uVar8 = uVar8 + 5;
      }
      else {
        iVar7 = param_1[5];
        param_1[5] = iVar7 + 1;
        *(char *)(param_1[2] + iVar7) = (char)uVar5;
        iVar7 = param_1[5];
        param_1[5] = iVar7 + 1;
        *(undefined1 *)(param_1[2] + iVar7) = *(undefined1 *)((int)param_1 + 0x16b9);
        uVar8 = *puVar12 - 0xb;
        uVar9 = (ushort)((iVar4 - 0x100U & 0xffff) >> (0x10 - *puVar12 & 0xff));
        *puVar11 = uVar9;
      }
      uVar5 = (uint)uVar9 | uVar10 << (uVar8 & 0xff);
      *puVar12 = uVar8;
      uVar9 = (ushort)uVar5;
      *puVar11 = uVar9;
      if ((int)uVar8 < 0xc) {
        uVar8 = uVar8 + 5;
      }
      else {
        iVar4 = param_1[5];
        param_1[5] = iVar4 + 1;
        *(char *)(param_1[2] + iVar4) = (char)uVar5;
        iVar4 = param_1[5];
        param_1[5] = iVar4 + 1;
        *(undefined1 *)(param_1[2] + iVar4) = *(undefined1 *)((int)param_1 + 0x16b9);
        uVar8 = *puVar12 - 0xb;
        uVar9 = (ushort)((uVar10 & 0xffff) >> (0x10 - *puVar12 & 0xff));
        *puVar11 = uVar9;
      }
      *puVar12 = uVar8;
      uVar5 = iVar2 - 3U << (uVar8 & 0xff) | (uint)uVar9;
      *puVar11 = (ushort)uVar5;
      if ((int)uVar8 < 0xd) {
        uVar8 = uVar8 + 4;
      }
      else {
        iVar4 = param_1[5];
        param_1[5] = iVar4 + 1;
        *(char *)(param_1[2] + iVar4) = (char)uVar5;
        iVar4 = param_1[5];
        param_1[5] = iVar4 + 1;
        *(undefined1 *)(param_1[2] + iVar4) = *(undefined1 *)((int)param_1 + 0x16b9);
        uVar8 = *puVar12 - 0xc;
        uVar5 = (iVar2 - 3U & 0xffff) >> (0x10 - *puVar12 & 0xff);
        *puVar11 = (ushort)uVar5;
      }
      *puVar12 = uVar8;
      if (-1 < iVar2) {
        iVar2 = iVar2 + 1;
        pbVar1 = &DAT_00261130;
        do {
          uVar9 = *(ushort *)((int)param_1 + (uint)*pbVar1 * 4 + 0xa7e);
          uVar5 = uVar5 & 0xffff | (uint)uVar9 << (uVar8 & 0xff);
          *puVar11 = (ushort)uVar5;
          if ((int)uVar8 < 0xe) {
            uVar8 = uVar8 + 3;
          }
          else {
            iVar4 = param_1[5];
            param_1[5] = iVar4 + 1;
            *(char *)(param_1[2] + iVar4) = (char)uVar5;
            iVar4 = param_1[5];
            param_1[5] = iVar4 + 1;
            *(undefined1 *)(param_1[2] + iVar4) = *(undefined1 *)((int)param_1 + 0x16b9);
            uVar8 = *puVar12 - 0xd;
            uVar9 = uVar9 >> (0x10 - *puVar12 & 0xff);
            uVar5 = (uint)uVar9;
            *puVar11 = uVar9;
          }
          pbVar1 = pbVar1 + 1;
          iVar2 = iVar2 + -1;
          *puVar12 = uVar8;
        } while (iVar2 != 0);
      }
      piVar3 = param_1 + 0x25;
      FUN_001bcf28(param_1,piVar3);
      piVar6 = param_1 + 0x262;
      FUN_001bcf28(param_1,piVar6,uVar10);
    }
    else {
      uVar5 = (uint)*(ushort *)(param_1 + 0x5ae) | param_4 + 2U << (uVar8 & 0xff);
      *(short *)(param_1 + 0x5ae) = (short)uVar5;
      if ((int)uVar8 < 0xe) {
        uVar8 = uVar8 + 3;
      }
      else {
        iVar2 = param_1[5];
        param_1[5] = iVar2 + 1;
        *(char *)(param_1[2] + iVar2) = (char)uVar5;
        iVar2 = param_1[5];
        param_1[5] = iVar2 + 1;
        *(undefined1 *)(param_1[2] + iVar2) = *(undefined1 *)((int)param_1 + 0x16b9);
        *(short *)(param_1 + 0x5ae) = (short)((param_4 + 2U & 0xffff) >> (0x10 - *puVar12 & 0xff));
        uVar8 = *puVar12 - 0xd;
      }
      *puVar12 = uVar8;
      piVar3 = (int *)&DAT_00260b00;
      piVar6 = (int *)&DAT_00260f80;
    }
    FUN_001bc9d4(param_1,piVar3,piVar6);
  }
  else {
    _tr_stored_block(param_1,param_2,param_3,param_4);
  }
  FUN_001bbfa4(param_1);
  if (param_4 == 0) {
    return;
  }
  FUN_001bccb0(param_1);
  return;
}

// ===== _tr_tally  @0x001bcd0c  (162 bytes)
bool _tr_tally(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x16a0);
  *(short *)(*(int *)(param_1 + 0x16a4) + iVar3 * 2) = (short)param_2;
  *(int *)(param_1 + 0x16a0) = iVar3 + 1;
  *(char *)(*(int *)(param_1 + 0x1698) + iVar3) = (char)param_3;
  if (param_2 == 0) {
    iVar3 = param_1 + param_3 * 4;
    *(short *)(iVar3 + 0x94) = *(short *)(iVar3 + 0x94) + 1;
  }
  else {
    uVar1 = param_2 - 1;
    *(int *)(param_1 + 0x16b0) = *(int *)(param_1 + 0x16b0) + 1;
    if (0xff < uVar1) {
      uVar1 = (uVar1 >> 7) + 0x100;
    }
    iVar2 = param_1 + ((byte)_length_code[param_3] | 0x100) * 4;
    iVar3 = param_1 + (uint)(byte)_dist_code[uVar1] * 4;
    *(short *)(iVar2 + 0x98) = *(short *)(iVar2 + 0x98) + 1;
    *(short *)(iVar3 + 0x988) = *(short *)(iVar3 + 0x988) + 1;
  }
  return *(int *)(param_1 + 0x16a0) == *(int *)(param_1 + 0x169c) + -1;
}

// ===== inflate_fast  @0x001bd290  (1120 bytes)
void inflate_fast(int *param_1,int param_2)

{
  ushort uVar1;
  byte bVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined1 *puVar12;
  int iVar13;
  undefined1 *puVar14;
  int iVar15;
  byte *pbVar16;
  byte *pbVar17;
  byte *pbVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  undefined1 *puVar25;
  uint uVar26;
  undefined4 *puVar27;
  undefined1 *puVar28;
  undefined1 *puVar29;
  undefined1 *puVar30;
  uint uVar31;
  uint uVar32;
  undefined1 *puVar33;
  int iVar34;
  
  iVar10 = param_1[1];
  iVar22 = param_1[4];
  puVar27 = (undefined4 *)param_1[7];
  pbVar16 = (byte *)(*param_1 + -1);
  puVar30 = (undefined1 *)(param_1[3] + -1);
  iVar15 = puVar27[10];
  uVar5 = puVar27[0xb];
  puVar28 = puVar30 + (iVar22 - param_2);
  uVar19 = puVar27[0xc];
  puVar33 = (undefined1 *)puVar27[0xd];
  iVar34 = puVar27[0x13];
  iVar6 = puVar27[0x14];
  uVar8 = puVar27[0x15];
  uVar11 = puVar27[0x16];
  uVar32 = puVar27[0xe];
  uVar9 = puVar27[0xf];
  puVar12 = puVar33 + -1;
  pbVar17 = pbVar16;
  puVar29 = puVar30;
LAB_001bd328:
  pbVar18 = pbVar17;
  if (uVar9 < 0xf) {
    pbVar18 = pbVar17 + 2;
    uVar23 = uVar9 + 8;
    uVar26 = uVar9 & 0xff;
    uVar9 = uVar9 + 0x10;
    uVar32 = ((uint)pbVar17[1] << uVar26) + uVar32 + ((uint)*pbVar18 << (uVar23 & 0xff));
  }
  uVar23 = uVar32 & (1 << (uVar8 & 0xff)) - 1U;
  iVar20 = iVar34 + uVar23 * 4;
  uVar26 = (uint)*(byte *)(iVar20 + 1);
  uVar1 = *(ushort *)(iVar20 + 2);
  uVar9 = uVar9 - uVar26;
  uVar26 = uVar32 >> uVar26;
  bVar2 = *(byte *)(iVar34 + uVar23 * 4);
  while (uVar23 = (uint)bVar2, pbVar17 = pbVar18, uVar32 = uVar26, uVar23 != 0) {
    if ((bVar2 & 0x10) != 0) {
      uVar23 = uVar23 & 0xf;
      uVar31 = (uint)uVar1;
      if ((bVar2 & 0xf) != 0) {
        if (uVar9 < uVar23) {
          pbVar18 = pbVar18 + 1;
          uVar26 = uVar26 + ((uint)*pbVar18 << (uVar9 & 0xff));
          uVar9 = uVar9 + 8;
        }
        uVar9 = uVar9 - uVar23;
        uVar31 = uVar31 + ((1 << uVar23) - 1U & uVar26);
        uVar26 = uVar26 >> uVar23;
        pbVar17 = pbVar18;
      }
      pbVar18 = pbVar17;
      if (uVar9 < 0xf) {
        pbVar18 = pbVar17 + 2;
        uVar26 = uVar26 + ((uint)pbVar17[1] << (uVar9 & 0xff)) +
                 ((uint)*pbVar18 << (uVar9 + 8 & 0xff));
        uVar9 = uVar9 + 0x10;
      }
      uVar32 = uVar26 & (1 << (uVar11 & 0xff)) - 1U;
      iVar20 = iVar6 + uVar32 * 4;
      bVar2 = *(byte *)(iVar6 + uVar32 * 4);
      uVar32 = (uint)*(byte *)(iVar20 + 1);
      uVar1 = *(ushort *)(iVar20 + 2);
      uVar9 = uVar9 - uVar32;
      uVar26 = uVar26 >> uVar32;
      goto joined_r0x001bd420;
    }
    if ((bVar2 & 0x40) != 0) {
      if ((bVar2 & 0x20) == 0) {
        param_1[6] = (int)"invalid literal/length code";
        goto LAB_001bd696;
      }
      uVar7 = 0xb;
      goto LAB_001bd698;
    }
    iVar20 = ((1 << uVar23) - 1U & uVar26) + (uint)uVar1;
    iVar13 = iVar34 + iVar20 * 4;
    uVar32 = (uint)*(byte *)(iVar13 + 1);
    uVar1 = *(ushort *)(iVar13 + 2);
    uVar9 = uVar9 - uVar32;
    uVar26 = uVar26 >> uVar32;
    bVar2 = *(byte *)(iVar34 + iVar20 * 4);
  }
  puVar29[1] = (char)uVar1;
  puVar25 = puVar29 + 1;
  goto LAB_001bd65c;
joined_r0x001bd420:
  uVar23 = (uint)uVar1;
  if ((bVar2 & 0x10) == 0) {
    if ((bVar2 & 0x40) == 0) goto code_r0x001bd42a;
    param_1[6] = (int)"invalid distance code";
LAB_001bd696:
    uVar7 = 0x1b;
    pbVar17 = pbVar18;
    uVar32 = uVar26;
    goto LAB_001bd698;
  }
  goto LAB_001bd452;
code_r0x001bd42a:
  iVar20 = ((1 << (uint)bVar2) - 1U & uVar26) + uVar23;
  iVar13 = iVar6 + iVar20 * 4;
  bVar2 = *(byte *)(iVar6 + iVar20 * 4);
  uVar32 = (uint)*(byte *)(iVar13 + 1);
  uVar1 = *(ushort *)(iVar13 + 2);
  uVar9 = uVar9 - uVar32;
  uVar26 = uVar26 >> uVar32;
  goto joined_r0x001bd420;
LAB_001bd452:
  uVar24 = bVar2 & 0xf;
  uVar32 = uVar9;
  pbVar17 = pbVar18;
  if (uVar9 < uVar24) {
    uVar32 = uVar9 + 8;
    uVar26 = uVar26 + ((uint)pbVar18[1] << (uVar9 & 0xff));
    pbVar17 = pbVar18 + 1;
    if (uVar32 < uVar24) {
      uVar26 = uVar26 + ((uint)pbVar18[2] << (uVar32 & 0xff));
      uVar32 = uVar9 + 0x10;
      pbVar17 = pbVar18 + 2;
    }
  }
  uVar9 = uVar32 - uVar24;
  uVar32 = uVar26 >> uVar24;
  uVar26 = uVar26 & (1 << uVar24) - 1U;
  uVar24 = uVar26 + uVar23;
  if (uVar24 <= (uint)((int)puVar29 - (int)puVar28)) {
    iVar20 = 0;
    iVar13 = -uVar23 - uVar26;
    uVar26 = 0;
    do {
      iVar20 = iVar20 + -3;
      iVar4 = iVar13 + uVar26;
      uVar23 = uVar26 + 3;
      puVar29[uVar26 + 1] = puVar29[iVar4 + 1];
      puVar29[uVar26 + 2] = puVar29[iVar4 + 2];
      puVar29[uVar26 + 3] = puVar29[iVar4 + 3];
      uVar26 = uVar23;
    } while (2 < uVar31 + iVar20);
    puVar25 = puVar29 + uVar23;
    if (uVar31 != uVar23) {
      puVar25[1] = puVar25[iVar13 + 1];
      if (uVar31 - 1 == uVar23) {
        puVar25 = puVar25 + 1;
      }
      else {
        puVar25[2] = puVar25[iVar13 + 2];
        puVar25 = puVar25 + 2;
      }
    }
    goto LAB_001bd65c;
  }
  uVar21 = uVar24 - ((int)puVar29 - (int)puVar28);
  if (uVar5 < uVar21) {
    param_1[6] = (int)"invalid distance too far back";
    uVar7 = 0x1b;
LAB_001bd698:
    *puVar27 = uVar7;
    puVar25 = puVar29;
LAB_001bd69c:
    param_1[3] = (int)(puVar25 + 1);
    iVar6 = (int)pbVar17 - (uVar9 >> 3);
    *param_1 = iVar6 + 1;
    param_1[1] = (int)(pbVar16 + (iVar10 - iVar6));
    param_1[4] = (int)(puVar30 + (iVar22 - (int)puVar25));
    uVar9 = uVar9 - (uVar9 & 0xfffffff8);
    puVar27[0xe] = (1 << (uVar9 & 0xff)) - 1U & uVar32;
    puVar27[0xf] = uVar9;
    return;
  }
  if (uVar19 == 0) {
    if (uVar21 < uVar31) {
      puVar25 = puVar29 + ((-(int)puVar28 - uVar26) - uVar23);
      do {
        puVar29 = puVar29 + 1;
        puVar14 = puVar25 + iVar15;
        puVar25 = puVar25 + 1;
        *puVar29 = puVar33[(int)puVar14];
      } while (puVar25 != (undefined1 *)0x0);
LAB_001bd5c4:
      uVar31 = uVar31 - uVar21;
      puVar29 = puVar28 + uVar24;
      puVar14 = puVar29 + -uVar24;
    }
    else {
      puVar14 = puVar12 + (iVar15 - uVar21);
    }
  }
  else {
    if (uVar19 < uVar21) {
      if (uVar21 - uVar19 < uVar31) {
        iVar20 = uVar24 - (int)puVar29;
        uVar31 = uVar31 - (uVar21 - uVar19);
        puVar14 = puVar29 + (((uVar19 - (int)puVar28) - uVar26) - uVar23);
        puVar25 = puVar29;
        do {
          puVar25 = puVar25 + 1;
          puVar3 = puVar14 + iVar15;
          puVar14 = puVar14 + 1;
          *puVar25 = puVar33[(int)puVar3];
        } while (puVar14 != (undefined1 *)0x0);
        if (uVar19 < uVar31) {
          uVar26 = uVar19;
          puVar25 = puVar29 + (int)(puVar28 + iVar20 + (1 - uVar19));
          puVar14 = puVar33;
          do {
            uVar26 = uVar26 - 1;
            *puVar25 = *puVar14;
            puVar25 = puVar25 + 1;
            puVar14 = puVar14 + 1;
          } while (uVar26 != 0);
          puVar29 = puVar29 + (int)puVar28 + iVar20;
          uVar31 = uVar31 - uVar19;
          puVar14 = puVar29 + -uVar24;
        }
        else {
          puVar29 = puVar29 + (int)(puVar28 + (iVar20 - uVar19));
          puVar14 = puVar12;
        }
        goto LAB_001bd60c;
      }
      iVar20 = (uVar19 + iVar15) - uVar21;
    }
    else {
      if (uVar21 < uVar31) {
        puVar25 = puVar29 + ((-(int)puVar28 - uVar26) - uVar23);
        do {
          puVar29 = puVar29 + 1;
          puVar14 = puVar25 + uVar19;
          puVar25 = puVar25 + 1;
          *puVar29 = puVar33[(int)puVar14];
        } while (puVar25 != (undefined1 *)0x0);
        goto LAB_001bd5c4;
      }
      iVar20 = uVar19 - uVar21;
    }
    puVar14 = puVar12 + iVar20;
  }
LAB_001bd60c:
  if (2 < uVar31) {
    iVar20 = 0;
    do {
      uVar31 = uVar31 - 3;
      iVar13 = iVar20 + 3;
      puVar29[iVar20 + 1] = puVar14[iVar20 + 1];
      puVar29[iVar20 + 2] = puVar14[iVar20 + 2];
      puVar29[iVar20 + 3] = puVar14[iVar20 + 3];
      iVar20 = iVar13;
    } while (2 < uVar31);
    puVar29 = puVar29 + iVar13;
    puVar14 = puVar14 + iVar13;
  }
  puVar25 = puVar29;
  if (uVar31 != 0) {
    puVar29[1] = puVar14[1];
    puVar25 = puVar29 + 1;
    if (uVar31 != 1) {
      puVar25 = puVar29 + 2;
      *puVar25 = puVar14[2];
    }
  }
LAB_001bd65c:
  if ((puVar30 + iVar22 + -0x101 <= puVar25) ||
     (puVar29 = puVar25, pbVar16 + iVar10 + -5 <= pbVar17)) goto LAB_001bd69c;
  goto LAB_001bd328;
}

// ===== adler32  @0x001bd6fc  (502 bytes)
uint adler32(uint param_1,byte *param_2,uint param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  byte *pbVar21;
  int iVar22;
  uint uVar23;
  
  uVar20 = param_1 & 0xffff;
  param_1 = param_1 >> 0x10;
  if (param_3 == 1) {
    uVar20 = *param_2 + uVar20;
    if (0xfff0 < uVar20) {
      uVar20 = uVar20 - 0xfff1;
    }
    param_1 = uVar20 + param_1;
    if (0xfff0 < param_1) {
      param_1 = param_1 + 0xf;
    }
    return uVar20 | param_1 << 0x10;
  }
  if (param_2 == (byte *)0x0) {
    return 1;
  }
  if (param_3 < 0x10) {
    for (; param_3 != 0; param_3 = param_3 - 1) {
      uVar20 = uVar20 + *param_2;
      param_1 = param_1 + uVar20;
      param_2 = param_2 + 1;
    }
    if (0xfff0 < uVar20) {
      uVar20 = uVar20 - 0xfff1;
    }
    return uVar20 | (param_1 % 0xfff1) * 0x10000;
  }
  if (0x15af < param_3) {
    do {
      param_3 = param_3 - 0x15b0;
      iVar13 = 0;
      do {
        iVar18 = iVar13 + 0x10;
        iVar17 = param_2[iVar13] + uVar20;
        iVar16 = (uint)param_2[iVar13 + 1] + iVar17;
        iVar22 = iVar16 + (uint)param_2[iVar13 + 2];
        iVar14 = (uint)param_2[iVar13 + 3] + iVar22;
        iVar15 = iVar14 + (uint)param_2[iVar13 + 4];
        iVar3 = (uint)param_2[iVar13 + 5] + iVar15;
        iVar4 = iVar3 + (uint)param_2[iVar13 + 6];
        iVar5 = iVar4 + (uint)param_2[iVar13 + 7];
        iVar6 = iVar5 + (uint)param_2[iVar13 + 8];
        iVar7 = iVar6 + (uint)param_2[iVar13 + 9];
        iVar8 = iVar7 + (uint)param_2[iVar13 + 10];
        iVar9 = iVar8 + (uint)param_2[iVar13 + 0xb];
        iVar10 = iVar9 + (uint)param_2[iVar13 + 0xc];
        iVar11 = iVar10 + (uint)param_2[iVar13 + 0xd];
        iVar12 = iVar11 + (uint)param_2[iVar13 + 0xe];
        uVar20 = iVar12 + (uint)param_2[iVar13 + 0xf];
        param_1 = iVar16 + iVar17 + param_1 + iVar22 + iVar14 + iVar15 + iVar3 + iVar4 + iVar5 +
                  iVar6 + iVar7 + iVar8 + iVar9 + iVar10 + iVar11 + iVar12 + uVar20;
        iVar13 = iVar18;
      } while (iVar18 != 0x15b0);
      param_2 = param_2 + 0x15b0;
      param_1 = param_1 % 0xfff1;
      uVar20 = uVar20 % 0xfff1;
    } while (0x15af < param_3);
    if (param_3 == 0) goto LAB_001bd8ea;
    if (param_3 < 0x10) goto LAB_001bd8be;
  }
  uVar23 = param_3 - 0x10;
  uVar19 = uVar23 & 0xfffffff0;
  pbVar21 = param_2 + uVar19 + 0x10;
  do {
    param_3 = param_3 - 0x10;
    iVar13 = *param_2 + uVar20;
    iVar16 = iVar13 + (uint)param_2[1];
    iVar17 = iVar16 + (uint)param_2[2];
    iVar7 = (uint)param_2[3] + iVar17;
    iVar8 = iVar7 + (uint)param_2[4];
    iVar9 = iVar8 + (uint)param_2[5];
    iVar10 = iVar9 + (uint)param_2[6];
    iVar11 = iVar10 + (uint)param_2[7];
    iVar12 = iVar11 + (uint)param_2[8];
    iVar14 = iVar12 + (uint)param_2[9];
    iVar15 = iVar14 + (uint)param_2[10];
    iVar3 = (uint)param_2[0xb] + iVar15;
    pbVar2 = param_2 + 0xe;
    iVar4 = iVar3 + (uint)param_2[0xc];
    pbVar1 = param_2 + 0xf;
    iVar5 = iVar4 + (uint)param_2[0xd];
    param_2 = param_2 + 0x10;
    iVar6 = iVar5 + (uint)*pbVar2;
    uVar20 = iVar6 + (uint)*pbVar1;
    param_1 = iVar13 + param_1 + iVar16 + iVar17 + iVar7 + iVar8 + iVar9 + iVar10 + iVar11 + iVar12
              + iVar14 + iVar15 + iVar3 + iVar4 + iVar5 + iVar6 + uVar20;
  } while (0xf < param_3);
  param_2 = pbVar21;
  for (param_3 = uVar23 - uVar19; param_3 != 0; param_3 = param_3 - 1) {
LAB_001bd8be:
    uVar20 = uVar20 + *param_2;
    param_1 = param_1 + uVar20;
    param_2 = param_2 + 1;
  }
  param_1 = param_1 % 0xfff1;
  uVar20 = uVar20 % 0xfff1;
LAB_001bd8ea:
  return uVar20 | param_1 << 0x10;
}

// ===== adler32_combine  @0x001bd8f2  (112 bytes)
uint adler32_combine(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = (param_1 & 0xffff) + (param_2 & 0xffff);
  uVar1 = (((param_1 >> 0x10) + (param_2 >> 0x10) + 0xfff1) - param_3 % 0xfff1) +
          ((param_3 % 0xfff1) * (param_1 & 0xffff)) % 0xfff1;
  if (0x1ffe2 < uVar1) {
    uVar1 = uVar1 - 0x1ffe2;
  }
  uVar3 = iVar2 + 0xfff0;
  if (0xfff1 < uVar1) {
    uVar1 = uVar1 + 0xf;
  }
  uVar4 = iVar2 - 1;
  if (uVar3 < 0xfff1 || uVar4 == 0) {
    uVar4 = uVar3;
  }
  uVar3 = uVar4 - 0xfff1;
  if (uVar4 < 0xfff1 || uVar4 - 0xfff1 == 0) {
    uVar3 = uVar4;
  }
  return uVar3 | uVar1 << 0x10;
}

// ===== _zip_memdup  @0x001bd962  (52 bytes)
void * _zip_memdup(undefined4 param_1,size_t param_2,undefined4 param_3)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_2);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
    _zip_error_set(param_3,0xe,0);
  }
  else {
    __aeabi_memcpy(pvVar1,param_1,param_2);
  }
  return pvVar1;
}

// ===== zip_add  @0x001bd996  (38 bytes)
undefined4 zip_add(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((param_2 != 0) && (param_3 != 0)) {
    uVar1 = _zip_replace(param_1,0xffffffff);
    return uVar1;
  }
  _zip_error_set(param_1 + 8,0x12,0);
  return 0xffffffff;
}

// ===== _zip_filerange_crc  @0x001bd9bc  (174 bytes)
void _zip_filerange_crc(FILE *param_1,__off_t param_2,size_t param_3,undefined4 *param_4,
                       undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  size_t sVar5;
  undefined1 auStack_2028 [8192];
  int iStack_28;
  
  iStack_28 = __stack_chk_guard;
  uVar1 = crc32(0,0,0);
  *param_4 = uVar1;
  iVar2 = fseeko(param_1,param_2,0);
  if (iVar2 == 0) {
    for (; 0 < (int)param_3; param_3 = param_3 - sVar5) {
      sVar5 = param_3;
      if (0x2000 < (int)param_3) {
        sVar5 = 0x2000;
      }
      sVar5 = fread(auStack_2028,1,sVar5,param_1);
      if (sVar5 == 0) {
        puVar3 = (undefined4 *)__errno();
        uVar4 = *puVar3;
        uVar1 = 5;
        goto LAB_001bda02;
      }
      uVar1 = crc32(*param_4,auStack_2028,sVar5);
      *param_4 = uVar1;
    }
    uVar1 = 0;
  }
  else {
    puVar3 = (undefined4 *)__errno();
    uVar4 = *puVar3;
    uVar1 = 4;
LAB_001bda02:
    _zip_error_set(param_5,uVar1,uVar4);
    uVar1 = 0xffffffff;
  }
  if (__stack_chk_guard == iStack_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar1);
}

// ===== zip_get_name  @0x001bda74  (10 bytes)
void zip_get_name(void)

{
  _zip_get_name();
  return;
}

// ===== _zip_get_name  @0x001bda7c  (92 bytes)
int _zip_get_name(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x28))) {
    if ((param_3 & 8) == 0) {
      if (*(int *)(*(int *)(param_1 + 0x30) + param_2 * 0x14) == 1) {
        uVar2 = 0x17;
        goto LAB_001bdace;
      }
      iVar3 = *(int *)(*(int *)(param_1 + 0x30) + param_2 * 0x14 + 8);
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    piVar1 = *(int **)(param_1 + 0x1c);
    if ((piVar1 != (int *)0x0) && (param_2 < piVar1[1])) {
      return *(int *)(*piVar1 + param_2 * 0x3c + 0x18);
    }
  }
  uVar2 = 0x12;
LAB_001bdace:
  _zip_error_set(param_4,uVar2,0);
  return 0;
}

// ===== zip_file_strerror  @0x001bdad8  (6 bytes)
void zip_file_strerror(int param_1)

{
  _zip_error_strerror(param_1 + 4);
  return;
}

// ===== zip_fopen_index  @0x001bdae0  (456 bytes)
int * zip_fopen_index(int param_1,int param_2,uint param_3)

{
  short sVar1;
  int *__ptr;
  void *pvVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x28))) {
    if (((param_3 & 8) == 0) &&
       ((*(uint *)(*(int *)(param_1 + 0x30) + param_2 * 0x14) & 0xfffffffe) == 2)) {
      uVar4 = 0xf;
      goto LAB_001bdb48;
    }
    if (param_2 < (*(int **)(param_1 + 0x1c))[1]) {
      sVar1 = *(short *)(**(int **)(param_1 + 0x1c) + param_2 * 0x3c + 6);
      if (sVar1 == 0) {
        iVar6 = 4;
      }
      else if (sVar1 == 8) {
        iVar6 = 0;
        if ((param_3 & 4) == 0) {
          iVar6 = 6;
        }
      }
      else {
        if ((param_3 & 4) == 0) {
          uVar4 = 0x10;
          goto LAB_001bdb48;
        }
        iVar6 = 0;
      }
      __ptr = malloc(0x34);
      if (__ptr == (int *)0x0) {
        __ptr = (int *)0x0;
        _zip_error_set(param_1 + 8,0xe,0);
      }
      else {
        iVar5 = *(int *)(param_1 + 0x34);
        if (iVar5 < *(int *)(param_1 + 0x38) + -1) {
          pvVar2 = *(void **)(param_1 + 0x3c);
        }
        else {
          iVar5 = *(int *)(param_1 + 0x38) + 10;
          pvVar2 = realloc(*(void **)(param_1 + 0x3c),iVar5 * 4);
          if (pvVar2 == (void *)0x0) {
            _zip_error_set(param_1 + 8,0xe,0);
            free(__ptr);
            __ptr = (int *)0x0;
            goto LAB_001bdbe6;
          }
          *(int *)(param_1 + 0x38) = iVar5;
          *(void **)(param_1 + 0x3c) = pvVar2;
          iVar5 = *(int *)(param_1 + 0x34);
        }
        *(int *)(param_1 + 0x34) = iVar5 + 1;
        *(int **)((int)pvVar2 + iVar5 * 4) = __ptr;
        *__ptr = param_1;
        _zip_error_init(__ptr + 1);
        __ptr[4] = 0;
        iVar5 = crc32(0,0,0);
        __ptr[9] = iVar5;
        __ptr[10] = 0;
        __ptr[5] = -1;
        __ptr[6] = 0;
        __ptr[7] = 0;
        __ptr[8] = 0;
        __ptr[0xb] = 0;
        __ptr[0xc] = 0;
      }
LAB_001bdbe6:
      __ptr[4] = iVar6;
      iVar6 = **(int **)(param_1 + 0x1c) + param_2 * 0x3c;
      __ptr[5] = (uint)*(ushort *)(iVar6 + 6);
      __ptr[7] = *(int *)(iVar6 + 0x14);
      __ptr[8] = *(int *)(iVar6 + 0x10);
      __ptr[10] = *(int *)(iVar6 + 0xc);
      iVar6 = _zip_file_get_offset(param_1,param_2);
      __ptr[6] = iVar6;
      if (iVar6 == 0) goto LAB_001bdc9e;
      if ((*(byte *)(__ptr + 4) & 2) == 0) {
        __ptr[7] = __ptr[8];
        return __ptr;
      }
      pvVar2 = malloc(0x2000);
      __ptr[0xb] = (int)pvVar2;
      if (pvVar2 == (void *)0x0) {
LAB_001bdc70:
        uVar4 = 0xe;
        iVar6 = 0;
      }
      else {
        iVar6 = _zip_file_fillbuf(pvVar2,0x2000,__ptr);
        if (iVar6 < 1) {
          _zip_error_copy(param_1 + 8,__ptr + 1);
          goto LAB_001bdc9e;
        }
        piVar3 = malloc(0x38);
        __ptr[0xc] = (int)piVar3;
        if (piVar3 == (int *)0x0) goto LAB_001bdc70;
        piVar3[8] = 0;
        piVar3[9] = 0;
        piVar3[10] = 0;
        *piVar3 = __ptr[0xb];
        piVar3[1] = iVar6;
        iVar6 = inflateInit2_(piVar3,0xfffffff1,"1.2.3",0x38);
        if (iVar6 == 0) {
          return __ptr;
        }
        uVar4 = 0xd;
      }
      _zip_error_set(param_1 + 8,uVar4,iVar6);
LAB_001bdc9e:
      zip_fclose(__ptr);
      return (int *)0x0;
    }
  }
  uVar4 = 0x12;
LAB_001bdb48:
  _zip_error_set(param_1 + 8,uVar4,0);
  return (int *)0x0;
}

// ===== _zip_file_fillbuf  @0x001bdcd0  (156 bytes)
size_t _zip_file_fillbuf(void *param_1,uint param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  size_t sVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  piVar1 = param_3 + 1;
  if (*piVar1 == 0) {
    uVar2 = (uint)*(byte *)(param_3 + 4);
    if ((*(byte *)(param_3 + 4) & 1) != 0) {
      return 0;
    }
    if (param_2 != 0) {
      uVar2 = param_3[8];
    }
    if (param_2 == 0 || uVar2 == 0) {
      return 0;
    }
    iVar3 = fseeko(*(FILE **)(*param_3 + 4),param_3[6],0);
    if (iVar3 < 0) {
      puVar5 = (undefined4 *)__errno();
      uVar7 = *puVar5;
      uVar6 = 4;
    }
    else {
      uVar2 = param_3[8];
      if (param_2 < (uint)param_3[8]) {
        uVar2 = param_2;
      }
      sVar4 = fread(param_1,1,uVar2,*(FILE **)(*param_3 + 4));
      if (sVar4 != 0) {
        if (-1 < (int)sVar4) {
          param_3[6] = param_3[6] + sVar4;
          param_3[8] = param_3[8] - sVar4;
          return sVar4;
        }
        puVar5 = (undefined4 *)__errno();
        _zip_error_set(piVar1,5,*puVar5);
        return sVar4;
      }
      uVar6 = 0x11;
      uVar7 = 0;
    }
    _zip_error_set(piVar1,uVar6,uVar7);
  }
  return 0xffffffff;
}

// ===== zip_source_buffer  @0x001bdd6c  (118 bytes)
int zip_source_buffer(int param_1,int param_2,int param_3,undefined4 param_4)

{
  void *__ptr;
  time_t tVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 != 0) {
    if ((param_3 < 0) || ((param_2 == 0 && (param_3 != 0)))) {
      uVar3 = 0x12;
    }
    else {
      __ptr = malloc(0x14);
      if (__ptr != (void *)0x0) {
        *(undefined4 *)((int)__ptr + 0x10) = param_4;
        *(int *)((int)__ptr + 4) = param_2;
        *(int *)((int)__ptr + 8) = param_2 + param_3;
        tVar1 = time((time_t *)0x0);
        *(time_t *)((int)__ptr + 0xc) = tVar1;
        iVar2 = zip_source_function(param_1,0x1bdde9,__ptr);
        if (iVar2 == 0) {
          free(__ptr);
          return 0;
        }
        return iVar2;
      }
      uVar3 = 0xe;
    }
    _zip_error_set(param_1 + 8,uVar3,0);
  }
  return 0;
}

// ===== zip_error_clear  @0x001bde6c  (6 bytes)
void zip_error_clear(int param_1)

{
  _zip_error_clear(param_1 + 8);
  return;
}

// ===== zip_get_archive_comment  @0x001bde72  (48 bytes)
undefined4 zip_get_archive_comment(int param_1,uint *param_2,uint param_3)

{
  int iVar1;
  
  if (((param_3 & 8) == 0) && (*(uint *)(param_1 + 0x24) != 0xffffffff)) {
    if (param_2 != (uint *)0x0) {
      *param_2 = *(uint *)(param_1 + 0x24);
    }
    return *(undefined4 *)(param_1 + 0x20);
  }
  iVar1 = *(int *)(param_1 + 0x1c);
  if (iVar1 != 0) {
    if (param_2 != (uint *)0x0) {
      *param_2 = (uint)*(ushort *)(iVar1 + 0x14);
    }
    return *(undefined4 *)(iVar1 + 0x10);
  }
  if (param_2 != (uint *)0x0) {
    *param_2 = 0xffffffff;
  }
  return 0;
}

// ===== zip_source_file  @0x001bdea2  (54 bytes)
undefined4 zip_source_file(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    if ((param_2 != 0) && (-1 < param_3 && -2 < param_4)) {
      uVar1 = _zip_source_file_or_p(param_1,param_2,0,param_3,param_4);
      return uVar1;
    }
    _zip_error_set(param_1 + 8,0x12,0);
  }
  return 0;
}

// ===== _zip_set_name  @0x001bded8  (134 bytes)
undefined4 _zip_set_name(int param_1,int param_2,char *param_3)

{
  int iVar1;
  char *pcVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  if (((param_2 < 0) || (param_3 == (char *)0x0)) || (*(int *)(param_1 + 0x28) <= param_2)) {
    uVar4 = 0x12;
  }
  else {
    iVar1 = _zip_name_locate(param_1,param_3,0,0);
    if (iVar1 == -1 || iVar1 == param_2) {
      if (iVar1 != param_2) {
        pcVar2 = strdup(param_3);
        if (pcVar2 == (char *)0x0) {
          uVar4 = 0xe;
          goto LAB_001bdf14;
        }
        puVar3 = (undefined4 *)(*(int *)(param_1 + 0x30) + param_2 * 0x14);
        if (*(int *)(*(int *)(param_1 + 0x30) + param_2 * 0x14) == 0) {
          *puVar3 = 4;
        }
        free((void *)puVar3[2]);
        *(char **)(*(int *)(param_1 + 0x30) + param_2 * 0x14 + 8) = pcVar2;
      }
      return 0;
    }
    uVar4 = 10;
  }
LAB_001bdf14:
  _zip_error_set(param_1 + 8,uVar4,0);
  return 0xffffffff;
}

// ===== zip_file_error_get  @0x001bdf5e  (6 bytes)
void zip_file_error_get(int param_1)

{
  _zip_error_get(param_1 + 4);
  return;
}

// ===== _zip_file_get_offset  @0x001bdf64  (136 bytes)
void _zip_file_get_offset(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 auStack_54 [60];
  int local_18;
  
  local_18 = __stack_chk_guard;
  iVar1 = fseeko(*(FILE **)(param_1 + 4),
                 *(__off_t *)(**(int **)(param_1 + 0x1c) + param_2 * 0x3c + 0x38),0);
  if (iVar1 == 0) {
    iVar1 = _zip_dirent_read(auStack_54,*(undefined4 *)(param_1 + 4),0,0,1,param_1 + 8);
    if (iVar1 == 0) {
      _zip_dirent_finalize(auStack_54);
    }
  }
  else {
    puVar2 = (undefined4 *)__errno();
    _zip_error_set(param_1 + 8,4,*puVar2);
  }
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== zip_unchange  @0x001bdff4  (8 bytes)
void zip_unchange(undefined4 param_1,undefined4 param_2)

{
  _zip_unchange(param_1,param_2,0);
  return;
}

// ===== _zip_unchange  @0x001bdffa  (154 bytes)
undefined4 _zip_unchange(int param_1,int param_2,int param_3)

{
  void *__ptr;
  undefined4 uVar1;
  int iVar2;
  
  if ((param_2 < 0) || (*(int *)(param_1 + 0x28) <= param_2)) {
    uVar1 = 0x12;
LAB_001be07c:
    _zip_error_set(param_1 + 8,uVar1,0);
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x30);
    __ptr = *(void **)(iVar2 + param_2 * 0x14 + 8);
    if (__ptr != (void *)0x0) {
      if (param_3 == 0) {
        uVar1 = _zip_get_name(param_1,param_2,8,0);
        iVar2 = _zip_name_locate(param_1,uVar1,0,0);
        if (iVar2 != -1 && iVar2 != param_2) {
          uVar1 = 10;
          goto LAB_001be07c;
        }
        __ptr = *(void **)(*(int *)(param_1 + 0x30) + param_2 * 0x14 + 8);
      }
      free(__ptr);
      iVar2 = *(int *)(param_1 + 0x30);
      *(undefined4 *)(iVar2 + param_2 * 0x14 + 8) = 0;
    }
    free(*(void **)(iVar2 + param_2 * 0x14 + 0xc));
    uVar1 = 0;
    iVar2 = *(int *)(param_1 + 0x30) + param_2 * 0x14;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(undefined4 *)(iVar2 + 0x10) = 0xffffffff;
    _zip_unchange_data();
  }
  return uVar1;
}

// ===== _zip_new  @0x001be094  (78 bytes)
undefined4 * _zip_new(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = malloc(0x40);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
    _zip_error_set(param_1,0xe,0);
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
    _zip_error_init(puVar1 + 2);
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0xffffffff;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[10] = 0;
    puVar1[0xb] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    puVar1[0xc] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    puVar1[0xd] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    puVar1[0xe] = 0;
    puVar1[0xf] = 0;
  }
  return puVar1;
}

// ===== zip_close  @0x001be0e4  (2538 bytes)
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void zip_close(undefined4 *param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  char *__base;
  undefined4 *puVar3;
  char *__template;
  FILE *pFVar4;
  undefined4 uVar5;
  __off_t _Var6;
  size_t sVar7;
  __off_t __off;
  __mode_t __mask;
  uint *puVar8;
  int *piVar9;
  int iVar10;
  uint __n;
  undefined4 uVar11;
  char *__s;
  int iVar12;
  undefined4 uVar13;
  uint uVar14;
  code *pcVar15;
  size_t sVar16;
  int iVar17;
  undefined4 uVar18;
  size_t sVar19;
  int iVar20;
  FILE *__stream;
  undefined4 *puVar21;
  undefined4 *puVar22;
  bool bVar23;
  undefined4 local_40c8;
  undefined4 local_40c4;
  undefined4 local_40c0;
  undefined4 uStack_40bc;
  int local_40b8;
  int local_40b4;
  char *local_40b0;
  undefined4 local_40ac;
  undefined4 uStack_40a8;
  undefined4 uStack_40a4;
  undefined4 local_40a0;
  undefined4 uStack_409c;
  undefined4 uStack_4098;
  undefined4 uStack_4094;
  undefined4 uStack_4090;
  undefined1 auStack_4088 [8];
  undefined4 local_4080;
  undefined4 local_407c;
  int local_4078;
  int local_4074;
  short local_4070;
  undefined4 *local_406c;
  int local_4068;
  undefined1 *local_4060;
  int local_405c;
  undefined4 local_404c;
  undefined4 uStack_4048;
  undefined4 local_4044;
  undefined4 local_4034;
  undefined4 local_4030;
  undefined4 local_402c [2048];
  undefined1 auStack_202c [8192];
  int iStack_2c;
  
  iStack_2c = __stack_chk_guard;
  if (param_1 == (undefined4 *)0x0) goto LAB_001be954;
  iVar2 = param_1[9];
  bVar23 = iVar2 == -1;
  if (bVar23) {
    iVar2 = param_1[5];
    param_2 = param_1[6];
  }
  bVar23 = !bVar23 || param_2 != iVar2;
  iVar2 = param_1[10];
  if (iVar2 < 1) {
    sVar19 = 0;
  }
  else {
    sVar19 = 0;
    piVar9 = (int *)(param_1[0xc] + 0x10);
    do {
      if ((piVar9[-4] != 0) || (*piVar9 != -1)) {
        bVar23 = true;
      }
      if (piVar9[-4] != 1) {
        sVar19 = sVar19 + 1;
      }
      iVar2 = iVar2 + -1;
      piVar9 = piVar9 + 5;
    } while (iVar2 != 0);
  }
  if (bVar23) {
    if (sVar19 != 0) {
      __base = malloc(sVar19 << 3);
      if (__base == (char *)0x0) goto LAB_001be954;
      puVar3 = param_1 + 2;
      piVar9 = (int *)_zip_cdir_new(sVar19,puVar3);
      if (piVar9 != (int *)0x0) {
        if (0 < (int)sVar19) {
          iVar2 = 0;
          sVar16 = sVar19;
          do {
            _zip_dirent_init(*piVar9 + iVar2);
            sVar16 = sVar16 - 1;
            iVar2 = iVar2 + 0x3c;
          } while (sVar16 != 0);
        }
        iVar2 = zip_get_archive_flag(param_1,1,0);
        if (iVar2 == 0) {
          iVar2 = zip_get_archive_flag(param_1,1,8);
          if (iVar2 != 0) goto LAB_001be24a;
          if (param_1[9] == -1) {
            iVar2 = param_1[7];
            if ((iVar2 == 0) || (*(int *)(iVar2 + 0x10) == 0)) goto LAB_001be24a;
            iVar2 = _zip_memdup(*(int *)(iVar2 + 0x10),*(undefined2 *)(iVar2 + 0x14),puVar3);
            piVar9[4] = iVar2;
            if (iVar2 != 0) {
              uVar1 = *(undefined2 *)(param_1[7] + 0x14);
              goto LAB_001be220;
            }
          }
          else {
            iVar2 = _zip_memdup(param_1[8],param_1[9],puVar3);
            piVar9[4] = iVar2;
            if (iVar2 != 0) {
              uVar1 = (undefined2)param_1[9];
LAB_001be220:
              *(undefined2 *)(piVar9 + 5) = uVar1;
              goto LAB_001be24a;
            }
          }
        }
        else {
          iVar2 = _zip_memdup("TORRENTZIPPED-XXXXXXXX",0x16,puVar3);
          piVar9[4] = iVar2;
          if (iVar2 == 0) goto LAB_001be944;
          *(undefined2 *)(piVar9 + 5) = 0x16;
LAB_001be24a:
          __s = (char *)*param_1;
          sVar16 = strlen(__s);
          __template = malloc(sVar16 + 8);
          if (__template == (char *)0x0) {
            _zip_error_set(puVar3,0xe,0);
          }
          else {
            FUN_001d65d0(__template,"%s.XXXXXX",__s);
            iVar2 = mkstemp(__template);
            if (iVar2 == -1) {
              puVar21 = (undefined4 *)__errno();
              _zip_error_set(puVar3,0xc,*puVar21);
            }
            else {
              pFVar4 = fdopen(iVar2,"r+b");
              if (pFVar4 != (FILE *)0x0) {
                iVar2 = param_1[10];
                if (0 < iVar2) {
                  iVar17 = 0;
                  iVar12 = 0;
                  iVar20 = 0;
                  do {
                    if (*(int *)(param_1[0xc] + iVar17) != 1) {
                      *(int *)(__base + iVar20 * 8) = iVar12;
                      uVar5 = zip_get_name(param_1,iVar12,0);
                      iVar2 = iVar20 * 8;
                      iVar20 = iVar20 + 1;
                      *(undefined4 *)(__base + iVar2 + 4) = uVar5;
                      iVar2 = param_1[10];
                    }
                    iVar12 = iVar12 + 1;
                    iVar17 = iVar17 + 0x14;
                  } while (iVar12 < iVar2);
                }
                iVar2 = zip_get_archive_flag(param_1,1,0);
                if (iVar2 != 0) {
                  qsort(__base,sVar19,8,(__compar_fn_t)&LAB_001beaf8_1);
                }
                bVar23 = false;
                iVar2 = zip_get_archive_flag(param_1,1,0);
                if ((iVar2 == 1) && (iVar2 = zip_get_archive_flag(param_1,1,8), iVar2 == 0)) {
                  bVar23 = true;
                }
                if (0 < (int)sVar19) {
                  iVar2 = 0;
                  do {
                    iVar12 = *(int *)(__base + iVar2 * 8);
                    if ((*(uint *)(param_1[0xc] + iVar12 * 0x14) & 0xfffffffe) != 2 && !bVar23) {
                      iVar17 = fseeko((FILE *)param_1[1],
                                      *(__off_t *)(*(int *)param_1[7] + iVar12 * 0x3c + 0x38),0);
                      if (iVar17 == 0) {
                        iVar17 = _zip_dirent_read(&local_40c8,param_1[1],0,0,1,puVar3);
                        if (iVar17 == 0) {
                          puVar21 = (undefined4 *)(*(int *)param_1[7] + iVar12 * 0x3c);
                          puVar22 = (undefined4 *)(*piVar9 + iVar2 * 0x3c);
                          uVar5 = puVar21[1];
                          uVar11 = puVar21[2];
                          uVar13 = puVar21[3];
                          uVar18 = puVar21[4];
                          *puVar22 = *puVar21;
                          puVar22[1] = uVar5;
                          puVar22[2] = uVar11;
                          puVar22[3] = uVar13;
                          puVar22[4] = uVar18;
                          uVar5 = puVar21[6];
                          uVar11 = puVar21[7];
                          uVar13 = puVar21[8];
                          uVar18 = puVar21[9];
                          puVar22[5] = puVar21[5];
                          puVar22[6] = uVar5;
                          puVar22[7] = uVar11;
                          puVar22[8] = uVar13;
                          puVar22[9] = uVar18;
                          uVar5 = puVar21[0xb];
                          uVar11 = puVar21[0xc];
                          uVar13 = puVar21[0xd];
                          uVar18 = puVar21[0xe];
                          puVar22[10] = puVar21[10];
                          puVar22[0xb] = uVar5;
                          puVar22[0xc] = uVar11;
                          puVar22[0xd] = uVar13;
                          puVar22[0xe] = uVar18;
                          if ((local_40c4 & 8) != 0) {
                            iVar17 = *(int *)param_1[7] + iVar12 * 0x3c;
                            uStack_40bc = *(undefined4 *)(iVar17 + 0xc);
                            local_40b8 = *(int *)(iVar17 + 0x10);
                            local_40b4 = *(int *)(iVar17 + 0x14);
                            local_40c4 = local_40c4 & 0xfffffff7;
                            iVar17 = *piVar9 + iVar2 * 0x3c;
                            *(ushort *)(iVar17 + 4) = *(ushort *)(iVar17 + 4) & 0xfff7;
                          }
                          goto LAB_001be4b6;
                        }
                        goto LAB_001bea7e;
                      }
                      puVar8 = (uint *)__errno();
                      uVar14 = *puVar8;
LAB_001bea78:
                      uVar5 = 4;
                      goto LAB_001bea7a;
                    }
                    _zip_dirent_init(&local_40c8);
                    iVar17 = zip_get_archive_flag(param_1,1,0);
                    if (iVar17 != 0) {
                      _zip_dirent_torrent_normalize(&local_40c8);
                    }
                    puVar21 = (undefined4 *)(*piVar9 + iVar2 * 0x3c);
                    *puVar21 = local_40c8;
                    puVar21[1] = local_40c4;
                    puVar21[2] = local_40c0;
                    puVar21[3] = uStack_40bc;
                    puVar21[4] = local_40b8;
                    puVar21[5] = local_40b4;
                    puVar21[6] = local_40b0;
                    puVar21[7] = local_40ac;
                    puVar21[8] = uStack_40a8;
                    puVar21[9] = uStack_40a4;
                    puVar21[10] = local_40a0;
                    puVar21[0xb] = uStack_409c;
                    puVar21[0xc] = uStack_4098;
                    puVar21[0xd] = uStack_4094;
                    puVar21[0xe] = uStack_4090;
                    if (*(int *)(param_1[0xc] + iVar12 * 0x14 + 8) == 0) {
                      if (*(int *)(param_1[0xc] + iVar12 * 0x14) == 3) {
                        local_40b0 = strdup("-");
                        local_40ac = CONCAT22(local_40ac._2_2_,1);
                        iVar17 = *piVar9 + iVar2 * 0x3c;
                        *(undefined **)(iVar17 + 0x18) = &DAT_0021f779;
                        *(undefined2 *)(iVar17 + 0x1c) = 1;
                      }
                      else {
                        local_40b0 = strdup(*(char **)(*(int *)param_1[7] + iVar12 * 0x3c + 0x18));
                        sVar16 = strlen(local_40b0);
                        local_40ac = CONCAT22(local_40ac._2_2_,(short)sVar16);
                        iVar17 = *piVar9 + iVar2 * 0x3c;
                        *(undefined4 *)(iVar17 + 0x18) =
                             *(undefined4 *)(*(int *)param_1[7] + iVar12 * 0x3c + 0x18);
                        *(short *)(iVar17 + 0x1c) = (short)sVar16;
                      }
                    }
LAB_001be4b6:
                    if (*(int *)(param_1[0xc] + iVar12 * 0x14 + 8) != 0) {
                      free(local_40b0);
                      local_40b0 = strdup(*(char **)(param_1[0xc] + iVar12 * 0x14 + 8));
                      if (local_40b0 == (char *)0x0) goto LAB_001bea7e;
                      sVar16 = strlen(local_40b0);
                      local_40ac = CONCAT22(local_40ac._2_2_,(short)sVar16);
                      iVar17 = *piVar9 + iVar2 * 0x3c;
                      *(undefined4 *)(iVar17 + 0x18) =
                           *(undefined4 *)(param_1[0xc] + iVar12 * 0x14 + 8);
                      *(short *)(iVar17 + 0x1c) = (short)sVar16;
                    }
                    iVar17 = zip_get_archive_flag(param_1,1,0);
                    if (iVar17 == 0) {
                      iVar20 = param_1[0xc] + iVar12 * 0x14;
                      iVar17 = *(int *)(iVar20 + 0x10);
                      if (iVar17 != -1) {
                        iVar10 = *piVar9 + iVar2 * 0x3c;
                        *(undefined4 *)(iVar10 + 0x28) = *(undefined4 *)(iVar20 + 0xc);
                        *(short *)(iVar10 + 0x2c) = (short)iVar17;
                      }
                    }
                    _Var6 = ftello(pFVar4);
                    *(__off_t *)(*piVar9 + iVar2 * 0x3c + 0x38) = _Var6;
                    uVar14 = *(uint *)(param_1[0xc] + iVar12 * 0x14) & 0xfffffffe;
                    if (uVar14 == 2 || bVar23) {
                      if (uVar14 == 2) {
                        puVar21 = *(undefined4 **)(param_1[0xc] + iVar12 * 0x14 + 4);
                      }
                      else {
                        puVar21 = (undefined4 *)
                                  zip_source_zip(param_1,param_1,iVar12,0x10,0,0xffffffff);
                        if (puVar21 == (undefined4 *)0x0) goto LAB_001bea7e;
                      }
                      pcVar15 = (code *)*puVar21;
                      uVar5 = puVar21[1];
                      iVar12 = (*pcVar15)(uVar5,auStack_4088,0x1c,3);
                      if ((iVar12 < 0x1c) || (iVar12 = (*pcVar15)(uVar5,0,0,0), iVar12 < 0)) {
                        iVar2 = (*pcVar15)(uVar5,&local_4034,8,4);
                      }
                      else {
                        _Var6 = ftello(pFVar4);
                        iVar12 = _zip_dirent_write(&local_40c8,pFVar4,1,puVar3);
                        if (iVar12 < 0) goto LAB_001bea7e;
                        if (local_4070 == 0) {
                          local_4070 = 8;
                          local_4078 = 0;
                          local_4074 = 0;
                          local_4080 = crc32(0,0,0);
                          local_404c = 0;
                          uStack_4048 = 0;
                          local_4044 = 0;
                          local_4068 = 0;
                          local_405c = 0;
                          iVar12 = zip_get_archive_flag(param_1,1,0);
                          uVar11 = 8;
                          if (iVar12 == 0) {
                            uVar11 = 9;
                          }
                          deflateInit2_(&local_406c,9,8,0xfffffff1,uVar11,0,"1.2.3",0x38);
                          iVar12 = 0;
                          local_4060 = auStack_202c;
                          local_405c = 0x2000;
                          local_406c = (undefined4 *)0x0;
                          local_4068 = 0;
                          do {
                            if (iVar12 == 0 && local_4068 == 0) {
                              iVar17 = (*pcVar15)(uVar5,local_402c,0x2000,1);
                              if (iVar17 < 0) {
                                iVar2 = (*pcVar15)(uVar5,&local_4034,8,4);
                                if (iVar2 < 8) {
                                  local_4034 = 0x14;
                                  local_4030 = 0;
                                }
                                param_1[2] = local_4034;
                                param_1[3] = local_4030;
                                deflateEnd(&local_406c);
                                goto LAB_001bea7e;
                              }
                              if (iVar17 == 0) {
                                iVar12 = 4;
                              }
                              else {
                                local_4078 = local_4078 + iVar17;
                                local_406c = local_402c;
                                local_4068 = iVar17;
                                local_4080 = crc32(local_4080,local_402c);
                              }
                            }
                            uVar14 = deflate(&local_406c,iVar12);
                            if (1 < uVar14) {
                              uVar5 = 0xd;
                              goto LAB_001bea7a;
                            }
                            if (local_405c != 0x2000) {
                              sVar7 = 0x2000 - local_405c;
                              sVar16 = fwrite(auStack_202c,1,sVar7,pFVar4);
                              if (sVar16 != sVar7) goto LAB_001be974;
                              local_405c = 0x2000;
                              local_4074 = local_4074 + sVar7;
                              local_4060 = auStack_202c;
                            }
                          } while (uVar14 != 1);
                          deflateEnd(&local_406c);
LAB_001be7ac:
                          iVar12 = (*pcVar15)(uVar5,0,0,2);
                          if (-1 < iVar12) {
                            __off = ftello(pFVar4);
                            iVar12 = fseeko(pFVar4,_Var6,0);
                            if (-1 < iVar12) {
                              local_40c0 = local_407c;
                              local_40c4 = CONCAT22(local_4070,(undefined2)local_40c4);
                              uStack_40bc = local_4080;
                              local_40b4 = local_4078;
                              local_40b8 = local_4074;
                              iVar12 = zip_get_archive_flag(param_1,1,0);
                              if (iVar12 != 0) {
                                _zip_dirent_torrent_normalize(&local_40c8);
                              }
                              iVar12 = _zip_dirent_write(&local_40c8,pFVar4,1,puVar3);
                              if (iVar12 < 0) goto LAB_001bea7e;
                              iVar12 = fseeko(pFVar4,__off,0);
                              if (-1 < iVar12) {
                                iVar12 = *piVar9 + iVar2 * 0x3c;
                                *(undefined2 *)(iVar12 + 6) = local_40c4._2_2_;
                                *(ulonglong *)(iVar12 + 8) = CONCAT44(uStack_40bc,local_40c0);
                                *(ulonglong *)(iVar12 + 0x10) = CONCAT44(local_40b4,local_40b8);
                                goto LAB_001be84c;
                              }
                            }
                            puVar8 = (uint *)__errno();
                            uVar14 = *puVar8;
                            goto LAB_001bea78;
                          }
                        }
                        else {
                          local_4074 = 0;
                          sVar16 = (*pcVar15)(uVar5,local_402c,0x2000,1);
                          if (0 < (int)sVar16) {
                            do {
                              sVar7 = fwrite(local_402c,1,sVar16,pFVar4);
                              if (sVar7 != sVar16) goto LAB_001be974;
                              local_4074 = local_4074 + sVar16;
                              sVar16 = (*pcVar15)(uVar5,local_402c,0x2000,1);
                            } while (0 < (int)sVar16);
                          }
                          if (-1 < (int)sVar16) goto LAB_001be7ac;
                        }
                        iVar2 = (*pcVar15)(uVar5,&local_4034,8,4);
                      }
                      if (iVar2 < 8) {
                        local_4034 = 0x14;
                        local_4030 = 0;
                      }
                      param_1[2] = local_4034;
                      param_1[3] = local_4030;
                      goto LAB_001bea7e;
                    }
                    iVar12 = _zip_dirent_write(&local_40c8,pFVar4,1,puVar3);
                    if (iVar12 < 0) goto LAB_001bea7e;
                    uVar14 = *(uint *)(*piVar9 + iVar2 * 0x3c + 0x10);
                    if (0 < (int)uVar14) {
                      __stream = (FILE *)param_1[1];
                      do {
                        __n = uVar14;
                        if (0x2000 < uVar14) {
                          __n = 0x2000;
                        }
                        sVar16 = fread(auStack_202c,1,__n,__stream);
                        if ((int)sVar16 < 0) {
                          puVar8 = (uint *)__errno();
                          uVar14 = *puVar8;
                          uVar5 = 5;
                          goto LAB_001bea7a;
                        }
                        if (sVar16 == 0) {
                          uVar5 = 0x11;
                          uVar14 = 0;
                          goto LAB_001bea7a;
                        }
                        sVar7 = fwrite(auStack_202c,1,sVar16,pFVar4);
                        if (sVar7 != sVar16) goto LAB_001be974;
                        uVar14 = uVar14 - sVar16;
                      } while (0 < (int)uVar14);
                    }
LAB_001be84c:
                    _zip_dirent_finalize(&local_40c8);
                    iVar2 = iVar2 + 1;
                  } while (iVar2 < (int)sVar19);
                }
                free(__base);
                iVar2 = _zip_cdir_write(piVar9,pFVar4,puVar3);
                if (iVar2 < 0) {
LAB_001bea86:
                  piVar9[1] = 0;
                  _zip_cdir_free(piVar9);
                  _zip_dirent_finalize(&local_40c8);
                  fclose(pFVar4);
                }
                else {
                  iVar2 = zip_get_archive_flag(param_1,1,0);
                  if (iVar2 != 0) {
                    _Var6 = ftello(pFVar4);
                    iVar2 = _zip_filerange_crc(pFVar4,piVar9[3],piVar9[2],local_402c,puVar3);
                    if (-1 < iVar2) {
                      FUN_001d6588(auStack_202c,9,"%08lX",local_402c[0]);
                      iVar2 = fseeko(pFVar4,_Var6 + -8,0);
                      if (iVar2 < 0) {
                        puVar21 = (undefined4 *)__errno();
                        uVar11 = *puVar21;
                        uVar5 = 4;
                      }
                      else {
                        sVar19 = fwrite(auStack_202c,8,1,pFVar4);
                        if (sVar19 == 1) goto LAB_001be8e4;
                        puVar21 = (undefined4 *)__errno();
                        uVar11 = *puVar21;
                        uVar5 = 6;
                      }
                      _zip_error_set(puVar3,uVar5,uVar11);
                    }
                    goto LAB_001bea86;
                  }
LAB_001be8e4:
                  piVar9[1] = 0;
                  _zip_cdir_free(piVar9);
                  iVar2 = fclose(pFVar4);
                  if (iVar2 == 0) {
                    pFVar4 = (FILE *)param_1[1];
                    if (pFVar4 != (FILE *)0x0) {
                      fclose(pFVar4);
                      param_1[1] = 0;
                    }
                    iVar2 = rename(__template,(char *)*param_1);
                    if (iVar2 == 0) {
                      __mask = umask(0);
                      umask(__mask);
                      chmod((char *)*param_1,~__mask & 0x1b6);
                      _zip_free(param_1);
                      free(__template);
                    }
                    else {
                      puVar21 = (undefined4 *)__errno();
                      _zip_error_set(puVar3,2,*puVar21);
                      remove(__template);
                      free(__template);
                      if (pFVar4 != (FILE *)0x0) {
                        pFVar4 = fopen((char *)*param_1,"rb");
                        param_1[1] = pFVar4;
                      }
                    }
                    goto LAB_001be954;
                  }
                  puVar21 = (undefined4 *)__errno();
                  _zip_error_set(puVar3,3,*puVar21);
                }
                remove(__template);
                __base = __template;
                goto LAB_001be94c;
              }
              puVar21 = (undefined4 *)__errno();
              _zip_error_set(puVar3,0xc,*puVar21);
              close(iVar2);
              remove(__template);
            }
            free(__template);
          }
        }
LAB_001be944:
        _zip_cdir_free(piVar9);
      }
LAB_001be94c:
      free(__base);
      goto LAB_001be954;
    }
    if ((((char *)*param_1 != (char *)0x0) && (param_1[1] != 0)) &&
       (iVar2 = remove((char *)*param_1), iVar2 != 0)) {
      puVar3 = (undefined4 *)__errno();
      _zip_error_set(param_1 + 2,0x16,*puVar3);
      goto LAB_001be954;
    }
  }
  _zip_free(param_1);
LAB_001be954:
  if (__stack_chk_guard - iStack_2c != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - iStack_2c);
  }
  return;
LAB_001be974:
  puVar8 = (uint *)__errno();
  uVar14 = *puVar8;
  uVar5 = 6;
LAB_001bea7a:
  _zip_error_set(puVar3,uVar5,uVar14);
LAB_001bea7e:
  free(__base);
  goto LAB_001bea86;
}

// ===== zip_add_dir  @0x001beb00  (160 bytes)
uint zip_add_dir(int param_1,char *param_2)

{
  size_t sVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  char *__dest;
  
  if (param_2 == (char *)0x0) {
    uVar4 = 0x12;
LAB_001beb8e:
    _zip_error_set(param_1 + 8,uVar4,0);
  }
  else {
    sVar1 = strlen(param_2);
    if (param_2[sVar1 - 1] == '/') {
      __dest = (char *)0x0;
    }
    else {
      __dest = malloc(sVar1 + 2);
      if (__dest == (char *)0x0) {
        uVar4 = 0xe;
        goto LAB_001beb8e;
      }
      strcpy(__dest,param_2);
      (__dest + sVar1)[0] = '/';
      (__dest + sVar1)[1] = '\0';
    }
    iVar2 = zip_source_buffer(param_1,0,0,0);
    if (iVar2 != 0) {
      if (__dest != (char *)0x0) {
        param_2 = __dest;
      }
      uVar3 = _zip_replace(param_1,0xffffffff,param_2,iVar2);
      free(__dest);
      if (uVar3 < 0x80000000) {
        return uVar3;
      }
      zip_source_free(iVar2);
      return uVar3;
    }
    free(__dest);
  }
  return 0xffffffff;
}

// ===== zip_error_get_sys_type  @0x001beba0  (34 bytes)
undefined4 zip_error_get_sys_type(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (-1 < param_1) {
    if (0x17 < param_1) {
      return 0;
    }
    uVar1 = *(undefined4 *)(_zip_err_type + param_1 * 4);
  }
  return uVar1;
}

// ===== zip_set_archive_comment  @0x001bebcc  (76 bytes)
undefined4 zip_set_archive_comment(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_3 < 0x10001) && ((param_2 != 0 || (param_3 == 0)))) {
    if (param_3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = _zip_memdup(param_2,param_3,param_1 + 8);
      if (iVar2 == 0) goto LAB_001bebec;
    }
    free(*(void **)(param_1 + 0x20));
    *(int *)(param_1 + 0x20) = iVar2;
    *(uint *)(param_1 + 0x24) = param_3;
    uVar1 = 0;
  }
  else {
    _zip_error_set(param_1 + 8,0x12,0);
LAB_001bebec:
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

// ===== zip_name_locate  @0x001bec18  (10 bytes)
void zip_name_locate(void)

{
  _zip_name_locate();
  return;
}

// ===== _zip_name_locate  @0x001bec20  (176 bytes)
int _zip_name_locate(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char *__s;
  int iVar6;
  int iVar7;
  code *pcVar8;
  
  if (param_2 == 0) {
    uVar4 = 0x12;
  }
  else {
    pcVar8 = strcmp;
    if ((param_3 & 1) != 0) {
      pcVar8 = strcasecmp;
    }
    if ((param_3 & 8) == 0) {
      piVar1 = (int *)(param_1 + 0x28);
    }
    else {
      piVar1 = (int *)(*(int *)(param_1 + 0x1c) + 4);
    }
    iVar6 = *piVar1;
    if (0 < iVar6) {
      iVar5 = 0;
      iVar7 = 0x18;
      do {
        if ((param_3 & 8) == 0) {
          __s = (char *)_zip_get_name(param_1,iVar5,param_3,param_4);
        }
        else {
          __s = *(char **)(**(int **)(param_1 + 0x1c) + iVar7);
        }
        if (__s != (char *)0x0) {
          if (((param_3 & 2) != 0) && (pcVar2 = strrchr(__s,0x2f), pcVar2 != (char *)0x0)) {
            __s = pcVar2 + 1;
          }
          iVar3 = (*pcVar8)(param_2,__s);
          if (iVar3 == 0) {
            return iVar5;
          }
        }
        iVar5 = iVar5 + 1;
        iVar7 = iVar7 + 0x3c;
      } while (iVar5 < iVar6);
    }
    uVar4 = 9;
  }
  _zip_error_set(param_4,uVar4,0);
  return -1;
}

// ===== zip_unchange_archive  @0x001becd8  (30 bytes)
undefined4 zip_unchange_archive(int param_1)

{
  free(*(void **)(param_1 + 0x20));
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x14);
  return 0;
}

// ===== zip_source_free  @0x001becf6  (32 bytes)
void zip_source_free(undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  (*(code *)*param_1)(param_1[1],0,0,5);
  free(param_1);
  return;
}

// ===== zip_get_num_files  @0x001bed16  (12 bytes)
undefined4 zip_get_num_files(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x28);
  }
  return uVar1;
}

// ===== zip_source_filep  @0x001bed22  (56 bytes)
undefined4 zip_source_filep(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    if ((param_2 != 0) && (-1 < param_3 && -2 < param_4)) {
      uVar1 = _zip_source_file_or_p(param_1,0,param_2,param_3,param_4);
      return uVar1;
    }
    _zip_error_set(param_1 + 8,0x12,0);
  }
  return 0;
}

// ===== _zip_source_file_or_p  @0x001bed5c  (144 bytes)
int _zip_source_file_or_p(int param_1,char *param_2,int param_3,undefined4 param_4,int param_5)

{
  undefined4 *__ptr;
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_2 == (char *)0x0) && (param_3 == 0)) {
    uVar3 = 0x12;
  }
  else {
    __ptr = malloc(0x1c);
    if (__ptr != (undefined4 *)0x0) {
      *__ptr = 0;
      if (param_2 != (char *)0x0) {
        pcVar1 = strdup(param_2);
        *__ptr = pcVar1;
        if (pcVar1 == (char *)0x0) {
          _zip_error_set(param_1 + 8,0xe,0);
          free(__ptr);
          return 0;
        }
      }
      if (param_5 == 0) {
        param_5 = -1;
      }
      __ptr[1] = param_3;
      __ptr[2] = param_4;
      __ptr[3] = param_5;
      iVar2 = zip_source_function(param_1,0x1bedf1,__ptr);
      if (iVar2 != 0) {
        return iVar2;
      }
      free(__ptr);
      return 0;
    }
    uVar3 = 0xe;
  }
  _zip_error_set(param_1 + 8,uVar3,0);
  return 0;
}

// ===== _zip_error_clear  @0x001bef28  (8 bytes)
void _zip_error_clear(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return;
}

// ===== _zip_error_copy  @0x001bef30  (10 bytes)
void _zip_error_copy(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  return;
}

// ===== _zip_error_fini  @0x001bef3a  (18 bytes)
void _zip_error_fini(int param_1)

{
  free(*(void **)(param_1 + 8));
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

// ===== _zip_error_get  @0x001bef4c  (34 bytes)
void _zip_error_get(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *param_1;
  }
  if (param_3 != (undefined4 *)0x0) {
    iVar1 = zip_error_get_sys_type(*param_1);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = param_1[1];
    }
    *param_3 = uVar2;
  }
  return;
}

// ===== _zip_error_init  @0x001bef6e  (10 bytes)
void _zip_error_init(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}

// ===== _zip_error_set  @0x001bef78  (8 bytes)
void _zip_error_set(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = param_2;
    param_1[1] = param_3;
  }
  return;
}

// ===== zip_strerror  @0x001bef80  (8 bytes)
void zip_strerror(int param_1)

{
  _zip_error_strerror(param_1 + 8);
  return;
}

// ===== _zip_entry_new  @0x001bef86  (116 bytes)
undefined4 * _zip_entry_new(int param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_1 == 0) {
    puVar3 = malloc(0x14);
    if (puVar3 == (undefined4 *)0x0) {
      param_1 = 8;
LAB_001befee:
      _zip_error_set(param_1,0xe,0);
      return (undefined4 *)0x0;
    }
  }
  else {
    iVar2 = *(int *)(param_1 + 0x28);
    if (iVar2 < *(int *)(param_1 + 0x2c) + -1) {
      pvVar1 = *(void **)(param_1 + 0x30);
    }
    else {
      iVar2 = *(int *)(param_1 + 0x2c) + 0x10;
      *(int *)(param_1 + 0x2c) = iVar2;
      pvVar1 = realloc(*(void **)(param_1 + 0x30),iVar2 * 0x14);
      *(void **)(param_1 + 0x30) = pvVar1;
      if (pvVar1 == (void *)0x0) {
        param_1 = param_1 + 8;
        goto LAB_001befee;
      }
      iVar2 = *(int *)(param_1 + 0x28);
    }
    puVar3 = (undefined4 *)((int)pvVar1 + iVar2 * 0x14);
  }
  *puVar3 = 0;
  puVar3[1] = 0;
  puVar3[2] = 0;
  puVar3[3] = 0;
  puVar3[4] = 0xffffffff;
  if (param_1 != 0) {
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
  }
  return puVar3;
}

// ===== zip_get_archive_flag  @0x001beffa  (24 bytes)
bool zip_get_archive_flag(int param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 + 0x14);
  if ((param_3 & 8) == 0) {
    puVar1 = (uint *)(param_1 + 0x18);
  }
  return (*puVar1 & param_2) != 0;
}

// ===== zip_set_archive_flag  @0x001bf012  (18 bytes)
undefined4 zip_set_archive_flag(int param_1,uint param_2,int param_3)

{
  if (param_3 == 0) {
    param_2 = *(uint *)(param_1 + 0x18) & ~param_2;
  }
  else {
    param_2 = param_2 | *(uint *)(param_1 + 0x18);
  }
  *(uint *)(param_1 + 0x18) = param_2;
  return 0;
}

// ===== _zip_unchange_data  @0x001bf024  (44 bytes)
void _zip_unchange_data(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)param_1[1];
  if (puVar1 != (undefined4 *)0x0) {
    (*(code *)*puVar1)(puVar1[1],0,0,5);
    free((void *)param_1[1]);
    param_1[1] = 0;
  }
  uVar2 = 0;
  if (param_1[2] != 0) {
    uVar2 = 4;
  }
  *param_1 = uVar2;
  return;
}

// ===== zip_fread  @0x001bf050  (292 bytes)
uint zip_fread(int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 4) != 0)) {
    return 0xffffffff;
  }
  if (param_3 == 0) {
    return 0;
  }
  uVar1 = *(uint *)(param_1 + 0x10);
  if ((uVar1 & 1) != 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x1c) == 0) {
    *(uint *)(param_1 + 0x10) = uVar1 | 1;
    if ((uVar1 & 4) != 0) {
LAB_001bf14c:
      if (*(int *)(param_1 + 0x24) != *(int *)(param_1 + 0x28)) {
        uVar6 = 7;
LAB_001bf16c:
        uVar2 = 0;
LAB_001bf16e:
        _zip_error_set((int *)(param_1 + 4),uVar6,uVar2);
        return 0xffffffff;
      }
    }
    return 0;
  }
  if ((uVar1 & 2) != 0) {
    puVar4 = *(undefined4 **)(param_1 + 0x30);
    puVar4[3] = param_2;
    puVar4[4] = param_3;
    iVar3 = puVar4[5];
LAB_001bf0da:
    do {
      uVar2 = inflate(puVar4,2);
      switch(uVar2) {
      case 0:
        puVar4 = *(undefined4 **)(param_1 + 0x30);
        iVar7 = puVar4[5];
        goto LAB_001bf122;
      case 1:
        puVar4 = *(undefined4 **)(param_1 + 0x30);
        iVar7 = puVar4[5];
        if (iVar7 != iVar3) goto LAB_001bf122;
        goto LAB_001bf14c;
      case 0xfffffffb:
        if (*(int *)(*(int *)(param_1 + 0x30) + 4) == 0) {
          iVar7 = _zip_file_fillbuf(*(undefined4 *)(param_1 + 0x2c),0x2000,param_1);
          if (iVar7 == 0) {
            uVar6 = 0x15;
            goto LAB_001bf16c;
          }
          if (iVar7 < 0) {
            return 0xffffffff;
          }
          puVar4 = *(undefined4 **)(param_1 + 0x30);
          *puVar4 = *(undefined4 *)(param_1 + 0x2c);
          puVar4[1] = iVar7;
          break;
        }
        uVar2 = 0xfffffffb;
      case 0xfffffffc:
      case 0xfffffffd:
      case 0xfffffffe:
      case 2:
        uVar6 = 0xd;
        goto LAB_001bf16e;
      default:
        puVar4 = *(undefined4 **)(param_1 + 0x30);
      }
    } while( true );
  }
  uVar1 = _zip_file_fillbuf(param_2,param_3,param_1);
  if ((int)uVar1 < 1) {
    return uVar1;
  }
  if ((*(byte *)(param_1 + 0x10) & 4) != 0) {
    uVar2 = crc32(*(undefined4 *)(param_1 + 0x24),param_2,uVar1);
    *(undefined4 *)(param_1 + 0x24) = uVar2;
  }
  iVar3 = *(int *)(param_1 + 0x1c) - uVar1;
LAB_001bf148:
  *(int *)(param_1 + 0x1c) = iVar3;
  return uVar1;
LAB_001bf122:
  uVar5 = *(uint *)(param_1 + 0x1c);
  uVar1 = iVar7 - iVar3;
  if (uVar5 <= uVar1 || param_3 <= uVar1) goto code_r0x001bf130;
  goto LAB_001bf0da;
code_r0x001bf130:
  if ((*(byte *)(param_1 + 0x10) & 4) != 0) {
    uVar2 = crc32(*(undefined4 *)(param_1 + 0x24),param_2,uVar1);
    *(undefined4 *)(param_1 + 0x24) = uVar2;
    uVar5 = *(uint *)(param_1 + 0x1c);
  }
  iVar3 = uVar5 - uVar1;
  goto LAB_001bf148;
}

// ===== zip_rename  @0x001bf17c  (134 bytes)
undefined4 zip_rename(int param_1,int param_2,char *param_3)

{
  char cVar1;
  char *__s;
  size_t sVar2;
  undefined4 uVar3;
  
  if (((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x28))) && (*param_3 != '\0')) {
    __s = (char *)zip_get_name(param_1,param_2,0);
    if (__s == (char *)0x0) {
      return 0xffffffff;
    }
    sVar2 = strlen(param_3);
    cVar1 = param_3[sVar2 - 1];
    sVar2 = strlen(__s);
    if ((cVar1 == '/') == (__s[sVar2 - 1] == '/')) {
      uVar3 = _zip_set_name(param_1,param_2,param_3);
      return uVar3;
    }
  }
  _zip_error_set(param_1 + 8,0x12,0);
  return 0xffffffff;
}

// ===== zip_source_zip  @0x001bf200  (320 bytes)
void zip_source_zip(int param_1,int param_2,int param_3,uint param_4,int param_5,int param_6)

{
  int *__ptr;
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int unaff_r11;
  undefined1 auStack_34 [12];
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (param_1 == 0) goto LAB_001bf31c;
  if ((param_3 < 0) || (param_2 == 0)) {
LAB_001bf25e:
    uVar2 = 0x12;
  }
  else {
    if (param_5 >= 0) {
      unaff_r11 = param_6;
    }
    if ((param_5 < 0 || unaff_r11 < -1) || (*(int *)(param_2 + 0x28) <= param_3)) goto LAB_001bf25e;
    if (((param_4 & 8) == 0) &&
       ((*(uint *)(*(int *)(param_2 + 0x30) + param_3 * 0x14) & 0xfffffffe) == 2)) {
      uVar2 = 0xf;
    }
    else {
      if (unaff_r11 == 0) {
        unaff_r11 = -1;
      }
      uVar3 = param_4 & 0xfffffffb;
      if (unaff_r11 == -1) {
        uVar3 = param_4 | 4;
      }
      if ((param_4 & 0x10) != 0 || param_5 != 0) {
        uVar3 = param_4 & 0xfffffffb;
      }
      __ptr = malloc(0x28);
      if (__ptr != (int *)0x0) {
        _zip_error_copy(auStack_34);
        iVar1 = zip_stat_index(param_2,param_3,uVar3,__ptr + 1);
        if (-1 < iVar1) {
          iVar1 = zip_fopen_index(param_2,param_3,uVar3);
          *__ptr = iVar1;
          if (iVar1 != 0) {
            __ptr[8] = param_5;
            __ptr[9] = unaff_r11;
            if ((uVar3 & 4) == 0) {
              __ptr[5] = unaff_r11;
              __ptr[6] = unaff_r11;
              *(undefined2 *)(__ptr + 7) = 0;
              __ptr[3] = 0;
            }
            iVar1 = zip_source_function(param_1,&LAB_001bf34c_1,__ptr);
            if (iVar1 == 0) {
              free(__ptr);
            }
            goto LAB_001bf31c;
          }
        }
        free(__ptr);
        _zip_error_copy(param_1 + 8,param_2 + 8);
        _zip_error_copy(param_2 + 8,auStack_34);
        goto LAB_001bf31c;
      }
      uVar2 = 0xe;
    }
  }
  _zip_error_set(param_1 + 8,uVar2,0);
LAB_001bf31c:
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

// ===== zip_stat_index  @0x001bf448  (208 bytes)
undefined4 zip_stat_index(int param_1,int param_2,uint param_3,int *param_4)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x28))) {
    iVar2 = zip_get_name(param_1,param_2,param_3);
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    if (((param_3 & 8) == 0) &&
       ((*(uint *)(*(int *)(param_1 + 0x30) + param_2 * 0x14) & 0xfffffffe) == 2)) {
      puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x30) + param_2 * 0x14 + 4);
      uVar4 = (*(code *)*puVar3)(puVar3[1],param_4,0x1c,3);
      if (uVar4 < 0x80000000) {
LAB_001bf510:
        *param_4 = iVar2;
        param_4[1] = param_2;
        return 0;
      }
      uVar7 = 0xf;
      goto LAB_001bf4f0;
    }
    piVar5 = *(int **)(param_1 + 0x1c);
    if ((piVar5 != (int *)0x0) && (param_2 < piVar5[1])) {
      iVar6 = *piVar5 + param_2 * 0x3c;
      param_4[2] = *(int *)(iVar6 + 0xc);
      param_4[4] = *(int *)(iVar6 + 0x14);
      param_4[3] = *(int *)(iVar6 + 8);
      param_4[5] = *(int *)(iVar6 + 0x10);
      *(undefined2 *)(param_4 + 6) = *(undefined2 *)(iVar6 + 6);
      if ((*(ushort *)(iVar6 + 4) & 1) == 0) {
        uVar1 = 0;
      }
      else if ((*(ushort *)(iVar6 + 4) & 0x40) == 0) {
        uVar1 = 1;
      }
      else {
        uVar1 = 0xffff;
      }
      *(undefined2 *)((int)param_4 + 0x1a) = uVar1;
      goto LAB_001bf510;
    }
  }
  uVar7 = 0x12;
LAB_001bf4f0:
  _zip_error_set(param_1 + 8,uVar7,0);
  return 0xffffffff;
}

// ===== zip_source_function  @0x001bf518  (54 bytes)
undefined4 * zip_source_function(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  if (param_1 == 0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = malloc(8);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
      _zip_error_set(param_1 + 8,0xe,0);
    }
    else {
      *puVar1 = param_2;
      puVar1[1] = param_3;
    }
  }
  return puVar1;
}

// ===== zip_replace  @0x001bf54e  (50 bytes)
int zip_replace(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (((-1 < param_2) && (param_3 != 0)) && (param_2 < *(int *)(param_1 + 0x28))) {
    iVar1 = _zip_replace(param_1,param_2,0);
    if (iVar1 != -1) {
      iVar1 = 0;
    }
    return iVar1;
  }
  _zip_error_set(param_1 + 8,0x12,0);
  return -1;
}

// ===== _zip_replace  @0x001bf580  (112 bytes)
int _zip_replace(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == -1) {
    iVar1 = _zip_entry_new(param_1);
    if (iVar1 == 0) {
      return -1;
    }
    param_2 = *(int *)(param_1 + 0x28) + -1;
  }
  _zip_unchange_data(*(int *)(param_1 + 0x30) + param_2 * 0x14);
  if ((param_3 != 0) && (iVar1 = _zip_set_name(param_1,param_2,param_3), iVar1 != 0)) {
    return -1;
  }
  if (*(int *)(param_1 + 0x1c) == 0) {
    uVar2 = 3;
  }
  else {
    uVar2 = 2;
    if (*(int *)(*(int *)(param_1 + 0x1c) + 4) <= param_2) {
      uVar2 = 3;
    }
  }
  iVar1 = *(int *)(param_1 + 0x30);
  *(undefined4 *)(iVar1 + param_2 * 0x14) = uVar2;
  *(undefined4 *)(iVar1 + param_2 * 0x14 + 4) = param_4;
  return param_2;
}

// ===== zip_delete  @0x001bf5f0  (68 bytes)
undefined4 zip_delete(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 < 0) || (*(int *)(param_1 + 0x28) <= param_2)) {
    _zip_error_set(param_1 + 8,0x12,0);
  }
  else {
    iVar1 = _zip_unchange(param_1,param_2,1);
    if (iVar1 == 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x30) + param_2 * 0x14) = 1;
      return 0;
    }
  }
  return 0xffffffff;
}

// ===== zip_set_file_comment  @0x001bf634  (118 bytes)
undefined4 zip_set_file_comment(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  
  if ((((-1 < param_2) && (param_4 < 0x10001)) && (param_2 < *(int *)(param_1 + 0x28))) &&
     ((param_3 != 0 || ((int)param_4 < 1)))) {
    if ((int)param_4 < 1) {
      iVar1 = 0;
    }
    else {
      iVar1 = _zip_memdup(param_3,param_4,param_1 + 8);
      if (iVar1 == 0) {
        return 0xffffffff;
      }
    }
    free(*(void **)(*(int *)(param_1 + 0x30) + param_2 * 0x14 + 0xc));
    iVar2 = *(int *)(param_1 + 0x30) + param_2 * 0x14;
    *(int *)(iVar2 + 0xc) = iVar1;
    *(uint *)(iVar2 + 0x10) = param_4;
    return 0;
  }
  _zip_error_set(param_1 + 8,0x12,0);
  return 0xffffffff;
}

// ===== zip_stat  @0x001bf6aa  (48 bytes)
undefined4 zip_stat(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = zip_name_locate();
  if (iVar1 < 0) {
    return 0xffffffff;
  }
  uVar2 = zip_stat_index(param_1,iVar1,param_3,param_4);
  return uVar2;
}

// ===== zip_get_file_comment  @0x001bf6d8  (94 bytes)
undefined4 zip_get_file_comment(int param_1,int param_2,uint *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if ((param_2 < 0) || (*(int *)(param_1 + 0x28) <= param_2)) {
    uVar3 = 0;
    _zip_error_set(param_1 + 8,0x12,0);
  }
  else {
    if ((param_4 & 8) == 0) {
      iVar1 = *(int *)(param_1 + 0x30) + param_2 * 0x14;
      uVar2 = *(uint *)(iVar1 + 0x10);
      if (uVar2 != 0xffffffff) {
        if (param_3 != (uint *)0x0) {
          *param_3 = uVar2;
        }
        return *(undefined4 *)(iVar1 + 0xc);
      }
    }
    iVar1 = **(int **)(param_1 + 0x1c);
    if (param_3 != (uint *)0x0) {
      *param_3 = (uint)*(ushort *)(iVar1 + param_2 * 0x3c + 0x2c);
    }
    uVar3 = *(undefined4 *)(iVar1 + param_2 * 0x3c + 0x28);
  }
  return uVar3;
}

// ===== _zip_mkstemp  @0x001bf738  (374 bytes)
void _zip_mkstemp(byte *param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  int *piVar6;
  undefined4 *puVar7;
  byte bVar8;
  int iVar9;
  char *pcVar10;
  byte *pbVar11;
  byte *pbVar12;
  stat sStack_88;
  int local_1c;
  
  pbVar11 = param_1 + -1;
  local_1c = __stack_chk_guard;
  iVar3 = getpid();
  iVar9 = 0;
  do {
    if (pbVar11[1] == 0x58) {
      iVar1 = iVar9 + 1;
    }
    else {
      iVar1 = 0;
      if (pbVar11[1] == 0) break;
    }
    iVar9 = iVar1;
    pbVar11 = pbVar11 + 1;
  } while( true );
  pbVar12 = pbVar11 + 1;
  if (*pbVar11 == 0x58) {
    *pbVar11 = DAT_0026b934;
    pbVar12 = pbVar11;
  }
  if ((6 < iVar9) && (pbVar11 = pbVar12 + -1, *pbVar11 == 0x58)) {
    *pbVar11 = DAT_0026b935;
    pbVar12 = pbVar11;
  }
  bVar8 = pbVar12[-1];
  pbVar11 = pbVar12 + -1;
  while (pbVar4 = pbVar11, bVar8 == 0x58) {
    *pbVar4 = (char)iVar3 + (char)(iVar3 / 10) * -10 + 0x30;
    pbVar11 = pbVar4 + -1;
    iVar3 = iVar3 / 10;
    pbVar12 = pbVar4;
    bVar8 = pbVar4[-1];
  }
  if (DAT_0026b934 == 0x7a) {
    cVar2 = 'a';
    DAT_0026b934 = 0x61;
    if (DAT_0026b935 == 0x7a) {
      pcVar10 = (char *)&DAT_0026b935;
      goto LAB_001bf7f6;
    }
    DAT_0026b935 = DAT_0026b935 + 1;
  }
  else {
    cVar2 = DAT_0026b934 + 1;
    pcVar10 = (char *)&DAT_0026b934;
LAB_001bf7f6:
    *pcVar10 = cVar2;
  }
  if (param_1 < pbVar4) {
    while (bVar8 != 0x2f) {
      pbVar4 = pbVar4 + -1;
      if (pbVar4 <= param_1) goto LAB_001bf838;
      bVar8 = *pbVar4;
    }
    *pbVar4 = 0;
    iVar3 = stat((char *)param_1,&sStack_88);
    if (iVar3 != 0) goto LAB_001bf894;
    if ((sStack_88.st_mode & 0xf000) != 0x4000) {
      puVar7 = (undefined4 *)__errno();
      *puVar7 = 0x14;
      goto LAB_001bf894;
    }
    *pbVar4 = 0x2f;
  }
LAB_001bf838:
  uVar5 = open((char *)param_1,0xc2,0x180);
  if (0x7fffffff < uVar5) {
    do {
      piVar6 = (int *)__errno();
      pbVar11 = pbVar12;
      if (*piVar6 != 0x11) break;
      while( true ) {
        uVar5 = (uint)*pbVar11;
        if (uVar5 != 0x7a) break;
        *pbVar11 = 0x61;
        pbVar11 = pbVar11 + 1;
      }
      if (uVar5 == 0) break;
      bVar8 = *pbVar11 + 1;
      if (uVar5 - 0x30 < 10) {
        bVar8 = 0x61;
      }
      *pbVar11 = bVar8;
      iVar3 = open((char *)param_1,0xc2,0x180);
    } while (iVar3 < 0);
  }
LAB_001bf894:
  if (__stack_chk_guard - local_1c == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_1c);
}

// ===== _zip_entry_free  @0x001bf8d8  (42 bytes)
void _zip_entry_free(int param_1)

{
  free(*(void **)(param_1 + 8));
  *(undefined4 *)(param_1 + 8) = 0;
  free(*(void **)(param_1 + 0xc));
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
  _zip_unchange_data(param_1);
  return;
}

// ===== zip_open  @0x001bf900  (1202 bytes)
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void zip_open(char *param_1,uint param_2,undefined4 *param_3)

{
  ushort uVar1;
  int iVar2;
  FILE *__stream;
  __off_t _Var3;
  int iVar4;
  int *piVar5;
  void *pvVar6;
  size_t sVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  char *pcVar12;
  int **ppiVar13;
  undefined4 uVar14;
  int *__ptr;
  int *piVar15;
  void *pvVar16;
  void *__s1;
  int local_b4;
  int local_a0;
  char *local_98;
  int *local_94;
  stat local_90;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (param_1 == (char *)0x0) {
    if (param_3 != (undefined4 *)0x0) {
      uVar8 = 0x12;
LAB_001bfa08:
      *param_3 = uVar8;
    }
  }
  else {
    iVar2 = stat(param_1,&local_90);
    iVar4 = __stack_chk_guard;
    if (iVar2 == 0) {
      if ((param_2 & 2) != 0) {
        if (param_3 != (undefined4 *)0x0) {
          uVar8 = 10;
          goto LAB_001bfa08;
        }
        goto LAB_001bfa0c;
      }
      __stream = fopen(param_1,"rb");
      if (__stream == (FILE *)0x0) goto LAB_001bf9fe;
      fseeko(__stream,0,2);
      _Var3 = ftello(__stream);
      if (_Var3 == 0) {
        iVar4 = FUN_001bfdcc(param_1,param_3);
        if (iVar4 != 0) {
          *(FILE **)(iVar4 + 4) = __stream;
          goto LAB_001bfa0c;
        }
      }
      else {
        if (0x10015 < _Var3) {
          _Var3 = 0x10016;
        }
        iVar4 = fseeko(__stream,-_Var3,2);
        if ((iVar4 == -1) && (piVar5 = (int *)__errno(), *piVar5 != 0x1b)) {
          if (param_3 != (undefined4 *)0x0) {
            *param_3 = 4;
          }
        }
        else {
          pvVar6 = malloc(0x10016);
          if (pvVar6 == (void *)0x0) {
            if (param_3 != (undefined4 *)0x0) {
              *param_3 = 0xe;
            }
          }
          else {
            clearerr(__stream);
            sVar7 = fread(pvVar6,1,0x10016,__stream);
            if (((uint)__stream->_IO_read_base & 0x40) == 0) {
              _zip_error_set(&local_90,0x13,0);
              iVar4 = sVar7 - 0x12;
              if (iVar4 < 4) {
                free(pvVar6);
                __ptr = (int *)0x0;
LAB_001bfd8c:
                FUN_001bfe30(param_3,&local_90,0);
              }
              else {
                local_a0 = -1;
                iVar2 = iVar4;
                pvVar16 = pvVar6;
                piVar5 = (int *)0x0;
LAB_001bfa84:
                do {
                  piVar15 = (int *)((int)pvVar16 + -1);
                  do {
                    piVar15 = memchr((void *)((int)piVar15 + 1),0x50,
                                     (int)pvVar16 + ((iVar2 + -3) - ((int)piVar15 + 1)));
                    __ptr = piVar5;
                    if (piVar15 == (int *)0x0) goto LAB_001bfcbc;
                    __s1 = (void *)((int)piVar15 + 1);
                    iVar9 = memcmp(__s1,&DAT_00221be7,3);
                  } while (iVar9 != 0);
                  iVar2 = (int)pvVar6 + (sVar7 - (int)piVar15);
                  pvVar16 = __s1;
                  if ((iVar2 < 0x16) || (*piVar15 != 0x6054b50)) {
                    uVar8 = 0x13;
LAB_001bfada:
                    _zip_error_set(&local_90,uVar8,0);
                  }
                  else {
                    if (piVar15[1] != 0) {
                      uVar8 = 1;
                      goto LAB_001bfada;
                    }
                    local_94 = piVar15 + 2;
                    iVar9 = _zip_read2(&local_94);
                    uVar8 = _zip_read2(&local_94);
                    __ptr = (int *)_zip_cdir_new(uVar8,&local_90);
                    if (__ptr != (int *)0x0) {
                      iVar2 = iVar2 + -0x16;
                      iVar10 = _zip_read4(&local_94);
                      __ptr[2] = iVar10;
                      iVar10 = _zip_read4(&local_94);
                      __ptr[3] = iVar10;
                      __ptr[4] = 0;
                      iVar10 = _zip_read2(&local_94);
                      *(short *)(__ptr + 5) = (short)iVar10;
                      if ((iVar2 < iVar10) || (__ptr[1] != iVar9)) {
                        _zip_error_set(&local_90,0x13,0);
                      }
                      else {
                        if (((param_2 & 4) == 0) || (iVar2 == iVar10)) {
                          if (iVar10 != 0) {
                            iVar2 = _zip_memdup((int)piVar15 + 0x16,iVar10,&local_90);
                            __ptr[4] = iVar2;
                            if (iVar2 == 0) goto LAB_001bfb7a;
                          }
                          pcVar12 = (char *)__ptr[2];
                          if (pcVar12 < (char *)((int)piVar15 - (int)pvVar6)) {
                            local_94 = (int *)((int)piVar15 - (int)pcVar12);
                            ppiVar13 = &local_94;
LAB_001bfbdc:
                            iVar9 = 0;
                            iVar2 = __ptr[1];
                            local_b4 = 0;
                            local_98 = pcVar12;
                            while( true ) {
                              if ((local_98 != (char *)0x0) && (iVar9 == iVar2)) {
                                _zip_cdir_grow(__ptr,iVar2 + 0x10000,&local_90);
                              }
                              iVar2 = _zip_dirent_read(*__ptr + local_b4,__stream,ppiVar13,&local_98
                                                      );
                              if (iVar2 < 0) {
                                __ptr[1] = iVar9;
                                _zip_cdir_free(__ptr);
                                goto LAB_001bfae0;
                              }
                              iVar2 = __ptr[1];
                              iVar9 = iVar9 + 1;
                              if (iVar2 <= iVar9) break;
                              local_b4 = local_b4 + 0x3c;
                            }
                            if (piVar5 == (int *)0x0) {
                              if ((param_2 & 4) == 0) {
                                local_a0 = 0;
                              }
                              else {
                                local_a0 = FUN_001bfe8c(__stream,__ptr,&local_90);
                              }
                            }
                            else {
                              if (local_a0 < 1) {
                                local_a0 = FUN_001bfe8c(__stream,piVar5,&local_90);
                              }
                              iVar2 = FUN_001bfe8c(__stream,__ptr,&local_90);
                              if (iVar2 <= local_a0) {
                                _zip_cdir_free(__ptr);
                                goto LAB_001bfae0;
                              }
                              _zip_cdir_free(piVar5);
                              local_a0 = iVar2;
                            }
                            iVar2 = (int)pvVar6 + (iVar4 - (int)__s1);
                            piVar5 = __ptr;
                            if (iVar2 < 4) break;
                            goto LAB_001bfa84;
                          }
                          clearerr(__stream);
                          fseeko(__stream,__ptr[3],0);
                          uVar1 = *(ushort *)&__stream->_IO_read_base;
                          if ((uVar1 & 0x40) == 0) {
                            _Var3 = ftello(__stream);
                            if (_Var3 == __ptr[3]) {
                              ppiVar13 = (int **)0x0;
                              pcVar12 = (char *)__ptr[2];
                              goto LAB_001bfbdc;
                            }
                            uVar1 = *(ushort *)&__stream->_IO_read_base;
                          }
                          if ((uVar1 & 0x40) == 0) {
                            uVar8 = 0x13;
                            goto LAB_001bfb64;
                          }
                          puVar11 = (undefined4 *)__errno();
                          uVar14 = *puVar11;
                          uVar8 = 4;
                        }
                        else {
                          uVar8 = 0x15;
LAB_001bfb64:
                          uVar14 = 0;
                        }
                        _zip_error_set(&local_90,uVar8,uVar14);
                      }
LAB_001bfb7a:
                      free(__ptr);
                    }
                  }
LAB_001bfae0:
                  iVar2 = (int)pvVar6 + (iVar4 - (int)__s1);
                  __ptr = piVar5;
                } while (3 < iVar2);
LAB_001bfcbc:
                free(pvVar6);
                if (local_a0 < 0) goto LAB_001bfd8c;
                if (__ptr == (int *)0x0) goto LAB_001bfd9c;
                iVar4 = FUN_001bfdcc(param_1,param_3);
                if (iVar4 != 0) {
                  *(int **)(iVar4 + 0x1c) = __ptr;
                  *(FILE **)(iVar4 + 4) = __stream;
                  pvVar6 = malloc(__ptr[1] * 0x14);
                  *(void **)(iVar4 + 0x30) = pvVar6;
                  if (pvVar6 == (void *)0x0) {
                    if (param_3 != (undefined4 *)0x0) {
                      *param_3 = 0xe;
                    }
                    _zip_free(iVar4);
                  }
                  else {
                    if (0 < __ptr[1]) {
                      iVar2 = 0;
                      do {
                        _zip_entry_new(iVar4);
                        iVar2 = iVar2 + 1;
                      } while (iVar2 < __ptr[1]);
                    }
                    if (((*(int *)(iVar4 + 4) != 0) && (iVar2 = *(int *)(iVar4 + 0x1c), iVar2 != 0))
                       && (*(short *)(iVar2 + 0x14) == 0x16)) {
                      pcVar12 = *(char **)(iVar2 + 0x10);
                      iVar2 = strncmp(pcVar12,"TORRENTZIPPED-",0xe);
                      if (iVar2 == 0) {
                        local_90.st_dev._4_4_ = *(undefined4 *)(pcVar12 + 0x12);
                        local_90.st_dev._0_4_ = *(undefined4 *)(pcVar12 + 0xe);
                        local_90.__pad1._0_1_ = 0;
                        puVar11 = (undefined4 *)__errno();
                        *puVar11 = 0;
                        piVar5 = (int *)strtoul((char *)&local_90,&local_98,0x10);
                        if ((((piVar5 != (int *)0xffffffff) ||
                             (piVar15 = (int *)__errno(), *piVar15 == 0)) &&
                            ((local_98 == (char *)0x0 || (*local_98 == '\0')))) &&
                           ((iVar2 = _zip_filerange_crc(*(undefined4 *)(iVar4 + 4),
                                                        *(undefined4 *)
                                                         (*(int *)(iVar4 + 0x1c) + 0xc),
                                                        *(undefined4 *)(*(int *)(iVar4 + 0x1c) + 8),
                                                        &local_94), -1 < iVar2 &&
                            (local_94 == piVar5)))) {
                          *(uint *)(iVar4 + 0x14) = *(uint *)(iVar4 + 0x14) | 1;
                        }
                      }
                    }
                    *(undefined4 *)(iVar4 + 0x18) = *(undefined4 *)(iVar4 + 0x14);
                  }
                  goto LAB_001bfa0c;
                }
              }
              _zip_cdir_free(__ptr);
            }
            else {
              if (param_3 != (undefined4 *)0x0) {
                *param_3 = 5;
              }
              free(pvVar6);
            }
          }
        }
      }
LAB_001bfd9c:
      fclose(__stream);
    }
    else {
      if ((param_2 & 1) != 0) {
        iVar2 = __stack_chk_guard - local_28;
        if (iVar2 == 0) {
          puVar11 = (undefined4 *)_zip_new(&stack0xffffffdc);
          if (puVar11 == (undefined4 *)0x0) {
            FUN_001bfe30(param_3,&stack0xffffffdc,0);
          }
          else {
            pcVar12 = strdup(param_1);
            *puVar11 = pcVar12;
            if ((pcVar12 == (char *)0x0) && (_zip_free(puVar11), param_3 != (undefined4 *)0x0)) {
              *param_3 = 0xe;
            }
          }
          if (__stack_chk_guard - iVar4 != 0) {
                    /* WARNING: Subroutine does not return */
            __stack_chk_fail(__stack_chk_guard - iVar4);
          }
          return;
        }
        goto LAB_001bfa24;
      }
LAB_001bf9fe:
      if (param_3 != (undefined4 *)0x0) {
        uVar8 = 0xb;
        goto LAB_001bfa08;
      }
    }
  }
LAB_001bfa0c:
  iVar2 = __stack_chk_guard - local_28;
  if (iVar2 == 0) {
    return;
  }
LAB_001bfa24:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar2);
}

// ===== zip_error_get  @0x001c000c  (8 bytes)
void zip_error_get(int param_1)

{
  _zip_error_get(param_1 + 8);
  return;
}

// ===== zip_fclose  @0x001c0012  (114 bytes)
int zip_fclose(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1[0xc] != 0) {
    inflateEnd();
  }
  free((void *)param_1[0xb]);
  free((void *)param_1[0xc]);
  iVar1 = *(int *)(*param_1 + 0x34);
  if (0 < iVar1) {
    iVar2 = *(int *)(*param_1 + 0x3c);
    iVar3 = 0;
    do {
      if (*(int **)(iVar2 + iVar3 * 4) == param_1) {
        *(undefined4 *)(iVar2 + iVar3 * 4) = *(undefined4 *)(iVar2 + iVar1 * 4 + -4);
        *(int *)(*param_1 + 0x34) = *(int *)(*param_1 + 0x34) + -1;
        break;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  iVar1 = param_1[1];
  if (iVar1 == 0) {
    if ((param_1[4] & 5U) == 5) {
      iVar1 = 7;
      if (param_1[10] == param_1[9]) {
        iVar1 = 0;
      }
    }
    else {
      iVar1 = 0;
    }
  }
  free(param_1);
  return iVar1;
}

// ===== _zip_cdir_free  @0x001c0084  (66 bytes)
void _zip_cdir_free(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    return;
  }
  if (0 < param_1[1]) {
    iVar1 = 0;
    iVar2 = 0;
    do {
      _zip_dirent_finalize(*param_1 + iVar1);
      iVar1 = iVar1 + 0x3c;
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1[1]);
  }
  free((void *)param_1[4]);
  free((void *)*param_1);
  free(param_1);
  return;
}

// ===== _zip_dirent_finalize  @0x001c00c6  (34 bytes)
void _zip_dirent_finalize(int param_1)

{
  free(*(void **)(param_1 + 0x18));
  *(undefined4 *)(param_1 + 0x18) = 0;
  free(*(void **)(param_1 + 0x20));
  *(undefined4 *)(param_1 + 0x20) = 0;
  free(*(void **)(param_1 + 0x28));
  *(undefined4 *)(param_1 + 0x28) = 0;
  return;
}

// ===== _zip_cdir_grow  @0x001c00e8  (64 bytes)
undefined4 _zip_cdir_grow(undefined4 *param_1,int param_2,undefined4 param_3)

{
  void *pvVar1;
  undefined4 uVar2;
  
  if (param_2 < (int)param_1[1]) {
    uVar2 = 0x14;
  }
  else {
    pvVar1 = realloc((void *)*param_1,param_2 * 0x3c);
    if (pvVar1 != (void *)0x0) {
      *param_1 = pvVar1;
      param_1[1] = param_2;
      return 0;
    }
    uVar2 = 0xe;
  }
  _zip_error_set(param_3,uVar2,0);
  return 0xffffffff;
}

// ===== _zip_cdir_new  @0x001c0128  (92 bytes)
undefined4 * _zip_cdir_new(int param_1,undefined4 param_2)

{
  undefined4 *__ptr;
  void *pvVar1;
  undefined4 *puVar2;
  
  __ptr = malloc(0x18);
  if (__ptr == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
    _zip_error_set(param_2,0xe,0);
  }
  else {
    pvVar1 = malloc(param_1 * 0x3c);
    *__ptr = pvVar1;
    if (pvVar1 == (void *)0x0) {
      puVar2 = (undefined4 *)0x0;
      _zip_error_set(param_2,0xe,0);
      free(__ptr);
    }
    else {
      __ptr[1] = param_1;
      __ptr[2] = 0;
      __ptr[3] = 0;
      *(undefined4 *)((int)__ptr + 0x12) = 0;
      *(undefined4 *)((int)__ptr + 0xe) = 0;
      puVar2 = __ptr;
    }
  }
  return puVar2;
}

// ===== _zip_cdir_write  @0x001c0184  (218 bytes)
undefined4 _zip_cdir_write(int *param_1,FILE *param_2,undefined4 param_3)

{
  ushort uVar1;
  __off_t _Var2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  
  _Var2 = ftello(param_2);
  param_1[3] = _Var2;
  if (0 < param_1[1]) {
    iVar5 = 0;
    iVar7 = 0;
    do {
      iVar3 = _zip_dirent_write(*param_1 + iVar5,param_2,0,param_3);
      if (iVar3 != 0) goto LAB_001c0254;
      iVar7 = iVar7 + 1;
      iVar5 = iVar5 + 0x3c;
    } while (iVar7 < param_1[1]);
  }
  _Var2 = ftello(param_2);
  param_1[2] = _Var2 - param_1[3];
  fwrite(&DAT_00221be6,1,4,param_2);
  uVar8 = 0;
  FUN_001c0434(0,param_2);
  uVar6 = param_1[1];
  putc(uVar6 & 0xff,param_2);
  putc((uVar6 & 0xffff) >> 8,param_2);
  uVar6 = param_1[1];
  putc(uVar6 & 0xff,param_2);
  putc((uVar6 & 0xffff) >> 8,param_2);
  FUN_001c0434(param_1[2],param_2);
  FUN_001c0434(param_1[3],param_2);
  uVar1 = *(ushort *)(param_1 + 5);
  putc((uint)(byte)uVar1,param_2);
  putc((uint)(uVar1 >> 8),param_2);
  fwrite((void *)param_1[4],1,(uint)*(ushort *)(param_1 + 5),param_2);
  if (((uint)param_2->_IO_read_base & 0x40) != 0) {
    puVar4 = (undefined4 *)__errno();
    _zip_error_set(param_3,6,*puVar4);
LAB_001c0254:
    uVar8 = 0xffffffff;
  }
  return uVar8;
}

// ===== _zip_dirent_write  @0x001c0264  (446 bytes)
void _zip_dirent_write(ushort *param_1,FILE *param_2,int param_3,undefined4 param_4)

{
  ushort uVar1;
  tm *ptVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  time_t local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  puVar4 = &DAT_00221beb;
  if (param_3 == 0) {
    puVar4 = &DAT_00221bf0;
  }
  fwrite(puVar4,1,4,param_2);
  if (param_3 == 0) {
    uVar1 = *param_1;
    putc((uint)(byte)uVar1,param_2);
    putc((uint)(uVar1 >> 8),param_2);
  }
  uVar1 = param_1[1];
  putc((uint)(byte)uVar1,param_2);
  putc((uint)(uVar1 >> 8),param_2);
  uVar1 = param_1[2];
  putc((uint)(byte)uVar1,param_2);
  putc((uint)(uVar1 >> 8),param_2);
  uVar1 = param_1[3];
  putc((uint)(byte)uVar1,param_2);
  putc((uint)(uVar1 >> 8),param_2);
  local_2c = *(time_t *)(param_1 + 4);
  ptVar2 = localtime(&local_2c);
  iVar7 = ptVar2->tm_mday;
  iVar8 = ptVar2->tm_mon;
  iVar5 = ptVar2->tm_year;
  uVar6 = ptVar2->tm_min * 0x20 + ptVar2->tm_hour * 0x800 + ((uint)ptVar2->tm_sec >> 1);
  putc(uVar6 & 0xff,param_2);
  putc((uVar6 & 0xffff) >> 8,param_2);
  uVar6 = iVar5 * 0x200 + iVar8 * 0x20 + iVar7 + 0x6020;
  putc(uVar6 & 0xff,param_2);
  putc((uVar6 & 0xffff) >> 8,param_2);
  FUN_001c0434(*(undefined4 *)(param_1 + 6),param_2);
  FUN_001c0434(*(undefined4 *)(param_1 + 8),param_2);
  FUN_001c0434(*(undefined4 *)(param_1 + 10),param_2);
  uVar1 = param_1[0xe];
  putc((uint)(byte)uVar1,param_2);
  putc((uint)(uVar1 >> 8),param_2);
  uVar1 = param_1[0x12];
  putc((uint)(byte)uVar1,param_2);
  putc((uint)(uVar1 >> 8),param_2);
  if (param_3 == 0) {
    uVar1 = param_1[0x16];
    putc((uint)(byte)uVar1,param_2);
    putc((uint)(uVar1 >> 8),param_2);
    uVar1 = param_1[0x17];
    putc((uint)(byte)uVar1,param_2);
    putc((uint)(uVar1 >> 8),param_2);
    uVar1 = param_1[0x18];
    putc((uint)(byte)uVar1,param_2);
    putc((uint)(uVar1 >> 8),param_2);
    FUN_001c0434(*(undefined4 *)(param_1 + 0x1a),param_2);
    FUN_001c0434(*(undefined4 *)(param_1 + 0x1c),param_2);
  }
  if (param_1[0xe] != 0) {
    fwrite(*(void **)(param_1 + 0xc),1,(uint)param_1[0xe],param_2);
  }
  if (param_1[0x12] != 0) {
    fwrite(*(void **)(param_1 + 0x10),1,(uint)param_1[0x12],param_2);
  }
  if ((param_3 == 0) && (param_1[0x16] != 0)) {
    fwrite(*(void **)(param_1 + 0x14),1,(uint)param_1[0x16],param_2);
  }
  if (((uint)param_2->_IO_read_base & 0x40) == 0) {
    uVar3 = 0;
  }
  else {
    puVar4 = (undefined4 *)__errno();
    _zip_error_set(param_4,6,*puVar4);
    uVar3 = 0xffffffff;
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}

// ===== _zip_dirent_init  @0x001c0462  (42 bytes)
void _zip_dirent_init(undefined2 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0x14;
  *(undefined4 *)(param_1 + 0x10) = 0;
  param_1[0x12] = 0;
  *(undefined4 *)(param_1 + 0x1a) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 7) = 0;
  *(undefined4 *)(param_1 + 9) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(param_1 + 0xb) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(param_1 + 0xd) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(param_1 + 2) = 0;
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(param_1 + 6) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x16) = 0;
  param_1[0x18] = 0;
  return;
}

// ===== _zip_dirent_read  @0x001c048c  (750 bytes)
void _zip_dirent_read(undefined2 *param_1,FILE *param_2,undefined4 *param_3,uint *param_4,
                     int param_5,undefined4 param_6)

{
  short sVar1;
  size_t sVar2;
  undefined4 *puVar3;
  int *piVar4;
  time_t tVar5;
  undefined4 uVar6;
  int iVar7;
  undefined2 uVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  int *__ptr;
  uint __n;
  uint uVar12;
  int *local_88;
  tm local_84;
  int local_56 [11];
  int local_28;
  
  __n = 0x2e;
  local_28 = __stack_chk_guard;
  if (param_5 != 0) {
    __n = 0x1e;
  }
  if ((param_4 != (uint *)0x0) && (*param_4 < __n)) goto LAB_001c0696;
  if (param_3 == (undefined4 *)0x0) {
    __ptr = local_56;
    sVar2 = fread(__ptr,1,__n,param_2);
    if (__n <= sVar2) goto LAB_001c04f0;
    puVar3 = (undefined4 *)__errno();
    uVar10 = *puVar3;
    uVar6 = 5;
LAB_001c069c:
    _zip_error_set(param_6,uVar6,uVar10);
  }
  else {
    __ptr = (int *)*param_3;
LAB_001c04f0:
    piVar4 = &DAT_00221beb;
    if (param_5 == 0) {
      piVar4 = &DAT_00221bf0;
    }
    local_88 = __ptr;
    if (*__ptr != *piVar4) {
LAB_001c0696:
      uVar6 = 0x13;
      uVar10 = 0;
      goto LAB_001c069c;
    }
    piVar4 = __ptr + 1;
    if (param_5 == 0) {
      piVar4 = (int *)((int)__ptr + 6);
      uVar8 = (undefined2)__ptr[1];
    }
    else {
      uVar8 = 0;
    }
    *param_1 = uVar8;
    param_1[1] = (short)*piVar4;
    param_1[2] = *(undefined2 *)((int)piVar4 + 2);
    param_1[3] = (short)piVar4[1];
    local_88 = (int *)((int)piVar4 + 10);
    local_84.tm_isdst = -1;
    local_84.tm_year = (*(byte *)((int)piVar4 + 9) >> 1) + 0x50;
    local_84.tm_mon = ((*(ushort *)(piVar4 + 2) & 0x1ff) >> 5) - 1;
    local_84.tm_mday = (byte)*(ushort *)(piVar4 + 2) & 0x1f;
    local_84.tm_hour = (int)(*(byte *)((int)piVar4 + 7) >> 3);
    local_84.tm_min = (*(ushort *)((int)piVar4 + 6) & 0x7ff) >> 5;
    local_84.tm_sec = (*(byte *)((int)piVar4 + 6) & 0x1f) << 1;
    tVar5 = mktime(&local_84);
    *(time_t *)(param_1 + 4) = tVar5;
    *(int *)(param_1 + 6) = *local_88;
    *(int *)(param_1 + 8) = local_88[1];
    *(int *)(param_1 + 10) = local_88[2];
    uVar12 = (uint)*(ushort *)(local_88 + 3);
    param_1[0xe] = *(ushort *)(local_88 + 3);
    uVar9 = (uint)*(ushort *)((int)local_88 + 0xe);
    param_1[0x12] = *(ushort *)((int)local_88 + 0xe);
    if (param_5 == 0) {
      uVar11 = (uint)*(ushort *)(local_88 + 4);
      param_1[0x16] = *(ushort *)(local_88 + 4);
      param_1[0x17] = *(undefined2 *)((int)local_88 + 0x12);
      param_1[0x18] = (short)local_88[5];
      *(undefined4 *)(param_1 + 0x1a) = *(undefined4 *)((int)local_88 + 0x16);
      uVar6 = *(undefined4 *)((int)local_88 + 0x1a);
      local_88 = (int *)((int)local_88 + 0x1e);
    }
    else {
      uVar11 = 0;
      param_1[0x16] = 0;
      uVar6 = 0;
      param_1[0x17] = 0;
      param_1[0x18] = 0;
      *(undefined4 *)(param_1 + 0x1a) = 0;
      local_88 = local_88 + 4;
    }
    *(undefined4 *)(param_1 + 0x1c) = uVar6;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    uVar11 = uVar12 + __n + uVar9 + uVar11;
    if ((param_4 != (uint *)0x0) && (*param_4 < uVar11)) goto LAB_001c0696;
    if (param_3 == (undefined4 *)0x0) {
      if (uVar12 != 0) {
        iVar7 = FUN_001c0826(param_2,uVar12,1,param_6);
        *(int *)(param_1 + 0xc) = iVar7;
        if (iVar7 == 0) goto LAB_001c06a0;
        uVar9 = (uint)(ushort)param_1[0x12];
      }
      if (uVar9 != 0) {
        iVar7 = FUN_001c0826(param_2,uVar9,0,param_6);
        *(int *)(param_1 + 0x10) = iVar7;
        if (iVar7 == 0) goto LAB_001c06a0;
      }
      sVar1 = param_1[0x16];
      if (sVar1 == 0) goto LAB_001c0766;
      iVar7 = FUN_001c0826(param_2,sVar1,0,param_6);
      uVar6 = 0;
      *(int *)(param_1 + 0x14) = iVar7;
      if (iVar7 == 0) {
        uVar6 = 0xffffffff;
      }
      if ((iVar7 == 0) || (param_4 == (uint *)0x0)) goto LAB_001c06a4;
LAB_001c076c:
      *param_4 = *param_4 - uVar11;
LAB_001c0776:
      uVar6 = 0;
      goto LAB_001c06a4;
    }
    if (uVar12 == 0) {
LAB_001c06dc:
      if (uVar9 != 0) {
        iVar7 = FUN_001c07be(&local_88,uVar9,0,param_6);
        *(int *)(param_1 + 0x10) = iVar7;
        if (iVar7 == 0) goto LAB_001c06a0;
      }
      sVar1 = param_1[0x16];
      if (sVar1 != 0) {
        iVar7 = FUN_001c07be(&local_88,sVar1,0,param_6);
        *(int *)(param_1 + 0x14) = iVar7;
        if (iVar7 == 0) goto LAB_001c06a0;
      }
      *param_3 = local_88;
LAB_001c0766:
      if (param_4 != (uint *)0x0) goto LAB_001c076c;
      goto LAB_001c0776;
    }
    iVar7 = FUN_001c07be(&local_88,uVar12,1,param_6);
    *(int *)(param_1 + 0xc) = iVar7;
    if (iVar7 != 0) {
      uVar9 = (uint)(ushort)param_1[0x12];
      goto LAB_001c06dc;
    }
  }
LAB_001c06a0:
  uVar6 = 0xffffffff;
LAB_001c06a4:
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}

// ===== _zip_read2  @0x001c078c  (16 bytes)
undefined2 _zip_read2(undefined4 *param_1)

{
  undefined2 uVar1;
  
  uVar1 = *(undefined2 *)*param_1;
  *param_1 = (undefined2 *)*param_1 + 1;
  return uVar1;
}

// ===== _zip_read4  @0x001c079c  (34 bytes)
undefined4 _zip_read4(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)*param_1;
  *param_1 = (undefined4 *)*param_1 + 1;
  return uVar1;
}

// ===== _zip_dirent_torrent_normalize  @0x001c08a0  (158 bytes)
void _zip_dirent_torrent_normalize(undefined2 *param_1)

{
  int iVar1;
  tm *ptVar2;
  time_t tStack_1c;
  int local_18;
  
  local_18 = __stack_chk_guard;
  if (DAT_00270e9c == 0) {
    DAT_00270e70 = 0x2000000000;
    DAT_00270e78 = 0x1800000017;
    DAT_00270e80 = 0x600000000b;
    DAT_00270e88 = 0;
    DAT_00270e90 = 0;
    time(&tStack_1c);
    ptVar2 = localtime(&tStack_1c);
    DAT_00270e94 = ptVar2->tm_gmtoff;
    DAT_00270e98 = ptVar2->tm_zone;
    DAT_00270e9c = mktime((tm *)&DAT_00270e70);
  }
  iVar1 = DAT_00270e9c;
  *param_1 = 0;
  param_1[1] = 0x14;
  param_1[2] = 2;
  param_1[3] = 8;
  *(int *)(param_1 + 4) = iVar1;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  *(undefined4 *)(param_1 + 0x1a) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  free(*(void **)(param_1 + 0x10));
  *(undefined4 *)(param_1 + 0x10) = 0;
  param_1[0x12] = 0;
  free(*(void **)(param_1 + 0x14));
  *(undefined4 *)(param_1 + 0x14) = 0;
  param_1[0x16] = 0;
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== _zip_free  @0x001c0980  (140 bytes)
void _zip_free(undefined4 *param_1)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
  }
  if ((FILE *)param_1[1] != (FILE *)0x0) {
    fclose((FILE *)param_1[1]);
  }
  _zip_cdir_free(param_1[7]);
  pvVar2 = (void *)param_1[0xc];
  if (pvVar2 != (void *)0x0) {
    if (0 < (int)param_1[10]) {
      iVar3 = 0;
      iVar4 = 0;
      do {
        _zip_entry_free((int)pvVar2 + iVar3);
        pvVar2 = (void *)param_1[0xc];
        iVar3 = iVar3 + 0x14;
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)param_1[10]);
    }
    free(pvVar2);
  }
  iVar3 = param_1[0xd];
  if (iVar3 < 1) {
    pvVar2 = (void *)param_1[0xf];
  }
  else {
    pvVar2 = (void *)param_1[0xf];
    iVar4 = 0;
    do {
      piVar1 = (int *)(*(int *)((int)pvVar2 + iVar4 * 4) + 4);
      if (*piVar1 == 0) {
        _zip_error_set(piVar1,8,0);
        pvVar2 = (void *)param_1[0xf];
        **(undefined4 **)((int)pvVar2 + iVar4 * 4) = 0;
        iVar3 = param_1[0xd];
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar3);
  }
  free(pvVar2);
  free(param_1);
  return;
}

// ===== zip_file_error_clear  @0x001c0a0c  (8 bytes)
void zip_file_error_clear(int param_1)

{
  _zip_error_clear(param_1 + 4);
  return;
}

// ===== zip_error_to_str  @0x001c0a14  (118 bytes)
void zip_error_to_str(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  char *pcVar2;
  
  if ((param_3 < 0) || (0x17 < param_3)) {
    pcVar2 = "Unknown error %d";
  }
  else {
    iVar1 = param_3 * 4;
    param_3 = *(int *)(_zip_err_str + param_3 * 4);
    if (*(int *)(_zip_err_type + iVar1) == 2) {
      zError(param_4);
    }
    else if (*(int *)(_zip_err_type + iVar1) == 1) {
      strerror(param_4);
    }
    pcVar2 = "%s%s%s";
  }
  FUN_001d6588(param_1,param_2,pcVar2,param_3);
  return;
}

// ===== zip_stat_init  @0x001c0ab0  (26 bytes)
void zip_stat_init(undefined4 *param_1)

{
  *param_1 = 0;
  *(undefined8 *)(param_1 + 1) = 0xffffffff;
  *(undefined8 *)(param_1 + 3) = 0xffffffffffffffff;
  param_1[5] = 0xffffffff;
  param_1[6] = 0;
  return;
}

// ===== zip_fopen  @0x001c0ae0  (36 bytes)
undefined4 zip_fopen(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = zip_name_locate();
  if (iVar1 < 0) {
    return 0;
  }
  uVar2 = zip_fopen_index(param_1,iVar1,param_3);
  return uVar2;
}

// ===== zip_unchange_all  @0x001c0b02  (54 bytes)
uint zip_unchange_all(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0x28) < 1) {
    uVar3 = 0;
  }
  else {
    iVar2 = 0;
    uVar3 = 0;
    do {
      uVar1 = _zip_unchange(param_1,iVar2,1);
      uVar3 = uVar3 | uVar1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x28));
  }
  uVar1 = zip_unchange_archive(param_1);
  return uVar1 | uVar3;
}

// ===== _zip_error_strerror  @0x001c0b38  (238 bytes)
void _zip_error_strerror(int *param_1)

{
  bool bVar1;
  char *__s;
  void *pvVar2;
  size_t sVar3;
  size_t sVar4;
  int iVar5;
  char *pcVar6;
  char *__s_00;
  char acStack_a4 [128];
  int local_24;
  
  local_24 = __stack_chk_guard;
  _zip_error_fini(param_1);
  iVar5 = *param_1;
  if ((iVar5 < 0) || (0x17 < iVar5)) {
    __s = acStack_a4;
    FUN_001d65d0(__s,"Unknown error %d");
    sVar3 = strlen(__s);
LAB_001c0ba0:
    bVar1 = false;
    __s_00 = (char *)0x0;
    iVar5 = 0;
  }
  else {
    __s_00 = *(char **)(_zip_err_str + iVar5 * 4);
    if (*(int *)(_zip_err_type + iVar5 * 4) == 2) {
      __s = (char *)zError(param_1[1]);
    }
    else {
      if (*(int *)(_zip_err_type + iVar5 * 4) != 1) goto LAB_001c0c0c;
      __s = strerror(param_1[1]);
    }
    if (__s == (char *)0x0) goto LAB_001c0c0c;
    sVar3 = strlen(__s);
    if (__s_00 == (char *)0x0) goto LAB_001c0ba0;
    sVar4 = strlen(__s_00);
    iVar5 = sVar4 + 2;
    bVar1 = true;
  }
  pvVar2 = malloc(iVar5 + sVar3 + 1);
  if (pvVar2 != (void *)0x0) {
    pcVar6 = ": ";
    if (!bVar1) {
      pcVar6 = "";
      __s_00 = "";
    }
    FUN_001d65d0(pvVar2,"%s%s%s",__s_00,pcVar6,__s);
    param_1[2] = (int)pvVar2;
  }
LAB_001c0c0c:
  if (__stack_chk_guard - local_24 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_24);
}

// ===== SHA224_Init  @0x001c0c50  (132 bytes)
int SHA224_Init(SHA256_CTX *c)

{
  memset(c,0,0x70);
  c->h[4] = 0xffc00b31;
  c->h[6] = 0x64f98fa7;
  c->h[0] = 0xc1059ed8;
  c->h[1] = 0x367cd507;
  c->h[2] = 0x3070dd17;
  c->h[3] = 0xf70e5939;
  c->h[5] = 0x68581511;
  c->h[7] = 0xbefa4fa4;
  c->md_len = 0x1c;
  return 1;
}

// ===== SHA256_Init  @0x001c0cd4  (132 bytes)
int SHA256_Init(SHA256_CTX *c)

{
  memset(c,0,0x70);
  c->h[4] = 0x510e527f;
  c->h[6] = 0x1f83d9ab;
  c->h[0] = 0x6a09e667;
  c->h[1] = 0xbb67ae85;
  c->h[2] = 0x3c6ef372;
  c->h[3] = 0xa54ff53a;
  c->h[5] = 0x9b05688c;
  c->h[7] = 0x5be0cd19;
  c->md_len = 0x20;
  return 1;
}

// ===== SHA256_Update  @0x001c0d58  (272 bytes)
int SHA256_Update(SHA256_CTX *c,void *data,size_t len)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  size_t __n;
  void *pvVar4;
  uint *__s;
  
  if (len == 0) {
    return 1;
  }
  uVar2 = c->Nl + len * 8;
  uVar3 = c->Nh;
  uVar1 = c->num;
  if (uVar2 < c->Nl) {
    uVar3 = uVar3 + 1;
  }
  c->Nl = uVar2;
  c->Nh = uVar3 + (len >> 0x1d);
  if (uVar1 == 0) {
    uVar1 = len >> 6;
    if (uVar1 == 0) goto LAB_001c0e10;
LAB_001c0e2c:
    sha256_block_data_order(c,data,uVar1);
    pvVar4 = (void *)((int)data + uVar1 * 0x40);
    len = len + uVar1 * -0x40;
  }
  else {
    __s = c->data;
    if ((len < 0x40) && (len + uVar1 < 0x40)) {
      memcpy((void *)((int)__s + uVar1),data,len);
      c->num = c->num + len;
      return 1;
    }
    __n = 0x40 - uVar1;
    len = len - __n;
    pvVar4 = (void *)((int)data + __n);
    memcpy((void *)((int)__s + uVar1),data,__n);
    sha256_block_data_order(c,__s,1);
    c->num = 0;
    memset(__s,0,0x40);
    uVar1 = len >> 6;
    data = pvVar4;
    if (uVar1 != 0) goto LAB_001c0e2c;
  }
  data = pvVar4;
  if (len == 0) {
    return 1;
  }
LAB_001c0e10:
  c->num = len;
  memcpy(c->data,data,len);
  return 1;
}

// ===== SHA256_Transform  @0x001c0e6c  (8 bytes)
void SHA256_Transform(SHA256_CTX *c,uchar *data)

{
  sha256_block_data_order(c,data,1);
  return;
}

// ===== SHA256_Final  @0x001c0e74  (1048 bytes)
int SHA256_Final(uchar *md,SHA256_CTX *c)

{
  uint uVar1;
  uint uVar2;
  size_t __n;
  uint *ptr;
  
  uVar2 = c->num;
  uVar1 = uVar2 + 1;
  ptr = c->data;
  *(undefined1 *)((int)ptr + uVar2) = 0x80;
  if (uVar1 < 0x39) {
    __n = 0x37 - uVar2;
  }
  else {
    memset((void *)((int)ptr + uVar1),0,0x3f - uVar2);
    sha256_block_data_order(c,ptr,1);
    __n = 0x38;
    uVar1 = 0;
  }
  memset((void *)((int)ptr + uVar1),0,__n);
  uVar2 = c->Nh;
  uVar1 = c->Nl;
  *(char *)((int)c->data + 0x3b) = (char)uVar2;
  *(char *)((int)c->data + 0x39) = (char)(uVar2 >> 0x10);
  *(char *)((int)c->data + 0x3f) = (char)uVar1;
  *(char *)((int)c->data + 0x3a) = (char)(uVar2 >> 8);
  *(char *)(c->data + 0xf) = (char)(uVar1 >> 0x18);
  *(char *)((int)c->data + 0x3d) = (char)(uVar1 >> 0x10);
  *(char *)((int)c->data + 0x3e) = (char)(uVar1 >> 8);
  *(char *)(c->data + 0xe) = (char)(uVar2 >> 0x18);
  sha256_block_data_order(c,ptr,1);
  c->num = 0;
  OPENSSL_cleanse(ptr,0x40);
  uVar1 = c->md_len;
  if (uVar1 == 0x1c) {
    uVar1 = c->h[0];
    md[3] = (uchar)uVar1;
    *md = (uchar)(uVar1 >> 0x18);
    md[1] = (uchar)(uVar1 >> 0x10);
    md[2] = (uchar)(uVar1 >> 8);
    uVar1 = c->h[1];
    md[7] = (uchar)uVar1;
    md[4] = (uchar)(uVar1 >> 0x18);
    md[5] = (uchar)(uVar1 >> 0x10);
    md[6] = (uchar)(uVar1 >> 8);
    uVar1 = c->h[2];
    md[0xb] = (uchar)uVar1;
    md[8] = (uchar)(uVar1 >> 0x18);
    md[9] = (uchar)(uVar1 >> 0x10);
    md[10] = (uchar)(uVar1 >> 8);
    uVar1 = c->h[3];
    md[0xf] = (uchar)uVar1;
    md[0xc] = (uchar)(uVar1 >> 0x18);
    md[0xd] = (uchar)(uVar1 >> 0x10);
    md[0xe] = (uchar)(uVar1 >> 8);
    uVar1 = c->h[4];
    md[0x13] = (uchar)uVar1;
    md[0x10] = (uchar)(uVar1 >> 0x18);
    md[0x11] = (uchar)(uVar1 >> 0x10);
    md[0x12] = (uchar)(uVar1 >> 8);
    uVar1 = c->h[5];
    md[0x17] = (uchar)uVar1;
    md[0x14] = (uchar)(uVar1 >> 0x18);
    md[0x15] = (uchar)(uVar1 >> 0x10);
    md[0x16] = (uchar)(uVar1 >> 8);
    uVar1 = c->h[6];
    md[0x18] = (uchar)(uVar1 >> 0x18);
    md[0x19] = (uchar)(uVar1 >> 0x10);
    md[0x1a] = (uchar)(uVar1 >> 8);
    md[0x1b] = (uchar)uVar1;
    return 1;
  }
  if (uVar1 == 0x20) {
    uVar1 = c->h[0];
    md[3] = (uchar)uVar1;
    *md = (uchar)(uVar1 >> 0x18);
    md[1] = (uchar)(uVar1 >> 0x10);
    md[2] = (uchar)(uVar1 >> 8);
    uVar1 = c->h[1];
    md[7] = (uchar)uVar1;
    md[4] = (uchar)(uVar1 >> 0x18);
    md[5] = (uchar)(uVar1 >> 0x10);
    md[6] = (uchar)(uVar1 >> 8);
    uVar1 = c->h[2];
    md[0xb] = (uchar)uVar1;
    md[8] = (uchar)(uVar1 >> 0x18);
    md[9] = (uchar)(uVar1 >> 0x10);
    md[10] = (uchar)(uVar1 >> 8);
    uVar1 = c->h[3];
    md[0xf] = (uchar)uVar1;
    md[0xc] = (uchar)(uVar1 >> 0x18);
    md[0xd] = (uchar)(uVar1 >> 0x10);
    md[0xe] = (uchar)(uVar1 >> 8);
    uVar1 = c->h[4];
    md[0x13] = (uchar)uVar1;
    md[0x10] = (uchar)(uVar1 >> 0x18);
    md[0x11] = (uchar)(uVar1 >> 0x10);
    md[0x12] = (uchar)(uVar1 >> 8);
    uVar1 = c->h[5];
    md[0x17] = (uchar)uVar1;
    md[0x14] = (uchar)(uVar1 >> 0x18);
    md[0x15] = (uchar)(uVar1 >> 0x10);
    md[0x16] = (uchar)(uVar1 >> 8);
    uVar1 = c->h[6];
    md[0x18] = (uchar)(uVar1 >> 0x18);
    md[0x19] = (uchar)(uVar1 >> 0x10);
    md[0x1a] = (uchar)(uVar1 >> 8);
    md[0x1b] = (uchar)uVar1;
  }
  else {
    if (0x20 < uVar1) {
      return 0;
    }
    if (uVar1 >> 2 == 0) {
      return 1;
    }
    uVar1 = c->h[0];
    md[3] = (uchar)uVar1;
    *md = (uchar)(uVar1 >> 0x18);
    md[1] = (uchar)(uVar1 >> 0x10);
    md[2] = (uchar)(uVar1 >> 8);
    if (c->md_len < 8) {
      return 1;
    }
    uVar1 = c->h[1];
    md[7] = (uchar)uVar1;
    md[4] = (uchar)(uVar1 >> 0x18);
    md[5] = (uchar)(uVar1 >> 0x10);
    md[6] = (uchar)(uVar1 >> 8);
    if (c->md_len < 0xc) {
      return 1;
    }
    uVar1 = c->h[2];
    md[0xb] = (uchar)uVar1;
    md[8] = (uchar)(uVar1 >> 0x18);
    md[9] = (uchar)(uVar1 >> 0x10);
    md[10] = (uchar)(uVar1 >> 8);
    if (c->md_len < 0x10) {
      return 1;
    }
    uVar1 = c->h[3];
    md[0xf] = (uchar)uVar1;
    md[0xc] = (uchar)(uVar1 >> 0x18);
    md[0xd] = (uchar)(uVar1 >> 0x10);
    md[0xe] = (uchar)(uVar1 >> 8);
    if (c->md_len < 0x14) {
      return 1;
    }
    uVar1 = c->h[4];
    md[0x13] = (uchar)uVar1;
    md[0x10] = (uchar)(uVar1 >> 0x18);
    md[0x11] = (uchar)(uVar1 >> 0x10);
    md[0x12] = (uchar)(uVar1 >> 8);
    if (c->md_len < 0x18) {
      return 1;
    }
    uVar1 = c->h[5];
    md[0x17] = (uchar)uVar1;
    md[0x14] = (uchar)(uVar1 >> 0x18);
    md[0x15] = (uchar)(uVar1 >> 0x10);
    md[0x16] = (uchar)(uVar1 >> 8);
    if (c->md_len < 0x1c) {
      return 1;
    }
    uVar1 = c->h[6];
    md[0x1b] = (uchar)uVar1;
    md[0x18] = (uchar)(uVar1 >> 0x18);
    md[0x19] = (uchar)(uVar1 >> 0x10);
    md[0x1a] = (uchar)(uVar1 >> 8);
    if (c->md_len < 0x20) {
      return 1;
    }
  }
  uVar1 = c->h[7];
  md[0x1f] = (uchar)uVar1;
  md[0x1c] = (uchar)(uVar1 >> 0x18);
  md[0x1d] = (uchar)(uVar1 >> 0x10);
  md[0x1e] = (uchar)(uVar1 >> 8);
  return 1;
}

// ===== SHA224  @0x001c128c  (96 bytes)
uchar * SHA224(uchar *d,size_t n,uchar *md)

{
  SHA256_CTX SStack_88;
  
  if (md == (uchar *)0x0) {
    md = (uchar *)0x270ea0;
  }
  SHA224_Init(&SStack_88);
  SHA256_Update(&SStack_88,d,n);
  SHA256_Final(md,&SStack_88);
  OPENSSL_cleanse(&SStack_88,0x70);
  return md;
}

// ===== SHA256  @0x001c12f0  (100 bytes)
uchar * SHA256(uchar *d,size_t n,uchar *md)

{
  SHA256_CTX SStack_88;
  
  if (md == (uchar *)0x0) {
    md = (uchar *)0x270ebc;
  }
  SHA256_Init(&SStack_88);
  SHA256_Update(&SStack_88,d,n);
  SHA256_Final(md,&SStack_88);
  OPENSSL_cleanse(&SStack_88,0x70);
  return md;
}

// ===== OPENSSL_atomic_add  @0x001c1360  (28 bytes)
int OPENSSL_atomic_add(int *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  
  do {
    iVar2 = *param_1;
    bVar1 = (bool)hasExclusiveAccess(param_1);
  } while (!bVar1);
  *param_1 = iVar2 + param_2;
  return iVar2 + param_2;
}

// ===== OPENSSL_cleanse  @0x001c137c  (84 bytes)
void OPENSSL_cleanse(void *ptr,size_t len)

{
  undefined4 *puVar1;
  uint uVar2;
  bool bVar3;
  
  if (6 < len) {
    uVar2 = len - 4;
    for (; puVar1 = ptr, ((uint)ptr & 3) != 0; ptr = (void *)((int)ptr + 1)) {
      *(undefined1 *)ptr = 0;
      uVar2 = uVar2 - 1;
    }
    do {
      len = uVar2;
      ptr = puVar1 + 1;
      *puVar1 = 0;
      puVar1 = ptr;
      uVar2 = len - 4;
    } while (3 < len);
  }
  if (len != 0) {
    do {
      *(undefined1 *)ptr = 0;
      bVar3 = len != 0;
      len = len - 1;
      ptr = (undefined4 *)((int)ptr + 1);
    } while (bVar3 && len != 0);
  }
  return;
}

// ===== CRYPTO_memcmp  @0x001c13d0  (56 bytes)
int CRYPTO_memcmp(void *a,void *b,size_t len)

{
  uint uVar1;
  
  uVar1 = 0;
  for (; len != 0; len = len - 1) {
    uVar1 = uVar1 | *(byte *)a ^ *(byte *)b;
    a = (byte *)((int)a + 1);
    b = (byte *)((int)b + 1);
  }
  return -uVar1 >> 0x1f;
}

// ===== _armv7_neon_probe  @0x001c1420  (8 bytes)
void _armv7_neon_probe(void)

{
  return;
}

// ===== _armv7_tick  @0x001c1428  (8 bytes)
undefined8 _armv7_tick(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 in_cr14;
  
  uVar1 = coprocessor_movefromRt(0xf,1,in_cr14);
  uVar2 = coprocessor_movefromRt2(0xf,1,in_cr14);
  return CONCAT44(uVar2,uVar1);
}

// ===== _armv8_aes_probe  @0x001c1430  (8 bytes)
undefined4 _armv8_aes_probe(void)

{
  undefined1 auVar1 [16];
  
  auVar1 = AESInvShiftRows((undefined1  [16])0x0);
  auVar1 = AESSubBytes(auVar1);
  return auVar1._0_4_;
}

// ===== _armv8_sha1_probe  @0x001c1438  (8 bytes)
undefined4 _armv8_sha1_probe(void)

{
  undefined1 in_q0 [16];
  undefined1 auVar1 [16];
  
  auVar1 = SHA1HashUpdateChoose(in_q0,in_q0._0_4_,in_q0);
  return auVar1._0_4_;
}

// ===== _armv8_sha256_probe  @0x001c1440  (8 bytes)
undefined4 _armv8_sha256_probe(void)

{
  undefined1 in_q0 [16];
  undefined1 auVar1 [16];
  
  auVar1 = SHA256hash(in_q0,in_q0,in_q0,1);
  return auVar1._0_4_;
}

// ===== _armv8_pmull_probe  @0x001c1448  (8 bytes)
undefined4 _armv8_pmull_probe(void)

{
  undefined8 in_d0;
  undefined1 auVar1 [16];
  
  auVar1 = PolynomialMultiply(in_d0,in_d0,8);
  return auVar1._0_4_;
}

// ===== OPENSSL_wipe_cpu  @0x001c1450  (88 bytes)
void OPENSSL_wipe_cpu(void)

{
  return;
}

// ===== OPENSSL_instrument_bus  @0x001c14a8  (8 bytes)
undefined4 OPENSSL_instrument_bus(void)

{
  return 0;
}

// ===== OPENSSL_instrument_bus2  @0x001c14b0  (8 bytes)
undefined4 OPENSSL_instrument_bus2(void)

{
  return 0;
}

// ===== sha256_block_data_order  @0x001c1600  (4068 bytes)
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void sha256_block_data_order(undefined1 (*param_1) [16],undefined1 (*param_2) [16],int param_3)

{
  undefined1 auVar1 [32];
  undefined1 auVar2 [32];
  undefined1 auVar3 [32];
  undefined1 auVar4 [32];
  undefined1 auVar5 [32];
  undefined1 auVar6 [32];
  undefined1 auVar7 [32];
  undefined1 auVar8 [32];
  uint uVar9;
  undefined1 (*pauVar10) [16];
  undefined1 (*pauVar11) [16];
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  int iVar28;
  uint uVar29;
  int iVar30;
  int *piVar31;
  int *piVar32;
  bool bVar33;
  undefined1 (*pauVar34) [16];
  undefined1 (*pauVar35) [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  undefined1 auVar45 [16];
  undefined1 auVar46 [16];
  undefined8 uVar47;
  ulonglong uVar48;
  ulonglong uVar49;
  undefined8 uVar50;
  ulonglong uVar51;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  uint local_40;
  undefined1 (*local_3c) [16];
  uint local_38;
  uint local_34;
  undefined1 (*local_2c) [16];
  
  if ((DAT_00272178 & 0x10) != 0) {
    auVar36 = *param_1;
    auVar37 = param_1[1];
    pauVar10 = param_2 + param_3 * 4;
    do {
      auVar38 = *param_2;
      pauVar34 = param_2 + 1;
      pauVar11 = param_2 + 2;
      pauVar35 = param_2 + 3;
      param_2 = param_2 + 4;
      auVar38 = vrev(auVar38,1);
      auVar42 = vrev(*pauVar34,1);
      auVar43 = vrev(*pauVar11,1);
      auVar44 = vrev(*pauVar35,1);
      auVar40 = VectorAdd(_DAT_001c14e0,auVar38,4);
      auVar39 = SHA256ScheduleUpdate0(auVar38,auVar42);
      auVar38 = SHA256hash(auVar36,auVar37,auVar40,1);
      auVar40 = SHA256hash(auVar37,auVar36,auVar40,0);
      auVar41 = SHA256ScheduleUpdate1(auVar39,auVar43,auVar44);
      auVar45 = VectorAdd(_DAT_001c14f0,auVar42,4);
      auVar42 = SHA256ScheduleUpdate0(auVar42,auVar43);
      auVar39 = SHA256hash(auVar38,auVar40,auVar45,1);
      auVar40 = SHA256hash(auVar40,auVar38,auVar45,0);
      auVar42 = SHA256ScheduleUpdate1(auVar42,auVar44,auVar41);
      auVar45 = VectorAdd(_DAT_001c1500,auVar43,4);
      auVar43 = SHA256ScheduleUpdate0(auVar43,auVar44);
      auVar38 = SHA256hash(auVar39,auVar40,auVar45,1);
      auVar40 = SHA256hash(auVar40,auVar39,auVar45,0);
      auVar43 = SHA256ScheduleUpdate1(auVar43,auVar41,auVar42);
      auVar45 = VectorAdd(_DAT_001c1510,auVar44,4);
      auVar44 = SHA256ScheduleUpdate0(auVar44,auVar41);
      auVar39 = SHA256hash(auVar38,auVar40,auVar45,1);
      auVar40 = SHA256hash(auVar40,auVar38,auVar45,0);
      auVar44 = SHA256ScheduleUpdate1(auVar44,auVar42,auVar43);
      auVar45 = VectorAdd(_DAT_001c1520,auVar41,4);
      auVar41 = SHA256ScheduleUpdate0(auVar41,auVar42);
      auVar38 = SHA256hash(auVar39,auVar40,auVar45,1);
      auVar40 = SHA256hash(auVar40,auVar39,auVar45,0);
      auVar41 = SHA256ScheduleUpdate1(auVar41,auVar43,auVar44);
      auVar45 = VectorAdd(_DAT_001c1530,auVar42,4);
      auVar42 = SHA256ScheduleUpdate0(auVar42,auVar43);
      auVar39 = SHA256hash(auVar38,auVar40,auVar45,1);
      auVar40 = SHA256hash(auVar40,auVar38,auVar45,0);
      auVar42 = SHA256ScheduleUpdate1(auVar42,auVar44,auVar41);
      auVar45 = VectorAdd(_DAT_001c1540,auVar43,4);
      auVar43 = SHA256ScheduleUpdate0(auVar43,auVar44);
      auVar38 = SHA256hash(auVar39,auVar40,auVar45,1);
      auVar40 = SHA256hash(auVar40,auVar39,auVar45,0);
      auVar43 = SHA256ScheduleUpdate1(auVar43,auVar41,auVar42);
      auVar45 = VectorAdd(_DAT_001c1550,auVar44,4);
      auVar44 = SHA256ScheduleUpdate0(auVar44,auVar41);
      auVar39 = SHA256hash(auVar38,auVar40,auVar45,1);
      auVar40 = SHA256hash(auVar40,auVar38,auVar45,0);
      auVar44 = SHA256ScheduleUpdate1(auVar44,auVar42,auVar43);
      auVar45 = VectorAdd(_DAT_001c1560,auVar41,4);
      auVar41 = SHA256ScheduleUpdate0(auVar41,auVar42);
      auVar38 = SHA256hash(auVar39,auVar40,auVar45,1);
      auVar40 = SHA256hash(auVar40,auVar39,auVar45,0);
      auVar41 = SHA256ScheduleUpdate1(auVar41,auVar43,auVar44);
      auVar45 = VectorAdd(_DAT_001c1570,auVar42,4);
      auVar42 = SHA256ScheduleUpdate0(auVar42,auVar43);
      auVar39 = SHA256hash(auVar38,auVar40,auVar45,1);
      auVar40 = SHA256hash(auVar40,auVar38,auVar45,0);
      auVar42 = SHA256ScheduleUpdate1(auVar42,auVar44,auVar41);
      auVar45 = VectorAdd(_DAT_001c1580,auVar43,4);
      auVar43 = SHA256ScheduleUpdate0(auVar43,auVar44);
      auVar38 = SHA256hash(auVar39,auVar40,auVar45,1);
      auVar40 = SHA256hash(auVar40,auVar39,auVar45,0);
      auVar43 = SHA256ScheduleUpdate1(auVar43,auVar41,auVar42);
      auVar45 = VectorAdd(_DAT_001c1590,auVar44,4);
      auVar44 = SHA256ScheduleUpdate0(auVar44,auVar41);
      auVar39 = SHA256hash(auVar38,auVar40,auVar45,1);
      auVar40 = SHA256hash(auVar40,auVar38,auVar45,0);
      auVar44 = SHA256ScheduleUpdate1(auVar44,auVar42,auVar43);
      auVar41 = VectorAdd(_DAT_001c15a0,auVar41,4);
      auVar38 = SHA256hash(auVar39,auVar40,auVar41,1);
      auVar40 = SHA256hash(auVar40,auVar39,auVar41,0);
      auVar41 = VectorAdd(_DAT_001c15b0,auVar42,4);
      auVar39 = SHA256hash(auVar38,auVar40,auVar41,1);
      auVar40 = SHA256hash(auVar40,auVar38,auVar41,0);
      auVar41 = VectorAdd(_DAT_001c15c0,auVar43,4);
      auVar38 = SHA256hash(auVar39,auVar40,auVar41,1);
      auVar40 = SHA256hash(auVar40,auVar39,auVar41,0);
      auVar41 = VectorAdd(_DAT_001c15d0,auVar44,4);
      auVar39 = SHA256hash(auVar38,auVar40,auVar41,1);
      auVar38 = SHA256hash(auVar40,auVar38,auVar41,0);
      auVar36 = VectorAdd(auVar39,auVar36,4);
      auVar37 = VectorAdd(auVar38,auVar37,4);
    } while (param_2 != pauVar10);
    *(longlong *)*param_1 = auVar36._0_8_;
    *(longlong *)(*param_1 + 8) = auVar36._8_8_;
    *(longlong *)param_1[1] = auVar37._0_8_;
    *(longlong *)(param_1[1] + 8) = auVar37._8_8_;
    return;
  }
  if ((DAT_00272178 & 1) != 0) {
    local_3c = param_2 + 4;
    auVar40._8_8_ = 0xe9b5dba5b5c0fbcf;
    auVar40._0_8_ = 0x71374491428a2f98;
    auVar36 = vrev(*param_2,1);
    auVar37 = vrev(param_2[1],1);
    auVar38 = vrev(param_2[2],1);
    auVar39 = vrev(param_2[3],1);
    auVar40 = VectorAdd(auVar40,auVar36,4);
    auVar41 = VectorAdd(_DAT_001c14f0,auVar37,4);
    uStack_78 = auVar40._8_8_;
    auVar42 = VectorAdd(_DAT_001c1500,auVar38,4);
    local_70 = auVar41._0_8_;
    local_68 = auVar41._8_8_;
    auVar41 = VectorAdd(_DAT_001c1510,auVar39,4);
    local_60 = auVar42._0_8_;
    local_58 = auVar42._8_8_;
    local_50 = auVar41._0_8_;
    local_48 = auVar41._8_8_;
    iVar28 = *(int *)*param_1;
    uVar17 = *(uint *)(*param_1 + 4);
    uVar22 = *(uint *)(*param_1 + 8);
    uVar24 = *(uint *)(*param_1 + 0xc);
    uVar26 = *(uint *)param_1[1];
    uVar9 = *(uint *)(param_1[1] + 4);
    uVar12 = *(uint *)(param_1[1] + 8);
    uVar20 = *(uint *)(param_1[1] + 0xc);
    uStack_80._0_4_ = auVar40._0_4_;
    uVar16 = 0;
    uVar14 = uVar17 ^ uVar22;
    iVar19 = (int)uStack_80;
    pauVar10 = (undefined1 (*) [16])&DAT_001c1520;
    uVar50 = auVar40._0_8_;
    while( true ) {
      do {
        uStack_80 = uVar50;
        pauVar11 = pauVar10;
        auVar1._16_16_ = auVar37;
        auVar1._0_16_ = auVar36;
        auVar40 = auVar1._4_16_;
        auVar2._16_16_ = auVar39;
        auVar2._0_16_ = auVar38;
        uVar16 = iVar28 + uVar16;
        uVar21 = uVar26 ^ (uVar26 >> 5 | uVar26 << 0x1b) ^ (uVar26 >> 0x13 | uVar26 << 0xd);
        auVar42 = VectorUnsignedFixedToFloat(auVar40,7);
        auVar36 = VectorAdd(auVar36,auVar2._4_16_,4);
        auVar41 = VectorUnsignedFixedToFloat(auVar40,3);
        uVar18 = uVar16 ^ (uVar16 >> 0xb | uVar16 * 0x200000) ^ (uVar16 >> 0x14 | uVar16 * 0x1000);
        iVar19 = uVar20 + iVar19 + (uVar21 >> 6 | uVar21 << 0x1a) +
                 ((uVar9 ^ uVar12) & uVar26 ^ uVar12);
        auVar42 = VectorShiftLeftInsert(auVar42,auVar40,0x19);
        auVar43 = VectorUnsignedFixedToFloat(auVar40,0x12);
        uVar24 = uVar24 + iVar19;
        auVar40 = VectorShiftLeftInsert(auVar43,auVar40,0xe);
        uVar50 = auVar39._8_8_;
        uVar47 = VectorShiftRight(uVar50,0x11);
        uVar27 = iVar19 + (uVar18 >> 2 | uVar18 << 0x1e) + (uVar14 & (uVar16 ^ uVar17) ^ uVar17);
        uVar20 = uVar24 ^ (uVar24 >> 5 | uVar24 * 0x8000000) ^ (uVar24 >> 0x13 | uVar24 * 0x2000);
        uVar48 = VectorShiftLeftInsert(uVar47,uVar50,0xf);
        uVar51 = VectorShiftRight(uVar50,10);
        uVar14 = uVar27 ^ (uVar27 >> 0xb | uVar27 * 0x200000) ^ (uVar27 >> 0x14 | uVar27 * 0x1000);
        auVar40 = VectorAdd(auVar36,auVar41 ^ auVar42 ^ auVar40,4);
        iVar19 = uVar12 + uStack_80._4_4_ + (uVar20 >> 6 | uVar20 << 0x1a) +
                 ((uVar26 ^ uVar9) & uVar24 ^ uVar9);
        uVar22 = uVar22 + iVar19;
        uVar47 = VectorShiftRight(uVar50,0x13);
        uVar49 = VectorShiftLeftInsert(uVar47,uVar50,0xd);
        uVar12 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
                 ((uVar16 ^ uVar17) & (uVar27 ^ uVar16) ^ uVar16);
        auVar36._0_8_ = VectorAdd(auVar40._0_8_,uVar51 ^ uVar48 ^ uVar49,4);
        uVar20 = uVar22 ^ (uVar22 >> 5 | uVar22 * 0x8000000) ^ (uVar22 >> 0x13 | uVar22 * 0x2000);
        uVar50 = VectorShiftRight(auVar36._0_8_,0x11);
        uVar48 = VectorShiftLeftInsert(uVar50,auVar36._0_8_,0xf);
        uVar51 = VectorShiftRight(auVar36._0_8_,10);
        uVar14 = uVar12 ^ (uVar12 >> 0xb | uVar12 * 0x200000) ^ (uVar12 >> 0x14 | uVar12 * 0x1000);
        iVar19 = uVar9 + (int)uStack_78 + (uVar20 >> 6 | uVar20 << 0x1a) +
                 ((uVar24 ^ uVar26) & uVar22 ^ uVar26);
        uVar50 = VectorShiftRight(auVar36._0_8_,0x13);
        uVar17 = uVar17 + iVar19;
        uVar49 = VectorShiftLeftInsert(uVar50,auVar36._0_8_,0xd);
        uVar25 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
                 ((uVar27 ^ uVar16) & (uVar12 ^ uVar27) ^ uVar27);
        auVar36._8_8_ = VectorAdd(auVar40._8_8_,uVar51 ^ uVar48 ^ uVar49,4);
        uVar9 = uVar17 ^ (uVar17 >> 5 | uVar17 * 0x8000000) ^ (uVar17 >> 0x13 | uVar17 * 0x2000);
        auVar41 = VectorAdd(*pauVar11,auVar36,4);
        uVar14 = uVar25 ^ (uVar25 >> 0xb | uVar25 * 0x200000) ^ (uVar25 >> 0x14 | uVar25 * 0x1000);
        iVar19 = uVar26 + uStack_78._4_4_ + (uVar9 >> 6 | uVar9 << 0x1a) +
                 ((uVar22 ^ uVar24) & uVar17 ^ uVar24);
        uVar16 = uVar16 + iVar19;
        uStack_78 = auVar41._8_8_;
        auVar3._16_16_ = auVar38;
        auVar3._0_16_ = auVar37;
        auVar40 = auVar3._4_16_;
        auVar4._16_16_ = auVar36;
        auVar4._0_16_ = auVar39;
        uVar26 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
                 ((uVar12 ^ uVar27) & (uVar25 ^ uVar12) ^ uVar12);
        uVar9 = uVar16 ^ (uVar16 >> 5 | uVar16 * 0x8000000) ^ (uVar16 >> 0x13 | uVar16 * 0x2000);
        auVar43 = VectorUnsignedFixedToFloat(auVar40,7);
        auVar37 = VectorAdd(auVar37,auVar4._4_16_,4);
        auVar42 = VectorUnsignedFixedToFloat(auVar40,3);
        uVar14 = uVar26 ^ (uVar26 >> 0xb | uVar26 * 0x200000) ^ (uVar26 >> 0x14 | uVar26 * 0x1000);
        iVar19 = uVar24 + (uint)local_70 + (uVar9 >> 6 | uVar9 << 0x1a) +
                 ((uVar17 ^ uVar22) & uVar16 ^ uVar22);
        auVar43 = VectorShiftLeftInsert(auVar43,auVar40,0x19);
        auVar44 = VectorUnsignedFixedToFloat(auVar40,0x12);
        uVar27 = uVar27 + iVar19;
        auVar40 = VectorShiftLeftInsert(auVar44,auVar40,0xe);
        uVar50 = VectorShiftRight(auVar36._8_8_,0x11);
        uVar23 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
                 ((uVar25 ^ uVar12) & (uVar26 ^ uVar25) ^ uVar25);
        uVar24 = uVar27 ^ (uVar27 >> 5 | uVar27 * 0x8000000) ^ (uVar27 >> 0x13 | uVar27 * 0x2000);
        uVar48 = VectorShiftLeftInsert(uVar50,auVar36._8_8_,0xf);
        uVar51 = VectorShiftRight(auVar36._8_8_,10);
        uVar14 = uVar23 ^ (uVar23 >> 0xb | uVar23 * 0x200000) ^ (uVar23 >> 0x14 | uVar23 * 0x1000);
        auVar40 = VectorAdd(auVar37,auVar42 ^ auVar43 ^ auVar40,4);
        iVar19 = uVar22 + local_70._4_4_ + (uVar24 >> 6 | uVar24 << 0x1a) +
                 ((uVar16 ^ uVar17) & uVar27 ^ uVar17);
        uVar12 = uVar12 + iVar19;
        uVar50 = VectorShiftRight(auVar36._8_8_,0x13);
        uVar49 = VectorShiftLeftInsert(uVar50,auVar36._8_8_,0xd);
        uVar22 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
                 ((uVar26 ^ uVar25) & (uVar23 ^ uVar26) ^ uVar26);
        auVar37._0_8_ = VectorAdd(auVar40._0_8_,uVar51 ^ uVar48 ^ uVar49,4);
        uVar24 = uVar12 ^ (uVar12 >> 5 | uVar12 * 0x8000000) ^ (uVar12 >> 0x13 | uVar12 * 0x2000);
        uVar50 = VectorShiftRight(auVar37._0_8_,0x11);
        uVar48 = VectorShiftLeftInsert(uVar50,auVar37._0_8_,0xf);
        uVar51 = VectorShiftRight(auVar37._0_8_,10);
        uVar14 = uVar22 ^ (uVar22 >> 0xb | uVar22 * 0x200000) ^ (uVar22 >> 0x14 | uVar22 * 0x1000);
        iVar19 = uVar17 + (uint)local_68 + (uVar24 >> 6 | uVar24 << 0x1a) +
                 ((uVar27 ^ uVar16) & uVar12 ^ uVar16);
        uVar50 = VectorShiftRight(auVar37._0_8_,0x13);
        uVar25 = uVar25 + iVar19;
        uVar49 = VectorShiftLeftInsert(uVar50,auVar37._0_8_,0xd);
        uVar18 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
                 ((uVar23 ^ uVar26) & (uVar22 ^ uVar23) ^ uVar23);
        auVar37._8_8_ = VectorAdd(auVar40._8_8_,uVar51 ^ uVar48 ^ uVar49,4);
        uVar17 = uVar25 ^ (uVar25 >> 5 | uVar25 * 0x8000000) ^ (uVar25 >> 0x13 | uVar25 * 0x2000);
        auVar42 = VectorAdd(pauVar11[1],auVar37,4);
        uVar14 = uVar18 ^ (uVar18 >> 0xb | uVar18 * 0x200000) ^ (uVar18 >> 0x14 | uVar18 * 0x1000);
        iVar19 = uVar16 + local_68._4_4_ + (uVar17 >> 6 | uVar17 << 0x1a) +
                 ((uVar12 ^ uVar27) & uVar25 ^ uVar27);
        uVar26 = uVar26 + iVar19;
        local_70 = auVar42._0_8_;
        local_68 = auVar42._8_8_;
        auVar5._16_16_ = auVar39;
        auVar5._0_16_ = auVar38;
        auVar40 = auVar5._4_16_;
        auVar6._16_16_ = auVar37;
        auVar6._0_16_ = auVar36;
        uVar21 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
                 ((uVar22 ^ uVar23) & (uVar18 ^ uVar22) ^ uVar22);
        uVar16 = uVar26 ^ (uVar26 >> 5 | uVar26 * 0x8000000) ^ (uVar26 >> 0x13 | uVar26 * 0x2000);
        auVar44 = VectorUnsignedFixedToFloat(auVar40,7);
        auVar38 = VectorAdd(auVar38,auVar6._4_16_,4);
        auVar43 = VectorUnsignedFixedToFloat(auVar40,3);
        uVar14 = uVar21 ^ (uVar21 >> 0xb | uVar21 * 0x200000) ^ (uVar21 >> 0x14 | uVar21 * 0x1000);
        iVar19 = uVar27 + (uint)local_60 + (uVar16 >> 6 | uVar16 << 0x1a) +
                 ((uVar25 ^ uVar12) & uVar26 ^ uVar12);
        auVar44 = VectorShiftLeftInsert(auVar44,auVar40,0x19);
        auVar45 = VectorUnsignedFixedToFloat(auVar40,0x12);
        uVar23 = uVar23 + iVar19;
        auVar40 = VectorShiftLeftInsert(auVar45,auVar40,0xe);
        uVar50 = VectorShiftRight(auVar37._8_8_,0x11);
        uVar20 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
                 ((uVar18 ^ uVar22) & (uVar21 ^ uVar18) ^ uVar18);
        uVar16 = uVar23 ^ (uVar23 >> 5 | uVar23 * 0x8000000) ^ (uVar23 >> 0x13 | uVar23 * 0x2000);
        uVar48 = VectorShiftLeftInsert(uVar50,auVar37._8_8_,0xf);
        uVar51 = VectorShiftRight(auVar37._8_8_,10);
        uVar14 = uVar20 ^ (uVar20 >> 0xb | uVar20 * 0x200000) ^ (uVar20 >> 0x14 | uVar20 * 0x1000);
        auVar40 = VectorAdd(auVar38,auVar43 ^ auVar44 ^ auVar40,4);
        iVar19 = uVar12 + local_60._4_4_ + (uVar16 >> 6 | uVar16 << 0x1a) +
                 ((uVar26 ^ uVar25) & uVar23 ^ uVar25);
        uVar22 = uVar22 + iVar19;
        uVar50 = VectorShiftRight(auVar37._8_8_,0x13);
        uVar49 = VectorShiftLeftInsert(uVar50,auVar37._8_8_,0xd);
        uVar12 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
                 ((uVar21 ^ uVar18) & (uVar20 ^ uVar21) ^ uVar21);
        auVar38._0_8_ = VectorAdd(auVar40._0_8_,uVar51 ^ uVar48 ^ uVar49,4);
        uVar16 = uVar22 ^ (uVar22 >> 5 | uVar22 * 0x8000000) ^ (uVar22 >> 0x13 | uVar22 * 0x2000);
        uVar50 = VectorShiftRight(auVar38._0_8_,0x11);
        uVar48 = VectorShiftLeftInsert(uVar50,auVar38._0_8_,0xf);
        uVar51 = VectorShiftRight(auVar38._0_8_,10);
        uVar14 = uVar12 ^ (uVar12 >> 0xb | uVar12 * 0x200000) ^ (uVar12 >> 0x14 | uVar12 * 0x1000);
        iVar19 = uVar25 + (uint)local_58 + (uVar16 >> 6 | uVar16 << 0x1a) +
                 ((uVar23 ^ uVar26) & uVar22 ^ uVar26);
        uVar50 = VectorShiftRight(auVar38._0_8_,0x13);
        uVar18 = uVar18 + iVar19;
        uVar49 = VectorShiftLeftInsert(uVar50,auVar38._0_8_,0xd);
        uVar9 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
                ((uVar20 ^ uVar21) & (uVar12 ^ uVar20) ^ uVar20);
        auVar38._8_8_ = VectorAdd(auVar40._8_8_,uVar51 ^ uVar48 ^ uVar49,4);
        uVar16 = uVar18 ^ (uVar18 >> 5 | uVar18 * 0x8000000) ^ (uVar18 >> 0x13 | uVar18 * 0x2000);
        auVar43 = VectorAdd(pauVar11[2],auVar38,4);
        uVar14 = uVar9 ^ (uVar9 >> 0xb | uVar9 * 0x200000) ^ (uVar9 >> 0x14 | uVar9 * 0x1000);
        iVar19 = uVar26 + local_58._4_4_ + (uVar16 >> 6 | uVar16 << 0x1a) +
                 ((uVar22 ^ uVar23) & uVar18 ^ uVar23);
        uVar21 = uVar21 + iVar19;
        local_60 = auVar43._0_8_;
        local_58 = auVar43._8_8_;
        auVar7._16_16_ = auVar36;
        auVar7._0_16_ = auVar39;
        auVar40 = auVar7._4_16_;
        auVar8._16_16_ = auVar38;
        auVar8._0_16_ = auVar37;
        uVar26 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
                 ((uVar12 ^ uVar20) & (uVar9 ^ uVar12) ^ uVar12);
        uVar16 = uVar21 ^ (uVar21 >> 5 | uVar21 * 0x8000000) ^ (uVar21 >> 0x13 | uVar21 * 0x2000);
        auVar45 = VectorUnsignedFixedToFloat(auVar40,7);
        auVar39 = VectorAdd(auVar39,auVar8._4_16_,4);
        auVar44 = VectorUnsignedFixedToFloat(auVar40,3);
        uVar14 = uVar26 ^ (uVar26 >> 0xb | uVar26 * 0x200000) ^ (uVar26 >> 0x14 | uVar26 * 0x1000);
        iVar19 = uVar23 + (uint)local_50 + (uVar16 >> 6 | uVar16 << 0x1a) +
                 ((uVar18 ^ uVar22) & uVar21 ^ uVar22);
        auVar45 = VectorShiftLeftInsert(auVar45,auVar40,0x19);
        auVar46 = VectorUnsignedFixedToFloat(auVar40,0x12);
        uVar20 = uVar20 + iVar19;
        auVar40 = VectorShiftLeftInsert(auVar46,auVar40,0xe);
        uVar50 = VectorShiftRight(auVar38._8_8_,0x11);
        uVar24 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
                 ((uVar9 ^ uVar12) & (uVar26 ^ uVar9) ^ uVar9);
        uVar16 = uVar20 ^ (uVar20 >> 5 | uVar20 * 0x8000000) ^ (uVar20 >> 0x13 | uVar20 * 0x2000);
        uVar48 = VectorShiftLeftInsert(uVar50,auVar38._8_8_,0xf);
        uVar51 = VectorShiftRight(auVar38._8_8_,10);
        uVar14 = uVar24 ^ (uVar24 >> 0xb | uVar24 * 0x200000) ^ (uVar24 >> 0x14 | uVar24 * 0x1000);
        auVar40 = VectorAdd(auVar39,auVar44 ^ auVar45 ^ auVar40,4);
        iVar19 = uVar22 + local_50._4_4_ + (uVar16 >> 6 | uVar16 << 0x1a) +
                 ((uVar21 ^ uVar18) & uVar20 ^ uVar18);
        uVar12 = uVar12 + iVar19;
        uVar50 = VectorShiftRight(auVar38._8_8_,0x13);
        uVar49 = VectorShiftLeftInsert(uVar50,auVar38._8_8_,0xd);
        uVar22 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
                 ((uVar26 ^ uVar9) & (uVar24 ^ uVar26) ^ uVar26);
        auVar39._0_8_ = VectorAdd(auVar40._0_8_,uVar51 ^ uVar48 ^ uVar49,4);
        uVar16 = uVar12 ^ (uVar12 >> 5 | uVar12 * 0x8000000) ^ (uVar12 >> 0x13 | uVar12 * 0x2000);
        uVar50 = VectorShiftRight(auVar39._0_8_,0x11);
        uVar48 = VectorShiftLeftInsert(uVar50,auVar39._0_8_,0xf);
        uVar51 = VectorShiftRight(auVar39._0_8_,10);
        uVar14 = uVar22 ^ (uVar22 >> 0xb | uVar22 * 0x200000) ^ (uVar22 >> 0x14 | uVar22 * 0x1000);
        iVar19 = uVar18 + (uint)local_48 + (uVar16 >> 6 | uVar16 << 0x1a) +
                 ((uVar20 ^ uVar21) & uVar12 ^ uVar21);
        uVar50 = VectorShiftRight(auVar39._0_8_,0x13);
        uVar9 = uVar9 + iVar19;
        uVar49 = VectorShiftLeftInsert(uVar50,auVar39._0_8_,0xd);
        uVar17 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
                 ((uVar24 ^ uVar26) & (uVar22 ^ uVar24) ^ uVar24);
        auVar39._8_8_ = VectorAdd(auVar40._8_8_,uVar51 ^ uVar48 ^ uVar49,4);
        uVar18 = uVar9 ^ (uVar9 >> 5 | uVar9 * 0x8000000) ^ (uVar9 >> 0x13 | uVar9 * 0x2000);
        auVar40 = VectorAdd(pauVar11[3],auVar39,4);
        uVar14 = uVar17 ^ uVar22;
        uVar16 = uVar17 ^ (uVar17 >> 0xb | uVar17 * 0x200000) ^ (uVar17 >> 0x14 | uVar17 * 0x1000);
        iVar28 = uVar21 + local_48._4_4_ + (uVar18 >> 6 | uVar18 << 0x1a) +
                 ((uVar12 ^ uVar20) & uVar9 ^ uVar20);
        uVar26 = uVar26 + iVar28;
        local_50 = auVar40._0_8_;
        local_48 = auVar40._8_8_;
        iVar28 = iVar28 + (uVar16 >> 2 | uVar16 << 0x1e);
        uVar16 = (uVar22 ^ uVar24) & uVar14 ^ uVar22;
        uStack_80._0_4_ = auVar41._0_4_;
        iVar19 = (int)uStack_80;
        pauVar10 = pauVar11 + 4;
        uVar50 = auVar41._0_8_;
      } while (*(int *)pauVar11[4] != 0);
      bVar33 = local_3c == param_2 + param_3 * 4;
      pauVar10 = local_3c;
      if (bVar33) {
        pauVar10 = local_3c + -4;
      }
      if (!bVar33) {
        local_3c = pauVar10 + 4;
      }
      uVar16 = iVar28 + uVar16;
      uVar21 = uVar26 ^ (uVar26 >> 5 | uVar26 * 0x8000000) ^ (uVar26 >> 0x13 | uVar26 * 0x2000);
      auVar36 = vrev(*pauVar10,1);
      uVar18 = uVar16 ^ (uVar16 >> 0xb | uVar16 * 0x200000) ^ (uVar16 >> 0x14 | uVar16 * 0x1000);
      iVar19 = uVar20 + (int)uStack_80 + (uVar21 >> 6 | uVar21 << 0x1a) +
               ((uVar9 ^ uVar12) & uVar26 ^ uVar12);
      auVar44 = VectorAdd(pauVar11[-0xc],auVar36,4);
      uStack_80._4_4_ = auVar41._4_4_;
      uVar24 = uVar24 + iVar19;
      uVar27 = iVar19 + (uVar18 >> 2 | uVar18 << 0x1e) + (uVar14 & (uVar16 ^ uVar17) ^ uVar17);
      uVar20 = uVar24 ^ (uVar24 >> 5 | uVar24 * 0x8000000) ^ (uVar24 >> 0x13 | uVar24 * 0x2000);
      uVar14 = uVar27 ^ (uVar27 >> 0xb | uVar27 * 0x200000) ^ (uVar27 >> 0x14 | uVar27 * 0x1000);
      iVar19 = uVar12 + uStack_80._4_4_ + (uVar20 >> 6 | uVar20 << 0x1a) +
               ((uVar26 ^ uVar9) & uVar24 ^ uVar9);
      uStack_78._0_4_ = auVar41._8_4_;
      uVar22 = uVar22 + iVar19;
      uVar12 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar16 ^ uVar17) & (uVar27 ^ uVar16) ^ uVar16);
      uVar20 = uVar22 ^ (uVar22 >> 5 | uVar22 * 0x8000000) ^ (uVar22 >> 0x13 | uVar22 * 0x2000);
      uVar14 = uVar12 ^ (uVar12 >> 0xb | uVar12 * 0x200000) ^ (uVar12 >> 0x14 | uVar12 * 0x1000);
      iVar19 = uVar9 + (int)uStack_78 + (uVar20 >> 6 | uVar20 << 0x1a) +
               ((uVar24 ^ uVar26) & uVar22 ^ uVar26);
      uStack_78._4_4_ = auVar41._12_4_;
      uVar17 = uVar17 + iVar19;
      uVar25 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar27 ^ uVar16) & (uVar12 ^ uVar27) ^ uVar27);
      uVar9 = uVar17 ^ (uVar17 >> 5 | uVar17 * 0x8000000) ^ (uVar17 >> 0x13 | uVar17 * 0x2000);
      uVar14 = uVar25 ^ (uVar25 >> 0xb | uVar25 * 0x200000) ^ (uVar25 >> 0x14 | uVar25 * 0x1000);
      iVar19 = uVar26 + uStack_78._4_4_ + (uVar9 >> 6 | uVar9 << 0x1a) +
               ((uVar22 ^ uVar24) & uVar17 ^ uVar24);
      local_70._0_4_ = auVar42._0_4_;
      uVar16 = uVar16 + iVar19;
      uStack_78 = auVar44._8_8_;
      uVar23 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar12 ^ uVar27) & (uVar25 ^ uVar12) ^ uVar12);
      uVar26 = uVar16 ^ (uVar16 >> 5 | uVar16 * 0x8000000) ^ (uVar16 >> 0x13 | uVar16 * 0x2000);
      auVar37 = vrev(pauVar10[1],1);
      uVar14 = uVar23 ^ (uVar23 >> 0xb | uVar23 * 0x200000) ^ (uVar23 >> 0x14 | uVar23 * 0x1000);
      iVar19 = uVar24 + (uint)local_70 + (uVar26 >> 6 | uVar26 << 0x1a) +
               ((uVar17 ^ uVar22) & uVar16 ^ uVar22);
      auVar38 = VectorAdd(pauVar11[-0xb],auVar37,4);
      local_70._4_4_ = auVar42._4_4_;
      uVar27 = uVar27 + iVar19;
      uVar21 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar25 ^ uVar12) & (uVar23 ^ uVar25) ^ uVar25);
      uVar24 = uVar27 ^ (uVar27 >> 5 | uVar27 * 0x8000000) ^ (uVar27 >> 0x13 | uVar27 * 0x2000);
      uVar14 = uVar21 ^ (uVar21 >> 0xb | uVar21 * 0x200000) ^ (uVar21 >> 0x14 | uVar21 * 0x1000);
      iVar19 = uVar22 + local_70._4_4_ + (uVar24 >> 6 | uVar24 << 0x1a) +
               ((uVar16 ^ uVar17) & uVar27 ^ uVar17);
      local_68._0_4_ = auVar42._8_4_;
      uVar12 = uVar12 + iVar19;
      uVar22 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar23 ^ uVar25) & (uVar21 ^ uVar23) ^ uVar23);
      uVar24 = uVar12 ^ (uVar12 >> 5 | uVar12 * 0x8000000) ^ (uVar12 >> 0x13 | uVar12 * 0x2000);
      uVar14 = uVar22 ^ (uVar22 >> 0xb | uVar22 * 0x200000) ^ (uVar22 >> 0x14 | uVar22 * 0x1000);
      iVar19 = uVar17 + (uint)local_68 + (uVar24 >> 6 | uVar24 << 0x1a) +
               ((uVar27 ^ uVar16) & uVar12 ^ uVar16);
      local_68._4_4_ = auVar42._12_4_;
      uVar25 = uVar25 + iVar19;
      uVar18 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar21 ^ uVar23) & (uVar22 ^ uVar21) ^ uVar21);
      uVar17 = uVar25 ^ (uVar25 >> 5 | uVar25 * 0x8000000) ^ (uVar25 >> 0x13 | uVar25 * 0x2000);
      uVar14 = uVar18 ^ (uVar18 >> 0xb | uVar18 * 0x200000) ^ (uVar18 >> 0x14 | uVar18 * 0x1000);
      iVar19 = uVar16 + local_68._4_4_ + (uVar17 >> 6 | uVar17 << 0x1a) +
               ((uVar12 ^ uVar27) & uVar25 ^ uVar27);
      local_60._0_4_ = auVar43._0_4_;
      uVar23 = uVar23 + iVar19;
      local_70 = auVar38._0_8_;
      local_68 = auVar38._8_8_;
      uVar26 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar22 ^ uVar21) & (uVar18 ^ uVar22) ^ uVar22);
      uVar16 = uVar23 ^ (uVar23 >> 5 | uVar23 * 0x8000000) ^ (uVar23 >> 0x13 | uVar23 * 0x2000);
      auVar38 = vrev(pauVar10[2],1);
      uVar14 = uVar26 ^ (uVar26 >> 0xb | uVar26 * 0x200000) ^ (uVar26 >> 0x14 | uVar26 * 0x1000);
      iVar19 = uVar27 + (uint)local_60 + (uVar16 >> 6 | uVar16 << 0x1a) +
               ((uVar25 ^ uVar12) & uVar23 ^ uVar12);
      auVar39 = VectorAdd(pauVar11[-10],auVar38,4);
      local_60._4_4_ = auVar43._4_4_;
      uVar21 = uVar21 + iVar19;
      uVar20 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar18 ^ uVar22) & (uVar26 ^ uVar18) ^ uVar18);
      uVar16 = uVar21 ^ (uVar21 >> 5 | uVar21 * 0x8000000) ^ (uVar21 >> 0x13 | uVar21 * 0x2000);
      uVar14 = uVar20 ^ (uVar20 >> 0xb | uVar20 * 0x200000) ^ (uVar20 >> 0x14 | uVar20 * 0x1000);
      iVar19 = uVar12 + local_60._4_4_ + (uVar16 >> 6 | uVar16 << 0x1a) +
               ((uVar23 ^ uVar25) & uVar21 ^ uVar25);
      local_58._0_4_ = auVar43._8_4_;
      uVar22 = uVar22 + iVar19;
      uVar12 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar26 ^ uVar18) & (uVar20 ^ uVar26) ^ uVar26);
      uVar16 = uVar22 ^ (uVar22 >> 5 | uVar22 * 0x8000000) ^ (uVar22 >> 0x13 | uVar22 * 0x2000);
      uVar14 = uVar12 ^ (uVar12 >> 0xb | uVar12 * 0x200000) ^ (uVar12 >> 0x14 | uVar12 * 0x1000);
      iVar19 = uVar25 + (uint)local_58 + (uVar16 >> 6 | uVar16 << 0x1a) +
               ((uVar21 ^ uVar23) & uVar22 ^ uVar23);
      local_58._4_4_ = auVar43._12_4_;
      uVar18 = uVar18 + iVar19;
      uVar9 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
              ((uVar20 ^ uVar26) & (uVar12 ^ uVar20) ^ uVar20);
      uVar16 = uVar18 ^ (uVar18 >> 5 | uVar18 * 0x8000000) ^ (uVar18 >> 0x13 | uVar18 * 0x2000);
      uVar14 = uVar9 ^ (uVar9 >> 0xb | uVar9 * 0x200000) ^ (uVar9 >> 0x14 | uVar9 * 0x1000);
      iVar19 = uVar23 + local_58._4_4_ + (uVar16 >> 6 | uVar16 << 0x1a) +
               ((uVar22 ^ uVar21) & uVar18 ^ uVar21);
      local_50._0_4_ = auVar40._0_4_;
      uVar26 = uVar26 + iVar19;
      local_60 = auVar39._0_8_;
      local_58 = auVar39._8_8_;
      uVar23 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar12 ^ uVar20) & (uVar9 ^ uVar12) ^ uVar12);
      uVar16 = uVar26 ^ (uVar26 >> 5 | uVar26 * 0x8000000) ^ (uVar26 >> 0x13 | uVar26 * 0x2000);
      auVar39 = vrev(pauVar10[3],1);
      uVar14 = uVar23 ^ (uVar23 >> 0xb | uVar23 * 0x200000) ^ (uVar23 >> 0x14 | uVar23 * 0x1000);
      iVar19 = uVar21 + (uint)local_50 + (uVar16 >> 6 | uVar16 << 0x1a) +
               ((uVar18 ^ uVar22) & uVar26 ^ uVar22);
      auVar41 = VectorAdd(pauVar11[-9],auVar39,4);
      local_50._4_4_ = auVar40._4_4_;
      uVar20 = uVar20 + iVar19;
      uVar24 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar9 ^ uVar12) & (uVar23 ^ uVar9) ^ uVar9);
      uVar16 = uVar20 ^ (uVar20 >> 5 | uVar20 * 0x8000000) ^ (uVar20 >> 0x13 | uVar20 * 0x2000);
      uVar14 = uVar24 ^ (uVar24 >> 0xb | uVar24 * 0x200000) ^ (uVar24 >> 0x14 | uVar24 * 0x1000);
      iVar19 = uVar22 + local_50._4_4_ + (uVar16 >> 6 | uVar16 << 0x1a) +
               ((uVar26 ^ uVar18) & uVar20 ^ uVar18);
      local_48._0_4_ = auVar40._8_4_;
      uVar12 = uVar12 + iVar19;
      uVar22 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar23 ^ uVar9) & (uVar24 ^ uVar23) ^ uVar23);
      uVar16 = uVar12 ^ (uVar12 >> 5 | uVar12 * 0x8000000) ^ (uVar12 >> 0x13 | uVar12 * 0x2000);
      uVar14 = uVar22 ^ (uVar22 >> 0xb | uVar22 * 0x200000) ^ (uVar22 >> 0x14 | uVar22 * 0x1000);
      iVar19 = uVar18 + (uint)local_48 + (uVar16 >> 6 | uVar16 << 0x1a) +
               ((uVar20 ^ uVar26) & uVar12 ^ uVar26);
      local_48._4_4_ = auVar40._12_4_;
      uVar9 = uVar9 + iVar19;
      uVar17 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar24 ^ uVar23) & (uVar22 ^ uVar24) ^ uVar24);
      uVar16 = uVar9 ^ (uVar9 >> 5 | uVar9 * 0x8000000) ^ (uVar9 >> 0x13 | uVar9 * 0x2000);
      uVar14 = uVar17 ^ (uVar17 >> 0xb | uVar17 * 0x200000) ^ (uVar17 >> 0x14 | uVar17 * 0x1000);
      iVar15 = uVar26 + local_48._4_4_ + (uVar16 >> 6 | uVar16 << 0x1a) +
               ((uVar12 ^ uVar20) & uVar9 ^ uVar20);
      local_50 = auVar41._0_8_;
      local_48 = auVar41._8_8_;
      iVar28 = iVar15 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar22 ^ uVar24) & (uVar17 ^ uVar22) ^ uVar22) + *(int *)*param_1;
      uVar17 = uVar17 + *(int *)(*param_1 + 4);
      iVar30 = *(int *)(param_1[1] + 4);
      uVar22 = uVar22 + *(int *)(*param_1 + 8);
      iVar13 = *(int *)(param_1[1] + 8);
      uVar24 = uVar24 + *(int *)(*param_1 + 0xc);
      iVar19 = *(int *)(param_1[1] + 0xc);
      uVar26 = uVar23 + iVar15 + *(int *)param_1[1];
      *(int *)*param_1 = iVar28;
      uVar9 = uVar9 + iVar30;
      *(uint *)(*param_1 + 4) = uVar17;
      uVar12 = uVar12 + iVar13;
      *(uint *)(*param_1 + 8) = uVar22;
      uVar20 = uVar20 + iVar19;
      *(uint *)(*param_1 + 0xc) = uVar24;
      *(uint *)param_1[1] = uVar26;
      *(uint *)(param_1[1] + 4) = uVar9;
      *(uint *)(param_1[1] + 8) = uVar12;
      *(uint *)(param_1[1] + 0xc) = uVar20;
      if (bVar33) break;
      uStack_80._0_4_ = auVar44._0_4_;
      uVar16 = 0;
      uVar14 = uVar17 ^ uVar22;
      iVar19 = (int)uStack_80;
      pauVar10 = pauVar11 + -8;
      uVar50 = auVar44._0_8_;
    }
    return;
  }
  uVar14 = *(uint *)*param_1;
  uVar16 = *(uint *)(*param_1 + 4);
  uVar17 = *(uint *)(*param_1 + 8);
  iVar19 = *(int *)(*param_1 + 0xc);
  uVar22 = *(uint *)param_1[1];
  uVar24 = *(uint *)(param_1[1] + 4);
  uVar26 = *(uint *)(param_1[1] + 8);
  iVar28 = *(int *)(param_1[1] + 0xc);
  piVar31 = (int *)&DAT_001c14e0;
  local_2c = param_2;
  do {
    uVar12 = *(uint *)*local_2c;
    uVar9 = uVar22 ^ (uVar22 >> 5 | uVar22 << 0x1b) ^ (uVar22 >> 0x13 | uVar22 << 0xd);
    local_70._0_4_ =
         uVar12 << 0x18 | (uVar12 >> 8 & 0xff) << 0x10 | (uVar12 >> 0x10 & 0xff) << 8 |
         uVar12 >> 0x18;
    iVar28 = iVar28 + (uint)local_70 + (uVar9 >> 6 | uVar9 << 0x1a) + *piVar31 +
             ((uVar24 ^ uVar26) & uVar22 ^ uVar26);
    uVar12 = *(uint *)(*local_2c + 4);
    uVar9 = uVar14 ^ (uVar14 >> 0xb | uVar14 << 0x15) ^ (uVar14 >> 0x14 | uVar14 << 0xc);
    uVar20 = iVar19 + iVar28;
    uVar29 = iVar28 + (uVar9 >> 2 | uVar9 << 0x1e) +
             ((uVar16 ^ uVar17) & (uVar14 ^ uVar16) ^ uVar16);
    uVar9 = uVar20 ^ (uVar20 >> 5 | uVar20 * 0x8000000) ^ (uVar20 >> 0x13 | uVar20 * 0x2000);
    uVar12 = uVar12 << 0x18 | (uVar12 >> 8 & 0xff) << 0x10 | (uVar12 >> 0x10 & 0xff) << 8 |
             uVar12 >> 0x18;
    iVar19 = uVar26 + uVar12 + (uVar9 >> 6 | uVar9 << 0x1a) + piVar31[1] +
             ((uVar22 ^ uVar24) & uVar20 ^ uVar24);
    uVar9 = *(uint *)(*local_2c + 8);
    uVar26 = uVar29 ^ (uVar29 >> 0xb | uVar29 * 0x200000) ^ (uVar29 >> 0x14 | uVar29 * 0x1000);
    uVar17 = uVar17 + iVar19;
    uVar27 = iVar19 + (uVar26 >> 2 | uVar26 << 0x1e) +
             ((uVar14 ^ uVar16) & (uVar29 ^ uVar14) ^ uVar14);
    uVar26 = uVar17 ^ (uVar17 >> 5 | uVar17 * 0x8000000) ^ (uVar17 >> 0x13 | uVar17 * 0x2000);
    local_68._0_4_ =
         uVar9 << 0x18 | (uVar9 >> 8 & 0xff) << 0x10 | (uVar9 >> 0x10 & 0xff) << 8 | uVar9 >> 0x18;
    iVar19 = uVar24 + (uint)local_68 + (uVar26 >> 6 | uVar26 << 0x1a) + piVar31[2] +
             ((uVar20 ^ uVar22) & uVar17 ^ uVar22);
    uVar26 = *(uint *)(*local_2c + 0xc);
    uVar24 = uVar27 ^ (uVar27 >> 0xb | uVar27 * 0x200000) ^ (uVar27 >> 0x14 | uVar27 * 0x1000);
    uVar16 = uVar16 + iVar19;
    uVar25 = iVar19 + (uVar24 >> 2 | uVar24 << 0x1e) +
             ((uVar29 ^ uVar14) & (uVar27 ^ uVar29) ^ uVar29);
    uVar24 = uVar16 ^ (uVar16 >> 5 | uVar16 * 0x8000000) ^ (uVar16 >> 0x13 | uVar16 * 0x2000);
    local_68._4_4_ =
         uVar26 << 0x18 | (uVar26 >> 8 & 0xff) << 0x10 | (uVar26 >> 0x10 & 0xff) << 8 |
         uVar26 >> 0x18;
    iVar19 = uVar22 + local_68._4_4_ + (uVar24 >> 6 | uVar24 << 0x1a) + piVar31[3] +
             ((uVar17 ^ uVar20) & uVar16 ^ uVar20);
    uVar24 = *(uint *)local_2c[1];
    uVar22 = uVar25 ^ (uVar25 >> 0xb | uVar25 * 0x200000) ^ (uVar25 >> 0x14 | uVar25 * 0x1000);
    uVar14 = uVar14 + iVar19;
    uVar23 = iVar19 + (uVar22 >> 2 | uVar22 << 0x1e) +
             ((uVar27 ^ uVar29) & (uVar25 ^ uVar27) ^ uVar27);
    uVar22 = uVar14 ^ (uVar14 >> 5 | uVar14 * 0x8000000) ^ (uVar14 >> 0x13 | uVar14 * 0x2000);
    local_60._0_4_ =
         uVar24 << 0x18 | (uVar24 >> 8 & 0xff) << 0x10 | (uVar24 >> 0x10 & 0xff) << 8 |
         uVar24 >> 0x18;
    iVar19 = uVar20 + (uint)local_60 + (uVar22 >> 6 | uVar22 << 0x1a) + piVar31[4] +
             ((uVar16 ^ uVar17) & uVar14 ^ uVar17);
    uVar24 = *(uint *)(local_2c[1] + 4);
    uVar22 = uVar23 ^ (uVar23 >> 0xb | uVar23 * 0x200000) ^ (uVar23 >> 0x14 | uVar23 * 0x1000);
    uVar29 = uVar29 + iVar19;
    uVar21 = iVar19 + (uVar22 >> 2 | uVar22 << 0x1e) +
             ((uVar25 ^ uVar27) & (uVar23 ^ uVar25) ^ uVar25);
    uVar22 = uVar29 ^ (uVar29 >> 5 | uVar29 * 0x8000000) ^ (uVar29 >> 0x13 | uVar29 * 0x2000);
    local_60._4_4_ =
         uVar24 << 0x18 | (uVar24 >> 8 & 0xff) << 0x10 | (uVar24 >> 0x10 & 0xff) << 8 |
         uVar24 >> 0x18;
    iVar19 = uVar17 + local_60._4_4_ + (uVar22 >> 6 | uVar22 << 0x1a) + piVar31[5] +
             ((uVar14 ^ uVar16) & uVar29 ^ uVar16);
    uVar22 = *(uint *)(local_2c[1] + 8);
    uVar17 = uVar21 ^ (uVar21 >> 0xb | uVar21 * 0x200000) ^ (uVar21 >> 0x14 | uVar21 * 0x1000);
    uVar27 = uVar27 + iVar19;
    uVar18 = iVar19 + (uVar17 >> 2 | uVar17 << 0x1e) +
             ((uVar23 ^ uVar25) & (uVar21 ^ uVar23) ^ uVar23);
    uVar17 = uVar27 ^ (uVar27 >> 5 | uVar27 * 0x8000000) ^ (uVar27 >> 0x13 | uVar27 * 0x2000);
    local_58._0_4_ =
         uVar22 << 0x18 | (uVar22 >> 8 & 0xff) << 0x10 | (uVar22 >> 0x10 & 0xff) << 8 |
         uVar22 >> 0x18;
    iVar19 = uVar16 + (uint)local_58 + (uVar17 >> 6 | uVar17 << 0x1a) + piVar31[6] +
             ((uVar29 ^ uVar14) & uVar27 ^ uVar14);
    uVar17 = *(uint *)(local_2c[1] + 0xc);
    uVar16 = uVar18 ^ (uVar18 >> 0xb | uVar18 * 0x200000) ^ (uVar18 >> 0x14 | uVar18 * 0x1000);
    uVar25 = uVar25 + iVar19;
    uVar9 = iVar19 + (uVar16 >> 2 | uVar16 << 0x1e) +
            ((uVar21 ^ uVar23) & (uVar18 ^ uVar21) ^ uVar21);
    uVar16 = uVar25 ^ (uVar25 >> 5 | uVar25 * 0x8000000) ^ (uVar25 >> 0x13 | uVar25 * 0x2000);
    local_58._4_4_ =
         uVar17 << 0x18 | (uVar17 >> 8 & 0xff) << 0x10 | (uVar17 >> 0x10 & 0xff) << 8 |
         uVar17 >> 0x18;
    iVar19 = uVar14 + local_58._4_4_ + (uVar16 >> 6 | uVar16 << 0x1a) + piVar31[7] +
             ((uVar27 ^ uVar29) & uVar25 ^ uVar29);
    uVar16 = *(uint *)local_2c[2];
    uVar14 = uVar9 ^ (uVar9 >> 0xb | uVar9 * 0x200000) ^ (uVar9 >> 0x14 | uVar9 * 0x1000);
    uVar23 = uVar23 + iVar19;
    uVar20 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
             ((uVar18 ^ uVar21) & (uVar9 ^ uVar18) ^ uVar18);
    uVar14 = uVar23 ^ (uVar23 >> 5 | uVar23 * 0x8000000) ^ (uVar23 >> 0x13 | uVar23 * 0x2000);
    local_50._0_4_ =
         uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 | (uVar16 >> 0x10 & 0xff) << 8 |
         uVar16 >> 0x18;
    iVar19 = uVar29 + (uint)local_50 + (uVar14 >> 6 | uVar14 << 0x1a) + piVar31[8] +
             ((uVar25 ^ uVar27) & uVar23 ^ uVar27);
    uVar16 = *(uint *)(local_2c[2] + 4);
    uVar14 = uVar20 ^ (uVar20 >> 0xb | uVar20 * 0x200000) ^ (uVar20 >> 0x14 | uVar20 * 0x1000);
    uVar21 = uVar21 + iVar19;
    uVar29 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) + ((uVar9 ^ uVar18) & (uVar20 ^ uVar9) ^ uVar9)
    ;
    uVar14 = uVar21 ^ (uVar21 >> 5 | uVar21 * 0x8000000) ^ (uVar21 >> 0x13 | uVar21 * 0x2000);
    local_50._4_4_ =
         uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 | (uVar16 >> 0x10 & 0xff) << 8 |
         uVar16 >> 0x18;
    iVar19 = uVar27 + local_50._4_4_ + (uVar14 >> 6 | uVar14 << 0x1a) + piVar31[9] +
             ((uVar23 ^ uVar25) & uVar21 ^ uVar25);
    uVar16 = *(uint *)(local_2c[2] + 8);
    uVar14 = uVar29 ^ (uVar29 >> 0xb | uVar29 * 0x200000) ^ (uVar29 >> 0x14 | uVar29 * 0x1000);
    uVar18 = uVar18 + iVar19;
    uVar26 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
             ((uVar20 ^ uVar9) & (uVar29 ^ uVar20) ^ uVar20);
    uVar14 = uVar18 ^ (uVar18 >> 5 | uVar18 * 0x8000000) ^ (uVar18 >> 0x13 | uVar18 * 0x2000);
    local_48._0_4_ =
         uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 | (uVar16 >> 0x10 & 0xff) << 8 |
         uVar16 >> 0x18;
    iVar19 = uVar25 + (uint)local_48 + (uVar14 >> 6 | uVar14 << 0x1a) + piVar31[10] +
             ((uVar21 ^ uVar23) & uVar18 ^ uVar23);
    uVar16 = *(uint *)(local_2c[2] + 0xc);
    uVar14 = uVar26 ^ (uVar26 >> 0xb | uVar26 * 0x200000) ^ (uVar26 >> 0x14 | uVar26 * 0x1000);
    uVar9 = uVar9 + iVar19;
    uVar24 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
             ((uVar29 ^ uVar20) & (uVar26 ^ uVar29) ^ uVar29);
    uVar14 = uVar9 ^ (uVar9 >> 5 | uVar9 * 0x8000000) ^ (uVar9 >> 0x13 | uVar9 * 0x2000);
    local_48._4_4_ =
         uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 | (uVar16 >> 0x10 & 0xff) << 8 |
         uVar16 >> 0x18;
    iVar19 = uVar23 + local_48._4_4_ + (uVar14 >> 6 | uVar14 << 0x1a) + piVar31[0xb] +
             ((uVar18 ^ uVar21) & uVar9 ^ uVar21);
    uVar16 = *(uint *)local_2c[3];
    uVar14 = uVar24 ^ (uVar24 >> 0xb | uVar24 * 0x200000) ^ (uVar24 >> 0x14 | uVar24 * 0x1000);
    uVar20 = uVar20 + iVar19;
    uVar22 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
             ((uVar26 ^ uVar29) & (uVar24 ^ uVar26) ^ uVar26);
    uVar14 = uVar20 ^ (uVar20 >> 5 | uVar20 * 0x8000000) ^ (uVar20 >> 0x13 | uVar20 * 0x2000);
    local_40 = uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 | (uVar16 >> 0x10 & 0xff) << 8 |
               uVar16 >> 0x18;
    iVar19 = uVar21 + local_40 + (uVar14 >> 6 | uVar14 << 0x1a) + piVar31[0xc] +
             ((uVar9 ^ uVar18) & uVar20 ^ uVar18);
    uVar16 = *(uint *)(local_2c[3] + 4);
    uVar14 = uVar22 ^ (uVar22 >> 0xb | uVar22 * 0x200000) ^ (uVar22 >> 0x14 | uVar22 * 0x1000);
    uVar29 = uVar29 + iVar19;
    uVar21 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
             ((uVar24 ^ uVar26) & (uVar22 ^ uVar24) ^ uVar24);
    uVar14 = uVar29 ^ (uVar29 >> 5 | uVar29 * 0x8000000) ^ (uVar29 >> 0x13 | uVar29 * 0x2000);
    local_3c = (undefined1 (*) [16])
               (uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 | (uVar16 >> 0x10 & 0xff) << 8 |
               uVar16 >> 0x18);
    iVar19 = uVar18 + (int)local_3c + (uVar14 >> 6 | uVar14 << 0x1a) + piVar31[0xd] +
             ((uVar20 ^ uVar9) & uVar29 ^ uVar9);
    pauVar10 = local_2c + 3;
    uVar16 = *(uint *)(local_2c[3] + 8);
    uVar14 = uVar21 ^ (uVar21 >> 0xb | uVar21 * 0x200000) ^ (uVar21 >> 0x14 | uVar21 * 0x1000);
    uVar26 = uVar26 + iVar19;
    uVar17 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
             ((uVar22 ^ uVar24) & (uVar21 ^ uVar22) ^ uVar22);
    uVar14 = uVar26 ^ (uVar26 >> 5 | uVar26 * 0x8000000) ^ (uVar26 >> 0x13 | uVar26 * 0x2000);
    local_38 = uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 | (uVar16 >> 0x10 & 0xff) << 8 |
               uVar16 >> 0x18;
    iVar19 = uVar9 + local_38 + (uVar14 >> 6 | uVar14 << 0x1a) + piVar31[0xe] +
             ((uVar29 ^ uVar20) & uVar26 ^ uVar20);
    local_2c = local_2c + 4;
    uVar9 = *(uint *)(*pauVar10 + 0xc);
    uVar14 = uVar17 ^ (uVar17 >> 0xb | uVar17 * 0x200000) ^ (uVar17 >> 0x14 | uVar17 * 0x1000);
    uVar24 = uVar24 + iVar19;
    uVar16 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
             ((uVar21 ^ uVar22) & (uVar17 ^ uVar21) ^ uVar21);
    uVar14 = uVar24 ^ (uVar24 >> 5 | uVar24 * 0x8000000) ^ (uVar24 >> 0x13 | uVar24 * 0x2000);
    local_34 = uVar9 << 0x18 | (uVar9 >> 8 & 0xff) << 0x10 | (uVar9 >> 0x10 & 0xff) << 8 |
               uVar9 >> 0x18;
    iVar19 = uVar20 + local_34 + (uVar14 >> 6 | uVar14 << 0x1a) + piVar31[0xf] +
             ((uVar26 ^ uVar29) & uVar24 ^ uVar29);
    uVar9 = uVar16 ^ uVar17;
    uVar14 = uVar16 ^ (uVar16 >> 0xb | uVar16 * 0x200000) ^ (uVar16 >> 0x14 | uVar16 * 0x1000);
    uVar22 = uVar22 + iVar19;
    uVar20 = (uVar17 ^ uVar21) & uVar9 ^ uVar17;
    iVar19 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e);
    do {
      piVar32 = piVar31;
      uVar20 = iVar19 + uVar20;
      uVar14 = uVar22 ^ (uVar22 >> 5 | uVar22 << 0x1b) ^ (uVar22 >> 0x13 | uVar22 << 0xd);
      local_70._0_4_ =
           (uint)local_70 +
           ((local_38 >> 0x11 | local_38 << 0xf) ^ (local_38 >> 0x13 | local_38 << 0xd) ^
           local_38 >> 10) +
           ((uVar12 >> 7 | uVar12 << 0x19) ^ (uVar12 >> 0x12 | uVar12 << 0xe) ^ uVar12 >> 3) +
           local_50._4_4_;
      iVar19 = uVar29 + (uint)local_70 + (uVar14 >> 6 | uVar14 << 0x1a) + piVar32[0x10] +
               ((uVar24 ^ uVar26) & uVar22 ^ uVar26);
      uVar14 = uVar20 ^ (uVar20 >> 0xb | uVar20 * 0x200000) ^ (uVar20 >> 0x14 | uVar20 * 0x1000);
      uVar21 = uVar21 + iVar19;
      uVar23 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) + (uVar9 & (uVar20 ^ uVar16) ^ uVar16);
      uVar14 = uVar21 ^ (uVar21 >> 5 | uVar21 * 0x8000000) ^ (uVar21 >> 0x13 | uVar21 * 0x2000);
      uVar12 = uVar12 + ((local_34 >> 0x11 | local_34 << 0xf) ^ (local_34 >> 0x13 | local_34 << 0xd)
                        ^ local_34 >> 10) +
                        (((uint)local_68 >> 7 | (uint)local_68 << 0x19) ^
                         ((uint)local_68 >> 0x12 | (uint)local_68 << 0xe) ^ (uint)local_68 >> 3) +
               (uint)local_48;
      iVar19 = uVar26 + uVar12 + (uVar14 >> 6 | uVar14 << 0x1a) + piVar32[0x11] +
               ((uVar22 ^ uVar24) & uVar21 ^ uVar24);
      uVar14 = uVar23 ^ (uVar23 >> 0xb | uVar23 * 0x200000) ^ (uVar23 >> 0x14 | uVar23 * 0x1000);
      uVar17 = uVar17 + iVar19;
      uVar26 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar20 ^ uVar16) & (uVar23 ^ uVar20) ^ uVar20);
      uVar14 = uVar17 ^ (uVar17 >> 5 | uVar17 * 0x8000000) ^ (uVar17 >> 0x13 | uVar17 * 0x2000);
      local_68._0_4_ =
           (uint)local_68 +
           (((uint)local_70 >> 0x11 | (uint)local_70 * 0x8000) ^
            ((uint)local_70 >> 0x13 | (uint)local_70 * 0x2000) ^ (uint)local_70 >> 10) +
           ((local_68._4_4_ >> 7 | local_68._4_4_ << 0x19) ^
            (local_68._4_4_ >> 0x12 | local_68._4_4_ << 0xe) ^ local_68._4_4_ >> 3) + local_48._4_4_
      ;
      iVar19 = uVar24 + (uint)local_68 + (uVar14 >> 6 | uVar14 << 0x1a) + piVar32[0x12] +
               ((uVar21 ^ uVar22) & uVar17 ^ uVar22);
      uVar14 = uVar26 ^ (uVar26 >> 0xb | uVar26 * 0x200000) ^ (uVar26 >> 0x14 | uVar26 * 0x1000);
      uVar16 = uVar16 + iVar19;
      uVar24 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar23 ^ uVar20) & (uVar26 ^ uVar23) ^ uVar23);
      uVar14 = uVar16 ^ (uVar16 >> 5 | uVar16 * 0x8000000) ^ (uVar16 >> 0x13 | uVar16 * 0x2000);
      local_68._4_4_ =
           local_68._4_4_ +
           ((uVar12 >> 0x11 | uVar12 * 0x8000) ^ (uVar12 >> 0x13 | uVar12 * 0x2000) ^ uVar12 >> 10)
           + (((uint)local_60 >> 7 | (uint)local_60 << 0x19) ^
              ((uint)local_60 >> 0x12 | (uint)local_60 << 0xe) ^ (uint)local_60 >> 3) + local_40;
      iVar19 = uVar22 + local_68._4_4_ + (uVar14 >> 6 | uVar14 << 0x1a) + piVar32[0x13] +
               ((uVar17 ^ uVar21) & uVar16 ^ uVar21);
      uVar14 = uVar24 ^ (uVar24 >> 0xb | uVar24 * 0x200000) ^ (uVar24 >> 0x14 | uVar24 * 0x1000);
      uVar20 = uVar20 + iVar19;
      uVar22 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar26 ^ uVar23) & (uVar24 ^ uVar26) ^ uVar26);
      uVar14 = uVar20 ^ (uVar20 >> 5 | uVar20 * 0x8000000) ^ (uVar20 >> 0x13 | uVar20 * 0x2000);
      local_60._0_4_ =
           (uint)local_60 +
           (((uint)local_68 >> 0x11 | (uint)local_68 * 0x8000) ^
            ((uint)local_68 >> 0x13 | (uint)local_68 * 0x2000) ^ (uint)local_68 >> 10) +
           ((local_60._4_4_ >> 7 | local_60._4_4_ << 0x19) ^
            (local_60._4_4_ >> 0x12 | local_60._4_4_ << 0xe) ^ local_60._4_4_ >> 3) + (int)local_3c;
      iVar19 = uVar21 + (uint)local_60 + (uVar14 >> 6 | uVar14 << 0x1a) + piVar32[0x14] +
               ((uVar16 ^ uVar17) & uVar20 ^ uVar17);
      uVar14 = uVar22 ^ (uVar22 >> 0xb | uVar22 * 0x200000) ^ (uVar22 >> 0x14 | uVar22 * 0x1000);
      uVar23 = uVar23 + iVar19;
      uVar18 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar24 ^ uVar26) & (uVar22 ^ uVar24) ^ uVar24);
      uVar14 = uVar23 ^ (uVar23 >> 5 | uVar23 * 0x8000000) ^ (uVar23 >> 0x13 | uVar23 * 0x2000);
      local_60._4_4_ =
           local_60._4_4_ +
           ((local_68._4_4_ >> 0x11 | local_68._4_4_ * 0x8000) ^
            (local_68._4_4_ >> 0x13 | local_68._4_4_ * 0x2000) ^ local_68._4_4_ >> 10) +
           (((uint)local_58 >> 7 | (uint)local_58 << 0x19) ^
            ((uint)local_58 >> 0x12 | (uint)local_58 << 0xe) ^ (uint)local_58 >> 3) + local_38;
      iVar19 = uVar17 + local_60._4_4_ + (uVar14 >> 6 | uVar14 << 0x1a) + piVar32[0x15] +
               ((uVar20 ^ uVar16) & uVar23 ^ uVar16);
      uVar14 = uVar18 ^ (uVar18 >> 0xb | uVar18 * 0x200000) ^ (uVar18 >> 0x14 | uVar18 * 0x1000);
      uVar26 = uVar26 + iVar19;
      uVar17 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar22 ^ uVar24) & (uVar18 ^ uVar22) ^ uVar22);
      uVar14 = uVar26 ^ (uVar26 >> 5 | uVar26 * 0x8000000) ^ (uVar26 >> 0x13 | uVar26 * 0x2000);
      local_58._0_4_ =
           (uint)local_58 +
           (((uint)local_60 >> 0x11 | (uint)local_60 * 0x8000) ^
            ((uint)local_60 >> 0x13 | (uint)local_60 * 0x2000) ^ (uint)local_60 >> 10) +
           ((local_58._4_4_ >> 7 | local_58._4_4_ << 0x19) ^
            (local_58._4_4_ >> 0x12 | local_58._4_4_ << 0xe) ^ local_58._4_4_ >> 3) + local_34;
      iVar19 = uVar16 + (uint)local_58 + (uVar14 >> 6 | uVar14 << 0x1a) + piVar32[0x16] +
               ((uVar23 ^ uVar20) & uVar26 ^ uVar20);
      uVar14 = uVar17 ^ (uVar17 >> 0xb | uVar17 * 0x200000) ^ (uVar17 >> 0x14 | uVar17 * 0x1000);
      uVar24 = uVar24 + iVar19;
      uVar16 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar18 ^ uVar22) & (uVar17 ^ uVar18) ^ uVar18);
      uVar14 = uVar24 ^ (uVar24 >> 5 | uVar24 * 0x8000000) ^ (uVar24 >> 0x13 | uVar24 * 0x2000);
      local_58._4_4_ =
           local_58._4_4_ +
           ((local_60._4_4_ >> 0x11 | local_60._4_4_ * 0x8000) ^
            (local_60._4_4_ >> 0x13 | local_60._4_4_ * 0x2000) ^ local_60._4_4_ >> 10) +
           (((uint)local_50 >> 7 | (uint)local_50 << 0x19) ^
            ((uint)local_50 >> 0x12 | (uint)local_50 << 0xe) ^ (uint)local_50 >> 3) + (uint)local_70
      ;
      iVar19 = uVar20 + local_58._4_4_ + (uVar14 >> 6 | uVar14 << 0x1a) + piVar32[0x17] +
               ((uVar26 ^ uVar23) & uVar24 ^ uVar23);
      uVar14 = uVar16 ^ (uVar16 >> 0xb | uVar16 * 0x200000) ^ (uVar16 >> 0x14 | uVar16 * 0x1000);
      uVar22 = uVar22 + iVar19;
      uVar9 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
              ((uVar17 ^ uVar18) & (uVar16 ^ uVar17) ^ uVar17);
      uVar14 = uVar22 ^ (uVar22 >> 5 | uVar22 * 0x8000000) ^ (uVar22 >> 0x13 | uVar22 * 0x2000);
      local_50._0_4_ =
           (uint)local_50 +
           (((uint)local_58 >> 0x11 | (uint)local_58 * 0x8000) ^
            ((uint)local_58 >> 0x13 | (uint)local_58 * 0x2000) ^ (uint)local_58 >> 10) +
           ((local_50._4_4_ >> 7 | local_50._4_4_ << 0x19) ^
            (local_50._4_4_ >> 0x12 | local_50._4_4_ << 0xe) ^ local_50._4_4_ >> 3) + uVar12;
      iVar19 = uVar23 + (uint)local_50 + (uVar14 >> 6 | uVar14 << 0x1a) + piVar32[0x18] +
               ((uVar24 ^ uVar26) & uVar22 ^ uVar26);
      uVar14 = uVar9 ^ (uVar9 >> 0xb | uVar9 * 0x200000) ^ (uVar9 >> 0x14 | uVar9 * 0x1000);
      uVar18 = uVar18 + iVar19;
      uVar29 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar16 ^ uVar17) & (uVar9 ^ uVar16) ^ uVar16);
      uVar14 = uVar18 ^ (uVar18 >> 5 | uVar18 * 0x8000000) ^ (uVar18 >> 0x13 | uVar18 * 0x2000);
      local_50._4_4_ =
           local_50._4_4_ +
           ((local_58._4_4_ >> 0x11 | local_58._4_4_ * 0x8000) ^
            (local_58._4_4_ >> 0x13 | local_58._4_4_ * 0x2000) ^ local_58._4_4_ >> 10) +
           (((uint)local_48 >> 7 | (uint)local_48 << 0x19) ^
            ((uint)local_48 >> 0x12 | (uint)local_48 << 0xe) ^ (uint)local_48 >> 3) + (uint)local_68
      ;
      iVar19 = uVar26 + local_50._4_4_ + (uVar14 >> 6 | uVar14 << 0x1a) + piVar32[0x19] +
               ((uVar22 ^ uVar24) & uVar18 ^ uVar24);
      uVar14 = uVar29 ^ (uVar29 >> 0xb | uVar29 * 0x200000) ^ (uVar29 >> 0x14 | uVar29 * 0x1000);
      uVar17 = uVar17 + iVar19;
      uVar26 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar9 ^ uVar16) & (uVar29 ^ uVar9) ^ uVar9);
      uVar14 = uVar17 ^ (uVar17 >> 5 | uVar17 * 0x8000000) ^ (uVar17 >> 0x13 | uVar17 * 0x2000);
      local_48._0_4_ =
           (uint)local_48 +
           (((uint)local_50 >> 0x11 | (uint)local_50 * 0x8000) ^
            ((uint)local_50 >> 0x13 | (uint)local_50 * 0x2000) ^ (uint)local_50 >> 10) +
           ((local_48._4_4_ >> 7 | local_48._4_4_ << 0x19) ^
            (local_48._4_4_ >> 0x12 | local_48._4_4_ << 0xe) ^ local_48._4_4_ >> 3) + local_68._4_4_
      ;
      iVar19 = uVar24 + (uint)local_48 + (uVar14 >> 6 | uVar14 << 0x1a) + piVar32[0x1a] +
               ((uVar18 ^ uVar22) & uVar17 ^ uVar22);
      uVar14 = uVar26 ^ (uVar26 >> 0xb | uVar26 * 0x200000) ^ (uVar26 >> 0x14 | uVar26 * 0x1000);
      uVar16 = uVar16 + iVar19;
      uVar24 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar29 ^ uVar9) & (uVar26 ^ uVar29) ^ uVar29);
      uVar14 = uVar16 ^ (uVar16 >> 5 | uVar16 * 0x8000000) ^ (uVar16 >> 0x13 | uVar16 * 0x2000);
      local_48._4_4_ =
           local_48._4_4_ +
           ((local_50._4_4_ >> 0x11 | local_50._4_4_ * 0x8000) ^
            (local_50._4_4_ >> 0x13 | local_50._4_4_ * 0x2000) ^ local_50._4_4_ >> 10) +
           ((local_40 >> 7 | local_40 << 0x19) ^ (local_40 >> 0x12 | local_40 << 0xe) ^
           local_40 >> 3) + (uint)local_60;
      iVar19 = uVar22 + local_48._4_4_ + (uVar14 >> 6 | uVar14 << 0x1a) + piVar32[0x1b] +
               ((uVar17 ^ uVar18) & uVar16 ^ uVar18);
      uVar14 = uVar24 ^ (uVar24 >> 0xb | uVar24 * 0x200000) ^ (uVar24 >> 0x14 | uVar24 * 0x1000);
      uVar9 = uVar9 + iVar19;
      uVar22 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar26 ^ uVar29) & (uVar24 ^ uVar26) ^ uVar26);
      uVar14 = uVar9 ^ (uVar9 >> 5 | uVar9 * 0x8000000) ^ (uVar9 >> 0x13 | uVar9 * 0x2000);
      local_40 = local_40 +
                 (((uint)local_48 >> 0x11 | (uint)local_48 * 0x8000) ^
                  ((uint)local_48 >> 0x13 | (uint)local_48 * 0x2000) ^ (uint)local_48 >> 10) +
                 (((uint)local_3c >> 7 | (int)local_3c << 0x19) ^
                  ((uint)local_3c >> 0x12 | (int)local_3c << 0xe) ^ (uint)local_3c >> 3) +
                 local_60._4_4_;
      iVar19 = uVar18 + local_40 + (uVar14 >> 6 | uVar14 << 0x1a) + piVar32[0x1c] +
               ((uVar16 ^ uVar17) & uVar9 ^ uVar17);
      uVar14 = uVar22 ^ (uVar22 >> 0xb | uVar22 * 0x200000) ^ (uVar22 >> 0x14 | uVar22 * 0x1000);
      uVar29 = uVar29 + iVar19;
      uVar21 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar24 ^ uVar26) & (uVar22 ^ uVar24) ^ uVar24);
      uVar14 = uVar29 ^ (uVar29 >> 5 | uVar29 * 0x8000000) ^ (uVar29 >> 0x13 | uVar29 * 0x2000);
      local_3c = (undefined1 (*) [16])
                 ((int)local_3c +
                  ((local_48._4_4_ >> 0x11 | local_48._4_4_ * 0x8000) ^
                   (local_48._4_4_ >> 0x13 | local_48._4_4_ * 0x2000) ^ local_48._4_4_ >> 10) +
                  ((local_38 >> 7 | local_38 << 0x19) ^ (local_38 >> 0x12 | local_38 << 0xe) ^
                  local_38 >> 3) + (uint)local_58);
      iVar19 = uVar17 + (int)local_3c + (uVar14 >> 6 | uVar14 << 0x1a) + piVar32[0x1d] +
               ((uVar9 ^ uVar16) & uVar29 ^ uVar16);
      uVar14 = uVar21 ^ (uVar21 >> 0xb | uVar21 * 0x200000) ^ (uVar21 >> 0x14 | uVar21 * 0x1000);
      uVar26 = uVar26 + iVar19;
      uVar17 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar22 ^ uVar24) & (uVar21 ^ uVar22) ^ uVar22);
      uVar14 = uVar26 ^ (uVar26 >> 5 | uVar26 * 0x8000000) ^ (uVar26 >> 0x13 | uVar26 * 0x2000);
      local_38 = local_38 +
                 ((local_40 >> 0x11 | local_40 * 0x8000) ^ (local_40 >> 0x13 | local_40 * 0x2000) ^
                 local_40 >> 10) +
                 ((local_34 >> 7 | local_34 << 0x19) ^ (local_34 >> 0x12 | local_34 << 0xe) ^
                 local_34 >> 3) + local_58._4_4_;
      iVar19 = uVar16 + local_38 + (uVar14 >> 6 | uVar14 << 0x1a) + piVar32[0x1e] +
               ((uVar29 ^ uVar9) & uVar26 ^ uVar9);
      uVar14 = uVar17 ^ (uVar17 >> 0xb | uVar17 * 0x200000) ^ (uVar17 >> 0x14 | uVar17 * 0x1000);
      uVar24 = uVar24 + iVar19;
      uVar16 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e) +
               ((uVar21 ^ uVar22) & (uVar17 ^ uVar21) ^ uVar21);
      uVar14 = uVar24 ^ (uVar24 >> 5 | uVar24 * 0x8000000) ^ (uVar24 >> 0x13 | uVar24 * 0x2000);
      local_34 = local_34 +
                 (((uint)local_3c >> 0x11 | (int)local_3c * 0x8000) ^
                  ((uint)local_3c >> 0x13 | (int)local_3c * 0x2000) ^ (uint)local_3c >> 10) +
                 (((uint)local_70 >> 7 | (uint)local_70 * 0x2000000) ^
                  ((uint)local_70 >> 0x12 | (uint)local_70 * 0x4000) ^ (uint)local_70 >> 3) +
                 (uint)local_50;
      iVar19 = uVar9 + local_34 + (uVar14 >> 6 | uVar14 << 0x1a) + piVar32[0x1f] +
               ((uVar26 ^ uVar29) & uVar24 ^ uVar29);
      uVar9 = uVar16 ^ uVar17;
      uVar14 = uVar16 ^ (uVar16 >> 0xb | uVar16 * 0x200000) ^ (uVar16 >> 0x14 | uVar16 * 0x1000);
      uVar22 = uVar22 + iVar19;
      uVar20 = (uVar17 ^ uVar21) & uVar9 ^ uVar17;
      iVar19 = iVar19 + (uVar14 >> 2 | uVar14 << 0x1e);
      piVar31 = piVar32 + 0x10;
    } while ((piVar32[0x1f] & 0xffU) != 0xf2);
    uVar14 = iVar19 + uVar20 + *(int *)*param_1;
    uVar16 = uVar16 + *(int *)(*param_1 + 4);
    uVar17 = uVar17 + *(int *)(*param_1 + 8);
    iVar19 = uVar21 + *(int *)(*param_1 + 0xc);
    uVar22 = uVar22 + *(int *)param_1[1];
    uVar24 = uVar24 + *(int *)(param_1[1] + 4);
    uVar26 = uVar26 + *(int *)(param_1[1] + 8);
    iVar28 = uVar29 + *(int *)(param_1[1] + 0xc);
    *(uint *)*param_1 = uVar14;
    *(uint *)(*param_1 + 4) = uVar16;
    *(uint *)(*param_1 + 8) = uVar17;
    *(int *)(*param_1 + 0xc) = iVar19;
    *(uint *)param_1[1] = uVar22;
    *(uint *)(param_1[1] + 4) = uVar24;
    *(uint *)(param_1[1] + 8) = uVar26;
    *(int *)(param_1[1] + 0xc) = iVar28;
    piVar31 = piVar32 + -0x20;
  } while (local_2c != param_2 + param_3 * 4);
  return;
}

// ===== sha256_block_data_order_neon  @0x001c2410  (3048 bytes)
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void sha256_block_data_order_neon(int *param_1,undefined1 (*param_2) [16],int param_3)

{
  undefined1 auVar1 [32];
  undefined1 auVar2 [32];
  undefined1 auVar3 [32];
  undefined1 auVar4 [32];
  undefined1 auVar5 [32];
  undefined1 auVar6 [32];
  undefined1 auVar7 [32];
  undefined1 auVar8 [32];
  uint uVar9;
  undefined1 (*pauVar10) [16];
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  undefined1 (*pauVar26) [16];
  bool bVar27;
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined8 uVar39;
  ulonglong uVar40;
  ulonglong uVar41;
  undefined8 uVar42;
  ulonglong uVar43;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined1 (*local_3c) [16];
  
  local_3c = param_2 + 4;
  auVar32._8_8_ = 0xe9b5dba5b5c0fbcf;
  auVar32._0_8_ = 0x71374491428a2f98;
  auVar28 = vrev(*param_2,1);
  auVar29 = vrev(param_2[1],1);
  auVar30 = vrev(param_2[2],1);
  auVar31 = vrev(param_2[3],1);
  auVar32 = VectorAdd(auVar32,auVar28,4);
  auVar33 = VectorAdd(_DAT_001c14f0,auVar29,4);
  local_78 = auVar32._8_8_;
  auVar34 = VectorAdd(_DAT_001c1500,auVar30,4);
  local_70 = auVar33._0_8_;
  local_68 = auVar33._8_8_;
  auVar33 = VectorAdd(_DAT_001c1510,auVar31,4);
  local_60 = auVar34._0_8_;
  local_58 = auVar34._8_8_;
  local_50 = auVar33._0_8_;
  local_48 = auVar33._8_8_;
  iVar12 = *param_1;
  uVar13 = param_1[1];
  uVar14 = param_1[2];
  uVar15 = param_1[3];
  uVar17 = param_1[4];
  uVar18 = param_1[5];
  uVar20 = param_1[6];
  uVar21 = param_1[7];
  local_80._0_4_ = auVar32._0_4_;
  uVar24 = 0;
  uVar11 = uVar13 ^ uVar14;
  iVar22 = (int)local_80;
  pauVar10 = (undefined1 (*) [16])&DAT_001c1520;
  uVar42 = auVar32._0_8_;
  while( true ) {
    do {
      local_80 = uVar42;
      pauVar26 = pauVar10;
      auVar1._16_16_ = auVar29;
      auVar1._0_16_ = auVar28;
      auVar32 = auVar1._4_16_;
      auVar2._16_16_ = auVar31;
      auVar2._0_16_ = auVar30;
      uVar24 = iVar12 + uVar24;
      uVar25 = uVar17 ^ (uVar17 >> 5 | uVar17 << 0x1b) ^ (uVar17 >> 0x13 | uVar17 << 0xd);
      auVar34 = VectorUnsignedFixedToFloat(auVar32,7);
      auVar28 = VectorAdd(auVar28,auVar2._4_16_,4);
      auVar33 = VectorUnsignedFixedToFloat(auVar32,3);
      uVar9 = uVar24 ^ (uVar24 >> 0xb | uVar24 * 0x200000) ^ (uVar24 >> 0x14 | uVar24 * 0x1000);
      iVar22 = uVar21 + iVar22 + (uVar25 >> 6 | uVar25 << 0x1a) +
               ((uVar18 ^ uVar20) & uVar17 ^ uVar20);
      auVar34 = VectorShiftLeftInsert(auVar34,auVar32,0x19);
      auVar35 = VectorUnsignedFixedToFloat(auVar32,0x12);
      uVar15 = uVar15 + iVar22;
      auVar32 = VectorShiftLeftInsert(auVar35,auVar32,0xe);
      uVar42 = auVar31._8_8_;
      uVar39 = VectorShiftRight(uVar42,0x11);
      uVar23 = iVar22 + (uVar9 >> 2 | uVar9 << 0x1e) + (uVar11 & (uVar24 ^ uVar13) ^ uVar13);
      uVar21 = uVar15 ^ (uVar15 >> 5 | uVar15 * 0x8000000) ^ (uVar15 >> 0x13 | uVar15 * 0x2000);
      uVar40 = VectorShiftLeftInsert(uVar39,uVar42,0xf);
      uVar43 = VectorShiftRight(uVar42,10);
      uVar11 = uVar23 ^ (uVar23 >> 0xb | uVar23 * 0x200000) ^ (uVar23 >> 0x14 | uVar23 * 0x1000);
      auVar32 = VectorAdd(auVar28,auVar33 ^ auVar34 ^ auVar32,4);
      iVar22 = uVar20 + local_80._4_4_ + (uVar21 >> 6 | uVar21 << 0x1a) +
               ((uVar17 ^ uVar18) & uVar15 ^ uVar18);
      uVar14 = uVar14 + iVar22;
      uVar39 = VectorShiftRight(uVar42,0x13);
      uVar41 = VectorShiftLeftInsert(uVar39,uVar42,0xd);
      uVar20 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
               ((uVar24 ^ uVar13) & (uVar23 ^ uVar24) ^ uVar24);
      auVar28._0_8_ = VectorAdd(auVar32._0_8_,uVar43 ^ uVar40 ^ uVar41,4);
      uVar21 = uVar14 ^ (uVar14 >> 5 | uVar14 * 0x8000000) ^ (uVar14 >> 0x13 | uVar14 * 0x2000);
      uVar42 = VectorShiftRight(auVar28._0_8_,0x11);
      uVar40 = VectorShiftLeftInsert(uVar42,auVar28._0_8_,0xf);
      uVar43 = VectorShiftRight(auVar28._0_8_,10);
      uVar11 = uVar20 ^ (uVar20 >> 0xb | uVar20 * 0x200000) ^ (uVar20 >> 0x14 | uVar20 * 0x1000);
      iVar22 = uVar18 + (int)local_78 + (uVar21 >> 6 | uVar21 << 0x1a) +
               ((uVar15 ^ uVar17) & uVar14 ^ uVar17);
      uVar42 = VectorShiftRight(auVar28._0_8_,0x13);
      uVar13 = uVar13 + iVar22;
      uVar41 = VectorShiftLeftInsert(uVar42,auVar28._0_8_,0xd);
      uVar19 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
               ((uVar23 ^ uVar24) & (uVar20 ^ uVar23) ^ uVar23);
      auVar28._8_8_ = VectorAdd(auVar32._8_8_,uVar43 ^ uVar40 ^ uVar41,4);
      uVar18 = uVar13 ^ (uVar13 >> 5 | uVar13 * 0x8000000) ^ (uVar13 >> 0x13 | uVar13 * 0x2000);
      auVar33 = VectorAdd(*pauVar26,auVar28,4);
      uVar11 = uVar19 ^ (uVar19 >> 0xb | uVar19 * 0x200000) ^ (uVar19 >> 0x14 | uVar19 * 0x1000);
      iVar22 = uVar17 + local_78._4_4_ + (uVar18 >> 6 | uVar18 << 0x1a) +
               ((uVar14 ^ uVar15) & uVar13 ^ uVar15);
      uVar24 = uVar24 + iVar22;
      local_78 = auVar33._8_8_;
      auVar3._16_16_ = auVar30;
      auVar3._0_16_ = auVar29;
      auVar32 = auVar3._4_16_;
      auVar4._16_16_ = auVar28;
      auVar4._0_16_ = auVar31;
      uVar17 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
               ((uVar20 ^ uVar23) & (uVar19 ^ uVar20) ^ uVar20);
      uVar18 = uVar24 ^ (uVar24 >> 5 | uVar24 * 0x8000000) ^ (uVar24 >> 0x13 | uVar24 * 0x2000);
      auVar35 = VectorUnsignedFixedToFloat(auVar32,7);
      auVar29 = VectorAdd(auVar29,auVar4._4_16_,4);
      auVar34 = VectorUnsignedFixedToFloat(auVar32,3);
      uVar11 = uVar17 ^ (uVar17 >> 0xb | uVar17 * 0x200000) ^ (uVar17 >> 0x14 | uVar17 * 0x1000);
      iVar22 = uVar15 + (int)local_70 + (uVar18 >> 6 | uVar18 << 0x1a) +
               ((uVar13 ^ uVar14) & uVar24 ^ uVar14);
      auVar35 = VectorShiftLeftInsert(auVar35,auVar32,0x19);
      auVar36 = VectorUnsignedFixedToFloat(auVar32,0x12);
      uVar23 = uVar23 + iVar22;
      auVar32 = VectorShiftLeftInsert(auVar36,auVar32,0xe);
      uVar42 = VectorShiftRight(auVar28._8_8_,0x11);
      uVar16 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
               ((uVar19 ^ uVar20) & (uVar17 ^ uVar19) ^ uVar19);
      uVar15 = uVar23 ^ (uVar23 >> 5 | uVar23 * 0x8000000) ^ (uVar23 >> 0x13 | uVar23 * 0x2000);
      uVar40 = VectorShiftLeftInsert(uVar42,auVar28._8_8_,0xf);
      uVar43 = VectorShiftRight(auVar28._8_8_,10);
      uVar11 = uVar16 ^ (uVar16 >> 0xb | uVar16 * 0x200000) ^ (uVar16 >> 0x14 | uVar16 * 0x1000);
      auVar32 = VectorAdd(auVar29,auVar34 ^ auVar35 ^ auVar32,4);
      iVar22 = uVar14 + local_70._4_4_ + (uVar15 >> 6 | uVar15 << 0x1a) +
               ((uVar24 ^ uVar13) & uVar23 ^ uVar13);
      uVar20 = uVar20 + iVar22;
      uVar42 = VectorShiftRight(auVar28._8_8_,0x13);
      uVar41 = VectorShiftLeftInsert(uVar42,auVar28._8_8_,0xd);
      uVar14 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
               ((uVar17 ^ uVar19) & (uVar16 ^ uVar17) ^ uVar17);
      auVar29._0_8_ = VectorAdd(auVar32._0_8_,uVar43 ^ uVar40 ^ uVar41,4);
      uVar15 = uVar20 ^ (uVar20 >> 5 | uVar20 * 0x8000000) ^ (uVar20 >> 0x13 | uVar20 * 0x2000);
      uVar42 = VectorShiftRight(auVar29._0_8_,0x11);
      uVar40 = VectorShiftLeftInsert(uVar42,auVar29._0_8_,0xf);
      uVar43 = VectorShiftRight(auVar29._0_8_,10);
      uVar11 = uVar14 ^ (uVar14 >> 0xb | uVar14 * 0x200000) ^ (uVar14 >> 0x14 | uVar14 * 0x1000);
      iVar22 = uVar13 + (int)local_68 + (uVar15 >> 6 | uVar15 << 0x1a) +
               ((uVar23 ^ uVar24) & uVar20 ^ uVar24);
      uVar42 = VectorShiftRight(auVar29._0_8_,0x13);
      uVar19 = uVar19 + iVar22;
      uVar41 = VectorShiftLeftInsert(uVar42,auVar29._0_8_,0xd);
      uVar9 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
              ((uVar16 ^ uVar17) & (uVar14 ^ uVar16) ^ uVar16);
      auVar29._8_8_ = VectorAdd(auVar32._8_8_,uVar43 ^ uVar40 ^ uVar41,4);
      uVar13 = uVar19 ^ (uVar19 >> 5 | uVar19 * 0x8000000) ^ (uVar19 >> 0x13 | uVar19 * 0x2000);
      auVar34 = VectorAdd(pauVar26[1],auVar29,4);
      uVar11 = uVar9 ^ (uVar9 >> 0xb | uVar9 * 0x200000) ^ (uVar9 >> 0x14 | uVar9 * 0x1000);
      iVar22 = uVar24 + local_68._4_4_ + (uVar13 >> 6 | uVar13 << 0x1a) +
               ((uVar20 ^ uVar23) & uVar19 ^ uVar23);
      uVar17 = uVar17 + iVar22;
      local_70 = auVar34._0_8_;
      local_68 = auVar34._8_8_;
      auVar5._16_16_ = auVar31;
      auVar5._0_16_ = auVar30;
      auVar32 = auVar5._4_16_;
      auVar6._16_16_ = auVar29;
      auVar6._0_16_ = auVar28;
      uVar25 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
               ((uVar14 ^ uVar16) & (uVar9 ^ uVar14) ^ uVar14);
      uVar24 = uVar17 ^ (uVar17 >> 5 | uVar17 * 0x8000000) ^ (uVar17 >> 0x13 | uVar17 * 0x2000);
      auVar36 = VectorUnsignedFixedToFloat(auVar32,7);
      auVar30 = VectorAdd(auVar30,auVar6._4_16_,4);
      auVar35 = VectorUnsignedFixedToFloat(auVar32,3);
      uVar11 = uVar25 ^ (uVar25 >> 0xb | uVar25 * 0x200000) ^ (uVar25 >> 0x14 | uVar25 * 0x1000);
      iVar22 = uVar23 + (int)local_60 + (uVar24 >> 6 | uVar24 << 0x1a) +
               ((uVar19 ^ uVar20) & uVar17 ^ uVar20);
      auVar36 = VectorShiftLeftInsert(auVar36,auVar32,0x19);
      auVar37 = VectorUnsignedFixedToFloat(auVar32,0x12);
      uVar16 = uVar16 + iVar22;
      auVar32 = VectorShiftLeftInsert(auVar37,auVar32,0xe);
      uVar42 = VectorShiftRight(auVar29._8_8_,0x11);
      uVar21 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
               ((uVar9 ^ uVar14) & (uVar25 ^ uVar9) ^ uVar9);
      uVar24 = uVar16 ^ (uVar16 >> 5 | uVar16 * 0x8000000) ^ (uVar16 >> 0x13 | uVar16 * 0x2000);
      uVar40 = VectorShiftLeftInsert(uVar42,auVar29._8_8_,0xf);
      uVar43 = VectorShiftRight(auVar29._8_8_,10);
      uVar11 = uVar21 ^ (uVar21 >> 0xb | uVar21 * 0x200000) ^ (uVar21 >> 0x14 | uVar21 * 0x1000);
      auVar32 = VectorAdd(auVar30,auVar35 ^ auVar36 ^ auVar32,4);
      iVar22 = uVar20 + local_60._4_4_ + (uVar24 >> 6 | uVar24 << 0x1a) +
               ((uVar17 ^ uVar19) & uVar16 ^ uVar19);
      uVar14 = uVar14 + iVar22;
      uVar42 = VectorShiftRight(auVar29._8_8_,0x13);
      uVar41 = VectorShiftLeftInsert(uVar42,auVar29._8_8_,0xd);
      uVar20 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
               ((uVar25 ^ uVar9) & (uVar21 ^ uVar25) ^ uVar25);
      auVar30._0_8_ = VectorAdd(auVar32._0_8_,uVar43 ^ uVar40 ^ uVar41,4);
      uVar24 = uVar14 ^ (uVar14 >> 5 | uVar14 * 0x8000000) ^ (uVar14 >> 0x13 | uVar14 * 0x2000);
      uVar42 = VectorShiftRight(auVar30._0_8_,0x11);
      uVar40 = VectorShiftLeftInsert(uVar42,auVar30._0_8_,0xf);
      uVar43 = VectorShiftRight(auVar30._0_8_,10);
      uVar11 = uVar20 ^ (uVar20 >> 0xb | uVar20 * 0x200000) ^ (uVar20 >> 0x14 | uVar20 * 0x1000);
      iVar22 = uVar19 + (int)local_58 + (uVar24 >> 6 | uVar24 << 0x1a) +
               ((uVar16 ^ uVar17) & uVar14 ^ uVar17);
      uVar42 = VectorShiftRight(auVar30._0_8_,0x13);
      uVar9 = uVar9 + iVar22;
      uVar41 = VectorShiftLeftInsert(uVar42,auVar30._0_8_,0xd);
      uVar18 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
               ((uVar21 ^ uVar25) & (uVar20 ^ uVar21) ^ uVar21);
      auVar30._8_8_ = VectorAdd(auVar32._8_8_,uVar43 ^ uVar40 ^ uVar41,4);
      uVar24 = uVar9 ^ (uVar9 >> 5 | uVar9 * 0x8000000) ^ (uVar9 >> 0x13 | uVar9 * 0x2000);
      auVar35 = VectorAdd(pauVar26[2],auVar30,4);
      uVar11 = uVar18 ^ (uVar18 >> 0xb | uVar18 * 0x200000) ^ (uVar18 >> 0x14 | uVar18 * 0x1000);
      iVar22 = uVar17 + local_58._4_4_ + (uVar24 >> 6 | uVar24 << 0x1a) +
               ((uVar14 ^ uVar16) & uVar9 ^ uVar16);
      uVar25 = uVar25 + iVar22;
      local_60 = auVar35._0_8_;
      local_58 = auVar35._8_8_;
      auVar7._16_16_ = auVar28;
      auVar7._0_16_ = auVar31;
      auVar32 = auVar7._4_16_;
      auVar8._16_16_ = auVar30;
      auVar8._0_16_ = auVar29;
      uVar17 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
               ((uVar20 ^ uVar21) & (uVar18 ^ uVar20) ^ uVar20);
      uVar24 = uVar25 ^ (uVar25 >> 5 | uVar25 * 0x8000000) ^ (uVar25 >> 0x13 | uVar25 * 0x2000);
      auVar37 = VectorUnsignedFixedToFloat(auVar32,7);
      auVar31 = VectorAdd(auVar31,auVar8._4_16_,4);
      auVar36 = VectorUnsignedFixedToFloat(auVar32,3);
      uVar11 = uVar17 ^ (uVar17 >> 0xb | uVar17 * 0x200000) ^ (uVar17 >> 0x14 | uVar17 * 0x1000);
      iVar22 = uVar16 + (int)local_50 + (uVar24 >> 6 | uVar24 << 0x1a) +
               ((uVar9 ^ uVar14) & uVar25 ^ uVar14);
      auVar37 = VectorShiftLeftInsert(auVar37,auVar32,0x19);
      auVar38 = VectorUnsignedFixedToFloat(auVar32,0x12);
      uVar21 = uVar21 + iVar22;
      auVar32 = VectorShiftLeftInsert(auVar38,auVar32,0xe);
      uVar42 = VectorShiftRight(auVar30._8_8_,0x11);
      uVar15 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
               ((uVar18 ^ uVar20) & (uVar17 ^ uVar18) ^ uVar18);
      uVar24 = uVar21 ^ (uVar21 >> 5 | uVar21 * 0x8000000) ^ (uVar21 >> 0x13 | uVar21 * 0x2000);
      uVar40 = VectorShiftLeftInsert(uVar42,auVar30._8_8_,0xf);
      uVar43 = VectorShiftRight(auVar30._8_8_,10);
      uVar11 = uVar15 ^ (uVar15 >> 0xb | uVar15 * 0x200000) ^ (uVar15 >> 0x14 | uVar15 * 0x1000);
      auVar32 = VectorAdd(auVar31,auVar36 ^ auVar37 ^ auVar32,4);
      iVar22 = uVar14 + local_50._4_4_ + (uVar24 >> 6 | uVar24 << 0x1a) +
               ((uVar25 ^ uVar9) & uVar21 ^ uVar9);
      uVar20 = uVar20 + iVar22;
      uVar42 = VectorShiftRight(auVar30._8_8_,0x13);
      uVar41 = VectorShiftLeftInsert(uVar42,auVar30._8_8_,0xd);
      uVar14 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
               ((uVar17 ^ uVar18) & (uVar15 ^ uVar17) ^ uVar17);
      auVar31._0_8_ = VectorAdd(auVar32._0_8_,uVar43 ^ uVar40 ^ uVar41,4);
      uVar24 = uVar20 ^ (uVar20 >> 5 | uVar20 * 0x8000000) ^ (uVar20 >> 0x13 | uVar20 * 0x2000);
      uVar42 = VectorShiftRight(auVar31._0_8_,0x11);
      uVar40 = VectorShiftLeftInsert(uVar42,auVar31._0_8_,0xf);
      uVar43 = VectorShiftRight(auVar31._0_8_,10);
      uVar11 = uVar14 ^ (uVar14 >> 0xb | uVar14 * 0x200000) ^ (uVar14 >> 0x14 | uVar14 * 0x1000);
      iVar22 = uVar9 + (int)local_48 + (uVar24 >> 6 | uVar24 << 0x1a) +
               ((uVar21 ^ uVar25) & uVar20 ^ uVar25);
      uVar42 = VectorShiftRight(auVar31._0_8_,0x13);
      uVar18 = uVar18 + iVar22;
      uVar41 = VectorShiftLeftInsert(uVar42,auVar31._0_8_,0xd);
      uVar13 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
               ((uVar15 ^ uVar17) & (uVar14 ^ uVar15) ^ uVar15);
      auVar31._8_8_ = VectorAdd(auVar32._8_8_,uVar43 ^ uVar40 ^ uVar41,4);
      uVar9 = uVar18 ^ (uVar18 >> 5 | uVar18 * 0x8000000) ^ (uVar18 >> 0x13 | uVar18 * 0x2000);
      auVar32 = VectorAdd(pauVar26[3],auVar31,4);
      uVar11 = uVar13 ^ uVar14;
      uVar24 = uVar13 ^ (uVar13 >> 0xb | uVar13 * 0x200000) ^ (uVar13 >> 0x14 | uVar13 * 0x1000);
      iVar12 = uVar25 + local_48._4_4_ + (uVar9 >> 6 | uVar9 << 0x1a) +
               ((uVar20 ^ uVar21) & uVar18 ^ uVar21);
      uVar17 = uVar17 + iVar12;
      local_50 = auVar32._0_8_;
      local_48 = auVar32._8_8_;
      iVar12 = iVar12 + (uVar24 >> 2 | uVar24 << 0x1e);
      uVar24 = (uVar14 ^ uVar15) & uVar11 ^ uVar14;
      local_80._0_4_ = auVar33._0_4_;
      iVar22 = (int)local_80;
      pauVar10 = pauVar26 + 4;
      uVar42 = auVar33._0_8_;
    } while (*(int *)pauVar26[4] != 0);
    bVar27 = local_3c == param_2 + param_3 * 4;
    pauVar10 = local_3c;
    if (bVar27) {
      pauVar10 = local_3c + -4;
    }
    if (!bVar27) {
      local_3c = pauVar10 + 4;
    }
    uVar24 = iVar12 + uVar24;
    uVar25 = uVar17 ^ (uVar17 >> 5 | uVar17 * 0x8000000) ^ (uVar17 >> 0x13 | uVar17 * 0x2000);
    auVar28 = vrev(*pauVar10,1);
    uVar9 = uVar24 ^ (uVar24 >> 0xb | uVar24 * 0x200000) ^ (uVar24 >> 0x14 | uVar24 * 0x1000);
    iVar22 = uVar21 + (int)local_80 + (uVar25 >> 6 | uVar25 << 0x1a) +
             ((uVar18 ^ uVar20) & uVar17 ^ uVar20);
    auVar36 = VectorAdd(pauVar26[-0xc],auVar28,4);
    local_80._4_4_ = auVar33._4_4_;
    uVar15 = uVar15 + iVar22;
    uVar23 = iVar22 + (uVar9 >> 2 | uVar9 << 0x1e) + (uVar11 & (uVar24 ^ uVar13) ^ uVar13);
    uVar21 = uVar15 ^ (uVar15 >> 5 | uVar15 * 0x8000000) ^ (uVar15 >> 0x13 | uVar15 * 0x2000);
    uVar11 = uVar23 ^ (uVar23 >> 0xb | uVar23 * 0x200000) ^ (uVar23 >> 0x14 | uVar23 * 0x1000);
    iVar22 = uVar20 + local_80._4_4_ + (uVar21 >> 6 | uVar21 << 0x1a) +
             ((uVar17 ^ uVar18) & uVar15 ^ uVar18);
    local_78._0_4_ = auVar33._8_4_;
    uVar14 = uVar14 + iVar22;
    uVar20 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
             ((uVar24 ^ uVar13) & (uVar23 ^ uVar24) ^ uVar24);
    uVar21 = uVar14 ^ (uVar14 >> 5 | uVar14 * 0x8000000) ^ (uVar14 >> 0x13 | uVar14 * 0x2000);
    uVar11 = uVar20 ^ (uVar20 >> 0xb | uVar20 * 0x200000) ^ (uVar20 >> 0x14 | uVar20 * 0x1000);
    iVar22 = uVar18 + (int)local_78 + (uVar21 >> 6 | uVar21 << 0x1a) +
             ((uVar15 ^ uVar17) & uVar14 ^ uVar17);
    local_78._4_4_ = auVar33._12_4_;
    uVar13 = uVar13 + iVar22;
    uVar19 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
             ((uVar23 ^ uVar24) & (uVar20 ^ uVar23) ^ uVar23);
    uVar18 = uVar13 ^ (uVar13 >> 5 | uVar13 * 0x8000000) ^ (uVar13 >> 0x13 | uVar13 * 0x2000);
    uVar11 = uVar19 ^ (uVar19 >> 0xb | uVar19 * 0x200000) ^ (uVar19 >> 0x14 | uVar19 * 0x1000);
    iVar22 = uVar17 + local_78._4_4_ + (uVar18 >> 6 | uVar18 << 0x1a) +
             ((uVar14 ^ uVar15) & uVar13 ^ uVar15);
    local_70._0_4_ = auVar34._0_4_;
    uVar24 = uVar24 + iVar22;
    local_78 = auVar36._8_8_;
    uVar16 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
             ((uVar20 ^ uVar23) & (uVar19 ^ uVar20) ^ uVar20);
    uVar17 = uVar24 ^ (uVar24 >> 5 | uVar24 * 0x8000000) ^ (uVar24 >> 0x13 | uVar24 * 0x2000);
    auVar29 = vrev(pauVar10[1],1);
    uVar11 = uVar16 ^ (uVar16 >> 0xb | uVar16 * 0x200000) ^ (uVar16 >> 0x14 | uVar16 * 0x1000);
    iVar22 = uVar15 + (int)local_70 + (uVar17 >> 6 | uVar17 << 0x1a) +
             ((uVar13 ^ uVar14) & uVar24 ^ uVar14);
    auVar30 = VectorAdd(pauVar26[-0xb],auVar29,4);
    local_70._4_4_ = auVar34._4_4_;
    uVar23 = uVar23 + iVar22;
    uVar25 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
             ((uVar19 ^ uVar20) & (uVar16 ^ uVar19) ^ uVar19);
    uVar15 = uVar23 ^ (uVar23 >> 5 | uVar23 * 0x8000000) ^ (uVar23 >> 0x13 | uVar23 * 0x2000);
    uVar11 = uVar25 ^ (uVar25 >> 0xb | uVar25 * 0x200000) ^ (uVar25 >> 0x14 | uVar25 * 0x1000);
    iVar22 = uVar14 + local_70._4_4_ + (uVar15 >> 6 | uVar15 << 0x1a) +
             ((uVar24 ^ uVar13) & uVar23 ^ uVar13);
    local_68._0_4_ = auVar34._8_4_;
    uVar20 = uVar20 + iVar22;
    uVar14 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
             ((uVar16 ^ uVar19) & (uVar25 ^ uVar16) ^ uVar16);
    uVar15 = uVar20 ^ (uVar20 >> 5 | uVar20 * 0x8000000) ^ (uVar20 >> 0x13 | uVar20 * 0x2000);
    uVar11 = uVar14 ^ (uVar14 >> 0xb | uVar14 * 0x200000) ^ (uVar14 >> 0x14 | uVar14 * 0x1000);
    iVar22 = uVar13 + (int)local_68 + (uVar15 >> 6 | uVar15 << 0x1a) +
             ((uVar23 ^ uVar24) & uVar20 ^ uVar24);
    local_68._4_4_ = auVar34._12_4_;
    uVar19 = uVar19 + iVar22;
    uVar9 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
            ((uVar25 ^ uVar16) & (uVar14 ^ uVar25) ^ uVar25);
    uVar13 = uVar19 ^ (uVar19 >> 5 | uVar19 * 0x8000000) ^ (uVar19 >> 0x13 | uVar19 * 0x2000);
    uVar11 = uVar9 ^ (uVar9 >> 0xb | uVar9 * 0x200000) ^ (uVar9 >> 0x14 | uVar9 * 0x1000);
    iVar22 = uVar24 + local_68._4_4_ + (uVar13 >> 6 | uVar13 << 0x1a) +
             ((uVar20 ^ uVar23) & uVar19 ^ uVar23);
    local_60._0_4_ = auVar35._0_4_;
    uVar16 = uVar16 + iVar22;
    local_70 = auVar30._0_8_;
    local_68 = auVar30._8_8_;
    uVar17 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
             ((uVar14 ^ uVar25) & (uVar9 ^ uVar14) ^ uVar14);
    uVar24 = uVar16 ^ (uVar16 >> 5 | uVar16 * 0x8000000) ^ (uVar16 >> 0x13 | uVar16 * 0x2000);
    auVar30 = vrev(pauVar10[2],1);
    uVar11 = uVar17 ^ (uVar17 >> 0xb | uVar17 * 0x200000) ^ (uVar17 >> 0x14 | uVar17 * 0x1000);
    iVar22 = uVar23 + (int)local_60 + (uVar24 >> 6 | uVar24 << 0x1a) +
             ((uVar19 ^ uVar20) & uVar16 ^ uVar20);
    auVar31 = VectorAdd(pauVar26[-10],auVar30,4);
    local_60._4_4_ = auVar35._4_4_;
    uVar25 = uVar25 + iVar22;
    uVar21 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) + ((uVar9 ^ uVar14) & (uVar17 ^ uVar9) ^ uVar9)
    ;
    uVar24 = uVar25 ^ (uVar25 >> 5 | uVar25 * 0x8000000) ^ (uVar25 >> 0x13 | uVar25 * 0x2000);
    uVar11 = uVar21 ^ (uVar21 >> 0xb | uVar21 * 0x200000) ^ (uVar21 >> 0x14 | uVar21 * 0x1000);
    iVar22 = uVar20 + local_60._4_4_ + (uVar24 >> 6 | uVar24 << 0x1a) +
             ((uVar16 ^ uVar19) & uVar25 ^ uVar19);
    local_58._0_4_ = auVar35._8_4_;
    uVar14 = uVar14 + iVar22;
    uVar20 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
             ((uVar17 ^ uVar9) & (uVar21 ^ uVar17) ^ uVar17);
    uVar24 = uVar14 ^ (uVar14 >> 5 | uVar14 * 0x8000000) ^ (uVar14 >> 0x13 | uVar14 * 0x2000);
    uVar11 = uVar20 ^ (uVar20 >> 0xb | uVar20 * 0x200000) ^ (uVar20 >> 0x14 | uVar20 * 0x1000);
    iVar22 = uVar19 + (int)local_58 + (uVar24 >> 6 | uVar24 << 0x1a) +
             ((uVar25 ^ uVar16) & uVar14 ^ uVar16);
    local_58._4_4_ = auVar35._12_4_;
    uVar9 = uVar9 + iVar22;
    uVar18 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
             ((uVar21 ^ uVar17) & (uVar20 ^ uVar21) ^ uVar21);
    uVar24 = uVar9 ^ (uVar9 >> 5 | uVar9 * 0x8000000) ^ (uVar9 >> 0x13 | uVar9 * 0x2000);
    uVar11 = uVar18 ^ (uVar18 >> 0xb | uVar18 * 0x200000) ^ (uVar18 >> 0x14 | uVar18 * 0x1000);
    iVar22 = uVar16 + local_58._4_4_ + (uVar24 >> 6 | uVar24 << 0x1a) +
             ((uVar14 ^ uVar25) & uVar9 ^ uVar25);
    local_50._0_4_ = auVar32._0_4_;
    uVar17 = uVar17 + iVar22;
    local_60 = auVar31._0_8_;
    local_58 = auVar31._8_8_;
    uVar16 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
             ((uVar20 ^ uVar21) & (uVar18 ^ uVar20) ^ uVar20);
    uVar24 = uVar17 ^ (uVar17 >> 5 | uVar17 * 0x8000000) ^ (uVar17 >> 0x13 | uVar17 * 0x2000);
    auVar31 = vrev(pauVar10[3],1);
    uVar11 = uVar16 ^ (uVar16 >> 0xb | uVar16 * 0x200000) ^ (uVar16 >> 0x14 | uVar16 * 0x1000);
    iVar22 = uVar25 + (int)local_50 + (uVar24 >> 6 | uVar24 << 0x1a) +
             ((uVar9 ^ uVar14) & uVar17 ^ uVar14);
    auVar33 = VectorAdd(pauVar26[-9],auVar31,4);
    local_50._4_4_ = auVar32._4_4_;
    uVar21 = uVar21 + iVar22;
    uVar15 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
             ((uVar18 ^ uVar20) & (uVar16 ^ uVar18) ^ uVar18);
    uVar24 = uVar21 ^ (uVar21 >> 5 | uVar21 * 0x8000000) ^ (uVar21 >> 0x13 | uVar21 * 0x2000);
    uVar11 = uVar15 ^ (uVar15 >> 0xb | uVar15 * 0x200000) ^ (uVar15 >> 0x14 | uVar15 * 0x1000);
    iVar22 = uVar14 + local_50._4_4_ + (uVar24 >> 6 | uVar24 << 0x1a) +
             ((uVar17 ^ uVar9) & uVar21 ^ uVar9);
    local_48._0_4_ = auVar32._8_4_;
    uVar20 = uVar20 + iVar22;
    uVar14 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
             ((uVar16 ^ uVar18) & (uVar15 ^ uVar16) ^ uVar16);
    uVar24 = uVar20 ^ (uVar20 >> 5 | uVar20 * 0x8000000) ^ (uVar20 >> 0x13 | uVar20 * 0x2000);
    uVar11 = uVar14 ^ (uVar14 >> 0xb | uVar14 * 0x200000) ^ (uVar14 >> 0x14 | uVar14 * 0x1000);
    iVar22 = uVar9 + (int)local_48 + (uVar24 >> 6 | uVar24 << 0x1a) +
             ((uVar21 ^ uVar17) & uVar20 ^ uVar17);
    local_48._4_4_ = auVar32._12_4_;
    uVar18 = uVar18 + iVar22;
    uVar13 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
             ((uVar15 ^ uVar16) & (uVar14 ^ uVar15) ^ uVar15);
    uVar24 = uVar18 ^ (uVar18 >> 5 | uVar18 * 0x8000000) ^ (uVar18 >> 0x13 | uVar18 * 0x2000);
    uVar11 = uVar13 ^ (uVar13 >> 0xb | uVar13 * 0x200000) ^ (uVar13 >> 0x14 | uVar13 * 0x1000);
    iVar22 = uVar17 + local_48._4_4_ + (uVar24 >> 6 | uVar24 << 0x1a) +
             ((uVar20 ^ uVar21) & uVar18 ^ uVar21);
    local_50 = auVar33._0_8_;
    local_48 = auVar33._8_8_;
    iVar12 = iVar22 + (uVar11 >> 2 | uVar11 << 0x1e) +
             ((uVar14 ^ uVar15) & (uVar13 ^ uVar14) ^ uVar14) + *param_1;
    uVar13 = uVar13 + param_1[1];
    uVar14 = uVar14 + param_1[2];
    uVar15 = uVar15 + param_1[3];
    uVar17 = uVar16 + iVar22 + param_1[4];
    *param_1 = iVar12;
    uVar18 = uVar18 + param_1[5];
    param_1[1] = uVar13;
    uVar20 = uVar20 + param_1[6];
    param_1[2] = uVar14;
    uVar21 = uVar21 + param_1[7];
    param_1[3] = uVar15;
    param_1[4] = uVar17;
    param_1[5] = uVar18;
    param_1[6] = uVar20;
    param_1[7] = uVar21;
    if (bVar27) break;
    local_80._0_4_ = auVar36._0_4_;
    uVar24 = 0;
    uVar11 = uVar13 ^ uVar14;
    iVar22 = (int)local_80;
    pauVar10 = pauVar26 + -8;
    uVar42 = auVar36._0_8_;
  }
  return;
}

// ===== operator.new  @0x001c3240  (60 bytes)
/* operator new(unsigned int) */

void * operator_new(uint param_1)

{
  void *pvVar1;
  code *pcVar2;
  bad_alloc *this;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    param_1 = 1;
  }
  while( true ) {
    pvVar1 = malloc(param_1);
    if (pvVar1 != (void *)0x0) {
      return pvVar1;
    }
    pcVar2 = (code *)std::get_new_handler();
    if (pcVar2 == (code *)0x0) break;
    (*pcVar2)();
  }
  this = (bad_alloc *)__cxa_allocate_exception(4);
  uVar3 = std::bad_alloc::bad_alloc(this);
                    /* WARNING: Subroutine does not return */
  __cxa_throw(uVar3,&std::bad_alloc::typeinfo,std::bad_array_length::~bad_array_length);
}

// ===== operator.new  @0x001c3284  (10 bytes)
/* operator new(unsigned int, std::nothrow_t const&) */

void * operator_new(uint param_1,nothrow_t *param_2)

{
  void *pvVar1;
  
  pvVar1 = operator_new(param_1);
  return pvVar1;
}

// ===== operator.new[]  @0x001c329e  (4 bytes)
/* operator new[](unsigned int) */

void * operator_new__(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(param_1);
  return pvVar1;
}

// ===== operator.new[]  @0x001c32a2  (10 bytes)
/* operator new[](unsigned int, std::nothrow_t const&) */

void * operator_new__(uint param_1,nothrow_t *param_2)

{
  void *pvVar1;
  
  pvVar1 = operator_new__(param_1);
  return pvVar1;
}

// ===== operator.delete  @0x001c32bc  (10 bytes)
/* operator delete(void*) */

void operator_delete(void *param_1)

{
  if (param_1 == (void *)0x0) {
    return;
  }
  free(param_1);
  return;
}

// ===== operator.delete  @0x001c32c6  (4 bytes)
/* operator delete(void*, std::nothrow_t const&) */

void operator_delete(void *param_1,nothrow_t *param_2)

{
  operator_delete(param_1);
  return;
}

// ===== operator.delete  @0x001c32ca  (4 bytes)
/* operator delete(void*, unsigned int) */

void operator_delete(void *param_1,uint param_2)

{
  operator_delete(param_1);
  return;
}

// ===== operator.delete[]  @0x001c32ce  (4 bytes)
/* operator delete[](void*) */

void operator_delete__(void *param_1)

{
  operator_delete(param_1);
  return;
}

// ===== operator.delete[]  @0x001c32d2  (4 bytes)
/* operator delete[](void*, std::nothrow_t const&) */

void operator_delete__(void *param_1,nothrow_t *param_2)

{
  operator_delete__(param_1);
  return;
}

// ===== operator.delete[]  @0x001c32d6  (14 bytes)
/* operator delete[](void*, unsigned int) */

void operator_delete__(void *param_1,uint param_2)

{
  operator_delete__(param_1);
  return;
}

// ===== __cxa_end_cleanup  @0x001c3304  (12 bytes)
void __cxa_end_cleanup(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = FUN_001c344e();
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume(uVar1,param_2,param_3,param_4);
}

// ===== __cxa_allocate_exception  @0x001c3314  (36 bytes)
int __cxa_allocate_exception(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_001c458c(param_1 + 0x80);
  if (iVar1 != 0) {
    __aeabi_memclr8(iVar1,param_1 + 0x80);
    return iVar1 + 0x80;
  }
                    /* WARNING: Subroutine does not return */
  std::terminate();
}

// ===== __cxa_free_exception  @0x001c333c  (12 bytes)
void __cxa_free_exception(int param_1)

{
  FUN_001c46cc(param_1 + -0x80);
  return;
}

// ===== __cxa_allocate_dependent_exception  @0x001c334c  (30 bytes)
int __cxa_allocate_dependent_exception(void)

{
  int iVar1;
  
  iVar1 = FUN_001c458c(0x80);
  if (iVar1 != 0) {
    __aeabi_memclr(iVar1,0x80);
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  std::terminate();
}

// ===== __cxa_throw  @0x001c3370  (100 bytes)
void __cxa_throw(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = __cxa_get_globals();
  uVar3 = std::get_unexpected();
  *(undefined4 *)(param_1 + -0x74) = uVar3;
  uVar3 = std::get_terminate();
  *(undefined4 *)(param_1 + -0x70) = uVar3;
  *(undefined4 *)(param_1 + -0x7c) = param_2;
  *(undefined4 *)(param_1 + -0x78) = param_3;
  puVar1 = (undefined4 *)(param_1 + -0x58);
  *puVar1 = 0x432b2b00;
  *(undefined4 *)(param_1 + -0x54) = 0x434c4e47;
  *(undefined4 *)(param_1 + -0x80) = 1;
  *(int *)(iVar2 + 4) = *(int *)(iVar2 + 4) + 1;
  *(undefined **)(param_1 + -0x50) = &DAT_001c33d9;
  _Unwind_RaiseException(puVar1);
  __cxa_begin_catch(puVar1);
                    /* WARNING: Subroutine does not return */
  FUN_001c3a3c(*(undefined4 *)(param_1 + -0x70));
}

// ===== __cxa_get_exception_ptr  @0x001c33f0  (4 bytes)
undefined4 __cxa_get_exception_ptr(int param_1)

{
  return *(undefined4 *)(param_1 + 0x24);
}

// ===== __cxa_begin_cleanup  @0x001c33f4  (86 bytes)
undefined4 __cxa_begin_cleanup(uint *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = __cxa_get_globals();
  if ((*param_1 >> 8 | param_1[1] << 0x18) == 0x47432b2b && param_1[1] >> 8 == 0x434c4e) {
    uVar2 = param_1[-2];
    if (uVar2 == 0) {
      param_1[-3] = *(uint *)(iVar1 + 8);
      *(uint **)(iVar1 + 8) = param_1 + -10;
    }
    param_1[-2] = uVar2 + 1;
  }
  else {
    if (*(int *)(iVar1 + 8) != 0) {
                    /* WARNING: Subroutine does not return */
      std::terminate();
    }
    *(uint **)(iVar1 + 8) = param_1 + -10;
  }
  return 1;
}

// ===== __cxa_begin_catch  @0x001c34b0  (108 bytes)
uint * __cxa_begin_catch(uint *param_1)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *param_1;
  uVar3 = param_1[1];
  piVar1 = (int *)__cxa_get_globals();
  puVar2 = param_1 + -10;
  if (uVar3 >> 8 == 0x434c4e && (uVar4 >> 8 | uVar3 << 0x18) == 0x47432b2b) {
    uVar3 = param_1[-4];
    if ((int)uVar3 < 0) {
      uVar3 = -uVar3;
    }
    param_1[-4] = uVar3 + 1;
    if (puVar2 != (uint *)*piVar1) {
      param_1[-5] = (uint)*piVar1;
      *piVar1 = (int)puVar2;
    }
    piVar1[1] = piVar1[1] + -1;
    param_1 = (uint *)param_1[9];
  }
  else {
    if (*piVar1 != 0) {
                    /* WARNING: Subroutine does not return */
      std::terminate();
    }
    *piVar1 = (int)puVar2;
    param_1 = param_1 + 0x16;
  }
  return param_1;
}

// ===== __cxa_end_catch  @0x001c3520  (128 bytes)
void __cxa_end_catch(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  piVar1 = (int *)__cxa_get_globals_fast();
  piVar2 = (int *)*piVar1;
  if (piVar2 == (int *)0x0) {
    return;
  }
  uVar4 = piVar2[10];
  if ((uint)piVar2[0xb] >> 8 == 0x434c4e && (uVar4 >> 8 | piVar2[0xb] << 0x18) == 0x47432b2b) {
    iVar3 = piVar2[6];
    if (-1 < iVar3) {
      piVar2[6] = iVar3 + -1;
      if (iVar3 + -1 != 0) {
        return;
      }
      *piVar1 = piVar2[5];
      if ((uVar4 & 0xff) == 1) {
        iVar3 = *piVar2;
        FUN_001c46cc();
        piVar2 = (int *)(iVar3 + -0x80);
      }
      __cxa_decrement_exception_refcount(piVar2 + 0x20);
      return;
    }
    piVar2[6] = iVar3 + 1;
    if (iVar3 + 1 != 0) {
      return;
    }
    iVar3 = piVar2[5];
  }
  else {
    _Unwind_DeleteException(piVar2 + 10);
    iVar3 = 0;
  }
  *piVar1 = iVar3;
  return;
}

// ===== __cxa_decrement_exception_refcount  @0x001c359e  (62 bytes)
void __cxa_decrement_exception_refcount(int param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  
  if (param_1 != 0) {
    piVar2 = (int *)(param_1 + -0x80);
    DataMemoryBarrier(0x1b);
    do {
      ExclusiveAccess(piVar2);
      iVar3 = *piVar2;
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = iVar3 + -1;
    DataMemoryBarrier(0x1b);
    if (iVar3 == 1) {
      if (*(code **)(param_1 + -0x78) != (code *)0x0) {
        (**(code **)(param_1 + -0x78))(param_1);
      }
      __cxa_free_exception(param_1);
      return;
    }
  }
  return;
}

// ===== __cxa_current_exception_type  @0x001c35de  (58 bytes)
undefined4 __cxa_current_exception_type(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)__cxa_get_globals_fast();
  if (((piVar1 != (int *)0x0) && (iVar2 = *piVar1, iVar2 != 0)) &&
     ((*(uint *)(iVar2 + 0x28) >> 8 | *(uint *)(iVar2 + 0x2c) << 0x18) == 0x47432b2b &&
      *(uint *)(iVar2 + 0x2c) >> 8 == 0x434c4e)) {
    return *(undefined4 *)(iVar2 + 4);
  }
  return 0;
}

// ===== __cxa_rethrow  @0x001c3618  (94 bytes)
void __cxa_rethrow(void)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  piVar2 = (int *)__cxa_get_globals();
  iVar5 = *piVar2;
  if (iVar5 != 0) {
    puVar1 = (uint *)(iVar5 + 0x28);
    uVar3 = *puVar1 & 0xffffff00 ^ 0x432b2b00;
    uVar4 = *(uint *)(iVar5 + 0x2c) ^ 0x434c4e47;
    if (uVar3 == 0 && uVar4 == 0) {
      *(int *)(iVar5 + 0x18) = -*(int *)(iVar5 + 0x18);
      piVar2[1] = piVar2[1] + 1;
    }
    else {
      *piVar2 = 0;
    }
    _Unwind_RaiseException(puVar1);
    __cxa_begin_catch(puVar1);
    if (uVar3 == 0 && uVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_001c3a3c(*(undefined4 *)(iVar5 + 0x10));
    }
  }
                    /* WARNING: Subroutine does not return */
  std::terminate();
}

// ===== __cxa_increment_exception_refcount  @0x001c3676  (28 bytes)
void __cxa_increment_exception_refcount(int param_1)

{
  bool bVar1;
  int *piVar2;
  
  if (param_1 != 0) {
    piVar2 = (int *)(param_1 + -0x80);
    DataMemoryBarrier(0x1b);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
    DataMemoryBarrier(0x1b);
  }
  return;
}

// ===== __cxa_current_primary_exception  @0x001c3692  (98 bytes)
int * __cxa_current_primary_exception(void)

{
  bool bVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  puVar2 = (undefined4 *)__cxa_get_globals_fast();
  if (((puVar2 != (undefined4 *)0x0) && (piVar3 = (int *)*puVar2, piVar3 != (int *)0x0)) &&
     (((uint)piVar3[10] >> 8 | piVar3[0xb] << 0x18) == 0x47432b2b &&
      (uint)piVar3[0xb] >> 8 == 0x434c4e)) {
    if ((piVar3[10] & 0xffU) == 1) {
      piVar3 = (int *)(*piVar3 + -0x80);
    }
    DataMemoryBarrier(0x1b);
    do {
      ExclusiveAccess(piVar3);
      bVar1 = (bool)hasExclusiveAccess(piVar3);
    } while (!bVar1);
    *piVar3 = *piVar3 + 1;
    DataMemoryBarrier(0x1b);
    return piVar3 + 0x20;
  }
  return (int *)0x0;
}

// ===== __cxa_rethrow_primary_exception  @0x001c36f8  (118 bytes)
void __cxa_rethrow_primary_exception(int param_1)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  if (param_1 != 0) {
    piVar2 = (int *)__cxa_allocate_dependent_exception();
    piVar3 = (int *)(param_1 + -0x80);
    *piVar2 = param_1;
    DataMemoryBarrier(0x1b);
    do {
      ExclusiveAccess(piVar3);
      bVar1 = (bool)hasExclusiveAccess(piVar3);
    } while (!bVar1);
    *piVar3 = *piVar3 + 1;
    DataMemoryBarrier(0x1b);
    piVar2[1] = *(int *)(param_1 + -0x7c);
    iVar4 = std::get_unexpected();
    piVar2[3] = iVar4;
    iVar4 = std::get_terminate();
    piVar2[4] = iVar4;
    piVar3 = piVar2 + 10;
    *piVar3 = 0x432b2b01;
    piVar2[0xb] = 0x434c4e47;
    iVar4 = __cxa_get_globals();
    *(int *)(iVar4 + 4) = *(int *)(iVar4 + 4) + 1;
    piVar2[0xc] = 0x1c3771;
    _Unwind_RaiseException(piVar3);
    __cxa_begin_catch(piVar3);
    return;
  }
  return;
}

// ===== __cxa_uncaught_exception  @0x001c3794  (16 bytes)
bool __cxa_uncaught_exception(void)

{
  int iVar1;
  
  iVar1 = __cxa_uncaught_exceptions();
  return iVar1 != 0;
}

// ===== __cxa_uncaught_exceptions  @0x001c37a4  (18 bytes)
undefined4 __cxa_uncaught_exceptions(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = __cxa_get_globals_fast();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 4);
  }
  return uVar2;
}

// ===== __cxa_get_globals  @0x001c37bc  (58 bytes)
void * __cxa_get_globals(void)

{
  void *__pointer;
  int iVar1;
  
  __pointer = (void *)__cxa_get_globals_fast();
  if (__pointer == (void *)0x0) {
    __pointer = (void *)FUN_001c469c(1,0xc);
    if (__pointer == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_001c5650("cannot allocate __cxa_eh_globals");
    }
    iVar1 = pthread_setspecific(DAT_00270edc,__pointer);
    if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_001c5650("__libcxxabi_tls_set failure in __cxa_get_globals()");
    }
  }
  return __pointer;
}

// ===== __cxa_get_globals_fast  @0x001c3804  (44 bytes)
void __cxa_get_globals_fast(void)

{
  int iVar1;
  
  iVar1 = pthread_once((pthread_once_t *)&DAT_00270ee0,(__init_routine *)0x1c3841);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_001c5650("execute once failure in __cxa_get_globals_fast()");
  }
  pthread_getspecific(DAT_00270edc);
  return;
}

// ===== __cxa_guard_acquire  @0x001c3894  (114 bytes)
bool __cxa_guard_acquire(uint *param_1)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&DAT_00270ee4);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_001c5650("__cxa_guard_acquire failed to acquire mutex");
  }
  bVar2 = false;
  if ((char)*param_1 == '\0') {
    while ((*param_1 & 0xff00) != 0) {
      iVar1 = pthread_cond_wait((pthread_cond_t *)&DAT_00270ee8,(pthread_mutex_t *)&DAT_00270ee4);
      if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_001c5650("__cxa_guard_acquire condition variable wait failed");
      }
    }
    bVar2 = (*param_1 & 0xff) == 0;
    if (bVar2) {
      *param_1 = 0x100;
    }
  }
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)&DAT_00270ee4);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_001c5650("__cxa_guard_acquire failed to release mutex");
  }
  return bVar2;
}

// ===== __cxa_guard_release  @0x001c3924  (66 bytes)
void __cxa_guard_release(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&DAT_00270ee4);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_001c5650("__cxa_guard_release failed to acquire mutex");
  }
  *param_1 = 1;
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)&DAT_00270ee4);
  if (iVar1 == 0) {
    iVar1 = pthread_cond_broadcast((pthread_cond_t *)&DAT_00270ee8);
    if (iVar1 == 0) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    FUN_001c5650("__cxa_guard_release failed to broadcast condition variable");
  }
                    /* WARNING: Subroutine does not return */
  FUN_001c5650("__cxa_guard_release failed to release mutex");
}

// ===== __cxa_guard_abort  @0x001c3980  (66 bytes)
void __cxa_guard_abort(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&DAT_00270ee4);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_001c5650("__cxa_guard_abort failed to acquire mutex");
  }
  *param_1 = 0;
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)&DAT_00270ee4);
  if (iVar1 == 0) {
    iVar1 = pthread_cond_broadcast((pthread_cond_t *)&DAT_00270ee8);
    if (iVar1 == 0) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    FUN_001c5650("__cxa_guard_abort failed to broadcast condition variable");
  }
                    /* WARNING: Subroutine does not return */
  FUN_001c5650("__cxa_guard_abort failed to release mutex");
}

// ===== __gxx_personality_v0  @0x001c3c24  (424 bytes)
void __gxx_personality_v0(uint param_1,uint *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint local_48;
  int local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  uint local_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  iVar3 = 3;
  if ((param_2 == (uint *)0x0) || (param_3 == 0)) goto LAB_001c3dac;
  uVar1 = param_1 & 0xfffffff7;
  if (uVar1 != 2) {
    uVar5 = param_2[1];
    uVar4 = *param_2 & 0xffffff00;
    if (uVar1 == 1) {
      uVar1 = param_2[8];
      local_48 = 0;
      _Unwind_VRS_Get(param_3,0,0xd,0,&local_48);
      if (uVar1 == local_48) {
        if (uVar4 == 0x432b2b00 && uVar5 == 0x434c4e47) {
          local_34 = param_2[9];
          local_40 = param_2[10];
          local_3c = param_2[0xb];
          local_38 = param_2[0xc];
          local_48 = param_2[0xd];
          local_44 = (int)local_48 >> 0x1f;
          local_30 = 6;
        }
        else {
          FUN_001c3dd4(&local_48,6,0,param_2,param_3);
          if (local_30 != 6) {
                    /* WARNING: Subroutine does not return */
            FUN_001c4160(0,param_2);
          }
        }
      }
      else {
        FUN_001c3dd4(&local_48,2,uVar4 == 0x432b2b00 && uVar5 == 0x434c4e47,param_2,param_3);
        if (local_30 == 8) goto LAB_001c3d78;
        iVar3 = local_30;
        if (local_30 != 6) goto LAB_001c3dac;
        __cxa_begin_cleanup(param_2);
      }
      FUN_001c4180(param_2,param_3,&local_48);
      iVar3 = 7;
      goto LAB_001c3dac;
    }
    if (uVar1 != 0) {
      iVar3 = 3;
      goto LAB_001c3dac;
    }
    if ((param_1 & 8) == 0) {
      FUN_001c3dd4(&local_48,1,(uVar4 ^ 0x432b2b00) == 0 && (uVar5 ^ 0x434c4e47) == 0,param_2,
                   param_3);
      if (local_30 != 8) {
        iVar3 = local_30;
        if (local_30 == 6) {
          local_28 = 0;
          _Unwind_VRS_Get(param_3,0,0xd,0,&local_28);
          param_2[8] = local_28;
          if ((uVar4 ^ 0x432b2b00) == 0 && (uVar5 ^ 0x434c4e47) == 0) {
            param_2[9] = local_34;
            param_2[10] = local_40;
            param_2[0xb] = local_3c;
            param_2[0xc] = local_38;
            param_2[0xd] = local_48;
          }
          iVar3 = 6;
        }
        goto LAB_001c3dac;
      }
    }
  }
LAB_001c3d78:
  iVar2 = __gnu_unwind_frame(param_2,param_3);
  iVar3 = 9;
  if (iVar2 == 0) {
    iVar3 = 8;
  }
LAB_001c3dac:
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar3);
  }
  return;
}

// ===== __cxa_call_unexpected  @0x001c420c  (420 bytes)
void __cxa_call_unexpected(uint *param_1)

{
  byte bVar1;
  uint uVar2;
  int *piVar3;
  uint *puVar4;
  uint *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  byte *pbVar10;
  byte *pbVar11;
  uint uVar12;
  byte *unaff_r8;
  undefined8 uVar13;
  uint local_30;
  undefined **local_2c;
  byte *local_28;
  
  if (param_1 == (uint *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_001c4160(0,0);
  }
  __cxa_begin_catch(param_1);
  uVar2 = param_1[1];
  uVar9 = *param_1 & 0xffffff00 ^ 0x432b2b00;
  if (uVar9 == 0 && (uVar2 ^ 0x434c4e47) == 0) {
    local_30 = param_1[0xd];
    puVar5 = param_1 + -10;
    uVar12 = param_1[-6];
    unaff_r8 = (byte *)param_1[0xb];
    uVar13 = CONCAT44((int)local_30 >> 0x1f,param_1[-7]);
    local_28 = unaff_r8;
  }
  else {
    uVar12 = std::get_terminate();
    puVar5 = (uint *)0x0;
    uVar13 = std::get_unexpected();
    local_30 = (uint)((ulonglong)uVar13 >> 0x20);
  }
  uVar8 = (undefined4)((ulonglong)uVar13 >> 0x20);
  FUN_001c39fc((int)uVar13);
  __cxa_begin_catch();
  if (uVar9 == 0 && (uVar2 ^ 0x434c4e47) == 0) {
    local_28 = unaff_r8 + 1;
    FUN_001c43d8(&local_28,*unaff_r8);
    pbVar10 = local_28 + 1;
    bVar1 = *local_28;
    local_28 = pbVar10;
    if (bVar1 == 0xff) goto LAB_001c4352;
    uVar2 = 0;
    uVar9 = 0;
    do {
      pbVar11 = pbVar10 + 1;
      bVar1 = *pbVar10;
      uVar9 = uVar9 | (bVar1 & 0x7f) << (uVar2 & 0xff);
      uVar2 = uVar2 + 7;
      pbVar10 = pbVar11;
    } while ((bVar1 & 0x80) != 0);
    local_28 = pbVar11;
    piVar3 = (int *)__cxa_get_globals_fast();
    puVar4 = (uint *)*piVar3;
    if (puVar4 == (uint *)0x0) goto LAB_001c4352;
    uVar2 = puVar4[10];
    if ((puVar4 != puVar5) && (puVar4[0xb] == 0x434c4e47 && (uVar2 & 0xffffff00) == 0x432b2b00)) {
      if (puVar4[0xb] == 0x434c4e47 && uVar2 == 0x432b2b01) {
        puVar5 = (uint *)*puVar4;
      }
      else {
        puVar5 = puVar4 + 0x20;
      }
      iVar6 = FUN_001c449c(local_30,uVar8,pbVar11 + uVar9,puVar4[1],puVar5,param_1);
      if (iVar6 == 0) {
        puVar4[6] = -puVar4[6];
        piVar3[1] = piVar3[1] + 1;
        __cxa_end_catch();
        __cxa_end_catch();
        __cxa_begin_catch(puVar4 + 10);
        uVar8 = __cxa_rethrow();
        __cxa_end_catch();
                    /* WARNING: Subroutine does not return */
        _Unwind_Resume(uVar8);
      }
    }
    local_2c = &PTR__bad_exception_00264cac;
    iVar6 = FUN_001c449c(local_30,uVar8,pbVar11 + uVar9,&std::bad_exception::typeinfo,&local_2c,
                         param_1);
    if (iVar6 == 0) {
      __cxa_end_catch();
      puVar7 = (undefined4 *)__cxa_allocate_exception(4);
      *puVar7 = &PTR__bad_exception_00264cac;
                    /* WARNING: Subroutine does not return */
      __cxa_throw(puVar7,&std::bad_exception::typeinfo,std::bad_exception::~bad_exception);
    }
    std::bad_exception::~bad_exception((bad_exception *)&local_2c);
  }
  __cxa_end_catch();
LAB_001c4352:
                    /* WARNING: Subroutine does not return */
  FUN_001c3a3c(uVar12);
}

// ===== __cxa_pure_virtual  @0x001c4548  (12 bytes)
void __cxa_pure_virtual(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_001c5650("Pure virtual function called!");
}

// ===== __cxa_deleted_virtual  @0x001c4558  (12 bytes)
void __cxa_deleted_virtual(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_001c5650("Deleted virtual function called!");
}

// ===== __dynamic_cast  @0x001c4fac  (200 bytes)
void __dynamic_cast(int *param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int *local_58;
  int *piStack_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined1 local_48 [32];
  undefined4 local_28;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  iVar2 = *(int *)(*param_1 + -8);
  piVar1 = *(int **)(*param_1 + -4);
  local_58 = param_3;
  piStack_54 = param_1;
  local_50 = param_2;
  uStack_4c = param_4;
  __aeabi_memclr8(local_48,0x27);
  iVar2 = (int)param_1 + iVar2;
  if (piVar1 == param_3) {
    local_28 = 1;
    (**(code **)(*param_3 + 0x14))(param_3,&local_58,iVar2,iVar2,1,0);
  }
  else {
    (**(code **)(*piVar1 + 0x18))(piVar1,&local_58,iVar2,1,0);
  }
  if (__stack_chk_guard - local_1c != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_1c);
  }
  return;
}

// ===== __cxa_demangle  @0x001c5824  (676 bytes)
void __cxa_demangle(char *param_1,void *param_2,uint *param_3,int *param_4)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  size_t sVar6;
  int *piVar7;
  undefined4 *puVar8;
  uint uVar9;
  int *piVar10;
  uint uVar11;
  byte *pbVar12;
  uint uVar13;
  byte *pbVar14;
  bool bVar15;
  byte *local_10a8;
  byte *local_10a4;
  undefined4 local_10a0;
  undefined4 *puStack_109c;
  int local_1098;
  int local_1094;
  undefined4 local_1090;
  undefined4 *puStack_108c;
  int *local_1088;
  int *piStack_1084;
  undefined4 local_1080;
  undefined4 *puStack_107c;
  undefined4 local_1078;
  undefined4 uStack_1074;
  undefined4 local_1070;
  undefined1 local_106c;
  undefined1 local_106b;
  undefined2 uStack_106a;
  undefined4 *local_1064;
  undefined4 *puStack_1060;
  undefined4 *local_105c;
  undefined4 *local_1058;
  undefined4 **local_1054;
  undefined4 local_1050 [4];
  undefined4 auStack_1040 [1020];
  undefined4 *local_50 [11];
  
  iVar3 = __stack_chk_guard;
  if ((param_1 == (char *)0x0) || ((param_2 != (void *)0x0 && (param_3 == (uint *)0x0)))) {
    if (param_4 == (int *)0x0) goto LAB_001c58a4;
    iVar5 = -3;
  }
  else {
    sVar6 = strlen(param_1);
    if ((1 < sVar6) &&
       ((iVar5 = strncmp(param_1,"_Z",2), iVar5 == 0 ||
        ((3 < sVar6 && (iVar5 = strncmp(param_1,"___Z",4), iVar5 == 0)))))) {
      uVar13 = 0;
      if (param_2 != (void *)0x0) {
        uVar13 = *param_3;
      }
      local_10a8 = (byte *)0x0;
      local_10a4 = (byte *)0x0;
      local_10a0 = 0;
      local_1098 = 0;
      local_1094 = 0;
      local_1090 = 0;
      local_1088 = (int *)0x0;
      piStack_1084 = (int *)0x0;
      local_1080 = 0;
      local_106c = 0;
      local_1070 = 0;
      local_1078 = 0;
      uStack_1074 = 0;
      _local_106b = CONCAT21(uStack_106a,1);
      local_1058 = (undefined4 *)0x0;
      local_1054 = &puStack_107c;
      puStack_109c = local_1050;
      puStack_108c = local_1050;
      puStack_107c = local_1050;
      if ((uint)((int)local_50 - (int)local_1050) < 0x10) {
        local_50[0] = local_1050;
        local_1064 = malloc(0x10);
      }
      else {
        local_50[0] = auStack_1040;
        local_1064 = local_1050;
      }
      local_105c = local_1064 + 4;
      *local_1064 = 0;
      local_1064[1] = 0;
      local_1064[2] = 0;
      local_1064[3] = local_1050;
      puStack_1060 = local_1064;
      local_1058 = local_105c;
      FUN_001c5ef6(&local_1088,&local_1064);
      FUN_001c5f62(&local_1064);
      _local_106b = CONCAT21(0x100,local_106b);
      local_1064 = (undefined4 *)0x0;
      FUN_001c5af8(param_1,param_1 + sVar6,&local_10a8,&local_1064);
      pbVar12 = local_10a8;
      if ((local_1064 == (undefined4 *)0x0) && ((char)uStack_106a != '\0')) {
        piVar7 = local_1088;
        piVar10 = piStack_1084;
        if (local_1088 != piStack_1084) {
          piVar10 = (int *)*local_1088;
          piVar7 = (int *)local_1088[1];
        }
        if (local_1088 == piStack_1084 || piVar10 == piVar7) goto LAB_001c5a10;
        _local_106b = _local_106b & 0xff0000;
        while (iVar5 = local_1098, pbVar4 = local_10a4, local_10a4 != pbVar12) {
          pbVar14 = local_10a4 + -0x18;
          pbVar1 = pbVar14;
          if ((local_10a4[-0xc] & 1) != 0) {
            pbVar1 = local_10a4 + -4;
            local_10a4 = pbVar14;
            free(*(void **)pbVar1);
            pbVar1 = local_10a4;
          }
          local_10a4 = pbVar1;
          if ((*pbVar14 & 1) != 0) {
            free(*(void **)(pbVar4 + -0x10));
          }
        }
        while (local_1094 != iVar5) {
          local_1094 = local_1094 + -0x10;
          FUN_001c5dac();
        }
        FUN_001c5af8(param_1,param_1 + sVar6,&local_10a8,&local_1064);
        if ((char)uStack_106a == '\0') goto LAB_001c5a0c;
        puVar8 = (undefined4 *)0xfffffffe;
        local_1064 = puVar8;
      }
      else {
LAB_001c5a0c:
        puVar8 = local_1064;
        if (local_1064 == (undefined4 *)0x0) {
LAB_001c5a10:
          bVar2 = local_10a4[-0x18];
          bVar15 = (bVar2 & 1) == 0;
          if (bVar15) {
            bVar2 = bVar2 >> 1;
          }
          uVar9 = (uint)bVar2;
          if (!bVar15) {
            uVar9 = *(uint *)(local_10a4 + -0x14);
          }
          if ((local_10a4[-0xc] & 1) == 0) {
            uVar11 = (uint)(local_10a4[-0xc] >> 1);
          }
          else {
            uVar11 = *(uint *)(local_10a4 + -8);
          }
          iVar5 = uVar11 + uVar9;
          uVar9 = iVar5 + 1;
          if (uVar13 < uVar9) {
            param_2 = realloc(param_2,uVar9);
            if (param_2 == (void *)0x0) {
              puVar8 = (undefined4 *)0xffffffff;
              local_1064 = puVar8;
            }
            else {
              if (param_3 != (uint *)0x0) {
                *param_3 = uVar9;
              }
LAB_001c5a5a:
              uVar13 = *(uint *)(local_10a4 + -8);
              pbVar12 = *(byte **)(local_10a4 + -4);
              if ((local_10a4[-0xc] & 1) == 0) {
                pbVar12 = local_10a4 + -0xb;
                uVar13 = (uint)(local_10a4[-0xc] >> 1);
              }
              FUN_001cb080(local_10a4 + -0x18,pbVar12,uVar13);
              if ((local_10a4[-0x18] & 1) == 0) {
                pbVar12 = local_10a4 + -0x17;
              }
              else {
                pbVar12 = *(byte **)(local_10a4 + -0x10);
              }
              __aeabi_memcpy(param_2,pbVar12,iVar5);
              *(undefined1 *)((int)param_2 + iVar5) = 0;
              puVar8 = (undefined4 *)0x0;
            }
          }
          else {
            if (param_2 != (void *)0x0) goto LAB_001c5a5a;
            puVar8 = (undefined4 *)0x0;
          }
        }
      }
      if (param_4 != (int *)0x0) {
        *param_4 = (int)puVar8;
      }
      FUN_001c5d4c(&local_1088);
      FUN_001c5d7c(&local_1098);
      FUN_001c5dac(&local_10a8);
      goto LAB_001c58a4;
    }
    if (param_4 == (int *)0x0) goto LAB_001c58a4;
    iVar5 = -2;
  }
  *param_4 = iVar5;
LAB_001c58a4:
  if (__stack_chk_guard - iVar3 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - iVar3);
}

// ===== __aeabi_ldivmod  @0x001d80a4  (56 bytes)
void __aeabi_ldivmod(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  
  if ((param_4 == 0) && (param_3 == 0)) {
    bVar3 = param_2 == 0;
    iVar2 = param_2;
    if (bVar3) {
      iVar2 = param_1;
    }
    bVar1 = iVar2 < 0;
    bVar4 = param_1 != 0;
    if (bVar1) {
      param_1 = 0;
      param_2 = -0x80000000;
    }
    if ((!bVar3 || bVar4) && !bVar1) {
      param_2 = 0x7fffffff;
    }
    if ((!bVar3 || bVar4) && !bVar1) {
      param_1 = -1;
    }
    __aeabi_idiv0(param_1,param_2);
    return;
  }
  __gnu_ldivmod_helper();
  return;
}

// ===== __aeabi_idiv0  @0x001d80dc  (12 bytes)
void __aeabi_idiv0(void)

{
  raise(8);
  return;
}

