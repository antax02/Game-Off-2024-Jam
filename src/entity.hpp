#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable{
public:
    virtual void update(sf::Time dt) = 0;

protected:
    sf::Vector2f position;
    sf::Sprite sprite;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(sprite, states);
    }
};
