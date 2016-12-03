#include "Model.h"

#include <glm/gtc/matrix_transform.hpp>

#include "game_logic/MainLoop.h"
#include "commons/ScopeBind.h"
#include "view/Shader.h"
#include "controller/Keyboard.h"
#include "model/models/hammer_holder_1.h"
#include "model/models/hammer_holder_2.h"
#include "model/models/hammer_head.h"
#include "model/models/hammer_handle.h"
#include "model/models/target_base.h"
#include "model/models/target_1.h"
#include "model/models/target_2.h"
#include "model/models/base.h"

Model::Model(const Shader& shader) :
        shapes{
            Shape{base_vertices, base_indices, GL_STATIC_DRAW}, 
            Shape{hammer_holder_1_vertices, hammer_holder_1_indices, GL_STATIC_DRAW}, 
            Shape{hammer_handle_vertices, hammer_handle_indices, GL_STATIC_DRAW}, 
            Shape{hammer_head_vertices, hammer_head_indices, GL_STATIC_DRAW}, 
            Shape{target_1_vertices, target_1_indices, GL_STATIC_DRAW}, 
            Shape{target_base_vertices, target_base_indices, GL_STATIC_DRAW},
        },
        shader(shader),
        angle(0.0f),
        push(0.0f) {

}

Model::ShapeArray& Model::getShapes() {
    return const_cast<ShapeArray&>(static_cast<const Model*>(this)->getShapes());
}

const Model::ShapeArray& Model::getShapes() const {
    return shapes;
}

void Model::onUpdate(const BasicEventArgs& args) {
    static bool target;
    static bool hitting;
    if(hitting) {
        angle += ROTATION_SPEED;
        if(angle > 0.0f) {
            hitting = false;
            target = !target;
        }
    } else {
        angle -= ROTATION_SPEED;
        if(angle < -180.0f) {
            hitting = true;
        }
    }
//    if(!hitting) {
        if(target) {
            if(push < 0.0f)
                push += PUSH_SPEED;
        } else {
            if(push > -2.0f)
                push -= PUSH_SPEED;
        }
//    }
}

void Model::draw() const {
    shader.use();
    draw_stable_shapes();
    draw_original_and_copy({0, 0, -2});
    draw_animated({0, 0, 2});
}

void Model::draw_stable_shapes() const {
    for(const auto id : {HammerShapes::BASE})
        shapes[static_cast<size_t>(id)].draw({0, 0, 0}, shader);
}

void Model::draw_original_and_copy(const glm::vec3& offset) const {
    for(const auto id : {HammerShapes::HOLDER}) {
        shapes[static_cast<size_t>(id)].draw({0, 0, 0}, shader);
        shapes[static_cast<size_t>(id)].draw(offset, shader);
    }

}

void Model::draw_animated(const glm::vec3& offset) const {
    const glm::vec3 rotation_point{0, 1.5, 0};
    auto hammer_rotation = glm::translate(glm::mat4(1), rotation_point);
    hammer_rotation = glm::rotate(hammer_rotation, glm::radians(angle), glm::vec3(0, 0, 1));
    hammer_rotation = glm::translate(hammer_rotation, -rotation_point);
    shapes[static_cast<size_t>(HammerShapes::HANDLE)].draw(hammer_rotation, shader);
    shapes[static_cast<size_t>(HammerShapes::HEAD)].draw(hammer_rotation, shader);

    const auto target_push = glm::translate(glm::mat4(1), glm::vec3(0, 0, push));
    shapes[static_cast<size_t>(HammerShapes::TARGET_BASE)].draw(target_push, shader);
    shapes[static_cast<size_t>(HammerShapes::TARGET)].draw(target_push, shader);
    shapes[static_cast<size_t>(HammerShapes::TARGET)].draw(target_push * glm::translate(glm::mat4(1), offset), shader);
}
