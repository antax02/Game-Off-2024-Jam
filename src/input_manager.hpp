#pragma once
#include <SFML/Window.hpp>
#include <unordered_map>

class InputManager {
public:
    void processEvent(const sf::Event& event);
    bool isKeyPressed(sf::Keyboard::Key key) const;

private:
    std::unordered_map<sf::Keyboard::Key, bool> keyStates;
};

