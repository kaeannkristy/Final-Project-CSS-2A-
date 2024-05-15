#pragma once

#include "Shape.h"
#include <SFML/Graphics.hpp>
#include <iostream>

// Circle class represents circles in the game
class Circle : public Shape {
public:
    // Constructor initializes circle with specified position and color
    Circle(sf::Vector2f position) {
        this->position = position;
        shape.setRadius(10);
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(position);
    }

    // Getter for the circle shape
    sf::CircleShape getShape() const { return shape; }

    // Overloaded operator for comparing circles based on position
    bool operator==(const Circle& other) const {
        return position == other.position;
    }

private:
    sf::CircleShape shape;// Circle shape object
};