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
    inputManager->addKeyboardMapping(sf::Keyboard::W);
    inputManager->addKeyboardMapping(sf::Keyboard::A);
    inputManager->addKeyboardMapping(sf::Keyboard::S);
    inputManager->addKeyboardMapping(sf::Keyboard::D);
    inputManager->addMouseMapping(sf::Mouse::XButton1);
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

    moveSpriteIndex(RIGHT);

    position = normalizeWithLength(finalVector, 30.0f);

    if (inputManager->getMouseState(sf::Mouse::Button::Left)) {
        position = sf::Vector2f(inputManager->getMousePosition().x, inputManager->getMousePosition().y);
    }
}