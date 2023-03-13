#include "Card.hpp"
#include <iostream>

Card::Card(){
    holder = None;
}

Card::Card(int holder){
    this->holder = holder;
}

Card::~Card(){}

int Card::getHolder(){
    return holder;
}

void Card::setHolder(int holder){
    this->holder = holder;
}