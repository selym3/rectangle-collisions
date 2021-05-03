#ifndef __RENDER_RECT_HPP__
#define __RENDER_RECT_HPP__

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>>

#include "../lib/rectangle.hpp"

// Example usage of the rectangle

struct render_rect : sf::Drawable
{
    rectangle shape;
    sf::Color color;

    render_rect(const rectangle& rect, const sf::Color& color) :
        shape { rect },
        color { color }
    {
    }

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        sf::RectangleShape rectangle;
        rectangle.setSize({ (float)shape.size.x, (float)shape.size.y });
        rectangle.setPosition({ (float)shape.position.x, (float)shape.position.y });
        rectangle.setFillColor(color);

        target.draw(rectangle, states);
    }

};

#endif