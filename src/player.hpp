#pragma once
#include "entity.hpp"
#include "input_manager.hpp"
#include <SFML/Graphics.hpp>

class Player : public Entity {
public:
    Player();
    void update(sf::Time deltaTime) override;
    void handleInput(const InputManager& input, sf::Time deltaTime);
};
