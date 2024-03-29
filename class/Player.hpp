//
// Created by suisei on 3/13/23.
//

#ifndef TUBES1_OOP_OBJECTIONERS_PLAYER_HPP
#define TUBES1_OOP_OBJECTIONERS_PLAYER_HPP
#include "PlayerCard.hpp"
//#include "Game.hpp"
#include <string>
#include <iostream>
#pragma once
using namespace std;

class Player{
private:
    int ID;
    string playerName;
    PlayerCard playerCard;
    bool isCanUseAbility;
    long long int score;
public:
    Player(int id,string playerName);

    void setPlayerCard(PlayerCard playerCard);
    void setCanUseAbility(bool isCanUse);
    void setScore(long long int scr);
    int getPlayerId();
    PlayerCard getPlayerCard();
    string getPlayerName();
    bool getIsCanUse();
    long long int getScore();
    void showPlayerStatus();
    bool operator>(Player other);
    bool operator<(Player other);
    bool operator==(Player other);
    
    bool REROLL();
    
    void DOUBLE();

    bool QUADRUPLE();

    void HALF();

    bool QUARTER();
    bool REVERSE();
    bool SWAPCARD();
    bool SWITCH();
    bool ABILITYLESS();
};

#endif //TUBES1_OOP_OBJECTIONERS_PLAYER_HPP
