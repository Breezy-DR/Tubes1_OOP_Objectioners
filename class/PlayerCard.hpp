#ifndef PLAYERCARD_HPP
#define PLAYERCARD_HPP

#include "InventoryHolder.hpp"
#include "Exception.h"
#include <vector>
#pragma once

class PlayerCard : public InventoryHolder
{
private:
    AbilityCard *abilityCard;

public:
    PlayerCard();
    PlayerCard(const PlayerCard &);
    ~PlayerCard();
    PlayerCard(vector<MainCard> mc);
    AbilityCard *getAbilityCard();
    void setAbilityCard(AbilityCard* abilityCard);
    void showCards();
    PlayerCard operator+(MainCard mc);
    friend PlayerCard operator+(MainCard, const PlayerCard &);
    PlayerCard operator+(AbilityCard *ac);
    friend PlayerCard operator+(AbilityCard*, const PlayerCard &);
    PlayerCard &operator=(const PlayerCard &);
    PlayerCard operator-(int num);
};

#endif