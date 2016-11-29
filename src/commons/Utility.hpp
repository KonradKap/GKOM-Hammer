#include <utility>
#include <iostream>

template<class Container, typename std::enable_if<boost::spirit::traits::is_container<Container>::type>::type>
    Container operator+(Container lhs, const Container& rhs) {
        return lhs += rhs;
    }

template<class Container, typename std::enable_if<boost::spirit::traits::is_container<Container>::type>::type>
    Container operator+=(Container& lhs, const Container& rhs) {
        lhs.insert(lhs.end(), rhs.begin(), rhs.end());
        return lhs;
    }

template<class Container, typename std::enable_if<boost::spirit::traits::is_container<Container>::type>::type>
    Container operator+(Container lhs, Container&& rhs) {
        return lhs += rhs;
    }

template<class Container, typename std::enable_if<boost::spirit::traits::is_container<Container>::type>::type>
    Container operator+=(Container& lhs, Container&& rhs) {
        lhs.insert(lhs.end(),
            std::make_move_iterator(rhs.begin()),
            std::make_move_iterator(rhs.end()));
        return lhs;
    }
