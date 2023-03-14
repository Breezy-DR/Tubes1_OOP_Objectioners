#ifndef TUBES1_OOP_OBJECTIONERS_COMBO_HPP
#define TUBES1_OOP_OBJECTIONERS_COMBO_HPP

#include "PlayerCard.hpp"
#include "TableCard.hpp"
#include "ValueHolder.hpp"
#include <iostream>
#include <string>
using namespace std;

enum Combos {None = 0}; // Tambahin kombo2nya nanti

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
};


#endif
