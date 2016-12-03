#include "Light.h"

#include "view/Shader.h"

void setLight(const glm::vec3& position, const glm::vec3& color, const Shader& shader) {
    shader.setUniform("light_position", position);
    shader.setUniform("light_color", color);
};
