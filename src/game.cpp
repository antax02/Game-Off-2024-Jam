#include "game.hpp"
#include <cmath>

Game::Game() : window(sf::VideoMode(800, 600), "Game"), level(32) { }

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
    float playerCenterX = player.getPosition().x + player.getRect().width / 2.0f;
    float playerCenterY = player.getPosition().y + player.getRect().height / 2.0f;
    float viewCenterX = std::floor(playerCenterX);
    float viewCenterY = std::floor(playerCenterY);
    view.setCenter(viewCenterX, viewCenterY);

    view.setCenter(player.getPosition());

    window.setView(view);
    window.clear();
    window.draw(level);
    window.draw(player);
    window.display();
}
