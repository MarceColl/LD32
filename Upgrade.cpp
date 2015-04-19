#include "Upgrade.h"
#include "LD32.h"


Upgrade::Upgrade(Game *g, std::string name, Beast::Attributes bonus, sf::Texture& tex) :
    Object(g, sf::Vector2f(80, 30), Resources::textureButton, sf::Vector2i(3, 1)),
    name(name), active(false), bonus(bonus)
{
}

Upgrade::~Upgrade() {}

std::string Upgrade::getName() {
    return name;
}

void Upgrade::draw() {
    Object::draw();

    /*sf::Sprite button;
    button.setTexture(Resources::textureButton);
    button.move(pos);
    game->getWindow()->draw(button);
    */
}
