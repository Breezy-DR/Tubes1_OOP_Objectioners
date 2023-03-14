#ifndef __Quarter_HPP__
#define __Quarter_HPP__
#include "AbilityCard.hpp"


class Quarter : public AbilityCard {
private:
public:
    Quarter();
    Quarter(int);
    void useAbility();
};


#endif