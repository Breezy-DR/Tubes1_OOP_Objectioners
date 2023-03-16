#include "InventoryHolder.hpp"

vector<MainCard> InventoryHolder::getMainCard() const
{
    return mainCard;
}

void InventoryHolder::setMainCards(vector<MainCard> mc){
    this->mainCard = mc;
}