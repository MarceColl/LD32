#include "City.h"
#include "Resources.h"
#include "LD32.h"

City::City()
    : Object()
{
}

City::City(Game* g, int id, Beasts beasts) 
    : Object(g, sf::Vector2f(200, 200), Resources::textureCity, sf::Vector2i(1, 1)),
    beasts(beasts)
{
    float y = id % 2 == 1 ? 750 - 100 * id : 100 * id;
    position = sf::Vector2f(200 * id, y);
    highlighted = false;
    highlightedSpecial = false;
    mouseOver = false;
    c_id = id;
}

City::~City()
{
}

void City::draw() {
    if (mouseOver) {
        sprite.setColor(sf::Color(130,130,130));
    }
    else if (highlighted) {
        sprite.setColor(sf::Color::Blue);
    }
    else if (highlightedSpecial) {
        sprite.setColor(sf::Color::Green);
    }
    else {
        sprite.setColor(sf::Color::White);
    }

    Object::draw();
}

void City::drawPopup() {
    if (mouseOver) {
        sf::RectangleShape rectangle(sf::Vector2f(200, 100));
        rectangle.setPosition(position - sf::Vector2f(-150, 50));
        rectangle.setFillColor(sf::Color(0, 0, 0, 170));
        game->getWindow()->draw(rectangle);
    }
}

void City::update() {
    sf::Vector2f mousePos = sf::Vector2f(inputManager->getMousePosition().x, inputManager->getMousePosition().y);
    if (isInside(mousePos)) {
        mouseOver = true;
    }
    else {
        mouseOver = false;
    }
}

int City::getId() {
    return c_id;
}

// Funcions top tier, algorismia pura
void City::highlight() {
    highlighted = true;
}

void City::unHighlight() {
    highlighted = false;
}

void City::highlightSpecial() {
    highlightedSpecial = true;
}

void City::unHighlightSpecial() {
    highlightedSpecial = false;
}

bool City::isInside(sf::Vector2f coords) {
    return isPointInsideRectangle(coords, sf::FloatRect(position, size));
}

Beasts* City::getBeasts() {
    return &beasts;
}
