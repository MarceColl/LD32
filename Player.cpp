#include "Player.h"
#include "Resources.h"

Player::Player(Game* game)
    : Object(game, sf::Vector2f(50, 50), Resources::texturePlayer, sf::Vector2i(1, 1))
{
    mapInput();
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

void Player::update(float deltaTime) {
    sf::Vector2f finalVector = position;
    if (inputManager->getKeyState(sf::Keyboard::D)) {
        finalVector += sf::Vector2f(30 * deltaTime, 0);
    }
    if (inputManager->getKeyState(sf::Keyboard::A)) {
        finalVector += sf::Vector2f(-30 * deltaTime, 0);
    }
    if (inputManager->getKeyState(sf::Keyboard::W)) {
        finalVector += sf::Vector2f(0, -30 * deltaTime);
    }
    if (inputManager->getKeyState(sf::Keyboard::S)) {
        finalVector += sf::Vector2f(0, 30 * deltaTime);
    }

    
    position = finalVector;
}