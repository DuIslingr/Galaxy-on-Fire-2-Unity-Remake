// Class: AbyssEngine::TexOnlyShader
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::TexOnlyShader::TexOnlyShader  @0x000964d0  (104 bytes)
/* AbyssEngine::TexOnlyShader::TexOnlyShader() */

void __thiscall AbyssEngine::TexOnlyShader::TexOnlyShader(TexOnlyShader *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_002636b0;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"TexOnlyShader",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::TexOnlyShader::Init  @0x0009657c  (84 bytes)
/* AbyssEngine::TexOnlyShader::Init(AbyssEngine::Engine*) */

void AbyssEngine::TexOnlyShader::Init(Engine *param_1)

{
  undefined4 uVar1;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position;\nattribute mediump vec2 a_texCoord;\nvarying mediump vec2 v_texCoord;\nuniform highp mat4 u_WorldMatrix;\nvoid main()\n{\n\tgl_Position = u_WorldMatrix * a_position;\n\tv_texCoord = a_texCoord;\n}\n"
                     ,
                     "precision lowp float;\nvarying mediump vec2 v_texCoord;\nuniform sampler2D s_texture_base;\nvoid main()\n{\n\tvec4 textureColor = texture2D( s_texture_base, v_texCoord );\n\tgl_FragColor = textureColor; // * vec4(4.0,4.0,4.0,1.0);\n}\n"
                    );
  *(undefined4 *)(param_1 + 4) = uVar1;
  uVar1 = glGetAttribLocation(uVar1,"a_position");
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_texCoord");
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_WorldMatrix");
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"s_texture_base");
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 4));
  glUniform1i(*(undefined4 *)(param_1 + 0x28),0);
  return;
}

// ===== AbyssEngine::TexOnlyShader::SetInActive  @0x000965e8  (22 bytes)
/* AbyssEngine::TexOnlyShader::SetInActive() */

void __thiscall AbyssEngine::TexOnlyShader::SetInActive(TexOnlyShader *this)

{
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x1c));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x20));
  return;
}

// ===== AbyssEngine::TexOnlyShader::UpdateMeshData  @0x000965fe  (144 bytes)
/* AbyssEngine::TexOnlyShader::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::TexOnlyShader::UpdateMeshData(TexOnlyShader *this,Mesh *param_1,Engine *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  glUniformMatrix4fv(*(undefined4 *)(this + 0x24),1,0,param_2 + 0xf4);
  if (this[9] != (TexOnlyShader)0x0) {
    this[9] = (TexOnlyShader)0x0;
  }
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x1c));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x20));
  if (param_1[0x5c] == (Mesh)0x0) {
    glVertexAttribPointer(*(undefined4 *)(this + 0x1c),3,0x1406,0,0,*(undefined4 *)(param_1 + 4));
    uVar1 = *(undefined4 *)(this + 0x20);
    uVar2 = *(undefined4 *)(param_1 + 8);
  }
  else {
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x60));
    glVertexAttribPointer(*(undefined4 *)(this + 0x1c),3,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x68));
    uVar1 = *(undefined4 *)(this + 0x20);
    uVar2 = 0;
  }
  glVertexAttribPointer(uVar1,2,0x1406,0,0,uVar2);
  return;
}

