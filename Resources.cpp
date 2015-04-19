#include "Resources.h"

sf::Texture Resources::texturePlayer;
sf::Texture Resources::textureMap;
sf::Texture Resources::textureCity;
sf::Texture Resources::textureSheep;
sf::Font Resources::font;

void Resources::load() {
    texturePlayer.loadFromFile("assets/placeholder-player.png");
    textureMap.loadFromFile("assets/placeholder-map.png");
    textureCity.loadFromFile("assets/city.png");
    textureSheep.loadFromFile("assets/sheep.png");
    font.loadFromFile("assets/font.ttf");
}
