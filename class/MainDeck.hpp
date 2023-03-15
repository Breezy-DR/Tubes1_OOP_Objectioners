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
    MainDeck(const MainDeck&);
    MainDeck(string);
    ~MainDeck();
    MainDeck &operator=(const MainDeck&);
    bool isInside(MainCard);
    int getSize();
    MainCard draw();
    
};



#endif