// Class: AbyssEngine::BlurShader
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::BlurShader::BlurShader  @0x000954b0  (120 bytes)
/* AbyssEngine::BlurShader::BlurShader() */

void __thiscall AbyssEngine::BlurShader::BlurShader(BlurShader *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_00263608;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"BlurShader",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  *(undefined4 *)(this + 0x54) = 0x3e2ab368;
  *(undefined4 *)(this + 0x58) = 0x40000000;
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::BlurShader::~BlurShader  @0x0009556c  (30 bytes)
/* AbyssEngine::BlurShader::~BlurShader() */

BlurShader * __thiscall AbyssEngine::BlurShader::~BlurShader(BlurShader *this)

{
  *(undefined ***)this = &PTR___cxa_pure_virtual_00263918;
  String::~String((String *)(this + 0xc));
  return this;
}

// ===== AbyssEngine::BlurShader::Init  @0x00095590  (132 bytes)
/* AbyssEngine::BlurShader::Init(AbyssEngine::Engine*) */

void AbyssEngine::BlurShader::Init(Engine *param_1)

{
  undefined4 uVar1;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position;\nuniform highp mat4 u_WorldMatrix;\nvarying mediump vec2 uv;\nvoid main(void)\n{\n\tgl_Position = vec4((u_WorldMatrix * a_position).xy, 0.0, 1.0 );\n\tgl_Position = sign( gl_Position );\n\t// Texture coordinate for screen aligned (in correct range):\n\tuv = (gl_Position.xy + 1.0) * 0.5;\n}\n"
                     ,
                     "precision lowp float;\nuniform sampler2D s_texture_base;\nuniform lowp vec2 u_radial_origin;   // blur origin\nuniform lowp float u_blur_strength;  // blur strength\nvarying mediump vec2 uv;\nconst lowp float sampleDist = 1.0;\nvoid main(void)\n{\n    mediump vec2 dir = u_radial_origin - uv;\n    float dist = length(dir);\n    dir = dir/dist;\n    mediump vec4 color = texture2D(s_texture_base, uv);\n    mediump vec4 sum = color;\n    float samples[6];\n    samples[0] = -0.03;\n    samples[1] = -0.02;\n    samples[2] = -0.01;\n    samples[3] =  0.01;\n    samples[4] =  0.02;\n    samples[5] =  0.03;\n    for (int i = 0; i < 5; i++)\n\t\tsum += texture2D( s_texture_base, uv + dir * samples[i]);\n\tsum *= 0.1429;\n\tgl_FragColor = mix( color, sum, clamp( dist * u_blur_strength ,0.0,1.0) );\n}\n"
                    );
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  uVar1 = glGetAttribLocation(uVar1,"a_position");
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 0x20),"a_texCoord");
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x20),"u_WorldMatrix");
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x20),"s_texture_base");
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x20),"u_texel_size");
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x20),"u_radial_origin");
  *(undefined4 *)(param_1 + 0x40) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x20),"u_blur_strength");
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 0x20),"u_radial_bright");
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 0x20));
  glUniform1i(*(undefined4 *)(param_1 + 0x30),0);
  return;
}

// ===== AbyssEngine::BlurShader::SetInActive  @0x0009563c  (22 bytes)
/* AbyssEngine::BlurShader::SetInActive() */

void __thiscall AbyssEngine::BlurShader::SetInActive(BlurShader *this)

{
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x44));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x4c));
  return;
}

// ===== AbyssEngine::BlurShader::RenderEffect  @0x00095654  (66 bytes)
/* AbyssEngine::BlurShader::RenderEffect(AbyssEngine::FBOContainer*, AbyssEngine::Engine*, float,
   AbyssEngine::AEMath::Vector) */

void AbyssEngine::BlurShader::RenderEffect
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 local_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_18 = 0;
  (**(code **)(*param_1 + 0x18))(param_1,param_2,&local_18,param_3,param_4,param_5,param_6,param_7);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::BlurShader::RenderEffect  @0x000956a0  (746 bytes)
/* AbyssEngine::BlurShader::RenderEffect(AbyssEngine::FBOContainer*, AbyssEngine::FBOContainer*&,
   AbyssEngine::Engine*, float, AbyssEngine::AEMath::Vector) */

void AbyssEngine::BlurShader::RenderEffect
               (int param_1,FBOContainer *param_2,undefined4 *param_3,Engine *param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  uint in_fpscr;
  float fVar7;
  float fVar8;
  undefined4 extraout_s1;
  undefined4 extraout_s1_00;
  undefined4 extraout_s1_01;
  undefined4 extraout_s1_02;
  undefined4 extraout_s1_03;
  undefined4 extraout_s1_04;
  undefined4 extraout_s1_05;
  undefined4 extraout_s1_06;
  undefined8 uVar9;
  uint extraout_s3;
  uint extraout_s3_00;
  uint extraout_s3_01;
  uint extraout_s3_02;
  uint extraout_s3_03;
  uint extraout_s3_04;
  uint extraout_s3_05;
  uint extraout_s3_06;
  uint uVar10;
  undefined4 uVar11;
  float fVar12;
  undefined4 uVar13;
  undefined4 local_88 [5];
  undefined4 local_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_50;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  int local_3c;
  
  uVar3 = 0;
  uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar11 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar13 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_3c = __stack_chk_guard;
  local_48 = param_6;
  uStack_44 = param_7;
  uStack_40 = param_8;
  *(undefined4 *)(param_4 + 0x3a4) = 0;
  *(undefined4 *)(param_4 + 0x3a8) = uVar2;
  *(undefined4 *)(param_4 + 0x3ac) = uVar11;
  *(undefined4 *)(param_4 + 0x3b0) = uVar13;
  *(undefined4 *)(param_4 + 0x394) = 0;
  *(undefined4 *)(param_4 + 0x398) = uVar2;
  *(undefined4 *)(param_4 + 0x39c) = uVar11;
  *(undefined4 *)(param_4 + 0x3a0) = uVar13;
  *(undefined4 *)(param_4 + 900) = 0;
  *(undefined4 *)(param_4 + 0x388) = uVar2;
  *(undefined4 *)(param_4 + 0x38c) = uVar11;
  *(undefined4 *)(param_4 + 0x390) = uVar13;
  *(undefined4 *)(param_4 + 0x374) = 0;
  *(undefined4 *)(param_4 + 0x378) = uVar2;
  *(undefined4 *)(param_4 + 0x37c) = uVar11;
  *(undefined4 *)(param_4 + 0x380) = uVar13;
  uVar1 = Engine::GetDisplayWidth(param_4);
  fVar7 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
  *(float *)(param_4 + 0x374) = 2.0 / fVar7;
  uVar1 = Engine::GetDisplayHeight(param_4);
  fVar7 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
  *(float *)(param_4 + 0x388) = -(2.0 / fVar7);
  *(undefined4 *)(param_4 + 0x39c) = 0xbd4ccccd;
  *(undefined4 *)(param_4 + 0x3b0) = 0x3f800000;
  *(undefined4 *)(param_4 + 0x3a4) = 0xbf800000;
  *(undefined4 *)(param_4 + 0x3a8) = 0x3f800000;
  puVar5 = (undefined4 *)((uint)local_88 | 4);
  local_88[0] = 0x3f800000;
  *puVar5 = uVar3;
  puVar5[1] = uVar2;
  puVar5[2] = uVar11;
  puVar5[3] = uVar13;
  local_74 = 0x3f800000;
  local_60 = 0x3f800000;
  uStack_58 = 0x3f8000003f800000;
  local_50 = 0x3f800000;
  local_70 = uVar3;
  uStack_6c = uVar2;
  uStack_68 = uVar11;
  uStack_64 = uVar13;
  Engine::SetWorldViewMatrix(param_4,(Matrix *)local_88);
  glDisable(0xb71);
  glDepthMask(0);
  glDisable(0xbe2);
  glUseProgram(*(undefined4 *)(param_1 + 0x20));
  glActiveTexture(0x84c0);
  FBOContainer::Activate(param_2);
  if ((FBOContainer *)*param_3 == (FBOContainer *)0x0) {
    glBindFramebuffer(0x8d40,*(undefined4 *)(param_4 + 0x3fc));
    if (*(int *)(**(int **)(param_4 + 0x28) + 0x30) == 2) {
      uVar3 = Engine::GetDisplayWidth(param_4);
      uVar2 = Engine::GetDisplayHeight(param_4);
    }
    else {
      uVar3 = Engine::GetDisplayHeight(param_4);
      uVar2 = Engine::GetDisplayWidth(param_4);
    }
    glViewport(0,0,uVar3,uVar2);
    uVar10 = extraout_s3_00;
    uVar3 = extraout_s1_00;
  }
  else {
    FBOContainer::BeginCapture((FBOContainer *)*param_3);
    uVar10 = extraout_s3;
    uVar3 = extraout_s1;
  }
  if (-1 < *(int *)(param_1 + 0x24)) {
    glEnableVertexAttribArray();
    uVar10 = extraout_s3_01;
    uVar3 = extraout_s1_01;
  }
  if (-1 < *(int *)(param_1 + 0x2c)) {
    glEnableVertexAttribArray();
    uVar10 = extraout_s3_02;
    uVar3 = extraout_s1_02;
  }
  if (-1 < *(int *)(param_1 + 0x28)) {
    glUniformMatrix4fv(*(int *)(param_1 + 0x28),1,0,param_4 + 0xf4);
    uVar10 = extraout_s3_03;
    uVar3 = extraout_s1_03;
  }
  iVar6 = *(int *)(param_1 + 0x34);
  if (-1 < iVar6) {
    if (*(int *)(**(int **)(param_4 + 0x28) + 0x30) == 2) {
      uVar3 = Engine::GetDisplayWidth(param_4);
      fVar12 = (float)VectorSignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
      fVar7 = 1.0;
      uVar3 = Engine::GetDisplayHeight(param_4);
    }
    else {
      uVar3 = Engine::GetDisplayHeight(param_4);
      fVar7 = 1.0;
      fVar12 = (float)VectorSignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
      uVar3 = Engine::GetDisplayWidth(param_4);
    }
    fVar8 = (float)VectorSignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
    glUniform2f(iVar6,fVar7 / fVar12,fVar7 / fVar8);
    uVar10 = extraout_s3_04;
    uVar3 = extraout_s1_04;
  }
  iVar6 = *(int *)(param_1 + 0x40);
  if (-1 < iVar6) {
    puVar5 = (undefined4 *)AEMath::Vector::operator[]((Vector *)&local_48,0);
    uVar3 = *puVar5;
    puVar5 = (undefined4 *)AEMath::Vector::operator[]((Vector *)&local_48,1);
    glUniform2f(iVar6,uVar3,*puVar5);
    uVar10 = extraout_s3_05;
    uVar3 = extraout_s1_05;
  }
  if (-1 < *(int *)(param_1 + 0x3c)) {
    glUniform1f(*(int *)(param_1 + 0x3c),*(undefined4 *)(param_1 + 0x54));
    uVar10 = extraout_s3_06;
    uVar3 = extraout_s1_06;
  }
  if (-1 < *(int *)(param_1 + 0x38)) {
    uVar9 = FloatVectorMax(CONCAT44(uVar3,param_5),(ulonglong)uVar10 << 0x20,2,0x20);
    glUniform1f(*(int *)(param_1 + 0x38),(float)uVar9 * *(float *)(param_1 + 0x58));
  }
  if (-1 < *(int *)(param_1 + 0x24)) {
    glVertexAttribPointer
              (*(int *)(param_1 + 0x24),3,0x1406,0,0,*(undefined4 *)(*(int *)(param_4 + 0x370) + 4))
    ;
  }
  if (-1 < *(int *)(param_1 + 0x2c)) {
    glVertexAttribPointer
              (*(int *)(param_1 + 0x2c),2,0x1406,0,0,*(undefined4 *)(*(int *)(param_4 + 0x370) + 8))
    ;
  }
  glClear(0x4000);
  iVar6 = Engine::GetDisplayWidth(param_4);
  iVar4 = Engine::GetDisplayHeight(param_4);
  Engine::DrawQuad(param_4,0,0,iVar6,iVar4);
  if (-1 < *(int *)(param_1 + 0x24)) {
    glDisableVertexAttribArray();
  }
  if (-1 < *(int *)(param_1 + 0x2c)) {
    glDisableVertexAttribArray();
  }
  if ((FBOContainer *)*param_3 != (FBOContainer *)0x0) {
    FBOContainer::EndCapture((FBOContainer *)*param_3);
  }
  glEnable(0xbe2);
  glBlendFunc(0x302,0x303);
  glActiveTexture(0x84c0);
  if (__stack_chk_guard != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::BlurShader::UpdateMeshData  @0x000959b0  (312 bytes)
/* AbyssEngine::BlurShader::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::BlurShader::UpdateMeshData(BlurShader *this,Mesh *param_1,Engine *param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint in_fpscr;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  
  if (-1 < *(int *)(this + 0x28)) {
    glUniformMatrix4fv(*(int *)(this + 0x28),1,0,param_2 + 0xf4);
  }
  iVar2 = *(int *)(this + 0x34);
  if (-1 < iVar2) {
    if (*(int *)(**(int **)(param_2 + 0x28) + 0x30) == 2) {
      uVar1 = Engine::GetDisplayWidth(param_2);
      fVar4 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
      uVar1 = Engine::GetDisplayHeight(param_2);
    }
    else {
      uVar1 = Engine::GetDisplayHeight(param_2);
      fVar4 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
      uVar1 = Engine::GetDisplayWidth(param_2);
    }
    fVar3 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
    glUniform2f(iVar2,1.0 / fVar4,1.0 / fVar3);
  }
  if (-1 < *(int *)(this + 0x40)) {
    glUniform2f(*(int *)(this + 0x40),0x3f000000,0x3e99999a);
  }
  if (-1 < *(int *)(this + 0x3c)) {
    glUniform1f(*(int *)(this + 0x3c),*(undefined4 *)(this + 0x54));
  }
  if (-1 < *(int *)(this + 0x38)) {
    glUniform1f(*(int *)(this + 0x38),*(undefined4 *)(this + 0x58));
  }
  if (this[9] != (BlurShader)0x0) {
    this[9] = (BlurShader)0x0;
  }
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x44));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x4c));
  if (param_1[0x5c] == (Mesh)0x0) {
    glVertexAttribPointer(*(undefined4 *)(this + 0x44),3,0x1406,0,0,*(undefined4 *)(param_1 + 4));
    uVar1 = *(undefined4 *)(this + 0x4c);
    uVar5 = *(undefined4 *)(param_1 + 8);
  }
  else {
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x60));
    glVertexAttribPointer(*(undefined4 *)(this + 0x44),3,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x68));
    uVar1 = *(undefined4 *)(this + 0x4c);
    uVar5 = 0;
  }
  glVertexAttribPointer(uVar1,2,0x1406,0,0,uVar5);
  return;
}

