#include "Quarter.hpp"


Quarter::Quarter() : AbilityCard(-3, "Quarter", "Membuat poin hadiah berjumlah 0.25x dari sebelumnya.") {}

Quarter::Quarter(int holder) : AbilityCard(holder, "Quarter", "Membuat poin hadiah berjumlah 0.25x dari sebelumnya.") {}

void Quarter::useAbility() {
    if (this->isDisabled) {
        KartuDisabledException err;
        throw err;
    }
    if (this->isUsed) {
        KartuUsedException err2;
        throw err2;
    }
    this->isUsed = true;
    Game game;
    long long newPrize = game.getPoolPrize() / 4;
    if (newPrize < 1) {
        cout << "Prize pool bernilai paling kecil 1" << endl;
        game.setPoolPrize(1);
    }
    else {
        game.setPoolPrize(newPrize);
    }
}