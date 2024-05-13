#pragma once

#include "Shape.h"
#include <SFML/Graphics.hpp>
#include <iostream>


class Circle: public Shape{
public:
    Circle(sf::Vector2f position)  {
        this -> position = position;
        shape.setRadius(10);
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(position);
    }

    sf::CircleShape getShape() const { return shape; }

    bool operator==(const Circle& other) const {
        return position == other.position;
    }

private:
    sf::CircleShape shape;
};