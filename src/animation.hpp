#pragma once
#include <SFML/Graphics.hpp>

class Animation {
public:
    Animation(int startRow, int frameWidth, int frameHeight, int numFrames, float speed);

    void update(sf::Time deltaTime);
    void applyToSprite(sf::Sprite& sprite);

private:
    int startRow;
    int frameWidth;
    int frameHeight;
    int numFrames;
    float speed;
    float timer;
    int currentFrame;
    sf::IntRect textureRect;
};
