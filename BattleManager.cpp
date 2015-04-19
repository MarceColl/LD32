#include "BattleManager.h"

void BattleManager::resolveBattle(Beasts *beasts1, Beasts *beasts2) {
    beasts1->beasts.erase(beasts1->beasts.begin());
    beasts1->beasts.erase(beasts1->beasts.begin());
    beasts2->beasts.clear();
}
