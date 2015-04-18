#ifndef __SFMLS_OBJECT_H__
#define __SFMLS_OBJECT_H__

#include "InputManager.h"

class Game;
class Object
{
public:
    Object(Game* g, sf::Vector2f size, sf::Texture& tex, sf::Vector2i spriteCount);
    ~Object();

protected:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Texture& tex;
    sf::Vector2i spriteCount;
    sf::Vector2i spriteNum;
    sf::Sprite sprite;

    virtual void update(float deltaTime);
    virtual void draw();

private:
    Game* game;
    InputManager* inputManager;
};

#endif