// Class: AMeshMerger
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AMeshMerger::render  @0x001b1ad8  (12 bytes)
/* AMeshMerger::render() */

void __thiscall AMeshMerger::render(AMeshMerger *this)

{
  AbyssEngine::PaintCanvas::DrawTransform
            (*(PaintCanvas **)(this + 0x14),*(uint *)(this + 0x1c),(Matrix *)0x0);
  return;
}

// ===== AMeshMerger::~AMeshMerger  @0x001b1ae4  (22 bytes)
/* AMeshMerger::~AMeshMerger() */

AMeshMerger * __thiscall AMeshMerger::~AMeshMerger(AMeshMerger *this)

{
  if (*(void **)(this + 0xc) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0xc));
  }
  *(undefined4 *)(this + 0xc) = 0;
  return this;
}

