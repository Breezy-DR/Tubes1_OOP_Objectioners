#include "ReverseDirection.hpp"


ReverseDirection::ReverseDirection() : Ability("Reverse Direction", "Memutar arah giliran.", -3) {}

ReverseDirection::ReverseDirection(int holder) : Ability("Reverse Direction", "Memutar arah giliran.", holder) {}

void ReverseDirection::useAbility() {
    if (disabled) {
        KartuDisabledException err;
        throw err;
    }
}