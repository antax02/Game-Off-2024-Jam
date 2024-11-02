#include "animation.hpp"

Animation::Animation(int startRow, int frameWidth, int frameHeight, int numFrames, float speed)
    : startRow(startRow), frameWidth(frameWidth), frameHeight(frameHeight),
      numFrames(numFrames), speed(speed), timer(0), currentFrame(0) {
      textureRect = sf::IntRect(0, startRow * frameHeight, frameWidth, frameHeight);
}

void Animation::update(sf::Time deltaTime) {
    timer += deltaTime.asSeconds();
    if (timer >= speed) {
        timer = 0;
        currentFrame = (currentFrame + 1) % numFrames;
        textureRect.left = currentFrame * frameWidth;
    }
}

void Animation::applyToSprite(sf::Sprite& sprite) {
    textureRect.top = startRow * frameHeight;
    sprite.setTextureRect(textureRect);
}
