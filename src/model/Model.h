#pragma once

#include <vector>

#include "game_logic/Loopable.h"
#include "model/Shape.h"
#include "game_logic/shaders/Shader.h"

class Model : public LoopableAdapter {
    public:
        Model(Shape&& shape, const Shader& shader);
        
        Shape& getShape();
        const Shape& getShape() const;
    
        void onStart(const BasicEventArgs& arg);
        void draw() const;
    private:
        void do_mapping();

        Shape shape;
        const Shader& shader;
        struct {
            GLuint MVP_location;
            GLuint V_location;
            GLuint M_location;

            GLuint colour_location;
            GLuint light_position;

            GLuint light_intensity;
            glm::vec3 colour;
            glm::mat4 model = glm::mat4(1.f);
        } mapping;
};
