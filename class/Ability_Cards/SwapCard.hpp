#ifndef __SWAPCARD_HPP__
#define __SWAPCARD_HPP__
#include "AbilityCard.hpp"
#pragma once

class SwapCard : public AbilityCard {
private:
public:
    SwapCard();
    SwapCard(int);
    void useAbility(Game);
};


#endif