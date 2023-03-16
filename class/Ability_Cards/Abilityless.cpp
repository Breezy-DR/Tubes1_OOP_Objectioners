#include "Abilityless.hpp"
using namespace std;


Abilityless::Abilityless() : AbilityCard(-3, "Abilityless", "Mematikan kartu ability milik pemain lain.") {}

Abilityless::Abilityless(int holder) : AbilityCard(holder, "Abilityless", "Mematikan kartu ability milik pemain lain.") {}

void Abilityless::useAbility() {
    if (this->isDisabled) {
        KartuDisabledException err;
        throw err;
    }
    if (this->isUsed) {
        KartuUsedException err2;
        throw err2;
    }
    // Game game;
    // vector<Player> players = game.getPlayers();
    // int target;
    // bool allUsed = true;

    // for (int i = 0; i < players.size(); i++) {
    //     if (players.at(i).getPlayerId() != this->holder) {
    //         if (!players.at(i).getPlayerCard().getAbilityCard()->getIsUsed()) {
    //             allUsed = false;
    //             break;
    //         }
    //     }
    // }

    // if (allUsed) {
    //     cout << "Yah telat pake abilityless, semua pemain udah pake ability mereka. Kamu kena sendiri deh abilityless" << endl;
    //     this->isDisabled = true;
    // }
    
    // else {
    //     cout << "Silahkan pilih pemain yang kartu abilitynya ingin dimatikan:" << endl;
    //     for (int i = 0; i < players.size(); i++) {
    //         if (players.at(i).getPlayerId() != this->holder) {
    //             cout << "Pemain " << players.at(i).getPlayerId() << " (" << players.at(i).getPlayerName() << ")" << endl;
    //         }
    //     }
    //     cout << "> ";
    //     cin >> target;
    //     while (target == this->holder) {
    //         cout << "Masukan salah! Silahkan masukkan kembali";
    //         cout << "> ";
    //         cin >> target;
    //     }
        
    //     target--;
    //     this->isUsed = true;
    //     if (players.at(target).getPlayerCard().getAbilityCard()->getIsUsed()) {
    //         cout << "Sayangnya pemain ini telah menggunakan kartu ability" << endl;
    //     }
    //     else {
    //         players.at(target).getPlayerCard().getAbilityCard()->setIsDisabled(true);
    //         game.modifyPlayer(players.at(target));
    //         cout << "kartu pemain " << players.at(target).getPlayerId() << "(" << players.at(target).getPlayerName() << ") telah terdisable" << endl;
    //     }
    // }
}