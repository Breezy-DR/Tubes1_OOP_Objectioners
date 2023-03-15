#include "PlayerCard.hpp"

PlayerCard::~PlayerCard(){}

PlayerCard::PlayerCard(const PlayerCard &pc){
    this->AbilityCard=pc.AbilityCard;
    for (int i = 0; i < pc.MainPlayerCard.size(); ++i) {
        this->MainPlayerCard.push_back(pc.MainPlayerCard.at(i))
    }
}

vector<MainCard> PlayerCard::getMainPlayerCard() {
    return this->MainPlayerCard;
}

AbilityCard PlayerCard::getAbilityCard() {
    return this->AbilityCard;
}

void PlayerCard::showCards() {
    cout<<"Main card: \n1. "<< this->getMainPlayerCard().at(0).getColorName()<<"\n";
    cout<<"2. "<< this->getMainPlayerCard().at(1).getColorName()<<"\n";
//    cout<<"Ability card: \n"<< this->getAbilityCard()->get
}

PlayerCard PlayerCard::operator+(MainCard mc){
    PlayerCard pc;
    pc.MainPlayerCard.push_back(mc);
    return pc;
}
PlayerCard operator+(MainCard mainCard,const PlayerCard& playerCard){
    PlayerCard pc;
    pc.MainPlayerCard=playerCard.MainPlayerCard;
    pc.MainPlayerCard.push_back(mainCard);
    return pc;
}
PlayerCard& PlayerCard::operator=(const PlayerCard& playerCard){
    this->MainPlayerCard=playerCard.MainPlayerCard;
    this->AbilityCard=playerCard.AbilityCard;
    return *this;
}