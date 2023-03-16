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

void PlayerCard::setAbilityCard(AbilityCard *abilityCard)
{
    this->abilityCard = abilityCard;
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
    pc.setAbilityCard(this->abilityCard);
    pc.mainCard.push_back(mc);
    return pc;
}

PlayerCard operator+(MainCard mainCard, const PlayerCard &playerCard)
{
    PlayerCard pc;
    pc.setAbilityCard(playerCard.abilityCard);
    pc.mainCard = playerCard.mainCard;
    pc.mainCard.push_back(mainCard);
    return pc;
}

PlayerCard PlayerCard::operator+(AbilityCard *ac)
{
    PlayerCard pc;
    pc.mainCard= this->mainCard;
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

PlayerCard PlayerCard::operator-(int num){
    PlayerCard pc;
    pc.mainCard= this->getMainCard();
    pc.setAbilityCard(this->getAbilityCard());
    for (int i = 0; i < num; ++i) {
        if (this->getMainCard().size()==0){
            return pc;
        }
        pc.mainCard.pop_back();
    }
    return pc;
}