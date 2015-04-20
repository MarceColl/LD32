#include "BattleManager.h"
#include "Beast.h"
#include <cstdlib>
#include <iostream>

void BattleManager::resolveBattle(Beasts *beasts1, Beasts *beasts2) {
    while(beasts1->beasts.size() > 0 && beasts2->beasts.size() > 0) {
        std::cout << "Player1: " << beasts1->beasts.size() << std::endl;
        std::cout << "Player2: " << beasts2->beasts.size() << std::endl;
        BattleManager::battle(beasts1->beasts.front(), beasts2->beasts.front());
        
        if(beasts1->beasts.front().getHealth() == 0) {
            beasts1->beasts.erase(beasts1->beasts.begin());
        }

        if(beasts2->beasts.front().getHealth() == 0) {
            beasts2->beasts.erase(beasts2->beasts.begin());
        }
    }
}

void BattleManager::round(Beasts *beasts1, Beasts *beasts2) {

}

/**
 * The algorithm goes this way:
 * Each enemy recives each turn an impact to health equal to 
 * (enemy.strengh*rand[0.8 - 1] - self.resistance*rand[0.8 - 1])
 *
 * If one enemy manages to fear the other, his strengh will double this round
 *
 * Both enemies are able to fear the other one in the same round
 */
void BattleManager::battle(Beast &beast1, Beast &beast2) {
    while(beast1.getHealth() > 0 && beast2.getHealth() > 0) {

        float factor1 = 1, factor2 = 1;
        float r;


        r = static_cast <float> (std::rand()) / static_cast <float> (RAND_MAX / 0.2f);
        factor1 -= r;


        r = static_cast <float> (std::rand()) / static_cast <float> (RAND_MAX / 0.2f);
        factor2 -= r;

        //Check if one enemy is able to fear the other, in this case
        //he will perform double damage
        if((std::rand() % 100) < beast1.getFear()) {
            factor1 *= 2;
        }

        if((std::rand() % 100) < beast2.getFear()) {
            factor2 *= 2;
        }
        
        std::cout << "FACTOR: " << factor1 << std::endl;
        std::cout << "Strength " << beast1.getStrength() << std::endl;
        std::cout << "Beast2 attacks: " << beast2.getStrength()*factor2 << " - Beast1 resistance, health: " << beast1.getResistance() << ", " << beast1.getHealth() << std::endl;
        std::cout << "Beast1 attacks: " << beast1.getStrength()*factor1 << " - Beast1 resistance, health: " << beast2.getResistance() << ", " << beast2.getHealth() << std::endl;
        
        beast1.loseHealth(beast2.getStrength()*factor2 - beast1.getResistance());
        beast2.loseHealth(beast1.getStrength()*factor1 - beast2.getResistance());

        //std::cout << factor1 << "  ,  " << factor2 << std::endl;
        std::cout << "Final Health1, Health2:  " << beast1.getHealth() << ", " << beast2.getHealth() << std::endl;
    }
}
        
