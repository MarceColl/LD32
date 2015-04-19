#ifndef __LD32_CITY_H__
#define __LD32_CITY_H__

#include "Object.h"
#include "Beasts.h"

class City : public Object
{
public:
    City(); 
    City(Game* g, int id, Beasts beasts);
    ~City();

    void highlight();
    void unHighlight();
    void highlightSpecial();
    void unHighlightSpecial();

    bool isInside(sf::Vector2f coords);
    
    Beasts* getBeasts();

protected:
    Beasts beasts;
    bool highlighted;
    bool highlightedSpecial;
};

#endif
