#include "ReverseDirection.hpp"


ReverseDirection::ReverseDirection() : Ability("Reverse Direction", "Memutar arah giliran.") {}

void ReverseDirection::useAbility() {
    if (disabled) {
        KartuDisabledException err;
        throw err;
    }
}