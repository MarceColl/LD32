#include "City.h"
#include "Resources.h"

City::City()
    : Object()
{
}

City::City(Game* g, int id) 
    : Object(g, sf::Vector2f(150, 150), Resources::texturePlayer, sf::Vector2i(2, 1))
{
    bool highlighted = false;
    bool highlightedSpecial = false;
}

City::~City()
{
}

// Funcions top tier, algorismia pura
void City::highlight() {
    highlighted = true;
}

void City::unhighlight() {
    highlighted = false;
}

void City::highlightspecial() {
    highlightedSpecial = true;
}

void City::unhighlightspecial() {
    highlightedSpecial = false;
}

bool City::isInside(sf::Vector2f coords) {
    return isPointInsideRectangle(coords, sf::FloatRect(position, size));
}
