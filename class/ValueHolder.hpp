#ifndef _VALUEHOLDER_HPP_
#define _VALUEHOLDER_HPP_

#include <iostream>
#include <string>
using namespace std;

class ValueHolder
{
protected:
    int val;
public:
    ValueHolder();
    ValueHolder(int);
    ValueHolder(const ValueHolder&);
    ~ValueHolder();
    virtual int value();
};





#endif