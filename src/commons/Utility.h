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

#include <boost/spirit/include/support.hpp>

template<class Container, typename std::enable_if<boost::spirit::traits::is_container<Container>::type>::type = 0>
    Container operator+(Container lhs, const Container& rhs);

template<class Container, typename std::enable_if<boost::spirit::traits::is_container<Container>::type>::type = 0>
    Container operator+=(Container& lhs, const Container& rhs);

template<class Container, typename std::enable_if<boost::spirit::traits::is_container<Container>::type>::type = 0>
    Container operator+(Container lhs, Container&& rhs);

template<class Container, typename std::enable_if<boost::spirit::traits::is_container<Container>::type>::type = 0>
    Container operator+=(Container& lhs, Container&& rhs);

template<class vector>
void print(const vector& w) {
    std::cout << w.x << ", " << w.y << ", " << w.z << std::endl;
}

#include "Utility.hpp"
