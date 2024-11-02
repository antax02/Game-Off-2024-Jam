#pragma once
#include "entity.hpp"
#include "input_manager.hpp"
#include "texture_manager.hpp"
#include "animation.hpp"

class Player : public Entity {
public:
    Player();
    void update(sf::Time deltaTime) override;
    void handleInput(const InputManager& input, sf::Time deltaTime);

private:
    Animation idleAnimation;
    Animation walkRightAnimation;
    Animation walkLeftAnimation;
    Animation walkUpAnimation;
    Animation walkDownAnimation;

    Animation* currentAnimation;
};
