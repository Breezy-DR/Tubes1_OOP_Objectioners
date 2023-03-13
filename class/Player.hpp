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
public:
    Player(int id,string playerName){ this->ID=id;
        this->playerName=playerName;
        this->isCanUseAbility= false;}
    void setPlayerCard(PlayerCard playerCard){ this->playerCard=playerCard;}
    void setCanUseAbility(bool isCanUse){ this->isCanUseAbility=isCanUse;}
    int getPlayerId(){return this->ID;}
    string getPlayerName(){return this->playerName;}
    bool getIsCanUse(){return this->isCanUseAbility;};
    void showPlayerStatus(){
        cout<<"ID: "<< this->ID<<"\nName: "<< this->playerName<<"\nNormal card:\n";

        for (int i = 0; i < this->playerCard.getMainPlayerCard().size(); ++i) {
            cout<<""
        }
    }

};

#endif //TUBES1_OOP_OBJECTIONERS_PLAYER_HPP
