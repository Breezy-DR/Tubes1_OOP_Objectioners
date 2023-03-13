//
// Created by suisei on 3/12/23.
//

#ifndef TUBES1_OOP_OBJECTIONERS_ABILITYCARD_HPP
#define TUBES1_OOP_OBJECTIONERS_ABILITYCARD_HPP
#include "Abilities/Ability.hpp"
#include "Card.hpp"
#include <iostream>
#include <string>
using namespace std;

class AbilityCard:public Card,Ability{
private:
    Ability *ability;
    bool isUsed;
public:
    AbilityCard() : Card(), Ability() {
        this->isUsed = false;
    }
    AbilityCard(int _holder, string _abilityname, string _abilitydescription) :
        Card(_holder), Ability(_abilityname, _abilitydescription) {
            this->isUsed = false;
        }
    ~AbilityCard() {}
    void useCard(){
        this->ability->useAbility();
        this->isUsed = true;
    }
    friend ostream &operator<<(ostream &os, AbilityCard& ac) {
        os << "Holder       : " << ac.getHolder() << endl;
        os << "Ability name : " << ac.getAbilityName() << endl;
        os << "Description  : " << ac.getDescription() << endl;
        return os;
    }
};

#endif //TUBES1_OOP_OBJECTIONERS_ABILITYCARD_HPP
