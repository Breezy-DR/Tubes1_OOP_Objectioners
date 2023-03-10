#ifndef _MAINCARD_HPP_
#define _MAINCARD_HPP_

#include <iostream>
#include <string>
using namespace std;

class MainCard
{
private:
    string color;
    int number;
public:
    MainCard();
    MainCard(int _color, int _number);
    MainCard(const MainCard &mc);
    ~MainCard();

    string getColor() const;
    int getNumber() const;
    friend ostream &operator<<(ostream &os, MainCard mc);
};



#endif