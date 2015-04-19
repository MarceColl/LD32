#ifndef __SFMLS_UPGRADE_H__
#define __SFMLS_UPGRADE_H__

#include "Object.h"
#include "Resources.h"

class Upgrade : public Object
{
public:
    Upgrade(Game *g, sf::Vector2f pos, std::string name);
    ~Upgrade();

    std::string getName();

protected:
    std::string name;
};

#endif
