#include "game.hpp"
#include <iostream>

Game::Game() : window(sf::VideoMode(800, 600), "Game") { }

void Game::run() {
    sf::Clock clock;
    view = window.getDefaultView();
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
    player.update(dt);
}

void Game::render() {
    view.setCenter(player.getPosition().x + player.getRect().width / 2.0f, player.getPosition().y + player.getRect().height / 2.0f);
    window.setView(view);
    window.clear();
    window.draw(player);
    window.display();
}
