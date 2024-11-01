#include "game.hpp"
#include "player.hpp"

Game::Game() : window(sf::VideoMode(800, 600), "Game Window") {
    // Initialize game objects here (e.g., player)
}

void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        processEvents();
        update(clock.restart());
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        // Pass event to InputManager
        inputManager.processEvent(event);
    }
}

void Game::update(sf::Time deltaTime) {
    // Update game objects here (e.g., player.update(deltaTime);)

}

void Game::render() {
    window.clear();
    // Draw game objects here (e.g., window.draw(player);)
    window.display();
}
