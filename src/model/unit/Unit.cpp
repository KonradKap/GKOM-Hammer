#include "Unit.h"

#include <iostream>

#include <boost/math/constants/constants.hpp>

#include <SFML/Window/Mouse.hpp>

#include "game_logic/event/EventType.h"
#include "view/View.h"

Unit::Unit(sf::ConvexShape shape) :
        velocity(),
        shape(shape) {
}

Unit::Unit(const Unit& u) :
        velocity(u.velocity),
        shape(u.shape){
}

Unit::~Unit() {
}

const sf::ConvexShape& Unit::getShape() const {
    return shape;
}

sf::ConvexShape& Unit::getShape() {
    return const_cast<sf::ConvexShape&>(static_cast<const Unit*>(this)->getShape());
}

const VectorD& Unit::getVelocity() const {
    return velocity;
}

VectorD& Unit::getVelocity() {
    return const_cast<VectorD&>(static_cast<const Unit*>(this)->getVelocity());
}

void Unit::onUpdate(const BasicEventArgs& arg) {
    const auto target = sf::Vector2f(sf::Mouse::getPosition(View::getWindow()));
    velocity = VectorD(target - shape.getPosition());
    const auto angle = (std::atan2(velocity.y, velocity.x) - std::atan2(-1, 0)) * 180 / boost::math::constants::pi<double>();
    
    shape.setRotation(angle);
    shape.move(sf::Vector2f(velocity*float(arg.frame_time)/1000.f));
}
