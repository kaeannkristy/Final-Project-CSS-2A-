#pragma once
#include "Shape.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Rectangle : public Shape {
public:
    Rectangle(sf::Vector2f position) {
        this -> position = position;
        shape.setSize(sf::Vector2f(100, 100));
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(position);
    }

    sf::RectangleShape getShape() const { return shape; }

    void move(float x, float y) {
        position += sf::Vector2f(x, y);
        shape.setPosition(position); // Update the position of the shape
    }

    bool operator==(const Rectangle& other) const {
        return position == other.position;
    }

private:
    sf::RectangleShape shape;
};