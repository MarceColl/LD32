#include "Beasts.h"

Beasts::Beasts(int number, int strength, int resistance, int fear, int beauty, int health)
{
    attributes.strength = strength;
    attributes.resistance = resistance;
    attributes.fear = fear;
    attributes.beauty = beauty;

    for(int i = 0; i < number; i++){
        beasts.push_back(Beast(health, &attributes));
    }
}

Beasts::~Beasts() {
    
}

/**
 * This is a comment to comment the code
 */
Beast::Attributes Beasts::getAttributes() {
    return attributes;
}
