#include "TableCard.hpp"

void TableCard::showTableCard()
{
    for (int i = 0; i < MainTableCard.size(); i++)
    {
        cout << MainTableCard[i] << " ";
    }
}