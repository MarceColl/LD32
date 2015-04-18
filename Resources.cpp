#include "Resources.h"

sf::Texture Resources::texturePlayer;
sf::Texture Resources::textureMap;

void Resources::load() {
    texturePlayer.loadFromFile("assets/placeholder-player.png");
    textureMap.loadFromFile("assets/palceholder-map.png");
}