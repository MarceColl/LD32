#include "Upgrade.h"


Upgrade::Upgrade(Game *g, sf::Vector2f pos, std::string name, Beast::Attributes bonus) :
    Object(g, sf::Vector2f(80, 30), Resources::textureSheep, sf::Vector2i(1, 1)),
    name(name), active(false)
{
    setPosition(pos);
}

Upgrade::~Upgrade() {}

std::string Upgrade::getName() {
    return name;
}
