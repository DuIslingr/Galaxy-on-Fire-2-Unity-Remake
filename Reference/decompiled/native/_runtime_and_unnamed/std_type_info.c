// Class: std::type_info
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== std::type_info::~type_info  @0x001c55e8  (2 bytes)
/* std::type_info::~type_info() */

type_info * __thiscall std::type_info::~type_info(type_info *this)

{
  return this;
}

// ===== std::type_info::~type_info  @0x001c55ea  (4 bytes)
/* std::type_info::~type_info() */

void __thiscall std::type_info::~type_info(type_info *this)

{
  operator_delete(this);
  return;
}

