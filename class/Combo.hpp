#ifndef TUBES1_OOP_OBJECTIONERS_COMBO_HPP
#define TUBES1_OOP_OBJECTIONERS_COMBO_HPP

#include "PlayerCard.hpp"
#include "TableCard.hpp"
#include "MainCard.hpp"
#include "ValueHolder.hpp"
#include <iostream>
#include <string>
using namespace std;

enum Combos {None = 0, HighCard = 1, Pair = 2, TwoPair = 3,
        ThreeofAKind = 4, Straight = 5, Flush = 6,
        FullHouse = 7, FourofAKind = 8, StraightFlush = 9};

class Combo : public ValueHolder {
    protected:
        int comboNum;
    public:
        Combo();
        Combo(int _val, int _comboNum);
        ~Combo();
        int getCombo();
        void setCombo(int comboNum);
        int value();
        bool operator<(const Combo& c2);
        bool operator>(const Combo& c2);
        bool operator==(const Combo& c2);
};


#endif
