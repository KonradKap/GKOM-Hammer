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

#include "commons/IsContainer.h"

template<class Container, typename std::enable_if<is_container<Container>::value>::type* = nullptr >
    Container operator+(Container lhs, const Container& rhs);

template<class Container, typename std::enable_if<is_container<Container>::value>::type* = nullptr >
    Container operator+=(Container& lhs, const Container& rhs);

template<class Container, typename std::enable_if<is_container<Container>::value>::type* = nullptr >
    Container operator+(Container lhs, Container&& rhs);

template<class Container, typename std::enable_if<is_container<Container>::value>::type* = nullptr >
    Container operator+=(Container& lhs, Container&& rhs);

template<class Container, typename std::enable_if<is_container<Container>::value>::type* = nullptr >
    bool operator==(const Container& lhs, const Container& rhs);

template<class Container, typename std::enable_if<is_container<Container>::value>::type* = nullptr >
    bool operator!=(const Container& lhs, const Container& rhs);

#include "Utility.hpp"
