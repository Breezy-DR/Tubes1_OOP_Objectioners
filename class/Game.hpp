//
// Created by suisei on 3/13/23.
//

#ifndef TUBES1_OOP_OBJECTIONERS_GAME_HPP
#define TUBES1_OOP_OBJECTIONERS_GAME_HPP
#include "Player.hpp"
#include <vector>
#include <string>
#include <queue>
#include "ValueHolder.hpp"
#include <math.h>
using namespace std;


class Game{
private:
    vector<Player> players;
    Player currentPlayer
    queue roundQueue;
    static int roundCount;
public:
    Game(){}
    void setPlayer(string playerName){this->players.push_back(*(new Player(this->players.size()+1,playerName)));}
    vector<Player> getPlayers(){return this->players;}
    void executeCommand(string command){}
    void start(){
        cout<<"start\n";
        string userName;
        for (int i = 0; i < 7; ++i) {
            cin>>userName;
            this->setPlayer(userName);
        }
        string command;
        this->currentPlayer= this->players[0];
        while (!checkPlayersScore()){
            while (roundCount<=7) {
                cin >> command;
                roundCount++;
            }
        }
    }
    bool checkPlayersScore(){
        for (int i = 0; i < this->getPlayers().size(); ++i) {
            if(this->getPlayers()[i].getScore()> (2<<32)){
                return true;
            }
        }
        return false;
    }
};

int Game::roundCount=0;
#endif //TUBES1_OOP_OBJECTIONERS_GAME_HPP
