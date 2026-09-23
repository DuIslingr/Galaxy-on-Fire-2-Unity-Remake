// Class: Array<AbyssEngine::AELoadedTexture*>
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Array<AbyssEngine::AELoadedTexture*>::~Array  @0x000816cc  (22 bytes)
/* Array<AbyssEngine::AELoadedTexture*>::~Array() */

Array<AbyssEngine::AELoadedTexture*> * __thiscall
Array<AbyssEngine::AELoadedTexture*>::~Array(Array<AbyssEngine::AELoadedTexture*> *this)

{
  if (*(void **)(this + 4) != (void *)0x0) {
    operator_delete__(*(void **)(this + 4));
  }
  *(undefined4 *)(this + 4) = 0;
  return this;
}

