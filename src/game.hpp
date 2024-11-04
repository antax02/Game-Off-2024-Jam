#pragma once
#include <SFML/Graphics.hpp>
#include "player.hpp"

class Game {
    public:
        Game();
        void run();
        void update(sf::Time dt);
        void render();

    private:
        sf::RenderWindow window;
        Player player;
};
