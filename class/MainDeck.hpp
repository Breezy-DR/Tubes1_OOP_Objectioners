#ifndef _MAINDECK_HPP_
#define _MAINDECK_HPP_

#include <stack>
#include "MainCard.cpp"

class MainDeck
{
private:
    int size;
    stack<MainCard> Cards;
public:
    MainDeck();
    MainDeck(string filepath);
    ~MainDeck();

    int getSize();
    MainCard draw();
    
};



#endif