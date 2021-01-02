#shader fragment
#version 330 core
#extension GL_ARB_separate_shader_objects: enable
out vec4 fragColor;
uniform vec4 u_color;
void main()
{
    fragColor = u_color;
}
#shader vertex
#version 330 core
#extension GL_ARB_separate_shader_objects : enable
layout(location = 0) in vec3 position;
void main()
{

    gl_Position = vec4(position,1.0);


}