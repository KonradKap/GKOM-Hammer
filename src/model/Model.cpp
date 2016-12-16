#include "commons/ScopeBind.h"
#include <GL/gl.h>
#include "Model.h"

#include "game_logic/MainLoop.h"
#include "controller/Keyboard.h"
#include "model/models/hammer_holder.h"
#include "model/models/hammer_head.h"
#include "model/models/hammer_handle.h"
#include "model/models/target_base.h"
#include "model/models/target.h"
#include "model/models/base.h"

Model::Model() :
        shapes{
            Shape{base_vertices, base_indices, Shape::VERTICES | Shape::NORMALS | Shape::TEXTURES}, 
            Shape{hammer_holder_vertices, hammer_holder_indices, Shape::VERTICES | Shape::NORMALS | Shape::TEXTURES}, 
            Shape{hammer_handle_vertices, hammer_handle_indices, Shape::VERTICES | Shape::NORMALS}, 
            Shape{hammer_head_vertices, hammer_head_indices, Shape::VERTICES | Shape::NORMALS}, 
            Shape{target_vertices, target_indices, Shape::VERTICES | Shape::NORMALS}, 
            Shape{target_base_vertices, target_base_indices, Shape::VERTICES | Shape::NORMALS | Shape::TEXTURES},
        },
        angle(0.0f),
        push(0.0f) {

}

Model::ShapeArray& Model::getShapes() {
    return const_cast<ShapeArray&>(static_cast<const Model*>(this)->getShapes());
}

const Model::ShapeArray& Model::getShapes() const {
    return shapes;
}

Shape& Model::operator[](HammerShapes id) {
    return const_cast<Shape&>(static_cast<const Model*>(this)->operator[](id));
}

const Shape& Model::operator[](HammerShapes id) const {
    return shapes[static_cast<size_t>(id)];
}

float Model::getPush() const {
    return push;
}

float Model::getAngle() const {
    return angle;
}

void Model::onUpdate(const BasicEventArgs& args) {
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

    if(target) {
        if(push < 0.0f)
            push += PUSH_SPEED;
    } else {
        if(push > -2.0f)
            push -= PUSH_SPEED;
    }
}
