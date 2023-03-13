#include "Ability.hpp"


Ability::Ability() {
    this->abilityName="";
    this->description="";
}

Ability::Ability(string abilityName, string description) {
    this->abilityName = abilityName;
    this->description = description;
}

void Ability::setAbilityName(string abilityName) {
    this->abilityName = abilityName;
}

void Ability::setDescription(string description) {
    this->description = description;
}

string Ability::getAbilityName() {
    return this->abilityName;
}

string Ability::getDescription() {
    return this->description;
}