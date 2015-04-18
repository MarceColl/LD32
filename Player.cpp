#include "Player.h"
#include "Resources.h"
#include "Utils.h"

Player::Player(Game* game)
    : Object(game, sf::Vector2f(50, 50), Resources::texturePlayer, sf::Vector2i(2, 1))
{
    mapInput();
}

Player::~Player()
{
}

void Player::mapInput() {
    inputManager->addMouseMapping(sf::Mouse::Button::Left);
}
        
void Player::update(float deltaTime) {

}