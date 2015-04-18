#include "LD32.h"
 
LD32::LD32(int scrwidth, int scrheight, std::string title)
    : Game(scrwidth, scrheight, title, sf::Style::Default),
    gameState(MENU),
    pl(this)
{
    
}

LD32::~LD32()
{
}

void LD32::update(float deltaTime) {

}

void LD32::draw() {
    pl.draw();
}

void LD32::processEvents() {

}