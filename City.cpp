#include "City.h"
#include "Resources.h"
#include "LD32.h"
#include <string.h>

City::City()
    : Object()
{
}

City::City(Game* g, int id, Beasts beasts) 
    : Object(g, sf::Vector2f(200, 200), Resources::textureCity, sf::Vector2i(1, 1)),
    beasts(beasts)
{
    float y = id % 2 == 1 ? 750 - 50 * id : 50 * id;
    destroyed = false;
    position = sf::Vector2f(100 * id, y);
    highlighted = false;
    highlightedSpecial = false;
    mouseOver = false;
    c_id = id;
}

City::~City()
{
}

void City::draw() {
    if (destroyed) {
        sprite.setColor(sf::Color::Black);
    }
    else if (mouseOver) {
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

    beasts.setPosition(position + sf::Vector2f(130, 130));
    beasts.draw();
}

void City::drawPopup() {
    if (mouseOver) {
        sf::Text text;
        text.setFont(Resources::font);
        text.setString(std::to_string(c_id));
        text.setCharacterSize(24);
        text.setPosition(position - sf::Vector2f(-170, 30));
        sf::RectangleShape rectangle(sf::Vector2f(200, 100));
        rectangle.setPosition(position - sf::Vector2f(-150, 50));
        rectangle.setFillColor(sf::Color(0, 0, 0, 170));
        game->getWindow()->draw(rectangle);
        game->getWindow()->draw(text);
    }
}

void City::destroy() {
    destroyed = true;
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
