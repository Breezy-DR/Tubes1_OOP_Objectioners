#ifndef __QUADRUPLE_HPP__
#define __QUADRUPLE_HPP__
#include "AbilityCard.cpp"


class Quadruple : public AbilityCard {
private:
public:
    Quadruple();
    Quadruple(int);
    void useAbility(Game);
};


#endif