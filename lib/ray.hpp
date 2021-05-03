#ifndef __RAY_HPP__
#define __RAY_HPP__

#include "vec2.hpp"

struct ray
{
    vec2d start, end;

    vec2d operator()(double t) const;
    vec2d direction() const;

};

#endif