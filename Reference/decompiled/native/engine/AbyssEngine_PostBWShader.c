// Class: AbyssEngine::PostBWShader
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::PostBWShader::PostBWShader  @0x00099c14  (104 bytes)
/* AbyssEngine::PostBWShader::PostBWShader() */

void __thiscall AbyssEngine::PostBWShader::PostBWShader(PostBWShader *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_002639bc;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"PostBWShader",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::PostBWShader::~PostBWShader  @0x00099cc0  (30 bytes)
/* AbyssEngine::PostBWShader::~PostBWShader() */

PostBWShader * __thiscall AbyssEngine::PostBWShader::~PostBWShader(PostBWShader *this)

{
  *(undefined ***)this = &PTR___cxa_pure_virtual_00263918;
  String::~String((String *)(this + 0xc));
  return this;
}

// ===== AbyssEngine::PostBWShader::Init  @0x00099ce4  (84 bytes)
/* AbyssEngine::PostBWShader::Init(AbyssEngine::Engine*) */

void AbyssEngine::PostBWShader::Init(Engine *param_1)

{
  undefined4 uVar1;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position;\nattribute mediump vec2 a_texCoord;\nvarying mediump vec2 v_texCoord;\nuniform highp mat4 u_WorldMatrix;\nvoid main()\n{\n\tgl_Position = u_WorldMatrix * a_position;\n\tv_texCoord = a_texCoord;\n}\n"
                     ,
                     "precision lowp float;\nvarying mediump vec2 v_texCoord;\nuniform sampler2D s_texture_base;\nvoid main()\n{\n\tvec4 textureColor = texture2D( s_texture_base, v_texCoord );\n   float value = (textureColor.r + textureColor.g + textureColor.b) / 3.0; \n   gl_FragColor.r = 0.0; \n   gl_FragColor.g = 0.0; \n   gl_FragColor.b = textureColor.b; \n\tgl_FragColor.a = textureColor.a;\n}\n"
                    );
  *(undefined4 *)(param_1 + 4) = uVar1;
  uVar1 = glGetAttribLocation(uVar1,"a_position");
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_texCoord");
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_WorldMatrix");
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"s_texture_base");
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 4));
  glUniform1i(*(undefined4 *)(param_1 + 0x28),0);
  return;
}

// ===== AbyssEngine::PostBWShader::SetInActive  @0x00099d50  (22 bytes)
/* AbyssEngine::PostBWShader::SetInActive() */

void __thiscall AbyssEngine::PostBWShader::SetInActive(PostBWShader *this)

{
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x1c));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x24));
  return;
}

// ===== AbyssEngine::PostBWShader::RenderEffect  @0x00099d70  (496 bytes)
/* AbyssEngine::PostBWShader::RenderEffect(AbyssEngine::FBOContainer*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::PostBWShader::RenderEffect(PostBWShader *this,FBOContainer *param_1,Engine *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint in_fpscr;
  float fVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 local_70 [5];
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  int local_34;
  
  uVar2 = 0;
  uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar8 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar9 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_34 = __stack_chk_guard;
  *(undefined4 *)(param_2 + 0x3d4) = *(undefined4 *)(this + 4);
  *(undefined4 *)(param_2 + 0x3a4) = 0;
  *(undefined4 *)(param_2 + 0x3a8) = uVar3;
  *(undefined4 *)(param_2 + 0x3ac) = uVar8;
  *(undefined4 *)(param_2 + 0x3b0) = uVar9;
  *(undefined4 *)(param_2 + 0x394) = 0;
  *(undefined4 *)(param_2 + 0x398) = uVar3;
  *(undefined4 *)(param_2 + 0x39c) = uVar8;
  *(undefined4 *)(param_2 + 0x3a0) = uVar9;
  *(undefined4 *)(param_2 + 900) = 0;
  *(undefined4 *)(param_2 + 0x388) = uVar3;
  *(undefined4 *)(param_2 + 0x38c) = uVar8;
  *(undefined4 *)(param_2 + 0x390) = uVar9;
  *(undefined4 *)(param_2 + 0x374) = 0;
  *(undefined4 *)(param_2 + 0x378) = uVar3;
  *(undefined4 *)(param_2 + 0x37c) = uVar8;
  *(undefined4 *)(param_2 + 0x380) = uVar9;
  uVar1 = Engine::GetDisplayWidth(param_2);
  fVar7 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
  *(float *)(param_2 + 0x374) = 2.0 / fVar7;
  uVar1 = Engine::GetDisplayHeight(param_2);
  fVar7 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
  *(float *)(param_2 + 0x388) = -(2.0 / fVar7);
  *(undefined4 *)(param_2 + 0x39c) = 0xbd4ccccd;
  *(undefined4 *)(param_2 + 0x3b0) = 0x3f800000;
  *(undefined4 *)(param_2 + 0x3a4) = 0xbf800000;
  *(undefined4 *)(param_2 + 0x3a8) = 0x3f800000;
  puVar6 = (undefined4 *)((uint)local_70 | 4);
  local_70[0] = 0x3f800000;
  *puVar6 = uVar2;
  puVar6[1] = uVar3;
  puVar6[2] = uVar8;
  puVar6[3] = uVar9;
  local_5c = 0x3f800000;
  local_48 = 0x3f800000;
  uStack_40 = 0x3f8000003f800000;
  local_38 = 0x3f800000;
  local_58 = uVar2;
  uStack_54 = uVar3;
  uStack_50 = uVar8;
  uStack_4c = uVar9;
  Engine::SetWorldViewMatrix(param_2,(Matrix *)local_70);
  glDisable(0xb71);
  glDepthMask(0);
  glDisable(0xbe2);
  glUseProgram(*(undefined4 *)(this + 4));
  glActiveTexture(0x84c0);
  FBOContainer::Activate(param_1);
  glBindFramebuffer(0x8d40,*(undefined4 *)(param_2 + 0x3fc));
  glClear(0x4100);
  if (*(int *)(**(int **)(param_2 + 0x28) + 0x30) == 2) {
    uVar2 = Engine::GetDisplayWidth(param_2);
    uVar3 = Engine::GetDisplayHeight(param_2);
  }
  else {
    uVar2 = Engine::GetDisplayHeight(param_2);
    uVar3 = Engine::GetDisplayWidth(param_2);
  }
  glViewport(0,0,uVar2,uVar3);
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x1c));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x24));
  glUniformMatrix4fv(*(undefined4 *)(this + 0x20),1,0,param_2 + 0xf4);
  glVertexAttribPointer
            (*(undefined4 *)(this + 0x1c),3,0x1406,0,0,
             *(undefined4 *)(*(int *)(param_2 + 0x370) + 4));
  glVertexAttribPointer
            (*(undefined4 *)(this + 0x24),2,0x1406,0,0,
             *(undefined4 *)(*(int *)(param_2 + 0x370) + 8));
  glClear(0x4000);
  iVar4 = Engine::GetDisplayWidth(param_2);
  iVar5 = Engine::GetDisplayHeight(param_2);
  Engine::DrawQuad(param_2,0,0,iVar4,iVar5);
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x1c));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x24));
  glEnable(0xbe2);
  glBlendFunc(0x302,0x303);
  glActiveTexture(0x84c0);
  *(undefined4 *)(param_2 + 0x6c) = 0xffffffff;
  if (__stack_chk_guard != local_34) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PostBWShader::UpdateMeshData  @0x00099f80  (144 bytes)
/* AbyssEngine::PostBWShader::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::PostBWShader::UpdateMeshData(PostBWShader *this,Mesh *param_1,Engine *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  glUniformMatrix4fv(*(undefined4 *)(this + 0x20),1,0,param_2 + 0xf4);
  if (this[9] != (PostBWShader)0x0) {
    this[9] = (PostBWShader)0x0;
  }
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x1c));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x24));
  if (param_1[0x5c] == (Mesh)0x0) {
    glVertexAttribPointer(*(undefined4 *)(this + 0x1c),3,0x1406,0,0,*(undefined4 *)(param_1 + 4));
    uVar1 = *(undefined4 *)(this + 0x24);
    uVar2 = *(undefined4 *)(param_1 + 8);
  }
  else {
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x60));
    glVertexAttribPointer(*(undefined4 *)(this + 0x1c),3,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x68));
    uVar1 = *(undefined4 *)(this + 0x24);
    uVar2 = 0;
  }
  glVertexAttribPointer(uVar1,2,0x1406,0,0,uVar2);
  return;
}

