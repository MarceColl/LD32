#ifndef __LD32_PLAYER_H__
#define __LD32_PLAYER_H__

#include "Object.h"
#include "BattleManager.h"
#include "Network.h"
#include "Beasts.h"

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
        MOVE_NEXT_CITY,
        MOVING_ANIMATION,
        IN_BATTLE,
        BATTLE_ANIMATION,
        BATTLE_RESULT,
        ROUND_RESULT
    };
    
    Network network;
    /**
     * When building the route, this is the last selected city
     */
    int lastSelectedCity;

    /**
     * When attacking, next city to attack, or -1, if all cities have been killed
     */
    int targetCity;

    std::vector<int> currentNeighbours;

    Beasts beasts;
    Beasts cityBeasts;
    int numBeasts;
    int numCityBeasts;

    float timer;

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
    void roundResult(float deltaTime);

};

#endif
