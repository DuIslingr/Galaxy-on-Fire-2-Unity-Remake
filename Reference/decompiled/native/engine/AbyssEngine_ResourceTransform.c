// Class: AbyssEngine::ResourceTransform
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::ResourceTransform::~ResourceTransform  @0x00081c68  (32 bytes)
/* AbyssEngine::ResourceTransform::~ResourceTransform() */

ResourceTransform * __thiscall
AbyssEngine::ResourceTransform::~ResourceTransform(ResourceTransform *this)

{
  if (*(void **)(this + 0x40) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x40));
  }
  *(undefined4 *)(this + 0x40) = 0;
  if (*(void **)(this + 0x48) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x48));
  }
  *(undefined4 *)(this + 0x48) = 0;
  return this;
}

