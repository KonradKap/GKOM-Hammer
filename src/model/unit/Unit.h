 /*
  * Unit.h
  *
  * 4.09.2016r.
  *
  * Memotosh
  */

#pragma once

#include <memory>

#include <SFML/Graphics/ConvexShape.hpp>

#include "game_logic/Loopable.h"
#include "commons/Vector.h"

class Unit : public LoopableAdapter {
    public:
        Unit(sf::ConvexShape shape);
        Unit(const Unit& u);
        virtual ~Unit();

        const sf::ConvexShape& getShape() const;
        sf::ConvexShape& getShape();

        const VectorD& getVelocity() const;
        VectorD& getVelocity();
    protected:
        VectorD velocity;

        sf::ConvexShape shape;
    private:
        virtual void onUpdate(const BasicEventArgs& args);
};
