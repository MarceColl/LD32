#include "Player.h"
#include "Resources.h"
#include "Utils.h"

Player::Player(Game* game)
    : Object(game, sf::Vector2f(50, 50), Resources::texturePlayer, sf::Vector2i(2, 1))
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
        startMenu();
        break;
    case SELECT_BEAST:
        selectBeast();
        break;
    case UPGRADE_BEAST:
        upgradeBeast();
        break;
    case CITIES_INITIALITZATION:
        citiesInitialitzation();
        break;
    case BEFORE_CITY_SELECTION:
        beforeCitySelection();
        break;
    case CITY_SELECTION:
        citySelection();
        break;
    case AFTER_CITY_SELECTION:
        afterCitySelection();
        break;
    case MOVING_ANIMATION:
        movingAnimation();
        break;
    case IN_BATTLE:
        inBattle();
        break;
    case BATTLE_ANIMATION:
        battleAnimation();
        break;
    case BATTLE_RESULT:
        battleResult();
        break;
    case GAME_RESULTS:
        gameResults();
        break;
    default:

        break;
    }

}

void Player::startMenu(){

}

void Player::selectBeast(){

}

void Player::upgradeBeast(){

}

void Player::citiesInitialitzation(){

}

void Player::beforeCitySelection(){

}

void Player::citySelection(){

}

void Player::afterCitySelection(){

}

void Player::movingAnimation(){

}

void Player::inBattle(){
    //BattleManager::resolveBattle(beasts, cityBeasts);
}

void Player::battleAnimation(){

}

void Player::battleResult(){

}

void Player::gameResults(){

}
