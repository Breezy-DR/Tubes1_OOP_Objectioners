#include "TableCard.hpp"

TableCard::TableCard() {}

TableCard::TableCard(const TableCard &tc)
{
    for (int i = 0; i < tc.MainTableCard.size(); ++i)
    {
        this->getMainTableCard().push_back(tc.MainTableCard.at(i));
    }
}

void TableCard::showCards()
{
    for (int i = 0; i < MainTableCard.size(); i++)
    {
        cout << MainTableCard[i] << " ";
    }
    cout << "\n";
}

vector<MainCard> TableCard::getMainTableCard() const
{
    return this->MainTableCard;
}

TableCard TableCard::operator+(MainCard mc)
{
    TableCard tc;
    tc.MainTableCard = this->getMainTableCard();
    tc.MainTableCard.push_back(mc);
    return tc;
}
TableCard operator+(MainCard mc, const TableCard &tc)
{
    TableCard newtc;
    newtc.MainTableCard = tc.getMainTableCard();
    newtc.MainTableCard.push_back(mc);
    return newtc;
}

TableCard &TableCard::operator=(const TableCard &tc)
{
    this->MainTableCard.clear();
    for (int i = 0; i < tc.MainTableCard.size(); ++i)
    {
        this->MainTableCard.push_back(tc.MainTableCard.at(i));
    }
    return *this;
}