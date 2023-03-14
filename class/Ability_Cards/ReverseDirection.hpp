#ifndef __REVERSEDIRECTION_HPP__
#define __REVERSEDIRECTION_HPP__
#include "AbilityCard.hpp"


class ReverseDirection : public AbilityCard {
private:
public:
    ReverseDirection();
    ReverseDirection(int);
    void useAbility();
};


#endif