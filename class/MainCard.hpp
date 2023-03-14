#ifndef _MAINCARD_HPP_
#define _MAINCARD_HPP_

#include "Card.cpp"
#include <iostream>
#include <utility>
#include <string>
using namespace std;

enum Colors {Green = 0, Blue = 1, Yellow = 2, Red = 3};

class MainCard : public Card
{
private:
    pair<int, int> oneCard;
public:
    MainCard();
    MainCard(int _color, int _number, int _holder);
    ~MainCard();

    int getColor() const;
    int getNumber() const;
    friend ostream &operator<<(ostream &os, MainCard mc);
};



#endif