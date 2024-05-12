#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Circle {
public:
    Circle(sf::Vector2f position) : position(position) {
        shape.setRadius(10);
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(position);
    }

    sf::Vector2f getPosition() const { return position; }
    sf::CircleShape getShape() const { return shape; }

    bool operator==(const Circle& other) const {
        return position == other.position;
    }

private:
    sf::Vector2f position;
    sf::CircleShape shape;
};
