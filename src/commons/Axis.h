 /*
  * Axis.h
  *
  * 4.09.2016 r.
  *
  * Memotosh
  *
  */

#pragma once

enum class Axis {
    X,
    Y
};

template <Axis AXIS>
    struct other {
        static constexpr const Axis value = AXIS == Axis::X ? Axis::Y : Axis::X;
    };
