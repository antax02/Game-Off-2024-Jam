#pragma once
#include <SFML/Graphics.hpp>
#include "input_manager.hpp"
#include "player.hpp"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    sf::RenderWindow window;
    InputManager inputManager;
    Player player;
    // Add game objects here later (e.g., Player player;)
};
