// Class: AbyssEngine::BloomShader
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::BloomShader::BloomShader  @0x000942fc  (104 bytes)
/* AbyssEngine::BloomShader::BloomShader() */

void __thiscall AbyssEngine::BloomShader::BloomShader(BloomShader *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_00263598;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"BloomShader",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::BloomShader::~BloomShader  @0x000943a8  (30 bytes)
/* AbyssEngine::BloomShader::~BloomShader() */

BloomShader * __thiscall AbyssEngine::BloomShader::~BloomShader(BloomShader *this)

{
  *(undefined ***)this = &PTR___cxa_pure_virtual_00263918;
  String::~String((String *)(this + 0xc));
  return this;
}

// ===== AbyssEngine::BloomShader::InternalInit  @0x000943cc  (274 bytes)
/* AbyssEngine::BloomShader::InternalInit(AbyssEngine::Engine*) */

void __thiscall AbyssEngine::BloomShader::InternalInit(BloomShader *this,Engine *param_1)

{
  FBOContainer *pFVar1;
  String aSStack_38 [8];
  String aSStack_30 [8];
  String aSStack_28 [8];
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  pFVar1 = operator_new(0x34);
  String::String(aSStack_20,"BloomShader fboLuma",false);
  FBOContainer::FBOContainer(pFVar1,param_1,aSStack_20);
  *(FBOContainer **)(this + 0x30) = pFVar1;
  String::~String(aSStack_20);
  FBOContainer::Create(*(int *)(this + 0x30),0x100,false,true);
  pFVar1 = operator_new(0x34);
  String::String(aSStack_28,"BloomShader fboBlurH",false);
  FBOContainer::FBOContainer(pFVar1,param_1,aSStack_28);
  *(FBOContainer **)(this + 0x4c) = pFVar1;
  String::~String(aSStack_28);
  FBOContainer::Create(*(int *)(this + 0x4c),0x100,false,true);
  pFVar1 = operator_new(0x34);
  String::String(aSStack_30,"BloomShader fboBlurV",false);
  FBOContainer::FBOContainer(pFVar1,param_1,aSStack_30);
  *(FBOContainer **)(this + 0x68) = pFVar1;
  String::~String(aSStack_30);
  FBOContainer::Create(*(int *)(this + 0x68),0x100,false,true);
  pFVar1 = operator_new(0x34);
  String::String(aSStack_38,"BloomShader fboBlack",false);
  FBOContainer::FBOContainer(pFVar1,param_1,aSStack_38);
  *(FBOContainer **)(this + 0x6c) = pFVar1;
  String::~String(aSStack_38);
  FBOContainer::Create(*(int *)(this + 0x6c),0x100,false,true);
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::BloomShader::Init  @0x00094528  (438 bytes)
/* AbyssEngine::BloomShader::Init(AbyssEngine::Engine*) */

void AbyssEngine::BloomShader::Init(Engine *param_1)

{
  undefined4 uVar1;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position;\nattribute mediump vec2 a_texCoord;\nvarying mediump vec2 v_texCoord;\nuniform highp mat4 u_WorldMatrix;\nvoid main()\n{\n\tgl_Position = u_WorldMatrix * a_position;\n\tv_texCoord = a_texCoord;\n}\n"
                     ,
                     "precision lowp float;\nvarying mediump vec2 v_texCoord;\nuniform sampler2D s_texture_base;\nvoid main()\n{\n\tvec4 textureColor = texture2D( s_texture_base, v_texCoord );\n\tgl_FragColor = textureColor;\n}\n"
                    );
  *(undefined4 *)(param_1 + 4) = uVar1;
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position;\nattribute mediump vec2 a_texCoord;\nvarying mediump vec2 v_texCoord;\nuniform highp mat4 u_WorldMatrix;\nvoid main()\n{\n\tgl_Position = u_WorldMatrix * a_position;\n\tv_texCoord = a_texCoord;\n}\n"
                     ,
                     "precision mediump float;\n//const float Luminance = 0.005; \n//const float fMiddleGray = 0.04;\n//const float fWhiteCutoff = 0.1;\nconst float Luminance = 0.08; \nconst float fMiddleGray = 0.005;\nconst float fWhiteCutoff = 0.014;\nvarying lowp vec2 v_texCoord;\nuniform sampler2D s_texture_base;\nvoid main()\n{\n\tmediump vec3 ColorOut = texture2D( s_texture_base, v_texCoord ).rgb;\n\tColorOut *= fMiddleGray / ( Luminance + 0.001 );\n\tColorOut *= ( 1.0 + ( ColorOut / ( fWhiteCutoff * fWhiteCutoff ) ) );\n\tColorOut -= 5.0;\n\tColorOut = max( ColorOut, 0.0 );\n\tColorOut /= ( 10.0 + ColorOut );\n\tgl_FragColor = vec4( ColorOut, 1.0 );\n}\n"
                    );
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position;\nattribute mediump vec2 a_texCoord;\nvarying mediump vec2 v_texCoord;\nuniform highp mat4 u_WorldMatrix;\nvoid main()\n{\n\tgl_Position = u_WorldMatrix * a_position;\n\tv_texCoord = a_texCoord;\n}\n"
                     ,
                     "precision lowp float;\nvarying lowp vec2 v_texCoord;\nuniform sampler2D s_texture_base;\nuniform mediump float texSize; \nmediump float offset[3];// = float[]( 0.0, 1.3846153846, 3.2307692308 ); \nfloat weight[3];// = float[]( 0.2270270270, 0.3162162162, 0.0702702703 ); \nvoid main()\n{\n\t  offset[0] = 0.0; \n\t  offset[1] = 1.3846153846; \n\t  offset[2] = 3.2307692308; \n\t  weight[0] = 0.2270270270; \n\t  weight[1] = 0.3162162162; \n\t  weight[2] = 0.0702702703; \n\t  mediump vec3 tc = vec3(1.0, 0.0, 0.0);\n\t\tvec2 uv = v_texCoord;\n\t\ttc = texture2D(s_texture_base, uv).rgb * weight[0];\n\t\tfor (int i=1; i<3; i++)\n\t\t{\n\t\t  tc += texture2D(s_texture_base, uv + vec2(offset[i])/texSize, 0.0).rgb * weight[i];\n\t\t  tc += texture2D(s_texture_base, uv - vec2(offset[i])/texSize, 0.0).rgb * weight[i];\n\t\t}\n\t  gl_FragColor = vec4(tc, 1.0);\n}\n"
                    );
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position;\nattribute mediump vec2 a_texCoord;\nvarying mediump vec2 v_texCoord;\nuniform highp mat4 u_WorldMatrix;\nvoid main()\n{\n\tgl_Position = u_WorldMatrix * a_position;\n\tv_texCoord = a_texCoord;\n}\n"
                     ,
                     "precision lowp float;\nvarying mediump vec2 v_texCoord;\nuniform sampler2D s_texture_base;\nuniform mediump float texSize; \nmediump float offset[3];// = float[]( 0.0, 1.3846153846, 3.2307692308 ); \nfloat weight[3];// = float[]( 0.2270270270, 0.3162162162, 0.0702702703 ); \nvoid main()\n{\n\t  offset[0] = 0.0; \n\t  offset[1] = 1.3846153846; \n\t  offset[2] = 3.2307692308; \n\t  weight[0] = 0.2270270270; \n\t  weight[1] = 0.3162162162; \n\t  weight[2] = 0.0702702703; \n\t  mediump vec3 tc = vec3(1.0, 0.0, 0.0);\n\t\tvec2 uv = v_texCoord;\n\t\ttc = texture2D(s_texture_base, uv).rgb * weight[0];\n\t\tfor (int i=1; i<3; i++)\n\t\t{\n\t\t  tc += texture2D(s_texture_base, uv + vec2(0.0, offset[i])/texSize).rgb * weight[i];\n\t\t  tc += texture2D(s_texture_base, uv - vec2(0.0, offset[i])/texSize).rgb * weight[i];\n\t\t}\n\t  gl_FragColor = vec4(tc, 1.0);\n}\n"
                    );
  *(undefined4 *)(param_1 + 0x50) = uVar1;
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position;\nattribute mediump vec2 a_texCoord;\nvarying mediump vec2 v_texCoord;\nuniform highp mat4 u_WorldMatrix;\nvoid main()\n{\n\tgl_Position = u_WorldMatrix * a_position;\n\tv_texCoord = a_texCoord;\n}\n"
                     ,
                     "precision lowp float;\nvarying lowp vec2 v_texCoord;\nuniform sampler2D s_texture_base;\nuniform sampler2D s_texture_bloom;\nvoid main()\n{\n\tvec3 textureColorBase = texture2D( s_texture_base, v_texCoord ).rgb;\n\tvec3 bloomBase = texture2D( s_texture_bloom, v_texCoord ).rgb; \n\tvec3 vFinalGlareColor = clamp(bloomBase + textureColorBase, vec3(0.0), vec3(1.0)); \n\tfloat fLum = dot(textureColorBase, vec3(0.3, 0.59, 0.11)); \n\tgl_FragColor.rgb = clamp( vFinalGlareColor * ( 1.0 - fLum ) + vFinalGlareColor * fLum, vec3(0.0), vec3(1.0) ); \n\t//gl_FragColor.rgb = bloomBase;\n}\n"
                    );
  *(undefined4 *)(param_1 + 0x70) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_position");
  *(undefined4 *)(param_1 + 0x88) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_texCoord");
  *(undefined4 *)(param_1 + 0x90) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_WorldMatrix");
  *(undefined4 *)(param_1 + 0x8c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"s_texture_base");
  *(undefined4 *)(param_1 + 0x94) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 4));
  glUniform1i(*(undefined4 *)(param_1 + 0x94),0);
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
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 0x34),"a_position");
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 0x34),"a_texCoord");
  *(undefined4 *)(param_1 + 0x40) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x34),"u_WorldMatrix");
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x34),"s_texture_base");
  *(undefined4 *)(param_1 + 0x44) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x34),"texSize");
  *(undefined4 *)(param_1 + 0x48) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 0x34));
  glUniform1i(*(undefined4 *)(param_1 + 0x44),0);
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 0x50),"a_position");
  *(undefined4 *)(param_1 + 0x54) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 0x50),"a_texCoord");
  *(undefined4 *)(param_1 + 0x5c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x50),"u_WorldMatrix");
  *(undefined4 *)(param_1 + 0x58) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x50),"s_texture_base");
  *(undefined4 *)(param_1 + 0x60) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x50),"texSize");
  *(undefined4 *)(param_1 + 100) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 0x50));
  glUniform1i(*(undefined4 *)(param_1 + 0x60),0);
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 0x70),"a_position");
  *(undefined4 *)(param_1 + 0x74) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 0x70),"a_texCoord");
  *(undefined4 *)(param_1 + 0x7c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x70),"u_WorldMatrix");
  *(undefined4 *)(param_1 + 0x78) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x70),"s_texture_base");
  *(undefined4 *)(param_1 + 0x80) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x70),"s_texture_bloom");
  *(undefined4 *)(param_1 + 0x84) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 0x70));
  glUniform1i(*(undefined4 *)(param_1 + 0x80),0);
  glUniform1i(*(undefined4 *)(param_1 + 0x84),1);
  return;
}

// ===== AbyssEngine::BloomShader::SetInActive  @0x00094710  (38 bytes)
/* AbyssEngine::BloomShader::SetInActive() */

void __thiscall AbyssEngine::BloomShader::SetInActive(BloomShader *this)

{
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x88));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x90));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x28));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x20));
  return;
}

// ===== AbyssEngine::BloomShader::RenderEffect  @0x00094740  (1122 bytes)
/* AbyssEngine::BloomShader::RenderEffect(AbyssEngine::FBOContainer*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::BloomShader::RenderEffect(BloomShader *this,FBOContainer *param_1,Engine *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  BloomShader *pBVar7;
  FBOContainer *pFVar8;
  Engine *pEVar9;
  uint in_fpscr;
  float fVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
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
  *(undefined4 *)(param_2 + 0x3d4) = *(undefined4 *)(this + 4);
  if (firstRender != '\0') {
    firstRender = '\0';
    InternalInit(this,param_2);
    FBOContainer::BeginCapture(*(FBOContainer **)(this + 0x6c));
    glClearColor(0,0,0,0x3f800000);
    glClear(0x4000);
    FBOContainer::EndCapture(*(FBOContainer **)(this + 0x6c));
  }
  uVar11 = 0;
  uVar5 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar12 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar13 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(param_2 + 0x3a4) = 0;
  *(undefined4 *)(param_2 + 0x3a8) = uVar5;
  *(undefined4 *)(param_2 + 0x3ac) = uVar12;
  *(undefined4 *)(param_2 + 0x3b0) = uVar13;
  *(undefined4 *)(param_2 + 0x394) = 0;
  *(undefined4 *)(param_2 + 0x398) = uVar5;
  *(undefined4 *)(param_2 + 0x39c) = uVar12;
  *(undefined4 *)(param_2 + 0x3a0) = uVar13;
  *(undefined4 *)(param_2 + 900) = 0;
  *(undefined4 *)(param_2 + 0x388) = uVar5;
  *(undefined4 *)(param_2 + 0x38c) = uVar12;
  *(undefined4 *)(param_2 + 0x390) = uVar13;
  *(undefined4 *)(param_2 + 0x374) = 0;
  *(undefined4 *)(param_2 + 0x378) = uVar5;
  *(undefined4 *)(param_2 + 0x37c) = uVar12;
  *(undefined4 *)(param_2 + 0x380) = uVar13;
  uVar1 = Engine::GetDisplayWidth(param_2);
  fVar10 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
  *(float *)(param_2 + 0x374) = 2.0 / fVar10;
  uVar1 = Engine::GetDisplayHeight(param_2);
  fVar10 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
  *(float *)(param_2 + 0x388) = -(2.0 / fVar10);
  *(undefined4 *)(param_2 + 0x39c) = 0xbd4ccccd;
  *(undefined4 *)(param_2 + 0x3b0) = 0x3f800000;
  *(undefined4 *)(param_2 + 0x3a4) = 0xbf800000;
  *(undefined4 *)(param_2 + 0x3a8) = 0x3f800000;
  puVar6 = (undefined4 *)((uint)local_80 | 4);
  local_80[0] = 0x3f800000;
  *puVar6 = uVar11;
  puVar6[1] = uVar5;
  puVar6[2] = uVar12;
  puVar6[3] = uVar13;
  local_6c = 0x3f800000;
  local_58 = 0x3f800000;
  uStack_50 = 0x3f8000003f800000;
  local_48 = 0x3f800000;
  local_68 = uVar11;
  uStack_64 = uVar5;
  uStack_60 = uVar12;
  uStack_5c = uVar13;
  Engine::SetWorldViewMatrix(param_2,(Matrix *)local_80);
  glDisable(0xb71);
  glDepthMask(0);
  glDisable(0xbe2);
  glUseProgram(*(undefined4 *)(this + 0x1c));
  glActiveTexture(0x84c0);
  FBOContainer::Activate(param_1);
  FBOContainer::BeginCapture(*(FBOContainer **)(this + 0x30));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x20));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x28));
  pEVar9 = param_2 + 0xf4;
  glUniformMatrix4fv(*(undefined4 *)(this + 0x24),1,0,pEVar9);
  glVertexAttribPointer
            (*(undefined4 *)(this + 0x20),3,0x1406,0,0,
             *(undefined4 *)(*(int *)(param_2 + 0x370) + 4));
  glVertexAttribPointer
            (*(undefined4 *)(this + 0x28),2,0x1406,0,0,
             *(undefined4 *)(*(int *)(param_2 + 0x370) + 8));
  glClear(0x4000);
  iVar2 = Engine::GetDisplayWidth(param_2);
  iVar3 = Engine::GetDisplayHeight(param_2);
  Engine::DrawQuad(param_2,0,0,iVar2,iVar3);
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x20));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x28));
  iVar2 = 6;
  pBVar7 = this + 0x30;
  do {
    pFVar8 = *(FBOContainer **)pBVar7;
    glUseProgram(*(undefined4 *)(this + 0x34));
    glActiveTexture(0x84c0);
    FBOContainer::Activate(pFVar8);
    FBOContainer::BeginCapture(*(FBOContainer **)(this + 0x4c));
    glEnableVertexAttribArray(*(undefined4 *)(this + 0x38));
    glEnableVertexAttribArray(*(undefined4 *)(this + 0x40));
    glUniformMatrix4fv(*(undefined4 *)(this + 0x3c),1,0,pEVar9);
    glVertexAttribPointer
              (*(undefined4 *)(this + 0x38),3,0x1406,0,0,
               *(undefined4 *)(*(int *)(param_2 + 0x370) + 4));
    glVertexAttribPointer
              (*(undefined4 *)(this + 0x40),2,0x1406,0,0,
               *(undefined4 *)(*(int *)(param_2 + 0x370) + 8));
    uVar11 = VectorSignedToFloat(*(undefined4 *)(*(int *)(this + 0x4c) + 0xc),
                                 (byte)(in_fpscr >> 0x16) & 3);
    glUniform1f(*(undefined4 *)(this + 0x48),uVar11);
    glClear(0x4000);
    iVar3 = Engine::GetDisplayWidth(param_2);
    iVar4 = Engine::GetDisplayHeight(param_2);
    Engine::DrawQuad(param_2,0,0,iVar3,iVar4);
    glDisableVertexAttribArray(*(undefined4 *)(this + 0x38));
    glDisableVertexAttribArray(*(undefined4 *)(this + 0x40));
    glUseProgram(*(undefined4 *)(this + 0x50));
    glActiveTexture(0x84c0);
    FBOContainer::Activate(*(FBOContainer **)(this + 0x4c));
    FBOContainer::BeginCapture(*(FBOContainer **)(this + 0x68));
    glEnableVertexAttribArray(*(undefined4 *)(this + 0x54));
    glEnableVertexAttribArray(*(undefined4 *)(this + 0x5c));
    glUniformMatrix4fv(*(undefined4 *)(this + 0x58),1,0,pEVar9);
    glVertexAttribPointer
              (*(undefined4 *)(this + 0x54),3,0x1406,0,0,
               *(undefined4 *)(*(int *)(param_2 + 0x370) + 4));
    glVertexAttribPointer
              (*(undefined4 *)(this + 0x5c),2,0x1406,0,0,
               *(undefined4 *)(*(int *)(param_2 + 0x370) + 8));
    uVar11 = VectorSignedToFloat(*(undefined4 *)(*(int *)(this + 0x68) + 0x10),
                                 (byte)(in_fpscr >> 0x16) & 3);
    glUniform1f(*(undefined4 *)(this + 100),uVar11);
    glClear(0x4000);
    iVar3 = Engine::GetDisplayWidth(param_2);
    iVar4 = Engine::GetDisplayHeight(param_2);
    Engine::DrawQuad(param_2,0,0,iVar3,iVar4);
    glDisableVertexAttribArray(*(undefined4 *)(this + 0x54));
    glDisableVertexAttribArray(*(undefined4 *)(this + 0x5c));
    iVar2 = iVar2 + -1;
    pBVar7 = this + 0x68;
  } while (iVar2 != 0);
  pFVar8 = (FBOContainer *)0x0;
  switch(Engine::switchBloom) {
  case 0:
    break;
  case 1:
    param_1 = *(FBOContainer **)(this + 0x30);
    break;
  case 2:
    param_1 = *(FBOContainer **)(this + 0x68);
    break;
  case 3:
    pFVar8 = *(FBOContainer **)(this + 0x68);
  default:
    goto switchD_00094a78_default;
  }
  pFVar8 = *(FBOContainer **)(this + 0x6c);
switchD_00094a78_default:
  glUseProgram(*(undefined4 *)(this + 0x70));
  glActiveTexture(0x84c0);
  FBOContainer::Activate(param_1);
  glActiveTexture(0x84c1);
  FBOContainer::Activate(pFVar8);
  glBindFramebuffer(0x8d40,*(undefined4 *)(param_2 + 0x3fc));
  if (*(int *)(**(int **)(param_2 + 0x28) + 0x30) == 2) {
    uVar11 = Engine::GetDisplayWidth(param_2);
    uVar5 = Engine::GetDisplayHeight(param_2);
  }
  else {
    uVar11 = Engine::GetDisplayHeight(param_2);
    uVar5 = Engine::GetDisplayWidth(param_2);
  }
  glViewport(0,0,uVar11,uVar5);
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x74));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x7c));
  glUniformMatrix4fv(*(undefined4 *)(this + 0x78),1,0,pEVar9);
  glVertexAttribPointer
            (*(undefined4 *)(this + 0x74),3,0x1406,0,0,
             *(undefined4 *)(*(int *)(param_2 + 0x370) + 4));
  glVertexAttribPointer
            (*(undefined4 *)(this + 0x7c),2,0x1406,0,0,
             *(undefined4 *)(*(int *)(param_2 + 0x370) + 8));
  glClear(0x4000);
  iVar2 = Engine::GetDisplayWidth(param_2);
  iVar3 = Engine::GetDisplayHeight(param_2);
  Engine::DrawQuad(param_2,0,0,iVar2,iVar3);
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x74));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x7c));
  glEnable(0xbe2);
  glBlendFunc(0x302,0x303);
  glActiveTexture(0x84c0);
  if (__stack_chk_guard == local_44) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::BloomShader::RenderEffect  @0x00094be0  (1076 bytes)
/* AbyssEngine::BloomShader::RenderEffect(AbyssEngine::FBOContainer*, AbyssEngine::FBOContainer*&,
   AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::BloomShader::RenderEffect
          (BloomShader *this,FBOContainer *param_1,FBOContainer **param_2,Engine *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  FBOContainer *pFVar6;
  BloomShader *pBVar7;
  Engine *pEVar8;
  uint in_fpscr;
  float fVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
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
  if (firstRender != '\0') {
    firstRender = '\0';
    InternalInit(this,param_3);
    FBOContainer::BeginCapture(*(FBOContainer **)(this + 0x6c));
    glClearColor(0,0,0,0x3f800000);
    glClear(0x4000);
    FBOContainer::EndCapture(*(FBOContainer **)(this + 0x6c));
  }
  uVar10 = 0;
  uVar11 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar12 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar13 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(param_3 + 0x3a4) = 0;
  *(undefined4 *)(param_3 + 0x3a8) = uVar11;
  *(undefined4 *)(param_3 + 0x3ac) = uVar12;
  *(undefined4 *)(param_3 + 0x3b0) = uVar13;
  *(undefined4 *)(param_3 + 0x394) = 0;
  *(undefined4 *)(param_3 + 0x398) = uVar11;
  *(undefined4 *)(param_3 + 0x39c) = uVar12;
  *(undefined4 *)(param_3 + 0x3a0) = uVar13;
  *(undefined4 *)(param_3 + 900) = 0;
  *(undefined4 *)(param_3 + 0x388) = uVar11;
  *(undefined4 *)(param_3 + 0x38c) = uVar12;
  *(undefined4 *)(param_3 + 0x390) = uVar13;
  *(undefined4 *)(param_3 + 0x374) = 0;
  *(undefined4 *)(param_3 + 0x378) = uVar11;
  *(undefined4 *)(param_3 + 0x37c) = uVar12;
  *(undefined4 *)(param_3 + 0x380) = uVar13;
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
  puVar5 = (undefined4 *)((uint)local_80 | 4);
  local_80[0] = 0x3f800000;
  *puVar5 = uVar10;
  puVar5[1] = uVar11;
  puVar5[2] = uVar12;
  puVar5[3] = uVar13;
  local_6c = 0x3f800000;
  local_58 = 0x3f800000;
  uStack_50 = 0x3f8000003f800000;
  local_48 = 0x3f800000;
  local_68 = uVar10;
  uStack_64 = uVar11;
  uStack_60 = uVar12;
  uStack_5c = uVar13;
  Engine::SetWorldViewMatrix(param_3,(Matrix *)local_80);
  glDisable(0xb71);
  glDepthMask(0);
  glDisable(0xbe2);
  glUseProgram(*(undefined4 *)(this + 0x1c));
  glActiveTexture(0x84c0);
  FBOContainer::Activate(param_1);
  FBOContainer::BeginCapture(*(FBOContainer **)(this + 0x30));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x20));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x28));
  pEVar8 = param_3 + 0xf4;
  glUniformMatrix4fv(*(undefined4 *)(this + 0x24),1,0,pEVar8);
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
  iVar2 = 6;
  pBVar7 = this + 0x30;
  do {
    pFVar6 = *(FBOContainer **)pBVar7;
    glUseProgram(*(undefined4 *)(this + 0x34));
    glActiveTexture(0x84c0);
    FBOContainer::Activate(pFVar6);
    FBOContainer::BeginCapture(*(FBOContainer **)(this + 0x4c));
    glEnableVertexAttribArray(*(undefined4 *)(this + 0x38));
    glEnableVertexAttribArray(*(undefined4 *)(this + 0x40));
    glUniformMatrix4fv(*(undefined4 *)(this + 0x3c),1,0,pEVar8);
    glVertexAttribPointer
              (*(undefined4 *)(this + 0x38),3,0x1406,0,0,
               *(undefined4 *)(*(int *)(param_3 + 0x370) + 4));
    glVertexAttribPointer
              (*(undefined4 *)(this + 0x40),2,0x1406,0,0,
               *(undefined4 *)(*(int *)(param_3 + 0x370) + 8));
    uVar10 = VectorSignedToFloat(*(undefined4 *)(*(int *)(this + 0x4c) + 0xc),
                                 (byte)(in_fpscr >> 0x16) & 3);
    glUniform1f(*(undefined4 *)(this + 0x48),uVar10);
    glClear(0x4000);
    iVar3 = Engine::GetDisplayWidth(param_3);
    iVar4 = Engine::GetDisplayHeight(param_3);
    Engine::DrawQuad(param_3,0,0,iVar3,iVar4);
    glDisableVertexAttribArray(*(undefined4 *)(this + 0x38));
    glDisableVertexAttribArray(*(undefined4 *)(this + 0x40));
    glUseProgram(*(undefined4 *)(this + 0x50));
    glActiveTexture(0x84c0);
    FBOContainer::Activate(*(FBOContainer **)(this + 0x4c));
    FBOContainer::BeginCapture(*(FBOContainer **)(this + 0x68));
    glEnableVertexAttribArray(*(undefined4 *)(this + 0x54));
    glEnableVertexAttribArray(*(undefined4 *)(this + 0x5c));
    glUniformMatrix4fv(*(undefined4 *)(this + 0x58),1,0,pEVar8);
    glVertexAttribPointer
              (*(undefined4 *)(this + 0x54),3,0x1406,0,0,
               *(undefined4 *)(*(int *)(param_3 + 0x370) + 4));
    glVertexAttribPointer
              (*(undefined4 *)(this + 0x5c),2,0x1406,0,0,
               *(undefined4 *)(*(int *)(param_3 + 0x370) + 8));
    uVar10 = VectorSignedToFloat(*(undefined4 *)(*(int *)(this + 0x68) + 0x10),
                                 (byte)(in_fpscr >> 0x16) & 3);
    glUniform1f(*(undefined4 *)(this + 100),uVar10);
    glClear(0x4000);
    pFVar6 = (FBOContainer *)Engine::GetDisplayWidth(param_3);
    iVar3 = Engine::GetDisplayHeight(param_3);
    Engine::DrawQuad(param_3,0,0,(int)pFVar6,iVar3);
    glDisableVertexAttribArray(*(undefined4 *)(this + 0x54));
    glDisableVertexAttribArray(*(undefined4 *)(this + 0x5c));
    iVar2 = iVar2 + -1;
    pBVar7 = this + 0x68;
  } while (iVar2 != 0);
  switch(Engine::switchBloom) {
  case 0:
    break;
  case 1:
    param_1 = *(FBOContainer **)(this + 0x30);
    break;
  case 2:
    param_1 = *(FBOContainer **)(this + 0x68);
    break;
  case 3:
    pFVar6 = *(FBOContainer **)(this + 0x68);
  default:
    goto switchD_00094f1a_default;
  }
  pFVar6 = *(FBOContainer **)(this + 0x6c);
switchD_00094f1a_default:
  glUseProgram(*(undefined4 *)(this + 0x70));
  glActiveTexture(0x84c0);
  FBOContainer::Activate(param_1);
  glActiveTexture(0x84c1);
  FBOContainer::Activate(pFVar6);
  if (*param_2 != (FBOContainer *)0x0) {
    FBOContainer::BeginCapture(*param_2);
  }
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x74));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x7c));
  glUniformMatrix4fv(*(undefined4 *)(this + 0x78),1,0,pEVar8);
  glVertexAttribPointer
            (*(undefined4 *)(this + 0x74),3,0x1406,0,0,
             *(undefined4 *)(*(int *)(param_3 + 0x370) + 4));
  glVertexAttribPointer
            (*(undefined4 *)(this + 0x7c),2,0x1406,0,0,
             *(undefined4 *)(*(int *)(param_3 + 0x370) + 8));
  glClear(0x4000);
  iVar2 = Engine::GetDisplayWidth(param_3);
  iVar3 = Engine::GetDisplayHeight(param_3);
  Engine::DrawQuad(param_3,0,0,iVar2,iVar3);
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x74));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x7c));
  glEnable(0xbe2);
  glBlendFunc(0x302,0x303);
  glActiveTexture(0x84c0);
  if (*param_2 != (FBOContainer *)0x0) {
    FBOContainer::EndCapture(*param_2);
  }
  if (__stack_chk_guard == local_44) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::BloomShader::UpdateMeshData  @0x00095050  (158 bytes)
/* AbyssEngine::BloomShader::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::BloomShader::UpdateMeshData(BloomShader *this,Mesh *param_1,Engine *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  glUniformMatrix4fv(*(undefined4 *)(this + 0x8c),1,0,param_2 + 0xf4);
  if (this[9] != (BloomShader)0x0) {
    this[9] = (BloomShader)0x0;
  }
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x88));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x90));
  if (param_1[0x5c] == (Mesh)0x0) {
    glVertexAttribPointer(*(undefined4 *)(this + 0x88),3,0x1406,0,0,*(undefined4 *)(param_1 + 4));
    uVar1 = *(undefined4 *)(this + 0x90);
    uVar2 = *(undefined4 *)(param_1 + 8);
  }
  else {
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x60));
    glVertexAttribPointer(*(undefined4 *)(this + 0x88),3,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x68));
    uVar1 = *(undefined4 *)(this + 0x90);
    uVar2 = 0;
  }
  glVertexAttribPointer(uVar1,2,0x1406,0,0,uVar2);
  return;
}

