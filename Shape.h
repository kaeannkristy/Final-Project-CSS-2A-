#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>


class Shape {
public:
    //Shape(sf::Vector2f position) : position(position) {
    Shape()  {

    }

    sf::Vector2f getPosition() const { return position; }

   

protected:
    sf::Vector2f position;
};