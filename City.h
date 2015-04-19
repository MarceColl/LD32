#ifndef __LD32_CITY_H__
#define __LD32_CITY_H__

#include "Object.h"
#include "Beasts.h"

class City : public Object
{
public:
    City(); 
    City(Game* g, int id, std::string name, Beasts beasts);
    ~City();

    void highlight();
    void unHighlight();
    void highlightSpecial();
    void unHighlightSpecial();

    bool isInside(sf::Vector2f coords);
    void draw();
    void update();
    void drawPopup();
    void drawBattlePopup(int numCityBeasts, int numPlayerBeasts, const Beast::Attributes& plattr);
    void destroy();

    int getId();

    Beasts* getBeasts();

protected:
    Beasts beasts;
    bool highlighted;
    bool highlightedSpecial;
    bool mouseOver;
    bool destroyed;
    std::string name;

    int c_id;
};

#endif
