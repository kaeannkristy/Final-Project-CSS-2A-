#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Game.h"

int main() {
    // Sets the size of the display window and titles it "Collect the Dots"
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Collect the Dots");

    // Sets the size and position of the rectangle
    Rectangle rectangle(sf::Vector2f(600, 350));

    // Creates a Circle vector and adds a new object to the vector using emplace_back and specifies their position
    std::vector<Circle> circles;
    circles.emplace_back(sf::Vector2f(200, 200));
    circles.emplace_back(sf::Vector2f(500, 400));
    circles.emplace_back(sf::Vector2f(800, 600));
    circles.emplace_back(sf::Vector2f(300, 300));
    circles.emplace_back(sf::Vector2f(700, 700));
    circles.emplace_back(sf::Vector2f(750, 600));

    /// Loads font for displaying text
    sf::Font fonty;
    if (!fonty.loadFromFile("./Arial Unicode.ttf"))
    {
        std::cerr << "Error loading font.\n";
        return -2;
    }

    // Creates text object for displaying game over message
    sf::Text mytext;
    mytext.setFont(fonty);
    mytext.setCharacterSize(100);
    mytext.setFillColor(sf::Color::White);
    mytext.setPosition(400, 0);
    mytext.setOrigin(mytext.getLocalBounds().left / 2.0, mytext.getLocalBounds().top / 2.0);

    // Initializes the game instance
    Game game;

    sf::Clock clock;
    float deltaTime = 0.0f;
    float moveSpeed = 200.0f; // Pixels per second

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        // Handles window events, such as closing the window
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Keyboard controls for moving the rectangle
        float moveX = 0.0f;
        float moveY = 0.0f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) moveY -= moveSpeed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) moveX -= moveSpeed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) moveY += moveSpeed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) moveX += moveSpeed * deltaTime;

        // Moves the rectangle based on user input
        rectangle.move(moveX, moveY, window.getSize().x, window.getSize().y);

        // Checks for collisions with circles
        game.checkCollision(rectangle, circles);

        // Updates the game timer
        game.updateTimer(deltaTime);

        // Clears the window for drawing
        window.clear();

        // Draws the rectangle shape onto the window
        window.draw(rectangle.getShape());

        // Draws the circle shapes onto the window
        for (const auto& circle : circles) {
            window.draw(circle.getShape());
        }

        // Displays timer on screen

        sf::Font font;

        // Draws the game timer on the screen
        if (font.loadFromFile("./Arial Unicode.ttf"))
        {
            sf::Text timerText("Time: " + std::to_string(static_cast<int>(game.isGameOver() ? 0.0f : game.getTimer())), font, 24);
            timerText.setPosition(10.f, 10.f);
            window.draw(timerText);
        }

        // Displays the window contents
        window.display();

        // Displays game over message when game has ended
        if (game.isGameOver())
        {
            window.clear();
            mytext.setString(("Good Job! You collected " + std::to_string(game.getCounter()) + " red dots!"));
            mytext.setCharacterSize(50);
            mytext.setPosition(10.f, 10.f);
            window.draw(mytext);
            window.display();
            sf::sleep(sf::seconds(5));
            window.close();
        }
    }

    return 0;
}