#include "Card.hpp"
#include <iostream>

Card::Card() : ValueHolder() {
    holder = None;
}

Card::Card(int holder) : ValueHolder() {
    this->holder = holder;
}

Card::~Card(){}

int Card::getHolder(){
    return holder;
}

void Card::setHolder(int holder){
    this->holder = holder;
}

int Card::value() {
    return this->val;
}