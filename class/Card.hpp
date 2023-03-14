//
// Created by suisei on 3/12/23.
//

#ifndef TUBES1_OOP_OBJECTIONERS_CARD_HPP
#define TUBES1_OOP_OBJECTIONERS_CARD_HPP

#include "ValueHolder.hpp"

enum Owner {None = -3, abilityDeck = -2, mainDeck = -1, Table = 0, p1 = 1, p2 = 2, p3 = 3, p4 = 4, p5 = 5, p6 = 6, p7 = 7};

class Card : public ValueHolder {
protected:
    int holder;
public:
    Card();

    Card(int holder);

    virtual ~Card();

    int getHolder();

    void setHolder(int holder);

    virtual int value()=0;
};

#endif //TUBES1_OOP_OBJECTIONERS_CARD_HPP
