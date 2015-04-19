#include "Player.h"
#include "Resources.h"
#include "Utils.h"
#include "Network.h"
#include <cmath>
#include "LD32.h"

Player::Player(Game* game)
    : Object(game, sf::Vector2f(50, 50), Resources::texturePlayer, sf::Vector2i(2, 1)),
    network(game), game(game)
{
    mapInput();
    state = SELECT_BEAST;
    timer = 0;
}

Player::~Player()
{
}

void Player::mapInput() {
    inputManager->addMouseMapping(sf::Mouse::Button::Left);
}
        
void Player::update(float deltaTime) {
    network.update();
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
    case ROUND_RESULT:
        roundResult(deltaTime);
        break;
    default:
        break;
    }

}

void Player::draw() {
    network.draw();

    sf::Text text;
    text.setFont(Resources::font);
    text.setString(std::to_string(numBeasts));
    text.setCharacterSize(24);
    text.setPosition(sf::Vector2f(50, 50));

    game->getWindow()->draw(text);


    text.setFont(Resources::font);
    text.setString(std::to_string(numCityBeasts));
    text.setCharacterSize(24);
    text.setPosition(sf::Vector2f(50, 100));

    game->getWindow()->draw(text);
}

void Player::startMenu(float deltaTime) {

}

void Player::selectBeast(float deltaTime) {
    numBeasts = 10;
    beasts = Beasts(game, numBeasts, 10, 10, 10, 10, 10);
    state = UPGRADE_BEAST;
}

void Player::upgradeBeast(float deltaTime) {
    state = CITIES_INITIALITZATION;
}

void Player::citiesInitialitzation(float deltaTime) {
    network.addPath(0,1);
    network.addPath(1,3);
    network.addPath(3,2);
    network.addPath(2,4);
    network.addPath(2,5);
    network.addPath(4,5);
    network.addPath(2, 6);
    network.addPath(3, 9);
    network.addPath(6, 7);
    network.addPath(6, 12);
    network.addPath(7, 8);
    network.addPath(7, 9);
    network.addPath(9, 10);
    network.addPath(10, 11);
    network.addPath(11, 12);

    path.clear();
    path.push_back(0);
    network.getCity(0)->highlightSpecial();
    
    state = BEFORE_CITY_SELECTION;
}

void Player::beforeCitySelection(float deltaTime) {
    currentNeighbours = network.getNeighbours(path.back());

    if (currentNeighbours.size() <= 0) {
        pathInitialLength = path.size();
        state = MOVE_NEXT_CITY;
        return;
    }

    //Highlight neighbours
    std::vector<int>::iterator it = currentNeighbours.begin(); 
    for (; it != currentNeighbours.end(); it++) {
        network.getCity(*it)->highlight();
    }

    state = CITY_SELECTION;
}

void Player::citySelection(float deltaTime) {
    if (inputManager->getMouseState(sf::Mouse::Button::Left) == true) {
        sf::Vector2f mousePos = sf::Vector2f(inputManager->getMousePosition().x, inputManager->getMousePosition().y);
        int result = network.getCityByCoords(mousePos);
        bool inNeighbours = false;

        for (std::vector<int>::iterator it = currentNeighbours.begin(); it != currentNeighbours.end(); it++) {
            if (*it == result) {
                inNeighbours = true;
                break;
            }
        }

        if (inNeighbours) {
            network.destroyNode(path.back());
            path.push_back(result);
            state = AFTER_CITY_SELECTION;
        }
    }
}

void Player::afterCitySelection(float deltaTime) {
    //Unhighlight neighbours
    std::vector<int>::iterator it = currentNeighbours.begin(); 

    for (; it != currentNeighbours.end(); it++) {
        network.getCity(*it)->unHighlight();
    }

    //Highlight special selected city
    network.getCity(path[path.size()-1])->highlightSpecial();

    state = BEFORE_CITY_SELECTION;
}

void Player::moveNextCity(float deltaTime) {
    cityBeasts = *network.getCity(path.front())->getBeasts();
    numCityBeasts = cityBeasts.beasts.size();

    state = MOVING_ANIMATION;
}

void Player::movingAnimation(float deltaTime) {
    state = IN_BATTLE;
}

void Player::inBattle(float deltaTime) {
    BattleManager::resolveBattle(&beasts, &cityBeasts);
    state = BATTLE_ANIMATION;
    timer = 0;
}

/**
 * Decrements numBeasts and numCityBeasts until they
 * reach the respective beasts.size()
 */
void Player::battleAnimation(float deltaTime) {
     timer += deltaTime;
     
     if (timer > 0.2f) {
         timer = 0;
         int deltaBeasts = (int)std::ceil((numBeasts - beasts.beasts.size())/7.0);
         int deltaCityBeasts = (int)std::ceil((numCityBeasts - cityBeasts.beasts.size())/7.0);
         
         numBeasts -= deltaBeasts;
         numCityBeasts -= deltaCityBeasts;

         if(deltaBeasts <= 0 && deltaCityBeasts <= 0) {
             state = BATTLE_RESULT;
         }
     }
}

void Player::battleResult(float deltaTime) {
    if(beasts.beasts.size() <= 0) {
        state = ROUND_RESULT;
    } else {
        network.getCity(path.front())->destroy();
        path.erase(path.begin());
        if (path.size() > 0) {
            state = MOVE_NEXT_CITY;
        }
        else {
            state = ROUND_RESULT;
        }
    }
}

void Player::roundResult(float deltaTime) {
    upgradePoints += (pathInitialLength - path.size())*10;
}
