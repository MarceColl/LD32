#include "Object.h"
#include "Game.h"
#include "Resources.h"

Object::Object() : text(Resources::textureMap) {
}

Object::Object(Game* g, sf::Vector2f size, sf::Texture& tex, sf::Vector2i spriteCount) :
    game(g), size(size), text(tex), spriteCount(spriteCount)
{
    inputManager = game->getInputManager();
    sprite.setTexture(tex);
}

Object::~Object()
{
}

void Object::draw() {
    sprite.setScale(size.x / text.getSize().x*spriteCount.x, size.y / text.getSize().y*spriteCount.y);

    sprite.setTextureRect(sf::IntRect(
        spriteNum.x*text.getSize().x / spriteCount.x,
        spriteNum.y*text.getSize().y / spriteCount.y,
        text.getSize().x / spriteCount.x,
        text.getSize().y / spriteCount.y
        ));

    sprite.setPosition(position);
    game->getWindow()->draw(sprite);
}

void Object::update(float deltaTime) {

}

sf::Vector2f Object::getPosition() {
    return position;
}

sf::Vector2f Object::getCenteredPosition() {
    return position + size / 2.f;
}

sf::Vector2f Object::getSize() {
    return size;
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
