//
// Created by suisei on 3/13/23.
//

#ifndef TUBES1_OOP_OBJECTIONERS_GAME_HPP
#define TUBES1_OOP_OBJECTIONERS_GAME_HPP
#include "Player.cpp"
#include <vector>
#include <string>
#include <math.h>
#include "PlayerCard.cpp"
#include "MainDeck.cpp"
#include "InventoryHolder.cpp"
#include "TableCard.cpp"
#include "Combo.cpp"
#include "ArrayComparer.hpp"
#include "Ability_Cards/AbilityCard.cpp"
#include "Ability_Cards/Ability.cpp"

#include "Ability_Cards/Abilityless.cpp"
#include "Ability_Cards/Quadruple.cpp"
#include "Ability_Cards/Quarter.cpp"
#include "Ability_Cards/ReRoll.cpp"
#include "Ability_Cards/ReverseDirection.cpp"
#include "Ability_Cards/SwapCard.cpp"
#include "Ability_Cards/Switch.cpp"
    
#include "Exception.h"
#pragma once
using namespace std;

class Game{
private:
    static vector<Player> players;
    static vector<Player> Turns;
    static bool reversed;
    static long long int poolPrize;
    static MainDeck mainDeck;

    int startingPlayerID;
    static int turnCount;
    static int roundCount;
    static int gameCount;
public:
    static TableCard table;
    Game();

    ~Game();

    //SETTERS

    void setPlayer(string playerName);
    void modifyPlayer(Player player);

    void setMainDeck(string filename);

    void setPoolPrize(long long int prize);

    void toggleReverse();


    // GETTERS

    string getCommand();

    vector<Player> getPlayers();

    vector<Player> getTurns();

    bool isReversed();

    int getStartingPlayerID();

    int getTurnCount();

    int getRoundCount();

    int getGameCount();

    long long int getPoolPrize();

    MainDeck getMainDeck();



    //GAME SEGMENTS

    void startGame();

    //Reverse turns (only affects remaining players haven't played this turn)
    void reverseTurns();

    void startNextTurn();

    //Initiate the next round
    void startNextRound();

    void endGame();
    void clearTable();

    void addTableCard();
    void clearHands();
    void setTableCard(vector<MainCard> tc);
    vector<MainCard> addtableVector();

    void deckConfig();

    void distributeAbilityCard();

    void showLeaderboard();


    //Get the next line of turns for the next round
    void roundRobin();

    Player getCurrentPlayer();

    bool checkPlayersScore();

    TableCard getTable();

    void setTableCard(vector<MainCard> mc);

};


#endif //TUBES1_OOP_OBJECTIONERS_GAME_HPP
