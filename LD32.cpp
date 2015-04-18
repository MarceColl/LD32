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
    pl.update(deltaTime);
}

void LD32::draw() {
    pl.draw();
}

void LD32::processEvents() {
    sf::Event event;

    // while there are pending events...
    while (window.pollEvent(event))
    {
        // check the type of the event...
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        default:
            inputManager.parseEvents(event);
        }
    }
}