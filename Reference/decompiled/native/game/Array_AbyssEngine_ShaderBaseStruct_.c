// Class: Array<AbyssEngine::ShaderBaseStruct*>
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Array<AbyssEngine::ShaderBaseStruct*>::~Array  @0x0008edb4  (22 bytes)
/* Array<AbyssEngine::ShaderBaseStruct*>::~Array() */

Array<AbyssEngine::ShaderBaseStruct*> * __thiscall
Array<AbyssEngine::ShaderBaseStruct*>::~Array(Array<AbyssEngine::ShaderBaseStruct*> *this)

{
  if (*(void **)(this + 4) != (void *)0x0) {
    operator_delete__(*(void **)(this + 4));
  }
  *(undefined4 *)(this + 4) = 0;
  return this;
}

