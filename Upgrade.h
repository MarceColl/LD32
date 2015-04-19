#ifndef __SFMLS_UPGRADE_H__
#define __SFMLS_UPGRADE_H__

#include "Object.h"
#include "Resources.h"
#include "Beast.h"

class Upgrade : public Object
{
public:
    Upgrade(Game *g, sf::Vector2f pos, std::string name, Beast::Attributes bonus);
    ~Upgrade();

    std::string getName();
    bool active;

protected:
    std::string name;
};

#endif
