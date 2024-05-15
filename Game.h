#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Rectangle.h"
#include "Circle.h"

// Game class handles collision detection, timer updates, and game over conditions
class Game {
public:
    Game() : counter(0) { gameover = false; }

    // Checks collision between the rectangle and circles, updating the score
    void checkCollision(Rectangle& rectangle, std::vector<Circle>& circles) {
        for (auto it = circles.begin(); it != circles.end();) {
            if (rectangle.getShape().getGlobalBounds().intersects(it->getShape().getGlobalBounds())) {
                it = circles.erase(it);
                counter++;
            }
            else {
                ++it;
            }
        }
    }

    // Getter for the score counter
    int getCounter() const { return counter; }

    // Checks if the game is over
    bool isGameOver() const { return gameover; }

    // Updates the game timer
    void updateTimer(float deltaTime)
    {
        if (!gameover)
        {
            timer -= deltaTime;
            if (timer <= 0.0f)
            {
                timer = 0.0f;
                gameover = true;
               // std::cout << "Good job! You collected " << counter << " red dots!" << std::endl;
            }
        }
    }

    // Getter for the game timer
    float getTimer() const { return timer; }

private:
    // Counter for collected red dots
    int counter;

    // Timer for game duration
    float timer = 11.0f;

    // Flag indicating game over
    bool gameover;
};