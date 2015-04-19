#ifndef __LD32_CITY_H__
#define __LD32_CITY_H__

#include "Object.h"

class City : public Object
{
public:
    City(); 
    City(Game* g, int id);
    ~City();

    void highlight();
    void unhighlight();
    void highlightspecial();
    void unhighlightspecial();

    bool isInside(sf::Vector2f coords);

protected:
    bool highlighted;
    bool highlightedSpecial;
};

#endif
