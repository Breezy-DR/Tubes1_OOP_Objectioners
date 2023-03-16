#ifndef __Quarter_HPP__
#define __Quarter_HPP__
#include "AbilityCard.hpp"
#pragma once

class Quarter : public AbilityCard {
private:
public:
    Quarter();
    Quarter(int);
    void useAbility();
};


#endif