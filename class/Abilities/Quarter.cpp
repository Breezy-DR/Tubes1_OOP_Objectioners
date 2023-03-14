#include "Quarter.hpp"


Quarter::Quarter() : Ability("Quarter", "Membuat poin hadiah berjumlah 0.25x dari sebelumnya.", -3) {}

Quarter::Quarter(int holder) : Ability("Quarter", "Membuat poin hadiah berjumlah 0.25x dari sebelumnya.", holder) {}

void Quarter::useAbility() {
    if (disabled) {
        KartuDisabledException err;
        throw err;
    }    
}