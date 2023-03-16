//
// Created by suisei on 3/13/23.
//

#ifndef TUBES1_OOP_OBJECTIONERS_GAME_HPP
#define TUBES1_OOP_OBJECTIONERS_GAME_HPP
#include "Player.hpp"
#include <vector>
#include <string>
#include <math.h>
#include "PlayerCard.cpp"
#include "MainDeck.cpp"
#include "InventoryHolder.cpp"
#include "TableCard.cpp"
#include "Combo.cpp"

#include "Ability_Cards/Abilityless.cpp"
#include "Ability_Cards/Quadruple.hpp"
#include "Ability_Cards/Quarter.hpp"
#include "Ability_Cards/ReRoll.hpp"
#include "Ability_Cards/ReverseDirection.hpp"
#include "Ability_Cards/SwapCard.hpp"
#include "Ability_Cards/Switch.hpp"
    
#include "Exception.h"
using namespace std;

class Game{
private:
    static vector<Player> players;
    static vector<Player> Turns;
    static bool reversed;
    static long long int poolPrize;
    static MainDeck mainDeck;
    static TableCard table;

    int startingPlayerID;
    static int turnCount;
    static int roundCount;
    static int gameCount;
public:
    Game(){
        roundCount = 0;
        gameCount = 0;
        turnCount = 0;
        poolPrize = 64;
        reversed = false;
    }

    ~Game(){}

    //SETTERS

    void setPlayer(string playerName){
        players.push_back(Player(players.size() + 1, playerName));
    }

    void modifyPlayer(Player player){
        int id = player.getPlayerId();
        players[id - 1] = player;
        
    }

    void setMainDeck(string filename){
        mainDeck = MainDeck(filename);
    }

    void setPoolPrize(long long int prize){
        poolPrize = prize;
    }

    void toggleReverse(){
        if(reversed){
            reversed = false;
        }else{
            reversed = true;
        }
    }


    // GETTERS

    string getCommand(){
        string command;
        cout << "Masukkan command!" << endl;
        cout << "> ";

        cin >> command;
        //Convert to uppercase
        for(int i = 0; i < command.length(); i++){
            if(command[i] > 90){
                command[i] -= 32;
            }
        }

        //cout << "Command: "

        if(command.compare("NEXT") != 0 && command.compare("DOUBLE") != 0 && command.compare("HALF") != 0 && command.compare("RE-ROLL") != 0 && 
        command.compare("QUADRUPLE") != 0 && command.compare("QUARTER") != 0 && command.compare("REVERSE") != 0 && command.compare("SWAPCARD") != 0 &&
        command.compare("SWITCH") && command.compare("ABILITYLESS") != 0){
            throw InvalidCommandException();
        }

        return command;
    }

    vector<Player> getPlayers(){
        return players;
    }

    vector<Player> getTurns(){
        return Turns;
    }

    bool isReversed(){
        return reversed;
    }

    int getStartingPlayerID(){
        return startingPlayerID;
    }

    int getTurnCount(){
        return turnCount;
    }

    int getRoundCount(){
        return roundCount;
    }

    int getGameCount(){
        return gameCount;
    }

    long long int getPoolPrize(){
        return poolPrize;
    }

    MainDeck getMainDeck(){
        return mainDeck;
    }



    //GAME SEGMENTS

    void startGame(){
        roundCount = 1;
        gameCount = 1;
        turnCount = 1;
        startingPlayerID = 1;
        Turns = players;
        for(int i = 0; i < 7; i++){
            for(int j = 0; j < 2; j++){
                players[i].setPlayerCard(players[i].getPlayerCard() + mainDeck.draw());
            }
        }
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
        string command = getCommand();
        if(command.compare("DOUBLE") == 0){
            Turns[0].DOUBLE();
            setPoolPrize(getPoolPrize() * 2);
        }else if(command.compare("HALF") == 0){
            Turns[0].HALF();
            setPoolPrize(floor(getPoolPrize() / 2));
            if(getPoolPrize() < 1){
                setPoolPrize(1);
            }
        }else if(command.compare("NEXT") == 0){
            cout << "Player " << Turns[0].getPlayerId() << " melakukan NEXT"  << endl;
        }else if(command.compare("QUADRUPLE") == 0){
            Turns[0].QUADRUPLE();
        }else if(command.compare("QUARTER") == 0){
            Turns[0].QUARTER();
        }else if(command.compare("REVERSE") == 0){
            Turns[0].REVERSE();
        }else if(command.compare("SWAPCARD") == 0){
            Turns[0].SWAPCARD();
        }else if(command.compare("SWITCH") == 0){
            Turns[0].SWITCH();
        }else{
            Turns[0].ABILITYLESS();
        }
        Turns.erase(Turns.begin());
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

    void endGame(){
        cout << "Ronde terakhir berakhir!\nSaatnya menunjukkan kartu kalian!" << endl;
        vector<Combo> combos;
        Combo max;
        int maxID;
        for(int i = 0; i < 7; i++){
            cout << "Kartu " << players[i].getPlayerName() << endl;
            players[i].getPlayerCard().showCards();
            combos.push_back(Combo(table, players[i].getPlayerCard()));
            cout << "Combo Value: " << combos[i].value() << endl;
            if(i == 0){
                max = combos[i];
                maxID = players[i].getPlayerId();
            }else if(combos[i] > max){
                max = combos[i];
                maxID = players[i].getPlayerId();
            }
        }

        players[maxID - 1].setScore(getPoolPrize());

        cout << "Poin hadiah telah diberikan kepada " << players[maxID - 1].getPlayerName() << "." << endl;
    }

    void addTableCard(){
        table = table + mainDeck.draw();
    }

    void distributeAbilityCard(){
        vector<int> randomizer;
        for(int i = 0; i < 7; i++){
            randomizer[i] = i + 1;
        }

        for(int i = 0; i < 7; i++){
            srand(time(NULL));
            int random = rand() % randomizer.size();
            int picked = randomizer.at(random);

            switch(picked){
                case 1:
                    AbilityCard* ac = new Quadruple(i + 1);
                    players[i].getPlayerCard().setAbilityCard(ac);
                case 2:
                    AbilityCard* ac = new Quarter(i + 1);
                    players[i].getPlayerCard().setAbilityCard(ac);
                case 3:
                    AbilityCard* ac = new ReRoll(i + 1);
                    players[i].getPlayerCard().setAbilityCard(ac);
                case 4:
                    AbilityCard* ac = new ReverseDirection(i + 1);
                    players[i].getPlayerCard().setAbilityCard(ac);
                case 5:
                    AbilityCard* ac = new SwapCard(i + 1);
                    players[i].getPlayerCard().setAbilityCard(ac);
                case 6:
                    AbilityCard* ac = new Switch(i + 1);
                    players[i].getPlayerCard().setAbilityCard(ac);
                default:
                    AbilityCard* ac = new Abilityless(i + 1);
                    players[i].getPlayerCard().setAbilityCard(ac);

            }

            randomizer.erase(randomizer.begin() + random);
        }
    }

    void showLeaderboard(){
        cout << "Leaderboard: " << endl;
        vector<Player> temp = players;
        for(int i = 0; i < 7; i++){
            cout << i + 1 << ". " << players[i].getPlayerName() << ": " << players[i].getScore() << endl;
            
        }
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

    Player getCurrentPlayer(){
        return Turns[0];        

    }

    bool checkPlayersScore(){
        long long int maxScore = pow(2, 32);
        for (int i = 0; i < this->getPlayers().size(); ++i) {
            if(this->getPlayers()[i].getScore() > maxScore){
                return true;
            }
        }
        return false;
    }

};

int Game::roundCount=0;
int Game::turnCount=0;
int Game::gameCount=0;
long long int Game::poolPrize = 0;
bool Game::reversed=false;
vector<Player> Game::players;
vector<Player> Game::Turns;
long long int Game::poolPrize = 64;
MainDeck Game::mainDeck;
TableCard Game::table;
#endif //TUBES1_OOP_OBJECTIONERS_GAME_HPP
