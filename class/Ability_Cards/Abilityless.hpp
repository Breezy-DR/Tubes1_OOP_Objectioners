#ifndef __ABILITYLESS_HPP__
#define __ABILITYLESS_HPP__
#include "AbilityCard.cpp"


class Abilityless : public AbilityCard {
private:
public:
    Abilityless();
    Abilityless(int);
    void useAbility(Game game);
};


#endif