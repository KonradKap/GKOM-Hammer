#pragma once

#include <glm/glm.hpp>

class Shader;

class Camera {
    public:
        Camera(const Shader& shader);
        Camera(const Shader& shader, const glm::vec3& position, const glm::vec3& direction, const float tilt);
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

        void begin() const;
    private:
        const Shader& shader;

        glm::vec3 position;
        glm::vec3 center;
        glm::vec3 up;
};
