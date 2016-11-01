#include "SAT.h"

#include <vector>
#include <utility>
#include <iostream>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Shape.hpp>

#include "commons/Vector.h"
#include "commons/Line.h"
#include "commons/ShapeUtils.h"
#include "commons/Utility.h"

namespace {

std::vector<VectorD> get_axes(const sf::Shape& shape) {
    std::vector<VectorD> sides = get_side_vectors(shape);
    std::transform(sides.begin(), sides.end(), sides.begin(), [](const VectorD& side) {
            return side.perpendicular().normalize();
        });
    return sides;
}

std::pair<double, double> get_projection(
        const std::vector<VectorD>& vertices, const VectorD& axis) {

    double min = vertices.front().dot_product(axis);
    double max = min;

    for(auto vertex : vertices) {
        double temp = vertex.dot_product(axis);
        min = std::min(min, temp);
        max = std::max(max, temp);
    }

    return {min, max};
}

std::pair<double, double> get_projection(
        const sf::Shape& shape, const VectorD& axis) {

    return get_projection(get_vertices(shape), axis);
}

} //namespace

std::pair<bool, VectorD> collision_check(const sf::Shape& lhs, const sf::Shape& rhs) {
    std::vector<VectorD> axes = get_axes(lhs) + get_axes(rhs);
    double smallest_overlap = std::numeric_limits<double>::max();
    VectorD overlapping_axis;
    for(const auto& axis : axes) {
        const auto l_projection = get_projection(lhs, axis);
        const auto r_projection = get_projection(rhs, axis);
    
        double o = overlap(l_projection, r_projection);
        if(o < 0) {
            return {false, {}};
        } else if (o < smallest_overlap) {
            smallest_overlap = o;
            overlapping_axis = axis;
        }
    }
    return {true, overlapping_axis*smallest_overlap};
}

