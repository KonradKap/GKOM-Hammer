#include "Light.h"

#include <algorithm>

#include "view/Shader.h"

void setLight(const glm::vec3& position, const glm::vec3& color, const Shader& shader) {
    shader.use();
    shader.setUniform("light_position", position);
    shader.setUniform("light_color", color);
};

void setLight(const glm::vec3& position, const glm::vec3& color, 
        const std::vector<std::reference_wrapper<const Shader>>& shaders) {

    std::for_each(shaders.begin(), shaders.end(), [&](const Shader& s) { 
        setLight(position, color, s); });
}
