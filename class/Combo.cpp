#include "Combo.hpp"

Combo::Combo() : ValueHolder() {
    this->comboNum = None;
}

Combo::Combo(int _val, int _comboNum) : ValueHolder(_val) {
    this->comboNum = _comboNum;
}

Combo::~Combo() {}

int Combo::getCombo() {
    return this->comboNum;
}

void Combo::setCombo(int comboNum) {
    this->comboNum = comboNum;
}

int Combo::value() {
    return this->val;
}

bool Combo::operator<(const Combo& c2) {
    return (this->comboNum < c2.comboNum);
}

bool Combo::operator>(const Combo& c2) {
    return (this->comboNum > c2.comboNum);
}

bool Combo::operator==(const Combo& c2) {
    return (this->comboNum == c2.comboNum);
}