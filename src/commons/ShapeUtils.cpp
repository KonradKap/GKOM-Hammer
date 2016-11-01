#include "ShapeUtils.h"

#include <SFML/Graphics/CircleShape.hpp>

void for_each_vertex(const sf::Shape& shape, std::function<void (const VectorD&)> function) {
    const auto transform = shape.getTransform();
    for(unsigned i = 0; i < shape.getPointCount(); ++i) {
        function(VectorD(transform.transformPoint(shape.getPoint(i))));
    }
}

void for_each_side(
        const sf::Shape& shape, 
        std::function<void (const VectorD&, const VectorD&)> function) {

    const auto transform = shape.getTransform();
    for(unsigned i = 0; i < shape.getPointCount(); ++i) {
        function(
            VectorD(transform.transformPoint(shape.getPoint(i))),
            VectorD(transform.transformPoint(shape.getPoint((i+1) == shape.getPointCount() ? 0 : i + 1))));
    }
}

std::vector<Line> get_sides(const sf::Shape& shape) {
    std::vector<Line> output{};
    output.reserve(shape.getPointCount());
    for_each_side(shape, [&output](const VectorD& begin, const VectorD& end) mutable {
        output.push_back(Line(begin, end));
    });
    return output;
}

std::vector<VectorD> get_side_vectors(const sf::Shape& shape) {
    std::vector<VectorD> output{};
    output.reserve(shape.getPointCount());
    for_each_side(shape, [&output](const VectorD& begin, const VectorD& end) mutable {
        output.push_back(begin - end);
    });
    return output;
}

std::vector<VectorD> get_vertices(const sf::Shape& shape) {
    std::vector<VectorD> output{};
    output.reserve(shape.getPointCount());
    for_each_vertex(shape, [&output](const VectorD& vertex) mutable {
        output.push_back(vertex);
    });
    return output;
}

sf::ConvexShape create_shape(unsigned vertex_count, float size) {
    sf::CircleShape temp{size, vertex_count};
    sf::ConvexShape ret{vertex_count};
    int i = 0;
    for_each_vertex(temp, [&ret, &i](const VectorD& vertex) mutable {
        ret.setPoint(i++, sf::Vector2f(vertex));
    });
    ret.setOrigin(size, size);
    return ret;
}
