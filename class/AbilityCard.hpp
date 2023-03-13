//
// Created by suisei on 3/12/23.
//

#ifndef TUBES1_OOP_OBJECTIONERS_ABILITYCARD_HPP
#define TUBES1_OOP_OBJECTIONERS_ABILITYCARD_HPP
#include "Abilities/Ability.hpp"
#include "Card.hpp"

class AbilityCard:public Card,Ability{
private:
    Ability *ability;
    bool isUsed;
public:
    void useCard(){ this->ability->useAbility();}
};

#endif //TUBES1_OOP_OBJECTIONERS_ABILITYCARD_HPP
