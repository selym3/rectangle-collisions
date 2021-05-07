#ifndef __POINT_TEST_HPP__
#define __POINT_TEST_HPP__

#include "test.hpp"

struct PointTest : public Test
{
    rectangle r;

    PointTest(const rectangle& r) :
        Test(),
        r { r } 
    {
    }

    void run(double dt)
    {
        auto touchesMouse = r.overlaps(this->getMouse()); 

        auto color = touchesMouse ?
            sf::Color::Red :
            sf::Color::Green;
        
        drawRectangle(r, color);
    }

};

#endif