#include "Quarter.hpp"


Quarter::Quarter() : Ability("Quarter", "Membuat poin hadiah berjumlah 0.25x dari sebelumnya.") {}

void Quarter::useAbility() {
    if (disabled) {
        KartuDisabledException err;
        throw err;
    }    
}