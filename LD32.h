#ifndef __LD32_LD32_H__
#define __LD32_LD32_H__

#include "Game.h"

enum GAMESTATE {
    MENU,
    PAUSED,
    RUNNING
};

class LD32 : public Game
{
public:
    LD32(int scrwidth, int scrheight, std::string title);
    ~LD32();

    void draw();
    void processEvents();
    void update(float deltaTime);
private:
    GAMESTATE gameState;
};

#endif