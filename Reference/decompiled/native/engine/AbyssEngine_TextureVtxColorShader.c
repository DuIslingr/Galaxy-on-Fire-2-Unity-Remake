// Class: AbyssEngine::TextureVtxColorShader
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::TextureVtxColorShader::TextureVtxColorShader  @0x00096b8c  (104 bytes)
/* AbyssEngine::TextureVtxColorShader::TextureVtxColorShader() */

void __thiscall
AbyssEngine::TextureVtxColorShader::TextureVtxColorShader(TextureVtxColorShader *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_00263720;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"TextureVtxColorShader",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::TextureVtxColorShader::UseShader  @0x00096c38  (26 bytes)
/* AbyssEngine::TextureVtxColorShader::UseShader(bool) */

void AbyssEngine::TextureVtxColorShader::UseShader(bool param_1)

{
  int iVar1;
  
  if ((Engine::fogEnabled == '\0') || (iVar1 = *(int *)(param_1 + 0x1c), iVar1 == 0)) {
    iVar1 = *(int *)(param_1 + 4);
  }
  glUseProgram(iVar1);
  return;
}

// ===== AbyssEngine::TextureVtxColorShader::ConnectShaderComponents  @0x00096c58  (208 bytes)
/* AbyssEngine::TextureVtxColorShader::ConnectShaderComponents(unsigned int, int) */

void __thiscall
AbyssEngine::TextureVtxColorShader::ConnectShaderComponents
          (TextureVtxColorShader *this,uint param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = glGetUniformLocation(param_1,"s_texture");
  *(undefined4 *)(this + param_2 * 4 + 0x48) = uVar1;
  uVar1 = glGetAttribLocation(param_1,"a_position");
  *(undefined4 *)(this + param_2 * 4 + 0x20) = uVar1;
  uVar1 = glGetAttribLocation(param_1,"a_texCoord");
  *(undefined4 *)(this + param_2 * 4 + 0x28) = uVar1;
  uVar1 = glGetAttribLocation(param_1,"a_VertexColor");
  *(undefined4 *)(this + param_2 * 4 + 0x30) = uVar1;
  uVar1 = glGetUniformLocation(param_1,"u_WorldMatrix");
  *(undefined4 *)(this + param_2 * 4 + 0x38) = uVar1;
  uVar1 = glGetUniformLocation(param_1,"glColor");
  *(undefined4 *)(this + param_2 * 4 + 0x40) = uVar1;
  uVar1 = glGetUniformLocation(param_1,"u_DarkenValue");
  *(undefined4 *)(this + param_2 * 4 + 0x88) = uVar1;
  uVar1 = glGetUniformLocation(param_1,"u_fogColor");
  *(undefined4 *)(this + param_2 * 4 + 0x60) = uVar1;
  uVar1 = glGetUniformLocation(param_1,"u_fogMaxDist");
  *(undefined4 *)(this + param_2 * 4 + 0x68) = uVar1;
  uVar1 = glGetUniformLocation(param_1,"u_fogMinDist");
  *(undefined4 *)(this + param_2 * 4 + 0x70) = uVar1;
  uVar1 = glGetUniformLocation(param_1,"u_EnableFog");
  *(undefined4 *)(this + param_2 * 4 + 0x78) = uVar1;
  uVar1 = glGetUniformLocation(param_1,"u_eyeposmodel");
  *(undefined4 *)(this + param_2 * 4 + 0x80) = uVar1;
  uVar1 = glGetUniformLocation(param_1,"u_UVAnimation");
  *(undefined4 *)(this + param_2 * 4 + 0x50) = uVar1;
  uVar1 = glGetUniformLocation(param_1,"u_UvMatrix");
  *(undefined4 *)(this + param_2 * 4 + 0x58) = uVar1;
  glUseProgram(param_1);
  glUniform1i(*(undefined4 *)(this + param_2 * 4 + 0x48),0);
  return;
}

// ===== AbyssEngine::TextureVtxColorShader::Init  @0x00096d60  (62 bytes)
/* AbyssEngine::TextureVtxColorShader::Init(AbyssEngine::Engine*) */

void AbyssEngine::TextureVtxColorShader::Init(Engine *param_1)

{
  uint uVar1;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position;   \nattribute mediump vec2 a_texCoord;   \nattribute mediump vec4 a_VertexColor;   \nvarying mediump vec4 v_VertexColor;     \nvarying mediump vec2 v_texCoord;     \nuniform highp mat4 u_WorldMatrix;  \nuniform highp mat4 u_UvMatrix;  \nuniform highp float u_fogMaxDist; \nuniform highp float u_fogMinDist;\nvarying lowp float v_FogFactor;\nuniform highp vec3 u_eyeposmodel;  \nuniform bool u_EnableFog; \nuniform bool u_UVAnimation; \nlowp float computeLinearFogFactor(highp float eyeDist) { \n    highp float factor; \n    // Compute linear fog equation \n    factor = (u_fogMaxDist - eyeDist) / (u_fogMaxDist - u_fogMinDist);\n    // Clamp in the [0,1] range \n    factor = (1.0 - clamp(factor, 0.0, 1.0));\n    return factor; \n}    \nvoid main()                  \n{                            \n   gl_Position = u_WorldMatrix * a_position;\t\t\n   if ( u_UVAnimation ) \n       v_texCoord = (u_UvMatrix*vec4(a_texCoord.x, a_texCoord.y, 0.0, 1.0)).xy;  \n   else \n       v_texCoord = a_texCoord; \n   v_VertexColor = a_VertexColor;  \n    if ( u_EnableFog ) { \n       highp float eyeDist = distance(u_eyeposmodel, a_position.xyz); \n       v_FogFactor = computeLinearFogFactor(eyeDist); \n    } else { \n       v_FogFactor = 1.0; \n    } \n}                            \n"
                     ,
                     "precision lowp float;                            \nvarying mediump vec2 v_texCoord;                            \nvarying mediump vec4 v_VertexColor;     \nuniform sampler2D s_texture;                        \nuniform lowp vec4 glColor;\t\t\t\t\t\t\t\t \nuniform bool u_EnableFog; \nuniform vec3 u_fogColor; \nuniform float u_DarkenValue; \nvarying lowp float v_FogFactor;\nvoid main()                                         \n{                                                   \n\tvec4 textureColor = texture2D( s_texture, v_texCoord );\t\n\tgl_FragColor = v_VertexColor * textureColor;\t\t\n}   \n"
                    );
  *(uint *)(param_1 + 4) = uVar1;
  ConnectShaderComponents((TextureVtxColorShader *)param_1,uVar1,0);
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position;   \nattribute mediump vec2 a_texCoord;   \nattribute mediump vec4 a_VertexColor;   \nvarying mediump vec4 v_VertexColor;     \nvarying mediump vec2 v_texCoord;     \nuniform highp mat4 u_WorldMatrix;  \nuniform highp mat4 u_UvMatrix;  \nuniform highp float u_fogMaxDist; \nuniform highp float u_fogMinDist;\nvarying lowp float v_FogFactor;\nuniform highp vec3 u_eyeposmodel;  \nuniform bool u_EnableFog; \nuniform bool u_UVAnimation; \nlowp float computeLinearFogFactor(highp float eyeDist) { \n    highp float factor; \n    // Compute linear fog equation \n    factor = (u_fogMaxDist - eyeDist) / (u_fogMaxDist - u_fogMinDist);\n    // Clamp in the [0,1] range \n    factor = (1.0 - clamp(factor, 0.0, 1.0));\n    return factor; \n}    \nvoid main()                  \n{                            \n   gl_Position = u_WorldMatrix * a_position;\t\t\n   if ( u_UVAnimation ) \n       v_texCoord = (u_UvMatrix*vec4(a_texCoord.x, a_texCoord.y, 0.0, 1.0)).xy;  \n   else \n       v_texCoord = a_texCoord; \n   v_VertexColor = a_VertexColor;  \n    if ( u_EnableFog ) { \n       highp float eyeDist = distance(u_eyeposmodel, a_position.xyz); \n       v_FogFactor = computeLinearFogFactor(eyeDist); \n    } else { \n       v_FogFactor = 1.0; \n    } \n}                            \n"
                     ,
                     "precision lowp float;                            \nvarying mediump vec2 v_texCoord;                            \nvarying mediump vec4 v_VertexColor;     \nuniform sampler2D s_texture;                        \nuniform lowp vec4 glColor;\t\t\t\t\t\t\t\t \nuniform bool u_EnableFog; \nuniform vec3 u_fogColor; \nuniform float u_DarkenValue; \nvarying lowp float v_FogFactor;\nvoid main()                                         \n{                                                   \n\tvec4 textureColor = texture2D( s_texture, v_texCoord );\t\n\tvec4 outColor = v_VertexColor * textureColor;\t\t\n   gl_FragColor.rgb = v_VertexColor.rgb*mix(outColor.rgb, u_fogColor, v_FogFactor); \n   gl_FragColor.a = outColor.a;\n}   \n"
                    );
  *(uint *)(param_1 + 0x1c) = uVar1;
  ConnectShaderComponents((TextureVtxColorShader *)param_1,uVar1,1);
  return;
}

// ===== AbyssEngine::TextureVtxColorShader::SetInActive  @0x00096da8  (42 bytes)
/* AbyssEngine::TextureVtxColorShader::SetInActive() */

void __thiscall AbyssEngine::TextureVtxColorShader::SetInActive(TextureVtxColorShader *this)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    glDisableVertexAttribArray(*(undefined4 *)(this + iVar1 * 4 + 0x20));
    glDisableVertexAttribArray(*(undefined4 *)(this + iVar1 * 4 + 0x28));
    glDisableVertexAttribArray(*(undefined4 *)(this + iVar1 * 4 + 0x30));
    iVar1 = iVar1 + 1;
  } while (iVar1 != 2);
  return;
}

// ===== AbyssEngine::TextureVtxColorShader::UpdateMeshData  @0x00096dd4  (402 bytes)
/* AbyssEngine::TextureVtxColorShader::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::TextureVtxColorShader::UpdateMeshData
          (TextureVtxColorShader *this,Mesh *param_1,Engine *param_2)

{
  TextureVtxColorShader *pTVar1;
  TextureVtxColorShader *pTVar2;
  TextureVtxColorShader *pTVar3;
  byte bVar4;
  float *pfVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  
  bVar4 = Engine::fogEnabled;
  glUniformMatrix4fv(*(undefined4 *)(this + (uint)Engine::fogEnabled * 4 + 0x38),1,0,param_2 + 0xf4)
  ;
  if (-1 < *(int *)(this + (uint)bVar4 * 4 + 0x58)) {
    glUniformMatrix4fv(*(int *)(this + (uint)bVar4 * 4 + 0x58),1,0,param_2 + 0x1b4);
  }
  if (-1 < *(int *)(this + (uint)bVar4 * 4 + 0x88)) {
    glUniform1f(*(int *)(this + (uint)bVar4 * 4 + 0x88),1.0 - *(float *)(param_1 + 0x1c));
  }
  if (this[9] != (TextureVtxColorShader)0x0) {
    glUniform4fv(*(undefined4 *)(this + (uint)bVar4 * 4 + 0x40),1,param_2 + 0xc0);
    if (-1 < *(int *)(this + (uint)bVar4 * 4 + 0x50)) {
      glUniform1i(*(int *)(this + (uint)bVar4 * 4 + 0x50),param_1[0x85]);
    }
    iVar7 = *(int *)(this + (uint)bVar4 * 4 + 0x60);
    if (-1 < iVar7) {
      pfVar5 = AEMath::Vector::operator_cast_to_float_((Vector *)(param_2 + 0x3e0));
      glUniform3fv(iVar7,1,pfVar5);
    }
    if (-1 < *(int *)(this + (uint)bVar4 * 4 + 0x70)) {
      glUniform1f(*(int *)(this + (uint)bVar4 * 4 + 0x70),*(undefined4 *)(param_2 + 0x3d8));
    }
    if (-1 < *(int *)(this + (uint)bVar4 * 4 + 0x68)) {
      glUniform1f(*(int *)(this + (uint)bVar4 * 4 + 0x68),*(undefined4 *)(param_2 + 0x3dc));
    }
    if (-1 < *(int *)(this + (uint)bVar4 * 4 + 0x78)) {
      glUniform1i(*(int *)(this + (uint)bVar4 * 4 + 0x78),Engine::fogEnabled);
    }
    if (-1 < *(int *)(this + (uint)bVar4 * 4 + 0x80)) {
      glUniform3f(*(int *)(this + (uint)bVar4 * 4 + 0x80),*(undefined4 *)(param_2 + 0x33c),
                  *(undefined4 *)(param_2 + 0x340),*(undefined4 *)(param_2 + 0x344));
    }
    this[9] = (TextureVtxColorShader)0x0;
  }
  pTVar1 = this + (uint)bVar4 * 4 + 0x20;
  glEnableVertexAttribArray(*(undefined4 *)pTVar1);
  pTVar2 = this + (uint)bVar4 * 4 + 0x28;
  glEnableVertexAttribArray(*(undefined4 *)pTVar2);
  pTVar3 = this + (uint)bVar4 * 4 + 0x30;
  glEnableVertexAttribArray(*(undefined4 *)pTVar3);
  if (param_1[0x5c] == (Mesh)0x0) {
    glVertexAttribPointer(*(undefined4 *)pTVar1,3,0x1406,0,0,*(undefined4 *)(param_1 + 4));
    glVertexAttribPointer(*(undefined4 *)pTVar2,2,0x1406,0,0,*(undefined4 *)(param_1 + 8));
    uVar6 = *(undefined4 *)pTVar3;
    uVar8 = *(undefined4 *)(param_1 + 0xc);
  }
  else {
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x60));
    glVertexAttribPointer(*(undefined4 *)pTVar1,3,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x68));
    glVertexAttribPointer(*(undefined4 *)pTVar2,2,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x78));
    uVar6 = *(undefined4 *)pTVar3;
    uVar8 = 0;
  }
  glVertexAttribPointer(uVar6,4,0x1406,0,0,uVar8);
  return;
}

