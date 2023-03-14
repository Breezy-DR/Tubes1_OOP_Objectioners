#include "Abilityless.hpp"

Abilityless::Abilityless() : AbilityCard(-3, "Abilityless", "Mematikan kartu ability milik pemain lain.") {}

Abilityless::Abilityless(int holder) : AbilityCard(holder, "Abilityless", "Mematikan kartu ability milik pemain lain.") {}

void Abilityless::useAbility() {
    if (this->isDisabled) {
        KartuDisabledException err;
        throw err;
    }    
}