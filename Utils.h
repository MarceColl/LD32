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

#endif