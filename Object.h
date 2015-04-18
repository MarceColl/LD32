#ifndef __SFMLS_OBJECT_H__
#define __SFMLS_OBJECT_H__

#include "InputManager.h"
#include "Utils.h"

class Game;
class Object
{
public:
    Object(Game* g, sf::Vector2f size, sf::Texture& tex, sf::Vector2i spriteCount);
    ~Object();

    virtual void update(float deltaTime);
    virtual void mapInput();
    void draw();
    sf::Vector2f getPosition();
    sf::Vector2f getSize();
protected:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Texture& tex;
    sf::Vector2i spriteCount;
    sf::Vector2i spriteNum;
    sf::Sprite sprite;

    InputManager* inputManager;
    void moveSpriteIndex(Dir d);

private:
    Game* game;
};

#endif
