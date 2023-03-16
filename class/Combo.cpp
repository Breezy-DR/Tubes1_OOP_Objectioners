#include "Combo.hpp"
#include <algorithm>


vector<MainCard> sortCard(vector<MainCard> cards);
bool findGreater(int* arr,int x,int arrsize);
bool findExact(int* arr,int x,int arrsize);
float sumValue(vector<MainCard> arr);

Combo::Combo() : ValueHolder() {
//    this->comboNum = None;
}

//Combo::Combo(int _val, int _comboNum) : ValueHolder(_val) {
//    this->comboNum = _comboNum;
//}
Combo::Combo(const TableCard& Table, PlayerCard playerCard) {
    this->playerCard=playerCard;
    this->tableCard=Table;
    vector<MainCard> mc;
    cout<<"CONSTRUCTOR\n";
    cout<<"tablecard "<<Table.getMainCard().size()<<endl;
    cout<<"TABLECARDS: ";
    for (int i = 0; i < Table.getMainCard().size(); i++) {
        cout<<"<"<<Table.getMainCard().at(i).getNumber()<<","<<Table.getMainCard().at(i).getColorName()<<"> ";
    }
    cout<<"PLAYERCARDS: ";
    cout<<"<"<<playerCard.getMainCard().at(0).getNumber()<<","<<playerCard.getMainCard().at(0).getColorName()<<"> ";
    cout<<"<"<<playerCard.getMainCard().at(1).getNumber()<<","<<playerCard.getMainCard().at(1).getColorName()<<"> ";
    cout<<endl;
    for (int i = 0; i < Table.getMainCard().size(); i++) {
        mc.push_back(Table.getMainCard().at(i));
    }
    mc.push_back(playerCard.getMainCard().at(0));mc.push_back(playerCard.getMainCard().at(1));
    this->cardPool=mc;
//    for (int i = 0; i < mc.size(); ++i) {
//        cout<<"<"<<mc.at(i).getNumber()<<","<<"> ";
//    }
//    cout<<endl;
    // for (int i = 0; i < mc.size(); i++)
    // {
    //     cout<<mc.at(i).value()<<" ";
    // }
    // cout<<endl;
}

Combo::~Combo() {}

//int Combo::getCombo() {
//    return this->comboNum;
//}

TableCard Combo::getTableCard(){
    return this->tableCard;
}
PlayerCard Combo::getPlayerCard(){
    return this->playerCard;
}

vector<MainCard> Combo::getCardPool(){
    return this->cardPool;
}

//void Combo::setCombo(int comboNum) {
//    this->comboNum = comboNum;
//}

float Combo::value() {
    if (this->checkStraightFlush()){return this->getStraightFlush();}
    else if(this->checkFourOfKind()){return this->getFourOfKind();}
    else if(this->checkFullHouse()){return this->getFullHouse();}
    else if(this->checkFlush()){return this->getFlush();}
    else if(this->checkStraight()){return this->getStraight();}
    else if (this->checkThreeOfKind()){return this->getThreeOfKind();}
    else if (this->checkTwoPair()){return this->getTwoPair();}
    else if (this->checkPair()){return this->checkPair();}
    else {return this->getHighCard();}
}

bool Combo::operator<(Combo c2) {
    return (this->value() < c2.value());
}

bool Combo::operator>(Combo c2) {
    return (this->value() > c2.value());
}

bool Combo::operator==(Combo c2) {
    return (this->value() == c2.value());
}

bool Combo::checkStraightFlush(){
//    cout<<this->cardPool.size();
//    cout<<"sf in\n";
    vector<MainCard> sorted= (new ArrayComparer<MainCard>(this->cardPool))->sort();
//    cout<<"sf sorted\n";
//    for (int i = 0; i < sorted.size(); i++)
//    {
//        cout<<sorted.at(i).value()<<" ";
//    }
//    cout<<endl;
    for (int i = sorted.size()-1; i >= 4; i--){
        for (int j = i-1; j >=3; j--) {
            if (sorted.at(i).getNumber()==sorted.at(j).getNumber()+1 && sorted.at(i).getColor()==sorted.at(j).getColor()){
                for (int k = j-1; k >=2 ; k--) {
                    if (sorted.at(j).getNumber()==sorted.at(k).getNumber()+1 && sorted.at(j).getColor()==sorted.at(k).getColor()){
                        for (int l = k-1; l >=1 ; l--) {
                            if (sorted.at(k).getNumber()==sorted.at(l).getNumber()+1 && sorted.at(k).getColor()==sorted.at(l).getColor()){
                                for (int m = l-1; m >=0; m--) {
                                    if (sorted.at(l).getNumber()==sorted.at(m).getNumber()+1 && sorted.at(l).getColor()==sorted.at(m).getColor()){
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
//    cout<<"end\n";
    return false;
}

bool Combo::checkFourOfKind(){
//    vector<MainCard> sorted= sortCard(this->getCardPool());
//    bool isFourof= false;
//    for (int i = 0; i < 5; ++i) {
//        for (int j = i+1; j < 4; ++j) {
//            if (sorted.at(i)!=sorted.at(j)){
//                isFourof= false;
//                break;
//            } else{
//                isFourof= true;
//            }
//        }
//        if (isFourof){return true;}
//    }
//    return isFourof;
//    cout<<"fok in\n";
    vector<MainCard> sorted= (new ArrayComparer<MainCard>(this->cardPool))->sort();
//    cout<<"fok sorted\n";
    for (int i = sorted.size()-1; i >=3; i--) {
        if (sorted.at(i).getNumber()==sorted.at(i-1).getNumber()&&sorted.at(i).getNumber()==sorted.at(i-2).getNumber()&&sorted.at(i).getNumber()==sorted.at(i-3).getNumber()){
            return true;
        }
    }
//    cout<<"end\n";
    return false;
}
bool Combo::checkFullHouse(){
//    cout<<"fh in\n";
    vector<MainCard> sorted= (new ArrayComparer<MainCard>(this->cardPool))->sort();
//    cout<<"fh sorted\n";
    for (int i = sorted.size()-1; i >=2; i--) {
        if (sorted.at(i).getNumber()==sorted.at(i-1).getNumber()&&sorted.at(i).getNumber()==sorted.at(i-2).getNumber()){
            for (int j = i-3; j >= 1; j--) {
                if (sorted.at(j).getNumber()==sorted.at(j-1).getNumber()){
                    return true;
                }
            }
        } else if (sorted.at(i).getNumber()==sorted.at(i-1).getNumber()&&sorted.at(i).getNumber()!=sorted.at(i-2).getNumber()){
            for (int j = i-2; j >= 2; j--){
                if (sorted.at(j).getNumber()==sorted.at(j-1).getNumber()&&sorted.at(j).getNumber()==sorted.at(j-2).getNumber()){
                    return true;
                }
            }
        }
    }
//    cout<<"end\n";
    return false;
}
bool Combo::checkFlush(){
//    bool isFlush= false;
//    int[] sameLogoCounter={0,0,0,0};
//    for (int i = 0; i < this->cardPool.size(); ++i) {
//        if (this->cardPool.at(i).getColor()==Blue){
//            sameLogoCounter[Blue]++;
//        } else if (this->cardPool.at(i).getColor()==Green){
//            sameLogoCounter[Green]++;
//        } else if (this->cardPool.at(i).getColor()==Yellow){
//            sameLogoCounter[Yellow]++;
//        } else{
//            sameLogoCounter[Red]++;
//        }
//    }
//    return findGreater(sameLogoCounter,5,4);
    vector<MainCard> blueCards;
    vector<MainCard> greenCards;
    vector<MainCard> yellowCards;
    vector<MainCard> redCards;
//    cout<<"f in\n";
    vector<MainCard> sorted= (new ArrayComparer<MainCard>(this->cardPool))->sort();
//    cout<<"f sorted\n";
    for (int i = sorted.size()-1; i >= 0; i--) {
        if (sorted.at(i).getColor()==Blue){blueCards.push_back(sorted.at(i));}
        else if (sorted.at(i).getColor()==Green){greenCards.push_back(sorted.at(i));}
        else if (sorted.at(i).getColor()==Yellow){yellowCards.push_back(sorted.at(i));}
        else {redCards.push_back(sorted.at(i));}
        if (blueCards.size()==5||greenCards.size()==5||yellowCards.size()==5||redCards.size()==5){
            return true;
        }
    }
//    cout<<"end\n";
    return false;
}
bool Combo::checkStraight(){
//    cout<<"s in\n";
    vector<MainCard> sorted= (new ArrayComparer<MainCard>(this->cardPool))->sort();
//    cout<<"s sorted\n";
    for (int i = sorted.size()-1; i >= 4; i--){
        for (int j = i-1; j >=3; j--) {
            if (sorted.at(i).getNumber()==sorted.at(j).getNumber()+1){
                for (int k = j-1; k >=2 ; k--) {
                    if (sorted.at(j).getNumber()==sorted.at(k).getNumber()+1){
                        for (int l = k-1; l >=1 ; l--) {
                            if (sorted.at(k).getNumber()==sorted.at(l).getNumber()+1){
                                for (int m = l-1; m >=0; m--) {
                                    if (sorted.at(l).getNumber()==sorted.at(m).getNumber()+1){
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
//    cout<<"end\n";
    return false;
}

bool Combo::checkThreeOfKind(){
//    cout<<"tok in\n";
    vector<MainCard> sorted= (new ArrayComparer<MainCard>(this->cardPool))->sort();
//    cout<<"tok sorted\n";
    for (int i = sorted.size()-1; i >=2; i--) {
        if (sorted.at(i).getNumber()== sorted.at(i-1).getNumber()&&sorted.at(i).getNumber()==sorted.at(i-2).getNumber()){
            return true;
        }
    }
//    cout<<"end\n";
    return false;
}

bool Combo::checkTwoPair(){
//    vector<MainCard> sorted= (new ArrayComparer<MainCard>(this->cardPool))->sort();
//    int[] arr={0,0,0,0,0,0,0,0,0,0,0,0,0};
//    for (int i = 7; i >=0 ; ++i) {
//        arr[sorted.at(i)-1]++;
//    }
//    return count(arr,arr+13,2)==2;
//    cout<<"tp in\n";
    vector<MainCard> sorted= (new ArrayComparer<MainCard>(this->cardPool))->sort();
//    cout<<"tp sorted\n";
    for (int i = sorted.size()-1; i >= 3; i--) {
        if (sorted.at(i).getNumber()==sorted.at(i-1).getNumber()){
            for (int j = i-2; j >=1; j--) {
                if (sorted.at(j).getNumber()==sorted.at(j-1).getNumber()){
                    return true;
                }
            }
        }
    }
//    cout<<"end\n";
    return false;
}
bool Combo::checkPair(){
//    cout<<"p in\n";
    vector<MainCard> sorted= (new ArrayComparer<MainCard>(this->cardPool))->sort();
//    cout<<"p sorted\n";
    for (int i = sorted.size()-1; i >=1; i--) {
        if (sorted.at(i).getNumber()== sorted.at(i-1).getNumber()){
            return true;
        }
    }
//    cout<<"end\n";
    return false;
}

float Combo::getHighCard(){
    vector<MainCard> sorted= (new ArrayComparer<MainCard>(this->cardPool))->sort();
    return sorted.at(1).value();
}

float Combo::getPair(){
    vector<MainCard> sorted= (new ArrayComparer<MainCard>(this->cardPool))->sort();
    for (int i = sorted.size()-1; i >=1; i--) {
        if (sorted.at(i).getNumber()== sorted.at(i-1).getNumber()){
            return (sorted.at(i).value()+sorted.at(i-1).value())+1.39;
        }
    }
    return 0;
}

float Combo::getThreeOfKind(){
    vector<MainCard> sorted= (new ArrayComparer<MainCard>(this->cardPool))->sort();
    for (int i = sorted.size()-1; i >=2; i--) {
        if (sorted.at(i).getNumber()== sorted.at(i-1).getNumber()&&sorted.at(i).getNumber()==sorted.at(i-2).getNumber()){
            return (sorted.at(i).value()+sorted.at(i-1).value() + sorted.at(i-2).value())+9.47;
        }
    }
    return 0;
}

float Combo::getTwoPair(){
    vector<MainCard> sorted= (new ArrayComparer<MainCard>(this->cardPool))->sort();
    for (int i = sorted.size()-1; i >= 3; i--) {
        if (sorted.at(i).getNumber()==sorted.at(i-1).getNumber()){
            for (int j = i-2; j >=1; j--) {
                if (sorted.at(j).getNumber()==sorted.at(j-1).getNumber()){
                    return (sorted.at(i).value()+sorted.at(i-1).value()+sorted.at(j).value()+sorted.at(j-1).value())+1.39*3;
                }
            }
        }
    }
    return 0;
}

float Combo::getStraight(){
    vector<MainCard> sorted= (new ArrayComparer<MainCard>(this->cardPool))->sort();
//    for (int i = sorted.size()-1; i >= 4; i--) {
//        if (sorted.at(i).getNumber()== sorted.at(i-1).getNumber()+1&&sorted.at(i).getNumber()==sorted.at(i-2).getNumber()+2
//        &&sorted.at(i).getNumber()==sorted.at(i-3).getNumber()+3&&sorted.at(i).getNumber()==sorted.at(i-4).getNumber()-4){
//            return (sorted.at(i).value()+sorted.at(i-1).value()+sorted.at(i-2).value()+sorted.at(i-3).value()+sorted.at(i-4).value())+13.55;
//        }
//    }
    for (int i = sorted.size()-1; i >= 4; i--){
        for (int j = i-1; j >=3; j--) {
            if (sorted.at(i).getNumber()==sorted.at(j).getNumber()+1){
                for (int k = j-1; k >=2 ; k--) {
                    if (sorted.at(j).getNumber()==sorted.at(k).getNumber()+1){
                        for (int l = k-1; l >=1 ; l--) {
                            if (sorted.at(k).getNumber()==sorted.at(l).getNumber()+1){
                                for (int m = l-1; m >=0; m--) {
                                    if (sorted.at(l).getNumber()==sorted.at(m).getNumber()+1){
                                        return (sorted.at(i).value()+sorted.at(j).value()+sorted.at(k).value()+sorted.at(l).value()+sorted.at(m).value())+13.55;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

float Combo::getFlush(){
    vector<MainCard> blueCards;
    vector<MainCard> greenCards;
    vector<MainCard> yellowCards;
    vector<MainCard> redCards;
    vector<MainCard> sorted= (new ArrayComparer<MainCard>(this->cardPool))->sort();
    for (int i = sorted.size()-1; i >= 0; i--) {
        if (sorted.at(i).getColor()==Blue){blueCards.push_back(sorted.at(i));}
        else if (sorted.at(i).getColor()==Green){greenCards.push_back(sorted.at(i));}
        else if (sorted.at(i).getColor()==Yellow){yellowCards.push_back(sorted.at(i));}
        else {redCards.push_back(sorted.at(i));}
        if (blueCards.size()==5||greenCards.size()==5||yellowCards.size()==5||redCards.size()==5){
            break;
        }
    }
    if (blueCards.size()==5){return sumValue(blueCards)+19.5;}
    else if (greenCards.size()==5){return sumValue(greenCards)+19.5;}
    else if (yellowCards.size()==5){return sumValue(yellowCards)+19.5;}
    else {return sumValue(redCards)+19.5;}
}

float Combo::getFullHouse(){
    vector<MainCard> sorted= (new ArrayComparer<MainCard>(this->cardPool))->sort();
    for (int i = sorted.size()-1; i >=2; i--) {
        if (sorted.at(i).getNumber()==sorted.at(i-1).getNumber()&&sorted.at(i).getNumber()==sorted.at(i-2).getNumber()){
            for (int j = i-3; j >= 1; j--) {
                if (sorted.at(j).getNumber()==sorted.at(j-1).getNumber()){
                    return (sorted.at(i).value()+sorted.at(i-1).value()+sorted.at(i-2).value()+sorted.at(j).value()+sorted.at(j-1).value())+25.45;
                }
            }
        } else if (sorted.at(i).getNumber()==sorted.at(i-1).getNumber()&&sorted.at(i).getNumber()!=sorted.at(i-2).getNumber()){
            for (int j = i-2; j >= 2; j--){
                if (sorted.at(j).getNumber()==sorted.at(j-1).getNumber()&&sorted.at(j).getNumber()==sorted.at(j-2).getNumber()){
                    return (sorted.at(i).value()+sorted.at(i-1).value()+sorted.at(j).value()+sorted.at(j-1).value()+sorted.at(j-2).value())+25.45;
                }
            }
        }
    }
    return 0;
}

float Combo::getFourOfKind(){
    vector<MainCard> sorted= (new ArrayComparer<MainCard>(this->cardPool))->sort();
    for (int i = sorted.size()-1; i >=3; i--) {
        if (sorted.at(i).getNumber()==sorted.at(i-1).getNumber()&&sorted.at(i).getNumber()==sorted.at(i-2).getNumber()&&sorted.at(i).getNumber()==sorted.at(i-3).getNumber()){
            return (sorted.at(i).value()+sorted.at(i-1).value()+sorted.at(i-2).value()+sorted.at(i-3).value())+32.08;
        }
    }
    return 0;
}

float Combo::getStraightFlush(){
    vector<MainCard> sorted= (new ArrayComparer<MainCard>(this->cardPool))->sort();
    for (int i = sorted.size()-1; i >= 4; i--){
        for (int j = i-1; j >=3; j--) {
            if (sorted.at(i).getNumber()==sorted.at(j).getNumber()+1 && sorted.at(i).getColor()==sorted.at(j).getColor()){
                for (int k = j-1; k >=2 ; k--) {
                    if (sorted.at(j).getNumber()==sorted.at(k).getNumber()+1 && sorted.at(j).getColor()==sorted.at(k).getColor()){
                        for (int l = k-1; l >=1 ; l--) {
                            if (sorted.at(k).getNumber()==sorted.at(l).getNumber()+1 && sorted.at(k).getColor()==sorted.at(l).getColor()){
                                for (int m = l-1; m >=0; m--) {
                                    if (sorted.at(l).getNumber()==sorted.at(m).getNumber()+1 && sorted.at(l).getColor()==sorted.at(m).getColor()){
                                        return (sorted.at(i).value()+sorted.at(j).value()+sorted.at(k).value()+sorted.at(l).value()+sorted.at(m).value())+37.46;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}



// vector<MainCard> sortCard(vector<MainCard> cards){
//     sort(cards.begin(), cards.end(), [](const MainCard& lhs, const MainCard& rhs) {
// //        return lhs.getNumber() < rhs.getNumber();
//         return lhs>rhs;
//     });
//     for(auto it = cards.begin(); it != cards.end(); it++) {
//         cout << it -> data << endl;
//     }
// }

//bool findGreater(int* arr,int x,int arrsize){
//    for (int i = 0; i < arrsize; ++i) {
//        if (arr[i]>=x){
//            return true;
//        }
//    }
//    return false;
//}
//
//bool findExact(int* arr,int x,int arrsize){
//    for (int i = 0; i < arrsize; ++i) {
//        if (arr[i]==x){
//            return true;
//        }
//    }
//    return false;
//}

float sumValue(vector<MainCard> arr){
    float f=0;
    for (int i = 0; i < arr.size(); ++i) {
        f+=arr.at(i).value();
    }
    return f;
}