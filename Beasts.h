#ifndef __SFMLS_BEASTS_H__
#define __SFMLS_BEASTS_H__

#include <list>
#include "Beast.h"
#include "Object.h"

class Beasts : public Object
{
public:
    Beasts();
    Beasts(Game *g, int number, int strength, int resistance, int fear, int beauty, int health);
    ~Beasts();
    std::list<Beast> beasts;
    Beast::Attributes getAttributes();

private:
    Beast::Attributes attributes;
};

#endif
