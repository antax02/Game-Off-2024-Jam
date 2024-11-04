#pragma once
#include <SFML/Graphics.hpp>
#include "entity.hpp"

class Player : public Entity {
    public:
        Player();
        void update(sf::Time dt) override;
        sf::IntRect getRect();
        sf::Vector2f getPosition();

    private:
        sf::Vector2f velocity;
};
