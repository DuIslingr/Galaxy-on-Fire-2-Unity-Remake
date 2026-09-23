// Class: Array<AbyssEngine::Transform*>
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Array<AbyssEngine::Transform*>::~Array  @0x00081674  (22 bytes)
/* Array<AbyssEngine::Transform*>::~Array() */

Array<AbyssEngine::Transform*> * __thiscall
Array<AbyssEngine::Transform*>::~Array(Array<AbyssEngine::Transform*> *this)

{
  if (*(void **)(this + 4) != (void *)0x0) {
    operator_delete__(*(void **)(this + 4));
  }
  *(undefined4 *)(this + 4) = 0;
  return this;
}

