#pragma once

#include <vector>
#include <functional>

#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/glm.hpp>

class Shader;

void setLight(const glm::vec3& position, const glm::vec3& color, const Shader& shader);
void setLight(const glm::vec3& position, const glm::vec3& color, 
        const std::vector<std::reference_wrapper<const Shader>>& shaders);
