#include "Line.h"

#include "Vector.h"

Line::Line() : 
        start_(),
        end_() {
}

Line::Line(const Line& l) :
        start_(l.start_),
        end_(l.end_) {
}

Line::Line(VectorD start_, VectorD end) :
        start_(start_),
        end_(end) {
}

Line::~Line() {
}

const VectorD& Line::begin() const {
    return start_;
}

const VectorD& Line::end() const {
    return end_;
}

VectorD Line::perpendicular() const {
    return to_vector().perpendicular();
}

VectorD Line::to_vector() const {
    return {end_.x-start_.x, end_.y-start_.y};
}

bool Line::operator==(const Line& l) const {
    return l.start_ == start_ and l.end_ == end_;
}

bool Line::operator!=(const Line& l) const {
    return !(l == *this);
}

