#include "TableCard.hpp"

TableCard::TableCard() {}

TableCard::TableCard(const TableCard &tc)
{
    for (int i = 0; i < tc.mainCard.size(); ++i)
    {
        this->getMainCard().push_back(tc.mainCard.at(i));
    }
}

void TableCard::showCards()
{
    for (int i = 0; i < mainCard.size(); i++)
    {
        cout << mainCard[i] << " ";
    }
    cout << "\n";
}

vector<MainCard> TableCard::getMainCard() const
{
    return this->mainCard;
}

TableCard TableCard::operator+(MainCard mc)
{
    TableCard tc;
    tc.mainCard = this->getMainCard();
    tc.mainCard.push_back(mc);
    return tc;
}
TableCard operator+(MainCard mc, const TableCard &tc)
{
    TableCard newtc;
    newtc.mainCard = tc.getMainCard();
    newtc.mainCard.push_back(mc);
    return newtc;
}

TableCard &TableCard::operator=(const TableCard &tc)
{
    this->mainCard.clear();
    for (int i = 0; i < tc.mainCard.size(); ++i)
    {
        this->mainCard.push_back(tc.mainCard.at(i));
    }
    return *this;
}