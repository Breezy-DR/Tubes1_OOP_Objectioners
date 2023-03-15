#include "PlayerCard.hpp"

PlayerCard::PlayerCard() {}

PlayerCard::~PlayerCard() {}

PlayerCard::PlayerCard(const PlayerCard &pc)
{
    this->abilityCard = pc.abilityCard;
    for (int i = 0; i < pc.mainCard.size(); ++i)
    {
        this->mainCard.push_back(pc.mainCard.at(i));
    }
}

AbilityCard *PlayerCard::getAbilityCard()
{
    return this->abilityCard;
}

void PlayerCard::showCards()
{
    cout << "Main card: \n1. " << this->getMainCard().at(0).getColorName() << "\n";
    cout << "2. " << this->getMainCard().at(1).getColorName() << "\n";
    //    cout<<"Ability card: \n"<< this->getAbilityCard()->get
}

PlayerCard PlayerCard::operator+(MainCard mc)
{
    PlayerCard pc;
    pc.mainCard.push_back(mc);
    return pc;
}
PlayerCard operator+(MainCard mainCard, const PlayerCard &playerCard)
{
    PlayerCard pc;
    pc.mainCard = playerCard.mainCard;
    pc.mainCard.push_back(mainCard);
    return pc;
}
PlayerCard &PlayerCard::operator=(const PlayerCard &playerCard)
{
    this->mainCard = playerCard.mainCard;
    this->abilityCard = playerCard.abilityCard;
    return *this;
}