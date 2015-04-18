#include "Resources.h"

sf::Texture Resources::texturePlayer;

void Resources::load() {
    texturePlayer.loadFromFile("assets/placeholder-player.png");
}