#ifndef __SFMLS_BEASTS_H__
#define __SFMLS_BEASTS_H__

#include <list>
#include "Beast.h"

class Beasts
{
public:

    Beasts(int number, int strength, int resistance, int fear, int beauty, int health);
    ~Beasts();
    std::list<Beast> beasts;
    Beast::Attributes getAttributes();

private:
    Beast::Attributes attributes;
};

#endif
