#ifndef __ABILITY_HPP__
#define __ABILITY_HPP__
#pragma once
class Game;
#include <string>
using namespace std;

class Ability {
protected:
    string abilityName;
    string description;
public:
    Ability();
    Ability(string, string);
    void setAbilityName(string);
    void setDescription(string);
    string getAbilityName();
    string getDescription();
    virtual void useAbility(){}
};


#endif