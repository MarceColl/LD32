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

void Object::moveSpriteIndex(Dir d) {
    switch (d){
    case UP:
        if (spriteNum.y == 0) {
            spriteNum.y = spriteCount.y - 1;
        }
        else {
            spriteNum.y -= 1;
        }
        break;
    case DOWN:
        if (spriteNum.y == spriteCount.y - 1) {
            spriteNum.y = 0;
        }
        else {
            spriteNum.y += 1;
        }
        break;
    case RIGHT:
        if (spriteNum.x == spriteCount.x - 1) {
            spriteNum.x = 0;
        }
        else {
            spriteNum.x += 1;
        }
        break;
    case LEFT:
        if (spriteNum.x == 0) {
            spriteNum.x = spriteCount.y - 1;
        }
        else {
            spriteNum.x -= 1;
        }
        break;
    }
}

void Object::mapInput() {}