#ifndef __SFMLS_BEAST_H__
#define __SFMLS_BEAST_H__

class Beast
{
public:
    struct Attributes{
        int strength;
        int resistance;
        int fear;
        int beauty;
    };
    
    Beast(int health, Attributes *attr);
    ~Beast();
    int getStrength();
    int getResistance();
    int getFear();
    int getHealth();
    int getBeauty();



protected:
    int health;
    Attributes *attributes;

};

#endif
