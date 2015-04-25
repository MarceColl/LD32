#include "Beasts.h"
#include "Resources.h"
#include <iostream>
#include "Beast.h"

Beasts::Beasts()
{
    
}

Beasts::Beasts(Game *g, Beast::Attributes attr) :
    Object(g, sf::Vector2f(60, 70), Resources::textureSheep, sf::Vector2i(1, 1)),
    attributes(attr)
{
    for(int i = 0; i < attr.number; i++){
        beasts.push_back(Beast(attributes));
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

void Beasts::show() {
    std::cout << "Number: " << attributes.number << std::endl;
    std::cout << "Strength: " << attributes.strength << std::endl;
    std::cout << "Health: " << attributes.health << std::endl;
}
