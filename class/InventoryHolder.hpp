#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include <iostream>
#include <string>
#include "MainCard.hpp"
#include "Ability_Cards/AbilityCard.hpp"
using namespace std;

class InventoryHolder
{
private:
public:
    InventoryHolder(){}
    InventoryHolder(const InventoryHolder &){}
    virtual ~InventoryHolder(){}
    virtual void showCards()=0;
};

#endif