#include "game.hpp"

Game::Game() : window(sf::VideoMode(800, 600), "Game") { }

void Game::run() {
    sf::Clock clock;
    while(window.isOpen()) {
        update(clock.restart());
        render();
    }
}

void Game::update(sf::Time dt) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::render() {
    window.clear();
    window.display();
}
