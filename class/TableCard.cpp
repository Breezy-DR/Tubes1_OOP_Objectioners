#include "TableCard.hpp"

TableCard::TableCard(const TableCard &tc){
    for (int i = 0; i < tc.MainTableCard.size(); ++i) {
        this->getMainTableCard().push_back(tc.MainTableCard.at(i));
    }
}

void TableCard::showCards()
{
    for (int i = 0; i < MainTableCard.size(); i++)
    {
        cout << MainTableCard[i] << " ";
    }
}

vector<MainCard> TableCard::getMainTableCard(){
    return this->MainTableCard;
}

vector<MainCard> TableCard::operator+(MainCard mc){

}
vector<MainCard> operator+(TableCard& other,MainCard tc){

}

TableCard &TableCard::operator=(const TableCard &tc) {
    return
}