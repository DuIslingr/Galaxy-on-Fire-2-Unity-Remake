// Class: AbyssEngine::BumpMapping
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::BumpMapping::BumpMapping  @0x0009becc  (104 bytes)
/* AbyssEngine::BumpMapping::BumpMapping() */

void __thiscall AbyssEngine::BumpMapping::BumpMapping(BumpMapping *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_00263bb4;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"BumpMapping",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::BumpMapping::Init  @0x0009bf78  (152 bytes)
/* AbyssEngine::BumpMapping::Init(AbyssEngine::Engine*) */

void AbyssEngine::BumpMapping::Init(Engine *param_1)

{
  undefined4 uVar1;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position;\nattribute mediump vec3 a_normal;\nattribute mediump vec3 a_tangent;\nattribute mediump vec3 a_bitangent;\nattribute mediump vec2 a_texCoord;\nvarying mediump vec2 v_texCoord;\nvarying mediump vec3 v_lightvec;\nuniform highp mat4 u_WorldMatrix;\nuniform highp vec3 u_lightposmodel;\nvoid main()\n{\n\tgl_Position = u_WorldMatrix * a_position;\n\thighp mat3 tangentSpaceXform = mat3(a_tangent, a_bitangent, a_normal);\n\tv_lightvec =   u_lightposmodel * tangentSpaceXform;\n\tv_texCoord = a_texCoord;\n}\n"
                     ,
                     "precision mediump float;   \nvarying mediump vec2 v_texCoord;    \nvarying mediump vec3 v_lightvec;    \nuniform sampler2D s_texture_base;   \nuniform sampler2D s_texture_normal;\nvoid main()                      \n{                              \n\tmediump vec3 normal = normalize(texture2D(s_texture_normal, v_texCoord).rgb*2.0 - 1.0);\n\tmediump vec3 lightvec = normalize(v_lightvec);\n\tmediump float lightIntensity = max(dot(lightvec, normal), 0.0);\n\tlowp vec4 textureColor = texture2D( s_texture_base, v_texCoord );// * v_color;\t\n\t// Compute Ambient term \n\tlowp vec4 ambient = vec4(0.3, 0.3, 0.3, 1.0) * textureColor; \n\tgl_FragColor = ambient;\n\tif (lightIntensity>0.0) {\t\n\t\t// Compute Diffuse term \n\t\tlowp vec4 diffuse =  vec4(0.7, 0.7, 0.7, 1.0) * lightIntensity * textureColor;\n\t\tgl_FragColor += diffuse; \n\t}\n\t//gl_FragColor = vec4(0.5,0.5,0.5,0.5);\n}\n"
                    );
  *(undefined4 *)(param_1 + 4) = uVar1;
  uVar1 = glGetAttribLocation(uVar1,"a_position");
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_normal");
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_tangent");
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_bitangent");
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_texCoord");
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_WorldMatrix");
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_lightposmodel");
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"s_texture_base");
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"s_texture_normal");
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 4));
  glUniform1i(*(undefined4 *)(param_1 + 0x38),0);
  glUniform1i(*(undefined4 *)(param_1 + 0x3c),1);
  return;
}

// ===== AbyssEngine::BumpMapping::SetInActive  @0x0009c03c  (40 bytes)
/* AbyssEngine::BumpMapping::SetInActive() */

void __thiscall AbyssEngine::BumpMapping::SetInActive(BumpMapping *this)

{
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x1c));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x20));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x24));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x28));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x2c));
  return;
}

// ===== AbyssEngine::BumpMapping::UpdateMeshData  @0x0009c064  (206 bytes)
/* AbyssEngine::BumpMapping::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::BumpMapping::UpdateMeshData(BumpMapping *this,Mesh *param_1,Engine *param_2)

{
  Mesh MVar1;
  
  if (this[9] != (BumpMapping)0x0) {
    this[9] = (BumpMapping)0x0;
  }
  glUniformMatrix4fv(*(undefined4 *)(this + 0x30),1,0,param_2 + 0xf4);
  glUniform3f(*(undefined4 *)(this + 0x34),*(undefined4 *)(param_2 + 800),
              *(undefined4 *)(param_2 + 0x324),*(undefined4 *)(param_2 + 0x328));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x1c));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x20));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x24));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x28));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x2c));
  glVertexAttribPointer(*(undefined4 *)(this + 0x1c),3,0x1406,0,0,*(undefined4 *)(param_1 + 4));
  MVar1 = *param_1;
  if (((byte)MVar1 & 2) != 0) {
    glVertexAttribPointer(*(undefined4 *)(this + 0x2c),2,0x1406,0,0,*(undefined4 *)(param_1 + 8));
    MVar1 = *param_1;
  }
  if (((byte)MVar1 & 4) != 0) {
    glVertexAttribPointer(*(undefined4 *)(this + 0x20),3,0x1406,0,0,*(undefined4 *)(param_1 + 0x10))
    ;
    glVertexAttribPointer(*(undefined4 *)(this + 0x24),3,0x1406,0,0,*(undefined4 *)(param_1 + 0x14))
    ;
    glVertexAttribPointer(*(undefined4 *)(this + 0x28),3,0x1406,0,0,*(undefined4 *)(param_1 + 0x18))
    ;
  }
  return;
}

