
#pragma once
#include "Shape.h"
#include <SFML/Graphics.hpp>
#include <iostream>

// Rectangle class represents rectangles in the game
class Rectangle : public Shape
{
public:
    // Constructor initializes rectangle with specified position, size, and color
    Rectangle(sf::Vector2f position)
    {
        this->position = position;
        shape.setSize(sf::Vector2f(100, 100));
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(position);
    }
    
    // Getter for the rectangle shape
    sf::RectangleShape getShape() const { return shape; }

    // Moves the rectangle by the specified amount
    void move(float x, float y, float winx, float winy)
    {
        position += sf::Vector2f(x, y);
        if (position.x < 0)
            position.x = 0;
        if (position.x > winx - 100)
            position.x = winx - 100;
        if (position.y < 0)
            position.y = 0;
        if (position.y > winy - 100)
            position.y = winy - 100;
        shape.setPosition(position); // Updates the position of the shape
    }

    // Overloaded operator for comparing rectangles based on position
    bool operator==(const Rectangle& other) const
    {
        return position == other.position;
    }

private:
    sf::RectangleShape shape;// Rectangle shape object
};
