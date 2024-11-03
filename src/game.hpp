#include <SFML/Graphics.hpp>

class Game {
    public:
        Game();
        void run();
        void update(sf::Time dt);
        void render();

    private:
        sf::RenderWindow window;

};
