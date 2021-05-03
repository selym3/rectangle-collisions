#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include "vec2.hpp"
#include "ray.hpp"

#include <optional>

struct rectangle
{
    // using point = vec2d;

    vec2d position;
    vec2d size;

    bool overlaps(const vec2d& point) const;
    bool overlaps(const rectangle& rect) const;

    struct ray_collision
    {
        vec2d hit;
        vec2d normal;
        double time;
    };

    std::optional<ray_collision> overlaps(const ray& ray, bool extend_infinitely = false) const;

};

#endif