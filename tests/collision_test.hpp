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

    }


};


#endif