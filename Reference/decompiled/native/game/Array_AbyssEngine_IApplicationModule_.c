// Class: Array<AbyssEngine::IApplicationModule*>
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Array<AbyssEngine::IApplicationModule*>::~Array  @0x0008c986  (22 bytes)
/* Array<AbyssEngine::IApplicationModule*>::~Array() */

Array<AbyssEngine::IApplicationModule*> * __thiscall
Array<AbyssEngine::IApplicationModule*>::~Array(Array<AbyssEngine::IApplicationModule*> *this)

{
  if (*(void **)(this + 4) != (void *)0x0) {
    operator_delete__(*(void **)(this + 4));
  }
  *(undefined4 *)(this + 4) = 0;
  return this;
}

