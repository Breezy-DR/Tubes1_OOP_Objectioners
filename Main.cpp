#include "class/Game.hpp"
using namespace std;

int main(){
    Game game;
    cout << "Selamat datang players!" << endl;
    
    string name;
    for(int i = 0; i < 7; i++){
        cout << "Selamat datang Player " << i + 1 << "! Silahkan masukkan nama anda: " << endl;
        cin >> name;
        game.setPlayer(name);
    }

    game.startGame();
    cout << "GAME 1";
    while(!game.checkPlayersScore()){
        deckConfig(game);
        cout << "ROUND 1 START!" << endl;
        while(game.getRoundCount() <= 6){
            cout << "Player " << game.getCurrentPlayer().getPlayerId() << " TURN!" << endl; 
            game.startNextTurn();
            if(game.getTurnCount() > 7){
                game.startNextRound();
                cout << "ROUND " << game.getRoundCount() <<" START!" << endl;
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