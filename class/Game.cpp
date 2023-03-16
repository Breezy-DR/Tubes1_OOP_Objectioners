//
// Created by suisei on 3/16/23.
//

#include "Game.hpp"

int Game::roundCount=0;
int Game::turnCount=0;
int Game::gameCount=0;
bool Game::reversed=false;
vector<Player> Game::players;
vector<Player> Game::Turns;
long long int Game::poolPrize = 64;
MainDeck Game::mainDeck;
TableCard Game::table;

Game::Game(){
    roundCount = 0;
    gameCount = 0;
    turnCount = 0;
    poolPrize = 64;
    reversed = false;
}

Game::~Game(){}

//SETTERS

void Game::setPlayer(string playerName){
    players.push_back(Player(players.size() + 1, playerName));
}

void Game::modifyPlayer(Player player){
    int id = player.getPlayerId();
    players[id - 1] = player;

}

void Game::setMainDeck(string filename){
    mainDeck = MainDeck(filename);
}

void Game::setPoolPrize(long long int prize){
    poolPrize = prize;
}

void Game::toggleReverse(){
    if(reversed){
        reversed = false;
    }else{
        reversed = true;
    }
}


// GETTERS

string Game::getCommand(){
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
       command.compare("SWITCH") && command.compare("ABILITYLESS") != 0 && command.compare("SHOWMYCARDS") != 0 && command.compare("SHOWTABLECARDS") != 0){
        throw InvalidCommandException();
    }

    return command;
}

vector<Player> Game::getPlayers(){
    return players;
}

vector<Player> Game::getTurns(){
    return Turns;
}

bool Game::isReversed(){
    return reversed;
}

int Game::getStartingPlayerID(){
    return startingPlayerID;
}

int Game::getTurnCount(){
    return turnCount;
}

int Game::getRoundCount(){
    return roundCount;
}

int Game::getGameCount(){
    return gameCount;
}

long long int Game::getPoolPrize(){
    return poolPrize;
}

MainDeck Game::getMainDeck(){
    return mainDeck;
}



//GAME SEGMENTS

void Game::startGame(){
    roundCount = 1;
    gameCount = 1;
    turnCount = 1;
    startingPlayerID = 1;
    Turns = players;
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 2; j++){
            cout << "Player " << i + 1 << " mendapat kartu: " << endl;
            vector<MainCard> baru = players[i].getPlayerCard().getMainCard();
            baru.push_back(mainDeck.draw());

            cout << "Baru size: " << baru.size() << endl;

            players[i].setPlayerCard(PlayerCard(baru));
            cout << "player card size: " << players[i].getPlayerCard().getMainCard().size() << endl;
            cout << players[i].getPlayerCard().getMainCard()[j].getColorName() << players[i].getPlayerCard().getMainCard()[j].getNumber() << endl;
        }
    }
}

//Reverse turns (only affects remaining players haven't played this turn)
void Game::reverseTurns(){
    vector<Player> temp = Turns;
    int len = Turns.size();
    for(int i = 0; i < Turns.size(); i++){
        Turns[i] = temp[len - 1];
        len--;
    }
}

void Game::startNextTurn(){
    string command = getCommand();
    while(command.compare("SHOWMYCARDS") == 0 || command.compare("SHOWTABLECARDS") == 0){
        if(command.compare("SHOWMYCARDS") == 0){
            cout << "TURNS PLAYER CARD SIZE: " << Turns[0].getPlayerCard().getMainCard().size() << endl;
            players[Turns[0].getPlayerId() - 1].getPlayerCard().showCards();
        }else{
            table.showCards();
        }
        command = getCommand();
    }



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
        cout << "Player " << players[Turns[0].getPlayerId() - 1].getPlayerId() << " melakukan NEXT"  << endl;
    }else if(command.compare("QUADRUPLE") == 0){
        if(Turns[0].QUADRUPLE()){
            setPoolPrize(getPoolPrize() * 4);
        }
    }else if(command.compare("QUARTER") == 0){
        if(Turns[0].QUARTER()){
            setPoolPrize(floor(getPoolPrize() / 4));
            if(getPoolPrize() < 1){
                setPoolPrize(1);
            }
        }
    }else if(command.compare("REVERSE") == 0){
        if(Turns[0].REVERSE()){
            toggleReverse();
            reverseTurns();
        }
    }else if(command.compare("SWAPCARD") == 0){
        if(Turns[0].SWAPCARD()){

        }
    }else if(command.compare("SWITCH") == 0){
        Turns[0].SWITCH();
    }else{
        Turns[0].ABILITYLESS();
    }
    turnCount++;
    Turns.erase(Turns.begin());
}

//Initiate the next round
void Game::startNextRound(){
    if(roundCount == 6){
        roundCount = 0;
        gameCount++;
    }
    roundCount++;
    turnCount = 1;

    roundRobin();
    //cout << "TURNS SIZE START: " << Turns.size() << endl;
}

void Game::endGame(){
    cout << "Ronde terakhir berakhir!\nSaatnya menunjukkan kartu kalian!" << endl;
    vector<Combo> combos;
    Combo max;
    int maxID;
    for(int i = 0; i < 7; i++){
        cout << "Kartu " << players[i].getPlayerName() << endl;
        cout << "Error show\n";
        players[i].getPlayerCard().showCards();
        cout << "Error combo loop\n";
        cout << "COMBO TABLE SIZE: " << table.getMainCard().size() << endl;
        combos.push_back(Combo(table, players[i].getPlayerCard()));
        cout << "COMBO TABLE SIZE AFTER: " << combos[i].getTableCard().getMainCard().size() << endl;

    }
    cout << "Error combo\n";
    cout << "Combo size: " << combos.size() << endl;
    cout << "Combo value 0: " << combos[0].value() << endl;

    cout <<"BATAS\n";
    for(int i = 0; i < 7; i++){
        cout << "Combo Value player " << i + 1 << ": " << combos[i].value() << endl;
        if(i == 0){
            max = combos[i];
            maxID = players[i].getPlayerId();
        }else if(combos[i] > max){
            max = combos[i];
            maxID = players[i].getPlayerId();
        }
    }
    cout << "SINI" << endl;
    players[maxID - 1].setScore(getPoolPrize());

    cout << "Poin hadiah telah diberikan kepada " << players[maxID - 1].getPlayerName() << "." << endl;
}

void Game::addTableCard(){
    // table = table + mainDeck.draw();
    vector<MainCard> newmc=this->table.getMainCard();
    newmc.push_back(mainDeck.draw());
    cout<<"before"<<table.getMainCard().size()<<endl;
    setTableCard(newmc);
    cout<<"after"<<table.getMainCard().size()<<endl;
}

void Game::setTableCard(vector<MainCard> mc){
    table.setMainCards(mc);
}

void Game::deckConfig(){
    string option = "";
    while(option.compare("1") != 0 && option.compare("2") != 0){
        try{
            cout << "Bagaimana anda mau mengatur deck permainan?(Input 1 / 2)\n1)Random shuffle\n2)Read text file\n> ";
            cin >> option;
            if(option.compare("1") != 0 && option.compare("2") != 0){
                throw InvalidChoiceException();
            }
        }catch(InvalidChoiceException err){
            cout << err.what() << endl;
        }
    }

    if(option.compare("2") == 0){
        string filename;
        bool flag = true;
        while(flag){
            try{
                cout << "Masukkan directory text file yang akan digunakan:\n> ";
                cin >> filename;
                mainDeck = MainDeck();
                setMainDeck(filename);
                flag = false;
            }catch(InvalidFileException err){
                cout << err.what() << endl;
            }catch(InvalidCardException err){
                cout << err.what() << endl;
            }catch(TooManyCardsException err){
                cout << err.what() << endl;
            }catch(TooFewCardsException err){
                cout << err.what() << endl;
            }catch(DuplicateCardsException err){
                cout << err.what() << endl;
            }
        }
    }else{
        mainDeck  = MainDeck();
    }
}

void Game::distributeAbilityCard(){
    vector<int> randomizer;
    for(int i = 0; i < 7; i++){
        randomizer.push_back(i + 1);
    }

    for(int i = 0; i < 7; i++){
        srand(time(NULL));
        int random = rand() % randomizer.size();
        int picked = randomizer.at(random);
        switch(picked){
            case 1:
            {
                cout << "Player " << i + 1 << " mendapatkan ability QUDARUPLE" << endl;
                AbilityCard* ac = new Quadruple(i + 1);
                players[i].getPlayerCard().setAbilityCard(ac);
                cout << "BERHASIL\n";
                break;
            }
            case 2:
            {
                cout << "Player " << i + 1 << " mendapatkan ability QUARTER" << endl;
                AbilityCard* ac = new Quarter(i + 1);
                players[i].getPlayerCard().setAbilityCard(ac);
                cout << "BERHASIL\n";
                break;
            }
            case 3:
            {
                cout << "Player " << i + 1 << " mendapatkan ability REROLL" << endl;
                AbilityCard* ac = new ReRoll(i + 1);
                players[i].getPlayerCard().setAbilityCard(ac);
                cout << "BERHASIL\n";
                break;
            }
            case 4:
            {
                cout << "Player " << i + 1 << " mendapatkan ability REVERSE" << endl;
                AbilityCard* ac = new ReverseDirection(i + 1);
                players[i].getPlayerCard().setAbilityCard(ac);
                cout << "BERHASIL\n";
                break;
            }
            case 5:
            {
                cout << "Player " << i + 1 << " mendapatkan ability SWAP" << endl;
                AbilityCard* ac = new SwapCard(i + 1);
                players[i].getPlayerCard().setAbilityCard(ac);
                cout << "BERHASIL\n";
                break;
            }
            case 6:
            {
                cout << "Player " << i + 1 << " mendapatkan ability SWITCH" << endl;
                AbilityCard* ac = new Switch(i + 1);
                players[i].getPlayerCard().setAbilityCard(ac);
                cout << "BERHASIL\n";
                break;
            }
            default:
            {
                cout << "Player " << i + 1 << " mendapatkan ability ABILITYLESS" << endl;
                AbilityCard* ac = new Abilityless(i + 1);
                players[i].getPlayerCard().setAbilityCard(ac);
                cout << "BERHASIL\n";
                break;
            }

        }

        randomizer.erase(randomizer.begin() + random);
    }
}

void Game::showLeaderboard(){
    cout << "Leaderboard: " << endl;
    vector<Player> temp = players;
    vector<Player> sorted=temp;

    //Sort
//    for(int i = 0; i < 7; i++){
//        Player max = temp[0];
//        int pos = 0;
//        for(int j = 0; j < temp.size(); j++){
//            if(players[j].getScore() >= max.getScore()){
//                max = players[j];
//                pos = j;
//            }
//        }
//        sorted.push_back(max);
//        temp.erase(temp.begin() + pos);
//    }
    for(int i = 0; i < 7; i++){
        cout << i + 1 << ". " << sorted[i].getPlayerName() << ": " << players[i].getScore() << endl;
    }
}


//Get the next line of turns for the next round
void Game::roundRobin(){
    cout << "TURNS SIZE ROUND BEFORE: " << getTurns().size() << endl;
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
            //cout << "URUTAN " << i + 1 << " adalah player " << players[j].getPlayerId() << endl;
            Turns.push_back(players[j]);
            //cout << "URUTAN " << i + 1 << " adalah player " << Turns[i].getPlayerId() << endl;
            //cout << "SINI AMAN2\n";
            j++;
        }
    }
    cout << "TURNS SIZE ROUND: " << getTurns().size() << endl;
}

Player Game::getCurrentPlayer(){
    return Turns[0];

}

bool Game::checkPlayersScore(){
    long long int maxScore = pow(2, 32);
    for (int i = 0; i < this->getPlayers().size(); ++i) {
        if(this->getPlayers()[i].getScore() > maxScore){
            return true;
        }
    }
    return false;
}

TableCard Game::getTable(){
    return table;
}