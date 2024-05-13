#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Game.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "My Program");

    Rectangle rectangle(sf::Vector2f(600, 350));

    std::vector<Circle> circles;
    circles.emplace_back(sf::Vector2f(200, 200));
    circles.emplace_back(sf::Vector2f(500, 400));
    circles.emplace_back(sf::Vector2f(800, 600));

    Game game;

    sf::Clock clock;
    float deltaTime = 0.0f;
    float moveSpeed = 200.0f; // Pixels per second

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Movement controls
        float moveX = 0.0f;
        float moveY = 0.0f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) moveY -= moveSpeed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) moveX -= moveSpeed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) moveY += moveSpeed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) moveX += moveSpeed * deltaTime;

        rectangle.move(moveX, moveY);

        // Check collision with circles
        game.checkCollision(rectangle, circles);

        game.updateTimer(deltaTime);

        window.clear();

        window.draw(rectangle.getShape());

        for (const auto& circle : circles) {
            window.draw(circle.getShape());
        }

        //timer on screen

        sf::Font font;
        if(font.loadFromFile("/Library/Fonts/Arial Unicode.ttf"))
        {
            sf::Text timerText("Time: " + std::to_string(static_cast<int>(game.isGameOver() ? 0.0f : game.getTimer())), font, 24);
            timerText.setPosition(10.f, 10.f);
            window.draw(timerText);
        }
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Game.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "My Program");

    Rectangle rectangle(sf::Vector2f(600, 350));

    std::vector<Circle> circles;
    circles.emplace_back(sf::Vector2f(200, 200));
    circles.emplace_back(sf::Vector2f(500, 400));
    circles.emplace_back(sf::Vector2f(800, 600));

    Game game;

    sf::Clock clock;
    float deltaTime = 0.0f;
    float moveSpeed = 200.0f; // Pixels per second

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Movement controls
        float moveX = 0.0f;
        float moveY = 0.0f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) moveY -= moveSpeed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) moveX -= moveSpeed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) moveY += moveSpeed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) moveX += moveSpeed * deltaTime;

        rectangle.move(moveX, moveY);

        // Check collision with circles
        game.checkCollision(rectangle, circles);

        game.updateTimer(deltaTime);

        window.clear();

        window.draw(rectangle.getShape());

        for (const auto& circle : circles) {
            window.draw(circle.getShape());
        }

        //timer on screen

        sf::Font font;
        if(font.loadFromFile("/Library/Fonts/Arial Unicode.ttf"))
        {
            sf::Text timerText("Time: " + std::to_string(static_cast<int>(game.isGameOver() ? 0.0f : game.getTimer())), font, 24);
            timerText.setPosition(10.f, 10.f);
            window.draw(timerText);
        }

        window.display();

        //is game over

        if (game.isGameOver())
        {
            sf::sleep(sf::seconds(2));
            window.close();
        }
    }

    return 0;
}
        window.display();

        //is game over

        if (game.isGameOver())
        {
            sf::Text collectedText("Good Job! You collected " + std::to_string(static_cast<int>(game.getCounter() )) " red dots!", font, 24);
            sf::sleep(sf::seconds(2));
            window.close();
        }
    }

    return 0;
}
