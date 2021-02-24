#shader fragment
#version 450 core
#extension GL_ARB_separate_shader_objects: enable
out vec4 fragColor;
uniform vec4 u_color;
uniform sampler2D u_MainTex;
in vec4 lgeColor;
in vec2 v_texCoord;

void main()
{
    vec4 texClr = texture(u_MainTex, v_texCoord);
    fragColor = texClr;
}
#shader vertex
#version 450 core
#extension GL_ARB_separate_shader_objects : enable
#extension GL_EXT_gpu_shader4 : enable
layout(location = 0) in vec2 position;
layout(location = 1) in vec2 u_texCoord;
layout(location = 2) in vec4 a_Color;

out vec4 lgeColor;
out vec2 v_texCoord;


uniform mat4 u_mvp;
void main()
{

    v_texCoord = u_texCoord;
    gl_Position = u_mvp * vec4(position,1.0f,1.0f) ;
    lgeColor = a_Color;

}