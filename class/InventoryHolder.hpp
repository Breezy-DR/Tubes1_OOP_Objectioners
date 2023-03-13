#ifndef INVENTORYHOLDDER_HPP
#define INVENTORYHOLDER_HPP

#include <iostream>
#include <string>
using namespace std;

class InventoryHolder
{
private:
public:
    InventoryHolder();
    InventoryHolder(const InventoryHolder &);
    virtual ~InventoryHolder();
};

#endif