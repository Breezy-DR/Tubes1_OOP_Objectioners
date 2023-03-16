//
// Created by suisei on 3/16/23.
//

#include "Player.hpp"

class Game;

Player::Player(int id,string playerName){
    this->ID=id;
    this->playerName=playerName;
    this->isCanUseAbility= false;
    this->score=0;
}

void Player::setPlayerCard(PlayerCard playerCard){ this->playerCard=playerCard;}
void Player::setCanUseAbility(bool isCanUse){ this->isCanUseAbility=isCanUse;}
void Player::setScore(long long int scr){this->score = scr;}
int Player::getPlayerId(){return this->ID;}
PlayerCard Player::getPlayerCard(){return this->playerCard;}
string Player::getPlayerName(){return this->playerName;}
bool Player::getIsCanUse(){return this->isCanUseAbility;}
long long int Player::getScore(){return this->score;}
void Player::showPlayerStatus(){
    cout<<"ID: "<< this->ID<<"\nName: "<< this->playerName<<"\nNormal card:\n";


    for (int i = 0; i < this->getPlayerCard().getMainCard().size(); ++i) {
        cout<< i+1<<"."<< this->getPlayerCard().getMainCard()[i]<<"\n";
    }
//        cout<< this->getPlayerCard()->getAbilityCard()->getAbility()->getAbilityName();
}
bool Player::operator>(Player other){return this->getScore()>other.getScore();}
bool Player::operator<(Player other){return this->getScore()<other.getScore();}
bool Player::operator==(Player other){return this->getScore()==other.getScore();}

bool Player::REROLL(){
    if(getIsCanUse() && playerCard.getAbilityCard()->getAbilityName().compare("Re-Roll") == 0){
        playerCard.getAbilityCard()->useAbility();
        cout << "Player " << ID << " melakukan RE-ROLL"  << endl;
        return true;
    }
    return false;
}

void Player::DOUBLE(){
    cout << "Player " << ID << " melakukan DOUBLE"  << endl;
}

bool Player::QUADRUPLE(){
    if(getIsCanUse() && playerCard.getAbilityCard()->getAbilityName().compare("Quadruple") == 0){
        playerCard.getAbilityCard()->useAbility();
        cout << "Player " << ID << " melakukan QUADRUPLE"  << endl;
        return true;
    }
    return false;
}

void Player::HALF(){
    cout << "Player " << ID << " melakukan HALF"  << endl;
}

bool Player::QUARTER(){
    if(getIsCanUse() && playerCard.getAbilityCard()->getAbilityName().compare("Quarter") == 0){
        playerCard.getAbilityCard()->useAbility();
        cout << "Player " << ID << " melakukan QUARTER"  << endl;
        return true;
    }
    return false;
}
bool Player::REVERSE(){
    if(getIsCanUse() && playerCard.getAbilityCard()->getAbilityName().compare("Reverse Direction") == 0){
        playerCard.getAbilityCard()->useAbility();
        cout << "Player " << ID << " melakukan REVERSE"  << endl;
        return true;
    }
    return false;
}
bool Player::SWAPCARD(){
    if(getIsCanUse() && playerCard.getAbilityCard()->getAbilityName().compare("Swap Card") == 0){
        playerCard.getAbilityCard()->useAbility();
        cout << "Player " << ID << " melakukan SWAP CARD"  << endl;
        return true;
    }
    return false;
}
bool Player::SWITCH(){
    if(getIsCanUse() && playerCard.getAbilityCard()->getAbilityName().compare("Switch") == 0){
        playerCard.getAbilityCard()->useAbility();
        cout << "Player " << ID << " melakukan SWITCH"  << endl;
        return true;
    }
    return false;
}
bool Player::ABILITYLESS(){
    //cout << "ABILITYYY" << endl;
    if(getIsCanUse() && playerCard.getAbilityCard()->getAbilityName().compare("Abilityless") == 0){
        //cout << "masuk\n";
        playerCard.getAbilityCard()->useAbility();
        cout << "Player " << ID << " melakukan ABILITYLESS"  << endl;
        return true;
    }
    return false;
}