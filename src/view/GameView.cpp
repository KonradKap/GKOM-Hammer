#include "GameView.h"

#include <glm/gtc/matrix_transform.hpp>

#include "commons/ScopeBind.h"
#include "controller/Keyboard.h"
#include "view/Light.h"
#include "model/Model.h"
#include "model/models/skybox.h"

GameView::GameView(const Model& model) :
        model(model),
        solid_shader("solid_shader.vert", "solid_shader.frag"),
        textured_shader("textured_shader.vert", "textured_shader.frag"),
        camera({0, 0, -6}, {0, 0, 1}, 0),
        skybox(skybox_vertices, skybox_indices, Shape::VERTICES | Shape::NORMALS | Shape::TEXTURES),
        wooden_texture("wood.jpg"), 
        skybox_texture("skybox.jpg") {
    
    
}

const Camera& GameView::getCamera() const {
    return camera;
}

Camera& GameView::getCamera() {
    return const_cast<Camera&>(static_cast<const GameView*>(this)->getCamera());
}

void GameView::onUpdate(const BasicEventArgs& args) {
    if(Keyboard::getInstance().isPressed(GLFW_KEY_W))
        camera.move(camera.getDirection()/2.0f);
    if(Keyboard::getInstance().isPressed(GLFW_KEY_S))
        camera.move(camera.getDirection()/-2.0f);
    if(Keyboard::getInstance().isPressed(GLFW_KEY_A))
        camera.move(camera.left()/2.0f);
    if(Keyboard::getInstance().isPressed(GLFW_KEY_D))
        camera.move(camera.right()/2.0f);
}

void GameView::doDrawing() {
    camera.begin({solid_shader, textured_shader});
    setLight({-2.5, 4, 0.5}, {1, 1, 1}, {solid_shader, textured_shader});
    draw_textured(skybox, skybox_texture, camera.getPosition());

    draw_textured(model[Model::HammerShapes::BASE], wooden_texture);
    draw_textured(model[Model::HammerShapes::HOLDER], wooden_texture);
    draw_textured(model[Model::HammerShapes::HOLDER], wooden_texture, {0, 0, 1});
    draw_animated({0, 0, 1});
}
void GameView::draw_textured(const Shape& shape, const Texture& texture, const glm::vec3& offset) const {
    const auto guard = ScopeBind::guard(texture);
    textured_shader.setUniform("texture_sampler", texture.get_id());
    shape.draw(offset, textured_shader);
}

void GameView::draw_animated(const glm::vec3& offset) const {
    const glm::vec3 rotation_point{0, 0.5, 0};
    auto hammer_rotation = glm::translate(glm::mat4(1), rotation_point);
    hammer_rotation = glm::rotate(hammer_rotation, glm::radians(model.getAngle()), glm::vec3(0, 0, 1));
    hammer_rotation = glm::translate(hammer_rotation, -rotation_point);
    model[Model::HammerShapes::HANDLE].draw(hammer_rotation, solid_shader);
    model[Model::HammerShapes::HEAD].draw(hammer_rotation, solid_shader);

    draw_textured(model[Model::HammerShapes::TARGET_BASE], wooden_texture, glm::vec3(0, 0, model.getPush()));
    model[Model::HammerShapes::TARGET].draw(glm::vec3(0, 0, model.getPush()), solid_shader);
    model[Model::HammerShapes::TARGET].draw(glm::vec3(0, 0, model.getPush()) - offset, solid_shader);
}
