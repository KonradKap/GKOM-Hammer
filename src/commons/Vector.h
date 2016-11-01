 /*
  * Vector.h
  *
  * 6.09.2016 r.
  *
  * Memotosh
  *
  */

#pragma once

#include <SFML/System/Vector2.hpp>

#include "commons/Direction.h"

template<class T>
    class Vector {
        public:
            Vector(T x=0, T y=0);
            Vector(const Vector& w);

            template<class W>
                explicit Vector(const sf::Vector2<W>& arg);
            template<class W>
                explicit Vector(const Vector<W>& arg);

            template<class W>
                explicit operator sf::Vector2<W>() const;

            template<class W>
                friend void swap(Vector& lhs, Vector& rhs);

            T length() const;
            T length_sqr() const;

            Vector<T>& normalize();
            Vector<T> normalize() const;

            T projection_length(const Vector<T>& target) const;
            Vector<T>& project(const Vector<T>& target);
            Vector<T> project(Vector<T> target) const;
            
            Vector<T> perpendicular() const;
            Vector<T>& rotate(double angle);
            Vector<T> rotate(double angle) const;
            
            Vector& operator=(Vector arg);
            Vector& operator+=(const Vector& arg);
            Vector& operator-=(const Vector& arg);

            template <class W>
                Vector& operator*=(const W scalar);
            template <class W>
                Vector& operator/=(const W scalar);

            T dot_product(const Vector<T>& other) const;

            T x;
            T y;
    };

typedef Vector<double> VectorD;
typedef Vector<int> VectorI;
typedef Vector<float> VectorF;
typedef Vector<unsigned> VectorU;

inline VectorI make_unit_vector(Direction dir);

template<class T>
    inline bool operator==(const Vector<T>& lhs, const Vector<T>& rhs);
template<class T>
    inline bool operator!=(const Vector<T>& lhs, const Vector<T>& rhs);
template<class T>
    inline Vector<T> operator+(Vector<T> lhs, const Vector<T>& rhs); 
template<class T>
    inline Vector<T> operator-(Vector<T> lhs, const Vector<T>& rhs); 
template<class T, class W>
    inline Vector<T> operator*(Vector<T> lhs, const W rhs); 
template<class T, class W>
    inline Vector<T> operator/(Vector<T> lhs, const W rhs); 

#include "Vector.hpp"
