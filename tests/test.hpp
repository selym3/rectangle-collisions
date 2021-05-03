#ifndef __TEST_HPP__
#define __TEST_HPP__

#include <SFML/Graphics.hpp>
#include "../lib/rectangle.hpp"
#include "render_rect.hpp"

class Test
{
    vec2d mouse;

protected:
    sf::RenderWindow window;

    rectangle target;
    sf::Color color;

public:
    Test(int width, int height, const rectangle& target, const sf::Color& color=sf::Color::Red) :
        window {
            sf::VideoMode(width, height),
            "Rectangle Collision Test",
            sf::Style::None
        },
        color { color },
        target { target }
    {
        updateMouse();
    }

    Test(const rectangle& target, const sf::Color& color=sf::Color::Red) :
        Test(600, 600, target, color)
    {
    }
    
    virtual ~Test()=default;

    const vec2d& getMouse() const { return mouse; }
    bool isRunning() const { return window.isOpen(); }
    
    void execute() 
    {
        // Event Handling
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } 
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }

        window.clear(sf::Color(107, 151, 255));
        updateMouse();

        run();

        window.draw(render_rect{target, color});
        
        window.display();
    }

    void drawLine(const vec2d& start, const vec2d& end)
    {
        sf::Vertex line[] = 
        {
            sf::Vertex(sf::Vector2f(start.x, start.y)),
            sf::Vertex(sf::Vector2f(end.x, end.y))
        };

        window.draw(line, 2, sf::Lines);
    }


    virtual void run() {}

private:

    void updateMouse() 
    {
        mouse = { 
            (double) sf::Mouse::getPosition(window).x, 
            (double) sf::Mouse::getPosition(window).y
        };
    }

};


#endif