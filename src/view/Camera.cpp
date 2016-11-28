#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>

#include "game_logic/shaders/Shader.h"
#include "game_logic/MainLoop.h"

Camera::Camera(const Shader& shader) : 
        shader(shader),
        position(0.0f, 0.0f, 0.0f),
        center(0.0f, 0.0f, 1.0f), 
        up(0.0f, 1.0f, 0.0f) {

}

Camera::Camera(const Shader& shader, const glm::vec3& position, const glm::vec3& direction, const float tilt) :
        shader(shader),
        position(position),
        center(position + direction),
        up(glm::vec3(glm::rotate(glm::mat4(1), tilt, glm::vec3(0.0f, 0.0f, 1.0f)) * glm::vec4(0.0f, 1.0f, 0.0f, 1.0f))) {
            
}
        
Camera::Camera(const Camera& c) : 
        shader(c.shader),
        position(c.position), 
        center(c.center), 
        up(c.up) {

}

Camera::~Camera() {
}

void Camera::setPosition(const glm::vec3& position) {
    this->position = position;
}

void Camera::move(const glm::vec3& offset) {
    position += offset;
}

const glm::vec3& Camera::getPosition() const {
    return position;
}

void Camera::setDirection(const glm::vec3& direction) {
    this->center = position + direction;
}

glm::vec3 Camera::getDirection() const {
    return center - position;
}

void Camera::tilt(float degrees) {
    up = glm::vec3(glm::rotate(glm::mat4(1), degrees, glm::vec3(0.0f, 0.0f, 1.0f)) * glm::vec4(up, 1.0f));
}

float Camera::getTilt() const {
    return glm::orientedAngle(up, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
}

void Camera::begin() const {
    shader.use();
    GLuint projLoc = glGetUniformLocation(shader.get_id(), "projection");
    glm::mat4 projection = glm::perspective(45.0f, (GLfloat)MainLoop::WINDOW_X / (GLfloat)MainLoop::WINDOW_Y, 0.1f, 100.0f);
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

    GLuint viewLoc = glGetUniformLocation(shader.get_id(), "view");
    const auto view = glm::lookAt(position, center, up);
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
}
