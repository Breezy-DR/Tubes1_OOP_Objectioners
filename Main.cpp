#include "class/Game.hpp"
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

        deckConfig(game);

        game.startGame();
        cout << "GAME " << game.getGameCount() << endl;
        while(!game.checkPlayersScore()){
            cout << "ROUND " << game.getRoundCount() << " START!" << endl;
            game.startNextTurn();
            if(game.getTurnCount() > 7){
                if(game.getRoundCount() == 1){
                    game.distributeAbilityCard();
                }

                if(game.getRoundCount() != 6){
                    game.addTableCard();
                }

                game.startNextRound();
                if(game.getRoundCount() == 1){
                    game.endGame();
                    if(!game.checkPlayersScore()){
                        game.showLeaderboard();
                        cout << "Score pemain belum ada yang mencapai 2^32, permainan berlanjut!!" << endl;
                        cout << "GAME " << game.getGameCount() << endl;
                        deckConfig(game);
                    }
                }
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

void deckConfig(Game game){
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
                game.setMainDeck(filename);
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
    }
}