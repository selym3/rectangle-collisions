#ifndef __RAY_TEST_HPP__
#define __RAY_TEST_HPP__

#include "test.hpp"

struct RayTest : public Test
{

    rectangle target;

    ray my_ray;
    double normal_length = 50;

    RayTest(const rectangle& r) :
        Test(),
        target { r }
    {
        auto size = this->window.getSize();
        my_ray = {
            // vec2d{ size.x / 2.0, size.y / 2.0 },
            vec2d { 0, 0 }, 
            vec2d { 0, 0 }
        };
    }

    void run(double dt)
    {
        my_ray.end = this->getMouse();

        auto collision = this->target.overlaps(my_ray);

        auto color = collision ? sf::Color::Red : sf::Color::Green;

        drawRectangle(target, color);

        if (collision) {
            auto normal_end = collision->hit + collision->normal * normal_length;
            drawLine(collision->hit, normal_end, color);
        }

        drawLine(my_ray.start, my_ray.end);
    }

};

#endif