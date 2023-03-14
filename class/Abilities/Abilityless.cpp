#include "Abilityless.hpp"


Abilityless::Abilityless() : Ability("Abilityless", "Mematikan kartu ability milik pemain lain.") {}

void Abilityless::useAbility() {
    if (disabled) {
        KartuDisabledException err;
        throw err;
    }    
}