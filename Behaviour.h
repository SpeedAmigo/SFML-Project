//
// Created by filip on 2.05.2025.
//

#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H
#include "SFML/Graphics/Drawable.hpp"

class Behaviour : sf::Drawable
{
    public:
        virtual void start();
        virtual void update(float deltaTime);
};

#endif //BEHAVIOUR_H
