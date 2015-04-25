#ifndef __SFMLS_BEAST_H__
#define __SFMLS_BEAST_H__

class Beast
{
public:
    class Attributes{
    public:
        Attributes();
        Attributes(int number, int strength, int resistance, int fear, int beauty, int health);
        ~Attributes();
        int number;
        int strength;
        int resistance;
        int fear;
        int beauty;
        int health;
    };
    
    Beast(Attributes attr);
    ~Beast();

    int getStrength();
    int getResistance();
    int getFear();
    int getHealth();
    int getBeauty();

    int loseHealth(int amount);

protected:
    int health;
    Attributes attributes;
};

#endif
