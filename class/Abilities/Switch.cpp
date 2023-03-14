#include "Switch.hpp"


Switch::Switch() : Ability("Switch", "Menukar 2 kartu main deck milik diri sendiri dengan 2 kartu main deck milik pemain lain.", -3) {}

Switch::Switch(int holder) : Ability("Switch", "Menukar 2 kartu main deck milik diri sendiri dengan 2 kartu main deck milik pemain lain.", holder) {}

void Switch::useAbility() {
    if (disabled) {
        KartuDisabledException err;
        throw err;
    }    
}