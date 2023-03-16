#ifndef TUBES1_OOP_OBJECTIONERS_COMBO_HPP
#define TUBES1_OOP_OBJECTIONERS_COMBO_HPP

#include "PlayerCard.hpp"
#include "TableCard.hpp"
#include "MainCard.hpp"
#include "ValueHolder.hpp"
#include <iostream>
#include <string>
using namespace std;

//enum Combos {None = 0, HighCard = 1, Pair = 2, TwoPair = 3,
//        ThreeofAKind = 4, Straight = 5, Flush = 6,
//        FullHouse = 7, FourofAKind = 8, StraightFlush = 9};

class Combo : public ValueHolder {
    protected:
//        int comboNum;
        TableCard tableCard;
        PlayerCard playerCard;
        vector<MainCard> cardPool;
    public:
        Combo();
//        Combo(int _val, int _comboNum);
        Combo(TableCard,PlayerCard);
        ~Combo();
//        int getCombo();
//        void setCombo(int comboNum);
        float value();

        vector<MainCard> getCardPool();
        TableCard getTableCard();
        PlayerCard getPlayerCard();

        bool operator<(Combo c2);
        bool operator>(Combo c2);
        bool operator==(Combo c2);
        bool checkStraightFlush();
        bool checkFourOfKind();
        bool checkFullHouse();
        bool checkFlush();
        bool checkStraight();
        bool checkThreeOfKind();
        bool checkTwoPair();
        bool checkPair();
        float getHighCard();
        float getStraight();
        float getPair();
        float getThreeOfKind();
        float getTwoPair();
        float getFlush();
        float getFullHouse();
        float getFourOfKind();
        float getStraightFlush();

};


#endif
