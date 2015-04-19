#ifndef __SFMLS_UPGRADE_H__
#define __SFMLS_UPGRADE_H__

#include "Object.h"
#include "Resources.h"
#include "Beast.h"

class Upgrade : public Object
{
public:
    Upgrade(Game *g, std::string name, Beast::Attributes bonus, sf::Texture& tex);
    ~Upgrade();

    std::string getName();
    bool active;
    Beast::Attributes bonus;

protected:
    std::string name;
};

#endif
