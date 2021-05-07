/*
g++ -std=c++17 -c src/ray.cpp -o bin/ray.o
g++ -std=c++17 -c src/rectangle.cpp -o bin/rectangle.o
g++ -std=c++17 main.cpp bin/*.o -lsfml-graphics -lsfml-window -lsfml-system -o main
*/

#include <iostream>
#include "tests/tests.hpp"

int main(int argc, char** argv)
{

    /*
    RayTest test {
        rectangle { 
            { 30, 100 }, 
            { 40, 25 } 
        }
    };
    */

    CollisionTest test {
        { 
            rectangle{{300,100}, {40, 25}},
            rectangle{{400, 400}, {100, 150}}
        }
    };

    std::cout << "Opening...\n";
    while (test.isRunning()) {
        test.execute();
    }
    std::cout << "Closing...\n";

}
