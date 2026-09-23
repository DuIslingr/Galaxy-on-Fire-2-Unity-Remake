// Class: Array<ParticleSystemSprite*>
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Array<ParticleSystemSprite*>::~Array  @0x001b4302  (22 bytes)
/* Array<ParticleSystemSprite*>::~Array() */

Array<ParticleSystemSprite*> * __thiscall
Array<ParticleSystemSprite*>::~Array(Array<ParticleSystemSprite*> *this)

{
  if (*(void **)(this + 4) != (void *)0x0) {
    operator_delete__(*(void **)(this + 4));
  }
  *(undefined4 *)(this + 4) = 0;
  return this;
}

