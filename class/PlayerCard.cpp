#include "PlayerCard.hpp"

PlayerCard::PlayerCard() {}

PlayerCard::PlayerCard(vector<MainCard> mc) {
    this->setMainCards(mc);
}

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

void PlayerCard::setAbilityCard(AbilityCard *abilityCard)
{
    this->abilityCard = abilityCard;
}

void PlayerCard::showCards()
{   
    cout << "Maincards size: " << this->getMainCard().size() << endl;
    cout << "Main Card: \n";
    cout << "1. " << this->getMainCard()[0].getColorName() << this->getMainCard()[0].getNumber() << endl;
    cout << "2. " << this->getMainCard()[1].getColorName() << this->getMainCard()[1].getNumber() << endl;
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

PlayerCard PlayerCard::operator+(AbilityCard *ac)
{
    PlayerCard pc;
    pc.abilityCard = ac;
    return pc;
}

PlayerCard operator+(AbilityCard *abilityCard, const PlayerCard &playerCard)
{
    PlayerCard pc;
    pc = playerCard;
    pc.setAbilityCard(abilityCard);
    return pc;
}

PlayerCard &PlayerCard::operator=(const PlayerCard &playerCard)
{
    this->mainCard = playerCard.mainCard;
    this->abilityCard = playerCard.abilityCard;
    return *this;
}