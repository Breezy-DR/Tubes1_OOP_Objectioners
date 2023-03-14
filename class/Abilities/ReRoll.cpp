#include "ReRoll.hpp"


ReRoll::ReRoll() : Ability("Re-Roll", "Membuang 2 kartu dari main deck yang dimiliki oleh diri sendiri dan mengambil ulang 2 kartu.", -3) {}

ReRoll::ReRoll(int holder) : Ability("Re-Roll", "Membuang 2 kartu dari main deck yang dimiliki oleh diri sendiri dan mengambil ulang 2 kartu.", holder) {}

void ReRoll::useAbility() {
    if (disabled) {
        KartuDisabledException err;
        throw err;
    }
}