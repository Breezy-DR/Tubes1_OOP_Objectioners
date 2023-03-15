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
        this->score=64;
    }

    void setPlayerCard(PlayerCard playerCard){ this->playerCard=playerCard;}
    void setCanUseAbility(bool isCanUse){ this->isCanUseAbility=isCanUse;}
    int getPlayerId(){return this->ID;}
    PlayerCard getPlayerCard(){return this->playerCard;}
    string getPlayerName(){return this->playerName;}
    bool getIsCanUse(){return this->isCanUseAbility;}
    long long int getScore(){return this->score;}
    void showPlayerStatus(){
        cout<<"ID: "<< this->ID<<"\nName: "<< this->playerName<<"\nNormal card:\n";


        for (int i = 0; i < this->getPlayerCard().getMainPlayerCard().size(); ++i) {
            cout<< i+1<<"."<< this->getPlayerCard().getMainPlayerCard()[i]<<"\n";
        }
//        cout<< this->getPlayerCard()->getAbilityCard()->getAbility()->getAbilityName();
    }
    bool operator>(Player other){return this->getScore()>other.getScore();}
    bool operator<(Player other){return this->getScore()<other.getScore();}
    bool operator==(Player other){return this->getScore()==other.getScore();}
    void REROLL(){
        cout << "Player " << ID << " melakukan RE-ROLL"  << endl;
    }
    void DOUBLE(){
        cout << "Player " << ID << " melakukan DOUBLE"  << endl;
    }
    void QUADRUPLE(){
        cout << "Player " << ID << " melakukan QUADRUPLE"  << endl;
    }
    void HALF(){
        cout << "Player " << ID << " melakukan HALF"  << endl;
    }
    void QUARTER(){
        cout << "Player " << ID << " melakukan QUARTER"  << endl;
    }
    void REVERSE(){
        cout << "Player " << ID << " melakukan REVERSE"  << endl;
    }
    void SWAPCARD(){
        cout << "Player " << ID << " melakukan SWAP CARD"  << endl;
    }
    void SWITCH(){
        cout << "Player " << ID << " melakukan SWITCH"  << endl;
    }
    void ABILITYLESS(){
        cout << "Player " << ID << " melakukan ABILITYLESS"  << endl;
    }
};

#endif //TUBES1_OOP_OBJECTIONERS_PLAYER_HPP
