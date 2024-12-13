#pragma once
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "level.hpp"

class Game {
    public:
        Game();
        void run();
        void update(sf::Time dt);
        void render();

    private:
        sf::RenderWindow window;
        sf::View view;
        Player player;
        Level level;
};
