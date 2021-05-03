#include "../lib/ray.hpp"

vec2d ray::direction() const
{
    return end - start;
}

vec2d ray::operator()(double t) const
{
    return start + direction() * t; 
}
