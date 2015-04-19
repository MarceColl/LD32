#include "Upgrade.h"
#include "LD32.h"


Upgrade::Upgrade(Game *g, std::string name, Beast::Attributes bonus, sf::Texture& tex) :
    Object(g, sf::Vector2f(150, 30), Resources::textureButton, sf::Vector2i(3, 1)),
    name(name), active(false), bonus(bonus), texture(tex)
{
}

Upgrade::~Upgrade() {}

std::string Upgrade::getName() {
    return name;
}

void Upgrade::draw() {
    Object::draw();

    Object icon(game, sf::Vector2f(50, 50), texture, sf::Vector2i(1, 1));
    icon.setPosition(position + sf::Vector2f(0, 0));
    icon.draw();

}
