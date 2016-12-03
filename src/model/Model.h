#pragma once

#include <array>

#include <glm/glm.hpp>

#include "game_logic/Loopable.h"
#include "model/Shape.h"

class Shader;
class BasicEventArgs;

class Model : public LoopableAdapter {
    public:
        enum class HammerShapes {
            BASE,
            HOLDER,
            HANDLE,
            HEAD,
            TARGET,
            TARGET_BASE,
            COUNT
        };
        typedef std::array<Shape, static_cast<size_t>(HammerShapes::COUNT)> ShapeArray;

        Model(const Shader& shader);
        
        ShapeArray& getShapes();
        const ShapeArray& getShapes() const;
    
        void draw() const;
    private:
        void onUpdate(const BasicEventArgs& args);

        void draw_stable_shapes() const;
        void draw_original_and_copy(const glm::vec3& offset) const;
        void draw_animated(const glm::vec3& offset) const;

        ShapeArray shapes;
        const Shader& shader;

        float angle;
        static constexpr const float ROTATION_SPEED = 4.0f;

        float push;
        static constexpr const float PUSH_SPEED = 0.2f;
};
