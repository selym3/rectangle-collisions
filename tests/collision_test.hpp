#ifndef __COLLISION_TEST_HPP__
#define __COLLISION_TEST_HPP__

#include "test.hpp"

#include <vector>

// TODO: finsish collision test 

struct CollisionTest : public Test
{

    std::vector<rectangle> rects;

    CollisionTest(const std::vector<rectangle> rects) :
        Test(),
        rects { rects }
    {
    }

    void run(double dt)
    {
        const auto mouse = getMouse();
        auto& target = rects.at(0);

        if (getMouseButton(sf::Mouse::Left))
            target.velocity = (mouse - target.center()).norm() * 100 * dt;
        
        for (int i = 1;i < rects.size(); ++i)  {
            auto collision = target.collision(rects[i], dt);

            if (collision) {
                drawCollision(*collision, sf::Color::Green);

                target.velocity += 
                    collision->normal * 
                    vec2d { std::abs(target.velocity.x), std::abs(target.velocity.y) } * 
                    (1-collision->time);
                
            }
        }

        target.position += target.velocity;

        for (const auto& rectangle : rects)
            drawRectangle(
                rectangle, 
                (&rectangle == &target) ? 
                    sf::Color::Red : 
                    sf::Color::White
            );

    }


};


#endif