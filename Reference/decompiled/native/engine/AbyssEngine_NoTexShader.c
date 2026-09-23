// Class: AbyssEngine::NoTexShader
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::NoTexShader::NoTexShader  @0x0009b27c  (104 bytes)
/* AbyssEngine::NoTexShader::NoTexShader() */

void __thiscall AbyssEngine::NoTexShader::NoTexShader(NoTexShader *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_00263ad4;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"NoTexShader",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::NoTexShader::Init  @0x0009b328  (64 bytes)
/* AbyssEngine::NoTexShader::Init(AbyssEngine::Engine*) */

void AbyssEngine::NoTexShader::Init(Engine *param_1)

{
  undefined4 uVar1;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position;   \nuniform highp mat4 u_WorldMatrix;  \nvoid main()                  \n{                            \n   gl_Position = u_WorldMatrix * a_position;\t\t\n}                            \n"
                     ,
                     "precision lowp float;                            \nuniform lowp vec4 glColor;\t\t\t\t\t\t\t\t \nvoid main()                                         \n{                                                   \n\t\tgl_FragColor = glColor;\n}   \t\t  \n"
                    );
  *(undefined4 *)(param_1 + 4) = uVar1;
  uVar1 = glGetAttribLocation(uVar1,"a_position");
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_WorldMatrix");
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"glColor");
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 4));
  return;
}

// ===== AbyssEngine::NoTexShader::SetInActive  @0x0009b37c  (6 bytes)
/* AbyssEngine::NoTexShader::SetInActive() */

void __thiscall AbyssEngine::NoTexShader::SetInActive(NoTexShader *this)

{
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x1c));
  return;
}

// ===== AbyssEngine::NoTexShader::UpdateMeshData  @0x0009b382  (128 bytes)
/* AbyssEngine::NoTexShader::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::NoTexShader::UpdateMeshData(NoTexShader *this,Mesh *param_1,Engine *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  glUniformMatrix4fv(*(undefined4 *)(this + 0x20),1,0,param_2 + 0xf4);
  if (this[9] != (NoTexShader)0x0) {
    glUniform4fv(*(undefined4 *)(this + 0x24),1,param_2 + 0xc0);
    this[9] = (NoTexShader)0x0;
  }
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x1c));
  if (param_1 == (Mesh *)0x0) {
    uVar2 = *(undefined4 *)(param_2 + 0x338);
    uVar1 = *(undefined4 *)(this + 0x1c);
    uVar3 = 2;
  }
  else {
    if (param_1[0x5c] == (Mesh)0x0) {
      uVar1 = *(undefined4 *)(this + 0x1c);
      uVar2 = *(undefined4 *)(param_1 + 4);
    }
    else {
      glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x60));
      uVar2 = 0;
      uVar1 = *(undefined4 *)(this + 0x1c);
    }
    uVar3 = 3;
  }
  glVertexAttribPointer(uVar1,uVar3,0x1406,0,0,uVar2);
  return;
}

