#include "class/Game.cpp"
//#include <iostream>
using namespace std;

int main(){
    int play = true;
    cout << "Selamat datang players!" << endl;
    while(play){
        Game game;
        string name;
        for(int i = 0; i < 7; i++){
            cout << "Selamat datang Player " << i + 1 << "! Silahkan masukkan nama anda: " << endl;
            cin >> name;
            game.setPlayer(name);
        }

        game.deckConfig();
        //cout << "DECK TEST\n";
        for(int i = 0; i < 52; i++){
            MainCard test = game.getMainDeck().draw();
            //cout << "Color: " << test.getColorName() << " Number: " << test.getNumber() << endl;
        }

        game.startGame();
        cout << "Jumlah kartu player 1: " << game.getPlayers()[0].getPlayerCard().getMainCard().size() << endl;
        cout << "GAME " << game.getGameCount() << endl;
        cout << "ROUND " << game.getRoundCount() << " START!" << endl;
        cout << "TURNS ORDER: ";
        for(int i = 0; i < 7; i++){
            cout << game.getTurns()[i].getPlayerId() << " ";
        }
        cout << endl;
        
        while(!game.checkPlayersScore()){
            cout << "Sisa kartu pada deck: " << game.getMainDeck().getSize() << endl;
            bool flag = true;
            while(flag){
                try{
                    game.startNextTurn();
                    flag = false;
                }catch(InvalidChoiceException err){
                    cout << err.what() << endl;
                }
            }
            if(game.getTurnCount() > 7){
                cout << "AKHIR RONDE\n";
                if(game.getRoundCount() == 1){
                    //cout << "Pre\n"; 
                    game.distributeAbilityCard();
                    //cout << "Post\n"; 
                }

                if(game.getRoundCount() != 6){
                    game.addTableCard();
                    cout<<"tablesizae" <<game.getTableCard().getMainCard().size()<<endl;
                }

                game.startNextRound();
                if(game.getRoundCount() == 1){
                    game.endGame();
                    if(!game.checkPlayersScore()){
                        game.showLeaderboard();
                        cout << "Score pemain belum ada yang mencapai 2^32, permainan berlanjut!!" << endl;
                        cout << "GAME " << game.getGameCount() << endl;
                        game.checkPlayersScore();
                    }
                }
                cout << "ROUND " << game.getRoundCount() << " START!" << endl;
                //cout << "TURNS SIZE: " << game.getTurns().size() << endl;
                cout << "TURNS ORDER: ";
                for(int i = 0; i < 7; i++){
                    cout << game.getTurns()[i].getPlayerId() << " ";
                }
                cout << endl;
            }
        }

        cout << "Permainan berakhir!\nLeaderboard akhir: " << endl;
        //Tunjukkan leaderboard
        cout << "Permainan dimenangkan oleh {pemenang}" << endl;
        bool flag = true;
        while(flag){
            try{
                string choice;
                cout << "Apakah ingin bermain lagi?\n1. Main lagi\n2. Exit\n";
                cin >> choice;

                //Error
                if(choice.compare("1") != 0  && choice.compare("2") != 0){
                    throw InvalidChoiceException();
                }

                flag = false;
                if(choice.compare("2") != 0){
                    play = false;
                }
            }catch(InvalidChoiceException err){
                cout << err.what() << endl;
            }
        }
    }
    


    return 0;
}