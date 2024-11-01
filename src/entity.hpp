#pragma once
#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable {
public:
    virtual void update(sf::Time deltaTime) = 0; // Force derived classes to implement update

protected:
    sf::Vector2f position;
    sf::Sprite sprite;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(sprite, states);
    }
};
