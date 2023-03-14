#include "Quadruple.hpp"


Quadruple::Quadruple() : Ability("Quadruple", "Membuat poin hadiah berjumlah 4x dari sebelumnya.", -3) {}

Quadruple::Quadruple(int holder) : Ability("Quadruple", "Membuat poin hadiah berjumlah 4x dari sebelumnya.", holder) {}

void Quadruple::useAbility() {
    if (disabled) {
        KartuDisabledException err;
        throw err;
    }
}