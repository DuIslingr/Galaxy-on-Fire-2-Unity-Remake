// Class: AbyssEngine::SandboxShader
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::SandboxShader::SandboxShader  @0x0009c3d8  (104 bytes)
/* AbyssEngine::SandboxShader::SandboxShader() */

void __thiscall AbyssEngine::SandboxShader::SandboxShader(SandboxShader *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_00263c24;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"SandboxShader",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::SandboxShader::Init  @0x0009c484  (188 bytes)
/* AbyssEngine::SandboxShader::Init(AbyssEngine::Engine*) */

void AbyssEngine::SandboxShader::Init(Engine *param_1)

{
  undefined4 uVar1;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 \ta_position;   \t\nattribute mediump vec2  a_texCoord;   \t\nattribute highp vec3  \ta_normal; \t\t\nattribute lowp vec3 \ta_tangent;\t\t\nattribute lowp vec3 \ta_bitangent;\t\nvarying mediump vec2 v_texCoord;\nvarying mediump vec3 v_light_dir;\nvarying mediump vec3 v_eye_dir;\nvarying mediump vec3 v_lightvec;\nuniform highp mat4 u_WorldMatrix;\nuniform highp vec3 u_light_dir;\nuniform highp vec3 u_eye_pos;\nvoid main()\n{\n\tgl_Position = u_WorldMatrix * a_position;\t\t\n\tv_texCoord  = a_texCoord;  \n\t//mediump vec3 bitangent = normalize(cross(a_normal, a_tangent)); \n\thighp mat3 tangentSpaceXform = mat3(a_tangent, a_bitangent, a_normal);\n\t//v_eye_dir   = tangentSpaceXform * normalize(u_eye_pos - a_position.xyz);\n\t//v_light_dir = tangentSpaceXform * u_light_dir;\n\tvec3 shininesDirection = normalize(normalize(u_eye_pos - a_position.xyz) + u_light_dir) ;\n\tv_lightvec = tangentSpaceXform * shininesDirection;\n\t//u_lightposmodel\n\t//v_DiffuseLight.rgb = vec3(max(dot(a_normal, u_LightDirection), 0.0));\n\t//v_DiffuseLight.a = 1.0;\n}\n"
                     ,
                     "precision lowp float;\nvarying mediump vec2 v_texCoord;\nvarying mediump vec3 v_light_dir;\nvarying mediump vec3 v_eye_dir;\nvarying mediump vec3 v_lightvec;\nuniform sampler2D  s_texture_norm;\nuniform sampler2D  s_texture_base;\nuniform lowp vec4  glColor;\nuniform lowp vec4  u_AmbientColor;\nvoid main()\n{\n\tlowp vec3 normal = normalize(texture2D(s_texture_norm, v_texCoord).rgb*2.0 - 1.0);\n\t//lowp vec3 lightvec = normalize(v_eye_dir+v_light_dir);\n\tlowp vec3 lightvec = normalize(v_lightvec);\n\tlowp float specularIntensity = abs( dot(lightvec, normal) );\n\t//lowp float diffuseIntensity  = 0.0; //max( dot(v_light_dir, normal), 0.0 );\n\tlowp vec4 textureColor = texture2D( s_texture_base, v_texCoord );// * v_color;\n\tgl_FragColor =  ( specularIntensity/* + diffuseIntensity*/) * textureColor * glColor;\n}\t\n"
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
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_WorldMatrix");
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_light_dir");
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_eye_pos");
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"s_texture_base");
  *(undefined4 *)(param_1 + 0x40) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"s_texture_norm");
  *(undefined4 *)(param_1 + 0x44) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"glColor");
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_AmbientColor");
  *(undefined4 *)(param_1 + 0x48) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 4));
  glUniform1i(*(undefined4 *)(param_1 + 0x40),0);
  glUniform1i(*(undefined4 *)(param_1 + 0x44),1);
  return;
}

// ===== AbyssEngine::SandboxShader::SetInActive  @0x0009c578  (40 bytes)
/* AbyssEngine::SandboxShader::SetInActive() */

void __thiscall AbyssEngine::SandboxShader::SetInActive(SandboxShader *this)

{
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x1c));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x20));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x24));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x28));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x2c));
  return;
}

// ===== AbyssEngine::SandboxShader::UpdateMeshData  @0x0009c5a0  (354 bytes)
/* AbyssEngine::SandboxShader::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::SandboxShader::UpdateMeshData(SandboxShader *this,Mesh *param_1,Engine *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  glUniformMatrix4fv(*(undefined4 *)(this + 0x30),1,0,param_2 + 0xf4);
  if (this[9] != (SandboxShader)0x0) {
    glUniform4fv(*(undefined4 *)(this + 0x3c),1,param_2 + 0xc0);
    glUniform3f(*(undefined4 *)(this + 0x34),*(undefined4 *)(param_2 + 800),
                *(undefined4 *)(param_2 + 0x324),*(undefined4 *)(param_2 + 0x328));
    glUniform3f(*(undefined4 *)(this + 0x38),*(undefined4 *)(param_2 + 0x33c),
                *(undefined4 *)(param_2 + 0x340),*(undefined4 *)(param_2 + 0x344));
    this[9] = (SandboxShader)0x0;
  }
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x1c));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x20));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x24));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x28));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x2c));
  if (param_1[0x5c] == (Mesh)0x0) {
    glVertexAttribPointer(*(undefined4 *)(this + 0x1c),3,0x1406,0,0,*(undefined4 *)(param_1 + 4));
    glVertexAttribPointer(*(undefined4 *)(this + 0x20),2,0x1406,0,0,*(undefined4 *)(param_1 + 8));
    glVertexAttribPointer(*(undefined4 *)(this + 0x24),3,0x1406,0,0,*(undefined4 *)(param_1 + 0x10))
    ;
    glVertexAttribPointer(*(undefined4 *)(this + 0x28),3,0x1406,0,0,*(undefined4 *)(param_1 + 0x14))
    ;
    uVar1 = *(undefined4 *)(this + 0x2c);
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
    uVar1 = *(undefined4 *)(this + 0x2c);
    uVar2 = 0;
  }
  glVertexAttribPointer(uVar1,3,0x1406,0,0,uVar2);
  return;
}

