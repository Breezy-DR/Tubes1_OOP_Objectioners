#include "SwapCard.hpp"


SwapCard::SwapCard() : AbilityCard(-3, "Swap Card", "Menukar 1 kartu main deck milik pemain lain dengan 1 kartu main deck milik pemain lain.") {}

SwapCard::SwapCard(int holder) : AbilityCard(holder, "Swap Card", "Menukar 1 kartu main deck milik pemain lain dengan 1 kartu main deck milik pemain lain.") {}

void SwapCard::useAbility() {
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
    int target1;
    int target2;
    vector<Player> players = game.getPlayers();

    cout << "Silahkan pilih pemain yang kartunya anda ingin tukar:" << endl;
    for (int i = 0; i < players.size(); i++) {
        if (players.at(i).getPlayerId() != this->holder) {
            cout << "Pemain " << players.at(i).getPlayerId() << " (" << players.at(i).getPlayerName() << ")" << endl;
        }
    }

    cin >> target1;
    cout << "Silahkan pilih pemain lainnya yang kartunya anda ingin tukar:" << endl;
    for (int i = 0; i < players.size(); i++) {
        if (players.at(i).getPlayerId() != this->holder && players.at(i).getPlayerId() != target1) {
            cout << "Pemain " << players.at(i).getPlayerId() << " (" << players.at(i).getPlayerName() << ")" << endl;
        }
    }
    cin >> target2;
    while (target2 == target1 || target2 == this->holder) {
        cout << "Masukan salah, silahkan masukkan kembali" << endl;
        cin >> target2;
    }
    target1--;
    target2--;

    int s1;
    int s2;
    MainCard temp;
    int s1Index;

    cout << "Silakan pilih kartu kanan/kiri " << players.at(target1).getPlayerId() << " (" << players.at(target1).getPlayerName() << ")" << ": " << endl;
    cout << "1. Kanan" << endl;
    cout << "2. Kiri" << endl;
    cin >> s1;
    while (s1 != 1 || s1 != 2) {
        cout << "Masukan salah, silahkan masukkan kembali" << endl;
        cin >> s1;
    }
    if (s1 == 1) {
        temp = players.at(target1).getPlayerCard().getMainCard().at(1);
        s1Index = 1;
    }
    else {
        temp = players.at(target1).getPlayerCard().getMainCard().at(0);
        s1Index = 0;
    }

    cout << "Silakan pilih kartu kanan/kiri " << players.at(target1).getPlayerId() << " (" << players.at(target1).getPlayerName() << ")" << ": " << endl;
    cout << "1. Kanan" << endl;
    cout << "2. Kiri" << endl;
    cin >> s2;
    while (s2 != 1 || s2 != 2) {
        cout << "Masukan salah, silahkan masukkan kembali" << endl;
        cin >> s2;
    }
    if (s2 == 1) {
        players.at(target1).getPlayerCard().getMainCard().at(s1Index) = players.at(target2).getPlayerCard().getMainCard().at(1);
        players.at(target2).getPlayerCard().getMainCard().at(1) = temp;
    }
    else {
        players.at(target1).getPlayerCard().getMainCard().at(s1Index) = players.at(target2).getPlayerCard().getMainCard().at(0);
        players.at(target2).getPlayerCard().getMainCard().at(0) = temp;
    }    
    game.modifyPlayer(players.at(target1));
    game.modifyPlayer(players.at(target2));
}