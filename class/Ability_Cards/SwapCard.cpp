#include "SwapCard.hpp"


SwapCard::SwapCard() : AbilityCard(-3, "Swap Card", "Menukar 1 kartu main deck milik pemain lain dengan 1 kartu main deck milik pemain lain.") {}

SwapCard::SwapCard(int holder) : AbilityCard(holder, "Swap Card", "Menukar 1 kartu main deck milik pemain lain dengan 1 kartu main deck milik pemain lain.") {}

void SwapCard::useAbility() {
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