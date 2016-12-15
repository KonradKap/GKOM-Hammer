#include <utility>
#include <iostream>

template<class Container, typename std::enable_if<is_container<Container>::value>::type* >
    Container operator+(Container lhs, const Container& rhs) {
        return lhs += rhs;
    }

template<class Container, typename std::enable_if<is_container<Container>::value>::type* >
    Container operator+=(Container& lhs, const Container& rhs) {
        lhs.insert(lhs.end(), rhs.begin(), rhs.end());
        return lhs;
    }

template<class Container, typename std::enable_if<is_container<Container>::value>::type* >
    Container operator+(Container lhs, Container&& rhs) {
        return lhs += rhs;
    }

template<class Container, typename std::enable_if<is_container<Container>::value>::type* >
    Container operator+=(Container& lhs, Container&& rhs) {
        lhs.insert(lhs.end(),
            std::make_move_iterator(rhs.begin()),
            std::make_move_iterator(rhs.end()));
        return lhs;
    }

template<class Container, typename std::enable_if<is_container<Container>::value>::type* >
    bool operator==(const Container& lhs, const Container& rhs) {
        return std::equal(lhs.begin(), lhs.end(), rhs.begin());
    }

template<class Container, typename std::enable_if<is_container<Container>::value>::type* >
    bool operator!=(const Container& lhs, const Container& rhs) {
        return !(lhs == rhs);
    }
