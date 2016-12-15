#pragma once

#include <GL/glew.h>

#include "view/View.h"
#include "view/Camera.h"
#include "view/Shader.h"
#include "model/Shape.h"
#include "model/Texture.h"

class Model;

class GameView : public View {
    public:
        GameView(const Model& model);
    
        const Camera& getCamera() const;
        Camera& getCamera();
    private:
        const Model& model;
        Shader solid_shader;
        Shader textured_shader;
        Camera camera;
        Shape skybox;
        Texture skybox_texture;

        void onUpdate(const BasicEventArgs& args);

        void doDrawing();

        void draw_stable_shapes() const;
        void draw_original_and_copy(const glm::vec3& offset) const;
        void draw_animated(const glm::vec3& offset) const;
};
