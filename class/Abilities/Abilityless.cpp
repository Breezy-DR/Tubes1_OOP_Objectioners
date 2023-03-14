#include "Abilityless.hpp"

Abilityless::Abilityless() : Ability("Abilityless", "Mematikan kartu ability milik pemain lain.", -3) {}

Abilityless::Abilityless(int holder) : Ability("Abilityless", "Mematikan kartu ability milik pemain lain.", holder) {}

void Abilityless::useAbility() {
    if (disabled) {
        KartuDisabledException err;
        throw err;
    }    
}