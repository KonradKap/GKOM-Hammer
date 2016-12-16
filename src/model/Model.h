#pragma once

#include <array>

#include <glm/glm.hpp>

#include "game_logic/Loopable.h"
#include "model/Shape.h"

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

        Model();
        
        ShapeArray& getShapes();
        const ShapeArray& getShapes() const;

        Shape& operator[](HammerShapes id);
        const Shape& operator[](HammerShapes id) const;
    
        float getPush() const;
        float getAngle() const;
    private:
        void onUpdate(const BasicEventArgs& args);

        ShapeArray shapes;

        float angle;
        static constexpr const float ROTATION_SPEED = 4.0f;

        float push;
        static constexpr const float PUSH_SPEED = 0.2f;

        bool target;
        bool hitting;
};
