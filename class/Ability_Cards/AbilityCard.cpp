#include "AbilityCard.hpp"


AbilityCard::AbilityCard() : Card(), Ability() {
    this->isUsed = false;
    this->isDisabled = false;
}

AbilityCard::AbilityCard(int _holder, string _abilityName, string _abilityDescription) : Card(_holder), Ability(_abilityName, _abilityDescription) {
    this->isUsed = false;
    this->isDisabled = false;
}

AbilityCard::~AbilityCard() {}

float AbilityCard::value() {
    return 0;
}

bool AbilityCard::getIsUsed(){
    return isUsed;
}
bool AbilityCard::getIsDisabled(){
    return isDisabled;
}

void AbilityCard::setIsUsed(bool state){
    isUsed = state;
}
void AbilityCard::setIsDisabled(bool state){
    isDisabled = state;
}

ostream &operator<<(ostream &os, AbilityCard& ac) {
    os << "Holder       : " << ac.holder << endl;
    os << "Ability name : " << ac.abilityName << endl;
    os << "Description  : " << ac.description << endl;
    return os;
}