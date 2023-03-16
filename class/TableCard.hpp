#ifndef TABLECARD_HPP
#define TABLECARD_HPP

#include "InventoryHolder.hpp"
#include <vector>

class TableCard : public InventoryHolder
{
public:
    TableCard();
    TableCard(const TableCard &);
    ~TableCard();
    void showCards();
    TableCard operator+(MainCard mc);
    friend TableCard operator+(MainCard, const TableCard &);
    TableCard &operator=(const TableCard &);
    vector<MainCard> getMainCard() const;
};

#endif