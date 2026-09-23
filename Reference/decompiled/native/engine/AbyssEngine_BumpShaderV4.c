// Class: AbyssEngine::BumpShaderV4
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::BumpShaderV4::BumpShaderV4  @0x000960d8  (104 bytes)
/* AbyssEngine::BumpShaderV4::BumpShaderV4() */

void __thiscall AbyssEngine::BumpShaderV4::BumpShaderV4(BumpShaderV4 *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_00263678;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"BumpShaderV4",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::BumpShaderV4::Init  @0x00096184  (236 bytes)
/* AbyssEngine::BumpShaderV4::Init(AbyssEngine::Engine*) */

void AbyssEngine::BumpShaderV4::Init(Engine *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 \ta_position;\t\t\nattribute mediump vec2  a_texCoord;   \t\nattribute highp vec3  \ta_normal; \t\t\nattribute lowp vec3 \ta_tangent;\t\t\nattribute lowp vec3 \ta_bitangent;\t\nvarying mediump vec2 v_texCoord;\t\t\nvarying mediump vec3 v_light_dir;\t\t\nvarying mediump vec3 v_eye_dir;\t\t\nvarying mediump vec3 v_lightvec;\t\t\nvarying mediump vec3 v_normal;\t\t\t\nvarying mediump vec3 v_specular_dir;\t\nuniform highp mat4 u_ModelViewProjectionMatrix;\t\nuniform highp vec3 u_lightdirmodel;\t\nuniform highp vec3 u_eyeposmodel;\t\t\n//uniform highp mat3 u_ModelMatrix;\t\nvoid main()\t\t\t\t\t\t\t\n{\t\t\t\t\t\t\t\t\t\t\n\tgl_Position = u_ModelViewProjectionMatrix * a_position;\t\n\tv_texCoord  = a_texCoord;\t\t\t\n\tv_normal = a_normal;\t\t\t\t\n\t//mediump vec3 bitangent = normalize(cross(a_normal, a_tangent)); \n\thighp mat3 tangentSpaceXform = mat3(a_tangent.x, a_bitangent.x, a_normal.x,\t\n\t\t\t\t\t\t\t\t\t\ta_tangent.y, a_bitangent.y, a_normal.y,\t\n\t\t\t\t\t\t\t\t\t\ta_tangent.z, a_bitangent.z, a_normal.z\t\n\t\t\t\t\t\t\t\t\t\t); \n\t//v_eye_dir   = tangentSpaceXform * normalize(u_eyeposmodel - a_position.xyz); \n\t//v_light_dir = tangentSpaceXform * u_lightdirmodel; \n\tvec3 shininesDirection = normalize(normalize(u_eyeposmodel - a_position.xyz) + u_lightdirmodel) ; \n\tv_specular_dir = tangentSpaceXform * shininesDirection; \n\tv_lightvec = tangentSpaceXform * u_lightdirmodel; //tangentSpaceXform * shininesDirection; \n\t//u_lightposmodel \n\t//v_DiffuseLight.rgb = vec3(max(dot(a_normal, u_LightDirection), 0.0)); \n\t//v_DiffuseLight.a = 1.0; \n} \n"
                     ,
                     "precision lowp float;\t\nvarying mediump vec2 v_texCoord;\t\nvarying mediump vec3 v_light_dir;\t\nvarying mediump vec3 v_eye_dir;\t\nvarying mediump vec3 v_lightvec;\t\nvarying mediump vec3 v_normal;\t\nvarying mediump vec3 v_specular_dir;\t\nuniform sampler2D  s_texture[2];\t\nvoid main()\t\n{\t\n\tlowp vec4 colorTex   = texture2D( s_texture[0], v_texCoord );\t\n\tlowp vec4 normalTex  = texture2D( s_texture[1], v_texCoord );\t\n\tlowp vec3 normalTexX = normalTex.rgb*2.0 - 1.0;\t\n\tlowp vec4 specTex = vec4(vec3(normalTex.a), 0.0);\t\n\tfloat specularIntensity = dot( v_specular_dir,normalTexX );\t\n\tfloat diffuseIntensity  = max( dot( normalTexX    ,v_lightvec ), 0.22 );\t\n\tlowp vec4 color;\t\n\tif (specularIntensity > 0.99)\t\n\t\tcolor = vec4(0.9, 0.9, 1.0, 1.0);\t\n\telse if (specularIntensity > 0.95)\t\n\t\tcolor = vec4(0.7, 0.7, 1.0, 1.0);\t\n\telse if (specularIntensity > 0.5)\t\n\t\tcolor = vec4(0.3, 0.3, 0.6, 1.0);\t\n\telse if (specularIntensity > 0.25)\t\n\t\tcolor = vec4(0.2, 0.2, 0.4, 1.0);\t\n\telse \tcolor = vec4(0.1, 0.1, 0.2, 1.0);\t\n\tgl_FragColor = colorTex*0.5+color; //diffuseIntensity * colorTex + specularIntensity * specTex;\t\n}\t\n"
                    );
  *(undefined4 *)(param_1 + 4) = uVar1;
  uVar1 = glGetAttribLocation(uVar1,"a_position");
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_texCoord");
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_normal");
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_tangent");
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_bitangent");
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_ModelViewProjectionMatrix");
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_ModelMatrix");
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_lightdirmodel");
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_eyeposmodel");
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"s_texture[0]");
  *(undefined4 *)(param_1 + 0x40) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"s_texture[1]");
  *(undefined4 *)(param_1 + 0x44) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"glColor");
  *(undefined4 *)(param_1 + 0x48) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_AmbientColor");
  *(undefined4 *)(param_1 + 0x4c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_DiffuseColor");
  *(undefined4 *)(param_1 + 0x50) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_SpecularColor");
  *(undefined4 *)(param_1 + 0x54) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 4));
  iVar2 = 0;
  do {
    if (-1 < *(int *)(param_1 + iVar2 * 4 + 0x40)) {
      glUniform1i(*(int *)(param_1 + iVar2 * 4 + 0x40),iVar2);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 2);
  return;
}

// ===== AbyssEngine::BumpShaderV4::SetInActive  @0x000962b4  (62 bytes)
/* AbyssEngine::BumpShaderV4::SetInActive() */

void __thiscall AbyssEngine::BumpShaderV4::SetInActive(BumpShaderV4 *this)

{
  if (-1 < *(int *)(this + 0x1c)) {
    glDisableVertexAttribArray();
  }
  if (-1 < *(int *)(this + 0x20)) {
    glDisableVertexAttribArray();
  }
  if (-1 < *(int *)(this + 0x24)) {
    glDisableVertexAttribArray();
  }
  if (-1 < *(int *)(this + 0x28)) {
    glDisableVertexAttribArray();
  }
  if (*(int *)(this + 0x2c) < 0) {
    return;
  }
  glDisableVertexAttribArray();
  return;
}

// ===== AbyssEngine::BumpShaderV4::UpdateMeshData  @0x000962f2  (476 bytes)
/* AbyssEngine::BumpShaderV4::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::BumpShaderV4::UpdateMeshData(BumpShaderV4 *this,Mesh *param_1,Engine *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (-1 < *(int *)(this + 0x30)) {
    glUniformMatrix4fv(*(int *)(this + 0x30),1,0,param_2 + 0xf4);
  }
  if (-1 < *(int *)(this + 0x34)) {
    glUniformMatrix3fv(*(int *)(this + 0x34),1,0,param_2 + 500);
  }
  if (this[9] != (BumpShaderV4)0x0) {
    if (-1 < *(int *)(this + 0x38)) {
      glUniform3f(*(int *)(this + 0x38),*(undefined4 *)(param_2 + 800),
                  *(undefined4 *)(param_2 + 0x324),*(undefined4 *)(param_2 + 0x328));
    }
    if (-1 < *(int *)(this + 0x3c)) {
      glUniform3f(*(int *)(this + 0x3c),*(undefined4 *)(param_2 + 0x33c),
                  *(undefined4 *)(param_2 + 0x340),*(undefined4 *)(param_2 + 0x344));
    }
    if (-1 < *(int *)(this + 0x48)) {
      glUniform4fv(*(int *)(this + 0x48),1,param_2 + 0xc0);
    }
    if (-1 < *(int *)(this + 0x4c)) {
      glUniform4fv(*(int *)(this + 0x4c),1,param_2 + 0x298);
    }
    if (-1 < *(int *)(this + 0x50)) {
      glUniform4fv(*(int *)(this + 0x50),1,param_2 + 0x288);
    }
    if (-1 < *(int *)(this + 0x54)) {
      glUniform4fv(*(int *)(this + 0x54),1,param_2 + 0x2a8);
    }
    this[9] = (BumpShaderV4)0x0;
  }
  if (-1 < *(int *)(this + 0x1c)) {
    glEnableVertexAttribArray();
  }
  if (-1 < *(int *)(this + 0x20)) {
    glEnableVertexAttribArray();
  }
  if (-1 < *(int *)(this + 0x24)) {
    glEnableVertexAttribArray();
  }
  if (-1 < *(int *)(this + 0x28)) {
    glEnableVertexAttribArray();
  }
  if (-1 < *(int *)(this + 0x2c)) {
    glEnableVertexAttribArray();
  }
  if (param_1[0x5c] == (Mesh)0x0) {
    if (-1 < *(int *)(this + 0x1c)) {
      glVertexAttribPointer(*(int *)(this + 0x1c),3,0x1406,0,0,*(undefined4 *)(param_1 + 4));
    }
    if (-1 < *(int *)(this + 0x20)) {
      glVertexAttribPointer(*(int *)(this + 0x20),2,0x1406,0,0,*(undefined4 *)(param_1 + 8));
    }
    if (-1 < *(int *)(this + 0x24)) {
      glVertexAttribPointer(*(int *)(this + 0x24),3,0x1406,0,0,*(undefined4 *)(param_1 + 0x10));
    }
    if (-1 < *(int *)(this + 0x28)) {
      glVertexAttribPointer(*(int *)(this + 0x28),3,0x1406,0,0,*(undefined4 *)(param_1 + 0x14));
    }
    iVar1 = *(int *)(this + 0x2c);
    if (iVar1 < 0) {
      return;
    }
    uVar2 = *(undefined4 *)(param_1 + 0x18);
  }
  else {
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x60));
    glVertexAttribPointer(*(undefined4 *)(this + 0x1c),3,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x68));
    glVertexAttribPointer(*(undefined4 *)(this + 0x20),2,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x6c));
    glVertexAttribPointer(*(undefined4 *)(this + 0x24),3,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x70));
    glVertexAttribPointer(*(undefined4 *)(this + 0x28),3,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x74));
    iVar1 = *(int *)(this + 0x2c);
    uVar2 = 0;
  }
  glVertexAttribPointer(iVar1,3,0x1406,0,0,uVar2);
  return;
}

