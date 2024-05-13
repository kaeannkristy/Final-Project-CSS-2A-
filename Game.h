#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Game {
public:
    Game() : counter(0) {}

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

    int getCounter() const { return counter; }
    bool isGameOver() const {return gameover;}

    void updateTimer(float deltaTime)
    {
        if (!gameover)
        {
            timer -= deltaTime;
            if(timer <= 0.0f)
            {
                timer = 0.0f;
                gameover = true;
                std::cout << "Good job! You collected " << counter << " red dots!" << std::endl;
            }
        }
    }

    float getTimer() const {return timer;}

private:
    int counter;
    float timer = 10.0f;
    bool gameover;
};