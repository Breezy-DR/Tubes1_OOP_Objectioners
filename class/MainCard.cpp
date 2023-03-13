#include "MainCard.hpp"

MainCard::MainCard() : Card() {
    this->oneCard = make_pair(0, 0);
}

MainCard::MainCard(int _color, int _number, int _holder) : Card(_holder) {
    this->oneCard = make_pair(_color, _number);
}

MainCard::~MainCard() {}

int MainCard::getColor() const {
    return this->oneCard.first;
}

int MainCard::getNumber() const {
    return this->oneCard.second;
}

ostream &operator<<(ostream &os, MainCard mc) {
    os << "Holder   : " << mc.getHolder() << endl;
    os << "Color    : " << mc.getColor() << endl;
    os << "Number   : " << mc.getNumber() << endl;
    return os;
}