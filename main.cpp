#include <SFML/Graphics.hpp>
#include <vector>

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

class Rectangle {
public:
    Rectangle(sf::Vector2f position) : position(position) {
        shape.setSize(sf::Vector2f(100, 100));
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(position);
    }

    sf::Vector2f getPosition() const { return position; }
    sf::RectangleShape getShape() const { return shape; }

    void move(float x, float y) {
        position += sf::Vector2f(x, y);
        shape.setPosition(position); // Update the position of the shape
    }

    bool operator==(const Rectangle& other) const {
        return position == other.position;
    }

private:
    sf::Vector2f position;
    sf::RectangleShape shape;
};

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

private:
    int counter;
};

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

        window.clear();

        window.draw(rectangle.getShape());

        for (const auto& circle : circles) {
            window.draw(circle.getShape());
        }

        window.display();
    }

    return 0;
}