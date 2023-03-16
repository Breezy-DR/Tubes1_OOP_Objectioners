#include "ReRoll.hpp"


ReRoll::ReRoll() : AbilityCard(-3, "Re-Roll", "Membuang 2 kartu dari main deck yang dimiliki oleh diri sendiri dan mengambil ulang 2 kartu.") {}

ReRoll::ReRoll(int holder) : AbilityCard(holder, "Re-Roll", "Membuang 2 kartu dari main deck yang dimiliki oleh diri sendiri dan mengambil ulang 2 kartu.") {}

void ReRoll::useAbility(Game game) {
    if (this->isDisabled) {
        KartuDisabledException err;
        throw err;
    }
    if (this->isUsed) {
        KartuUsedException err2;
        throw err2;
    }
    this->isUsed = true;
    cout << "Melakukan pembuangan kartu yang sedang dimiliki" << endl;

    //Game game;
    vector<Player> players = game.getPlayers();
    players.at(this->holder-1).getPlayerCard() = players.at(this->holder-1).getPlayerCard() - 2;
    //players.at(this->holder-1).getPlayerCard() = players.at(this->holder-1).getPlayerCard() + 2;

    game.modifyPlayer(players.at(this->holder-1));
    cout << "Kamu mendapatkan 2 kartu baru yaitu:" << endl;
    cout << "1. " << players.at(this->holder-1).getPlayerCard().getMainCard().at(0).getColorName() << players.at(this->holder-1).getPlayerCard().getMainCard().at(0).getNumber() << endl;
    cout << "2. " << players.at(this->holder-1).getPlayerCard().getMainCard().at(1).getColorName() << players.at(this->holder-1).getPlayerCard().getMainCard().at(1).getNumber() << endl;
}