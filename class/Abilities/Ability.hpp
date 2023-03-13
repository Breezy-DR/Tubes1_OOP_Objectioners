#ifndef __ABILITY_HPP__
#define __ABILITY_HPP__
#include <string>
#include "../Exception.h"
using namespace std;


class Ability {
protected:
    string abilityName;
    string description;
    bool disabled;
public:
    Ability();
    Ability(string, string);
    void setAbilityName(string);
    void setDescription(string);
    string getAbilityName();
    string getDescription();
    virtual void useAbility() = 0;
};


#endif