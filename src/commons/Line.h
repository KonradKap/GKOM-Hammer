 /*
  * Line.h
  *
  * 6.09.2016 r.
  *
  * Memotosh
  *
  */

#pragma once

#include "Vector.h"

class Line {
    public:
        Line();
        Line(const Line& l);
        Line(VectorD start, VectorD end);
        ~Line();

        const VectorD& begin() const;
        const VectorD& end() const;

        VectorD perpendicular() const;
        VectorD to_vector() const;

        bool operator==(const Line& l) const;
        bool operator!=(const Line& l) const;

    private:
        VectorD start_;
        VectorD end_;
};
