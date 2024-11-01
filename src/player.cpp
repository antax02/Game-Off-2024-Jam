#include "player.hpp"
#include "input_manager.hpp"

Player::Player() {
    // Load texture, set sprite, initial position, etc.
}

void Player::update(sf::Time deltaTime) {
    // Update player position, animations, etc.
}

void Player::handleInput(const InputManager& input, sf::Time deltaTime) {
    float speed = 100.0f; // Base movement speed

    // Scale movement based on deltaTime
    if (input.isKeyPressed(sf::Keyboard::W)) position.y -= speed * deltaTime.asSeconds();
    if (input.isKeyPressed(sf::Keyboard::S)) position.y += speed * deltaTime.asSeconds();
    if (input.isKeyPressed(sf::Keyboard::A)) position.x -= speed * deltaTime.asSeconds();
    if (input.isKeyPressed(sf::Keyboard::D)) position.x += speed * deltaTime.asSeconds();

    sprite.setPosition(position);
}
