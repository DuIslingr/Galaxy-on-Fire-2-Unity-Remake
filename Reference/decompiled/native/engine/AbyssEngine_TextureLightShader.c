// Class: AbyssEngine::TextureLightShader
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::TextureLightShader::TextureLightShader  @0x00098894  (104 bytes)
/* AbyssEngine::TextureLightShader::TextureLightShader() */

void __thiscall AbyssEngine::TextureLightShader::TextureLightShader(TextureLightShader *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_00263870;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"TextureLightShader",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::TextureLightShader::Init  @0x00098940  (276 bytes)
/* AbyssEngine::TextureLightShader::Init(AbyssEngine::Engine*) */

void AbyssEngine::TextureLightShader::Init(Engine *param_1)

{
  undefined4 uVar1;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position;   \nattribute mediump vec2 a_texCoord;   \nattribute highp vec3  a_normal; \nvarying mediump vec2 v_texCoord;     \nvarying lowp vec3  v_DiffuseLight[2];\t\nvarying lowp vec3  v_SpecularLight[2];\t\nuniform highp mat4 u_WorldMatrix;  \nuniform highp mat4 u_UvMatrix;  \nuniform mediump mat4 u_FullModelMatrix;  \nuniform mediump mat3 u_ModelMatrix;  \nuniform highp vec4 u_LightDirection[2]; \nuniform highp vec3 u_EyePosModel;  \nuniform lowp vec3 u_AmbientColor[2];\nuniform lowp vec3 u_DiffuseColor[2];\nuniform lowp vec3 u_SpecularColor[2];\nuniform lowp float u_SpecularPower;\nuniform bool u_UVAnimation; \nvoid main()                  \n{                            \n   gl_Position = u_WorldMatrix * a_position;\t\t\n   if ( u_UVAnimation ) \n       v_texCoord = (u_UvMatrix*vec4(a_texCoord.x, a_texCoord.y, 0.0, 1.0)).xy;  \n   else \n       v_texCoord = a_texCoord; \n\thighp vec3 lightDirLocal; \n\thighp float nDotL; \n\tif ( u_LightDirection[0].w == 0.0 ) {\n\t\tlightDirLocal = u_LightDirection[0].xyz; \n\t\tnDotL = dot(a_normal, lightDirLocal);\n\t} else {\n\t\t// lightDirLocal = normalize(u_LightDirection[0].xyz - a_position.xyz);\n\t\t// nDotL = dot(a_normal, lightDirLocal);\n\t\thighp vec4 positionWorld = u_FullModelMatrix * a_position; \n\t\tlightDirLocal = normalize(u_LightDirection[0].xyz - positionWorld.xyz);\n\t\thighp vec3 normalWorld = normalize(u_ModelMatrix * a_normal.xyz); \n\t\tnDotL = dot(normalWorld, lightDirLocal);\n\t} \n\tv_DiffuseLight[0] = vec3(max(nDotL, 0.0)); \n\t// Compute\treflection vector \n\thighp vec3 reflection = (2.0 * a_normal * nDotL) - lightDirLocal;\t\n   reflection = normalize(-reflect(lightDirLocal, a_normal)); \n\t// Compute R.V \n\thighp float rDotV = max(0.0, dot(reflection, normalize(u_EyePosModel)));\n\t// Compute Specular term \n\tv_SpecularLight[0] = u_SpecularColor[0] * pow(rDotV, u_SpecularPower);\t\n\tv_DiffuseLight[0] *= u_DiffuseColor[0];\n\tv_DiffuseLight[0] += u_AmbientColor[0];\n\tif ( u_LightDirection[1].w == 0.0 ) {\n\t\tlightDirLocal = u_LightDirection[1].xyz; \n\t\tnDotL = dot(a_normal, lightDirLocal);\n\t} else {\n\t..." /* TRUNCATED STRING LITERAL */
                     ,
                     "precision lowp float;                            \nvarying mediump vec2 v_texCoord;                            \nvarying lowp vec3  v_DiffuseLight[2];\t\nvarying lowp vec3  v_SpecularLight[2];\t\nuniform sampler2D s_texture;                        \nuniform lowp vec4 glColor;\t\t\t\t\t\t\t\t \nvoid main()                                         \n{                                                   \n\tvec4 textureColor = texture2D( s_texture, v_texCoord );\t\n   lowp vec3 color = (v_DiffuseLight[0] + v_DiffuseLight[1]) * (textureColor.rgb) + v_SpecularLight[0] + v_SpecularLight[1]; \n\tgl_FragColor.rgb = glColor.rgb * color;\n\tgl_FragColor.a = glColor.a * textureColor.a; \n}   \t\t  \n"
                    );
  *(undefined4 *)(param_1 + 4) = uVar1;
  uVar1 = glGetUniformLocation(uVar1,"u_UvMatrix");
  *(undefined4 *)(param_1 + 100) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_UVAnimation");
  *(undefined4 *)(param_1 + 0x68) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_position");
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_texCoord");
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_normal");
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_WorldMatrix");
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_FullModelMatrix");
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_ModelMatrix");
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_LightDirection[0]");
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_LightDirection[1]");
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_EyePosModel");
  *(undefined4 *)(param_1 + 0x60) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"s_texture");
  *(undefined4 *)(param_1 + 0x40) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"glColor");
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_AmbientColor[0]");
  *(undefined4 *)(param_1 + 0x44) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_DiffuseColor[0]");
  *(undefined4 *)(param_1 + 0x4c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_SpecularColor[0]");
  *(undefined4 *)(param_1 + 0x54) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_SpecularPower");
  *(undefined4 *)(param_1 + 0x5c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_AmbientColor[1]");
  *(undefined4 *)(param_1 + 0x48) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_DiffuseColor[1]");
  *(undefined4 *)(param_1 + 0x50) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_SpecularColor[1]");
  *(undefined4 *)(param_1 + 0x58) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 4));
  glUniform1i(*(undefined4 *)(param_1 + 0x40),0);
  return;
}

// ===== AbyssEngine::TextureLightShader::SetInActive  @0x00098aac  (28 bytes)
/* AbyssEngine::TextureLightShader::SetInActive() */

void __thiscall AbyssEngine::TextureLightShader::SetInActive(TextureLightShader *this)

{
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x1c));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x20));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x24));
  return;
}

// ===== AbyssEngine::TextureLightShader::UpdateMeshData  @0x00098ac8  (466 bytes)
/* AbyssEngine::TextureLightShader::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::TextureLightShader::UpdateMeshData
          (TextureLightShader *this,Mesh *param_1,Engine *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  glUniformMatrix4fv(*(undefined4 *)(this + 0x28),1,0,param_2 + 0xf4);
  if (-1 < *(int *)(this + 100)) {
    glUniformMatrix4fv(*(int *)(this + 100),1,0,param_2 + 0x1b4);
  }
  glUniformMatrix3fv(*(undefined4 *)(this + 0x30),1,0,param_2 + 500);
  if (-1 < *(int *)(this + 0x2c)) {
    glUniformMatrix4fv(*(int *)(this + 0x2c),1,0,param_2 + 0x134);
  }
  if (this[9] != (TextureLightShader)0x0) {
    if (-1 < *(int *)(this + 0x68)) {
      glUniform1i(*(int *)(this + 0x68),param_1[0x85]);
    }
    glUniform4fv(*(undefined4 *)(this + 0x3c),1,param_2 + 0xc0);
    glUniform3fv(*(undefined4 *)(this + 0x44),1,param_2 + 700);
    glUniform3fv(*(undefined4 *)(this + 0x4c),1,param_2 + 0x2ec);
    glUniform3fv(*(undefined4 *)(this + 0x54),1,param_2 + 0x2d4);
    glUniform4f(*(undefined4 *)(this + 0x34),*(undefined4 *)(param_2 + 800),
                *(undefined4 *)(param_2 + 0x324),*(undefined4 *)(param_2 + 0x328),
                *(undefined4 *)(param_2 + 0x368));
    if (*(int *)(param_2 + 0x31c) < 2) {
      glUniform3f(*(undefined4 *)(this + 0x48),0,0,0);
      glUniform3f(*(undefined4 *)(this + 0x50),0,0,0);
      glUniform3f(*(undefined4 *)(this + 0x58),0,0,0);
    }
    else {
      glUniform3fv(*(undefined4 *)(this + 0x48),1,param_2 + 0x2c8);
      glUniform3fv(*(undefined4 *)(this + 0x50),1,param_2 + 0x2f8);
      glUniform3fv(*(undefined4 *)(this + 0x58),1,param_2 + 0x2e0);
    }
    glUniform4f(*(undefined4 *)(this + 0x38),*(undefined4 *)(param_2 + 0x32c),
                *(undefined4 *)(param_2 + 0x330),*(undefined4 *)(param_2 + 0x334),
                *(undefined4 *)(param_2 + 0x36c));
    glUniform1f(*(undefined4 *)(this + 0x5c),*(undefined4 *)(param_2 + 0x2b8));
    if (-1 < *(int *)(this + 0x60)) {
      glUniform3f(*(int *)(this + 0x60),*(undefined4 *)(param_2 + 0x33c),
                  *(undefined4 *)(param_2 + 0x340),*(undefined4 *)(param_2 + 0x344));
    }
    this[9] = (TextureLightShader)0x0;
  }
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x1c));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x20));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x24));
  if (param_1[0x5c] == (Mesh)0x0) {
    glVertexAttribPointer(*(undefined4 *)(this + 0x1c),3,0x1406,0,0,*(undefined4 *)(param_1 + 4));
    glVertexAttribPointer(*(undefined4 *)(this + 0x20),2,0x1406,0,0,*(undefined4 *)(param_1 + 8));
    uVar1 = *(undefined4 *)(this + 0x24);
    uVar2 = *(undefined4 *)(param_1 + 0x10);
  }
  else {
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x60));
    glVertexAttribPointer(*(undefined4 *)(this + 0x1c),3,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x68));
    glVertexAttribPointer(*(undefined4 *)(this + 0x20),2,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x6c));
    uVar1 = *(undefined4 *)(this + 0x24);
    uVar2 = 0;
  }
  glVertexAttribPointer(uVar1,3,0x1406,0,0,uVar2);
  return;
}

