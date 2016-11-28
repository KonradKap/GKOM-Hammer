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
