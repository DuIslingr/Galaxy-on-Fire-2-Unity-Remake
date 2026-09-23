// Class: Array<AbyssEngine::Mesh*>
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Array<AbyssEngine::Mesh*>::~Array  @0x0008161c  (22 bytes)
/* Array<AbyssEngine::Mesh*>::~Array() */

Array<AbyssEngine::Mesh*> * __thiscall
Array<AbyssEngine::Mesh*>::~Array(Array<AbyssEngine::Mesh*> *this)

{
  if (*(void **)(this + 4) != (void *)0x0) {
    operator_delete__(*(void **)(this + 4));
  }
  *(undefined4 *)(this + 4) = 0;
  return this;
}

