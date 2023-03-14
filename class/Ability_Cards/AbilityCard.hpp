#ifndef __ABILITYCARD_HPP__
#define __ABILITYCARD_HPP__
#include <iostream>
#include "Ability.hpp"
#include "../Card.hpp"
#include "../Exception.h"


class AbilityCard : public Card, Ability {
protected:
    bool isDisabled;
    bool isUsed;
public:
    AbilityCard();
    AbilityCard(int _holder, string _abilityname, string _abilitydescription);
    ~AbilityCard();
    virtual void useAbility() = 0;
    friend ostream &operator<<(ostream &os, AbilityCard& ac);
};

#endif