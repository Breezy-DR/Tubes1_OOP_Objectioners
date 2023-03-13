//
// Created by suisei on 3/13/23.
//

#ifndef TUBES1_OOP_OBJECTIONERS_PLAYER_HPP
#define TUBES1_OOP_OBJECTIONERS_PLAYER_HPP
#include "PlayerCard.hpp"
#include <string>
using namespace std;


class Player{
private:
    int ID;
    string playerName;
    PlayerCard playerCard;
public:
    Player(int id,string playerName){ this->ID=id;
        this->playerName=playerName;}
    void setPlayerCard(PlayerCard playerCard){ this->playerCard=playerCard;}
    int getPlayerId(){return this->ID;}
    string getPlayerName(){return this->playerName;}

};

#endif //TUBES1_OOP_OBJECTIONERS_PLAYER_HPP
