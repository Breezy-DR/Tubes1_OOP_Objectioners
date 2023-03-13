#ifndef ABILITY_HPP
#define ABILITY_HPP
#include <string>
using namespace std;

class Ability{
protected:
    string abilityName;
    string description;
public:
    Ability(){ this->abilityName="";
        this->description=""}
    string getAbilityName(){return this->abilityName;}
    string getDescription(){return this->description;}
    void setAbilityName(string abilityName){ this->abilityName=abilityName;}
    void setDescription(string description){ this->description=description;}
    virtual void executeAction()=0;
}

#endif