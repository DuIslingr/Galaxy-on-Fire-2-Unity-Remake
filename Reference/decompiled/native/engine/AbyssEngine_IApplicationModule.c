// Class: AbyssEngine::IApplicationModule
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::IApplicationModule::SetApplicationManager  @0x0007d790  (8 bytes)
/* AbyssEngine::IApplicationModule::SetApplicationManager(AbyssEngine::ApplicationManager*) */

void __thiscall
AbyssEngine::IApplicationModule::SetApplicationManager
          (IApplicationModule *this,ApplicationManager *param_1)

{
  *(ApplicationManager **)(this + 8) = param_1;
  *(undefined4 *)(this + 4) = *(undefined4 *)param_1;
  return;
}

// ===== AbyssEngine::IApplicationModule::OnTouchBegin  @0x000a35f2  (2 bytes)
/* AbyssEngine::IApplicationModule::OnTouchBegin(int, int, void*) */

int AbyssEngine::IApplicationModule::OnTouchBegin(int param_1,int param_2,void *param_3)

{
  return param_1;
}

// ===== AbyssEngine::IApplicationModule::OnTouchMove  @0x000a35f4  (2 bytes)
/* AbyssEngine::IApplicationModule::OnTouchMove(int, int, void*) */

int AbyssEngine::IApplicationModule::OnTouchMove(int param_1,int param_2,void *param_3)

{
  return param_1;
}

// ===== AbyssEngine::IApplicationModule::OnTouchEnd  @0x000a35f6  (2 bytes)
/* AbyssEngine::IApplicationModule::OnTouchEnd(int, int, void*) */

int AbyssEngine::IApplicationModule::OnTouchEnd(int param_1,int param_2,void *param_3)

{
  return param_1;
}

// ===== AbyssEngine::IApplicationModule::OnSuspend  @0x000a35f8  (2 bytes)
/* AbyssEngine::IApplicationModule::OnSuspend() */

void AbyssEngine::IApplicationModule::OnSuspend(void)

{
  return;
}

// ===== AbyssEngine::IApplicationModule::OnResume  @0x000a35fa  (2 bytes)
/* AbyssEngine::IApplicationModule::OnResume() */

void AbyssEngine::IApplicationModule::OnResume(void)

{
  return;
}

