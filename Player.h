#ifndef __LD32_PLAYER_H__
#define __LD32_PLAYER_H__

#include "Object.h"

class Player : public Object
{
public:
    Player(Game* g);
    ~Player();

    void update(float deltaTime);

protected:
    sf::Vector2f speed;
    const sf::Vector2f acceleration;
    void mapInput();
};

#endif
