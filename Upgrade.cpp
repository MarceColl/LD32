#include "Upgrade.h"


Upgrade::Upgrade(Game *g, std::string name, Beast::Attributes bonus, sf::Texture& tex) :
    Object(g, sf::Vector2f(80, 30), tex, sf::Vector2i(1, 1)),
    name(name), active(false)
{
}

Upgrade::~Upgrade() {}

std::string Upgrade::getName() {
    return name;
}
