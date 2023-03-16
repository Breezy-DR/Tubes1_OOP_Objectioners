#include "Card.hpp"
#include <iostream>

Card::Card() : ValueHolder() {}

Card::~Card(){}

Card::Card(int holder){
    this->holder = holder;
}

int Card::getHolder(){
    return holder;
}

void Card::setHolder(int holder){
    this->holder = holder;
}
