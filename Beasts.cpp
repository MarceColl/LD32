#include "Beasts.h"
#include "Resources.h"
#include <iostream>

Beasts::Beasts()
{
    
}

Beasts::Beasts(Game *g, Beast::Attributes attr) :
    Object(g, sf::Vector2f(60, 70), Resources::textureSheep, sf::Vector2i(1, 1)),
    attributes(attr)
{
    std::cout << attr.number << std::endl;
    for(int i = 0; i < attr.number; i++){
        beasts.push_back(Beast(&attributes));
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
