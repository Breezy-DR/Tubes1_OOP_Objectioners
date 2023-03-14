#ifndef __ABILITY_HPP__
#define __ABILITY_HPP__
#include <string>
#include <iostream>
#include "../Exception.h"
#include "../Card.hpp"
using namespace std;


class Ability : public Card {
protected:
    string abilityName;
    string description;
//    bool disabled;
public:
    Ability();
    Ability(string, string, int);
    void setAbilityName(string);
    void setDescription(string);
    string getAbilityName();
    string getDescription();
    virtual void useAbility() = 0;
    friend ostream &operator<<(ostream &os, Ability& ac);
};


#endif