#ifndef __REROLL_HPP__
#define __REROLL_HPP__
#include "AbilityCard.hpp"


class ReRoll : public AbilityCard {
private:
public:
    ReRoll();
    ReRoll(int);
    void useAbility(Game);
};


#endif