#ifndef PLAYERCARD_HPP
#define PLAYERCARD_HPP

#include "InventoryHolder.hpp"
#include <vector>

class PlayerCard : public InventoryHolder
{
private:
    vector<MainCard> MainPlayerCard;
    AbilityCard *abilityCard;

public:
    PlayerCard();
    PlayerCard(const PlayerCard &);
    ~PlayerCard();
    vector<MainCard> getMainCard() const;
    AbilityCard *getAbilityCard();
    void showCards();
    PlayerCard operator+(MainCard mc);
    friend PlayerCard operator+(MainCard, const PlayerCard &);
    PlayerCard &operator=(const PlayerCard &);
};

#endif