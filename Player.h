#ifndef __LD32_PLAYER_H__
#define __LD32_PLAYER_H__

#include "Object.h"
#include "BattleManager.h"
#include "Network.h"

class Player : public Object
{
public:
    Player(Game* g);
    ~Player();

    void update(float deltaTime);

protected:
    void mapInput();
    enum GameState {
        START_MENU,
        SELECT_BEAST,
        UPGRADE_BEAST,
        CITIES_INITIALITZATION,
        BEFORE_CITY_SELECTION,
        CITY_SELECTION,
        AFTER_CITY_SELECTION,
        MOVING_ANIMATION,
        IN_BATTLE,
        BATTLE_ANIMATION,
        BATTLE_RESULT,
        GAME_RESULTS
    };

    Beasts beasts;
    Beasts cityBeasts;

    int numBeasts;
    int numCityBeasts;

    GameState state;

    void startMenu(float deltaTime);
    void selectBeast(float deltaTime);
    void upgradeBeast(float deltaTime);
    void citiesInitialitzation(float deltaTime);
    void beforeCitySelection(float deltaTime);
    void citySelection(float deltaTime);
    void afterCitySelection(float deltaTime);
    void moveNextCity(float deltaTime);
    void movingAnimation(float deltaTime);
    void inBattle(float deltaTime);
    void battleAnimation(float deltaTime);
    void battleResult(float deltaTime);
    void gameResults(float deltaTime);

    Network network;
};

#endif
