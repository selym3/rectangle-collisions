#ifndef __TEST_HPP__
#define __TEST_HPP__

#include <SFML/Graphics.hpp>
#include "../lib/rectangle.hpp"
#include "render_rect.hpp"
#include "timer.hpp"

class Test
{
protected:
    sf::RenderWindow window;
    Timed::Timer stopwatch;

public:
    //////////////////
    // CONSTRUCTORS //
    //////////////////

    Test(int width, int height) :
        window {
            sf::VideoMode(width, height),
            "Rectangle Collision Test",
            sf::Style::None
        },
        stopwatch {}
    {
    }

    Test() :
        Test(600, 600)
    {
    }
    
    virtual ~Test()=default;

public:
    //////////////////
    // OVERIDDABLES //
    //////////////////

    virtual void run(double dt) {}
    virtual void handleKey(const sf::Keyboard::Key& key) {}
    virtual sf::Color getBackground() { return sf::Color(107, 151, 255); }

public:
    /////////////
    // HELPERS //
    /////////////

    vec2d getMouse() const 
    {
        return { 
            (double) sf::Mouse::getPosition(window).x, 
            (double) sf::Mouse::getPosition(window).y
        };
    }

    const bool getKey(const sf::Keyboard::Key& key) const
    {
        return sf::Keyboard::isKeyPressed(key);
    }
    
public:
    ////////////////////
    // MAIN FUNCTIONS //
    ////////////////////

    bool isRunning() const 
    { 
        return window.isOpen(); 
    }
    
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
                handleKey(event.key.code);
            }
        }

        const double dt = this->stopwatch.reset();

        window.clear(this->getBackground());
        run(dt);
        window.display();
    }

public:
    ////////////////////
    // RENDER HELPERS //
    ////////////////////

    void drawLine(const vec2d& start, const vec2d& end, const sf::Color& color=sf::Color::White)
    {
        sf::Vertex line[] = 
        {
            sf::Vertex(sf::Vector2f(start.x, start.y), color),
            sf::Vertex(sf::Vector2f(end.x, end.y), color)
        };

        window.draw(line, 2, sf::Lines);
    }

    void drawRectangle(const rectangle& r, const sf::Color& color=sf::Color::White)
    {
        window.draw(render_rect{r, color});
    }

};


#endif