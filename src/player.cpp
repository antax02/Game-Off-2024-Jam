#include "player.hpp"
#include "texture_manager.hpp"
#include <iostream>

Player::Player() {
    sprite.setTexture(TextureManager::getTexture("../assets/player.png"));
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    sprite.setPosition(position);
}

void Player::update(sf::Time dt) {
    velocity.x = velocity.y = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        velocity.y = -100;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        velocity.y = 100;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        velocity.x = -100;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            velocity.x = 100;
    }
    
    position += velocity * dt.asSeconds();
    sprite.setPosition(position);
}

sf::IntRect Player::getRect() {
    return sprite.getTextureRect();
}

sf::Vector2f Player::getPosition() {
    return position;
}
