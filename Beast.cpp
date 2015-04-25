#include "Beast.h"

Beast::Beast(Attributes attr) :
    health(attr.health), attributes(attr)
{
}

Beast::~Beast() {}

int Beast::getStrength() {
    return attributes.strength;
}

int Beast::getResistance() {
    return attributes.resistance;
}

int Beast::getFear() {
    return attributes.fear;
}

int Beast::getBeauty() {
    return attributes.beauty;
}

int Beast::getHealth() {
    return health;
}

/**
 * Retrives amount from health, and returns the remaining health
 */
int Beast::loseHealth(int amount) {
    health -= amount;
    if(health < 0) health = 0;
    return health;
}

Beast::Attributes::Attributes() {}
Beast::Attributes::Attributes(int number, int strength, int resistance, int fear, int beauty, int health) :
    number(number), strength(strength), resistance(resistance), fear(fear), beauty(beauty), health(health)
{

}

Beast::Attributes::~Attributes() {}
