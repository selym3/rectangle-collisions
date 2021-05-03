#ifndef __POINT_TEST_HPP__
#define __POINT_TEST_HPP__

#include "test.hpp"

struct PointTest : public Test
{

    PointTest(const rectangle& r) :
        Test(r)
    {
    }

    void run()
    {
        auto touchesMouse = this->target.overlaps(this->getMouse()); 

        this->color = touchesMouse ?
            sf::Color::Red :
            sf::Color::Green;
    }

};

#endif