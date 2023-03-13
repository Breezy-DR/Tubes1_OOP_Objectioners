#include "Ability.hpp"


Ability::Ability() {
    this->abilityName = "";
    this->description = "";
    this->disabled = false;
}

Ability::Ability(string abilityName, string description) {
    this->abilityName = abilityName;
    this->description = description;
    this->disabled = false;
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