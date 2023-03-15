#include "ReRoll.hpp"


ReRoll::ReRoll() : AbilityCard(-3, "Re-Roll", "Membuang 2 kartu dari main deck yang dimiliki oleh diri sendiri dan mengambil ulang 2 kartu.") {}

ReRoll::ReRoll(int holder) : AbilityCard(holder, "Re-Roll", "Membuang 2 kartu dari main deck yang dimiliki oleh diri sendiri dan mengambil ulang 2 kartu.") {}

void ReRoll::useAbility() {
    if (this->isDisabled) {
        KartuDisabledException err;
        throw err;
    }
    if (this->isUsed) {
        KartuUsedException err2;
        throw err2;
    }
    this->isUsed = true;
}