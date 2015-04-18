#include "Object.h"
#include "Game.h"

Object::Object(Game* g, sf::Vector2f size, sf::Texture& tex, sf::Vector2i spriteCount) :
    game(g), size(size), tex(tex), spriteCount(spriteCount)
{
    inputManager = game->getInputManager();
    sprite.setTexture(tex);
}

Object::~Object()
{
}

void Object::draw() {
    sprite.setScale(size.x / tex.getSize().x*spriteCount.x, size.y / tex.getSize().y*spriteCount.y);

    sprite.setTextureRect(sf::IntRect(
        spriteNum.x*tex.getSize().x / spriteCount.x,
        spriteNum.y*tex.getSize().y / spriteCount.y,
        tex.getSize().x / spriteCount.x,
        tex.getSize().y / spriteCount.y
        ));

    sprite.setPosition(position);
    game->getWindow()->draw(sprite);
}

void Object::update(float deltaTime) {

}

void Object::mapInput() {}