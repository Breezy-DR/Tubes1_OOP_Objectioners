#include "SwapCard.hpp"


SwapCard::SwapCard() : Ability("Swap Card", "Menukar 1 kartu main deck milik pemain lain dengan 1 kartu main deck milik pemain lain.", -3) {}

SwapCard::SwapCard(int holder) : Ability("Swap Card", "Menukar 1 kartu main deck milik pemain lain dengan 1 kartu main deck milik pemain lain.", holder) {}

void SwapCard::useAbility() {
    if (disabled) {
        KartuDisabledException err;
        throw err;
    }
}