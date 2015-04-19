#include "Player.h"
#include "Resources.h"
#include "Utils.h"
#include "Network.h"
#include <cmath>
#include "Upgrade.h"
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
    if (state == UPGRADE_BEAST) {
        drawUpgradeMenu();
    }

    beasts.draw();

    if (state == BATTLE_ANIMATION) {
        network.getCity(path.front())->drawBattlePopup(numCityBeasts, numBeasts, beasts.getAttributes());
    }
}

void Player::drawUpgradeMenu() {
    
    int width = 800;
    int height = 600;
    sf::RectangleShape menu(sf::Vector2f(width, height));
    
    sf::Vector2f posRel = sf::Vector2f(750-width/2, 500-height/2);
    menu.move(posRel);
    
    //Menu
    menu.setFillColor(sf::Color(200, 200, 200));
    menu.setOutlineThickness(5);
    menu.setOutlineColor(sf::Color(150, 150, 150));
    game->getWindow()->draw(menu);

    //Title
    sf::Text title;
    title.setFont(Resources::font);
    title.setString("Upgrades");
    title.setCharacterSize(40);
    title.setColor(sf::Color(0, 0, 0));
    title.setStyle(sf::Text::Bold);
    title.move(posRel + sf::Vector2f(width/2 - title.getLocalBounds().width/2, 0));
    game->getWindow()->draw(title);

    sf::Sprite beastSprite;
    beastSprite.setTexture(Resources::textureSheep);
    beastSprite.move(posRel + sf::Vector2f(60, 40));
    beastSprite.scale(sf::Vector2f(4,4));
    game->getWindow()->draw(beastSprite);

    //Stats menu
    sf::Text text;
    text.setFont(Resources::font);
    
    Beast::Attributes atr = beasts.getAttributes();

    sf::Vector2f attrPos = posRel + sf::Vector2f(width/2 + 30, 40);

    text.setCharacterSize(30);
    text.setPosition(attrPos + sf::Vector2f(0, 100));
    text.setString("Attributes");
    text.setColor(sf::Color(0, 0, 0));
    text.setStyle(sf::Text::Bold);
    game->getWindow()->draw(text);

    text.setStyle(sf::Text::Regular);
    text.setCharacterSize(20);

    sf::Vector2f currentPos = attrPos + sf::Vector2f(0, 115);
    sf::Vector2f step = sf::Vector2f(0, 30);


/////// HARDODEJAT, ELIMINAR!!!/////
    hoverUpgrade = 0;
///// END HARDOCDE ////

    currentPos += step;
    text.setPosition(currentPos);
    text.setString("Number of beasts: " + std::to_string(atr.number));
    game->getWindow()->draw(text);
    if(hoverUpgrade != -1 && upgrades[hoverUpgrade].bonus.number) {
        text.setPosition(currentPos + sf::Vector2f(text.getLocalBounds().width + 10, 0));
        text.setColor(sf::Color(0, 200, 0));
        text.setString("( +" + std::to_string(upgrades[hoverUpgrade].bonus.number) + " )");
        game->getWindow()->draw(text);
        text.setColor(sf::Color(0, 0, 0));
    }

    currentPos += step;
    text.setPosition(currentPos);
    text.setString("Strength: " + std::to_string(atr.strength));
    game->getWindow()->draw(text);
    if(hoverUpgrade != -1 && upgrades[hoverUpgrade].bonus.strength) {
        text.setPosition(currentPos + sf::Vector2f(text.getLocalBounds().width + 10, 0));
        text.setColor(sf::Color(0, 200, 0));
        text.setString("( +" + std::to_string(upgrades[hoverUpgrade].bonus.strength) + " )");
        game->getWindow()->draw(text);
        text.setColor(sf::Color(0, 0, 0));
    }

    currentPos += step;
    text.setPosition(currentPos);
    text.setString("Resistance: " + std::to_string(atr.resistance));
    game->getWindow()->draw(text);
    if(hoverUpgrade != -1 && upgrades[hoverUpgrade].bonus.resistance) {
        text.setPosition(currentPos + sf::Vector2f(text.getLocalBounds().width + 10, 0));
        text.setColor(sf::Color(0, 200, 0));
        text.setString("( +" + std::to_string(upgrades[hoverUpgrade].bonus.resistance) + " )");
        game->getWindow()->draw(text);
        text.setColor(sf::Color(0, 0, 0));
    }

    currentPos += step;
    text.setPosition(currentPos);
    text.setString("Fear: " + std::to_string(atr.fear));
    game->getWindow()->draw(text);
    if(hoverUpgrade != -1 && upgrades[hoverUpgrade].bonus.fear) {
        text.setPosition(currentPos + sf::Vector2f(text.getLocalBounds().width + 10, 0));
        text.setColor(sf::Color(0, 200, 0));
        text.setString("( +" + std::to_string(upgrades[hoverUpgrade].bonus.fear) + " )");
        game->getWindow()->draw(text);
        text.setColor(sf::Color(0, 0, 0));
    }

    currentPos += step;
    text.setPosition(currentPos);
    text.setString("Beauty: " + std::to_string(atr.beauty));
    game->getWindow()->draw(text);
    if(hoverUpgrade != -1 && upgrades[hoverUpgrade].bonus.beauty) {
        text.setPosition(currentPos + sf::Vector2f(text.getLocalBounds().width + 10, 0));
        text.setColor(sf::Color(0, 200, 0));
        text.setString("( +" + std::to_string(upgrades[hoverUpgrade].bonus.beauty) + " )");
        game->getWindow()->draw(text);
        text.setColor(sf::Color(0, 0, 0));
    }

    currentPos += step;
    text.setPosition(currentPos);
    text.setString("Health: " + std::to_string(atr.health));
    game->getWindow()->draw(text);
    if(hoverUpgrade != -1 && upgrades[hoverUpgrade].bonus.health) {
        text.setPosition(currentPos + sf::Vector2f(text.getLocalBounds().width + 10, 0));
        text.setColor(sf::Color(0, 200, 0));
        text.setString("( +" + std::to_string(upgrades[hoverUpgrade].bonus.health) + " )");
        game->getWindow()->draw(text);
        text.setColor(sf::Color(0, 0, 0));
    }

}

void Player::startMenu(float deltaTime) {

}

void Player::selectBeast(float deltaTime) {
    Beast::Attributes attr(10, 10, 10, 10, 10, 10);

    beasts = Beasts(game, attr);

    upgrades.push_back(Upgrade(game, "Stamina", Beast::Attributes(1, 0, 1, 0, 0, 0), Resources::textureSheep));
    
    state = UPGRADE_BEAST;

    beasts.setPosition(sf::Vector2f(-200, -200));
}

void Player::upgradeBeast(float deltaTime) {
    state = CITIES_INITIALITZATION;
}

void Player::citiesInitialitzation(float deltaTime) {
    network.addPath(0, 2);
    network.addPath(0, 3);
    network.addPath(3, 1);
    network.addPath(3, 5);
    network.addPath(3, 4);
    network.addPath(3, 6);
    network.addPath(2, 5);
    network.addPath(5, 6);
    network.addPath(5, 8);
    network.addPath(4, 7);
    network.addPath(6, 8);
    network.addPath(7, 8);

    path.clear();
    path.push_back(0);
    network.getCity(0)->highlightSpecial();
    
    state = BEFORE_CITY_SELECTION;
}

void Player::beforeCitySelection(float deltaTime) {
    currentNeighbours = network.getNeighbours(path.back());

    if (currentNeighbours.size() <= 0) {
        pathInitialLength = path.size();
        beasts.setCenteredPosition(network.getCity(path.front())->getCenteredPosition());
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
    numBeasts = beasts.beasts.size();

    beastsInitialPos = beasts.getCenteredPosition();
    beastsFinalPos = network.getCity(path.front())->getCenteredPosition();

    speed = (beastsFinalPos - beastsInitialPos) / 1.f;

    state = MOVING_ANIMATION;
}

void Player::movingAnimation(float deltaTime) {
    beasts.setPosition(beasts.getPosition() + speed*deltaTime);
    bool finished = false;

    if (speed.x <= 0 && beasts.getCenteredPosition().x <= beastsFinalPos.x)
        finished = true;
    if (speed.x >= 0 && beasts.getCenteredPosition().x >= beastsFinalPos.x)
        finished = true;

    if (finished)
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
    if (cityBeasts.beasts.size() <= 0) {
        network.getCity(path.front())->destroy();
    }

    if(beasts.beasts.size() <= 0) {
        state = ROUND_RESULT;
    } else {
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
    state = UPGRADE_BEAST;
}
