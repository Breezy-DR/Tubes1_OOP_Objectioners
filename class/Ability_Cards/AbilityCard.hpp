#ifndef __ABILITYCARD_HPP__
#define __ABILITYCARD_HPP__
#include <iostream>
#include "Ability.hpp"
#include "../Card.hpp"
#include "../Exception.h"
#include "../Game.hpp"


class AbilityCard : public Card, Ability {
protected:
    bool isDisabled;
    bool isUsed;
public:
    AbilityCard();
    AbilityCard(int _holder, string _abilityname, string _abilitydescription);
    ~AbilityCard();
    virtual void useAbility() = 0;
    float value();
    friend ostream &operator<<(ostream &os, AbilityCard& ac);
};

#endif