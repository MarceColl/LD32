#ifndef __SFMLS_BATTLE_MANAGER_H__
#define __SFMLS_BATTLE_MANAGER_H__

#include "Beasts.h"

class BattleManager
{
public:
    static void resolveBattle(Beasts *beasts1, Beasts *beasts2);
    static void round(Beasts *beasts1, Beasts *beasts2);

private:
    static void battle(Beast &beast1, Beast &beast2);
};

#endif
