#ifndef __QUADRUPLE_HPP__
#define __QUADRUPLE_HPP__
#include "AbilityCard.hpp"
#pragma once

class Quadruple : public AbilityCard {
private:
public:
    Quadruple();
    Quadruple(int);
    void useAbility();
};


#endif