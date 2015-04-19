#include "Resources.h"

sf::Texture Resources::texturePlayer;
sf::Texture Resources::textureMap;
sf::Texture Resources::textureCity;
sf::Texture Resources::textureSheep;
sf::Texture Resources::textureButton;
sf::Texture Resources::textureBoxGloves;
sf::Texture Resources::textureCarpet;
sf::Texture Resources::textureJustinBMask;
sf::Texture Resources::textureNeedle;
sf::Texture Resources::textureResistor;
sf::Texture Resources::textureRock;
sf::Font Resources::font;

void Resources::load() {
    texturePlayer.loadFromFile("assets/placeholder-player.png");
    textureMap.loadFromFile("assets/placeholder-map.png");
    textureCity.loadFromFile("assets/city.png");
    textureSheep.loadFromFile("assets/sheep.png");
    textureButton.loadFromFile("assets/button.png");
    textureBoxGloves.loadFromFile("assets/box-gloves.png");
    textureCarpet.loadFromFile("assets/carpet.png");
    textureJustinBMask.loadFromFile("assets/justin-b-mask.png");
    textureNeedle.loadFromFile("assets/needle.png");
    textureResistor.loadFromFile("assets/resistor.png");
    textureRock.loadFromFile("assets/rock.png");
    font.loadFromFile("assets/font.ttf");
    
}
