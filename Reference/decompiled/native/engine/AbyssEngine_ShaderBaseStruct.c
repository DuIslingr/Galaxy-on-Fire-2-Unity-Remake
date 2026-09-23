// Class: AbyssEngine::ShaderBaseStruct
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::ShaderBaseStruct::RenderEffect  @0x00092c78  (2 bytes)
/* AbyssEngine::ShaderBaseStruct::RenderEffect(AbyssEngine::FBOContainer*, AbyssEngine::Engine*) */

FBOContainer * AbyssEngine::ShaderBaseStruct::RenderEffect(FBOContainer *param_1,Engine *param_2)

{
  return param_1;
}

// ===== AbyssEngine::ShaderBaseStruct::RenderEffect  @0x00092c7a  (2 bytes)
/* AbyssEngine::ShaderBaseStruct::RenderEffect(AbyssEngine::FBOContainer*, AbyssEngine::Engine*,
   float, AbyssEngine::AEMath::Vector) */

void AbyssEngine::ShaderBaseStruct::RenderEffect(void)

{
  return;
}

// ===== AbyssEngine::ShaderBaseStruct::RenderEffect  @0x00092c7c  (2 bytes)
/* AbyssEngine::ShaderBaseStruct::RenderEffect(AbyssEngine::FBOContainer*,
   AbyssEngine::FBOContainer*&, AbyssEngine::Engine*) */

FBOContainer *
AbyssEngine::ShaderBaseStruct::RenderEffect
          (FBOContainer *param_1,FBOContainer **param_2,Engine *param_3)

{
  return param_1;
}

// ===== AbyssEngine::ShaderBaseStruct::RenderEffect  @0x00092c7e  (2 bytes)
/* AbyssEngine::ShaderBaseStruct::RenderEffect(AbyssEngine::FBOContainer*,
   AbyssEngine::FBOContainer*&, AbyssEngine::Engine*, float, AbyssEngine::AEMath::Vector) */

void AbyssEngine::ShaderBaseStruct::RenderEffect(void)

{
  return;
}

// ===== AbyssEngine::ShaderBaseStruct::ShaderBaseStruct  @0x0009918c  (120 bytes)
/* AbyssEngine::ShaderBaseStruct::ShaderBaseStruct() */

void __thiscall AbyssEngine::ShaderBaseStruct::ShaderBaseStruct(ShaderBaseStruct *this)

{
  String aSStack_1c [8];
  int local_14;
  
  local_14 = __stack_chk_guard;
  *(undefined ***)this = &PTR___cxa_pure_virtual_00263918;
  String::String((String *)(this + 0xc));
  this[8] = (ShaderBaseStruct)0x0;
  this[9] = (ShaderBaseStruct)0x1;
  *(undefined4 *)(this + 4) = 0xffffffff;
  shaderIndexIntern = shaderIndexIntern + 1;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  String::String(aSStack_1c,"ShaderBaseStruct",false);
  String::operator=((String *)(this + 0xc),aSStack_1c);
  String::~String(aSStack_1c);
  if (__stack_chk_guard - local_14 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_14);
  }
  return;
}

// ===== AbyssEngine::ShaderBaseStruct::DeleteShader  @0x00099230  (8 bytes)
/* AbyssEngine::ShaderBaseStruct::DeleteShader() */

void __thiscall AbyssEngine::ShaderBaseStruct::DeleteShader(ShaderBaseStruct *this)

{
  glDeleteProgram(*(undefined4 *)(this + 4));
  return;
}

// ===== AbyssEngine::ShaderBaseStruct::ES2LoadShader  @0x00099238  (142 bytes)
/* AbyssEngine::ShaderBaseStruct::ES2LoadShader(unsigned int, char const*) */

void __thiscall
AbyssEngine::ShaderBaseStruct::ES2LoadShader(ShaderBaseStruct *this,uint param_1,char *param_2)

{
  size_t sVar1;
  int iVar2;
  void *__ptr;
  size_t local_24;
  int local_20;
  char *local_1c;
  int local_18;
  
  local_18 = __stack_chk_guard;
  local_1c = param_2;
  iVar2 = glCreateShader(param_1);
  if (iVar2 != 0) {
    glShaderSource(iVar2,1,&local_1c,0);
    glCompileShader(iVar2);
    glGetShaderiv(iVar2,0x8b81,&local_20);
    if (local_20 == 0) {
      local_24 = 0;
      glGetShaderiv(iVar2,0x8b84,&local_24);
      sVar1 = local_24;
      if (1 < (int)local_24) {
        __ptr = malloc(local_24);
        glGetShaderInfoLog(iVar2,sVar1,0,__ptr);
        free(__ptr);
      }
      glDeleteShader(iVar2);
    }
  }
  if (__stack_chk_guard - local_18 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_18);
}

// ===== AbyssEngine::ShaderBaseStruct::ES2LoadProgram  @0x000992d0  (234 bytes)
/* AbyssEngine::ShaderBaseStruct::ES2LoadProgram(char const*, char const*) */

void __thiscall
AbyssEngine::ShaderBaseStruct::ES2LoadProgram(ShaderBaseStruct *this,char *param_1,char *param_2)

{
  size_t sVar1;
  ShaderBaseStruct *this_00;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  void *__ptr;
  size_t local_24;
  int local_20;
  ShaderBaseStruct *local_1c;
  
  local_1c = __stack_chk_guard;
  this_00 = (ShaderBaseStruct *)ES2LoadShader(__stack_chk_guard,0x8b31,param_1);
  if (this_00 != (ShaderBaseStruct *)0x0) {
    iVar2 = ES2LoadShader(this_00,0x8b30,param_2);
    if (iVar2 == 0) {
      glDeleteShader(this_00);
    }
    else {
      uVar3 = glCreateProgram();
      if (uVar3 != 0) {
        glAttachShader(uVar3,this_00);
        glAttachShader(uVar3,iVar2);
        glLinkProgram(uVar3);
        glGetProgramiv(uVar3,0x8b82,&local_20);
        if (local_20 == 0) {
          local_24 = 0;
          glGetProgramiv(uVar3,0x8b84,&local_24);
          sVar1 = local_24;
          if (1 < (int)local_24) {
            __ptr = malloc(local_24);
            glGetProgramInfoLog(uVar3,sVar1,0,__ptr);
            free(__ptr);
          }
          glDeleteProgram(uVar3);
        }
        else {
          glDeleteShader(this_00);
          glDeleteShader(iVar2);
          pcVar4 = (char *)String::GetAEChar((String *)(this + 0xc));
          AELabelObject(0x8b40,uVar3,pcVar4);
          if (pcVar4 != (char *)0x0) {
            operator_delete__(pcVar4);
          }
        }
      }
    }
  }
  if ((int)__stack_chk_guard - (int)local_1c == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail((int)__stack_chk_guard - (int)local_1c);
}

// ===== AbyssEngine::ShaderBaseStruct::LoadBindShader  @0x000993c4  (206 bytes)
/* AbyssEngine::ShaderBaseStruct::LoadBindShader(char const*, char const*) */

void __thiscall
AbyssEngine::ShaderBaseStruct::LoadBindShader(ShaderBaseStruct *this,char *param_1,char *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  uint local_24;
  int local_20;
  
  local_20 = __stack_chk_guard;
  if ((param_1 != (char *)0x0) && (param_2 != (char *)0x0)) {
    *(char **)(this + 0x14) = param_1;
    *(char **)(this + 0x18) = param_2;
    iVar1 = AEFile::OpenRead(param_1,&local_24);
    if (iVar1 == 1) {
      uVar2 = AEFile::GetFileSize(local_24);
      uVar3 = uVar2 + 1;
      if ((int)uVar2 < -1) {
        uVar3 = 0xffffffff;
      }
      pcVar4 = operator_new__(uVar3);
      AEFile::Read(uVar2,pcVar4,local_24);
      AEFile::Close(local_24);
      pcVar4[uVar2] = '\0';
      iVar1 = AEFile::OpenRead(param_2,&local_24);
      if (iVar1 == 1) {
        uVar2 = AEFile::GetFileSize(local_24);
        uVar3 = uVar2 + 1;
        if ((int)uVar2 < -1) {
          uVar3 = 0xffffffff;
        }
        pcVar5 = operator_new__(uVar3);
        AEFile::Read(uVar2,pcVar5,local_24);
        AEFile::Close(local_24);
        pcVar5[uVar2] = '\0';
        ES2LoadProgram(this,pcVar4,pcVar5);
        operator_delete__(pcVar5);
        operator_delete__(pcVar4);
      }
    }
  }
  if (__stack_chk_guard - local_20 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_20);
  }
  return;
}

// ===== AbyssEngine::ShaderBaseStruct::UseShader  @0x0009949c  (6 bytes)
/* AbyssEngine::ShaderBaseStruct::UseShader(bool) */

void AbyssEngine::ShaderBaseStruct::UseShader(bool param_1)

{
  glUseProgram(*(undefined4 *)(param_1 + 4));
  return;
}

// ===== AbyssEngine::ShaderBaseStruct::Update  @0x000994a2  (6 bytes)
/* AbyssEngine::ShaderBaseStruct::Update() */

void __thiscall AbyssEngine::ShaderBaseStruct::Update(ShaderBaseStruct *this)

{
  this[9] = (ShaderBaseStruct)0x1;
  return;
}

