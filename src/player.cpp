#include "player.hpp"
#include "texture_manager.hpp"
#include <cmath>

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

    double velocityMagnitude = std::sqrt(std::pow(velocity.x, 2) + std::pow(velocity.y, 2));

    sf::Vector2f velocityUnit;
    if (velocityMagnitude != 0) {
        velocityUnit.x = velocity.x / velocityMagnitude;
        velocityUnit.y = velocity.y / velocityMagnitude;
    } else {
        velocityUnit.x = 0;
        velocityUnit.y = 0;
    }

    velocity.x = velocityUnit.x * 100;
    velocity.y = velocityUnit.y * 100;

    //velocity.x = std::clamp(velocity.x, -100, 100);
    //velocity.y = std::clamp(velocity.y, -100, 100);
    
    position += velocity * dt.asSeconds();
    sprite.setPosition(position);
}

sf::IntRect Player::getRect() {
    return sprite.getTextureRect();
}

sf::Vector2f Player::getPosition() {
    return position;
}

void Player::setPosition(sf::Vector2f pos) {
    position = pos;
}
