#include "Beasts.h"
#include "Resources.h"

Beasts::Beasts()
{
    
}

Beasts::Beasts(Game *g, int number, int strength, int resistance, int fear, int beauty, int health) :
    Object(g, sf::Vector2f(72, 84), Resources::textureSheep, sf::Vector2i(1, 1))
{
    attributes.strength = strength;
    attributes.resistance = resistance;
    attributes.fear = fear;
    attributes.beauty = beauty;

    for(int i = 0; i < number; i++){
        beasts.push_back(Beast(health, &attributes));
    }
}

Beasts::~Beasts() {}

/**
 * This is a comment to comment the code
 de chilling
 */
Beast::Attributes Beasts::getAttributes() {
    return attributes;
}
