#include "Player.h"
#include "Resources.h"
#include "Utils.h"
#include "Network.h"

Player::Player(Game* game)
    : Object(game, sf::Vector2f(50, 50), Resources::texturePlayer, sf::Vector2i(2, 1)),
    network(game)
{
    mapInput();
    state = START_MENU;
}

Player::~Player()
{
}

void Player::mapInput() {
    inputManager->addMouseMapping(sf::Mouse::Button::Left);
}
        
void Player::update(float deltaTime) {
    switch(state) {

    case START_MENU:
        startMenu(deltaTime);
        break;
    case SELECT_BEAST:
        selectBeast(deltaTime);
        break;
    case UPGRADE_BEAST:
        upgradeBeast(deltaTime);
        break;
    case CITIES_INITIALITZATION:
        citiesInitialitzation(deltaTime);
        break;
    case BEFORE_CITY_SELECTION:
        beforeCitySelection(deltaTime);
        break;
    case CITY_SELECTION:
        citySelection(deltaTime);
        break;
    case AFTER_CITY_SELECTION:
        afterCitySelection(deltaTime);
        break;
    case MOVE_NEXT_CITY:
        moveNextCity(deltaTime);
        break;
    case MOVING_ANIMATION:
        movingAnimation(deltaTime);
        break;
    case IN_BATTLE:
        inBattle(deltaTime);
        break;
    case BATTLE_ANIMATION:
        battleAnimation(deltaTime);
        break;
    case BATTLE_RESULT:
        battleResult(deltaTime);
        break;
    case GAME_RESULTS:
        gameResults(deltaTime);
        break;
    default:
        break;
    }

}

void Player::startMenu(float deltaTime) {

}

void Player::selectBeast(float deltaTime) {
    numBeasts = 10;
    beasts = Beasts(numBeasts, 10, 10, 10, 10, 10);
}

void Player::upgradeBeast(float deltaTime) {

}

void Player::citiesInitialitzation(float deltaTime) {

}

void Player::beforeCitySelection(float deltaTime) {

}

void Player::citySelection(float deltaTime) {

}

void Player::afterCitySelection(float deltaTime) {

}

void Player::moveNextCity(float deltaTime) {
    numCityBeasts = 100;
    cityBeasts = Beasts(numCityBeasts, 100, 100, 100, 100, 100);
}

void Player::movingAnimation(float deltaTime) {

}

void Player::inBattle(float deltaTime) {
    BattleManager::resolveBattle(&beasts, &cityBeasts);
}

void Player::battleAnimation(float deltaTime) {
       
}

void Player::battleResult(float deltaTime) {

}

void Player::gameResults(float deltaTime) {

}
