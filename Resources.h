#ifndef __SFMLS_RESOURCES_H__
#define __SFMLS_RESOURCES_H__

#include <SFML/Graphics.hpp>

class Resources {
public:
    static void load();
    static sf::Texture texturePlayer;
    static sf::Texture textureMap;
    static sf::Texture textureCity;
    static sf::Texture textureSheep;
    static sf::Texture textureButton;
    static sf::Texture textureBoxGloves;
    static sf::Texture textureCarpet;
    static sf::Texture textureJustinBMask;
    static sf::Texture textureNeedle;
    static sf::Texture textureResistor;
    static sf::Texture textureRock;

    static sf::Font font;
};

#endif
