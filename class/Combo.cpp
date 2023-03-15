#include "Combo.hpp"
#include <algorithm>


vector<MainCard> sortCard(vector<MainCard> cards);
bool findGreater(int* arr,int x,int arrsize);
bool findExact(int* arr,int x,int arrsize);

Combo::Combo() : ValueHolder() {
//    this->comboNum = None;
}

//Combo::Combo(int _val, int _comboNum) : ValueHolder(_val) {
//    this->comboNum = _comboNum;
//}
Combo::Combo(TableCard tableCard, PlayerCard playerCard) {
    this->playerCard=playerCard;
    this->tableCard=tableCard;
    vector<MainCard> mc;
    for (int i = 0; i < tableCard.getMainTableCard().size(); ++i) {
        mc.push_back(tableCard.getMainTableCard().at(i));
    }
    mc.push_back(playerCard.getMainPlayerCard().at(0));mc.push_back(playerCard.getMainPlayerCard().at(1));
    this->cardPool=mc;
}

Combo::~Combo() {}

int Combo::getCombo() {
//    return this->comboNum;
}

TableCard Combo::getTableCard(){
    return this->tableCard;
}
PlayerCard Combo::getPlayerCard(){
    return this->playerCard;
}

vector<MainCard> Combo::getCardPool(){
    return this->cardPool;
}

void Combo::setCombo(int comboNum) {
    this->comboNum = comboNum;
}

float Combo::value() {
    return ;
}

bool Combo::operator<(const Combo& c2) {
    return (this->comboNum < c2.comboNum);
}

bool Combo::operator>(const Combo& c2) {
    return (this->comboNum > c2.comboNum);
}

bool Combo::operator==(const Combo& c2) {
    return (this->comboNum == c2.comboNum);
}

bool Combo::checkStraightFlush(){
    MainCard firstHand(this->getPlayerCard().getMainPlayerCard().at(0));
    MainCard secondHand(this->getPlayerCard().getMainPlayerCard().at(1));
    vector<MainCard> tableCardvec= this->getTableCard().getMainTableCard();
    if (firstHand.getColor()== secondHand.getColor()){
        if (firstHand.getNumber()>secondHand.getNumber()){
            if (!(firstHand.getNumber()>secondHand.getNumber()+4)){
                for (int i = 0; i < tableCardvec.size(); ++i) {
                    
                }
            }
        }
    } else{
        for (int i = 0; i < 2; ++i) {

        }
    }
}

bool Combo::checkFourOfKind(){
    vector<MainCard> sorted= sortCard(this->getCardPool());
    bool isFourof= false;
    for (int i = 0; i < 5; ++i) {
        for (int j = i+1; j < 4; ++j) {
            if (sorted.at(i)!=sorted.at(j)){
                isFourof= false;
                break;
            } else{
                isFourof= true;
            }
        }
        if (isFourof){return true;}
    }
    return isFourof;
}
bool Combo::checkFullHouse(){

}
bool Combo::checkFlush(){
    bool isFlush= false;
    int[] sameLogoCounter={0,0,0,0};
    for (int i = 0; i < this->cardPool.size(); ++i) {
        if (this->cardPool.at(i).getColor()==Blue){
            sameLogoCounter[Blue]++;
        } else if (this->cardPool.at(i).getColor()==Green){
            sameLogoCounter[Green]++;
        } else if (this->cardPool.at(i).getColor()==Yellow){
            sameLogoCounter[Yellow]++;
        } else{
            sameLogoCounter[Red]++;
        }
    }
    return findGreater(sameLogoCounter,5,4);
}
bool Combo::checkStraight(){
    vector<MainCard> sorted= sortCard(this->cardPool);
    int straightCounter=1;
    for (int i = 7; i >= 4; ++i) {
        for (int j = i-1; j > i - 5; ++j) {
            if (sorted.at(i)-sorted.at(j)!=i-j){
                straightCounter=1;
                break;
            } else{
                straightCounter++;
            }
        }
        if (straightCounter==5){
            return true;
        }
    }
    return false;
}
vector<MainCard> Combo::getStraightCard(){
    vector<MainCard> sorted= sortCard(this->cardPool);
    vector<MainCard> ret;
    for (int i = 7; i >= 4; ++i) {
        for (int j = i-1; j > i - 5; ++j) {
            if (sorted.at(i)-sorted.at(j)!=i-j){
                straightCounter=1;
                break;
            } else{
                straightCounter++;
                ret.push_back()
            }
        }
        if (straightCounter==5){
            return true;
        }
    }
}
bool Combo::checkThreeOfKind(){
    vector<MainCard> sorted= sortCard(this->cardPool);
    int[] arr={0,0,0,0,0,0,0,0,0,0,0,0,0};
    for (int i = 7; i >=0 ; ++i) {
        arr[sorted.at(i)-1]++;
    }
    return findExact(arr,3,13);
}

bool Combo::checkTwoPair(){
    vector<MainCard> sorted= sortCard(this->cardPool);
    int[] arr={0,0,0,0,0,0,0,0,0,0,0,0,0};
    for (int i = 7; i >=0 ; ++i) {
        arr[sorted.at(i)-1]++;
    }
    return count(arr,arr+13,2)==2;
}
bool Combo::checkPair(){
    vector<MainCard> sorted= sortCard(this->cardPool);
    int[] arr={0,0,0,0,0,0,0,0,0,0,0,0,0};
    for (int i = 7; i >=0 ; ++i) {
        arr[sorted.at(i)-1]++;
    }
    return findExact(arr,2,13);
}
float Combo::getHighCard(){
    vector<MainCard> sorted= sortCard(this->cardPool);
    return sorted.at(1).value()
}

float Combo::getPair(){
    vector<MainCard> sorted= sortCard(this->cardPool);
//    vector<MainCard> ret;
    for (int i = 0; i < sorted.size()-1; ++i) {
        if (sorted.at(i).getNumber()== sorted.at(i+1).getNumber()){
//            ret.push_back(sorted.at(i));ret.push_back(sorted.at(i+1));
//            break;
            return (sorted.at(i).value()+sorted.at(i+1).value())+1.39;
        }
    }
    return ret;
}

float Combo::getThreeOfKind(){
    vector<MainCard> sorted= sortCard(this->cardPool);
//    vector<MainCard> ret;
    for (int i = 0; i < this->cardPool.size()-2; ++i) {
        if (sorted.at(i).getNumber()== sorted.at(i+1).getNumber()& sorted.at(i).getNumber()= sorted.at(i+2).getNumber()){
//            ret.push_back(sorted.at(i));ret.push_back(sorted.at(i+1));ret.push_back(sorted.at(i+2));
//            break;
            return (sorted.at(i).value()+sorted.at(i+1).value()+sorted.at(i+2))+1.39*3;
        }
    }
//    return ret;
}

float Combo::getTwoPair(){

}

float Combo::getFlush(){
    vector<MainCard> blueCards;
    vector<MainCard> greenCards;
    vector<MainCard> yellowCards;
    vector<MainCard> redCards;
    vector<MainCard> sorted= sortCard(this->cardPool);
    for (int i = 0; i < sorted.size(); ++i) {
        if (sorted.at(i).getColor()==Blue){blueCards.push_back(sorted.at(i))}
        else if (sorted.at(i).getColor()==Green){greenCards.push_back(sorted.at(i))}
        else if (sorted.at(i).getColor()==Yellow){yellowCards.push_back(sorted.at(i))}
        else {redCards.push_back(sorted.at(i))}
        if (blueCards.size()==5||greenCards.size()==5||yellowCards.size()==5||redCards.size()==5){
            break;
        }
    }
    if (blueCards.size()==5){return blueCards;}
    else if (greenCards.size()==5){return greenCards;}
    else if (yellowCards.size()==5){return yellowCards;}
    else {return redCards;}
}

float Combo::getFullHouse(){

}

float Combo::getFourOfKind(){
    vector<MainCard> sorted= sortCard(this->cardPool);
    vector<MainCard> ret;
    for (int i = 0; i < this->cardPool.size()-3; ++i) {
        if (this->cardPool.at(i).getNumber()== this->cardPool.at(i+1).getNumber()&&this->cardPool.at(i).getNumber()==this->cardPool.at(i+2).getNumber() && this->cardPool.at(i).getNumber()==this->cardPool.at(i+3)){
            ret.push_back(sorted.at(i));ret.push_back(sorted.at(i+1));ret.push_back(sorted.at(i+2));ret.push_back(sorted.at(i+3));
            break;
        }
    }
    return ret;
}

float Combo::getStraightFlush(){

}



vector<MainCard> sortCard(vector<MainCard> cards){
    sort(cards.begin(), cards.end(), [](const MainCard& lhs, const MainCard& rhs) {
//        return lhs.getNumber() < rhs.getNumber();
        return lhs>rhs;
    });
    for(auto it = cards.begin(); it != cards.end(); it++) {
        cout << it -> data << endl;
    }
}

bool findGreater(int* arr,int x,int arrsize){
    for (int i = 0; i < arrsize; ++i) {
        if (arr[i]>=x){
            return true;
        }
    }
    return false;
}

bool findExact(int* arr,int x,int arrsize){
    for (int i = 0; i < arrsize; ++i) {
        if (arr[i]==x){
            return true;
        }
    }
    return false;
}

