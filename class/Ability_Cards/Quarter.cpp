#include "Quarter.hpp"


Quarter::Quarter() : AbilityCard(-3, "Quarter", "Membuat poin hadiah berjumlah 0.25x dari sebelumnya.") {}

Quarter::Quarter(int holder) : AbilityCard(holder, "Quarter", "Membuat poin hadiah berjumlah 0.25x dari sebelumnya.") {}

void Quarter::useAbility() {
    if (this->isDisabled) {
        KartuDisabledException err;
        throw err;
    }    
}