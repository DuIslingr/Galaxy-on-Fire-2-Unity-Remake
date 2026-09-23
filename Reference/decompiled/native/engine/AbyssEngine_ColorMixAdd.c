// Class: AbyssEngine::ColorMixAdd
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::ColorMixAdd::ColorMixAdd  @0x0009cd2c  (104 bytes)
/* AbyssEngine::ColorMixAdd::ColorMixAdd() */

void __thiscall AbyssEngine::ColorMixAdd::ColorMixAdd(ColorMixAdd *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_00263ccc;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"ColorMixAdd",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::ColorMixAdd::Init  @0x0009cdd8  (132 bytes)
/* AbyssEngine::ColorMixAdd::Init(AbyssEngine::Engine*) */

void AbyssEngine::ColorMixAdd::Init(Engine *param_1)

{
  undefined4 uVar1;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position;   \nattribute mediump vec2 a_texCoord;   \nvarying mediump vec2 v_texCoord;     \nuniform highp mat4 u_WorldMatrix;  \nuniform highp mat4 u_UvMatrix;  \nuniform bool u_UVAnimation; \nvoid main()                  \n{                            \n   gl_Position = u_WorldMatrix * a_position;\t\t\n   if ( u_UVAnimation ) \n       v_texCoord = (u_UvMatrix*vec4(a_texCoord.x, a_texCoord.y, 0.0, 1.0)).xy;  \n   else \n       v_texCoord = a_texCoord; \n}                            \n"
                     ,
                     "precision lowp float;                            \nvarying mediump vec2 v_texCoord;                            \nuniform sampler2D s_texture;                        \nuniform lowp vec4 glColor;\t\t\t\t\t\t\t\t \nuniform float u_DarkenValue; \nvoid main()                                         \n{                                                   \n\tvec4 textureColor = texture2D( s_texture, v_texCoord );\t\n\tvec3 outColor = glColor.rgb + textureColor.rgb;\t\t\n   gl_FragColor.rgb = outColor; \n   gl_FragColor.a = textureColor.a;\n}   \t\t  \n"
                    );
  *(undefined4 *)(param_1 + 4) = uVar1;
  uVar1 = glGetUniformLocation(uVar1,"s_texture");
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_position");
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_texCoord");
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_WorldMatrix");
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"glColor");
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_DarkenValue");
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_UvMatrix");
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_UVAnimation");
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 4));
  glUniform1i(*(undefined4 *)(param_1 + 0x2c),0);
  return;
}

// ===== AbyssEngine::ColorMixAdd::SetInActive  @0x0009ce84  (26 bytes)
/* AbyssEngine::ColorMixAdd::SetInActive() */

void __thiscall AbyssEngine::ColorMixAdd::SetInActive(ColorMixAdd *this)

{
  int iVar1;
  
  iVar1 = 2;
  do {
    glDisableVertexAttribArray(*(undefined4 *)(this + 0x1c));
    glDisableVertexAttribArray(*(undefined4 *)(this + 0x20));
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

// ===== AbyssEngine::ColorMixAdd::UpdateMeshData  @0x0009ce9e  (224 bytes)
/* AbyssEngine::ColorMixAdd::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::ColorMixAdd::UpdateMeshData(ColorMixAdd *this,Mesh *param_1,Engine *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  glUniformMatrix4fv(*(undefined4 *)(this + 0x24),1,0,param_2 + 0xf4);
  if (-1 < *(int *)(this + 0x30)) {
    glUniformMatrix4fv(*(int *)(this + 0x30),1,0,param_2 + 0x1b4);
  }
  if (-1 < *(int *)(this + 0x38)) {
    glUniform1i(*(int *)(this + 0x38),param_1[0x85]);
  }
  if (this[9] != (ColorMixAdd)0x0) {
    glUniform4fv(*(undefined4 *)(this + 0x28),1,param_2 + 0xc0);
    if (-1 < *(int *)(this + 0x34)) {
      glUniform1f(*(int *)(this + 0x34),1.0 - *(float *)(param_1 + 0x1c));
    }
    this[9] = (ColorMixAdd)0x0;
  }
  if (((byte)*param_1 & 2) != 0) {
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
  }
  return;
}

