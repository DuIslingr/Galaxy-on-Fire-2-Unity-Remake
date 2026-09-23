// Class: AbyssEngine::PulseShader
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::PulseShader::PulseShader  @0x0009cf80  (104 bytes)
/* AbyssEngine::PulseShader::PulseShader() */

void __thiscall AbyssEngine::PulseShader::PulseShader(PulseShader *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_00263d04;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"PulseShader",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::PulseShader::Init  @0x0009d02c  (216 bytes)
/* AbyssEngine::PulseShader::Init(AbyssEngine::Engine*) */

void AbyssEngine::PulseShader::Init(Engine *param_1)

{
  undefined4 uVar1;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position;   \nattribute mediump vec2 a_texCoord;   \nvarying mediump vec2 v_texCoord;     \nuniform highp mat4 u_ModelViewProjectionMatrix;  \nvoid main()                  \n{                            \n   gl_Position = u_ModelViewProjectionMatrix * a_position;\t\t\n   v_texCoord = a_texCoord;  \n}                            \n"
                     ,
                     "precision lowp float;\nvarying mediump vec2 v_texCoord;\nuniform sampler2D  s_texture;\nuniform highp float u_timevalue;\nvoid main()\n{\n\tvec4 textureColor = texture2D(  s_texture, v_texCoord );\n\tgl_FragColor = textureColor * vec4(vec3( u_timevalue ), 1.0); // * vec4(4.0,4.0,4.0,1.0);\n}\n"
                    );
  *(undefined4 *)(param_1 + 4) = uVar1;
  uVar1 = glGetAttribLocation(uVar1,"a_position");
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_texCoord");
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_normal");
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_tangent");
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_bitangent");
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_ModelViewProjectionMatrix");
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_ModelMatrix");
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_lightdirmodel");
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_eyeposmodel");
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_timevalue");
  *(undefined4 *)(param_1 + 0x54) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"s_texture");
  *(undefined4 *)(param_1 + 0x40) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"glColor");
  *(undefined4 *)(param_1 + 0x44) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_AmbientColor");
  *(undefined4 *)(param_1 + 0x48) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_DiffuseColor");
  *(undefined4 *)(param_1 + 0x4c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_SpecularColor");
  *(undefined4 *)(param_1 + 0x50) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 4));
  glUniform1i(*(undefined4 *)(param_1 + 0x40),0);
  return;
}

// ===== AbyssEngine::PulseShader::SetInActive  @0x0009d148  (62 bytes)
/* AbyssEngine::PulseShader::SetInActive() */

void __thiscall AbyssEngine::PulseShader::SetInActive(PulseShader *this)

{
  if (-1 < *(int *)(this + 0x1c)) {
    glDisableVertexAttribArray();
  }
  if (-1 < *(int *)(this + 0x20)) {
    glDisableVertexAttribArray();
  }
  if (-1 < *(int *)(this + 0x24)) {
    glDisableVertexAttribArray();
  }
  if (-1 < *(int *)(this + 0x28)) {
    glDisableVertexAttribArray();
  }
  if (*(int *)(this + 0x2c) < 0) {
    return;
  }
  glDisableVertexAttribArray();
  return;
}

// ===== AbyssEngine::PulseShader::UpdateMeshData  @0x0009d188  (530 bytes)
/* AbyssEngine::PulseShader::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::PulseShader::UpdateMeshData(PulseShader *this,Mesh *param_1,Engine *param_2)

{
  float fVar1;
  float extraout_r0;
  int iVar2;
  undefined4 uVar3;
  
  if (-1 < *(int *)(this + 0x30)) {
    glUniformMatrix4fv(*(int *)(this + 0x30),1,0,param_2 + 0xf4);
  }
  if (-1 < *(int *)(this + 0x34)) {
    glUniformMatrix3fv(*(int *)(this + 0x34),1,0,param_2 + 500);
  }
  if (this[9] != (PulseShader)0x0) {
    if (-1 < *(int *)(this + 0x38)) {
      glUniform3f(*(int *)(this + 0x38),*(undefined4 *)(param_2 + 800),
                  *(undefined4 *)(param_2 + 0x324),*(undefined4 *)(param_2 + 0x328));
    }
    if (-1 < *(int *)(this + 0x3c)) {
      glUniform3f(*(int *)(this + 0x3c),*(undefined4 *)(param_2 + 0x33c),
                  *(undefined4 *)(param_2 + 0x340),*(undefined4 *)(param_2 + 0x344));
    }
    if (-1 < *(int *)(this + 0x44)) {
      glUniform4fv(*(int *)(this + 0x44),1,param_2 + 0xc0);
    }
    if (-1 < *(int *)(this + 0x48)) {
      glUniform4fv(*(int *)(this + 0x48),1,param_2 + 0x298);
    }
    if (-1 < *(int *)(this + 0x4c)) {
      glUniform4fv(*(int *)(this + 0x4c),1,param_2 + 0x288);
    }
    if (-1 < *(int *)(this + 0x50)) {
      glUniform4fv(*(int *)(this + 0x50),1,param_2 + 0x2a8);
    }
    ApplicationManager::GetCurrentTimeMillis(*(ApplicationManager **)(param_2 + 0x28));
    fVar1 = (float)__aeabi_l2f();
    sinf(fVar1 / 1000.0);
    glUniform1f(*(undefined4 *)(this + 0x54),extraout_r0 + 2.0);
    this[9] = (PulseShader)0x0;
  }
  if (-1 < *(int *)(this + 0x1c)) {
    glEnableVertexAttribArray();
  }
  if (-1 < *(int *)(this + 0x20)) {
    glEnableVertexAttribArray();
  }
  if (-1 < *(int *)(this + 0x24)) {
    glEnableVertexAttribArray();
  }
  if (-1 < *(int *)(this + 0x28)) {
    glEnableVertexAttribArray();
  }
  if (-1 < *(int *)(this + 0x2c)) {
    glEnableVertexAttribArray();
  }
  if (param_1[0x5c] == (Mesh)0x0) {
    if (-1 < *(int *)(this + 0x1c)) {
      glVertexAttribPointer(*(int *)(this + 0x1c),3,0x1406,0,0,*(undefined4 *)(param_1 + 4));
    }
    if (-1 < *(int *)(this + 0x20)) {
      glVertexAttribPointer(*(int *)(this + 0x20),2,0x1406,0,0,*(undefined4 *)(param_1 + 8));
    }
    if (-1 < *(int *)(this + 0x24)) {
      glVertexAttribPointer(*(int *)(this + 0x24),3,0x1406,0,0,*(undefined4 *)(param_1 + 0x10));
    }
    if (-1 < *(int *)(this + 0x28)) {
      glVertexAttribPointer(*(int *)(this + 0x28),3,0x1406,0,0,*(undefined4 *)(param_1 + 0x14));
    }
    iVar2 = *(int *)(this + 0x2c);
    if (iVar2 < 0) {
      return;
    }
    uVar3 = *(undefined4 *)(param_1 + 0x18);
  }
  else {
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x60));
    glVertexAttribPointer(*(undefined4 *)(this + 0x1c),3,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x68));
    glVertexAttribPointer(*(undefined4 *)(this + 0x20),2,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x6c));
    glVertexAttribPointer(*(undefined4 *)(this + 0x24),3,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x70));
    glVertexAttribPointer(*(undefined4 *)(this + 0x28),3,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x74));
    iVar2 = *(int *)(this + 0x2c);
    uVar3 = 0;
  }
  glVertexAttribPointer(iVar2,3,0x1406,0,0,uVar3);
  return;
}

