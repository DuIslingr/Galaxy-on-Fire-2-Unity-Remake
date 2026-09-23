// Class: Array<AbyssEngine::Material*>
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Array<AbyssEngine::Material*>::~Array  @0x00081648  (22 bytes)
/* Array<AbyssEngine::Material*>::~Array() */

Array<AbyssEngine::Material*> * __thiscall
Array<AbyssEngine::Material*>::~Array(Array<AbyssEngine::Material*> *this)

{
  if (*(void **)(this + 4) != (void *)0x0) {
    operator_delete__(*(void **)(this + 4));
  }
  *(undefined4 *)(this + 4) = 0;
  return this;
}

