#include <utility>
#include <iostream>

template <class T>
    double overlap(T a_begin, T a_end, T b_begin, T b_end) {
        if(a_begin > a_end)
            std::swap(a_begin, a_end);
        if(b_begin > b_end)
            std::swap(b_begin, b_end);
        return std::min(a_end, b_end) - std::max(a_begin, b_begin);
    }

template <class T>
    double overlap(std::pair<T, T> a, std::pair<T, T> b) {
        return overlap(a.first, a.second, b.first, b.second);
    }

template<class Container>
    Container operator+(Container lhs, const Container& rhs) {
        return lhs += rhs;
    }

template<class Container>
    Container operator+=(Container& lhs, const Container& rhs) {
        lhs.insert(lhs.end(), rhs.begin(), rhs.end());
        return lhs;
    }

template<class Container>
    Container operator+(Container lhs, Container&& rhs) {
        return lhs += rhs;
    }

template<class Container>
    Container operator+=(Container& lhs, Container&& rhs) {
        lhs.insert(lhs.end(),
            std::make_move_iterator(rhs.begin()),
            std::make_move_iterator(rhs.end()));
        return lhs;
    }

template<class T>
    void print(T printable) {
        std::cout << "(" << printable.x << ", " << printable.y << ")" << std::endl;
    }
