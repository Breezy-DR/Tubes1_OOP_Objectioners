#ifndef __ABILITYLESS_HPP__
#define __ABILITYLESS_HPP__
#include "AbilityCard.hpp"
#pragma once

class Abilityless : public AbilityCard {
private:
public:
    Abilityless();
    Abilityless(int);
    void useAbility();
};


#endif