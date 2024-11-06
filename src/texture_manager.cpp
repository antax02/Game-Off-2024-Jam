#include "texture_manager.hpp"

std::unordered_map<std::string, sf::Texture> TextureManager::textures;

sf::Texture& TextureManager::getTexture(const std::string& filename) {
    // Load texture only if it's not already loaded
    if (textures.find(filename) == textures.end()) {
        sf::Texture texture;
        texture.loadFromFile(filename);
        textures[filename] = std::move(texture);
    }
    return textures[filename];
}

