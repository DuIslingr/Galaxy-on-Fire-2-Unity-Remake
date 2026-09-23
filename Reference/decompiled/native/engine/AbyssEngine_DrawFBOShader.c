// Class: AbyssEngine::DrawFBOShader
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::DrawFBOShader::DrawFBOShader  @0x000933b4  (36 bytes)
/* AbyssEngine::DrawFBOShader::DrawFBOShader() */

void __thiscall AbyssEngine::DrawFBOShader::DrawFBOShader(DrawFBOShader *this)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *puVar1 = &PTR_Init_002634b8;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  return;
}

// ===== AbyssEngine::DrawFBOShader::~DrawFBOShader  @0x000933e4  (30 bytes)
/* AbyssEngine::DrawFBOShader::~DrawFBOShader() */

DrawFBOShader * __thiscall AbyssEngine::DrawFBOShader::~DrawFBOShader(DrawFBOShader *this)

{
  *(undefined ***)this = &PTR___cxa_pure_virtual_00263918;
  String::~String((String *)(this + 0xc));
  return this;
}

// ===== AbyssEngine::DrawFBOShader::Init  @0x00093408  (84 bytes)
/* AbyssEngine::DrawFBOShader::Init(AbyssEngine::Engine*) */

void AbyssEngine::DrawFBOShader::Init(Engine *param_1)

{
  undefined4 uVar1;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position;\nattribute mediump vec2 a_texCoord;\nvarying mediump vec2 v_texCoord;\nuniform highp mat4 u_WorldMatrix;\nvoid main()\n{\n\tgl_Position = u_WorldMatrix * a_position;\n\tv_texCoord = a_texCoord;\n}\n"
                     ,
                     "precision lowp float;\nvarying mediump vec2 v_texCoord;\nuniform sampler2D s_texture_base;\nvoid main(void)\n{\n   gl_FragColor.rgb = texture2D(s_texture_base, v_texCoord).rgb;\n}\n"
                    );
  *(undefined4 *)(param_1 + 4) = uVar1;
  uVar1 = glGetAttribLocation(uVar1,"a_position");
  *(undefined4 *)(param_1 + 0x44) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_texCoord");
  *(undefined4 *)(param_1 + 0x4c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_WorldMatrix");
  *(undefined4 *)(param_1 + 0x48) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"s_texture_base");
  *(undefined4 *)(param_1 + 0x50) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 4));
  glUniform1i(*(undefined4 *)(param_1 + 0x50),0);
  return;
}

// ===== AbyssEngine::DrawFBOShader::SetInActive  @0x00093474  (22 bytes)
/* AbyssEngine::DrawFBOShader::SetInActive() */

void __thiscall AbyssEngine::DrawFBOShader::SetInActive(DrawFBOShader *this)

{
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x44));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x4c));
  return;
}

// ===== AbyssEngine::DrawFBOShader::RenderEffect  @0x00093490  (514 bytes)
/* AbyssEngine::DrawFBOShader::RenderEffect(AbyssEngine::FBOContainer*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::DrawFBOShader::RenderEffect(DrawFBOShader *this,FBOContainer *param_1,Engine *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
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
  
  uVar3 = 0;
  uVar4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar8 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar9 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_34 = __stack_chk_guard;
  *(undefined4 *)(param_2 + 0x3a4) = 0;
  *(undefined4 *)(param_2 + 0x3a8) = uVar4;
  *(undefined4 *)(param_2 + 0x3ac) = uVar8;
  *(undefined4 *)(param_2 + 0x3b0) = uVar9;
  *(undefined4 *)(param_2 + 0x394) = 0;
  *(undefined4 *)(param_2 + 0x398) = uVar4;
  *(undefined4 *)(param_2 + 0x39c) = uVar8;
  *(undefined4 *)(param_2 + 0x3a0) = uVar9;
  *(undefined4 *)(param_2 + 900) = 0;
  *(undefined4 *)(param_2 + 0x388) = uVar4;
  *(undefined4 *)(param_2 + 0x38c) = uVar8;
  *(undefined4 *)(param_2 + 0x390) = uVar9;
  *(undefined4 *)(param_2 + 0x374) = 0;
  *(undefined4 *)(param_2 + 0x378) = uVar4;
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
  *puVar6 = uVar3;
  puVar6[1] = uVar4;
  puVar6[2] = uVar8;
  puVar6[3] = uVar9;
  local_5c = 0x3f800000;
  local_48 = 0x3f800000;
  uStack_40 = 0x3f8000003f800000;
  local_38 = 0x3f800000;
  local_58 = uVar3;
  uStack_54 = uVar4;
  uStack_50 = uVar8;
  uStack_4c = uVar9;
  Engine::SetWorldViewMatrix(param_2,(Matrix *)local_70);
  glDisable(0xb71);
  glDepthMask(0);
  glDisable(0xbe2);
  glUseProgram(*(undefined4 *)(this + 4));
  glActiveTexture(0x84c0);
  FBOContainer::Activate(param_1);
  iVar2 = Engine::IsPostEffectActivated(param_2);
  if (iVar2 == 1) {
    Engine::ActivateRender2FracFBO(param_2);
  }
  else {
    glBindFramebuffer(0x8d40,*(undefined4 *)(param_2 + 0x3fc));
    if (*(int *)(**(int **)(param_2 + 0x28) + 0x30) == 2) {
      uVar3 = Engine::GetDisplayWidth(param_2);
      uVar4 = Engine::GetDisplayHeight(param_2);
    }
    else {
      uVar3 = Engine::GetDisplayHeight(param_2);
      uVar4 = Engine::GetDisplayWidth(param_2);
    }
    glViewport(0,0,uVar3,uVar4);
  }
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x44));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x4c));
  glUniformMatrix4fv(*(undefined4 *)(this + 0x48),1,0,param_2 + 0xf4);
  glVertexAttribPointer
            (*(undefined4 *)(this + 0x44),3,0x1406,0,0,
             *(undefined4 *)(*(int *)(param_2 + 0x370) + 4));
  glVertexAttribPointer
            (*(undefined4 *)(this + 0x4c),2,0x1406,0,0,
             *(undefined4 *)(*(int *)(param_2 + 0x370) + 8));
  glClear(0x4000);
  glClear(0x100);
  iVar2 = Engine::GetDisplayWidth(param_2);
  iVar5 = Engine::GetDisplayHeight(param_2);
  Engine::DrawQuad(param_2,0,0,iVar2,iVar5);
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x44));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x4c));
  glEnable(0xb71);
  glClear(0x100);
  iVar2 = Engine::IsPostEffectActivated(param_2);
  if (iVar2 == 1) {
    Engine::DeactivateRender2FracFBO(param_2);
  }
  glActiveTexture(0x84c0);
  if (__stack_chk_guard != local_34) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::DrawFBOShader::UpdateMeshData  @0x000936c0  (144 bytes)
/* AbyssEngine::DrawFBOShader::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::DrawFBOShader::UpdateMeshData(DrawFBOShader *this,Mesh *param_1,Engine *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  glUniformMatrix4fv(*(undefined4 *)(this + 0x48),1,0,param_2 + 0xf4);
  if (this[9] != (DrawFBOShader)0x0) {
    this[9] = (DrawFBOShader)0x0;
  }
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x44));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x4c));
  if (param_1[0x5c] == (Mesh)0x0) {
    glVertexAttribPointer(*(undefined4 *)(this + 0x44),3,0x1406,0,0,*(undefined4 *)(param_1 + 4));
    uVar1 = *(undefined4 *)(this + 0x4c);
    uVar2 = *(undefined4 *)(param_1 + 8);
  }
  else {
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x60));
    glVertexAttribPointer(*(undefined4 *)(this + 0x44),3,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x68));
    uVar1 = *(undefined4 *)(this + 0x4c);
    uVar2 = 0;
  }
  glVertexAttribPointer(uVar1,2,0x1406,0,0,uVar2);
  return;
}

