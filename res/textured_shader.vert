#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 tex;

out vec3 v_pos;
out vec3 v_norm;
out vec2 v_tex;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    v_pos = position;
    v_norm = normal;
    v_tex = tex;
    gl_Position = projection * view * model * vec4(position, 1.0f);
}
