// Class: Array<AbyssEngine::Image2D*>
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Array<AbyssEngine::Image2D*>::~Array  @0x0008168a  (22 bytes)
/* Array<AbyssEngine::Image2D*>::~Array() */

Array<AbyssEngine::Image2D*> * __thiscall
Array<AbyssEngine::Image2D*>::~Array(Array<AbyssEngine::Image2D*> *this)

{
  if (*(void **)(this + 4) != (void *)0x0) {
    operator_delete__(*(void **)(this + 4));
  }
  *(undefined4 *)(this + 4) = 0;
  return this;
}

