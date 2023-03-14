#include "Switch.hpp"


Switch::Switch() : AbilityCard(-3, "Switch", "Menukar 2 kartu main deck milik diri sendiri dengan 2 kartu main deck milik pemain lain.") {}

Switch::Switch(int holder) : AbilityCard(holder, "Switch", "Menukar 2 kartu main deck milik diri sendiri dengan 2 kartu main deck milik pemain lain.") {}

void Switch::useAbility() {
    if (this->isDisabled) {
        KartuDisabledException err;
        throw err;
    }    
}