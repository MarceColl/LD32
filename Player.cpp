#include "Player.h"
#include "Resources.h"

Player::Player(Game* game)
    : Object(game, sf::Vector2f(50, 50), Resources::texturePlayer, sf::Vector2i(1, 1))
{
    this->mapInput();
}

Player::~Player()
{
}

void Player::mapInput() {
    inputManager->addKeyboardMapping(sf::Keyboard::W);
    inputManager->addKeyboardMapping(sf::Keyboard::A);
    inputManager->addKeyboardMapping(sf::Keyboard::S);
    inputManager->addKeyboardMapping(sf::Keyboard::D);
}
