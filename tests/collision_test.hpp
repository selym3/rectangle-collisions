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
            target.velocity = (mouse - target.center()) * dt;
        
        for (int i = 1;i < rects.size(); ++i) 
            if (target.collision(rects[i], dt))
                target.velocity = 0;

        target.position += target.velocity;


        for (const auto& rectangle : rects)
            drawRectangle(rectangle);

    }


};


#endif