#ifndef __REVERSEDIRECTION_HPP__
#define __REVERSEDIRECTION_HPP__
#include "Ability.hpp"


class ReverseDirection : public Ability {
private:
public:
    ReverseDirection();
    ReverseDirection(int);
    void useAbility();
};


#endif