// Class: AbyssEngine::GlowShader
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::GlowShader::GlowShader  @0x0009cb30  (104 bytes)
/* AbyssEngine::GlowShader::GlowShader() */

void __thiscall AbyssEngine::GlowShader::GlowShader(GlowShader *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_00263c94;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"GlowShader",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::GlowShader::Init  @0x0009cbdc  (96 bytes)
/* AbyssEngine::GlowShader::Init(AbyssEngine::Engine*) */

void AbyssEngine::GlowShader::Init(Engine *param_1)

{
  undefined4 uVar1;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 \ta_position;  \nattribute mediump vec2  a_texCoord;    \nvarying mediump vec2 v_texCoord;  \nuniform highp mat4 u_ModelViewProjectionMatrix;  \nvoid main()  \n{  \n\tgl_Position = u_ModelViewProjectionMatrix * a_position;  \n\tv_texCoord  = a_texCoord;    \n}  \n"
                     ,
                     "precision lowp float;  \nvarying mediump vec2 v_texCoord;\nuniform sampler2D  s_texture;\nvoid main()\n{\n   gl_FragColor.a = step(0.5/*08*/, texture2D(s_texture, v_texCoord).a); \n}\n"
                    );
  *(undefined4 *)(param_1 + 4) = uVar1;
  uVar1 = glGetAttribLocation(uVar1,"a_position");
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_texCoord");
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_ModelViewProjectionMatrix");
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_ModelMatrix");
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"s_texture");
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 4));
  glUniform1i(*(undefined4 *)(param_1 + 0x2c),0);
  return;
}

// ===== AbyssEngine::GlowShader::SetInActive  @0x0009cc58  (32 bytes)
/* AbyssEngine::GlowShader::SetInActive() */

void __thiscall AbyssEngine::GlowShader::SetInActive(GlowShader *this)

{
  if (-1 < *(int *)(this + 0x1c)) {
    glDisableVertexAttribArray();
  }
  if (*(int *)(this + 0x20) < 0) {
    return;
  }
  glDisableVertexAttribArray();
  return;
}

// ===== AbyssEngine::GlowShader::UpdateMeshData  @0x0009cc78  (178 bytes)
/* AbyssEngine::GlowShader::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::GlowShader::UpdateMeshData(GlowShader *this,Mesh *param_1,Engine *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (-1 < *(int *)(this + 0x24)) {
    glUniformMatrix4fv(*(int *)(this + 0x24),1,0,param_2 + 0xf4);
  }
  if (-1 < *(int *)(this + 0x28)) {
    glUniformMatrix3fv(*(int *)(this + 0x28),1,0,param_2 + 500);
  }
  if (-1 < *(int *)(this + 0x1c)) {
    glEnableVertexAttribArray();
  }
  if (-1 < *(int *)(this + 0x20)) {
    glEnableVertexAttribArray();
  }
  if (param_1[0x5c] == (Mesh)0x0) {
    if (-1 < *(int *)(this + 0x1c)) {
      glVertexAttribPointer(*(int *)(this + 0x1c),3,0x1406,0,0,*(undefined4 *)(param_1 + 4));
    }
    iVar1 = *(int *)(this + 0x20);
    if (iVar1 < 0) {
      return;
    }
    uVar2 = *(undefined4 *)(param_1 + 8);
  }
  else {
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x60));
    glVertexAttribPointer(*(undefined4 *)(this + 0x1c),3,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x68));
    iVar1 = *(int *)(this + 0x20);
    uVar2 = 0;
  }
  glVertexAttribPointer(iVar1,2,0x1406,0,0,uVar2);
  return;
}

