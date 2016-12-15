#pragma once

#include <vector>
#include <functional>

#include <glm/glm.hpp>

class Shader;

class Camera {
    public:
        Camera();
        Camera(const glm::vec3& position, const glm::vec3& direction, const float tilt);
        Camera(const Camera& c);
        ~Camera();

        void setPosition(const glm::vec3& position);
        void move(const glm::vec3& offset);
        const glm::vec3& getPosition() const;

        void setDirection(const glm::vec3& direction);
        glm::vec3 getDirection() const;

        void lean(float degrees);
        void tilt(float degrees);
        void rotate(float degrees);

        glm::vec3 left() const;
        glm::vec3 right() const;

        void begin(const Shader& shader) const;
        void begin(const std::vector<std::reference_wrapper<const Shader>>& shaders) const;
    private:
        glm::vec3 position;
        glm::vec3 center;
        glm::vec3 up;
};
