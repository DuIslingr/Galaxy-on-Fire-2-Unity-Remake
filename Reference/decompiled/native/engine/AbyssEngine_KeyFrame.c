// Class: AbyssEngine::KeyFrame
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::KeyFrame::KeyFrame  @0x0007f044  (98 bytes)
/* AbyssEngine::KeyFrame::KeyFrame() */

void __thiscall AbyssEngine::KeyFrame::KeyFrame(KeyFrame *this)

{
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  int local_18;
  
  local_18 = __stack_chk_guard;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  __aeabi_memclr4(this,0x48);
  local_24 = 0x3f800000;
  uStack_20 = 0x3f800000;
  local_1c = 0x3f800000;
  AEMath::Vector::operator=((Vector *)(this + 0xc),(Vector *)&local_24);
  local_24 = 0x3f800000;
  uStack_20 = 0x3f800000;
  local_1c = 0x3f800000;
  AEMath::Vector::operator=((Vector *)(this + 0x30),(Vector *)&local_24);
  *(undefined4 *)(this + 0x48) = 0x3f800000;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

