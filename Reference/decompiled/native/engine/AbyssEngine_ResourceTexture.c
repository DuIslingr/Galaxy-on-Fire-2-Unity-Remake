// Class: AbyssEngine::ResourceTexture
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::ResourceTexture::ResourceTexture  @0x001405a0  (58 bytes)
/* AbyssEngine::ResourceTexture::ResourceTexture(AbyssEngine::String const&, float) */

ResourceTexture * __thiscall
AbyssEngine::ResourceTexture::ResourceTexture(ResourceTexture *this,String *param_1,float param_2)

{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  undefined4 in_r2;
  
  pvVar1 = (void *)String::GetAEChar((String *)param_1);
  iVar2 = *(int *)(param_1 + 4);
  pvVar3 = operator_new__(iVar2 + 1U);
  *(void **)this = pvVar3;
  __aeabi_memcpy(pvVar3,pvVar1,iVar2 + 1U);
  *(undefined4 *)(this + 4) = in_r2;
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  return this;
}

