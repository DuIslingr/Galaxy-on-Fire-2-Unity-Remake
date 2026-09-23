// Class: AbyssEngine::DNSShader
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::DNSShader::DNSShader  @0x0009a010  (104 bytes)
/* AbyssEngine::DNSShader::DNSShader() */

void __thiscall AbyssEngine::DNSShader::DNSShader(DNSShader *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_002639f4;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"DNSShader",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::DNSShader::Init  @0x0009a0bc  (250 bytes)
/* AbyssEngine::DNSShader::Init(AbyssEngine::Engine*) */

void AbyssEngine::DNSShader::Init(Engine *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ShaderBaseStruct::LoadBindShader
                    ((ShaderBaseStruct *)param_1,"data/shader/DNSShader.vs",
                     "data/shader/DNSShader.fs");
  *(int *)(param_1 + 4) = iVar1;
  if (iVar1 == 0) {
    iVar1 = ShaderBaseStruct::ES2LoadProgram
                      ((ShaderBaseStruct *)param_1,
                       "attribute highp vec3 \ta_position;  \nuniform highp mat4 u_ModelViewProjectionMatrix;  \nvoid main()  \n{  \n\tgl_Position = u_ModelViewProjectionMatrix * vec4(a_position, 1.0);  \n}  \n"
                       ,
                       "precision lowp float;  \nvoid main()  \n{  \n       gl_FragColor = vec4(0.5, 0.5, 0.5, 1.0); \n}  \n"
                      );
    *(int *)(param_1 + 4) = iVar1;
  }
  uVar2 = glGetAttribLocation(iVar1,"a_position");
  *(undefined4 *)(param_1 + 0x1c) = uVar2;
  uVar2 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_texCoord");
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  uVar2 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_normal");
  *(undefined4 *)(param_1 + 0x24) = uVar2;
  uVar2 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_tangent");
  *(undefined4 *)(param_1 + 0x28) = uVar2;
  uVar2 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_bitangent");
  *(undefined4 *)(param_1 + 0x2c) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_ModelViewProjectionMatrix");
  *(undefined4 *)(param_1 + 0x30) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_ModelMatrix");
  *(undefined4 *)(param_1 + 0x34) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_ModelMatrixFull");
  *(undefined4 *)(param_1 + 0x38) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_lightdirmodel");
  *(undefined4 *)(param_1 + 0x3c) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_eyeposmodel");
  *(undefined4 *)(param_1 + 0x40) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"glColor");
  *(undefined4 *)(param_1 + 0x44) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_AmbientColor");
  *(undefined4 *)(param_1 + 0x48) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_DiffuseColor");
  *(undefined4 *)(param_1 + 0x4c) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_SpecularColor");
  *(undefined4 *)(param_1 + 0x50) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_SpecularPower");
  *(undefined4 *)(param_1 + 0x54) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_TexBiasDiffuse");
  *(undefined4 *)(param_1 + 0x58) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_TexBiasNormal");
  *(undefined4 *)(param_1 + 0x5c) = uVar2;
  glUseProgram(*(undefined4 *)(param_1 + 4));
  return;
}

// ===== AbyssEngine::DNSShader::SetInActive  @0x0009a20c  (62 bytes)
/* AbyssEngine::DNSShader::SetInActive() */

void __thiscall AbyssEngine::DNSShader::SetInActive(DNSShader *this)

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

// ===== AbyssEngine::DNSShader::UpdateMeshData  @0x0009a24c  (540 bytes)
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* AbyssEngine::DNSShader::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::DNSShader::UpdateMeshData(DNSShader *this,Mesh *param_1,Engine *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (-1 < *(int *)(this + 0x30)) {
    glUniformMatrix4fv(*(int *)(this + 0x30),1,0,param_2 + 0xf4);
  }
  if (-1 < *(int *)(this + 0x34)) {
    glUniformMatrix3fv(*(int *)(this + 0x34),1,0,param_2 + 500);
  }
  if (-1 < *(int *)(this + 0x38)) {
    glUniformMatrix4fv(*(int *)(this + 0x38),1,0,param_2 + 0x134);
  }
  if (-1 < *(int *)(this + 0x58)) {
    glUniform1f(*(int *)(this + 0x58),**(undefined4 **)(_FUN_0009a468 + 0x9a29a));
  }
  if (-1 < *(int *)(this + 0x5c)) {
    glUniform1f(*(int *)(this + 0x5c),**(undefined4 **)(iRam0009a46c + 0x9a2ac));
  }
  if (this[9] != (DNSShader)0x0) {
    glUniform3f(*(undefined4 *)(this + 0x3c),*(undefined4 *)(param_2 + 800),
                *(undefined4 *)(param_2 + 0x324),*(undefined4 *)(param_2 + 0x328));
    if (-1 < *(int *)(this + 0x40)) {
      glUniform3f(*(int *)(this + 0x40),*(undefined4 *)(param_2 + 0x33c),
                  *(undefined4 *)(param_2 + 0x340),*(undefined4 *)(param_2 + 0x344));
    }
    if (-1 < *(int *)(this + 0x44)) {
      glUniform4fv(*(int *)(this + 0x44),1,param_2 + 0xc0);
    }
    if (-1 < *(int *)(this + 0x48)) {
      glUniform3fv(*(int *)(this + 0x48),1,param_2 + 700);
    }
    if (-1 < *(int *)(this + 0x4c)) {
      glUniform3fv(*(int *)(this + 0x4c),1,param_2 + 0x2ec);
    }
    if (-1 < *(int *)(this + 0x50)) {
      glUniform3fv(*(int *)(this + 0x50),1,param_2 + 0x2d4);
    }
    if (-1 < *(int *)(this + 0x54)) {
      glUniform1f(*(int *)(this + 0x54),*(undefined4 *)(param_2 + 0x2b8));
    }
    this[9] = (DNSShader)0x0;
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
    iVar1 = *(int *)(this + 0x2c);
    if (iVar1 < 0) {
      return;
    }
    uVar2 = *(undefined4 *)(param_1 + 0x18);
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
    iVar1 = *(int *)(this + 0x2c);
    uVar2 = 0;
  }
  glVertexAttribPointer(iVar1,3,0x1406,0,0,uVar2);
  return;
}

