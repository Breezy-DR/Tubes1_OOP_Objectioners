#include "Quadruple.hpp"


Quadruple::Quadruple() : AbilityCard(-3, "Quadruple", "Membuat poin hadiah berjumlah 4x dari sebelumnya.") {}

Quadruple::Quadruple(int holder) : AbilityCard(holder, "Quadruple", "Membuat poin hadiah berjumlah 4x dari sebelumnya.") {}

void Quadruple::useAbility() {
    if (this->isDisabled) {
        KartuDisabledException err;
        throw err;
    }
    if (this->isUsed) {
        KartuUsedException err2;
        throw err2;
    }

    Game game;
    long long newPrize = game.getPoolPrize() * 4;
    game.setPoolPrize(newPrize);
    this->isUsed = true;
}