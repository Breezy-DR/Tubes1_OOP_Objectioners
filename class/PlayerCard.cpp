#include "PlayerCard.hpp"

vector<Card *> PlayerCard::getMainPlayerCard()
{
    return MainPlayerCard;
}

PlayerCard::~PlayerCard(){}

PlayerCard::PlayerCard(const PlayerCard &){}

vector<Card *> PlayerCard::getMainPlayerCard() {}

Card *PlayerCard::getAbilityCard() {}

void PlayerCard::showCards() {}
