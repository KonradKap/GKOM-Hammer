#version 330 core

out vec4 color;

in vec3 v_pos;
in vec3 v_norm;
in vec2 v_tex;

uniform vec3 light_position;
uniform vec3 light_color;
uniform mat4 model;

uniform sampler2D texture_sampler;

void main()
{
    vec4 material_color = texture(texture_sampler, v_tex).rgba;
    mat3 normalMatrix = transpose(inverse(mat3(model)));
    vec3 normal = normalize(normalMatrix * v_norm);

    vec3 frag_position = vec3(model * vec4(v_pos, 1));
    
    vec3 surface_to_light = light_position - frag_position;

    float brightness = dot(normal, surface_to_light) / (length(surface_to_light) * length(normal));
    brightness = clamp(brightness, 0, 1);

    color = vec4(brightness * light_color * material_color.rgb, 1.0) + vec4(0.1, 0.1, 0.1, 1.0);
}
