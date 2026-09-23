// Class: Array<AbyssEngine::Resource*>
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Array<AbyssEngine::Resource*>::~Array  @0x000816b6  (22 bytes)
/* Array<AbyssEngine::Resource*>::~Array() */

Array<AbyssEngine::Resource*> * __thiscall
Array<AbyssEngine::Resource*>::~Array(Array<AbyssEngine::Resource*> *this)

{
  if (*(void **)(this + 4) != (void *)0x0) {
    operator_delete__(*(void **)(this + 4));
  }
  *(undefined4 *)(this + 4) = 0;
  return this;
}

