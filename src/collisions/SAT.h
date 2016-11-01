    /*
     * SAT.h
     *
     * 12.10.2016 r.
     *
     * Memotosh
     *
     */

#pragma once

#include <utility>

#include <SFML/Graphics/Shape.hpp>

#include "commons/Vector.h"

std::pair<bool, VectorD> collision_check(const sf::Shape& lhs, const sf::Shape& rhs);
