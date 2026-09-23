// Class: std::bad_exception
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== std::bad_exception::~bad_exception  @0x001c4568  (2 bytes)
/* std::bad_exception::~bad_exception() */

bad_exception * __thiscall std::bad_exception::~bad_exception(bad_exception *this)

{
  return this;
}

// ===== std::bad_exception::~bad_exception  @0x001c457c  (4 bytes)
/* std::bad_exception::~bad_exception() */

void __thiscall std::bad_exception::~bad_exception(bad_exception *this)

{
  operator_delete(this);
  return;
}

// ===== std::bad_exception::what  @0x001c4580  (6 bytes)
/* std::bad_exception::what() const */

char * std::bad_exception::what(void)

{
  return "std::bad_exception";
}

