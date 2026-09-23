// Class: AbyssEngine::NoTexVtxColorShader
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::NoTexVtxColorShader::NoTexVtxColorShader  @0x00098c9c  (104 bytes)
/* AbyssEngine::NoTexVtxColorShader::NoTexVtxColorShader() */

void __thiscall AbyssEngine::NoTexVtxColorShader::NoTexVtxColorShader(NoTexVtxColorShader *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_002638a8;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"NoTexVtxColorShader",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::NoTexVtxColorShader::Init  @0x00098d48  (76 bytes)
/* AbyssEngine::NoTexVtxColorShader::Init(AbyssEngine::Engine*) */

void AbyssEngine::NoTexVtxColorShader::Init(Engine *param_1)

{
  undefined4 uVar1;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position;   \nattribute mediump vec4 a_VertexColor;   \nvarying mediump vec4 v_VertexColor;     \nuniform highp mat4 u_WorldMatrix;  \nvoid main()                  \n{                            \n   gl_Position = u_WorldMatrix * a_position;\t\t\n   v_VertexColor = a_VertexColor;  \n}                            \n"
                     ,
                     "precision lowp float;                            \nvarying mediump vec4 v_VertexColor;                            \nuniform lowp vec4 glColor;\t\t\t\t\t\t\t\t \nvoid main()                                         \n{                                                   \n\tgl_FragColor = glColor * v_VertexColor;\t\t\n}   \t\t  \n"
                    );
  *(undefined4 *)(param_1 + 4) = uVar1;
  uVar1 = glGetAttribLocation(uVar1,"a_position");
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_VertexColor");
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_WorldMatrix");
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"glColor");
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 4));
  return;
}

// ===== AbyssEngine::NoTexVtxColorShader::SetInActive  @0x00098dac  (22 bytes)
/* AbyssEngine::NoTexVtxColorShader::SetInActive() */

void __thiscall AbyssEngine::NoTexVtxColorShader::SetInActive(NoTexVtxColorShader *this)

{
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x1c));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x20));
  return;
}

// ===== AbyssEngine::NoTexVtxColorShader::UpdateMeshData  @0x00098dc2  (128 bytes)
/* AbyssEngine::NoTexVtxColorShader::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::NoTexVtxColorShader::UpdateMeshData
          (NoTexVtxColorShader *this,Mesh *param_1,Engine *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  glUniformMatrix4fv(*(undefined4 *)(this + 0x24),1,0,param_2 + 0xf4);
  if (this[9] != (NoTexVtxColorShader)0x0) {
    glUniform4fv(*(undefined4 *)(this + 0x28),1,param_2 + 0xc0);
    this[9] = (NoTexVtxColorShader)0x0;
  }
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x1c));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x20));
  uVar1 = *(undefined4 *)(this + 0x1c);
  if (param_1 == (Mesh *)0x0) {
    uVar2 = *(undefined4 *)(param_2 + 0x338);
    uVar3 = 2;
  }
  else {
    glVertexAttribPointer(uVar1,3,0x1406,0,0,*(undefined4 *)(param_1 + 4));
    uVar2 = *(undefined4 *)(param_1 + 0xc);
    uVar1 = *(undefined4 *)(this + 0x20);
    uVar3 = 4;
  }
  glVertexAttribPointer(uVar1,uVar3,0x1406,0,0,uVar2);
  return;
}

