 /*
  * Utility.h
  *
  * 12.10.2016 r.
  *
  * Memotosh
  *
  */

#pragma once

#include <utility>

template <class T>
    double overlap(T a_begin, T a_end, T b_begin, T b_end);

template <class T>
    double overlap(std::pair<T, T> a, std::pair<T, T> b);

template<class Container>
    Container operator+(Container lhs, const Container& rhs);

template<class Container>
    Container operator+=(Container& lhs, const Container& rhs);

template<class Container>
    Container operator+(Container lhs, Container&& rhs);

template<class Container>
    Container operator+=(Container& lhs, Container&& rhs);

template<class T>
    void print(T printable);

#include "Utility.hpp"
