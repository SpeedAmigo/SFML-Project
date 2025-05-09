#include <SFML/Graphics.hpp>
#include "CircleDrawer.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");

    CircleDrawer myCircle(50, sf::Color::White, sf::Vector2f(300, 300), 200.f);
    sf::Clock clock;

    auto *rectangle = new sf::RectangleShape();

    rectangle->setSize(sf::Vector2f(200, 100));
    rectangle->setFillColor(sf::Color::Red);
    rectangle->setPosition(sf::Vector2f(300, 000));

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();


        sf::Vector2f lastPosition = myCircle.getPosition();
        myCircle.update(deltaTime);

        if (myCircle.getPosition().y > 400.f)
        {
            myCircle.setPosition(sf::Vector2f(300, 300));
        }


        if (rectangle != nullptr && rectangle->getGlobalBounds().findIntersection(myCircle.getBounds()))
        {
            myCircle.setPosition(lastPosition);
        }

        if (rectangle)
        {
            rectangle->move(sf::Vector2f(0.f, 50.f * deltaTime));

            if (rectangle->getPosition().y > 300.f)
            {
                delete rectangle;
                rectangle = nullptr;
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);

        if (rectangle)
        {
            window.draw(*rectangle);
        }

        window.draw(myCircle);

        // end the current frame
        window.display();
    }
};