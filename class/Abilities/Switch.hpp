#ifndef __SWITCH_HPP__
#define __SWITCH_HPP__
#include "Ability.hpp"


class Switch : public Ability {
private:
public:
    Switch();
    Switch(int);
    void useAbility();
};


#endif