#version 330 core
layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec3 aNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 normal;
uniform mat4 projection;

out vec3 Color;

void main()
{
    gl_Position = projection * view * model * vec4(aPosition, 1.f);
    Color = aColor;
    //vec3 norm = normalize(vec3(normal * aNormal));
}
