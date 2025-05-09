//
// Created by filip on 1.05.2025.
//

#ifndef CIRCLEDRAWER_H
#define CIRCLEDRAWER_H
#include <SFML/Graphics.hpp>

class CircleDrawer : public sf::Drawable
{
public:
    CircleDrawer(float radius, sf::Color color, sf::Vector2f position, float movementSpeed);
    void update(float deltaTime);
    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f position);
    sf::Rect<float> getBounds();

private:
    sf::CircleShape circle;
    float speed = 100.f;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
#endif //CIRCLEDRAWER_H
