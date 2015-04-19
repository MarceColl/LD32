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
    GameState state;

    void startMenu();
    void selectBeast();
    void upgradeBeast();
    void citiesInitialitzation();
    void beforeCitySelection();
    void citySelection();
    void afterCitySelection();
    void movingAnimation();
    void inBattle();
    void battleAnimation();
    void battleResult();
    void gameResults();

    Network network;
};

#endif
