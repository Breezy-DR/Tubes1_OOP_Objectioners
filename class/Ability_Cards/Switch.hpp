#ifndef __SWITCH_HPP__
#define __SWITCH_HPP__
#include "AbilityCard.hpp"
#pragma once

class Switch : public AbilityCard {
private:
public:
    Switch();
    Switch(int);
    void useAbility(Game);
};


#endif