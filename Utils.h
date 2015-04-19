#ifndef __LD32_UTILS_H__
#define __LD32_UTILS_H__

#include <SFML/Graphics.hpp>

enum Dir {
    UP,
    DOWN,
    RIGHT,
    LEFT
};

sf::Vector2f normalizeWithLength(sf::Vector2f vec, float length);
sf::Vector2f limitVector2f(sf::Vector2f vec, sf::Vector2f limits);
bool isPointInsideRectangle(sf::Vector2f vec, sf::FloatRect rect);
sf::Vector2f limitToScreen(sf::Vector2f vec, sf::Vector2f rect);

#endif