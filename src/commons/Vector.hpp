#pragma once

#include <cmath>
#include <utility>
#include <stdexcept>

template<class T>
    Vector<T>::Vector(T x, T y) : 
        x(x), y(y) {
    }

template<class T>
    Vector<T>::Vector(const Vector& w) : 
        Vector(w.x, w.y) {
    }

template<class T>
    template<class W>
        Vector<T>::Vector(const sf::Vector2<W>& arg) : 
            Vector(arg.x, arg.y) {
        }

template<class T>
    template<class W>
        Vector<T>::Vector(const Vector<W>& arg) : 
            Vector(arg.x, arg.y) {
        }

template<class T>
    template<class W>
        Vector<T>::operator sf::Vector2<W>() const {
            return sf::Vector2<W>(x, y);
        }

template<class T>
    void swap(Vector<T>& lhs, Vector<T>& rhs) {
        std::swap(lhs.x, rhs.x);
        std::swap(lhs.y, rhs.y);
    }

template<class T>
    T Vector<T>::length() const {
        return std::sqrt(length_sqr());
    }

template<class T>
    T Vector<T>::length_sqr() const {
        return this->x*this->x + this->y*this->y;
    }

template<class T>
    Vector<T>& Vector<T>::normalize() {
        *this /= this->length();
        return *this;
    }

template<class T>
    Vector<T> Vector<T>::normalize() const {
        Vector<T> temp = *this;
        return temp.normalize();
    }

template<class T>
    T Vector<T>::projection_length(const Vector<T>& target) const {
        return dot_product(normalize(target));
    }

template<class T>
    Vector<T>& Vector<T>::project(const Vector<T>& target) {
        return *this *= this->projection_length(target)/target.length();
    }

template<class T>
    Vector<T> Vector<T>::project(Vector<T> target) const {
        return target *= this->projection_length(target)/target.length();
    }

template<class T>
    Vector<T> Vector<T>::perpendicular() const {
        return {this->y, -this->x};
    }

template<class T>
    T Vector<T>::dot_product(const Vector<T>& arg) const {
        return arg.x*this->x + arg.y*this->y;
    }

VectorI make_unit_vector(Direction dir) {
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
    Vector<T>& Vector<T>::operator=(Vector<T> arg) {
        swap(*this, arg);
        return *this;
    }

template<class T>
    Vector<T>& Vector<T>::operator+=(const Vector<T>& arg) {
        x += arg.x;
        y += arg.y;
        return *this;
    }

template<class T>
    Vector<T>& Vector<T>::operator-=(const Vector<T>& arg) {
        x -= arg.x;
        y -= arg.y;
        return *this;
    }

template <class T>
    template <class W>
        Vector<T>& Vector<T>::operator*=(const W scalar) {
            x *= scalar;
            y *= scalar;
            return *this;
        }

template<class T>
    template <class W>
        Vector<T>& Vector<T>::operator/=(const W scalar) {
            x /= scalar;
            y /= scalar;
            return *this;
        }

template<class T>
    bool operator==(const Vector<T>& lhs, const Vector<T>& rhs) {
        return lhs.x == rhs.x and lhs.y == rhs.y;
    }

template<class T>
    bool operator!=(const Vector<T>& lhs, const Vector<T>& rhs) {
        return !(lhs == rhs);
    }

template<class T>
    Vector<T> operator+(Vector<T> lhs, const Vector<T>& rhs) {
        return lhs += rhs;
    }

template<class T>
     Vector<T> operator-(Vector<T> lhs, const Vector<T>& rhs) {
         return lhs -= rhs;
     }

template<class T, class W>
     Vector<T> operator*(Vector<T> lhs, const W rhs) {
         return lhs *= rhs;
     }

template<class T, class W>
     Vector<T> operator/(Vector<T> lhs, const W rhs) {
         return lhs /= rhs;
     }
