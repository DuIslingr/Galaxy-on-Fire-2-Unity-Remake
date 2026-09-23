// Class: std::exception
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== std::exception::~exception  @0x001c456a  (4 bytes)
/* std::exception::~exception() */

void __thiscall std::exception::~exception(exception *this)

{
  operator_delete(this);
  return;
}

// ===== std::exception::what  @0x001c4570  (6 bytes)
/* std::exception::what() const */

char * std::exception::what(void)

{
  return "std::exception";
}

