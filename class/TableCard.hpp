#ifndef TABLECARD_HPP
#define TABLECARD_HPP

#include "InventoryHolder.hpp"
#include <vector>

class TableCard : public InventoryHolder
{
private:
    vector<MainCard> MainTableCard;

public:
    TableCard();
    TableCard(const TableCard &);
    ~TableCard();
    vector<MainCard> getMainCard() const;
    void showCards();
    TableCard operator+(MainCard mc);
    friend TableCard operator+(MainCard, const TableCard &);
    TableCard &operator=(const TableCard &);
};

#endif