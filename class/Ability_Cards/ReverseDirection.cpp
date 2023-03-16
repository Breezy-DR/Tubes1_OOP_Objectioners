#include "ReverseDirection.hpp"


ReverseDirection::ReverseDirection() : AbilityCard(-3, "Reverse Direction", "Memutar arah giliran.") {}

ReverseDirection::ReverseDirection(int holder) : AbilityCard(holder, "Reverse Direction", "Memutar arah giliran.") {}

void ReverseDirection::useAbility() {
    if (this->isDisabled) {
        KartuDisabledException err;
        throw err;
    }
    if (this->isUsed) {
        KartuUsedException err2;
        throw err2;
    }    

    // Game game;
    // // game.set
    // this->isUsed = true;
}