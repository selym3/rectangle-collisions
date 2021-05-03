#include "../lib/rectangle.hpp"

bool rectangle::overlaps(const vec2d& p) const
{   
    auto extent = this->position + this->size; 

    return (p.x >= position.x && p.y >= position.y) &&
        (p.x < extent.x && p.y < extent.y);
}

bool rectangle::overlaps(const rectangle& r) const
{
    auto extent1 = position + size;
    auto extent2 = r.position + r.size;

    return (position.x < extent2.x && r.position.x < extent1.x) &&
        (position.y < extent2.y && r.position.y < extent1.y);

}

std::optional<rectangle::ray_collision> rectangle::overlaps(const ray& r, bool extend_infinitely) const
{
    // Calculate where along the axes of the 
    // rectangle the ray hits as a percentage / time
    // value of the ray

    const auto direction = r.direction();

    auto t_near = (position - r.start) / direction;
    auto t_far = (position + size - r.start) / direction;

    // if the ray is oriented a certain way, it may think these 
    // values are backwards
    if (t_near.x > t_far.x) std::swap(t_near.x, t_far.x);
    if (t_near.y > t_far.y) std::swap(t_near.y, t_far.y);

    // If these conditions are not met, 
    // the ray doesn't intersect
    if (t_near.x > t_far.y || t_near.y > t_far.x) 
        return std::nullopt;

    // Calculate the actual times to the 
    // near and far collisions

    auto t_hit_near = std::max(t_near.x, t_near.y);
    auto t_hit_far = std::min(t_far.x, t_far.y);

    // if the collision is entirely behind the rectangle,
    // reject it as well
    if (t_hit_far < 0) 
        return std::nullopt;

    // if the collision extends past the end point of the ray,
    // and we don't want to extend infinitely, reject this as well
    if (!extend_infinitely && t_hit_near > 1)
        return std::nullopt;

    // If the hit point can be calculated, calculate it
    vec2d hit_point = r(t_hit_near);

    // Determine the normal direction of the hit
    // by looking at where it hit the axes
    vec2d normal_dir = { 0, 0 };

    if (t_near.x > t_near.y)
        if (direction.x < 0)
            normal_dir = { +1, 0 };
        else
            normal_dir = { -1, 0 };
    else if (t_near.x < t_near.y)
        if (direction.y < 0)
            normal_dir = { 0, +1 };
        else
            normal_dir = { 0, -1 };
    
    return rectangle::ray_collision{
        hit_point,
        normal_dir,
        t_hit_near
    };

}