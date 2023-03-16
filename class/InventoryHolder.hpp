#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include <iostream>
#include <vector>
#include "MainCard.hpp"
#include "Ability_Cards/AbilityCard.hpp"
#pragma once
using namespace std;

class InventoryHolder
{
protected:
    vector<MainCard> mainCard;

public:
    InventoryHolder() {}
    InventoryHolder(const InventoryHolder &) {}
    void setMainCards(vector<MainCard>);
    virtual ~InventoryHolder() {}
    virtual void showCards() = 0;
    virtual vector<MainCard> getMainCard() const;
};

#endif