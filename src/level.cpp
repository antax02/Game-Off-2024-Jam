#include "level.hpp"
#include "texture_manager.hpp"

std::unordered_map<sf::Uint32, int> Level::colorKey;

Level::Level(int tileSize) : tileSize(tileSize) {
    image.loadFromFile("../assets/map.png");
    // Get a non-const reference to the texture
    sf::Texture& texture = TextureManager::getTexture("../assets/tilesheet.png");

    // Disable texture smoothing
    texture.setSmooth(false);

    // Set the texture to the sprite
    tiles.setTexture(texture);

    textureRect = sf::IntRect(0, 0, tileSize, tileSize);

    colorKey[sf::Color(255, 0, 0).toInteger()] = 0;
    colorKey[sf::Color(0, 255, 0).toInteger()] = 1;
    colorKey[sf::Color(0, 0, 255).toInteger()] = 2;
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::Sprite tileSprite;
    tileSprite.setTexture(*tiles.getTexture());
    tileSprite.setTextureRect(textureRect);

    sf::IntRect localTextureRect = textureRect;

    for (unsigned y = 0; y < image.getSize().y; y++) {
        for (unsigned x = 0; x < image.getSize().x; x++) {
            sf::Color pixelColor = image.getPixel(x, y);
            sf::Uint32 colorKeyInt = pixelColor.toInteger();

            auto it = colorKey.find(colorKeyInt);
            if (it != colorKey.end()) {
                int tileIndex = it->second;
                localTextureRect.left = tileIndex * tileSize;
                tileSprite.setTextureRect(localTextureRect);
                // Align positions to integer values
                tileSprite.setPosition(static_cast<float>(x * tileSize), static_cast<float>(y * tileSize));
                target.draw(tileSprite, states);
            }
        }
    }
}
