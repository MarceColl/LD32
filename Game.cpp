#include "Game.h"
#include <string>
#include "Resources.h"
#include <SFML/System.hpp>

Game::Game(int scrwidth, int scrheight, std::string title, int style) :
    window(sf::VideoMode(scrwidth, scrheight), title, style),
    inputManager(&window)
{
    Resources::load();
}

Game::~Game(){}

/*
Game main loop
*/
void Game::run() {
    sf::Clock c;
    srand(time(0));
    //view.reset(sf::FloatRect(0, 0, 10, 10));
    //window.setView(view);

    while (window.isOpen()) {
        float deltaTime = c.restart().asSeconds();

        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::render() {
    window.clear();
    draw();
    window.display();
}

InputManager* Game::getInputManager() {
    return &inputManager;
}

sf::RenderWindow* Game::getWindow() {
    return &window;
}
