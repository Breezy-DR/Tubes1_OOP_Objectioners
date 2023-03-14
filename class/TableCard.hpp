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
    vector<MainCard> getMainTableCard();
    void showCards()=0;
    vector<MainCard> operator+(MainCard);
    friend vector<MainCard> operator+(TableCard&,MainCard);
    TableCard& operator=(const TableCard&);
};

#endif