// Class: AbyssEngine::AEMath::Vector
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::AEMath::Vector::operator.cast.to.float*  @0x0007cf0c  (2 bytes)
/* AbyssEngine::AEMath::Vector::operator float*() */

float * __thiscall AbyssEngine::AEMath::Vector::operator_cast_to_float_(Vector *this)

{
  return (float *)this;
}

// ===== AbyssEngine::AEMath::Vector::operator.cast.to.float*  @0x0007cf0e  (2 bytes)
/* AbyssEngine::AEMath::Vector::operator float const*() const */

float * __thiscall AbyssEngine::AEMath::Vector::operator_cast_to_float_(Vector *this)

{
  return (float *)this;
}

// ===== AbyssEngine::AEMath::Vector::operator[]  @0x0007cf10  (6 bytes)
/* AbyssEngine::AEMath::Vector::operator[](int) */

Vector * __thiscall AbyssEngine::AEMath::Vector::operator[](Vector *this,int param_1)

{
  return this + param_1 * 4;
}

// ===== AbyssEngine::AEMath::Vector::operator[]  @0x0007cf16  (6 bytes)
/* AbyssEngine::AEMath::Vector::operator[](int) const */

Vector * __thiscall AbyssEngine::AEMath::Vector::operator[](Vector *this,int param_1)

{
  return this + param_1 * 4;
}

// ===== AbyssEngine::AEMath::Vector::operator=  @0x0007cf1c  (14 bytes)
/* AbyssEngine::AEMath::Vector::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::Vector const&) */

void __thiscall AbyssEngine::AEMath::Vector::operator=(Vector *this,Vector *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  return;
}

// ===== AbyssEngine::AEMath::Vector::operator+=  @0x0007cf2a  (50 bytes)
/* AbyssEngine::AEMath::Vector::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::Vector const&) */

void __thiscall AbyssEngine::AEMath::Vector::operator+=(Vector *this,Vector *param_1)

{
  *(float *)this = *(float *)param_1 + *(float *)this;
  *(float *)(this + 4) = *(float *)(param_1 + 4) + *(float *)(this + 4);
  *(float *)(this + 8) = *(float *)(param_1 + 8) + *(float *)(this + 8);
  return;
}

// ===== AbyssEngine::AEMath::Vector::operator-=  @0x0007cf5c  (50 bytes)
/* AbyssEngine::AEMath::Vector::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::Vector const&) */

void __thiscall AbyssEngine::AEMath::Vector::operator-=(Vector *this,Vector *param_1)

{
  *(float *)this = *(float *)this - *(float *)param_1;
  *(float *)(this + 4) = *(float *)(this + 4) - *(float *)(param_1 + 4);
  *(float *)(this + 8) = *(float *)(this + 8) - *(float *)(param_1 + 8);
  return;
}

// ===== AbyssEngine::AEMath::Vector::operator*=  @0x0007cf8e  (42 bytes)
/* AbyssEngine::AEMath::Vector::TEMPNAMEPLACEHOLDERVALUE(float) */

void __thiscall AbyssEngine::AEMath::Vector::operator*=(Vector *this,float param_1)

{
  float in_r1;
  
  *(float *)this = *(float *)this * in_r1;
  *(float *)(this + 4) = *(float *)(this + 4) * in_r1;
  *(float *)(this + 8) = *(float *)(this + 8) * in_r1;
  return;
}

// ===== AbyssEngine::AEMath::Vector::operator*=  @0x0007cfb8  (50 bytes)
/* AbyssEngine::AEMath::Vector::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::Vector const&) */

void __thiscall AbyssEngine::AEMath::Vector::operator*=(Vector *this,Vector *param_1)

{
  *(float *)this = *(float *)param_1 * *(float *)this;
  *(float *)(this + 4) = *(float *)(param_1 + 4) * *(float *)(this + 4);
  *(float *)(this + 8) = *(float *)(param_1 + 8) * *(float *)(this + 8);
  return;
}

// ===== AbyssEngine::AEMath::Vector::operator/=  @0x0007cfea  (42 bytes)
/* AbyssEngine::AEMath::Vector::TEMPNAMEPLACEHOLDERVALUE(float) */

void __thiscall AbyssEngine::AEMath::Vector::operator/=(Vector *this,float param_1)

{
  float in_r1;
  
  *(float *)this = *(float *)this / in_r1;
  *(float *)(this + 4) = *(float *)(this + 4) / in_r1;
  *(float *)(this + 8) = *(float *)(this + 8) / in_r1;
  return;
}

// ===== AbyssEngine::AEMath::Vector::operator/=  @0x0007d014  (50 bytes)
/* AbyssEngine::AEMath::Vector::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::AEMath::Vector const&) */

void __thiscall AbyssEngine::AEMath::Vector::operator/=(Vector *this,Vector *param_1)

{
  *(float *)this = *(float *)param_1 * *(float *)this;
  *(float *)(this + 4) = *(float *)(param_1 + 4) * *(float *)(this + 4);
  *(float *)(this + 8) = *(float *)(param_1 + 8) * *(float *)(this + 8);
  return;
}

