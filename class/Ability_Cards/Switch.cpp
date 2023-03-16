#include "Switch.hpp"


Switch::Switch() : AbilityCard(-3, "Switch", "Menukar 2 kartu main deck milik diri sendiri dengan 2 kartu main deck milik pemain lain.") {}

Switch::Switch(int holder) : AbilityCard(holder, "Switch", "Menukar 2 kartu main deck milik diri sendiri dengan 2 kartu main deck milik pemain lain.") {}

void Switch::useAbility() {
    if (this->isDisabled) {
        KartuDisabledException err;
        throw err;
    }    
    if (this->isUsed) {
        KartuUsedException err2;
        throw err2;
    }
    this->isUsed = true;

    Game game;
    vector<Player> players = game.getPlayers();
    int target;

    cout << "Kartumu sekarang adalah:" << endl;
    cout << "1. " << players.at(this->holder-1).getPlayerCard().getMainCard().at(0).getColorName() << endl;
    cout << "2. " << players.at(this->holder-1).getPlayerCard().getMainCard().at(1).getColorName() << endl;

    cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
    for (int i = 0; i < players.size(); i++) {
        if (players.at(i).getPlayerId() != this->holder) {
            cout << "Pemain " << players.at(i).getPlayerId() << " (" << players.at(i).getPlayerName() << ")" << endl;
        }
    }
    cin >> target;
    while (target == this->holder || target < 1 || target > 7) {
        cout << "Masukan salah, silahkan masukkan kembali" << endl;
        cin >> target;
    }
    MainCard temp1 = players.at(this->holder-1).getPlayerCard().getMainCard().at(0);
    MainCard temp2 = players.at(this->holder-1).getPlayerCard().getMainCard().at(1);

    players.at(this->holder-1).getPlayerCard().getMainCard().at(0) = players.at(target-1).getPlayerCard().getMainCard().at(0);
    players.at(this->holder-1).getPlayerCard().getMainCard().at(0) = players.at(target-1).getPlayerCard().getMainCard().at(1);
    players.at(target-1).getPlayerCard().getMainCard().at(0) = temp1;
    players.at(target-1).getPlayerCard().getMainCard().at(1) = temp2;

    game.modifyPlayer(players.at(this->holder-1));
    game.modifyPlayer(players.at(target-1));
    cout << "Kedua kartu " << players.at(this->holder-1).getPlayerId() << " (" << players.at(this->holder-1).getPlayerName() << ") telah ditukar dengan " << players.at(target-1).getPlayerId() << " (" << players.at(target-1).getPlayerName() << ")" << endl;
    cout << "Kartumu sekarang:" << endl;
    cout << "1. " << players.at(this->holder-1).getPlayerCard().getMainCard().at(0).getColorName() << endl;
    cout << "2. " << players.at(this->holder-1).getPlayerCard().getMainCard().at(1).getColorName() << endl;
}