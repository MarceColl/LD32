#include "Beasts.h"
#include "Resources.h"

Beasts::Beasts()
{
    
}

Beasts::Beasts(Game *g, int number, Beast::Attributes attr) :
    Object(g, sf::Vector2f(40, 47), Resources::textureSheep, sf::Vector2i(1, 1)),
    attributes(attr)
{
    for(int i = 0; i < number; i++){
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
