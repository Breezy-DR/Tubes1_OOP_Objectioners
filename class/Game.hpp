//
// Created by suisei on 3/13/23.
//

#ifndef TUBES1_OOP_OBJECTIONERS_GAME_HPP
#define TUBES1_OOP_OBJECTIONERS_GAME_HPP
#include "Player.hpp"
#include <vector>
#include <string>
using namespace std;

int Game::roundCount=0;
class Game{
private:
    vector<Player> players;

    static int roundCount;
public:
    Game(){}
    void setPlayer(string playerName){this->players.push_back(new Player(this->players.size()+1,playerName));}
    void executeCommand(string command){}
};


#endif //TUBES1_OOP_OBJECTIONERS_GAME_HPP
