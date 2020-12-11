#shader fragment
#version 330 core
#extension GL_ARB_separate_shader_objects: enable
out vec4 fragColor;
in vec4 m_Color;
uniform vec4 u_colorMix;
uniform float u_mixIntensity;
void main()
{
    
    fragColor = mix(m_Color, u_colorMix, u_mixIntensity);


}
#shader vertex
#version 330 core
#extension GL_ARB_separate_shader_objects : enable
layout(location = 0) in vec3 position;
layout(location = 1) in vec4 aColor;
out vec4 m_Color;
void main()
{
    m_Color = aColor;
    gl_Position = vec4(position,1.0);


}