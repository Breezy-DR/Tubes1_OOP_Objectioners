//
// Created by suisei on 3/13/23.
//

#ifndef TUBES1_OOP_OBJECTIONERS_PLAYER_HPP
#define TUBES1_OOP_OBJECTIONERS_PLAYER_HPP
#include "PlayerCard.hpp"
#include <string>
#include <iostream>
using namespace std;


class Player{
private:
    int ID;
    string playerName;
    PlayerCard playerCard;
    bool isCanUseAbility;
    long long int score;
public:
    Player(int id,string playerName){ 
        this->ID=id;
        this->playerName=playerName;
        this->isCanUseAbility= false;
        this->score=0;
    }

    void setPlayerCard(PlayerCard playerCard){ this->playerCard=playerCard;}
    void setCanUseAbility(bool isCanUse){ this->isCanUseAbility=isCanUse;}
    void setScore(long long int scr){this->score = scr;}
    int getPlayerId(){return this->ID;}
    PlayerCard getPlayerCard(){return this->playerCard;}
    string getPlayerName(){return this->playerName;}
    bool getIsCanUse(){return this->isCanUseAbility;}
    long long int getScore(){return this->score;}
    void showPlayerStatus(){
        cout<<"ID: "<< this->ID<<"\nName: "<< this->playerName<<"\nNormal card:\n";


        for (int i = 0; i < this->getPlayerCard().getMainCard().size(); ++i) {
            cout<< i+1<<"."<< this->getPlayerCard().getMainCard()[i]<<"\n";
        }
//        cout<< this->getPlayerCard()->getAbilityCard()->getAbility()->getAbilityName();
    }
    bool operator>(Player other){return this->getScore()>other.getScore();}
    bool operator<(Player other){return this->getScore()<other.getScore();}
    bool operator==(Player other){return this->getScore()==other.getScore();}
    
    bool REROLL(){
        if(getIsCanUse() && playerCard.getAbilityCard()->getAbilityName().compare("Re-Roll") == 0){
            playerCard.getAbilityCard()->useAbility();
            cout << "Player " << ID << " melakukan RE-ROLL"  << endl;
            return true;
        }
        return false;
    }
    
    void DOUBLE(){
        cout << "Player " << ID << " melakukan DOUBLE"  << endl;
    }

    bool QUADRUPLE(){
        if(getIsCanUse() && playerCard.getAbilityCard()->getAbilityName().compare("Quadruple") == 0){
            playerCard.getAbilityCard()->useAbility();
            cout << "Player " << ID << " melakukan QUADRUPLE"  << endl;
            return true;
        }
        return false;
    }

    void HALF(){
        cout << "Player " << ID << " melakukan HALF"  << endl;
    }

    bool QUARTER(){
        if(getIsCanUse() && playerCard.getAbilityCard()->getAbilityName().compare("Quarter") == 0){
            playerCard.getAbilityCard()->useAbility();
            cout << "Player " << ID << " melakukan QUARTER"  << endl;
            return true;
        }
        return false;
    }
    bool REVERSE(){
        if(getIsCanUse() && playerCard.getAbilityCard()->getAbilityName().compare("Reverse Direction") == 0){
            playerCard.getAbilityCard()->useAbility();
            cout << "Player " << ID << " melakukan REVERSE"  << endl;
            return true;
        }
        return false;
    }
    bool SWAPCARD(){
        if(getIsCanUse() && playerCard.getAbilityCard()->getAbilityName().compare("Swap Card") == 0){
            playerCard.getAbilityCard()->useAbility();
            cout << "Player " << ID << " melakukan SWAP CARD"  << endl;
            return true;
        }
        return false;
    }
    bool SWITCH(){
        if(getIsCanUse() && playerCard.getAbilityCard()->getAbilityName().compare("Switch") == 0){
            playerCard.getAbilityCard()->useAbility();
            cout << "Player " << ID << " melakukan SWITCH"  << endl;
            return true;
        }
        return false;
    }
    bool ABILITYLESS(){
        if(getIsCanUse() && playerCard.getAbilityCard()->getAbilityName().compare("Abilityless") == 0){
            playerCard.getAbilityCard()->useAbility();
            cout << "Player " << ID << " melakukan ABILITYLESS"  << endl;
            return true;
        }
        return false;
    }
};

#endif //TUBES1_OOP_OBJECTIONERS_PLAYER_HPP
