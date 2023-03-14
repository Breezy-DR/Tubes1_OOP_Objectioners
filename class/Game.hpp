//
// Created by suisei on 3/13/23.
//

#ifndef TUBES1_OOP_OBJECTIONERS_GAME_HPP
#define TUBES1_OOP_OBJECTIONERS_GAME_HPP
#include "Player.hpp"
#include <vector>
#include <string>
#include "Exception.h"
using namespace std;

class Game{
private:
    vector<Player> players;
    vector<Player> Turns;
    bool reversed;

    int startingPlayerID;
    int turnCount;
    int roundCount;
    int gameCount;
public:
    Game(){
        roundCount = 0;
        gameCount = 0;
        turnCount = 0;
        reversed = false;
    }

    void setPlayer(string playerName){
        players.push_back(Player(players.size() + 1, playerName));
    }

    string getCommand(){
        string command;
        cout << "> ";

        cin >> command;
        //Convert to uppercase
        for(int i = 0; i < command.length(); i++){
            command[i] -= 32;
        }

        if(command.compare("NEXT") != 0 && command.compare("DOUBLE") != 0 && command.compare("HALF") != 0 && command.compare("RE-ROLL") != 0 && 
        command.compare("QUADRUPLE") != 0 && command.compare("QUARTER") != 0 && command.compare("REVERSE") != 0 && command.compare("SWAPCARD") != 0 &&
        command.compare("SWITCH") && command.compare("ABILITYLESS") != 0){
            throw InvalidCommandException();
        }else{
            return command;
        }
    }

    void startGame(){
        roundCount = 1;
        gameCount = 1;
        turnCount = 1;
        startingPlayerID = 1;
        Turns = players;
    }

    //Reverse turns (only affects remaining players haven't played this turn)
    void reverseTurns(){
        vector<Player> temp = Turns;
        int len = Turns.size();
        for(int i = 0; i < Turns.size(); i++){
            Turns[i] = temp[len - 1];
            len--;
        }
    }

    void startNextTurn(){
        if(getCommand().compare("DOUBLE") == 0){

        }else if(getCommand().compare("HALF") == 0){

        }else if(getCommand().compare("NEXT") == 0){
            
        }else if(getCommand().compare("QUADRUPLE") == 0){
            
        }else if(getCommand().compare("QUARTER") == 0){
            
        }else if(getCommand().compare("REVERSE") == 0){
            
        }else if(getCommand().compare("SWAPCARD") == 0){
            
        }else if(getCommand().compare("SWITCH") == 0){
            
        }else{
            
        }
        //Turns[turnCount].
    }

    //Initiate the next round
    void startNextRound(){
        if(roundCount == 6){
            roundCount = 0;
            gameCount++;
        }
        roundCount++;
        turnCount = 1;
        roundRobin();
    }


    //Get the next line of turns for the next round
    void roundRobin(){
        if(reversed){
            if(startingPlayerID == 1){
                startingPlayerID = 7;
            }else{
                startingPlayerID--;
            }

            int j = startingPlayerID - 1;
            for(int i = 0; i < 7; i++){
                if(j == -1){
                    j = 6;
                }
                Turns[i] = players[j];
                j--;
            }
        }else{
            if(startingPlayerID == 7){
                startingPlayerID = 1;
            }else{
                startingPlayerID++;
            }

            int j = startingPlayerID - 1;
            for(int i = 0; i < 7; i++){
                if(j == 7){
                    j = 0;
                }
                Turns[i] = players[j];
                j++;
            }
        }
    }

    int getCurrentPlayer(int turn, vector<int> robinstate){
        return robinstate[turn];        
    }
};


#endif //TUBES1_OOP_OBJECTIONERS_GAME_HPP
