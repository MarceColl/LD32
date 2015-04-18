#include "Utils.h"
#include <math.h>

sf::Vector2f normalizeWithLength(sf::Vector2f vec, float length) {
    sf::Vector2f result = vec;
    float size = sqrt(vec.x*vec.x + vec.y*vec.y);
    vec /= size;
    vec *= length;

    return result;
}