#pragma once

#include <cmath>
#include <utility>
#include <stdexcept>

template<class T>
    Vector2<T>::Vector2(T x, T y) : 
        x(x), y(y) {
    }

template<class T>
    Vector2<T>::Vector2(const Vector2& w) : 
        Vector2(w.x, w.y) {
    }

template<class T>
    template<class W>
        Vector2<T>::Vector2(const Vector2<W>& arg) : 
            Vector2(arg.x, arg.y) {
        }

template<class T>
    void swap(Vector2<T>& lhs, Vector2<T>& rhs) {
        std::swap(lhs.x, rhs.x);
        std::swap(lhs.y, rhs.y);
    }

template<class T>
    T Vector2<T>::length() const {
        return std::sqrt(length_sqr());
    }

template<class T>
    T Vector2<T>::length_sqr() const {
        return this->x*this->x + this->y*this->y;
    }

template<class T>
    Vector2<T>& Vector2<T>::normalize() {
        *this /= this->length();
        return *this;
    }

template<class T>
    Vector2<T> Vector2<T>::normalize() const {
        Vector2<T> temp = *this;
        return temp.normalize();
    }

template<class T>
    T Vector2<T>::projection_length(const Vector2<T>& target) const {
        return dot_product(normalize(target));
    }

template<class T>
    Vector2<T>& Vector2<T>::project(const Vector2<T>& target) {
        return *this *= this->projection_length(target)/target.length();
    }

template<class T>
    Vector2<T> Vector2<T>::project(Vector2<T> target) const {
        return target *= this->projection_length(target)/target.length();
    }

template<class T>
    Vector2<T> Vector2<T>::perpendicular() const {
        return {this->y, -this->x};
    }

template<class T>
    T Vector2<T>::dot_product(const Vector2<T>& arg) const {
        return arg.x*this->x + arg.y*this->y;
    }

Vector2I make_unit_vector(Direction dir) {
    switch(dir) {
        case Direction::UP:
            return {0, -1};
        case Direction::DOWN:
            return {0, 1};
        case Direction::LEFT:
            return {-1, 0};
        case Direction::RIGHT:
            return {1, 0};
        default:
            throw std::invalid_argument("Direction " + std::to_string(int(dir)) + "not present");
    }
}

template<class T>
    Vector2<T>& Vector2<T>::operator=(Vector2<T> arg) {
        swap(*this, arg);
        return *this;
    }

template<class T>
    Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& arg) {
        x += arg.x;
        y += arg.y;
        return *this;
    }

template<class T>
    Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& arg) {
        x -= arg.x;
        y -= arg.y;
        return *this;
    }

template <class T>
    template <class W>
        Vector2<T>& Vector2<T>::operator*=(const W scalar) {
            x *= scalar;
            y *= scalar;
            return *this;
        }

template<class T>
    template <class W>
        Vector2<T>& Vector2<T>::operator/=(const W scalar) {
            x /= scalar;
            y /= scalar;
            return *this;
        }

template<class T>
    bool operator==(const Vector2<T>& lhs, const Vector2<T>& rhs) {
        return lhs.x == rhs.x and lhs.y == rhs.y;
    }

template<class T>
    bool operator!=(const Vector2<T>& lhs, const Vector2<T>& rhs) {
        return !(lhs == rhs);
    }

template<class T>
    Vector2<T> operator+(Vector2<T> lhs, const Vector2<T>& rhs) {
        return lhs += rhs;
    }

template<class T>
     Vector2<T> operator-(Vector2<T> lhs, const Vector2<T>& rhs) {
         return lhs -= rhs;
     }

template<class T, class W>
     Vector2<T> operator*(Vector2<T> lhs, const W rhs) {
         return lhs *= rhs;
     }

template<class T, class W>
     Vector2<T> operator/(Vector2<T> lhs, const W rhs) {
         return lhs /= rhs;
     }
