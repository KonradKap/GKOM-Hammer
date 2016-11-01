 /*
  * ShapeUtils.h
  *
  * 12.10.2016 r.
  *
  * Memotosh
  *
  */

#pragma once

#include <vector>
#include <functional>

#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>

#include "Line.h"
#include "Vector.h"

void for_each_vertex(
        const sf::Shape& shape, 
        std::function<void (const VectorD&)> function);

void for_each_side(
        const sf::Shape& shape, 
        std::function<void (const VectorD&, const VectorD&)> function);

std::vector<Line> get_sides(const sf::Shape& shape);
std::vector<VectorD> get_side_vectors(const sf::Shape& shape);
std::vector<VectorD> get_vertices(const sf::Shape& shape);

sf::ConvexShape create_shape(unsigned vertex_count, float size = 5.f);
