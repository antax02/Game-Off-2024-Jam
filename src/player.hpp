#pragma once
#include <SFML/Graphics.hpp>
#include "entity.hpp"

class Player : public Entity {
    public:
        Player();
        void update(sf::Time dt) override;

    private:
        sf::Vector2f velocity;
};
