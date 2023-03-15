#include "MainCard.hpp"

MainCard::MainCard() : Card() {
    this->oneCard = make_pair(0, 0);
}

MainCard::MainCard(int _color, int _number) : Card() {
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

bool MainCard::operator>(MainCard other) {
    return this->value()>other.value();
}

bool MainCard::operator<(MainCard other) {
    return this->value()<other.value();
}

bool MainCard::operator==(MainCard other) {
    return this->value()==other.value();
}

float MainCard::value() {
    return (float )this->getNumber()*0.1+ this->getColor()*0.03;
}

string MainCard::getColorName() const{
    if (this->getColor()==Blue){return "Blue";}
    else if (this->getColor()==Green){return "Green";}
    else if (this->getColor()==Yellow){return "Yellow";}
    else {return "Red";}
}