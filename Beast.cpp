#include "Beast.h"

Beast::Beast(int health, Attributes *attr) :
    health(health), attributes(attr)
{
}

Beast::~Beast() {}

int Beast::getStrength() {
    return attributes->strength;
}

int Beast::getResistance() {
    return attributes->resistance;
}

int Beast::getFear() {
    return attributes->fear;
}

int Beast::getBeauty() {
    return attributes->beauty;
}

int Beast::getHealth() {
    return health;
}

