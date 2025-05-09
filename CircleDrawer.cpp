#include "CircleDrawer.h"

    CircleDrawer::CircleDrawer(float radius, sf::Color color, sf::Vector2f position, float movementSpeed)
    {
        circle.setRadius(radius);
        circle.setFillColor(color);
        circle.setPosition(position);
        speed = movementSpeed;
    };

    sf::Vector2f CircleDrawer::getPosition()
    {
        return circle.getPosition();
    }

    void CircleDrawer::setPosition(sf::Vector2f position)
    {
        circle.setPosition(position);
    }

    void CircleDrawer::update(float deltaTime)
    {
        sf::Vector2f movement(0.f, 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            movement.y -= speed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            movement.y += speed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            movement.x -= speed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            movement.x += speed * deltaTime;

        circle.move(movement);
    }

    sf::Rect<float> CircleDrawer::getBounds()
    {
        return circle.getGlobalBounds();
    }

    sf::CircleShape circle;
    float speed;

    void CircleDrawer::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(circle, states);
    }
