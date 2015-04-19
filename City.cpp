#include "City.h"
#include "Resources.h"
#include "LD32.h"
#include <string.h>

City::City()
    : Object()
{
}

City::City(Game* g, int id, std::string name, Beasts beasts) 
    : Object(g, sf::Vector2f(200, 200), Resources::textureCity, sf::Vector2i(1, 1)),
    beasts(beasts), name(name)
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
        sprite.setColor(sf::Color(0xFF, 0x99, 0x00));
    }
    else if (highlightedSpecial) {
        sprite.setColor(sf::Color(0x55, 0x33, 0x00));
    }
    else {
        sprite.setColor(sf::Color::White);
    }

    Object::draw();
}

void City::drawPopup() {
    if (mouseOver) {
        sf::RectangleShape rectangle(sf::Vector2f(200, 100));

        sf::Vector2f popupPos = limitToScreen(position - sf::Vector2f(-150, 70), sf::Vector2f(200, 100));

        rectangle.setPosition(popupPos);
        rectangle.setFillColor(sf::Color(0, 0, 0, 200));
        game->getWindow()->draw(rectangle);

        sf::Text text;
        text.setFont(Resources::font);
        
        Beast::Attributes atr = beasts.getAttributes();

        text.setCharacterSize(15);
        text.setPosition(popupPos + sf::Vector2f(10, 5));
        text.setString(name);
        game->getWindow()->draw(text);
        text.setCharacterSize(10);
        text.setPosition(popupPos + sf::Vector2f(15, 25));
        text.setString("Number of beasts: " + std::to_string(atr.number));
        game->getWindow()->draw(text);
        text.setPosition(popupPos + sf::Vector2f(15, 35));
        text.setString("Strength: " + std::to_string(atr.strength));
        game->getWindow()->draw(text);
        text.setPosition(popupPos + sf::Vector2f(15, 45));
        text.setString("Resistance: " + std::to_string(atr.resistance));
        game->getWindow()->draw(text);
        text.setPosition(popupPos + sf::Vector2f(15, 55));
        text.setString("Fear: " + std::to_string(atr.fear));
        game->getWindow()->draw(text);
        text.setPosition(popupPos + sf::Vector2f(15, 65));
        text.setString("Beauty: " + std::to_string(atr.beauty));
        game->getWindow()->draw(text);
        text.setPosition(popupPos + sf::Vector2f(15, 75));
        text.setString("Health: " + std::to_string(atr.health));
        game->getWindow()->draw(text);

        beasts.setPosition(popupPos + sf::Vector2f(145, 50));
        beasts.draw();
    }
}

void City::drawBattlePopup(int numCityBeasts, int numPlayerBeasts, const Beast::Attributes& plattr) {
    sf::RectangleShape rectangle(sf::Vector2f(200, 100));

    sf::Vector2f popupPos = limitToScreen(position - sf::Vector2f(-150, 70), sf::Vector2f(200, 250));

    rectangle.setPosition(popupPos);
    rectangle.setFillColor(sf::Color(0, 0, 0, 200));
    game->getWindow()->draw(rectangle);

    sf::Text text;
    text.setFont(Resources::font);

    Beast::Attributes atr = beasts.getAttributes();

    text.setCharacterSize(15);
    text.setPosition(popupPos + sf::Vector2f(10, 5));
    text.setString(name);
    game->getWindow()->draw(text);
    text.setCharacterSize(10);
    text.setPosition(popupPos + sf::Vector2f(15, 25));
    text.setString("Number of beasts: " + std::to_string(numCityBeasts));
    game->getWindow()->draw(text);
    text.setPosition(popupPos + sf::Vector2f(15, 35));
    text.setString("Strength: " + std::to_string(atr.strength));
    game->getWindow()->draw(text);
    text.setPosition(popupPos + sf::Vector2f(15, 45));
    text.setString("Resistance: " + std::to_string(atr.resistance));
    game->getWindow()->draw(text);
    text.setPosition(popupPos + sf::Vector2f(15, 55));
    text.setString("Fear: " + std::to_string(atr.fear));
    game->getWindow()->draw(text);
    text.setPosition(popupPos + sf::Vector2f(15, 65));
    text.setString("Beauty: " + std::to_string(atr.beauty));
    game->getWindow()->draw(text);
    text.setPosition(popupPos + sf::Vector2f(15, 75));
    text.setString("Health: " + std::to_string(atr.health));
    game->getWindow()->draw(text);

    beasts.setPosition(popupPos + sf::Vector2f(145, 50));
    beasts.draw();

    // PLAYER POPUP
    popupPos = limitToScreen(position - sf::Vector2f(-150, -60), sf::Vector2f(200, 100));

    rectangle.setPosition(popupPos);
    rectangle.setFillColor(sf::Color(0, 0, 0, 200));
    game->getWindow()->draw(rectangle);

    text.setCharacterSize(15);
    text.setPosition(popupPos + sf::Vector2f(10, 5));
    text.setString("You");
    game->getWindow()->draw(text);
    text.setCharacterSize(10);
    text.setPosition(popupPos + sf::Vector2f(15, 25));
    text.setString("Number of beasts: " + std::to_string(numPlayerBeasts));
    game->getWindow()->draw(text);
    text.setPosition(popupPos + sf::Vector2f(15, 35));
    text.setString("Strength: " + std::to_string(plattr.strength));
    game->getWindow()->draw(text);
    text.setPosition(popupPos + sf::Vector2f(15, 45));
    text.setString("Resistance: " + std::to_string(plattr.resistance));
    game->getWindow()->draw(text);
    text.setPosition(popupPos + sf::Vector2f(15, 55));
    text.setString("Fear: " + std::to_string(plattr.fear));
    game->getWindow()->draw(text);
    text.setPosition(popupPos + sf::Vector2f(15, 65));
    text.setString("Beauty: " + std::to_string(plattr.beauty));
    game->getWindow()->draw(text);
    text.setPosition(popupPos + sf::Vector2f(15, 75));
    text.setString("Health: " + std::to_string(plattr.health));
    game->getWindow()->draw(text);

    beasts.setPosition(popupPos + sf::Vector2f(145, 50));
    beasts.draw();
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
