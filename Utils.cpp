#include "Utils.h"
#include <math.h>

sf::Vector2f normalizeWithLength(sf::Vector2f vec, float length) {
    sf::Vector2f result = vec;
    float size = sqrt(vec.x*vec.x + vec.y*vec.y);
    vec /= size;
    vec *= length;

    return result;
}

sf::Vector2f limitVector2f(sf::Vector2f vec, sf::Vector2f limits) {
    if (vec.x > limits.x)
        vec.x = limits.x;
    else if (vec.x < - limits.x)
        vec.x = -limits.x;
    if (vec.y > limits.y)
        vec.y = limits.y;
    else if (vec.y < -limits.y)
        vec.y = -limits.y;
    return vec;
}