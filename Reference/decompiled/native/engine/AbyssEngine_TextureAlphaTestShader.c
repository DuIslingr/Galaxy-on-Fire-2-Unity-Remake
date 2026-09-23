// Class: AbyssEngine::TextureAlphaTestShader
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::TextureAlphaTestShader::TextureAlphaTestShader  @0x00093fd4  (104 bytes)
/* AbyssEngine::TextureAlphaTestShader::TextureAlphaTestShader() */

void __thiscall
AbyssEngine::TextureAlphaTestShader::TextureAlphaTestShader(TextureAlphaTestShader *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_00263560;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"TextureAlphaTestShader",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::TextureAlphaTestShader::UseShader  @0x00094080  (26 bytes)
/* AbyssEngine::TextureAlphaTestShader::UseShader(bool) */

void AbyssEngine::TextureAlphaTestShader::UseShader(bool param_1)

{
  int iVar1;
  
  if ((Engine::fogEnabled == '\0') || (iVar1 = *(int *)(param_1 + 0x1c), iVar1 == 0)) {
    iVar1 = *(int *)(param_1 + 4);
  }
  glUseProgram(iVar1);
  return;
}

// ===== AbyssEngine::TextureAlphaTestShader::ConnectShaderComponents  @0x000940a0  (156 bytes)
/* AbyssEngine::TextureAlphaTestShader::ConnectShaderComponents(unsigned int, int) */

void __thiscall
AbyssEngine::TextureAlphaTestShader::ConnectShaderComponents
          (TextureAlphaTestShader *this,uint param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = glGetUniformLocation(param_1,"s_texture");
  *(undefined4 *)(this + param_2 * 4 + 0x40) = uVar1;
  uVar1 = glGetAttribLocation(param_1,"a_position");
  *(undefined4 *)(this + param_2 * 4 + 0x20) = uVar1;
  uVar1 = glGetAttribLocation(param_1,"a_texCoord");
  *(undefined4 *)(this + param_2 * 4 + 0x28) = uVar1;
  uVar1 = glGetUniformLocation(param_1,"u_WorldMatrix");
  *(undefined4 *)(this + param_2 * 4 + 0x30) = uVar1;
  uVar1 = glGetUniformLocation(param_1,"glColor");
  *(undefined4 *)(this + param_2 * 4 + 0x38) = uVar1;
  uVar1 = glGetUniformLocation(param_1,"u_fogColor");
  *(undefined4 *)(this + param_2 * 4 + 0x48) = uVar1;
  uVar1 = glGetUniformLocation(param_1,"u_fogMaxDist");
  *(undefined4 *)(this + param_2 * 4 + 0x50) = uVar1;
  uVar1 = glGetUniformLocation(param_1,"u_fogMinDist");
  *(undefined4 *)(this + param_2 * 4 + 0x58) = uVar1;
  uVar1 = glGetUniformLocation(param_1,"u_EnableFog");
  *(undefined4 *)(this + param_2 * 4 + 0x60) = uVar1;
  uVar1 = glGetUniformLocation(param_1,"u_eyeposmodel");
  *(undefined4 *)(this + param_2 * 4 + 0x68) = uVar1;
  glUseProgram(param_1);
  glUniform1i(*(undefined4 *)(this + param_2 * 4 + 0x40),0);
  return;
}

// ===== AbyssEngine::TextureAlphaTestShader::Init  @0x00094164  (62 bytes)
/* AbyssEngine::TextureAlphaTestShader::Init(AbyssEngine::Engine*) */

void AbyssEngine::TextureAlphaTestShader::Init(Engine *param_1)

{
  uint uVar1;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position;   \nattribute mediump vec2 a_texCoord;   \nvarying mediump vec2 v_texCoord;     \nuniform highp mat4 u_WorldMatrix;  \nuniform highp float u_fogMaxDist; \nuniform highp float u_fogMinDist;\nvarying lowp float v_FogFactor;\nuniform highp vec3 u_eyeposmodel;  \nuniform bool u_EnableFog; \nlowp float computeLinearFogFactor(highp float eyeDist) { \n    highp float factor; \n    // Compute linear fog equation \n    factor = (u_fogMaxDist - eyeDist) / (u_fogMaxDist - u_fogMinDist);\n    // Clamp in the [0,1] range \n    factor = (1.0 - clamp(factor, 0.0, 1.0));\n    return factor; \n}    \nvoid main()                  \n{                            \n   gl_Position = u_WorldMatrix * a_position;\t\t\n   v_texCoord = a_texCoord;  \n    if ( u_EnableFog ) { \n       highp float eyeDist = distance(u_eyeposmodel, a_position.xyz); \n       v_FogFactor = computeLinearFogFactor(eyeDist); \n    } else { \n       v_FogFactor = 1.0; \n    } \n}                            \n"
                     ,
                     "precision lowp float;                            \nvarying mediump vec2 v_texCoord;                            \nuniform sampler2D s_texture;                        \nuniform lowp vec4 glColor;\t\t\t\t\t\t\t\t \nvoid main()                                         \n{                                                   \n\t\tvec4 textureColor = texture2D( s_texture, v_texCoord );\t\n\t\tif ( textureColor.a < 0.5)\t\n\t\t\tdiscard;\t\n\t\tgl_FragColor = glColor * textureColor;\t\t\n}   \t\t  \n"
                    );
  *(uint *)(param_1 + 4) = uVar1;
  ConnectShaderComponents((TextureAlphaTestShader *)param_1,uVar1,0);
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position;   \nattribute mediump vec2 a_texCoord;   \nvarying mediump vec2 v_texCoord;     \nuniform highp mat4 u_WorldMatrix;  \nuniform highp float u_fogMaxDist; \nuniform highp float u_fogMinDist;\nvarying lowp float v_FogFactor;\nuniform highp vec3 u_eyeposmodel;  \nuniform bool u_EnableFog; \nlowp float computeLinearFogFactor(highp float eyeDist) { \n    highp float factor; \n    // Compute linear fog equation \n    factor = (u_fogMaxDist - eyeDist) / (u_fogMaxDist - u_fogMinDist);\n    // Clamp in the [0,1] range \n    factor = (1.0 - clamp(factor, 0.0, 1.0));\n    return factor; \n}    \nvoid main()                  \n{                            \n   gl_Position = u_WorldMatrix * a_position;\t\t\n   v_texCoord = a_texCoord;  \n    if ( u_EnableFog ) { \n       highp float eyeDist = distance(u_eyeposmodel, a_position.xyz); \n       v_FogFactor = computeLinearFogFactor(eyeDist); \n    } else { \n       v_FogFactor = 1.0; \n    } \n}                            \n"
                     ,
                     "precision lowp float;                            \nvarying mediump vec2 v_texCoord;                            \nuniform sampler2D s_texture;                        \nuniform lowp vec4 glColor;\t\t\t\t\t\t\t\t \nuniform vec3 u_fogColor; \nvarying lowp float v_FogFactor;\nvoid main()                                         \n{                                                   \n\t\tvec4 textureColor = texture2D( s_texture, v_texCoord );\t\n\t\tif ( textureColor.a < 0.5)\t\n\t\t\tdiscard;\t\n       vec4 outColor = glColor * textureColor;\t\t\n       gl_FragColor.rgb = mix(outColor.rgb, u_fogColor, v_FogFactor); \n\t\tgl_FragColor.a = outColor.a;\t\t\n}   \t\t  \n"
                    );
  *(uint *)(param_1 + 0x1c) = uVar1;
  ConnectShaderComponents((TextureAlphaTestShader *)param_1,uVar1,1);
  return;
}

// ===== AbyssEngine::TextureAlphaTestShader::SetInActive  @0x000941ac  (36 bytes)
/* AbyssEngine::TextureAlphaTestShader::SetInActive() */

void __thiscall AbyssEngine::TextureAlphaTestShader::SetInActive(TextureAlphaTestShader *this)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    glDisableVertexAttribArray(*(undefined4 *)(this + iVar1 * 4 + 0x20));
    glDisableVertexAttribArray(*(undefined4 *)(this + iVar1 * 4 + 0x28));
    iVar1 = iVar1 + 1;
  } while (iVar1 != 2);
  return;
}

// ===== AbyssEngine::TextureAlphaTestShader::UpdateMeshData  @0x000941d0  (292 bytes)
/* AbyssEngine::TextureAlphaTestShader::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::TextureAlphaTestShader::UpdateMeshData
          (TextureAlphaTestShader *this,Mesh *param_1,Engine *param_2)

{
  TextureAlphaTestShader *pTVar1;
  TextureAlphaTestShader *pTVar2;
  byte bVar3;
  float *pfVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  
  bVar3 = Engine::fogEnabled;
  glUniformMatrix4fv(*(undefined4 *)(this + (uint)Engine::fogEnabled * 4 + 0x30),1,0,param_2 + 0xf4)
  ;
  if (this[9] != (TextureAlphaTestShader)0x0) {
    if (-1 < *(int *)(this + (uint)bVar3 * 4 + 0x38)) {
      glUniform4fv(*(int *)(this + (uint)bVar3 * 4 + 0x38),1,param_2 + 0xc0);
    }
    iVar6 = *(int *)(this + (uint)bVar3 * 4 + 0x48);
    if (-1 < iVar6) {
      pfVar4 = AEMath::Vector::operator_cast_to_float_((Vector *)(param_2 + 0x3e0));
      glUniform3fv(iVar6,1,pfVar4);
    }
    if (-1 < *(int *)(this + (uint)bVar3 * 4 + 0x58)) {
      glUniform1f(*(int *)(this + (uint)bVar3 * 4 + 0x58),*(undefined4 *)(param_2 + 0x3d8));
    }
    if (-1 < *(int *)(this + (uint)bVar3 * 4 + 0x50)) {
      glUniform1f(*(int *)(this + (uint)bVar3 * 4 + 0x50),*(undefined4 *)(param_2 + 0x3dc));
    }
    if (-1 < *(int *)(this + (uint)bVar3 * 4 + 0x60)) {
      glUniform1i(*(int *)(this + (uint)bVar3 * 4 + 0x60),Engine::fogEnabled);
    }
    if (-1 < *(int *)(this + (uint)bVar3 * 4 + 0x68)) {
      glUniform3f(*(int *)(this + (uint)bVar3 * 4 + 0x68),*(undefined4 *)(param_2 + 0x33c),
                  *(undefined4 *)(param_2 + 0x340),*(undefined4 *)(param_2 + 0x344));
    }
    this[9] = (TextureAlphaTestShader)0x0;
  }
  if (((byte)*param_1 & 2) != 0) {
    pTVar1 = this + (uint)bVar3 * 4 + 0x20;
    glEnableVertexAttribArray(*(undefined4 *)pTVar1);
    pTVar2 = this + (uint)bVar3 * 4 + 0x28;
    glEnableVertexAttribArray(*(undefined4 *)pTVar2);
    if (param_1[0x5c] == (Mesh)0x0) {
      glVertexAttribPointer(*(undefined4 *)pTVar1,3,0x1406,0,0,*(undefined4 *)(param_1 + 4));
      uVar5 = *(undefined4 *)pTVar2;
      uVar7 = *(undefined4 *)(param_1 + 8);
    }
    else {
      glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x60));
      glVertexAttribPointer(*(undefined4 *)pTVar1,3,0x1406,0,0,0);
      glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x68));
      uVar5 = *(undefined4 *)pTVar2;
      uVar7 = 0;
    }
    glVertexAttribPointer(uVar5,2,0x1406,0,0,uVar7);
  }
  return;
}

