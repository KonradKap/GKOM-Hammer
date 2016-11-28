#include "Model.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "model/BasicShapes.h"
#include "game_logic/MainLoop.h"
#include "commons/ScopeBind.h"

Model::Model(Shape&& shape, const Shader& shader) :
        shape(std::move(shape)),
        shader(shader) {

}

void Model::onStart(const BasicEventArgs& args) {
    do_mapping();
}

Shape& Model::getShape() {
    return const_cast<Shape&>(static_cast<const Model*>(this)->getShape());
}

const Shape& Model::getShape() const {
    return shape;
}

void Model::do_mapping() {
    GLuint programID = shader.get_id();
    mapping.MVP_location = glGetUniformLocation(programID, "MVP");
    mapping.V_location = glGetUniformLocation(programID, "V");
    mapping.M_location = glGetUniformLocation(programID, "M");

    mapping.colour_location = glGetUniformLocation(programID, "colour");
    mapping.light_position = glGetUniformLocation(programID, "LightPosition_worldspace");

    mapping.light_intensity = glGetUniformLocation(programID, "lightIntensity");
}

void Model::draw() const {
    const auto guard = ScopeBind::guard(shape);
    shader.use();

    GLuint modelLoc = glGetUniformLocation(shader.get_id(), "model");
    
    glm::mat4 trans;
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(trans));
    glDrawElements(GL_TRIANGLES, shape.indexCount(), GL_UNSIGNED_INT, 0);
}
