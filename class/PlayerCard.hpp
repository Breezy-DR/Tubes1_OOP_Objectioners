#ifndef PLAYERCARD_HPP
#define PLAYERCARD_HPP

#include "InventoryHolder.hpp"
#include <vector>

class PlayerCard : public InventoryHolder
{
private:
    vector<Card *> MainPlayerCard;
    Card *AbilityCard;

public:
    PlayerCard();
    PlayerCard(const PlayerCard &);
    ~PlayerCard();
    vector<Card *> getMainPlayerCard();
    void showPlayerCard();
};

#endif