#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>

class Level : public sf::Drawable {
public:
    Level(int tileSize);

private:
    sf::Image image;
    sf::Sprite tiles;
    sf::IntRect textureRect;
    int tileSize;
    int tileCount;
    static std::unordered_map<sf::Uint32, int> colorKey;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
