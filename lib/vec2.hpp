#ifndef __VEC2_HPP__
#define __VEC2_HPP__

/////////////////////////
// EXTRA FUNCTIONALITY //
/////////////////////////
#define EXTRA_TYPDEFS
#define IOSTREAM_OVERLOAD

#ifdef IOSTREAM_OVERLOAD
#include <ostream>
#endif


template <typename Number>
struct vec2
{
    //////////
    // DATA //
    //////////

    Number x, y;

    //////////////////
    // CONSTRUCTORS //
    //////////////////

    vec2(const Number& x, const Number& y) :
        x { x }, 
        y { y }
    {
    }

    vec2(const Number& x) :
        vec2(x, x)
    {
    }

    vec2() :
        vec2(0)
    {
    }

    ///////////////
    // OPERATORS //
    ///////////////

    // Overloads with type Number are not provided 
    // because Numbers can be constructed into vec2s

    vec2& operator+=(const vec2& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    vec2& operator-=(const vec2& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    vec2& operator*=(const vec2& rhs)
    {
        x *= rhs.x;
        y *= rhs.y;
        return *this;
    }

    vec2& operator/=(const vec2& rhs)
    {
        x /= rhs.x;
        y /= rhs.y;
        return *this;
    }

    friend vec2 operator+(vec2 lhs, const vec2& rhs)
    {
        return lhs += rhs;
    }

    friend vec2 operator-(vec2 lhs, const vec2& rhs)
    {
        return lhs -= rhs;
    }

    friend vec2 operator*(vec2 lhs, const vec2& rhs)
    {
        return lhs *= rhs;
    }

    friend vec2 operator/(vec2 lhs, const vec2& rhs)
    {
        return lhs /= rhs;
    }

    ///////////////////////
    // IOSTREAM OVERLOAD //
    ///////////////////////

    #ifdef IOSTREAM_OVERLOAD
    friend std::ostream& operator<<(std::ostream& os, const vec2& v)
    {
        return os << "( " << v.x << ", " << v.y << " )";
    }
    #endif

};

//////////////
// TYPEDEFS //
//////////////

#ifdef EXTRA_TYPDEFS
using vec2d = vec2<double>;
using vec2f = vec2<float>;
using vec2i = vec2<int>;
#endif

#endif