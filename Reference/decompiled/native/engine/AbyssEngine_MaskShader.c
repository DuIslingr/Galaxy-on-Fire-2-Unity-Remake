// Class: AbyssEngine::MaskShader
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::MaskShader::MaskShader  @0x0009c134  (104 bytes)
/* AbyssEngine::MaskShader::MaskShader() */

void __thiscall AbyssEngine::MaskShader::MaskShader(MaskShader *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_00263bec;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"MaskShader",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::MaskShader::Init  @0x0009c1e0  (140 bytes)
/* AbyssEngine::MaskShader::Init(AbyssEngine::Engine*) */

void AbyssEngine::MaskShader::Init(Engine *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position;   \nattribute mediump vec2 a_texCoord_0;   \nattribute mediump vec2 a_texCoord_1;   \nvarying mediump vec2 v_texCoord[2];     \nuniform highp mat4 u_WorldMatrix;  \nvoid main()                  \n{                            \n   gl_Position = u_WorldMatrix * a_position;\t\t\n   v_texCoord[0] = a_texCoord_0;  \n   v_texCoord[1] = a_texCoord_1;  \n}                            \n"
                     ,
                     "precision lowp float;                            \nvarying mediump vec2 v_texCoord[2];                     \nuniform sampler2D s_texture[2];                        \nuniform lowp vec4 glColor;\t\t\t\t\t\t\t\t \nvoid main()                                         \n{                                                   \n\tvec4 textureColorBase = texture2D( s_texture[0], v_texCoord[0] );\t\n\tvec4 textureColorMask = texture2D( s_texture[1], v_texCoord[1] );\t\n\tgl_FragColor = glColor * textureColorBase;\t\t\n\tgl_FragColor.a = glColor.a * (1.0 - textureColorMask.a) * textureColorBase.a;\t\t\n}   \t\t  \n"
                    );
  *(undefined4 *)(param_1 + 4) = uVar1;
  uVar1 = glGetAttribLocation(uVar1,"a_position");
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_texCoord_0");
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_texCoord_1");
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_WorldMatrix");
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"s_texture[0]");
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"s_texture[1]");
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"glColor");
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 4));
  iVar2 = 0;
  do {
    if (-1 < *(int *)(param_1 + iVar2 * 4 + 0x2c)) {
      glUniform1i(*(int *)(param_1 + iVar2 * 4 + 0x2c),iVar2);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 2);
  return;
}

// ===== AbyssEngine::MaskShader::SetInActive  @0x0009c290  (42 bytes)
/* AbyssEngine::MaskShader::SetInActive() */

void __thiscall AbyssEngine::MaskShader::SetInActive(MaskShader *this)

{
  if (-1 < *(int *)(this + 0x1c)) {
    glDisableVertexAttribArray();
  }
  if (-1 < *(int *)(this + 0x20)) {
    glDisableVertexAttribArray();
  }
  if (*(int *)(this + 0x24) < 0) {
    return;
  }
  glDisableVertexAttribArray();
  return;
}

// ===== AbyssEngine::MaskShader::UpdateMeshData  @0x0009c2ba  (286 bytes)
/* AbyssEngine::MaskShader::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::MaskShader::UpdateMeshData(MaskShader *this,Mesh *param_1,Engine *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if (-1 < *(int *)(this + 0x28)) {
    glUniformMatrix4fv(*(int *)(this + 0x28),1,0,param_2 + 0xf4);
  }
  if (this[9] != (MaskShader)0x0) {
    if (-1 < *(int *)(this + 0x34)) {
      glUniform4fv(*(int *)(this + 0x34),1,param_2 + 0xc0);
    }
    this[9] = (MaskShader)0x0;
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
  piVar2 = *(int **)(**(int **)(param_2 + 0x28) + 0x20);
  if (piVar2 != (int *)0x0) {
    Engine::SetTextureSlot(param_2,piVar2[1],1);
  }
  if (param_1[0x5c] == (Mesh)0x0) {
    if (-1 < *(int *)(this + 0x1c)) {
      glVertexAttribPointer(*(int *)(this + 0x1c),3,0x1406,0,0,*(undefined4 *)(param_1 + 4));
    }
    if (-1 < *(int *)(this + 0x20)) {
      glVertexAttribPointer(*(int *)(this + 0x20),2,0x1406,0,0,*(undefined4 *)(param_1 + 8));
    }
    if (piVar2 == (int *)0x0) {
      return;
    }
    iVar1 = *(int *)(this + 0x24);
    if (iVar1 < 0) {
      return;
    }
    uVar3 = *(undefined4 *)(*piVar2 + 8);
  }
  else {
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x60));
    glVertexAttribPointer(*(undefined4 *)(this + 0x1c),3,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x68));
    glVertexAttribPointer(*(undefined4 *)(this + 0x20),2,0x1406,0,0,0);
    if (piVar2 == (int *)0x0) {
      return;
    }
    glBindBuffer(0x8892,*(undefined4 *)(*piVar2 + 0x68));
    iVar1 = *(int *)(this + 0x24);
    uVar3 = 0;
  }
  glVertexAttribPointer(iVar1,2,0x1406,0,0,uVar3);
  return;
}

