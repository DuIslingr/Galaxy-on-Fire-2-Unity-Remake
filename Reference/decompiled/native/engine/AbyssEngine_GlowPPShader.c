// Class: AbyssEngine::GlowPPShader
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::GlowPPShader::GlowPPShader  @0x00097b18  (104 bytes)
/* AbyssEngine::GlowPPShader::GlowPPShader() */

void __thiscall AbyssEngine::GlowPPShader::GlowPPShader(GlowPPShader *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_00263800;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"GlowPPShader",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::GlowPPShader::~GlowPPShader  @0x00097bc4  (30 bytes)
/* AbyssEngine::GlowPPShader::~GlowPPShader() */

GlowPPShader * __thiscall AbyssEngine::GlowPPShader::~GlowPPShader(GlowPPShader *this)

{
  *(undefined ***)this = &PTR___cxa_pure_virtual_00263918;
  String::~String((String *)(this + 0xc));
  return this;
}

// ===== AbyssEngine::GlowPPShader::InternalInit  @0x00097be8  (278 bytes)
/* AbyssEngine::GlowPPShader::InternalInit(AbyssEngine::Engine*) */

void __thiscall AbyssEngine::GlowPPShader::InternalInit(GlowPPShader *this,Engine *param_1)

{
  FBOContainer *pFVar1;
  String aSStack_38 [8];
  String aSStack_30 [8];
  String aSStack_28 [8];
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  pFVar1 = operator_new(0x34);
  String::String(aSStack_20,"GlowPPShader fboMasked",false);
  FBOContainer::FBOContainer(pFVar1,param_1,aSStack_20);
  *(FBOContainer **)(this + 0x38) = pFVar1;
  String::~String(aSStack_20);
  FBOContainer::Create(*(int *)(this + 0x38),0x200,false,true);
  pFVar1 = operator_new(0x34);
  String::String(aSStack_28,"GlowPPShader fboBlurH",false);
  FBOContainer::FBOContainer(pFVar1,param_1,aSStack_28);
  *(FBOContainer **)(this + 0x54) = pFVar1;
  String::~String(aSStack_28);
  FBOContainer::Create(*(int *)(this + 0x54),0x200,false,true);
  pFVar1 = operator_new(0x34);
  String::String(aSStack_30,"GlowPPShader fboBlurV",false);
  FBOContainer::FBOContainer(pFVar1,param_1,aSStack_30);
  *(FBOContainer **)(this + 0x70) = pFVar1;
  String::~String(aSStack_30);
  FBOContainer::Create(*(int *)(this + 0x70),0x200,false,true);
  pFVar1 = operator_new(0x34);
  String::String(aSStack_38,"GlowPPShader fboBlack",false);
  FBOContainer::FBOContainer(pFVar1,param_1,aSStack_38);
  *(FBOContainer **)(this + 0x9c) = pFVar1;
  String::~String(aSStack_38);
  FBOContainer::Create(*(int *)(this + 0x9c),0x200,false,true);
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::GlowPPShader::Init  @0x00097d48  (190 bytes)
/* AbyssEngine::GlowPPShader::Init(AbyssEngine::Engine*) */

void AbyssEngine::GlowPPShader::Init(Engine *param_1)

{
  undefined4 uVar1;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position;\nattribute mediump vec2 a_texCoord;\nvarying lowp vec2 v_texCoord;\nuniform highp mat4 u_WorldMatrix;\nvoid main()\n{\n\tgl_Position = u_WorldMatrix * a_position;\n\tv_texCoord = a_texCoord;\n}\n"
                     ,
                     "precision lowp float;\nvarying lowp vec2 v_texCoord;\nuniform sampler2D s_texture_base;\nvoid main(void)\n{\n   gl_FragColor.rgb = texture2D(s_texture_base, v_texCoord).rgb * texture2D(s_texture_base, v_texCoord).a;\n}\n"
                    );
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position;\nattribute mediump vec2 a_texCoord;\nvarying lowp vec2 v_texCoord;\nuniform highp mat4 u_WorldMatrix;\nvoid main()\n{\n\tgl_Position = u_WorldMatrix * a_position;\n\tv_texCoord = a_texCoord;\n}\n"
                     ,
                     "precision lowp float;\nvarying lowp vec2 v_texCoord;\nuniform sampler2D s_texture_base;\nuniform float texSize; \nmediump float offset[3];// = float[]( 0.0, 1.3846153846, 3.2307692308 ); \nfloat weight[3];\nvoid main()\n{\n\toffset[0] = 0.0; \n\toffset[1] = 1.3846153846; \n\toffset[2] = 3.2307692308; \n\tweight[0] = 0.6; //0.5 \n\tweight[1] = 0.2; \n\tweight[2] = 0.05; \n\tvec2 uv = v_texCoord;\n\tmediump vec3 tc = texture2D(s_texture_base, uv).rgb * weight[0];\n\tfor (int i=1; i<3; i++) {\n\t\ttc += texture2D(s_texture_base, uv + vec2(offset[i] * texSize, 0.0)).rgb * weight[i];\n\t\ttc += texture2D(s_texture_base, uv - vec2(offset[i] * texSize, 0.0)).rgb * weight[i];\n\t}\n\tgl_FragColor = vec4(tc, 1.0);\n}\n"
                    );
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position;\nattribute mediump vec2 a_texCoord;\nvarying lowp vec2 v_texCoord;\nuniform highp mat4 u_WorldMatrix;\nvoid main()\n{\n\tgl_Position = u_WorldMatrix * a_position;\n\tv_texCoord = a_texCoord;\n}\n"
                     ,
                     "precision lowp float;\nvarying lowp vec2 v_texCoord;\nuniform sampler2D s_texture_base;\nuniform float texSize; \nmediump float offset[3];// = float[]( 0.0, 1.3846153846, 3.2307692308 ); \nfloat weight[3];\nvoid main()\n{\n\toffset[0] = 0.0; \n\toffset[1] = 1.3846153846; \n\toffset[2] = 3.2307692308; \n\tweight[0] = 0.6; //0.5 \n\tweight[1] = 0.2; \n\tweight[2] = 0.05; \n\tvec2 uv = v_texCoord;\n\tmediump vec3 tc = texture2D(s_texture_base, uv).rgb * weight[0];\n\tfor (int i=1; i<3; i++) {\n\t\ttc += texture2D(s_texture_base, uv + vec2(0.0, offset[i] * texSize)).rgb * weight[i];\n\t\ttc += texture2D(s_texture_base, uv - vec2(0.0, offset[i] * texSize)).rgb * weight[i];\n\t}\n\tgl_FragColor = vec4(tc, 1.0);\n}\n"
                    );
  *(undefined4 *)(param_1 + 0x58) = uVar1;
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position;\nattribute mediump vec2 a_texCoord;\nvarying lowp vec2 v_texCoord;\nuniform highp mat4 u_WorldMatrix;\nvoid main()\n{\n\tgl_Position = u_WorldMatrix * a_position;\n\tv_texCoord = a_texCoord;\n}\n"
                     ,
                     "precision lowp float;\nvarying lowp vec2 v_texCoord;\nuniform sampler2D s_texture_base;\nuniform sampler2D s_texture_glow;\nvoid main(void)\n{\n\tvec2 TexCoord = v_texCoord;\n\tgl_FragColor.rgb = texture2D(s_texture_base, v_texCoord).rgb + texture2D(s_texture_glow, v_texCoord).rgb;\n}\n"
                    );
  *(undefined4 *)(param_1 + 0x74) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 0x1c),"a_position");
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 0x1c),"a_texCoord");
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x1c),"u_WorldMatrix");
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x1c),"s_texture_base");
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 0x1c));
  glUniform1i(*(undefined4 *)(param_1 + 0x2c),0);
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 0x3c),"a_position");
  *(undefined4 *)(param_1 + 0x40) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 0x3c),"a_texCoord");
  *(undefined4 *)(param_1 + 0x48) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x3c),"u_WorldMatrix");
  *(undefined4 *)(param_1 + 0x44) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x3c),"s_texture_base");
  *(undefined4 *)(param_1 + 0x4c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x3c),"texSize");
  *(undefined4 *)(param_1 + 0x50) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 0x3c));
  glUniform1i(*(undefined4 *)(param_1 + 0x4c),0);
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 0x58),"a_position");
  *(undefined4 *)(param_1 + 0x5c) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 0x58),"a_texCoord");
  *(undefined4 *)(param_1 + 100) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x58),"u_WorldMatrix");
  *(undefined4 *)(param_1 + 0x60) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x58),"s_texture_base");
  *(undefined4 *)(param_1 + 0x68) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x58),"texSize");
  *(undefined4 *)(param_1 + 0x6c) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 0x58));
  glUniform1i(*(undefined4 *)(param_1 + 0x68),0);
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 0x74),"a_position");
  *(undefined4 *)(param_1 + 0x78) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 0x74),"a_texCoord");
  *(undefined4 *)(param_1 + 0x80) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x74),"u_WorldMatrix");
  *(undefined4 *)(param_1 + 0x7c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x74),"s_texture_base");
  *(undefined4 *)(param_1 + 0x84) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x74),"s_texture_glow");
  *(undefined4 *)(param_1 + 0x88) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 0x74));
  glUniform1i(*(undefined4 *)(param_1 + 0x84),0);
  glUniform1i(*(undefined4 *)(param_1 + 0x88),1);
  return;
}

// ===== AbyssEngine::GlowPPShader::SetInActive  @0x00097ee0  (26 bytes)
/* AbyssEngine::GlowPPShader::SetInActive() */

void __thiscall AbyssEngine::GlowPPShader::SetInActive(GlowPPShader *this)

{
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x8c));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x94));
  return;
}

// ===== AbyssEngine::GlowPPShader::RenderEffect  @0x00097efc  (54 bytes)
/* AbyssEngine::GlowPPShader::RenderEffect(AbyssEngine::FBOContainer*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::GlowPPShader::RenderEffect(GlowPPShader *this,FBOContainer *param_1,Engine *param_2)

{
  undefined4 local_10;
  int local_c;
  
  local_c = __stack_chk_guard;
  local_10 = 0;
  (**(code **)(*(int *)this + 0x14))(this,param_1,&local_10,param_2);
  if (__stack_chk_guard != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::GlowPPShader::RenderEffect  @0x00097f40  (1160 bytes)
/* AbyssEngine::GlowPPShader::RenderEffect(AbyssEngine::FBOContainer*, AbyssEngine::FBOContainer*&,
   AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::GlowPPShader::RenderEffect
          (GlowPPShader *this,FBOContainer *param_1,FBOContainer **param_2,Engine *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  FBOContainer *this_00;
  int iVar7;
  Engine *pEVar8;
  uint in_fpscr;
  float fVar9;
  float fVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 local_80 [5];
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  int local_44;
  
  local_44 = __stack_chk_guard;
  if (firstRenderGlow != '\0') {
    firstRenderGlow = '\0';
    InternalInit(this,param_3);
    FBOContainer::BeginCapture(*(FBOContainer **)(this + 0x9c));
    glClearColor(0,0,0,0x3f800000);
    glClear(0x4000);
    FBOContainer::EndCapture(*(FBOContainer **)(this + 0x9c));
  }
  uVar4 = 0;
  uVar5 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar11 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar12 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(param_3 + 0x3a4) = 0;
  *(undefined4 *)(param_3 + 0x3a8) = uVar5;
  *(undefined4 *)(param_3 + 0x3ac) = uVar11;
  *(undefined4 *)(param_3 + 0x3b0) = uVar12;
  *(undefined4 *)(param_3 + 0x394) = 0;
  *(undefined4 *)(param_3 + 0x398) = uVar5;
  *(undefined4 *)(param_3 + 0x39c) = uVar11;
  *(undefined4 *)(param_3 + 0x3a0) = uVar12;
  *(undefined4 *)(param_3 + 900) = 0;
  *(undefined4 *)(param_3 + 0x388) = uVar5;
  *(undefined4 *)(param_3 + 0x38c) = uVar11;
  *(undefined4 *)(param_3 + 0x390) = uVar12;
  *(undefined4 *)(param_3 + 0x374) = 0;
  *(undefined4 *)(param_3 + 0x378) = uVar5;
  *(undefined4 *)(param_3 + 0x37c) = uVar11;
  *(undefined4 *)(param_3 + 0x380) = uVar12;
  uVar1 = Engine::GetDisplayWidth(param_3);
  fVar9 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
  *(float *)(param_3 + 0x374) = 2.0 / fVar9;
  uVar1 = Engine::GetDisplayHeight(param_3);
  fVar9 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
  *(float *)(param_3 + 0x388) = -(2.0 / fVar9);
  *(undefined4 *)(param_3 + 0x39c) = 0xbd4ccccd;
  *(undefined4 *)(param_3 + 0x3b0) = 0x3f800000;
  *(undefined4 *)(param_3 + 0x3a4) = 0xbf800000;
  *(undefined4 *)(param_3 + 0x3a8) = 0x3f800000;
  puVar6 = (undefined4 *)((uint)local_80 | 4);
  local_80[0] = 0x3f800000;
  *puVar6 = uVar4;
  puVar6[1] = uVar5;
  puVar6[2] = uVar11;
  puVar6[3] = uVar12;
  local_6c = 0x3f800000;
  local_58 = 0x3f800000;
  uStack_50 = 0x3f8000003f800000;
  local_48 = 0x3f800000;
  local_68 = uVar4;
  uStack_64 = uVar5;
  uStack_60 = uVar11;
  uStack_5c = uVar12;
  Engine::SetWorldViewMatrix(param_3,(Matrix *)local_80);
  glDisable(0xb71);
  glDepthMask(0);
  glDisable(0xbe2);
  glUseProgram(*(undefined4 *)(this + 0x1c));
  glActiveTexture(0x84c0);
  FBOContainer::Activate(param_1);
  FBOContainer::BeginCapture(*(FBOContainer **)(this + 0x38));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x20));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x28));
  pEVar8 = param_3 + 0xf4;
  glUniformMatrix4fv(*(undefined4 *)(this + 0x24),1,0,pEVar8);
  iVar7 = 3;
  glVertexAttribPointer
            (*(undefined4 *)(this + 0x20),3,0x1406,0,0,
             *(undefined4 *)(*(int *)(param_3 + 0x370) + 4));
  glVertexAttribPointer
            (*(undefined4 *)(this + 0x28),2,0x1406,0,0,
             *(undefined4 *)(*(int *)(param_3 + 0x370) + 8));
  glClear(0x4000);
  iVar2 = Engine::GetDisplayWidth(param_3);
  iVar3 = Engine::GetDisplayHeight(param_3);
  Engine::DrawQuad(param_3,0,0,iVar2,iVar3);
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x20));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x28));
  fVar9 = 1.0;
  this_00 = *(FBOContainer **)(this + 0x38);
  do {
    glUseProgram(*(undefined4 *)(this + 0x3c));
    glActiveTexture(0x84c0);
    FBOContainer::Activate(this_00);
    FBOContainer::BeginCapture(*(FBOContainer **)(this + 0x54));
    glEnableVertexAttribArray(*(undefined4 *)(this + 0x40));
    glEnableVertexAttribArray(*(undefined4 *)(this + 0x48));
    glUniformMatrix4fv(*(undefined4 *)(this + 0x44),1,0,pEVar8);
    glVertexAttribPointer
              (*(undefined4 *)(this + 0x40),3,0x1406,0,0,
               *(undefined4 *)(*(int *)(param_3 + 0x370) + 4));
    glVertexAttribPointer
              (*(undefined4 *)(this + 0x48),2,0x1406,0,0,
               *(undefined4 *)(*(int *)(param_3 + 0x370) + 8));
    fVar10 = (float)VectorSignedToFloat(*(undefined4 *)(*(int *)(this + 0x54) + 0xc),
                                        (byte)(in_fpscr >> 0x16) & 3);
    glUniform1f(*(undefined4 *)(this + 0x50),fVar9 / fVar10);
    glClear(0x4000);
    iVar2 = Engine::GetDisplayWidth(param_3);
    iVar3 = Engine::GetDisplayHeight(param_3);
    Engine::DrawQuad(param_3,0,0,iVar2,iVar3);
    glDisableVertexAttribArray(*(undefined4 *)(this + 0x40));
    glDisableVertexAttribArray(*(undefined4 *)(this + 0x48));
    glUseProgram(*(undefined4 *)(this + 0x58));
    glActiveTexture(0x84c0);
    FBOContainer::Activate(*(FBOContainer **)(this + 0x54));
    FBOContainer::BeginCapture(*(FBOContainer **)(this + 0x70));
    glEnableVertexAttribArray(*(undefined4 *)(this + 0x5c));
    glEnableVertexAttribArray(*(undefined4 *)(this + 100));
    glUniformMatrix4fv(*(undefined4 *)(this + 0x60),1,0,pEVar8);
    glVertexAttribPointer
              (*(undefined4 *)(this + 0x5c),3,0x1406,0,0,
               *(undefined4 *)(*(int *)(param_3 + 0x370) + 4));
    glVertexAttribPointer
              (*(undefined4 *)(this + 100),2,0x1406,0,0,
               *(undefined4 *)(*(int *)(param_3 + 0x370) + 8));
    fVar10 = (float)VectorSignedToFloat(*(undefined4 *)(*(int *)(this + 0x70) + 0x10),
                                        (byte)(in_fpscr >> 0x16) & 3);
    glUniform1f(*(undefined4 *)(this + 0x6c),fVar9 / fVar10);
    glClear(0x4000);
    iVar2 = Engine::GetDisplayWidth(param_3);
    iVar3 = Engine::GetDisplayHeight(param_3);
    Engine::DrawQuad(param_3,0,0,iVar2,iVar3);
    glDisableVertexAttribArray(*(undefined4 *)(this + 0x5c));
    glDisableVertexAttribArray(*(undefined4 *)(this + 100));
    this_00 = *(FBOContainer **)(this + 0x70);
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  if (Engine::switchGlow == 0) {
    this_00 = *(FBOContainer **)(this + 0x9c);
  }
  else if (Engine::switchGlow == 1) {
    param_1 = *(FBOContainer **)(this + 0x38);
    this_00 = *(FBOContainer **)(this + 0x9c);
  }
  else if (Engine::switchGlow == 2) {
    param_1 = this_00;
    this_00 = *(FBOContainer **)(this + 0x9c);
  }
  glUseProgram(*(undefined4 *)(this + 0x74));
  glActiveTexture(0x84c0);
  FBOContainer::Activate(param_1);
  glActiveTexture(0x84c1);
  FBOContainer::Activate(this_00);
  if (*param_2 == (FBOContainer *)0x0) {
    glBindFramebuffer(0x8d40,*(undefined4 *)(param_3 + 0x3fc));
    if (*(int *)(**(int **)(param_3 + 0x28) + 0x30) == 2) {
      uVar4 = Engine::GetDisplayWidth(param_3);
      uVar5 = Engine::GetDisplayHeight(param_3);
    }
    else {
      uVar4 = Engine::GetDisplayHeight(param_3);
      uVar5 = Engine::GetDisplayWidth(param_3);
    }
    glViewport(0,0,uVar4,uVar5);
  }
  else {
    FBOContainer::BeginCapture(*param_2);
  }
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x78));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x80));
  glUniformMatrix4fv(*(undefined4 *)(this + 0x7c),1,0,pEVar8);
  glVertexAttribPointer
            (*(undefined4 *)(this + 0x78),3,0x1406,0,0,
             *(undefined4 *)(*(int *)(param_3 + 0x370) + 4));
  glVertexAttribPointer
            (*(undefined4 *)(this + 0x80),2,0x1406,0,0,
             *(undefined4 *)(*(int *)(param_3 + 0x370) + 8));
  glClear(0x4000);
  iVar2 = Engine::GetDisplayWidth(param_3);
  iVar3 = Engine::GetDisplayHeight(param_3);
  Engine::DrawQuad(param_3,0,0,iVar2,iVar3);
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x78));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x80));
  if (*param_2 != (FBOContainer *)0x0) {
    FBOContainer::EndCapture(*param_2);
  }
  glEnable(0xbe2);
  glBlendFunc(0x302,0x303);
  glActiveTexture(0x84c0);
  if (__stack_chk_guard == local_44) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::GlowPPShader::UpdateMeshData  @0x00098400  (156 bytes)
/* AbyssEngine::GlowPPShader::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::GlowPPShader::UpdateMeshData(GlowPPShader *this,Mesh *param_1,Engine *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  glUniformMatrix4fv(*(undefined4 *)(this + 0x7c),1,0,param_2 + 0xf4);
  if (this[9] != (GlowPPShader)0x0) {
    this[9] = (GlowPPShader)0x0;
  }
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x8c));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x94));
  if (param_1[0x5c] == (Mesh)0x0) {
    glVertexAttribPointer(*(undefined4 *)(this + 0x8c),3,0x1406,0,0,*(undefined4 *)(param_1 + 4));
    uVar1 = *(undefined4 *)(this + 0x94);
    uVar2 = *(undefined4 *)(param_1 + 8);
  }
  else {
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x60));
    glVertexAttribPointer(*(undefined4 *)(this + 0x8c),3,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x68));
    uVar1 = *(undefined4 *)(this + 0x94);
    uVar2 = 0;
  }
  glVertexAttribPointer(uVar1,2,0x1406,0,0,uVar2);
  return;
}

