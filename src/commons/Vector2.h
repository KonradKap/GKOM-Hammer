 /*
  * Vector2.h
  *
  * 6.09.2016 r.
  *
  * Memotosh
  *
  */

#pragma once

#include "commons/Direction.h"

template<class T>
    class Vector2 {
        public:
            Vector2(T x=0, T y=0);
            Vector2(const Vector2& w);

            template<class W>
                explicit Vector2(const Vector2<W>& arg);

            template<class W>
                friend void swap(Vector2& lhs, Vector2& rhs);

            T length() const;
            T length_sqr() const;

            Vector2<T>& normalize();
            Vector2<T> normalize() const;

            T projection_length(const Vector2<T>& target) const;
            Vector2<T>& project(const Vector2<T>& target);
            Vector2<T> project(Vector2<T> target) const;
            
            Vector2<T> perpendicular() const;
            Vector2<T>& rotate(double angle);
            Vector2<T> rotate(double angle) const;
            
            Vector2& operator=(Vector2 arg);
            Vector2& operator+=(const Vector2& arg);
            Vector2& operator-=(const Vector2& arg);

            template <class W>
                Vector2& operator*=(const W scalar);
            template <class W>
                Vector2& operator/=(const W scalar);

            T dot_product(const Vector2<T>& other) const;

            T x;
            T y;
    };

typedef Vector2<double> Vector2D;
typedef Vector2<int> Vector2I;
typedef Vector2<float> Vector2F;
typedef Vector2<unsigned> Vector2U;

inline Vector2I make_unit_vector(Direction dir);

template<class T>
    inline bool operator==(const Vector2<T>& lhs, const Vector2<T>& rhs);
template<class T>
    inline bool operator!=(const Vector2<T>& lhs, const Vector2<T>& rhs);
template<class T>
    inline Vector2<T> operator+(Vector2<T> lhs, const Vector2<T>& rhs); 
template<class T>
    inline Vector2<T> operator-(Vector2<T> lhs, const Vector2<T>& rhs); 
template<class T, class W>
    inline Vector2<T> operator*(Vector2<T> lhs, const W rhs); 
template<class T, class W>
    inline Vector2<T> operator/(Vector2<T> lhs, const W rhs); 

#include "Vector2.hpp"
