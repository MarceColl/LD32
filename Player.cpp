#include "Player.h"
#include "Resources.h"
#include "Utils.h"

Player::Player(Game* game)
    : Object(game, sf::Vector2f(50, 50), Resources::texturePlayer, sf::Vector2i(2, 1)),
    acceleration(sf::Vector2f(0, 100.f))
{
    mapInput();
}

Player::~Player()
{
}

void Player::mapInput() {
    inputManager->addKeyboardMapping(sf::Keyboard::W);
    inputManager->addKeyboardMapping(sf::Keyboard::A);
    inputManager->addKeyboardMapping(sf::Keyboard::D);
    inputManager->addMouseMapping(sf::Mouse::XButton1);
}

void Player::update(float deltaTime) {
    sf::Vector2f finalVector = position;
    sf::Vector2f tempAcceleration = acceleration;

    if (inputManager->getKeyState(sf::Keyboard::D)) {
        tempAcceleration += sf::Vector2f(1000, 0);
    }
    if (inputManager->getKeyState(sf::Keyboard::A)) {
        tempAcceleration += sf::Vector2f(-1000, 0);
    }
    if (inputManager->getKeyState(sf::Keyboard::W)) {
        tempAcceleration += sf::Vector2f(0, -10000);
    }

    speed = limitVector2f(speed + tempAcceleration*deltaTime, sf::Vector2f(200, 200));

    finalVector = sf::Vector2f(finalVector.x + speed.x*deltaTime, finalVector.y + speed.y*deltaTime);

    moveSpriteIndex(RIGHT);

    position = normalizeWithLength(finalVector, 100.0f);
}