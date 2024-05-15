#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

// Base class for shapes 

class Shape {
public:

    // Default constructor
    Shape()  {}

    // Getter for the position of the shape
    sf::Vector2f getPosition() const { return position; }

   
protected:
    // Position of the shape
    sf::Vector2f position;
};