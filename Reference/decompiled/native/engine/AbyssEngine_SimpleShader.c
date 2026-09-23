// Class: AbyssEngine::SimpleShader
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::SimpleShader::SimpleShader  @0x00093e60  (104 bytes)
/* AbyssEngine::SimpleShader::SimpleShader() */

void __thiscall AbyssEngine::SimpleShader::SimpleShader(SimpleShader *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_00263528;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"SimpleShader",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::SimpleShader::Init  @0x00093f0c  (64 bytes)
/* AbyssEngine::SimpleShader::Init(AbyssEngine::Engine*) */

void AbyssEngine::SimpleShader::Init(Engine *param_1)

{
  undefined4 uVar1;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position; uniform highp mat4 u_WorldMatrix;void main()                 {                          \tgl_Position = u_WorldMatrix * a_position;\t\t} "
                     ,
                     "precision lowp float;uniform lowp vec4 glColor;void main()  {   gl_FragColor = glColor;} "
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

// ===== AbyssEngine::SimpleShader::SetInActive  @0x00093f60  (6 bytes)
/* AbyssEngine::SimpleShader::SetInActive() */

void __thiscall AbyssEngine::SimpleShader::SetInActive(SimpleShader *this)

{
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x1c));
  return;
}

// ===== AbyssEngine::SimpleShader::UpdateMeshData  @0x00093f66  (110 bytes)
/* AbyssEngine::SimpleShader::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::SimpleShader::UpdateMeshData(SimpleShader *this,Mesh *param_1,Engine *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  glUniformMatrix4fv(*(undefined4 *)(this + 0x20),1,0,param_2 + 0xf4);
  if (this[9] != (SimpleShader)0x0) {
    glUniform4fv(*(undefined4 *)(this + 0x24),1,param_2 + 0xc0);
    this[9] = (SimpleShader)0x0;
  }
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x1c));
  if (param_1[0x5c] == (Mesh)0x0) {
    uVar1 = *(undefined4 *)(this + 0x1c);
    uVar2 = *(undefined4 *)(param_1 + 4);
  }
  else {
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x60));
    uVar2 = 0;
    uVar1 = *(undefined4 *)(this + 0x1c);
  }
  glVertexAttribPointer(uVar1,3,0x1406,0,0,uVar2);
  return;
}

