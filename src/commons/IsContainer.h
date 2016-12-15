#pragma once

#include <type_traits>

template <class Container, typename = void>
    class is_container : public std::false_type {
    };

template <class Container>
    class is_container<Container, typename std::enable_if<
        std::is_same <
            decltype (std::declval<Container>().begin()),
            typename Container::iterator
        >::value 
        and
        std::is_same <
            decltype (std::declval<Container>().end()),
            typename Container::iterator
        >::value
    >::type > : public std::true_type {
    };
